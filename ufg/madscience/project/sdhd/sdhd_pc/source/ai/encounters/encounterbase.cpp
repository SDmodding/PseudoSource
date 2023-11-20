// File Line: 132
// RVA: 0x3F3A80
void __fastcall UFG::EncounterBase_VehicleDisabledHandler(UFG::Event *pEvent)
{
  UFG::qNode<UFG::Event,UFG::Event> *v1; // rbx
  UFG::AiDriverComponent *v2; // rax
  UFG::CopUnitComponent *v3; // rcx

  v1 = pEvent[1].mNext;
  if ( v1 )
  {
    v2 = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>((UFG::SimObjectCVBase *)pEvent[1].mNext);
    if ( v2 )
      v2->m_DesiredSpeedLimit = 8.333334;
    v3 = (UFG::CopUnitComponent *)v1[6].mNext[17].mPrev;
    if ( v3 )
      UFG::CopUnitComponent::DisableHandler(v3);
  }
}

// File Line: 199
// RVA: 0x3F2250
void __fastcall UFG::EncounterBase::EncounterBase(UFG::EncounterBase *this)
{
  UFG::EncounterBase *v1; // r14
  signed __int64 v2; // rbp
  UFG::qSymbol *v3; // rdi
  float v4; // xmm1_4
  float v5; // xmm2_4
  bool *v6; // rsi
  UFG::qPropertySet **v7; // rbx
  void (__fastcall *v8)(fastdelegate::FastDelegate1<char const *,void> *, const char *); // rbx
  void (__fastcall *v9)(fastdelegate::FastDelegate1<char const *,void> *, const char *); // rax
  void (__fastcall *v10)(UFG::Event *); // [rsp+38h] [rbp-50h]
  void (__fastcall *v11)(fastdelegate::FastDelegate1<char const *,void> *, const char *); // [rsp+40h] [rbp-48h]
  void (__fastcall *v12)(UFG::Event *); // [rsp+48h] [rbp-40h]
  void (__fastcall *v13)(fastdelegate::FastDelegate1<char const *,void> *, const char *); // [rsp+50h] [rbp-38h]
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v14; // [rsp+98h] [rbp+10h]
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v15; // [rsp+98h] [rbp+10h]
  UFG::qSafePointer<UFG::CombatRegion,UFG::CombatRegion> *v16; // [rsp+98h] [rbp+10h]

  v1 = this;
  UFG::qSafePointerNodeWithCallbacks<UFG::EncounterBase>::qSafePointerNodeWithCallbacks<UFG::EncounterBase>((UFG::qSafePointerNodeWithCallbacks<UFG::EncounterBase> *)&this->vfptr);
  v1->vfptr = (UFG::qSafePointerNode<UFG::EncounterBase>Vtbl *)&UFG::EncounterBase::`vftable';
  v1->mEnable = 1;
  UFG::PropertySetHandle::PropertySetHandle(&v1->mProperties);
  v1->mObjective = 0;
  v1->mPostObjective = 36;
  v1->mCurrentWaveType.mUID = -1;
  v2 = 6i64;
  `eh vector constructor iterator'(
    v1->mHeatLevelPropertiesName,
    4ui64,
    6,
    (void (__fastcall *)(void *))BackInfo::BackInfo);
  v3 = v1->mWaterHeatLevelPropertiesName;
  `eh vector constructor iterator'(
    v1->mWaterHeatLevelPropertiesName,
    4ui64,
    6,
    (void (__fastcall *)(void *))BackInfo::BackInfo);
  *(_QWORD *)&v1->mInsideDynamicRadiusCount = 0i64;
  v1->mMaxHeatLevel = -1;
  v1->mpVehicleSpawnSensor = 0i64;
  v1->mStartTimestamp = 0i64;
  *(_QWORD *)&v1->mVehicleSpawnIteratingIndex = 0i64;
  v4 = UFG::qVector3::msZero.y;
  v5 = UFG::qVector3::msZero.z;
  v1->mFocusTargetPosition.x = UFG::qVector3::msZero.x;
  v1->mFocusTargetPosition.y = v4;
  v1->mFocusTargetPosition.z = v5;
  *(_QWORD *)&v1->mWaveCount = 0i64;
  *(_QWORD *)&v1->mWaveTimer = 0i64;
  *(_QWORD *)&v1->mSpawnTimeout = 0i64;
  *(_QWORD *)&v1->mReducedRadiusPercentage = 1065353216i64;
  *(_DWORD *)&v1->mIsStaysOffSidewalk = 0;
  *(_DWORD *)&v1->mIsReplenishing = 0x1000000;
  v1->mEnableWaveTimerChangesByDisabledUnits = 0;
  v1->mFocusTargetContext.mpSimObject = 0i64;
  v1->mFocusTargetContext.mpVehicle = 0i64;
  v1->mFocusTargetContext.mWaterContextTimer = 0.0;
  *(_DWORD *)&v1->mFocusTargetContext.mIsOnFootRaw = 16777217;
  *(_WORD *)&v1->mFocusTargetContext.mIsOnMeshHeuristic = 1;
  v1->mFocusTargetContext.mOpenFiredWithHostage = 0;
  v1->mHumans.size = 0;
  v1->mVehicles.size = 0;
  v1->mHumanSpawnRegions.size = 0;
  *(_QWORD *)&v1->mNumWaveGroupTypes = 0i64;
  *(_QWORD *)&v1->mNumDesiredCharacterGroups = 0i64;
  *(_QWORD *)&v1->mCharacterSpawnCount = 0i64;
  v1->mCharacterKillCount = 0;
  UFG::VehicleWayFinderClient::VehicleWayFinderClient(
    (UFG::VehicleWayFinderClient *)&v1->mWayTraversalClient.vfptr,
    0i64,
    0xFFFFFFFF);
  v1->mWayTraversalClient.vfptr = (UFG::WayFinderClientVtbl *)&UFG::WayTraversalClient::`vftable';
  v14 = &v1->mpFocusTarget;
  v14->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v14->mPrev;
  v14->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v14->mPrev;
  v1->mpFocusTarget.m_pPointer = 0i64;
  v15 = &v1->mpSecondaryTarget;
  v15->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v15->mPrev;
  v15->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v15->mPrev;
  v1->mpSecondaryTarget.m_pPointer = 0i64;
  v16 = &v1->mpCombatRegion;
  v16->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::CombatRegion>,UFG::qSafePointerNodeList> *)&v16->mPrev;
  v16->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::CombatRegion>,UFG::qSafePointerNodeList> *)&v16->mPrev;
  v1->mpCombatRegion.m_pPointer = 0i64;
  v1->mHumans.size = 0;
  v1->mVehicles.size = 0;
  v1->mHumanSpawnRegions.size = 0;
  v6 = v1->mPreloadedResources;
  v7 = v1->mWaterHeatLevelProperties;
  do
  {
    UFG::qSymbol::set_null(v3 - 6);
    UFG::qSymbol::set_null(v3);
    *(v7 - 6) = 0i64;
    *v7 = 0i64;
    *v6 = 0;
    ++v3;
    ++v7;
    ++v6;
    --v2;
  }
  while ( v2 );
  if ( !registeredStaticEventHandlers )
  {
    v8 = fastdelegate::FastDelegate1<char const *,void>::InvokeStaticFunction;
    v9 = fastdelegate::FastDelegate1<char const *,void>::InvokeStaticFunction;
    if ( !UFG::EncounterBase_VehicleDisabledHandler )
      v9 = 0i64;
    v13 = v9;
    v12 = UFG::EncounterBase_VehicleDisabledHandler;
    v11 = v9;
    v10 = UFG::EncounterBase_VehicleDisabledHandler;
    UFG::EventDispatcher::Register(
      &UFG::EventDispatcher::mInstance,
      (fastdelegate::FastDelegate1<UFG::Event *,void> *)&v10,
      UFG::gVehicleTakenDownChannel.mUID,
      0i64,
      0);
    if ( !UFG::EncounterBase_VehicleDisabledHandler )
      v8 = 0i64;
    v13 = v8;
    v12 = UFG::EncounterBase_VehicleDisabledHandler;
    v11 = v8;
    v10 = UFG::EncounterBase_VehicleDisabledHandler;
    UFG::EventDispatcher::Register(
      &UFG::EventDispatcher::mInstance,
      (fastdelegate::FastDelegate1<UFG::Event *,void> *)&v10,
      UFG::gVehicleDisabledChannel.mUID,
      0i64,
      0);
    registeredStaticEventHandlers = 1;
  }
}

