// File Line: 131
// RVA: 0x1530180
__int64 UFG::_dynamic_initializer_for__sSym_CombatFish__()
{
  UFG::qSymbol::create_from_string(&sSym_CombatFish, "object-physical-weapon-melee-CombatFish001");
  return atexit(UFG::_dynamic_atexit_destructor_for__sSym_CombatFish__);
}

// File Line: 139
// RVA: 0x15300C0
__int64 UFG::GameStatAction::_dynamic_initializer_for__sFaceEventSymbol_FaceTypeGained__()
{
  UFG::qSymbol::create_from_string(&sFaceEventSymbol_FaceTypeGained, "FaceGained");
  return atexit(UFG::GameStatAction::_dynamic_atexit_destructor_for__sFaceEventSymbol_FaceTypeGained__);
}

// File Line: 140
// RVA: 0x1530120
__int64 UFG::GameStatAction::_dynamic_initializer_for__sFaceEventSymbol_FaceTypeUsed__()
{
  UFG::qSymbol::create_from_string(&sFaceEventSymbol_FaceTypeUsed, "FaceUsed");
  return atexit(UFG::GameStatAction::_dynamic_atexit_destructor_for__sFaceEventSymbol_FaceTypeUsed__);
}

// File Line: 141
// RVA: 0x15300F0
__int64 UFG::GameStatAction::_dynamic_initializer_for__sFaceEventSymbol_FaceTypeLost__()
{
  UFG::qSymbol::create_from_string(&sFaceEventSymbol_FaceTypeLost, "FaceLost");
  return atexit(UFG::GameStatAction::_dynamic_atexit_destructor_for__sFaceEventSymbol_FaceTypeLost__);
}

// File Line: 142
// RVA: 0x1530150
__int64 UFG::GameStatAction::_dynamic_initializer_for__sSymDescription__()
{
  UFG::qSymbol::create_from_string(&sSymDescription, "Description");
  return atexit(UFG::GameStatAction::_dynamic_atexit_destructor_for__sSymDescription__);
}

// File Line: 144
// RVA: 0x152C100
__int64 UFG::GameStatAction::_dynamic_initializer_for__gMissionSymbol_M_VE__()
{
  UFG::qSymbol::create_from_string(&gMissionSymbol_M_VE, "M_VE");
  return atexit(UFG::GameStatAction::_dynamic_atexit_destructor_for__gMissionSymbol_M_VE__);
}

// File Line: 154
// RVA: 0x499B60
void __fastcall UFG::GameStatAction::MiniGame::Completed(UFG::MiniGameType e)
{
  UFG::MiniGameType v1; // esi
  unsigned int v2; // edx
  UFG::GameStatTracker *v3; // rbx
  UFG::GameStatTracker *v4; // r8
  int v5; // edi
  UFG::qSymbol mapid; // [rsp+40h] [rbp+8h]
  UFG::qSymbol *v7; // [rsp+48h] [rbp+10h]

  v1 = e;
  v2 = _S12_6;
  v3 = &sGameStatTracker;
  if ( !(_S12_6 & 1) )
  {
    _S12_6 |= 1u;
    UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
    atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
    v2 = _S12_6;
  }
  v4 = &sGameStatTracker;
  if ( UFG::GameStatTracker::mspInstance )
    v4 = UFG::GameStatTracker::mspInstance;
  UFG::GameStatTracker::mspInstance = v4;
  v5 = v1 | v4->mpSnapshots[0]->mInts[48].mValue;
  if ( !(v2 & 1) )
  {
    _S12_6 = v2 | 1;
    UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
    atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
    v4 = UFG::GameStatTracker::mspInstance;
  }
  if ( v4 )
    v3 = v4;
  UFG::GameStatTracker::mspInstance = v3;
  if ( !(*((_BYTE *)v3 + 6216) & 1) )
  {
    v3->mpSnapshots[0]->mInts[48].mValue = v5;
    v7 = &mapid;
    mapid.mUID = UFG::gNullQSymbol.mUID;
    UFG::GameStatAction::PostStat::Achieve(PDT_INT, 48, (__int64)&mapid);
  }
  if ( v5 == 31 )
    UFG::AchievementTrophyManager::UnlockAchievementTrophy(15);
}

// File Line: 172
// RVA: 0x4AD1D0
void __fastcall UFG::GameStatAction::MiniGame::KaraokeSongCompleted(unsigned int songid, unsigned int score, unsigned int num_of_songs)
{
  unsigned int v3; // er14
  unsigned int v4; // esi
  unsigned int v5; // ebp
  UFG::GameStatTracker *v6; // rdi
  UFG::GameStatTracker *v7; // rbx
  UFG::qWiseSymbol *v8; // rax
  UFG::PersistentData::MapInt *v9; // r9
  unsigned int v10; // er8
  int v11; // ebx
  unsigned int v12; // ecx
  UFG::PersistentData::KeyValue *v13; // r9
  unsigned int v14; // edx
  UFG::PersistentData::KeyValue *v15; // rax
  unsigned int v16; // ecx
  UFG::qSymbol *v17; // rbp
  UFG::GameStatTracker *v18; // rax
  unsigned int v19; // ecx
  UFG::GameStatTracker *v20; // rdx
  int *v21; // rdx
  __int64 v22; // rcx
  UFG::PersistentData::MapFloat::Iterator v23; // [rsp+28h] [rbp-30h]
  UFG::qWiseSymbol result; // [rsp+68h] [rbp+10h]

  v3 = num_of_songs;
  v4 = score;
  v5 = songid;
  v6 = &sGameStatTracker;
  if ( !(_S12_6 & 1) )
  {
    _S12_6 |= 1u;
    UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
    atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
  }
  v7 = &sGameStatTracker;
  if ( UFG::GameStatTracker::mspInstance )
    v7 = UFG::GameStatTracker::mspInstance;
  UFG::GameStatTracker::mspInstance = v7;
  v8 = UFG::qSymbol::qSymbol(&result, v5);
  v9 = v7->mpSnapshots[0]->mpMapInts[0];
  v10 = v9->mValues.size;
  v11 = 0;
  v12 = 0;
  if ( !v9->mValues.size )
    goto LABEL_12;
  v13 = v9->mValues.p;
  v14 = v8->mUID;
  v15 = v13;
  while ( v15->mKey.mUID != v14 )
  {
    ++v12;
    ++v15;
    if ( v12 >= v10 )
      goto LABEL_12;
  }
  if ( v12 != -1 )
    v16 = v13[v12].mIntValue;
  else
LABEL_12:
    v16 = 0;
  if ( (v4 > v16 && v4 != 111 || v16 == 111 && v4)
    && (v17 = (UFG::qSymbol *)UFG::qSymbol::qSymbol(&result, v5),
        v18 = UFG::GameStatTracker::Instance(),
        !(*((_BYTE *)v18 + 6216) & 1))
    && (UFG::PersistentData::MapInt::SetStatus(v18->mpSnapshots[0]->mpMapInts[0], v17, v4),
        UFG::GameStatAction::PostStat::sIsEnabled) )
  {
    v19 = _S12_6;
    if ( !(_S12_6 & 1) )
    {
      _S12_6 |= 1u;
      UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
      atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
      v19 = _S12_6;
    }
    v20 = &sGameStatTracker;
    if ( UFG::GameStatTracker::mspInstance )
      v20 = UFG::GameStatTracker::mspInstance;
    UFG::GameStatTracker::mspInstance = v20;
  }
  else
  {
    v19 = _S12_6;
    v20 = UFG::GameStatTracker::mspInstance;
  }
  if ( !(v19 & 1) )
  {
    _S12_6 = v19 | 1;
    UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
    atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
    v20 = UFG::GameStatTracker::mspInstance;
  }
  if ( v20 )
    v6 = v20;
  UFG::GameStatTracker::mspInstance = v6;
  UFG::PersistentData::MapInt::GetIterator((UFG::PersistentData::MapFloat *)v6->mpSnapshots[0]->mpMapInts[0], &v23);
  if ( v23.mIndex < v23.mList->mValues.size )
  {
    v21 = (int *)&v23.mList->mValues.p[v23.mIndex].4;
    v22 = v23.mList->mValues.size - v23.mIndex;
    do
    {
      if ( (unsigned int)*v21 >= 0x5A && *v21 <= 100 )
        ++v11;
      v21 += 2;
      --v22;
    }
    while ( v22 );
  }
  if ( v11 == v3 )
    UFG::AchievementTrophyManager::UnlockAchievementTrophy(35);
}

// File Line: 212
// RVA: 0x4C9110
void __fastcall UFG::GameStatAction::Bike::WheelieDistance(float wheelie_dist)
{
  UFG::GameStatTracker *v1; // rax
  UFG::GameSnapshot *v2; // rax
  UFG::OSuiteLeaderboardManager *v3; // rax
  UFG::OSuiteLeaderboardData *v4; // rax

  if ( wheelie_dist > 0.001 )
  {
    UFG::GameStatTracker::Instance();
    v1 = UFG::GameStatTracker::Instance();
    if ( !(*((_BYTE *)v1 + 6216) & 1) )
    {
      v2 = v1->mpSnapshots[0];
      if ( wheelie_dist > v2->mFloats[88].mValue )
        v2->mFloats[88].mValue = wheelie_dist;
    }
    v3 = UFG::OSuiteLeaderboardManager::Instance();
    v4 = UFG::OSuiteLeaderboardManager::GetLeaderboardDataUsingLeaderboardName(v3, "StatGamesWheelieDistance");
    UFG::StatGameManager::EndStatGame(v4, (signed int)(float)(wheelie_dist * 1000.0));
  }
}

// File Line: 232
// RVA: 0x4B0E10
void __fastcall UFG::GameStatAction::Vehicle::Mount(bool bIsDriver, UFG::eSimObjectVehicleTypeEnum vehicle, UFG::eTargetTypeEnum target, UFG::SimObject *pSimObject)
{
  UFG::SimObjectGame *v4; // rsi
  bool v5; // bp
  UFG::GameStatTracker *v6; // rdi
  UFG::GameStatTracker *v7; // rbx
  UFG::SimpleTimer *v8; // rbx
  UFG::GameStatTracker *v9; // rcx
  UFG::GameStatTracker *v10; // rax
  unsigned __int16 v11; // cx
  UFG::SimComponent *v12; // rax
  UFG::GameStatTracker *v13; // rax
  UFG::qString v14; // [rsp+38h] [rbp-40h]
  UFG::qSymbol mapid; // [rsp+80h] [rbp+8h]
  UFG::qSymbol *v16; // [rsp+98h] [rbp+20h]

  v4 = (UFG::SimObjectGame *)pSimObject;
  v5 = bIsDriver;
  v6 = &sGameStatTracker;
  if ( !(_S12_6 & 1) )
  {
    _S12_6 |= 1u;
    UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
    atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
  }
  v7 = &sGameStatTracker;
  if ( UFG::GameStatTracker::mspInstance )
    v7 = UFG::GameStatTracker::mspInstance;
  UFG::GameStatTracker::mspInstance = v7;
  v8 = (UFG::SimpleTimer *)v7->mpSnapshots[0];
  UFG::SimpleTimer::SetElapsedTime(v8 + 17, 0.0);
  UFG::SimpleTimer::Start(v8 + 17);
  if ( !(_S12_6 & 1) )
  {
    _S12_6 |= 1u;
    UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
    atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
  }
  v9 = &sGameStatTracker;
  if ( UFG::GameStatTracker::mspInstance )
    v9 = UFG::GameStatTracker::mspInstance;
  UFG::GameStatTracker::mspInstance = v9;
  UFG::SimpleTimer::Stop(&v9->mpSnapshots[0]->mTimes[4].mTimer);
  if ( !(_S12_6 & 1) )
  {
    _S12_6 |= 1u;
    UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
    atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
  }
  if ( UFG::GameStatTracker::mspInstance )
    v6 = UFG::GameStatTracker::mspInstance;
  UFG::GameStatTracker::mspInstance = v6;
  if ( !(*((_BYTE *)v6 + 6216) & 1) )
  {
    v6->mpSnapshots[0]->mInts[162].mValue = 0;
    v16 = &mapid;
    mapid.mUID = UFG::gNullQSymbol.mUID;
    UFG::GameStatAction::PostStat::Achieve(PDT_INT, 162, (__int64)&mapid);
  }
  if ( UFG::RadioFullyControlled::sm_playerRadio )
  {
    UFG::qString::qString(&v14, UFG::RadioFullyControlled::sm_playerRadio->m_curStation->m_name);
    v10 = UFG::GameStatTracker::Instance();
    if ( !(*((_BYTE *)v10 + 6216) & 1) )
      UFG::qString::Set(&v10->mpSnapshots[0]->mStrings[23].mValue, v14.mData, v14.mLength, 0i64, 0);
    UFG::qString::~qString(&v14);
  }
  if ( v4 )
  {
    v11 = v4->m_Flags;
    if ( !((v11 >> 14) & 1) )
    {
      if ( (v11 & 0x8000u) == 0 )
      {
        if ( (v11 >> 13) & 1 )
          goto LABEL_29;
        if ( (v11 >> 12) & 1 )
          v12 = UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::PhysicsMoverInterface::_TypeUID);
        else
          v12 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v4->vfptr, UFG::PhysicsMoverInterface::_TypeUID);
      }
      else
      {
        v12 = v4->m_Components.p[34].m_pComponent;
      }
      if ( v12 )
        LODWORD(v12[10].m_BoundComponentHandles.mNode.mNext) = 0;
    }
  }
LABEL_29:
  if ( !v5 )
  {
    if ( UFG::SimObjectUtility::IsClassType((UFG::SimObject *)&v4->vfptr, (UFG::qSymbol *)&qSymbol_Taxi.mUID) )
    {
      v13 = UFG::GameStatTracker::Instance();
      UFG::SimpleTimer::Resume((UFG::SimpleTimer *)v13->mpSnapshots[0]);
    }
  }
}

// File Line: 256
// RVA: 0x49D500
void __fastcall UFG::GameStatAction::Vehicle::Dismount(bool bIsDriver, UFG::eSimObjectVehicleTypeEnum vehicle, UFG::eTargetTypeEnum target, UFG::SimObject *pSimObject)
{
  UFG::SimObjectGame *v4; // rbp
  UFG::eSimObjectVehicleTypeEnum v5; // esi
  bool v6; // di
  UFG::GameStatTracker *v7; // rbx
  UFG::GameStatTracker *v8; // rcx
  UFG::GameStatTracker *v9; // rcx
  UFG::GameStatTracker *v10; // rcx
  float v11; // xmm0_4
  float v12; // xmm6_4
  int v13; // er15
  char v14; // r12
  UFG::SimComponent *v15; // rax
  unsigned __int16 v16; // cx
  UFG::PhysicsMoverInterface *v17; // rdi
  UFG::SimComponent *v18; // rax
  UFG::WaterFloatingTrackerComponent *v19; // r14
  const char *v20; // rdx
  UFG::qString *v21; // rcx
  UFG::SceneObjectProperties *v22; // rcx
  UFG::qSymbol *v23; // rax
  UFG::qSymbol *v24; // r14
  int v25; // eax
  int v26; // esi
  int v27; // esi
  UFG::RadioFullyControlled *v28; // rsi
  UFG::OSuiteDBLogger *v29; // rbx
  UFG::GameStatTracker *v30; // rax
  UFG::GameStatTracker *v31; // rax
  UFG::qString v32; // [rsp+30h] [rbp-88h]
  UFG::qString v33; // [rsp+58h] [rbp-60h]
  UFG::qSymbol v34; // [rsp+C0h] [rbp+8h]

  v4 = (UFG::SimObjectGame *)pSimObject;
  v5 = vehicle;
  v6 = bIsDriver;
  v7 = &sGameStatTracker;
  if ( !(_S12_6 & 1) )
  {
    _S12_6 |= 1u;
    UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
    atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
  }
  v8 = &sGameStatTracker;
  if ( UFG::GameStatTracker::mspInstance )
    v8 = UFG::GameStatTracker::mspInstance;
  UFG::GameStatTracker::mspInstance = v8;
  UFG::SimpleTimer::Resume(&v8->mpSnapshots[0]->mTimes[4].mTimer);
  if ( !(_S12_6 & 1) )
  {
    _S12_6 |= 1u;
    UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
    atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
  }
  v9 = &sGameStatTracker;
  if ( UFG::GameStatTracker::mspInstance )
    v9 = UFG::GameStatTracker::mspInstance;
  UFG::GameStatTracker::mspInstance = v9;
  UFG::SimpleTimer::Stop(&v9->mpSnapshots[0]->mTimes[17].mTimer);
  if ( !(_S12_6 & 1) )
  {
    _S12_6 |= 1u;
    UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
    atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
  }
  v10 = &sGameStatTracker;
  if ( UFG::GameStatTracker::mspInstance )
    v10 = UFG::GameStatTracker::mspInstance;
  UFG::GameStatTracker::mspInstance = v10;
  UFG::SimpleTimer::Stop((UFG::SimpleTimer *)v10->mpSnapshots[0]);
  if ( !(_S12_6 & 1) )
  {
    _S12_6 |= 1u;
    UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
    atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
  }
  if ( UFG::GameStatTracker::mspInstance )
    v7 = UFG::GameStatTracker::mspInstance;
  UFG::GameStatTracker::mspInstance = v7;
  if ( v6 )
  {
    v11 = UFG::SimpleTimer::GetElapsedSeconds(&v7->mpSnapshots[0]->mTimes[17].mTimer);
    v12 = v11;
    UFG::qString::qString(&v32, "OK");
    UFG::qString::qString(&v33, "Exit");
    v13 = 0;
    v14 = 0;
    if ( !v4 )
    {
      v17 = 0i64;
      goto LABEL_62;
    }
    v15 = UFG::SimObject::GetComponentOfType(
            (UFG::SimObject *)&v4->vfptr,
            UFG::SimObjectVehiclePropertiesComponent::_TypeUID);
    if ( v15 )
      v14 = v15[3].m_Flags;
    v16 = v4->m_Flags;
    if ( (v16 >> 14) & 1 )
    {
      v17 = 0i64;
      goto LABEL_47;
    }
    if ( (v16 & 0x8000u) == 0 )
    {
      if ( (v16 >> 13) & 1 )
      {
        v17 = 0i64;
        goto LABEL_47;
      }
      if ( (v16 >> 12) & 1 )
        v18 = UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::PhysicsMoverInterface::_TypeUID);
      else
        v18 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v4->vfptr, UFG::PhysicsMoverInterface::_TypeUID);
      v17 = (UFG::PhysicsMoverInterface *)v18;
    }
    else
    {
      v17 = (UFG::PhysicsMoverInterface *)v4->m_Components.p[34].m_pComponent;
    }
    if ( !v17 )
      goto LABEL_47;
    if ( !(*((_BYTE *)v7 + 6216) & 1) )
    {
      v7->mpSnapshots[0]->mFloats[0].mValue = (float)(v17->mOdometer * 0.001) + v7->mpSnapshots[0]->mFloats[0].mValue;
      if ( !(*((_BYTE *)v7 + 6216) & 1) )
        v7->mpSnapshots[0]->mFloats[1].mValue = v11 + v7->mpSnapshots[0]->mFloats[1].mValue;
    }
    v19 = v17->mPhysicsVehicle->mWaterFloatingTrackerComponent;
    if ( UFG::PhysicsMoverInterface::GetEngineDamage(v17) >= 1.0 )
    {
      UFG::qString::Format(&v32, "Wrecked");
      v20 = "Death";
      v21 = &v33;
LABEL_46:
      UFG::qString::Format(v21, v20);
      goto LABEL_47;
    }
    if ( v19 )
    {
      if ( UFG::WaterFloatingTrackerComponent::IsInWater(v19) )
      {
        v20 = "In Water";
LABEL_45:
        v21 = &v32;
        goto LABEL_46;
      }
      if ( UFG::WaterFloatingTrackerComponent::IsSunk(v19) )
      {
        v20 = "Submerged";
        goto LABEL_45;
      }
    }
    if ( UFG::PhysicsMoverInterface::GetEngineDamage(v17) >= 1.0
      || UFG::PhysicsMoverInterface::GetEngineDamage(v17) <= 0.0 )
    {
LABEL_47:
      v22 = v4->m_pSceneObj;
      if ( v22 )
      {
        v23 = UFG::SceneObjectProperties::GetArchetypePropertiesName(v22);
        v24 = v23;
        v25 = v23->mUID;
        if ( v25 != UFG::gNullQSymbol.mUID )
        {
          v13 = v25;
          v26 = v5 - 1;
          if ( v26 )
          {
            v27 = v26 - 1;
            if ( v27 )
            {
              if ( v27 != 1 )
              {
LABEL_64:
                UFG::qString::~qString(&v33);
                UFG::qString::~qString(&v32);
                return;
              }
              UFG::GameStatTracker::ApplyDelta(v7, TimeOnBoatList, v24, v12);
              if ( !(*((_BYTE *)v7 + 6216) & 1) )
                v7->mpSnapshots[0]->mFloats[107].mValue = v12 + v7->mpSnapshots[0]->mFloats[107].mValue;
            }
            else if ( !(*((_BYTE *)v7 + 6216) & 1) )
            {
              UFG::PersistentData::MapFloat::ApplyDelta(v7->mpSnapshots[0]->mpMapFloats[3], v24, v12);
              if ( UFG::GameStatAction::PostStat::sIsEnabled )
                v34.mUID = v24->mUID;
              if ( !(*((_BYTE *)v7 + 6216) & 1) )
                v7->mpSnapshots[0]->mFloats[105].mValue = v12 + v7->mpSnapshots[0]->mFloats[105].mValue;
            }
          }
          else
          {
            UFG::GameStatTracker::ApplyDelta(v7, TimeOnBikeList, v24, v12);
            if ( !(*((_BYTE *)v7 + 6216) & 1) )
              v7->mpSnapshots[0]->mFloats[106].mValue = v12 + v7->mpSnapshots[0]->mFloats[106].mValue;
          }
        }
      }
LABEL_62:
      v28 = UFG::RadioFullyControlled::sm_playerRadio;
      v29 = UFG::OSuiteDBLogger::Instance();
      if ( UFG::OSuiteDBLogger::CreateMetric(v29, "VehicleExit") )
      {
        UFG::OSuiteDBLogger::AddValue(v29, "IsGarageVehicle", v14);
        UFG::OSuiteDBLogger::AddValue(v29, "Exit", v33.mData);
        UFG::OSuiteDBLogger::AddValue(v29, "VehicleState", v32.mData);
        UFG::OSuiteDBLogger::AddValue(v29, "Vehicle", v13);
        UFG::OSuiteDBLogger::AddValue(v29, "Distance", v17->mOdometer * 0.001);
        UFG::OSuiteDBLogger::AddValue(v29, "Time", v12);
        v30 = UFG::GameStatTracker::Instance();
        UFG::OSuiteDBLogger::AddValue(v29, "Kills", v30->mpSnapshots[0]->mInts[162].mValue);
        v31 = UFG::GameStatTracker::Instance();
        UFG::OSuiteDBLogger::AddValue(v29, "RadioStationEnter", v31->mpSnapshots[0]->mStrings[23].mValue.mData);
        UFG::OSuiteDBLogger::AddValue(v29, "RadioStationExit", v28->m_curStation->m_name);
        UFG::OSuiteDBLogger::SubmitMetric(v29, 1);
      }
      goto LABEL_64;
    }
    v20 = "Damaged";
    goto LABEL_45;
  }
}

// File Line: 348
// RVA: 0x4BCC30
void __fastcall UFG::GameStatAction::Vehicle::SetHighestJump(int numWheels, float height)
{
  UFG::GameStatTracker *v2; // rax
  UFG::GameSnapshot *v3; // rax
  UFG::GameStatTracker *v4; // rax
  UFG::GameSnapshot *v5; // rax
  UFG::GameStatTracker *v6; // rax
  UFG::GameSnapshot *v7; // rax

  if ( numWheels )
  {
    if ( numWheels == 2 )
    {
      v4 = UFG::GameStatTracker::Instance();
      if ( !(*((_BYTE *)v4 + 6216) & 1) )
      {
        v5 = v4->mpSnapshots[0];
        if ( height > v5->mFloats[90].mValue )
          v5->mFloats[90].mValue = height;
      }
    }
    else if ( numWheels == 4 )
    {
      v2 = UFG::GameStatTracker::Instance();
      if ( !(*((_BYTE *)v2 + 6216) & 1) )
      {
        v3 = v2->mpSnapshots[0];
        if ( height > v3->mFloats[89].mValue )
          v3->mFloats[89].mValue = height;
      }
    }
  }
  else
  {
    v6 = UFG::GameStatTracker::Instance();
    if ( !(*((_BYTE *)v6 + 6216) & 1) )
    {
      v7 = v6->mpSnapshots[0];
      if ( height > v7->mFloats[91].mValue )
        v7->mFloats[91].mValue = height;
    }
  }
}

// File Line: 361
// RVA: 0x4BCD80
void __fastcall UFG::GameStatAction::Vehicle::SetLongestJump(UFG::SimObject *pVehicle, float dist)
{
  UFG::SimObjectVehiclePropertiesComponent *v2; // rax
  unsigned __int16 v3; // dx
  UFG::GameStatTracker *v4; // rax
  UFG::GameSnapshot *v5; // rax
  UFG::OSuiteLeaderboardManager *v6; // rax
  const char *v7; // rdx
  UFG::GameStatTracker *v8; // rax
  UFG::GameSnapshot *v9; // rax
  UFG::OSuiteLeaderboardData *v10; // rax

  if ( pVehicle )
  {
    v3 = pVehicle->m_Flags;
    if ( (v3 >> 14) & 1 )
    {
      v2 = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectVehiclePropertiesComponent>((UFG::SimObjectCVBase *)pVehicle);
    }
    else if ( (v3 & 0x8000u) == 0 )
    {
      if ( (v3 >> 13) & 1 )
      {
        v2 = (UFG::SimObjectVehiclePropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                           (UFG::SimObjectGame *)pVehicle,
                                                           UFG::SimObjectVehiclePropertiesComponent::_TypeUID);
      }
      else if ( (v3 >> 12) & 1 )
      {
        v2 = (UFG::SimObjectVehiclePropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                           (UFG::SimObjectGame *)pVehicle,
                                                           UFG::SimObjectVehiclePropertiesComponent::_TypeUID);
      }
      else
      {
        v2 = (UFG::SimObjectVehiclePropertiesComponent *)UFG::SimObject::GetComponentOfType(
                                                           pVehicle,
                                                           UFG::SimObjectVehiclePropertiesComponent::_TypeUID);
      }
    }
    else
    {
      v2 = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectVehiclePropertiesComponent>((UFG::SimObjectCVBase *)pVehicle);
    }
  }
  else
  {
    v2 = 0i64;
  }
  switch ( v2->m_eSimObjectVehicleType )
  {
    case 1:
    case 6:
      v4 = UFG::GameStatTracker::Instance();
      if ( !(*((_BYTE *)v4 + 6216) & 1) )
      {
        v5 = v4->mpSnapshots[0];
        if ( dist > v5->mFloats[93].mValue )
          v5->mFloats[93].mValue = dist;
      }
      v6 = UFG::OSuiteLeaderboardManager::Instance();
      v7 = "StatGamesBikeJump";
      goto LABEL_21;
    case 2:
    case 4:
    case 5:
      v8 = UFG::GameStatTracker::Instance();
      if ( !(*((_BYTE *)v8 + 6216) & 1) )
      {
        v9 = v8->mpSnapshots[0];
        if ( dist > v9->mFloats[92].mValue )
          v9->mFloats[92].mValue = dist;
      }
      v6 = UFG::OSuiteLeaderboardManager::Instance();
      v7 = "StatGamesCarJump";
LABEL_21:
      v10 = UFG::OSuiteLeaderboardManager::GetLeaderboardDataUsingLeaderboardName(v6, v7);
      UFG::StatGameManager::EndStatGame(v10, (signed int)(float)(dist * 1000.0));
      break;
    default:
      return;
  }
}

// File Line: 388
// RVA: 0x4C2BD0
void __fastcall UFG::GameStatAction::Vehicle::TireHit(UFG::SimObject *shooter, UFG::SimObject *car)
{
  UFG::SimObjectGame *v2; // rbx
  UFG::SimObjectGame *v3; // rsi
  unsigned __int16 v4; // cx
  UFG::SimComponent *v5; // rax
  hkSimpleLocalFrame *v6; // rdi
  UFG::SimObject *v7; // rax
  UFG::SimComponent *v8; // rdi
  UFG::SimComponent *v9; // rsi
  unsigned __int16 v10; // cx
  UFG::SimComponent *v11; // rax
  unsigned __int16 v12; // cx
  UFG::SimComponent *v13; // rax
  UFG::GameStatTracker *v14; // rax
  UFG::GameStatTracker *v15; // rbx
  UFG::GameStatTracker *v16; // rcx
  UFG::OSuiteLeaderboardManager *v17; // rax
  UFG::OSuiteLeaderboardData *v18; // rax
  UFG::GameStatTracker *v19; // rax
  UFG::CopSystem *v20; // rax
  bool pIsCop; // [rsp+40h] [rbp+8h]
  bool pIsAmbient; // [rsp+50h] [rbp+18h]

  v2 = (UFG::SimObjectGame *)car;
  v3 = (UFG::SimObjectGame *)shooter;
  if ( shooter != (UFG::SimObject *)UFG::GetLocalPlayer() )
    return;
  pIsCop = 0;
  pIsAmbient = 0;
  UFG::GameStatAction::MissionScoring::DeduceFaction((UFG::SimObject *)&v2->vfptr, &pIsCop, &pIsAmbient);
  if ( pIsCop || pIsAmbient )
  {
    UFG::GameStatAction::MissionScoring::LogCopEvent(COP_VEHICLE_TIRE_SHOT, 0, &customWorldMapCaption);
    goto LABEL_20;
  }
  if ( !v2 )
    goto LABEL_20;
  v4 = v2->m_Flags;
  if ( (v4 >> 14) & 1 )
  {
    v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::VehicleOccupantComponent::_TypeUID);
LABEL_14:
    v6 = (hkSimpleLocalFrame *)v5;
    goto LABEL_15;
  }
  if ( (v4 & 0x8000u) == 0 )
  {
    if ( (v4 >> 13) & 1 )
    {
      v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::VehicleOccupantComponent::_TypeUID);
    }
    else if ( (v4 >> 12) & 1 )
    {
      v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::VehicleOccupantComponent::_TypeUID);
    }
    else
    {
      v5 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v2->vfptr, UFG::VehicleOccupantComponent::_TypeUID);
    }
    goto LABEL_14;
  }
  v6 = (hkSimpleLocalFrame *)v2->m_Components.p[30].m_pComponent;
LABEL_15:
  if ( v6 )
  {
    if ( Scaleform::Render::RBGenericImpl::RenderTarget::GetTexture(v6) )
    {
      v7 = (UFG::SimObject *)Scaleform::Render::RBGenericImpl::RenderTarget::GetTexture(v6);
      if ( !UFG::AreCharactersAllied((UFG::SimObject *)&v3->vfptr, v7) )
        UFG::GameStatAction::MissionScoring::LogTriadEvent(TRIAD_VEHICLE_TIRE_SHOT, 0, &customWorldMapCaption);
    }
  }
LABEL_20:
  v8 = 0i64;
  if ( v3 )
  {
    v10 = v3->m_Flags;
    if ( (v10 >> 14) & 1 )
    {
      v9 = v3->m_Components.p[44].m_pComponent;
    }
    else
    {
      if ( (v10 & 0x8000u) == 0 )
      {
        if ( (v10 >> 13) & 1 )
        {
          v11 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::CharacterOccupantComponent::_TypeUID);
        }
        else if ( (v10 >> 12) & 1 )
        {
          v11 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::CharacterOccupantComponent::_TypeUID);
        }
        else
        {
          v11 = UFG::SimObject::GetComponentOfType(
                  (UFG::SimObject *)&v3->vfptr,
                  UFG::CharacterOccupantComponent::_TypeUID);
        }
      }
      else
      {
        v11 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::CharacterOccupantComponent::_TypeUID);
      }
      v9 = v11;
    }
  }
  else
  {
    v9 = 0i64;
  }
  if ( !v2 )
    goto LABEL_43;
  v12 = v2->m_Flags;
  if ( (v12 >> 14) & 1 )
  {
    v13 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::VehicleOccupantComponent::_TypeUID);
  }
  else
  {
    if ( (v12 & 0x8000u) != 0 )
    {
      v8 = v2->m_Components.p[30].m_pComponent;
      goto LABEL_43;
    }
    if ( (v12 >> 13) & 1 )
    {
      v13 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::VehicleOccupantComponent::_TypeUID);
    }
    else if ( (v12 >> 12) & 1 )
    {
      v13 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::VehicleOccupantComponent::_TypeUID);
    }
    else
    {
      v13 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v2->vfptr, UFG::VehicleOccupantComponent::_TypeUID);
    }
  }
  v8 = v13;
LABEL_43:
  v14 = UFG::GameStatTracker::Instance();
  v15 = &sGameStatTracker;
  if ( !(*((_BYTE *)v14 + 6216) & 1) )
  {
    ++v14->mpSnapshots[0]->mInts[96].mValue;
    if ( UFG::GameStatAction::PostStat::sIsEnabled )
    {
      if ( !(_S12_6 & 1) )
      {
        _S12_6 |= 1u;
        UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
        atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
      }
      v16 = &sGameStatTracker;
      if ( UFG::GameStatTracker::mspInstance )
        v16 = UFG::GameStatTracker::mspInstance;
      UFG::GameStatTracker::mspInstance = v16;
    }
  }
  if ( v9 )
  {
    if ( LODWORD(v9[1].m_SafePointerList.mNode.mNext) == 4 )
    {
      if ( v8 )
      {
        v17 = UFG::OSuiteLeaderboardManager::Instance();
        v18 = UFG::OSuiteLeaderboardManager::GetLeaderboardDataUsingLeaderboardName(v17, "StatGamesTireShots");
        UFG::StatGameManager::UpdateScore(v18, 1, 1);
        v19 = UFG::GameStatTracker::Instance();
        if ( !(*((_BYTE *)v19 + 6216) & 1) )
        {
          ++v19->mpSnapshots[0]->mInts[97].mValue;
          if ( UFG::GameStatAction::PostStat::sIsEnabled )
          {
            if ( !(_S12_6 & 1) )
            {
              _S12_6 |= 1u;
              UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
              atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
            }
            if ( UFG::GameStatTracker::mspInstance )
              v15 = UFG::GameStatTracker::mspInstance;
            UFG::GameStatTracker::mspInstance = v15;
          }
        }
      }
    }
  }
  v20 = UFG::CopSystem::Instance();
  if ( ((signed int (__fastcall *)(UFG::CopSystem *))v20->vfptr[89].__vecDelDtor)(v20) > 0 && pIsCop )
  {
    if ( v8 )
      UFG::AchievementTrophyManager::UnlockAchievementTrophy(22);
  }
}

// File Line: 455
// RVA: 0x49FDF0
void __fastcall UFG::GameStatAction::Vehicle::Explosion(UFG::SimObject *car)
{
  UFG::SimObjectGame *v1; // rdi
  UFG::SimObjectCharacter *v2; // rsi
  unsigned __int16 v3; // cx
  UFG::SimComponent *v4; // rax
  __int64 v5; // rcx
  unsigned __int16 v6; // cx
  unsigned int v7; // edx
  UFG::SimObjectGame *v8; // rcx
  UFG::SimComponent *v9; // rax
  hkSimpleLocalFrame *v10; // rbx
  bool v11; // zf
  UFG::SimObjectCharacter *v12; // rbx
  unsigned int v13; // ecx
  UFG::GameStatTracker *v14; // rbx
  UFG::GameStatTracker *v15; // rdx
  unsigned __int16 v16; // cx
  UFG::SimComponent *v17; // rax
  hkSimpleLocalFrame *v18; // rbx
  UFG::SimObject *v19; // rbx
  UFG::SimObjectCharacter *v20; // rax
  UFG::SimComponent *v21; // rax
  unsigned __int16 v22; // cx
  UFG::allocator::free_link *v23; // rsi
  const char *v24; // rdi
  unsigned int v25; // ebx
  UFG::SimObjectCharacter *v26; // rax
  UFG::allocator::free_link *v27; // rcx
  bool pIsCop; // [rsp+40h] [rbp+8h]
  bool pIsAmbient; // [rsp+48h] [rbp+10h]

  v1 = (UFG::SimObjectGame *)car;
  v2 = 0i64;
  if ( !car
    || ((v3 = car->m_Flags, !((v3 >> 14) & 1)) ? ((v3 & 0x8000u) == 0 ? (!((v3 >> 13) & 1) ? (!((v3 >> 12) & 1) ? (v4 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v1->vfptr, UFG::HitReactionComponent::_TypeUID)) : (v4 = UFG::SimObjectGame::GetComponentOfTypeHK(v1, UFG::HitReactionComponent::_TypeUID))) : (v4 = UFG::SimObjectGame::GetComponentOfTypeHK(v1, UFG::HitReactionComponent::_TypeUID))) : (v4 = v1->m_Components.p[15].m_pComponent)) : (v4 = v1->m_Components.p[15].m_pComponent),
        !v4 || (v5 = *(_QWORD *)&v4[3].m_TypeUID) == 0) )
  {
    v10 = 0i64;
    goto LABEL_23;
  }
  v2 = *(UFG::SimObjectCharacter **)&v4[3].m_TypeUID;
  v6 = *(_WORD *)(v5 + 76);
  if ( (v6 >> 14) & 1 )
    goto LABEL_74;
  if ( (v6 & 0x8000u) != 0 )
  {
    v10 = (hkSimpleLocalFrame *)v2->m_Components.p[30].m_pComponent;
    goto LABEL_23;
  }
  if ( (v6 >> 13) & 1 )
  {
LABEL_74:
    v7 = UFG::VehicleOccupantComponent::_TypeUID;
    v8 = *(UFG::SimObjectGame **)&v4[3].m_TypeUID;
  }
  else
  {
    v7 = UFG::VehicleOccupantComponent::_TypeUID;
    v11 = ((v6 >> 12) & 1) == 0;
    v8 = *(UFG::SimObjectGame **)&v4[3].m_TypeUID;
    if ( v11 )
    {
      v9 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v2->vfptr, UFG::VehicleOccupantComponent::_TypeUID);
      goto LABEL_16;
    }
  }
  v9 = UFG::SimObjectGame::GetComponentOfTypeHK(v8, v7);
LABEL_16:
  v10 = (hkSimpleLocalFrame *)v9;
