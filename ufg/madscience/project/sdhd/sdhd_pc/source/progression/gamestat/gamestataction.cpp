// File Line: 131
// RVA: 0x1530180
__int64 UFG::_dynamic_initializer_for__sSym_CombatFish__()
{
  UFG::qSymbol::create_from_string(&sSym_CombatFish, "object-physical-weapon-melee-CombatFish001");
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__sSym_CombatFish__);
}

// File Line: 139
// RVA: 0x15300C0
__int64 UFG::GameStatAction::_dynamic_initializer_for__sFaceEventSymbol_FaceTypeGained__()
{
  UFG::qSymbol::create_from_string(&sFaceEventSymbol_FaceTypeGained, "FaceGained");
  return atexit((int (__fastcall *)())UFG::GameStatAction::_dynamic_atexit_destructor_for__sFaceEventSymbol_FaceTypeGained__);
}

// File Line: 140
// RVA: 0x1530120
__int64 UFG::GameStatAction::_dynamic_initializer_for__sFaceEventSymbol_FaceTypeUsed__()
{
  UFG::qSymbol::create_from_string(&sFaceEventSymbol_FaceTypeUsed, "FaceUsed");
  return atexit((int (__fastcall *)())UFG::GameStatAction::_dynamic_atexit_destructor_for__sFaceEventSymbol_FaceTypeUsed__);
}

// File Line: 141
// RVA: 0x15300F0
__int64 UFG::GameStatAction::_dynamic_initializer_for__sFaceEventSymbol_FaceTypeLost__()
{
  UFG::qSymbol::create_from_string(&sFaceEventSymbol_FaceTypeLost, "FaceLost");
  return atexit((int (__fastcall *)())UFG::GameStatAction::_dynamic_atexit_destructor_for__sFaceEventSymbol_FaceTypeLost__);
}

// File Line: 142
// RVA: 0x1530150
__int64 UFG::GameStatAction::_dynamic_initializer_for__sSymDescription__()
{
  UFG::qSymbol::create_from_string(&sSymDescription, "Description");
  return atexit((int (__fastcall *)())UFG::GameStatAction::_dynamic_atexit_destructor_for__sSymDescription__);
}

// File Line: 144
// RVA: 0x152C100
__int64 UFG::GameStatAction::_dynamic_initializer_for__gMissionSymbol_M_VE__()
{
  UFG::qSymbol::create_from_string(&gMissionSymbol_M_VE, "M_VE");
  return atexit((int (__fastcall *)())UFG::GameStatAction::_dynamic_atexit_destructor_for__gMissionSymbol_M_VE__);
}

// File Line: 154
// RVA: 0x499B60
void __fastcall UFG::GameStatAction::MiniGame::Completed(UFG::MiniGameType e)
{
  unsigned int v2; // edx
  UFG::GameStatTracker *v3; // rbx
  UFG::GameStatTracker *v4; // r8
  __int32 v5; // edi
  UFG::qSymbol mapid; // [rsp+40h] [rbp+8h] BYREF
  UFG::qSymbol *p_mapid; // [rsp+48h] [rbp+10h]

  v2 = _S12_6;
  v3 = &sGameStatTracker;
  if ( (_S12_6 & 1) == 0 )
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
  v5 = e | v4->mpSnapshots[0]->mInts[48].mValue;
  if ( (v2 & 1) == 0 )
  {
    _S12_6 = v2 | 1;
    UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
    atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
    v4 = UFG::GameStatTracker::mspInstance;
  }
  if ( v4 )
    v3 = v4;
  UFG::GameStatTracker::mspInstance = v3;
  if ( (*((_BYTE *)v3 + 6216) & 1) == 0 )
  {
    v3->mpSnapshots[0]->mInts[48].mValue = v5;
    p_mapid = &mapid;
    mapid.mUID = UFG::gNullQSymbol.mUID;
    UFG::GameStatAction::PostStat::Achieve(PDT_INT, MiniGamePlayed, &mapid.mUID);
  }
  if ( v5 == 31 )
    UFG::AchievementTrophyManager::UnlockAchievementTrophy(15);
}

// File Line: 172
// RVA: 0x4AD1D0
void __fastcall UFG::GameStatAction::MiniGame::KaraokeSongCompleted(
        unsigned int songid,
        unsigned int score,
        unsigned int num_of_songs)
{
  UFG::GameStatTracker *v6; // rdi
  UFG::GameStatTracker *v7; // rbx
  UFG::qWiseSymbol *v8; // rax
  UFG::PersistentData::MapInt *v9; // r9
  unsigned int size; // r8d
  int v11; // ebx
  unsigned int v12; // ecx
  UFG::PersistentData::KeyValue *p; // r9
  unsigned int mUID; // edx
  UFG::PersistentData::KeyValue *v15; // rax
  unsigned int mIntValue; // ecx
  UFG::qSymbol *v17; // rbp
  UFG::GameStatTracker *v18; // rax
  unsigned int v19; // ecx
  UFG::GameStatTracker *v20; // rdx
  $CCFB32CF948EEB04FF452B3FEB4ECF53 *v21; // rdx
  __int64 v22; // rcx
  UFG::PersistentData::MapFloat::Iterator v23; // [rsp+28h] [rbp-30h] BYREF
  UFG::qWiseSymbol result; // [rsp+68h] [rbp+10h] BYREF

  v6 = &sGameStatTracker;
  if ( (_S12_6 & 1) == 0 )
  {
    _S12_6 |= 1u;
    UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
    atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
  }
  v7 = &sGameStatTracker;
  if ( UFG::GameStatTracker::mspInstance )
    v7 = UFG::GameStatTracker::mspInstance;
  UFG::GameStatTracker::mspInstance = v7;
  v8 = UFG::qSymbol::qSymbol(&result, songid);
  v9 = v7->mpSnapshots[0]->mpMapInts[0];
  size = v9->mValues.size;
  v11 = 0;
  v12 = 0;
  if ( !v9->mValues.size )
    goto LABEL_12;
  p = v9->mValues.p;
  mUID = v8->mUID;
  v15 = p;
  while ( v15->mKey.mUID != mUID )
  {
    ++v12;
    ++v15;
    if ( v12 >= size )
      goto LABEL_12;
  }
  if ( v12 == -1 )
LABEL_12:
    mIntValue = 0;
  else
    mIntValue = p[v12].mIntValue;
  if ( (score > mIntValue && score != 111 || mIntValue == 111 && score)
    && (v17 = (UFG::qSymbol *)UFG::qSymbol::qSymbol(&result, songid),
        v18 = UFG::GameStatTracker::Instance(),
        (*((_BYTE *)v18 + 6216) & 1) == 0)
    && (UFG::PersistentData::MapInt::SetStatus(v18->mpSnapshots[0]->mpMapInts[0], v17, score),
        UFG::GameStatAction::PostStat::sIsEnabled) )
  {
    v19 = _S12_6;
    if ( (_S12_6 & 1) == 0 )
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
  if ( (v19 & 1) == 0 )
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
    v21 = &v23.mList->mValues.p[v23.mIndex].4;
    v22 = v23.mList->mValues.size - v23.mIndex;
    do
    {
      if ( v21->mIntValue >= 0x5Au && v21->mIntValue <= 100 )
        ++v11;
      v21 += 2;
      --v22;
    }
    while ( v22 );
  }
  if ( v11 == num_of_songs )
    UFG::AchievementTrophyManager::UnlockAchievementTrophy(35);
}

// File Line: 212
// RVA: 0x4C9110
void __fastcall UFG::GameStatAction::Bike::WheelieDistance(float wheelie_dist)
{
  UFG::GameStatTracker *v1; // rax
  UFG::GameSnapshot *v2; // rax
  UFG::OSuiteLeaderboardManager *v3; // rax
  UFG::OSuiteLeaderboardData *LeaderboardDataUsingLeaderboardName; // rax

  if ( wheelie_dist > 0.001 )
  {
    UFG::GameStatTracker::Instance();
    v1 = UFG::GameStatTracker::Instance();
    if ( (*((_BYTE *)v1 + 6216) & 1) == 0 )
    {
      v2 = v1->mpSnapshots[0];
      if ( wheelie_dist > v2->mFloats[88].mValue )
        v2->mFloats[88].mValue = wheelie_dist;
    }
    v3 = UFG::OSuiteLeaderboardManager::Instance();
    LeaderboardDataUsingLeaderboardName = UFG::OSuiteLeaderboardManager::GetLeaderboardDataUsingLeaderboardName(
                                            v3,
                                            "StatGamesWheelieDistance");
    UFG::StatGameManager::EndStatGame(LeaderboardDataUsingLeaderboardName, (int)(float)(wheelie_dist * 1000.0));
  }
}

// File Line: 232
// RVA: 0x4B0E10
void __fastcall UFG::GameStatAction::Vehicle::Mount(
        bool bIsDriver,
        UFG::eSimObjectVehicleTypeEnum vehicle,
        UFG::eTargetTypeEnum target,
        UFG::SimObjectGame *pSimObject)
{
  UFG::GameStatTracker *v6; // rdi
  UFG::GameStatTracker *v7; // rbx
  UFG::SimpleTimer *v8; // rbx
  UFG::GameStatTracker *v9; // rcx
  UFG::GameStatTracker *v10; // rax
  signed __int16 m_Flags; // cx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::GameStatTracker *v13; // rax
  UFG::qString v14; // [rsp+38h] [rbp-40h] BYREF
  UFG::qSymbol mapid; // [rsp+80h] [rbp+8h] BYREF
  UFG::qSymbol *p_mapid; // [rsp+98h] [rbp+20h]

  v6 = &sGameStatTracker;
  if ( (_S12_6 & 1) == 0 )
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
  if ( (_S12_6 & 1) == 0 )
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
  if ( (_S12_6 & 1) == 0 )
  {
    _S12_6 |= 1u;
    UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
    atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
  }
  if ( UFG::GameStatTracker::mspInstance )
    v6 = UFG::GameStatTracker::mspInstance;
  UFG::GameStatTracker::mspInstance = v6;
  if ( (*((_BYTE *)v6 + 6216) & 1) == 0 )
  {
    v6->mpSnapshots[0]->mInts[162].mValue = 0;
    p_mapid = &mapid;
    mapid.mUID = UFG::gNullQSymbol.mUID;
    UFG::GameStatAction::PostStat::Achieve(PDT_INT, CurrentVehicleKills, &mapid.mUID);
  }
  if ( UFG::RadioFullyControlled::sm_playerRadio )
  {
    UFG::qString::qString(&v14, UFG::RadioFullyControlled::sm_playerRadio->m_curStation->m_name);
    v10 = UFG::GameStatTracker::Instance();
    if ( (*((_BYTE *)v10 + 6216) & 1) == 0 )
      UFG::qString::Set(&v10->mpSnapshots[0]->mStrings[23].mValue, v14.mData, v14.mLength, 0i64, 0);
    UFG::qString::~qString(&v14);
  }
  if ( pSimObject )
  {
    m_Flags = pSimObject->m_Flags;
    if ( (m_Flags & 0x4000) == 0 )
    {
      if ( m_Flags >= 0 )
      {
        if ( (m_Flags & 0x2000) != 0 )
          goto LABEL_29;
        if ( (m_Flags & 0x1000) != 0 )
          ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(pSimObject, UFG::PhysicsMoverInterface::_TypeUID);
        else
          ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(pSimObject, UFG::PhysicsMoverInterface::_TypeUID);
      }
      else
      {
        ComponentOfTypeHK = pSimObject->m_Components.p[34].m_pComponent;
      }
      if ( ComponentOfTypeHK )
        LODWORD(ComponentOfTypeHK[10].m_BoundComponentHandles.mNode.mNext) = 0;
    }
  }
LABEL_29:
  if ( !bIsDriver )
  {
    if ( UFG::SimObjectUtility::IsClassType(pSimObject, &qSymbol_Taxi) )
    {
      v13 = UFG::GameStatTracker::Instance();
      UFG::SimpleTimer::Resume((UFG::SimpleTimer *)v13->mpSnapshots[0]);
    }
  }
}

// File Line: 256
// RVA: 0x49D500
void __fastcall UFG::GameStatAction::Vehicle::Dismount(
        bool bIsDriver,
        UFG::eSimObjectVehicleTypeEnum vehicle,
        UFG::eTargetTypeEnum target,
        UFG::SimObjectGame *pSimObject)
{
  UFG::GameStatTracker *v7; // rbx
  UFG::GameStatTracker *v8; // rcx
  UFG::GameStatTracker *v9; // rcx
  UFG::GameStatTracker *v10; // rcx
  float ElapsedSeconds; // xmm0_4
  float v12; // xmm6_4
  int mUID; // r15d
  char m_Flags; // r12
  UFG::SimComponent *ComponentOfType; // rax
  signed __int16 v16; // cx
  UFG::PhysicsMoverInterface *m_pComponent; // rdi
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::WaterFloatingTrackerComponent *mWaterFloatingTrackerComponent; // r14
  UFG::SceneObjectProperties *m_pSceneObj; // rcx
  UFG::qSymbol *ArchetypePropertiesName; // r14
  int v22; // esi
  int v23; // esi
  UFG::RadioFullyControlled *v24; // rsi
  UFG::OSuiteDBLogger *v25; // rbx
  UFG::GameStatTracker *v26; // rax
  UFG::GameStatTracker *v27; // rax
  UFG::qString v28; // [rsp+30h] [rbp-88h] BYREF
  UFG::qString v29; // [rsp+58h] [rbp-60h] BYREF

  v7 = &sGameStatTracker;
  if ( (_S12_6 & 1) == 0 )
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
  if ( (_S12_6 & 1) == 0 )
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
  if ( (_S12_6 & 1) == 0 )
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
  if ( (_S12_6 & 1) == 0 )
  {
    _S12_6 |= 1u;
    UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
    atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
  }
  if ( UFG::GameStatTracker::mspInstance )
    v7 = UFG::GameStatTracker::mspInstance;
  UFG::GameStatTracker::mspInstance = v7;
  if ( bIsDriver )
  {
    ElapsedSeconds = UFG::SimpleTimer::GetElapsedSeconds(&v7->mpSnapshots[0]->mTimes[17].mTimer);
    v12 = ElapsedSeconds;
    UFG::qString::qString(&v28, "OK");
    UFG::qString::qString(&v29, "Exit");
    mUID = 0;
    m_Flags = 0;
    if ( !pSimObject )
    {
      m_pComponent = 0i64;
      goto LABEL_58;
    }
    ComponentOfType = UFG::SimObject::GetComponentOfType(pSimObject, UFG::SimObjectVehiclePropertiesComponent::_TypeUID);
    if ( ComponentOfType )
      m_Flags = ComponentOfType[3].m_Flags;
    v16 = pSimObject->m_Flags;
    if ( (v16 & 0x4000) != 0 )
    {
      m_pComponent = 0i64;
    }
    else
    {
      if ( v16 >= 0 )
      {
        if ( (v16 & 0x2000) != 0 )
        {
          m_pComponent = 0i64;
          goto LABEL_45;
        }
        if ( (v16 & 0x1000) != 0 )
          ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(pSimObject, UFG::PhysicsMoverInterface::_TypeUID);
        else
          ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(pSimObject, UFG::PhysicsMoverInterface::_TypeUID);
        m_pComponent = (UFG::PhysicsMoverInterface *)ComponentOfTypeHK;
      }
      else
      {
        m_pComponent = (UFG::PhysicsMoverInterface *)pSimObject->m_Components.p[34].m_pComponent;
      }
      if ( m_pComponent )
      {
        if ( (*((_BYTE *)v7 + 6216) & 1) == 0 )
        {
          v7->mpSnapshots[0]->mFloats[0].mValue = (float)(m_pComponent->mOdometer * 0.001)
                                                + v7->mpSnapshots[0]->mFloats[0].mValue;
          if ( (*((_BYTE *)v7 + 6216) & 1) == 0 )
            v7->mpSnapshots[0]->mFloats[1].mValue = ElapsedSeconds + v7->mpSnapshots[0]->mFloats[1].mValue;
        }
        mWaterFloatingTrackerComponent = m_pComponent->mPhysicsVehicle->mWaterFloatingTrackerComponent;
        if ( UFG::PhysicsMoverInterface::GetEngineDamage(m_pComponent) < 1.0 )
        {
          if ( mWaterFloatingTrackerComponent )
          {
            if ( UFG::WaterFloatingTrackerComponent::IsInWater(mWaterFloatingTrackerComponent) )
            {
              UFG::qString::Format(&v28, "In Water");
              goto LABEL_45;
            }
            if ( UFG::WaterFloatingTrackerComponent::IsSunk(mWaterFloatingTrackerComponent) )
            {
              UFG::qString::Format(&v28, "Submerged");
              goto LABEL_45;
            }
          }
          if ( UFG::PhysicsMoverInterface::GetEngineDamage(m_pComponent) < 1.0
            && UFG::PhysicsMoverInterface::GetEngineDamage(m_pComponent) > 0.0 )
          {
            UFG::qString::Format(&v28, "Damaged");
          }
        }
        else
        {
          UFG::qString::Format(&v28, "Wrecked");
          UFG::qString::Format(&v29, "Death");
        }
      }
    }
LABEL_45:
    m_pSceneObj = pSimObject->m_pSceneObj;
    if ( m_pSceneObj )
    {
      ArchetypePropertiesName = UFG::SceneObjectProperties::GetArchetypePropertiesName(m_pSceneObj);
      if ( ArchetypePropertiesName->mUID != UFG::gNullQSymbol.mUID )
      {
        mUID = ArchetypePropertiesName->mUID;
        v22 = vehicle - 1;
        if ( v22 )
        {
          v23 = v22 - 1;
          if ( v23 )
          {
            if ( v23 != 1 )
            {
LABEL_60:
              UFG::qString::~qString(&v29);
              UFG::qString::~qString(&v28);
              return;
            }
            UFG::GameStatTracker::ApplyDelta(v7, TimeOnBoatList, ArchetypePropertiesName, v12);
            if ( (*((_BYTE *)v7 + 6216) & 1) == 0 )
              v7->mpSnapshots[0]->mFloats[107].mValue = v12 + v7->mpSnapshots[0]->mFloats[107].mValue;
          }
          else if ( (*((_BYTE *)v7 + 6216) & 1) == 0 )
          {
            UFG::PersistentData::MapFloat::ApplyDelta(v7->mpSnapshots[0]->mpMapFloats[3], ArchetypePropertiesName, v12);
            if ( (*((_BYTE *)v7 + 6216) & 1) == 0 )
              v7->mpSnapshots[0]->mFloats[105].mValue = v12 + v7->mpSnapshots[0]->mFloats[105].mValue;
          }
        }
        else
        {
          UFG::GameStatTracker::ApplyDelta(v7, TimeOnBikeList, ArchetypePropertiesName, v12);
          if ( (*((_BYTE *)v7 + 6216) & 1) == 0 )
            v7->mpSnapshots[0]->mFloats[106].mValue = v12 + v7->mpSnapshots[0]->mFloats[106].mValue;
        }
      }
    }
LABEL_58:
    v24 = UFG::RadioFullyControlled::sm_playerRadio;
    v25 = UFG::OSuiteDBLogger::Instance();
    if ( UFG::OSuiteDBLogger::CreateMetric(v25, "VehicleExit") )
    {
      UFG::OSuiteDBLogger::AddValue(v25, "IsGarageVehicle", m_Flags);
      UFG::OSuiteDBLogger::AddValue(v25, "Exit", v29.mData);
      UFG::OSuiteDBLogger::AddValue(v25, "VehicleState", v28.mData);
      UFG::OSuiteDBLogger::AddValue(v25, "Vehicle", mUID);
      UFG::OSuiteDBLogger::AddValue(v25, "Distance", m_pComponent->mOdometer * 0.001);
      UFG::OSuiteDBLogger::AddValue(v25, "Time", v12);
      v26 = UFG::GameStatTracker::Instance();
      UFG::OSuiteDBLogger::AddValue(v25, "Kills", v26->mpSnapshots[0]->mInts[162].mValue);
      v27 = UFG::GameStatTracker::Instance();
      UFG::OSuiteDBLogger::AddValue(v25, "RadioStationEnter", v27->mpSnapshots[0]->mStrings[23].mValue.mData);
      UFG::OSuiteDBLogger::AddValue(v25, "RadioStationExit", v24->m_curStation->m_name);
      UFG::OSuiteDBLogger::SubmitMetric(v25, 1);
    }
    goto LABEL_60;
  }
}hots[0]->mStrings[23].mValue.mData);
      UFG::OSuiteDBLogger::AddValue(v25, 

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
      if ( (*((_BYTE *)v4 + 6216) & 1) == 0 )
      {
        v5 = v4->mpSnapshots[0];
        if ( height > v5->mFloats[90].mValue )
          v5->mFloats[90].mValue = height;
      }
    }
    else if ( numWheels == 4 )
    {
      v2 = UFG::GameStatTracker::Instance();
      if ( (*((_BYTE *)v2 + 6216) & 1) == 0 )
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
    if ( (*((_BYTE *)v6 + 6216) & 1) == 0 )
    {
      v7 = v6->mpSnapshots[0];
      if ( height > v7->mFloats[91].mValue )
        v7->mFloats[91].mValue = height;
    }
  }
}

// File Line: 361
// RVA: 0x4BCD80
void __fastcall UFG::GameStatAction::Vehicle::SetLongestJump(UFG::SimObjectCVBase *pVehicle, float dist)
{
  UFG::SimObjectVehiclePropertiesComponent *ComponentOfTypeHK; // rax
  signed __int16 m_Flags; // dx
  UFG::GameStatTracker *v4; // rax
  UFG::GameSnapshot *v5; // rax
  UFG::OSuiteLeaderboardManager *v6; // rax
  const char *v7; // rdx
  UFG::GameStatTracker *v8; // rax
  UFG::GameSnapshot *v9; // rax
  UFG::OSuiteLeaderboardData *LeaderboardDataUsingLeaderboardName; // rax

  if ( pVehicle )
  {
    m_Flags = pVehicle->m_Flags;
    if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
    {
      ComponentOfTypeHK = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectVehiclePropertiesComponent>(pVehicle);
    }
    else if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
    {
      ComponentOfTypeHK = (UFG::SimObjectVehiclePropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                        pVehicle,
                                                                        UFG::SimObjectVehiclePropertiesComponent::_TypeUID);
    }
    else
    {
      ComponentOfTypeHK = (UFG::SimObjectVehiclePropertiesComponent *)UFG::SimObject::GetComponentOfType(
                                                                        pVehicle,
                                                                        UFG::SimObjectVehiclePropertiesComponent::_TypeUID);
    }
  }
  else
  {
    ComponentOfTypeHK = 0i64;
  }
  switch ( ComponentOfTypeHK->m_eSimObjectVehicleType )
  {
    case eSIM_OBJ_VEHICLE_TYPE_BIKE:
    case eSIM_OBJ_VEHICLE_TYPE_SCOOTER:
      v4 = UFG::GameStatTracker::Instance();
      if ( (*((_BYTE *)v4 + 6216) & 1) == 0 )
      {
        v5 = v4->mpSnapshots[0];
        if ( dist > v5->mFloats[93].mValue )
          v5->mFloats[93].mValue = dist;
      }
      v6 = UFG::OSuiteLeaderboardManager::Instance();
      v7 = "StatGamesBikeJump";
      goto LABEL_19;
    case eSIM_OBJ_VEHICLE_TYPE_CAR:
    case eSIM_OBJ_VEHICLE_TYPE_VAN:
    case eSIM_OBJ_VEHICLE_TYPE_TRUCK:
      v8 = UFG::GameStatTracker::Instance();
      if ( (*((_BYTE *)v8 + 6216) & 1) == 0 )
      {
        v9 = v8->mpSnapshots[0];
        if ( dist > v9->mFloats[92].mValue )
          v9->mFloats[92].mValue = dist;
      }
      v6 = UFG::OSuiteLeaderboardManager::Instance();
      v7 = "StatGamesCarJump";
LABEL_19:
      LeaderboardDataUsingLeaderboardName = UFG::OSuiteLeaderboardManager::GetLeaderboardDataUsingLeaderboardName(
                                              v6,
                                              v7);
      UFG::StatGameManager::EndStatGame(LeaderboardDataUsingLeaderboardName, (int)(float)(dist * 1000.0));
      break;
    default:
      return;
  }
}