// File Line: 229
// RVA: 0x3F2880
void __fastcall UFG::EncounterBase::~EncounterBase(UFG::EncounterBase *this)
{
  UFG::EncounterBase *v1; // rbx
  UFG::qSafePointer<UFG::CombatRegion,UFG::CombatRegion> *v2; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::CombatRegion>,UFG::qSafePointerNodeList> *v3; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::CombatRegion>,UFG::qSafePointerNodeList> *v4; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::CombatRegion>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::CombatRegion>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v7; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v10; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v11; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v12; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v13; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v14; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v15; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v16; // rax
  UFG::WayTraversalClient *v17; // [rsp+48h] [rbp+10h]

  v1 = this;
  this->vfptr = (UFG::qSafePointerNode<UFG::EncounterBase>Vtbl *)&UFG::EncounterBase::`vftable';
  UFG::EncounterBase::Shutdown(this);
  v2 = &v1->mpCombatRegion;
  if ( v1->mpCombatRegion.m_pPointer )
  {
    v3 = v2->mPrev;
    v4 = v1->mpCombatRegion.mNext;
    v3->mNext = v4;
    v4->mPrev = v3;
    v2->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::CombatRegion>,UFG::qSafePointerNodeList> *)&v2->mPrev;
    v1->mpCombatRegion.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::CombatRegion>,UFG::qSafePointerNodeList> *)&v1->mpCombatRegion.mPrev;
  }
  v1->mpCombatRegion.m_pPointer = 0i64;
  v5 = v2->mPrev;
  v6 = v1->mpCombatRegion.mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  v2->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::CombatRegion>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  v1->mpCombatRegion.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::CombatRegion>,UFG::qSafePointerNodeList> *)&v1->mpCombatRegion.mPrev;
  v7 = &v1->mpSecondaryTarget;
  if ( v1->mpSecondaryTarget.m_pPointer )
  {
    v8 = v7->mPrev;
    v9 = v1->mpSecondaryTarget.mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    v7->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v7->mPrev;
    v1->mpSecondaryTarget.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v1->mpSecondaryTarget.mPrev;
  }
  v1->mpSecondaryTarget.m_pPointer = 0i64;
  v10 = v7->mPrev;
  v11 = v1->mpSecondaryTarget.mNext;
  v10->mNext = v11;
  v11->mPrev = v10;
  v7->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v7->mPrev;
  v1->mpSecondaryTarget.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v1->mpSecondaryTarget.mPrev;
  v12 = &v1->mpFocusTarget;
  if ( v1->mpFocusTarget.m_pPointer )
  {
    v13 = v12->mPrev;
    v14 = v1->mpFocusTarget.mNext;
    v13->mNext = v14;
    v14->mPrev = v13;
    v12->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v12->mPrev;
    v1->mpFocusTarget.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v1->mpFocusTarget.mPrev;
  }
  v1->mpFocusTarget.m_pPointer = 0i64;
  v15 = v12->mPrev;
  v16 = v1->mpFocusTarget.mNext;
  v15->mNext = v16;
  v16->mPrev = v15;
  v12->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v12->mPrev;
  v1->mpFocusTarget.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v1->mpFocusTarget.mPrev;
  v17 = &v1->mWayTraversalClient;
  v17->vfptr = (UFG::WayFinderClientVtbl *)&UFG::VehicleWayFinderClient::`vftable';
  v17->vfptr = (UFG::WayFinderClientVtbl *)&UFG::WayFinderClient::`vftable';
  v1->mHumanSpawnRegions.size = 0;
  v1->mVehicles.size = 0;
  v1->mHumans.size = 0;
  `eh vector destructor iterator'(v1->mWaterHeatLevelPropertiesName, 4ui64, 6, (void (__fastcall *)(void *))_);
  `eh vector destructor iterator'(v1->mHeatLevelPropertiesName, 4ui64, 6, (void (__fastcall *)(void *))_);
  UFG::PropertySetHandle::~PropertySetHandle(&v1->mProperties);
  UFG::qSafePointerNodeWithCallbacks<UFG::EncounterBase>::~qSafePointerNodeWithCallbacks<UFG::EncounterBase>((UFG::qSafePointerNodeWithCallbacks<UFG::EncounterBase> *)&v1->vfptr);
}

// File Line: 234
// RVA: 0x3F4030
UFG::qPropertySet *__fastcall UFG::FindWave(UFG::qPropertyList *pWaveList, UFG::qSymbol *identifier)
{
  unsigned int v2; // edi
  unsigned int v3; // ebx
  UFG::qSymbol *v4; // rsi
  UFG::qPropertyList *v5; // rbp
  char *v6; // rax
  char *v7; // rcx

  v2 = pWaveList->mNumElements;
  v3 = 0;
  v4 = identifier;
  v5 = pWaveList;
  if ( !v2 )
    return 0i64;
  while ( 1 )
  {
    v6 = UFG::qPropertyList::GetValuePtr(v5, 0x1Au, v3);
    if ( v6 )
    {
      if ( *(_QWORD *)v6 )
      {
        v7 = &v6[*(_QWORD *)v6];
        if ( v7 )
        {
          if ( *((_DWORD *)v7 + 16) == v4->mUID )
            break;
        }
      }
    }
    if ( ++v3 >= v2 )
      return 0i64;
  }
  return (UFG::qPropertySet *)&v6[*(_QWORD *)v6];
}

// File Line: 252
// RVA: 0x3F40B0
signed __int64 __fastcall UFG::EncounterBase::FindWaveGroupIndex(UFG::EncounterBase *this, UFG::qPropertySet *pGroupPropertySet)
{
  UFG::qPropertySet *v2; // rsi
  UFG::qPropertySet *v3; // rax
  UFG::qPropertyList *v4; // rax
  unsigned int v5; // ebx
  unsigned int v6; // edi
  UFG::qPropertyList *v7; // rbp
  char *v8; // rax
  UFG::qPropertySet *v9; // rax

  v2 = pGroupPropertySet;
  v3 = (UFG::qPropertySet *)((__int64 (*)(void))this->vfptr[33].__vecDelDtor)();
  v4 = UFG::qPropertySet::Get<UFG::qPropertyList>(v3, (UFG::qSymbol *)&EncounterSym_spawn_groups.mUID, DEPTH_RECURSE);
  v5 = 0;
  v6 = v4->mNumElements;
  v7 = v4;
  if ( !v6 )
    return 0xFFFFFFFFi64;
  while ( 1 )
  {
    v8 = UFG::qPropertyList::GetValuePtr(v7, 0x1Au, v5);
    if ( v8 && *(_QWORD *)v8 )
      v9 = (UFG::qPropertySet *)&v8[*(_QWORD *)v8];
    else
      v9 = 0i64;
    if ( v9 == v2 )
      break;
    if ( ++v5 >= v6 )
      return 0xFFFFFFFFi64;
  }
  return v5;
}

// File Line: 269
// RVA: 0x3F9430
void __fastcall UFG::EncounterBase::SetPropertySet(UFG::EncounterBase *this, const char *pPropertySetName)
{
  UFG::EncounterBase *v2; // r13
  UFG::qSymbol *v3; // rax
  UFG::qPropertySet *v4; // rax
  UFG::qPropertySet *v5; // r12
  UFG::qPropertySet *v6; // rcx
  char *v7; // rax
  const char **v8; // rsi
  const char *v9; // rbp
  unsigned int v10; // ebx
  const char **v11; // rdi
  char *v12; // rax
  const char *v13; // rdi
  unsigned int v14; // ebx
  UFG::qPropertySet **v15; // r14
  char *v16; // rbx
  UFG::qSymbol *v17; // rdi
  UFG::qPropertyList *v18; // rbp
  signed __int64 v19; // r15
  char *v20; // r13
  UFG::qSymbol *v21; // rax
  unsigned int v22; // ebx
  unsigned int v23; // esi
  char *v24; // rax
  char *v25; // rcx
  unsigned int v26; // esi
  unsigned int v27; // ebx
  char *v28; // rax
  char *v29; // rcx
  bool *v30; // rax
  UFG::EncounterBase *v31; // [rsp+60h] [rbp+8h]
  UFG::qSymbol result; // [rsp+70h] [rbp+18h]
  UFG::qSymbol **v33; // [rsp+78h] [rbp+20h]

  v31 = this;
  v2 = this;
  v3 = UFG::qSymbol::create_from_string(&result, pPropertySetName);
  v4 = UFG::PropertySetManager::GetPropertySet(v3);
  UFG::PropertySetHandle::SetPropSet(&v2->mProperties, v4);
  UFG::PropertySetHandle::Bind(&v2->mProperties);
  v5 = v2->mProperties.mpPropSet;
  v6 = v2->mProperties.mpPropSet;
  v2->mObjective = 0;
  v7 = UFG::qPropertySet::Get<char const *>(v6, (UFG::qSymbol *)&qSymbol_AIObjective.mUID, DEPTH_RECURSE);
  v8 = UFG::AIObjectiveNames;
  v9 = v7;
  if ( v7 && *v7 )
  {
    v10 = 0;
    v11 = UFG::AIObjectiveNames;
    while ( (unsigned int)UFG::qStringCompareInsensitive(v9, *v11, -1) )
    {
      ++v10;
      ++v11;
      if ( v10 >= 0x24 )
        goto LABEL_8;
    }
    v2->mObjective = v10;
  }
LABEL_8:
  v2->mPostObjective = 36;
  v12 = UFG::qPropertySet::Get<char const *>(v5, (UFG::qSymbol *)&qSymbol_PostAIObjective.mUID, DEPTH_RECURSE);
  v13 = v12;
  if ( v12 && *v12 )
  {
    v14 = 0;
    while ( (unsigned int)UFG::qStringCompareInsensitive(v13, *v8, -1) )
    {
      ++v14;
      ++v8;
      if ( v14 >= 0x24 )
        goto LABEL_15;
    }
    v2->mPostObjective = v14;
  }
LABEL_15:
  v15 = v2->mWaterHeatLevelProperties;
  v16 = (char *)((char *)EncounterProperty_water_heat_level_property_set - (char *)v2 - 176);
  v17 = v2->mWaterHeatLevelPropertiesName;
  v18 = UFG::qPropertySet::Get<UFG::qPropertyList>(
          v5,
          (UFG::qSymbol *)&EncounterSym_wave_definitions.mUID,
          DEPTH_RECURSE);
  v19 = 6i64;
  v33 = (UFG::qSymbol **)((char *)EncounterProperty_water_heat_level_property_set - (char *)v2 - 176);
  v20 = (char *)((char *)EncounterProperty_heat_level_property_set - (char *)v2 - 176);
  do
  {
    v17[-6].mUID = UFG::qPropertySet::Get<UFG::qSymbol>(
                     v5,
                     *(UFG::qSymbol **)((char *)v15 + (_QWORD)v20),
                     DEPTH_RECURSE)->mUID;
    v21 = UFG::qPropertySet::Get<UFG::qSymbol>(v5, *(UFG::qSymbol **)((char *)v15 + (_QWORD)v16), DEPTH_RECURSE);
    v22 = 0;
    v17->mUID = v21->mUID;
    v23 = v18->mNumElements;
    if ( v23 )
    {
      while ( 1 )
      {
        v24 = UFG::qPropertyList::GetValuePtr(v18, 0x1Au, v22);
        if ( v24 )
        {
          if ( *(_QWORD *)v24 )
          {
            v25 = &v24[*(_QWORD *)v24];
            if ( v25 )
            {
              if ( *((_DWORD *)v25 + 16) == v17[-6].mUID )
                break;
            }
          }
        }
        if ( ++v22 >= v23 )
          goto LABEL_22;
      }
    }
    else
    {
LABEL_22:
      v25 = 0i64;
    }
    *(v15 - 6) = (UFG::qPropertySet *)v25;
    v26 = v18->mNumElements;
    v27 = 0;
    if ( v26 )
    {
      while ( 1 )
      {
        v28 = UFG::qPropertyList::GetValuePtr(v18, 0x1Au, v27);
        if ( v28 )
        {
          if ( *(_QWORD *)v28 )
          {
            v29 = &v28[*(_QWORD *)v28];
            if ( v29 )
            {
              if ( *((_DWORD *)v29 + 16) == v17->mUID )
                break;
            }
          }
        }
        if ( ++v27 >= v26 )
          goto LABEL_29;
      }
    }
    else
    {
LABEL_29:
      v29 = 0i64;
    }
    v16 = (char *)v33;
    *v15 = (UFG::qPropertySet *)v29;
    ++v15;
    ++v17;
    --v19;
  }
  while ( v19 );
  v30 = UFG::qPropertySet::Get<bool>(
          v5,
          (UFG::qSymbol *)&EncounterSym_suppress_vehicle_spawning_by_kill.mUID,
          DEPTH_RECURSE);
  if ( v30 )
    v31->mSuppressVehicleSpawningByKillCount = *v30;
  else
    v31->mSuppressVehicleSpawningByKillCount = 0;
}

// File Line: 318
// RVA: 0x3F7C50
void __fastcall UFG::EncounterBase::Initialize(UFG::EncounterBase *this)
{
  UFG::EncounterBase *v1; // rdi
  int *v2; // rax
  signed __int64 v3; // rcx
  float v4; // xmm1_4
  float v5; // xmm2_4
  UFG::qPropertySet *v6; // rbx
  UFG::qSymbol *v7; // rax
  __m128 v8; // xmm7
  __m128 v9; // xmm6
  __m128 v10; // xmm5
  UFG::allocator::free_link *v11; // rax
  UFG::SensorPhantom *v12; // rax
  hkAabb aabb; // [rsp+40h] [rbp-48h]

  v1 = this;
  *(_QWORD *)&this->mInsideDynamicRadiusCount = 0i64;
  this->mMaxHeatLevel = -1;
  this->mStartTimestamp = 0i64;
  *(_QWORD *)&this->mVehicleSpawnIteratingIndex = 0i64;
  this->mNumWaveGroupTypes = 0;
  v2 = this->mWaveGroupInstancesRequired;
  v3 = 10i64;
  do
  {
    *(v2 - 10) = 0;
    *v2 = 0;
    v2[10] = 0;
    ++v2;
    --v3;
  }
  while ( v3 );
  v4 = UFG::qVector3::msZero.y;
  v5 = UFG::qVector3::msZero.z;
  v1->mFocusTargetPosition.x = UFG::qVector3::msZero.x;
  v1->mFocusTargetPosition.y = v4;
  v1->mFocusTargetPosition.z = v5;
  *(_QWORD *)&v1->mWaveCount = 0i64;
  *(_QWORD *)&v1->mReducedRadiusPercentage = 1065353216i64;
  *(_QWORD *)&v1->mWaveTimer = 0i64;
  *(_QWORD *)&v1->mSpawnTimeout = 0i64;
  *(_WORD *)&v1->mIsStaysOffSidewalk = 0;
  v1->mIsCanTurnAround = 0;
  *(_DWORD *)&v1->mIsReplenishing = 0x1000000;
  v1->mEnableWaveTimerChangesByDisabledUnits = 0;
  v1->mFocusTargetContext.mpSimObject = 0i64;
  v1->mFocusTargetContext.mpVehicle = 0i64;
  v1->mFocusTargetContext.mWaterContextTimer = 0.0;
  *(_DWORD *)&v1->mFocusTargetContext.mIsOnFootRaw = 16777217;
  *(_WORD *)&v1->mFocusTargetContext.mIsOnMeshHeuristic = 1;
  v1->mFocusTargetContext.mOpenFiredWithHostage = 0;
  *(_QWORD *)&v1->mVehicleSpawnCount = 0i64;
  *(_QWORD *)&v1->mVehicleKillCount = 0i64;
  UFG::PropertySetHandle::Bind(&v1->mProperties);
  v6 = v1->mProperties.mpPropSet;
  v7 = UFG::qPropertySet::Get<UFG::qSymbol>(
         v1->mProperties.mpPropSet,
         (UFG::qSymbol *)&EncounterSym_replenish_style.mUID,
         DEPTH_RECURSE);
  if ( v7 )
    v1->mReplenishStyle = v7->mUID == EncounterSym_by_wave_type.mUID;
  else
    v1->mReplenishStyle = 0;
  ((void (__fastcall *)(UFG::EncounterBase *))v1->vfptr[50].__vecDelDtor)(v1);
  v8 = (__m128)*(unsigned int *)UFG::qPropertySet::Get<float>(
                                  v6,
                                  (UFG::qSymbol *)&EncounterSym_vehicle_spawn_sensor_extent_x.mUID,
                                  DEPTH_RECURSE);
  v9 = (__m128)*(unsigned int *)UFG::qPropertySet::Get<float>(
                                  v6,
                                  (UFG::qSymbol *)&EncounterSym_vehicle_spawn_sensor_extent_y.mUID,
                                  DEPTH_RECURSE);
  v10 = (__m128)*(unsigned int *)UFG::qPropertySet::Get<float>(
                                   v6,
                                   (UFG::qSymbol *)&EncounterSym_vehicle_spawn_sensor_extent_z.mUID,
                                   DEPTH_RECURSE);
  aabb.m_min.m_quad = _mm_unpacklo_ps(
                        _mm_unpacklo_ps(
                          _mm_xor_ps(v8, (__m128)(unsigned int)_xmm[0]),
                          _mm_xor_ps(v10, (__m128)(unsigned int)_xmm[0])),
                        _mm_unpacklo_ps(_mm_xor_ps(v9, (__m128)(unsigned int)_xmm[0]), (__m128)0i64));
  aabb.m_max.m_quad = _mm_unpacklo_ps(_mm_unpacklo_ps(v8, v10), _mm_unpacklo_ps(v9, (__m128)0i64));
  v11 = UFG::qMemoryPool::Allocate(&gPhysicsMemoryPool, 0x18ui64, "SensorPhantom", 0i64, 1u);
  if ( v11 )
  {
    UFG::SensorPhantom::SensorPhantom((UFG::SensorPhantom *)v11, &aabb, 0x18u, "VehicleSpawnSensor");
    v1->mpVehicleSpawnSensor = v12;
  }
  else
  {
    v1->mpVehicleSpawnSensor = 0i64;
  }
}

// File Line: 395
// RVA: 0x3F9820
void __fastcall UFG::EncounterBase::Shutdown(UFG::EncounterBase *this)
{
  UFG::EncounterBase *v1; // rbx
  UFG::SensorPhantom *v2; // rcx
  signed int v3; // edi
  UFG::qPropertySet **v4; // rsi
  UFG::qSymbol *v5; // rbp

  v1 = this;
  v2 = this->mpVehicleSpawnSensor;
  if ( v2 )
  {
    v2->vfptr->__vecDelDtor(v2, 1u);
    v1->mpVehicleSpawnSensor = 0i64;
  }
  UFG::PropertySetHandle::Null(&v1->mProperties);
  v3 = 0;
  v4 = v1->mWaterHeatLevelProperties;
  v5 = v1->mWaterHeatLevelPropertiesName;
  do
  {
    v1->vfptr[46].__vecDelDtor((UFG::qSafePointerNode<UFG::EncounterBase> *)&v1->vfptr, v3);
    UFG::qSymbol::set_null(v5 - 6);
    UFG::qSymbol::set_null(v5);
    ++v3;
    ++v5;
    *(v4 - 6) = 0i64;
    *v4 = 0i64;
    ++v4;
  }
  while ( v3 < 6 );
}

// File Line: 416
// RVA: 0x3F8F60
void __fastcall UFG::EncounterBase::RemoveAllUnitsOnScene(UFG::EncounterBase *this, bool includeNonManaged)
{
  UFG::EncounterBase *v2; // rbx
  unsigned int v3; // edi
  UFG::SimObject *v4; // rsi
  UFG::SimObjectCharacter *v5; // rax
  unsigned __int16 v6; // dx
  UFG::VehicleOwnershipComponent *v7; // rax
  UFG::SimObject *v8; // rbp
  unsigned int i; // edi
  UFG::SimObject *v10; // rsi

  v2 = this;
  v3 = 0;
  if ( this->mHumans.size )
  {
    do
    {
      v4 = v2->mHumans.p[v3]->m_pSimObject;
      if ( v4 )
      {
        UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&v4->m_Name);
        UFG::qPrintChannel::Print(
          &UFG::gPrintChannel_HK_Encounters,
          OUTPUT_LEVEL_DEBUG,
          "[Encounters]:   Deleting (%s)\n");
        UFG::Simulation::QueueSimObjectToBeDestroyed(&UFG::gSim, v4);
      }
      ++v3;
    }
    while ( v3 < v2->mHumans.size );
  }
  v2->mHumans.size = 0;
  v5 = UFG::GetLocalPlayer();
  if ( v5
    && ((v6 = v5->m_Flags, !((v6 >> 14) & 1)) ? ((v6 & 0x8000u) == 0 ? (!((v6 >> 13) & 1) ? (!((v6 >> 12) & 1) ? (v7 = (UFG::VehicleOwnershipComponent *)UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v5->vfptr, UFG::VehicleOwnershipComponent::_TypeUID)) : (v7 = (UFG::VehicleOwnershipComponent *)UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&v5->vfptr, UFG::VehicleOwnershipComponent::_TypeUID))) : (v7 = (UFG::VehicleOwnershipComponent *)UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&v5->vfptr, UFG::VehicleOwnershipComponent::_TypeUID))) : (v7 = (UFG::VehicleOwnershipComponent *)UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&v5->vfptr, UFG::VehicleOwnershipComponent::_TypeUID))) : (v7 = (UFG::VehicleOwnershipComponent *)UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&v5->vfptr, UFG::VehicleOwnershipComponent::_TypeUID)),
        v7) )
  {
    v8 = UFG::VehicleOwnershipComponent::GetOwnedVehicle(v7);
  }
  else
  {
    v8 = 0i64;
  }
  for ( i = 0; i < v2->mVehicles.size; ++i )
  {
    v10 = v2->mVehicles.p[i]->m_pSimObject;
    if ( v10 )
    {
      UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&v10->m_Name);
      if ( v10 == v8 )
      {
        UFG::qPrintChannel::Print(
          &UFG::gPrintChannel_HK_Encounters,
          OUTPUT_LEVEL_DEBUG,
          "[Encounters]:   IGNORING (%s), because player vehicle!\n");
      }
      else
      {
        UFG::qPrintChannel::Print(
          &UFG::gPrintChannel_HK_Encounters,
          OUTPUT_LEVEL_DEBUG,
          "[Encounters]:   Deleting (%s)\n");
        UFG::Simulation::QueueSimObjectToBeDestroyed(&UFG::gSim, v10);
      }
    }
  }
  v2->mHumanSpawnRegions.size = 0;
  v2->mVehicles.size = 0;
}

// File Line: 457
// RVA: 0x3F8790
bool __fastcall UFG::EncounterBase::IsInvalidReacquirePosition(UFG::EncounterBase *this, UFG::qVector3 *position)
{
  UFG::EncounterBase *v2; // rdi
  UFG::qVector3 *v3; // rsi
  float *v4; // rax

  v2 = this;
  v3 = position;
  UFG::PropertySetHandle::Bind(&this->mProperties);
  v4 = UFG::qPropertySet::Get<float>(
         v2->mProperties.mpPropSet,
         (UFG::qSymbol *)&EncounterSym_invalid_reacquire_distance.mUID,
         DEPTH_RECURSE);
  return (float)((float)((float)(v3->y - v2->mFocusTargetPosition.y) * (float)(v3->y - v2->mFocusTargetPosition.y))
               + (float)((float)(v3->x - v2->mFocusTargetPosition.x) * (float)(v3->x - v2->mFocusTargetPosition.x))) > (float)(*v4 * *v4);
}

// File Line: 473
// RVA: 0x3F8710
bool __fastcall UFG::EncounterBase::IsInvalidOnFootPosition(UFG::EncounterBase *this, UFG::qVector3 *position)
{
  UFG::EncounterBase *v2; // rdi
  UFG::qVector3 *v3; // rsi
  float *v4; // rax

  v2 = this;
  v3 = position;
  UFG::PropertySetHandle::Bind(&this->mProperties);
  v4 = UFG::qPropertySet::Get<float>(
         v2->mProperties.mpPropSet,
         (UFG::qSymbol *)&EncounterSym_invalid_onfoot_distance.mUID,
         DEPTH_RECURSE);
  return (float)((float)((float)(v3->y - v2->mFocusTargetPosition.y) * (float)(v3->y - v2->mFocusTargetPosition.y))
               + (float)((float)(v3->x - v2->mFocusTargetPosition.x) * (float)(v3->x - v2->mFocusTargetPosition.x))) > (float)(*v4 * *v4);
}

// File Line: 489
// RVA: 0x3F8810
bool __fastcall UFG::EncounterBase::IsInvalidVehiclePosition(UFG::EncounterBase *this, UFG::qVector3 *position)
{
  UFG::EncounterBase *v2; // rsi
  UFG::qStaticSymbol *v3; // rdi
  UFG::qVector3 *v4; // rbp
  float *v5; // rax
  float v6; // xmm1_4

  v2 = this;
  v3 = &EncounterSym_invalid_vehicle_distance;
  v4 = position;
  if ( this->mFocusTargetContext.mIsInWater )
    v3 = &EncounterSym_invalid_water_vehicle_distance;
  UFG::PropertySetHandle::Bind(&this->mProperties);
  v5 = UFG::qPropertySet::Get<float>(v2->mProperties.mpPropSet, (UFG::qSymbol *)&v3->mUID, DEPTH_RECURSE);
  v6 = v4->y - v2->mFocusTargetPosition.y;
  return (float)((float)(v6 * v6)
               + (float)((float)(v4->x - v2->mFocusTargetPosition.x) * (float)(v4->x - v2->mFocusTargetPosition.x))) > (float)(*v5 * *v5);
}

// File Line: 507
// RVA: 0x3F88B0
bool __fastcall UFG::EncounterBase::IsOnFootMode(UFG::EncounterBase *this)
{
  return this->mFocusTargetContext.mIsOnFootHeuristic
      || !this->mNumDesiredVehicleGroups && this->mNumDesiredCharacterGroups > 0;
}

// File Line: 513
// RVA: 0x3FA120
void __fastcall UFG::EncounterBase::UpdateDesiredPopulation(UFG::EncounterBase *this)
{
  UFG::EncounterBase *v1; // rbx
  UFG::qPropertySet *v2; // rax
  UFG::qPropertySet *v3; // rdi
  int v4; // er15
  int v5; // er12
  UFG::qPropertyList *v6; // rax
  signed int v7; // edx
  unsigned int v8; // esi
  char *v9; // rax
  UFG::qPropertySet *v10; // rdi
  signed __int64 v11; // r14
  UFG::qSymbol *v12; // r13
  unsigned int *v13; // rax
  signed int v14; // ecx
  UFG::EncounterBase::ReplenishStyle v15; // ecx
  UFG::qSymbol *v16; // [rsp+60h] [rbp+8h]
  UFG::qPropertyList *v17; // [rsp+68h] [rbp+10h]
  UFG::qPropertySet *v18; // [rsp+70h] [rbp+18h]

  v1 = this;
  v2 = (UFG::qPropertySet *)((__int64 (*)(void))this->vfptr[33].__vecDelDtor)();
  v3 = v2;
  v18 = v2;
  if ( v2 )
  {
    v4 = 0;
    v5 = 0;
    v6 = UFG::qPropertySet::Get<UFG::qPropertyList>(v2, (UFG::qSymbol *)&EncounterSym_spawn_groups.mUID, DEPTH_RECURSE);
    v7 = 10;
    v8 = 0;
    v17 = v6;
    if ( v6->mNumElements < 0xA )
      v7 = v6->mNumElements;
    v1->mNumWaveGroupTypes = v7;
    if ( v7 )
    {
      do
      {
        v9 = UFG::qPropertyList::GetValuePtr(v6, 0x1Au, v8);
        if ( !v9 || (v10 = (UFG::qPropertySet *)&v9[*(_QWORD *)v9], !*(_QWORD *)v9) )
          v10 = 0i64;
        v11 = (signed __int64)v1 + 4 * v8;
        *(_DWORD *)(v11 + 864) = 0;
        v12 = UFG::qPropertySet::Get<UFG::qSymbol>(v10, (UFG::qSymbol *)&EncounterSym_boat.mUID, DEPTH_RECURSE);
        v16 = UFG::qPropertySet::Get<UFG::qSymbol>(v10, (UFG::qSymbol *)&EncounterSym_vehicle.mUID, DEPTH_RECURSE);
        v13 = UFG::qPropertySet::Get<unsigned long>(
                v10,
                (UFG::qSymbol *)&EncounterSym_num_instances.mUID,
                DEPTH_RECURSE);
        if ( v13 )
          v14 = *v13;
        else
          v14 = 1;
        v1->mWaveGroupInstancesRequired[v8] = v14;
        if ( v12 || v16 )
        {
          *(_DWORD *)(v11 + 864) = 2;
          v4 += v14;
        }
        else
        {
          *(_DWORD *)(v11 + 864) = 1;
          v5 += v14;
        }
        v6 = v17;
        ++v8;
      }
      while ( v8 < v1->mNumWaveGroupTypes );
      v3 = v18;
    }
    v15 = v1->mReplenishStyle;
    if ( v15 )
    {
      if ( v15 == 1 )
      {
        v1->mNumDesiredVehicleGroups = v4;
        v1->mNumDesiredCharacterGroups = v5;
      }
    }
    else
    {
      v1->mNumDesiredVehicleGroups = *UFG::qPropertySet::Get<unsigned long>(
                                        v3,
                                        (UFG::qSymbol *)&EncounterSym_vehicle_population.mUID,
                                        DEPTH_RECURSE);
      v1->mNumDesiredCharacterGroups = *UFG::qPropertySet::Get<unsigned long>(
                                          v3,
                                          (UFG::qSymbol *)&EncounterSym_onfoot_population.mUID,
                                          DEPTH_RECURSE);
    }
  }
  if ( v1->mHeatLevel == HEATLEVEL_NONE )
  {
    *(_QWORD *)&v1->mVehicleSpawnCount = 0i64;
    *(_QWORD *)&v1->mVehicleKillCount = 0i64;
  }
}

// File Line: 593
// RVA: 0x3F6110
void __fastcall UFG::EncounterBase::HandleHeatLevelChange(UFG::EncounterBase *this)
{
  UFG::EncounterBase *v1; // rdi
  UFG::qPropertySet *v2; // rax
  signed int v3; // ebp
  UFG::qPropertySet *v4; // rbx
  UFG::eAIObjective v5; // er15
  bool v6; // cl
  unsigned int v7; // er14
  UFG::SimObject *i; // r12
  UFG::SimObjectGame *v9; // rbx
  unsigned __int16 v10; // cx
  UFG::ActiveAIEntityComponent *v11; // rax
  bool v12; // zf
  UFG::SimObjectGame *v13; // rcx
  unsigned __int16 v14; // cx
  UFG::ActiveAIEntityComponent *v15; // rsi
  UFG::TargetingSystemBaseComponent *v16; // rbx
  UFG::SimComponent *v17; // rax
  signed int v18; // ebx

  v1 = this;
  v2 = (UFG::qPropertySet *)((__int64 (*)(void))this->vfptr[33].__vecDelDtor)();
  v3 = 0;
  v4 = v2;
  if ( v2 )
  {
    v1->mIsAvoidPeds = *UFG::qPropertySet::Get<bool>(
                          v2,
                          (UFG::qSymbol *)&EncounterSym_vehicle_avoid_peds.mUID,
                          DEPTH_RECURSE);
    v1->mIsAllowedToPass = *UFG::qPropertySet::Get<bool>(
                              v4,
                              (UFG::qSymbol *)&EncounterSym_vehicle_allowed_to_pass.mUID,
                              DEPTH_RECURSE);
    v1->mIsStaysOffSidewalk = *UFG::qPropertySet::Get<bool>(
                                 v4,
                                 (UFG::qSymbol *)&EncounterSym_vehicle_stays_off_sidewalk.mUID,
                                 DEPTH_RECURSE);
    v1->mIsRespectSpeedLimit = *UFG::qPropertySet::Get<bool>(
                                  v4,
                                  (UFG::qSymbol *)&EncounterSym_vehicle_respect_speed_limit.mUID,
                                  DEPTH_RECURSE);
    v5 = 0;
    v6 = *UFG::qPropertySet::Get<bool>(v4, (UFG::qSymbol *)&EncounterSym_vehicle_can_turn_around.mUID, DEPTH_RECURSE);
    if ( v1->mPostObjective < 36 )
      v5 = v1->mPostObjective;
    v1->mIsCanTurnAround = v6;
    if ( v1->mHeatLevel > 0 )
      v5 = v1->mObjective;
    v7 = 0;
    for ( i = (UFG::SimObject *)((__int64 (__fastcall *)(UFG::EncounterBase *))v1->vfptr[18].__vecDelDtor)(v1);
          v7 < v1->mHumans.size;
          ++v7 )
    {
      v9 = (UFG::SimObjectGame *)v1->mHumans.p[v7]->m_pSimObject;
      if ( v9 )
      {
        v10 = v9->m_Flags;
        if ( (v10 >> 14) & 1 )
        {
          v11 = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>((UFG::SimObjectCVBase *)v1->mHumans.p[v7]->m_pSimObject);
        }
        else if ( (v10 & 0x8000u) == 0 )
        {
          if ( (v10 >> 13) & 1 )
          {
            v11 = (UFG::ActiveAIEntityComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                    (UFG::SimObjectGame *)v1->mHumans.p[v7]->m_pSimObject,
                                                    UFG::ActiveAIEntityComponent::_TypeUID);
          }
          else
          {
            v12 = ((v10 >> 12) & 1) == 0;
            v13 = (UFG::SimObjectGame *)v1->mHumans.p[v7]->m_pSimObject;
            v11 = (UFG::ActiveAIEntityComponent *)(v12 ? UFG::SimObject::GetComponentOfType(
                                                           (UFG::SimObject *)&v13->vfptr,
                                                           UFG::ActiveAIEntityComponent::_TypeUID) : UFG::SimObjectGame::GetComponentOfTypeHK(v13, UFG::ActiveAIEntityComponent::_TypeUID));
          }
        }
        else
        {
          v11 = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>((UFG::SimObjectCVBase *)v1->mHumans.p[v7]->m_pSimObject);
        }
        v14 = v9->m_Flags;
        v15 = v11;
        if ( (v14 >> 14) & 1 )
        {
          v16 = (UFG::TargetingSystemBaseComponent *)v9->m_Components.p[20].m_pComponent;
        }
        else if ( (v14 & 0x8000u) == 0 )
        {
          if ( (v14 >> 13) & 1 )
            v17 = UFG::SimObjectGame::GetComponentOfTypeHK(v9, UFG::TargetingSystemBaseComponent::_TypeUID);
          else
            v17 = (v14 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                      v9,
                                      UFG::TargetingSystemBaseComponent::_TypeUID) : UFG::SimObject::GetComponentOfType(
                                                                                       (UFG::SimObject *)&v9->vfptr,
                                                                                       UFG::TargetingSystemBaseComponent::_TypeUID);
          v16 = (UFG::TargetingSystemBaseComponent *)v17;
        }
        else
        {
          v16 = (UFG::TargetingSystemBaseComponent *)v9->m_Components.p[20].m_pComponent;
        }
        if ( v15 && v16 )
        {
          UFG::ActiveAIEntityComponent::SetCurrentObjective(v15, v5, "EncounterBase::HandleHeatLevelChange");
          UFG::TargetingSystemBaseComponent::SetTarget(v16, eTARGET_TYPE_AI_OBJECTIVE, i);
        }
      }
    }
  }
  ((void (__fastcall *)(UFG::EncounterBase *))v1->vfptr[49].__vecDelDtor)(v1);
  v18 = 0;
  do
  {
    if ( v18 == v1->mHeatLevel )
      v1->vfptr[45].__vecDelDtor((UFG::qSafePointerNode<UFG::EncounterBase> *)&v1->vfptr, v18);
    ++v18;
  }
  while ( v18 < 6 );
  do
  {
    if ( v3 != v1->mHeatLevel )
      v1->vfptr[46].__vecDelDtor((UFG::qSafePointerNode<UFG::EncounterBase> *)&v1->vfptr, v3);
    ++v3;
  }
  while ( v3 < 6 );
}

// File Line: 647
// RVA: 0x3F6F50
void __fastcall UFG::EncounterBase::HandlePreloadResources(UFG::EncounterBase *this, int level)
{
  __int64 v2; // rax
  char *v3; // rdx
  UFG::qPropertySet *v4; // rcx
  UFG::qPropertyList *v5; // rax
  unsigned int v6; // ebx
  unsigned int v7; // esi
  UFG::qPropertyList *v8; // rbp
  UFG::qSymbol *v9; // rax
  UFG::qPropertySet *v10; // rdi
  UFG::ObjectResourceManager *v11; // rax

  v2 = level;
  v3 = (char *)this + level;
  if ( !v3[224] )
  {
    v4 = this->mHeatLevelProperties[v2];
    if ( v4 )
    {
      v3[224] = 1;
      v5 = UFG::qPropertySet::Get<UFG::qPropertyList>(
             v4,
             (UFG::qSymbol *)&EncounterSym_persistent_resources.mUID,
             DEPTH_RECURSE);
      v6 = 0;
      v7 = v5->mNumElements;
      v8 = v5;
      if ( v7 )
      {
        do
        {
          v9 = UFG::qPropertyList::Get<UFG::qSymbol>(v8, v6);
          if ( v9 )
          {
            v10 = UFG::PropertySetManager::GetPropertySet(v9);
            v11 = UFG::ObjectResourceManager::Instance();
            UFG::ObjectResourceManager::PreLoadCriticalResource(v11, v10);
          }
          ++v6;
        }
        while ( v6 < v7 );
      }
    }
  }
}

// File Line: 675
// RVA: 0x3F7000
void __fastcall UFG::EncounterBase::HandleUnloadResources(UFG::EncounterBase *this, int level)
{
  __int64 v2; // rax
  char *v3; // rdx
  UFG::qPropertySet *v4; // rcx
  UFG::qPropertyList *v5; // rax
  UFG::qPropertyList *v6; // rbp
  unsigned int v7; // esi
  unsigned int v8; // ebx
  UFG::qSymbol *v9; // rax
  UFG::qPropertySet *v10; // rdi
  UFG::ObjectResourceManager *v11; // rax

  v2 = level;
  v3 = (char *)this + level;
  if ( v3[224] )
  {
    v4 = this->mHeatLevelProperties[v2];
    v3[224] = 0;
    if ( v4 )
    {
      v5 = UFG::qPropertySet::Get<UFG::qPropertyList>(
             v4,
             (UFG::qSymbol *)&EncounterSym_persistent_resources.mUID,
             DEPTH_RECURSE);
      v6 = v5;
      if ( v5 )
      {
        v7 = v5->mNumElements;
        v8 = 0;
        if ( v7 )
        {
          do
          {
            v9 = UFG::qPropertyList::Get<UFG::qSymbol>(v6, v8);
            if ( v9 )
            {
              v10 = UFG::PropertySetManager::GetPropertySet(v9);
              v11 = UFG::ObjectResourceManager::Instance();
              UFG::ObjectResourceManager::ReleaseCriticalResource(v11, v10);
            }
            ++v8;
          }
          while ( v8 < v7 );
        }
      }
    }
  }
}

// File Line: 709
// RVA: 0x3FB4E0
void __fastcall UFG::EncounterBase::UpdateVehicleFlags(UFG::EncounterBase *this, UFG::SimObject *pSimObject)
{
  UFG::SimObjectCVBase *v2; // rbx
  unsigned __int16 v3; // dx
  UFG::EncounterBase *v4; // rsi
  UFG::AiDriverComponent *v5; // rax
  UFG::AiDriverComponent *v6; // rdi
  unsigned __int16 v7; // cx
  UFG::SimComponent *v8; // rbx
  UFG::SimComponent *v9; // rax
  char v10; // cl

  if ( pSimObject )
  {
    v2 = (UFG::SimObjectCVBase *)pSimObject;
    v3 = pSimObject->m_Flags;
    v4 = this;
    if ( (v3 >> 14) & 1 )
    {
      v5 = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(v2);
    }
    else if ( (v3 & 0x8000u) == 0 )
    {
      if ( (v3 >> 13) & 1 )
      {
        v5 = (UFG::AiDriverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                         (UFG::SimObjectGame *)&v2->vfptr,
                                         UFG::AiDriverComponent::_TypeUID);
      }
      else if ( (v3 >> 12) & 1 )
      {
        v5 = (UFG::AiDriverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                         (UFG::SimObjectGame *)&v2->vfptr,
                                         UFG::AiDriverComponent::_TypeUID);
      }
      else
      {
        v5 = (UFG::AiDriverComponent *)UFG::SimObject::GetComponentOfType(
                                         (UFG::SimObject *)&v2->vfptr,
                                         UFG::AiDriverComponent::_TypeUID);
      }
    }
    else
    {
      v5 = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(v2);
    }
    v6 = v5;
    if ( v5 )
    {
      UFG::AiDriverComponent::SetAvoidPeds(v5, v4->mIsAvoidPeds);
      UFG::AiDriverComponent::SetAllowedToPass(v6, v4->mIsAllowedToPass);
      UFG::AiDriverComponent::SetStayOffSidewalk(v6, v4->mIsStaysOffSidewalk);
      UFG::AiDriverComponent::SetRespectSpeedLimit(v6, v4->mIsRespectSpeedLimit);
      UFG::AiDriverComponent::SetCanTurnAround(v6, v4->mIsCanTurnAround);
    }
    v7 = v2->m_Flags;
    if ( (v7 >> 14) & 1 )
    {
      v8 = v2->m_Components.p[24].m_pComponent;
    }
    else if ( (v7 & 0x8000u) == 0 )
    {
      if ( (v7 >> 13) & 1 )
      {
        v9 = UFG::SimObjectGame::GetComponentOfTypeHK(
               (UFG::SimObjectGame *)&v2->vfptr,
               UFG::RoadSpaceComponent::_TypeUID);
      }
      else if ( (v7 >> 12) & 1 )
      {
        v9 = UFG::SimObjectGame::GetComponentOfTypeHK(
               (UFG::SimObjectGame *)&v2->vfptr,
               UFG::RoadSpaceComponent::_TypeUID);
      }
      else
      {
        v9 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v2->vfptr, UFG::RoadSpaceComponent::_TypeUID);
      }
      v8 = v9;
    }
    else
    {
      v8 = v2->m_Components.p[24].m_pComponent;
    }
    if ( v8 )
    {
      UFG::RoadSpaceComponent::SetLaneFlags((UFG::RoadSpaceComponent *)v8, 1u);
      v10 = 0;
      if ( v4->mHeatLevel )
        v10 = 1;
      v8[30].m_TypeUID &= 0xFFFFFFFD;
      v8[30].m_TypeUID |= 2 * (v10 != 0);
    }
  }
}

// File Line: 736
// RVA: 0x3F3DC0
bool __fastcall UFG::EncounterBase::FindGoodSpawnLocationCharacter(UFG::EncounterBase *this, UFG::qPropertySet *pProperties, UFG::TransformNodeComponent *pTargetTransform, UFG::qVector3 *pResult)
{
  UFG::EncounterBase *v4; // rsi
  int v5; // ecx
  UFG::qVector3 *v6; // r15
  UFG::qPropertySet *v7; // rbx
  int v8; // eax
  bool v9; // al
  UFG::qPropertySet *v10; // rbx
  __int128 v11; // xmm6
  float *v12; // rax
  float v13; // xmm6_4
  UFG::qNode<UFG::AIMarker,UFG::AIMarker> *v14; // rdi
  UFG::qNode<UFG::AIMarker,UFG::AIMarker> *v15; // rbp
  UFG::qNode<UFG::AIMarker,UFG::AIMarker> *v16; // rbx
  float *v17; // rbx
  __m128 v18; // xmm2
  float v19; // xmm1_4
  float v20; // xmm1_4
  float *v21; // rbx
  float v22; // xmm0_4
  float v23; // xmm1_4
  UFG::qVector3 result; // [rsp+30h] [rbp-38h]

  v4 = this;
  v5 = this->mHumanSpawnRegions.size;
  v6 = pResult;
  v7 = pProperties;
  if ( v5 )
  {
    v8 = UFG::qRandom(v5, &UFG::qDefaultSeed);
    UFG::RegionComponent::GetRandomPosition(v4->mHumanSpawnRegions.p[v8], &result);
    v9 = UFG::SimObjectUtility::PlaceOnGround(v6, &result, 0.050000001, 5.0)
      && (!*UFG::qPropertySet::Get<bool>(v7, (UFG::qSymbol *)&EncounterSym_offscreen_spawn_only.mUID, DEPTH_RECURSE)
       || !UFG::SimObjectUtility::IsPositionOnScreen(&result, 2.0, 0));
  }
  else
  {
    UFG::PropertySetHandle::Bind(&v4->mProperties);
    v10 = v4->mProperties.mpPropSet;
    v11 = *(unsigned int *)UFG::qPropertySet::Get<float>(
                             v4->mProperties.mpPropSet,
                             (UFG::qSymbol *)&EncounterSym_character_generic_spawn_min_radius.mUID,
                             DEPTH_RECURSE);
    v12 = UFG::qPropertySet::Get<float>(
            v10,
            (UFG::qSymbol *)&EncounterSym_character_generic_spawn_max_radius.mUID,
            DEPTH_RECURSE);
    if ( (unsigned __int8)UFG::SimObjectUtility::FindSpawnCharacterPosition(
                            &v4->mFocusTargetPosition,
                            *(float *)&v11,
                            *v12,
                            1) )
    {
      v9 = 1;
    }
    else if ( v4->mFocusTargetContext.mIsInsideInterior )
    {
      v13 = FLOAT_N1_0;
      v14 = UFG::AIMarker::s_AIReinforcementPointList.mNode.mNext - 7;
      v15 = 0i64;
      if ( (UFG::qList<UFG::AIMarker,UFG::AIMarker,1,0> *)&UFG::AIMarker::s_AIReinforcementPointList.mNode.mNext[-7] == &UFG::AIMarker::s_AIReinforcementPointList - 7 )
        goto LABEL_24;
      do
      {
        v16 = v14[6].mNext;
        if ( v16 )
        {
          UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v14[6].mNext);
          if ( !(unsigned __int8)v4->vfptr[59].__vecDelDtor(
                                   (UFG::qSafePointerNode<UFG::EncounterBase> *)&v4->vfptr,
                                   (unsigned int)&v16[11]) )
          {
            v17 = (float *)v14[6].mNext;
            UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v14[6].mNext);
            v18 = (__m128)LODWORD(v4->mFocusTargetPosition.y);
            v19 = v4->mFocusTargetPosition.x - v17[44];
            v18.m128_f32[0] = (float)((float)((float)(v18.m128_f32[0] - v17[45]) * (float)(v18.m128_f32[0] - v17[45]))
                                    + (float)(v19 * v19))
                            + (float)((float)(v4->mFocusTargetPosition.z - v17[46])
                                    * (float)(v4->mFocusTargetPosition.z - v17[46]));
            LODWORD(v20) = (unsigned __int128)_mm_sqrt_ps(v18);
            if ( !v15 || v20 < v13 )
            {
              v15 = v14;
              v13 = v20;
            }
          }
        }
        v14 = v14[7].mNext - 7;
      }
      while ( v14 != (UFG::qNode<UFG::AIMarker,UFG::AIMarker> *)(&UFG::AIMarker::s_AIReinforcementPointList - 7) );
      if ( v15 && (v21 = (float *)v15[6].mNext) != 0i64 )
      {
        UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v15[6].mNext);
        v22 = v21[45];
        v23 = v21[46];
        v6->x = v21[44];
        v9 = 1;
        v6->y = v22;
        v6->z = v23;
      }
      else
      {
LABEL_24:
        v9 = 0;
      }
    }
    else
    {
      v9 = 0;
    }
  }
  return v9;
}

// File Line: 808
// RVA: 0x3F5FC0
__int64 __fastcall UFG::EncounterBase::GetDesiredVehiclePopulation(UFG::EncounterBase *this, UFG::qPropertySet *heatPropSet)
{
  __int64 result; // rax
  int v3; // ecx

  result = 0i64;
  if ( this->mEnable && !this->mFocusTargetContext.mIsInsideInterior )
  {
    if ( this->mSuppressVehicleSpawningByKillCount )
    {
      v3 = this->mNumDesiredVehicleGroups - this->mVehicleKillCount;
      if ( v3 > 0 )
        result = (unsigned int)v3;
    }
    else
    {
      result = (unsigned int)this->mNumDesiredVehicleGroups;
    }
  }
  return result;
}

// File Line: 825
// RVA: 0x3F5FB0
__int64 __fastcall UFG::EncounterBase::GetDesiredOnFootPopulation(UFG::EncounterBase *this, UFG::qPropertySet *heatPropSet)
{
  __int64 result; // rax

  if ( this->mEnable )
    result = (unsigned int)this->mNumDesiredCharacterGroups;
  else
    result = 0i64;
  return result;
}

// File Line: 835
// RVA: 0x3F4150
void __fastcall UFG::EncounterBase::Forget(UFG::EncounterBase *this, UFG::EncounterUnitComponent *pEncounterUnitComponent)
{
  UFG::SimObject *v2; // rdi
  UFG::EncounterUnitComponent *v3; // r15
  UFG::EncounterBase *v4; // r14
  UFG::SimObjectGame *v5; // r8
  unsigned __int16 v6; // cx
  UFG::SimComponent *v7; // rax
  bool v8; // zf
  UFG::qPropertySet *v9; // rax
  float *v10; // rax
  float v11; // xmm0_4
  unsigned __int16 v12; // cx
  UFG::SimComponent *v13; // rax
  UFG::VehicleOccupantComponent *v14; // rsi
  unsigned int v15; // ebx
  unsigned int v16; // ebp
  UFG::SimObjectGame *v17; // rax
  unsigned __int16 v18; // dx
  UFG::SimComponent *v19; // rax
  unsigned __int16 v20; // cx
  UFG::SimComponent *v21; // rbx
  UFG::SimComponent *v22; // rax
  UFG::SimObjectGame *v23; // rax
  unsigned __int16 v24; // dx
  UFG::SimComponent *v25; // rax
  unsigned __int16 v26; // cx
  UFG::StreamedResourceComponent *v27; // rbx
  UFG::SimComponent *v28; // rax
  unsigned __int16 v29; // cx
  UFG::SimComponent *v30; // rax
  unsigned __int16 v31; // cx
  UFG::AiDriverComponent *v32; // rax
  UFG::AiDriverComponent *v33; // rbx
  unsigned __int16 v34; // cx
  UFG::ActiveAIEntityComponent *v35; // rax
  UFG::ActiveAIEntityComponent *v36; // rbx
  UFG::eAIObjective v37; // edx
  unsigned __int16 v38; // cx
  UFG::SimComponent *v39; // rsi
  UFG::SimComponent *v40; // rax
  unsigned __int8 v41; // cl
  signed __int64 v42; // rbx
  UFG::PedSpawnManager *v43; // rax
  UFG::SimObjectCharacter *v44; // rax
  unsigned __int16 v45; // dx
  UFG::SimComponent *v46; // rax
  UFG::VehicleOccupantComponent *v47; // rsi
  unsigned int v48; // edi
  UFG::SimObjectGame *v49; // rax
  UFG::SimObjectGame *v50; // r8
  unsigned __int16 v51; // dx
  UFG::SimComponent *v52; // rbx
  UFG::SimObjectGame *v53; // rcx
  unsigned __int16 v54; // dx
  UFG::SimComponent *v55; // rax
  UFG::qSymbol symbol; // [rsp+48h] [rbp+10h]

  v2 = pEncounterUnitComponent->m_pSimObject;
  v3 = pEncounterUnitComponent;
  v4 = this;
  if ( !v2 )
  {
LABEL_160:
    v53 = (UFG::SimObjectGame *)v3->m_pSimObject;
    if ( v53 )
    {
      v54 = v53->m_Flags;
      if ( (v54 >> 14) & 1 )
      {
        v55 = v53->m_Components.p[17].m_pComponent;
      }
      else if ( (v54 & 0x8000u) == 0 )
      {
        if ( (v54 >> 13) & 1 )
        {
          v55 = UFG::SimObjectGame::GetComponentOfTypeHK(v53, UFG::CopUnitComponent::_TypeUID);
        }
        else if ( (v54 >> 12) & 1 )
        {
          v55 = UFG::SimObjectGame::GetComponentOfTypeHK(v53, UFG::CopUnitComponent::_TypeUID);
        }
        else
        {
          v55 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v53->vfptr, UFG::CopUnitComponent::_TypeUID);
        }
      }
      else
      {
        v55 = v53->m_Components.p[17].m_pComponent;
      }
      if ( v55 )
      {
        LOBYTE(v55[7].m_Flags) &= 0xFEu;
        LOBYTE(v55[7].m_Flags) |= 4u;
        v3->mAcquiredTimer = 0.0;
      }
    }
    UFG::EncounterUnitComponent::ReleaseByEncounter(v3);
    return;
  }
  UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&v2->m_Name);
  UFG::qPrintChannel::Print(
    &UFG::gPrintChannel_HK_Encounters,
    OUTPUT_LEVEL_DEBUG,
    "[Encounters]: Forgetting unit (%s)\n");
  if ( v3->mEnableKillCount )
  {
    v5 = (UFG::SimObjectGame *)v3->m_pSimObject;
    v3->mEnableKillCount = 0;
    if ( v5 )
    {
      v6 = v5->m_Flags;
      if ( !((v6 >> 14) & 1) )
      {
        if ( (v6 & 0x8000u) != 0 )
        {
          v7 = v5->m_Components.p[34].m_pComponent;
          goto LABEL_11;
        }
        if ( !((v6 >> 13) & 1) )
        {
          if ( (v6 >> 12) & 1 )
            v7 = UFG::SimObjectGame::GetComponentOfTypeHK(v5, UFG::PhysicsMoverInterface::_TypeUID);
          else
            v7 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v5->vfptr, UFG::PhysicsMoverInterface::_TypeUID);
LABEL_11:
          if ( v7 )
          {
            if ( !v3->mUnitDisabled )
              goto LABEL_72;
            ++v4->mVehicleKillCount;
            v8 = v4->mEnableWaveTimerChangesByDisabledUnits == 0;
            v4->mDisabledUnitForCurrentWave = 1;
            if ( !v8 && v4->mWaveTimer >= 0.0 )
            {
              v9 = (UFG::qPropertySet *)((__int64 (__fastcall *)(UFG::EncounterBase *))v4->vfptr[33].__vecDelDtor)(v4);
              if ( v9
                && (v10 = UFG::qPropertySet::Get<float>(
                            v9,
                            (UFG::qSymbol *)&EncounterSym_vehicle_kill_bonus_timer.mUID,
                            DEPTH_RECURSE)) != 0i64 )
              {
                v11 = *v10;
              }
              else
              {
                v11 = FLOAT_2_0;
              }
              v4->mWaveTimer = v11 + v4->mWaveTimer;
            }
            v12 = v2->m_Flags;
            if ( (v12 >> 14) & 1 )
            {
              v13 = UFG::SimObjectGame::GetComponentOfTypeHK(
                      (UFG::SimObjectGame *)v2,
                      UFG::VehicleOccupantComponent::_TypeUID);
            }
            else
            {
              if ( (v12 & 0x8000u) != 0 )
              {
                v14 = (UFG::VehicleOccupantComponent *)v2->m_Components.p[30].m_pComponent;
LABEL_30:
                if ( v14 )
                {
                  v15 = 0;
                  v16 = UFG::VehicleOccupantComponent::GetNumberOfOccupants(v14);
                  if ( v16 )
                  {
                    do
                    {
                      v17 = (UFG::SimObjectGame *)UFG::VehicleOccupantComponent::GetOccupant(v14, v15, 0i64);
                      if ( v17 )
                      {
                        v18 = v17->m_Flags;
                        if ( (v18 >> 14) & 1 )
                        {
                          v19 = v17->m_Components.p[16].m_pComponent;
                        }
                        else if ( (v18 & 0x8000u) == 0 )
                        {
                          if ( (v18 >> 13) & 1 )
                            v19 = UFG::SimObjectGame::GetComponentOfTypeHK(v17, UFG::EncounterUnitComponent::_TypeUID);
                          else
                            v19 = (v18 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                      v17,
                                                      UFG::EncounterUnitComponent::_TypeUID) : UFG::SimObject::GetComponentOfType(
                                                                                                 (UFG::SimObject *)&v17->vfptr,
                                                                                                 UFG::EncounterUnitComponent::_TypeUID);
                        }
                        else
                        {
                          v19 = v17->m_Components.p[16].m_pComponent;
                        }
                        if ( v19 )
                          LOBYTE(v19[2].m_SafePointerList.mNode.mNext) = 0;
                      }
                      ++v15;
                    }
                    while ( v15 < v16 );
                  }
                }
                goto LABEL_72;
              }
              if ( (v12 >> 13) & 1 )
              {
                v13 = UFG::SimObjectGame::GetComponentOfTypeHK(
                        (UFG::SimObjectGame *)v2,
                        UFG::VehicleOccupantComponent::_TypeUID);
              }
              else if ( (v12 >> 12) & 1 )
              {
                v13 = UFG::SimObjectGame::GetComponentOfTypeHK(
                        (UFG::SimObjectGame *)v2,
                        UFG::VehicleOccupantComponent::_TypeUID);
              }
              else
              {
                v13 = UFG::SimObject::GetComponentOfType(v2, UFG::VehicleOccupantComponent::_TypeUID);
              }
            }
            v14 = (UFG::VehicleOccupantComponent *)v13;
            goto LABEL_30;
          }
          goto LABEL_46;
        }
      }
    }
LABEL_46:
    if ( !(unsigned __int8)v4->vfptr[78].__vecDelDtor(
                             (UFG::qSafePointerNode<UFG::EncounterBase> *)&v4->vfptr,
                             (unsigned int)v3) )
      ++v4->mCharacterKillCount;
    v20 = v2->m_Flags;
    if ( (v20 >> 14) & 1 )
    {
      v21 = v2->m_Components.p[44].m_pComponent;
    }
    else
    {
      if ( (v20 & 0x8000u) == 0 )
      {
        if ( (v20 >> 13) & 1 )
        {
          v22 = UFG::SimObjectGame::GetComponentOfTypeHK(
                  (UFG::SimObjectGame *)v2,
                  UFG::CharacterOccupantComponent::_TypeUID);
        }
        else if ( (v20 >> 12) & 1 )
        {
          v22 = UFG::SimObjectGame::GetComponentOfTypeHK(
                  (UFG::SimObjectGame *)v2,
                  UFG::CharacterOccupantComponent::_TypeUID);
        }
        else
        {
          v22 = UFG::SimObject::GetComponentOfType(v2, UFG::CharacterOccupantComponent::_TypeUID);
        }
      }
      else
      {
        v22 = UFG::SimObjectGame::GetComponentOfTypeHK(
                (UFG::SimObjectGame *)v2,
                UFG::CharacterOccupantComponent::_TypeUID);
      }
      v21 = v22;
    }
    if ( v21 )
    {
      v23 = (UFG::SimObjectGame *)UFG::CharacterOccupantComponent::GetCurrentVehicle((UFG::CharacterOccupantComponent *)v21);
      if ( v23 )
      {
        if ( LODWORD(v21[1].m_SafePointerList.mNode.mNext) == 4 )
        {
          v24 = v23->m_Flags;
          if ( (v24 >> 14) & 1 )
          {
            v25 = v23->m_Components.p[16].m_pComponent;
          }
          else if ( (v24 & 0x8000u) == 0 )
          {
            if ( (v24 >> 13) & 1 )
              v25 = UFG::SimObjectGame::GetComponentOfTypeHK(v23, UFG::EncounterUnitComponent::_TypeUID);
            else
              v25 = (v24 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                        v23,
                                        UFG::EncounterUnitComponent::_TypeUID) : UFG::SimObject::GetComponentOfType(
                                                                                   (UFG::SimObject *)&v23->vfptr,
                                                                                   UFG::EncounterUnitComponent::_TypeUID);
          }
          else
          {
            v25 = v23->m_Components.p[16].m_pComponent;
          }
          if ( v25 )
            LOBYTE(v25[2].m_SafePointerList.mNode.mNext) = 0;
        }
      }
    }
  }
LABEL_72:
  v26 = v2->m_Flags;
  if ( (v26 >> 14) & 1 )
  {
    v27 = (UFG::StreamedResourceComponent *)v2->m_Components.p[10].m_pComponent;
  }
  else if ( (v26 & 0x8000u) == 0 )
  {
    if ( (v26 >> 13) & 1 )
    {
      v27 = (UFG::StreamedResourceComponent *)v2->m_Components.p[7].m_pComponent;
    }
    else
    {
      if ( (v26 >> 12) & 1 )
        v28 = UFG::SimObjectGame::GetComponentOfTypeHK(
                (UFG::SimObjectGame *)v2,
                UFG::StreamedResourceComponent::_TypeUID);
      else
        v28 = UFG::SimObject::GetComponentOfType(v2, UFG::StreamedResourceComponent::_TypeUID);
      v27 = (UFG::StreamedResourceComponent *)v28;
    }
  }
  else
  {
    v27 = (UFG::StreamedResourceComponent *)v2->m_Components.p[10].m_pComponent;
  }
  if ( v27 )
  {
    symbol.mUID = v27->mActivePriority.mUID;
    UFG::StreamedResourceComponent::IncrementPriorityReferenceCount(v27, (UFG::qSymbol *)&qSymbol_Low.mUID);
    UFG::StreamedResourceComponent::DecrementPriorityReferenceCount(v27, &symbol);
  }
  v29 = v2->m_Flags;
  if ( (v29 >> 14) & 1 )
  {
    v30 = v2->m_Components.p[24].m_pComponent;
  }
  else if ( (v29 & 0x8000u) == 0 )
  {
    if ( (v29 >> 13) & 1 )
    {
      v30 = UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)v2, UFG::RoadSpaceComponent::_TypeUID);
    }
    else if ( (v29 >> 12) & 1 )
    {
      v30 = UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)v2, UFG::RoadSpaceComponent::_TypeUID);
    }
    else
    {
      v30 = UFG::SimObject::GetComponentOfType(v2, UFG::RoadSpaceComponent::_TypeUID);
    }
  }
  else
  {
    v30 = v2->m_Components.p[24].m_pComponent;
  }
  if ( v30 )
  {
    v31 = v2->m_Flags;
    if ( (v31 >> 14) & 1 )
    {
      v32 = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>((UFG::SimObjectCVBase *)v2);
    }
    else if ( (v31 & 0x8000u) == 0 )
    {
      if ( (v31 >> 13) & 1 )
        v32 = (UFG::AiDriverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                          (UFG::SimObjectGame *)v2,
                                          UFG::AiDriverComponent::_TypeUID);
      else
        v32 = (UFG::AiDriverComponent *)((v31 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                             (UFG::SimObjectGame *)v2,
                                                             UFG::AiDriverComponent::_TypeUID) : UFG::SimObject::GetComponentOfType(
                                                                                                   v2,
                                                                                                   UFG::AiDriverComponent::_TypeUID));
    }
    else
    {
      v32 = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>((UFG::SimObjectCVBase *)v2);
    }
    v33 = v32;
    if ( v32 )
    {
      if ( v32->m_DrivingMode )
      {
        UFG::AiDriverComponent::SetDrivingRole(v32, 0);
        UFG::AiDriverComponent::SetDrivingMode(v33, 0);
      }
    }
  }
  v34 = v2->m_Flags;
  if ( (v34 >> 14) & 1 )
  {
    v35 = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>((UFG::SimObjectCVBase *)v2);
  }
  else if ( (v34 & 0x8000u) == 0 )
  {
    if ( (v34 >> 13) & 1 )
    {
      v35 = (UFG::ActiveAIEntityComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                              (UFG::SimObjectGame *)v2,
                                              UFG::ActiveAIEntityComponent::_TypeUID);
    }
    else if ( (v34 >> 12) & 1 )
    {
      v35 = (UFG::ActiveAIEntityComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                              (UFG::SimObjectGame *)v2,
                                              UFG::ActiveAIEntityComponent::_TypeUID);
    }
    else
    {
      v35 = (UFG::ActiveAIEntityComponent *)UFG::SimObject::GetComponentOfType(
                                              v2,
                                              UFG::ActiveAIEntityComponent::_TypeUID);
    }
  }
  else
  {
    v35 = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>((UFG::SimObjectCVBase *)v2);
  }
  v36 = v35;
  if ( v35 )
  {
    v37 = v4->mPostObjective;
    if ( (signed int)v37 >= 36 )
      v37 = 0;
    UFG::ActiveAIEntityComponent::SetCurrentObjective(v35, v37, "EncounterBase::Forget");
    v36->m_bCanWander = 1;
  }
  v38 = v2->m_Flags;
  if ( (v38 >> 14) & 1 )
  {
    v39 = v2->m_Components.p[20].m_pComponent;
  }
  else if ( (v38 & 0x8000u) == 0 )
  {
    if ( (v38 >> 13) & 1 )
    {
      v40 = UFG::SimObjectGame::GetComponentOfTypeHK(
              (UFG::SimObjectGame *)v2,
              UFG::TargetingSystemBaseComponent::_TypeUID);
    }
    else if ( (v38 >> 12) & 1 )
    {
      v40 = UFG::SimObjectGame::GetComponentOfTypeHK(
              (UFG::SimObjectGame *)v2,
              UFG::TargetingSystemBaseComponent::_TypeUID);
    }
    else
    {
      v40 = UFG::SimObject::GetComponentOfType(v2, UFG::TargetingSystemBaseComponent::_TypeUID);
    }
    v39 = v40;
  }
  else
  {
    v39 = v2->m_Components.p[20].m_pComponent;
  }
  if ( v39 )
  {
    v41 = *(_BYTE *)(*(_QWORD *)&v39[1].m_Flags + 37i64);
    if ( v41 )
    {
      v42 = 56i64 * v41;
      UFG::TargetingSimObject::SetTarget((UFG::TargetingSimObject *)(v42 + *(_QWORD *)&v39[1].m_TypeUID), 0i64);
      UFG::TargetingSimObject::SetLock((UFG::TargetingSimObject *)(v42 + *(_QWORD *)&v39[1].m_TypeUID), 0);
    }
  }
  v43 = UFG::PedSpawnManager::GetInstance();
  UFG::PedSpawnManager::SetSuspendOption(v43, v2, DeleteOnSuspend);
  v44 = UFG::PedSpawnManager::ReleaseOwnership(v2, 4u, 1);
  if ( v44 )
  {
    v45 = v44->m_Flags;
    if ( (v45 >> 14) & 1 )
    {
      v46 = UFG::SimObjectGame::GetComponentOfTypeHK(
              (UFG::SimObjectGame *)&v44->vfptr,
              UFG::VehicleOccupantComponent::_TypeUID);
    }
    else
    {
      if ( (v45 & 0x8000u) != 0 )
      {
        v47 = (UFG::VehicleOccupantComponent *)v44->m_Components.p[30].m_pComponent;
LABEL_143:
        if ( v47 )
        {
          v48 = 0;
          if ( (unsigned int)UFG::VehicleOccupantComponent::GetNumberOfOccupants(v47) )
          {
            do
            {
              v49 = (UFG::SimObjectGame *)UFG::VehicleOccupantComponent::GetOccupant(v47, v48, 0i64);
              v50 = v49;
              if ( v49 )
              {
                v51 = v49->m_Flags;
                if ( (v51 >> 14) & 1 )
                {
                  v52 = v49->m_Components.p[16].m_pComponent;
                }
                else if ( (v51 & 0x8000u) == 0 )
                {
                  if ( (v51 >> 13) & 1 )
                  {
                    v52 = UFG::SimObjectGame::GetComponentOfTypeHK(v49, UFG::EncounterUnitComponent::_TypeUID);
                  }
                  else if ( (v51 >> 12) & 1 )
                  {
                    v52 = UFG::SimObjectGame::GetComponentOfTypeHK(v49, UFG::EncounterUnitComponent::_TypeUID);
                  }
                  else
                  {
                    v52 = UFG::SimObject::GetComponentOfType(
                            (UFG::SimObject *)&v49->vfptr,
                            UFG::EncounterUnitComponent::_TypeUID);
                  }
                }
                else
                {
                  v52 = v49->m_Components.p[16].m_pComponent;
                }
              }
              else
              {
                v52 = 0i64;
              }
              if ( v52 && v4 == *(UFG::EncounterBase **)&v52[1].m_TypeUID )
              {
                ((void (__fastcall *)(UFG::EncounterBase *, UFG::SimComponent *, UFG::SimObjectGame *))v4->vfptr[37].__vecDelDtor)(
                  v4,
                  v52,
                  v50);
                v4->vfptr[24].__vecDelDtor((UFG::qSafePointerNode<UFG::EncounterBase> *)&v4->vfptr, (unsigned int)v52);
              }
              ++v48;
            }
            while ( v48 < (unsigned int)UFG::VehicleOccupantComponent::GetNumberOfOccupants(v47) );
          }
        }
        goto LABEL_160;
      }
      if ( (v45 >> 13) & 1 )
      {
        v46 = UFG::SimObjectGame::GetComponentOfTypeHK(
                (UFG::SimObjectGame *)&v44->vfptr,
                UFG::VehicleOccupantComponent::_TypeUID);
      }
      else if ( (v45 >> 12) & 1 )
      {
        v46 = UFG::SimObjectGame::GetComponentOfTypeHK(
                (UFG::SimObjectGame *)&v44->vfptr,
                UFG::VehicleOccupantComponent::_TypeUID);
      }
      else
      {
        v46 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v44->vfptr, UFG::VehicleOccupantComponent::_TypeUID);
      }
    }
    v47 = (UFG::VehicleOccupantComponent *)v46;
    goto LABEL_143;
  }
}

// File Line: 994
// RVA: 0x3FB760
void __fastcall UFG::EncounterBase::UpdateVehicleStatus(UFG::EncounterBase *this, float deltaTime, UFG::EncounterUnitComponent *pEncounterUnitComponent)
{
  UFG::SimObjectVehicle *v3; // rcx
  UFG::EncounterUnitComponent *v4; // rbx
  float v5; // xmm0_4

  v3 = (UFG::SimObjectVehicle *)pEncounterUnitComponent->m_pSimObject;
  v4 = pEncounterUnitComponent;
  if ( v3 )
    v5 = deltaTime + pEncounterUnitComponent->mAcquiredTimer;
  else
    v5 = 0.0;
  pEncounterUnitComponent->mAcquiredTimer = v5;
  if ( (unsigned int)UFG::VehicleUtility::GetVehicleOrientation(v3, 0, 0i64) )
    v4->mVehicleFlipTimer = deltaTime + v4->mVehicleFlipTimer;
  else
    v4->mVehicleFlipTimer = 0.0;
}

// File Line: 1012
// RVA: 0x3FA780
void __fastcall UFG::EncounterBase::UpdatePopulation(UFG::EncounterBase *this, float deltaTime)
{
  UFG::EncounterBase *v2; // rdi
  __int64 v3; // r12
  __int64 v4; // rax
  __int64 v5; // r13
  UFG::qPropertySet *v6; // rsi
  __int64 v7; // r14
  UFG::qSymbol *v8; // r15
  UFG::SimObject *v9; // r8
  unsigned __int16 v10; // dx
  UFG::SimComponent *v11; // rax
  UFG::SimObjectGame *v12; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v13; // rbx
  bool *v14; // rax
  bool *v15; // rax
  bool *v16; // rax
  bool *v17; // rax
  bool *v18; // rax
  bool *v19; // rax
  bool *v20; // rax
  unsigned int v21; // ecx
  signed int v22; // eax
  __int64 v23; // rdx
  unsigned int i; // ebp
  __int64 v25; // r15
  UFG::EncounterUnitComponent *v26; // rsi
  UFG::SimObjectGame *v27; // rbx
  float v28; // xmm0_4
  unsigned __int16 v29; // cx
  UFG::SimComponent *v30; // rax
  unsigned int j; // ebx
  __int64 v32; // rbp
  UFG::EncounterUnitComponent *v33; // rsi
  UFG::SimObject *v34; // r15
  UFG::EncounterBase::ReplenishStyle v35; // ecx
  unsigned int v36; // edx
  char v37; // r8
  unsigned int v38; // ebx
  unsigned int v39; // esi
  unsigned int v40; // ebp
  unsigned int v41; // er14
  bool v42; // cf
  __int64 v43; // [rsp+70h] [rbp+8h]

  v2 = this;
  v3 = ((__int64 (*)(void))this->vfptr[33].__vecDelDtor)();
  v4 = ((__int64 (__fastcall *)(UFG::EncounterBase *))v2->vfptr[18].__vecDelDtor)(v2);
  v5 = v4;
  if ( v3 )
  {
    if ( v4 )
    {
      UFG::PropertySetHandle::Bind(&v2->mProperties);
      v6 = v2->mProperties.mpPropSet;
      v43 = *(_QWORD *)(v5 + 88);
      if ( v43 )
      {
        v7 = 0i64;
        if ( v2->mHeatLevel )
        {
          v8 = UFG::qPropertySet::Get<UFG::qSymbol>(
                 v6,
                 (UFG::qSymbol *)&EncounterSym_formation_style.mUID,
                 DEPTH_RECURSE);
          if ( v8 )
          {
            v9 = v2->mFocusTargetContext.mpVehicle;
            if ( v9 )
            {
              v10 = v9->m_Flags;
              if ( (v10 >> 14) & 1 )
              {
                v11 = v9->m_Components.p[24].m_pComponent;
              }
              else if ( (v10 & 0x8000u) == 0 )
              {
                v12 = (UFG::SimObjectGame *)v2->mFocusTargetContext.mpVehicle;
                if ( (v10 >> 13) & 1 )
                  v11 = UFG::SimObjectGame::GetComponentOfTypeHK(v12, UFG::RoadSpaceComponent::_TypeUID);
                else
                  v11 = (v10 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                            v12,
                                            UFG::RoadSpaceComponent::_TypeUID) : UFG::SimObject::GetComponentOfType(
                                                                                   (UFG::SimObject *)&v12->vfptr,
                                                                                   UFG::RoadSpaceComponent::_TypeUID);
              }
              else
              {
                v11 = v9->m_Components.p[24].m_pComponent;
              }
              if ( v11 )
              {
                v13 = v11[26].m_BoundComponentHandles.mNode.mPrev;
                v11[30].m_TypeUID |= 2u;
                if ( v13 )
                {
                  BYTE4(v13[38].mPrev) = 1;
                  v14 = UFG::qPropertySet::Get<bool>(
                          v6,
                          (UFG::qSymbol *)&EncounterSym_formation_slot_follow.mUID,
                          DEPTH_RECURSE);
                  UFG::VehicleFormations::SetSlotUsability((UFG::VehicleFormations *)v13, 0, *v14);
                  v15 = UFG::qPropertySet::Get<bool>(
                          v6,
                          (UFG::qSymbol *)&EncounterSym_formation_slot_behind.mUID,
                          DEPTH_RECURSE);
                  UFG::VehicleFormations::SetSlotUsability((UFG::VehicleFormations *)v13, Behind, *v15);
                  v16 = UFG::qPropertySet::Get<bool>(
                          v6,
                          (UFG::qSymbol *)&EncounterSym_formation_slot_rearcorner.mUID,
                          DEPTH_RECURSE);
                  UFG::VehicleFormations::SetSlotUsability((UFG::VehicleFormations *)v13, RearCorner, *v16);
                  v17 = UFG::qPropertySet::Get<bool>(
                          v6,
                          (UFG::qSymbol *)&EncounterSym_formation_slot_pitposition.mUID,
                          DEPTH_RECURSE);
                  UFG::VehicleFormations::SetSlotUsability((UFG::VehicleFormations *)v13, PitPosition, *v17);
                  v18 = UFG::qPropertySet::Get<bool>(
                          v6,
                          (UFG::qSymbol *)&EncounterSym_formation_slot_beside.mUID,
                          DEPTH_RECURSE);
                  UFG::VehicleFormations::SetSlotUsability((UFG::VehicleFormations *)v13, Beside, *v18);
                  v19 = UFG::qPropertySet::Get<bool>(
                          v6,
                          (UFG::qSymbol *)&EncounterSym_formation_slot_frontcorner.mUID,
                          DEPTH_RECURSE);
                  UFG::VehicleFormations::SetSlotUsability((UFG::VehicleFormations *)v13, FrontCorner, *v19);
                  v20 = UFG::qPropertySet::Get<bool>(
                          v6,
                          (UFG::qSymbol *)&EncounterSym_formation_slot_front.mUID,
                          DEPTH_RECURSE);
                  UFG::VehicleFormations::SetSlotUsability((UFG::VehicleFormations *)v13, Front, *v20);
                  UFG::VehicleFormations::OverrideSlotOffsets((UFG::VehicleFormations *)v13, v6);
                  v21 = v8->mUID;
                  if ( v8->mUID == EncounterSym_escort.mUID )
                  {
                    LODWORD(v13[1].mPrev) = 3;
                  }
                  else if ( v21 == EncounterSym_generic_favor_front.mUID )
                  {
                    LODWORD(v13[1].mPrev) = 1;
                  }
                  else
                  {
                    v22 = 0;
                    if ( v21 == EncounterSym_generic_favor_back.mUID )
                      v22 = 2;
                    LODWORD(v13[1].mPrev) = v22;
                  }
                  UFG::VehicleFormations::SetSecondaryTarget(
                    (UFG::VehicleFormations *)v13,
                    v2->mpSecondaryTarget.m_pPointer);
                }
              }
            }
          }
        }
        v2->vfptr[35].__vecDelDtor((UFG::qSafePointerNode<UFG::EncounterBase> *)&v2->vfptr, v3);
        v2->vfptr[36].__vecDelDtor((UFG::qSafePointerNode<UFG::EncounterBase> *)&v2->vfptr, v3);
        for ( i = 0; i < v2->mHumans.size; ++i )
        {
          v25 = i;
          v26 = v2->mHumans.p[i];
          v27 = (UFG::SimObjectGame *)v26->m_pSimObject;
          if ( v27 )
            v28 = deltaTime + v26->mAcquiredTimer;
          else
            v28 = 0.0;
          v26->mAcquiredTimer = v28;
          if ( v27 )
          {
            if ( (unsigned __int8)v2->vfptr[71].__vecDelDtor(
                                    (UFG::qSafePointerNode<UFG::EncounterBase> *)&v2->vfptr,
                                    (unsigned int)v26)
              && (unsigned __int8)v2->vfptr[73].__vecDelDtor(
                                    (UFG::qSafePointerNode<UFG::EncounterBase> *)&v2->vfptr,
                                    (unsigned int)v26) )
            {
              continue;
            }
            if ( v2->mHumans.size == 1
              && !(unsigned __int8)v2->vfptr[78].__vecDelDtor(
                                     (UFG::qSafePointerNode<UFG::EncounterBase> *)&v2->vfptr,
                                     (unsigned int)v26) )
            {
              v29 = v27->m_Flags;
              if ( (v29 >> 14) & 1 )
              {
                v30 = v27->m_Components.p[44].m_pComponent;
              }
              else if ( (v29 & 0x8000u) == 0 )
              {
                if ( (v29 >> 13) & 1 )
                  v30 = UFG::SimObjectGame::GetComponentOfTypeHK(v27, UFG::CharacterOccupantComponent::_TypeUID);
                else
                  v30 = (v29 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                            v27,
                                            UFG::CharacterOccupantComponent::_TypeUID) : UFG::SimObject::GetComponentOfType(
                                                                                           (UFG::SimObject *)&v27->vfptr,
                                                                                           UFG::CharacterOccupantComponent::_TypeUID);
              }
              else
              {
                v30 = UFG::SimObjectGame::GetComponentOfTypeHK(v27, UFG::CharacterOccupantComponent::_TypeUID);
              }
              if ( !v30 )
                v2->vfptr[70].__vecDelDtor((UFG::qSafePointerNode<UFG::EncounterBase> *)&v2->vfptr, (unsigned int)v26);
            }
            v2->vfptr[37].__vecDelDtor((UFG::qSafePointerNode<UFG::EncounterBase> *)&v2->vfptr, (unsigned int)v26);
          }
          --v2->mHumans.size;
          --i;
          v2->mHumans.p[v25] = v2->mHumans.p[v2->mHumans.size];
        }
        for ( j = 0; j < v2->mVehicles.size; ++j )
        {
          v32 = j;
          v33 = v2->mVehicles.p[j];
          v34 = v33->m_pSimObject;
          ((void (__fastcall *)(UFG::EncounterBase *, __int64, UFG::EncounterUnitComponent *))v2->vfptr[80].__vecDelDtor)(
            v2,
            v23,
            v2->mVehicles.p[j]);
          if ( v34 )
          {
            if ( v2->vfptr[72].__vecDelDtor((UFG::qSafePointerNode<UFG::EncounterBase> *)&v2->vfptr, (unsigned int)v33) )
            {
              if ( v2->vfptr[74].__vecDelDtor(
                     (UFG::qSafePointerNode<UFG::EncounterBase> *)&v2->vfptr,
                     (unsigned int)v33) )
              {
                if ( v2->vfptr[73].__vecDelDtor(
                       (UFG::qSafePointerNode<UFG::EncounterBase> *)&v2->vfptr,
                       (unsigned int)v33) )
                {
                  v2->vfptr[51].__vecDelDtor((UFG::qSafePointerNode<UFG::EncounterBase> *)&v2->vfptr, (unsigned int)v34);
                  continue;
                }
              }
              else
              {
                v33->mUnitDisabled = 1;
              }
            }
            v2->vfptr[37].__vecDelDtor((UFG::qSafePointerNode<UFG::EncounterBase> *)&v2->vfptr, (unsigned int)v33);
          }
          --v2->mVehicles.size;
          --j;
          v2->mVehicles.p[v32] = v2->mVehicles.p[v2->mVehicles.size];
        }
        if ( 0.0 == v2->mFocusTargetContext.mWaterContextTimer )
        {
          if ( v2->mIsReplenishing )
          {
            v35 = v2->mReplenishStyle;
            if ( v35 )
            {
              if ( v35 == 1 )
              {
                v36 = v2->mNumWaveGroupTypes;
                v37 = 0;
                if ( v36 )
                {
                  while ( v2->mWaveGroupInstances[v7] >= v2->mWaveGroupInstancesRequired[v7] )
                  {
                    v7 = (unsigned int)(v7 + 1);
                    if ( (unsigned int)v7 >= v36 )
                    {
                      v2->mIsReplenishing = 0;
                      goto LABEL_75;
                    }
                  }
                  v37 = 1;
                }
                v2->mIsReplenishing = v37;
              }
            }
            else
            {
              v38 = (__int64)v2->vfptr[35].__vecDelDtor((UFG::qSafePointerNode<UFG::EncounterBase> *)&v2->vfptr, v3);
              v39 = (__int64)v2->vfptr[36].__vecDelDtor((UFG::qSafePointerNode<UFG::EncounterBase> *)&v2->vfptr, v3);
              v40 = (__int64)v2->vfptr[75].__vecDelDtor((UFG::qSafePointerNode<UFG::EncounterBase> *)&v2->vfptr, 2u);
              v41 = (__int64)v2->vfptr[75].__vecDelDtor((UFG::qSafePointerNode<UFG::EncounterBase> *)&v2->vfptr, 1u);
              if ( v2->mIsReplenishing )
              {
                if ( ((unsigned __int8 (__fastcall *)(UFG::EncounterBase *))v2->vfptr[61].__vecDelDtor)(v2) )
                  v42 = v41 < v39;
                else
                  v42 = v40 < v38;
                if ( !v42 )
                  v2->mIsReplenishing = 0;
              }
            }
          }
LABEL_75:
          ((void (__fastcall *)(UFG::EncounterBase *, __int64, __int64))v2->vfptr[42].__vecDelDtor)(v2, v5, v43);
          ((void (__fastcall *)(UFG::EncounterBase *, UFG::SimObject *, __int64))v2->vfptr[43].__vecDelDtor)(
            v2,
            v2->mFocusTargetContext.mpVehicle,
            v43);
        }
      }
    }
  }
}

// File Line: 1235
// RVA: 0x3FB1C0
void __fastcall UFG::EncounterBase::UpdateRoleAssignments(UFG::EncounterBase *this)
{
  __int64 v1; // r15
  UFG::GroupComponent *v2; // r12
  UFG::EncounterUnitComponent *v3; // rbp
  float v4; // xmm6_4
  UFG::EncounterBase *v5; // r14
  UFG::EncounterUnitComponent **v6; // rbx
  __int64 v7; // rsi
  UFG::EncounterUnitComponent *v8; // rdi
  UFG::SimObjectCVBase *v9; // rcx
  UFG::ActiveAIEntityComponent *v10; // rax
  unsigned __int16 v11; // dx
  UFG::GroupComponent *v12; // rcx
  UFG::qVector3 *v13; // rax
  __m128 v14; // xmm2
  float v15; // xmm1_4
  UFG::SimObjectCVBase *v16; // rcx
  UFG::ActiveAIEntityComponent *v17; // rax
  unsigned __int16 v18; // dx
  UFG::GroupComponent *v19; // rcx
  signed __int64 v20; // rbx
  __int64 v21; // rbp
  __int64 v22; // rdi
  UFG::GroupComponent *v23; // rsi
  UFG::SimObjectCVBase *v24; // rcx
  UFG::ActiveAIEntityComponent *v25; // rax
  unsigned __int16 v26; // dx
  UFG::GroupComponent *v27; // rcx
  UFG::qVector3 result; // [rsp+20h] [rbp-38h]

  v1 = this->mHumans.size;
  v2 = 0i64;
  v3 = 0i64;
  v4 = FLOAT_3_4028235e38;
  v5 = this;
  if ( (_DWORD)v1 )
  {
    v6 = this->mHumans.p;
    v7 = (unsigned int)v1;
    do
    {
      v8 = *v6;
      v9 = (UFG::SimObjectCVBase *)(*v6)->m_pSimObject;
      if ( v9 )
      {
        v11 = v9->m_Flags;
        if ( (v11 >> 14) & 1 )
        {
          v10 = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>(v9);
        }
        else if ( (v11 & 0x8000u) == 0 )
        {
          if ( (v11 >> 13) & 1 )
          {
            v10 = (UFG::ActiveAIEntityComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                    (UFG::SimObjectGame *)&v9->vfptr,
                                                    UFG::ActiveAIEntityComponent::_TypeUID);
          }
          else if ( (v11 >> 12) & 1 )
          {
            v10 = (UFG::ActiveAIEntityComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                    (UFG::SimObjectGame *)&v9->vfptr,
                                                    UFG::ActiveAIEntityComponent::_TypeUID);
          }
          else
          {
            v10 = (UFG::ActiveAIEntityComponent *)UFG::SimObject::GetComponentOfType(
                                                    (UFG::SimObject *)&v9->vfptr,
                                                    UFG::ActiveAIEntityComponent::_TypeUID);
          }
        }
        else
        {
          v10 = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>(v9);
        }
      }
      else
      {
        v10 = 0i64;
      }
      v12 = v10->m_pGroupComponent.m_pPointer;
      if ( v12 )
      {
        v13 = UFG::GroupComponent::GetPosition(v12, &result);
        v14 = (__m128)LODWORD(v13->y);
        v14.m128_f32[0] = (float)((float)((float)(v14.m128_f32[0] - v5->mFocusTargetPosition.y)
                                        * (float)(v14.m128_f32[0] - v5->mFocusTargetPosition.y))
                                + (float)((float)(v13->x - v5->mFocusTargetPosition.x)
                                        * (float)(v13->x - v5->mFocusTargetPosition.x)))
                        + (float)((float)(v13->z - v5->mFocusTargetPosition.z)
                                * (float)(v13->z - v5->mFocusTargetPosition.z));
        LODWORD(v15) = (unsigned __int128)_mm_sqrt_ps(v14);
        if ( v15 < v4 )
        {
          v4 = v15;
          v3 = v8;
        }
      }
      ++v6;
      --v7;
    }
    while ( v7 );
    if ( v3 )
    {
      v16 = (UFG::SimObjectCVBase *)v3->m_pSimObject;
      if ( v16 )
      {
        v18 = v16->m_Flags;
        if ( (v18 >> 14) & 1 )
        {
          v17 = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>(v16);
        }
        else if ( (v18 & 0x8000u) == 0 )
        {
          if ( (v18 >> 13) & 1 )
            v17 = (UFG::ActiveAIEntityComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                    (UFG::SimObjectGame *)&v16->vfptr,
                                                    UFG::ActiveAIEntityComponent::_TypeUID);
          else
            v17 = (UFG::ActiveAIEntityComponent *)((v18 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                       (UFG::SimObjectGame *)&v16->vfptr,
                                                                       UFG::ActiveAIEntityComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v16->vfptr, UFG::ActiveAIEntityComponent::_TypeUID));
        }
        else
        {
          v17 = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>(v16);
        }
      }
      else
      {
        v17 = 0i64;
      }
      v19 = v17->m_pGroupComponent.m_pPointer;
      if ( v19 )
        v2 = UFG::GroupComponent::GetSharedGroupComponent(v19);
    }
  }
  if ( (_DWORD)v1 )
  {
    v20 = (signed __int64)v5->mHumans.p;
    v21 = v1;
    do
    {
      v22 = *(_QWORD *)v20;
      v23 = 0i64;
      v24 = *(UFG::SimObjectCVBase **)(*(_QWORD *)v20 + 40i64);
      if ( v24 )
      {
        v26 = v24->m_Flags;
        if ( (v26 >> 14) & 1 )
        {
          v25 = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>(v24);
        }
        else if ( (v26 & 0x8000u) == 0 )
        {
          if ( (v26 >> 13) & 1 )
          {
            v25 = (UFG::ActiveAIEntityComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                    (UFG::SimObjectGame *)&v24->vfptr,
                                                    UFG::ActiveAIEntityComponent::_TypeUID);
          }
          else if ( (v26 >> 12) & 1 )
          {
            v25 = (UFG::ActiveAIEntityComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                    (UFG::SimObjectGame *)&v24->vfptr,
                                                    UFG::ActiveAIEntityComponent::_TypeUID);
          }
          else
          {
            v25 = (UFG::ActiveAIEntityComponent *)UFG::SimObject::GetComponentOfType(
                                                    (UFG::SimObject *)&v24->vfptr,
                                                    UFG::ActiveAIEntityComponent::_TypeUID);
          }
        }
        else
        {
          v25 = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>(v24);
        }
      }
      else
      {
        v25 = 0i64;
      }
      v27 = v25->m_pGroupComponent.m_pPointer;
      if ( v27 )
        v23 = UFG::GroupComponent::GetSharedGroupComponent(v27);
      v20 += 8i64;
      *(_DWORD *)(v22 + 64) = (v23 != v2) + 1;
      --v21;
    }
    while ( v21 );
  }
}

// File Line: 1290
// RVA: 0x3F82D0
char __fastcall UFG::EncounterBase::IsGoodVehicleSpawnTransform(UFG::EncounterBase *this, UFG::qMatrix44 *pTransform)
{
  UFG::qMatrix44 *v2; // r14
  UFG::EncounterBase *v3; // rdi
  __int64 v4; // rbx
  UFG::SimObject *v5; // rsi
  UFG::TransformNodeComponent *v6; // rsi
  UFG::SimObjectGame *v7; // rax
  unsigned __int16 v8; // dx
  UFG::SimComponent *v9; // rax
  char *v11; // rax
  bool i; // zf
  signed __int64 v13; // rbx
  __int64 v14; // rax
  __int64 v15; // rax
  float *v16; // rdi
  UFG::SensorPhantomIterator v17; // [rsp+28h] [rbp-30h]

  v2 = pTransform;
  v3 = this;
  if ( this->vfptr[60].__vecDelDtor((UFG::qSafePointerNode<UFG::EncounterBase> *)this, (unsigned int)&pTransform->v3) )
    return 0;
  v4 = 0i64;
  if ( v3->mVehicles.size )
  {
    do
    {
      v5 = v3->mVehicles.p[v4]->m_pSimObject;
      if ( v5 )
      {
        v6 = v5->m_pTransformNodeComponent;
        if ( v6 )
        {
          UFG::TransformNodeComponent::UpdateWorldTransform(v6);
          if ( (float)((float)((float)((float)(v2->v3.y - v6->mWorldTransform.v3.y)
                                     * (float)(v2->v3.y - v6->mWorldTransform.v3.y))
                             + (float)((float)(v2->v3.x - v6->mWorldTransform.v3.x)
                                     * (float)(v2->v3.x - v6->mWorldTransform.v3.x)))
                     + (float)((float)(v2->v3.z - v6->mWorldTransform.v3.z)
                             * (float)(v2->v3.z - v6->mWorldTransform.v3.z))) < 81.0 )
            return 0;
        }
      }
      v4 = (unsigned int)(v4 + 1);
    }
    while ( (unsigned int)v4 < v3->mVehicles.size );
  }
  UFG::SensorPhantom::SetTransform(v3->mpVehicleSpawnSensor, v2);
  UFG::SensorPhantomIterator::SensorPhantomIterator(&v17, v3->mpVehicleSpawnSensor, 0);
  while ( UFG::SensorPhantomIterator::operator*(&v17) )
  {
    v7 = (UFG::SimObjectGame *)UFG::SensorPhantomIterator::operator*(&v17);
    if ( v7 )
    {
      v8 = v7->m_Flags;
      if ( !((v8 >> 14) & 1) )
      {
        if ( (v8 & 0x8000u) == 0 )
        {
          if ( (v8 >> 13) & 1 )
            goto LABEL_18;
          if ( (v8 >> 12) & 1 )
            v9 = UFG::SimObjectGame::GetComponentOfTypeHK(v7, UFG::PhysicsMoverInterface::_TypeUID);
          else
            v9 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v7->vfptr, UFG::PhysicsMoverInterface::_TypeUID);
        }
        else
        {
          v9 = v7->m_Components.p[34].m_pComponent;
        }
        if ( v9 )
        {
          UFG::SensorPhantomIterator::~SensorPhantomIterator(&v17);
          return 0;
        }
      }
    }
LABEL_18:
    UFG::SensorPhantomIterator::operator++(&v17);
  }
  UFG::SensorPhantomIterator::~SensorPhantomIterator(&v17);
  v11 = (char *)&UFG::PhysicsMoverInterface::s_PhysicsMoverInterfaceList.mNode.mNext[-5].mNext;
  for ( i = &UFG::PhysicsMoverInterface::s_PhysicsMoverInterfaceList.mNode.mNext[-5].mNext == (UFG::qNode<UFG::PhysicsMoverInterface,UFG::PhysicsMoverInterface> **)((char *)&UFG::PhysicsMoverInterface::s_PhysicsMoverInterfaceList - 72);
        !i;
        i = v13 == (_QWORD)&UFG::PhysicsMoverInterface::s_PhysicsMoverInterfaceList - 72 )
  {
    v13 = *((_QWORD *)v11 + 10) - 72i64;
    v14 = *((_QWORD *)v11 + 5);
    if ( v14 )
    {
      v15 = *(_QWORD *)(v14 + 104);
      v16 = *(float **)(v15 + 32);
      if ( v16 )
      {
        UFG::TransformNodeComponent::UpdateWorldTransform(*(UFG::TransformNodeComponent **)(v15 + 32));
        if ( (float)((float)((float)((float)(v2->v3.y - v16[45]) * (float)(v2->v3.y - v16[45]))
                           + (float)((float)(v2->v3.x - v16[44]) * (float)(v2->v3.x - v16[44])))
                   + (float)((float)(v2->v3.z - v16[46]) * (float)(v2->v3.z - v16[46]))) < 81.0 )
          return 0;
      }
    }
    v11 = (char *)v13;
  }
  return 1;
}

// File Line: 1344
// RVA: 0x3F89B0
__int64 __fastcall UFG::EncounterBase::IsSuitableSpawnPointByRoadProperty(UFG::EncounterBase *this, __int64 unitType, UFG::RoadNetworkSpawnPoint *pSpawnPoint)
{
  return ((__int64 (__fastcall *)(UFG::EncounterBase *, __int64, UFG::RoadNetworkSegment *))this->vfptr[55].__vecDelDtor)(
           this,
           unitType,
           pSpawnPoint->mSubSegment->mParentNode);
}

// File Line: 1354
// RVA: 0x3F88E0
bool __fastcall UFG::EncounterBase::IsSuitableByRoadProperty(UFG::EncounterBase *this, UFG::EncounterUnit::UnitType unitType, UFG::RoadNetworkSegment *pSegment)
{
  UFG::EncounterBase *v3; // rsi
  UFG::RoadNetworkSegment *v4; // rbx
  UFG::EncounterUnit::UnitType v5; // edi
  int v6; // eax
  bool result; // al

  v3 = this;
  v4 = pSegment;
  v5 = unitType;
  v6 = UFG::RoadNetworkSegment::GetRoadNetworkType(pSegment);
  if ( v5 == 2 )
  {
    if ( v6 )
      return 0;
  }
  else if ( v5 == 3 && v6 != 3 )
  {
    return 0;
  }
  if ( v3->mHeatLevel <= 0 )
    result = ~(unsigned __int8)(*(_DWORD *)&v4->mBits >> 4) & 1;
  else
    result = !((*(_DWORD *)&v4->mBits >> 1) & 1) && !((*(_DWORD *)&v4->mBits >> 3) & 1);
  return result;
}

// File Line: 1379
// RVA: 0x3F4A80
bool __fastcall UFG::EncounterBase::GenerateVehicleSpawnTransform(UFG::EncounterBase *this, bool enableForwardSpawning, UFG::SimObject *pTargetVehicle, UFG::TransformNodeComponent *pTargetTransform, UFG::qMatrix44 *pTransform, bool *location_is_on_screen, bool enableDebugDraw)
{
  UFG::qVector4 v7; // xmm1
  UFG::qVector4 v8; // xmm2
  UFG::EncounterBase *v9; // r12
  UFG::TransformNodeComponent *v10; // rsi
  UFG::SimObjectGame *v11; // r14
  UFG::qVector4 v12; // xmm3
  UFG::qPropertySet *v13; // rdi
  UFG::qVector4 v14; // xmm3
  UFG::qVector4 v15; // xmm2
  UFG::qVector4 v16; // xmm1
  float *v17; // rbx
  float *v18; // rax
  float v19; // xmm0_4
  float v20; // xmm1_4
  __int64 v21; // rax
  float v22; // xmm0_4
  __int128 v23; // xmm6
  float *v24; // rax
  UFG::TransformNodeComponent *v25; // rax
  UFG::TransformNodeComponent *v26; // rbx
  UFG::qVector4 v27; // xmm3
  UFG::qVector4 v28; // xmm2
  UFG::qVector4 v29; // xmm1
  __int128 v30; // xmm12
  __int128 v31; // xmm7
  UFG::RoadNetworkResource *v32; // rax
  float *v33; // r13
  UFG::RoadNetworkSegment *v34; // rax
  Render::DebugDrawContext *v35; // rax
  float v36; // xmm1_4
  Render::DebugDrawContext *v37; // rbx
  float v38; // xmm0_4
  float v39; // xmm1_4
  float v40; // xmm0_4
  signed int v41; // ebx
  UFG::RoadNetworkGraph *v42; // r15
  UFG::WayTraversal *v43; // rax
  UFG::WayTraversal *v44; // rax
  int v45; // xmm12_4
  unsigned __int16 v46; // cx
  UFG::SimComponent *v47; // rax
  float *v48; // rax
  float v49; // xmm3_4
  __m128 v50; // xmm4
  float v51; // xmm5_4
  __m128 v52; // xmm2
  float v53; // xmm1_4
  __int64 v54; // rbx
  float v55; // xmm6_4
  float v56; // xmm0_4
  bool v57; // zf
  unsigned int v58; // er14
  float v59; // xmm6_4
  unsigned __int16 v60; // bx
  unsigned __int16 v61; // di
  UFG::RoadNetworkResource *v62; // rsi
  UFG::RoadNetworkSegment *v63; // rdi
  int v64; // eax
  UFG::RoadNetworkIntersection *v65; // rsi
  unsigned int v66; // ebx
  UFG::RoadNetworkConnection *v67; // rax
  UFG::RoadNetworkGate *v68; // r13
  UFG::RoadNetworkIntersection *v69; // rcx
  __int64 v70; // rbx
  bool v71; // al
  unsigned int v72; // er12
  UFG::RoadNetworkConnection *v73; // rax
  UFG::RoadNetworkConnection *v74; // rsi
  __int64 v75; // rax
  signed __int64 v76; // rax
  __int64 v77; // rax
  unsigned int *v78; // r15
  unsigned int v79; // er14
  unsigned int v80; // edi
  unsigned int v81; // er12
  UFG::RoadNetworkConnection *v82; // rax
  UFG::RoadNetworkConnection *v83; // rsi
  __int64 v84; // rax
  signed __int64 v85; // rax
  __int64 v86; // rax
  unsigned int *v87; // r15
  unsigned int v88; // er14
  unsigned int v89; // edi
  Render::DebugDrawManager *v90; // rax
  Render::DebugDrawContext *v91; // rsi
  __int64 *v92; // r14
  __int64 v93; // r15
  UFG::RoadNetworkLane *v94; // rdi
  float v95; // xmm15_4
  float v96; // xmm0_4
  float v97; // xmm11_4
  bool v98; // al
  float *v99; // r13
  UFG::qColour *v100; // rcx
  float v101; // xmm1_4
  float v102; // xmm0_4
  float v103; // eax
  float v104; // eax
  float v105; // eax
  float v106; // xmm13_4
  float v107; // xmm3_4
  __m128 v108; // xmm2
  float v109; // xmm4_4
  float v110; // xmm6_4
  __m128 v111; // xmm7
  float v112; // xmm1_4
  float v113; // xmm2_4
  float v114; // xmm3_4
  float v115; // xmm4_4
  UFG::qColour *v116; // r9
  UFG::qVector3 *v117; // r8
  float v118; // xmm6_4
  bool v119; // bl
  UFG::BaseCameraComponent *v120; // rcx
  UFG::RoadNetworkNode *v121; // rcx
  __m128 v122; // xmm4
  __m128 v123; // xmm3
  __m128 v124; // xmm2
  float v125; // xmm1_4
  float v126; // xmm4_4
  float v127; // xmm9_4
  __m128 v128; // xmm2
  float v129; // xmm5_4
  float v130; // xmm1_4
  float v131; // xmm10_4
  float v132; // xmm5_4
  float v133; // xmm1_4
  float v134; // xmm10_4
  float v135; // xmm11_4
  float v136; // xmm5_4
  float v137; // xmm10_4
  float v138; // xmm2_4
  float v139; // xmm8_4
  float v140; // xmm1_4
  float v141; // xmm2_4
  unsigned int v142; // xmm8_4
  float v143; // xmm2_4
  float v144; // xmm5_4
  float v145; // xmm0_4
  float v146; // xmm4_4
  __m128 v147; // xmm2
  float v148; // xmm7_4
  UFG::qSafePointerNode<UFG::EncounterBase>Vtbl *v149; // rax
  char v150; // al
  UFG::qVector4 v151; // xmm1
  UFG::qVector4 v152; // xmm1
  bool v154; // [rsp+40h] [rbp-C0h]
  char v155; // [rsp+41h] [rbp-BFh]
  UFG::qVector3 p1; // [rsp+48h] [rbp-B8h]
  UFG::qVector3 position; // [rsp+58h] [rbp-A8h]
  UFG::qVector3 p0; // [rsp+68h] [rbp-98h]
  float laneT; // [rsp+78h] [rbp-88h]
  UFG::qVector3 result; // [rsp+80h] [rbp-80h]
  float v161; // [rsp+90h] [rbp-70h]
  UFG::qVector3 v162; // [rsp+98h] [rbp-68h]
  unsigned int v163; // [rsp+A8h] [rbp-58h]
  float v164; // [rsp+ACh] [rbp-54h]
  int v165; // [rsp+B0h] [rbp-50h]
  float v166; // [rsp+B4h] [rbp-4Ch]
  char v167[64]; // [rsp+C0h] [rbp-40h]
  UFG::qColour colour; // [rsp+100h] [rbp+0h]
  float v169; // [rsp+110h] [rbp+10h]
  float v170; // [rsp+114h] [rbp+14h]
  __int64 v171; // [rsp+118h] [rbp+18h]
  float nearestT; // [rsp+120h] [rbp+20h]
  float v173; // [rsp+124h] [rbp+24h]
  float v174; // [rsp+128h] [rbp+28h]
  UFG::qVector3 *v175; // [rsp+130h] [rbp+30h]
  float v176; // [rsp+138h] [rbp+38h]
  float v177; // [rsp+13Ch] [rbp+3Ch]
  __int64 v178; // [rsp+140h] [rbp+40h]
  UFG::RoadNetworkGraph *v179; // [rsp+148h] [rbp+48h]
  __int64 v180; // [rsp+150h] [rbp+50h]
  __int64 v181; // [rsp+158h] [rbp+58h]
  __int64 *v182; // [rsp+160h] [rbp+60h]
  UFG::qVector3 v183; // [rsp+168h] [rbp+68h]
  float v184; // [rsp+174h] [rbp+74h]
  float v185; // [rsp+178h] [rbp+78h]
  float v186; // [rsp+17Ch] [rbp+7Ch]
  UFG::qVector3 centre; // [rsp+180h] [rbp+80h]
  UFG::qVector3 v188; // [rsp+190h] [rbp+90h]
  UFG::qVector3 v189; // [rsp+1A0h] [rbp+A0h]
  UFG::qVector3 v190; // [rsp+1ACh] [rbp+ACh]
  UFG::qVector3 v191; // [rsp+1B8h] [rbp+B8h]
  UFG::qVector3 v192; // [rsp+1C4h] [rbp+C4h]
  UFG::qVector3 v193; // [rsp+1D0h] [rbp+D0h]
  UFG::qVector3 v194; // [rsp+1DCh] [rbp+DCh]
  UFG::qVector3 v195; // [rsp+1E8h] [rbp+E8h]
  UFG::qVector3 v196; // [rsp+1F4h] [rbp+F4h]
  UFG::RoadNetworkSegment *v197; // [rsp+200h] [rbp+100h]
  __int64 v198; // [rsp+208h] [rbp+108h]
  UFG::RoadNetworkResource *v199; // [rsp+210h] [rbp+110h]
  __int64 v200; // [rsp+218h] [rbp+118h]
  __int64 v201; // [rsp+220h] [rbp+120h]
  __int64 v202[12]; // [rsp+230h] [rbp+130h]
  UFG::EncounterBase *v203; // [rsp+370h] [rbp+270h]
  bool v204; // [rsp+378h] [rbp+278h]

  v204 = enableForwardSpawning;
  v203 = this;
  v7 = UFG::qMatrix44::msIdentity.v1;
  v8 = UFG::qMatrix44::msIdentity.v2;
  v9 = this;
  v10 = pTargetTransform;
  v11 = (UFG::SimObjectGame *)pTargetVehicle;
  v12 = UFG::qMatrix44::msIdentity.v3;
  pTransform->v0 = UFG::qMatrix44::msIdentity.v0;
  pTransform->v1 = v7;
  pTransform->v2 = v8;
  pTransform->v3 = v12;
  *(UFG::qMatrix44 *)v167 = UFG::qMatrix44::msIdentity;
  UFG::PropertySetHandle::Bind(&this->mProperties);
  v13 = v9->mProperties.mpPropSet;
  if ( v9->mFocusTargetContext.mIsInWater )
  {
    UFG::TransformNodeComponent::UpdateWorldTransform(v10);
    v14 = v10->mWorldTransform.v1;
    v15 = v10->mWorldTransform.v2;
    v16 = v10->mWorldTransform.v3;
    pTransform->v0 = v10->mWorldTransform.v0;
    pTransform->v1 = v14;
    pTransform->v2 = v15;
    pTransform->v3 = v16;
    UFG::TransformNodeComponent::UpdateWorldTransform(v10);
    v17 = UFG::qPropertySet::Get<float>(v13, (UFG::qSymbol *)&EncounterSym_water_offset_max_range.mUID, DEPTH_RECURSE);
    v18 = UFG::qPropertySet::Get<float>(v13, (UFG::qSymbol *)&EncounterSym_water_offset_min_range.mUID, DEPTH_RECURSE);
    if ( UFG::SimObjectUtility::FindSpawnBoatPosition((UFG::qVector3 *)&v10->mWorldTransform.v3, *v18, *v17, 1, &p1) )
    {
      v19 = p1.x;
      v20 = p1.y;
      pTransform->v3.w = 1.0;
      LOBYTE(v21) = 1;
      pTransform->v3.x = v19;
      v22 = p1.z;
      pTransform->v3.y = v20;
      pTransform->v3.z = v22;
    }
    else
    {
      LOBYTE(v21) = 0;
    }
    return v21;
  }
  v155 = 0;
  v23 = *(unsigned int *)UFG::qPropertySet::Get<float>(
                           v13,
                           (UFG::qSymbol *)&EncounterSym_vehicle_spawn_behind_probability.mUID,
                           DEPTH_RECURSE);
  if ( v9->mHeatLevel > 0
    && !v9->mFocusTargetContext.mIsOnFootHeuristic
    && (UFG::Metrics::msInstance.mSimTimeMSec - v9->mStartTimestamp < 0x7530
     || !v9->mCoolingDown && !v9->mInsideDynamicRadiusCount)
    && UFG::qRandom(1.0, &UFG::qDefaultSeed) < *(float *)&v23 )
  {
    v24 = UFG::qPropertySet::Get<float>(
            v13,
            (UFG::qSymbol *)&EncounterSym_vehicle_chase_spawn_distance.mUID,
            DEPTH_RECURSE);
    v25 = UFG::VehicleUtility::GetChaseSpawnTransform((UFG::SimObject *)&v11->vfptr, *v24);
    v26 = v25;
    if ( v25 )
    {
      UFG::TransformNodeComponent::UpdateWorldTransform(v25);
      if ( v9->vfptr[57].__vecDelDtor(
             (UFG::qSafePointerNode<UFG::EncounterBase> *)&v9->vfptr,
             (unsigned int)&v26->mWorldTransform) )
      {
        UFG::TransformNodeComponent::UpdateWorldTransform(v26);
        *location_is_on_screen = UFG::SimObjectUtility::IsPositionOnScreen(
                                   (UFG::qVector3 *)&v26->mWorldTransform.v3,
                                   4.0,
                                   0);
        UFG::TransformNodeComponent::UpdateWorldTransform(v26);
        LOBYTE(v21) = 1;
        v27 = v26->mWorldTransform.v1;
        v28 = v26->mWorldTransform.v2;
        v29 = v26->mWorldTransform.v3;
        pTransform->v0 = v26->mWorldTransform.v0;
        pTransform->v1 = v27;
        pTransform->v2 = v28;
        pTransform->v3 = v29;
        return v21;
      }
    }
LABEL_20:
    LOBYTE(v21) = 0;
    return v21;
  }
  v30 = *(unsigned int *)UFG::qPropertySet::Get<float>(
                           v13,
                           (UFG::qSymbol *)&EncounterSym_vehicle_generic_spawn_min_radius.mUID,
                           DEPTH_RECURSE);
  v31 = *(unsigned int *)UFG::qPropertySet::Get<float>(
                           v13,
                           (UFG::qSymbol *)&EncounterSym_vehicle_generic_spawn_max_radius.mUID,
                           DEPTH_RECURSE);
  if ( *(float *)&v31 < 68.0 )
    *(float *)&v31 = FLOAT_68_0;
  if ( v9->mWaveCount <= 1 )
  {
    *(float *)&v30 = *(float *)&v30 * FIRST_WAVE_MODIFIER;
    *(float *)&v31 = *(float *)&v31 * FIRST_WAVE_MODIFIER;
  }
  v32 = UFG::WheeledVehicleNavigationData::GetRoadNetwork(UFG::WheeledVehicleManager::m_Instance->m_NavigationData);
  v199 = v32;
  if ( !v32 )
  {
    printWarning = 0;
    goto LABEL_20;
  }
  v33 = &v9->mFocusTargetPosition.x;
  v175 = &v9->mFocusTargetPosition;
  v34 = UFG::RoadNetworkResource::GetClosestSegment(v32, &v9->mFocusTargetPosition, 0i64, 0);
  nearestT = *(float *)&FLOAT_1_0;
  v197 = v34;
  UFG::RoadNetworkNode::GetClosestPosition(
    (UFG::RoadNetworkNode *)&v34->mType,
    &result,
    &v9->mFocusTargetPosition,
    &nearestT);
  if ( enableDebugDraw )
  {
    v35 = (Render::DebugDrawContext *)Render::DebugDrawManager::GetContext(Render::DebugDrawManager::mInstance, 2u);
    p1.x = result.x;
    p1.y = result.y;
    v36 = v9->mFocusTargetPosition.y;
    v37 = v35;
    p1.z = result.z + 0.5;
    v38 = *v33;
    p0.y = v36;
    p0.x = v38;
    p0.z = v9->mFocusTargetPosition.z + 0.5;
    Render::DebugDrawContext::DrawLine(v35, &p0, &p1, &UFG::qColour::Blue, &UFG::qMatrix44::msIdentity, 0i64, 0);
    v39 = v9->mFocusTargetPosition.y;
    p1.x = *v33;
    v40 = v9->mFocusTargetPosition.z;
    p1.y = v39;
    p1.z = v40 + 0.5;
    Render::DebugDrawContext::DrawSphere(v37, &p1, 0.5, &UFG::qColour::Blue, &UFG::qMatrix44::msIdentity, 0i64);
    p1.x = result.x;
    p1.y = result.y;
    p1.z = result.z + 0.5;
    Render::DebugDrawContext::DrawSphere(v37, &p1, 0.5, &UFG::qColour::Blue, &UFG::qMatrix44::msIdentity, 0i64);
  }
  v41 = v9->mFocusTargetContext.mIsInWater != 0 ? 3 : 0;
  v42 = UFG::WheeledVehicleNavigationData::GetRoadNetworkGraph(
          UFG::WheeledVehicleManager::m_Instance->m_NavigationData,
          (UFG::RoadNetworkNode::RoadNetworkType)v41);
  v179 = v42;
  UFG::VehicleWayFinderClient::SetRoadNetworkType((UFG::VehicleWayFinderClient *)&v9->mWayTraversalClient.vfptr, v41);
  UFG::GetWayTraversal()->pWayGraph = (UFG::WayGraph *)&v42->vfptr;
  v43 = UFG::GetWayTraversal();
  UFG::WayTraversal::FindConnectedEdgesInRange(
    v43,
    &v9->mWayTraversalClient,
    &v9->mFocusTargetPosition,
    &result,
    *(const float *)&v30,
    *(const float *)&v31);
  v44 = UFG::GetWayTraversal();
  UFG::WayTraversal::Service(v44, 0.0);
  *(float *)&v45 = *(float *)&v30 * *(float *)&v30;
  v165 = v45;
  v170 = *(float *)&v31 * *(float *)&v31;
  UFG::TransformNodeComponent::UpdateWorldTransform(v10);
  if ( v11
    && ((v46 = v11->m_Flags, !((v46 >> 14) & 1)) ? ((v46 & 0x8000u) == 0 ? (!((v46 >> 13) & 1) ? (!((v46 >> 12) & 1) ? (v47 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v11->vfptr, UFG::RoadSpaceComponent::_TypeUID)) : (v47 = UFG::SimObjectGame::GetComponentOfTypeHK(v11, UFG::RoadSpaceComponent::_TypeUID))) : (v47 = UFG::SimObjectGame::GetComponentOfTypeHK(v11, UFG::RoadSpaceComponent::_TypeUID))) : (v47 = v11->m_Components.p[24].m_pComponent)) : (v47 = v11->m_Components.p[24].m_pComponent),
        v47) )
  {
    v48 = (float *)&v47[27].m_pSimObject;
  }
  else
  {
    UFG::TransformNodeComponent::UpdateWorldTransform(v10);
    v48 = &v10->mWorldTransform.v0.x;
  }
  v49 = v48[1];
  v50 = (__m128)*(unsigned int *)v48;
  v51 = v48[2];
  v52 = v50;
  v52.m128_f32[0] = (float)((float)(v50.m128_f32[0] * v50.m128_f32[0]) + (float)(v49 * v49)) + (float)(v51 * v51);
  if ( v52.m128_f32[0] == 0.0 )
    v53 = 0.0;
  else
    v53 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v52));
  v54 = v9->mWayTraversalClient.m_NumWayEdges;
  v174 = v53 * v50.m128_f32[0];
  v176 = v53 * v51;
  v169 = v53 * v49;
  v55 = UFG::qRandom(6.2831855, &UFG::qDefaultSeed);
  v177 = sinf(v55);
  v56 = cosf(v55);
  v198 = v54;
  v57 = v9->mFocusTargetContext.mIsInWater == 0;
  v173 = v56;
  v21 = 0i64;
  v164 = FLOAT_N2_0;
  v58 = !v57 + 2;
  v180 = 0i64;
  v163 = !v57 + 2;
  if ( (signed int)v54 > 0 )
  {
    v59 = FLOAT_0_30000001;
    while ( 1 )
    {
      v60 = v9->mWayTraversalClient.aWayNodes[v21];
      v61 = v9->mWayTraversalClient.m_WayEdges[v21];
      if ( !v42->vfptr->IsEdge((UFG::WayGraph *)&v42->vfptr, v60) )
      {
        v62 = v199;
        v63 = UFG::RoadNetworkResource::GetSegment(v199, v61);
        if ( ((unsigned __int8 (__fastcall *)(UFG::EncounterBase *, _QWORD, UFG::RoadNetworkSegment *))v9->vfptr[55].__vecDelDtor)(
               v9,
               v58,
               v63) )
        {
          if ( v60 )
          {
            v64 = v42->vfptr->GetNumEdges((UFG::WayGraph *)&v42->vfptr);
            v65 = UFG::RoadNetworkResource::GetIntersection(v62, (unsigned int)v60 - v64);
          }
          else
          {
            v65 = 0i64;
          }
          v66 = 0;
          if ( v63->mNumGates )
          {
            while ( 1 )
            {
              v67 = UFG::RoadNetworkGate::GetIncomingConnection((UFG::RoadNetworkGate *)v63, v66);
              v68 = (UFG::RoadNetworkGate *)v67;
              v69 = (UFG::RoadNetworkIntersection *)v67->mLaneList.mOffset;
              if ( v69 )
                v69 = (UFG::RoadNetworkIntersection *)((char *)v69 + (_QWORD)v67 + 8);
              if ( v69 == v65 )
                break;
              if ( ++v66 >= (unsigned __int8)v63->mNumGates )
                goto LABEL_149;
            }
            if ( v67 )
            {
              v70 = 0i64;
              v71 = v63 == v197;
              v72 = 0;
              v154 = v63 == v197;
              if ( v68->mNumOutgoingConnections )
              {
                while ( 1 )
                {
                  v73 = UFG::RoadNetworkGate::GetOutgoingConnection(v68, v72);
                  v74 = v73;
                  if ( v73 )
                  {
                    v75 = v73->mConnection.mOffset;
                    if ( v75 && (v76 = (signed __int64)&v74->mConnection + v75) != 0 )
                    {
                      v77 = v76 - (_QWORD)&v178;
                      v178 = v77;
                      if ( v77 )
                      {
                        v78 = (unsigned int *)((char *)&v178 + v77);
                        goto LABEL_62;
                      }
                    }
                    else
                    {
                      v178 = 0i64;
                    }
                  }
                  else
                  {
                    v201 = 0i64;
                  }
                  v78 = 0i64;
LABEL_62:
                  if ( v74 )
                  {
                    if ( v78 )
                    {
                      v79 = 0;
                      if ( *v78 )
                      {
                        do
                        {
                          v80 = 0;
                          if ( v74->mNumLanes )
                          {
                            do
                            {
                              if ( (unsigned int)v70 < 0xC )
                              {
                                v202[v70] = (__int64)UFG::qBezierPathCollectionMemImaged::GetPath(v74, v80);
                                v70 = (unsigned int)(v70 + 1);
                              }
                              ++v80;
                            }
                            while ( v80 < v74->mNumLanes );
                          }
                          ++v79;
                        }
                        while ( v79 < *v78 );
                      }
                    }
                  }
                  if ( ++v72 >= v68->mNumOutgoingConnections )
                  {
                    v71 = v154;
                    break;
                  }
                }
              }
              if ( v71 )
              {
                v81 = 0;
                if ( v68->mNumIncomingConnections )
                {
                  do
                  {
                    v82 = UFG::RoadNetworkGate::GetIncomingConnection(v68, v81);
                    v83 = v82;
                    if ( v82 )
                    {
                      v84 = v82->mConnection.mOffset;
                      if ( v84 && (v85 = (signed __int64)&v83->mConnection + v84) != 0 )
                      {
                        v86 = v85 - (_QWORD)&v171;
                        v171 = v86;
                        if ( v86 )
                        {
                          v87 = (unsigned int *)((char *)&v171 + v86);
                          goto LABEL_82;
                        }
                      }
                      else
                      {
                        v171 = 0i64;
                      }
                    }
                    else
                    {
                      v200 = 0i64;
                    }
                    v87 = 0i64;
LABEL_82:
                    if ( v83 )
                    {
                      if ( v87 )
                      {
                        v88 = 0;
                        if ( *v87 )
                        {
                          do
                          {
                            v89 = 0;
                            if ( v83->mNumLanes )
                            {
                              do
                              {
                                if ( (unsigned int)v70 < 0xC )
                                {
                                  v202[v70] = (__int64)UFG::qBezierPathCollectionMemImaged::GetPath(v83, v89);
                                  v70 = (unsigned int)(v70 + 1);
                                }
                                ++v89;
                              }
                              while ( v89 < v83->mNumLanes );
                            }
                            ++v88;
                          }
                          while ( v88 < *v87 );
                        }
                      }
                    }
                    ++v81;
                  }
                  while ( v81 < v68->mNumIncomingConnections );
                }
              }
              v90 = Render::DebugDrawManager::GetContext(Render::DebugDrawManager::mInstance, 2u);
              *(_QWORD *)&p0.x = 0i64;
              p0.z = 0.0;
              v91 = (Render::DebugDrawContext *)v90;
              if ( (_DWORD)v70 )
              {
                v92 = v202;
                v93 = (unsigned int)v70;
                v182 = v202;
                v181 = (unsigned int)v70;
                while ( 1 )
                {
                  v94 = (UFG::RoadNetworkLane *)*v92;
                  v95 = 0.0;
                  v96 = UFG::RoadNetworkLane::GetLength((UFG::RoadNetworkLane *)*v92);
                  v97 = *(float *)&FLOAT_1_0;
                  v161 = *(float *)&FLOAT_1_0;
                  v166 = 3.0 / v96;
                  if ( (float)(3.0 / v96) >= 1.0 )
                    v166 = *(float *)&FLOAT_1_0;
                  if ( v154
                    && (laneT = 0.0,
                        UFG::RoadNetworkLane::GetNearestPoint(v94, &v162, &result, &laneT),
                        UFG::RoadNetworkLane::GetPos(v94, &p1, laneT),
                        v97 = laneT,
                        v161 = laneT,
                        enableDebugDraw) )
                  {
                    v98 = UFG::RoadNetworkLane::IsReversedInNode(v94);
                    v99 = &v175->x;
                    v100 = &UFG::qColour::White;
                    v101 = v175->y;
                    v193.x = v175->x;
                    v102 = v175->z;
                    v193.y = v101;
                    if ( v98 )
                      v100 = &UFG::qColour::Cyan;
                    v103 = v100->r;
                    v193.z = v102 + 1.0;
                    v196.y = v162.y;
                    colour.r = v103;
                    v104 = v100->g;
                    v196.x = v162.x;
                    colour.g = v104;
                    v105 = v100->b;
                    v196.z = v162.z + 1.0;
                    colour.b = v105;
                    colour.a = v100->a;
                    Render::DebugDrawContext::DrawLine(v91, &v196, &v193, &colour, &UFG::qMatrix44::msIdentity, 0i64, 0);
                    centre.x = v162.x;
                    centre.y = v162.y;
                    centre.z = v162.z + 1.0;
                    Render::DebugDrawContext::DrawSphere(v91, &centre, v59, &colour, &UFG::qMatrix44::msIdentity, 0i64);
                    v195.x = result.x;
                    v195.y = result.y;
                    v195.z = result.z + 1.0;
                    Render::DebugDrawContext::DrawSphere(v91, &v195, v59, &colour, &UFG::qMatrix44::msIdentity, 0i64);
                    v189.x = v162.x;
                    v189.y = v162.y;
                    v189.z = v162.z + 1.0;
                    v183.y = p1.y;
                    v183.x = p1.x;
                    v183.z = p1.z + 1.0;
                    Render::DebugDrawContext::DrawLine(v91, &v183, &v189, &colour, &UFG::qMatrix44::msIdentity, 0i64, 0);
                    v191.x = p1.x;
                    v191.y = p1.y;
                    v191.z = p1.z + 1.0;
                    Render::DebugDrawContext::DrawSphere(v91, &v191, v59, &colour, &UFG::qMatrix44::msIdentity, 0i64);
                  }
                  else
                  {
                    v99 = &v175->x;
                  }
                  v106 = 0.0;
                  if ( v97 > 0.0 )
                    break;
LABEL_144:
                  if ( enableDebugDraw && v95 > 0.0 )
                  {
                    v194.x = p0.x;
                    v194.y = p0.y;
                    v194.z = p0.z + 2.0;
                    Render::DebugDrawContext::DrawLine(
                      v91,
                      &p0,
                      &v194,
                      &UFG::qColour::Green,
                      &UFG::qMatrix44::msIdentity,
                      0i64,
                      0);
                  }
                  ++v92;
                  v181 = --v93;
                  v182 = v92;
                  if ( !v93 )
                    goto LABEL_148;
                }
                while ( 2 )
                {
                  UFG::RoadNetworkLane::GetPos(v94, &position, v106);
                  v108 = (__m128)LODWORD(position.y);
                  v107 = position.x - *v99;
                  v108.m128_f32[0] = position.y - v99[1];
                  v109 = position.z - v99[2];
                  v111 = v108;
                  v110 = (float)((float)(v108.m128_f32[0] * v108.m128_f32[0]) + (float)(v107 * v107))
                       + (float)(v109 * v109);
                  v111.m128_f32[0] = (float)((float)(v108.m128_f32[0] * v108.m128_f32[0]) + (float)(v107 * v107))
                                   + (float)(v109 * v109);
                  if ( v111.m128_f32[0] == 0.0 )
                    v112 = 0.0;
                  else
                    v112 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v111));
                  v113 = v108.m128_f32[0] * v112;
                  v114 = v107 * v112;
                  v115 = v109 * v112;
                  if ( v110 >= *(float *)&v45 )
                  {
                    if ( v110 <= v170 )
                    {
                      if ( v204
                        || (float)((float)((float)(v113 * v169) + (float)(v114 * v174)) + (float)(v115 * v176)) <= -0.1 )
                      {
                        v118 = (float)((float)(v110 - *(float *)&v45) / (float)(v170 - *(float *)&v45))
                             + (float)((float)((float)((float)((float)((float)(v114 * v173) + (float)(v113 * v177))
                                                             + v115)
                                                     + 1.0)
                                             * 0.5)
                                     + 100.0);
                        v119 = UFG::SimObjectUtility::IsPositionOnScreen(&position, 4.0, 0);
                        if ( v119 )
                        {
                          v120 = UFG::Director::Get()->mCurrentCamera;
                          if ( v120 )
                            v120 = (UFG::BaseCameraComponent *)((char *)v120 + 80);
                          if ( (float)((float)((float)((float)(v120->mCamera.mView.v2.y - position.y)
                                                     * (float)(v120->mCamera.mView.v2.y - position.y))
                                             + (float)((float)(v120->mCamera.mView.v2.x - position.x)
                                                     * (float)(v120->mCamera.mView.v2.x - position.x)))
                                     + (float)((float)(v120->mCamera.mView.v2.z - position.z)
                                             * (float)(v120->mCamera.mView.v2.z - position.z))) < 3364.0 )
                            v118 = FLOAT_N99_0;
                        }
                        if ( v118 > v164 )
                        {
                          v121 = (UFG::RoadNetworkNode *)(v94->mNode.mOffset ? (UFG::RoadNetworkLane *)((char *)v94 + v94->mNode.mOffset) : 0i64);
                          UFG::RoadNetworkNode::GetTangent(v121, &v188, v94->mLaneIndex, v106);
                          v122 = (__m128)LODWORD(v188.x);
                          v123 = (__m128)LODWORD(v188.z);
                          v124 = v122;
                          v124.m128_f32[0] = (float)((float)(v122.m128_f32[0] * v122.m128_f32[0])
                                                   + (float)(v188.y * v188.y))
                                           + (float)(v123.m128_f32[0] * v123.m128_f32[0]);
                          v125 = v124.m128_f32[0] == 0.0 ? 0.0 : 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v124));
                          v126 = v188.x * v125;
                          v127 = v188.y * v125;
                          v123.m128_f32[0] = v188.z * v125;
                          v128 = (__m128)LODWORD(UFG::qVector3::msDirUp.x);
                          *(float *)v167 = v188.x * v125;
                          *(float *)&v167[4] = v188.y * v125;
                          *(_QWORD *)&v167[8] = COERCE_UNSIGNED_INT(v188.z * v125);
                          v128.m128_f32[0] = (float)((float)(v128.m128_f32[0] * v128.m128_f32[0])
                                                   + (float)(UFG::qVector3::msDirUp.y * UFG::qVector3::msDirUp.y))
                                           + (float)(UFG::qVector3::msDirUp.z * UFG::qVector3::msDirUp.z);
                          v129 = v128.m128_f32[0] == 0.0 ? 0.0 : 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v128));
                          v130 = v129;
                          v131 = v129;
                          v132 = v129 * UFG::qVector3::msDirUp.z;
                          v133 = v130 * UFG::qVector3::msDirUp.y;
                          v134 = v131 * UFG::qVector3::msDirUp.x;
                          v135 = (float)(v133 * v123.m128_f32[0]) - (float)(v132 * v127);
                          v136 = (float)(v132 * v126) - (float)(v134 * v123.m128_f32[0]);
                          v137 = (float)(v134 * v127) - (float)(v133 * v126);
                          v138 = (float)((float)(v136 * v136) + (float)(v135 * v135)) + (float)(v137 * v137);
                          v139 = v138 == 0.0 ? 0.0 : 1.0 / fsqrt(v138);
                          v140 = v139;
                          v141 = v139;
                          *(float *)&v142 = v139 * v137;
                          v143 = v141 * v135;
                          *(_QWORD *)&v167[24] = v142;
                          *(float *)&v167[16] = v143;
                          *(float *)&v167[20] = v140 * v136;
                          v144 = (float)(v127 * *(float *)&v142) - (float)(v123.m128_f32[0] * (float)(v140 * v136));
                          v145 = v126;
                          v146 = (float)(v126 * *(float *)&v167[20]) - (float)(v127 * v143);
                          v123.m128_f32[0] = (float)(v123.m128_f32[0] * v143) - (float)(v145 * *(float *)&v142);
                          v147 = v123;
                          v147.m128_f32[0] = (float)((float)(v123.m128_f32[0] * v123.m128_f32[0]) + (float)(v144 * v144))
                                           + (float)(v146 * v146);
                          v148 = v147.m128_f32[0] == 0.0 ? 0.0 : 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v147));
                          v149 = v203->vfptr;
                          *(_QWORD *)&v167[48] = *(_QWORD *)&position.x;
                          *(_QWORD *)&v167[56] = __PAIR__(1065353216, LODWORD(position.z));
                          *(float *)&v167[32] = v144 * v148;
                          *(float *)&v167[36] = v123.m128_f32[0] * v148;
                          *(_QWORD *)&v167[40] = COERCE_UNSIGNED_INT(v146 * v148);
                          v150 = (__int64)v149[57].__vecDelDtor(
                                            (UFG::qSafePointerNode<UFG::EncounterBase> *)&v203->vfptr,
                                            (unsigned int)v167);
                          v97 = v161;
                          v45 = v165;
                          if ( v150 )
                          {
                            v151 = *(UFG::qVector4 *)&v167[16];
                            v164 = v118;
                            v155 = 1;
                            pTransform->v0 = *(UFG::qVector4 *)v167;
                            pTransform->v1 = v151;
                            v152 = *(UFG::qVector4 *)&v167[48];
                            pTransform->v2 = *(UFG::qVector4 *)&v167[32];
                            pTransform->v3 = v152;
                            *location_is_on_screen = v119 != 0;
                          }
                        }
                        if ( enableDebugDraw )
                        {
                          v190.x = position.x;
                          v190.y = position.y;
                          v190.z = position.z + 1.0;
                          Render::DebugDrawContext::DrawLine(
                            v91,
                            &position,
                            &v190,
                            &UFG::qColour::Yellow,
                            &UFG::qMatrix44::msIdentity,
                            0i64,
                            0);
                        }
                        if ( v118 > v95 )
                        {
                          v95 = v118;
                          p0 = position;
                        }
                      }
                      else if ( enableDebugDraw )
                      {
                        v184 = position.x;
                        v185 = position.y;
                        v116 = &UFG::qColour::Cyan;
                        v117 = (UFG::qVector3 *)&v184;
                        v186 = position.z + 1.0;
                        goto LABEL_141;
                      }
                      goto LABEL_142;
                    }
                    if ( v110 >= *(float *)&v45 )
                      goto LABEL_142;
                  }
                  if ( enableDebugDraw )
                  {
                    v192.x = position.x;
                    v192.y = position.y;
                    v116 = &UFG::qColour::Red;
                    v117 = &v192;
                    v192.z = position.z + 1.0;
LABEL_141:
                    Render::DebugDrawContext::DrawLine(v91, &position, v117, v116, &UFG::qMatrix44::msIdentity, 0i64, 0);
                  }
LABEL_142:
                  v106 = v106 + v166;
                  if ( v106 >= v97 )
                  {
                    v59 = FLOAT_0_30000001;
                    v92 = v182;
                    v93 = v181;
                    goto LABEL_144;
                  }
                  continue;
                }
              }
LABEL_148:
              v58 = v163;
              v42 = v179;
              v9 = v203;
            }
          }
        }
      }
LABEL_149:
      v21 = v180 + 1;
      v180 = v21;
      if ( v21 >= v198 )
      {
        LOBYTE(v21) = v155;
        return v21;
      }
    }
  }
  return v21;
}

// File Line: 1757
// RVA: 0x3F63A0
UFG::SimComponent *__fastcall UFG::EncounterBase::HandleOnFootSpawn(UFG::EncounterBase *this, UFG::qMatrix44 *pSpawnTransform, UFG::qPropertySet *pGroupPropertySet, UFG::qSymbol *pSpecificCharacterResource)
{
  UFG::qSymbol *v4; // r14
  UFG::qPropertySet *v5; // r13
  UFG::qMatrix44 *v6; // r15
  UFG::EncounterBase *v7; // rdi
  UFG::qPropertySet *v9; // r12
  __int64 v10; // rsi
  UFG::qPropertySet *v11; // rax
  UFG::qPropertyList *v12; // rbx
  unsigned int v13; // eax
  UFG::EncounterBase::ReplenishStyle v14; // edx
  unsigned int v15; // er8
  unsigned int v16; // er9
  unsigned int v17; // ecx
  char *v18; // rax
  UFG::qPropertySet *v19; // rbx
  UFG::ObjectResourceManager *v20; // rax
  __int64 v21; // rdx
  const char *v22; // rax
  UFG::qSymbol *v23; // rax
  UFG::SimComponent *v24; // r14
  UFG::SimObject *v25; // rax
  UFG::SimObjectGame *v26; // rbx
  UFG::PedSpawnManager *v27; // rax
  UFG::TransformNodeComponent *v28; // rax
  UFG::PedSpawnManager *v29; // rax
  unsigned __int16 v30; // cx
  UFG::SimComponent *v31; // rax
  UFG::qMemoryPool *v32; // rax
  UFG::allocator::free_link *v33; // rax
  UFG::SimComponent *v34; // rax
  unsigned __int16 v35; // cx
  unsigned int v36; // er15
  UFG::SimObjectGame *v37; // rcx
  unsigned __int16 v38; // dx
  UFG::SimComponent *v39; // rax
  UFG::qSymbol *v40; // rax
  UFG::qSymbol *v41; // r15
  UFG::GameStatTracker *v42; // rax
  UFG::qSymbol *v43; // rax
  UFG::qSymbol *v44; // r15
  UFG::qPropertySet *v45; // rax
  UFG::SimObjectGame *v46; // rax
  UFG::SimObject *v47; // rsi
  unsigned __int16 v48; // dx
  UFG::RigidBody *v49; // rax
  unsigned __int16 v50; // cx
  UFG::InventoryComponent *v51; // rax
  UFG::SceneObjectProperties *v52; // rax
  UFG::qPropertySet *v53; // r12
  unsigned __int16 v54; // cx
  UFG::TSActorComponent *v55; // r15
  ASymbol *v56; // rax
  UFG::TSActor *v57; // rax
  ASymbol *v58; // rax
  UFG::TSActor *v59; // rax
  UFG::qSymbol *v60; // rax
  UFG::qPropertySet *v61; // rax
  UFG::qSymbol objName; // [rsp+30h] [rbp-40h]
  UFG::qSymbol result[2]; // [rsp+38h] [rbp-38h]
  __int64 v64; // [rsp+40h] [rbp-30h]
  UFG::SimObjectModifier v65; // [rsp+48h] [rbp-28h]
  UFG::qSymbol propSetName; // [rsp+A0h] [rbp+30h]

  v64 = -2i64;
  v4 = pSpecificCharacterResource;
  v5 = pGroupPropertySet;
  v6 = pSpawnTransform;
  v7 = this;
  if ( this->mHumans.size >= 0x20 )
    return 0i64;
  UFG::PropertySetHandle::Bind(&this->mProperties);
  v9 = v7->mProperties.mpPropSet;
  propSetName.mUID = -1;
  v10 = 0i64;
  if ( v5 && v4 )
  {
    propSetName.mUID = v4->mUID;
  }
  else
  {
    v11 = (UFG::qPropertySet *)((__int64 (__fastcall *)(UFG::EncounterBase *))v7->vfptr[33].__vecDelDtor)(v7);
    v12 = UFG::qPropertySet::Get<UFG::qPropertyList>(
            v11,
            (UFG::qSymbol *)&EncounterSym_spawn_groups.mUID,
            DEPTH_RECURSE);
    v13 = 0;
    v14 = v7->mReplenishStyle;
    if ( v14 )
    {
      if ( v14 == 1 )
      {
        v15 = v7->mNumWaveGroupTypes;
        v16 = v15;
        v17 = 0;
        if ( v15 )
        {
          while ( v7->mWaveGroupTypes[v17] != 1 || v7->mWaveGroupInstances[v17] >= v7->mWaveGroupInstancesRequired[v17] )
          {
            if ( ++v17 >= v15 )
              goto LABEL_14;
          }
          v16 = v17;
        }
LABEL_14:
        v13 = 0;
        if ( v16 < v15 )
          v13 = v16;
      }
    }
    else
    {
      v13 = UFG::qPropertyList::GetRandomIndex(v12);
    }
    v18 = UFG::qPropertyList::GetValuePtr(v12, 0x1Au, v13);
    if ( !v18 || (v5 = (UFG::qPropertySet *)&v18[*(_QWORD *)v18], !*(_QWORD *)v18) )
      v5 = 0i64;
    propSetName.mUID = UFG::qPropertySet::Get<UFG::qSymbol>(
                         v5,
                         (UFG::qSymbol *)&EncounterSym_character.mUID,
                         DEPTH_RECURSE)->mUID;
  }
  v19 = UFG::PropertySetManager::GetPropertySet(&propSetName);
  v20 = UFG::ObjectResourceManager::Instance();
  if ( UFG::ObjectResourceManager::IsLoaded(v20, v19) )
    goto LABEL_26;
  if ( !UFG::EncounterBase::sEnableBlockSpawningByResource )
  {
    UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&propSetName);
    UFG::qPrintChannel::Print(
      &UFG::gPrintChannel_HK_Encounters,
      OUTPUT_LEVEL_DEBUG,
      "[Encounters]: This character resource is not loaded yet, you will see invisible (%s)\n");
LABEL_26:
    LOBYTE(v21) = 1;
    v22 = (const char *)v7->vfptr[82].__vecDelDtor((UFG::qSafePointerNode<UFG::EncounterBase> *)&v7->vfptr, v21);
    v23 = UFG::qSymbol::create_from_string(result, v22);
    UFG::SimObjectUtility::GenerateUniqueActorName(&objName, v23);
    v24 = 0i64;
    if ( v6 )
      v25 = UFG::SpawnInfoInterface::SpawnObject(&objName, &propSetName, v6, 0, 0i64, 0i64);
    else
      v25 = UFG::SpawnInfoInterface::SpawnObject(&objName, &propSetName, 0, 0i64, 0i64, 0i64);
    v26 = (UFG::SimObjectGame *)v25;
    if ( v25 )
    {
      UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&v25->m_Name);
      UFG::qPrintChannel::Print(
        &UFG::gPrintChannel_HK_Encounters,
        OUTPUT_LEVEL_DEBUG,
        "[Encounters]: Spawned onfoot unit (%s)\n");
      UFG::PedSpawnManager::AquireOwnership((UFG::SimObject *)&v26->vfptr, 0, 1, -1);
      v27 = UFG::PedSpawnManager::GetInstance();
      UFG::PedSpawnManager::SetSuspendOption(v27, (UFG::SimObject *)&v26->vfptr, NoSuspend);
      v28 = v26->m_pTransformNodeComponent;
      if ( v28 && (v28->m_Flags & 3) != 1 )
      {
        v29 = UFG::PedSpawnManager::GetInstance();
        UFG::PedSpawnManager::ChangeActiveStatusOfSimObj(
          v29,
          Active,
          (UFG::SimObject *)&v26->vfptr,
          "d:\\ufg\\madscience\\project\\sdhd\\sdhd_pc\\source\\ai\\encounters\\encounterbase.cpp",
          1854);
      }
      v30 = v26->m_Flags;
      if ( (v30 >> 14) & 1 )
      {
        v24 = v26->m_Components.p[16].m_pComponent;
      }
      else if ( (v30 & 0x8000u) == 0 )
      {
        if ( (v30 >> 13) & 1 )
        {
          v31 = UFG::SimObjectGame::GetComponentOfTypeHK(v26, UFG::EncounterUnitComponent::_TypeUID);
        }
        else if ( (v30 >> 12) & 1 )
        {
          v31 = UFG::SimObjectGame::GetComponentOfTypeHK(v26, UFG::EncounterUnitComponent::_TypeUID);
        }
        else
        {
          v31 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v26->vfptr, UFG::EncounterUnitComponent::_TypeUID);
        }
        v24 = v31;
      }
      else
      {
        v24 = v26->m_Components.p[16].m_pComponent;
      }
      if ( !v24 )
      {
        v32 = UFG::GetSimulationMemoryPool();
        v33 = UFG::qMemoryPool::Allocate(v32, 0xE0ui64, "EncounterUnitComponent", 0i64, 1u);
        *(_QWORD *)&result[0].mUID = v33;
        if ( v33 )
        {
          UFG::EncounterUnitComponent::EncounterUnitComponent((UFG::EncounterUnitComponent *)v33, v26->mNode.mUID);
          v24 = v34;
        }
        else
        {
          v24 = 0i64;
        }
        v35 = v26->m_Flags;
        if ( (v35 >> 14) & 1 )
        {
          v36 = 16;
        }
        else if ( (v35 & 0x8000u) == 0 )
        {
          v36 = -1;
        }
        else
        {
          v36 = 16;
        }
        UFG::SimObjectModifier::SimObjectModifier(&v65, (UFG::SimObject *)&v26->vfptr, 1);
        UFG::SimObjectModifier::AttachComponent(&v65, v24, v36);
        UFG::SimObjectModifier::Close(&v65);
        UFG::SimObjectModifier::~SimObjectModifier(&v65);
      }
      v7->mHumans.p[v7->mHumans.size++] = (UFG::EncounterUnitComponent *)v24;
      ((void (__fastcall *)(UFG::EncounterBase *, UFG::SimComponent *, UFG::qPropertySet *))v7->vfptr[69].__vecDelDtor)(
        v7,
        v24,
        v5);
      v37 = (UFG::SimObjectGame *)v24->m_pSimObject;
      if ( v37 )
      {
        v38 = v37->m_Flags;
        if ( (v38 >> 14) & 1 )
        {
          v39 = v37->m_Components.p[17].m_pComponent;
        }
        else if ( (v38 & 0x8000u) == 0 )
        {
          if ( (v38 >> 13) & 1 )
            v39 = UFG::SimObjectGame::GetComponentOfTypeHK(v37, UFG::CopUnitComponent::_TypeUID);
          else
            v39 = (v38 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v37, UFG::CopUnitComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v37->vfptr, UFG::CopUnitComponent::_TypeUID);
        }
        else
        {
          v39 = v37->m_Components.p[17].m_pComponent;
        }
        if ( v39 )
          LOBYTE(v39[7].m_Flags) |= 3u;
      }
      v40 = UFG::qPropertySet::Get<UFG::qSymbol>(v9, (UFG::qSymbol *)&qSymbol_EncounterFactionClass.mUID, DEPTH_RECURSE);
      v41 = v40;
      if ( v40 && v40->mUID != -1 )
      {
        v42 = UFG::FactionInterface::Get();
        UFG::FactionInterface::SetFaction(&v42->mFactionInterface, (UFG::SimObject *)&v26->vfptr, v41);
      }
      if ( !*UFG::qPropertySet::Get<bool>(v9, (UFG::qSymbol *)&qSymbol_SuppressWeapon.mUID, DEPTH_RECURSE) )
      {
        v43 = UFG::qPropertySet::Get<UFG::qSymbol>(v5, (UFG::qSymbol *)&EncounterSym_weapon.mUID, DEPTH_RECURSE);
        v44 = v43;
        if ( v43 && v43->mUID != -1 )
        {
          UFG::Simulation::GenerateUniqueName(&UFG::gSim, result, "EncounterWeapon");
          v45 = UFG::PropertySetManager::FindPropertySet(v44);
          if ( v45 )
          {
            v46 = (UFG::SimObjectGame *)UFG::SpawnInfoInterface::SpawnObject(result, v45, 0, 0i64, 0i64, 0i64);
            v47 = (UFG::SimObject *)&v46->vfptr;
            if ( v46 )
            {
              v48 = v46->m_Flags;
              if ( (v48 >> 14) & 1 )
              {
                v49 = (UFG::RigidBody *)UFG::SimObjectGame::GetComponentOfTypeHK(v46, UFG::RigidBodyComponent::_TypeUID);
              }
              else if ( (v48 & 0x8000u) == 0 )
              {
                if ( (v48 >> 13) & 1 )
                {
                  v49 = (UFG::RigidBody *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                            v46,
                                            UFG::RigidBodyComponent::_TypeUID);
                }
                else if ( (v48 >> 12) & 1 )
                {
                  v49 = (UFG::RigidBody *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                            v46,
                                            UFG::RigidBodyComponent::_TypeUID);
                }
                else
                {
                  v49 = (UFG::RigidBody *)UFG::SimObject::GetComponentOfType(
                                            (UFG::SimObject *)&v46->vfptr,
                                            UFG::RigidBodyComponent::_TypeUID);
                }
              }
              else
              {
                v49 = (UFG::RigidBody *)UFG::SimObjectGame::GetComponentOfTypeHK(v46, UFG::RigidBodyComponent::_TypeUID);
              }
              if ( v49 )
                UFG::RigidBody::SetMotionType(v49, 0x100u);
              v50 = v26->m_Flags;
              if ( (v50 >> 14) & 1 )
              {
                v51 = (UFG::InventoryComponent *)v26->m_Components.p[39].m_pComponent;
              }
              else if ( (v50 & 0x8000u) == 0 )
              {
                if ( (v50 >> 13) & 1 )
                {
                  v51 = (UFG::InventoryComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                     v26,
                                                     UFG::InventoryComponent::_TypeUID);
                }
                else if ( (v50 >> 12) & 1 )
                {
                  v51 = (UFG::InventoryComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                     v26,
                                                     UFG::InventoryComponent::_TypeUID);
                }
                else
                {
                  v51 = (UFG::InventoryComponent *)UFG::SimObject::GetComponentOfType(
                                                     (UFG::SimObject *)&v26->vfptr,
                                                     UFG::InventoryComponent::_TypeUID);
                }
              }
              else
              {
                v51 = (UFG::InventoryComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                   v26,
                                                   UFG::InventoryComponent::_TypeUID);
              }
              if ( v51 )
                UFG::InventoryComponent::Equip(v51, v47);
            }
          }
        }
        else
        {
          v52 = v26->m_pSceneObj;
          if ( v52 )
          {
            v53 = v52->mpWritableProperties;
            if ( !v53 )
              v53 = v52->mpConstProperties;
          }
          else
          {
            v53 = 0i64;
          }
          v54 = v26->m_Flags;
          if ( (v54 >> 14) & 1 )
          {
            v55 = (UFG::TSActorComponent *)v26->m_Components.p[4].m_pComponent;
          }
          else if ( (v54 & 0x8000u) == 0 )
          {
            if ( (v54 >> 13) & 1 )
            {
              v55 = (UFG::TSActorComponent *)v26->m_Components.p[3].m_pComponent;
            }
            else if ( (v54 >> 12) & 1 )
            {
              v55 = (UFG::TSActorComponent *)v26->m_Components.p[2].m_pComponent;
            }
            else
            {
              v55 = (UFG::TSActorComponent *)UFG::SimObject::GetComponentOfType(
                                               (UFG::SimObject *)&v26->vfptr,
                                               UFG::TSActorComponent::_TypeUID);
            }
          }
          else
          {
            v55 = (UFG::TSActorComponent *)v26->m_Components.p[4].m_pComponent;
          }
          v56 = (ASymbol *)UFG::qPropertySet::Get<UFG::qSymbol>(
                             v53,
                             (UFG::qSymbol *)&qSymbol_DefaultFirearm.mUID,
                             DEPTH_RECURSE);
          if ( v56 && v56->i_uid != -1 )
          {
            *(_QWORD *)&result[0].mUID = SSSymbol::as_instance(v56);
            v57 = UFG::TSActorComponent::GetActor(v55);
            ((void (__fastcall *)(UFG::TSActor *, UFG::qStaticSymbol *, UFG::qSymbol *, bool, _QWORD, _QWORD))v57->vfptr[1].set_data_by_name)(
              v57,
              &qSymbol_equip_firearm,
              result,
              *(_QWORD *)&result[0].mUID != 0i64,
              0i64,
              0i64);
          }
          v58 = (ASymbol *)UFG::qPropertySet::Get<UFG::qSymbol>(
                             v53,
                             (UFG::qSymbol *)&qSymbol_DefaultMelee.mUID,
                             DEPTH_RECURSE);
          if ( v58 && v58->i_uid != -1 )
          {
            *(_QWORD *)&result[0].mUID = SSSymbol::as_instance(v58);
            v59 = UFG::TSActorComponent::GetActor(v55);
            ((void (__fastcall *)(UFG::TSActor *, UFG::qStaticSymbol *, UFG::qSymbol *, bool, _QWORD, _QWORD))v59->vfptr[1].set_data_by_name)(
              v59,
              &qSymbol_equip_melee,
              result,
              *(_QWORD *)&result[0].mUID != 0i64,
              0i64,
              0i64);
          }
        }
      }
      v60 = UFG::qPropertySet::Get<UFG::qSymbol>(v5, (UFG::qSymbol *)&EncounterSym_helmet.mUID, DEPTH_RECURSE);
      if ( v60 && v60->mUID != -1 )
      {
        v61 = UFG::PropertySetManager::FindPropertySet(v60);
        if ( v61 )
          UFG::SimObjectUtility::CreateAndAttachProp(v61, (UFG::SimObject *)&v26->vfptr, 1);
      }
      v7->vfptr[68].__vecDelDtor((UFG::qSafePointerNode<UFG::EncounterBase> *)&v7->vfptr, (unsigned int)v26);
    }
    else
    {
      UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&propSetName);
      UFG::qPrintChannel::Print(
        &UFG::gPrintChannel_HK_Encounters,
        OUTPUT_LEVEL_DEBUG,
        "[Encounters]: Unable to spawn onfoot unit (%s)\n");
    }
    return v24;
  }
  UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&propSetName);
  UFG::qPrintChannel::Print(
    &UFG::gPrintChannel_HK_Encounters,
    OUTPUT_LEVEL_DEBUG,
    "[Encounters]: Character not spawning, resource not loaded yet (%s)\n");
  return (UFG::SimComponent *)v10;
}
        &UFG::gPrintChannel_HK_Encounters,
        OUTPUT_LEVEL_DEBUG,
        "[Encounters]: Unable to spawn onfoot unit (%s)\n");
    }
    return v24;
  }
  UFG::qSymbol::as_cstr_d

// File Line: 1961
// RVA: 0x3F6BC0
void __fastcall UFG::EncounterBase::HandleOnFootSpawnPost(UFG::EncounterBase *this, UFG::SimObject *pOnFootSpawn)
{
  UFG::SimObjectCVBase *v2; // rdi
  UFG::EncounterBase *v3; // r14
  UFG::eAIObjective v4; // ebp
  unsigned __int16 v5; // dx
  UFG::SimComponent *v6; // rsi
  UFG::SimComponent *v7; // rax
  UFG::qMemoryPool *v8; // rax
  UFG::allocator::free_link *v9; // rax
  UFG::SimComponent *v10; // rax
  unsigned __int16 v11; // cx
  unsigned int v12; // ebx
  UFG::qPropertySet *v13; // r15
  UFG::qPropertySet *v14; // rbx
  UFG::qSymbol *v15; // rax
  unsigned __int16 v16; // cx
  UFG::ActiveAIEntityComponent *v17; // rax
  UFG::ActiveAIEntityComponent *v18; // rbx
  char *v19; // rax
  UFG::CombatRegion *v20; // rdx
  unsigned __int16 v21; // cx
  UFG::TargetingSystemBaseComponent *v22; // rbx
  UFG::SimComponent *v23; // rax
  UFG::SimObject *v24; // rax
  UFG::SimObjectModifier v25; // [rsp+38h] [rbp-40h]
  UFG::allocator::free_link *result; // [rsp+80h] [rbp+8h]

  v2 = (UFG::SimObjectCVBase *)pOnFootSpawn;
  v3 = this;
  v4 = 0;
  if ( !pOnFootSpawn
    || ((v5 = pOnFootSpawn->m_Flags, !((v5 >> 14) & 1)) ? ((v5 & 0x8000u) == 0 ? (!((v5 >> 13) & 1) ? (!((v5 >> 12) & 1) ? (v7 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v2->vfptr, UFG::EncounterUnitComponent::_TypeUID)) : (v7 = UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&v2->vfptr, UFG::EncounterUnitComponent::_TypeUID))) : (v7 = UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&v2->vfptr, UFG::EncounterUnitComponent::_TypeUID)),
                                                                                  v6 = v7) : (v6 = v2->m_Components.p[16].m_pComponent)) : (v6 = v2->m_Components.p[16].m_pComponent),
        !v6) )
  {
    v8 = UFG::GetSimulationMemoryPool();
    v9 = UFG::qMemoryPool::Allocate(v8, 0xE0ui64, "EncounterUnitComponent", 0i64, 1u);
    result = v9;
    if ( v9 )
    {
      UFG::EncounterUnitComponent::EncounterUnitComponent((UFG::EncounterUnitComponent *)v9, v2->mNode.mUID);
      v6 = v10;
    }
    else
    {
      v6 = 0i64;
    }
    v11 = v2->m_Flags;
    if ( (v11 >> 14) & 1 )
    {
      v12 = 16;
    }
    else if ( (v11 & 0x8000u) == 0 )
    {
      v12 = -1;
    }
    else
    {
      v12 = 16;
    }
    UFG::SimObjectModifier::SimObjectModifier(&v25, (UFG::SimObject *)&v2->vfptr, 1);
    UFG::SimObjectModifier::AttachComponent(&v25, v6, v12);
    UFG::SimObjectModifier::Close(&v25);
    UFG::SimObjectModifier::~SimObjectModifier(&v25);
    ((void (__fastcall *)(UFG::EncounterBase *, UFG::SimComponent *, _QWORD))v3->vfptr[69].__vecDelDtor)(v3, v6, 0i64);
  }
  UFG::PropertySetHandle::Bind(&v3->mProperties);
  v13 = v3->mProperties.mpPropSet;
  v14 = UFG::SceneObjectProperties::GetWritableProperties(v2->m_pSceneObj);
  UFG::qPropertySet::Set<bool>(v14, (UFG::qSymbol *)&qSymbol_CanEnterExitVehicle.mUID, 1);
  v15 = UFG::qSymbol::create_from_string((UFG::qSymbol *)&result, "SkipCombatEntry");
  UFG::qPropertySet::Set<bool>(v14, v15, 1);
  v16 = v2->m_Flags;
  if ( (v16 >> 14) & 1 )
  {
    v17 = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>(v2);
  }
  else if ( (v16 & 0x8000u) == 0 )
  {
    if ( (v16 >> 13) & 1 )
    {
      v17 = (UFG::ActiveAIEntityComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                              (UFG::SimObjectGame *)&v2->vfptr,
                                              UFG::ActiveAIEntityComponent::_TypeUID);
    }
    else if ( (v16 >> 12) & 1 )
    {
      v17 = (UFG::ActiveAIEntityComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                              (UFG::SimObjectGame *)&v2->vfptr,
                                              UFG::ActiveAIEntityComponent::_TypeUID);
    }
    else
    {
      v17 = (UFG::ActiveAIEntityComponent *)UFG::SimObject::GetComponentOfType(
                                              (UFG::SimObject *)&v2->vfptr,
                                              UFG::ActiveAIEntityComponent::_TypeUID);
    }
  }
  else
  {
    v17 = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>(v2);
  }
  v18 = v17;
  if ( v17 )
  {
    v19 = UFG::qPropertySet::Get<char const *>(v13, (UFG::qSymbol *)&qSymbol_OverrideAIBehaviour.mUID, DEPTH_RECURSE);
    if ( v19 && *v19 )
      UFG::ActiveAIEntityComponent::SetBehaviourTree(v18, v19);
    v18->m_MaxEngagementDistanceXY = 1000.0;
    v18->m_MaxEngagementDistanceZ = 1000.0;
    if ( v3->mHeatLevel > 0 )
      v4 = v3->mObjective;
    UFG::ActiveAIEntityComponent::SetCurrentObjective(v18, v4, "EncounterBase::HandleOnFootSpawnPost");
    v20 = v3->mpCombatRegion.m_pPointer;
    if ( v20 )
      UFG::AIEntityComponent::SetCombatRegion((UFG::AIEntityComponent *)&v18->vfptr, v20);
  }
  v21 = v2->m_Flags;
  if ( (v21 >> 14) & 1 )
  {
    v22 = (UFG::TargetingSystemBaseComponent *)v2->m_Components.p[20].m_pComponent;
  }
  else if ( (v21 & 0x8000u) == 0 )
  {
    if ( (v21 >> 13) & 1 )
    {
      v23 = UFG::SimObjectGame::GetComponentOfTypeHK(
              (UFG::SimObjectGame *)&v2->vfptr,
              UFG::TargetingSystemBaseComponent::_TypeUID);
    }
    else if ( (v21 >> 12) & 1 )
    {
      v23 = UFG::SimObjectGame::GetComponentOfTypeHK(
              (UFG::SimObjectGame *)&v2->vfptr,
              UFG::TargetingSystemBaseComponent::_TypeUID);
    }
    else
    {
      v23 = UFG::SimObject::GetComponentOfType(
              (UFG::SimObject *)&v2->vfptr,
              UFG::TargetingSystemBaseComponent::_TypeUID);
    }
    v22 = (UFG::TargetingSystemBaseComponent *)v23;
  }
  else
  {
    v22 = (UFG::TargetingSystemBaseComponent *)v2->m_Components.p[20].m_pComponent;
  }
  if ( v22 )
  {
    v24 = (UFG::SimObject *)((__int64 (__fastcall *)(UFG::EncounterBase *))v3->vfptr[18].__vecDelDtor)(v3);
    UFG::TargetingSystemBaseComponent::SetTarget(v22, eTARGET_TYPE_AI_OBJECTIVE, v24);
  }
  if ( v3->mWaveCount <= 1 )
    HIDWORD(v6[2].m_SafePointerList.mNode.mNext) = v6[2].m_TypeUID;
}

// File Line: 2021
// RVA: 0x3F8130
char __fastcall UFG::EncounterBase::IsCorrectResourceType(UFG::EncounterBase *this, UFG::SimObject *pCop)
{
  UFG::SimObject *v2; // rbx
  UFG::SceneObjectProperties *v3; // rax
  UFG::qPropertySet *v4; // rax
  UFG::qPropertyList *v5; // rbp
  UFG::qResourceData *v6; // rax
  unsigned int v7; // edi
  unsigned int v8; // ebx
  UFG::qResourceData *v9; // rsi

  v2 = pCop;
  if ( !pCop )
    return 0;
  v3 = pCop->m_pSceneObj;
  if ( !v3 || !v3->mpWritableProperties && !v3->mpConstProperties )
    return 0;
  v4 = (UFG::qPropertySet *)((__int64 (*)(void))this->vfptr[33].__vecDelDtor)();
  v5 = UFG::qPropertySet::Get<UFG::qPropertyList>(
         v4,
         (UFG::qSymbol *)&EncounterSym_persistent_resources.mUID,
         DEPTH_RECURSE);
  v6 = UFG::SceneObjectProperties::GetArchetypeProperties(v2->m_pSceneObj);
  v7 = v5->mNumElements;
  v8 = 0;
  v9 = v6;
  if ( !v7 )
    return 0;
  while ( UFG::qPropertyList::Get<UFG::qSymbol>(v5, v8)->mUID != *(_DWORD *)&v9->mDebugName[12] )
  {
    if ( ++v8 >= v7 )
      return 0;
  }
  return 1;
}

// File Line: 2054
// RVA: 0x3F6090
float __fastcall UFG::EncounterBase::GetSpawnTimeout(UFG::EncounterBase *this)
{
  ((void (*)(void))this->vfptr[32].__vecDelDtor)();
  return FLOAT_1_2;
}

// File Line: 2070
// RVA: 0x3FA530
void __fastcall UFG::EncounterBase::UpdateOnFootPopulation(UFG::EncounterBase *this, UFG::SimObject *pTarget, UFG::TransformNodeComponent *pTargetTransform)
{
  UFG::TransformNodeComponent *v3; // rsi
  UFG::SimObject *v4; // r14
  UFG::EncounterBase *v5; // rdi
  __int64 v6; // rbx
  unsigned int v7; // eax
  UFG::qSafePointerNode<UFG::EncounterBase>Vtbl *v8; // r10
  unsigned int v9; // ebx
  char v10; // r15
  unsigned int v11; // eax
  signed int v12; // ecx
  UFG::qSafePointerNode<UFG::EncounterBase>Vtbl *v13; // rax
  UFG::qSafePointerNode<UFG::EncounterBase>Vtbl *v14; // rax
  unsigned int v15; // xmm0_4
  UFG::qSafePointerNode<UFG::EncounterBase>Vtbl *v16; // rax
  __int64 v17; // [rsp+10h] [rbp-19h]
  unsigned int v18; // [rsp+18h] [rbp-11h]
  UFG::qVector4 v19; // [rsp+20h] [rbp-9h]
  UFG::qVector4 v20; // [rsp+30h] [rbp+7h]
  UFG::qVector4 v21; // [rsp+40h] [rbp+17h]
  __int64 v22; // [rsp+50h] [rbp+27h]
  unsigned __int64 v23; // [rsp+58h] [rbp+2Fh]
  __int64 v24; // [rsp+90h] [rbp+67h]
  __int64 retaddr; // [rsp+A8h] [rbp+7Fh]

  v3 = pTargetTransform;
  v4 = pTarget;
  v5 = this;
  if ( !this->mFocusTargetContext.mIsInWater )
  {
    v6 = ((__int64 (*)(void))this->vfptr[33].__vecDelDtor)();
    v5->vfptr[35].__vecDelDtor((UFG::qSafePointerNode<UFG::EncounterBase> *)&v5->vfptr, v6);
    v7 = (__int64)v5->vfptr[36].__vecDelDtor((UFG::qSafePointerNode<UFG::EncounterBase> *)&v5->vfptr, v6);
    v8 = v5->vfptr;
    v9 = v7;
    v24 = 0i64;
    if ( ((unsigned __int8 (__fastcall *)(UFG::EncounterBase *, signed __int64, UFG::SimObject *, UFG::TransformNodeComponent *, __int64 *))v8[48].__vecDelDtor)(
           v5,
           1i64,
           v4,
           v3,
           &v24) )
    {
      do
        v5->vfptr[68].__vecDelDtor((UFG::qSafePointerNode<UFG::EncounterBase> *)&v5->vfptr, v24);
      while ( ((unsigned __int8 (__fastcall *)(UFG::EncounterBase *, signed __int64, UFG::SimObject *, UFG::TransformNodeComponent *, __int64 *))v5->vfptr[48].__vecDelDtor)(
                v5,
                1i64,
                v4,
                v3,
                &v24) );
    }
    v10 = ((__int64 (__fastcall *)(UFG::EncounterBase *))v5->vfptr[61].__vecDelDtor)(v5);
    if ( v10 )
    {
      v11 = (__int64)v5->vfptr[44].__vecDelDtor((UFG::qSafePointerNode<UFG::EncounterBase> *)&v5->vfptr, 1u);
      if ( v11 + v9 > 0x20 )
      {
        v12 = 32;
        if ( v11 < 0x20 )
          v12 = v11;
        v9 = 32 - v12;
      }
    }
    if ( v5->mIsReplenishing && v10 && v5->mHumans.size < v9 )
    {
      retaddr = 0i64;
      if ( ((unsigned __int8 (__fastcall *)(UFG::EncounterBase *, signed __int64, UFG::SimObject *, UFG::TransformNodeComponent *, __int64 *))v5->vfptr[48].__vecDelDtor)(
             v5,
             1i64,
             v4,
             v3,
             &retaddr) )
      {
        v13 = v5->vfptr;
        ++v5->mCharacterSpawnCount;
        v13[68].__vecDelDtor((UFG::qSafePointerNode<UFG::EncounterBase> *)&v5->vfptr, retaddr);
      }
      else if ( v5->mSpawnTimeout <= 0.0 )
      {
        UFG::PropertySetHandle::Bind(&v5->mProperties);
        if ( ((unsigned __int8 (__fastcall *)(UFG::EncounterBase *, UFG::qPropertySet *, UFG::TransformNodeComponent *, __int64 *))v5->vfptr[34].__vecDelDtor)(
               v5,
               v5->mProperties.mpPropSet,
               v3,
               &v17) )
        {
          v14 = v5->vfptr;
          v19 = UFG::qMatrix44::msIdentity.v0;
          v20 = UFG::qMatrix44::msIdentity.v1;
          v21 = UFG::qMatrix44::msIdentity.v2;
          v22 = v17;
          v15 = v18;
          v23 = __PAIR__((unsigned int)FLOAT_1_0, v18);
          if ( *(_QWORD *)(((__int64 (__fastcall *)(UFG::EncounterBase *, UFG::qVector4 *, _QWORD, _QWORD, _QWORD, _QWORD, _QWORD, _QWORD, _QWORD, _QWORD, __int64, unsigned __int64))v14[67].__vecDelDtor)(
                             v5,
                             &v19,
                             0i64,
                             0i64,
                             *(_QWORD *)&UFG::qMatrix44::msIdentity.v0.x,
                             *(_QWORD *)&UFG::qMatrix44::msIdentity.v0.z,
                             *(_QWORD *)&UFG::qMatrix44::msIdentity.v1.x,
                             *(_QWORD *)&UFG::qMatrix44::msIdentity.v1.z,
                             *(_QWORD *)&UFG::qMatrix44::msIdentity.v2.x,
                             *(_QWORD *)&UFG::qMatrix44::msIdentity.v2.z,
                             v17,
                             __PAIR__((unsigned int)FLOAT_1_0, v18))
                         + 40) )
          {
            v16 = v5->vfptr;
            ++v5->mCharacterSpawnCount;
            ((void (__fastcall *)(UFG::EncounterBase *))v16[84].__vecDelDtor)(v5);
            LODWORD(v5->mSpawnTimeout) = v15;
          }
        }
      }
    }
  }
}

// File Line: 2142
// RVA: 0x3FB670
void __fastcall UFG::EncounterBase::UpdateVehiclePopulation(UFG::EncounterBase *this, UFG::SimObject *pTargetVehicle, UFG::TransformNodeComponent *pTargetTransform)
{
  UFG::TransformNodeComponent *v3; // rdi
  UFG::SimObject *v4; // r14
  UFG::EncounterBase *v5; // rbx
  __int64 v6; // rax
  unsigned int v7; // eax
  UFG::qSafePointerNode<UFG::EncounterBase>Vtbl *v8; // r9
  unsigned int v9; // ebp
  __int64 v10; // rsi
  UFG::qSafePointerNode<UFG::EncounterBase>Vtbl *v11; // rax
  __int64 v12; // [rsp+50h] [rbp+8h]

  v3 = pTargetTransform;
  v4 = pTargetVehicle;
  v5 = this;
  v6 = ((__int64 (*)(void))this->vfptr[33].__vecDelDtor)();
  v7 = (__int64)v5->vfptr[35].__vecDelDtor((UFG::qSafePointerNode<UFG::EncounterBase> *)&v5->vfptr, v6);
  v8 = v5->vfptr;
  v9 = v7;
  v12 = 0i64;
  v10 = ((__int64 (__fastcall *)(UFG::EncounterBase *))v8[18].__vecDelDtor)(v5);
  while ( ((unsigned __int8 (__fastcall *)(UFG::EncounterBase *, signed __int64, __int64, UFG::TransformNodeComponent *, __int64 *))v5->vfptr[48].__vecDelDtor)(
            v5,
            2i64,
            v10,
            v3,
            &v12) )
    ;
  if ( v5->mIsReplenishing
    && v5->mSpawnTimeout <= 0.0
    && v5->mVehicles.size < 8
    && (unsigned int)v5->vfptr[75].__vecDelDtor((UFG::qSafePointerNode<UFG::EncounterBase> *)&v5->vfptr, 2u) < v9 )
  {
    if ( ((unsigned __int8 (__fastcall *)(UFG::EncounterBase *, UFG::SimObject *, UFG::TransformNodeComponent *))v5->vfptr[66].__vecDelDtor)(
           v5,
           v4,
           v3) )
    {
      v11 = v5->vfptr;
      ++v5->mVehicleSpawnCount;
      ((void (__fastcall *)(UFG::EncounterBase *))v11[84].__vecDelDtor)(v5);
      v5->mSpawnTimeout = 0.0;
    }
  }
}

// File Line: 2178
// RVA: 0x3F70B0
void __fastcall UFG::EncounterBase::HandleVehicleAcquired(UFG::EncounterBase *this, UFG::EncounterUnitComponent *pEncounterUnitComponent, UFG::qPropertySet *pEncounterPropertySet, UFG::qPropertySet *pGroupPropertySet)
{
  UFG::EncounterBase *v4; // rbp
  UFG::SimObjectGame *v5; // rcx
  UFG::EncounterUnitComponent *v6; // rsi
  UFG::qPropertySet *v7; // rdi
  unsigned __int16 v8; // r8
  UFG::SimComponent *v9; // rbx
  UFG::SimComponent *v10; // rax
  float *v11; // rax
  float *v12; // rax
  float *v13; // rax
  float *v14; // rax
  float *v15; // rax

  v4 = this;
  v5 = (UFG::SimObjectGame *)pEncounterUnitComponent->m_pSimObject;
  v6 = pEncounterUnitComponent;
  v7 = pGroupPropertySet;
  if ( !v5 )
    goto LABEL_22;
  v8 = v5->m_Flags;
  if ( (v8 >> 14) & 1 )
    goto LABEL_22;
  if ( (v8 & 0x8000u) == 0 )
  {
    if ( (v8 >> 13) & 1 )
      goto LABEL_22;
    if ( (v8 >> 12) & 1 )
      v10 = UFG::SimObjectGame::GetComponentOfTypeHK(v5, UFG::PhysicsMoverInterface::_TypeUID);
    else
      v10 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v5->vfptr, UFG::PhysicsMoverInterface::_TypeUID);
    v9 = v10;
  }
  else
  {
    v9 = v5->m_Components.p[34].m_pComponent;
  }
  if ( v9 && v7 )
  {
    v11 = UFG::qPropertySet::Get<float>(
            v7,
            (UFG::qSymbol *)&EncounterSym_vehicle_damage_multiplier_world_collision.mUID,
            DEPTH_RECURSE);
    if ( v11 )
      *((float *)&v9[10].m_BoundComponentHandles.mNode.mNext + 1) = *v11;
    v12 = UFG::qPropertySet::Get<float>(
            v7,
            (UFG::qSymbol *)&EncounterSym_vehicle_damage_multiplier_vehicle_collision.mUID,
            DEPTH_RECURSE);
    if ( v12 )
      *(float *)&v9[11].vfptr = *v12;
    v13 = UFG::qPropertySet::Get<float>(
            v7,
            (UFG::qSymbol *)&EncounterSym_vehicle_damage_multiplier_attacks.mUID,
            DEPTH_RECURSE);
    if ( v13 )
      *((float *)&v9[11].vfptr + 1) = *v13;
    v14 = UFG::qPropertySet::Get<float>(
            v7,
            (UFG::qSymbol *)&EncounterSym_vehicle_damage_multiplier_bullets.mUID,
            DEPTH_RECURSE);
    if ( v14 )
      *(float *)&v9[11].m_SafePointerList.mNode.mPrev = *v14;
    v15 = UFG::qPropertySet::Get<float>(
            v7,
            (UFG::qSymbol *)&EncounterSym_vehicle_damage_multiplier_tires.mUID,
            DEPTH_RECURSE);
    if ( v15 )
      *((float *)&v9[11].m_SafePointerList.mNode.mPrev + 1) = *v15;
  }
LABEL_22:
  if ( v4->mWaveCount <= 1 )
    v6->mInsideRadiusTimer = v6->mAcquiredTimer;
}

// File Line: 2220
// RVA: 0x3F7260
char __fastcall UFG::EncounterBase::HandleVehicleSpawn(UFG::EncounterBase *this, UFG::SimObject *pTargetVehicle, UFG::TransformNodeComponent *pTargetTransform)
{
  UFG::SimObjectGame *v3; // r14
  UFG::EncounterBase *v4; // rdi
  UFG::qPropertyList *v5; // r15
  unsigned int v6; // esi
  UFG::EncounterBase::ReplenishStyle v7; // edx
  unsigned int v8; // er8
  unsigned int v9; // er9
  __int64 v10; // rcx
  int v11; // ebx
  unsigned int v12; // eax
  char *v13; // rax
  UFG::qPropertySet *v14; // r12
  UFG::qSymbol *v15; // rbx
  UFG::qSymbolUC *v16; // r13
  bool *v17; // rax
  unsigned __int8 v18; // si
  UFG::qPropertySet *v19; // rbx
  UFG::qPropertySet *v20; // r15
  UFG::ObjectResourceManager *v21; // rax
  UFG::ObjectResourceManager *v22; // rax
  const char *v23; // rax
  UFG::qSymbol *v24; // rax
  UFG::qSymbolUC *v25; // rax
  UFG::qSymbolUC *v26; // r15
  __int64 v27; // rax
  UFG::qPropertySet *v28; // rbx
  UFG::qPropertySet *v29; // rax
  char *v30; // rax
  UFG::qPropertySet *v31; // rdx
  UFG::qPropertySet *v32; // r13
  __int64 v33; // rsi
  float v34; // xmm8_4
  float v35; // xmm7_4
  UFG::SimComponent *v36; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v37; // rcx
  UFG::qPropertySet *v38; // rax
  float v39; // xmm6_4
  UFG::qSymbol *v40; // rax
  UFG::qPropertySet *v41; // r13
  float v42; // xmm6_4
  UFG::TransformNodeComponent *v43; // rbx
  unsigned __int16 v44; // cx
  UFG::SimComponent *v45; // rax
  float *v46; // rax
  float v47; // xmm9_4
  __m128 v48; // xmm10
  float v49; // xmm5_4
  __m128 v50; // xmm2
  float v51; // xmm1_4
  float v52; // xmm5_4
  float v53; // xmm9_4
  float v54; // xmm10_4
  float v55; // xmm12_4
  float v56; // xmm11_4
  __m128 v57; // xmm2
  __m128 v58; // xmm4
  float v59; // xmm2_4
  float v60; // xmm3_4
  UFG::SimComponent *v61; // rsi
  UFG::qMemoryPool *v62; // rax
  UFG::allocator::free_link *v63; // rax
  UFG::SimComponent *v64; // rax
  unsigned __int16 v65; // cx
  unsigned int v66; // ebx
  UFG::SimObjectGame *v67; // rcx
  unsigned __int16 v68; // dx
  UFG::SimComponent *v69; // rax
  UFG::CompositeLookComponent *v70; // rax
  UFG::CompositeLookComponent *v71; // rbx
  UFG::qSymbol v73; // [rsp+40h] [rbp-88h]
  UFG::qSymbol result; // [rsp+44h] [rbp-84h]
  UFG::qPropertySet *v75; // [rsp+48h] [rbp-80h]
  unsigned int v76; // [rsp+50h] [rbp-78h]
  UFG::qSymbol objName; // [rsp+54h] [rbp-74h]
  UFG::qMatrix44 xform; // [rsp+58h] [rbp-70h]
  char v79; // [rsp+148h] [rbp+80h]
  UFG::TransformNodeComponent *v80; // [rsp+158h] [rbp+90h]
  UFG::qSymbol propSetName; // [rsp+160h] [rbp+98h]

  *(_QWORD *)&xform.v1.x = -2i64;
  v3 = (UFG::SimObjectGame *)pTargetVehicle;
  v4 = this;
  *(_QWORD *)&xform.v0.z = 0i64;
  if ( ((unsigned __int8 (__fastcall *)(UFG::EncounterBase *, signed __int64, UFG::SimObject *, UFG::TransformNodeComponent *, float *))this->vfptr[48].__vecDelDtor)(
         this,
         2i64,
         pTargetVehicle,
         pTargetTransform,
         &xform.v0.z) )
  {
    UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)(*(_QWORD *)&xform.v0.z + 72i64));
    UFG::qPrintChannel::Print(
      &UFG::gPrintChannel_HK_Encounters,
      OUTPUT_LEVEL_DEBUG,
      "[Encounters]: Reacquired Vehicle (%s)\n");
    return 1;
  }
  *(_QWORD *)&xform.v0.x = ((__int64 (__fastcall *)(UFG::EncounterBase *))v4->vfptr[33].__vecDelDtor)(v4);
  v5 = UFG::qPropertySet::Get<UFG::qPropertyList>(
         *(UFG::qPropertySet **)&xform.v0.x,
         (UFG::qSymbol *)&EncounterSym_spawn_groups.mUID,
         DEPTH_RECURSE);
  v6 = 0;
  v7 = v4->mReplenishStyle;
  if ( v7 )
  {
    if ( v7 == 1 )
    {
      v8 = v4->mNumWaveGroupTypes;
      v9 = v8;
      v10 = 0i64;
      if ( v8 )
      {
        while ( v4->mWaveGroupTypes[v10] != 2 || v4->mWaveGroupInstances[v10] >= v4->mWaveGroupInstancesRequired[v10] )
        {
          v10 = (unsigned int)(v10 + 1);
          if ( (unsigned int)v10 >= v8 )
            goto LABEL_11;
        }
        v9 = v10;
      }
LABEL_11:
      if ( v9 < v8 )
        v6 = v9;
    }
  }
  else
  {
    v11 = 0;
    while ( 1 )
    {
      v12 = UFG::qPropertyList::GetRandomIndex(v5);
      v6 = v12;
      if ( v4->mWaveGroupTypes[v12] == 2 )
        break;
      if ( ++v11 >= 10 )
      {
        if ( v4->mWaveGroupTypes[v12] != 2 )
          return 0;
        break;
      }
    }
  }
  UFG::PropertySetHandle::Bind(&v4->mProperties);
  v75 = v4->mProperties.mpPropSet;
  v13 = UFG::qPropertyList::GetValuePtr(v5, 0x1Au, v6);
  if ( v13 && *(_QWORD *)v13 )
    v14 = (UFG::qPropertySet *)&v13[*(_QWORD *)v13];
  else
    v14 = 0i64;
  v15 = UFG::qPropertySet::Get<UFG::qSymbol>(v14, (UFG::qSymbol *)&EncounterSym_boat.mUID, DEPTH_RECURSE);
  v16 = (UFG::qSymbolUC *)UFG::qPropertySet::Get<UFG::qSymbol>(
                            v14,
                            (UFG::qSymbol *)&EncounterSym_vehicle.mUID,
                            DEPTH_RECURSE);
  v73.mUID = UFG::qPropertySet::Get<UFG::qSymbol>(v14, (UFG::qSymbol *)&EncounterSym_character.mUID, DEPTH_RECURSE)->mUID;
  if ( v16 )
    v15 = (UFG::qSymbol *)v16;
  propSetName.mUID = v15->mUID;
  v76 = ((__int64 (__fastcall *)(UFG::EncounterBase *, UFG::qPropertySet *, UFG::qSymbol *))v4->vfptr[52].__vecDelDtor)(
          v4,
          v14,
          &propSetName);
  if ( v76 + v4->mHumans.size < 0x20 )
  {
    v17 = UFG::qPropertySet::Get<bool>(
            *(UFG::qPropertySet **)&xform.v0.x,
            (UFG::qSymbol *)&EncounterSym_enable_forward_spawning.mUID,
            DEPTH_RECURSE);
    if ( v17 )
      v18 = *v17;
    else
      v18 = 0;
    if ( v4->mFocusTargetContext.mIsOnFootHeuristic )
    {
      v18 = 1;
    }
    else if ( v4->mEnableWaveTimerChangesByDisabledUnits
           && UFG::Metrics::msInstance.mSimTimeMSec - v4->mStartTimestamp > 0x1D4C0 )
    {
      v18 &= v4->mHasSpawnedInFrontForCurrentWave == 0;
    }
    v19 = UFG::PropertySetManager::GetPropertySet(&propSetName);
    v20 = UFG::PropertySetManager::GetPropertySet(&v73);
    v21 = UFG::ObjectResourceManager::Instance();
    if ( !UFG::ObjectResourceManager::IsLoaded(v21, v19)
      || (v22 = UFG::ObjectResourceManager::Instance(), !UFG::ObjectResourceManager::IsLoaded(v22, v20)) )
    {
      if ( UFG::EncounterBase::sEnableBlockSpawningByResource )
      {
        UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&v73);
        UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&propSetName);
        UFG::qPrintChannel::Print(
          &UFG::gPrintChannel_HK_Encounters,
          OUTPUT_LEVEL_DEBUG,
          "[Encounters]: Not spawning this vehicle, its resource (%s) (%s) not yet loaded\n");
        return 0;
      }
      UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&v73);
      UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&propSetName);
      UFG::qPrintChannel::Print(
        &UFG::gPrintChannel_HK_Encounters,
        OUTPUT_LEVEL_DEBUG,
        "[Encounters]: This vehicle or its character resource is not loaded yet, you will see invisible (%s) (%s)\n");
    }
    v79 = 0;
    if ( !((unsigned __int8 (__fastcall *)(UFG::EncounterBase *, _QWORD, UFG::SimObjectGame *, UFG::TransformNodeComponent *, UFG::qMatrix44 *, char *, _BYTE))v4->vfptr[56].__vecDelDtor)(
            v4,
            v18,
            v3,
            v80,
            &xform,
            &v79,
            0) )
      return 0;
    v23 = (const char *)v4->vfptr[82].__vecDelDtor((UFG::qSafePointerNode<UFG::EncounterBase> *)&v4->vfptr, 0);
    v24 = UFG::qSymbol::create_from_string(&result, v23);
    UFG::SimObjectUtility::GenerateUniqueActorName(&objName, v24);
    v25 = (UFG::qSymbolUC *)UFG::SpawnInfoInterface::SpawnObject(&objName, &propSetName, &xform, 0, 0i64, 0i64);
    v26 = v25;
    if ( !v25 )
    {
      UFG::qSymbol::as_cstr_dbg(v16);
      UFG::qPrintChannel::Print(
        &UFG::gPrintChannel_HK_Encounters,
        OUTPUT_LEVEL_DEBUG,
        "[Encounters]: Unable to spawn vehicle unit (%s)\n");
      return 0;
    }
    UFG::qSymbol::as_cstr_dbg(v25 + 18);
    UFG::qPrintChannel::Print(
      &UFG::gPrintChannel_HK_Encounters,
      OUTPUT_LEVEL_DEBUG,
      "[Encounters]: Spawned vehicle unit (%s)\n");
    v27 = *(_QWORD *)&v26[20].mUID;
    if ( v27 )
    {
      v28 = *(UFG::qPropertySet **)(v27 + 144);
      if ( !v28 )
        v28 = *(UFG::qPropertySet **)(v27 + 152);
    }
    else
    {
      v28 = 0i64;
    }
    v29 = UFG::qPropertySet::Get<UFG::qPropertySet>(
            v28,
            (UFG::qSymbol *)&component_PhysicsMover::sPropertyName.mUID,
            DEPTH_RECURSE);
    if ( v29 )
      v30 = UFG::qPropertySet::GetMemImagePtr(v29);
    else
      v30 = 0i64;
    result.mUID = *((_DWORD *)v30 + 1);
    v32 = UFG::PropertySetManager::FindPropertySet(&result);
    v33 = *(_QWORD *)(*(_QWORD *)&v26[26].mUID + 32i64);
    v34 = 0.0;
    v35 = 0.0;
    if ( !v3 )
      goto LABEL_62;
    v31 = (UFG::qPropertySet *)v3->m_Flags;
    if ( !(((unsigned __int16)v31 >> 14) & 1) )
    {
      if ( (signed __int16)v31 < 0 )
      {
        v36 = v3->m_Components.p[34].m_pComponent;
        goto LABEL_55;
      }
      if ( !(((unsigned __int16)v31 >> 13) & 1) )
      {
        if ( ((unsigned __int16)v31 >> 12) & 1 )
          v36 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::PhysicsMoverInterface::_TypeUID);
        else
          v36 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::PhysicsMoverInterface::_TypeUID);
LABEL_55:
        if ( v36 )
        {
          v37 = v36[10].m_SafePointerList.mNode.mPrev;
LABEL_59:
          if ( v36 && v37 )
            v35 = *((float *)&v37[36].mNext + 1);
LABEL_62:
          if ( v33 && v32 )
          {
            v38 = UFG::PropertySetManager::GetComponentDataPtr<Vehicles_BasePhysicsProperties>(
                    (UFG::PropertySetManager *)v28,
                    v31);
            if ( v38 )
              v39 = *((float *)&v38->mNext + 1);
            else
              v39 = FLOAT_70_0;
            v40 = UFG::qSymbol::create_from_string((UFG::qSymbol *)&xform, "vehicle_initial_speed_ratio");
            v41 = v75;
            v42 = v39 * *UFG::qPropertySet::Get<float>(v75, v40, DEPTH_RECURSE);
            v43 = v80;
            UFG::TransformNodeComponent::UpdateWorldTransform(v80);
            if ( v3
              && ((v44 = v3->m_Flags, !((v44 >> 14) & 1)) ? ((v44 & 0x8000u) == 0 ? (!((v44 >> 13) & 1) ? (!((v44 >> 12) & 1) ? (v45 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::RoadSpaceComponent::_TypeUID)) : (v45 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::RoadSpaceComponent::_TypeUID))) : (v45 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::RoadSpaceComponent::_TypeUID))) : (v45 = v3->m_Components.p[24].m_pComponent)) : (v45 = v3->m_Components.p[24].m_pComponent),
                  v45) )
            {
              v46 = (float *)&v45[27].m_pSimObject;
            }
            else
            {
              UFG::TransformNodeComponent::UpdateWorldTransform(v43);
              v46 = &v43->mWorldTransform.v0.x;
            }
            v47 = v46[1];
            v48 = (__m128)*(unsigned int *)v46;
            v49 = v46[2];
            v50 = v48;
            v50.m128_f32[0] = (float)((float)(v48.m128_f32[0] * v48.m128_f32[0]) + (float)(v47 * v47))
                            + (float)(v49 * v49);
            if ( v50.m128_f32[0] == 0.0 )
              v51 = 0.0;
            else
              v51 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v50));
            v52 = v49 * v51;
            v53 = v47 * v51;
            v54 = v48.m128_f32[0] * v51;
            v55 = xform.v3.z - v43->mWorldTransform.v3.z;
            v56 = xform.v3.y - v43->mWorldTransform.v3.y;
            v57 = (__m128)LODWORD(xform.v3.x);
            v57.m128_f32[0] = xform.v3.x - v43->mWorldTransform.v3.x;
            v58 = v57;
            v58.m128_f32[0] = (float)((float)(v57.m128_f32[0] * v57.m128_f32[0]) + (float)(v56 * v56))
                            + (float)(v55 * v55);
            if ( v58.m128_f32[0] != 0.0 )
              v34 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v58));
            v59 = (float)((float)((float)(v57.m128_f32[0] * v34) * v54) + (float)((float)(v56 * v34) * v53))
                + (float)((float)(v55 * v34) * v52);
            v60 = 1.0 - (float)((float)(v59 + 1.0) * 0.5);
            if ( v60 < 0.1 )
              v60 = FLOAT_0_1;
            if ( v59 > -0.1 )
              v4->mHasSpawnedInFrontForCurrentWave = 1;
            if ( v35 <= v42 )
              v35 = v42;
            UFG::VehicleUtility::OverrideForwardSpeedKPH((UFG::SimObjectVehicle *)v26, v35 * v60);
          }
          else
          {
            v41 = v75;
          }
          v61 = *(UFG::SimComponent **)(*(_QWORD *)&v26[26].mUID + 256i64);
          if ( !v61 )
          {
            v62 = UFG::GetSimulationMemoryPool();
            v63 = UFG::qMemoryPool::Allocate(v62, 0xE0ui64, "EncounterUnitComponent", 0i64, 1u);
            v75 = (UFG::qPropertySet *)v63;
            if ( v63 )
            {
              UFG::EncounterUnitComponent::EncounterUnitComponent((UFG::EncounterUnitComponent *)v63, v26[16].mUID);
              v61 = v64;
            }
            else
            {
              v61 = 0i64;
            }
            v65 = v26[19].mUID;
            if ( (v65 >> 14) & 1 )
            {
              v66 = 16;
            }
            else if ( (v65 & 0x8000u) == 0 )
            {
              v66 = -1;
            }
            else
            {
              v66 = 16;
            }
            UFG::SimObjectModifier::SimObjectModifier((UFG::SimObjectModifier *)&xform.v1.z, (UFG::SimObject *)v26, 1);
            UFG::SimObjectModifier::AttachComponent((UFG::SimObjectModifier *)&xform.v1.z, v61, v66);
            UFG::SimObjectModifier::Close((UFG::SimObjectModifier *)&xform.v1.z);
            UFG::SimObjectModifier::~SimObjectModifier((UFG::SimObjectModifier *)&xform.v1.z);
          }
          if ( ((unsigned __int8 (__fastcall *)(UFG::EncounterBase *, UFG::qMatrix44 *, _QWORD, UFG::qPropertySet *, UFG::qSymbolUC *, UFG::qSymbol *))v4->vfptr[53].__vecDelDtor)(
                 v4,
                 &xform,
                 v76,
                 v14,
                 v26,
                 &v73) )
          {
            v4->mVehicles.p[v4->mVehicles.size++] = (UFG::EncounterUnitComponent *)v61;
            ((void (__fastcall *)(UFG::EncounterBase *, UFG::SimComponent *, UFG::qPropertySet *))v4->vfptr[69].__vecDelDtor)(
              v4,
              v61,
              v14);
            v67 = (UFG::SimObjectGame *)v61->m_pSimObject;
            if ( v67 )
            {
              v68 = v67->m_Flags;
              if ( (v68 >> 14) & 1 )
              {
                v69 = v67->m_Components.p[17].m_pComponent;
              }
              else if ( (v68 & 0x8000u) == 0 )
              {
                if ( (v68 >> 13) & 1 )
                  v69 = UFG::SimObjectGame::GetComponentOfTypeHK(v67, UFG::CopUnitComponent::_TypeUID);
                else
                  v69 = (v68 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v67, UFG::CopUnitComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v67->vfptr, UFG::CopUnitComponent::_TypeUID);
              }
              else
              {
                v69 = v67->m_Components.p[17].m_pComponent;
              }
              if ( v69 )
                LOBYTE(v69[7].m_Flags) |= 3u;
            }
            ((void (__fastcall *)(UFG::EncounterBase *, UFG::SimComponent *, UFG::qPropertySet *, UFG::qPropertySet *))v4->vfptr[81].__vecDelDtor)(
              v4,
              v61,
              v41,
              v14);
            if ( v79 )
            {
              v70 = (UFG::CompositeLookComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                     (UFG::SimObjectGame *)v26,
                                                     UFG::CompositeLookComponent::_TypeUID);
              v71 = v70;
              if ( v70 )
              {
                UFG::CompositeLookComponent::StartFadeIn(v70);
                v71->mSlowFade = 1;
              }
            }
            return 1;
          }
          UFG::qSymbol::as_cstr_dbg(v26 + 18);
          UFG::qPrintChannel::Print(
            &UFG::gPrintChannel_HK_Encounters,
            OUTPUT_LEVEL_DEBUG,
            "[Encounters]: Destroying vehicle unit (%s), because characters were unable to spawn\n");
          UFG::SimObject::Destroy((UFG::SimObject *)v26);
          return 0;
        }
LABEL_58:
        v37 = 0i64;
        goto LABEL_59;
      }
    }
    v36 = 0i64;
    goto LABEL_58;
  }
  return 0;
}

// File Line: 2466
// RVA: 0x3F5E40
__int64 __fastcall UFG::EncounterBase::GetDesiredNumOccupants(UFG::EncounterBase *this, UFG::qPropertySet *pGroupPropertySet, UFG::qSymbol *vehicleResource)
{
  UFG::qPropertySet *v3; // r14
  int v4; // edi
  UFG::qPropertySet *v5; // rbx
  int v6; // esi
  UFG::qPropertySet *v7; // rax
  char *v8; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v9; // rax
  unsigned int *v10; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v11; // rcx
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v12; // rax
  TracksEnumBinding<unsigned long> pTrackEnumBinding; // [rsp+28h] [rbp-28h]

  v3 = pGroupPropertySet;
  v4 = 2;
  v5 = UFG::PropertySetManager::FindPropertySet(vehicleResource);
  v6 = *UFG::qPropertySet::Get<unsigned long>(v5, (UFG::qSymbol *)&qSymbol_SeatCount.mUID, DEPTH_RECURSE);
  v7 = UFG::qPropertySet::Get<UFG::qPropertySet>(
         v5,
         (UFG::qSymbol *)&component_VehicleProperties::sPropertyName.mUID,
         DEPTH_RECURSE);
  if ( v7 )
    v8 = UFG::qPropertySet::GetMemImagePtr(v7);
  else
    v8 = 0i64;
  pTrackEnumBinding.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
  pTrackEnumBinding.mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
  pTrackEnumBinding.m_EnumSymbol.mUID = -1;
  pTrackEnumBinding.m_EnumSymbol.mUID = *((_DWORD *)v8 + 2);
  *(_QWORD *)&pTrackEnumBinding.m_EnumValue = 0i64;
  pTrackEnumBinding.m_uEnumUID = 0;
  if ( UFG::gSimObjectVehicleTypeTracksEnum.m_enumLists.size )
  {
    TracksEnum<unsigned long>::ResolveBinding(&UFG::gSimObjectVehicleTypeTracksEnum, &pTrackEnumBinding);
  }
  else
  {
    v9 = UFG::gSimObjectVehicleTypeTracksEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev;
    UFG::gSimObjectVehicleTypeTracksEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev->mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
    pTrackEnumBinding.mPrev = v9;
    pTrackEnumBinding.mNext = &UFG::gSimObjectVehicleTypeTracksEnum.m_UnresolvedTracksEnumBindingList.mNode;
    UFG::gSimObjectVehicleTypeTracksEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
  }
  if ( pTrackEnumBinding.m_EnumValue == 3 )
    v4 = 4;
  v10 = UFG::qPropertySet::Get<unsigned long>(v3, (UFG::qSymbol *)&EncounterSym_num_passengers.mUID, DEPTH_RECURSE);
  if ( v10 )
  {
    v4 = *v10 + 1;
  }
  else if ( v4 >= v6 )
  {
    v4 = v6;
  }
  v11 = pTrackEnumBinding.mPrev;
  v12 = pTrackEnumBinding.mNext;
  pTrackEnumBinding.mPrev->mNext = pTrackEnumBinding.mNext;
  v12->mPrev = v11;
  return (unsigned int)v4;
}

// File Line: 2507
// RVA: 0x3F3AE0
char __fastcall UFG::EncounterBase::FillVehicleOccupants(UFG::EncounterBase *this, UFG::qMatrix44 *pSpawnTransform, unsigned int desiredNumOccupants, UFG::qPropertySet *pGroupPropertySet, UFG::SimObjectVehicle *pVehicle, UFG::qSymbol *characterResource)
{
  unsigned int v6; // esi
  UFG::EncounterBase *v7; // r12
  __int64 v8; // rax
  UFG::EncounterUnitComponent *v9; // rdi
  UFG::SimObjectCVBase *v10; // rbx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v11; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v12; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v13; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v14; // rax
  UFG::qList<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList,1,0> *v15; // r13
  unsigned __int16 v16; // cx
  UFG::ActiveAIEntityComponent *v17; // rax
  UFG::GroupComponent *v18; // rbp
  UFG::eTargetTypeEnum v19; // er14
  __int64 v20; // rsi
  __int64 v21; // rax
  UFG::EncounterUnitComponent *v22; // rdi
  UFG::SimObjectCVBase *v23; // rbx
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v24; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v25; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v26; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v27; // rax
  unsigned __int16 v28; // cx
  UFG::ActiveAIEntityComponent *v29; // rax
  UFG::GroupComponent *v30; // rdi
  unsigned int v31; // edx
  UFG::qBaseTreeRB *v32; // rbx
  UFG::qPropertySet *v34; // [rsp+78h] [rbp+20h]

  v34 = pGroupPropertySet;
  v6 = desiredNumOccupants;
  v7 = this;
  if ( !pVehicle )
    return 0;
  v8 = ((__int64 (__fastcall *)(UFG::EncounterBase *, UFG::qMatrix44 *, UFG::qPropertySet *, UFG::qSymbol *))this->vfptr[67].__vecDelDtor)(
         this,
         pSpawnTransform,
         pGroupPropertySet,
         characterResource);
  v9 = (UFG::EncounterUnitComponent *)v8;
  v10 = *(UFG::SimObjectCVBase **)(v8 + 40);
  if ( !v10 )
    return 0;
  UFG::VehicleUtility::PlaceCharacterInVehicle(
    *(UFG::SimObjectCharacter **)(v8 + 40),
    pVehicle,
    eTARGET_TYPE_VEHICLE_DRIVER,
    1,
    0,
    0);
  v11 = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v9->mGroupVehicle.mPrev;
  if ( v9->mGroupVehicle.m_pPointer )
  {
    v12 = v11->mPrev;
    v13 = v9->mGroupVehicle.mNext;
    v12->mNext = v13;
    v13->mPrev = v12;
    v11->mPrev = v11;
    v9->mGroupVehicle.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v9->mGroupVehicle.mPrev;
  }
  v9->mGroupVehicle.m_pPointer = (UFG::SimObject *)&pVehicle->vfptr;
  v14 = pVehicle->m_SafePointerList.mNode.mPrev;
  v15 = &pVehicle->m_SafePointerList;
  v14->mNext = v11;
  v11->mPrev = v14;
  v9->mGroupVehicle.mNext = &pVehicle->m_SafePointerList.mNode;
  pVehicle->m_SafePointerList.mNode.mPrev = v11;
  UFG::EncounterUnitComponent::IncrementGroupVehicleUsageCount(v9);
  v16 = v10->m_Flags;
  if ( (v16 >> 14) & 1 )
  {
    v17 = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>(v10);
  }
  else if ( (v16 & 0x8000u) == 0 )
  {
    if ( (v16 >> 13) & 1 )
    {
      v17 = (UFG::ActiveAIEntityComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                              (UFG::SimObjectGame *)&v10->vfptr,
                                              UFG::ActiveAIEntityComponent::_TypeUID);
    }
    else if ( (v16 >> 12) & 1 )
    {
      v17 = (UFG::ActiveAIEntityComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                              (UFG::SimObjectGame *)&v10->vfptr,
                                              UFG::ActiveAIEntityComponent::_TypeUID);
    }
    else
    {
      v17 = (UFG::ActiveAIEntityComponent *)UFG::SimObject::GetComponentOfType(
                                              (UFG::SimObject *)&v10->vfptr,
                                              UFG::ActiveAIEntityComponent::_TypeUID);
    }
  }
  else
  {
    v17 = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>(v10);
  }
  if ( v17 )
    v18 = v17->m_pGroupComponent.m_pPointer;
  else
    v18 = 0i64;
  v19 = 5;
  if ( v6 > 1 )
  {
    v20 = v6 - 1;
    do
    {
      v21 = ((__int64 (__fastcall *)(UFG::EncounterBase *, _QWORD, UFG::qPropertySet *, UFG::qSymbol *))v7->vfptr[67].__vecDelDtor)(
              v7,
              0i64,
              v34,
              characterResource);
      v22 = (UFG::EncounterUnitComponent *)v21;
      v23 = *(UFG::SimObjectCVBase **)(v21 + 40);
      if ( v23 )
      {
        UFG::VehicleUtility::PlaceCharacterInVehicle(*(UFG::SimObjectCharacter **)(v21 + 40), pVehicle, v19, 1, 0, 0);
        v24 = &v22->mGroupVehicle;
        if ( v22->mGroupVehicle.m_pPointer )
        {
          v25 = v24->mPrev;
          v26 = v22->mGroupVehicle.mNext;
          v25->mNext = v26;
          v26->mPrev = v25;
          v24->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v24->mPrev;
          v22->mGroupVehicle.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v22->mGroupVehicle.mPrev;
        }
        v22->mGroupVehicle.m_pPointer = (UFG::SimObject *)&pVehicle->vfptr;
        v27 = v15->mNode.mPrev;
        v27->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v24->mPrev;
        v24->mPrev = v27;
        v22->mGroupVehicle.mNext = &v15->mNode;
        v15->mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v24->mPrev;
        UFG::EncounterUnitComponent::IncrementGroupVehicleUsageCount(v22);
        v28 = v23->m_Flags;
        if ( (v28 >> 14) & 1 )
        {
          v29 = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>(v23);
        }
        else if ( (v28 & 0x8000u) == 0 )
        {
          if ( (v28 >> 13) & 1 )
          {
            v29 = (UFG::ActiveAIEntityComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                    (UFG::SimObjectGame *)&v23->vfptr,
                                                    UFG::ActiveAIEntityComponent::_TypeUID);
          }
          else if ( (v28 >> 12) & 1 )
          {
            v29 = (UFG::ActiveAIEntityComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                    (UFG::SimObjectGame *)&v23->vfptr,
                                                    UFG::ActiveAIEntityComponent::_TypeUID);
          }
          else
          {
            v29 = (UFG::ActiveAIEntityComponent *)UFG::SimObject::GetComponentOfType(
                                                    (UFG::SimObject *)&v23->vfptr,
                                                    UFG::ActiveAIEntityComponent::_TypeUID);
          }
        }
        else
        {
          v29 = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>(v23);
        }
        if ( v29 )
          v30 = v29->m_pGroupComponent.m_pPointer;
        else
          v30 = 0i64;
        if ( v18 && v30 )
        {
          UFG::PropertySetHandle::Bind(&v7->mProperties);
          v31 = UFG::qPropertySet::Get<UFG::qSymbol>(
                  v7->mProperties.mpPropSet,
                  (UFG::qSymbol *)&EncounterSym_group_formation.mUID,
                  DEPTH_RECURSE)->mUID;
          if ( v31 )
            v32 = UFG::qBaseTreeRB::Get(&UFG::PedFormationManagerComponent::s_Profiles.mTree, v31);
          else
            v32 = 0i64;
          if ( !UFG::GroupComponent::JoinExistingGroup(v30, v18, (UFG::PedFormationProfile *)v32) )
            UFG::GroupComponent::JoinNewGroup(v30, v18, (UFG::PedFormationProfile *)v32);
        }
      }
      ++v19;
      --v20;
    }
    while ( v20 );
  }
  return 1;
}32);
        }
      }
      ++v19;
      --v20;
    }
    while ( v20 );
  }
  return 1;
}

// File Line: 2575
// RVA: 0x3F6000
float __fastcall UFG::EncounterBase::GetHeatRadius(UFG::EncounterBase *this, __int64 isOnfoot, UFG::EncounterUnitComponent *pEncounterUnitComponent)
{
  char v3; // si
  UFG::EncounterBase *v4; // rdi
  __int128 v5; // xmm6
  UFG::qStaticSymbol *v6; // rdx

  v3 = isOnfoot;
  v4 = this;
  if ( this->mInstantCooldownActive )
  {
    LODWORD(v5) = 0;
  }
  else
  {
    UFG::PropertySetHandle::Bind(&this->mProperties);
    v6 = &EncounterSym_heat_radius_vehicle;
    if ( v3 )
      v6 = &EncounterSym_heat_radius_onfoot;
    v5 = *(unsigned int *)UFG::qPropertySet::Get<float>(
                            v4->mProperties.mpPropSet,
                            (UFG::qSymbol *)&v6->mUID,
                            DEPTH_RECURSE);
  }
  if ( ((unsigned __int8 (__fastcall *)(UFG::EncounterBase *, __int64, UFG::EncounterUnitComponent *))v4->vfptr[16].__vecDelDtor)(
         v4,
         isOnfoot,
         pEncounterUnitComponent) )
  {
    *(float *)&v5 = *(float *)&v5 * v4->mReducedRadiusPercentage;
  }
  return *(float *)&v5;
}

// File Line: 2587
// RVA: 0x3F96A0
void __fastcall UFG::EncounterBase::SetSecondaryTarget(UFG::EncounterBase *this, UFG::SimObject *pTarget)
{
  UFG::EncounterBase *v2; // rbx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v3; // r9
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v4; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v5; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::SimObjectGame *v7; // rcx
  unsigned __int16 v8; // dx
  UFG::SimComponent *v9; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v10; // rdx
  UFG::SimObject *v11; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v12; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v13; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v14; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v15; // rax

  v2 = this;
  if ( this->mpSecondaryTarget.m_pPointer != pTarget )
  {
    v3 = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&this->mpSecondaryTarget.mPrev;
    if ( this->mpSecondaryTarget.m_pPointer )
    {
      v4 = v3->mPrev;
      v5 = this->mpSecondaryTarget.mNext;
      v4->mNext = v5;
      v5->mPrev = v4;
      v3->mPrev = v3;
      this->mpSecondaryTarget.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&this->mpSecondaryTarget.mPrev;
    }
    this->mpSecondaryTarget.m_pPointer = pTarget;
    if ( pTarget )
    {
      v6 = pTarget->m_SafePointerList.mNode.mPrev;
      v6->mNext = v3;
      v3->mPrev = v6;
      this->mpSecondaryTarget.mNext = &pTarget->m_SafePointerList.mNode;
      pTarget->m_SafePointerList.mNode.mPrev = v3;
    }
    v7 = (UFG::SimObjectGame *)this->mFocusTargetContext.mpVehicle;
    if ( v7 )
    {
      v8 = v7->m_Flags;
      if ( (v8 >> 14) & 1 )
      {
        v9 = v7->m_Components.p[24].m_pComponent;
      }
      else if ( (v8 & 0x8000u) == 0 )
      {
        if ( (v8 >> 13) & 1 )
          v9 = UFG::SimObjectGame::GetComponentOfTypeHK(v7, UFG::RoadSpaceComponent::_TypeUID);
        else
          v9 = (v8 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v7, UFG::RoadSpaceComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v7->vfptr, UFG::RoadSpaceComponent::_TypeUID);
      }
      else
      {
        v9 = v7->m_Components.p[24].m_pComponent;
      }
      if ( v9 )
      {
        v10 = v9[26].m_BoundComponentHandles.mNode.mPrev;
        if ( v10 )
        {
          v11 = v2->mpSecondaryTarget.m_pPointer;
          v12 = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v10[1].mNext;
          if ( v12[1].mPrev )
          {
            v13 = v12->mPrev;
            v14 = v12->mNext;
            v13->mNext = v14;
            v14->mPrev = v13;
            v12->mPrev = v12;
            v12->mNext = v12;
          }
          v12[1].mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)v11;
          if ( v11 )
          {
            v15 = v11->m_SafePointerList.mNode.mPrev;
            v15->mNext = v12;
            v12->mPrev = v15;
            v12->mNext = &v11->m_SafePointerList.mNode;
            v11->m_SafePointerList.mNode.mPrev = v12;
          }
        }
      }
    }
  }
}

// File Line: 2605
// RVA: 0x3FC290
void __fastcall UFG::EncounterBase::VisualizeNearByRoads(UFG::EncounterBase *this, UFG::qPropertySet *pProperties, UFG::TransformNodeComponent *pTargetTransform)
{
  char v3; // ST30_1
  __int64 v4; // [rsp+40h] [rbp-48h]
  __int64 v5; // [rsp+90h] [rbp+8h]

  v3 = 1;
  ((void (__fastcall *)(UFG::EncounterBase *, _QWORD, UFG::SimObject *, UFG::TransformNodeComponent *, __int64 *, __int64 *, char))this->vfptr[56].__vecDelDtor)(
    this,
    0i64,
    this->mFocusTargetContext.mpVehicle,
    pTargetTransform,
    &v4,
    &v5,
    v3);
}

// File Line: 2612
// RVA: 0x3FC190
void __fastcall UFG::EncounterBase::VisualizeFocusTargetContext(UFG::EncounterBase *this)
{
  UFG::EncounterBase *v1; // rbx
  const char *v2; // rdx
  const char *v3; // rdx
  Render::DebugDrawContext *v4; // rbx
  UFG::qString v5; // [rsp+38h] [rbp-60h]
  UFG::qString v6; // [rsp+60h] [rbp-38h]

  v1 = this;
  v2 = "on land";
  if ( this->mFocusTargetContext.mIsInWater )
    v2 = "in open water";
  UFG::qString::qString(&v6, v2);
  v3 = "outside";
  if ( v1->mFocusTargetContext.mIsInsideInterior )
    v3 = "inside";
  UFG::qString::qString(&v5, v3);
  v4 = (Render::DebugDrawContext *)Render::DebugDrawManager::GetContext(Render::DebugDrawManager::mInstance, 1u);
  Render::DebugDrawContext::DrawTextA(v4, 60, 300, &UFG::qColour::Green, "(Player is %s)", v6.mData, -2i64);
  Render::DebugDrawContext::DrawTextA(v4, 60, 315, &UFG::qColour::Green, "(Player is %s)", v5.mData);
  UFG::qString::~qString(&v5);
  UFG::qString::~qString(&v6);
}

// File Line: 2622
// RVA: 0x3FC2D0
void __fastcall UFG::EncounterBase::VisualizeRoles(UFG::EncounterBase *this)
{
  UFG::EncounterBase *v1; // rsi
  Render::DebugDrawContext *v2; // r14
  unsigned int v3; // edi
  UFG::EncounterUnitComponent *v4; // rbp
  UFG::SimObjectCVBase *v5; // rcx
  unsigned __int16 v6; // dx
  UFG::ActiveAIEntityComponent *v7; // rax
  UFG::GroupComponent *v8; // rbx
  bool v9; // bp
  UFG::GroupComponent *v10; // rax
  UFG::qColour *v11; // r9
  float v12; // xmm2_4
  UFG::qColour *v13; // r9
  UFG::qVector3 result; // [rsp+40h] [rbp-68h]
  UFG::qVector3 p0; // [rsp+50h] [rbp-58h]

  v1 = this;
  v2 = (Render::DebugDrawContext *)Render::DebugDrawManager::GetContext(Render::DebugDrawManager::mInstance, 2u);
  v3 = 0;
  if ( v1->mHumans.size )
  {
    do
    {
      v4 = v1->mHumans.p[v3];
      v5 = (UFG::SimObjectCVBase *)v4->m_pSimObject;
      if ( v5 )
      {
        v6 = v5->m_Flags;
        if ( (v6 >> 14) & 1 )
        {
          v7 = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>(v5);
        }
        else if ( (v6 & 0x8000u) == 0 )
        {
          if ( (v6 >> 13) & 1 )
            v7 = (UFG::ActiveAIEntityComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                   (UFG::SimObjectGame *)&v5->vfptr,
                                                   UFG::ActiveAIEntityComponent::_TypeUID);
          else
            v7 = (UFG::ActiveAIEntityComponent *)((v6 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                     (UFG::SimObjectGame *)&v5->vfptr,
                                                                     UFG::ActiveAIEntityComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v5->vfptr, UFG::ActiveAIEntityComponent::_TypeUID));
        }
        else
        {
          v7 = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>(v5);
        }
        if ( v7 )
        {
          v8 = v7->m_pGroupComponent.m_pPointer;
          if ( v8 )
          {
            UFG::GroupComponent::GetPosition(v7->m_pGroupComponent.m_pPointer, &result);
            v9 = v4->mRole == 1;
            result.z = result.z + 0.5;
            v10 = UFG::GroupComponent::GetSharedGroupComponent(v8);
            if ( v10 == v8 )
            {
              v11 = &UFG::qColour::Blue;
              v12 = FLOAT_0_5;
              if ( v9 )
                v11 = &UFG::qColour::ForestGreen;
            }
            else
            {
              UFG::GroupComponent::GetPosition(v10, &p0);
              p0.z = p0.z + 0.5;
              Render::DebugDrawContext::DrawLine(
                v2,
                &p0,
                &result,
                &UFG::qColour::Yellow,
                &UFG::qMatrix44::msIdentity,
                0i64,
                0);
              v12 = FLOAT_0_30000001;
              v11 = &UFG::qColour::Yellow;
            }
            Render::DebugDrawContext::DrawSphere(v2, &result, v12, v11, &UFG::qMatrix44::msIdentity, 0i64);
            v13 = &UFG::qColour::Yellow;
            if ( v9 )
              v13 = &UFG::qColour::ForestGreen;
            Render::DebugDrawContext::DrawLine(
              v2,
              &v1->mFocusTargetPosition,
              &result,
              v13,
              &UFG::qMatrix44::msIdentity,
              0i64,
              0);
          }
        }
      }
      ++v3;
    }
    while ( v3 < v1->mHumans.size );
  }
}

// File Line: 2656
// RVA: 0x3FB920
__int64 __fastcall UFG::EncounterBase::VisualizeEncounterUnitsInfo(UFG::EncounterBase *this, int x, int startY)
{
  int v3; // er12
  int v4; // er13
  UFG::EncounterBase *v5; // r14
  Render::DebugDrawContext *v6; // rsi
  int v7; // ebp
  UFG::qPropertySet *v8; // r15
  const char *v9; // rsi
  const char *v10; // rdi
  int v11; // ebx
  int v12; // eax
  const char *v13; // rdx
  int v14; // eax
  __int64 v15; // ST38_8
  __int64 v16; // ST30_8
  __int64 v17; // ST28_8
  double v18; // xmm2_8
  const char *v19; // rcx
  const char *v20; // rax
  const char *v21; // ST28_8
  unsigned int v22; // er12
  unsigned int v23; // ebx
  UFG::qColour *v24; // rdi
  const char *v25; // rcx
  int v26; // ebp
  __int64 v27; // rax
  UFG::EncounterUnitComponent *v28; // rsi
  UFG::SimObject *v29; // rbx
  char *v30; // rax
  char v31; // r15
  UFG::SimObjectCVBase *v32; // rcx
  UFG::ActiveAIEntityComponent *v33; // rax
  unsigned __int16 v34; // dx
  __int64 v35; // r13
  float v36; // xmm8_4
  float v37; // xmm7_4
  unsigned __int16 v38; // cx
  UFG::AiDriverComponent *v39; // rax
  unsigned __int16 v40; // cx
  UFG::SimComponent *v41; // rax
  float v42; // xmm6_4
  UFG::qColour *v43; // rdi
  char *v44; // rbx
  double v45; // xmm6_8
  double v46; // xmm7_8
  double v47; // xmm8_8
  char *v48; // rax
  signed int v49; // er10
  const char *v50; // ST40_8
  UFG::EncounterUnitComponent *v51; // rsi
  UFG::qSymbolUC *v52; // rbx
  char *v53; // rax
  char v54; // r15
  UFG::qColour *v55; // rdi
  char *v56; // rbx
  double v57; // xmm6_8
  char *v58; // rax
  signed int v59; // er8
  __int64 v61; // [rsp+30h] [rbp-118h]
  __int64 v62; // [rsp+30h] [rbp-118h]
  __int64 v63; // [rsp+38h] [rbp-110h]
  __int64 v64; // [rsp+40h] [rbp-108h]
  __int64 v65; // [rsp+48h] [rbp-100h]
  Render::DebugDrawContext *v66; // [rsp+70h] [rbp-D8h]
  UFG::qString v67; // [rsp+80h] [rbp-C8h]
  int xa; // [rsp+158h] [rbp+10h]
  int v69; // [rsp+160h] [rbp+18h]
  int v70; // [rsp+168h] [rbp+20h]

  v69 = startY;
  xa = x;
  v3 = startY;
  v4 = x;
  v5 = this;
  v6 = (Render::DebugDrawContext *)Render::DebugDrawManager::GetContext(Render::DebugDrawManager::mInstance, 1u);
  v66 = v6;
  v7 = v3;
  if ( UFG::EncounterBase::sVisualizeWavesInfo )
  {
    v8 = (UFG::qPropertySet *)((__int64 (__fastcall *)(UFG::EncounterBase *))v5->vfptr[33].__vecDelDtor)(v5);
    if ( v8 )
    {
      v9 = "No";
      v10 = "No";
      if ( v5->mIsReplenishing )
        v10 = "Yes";
      v11 = (__int64)v5->vfptr[36].__vecDelDtor(
                       (UFG::qSafePointerNode<UFG::EncounterBase> *)&v5->vfptr,
                       (unsigned int)v8);
      v12 = (__int64)v5->vfptr[35].__vecDelDtor(
                       (UFG::qSafePointerNode<UFG::EncounterBase> *)&v5->vfptr,
                       (unsigned int)v8);
      v13 = "By Wave";
      if ( v5->mReplenishStyle == ReplenishStyle_TopUpByPopulation )
        v13 = "By Population";
      LODWORD(v65) = v5->mNumDesiredCharacterGroups;
      LODWORD(v64) = v11;
      LODWORD(v63) = v5->mNumDesiredVehicleGroups;
      LODWORD(v61) = v12;
      Render::DebugDrawContext::DrawTextA(
        v66,
        v4,
        v3,
        &UFG::qColour::White,
        "Style:%15s  DesiredVehicleGroups:%d/%d  DesiredFootGroups:%d/%d  IsReplenishing:%s",
        v13,
        v61,
        v63,
        v64,
        v65,
        v10);
      v14 = ((__int64 (__fastcall *)(UFG::EncounterBase *))v5->vfptr[31].__vecDelDtor)(v5);
      LODWORD(v15) = v5->mCharacterKillCount;
      LODWORD(v16) = v5->mVehicleKillCount;
      LODWORD(v17) = v14;
      Render::DebugDrawContext::DrawTextA(
        v66,
        v4,
        v3 + 10,
        &UFG::qColour::White,
        "KillCount:%d (Vehicles:%d, Characters:%d)",
        v17,
        v16,
        v15);
      v18 = *UFG::qPropertySet::Get<float>(v8, (UFG::qSymbol *)&EncounterSym_cooldown_timer.mUID, DEPTH_RECURSE);
      v19 = "No";
      if ( v5->mCoolingDown )
        v19 = "Yes";
      v20 = "No";
      if ( v5->mCooldownAllowed )
        v20 = "Yes";
      if ( v5->mInstantCooldownActive )
        v9 = "Yes";
      v21 = v9;
      v6 = v66;
      Render::DebugDrawContext::DrawTextA(
        v66,
        v4,
        v3 + 20,
        &UFG::qColour::White,
        "InstantCooldownActive:%s  IsCoolDownAllowed:%s  IsCoolingDown:%s (%.2f/%.2f)",
        v21,
        v20,
        v19,
        (float)(UFG::Metrics::msInstance.mSimTime_Temp - v5->mNonEventfulCooldownTimestamp),
        v18);
      v7 = v3 + 30;
    }
    v22 = 0;
    v23 = 0;
    if ( v5->mNumWaveGroupTypes )
    {
      v24 = &UFG::qColour::White;
      if ( v5->mWaveGroupInstances >= v5->mWaveGroupInstancesRequired )
        v24 = &UFG::qColour::Green;
      do
      {
        v25 = "CharacterGroup";
        if ( v5->mWaveGroupTypes[v23] == 2 )
          v25 = "VehicleGroup";
        LODWORD(v63) = v5->mWaveGroupInstancesRequired[v23];
        LODWORD(v61) = v5->mWaveGroupInstances[v23];
        Render::DebugDrawContext::DrawTextA(v6, v4, v7, v24, "Type:%s  Instances:%d/%d", v25, v61, v63);
        v7 += 10;
        ++v23;
      }
      while ( v23 < v5->mNumWaveGroupTypes );
      v22 = 0;
    }
    Render::DebugDrawContext::DrawTextA(
      v6,
      v4,
      v7,
      &UFG::qColour::White,
      "%20s - Type  Role  Engaged   %35s  [Ref]WaveType  FlipTimer",
      "Name",
      "Objective");
    v26 = v7 + 10;
    v27 = 0i64;
    v70 = 0;
    if ( v5->mHumans.size )
    {
      while ( 1 )
      {
        v28 = v5->mHumans.p[v27];
        v29 = v28->m_pSimObject;
        UFG::qString::qString(&v67);
        v30 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&v29->m_Name);
        UFG::qString::Format(&v67, "%20s", v30);
        UFG::qString::operator+=(&v67, " - Char");
        if ( v28->mRole == 1 )
          v31 = 69;
        else
          v31 = v28->mRole == 2 ? 83 : 78;
        v32 = (UFG::SimObjectCVBase *)v28->m_pSimObject;
        if ( v32 )
        {
          v34 = v32->m_Flags;
          if ( (v34 >> 14) & 1 )
          {
            v33 = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>(v32);
          }
          else if ( (v34 & 0x8000u) == 0 )
          {
            if ( (v34 >> 13) & 1 )
              v33 = (UFG::ActiveAIEntityComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                      (UFG::SimObjectGame *)&v32->vfptr,
                                                      UFG::ActiveAIEntityComponent::_TypeUID);
            else
              v33 = (UFG::ActiveAIEntityComponent *)((v34 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                         (UFG::SimObjectGame *)&v32->vfptr,
                                                                         UFG::ActiveAIEntityComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v32->vfptr, UFG::ActiveAIEntityComponent::_TypeUID));
          }
          else
          {
            v33 = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>(v32);
          }
        }
        else
        {
          v33 = 0i64;
        }
        v35 = v33->m_CurrentObjective;
        v36 = FLOAT_N1_0;
        v37 = FLOAT_N1_0;
        if ( !v29 )
          break;
        v38 = v29->m_Flags;
        if ( (v38 >> 14) & 1 )
        {
          v39 = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>((UFG::SimObjectCVBase *)v29);
        }
        else if ( (v38 & 0x8000u) == 0 )
        {
          if ( (v38 >> 13) & 1 )
          {
            v39 = (UFG::AiDriverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                              (UFG::SimObjectGame *)v29,
                                              UFG::AiDriverComponent::_TypeUID);
          }
          else if ( (v38 >> 12) & 1 )
          {
            v39 = (UFG::AiDriverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                              (UFG::SimObjectGame *)v29,
                                              UFG::AiDriverComponent::_TypeUID);
          }
          else
          {
            v39 = (UFG::AiDriverComponent *)UFG::SimObject::GetComponentOfType(v29, UFG::AiDriverComponent::_TypeUID);
          }
        }
        else
        {
          v39 = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>((UFG::SimObjectCVBase *)v29);
        }
        if ( v39 )
          v36 = v39->m_fDesiredSpeed * 3.5999999;
        v40 = v29->m_Flags;
        if ( (v40 >> 14) & 1 )
          break;
        if ( (v40 & 0x8000u) == 0 )
        {
          if ( (v40 >> 13) & 1 )
            break;
          v41 = (v40 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                    (UFG::SimObjectGame *)v29,
                                    UFG::PhysicsMoverInterface::_TypeUID) : UFG::SimObject::GetComponentOfType(
                                                                              v29,
                                                                              UFG::PhysicsMoverInterface::_TypeUID);
        }
        else
        {
          v41 = v29->m_Components.p[34].m_pComponent;
        }
        if ( !v41 )
          break;
        v37 = *((float *)&v41[10].m_BoundComponentHandles.mNode.mPrev + 1) * 3.5999999;
        if ( v37 <= 0.0 )
          break;
        v42 = v37 / v36;
LABEL_61:
        v43 = &UFG::qColour::White;
        if ( *(_DWORD *)((__int64 (__fastcall *)(UFG::EncounterBase *))v5->vfptr[26].__vecDelDtor)(v5) == v28->mWaveType.mUID )
          v43 = &UFG::qColour::Yellow;
        v44 = v67.mData;
        v45 = v42;
        v46 = v37;
        v47 = v36;
        v48 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&v28->mWaveType);
        v49 = 78;
        if ( v28->mEngaged )
          v49 = 89;
        LODWORD(v65) = v28->mUsageCount;
        v50 = UFG::AIObjectiveNames[v35];
        LODWORD(v63) = v49;
        LODWORD(v62) = v31;
        v4 = xa;
        Render::DebugDrawContext::DrawTextA(
          v66,
          xa,
          v26,
          v43,
          "%s  %c      %c        %35s  [%3d]%s  %03.2f   %03.2f   %03.2f",
          v44,
          v62,
          v63,
          v50,
          v65,
          v48,
          v47,
          v46,
          v45);
        v26 += 10;
        UFG::qString::~qString(&v67);
        v27 = (unsigned int)(v70 + 1);
        v70 = v27;
        if ( (unsigned int)v27 >= v5->mHumans.size )
          goto LABEL_66;
      }
      v42 = 0.0;
      goto LABEL_61;
    }
LABEL_66:
    if ( v5->mVehicles.size )
    {
      do
      {
        v51 = v5->mVehicles.p[v22];
        v52 = (UFG::qSymbolUC *)v51->m_pSimObject;
        UFG::qString::qString(&v67);
        v53 = UFG::qSymbol::as_cstr_dbg(v52 + 18);
        UFG::qString::Format(&v67, "%20s", v53);
        UFG::qString::operator+=(&v67, " - Vehi");
        if ( v51->mRole == 1 )
        {
          v54 = 69;
        }
        else if ( v51->mRole == 2 )
        {
          v54 = 83;
        }
        else
        {
          v54 = 78;
        }
        v55 = &UFG::qColour::White;
        if ( *(_DWORD *)((__int64 (__fastcall *)(UFG::EncounterBase *))v5->vfptr[26].__vecDelDtor)(v5) == v51->mWaveType.mUID )
          v55 = &UFG::qColour::Yellow;
        v56 = v67.mData;
        v57 = v51->mVehicleFlipTimer;
        v58 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&v51->mWaveType);
        v59 = 78;
        if ( v51->mEngaged )
          v59 = 89;
        LODWORD(v65) = v51->mUsageCount;
        LODWORD(v63) = v59;
        LODWORD(v62) = v54;
        Render::DebugDrawContext::DrawTextA(
          v66,
          v4,
          v26,
          v55,
          "%s  %c      %c        %35s  [%3d]%s  %.2f",
          v56,
          v62,
          v63,
          &customWorldMapCaption,
          v65,
          v58,
          v57);
        v26 += 10;
        UFG::qString::~qString(&v67);
        ++v22;
      }
      while ( v22 < v5->mVehicles.size );
    }
    v7 = v26 + 20;
    v3 = v69;
  }
  return (unsigned int)(v7 - v3);
}      %c        %35s  [%3d]%s  %.2f",
          v56,
          v62,
          v63,
          &customWorldMapCaption,
          v65,
          v58,
          v57);
        v26 += 10;

// File Line: 2810
// RVA: 0x3F9A10
void __fastcall UFG::EncounterBase::Update(UFG::EncounterBase *this, float deltaTime)
{
  UFG::EncounterBase *v2; // rbx
  float v3; // xmm7_4
  __int64 v4; // rax
  __int64 v5; // rdi
  UFG::qVector3 *v6; // rdi
  float v7; // xmm0_4
  float v8; // xmm1_4
  UFG::qSafePointerNode<UFG::EncounterBase>Vtbl *v9; // rax
  UFG::SimObject *v10; // rax

  v2 = this;
  v3 = deltaTime;
  UFG::OnlineManager::Instance();
  v4 = ((__int64 (__fastcall *)(UFG::EncounterBase *))v2->vfptr[18].__vecDelDtor)(v2);
  if ( v4 && (v5 = *(_QWORD *)(v4 + 88)) != 0 )
  {
    UFG::TransformNodeComponent::UpdateWorldTransform(*(UFG::TransformNodeComponent **)(v4 + 88));
    v6 = (UFG::qVector3 *)(v5 + 176);
  }
  else
  {
    v6 = &UFG::qVector3::msZero;
  }
  v7 = v6->y;
  v8 = v6->z;
  v2->mFocusTargetPosition.x = v6->x;
  v9 = v2->vfptr;
  v2->mFocusTargetPosition.y = v7;
  v2->mFocusTargetPosition.z = v8;
  v10 = (UFG::SimObject *)((__int64 (__fastcall *)(UFG::EncounterBase *))v9[18].__vecDelDtor)(v2);
  UFG::EncounterUnitContext::Update(&v2->mFocusTargetContext, v10, v3);
  ((void (__fastcall *)(UFG::EncounterBase *))v2->vfptr[38].__vecDelDtor)(v2);
  ((void (__fastcall *)(UFG::EncounterBase *))v2->vfptr[40].__vecDelDtor)(v2);
  ((void (__fastcall *)(UFG::EncounterBase *))v2->vfptr[39].__vecDelDtor)(v2);
  ((void (__fastcall *)(UFG::EncounterBase *))v2->vfptr[76].__vecDelDtor)(v2);
  ((void (__fastcall *)(UFG::EncounterBase *))v2->vfptr[41].__vecDelDtor)(v2);
  ((void (__fastcall *)(UFG::EncounterBase *))v2->vfptr[83].__vecDelDtor)(v2);
}

// File Line: 2842
// RVA: 0x3F36D0
void __usercall UFG::EncounterBase::CountInsideRadiusObjects(UFG::EncounterBase *this@<rcx>, float a2@<xmm0>)
{
  __int64 v2; // r15
  UFG::EncounterBase *v3; // rbx
  unsigned int i; // er12
  UFG::EncounterUnitComponent *v5; // rsi
  UFG::SimObjectGame *v6; // rcx
  __int64 v7; // rdx
  UFG::SimComponent *v8; // rcx
  UFG::SimComponent *v9; // rax
  UFG::SimObject *v10; // rax
  float v11; // xmm6_4
  UFG::TransformNodeComponent *v12; // r14
  unsigned int j; // edi
  UFG::EncounterUnitComponent *v14; // rcx
  UFG::SimObject *v15; // rax
  UFG::TransformNodeComponent *v16; // rbp
  UFG::EncounterUnitComponent *v17; // rdi
  UFG::SimObject *v18; // rsi
  float v19; // xmm6_4
  UFG::TransformNodeComponent *v20; // rsi
  float v21; // xmm1_4

  v2 = 0i64;
  v3 = this;
  this->mInsideDynamicRadiusCount = 0;
  for ( i = 0; i < v3->mHumans.size; ++i )
  {
    v5 = v3->mHumans.p[i];
    v6 = (UFG::SimObjectGame *)v5->m_pSimObject;
    if ( v6 )
    {
      v7 = v6->m_Flags;
      if ( ((unsigned __int16)v7 >> 14) & 1 )
      {
        v8 = v6->m_Components.p[44].m_pComponent;
      }
      else
      {
        if ( (v7 & 0x8000u) == 0i64 )
        {
          if ( ((unsigned __int16)v7 >> 13) & 1 )
            v9 = UFG::SimObjectGame::GetComponentOfTypeHK(v6, UFG::CharacterOccupantComponent::_TypeUID);
          else
            v9 = ((unsigned __int16)v7 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                      v6,
                                                      UFG::CharacterOccupantComponent::_TypeUID) : UFG::SimObject::GetComponentOfType(
                                                                                                     (UFG::SimObject *)&v6->vfptr,
                                                                                                     UFG::CharacterOccupantComponent::_TypeUID);
        }
        else
        {
          v9 = UFG::SimObjectGame::GetComponentOfTypeHK(v6, UFG::CharacterOccupantComponent::_TypeUID);
        }
        v8 = v9;
      }
      LOBYTE(v7) = v8 == 0i64;
      ((void (__fastcall *)(UFG::EncounterBase *, __int64, UFG::EncounterUnitComponent *))v3->vfptr[17].__vecDelDtor)(
        v3,
        v7,
        v5);
      v10 = v5->m_pSimObject;
      v11 = a2 * a2;
      if ( v10 )
      {
        v12 = v10->m_pTransformNodeComponent;
        if ( v12 )
        {
          UFG::TransformNodeComponent::UpdateWorldTransform(v10->m_pTransformNodeComponent);
          a2 = (float)(v3->mFocusTargetPosition.x - v12->mWorldTransform.v3.x)
             * (float)(v3->mFocusTargetPosition.x - v12->mWorldTransform.v3.x);
          if ( (float)((float)((float)(v3->mFocusTargetPosition.y - v12->mWorldTransform.v3.y)
                             * (float)(v3->mFocusTargetPosition.y - v12->mWorldTransform.v3.y))
                     + a2) < v11 )
          {
            if ( v5->mInsideRadiusTimer < 0.0 )
              v5->mInsideRadiusTimer = v5->mAcquiredTimer;
            ++v3->mInsideDynamicRadiusCount;
            v5->mEngaged = 1;
          }
          if ( v5->mInsideRadiusTimer < 0.0 )
          {
            for ( j = 0; j < v3->mVehicles.size; ++j )
            {
              v14 = v3->mVehicles.p[j];
              if ( v14 )
              {
                if ( v14->mInsideRadiusTimer >= 0.0 )
                {
                  v15 = v14->m_pSimObject;
                  if ( v15 )
                  {
                    v16 = v15->m_pTransformNodeComponent;
                    if ( v16 )
                    {
                      UFG::TransformNodeComponent::UpdateWorldTransform(v15->m_pTransformNodeComponent);
                      a2 = (float)(v12->mWorldTransform.v3.x - v16->mWorldTransform.v3.x)
                         * (float)(v12->mWorldTransform.v3.x - v16->mWorldTransform.v3.x);
                      if ( (float)((float)((float)(v12->mWorldTransform.v3.y - v16->mWorldTransform.v3.y)
                                         * (float)(v12->mWorldTransform.v3.y - v16->mWorldTransform.v3.y))
                                 + a2) < v11 )
                        v5->mInsideRadiusTimer = v5->mAcquiredTimer;
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  if ( v3->mVehicles.size > 0 )
  {
    do
    {
      v17 = v3->mVehicles.p[v2];
      if ( v17->m_pSimObject )
      {
        ((void (__fastcall *)(UFG::EncounterBase *, _QWORD, UFG::EncounterUnitComponent *))v3->vfptr[17].__vecDelDtor)(
          v3,
          0i64,
          v3->mVehicles.p[v2]);
        v18 = v17->m_pSimObject;
        v19 = a2 * a2;
        if ( v18 )
        {
          v20 = v18->m_pTransformNodeComponent;
          if ( v20 )
          {
            UFG::TransformNodeComponent::UpdateWorldTransform(v20);
            a2 = (float)(v3->mFocusTargetPosition.x - v20->mWorldTransform.v3.x)
               * (float)(v3->mFocusTargetPosition.x - v20->mWorldTransform.v3.x);
            v21 = (float)((float)(v3->mFocusTargetPosition.y - v20->mWorldTransform.v3.y)
                        * (float)(v3->mFocusTargetPosition.y - v20->mWorldTransform.v3.y))
                + a2;
            if ( v21 < v19 )
            {
              if ( v17->mInsideRadiusTimer < 0.0 )
                v17->mInsideRadiusTimer = v17->mAcquiredTimer;
              if ( v21 < 900.0 )
                v17->mEngaged = 1;
            }
          }
        }
      }
      v2 = (unsigned int)(v2 + 1);
    }
    while ( (unsigned int)v2 < v3->mVehicles.size );
  }
}

// File Line: 2931
// RVA: 0x3FB440
void __fastcall UFG::EncounterBase::UpdateSpawnTimeout(UFG::EncounterBase *this, float deltaTime)
{
  float v2; // xmm0_4

  if ( this->mIsReplenishing )
  {
    v2 = this->mSpawnTimeout - deltaTime;
    if ( v2 <= 0.0 )
      v2 = 0.0;
    this->mSpawnTimeout = v2;
  }
}

// File Line: 2939
// RVA: 0x3FA320
void __fastcall UFG::EncounterBase::UpdateHeatTimer(UFG::EncounterBase *this, float deltaTime, float currentTime)
{
  float v3; // xmm0_4
  float v4; // xmm6_4
  UFG::EncounterBase *v5; // rdi
  float v6; // xmm0_4
  bool v7; // zf
  UFG::qPropertySet *v8; // rax
  float *v9; // rax
  float v10; // xmm0_4
  UFG::qSafePointerNode<UFG::EncounterBase>Vtbl *v11; // rax
  UFG::qPropertySet *v12; // rax
  UFG::qPropertySet *v13; // rax
  float v14; // xmm0_4
  float v15; // xmm0_4

  v3 = this->mReducedRadiusTimer;
  v4 = 0.0;
  v5 = this;
  this->mCoolingDown = 0;
  v6 = v3 - deltaTime;
  if ( v6 <= 0.0 )
    v6 = 0.0;
  v7 = this->mHeatLevel == 0;
  this->mReducedRadiusTimer = v6;
  if ( !v7 )
  {
    if ( this->mIsReplenishing && this->mReplenishTimeout > 0.0 )
    {
      v8 = (UFG::qPropertySet *)((__int64 (*)(void))this->vfptr[33].__vecDelDtor)();
      v9 = UFG::qPropertySet::Get<float>(v8, (UFG::qSymbol *)&EncounterSym_heatwave_timer.mUID, DEPTH_RECURSE);
      v10 = v5->mReplenishTimeout - deltaTime;
      v5->mWaveTimer = *v9;
      if ( v10 <= 0.0 )
        v10 = 0.0;
      v5->mReplenishTimeout = v10;
    }
    else if ( !((unsigned int (*)(void))this->vfptr[32].__vecDelDtor)() )
    {
      goto LABEL_11;
    }
    v5->mCooldownAllowed = 0;
  }
LABEL_11:
  UFG::PropertySetHandle::Bind(&v5->mProperties);
  if ( *UFG::qPropertySet::Get<bool>(
          v5->mProperties.mpPropSet,
          (UFG::qSymbol *)&EncounterSym_show_blip_radius.mUID,
          DEPTH_RECURSE) )
  {
    if ( v5->mCooldownAllowed )
    {
      v5->mCoolingDown = 1;
    }
    else
    {
      v11 = v5->vfptr;
      v5->mCooldownAllowed = 1;
      v12 = (UFG::qPropertySet *)((__int64 (__fastcall *)(UFG::EncounterBase *))v11[33].__vecDelDtor)(v5);
      v5->mNonEventfulCooldownTimestamp = UFG::Metrics::msInstance.mSimTime_Temp
                                        + *UFG::qPropertySet::Get<float>(
                                             v12,
                                             (UFG::qSymbol *)&EncounterSym_cooldown_timer.mUID,
                                             DEPTH_RECURSE);
    }
  }
  else
  {
    v5->mCooldownAllowed = 0;
  }
  if ( v5->mInstantCooldownActive )
    *(_WORD *)&v5->mCoolingDown = 257;
  if ( v5->mCooldownAllowed && v5->mCoolingDown && currentTime > v5->mNonEventfulCooldownTimestamp )
  {
    v5->mHeatLevel = 0;
    v5->mStartTimestamp = UFG::Metrics::msInstance.mSimTimeMSec;
    v13 = (UFG::qPropertySet *)((__int64 (__fastcall *)(UFG::EncounterBase *))v5->vfptr[33].__vecDelDtor)(v5);
    if ( v13 )
      v4 = *UFG::qPropertySet::Get<float>(v13, (UFG::qSymbol *)&EncounterSym_cooldown_timer.mUID, DEPTH_RECURSE);
    v5->mNonEventfulCooldownTimestamp = UFG::Metrics::msInstance.mSimTime_Temp + v4;
  }
  else if ( !v5->mIsReplenishing )
  {
    v14 = v5->mWaveTimer;
    if ( v14 != -1.0 )
    {
      v15 = v14 - deltaTime;
      v5->mWaveTimer = v15;
      if ( v15 <= 0.0 )
        ((void (__fastcall *)(UFG::EncounterBase *))v5->vfptr[23].__vecDelDtor)(v5);
    }
  }
}

// File Line: 3037
// RVA: 0x3F7EE0
bool __fastcall UFG::EncounterBase::IsAlive(UFG::EncounterBase *this, UFG::EncounterUnitComponent *pEncounterUnitComponent)
{
  UFG::SimObjectGame *v2; // rcx
  unsigned __int16 v3; // dx
  UFG::SimComponent *v4; // rax
  bool result; // al

  v2 = (UFG::SimObjectGame *)pEncounterUnitComponent->m_pSimObject;
  result = 0;
  if ( v2 )
  {
    v3 = v2->m_Flags;
    if ( (v3 >> 14) & 1 )
    {
      v4 = v2->m_Components.p[6].m_pComponent;
    }
    else if ( (v3 & 0x8000u) == 0 )
    {
      if ( (v3 >> 13) & 1 )
        v4 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::HealthComponent::_TypeUID);
      else
        v4 = (v3 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::HealthComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v2->vfptr, UFG::HealthComponent::_TypeUID);
    }
    else
    {
      v4 = v2->m_Components.p[6].m_pComponent;
    }
    if ( v4 && !BYTE4(v4[1].m_BoundComponentHandles.mNode.mPrev) )
      result = 1;
  }
  return result;
}

// File Line: 3047
// RVA: 0x3F8530
bool __fastcall UFG::EncounterBase::IsInFight(UFG::EncounterBase *this, UFG::EncounterUnitComponent *pEncounterUnitComponent)
{
  UFG::EncounterBase *v2; // r14
  UFG::SimObjectGame *v3; // rcx
  UFG::EncounterUnitComponent *v4; // rdi
  unsigned __int16 v5; // r8
  UFG::PhysicsMoverInterface *v6; // rsi
  UFG::SimComponent *v7; // rax
  bool result; // al
  int v9; // er14
  int v10; // ebp
  int i; // edi
  bool v12; // al
  UFG::SimObjectGame *v13; // rcx
  UFG::SimComponent *v14; // rbx
  unsigned __int16 v15; // dx
  UFG::SimComponent *v16; // rax

  v2 = this;
  v3 = (UFG::SimObjectGame *)pEncounterUnitComponent->m_pSimObject;
  v4 = pEncounterUnitComponent;
  if ( !v3 )
    goto LABEL_23;
  v5 = v3->m_Flags;
  if ( (v5 >> 14) & 1 )
    goto LABEL_23;
  if ( (v5 & 0x8000u) == 0 )
  {
    if ( (v5 >> 13) & 1 )
      goto LABEL_23;
    v7 = (v5 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::PhysicsMoverInterface::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::PhysicsMoverInterface::_TypeUID);
    v6 = (UFG::PhysicsMoverInterface *)v7;
  }
  else
  {
    v6 = (UFG::PhysicsMoverInterface *)v3->m_Components.p[34].m_pComponent;
  }
  if ( !v6 )
  {
LABEL_23:
    v13 = (UFG::SimObjectGame *)v4->m_pSimObject;
    if ( v13 )
    {
      v15 = v13->m_Flags;
      if ( (v15 >> 14) & 1 )
      {
        v14 = v13->m_Components.p[5].m_pComponent;
      }
      else if ( (v15 & 0x8000u) == 0 )
      {
        if ( (v15 >> 13) & 1 )
        {
          v16 = UFG::SimObjectGame::GetComponentOfTypeHK(v13, UFG::AIScriptInterfaceComponent::_TypeUID);
        }
        else if ( (v15 >> 12) & 1 )
        {
          v16 = UFG::SimObjectGame::GetComponentOfTypeHK(v13, UFG::AIScriptInterfaceComponent::_TypeUID);
        }
        else
        {
          v16 = UFG::SimObject::GetComponentOfType(
                  (UFG::SimObject *)&v13->vfptr,
                  UFG::AIScriptInterfaceComponent::_TypeUID);
        }
        v14 = v16;
      }
      else
      {
        v14 = v13->m_Components.p[5].m_pComponent;
      }
    }
    else
    {
      v14 = 0i64;
    }
    if ( (unsigned __int8)v2->vfptr[77].__vecDelDtor(
                            (UFG::qSafePointerNode<UFG::EncounterBase> *)&v2->vfptr,
                            (unsigned int)v4)
      && v14
      && !((_QWORD)v14[32].m_BoundComponentHandles.mNode.mPrev & 0x20) )
    {
      return 1;
    }
    return 0;
  }
  if ( v4->mVehicleFlipTimer >= 2.0 || v4->mUnitDisabled )
    return 0;
  v9 = v6->mNumWheels;
  if ( !v9 )
    goto LABEL_41;
  v10 = 0;
  for ( i = 0; i < v9; v10 += v12 != 0 )
    v12 = UFG::PhysicsMoverInterface::IsTireBlown(v6, i++);
  if ( v10 >= v9 / 2 || v10 >= 1 && UFG::PhysicsMoverInterface::GetLinearVelocityMagnitudeKPH(v6) <= 40.0 )
    result = 0;
  else
LABEL_41:
    result = 1;
  return result;
}

// File Line: 3109
// RVA: 0x3F8D60
bool __fastcall UFG::EncounterBase::IsVisible(UFG::EncounterBase *this, UFG::EncounterUnitComponent *pEncounterUnitComponent)
{
  UFG::SimObject *v2; // rbx
  UFG::TransformNodeComponent *v3; // rbx
  bool result; // al

  v2 = pEncounterUnitComponent->m_pSimObject;
  result = 0;
  if ( v2 )
  {
    v3 = v2->m_pTransformNodeComponent;
    if ( v3 )
    {
      UFG::TransformNodeComponent::UpdateWorldTransform(v3);
      if ( UFG::SimObjectUtility::IsPositionOnScreen((UFG::qVector3 *)&v3->mWorldTransform.v3, 2.0, 0) )
        result = 1;
    }
  }
  return result;
}

// File Line: 3119
// RVA: 0x3F9120
void __fastcall UFG::EncounterBase::Replenish(UFG::EncounterBase *this)
{
  UFG::EncounterBase *v1; // rdi
  __int64 v2; // rax
  UFG::qPropertySet *v3; // rsi
  float v4; // ecx
  float *v5; // rax
  bool v6; // zf
  float v7; // xmm1_4
  float *v8; // rax
  float v9; // xmm1_4

  v1 = this;
  if ( !this->mIsReplenishing )
  {
    ++this->mWaveCount;
    if ( this->mDisabledUnitForCurrentWave )
      ++this->mWavesDisabledUnitCount;
    *(_WORD *)&this->mHasSpawnedInFrontForCurrentWave = 0;
  }
  v2 = ((__int64 (*)(void))this->vfptr[33].__vecDelDtor)();
  v1->mIsReplenishing = 1;
  v3 = (UFG::qPropertySet *)v2;
  UFG::PropertySetHandle::Bind(&v1->mProperties);
  v4 = *UFG::qPropertySet::Get<float>(
          v1->mProperties.mpPropSet,
          (UFG::qSymbol *)&EncounterSym_replenish_timeout.mUID,
          DEPTH_RECURSE);
  v1->mSpawnTimeout = 0.0;
  v1->mReplenishTimeout = v4;
  v5 = UFG::qPropertySet::Get<float>(v3, (UFG::qSymbol *)&EncounterSym_heatwave_timer.mUID, DEPTH_RECURSE);
  v6 = v1->mEnableWaveTimerChangesByDisabledUnits == 0;
  v7 = *v5;
  v1->mWaveTimer = *v5;
  if ( !v6 && v7 >= 0.0 )
  {
    if ( v3
      && (v8 = UFG::qPropertySet::Get<float>(
                 v3,
                 (UFG::qSymbol *)&EncounterSym_vehicle_kill_bonus_timer.mUID,
                 DEPTH_RECURSE)) != 0i64 )
    {
      v9 = *v8;
    }
    else
    {
      v9 = FLOAT_2_0;
    }
    v1->mWaveTimer = (float)((float)v1->mWavesDisabledUnitCount * v9) + v1->mWaveTimer;
  }
}

// File Line: 3150
// RVA: 0x3F8E50
void __fastcall UFG::EncounterBase::OnDetachEncounterUnitComponent(UFG::EncounterBase *this, UFG::EncounterUnitComponent *pComponent)
{
  unsigned int v2; // er10
  __int64 v3; // r8
  UFG::EncounterBase *v4; // r11
  unsigned int v5; // er9
  UFG::EncounterUnitComponent **v6; // rax
  __int64 v7; // rax
  unsigned int v8; // ecx
  UFG::EncounterUnitComponent **v9; // rax
  __int64 v10; // rax

  v2 = this->mHumans.size;
  v3 = 0i64;
  v4 = this;
  v5 = 0;
  if ( v2 )
  {
    v6 = this->mHumans.p;
    while ( *v6 != pComponent )
    {
      ++v5;
      ++v6;
      if ( v5 >= v2 )
        goto LABEL_7;
    }
    v7 = v2 - 1;
    this->mHumans.size = v7;
    this->mHumans.p[v5] = this->mHumans.p[v7];
  }
LABEL_7:
  v8 = this->mVehicles.size;
  if ( v8 )
  {
    v9 = v4->mVehicles.p;
    while ( *v9 != pComponent )
    {
      v3 = (unsigned int)(v3 + 1);
      ++v9;
      if ( (unsigned int)v3 >= v8 )
        return;
    }
    v10 = v8 - 1;
    v4->mVehicles.size = v10;
    v4->mVehicles.p[v3] = v4->mVehicles.p[v10];
  }
}

// File Line: 3175
// RVA: 0x3F7F70
bool __fastcall UFG::EncounterBase::IsCharacterInUseHeuristic(UFG::EncounterBase *this, UFG::EncounterUnitComponent *pEncounterUnitComponent)
{
  UFG::EncounterUnitComponent *v2; // rbx
  UFG::EncounterBase *v3; // r15
  UFG::SimObjectGame *v5; // rcx
  UFG::TransformNodeComponent *v6; // r12
  unsigned __int16 v7; // dx
  UFG::SimComponent *v8; // rax
  UFG::qStaticSymbol *v9; // rbp
  UFG::qPropertySet *v10; // rdi
  UFG::qPropertySet *v11; // rsi
  float *v12; // rbx
  float v13; // xmm6_4
  char v14; // al

  v2 = pEncounterUnitComponent;
  v3 = this;
  if ( !((unsigned __int8 (*)(void))this->vfptr[78].__vecDelDtor)() )
    return 0;
  v5 = (UFG::SimObjectGame *)v2->m_pSimObject;
  v6 = 0i64;
  if ( v5 )
  {
    v7 = v5->m_Flags;
    v6 = v5->m_pTransformNodeComponent;
    if ( (v7 >> 14) & 1 )
    {
      v8 = v5->m_Components.p[44].m_pComponent;
    }
    else if ( (v7 & 0x8000u) == 0 )
    {
      if ( (v7 >> 13) & 1 )
      {
        v8 = UFG::SimObjectGame::GetComponentOfTypeHK(v5, UFG::CharacterOccupantComponent::_TypeUID);
      }
      else if ( (v7 >> 12) & 1 )
      {
        v8 = UFG::SimObjectGame::GetComponentOfTypeHK(v5, UFG::CharacterOccupantComponent::_TypeUID);
      }
      else
      {
        v8 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v5->vfptr, UFG::CharacterOccupantComponent::_TypeUID);
      }
    }
    else
    {
      v8 = UFG::SimObjectGame::GetComponentOfTypeHK(v5, UFG::CharacterOccupantComponent::_TypeUID);
    }
  }
  else
  {
    v8 = 0i64;
  }
  v9 = &EncounterSym_invalid_vehicle_distance;
  if ( !v8 )
    v9 = &EncounterSym_invalid_onfoot_distance;
  if ( v3->mFocusTargetContext.mIsInWater )
    v9 = &EncounterSym_invalid_water_vehicle_distance;
  UFG::PropertySetHandle::Bind(&v3->mProperties);
  v10 = v3->mProperties.mpPropSet;
  UFG::PropertySetHandle::Bind(&v3->mProperties);
  v11 = v3->mProperties.mpPropSet;
  v12 = UFG::qPropertySet::Get<float>(v10, (UFG::qSymbol *)&v9->mUID, DEPTH_RECURSE);
  v13 = *v12
      + *UFG::qPropertySet::Get<float>(v11, (UFG::qSymbol *)&EncounterSym_invalid_buffer_distance.mUID, DEPTH_RECURSE);
  UFG::TransformNodeComponent::UpdateWorldTransform(v6);
  v14 = 0;
  if ( (float)((float)((float)(v6->mWorldTransform.v3.y - v3->mFocusTargetPosition.y)
                     * (float)(v6->mWorldTransform.v3.y - v3->mFocusTargetPosition.y))
             + (float)((float)(v6->mWorldTransform.v3.x - v3->mFocusTargetPosition.x)
                     * (float)(v6->mWorldTransform.v3.x - v3->mFocusTargetPosition.x))) > (float)(v13 * v13) )
    v14 = 1;
  return v14 == 0;
}

// File Line: 3216
// RVA: 0x3F89D0
char __fastcall UFG::EncounterBase::IsVehicleInUseHeuristic(UFG::EncounterBase *this, UFG::EncounterUnitComponent *pEncounterUnitComponent)
{
  UFG::SimObjectCVBase *v2; // rsi
  UFG::EncounterBase *v3; // rdi
  UFG::EncounterUnitComponent *v4; // rbp
  __int128 v5; // xmm6
  char v6; // r14
  unsigned __int16 v7; // cx
  UFG::HumanDriverComponent *v8; // rax
  unsigned __int16 v9; // cx
  UFG::SimComponent *v10; // rax
  hkSimpleLocalFrame *v11; // rdi
  UFG::SimObjectGame *v12; // rax
  UFG::SimObjectGame *v13; // rbx
  unsigned __int16 v14; // dx
  UFG::SimComponent *v15; // rdi
  UFG::SimComponent *v16; // rax
  unsigned __int16 v17; // cx
  UFG::SimComponent *v18; // rax
  unsigned __int16 v19; // cx
  UFG::SimComponent *v20; // rax

  v2 = (UFG::SimObjectCVBase *)pEncounterUnitComponent->m_pSimObject;
  v3 = this;
  v4 = pEncounterUnitComponent;
  UFG::PropertySetHandle::Bind(&this->mProperties);
  v5 = *(unsigned int *)UFG::qPropertySet::Get<float>(
                          v3->mProperties.mpPropSet,
                          (UFG::qSymbol *)&EncounterSym_minimum_acquired_time.mUID,
                          DEPTH_RECURSE);
  v6 = (__int64)v3->vfptr[78].__vecDelDtor((UFG::qSafePointerNode<UFG::EncounterBase> *)&v3->vfptr, (unsigned int)v4) & 1;
  if ( !v6 )
    return v6;
  if ( v4->mEngaged )
    *(float *)&v5 = FLOAT_5_0;
  if ( v2 )
  {
    v7 = v2->m_Flags;
    if ( (v7 >> 14) & 1 )
    {
      v8 = UFG::SimObjectCVBase::GetComponent<UFG::HumanDriverComponent>(v2);
    }
    else if ( (v7 & 0x8000u) == 0 )
    {
      if ( (v7 >> 13) & 1 )
        v8 = (UFG::HumanDriverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                            (UFG::SimObjectGame *)&v2->vfptr,
                                            UFG::HumanDriverComponent::_TypeUID);
      else
        v8 = (UFG::HumanDriverComponent *)((v7 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                              (UFG::SimObjectGame *)&v2->vfptr,
                                                              UFG::HumanDriverComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v2->vfptr, UFG::HumanDriverComponent::_TypeUID));
    }
    else
    {
      v8 = UFG::SimObjectCVBase::GetComponent<UFG::HumanDriverComponent>(v2);
    }
    if ( v8 )
      return 0;
  }
  if ( v4->mUsageCount == 1 )
    return 0;
  if ( *(float *)&v5 >= v4->mAcquiredTimer )
    return v6;
  if ( !v2 )
    return 0;
  v9 = v2->m_Flags;
  if ( (v9 >> 14) & 1 )
  {
    v10 = UFG::SimObjectGame::GetComponentOfTypeHK(
            (UFG::SimObjectGame *)&v2->vfptr,
            UFG::VehicleOccupantComponent::_TypeUID);
  }
  else
  {
    if ( (v9 & 0x8000u) != 0 )
    {
      v11 = (hkSimpleLocalFrame *)v2->m_Components.p[30].m_pComponent;
      goto LABEL_28;
    }
    if ( (v9 >> 13) & 1 )
    {
      v10 = UFG::SimObjectGame::GetComponentOfTypeHK(
              (UFG::SimObjectGame *)&v2->vfptr,
              UFG::VehicleOccupantComponent::_TypeUID);
    }
    else if ( (v9 >> 12) & 1 )
    {
      v10 = UFG::SimObjectGame::GetComponentOfTypeHK(
              (UFG::SimObjectGame *)&v2->vfptr,
              UFG::VehicleOccupantComponent::_TypeUID);
    }
    else
    {
      v10 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v2->vfptr, UFG::VehicleOccupantComponent::_TypeUID);
    }
  }
  v11 = (hkSimpleLocalFrame *)v10;
LABEL_28:
  if ( !v11 )
    return 0;
  v12 = (UFG::SimObjectGame *)Scaleform::Render::RBGenericImpl::RenderTarget::GetTexture(v11);
  v13 = v12;
  if ( !v12 )
    return UFG::VehicleOccupantComponent::HasPassengers((UFG::VehicleOccupantComponent *)v11) != 0;
  v14 = v12->m_Flags;
  if ( (v14 >> 14) & 1 )
  {
    v15 = v12->m_Components.p[6].m_pComponent;
  }
  else if ( (v14 & 0x8000u) == 0 )
  {
    if ( (v14 >> 13) & 1 )
    {
      v16 = UFG::SimObjectGame::GetComponentOfTypeHK(v12, UFG::HealthComponent::_TypeUID);
    }
    else if ( (v14 >> 12) & 1 )
    {
      v16 = UFG::SimObjectGame::GetComponentOfTypeHK(v12, UFG::HealthComponent::_TypeUID);
    }
    else
    {
      v16 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v12->vfptr, UFG::HealthComponent::_TypeUID);
    }
    v15 = v16;
  }
  else
  {
    v15 = v12->m_Components.p[6].m_pComponent;
  }
  v17 = v13->m_Flags;
  if ( (v17 >> 14) & 1 )
  {
    v18 = v13->m_Components.p[5].m_pComponent;
  }
  else if ( (v17 & 0x8000u) == 0 )
  {
    if ( (v17 >> 13) & 1 )
    {
      v18 = UFG::SimObjectGame::GetComponentOfTypeHK(v13, UFG::AIScriptInterfaceComponent::_TypeUID);
    }
    else if ( (v17 >> 12) & 1 )
    {
      v18 = UFG::SimObjectGame::GetComponentOfTypeHK(v13, UFG::AIScriptInterfaceComponent::_TypeUID);
    }
    else
    {
      v18 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v13->vfptr, UFG::AIScriptInterfaceComponent::_TypeUID);
    }
  }
  else
  {
    v18 = v13->m_Components.p[5].m_pComponent;
  }
  if ( !v15
    || BYTE4(v15[1].m_BoundComponentHandles.mNode.mPrev)
    || !v18
    || (_QWORD)v18[32].m_BoundComponentHandles.mNode.mPrev & 0x20 )
  {
    return 0;
  }
  v19 = v13->m_Flags;
  if ( (v19 >> 14) & 1 )
  {
    v20 = v13->m_Components.p[16].m_pComponent;
  }
  else if ( (v19 & 0x8000u) == 0 )
  {
    if ( (v19 >> 13) & 1 )
      v20 = UFG::SimObjectGame::GetComponentOfTypeHK(v13, UFG::EncounterUnitComponent::_TypeUID);
    else
      v20 = (v19 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v13, UFG::EncounterUnitComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v13->vfptr, UFG::EncounterUnitComponent::_TypeUID);
  }
  else
  {
    v20 = v13->m_Components.p[16].m_pComponent;
  }
  if ( !v20 || *(UFG::EncounterBase **)&v20[1].m_TypeUID != v4->mpEncounter.m_pPointer )
    return 0;
  return v6;
}

// File Line: 3299
// RVA: 0x3F8D00
bool __fastcall UFG::EncounterBase::IsVehicleUsableByDistance(UFG::EncounterBase *this, UFG::EncounterUnitComponent *pEncounterUnitComponent)
{
  UFG::SimObject *v2; // rbx
  UFG::EncounterBase *v3; // rdi
  UFG::TransformNodeComponent *v4; // rbx

  v2 = pEncounterUnitComponent->m_pSimObject;
  v3 = this;
  if ( !v2 )
    return 0;
  v4 = v2->m_pTransformNodeComponent;
  if ( !v4 )
    return 0;
  UFG::TransformNodeComponent::UpdateWorldTransform(v4);
  return (unsigned __int8)v3->vfptr[60].__vecDelDtor(
                            (UFG::qSafePointerNode<UFG::EncounterBase> *)&v3->vfptr,
                            (unsigned int)&v4->mWorldTransform.v3) == 0;
}

// File Line: 3315
// RVA: 0x3F81E0
bool __fastcall UFG::EncounterBase::IsCorrectWaveHeuristic(UFG::EncounterBase *this, UFG::EncounterUnitComponent *pEncounterUnitComponent)
{
  UFG::EncounterUnitComponent *v2; // rbx
  UFG::EncounterBase *v3; // rdi
  UFG::SimObject *v4; // rbx
  UFG::TransformNodeComponent *v5; // rbx
  float *v6; // rax
  bool result; // al

  v2 = pEncounterUnitComponent;
  v3 = this;
  result = 1;
  if ( pEncounterUnitComponent->mWaveType.mUID != *(_DWORD *)((__int64 (*)(void))this->vfptr[26].__vecDelDtor)() )
  {
    v4 = v2->m_pSimObject;
    if ( !v4
      || (v5 = v4->m_pTransformNodeComponent) == 0i64
      || (UFG::TransformNodeComponent::UpdateWorldTransform(v5),
          !UFG::SimObjectUtility::IsPositionOnScreen((UFG::qVector3 *)&v5->mWorldTransform.v3, 5.0, 1))
      && (UFG::PropertySetHandle::Bind(&v3->mProperties),
          v6 = UFG::qPropertySet::Get<float>(
                 v3->mProperties.mpPropSet,
                 (UFG::qSymbol *)&EncounterSym_invalid_wave_distance.mUID,
                 DEPTH_RECURSE),
          (float)((float)((float)(v5->mWorldTransform.v3.y - v3->mFocusTargetPosition.y)
                        * (float)(v5->mWorldTransform.v3.y - v3->mFocusTargetPosition.y))
                + (float)((float)(v5->mWorldTransform.v3.x - v3->mFocusTargetPosition.x)
                        * (float)(v5->mWorldTransform.v3.x - v3->mFocusTargetPosition.x))) > (float)(*v6 * *v6)) )
    {
      result = 0;
    }
  }
  return result;
}

// File Line: 3343
// RVA: 0x3F35E0
__int64 __fastcall UFG::EncounterBase::CountActiveUnits(UFG::EncounterBase *this, UFG::EncounterUnit::UnitType unitType)
{
  UFG::EncounterBase *v2; // rdi
  bool v3; // r15
  unsigned int v4; // ebx
  unsigned int v5; // eax
  UFG::EncounterUnitComponent **v6; // rsi
  __int64 v7; // rbp
  UFG::EncounterUnitComponent *v8; // r14
  unsigned int v9; // eax
  UFG::EncounterUnitComponent **v10; // rsi
  __int64 v11; // rbp
  UFG::EncounterUnitComponent *v12; // r14

  v2 = this;
  v3 = this->mReplenishStyle == 1;
  v4 = 0;
  if ( unitType == 1 )
  {
    v5 = this->mHumans.size;
    if ( v5 )
    {
      v6 = this->mHumans.p;
      v7 = v5;
      do
      {
        v8 = *v6;
        if ( !v3
          || v8->mWaveType.mUID == *(_DWORD *)((__int64 (__fastcall *)(UFG::EncounterBase *))v2->vfptr[26].__vecDelDtor)(v2) )
        {
          if ( v2->vfptr[71].__vecDelDtor((UFG::qSafePointerNode<UFG::EncounterBase> *)&v2->vfptr, (unsigned int)v8) )
            ++v4;
        }
        ++v6;
        --v7;
      }
      while ( v7 );
    }
  }
  else
  {
    v9 = this->mVehicles.size;
    if ( v9 )
    {
      v10 = this->mVehicles.p;
      v11 = v9;
      do
      {
        v12 = *v10;
        if ( (!v3
           || v12->mWaveType.mUID == *(_DWORD *)((__int64 (__fastcall *)(UFG::EncounterBase *))v2->vfptr[26].__vecDelDtor)(v2))
          && (unsigned __int8)v2->vfptr[72].__vecDelDtor(
                                (UFG::qSafePointerNode<UFG::EncounterBase> *)&v2->vfptr,
                                (unsigned int)v12) )
        {
          ++v4;
        }
        ++v10;
        --v11;
      }
      while ( v11 );
    }
  }
  return v4;
}

// File Line: 3379
// RVA: 0x3F60B0
const char *__fastcall UFG::EncounterBase::GetSpawningPrefix(UFG::EncounterBase *this, bool isCharacter)
{
  const char *result; // rax

  result = "encounter_vehicle_";
  if ( isCharacter )
    result = "encounter_character_";
  return result;
}

// File Line: 3384
// RVA: 0x3F9350
void __fastcall UFG::EncounterBase::SetCurrentWaveType(UFG::EncounterBase *this, UFG::qSymbol *waveId)
{
  UFG::EncounterBase *v2; // rsi
  signed int v3; // edi
  UFG::qPropertyList *v4; // rax
  UFG::qPropertyList *v5; // rbx

  v2 = this;
  if ( this->mCurrentWaveType.mUID != waveId->mUID )
  {
    this->mCurrentWaveType = (UFG::qSymbol)waveId->mUID;
    UFG::PropertySetHandle::Bind(&this->mProperties);
    v3 = 1;
    v4 = UFG::qPropertySet::Get<UFG::qPropertyList>(
           v2->mProperties.mpPropSet,
           (UFG::qSymbol *)&EncounterSym_wave_definitions.mUID,
           DEPTH_RECURSE);
    v5 = v4;
    if ( v2->mHeatLevel == 1 )
      v3 = 3;
    v2->mHeatLevel = v3;
    v2->mHeatLevelProperties[v2->mHeatLevel] = UFG::FindWave(v4, &v2->mCurrentWaveType);
    v2->mWaterHeatLevelProperties[v2->mHeatLevel] = UFG::FindWave(v5, &v2->mCurrentWaveType);
    ((void (__fastcall *)(UFG::EncounterBase *))v2->vfptr[50].__vecDelDtor)(v2);
    ((void (__fastcall *)(UFG::EncounterBase *))v2->vfptr[23].__vecDelDtor)(v2);
  }
}

// File Line: 3407
// RVA: 0x3F31E0
UFG::SimComponent *__fastcall UFG::EncounterBase::AddExternalVehicleIntoSystem(UFG::EncounterBase *this, UFG::SimObject *pVehicle)
{
  UFG::SimObject *v2; // rbx
  UFG::EncounterBase *v3; // r14
  UFG::SimComponent *v4; // rdi
  unsigned __int16 v5; // cx
  UFG::SimComponent *v6; // rax
  UFG::qMemoryPool *v7; // rax
  UFG::allocator::free_link *v8; // rax
  UFG::SimComponent *v9; // rax
  unsigned __int16 v10; // cx
  unsigned int v11; // esi
  UFG::SimObjectModifier v13; // [rsp+38h] [rbp-30h]

  v2 = pVehicle;
  v3 = this;
  if ( this->mVehicles.size >= 8 )
    return 0i64;
  if ( pVehicle )
  {
    v5 = pVehicle->m_Flags;
    if ( (v5 >> 14) & 1 )
    {
      v4 = pVehicle->m_Components.p[16].m_pComponent;
    }
    else if ( (v5 & 0x8000u) == 0 )
    {
      if ( (v5 >> 13) & 1 )
      {
        v6 = UFG::SimObjectGame::GetComponentOfTypeHK(
               (UFG::SimObjectGame *)pVehicle,
               UFG::EncounterUnitComponent::_TypeUID);
      }
      else if ( (v5 >> 12) & 1 )
      {
        v6 = UFG::SimObjectGame::GetComponentOfTypeHK(
               (UFG::SimObjectGame *)pVehicle,
               UFG::EncounterUnitComponent::_TypeUID);
      }
      else
      {
        v6 = UFG::SimObject::GetComponentOfType(pVehicle, UFG::EncounterUnitComponent::_TypeUID);
      }
      v4 = v6;
    }
    else
    {
      v4 = pVehicle->m_Components.p[16].m_pComponent;
    }
  }
  else
  {
    v4 = 0i64;
  }
  if ( !v4 )
  {
    v7 = UFG::GetSimulationMemoryPool();
    v8 = UFG::qMemoryPool::Allocate(v7, 0xE0ui64, "EncounterUnitComponent", 0i64, 1u);
    if ( v8 )
    {
      UFG::EncounterUnitComponent::EncounterUnitComponent((UFG::EncounterUnitComponent *)v8, v2->mNode.mUID);
      v4 = v9;
    }
    else
    {
      v4 = 0i64;
    }
    v10 = v2->m_Flags;
    if ( (v10 >> 14) & 1 || (v10 & 0x8000u) != 0 )
      v11 = 16;
    else
      v11 = -1;
    UFG::SimObjectModifier::SimObjectModifier(&v13, v2, 1);
    UFG::SimObjectModifier::AttachComponent(&v13, v4, v11);
    UFG::SimObjectModifier::Close(&v13);
    UFG::SimObjectModifier::~SimObjectModifier(&v13);
  }
  v3->mVehicles.p[v3->mVehicles.size++] = (UFG::EncounterUnitComponent *)v4;
  ((void (__fastcall *)(UFG::EncounterBase *, UFG::SimComponent *, _QWORD))v3->vfptr[69].__vecDelDtor)(v3, v4, 0i64);
  UFG::PropertySetHandle::Bind(&v3->mProperties);
  ((void (__fastcall *)(UFG::EncounterBase *, UFG::SimComponent *, UFG::qPropertySet *, _QWORD))v3->vfptr[81].__vecDelDtor)(
    v3,
    v4,
    v3->mProperties.mpPropSet,
    0i64);
  return v4;
}

// File Line: 3440
// RVA: 0x3F2F90
UFG::SimComponent *__fastcall UFG::EncounterBase::AddExternalCharacterIntoSystem(UFG::EncounterBase *this, UFG::SimObject *pCharacter)
{
  UFG::SimObjectGame *v2; // rdi
  UFG::EncounterBase *v3; // r14
  UFG::PedSpawnManager *v4; // rax
  UFG::SimComponent *v5; // rsi
  unsigned __int16 v6; // cx
  UFG::SimComponent *v7; // rax
  UFG::qMemoryPool *v8; // rax
  UFG::allocator::free_link *v9; // rax
  UFG::SimComponent *v10; // rax
  unsigned __int16 v11; // cx
  unsigned int v12; // ebx
  UFG::qSymbol *v13; // rax
  UFG::qSymbol *v14; // rbx
  UFG::GameStatTracker *v15; // rax
  UFG::SimObjectModifier v17; // [rsp+38h] [rbp-30h]

  v2 = (UFG::SimObjectGame *)pCharacter;
  v3 = this;
  if ( this->mHumans.size >= 0x20 )
    return 0i64;
  v4 = UFG::PedSpawnManager::GetInstance();
  UFG::PedSpawnManager::SetSuspendOption(v4, (UFG::SimObject *)&v2->vfptr, NoSuspend);
  if ( v2 )
  {
    v6 = v2->m_Flags;
    if ( (v6 >> 14) & 1 )
    {
      v5 = v2->m_Components.p[16].m_pComponent;
    }
    else if ( (v6 & 0x8000u) == 0 )
    {
      if ( (v6 >> 13) & 1 )
      {
        v7 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::EncounterUnitComponent::_TypeUID);
      }
      else if ( (v6 >> 12) & 1 )
      {
        v7 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::EncounterUnitComponent::_TypeUID);
      }
      else
      {
        v7 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v2->vfptr, UFG::EncounterUnitComponent::_TypeUID);
      }
      v5 = v7;
    }
    else
    {
      v5 = v2->m_Components.p[16].m_pComponent;
    }
  }
  else
  {
    v5 = 0i64;
  }
  if ( !v5 )
  {
    v8 = UFG::GetSimulationMemoryPool();
    v9 = UFG::qMemoryPool::Allocate(v8, 0xE0ui64, "EncounterUnitComponent", 0i64, 1u);
    if ( v9 )
    {
      UFG::EncounterUnitComponent::EncounterUnitComponent((UFG::EncounterUnitComponent *)v9, v2->mNode.mUID);
      v5 = v10;
    }
    else
    {
      v5 = 0i64;
    }
    v11 = v2->m_Flags;
    if ( (v11 >> 14) & 1 )
    {
      v12 = 16;
    }
    else if ( (v11 & 0x8000u) == 0 )
    {
      v12 = -1;
    }
    else
    {
      v12 = 16;
    }
    UFG::SimObjectModifier::SimObjectModifier(&v17, (UFG::SimObject *)&v2->vfptr, 1);
    UFG::SimObjectModifier::AttachComponent(&v17, v5, v12);
    UFG::SimObjectModifier::Close(&v17);
    UFG::SimObjectModifier::~SimObjectModifier(&v17);
  }
  v3->mHumans.p[v3->mHumans.size++] = (UFG::EncounterUnitComponent *)v5;
  ((void (__fastcall *)(UFG::EncounterBase *, UFG::SimComponent *, _QWORD))v3->vfptr[69].__vecDelDtor)(v3, v5, 0i64);
  UFG::PropertySetHandle::Bind(&v3->mProperties);
  v13 = UFG::qPropertySet::Get<UFG::qSymbol>(
          v3->mProperties.mpPropSet,
          (UFG::qSymbol *)&qSymbol_EncounterFactionClass.mUID,
          DEPTH_RECURSE);
  v14 = v13;
  if ( v13 )
  {
    if ( v13->mUID != -1 )
    {
      v15 = UFG::FactionInterface::Get();
      UFG::FactionInterface::SetFaction(&v15->mFactionInterface, (UFG::SimObject *)&v2->vfptr, v14);
    }
  }
  UFG::TSCharacter::EnableScriptControlOnSimObject((UFG::SimObject *)&v2->vfptr, 0);
  v3->vfptr[68].__vecDelDtor((UFG::qSafePointerNode<UFG::EncounterBase> *)&v3->vfptr, (unsigned int)v2);
  return v5;
}

// File Line: 3486
// RVA: 0x3F2DF0
void __fastcall UFG::EncounterBase::Acquire(UFG::EncounterBase *this, UFG::EncounterUnitComponent *pEncounterUnitComponent, UFG::qPropertySet *pGroupPropertySet)
{
  UFG::EncounterUnitComponent::AcquireBy(pEncounterUnitComponent, this, pGroupPropertySet);
}

// File Line: 3493
// RVA: 0x3FB7E0
void __fastcall UFG::EncounterBase::UpdateWaveGroupStats(UFG::EncounterBase *this)
{
  UFG::EncounterBase *v1; // rbx
  unsigned int v2; // ecx
  __int64 v3; // rax
  unsigned int v4; // eax
  UFG::EncounterUnitComponent **v5; // rdi
  __int64 v6; // r14
  UFG::EncounterUnitComponent *v7; // rsi
  char v8; // al
  __int64 v9; // rbp
  unsigned int v10; // eax
  UFG::EncounterUnitComponent **v11; // rdi
  __int64 v12; // r14
  UFG::EncounterUnitComponent *v13; // rsi
  char v14; // al
  __int64 v15; // rbp

  v1 = this;
  v2 = 0;
  if ( v1->mNumWaveGroupTypes )
  {
    do
    {
      v3 = v2++;
      v1->mWaveGroupInstances[v3] = 0;
    }
    while ( v2 < v1->mNumWaveGroupTypes );
  }
  v4 = v1->mHumans.size;
  if ( v4 )
  {
    v5 = v1->mHumans.p;
    v6 = v4;
    do
    {
      v7 = *v5;
      if ( v7->mWaveType.mUID == *(_DWORD *)((__int64 (__fastcall *)(UFG::EncounterBase *))v1->vfptr[26].__vecDelDtor)(v1) )
      {
        v8 = v7->mWaveTypeGroupIndex;
        if ( v8 != -1 )
        {
          v9 = v8;
          if ( v1->mWaveGroupTypes[v8] == 1 )
          {
            if ( v1->vfptr[71].__vecDelDtor((UFG::qSafePointerNode<UFG::EncounterBase> *)&v1->vfptr, (unsigned int)v7) )
              ++v1->mWaveGroupInstances[v9];
          }
        }
      }
      ++v5;
      --v6;
    }
    while ( v6 );
  }
  v10 = v1->mVehicles.size;
  if ( v10 )
  {
    v11 = v1->mVehicles.p;
    v12 = v10;
    do
    {
      v13 = *v11;
      if ( v13->mWaveType.mUID == *(_DWORD *)((__int64 (__fastcall *)(UFG::EncounterBase *))v1->vfptr[26].__vecDelDtor)(v1) )
      {
        v14 = v13->mWaveTypeGroupIndex;
        if ( v14 != -1 )
        {
          v15 = v14;
          if ( v1->mWaveGroupTypes[v14] == 2 )
          {
            if ( v1->vfptr[72].__vecDelDtor((UFG::qSafePointerNode<UFG::EncounterBase> *)&v1->vfptr, (unsigned int)v13) )
              ++v1->mWaveGroupInstances[v15];
          }
        }
      }
      ++v11;
      --v12;
    }
    while ( v12 );
  }
}

// File Line: 3541
// RVA: 0x3F2F70
void __fastcall UFG::EncounterBase::AddCharacterSpawnRegion(UFG::EncounterBase *this, UFG::RegionComponent *pRegion)
{
  this->mHumanSpawnRegions.p[this->mHumanSpawnRegions.size++] = pRegion;
}

// File Line: 3546
// RVA: 0x3F35D0
void __fastcall UFG::EncounterBase::ClearCharacterSpawnRegions(UFG::EncounterBase *this)
{
  this->mHumanSpawnRegions.size = 0;
}

// File Line: 3551
// RVA: 0x3F9300
void __fastcall UFG::EncounterBase::SetCombatRegion(UFG::EncounterBase *this, UFG::CombatRegion *pRegion)
{
  UFG::qNode<UFG::qSafePointerBase<UFG::CombatRegion>,UFG::qSafePointerNodeList> *v2; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::CombatRegion>,UFG::qSafePointerNodeList> *v3; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::CombatRegion>,UFG::qSafePointerNodeList> *v4; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::CombatRegion>,UFG::qSafePointerNodeList> *v5; // rax

  v2 = (UFG::qNode<UFG::qSafePointerBase<UFG::CombatRegion>,UFG::qSafePointerNodeList> *)&this->mpCombatRegion.mPrev;
  if ( this->mpCombatRegion.m_pPointer )
  {
    v3 = v2->mPrev;
    v4 = v2->mNext;
    v3->mNext = v4;
    v4->mPrev = v3;
    v2->mPrev = v2;
    v2->mNext = v2;
  }
  v2[1].mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::CombatRegion>,UFG::qSafePointerNodeList> *)pRegion;
  if ( pRegion )
  {
    v5 = pRegion->m_SafePointerList.mNode.mPrev;
    v5->mNext = v2;
    v2->mPrev = v5;
    v2->mNext = &pRegion->m_SafePointerList.mNode;
    pRegion->m_SafePointerList.mNode.mPrev = v2;
  }
}