LABEL_23:
  if ( v2 != UFG::GetLocalPlayer() )
  {
    if ( !v10 )
      return;
    v12 = (UFG::SimObjectCharacter *)Scaleform::Render::RBGenericImpl::RenderTarget::GetTexture(v10);
    if ( v12 != UFG::GetLocalPlayer() )
      return;
  }
  v13 = _S12_6;
  v14 = &sGameStatTracker;
  if ( !(_S12_6 & 1) )
  {
    _S12_6 |= 1u;
    UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
    atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
    v13 = _S12_6;
  }
  v15 = &sGameStatTracker;
  if ( UFG::GameStatTracker::mspInstance )
    v15 = UFG::GameStatTracker::mspInstance;
  UFG::GameStatTracker::mspInstance = v15;
  if ( !(*((_BYTE *)v15 + 6216) & 1) )
  {
    ++v15->mpSnapshots[0]->mInts[98].mValue;
    if ( UFG::GameStatAction::PostStat::sIsEnabled )
    {
      if ( !(v13 & 1) )
      {
        _S12_6 = v13 | 1;
        UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
        atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
      }
      if ( UFG::GameStatTracker::mspInstance )
        v14 = UFG::GameStatTracker::mspInstance;
      UFG::GameStatTracker::mspInstance = v14;
    }
  }
  UFG::OnlineEventManager::PostEvent(Prop, 0);
  UFG::GameStatAction::MissionScoring::DeduceFaction((UFG::SimObject *)&v1->vfptr, &pIsCop, &pIsAmbient);
  if ( !pIsCop )
  {
    if ( !pIsAmbient )
    {
      if ( !v1 )
      {
LABEL_54:
        UFG::GameStatAction::MissionScoring::LogTriadEvent(TRIAD_VEHICLE_DESTROY, 0, &customWorldMapCaption);
        goto LABEL_56;
      }
      v16 = v1->m_Flags;
      if ( (v16 >> 14) & 1 )
      {
        v17 = UFG::SimObjectGame::GetComponentOfTypeHK(v1, UFG::VehicleOccupantComponent::_TypeUID);
      }
      else
      {
        if ( (v16 & 0x8000u) != 0 )
        {
          v18 = (hkSimpleLocalFrame *)v1->m_Components.p[30].m_pComponent;
LABEL_50:
          if ( v18 )
          {
            if ( Scaleform::Render::RBGenericImpl::RenderTarget::GetTexture(v18) )
            {
              v19 = (UFG::SimObject *)Scaleform::Render::RBGenericImpl::RenderTarget::GetTexture(v18);
              if ( v19 )
              {
                v20 = UFG::GetLocalPlayer();
                if ( UFG::AreCharactersAllied((UFG::SimObject *)&v20->vfptr, v19) )
                  goto LABEL_56;
              }
            }
          }
          goto LABEL_54;
        }
        if ( (v16 >> 13) & 1 )
        {
          v17 = UFG::SimObjectGame::GetComponentOfTypeHK(v1, UFG::VehicleOccupantComponent::_TypeUID);
        }
        else if ( (v16 >> 12) & 1 )
        {
          v17 = UFG::SimObjectGame::GetComponentOfTypeHK(v1, UFG::VehicleOccupantComponent::_TypeUID);
        }
        else
        {
          v17 = UFG::SimObject::GetComponentOfType(
                  (UFG::SimObject *)&v1->vfptr,
                  UFG::VehicleOccupantComponent::_TypeUID);
        }
      }
      v18 = (hkSimpleLocalFrame *)v17;
      goto LABEL_50;
    }
    UFG::GameStatAction::MissionScoring::LogCopEvent(COP_VEHICLE_DESTROY, 0, &customWorldMapCaption);
  }
LABEL_56:
  if ( v1 )
  {
    v22 = v1->m_Flags;
    if ( (v22 >> 14) & 1 )
    {
      v21 = 0i64;
    }
    else if ( (v22 & 0x8000u) == 0 )
    {
      if ( (v22 >> 13) & 1 )
      {
        v21 = 0i64;
      }
      else if ( (v22 >> 12) & 1 )
      {
        v21 = UFG::SimObjectGame::GetComponentOfTypeHK(v1, UFG::PhysicsMoverInterface::_TypeUID);
      }
      else
      {
        v21 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v1->vfptr, UFG::PhysicsMoverInterface::_TypeUID);
      }
    }
    else
    {
      v21 = v1->m_Components.p[34].m_pComponent;
    }
  }
  else
  {
    v21 = 0i64;
  }
  if ( LODWORD(v21[12].m_BoundComponentHandles.mNode.mNext) == 4 )
  {
    v23 = UFG::qMalloc(0x48ui64, "GameStatEventTask", 0i64);
    *(_QWORD *)&pIsCop = v23;
    if ( v23 )
    {
      v24 = UFG::gGameStatEventChannel.mName;
      v25 = UFG::gGameStatEventChannel.mUID;
      v26 = UFG::GetLocalPlayer();
      v27 = v23 + 1;
      v27->mNext = v27;
      v27[1].mNext = v27;
      v23->mNext = (UFG::allocator::free_link *)&UFG::Event::`vftable;
      LODWORD(v23[3].mNext) = v25;
      v23[4].mNext = (UFG::allocator::free_link *)v24;
      v23->mNext = (UFG::allocator::free_link *)&UFG::GameStatEvent::`vftable;
      LODWORD(v23[7].mNext) = 23;
      v23[8].mNext = (UFG::allocator::free_link *)v26;
    }
    else
    {
      v23 = 0i64;
    }
    UFG::EventDispatcher::DispatchEvent(&UFG::EventDispatcher::mInstance, (UFG::Event *)v23);
  }
}

// File Line: 539
// RVA: 0x4BF680
void UFG::GameStatAction::Radio::Start(void)
{
  UFG::GameStatTracker *v0; // rbx
  UFG::SimpleTimer *v1; // rbx

  v0 = &sGameStatTracker;
  if ( !(_S12_6 & 1) )
  {
    _S12_6 |= 1u;
    UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
    atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
  }
  if ( UFG::GameStatTracker::mspInstance )
    v0 = UFG::GameStatTracker::mspInstance;
  UFG::GameStatTracker::mspInstance = v0;
  v1 = (UFG::SimpleTimer *)v0->mpSnapshots[0];
  UFG::SimpleTimer::SetElapsedTime(v1 + 16, 0.0);
  UFG::SimpleTimer::Start(v1 + 16);
}

// File Line: 544
// RVA: 0x4C18A0
void __fastcall UFG::GameStatAction::Radio::Stop(UFG::RadioStation *station)
{
  UFG::RadioStation *v1; // rbx
  UFG::SimpleTimer *v2; // rdi
  float v3; // xmm6_4
  UFG::GameStatTracker *v4; // rax
  UFG::qSymbol result; // [rsp+50h] [rbp+8h]
  unsigned int v6; // [rsp+58h] [rbp+10h]
  unsigned int *v7; // [rsp+60h] [rbp+18h]

  if ( station )
  {
    v1 = station;
    v2 = &UFG::GameStatTracker::Instance()->mpSnapshots[0]->mTimes[16].mTimer;
    UFG::SimpleTimer::Stop(v2);
    UFG::qSymbol::create_from_string(&result, v1->m_name);
    v3 = UFG::SimpleTimer::GetElapsedSeconds(v2);
    v4 = UFG::GameStatTracker::Instance();
    if ( !(*((_BYTE *)v4 + 6216) & 1) )
    {
      UFG::PersistentData::MapFloat::ApplyDelta(v4->mpSnapshots[0]->mpMapFloats[2], &result, v3);
      if ( UFG::GameStatAction::PostStat::sIsEnabled )
      {
        v7 = &v6;
        v6 = result.mUID;
      }
    }
    UFG::SimpleTimer::GetElapsedSeconds(v2);
  }
}

// File Line: 577
// RVA: 0x4BF5D0
void UFG::GameStatAction::GameState::Start(void)
{
  UFG::GameStatAction::World::sCurrentZone = 0;
  if ( !(_S19_1 & 1) )
  {
    _S19_1 |= 1u;
    UFG::ProgressionTracker::ProgressionTracker(&sProgressionTracker);
    atexit(UFG::ProgressionTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sProgressionTracker__);
  }
  UFG::ProgressionTracker::mspInstance = &sProgressionTracker;
  UFG::ProgressionTracker::PublishProgressionStatistics(&sProgressionTracker);
  if ( !(_S15_1 & 1) )
  {
    _S15_1 |= 1u;
    instance_5.m_lLeaderboards.mNode.mPrev = (UFG::qNode<UFG::CachedLeaderboard,UFG::CachedLeaderboard> *)&instance_5;
    instance_5.m_lLeaderboards.mNode.mNext = (UFG::qNode<UFG::CachedLeaderboard,UFG::CachedLeaderboard> *)&instance_5;
    instance_5.m_bIsCachedLeaderboardBuilt = 0;
    atexit(UFG::CachedLeaderboardManager::Instance_::_2_::_dynamic_atexit_destructor_for__instance__);
  }
  UFG::CachedLeaderboardManager::BuildCachedLeaderboard(&instance_5);
}

// File Line: 593
// RVA: 0x49E160
void __fastcall UFG::GameStatAction::Character::EnterWater(UFG::SimObject *who)
{
  UFG::GameStatTracker *v1; // rax
  UFG::GameStatTracker *v2; // rax

  if ( UFG::GetLocalPlayer() == (UFG::SimObjectCharacter *)who )
  {
    v1 = UFG::GameStatTracker::Instance();
    UFG::SimpleTimer::Resume(&v1->mpSnapshots[0]->mTimes[6].mTimer);
    v2 = UFG::GameStatTracker::Instance();
    UFG::SimpleTimer::Stop(&v2->mpSnapshots[0]->mTimes[4].mTimer);
  }
}

// File Line: 602
// RVA: 0x49FD90
void __fastcall UFG::GameStatAction::Character::ExitWater(UFG::SimObject *who)
{
  UFG::GameStatTracker *v1; // rax
  UFG::GameStatTracker *v2; // rax
  UFG::GameStatTracker *v3; // rax

  if ( UFG::GetLocalPlayer() == (UFG::SimObjectCharacter *)who )
  {
    v1 = UFG::GameStatTracker::Instance();
    UFG::SimpleTimer::Stop(&v1->mpSnapshots[0]->mTimes[6].mTimer);
    v2 = UFG::GameStatTracker::Instance();
    UFG::SimpleTimer::Resume(&v2->mpSnapshots[0]->mTimes[4].mTimer);
    v3 = UFG::GameStatTracker::Instance();
    UFG::SimpleTimer::GetElapsedSeconds(&v3->mpSnapshots[0]->mTimes[6].mTimer);
  }
}

// File Line: 647
// RVA: 0x4B4B50
void __fastcall UFG::GameStatAction::Player::RecordSpecialMove(__int64 path)
{
  UFG::qSymbol *v1; // rdi
  UFG::GameStatTracker *v2; // rbx
  UFG::GameStatTracker *v3; // rax
  unsigned int v4; // ecx
  UFG::GameStatTracker *v5; // rdx
  UFG::GameStatTracker *v6; // rax
  unsigned int v7; // eax
  UFG::qSymbol mapid; // [rsp+40h] [rbp+8h]
  UFG::qSymbol *v9; // [rsp+48h] [rbp+10h]

  v1 = (UFG::qSymbol *)path;
  v2 = &sGameStatTracker;
  if ( *(_DWORD *)path != 188606418 )
  {
    if ( *(_DWORD *)path == 2092809126 )
    {
      v3 = UFG::GameStatTracker::Instance();
      if ( !(*((_BYTE *)v3 + 6216) & 1) )
      {
        ++v3->mpSnapshots[0]->mInts[121].mValue;
        if ( UFG::GameStatAction::PostStat::sIsEnabled )
        {
          v4 = _S12_6;
          if ( !(_S12_6 & 1) )
          {
            _S12_6 |= 1u;
            UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
            atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
            v4 = _S12_6;
          }
          v5 = UFG::GameStatTracker::mspInstance;
          if ( !UFG::GameStatTracker::mspInstance )
          {
            v5 = &sGameStatTracker;
            UFG::GameStatTracker::mspInstance = &sGameStatTracker;
          }
          goto LABEL_17;
        }
      }
    }
LABEL_16:
    v4 = _S12_6;
    v5 = UFG::GameStatTracker::mspInstance;
    goto LABEL_17;
  }
  v6 = UFG::GameStatTracker::Instance();
  if ( *((_BYTE *)v6 + 6216) & 1 )
    goto LABEL_16;
  ++v6->mpSnapshots[0]->mInts[120].mValue;
  if ( !UFG::GameStatAction::PostStat::sIsEnabled )
    goto LABEL_16;
  v4 = _S12_6;
  if ( !(_S12_6 & 1) )
  {
    _S12_6 |= 1u;
    UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
    atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
    v4 = _S12_6;
  }
  v5 = &sGameStatTracker;
  if ( UFG::GameStatTracker::mspInstance )
    v5 = UFG::GameStatTracker::mspInstance;
  UFG::GameStatTracker::mspInstance = v5;
LABEL_17:
  if ( !(v4 & 1) )
  {
    _S12_6 = v4 | 1;
    UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
    atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
    v5 = UFG::GameStatTracker::mspInstance;
  }
  if ( v5 )
    v2 = v5;
  UFG::GameStatTracker::mspInstance = v2;
  if ( !(*((_BYTE *)v2 + 6216) & 1) )
  {
    UFG::PersistentData::MapInt::ApplyDelta(v2->mpSnapshots[0]->mpMapInts[24], v1, 1);
    v7 = v1->mUID;
    if ( UFG::GameStatAction::PostStat::sIsEnabled )
    {
      v9 = &mapid;
      mapid.mUID = v7;
      UFG::GameStatAction::PostStat::AchieveMapInt(SpecialMoves, (UFG::qSymbol)&mapid);
    }
  }
}

// File Line: 670
// RVA: 0x496D10
void __fastcall UFG::GameStatAction::Player::ClampAndApplyDeltaCombatMeter(float deltaFaceValue, unsigned int faceadjustmenttype)
{
  unsigned int v2; // edi
  UFG::GameStatTracker *v3; // rbx
  unsigned __int16 v4; // dx
  UFG::SimComponent *v5; // rax
  float v6; // xmm6_4
  float v7; // xmm6_4
  UFG::GameStatTracker *v8; // rax
  int v9; // xmm6_4
  UFG::GameStatTracker *v10; // rax
  UFG::GameStat::FloatStat v11; // edx

  v2 = faceadjustmenttype;
  v3 = &sGameStatTracker;
  if ( !(_S12_6 & 1) )
  {
    _S12_6 |= 1u;
    UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
    atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
  }
  if ( UFG::GameStatTracker::mspInstance )
    v3 = UFG::GameStatTracker::mspInstance;
  UFG::GameStatTracker::mspInstance = v3;
  if ( (float)v3->mpSnapshots[0]->mInts[29].mValue >= 1000.0 && LocalPlayer )
  {
    v4 = LocalPlayer->m_Flags;
    if ( (v4 >> 14) & 1 )
    {
      v5 = UFG::SimObjectGame::GetComponentOfTypeHK(
             (UFG::SimObjectGame *)&LocalPlayer->vfptr,
             UFG::FaceMeterComponent::_TypeUID);
    }
    else if ( (v4 & 0x8000u) == 0 )
    {
      if ( (v4 >> 13) & 1 )
        v5 = UFG::SimObjectGame::GetComponentOfTypeHK(
               (UFG::SimObjectGame *)&LocalPlayer->vfptr,
               UFG::FaceMeterComponent::_TypeUID);
      else
        v5 = (v4 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                (UFG::SimObjectGame *)&LocalPlayer->vfptr,
                                UFG::FaceMeterComponent::_TypeUID) : UFG::SimObject::GetComponentOfType(
                                                                       (UFG::SimObject *)&LocalPlayer->vfptr,
                                                                       UFG::FaceMeterComponent::_TypeUID);
    }
    else
    {
      v5 = UFG::SimObjectGame::GetComponentOfTypeHK(
             (UFG::SimObjectGame *)&LocalPlayer->vfptr,
             UFG::FaceMeterComponent::_TypeUID);
    }
    if ( v5 && LOBYTE(v5[135].m_SafePointerList.mNode.mPrev) )
    {
      v6 = UFG::GameStatTracker::Instance()->mpSnapshots[0]->mFloats[43].mValue;
      UFG::GameStatAction::Player::ClampAndSetCombatMeter(v6 + deltaFaceValue);
      v7 = v6 - UFG::GameStatTracker::Instance()->mpSnapshots[0]->mFloats[43].mValue;
      if ( v2 == sFaceEventSymbol_FaceTypeGained.mUID )
      {
        v8 = UFG::GameStatTracker::Instance();
        if ( !(*((_BYTE *)v8 + 6216) & 1) )
          v8->mpSnapshots[0]->mFloats[44].mValue = v7 + v8->mpSnapshots[0]->mFloats[44].mValue;
      }
      else
      {
        if ( v2 == sFaceEventSymbol_FaceTypeUsed.mUID )
        {
          v9 = LODWORD(v7) ^ _xmm[0];
          v10 = UFG::GameStatTracker::Instance();
          v11 = 0x2D;
        }
        else
        {
          if ( v2 != sFaceEventSymbol_FaceTypeLost.mUID )
            return;
          v9 = LODWORD(v7) ^ _xmm[0];
          v10 = UFG::GameStatTracker::Instance();
          v11 = 0x2E;
        }
        UFG::GameStatTracker::ApplyDelta(v10, v11, *(float *)&v9);
      }
    }
  }
}

// File Line: 700
// RVA: 0x496EE0
void __fastcall UFG::GameStatAction::Player::ClampAndSetCombatMeter(float val)
{
  float v1; // xmm6_4
  UFG::GameStatTracker *v2; // rbx

  if ( val <= 0.0 )
  {
    val = 0.0;
    goto LABEL_5;
  }
  v1 = FLOAT_100_0;
  if ( val < 100.0 )
LABEL_5:
    v1 = val;
  v2 = &sGameStatTracker;
  if ( !(_S12_6 & 1) )
  {
    _S12_6 |= 1u;
    UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
    atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
  }
  if ( UFG::GameStatTracker::mspInstance )
    v2 = UFG::GameStatTracker::mspInstance;
  UFG::GameStatTracker::mspInstance = v2;
  if ( !(*((_BYTE *)v2 + 6216) & 1) )
    v2->mpSnapshots[0]->mFloats[0x2B].mValue = v1;
}

// File Line: 708
// RVA: 0x4BCB40
void __fastcall UFG::GameStatAction::Player::SetHeat(float heat)
{
  unsigned int v1; // ecx
  UFG::GameStatTracker *v2; // rbx
  UFG::GameStatTracker *v3; // rdx
  UFG::GameSnapshot *v4; // rax

  v1 = _S12_6;
  v2 = &sGameStatTracker;
  if ( !(_S12_6 & 1) )
  {
    _S12_6 |= 1u;
    UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
    atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
    v1 = _S12_6;
  }
  v3 = &sGameStatTracker;
  if ( UFG::GameStatTracker::mspInstance )
    v3 = UFG::GameStatTracker::mspInstance;
  UFG::GameStatTracker::mspInstance = v3;
  if ( !(*((_BYTE *)v3 + 6216) & 1) )
  {
    v3->mpSnapshots[0]->mFloats[41].mValue = heat;
    v3 = UFG::GameStatTracker::mspInstance;
  }
  if ( !(v1 & 1) )
  {
    _S12_6 = v1 | 1;
    UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
    atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
    v3 = UFG::GameStatTracker::mspInstance;
  }
  if ( v3 )
    v2 = v3;
  UFG::GameStatTracker::mspInstance = v2;
  if ( !(*((_BYTE *)v2 + 6216) & 1) )
  {
    v4 = v2->mpSnapshots[0];
    if ( heat > v4->mFloats[42].mValue )
      v4->mFloats[42].mValue = heat;
  }
}

// File Line: 714
// RVA: 0x4B1380
void __fastcall UFG::GameStatAction::Player::NotifyHeatLevelChange(UFG::HeatLevelEnum oldHL, UFG::HeatLevelEnum heatLevel)
{
  UFG::HeatLevelEnum v2; // edi
  UFG::HeatLevelEnum v3; // er14
  unsigned int v4; // er8
  UFG::GameStatTracker *v5; // rbx
  UFG::GameStatTracker *v6; // rcx
  UFG::SimpleTimer *v7; // rsi
  UFG::GameStatTracker *v8; // rax
  UFG::SimpleTimer *v9; // rbp
  float v10; // xmm6_4
  UFG::GameStatTracker *v11; // rcx
  UFG::GameSnapshot *v12; // rax
  float v13; // xmm6_4
  UFG::GameSnapshot *v14; // rax

  v2 = heatLevel;
  v3 = oldHL;
  v4 = _S12_6;
  v5 = &sGameStatTracker;
  if ( !(_S12_6 & 1) )
  {
    _S12_6 |= 1u;
    UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
    atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
    v4 = _S12_6;
  }
  v6 = &sGameStatTracker;
  if ( UFG::GameStatTracker::mspInstance )
    v6 = UFG::GameStatTracker::mspInstance;
  UFG::GameStatTracker::mspInstance = v6;
  v7 = &v6->mpSnapshots[0]->mTimes[13].mTimer;
  if ( !(v4 & 1) )
  {
    _S12_6 = v4 | 1;
    UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
    atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
    v6 = UFG::GameStatTracker::mspInstance;
  }
  v8 = &sGameStatTracker;
  if ( v6 )
    v8 = v6;
  UFG::GameStatTracker::mspInstance = v8;
  v9 = &v8->mpSnapshots[0]->mTimes[14].mTimer;
  if ( (signed int)v3 > 0 )
  {
    if ( (signed int)v2 <= 0 )
      UFG::SimpleTimer::Stop(v7);
  }
  else if ( (signed int)v2 > 0 )
  {
    UFG::SimpleTimer::Resume(v7);
  }
  if ( (signed int)v3 >= 5 )
  {
    if ( (signed int)v2 < 5 )
      UFG::SimpleTimer::Stop(v9);
  }
  else if ( (signed int)v2 >= 5 )
  {
    UFG::SimpleTimer::Resume(v9);
  }
  v10 = UFG::SimpleTimer::GetElapsedSeconds(v7);
  if ( !(_S12_6 & 1) )
  {
    _S12_6 |= 1u;
    UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
    atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
  }
  v11 = &sGameStatTracker;
  if ( UFG::GameStatTracker::mspInstance )
    v11 = UFG::GameStatTracker::mspInstance;
  UFG::GameStatTracker::mspInstance = v11;
  if ( !(*((_BYTE *)v11 + 6216) & 1) )
  {
    v12 = v11->mpSnapshots[0];
    if ( v10 > v12->mFloats[110].mValue )
      v12->mFloats[110].mValue = v10;
  }
  v13 = UFG::SimpleTimer::GetElapsedSeconds(v9);
  if ( !(_S12_6 & 1) )
  {
    _S12_6 |= 1u;
    UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
    atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
  }
  if ( UFG::GameStatTracker::mspInstance )
    v5 = UFG::GameStatTracker::mspInstance;
  UFG::GameStatTracker::mspInstance = v5;
  if ( !(*((_BYTE *)v5 + 6216) & 1) )
  {
    v14 = v5->mpSnapshots[0];
    if ( v13 > v14->mFloats[111].mValue )
      v14->mFloats[111].mValue = v13;
  }
  if ( (signed int)v3 > 0 && (signed int)v2 <= 0 )
    UFG::SimpleTimer::GetElapsedSeconds(v7);
}

// File Line: 747
// RVA: 0x4B52F0
void __fastcall UFG::GameStatAction::Player::RegisterSuccessFaceEvent(UFG::qSymbol *faceadjustmenttype)
{
  unsigned int v1; // eax
  UFG::GameStatTracker *v2; // rax
  UFG::GameStatTracker *v3; // rbx
  UFG::GameStatTracker *v4; // rax
  UFG::GameStatTracker *v5; // rax

  v1 = faceadjustmenttype->mUID;
  if ( faceadjustmenttype->mUID == sFaceEventSymbol_FaceTypeGained.mUID )
  {
    v2 = UFG::GameStatTracker::Instance();
    if ( !(*((_BYTE *)v2 + 6216) & 1) )
    {
      ++v2->mpSnapshots[0]->mInts[33].mValue;
      if ( UFG::GameStatAction::PostStat::sIsEnabled )
      {
        v3 = &sGameStatTracker;
        if ( !(_S12_6 & 1) )
        {
          _S12_6 |= 1u;
          UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
          atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
        }
        if ( !UFG::GameStatTracker::mspInstance )
        {
LABEL_22:
          UFG::GameStatTracker::mspInstance = v3;
          return;
        }
      }
    }
  }
  else if ( v1 == sFaceEventSymbol_FaceTypeUsed.mUID )
  {
    v4 = UFG::GameStatTracker::Instance();
    if ( !(*((_BYTE *)v4 + 6216) & 1) )
    {
      ++v4->mpSnapshots[0]->mInts[33].mValue;
      if ( UFG::GameStatAction::PostStat::sIsEnabled )
      {
        v3 = &sGameStatTracker;
        if ( !(_S12_6 & 1) )
        {
          _S12_6 |= 1u;
          UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
          atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
        }
        if ( !UFG::GameStatTracker::mspInstance )
          goto LABEL_22;
      }
    }
  }
  else if ( v1 == sFaceEventSymbol_FaceTypeLost.mUID )
  {
    v5 = UFG::GameStatTracker::Instance();
    if ( !(*((_BYTE *)v5 + 6216) & 1) )
    {
      ++v5->mpSnapshots[0]->mInts[34].mValue;
      if ( UFG::GameStatAction::PostStat::sIsEnabled )
      {
        v3 = &sGameStatTracker;
        if ( !(_S12_6 & 1) )
        {
          _S12_6 |= 1u;
          UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
          atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
        }
        if ( UFG::GameStatTracker::mspInstance )
          v3 = UFG::GameStatTracker::mspInstance;
        goto LABEL_22;
      }
    }
  }
}

// File Line: 766
// RVA: 0x4A75A0
void __fastcall UFG::GameStatAction::Player::HandleGameStatEvent(UFG::SimObject *me, UFG::SimObject *target, unsigned int iEnum)
{
  unsigned int v3; // esi
  UFG::SimObjectCharacter *v4; // rbp
  UFG::SimObjectGame *v5; // rdi
  unsigned __int16 v6; // cx
  UFG::HitReactionComponent *v7; // rax
  UFG::SimObjectCharacter *v8; // rax
  UFG::SimObjectWeaponPropertiesComponent *v9; // rax
  bool v10; // al
  UFG::OSuiteLeaderboardManager *v11; // rax
  const char *v12; // rdx
  UFG::OSuiteLeaderboardManager *v13; // rax
  UFG::OSuiteLeaderboardData *v14; // rax
  UFG::GameStatTracker *v15; // rax
  UFG::OSuiteLeaderboardManager *v16; // rax
  UFG::OSuiteLeaderboardData *v17; // rax
  UFG::GameStatTracker *v18; // rax
  UFG::GameStatTracker *v19; // rax
  UFG::GameStatTracker *v20; // rbx
  UFG::CopSystem *v21; // rax
  UFG::GameStatTracker *v22; // rax
  UFG::OSuiteLeaderboardData *v23; // rax
  UFG::OSuiteLeaderboardManager *v24; // rax
  UFG::OSuiteLeaderboardData *v25; // rax
  UFG::OSuiteLeaderboardManager *v26; // rax
  const char *v27; // rdx
  UFG::OSuiteLeaderboardData *v28; // rax
  UFG::OSuiteLeaderboardManager *v29; // rax
  UFG::OSuiteLeaderboardData *v30; // rax
  UFG::GameStatTracker *v31; // rax
  UFG::GameStatTracker *v32; // rax
  UFG::GameStatTracker *v33; // rax
  UFG::GameStatTracker *v34; // rax
  unsigned __int16 v35; // cx
  UFG::CharacterOccupantComponent *v36; // rax
  UFG::SimObjectCVBase *v37; // rax
  UFG::BikeHumanDriverComponent *v38; // rax
  unsigned __int16 v39; // cx
  UFG::CharacterOccupantComponent *v40; // rax
  UFG::SimObjectCVBase *v41; // rax
  UFG::BikeHumanDriverComponent *v42; // rax
  UFG::qSymbol result; // [rsp+40h] [rbp+8h]

  v3 = iEnum;
  v4 = (UFG::SimObjectCharacter *)target;
  v5 = (UFG::SimObjectGame *)me;
  if ( me == (UFG::SimObject *)UFG::GetLocalPlayer() )
  {
    switch ( v3 )
    {
      case 2u:
        if ( v5 )
        {
          v39 = v5->m_Flags;
          if ( (v39 >> 14) & 1 )
          {
            v40 = (UFG::CharacterOccupantComponent *)v5->m_Components.p[44].m_pComponent;
          }
          else if ( (v39 & 0x8000u) == 0 )
          {
            if ( (v39 >> 13) & 1 )
              v40 = (UFG::CharacterOccupantComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                         v5,
                                                         UFG::CharacterOccupantComponent::_TypeUID);
            else
              v40 = (UFG::CharacterOccupantComponent *)((v39 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                            v5,
                                                                            UFG::CharacterOccupantComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v5->vfptr, UFG::CharacterOccupantComponent::_TypeUID));
          }
          else
          {
            v40 = (UFG::CharacterOccupantComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                       v5,
                                                       UFG::CharacterOccupantComponent::_TypeUID);
          }
          if ( v40 )
          {
            v41 = (UFG::SimObjectCVBase *)UFG::CharacterOccupantComponent::GetCurrentVehicle(v40);
            if ( v41 )
            {
              v42 = UFG::SimObjectCVBase::GetComponent<UFG::BikeHumanDriverComponent>(v41);
              if ( v42 )
                UFG::BikeHumanDriverComponent::WheelieStop(v42);
            }
          }
        }
        return;
      case 3u:
        if ( v5 )
        {
          v35 = v5->m_Flags;
          if ( (v35 >> 14) & 1 )
          {
            v36 = (UFG::CharacterOccupantComponent *)v5->m_Components.p[44].m_pComponent;
          }
          else if ( (v35 & 0x8000u) == 0 )
          {
            if ( (v35 >> 13) & 1 )
              v36 = (UFG::CharacterOccupantComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                         v5,
                                                         UFG::CharacterOccupantComponent::_TypeUID);
            else
              v36 = (UFG::CharacterOccupantComponent *)((v35 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                            v5,
                                                                            UFG::CharacterOccupantComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v5->vfptr, UFG::CharacterOccupantComponent::_TypeUID));
          }
          else
          {
            v36 = (UFG::CharacterOccupantComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                       v5,
                                                       UFG::CharacterOccupantComponent::_TypeUID);
          }
          if ( v36 )
          {
            v37 = (UFG::SimObjectCVBase *)UFG::CharacterOccupantComponent::GetCurrentVehicle(v36);
            if ( v37 )
            {
              v38 = UFG::SimObjectCVBase::GetComponent<UFG::BikeHumanDriverComponent>(v37);
              if ( v38 )
                UFG::BikeHumanDriverComponent::WheelieStart(v38);
            }
          }
        }
        return;
      case 7u:
        v34 = UFG::GameStatTracker::Instance();
        UFG::SimpleTimer::Stop(&v34->mpSnapshots[0]->mTimes[5].mTimer);
        return;
      case 8u:
        v33 = UFG::GameStatTracker::Instance();
        UFG::SimpleTimer::Resume(&v33->mpSnapshots[0]->mTimes[5].mTimer);
        return;
      case 0x15u:
        v11 = UFG::OSuiteLeaderboardManager::Instance();
        v12 = "StatAwardsLuckyShooter";
        goto LABEL_54;
      case 0x16u:
        v15 = UFG::GameStatTracker::Instance();
        if ( *((_BYTE *)v15 + 6216) & 1 )
          return;
        ++v15->mpSnapshots[0]->mInts[95].mValue;
        if ( !UFG::GameStatAction::PostStat::sIsEnabled )
          return;
        if ( !(_S12_6 & 1) )
        {
          _S12_6 |= 1u;
          UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
          atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
        }
        goto LABEL_51;
      case 0x17u:
        v11 = UFG::OSuiteLeaderboardManager::Instance();
        v12 = "StatAwardsWrecker";
        goto LABEL_54;
      case 0x19u:
        v16 = UFG::OSuiteLeaderboardManager::Instance();
        v17 = UFG::OSuiteLeaderboardManager::GetLeaderboardDataUsingLeaderboardName(v16, "StatAwardsDefence");
        UFG::DataSynchronizer::ApplyDeltaToGlobalSnapshot(v17, 1);
        UFG::GameStatAction::MissionScoring::LogTriadEvent(TRIAD_MELEE_COUNTER, 0, &customWorldMapCaption);
        return;
      case 0x1Au:
        v18 = UFG::GameStatTracker::Instance();
        if ( *((_BYTE *)v18 + 6216) & 1 )
          return;
        ++v18->mpSnapshots[0]->mInts[32].mValue;
        if ( !UFG::GameStatAction::PostStat::sIsEnabled )
          return;
        if ( !(_S12_6 & 1) )
        {
          _S12_6 |= 1u;
          UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
          atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
        }
        goto LABEL_51;
      case 0x1Eu:
        v24 = UFG::OSuiteLeaderboardManager::Instance();
        v25 = UFG::OSuiteLeaderboardManager::GetLeaderboardDataUsingLeaderboardName(v24, "StatAwardsDisarming");
        UFG::DataSynchronizer::ApplyDeltaToGlobalSnapshot(v25, 1);
        UFG::GameStatAction::MissionScoring::LogTriadEvent(TRIAD_WEAPON_DISARM, 0, &customWorldMapCaption);
        return;
      case 0x25u:
        v11 = UFG::OSuiteLeaderboardManager::Instance();
        v12 = "StatAwardsFirestarter";
        goto LABEL_54;
      case 0x29u:
        v13 = UFG::OSuiteLeaderboardManager::Instance();
        v14 = UFG::OSuiteLeaderboardManager::GetLeaderboardDataUsingLeaderboardName(v13, "StatAwardsFastTalker");
        UFG::DataSynchronizer::ApplyDeltaToGlobalSnapshot(v14, 1);
        UFG::GameStatAction::MissionScoring::LogTriadEvent(TRIAD_FAST_TALK, 0, &customWorldMapCaption);
        return;
      case 0x39u:
        v11 = UFG::OSuiteLeaderboardManager::Instance();
        v12 = "StatAwardsBonebreaker";
        goto LABEL_54;
      case 0x45u:
        v26 = UFG::OSuiteLeaderboardManager::Instance();
        v27 = "StatGamesFlyingKicks";
        goto LABEL_58;
      case 0x47u:
        v11 = UFG::OSuiteLeaderboardManager::Instance();
        v12 = "StatAwardsNinja";
        goto LABEL_54;
      case 0x48u:
        goto LABEL_46;
      case 0x4Du:
        v26 = UFG::OSuiteLeaderboardManager::Instance();
        v27 = "StatGamesTackles";
LABEL_58:
        v28 = UFG::OSuiteLeaderboardManager::GetLeaderboardDataUsingLeaderboardName(v26, v27);
        UFG::StatGameManager::UpdateScore(v28, 1, 1);
        return;
      case 0x51u:
        v11 = UFG::OSuiteLeaderboardManager::Instance();
        v12 = "StatAwardsDeadeye";
        goto LABEL_54;
      case 0x52u:
      case 0x54u:
      case 0x57u:
        v22 = UFG::GameStatTracker::Instance();
        if ( !(*((_BYTE *)v22 + 6216) & 1) )
        {
          ++v22->mpSnapshots[0]->mInts[13].mValue;
          if ( UFG::GameStatAction::PostStat::sIsEnabled )
          {
            if ( !(_S12_6 & 1) )
            {
              _S12_6 |= 1u;
              UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
              atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
            }
LABEL_51:
            if ( !UFG::GameStatTracker::mspInstance )
              UFG::GameStatTracker::mspInstance = &sGameStatTracker;
          }
        }
        break;
      case 0x53u:
      case 0x55u:
      case 0x59u:
        v19 = UFG::GameStatTracker::Instance();
        if ( !(*((_BYTE *)v19 + 6216) & 1) )
        {
          ++v19->mpSnapshots[0]->mInts[12].mValue;
          if ( UFG::GameStatAction::PostStat::sIsEnabled )
          {
            v20 = &sGameStatTracker;
            if ( !(_S12_6 & 1) )
            {
              _S12_6 |= 1u;
              UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
              atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
            }
            if ( UFG::GameStatTracker::mspInstance )
              v20 = UFG::GameStatTracker::mspInstance;
            UFG::GameStatTracker::mspInstance = v20;
          }
        }
LABEL_46:
        v21 = UFG::CopSystem::Instance();
        UFG::CopSystem::TriggerOnFootNoSprint(v21);
        break;
      case 0x56u:
        v11 = UFG::OSuiteLeaderboardManager::Instance();
        v12 = "StatAwardsFluidStriker";
LABEL_54:
        v23 = UFG::OSuiteLeaderboardManager::GetLeaderboardDataUsingLeaderboardName(v11, v12);
        UFG::DataSynchronizer::ApplyDeltaToGlobalSnapshot(v23, 1);
        break;
      case 0x60u:
        v29 = UFG::OSuiteLeaderboardManager::Instance();
        v30 = UFG::OSuiteLeaderboardManager::GetLeaderboardDataUsingLeaderboardName(v29, "StatAwardsHijacker");
        UFG::DataSynchronizer::ApplyDeltaToGlobalSnapshot(v30, 1);
        v31 = UFG::GameStatTracker::Instance();
        if ( !(*((_BYTE *)v31 + 6216) & 1) )
        {
          ++v31->mpSnapshots[0]->mInts[89].mValue;
          if ( UFG::GameStatAction::PostStat::sIsEnabled )
            UFG::GameStatAction::PostStat::AchieveInt(VehiclesActionHijacked);
        }
        UFG::AchievementTrophyManager::UnlockAchievementTrophy(9);
        break;
      case 0x61u:
        UFG::GameStatAction::MissionScoring::LogTriadEvent(TRIAD_VEHICLE_ACTIONHIJACK, 0, &customWorldMapCaption);
        break;
      case 0x67u:
      case 0x6Au:
        v32 = UFG::GameStatTracker::Instance();
        if ( !(*((_BYTE *)v32 + 6216) & 1) )
        {
          ++v32->mpSnapshots[0]->mInts[88].mValue;
          if ( UFG::GameStatAction::PostStat::sIsEnabled )
            UFG::GameStatAction::PostStat::AchieveInt(VehiclesStolen);
        }
        UFG::GameStatAction::MissionScoring::LogCopEvent(COP_VEHICLE_STEAL, 0, &customWorldMapCaption);
        break;
      default:
        return;
    }
  }
  else if ( v4 == UFG::GetLocalPlayer() && v3 == 91 && v5 )
  {
    v6 = v5->m_Flags;
    if ( (v6 >> 14) & 1 )
    {
      v7 = (UFG::HitReactionComponent *)v5->m_Components.p[15].m_pComponent;
    }
    else if ( (v6 & 0x8000u) == 0 )
    {
      if ( (v6 >> 13) & 1 )
        v7 = (UFG::HitReactionComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                            v5,
                                            UFG::HitReactionComponent::_TypeUID);
      else
        v7 = (UFG::HitReactionComponent *)((v6 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                              v5,
                                                              UFG::HitReactionComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v5->vfptr, UFG::HitReactionComponent::_TypeUID));
    }
    else
    {
      v7 = (UFG::HitReactionComponent *)v5->m_Components.p[15].m_pComponent;
    }
    if ( v7 && v7->mHitRecord.mIsDeadly )
    {
      v8 = UFG::GetLocalPlayer();
      v9 = UFG::GameStatAction::Weapon::GetHoldingWeapon((UFG::SimObject *)&v8->vfptr);
      v10 = v9 && UFG::SimObjectWeaponPropertiesComponent::GetWeaponID(v9, &result)->mUID == sSym_CombatFish.mUID;
      if ( v10 )
        UFG::AchievementTrophyManager::UnlockAchievementTrophy(10);
    }
  }
}

// File Line: 973
// RVA: 0x4B5ED0
UFG::qSymbol *__fastcall UFG::GameStatAction::RegisterWeaponKill(UFG::qSymbol *result, UFG::GameStatTracker *gst, UFG::HitRecord *hitRecord, UFG::qString *reason, const char *reason_text)
{
  UFG::qSymbol *v5; // rdi
  UFG::HitRecord *v6; // rbx

  v5 = result;
  v6 = hitRecord;
  UFG::qString::Format(reason, reason_text);
  UFG::SimObjectWeaponPropertiesComponent::GetWeaponID(
    (UFG::SimObjectWeaponPropertiesComponent *)v6->mProjectileInfo.m_pSOWPC.m_pPointer,
    v5);
  return v5;
}