// File Line: 388
// RVA: 0x4C2BD0
void __fastcall UFG::GameStatAction::Vehicle::TireHit(UFG::SimObjectCharacter *shooter, UFG::SimObjectCVBase *car)
{
  signed __int16 m_Flags; // cx
  UFG::SimComponent *m_pComponent; // rdi
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::SimObjectCVBase *Texture; // rax
  UFG::SimComponent *v8; // rdi
  UFG::SimComponent *v9; // rsi
  signed __int16 v10; // cx
  UFG::SimComponent *ComponentOfType; // rax
  signed __int16 v12; // cx
  UFG::SimComponent *v13; // rax
  UFG::GameStatTracker *v14; // rax
  UFG::GameStatTracker *v15; // rbx
  UFG::GameStatTracker *v16; // rcx
  UFG::OSuiteLeaderboardManager *v17; // rax
  UFG::OSuiteLeaderboardData *LeaderboardDataUsingLeaderboardName; // rax
  UFG::GameStatTracker *v19; // rax
  UFG::CopSystem *v20; // rax
  bool pIsCop; // [rsp+40h] [rbp+8h] BYREF
  bool pIsAmbient; // [rsp+50h] [rbp+18h] BYREF

  if ( shooter != UFG::GetLocalPlayer() )
    return;
  pIsCop = 0;
  pIsAmbient = 0;
  UFG::GameStatAction::MissionScoring::DeduceFaction(car, &pIsCop, &pIsAmbient);
  if ( pIsCop || pIsAmbient )
  {
    UFG::GameStatAction::MissionScoring::LogCopEvent(COP_VEHICLE_TIRE_SHOT, 0, &customCaption);
  }
  else if ( car )
  {
    m_Flags = car->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
      goto LABEL_11;
    if ( m_Flags < 0 )
    {
      m_pComponent = car->m_Components.p[30].m_pComponent;
LABEL_14:
      if ( m_pComponent )
      {
        if ( Scaleform::Render::RBGenericImpl::RenderTarget::GetTexture((hkSimpleLocalFrame *)m_pComponent) )
        {
          Texture = (UFG::SimObjectCVBase *)Scaleform::Render::RBGenericImpl::RenderTarget::GetTexture((hkSimpleLocalFrame *)m_pComponent);
          if ( !UFG::AreCharactersAllied(shooter, Texture) )
            UFG::GameStatAction::MissionScoring::LogTriadEvent(TRIAD_VEHICLE_TIRE_SHOT, 0, &customCaption);
        }
      }
      goto LABEL_19;
    }
    if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
LABEL_11:
      ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(car, UFG::VehicleOccupantComponent::_TypeUID);
    else
      ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(car, UFG::VehicleOccupantComponent::_TypeUID);
    m_pComponent = ComponentOfTypeHK;
    goto LABEL_14;
  }
LABEL_19:
  v8 = 0i64;
  if ( shooter )
  {
    v10 = shooter->m_Flags;
    if ( (v10 & 0x4000) != 0 )
    {
      v9 = shooter->m_Components.p[44].m_pComponent;
    }
    else
    {
      if ( v10 < 0 || (v10 & 0x2000) != 0 || (v10 & 0x1000) != 0 )
        ComponentOfType = UFG::SimObjectGame::GetComponentOfTypeHK(shooter, UFG::CharacterOccupantComponent::_TypeUID);
      else
        ComponentOfType = UFG::SimObject::GetComponentOfType(shooter, UFG::CharacterOccupantComponent::_TypeUID);
      v9 = ComponentOfType;
    }
  }
  else
  {
    v9 = 0i64;
  }
  if ( !car )
    goto LABEL_40;
  v12 = car->m_Flags;
  if ( (v12 & 0x4000) != 0 )
    goto LABEL_37;
  if ( v12 < 0 )
  {
    v8 = car->m_Components.p[30].m_pComponent;
    goto LABEL_40;
  }
  if ( (v12 & 0x2000) != 0 || (v12 & 0x1000) != 0 )
LABEL_37:
    v13 = UFG::SimObjectGame::GetComponentOfTypeHK(car, UFG::VehicleOccupantComponent::_TypeUID);
  else
    v13 = UFG::SimObject::GetComponentOfType(car, UFG::VehicleOccupantComponent::_TypeUID);
  v8 = v13;
LABEL_40:
  v14 = UFG::GameStatTracker::Instance();
  v15 = &sGameStatTracker;
  if ( (*((_BYTE *)v14 + 6216) & 1) == 0 )
  {
    ++v14->mpSnapshots[0]->mInts[96].mValue;
    if ( UFG::GameStatAction::PostStat::sIsEnabled )
    {
      if ( (_S12_6 & 1) == 0 )
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
        LeaderboardDataUsingLeaderboardName = UFG::OSuiteLeaderboardManager::GetLeaderboardDataUsingLeaderboardName(
                                                v17,
                                                "StatGamesTireShots");
        UFG::StatGameManager::UpdateScore(LeaderboardDataUsingLeaderboardName, 1, 1);
        v19 = UFG::GameStatTracker::Instance();
        if ( (*((_BYTE *)v19 + 6216) & 1) == 0 )
        {
          ++v19->mpSnapshots[0]->mInts[97].mValue;
          if ( UFG::GameStatAction::PostStat::sIsEnabled )
          {
            if ( (_S12_6 & 1) == 0 )
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
  if ( ((int (__fastcall *)(UFG::CopSystem *))v20->vfptr[89].__vecDelDtor)(v20) > 0 && pIsCop )
  {
    if ( v8 )
      UFG::AchievementTrophyManager::UnlockAchievementTrophy(22);
  }
}

// File Line: 455
// RVA: 0x49FDF0
void __fastcall UFG::GameStatAction::Vehicle::Explosion(UFG::SimObjectCVBase *car)
{
  UFG::SimObjectCharacter *v2; // rsi
  signed __int16 m_Flags; // cx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  __int64 v5; // rcx
  __int16 v6; // cx
  unsigned int v7; // edx
  UFG::SimObjectGame *v8; // rcx
  UFG::SimComponent *ComponentOfType; // rax
  hkSimpleLocalFrame *m_pComponent; // rbx
  bool v11; // zf
  UFG::SimObjectCharacter *Texture; // rbx
  unsigned int v13; // ecx
  UFG::GameStatTracker *v14; // rbx
  UFG::GameStatTracker *v15; // rdx
  signed __int16 v16; // cx
  UFG::SimComponent *v17; // rbx
  UFG::SimComponent *v18; // rax
  UFG::SimObjectCVBase *v19; // rbx
  UFG::SimObjectCharacter *LocalPlayer; // rax
  UFG::SimComponent *v21; // rax
  signed __int16 v22; // cx
  UFG::allocator::free_link *v23; // rsi
  const char *mName; // rdi
  unsigned int mUID; // ebx
  UFG::SimObjectCharacter *v26; // rax
  UFG::allocator::free_link *pIsCop; // [rsp+40h] [rbp+8h] BYREF
  bool pIsAmbient; // [rsp+48h] [rbp+10h] BYREF

  v2 = 0i64;
  if ( !car
    || ((m_Flags = car->m_Flags, (m_Flags & 0x4000) == 0)
      ? (m_Flags >= 0
       ? ((m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
        ? (ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(car, UFG::HitReactionComponent::_TypeUID))
        : (ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(car, UFG::HitReactionComponent::_TypeUID)))
       : (ComponentOfTypeHK = car->m_Components.p[15].m_pComponent))
      : (ComponentOfTypeHK = car->m_Components.p[15].m_pComponent),
        !ComponentOfTypeHK || (v5 = *(_QWORD *)&ComponentOfTypeHK[3].m_TypeUID) == 0) )
  {
    m_pComponent = 0i64;
    goto LABEL_22;
  }
  v2 = *(UFG::SimObjectCharacter **)&ComponentOfTypeHK[3].m_TypeUID;
  v6 = *(_WORD *)(v5 + 76);
  if ( (v6 & 0x4000) != 0 )
    goto LABEL_13;
  if ( v6 < 0 )
  {
    m_pComponent = (hkSimpleLocalFrame *)v2->m_Components.p[30].m_pComponent;
    goto LABEL_22;
  }
  if ( (v6 & 0x2000) != 0 )
  {
LABEL_13:
    v7 = UFG::VehicleOccupantComponent::_TypeUID;
    v8 = *(UFG::SimObjectGame **)&ComponentOfTypeHK[3].m_TypeUID;
  }
  else
  {
    v7 = UFG::VehicleOccupantComponent::_TypeUID;
    v11 = (v6 & 0x1000) == 0;
    v8 = *(UFG::SimObjectGame **)&ComponentOfTypeHK[3].m_TypeUID;
    if ( v11 )
    {
      ComponentOfType = UFG::SimObject::GetComponentOfType(v2, UFG::VehicleOccupantComponent::_TypeUID);
      goto LABEL_15;
    }
  }
  ComponentOfType = UFG::SimObjectGame::GetComponentOfTypeHK(v8, v7);
LABEL_15:
  m_pComponent = (hkSimpleLocalFrame *)ComponentOfType;
LABEL_22:
  if ( v2 != UFG::GetLocalPlayer() )
  {
    if ( !m_pComponent )
      return;
    Texture = (UFG::SimObjectCharacter *)Scaleform::Render::RBGenericImpl::RenderTarget::GetTexture(m_pComponent);
    if ( Texture != UFG::GetLocalPlayer() )
      return;
  }
  v13 = _S12_6;
  v14 = &sGameStatTracker;
  if ( (_S12_6 & 1) == 0 )
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
  if ( (*((_BYTE *)v15 + 6216) & 1) == 0 )
  {
    ++v15->mpSnapshots[0]->mInts[98].mValue;
    if ( UFG::GameStatAction::PostStat::sIsEnabled )
    {
      if ( (v13 & 1) == 0 )
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
  UFG::GameStatAction::MissionScoring::DeduceFaction(car, (bool *)&pIsCop, &pIsAmbient);
  if ( !(_BYTE)pIsCop )
  {
    if ( !pIsAmbient )
    {
      if ( !car )
      {
LABEL_52:
        UFG::GameStatAction::MissionScoring::LogTriadEvent(TRIAD_VEHICLE_DESTROY, 0, &customCaption);
        goto LABEL_54;
      }
      v16 = car->m_Flags;
      if ( (v16 & 0x4000) != 0 )
        goto LABEL_45;
      if ( v16 < 0 )
      {
        v17 = car->m_Components.p[30].m_pComponent;
LABEL_48:
        if ( v17 )
        {
          if ( Scaleform::Render::RBGenericImpl::RenderTarget::GetTexture((hkSimpleLocalFrame *)v17) )
          {
            v19 = (UFG::SimObjectCVBase *)Scaleform::Render::RBGenericImpl::RenderTarget::GetTexture((hkSimpleLocalFrame *)v17);
            if ( v19 )
            {
              LocalPlayer = UFG::GetLocalPlayer();
              if ( UFG::AreCharactersAllied(LocalPlayer, v19) )
                goto LABEL_54;
            }
          }
        }
        goto LABEL_52;
      }
      if ( (v16 & 0x2000) != 0 || (v16 & 0x1000) != 0 )
LABEL_45:
        v18 = UFG::SimObjectGame::GetComponentOfTypeHK(car, UFG::VehicleOccupantComponent::_TypeUID);
      else
        v18 = UFG::SimObject::GetComponentOfType(car, UFG::VehicleOccupantComponent::_TypeUID);
      v17 = v18;
      goto LABEL_48;
    }
    UFG::GameStatAction::MissionScoring::LogCopEvent(COP_VEHICLE_DESTROY, 0, &customCaption);
  }
LABEL_54:
  if ( car )
  {
    v22 = car->m_Flags;
    if ( (v22 & 0x4000) != 0 )
    {
      v21 = 0i64;
    }
    else if ( v22 >= 0 )
    {
      if ( (v22 & 0x2000) != 0 )
      {
        v21 = 0i64;
      }
      else if ( (v22 & 0x1000) != 0 )
      {
        v21 = UFG::SimObjectGame::GetComponentOfTypeHK(car, UFG::PhysicsMoverInterface::_TypeUID);
      }
      else
      {
        v21 = UFG::SimObject::GetComponentOfType(car, UFG::PhysicsMoverInterface::_TypeUID);
      }
    }
    else
    {
      v21 = car->m_Components.p[34].m_pComponent;
    }
  }
  else
  {
    v21 = 0i64;
  }
  if ( LODWORD(v21[12].m_BoundComponentHandles.mNode.mNext) == 4 )
  {
    v23 = UFG::qMalloc(0x48ui64, "GameStatEventTask", 0i64);
    pIsCop = v23;
    if ( v23 )
    {
      mName = UFG::gGameStatEventChannel.mName;
      mUID = UFG::gGameStatEventChannel.mUID;
      v26 = UFG::GetLocalPlayer();
      v23[1].mNext = v23 + 1;
      v23[2].mNext = v23 + 1;
      v23->mNext = (UFG::allocator::free_link *)&UFG::Event::`vftable;
      LODWORD(v23[3].mNext) = mUID;
      v23[4].mNext = (UFG::allocator::free_link *)mName;
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
  if ( (_S12_6 & 1) == 0 )
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
  UFG::PersistentData::Time *v2; // rdi
  float ElapsedSeconds; // xmm6_4
  UFG::GameStatTracker *v4; // rax
  UFG::qSymbol result; // [rsp+50h] [rbp+8h] BYREF
  unsigned int mUID; // [rsp+58h] [rbp+10h] BYREF
  unsigned int *v7; // [rsp+60h] [rbp+18h]

  if ( station )
  {
    v2 = &UFG::GameStatTracker::Instance()->mpSnapshots[0]->mTimes[16];
    UFG::SimpleTimer::Stop(&v2->mTimer);
    UFG::qSymbol::create_from_string(&result, station->m_name);
    ElapsedSeconds = UFG::SimpleTimer::GetElapsedSeconds(&v2->mTimer);
    v4 = UFG::GameStatTracker::Instance();
    if ( (*((_BYTE *)v4 + 6216) & 1) == 0 )
    {
      UFG::PersistentData::MapFloat::ApplyDelta(v4->mpSnapshots[0]->mpMapFloats[2], &result, ElapsedSeconds);
      if ( UFG::GameStatAction::PostStat::sIsEnabled )
      {
        v7 = &mUID;
        mUID = result.mUID;
      }
    }
    UFG::SimpleTimer::GetElapsedSeconds(&v2->mTimer);
  }
}

// File Line: 577
// RVA: 0x4BF5D0
void UFG::GameStatAction::GameState::Start(void)
{
  UFG::GameStatAction::World::sCurrentZone = 0;
  if ( (_S19_1 & 1) == 0 )
  {
    _S19_1 |= 1u;
    UFG::ProgressionTracker::ProgressionTracker(&sProgressionTracker);
    atexit(UFG::ProgressionTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sProgressionTracker__);
  }
  UFG::ProgressionTracker::mspInstance = &sProgressionTracker;
  UFG::ProgressionTracker::PublishProgressionStatistics(&sProgressionTracker);
  if ( (_S15_1 & 1) == 0 )
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
void __fastcall UFG::GameStatAction::Character::EnterWater(UFG::SimObjectCharacter *who)
{
  UFG::GameStatTracker *v1; // rax
  UFG::GameStatTracker *v2; // rax

  if ( UFG::GetLocalPlayer() == who )
  {
    v1 = UFG::GameStatTracker::Instance();
    UFG::SimpleTimer::Resume(&v1->mpSnapshots[0]->mTimes[6].mTimer);
    v2 = UFG::GameStatTracker::Instance();
    UFG::SimpleTimer::Stop(&v2->mpSnapshots[0]->mTimes[4].mTimer);
  }
}

// File Line: 602
// RVA: 0x49FD90
double __fastcall UFG::GameStatAction::Character::ExitWater(UFG::SimObjectCharacter *who)
{
  UFG::GameStatTracker *v1; // rax
  UFG::GameStatTracker *v2; // rax
  UFG::GameStatTracker *v3; // rax
  double result; // xmm0_8

  if ( UFG::GetLocalPlayer() == who )
  {
    v1 = UFG::GameStatTracker::Instance();
    UFG::SimpleTimer::Stop(&v1->mpSnapshots[0]->mTimes[6].mTimer);
    v2 = UFG::GameStatTracker::Instance();
    UFG::SimpleTimer::Resume(&v2->mpSnapshots[0]->mTimes[4].mTimer);
    v3 = UFG::GameStatTracker::Instance();
    *(float *)&result = UFG::SimpleTimer::GetElapsedSeconds(&v3->mpSnapshots[0]->mTimes[6].mTimer);
  }
  return result;
}

// File Line: 647
// RVA: 0x4B4B50
void __fastcall UFG::GameStatAction::Player::RecordSpecialMove(UFG::qSymbol *path)
{
  UFG::GameStatTracker *v2; // rbx
  UFG::GameStatTracker *v3; // rax
  unsigned int v4; // ecx
  UFG::GameStatTracker *v5; // rdx
  UFG::GameStatTracker *v6; // rax
  unsigned int mUID; // eax
  UFG::qSymbol mapid; // [rsp+40h] [rbp+8h] BYREF
  UFG::qSymbol *p_mapid; // [rsp+48h] [rbp+10h]

  v2 = &sGameStatTracker;
  if ( path->mUID != 188606418 )
  {
    if ( path->mUID == 2092809126 )
    {
      v3 = UFG::GameStatTracker::Instance();
      if ( (*((_BYTE *)v3 + 6216) & 1) == 0 )
      {
        ++v3->mpSnapshots[0]->mInts[121].mValue;
        if ( UFG::GameStatAction::PostStat::sIsEnabled )
        {
          v4 = _S12_6;
          if ( (_S12_6 & 1) == 0 )
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
  if ( (*((_BYTE *)v6 + 6216) & 1) != 0 )
    goto LABEL_16;
  ++v6->mpSnapshots[0]->mInts[120].mValue;
  if ( !UFG::GameStatAction::PostStat::sIsEnabled )
    goto LABEL_16;
  v4 = _S12_6;
  if ( (_S12_6 & 1) == 0 )
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
  if ( (v4 & 1) == 0 )
  {
    _S12_6 = v4 | 1;
    UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
    atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
    v5 = UFG::GameStatTracker::mspInstance;
  }
  if ( v5 )
    v2 = v5;
  UFG::GameStatTracker::mspInstance = v2;
  if ( (*((_BYTE *)v2 + 6216) & 1) == 0 )
  {
    UFG::PersistentData::MapInt::ApplyDelta(v2->mpSnapshots[0]->mpMapInts[24], path, 1);
    mUID = path->mUID;
    if ( UFG::GameStatAction::PostStat::sIsEnabled )
    {
      p_mapid = &mapid;
      mapid.mUID = mUID;
      UFG::GameStatAction::PostStat::AchieveMapInt(SpecialMoves, (UFG::qSymbol)&mapid);
    }
  }
}

// File Line: 670
// RVA: 0x496D10
void __fastcall UFG::GameStatAction::Player::ClampAndApplyDeltaCombatMeter(
        float deltaFaceValue,
        unsigned int faceadjustmenttype)
{
  UFG::GameStatTracker *v3; // rbx
  signed __int16 m_Flags; // dx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  float mValue; // xmm6_4
  float v7; // xmm6_4
  UFG::GameStatTracker *v8; // rax
  int v9; // xmm6_4
  UFG::GameStatTracker *v10; // rax
  UFG::GameStat::FloatStat v11; // edx

  v3 = &sGameStatTracker;
  if ( (_S12_6 & 1) == 0 )
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
    m_Flags = LocalPlayer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
      ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(LocalPlayer, UFG::FaceMeterComponent::_TypeUID);
    else
      ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(LocalPlayer, UFG::FaceMeterComponent::_TypeUID);
    if ( ComponentOfTypeHK && LOBYTE(ComponentOfTypeHK[135].m_SafePointerList.mNode.mPrev) )
    {
      mValue = UFG::GameStatTracker::Instance()->mpSnapshots[0]->mFloats[43].mValue;
      UFG::GameStatAction::Player::ClampAndSetCombatMeter(mValue + deltaFaceValue);
      v7 = mValue - UFG::GameStatTracker::Instance()->mpSnapshots[0]->mFloats[43].mValue;
      if ( faceadjustmenttype == sFaceEventSymbol_FaceTypeGained.mUID )
      {
        v8 = UFG::GameStatTracker::Instance();
        if ( (*((_BYTE *)v8 + 6216) & 1) == 0 )
          v8->mpSnapshots[0]->mFloats[44].mValue = v7 + v8->mpSnapshots[0]->mFloats[44].mValue;
      }
      else
      {
        if ( faceadjustmenttype == sFaceEventSymbol_FaceTypeUsed.mUID )
        {
          v9 = LODWORD(v7) ^ _xmm[0];
          v10 = UFG::GameStatTracker::Instance();
          v11 = 0x2D;
        }
        else
        {
          if ( faceadjustmenttype != sFaceEventSymbol_FaceTypeLost.mUID )
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
  if ( (_S12_6 & 1) == 0 )
  {
    _S12_6 |= 1u;
    UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
    atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
  }
  if ( UFG::GameStatTracker::mspInstance )
    v2 = UFG::GameStatTracker::mspInstance;
  UFG::GameStatTracker::mspInstance = v2;
  if ( (*((_BYTE *)v2 + 6216) & 1) == 0 )
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
  if ( (_S12_6 & 1) == 0 )
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
  if ( (*((_BYTE *)v3 + 6216) & 1) == 0 )
  {
    v3->mpSnapshots[0]->mFloats[41].mValue = heat;
    v3 = UFG::GameStatTracker::mspInstance;
  }
  if ( (v1 & 1) == 0 )
  {
    _S12_6 = v1 | 1;
    UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
    atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
    v3 = UFG::GameStatTracker::mspInstance;
  }
  if ( v3 )
    v2 = v3;
  UFG::GameStatTracker::mspInstance = v2;
  if ( (*((_BYTE *)v2 + 6216) & 1) == 0 )
  {
    v4 = v2->mpSnapshots[0];
    if ( heat > v4->mFloats[42].mValue )
      v4->mFloats[42].mValue = heat;
  }
}

// File Line: 714
// RVA: 0x4B1380
void __fastcall UFG::GameStatAction::Player::NotifyHeatLevelChange(int oldHL, int heatLevel)
{
  unsigned int v4; // r8d
  UFG::GameStatTracker *v5; // rbx
  UFG::GameStatTracker *v6; // rcx
  UFG::SimpleTimer *p_mTimer; // rsi
  UFG::GameStatTracker *v8; // rax
  UFG::SimpleTimer *v9; // rbp
  float ElapsedSeconds; // xmm6_4
  UFG::GameStatTracker *v11; // rcx
  UFG::GameSnapshot *v12; // rax
  float v13; // xmm6_4
  UFG::GameSnapshot *v14; // rax

  v4 = _S12_6;
  v5 = &sGameStatTracker;
  if ( (_S12_6 & 1) == 0 )
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
  p_mTimer = &v6->mpSnapshots[0]->mTimes[13].mTimer;
  if ( (v4 & 1) == 0 )
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
  if ( oldHL > 0 )
  {
    if ( heatLevel <= 0 )
      UFG::SimpleTimer::Stop(p_mTimer);
  }
  else if ( heatLevel > 0 )
  {
    UFG::SimpleTimer::Resume(p_mTimer);
  }
  if ( oldHL >= 5 )
  {
    if ( heatLevel < 5 )
      UFG::SimpleTimer::Stop(v9);
  }
  else if ( heatLevel >= 5 )
  {
    UFG::SimpleTimer::Resume(v9);
  }
  ElapsedSeconds = UFG::SimpleTimer::GetElapsedSeconds(p_mTimer);
  if ( (_S12_6 & 1) == 0 )
  {
    _S12_6 |= 1u;
    UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
    atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
  }
  v11 = &sGameStatTracker;
  if ( UFG::GameStatTracker::mspInstance )
    v11 = UFG::GameStatTracker::mspInstance;
  UFG::GameStatTracker::mspInstance = v11;
  if ( (*((_BYTE *)v11 + 6216) & 1) == 0 )
  {
    v12 = v11->mpSnapshots[0];
    if ( ElapsedSeconds > v12->mFloats[110].mValue )
      v12->mFloats[110].mValue = ElapsedSeconds;
  }
  v13 = UFG::SimpleTimer::GetElapsedSeconds(v9);
  if ( (_S12_6 & 1) == 0 )
  {
    _S12_6 |= 1u;
    UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
    atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
  }
  if ( UFG::GameStatTracker::mspInstance )
    v5 = UFG::GameStatTracker::mspInstance;
  UFG::GameStatTracker::mspInstance = v5;
  if ( (*((_BYTE *)v5 + 6216) & 1) == 0 )
  {
    v14 = v5->mpSnapshots[0];
    if ( v13 > v14->mFloats[111].mValue )
      v14->mFloats[111].mValue = v13;
  }
  if ( oldHL > 0 && heatLevel <= 0 )
    UFG::SimpleTimer::GetElapsedSeconds(p_mTimer);
}

// File Line: 747
// RVA: 0x4B52F0
void __fastcall UFG::GameStatAction::Player::RegisterSuccessFaceEvent(UFG::qSymbol *faceadjustmenttype)
{
  unsigned int mUID; // eax
  UFG::GameStatTracker *v2; // rax
  UFG::GameStatTracker *v3; // rbx
  UFG::GameStatTracker *v4; // rax
  UFG::GameStatTracker *v5; // rax

  mUID = faceadjustmenttype->mUID;
  if ( faceadjustmenttype->mUID == sFaceEventSymbol_FaceTypeGained.mUID )
  {
    v2 = UFG::GameStatTracker::Instance();
    if ( (*((_BYTE *)v2 + 6216) & 1) == 0 )
    {
      ++v2->mpSnapshots[0]->mInts[33].mValue;
      if ( UFG::GameStatAction::PostStat::sIsEnabled )
      {
        v3 = &sGameStatTracker;
        if ( (_S12_6 & 1) == 0 )
        {
          _S12_6 |= 1u;
          UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
          atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
        }
        if ( !UFG::GameStatTracker::mspInstance )
LABEL_22:
          UFG::GameStatTracker::mspInstance = v3;
      }
    }
  }
  else if ( mUID == sFaceEventSymbol_FaceTypeUsed.mUID )
  {
    v4 = UFG::GameStatTracker::Instance();
    if ( (*((_BYTE *)v4 + 6216) & 1) == 0 )
    {
      ++v4->mpSnapshots[0]->mInts[33].mValue;
      if ( UFG::GameStatAction::PostStat::sIsEnabled )
      {
        v3 = &sGameStatTracker;
        if ( (_S12_6 & 1) == 0 )
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
  else if ( mUID == sFaceEventSymbol_FaceTypeLost.mUID )
  {
    v5 = UFG::GameStatTracker::Instance();
    if ( (*((_BYTE *)v5 + 6216) & 1) == 0 )
    {
      ++v5->mpSnapshots[0]->mInts[34].mValue;
      if ( UFG::GameStatAction::PostStat::sIsEnabled )
      {
        v3 = &sGameStatTracker;
        if ( (_S12_6 & 1) == 0 )
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
void __fastcall UFG::GameStatAction::Player::HandleGameStatEvent(
        UFG::SimObjectCharacter *me,
        UFG::SimObjectCharacter *target,
        unsigned int iEnum)
{
  signed __int16 v6; // cx
  UFG::HitReactionComponent *v7; // rax
  UFG::SimObjectCharacter *LocalPlayer; // rax
  UFG::SimObjectWeaponPropertiesComponent *HoldingWeapon; // rax
  UFG::OSuiteLeaderboardManager *v11; // rax
  const char *v12; // rdx
  UFG::OSuiteLeaderboardManager *v13; // rax
  UFG::OSuiteLeaderboardData *v14; // rax
  UFG::GameStatTracker *v15; // rax
  unsigned int v16; // eax
  UFG::OSuiteLeaderboardManager *v17; // rax
  UFG::OSuiteLeaderboardData *LeaderboardDataUsingLeaderboardName; // rax
  UFG::GameStatTracker *v19; // rax
  UFG::GameStatTracker *v20; // rax
  UFG::GameStatTracker *v21; // rbx
  UFG::CopSystem *v22; // rax
  UFG::GameStatTracker *v23; // rax
  UFG::OSuiteLeaderboardData *v24; // rax
  UFG::OSuiteLeaderboardManager *v25; // rax
  UFG::OSuiteLeaderboardData *v26; // rax
  UFG::OSuiteLeaderboardManager *v27; // rax
  const char *v28; // rdx
  UFG::OSuiteLeaderboardData *v29; // rax
  UFG::OSuiteLeaderboardManager *v30; // rax
  UFG::OSuiteLeaderboardData *v31; // rax
  UFG::GameStatTracker *v32; // rax
  UFG::GameStatTracker *v33; // rax
  UFG::GameStatTracker *v34; // rax
  UFG::GameStatTracker *v35; // rax
  signed __int16 v36; // cx
  UFG::CharacterOccupantComponent *v37; // rax
  UFG::SimObjectCVBase *v38; // rax
  UFG::BikeHumanDriverComponent *v39; // rax
  signed __int16 m_Flags; // cx
  UFG::CharacterOccupantComponent *m_pComponent; // rax
  UFG::SimObjectCVBase *CurrentVehicle; // rax
  UFG::BikeHumanDriverComponent *v43; // rax
  UFG::qSymbol result; // [rsp+40h] [rbp+8h] BYREF

  if ( me == UFG::GetLocalPlayer() )
  {
    switch ( iEnum )
    {
      case 2u:
        if ( me )
        {
          m_Flags = me->m_Flags;
          if ( (m_Flags & 0x4000) != 0 )
            m_pComponent = (UFG::CharacterOccupantComponent *)me->m_Components.p[44].m_pComponent;
          else
            m_pComponent = (UFG::CharacterOccupantComponent *)(m_Flags < 0
                                                            || (m_Flags & 0x2000) != 0
                                                            || (m_Flags & 0x1000) != 0
                                                             ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                 me,
                                                                 UFG::CharacterOccupantComponent::_TypeUID)
                                                             : UFG::SimObject::GetComponentOfType(
                                                                 me,
                                                                 UFG::CharacterOccupantComponent::_TypeUID));
          if ( m_pComponent )
          {
            CurrentVehicle = (UFG::SimObjectCVBase *)UFG::CharacterOccupantComponent::GetCurrentVehicle(m_pComponent);
            if ( CurrentVehicle )
            {
              v43 = UFG::SimObjectCVBase::GetComponent<UFG::BikeHumanDriverComponent>(CurrentVehicle);
              if ( v43 )
                UFG::BikeHumanDriverComponent::WheelieStop(v43);
            }
          }
        }
        return;
      case 3u:
        if ( me )
        {
          v36 = me->m_Flags;
          if ( (v36 & 0x4000) != 0 )
            v37 = (UFG::CharacterOccupantComponent *)me->m_Components.p[44].m_pComponent;
          else
            v37 = (UFG::CharacterOccupantComponent *)(v36 < 0 || (v36 & 0x2000) != 0 || (v36 & 0x1000) != 0
                                                    ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                        me,
                                                        UFG::CharacterOccupantComponent::_TypeUID)
                                                    : UFG::SimObject::GetComponentOfType(
                                                        me,
                                                        UFG::CharacterOccupantComponent::_TypeUID));
          if ( v37 )
          {
            v38 = (UFG::SimObjectCVBase *)UFG::CharacterOccupantComponent::GetCurrentVehicle(v37);
            if ( v38 )
            {
              v39 = UFG::SimObjectCVBase::GetComponent<UFG::BikeHumanDriverComponent>(v38);
              if ( v39 )
                UFG::BikeHumanDriverComponent::WheelieStart(v39);
            }
          }
        }
        return;
      case 7u:
        v35 = UFG::GameStatTracker::Instance();
        UFG::SimpleTimer::Stop(&v35->mpSnapshots[0]->mTimes[5].mTimer);
        return;
      case 8u:
        v34 = UFG::GameStatTracker::Instance();
        UFG::SimpleTimer::Resume(&v34->mpSnapshots[0]->mTimes[5].mTimer);
        return;
      case 0x15u:
        v11 = UFG::OSuiteLeaderboardManager::Instance();
        v12 = "StatAwardsLuckyShooter";
        goto LABEL_53;
      case 0x16u:
        v15 = UFG::GameStatTracker::Instance();
        if ( (*((_BYTE *)v15 + 6216) & 1) != 0 )
          return;
        ++v15->mpSnapshots[0]->mInts[95].mValue;
        if ( !UFG::GameStatAction::PostStat::sIsEnabled )
          return;
        v16 = _S12_6;
        if ( (_S12_6 & 1) == 0 )
          goto LABEL_49;
        goto LABEL_50;
      case 0x17u:
        v11 = UFG::OSuiteLeaderboardManager::Instance();
        v12 = "StatAwardsWrecker";
        goto LABEL_53;
      case 0x19u:
        v17 = UFG::OSuiteLeaderboardManager::Instance();
        LeaderboardDataUsingLeaderboardName = UFG::OSuiteLeaderboardManager::GetLeaderboardDataUsingLeaderboardName(
                                                v17,
                                                "StatAwardsDefence");
        UFG::DataSynchronizer::ApplyDeltaToGlobalSnapshot(LeaderboardDataUsingLeaderboardName, 1);
        UFG::GameStatAction::MissionScoring::LogTriadEvent(TRIAD_MELEE_COUNTER, 0, &customCaption);
        return;
      case 0x1Au:
        v19 = UFG::GameStatTracker::Instance();
        if ( (*((_BYTE *)v19 + 6216) & 1) != 0 )
          return;
        ++v19->mpSnapshots[0]->mInts[32].mValue;
        if ( !UFG::GameStatAction::PostStat::sIsEnabled )
          return;
        v16 = _S12_6;
        if ( (_S12_6 & 1) == 0 )
          goto LABEL_49;
        goto LABEL_50;
      case 0x1Eu:
        v25 = UFG::OSuiteLeaderboardManager::Instance();
        v26 = UFG::OSuiteLeaderboardManager::GetLeaderboardDataUsingLeaderboardName(v25, "StatAwardsDisarming");
        UFG::DataSynchronizer::ApplyDeltaToGlobalSnapshot(v26, 1);
        UFG::GameStatAction::MissionScoring::LogTriadEvent(TRIAD_WEAPON_DISARM, 0, &customCaption);
        return;
      case 0x25u:
        v11 = UFG::OSuiteLeaderboardManager::Instance();
        v12 = "StatAwardsFirestarter";
        goto LABEL_53;
      case 0x29u:
        v13 = UFG::OSuiteLeaderboardManager::Instance();
        v14 = UFG::OSuiteLeaderboardManager::GetLeaderboardDataUsingLeaderboardName(v13, "StatAwardsFastTalker");
        UFG::DataSynchronizer::ApplyDeltaToGlobalSnapshot(v14, 1);
        UFG::GameStatAction::MissionScoring::LogTriadEvent(TRIAD_FAST_TALK, 0, &customCaption);
        return;
      case 0x39u:
        v11 = UFG::OSuiteLeaderboardManager::Instance();
        v12 = "StatAwardsBonebreaker";
        goto LABEL_53;
      case 0x45u:
        v27 = UFG::OSuiteLeaderboardManager::Instance();
        v28 = "StatGamesFlyingKicks";
        goto LABEL_57;
      case 0x47u:
        v11 = UFG::OSuiteLeaderboardManager::Instance();
        v12 = "StatAwardsNinja";
        goto LABEL_53;
      case 0x48u:
        goto LABEL_45;
      case 0x4Du:
        v27 = UFG::OSuiteLeaderboardManager::Instance();
        v28 = "StatGamesTackles";
LABEL_57:
        v29 = UFG::OSuiteLeaderboardManager::GetLeaderboardDataUsingLeaderboardName(v27, v28);
        UFG::StatGameManager::UpdateScore(v29, 1, 1);
        return;
      case 0x51u:
        v11 = UFG::OSuiteLeaderboardManager::Instance();
        v12 = "StatAwardsDeadeye";
        goto LABEL_53;
      case 0x52u:
      case 0x54u:
      case 0x57u:
        v23 = UFG::GameStatTracker::Instance();
        if ( (*((_BYTE *)v23 + 6216) & 1) != 0 )
          return;
        ++v23->mpSnapshots[0]->mInts[13].mValue;
        if ( !UFG::GameStatAction::PostStat::sIsEnabled )
          return;
        v16 = _S12_6;
        if ( (_S12_6 & 1) == 0 )
        {
LABEL_49:
          _S12_6 = v16 | 1;
          UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
          atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
        }
LABEL_50:
        if ( !UFG::GameStatTracker::mspInstance )
          UFG::GameStatTracker::mspInstance = &sGameStatTracker;
        break;
      case 0x53u:
      case 0x55u:
      case 0x59u:
        v20 = UFG::GameStatTracker::Instance();
        if ( (*((_BYTE *)v20 + 6216) & 1) == 0 )
        {
          ++v20->mpSnapshots[0]->mInts[12].mValue;
          if ( UFG::GameStatAction::PostStat::sIsEnabled )
          {
            v21 = &sGameStatTracker;
            if ( (_S12_6 & 1) == 0 )
            {
              _S12_6 |= 1u;
              UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
              atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
            }
            if ( UFG::GameStatTracker::mspInstance )
              v21 = UFG::GameStatTracker::mspInstance;
            UFG::GameStatTracker::mspInstance = v21;
          }
        }
LABEL_45:
        v22 = UFG::CopSystem::Instance();
        UFG::CopSystem::TriggerOnFootNoSprint(v22);
        return;
      case 0x56u:
        v11 = UFG::OSuiteLeaderboardManager::Instance();
        v12 = "StatAwardsFluidStriker";
LABEL_53:
        v24 = UFG::OSuiteLeaderboardManager::GetLeaderboardDataUsingLeaderboardName(v11, v12);
        UFG::DataSynchronizer::ApplyDeltaToGlobalSnapshot(v24, 1);
        break;
      case 0x60u:
        v30 = UFG::OSuiteLeaderboardManager::Instance();
        v31 = UFG::OSuiteLeaderboardManager::GetLeaderboardDataUsingLeaderboardName(v30, "StatAwardsHijacker");
        UFG::DataSynchronizer::ApplyDeltaToGlobalSnapshot(v31, 1);
        v32 = UFG::GameStatTracker::Instance();
        if ( (*((_BYTE *)v32 + 6216) & 1) == 0 )
        {
          ++v32->mpSnapshots[0]->mInts[89].mValue;
          if ( UFG::GameStatAction::PostStat::sIsEnabled )
            UFG::GameStatAction::PostStat::AchieveInt(VehiclesActionHijacked);
        }
        UFG::AchievementTrophyManager::UnlockAchievementTrophy(9);
        break;
      case 0x61u:
        UFG::GameStatAction::MissionScoring::LogTriadEvent(TRIAD_VEHICLE_ACTIONHIJACK, 0, &customCaption);
        break;
      case 0x67u:
      case 0x6Au:
        v33 = UFG::GameStatTracker::Instance();
        if ( (*((_BYTE *)v33 + 6216) & 1) == 0 )
        {
          ++v33->mpSnapshots[0]->mInts[88].mValue;
          if ( UFG::GameStatAction::PostStat::sIsEnabled )
            UFG::GameStatAction::PostStat::AchieveInt(VehiclesStolen);
        }
        UFG::GameStatAction::MissionScoring::LogCopEvent(COP_VEHICLE_STEAL, 0, &customCaption);
        break;
      default:
        return;
    }
  }
  else if ( target == UFG::GetLocalPlayer() && iEnum == 91 && me )
  {
    v6 = me->m_Flags;
    if ( (v6 & 0x4000) != 0 )
    {
      v7 = (UFG::HitReactionComponent *)me->m_Components.p[15].m_pComponent;
    }
    else if ( v6 >= 0 )
    {
      v7 = (UFG::HitReactionComponent *)((v6 & 0x2000) != 0 || (v6 & 0x1000) != 0
                                       ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                           me,
                                           UFG::HitReactionComponent::_TypeUID)
                                       : UFG::SimObject::GetComponentOfType(me, UFG::HitReactionComponent::_TypeUID));
    }
    else
    {
      v7 = (UFG::HitReactionComponent *)me->m_Components.p[15].m_pComponent;
    }
    if ( v7 && v7->mHitRecord.mIsDeadly )
    {
      LocalPlayer = UFG::GetLocalPlayer();
      HoldingWeapon = UFG::GameStatAction::Weapon::GetHoldingWeapon(LocalPlayer);
      if ( HoldingWeapon
        && UFG::SimObjectWeaponPropertiesComponent::GetWeaponID(HoldingWeapon, &result)->mUID == sSym_CombatFish.mUID )
      {
        UFG::AchievementTrophyManager::UnlockAchievementTrophy(10);
      }
    }
  }
}

// File Line: 973
// RVA: 0x4B5ED0
UFG::qSymbol *__fastcall UFG::GameStatAction::RegisterWeaponKill(
        UFG::qSymbol *result,
        UFG::GameStatTracker *gst,
        UFG::HitRecord *hitRecord,
        UFG::qString *reason,
        const char *reason_text)
{
  UFG::qString::Format(reason, reason_text);
  UFG::SimObjectWeaponPropertiesComponent::GetWeaponID(
    (UFG::SimObjectWeaponPropertiesComponent *)hitRecord->mProjectileInfo.m_pSOWPC.m_pPointer,
    result);
  return result;
}

// File Line: 979
// RVA: 0x4B4D10
void __fastcall UFG::GameStatAction::Player::RegisterPlayerDeath(UFG::SimObjectGame *src, UFG::HitRecord *hitRecord)
{
  UFG::GameStatTracker *v4; // rsi
  UFG::GameStatTracker *v5; // rdi
  int mUID; // ebx
  UFG::SimObjectCharacter *LocalPlayer; // rax
  UFG::SimObjectWeaponPropertiesComponent *HoldingWeapon; // rax
  unsigned int v9; // edx
  UFG::GameStatTracker *v10; // rcx
  signed __int16 m_Flags; // cx
  UFG::SimComponent *m_pComponent; // rax
  UFG::SceneObjectProperties *m_pSceneObj; // rcx
  int v14; // eax
  const char *v15; // rax
  UFG::SimObjectWeaponPropertiesComponent *v16; // rsi
  UFG::SimObject *m_pPointer; // rsi
  __int16 v18; // cx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  bool v20; // zf
  UFG::SimObjectGame *v21; // rcx
  UFG::SceneObjectProperties *v22; // rcx
  UFG::SimObjectCharacter *v23; // rax
  UFG::TransformNodeComponent *v24; // rcx
  UFG::OSuiteDBLogger *v25; // r15
  unsigned int v26; // r12d
  __int64 mAttackTypeID; // rcx
  EnumList<unsigned long> *v28; // rax
  unsigned int v29; // esi
  unsigned int v30; // r14d
  char *v31; // rdi
  char *v32; // rax
  char *reason_text; // [rsp+20h] [rbp-99h]
  UFG::qString reason; // [rsp+30h] [rbp-89h] BYREF
  __int64 v35; // [rsp+58h] [rbp-61h]
  char dest[176]; // [rsp+60h] [rbp-59h] BYREF
  UFG::qSymbolUC v37; // [rsp+120h] [rbp+67h] BYREF
  UFG::qSymbolUC v38; // [rsp+128h] [rbp+6Fh] BYREF
  UFG::qSymbol result; // [rsp+130h] [rbp+77h] BYREF

  v35 = -2i64;
  UFG::qString::qString(&reason);
  v4 = &sGameStatTracker;
  if ( (_S12_6 & 1) == 0 )
  {
    _S12_6 |= 1u;
    UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
    atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
  }
  v5 = &sGameStatTracker;
  if ( UFG::GameStatTracker::mspInstance )
    v5 = UFG::GameStatTracker::mspInstance;
  UFG::GameStatTracker::mspInstance = v5;
  mUID = UFG::gNullQSymbol.mUID;
  v38.mUID = UFG::gNullQSymbol.mUID;
  v37.mUID = UFG::gNullQSymbol.mUID;
  LocalPlayer = UFG::GetLocalPlayer();
  HoldingWeapon = UFG::GameStatAction::Weapon::GetHoldingWeapon(LocalPlayer);
  if ( HoldingWeapon )
    mUID = UFG::SimObjectWeaponPropertiesComponent::GetWeaponID(HoldingWeapon, &result)->mUID;
  if ( (*((_BYTE *)v5 + 6216) & 1) != 0
    || (v5->mpSnapshots[0]->mIDs[34].mValue.mUID = mUID, (*((_BYTE *)v5 + 6216) & 1) != 0)
    || (++v5->mpSnapshots[0]->mInts[2].mValue, !UFG::GameStatAction::PostStat::sIsEnabled) )
  {
    v9 = _S12_6;
  }
  else
  {
    v9 = _S12_6;
    if ( (_S12_6 & 1) == 0 )
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
  if ( src )
  {
    m_Flags = src->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = src->m_Components.p[23].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      m_pComponent = (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
                   ? UFG::SimObjectGame::GetComponentOfTypeHK(src, UFG::VehicleDriverInterface::_TypeUID)
                   : UFG::SimObject::GetComponentOfType(src, UFG::VehicleDriverInterface::_TypeUID);
      v9 = _S12_6;
    }
    else
    {
      m_pComponent = src->m_Components.p[23].m_pComponent;
    }
    if ( m_pComponent )
    {
      if ( (*((_BYTE *)v5 + 6216) & 1) == 0 )
      {
        ++v5->mpSnapshots[0]->mInts[5].mValue;
        if ( UFG::GameStatAction::PostStat::sIsEnabled )
        {
          if ( (v9 & 1) == 0 )
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
      m_pSceneObj = src->m_pSceneObj;
      if ( m_pSceneObj )
        v37.mUID = UFG::SceneObjectProperties::GetArchetypePropertiesName(m_pSceneObj)->mUID;
      goto LABEL_60;
    }
  }
  if ( hitRecord->mProjectileInfo.m_pSOWPC.m_pPointer )
  {
    if ( (*((_BYTE *)v5 + 6216) & 1) == 0 )
    {
      ++v5->mpSnapshots[0]->mInts[3].mValue;
      if ( UFG::GameStatAction::PostStat::sIsEnabled )
      {
        if ( (v9 & 1) == 0 )
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
    v14 = **((_DWORD **)&hitRecord->mProjectileInfo.m_pSOWPC.m_pPointer[2].m_BoundComponentHandles.mNode.mPrev->mNext
           + HIDWORD(hitRecord->mProjectileInfo.m_pSOWPC.m_pPointer[2].m_pSimObject));
    if ( v14 == UFG::gSimObjectWeaponTypeTrackEnum_eSIM_OBJ_WEAPON_TYPE_PISTOL.m_EnumValue )
    {
      v15 = "Killed from pistol";
LABEL_53:
      UFG::GameStatAction::RegisterWeaponKill(&result, v5, hitRecord, &reason, v15);
      goto LABEL_60;
    }
    if ( v14 != UFG::gSimObjectWeaponTypeTrackEnum_eSIM_OBJ_WEAPON_TYPE_RIFLE.m_EnumValue )
    {
      if ( v14 == UFG::gSimObjectWeaponTypeTrackEnum_eSIM_OBJ_WEAPON_TYPE_SHOTGUN.m_EnumValue )
      {
        v15 = "Killed from shotgun";
        goto LABEL_53;
      }
      if ( v14 == UFG::gSimObjectWeaponTypeTrackEnum_eSIM_OBJ_WEAPON_TYPE_SMG.m_EnumValue )
      {
        v15 = "Killed from SMG";
        goto LABEL_53;
      }
      if ( v14 != UFG::gSimObjectWeaponTypeTrackEnum_eSIM_OBJ_WEAPON_TYPE_SNIPER.m_EnumValue )
        goto LABEL_60;
    }
    v15 = "Killed from rifle";
    goto LABEL_53;
  }
  if ( (*((_BYTE *)v5 + 6216) & 1) == 0 )
  {
    ++v5->mpSnapshots[0]->mInts[4].mValue;
    if ( UFG::GameStatAction::PostStat::sIsEnabled )
      UFG::GameStatAction::PostStat::AchieveInt(KilledByMelee);
  }
  if ( hitRecord->mMeleeInfo.mAttackMaterialUID == gAttackMaterialWeaponEquipped.m_EnumSymbol.mUID )
  {
    v16 = UFG::GameStatAction::Weapon::GetHoldingWeapon((UFG::SimObjectGame *)hitRecord->mAttacker.m_pPointer);
    UFG::qString::Format(&reason, "Killed from melee");
    if ( v16 )
      v38.mUID = UFG::SimObjectWeaponPropertiesComponent::GetWeaponID(v16, &result)->mUID;
  }
LABEL_60:
  m_pPointer = hitRecord->mAttacker.m_pPointer;
  if ( m_pPointer )
  {
    v18 = m_pPointer->m_Flags;
    if ( (v18 & 0x4000) != 0 )
    {
      ComponentOfTypeHK = m_pPointer->m_Components.p[19].m_pComponent;
    }
    else if ( v18 >= 0 )
    {
      if ( (v18 & 0x2000) != 0 )
      {
        ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(
                              (UFG::SimObjectGame *)hitRecord->mAttacker.m_pPointer,
                              UFG::AIActionTreeComponent::_TypeUID);
      }
      else
      {
        v20 = (v18 & 0x1000) == 0;
        v21 = (UFG::SimObjectGame *)hitRecord->mAttacker.m_pPointer;
        ComponentOfTypeHK = v20
                          ? UFG::SimObject::GetComponentOfType(v21, UFG::AIActionTreeComponent::_TypeUID)
                          : UFG::SimObjectGame::GetComponentOfTypeHK(v21, UFG::AIActionTreeComponent::_TypeUID);
      }
    }
    else
    {
      ComponentOfTypeHK = m_pPointer->m_Components.p[19].m_pComponent;
    }
    if ( ComponentOfTypeHK )
    {
      v22 = m_pPointer->m_pSceneObj;
      if ( v22 )
        v37.mUID = UFG::SceneObjectProperties::GetArchetypePropertiesName(v22)->mUID;
      UFG::qString::Format(&reason, "%s by %d", reason.mData, v37.mUID);
    }
  }
  if ( (*((_BYTE *)v5 + 6216) & 1) == 0 )
  {
    v5->mpSnapshots[0]->mIDs[32].mValue.mUID = v37.mUID;
    if ( (*((_BYTE *)v5 + 6216) & 1) == 0 )
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
    mAttackTypeID = (unsigned int)hitRecord->mAttackTypeID;
    if ( (int)mAttackTypeID >= 0 )
    {
      if ( (int)gAttackCollisionEnum.m_enumLists.size <= 0 )
        v28 = 0i64;
      else
        v28 = *gAttackCollisionEnum.m_enumLists.p;
      v26 = v28->m_enumNameHash.p[mAttackTypeID];
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
    UFG::qSPrintf(dest, 128, "i32_%s", "Cause");
    OSuite::ZMetric::SetProperty(v25->m_pMetric, dest, v26);
    LODWORD(v31) = v37;
    UFG::qSPrintf(dest, 128, "i32_%s", "KilledNameEnemy");
    OSuite::ZMetric::SetProperty(v25->m_pMetric, dest, (int)v31);
    LODWORD(v31) = v38;
    UFG::qSPrintf(dest, 128, "i32_%s", "KilledNameWeapon");
    OSuite::ZMetric::SetProperty(v25->m_pMetric, dest, (int)v31);
    UFG::qSPrintf(dest, 128, "i32_%s", "PlayerWeaponName");
    OSuite::ZMetric::SetProperty(v25->m_pMetric, dest, mUID);
    UFG::OSuiteDBLogger::SubmitMetric(v25, 1);
  }
  UFG::qString::~qString(&reason);
}

// File Line: 1119
// RVA: 0x4B5460
void __fastcall UFG::GameStatAction::Player::RegisterSuccessfulHit(
        UFG::SimObjectCharacter *src,
        UFG::SimObjectCVBase *target,
        UFG::HitRecord *hitRec)
{
  UFG::GameStatTracker *v6; // rbp
  signed __int16 m_Flags; // cx
  UFG::CharacterSubjectComponent *v8; // rax
  __m128 y_low; // xmm1
  float v10; // xmm0_4
  float v11; // xmm0_4
  UFG::GameSnapshot *v12; // rax
  bool v13; // di
  UFG::SimObjectCharacterPropertiesComponent *v14; // r15
  signed __int16 v15; // cx
  UFG::SimObjectCharacterPropertiesComponent *ComponentOfTypeHK; // rax
  UFG::eCharacterTypeEnum m_eCharacterType; // eax
  UFG::OSuiteLeaderboardManager *v18; // rax
  UFG::OSuiteLeaderboardData *LeaderboardDataUsingLeaderboardName; // rax
  UFG::OSuiteLeaderboardManager *v20; // rax
  UFG::OSuiteLeaderboardData *v21; // rax
  UFG::OSuiteLeaderboardManager *v22; // rax
  UFG::OSuiteLeaderboardData *v23; // rax
  UFG::OSuiteLeaderboardManager *v24; // rax
  UFG::OSuiteLeaderboardData *v25; // rax
  UFG::SimComponent *v26; // rbx
  signed __int16 v27; // cx
  UFG::SimComponent *v28; // rax
  UFG::SimObjectProp *v29; // rcx
  __int16 v30; // dx
  UFG::SimObjectWeaponPropertiesComponent *v31; // rax
  UFG::OSuiteLeaderboardManager *v32; // rax
  UFG::OSuiteLeaderboardData *v33; // rax
  UFG::OSuiteLeaderboardManager *v34; // rax
  UFG::OSuiteLeaderboardData *v35; // rax
  UFG::GameStatTracker *v36; // rbx
  signed __int16 v37; // cx
  UFG::AICoverComponent *ComponentOfType; // rax
  unsigned int v39; // edx
  UFG::GameStatTracker *v40; // rcx
  bool v41; // r12
  UFG::eFactionClassEnum m_eFactionClass; // eax
  UFG::CopSystem *v43; // rax
  UFG::OSuiteLeaderboardManager *v44; // rax
  UFG::OSuiteLeaderboardData *v45; // rax
  UFG::OSuiteLeaderboardManager *v46; // rax
  UFG::OSuiteLeaderboardData *v47; // rax
  signed __int16 v48; // cx
  UFG::SimObjectCharacterPropertiesComponent *v49; // rax
  UFG::eFactionClassEnum v50; // ebx
  UFG::eFactionClassEnum v51; // edi
  UFG::GameStatTracker *v52; // rax
  signed __int16 v53; // cx
  UFG::SimComponent *m_pComponent; // rbx
  UFG::SimComponent *v55; // rax
  unsigned int v56; // eax
  unsigned int MostUsedIndex; // eax
  UFG::allocator::free_link *v58; // r14
  const char *mName; // rdi
  unsigned int mUID; // ebx
  UFG::SimObjectCharacter *LocalPlayer; // rax
  UFG::OSuiteLeaderboardManager *v62; // rax
  UFG::OSuiteLeaderboardData *v63; // rax
  UFG::OSuiteLeaderboardManager *v64; // rax
  UFG::OSuiteLeaderboardData *v65; // rax
  signed __int16 v66; // cx
  UFG::SimObjectVehiclePropertiesComponent *v67; // rax
  UFG::eSimObjectVehicleTypeEnum m_eSimObjectVehicleType; // ecx
  char v69; // al
  int mAttackTypeID; // ecx
  bool v71; // [rsp+80h] [rbp+18h]

  if ( hitRec )
  {
    UFG::GameStatAction::Player::SuccessfulWeaponHit(hitRec, target);
    v6 = UFG::GameStatTracker::Instance();
    if ( src )
    {
      m_Flags = src->m_Flags;
      if ( (m_Flags & 0x4000) != 0 )
        v8 = UFG::SimObjectCharacter::GetComponent<UFG::CharacterSubjectComponent>(src);
      else
        v8 = (UFG::CharacterSubjectComponent *)(m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
                                              ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                  src,
                                                  UFG::CharacterSubjectComponent::_TypeUID)
                                              : UFG::SimObject::GetComponentOfType(
                                                  src,
                                                  UFG::CharacterSubjectComponent::_TypeUID));
      if ( v8 )
      {
        y_low = (__m128)LODWORD(hitRec->mCollisionInfo.mHitLocation.y);
        v10 = hitRec->mCollisionInfo.mHitLocation.x - v8->mFilteredPosition.x;
        y_low.m128_f32[0] = (float)((float)((float)(y_low.m128_f32[0] - v8->mFilteredPosition.y)
                                          * (float)(y_low.m128_f32[0] - v8->mFilteredPosition.y))
                                  + (float)(v10 * v10))
                          + (float)((float)(hitRec->mCollisionInfo.mHitLocation.z - v8->mFilteredPosition.z)
                                  * (float)(hitRec->mCollisionInfo.mHitLocation.z - v8->mFilteredPosition.z));
        LODWORD(v11) = _mm_sqrt_ps(y_low).m128_u32[0];
        if ( (*((_BYTE *)v6 + 6216) & 1) == 0 )
        {
          v12 = v6->mpSnapshots[0];
          if ( v11 > v12->mFloats[102].mValue )
            v12->mFloats[102].mValue = v11;
        }
      }
    }
    if ( hitRec->mIsDeadly )
    {
      if ( !UFG::GameStatAction::gIgnoreMissionKillsInWTHK )
        UFG::GameStatAction::Player::CountKills(target);
      v13 = UFG::GameStatAction::Player::IsInVehicle(src);
      v71 = v13;
      if ( !target )
      {
        v14 = 0i64;
        goto LABEL_60;
      }
      v15 = target->m_Flags;
      if ( (v15 & 0x4000) != 0 || v15 < 0 )
      {
        ComponentOfTypeHK = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectCharacterPropertiesComponent>(target);
      }
      else if ( (v15 & 0x2000) != 0 || (v15 & 0x1000) != 0 )
      {
        ComponentOfTypeHK = (UFG::SimObjectCharacterPropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                            target,
                                                                            UFG::SimObjectCharacterPropertiesComponent::_TypeUID);
      }
      else
      {
        ComponentOfTypeHK = (UFG::SimObjectCharacterPropertiesComponent *)UFG::SimObject::GetComponentOfType(
                                                                            target,
                                                                            UFG::SimObjectCharacterPropertiesComponent::_TypeUID);
      }
      v14 = ComponentOfTypeHK;
      if ( !ComponentOfTypeHK )
        goto LABEL_60;
      m_eCharacterType = ComponentOfTypeHK->m_eCharacterType;
      if ( m_eCharacterType == eCHARACTER_TYPE_PEDESTRIAN && (*((_BYTE *)v14 + 248) & 1) != 0 )
      {
        v18 = UFG::OSuiteLeaderboardManager::Instance();
        LeaderboardDataUsingLeaderboardName = UFG::OSuiteLeaderboardManager::GetLeaderboardDataUsingLeaderboardName(
                                                v18,
                                                "StatGamesPossessedPedsKilled");
        UFG::StatGameManager::UpdateScore(LeaderboardDataUsingLeaderboardName, 1, 1);
        goto LABEL_60;
      }
      if ( !v13 && m_eCharacterType == eCHARACTER_TYPE_DLC_JIANG_SHI )
      {
        v20 = UFG::OSuiteLeaderboardManager::Instance();
        v21 = UFG::OSuiteLeaderboardManager::GetLeaderboardDataUsingLeaderboardName(
                v20,
                "StatGamesJiangShiDefeatedStreak");
        UFG::StatGameManager::UpdateScore(v21, 1, 1);
        v22 = UFG::OSuiteLeaderboardManager::Instance();
        v23 = UFG::OSuiteLeaderboardManager::GetLeaderboardDataUsingLeaderboardName(v22, "StatAwardsJiangShiDefeated");
        UFG::DataSynchronizer::ApplyDeltaToGlobalSnapshot(v23, 1);
        goto LABEL_61;
      }
      if ( m_eCharacterType != eCHARACTER_TYPE_DLC_ELITE_GHOUL
        || ((v24 = UFG::OSuiteLeaderboardManager::Instance(),
             v25 = UFG::OSuiteLeaderboardManager::GetLeaderboardDataUsingLeaderboardName(
                     v24,
                     "StatAwardsYaoguaiDefeated"),
             UFG::DataSynchronizer::ApplyDeltaToGlobalSnapshot(v25, 1),
             src)
          ? ((v27 = src->m_Flags, (v27 & 0x4000) == 0)
           ? (v27 >= 0
            ? ((v27 & 0x2000) != 0 || (v27 & 0x1000) != 0
             ? (v28 = UFG::SimObjectGame::GetComponentOfTypeHK(src, UFG::TargetingSystemBaseComponent::_TypeUID))
             : (v28 = UFG::SimObject::GetComponentOfType(src, UFG::TargetingSystemBaseComponent::_TypeUID)),
               v26 = v28)
            : (v26 = src->m_Components.p[20].m_pComponent))
           : (v26 = src->m_Components.p[20].m_pComponent))
          : (v26 = 0i64),
            UFG::GameStatAction::Player::IsInVehicle(src)
         || !v26
         || (v29 = *(UFG::SimObjectProp **)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&v26[1].m_Flags + 25i64)
                                          + *(_QWORD *)&v26[1].m_TypeUID
                                          + 40)) == 0i64) )
      {
LABEL_60:
        if ( v13 )
        {
LABEL_62:
          v36 = &sGameStatTracker;
          if ( src
            && ((v37 = src->m_Flags, (v37 & 0x4000) == 0) && v37 >= 0 && (v37 & 0x2000) == 0 && (v37 & 0x1000) == 0
              ? (ComponentOfType = (UFG::AICoverComponent *)UFG::SimObject::GetComponentOfType(
                                                              src,
                                                              UFG::AICoverComponent::_TypeUID))
              : (ComponentOfType = (UFG::AICoverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                              src,
                                                              UFG::AICoverComponent::_TypeUID)),
                ComponentOfType
             && UFG::AICoverComponent::IsInCover(ComponentOfType)
             && (*((_BYTE *)v6 + 6216) & 1) == 0
             && (++v6->mpSnapshots[0]->mInts[94].mValue, UFG::GameStatAction::PostStat::sIsEnabled)) )
          {
            v39 = _S12_6;
            if ( (_S12_6 & 1) == 0 )
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
            m_eFactionClass = v14->m_eFactionClass;
            if ( m_eFactionClass == FACTION_INNOCENT )
            {
              v41 = 1;
              if ( (*((_BYTE *)v6 + 6216) & 1) == 0 )
              {
                ++v6->mpSnapshots[0]->mInts[8].mValue;
                if ( UFG::GameStatAction::PostStat::sIsEnabled )
                {
                  if ( (v39 & 1) == 0 )
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
              UFG::OnlineEventManager::PostEvent((UFG::OnlineEventManager::Event)6, 1);
              if ( (*((_BYTE *)v6 + 6216) & 1) == 0 )
              {
                ++v6->mpSnapshots[0]->mInts[151].mValue;
                if ( UFG::GameStatAction::PostStat::sIsEnabled )
                  UFG::GameStatAction::PostStat::AchieveInt(DebugValueC);
                if ( (*((_BYTE *)v6 + 6216) & 1) == 0 )
                {
                  ++v6->mpSnapshots[0]->mInts[0].mValue;
                  if ( UFG::GameStatAction::PostStat::sIsEnabled )
                    UFG::GameStatAction::PostStat::AchieveInt(DebugValueF);
                  if ( (*((_BYTE *)v6 + 6216) & 1) == 0 )
                  {
                    ++v6->mpSnapshots[0]->mInts[157].mValue;
                    if ( UFG::GameStatAction::PostStat::sIsEnabled )
                      UFG::GameStatAction::PostStat::AchieveInt(DebugValueFC);
                    if ( (*((_BYTE *)v6 + 6216) & 1) == 0 )
                    {
                      ++v6->mpSnapshots[0]->mInts[122].mValue;
                      if ( UFG::GameStatAction::PostStat::sIsEnabled )
                        UFG::GameStatAction::PostStat::AchieveInt(DebugValueO);
                    }
                  }
                }
              }
              UFG::GameStatAction::MissionScoring::LogCopEvent(COP_PEDESTRIAN_KILL, 0, &customCaption);
            }
            else if ( m_eFactionClass == FACTION_LAW )
            {
              UFG::GameStatAction::MissionScoring::LogCopEvent(COP_KILL, 0, &customCaption);
              v43 = UFG::CopSystem::Instance();
              if ( ((int (__fastcall *)(UFG::CopSystem *))v43->vfptr[89].__vecDelDtor)(v43) >= 2 )
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
              if ( !src )
              {
LABEL_139:
                if ( v71 )
                {
                  UFG::GameStatTracker::ApplyDelta(v6, VehicleKills, 1);
                  UFG::GameStatTracker::ApplyDelta(v6, CurrentVehicleKills, 1);
                  v62 = UFG::OSuiteLeaderboardManager::Instance();
                  v63 = UFG::OSuiteLeaderboardManager::GetLeaderboardDataUsingLeaderboardName(
                          v62,
                          "StatGamesLongestHitAndRun");
                  UFG::StatGameManager::UpdateScore(v63, 1, 1);
                  if ( v14 && v14->m_eCharacterType == eCHARACTER_TYPE_DLC_JIANG_SHI )
                  {
                    v64 = UFG::OSuiteLeaderboardManager::Instance();
                    v65 = UFG::OSuiteLeaderboardManager::GetLeaderboardDataUsingLeaderboardName(
                            v64,
                            "StatGamesJiangShiRunOver");
                    UFG::StatGameManager::UpdateScore(v65, 1, 1);
                  }
                  if ( src )
                  {
                    v66 = src->m_Flags;
                    if ( (v66 & 0x4000) != 0 || v66 < 0 )
                    {
                      v67 = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectVehiclePropertiesComponent>(src);
                    }
                    else if ( (v66 & 0x2000) != 0 || (v66 & 0x1000) != 0 )
                    {
                      v67 = (UFG::SimObjectVehiclePropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                          src,
                                                                          UFG::SimObjectVehiclePropertiesComponent::_TypeUID);
                    }
                    else
                    {
                      v67 = (UFG::SimObjectVehiclePropertiesComponent *)UFG::SimObject::GetComponentOfType(
                                                                          src,
                                                                          UFG::SimObjectVehiclePropertiesComponent::_TypeUID);
                    }
                    if ( v67 )
                    {
                      m_eSimObjectVehicleType = v67->m_eSimObjectVehicleType;
                      switch ( m_eSimObjectVehicleType )
                      {
                        case eSIM_OBJ_VEHICLE_TYPE_BIKE:
                          UFG::GameStatTracker::ApplyDelta(v6, BikeKills, 1);
                          break;
                        case eSIM_OBJ_VEHICLE_TYPE_BOAT:
                          UFG::GameStatTracker::ApplyDelta(v6, BoatKills, 1);
                          break;
                        case eSIM_OBJ_VEHICLE_TYPE_CAR:
                          UFG::GameStatTracker::ApplyDelta(v6, CarKills, 1);
                          break;
                      }
                    }
                  }
                }
                else if ( !UFG::GameStatAction::gIgnoreMissionKillsInWTHK )
                {
                  v69 = UFG::GameStatAction::Player::SuccessfulWeaponKill(hitRec, v41);
                  mAttackTypeID = hitRec->mAttackTypeID;
                  if ( mAttackTypeID != gAttackCollisionExplosionNoDamage.m_EnumValue
                    && mAttackTypeID != gAttackCollisionExplosion.m_EnumValue
                    && !v69 )
                  {
                    UFG::GameStatAction::Player::CountHandCombatKills();
                  }
                }
                return;
              }
              v48 = src->m_Flags;
              if ( (v48 & 0x4000) != 0 || v48 < 0 )
              {
                v49 = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectCharacterPropertiesComponent>(src);
              }
              else if ( (v48 & 0x2000) != 0 || (v48 & 0x1000) != 0 )
              {
                v49 = (UFG::SimObjectCharacterPropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                      src,
                                                                      UFG::SimObjectCharacterPropertiesComponent::_TypeUID);
              }
              else
              {
                v49 = (UFG::SimObjectCharacterPropertiesComponent *)UFG::SimObject::GetComponentOfType(
                                                                      src,
                                                                      UFG::SimObjectCharacterPropertiesComponent::_TypeUID);
              }
              if ( v49 )
              {
                v50 = v14->m_eFactionClass;
                v51 = v49->m_eFactionClass;
                v52 = UFG::FactionInterface::Get();
                if ( (unsigned int)UFG::FactionInterface::GetStanding(&v52->mFactionInterface, v51, v50) == 2 )
                {
                  UFG::GameStatTracker::ApplyDelta(v6, EnemiesKilled, 1);
                  UFG::OnlineEventManager::PostEvent((UFG::OnlineEventManager::Event)5, 1);
                  UFG::GameStatAction::MissionScoring::LogTriadEvent(TRIAD_KILL_HOSTILE, 0, &customCaption);
                }
              }
            }
          }
          if ( src )
          {
            v53 = src->m_Flags;
            if ( (v53 & 0x4000) != 0 )
            {
              m_pComponent = src->m_Components.p[7].m_pComponent;
            }
            else if ( v53 >= 0 )
            {
              if ( (v53 & 0x2000) != 0 )
              {
                m_pComponent = src->m_Components.p[6].m_pComponent;
              }
              else
              {
                v55 = (v53 & 0x1000) != 0
                    ? UFG::SimObjectGame::GetComponentOfTypeHK(src, UFG::ActionTreeComponent::_TypeUID)
                    : UFG::SimObject::GetComponentOfType(src, UFG::ActionTreeComponent::_TypeUID);
                m_pComponent = v55;
              }
            }
            else
            {
              m_pComponent = src->m_Components.p[7].m_pComponent;
            }
            if ( m_pComponent && !v41 )
            {
              v56 = _S10_8;
              if ( (_S10_8 & 1) == 0 )
              {
                _S10_8 |= 1u;
                TimeWarpVaultShootUID.mUID = UFG::qStringHashUpper32("VaultShoot", -1);
                v56 = _S10_8;
              }
              if ( (v56 & 2) != 0 )
              {
                MostUsedIndex = mostUsedIndex_TimeWarpVaultShootUID;
              }
              else
              {
                _S10_8 = v56 | 2;
                MostUsedIndex = GetMostUsedIndex(TimeWarpVaultShootUID.mUID);
                mostUsedIndex_TimeWarpVaultShootUID = MostUsedIndex;
              }
              if ( ActionController::IsPlaying(
                     (ActionController *)&m_pComponent[3],
                     &TimeWarpVaultShootUID,
                     MostUsedIndex,
                     1) )
              {
                v58 = UFG::qMalloc(0x48ui64, "GameStatEventTask", 0i64);
                if ( v58 )
                {
                  mName = UFG::gGameStatEventChannel.mName;
                  mUID = UFG::gGameStatEventChannel.mUID;
                  LocalPlayer = UFG::GetLocalPlayer();
                  v58[1].mNext = v58 + 1;
                  v58[2].mNext = v58 + 1;
                  v58->mNext = (UFG::allocator::free_link *)&UFG::Event::`vftable;
                  LODWORD(v58[3].mNext) = mUID;
                  v58[4].mNext = (UFG::allocator::free_link *)mName;
                  v58->mNext = (UFG::allocator::free_link *)&UFG::GameStatEvent::`vftable;
                  LODWORD(v58[7].mNext) = 88;
                  v58[8].mNext = (UFG::allocator::free_link *)LocalPlayer;
                }
                else
                {
                  v58 = 0i64;
                }
                UFG::EventDispatcher::DispatchEvent(&UFG::EventDispatcher::mInstance, (UFG::Event *)v58);
              }
            }
          }
          goto LABEL_139;
        }
LABEL_61:
        v34 = UFG::OSuiteLeaderboardManager::Instance();
        v35 = UFG::OSuiteLeaderboardManager::GetLeaderboardDataUsingLeaderboardName(v34, "StatGamesKillStreak");
        UFG::StatGameManager::UpdateScore(v35, 1, 1);
        goto LABEL_62;
      }
      v30 = v29->m_Flags;
      if ( (v30 & 0x4000) == 0 && v30 >= 0 )
      {
        if ( (v30 & 0x2000) != 0 )
        {
          v31 = UFG::SimObjectProp::GetComponent<UFG::SimObjectWeaponPropertiesComponent>(v29);
LABEL_57:
          if ( v31
            && v31->mWeaponTypeInfo->mFireModes[v31->mFireMode]->mSimObjectWeaponType == UFG::gSimObjectWeaponTypeTrackEnum_eSIM_OBJ_WEAPON_TYPE_STRAIGHT_SWORD.m_EnumValue )
          {
            v32 = UFG::OSuiteLeaderboardManager::Instance();
            v33 = UFG::OSuiteLeaderboardManager::GetLeaderboardDataUsingLeaderboardName(
                    v32,
                    "StatAwardsYaoguaiPeachwooded");
            UFG::DataSynchronizer::ApplyDeltaToGlobalSnapshot(v33, 1);
          }
          goto LABEL_60;
        }
        if ( (v30 & 0x1000) == 0 )
        {
          v31 = (UFG::SimObjectWeaponPropertiesComponent *)UFG::SimObject::GetComponentOfType(
                                                             v29,
                                                             UFG::SimObjectWeaponPropertiesComponent::_TypeUID);
          goto LABEL_57;
        }
      }
      v31 = (UFG::SimObjectWeaponPropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                         v29,
                                                         UFG::SimObjectWeaponPropertiesComponent::_TypeUID);
      goto LABEL_57;
    }
  }
}

// File Line: 1334
// RVA: 0x499D50
void __fastcall UFG::GameStatAction::Player::CountKills(UFG::SimObject *target)
{
  UFG::OSuiteLeaderboardManager *v2; // rax
  UFG::OSuiteLeaderboardData *LeaderboardDataUsingLeaderboardName; // rax
  UFG::OSuiteLeaderboardManager *v4; // rax
  UFG::OSuiteLeaderboardData *v5; // rax
  bool pIsCop; // [rsp+38h] [rbp+10h] BYREF
  bool pIsAmbient; // [rsp+40h] [rbp+18h] BYREF

  ++sKillsPerSession;
  v2 = UFG::OSuiteLeaderboardManager::Instance();
  LeaderboardDataUsingLeaderboardName = UFG::OSuiteLeaderboardManager::GetLeaderboardDataUsingLeaderboardName(
                                          v2,
                                          "StatAwardsPublicEnemy");
  UFG::DataSynchronizer::SetMaxToGlobalSnapshot(LeaderboardDataUsingLeaderboardName, sKillsPerSession);
  pIsCop = 0;
  pIsAmbient = 0;
  UFG::GameStatAction::MissionScoring::DeduceFaction(target, &pIsCop, &pIsAmbient);
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
  UFG::OSuiteLeaderboardData *LeaderboardDataUsingLeaderboardName; // rax

  v0 = _S12_6;
  v1 = &sGameStatTracker;
  if ( (_S12_6 & 1) == 0 )
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
  if ( (*((_BYTE *)v2 + 6216) & 1) == 0 )
  {
    ++v2->mpSnapshots[0]->mInts[158].mValue;
    if ( UFG::GameStatAction::PostStat::sIsEnabled )
    {
      if ( (v0 & 1) == 0 )
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
  LeaderboardDataUsingLeaderboardName = UFG::OSuiteLeaderboardManager::GetLeaderboardDataUsingLeaderboardName(
                                          v3,
                                          "StatAwardsMartialArtist");
  UFG::DataSynchronizer::ApplyDeltaToGlobalSnapshot(LeaderboardDataUsingLeaderboardName, 1);
}

// File Line: 1356
// RVA: 0x4AC970
bool __fastcall UFG::GameStatAction::Player::IsInVehicle(UFG::SimObjectGame *src)
{
  UFG::SimObjectCharacter *LocalPlayer; // rdi
  signed __int16 m_Flags; // cx
  UFG::VehicleDriverInterface *m_pComponent; // rax
  bool result; // al

  LocalPlayer = UFG::GetLocalPlayer();
  result = 0;
  if ( src )
  {
    m_Flags = src->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = (UFG::VehicleDriverInterface *)src->m_Components.p[23].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      m_pComponent = (UFG::VehicleDriverInterface *)((m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
                                                   ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                       src,
                                                       UFG::VehicleDriverInterface::_TypeUID)
                                                   : UFG::SimObject::GetComponentOfType(
                                                       src,
                                                       UFG::VehicleDriverInterface::_TypeUID));
    }
    else
    {
      m_pComponent = (UFG::VehicleDriverInterface *)src->m_Components.p[23].m_pComponent;
    }
    if ( m_pComponent && m_pComponent->mDriver.m_pPointer == LocalPlayer )
      return 1;
  }
  return result;
}

// File Line: 1372
// RVA: 0x4C90A0
bool __fastcall UFG::GameStatAction::WeaponIsDLC(UFG::SimObjectWeaponPropertiesComponent *WPC)
{
  unsigned int mUID; // ebx
  UFG::qSymbol v3; // [rsp+20h] [rbp-18h] BYREF
  UFG::qSymbol result; // [rsp+48h] [rbp+10h] BYREF
  UFG::qSymbol v5; // [rsp+50h] [rbp+18h] BYREF
  UFG::qSymbol v6; // [rsp+58h] [rbp+20h] BYREF

  UFG::SimObjectWeaponPropertiesComponent::GetWeaponID(WPC, &result);
  UFG::qSymbol::create_from_string(&v5, "object-physical-weapon-firearm-rifle-assault_dlc");
  mUID = result.mUID;
  if ( result.mUID == v5.mUID )
    return 1;
  UFG::qSymbol::create_from_string(&v6, "object-physical-weapon-firearm-smg-45cal_gold");
  if ( mUID == v6.mUID )
    return 1;
  UFG::qSymbol::create_from_string(&v3, "object-physical-weapon-melee-cleaver_Gold");
  return mUID == v3.mUID;
}

// File Line: 1387
// RVA: 0x4C1F60
char __fastcall UFG::GameStatAction::Player::SuccessfulWeaponKill(UFG::HitRecord *hitRec, bool killedInnocent)
{
  UFG::GameStatTracker *v4; // rdi
  UFG::GameStatTracker *v5; // rbx
  UFG::SimObjectWeaponPropertiesComponent *HoldingWeapon; // rax
  UFG::SimObjectWeaponPropertiesComponent *v7; // rbp
  UFG::GameStatTracker *v8; // rcx
  UFG::qSymbol *WeaponID; // rax
  UFG::GameStatTracker *v10; // rcx
  UFG::OSuiteLeaderboardManager *v11; // rax
  UFG::OSuiteLeaderboardData *LeaderboardDataUsingLeaderboardName; // rax
  unsigned int v13; // edx
  UFG::GameStatTracker *v14; // rcx
  int v15; // eax
  UFG::GameStat::Int32Stat v17; // edx
  UFG::qSymbol *v18; // rax
  UFG::OSuiteLeaderboardManager *v19; // rax
  UFG::OSuiteLeaderboardData *v20; // rax
  UFG::SimObject *m_pPointer; // rcx
  UFG::SimObjectCharacter *LocalPlayer; // rax
  UFG::SimObjectWeaponPropertiesComponent *v23; // rax
  UFG::qSymbol result; // [rsp+50h] [rbp+8h] BYREF

  v4 = &sGameStatTracker;
  if ( (_S12_6 & 1) == 0 )
  {
    _S12_6 |= 1u;
    UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
    atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
  }
  v5 = &sGameStatTracker;
  if ( UFG::GameStatTracker::mspInstance )
    v5 = UFG::GameStatTracker::mspInstance;
  UFG::GameStatTracker::mspInstance = v5;
  HoldingWeapon = UFG::GameStatAction::Weapon::GetHoldingWeapon((UFG::SimObjectGame *)hitRec->mAttacker.m_pPointer);
  v7 = HoldingWeapon;
  if ( HoldingWeapon )
  {
    if ( UFG::GameStatAction::WeaponIsDLC(HoldingWeapon) && (*((_BYTE *)v5 + 6216) & 1) == 0 )
    {
      ++v5->mpSnapshots[0]->mInts[161].mValue;
      if ( UFG::GameStatAction::PostStat::sIsEnabled )
      {
        if ( (_S12_6 & 1) == 0 )
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
    if ( hitRec->mProjectileInfo.m_pSOWPC.m_pPointer )
    {
      WeaponID = UFG::SimObjectWeaponPropertiesComponent::GetWeaponID(v7, &result);
      if ( (*((_BYTE *)v5 + 6216) & 1) == 0 )
      {
        UFG::PersistentData::MapInt::ApplyDelta(v5->mpSnapshots[0]->mpMapInts[28], WeaponID, 1);
        if ( UFG::GameStatAction::PostStat::sIsEnabled )
        {
          if ( (_S12_6 & 1) == 0 )
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
      LeaderboardDataUsingLeaderboardName = UFG::OSuiteLeaderboardManager::GetLeaderboardDataUsingLeaderboardName(
                                              v11,
                                              "StatAwardsGunman");
      UFG::DataSynchronizer::ApplyDeltaToGlobalSnapshot(LeaderboardDataUsingLeaderboardName, 1);
      if ( (*((_BYTE *)v5 + 6216) & 1) != 0
        || (++v5->mpSnapshots[0]->mInts[159].mValue, !UFG::GameStatAction::PostStat::sIsEnabled) )
      {
        v13 = _S12_6;
      }
      else
      {
        v13 = _S12_6;
        if ( (_S12_6 & 1) == 0 )
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
      v15 = **((_DWORD **)&hitRec->mProjectileInfo.m_pSOWPC.m_pPointer[2].m_BoundComponentHandles.mNode.mPrev->mNext
             + HIDWORD(hitRec->mProjectileInfo.m_pSOWPC.m_pPointer[2].m_pSimObject));
      if ( v15 == UFG::gSimObjectWeaponTypeTrackEnum_eSIM_OBJ_WEAPON_TYPE_PISTOL.m_EnumValue )
      {
        if ( (*((_BYTE *)v5 + 6216) & 1) == 0 )
        {
          ++v5->mpSnapshots[0]->mInts[104].mValue;
          if ( UFG::GameStatAction::PostStat::sIsEnabled )
          {
            if ( (v13 & 1) == 0 )
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
        v17 = RifleKills;
LABEL_42:
        UFG::GameStatTracker::ApplyDelta(v5, v17, 1);
        return 1;
      }
      if ( v15 == UFG::gSimObjectWeaponTypeTrackEnum_eSIM_OBJ_WEAPON_TYPE_SHOTGUN.m_EnumValue )
      {
        v17 = ShotgunKills;
        goto LABEL_42;
      }
      if ( v15 != UFG::gSimObjectWeaponTypeTrackEnum_eSIM_OBJ_WEAPON_TYPE_SMG.m_EnumValue )
      {
        if ( v15 != UFG::gSimObjectWeaponTypeTrackEnum_eSIM_OBJ_WEAPON_TYPE_SNIPER.m_EnumValue )
          return 1;
        v17 = SniperRifleKills;
        goto LABEL_42;
      }
      UFG::GameStatTracker::ApplyDelta(v5, MachineGunKills, 1);
    }
    else if ( hitRec->mMeleeInfo.mAttackMaterialUID == gAttackMaterialWeaponEquipped.m_EnumSymbol.mUID )
    {
      UFG::GameStatTracker::ApplyDelta(v5, MissionMeleeWeaponKills, 1);
      if ( sSym_CombatFish.mUID == UFG::SimObjectWeaponPropertiesComponent::GetWeaponID(v7, &result)->mUID )
        UFG::AchievementTrophyManager::UnlockAchievementTrophy(10);
      v18 = UFG::SimObjectWeaponPropertiesComponent::GetWeaponID(v7, &result);
      UFG::GameStatTracker::ApplyDelta(v5, MeleeWeaponKills, v18, 1);
      v19 = UFG::OSuiteLeaderboardManager::Instance();
      v20 = UFG::OSuiteLeaderboardManager::GetLeaderboardDataUsingLeaderboardName(v19, "StatAwardsHandyman");
      UFG::DataSynchronizer::ApplyDeltaToGlobalSnapshot(v20, 1);
      if ( !killedInnocent )
        UFG::GameStatAction::MissionScoring::LogTriadEvent(TRIAD_MELEE_WEAPON_STRIKE, 0, &customCaption);
      return 1;
    }
  }
  m_pPointer = hitRec->mAttacker.m_pPointer;
  if ( m_pPointer
    && m_pPointer->m_pSceneObj
    && UFG::SceneObjectProperties::GetArchetypeProperties(m_pPointer->m_pSceneObj)
    && UFG::SceneObjectProperties::GetArchetypePropertiesName(hitRec->mAttacker.m_pPointer->m_pSceneObj)->mUID == sSym_CombatFish.mUID )
  {
    UFG::AchievementTrophyManager::UnlockAchievementTrophy(10);
  }
  if ( (_S11_6 & 1) == 0 )
  {
    _S11_6 |= 1u;
    meleeAttack.mPath.mCount = 0;
    meleeAttack.mPath.mData.mOffset = 0i64;
    ActionPath::Append(
      &meleeAttack,
      "\\Global\\Player\\Attacks\\Grapples\\Grapple\\GrappleMoves\\Weapons\\HeavyDamage\\Baton\\GrapRCV");
    atexit(UFG::GameStatAction::Player::SuccessfulWeaponKill_::_47_::_dynamic_atexit_destructor_for__meleeAttack__);
  }
  if ( ActionPath::operator==(&hitRec->mMeleeInfo.mActionPath, &meleeAttack) )
  {
    LocalPlayer = UFG::GetLocalPlayer();
    v23 = UFG::GameStatAction::Weapon::GetHoldingWeapon(LocalPlayer);
    if ( sSym_CombatFish.mUID == UFG::SimObjectWeaponPropertiesComponent::GetWeaponID(v23, &result)->mUID )
      UFG::AchievementTrophyManager::UnlockAchievementTrophy(10);
  }
  return 0;
}sSym_CombatFish.mUID == UFG::SimObjectWeaponPropertiesComponent::GetWeaponID(v23, &result)->mUID )
      UFG::AchievementTrophyManager::UnlockAchievementTrophy(10);
  }
  return 0

// File Line: 1500
// RVA: 0x4C1A70
void __fastcall UFG::GameStatAction::Player::SuccessfulWeaponHit(UFG::HitRecord *hitRec, UFG::SimObjectCVBase *target)
{
  UFG::GameStatTracker *v4; // rdi
  UFG::qSymbol *WeaponID; // rax
  unsigned int v6; // edx
  UFG::GameStatTracker *v7; // rcx
  int v8; // eax
  UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject> *v9; // rcx
  const char *TypeName; // rax
  int size; // ebx
  signed __int16 m_Flags; // cx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::OSuiteLeaderboardManager *v14; // rax
  UFG::OSuiteLeaderboardData *LeaderboardDataUsingLeaderboardName; // rax
  UFG::OSuiteLeaderboardManager *v16; // rax
  UFG::OSuiteLeaderboardData *v17; // rax
  UFG::SimObjectCharacter *LocalPlayer; // rax
  UFG::GameStatAction::MissionScoring::CopScoreEvent v19; // ecx
  UFG::qSymbol *v20; // rax
  UFG::PersistentData::MapBool *v21; // rax
  __int64 v22; // rcx
  $CCFB32CF948EEB04FF452B3FEB4ECF53 *v23; // rax
  UFG::OSuiteLeaderboardManager *v24; // rax
  UFG::OSuiteLeaderboardData *v25; // rax
  UFG::qReflectHandleBase v26; // [rsp+28h] [rbp-50h] BYREF
  UFG::qSymbol result; // [rsp+80h] [rbp+8h] BYREF
  bool pIsAmbient; // [rsp+90h] [rbp+18h] BYREF

  if ( !hitRec->mProjectileInfo.m_pSOWPC.m_pPointer )
    return;
  v4 = UFG::GameStatTracker::Instance();
  WeaponID = UFG::SimObjectWeaponPropertiesComponent::GetWeaponID(
               (UFG::SimObjectWeaponPropertiesComponent *)hitRec->mProjectileInfo.m_pSOWPC.m_pPointer,
               &result);
  if ( (*((_BYTE *)v4 + 6216) & 1) != 0
    || (UFG::PersistentData::MapInt::ApplyDelta(v4->mpSnapshots[0]->mpMapInts[27], WeaponID, 1),
        !UFG::GameStatAction::PostStat::sIsEnabled) )
  {
    v6 = _S12_6;
  }
  else
  {
    v6 = _S12_6;
    if ( (_S12_6 & 1) == 0 )
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
  v8 = **((_DWORD **)&hitRec->mProjectileInfo.m_pSOWPC.m_pPointer[2].m_BoundComponentHandles.mNode.mPrev->mNext
        + HIDWORD(hitRec->mProjectileInfo.m_pSOWPC.m_pPointer[2].m_pSimObject));
  if ( v8 == UFG::gSimObjectWeaponTypeTrackEnum_eSIM_OBJ_WEAPON_TYPE_PISTOL.m_EnumValue )
  {
    if ( (*((_BYTE *)v4 + 6216) & 1) == 0 )
    {
      ++v4->mpSnapshots[0]->mInts[103].mValue;
      if ( UFG::GameStatAction::PostStat::sIsEnabled )
      {
        if ( (v6 & 1) != 0 )
          goto LABEL_25;
LABEL_24:
        _S12_6 = v6 | 1;
        UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
        atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
LABEL_25:
        if ( !UFG::GameStatTracker::mspInstance )
          UFG::GameStatTracker::mspInstance = &sGameStatTracker;
      }
    }
  }
  else if ( v8 == UFG::gSimObjectWeaponTypeTrackEnum_eSIM_OBJ_WEAPON_TYPE_RIFLE.m_EnumValue )
  {
    if ( (*((_BYTE *)v4 + 6216) & 1) == 0 )
    {
      ++v4->mpSnapshots[0]->mInts[112].mValue;
      if ( UFG::GameStatAction::PostStat::sIsEnabled )
      {
        if ( (v6 & 1) != 0 )
          goto LABEL_25;
        goto LABEL_24;
      }
    }
  }
  else
  {
    if ( v8 != UFG::gSimObjectWeaponTypeTrackEnum_eSIM_OBJ_WEAPON_TYPE_SHOTGUN.m_EnumValue )
    {
      if ( v8 == UFG::gSimObjectWeaponTypeTrackEnum_eSIM_OBJ_WEAPON_TYPE_SMG.m_EnumValue )
      {
        if ( (*((_BYTE *)v4 + 6216) & 1) == 0 )
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
    if ( (*((_BYTE *)v4 + 6216) & 1) == 0 )
    {
      ++v4->mpSnapshots[0]->mInts[115].mValue;
      if ( UFG::GameStatAction::PostStat::sIsEnabled )
      {
        if ( (v6 & 1) != 0 )
          goto LABEL_25;
        goto LABEL_24;
      }
    }
  }
LABEL_33:
  UFG::qReflectHandleBase::qReflectHandleBase(&v26);
  TypeName = UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject>::GetTypeName(v9);
  v26.mTypeUID = UFG::qStringHash64(TypeName, 0xFFFFFFFFFFFFFFFFui64);
  UFG::qReflectHandleBase::Init(&v26, v26.mTypeUID, hitRec->mCollisionInfo.mPhysicsObjectPropertyHandleUID);
  size = 0;
  if ( v26.mData && HIDWORD(v26.mData[4].mBaseNode.mParent) == -392267045 )
  {
    if ( !target
      || ((m_Flags = target->m_Flags, (m_Flags & 0x4000) == 0)
        ? (m_Flags >= 0
         ? ((m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
          ? (ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(target, UFG::HealthComponent::_TypeUID))
          : (ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(target, UFG::HealthComponent::_TypeUID)))
         : (ComponentOfTypeHK = target->m_Components.p[6].m_pComponent))
        : (ComponentOfTypeHK = target->m_Components.p[6].m_pComponent),
          !ComponentOfTypeHK
       || !BYTE5(ComponentOfTypeHK[1].m_BoundComponentHandles.mNode.mPrev)
       && BYTE6(ComponentOfTypeHK[1].m_BoundComponentHandles.mNode.mPrev)) )
    {
      v14 = UFG::OSuiteLeaderboardManager::Instance();
      LeaderboardDataUsingLeaderboardName = UFG::OSuiteLeaderboardManager::GetLeaderboardDataUsingLeaderboardName(
                                              v14,
                                              "StatAwardsHeadhunter");
      UFG::DataSynchronizer::ApplyDeltaToGlobalSnapshot(LeaderboardDataUsingLeaderboardName, 1);
      v16 = UFG::OSuiteLeaderboardManager::Instance();
      v17 = UFG::OSuiteLeaderboardManager::GetLeaderboardDataUsingLeaderboardName(v16, "StatGamesHeadShots");
      UFG::StatGameManager::UpdateScore(v17, 1, 1);
      LOBYTE(result.mUID) = 0;
      pIsAmbient = 0;
      UFG::GameStatAction::MissionScoring::DeduceFaction(target, (bool *)&result, &pIsAmbient);
      if ( LOBYTE(result.mUID) || pIsAmbient )
      {
        v19 = COP_PEDESTRIAN_KILL;
        if ( LOBYTE(result.mUID) )
          v19 = COP_KILL;
        UFG::GameStatAction::MissionScoring::LogCopEvent(v19, 0, &customCaption);
      }
      else if ( !target || (LocalPlayer = UFG::GetLocalPlayer(), !UFG::AreCharactersAllied(LocalPlayer, target)) )
      {
        UFG::GameStatAction::MissionScoring::LogTriadEvent(TRIAD_KILL_HEAD_SHOT, 0, &customCaption);
      }
    }
  }
  if ( (*((_BYTE *)v4 + 6216) & 1) == 0 )
  {
    ++v4->mpSnapshots[0]->mInts[101].mValue;
    if ( UFG::GameStatAction::PostStat::sIsEnabled )
      UFG::GameStatAction::PostStat::AchieveInt(ShotsHit);
  }
  v20 = (UFG::qSymbol *)UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&result, v4->mpSnapshots[0]->mInts[100].mValue % 50);
  UFG::GameStatTracker::SetStat(v4, Last50ShotsBoolList, v20, 1);
  v21 = v4->mpSnapshots[0]->mpMapBools[84];
  if ( v21->mKeepType != KEEP_FALSE )
  {
    if ( v21->mKeepType == KEEP_TRUE )
    {
      size = v21->mNames.size;
    }
    else
    {
      v22 = v21->mValues.size;
      if ( (_DWORD)v22 )
      {
        v23 = &v21->mValues.p->4;
        do
        {
          if ( v23->mBoolValue )
            ++size;
          v23 += 2;
          --v22;
        }
        while ( v22 );
      }
    }
  }
  v24 = UFG::OSuiteLeaderboardManager::Instance();
  v25 = UFG::OSuiteLeaderboardManager::GetLeaderboardDataUsingLeaderboardName(v24, "StatAwardsSniper");
  UFG::DataSynchronizer::SetMaxToGlobalSnapshot(v25, (float)((float)size * 100.0) * 0.02);
  UFG::qReflectHandleBase::~qReflectHandleBase(&v26);
}

// File Line: 1641
// RVA: 0x4B5F10
void __fastcall UFG::GameStatAction::World::RegisterZone(unsigned int currentZone)
{
  char v2; // r12
  UFG::PersistentData::MapBool *v3; // rax
  unsigned int size; // ecx
  __int64 v5; // rdx
  $CCFB32CF948EEB04FF452B3FEB4ECF53 *v6; // rax
  bool v7; // r15
  UFG::PersistentData::Time *v8; // rbx
  UFG::PersistentData::Time *v9; // rsi
  UFG::PersistentData::Time *v10; // rbp
  UFG::PersistentData::Time *v11; // r14
  char v12; // r13
  UFG::SimpleTimer *p_mTimer; // rcx
  float ElapsedSeconds; // xmm0_4
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

  if ( UFG::GameStatAction::World::sCurrentZone == currentZone )
    return;
  v2 = 1;
  v3 = UFG::GameStatTracker::Instance()->mpSnapshots[0]->mpMapBools[12];
  if ( v3->mKeepType == KEEP_FALSE )
  {
    size = 0;
  }
  else if ( v3->mKeepType == KEEP_TRUE )
  {
    size = v3->mNames.size;
  }
  else
  {
    size = 0;
    v5 = v3->mValues.size;
    if ( (_DWORD)v5 )
    {
      v6 = &v3->mValues.p->4;
      do
      {
        if ( v6->mBoolValue )
          ++size;
        v6 += 2;
        --v5;
      }
      while ( v5 );
    }
  }
  v7 = size != 0;
  v8 = &UFG::GameStatTracker::Instance()->mpSnapshots[0]->mTimes[7];
  v9 = &UFG::GameStatTracker::Instance()->mpSnapshots[0]->mTimes[8];
  v10 = &UFG::GameStatTracker::Instance()->mpSnapshots[0]->mTimes[9];
  v11 = &UFG::GameStatTracker::Instance()->mpSnapshots[0]->mTimes[10];
  v12 = 0;
  v23 = 0;
  v25 = 0;
  v24 = 0;
  if ( currentZone == UFG::ZoneTag::smNorthPoint )
  {
    v12 = 1;
    if ( v7 )
    {
      UFG::SimpleTimer::Resume(&v11->mTimer);
      p_mTimer = &v8->mTimer;
LABEL_17:
      UFG::SimpleTimer::Stop(p_mTimer);
      UFG::SimpleTimer::Stop(&v9->mTimer);
      UFG::SimpleTimer::Stop(&v10->mTimer);
    }
  }
  else
  {
    if ( currentZone != UFG::ZoneTag::smAberdeen )
    {
      if ( currentZone == UFG::ZoneTag::smKennedyTown )
      {
        v25 = 1;
        if ( v7 )
        {
          UFG::SimpleTimer::Resume(&v10->mTimer);
          UFG::SimpleTimer::Stop(&v8->mTimer);
          UFG::SimpleTimer::Stop(&v9->mTimer);
          UFG::SimpleTimer::Stop(&v11->mTimer);
        }
      }
      else if ( currentZone == UFG::ZoneTag::smCentral )
      {
        v24 = 1;
        if ( v7 )
        {
          UFG::SimpleTimer::Resume(&v9->mTimer);
          UFG::SimpleTimer::Stop(&v8->mTimer);
          UFG::SimpleTimer::Stop(&v11->mTimer);
          UFG::SimpleTimer::Stop(&v10->mTimer);
        }
      }
      else
      {
        UFG::SimpleTimer::Stop(&v9->mTimer);
        UFG::SimpleTimer::Stop(&v8->mTimer);
        UFG::SimpleTimer::Stop(&v11->mTimer);
        UFG::SimpleTimer::Stop(&v10->mTimer);
        v2 = 0;
      }
      goto LABEL_25;
    }
    v23 = 1;
    if ( v7 )
    {
      UFG::SimpleTimer::Resume(&v8->mTimer);
      p_mTimer = &v11->mTimer;
      goto LABEL_17;
    }
  }
LABEL_25:
  ElapsedSeconds = UFG::SimpleTimer::GetElapsedSeconds(&v8->mTimer);
  v15 = v23;
  if ( ElapsedSeconds > 0.0 )
    v15 = 1;
  v16 = v24;
  if ( UFG::SimpleTimer::GetElapsedSeconds(&v9->mTimer) > 0.0 )
    v16 = 1;
  v17 = v25;
  if ( UFG::SimpleTimer::GetElapsedSeconds(&v10->mTimer) > 0.0 )
    v17 = 1;
  v18 = UFG::SimpleTimer::GetElapsedSeconds(&v11->mTimer);
  v19 = v12;
  if ( v18 > 0.0 )
    v19 = 1;
  if ( v15 && v16 && v17 && v19 )
    UFG::AchievementTrophyManager::UnlockAchievementTrophy(12);
  UFG::GameStatAction::World::sCurrentZone = currentZone;
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
      LODWORD(v21[7].mNext) = currentZone;
    }
    else
    {
      v21 = 0i64;
    }
    UFG::UIScreenManagerBase::queueMessageEx(UFG::UIScreenManager::s_instance, (UFG::UIMessage *)v21);
  }
}

// File Line: 1746
// RVA: 0x4C7890
void __fastcall UFG::GameStatAction::Inventory::UpdateItem(UFG::eInventoryItemEnum eItem, int iAmount)
{
  __int64 v3; // rsi
  UFG::GameStatTracker *v4; // rbx
  UFG::GameStatTracker *v5; // rcx

  v3 = eItem;
  v4 = &sGameStatTracker;
  if ( (_S12_6 & 1) == 0 )
  {
    _S12_6 |= 1u;
    UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
    atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
  }
  v5 = &sGameStatTracker;
  if ( UFG::GameStatTracker::mspInstance )
    v5 = UFG::GameStatTracker::mspInstance;
  UFG::GameStatTracker::mspInstance = v5;
  if ( (*((_BYTE *)v5 + 6216) & 1) == 0 )
  {
    UFG::PersistentData::MapInt::SetStatus(
      v5->mpSnapshots[0]->mpMapInts[15],
      &UFG::InventoryItemEnumSymbols[v3],
      iAmount);
    if ( UFG::GameStatAction::PostStat::sIsEnabled )
    {
      if ( (_S12_6 & 1) == 0 )
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
  UFG::GameStatTracker *v2; // rdi
  UFG::qStaticSymbol *v3; // r9
  signed __int64 v4; // rbx
  __int64 v5; // r11
  UFG::PersistentData::MapInt *v6; // rcx
  unsigned int size; // edx
  __int64 v8; // rax
  UFG::PersistentData::KeyValue *p; // r10
  UFG::PersistentData::KeyValue *v10; // rcx
  unsigned int mIntValue; // eax

  v2 = &sGameStatTracker;
  if ( (_S12_6 & 1) == 0 )
  {
    _S12_6 |= 1u;
    UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
    atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
  }
  if ( UFG::GameStatTracker::mspInstance )
    v2 = UFG::GameStatTracker::mspInstance;
  UFG::GameStatTracker::mspInstance = v2;
  v3 = UFG::InventoryItemEnumSymbols;
  v4 = (char *)pIC - (char *)UFG::InventoryItemEnumSymbols;
  v5 = 209i64;
  do
  {
    v6 = v2->mpSnapshots[0]->mpMapInts[15];
    size = v6->mValues.size;
    v8 = 0i64;
    if ( !v6->mValues.size )
      goto LABEL_13;
    p = v6->mValues.p;
    v10 = p;
    while ( v10->mKey.mUID != v3->mUID )
    {
      v8 = (unsigned int)(v8 + 1);
      ++v10;
      if ( (unsigned int)v8 >= size )
        goto LABEL_13;
    }
    if ( (_DWORD)v8 == -1 )
LABEL_13:
      mIntValue = 0;
    else
      mIntValue = p[v8].mIntValue;
    *(unsigned int *)((char *)&v3[23].mUID + v4) = mIntValue;
    ++v3;
    --v5;
  }
  while ( v5 );
}

// File Line: 1764
// RVA: 0x49E1B0
void __fastcall UFG::GameStatAction::Inventory::Equip(UFG::SimObjectProp *pSimObject)
{
  signed __int16 m_Flags; // cx
  UFG::SimObjectWeaponPropertiesComponent *ComponentOfTypeHK; // rax
  UFG::GameStatTracker *v4; // rdi
  UFG::qSymbol *ArchetypePropertiesName; // rax
  signed __int16 v6; // cx
  UFG::GunComponent *ComponentOfType; // rax
  int ClipAmmo; // eax
  UFG::GameStatTracker *v9; // rbx

  if ( !pSimObject )
    return;
  m_Flags = pSimObject->m_Flags;
  if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
    goto LABEL_8;
  if ( (m_Flags & 0x2000) != 0 )
  {
    ComponentOfTypeHK = UFG::SimObjectProp::GetComponent<UFG::SimObjectWeaponPropertiesComponent>(pSimObject);
    goto LABEL_10;
  }
  if ( (m_Flags & 0x1000) != 0 )
LABEL_8:
    ComponentOfTypeHK = (UFG::SimObjectWeaponPropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                     pSimObject,
                                                                     UFG::SimObjectWeaponPropertiesComponent::_TypeUID);
  else
    ComponentOfTypeHK = (UFG::SimObjectWeaponPropertiesComponent *)UFG::SimObject::GetComponentOfType(
                                                                     pSimObject,
                                                                     UFG::SimObjectWeaponPropertiesComponent::_TypeUID);
LABEL_10:
  if ( ComponentOfTypeHK )
  {
    v4 = UFG::GameStatTracker::Instance();
    ArchetypePropertiesName = UFG::SceneObjectProperties::GetArchetypePropertiesName(pSimObject->m_pSceneObj);
    if ( (*((_BYTE *)v4 + 6216) & 1) == 0 )
      v4->mpSnapshots[0]->mIDs[22].mValue = (UFG::qSymbol)ArchetypePropertiesName->mUID;
    v6 = pSimObject->m_Flags;
    if ( (v6 & 0x4000) != 0 || v6 < 0 || (v6 & 0x2000) != 0 || (v6 & 0x1000) != 0 )
      ComponentOfType = (UFG::GunComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                               pSimObject,
                                               UFG::GunComponent::_TypeUID);
    else
      ComponentOfType = (UFG::GunComponent *)UFG::SimObject::GetComponentOfType(pSimObject, UFG::GunComponent::_TypeUID);
    if ( ComponentOfType )
    {
      ClipAmmo = UFG::GunComponent::GetClipAmmo(ComponentOfType);
      if ( (*((_BYTE *)v4 + 6216) & 1) == 0 )
      {
        v4->mpSnapshots[0]->mInts[46].mValue = ClipAmmo;
        if ( UFG::GameStatAction::PostStat::sIsEnabled )
        {
          v9 = &sGameStatTracker;
          if ( (_S12_6 & 1) == 0 )
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

// File Line: 1784
// RVA: 0x4C36F0
void __fastcall UFG::GameStatAction::Inventory::UnequipAllWeapons(const bool bClearInventory)
{
  UFG::GameStatTracker *v2; // rdi
  UFG::GameStatTracker *v3; // rbx
  UFG::qPropertySet *PropertySet; // rax
  UFG::qPropertySet *v5; // rsi
  char *v6; // rax
  UFG::qSymbol *v7; // rax
  UFG::qStaticSymbol *v8; // rdx
  UFG::GameStatTracker *v9; // rcx
  UFG::qPropertySet *v10; // rax
  char *MemImagePtr; // rax
  int EnumFromSymbol; // eax
  UFG::qPropertySet *v13; // rax
  UFG::qPropertySet *v14; // rsi
  char *v15; // rax
  UFG::qSymbol *v16; // rax
  UFG::qStaticSymbol *v17; // rdx
  UFG::qPropertySet *v18; // rax
  char *v19; // rax
  int v20; // eax
  UFG::qSymbol propSetName; // [rsp+68h] [rbp+10h] BYREF
  UFG::qSymbol result; // [rsp+70h] [rbp+18h] BYREF
  UFG::qSymbol v23; // [rsp+78h] [rbp+20h] BYREF

  v2 = &sGameStatTracker;
  if ( (_S12_6 & 1) == 0 )
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
    if ( bClearInventory )
    {
      PropertySet = UFG::PropertySetManager::FindPropertySet(&propSetName);
      v5 = PropertySet;
      if ( PropertySet )
      {
        v6 = UFG::qPropertySet::Get<char const *>(
               PropertySet,
               (UFG::qArray<unsigned long,0> *)&PhysicsSym_AmmoInventoryItem,
               DEPTH_RECURSE);
        if ( v6 )
        {
          v7 = UFG::qSymbol::create_from_string(&result, v6);
          v8 = &UFG::InventoryItemEnumSymbols[(int)TracksEnum<unsigned long>::GetEnumFromSymbol(
                                                     &UFG::gInventoryItemTracksEnum,
                                                     v7)];
          if ( (*((_BYTE *)v3 + 6216) & 1) == 0 )
          {
            UFG::PersistentData::MapInt::SetStatus(v3->mpSnapshots[0]->mpMapInts[15], v8, 0);
            if ( UFG::GameStatAction::PostStat::sIsEnabled )
            {
              if ( (_S12_6 & 1) == 0 )
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
                (UFG::qArray<unsigned long,0> *)&component_InventoryItem::sPropertyName,
                DEPTH_RECURSE);
        if ( v10 )
        {
          MemImagePtr = UFG::qPropertySet::GetMemImagePtr(v10);
          if ( MemImagePtr )
          {
            result.mUID = *((_DWORD *)MemImagePtr + 2);
            if ( result.mUID != -1 )
            {
              EnumFromSymbol = TracksEnum<unsigned long>::GetEnumFromSymbol(&UFG::gInventoryItemTracksEnum, &result);
              UFG::GameStatTracker::SetStat(v3, InventoryItems, &UFG::InventoryItemEnumSymbols[EnumFromSymbol], 0);
            }
          }
        }
      }
    }
    if ( (*((_BYTE *)v3 + 6216) & 1) == 0 )
      v3->mpSnapshots[0]->mIDs[23].mValue = UFG::gNullQSymbol;
  }
  v23.mUID = v3->mpSnapshots[0]->mIDs[24].mValue.mUID;
  if ( v23.mUID != -1 )
  {
    if ( bClearInventory )
    {
      v13 = UFG::PropertySetManager::FindPropertySet(&v23);
      v14 = v13;
      if ( v13 )
      {
        v15 = UFG::qPropertySet::Get<char const *>(
                v13,
                (UFG::qArray<unsigned long,0> *)&PhysicsSym_AmmoInventoryItem,
                DEPTH_RECURSE);
        if ( v15 )
        {
          v16 = UFG::qSymbol::create_from_string(&result, v15);
          v17 = &UFG::InventoryItemEnumSymbols[(int)TracksEnum<unsigned long>::GetEnumFromSymbol(
                                                      &UFG::gInventoryItemTracksEnum,
                                                      v16)];
          if ( (*((_BYTE *)v3 + 6216) & 1) == 0 )
          {
            UFG::PersistentData::MapInt::SetStatus(v3->mpSnapshots[0]->mpMapInts[15], v17, 0);
            if ( UFG::GameStatAction::PostStat::sIsEnabled )
            {
              if ( (_S12_6 & 1) == 0 )
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
                (UFG::qArray<unsigned long,0> *)&component_InventoryItem::sPropertyName,
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
              UFG::GameStatTracker::SetStat(v3, InventoryItems, &UFG::InventoryItemEnumSymbols[v20], 0);
            }
          }
        }
      }
    }
    if ( (*((_BYTE *)v3 + 6216) & 1) == 0 )
      v3->mpSnapshots[0]->mIDs[24].mValue = UFG::gNullQSymbol;
  }
}

// File Line: 1859
// RVA: 0x4C34B0
void __fastcall UFG::GameStatAction::Inventory::UnEquip(const bool bClearInventory)
{
  unsigned int v2; // edx
  UFG::GameStatTracker *v3; // rbx
  UFG::GameStatTracker *v4; // rdi
  UFG::qPropertySet *PropertySet; // rax
  UFG::qPropertySet *v6; // rsi
  char *v7; // rax
  UFG::qSymbol *v8; // rax
  UFG::qStaticSymbol *v9; // rdx
  UFG::GameStatTracker *v10; // rcx
  UFG::qPropertySet *v11; // rax
  char *MemImagePtr; // rax
  int EnumFromSymbol; // eax
  UFG::qSymbol propSetName; // [rsp+58h] [rbp+10h] BYREF
  UFG::qSymbol result; // [rsp+60h] [rbp+18h] BYREF

  v2 = _S12_6;
  v3 = &sGameStatTracker;
  if ( (_S12_6 & 1) == 0 )
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
  if ( bClearInventory )
  {
    PropertySet = UFG::PropertySetManager::FindPropertySet(&propSetName);
    v6 = PropertySet;
    if ( PropertySet )
    {
      v7 = UFG::qPropertySet::Get<char const *>(
             PropertySet,
             (UFG::qArray<unsigned long,0> *)&PhysicsSym_AmmoInventoryItem,
             DEPTH_RECURSE);
      if ( v7 )
      {
        v8 = UFG::qSymbol::create_from_string(&result, v7);
        v9 = &UFG::InventoryItemEnumSymbols[(int)TracksEnum<unsigned long>::GetEnumFromSymbol(
                                                   &UFG::gInventoryItemTracksEnum,
                                                   v8)];
        if ( (*((_BYTE *)v4 + 6216) & 1) == 0 )
        {
          UFG::PersistentData::MapInt::SetStatus(v4->mpSnapshots[0]->mpMapInts[15], v9, 0);
          if ( UFG::GameStatAction::PostStat::sIsEnabled )
          {
            if ( (_S12_6 & 1) == 0 )
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
              (UFG::qArray<unsigned long,0> *)&component_InventoryItem::sPropertyName,
              DEPTH_RECURSE);
      if ( v11 )
      {
        MemImagePtr = UFG::qPropertySet::GetMemImagePtr(v11);
        if ( MemImagePtr )
        {
          result.mUID = *((_DWORD *)MemImagePtr + 2);
          if ( result.mUID != -1 )
          {
            EnumFromSymbol = TracksEnum<unsigned long>::GetEnumFromSymbol(&UFG::gInventoryItemTracksEnum, &result);
            UFG::GameStatTracker::SetStat(v4, InventoryItems, &UFG::InventoryItemEnumSymbols[EnumFromSymbol], 0);
          }
        }
      }
    }
    v2 = _S12_6;
  }
  if ( (*((_BYTE *)v4 + 6216) & 1) == 0 )
  {
    v4->mpSnapshots[0]->mIDs[22].mValue = UFG::gNullQSymbol;
LABEL_23:
    if ( (*((_BYTE *)v4 + 6216) & 1) == 0 )
    {
      v4->mpSnapshots[0]->mInts[46].mValue = 0;
      if ( UFG::GameStatAction::PostStat::sIsEnabled )
      {
        if ( (v2 & 1) == 0 )
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
void __fastcall UFG::GameStatAction::Inventory::RestoreEquipped(
        UFG::InventoryComponent *pIC,
        UFG::qSymbol *weaponOverride)
{
  UFG::GameSnapshot *v4; // r8
  unsigned int mUID; // r8d
  UFG::qPropertySet *v6; // rbx
  UFG::qPropertySet *PropertySet; // rax
  UFG::qPropertySet *v8; // rdi
  UFG::qPropertySet *v9; // rsi
  UFG::qPropertySet *ParentFromName; // rax
  bool v11; // bp
  UFG::qPropertySet *v12; // rax
  UFG::SimObjectGame *v13; // rax
  UFG::SimObject *v14; // rdi
  __int16 m_Flags; // dx
  UFG::RigidBody *ComponentOfTypeHK; // rax
  UFG::SimObjectGame *v17; // rax
  UFG::SimObject *v18; // rbx
  __int16 v19; // dx
  UFG::RigidBody *ComponentOfType; // rax
  UFG::qSymbol v21; // [rsp+60h] [rbp+8h] BYREF
  UFG::qSymbol propSetName; // [rsp+70h] [rbp+18h] BYREF
  UFG::qSymbol result; // [rsp+78h] [rbp+20h] BYREF

  if ( pIC )
  {
    v4 = UFG::GameStatTracker::Instance()->mpSnapshots[0];
    propSetName.mUID = v4->mIDs[23].mValue.mUID;
    mUID = v4->mIDs[24].mValue.mUID;
    v21.mUID = mUID;
    if ( propSetName.mUID == -1 )
    {
      v6 = 0i64;
    }
    else
    {
      PropertySet = UFG::PropertySetManager::FindPropertySet(&propSetName);
      mUID = v21.mUID;
      v6 = PropertySet;
    }
    if ( mUID == -1 )
      v8 = 0i64;
    else
      v8 = UFG::PropertySetManager::FindPropertySet(&v21);
    if ( weaponOverride->mUID == -1 )
      v9 = 0i64;
    else
      v9 = UFG::PropertySetManager::FindPropertySet(weaponOverride);
    if ( v6 )
      ParentFromName = UFG::qPropertySet::GetParentFromName(
                         v6,
                         (UFG::qArray<unsigned long,0> *)&SimSymX_propset_componentGun,
                         DEPTH_RECURSE);
    else
      ParentFromName = 0i64;
    v11 = ParentFromName != 0i64;
    if ( v8 )
      v12 = UFG::qPropertySet::GetParentFromName(
              v8,
              (UFG::qArray<unsigned long,0> *)&SimSymX_propset_componentGun,
              DEPTH_RECURSE);
    else
      v12 = 0i64;
    if ( !v11 && !v12 && v9 )
      v6 = v9;
    if ( v8 )
    {
      UFG::Simulation::GenerateUniqueName(&UFG::gSim, &result, "RestoredWeaponStowed");
      v13 = (UFG::SimObjectGame *)UFG::SpawnInfoInterface::SpawnObject(&result, v8, UnReferenced, 0i64, 0i64, 0i64);
      v14 = v13;
      if ( v13 )
      {
        m_Flags = v13->m_Flags;
        if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
          ComponentOfTypeHK = (UFG::RigidBody *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                  v13,
                                                  UFG::RigidBodyComponent::_TypeUID);
        else
          ComponentOfTypeHK = (UFG::RigidBody *)UFG::SimObject::GetComponentOfType(
                                                  v13,
                                                  UFG::RigidBodyComponent::_TypeUID);
        if ( ComponentOfTypeHK )
          UFG::RigidBody::SetMotionType(ComponentOfTypeHK, 0x100u);
        UFG::InventoryComponent::Equip(pIC, v14, 1, eINVENTORY_EQUIP_SLOT_RIGHT_HAND);
        UFG::InventoryComponent::Stow(pIC, eINVENTORY_EQUIP_SLOT_RIGHT_HAND, eINVENTORY_EQUIP_SLOT_STOWED_1H);
      }
    }
    if ( v6 )
    {
      UFG::Simulation::GenerateUniqueName(&UFG::gSim, &result, "RestoredWeaponEquipped");
      v17 = (UFG::SimObjectGame *)UFG::SpawnInfoInterface::SpawnObject(&result, v6, UnReferenced, 0i64, 0i64, 0i64);
      v18 = v17;
      if ( v17 )
      {
        v19 = v17->m_Flags;
        if ( (v19 & 0x4000) != 0 || v19 < 0 || (v19 & 0x2000) != 0 || (v19 & 0x1000) != 0 )
          ComponentOfType = (UFG::RigidBody *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                v17,
                                                UFG::RigidBodyComponent::_TypeUID);
        else
          ComponentOfType = (UFG::RigidBody *)UFG::SimObject::GetComponentOfType(v17, UFG::RigidBodyComponent::_TypeUID);
        if ( ComponentOfType )
          UFG::RigidBody::SetMotionType(ComponentOfType, 0x100u);
        UFG::InventoryComponent::Equip(pIC, v18, 1, eINVENTORY_EQUIP_SLOT_RIGHT_HAND);
      }
    }
  }
}

// File Line: 2048
// RVA: 0x494F40
char __fastcall UFG::GameStatAction::Store::AreAllItemsPurchased(
        UFG::qSymbol *store,
        UFG::GameStat::MapBoolStat snapShotEntry)
{
  __int64 v2; // r13
  UFG::qPropertySet *PropertySet; // rbx
  UFG::qArray<unsigned long,0> *v4; // rax
  UFG::qPropertyList *v5; // rax
  UFG::qPropertyList *v6; // r15
  char v7; // r14
  unsigned int mNumElements; // r12d
  unsigned int v9; // ebp
  char *ValuePtr; // rax
  UFG::qPropertySet *v11; // rsi
  float *v12; // rax
  float *v13; // rcx
  unsigned int v14; // ebx
  UFG::GameStatTracker *v15; // rdi
  UFG::GameStatTracker *v16; // rax
  float v18; // [rsp+90h] [rbp+18h] BYREF
  UFG::qSymbol result; // [rsp+98h] [rbp+20h] BYREF

  v2 = snapShotEntry;
  PropertySet = UFG::PropertySetManager::GetPropertySet(store);
  if ( !PropertySet )
    return 0;
  v4 = (UFG::qArray<unsigned long,0> *)UFG::qSymbol::create_from_string(&result, "Items");
  v5 = UFG::qPropertySet::Get<UFG::qPropertyList>(PropertySet, v4, DEPTH_RECURSE);
  v6 = v5;
  if ( !v5 )
    return 0;
  v7 = 1;
  mNumElements = v5->mNumElements;
  v9 = 0;
  if ( mNumElements )
  {
    v18 = FLOAT_N1_0;
    do
    {
      ValuePtr = UFG::qPropertyList::GetValuePtr(v6, 0x1Au, v9);
      if ( !ValuePtr || (v11 = (UFG::qPropertySet *)&ValuePtr[*(_QWORD *)ValuePtr], !*(_QWORD *)ValuePtr) )
        v11 = 0i64;
      v12 = UFG::qPropertySet::Get<float>(
              v11,
              (UFG::qArray<unsigned long,0> *)&UFG::StoreItemSymbol_Price,
              DEPTH_RECURSE);
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
        if ( (_S12_6 & 1) == 0 )
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
      if ( (v14 & 1) == 0 )
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
    while ( v9 < mNumElements );
  }
  return v7;
}

// File Line: 2095
// RVA: 0x494F00
char __fastcall UFG::GameStatAction::Store::AreAllClothesPurchased()
{
  UFG::qSymbol *v0; // rax
  UFG::qSymbol result; // [rsp+40h] [rbp+8h] BYREF
  UFG::qSymbol *p_result; // [rsp+48h] [rbp+10h]

  p_result = &result;
  v0 = UFG::qSymbol::create_from_string(&result, "default-unlockables-merchantdatabase-clothing");
  return UFG::GameStatAction::Store::AreAllItemsPurchased((__int64)v0, Asset_Clothing);
}

// File Line: 2100
// RVA: 0x495140
char __fastcall UFG::GameStatAction::Store::AreAllVehiclesPurchased()
{
  UFG::qSymbol *v0; // rax
  UFG::qSymbol result; // [rsp+40h] [rbp+8h] BYREF
  UFG::qSymbol *p_result; // [rsp+48h] [rbp+10h]

  p_result = &result;
  v0 = UFG::qSymbol::create_from_string(&result, "default-unlockables-merchantdatabase-vehicles");
  return UFG::GameStatAction::Store::AreAllItemsPurchased(v0, Asset_Vehicle);
}

// File Line: 2106
// RVA: 0x4B6240
void __fastcall UFG::GameStatAction::Weapon::Reload(UFG::GunComponent *pGC)
{
  UFG::GameStatTracker *v2; // rbx
  int ClipAmmo; // eax
  UFG::qSymbol mapid; // [rsp+48h] [rbp+10h] BYREF
  UFG::qSymbol *p_mapid; // [rsp+50h] [rbp+18h]

  v2 = &sGameStatTracker;
  if ( (_S12_6 & 1) == 0 )
  {
    _S12_6 |= 1u;
    UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
    atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
  }
  if ( UFG::GameStatTracker::mspInstance )
    v2 = UFG::GameStatTracker::mspInstance;
  UFG::GameStatTracker::mspInstance = v2;
  ClipAmmo = UFG::GunComponent::GetClipAmmo(pGC);
  if ( (*((_BYTE *)v2 + 6216) & 1) == 0 )
  {
    v2->mpSnapshots[0]->mInts[46].mValue = ClipAmmo;
    p_mapid = &mapid;
    mapid.mUID = UFG::gNullQSymbol.mUID;
    UFG::GameStatAction::PostStat::Achieve(PDT_INT, ClipAmmo, &mapid.mUID);
  }
}

// File Line: 2116
// RVA: 0x49D1D0
void __fastcall UFG::GameStatAction::Weapon::Discharge(UFG::GunComponent *pGC)
{
  UFG::GameStatTracker *v2; // rbx
  int ClipAmmo; // eax
  CAkScheduledItem *SimObjectWeaponPropertiesComponent; // rax
  int v5; // eax
  unsigned int v6; // eax
  UFG::qSymbol *v7; // rax
  UFG::SimObjectWeaponPropertiesComponent *v8; // rax
  UFG::qSymbol *WeaponID; // rax
  unsigned int *p_mUID; // rdi
  unsigned int v11; // eax
  UFG::qSymbol mapid; // [rsp+58h] [rbp+10h] BYREF
  UFG::qSymbol *result; // [rsp+60h] [rbp+18h] BYREF
  UFG::qSymbol *p_mapid; // [rsp+68h] [rbp+20h]

  if ( (_S12_6 & 1) == 0 )
  {
    _S12_6 |= 1u;
    UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
    atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
  }
  v2 = &sGameStatTracker;
  if ( UFG::GameStatTracker::mspInstance )
    v2 = UFG::GameStatTracker::mspInstance;
  UFG::GameStatTracker::mspInstance = v2;
  ClipAmmo = UFG::GunComponent::GetClipAmmo(pGC);
  if ( (*((_BYTE *)v2 + 6216) & 1) == 0 )
  {
    v2->mpSnapshots[0]->mInts[46].mValue = ClipAmmo;
    result = &mapid;
    mapid.mUID = UFG::gNullQSymbol.mUID;
    UFG::GameStatAction::PostStat::Achieve(PDT_INT, ClipAmmo, &mapid.mUID);
  }
  SimObjectWeaponPropertiesComponent = UFG::GunComponent::GetSimObjectWeaponPropertiesComponent((CAkChainCtx *)pGC);
  v5 = **(_DWORD **)(*(_QWORD *)&SimObjectWeaponPropertiesComponent[2].m_cmdStop.iRelativeTime
                   + 8i64 * (unsigned int)SimObjectWeaponPropertiesComponent[2].m_cmdPlay.fadeParams.iFadeOffset
                   + 8);
  if ( v5 == UFG::gSimObjectWeaponTypeTrackEnum_eSIM_OBJ_WEAPON_TYPE_PISTOL.m_EnumValue )
  {
    if ( (*((_BYTE *)v2 + 6216) & 1) == 0 )
    {
      ++v2->mpSnapshots[0]->mInts[102].mValue;
      if ( UFG::GameStatAction::PostStat::sIsEnabled )
      {
        v6 = _S12_6;
        if ( (_S12_6 & 1) != 0 )
          goto LABEL_27;
LABEL_26:
        _S12_6 = v6 | 1;
        UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
        atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
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
    if ( (*((_BYTE *)v2 + 6216) & 1) == 0 )
    {
      ++v2->mpSnapshots[0]->mInts[111].mValue;
      if ( UFG::GameStatAction::PostStat::sIsEnabled )
      {
        v6 = _S12_6;
        if ( (_S12_6 & 1) != 0 )
          goto LABEL_27;
        goto LABEL_26;
      }
LABEL_31:
      if ( (*((_BYTE *)v2 + 6216) & 1) == 0 )
      {
        ++v2->mpSnapshots[0]->mInts[100].mValue;
        if ( UFG::GameStatAction::PostStat::sIsEnabled )
          UFG::GameStatAction::PostStat::AchieveInt(ShotsMade);
      }
    }
  }
  else if ( v5 == UFG::gSimObjectWeaponTypeTrackEnum_eSIM_OBJ_WEAPON_TYPE_SHOTGUN.m_EnumValue )
  {
    if ( (*((_BYTE *)v2 + 6216) & 1) == 0 )
    {
      ++v2->mpSnapshots[0]->mInts[114].mValue;
      if ( UFG::GameStatAction::PostStat::sIsEnabled )
      {
        v6 = _S12_6;
        if ( (_S12_6 & 1) != 0 )
          goto LABEL_27;
        goto LABEL_26;
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
    if ( (*((_BYTE *)v2 + 6216) & 1) == 0 )
    {
      ++v2->mpSnapshots[0]->mInts[105].mValue;
      if ( UFG::GameStatAction::PostStat::sIsEnabled )
      {
        v6 = _S12_6;
        if ( (_S12_6 & 1) != 0 )
          goto LABEL_27;
        goto LABEL_26;
      }
      goto LABEL_31;
    }
  }
  v7 = (UFG::qSymbol *)UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&mapid, v2->mpSnapshots[0]->mInts[100].mValue % 50);
  UFG::GameStatTracker::SetStat(v2, Last50ShotsBoolList, v7, 0);
  v8 = (UFG::SimObjectWeaponPropertiesComponent *)UFG::GunComponent::GetSimObjectWeaponPropertiesComponent((CAkChainCtx *)pGC);
  WeaponID = UFG::SimObjectWeaponPropertiesComponent::GetWeaponID(v8, (UFG::qSymbol *)&result);
  p_mUID = &WeaponID->mUID;
  if ( (*((_BYTE *)v2 + 6216) & 1) == 0 )
  {
    UFG::PersistentData::MapInt::ApplyDelta(v2->mpSnapshots[0]->mpMapInts[26], WeaponID, 1);
    v11 = *p_mUID;
    if ( UFG::GameStatAction::PostStat::sIsEnabled )
    {
      p_mapid = &mapid;
      mapid.mUID = v11;
      UFG::GameStatAction::PostStat::AchieveMapInt(FireArmFired, (UFG::qSymbol)&mapid);
    }
  }
}

// File Line: 2167
// RVA: 0x4A3460
UFG::SimObjectWeaponPropertiesComponent *__fastcall UFG::GameStatAction::Weapon::GetHoldingWeapon(
        UFG::SimObjectGame *holder)
{
  signed __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rdx
  UFG::SimComponent *v3; // rax
  UFG::SimObjectProp *v4; // rcx
  __int16 v5; // dx
  unsigned int v6; // edx
  bool v8; // zf

  if ( holder )
  {
    m_Flags = holder->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = holder->m_Components.p[20].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      v3 = (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
         ? UFG::SimObjectGame::GetComponentOfTypeHK(holder, UFG::TargetingSystemBaseComponent::_TypeUID)
         : UFG::SimObject::GetComponentOfType(holder, UFG::TargetingSystemBaseComponent::_TypeUID);
      m_pComponent = v3;
    }
    else
    {
      m_pComponent = holder->m_Components.p[20].m_pComponent;
    }
    if ( m_pComponent )
    {
      v4 = *(UFG::SimObjectProp **)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&m_pComponent[1].m_Flags + 25i64)
                                  + *(_QWORD *)&m_pComponent[1].m_TypeUID
                                  + 40);
      if ( v4 )
      {
        v5 = v4->m_Flags;
        if ( (v5 & 0x4000) != 0 || v5 < 0 )
        {
          v6 = UFG::SimObjectWeaponPropertiesComponent::_TypeUID;
        }
        else
        {
          if ( (v5 & 0x2000) != 0 )
            return UFG::SimObjectProp::GetComponent<UFG::SimObjectWeaponPropertiesComponent>(v4);
          v8 = (v5 & 0x1000) == 0;
          v6 = UFG::SimObjectWeaponPropertiesComponent::_TypeUID;
          if ( v8 )
            return (UFG::SimObjectWeaponPropertiesComponent *)UFG::SimObject::GetComponentOfType(
                                                                v4,
                                                                UFG::SimObjectWeaponPropertiesComponent::_TypeUID);
        }
        return (UFG::SimObjectWeaponPropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v4, v6);
      }
    }
  }
  return 0i64;
}

// File Line: 2202
// RVA: 0x4B9EA0
void __fastcall UFG::GameStatAction::Money::SendTransactionTelemetry(
        UFG::qSymbol *origin,
        UFG::qSymbol *itemName,
        int amount)
{
  UFG::GameStatTracker *v6; // rbx
  int v7; // edi
  UFG::GameSlice *mpActiveMaster; // rcx
  UFG::qSymbol *p_mUID; // rcx
  int mUID; // ebx
  UFG::OSuiteDBLogger *v11; // rsi
  int v12; // edi
  int v13; // edi
  char dest[128]; // [rsp+30h] [rbp-98h] BYREF

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
  v7 = v6->mpSnapshots[0]->mInts[62].mValue - amount;
  mpActiveMaster = UFG::ProgressionTracker::Instance()->mpActiveMaster;
  if ( !mpActiveMaster || mpActiveMaster->mInternalSlice )
    p_mUID = &UFG::gNullQSymbol;
  else
    p_mUID = (UFG::qSymbol *)&mpActiveMaster->mNode.mUID;
  mUID = p_mUID->mUID;
  v11 = UFG::OSuiteDBLogger::Instance();
  if ( UFG::OSuiteDBLogger::CreateMetric(v11, "MoneyTransaction") )
  {
    UFG::qSPrintf(dest, 128, "i32_%s", "MoneyBeforeTransaction");
    OSuite::ZMetric::SetProperty(v11->m_pMetric, dest, v7);
    UFG::qSPrintf(dest, 128, "i32_%s", "TransactionValue");
    OSuite::ZMetric::SetProperty(v11->m_pMetric, dest, amount);
    v12 = itemName->mUID;
    UFG::qSPrintf(dest, 128, "i32_%s", "ItemPurchased");
    OSuite::ZMetric::SetProperty(v11->m_pMetric, dest, v12);
    v13 = origin->mUID;
    UFG::qSPrintf(dest, 128, "i32_%s", "LocationType");
    OSuite::ZMetric::SetProperty(v11->m_pMetric, dest, v13);
    UFG::qSPrintf(dest, 128, "i32_%s", "ContentName");
    OSuite::ZMetric::SetProperty(v11->m_pMetric, dest, mUID);
    UFG::OSuiteDBLogger::SubmitMetric(v11, 1);
  }
}

// File Line: 2232
// RVA: 0x4B3110
void __fastcall UFG::GameStatAction::Money::PurchaseItem(
        UFG::SimObject *pOrigin,
        UFG::eInventoryItemEnum inventory,
        int cost)
{
  __int64 v4; // r14
  unsigned int v6; // r8d
  UFG::GameStatTracker *v7; // rsi
  UFG::GameStatTracker *v8; // rbx
  UFG::GameStatTracker *v9; // rcx
  UFG::GameSnapshot *v10; // rax
  int mValue; // r8d
  UFG::qSymbol *p_m_Name; // rax
  int v13; // eax
  UFG::GameSnapshot *v14; // rdx
  int v15; // ecx
  int mRange; // eax
  UFG::qSymbol *v17; // rax
  UFG::OSuiteLeaderboardManager *v18; // rax
  UFG::OSuiteLeaderboardData *LeaderboardDataUsingLeaderboardName; // rax
  char *p_result; // rcx
  UFG::qSymbol *v21; // rax
  UFG::OSuiteLeaderboardManager *v22; // rax
  UFG::OSuiteLeaderboardData *v23; // rax
  UFG::OSuiteLeaderboardManager *v24; // rax
  UFG::OSuiteLeaderboardData *v25; // rax
  char v26; // [rsp+70h] [rbp+8h] BYREF
  UFG::qSymbol origin; // [rsp+78h] [rbp+10h] BYREF
  UFG::qWiseSymbol result; // [rsp+80h] [rbp+18h] BYREF
  char v29; // [rsp+88h] [rbp+20h] BYREF

  v4 = inventory;
  v6 = _S12_6;
  v7 = &sGameStatTracker;
  if ( (_S12_6 & 1) == 0 )
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
  if ( (*((_BYTE *)v8 + 6216) & 1) == 0 )
  {
    v8->mpSnapshots[0]->mInts[62].mValue -= cost;
    if ( UFG::GameStatAction::PostStat::sIsEnabled )
    {
      if ( (v6 & 1) == 0 )
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
      mValue = v10->mInts[62].mValue;
      if ( v10->mInts[63].mValue < mValue )
        UFG::GameStatTracker::SetStat(v9, MostCashHeld, mValue);
    }
  }
  p_m_Name = &pOrigin->m_Name;
  if ( !pOrigin )
    p_m_Name = &UFG::gNullQSymbol;
  origin.mUID = p_m_Name->mUID;
  UFG::GameStatAction::Money::SendTransactionTelemetry(&origin, &UFG::InventoryItemEnumSymbols[v4], -cost);
  switch ( v13 )
  {
    case 0:
      if ( (*((_BYTE *)v8 + 6216) & 1) == 0 )
      {
        v8->mpSnapshots[0]->mInts[70].mValue += cost;
        if ( UFG::GameStatAction::PostStat::sIsEnabled )
        {
          if ( (_S12_6 & 1) == 0 )
          {
            _S12_6 |= 1u;
            UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
            atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
          }
          if ( UFG::GameStatTracker::mspInstance )
            v7 = UFG::GameStatTracker::mspInstance;
          UFG::GameStatTracker::mspInstance = v7;
        }
        if ( (*((_BYTE *)v8 + 6216) & 1) == 0 )
        {
          v14 = v8->mpSnapshots[0];
          v15 = 0;
          if ( v14->mIntsRanged[0].mValue + 1 > 0 )
            v15 = v14->mIntsRanged[0].mValue + 1;
          mRange = v14->mIntsRanged[0].mRange;
          if ( v15 < mRange )
            mRange = v15;
          v14->mIntsRanged[0].mValue = mRange;
        }
      }
      goto LABEL_79;
    case 1:
      if ( (*((_BYTE *)v8 + 6216) & 1) == 0 )
      {
        v8->mpSnapshots[0]->mInts[75].mValue += cost;
        if ( UFG::GameStatAction::PostStat::sIsEnabled )
        {
          if ( (_S12_6 & 1) == 0 )
          {
            _S12_6 |= 1u;
            UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
            atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
          }
          if ( UFG::GameStatTracker::mspInstance )
            v7 = UFG::GameStatTracker::mspInstance;
          UFG::GameStatTracker::mspInstance = v7;
        }
        if ( (*((_BYTE *)v8 + 6216) & 1) == 0 )
        {
          ++v8->mpSnapshots[0]->mInts[82].mValue;
          if ( UFG::GameStatAction::PostStat::sIsEnabled )
            UFG::GameStatAction::PostStat::AchieveInt(PorkBunsPurchased);
          if ( (*((_BYTE *)v8 + 6216) & 1) == 0 )
          {
            ++v8->mpSnapshots[0]->mInts[83].mValue;
            if ( UFG::GameStatAction::PostStat::sIsEnabled )
              UFG::GameStatAction::PostStat::AchieveInt(FoodPurchased);
          }
        }
      }
      v17 = (UFG::qSymbol *)UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&origin, v4);
      UFG::GameStatTracker::SetStat(v8, FoodPurchasedBoolList, v17, 1);
      v18 = UFG::OSuiteLeaderboardManager::Instance();
      LeaderboardDataUsingLeaderboardName = UFG::OSuiteLeaderboardManager::GetLeaderboardDataUsingLeaderboardName(
                                              v18,
                                              "StatAwardsBigSpender");
      UFG::DataSynchronizer::ApplyDeltaToGlobalSnapshot(LeaderboardDataUsingLeaderboardName, cost);
      UFG::OnlineEventManager::PostEvent(Vehicle, 1);
      return;
    case 2:
      if ( (*((_BYTE *)v8 + 6216) & 1) == 0 )
      {
        ++v8->mpSnapshots[0]->mInts[83].mValue;
        if ( UFG::GameStatAction::PostStat::sIsEnabled )
          UFG::GameStatAction::PostStat::AchieveInt(FoodPurchased);
      }
      p_result = (char *)&result;
      goto LABEL_47;
    case 3:
      if ( (*((_BYTE *)v8 + 6216) & 1) == 0 )
      {
        v8->mpSnapshots[0]->mInts[72].mValue += cost;
        if ( UFG::GameStatAction::PostStat::sIsEnabled )
          UFG::GameStatAction::PostStat::AchieveInt(CashSpentOnEnergyDrinks);
        if ( (*((_BYTE *)v8 + 6216) & 1) == 0 )
        {
          ++v8->mpSnapshots[0]->mInts[79].mValue;
          if ( UFG::GameStatAction::PostStat::sIsEnabled )
            UFG::GameStatAction::PostStat::AchieveInt(EnergyDrinksPurchased);
        }
      }
      p_result = &v26;
      goto LABEL_47;
    case 4:
      if ( (*((_BYTE *)v8 + 6216) & 1) == 0 )
      {
        v8->mpSnapshots[0]->mInts[73].mValue += cost;
        if ( UFG::GameStatAction::PostStat::sIsEnabled )
          UFG::GameStatAction::PostStat::AchieveInt(CashSpentOnMassages);
        if ( (*((_BYTE *)v8 + 6216) & 1) == 0 )
        {
          ++v8->mpSnapshots[0]->mInts[80].mValue;
          if ( UFG::GameStatAction::PostStat::sIsEnabled )
            UFG::GameStatAction::PostStat::AchieveInt(MassagesPurchased);
        }
      }
      goto LABEL_79;
    case 5:
      if ( (*((_BYTE *)v8 + 6216) & 1) == 0 )
      {
        v8->mpSnapshots[0]->mInts[74].mValue += cost;
        if ( UFG::GameStatAction::PostStat::sIsEnabled )
          UFG::GameStatAction::PostStat::AchieveInt(CashSpentOnHerbalTea);
        if ( (*((_BYTE *)v8 + 6216) & 1) == 0 )
        {
          ++v8->mpSnapshots[0]->mInts[81].mValue;
          if ( UFG::GameStatAction::PostStat::sIsEnabled )
            UFG::GameStatAction::PostStat::AchieveInt(HerbalTeaPurchased);
        }
      }
      p_result = &v29;
LABEL_47:
      v21 = (UFG::qSymbol *)UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)p_result, v4);
      UFG::GameStatTracker::SetStat(v8, FoodPurchasedBoolList, v21, 1);
      goto LABEL_79;
    case 6:
      if ( (*((_BYTE *)v8 + 6216) & 1) == 0 )
      {
        v8->mpSnapshots[0]->mInts[76].mValue += cost;
        if ( UFG::GameStatAction::PostStat::sIsEnabled )
          UFG::GameStatAction::PostStat::AchieveInt(CashSpentOnTaxis);
      }
      goto LABEL_79;
    case 7:
      if ( (*((_BYTE *)v8 + 6216) & 1) == 0 )
      {
        v8->mpSnapshots[0]->mInts[69].mValue += cost;
        if ( UFG::GameStatAction::PostStat::sIsEnabled )
          UFG::GameStatAction::PostStat::AchieveInt(CashSpentOnClothes);
      }
      v22 = UFG::OSuiteLeaderboardManager::Instance();
      v23 = UFG::OSuiteLeaderboardManager::GetLeaderboardDataUsingLeaderboardName(v22, "StatAwardsBigSpender");
      UFG::DataSynchronizer::ApplyDeltaToGlobalSnapshot(v23, cost);
      UFG::OnlineEventManager::PostEvent(NumEntityTypes, cost);
      return;
    case 8:
      if ( (*((_BYTE *)v8 + 6216) & 1) == 0 )
      {
        v8->mpSnapshots[0]->mInts[77].mValue += cost;
        if ( UFG::GameStatAction::PostStat::sIsEnabled )
          UFG::GameStatAction::PostStat::AchieveInt(CashSpentOnSafehouseDecor);
      }
      UFG::GameStatTracker::SetStat(v8, Collectible_SafehouseItems, &UFG::InventoryItemEnumSymbols[v4], 1);
LABEL_79:
      v24 = UFG::OSuiteLeaderboardManager::Instance();
      v25 = UFG::OSuiteLeaderboardManager::GetLeaderboardDataUsingLeaderboardName(v24, "StatAwardsBigSpender");
      UFG::DataSynchronizer::ApplyDeltaToGlobalSnapshot(v25, cost);
      break;
    case 9:
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
  return atexit((int (__fastcall *)())UFG::GameStatAction::_dynamic_atexit_destructor_for__clothingSymbol__);
}

// File Line: 2409
// RVA: 0x1530520
__int64 UFG::GameStatAction::_dynamic_initializer_for__vehicleSymbol__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("Vehicle", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::GameStatAction::vehicleSymbol, v0);
  return atexit((int (__fastcall *)())UFG::GameStatAction::_dynamic_atexit_destructor_for__vehicleSymbol__);
}

// File Line: 2412
// RVA: 0x4B2E80
void __fastcall UFG::GameStatAction::Money::PurchaseItem(
        UFG::SimObject *pOrigin,
        UFG::StoreFront::InventoryType inventory,
        int cost)
{
  unsigned int v6; // r9d
  UFG::GameStatTracker *v7; // rbx
  UFG::GameStatTracker *v8; // rdi
  UFG::GameStatTracker *v9; // rcx
  UFG::GameSnapshot *v10; // rax
  int mValue; // r8d
  int v12; // ebp
  UFG::GameSnapshot *v13; // rdx
  int v14; // ecx
  int mRange; // eax
  UFG::qSymbol *p_m_Name; // rax
  UFG::qStaticSymbol *v17; // rdx
  UFG::OSuiteLeaderboardManager *v18; // rax
  UFG::OSuiteLeaderboardData *LeaderboardDataUsingLeaderboardName; // rax
  UFG::qSymbol origin; // [rsp+58h] [rbp+10h] BYREF

  v6 = _S12_6;
  v7 = &sGameStatTracker;
  if ( (_S12_6 & 1) == 0 )
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
  if ( (*((_BYTE *)v8 + 6216) & 1) == 0 )
  {
    v8->mpSnapshots[0]->mInts[62].mValue -= cost;
    if ( UFG::GameStatAction::PostStat::sIsEnabled )
    {
      if ( (v6 & 1) == 0 )
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
      mValue = v10->mInts[62].mValue;
      if ( v10->mInts[63].mValue < mValue )
      {
        UFG::GameStatTracker::SetStat(v9, MostCashHeld, mValue);
        v6 = _S12_6;
      }
    }
  }
  v12 = inventory - 61;
  if ( v12 )
  {
    if ( v12 != 1 )
      return;
    if ( (*((_BYTE *)v8 + 6216) & 1) == 0 )
    {
      v8->mpSnapshots[0]->mInts[71].mValue += cost;
      if ( UFG::GameStatAction::PostStat::sIsEnabled )
      {
        if ( (v6 & 1) == 0 )
        {
          _S12_6 = v6 | 1;
          UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
          atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
        }
        if ( UFG::GameStatTracker::mspInstance )
          v7 = UFG::GameStatTracker::mspInstance;
        UFG::GameStatTracker::mspInstance = v7;
      }
      if ( (*((_BYTE *)v8 + 6216) & 1) == 0 )
      {
        v13 = v8->mpSnapshots[0];
        v14 = 0;
        if ( v13->mIntsRanged[1].mValue + 1 > 0 )
          v14 = v13->mIntsRanged[1].mValue + 1;
        mRange = v13->mIntsRanged[1].mRange;
        if ( v14 < mRange )
          mRange = v14;
        v13->mIntsRanged[1].mValue = mRange;
      }
    }
    p_m_Name = &pOrigin->m_Name;
    if ( !pOrigin )
      p_m_Name = &UFG::gNullQSymbol;
    v17 = &UFG::GameStatAction::vehicleSymbol;
  }
  else
  {
    if ( (*((_BYTE *)v8 + 6216) & 1) == 0 )
    {
      v8->mpSnapshots[0]->mInts[69].mValue += cost;
      if ( UFG::GameStatAction::PostStat::sIsEnabled )
      {
        if ( (v6 & 1) == 0 )
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
    UFG::OnlineEventManager::PostEvent(NumEntityTypes, cost);
    p_m_Name = &pOrigin->m_Name;
    if ( !pOrigin )
      p_m_Name = &UFG::gNullQSymbol;
    v17 = &UFG::GameStatAction::clothingSymbol;
  }
  origin.mUID = p_m_Name->mUID;
  UFG::GameStatAction::Money::SendTransactionTelemetry(&origin, v17, -cost);
  v18 = UFG::OSuiteLeaderboardManager::Instance();
  LeaderboardDataUsingLeaderboardName = UFG::OSuiteLeaderboardManager::GetLeaderboardDataUsingLeaderboardName(
                                          v18,
                                          "StatAwardsBigSpender");
  UFG::DataSynchronizer::ApplyDeltaToGlobalSnapshot(LeaderboardDataUsingLeaderboardName, cost);
}

// File Line: 2441
// RVA: 0x49F850
void __fastcall UFG::GameStatAction::Money::Exchange(UFG::SimObject *pMerchant, int reason, int cost)
{
  unsigned int v5; // ecx
  UFG::GameStatTracker *v6; // rbx
  UFG::GameStatTracker *v7; // rdx
  UFG::GameStatTracker *v8; // rcx
  UFG::GameSnapshot *v9; // rax
  int mValue; // r8d
  UFG::GameStatTracker *v11; // rax
  UFG::GameStatTracker *v12; // rcx
  UFG::OSuiteLeaderboardManager *v13; // rax
  UFG::OSuiteLeaderboardData *LeaderboardDataUsingLeaderboardName; // rax
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
  UFG::qWiseSymbol *p_result; // rcx
  UFG::qSymbol *v29; // rbx
  UFG::GameStatTracker *v30; // rax
  UFG::GameStatTracker *v31; // rax
  UFG::OSuiteLeaderboardManager *v32; // rax
  UFG::OSuiteLeaderboardData *v33; // rax
  UFG::qWiseSymbol result; // [rsp+48h] [rbp+10h] BYREF
  char v35; // [rsp+50h] [rbp+18h] BYREF

  v5 = _S12_6;
  v6 = &sGameStatTracker;
  if ( (_S12_6 & 1) == 0 )
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
  if ( (*((_BYTE *)v7 + 6216) & 1) == 0 )
  {
    v7->mpSnapshots[0]->mInts[62].mValue += cost;
    if ( UFG::GameStatAction::PostStat::sIsEnabled )
    {
      if ( (v5 & 1) == 0 )
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
      mValue = v9->mInts[62].mValue;
      if ( v9->mInts[63].mValue < mValue )
        UFG::GameStatTracker::SetStat(v8, MostCashHeld, mValue);
    }
  }
  if ( cost > 0 )
  {
    v11 = UFG::GameStatTracker::Instance();
    if ( (*((_BYTE *)v11 + 6216) & 1) == 0 )
    {
      v11->mpSnapshots[0]->mInts[61].mValue += cost;
      if ( UFG::GameStatAction::PostStat::sIsEnabled )
      {
        if ( (_S12_6 & 1) == 0 )
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
    LeaderboardDataUsingLeaderboardName = UFG::OSuiteLeaderboardManager::GetLeaderboardDataUsingLeaderboardName(
                                            v13,
                                            "StatAwardsMogul");
    UFG::DataSynchronizer::ApplyDeltaToGlobalSnapshot(LeaderboardDataUsingLeaderboardName, cost);
  }
  switch ( reason )
  {
    case 1:
      if ( cost <= 0 )
      {
        if ( cost < 0 )
          cost = -cost;
        v16 = UFG::GameStatTracker::Instance();
        UFG::GameStatTracker::ApplyDelta(v16, GamblingLoss, cost);
      }
      else
      {
        v15 = UFG::GameStatTracker::Instance();
        if ( (*((_BYTE *)v15 + 6216) & 1) == 0 )
        {
          v15->mpSnapshots[0]->mInts[64].mValue += cost;
          if ( UFG::GameStatAction::PostStat::sIsEnabled )
          {
            if ( (_S12_6 & 1) == 0 )
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
      UFG::GameStatTracker::ApplyDelta(v21, BusDriverEarnings, cost);
      return;
    case 3:
      v22 = UFG::GameStatTracker::Instance();
      UFG::GameStatTracker::ApplyDelta(v22, LimoDriverEarnings, cost);
      return;
    case 4:
      v23 = UFG::GameStatTracker::Instance();
      UFG::GameStatTracker::ApplyDelta(v23, RepoEarnings, cost);
      return;
    case 8:
      v24 = cost;
      if ( cost < 0 )
        v24 = -cost;
      v25 = UFG::GameStatTracker::Instance();
      UFG::GameStatTracker::ApplyDelta(v25, CashSpentOnEnergyDrinks, v24);
      v26 = UFG::GameStatTracker::Instance();
      if ( (*((_BYTE *)v26 + 6216) & 1) == 0 )
      {
        ++v26->mpSnapshots[0]->mInts[79].mValue;
        if ( UFG::GameStatAction::PostStat::sIsEnabled )
        {
          if ( (_S12_6 & 1) == 0 )
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
      p_result = &result;
      goto LABEL_47;
    case 9:
    case 10:
      goto $LN2_36;
    case 11:
      v31 = UFG::GameStatTracker::Instance();
      UFG::GameStatTracker::ApplyDelta(v31, FoodPurchased, 1);
      v27 = 26;
      p_result = (UFG::qWiseSymbol *)&v35;
LABEL_47:
      v29 = (UFG::qSymbol *)UFG::qSymbol::qSymbol(p_result, v27);
      v30 = UFG::GameStatTracker::Instance();
      UFG::GameStatTracker::SetStat(v30, FoodPurchasedBoolList, v29, 1);
$LN2_36:
      if ( cost < 0 )
        cost = -cost;
      v32 = UFG::OSuiteLeaderboardManager::Instance();
      v33 = UFG::OSuiteLeaderboardManager::GetLeaderboardDataUsingLeaderboardName(v32, "StatAwardsBigSpender");
      UFG::DataSynchronizer::ApplyDeltaToGlobalSnapshot(v33, cost);
      break;
    default:
      return;
  }
}

// File Line: 2553
// RVA: 0x4B97C0
void __fastcall UFG::GameStatAction::GameSliceAction::SendTelemetryStat(UFG::GameSlice *gameslice)
{
  UFG::OSuiteDBLogger *v2; // rsi
  UFG::GameStatTracker *v3; // r14
  int mUID; // ebx
  const char *mData; // rbx
  int v6; // ebx
  int v7; // ebx
  int v8; // ebx
  float mValue; // xmm6_4
  float v10; // xmm6_4
  float v11; // xmm6_4
  float v12; // xmm6_4
  char *v13; // rbx
  float ElapsedSeconds; // xmm0_4
  float v15; // xmm0_4
  UFG::SimpleTimer *v16; // rcx
  float v17; // xmm0_4
  float v18; // xmm0_4
  float v19; // xmm0_4
  UFG::GameStatTracker *v20; // rbx
  int v21; // ecx
  int v22; // ebx
  int TriadScore; // edi
  int v24; // ebx
  int v25; // ebx
  int v26; // ebx
  int v27; // ebx
  UFG::NameValueColumnType *i; // rbx
  UFG::qNode<UFG::NameValueColumnType,UFG::NameValueColumnType> *mPrev; // rdx
  UFG::qNode<UFG::NameValueColumnType,UFG::NameValueColumnType> *mNext; // rax
  __int64 *v31; // rcx
  UFG::NameValueColumnType *v32; // rax
  __int64 *v33; // [rsp+18h] [rbp-79h] BYREF
  UFG::NameValueColumnType *v34; // [rsp+20h] [rbp-71h]
  char dest[128]; // [rsp+28h] [rbp-69h] BYREF
  UFG::qString v36; // [rsp+A8h] [rbp+17h] BYREF
  __int64 v37; // [rsp+D0h] [rbp+3Fh]

  v37 = -2i64;
  v2 = UFG::OSuiteDBLogger::Instance();
  if ( UFG::OSuiteDBLogger::CreateMetric(v2, "MissionAttempt") )
  {
    v3 = UFG::GameStatTracker::Instance();
    v33 = (__int64 *)&v33;
    v34 = (UFG::NameValueColumnType *)&v33;
    mUID = v3->mpSnapshots[0]->mIDs[43].mValue.mUID;
    if ( mUID != -1 )
    {
      UFG::qSPrintf(dest, 128, "i32_%s", "EventType");
      OSuite::ZMetric::SetProperty(v2->m_pMetric, dest, mUID);
    }
    mData = v3->mpSnapshots[0]->mStrings[24].mValue.mData;
    UFG::qSPrintf(dest, 128, "s_%s", "EventDesc");
    OSuite::ZMetric::SetProperty(v2->m_pMetric, dest, mData);
    v6 = v3->mpSnapshots[0]->mIDs[32].mValue.mUID;
    if ( v6 != -1 )
    {
      UFG::qSPrintf(dest, 128, "i32_%s", "KilledNameEnemy");
      OSuite::ZMetric::SetProperty(v2->m_pMetric, dest, v6);
    }
    v7 = v3->mpSnapshots[0]->mIDs[33].mValue.mUID;
    if ( v7 != -1 )
    {
      UFG::qSPrintf(dest, 128, "i32_%s", "KilledNameWeapon");
      OSuite::ZMetric::SetProperty(v2->m_pMetric, dest, v7);
    }
    v8 = v3->mpSnapshots[0]->mIDs[34].mValue.mUID;
    if ( v8 != -1 )
    {
      UFG::qSPrintf(dest, 128, "i32_%s", "PlayerWeaponName");
      OSuite::ZMetric::SetProperty(v2->m_pMetric, dest, v8);
    }
    mValue = v3->mpSnapshots[0]->mFloats[135].mValue;
    UFG::qSPrintf(dest, 128, "f_%s", "CopScore");
    OSuite::ZMetric::SetProperty(v2->m_pMetric, dest, mValue);
    v10 = v3->mpSnapshots[0]->mFloats[136].mValue;
    UFG::qSPrintf(dest, 128, "f_%s", "TriadScore");
    OSuite::ZMetric::SetProperty(v2->m_pMetric, dest, v10);
    v11 = v3->mpSnapshots[0]->mFloats[137].mValue;
    UFG::qSPrintf(dest, 128, "f_%s", "RangedDamageReceived");
    OSuite::ZMetric::SetProperty(v2->m_pMetric, dest, v11);
    v12 = v3->mpSnapshots[0]->mFloats[138].mValue;
    UFG::qSPrintf(dest, 128, "f_%s", "MeleeDamageReceived");
    OSuite::ZMetric::SetProperty(v2->m_pMetric, dest, v12);
    UFG::qString::qString(&v36);
    switch ( gameslice->mTrackType )
    {
      case 1:
        UFG::qString::Format(&v36, "Mission");
        break;
      case 2:
        UFG::qString::Format(&v36, "Case");
        break;
      case 3:
        UFG::qString::Format(&v36, "Event");
        break;
      case 4:
        UFG::qString::Format(&v36, "Favour");
        break;
      case 5:
        UFG::qString::Format(&v36, "Job");
        break;
      case 6:
        UFG::qString::Format(&v36, "Date");
        break;
      case 8:
        UFG::qString::Format(&v36, "DLC");
        break;
      default:
        break;
    }
    v13 = v36.mData;
    UFG::qSPrintf(dest, 128, "s_%s", "MissionType");
    OSuite::ZMetric::SetProperty(v2->m_pMetric, dest, v13);
    ElapsedSeconds = UFG::SimpleTimer::GetElapsedSeconds(&v3->mpSnapshots[0]->mTimes[19].mTimer);
    UFG::qSPrintf(dest, 128, "f_%s", "SandboxTime");
    OSuite::ZMetric::SetProperty(v2->m_pMetric, dest, ElapsedSeconds);
    v15 = UFG::SimpleTimer::GetElapsedSeconds(&v3->mpSnapshots[0]->mTimes[20].mTimer);
    UFG::qSPrintf(dest, 128, "f_%s", "AttemptDuration");
    OSuite::ZMetric::SetProperty(v2->m_pMetric, dest, v15);
    v16 = (UFG::SimpleTimer *)v3->mpSnapshots[0];
    if ( gCurrentTrackedMissionSlice == gCurrentMissionSlice )
    {
      v19 = UFG::SimpleTimer::GetElapsedSeconds(v16 + 21);
      UFG::qSPrintf(dest, 128, "f_%s", "AccumulativeMissionDuration");
      OSuite::ZMetric::SetProperty(v2->m_pMetric, dest, v19);
    }
    else
    {
      gCurrentTrackedMissionSlice = gCurrentMissionSlice;
      v17 = UFG::SimpleTimer::GetElapsedSeconds(v16 + 20);
      UFG::qSPrintf(dest, 128, "f_%s", "AccumulativeMissionDuration");
      OSuite::ZMetric::SetProperty(v2->m_pMetric, dest, v17);
      v18 = UFG::SimpleTimer::GetElapsedSeconds(&v3->mpSnapshots[0]->mTimes[20].mTimer);
      UFG::SimpleTimer::SetElapsedTime(&v3->mpSnapshots[0]->mTimes[21].mTimer, v18);
    }
    v20 = &sGameStatTracker;
    if ( (_S12_6 & 1) == 0 )
    {
      _S12_6 |= 1u;
      UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
      atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
    }
    if ( UFG::GameStatTracker::mspInstance )
      v20 = UFG::GameStatTracker::mspInstance;
    UFG::GameStatTracker::mspInstance = v20;
    v21 = UFG::GameStatAction::MissionScoring::ms_CopStartingScore - v20->mpSnapshots[0]->mInts[155].mValue;
    v22 = 0;
    if ( v21 > 0 )
      v22 = v21;
    TriadScore = UFG::GameStatAction::MissionScoring::GetTriadScore(1);
    UFG::qSPrintf(dest, 128, "i32_%s", "PoliceXP");
    OSuite::ZMetric::SetProperty(v2->m_pMetric, dest, v22);
    UFG::qSPrintf(dest, 128, "i32_%s", "TriadXP");
    OSuite::ZMetric::SetProperty(v2->m_pMetric, dest, TriadScore);
    v24 = v3->mpSnapshots[0]->mInts[158].mValue;
    UFG::qSPrintf(dest, 128, "i32_%s", "MeleeKills");
    OSuite::ZMetric::SetProperty(v2->m_pMetric, dest, v24);
    v25 = v3->mpSnapshots[0]->mInts[159].mValue;
    UFG::qSPrintf(dest, 128, "i32_%s", "GunKills");
    OSuite::ZMetric::SetProperty(v2->m_pMetric, dest, v25);
    v26 = v3->mpSnapshots[0]->mInts[160].mValue;
    UFG::qSPrintf(dest, 128, "i32_%s", "MeleeWeaponKills");
    OSuite::ZMetric::SetProperty(v2->m_pMetric, dest, v26);
    v27 = v3->mpSnapshots[0]->mInts[161].mValue;
    UFG::qSPrintf(dest, 128, "i32_%s", "DLCWeaponKills");
    OSuite::ZMetric::SetProperty(v2->m_pMetric, dest, v27);
    UFG::OSuiteDBLogger::SubmitMetric(v2, 1);
    UFG::qString::~qString(&v36);
    for ( i = v34; v34 != (UFG::NameValueColumnType *)&v33; i = v34 )
    {
      mPrev = i->mPrev;
      mNext = i->mNext;
      mPrev->mNext = mNext;
      mNext->mPrev = mPrev;
      i->mPrev = i;
      i->mNext = i;
      UFG::NameValueColumnType::~NameValueColumnType(i);
      operator delete[](i);
    }
    v31 = v33;
    v32 = v34;
    v33[1] = (__int64)v34;
    v32->mPrev = (UFG::qNode<UFG::NameValueColumnType,UFG::NameValueColumnType> *)v31;
  }
}

// File Line: 2654
// RVA: 0x4BF040
void __fastcall UFG::GameStatAction::GameSliceAction::Start(UFG::GameSlice *gameslice)
{
  int v2; // eax
  char v3; // dl
  UFG::GameStatTracker *v4; // rdi
  unsigned int v5; // eax
  UFG::GameStatTracker *v6; // rbx
  float ElapsedSeconds; // xmm0_4
  int mTrackType; // ecx
  UFG::SimpleTimer *v9; // rbx
  UFG::qWiseSymbol *v10; // rax
  UFG::qWiseSymbol *v11; // rax
  UFG::qString v12; // [rsp+38h] [rbp-40h] BYREF
  UFG::qWiseSymbol result; // [rsp+80h] [rbp+8h] BYREF

  if ( !gameslice->mTrackType )
    return;
  v2 = UFG::qStringCompareInsensitive(gameslice->mName.mText, "M_WTHK", -1);
  v3 = UFG::GameStatAction::gIgnoreMissionKillsInWTHK;
  if ( !v2 )
    v3 = 1;
  UFG::GameStatAction::gIgnoreMissionKillsInWTHK = v3;
  v4 = UFG::GameStatTracker::Instance();
  switch ( gameslice->mTrackType )
  {
    case 1:
      if ( (*((_BYTE *)v4 + 6216) & 1) == 0 )
      {
        ++v4->mpSnapshots[0]->mInts[49].mValue;
        if ( UFG::GameStatAction::PostStat::sIsEnabled )
          UFG::GameStatAction::PostStat::AchieveInt(MissionsAttmpted);
      }
      UFG::SimpleTimer::Stop(&v4->mpSnapshots[0]->mTimes[18].mTimer);
      ElapsedSeconds = UFG::SimpleTimer::GetElapsedSeconds(&v4->mpSnapshots[0]->mTimes[18].mTimer);
      UFG::GameStatTracker::ApplyDelta(v4, TotalTimeBetweenMissions, ElapsedSeconds);
      UFG::GameStatTracker::SetStatHigh(v4, 86, ElapsedSeconds);
      UFG::SimpleTimer::Resume(&v4->mpSnapshots[0]->mTimes[3].mTimer);
      UFG::GameStatAction::mTick_Mission_Start = UFG::qGetTicks();
      break;
    case 2:
      if ( (*((_BYTE *)v4 + 6216) & 1) == 0 )
      {
        ++v4->mpSnapshots[0]->mInts[55].mValue;
        if ( UFG::GameStatAction::PostStat::sIsEnabled )
        {
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
        }
      }
      UFG::GameStatAction::mTick_Case_Start = UFG::qGetTicks();
      break;
    case 3:
      if ( (*((_BYTE *)v4 + 6216) & 1) == 0 )
      {
        ++v4->mpSnapshots[0]->mInts[51].mValue;
        if ( UFG::GameStatAction::PostStat::sIsEnabled )
        {
          v5 = _S12_6;
          if ( (_S12_6 & 1) != 0 )
            goto LABEL_21;
          goto LABEL_20;
        }
      }
      break;
    case 4:
      if ( (*((_BYTE *)v4 + 6216) & 1) == 0 )
      {
        ++v4->mpSnapshots[0]->mInts[53].mValue;
        if ( UFG::GameStatAction::PostStat::sIsEnabled )
        {
          v5 = _S12_6;
          if ( (_S12_6 & 1) != 0 )
            goto LABEL_21;
          goto LABEL_20;
        }
      }
      break;
    default:
      if ( gameslice->mTrackType == 6 && (*((_BYTE *)v4 + 6216) & 1) == 0 )
      {
        ++v4->mpSnapshots[0]->mInts[57].mValue;
        if ( UFG::GameStatAction::PostStat::sIsEnabled )
        {
          v5 = _S12_6;
          if ( (_S12_6 & 1) != 0 )
            goto LABEL_21;
LABEL_20:
          _S12_6 = v5 | 1;
          UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
          atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
LABEL_21:
          if ( !UFG::GameStatTracker::mspInstance )
            UFG::GameStatTracker::mspInstance = &sGameStatTracker;
        }
      }
      break;
  }
  mTrackType = (unsigned __int8)gameslice->mTrackType;
  if ( ((mTrackType - 1) & 0xFFFFFFF8) == 0 && mTrackType != 7 )
  {
    UFG::SimpleTimer::Stop(&v4->mpSnapshots[0]->mTimes[19].mTimer);
    v9 = (UFG::SimpleTimer *)v4->mpSnapshots[0];
    UFG::SimpleTimer::SetElapsedTime(v9 + 20, 0.0);
    UFG::SimpleTimer::Start(v9 + 20);
    UFG::SimpleTimer::Resume(&v4->mpSnapshots[0]->mTimes[21].mTimer);
    UFG::GameStatTracker::SetStat(v4, MissionMeleeKills, 0);
    UFG::GameStatTracker::SetStat(v4, MissionGunKills, 0);
    UFG::GameStatTracker::SetStat(v4, MissionMeleeWeaponKills, 0);
    UFG::GameStatTracker::SetStat(v4, MissionDLCWeaponKills, 0);
    gCurrentMissionSlice = gameslice->mNode.mUID;
    v10 = UFG::qSymbol::qSymbol(&result, 0x62D86D56u);
    if ( (*((_BYTE *)v4 + 6216) & 1) == 0 )
      v4->mpSnapshots[0]->mIDs[43].mValue.mUID = v10->mUID;
    UFG::qString::qString(&v12, &customCaption);
    if ( (*((_BYTE *)v4 + 6216) & 1) == 0 )
      UFG::qString::Set(&v4->mpSnapshots[0]->mStrings[24].mValue, v12.mData, v12.mLength, 0i64, 0);
    UFG::qString::~qString(&v12);
    if ( (*((_BYTE *)v4 + 6216) & 1) == 0 )
    {
      v4->mpSnapshots[0]->mIDs[32].mValue = UFG::gNullQSymbol;
      if ( (*((_BYTE *)v4 + 6216) & 1) == 0 )
      {
        v4->mpSnapshots[0]->mIDs[33].mValue = UFG::gNullQSymbol;
        if ( (*((_BYTE *)v4 + 6216) & 1) == 0 )
        {
          v4->mpSnapshots[0]->mIDs[34].mValue = UFG::gNullQSymbol;
          if ( (*((_BYTE *)v4 + 6216) & 1) == 0 )
          {
            v4->mpSnapshots[0]->mFloats[132].mValue = -10000.0;
            if ( (*((_BYTE *)v4 + 6216) & 1) == 0 )
            {
              v4->mpSnapshots[0]->mFloats[133].mValue = -10000.0;
              if ( (*((_BYTE *)v4 + 6216) & 1) == 0 )
              {
                v4->mpSnapshots[0]->mFloats[134].mValue = -10000.0;
                if ( (*((_BYTE *)v4 + 6216) & 1) == 0 )
                {
                  v4->mpSnapshots[0]->mFloats[135].mValue = -1.0;
                  if ( (*((_BYTE *)v4 + 6216) & 1) == 0 )
                  {
                    v4->mpSnapshots[0]->mFloats[136].mValue = -1.0;
                    if ( (*((_BYTE *)v4 + 6216) & 1) == 0 )
                    {
                      v4->mpSnapshots[0]->mFloats[137].mValue = 0.0;
                      if ( (*((_BYTE *)v4 + 6216) & 1) == 0 )
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
    UFG::GameStatAction::GameSliceAction::SendTelemetryStat(gameslice);
    v11 = UFG::qSymbol::qSymbol(&result, 0xEF305CE5);
    if ( (*((_BYTE *)v4 + 6216) & 1) == 0 )
      v4->mpSnapshots[0]->mIDs[43].mValue.mUID = v11->mUID;
    UFG::qString::qString(&v12, "Not applicable.");
    if ( (*((_BYTE *)v4 + 6216) & 1) == 0 )
      UFG::qString::Set(&v4->mpSnapshots[0]->mStrings[24].mValue, v12.mData, v12.mLength, 0i64, 0);
    UFG::qString::~qString(&v12);
  }
}

// File Line: 2761
// RVA: 0x4C10B0
void __fastcall UFG::GameStatAction::GameSliceAction::Stop(UFG::GameSlice *gameslice, bool success)
{
  __int64 v2; // rbx
  __int64 v3; // rbp
  __int64 v4; // rdi
  __int64 v5; // rsi
  __int128 v6; // xmm6
  int v9; // eax
  bool v10; // r8
  UFG::GameStatTracker *v11; // rdi
  UFG::GameStatTracker *v12; // rax
  UFG::GameSnapshot *v13; // r9
  UFG::PersistentData::MapBool *v14; // rdx
  UFG::PersistentData::MapBool::KeepType mKeepType; // ecx
  int size; // eax
  float v17; // xmm0_4
  int v18; // ecx
  unsigned int v19; // r8d
  $CCFB32CF948EEB04FF452B3FEB4ECF53 *v20; // rax
  __int64 v21; // rdx
  float v22; // xmm1_4
  unsigned __int64 Ticks; // rax
  UFG::GameStatTracker *v24; // rax
  float CopScore; // xmm0_4
  float TriadScore; // xmm0_4
  UFG::PersistentData::MapBool *v27; // rdx
  UFG::PersistentData::MapBool::KeepType v28; // ecx
  unsigned int v29; // r9d
  unsigned int v30; // ecx
  unsigned int v31; // r8d
  $CCFB32CF948EEB04FF452B3FEB4ECF53 *v32; // rax
  __int64 v33; // rdx
  unsigned __int64 v34; // rax
  UFG::GameStatTracker *v35; // rax
  UFG::GameStatTracker *v36; // rax
  UFG::PersistentData::MapBool *v37; // rbx
  UFG::PersistentData::MapBool::KeepType v38; // ecx
  unsigned int v39; // r8d
  unsigned int v40; // ecx
  __int64 v41; // rdx
  $CCFB32CF948EEB04FF452B3FEB4ECF53 *v42; // rax
  UFG::PersistentData::MapBool::KeepType v43; // r8d
  unsigned int v44; // ecx
  __int64 v45; // rdx
  $CCFB32CF948EEB04FF452B3FEB4ECF53 *v46; // rax
  unsigned int v47; // r8d
  UFG::GameStatTracker *v48; // rax
  UFG::PersistentData::MapBool *v49; // rbx
  UFG::PersistentData::MapBool::KeepType v50; // ecx
  unsigned int v51; // r8d
  unsigned int v52; // ecx
  __int64 v53; // rdx
  $CCFB32CF948EEB04FF452B3FEB4ECF53 *v54; // rax
  UFG::GameStatTracker *v55; // rax
  UFG::PersistentData::MapBool *v56; // rdx
  UFG::PersistentData::MapBool::KeepType v57; // ecx
  unsigned int v58; // r9d
  unsigned int v59; // ecx
  unsigned int v60; // r8d
  $CCFB32CF948EEB04FF452B3FEB4ECF53 *v61; // rax
  __int64 v62; // rdx
  UFG::GameStatTracker *v63; // rax
  UFG::GameStat::MapBoolStat v64; // edx
  int mTrackType; // ecx
  UFG::SimpleTimer *v66; // rbx
  UFG::qWiseSymbol *v67; // rax
  float v68; // xmm0_4
  float v69; // xmm0_4
  UFG::ProgressionTracker *v70; // rax
  float updated; // xmm6_4
  UFG::OSuiteLeaderboardManager *v72; // rax
  UFG::OSuiteLeaderboardData *LeaderboardDataUsingLeaderboardName; // rax
  UFG::GameStat::Int32Stat v74; // edx
  int v75; // ecx
  UFG::qString v76; // [rsp+38h] [rbp-40h] BYREF
  __int128 v77; // [rsp+60h] [rbp-18h]
  __int64 v78; // [rsp+70h] [rbp-8h]
  UFG::qWiseSymbol result; // [rsp+80h] [rbp+8h] BYREF
  __int64 v80; // [rsp+88h] [rbp+10h]
  __int64 v81; // [rsp+90h] [rbp+18h]
  __int64 v82; // [rsp+98h] [rbp+20h]

  v78 = v4;
  v80 = v2;
  v81 = v3;
  v82 = v5;
  v77 = v6;
  if ( gameslice->mTrackType )
  {
    v9 = UFG::qStringCompareInsensitive(gameslice->mName.mText, "M_WTHK", -1);
    v10 = UFG::GameStatAction::gIgnoreMissionKillsInWTHK;
    if ( !v9 )
      v10 = 0;
    UFG::GameStatAction::gIgnoreMissionKillsInWTHK = v10;
    v11 = UFG::GameStatTracker::Instance();
    if ( success )
    {
      switch ( gameslice->mTrackType )
      {
        case 1:
          v12 = UFG::GameStatTracker::Instance();
          UFG::GameStatTracker::SetStat(v12, MissionsCompleted, (UFG::qSymbol *)&gameslice->mNode.mUID, 1);
          UFG::SimpleTimer::Resume(&v11->mpSnapshots[0]->mTimes[18].mTimer);
          UFG::SimpleTimer::Stop(&v11->mpSnapshots[0]->mTimes[3].mTimer);
          v13 = v11->mpSnapshots[0];
          v14 = v13->mpMapBools[66];
          mKeepType = v14->mKeepType;
          if ( v14->mKeepType )
          {
            if ( (unsigned int)(mKeepType - 1) > 1 )
              size = 0;
            else
              size = v14->mNames.size;
          }
          else
          {
            size = v14->mValues.size;
          }
          v17 = (float)size;
          if ( mKeepType == KEEP_FALSE )
          {
            v18 = 0;
          }
          else if ( mKeepType == KEEP_TRUE )
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
                if ( v20->mBoolValue )
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
          if ( (*((_BYTE *)v11 + 6216) & 1) == 0 )
            v13->mFloats[118].mValue = (float)((float)v18 * 100.0) / v22;
          Ticks = UFG::qGetTicks();
          UFG::qGetTickTime(UFG::GameStatAction::mTick_Mission_Start, Ticks);
          break;
        case 2:
          v24 = UFG::GameStatTracker::Instance();
          UFG::GameStatTracker::SetStat(v24, CasesCompleted, (UFG::qSymbol *)&gameslice->mNode.mUID, 1);
          CopScore = (float)(int)UFG::GameStatAction::MissionScoring::GetCopScore(1);
          if ( (*((_BYTE *)v11 + 6216) & 1) == 0 )
            v11->mpSnapshots[0]->mFloats[135].mValue = CopScore;
          TriadScore = (float)(int)UFG::GameStatAction::MissionScoring::GetTriadScore(1);
          if ( (*((_BYTE *)v11 + 6216) & 1) == 0 )
            v11->mpSnapshots[0]->mFloats[136].mValue = TriadScore;
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
          if ( v28 == KEEP_FALSE )
          {
            v30 = 0;
          }
          else if ( v28 == KEEP_TRUE )
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
                if ( v32->mBoolValue )
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
          UFG::GameStatTracker::SetStat(v36, EventsCompleted, (UFG::qSymbol *)&gameslice->mNode.mUID, 1);
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
            if ( v38 == KEEP_FALSE )
            {
              v40 = 0;
            }
            else if ( v38 == KEEP_TRUE )
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
                  if ( v42->mBoolValue )
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
            if ( v37->mKeepType == KEEP_FALSE )
            {
              v44 = 0;
            }
            else if ( v43 == KEEP_TRUE )
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
                  if ( v46->mBoolValue )
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
          UFG::GameStatTracker::SetStat(v48, FavoursCompleted, (UFG::qSymbol *)&gameslice->mNode.mUID, 1);
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
            if ( v50 == KEEP_FALSE )
            {
              v52 = 0;
            }
            else if ( v50 == KEEP_TRUE )
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
                  if ( v54->mBoolValue )
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
          v64 = JobsCompleted;
          goto LABEL_115;
        case 6:
          v35 = UFG::GameStatTracker::Instance();
          UFG::GameStatTracker::SetStat(v35, DatesCompleted, (UFG::qSymbol *)&gameslice->mNode.mUID, 1);
          UFG::GameStatTracker::Instance();
          break;
        case 7:
          v55 = UFG::GameStatTracker::Instance();
          UFG::GameStatTracker::SetStat(v55, StreetRacesCompletedWon, (UFG::qSymbol *)&gameslice->mNode.mUID, 1);
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
          if ( v57 == KEEP_FALSE )
          {
            v59 = 0;
          }
          else if ( v57 == KEEP_TRUE )
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
                if ( v61->mBoolValue )
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
          v64 = DLCCompleted;
LABEL_115:
          UFG::GameStatTracker::SetStat(v63, v64, (UFG::qSymbol *)&gameslice->mNode.mUID, 1);
          break;
        default:
          break;
      }
      mTrackType = (unsigned __int8)gameslice->mTrackType;
      if ( ((mTrackType - 1) & 0xFFFFFFF8) == 0 && mTrackType != 7 || (_BYTE)mTrackType == 7 )
      {
        if ( ((mTrackType - 1) & 0xFFFFFFF8) == 0 && mTrackType != 7 )
        {
          v66 = (UFG::SimpleTimer *)v11->mpSnapshots[0];
          UFG::SimpleTimer::SetElapsedTime(v66 + 19, 0.0);
          UFG::SimpleTimer::Start(v66 + 19);
          UFG::SimpleTimer::Stop(&v11->mpSnapshots[0]->mTimes[20].mTimer);
          UFG::SimpleTimer::Stop(&v11->mpSnapshots[0]->mTimes[21].mTimer);
          v67 = UFG::qSymbol::qSymbol(&result, 0xFC1C7189);
          if ( (*((_BYTE *)v11 + 6216) & 1) == 0 )
            v11->mpSnapshots[0]->mIDs[43].mValue.mUID = v67->mUID;
          UFG::qString::qString(&v76, &customCaption);
          if ( (*((_BYTE *)v11 + 6216) & 1) == 0 )
            UFG::qString::Set(&v11->mpSnapshots[0]->mStrings[24].mValue, v76.mData, v76.mLength, 0i64, 0);
          UFG::qString::~qString(&v76);
          v68 = (float)(int)UFG::GameStatAction::MissionScoring::GetCopScore(1);
          if ( (*((_BYTE *)v11 + 6216) & 1) == 0 )
            v11->mpSnapshots[0]->mFloats[135].mValue = v68;
          v69 = (float)(int)UFG::GameStatAction::MissionScoring::GetTriadScore(1);
          if ( (*((_BYTE *)v11 + 6216) & 1) == 0 )
            v11->mpSnapshots[0]->mFloats[136].mValue = v69;
          UFG::GameStatAction::GameSliceAction::SendTelemetryStat(gameslice);
        }
        v70 = UFG::ProgressionTracker::Instance();
        updated = UFG::ProgressionTracker::UpdateCompletionPercentage(v70);
        v72 = UFG::OSuiteLeaderboardManager::Instance();
        LeaderboardDataUsingLeaderboardName = UFG::OSuiteLeaderboardManager::GetLeaderboardDataUsingLeaderboardName(
                                                v72,
                                                "StatAwardsCompletionist");
        UFG::DataSynchronizer::SetMaxToGlobalSnapshot(LeaderboardDataUsingLeaderboardName, updated);
        if ( UFG::ProgressionTracker::Instance()->mActiveFlowId.mUID == gDefaultFlowId.mUID )
        {
          if ( updated >= 10.0 )
            UFG::AchievementTrophyManager::UnlockAchievementTrophy(47);
          if ( updated >= 25.0 )
            UFG::AchievementTrophyManager::UnlockAchievementTrophy(48);
          if ( updated >= 50.0 )
            UFG::AchievementTrophyManager::UnlockAchievementTrophy(49);
          if ( updated >= 100.0 )
            UFG::AchievementTrophyManager::UnlockAchievementTrophy(50);
        }
      }
    }
    else
    {
      switch ( gameslice->mTrackType )
      {
        case 1:
          v74 = MissionsFailed;
          goto LABEL_146;
        case 2:
          v74 = CasesFailed;
          goto LABEL_146;
        case 3:
          v74 = EventsFailed;
          goto LABEL_146;
        case 4:
          v74 = FavoursFailed;
          goto LABEL_146;
        case 6:
          v74 = DatesFailed;
          goto LABEL_146;
        case 7:
          v74 = StreetRacesLost;
LABEL_146:
          UFG::GameStatTracker::ApplyDelta(v11, v74, 1);
          break;
        default:
          break;
      }
      v75 = (unsigned __int8)gameslice->mTrackType;
      if ( ((v75 - 1) & 0xFFFFFFF8) == 0 && v75 != 7 )
        UFG::GameStatAction::GameSliceAction::SendTelemetryStat(gameslice);
    }
  }
}= 7 )
        UFG::GameStatAction::GameSliceAction::SendTelemetryStat(gameslice);
    }
  }
}

// File Line: 2958
// RVA: 0x4B2C20
void __fastcall UFG::GameStatAction::GameSliceAction::PublishProgression(UFG::GameSlice *pSlice)
{
  bool v2; // di
  UFG::GameStatTracker *v3; // rax
  UFG::GameStat::MapBoolStat v4; // edx

  v2 = pSlice->mState == STATE_COMPLETED || pSlice->mCompletionCount > 0;
  switch ( pSlice->mTrackType )
  {
    case 1:
      v3 = UFG::GameStatTracker::Instance();
      v4 = MissionsCompleted;
      goto LABEL_14;
    case 2:
      v3 = UFG::GameStatTracker::Instance();
      v4 = CasesCompleted;
      goto LABEL_14;
    case 3:
      v3 = UFG::GameStatTracker::Instance();
      v4 = EventsCompleted;
      goto LABEL_14;
    case 4:
      v3 = UFG::GameStatTracker::Instance();
      v4 = FavoursCompleted;
      goto LABEL_14;
    case 5:
      v3 = UFG::GameStatTracker::Instance();
      v4 = JobsCompleted;
      goto LABEL_14;
    case 6:
      v3 = UFG::GameStatTracker::Instance();
      v4 = DatesCompleted;
      goto LABEL_14;
    case 7:
      v3 = UFG::GameStatTracker::Instance();
      v4 = StreetRacesCompletedWon;
      goto LABEL_14;
    case 8:
      v3 = UFG::GameStatTracker::Instance();
      v4 = DLCCompleted;
LABEL_14:
      UFG::GameStatTracker::SetStat(v3, v4, (UFG::qSymbol *)&pSlice->mNode.mUID, v2);
      break;
    default:
      return;
  }
}

// File Line: 3037
// RVA: 0x4ABDC0
char __fastcall UFG::GameStatAction::GameSliceAction::IsCompleted(unsigned int *symGameSliceName)
{
  UFG::qBaseTreeRB *v2; // rax
  UFG::qSymbol *v4; // rbx
  UFG::qBaseTreeRB *v5; // rax
  UFG::qSymbol result; // [rsp+48h] [rbp+10h] BYREF

  if ( (_S19_1 & 1) == 0 )
  {
    _S19_1 |= 1u;
    UFG::ProgressionTracker::ProgressionTracker(&sProgressionTracker);
    atexit(UFG::ProgressionTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sProgressionTracker__);
  }
  UFG::ProgressionTracker::mspInstance = &sProgressionTracker;
  if ( *symGameSliceName && (v2 = UFG::qBaseTreeRB::Get(&stru_14240A100, *symGameSliceName)) != 0i64
    || (*symGameSliceName ? (v2 = UFG::qBaseTreeRB::Get(&stru_14240A148, *symGameSliceName)) : (v2 = 0i64), v2) )
  {
    if ( LODWORD(v2[3].mNULL.mChild[1]) == 8 || SWORD2(v2[5].mRoot.mParent) > 0 )
      return 1;
  }
  if ( *symGameSliceName != gMissionSymbol_M_VE.mUID )
    return 0;
  if ( (_S19_1 & 1) == 0 )
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
    return 1;
  }
  else
  {
    return 0;
  }
}

// File Line: 3065
// RVA: 0x4AAB40
void UFG::GameStatAction::Snapshot::Initialize(void)
{
  hkaMatrix<float> *Instance; // rax
  int v1; // r14d
  int v2; // esi
  UFG::UIAmbientMapBlipManager *v3; // rax
  UFG::UIAmbientMapBlipData *BlipData; // rbx
  unsigned int ID; // eax
  UFG::PersistentData::MapBool *v6; // r9
  __int64 v7; // rdx
  unsigned int v8; // r8d
  UFG::qSymbol *v9; // r9
  bool mBoolValue; // al
  __int64 v11; // rdx
  unsigned int size; // r8d
  UFG::qSymbol *p; // r9
  unsigned int v14; // r8d
  __int64 v15; // rdx
  UFG::PersistentData::KeyValue *v16; // rcx
  UFG::GameStatTracker *v17; // rax
  unsigned int v18; // edx
  UFG::GameStatTracker *v19; // r8
  UFG::PersistentData::MapBool *v20; // rax
  unsigned int v21; // ebx
  __int64 v22; // rcx
  $CCFB32CF948EEB04FF452B3FEB4ECF53 *v23; // rax
  UFG::GameStatTracker *v24; // rax
  UFG::PersistentData::MapBool *v25; // rcx
  unsigned int v26; // eax
  UFG::UIAmbientMapBlipData::eZoneInfo mZoneInfo; // ecx
  __int32 v28; // ecx
  __int32 v29; // ecx
  __int64 v30; // rdi
  UFG::PersistentData::MapBool *v31; // r9
  __int64 v32; // rdx
  unsigned int v33; // r8d
  UFG::qSymbol *v34; // r9
  bool v35; // al
  __int64 v36; // rdx
  unsigned int v37; // r8d
  UFG::qSymbol *v38; // r9
  unsigned int v39; // r8d
  __int64 v40; // rdx
  UFG::PersistentData::KeyValue *v41; // rcx
  UFG::GameStatTracker *v42; // rax
  UFG::UIAmbientMapBlipData::eZoneInfo v43; // ecx
  __int32 v44; // ecx
  __int32 v45; // ecx
  UFG::PersistentData::MapBool *v46; // r9
  __int64 v47; // rdx
  unsigned int v48; // r8d
  UFG::qSymbol *v49; // r9
  bool v50; // al
  __int64 v51; // rdx
  unsigned int v52; // r8d
  UFG::qSymbol *v53; // r9
  unsigned int v54; // r8d
  __int64 v55; // rdx
  UFG::PersistentData::KeyValue *v56; // rcx
  UFG::GameStatTracker *v57; // rax
  UFG::PersistentData::MapBool *v58; // r9
  __int64 v59; // rdx
  unsigned int v60; // r8d
  UFG::qSymbol *v61; // r9
  bool v62; // al
  __int64 v63; // rdx
  unsigned int v64; // r8d
  UFG::qSymbol *v65; // r9
  unsigned int v66; // r8d
  __int64 v67; // rdx
  UFG::PersistentData::KeyValue *v68; // rcx
  UFG::GameStatTracker *v69; // rax
  unsigned int v70; // ecx
  UFG::GameStatTracker *v71; // rdx
  UFG::PersistentData::MapBool *v72; // r9
  __int64 v73; // rdx
  unsigned int v74; // r8d
  UFG::qSymbol *v75; // r9
  bool v76; // al
  __int64 v77; // rdx
  unsigned int v78; // r8d
  UFG::qSymbol *v79; // r9
  unsigned int v80; // r8d
  __int64 v81; // rdx
  UFG::PersistentData::KeyValue *v82; // rcx
  UFG::GameStatTracker *v83; // rax
  UFG::GameStatTracker *v84; // rax
  UFG::GameStatTracker *v85; // rax
  UFG::GameStat::MapBoolStat v86; // edx
  UFG::GameStatTracker *v87; // rax
  UFG::GameStatTracker *v88; // rax
  UFG::GameStatTracker *v89; // rax
  UFG::qWiseSymbol result; // [rsp+70h] [rbp+40h] BYREF
  UFG::qSymbol keyname; // [rsp+78h] [rbp+48h] BYREF
  UFG::qSymbol *p_keyname; // [rsp+80h] [rbp+50h]

  Instance = (hkaMatrix<float> *)UFG::UIAmbientMapBlipManager::getInstance();
  v1 = hkaMatrix<float>::Height(Instance);
  v2 = 0;
  if ( v1 > 0 )
  {
    while ( 1 )
    {
      v3 = UFG::UIAmbientMapBlipManager::getInstance();
      BlipData = UFG::UIAmbientMapBlipManager::GetBlipData(v3, v2);
      ID = UFG::UIAmbientMapBlipData::GetID(BlipData);
      UFG::qSymbol::qSymbol(&result, ID);
      switch ( BlipData->mCollectibleType )
      {
        case COLLECTIBLE_SPY_CAM:
          v6 = UFG::GameStatTracker::Instance()->mpSnapshots[0]->mpMapBools[31];
          if ( v6->mKeepType )
          {
            if ( v6->mKeepType == KEEP_TRUE )
            {
              v11 = 0i64;
              size = v6->mNames.size;
              if ( size )
              {
                p = v6->mNames.p;
                while ( result.mUID != p[v11].mUID )
                {
                  v11 = (unsigned int)(v11 + 1);
                  if ( (unsigned int)v11 >= size )
                    goto LABEL_16;
                }
              }
              else
              {
LABEL_16:
                LODWORD(v11) = -1;
              }
              mBoolValue = (_DWORD)v11 != -1;
            }
            else
            {
              if ( v6->mKeepType != KEEP_FALSE )
                goto LABEL_26;
              v7 = 0i64;
              v8 = v6->mNames.size;
              if ( v8 )
              {
                v9 = v6->mNames.p;
                while ( result.mUID != v9[v7].mUID )
                {
                  v7 = (unsigned int)(v7 + 1);
                  if ( (unsigned int)v7 >= v8 )
                    goto LABEL_10;
                }
              }
              else
              {
LABEL_10:
                LODWORD(v7) = -1;
              }
              mBoolValue = (_DWORD)v7 == -1;
            }
          }
          else
          {
            v14 = v6->mValues.size;
            v15 = 0i64;
            if ( !v14 )
              goto LABEL_26;
            v16 = v6->mValues.p;
            while ( v16->mKey.mUID != result.mUID )
            {
              v15 = (unsigned int)(v15 + 1);
              ++v16;
              if ( (unsigned int)v15 >= v14 )
                goto LABEL_26;
            }
            if ( (_DWORD)v15 == -1 )
            {
LABEL_26:
              v17 = UFG::GameStatTracker::Instance();
              if ( (*((_BYTE *)v17 + 6216) & 1) == 0 )
              {
                UFG::PersistentData::MapBool::SetStatus(v17->mpSnapshots[0]->mpMapBools[31], (UFG::qSymbol *)&result, 0);
                if ( UFG::GameStatAction::PostStat::sIsEnabled )
                {
                  v18 = _S12_6;
                  if ( (_S12_6 & 1) == 0 )
                  {
                    _S12_6 |= 1u;
                    UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
                    atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
                    v18 = _S12_6;
                  }
                  v19 = &sGameStatTracker;
                  if ( UFG::GameStatTracker::mspInstance )
                    v19 = UFG::GameStatTracker::mspInstance;
                  UFG::GameStatTracker::mspInstance = v19;
                  v20 = v19->mpSnapshots[0]->mpMapBools[31];
                  if ( v20->mKeepType == KEEP_FALSE )
                  {
                    v21 = 0;
                  }
                  else if ( v20->mKeepType == KEEP_TRUE )
                  {
                    v21 = v20->mNames.size;
                  }
                  else
                  {
                    v21 = 0;
                    v22 = v20->mValues.size;
                    if ( (_DWORD)v22 )
                    {
                      v23 = &v20->mValues.p->4;
                      do
                      {
                        if ( v23->mBoolValue )
                          ++v21;
                        v23 += 2;
                        --v22;
                      }
                      while ( v22 );
                    }
                  }
                  if ( (v18 & 1) == 0 )
                  {
                    _S12_6 = v18 | 1;
                    UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
                    atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
                    v19 = UFG::GameStatTracker::mspInstance;
                  }
                  v24 = &sGameStatTracker;
                  if ( v19 )
                    v24 = v19;
                  UFG::GameStatTracker::mspInstance = v24;
                  v25 = v24->mpSnapshots[0]->mpMapBools[31];
                  if ( v25->mKeepType )
                  {
                    if ( (unsigned int)(v25->mKeepType - 1) > 1 )
                      v26 = 0;
                    else
                      v26 = v25->mNames.size;
                  }
                  else
                  {
                    v26 = v25->mValues.size;
                  }
                  if ( v21 == v26 )
                    UFG::AchievementTrophyManager::UnlockAchievementTrophy(36);
                  UFG::GameStatAction::PostStat::HandleExplorerStatAward();
                }
              }
              goto LABEL_194;
            }
            mBoolValue = v6->mValues.p[v15].mBoolValue;
          }
          if ( !mBoolValue )
            goto LABEL_26;
          goto LABEL_194;
        case COLLECTIBLE_HEALTH_SHRINE:
          mZoneInfo = BlipData->mZoneInfo;
          if ( mZoneInfo )
          {
            v28 = mZoneInfo - 1;
            if ( v28 )
            {
              v29 = v28 - 1;
              if ( v29 )
              {
                if ( v29 != 1 )
                  goto LABEL_194;
                v30 = 26i64;
              }
              else
              {
                v30 = 25i64;
              }
            }
            else
            {
              v30 = 24i64;
            }
          }
          else
          {
            v30 = 23i64;
          }
          v31 = UFG::GameStatTracker::Instance()->mpSnapshots[0]->mpMapBools[v30];
          if ( v31->mKeepType )
          {
            if ( v31->mKeepType == KEEP_TRUE )
            {
              v36 = 0i64;
              v37 = v31->mNames.size;
              if ( v37 )
              {
                v38 = v31->mNames.p;
                while ( result.mUID != v38[v36].mUID )
                {
                  v36 = (unsigned int)(v36 + 1);
                  if ( (unsigned int)v36 >= v37 )
                    goto LABEL_74;
                }
              }
              else
              {
LABEL_74:
                LODWORD(v36) = -1;
              }
              v35 = (_DWORD)v36 != -1;
            }
            else
            {
              if ( v31->mKeepType != KEEP_FALSE )
                goto LABEL_84;
              v32 = 0i64;
              v33 = v31->mNames.size;
              if ( v33 )
              {
                v34 = v31->mNames.p;
                while ( result.mUID != v34[v32].mUID )
                {
                  v32 = (unsigned int)(v32 + 1);
                  if ( (unsigned int)v32 >= v33 )
                    goto LABEL_68;
                }
              }
              else
              {
LABEL_68:
                LODWORD(v32) = -1;
              }
              v35 = (_DWORD)v32 == -1;
            }
          }
          else
          {
            v39 = v31->mValues.size;
            v40 = 0i64;
            if ( !v39 )
              goto LABEL_84;
            v41 = v31->mValues.p;
            while ( v41->mKey.mUID != result.mUID )
            {
              v40 = (unsigned int)(v40 + 1);
              ++v41;
              if ( (unsigned int)v40 >= v39 )
                goto LABEL_84;
            }
            if ( (_DWORD)v40 == -1 )
            {
LABEL_84:
              v42 = UFG::GameStatTracker::Instance();
              if ( (*((_BYTE *)v42 + 6216) & 1) == 0 )
              {
                UFG::PersistentData::MapBool::SetStatus(
                  v42->mpSnapshots[0]->mpMapBools[v30],
                  (UFG::qSymbol *)&result,
                  0);
                if ( UFG::GameStatAction::PostStat::sIsEnabled )
                  goto LABEL_86;
              }
              goto LABEL_194;
            }
            v35 = v31->mValues.p[v40].mBoolValue;
          }
          if ( !v35 )
            goto LABEL_84;
LABEL_194:
          if ( ++v2 >= v1 )
            goto LABEL_195;
          break;
        case COLLECTIBLE_LOCKBOX:
          v43 = BlipData->mZoneInfo;
          if ( v43 )
          {
            v44 = v43 - 1;
            if ( v44 )
            {
              v45 = v44 - 1;
              if ( v45 )
              {
                if ( v45 != 1 )
                  goto LABEL_194;
                v30 = 30i64;
              }
              else
              {
                v30 = 29i64;
              }
            }
            else
            {
              v30 = 28i64;
            }
          }
          else
          {
            v30 = 27i64;
          }
          v46 = UFG::GameStatTracker::Instance()->mpSnapshots[0]->mpMapBools[v30];
          if ( v46->mKeepType )
          {
            if ( v46->mKeepType == KEEP_TRUE )
            {
              v51 = 0i64;
              v52 = v46->mNames.size;
              if ( v52 )
              {
                v53 = v46->mNames.p;
                while ( result.mUID != v53[v51].mUID )
                {
                  v51 = (unsigned int)(v51 + 1);
                  if ( (unsigned int)v51 >= v52 )
                    goto LABEL_108;
                }
              }
              else
              {
LABEL_108:
                LODWORD(v51) = -1;
              }
              v50 = (_DWORD)v51 != -1;
            }
            else
            {
              if ( v46->mKeepType != KEEP_FALSE )
                goto LABEL_118;
              v47 = 0i64;
              v48 = v46->mNames.size;
              if ( v48 )
              {
                v49 = v46->mNames.p;
                while ( result.mUID != v49[v47].mUID )
                {
                  v47 = (unsigned int)(v47 + 1);
                  if ( (unsigned int)v47 >= v48 )
                    goto LABEL_102;
                }
              }
              else
              {
LABEL_102:
                LODWORD(v47) = -1;
              }
              v50 = (_DWORD)v47 == -1;
            }
          }
          else
          {
            v54 = v46->mValues.size;
            v55 = 0i64;
            if ( !v54 )
              goto LABEL_118;
            v56 = v46->mValues.p;
            while ( v56->mKey.mUID != result.mUID )
            {
              v55 = (unsigned int)(v55 + 1);
              ++v56;
              if ( (unsigned int)v55 >= v54 )
                goto LABEL_118;
            }
            if ( (_DWORD)v55 == -1 )
            {
LABEL_118:
              v57 = UFG::GameStatTracker::Instance();
              if ( (*((_BYTE *)v57 + 6216) & 1) == 0 )
              {
                UFG::PersistentData::MapBool::SetStatus(
                  v57->mpSnapshots[0]->mpMapBools[v30],
                  (UFG::qSymbol *)&result,
                  0);
                if ( UFG::GameStatAction::PostStat::sIsEnabled )
                {
LABEL_86:
                  p_keyname = &keyname;
                  keyname.mUID = result.mUID;
                  UFG::GameStatAction::PostStat::AchieveMapBool((UFG::GameStat::MapBoolStat)v30, (UFG::qSymbol)&keyname);
                }
              }
              goto LABEL_194;
            }
            v50 = v46->mValues.p[v55].mBoolValue;
          }
          if ( !v50 )
            goto LABEL_118;
          goto LABEL_194;
        case COLLECTIBLE_SAFE_HOUSE:
          v58 = UFG::GameStatTracker::Instance()->mpSnapshots[0]->mpMapBools[12];
          if ( v58->mKeepType )
          {
            if ( v58->mKeepType == KEEP_TRUE )
            {
              v63 = 0i64;
              v64 = v58->mNames.size;
              if ( v64 )
              {
                v65 = v58->mNames.p;
                while ( result.mUID != v65[v63].mUID )
                {
                  v63 = (unsigned int)(v63 + 1);
                  if ( (unsigned int)v63 >= v64 )
                    goto LABEL_134;
                }
              }
              else
              {
LABEL_134:
                LODWORD(v63) = -1;
              }
              v62 = (_DWORD)v63 != -1;
            }
            else
            {
              if ( v58->mKeepType != KEEP_FALSE )
                goto LABEL_144;
              v59 = 0i64;
              v60 = v58->mNames.size;
              if ( v60 )
              {
                v61 = v58->mNames.p;
                while ( result.mUID != v61[v59].mUID )
                {
                  v59 = (unsigned int)(v59 + 1);
                  if ( (unsigned int)v59 >= v60 )
                    goto LABEL_128;
                }
              }
              else
              {
LABEL_128:
                LODWORD(v59) = -1;
              }
              v62 = (_DWORD)v59 == -1;
            }
          }
          else
          {
            v66 = v58->mValues.size;
            v67 = 0i64;
            if ( !v66 )
              goto LABEL_144;
            v68 = v58->mValues.p;
            while ( v68->mKey.mUID != result.mUID )
            {
              v67 = (unsigned int)(v67 + 1);
              ++v68;
              if ( (unsigned int)v67 >= v66 )
                goto LABEL_144;
            }
            if ( (_DWORD)v67 == -1 )
            {
LABEL_144:
              v69 = UFG::GameStatTracker::Instance();
              if ( (*((_BYTE *)v69 + 6216) & 1) == 0 )
              {
                UFG::PersistentData::MapBool::SetStatus(v69->mpSnapshots[0]->mpMapBools[12], (UFG::qSymbol *)&result, 0);
                if ( UFG::GameStatAction::PostStat::sIsEnabled )
                {
                  v70 = _S12_6;
                  if ( (_S12_6 & 1) == 0 )
                  {
                    _S12_6 |= 1u;
                    UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
                    atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
                    v70 = _S12_6;
                  }
                  v71 = &sGameStatTracker;
                  if ( UFG::GameStatTracker::mspInstance )
                    v71 = UFG::GameStatTracker::mspInstance;
                  UFG::GameStatTracker::mspInstance = v71;
                  if ( (v70 & 1) != 0 )
                    goto LABEL_152;
                  goto LABEL_151;
                }
              }
              goto LABEL_194;
            }
            v62 = v58->mValues.p[v67].mBoolValue;
          }
          if ( !v62 )
            goto LABEL_144;
          goto LABEL_194;
        case COLLECTIBLE_HIDING_SPOT:
          v72 = UFG::GameStatTracker::Instance()->mpSnapshots[0]->mpMapBools[5];
          if ( v72->mKeepType )
          {
            if ( v72->mKeepType == KEEP_TRUE )
            {
              v77 = 0i64;
              v78 = v72->mNames.size;
              if ( v78 )
              {
                v79 = v72->mNames.p;
                while ( result.mUID != v79[v77].mUID )
                {
                  v77 = (unsigned int)(v77 + 1);
                  if ( (unsigned int)v77 >= v78 )
                    goto LABEL_167;
                }
              }
              else
              {
LABEL_167:
                LODWORD(v77) = -1;
              }
              v76 = (_DWORD)v77 != -1;
            }
            else
            {
              if ( v72->mKeepType != KEEP_FALSE )
                goto LABEL_177;
              v73 = 0i64;
              v74 = v72->mNames.size;
              if ( v74 )
              {
                v75 = v72->mNames.p;
                while ( result.mUID != v75[v73].mUID )
                {
                  v73 = (unsigned int)(v73 + 1);
                  if ( (unsigned int)v73 >= v74 )
                    goto LABEL_161;
                }
              }
              else
              {
LABEL_161:
                LODWORD(v73) = -1;
              }
              v76 = (_DWORD)v73 == -1;
            }
          }
          else
          {
            v80 = v72->mValues.size;
            v81 = 0i64;
            if ( !v80 )
              goto LABEL_177;
            v82 = v72->mValues.p;
            while ( v82->mKey.mUID != result.mUID )
            {
              v81 = (unsigned int)(v81 + 1);
              ++v82;
              if ( (unsigned int)v81 >= v80 )
                goto LABEL_177;
            }
            if ( (_DWORD)v81 == -1 )
            {
LABEL_177:
              v83 = UFG::GameStatTracker::Instance();
              if ( (*((_BYTE *)v83 + 6216) & 1) == 0 )
              {
                UFG::PersistentData::MapBool::SetStatus(v83->mpSnapshots[0]->mpMapBools[5], (UFG::qSymbol *)&result, 0);
                if ( UFG::GameStatAction::PostStat::sIsEnabled )
                {
                  v70 = _S12_6;
                  if ( (_S12_6 & 1) == 0 )
                  {
                    _S12_6 |= 1u;
                    UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
                    atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
                    v70 = _S12_6;
                  }
                  v71 = &sGameStatTracker;
                  if ( UFG::GameStatTracker::mspInstance )
                    v71 = UFG::GameStatTracker::mspInstance;
                  UFG::GameStatTracker::mspInstance = v71;
                  if ( (v70 & 1) == 0 )
                  {
LABEL_151:
                    _S12_6 = v70 | 1;
                    UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
                    atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
                    v71 = UFG::GameStatTracker::mspInstance;
                  }
LABEL_152:
                  if ( !v71 )
                    UFG::GameStatTracker::mspInstance = &sGameStatTracker;
                }
              }
              goto LABEL_194;
            }
            v76 = v72->mValues.p[v81].mBoolValue;
          }
          if ( !v76 )
            goto LABEL_177;
          goto LABEL_194;
        case COLLECTIBLE_BUS_STOP:
          v84 = UFG::GameStatTracker::Instance();
          if ( !UFG::PersistentData::MapBool::GetStatus(v84->mpSnapshots[0]->mpMapBools[3], (UFG::qSymbol *)&result) )
          {
            v85 = UFG::GameStatTracker::Instance();
            v86 = Collectible_BusStop;
            goto LABEL_193;
          }
          goto LABEL_194;
        case COLLECTIBLE_GHOST_ORB:
          v87 = UFG::GameStatTracker::Instance();
          if ( !UFG::PersistentData::MapBool::GetStatus(v87->mpSnapshots[0]->mpMapBools[34], (UFG::qSymbol *)&result) )
          {
            v85 = UFG::GameStatTracker::Instance();
            v86 = Collectible_DLC_01;
            goto LABEL_193;
          }
          goto LABEL_194;
        case COLLECTIBLE_BOMB_BAG:
          v89 = UFG::GameStatTracker::Instance();
          if ( !UFG::PersistentData::MapBool::GetStatus(v89->mpSnapshots[0]->mpMapBools[36], (UFG::qSymbol *)&result) )
          {
            v85 = UFG::GameStatTracker::Instance();
            v86 = Collectible_DLC_03;
            goto LABEL_193;
          }
          goto LABEL_194;
        case COLLECTIBLE_ZODIAC:
          v88 = UFG::GameStatTracker::Instance();
          if ( !UFG::PersistentData::MapBool::GetStatus(v88->mpSnapshots[0]->mpMapBools[35], (UFG::qSymbol *)&result) )
          {
            v85 = UFG::GameStatTracker::Instance();
            v86 = Collectible_DLC_02;
LABEL_193:
            UFG::GameStatTracker::SetStat(v85, v86, (UFG::qSymbol *)&result, 0);
          }
          goto LABEL_194;
        default:
          goto LABEL_194;
      }
    }
  }
LABEL_195:
  UFG::GameStatAction::PostStat::sIsEnabled = 1;
}

// File Line: 3205
// RVA: 0x491D60
void __fastcall UFG::GameStatAction::PostStat::Achieve(
        UFG::GameSnapshot::PersistentDataType persistentdatatype,
        UFG::GameStat::Int32Stat stat_enum,
        unsigned int *mapid)
{
  UFG::qSymbol mapida; // [rsp+20h] [rbp-28h] BYREF
  __int64 v4; // [rsp+30h] [rbp-18h]
  UFG::qSymbol *p_keyname; // [rsp+38h] [rbp-10h]
  UFG::qSymbol keyname; // [rsp+68h] [rbp+20h] BYREF

  v4 = -2i64;
  if ( UFG::GameStatAction::PostStat::sIsEnabled )
  {
    switch ( persistentdatatype )
    {
      case PDT_INT:
        UFG::GameStatAction::PostStat::AchieveInt(stat_enum);
        break;
      case PDT_MAPBOOL:
        p_keyname = &keyname;
        keyname.mUID = *mapid;
        UFG::GameStatAction::PostStat::AchieveMapBool((UFG::GameStat::MapBoolStat)stat_enum, (UFG::qSymbol)&keyname);
        break;
      case PDT_MAPINT:
        p_keyname = &mapida;
        mapida.mUID = *mapid;
        UFG::GameStatAction::PostStat::AchieveMapInt((UFG::GameStat::MapInt32Stat)stat_enum, (UFG::qSymbol)&mapida);
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
  UFG::GameStatTracker *v2; // rdi
  int v3; // ebx
  int v4; // ebx
  UFG::GameSnapshot *v5; // rax
  int mValue; // r8d
  int v7; // ecx
  int FaceLevelFromExperience; // ebx

  v2 = &sGameStatTracker;
  if ( (_S12_6 & 1) == 0 )
  {
    _S12_6 |= 1u;
    UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
    atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
  }
  if ( UFG::GameStatTracker::mspInstance )
    v2 = UFG::GameStatTracker::mspInstance;
  UFG::GameStatTracker::mspInstance = v2;
  v3 = e - 29;
  if ( v3 )
  {
    v4 = v3 - 18;
    if ( v4 )
    {
      if ( v4 == 15 )
      {
        v5 = v2->mpSnapshots[0];
        mValue = v5->mInts[62].mValue;
        if ( v5->mInts[63].mValue < mValue )
          UFG::GameStatTracker::SetStat(v2, MostCashHeld, mValue);
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
  FaceLevelFromExperience = UFG::GameStatTracker::GetFaceLevelFromExperience(v2, v2->mpSnapshots[0]->mInts[29].mValue);
  if ( UFG::ProgressionTracker::Instance()->mActiveFlowId.mUID == gDefaultFlowId.mUID )
  {
    if ( FaceLevelFromExperience >= 2 )
      UFG::AchievementTrophyManager::UnlockAchievementTrophy(5);
    if ( FaceLevelFromExperience >= 5 )
      UFG::AchievementTrophyManager::UnlockAchievementTrophy(6);
    if ( FaceLevelFromExperience >= 10 )
    {
      v7 = 7;
      goto LABEL_19;
    }
  }
}

// File Line: 3282
// RVA: 0x491F80
void __fastcall UFG::GameStatAction::PostStat::AchieveMapBool(
        UFG::GameStat::MapBoolStat stat_enum,
        UFG::qSymbol keyname)
{
  __int64 v2; // rbp
  unsigned int v3; // edx
  UFG::GameStatTracker *v4; // rsi
  UFG::GameStatTracker *v5; // r8
  __int64 v6; // r14
  __int64 v7; // rax
  unsigned int v8; // edi
  int v9; // ebx
  __int64 v10; // rcx
  _BYTE *v11; // rax
  int *v12; // rcx
  int v13; // eax
  int v14; // edx
  UFG::PersistentData::MapBool *v15; // r15
  UFG::PersistentData::MapBool *v16; // rbx
  UFG::PersistentData::MapBool *v17; // rsi
  UFG::PersistentData::MapBool *v18; // r14
  unsigned int TrueCount; // ebp
  unsigned int v20; // ebp
  unsigned int v21; // ebp
  unsigned int v22; // ebp
  unsigned int size; // r8d
  unsigned int v24; // edx
  unsigned int v25; // ecx
  UFG::PersistentData::MapBool *v26; // rsi
  UFG::PersistentData::MapBool *v27; // rbx
  unsigned int v28; // ebp
  unsigned int v29; // ebp
  unsigned int v30; // ecx
  int v31; // ecx

  v2 = stat_enum;
  v3 = _S12_6;
  v4 = &sGameStatTracker;
  if ( (_S12_6 & 1) == 0 )
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
  if ( (v3 & 1) == 0 )
  {
    _S12_6 = v3 | 1;
    UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
    atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
    v5 = UFG::GameStatTracker::mspInstance;
  }
  if ( v5 )
    v4 = v5;
  UFG::GameStatTracker::mspInstance = v4;
  v12 = *(int **)((char *)&v4->mpSnapshots[0]->mTimes[0].mTimer.mTimestamp + v6);
  v13 = *v12;
  if ( *v12 )
  {
    if ( (unsigned int)--v13 > 1 )
      v14 = 0;
    else
      v14 = v12[6];
  }
  else
  {
    v14 = v12[2];
  }
  switch ( v13 )
  {
    case 0:
      goto $LN10_36;
    case 1:
      v15 = UFG::GameStatTracker::Instance()->mpSnapshots[0]->mpMapBools[23];
      v16 = UFG::GameStatTracker::Instance()->mpSnapshots[0]->mpMapBools[24];
      v17 = UFG::GameStatTracker::Instance()->mpSnapshots[0]->mpMapBools[25];
      v18 = UFG::GameStatTracker::Instance()->mpSnapshots[0]->mpMapBools[26];
      TrueCount = UFG::PersistentData::MapBool::GetTrueCount(v18);
      v20 = UFG::PersistentData::MapBool::GetTrueCount(v17) + TrueCount;
      v21 = UFG::PersistentData::MapBool::GetTrueCount(v16) + v20;
      v22 = UFG::PersistentData::MapBool::GetTrueCount(v15) + v21;
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
        if ( (unsigned int)(v17->mKeepType - 1) > 1 )
          v25 = 0;
        else
          v25 = v17->mNames.size;
      }
      else
      {
        v25 = v17->mValues.size;
      }
      if ( v18->mKeepType )
      {
        if ( (unsigned int)(v18->mKeepType - 1) <= 1 )
          v8 = v18->mNames.size;
      }
      else
      {
        v8 = v18->mValues.size;
      }
      if ( v22 == size + v24 + v8 + v25 )
        UFG::AchievementTrophyManager::UnlockAchievementTrophy(38);
      goto $LN10_36;
    case 2:
      v26 = UFG::GameStatTracker::Instance()->mpSnapshots[0]->mpMapBools[27];
      v27 = UFG::GameStatTracker::Instance()->mpSnapshots[0]->mpMapBools[29];
      v28 = UFG::PersistentData::MapBool::GetTrueCount(v27);
      v29 = UFG::PersistentData::MapBool::GetTrueCount(v26) + v28;
      if ( v26->mKeepType )
      {
        if ( (unsigned int)(v26->mKeepType - 1) > 1 )
          v30 = 0;
        else
          v30 = v26->mNames.size;
      }
      else
      {
        v30 = v26->mValues.size;
      }
      if ( v27->mKeepType )
      {
        if ( (unsigned int)(v27->mKeepType - 1) <= 1 )
          v8 = v27->mNames.size;
      }
      else
      {
        v8 = v27->mValues.size;
      }
      if ( v29 == v8 + v30 )
        UFG::AchievementTrophyManager::UnlockAchievementTrophy(33);
      goto $LN10_36;
    case 3:
      if ( v9 == v14 )
        UFG::AchievementTrophyManager::UnlockAchievementTrophy(32);
      goto $LN10_36;
    case 4:
      if ( v9 == v14 )
        UFG::AchievementTrophyManager::UnlockAchievementTrophy(31);
      goto $LN10_36;
    case 5:
      if ( v9 == v14 )
        UFG::AchievementTrophyManager::UnlockAchievementTrophy(36);
$LN10_36:
      UFG::GameStatAction::PostStat::HandleExplorerStatAward();
      return;
    case 6:
      if ( v9 < v14 )
        return;
      v31 = 55;
      break;
    case 7:
      if ( v9 < v14 )
        return;
      v31 = 60;
      break;
    case 8:
      if ( !UFG::GameStatAction::Store::AreAllClothesPurchased() )
        return;
      v31 = 37;
      break;
  }
  UFG::AchievementTrophyManager::UnlockAchievementTrophy(v31);
}

// File Line: 3409
// RVA: 0x4A7400
void UFG::GameStatAction::PostStat::HandleExplorerStatAward(void)
{
  int v0; // esi
  int v1; // ebx
  int *v2; // rdi
  unsigned int v3; // r8d
  UFG::GameStatTracker *v4; // r9
  UFG::GameStatTracker *v5; // rax
  UFG::PersistentData::MapBool *v6; // rax
  unsigned int size; // ecx
  __int64 v8; // rdx
  $CCFB32CF948EEB04FF452B3FEB4ECF53 *v9; // rax
  UFG::OSuiteLeaderboardManager *v10; // rax
  UFG::OSuiteLeaderboardData *LeaderboardDataUsingLeaderboardName; // rax
  _DWORD v12[12]; // [rsp+28h] [rbp-30h] BYREF

  v12[0] = 23;
  v12[1] = 24;
  v12[2] = 25;
  v12[3] = 26;
  v12[4] = 27;
  v12[5] = 28;
  v12[6] = 29;
  v12[7] = 30;
  v12[8] = 7;
  v12[9] = 31;
  v0 = 0;
  v1 = 0;
  v2 = v12;
  v3 = _S12_6;
  v4 = UFG::GameStatTracker::mspInstance;
  do
  {
    if ( (v3 & 1) == 0 )
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
    if ( (v3 & 1) == 0 )
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
    if ( v6->mKeepType == KEEP_FALSE )
    {
      size = 0;
    }
    else if ( v6->mKeepType == KEEP_TRUE )
    {
      size = v6->mNames.size;
    }
    else
    {
      size = 0;
      v8 = v6->mValues.size;
      if ( (_DWORD)v8 )
      {
        v9 = &v6->mValues.p->4;
        do
        {
          if ( v9->mBoolValue )
            ++size;
          v9 += 2;
          --v8;
        }
        while ( v8 );
      }
    }
    v0 += size;
    ++v1;
    ++v2;
  }
  while ( (unsigned __int64)v1 < 0xA );
  v10 = UFG::OSuiteLeaderboardManager::Instance();
  LeaderboardDataUsingLeaderboardName = UFG::OSuiteLeaderboardManager::GetLeaderboardDataUsingLeaderboardName(
                                          v10,
                                          "StatAwardsExplorer");
  UFG::DataSynchronizer::SetMaxToGlobalSnapshot(LeaderboardDataUsingLeaderboardName, v0);
}

// File Line: 3435
// RVA: 0x492350
void __fastcall UFG::GameStatAction::PostStat::AchieveMapInt(UFG::GameStat::MapInt32Stat e, UFG::qSymbol mapid)
{
  __int64 v2; // rbx
  UFG::GameStatTracker *v3; // rdi
  int *v4; // rdx
  int v5; // ebx
  int v6; // ebx
  int v7; // ecx

  v2 = e;
  v3 = &sGameStatTracker;
  if ( (_S12_6 & 1) == 0 )
  {
    _S12_6 |= 1u;
    UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
    atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
  }
  if ( UFG::GameStatTracker::mspInstance )
    v3 = UFG::GameStatTracker::mspInstance;
  UFG::GameStatTracker::mspInstance = v3;
  v4 = (int *)v3->mpSnapshots[0]->mpMapInts[v2];
  v5 = v2 - 24;
  if ( !v5 )
  {
    if ( *v4 < 5 )
      return;
    v7 = 14;
    goto LABEL_14;
  }
  v6 = v5 - 1;
  if ( !v6 )
  {
    if ( *v4 < 10 )
      return;
    v7 = 18;
    goto LABEL_14;
  }
  if ( v6 == 3 && *v4 >= 10 )
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
  float mValue; // xmm1_4
  float v2; // xmm6_4
  float v3; // xmm1_4
  float v4; // xmm1_4
  float v5; // xmm1_4
  UFG::GameSnapshot *v6; // r9
  UFG::PersistentData::MapBool *v7; // rdx
  UFG::PersistentData::MapBool::KeepType mKeepType; // ecx
  int size; // eax
  float v10; // xmm1_4
  int v11; // ecx
  unsigned int v12; // r8d
  $CCFB32CF948EEB04FF452B3FEB4ECF53 *v13; // rax
  __int64 v14; // rdx
  UFG::SimObjectCharacter *LocalPlayer; // rax
  UFG::SimComponent *m_pComponent; // rcx
  float v17; // xmm8_4
  float v18; // xmm1_4
  UFG::GameSnapshot *v19; // rax
  int v20; // ecx
  UFG::GameSnapshot *v21; // rax
  float v22; // xmm1_4
  UFG::AchievementTrophyManager *v23; // r15
  signed int v24; // esi
  __int64 v25; // r14
  UFG::qSymbol *v26; // rbx
  UFG::GameStatTracker *v27; // rax
  unsigned int mUID; // ebx
  UFG::ProgressionTracker *v29; // rax
  UFG::ProgressionTracker *v30; // rsi
  UFG::qBaseTreeRB *v31; // rax
  const char *m_name; // rbx
  UFG::RadioStation *RadioStation; // rax
  const char *v34; // rbx
  UFG::RadioStation *v35; // rax
  char *v36; // rbx
  UFG::qPropertySet *PropertySet; // rax
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
  UFG::PersistentData::MapFloat *v55; // r12
  unsigned int mPrev; // r10d
  UFG::PersistentData::MapInt *v57; // r13
  unsigned int v58; // r11d
  unsigned int v59; // ebx
  __int64 v60; // rdx
  UFG::PersistentData::KeyValue *p; // rax
  int mIntValue; // r9d
  __int64 v63; // rdx
  UFG::PersistentData::KeyValue *v64; // rax
  int v65; // ecx
  float v66; // xmm1_4
  char *v67; // rbx
  UFG::qPropertySet *v68; // rax
  __int64 v69; // rsi
  unsigned int i; // ebx
  UFG::GameSnapshot *v71; // rcx
  int v72; // eax
  __int64 v73; // [rsp+8h] [rbp-79h]
  __int64 v74; // [rsp+8h] [rbp-79h]
  UFG::qString v75; // [rsp+10h] [rbp-71h] BYREF
  UFG::qString result[4]; // [rsp+38h] [rbp-49h] BYREF
  UFG::qSymbol symGameSliceName[2]; // [rsp+E8h] [rbp+67h] BYREF
  UFG::qSymbol *min[4]; // [rsp+F0h] [rbp+6Fh] BYREF

  *(_QWORD *)&v75.mStringHash32 = -2i64;
  v0 = &sGameStatTracker;
  if ( (_S12_6 & 1) == 0 )
  {
    _S12_6 |= 1u;
    UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
    atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
  }
  if ( UFG::GameStatTracker::mspInstance )
    v0 = UFG::GameStatTracker::mspInstance;
  UFG::GameStatTracker::mspInstance = v0;
  mValue = (float)v0->mpSnapshots[0]->mInts[100].mValue;
  v2 = *(float *)&FLOAT_1_0;
  if ( mValue < 1.0 )
    mValue = *(float *)&FLOAT_1_0;
  if ( (*((_BYTE *)v0 + 6216) & 1) == 0 )
    v0->mpSnapshots[0]->mFloats[121].mValue = (float)((float)v0->mpSnapshots[0]->mInts[101].mValue * 100.0) / mValue;
  v3 = (float)v0->mpSnapshots[0]->mInts[102].mValue;
  if ( v3 < 1.0 )
    v3 = *(float *)&FLOAT_1_0;
  if ( (*((_BYTE *)v0 + 6216) & 1) == 0 )
    v0->mpSnapshots[0]->mFloats[122].mValue = (float)((float)v0->mpSnapshots[0]->mInts[103].mValue * 100.0) / v3;
  v4 = (float)v0->mpSnapshots[0]->mInts[105].mValue;
  if ( v4 < 1.0 )
    v4 = *(float *)&FLOAT_1_0;
  if ( (*((_BYTE *)v0 + 6216) & 1) == 0 )
    v0->mpSnapshots[0]->mFloats[123].mValue = (float)((float)v0->mpSnapshots[0]->mInts[106].mValue * 100.0) / v4;
  v5 = (float)v0->mpSnapshots[0]->mInts[108].mValue;
  if ( v5 < 1.0 )
    v5 = *(float *)&FLOAT_1_0;
  if ( (*((_BYTE *)v0 + 6216) & 1) == 0 )
    v0->mpSnapshots[0]->mFloats[124].mValue = (float)((float)v0->mpSnapshots[0]->mInts[109].mValue * 100.0) / v5;
  min[0] = symGameSliceName;
  symGameSliceName[0] = gMissionSymbol_M_VE;
  if ( UFG::GameStatAction::GameSliceAction::IsCompleted(&symGameSliceName[0].mUID) )
  {
    if ( (*((_BYTE *)v0 + 6216) & 1) == 0 )
    {
      UFG::PersistentData::MapBool::SetStatus(v0->mpSnapshots[0]->mpMapBools[66], &gMissionSymbol_M_VE, 1);
      if ( UFG::GameStatAction::PostStat::sIsEnabled )
      {
        min[0] = symGameSliceName;
        symGameSliceName[0] = gMissionSymbol_M_VE;
        UFG::GameStatAction::PostStat::AchieveMapBool(MissionsCompleted, (UFG::qSymbol)symGameSliceName);
      }
    }
  }
  v6 = v0->mpSnapshots[0];
  v7 = v6->mpMapBools[66];
  mKeepType = v7->mKeepType;
  if ( v7->mKeepType )
  {
    if ( (unsigned int)(mKeepType - 1) > 1 )
      size = 0;
    else
      size = v7->mNames.size;
  }
  else
  {
    size = v7->mValues.size;
  }
  v10 = (float)size;
  if ( mKeepType == KEEP_FALSE )
  {
    v11 = 0;
  }
  else if ( mKeepType == KEEP_TRUE )
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
        if ( v13->mBoolValue )
          ++v11;
        v13 += 2;
        --v14;
      }
      while ( v14 );
    }
  }
  if ( v10 < 1.0 )
    v10 = *(float *)&FLOAT_1_0;
  if ( (*((_BYTE *)v0 + 6216) & 1) == 0 )
    v6->mFloats[118].mValue = (float)((float)v11 * 100.0) / v10;
  LocalPlayer = UFG::GetLocalPlayer();
  if ( LocalPlayer )
  {
    m_pComponent = LocalPlayer->m_Components.p[6].m_pComponent;
    if ( m_pComponent )
    {
      if ( (*((_BYTE *)v0 + 6216) & 1) == 0 )
        v0->mpSnapshots[0]->mFloats[127].mValue = (float)(int)*((float *)&m_pComponent[1].m_SafePointerList.mNode.mNext
                                                              + 1);
    }
  }
  v17 = 0.0;
  v18 = 0.0;
  v19 = v0->mpSnapshots[0];
  v20 = v19->mInts[49].mValue;
  if ( v20 && v19->mFloats[85].mValue > 0.0 )
    v18 = v19->mFloats[85].mValue / (float)v20;
  if ( (*((_BYTE *)v0 + 6216) & 1) == 0 )
  {
    v19->mFloats[125].mValue = v18;
    if ( (*((_BYTE *)v0 + 6216) & 1) == 0 )
      v0->mpSnapshots[0]->mFloats[126].mValue = 0.0;
  }
  v21 = v0->mpSnapshots[0];
  v22 = v21->mFloats[1].mValue;
  if ( v22 > 1.0 && (*((_BYTE *)v0 + 6216) & 1) == 0 )
    v21->mFloats[126].mValue = (float)(v21->mFloats[0].mValue / v22) * 3.0;
  v23 = UFG::AchievementTrophyManager::mInstance;
  if ( UFG::AchievementTrophyManager::mInstance )
  {
    v24 = 0;
    v25 = 0i64;
    do
    {
      if ( (unsigned int)v24 <= 0x7F && v23->mTrophyUnlockedFlag[v25] )
      {
        v26 = (UFG::qSymbol *)UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)symGameSliceName, v24);
        v27 = UFG::GameStatTracker::Instance();
        UFG::GameStatTracker::SetStat(v27, AchievementsCompleted, v26, 1);
      }
      ++v24;
      ++v25;
    }
    while ( v24 < 128 );
  }
  UFG::qString::qString(&v75, UFG::GameStatAction::invalid_name);
  if ( (*((_BYTE *)v0 + 6216) & 1) == 0 )
    UFG::qString::Set(&v0->mpSnapshots[0]->mStrings[15].mValue, v75.mData, v75.mLength, 0i64, 0);
  UFG::qString::~qString(&v75);
  mUID = v0->mpSnapshots[0]->mIDs[28].mValue.mUID;
  if ( mUID != -1 )
  {
    v29 = UFG::ProgressionTracker::Instance();
    v30 = v29;
    if ( mUID )
    {
      v31 = UFG::qBaseTreeRB::Get(&v29->mGameSlices.mTree, mUID);
      if ( v31 )
      {
LABEL_70:
        UFG::qString::qString(&v75, (const char *)v31->mNULL.mChild[0]);
        if ( (*((_BYTE *)v0 + 6216) & 1) == 0 )
          UFG::qString::Set(&v0->mpSnapshots[0]->mStrings[15].mValue, v75.mData, v75.mLength, 0i64, 0);
        UFG::qString::~qString(&v75);
        goto LABEL_73;
      }
      v31 = UFG::qBaseTreeRB::Get(&v30->mContainerGameSlices.mTree, mUID);
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
  UFG::PersistentData::MapFloat::GetMaxMin(
    v0->mpSnapshots[0]->mpMapFloats[2],
    (UFG::PersistentData::KeyValue **)symGameSliceName,
    (UFG::PersistentData::KeyValue **)min);
  m_name = UFG::GameStatAction::invalid_name;
  if ( *(_QWORD *)&symGameSliceName[0].mUID )
  {
    RadioStation = UFG::Radio::FindRadioStation(*(UFG::qSymbol **)&symGameSliceName[0].mUID);
    if ( RadioStation )
      m_name = RadioStation->m_name;
  }
  UFG::qString::qString(&v75, m_name);
  if ( (*((_BYTE *)v0 + 6216) & 1) == 0 )
    UFG::qString::Set(&v0->mpSnapshots[0]->mStrings[7].mValue, v75.mData, v75.mLength, 0i64, 0);
  UFG::qString::~qString(&v75);
  v34 = UFG::GameStatAction::invalid_name;
  if ( min[0] )
  {
    v35 = UFG::Radio::FindRadioStation(min[0]);
    if ( v35 )
      v34 = v35->m_name;
  }
  UFG::qString::qString(&v75, v34);
  if ( (*((_BYTE *)v0 + 6216) & 1) == 0 )
    UFG::qString::Set(&v0->mpSnapshots[0]->mStrings[8].mValue, v75.mData, v75.mLength, 0i64, 0);
  UFG::qString::~qString(&v75);
  UFG::PersistentData::MapFloat::GetMaxMin(
    v0->mpSnapshots[0]->mpMapFloats[3],
    (UFG::PersistentData::KeyValue **)symGameSliceName,
    (UFG::PersistentData::KeyValue **)min);
  v36 = (char *)UFG::GameStatAction::invalid_name;
  if ( *(_QWORD *)&symGameSliceName[0].mUID )
  {
    PropertySet = UFG::PropertySetManager::GetPropertySet(*(UFG::qSymbol **)&symGameSliceName[0].mUID);
    if ( PropertySet )
      v36 = PropertyUtils::Get<char const *>(
              PropertySet,
              (UFG::qArray<unsigned long,0> *)&sSymDescription,
              DEPTH_RECURSE);
  }
  UFG::qString::qString(&v75, v36);
  if ( (*((_BYTE *)v0 + 6216) & 1) == 0 )
    UFG::qString::Set(&v0->mpSnapshots[0]->mStrings[9].mValue, v75.mData, v75.mLength, 0i64, 0);
  UFG::qString::~qString(&v75);
  v38 = (char *)UFG::GameStatAction::invalid_name;
  if ( min[0] )
  {
    v39 = UFG::PropertySetManager::GetPropertySet(min[0]);
    if ( v39 )
      v38 = PropertyUtils::Get<char const *>(v39, (UFG::qArray<unsigned long,0> *)&sSymDescription, DEPTH_RECURSE);
  }
  UFG::qString::qString(&v75, v38);
  if ( (*((_BYTE *)v0 + 6216) & 1) == 0 )
    UFG::qString::Set(&v0->mpSnapshots[0]->mStrings[10].mValue, v75.mData, v75.mLength, 0i64, 0);
  UFG::qString::~qString(&v75);
  UFG::PersistentData::MapFloat::GetMaxMin(
    v0->mpSnapshots[0]->mpMapFloats[4],
    (UFG::PersistentData::KeyValue **)symGameSliceName,
    (UFG::PersistentData::KeyValue **)min);
  v40 = (char *)UFG::GameStatAction::invalid_name;
  if ( *(_QWORD *)&symGameSliceName[0].mUID )
  {
    v41 = UFG::PropertySetManager::GetPropertySet(*(UFG::qSymbol **)&symGameSliceName[0].mUID);
    if ( v41 )
      v40 = PropertyUtils::Get<char const *>(v41, (UFG::qArray<unsigned long,0> *)&sSymDescription, DEPTH_RECURSE);
  }
  UFG::qString::qString(&v75, v40);
  if ( (*((_BYTE *)v0 + 6216) & 1) == 0 )
    UFG::qString::Set(&v0->mpSnapshots[0]->mStrings[11].mValue, v75.mData, v75.mLength, 0i64, 0);
  UFG::qString::~qString(&v75);
  v42 = (char *)UFG::GameStatAction::invalid_name;
  if ( min[0] )
  {
    v43 = UFG::PropertySetManager::GetPropertySet(min[0]);
    if ( v43 )
      v42 = PropertyUtils::Get<char const *>(v43, (UFG::qArray<unsigned long,0> *)&sSymDescription, DEPTH_RECURSE);
  }
  UFG::qString::qString(&v75, v42);
  if ( (*((_BYTE *)v0 + 6216) & 1) == 0 )
    UFG::qString::Set(&v0->mpSnapshots[0]->mStrings[12].mValue, v75.mData, v75.mLength, 0i64, 0);
  UFG::qString::~qString(&v75);
  UFG::PersistentData::MapFloat::GetMaxMin(
    v0->mpSnapshots[0]->mpMapFloats[5],
    (UFG::PersistentData::KeyValue **)symGameSliceName,
    (UFG::PersistentData::KeyValue **)min);
  v44 = (char *)UFG::GameStatAction::invalid_name;
  if ( *(_QWORD *)&symGameSliceName[0].mUID )
  {
    v45 = UFG::PropertySetManager::GetPropertySet(*(UFG::qSymbol **)&symGameSliceName[0].mUID);
    if ( v45 )
      v44 = PropertyUtils::Get<char const *>(v45, (UFG::qArray<unsigned long,0> *)&sSymDescription, DEPTH_RECURSE);
  }
  UFG::qString::qString(&v75, v44);
  if ( (*((_BYTE *)v0 + 6216) & 1) == 0 )
    UFG::qString::Set(&v0->mpSnapshots[0]->mStrings[13].mValue, v75.mData, v75.mLength, 0i64, 0);
  UFG::qString::~qString(&v75);
  v46 = (char *)UFG::GameStatAction::invalid_name;
  if ( min[0] )
  {
    v47 = UFG::PropertySetManager::GetPropertySet(min[0]);
    if ( v47 )
      v46 = PropertyUtils::Get<char const *>(v47, (UFG::qArray<unsigned long,0> *)&sSymDescription, DEPTH_RECURSE);
  }
  UFG::qString::qString(&v75, v46);
  if ( (*((_BYTE *)v0 + 6216) & 1) == 0 )
    UFG::qString::Set(&v0->mpSnapshots[0]->mStrings[14].mValue, v75.mData, v75.mLength, 0i64, 0);
  UFG::qString::~qString(&v75);
  UFG::PersistentData::MapInt::GetMaxMin(
    v0->mpSnapshots[0]->mpMapInts[28],
    (UFG::PersistentData::KeyValue **)symGameSliceName,
    (UFG::PersistentData::KeyValue **)min);
  v48 = (char *)UFG::GameStatAction::invalid_name;
  if ( *(_QWORD *)&symGameSliceName[0].mUID )
  {
    v49 = UFG::PropertySetManager::GetPropertySet(*(UFG::qSymbol **)&symGameSliceName[0].mUID);
    if ( v49 )
      v48 = PropertyUtils::Get<char const *>(v49, (UFG::qArray<unsigned long,0> *)&sSymDescription, DEPTH_RECURSE);
  }
  UFG::qString::qString(&v75, v48);
  if ( (*((_BYTE *)v0 + 6216) & 1) == 0 )
    UFG::qString::Set(&v0->mpSnapshots[0]->mStrings[20].mValue, v75.mData, v75.mLength, 0i64, 0);
  UFG::qString::~qString(&v75);
  UFG::PersistentData::MapInt::GetMaxMin(
    v0->mpSnapshots[0]->mpMapInts[26],
    (UFG::PersistentData::KeyValue **)symGameSliceName,
    (UFG::PersistentData::KeyValue **)min);
  v50 = (char *)UFG::GameStatAction::invalid_name;
  if ( *(_QWORD *)&symGameSliceName[0].mUID )
  {
    v51 = UFG::PropertySetManager::GetPropertySet(*(UFG::qSymbol **)&symGameSliceName[0].mUID);
    if ( v51 )
      v50 = PropertyUtils::Get<char const *>(v51, (UFG::qArray<unsigned long,0> *)&sSymDescription, DEPTH_RECURSE);
  }
  UFG::qString::qString(&v75, v50);
  if ( (*((_BYTE *)v0 + 6216) & 1) == 0 )
    UFG::qString::Set(&v0->mpSnapshots[0]->mStrings[21].mValue, v75.mData, v75.mLength, 0i64, 0);
  UFG::qString::~qString(&v75);
  v52 = 0.0;
  v53 = 0i64;
  v54 = v0->mpSnapshots[0];
  v55 = (UFG::PersistentData::MapFloat *)v54->mpMapInts[26];
  UFG::PersistentData::MapInt::GetIterator(v55, (UFG::PersistentData::MapFloat::Iterator *)result);
  mPrev = (unsigned int)result[0].mPrev;
  if ( LODWORD(result[0].mPrev) < *(_DWORD *)v73 )
  {
    v57 = v54->mpMapInts[27];
    v58 = v57->mValues.size;
    v59 = v55->mValues.size;
    do
    {
      v60 = 0i64;
      if ( !v58 )
        goto LABEL_132;
      p = v57->mValues.p;
      while ( p->mKey.mUID != *(_DWORD *)(*(_QWORD *)(v73 + 8) + 8i64 * mPrev) )
      {
        v60 = (unsigned int)(v60 + 1);
        ++p;
        if ( (unsigned int)v60 >= v58 )
          goto LABEL_132;
      }
      if ( (_DWORD)v60 == -1 )
LABEL_132:
        mIntValue = 0;
      else
        mIntValue = v57->mValues.p[v60].mIntValue;
      v63 = 0i64;
      if ( !v59 )
        goto LABEL_140;
      v64 = v55->mValues.p;
      while ( v64->mKey.mUID != *(_DWORD *)(*(_QWORD *)(v73 + 8) + 8i64 * mPrev) )
      {
        v63 = (unsigned int)(v63 + 1);
        ++v64;
        if ( (unsigned int)v63 >= v59 )
          goto LABEL_140;
      }
      if ( (_DWORD)v63 == -1 )
LABEL_140:
        v65 = 0;
      else
        v65 = v55->mValues.p[v63].mIntValue;
      v66 = (float)v65;
      if ( (float)v65 < 1.0 )
        v66 = *(float *)&FLOAT_1_0;
      if ( (float)((float)mIntValue / v66) > v52 )
      {
        v53 = (UFG::qSymbol *)(*(_QWORD *)(v73 + 8) + 8i64 * mPrev);
        v52 = (float)mIntValue / v66;
      }
      ++mPrev;
    }
    while ( mPrev < *(_DWORD *)v73 );
  }
  v67 = (char *)UFG::GameStatAction::invalid_name;
  if ( v53 )
  {
    v68 = UFG::PropertySetManager::GetPropertySet(v53);
    if ( v68 )
      v67 = PropertyUtils::Get<char const *>(v68, (UFG::qArray<unsigned long,0> *)&sSymDescription, DEPTH_RECURSE);
  }
  UFG::qString::qString(&v75, v67);
  if ( (*((_BYTE *)v0 + 6216) & 1) == 0 )
    UFG::qString::Set(&v0->mpSnapshots[0]->mStrings[19].mValue, v75.mData, v75.mLength, 0i64, 0);
  UFG::qString::~qString(&v75);
  UFG::qString::FormatEx(
    result,
    "%d / %d",
    (unsigned int)(v0->mpSnapshots[0]->mInts[22].mValue + v0->mpSnapshots[0]->mInts[23].mValue),
    12i64);
  UFG::qString::qString(&v75, result[0].mData);
  if ( (*((_BYTE *)v0 + 6216) & 1) == 0 )
    UFG::qString::Set(&v0->mpSnapshots[0]->mStrings[16].mValue, v75.mData, v75.mLength, 0i64, 0);
  UFG::qString::~qString(&v75);
  UFG::qString::~qString(result);
  UFG::qString::FormatEx(
    result,
    "%d / %d",
    (unsigned int)(v0->mpSnapshots[0]->mInts[27].mValue + v0->mpSnapshots[0]->mInts[28].mValue),
    10i64);
  UFG::qString::qString(&v75, result[0].mData);
  if ( (*((_BYTE *)v0 + 6216) & 1) == 0 )
    UFG::qString::Set(&v0->mpSnapshots[0]->mStrings[17].mValue, v75.mData, v75.mLength, 0i64, 0);
  UFG::qString::~qString(&v75);
  UFG::qString::~qString(result);
  UFG::qString::FormatEx(
    result,
    "%d / %d",
    (unsigned int)(v0->mpSnapshots[0]->mInts[24].mValue + v0->mpSnapshots[0]->mInts[25].mValue),
    10i64);
  UFG::qString::qString(&v75, result[0].mData);
  if ( (*((_BYTE *)v0 + 6216) & 1) == 0 )
    UFG::qString::Set(&v0->mpSnapshots[0]->mStrings[18].mValue, v75.mData, v75.mLength, 0i64, 0);
  UFG::qString::~qString(&v75);
  UFG::qString::~qString(result);
  if ( (*((_BYTE *)v0 + 6216) & 1) == 0 )
  {
    v0->mpSnapshots[0]->mInts[154].mValue = 0;
    if ( UFG::GameStatAction::PostStat::sIsEnabled )
      UFG::GameStatAction::PostStat::AchieveInt(PhotosSaved);
  }
  UFG::PersistentData::MapInt::GetIterator(
    (UFG::PersistentData::MapFloat *)v0->mpSnapshots[0]->mpMapBinaries[0],
    (UFG::PersistentData::MapFloat::Iterator *)result);
  v69 = v74;
  for ( i = (unsigned int)result[0].mPrev; i < *(_DWORD *)v69; ++i )
  {
    if ( *(_QWORD *)(v69 + 8) + 8 * (3i64 * i + 1) )
    {
      if ( (*((_BYTE *)v0 + 6216) & 1) == 0 )
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
  v71 = v0->mpSnapshots[0];
  v72 = v71->mInts[51].mValue;
  if ( v72 )
  {
    if ( (float)v72 >= 1.0 )
      v2 = (float)v72;
    v17 = (float)((float)(v71->mInts[51].mValue - v71->mInts[52].mValue) * 100.0) / v2;
  }
  if ( (*((_BYTE *)v0 + 6216) & 1) == 0 )
    v71->mFloats[119].mValue = v17;
  UFG::GameStatTracker::SetStat(
    v0,
    BuffsPurchased,
    v0->mpSnapshots[0]->mInts[79].mValue
  + v0->mpSnapshots[0]->mInts[80].mValue
  + v0->mpSnapshots[0]->mInts[81].mValue
  + v0->mpSnapshots[0]->mInts[82].mValue);
}