// File Line: 979
// RVA: 0x4B4D10
void __fastcall UFG::GameStatAction::Player::RegisterPlayerDeath(UFG::SimObject *src, UFG::HitRecord *hitRecord)
{
  UFG::HitRecord *v2; // r14
  UFG::SimObjectGame *v3; // r15
  UFG::GameStatTracker *v4; // rsi
  UFG::GameStatTracker *v5; // rdi
  int v6; // ebx
  UFG::SimObjectCharacter *v7; // rax
  UFG::SimObjectWeaponPropertiesComponent *v8; // rax
  unsigned int v9; // edx
  UFG::GameStatTracker *v10; // rcx
  unsigned __int16 v11; // cx
  UFG::SimComponent *v12; // rax
  UFG::SceneObjectProperties *v13; // rcx
  int v14; // eax
  const char *v15; // rax
  UFG::SimObjectWeaponPropertiesComponent *v16; // rsi
  UFG::SimObject *v17; // rsi
  unsigned __int16 v18; // cx
  UFG::SimComponent *v19; // rax
  bool v20; // zf
  UFG::SimObjectGame *v21; // rcx
  UFG::SceneObjectProperties *v22; // rcx
  UFG::SimObjectCharacter *v23; // rax
  UFG::TransformNodeComponent *v24; // rcx
  UFG::OSuiteDBLogger *v25; // r15
  unsigned int v26; // er12
  __int64 v27; // rcx
  EnumList<unsigned long> *v28; // rax
  unsigned int v29; // esi
  unsigned int v30; // er14
  char *v31; // rdi
  char *v32; // rax
  char *reason_text; // [rsp+20h] [rbp-99h]
  UFG::qString reason; // [rsp+30h] [rbp-89h]
  __int64 v35; // [rsp+58h] [rbp-61h]
  char dest; // [rsp+60h] [rbp-59h]
  UFG::qSymbolUC v37; // [rsp+120h] [rbp+67h]
  UFG::qSymbolUC v38; // [rsp+128h] [rbp+6Fh]
  UFG::qSymbol result; // [rsp+130h] [rbp+77h]

  v35 = -2i64;
  v2 = hitRecord;
  v3 = (UFG::SimObjectGame *)src;
  UFG::qString::qString(&reason);
  v4 = &sGameStatTracker;
  if ( !(_S12_6 & 1) )
  {
    _S12_6 |= 1u;
    UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
    atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
  }
  v5 = &sGameStatTracker;
  if ( UFG::GameStatTracker::mspInstance )
    v5 = UFG::GameStatTracker::mspInstance;
  UFG::GameStatTracker::mspInstance = v5;
  v6 = UFG::gNullQSymbol.mUID;
  v38.mUID = UFG::gNullQSymbol.mUID;
  v37.mUID = UFG::gNullQSymbol.mUID;
  v7 = UFG::GetLocalPlayer();
  v8 = UFG::GameStatAction::Weapon::GetHoldingWeapon((UFG::SimObject *)&v7->vfptr);
  if ( v8 )
    v6 = UFG::SimObjectWeaponPropertiesComponent::GetWeaponID(v8, &result)->mUID;
  if ( *((_BYTE *)v5 + 6216) & 1
    || (v5->mpSnapshots[0]->mIDs[34].mValue.mUID = v6, *((_BYTE *)v5 + 6216) & 1)
    || (++v5->mpSnapshots[0]->mInts[2].mValue, !UFG::GameStatAction::PostStat::sIsEnabled) )
  {
    v9 = _S12_6;
  }
  else
  {
    v9 = _S12_6;
    if ( !(_S12_6 & 1) )
    {
      _S12_6 |= 1u;
      UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
      atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
      v9 = _S12_6;
    }
    v10 = &sGameStatTracker;
    if ( UFG::GameStatTracker::mspInstance )
      v10 = UFG::GameStatTracker::mspInstance;
    UFG::GameStatTracker::mspInstance = v10;
  }
  if ( v3 )
  {
    v11 = v3->m_Flags;
    if ( (v11 >> 14) & 1 )
    {
      v12 = v3->m_Components.p[23].m_pComponent;
    }
    else if ( (v11 & 0x8000u) == 0 )
    {
      if ( (v11 >> 13) & 1 )
        v12 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::VehicleDriverInterface::_TypeUID);
      else
        v12 = (v11 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::VehicleDriverInterface::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::VehicleDriverInterface::_TypeUID);
      v9 = _S12_6;
    }
    else
    {
      v12 = v3->m_Components.p[23].m_pComponent;
    }
    if ( v12 )
    {
      if ( !(*((_BYTE *)v5 + 6216) & 1) )
      {
        ++v5->mpSnapshots[0]->mInts[5].mValue;
        if ( UFG::GameStatAction::PostStat::sIsEnabled )
        {
          if ( !(v9 & 1) )
          {
            _S12_6 = v9 | 1;
            UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
            atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
          }
          if ( UFG::GameStatTracker::mspInstance )
            v4 = UFG::GameStatTracker::mspInstance;
          UFG::GameStatTracker::mspInstance = v4;
        }
      }
      UFG::qString::Format(&reason, "Killed from vehicle");
      v13 = v3->m_pSceneObj;
      if ( v13 )
        v37.mUID = UFG::SceneObjectProperties::GetArchetypePropertiesName(v13)->mUID;
      goto LABEL_61;
    }
  }
  if ( v2->mProjectileInfo.m_pSOWPC.m_pPointer )
  {
    if ( !(*((_BYTE *)v5 + 6216) & 1) )
    {
      ++v5->mpSnapshots[0]->mInts[3].mValue;
      if ( UFG::GameStatAction::PostStat::sIsEnabled )
      {
        if ( !(v9 & 1) )
        {
          _S12_6 = v9 | 1;
          UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
          atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
        }
        if ( UFG::GameStatTracker::mspInstance )
          v4 = UFG::GameStatTracker::mspInstance;
        UFG::GameStatTracker::mspInstance = v4;
      }
    }
    v14 = **((_DWORD **)&v2->mProjectileInfo.m_pSOWPC.m_pPointer[2].m_BoundComponentHandles.mNode.mPrev->mNext
           + HIDWORD(v2->mProjectileInfo.m_pSOWPC.m_pPointer[2].m_pSimObject));
    if ( v14 == UFG::gSimObjectWeaponTypeTrackEnum_eSIM_OBJ_WEAPON_TYPE_PISTOL.m_EnumValue )
    {
      v15 = "Killed from pistol";
LABEL_54:
      UFG::GameStatAction::RegisterWeaponKill(&result, v5, v2, &reason, v15);
      goto LABEL_61;
    }
    if ( v14 != UFG::gSimObjectWeaponTypeTrackEnum_eSIM_OBJ_WEAPON_TYPE_RIFLE.m_EnumValue )
    {
      if ( v14 == UFG::gSimObjectWeaponTypeTrackEnum_eSIM_OBJ_WEAPON_TYPE_SHOTGUN.m_EnumValue )
      {
        v15 = "Killed from shotgun";
        goto LABEL_54;
      }
      if ( v14 == UFG::gSimObjectWeaponTypeTrackEnum_eSIM_OBJ_WEAPON_TYPE_SMG.m_EnumValue )
      {
        v15 = "Killed from SMG";
        goto LABEL_54;
      }
      if ( v14 != UFG::gSimObjectWeaponTypeTrackEnum_eSIM_OBJ_WEAPON_TYPE_SNIPER.m_EnumValue )
        goto LABEL_61;
    }
    v15 = "Killed from rifle";
    goto LABEL_54;
  }
  if ( !(*((_BYTE *)v5 + 6216) & 1) )
  {
    ++v5->mpSnapshots[0]->mInts[4].mValue;
    if ( UFG::GameStatAction::PostStat::sIsEnabled )
      UFG::GameStatAction::PostStat::AchieveInt(KilledByMelee);
  }
  if ( v2->mMeleeInfo.mAttackMaterialUID == gAttackMaterialWeaponEquipped.m_EnumSymbol.mUID )
  {
    v16 = UFG::GameStatAction::Weapon::GetHoldingWeapon(v2->mAttacker.m_pPointer);
    UFG::qString::Format(&reason, "Killed from melee");
    if ( v16 )
      v38.mUID = UFG::SimObjectWeaponPropertiesComponent::GetWeaponID(v16, &result)->mUID;
  }
LABEL_61:
  v17 = v2->mAttacker.m_pPointer;
  if ( v17 )
  {
    v18 = v17->m_Flags;
    if ( (v18 >> 14) & 1 )
    {
      v19 = v17->m_Components.p[19].m_pComponent;
    }
    else if ( (v18 & 0x8000u) == 0 )
    {
      if ( (v18 >> 13) & 1 )
      {
        v19 = UFG::SimObjectGame::GetComponentOfTypeHK(
                (UFG::SimObjectGame *)v2->mAttacker.m_pPointer,
                UFG::AIActionTreeComponent::_TypeUID);
      }
      else
      {
        v20 = ((v18 >> 12) & 1) == 0;
        v21 = (UFG::SimObjectGame *)v2->mAttacker.m_pPointer;
        v19 = v20 ? UFG::SimObject::GetComponentOfType(
                      (UFG::SimObject *)&v21->vfptr,
                      UFG::AIActionTreeComponent::_TypeUID) : UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                v21,
                                                                UFG::AIActionTreeComponent::_TypeUID);
      }
    }
    else
    {
      v19 = v17->m_Components.p[19].m_pComponent;
    }
    if ( v19 )
    {
      v22 = v17->m_pSceneObj;
      if ( v22 )
        v37.mUID = UFG::SceneObjectProperties::GetArchetypePropertiesName(v22)->mUID;
      UFG::qString::Format(&reason, "%s by %d", reason.mData, v37.mUID);
    }
  }
  if ( !(*((_BYTE *)v5 + 6216) & 1) )
  {
    v5->mpSnapshots[0]->mIDs[32].mValue.mUID = v37.mUID;
    if ( !(*((_BYTE *)v5 + 6216) & 1) )
      v5->mpSnapshots[0]->mIDs[33].mValue.mUID = v38.mUID;
  }
  v23 = UFG::GetLocalPlayer();
  if ( v23 )
  {
    v24 = (UFG::TransformNodeComponent *)v23->m_Components.p[2].m_pComponent;
    if ( v24 )
      UFG::TransformNodeComponent::UpdateWorldTransform(v24);
  }
  v25 = UFG::OSuiteDBLogger::Instance();
  if ( UFG::OSuiteDBLogger::CreateMetric(v25, "OpenWorldPlayerDeath") )
  {
    v26 = UFG::gNullQSymbol.mUID;
    v27 = (unsigned int)v2->mAttackTypeID;
    if ( (signed int)v27 >= 0 )
    {
      if ( (signed int)gAttackCollisionEnum.m_enumLists.size <= 0 )
        v28 = 0i64;
      else
        v28 = *gAttackCollisionEnum.m_enumLists.p;
      v26 = v28->m_enumNameHash.p[v27];
    }
    v29 = v38.mUID;
    v30 = v37.mUID;
    v31 = UFG::qSymbol::as_cstr_dbg(&v38);
    v32 = UFG::qSymbol::as_cstr_dbg(&v37);
    LODWORD(reason_text) = v29;
    UFG::qPrintf(
      "********** Player Died: Cause: 0x%08x Killer:0x%08x(%s) Weapon:0x%08x(%s)",
      v26,
      v30,
      v32,
      reason_text,
      v31);
    UFG::qSPrintf(&dest, 128, "i32_%s", "Cause");
    OSuite::ZMetric::SetProperty(v25->m_pMetric, &dest, v26);
    LODWORD(v31) = v37;
    UFG::qSPrintf(&dest, 128, "i32_%s", "KilledNameEnemy");
    OSuite::ZMetric::SetProperty(v25->m_pMetric, &dest, (int)v31);
    LODWORD(v31) = v38;
    UFG::qSPrintf(&dest, 128, "i32_%s", "KilledNameWeapon");
    OSuite::ZMetric::SetProperty(v25->m_pMetric, &dest, (int)v31);
    UFG::qSPrintf(&dest, 128, "i32_%s", "PlayerWeaponName");
    OSuite::ZMetric::SetProperty(v25->m_pMetric, &dest, v6);
    UFG::OSuiteDBLogger::SubmitMetric(v25, 1);
  }
  UFG::qString::~qString(&reason);
}

// File Line: 1119
// RVA: 0x4B5460
void __fastcall UFG::GameStatAction::Player::RegisterSuccessfulHit(UFG::SimObject *src, UFG::SimObject *target, UFG::HitRecord *hitRec)
{
  UFG::HitRecord *v3; // r13
  UFG::SimObjectCVBase *v4; // rbx
  UFG::SimObjectCharacter *v5; // rsi
  UFG::GameStatTracker *v6; // rbp
  unsigned __int16 v7; // cx
  UFG::CharacterSubjectComponent *v8; // rax
  __m128 v9; // xmm1
  float v10; // xmm0_4
  float v11; // xmm0_4
  UFG::GameSnapshot *v12; // rax
  bool v13; // di
  UFG::SimObjectCharacterPropertiesComponent *v14; // r15
  unsigned __int16 v15; // cx
  UFG::SimObjectCharacterPropertiesComponent *v16; // rax
  UFG::eCharacterTypeEnum v17; // eax
  UFG::OSuiteLeaderboardManager *v18; // rax
  UFG::OSuiteLeaderboardData *v19; // rax
  UFG::OSuiteLeaderboardManager *v20; // rax
  UFG::OSuiteLeaderboardData *v21; // rax
  UFG::OSuiteLeaderboardManager *v22; // rax
  UFG::OSuiteLeaderboardData *v23; // rax
  UFG::OSuiteLeaderboardManager *v24; // rax
  UFG::OSuiteLeaderboardData *v25; // rax
  UFG::SimComponent *v26; // rbx
  unsigned __int16 v27; // cx
  UFG::SimComponent *v28; // rax
  UFG::SimObjectProp *v29; // rcx
  unsigned __int16 v30; // dx
  UFG::SimObjectWeaponPropertiesComponent *v31; // rax
  UFG::OSuiteLeaderboardManager *v32; // rax
  UFG::OSuiteLeaderboardData *v33; // rax
  UFG::OSuiteLeaderboardManager *v34; // rax
  UFG::OSuiteLeaderboardData *v35; // rax
  UFG::GameStatTracker *v36; // rbx
  unsigned __int16 v37; // cx
  UFG::AICoverComponent *v38; // rax
  unsigned int v39; // edx
  UFG::GameStatTracker *v40; // rcx
  bool v41; // r12
  UFG::eFactionClassEnum v42; // eax
  UFG::CopSystem *v43; // rax
  UFG::OSuiteLeaderboardManager *v44; // rax
  UFG::OSuiteLeaderboardData *v45; // rax
  UFG::OSuiteLeaderboardManager *v46; // rax
  UFG::OSuiteLeaderboardData *v47; // rax
  unsigned __int16 v48; // cx
  UFG::SimObjectCharacterPropertiesComponent *v49; // rax
  UFG::eFactionClassEnum v50; // ebx
  UFG::eFactionClassEnum v51; // edi
  UFG::GameStatTracker *v52; // rax
  unsigned __int16 v53; // cx
  UFG::SimComponent *v54; // rbx
  UFG::SimComponent *v55; // rax
  unsigned int v56; // eax
  unsigned int v57; // eax
  UFG::allocator::free_link *v58; // r14
  const char *v59; // rdi
  unsigned int v60; // ebx
  UFG::SimObjectCharacter *v61; // rax
  UFG::allocator::free_link *v62; // rcx
  UFG::OSuiteLeaderboardManager *v63; // rax
  UFG::OSuiteLeaderboardData *v64; // rax
  UFG::OSuiteLeaderboardManager *v65; // rax
  UFG::OSuiteLeaderboardData *v66; // rax
  unsigned __int16 v67; // cx
  UFG::SimObjectVehiclePropertiesComponent *v68; // rax
  UFG::eSimObjectVehicleTypeEnum v69; // ecx
  char v70; // al
  int v71; // ecx
  bool v72; // [rsp+80h] [rbp+18h]

  if ( hitRec )
  {
    v3 = hitRec;
    v4 = (UFG::SimObjectCVBase *)target;
    v5 = (UFG::SimObjectCharacter *)src;
    UFG::GameStatAction::Player::SuccessfulWeaponHit(hitRec, target);
    v6 = UFG::GameStatTracker::Instance();
    if ( v5 )
    {
      v7 = v5->m_Flags;
      if ( (v7 >> 14) & 1 )
      {
        v8 = UFG::SimObjectCharacter::GetComponent<UFG::CharacterSubjectComponent>(v5);
      }
      else if ( (v7 & 0x8000u) == 0 )
      {
        if ( (v7 >> 13) & 1 )
          v8 = (UFG::CharacterSubjectComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                   (UFG::SimObjectGame *)&v5->vfptr,
                                                   UFG::CharacterSubjectComponent::_TypeUID);
        else
          v8 = (UFG::CharacterSubjectComponent *)((v7 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                     (UFG::SimObjectGame *)&v5->vfptr,
                                                                     UFG::CharacterSubjectComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v5->vfptr, UFG::CharacterSubjectComponent::_TypeUID));
      }
      else
      {
        v8 = (UFG::CharacterSubjectComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                 (UFG::SimObjectGame *)&v5->vfptr,
                                                 UFG::CharacterSubjectComponent::_TypeUID);
      }
      if ( v8 )
      {
        v9 = (__m128)LODWORD(v3->mCollisionInfo.mHitLocation.y);
        v10 = v3->mCollisionInfo.mHitLocation.x - v8->mFilteredPosition.x;
        v9.m128_f32[0] = (float)((float)((float)(v9.m128_f32[0] - v8->mFilteredPosition.y)
                                       * (float)(v9.m128_f32[0] - v8->mFilteredPosition.y))
                               + (float)(v10 * v10))
                       + (float)((float)(v3->mCollisionInfo.mHitLocation.z - v8->mFilteredPosition.z)
                               * (float)(v3->mCollisionInfo.mHitLocation.z - v8->mFilteredPosition.z));
        LODWORD(v11) = (unsigned __int128)_mm_sqrt_ps(v9);
        if ( !(*((_BYTE *)v6 + 6216) & 1) )
        {
          v12 = v6->mpSnapshots[0];
          if ( v11 > v12->mFloats[102].mValue )
            v12->mFloats[102].mValue = v11;
        }
      }
    }
    if ( v3->mIsDeadly )
    {
      if ( !UFG::GameStatAction::gIgnoreMissionKillsInWTHK )
        UFG::GameStatAction::Player::CountKills((UFG::SimObject *)&v4->vfptr);
      v13 = UFG::GameStatAction::Player::IsInVehicle((UFG::SimObject *)&v5->vfptr);
      v72 = v13;
      if ( v4 )
      {
        v15 = v4->m_Flags;
        if ( (v15 >> 14) & 1 )
        {
          v16 = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectCharacterPropertiesComponent>(v4);
        }
        else if ( (v15 & 0x8000u) == 0 )
        {
          if ( (v15 >> 13) & 1 )
          {
            v16 = (UFG::SimObjectCharacterPropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                  (UFG::SimObjectGame *)&v4->vfptr,
                                                                  UFG::SimObjectCharacterPropertiesComponent::_TypeUID);
          }
          else if ( (v15 >> 12) & 1 )
          {
            v16 = (UFG::SimObjectCharacterPropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                  (UFG::SimObjectGame *)&v4->vfptr,
                                                                  UFG::SimObjectCharacterPropertiesComponent::_TypeUID);
          }
          else
          {
            v16 = (UFG::SimObjectCharacterPropertiesComponent *)UFG::SimObject::GetComponentOfType(
                                                                  (UFG::SimObject *)&v4->vfptr,
                                                                  UFG::SimObjectCharacterPropertiesComponent::_TypeUID);
          }
        }
        else
        {
          v16 = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectCharacterPropertiesComponent>(v4);
        }
        v14 = v16;
        if ( v16 )
        {
          v17 = v16->m_eCharacterType;
          if ( v17 == 3 && *((_BYTE *)v14 + 248) & 1 )
          {
            v18 = UFG::OSuiteLeaderboardManager::Instance();
            v19 = UFG::OSuiteLeaderboardManager::GetLeaderboardDataUsingLeaderboardName(
                    v18,
                    "StatGamesPossessedPedsKilled");
            UFG::StatGameManager::UpdateScore(v19, 1, 1);
          }
          else
          {
            if ( !v13 && v17 == 41 )
            {
              v20 = UFG::OSuiteLeaderboardManager::Instance();
              v21 = UFG::OSuiteLeaderboardManager::GetLeaderboardDataUsingLeaderboardName(
                      v20,
                      "StatGamesJiangShiDefeatedStreak");
              UFG::StatGameManager::UpdateScore(v21, 1, 1);
              v22 = UFG::OSuiteLeaderboardManager::Instance();
              v23 = UFG::OSuiteLeaderboardManager::GetLeaderboardDataUsingLeaderboardName(
                      v22,
                      "StatAwardsJiangShiDefeated");
              UFG::DataSynchronizer::ApplyDeltaToGlobalSnapshot(v23, 1);
              goto LABEL_66;
            }
            if ( v17 == 40 )
            {
              v24 = UFG::OSuiteLeaderboardManager::Instance();
              v25 = UFG::OSuiteLeaderboardManager::GetLeaderboardDataUsingLeaderboardName(
                      v24,
                      "StatAwardsYaoguaiDefeated");
              UFG::DataSynchronizer::ApplyDeltaToGlobalSnapshot(v25, 1);
              if ( v5 )
              {
                v27 = v5->m_Flags;
                if ( (v27 >> 14) & 1 )
                {
                  v26 = v5->m_Components.p[20].m_pComponent;
                }
                else if ( (v27 & 0x8000u) == 0 )
                {
                  if ( (v27 >> 13) & 1 )
                    v28 = UFG::SimObjectGame::GetComponentOfTypeHK(
                            (UFG::SimObjectGame *)&v5->vfptr,
                            UFG::TargetingSystemBaseComponent::_TypeUID);
                  else
                    v28 = (v27 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                              (UFG::SimObjectGame *)&v5->vfptr,
                                              UFG::TargetingSystemBaseComponent::_TypeUID) : UFG::SimObject::GetComponentOfType(
                                                                                               (UFG::SimObject *)&v5->vfptr,
                                                                                               UFG::TargetingSystemBaseComponent::_TypeUID);
                  v26 = v28;
                }
                else
                {
                  v26 = v5->m_Components.p[20].m_pComponent;
                }
              }
              else
              {
                v26 = 0i64;
              }
              if ( !UFG::GameStatAction::Player::IsInVehicle((UFG::SimObject *)&v5->vfptr) )
              {
                if ( v26 )
                {
                  v29 = *(UFG::SimObjectProp **)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&v26[1].m_Flags + 25i64)
                                               + *(_QWORD *)&v26[1].m_TypeUID
                                               + 40);
                  if ( v29 )
                  {
                    v30 = v29->m_Flags;
                    if ( (v30 >> 14) & 1 )
                    {
                      v31 = (UFG::SimObjectWeaponPropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                         (UFG::SimObjectGame *)&v29->vfptr,
                                                                         UFG::SimObjectWeaponPropertiesComponent::_TypeUID);
                    }
                    else if ( (v30 & 0x8000u) == 0 )
                    {
                      if ( (v30 >> 13) & 1 )
                        v31 = UFG::SimObjectProp::GetComponent<UFG::SimObjectWeaponPropertiesComponent>(v29);
                      else
                        v31 = (UFG::SimObjectWeaponPropertiesComponent *)((v30 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                                              (UFG::SimObjectGame *)&v29->vfptr,
                                                                                              UFG::SimObjectWeaponPropertiesComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v29->vfptr, UFG::SimObjectWeaponPropertiesComponent::_TypeUID));
                    }
                    else
                    {
                      v31 = (UFG::SimObjectWeaponPropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                         (UFG::SimObjectGame *)&v29->vfptr,
                                                                         UFG::SimObjectWeaponPropertiesComponent::_TypeUID);
                    }
                    if ( v31
                      && v31->mWeaponTypeInfo->mFireModes[v31->mFireMode]->mSimObjectWeaponType == UFG::gSimObjectWeaponTypeTrackEnum_eSIM_OBJ_WEAPON_TYPE_STRAIGHT_SWORD.m_EnumValue )
                    {
                      v32 = UFG::OSuiteLeaderboardManager::Instance();
                      v33 = UFG::OSuiteLeaderboardManager::GetLeaderboardDataUsingLeaderboardName(
                              v32,
                              "StatAwardsYaoguaiPeachwooded");
                      UFG::DataSynchronizer::ApplyDeltaToGlobalSnapshot(v33, 1);
                    }
                  }
                }
              }
            }
          }
        }
      }
      else
      {
        v14 = 0i64;
      }
      if ( v13 )
      {
LABEL_67:
        v36 = &sGameStatTracker;
        if ( v5
          && ((v37 = v5->m_Flags, !((v37 >> 14) & 1)) ? ((v37 & 0x8000u) == 0 ? (!((v37 >> 13) & 1) ? (!((v37 >> 12) & 1) ? (v38 = (UFG::AICoverComponent *)UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v5->vfptr, UFG::AICoverComponent::_TypeUID)) : (v38 = (UFG::AICoverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&v5->vfptr, UFG::AICoverComponent::_TypeUID))) : (v38 = (UFG::AICoverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&v5->vfptr, UFG::AICoverComponent::_TypeUID))) : (v38 = (UFG::AICoverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&v5->vfptr, UFG::AICoverComponent::_TypeUID))) : (v38 = (UFG::AICoverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&v5->vfptr, UFG::AICoverComponent::_TypeUID)),
              v38
           && UFG::AICoverComponent::IsInCover(v38)
           && !(*((_BYTE *)v6 + 6216) & 1)
           && (++v6->mpSnapshots[0]->mInts[94].mValue, UFG::GameStatAction::PostStat::sIsEnabled)) )
        {
          v39 = _S12_6;
          if ( !(_S12_6 & 1) )
          {
            _S12_6 |= 1u;
            UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
            atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
            v39 = _S12_6;
          }
          v40 = &sGameStatTracker;
          if ( UFG::GameStatTracker::mspInstance )
            v40 = UFG::GameStatTracker::mspInstance;
          UFG::GameStatTracker::mspInstance = v40;
        }
        else
        {
          v39 = _S12_6;
        }
        v41 = 0;
        if ( v14 )
        {
          v42 = v14->m_eFactionClass;
          if ( v42 == 17 )
          {
            v41 = 1;
            if ( !(*((_BYTE *)v6 + 6216) & 1) )
            {
              ++v6->mpSnapshots[0]->mInts[8].mValue;
              if ( UFG::GameStatAction::PostStat::sIsEnabled )
              {
                if ( !(v39 & 1) )
                {
                  _S12_6 = v39 | 1;
                  UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
                  atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
                }
                if ( UFG::GameStatTracker::mspInstance )
                  v36 = UFG::GameStatTracker::mspInstance;
                UFG::GameStatTracker::mspInstance = v36;
              }
            }
            UFG::OnlineEventManager::PostEvent((UFG::OnlineEventManager::Event)6u, 1);
            if ( !(*((_BYTE *)v6 + 6216) & 1) )
            {
              ++v6->mpSnapshots[0]->mInts[151].mValue;
              if ( UFG::GameStatAction::PostStat::sIsEnabled )
                UFG::GameStatAction::PostStat::AchieveInt(DebugValueC);
              if ( !(*((_BYTE *)v6 + 6216) & 1) )
              {
                ++v6->mpSnapshots[0]->mInts[0].mValue;
                if ( UFG::GameStatAction::PostStat::sIsEnabled )
                  UFG::GameStatAction::PostStat::AchieveInt(0);
                if ( !(*((_BYTE *)v6 + 6216) & 1) )
                {
                  ++v6->mpSnapshots[0]->mInts[157].mValue;
                  if ( UFG::GameStatAction::PostStat::sIsEnabled )
                    UFG::GameStatAction::PostStat::AchieveInt(DebugValueFC);
                  if ( !(*((_BYTE *)v6 + 6216) & 1) )
                  {
                    ++v6->mpSnapshots[0]->mInts[122].mValue;
                    if ( UFG::GameStatAction::PostStat::sIsEnabled )
                      UFG::GameStatAction::PostStat::AchieveInt(DebugValueO);
                  }
                }
              }
            }
            UFG::GameStatAction::MissionScoring::LogCopEvent(COP_PEDESTRIAN_KILL, 0, &customWorldMapCaption);
          }
          else if ( v42 == 3 )
          {
            UFG::GameStatAction::MissionScoring::LogCopEvent(0, 0, &customWorldMapCaption);
            v43 = UFG::CopSystem::Instance();
            if ( ((signed int (__fastcall *)(UFG::CopSystem *))v43->vfptr[89].__vecDelDtor)(v43) >= 2 )
            {
              v44 = UFG::OSuiteLeaderboardManager::Instance();
              v45 = UFG::OSuiteLeaderboardManager::GetLeaderboardDataUsingLeaderboardName(v44, "StatGamesCopsKilled");
              UFG::StatGameManager::UpdateScore(v45, 1, 1);
              v46 = UFG::OSuiteLeaderboardManager::Instance();
              v47 = UFG::OSuiteLeaderboardManager::GetLeaderboardDataUsingLeaderboardName(v46, "StatAwardsCopKiller");
              UFG::DataSynchronizer::ApplyDeltaToGlobalSnapshot(v47, 1);
            }
          }
          else
          {
            if ( !v5 )
            {
LABEL_148:
              if ( v72 )
              {
                UFG::GameStatTracker::ApplyDelta(v6, VehicleKills, 1);
                UFG::GameStatTracker::ApplyDelta(v6, CurrentVehicleKills, 1);
                v63 = UFG::OSuiteLeaderboardManager::Instance();
                v64 = UFG::OSuiteLeaderboardManager::GetLeaderboardDataUsingLeaderboardName(
                        v63,
                        "StatGamesLongestHitAndRun");
                UFG::StatGameManager::UpdateScore(v64, 1, 1);
                if ( v14 && v14->m_eCharacterType == 41 )
                {
                  v65 = UFG::OSuiteLeaderboardManager::Instance();
                  v66 = UFG::OSuiteLeaderboardManager::GetLeaderboardDataUsingLeaderboardName(
                          v65,
                          "StatGamesJiangShiRunOver");
                  UFG::StatGameManager::UpdateScore(v66, 1, 1);
                }
                if ( v5 )
                {
                  v67 = v5->m_Flags;
                  if ( (v67 >> 14) & 1 )
                  {
                    v68 = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectVehiclePropertiesComponent>((UFG::SimObjectCVBase *)&v5->vfptr);
                  }
                  else if ( (v67 & 0x8000u) == 0 )
                  {
                    if ( (v67 >> 13) & 1 )
                    {
                      v68 = (UFG::SimObjectVehiclePropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                          (UFG::SimObjectGame *)&v5->vfptr,
                                                                          UFG::SimObjectVehiclePropertiesComponent::_TypeUID);
                    }
                    else if ( (v67 >> 12) & 1 )
                    {
                      v68 = (UFG::SimObjectVehiclePropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                          (UFG::SimObjectGame *)&v5->vfptr,
                                                                          UFG::SimObjectVehiclePropertiesComponent::_TypeUID);
                    }
                    else
                    {
                      v68 = (UFG::SimObjectVehiclePropertiesComponent *)UFG::SimObject::GetComponentOfType(
                                                                          (UFG::SimObject *)&v5->vfptr,
                                                                          UFG::SimObjectVehiclePropertiesComponent::_TypeUID);
                    }
                  }
                  else
                  {
                    v68 = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectVehiclePropertiesComponent>((UFG::SimObjectCVBase *)&v5->vfptr);
                  }
                  if ( v68 )
                  {
                    v69 = v68->m_eSimObjectVehicleType;
                    switch ( v69 )
                    {
                      case 1:
                        UFG::GameStatTracker::ApplyDelta(v6, BikeKills, 1);
                        break;
                      case 3:
                        UFG::GameStatTracker::ApplyDelta(v6, BoatKills, 1);
                        break;
                      case 2:
                        UFG::GameStatTracker::ApplyDelta(v6, CarKills, 1);
                        break;
                    }
                  }
                }
              }
              else if ( !UFG::GameStatAction::gIgnoreMissionKillsInWTHK )
              {
                v70 = UFG::GameStatAction::Player::SuccessfulWeaponKill(v3, v41);
                v71 = v3->mAttackTypeID;
                if ( v71 != gAttackCollisionExplosionNoDamage.m_EnumValue
                  && v71 != gAttackCollisionExplosion.m_EnumValue
                  && !v70 )
                {
                  UFG::GameStatAction::Player::CountHandCombatKills();
                }
              }
              return;
            }
            v48 = v5->m_Flags;
            if ( (v48 >> 14) & 1 )
            {
              v49 = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectCharacterPropertiesComponent>((UFG::SimObjectCVBase *)&v5->vfptr);
            }
            else if ( (v48 & 0x8000u) == 0 )
            {
              if ( (v48 >> 13) & 1 )
              {
                v49 = (UFG::SimObjectCharacterPropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                      (UFG::SimObjectGame *)&v5->vfptr,
                                                                      UFG::SimObjectCharacterPropertiesComponent::_TypeUID);
              }
              else if ( (v48 >> 12) & 1 )
              {
                v49 = (UFG::SimObjectCharacterPropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                      (UFG::SimObjectGame *)&v5->vfptr,
                                                                      UFG::SimObjectCharacterPropertiesComponent::_TypeUID);
              }
              else
              {
                v49 = (UFG::SimObjectCharacterPropertiesComponent *)UFG::SimObject::GetComponentOfType(
                                                                      (UFG::SimObject *)&v5->vfptr,
                                                                      UFG::SimObjectCharacterPropertiesComponent::_TypeUID);
              }
            }
            else
            {
              v49 = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectCharacterPropertiesComponent>((UFG::SimObjectCVBase *)&v5->vfptr);
            }
            if ( v49 )
            {
              v50 = v14->m_eFactionClass;
              v51 = v49->m_eFactionClass;
              v52 = UFG::FactionInterface::Get();
              if ( (unsigned int)UFG::FactionInterface::GetStanding(&v52->mFactionInterface, v51, v50) == 2 )
              {
                UFG::GameStatTracker::ApplyDelta(v6, EnemiesKilled, 1);
                UFG::OnlineEventManager::PostEvent((UFG::OnlineEventManager::Event)5u, 1);
                UFG::GameStatAction::MissionScoring::LogTriadEvent(TRIAD_KILL_HOSTILE, 0, &customWorldMapCaption);
              }
            }
          }
        }
        if ( v5 )
        {
          v53 = v5->m_Flags;
          if ( (v53 >> 14) & 1 )
          {
            v54 = v5->m_Components.p[7].m_pComponent;
          }
          else if ( (v53 & 0x8000u) == 0 )
          {
            if ( (v53 >> 13) & 1 )
            {
              v54 = v5->m_Components.p[6].m_pComponent;
            }
            else
            {
              v55 = (v53 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                        (UFG::SimObjectGame *)&v5->vfptr,
                                        UFG::ActionTreeComponent::_TypeUID) : UFG::SimObject::GetComponentOfType(
                                                                                (UFG::SimObject *)&v5->vfptr,
                                                                                UFG::ActionTreeComponent::_TypeUID);
              v54 = v55;
            }
          }
          else
          {
            v54 = v5->m_Components.p[7].m_pComponent;
          }
          if ( v54 && !v41 )
          {
            v56 = _S10_8;
            if ( !(_S10_8 & 1) )
            {
              _S10_8 |= 1u;
              TimeWarpVaultShootUID.mUID = UFG::qStringHashUpper32("VaultShoot", 0xFFFFFFFF);
              v56 = _S10_8;
            }
            if ( v56 & 2 )
            {
              v57 = mostUsedIndex_TimeWarpVaultShootUID;
            }
            else
            {
              _S10_8 = v56 | 2;
              v57 = GetMostUsedIndex(TimeWarpVaultShootUID.mUID);
              mostUsedIndex_TimeWarpVaultShootUID = v57;
            }
            if ( ActionController::IsPlaying((ActionController *)&v54[3], &TimeWarpVaultShootUID, v57, 1) )
            {
              v58 = UFG::qMalloc(0x48ui64, "GameStatEventTask", 0i64);
              if ( v58 )
              {
                v59 = UFG::gGameStatEventChannel.mName;
                v60 = UFG::gGameStatEventChannel.mUID;
                v61 = UFG::GetLocalPlayer();
                v62 = v58 + 1;
                v62->mNext = v62;
                v62[1].mNext = v62;
                v58->mNext = (UFG::allocator::free_link *)&UFG::Event::`vftable;
                LODWORD(v58[3].mNext) = v60;
                v58[4].mNext = (UFG::allocator::free_link *)v59;
                v58->mNext = (UFG::allocator::free_link *)&UFG::GameStatEvent::`vftable;
                LODWORD(v58[7].mNext) = 88;
                v58[8].mNext = (UFG::allocator::free_link *)v61;
              }
              else
              {
                v58 = 0i64;
              }
              UFG::EventDispatcher::DispatchEvent(&UFG::EventDispatcher::mInstance, (UFG::Event *)v58);
            }
          }
        }
        goto LABEL_148;
      }
LABEL_66:
      v34 = UFG::OSuiteLeaderboardManager::Instance();
      v35 = UFG::OSuiteLeaderboardManager::GetLeaderboardDataUsingLeaderboardName(v34, "StatGamesKillStreak");
      UFG::StatGameManager::UpdateScore(v35, 1, 1);
      goto LABEL_67;
    }
  }
}

// File Line: 1334
// RVA: 0x499D50
void __fastcall UFG::GameStatAction::Player::CountKills(UFG::SimObject *target)
{
  UFG::SimObject *v1; // rbx
  UFG::OSuiteLeaderboardManager *v2; // rax
  UFG::OSuiteLeaderboardData *v3; // rax
  UFG::OSuiteLeaderboardManager *v4; // rax
  UFG::OSuiteLeaderboardData *v5; // rax
  bool pIsCop; // [rsp+38h] [rbp+10h]
  bool pIsAmbient; // [rsp+40h] [rbp+18h]

  ++sKillsPerSession;
  v1 = target;
  v2 = UFG::OSuiteLeaderboardManager::Instance();
  v3 = UFG::OSuiteLeaderboardManager::GetLeaderboardDataUsingLeaderboardName(v2, "StatAwardsPublicEnemy");
  UFG::DataSynchronizer::SetMaxToGlobalSnapshot(v3, sKillsPerSession);
  pIsCop = 0;
  pIsAmbient = 0;
  UFG::GameStatAction::MissionScoring::DeduceFaction(v1, &pIsCop, &pIsAmbient);
  if ( !pIsCop && !pIsAmbient )
  {
    v4 = UFG::OSuiteLeaderboardManager::Instance();
    v5 = UFG::OSuiteLeaderboardManager::GetLeaderboardDataUsingLeaderboardName(v4, "StatAwardsEnforcer");
    UFG::DataSynchronizer::ApplyDeltaToGlobalSnapshot(v5, 1);
  }
}

// File Line: 1348
// RVA: 0x499C70
void UFG::GameStatAction::Player::CountHandCombatKills(void)
{
  unsigned int v0; // ecx
  UFG::GameStatTracker *v1; // rbx
  UFG::GameStatTracker *v2; // rdx
  UFG::OSuiteLeaderboardManager *v3; // rax
  UFG::OSuiteLeaderboardData *v4; // rax

  v0 = _S12_6;
  v1 = &sGameStatTracker;
  if ( !(_S12_6 & 1) )
  {
    _S12_6 |= 1u;
    UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
    atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
    v0 = _S12_6;
  }
  v2 = &sGameStatTracker;
  if ( UFG::GameStatTracker::mspInstance )
    v2 = UFG::GameStatTracker::mspInstance;
  UFG::GameStatTracker::mspInstance = v2;
  if ( !(*((_BYTE *)v2 + 6216) & 1) )
  {
    ++v2->mpSnapshots[0]->mInts[158].mValue;
    if ( UFG::GameStatAction::PostStat::sIsEnabled )
    {
      if ( !(v0 & 1) )
      {
        _S12_6 = v0 | 1;
        UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
        atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
      }
      if ( UFG::GameStatTracker::mspInstance )
        v1 = UFG::GameStatTracker::mspInstance;
      UFG::GameStatTracker::mspInstance = v1;
    }
  }
  v3 = UFG::OSuiteLeaderboardManager::Instance();
  v4 = UFG::OSuiteLeaderboardManager::GetLeaderboardDataUsingLeaderboardName(v3, "StatAwardsMartialArtist");
  UFG::DataSynchronizer::ApplyDeltaToGlobalSnapshot(v4, 1);
}

// File Line: 1356
// RVA: 0x4AC970
bool __fastcall UFG::GameStatAction::Player::IsInVehicle(UFG::SimObject *src)
{
  UFG::SimObjectGame *v1; // rbx
  UFG::SimObjectCharacter *v2; // rdi
  unsigned __int16 v3; // cx
  UFG::VehicleDriverInterface *v4; // rax
  bool result; // al

  v1 = (UFG::SimObjectGame *)src;
  v2 = UFG::GetLocalPlayer();
  result = 0;
  if ( v1 )
  {
    v3 = v1->m_Flags;
    if ( (v3 >> 14) & 1 )
    {
      v4 = (UFG::VehicleDriverInterface *)v1->m_Components.p[23].m_pComponent;
    }
    else if ( (v3 & 0x8000u) == 0 )
    {
      if ( (v3 >> 13) & 1 )
        v4 = (UFG::VehicleDriverInterface *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                              v1,
                                              UFG::VehicleDriverInterface::_TypeUID);
      else
        v4 = (UFG::VehicleDriverInterface *)((v3 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                v1,
                                                                UFG::VehicleDriverInterface::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v1->vfptr, UFG::VehicleDriverInterface::_TypeUID));
    }
    else
    {
      v4 = (UFG::VehicleDriverInterface *)v1->m_Components.p[23].m_pComponent;
    }
    if ( v4 && (UFG::SimObjectCharacter *)v4->mDriver.m_pPointer == v2 )
      result = 1;
  }
  return result;
}

// File Line: 1372
// RVA: 0x4C90A0
bool __fastcall UFG::GameStatAction::WeaponIsDLC(UFG::SimObjectWeaponPropertiesComponent *WPC)
{
  unsigned int v1; // ebx
  UFG::qSymbol v3; // [rsp+20h] [rbp-18h]
  UFG::qSymbol result; // [rsp+48h] [rbp+10h]
  UFG::qSymbol v5; // [rsp+50h] [rbp+18h]
  UFG::qSymbol v6; // [rsp+58h] [rbp+20h]

  UFG::SimObjectWeaponPropertiesComponent::GetWeaponID(WPC, &result);
  UFG::qSymbol::create_from_string(&v5, "object-physical-weapon-firearm-rifle-assault_dlc");
  v1 = result.mUID;
  if ( result.mUID == v5.mUID )
    return 1;
  UFG::qSymbol::create_from_string(&v6, "object-physical-weapon-firearm-smg-45cal_gold");
  if ( v1 == v6.mUID )
    return 1;
  UFG::qSymbol::create_from_string(&v3, "object-physical-weapon-melee-cleaver_Gold");
  return v1 == v3.mUID;
}

// File Line: 1387
// RVA: 0x4C1F60
char __fastcall UFG::GameStatAction::Player::SuccessfulWeaponKill(UFG::HitRecord *hitRec, bool killedInnocent)
{
  bool v2; // r14
  UFG::HitRecord *v3; // rsi
  UFG::GameStatTracker *v4; // rdi
  UFG::GameStatTracker *v5; // rbx
  UFG::SimObjectWeaponPropertiesComponent *v6; // rax
  UFG::SimObjectWeaponPropertiesComponent *v7; // rbp
  UFG::GameStatTracker *v8; // rcx
  UFG::qSymbol *v9; // rax
  UFG::GameStatTracker *v10; // rcx
  UFG::OSuiteLeaderboardManager *v11; // rax
  UFG::OSuiteLeaderboardData *v12; // rax
  unsigned int v13; // edx
  UFG::GameStatTracker *v14; // rcx
  int v15; // eax
  UFG::GameStat::Int32Stat v17; // edx
  UFG::qSymbol *v18; // rax
  UFG::OSuiteLeaderboardManager *v19; // rax
  UFG::OSuiteLeaderboardData *v20; // rax
  UFG::SimObject *v21; // rcx
  UFG::SimObjectCharacter *v22; // rax
  UFG::SimObjectWeaponPropertiesComponent *v23; // rax
  UFG::qSymbol result; // [rsp+50h] [rbp+8h]

  v2 = killedInnocent;
  v3 = hitRec;
  v4 = &sGameStatTracker;
  if ( !(_S12_6 & 1) )
  {
    _S12_6 |= 1u;
    UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
    atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
  }
  v5 = &sGameStatTracker;
  if ( UFG::GameStatTracker::mspInstance )
    v5 = UFG::GameStatTracker::mspInstance;
  UFG::GameStatTracker::mspInstance = v5;
  v6 = UFG::GameStatAction::Weapon::GetHoldingWeapon(v3->mAttacker.m_pPointer);
  v7 = v6;
  if ( v6 )
  {
    if ( UFG::GameStatAction::WeaponIsDLC(v6) && !(*((_BYTE *)v5 + 6216) & 1) )
    {
      ++v5->mpSnapshots[0]->mInts[161].mValue;
      if ( UFG::GameStatAction::PostStat::sIsEnabled )
      {
        if ( !(_S12_6 & 1) )
        {
          _S12_6 |= 1u;
          UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
          atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
        }
        v8 = &sGameStatTracker;
        if ( UFG::GameStatTracker::mspInstance )
          v8 = UFG::GameStatTracker::mspInstance;
        UFG::GameStatTracker::mspInstance = v8;
      }
    }
    if ( v3->mProjectileInfo.m_pSOWPC.m_pPointer )
    {
      v9 = UFG::SimObjectWeaponPropertiesComponent::GetWeaponID(v7, &result);
      if ( !(*((_BYTE *)v5 + 6216) & 1) )
      {
        UFG::PersistentData::MapInt::ApplyDelta(v5->mpSnapshots[0]->mpMapInts[28], v9, 1);
        if ( UFG::GameStatAction::PostStat::sIsEnabled )
        {
          if ( !(_S12_6 & 1) )
          {
            _S12_6 |= 1u;
            UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
            atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
          }
          v10 = &sGameStatTracker;
          if ( UFG::GameStatTracker::mspInstance )
            v10 = UFG::GameStatTracker::mspInstance;
          UFG::GameStatTracker::mspInstance = v10;
          if ( (signed int)v10->mpSnapshots[0]->mpMapInts[28]->mValues.size >= 10 )
            UFG::AchievementTrophyManager::UnlockAchievementTrophy(17);
        }
      }
      v11 = UFG::OSuiteLeaderboardManager::Instance();
      v12 = UFG::OSuiteLeaderboardManager::GetLeaderboardDataUsingLeaderboardName(v11, "StatAwardsGunman");
      UFG::DataSynchronizer::ApplyDeltaToGlobalSnapshot(v12, 1);
      if ( *((_BYTE *)v5 + 6216) & 1
        || (++v5->mpSnapshots[0]->mInts[159].mValue, !UFG::GameStatAction::PostStat::sIsEnabled) )
      {
        v13 = _S12_6;
      }
      else
      {
        v13 = _S12_6;
        if ( !(_S12_6 & 1) )
        {
          _S12_6 |= 1u;
          UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
          atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
          v13 = _S12_6;
        }
        v14 = &sGameStatTracker;
        if ( UFG::GameStatTracker::mspInstance )
          v14 = UFG::GameStatTracker::mspInstance;
        UFG::GameStatTracker::mspInstance = v14;
      }
      v15 = **((_DWORD **)&v3->mProjectileInfo.m_pSOWPC.m_pPointer[2].m_BoundComponentHandles.mNode.mPrev->mNext
             + HIDWORD(v3->mProjectileInfo.m_pSOWPC.m_pPointer[2].m_pSimObject));
      if ( v15 == UFG::gSimObjectWeaponTypeTrackEnum_eSIM_OBJ_WEAPON_TYPE_PISTOL.m_EnumValue )
      {
        if ( !(*((_BYTE *)v5 + 6216) & 1) )
        {
          ++v5->mpSnapshots[0]->mInts[104].mValue;
          if ( UFG::GameStatAction::PostStat::sIsEnabled )
          {
            if ( !(v13 & 1) )
            {
              _S12_6 = v13 | 1;
              UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
              atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
            }
            if ( UFG::GameStatTracker::mspInstance )
              v4 = UFG::GameStatTracker::mspInstance;
            UFG::GameStatTracker::mspInstance = v4;
          }
        }
        return 1;
      }
      if ( v15 == UFG::gSimObjectWeaponTypeTrackEnum_eSIM_OBJ_WEAPON_TYPE_RIFLE.m_EnumValue )
      {
        v17 = 113;
LABEL_42:
        UFG::GameStatTracker::ApplyDelta(v5, v17, 1);
        return 1;
      }
      if ( v15 == UFG::gSimObjectWeaponTypeTrackEnum_eSIM_OBJ_WEAPON_TYPE_SHOTGUN.m_EnumValue )
      {
        v17 = 116;
        goto LABEL_42;
      }
      if ( v15 != UFG::gSimObjectWeaponTypeTrackEnum_eSIM_OBJ_WEAPON_TYPE_SMG.m_EnumValue )
      {
        if ( v15 != UFG::gSimObjectWeaponTypeTrackEnum_eSIM_OBJ_WEAPON_TYPE_SNIPER.m_EnumValue )
          return 1;
        v17 = 110;
        goto LABEL_42;
      }
      UFG::GameStatTracker::ApplyDelta(v5, MachineGunKills, 1);
    }
    else if ( v3->mMeleeInfo.mAttackMaterialUID == gAttackMaterialWeaponEquipped.m_EnumSymbol.mUID )
    {
      UFG::GameStatTracker::ApplyDelta(v5, MissionMeleeWeaponKills, 1);
      if ( sSym_CombatFish.mUID == UFG::SimObjectWeaponPropertiesComponent::GetWeaponID(v7, &result)->mUID )
        UFG::AchievementTrophyManager::UnlockAchievementTrophy(10);
      v18 = UFG::SimObjectWeaponPropertiesComponent::GetWeaponID(v7, &result);
      UFG::GameStatTracker::ApplyDelta(v5, MeleeWeaponKills, v18, 1);
      v19 = UFG::OSuiteLeaderboardManager::Instance();
      v20 = UFG::OSuiteLeaderboardManager::GetLeaderboardDataUsingLeaderboardName(v19, "StatAwardsHandyman");
      UFG::DataSynchronizer::ApplyDeltaToGlobalSnapshot(v20, 1);
      if ( !v2 )
        UFG::GameStatAction::MissionScoring::LogTriadEvent(TRIAD_MELEE_WEAPON_STRIKE, 0, &customWorldMapCaption);
      return 1;
    }
  }
  v21 = v3->mAttacker.m_pPointer;
  if ( v21
    && v21->m_pSceneObj
    && UFG::SceneObjectProperties::GetArchetypeProperties(v21->m_pSceneObj)
    && UFG::SceneObjectProperties::GetArchetypePropertiesName(v3->mAttacker.m_pPointer->m_pSceneObj)->mUID == sSym_CombatFish.mUID )
  {
    UFG::AchievementTrophyManager::UnlockAchievementTrophy(10);
  }
  if ( !(_S11_6 & 1) )
  {
    _S11_6 |= 1u;
    meleeAttack.mPath.mCount = 0;
    meleeAttack.mPath.mData.mOffset = 0i64;
    ActionPath::Append(
      &meleeAttack,
      "\\Global\\Player\\Attacks\\Grapples\\Grapple\\GrappleMoves\\Weapons\\HeavyDamage\\Baton\\GrapRCV");
    atexit(UFG::GameStatAction::Player::SuccessfulWeaponKill_::_47_::_dynamic_atexit_destructor_for__meleeAttack__);
  }
  if ( ActionPath::operator==(&v3->mMeleeInfo.mActionPath, &meleeAttack) )
  {
    v22 = UFG::GetLocalPlayer();
    v23 = UFG::GameStatAction::Weapon::GetHoldingWeapon((UFG::SimObject *)&v22->vfptr);
    if ( sSym_CombatFish.mUID == UFG::SimObjectWeaponPropertiesComponent::GetWeaponID(v23, &result)->mUID )
      UFG::AchievementTrophyManager::UnlockAchievementTrophy(10);
  }
  return 0;
}

// File Line: 1500
// RVA: 0x4C1A70
void __fastcall UFG::GameStatAction::Player::SuccessfulWeaponHit(UFG::HitRecord *hitRec, UFG::SimObject *target)
{
  UFG::SimObjectGame *v2; // rsi
  UFG::HitRecord *v3; // rbx
  UFG::GameStatTracker *v4; // rdi
  UFG::qSymbol *v5; // rax
  unsigned int v6; // edx
  UFG::GameStatTracker *v7; // rcx
  int v8; // eax
  UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject> *v9; // rcx
  const char *v10; // rax
  signed int v11; // ebx
  unsigned __int16 v12; // cx
  UFG::SimComponent *v13; // rax
  UFG::OSuiteLeaderboardManager *v14; // rax
  UFG::OSuiteLeaderboardData *v15; // rax
  UFG::OSuiteLeaderboardManager *v16; // rax
  UFG::OSuiteLeaderboardData *v17; // rax
  UFG::SimObjectCharacter *v18; // rax
  UFG::GameStatAction::MissionScoring::CopScoreEvent v19; // ecx
  UFG::qSymbol *v20; // rax
  UFG::PersistentData::MapBool *v21; // rax
  __int64 v22; // rcx
  $CCFB32CF948EEB04FF452B3FEB4ECF53 *v23; // rax
  UFG::OSuiteLeaderboardManager *v24; // rax
  UFG::OSuiteLeaderboardData *v25; // rax
  UFG::qReflectHandleBase v26; // [rsp+28h] [rbp-50h]
  UFG::qSymbol result; // [rsp+80h] [rbp+8h]
  bool pIsAmbient; // [rsp+90h] [rbp+18h]

  v2 = (UFG::SimObjectGame *)target;
  v3 = hitRec;
  if ( !hitRec->mProjectileInfo.m_pSOWPC.m_pPointer )
    return;
  v4 = UFG::GameStatTracker::Instance();
  v5 = UFG::SimObjectWeaponPropertiesComponent::GetWeaponID(
         (UFG::SimObjectWeaponPropertiesComponent *)v3->mProjectileInfo.m_pSOWPC.m_pPointer,
         &result);
  if ( *((_BYTE *)v4 + 6216) & 1
    || (UFG::PersistentData::MapInt::ApplyDelta(v4->mpSnapshots[0]->mpMapInts[27], v5, 1),
        !UFG::GameStatAction::PostStat::sIsEnabled) )
  {
    v6 = _S12_6;
  }
  else
  {
    v6 = _S12_6;
    if ( !(_S12_6 & 1) )
    {
      _S12_6 |= 1u;
      UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
      atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
      v6 = _S12_6;
    }
    v7 = &sGameStatTracker;
    if ( UFG::GameStatTracker::mspInstance )
      v7 = UFG::GameStatTracker::mspInstance;
    UFG::GameStatTracker::mspInstance = v7;
  }
  v8 = **((_DWORD **)&v3->mProjectileInfo.m_pSOWPC.m_pPointer[2].m_BoundComponentHandles.mNode.mPrev->mNext
        + HIDWORD(v3->mProjectileInfo.m_pSOWPC.m_pPointer[2].m_pSimObject));
  if ( v8 == UFG::gSimObjectWeaponTypeTrackEnum_eSIM_OBJ_WEAPON_TYPE_PISTOL.m_EnumValue )
  {
    if ( !(*((_BYTE *)v4 + 6216) & 1) )
    {
      ++v4->mpSnapshots[0]->mInts[103].mValue;
      if ( UFG::GameStatAction::PostStat::sIsEnabled )
      {
        if ( !(v6 & 1) )
        {
          _S12_6 = v6 | 1;
          UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
          atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
        }
LABEL_25:
        if ( !UFG::GameStatTracker::mspInstance )
          UFG::GameStatTracker::mspInstance = &sGameStatTracker;
        goto LABEL_33;
      }
    }
  }
  else if ( v8 == UFG::gSimObjectWeaponTypeTrackEnum_eSIM_OBJ_WEAPON_TYPE_RIFLE.m_EnumValue )
  {
    if ( !(*((_BYTE *)v4 + 6216) & 1) )
    {
      ++v4->mpSnapshots[0]->mInts[112].mValue;
      if ( UFG::GameStatAction::PostStat::sIsEnabled )
      {
        if ( !(v6 & 1) )
        {
          _S12_6 = v6 | 1;
          UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
          atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
        }
        goto LABEL_25;
      }
    }
  }
  else
  {
    if ( v8 != UFG::gSimObjectWeaponTypeTrackEnum_eSIM_OBJ_WEAPON_TYPE_SHOTGUN.m_EnumValue )
    {
      if ( v8 == UFG::gSimObjectWeaponTypeTrackEnum_eSIM_OBJ_WEAPON_TYPE_SMG.m_EnumValue )
      {
        if ( !(*((_BYTE *)v4 + 6216) & 1) )
        {
          ++v4->mpSnapshots[0]->mInts[106].mValue;
          if ( UFG::GameStatAction::PostStat::sIsEnabled )
            UFG::GameStatAction::PostStat::AchieveInt(MachineGunHits);
        }
      }
      else
      {
        if ( v8 != UFG::gSimObjectWeaponTypeTrackEnum_eSIM_OBJ_WEAPON_TYPE_SNIPER.m_EnumValue )
          return;
        UFG::GameStatTracker::ApplyDelta(v4, SniperRifleHits, 1);
      }
      goto LABEL_33;
    }
    if ( !(*((_BYTE *)v4 + 6216) & 1) )
    {
      ++v4->mpSnapshots[0]->mInts[115].mValue;
      if ( UFG::GameStatAction::PostStat::sIsEnabled )
      {
        if ( !(v6 & 1) )
        {
          _S12_6 = v6 | 1;
          UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
          atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
        }
        goto LABEL_25;
      }
    }
  }
LABEL_33:
  UFG::qReflectHandleBase::qReflectHandleBase(&v26);
  v10 = UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject>::GetTypeName(v9);
  v26.mTypeUID = UFG::qStringHash64(v10, 0xFFFFFFFFFFFFFFFFui64);
  UFG::qReflectHandleBase::Init(&v26, v26.mTypeUID, v3->mCollisionInfo.mPhysicsObjectPropertyHandleUID);
  v11 = 0;
  if ( v26.mData && HIDWORD(v26.mData[4].mBaseNode.mParent) == -392267045 )
  {
    if ( !v2
      || ((v12 = v2->m_Flags, !((v12 >> 14) & 1)) ? ((v12 & 0x8000u) == 0 ? (!((v12 >> 13) & 1) ? (!((v12 >> 12) & 1) ? (v13 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v2->vfptr, UFG::HealthComponent::_TypeUID)) : (v13 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::HealthComponent::_TypeUID))) : (v13 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::HealthComponent::_TypeUID))) : (v13 = v2->m_Components.p[6].m_pComponent)) : (v13 = v2->m_Components.p[6].m_pComponent),
          !v13
       || !BYTE5(v13[1].m_BoundComponentHandles.mNode.mPrev) && BYTE6(v13[1].m_BoundComponentHandles.mNode.mPrev)) )
    {
      v14 = UFG::OSuiteLeaderboardManager::Instance();
      v15 = UFG::OSuiteLeaderboardManager::GetLeaderboardDataUsingLeaderboardName(v14, "StatAwardsHeadhunter");
      UFG::DataSynchronizer::ApplyDeltaToGlobalSnapshot(v15, 1);
      v16 = UFG::OSuiteLeaderboardManager::Instance();
      v17 = UFG::OSuiteLeaderboardManager::GetLeaderboardDataUsingLeaderboardName(v16, "StatGamesHeadShots");
      UFG::StatGameManager::UpdateScore(v17, 1, 1);
      LOBYTE(result.mUID) = 0;
      pIsAmbient = 0;
      UFG::GameStatAction::MissionScoring::DeduceFaction((UFG::SimObject *)&v2->vfptr, (bool *)&result, &pIsAmbient);
      if ( LOBYTE(result.mUID) || pIsAmbient )
      {
        v19 = 2;
        if ( LOBYTE(result.mUID) )
          v19 = 0;
        UFG::GameStatAction::MissionScoring::LogCopEvent(v19, 0, &customWorldMapCaption);
      }
      else if ( !v2
             || (v18 = UFG::GetLocalPlayer(),
                 !UFG::AreCharactersAllied((UFG::SimObject *)&v18->vfptr, (UFG::SimObject *)&v2->vfptr)) )
      {
        UFG::GameStatAction::MissionScoring::LogTriadEvent(TRIAD_KILL_HEAD_SHOT, 0, &customWorldMapCaption);
      }
    }
  }
  if ( !(*((_BYTE *)v4 + 6216) & 1) )
  {
    ++v4->mpSnapshots[0]->mInts[101].mValue;
    if ( UFG::GameStatAction::PostStat::sIsEnabled )
      UFG::GameStatAction::PostStat::AchieveInt(ShotsHit);
  }
  v20 = (UFG::qSymbol *)UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&result, v4->mpSnapshots[0]->mInts[100].mValue % 50);
  UFG::GameStatTracker::SetStat(v4, Last50ShotsBoolList, v20, 1);
  v21 = v4->mpSnapshots[0]->mpMapBools[84];
  if ( v21->mKeepType != 2 )
  {
    if ( v21->mKeepType == 1 )
    {
      v11 = v21->mNames.size;
    }
    else
    {
      v22 = v21->mValues.size;
      if ( (_DWORD)v22 )
      {
        v23 = &v21->mValues.p->4;
        do
        {
          if ( LOBYTE(v23->mFloatValue) )
            ++v11;
          v23 += 2;
          --v22;
        }
        while ( v22 );
      }
    }
  }
  v24 = UFG::OSuiteLeaderboardManager::Instance();
  v25 = UFG::OSuiteLeaderboardManager::GetLeaderboardDataUsingLeaderboardName(v24, "StatAwardsSniper");
  UFG::DataSynchronizer::SetMaxToGlobalSnapshot(v25, (float)((float)v11 * 100.0) * 0.02);
  UFG::qReflectHandleBase::~qReflectHandleBase(&v26);
}derboardDataUsingLeaderboardName(v24, "StatAwardsSniper");
  UFG::DataSynchronizer::SetMaxToGlobalSnapshot(v25, (float)((float)v11 * 100.0) * 0.02);
  UFG::qReflectHandleB

// File Line: 1641
// RVA: 0x4B5F10
void __fastcall UFG::GameStatAction::World::RegisterZone(unsigned int currentZone)
{
  unsigned int v1; // edi
  char v2; // r12
  UFG::PersistentData::MapBool *v3; // rax
  unsigned int v4; // ecx
  __int64 v5; // rdx
  $CCFB32CF948EEB04FF452B3FEB4ECF53 *v6; // rax
  bool v7; // r15
  UFG::SimpleTimer *v8; // rbx
  UFG::SimpleTimer *v9; // rsi
  UFG::SimpleTimer *v10; // rbp
  UFG::SimpleTimer *v11; // r14
  char v12; // r13
  UFG::SimpleTimer *v13; // rcx
  float v14; // xmm0_4
  char v15; // bl
  char v16; // r15
  char v17; // si
  float v18; // xmm0_4
  char v19; // al
  UFG::allocator::free_link *v20; // rax
  UFG::allocator::free_link *v21; // rdx
  UFG::allocator::free_link *v22; // rax
  char v23; // [rsp+90h] [rbp+8h]
  char v24; // [rsp+98h] [rbp+10h]
  char v25; // [rsp+A0h] [rbp+18h]

  v1 = currentZone;
  if ( UFG::GameStatAction::World::sCurrentZone == currentZone )
    return;
  v2 = 1;
  v3 = UFG::GameStatTracker::Instance()->mpSnapshots[0]->mpMapBools[12];
  if ( v3->mKeepType == 2 )
  {
    v4 = 0;
  }
  else if ( v3->mKeepType == 1 )
  {
    v4 = v3->mNames.size;
  }
  else
  {
    v4 = 0;
    v5 = v3->mValues.size;
    if ( (_DWORD)v5 )
    {
      v6 = &v3->mValues.p->4;
      do
      {
        if ( LOBYTE(v6->mFloatValue) )
          ++v4;
        v6 += 2;
        --v5;
      }
      while ( v5 );
    }
  }
  v7 = v4 != 0;
  v8 = &UFG::GameStatTracker::Instance()->mpSnapshots[0]->mTimes[7].mTimer;
  v9 = &UFG::GameStatTracker::Instance()->mpSnapshots[0]->mTimes[8].mTimer;
  v10 = &UFG::GameStatTracker::Instance()->mpSnapshots[0]->mTimes[9].mTimer;
  v11 = &UFG::GameStatTracker::Instance()->mpSnapshots[0]->mTimes[10].mTimer;
  v12 = 0;
  v23 = 0;
  v25 = 0;
  v24 = 0;
  if ( v1 == UFG::ZoneTag::smNorthPoint )
  {
    v12 = 1;
    if ( v7 )
    {
      UFG::SimpleTimer::Resume(v11);
      v13 = v8;
LABEL_17:
      UFG::SimpleTimer::Stop(v13);
      UFG::SimpleTimer::Stop(v9);
      UFG::SimpleTimer::Stop(v10);
      goto LABEL_25;
    }
  }
  else
  {
    if ( v1 != UFG::ZoneTag::smAberdeen )
    {
      if ( v1 == UFG::ZoneTag::smKennedyTown )
      {
        v25 = 1;
        if ( v7 )
        {
          UFG::SimpleTimer::Resume(v10);
          UFG::SimpleTimer::Stop(v8);
          UFG::SimpleTimer::Stop(v9);
          UFG::SimpleTimer::Stop(v11);
        }
      }
      else if ( v1 == UFG::ZoneTag::smCentral )
      {
        v24 = 1;
        if ( v7 )
        {
          UFG::SimpleTimer::Resume(v9);
          UFG::SimpleTimer::Stop(v8);
          UFG::SimpleTimer::Stop(v11);
          UFG::SimpleTimer::Stop(v10);
        }
      }
      else
      {
        UFG::SimpleTimer::Stop(v9);
        UFG::SimpleTimer::Stop(v8);
        UFG::SimpleTimer::Stop(v11);
        UFG::SimpleTimer::Stop(v10);
        v2 = 0;
      }
      goto LABEL_25;
    }
    v23 = 1;
    if ( v7 )
    {
      UFG::SimpleTimer::Resume(v8);
      v13 = v11;
      goto LABEL_17;
    }
  }
LABEL_25:
  v14 = UFG::SimpleTimer::GetElapsedSeconds(v8);
  v15 = v23;
  if ( v14 > 0.0 )
    v15 = 1;
  v16 = v24;
  if ( UFG::SimpleTimer::GetElapsedSeconds(v9) > 0.0 )
    v16 = 1;
  v17 = v25;
  if ( UFG::SimpleTimer::GetElapsedSeconds(v10) > 0.0 )
    v17 = 1;
  v18 = UFG::SimpleTimer::GetElapsedSeconds(v11);
  v19 = v12;
  if ( v18 > 0.0 )
    v19 = 1;
  if ( v15 && v16 && v17 && v19 )
    UFG::AchievementTrophyManager::UnlockAchievementTrophy(12);
  UFG::GameStatAction::World::sCurrentZone = v1;
  if ( v2 )
  {
    v20 = UFG::qMemoryPool::Allocate(&gScaleformMemoryPool, 0x40ui64, "UICommand", 0i64, 1u);
    v21 = v20;
    if ( v20 )
    {
      v22 = v20 + 1;
      v22->mNext = v22;
      v22[1].mNext = v22;
      v21->mNext = (UFG::allocator::free_link *)&UFG::UICommand::`vftable;
      LODWORD(v21[3].mNext) = -1;
      v21[4].mNext = 0i64;
      v21->mNext = (UFG::allocator::free_link *)&UFG::UIMessage::`vftable;
      v21[5].mNext = (UFG::allocator::free_link *)UI_HASH_REGION_CHANGE_14;
      v21[6].mNext = (UFG::allocator::free_link *)-1i64;
      LODWORD(v21[3].mNext) = 5;
      v21->mNext = (UFG::allocator::free_link *)&UFG::UIMessageRegionChange::`vftable;
      LODWORD(v21[7].mNext) = v1;
    }
    else
    {
      v21 = 0i64;
    }
    UFG::UIScreenManagerBase::queueMessageEx(
      (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
      (UFG::UIMessage *)v21);
  }
}

// File Line: 1746
// RVA: 0x4C7890
void __fastcall UFG::GameStatAction::Inventory::UpdateItem(UFG::eInventoryItemEnum eItem, int iAmount)
{
  int v2; // edi
  __int64 v3; // rsi
  UFG::GameStatTracker *v4; // rbx
  UFG::GameStatTracker *v5; // rcx

  v2 = iAmount;
  v3 = eItem;
  v4 = &sGameStatTracker;
  if ( !(_S12_6 & 1) )
  {
    _S12_6 |= 1u;
    UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
    atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
  }
  v5 = &sGameStatTracker;
  if ( UFG::GameStatTracker::mspInstance )
    v5 = UFG::GameStatTracker::mspInstance;
  UFG::GameStatTracker::mspInstance = v5;
  if ( !(*((_BYTE *)v5 + 6216) & 1) )
  {
    UFG::PersistentData::MapInt::SetStatus(
      v5->mpSnapshots[0]->mpMapInts[15],
      (UFG::qSymbol *)&UFG::InventoryItemEnumSymbols[v3].mUID,
      v2);
    if ( UFG::GameStatAction::PostStat::sIsEnabled )
    {
      if ( !(_S12_6 & 1) )
      {
        _S12_6 |= 1u;
        UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
        atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
      }
      if ( UFG::GameStatTracker::mspInstance )
        v4 = UFG::GameStatTracker::mspInstance;
      UFG::GameStatTracker::mspInstance = v4;
    }
  }
}

// File Line: 1753
// RVA: 0x4B7A10
void __fastcall UFG::GameStatAction::Inventory::RestoreItems(UFG::InventoryComponent *pIC)
{
  UFG::InventoryComponent *v1; // rbx
  UFG::GameStatTracker *v2; // rdi
  UFG::qStaticSymbol *v3; // r9
  signed __int64 v4; // rbx
  signed __int64 v5; // r11
  UFG::PersistentData::MapInt *v6; // rcx
  unsigned int v7; // edx
  __int64 v8; // rax
  UFG::PersistentData::KeyValue *v9; // r10
  UFG::PersistentData::KeyValue *v10; // rcx
  unsigned int v11; // eax

  v1 = pIC;
  v2 = &sGameStatTracker;
  if ( !(_S12_6 & 1) )
  {
    _S12_6 |= 1u;
    UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
    atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
  }
  if ( UFG::GameStatTracker::mspInstance )
    v2 = UFG::GameStatTracker::mspInstance;
  UFG::GameStatTracker::mspInstance = v2;
  v3 = UFG::InventoryItemEnumSymbols;
  v4 = (char *)v1 - (char *)UFG::InventoryItemEnumSymbols;
  v5 = 209i64;
  do
  {
    v6 = v2->mpSnapshots[0]->mpMapInts[15];
    v7 = v6->mValues.size;
    v8 = 0i64;
    if ( !v6->mValues.size )
      goto LABEL_13;
    v9 = v6->mValues.p;
    v10 = v6->mValues.p;
    while ( v10->mKey.mUID != v3->mUID )
    {
      v8 = (unsigned int)(v8 + 1);
      ++v10;
      if ( (unsigned int)v8 >= v7 )
        goto LABEL_13;
    }
    if ( (_DWORD)v8 != -1 )
      v11 = v9[v8].mIntValue;
    else
LABEL_13:
      v11 = 0;
    *(unsigned int *)((char *)&v3[23].mUID + v4) = v11;
    ++v3;
    --v5;
  }
  while ( v5 );
}

// File Line: 1764
// RVA: 0x49E1B0
void __fastcall UFG::GameStatAction::Inventory::Equip(UFG::SimObject *pSimObject)
{
  UFG::SimObjectProp *v1; // rbx
  unsigned __int16 v2; // cx
  UFG::SimObjectWeaponPropertiesComponent *v3; // rax
  UFG::GameStatTracker *v4; // rdi
  UFG::qSymbol *v5; // rax
  unsigned __int16 v6; // cx
  UFG::GunComponent *v7; // rax
  int v8; // eax
  UFG::GameStatTracker *v9; // rbx

  if ( pSimObject )
  {
    v1 = (UFG::SimObjectProp *)pSimObject;
    v2 = pSimObject->m_Flags;
    if ( (v2 >> 14) & 1 )
    {
      v3 = (UFG::SimObjectWeaponPropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                        (UFG::SimObjectGame *)&v1->vfptr,
                                                        UFG::SimObjectWeaponPropertiesComponent::_TypeUID);
    }
    else if ( (v2 & 0x8000u) == 0 )
    {
      if ( (v2 >> 13) & 1 )
        v3 = UFG::SimObjectProp::GetComponent<UFG::SimObjectWeaponPropertiesComponent>(v1);
      else
        v3 = (UFG::SimObjectWeaponPropertiesComponent *)((v2 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                            (UFG::SimObjectGame *)&v1->vfptr,
                                                                            UFG::SimObjectWeaponPropertiesComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v1->vfptr, UFG::SimObjectWeaponPropertiesComponent::_TypeUID));
    }
    else
    {
      v3 = (UFG::SimObjectWeaponPropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                        (UFG::SimObjectGame *)&v1->vfptr,
                                                        UFG::SimObjectWeaponPropertiesComponent::_TypeUID);
    }
    if ( v3 )
    {
      v4 = UFG::GameStatTracker::Instance();
      v5 = UFG::SceneObjectProperties::GetArchetypePropertiesName(v1->m_pSceneObj);
      if ( !(*((_BYTE *)v4 + 6216) & 1) )
        v4->mpSnapshots[0]->mIDs[22].mValue = (UFG::qSymbol)v5->mUID;
      v6 = v1->m_Flags;
      if ( (v6 >> 14) & 1 )
      {
        v7 = (UFG::GunComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                    (UFG::SimObjectGame *)&v1->vfptr,
                                    UFG::GunComponent::_TypeUID);
      }
      else if ( (v6 & 0x8000u) == 0 )
      {
        if ( (v6 >> 13) & 1 )
        {
          v7 = (UFG::GunComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                      (UFG::SimObjectGame *)&v1->vfptr,
                                      UFG::GunComponent::_TypeUID);
        }
        else if ( (v6 >> 12) & 1 )
        {
          v7 = (UFG::GunComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                      (UFG::SimObjectGame *)&v1->vfptr,
                                      UFG::GunComponent::_TypeUID);
        }
        else
        {
          v7 = (UFG::GunComponent *)UFG::SimObject::GetComponentOfType(
                                      (UFG::SimObject *)&v1->vfptr,
                                      UFG::GunComponent::_TypeUID);
        }
      }
      else
      {
        v7 = (UFG::GunComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                    (UFG::SimObjectGame *)&v1->vfptr,
                                    UFG::GunComponent::_TypeUID);
      }
      if ( v7 )
      {
        v8 = UFG::GunComponent::GetClipAmmo(v7);
        if ( !(*((_BYTE *)v4 + 6216) & 1) )
        {
          v4->mpSnapshots[0]->mInts[46].mValue = v8;
          if ( UFG::GameStatAction::PostStat::sIsEnabled )
          {
            v9 = &sGameStatTracker;
            if ( !(_S12_6 & 1) )
            {
              _S12_6 |= 1u;
              UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
              atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
            }
            if ( UFG::GameStatTracker::mspInstance )
              v9 = UFG::GameStatTracker::mspInstance;
            UFG::GameStatTracker::mspInstance = v9;
          }
        }
      }
    }
  }
}

// File Line: 1784
// RVA: 0x4C36F0
void __fastcall UFG::GameStatAction::Inventory::UnequipAllWeapons(const bool bClearInventory)
{
  bool v1; // bp
  UFG::GameStatTracker *v2; // rdi
  UFG::GameStatTracker *v3; // rbx
  UFG::qPropertySet *v4; // rax
  UFG::qPropertySet *v5; // rsi
  char *v6; // rax
  UFG::qSymbol *v7; // rax
  UFG::qStaticSymbol *v8; // rdx
  UFG::GameStatTracker *v9; // rcx
  UFG::qPropertySet *v10; // rax
  char *v11; // rax
  int v12; // eax
  UFG::qPropertySet *v13; // rax
  UFG::qPropertySet *v14; // rsi
  char *v15; // rax
  UFG::qSymbol *v16; // rax
  UFG::qStaticSymbol *v17; // rdx
  UFG::qPropertySet *v18; // rax
  char *v19; // rax
  int v20; // eax
  UFG::qSymbol propSetName; // [rsp+68h] [rbp+10h]
  UFG::qSymbol result; // [rsp+70h] [rbp+18h]
  UFG::qSymbol v23; // [rsp+78h] [rbp+20h]

  v1 = bClearInventory;
  v2 = &sGameStatTracker;
  if ( !(_S12_6 & 1) )
  {
    _S12_6 |= 1u;
    UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
    atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
  }
  v3 = &sGameStatTracker;
  if ( UFG::GameStatTracker::mspInstance )
    v3 = UFG::GameStatTracker::mspInstance;
  UFG::GameStatTracker::mspInstance = v3;
  propSetName.mUID = v3->mpSnapshots[0]->mIDs[23].mValue.mUID;
  if ( propSetName.mUID != -1 )
  {
    if ( v1 )
    {
      v4 = UFG::PropertySetManager::FindPropertySet(&propSetName);
      v5 = v4;
      if ( v4 )
      {
        v6 = UFG::qPropertySet::Get<char const *>(v4, (UFG::qSymbol *)&PhysicsSym_AmmoInventoryItem.mUID, DEPTH_RECURSE);
        if ( v6 )
        {
          v7 = UFG::qSymbol::create_from_string(&result, v6);
          v8 = &UFG::InventoryItemEnumSymbols[(signed int)TracksEnum<unsigned long>::GetEnumFromSymbol(
                                                            &UFG::gInventoryItemTracksEnum,
                                                            v7)];
          if ( !(*((_BYTE *)v3 + 6216) & 1) )
          {
            UFG::PersistentData::MapInt::SetStatus(v3->mpSnapshots[0]->mpMapInts[15], (UFG::qSymbol *)&v8->mUID, 0);
            if ( UFG::GameStatAction::PostStat::sIsEnabled )
            {
              if ( !(_S12_6 & 1) )
              {
                _S12_6 |= 1u;
                UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
                atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
              }
              v9 = &sGameStatTracker;
              if ( UFG::GameStatTracker::mspInstance )
                v9 = UFG::GameStatTracker::mspInstance;
              UFG::GameStatTracker::mspInstance = v9;
            }
          }
        }
        v10 = UFG::qPropertySet::Get<UFG::qPropertySet>(
                v5,
                (UFG::qSymbol *)&component_InventoryItem::sPropertyName.mUID,
                DEPTH_RECURSE);
        if ( v10 )
        {
          v11 = UFG::qPropertySet::GetMemImagePtr(v10);
          if ( v11 )
          {
            result.mUID = *((_DWORD *)v11 + 2);
            if ( result.mUID != -1 )
            {
              v12 = TracksEnum<unsigned long>::GetEnumFromSymbol(&UFG::gInventoryItemTracksEnum, &result);
              UFG::GameStatTracker::SetStat(
                v3,
                InventoryItems,
                (UFG::qSymbol *)&UFG::InventoryItemEnumSymbols[v12].mUID,
                0);
            }
          }
        }
      }
    }
    if ( !(*((_BYTE *)v3 + 6216) & 1) )
      v3->mpSnapshots[0]->mIDs[23].mValue = UFG::gNullQSymbol;
  }
  v23.mUID = v3->mpSnapshots[0]->mIDs[24].mValue.mUID;
  if ( v23.mUID != -1 )
  {
    if ( v1 )
    {
      v13 = UFG::PropertySetManager::FindPropertySet(&v23);
      v14 = v13;
      if ( v13 )
      {
        v15 = UFG::qPropertySet::Get<char const *>(
                v13,
                (UFG::qSymbol *)&PhysicsSym_AmmoInventoryItem.mUID,
                DEPTH_RECURSE);
        if ( v15 )
        {
          v16 = UFG::qSymbol::create_from_string(&result, v15);
          v17 = &UFG::InventoryItemEnumSymbols[(signed int)TracksEnum<unsigned long>::GetEnumFromSymbol(
                                                             &UFG::gInventoryItemTracksEnum,
                                                             v16)];
          if ( !(*((_BYTE *)v3 + 6216) & 1) )
          {
            UFG::PersistentData::MapInt::SetStatus(v3->mpSnapshots[0]->mpMapInts[15], (UFG::qSymbol *)&v17->mUID, 0);
            if ( UFG::GameStatAction::PostStat::sIsEnabled )
            {
              if ( !(_S12_6 & 1) )
              {
                _S12_6 |= 1u;
                UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
                atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
              }
              if ( UFG::GameStatTracker::mspInstance )
                v2 = UFG::GameStatTracker::mspInstance;
              UFG::GameStatTracker::mspInstance = v2;
            }
          }
        }
        v18 = UFG::qPropertySet::Get<UFG::qPropertySet>(
                v14,
                (UFG::qSymbol *)&component_InventoryItem::sPropertyName.mUID,
                DEPTH_RECURSE);
        if ( v18 )
        {
          v19 = UFG::qPropertySet::GetMemImagePtr(v18);
          if ( v19 )
          {
            result.mUID = *((_DWORD *)v19 + 2);
            if ( result.mUID != -1 )
            {
              v20 = TracksEnum<unsigned long>::GetEnumFromSymbol(&UFG::gInventoryItemTracksEnum, &result);
              UFG::GameStatTracker::SetStat(
                v3,
                InventoryItems,
                (UFG::qSymbol *)&UFG::InventoryItemEnumSymbols[v20].mUID,
                0);
            }
          }
        }
      }
    }
    if ( !(*((_BYTE *)v3 + 6216) & 1) )
      v3->mpSnapshots[0]->mIDs[24].mValue = UFG::gNullQSymbol;
  }
}

// File Line: 1859
// RVA: 0x4C34B0
void __fastcall UFG::GameStatAction::Inventory::UnEquip(const bool bClearInventory)
{
  bool v1; // si
  unsigned int v2; // edx
  UFG::GameStatTracker *v3; // rbx
  UFG::GameStatTracker *v4; // rdi
  UFG::qPropertySet *v5; // rax
  UFG::qPropertySet *v6; // rsi
  char *v7; // rax
  UFG::qSymbol *v8; // rax
  UFG::qStaticSymbol *v9; // rdx
  UFG::GameStatTracker *v10; // rcx
  UFG::qPropertySet *v11; // rax
  char *v12; // rax
  int v13; // eax
  UFG::qSymbol propSetName; // [rsp+58h] [rbp+10h]
  UFG::qSymbol result; // [rsp+60h] [rbp+18h]

  v1 = bClearInventory;
  v2 = _S12_6;
  v3 = &sGameStatTracker;
  if ( !(_S12_6 & 1) )
  {
    _S12_6 |= 1u;
    UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
    atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
    v2 = _S12_6;
  }
  v4 = &sGameStatTracker;
  if ( UFG::GameStatTracker::mspInstance )
    v4 = UFG::GameStatTracker::mspInstance;
  UFG::GameStatTracker::mspInstance = v4;
  propSetName.mUID = v4->mpSnapshots[0]->mIDs[22].mValue.mUID;
  if ( propSetName.mUID == -1 )
    goto LABEL_23;
  if ( v1 )
  {
    v5 = UFG::PropertySetManager::FindPropertySet(&propSetName);
    v6 = v5;
    if ( v5 )
    {
      v7 = UFG::qPropertySet::Get<char const *>(v5, (UFG::qSymbol *)&PhysicsSym_AmmoInventoryItem.mUID, DEPTH_RECURSE);
      if ( v7 )
      {
        v8 = UFG::qSymbol::create_from_string(&result, v7);
        v9 = &UFG::InventoryItemEnumSymbols[(signed int)TracksEnum<unsigned long>::GetEnumFromSymbol(
                                                          &UFG::gInventoryItemTracksEnum,
                                                          v8)];
        if ( !(*((_BYTE *)v4 + 6216) & 1) )
        {
          UFG::PersistentData::MapInt::SetStatus(v4->mpSnapshots[0]->mpMapInts[15], (UFG::qSymbol *)&v9->mUID, 0);
          if ( UFG::GameStatAction::PostStat::sIsEnabled )
          {
            if ( !(_S12_6 & 1) )
            {
              _S12_6 |= 1u;
              UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
              atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
            }
            v10 = &sGameStatTracker;
            if ( UFG::GameStatTracker::mspInstance )
              v10 = UFG::GameStatTracker::mspInstance;
            UFG::GameStatTracker::mspInstance = v10;
          }
        }
      }
      v11 = UFG::qPropertySet::Get<UFG::qPropertySet>(
              v6,
              (UFG::qSymbol *)&component_InventoryItem::sPropertyName.mUID,
              DEPTH_RECURSE);
      if ( v11 )
      {
        v12 = UFG::qPropertySet::GetMemImagePtr(v11);
        if ( v12 )
        {
          result.mUID = *((_DWORD *)v12 + 2);
          if ( result.mUID != -1 )
          {
            v13 = TracksEnum<unsigned long>::GetEnumFromSymbol(&UFG::gInventoryItemTracksEnum, &result);
            UFG::GameStatTracker::SetStat(
              v4,
              InventoryItems,
              (UFG::qSymbol *)&UFG::InventoryItemEnumSymbols[v13].mUID,
              0);
          }
        }
      }
    }
    v2 = _S12_6;
  }
  if ( !(*((_BYTE *)v4 + 6216) & 1) )
  {
    v4->mpSnapshots[0]->mIDs[22].mValue = UFG::gNullQSymbol;
LABEL_23:
    if ( !(*((_BYTE *)v4 + 6216) & 1) )
    {
      v4->mpSnapshots[0]->mInts[46].mValue = 0;
      if ( UFG::GameStatAction::PostStat::sIsEnabled )
      {
        if ( !(v2 & 1) )
        {
          _S12_6 = v2 | 1;
          UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
          atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
        }
        if ( UFG::GameStatTracker::mspInstance )
          v3 = UFG::GameStatTracker::mspInstance;
        UFG::GameStatTracker::mspInstance = v3;
      }
    }
  }
}

// File Line: 1902
// RVA: 0x4B7740
void __fastcall UFG::GameStatAction::Inventory::RestoreEquipped(UFG::InventoryComponent *pIC, __int64 weaponOverride)
{
  UFG::qSymbol *v2; // rsi
  UFG::InventoryComponent *v3; // r14
  UFG::GameSnapshot *v4; // r8
  unsigned int v5; // er8
  UFG::qPropertySet *v6; // rbx
  UFG::qPropertySet *v7; // rax
  UFG::qPropertySet *v8; // rdi
  UFG::qPropertySet *v9; // rsi
  UFG::qPropertySet *v10; // rax
  bool v11; // bp
  UFG::qPropertySet *v12; // rax
  UFG::SimObjectGame *v13; // rax
  UFG::SimObject *v14; // rdi
  unsigned __int16 v15; // dx
  UFG::RigidBody *v16; // rax
  UFG::SimObjectGame *v17; // rax
  UFG::SimObject *v18; // rbx
  unsigned __int16 v19; // dx
  UFG::RigidBody *v20; // rax
  UFG::qSymbol v21; // [rsp+60h] [rbp+8h]
  UFG::qSymbol propSetName; // [rsp+70h] [rbp+18h]
  UFG::qSymbol result; // [rsp+78h] [rbp+20h]

  if ( pIC )
  {
    v2 = (UFG::qSymbol *)weaponOverride;
    v3 = pIC;
    v4 = UFG::GameStatTracker::Instance()->mpSnapshots[0];
    propSetName.mUID = v4->mIDs[23].mValue.mUID;
    v5 = v4->mIDs[24].mValue.mUID;
    v21.mUID = v5;
    if ( propSetName.mUID == -1 )
    {
      v6 = 0i64;
    }
    else
    {
      v7 = UFG::PropertySetManager::FindPropertySet(&propSetName);
      v5 = v21.mUID;
      v6 = v7;
    }
    if ( v5 == -1 )
      v8 = 0i64;
    else
      v8 = UFG::PropertySetManager::FindPropertySet(&v21);
    if ( v2->mUID == -1 )
      v9 = 0i64;
    else
      v9 = UFG::PropertySetManager::FindPropertySet(v2);
    if ( v6 )
      v10 = UFG::qPropertySet::GetParentFromName(v6, (UFG::qSymbol *)&SimSymX_propset_componentGun.mUID, DEPTH_RECURSE);
    else
      v10 = 0i64;
    v11 = v10 != 0i64;
    if ( v8 )
      v12 = UFG::qPropertySet::GetParentFromName(v8, (UFG::qSymbol *)&SimSymX_propset_componentGun.mUID, DEPTH_RECURSE);
    else
      v12 = 0i64;
    if ( !v11 && !v12 && v9 )
      v6 = v9;
    if ( v8 )
    {
      UFG::Simulation::GenerateUniqueName(&UFG::gSim, &result, "RestoredWeaponStowed");
      v13 = (UFG::SimObjectGame *)UFG::SpawnInfoInterface::SpawnObject(&result, v8, 0, 0i64, 0i64, 0i64);
      v14 = (UFG::SimObject *)&v13->vfptr;
      if ( v13 )
      {
        v15 = v13->m_Flags;
        if ( (v15 >> 14) & 1 )
        {
          v16 = (UFG::RigidBody *)UFG::SimObjectGame::GetComponentOfTypeHK(v13, UFG::RigidBodyComponent::_TypeUID);
        }
        else if ( (v15 & 0x8000u) == 0 )
        {
          if ( (v15 >> 13) & 1 )
          {
            v16 = (UFG::RigidBody *)UFG::SimObjectGame::GetComponentOfTypeHK(v13, UFG::RigidBodyComponent::_TypeUID);
          }
          else if ( (v15 >> 12) & 1 )
          {
            v16 = (UFG::RigidBody *)UFG::SimObjectGame::GetComponentOfTypeHK(v13, UFG::RigidBodyComponent::_TypeUID);
          }
          else
          {
            v16 = (UFG::RigidBody *)UFG::SimObject::GetComponentOfType(
                                      (UFG::SimObject *)&v13->vfptr,
                                      UFG::RigidBodyComponent::_TypeUID);
          }
        }
        else
        {
          v16 = (UFG::RigidBody *)UFG::SimObjectGame::GetComponentOfTypeHK(v13, UFG::RigidBodyComponent::_TypeUID);
        }
        if ( v16 )
          UFG::RigidBody::SetMotionType(v16, 0x100u);
        UFG::InventoryComponent::Equip(v3, v14, 1, 0);
        UFG::InventoryComponent::Stow(v3, 0, eINVENTORY_EQUIP_SLOT_STOWED_1H);
      }
    }
    if ( v6 )
    {
      UFG::Simulation::GenerateUniqueName(&UFG::gSim, &result, "RestoredWeaponEquipped");
      v17 = (UFG::SimObjectGame *)UFG::SpawnInfoInterface::SpawnObject(&result, v6, 0, 0i64, 0i64, 0i64);
      v18 = (UFG::SimObject *)&v17->vfptr;
      if ( v17 )
      {
        v19 = v17->m_Flags;
        if ( (v19 >> 14) & 1 )
        {
          v20 = (UFG::RigidBody *)UFG::SimObjectGame::GetComponentOfTypeHK(v17, UFG::RigidBodyComponent::_TypeUID);
        }
        else if ( (v19 & 0x8000u) == 0 )
        {
          if ( (v19 >> 13) & 1 )
          {
            v20 = (UFG::RigidBody *)UFG::SimObjectGame::GetComponentOfTypeHK(v17, UFG::RigidBodyComponent::_TypeUID);
          }
          else if ( (v19 >> 12) & 1 )
          {
            v20 = (UFG::RigidBody *)UFG::SimObjectGame::GetComponentOfTypeHK(v17, UFG::RigidBodyComponent::_TypeUID);
          }
          else
          {
            v20 = (UFG::RigidBody *)UFG::SimObject::GetComponentOfType(
                                      (UFG::SimObject *)&v17->vfptr,
                                      UFG::RigidBodyComponent::_TypeUID);
          }
        }
        else
        {
          v20 = (UFG::RigidBody *)UFG::SimObjectGame::GetComponentOfTypeHK(v17, UFG::RigidBodyComponent::_TypeUID);
        }
        if ( v20 )
          UFG::RigidBody::SetMotionType(v20, 0x100u);
        UFG::InventoryComponent::Equip(v3, v18, 1, 0);
      }
    }
  }
}

// File Line: 2048
// RVA: 0x494F40
char __fastcall UFG::GameStatAction::Store::AreAllItemsPurchased(__int64 store, UFG::GameStat::MapBoolStat snapShotEntry)
{
  __int64 v2; // r13
  UFG::qPropertySet *v3; // rbx
  UFG::qSymbol *v4; // rax
  UFG::qPropertyList *v5; // rax
  UFG::qPropertyList *v6; // r15
  char v7; // r14
  unsigned int v8; // er12
  unsigned int v9; // ebp
  char *v10; // rax
  UFG::qPropertySet *v11; // rsi
  float *v12; // rax
  float *v13; // rcx
  unsigned int v14; // ebx
  UFG::GameStatTracker *v15; // rdi
  UFG::GameStatTracker *v16; // rax
  float v18; // [rsp+90h] [rbp+18h]
  UFG::qSymbol result; // [rsp+98h] [rbp+20h]

  v2 = snapShotEntry;
  v3 = UFG::PropertySetManager::GetPropertySet((UFG::qSymbol *)store);
  if ( !v3 )
    return 0;
  v4 = UFG::qSymbol::create_from_string(&result, "Items");
  v5 = UFG::qPropertySet::Get<UFG::qPropertyList>(v3, v4, DEPTH_RECURSE);
  v6 = v5;
  if ( !v5 )
    return 0;
  v7 = 1;
  v8 = v5->mNumElements;
  v9 = 0;
  if ( v8 )
  {
    v18 = FLOAT_N1_0;
    do
    {
      v10 = UFG::qPropertyList::GetValuePtr(v6, 0x1Au, v9);
      if ( !v10 || (v11 = (UFG::qPropertySet *)&v10[*(_QWORD *)v10], !*(_QWORD *)v10) )
        v11 = 0i64;
      v12 = UFG::qPropertySet::Get<float>(v11, (UFG::qSymbol *)&UFG::StoreItemSymbol_Price.mUID, DEPTH_RECURSE);
      v13 = &v18;
      if ( v12 )
        v13 = v12;
      v14 = _S12_6;
      if ( *v13 <= 0.0 )
      {
        v15 = UFG::GameStatTracker::mspInstance;
      }
      else
      {
        if ( !(_S12_6 & 1) )
        {
          _S12_6 |= 1u;
          UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
          atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
          v14 = _S12_6;
        }
        v15 = &sGameStatTracker;
        if ( UFG::GameStatTracker::mspInstance )
          v15 = UFG::GameStatTracker::mspInstance;
        UFG::GameStatTracker::mspInstance = v15;
        if ( !UFG::PersistentData::MapBool::GetStatus(v15->mpSnapshots[0]->mpMapBools[v2], &v11->mName) )
          v7 = 0;
      }
      if ( !(v14 & 1) )
      {
        _S12_6 = v14 | 1;
        UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
        atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
        v15 = UFG::GameStatTracker::mspInstance;
      }
      v16 = &sGameStatTracker;
      if ( v15 )
        v16 = v15;
      UFG::GameStatTracker::mspInstance = v16;
      UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&v11->mName);
      ++v9;
    }
    while ( v9 < v8 );
  }
  return v7;
}

// File Line: 2095
// RVA: 0x494F00
char __fastcall UFG::GameStatAction::Store::AreAllClothesPurchased()
{
  UFG::qSymbol *v0; // rax
  UFG::qSymbol result; // [rsp+40h] [rbp+8h]
  UFG::qSymbol *v3; // [rsp+48h] [rbp+10h]

  v3 = &result;
  v0 = UFG::qSymbol::create_from_string(&result, "default-unlockables-merchantdatabase-clothing");
  return UFG::GameStatAction::Store::AreAllItemsPurchased((__int64)v0, Asset_Clothing);
}

// File Line: 2100
// RVA: 0x495140
char __fastcall UFG::GameStatAction::Store::AreAllVehiclesPurchased()
{
  UFG::qSymbol *v0; // rax
  UFG::qSymbol result; // [rsp+40h] [rbp+8h]
  UFG::qSymbol *v3; // [rsp+48h] [rbp+10h]

  v3 = &result;
  v0 = UFG::qSymbol::create_from_string(&result, "default-unlockables-merchantdatabase-vehicles");
  return UFG::GameStatAction::Store::AreAllItemsPurchased((__int64)v0, Asset_Vehicle);
}

// File Line: 2106
// RVA: 0x4B6240
void __fastcall UFG::GameStatAction::Weapon::Reload(UFG::GunComponent *pGC)
{
  UFG::GunComponent *v1; // rdi
  UFG::GameStatTracker *v2; // rbx
  int v3; // eax
  UFG::qSymbol mapid; // [rsp+48h] [rbp+10h]
  UFG::qSymbol *v5; // [rsp+50h] [rbp+18h]

  v1 = pGC;
  v2 = &sGameStatTracker;
  if ( !(_S12_6 & 1) )
  {
    _S12_6 |= 1u;
    UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
    atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
  }
  if ( UFG::GameStatTracker::mspInstance )
    v2 = UFG::GameStatTracker::mspInstance;
  UFG::GameStatTracker::mspInstance = v2;
  v3 = UFG::GunComponent::GetClipAmmo(v1);
  if ( !(*((_BYTE *)v2 + 6216) & 1) )
  {
    v2->mpSnapshots[0]->mInts[46].mValue = v3;
    v5 = &mapid;
    mapid.mUID = UFG::gNullQSymbol.mUID;
    UFG::GameStatAction::PostStat::Achieve(PDT_INT, 46, (__int64)&mapid);
  }
}

// File Line: 2116
// RVA: 0x49D1D0
void __fastcall UFG::GameStatAction::Weapon::Discharge(UFG::GunComponent *pGC)
{
  UFG::GunComponent *v1; // rdi
  UFG::GameStatTracker *v2; // rbx
  int v3; // eax
  CAkScheduledItem *v4; // rax
  int v5; // eax
  UFG::qSymbol *v6; // rax
  UFG::SimObjectWeaponPropertiesComponent *v7; // rax
  UFG::qSymbol *v8; // rax
  unsigned int *v9; // rdi
  unsigned int v10; // eax
  UFG::qSymbol mapid; // [rsp+58h] [rbp+10h]
  UFG::qSymbol *result; // [rsp+60h] [rbp+18h]
  UFG::qSymbol *v13; // [rsp+68h] [rbp+20h]

  v1 = pGC;
  if ( !(_S12_6 & 1) )
  {
    _S12_6 |= 1u;
    UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
    atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
  }
  v2 = &sGameStatTracker;
  if ( UFG::GameStatTracker::mspInstance )
    v2 = UFG::GameStatTracker::mspInstance;
  UFG::GameStatTracker::mspInstance = v2;
  v3 = UFG::GunComponent::GetClipAmmo(v1);
  if ( !(*((_BYTE *)v2 + 6216) & 1) )
  {
    v2->mpSnapshots[0]->mInts[46].mValue = v3;
    result = &mapid;
    mapid.mUID = UFG::gNullQSymbol.mUID;
    UFG::GameStatAction::PostStat::Achieve(PDT_INT, 46, (__int64)&mapid);
  }
  v4 = UFG::GunComponent::GetSimObjectWeaponPropertiesComponent((CAkChainCtx *)v1);
  v5 = **(_DWORD **)(*(_QWORD *)&v4[2].m_cmdStop.iRelativeTime
                   + 8i64 * (unsigned int)v4[2].m_cmdPlay.fadeParams.iFadeOffset
                   + 8);
  if ( v5 == UFG::gSimObjectWeaponTypeTrackEnum_eSIM_OBJ_WEAPON_TYPE_PISTOL.m_EnumValue )
  {
    if ( !(*((_BYTE *)v2 + 6216) & 1) )
    {
      ++v2->mpSnapshots[0]->mInts[102].mValue;
      if ( UFG::GameStatAction::PostStat::sIsEnabled )
      {
        if ( !(_S12_6 & 1) )
        {
          _S12_6 |= 1u;
          UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
          atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
        }
LABEL_27:
        if ( !UFG::GameStatTracker::mspInstance )
          UFG::GameStatTracker::mspInstance = &sGameStatTracker;
        goto LABEL_31;
      }
      goto LABEL_31;
    }
  }
  else if ( v5 == UFG::gSimObjectWeaponTypeTrackEnum_eSIM_OBJ_WEAPON_TYPE_RIFLE.m_EnumValue )
  {
    if ( !(*((_BYTE *)v2 + 6216) & 1) )
    {
      ++v2->mpSnapshots[0]->mInts[111].mValue;
      if ( UFG::GameStatAction::PostStat::sIsEnabled )
      {
        if ( !(_S12_6 & 1) )
        {
          _S12_6 |= 1u;
          UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
          atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
        }
        goto LABEL_27;
      }
LABEL_31:
      if ( !(*((_BYTE *)v2 + 6216) & 1) )
      {
        ++v2->mpSnapshots[0]->mInts[100].mValue;
        if ( UFG::GameStatAction::PostStat::sIsEnabled )
          UFG::GameStatAction::PostStat::AchieveInt(ShotsMade);
      }
      goto LABEL_34;
    }
  }
  else if ( v5 == UFG::gSimObjectWeaponTypeTrackEnum_eSIM_OBJ_WEAPON_TYPE_SHOTGUN.m_EnumValue )
  {
    if ( !(*((_BYTE *)v2 + 6216) & 1) )
    {
      ++v2->mpSnapshots[0]->mInts[114].mValue;
      if ( UFG::GameStatAction::PostStat::sIsEnabled )
      {
        if ( !(_S12_6 & 1) )
        {
          _S12_6 |= 1u;
          UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
          atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
        }
        goto LABEL_27;
      }
      goto LABEL_31;
    }
  }
  else
  {
    if ( v5 != UFG::gSimObjectWeaponTypeTrackEnum_eSIM_OBJ_WEAPON_TYPE_SMG.m_EnumValue )
    {
      if ( v5 != UFG::gSimObjectWeaponTypeTrackEnum_eSIM_OBJ_WEAPON_TYPE_SNIPER.m_EnumValue )
        return;
      UFG::GameStatTracker::ApplyDelta(v2, SniperRifleFired, 1);
      goto LABEL_31;
    }
    if ( !(*((_BYTE *)v2 + 6216) & 1) )
    {
      ++v2->mpSnapshots[0]->mInts[105].mValue;
      if ( UFG::GameStatAction::PostStat::sIsEnabled )
      {
        if ( !(_S12_6 & 1) )
        {
          _S12_6 |= 1u;
          UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
          atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
        }
        goto LABEL_27;
      }
      goto LABEL_31;
    }
  }
LABEL_34:
  v6 = (UFG::qSymbol *)UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&mapid, v2->mpSnapshots[0]->mInts[100].mValue % 50);
  UFG::GameStatTracker::SetStat(v2, Last50ShotsBoolList, v6, 0);
  v7 = (UFG::SimObjectWeaponPropertiesComponent *)UFG::GunComponent::GetSimObjectWeaponPropertiesComponent((CAkChainCtx *)v1);
  v8 = UFG::SimObjectWeaponPropertiesComponent::GetWeaponID(v7, (UFG::qSymbol *)&result);
  v9 = &v8->mUID;
  if ( !(*((_BYTE *)v2 + 6216) & 1) )
  {
    UFG::PersistentData::MapInt::ApplyDelta(v2->mpSnapshots[0]->mpMapInts[26], v8, 1);
    v10 = *v9;
    if ( UFG::GameStatAction::PostStat::sIsEnabled )
    {
      v13 = &mapid;
      mapid.mUID = v10;
      UFG::GameStatAction::PostStat::AchieveMapInt(FireArmFired, (UFG::qSymbol)&mapid);
    }
  }
}

// File Line: 2167
// RVA: 0x4A3460
UFG::SimObjectWeaponPropertiesComponent *__fastcall UFG::GameStatAction::Weapon::GetHoldingWeapon(UFG::SimObject *holder)
{
  unsigned __int16 v1; // dx
  UFG::SimComponent *v2; // rdx
  UFG::SimComponent *v3; // rax
  UFG::SimObjectProp *v4; // rcx
  unsigned __int16 v5; // dx
  unsigned int v6; // edx
  bool v8; // zf

  if ( holder )
  {
    v1 = holder->m_Flags;
    if ( (v1 >> 14) & 1 )
    {
      v2 = holder->m_Components.p[20].m_pComponent;
    }
    else if ( (v1 & 0x8000u) == 0 )
    {
      if ( (v1 >> 13) & 1 )
        v3 = UFG::SimObjectGame::GetComponentOfTypeHK(
               (UFG::SimObjectGame *)holder,
               UFG::TargetingSystemBaseComponent::_TypeUID);
      else
        v3 = (v1 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                (UFG::SimObjectGame *)holder,
                                UFG::TargetingSystemBaseComponent::_TypeUID) : UFG::SimObject::GetComponentOfType(
                                                                                 holder,
                                                                                 UFG::TargetingSystemBaseComponent::_TypeUID);
      v2 = v3;
    }
    else
    {
      v2 = holder->m_Components.p[20].m_pComponent;
    }
    if ( v2 )
    {
      v4 = *(UFG::SimObjectProp **)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&v2[1].m_Flags + 25i64)
                                  + *(_QWORD *)&v2[1].m_TypeUID
                                  + 40);
      if ( v4 )
      {
        v5 = v4->m_Flags;
        if ( (v5 >> 14) & 1 || (v5 & 0x8000u) != 0 )
        {
          v6 = UFG::SimObjectWeaponPropertiesComponent::_TypeUID;
        }
        else
        {
          if ( (v5 >> 13) & 1 )
            return UFG::SimObjectProp::GetComponent<UFG::SimObjectWeaponPropertiesComponent>(v4);
          v8 = ((v5 >> 12) & 1) == 0;
          v6 = UFG::SimObjectWeaponPropertiesComponent::_TypeUID;
          if ( v8 )
            return (UFG::SimObjectWeaponPropertiesComponent *)UFG::SimObject::GetComponentOfType(
                                                                (UFG::SimObject *)&v4->vfptr,
                                                                UFG::SimObjectWeaponPropertiesComponent::_TypeUID);
        }
        return (UFG::SimObjectWeaponPropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                            (UFG::SimObjectGame *)&v4->vfptr,
                                                            v6);
      }
    }
  }
  return 0i64;
}

// File Line: 2202
// RVA: 0x4B9EA0
void __fastcall UFG::GameStatAction::Money::SendTransactionTelemetry(UFG::qSymbol *origin, UFG::qSymbol *itemName, int amount)
{
  int v3; // ebp
  UFG::qSymbol *v4; // r14
  UFG::qSymbol *v5; // r15
  UFG::GameStatTracker *v6; // rbx
  int v7; // edi
  UFG::GameSlice *v8; // rcx
  UFG::qSymbol *v9; // rcx
  int v10; // ebx
  UFG::OSuiteDBLogger *v11; // rsi
  int v12; // edi
  int v13; // edi
  char dest; // [rsp+30h] [rbp-98h]

  v3 = amount;
  v4 = itemName;
  v5 = origin;
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
  v7 = v6->mpSnapshots[0]->mInts[62].mValue - v3;
  v8 = UFG::ProgressionTracker::Instance()->mpActiveMaster;
  if ( !v8 || v8->mInternalSlice )
    v9 = &UFG::gNullQSymbol;
  else
    v9 = (UFG::qSymbol *)&v8->mNode.mUID;
  v10 = v9->mUID;
  v11 = UFG::OSuiteDBLogger::Instance();
  if ( UFG::OSuiteDBLogger::CreateMetric(v11, "MoneyTransaction") )
  {
    UFG::qSPrintf(&dest, 128, "i32_%s", "MoneyBeforeTransaction", -2i64);
    OSuite::ZMetric::SetProperty(v11->m_pMetric, &dest, v7);
    UFG::qSPrintf(&dest, 128, "i32_%s", "TransactionValue");
    OSuite::ZMetric::SetProperty(v11->m_pMetric, &dest, v3);
    v12 = v4->mUID;
    UFG::qSPrintf(&dest, 128, "i32_%s", "ItemPurchased");
    OSuite::ZMetric::SetProperty(v11->m_pMetric, &dest, v12);
    v13 = v5->mUID;
    UFG::qSPrintf(&dest, 128, "i32_%s", "LocationType");
    OSuite::ZMetric::SetProperty(v11->m_pMetric, &dest, v13);
    UFG::qSPrintf(&dest, 128, "i32_%s", "ContentName");
    OSuite::ZMetric::SetProperty(v11->m_pMetric, &dest, v10);
    UFG::OSuiteDBLogger::SubmitMetric(v11, 1);
  }
}

// File Line: 2232
// RVA: 0x4B3110
void __fastcall UFG::GameStatAction::Money::PurchaseItem(UFG::SimObject *pOrigin, UFG::eInventoryItemEnum inventory, int cost)
{
  int v3; // edi
  __int64 v4; // r14
  UFG::SimObject *v5; // rbp
  unsigned int v6; // er8
  UFG::GameStatTracker *v7; // rsi
  UFG::GameStatTracker *v8; // rbx
  UFG::GameStatTracker *v9; // rcx
  UFG::GameSnapshot *v10; // rax
  int v11; // er8
  UFG::qSymbol *v12; // rax
  UFG::GameSnapshot *v13; // rdx
  int v14; // ecx
  int v15; // eax
  UFG::qSymbol *v16; // rax
  UFG::OSuiteLeaderboardManager *v17; // rax
  UFG::OSuiteLeaderboardData *v18; // rax
  char *v19; // rcx
  UFG::qSymbol *v20; // rax
  UFG::OSuiteLeaderboardManager *v21; // rax
  UFG::OSuiteLeaderboardData *v22; // rax
  UFG::OSuiteLeaderboardManager *v23; // rax
  UFG::OSuiteLeaderboardData *v24; // rax
  char v25; // [rsp+70h] [rbp+8h]
  UFG::qSymbol origin; // [rsp+78h] [rbp+10h]
  UFG::qWiseSymbol result; // [rsp+80h] [rbp+18h]
  char v28; // [rsp+88h] [rbp+20h]

  v3 = cost;
  v4 = inventory;
  v5 = pOrigin;
  v6 = _S12_6;
  v7 = &sGameStatTracker;
  if ( !(_S12_6 & 1) )
  {
    _S12_6 |= 1u;
    UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
    atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
    v6 = _S12_6;
  }
  v8 = &sGameStatTracker;
  if ( UFG::GameStatTracker::mspInstance )
    v8 = UFG::GameStatTracker::mspInstance;
  UFG::GameStatTracker::mspInstance = v8;
  if ( !(*((_BYTE *)v8 + 6216) & 1) )
  {
    v8->mpSnapshots[0]->mInts[62].mValue -= v3;
    if ( UFG::GameStatAction::PostStat::sIsEnabled )
    {
      if ( !(v6 & 1) )
      {
        _S12_6 = v6 | 1;
        UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
        atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
      }
      v9 = &sGameStatTracker;
      if ( UFG::GameStatTracker::mspInstance )
        v9 = UFG::GameStatTracker::mspInstance;
      UFG::GameStatTracker::mspInstance = v9;
      v10 = v9->mpSnapshots[0];
      v11 = v10->mInts[62].mValue;
      if ( v10->mInts[63].mValue < v11 )
        UFG::GameStatTracker::SetStat(v9, MostCashHeld, v11);
    }
  }
  v12 = &v5->m_Name;
  if ( !v5 )
    v12 = &UFG::gNullQSymbol;
  origin.mUID = v12->mUID;
  UFG::GameStatAction::Money::SendTransactionTelemetry(
    &origin,
    (UFG::qSymbol *)&UFG::InventoryItemEnumSymbols[v4].mUID,
    -v3);
  switch ( (_DWORD)v4 )
  {
    case 1:
    case 3:
    case 4:
    case 7:
    case 8:
    case 9:
    case 0x20:
    case 0x22:
    case 0x24:
    case 0x29:
    case 0x2A:
    case 0x2B:
    case 0x2E:
    case 0x32:
    case 0x34:
    case 0x37:
    case 0x39:
    case 0x41:
    case 0x42:
    case 0x43:
      if ( !(*((_BYTE *)v8 + 6216) & 1) )
      {
        v8->mpSnapshots[0]->mInts[70].mValue += v3;
        if ( UFG::GameStatAction::PostStat::sIsEnabled )
        {
          if ( !(_S12_6 & 1) )
          {
            _S12_6 |= 1u;
            UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
            atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
          }
          if ( UFG::GameStatTracker::mspInstance )
            v7 = UFG::GameStatTracker::mspInstance;
          UFG::GameStatTracker::mspInstance = v7;
        }
        if ( !(*((_BYTE *)v8 + 6216) & 1) )
        {
          v13 = v8->mpSnapshots[0];
          v14 = 0;
          if ( v13->mIntsRanged[0].mValue + 1 > 0 )
            v14 = v13->mIntsRanged[0].mValue + 1;
          v15 = v13->mIntsRanged[0].mRange;
          if ( v14 < v15 )
            v15 = v14;
          v13->mIntsRanged[0].mValue = v15;
        }
      }
      goto LABEL_79;
    case 0x12:
      if ( !(*((_BYTE *)v8 + 6216) & 1) )
      {
        v8->mpSnapshots[0]->mInts[75].mValue += v3;
        if ( UFG::GameStatAction::PostStat::sIsEnabled )
        {
          if ( !(_S12_6 & 1) )
          {
            _S12_6 |= 1u;
            UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
            atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
          }
          if ( UFG::GameStatTracker::mspInstance )
            v7 = UFG::GameStatTracker::mspInstance;
          UFG::GameStatTracker::mspInstance = v7;
        }
        if ( !(*((_BYTE *)v8 + 6216) & 1) )
        {
          ++v8->mpSnapshots[0]->mInts[82].mValue;
          if ( UFG::GameStatAction::PostStat::sIsEnabled )
            UFG::GameStatAction::PostStat::AchieveInt(PorkBunsPurchased);
          if ( !(*((_BYTE *)v8 + 6216) & 1) )
          {
            ++v8->mpSnapshots[0]->mInts[83].mValue;
            if ( UFG::GameStatAction::PostStat::sIsEnabled )
              UFG::GameStatAction::PostStat::AchieveInt(FoodPurchased);
          }
        }
      }
      v16 = (UFG::qSymbol *)UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&origin, v4);
      UFG::GameStatTracker::SetStat(v8, FoodPurchasedBoolList, v16, 1);
      v17 = UFG::OSuiteLeaderboardManager::Instance();
      v18 = UFG::OSuiteLeaderboardManager::GetLeaderboardDataUsingLeaderboardName(v17, "StatAwardsBigSpender");
      UFG::DataSynchronizer::ApplyDeltaToGlobalSnapshot(v18, v3);
      UFG::OnlineEventManager::PostEvent(Vehicle, 1);
      return;
    case 0x13:
    case 0x14:
    case 0x15:
    case 0x16:
    case 0x17:
    case 0x18:
    case 0x19:
    case 0x1A:
    case 0x97:
      if ( !(*((_BYTE *)v8 + 6216) & 1) )
      {
        ++v8->mpSnapshots[0]->mInts[83].mValue;
        if ( UFG::GameStatAction::PostStat::sIsEnabled )
          UFG::GameStatAction::PostStat::AchieveInt(FoodPurchased);
      }
      v19 = (char *)&result;
      goto LABEL_47;
    case 0x1B:
      if ( !(*((_BYTE *)v8 + 6216) & 1) )
      {
        v8->mpSnapshots[0]->mInts[72].mValue += v3;
        if ( UFG::GameStatAction::PostStat::sIsEnabled )
          UFG::GameStatAction::PostStat::AchieveInt(CashSpentOnEnergyDrinks);
        if ( !(*((_BYTE *)v8 + 6216) & 1) )
        {
          ++v8->mpSnapshots[0]->mInts[79].mValue;
          if ( UFG::GameStatAction::PostStat::sIsEnabled )
            UFG::GameStatAction::PostStat::AchieveInt(EnergyDrinksPurchased);
        }
      }
      v19 = &v25;
      goto LABEL_47;
    case 0x1C:
    case 0x1D:
    case 0x1E:
      if ( !(*((_BYTE *)v8 + 6216) & 1) )
      {
        v8->mpSnapshots[0]->mInts[73].mValue += v3;
        if ( UFG::GameStatAction::PostStat::sIsEnabled )
          UFG::GameStatAction::PostStat::AchieveInt(CashSpentOnMassages);
        if ( !(*((_BYTE *)v8 + 6216) & 1) )
        {
          ++v8->mpSnapshots[0]->mInts[80].mValue;
          if ( UFG::GameStatAction::PostStat::sIsEnabled )
            UFG::GameStatAction::PostStat::AchieveInt(MassagesPurchased);
        }
      }
      goto LABEL_79;
    case 0x1F:
      if ( !(*((_BYTE *)v8 + 6216) & 1) )
      {
        v8->mpSnapshots[0]->mInts[74].mValue += v3;
        if ( UFG::GameStatAction::PostStat::sIsEnabled )
          UFG::GameStatAction::PostStat::AchieveInt(CashSpentOnHerbalTea);
        if ( !(*((_BYTE *)v8 + 6216) & 1) )
        {
          ++v8->mpSnapshots[0]->mInts[81].mValue;
          if ( UFG::GameStatAction::PostStat::sIsEnabled )
            UFG::GameStatAction::PostStat::AchieveInt(HerbalTeaPurchased);
        }
      }
      v19 = &v28;
LABEL_47:
      v20 = (UFG::qSymbol *)UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)v19, v4);
      UFG::GameStatTracker::SetStat(v8, FoodPurchasedBoolList, v20, 1);
      goto LABEL_79;
    case 0x54:
      if ( !(*((_BYTE *)v8 + 6216) & 1) )
      {
        v8->mpSnapshots[0]->mInts[76].mValue += v3;
        if ( UFG::GameStatAction::PostStat::sIsEnabled )
          UFG::GameStatAction::PostStat::AchieveInt(CashSpentOnTaxis);
      }
      goto LABEL_79;
    case 0x58:
    case 0x59:
      if ( !(*((_BYTE *)v8 + 6216) & 1) )
      {
        v8->mpSnapshots[0]->mInts[69].mValue += v3;
        if ( UFG::GameStatAction::PostStat::sIsEnabled )
          UFG::GameStatAction::PostStat::AchieveInt(CashSpentOnClothes);
      }
      v21 = UFG::OSuiteLeaderboardManager::Instance();
      v22 = UFG::OSuiteLeaderboardManager::GetLeaderboardDataUsingLeaderboardName(v21, "StatAwardsBigSpender");
      UFG::DataSynchronizer::ApplyDeltaToGlobalSnapshot(v22, v3);
      UFG::OnlineEventManager::PostEvent(NumEntityTypes, v3);
      break;
    case 0xA3:
    case 0xA4:
    case 0xA5:
    case 0xA6:
    case 0xA7:
    case 0xA8:
    case 0xA9:
    case 0xAA:
    case 0xAB:
    case 0xAC:
    case 0xAD:
    case 0xAE:
    case 0xAF:
    case 0xB0:
    case 0xB1:
    case 0xB2:
    case 0xB3:
    case 0xB4:
    case 0xB5:
    case 0xB6:
      if ( !(*((_BYTE *)v8 + 6216) & 1) )
      {
        v8->mpSnapshots[0]->mInts[77].mValue += v3;
        if ( UFG::GameStatAction::PostStat::sIsEnabled )
          UFG::GameStatAction::PostStat::AchieveInt(CashSpentOnSafehouseDecor);
      }
      UFG::GameStatTracker::SetStat(
        v8,
        Collectible_SafehouseItems,
        (UFG::qSymbol *)&UFG::InventoryItemEnumSymbols[v4].mUID,
        1);
LABEL_79:
      v23 = UFG::OSuiteLeaderboardManager::Instance();
      v24 = UFG::OSuiteLeaderboardManager::GetLeaderboardDataUsingLeaderboardName(v23, "StatAwardsBigSpender");
      UFG::DataSynchronizer::ApplyDeltaToGlobalSnapshot(v24, v3);
      break;
    default:
      return;
  }
}

// File Line: 2408
// RVA: 0x152BFF0
__int64 UFG::GameStatAction::_dynamic_initializer_for__clothingSymbol__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("Clothing", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::GameStatAction::clothingSymbol, v0);
  return atexit(UFG::GameStatAction::_dynamic_atexit_destructor_for__clothingSymbol__);
}

// File Line: 2409
// RVA: 0x1530520
__int64 UFG::GameStatAction::_dynamic_initializer_for__vehicleSymbol__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("Vehicle", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::GameStatAction::vehicleSymbol, v0);
  return atexit(UFG::GameStatAction::_dynamic_atexit_destructor_for__vehicleSymbol__);
}

// File Line: 2412
// RVA: 0x4B2E80
void __fastcall UFG::GameStatAction::Money::PurchaseItem(UFG::SimObject *pOrigin, UFG::StoreFront::InventoryType inventory, int cost)
{
  int v3; // esi
  UFG::StoreFront::InventoryType v4; // ebp
  UFG::SimObject *v5; // r14
  unsigned int v6; // er9
  UFG::GameStatTracker *v7; // rbx
  UFG::GameStatTracker *v8; // rdi
  UFG::GameStatTracker *v9; // rcx
  UFG::GameSnapshot *v10; // rax
  int v11; // er8
  int v12; // ebp
  UFG::GameSnapshot *v13; // rdx
  int v14; // ecx
  int v15; // eax
  UFG::qSymbol *v16; // rax
  UFG::qStaticSymbol *v17; // rdx
  UFG::OSuiteLeaderboardManager *v18; // rax
  UFG::OSuiteLeaderboardData *v19; // rax
  UFG::qSymbol origin; // [rsp+58h] [rbp+10h]

  v3 = cost;
  v4 = inventory;
  v5 = pOrigin;
  v6 = _S12_6;
  v7 = &sGameStatTracker;
  if ( !(_S12_6 & 1) )
  {
    _S12_6 |= 1u;
    UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
    atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
    v6 = _S12_6;
  }
  v8 = &sGameStatTracker;
  if ( UFG::GameStatTracker::mspInstance )
    v8 = UFG::GameStatTracker::mspInstance;
  UFG::GameStatTracker::mspInstance = v8;
  if ( !(*((_BYTE *)v8 + 6216) & 1) )
  {
    v8->mpSnapshots[0]->mInts[62].mValue -= v3;
    if ( UFG::GameStatAction::PostStat::sIsEnabled )
    {
      if ( !(v6 & 1) )
      {
        _S12_6 = v6 | 1;
        UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
        atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
        v6 = _S12_6;
      }
      v9 = &sGameStatTracker;
      if ( UFG::GameStatTracker::mspInstance )
        v9 = UFG::GameStatTracker::mspInstance;
      UFG::GameStatTracker::mspInstance = v9;
      v10 = v9->mpSnapshots[0];
      v11 = v10->mInts[62].mValue;
      if ( v10->mInts[63].mValue < v11 )
      {
        UFG::GameStatTracker::SetStat(v9, MostCashHeld, v11);
        v6 = _S12_6;
      }
    }
  }
  v12 = v4 - 61;
  if ( v12 )
  {
    if ( v12 != 1 )
      return;
    if ( !(*((_BYTE *)v8 + 6216) & 1) )
    {
      v8->mpSnapshots[0]->mInts[71].mValue += v3;
      if ( UFG::GameStatAction::PostStat::sIsEnabled )
      {
        if ( !(v6 & 1) )
        {
          _S12_6 = v6 | 1;
          UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
          atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
        }
        if ( UFG::GameStatTracker::mspInstance )
          v7 = UFG::GameStatTracker::mspInstance;
        UFG::GameStatTracker::mspInstance = v7;
      }
      if ( !(*((_BYTE *)v8 + 6216) & 1) )
      {
        v13 = v8->mpSnapshots[0];
        v14 = 0;
        if ( v13->mIntsRanged[1].mValue + 1 > 0 )
          v14 = v13->mIntsRanged[1].mValue + 1;
        v15 = v13->mIntsRanged[1].mRange;
        if ( v14 < v15 )
          v15 = v14;
        v13->mIntsRanged[1].mValue = v15;
      }
    }
    v16 = &v5->m_Name;
    if ( !v5 )
      v16 = &UFG::gNullQSymbol;
    v17 = &UFG::GameStatAction::vehicleSymbol;
  }
  else
  {
    if ( !(*((_BYTE *)v8 + 6216) & 1) )
    {
      v8->mpSnapshots[0]->mInts[69].mValue += v3;
      if ( UFG::GameStatAction::PostStat::sIsEnabled )
      {
        if ( !(v6 & 1) )
        {
          _S12_6 = v6 | 1;
          UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
          atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
        }
        if ( UFG::GameStatTracker::mspInstance )
          v7 = UFG::GameStatTracker::mspInstance;
        UFG::GameStatTracker::mspInstance = v7;
      }
    }
    UFG::OnlineEventManager::PostEvent(NumEntityTypes, v3);
    v16 = &v5->m_Name;
    if ( !v5 )
      v16 = &UFG::gNullQSymbol;
    v17 = &UFG::GameStatAction::clothingSymbol;
  }
  origin.mUID = v16->mUID;
  UFG::GameStatAction::Money::SendTransactionTelemetry(&origin, (UFG::qSymbol *)&v17->mUID, -v3);
  v18 = UFG::OSuiteLeaderboardManager::Instance();
  v19 = UFG::OSuiteLeaderboardManager::GetLeaderboardDataUsingLeaderboardName(v18, "StatAwardsBigSpender");
  UFG::DataSynchronizer::ApplyDeltaToGlobalSnapshot(v19, v3);
}

// File Line: 2441
// RVA: 0x49F850
void __fastcall UFG::GameStatAction::Money::Exchange(UFG::SimObject *pMerchant, int reason, int cost)
{
  int v3; // edi
  int v4; // esi
  unsigned int v5; // ecx
  UFG::GameStatTracker *v6; // rbx
  UFG::GameStatTracker *v7; // rdx
  UFG::GameStatTracker *v8; // rcx
  UFG::GameSnapshot *v9; // rax
  int v10; // er8
  UFG::GameStatTracker *v11; // rax
  UFG::GameStatTracker *v12; // rcx
  UFG::OSuiteLeaderboardManager *v13; // rax
  UFG::OSuiteLeaderboardData *v14; // rax
  UFG::GameStatTracker *v15; // rax
  UFG::GameStatTracker *v16; // rax
  int v17; // ebx
  int v18; // ebx
  UFG::OSuiteLeaderboardManager *v19; // rax
  UFG::OSuiteLeaderboardData *v20; // rax
  UFG::GameStatTracker *v21; // rax
  UFG::GameStatTracker *v22; // rax
  UFG::GameStatTracker *v23; // rax
  int v24; // esi
  UFG::GameStatTracker *v25; // rax
  UFG::GameStatTracker *v26; // rax
  unsigned int v27; // edx
  UFG::qWiseSymbol *v28; // rcx
  UFG::qSymbol *v29; // rbx
  UFG::GameStatTracker *v30; // rax
  UFG::GameStatTracker *v31; // rax
  UFG::OSuiteLeaderboardManager *v32; // rax
  UFG::OSuiteLeaderboardData *v33; // rax
  UFG::qWiseSymbol result; // [rsp+48h] [rbp+10h]
  char v35; // [rsp+50h] [rbp+18h]

  v3 = cost;
  v4 = reason;
  v5 = _S12_6;
  v6 = &sGameStatTracker;
  if ( !(_S12_6 & 1) )
  {
    _S12_6 |= 1u;
    UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
    atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
    v5 = _S12_6;
  }
  v7 = &sGameStatTracker;
  if ( UFG::GameStatTracker::mspInstance )
    v7 = UFG::GameStatTracker::mspInstance;
  UFG::GameStatTracker::mspInstance = v7;
  if ( !(*((_BYTE *)v7 + 6216) & 1) )
  {
    v7->mpSnapshots[0]->mInts[62].mValue += v3;
    if ( UFG::GameStatAction::PostStat::sIsEnabled )
    {
      if ( !(v5 & 1) )
      {
        _S12_6 = v5 | 1;
        UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
        atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
      }
      v8 = &sGameStatTracker;
      if ( UFG::GameStatTracker::mspInstance )
        v8 = UFG::GameStatTracker::mspInstance;
      UFG::GameStatTracker::mspInstance = v8;
      v9 = v8->mpSnapshots[0];
      v10 = v9->mInts[62].mValue;
      if ( v9->mInts[63].mValue < v10 )
        UFG::GameStatTracker::SetStat(v8, MostCashHeld, v10);
    }
  }
  if ( v3 > 0 )
  {
    v11 = UFG::GameStatTracker::Instance();
    if ( !(*((_BYTE *)v11 + 6216) & 1) )
    {
      v11->mpSnapshots[0]->mInts[61].mValue += v3;
      if ( UFG::GameStatAction::PostStat::sIsEnabled )
      {
        if ( !(_S12_6 & 1) )
        {
          _S12_6 |= 1u;
          UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
          atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
        }
        v12 = &sGameStatTracker;
        if ( UFG::GameStatTracker::mspInstance )
          v12 = UFG::GameStatTracker::mspInstance;
        UFG::GameStatTracker::mspInstance = v12;
      }
    }
    v13 = UFG::OSuiteLeaderboardManager::Instance();
    v14 = UFG::OSuiteLeaderboardManager::GetLeaderboardDataUsingLeaderboardName(v13, "StatAwardsMogul");
    UFG::DataSynchronizer::ApplyDeltaToGlobalSnapshot(v14, v3);
  }
  switch ( v4 )
  {
    case 1:
      if ( v3 <= 0 )
      {
        if ( v3 < 0 )
          v3 = -v3;
        v16 = UFG::GameStatTracker::Instance();
        UFG::GameStatTracker::ApplyDelta(v16, GamblingLoss, v3);
      }
      else
      {
        v15 = UFG::GameStatTracker::Instance();
        if ( !(*((_BYTE *)v15 + 6216) & 1) )
        {
          v15->mpSnapshots[0]->mInts[64].mValue += v3;
          if ( UFG::GameStatAction::PostStat::sIsEnabled )
          {
            if ( !(_S12_6 & 1) )
            {
              _S12_6 |= 1u;
              UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
              atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
            }
            if ( !UFG::GameStatTracker::mspInstance )
              UFG::GameStatTracker::mspInstance = &sGameStatTracker;
          }
        }
      }
      v17 = UFG::GameStatTracker::Instance()->mpSnapshots[0]->mInts[64].mValue;
      v18 = v17 - UFG::GameStatTracker::Instance()->mpSnapshots[0]->mInts[65].mValue;
      v19 = UFG::OSuiteLeaderboardManager::Instance();
      v20 = UFG::OSuiteLeaderboardManager::GetLeaderboardDataUsingLeaderboardName(v19, "StatAwardsGambler");
      UFG::DataSynchronizer::SetMaxToGlobalSnapshot(v20, v18);
      return;
    case 2:
      v21 = UFG::GameStatTracker::Instance();
      UFG::GameStatTracker::ApplyDelta(v21, BusDriverEarnings, v3);
      return;
    case 3:
      v22 = UFG::GameStatTracker::Instance();
      UFG::GameStatTracker::ApplyDelta(v22, LimoDriverEarnings, v3);
      return;
    case 4:
      v23 = UFG::GameStatTracker::Instance();
      UFG::GameStatTracker::ApplyDelta(v23, RepoEarnings, v3);
      return;
    case 8:
      v24 = v3;
      if ( v3 < 0 )
        v24 = -v3;
      v25 = UFG::GameStatTracker::Instance();
      UFG::GameStatTracker::ApplyDelta(v25, CashSpentOnEnergyDrinks, v24);
      v26 = UFG::GameStatTracker::Instance();
      if ( !(*((_BYTE *)v26 + 6216) & 1) )
      {
        ++v26->mpSnapshots[0]->mInts[79].mValue;
        if ( UFG::GameStatAction::PostStat::sIsEnabled )
        {
          if ( !(_S12_6 & 1) )
          {
            _S12_6 |= 1u;
            UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
            atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
          }
          if ( UFG::GameStatTracker::mspInstance )
            v6 = UFG::GameStatTracker::mspInstance;
          UFG::GameStatTracker::mspInstance = v6;
        }
      }
      v27 = 27;
      v28 = &result;
      goto LABEL_47;
    case 9:
    case 10:
      goto $LN2_36;
    case 11:
      v31 = UFG::GameStatTracker::Instance();
      UFG::GameStatTracker::ApplyDelta(v31, FoodPurchased, 1);
      v27 = 26;
      v28 = (UFG::qWiseSymbol *)&v35;
LABEL_47:
      v29 = (UFG::qSymbol *)UFG::qSymbol::qSymbol(v28, v27);
      v30 = UFG::GameStatTracker::Instance();
      UFG::GameStatTracker::SetStat(v30, FoodPurchasedBoolList, v29, 1);
$LN2_36:
      if ( v3 < 0 )
        v3 = -v3;
      v32 = UFG::OSuiteLeaderboardManager::Instance();
      v33 = UFG::OSuiteLeaderboardManager::GetLeaderboardDataUsingLeaderboardName(v32, "StatAwardsBigSpender");
      UFG::DataSynchronizer::ApplyDeltaToGlobalSnapshot(v33, v3);
      break;
    default:
      return;
  }
}

// File Line: 2553
// RVA: 0x4B97C0
void __fastcall UFG::GameStatAction::GameSliceAction::SendTelemetryStat(UFG::GameSlice *gameslice)
{
  UFG::GameSlice *v1; // rdi
  UFG::OSuiteDBLogger *v2; // rsi
  UFG::GameStatTracker *v3; // r14
  int v4; // ebx
  const char *v5; // rbx
  int v6; // ebx
  int v7; // ebx
  int v8; // ebx
  float v9; // xmm6_4
  float v10; // xmm6_4
  float v11; // xmm6_4
  float v12; // xmm6_4
  const char *v13; // rdx
  char *v14; // rbx
  float v15; // xmm6_4
  float v16; // xmm0_4
  UFG::SimpleTimer *v17; // rcx
  float v18; // xmm0_4
  float v19; // xmm0_4
  float v20; // xmm0_4
  UFG::GameStatTracker *v21; // rbx
  int v22; // ecx
  int v23; // ebx
  int v24; // edi
  int v25; // ebx
  int v26; // ebx
  int v27; // ebx
  int v28; // ebx
  UFG::NameValueColumnType *i; // rbx
  UFG::qNode<UFG::NameValueColumnType,UFG::NameValueColumnType> *v30; // rdx
  UFG::qNode<UFG::NameValueColumnType,UFG::NameValueColumnType> *v31; // rax
  __int64 *v32; // rcx
  UFG::NameValueColumnType *v33; // rax
  __int64 *v34; // [rsp+18h] [rbp-79h]
  UFG::NameValueColumnType *v35; // [rsp+20h] [rbp-71h]
  char dest; // [rsp+28h] [rbp-69h]
  UFG::qString v37; // [rsp+A8h] [rbp+17h]
  __int64 v38; // [rsp+D0h] [rbp+3Fh]

  v38 = -2i64;
  v1 = gameslice;
  v2 = UFG::OSuiteDBLogger::Instance();
  if ( UFG::OSuiteDBLogger::CreateMetric(v2, "MissionAttempt") )
  {
    v3 = UFG::GameStatTracker::Instance();
    v34 = (__int64 *)&v34;
    v35 = (UFG::NameValueColumnType *)&v34;
    v4 = v3->mpSnapshots[0]->mIDs[43].mValue.mUID;
    if ( v4 != -1 )
    {
      UFG::qSPrintf(&dest, 128, "i32_%s", "EventType");
      OSuite::ZMetric::SetProperty(v2->m_pMetric, &dest, v4);
    }
    v5 = v3->mpSnapshots[0]->mStrings[24].mValue.mData;
    UFG::qSPrintf(&dest, 128, "s_%s", "EventDesc");
    OSuite::ZMetric::SetProperty(v2->m_pMetric, &dest, v5);
    v6 = v3->mpSnapshots[0]->mIDs[32].mValue.mUID;
    if ( v6 != -1 )
    {
      UFG::qSPrintf(&dest, 128, "i32_%s", "KilledNameEnemy");
      OSuite::ZMetric::SetProperty(v2->m_pMetric, &dest, v6);
    }
    v7 = v3->mpSnapshots[0]->mIDs[33].mValue.mUID;
    if ( v7 != -1 )
    {
      UFG::qSPrintf(&dest, 128, "i32_%s", "KilledNameWeapon");
      OSuite::ZMetric::SetProperty(v2->m_pMetric, &dest, v7);
    }
    v8 = v3->mpSnapshots[0]->mIDs[34].mValue.mUID;
    if ( v8 != -1 )
    {
      UFG::qSPrintf(&dest, 128, "i32_%s", "PlayerWeaponName");
      OSuite::ZMetric::SetProperty(v2->m_pMetric, &dest, v8);
    }
    v9 = v3->mpSnapshots[0]->mFloats[135].mValue;
    UFG::qSPrintf(&dest, 128, "f_%s", "CopScore");
    OSuite::ZMetric::SetProperty(v2->m_pMetric, &dest, v9);
    v10 = v3->mpSnapshots[0]->mFloats[136].mValue;
    UFG::qSPrintf(&dest, 128, "f_%s", "TriadScore");
    OSuite::ZMetric::SetProperty(v2->m_pMetric, &dest, v10);
    v11 = v3->mpSnapshots[0]->mFloats[137].mValue;
    UFG::qSPrintf(&dest, 128, "f_%s", "RangedDamageReceived");
    OSuite::ZMetric::SetProperty(v2->m_pMetric, &dest, v11);
    v12 = v3->mpSnapshots[0]->mFloats[138].mValue;
    UFG::qSPrintf(&dest, 128, "f_%s", "MeleeDamageReceived");
    OSuite::ZMetric::SetProperty(v2->m_pMetric, &dest, v12);
    UFG::qString::qString(&v37);
    switch ( v1->mTrackType )
    {
      case 1:
        v13 = "Mission";
        goto LABEL_18;
      case 2:
        v13 = "Case";
        goto LABEL_18;
      case 3:
        v13 = "Event";
        goto LABEL_18;
      case 4:
        v13 = "Favour";
        goto LABEL_18;
      case 5:
        v13 = "Job";
        goto LABEL_18;
      case 6:
        v13 = "Date";
        goto LABEL_18;
      case 8:
        v13 = "DLC";
LABEL_18:
        UFG::qString::Format(&v37, v13);
        break;
      default:
        break;
    }
    v14 = v37.mData;
    UFG::qSPrintf(&dest, 128, "s_%s", "MissionType");
    OSuite::ZMetric::SetProperty(v2->m_pMetric, &dest, v14);
    v15 = UFG::SimpleTimer::GetElapsedSeconds(&v3->mpSnapshots[0]->mTimes[19].mTimer);
    UFG::qSPrintf(&dest, 128, "f_%s", "SandboxTime");
    OSuite::ZMetric::SetProperty(v2->m_pMetric, &dest, v15);
    v16 = UFG::SimpleTimer::GetElapsedSeconds(&v3->mpSnapshots[0]->mTimes[20].mTimer);
    UFG::qSPrintf(&dest, 128, "f_%s", "AttemptDuration");
    OSuite::ZMetric::SetProperty(v2->m_pMetric, &dest, v16);
    v17 = (UFG::SimpleTimer *)v3->mpSnapshots[0];
    if ( gCurrentTrackedMissionSlice == gCurrentMissionSlice )
    {
      v20 = UFG::SimpleTimer::GetElapsedSeconds(v17 + 21);
      UFG::qSPrintf(&dest, 128, "f_%s", "AccumulativeMissionDuration");
      OSuite::ZMetric::SetProperty(v2->m_pMetric, &dest, v20);
    }
    else
    {
      gCurrentTrackedMissionSlice = gCurrentMissionSlice;
      v18 = UFG::SimpleTimer::GetElapsedSeconds(v17 + 20);
      UFG::qSPrintf(&dest, 128, "f_%s", "AccumulativeMissionDuration");
      OSuite::ZMetric::SetProperty(v2->m_pMetric, &dest, v18);
      v19 = UFG::SimpleTimer::GetElapsedSeconds(&v3->mpSnapshots[0]->mTimes[20].mTimer);
      UFG::SimpleTimer::SetElapsedTime(&v3->mpSnapshots[0]->mTimes[21].mTimer, v19);
    }
    v21 = &sGameStatTracker;
    if ( !(_S12_6 & 1) )
    {
      _S12_6 |= 1u;
      UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
      atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
    }
    if ( UFG::GameStatTracker::mspInstance )
      v21 = UFG::GameStatTracker::mspInstance;
    UFG::GameStatTracker::mspInstance = v21;
    v22 = UFG::GameStatAction::MissionScoring::ms_CopStartingScore - v21->mpSnapshots[0]->mInts[155].mValue;
    v23 = 0;
    if ( v22 > 0 )
      v23 = v22;
    v24 = UFG::GameStatAction::MissionScoring::GetTriadScore(1);
    UFG::qSPrintf(&dest, 128, "i32_%s", "PoliceXP");
    OSuite::ZMetric::SetProperty(v2->m_pMetric, &dest, v23);
    UFG::qSPrintf(&dest, 128, "i32_%s", "TriadXP");
    OSuite::ZMetric::SetProperty(v2->m_pMetric, &dest, v24);
    v25 = v3->mpSnapshots[0]->mInts[158].mValue;
    UFG::qSPrintf(&dest, 128, "i32_%s", "MeleeKills");
    OSuite::ZMetric::SetProperty(v2->m_pMetric, &dest, v25);
    v26 = v3->mpSnapshots[0]->mInts[159].mValue;
    UFG::qSPrintf(&dest, 128, "i32_%s", "GunKills");
    OSuite::ZMetric::SetProperty(v2->m_pMetric, &dest, v26);
    v27 = v3->mpSnapshots[0]->mInts[160].mValue;
    UFG::qSPrintf(&dest, 128, "i32_%s", "MeleeWeaponKills");
    OSuite::ZMetric::SetProperty(v2->m_pMetric, &dest, v27);
    v28 = v3->mpSnapshots[0]->mInts[161].mValue;
    UFG::qSPrintf(&dest, 128, "i32_%s", "DLCWeaponKills");
    OSuite::ZMetric::SetProperty(v2->m_pMetric, &dest, v28);
    UFG::OSuiteDBLogger::SubmitMetric(v2, 1);
    UFG::qString::~qString(&v37);
    for ( i = v35; v35 != (UFG::NameValueColumnType *)&v34; i = v35 )
    {
      v30 = i->mPrev;
      v31 = i->mNext;
      v30->mNext = v31;
      v31->mPrev = v30;
      i->mPrev = (UFG::qNode<UFG::NameValueColumnType,UFG::NameValueColumnType> *)&i->mPrev;
      i->mNext = (UFG::qNode<UFG::NameValueColumnType,UFG::NameValueColumnType> *)&i->mPrev;
      UFG::NameValueColumnType::~NameValueColumnType(i);
      operator delete[](i);
    }
    v32 = v34;
    v33 = v35;
    v34[1] = (__int64)v35;
    v33->mPrev = (UFG::qNode<UFG::NameValueColumnType,UFG::NameValueColumnType> *)v32;
  }
}

// File Line: 2654
// RVA: 0x4BF040
void __fastcall UFG::GameStatAction::GameSliceAction::Start(UFG::GameSlice *gameslice)
{
  UFG::GameSlice *v1; // rsi
  int v2; // eax
  char v3; // dl
  UFG::GameStatTracker *v4; // rdi
  UFG::GameStatTracker *v5; // rbx
  float v6; // xmm0_4
  int v7; // ecx
  UFG::SimpleTimer *v8; // rbx
  UFG::qWiseSymbol *v9; // rax
  UFG::qWiseSymbol *v10; // rax
  UFG::qString v11; // [rsp+38h] [rbp-40h]
  UFG::qWiseSymbol result; // [rsp+80h] [rbp+8h]

  v1 = gameslice;
  if ( !gameslice->mTrackType )
    return;
  v2 = UFG::qStringCompareInsensitive(gameslice->mName.mText, "M_WTHK", -1);
  v3 = UFG::GameStatAction::gIgnoreMissionKillsInWTHK;
  if ( !v2 )
    v3 = 1;
  UFG::GameStatAction::gIgnoreMissionKillsInWTHK = v3;
  v4 = UFG::GameStatTracker::Instance();
  switch ( v1->mTrackType )
  {
    case 1:
      if ( !(*((_BYTE *)v4 + 6216) & 1) )
      {
        ++v4->mpSnapshots[0]->mInts[49].mValue;
        if ( UFG::GameStatAction::PostStat::sIsEnabled )
          UFG::GameStatAction::PostStat::AchieveInt(MissionsAttmpted);
      }
      UFG::SimpleTimer::Stop(&v4->mpSnapshots[0]->mTimes[18].mTimer);
      v6 = UFG::SimpleTimer::GetElapsedSeconds(&v4->mpSnapshots[0]->mTimes[18].mTimer);
      UFG::GameStatTracker::ApplyDelta(v4, TotalTimeBetweenMissions, v6);
      UFG::GameStatTracker::SetStatHigh(v4, LongestTimeBetweenMissions, v6);
      UFG::SimpleTimer::Resume(&v4->mpSnapshots[0]->mTimes[3].mTimer);
      UFG::GameStatAction::mTick_Mission_Start = UFG::qGetTicks();
      break;
    case 2:
      if ( !(*((_BYTE *)v4 + 6216) & 1) )
      {
        ++v4->mpSnapshots[0]->mInts[55].mValue;
        if ( UFG::GameStatAction::PostStat::sIsEnabled )
        {
          v5 = &sGameStatTracker;
          if ( !(_S12_6 & 1) )
          {
            _S12_6 |= 1u;
            UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
            atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
          }
          if ( UFG::GameStatTracker::mspInstance )
            v5 = UFG::GameStatTracker::mspInstance;
          UFG::GameStatTracker::mspInstance = v5;
        }
      }
      UFG::GameStatAction::mTick_Case_Start = UFG::qGetTicks();
      break;
    case 3:
      if ( !(*((_BYTE *)v4 + 6216) & 1) )
      {
        ++v4->mpSnapshots[0]->mInts[51].mValue;
        if ( UFG::GameStatAction::PostStat::sIsEnabled )
        {
          if ( !(_S12_6 & 1) )
          {
            _S12_6 |= 1u;
            UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
            atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
          }
          goto LABEL_21;
        }
      }
      break;
    case 4:
      if ( !(*((_BYTE *)v4 + 6216) & 1) )
      {
        ++v4->mpSnapshots[0]->mInts[53].mValue;
        if ( UFG::GameStatAction::PostStat::sIsEnabled )
        {
          if ( !(_S12_6 & 1) )
          {
            _S12_6 |= 1u;
            UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
            atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
          }
          goto LABEL_21;
        }
      }
      break;
    default:
      if ( v1->mTrackType == 6 && !(*((_BYTE *)v4 + 6216) & 1) )
      {
        ++v4->mpSnapshots[0]->mInts[57].mValue;
        if ( UFG::GameStatAction::PostStat::sIsEnabled )
        {
          if ( !(_S12_6 & 1) )
          {
            _S12_6 |= 1u;
            UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
            atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
          }
LABEL_21:
          if ( !UFG::GameStatTracker::mspInstance )
            UFG::GameStatTracker::mspInstance = &sGameStatTracker;
          break;
        }
      }
      break;
  }
  v7 = (unsigned __int8)v1->mTrackType;
  if ( !((v7 - 1) & 0xFFFFFFF8) && v7 != 7 )
  {
    UFG::SimpleTimer::Stop(&v4->mpSnapshots[0]->mTimes[19].mTimer);
    v8 = (UFG::SimpleTimer *)v4->mpSnapshots[0];
    UFG::SimpleTimer::SetElapsedTime(v8 + 20, 0.0);
    UFG::SimpleTimer::Start(v8 + 20);
    UFG::SimpleTimer::Resume(&v4->mpSnapshots[0]->mTimes[21].mTimer);
    UFG::GameStatTracker::SetStat(v4, MissionMeleeKills, 0);
    UFG::GameStatTracker::SetStat(v4, MissionGunKills, 0);
    UFG::GameStatTracker::SetStat(v4, MissionMeleeWeaponKills, 0);
    UFG::GameStatTracker::SetStat(v4, MissionDLCWeaponKills, 0);
    gCurrentMissionSlice = v1->mNode.mUID;
    v9 = UFG::qSymbol::qSymbol(&result, 0x62D86D56u);
    if ( !(*((_BYTE *)v4 + 6216) & 1) )
      v4->mpSnapshots[0]->mIDs[43].mValue.mUID = v9->mUID;
    UFG::qString::qString(&v11, &customWorldMapCaption);
    if ( !(*((_BYTE *)v4 + 6216) & 1) )
      UFG::qString::Set(&v4->mpSnapshots[0]->mStrings[24].mValue, v11.mData, v11.mLength, 0i64, 0);
    UFG::qString::~qString(&v11);
    if ( !(*((_BYTE *)v4 + 6216) & 1) )
    {
      v4->mpSnapshots[0]->mIDs[32].mValue = UFG::gNullQSymbol;
      if ( !(*((_BYTE *)v4 + 6216) & 1) )
      {
        v4->mpSnapshots[0]->mIDs[33].mValue = UFG::gNullQSymbol;
        if ( !(*((_BYTE *)v4 + 6216) & 1) )
        {
          v4->mpSnapshots[0]->mIDs[34].mValue = UFG::gNullQSymbol;
          if ( !(*((_BYTE *)v4 + 6216) & 1) )
          {
            v4->mpSnapshots[0]->mFloats[132].mValue = -10000.0;
            if ( !(*((_BYTE *)v4 + 6216) & 1) )
            {
              v4->mpSnapshots[0]->mFloats[133].mValue = -10000.0;
              if ( !(*((_BYTE *)v4 + 6216) & 1) )
              {
                v4->mpSnapshots[0]->mFloats[134].mValue = -10000.0;
                if ( !(*((_BYTE *)v4 + 6216) & 1) )
                {
                  v4->mpSnapshots[0]->mFloats[135].mValue = -1.0;
                  if ( !(*((_BYTE *)v4 + 6216) & 1) )
                  {
                    v4->mpSnapshots[0]->mFloats[136].mValue = -1.0;
                    if ( !(*((_BYTE *)v4 + 6216) & 1) )
                    {
                      v4->mpSnapshots[0]->mFloats[137].mValue = 0.0;
                      if ( !(*((_BYTE *)v4 + 6216) & 1) )
                        v4->mpSnapshots[0]->mFloats[138].mValue = 0.0;
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
    UFG::GameStatAction::GameSliceAction::SendTelemetryStat(v1);
    v10 = UFG::qSymbol::qSymbol(&result, 0xEF305CE5);
    if ( !(*((_BYTE *)v4 + 6216) & 1) )
      v4->mpSnapshots[0]->mIDs[43].mValue.mUID = v10->mUID;
    UFG::qString::qString(&v11, "Not applicable.");
    if ( !(*((_BYTE *)v4 + 6216) & 1) )
      UFG::qString::Set(&v4->mpSnapshots[0]->mStrings[24].mValue, v11.mData, v11.mLength, 0i64, 0);
    UFG::qString::~qString(&v11);
  }
}

// File Line: 2761
// RVA: 0x4C10B0
void __usercall UFG::GameStatAction::GameSliceAction::Stop(UFG::GameSlice *gameslice@<rcx>, bool success@<dl>, __int64 a3@<rbx>, __int64 a4@<rbp>, __int64 a5@<rdi>, __int64 a6@<rsi>, __int128 a7@<xmm6>)
{
  bool v7; // bl
  UFG::GameSlice *v8; // rsi
  int v9; // eax
  bool v10; // r8
  UFG::GameStatTracker *v11; // rdi
  UFG::GameStatTracker *v12; // rax
  UFG::GameSnapshot *v13; // r9
  UFG::PersistentData::MapBool *v14; // rdx
  UFG::PersistentData::MapBool::KeepType v15; // ecx
  signed int v16; // eax
  float v17; // xmm0_4
  signed int v18; // ecx
  unsigned int v19; // er8
  $CCFB32CF948EEB04FF452B3FEB4ECF53 *v20; // rax
  __int64 v21; // rdx
  float v22; // xmm1_4
  unsigned __int64 v23; // rax
  UFG::GameStatTracker *v24; // rax
  float v25; // xmm0_4
  __int128 v26; // xmm0
  UFG::PersistentData::MapBool *v27; // rdx
  UFG::PersistentData::MapBool::KeepType v28; // ecx
  unsigned int v29; // er9
  unsigned int v30; // ecx
  unsigned int v31; // er8
  $CCFB32CF948EEB04FF452B3FEB4ECF53 *v32; // rax
  __int64 v33; // rdx
  unsigned __int64 v34; // rax
  UFG::GameStatTracker *v35; // rax
  UFG::GameStatTracker *v36; // rax
  UFG::PersistentData::MapBool *v37; // rbx
  UFG::PersistentData::MapBool::KeepType v38; // ecx
  unsigned int v39; // er8
  unsigned int v40; // ecx
  __int64 v41; // rdx
  $CCFB32CF948EEB04FF452B3FEB4ECF53 *v42; // rax
  UFG::PersistentData::MapBool::KeepType v43; // er8
  unsigned int v44; // ecx
  __int64 v45; // rdx
  $CCFB32CF948EEB04FF452B3FEB4ECF53 *v46; // rax
  unsigned int v47; // er8
  UFG::GameStatTracker *v48; // rax
  UFG::PersistentData::MapBool *v49; // rbx
  UFG::PersistentData::MapBool::KeepType v50; // ecx
  unsigned int v51; // er8
  unsigned int v52; // ecx
  __int64 v53; // rdx
  $CCFB32CF948EEB04FF452B3FEB4ECF53 *v54; // rax
  UFG::GameStatTracker *v55; // rax
  UFG::PersistentData::MapBool *v56; // rdx
  UFG::PersistentData::MapBool::KeepType v57; // ecx
  unsigned int v58; // er9
  unsigned int v59; // ecx
  unsigned int v60; // er8
  $CCFB32CF948EEB04FF452B3FEB4ECF53 *v61; // rax
  __int64 v62; // rdx
  UFG::GameStatTracker *v63; // rax
  UFG::GameStat::MapBoolStat v64; // edx
  int v65; // ecx
  UFG::SimpleTimer *v66; // rbx
  UFG::qWiseSymbol *v67; // rax
  float v68; // xmm0_4
  __int128 v69; // xmm0
  UFG::ProgressionTracker *v70; // rax
  float v71; // xmm6_4
  UFG::OSuiteLeaderboardManager *v72; // rax
  UFG::OSuiteLeaderboardData *v73; // rax
  UFG::GameStat::Int32Stat v74; // edx
  int v75; // ecx
  UFG::qString v76; // [rsp+38h] [rbp-40h]
  __int128 v77; // [rsp+60h] [rbp-18h]
  __int64 v78; // [rsp+70h] [rbp-8h]
  UFG::qWiseSymbol result; // [rsp+80h] [rbp+8h]
  __int64 v80; // [rsp+88h] [rbp+10h]
  __int64 v81; // [rsp+90h] [rbp+18h]
  __int64 v82; // [rsp+98h] [rbp+20h]

  v78 = a5;
  v80 = a3;
  v81 = a4;
  v82 = a6;
  v77 = a7;
  v7 = success;
  v8 = gameslice;
  if ( gameslice->mTrackType )
  {
    v9 = UFG::qStringCompareInsensitive(gameslice->mName.mText, "M_WTHK", -1);
    v10 = UFG::GameStatAction::gIgnoreMissionKillsInWTHK;
    if ( !v9 )
      v10 = 0;
    UFG::GameStatAction::gIgnoreMissionKillsInWTHK = v10;
    v11 = UFG::GameStatTracker::Instance();
    if ( v7 )
    {
      switch ( v8->mTrackType )
      {
        case 1:
          v12 = UFG::GameStatTracker::Instance();
          UFG::GameStatTracker::SetStat(v12, MissionsCompleted, (UFG::qSymbol *)&v8->mNode.mUID, 1);
          UFG::SimpleTimer::Resume(&v11->mpSnapshots[0]->mTimes[18].mTimer);
          UFG::SimpleTimer::Stop(&v11->mpSnapshots[0]->mTimes[3].mTimer);
          v13 = v11->mpSnapshots[0];
          v14 = v13->mpMapBools[66];
          v15 = v14->mKeepType;
          if ( v14->mKeepType )
          {
            if ( (unsigned int)(v15 - 1) > 1 )
              v16 = 0;
            else
              v16 = v14->mNames.size;
          }
          else
          {
            v16 = v14->mValues.size;
          }
          v17 = (float)v16;
          if ( v15 == 2 )
          {
            v18 = 0;
          }
          else if ( v15 == 1 )
          {
            v18 = v14->mNames.size;
          }
          else
          {
            v18 = 0;
            v19 = v14->mValues.size;
            if ( v19 )
            {
              v20 = &v14->mValues.p->4;
              v21 = v19;
              do
              {
                if ( LOBYTE(v20->mFloatValue) )
                  ++v18;
                v20 += 2;
                --v21;
              }
              while ( v21 );
            }
          }
          v22 = *(float *)&FLOAT_1_0;
          if ( v17 >= 1.0 )
            v22 = v17;
          if ( !(*((_BYTE *)v11 + 6216) & 1) )
            v13->mFloats[118].mValue = (float)((float)v18 * 100.0) / v22;
          v23 = UFG::qGetTicks();
          UFG::qGetTickTime(UFG::GameStatAction::mTick_Mission_Start, v23);
          break;
        case 2:
          v24 = UFG::GameStatTracker::Instance();
          UFG::GameStatTracker::SetStat(v24, CasesCompleted, (UFG::qSymbol *)&v8->mNode.mUID, 1);
          v25 = (float)(signed int)UFG::GameStatAction::MissionScoring::GetCopScore(1);
          if ( !(*((_BYTE *)v11 + 6216) & 1) )
            v11->mpSnapshots[0]->mFloats[135].mValue = v25;
          v26 = COERCE_UNSIGNED_INT((float)(signed int)UFG::GameStatAction::MissionScoring::GetTriadScore(1));
          if ( !(*((_BYTE *)v11 + 6216) & 1) )
            LODWORD(v11->mpSnapshots[0]->mFloats[136].mValue) = v26;
          v27 = UFG::GameStatTracker::Instance()->mpSnapshots[0]->mpMapBools[69];
          v28 = v27->mKeepType;
          if ( v27->mKeepType )
          {
            if ( (unsigned int)(v28 - 1) > 1 )
              v29 = 0;
            else
              v29 = v27->mNames.size;
          }
          else
          {
            v29 = v27->mValues.size;
          }
          if ( v28 == 2 )
          {
            v30 = 0;
          }
          else if ( v28 == 1 )
          {
            v30 = v27->mNames.size;
          }
          else
          {
            v30 = 0;
            v31 = v27->mValues.size;
            if ( v31 )
            {
              v32 = &v27->mValues.p->4;
              v33 = v31;
              do
              {
                if ( LOBYTE(v32->mFloatValue) )
                  ++v30;
                v32 += 2;
                --v33;
              }
              while ( v33 );
            }
          }
          if ( v29 == v30 )
            UFG::AchievementTrophyManager::UnlockAchievementTrophy(23);
          v34 = UFG::qGetTicks();
          UFG::qGetTickTime(UFG::GameStatAction::mTick_Case_Start, v34);
          break;
        case 3:
          v36 = UFG::GameStatTracker::Instance();
          UFG::GameStatTracker::SetStat(v36, EventsCompleted, (UFG::qSymbol *)&v8->mNode.mUID, 1);
          v37 = UFG::GameStatTracker::Instance()->mpSnapshots[0]->mpMapBools[67];
          if ( UFG::ProgressionTracker::Instance()->mActiveFlowId.mUID == gDefaultFlowId.mUID )
          {
            v38 = v37->mKeepType;
            if ( v37->mKeepType )
            {
              if ( (unsigned int)(v38 - 1) > 1 )
                v39 = 0;
              else
                v39 = v37->mNames.size;
            }
            else
            {
              v39 = v37->mValues.size;
            }
            if ( v38 == 2 )
            {
              v40 = 0;
            }
            else if ( v38 == 1 )
            {
              v40 = v37->mNames.size;
            }
            else
            {
              v40 = 0;
              v41 = v37->mValues.size;
              if ( (_DWORD)v41 )
              {
                v42 = &v37->mValues.p->4;
                do
                {
                  if ( LOBYTE(v42->mFloatValue) )
                    ++v40;
                  v42 += 2;
                  --v41;
                }
                while ( v41 );
              }
            }
            if ( v39 == v40 )
              UFG::AchievementTrophyManager::UnlockAchievementTrophy(26);
            v43 = v37->mKeepType;
            if ( v37->mKeepType == 2 )
            {
              v44 = 0;
            }
            else if ( v43 == 1 )
            {
              v44 = v37->mNames.size;
            }
            else
            {
              v44 = 0;
              v45 = v37->mValues.size;
              if ( (_DWORD)v45 )
              {
                v46 = &v37->mValues.p->4;
                do
                {
                  if ( LOBYTE(v46->mFloatValue) )
                    ++v44;
                  v46 += 2;
                  --v45;
                }
                while ( v45 );
              }
            }
            if ( v43 )
            {
              if ( (unsigned int)(v43 - 1) > 1 )
                v47 = 0;
              else
                v47 = v37->mNames.size;
            }
            else
            {
              v47 = v37->mValues.size;
            }
            if ( 100 * v44 / v47 > 0x31 )
              UFG::AchievementTrophyManager::UnlockAchievementTrophy(25);
          }
          break;
        case 4:
          v48 = UFG::GameStatTracker::Instance();
          UFG::GameStatTracker::SetStat(v48, FavoursCompleted, (UFG::qSymbol *)&v8->mNode.mUID, 1);
          v49 = UFG::GameStatTracker::Instance()->mpSnapshots[0]->mpMapBools[68];
          if ( UFG::ProgressionTracker::Instance()->mActiveFlowId.mUID == gDefaultFlowId.mUID )
          {
            v50 = v49->mKeepType;
            if ( v49->mKeepType )
            {
              if ( (unsigned int)(v50 - 1) > 1 )
                v51 = 0;
              else
                v51 = v49->mNames.size;
            }
            else
            {
              v51 = v49->mValues.size;
            }
            if ( v50 == 2 )
            {
              v52 = 0;
            }
            else if ( v50 == 1 )
            {
              v52 = v49->mNames.size;
            }
            else
            {
              v52 = 0;
              v53 = v49->mValues.size;
              if ( (_DWORD)v53 )
              {
                v54 = &v49->mValues.p->4;
                do
                {
                  if ( LOBYTE(v54->mFloatValue) )
                    ++v52;
                  v54 += 2;
                  --v53;
                }
                while ( v53 );
              }
            }
            if ( v51 == v52 )
              UFG::AchievementTrophyManager::UnlockAchievementTrophy(24);
          }
          break;
        case 5:
          v63 = UFG::GameStatTracker::Instance();
          v64 = 72;
          goto LABEL_115;
        case 6:
          v35 = UFG::GameStatTracker::Instance();
          UFG::GameStatTracker::SetStat(v35, DatesCompleted, (UFG::qSymbol *)&v8->mNode.mUID, 1);
          UFG::GameStatTracker::Instance();
          break;
        case 7:
          v55 = UFG::GameStatTracker::Instance();
          UFG::GameStatTracker::SetStat(v55, StreetRacesCompletedWon, (UFG::qSymbol *)&v8->mNode.mUID, 1);
          v56 = UFG::GameStatTracker::Instance()->mpSnapshots[0]->mpMapBools[71];
          v57 = v56->mKeepType;
          if ( v56->mKeepType )
          {
            if ( (unsigned int)(v57 - 1) > 1 )
              v58 = 0;
            else
              v58 = v56->mNames.size;
          }
          else
          {
            v58 = v56->mValues.size;
          }
          if ( v57 == 2 )
          {
            v59 = 0;
          }
          else if ( v57 == 1 )
          {
            v59 = v56->mNames.size;
          }
          else
          {
            v59 = 0;
            v60 = v56->mValues.size;
            if ( v60 )
            {
              v61 = &v56->mValues.p->4;
              v62 = v60;
              do
              {
                if ( LOBYTE(v61->mFloatValue) )
                  ++v59;
                v61 += 2;
                --v62;
              }
              while ( v62 );
            }
          }
          if ( v58 == v59 )
            UFG::AchievementTrophyManager::UnlockAchievementTrophy(28);
          break;
        case 8:
          v63 = UFG::GameStatTracker::Instance();
          v64 = 73;
LABEL_115:
          UFG::GameStatTracker::SetStat(v63, v64, (UFG::qSymbol *)&v8->mNode.mUID, 1);
          break;
        default:
          break;
      }
      v65 = (unsigned __int8)v8->mTrackType;
      if ( !((v65 - 1) & 0xFFFFFFF8) && v65 != 7 || (_BYTE)v65 == 7 )
      {
        if ( !((v65 - 1) & 0xFFFFFFF8) && v65 != 7 )
        {
          v66 = (UFG::SimpleTimer *)v11->mpSnapshots[0];
          UFG::SimpleTimer::SetElapsedTime(v66 + 19, 0.0);
          UFG::SimpleTimer::Start(v66 + 19);
          UFG::SimpleTimer::Stop(&v11->mpSnapshots[0]->mTimes[20].mTimer);
          UFG::SimpleTimer::Stop(&v11->mpSnapshots[0]->mTimes[21].mTimer);
          v67 = UFG::qSymbol::qSymbol(&result, 0xFC1C7189);
          if ( !(*((_BYTE *)v11 + 6216) & 1) )
            v11->mpSnapshots[0]->mIDs[43].mValue.mUID = v67->mUID;
          UFG::qString::qString(&v76, &customWorldMapCaption);
          if ( !(*((_BYTE *)v11 + 6216) & 1) )
            UFG::qString::Set(&v11->mpSnapshots[0]->mStrings[24].mValue, v76.mData, v76.mLength, 0i64, 0);
          UFG::qString::~qString(&v76);
          v68 = (float)(signed int)UFG::GameStatAction::MissionScoring::GetCopScore(1);
          if ( !(*((_BYTE *)v11 + 6216) & 1) )
            v11->mpSnapshots[0]->mFloats[135].mValue = v68;
          v69 = COERCE_UNSIGNED_INT((float)(signed int)UFG::GameStatAction::MissionScoring::GetTriadScore(1));
          if ( !(*((_BYTE *)v11 + 6216) & 1) )
            LODWORD(v11->mpSnapshots[0]->mFloats[136].mValue) = v69;
          UFG::GameStatAction::GameSliceAction::SendTelemetryStat(v8);
        }
        v70 = UFG::ProgressionTracker::Instance();
        v71 = UFG::ProgressionTracker::UpdateCompletionPercentage(v70);
        v72 = UFG::OSuiteLeaderboardManager::Instance();
        v73 = UFG::OSuiteLeaderboardManager::GetLeaderboardDataUsingLeaderboardName(v72, "StatAwardsCompletionist");
        UFG::DataSynchronizer::SetMaxToGlobalSnapshot(v73, v71);
        if ( UFG::ProgressionTracker::Instance()->mActiveFlowId.mUID == gDefaultFlowId.mUID )
        {
          if ( v71 >= 10.0 )
            UFG::AchievementTrophyManager::UnlockAchievementTrophy(47);
          if ( v71 >= 25.0 )
            UFG::AchievementTrophyManager::UnlockAchievementTrophy(48);
          if ( v71 >= 50.0 )
            UFG::AchievementTrophyManager::UnlockAchievementTrophy(49);
          if ( v71 >= 100.0 )
            UFG::AchievementTrophyManager::UnlockAchievementTrophy(50);
        }
      }
    }
    else
    {
      switch ( v8->mTrackType )
      {
        case 1:
          v74 = 50;
          goto LABEL_146;
        case 2:
          v74 = 56;
          goto LABEL_146;
        case 3:
          v74 = 52;
          goto LABEL_146;
        case 4:
          v74 = 54;
          goto LABEL_146;
        case 6:
          v74 = 58;
          goto LABEL_146;
        case 7:
          v74 = 59;
LABEL_146:
          UFG::GameStatTracker::ApplyDelta(v11, v74, 1);
          break;
        default:
          break;
      }
      v75 = (unsigned __int8)v8->mTrackType;
      if ( !((v75 - 1) & 0xFFFFFFF8) && v75 != 7 )
        UFG::GameStatAction::GameSliceAction::SendTelemetryStat(v8);
    }
  }
}

// File Line: 2958
// RVA: 0x4B2C20
void __fastcall UFG::GameStatAction::GameSliceAction::PublishProgression(UFG::GameSlice *pSlice)
{
  UFG::GameSlice *v1; // rbx
  bool v2; // di
  UFG::GameStatTracker *v3; // rax
  UFG::GameStat::MapBoolStat v4; // edx

  v1 = pSlice;
  v2 = pSlice->mState == 8 || pSlice->mCompletionCount > 0;
  switch ( pSlice->mTrackType )
  {
    case 1:
      v3 = UFG::GameStatTracker::Instance();
      v4 = 66;
      goto LABEL_14;
    case 2:
      v3 = UFG::GameStatTracker::Instance();
      v4 = 69;
      goto LABEL_14;
    case 3:
      v3 = UFG::GameStatTracker::Instance();
      v4 = 67;
      goto LABEL_14;
    case 4:
      v3 = UFG::GameStatTracker::Instance();
      v4 = 68;
      goto LABEL_14;
    case 5:
      v3 = UFG::GameStatTracker::Instance();
      v4 = 72;
      goto LABEL_14;
    case 6:
      v3 = UFG::GameStatTracker::Instance();
      v4 = 70;
      goto LABEL_14;
    case 7:
      v3 = UFG::GameStatTracker::Instance();
      v4 = 71;
      goto LABEL_14;
    case 8:
      v3 = UFG::GameStatTracker::Instance();
      v4 = 73;
LABEL_14:
      UFG::GameStatTracker::SetStat(v3, v4, (UFG::qSymbol *)&v1->mNode.mUID, v2);
      break;
    default:
      return;
  }
}

// File Line: 3037
// RVA: 0x4ABDC0
char __fastcall UFG::GameStatAction::GameSliceAction::IsCompleted(__int64 symGameSliceName)
{
  unsigned int *v1; // rbx
  UFG::qBaseTreeRB *v2; // rax
  char v3; // al
  UFG::qSymbol *v4; // rbx
  UFG::qBaseTreeRB *v5; // rax
  UFG::qSymbol result; // [rsp+48h] [rbp+10h]

  v1 = (unsigned int *)symGameSliceName;
  if ( !(_S19_1 & 1) )
  {
    _S19_1 |= 1u;
    UFG::ProgressionTracker::ProgressionTracker(&sProgressionTracker);
    atexit(UFG::ProgressionTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sProgressionTracker__);
  }
  UFG::ProgressionTracker::mspInstance = &sProgressionTracker;
  if ( *v1 && (v2 = UFG::qBaseTreeRB::Get(&stru_14240A100, *v1)) != 0i64
    || (*v1 ? (v2 = UFG::qBaseTreeRB::Get(&stru_14240A148, *v1)) : (v2 = 0i64), v2) )
  {
    if ( LODWORD(v2[3].mNULL.mChild[1]) == 8 || SWORD2(v2[5].mRoot.mParent) > 0 )
      goto LABEL_26;
  }
  if ( *v1 != gMissionSymbol_M_VE.mUID )
    goto LABEL_27;
  if ( !(_S19_1 & 1) )
  {
    _S19_1 |= 1u;
    UFG::ProgressionTracker::ProgressionTracker(&sProgressionTracker);
    atexit(UFG::ProgressionTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sProgressionTracker__);
  }
  if ( ((UFG::ProgressionTracker::mspInstance = &sProgressionTracker,
         v4 = UFG::qSymbol::create_from_string(&result, "VE2g"),
         v4->mUID)
     && (v5 = UFG::qBaseTreeRB::Get(&stru_14240A100, v4->mUID)) != 0i64
     || (v4->mUID ? (v5 = UFG::qBaseTreeRB::Get(&stru_14240A148, v4->mUID)) : (v5 = 0i64), v5))
    && (LODWORD(v5[3].mNULL.mChild[1]) == 8 || SWORD2(v5[5].mRoot.mParent) > 0) )
  {
LABEL_26:
    v3 = 1;
  }
  else
  {
LABEL_27:
    v3 = 0;
  }
  return v3;
}

// File Line: 3065
// RVA: 0x4AAB40
void __fastcall UFG::GameStatAction::Snapshot::Initialize(float a1)
{
  UFG::UIAmbientMapBlipManager *v1; // rax
  int v2; // er14
  int v3; // esi
  UFG::UIAmbientMapBlipManager *v4; // rax
  UFG::UIAmbientMapBlipData *v5; // rax
  UFG::UIAmbientMapBlipData *v6; // rbx
  unsigned int v7; // eax
  UFG::PersistentData::MapBool *v8; // r9
  __int64 v9; // rdx
  unsigned int v10; // er8
  UFG::qSymbol *v11; // r9
  bool v12; // al
  __int64 v13; // rdx
  unsigned int v14; // er8
  UFG::qSymbol *v15; // r9
  unsigned int v16; // er8
  __int64 v17; // rdx
  UFG::PersistentData::KeyValue *v18; // rcx
  UFG::GameStatTracker *v19; // rax
  unsigned int v20; // edx
  UFG::GameStatTracker *v21; // r8
  UFG::PersistentData::MapBool *v22; // rax
  unsigned int v23; // ebx
  __int64 v24; // rcx
  $CCFB32CF948EEB04FF452B3FEB4ECF53 *v25; // rax
  UFG::GameStatTracker *v26; // rax
  UFG::PersistentData::MapBool *v27; // rcx
  unsigned int v28; // eax
  UFG::UIAmbientMapBlipData::eZoneInfo v29; // ecx
  int v30; // ecx
  int v31; // ecx
  signed __int64 v32; // rdi
  UFG::PersistentData::MapBool *v33; // r9
  __int64 v34; // rdx
  unsigned int v35; // er8
  UFG::qSymbol *v36; // r9
  bool v37; // al
  __int64 v38; // rdx
  unsigned int v39; // er8
  UFG::qSymbol *v40; // r9
  unsigned int v41; // er8
  __int64 v42; // rdx
  UFG::PersistentData::KeyValue *v43; // rcx
  UFG::GameStatTracker *v44; // rax
  UFG::UIAmbientMapBlipData::eZoneInfo v45; // ecx
  int v46; // ecx
  int v47; // ecx
  signed __int64 v48; // rdi
  UFG::PersistentData::MapBool *v49; // r9
  __int64 v50; // rdx
  unsigned int v51; // er8
  UFG::qSymbol *v52; // r9
  bool v53; // al
  __int64 v54; // rdx
  unsigned int v55; // er8
  UFG::qSymbol *v56; // r9
  unsigned int v57; // er8
  __int64 v58; // rdx
  UFG::PersistentData::KeyValue *v59; // rcx
  UFG::GameStatTracker *v60; // rax
  UFG::PersistentData::MapBool *v61; // r9
  __int64 v62; // rdx
  unsigned int v63; // er8
  UFG::qSymbol *v64; // r9
  bool v65; // al
  __int64 v66; // rdx
  unsigned int v67; // er8
  UFG::qSymbol *v68; // r9
  unsigned int v69; // er8
  __int64 v70; // rdx
  UFG::PersistentData::KeyValue *v71; // rcx
  UFG::GameStatTracker *v72; // rax
  unsigned int v73; // ecx
  UFG::GameStatTracker *v74; // rdx
  UFG::PersistentData::MapBool *v75; // r9
  __int64 v76; // rdx
  unsigned int v77; // er8
  UFG::qSymbol *v78; // r9
  bool v79; // al
  __int64 v80; // rdx
  unsigned int v81; // er8
  UFG::qSymbol *v82; // r9
  unsigned int v83; // er8
  __int64 v84; // rdx
  UFG::PersistentData::KeyValue *v85; // rcx
  UFG::GameStatTracker *v86; // rax
  unsigned int v87; // ecx
  UFG::GameStatTracker *v88; // rax
  UFG::GameStatTracker *v89; // rax
  UFG::GameStat::MapBoolStat v90; // edx
  UFG::GameStatTracker *v91; // rax
  UFG::GameStatTracker *v92; // rax
  UFG::GameStatTracker *v93; // rax
  UFG::qWiseSymbol result; // [rsp+70h] [rbp+40h]
  UFG::qSymbol keyname; // [rsp+78h] [rbp+48h]
  UFG::qSymbol *v96; // [rsp+80h] [rbp+50h]

  v1 = UFG::UIAmbientMapBlipManager::getInstance(a1);
  v2 = hkaMatrix<float>::Height((hkaMatrix<float> *)v1);
  v3 = 0;
  if ( v2 > 0 )
  {
    while ( 1 )
    {
      v4 = UFG::UIAmbientMapBlipManager::getInstance(a1);
      v5 = UFG::UIAmbientMapBlipManager::GetBlipData(v4, v3);
      v6 = v5;
      v7 = UFG::UIAmbientMapBlipData::GetID(v5);
      UFG::qSymbol::qSymbol(&result, v7);
      switch ( v6->mCollectibleType )
      {
        case 1:
          v8 = UFG::GameStatTracker::Instance()->mpSnapshots[0]->mpMapBools[31];
          if ( v8->mKeepType )
          {
            if ( v8->mKeepType == 1 )
            {
              v13 = 0i64;
              v14 = v8->mNames.size;
              if ( v14 )
              {
                v15 = v8->mNames.p;
                while ( result.mUID != v15[v13].mUID )
                {
                  v13 = (unsigned int)(v13 + 1);
                  if ( (unsigned int)v13 >= v14 )
                    goto LABEL_16;
                }
              }
              else
              {
LABEL_16:
                LODWORD(v13) = -1;
              }
              v12 = (_DWORD)v13 != -1;
            }
            else
            {
              if ( v8->mKeepType != 2 )
                goto LABEL_26;
              v9 = 0i64;
              v10 = v8->mNames.size;
              if ( v10 )
              {
                v11 = v8->mNames.p;
                while ( result.mUID != v11[v9].mUID )
                {
                  v9 = (unsigned int)(v9 + 1);
                  if ( (unsigned int)v9 >= v10 )
                    goto LABEL_10;
                }
              }
              else
              {
LABEL_10:
                LODWORD(v9) = -1;
              }
              v12 = (_DWORD)v9 == -1;
            }
          }
          else
          {
            v16 = v8->mValues.size;
            v17 = 0i64;
            if ( !v16 )
              goto LABEL_26;
            v18 = v8->mValues.p;
            while ( v18->mKey.mUID != result.mUID )
            {
              v17 = (unsigned int)(v17 + 1);
              ++v18;
              if ( (unsigned int)v17 >= v16 )
                goto LABEL_26;
            }
            if ( (_DWORD)v17 == -1 )
            {
LABEL_26:
              v19 = UFG::GameStatTracker::Instance();
              if ( !(*((_BYTE *)v19 + 6216) & 1) )
              {
                UFG::PersistentData::MapBool::SetStatus(v19->mpSnapshots[0]->mpMapBools[31], (UFG::qSymbol *)&result, 0);
                if ( UFG::GameStatAction::PostStat::sIsEnabled )
                {
                  v20 = _S12_6;
                  if ( !(_S12_6 & 1) )
                  {
                    _S12_6 |= 1u;
                    UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
                    atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
                    v20 = _S12_6;
                  }
                  v21 = &sGameStatTracker;
                  if ( UFG::GameStatTracker::mspInstance )
                    v21 = UFG::GameStatTracker::mspInstance;
                  UFG::GameStatTracker::mspInstance = v21;
                  v22 = v21->mpSnapshots[0]->mpMapBools[31];
                  if ( v22->mKeepType == 2 )
                  {
                    v23 = 0;
                  }
                  else if ( v22->mKeepType == 1 )
                  {
                    v23 = v22->mNames.size;
                  }
                  else
                  {
                    v23 = 0;
                    v24 = v22->mValues.size;
                    if ( (_DWORD)v24 )
                    {
                      v25 = &v22->mValues.p->4;
                      do
                      {
                        if ( LOBYTE(v25->mFloatValue) )
                          ++v23;
                        v25 += 2;
                        --v24;
                      }
                      while ( v24 );
                    }
                  }
                  if ( !(v20 & 1) )
                  {
                    _S12_6 = v20 | 1;
                    UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
                    atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
                    v21 = UFG::GameStatTracker::mspInstance;
                  }
                  v26 = &sGameStatTracker;
                  if ( v21 )
                    v26 = v21;
                  UFG::GameStatTracker::mspInstance = v26;
                  v27 = v26->mpSnapshots[0]->mpMapBools[31];
                  if ( v27->mKeepType )
                  {
                    if ( (unsigned int)(v27->mKeepType - 1) > 1 )
                      v28 = 0;
                    else
                      v28 = v27->mNames.size;
                  }
                  else
                  {
                    v28 = v27->mValues.size;
                  }
                  if ( v23 == v28 )
                    UFG::AchievementTrophyManager::UnlockAchievementTrophy(36);
                  UFG::GameStatAction::PostStat::HandleExplorerStatAward();
                }
              }
              goto LABEL_195;
            }
            v12 = v8->mValues.p[v17].mBoolValue;
          }
          if ( !v12 )
            goto LABEL_26;
          goto LABEL_195;
        case 2:
          v29 = v6->mZoneInfo;
          if ( v29 )
          {
            v30 = v29 - 1;
            if ( v30 )
            {
              v31 = v30 - 1;
              if ( v31 )
              {
                if ( v31 != 1 )
                  goto LABEL_195;
                v32 = 26i64;
              }
              else
              {
                v32 = 25i64;
              }
            }
            else
            {
              v32 = 24i64;
            }
          }
          else
          {
            v32 = 23i64;
          }
          v33 = UFG::GameStatTracker::Instance()->mpSnapshots[0]->mpMapBools[v32];
          if ( v33->mKeepType )
          {
            if ( v33->mKeepType == 1 )
            {
              v38 = 0i64;
              v39 = v33->mNames.size;
              if ( v39 )
              {
                v40 = v33->mNames.p;
                while ( result.mUID != v40[v38].mUID )
                {
                  v38 = (unsigned int)(v38 + 1);
                  if ( (unsigned int)v38 >= v39 )
                    goto LABEL_74;
                }
              }
              else
              {
LABEL_74:
                LODWORD(v38) = -1;
              }
              v37 = (_DWORD)v38 != -1;
            }
            else
            {
              if ( v33->mKeepType != 2 )
                goto LABEL_84;
              v34 = 0i64;
              v35 = v33->mNames.size;
              if ( v35 )
              {
                v36 = v33->mNames.p;
                while ( result.mUID != v36[v34].mUID )
                {
                  v34 = (unsigned int)(v34 + 1);
                  if ( (unsigned int)v34 >= v35 )
                    goto LABEL_68;
                }
              }
              else
              {
LABEL_68:
                LODWORD(v34) = -1;
              }
              v37 = (_DWORD)v34 == -1;
            }
          }
          else
          {
            v41 = v33->mValues.size;
            v42 = 0i64;
            if ( !v41 )
              goto LABEL_84;
            v43 = v33->mValues.p;
            while ( v43->mKey.mUID != result.mUID )
            {
              v42 = (unsigned int)(v42 + 1);
              ++v43;
              if ( (unsigned int)v42 >= v41 )
                goto LABEL_84;
            }
            if ( (_DWORD)v42 == -1 )
            {
LABEL_84:
              v44 = UFG::GameStatTracker::Instance();
              if ( !(*((_BYTE *)v44 + 6216) & 1) )
              {
                UFG::PersistentData::MapBool::SetStatus(
                  v44->mpSnapshots[0]->mpMapBools[v32],
                  (UFG::qSymbol *)&result,
                  0);
                if ( UFG::GameStatAction::PostStat::sIsEnabled )
                {
                  v96 = &keyname;
                  keyname.mUID = result.mUID;
                  UFG::GameStatAction::PostStat::AchieveMapBool((UFG::GameStat::MapBoolStat)v32, (UFG::qSymbol)&keyname);
                }
              }
              goto LABEL_195;
            }
            v37 = v33->mValues.p[v42].mBoolValue;
          }
          if ( !v37 )
            goto LABEL_84;
LABEL_195:
          if ( ++v3 >= v2 )
            goto LABEL_196;
          break;
        case 3:
          v45 = v6->mZoneInfo;
          if ( v45 )
          {
            v46 = v45 - 1;
            if ( v46 )
            {
              v47 = v46 - 1;
              if ( v47 )
              {
                if ( v47 != 1 )
                  goto LABEL_195;
                v48 = 30i64;
              }
              else
              {
                v48 = 29i64;
              }
            }
            else
            {
              v48 = 28i64;
            }
          }
          else
          {
            v48 = 27i64;
          }
          v49 = UFG::GameStatTracker::Instance()->mpSnapshots[0]->mpMapBools[v48];
          if ( v49->mKeepType )
          {
            if ( v49->mKeepType == 1 )
            {
              v54 = 0i64;
              v55 = v49->mNames.size;
              if ( v55 )
              {
                v56 = v49->mNames.p;
                while ( result.mUID != v56[v54].mUID )
                {
                  v54 = (unsigned int)(v54 + 1);
                  if ( (unsigned int)v54 >= v55 )
                    goto LABEL_108;
                }
              }
              else
              {
LABEL_108:
                LODWORD(v54) = -1;
              }
              v53 = (_DWORD)v54 != -1;
            }
            else
            {
              if ( v49->mKeepType != 2 )
                goto LABEL_118;
              v50 = 0i64;
              v51 = v49->mNames.size;
              if ( v51 )
              {
                v52 = v49->mNames.p;
                while ( result.mUID != v52[v50].mUID )
                {
                  v50 = (unsigned int)(v50 + 1);
                  if ( (unsigned int)v50 >= v51 )
                    goto LABEL_102;
                }
              }
              else
              {
LABEL_102:
                LODWORD(v50) = -1;
              }
              v53 = (_DWORD)v50 == -1;
            }
          }
          else
          {
            v57 = v49->mValues.size;
            v58 = 0i64;
            if ( !v57 )
              goto LABEL_118;
            v59 = v49->mValues.p;
            while ( v59->mKey.mUID != result.mUID )
            {
              v58 = (unsigned int)(v58 + 1);
              ++v59;
              if ( (unsigned int)v58 >= v57 )
                goto LABEL_118;
            }
            if ( (_DWORD)v58 == -1 )
            {
LABEL_118:
              v60 = UFG::GameStatTracker::Instance();
              if ( !(*((_BYTE *)v60 + 6216) & 1) )
              {
                UFG::PersistentData::MapBool::SetStatus(
                  v60->mpSnapshots[0]->mpMapBools[v48],
                  (UFG::qSymbol *)&result,
                  0);
                if ( UFG::GameStatAction::PostStat::sIsEnabled )
                {
                  v96 = &keyname;
                  keyname.mUID = result.mUID;
                  UFG::GameStatAction::PostStat::AchieveMapBool((UFG::GameStat::MapBoolStat)v48, (UFG::qSymbol)&keyname);
                }
              }
              goto LABEL_195;
            }
            v53 = v49->mValues.p[v58].mBoolValue;
          }
          if ( !v53 )
            goto LABEL_118;
          goto LABEL_195;
        case 4:
          v61 = UFG::GameStatTracker::Instance()->mpSnapshots[0]->mpMapBools[12];
          if ( v61->mKeepType )
          {
            if ( v61->mKeepType == 1 )
            {
              v66 = 0i64;
              v67 = v61->mNames.size;
              if ( v67 )
              {
                v68 = v61->mNames.p;
                while ( result.mUID != v68[v66].mUID )
                {
                  v66 = (unsigned int)(v66 + 1);
                  if ( (unsigned int)v66 >= v67 )
                    goto LABEL_134;
                }
              }
              else
              {
LABEL_134:
                LODWORD(v66) = -1;
              }
              v65 = (_DWORD)v66 != -1;
            }
            else
            {
              if ( v61->mKeepType != 2 )
                goto LABEL_144;
              v62 = 0i64;
              v63 = v61->mNames.size;
              if ( v63 )
              {
                v64 = v61->mNames.p;
                while ( result.mUID != v64[v62].mUID )
                {
                  v62 = (unsigned int)(v62 + 1);
                  if ( (unsigned int)v62 >= v63 )
                    goto LABEL_128;
                }
              }
              else
              {
LABEL_128:
                LODWORD(v62) = -1;
              }
              v65 = (_DWORD)v62 == -1;
            }
          }
          else
          {
            v69 = v61->mValues.size;
            v70 = 0i64;
            if ( !v69 )
              goto LABEL_144;
            v71 = v61->mValues.p;
            while ( v71->mKey.mUID != result.mUID )
            {
              v70 = (unsigned int)(v70 + 1);
              ++v71;
              if ( (unsigned int)v70 >= v69 )
                goto LABEL_144;
            }
            if ( (_DWORD)v70 == -1 )
            {
LABEL_144:
              v72 = UFG::GameStatTracker::Instance();
              if ( !(*((_BYTE *)v72 + 6216) & 1) )
              {
                UFG::PersistentData::MapBool::SetStatus(v72->mpSnapshots[0]->mpMapBools[12], (UFG::qSymbol *)&result, 0);
                if ( UFG::GameStatAction::PostStat::sIsEnabled )
                {
                  v73 = _S12_6;
                  if ( !(_S12_6 & 1) )
                  {
                    _S12_6 |= 1u;
                    UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
                    atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
                    v73 = _S12_6;
                  }
                  v74 = &sGameStatTracker;
                  if ( UFG::GameStatTracker::mspInstance )
                    v74 = UFG::GameStatTracker::mspInstance;
                  UFG::GameStatTracker::mspInstance = v74;
                  if ( !(v73 & 1) )
                  {
                    _S12_6 = v73 | 1;
                    UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
                    atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
                    goto LABEL_152;
                  }
                  goto LABEL_153;
                }
              }
              goto LABEL_195;
            }
            v65 = v61->mValues.p[v70].mBoolValue;
          }
          if ( !v65 )
            goto LABEL_144;
          goto LABEL_195;
        case 6:
          v75 = UFG::GameStatTracker::Instance()->mpSnapshots[0]->mpMapBools[5];
          if ( v75->mKeepType )
          {
            if ( v75->mKeepType == 1 )
            {
              v80 = 0i64;
              v81 = v75->mNames.size;
              if ( v81 )
              {
                v82 = v75->mNames.p;
                while ( result.mUID != v82[v80].mUID )
                {
                  v80 = (unsigned int)(v80 + 1);
                  if ( (unsigned int)v80 >= v81 )
                    goto LABEL_168;
                }
              }
              else
              {
LABEL_168:
                LODWORD(v80) = -1;
              }
              v79 = (_DWORD)v80 != -1;
            }
            else
            {
              if ( v75->mKeepType != 2 )
                goto LABEL_178;
              v76 = 0i64;
              v77 = v75->mNames.size;
              if ( v77 )
              {
                v78 = v75->mNames.p;
                while ( result.mUID != v78[v76].mUID )
                {
                  v76 = (unsigned int)(v76 + 1);
                  if ( (unsigned int)v76 >= v77 )
                    goto LABEL_162;
                }
              }
              else
              {
LABEL_162:
                LODWORD(v76) = -1;
              }
              v79 = (_DWORD)v76 == -1;
            }
          }
          else
          {
            v83 = v75->mValues.size;
            v84 = 0i64;
            if ( !v83 )
              goto LABEL_178;
            v85 = v75->mValues.p;
            while ( v85->mKey.mUID != result.mUID )
            {
              v84 = (unsigned int)(v84 + 1);
              ++v85;
              if ( (unsigned int)v84 >= v83 )
                goto LABEL_178;
            }
            if ( (_DWORD)v84 == -1 )
            {
LABEL_178:
              v86 = UFG::GameStatTracker::Instance();
              if ( !(*((_BYTE *)v86 + 6216) & 1) )
              {
                UFG::PersistentData::MapBool::SetStatus(v86->mpSnapshots[0]->mpMapBools[5], (UFG::qSymbol *)&result, 0);
                if ( UFG::GameStatAction::PostStat::sIsEnabled )
                {
                  v87 = _S12_6;
                  if ( !(_S12_6 & 1) )
                  {
                    _S12_6 |= 1u;
                    UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
                    atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
                    v87 = _S12_6;
                  }
                  v74 = &sGameStatTracker;
                  if ( UFG::GameStatTracker::mspInstance )
                    v74 = UFG::GameStatTracker::mspInstance;
                  UFG::GameStatTracker::mspInstance = v74;
                  if ( !(v87 & 1) )
                  {
                    _S12_6 = v87 | 1;
                    UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
                    atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
LABEL_152:
                    v74 = UFG::GameStatTracker::mspInstance;
                  }
LABEL_153:
                  if ( !v74 )
                    UFG::GameStatTracker::mspInstance = &sGameStatTracker;
                }
              }
              goto LABEL_195;
            }
            v79 = v75->mValues.p[v84].mBoolValue;
          }
          if ( !v79 )
            goto LABEL_178;
          goto LABEL_195;
        case 8:
          v88 = UFG::GameStatTracker::Instance();
          if ( !UFG::PersistentData::MapBool::GetStatus(v88->mpSnapshots[0]->mpMapBools[3], (UFG::qSymbol *)&result) )
          {
            v89 = UFG::GameStatTracker::Instance();
            v90 = 3;
            goto LABEL_194;
          }
          goto LABEL_195;
        case 0xB:
          v91 = UFG::GameStatTracker::Instance();
          if ( !UFG::PersistentData::MapBool::GetStatus(v91->mpSnapshots[0]->mpMapBools[34], (UFG::qSymbol *)&result) )
          {
            v89 = UFG::GameStatTracker::Instance();
            v90 = 34;
            goto LABEL_194;
          }
          goto LABEL_195;
        case 0xC:
          v93 = UFG::GameStatTracker::Instance();
          if ( !UFG::PersistentData::MapBool::GetStatus(v93->mpSnapshots[0]->mpMapBools[36], (UFG::qSymbol *)&result) )
          {
            v89 = UFG::GameStatTracker::Instance();
            v90 = 36;
            goto LABEL_194;
          }
          goto LABEL_195;
        case 0xD:
          v92 = UFG::GameStatTracker::Instance();
          if ( !UFG::PersistentData::MapBool::GetStatus(v92->mpSnapshots[0]->mpMapBools[35], (UFG::qSymbol *)&result) )
          {
            v89 = UFG::GameStatTracker::Instance();
            v90 = 35;
LABEL_194:
            UFG::GameStatTracker::SetStat(v89, v90, (UFG::qSymbol *)&result, 0);
          }
          goto LABEL_195;
        default:
          goto LABEL_195;
      }
    }
  }
LABEL_196:
  UFG::GameStatAction::PostStat::sIsEnabled = 1;
}195;
      }
    }
  }
LABEL_196:
  UFG::GameStatAction::PostStat::sIsEnabled = 1;
}

// File Line: 3205
// RVA: 0x491D60
void __fastcall UFG::GameStatAction::PostStat::Achieve(UFG::GameSnapshot::PersistentDataType persistentdatatype, int stat_enum, __int64 mapid)
{
  __int64 v3; // rax
  UFG::qSymbol mapida; // [rsp+20h] [rbp-28h]
  unsigned int v5; // [rsp+24h] [rbp-24h]
  unsigned int v6; // [rsp+28h] [rbp-20h]
  int v7; // [rsp+2Ch] [rbp-1Ch]
  __int64 v8; // [rsp+30h] [rbp-18h]
  UFG::qSymbol *v9; // [rsp+38h] [rbp-10h]
  UFG::qSymbol keyname; // [rsp+68h] [rbp+20h]

  v8 = -2i64;
  if ( UFG::GameStatAction::PostStat::sIsEnabled )
  {
    switch ( persistentdatatype )
    {
      case 3:
        UFG::GameStatAction::PostStat::AchieveInt((UFG::GameStat::Int32Stat)stat_enum);
        break;
      case 10:
        v9 = &keyname;
        keyname.mUID = *(_DWORD *)mapid;
        UFG::GameStatAction::PostStat::AchieveMapBool((UFG::GameStat::MapBoolStat)stat_enum, (UFG::qSymbol)&keyname);
        break;
      case 11:
        v9 = &mapida;
        mapida.mUID = *(_DWORD *)mapid;
        UFG::GameStatAction::PostStat::AchieveMapInt((UFG::GameStat::MapInt32Stat)stat_enum, (UFG::qSymbol)&mapida);
        break;
      case 12:
        v9 = (UFG::qSymbol *)&v5;
        v5 = *(_DWORD *)mapid;
        break;
      case 13:
        v9 = (UFG::qSymbol *)&v6;
        v6 = *(_DWORD *)mapid;
        break;
      case 14:
        v9 = (UFG::qSymbol *)&v7;
        v3 = *(unsigned int *)mapid;
        break;
      default:
        return;
    }
  }
}

// File Line: 3231
// RVA: 0x491E70
void __fastcall UFG::GameStatAction::PostStat::AchieveInt(UFG::GameStat::Int32Stat e)
{
  UFG::GameStat::Int32Stat v1; // ebx
  UFG::GameStatTracker *v2; // rdi
  int v3; // ebx
  int v4; // ebx
  UFG::GameSnapshot *v5; // rax
  int v6; // er8
  int v7; // ecx
  signed int v8; // ebx

  v1 = e;
  v2 = &sGameStatTracker;
  if ( !(_S12_6 & 1) )
  {
    _S12_6 |= 1u;
    UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
    atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
  }
  if ( UFG::GameStatTracker::mspInstance )
    v2 = UFG::GameStatTracker::mspInstance;
  UFG::GameStatTracker::mspInstance = v2;
  v3 = v1 - 29;
  if ( v3 )
  {
    v4 = v3 - 18;
    if ( v4 )
    {
      if ( v4 == 15 )
      {
        v5 = v2->mpSnapshots[0];
        v6 = v5->mInts[62].mValue;
        if ( v5->mInts[63].mValue < v6 )
          UFG::GameStatTracker::SetStat(v2, MostCashHeld, v6);
      }
      return;
    }
    if ( v2->mpSnapshots[0]->mInts[47].mValue < 5 )
      return;
    v7 = 21;
LABEL_19:
    UFG::AchievementTrophyManager::UnlockAchievementTrophy(v7);
    return;
  }
  v8 = UFG::GameStatTracker::GetFaceLevelFromExperience(v2, v2->mpSnapshots[0]->mInts[29].mValue);
  if ( UFG::ProgressionTracker::Instance()->mActiveFlowId.mUID == gDefaultFlowId.mUID )
  {
    if ( v8 >= 2 )
      UFG::AchievementTrophyManager::UnlockAchievementTrophy(5);
    if ( v8 >= 5 )
      UFG::AchievementTrophyManager::UnlockAchievementTrophy(6);
    if ( v8 >= 10 )
    {
      v7 = 7;
      goto LABEL_19;
    }
  }
}

// File Line: 3282
// RVA: 0x491F80
void __fastcall UFG::GameStatAction::PostStat::AchieveMapBool(UFG::GameStat::MapBoolStat stat_enum, UFG::qSymbol keyname)
{
  __int64 v2; // rbp
  unsigned int v3; // edx
  UFG::GameStatTracker *v4; // rsi
  UFG::GameStatTracker *v5; // r8
  signed __int64 v6; // r14
  __int64 v7; // rax
  unsigned int v8; // edi
  signed int v9; // ebx
  __int64 v10; // rcx
  _BYTE *v11; // rax
  _DWORD *v12; // rcx
  signed int v13; // edx
  UFG::PersistentData::MapBool *v14; // r15
  UFG::PersistentData::MapBool *v15; // rbx
  UFG::PersistentData::MapBool *v16; // rsi
  UFG::PersistentData::MapBool *v17; // r14
  unsigned int v18; // ebp
  unsigned int v19; // ebp
  unsigned int v20; // ebp
  unsigned int v21; // ebp
  unsigned int v22; // er8
  unsigned int v23; // edx
  unsigned int v24; // ecx
  UFG::PersistentData::MapBool *v25; // rsi
  UFG::PersistentData::MapBool *v26; // rbx
  unsigned int v27; // ebp
  unsigned int v28; // ebp
  unsigned int v29; // ecx
  int v30; // ecx

  v2 = stat_enum;
  v3 = _S12_6;
  v4 = &sGameStatTracker;
  if ( !(_S12_6 & 1) )
  {
    _S12_6 |= 1u;
    UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
    atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
    v3 = _S12_6;
  }
  v5 = &sGameStatTracker;
  if ( UFG::GameStatTracker::mspInstance )
    v5 = UFG::GameStatTracker::mspInstance;
  UFG::GameStatTracker::mspInstance = v5;
  v6 = 8 * v2 + 3048;
  v7 = *(unsigned __int64 *)((char *)&v5->mpSnapshots[0]->mTimes[0].mTimer.mTimestamp + v6);
  v8 = 0;
  if ( *(_DWORD *)v7 == 2 )
  {
    v9 = 0;
  }
  else if ( *(_DWORD *)v7 == 1 )
  {
    v9 = *(_DWORD *)(v7 + 24);
  }
  else
  {
    v9 = 0;
    v10 = *(unsigned int *)(v7 + 8);
    if ( (_DWORD)v10 )
    {
      v11 = (_BYTE *)(*(_QWORD *)(v7 + 16) + 4i64);
      do
      {
        if ( *v11 )
          ++v9;
        v11 += 8;
        --v10;
      }
      while ( v10 );
    }
  }
  if ( !(v3 & 1) )
  {
    _S12_6 = v3 | 1;
    UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
    atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
    v5 = UFG::GameStatTracker::mspInstance;
  }
  if ( v5 )
    v4 = v5;
  UFG::GameStatTracker::mspInstance = v4;
  v12 = *(_DWORD **)((char *)&v4->mpSnapshots[0]->mTimes[0].mTimer.mTimestamp + v6);
  if ( *v12 )
  {
    if ( (unsigned int)(*v12 - 1) > 1 )
      v13 = 0;
    else
      v13 = v12[6];
  }
  else
  {
    v13 = v12[2];
  }
  switch ( (_DWORD)v2 )
  {
    case 7:
      goto $LN10_36;
    case 0x17:
    case 0x18:
    case 0x19:
    case 0x1A:
      v14 = UFG::GameStatTracker::Instance()->mpSnapshots[0]->mpMapBools[23];
      v15 = UFG::GameStatTracker::Instance()->mpSnapshots[0]->mpMapBools[24];
      v16 = UFG::GameStatTracker::Instance()->mpSnapshots[0]->mpMapBools[25];
      v17 = UFG::GameStatTracker::Instance()->mpSnapshots[0]->mpMapBools[26];
      v18 = UFG::PersistentData::MapBool::GetTrueCount(v17);
      v19 = UFG::PersistentData::MapBool::GetTrueCount(v16) + v18;
      v20 = UFG::PersistentData::MapBool::GetTrueCount(v15) + v19;
      v21 = UFG::PersistentData::MapBool::GetTrueCount(v14) + v20;
      if ( v14->mKeepType )
      {
        if ( (unsigned int)(v14->mKeepType - 1) > 1 )
          v22 = 0;
        else
          v22 = v14->mNames.size;
      }
      else
      {
        v22 = v14->mValues.size;
      }
      if ( v15->mKeepType )
      {
        if ( (unsigned int)(v15->mKeepType - 1) > 1 )
          v23 = 0;
        else
          v23 = v15->mNames.size;
      }
      else
      {
        v23 = v15->mValues.size;
      }
      if ( v16->mKeepType )
      {
        if ( (unsigned int)(v16->mKeepType - 1) > 1 )
          v24 = 0;
        else
          v24 = v16->mNames.size;
      }
      else
      {
        v24 = v16->mValues.size;
      }
      if ( v17->mKeepType )
      {
        if ( (unsigned int)(v17->mKeepType - 1) <= 1 )
          v8 = v17->mNames.size;
      }
      else
      {
        v8 = v17->mValues.size;
      }
      if ( v21 == v22 + v23 + v8 + v24 )
        UFG::AchievementTrophyManager::UnlockAchievementTrophy(38);
      UFG::GameStatAction::PostStat::HandleExplorerStatAward();
      return;
    case 0x1B:
    case 0x1D:
      v25 = UFG::GameStatTracker::Instance()->mpSnapshots[0]->mpMapBools[27];
      v26 = UFG::GameStatTracker::Instance()->mpSnapshots[0]->mpMapBools[29];
      v27 = UFG::PersistentData::MapBool::GetTrueCount(v26);
      v28 = UFG::PersistentData::MapBool::GetTrueCount(v25) + v27;
      if ( v25->mKeepType )
      {
        if ( (unsigned int)(v25->mKeepType - 1) > 1 )
          v29 = 0;
        else
          v29 = v25->mNames.size;
      }
      else
      {
        v29 = v25->mValues.size;
      }
      if ( v26->mKeepType )
      {
        if ( (unsigned int)(v26->mKeepType - 1) <= 1 )
          v8 = v26->mNames.size;
      }
      else
      {
        v8 = v26->mValues.size;
      }
      if ( v28 == v8 + v29 )
        UFG::AchievementTrophyManager::UnlockAchievementTrophy(33);
      UFG::GameStatAction::PostStat::HandleExplorerStatAward();
      return;
    case 0x1C:
      if ( v9 == v13 )
        UFG::AchievementTrophyManager::UnlockAchievementTrophy(32);
      UFG::GameStatAction::PostStat::HandleExplorerStatAward();
      return;
    case 0x1E:
      if ( v9 == v13 )
        UFG::AchievementTrophyManager::UnlockAchievementTrophy(31);
$LN10_36:
      UFG::GameStatAction::PostStat::HandleExplorerStatAward();
      return;
    case 0x1F:
      if ( v9 == v13 )
        UFG::AchievementTrophyManager::UnlockAchievementTrophy(36);
      UFG::GameStatAction::PostStat::HandleExplorerStatAward();
      return;
    case 0x22:
      if ( v9 < v13 )
        return;
      v30 = 55;
      goto LABEL_75;
    case 0x23:
      if ( v9 < v13 )
        return;
      v30 = 60;
      goto LABEL_75;
    case 0x3D:
      if ( !UFG::GameStatAction::Store::AreAllClothesPurchased() )
        return;
      v30 = 37;
      goto LABEL_75;
    case 0x4E:
      if ( v13 >= 10 )
      {
        v30 = 13;
LABEL_75:
        UFG::AchievementTrophyManager::UnlockAchievementTrophy(v30);
      }
      break;
    default:
      return;
  }
}

// File Line: 3409
// RVA: 0x4A7400
void UFG::GameStatAction::PostStat::HandleExplorerStatAward(void)
{
  int v0; // esi
  int v1; // ebx
  int *v2; // rdi
  unsigned int v3; // er8
  UFG::GameStatTracker *v4; // r9
  UFG::GameStatTracker *v5; // rax
  UFG::PersistentData::MapBool *v6; // rax
  unsigned int v7; // ecx
  __int64 v8; // rdx
  $CCFB32CF948EEB04FF452B3FEB4ECF53 *v9; // rax
  UFG::OSuiteLeaderboardManager *v10; // rax
  UFG::OSuiteLeaderboardData *v11; // rax
  int v12; // [rsp+28h] [rbp-30h]
  int v13; // [rsp+2Ch] [rbp-2Ch]
  int v14; // [rsp+30h] [rbp-28h]
  int v15; // [rsp+34h] [rbp-24h]
  int v16; // [rsp+38h] [rbp-20h]
  int v17; // [rsp+3Ch] [rbp-1Ch]
  int v18; // [rsp+40h] [rbp-18h]
  int v19; // [rsp+44h] [rbp-14h]
  int v20; // [rsp+48h] [rbp-10h]
  int v21; // [rsp+4Ch] [rbp-Ch]

  v12 = 23;
  v13 = 24;
  v14 = 25;
  v15 = 26;
  v16 = 27;
  v17 = 28;
  v18 = 29;
  v19 = 30;
  v20 = 7;
  v21 = 31;
  v0 = 0;
  v1 = 0;
  v2 = &v12;
  v3 = _S12_6;
  v4 = UFG::GameStatTracker::mspInstance;
  do
  {
    if ( !(v3 & 1) )
    {
      _S12_6 = v3 | 1;
      UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
      atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
      v3 = _S12_6;
      v4 = UFG::GameStatTracker::mspInstance;
    }
    v5 = &sGameStatTracker;
    if ( v4 )
      v5 = v4;
    UFG::GameStatTracker::mspInstance = v5;
    if ( !(v3 & 1) )
    {
      _S12_6 = v3 | 1;
      UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
      atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
      v3 = _S12_6;
      v5 = UFG::GameStatTracker::mspInstance;
    }
    v4 = &sGameStatTracker;
    if ( v5 )
      v4 = v5;
    UFG::GameStatTracker::mspInstance = v4;
    v6 = v4->mpSnapshots[0]->mpMapBools[*v2];
    if ( v6->mKeepType == 2 )
    {
      v7 = 0;
    }
    else if ( v6->mKeepType == 1 )
    {
      v7 = v6->mNames.size;
    }
    else
    {
      v7 = 0;
      v8 = v6->mValues.size;
      if ( (_DWORD)v8 )
      {
        v9 = &v6->mValues.p->4;
        do
        {
          if ( LOBYTE(v9->mFloatValue) )
            ++v7;
          v9 += 2;
          --v8;
        }
        while ( v8 );
      }
    }
    v0 += v7;
    ++v1;
    ++v2;
  }
  while ( (unsigned __int64)v1 < 0xA );
  v10 = UFG::OSuiteLeaderboardManager::Instance();
  v11 = UFG::OSuiteLeaderboardManager::GetLeaderboardDataUsingLeaderboardName(v10, "StatAwardsExplorer");
  UFG::DataSynchronizer::SetMaxToGlobalSnapshot(v11, v0);
}

// File Line: 3435
// RVA: 0x492350
void __fastcall UFG::GameStatAction::PostStat::AchieveMapInt(UFG::GameStat::MapInt32Stat e, UFG::qSymbol mapid)
{
  __int64 v2; // rbx
  UFG::GameStatTracker *v3; // rdi
  UFG::PersistentData::MapInt *v4; // rdx
  int v5; // ebx
  int v6; // ebx
  int v7; // ecx

  v2 = e;
  v3 = &sGameStatTracker;
  if ( !(_S12_6 & 1) )
  {
    _S12_6 |= 1u;
    UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
    atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
  }
  if ( UFG::GameStatTracker::mspInstance )
    v3 = UFG::GameStatTracker::mspInstance;
  UFG::GameStatTracker::mspInstance = v3;
  v4 = v3->mpSnapshots[0]->mpMapInts[v2];
  v5 = v2 - 24;
  if ( !v5 )
  {
    if ( (signed int)v4->mValues.size < 5 )
      return;
    v7 = 14;
    goto LABEL_14;
  }
  v6 = v5 - 1;
  if ( !v6 )
  {
    if ( (signed int)v4->mValues.size < 10 )
      return;
    v7 = 18;
    goto LABEL_14;
  }
  if ( v6 == 3 && (signed int)v4->mValues.size >= 10 )
  {
    v7 = 17;
LABEL_14:
    UFG::AchievementTrophyManager::UnlockAchievementTrophy(v7);
  }
}

// File Line: 3482
// RVA: 0x4C4AA0
void UFG::GameStatAction::TemporaryData::Update(void)
{
  UFG::GameStatTracker *v0; // rdi
  float v1; // xmm1_4
  float v2; // xmm6_4
  float v3; // xmm1_4
  float v4; // xmm1_4
  float v5; // xmm1_4
  UFG::GameSnapshot *v6; // r9
  UFG::PersistentData::MapBool *v7; // rdx
  UFG::PersistentData::MapBool::KeepType v8; // ecx
  signed int v9; // eax
  float v10; // xmm1_4
  signed int v11; // ecx
  unsigned int v12; // er8
  $CCFB32CF948EEB04FF452B3FEB4ECF53 *v13; // rax
  __int64 v14; // rdx
  UFG::SimObjectCharacter *v15; // rax
  UFG::SimComponent *v16; // rcx
  float v17; // xmm8_4
  float v18; // xmm1_4
  UFG::GameSnapshot *v19; // rax
  signed int v20; // ecx
  UFG::GameSnapshot *v21; // rax
  float v22; // xmm1_4
  UFG::AchievementTrophyManager *v23; // r15
  unsigned int v24; // esi
  __int64 v25; // r14
  UFG::qSymbol *v26; // rbx
  UFG::GameStatTracker *v27; // rax
  unsigned int v28; // ebx
  UFG::ProgressionTracker *v29; // rax
  UFG::ProgressionTracker *v30; // rsi
  UFG::qBaseTreeRB *v31; // rax
  const char *v32; // rbx
  UFG::RadioStation *v33; // rax
  const char *v34; // rbx
  UFG::RadioStation *v35; // rax
  char *v36; // rbx
  UFG::qPropertySet *v37; // rax
  char *v38; // rbx
  UFG::qPropertySet *v39; // rax
  char *v40; // rbx
  UFG::qPropertySet *v41; // rax
  char *v42; // rbx
  UFG::qPropertySet *v43; // rax
  char *v44; // rbx
  UFG::qPropertySet *v45; // rax
  char *v46; // rbx
  UFG::qPropertySet *v47; // rax
  char *v48; // rbx
  UFG::qPropertySet *v49; // rax
  char *v50; // rbx
  UFG::qPropertySet *v51; // rax
  float v52; // xmm7_4
  UFG::qSymbol *v53; // r14
  UFG::GameSnapshot *v54; // rbx
  UFG::PersistentData::MapInt *v55; // r12
  unsigned int v56; // er10
  UFG::PersistentData::MapInt *v57; // r13
  unsigned int v58; // er11
  unsigned int v59; // ebx
  __int64 v60; // rdx
  UFG::PersistentData::KeyValue *v61; // rax
  signed int v62; // er9
  __int64 v63; // rdx
  UFG::PersistentData::KeyValue *v64; // rax
  signed int v65; // ecx
  float v66; // xmm1_4
  char *v67; // rbx
  UFG::qPropertySet *v68; // rax
  __int64 v69; // ST08_8
  __int64 v70; // rsi
  unsigned int i; // ebx
  UFG::GameSnapshot *v72; // rcx
  signed int v73; // eax
  __int64 v74; // [rsp+8h] [rbp-79h]
  UFG::qString v75; // [rsp+10h] [rbp-71h]
  UFG::PersistentData::MapFloat::Iterator result; // [rsp+38h] [rbp-49h]
  char *format; // [rsp+50h] [rbp-31h]
  UFG::qSymbol symGameSliceName[2]; // [rsp+E8h] [rbp+67h]
  UFG::qSymbol *min; // [rsp+F0h] [rbp+6Fh]

  *(_QWORD *)&v75.mStringHash32 = -2i64;
  v0 = &sGameStatTracker;
  if ( !(_S12_6 & 1) )
  {
    _S12_6 |= 1u;
    UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
    atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
  }
  if ( UFG::GameStatTracker::mspInstance )
    v0 = UFG::GameStatTracker::mspInstance;
  UFG::GameStatTracker::mspInstance = v0;
  v1 = (float)v0->mpSnapshots[0]->mInts[100].mValue;
  v2 = *(float *)&FLOAT_1_0;
  if ( v1 < 1.0 )
    v1 = *(float *)&FLOAT_1_0;
  if ( !(*((_BYTE *)v0 + 6216) & 1) )
    v0->mpSnapshots[0]->mFloats[121].mValue = (float)((float)v0->mpSnapshots[0]->mInts[101].mValue * 100.0) / v1;
  v3 = (float)v0->mpSnapshots[0]->mInts[102].mValue;
  if ( v3 < 1.0 )
    v3 = *(float *)&FLOAT_1_0;
  if ( !(*((_BYTE *)v0 + 6216) & 1) )
    v0->mpSnapshots[0]->mFloats[122].mValue = (float)((float)v0->mpSnapshots[0]->mInts[103].mValue * 100.0) / v3;
  v4 = (float)v0->mpSnapshots[0]->mInts[105].mValue;
  if ( v4 < 1.0 )
    v4 = *(float *)&FLOAT_1_0;
  if ( !(*((_BYTE *)v0 + 6216) & 1) )
    v0->mpSnapshots[0]->mFloats[123].mValue = (float)((float)v0->mpSnapshots[0]->mInts[106].mValue * 100.0) / v4;
  v5 = (float)v0->mpSnapshots[0]->mInts[108].mValue;
  if ( v5 < 1.0 )
    v5 = *(float *)&FLOAT_1_0;
  if ( !(*((_BYTE *)v0 + 6216) & 1) )
    v0->mpSnapshots[0]->mFloats[124].mValue = (float)((float)v0->mpSnapshots[0]->mInts[109].mValue * 100.0) / v5;
  min = symGameSliceName;
  symGameSliceName[0] = gMissionSymbol_M_VE;
  if ( UFG::GameStatAction::GameSliceAction::IsCompleted((__int64)symGameSliceName) )
  {
    if ( !(*((_BYTE *)v0 + 6216) & 1) )
    {
      UFG::PersistentData::MapBool::SetStatus(v0->mpSnapshots[0]->mpMapBools[66], &gMissionSymbol_M_VE, 1);
      if ( UFG::GameStatAction::PostStat::sIsEnabled )
      {
        min = symGameSliceName;
        symGameSliceName[0] = gMissionSymbol_M_VE;
        UFG::GameStatAction::PostStat::AchieveMapBool(MissionsCompleted, (UFG::qSymbol)symGameSliceName);
      }
    }
  }
  v6 = v0->mpSnapshots[0];
  v7 = v6->mpMapBools[66];
  v8 = v7->mKeepType;
  if ( v7->mKeepType )
  {
    if ( (unsigned int)(v8 - 1) > 1 )
      v9 = 0;
    else
      v9 = v7->mNames.size;
  }
  else
  {
    v9 = v7->mValues.size;
  }
  v10 = (float)v9;
  if ( v8 == 2 )
  {
    v11 = 0;
  }
  else if ( v8 == 1 )
  {
    v11 = v7->mNames.size;
  }
  else
  {
    v11 = 0;
    v12 = v7->mValues.size;
    if ( v12 )
    {
      v13 = &v7->mValues.p->4;
      v14 = v12;
      do
      {
        if ( LOBYTE(v13->mFloatValue) )
          ++v11;
        v13 += 2;
        --v14;
      }
      while ( v14 );
    }
  }
  if ( v10 < 1.0 )
    v10 = *(float *)&FLOAT_1_0;
  if ( !(*((_BYTE *)v0 + 6216) & 1) )
    v6->mFloats[118].mValue = (float)((float)v11 * 100.0) / v10;
  v15 = UFG::GetLocalPlayer();
  if ( v15 )
  {
    v16 = v15->m_Components.p[6].m_pComponent;
    if ( v16 )
    {
      if ( !(*((_BYTE *)v0 + 6216) & 1) )
        v0->mpSnapshots[0]->mFloats[127].mValue = (float)(signed int)*((float *)&v16[1].m_SafePointerList.mNode.mNext + 1);
    }
  }
  v17 = 0.0;
  v18 = 0.0;
  v19 = v0->mpSnapshots[0];
  v20 = v19->mInts[49].mValue;
  if ( v20 && v19->mFloats[85].mValue > 0.0 )
    v18 = v19->mFloats[85].mValue / (float)v20;
  if ( !(*((_BYTE *)v0 + 6216) & 1) )
  {
    v19->mFloats[125].mValue = v18;
    if ( !(*((_BYTE *)v0 + 6216) & 1) )
      v0->mpSnapshots[0]->mFloats[126].mValue = 0.0;
  }
  v21 = v0->mpSnapshots[0];
  v22 = v21->mFloats[1].mValue;
  if ( v22 > 1.0 && !(*((_BYTE *)v0 + 6216) & 1) )
    v21->mFloats[126].mValue = (float)(v21->mFloats[0].mValue / v22) * 3.0;
  v23 = UFG::AchievementTrophyManager::mInstance;
  if ( UFG::AchievementTrophyManager::mInstance )
  {
    v24 = 0;
    v25 = 0i64;
    do
    {
      if ( v24 <= 0x7F && v23->mTrophyUnlockedFlag[v25] )
      {
        v26 = (UFG::qSymbol *)UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)symGameSliceName, v24);
        v27 = UFG::GameStatTracker::Instance();
        UFG::GameStatTracker::SetStat(v27, AchievementsCompleted, v26, 1);
      }
      ++v24;
      ++v25;
    }
    while ( (signed int)v24 < 128 );
  }
  UFG::qString::qString(&v75, UFG::GameStatAction::invalid_name);
  if ( !(*((_BYTE *)v0 + 6216) & 1) )
    UFG::qString::Set(&v0->mpSnapshots[0]->mStrings[15].mValue, v75.mData, v75.mLength, 0i64, 0);
  UFG::qString::~qString(&v75);
  v28 = v0->mpSnapshots[0]->mIDs[28].mValue.mUID;
  if ( v28 != -1 )
  {
    v29 = UFG::ProgressionTracker::Instance();
    v30 = v29;
    if ( v28 )
    {
      v31 = UFG::qBaseTreeRB::Get(&v29->mGameSlices.mTree, v28);
      if ( v31 )
      {
LABEL_70:
        UFG::qString::qString(&v75, (const char *)v31->mNULL.mChild[0]);
        if ( !(*((_BYTE *)v0 + 6216) & 1) )
          UFG::qString::Set(&v0->mpSnapshots[0]->mStrings[15].mValue, v75.mData, v75.mLength, 0i64, 0);
        UFG::qString::~qString(&v75);
        goto LABEL_73;
      }
      v31 = UFG::qBaseTreeRB::Get(&v30->mContainerGameSlices.mTree, v28);
    }
    else
    {
      v31 = 0i64;
    }
    if ( !v31 )
      goto LABEL_73;
    goto LABEL_70;
  }
LABEL_73:
  UFG::PersistentData::MapFloat::GetMaxMin(v0->mpSnapshots[0]->mpMapFloats[2], (UFG::qSymbol **)symGameSliceName, &min);
  v32 = UFG::GameStatAction::invalid_name;
  if ( *(_QWORD *)&symGameSliceName[0].mUID )
  {
    v33 = UFG::Radio::FindRadioStation(*(UFG::qSymbol **)&symGameSliceName[0].mUID);
    if ( v33 )
      v32 = v33->m_name;
  }
  UFG::qString::qString(&v75, v32);
  if ( !(*((_BYTE *)v0 + 6216) & 1) )
    UFG::qString::Set(&v0->mpSnapshots[0]->mStrings[7].mValue, v75.mData, v75.mLength, 0i64, 0);
  UFG::qString::~qString(&v75);
  v34 = UFG::GameStatAction::invalid_name;
  if ( min )
  {
    v35 = UFG::Radio::FindRadioStation(min);
    if ( v35 )
      v34 = v35->m_name;
  }
  UFG::qString::qString(&v75, v34);
  if ( !(*((_BYTE *)v0 + 6216) & 1) )
    UFG::qString::Set(&v0->mpSnapshots[0]->mStrings[8].mValue, v75.mData, v75.mLength, 0i64, 0);
  UFG::qString::~qString(&v75);
  UFG::PersistentData::MapFloat::GetMaxMin(v0->mpSnapshots[0]->mpMapFloats[3], (UFG::qSymbol **)symGameSliceName, &min);
  v36 = (char *)UFG::GameStatAction::invalid_name;
  if ( *(_QWORD *)&symGameSliceName[0].mUID )
  {
    v37 = UFG::PropertySetManager::GetPropertySet(*(UFG::qSymbol **)&symGameSliceName[0].mUID);
    if ( v37 )
      v36 = PropertyUtils::Get<char const *>(v37, &sSymDescription, DEPTH_RECURSE);
  }
  UFG::qString::qString(&v75, v36);
  if ( !(*((_BYTE *)v0 + 6216) & 1) )
    UFG::qString::Set(&v0->mpSnapshots[0]->mStrings[9].mValue, v75.mData, v75.mLength, 0i64, 0);
  UFG::qString::~qString(&v75);
  v38 = (char *)UFG::GameStatAction::invalid_name;
  if ( min )
  {
    v39 = UFG::PropertySetManager::GetPropertySet(min);
    if ( v39 )
      v38 = PropertyUtils::Get<char const *>(v39, &sSymDescription, DEPTH_RECURSE);
  }
  UFG::qString::qString(&v75, v38);
  if ( !(*((_BYTE *)v0 + 6216) & 1) )
    UFG::qString::Set(&v0->mpSnapshots[0]->mStrings[10].mValue, v75.mData, v75.mLength, 0i64, 0);
  UFG::qString::~qString(&v75);
  UFG::PersistentData::MapFloat::GetMaxMin(v0->mpSnapshots[0]->mpMapFloats[4], (UFG::qSymbol **)symGameSliceName, &min);
  v40 = (char *)UFG::GameStatAction::invalid_name;
  if ( *(_QWORD *)&symGameSliceName[0].mUID )
  {
    v41 = UFG::PropertySetManager::GetPropertySet(*(UFG::qSymbol **)&symGameSliceName[0].mUID);
    if ( v41 )
      v40 = PropertyUtils::Get<char const *>(v41, &sSymDescription, DEPTH_RECURSE);
  }
  UFG::qString::qString(&v75, v40);
  if ( !(*((_BYTE *)v0 + 6216) & 1) )
    UFG::qString::Set(&v0->mpSnapshots[0]->mStrings[11].mValue, v75.mData, v75.mLength, 0i64, 0);
  UFG::qString::~qString(&v75);
  v42 = (char *)UFG::GameStatAction::invalid_name;
  if ( min )
  {
    v43 = UFG::PropertySetManager::GetPropertySet(min);
    if ( v43 )
      v42 = PropertyUtils::Get<char const *>(v43, &sSymDescription, DEPTH_RECURSE);
  }
  UFG::qString::qString(&v75, v42);
  if ( !(*((_BYTE *)v0 + 6216) & 1) )
    UFG::qString::Set(&v0->mpSnapshots[0]->mStrings[12].mValue, v75.mData, v75.mLength, 0i64, 0);
  UFG::qString::~qString(&v75);
  UFG::PersistentData::MapFloat::GetMaxMin(v0->mpSnapshots[0]->mpMapFloats[5], (UFG::qSymbol **)symGameSliceName, &min);
  v44 = (char *)UFG::GameStatAction::invalid_name;
  if ( *(_QWORD *)&symGameSliceName[0].mUID )
  {
    v45 = UFG::PropertySetManager::GetPropertySet(*(UFG::qSymbol **)&symGameSliceName[0].mUID);
    if ( v45 )
      v44 = PropertyUtils::Get<char const *>(v45, &sSymDescription, DEPTH_RECURSE);
  }
  UFG::qString::qString(&v75, v44);
  if ( !(*((_BYTE *)v0 + 6216) & 1) )
    UFG::qString::Set(&v0->mpSnapshots[0]->mStrings[13].mValue, v75.mData, v75.mLength, 0i64, 0);
  UFG::qString::~qString(&v75);
  v46 = (char *)UFG::GameStatAction::invalid_name;
  if ( min )
  {
    v47 = UFG::PropertySetManager::GetPropertySet(min);
    if ( v47 )
      v46 = PropertyUtils::Get<char const *>(v47, &sSymDescription, DEPTH_RECURSE);
  }
  UFG::qString::qString(&v75, v46);
  if ( !(*((_BYTE *)v0 + 6216) & 1) )
    UFG::qString::Set(&v0->mpSnapshots[0]->mStrings[14].mValue, v75.mData, v75.mLength, 0i64, 0);
  UFG::qString::~qString(&v75);
  UFG::PersistentData::MapInt::GetMaxMin(v0->mpSnapshots[0]->mpMapInts[28], (UFG::qSymbol **)symGameSliceName, &min);
  v48 = (char *)UFG::GameStatAction::invalid_name;
  if ( *(_QWORD *)&symGameSliceName[0].mUID )
  {
    v49 = UFG::PropertySetManager::GetPropertySet(*(UFG::qSymbol **)&symGameSliceName[0].mUID);
    if ( v49 )
      v48 = PropertyUtils::Get<char const *>(v49, &sSymDescription, DEPTH_RECURSE);
  }
  UFG::qString::qString(&v75, v48);
  if ( !(*((_BYTE *)v0 + 6216) & 1) )
    UFG::qString::Set(&v0->mpSnapshots[0]->mStrings[20].mValue, v75.mData, v75.mLength, 0i64, 0);
  UFG::qString::~qString(&v75);
  UFG::PersistentData::MapInt::GetMaxMin(v0->mpSnapshots[0]->mpMapInts[26], (UFG::qSymbol **)symGameSliceName, &min);
  v50 = (char *)UFG::GameStatAction::invalid_name;
  if ( *(_QWORD *)&symGameSliceName[0].mUID )
  {
    v51 = UFG::PropertySetManager::GetPropertySet(*(UFG::qSymbol **)&symGameSliceName[0].mUID);
    if ( v51 )
      v50 = PropertyUtils::Get<char const *>(v51, &sSymDescription, DEPTH_RECURSE);
  }
  UFG::qString::qString(&v75, v50);
  if ( !(*((_BYTE *)v0 + 6216) & 1) )
    UFG::qString::Set(&v0->mpSnapshots[0]->mStrings[21].mValue, v75.mData, v75.mLength, 0i64, 0);
  UFG::qString::~qString(&v75);
  v52 = 0.0;
  v53 = 0i64;
  v54 = v0->mpSnapshots[0];
  v55 = v54->mpMapInts[26];
  UFG::PersistentData::MapInt::GetIterator((UFG::PersistentData::MapFloat *)v54->mpMapInts[26], &result);
  v56 = result.mIndex;
  if ( result.mIndex < *(_DWORD *)v74 )
  {
    v57 = v54->mpMapInts[27];
    v58 = v57->mValues.size;
    v59 = v55->mValues.size;
    do
    {
      v60 = 0i64;
      if ( !v58 )
        goto LABEL_132;
      v61 = v57->mValues.p;
      while ( v61->mKey.mUID != *(_DWORD *)(*(_QWORD *)(v74 + 8) + 8i64 * v56) )
      {
        v60 = (unsigned int)(v60 + 1);
        ++v61;
        if ( (unsigned int)v60 >= v58 )
          goto LABEL_132;
      }
      if ( (_DWORD)v60 != -1 )
        v62 = v57->mValues.p[v60].mIntValue;
      else
LABEL_132:
        v62 = 0;
      v63 = 0i64;
      if ( !v59 )
        goto LABEL_140;
      v64 = v55->mValues.p;
      while ( v64->mKey.mUID != *(_DWORD *)(*(_QWORD *)(v74 + 8) + 8i64 * v56) )
      {
        v63 = (unsigned int)(v63 + 1);
        ++v64;
        if ( (unsigned int)v63 >= v59 )
          goto LABEL_140;
      }
      if ( (_DWORD)v63 != -1 )
        v65 = v55->mValues.p[v63].mIntValue;
      else
LABEL_140:
        v65 = 0;
      v66 = (float)v65;
      if ( (float)v65 < 1.0 )
        v66 = *(float *)&FLOAT_1_0;
      if ( (float)((float)v62 / v66) > v52 )
      {
        v53 = (UFG::qSymbol *)(*(_QWORD *)(v74 + 8) + 8i64 * v56);
        v52 = (float)v62 / v66;
      }
      ++v56;
    }
    while ( v56 < *(_DWORD *)v74 );
  }
  v67 = (char *)UFG::GameStatAction::invalid_name;
  if ( v53 )
  {
    v68 = UFG::PropertySetManager::GetPropertySet(v53);
    if ( v68 )
      v67 = PropertyUtils::Get<char const *>(v68, &sSymDescription, DEPTH_RECURSE);
  }
  UFG::qString::qString(&v75, v67);
  if ( !(*((_BYTE *)v0 + 6216) & 1) )
    UFG::qString::Set(&v0->mpSnapshots[0]->mStrings[19].mValue, v75.mData, v75.mLength, 0i64, 0);
  UFG::qString::~qString(&v75);
  UFG::qString::FormatEx(
    (UFG::qString *)&result,
    "%d / %d",
    (unsigned int)(v0->mpSnapshots[0]->mInts[22].mValue + v0->mpSnapshots[0]->mInts[23].mValue),
    12i64);
  UFG::qString::qString(&v75, format);
  if ( !(*((_BYTE *)v0 + 6216) & 1) )
    UFG::qString::Set(&v0->mpSnapshots[0]->mStrings[16].mValue, v75.mData, v75.mLength, 0i64, 0);
  UFG::qString::~qString(&v75);
  UFG::qString::~qString((UFG::qString *)&result);
  UFG::qString::FormatEx(
    (UFG::qString *)&result,
    "%d / %d",
    (unsigned int)(v0->mpSnapshots[0]->mInts[27].mValue + v0->mpSnapshots[0]->mInts[28].mValue),
    10i64);
  UFG::qString::qString(&v75, format);
  if ( !(*((_BYTE *)v0 + 6216) & 1) )
    UFG::qString::Set(&v0->mpSnapshots[0]->mStrings[17].mValue, v75.mData, v75.mLength, 0i64, 0);
  UFG::qString::~qString(&v75);
  UFG::qString::~qString((UFG::qString *)&result);
  UFG::qString::FormatEx(
    (UFG::qString *)&result,
    "%d / %d",
    (unsigned int)(v0->mpSnapshots[0]->mInts[24].mValue + v0->mpSnapshots[0]->mInts[25].mValue),
    10i64);
  UFG::qString::qString(&v75, format);
  if ( !(*((_BYTE *)v0 + 6216) & 1) )
    UFG::qString::Set(&v0->mpSnapshots[0]->mStrings[18].mValue, v75.mData, v75.mLength, 0i64, 0);
  UFG::qString::~qString(&v75);
  UFG::qString::~qString((UFG::qString *)&result);
  if ( !(*((_BYTE *)v0 + 6216) & 1) )
  {
    v0->mpSnapshots[0]->mInts[154].mValue = 0;
    if ( UFG::GameStatAction::PostStat::sIsEnabled )
      UFG::GameStatAction::PostStat::AchieveInt(PhotosSaved);
  }
  UFG::PersistentData::MapInt::GetIterator(
    (UFG::PersistentData::MapFloat *)v0->mpSnapshots[0]->mpMapBinaries[0],
    &result);
  v70 = v69;
  for ( i = result.mIndex; i < *(_DWORD *)v70; ++i )
  {
    if ( *(_QWORD *)(v70 + 8) + 8 * (3i64 * i + 1) )
    {
      if ( !(*((_BYTE *)v0 + 6216) & 1) )
      {
        ++v0->mpSnapshots[0]->mInts[154].mValue;
        if ( UFG::GameStatAction::PostStat::sIsEnabled )
          UFG::GameStatAction::PostStat::AchieveInt(PhotosSaved);
      }
    }
  }
  UFG::GameStatTracker::SetStat(
    v0,
    GamblingProfit,
    v0->mpSnapshots[0]->mInts[64].mValue - v0->mpSnapshots[0]->mInts[65].mValue);
  v72 = v0->mpSnapshots[0];
  v73 = v72->mInts[51].mValue;
  if ( v73 )
  {
    if ( (float)v73 >= 1.0 )
      v2 = (float)v73;
    v17 = (float)((float)(v72->mInts[51].mValue - v72->mInts[52].mValue) * 100.0) / v2;
  }
  if ( !(*((_BYTE *)v0 + 6216) & 1) )
    v72->mFloats[119].mValue = v17;
  UFG::GameStatTracker::SetStat(
    v0,
    BuffsPurchased,
    v0->mpSnapshots[0]->mInts[79].mValue
  + v0->mpSnapshots[0]->mInts[80].mValue
  + v0->mpSnapshots[0]->mInts[81].mValue
  + v0->mpSnapshots[0]->mInts[82].mValue);
}

