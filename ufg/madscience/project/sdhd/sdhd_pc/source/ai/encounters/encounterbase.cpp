// File Line: 132
// RVA: 0x3F3A80
void __fastcall UFG::EncounterBase_VehicleDisabledHandler(UFG::Event *pEvent)
{
  UFG::qNode<UFG::Event,UFG::Event> *mNext; // rbx
  UFG::AiDriverComponent *v2; // rax
  UFG::CopUnitComponent *mPrev; // rcx

  mNext = pEvent[1].mNext;
  if ( mNext )
  {
    v2 = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>((UFG::SimObjectCVBase *)pEvent[1].mNext);
    if ( v2 )
      v2->m_DesiredSpeedLimit = 8.333334;
    mPrev = (UFG::CopUnitComponent *)mNext[6].mNext[17].mPrev;
    if ( mPrev )
      UFG::CopUnitComponent::DisableHandler(mPrev);
  }
}

// File Line: 199
// RVA: 0x3F2250
void __fastcall UFG::EncounterBase::EncounterBase(UFG::EncounterBase *this)
{
  __int64 v2; // rbp
  UFG::qSymbol *mWaterHeatLevelPropertiesName; // rdi
  float y; // xmm1_4
  float z; // xmm2_4
  bool *mPreloadedResources; // rsi
  UFG::qPropertySet **mWaterHeatLevelProperties; // rbx
  void (__fastcall *v8)(fastdelegate::detail::GenericClass *); // rbx
  void (__fastcall *v9)(fastdelegate::detail::GenericClass *); // rax
  fastdelegate::FastDelegate1<UFG::Event *,void> v10; // [rsp+38h] [rbp-50h] BYREF
  void (__fastcall *v11)(UFG::Event *); // [rsp+48h] [rbp-40h]
  void (__fastcall *v12)(fastdelegate::detail::GenericClass *); // [rsp+50h] [rbp-38h]

  UFG::qSafePointerNodeWithCallbacks<UFG::EncounterBase>::qSafePointerNodeWithCallbacks<UFG::EncounterBase>(this);
  this->vfptr = (UFG::qSafePointerNode<UFG::EncounterBase>Vtbl *)&UFG::EncounterBase::`vftable;
  this->mEnable = 1;
  UFG::PropertySetHandle::PropertySetHandle(&this->mProperties);
  this->mObjective = eAI_OBJECTIVE_NONE;
  this->mPostObjective = NUM_AI_OBJECTIVES;
  this->mCurrentWaveType.mUID = -1;
  v2 = 6i64;
  `eh vector constructor iterator(
    this->mHeatLevelPropertiesName,
    4ui64,
    6,
    (void (__fastcall *)(void *))BackInfo::BackInfo);
  mWaterHeatLevelPropertiesName = this->mWaterHeatLevelPropertiesName;
  `eh vector constructor iterator(
    this->mWaterHeatLevelPropertiesName,
    4ui64,
    6,
    (void (__fastcall *)(void *))BackInfo::BackInfo);
  *(_QWORD *)&this->mInsideDynamicRadiusCount = 0i64;
  this->mMaxHeatLevel = -1;
  this->mpVehicleSpawnSensor = 0i64;
  this->mStartTimestamp = 0i64;
  *(_QWORD *)&this->mVehicleSpawnIteratingIndex = 0i64;
  y = UFG::qVector3::msZero.y;
  z = UFG::qVector3::msZero.z;
  this->mFocusTargetPosition.x = UFG::qVector3::msZero.x;
  this->mFocusTargetPosition.y = y;
  this->mFocusTargetPosition.z = z;
  *(_QWORD *)&this->mWaveCount = 0i64;
  *(_QWORD *)&this->mWaveTimer = 0i64;
  *(_QWORD *)&this->mSpawnTimeout = 0i64;
  *(_QWORD *)&this->mReducedRadiusPercentage = 1065353216i64;
  *(_DWORD *)&this->mIsStaysOffSidewalk = 0;
  *(_DWORD *)&this->mIsReplenishing = 0x1000000;
  this->mEnableWaveTimerChangesByDisabledUnits = 0;
  this->mFocusTargetContext.mpSimObject = 0i64;
  this->mFocusTargetContext.mpVehicle = 0i64;
  this->mFocusTargetContext.mWaterContextTimer = 0.0;
  *(_DWORD *)&this->mFocusTargetContext.mIsOnFootRaw = 16777217;
  *(_WORD *)&this->mFocusTargetContext.mIsOnMeshHeuristic = 1;
  this->mFocusTargetContext.mOpenFiredWithHostage = 0;
  this->mHumans.size = 0;
  this->mVehicles.size = 0;
  this->mHumanSpawnRegions.size = 0;
  *(_QWORD *)&this->mNumWaveGroupTypes = 0i64;
  *(_QWORD *)&this->mNumDesiredCharacterGroups = 0i64;
  *(_QWORD *)&this->mCharacterSpawnCount = 0i64;
  this->mCharacterKillCount = 0;
  UFG::VehicleWayFinderClient::VehicleWayFinderClient(&this->mWayTraversalClient, 0i64, 0xFFFFFFFF);
  this->mWayTraversalClient.vfptr = (UFG::WayFinderClientVtbl *)&UFG::WayTraversalClient::`vftable;
  this->mpFocusTarget.mPrev = &this->mpFocusTarget;
  this->mpFocusTarget.mNext = &this->mpFocusTarget;
  this->mpFocusTarget.m_pPointer = 0i64;
  this->mpSecondaryTarget.mPrev = &this->mpSecondaryTarget;
  this->mpSecondaryTarget.mNext = &this->mpSecondaryTarget;
  this->mpSecondaryTarget.m_pPointer = 0i64;
  this->mpCombatRegion.mPrev = &this->mpCombatRegion;
  this->mpCombatRegion.mNext = &this->mpCombatRegion;
  this->mpCombatRegion.m_pPointer = 0i64;
  this->mHumans.size = 0;
  this->mVehicles.size = 0;
  this->mHumanSpawnRegions.size = 0;
  mPreloadedResources = this->mPreloadedResources;
  mWaterHeatLevelProperties = this->mWaterHeatLevelProperties;
  do
  {
    UFG::qSymbol::set_null(mWaterHeatLevelPropertiesName - 6);
    UFG::qSymbol::set_null(mWaterHeatLevelPropertiesName);
    *(mWaterHeatLevelProperties - 6) = 0i64;
    *mWaterHeatLevelProperties = 0i64;
    *mPreloadedResources = 0;
    ++mWaterHeatLevelPropertiesName;
    ++mWaterHeatLevelProperties;
    ++mPreloadedResources;
    --v2;
  }
  while ( v2 );
  if ( !registeredStaticEventHandlers )
  {
    v8 = (void (__fastcall *)(fastdelegate::detail::GenericClass *))fastdelegate::FastDelegate1<char const *,void>::InvokeStaticFunction;
    v9 = (void (__fastcall *)(fastdelegate::detail::GenericClass *))fastdelegate::FastDelegate1<char const *,void>::InvokeStaticFunction;
    if ( !UFG::EncounterBase_VehicleDisabledHandler )
      v9 = 0i64;
    v12 = v9;
    v11 = UFG::EncounterBase_VehicleDisabledHandler;
    v10.m_Closure.m_pFunction = v9;
    v10.m_Closure.m_pthis = (fastdelegate::detail::GenericClass *)UFG::EncounterBase_VehicleDisabledHandler;
    UFG::EventDispatcher::Register(&UFG::EventDispatcher::mInstance, &v10, UFG::gVehicleTakenDownChannel.mUID, 0i64, 0);
    if ( !UFG::EncounterBase_VehicleDisabledHandler )
      v8 = 0i64;
    v12 = v8;
    v11 = UFG::EncounterBase_VehicleDisabledHandler;
    v10.m_Closure.m_pFunction = v8;
    v10.m_Closure.m_pthis = (fastdelegate::detail::GenericClass *)UFG::EncounterBase_VehicleDisabledHandler;
    UFG::EventDispatcher::Register(&UFG::EventDispatcher::mInstance, &v10, UFG::gVehicleDisabledChannel.mUID, 0i64, 0);
    registeredStaticEventHandlers = 1;
  }
}

// File Line: 229
// RVA: 0x3F2880
void __fastcall UFG::EncounterBase::~EncounterBase(UFG::EncounterBase *this)
{
  UFG::qSafePointer<UFG::CombatRegion,UFG::CombatRegion> *p_mpCombatRegion; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::CombatRegion>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::CombatRegion>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::CombatRegion>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::CombatRegion>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *p_mpSecondaryTarget; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v10; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v11; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *p_mpFocusTarget; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v13; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v14; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v15; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v16; // rax

  this->vfptr = (UFG::qSafePointerNode<UFG::EncounterBase>Vtbl *)&UFG::EncounterBase::`vftable;
  UFG::EncounterBase::Shutdown(this);
  p_mpCombatRegion = &this->mpCombatRegion;
  if ( this->mpCombatRegion.m_pPointer )
  {
    mPrev = p_mpCombatRegion->mPrev;
    mNext = this->mpCombatRegion.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_mpCombatRegion->mPrev = p_mpCombatRegion;
    this->mpCombatRegion.mNext = &this->mpCombatRegion;
  }
  this->mpCombatRegion.m_pPointer = 0i64;
  v5 = p_mpCombatRegion->mPrev;
  v6 = this->mpCombatRegion.mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  p_mpCombatRegion->mPrev = p_mpCombatRegion;
  this->mpCombatRegion.mNext = &this->mpCombatRegion;
  p_mpSecondaryTarget = &this->mpSecondaryTarget;
  if ( this->mpSecondaryTarget.m_pPointer )
  {
    v8 = p_mpSecondaryTarget->mPrev;
    v9 = this->mpSecondaryTarget.mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    p_mpSecondaryTarget->mPrev = p_mpSecondaryTarget;
    this->mpSecondaryTarget.mNext = &this->mpSecondaryTarget;
  }
  this->mpSecondaryTarget.m_pPointer = 0i64;
  v10 = p_mpSecondaryTarget->mPrev;
  v11 = this->mpSecondaryTarget.mNext;
  v10->mNext = v11;
  v11->mPrev = v10;
  p_mpSecondaryTarget->mPrev = p_mpSecondaryTarget;
  this->mpSecondaryTarget.mNext = &this->mpSecondaryTarget;
  p_mpFocusTarget = &this->mpFocusTarget;
  if ( this->mpFocusTarget.m_pPointer )
  {
    v13 = p_mpFocusTarget->mPrev;
    v14 = this->mpFocusTarget.mNext;
    v13->mNext = v14;
    v14->mPrev = v13;
    p_mpFocusTarget->mPrev = p_mpFocusTarget;
    this->mpFocusTarget.mNext = &this->mpFocusTarget;
  }
  this->mpFocusTarget.m_pPointer = 0i64;
  v15 = p_mpFocusTarget->mPrev;
  v16 = this->mpFocusTarget.mNext;
  v15->mNext = v16;
  v16->mPrev = v15;
  p_mpFocusTarget->mPrev = p_mpFocusTarget;
  this->mpFocusTarget.mNext = &this->mpFocusTarget;
  this->mWayTraversalClient.vfptr = (UFG::WayFinderClientVtbl *)&UFG::VehicleWayFinderClient::`vftable;
  this->mWayTraversalClient.vfptr = (UFG::WayFinderClientVtbl *)&UFG::WayFinderClient::`vftable;
  this->mHumanSpawnRegions.size = 0;
  this->mVehicles.size = 0;
  this->mHumans.size = 0;
  `eh vector destructor iterator(this->mWaterHeatLevelPropertiesName, 4ui64, 6, (void (__fastcall *)(void *))_);
  `eh vector destructor iterator(this->mHeatLevelPropertiesName, 4ui64, 6, (void (__fastcall *)(void *))_);
  UFG::PropertySetHandle::~PropertySetHandle(&this->mProperties);
  UFG::qSafePointerNodeWithCallbacks<UFG::EncounterBase>::~qSafePointerNodeWithCallbacks<UFG::EncounterBase>(this);
}

// File Line: 234
// RVA: 0x3F4030
UFG::qPropertySet *__fastcall UFG::FindWave(UFG::qPropertyList *pWaveList, UFG::qSymbol *identifier)
{
  unsigned int mNumElements; // edi
  unsigned int v3; // ebx
  char *ValuePtr; // rax
  char *v7; // rcx

  mNumElements = pWaveList->mNumElements;
  v3 = 0;
  if ( !mNumElements )
    return 0i64;
  while ( 1 )
  {
    ValuePtr = UFG::qPropertyList::GetValuePtr(pWaveList, 0x1Au, v3);
    if ( ValuePtr )
    {
      if ( *(_QWORD *)ValuePtr )
      {
        v7 = &ValuePtr[*(_QWORD *)ValuePtr];
        if ( v7 )
        {
          if ( *((_DWORD *)v7 + 16) == identifier->mUID )
            break;
        }
      }
    }
    if ( ++v3 >= mNumElements )
      return 0i64;
  }
  return (UFG::qPropertySet *)&ValuePtr[*(_QWORD *)ValuePtr];
}

// File Line: 252
// RVA: 0x3F40B0
__int64 __fastcall UFG::EncounterBase::FindWaveGroupIndex(
        UFG::EncounterBase *this,
        UFG::qPropertySet *pGroupPropertySet)
{
  UFG::qPropertySet *v3; // rax
  UFG::qPropertyList *v4; // rax
  unsigned int v5; // ebx
  unsigned int mNumElements; // edi
  UFG::qPropertyList *v7; // rbp
  char *ValuePtr; // rax
  UFG::qPropertySet *v9; // rax

  v3 = (UFG::qPropertySet *)((__int64 (__fastcall *)(UFG::EncounterBase *))this->vfptr[33].__vecDelDtor)(this);
  v4 = UFG::qPropertySet::Get<UFG::qPropertyList>(
         v3,
         (UFG::qArray<unsigned long,0> *)&EncounterSym_spawn_groups,
         DEPTH_RECURSE);
  v5 = 0;
  mNumElements = v4->mNumElements;
  v7 = v4;
  if ( !mNumElements )
    return 0xFFFFFFFFi64;
  while ( 1 )
  {
    ValuePtr = UFG::qPropertyList::GetValuePtr(v7, 0x1Au, v5);
    if ( ValuePtr && *(_QWORD *)ValuePtr )
      v9 = (UFG::qPropertySet *)&ValuePtr[*(_QWORD *)ValuePtr];
    else
      v9 = 0i64;
    if ( v9 == pGroupPropertySet )
      break;
    if ( ++v5 >= mNumElements )
      return 0xFFFFFFFFi64;
  }
  return v5;
}

// File Line: 269
// RVA: 0x3F9430
void __fastcall UFG::EncounterBase::SetPropertySet(UFG::EncounterBase *this, const char *pPropertySetName)
{
  UFG::qSymbol *v3; // rax
  UFG::qPropertySet *PropertySet; // rax
  UFG::qPropertySet *mpPropSet; // r12
  char *v6; // rax
  const char **v7; // rsi
  const char *v8; // rbp
  UFG::eAIObjective v9; // ebx
  const char **v10; // rdi
  char *v11; // rax
  const char *v12; // rdi
  UFG::eAIObjective v13; // ebx
  UFG::qPropertySet **mWaterHeatLevelProperties; // r14
  signed __int64 v15; // rbx
  UFG::qSymbol *mWaterHeatLevelPropertiesName; // rdi
  UFG::qPropertyList *v17; // rbp
  __int64 v18; // r15
  signed __int64 v19; // r13
  UFG::qSymbol *v20; // rax
  unsigned int v21; // ebx
  unsigned int mNumElements; // esi
  char *ValuePtr; // rax
  UFG::qPropertySet *v24; // rcx
  unsigned int v25; // esi
  unsigned int v26; // ebx
  char *v27; // rax
  UFG::qPropertySet *v28; // rcx
  bool *v29; // rax
  UFG::qSymbol result; // [rsp+70h] [rbp+18h] BYREF
  __int64 v32; // [rsp+78h] [rbp+20h]

  v3 = UFG::qSymbol::create_from_string(&result, pPropertySetName);
  PropertySet = UFG::PropertySetManager::GetPropertySet(v3);
  UFG::PropertySetHandle::SetPropSet(&this->mProperties, PropertySet);
  UFG::PropertySetHandle::Bind(&this->mProperties);
  mpPropSet = this->mProperties.mpPropSet;
  this->mObjective = eAI_OBJECTIVE_NONE;
  v6 = UFG::qPropertySet::Get<char const *>(
         mpPropSet,
         (UFG::qArray<unsigned long,0> *)&qSymbol_AIObjective,
         DEPTH_RECURSE);
  v7 = UFG::AIObjectiveNames;
  v8 = v6;
  if ( v6 && *v6 )
  {
    v9 = eAI_OBJECTIVE_NONE;
    v10 = UFG::AIObjectiveNames;
    while ( (unsigned int)UFG::qStringCompareInsensitive(v8, *v10, -1) )
    {
      ++v9;
      ++v10;
      if ( (unsigned int)v9 >= NUM_AI_OBJECTIVES )
        goto LABEL_8;
    }
    this->mObjective = v9;
  }
LABEL_8:
  this->mPostObjective = NUM_AI_OBJECTIVES;
  v11 = UFG::qPropertySet::Get<char const *>(
          mpPropSet,
          (UFG::qArray<unsigned long,0> *)&qSymbol_PostAIObjective,
          DEPTH_RECURSE);
  v12 = v11;
  if ( v11 && *v11 )
  {
    v13 = eAI_OBJECTIVE_NONE;
    while ( (unsigned int)UFG::qStringCompareInsensitive(v12, *v7, -1) )
    {
      ++v13;
      ++v7;
      if ( (unsigned int)v13 >= NUM_AI_OBJECTIVES )
        goto LABEL_15;
    }
    this->mPostObjective = v13;
  }
LABEL_15:
  mWaterHeatLevelProperties = this->mWaterHeatLevelProperties;
  v15 = (char *)EncounterProperty_water_heat_level_property_set - (char *)this - 176;
  mWaterHeatLevelPropertiesName = this->mWaterHeatLevelPropertiesName;
  v17 = UFG::qPropertySet::Get<UFG::qPropertyList>(
          mpPropSet,
          (UFG::qArray<unsigned long,0> *)&EncounterSym_wave_definitions,
          DEPTH_RECURSE);
  v18 = 6i64;
  v32 = v15;
  v19 = (char *)EncounterProperty_heat_level_property_set - (char *)this - 176;
  do
  {
    mWaterHeatLevelPropertiesName[-6].mUID = UFG::qPropertySet::Get<UFG::qSymbol>(
                                               mpPropSet,
                                               *(UFG::qArray<unsigned long,0> **)((char *)mWaterHeatLevelProperties + v19),
                                               DEPTH_RECURSE)->mUID;
    v20 = UFG::qPropertySet::Get<UFG::qSymbol>(
            mpPropSet,
            *(UFG::qArray<unsigned long,0> **)((char *)mWaterHeatLevelProperties + v15),
            DEPTH_RECURSE);
    v21 = 0;
    mWaterHeatLevelPropertiesName->mUID = v20->mUID;
    mNumElements = v17->mNumElements;
    if ( mNumElements )
    {
      while ( 1 )
      {
        ValuePtr = UFG::qPropertyList::GetValuePtr(v17, 0x1Au, v21);
        if ( ValuePtr )
        {
          if ( *(_QWORD *)ValuePtr )
          {
            v24 = (UFG::qPropertySet *)&ValuePtr[*(_QWORD *)ValuePtr];
            if ( v24 )
            {
              if ( v24->mName.mUID == mWaterHeatLevelPropertiesName[-6].mUID )
                break;
            }
          }
        }
        if ( ++v21 >= mNumElements )
          goto LABEL_22;
      }
    }
    else
    {
LABEL_22:
      v24 = 0i64;
    }
    *(mWaterHeatLevelProperties - 6) = v24;
    v25 = v17->mNumElements;
    v26 = 0;
    if ( v25 )
    {
      while ( 1 )
      {
        v27 = UFG::qPropertyList::GetValuePtr(v17, 0x1Au, v26);
        if ( v27 )
        {
          if ( *(_QWORD *)v27 )
          {
            v28 = (UFG::qPropertySet *)&v27[*(_QWORD *)v27];
            if ( v28 )
            {
              if ( v28->mName.mUID == mWaterHeatLevelPropertiesName->mUID )
                break;
            }
          }
        }
        if ( ++v26 >= v25 )
          goto LABEL_29;
      }
    }
    else
    {
LABEL_29:
      v28 = 0i64;
    }
    v15 = v32;
    *mWaterHeatLevelProperties++ = v28;
    ++mWaterHeatLevelPropertiesName;
    --v18;
  }
  while ( v18 );
  v29 = UFG::qPropertySet::Get<bool>(
          mpPropSet,
          (UFG::qArray<unsigned long,0> *)&EncounterSym_suppress_vehicle_spawning_by_kill,
          DEPTH_RECURSE);
  if ( v29 )
    this->mSuppressVehicleSpawningByKillCount = *v29;
  else
    this->mSuppressVehicleSpawningByKillCount = 0;
}

// File Line: 318
// RVA: 0x3F7C50
void __fastcall UFG::EncounterBase::Initialize(UFG::EncounterBase *this)
{
  int *mWaveGroupInstancesRequired; // rax
  __int64 v3; // rcx
  float y; // xmm1_4
  float z; // xmm2_4
  UFG::qPropertySet *mpPropSet; // rbx
  UFG::qSymbol *v7; // rax
  __m128 v8; // xmm7
  __m128 v9; // xmm6
  __m128 v10; // xmm5
  UFG::allocator::free_link *v11; // rax
  UFG::SensorPhantom *v12; // rax
  hkAabb aabb; // [rsp+40h] [rbp-48h] BYREF

  *(_QWORD *)&this->mInsideDynamicRadiusCount = 0i64;
  this->mMaxHeatLevel = -1;
  this->mStartTimestamp = 0i64;
  *(_QWORD *)&this->mVehicleSpawnIteratingIndex = 0i64;
  this->mNumWaveGroupTypes = 0;
  mWaveGroupInstancesRequired = this->mWaveGroupInstancesRequired;
  v3 = 10i64;
  do
  {
    *(mWaveGroupInstancesRequired - 10) = 0;
    *mWaveGroupInstancesRequired = 0;
    mWaveGroupInstancesRequired[10] = 0;
    ++mWaveGroupInstancesRequired;
    --v3;
  }
  while ( v3 );
  y = UFG::qVector3::msZero.y;
  z = UFG::qVector3::msZero.z;
  this->mFocusTargetPosition.x = UFG::qVector3::msZero.x;
  this->mFocusTargetPosition.y = y;
  this->mFocusTargetPosition.z = z;
  *(_QWORD *)&this->mWaveCount = 0i64;
  *(_QWORD *)&this->mReducedRadiusPercentage = 1065353216i64;
  *(_QWORD *)&this->mWaveTimer = 0i64;
  *(_QWORD *)&this->mSpawnTimeout = 0i64;
  *(_WORD *)&this->mIsStaysOffSidewalk = 0;
  this->mIsCanTurnAround = 0;
  *(_DWORD *)&this->mIsReplenishing = 0x1000000;
  this->mEnableWaveTimerChangesByDisabledUnits = 0;
  this->mFocusTargetContext.mpSimObject = 0i64;
  this->mFocusTargetContext.mpVehicle = 0i64;
  this->mFocusTargetContext.mWaterContextTimer = 0.0;
  *(_DWORD *)&this->mFocusTargetContext.mIsOnFootRaw = 16777217;
  *(_WORD *)&this->mFocusTargetContext.mIsOnMeshHeuristic = 1;
  this->mFocusTargetContext.mOpenFiredWithHostage = 0;
  *(_QWORD *)&this->mVehicleSpawnCount = 0i64;
  *(_QWORD *)&this->mVehicleKillCount = 0i64;
  UFG::PropertySetHandle::Bind(&this->mProperties);
  mpPropSet = this->mProperties.mpPropSet;
  v7 = UFG::qPropertySet::Get<UFG::qSymbol>(
         mpPropSet,
         (UFG::qArray<unsigned long,0> *)&EncounterSym_replenish_style,
         DEPTH_RECURSE);
  if ( v7 )
    this->mReplenishStyle = v7->mUID == EncounterSym_by_wave_type.mUID;
  else
    this->mReplenishStyle = ReplenishStyle_TopUpByPopulation;
  ((void (__fastcall *)(UFG::EncounterBase *))this->vfptr[50].__vecDelDtor)(this);
  v8 = (__m128)*(unsigned int *)UFG::qPropertySet::Get<float>(
                                  mpPropSet,
                                  (UFG::qArray<unsigned long,0> *)&EncounterSym_vehicle_spawn_sensor_extent_x,
                                  DEPTH_RECURSE);
  v9 = (__m128)*(unsigned int *)UFG::qPropertySet::Get<float>(
                                  mpPropSet,
                                  (UFG::qArray<unsigned long,0> *)&EncounterSym_vehicle_spawn_sensor_extent_y,
                                  DEPTH_RECURSE);
  v10 = (__m128)*(unsigned int *)UFG::qPropertySet::Get<float>(
                                   mpPropSet,
                                   (UFG::qArray<unsigned long,0> *)&EncounterSym_vehicle_spawn_sensor_extent_z,
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
    this->mpVehicleSpawnSensor = v12;
  }
  else
  {
    this->mpVehicleSpawnSensor = 0i64;
  }
}

// File Line: 395
// RVA: 0x3F9820
void __fastcall UFG::EncounterBase::Shutdown(UFG::EncounterBase *this)
{
  UFG::SensorPhantom *mpVehicleSpawnSensor; // rcx
  signed int v3; // edi
  UFG::qPropertySet **mWaterHeatLevelProperties; // rsi
  UFG::qSymbol *mWaterHeatLevelPropertiesName; // rbp

  mpVehicleSpawnSensor = this->mpVehicleSpawnSensor;
  if ( mpVehicleSpawnSensor )
  {
    mpVehicleSpawnSensor->vfptr->__vecDelDtor(mpVehicleSpawnSensor, 1u);
    this->mpVehicleSpawnSensor = 0i64;
  }
  UFG::PropertySetHandle::Null(&this->mProperties);
  v3 = 0;
  mWaterHeatLevelProperties = this->mWaterHeatLevelProperties;
  mWaterHeatLevelPropertiesName = this->mWaterHeatLevelPropertiesName;
  do
  {
    this->vfptr[46].__vecDelDtor(this, v3);
    UFG::qSymbol::set_null(mWaterHeatLevelPropertiesName - 6);
    UFG::qSymbol::set_null(mWaterHeatLevelPropertiesName);
    ++v3;
    ++mWaterHeatLevelPropertiesName;
    *(mWaterHeatLevelProperties - 6) = 0i64;
    *mWaterHeatLevelProperties++ = 0i64;
  }
  while ( v3 < 6 );
}

// File Line: 416
// RVA: 0x3F8F60
void __fastcall UFG::EncounterBase::RemoveAllUnitsOnScene(UFG::EncounterBase *this, bool includeNonManaged)
{
  unsigned int i; // edi
  UFG::SimObject *m_pSimObject; // rsi
  UFG::SimObjectCharacter *LocalPlayer; // rax
  __int16 m_Flags; // dx
  UFG::VehicleOwnershipComponent *ComponentOfTypeHK; // rax
  UFG::SimObject *OwnedVehicle; // rbp
  unsigned int j; // edi
  UFG::SimObject *v10; // rsi

  for ( i = 0; i < this->mHumans.size; ++i )
  {
    m_pSimObject = this->mHumans.p[i]->m_pSimObject;
    if ( m_pSimObject )
    {
      UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&m_pSimObject->m_Name);
      UFG::qPrintChannel::Print(
        &UFG::gPrintChannel_HK_Encounters,
        OUTPUT_LEVEL_DEBUG,
        "[Encounters]:   Deleting (%s)\n");
      UFG::Simulation::QueueSimObjectToBeDestroyed(&UFG::gSim, m_pSimObject);
    }
  }
  this->mHumans.size = 0;
  LocalPlayer = UFG::GetLocalPlayer();
  if ( LocalPlayer
    && ((m_Flags = LocalPlayer->m_Flags, (m_Flags & 0x4000) != 0)
     || m_Flags < 0
     || (m_Flags & 0x2000) != 0
     || (m_Flags & 0x1000) != 0
      ? (ComponentOfTypeHK = (UFG::VehicleOwnershipComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                 LocalPlayer,
                                                                 UFG::VehicleOwnershipComponent::_TypeUID))
      : (ComponentOfTypeHK = (UFG::VehicleOwnershipComponent *)UFG::SimObject::GetComponentOfType(
                                                                 LocalPlayer,
                                                                 UFG::VehicleOwnershipComponent::_TypeUID)),
        ComponentOfTypeHK) )
  {
    OwnedVehicle = UFG::VehicleOwnershipComponent::GetOwnedVehicle(ComponentOfTypeHK);
  }
  else
  {
    OwnedVehicle = 0i64;
  }
  for ( j = 0; j < this->mVehicles.size; ++j )
  {
    v10 = this->mVehicles.p[j]->m_pSimObject;
    if ( v10 )
    {
      UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&v10->m_Name);
      if ( v10 == OwnedVehicle )
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
  this->mHumanSpawnRegions.size = 0;
  this->mVehicles.size = 0;
}

// File Line: 457
// RVA: 0x3F8790
bool __fastcall UFG::EncounterBase::IsInvalidReacquirePosition(UFG::EncounterBase *this, UFG::qVector3 *position)
{
  float *v4; // rax

  UFG::PropertySetHandle::Bind(&this->mProperties);
  v4 = UFG::qPropertySet::Get<float>(
         this->mProperties.mpPropSet,
         (UFG::qArray<unsigned long,0> *)&EncounterSym_invalid_reacquire_distance,
         DEPTH_RECURSE);
  return (float)((float)((float)(position->y - this->mFocusTargetPosition.y)
                       * (float)(position->y - this->mFocusTargetPosition.y))
               + (float)((float)(position->x - this->mFocusTargetPosition.x)
                       * (float)(position->x - this->mFocusTargetPosition.x))) > (float)(*v4 * *v4);
}

// File Line: 473
// RVA: 0x3F8710
bool __fastcall UFG::EncounterBase::IsInvalidOnFootPosition(UFG::EncounterBase *this, UFG::qVector3 *position)
{
  float *v4; // rax

  UFG::PropertySetHandle::Bind(&this->mProperties);
  v4 = UFG::qPropertySet::Get<float>(
         this->mProperties.mpPropSet,
         (UFG::qArray<unsigned long,0> *)&EncounterSym_invalid_onfoot_distance,
         DEPTH_RECURSE);
  return (float)((float)((float)(position->y - this->mFocusTargetPosition.y)
                       * (float)(position->y - this->mFocusTargetPosition.y))
               + (float)((float)(position->x - this->mFocusTargetPosition.x)
                       * (float)(position->x - this->mFocusTargetPosition.x))) > (float)(*v4 * *v4);
}

// File Line: 489
// RVA: 0x3F8810
bool __fastcall UFG::EncounterBase::IsInvalidVehiclePosition(UFG::EncounterBase *this, UFG::qVector3 *position)
{
  UFG::qStaticSymbol *v3; // rdi
  float *v5; // rax
  float v6; // xmm1_4

  v3 = &EncounterSym_invalid_vehicle_distance;
  if ( this->mFocusTargetContext.mIsInWater )
    v3 = &EncounterSym_invalid_water_vehicle_distance;
  UFG::PropertySetHandle::Bind(&this->mProperties);
  v5 = UFG::qPropertySet::Get<float>(this->mProperties.mpPropSet, (UFG::qArray<unsigned long,0> *)v3, DEPTH_RECURSE);
  v6 = position->y - this->mFocusTargetPosition.y;
  return (float)((float)(v6 * v6)
               + (float)((float)(position->x - this->mFocusTargetPosition.x)
                       * (float)(position->x - this->mFocusTargetPosition.x))) > (float)(*v5 * *v5);
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
  UFG::qPropertySet *v2; // rax
  UFG::qPropertySet *v3; // rdi
  int v4; // r15d
  int v5; // r12d
  UFG::qPropertyList *v6; // rax
  unsigned int mNumElements; // edx
  unsigned int v8; // esi
  char *ValuePtr; // rax
  UFG::qPropertySet *v10; // rdi
  char *v11; // r14
  UFG::qSymbol *v12; // r13
  unsigned int *v13; // rax
  int v14; // ecx
  UFG::EncounterBase::ReplenishStyle mReplenishStyle; // ecx
  UFG::qSymbol *v16; // [rsp+60h] [rbp+8h]
  UFG::qPropertyList *v17; // [rsp+68h] [rbp+10h]
  UFG::qPropertySet *v18; // [rsp+70h] [rbp+18h]

  v2 = (UFG::qPropertySet *)((__int64 (*)(void))this->vfptr[33].__vecDelDtor)();
  v3 = v2;
  v18 = v2;
  if ( v2 )
  {
    v4 = 0;
    v5 = 0;
    v6 = UFG::qPropertySet::Get<UFG::qPropertyList>(
           v2,
           (UFG::qArray<unsigned long,0> *)&EncounterSym_spawn_groups,
           DEPTH_RECURSE);
    mNumElements = 10;
    v8 = 0;
    v17 = v6;
    if ( v6->mNumElements < 0xA )
      mNumElements = v6->mNumElements;
    this->mNumWaveGroupTypes = mNumElements;
    if ( mNumElements )
    {
      do
      {
        ValuePtr = UFG::qPropertyList::GetValuePtr(v6, 0x1Au, v8);
        if ( !ValuePtr || (v10 = (UFG::qPropertySet *)&ValuePtr[*(_QWORD *)ValuePtr], !*(_QWORD *)ValuePtr) )
          v10 = 0i64;
        v11 = (char *)this + 4 * v8;
        *((_DWORD *)v11 + 216) = 0;
        v12 = UFG::qPropertySet::Get<UFG::qSymbol>(
                v10,
                (UFG::qArray<unsigned long,0> *)&EncounterSym_boat,
                DEPTH_RECURSE);
        v16 = UFG::qPropertySet::Get<UFG::qSymbol>(
                v10,
                (UFG::qArray<unsigned long,0> *)&EncounterSym_vehicle,
                DEPTH_RECURSE);
        v13 = UFG::qPropertySet::Get<unsigned long>(
                v10,
                (UFG::qArray<unsigned long,0> *)&EncounterSym_num_instances,
                DEPTH_RECURSE);
        if ( v13 )
          v14 = *v13;
        else
          v14 = 1;
        this->mWaveGroupInstancesRequired[v8] = v14;
        if ( v12 || v16 )
        {
          *((_DWORD *)v11 + 216) = 2;
          v4 += v14;
        }
        else
        {
          *((_DWORD *)v11 + 216) = 1;
          v5 += v14;
        }
        v6 = v17;
        ++v8;
      }
      while ( v8 < this->mNumWaveGroupTypes );
      v3 = v18;
    }
    mReplenishStyle = this->mReplenishStyle;
    if ( mReplenishStyle )
    {
      if ( mReplenishStyle == ReplenishStyle_TopUpByWaveType )
      {
        this->mNumDesiredVehicleGroups = v4;
        this->mNumDesiredCharacterGroups = v5;
      }
    }
    else
    {
      this->mNumDesiredVehicleGroups = *UFG::qPropertySet::Get<unsigned long>(
                                          v3,
                                          (UFG::qArray<unsigned long,0> *)&EncounterSym_vehicle_population,
                                          DEPTH_RECURSE);
      this->mNumDesiredCharacterGroups = *UFG::qPropertySet::Get<unsigned long>(
                                            v3,
                                            (UFG::qArray<unsigned long,0> *)&EncounterSym_onfoot_population,
                                            DEPTH_RECURSE);
    }
  }
  if ( this->mHeatLevel == HEATLEVEL_NONE )
  {
    *(_QWORD *)&this->mVehicleSpawnCount = 0i64;
    *(_QWORD *)&this->mVehicleKillCount = 0i64;
  }
}

// File Line: 593
// RVA: 0x3F6110
void __fastcall UFG::EncounterBase::HandleHeatLevelChange(UFG::EncounterBase *this)
{
  UFG::qPropertySet *v2; // rax
  signed int v3; // ebp
  UFG::qPropertySet *v4; // rbx
  UFG::eAIObjective mPostObjective; // r15d
  bool v6; // cl
  unsigned int v7; // r14d
  UFG::SimObject *i; // r12
  UFG::SimObjectGame *m_pSimObject; // rbx
  __int16 m_Flags; // cx
  UFG::ActiveAIEntityComponent *ComponentOfTypeHK; // rax
  bool v12; // zf
  UFG::SimObjectGame *v13; // rcx
  __int16 v14; // cx
  UFG::ActiveAIEntityComponent *v15; // rsi
  UFG::TargetingSystemBaseComponent *m_pComponent; // rbx
  UFG::SimComponent *v17; // rax
  signed int j; // ebx

  v2 = (UFG::qPropertySet *)((__int64 (*)(void))this->vfptr[33].__vecDelDtor)();
  v3 = 0;
  v4 = v2;
  if ( v2 )
  {
    this->mIsAvoidPeds = *UFG::qPropertySet::Get<bool>(
                            v2,
                            (UFG::qArray<unsigned long,0> *)&EncounterSym_vehicle_avoid_peds,
                            DEPTH_RECURSE);
    this->mIsAllowedToPass = *UFG::qPropertySet::Get<bool>(
                                v4,
                                (UFG::qArray<unsigned long,0> *)&EncounterSym_vehicle_allowed_to_pass,
                                DEPTH_RECURSE);
    this->mIsStaysOffSidewalk = *UFG::qPropertySet::Get<bool>(
                                   v4,
                                   (UFG::qArray<unsigned long,0> *)&EncounterSym_vehicle_stays_off_sidewalk,
                                   DEPTH_RECURSE);
    this->mIsRespectSpeedLimit = *UFG::qPropertySet::Get<bool>(
                                    v4,
                                    (UFG::qArray<unsigned long,0> *)&EncounterSym_vehicle_respect_speed_limit,
                                    DEPTH_RECURSE);
    mPostObjective = eAI_OBJECTIVE_NONE;
    v6 = *UFG::qPropertySet::Get<bool>(
            v4,
            (UFG::qArray<unsigned long,0> *)&EncounterSym_vehicle_can_turn_around,
            DEPTH_RECURSE);
    if ( this->mPostObjective < NUM_AI_OBJECTIVES )
      mPostObjective = this->mPostObjective;
    this->mIsCanTurnAround = v6;
    if ( this->mHeatLevel > HEATLEVEL_NONE )
      mPostObjective = this->mObjective;
    v7 = 0;
    for ( i = (UFG::SimObject *)((__int64 (__fastcall *)(UFG::EncounterBase *))this->vfptr[18].__vecDelDtor)(this);
          v7 < this->mHumans.size;
          ++v7 )
    {
      m_pSimObject = (UFG::SimObjectGame *)this->mHumans.p[v7]->m_pSimObject;
      if ( m_pSimObject )
      {
        m_Flags = m_pSimObject->m_Flags;
        if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
        {
          ComponentOfTypeHK = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>((UFG::SimObjectCVBase *)this->mHumans.p[v7]->m_pSimObject);
        }
        else if ( (m_Flags & 0x2000) != 0 )
        {
          ComponentOfTypeHK = (UFG::ActiveAIEntityComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                (UFG::SimObjectGame *)this->mHumans.p[v7]->m_pSimObject,
                                                                UFG::ActiveAIEntityComponent::_TypeUID);
        }
        else
        {
          v12 = (m_Flags & 0x1000) == 0;
          v13 = (UFG::SimObjectGame *)this->mHumans.p[v7]->m_pSimObject;
          ComponentOfTypeHK = (UFG::ActiveAIEntityComponent *)(v12
                                                             ? UFG::SimObject::GetComponentOfType(
                                                                 v13,
                                                                 UFG::ActiveAIEntityComponent::_TypeUID)
                                                             : UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                 v13,
                                                                 UFG::ActiveAIEntityComponent::_TypeUID));
        }
        v14 = m_pSimObject->m_Flags;
        v15 = ComponentOfTypeHK;
        if ( (v14 & 0x4000) != 0 )
        {
          m_pComponent = (UFG::TargetingSystemBaseComponent *)m_pSimObject->m_Components.p[20].m_pComponent;
        }
        else if ( v14 >= 0 )
        {
          v17 = (v14 & 0x2000) != 0 || (v14 & 0x1000) != 0
              ? UFG::SimObjectGame::GetComponentOfTypeHK(m_pSimObject, UFG::TargetingSystemBaseComponent::_TypeUID)
              : UFG::SimObject::GetComponentOfType(m_pSimObject, UFG::TargetingSystemBaseComponent::_TypeUID);
          m_pComponent = (UFG::TargetingSystemBaseComponent *)v17;
        }
        else
        {
          m_pComponent = (UFG::TargetingSystemBaseComponent *)m_pSimObject->m_Components.p[20].m_pComponent;
        }
        if ( v15 && m_pComponent )
        {
          UFG::ActiveAIEntityComponent::SetCurrentObjective(v15, mPostObjective, "EncounterBase::HandleHeatLevelChange");
          UFG::TargetingSystemBaseComponent::SetTarget(m_pComponent, eTARGET_TYPE_AI_OBJECTIVE, i);
        }
      }
    }
  }
  ((void (__fastcall *)(UFG::EncounterBase *))this->vfptr[49].__vecDelDtor)(this);
  for ( j = 0; j < 6; ++j )
  {
    if ( j == this->mHeatLevel )
      this->vfptr[45].__vecDelDtor(this, j);
  }
  do
  {
    if ( v3 != this->mHeatLevel )
      this->vfptr[46].__vecDelDtor(this, v3);
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
  unsigned int mNumElements; // esi
  UFG::qPropertyList *v8; // rbp
  UFG::qSymbol *v9; // rax
  UFG::qPropertySet *PropertySet; // rdi
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
             (UFG::qArray<unsigned long,0> *)&EncounterSym_persistent_resources,
             DEPTH_RECURSE);
      v6 = 0;
      mNumElements = v5->mNumElements;
      v8 = v5;
      if ( mNumElements )
      {
        do
        {
          v9 = UFG::qPropertyList::Get<UFG::qSymbol>(v8, v6);
          if ( v9 )
          {
            PropertySet = UFG::PropertySetManager::GetPropertySet(v9);
            v11 = UFG::ObjectResourceManager::Instance();
            UFG::ObjectResourceManager::PreLoadCriticalResource(v11, PropertySet);
          }
          ++v6;
        }
        while ( v6 < mNumElements );
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
  unsigned int mNumElements; // esi
  unsigned int i; // ebx
  UFG::qSymbol *v9; // rax
  UFG::qPropertySet *PropertySet; // rdi
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
             (UFG::qArray<unsigned long,0> *)&EncounterSym_persistent_resources,
             DEPTH_RECURSE);
      v6 = v5;
      if ( v5 )
      {
        mNumElements = v5->mNumElements;
        for ( i = 0; i < mNumElements; ++i )
        {
          v9 = UFG::qPropertyList::Get<UFG::qSymbol>(v6, i);
          if ( v9 )
          {
            PropertySet = UFG::PropertySetManager::GetPropertySet(v9);
            v11 = UFG::ObjectResourceManager::Instance();
            UFG::ObjectResourceManager::ReleaseCriticalResource(v11, PropertySet);
          }
        }
      }
    }
  }
}

// File Line: 709
// RVA: 0x3FB4E0
void __fastcall UFG::EncounterBase::UpdateVehicleFlags(UFG::EncounterBase *this, UFG::SimObjectCVBase *pSimObject)
{
  signed __int16 m_Flags; // dx
  UFG::AiDriverComponent *ComponentOfTypeHK; // rax
  UFG::AiDriverComponent *v6; // rdi
  signed __int16 v7; // cx
  UFG::SimComponent *m_pComponent; // rbx
  UFG::SimComponent *ComponentOfType; // rax
  bool v10; // cl

  if ( pSimObject )
  {
    m_Flags = pSimObject->m_Flags;
    if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
    {
      ComponentOfTypeHK = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(pSimObject);
    }
    else if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
    {
      ComponentOfTypeHK = (UFG::AiDriverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                      pSimObject,
                                                      UFG::AiDriverComponent::_TypeUID);
    }
    else
    {
      ComponentOfTypeHK = (UFG::AiDriverComponent *)UFG::SimObject::GetComponentOfType(
                                                      pSimObject,
                                                      UFG::AiDriverComponent::_TypeUID);
    }
    v6 = ComponentOfTypeHK;
    if ( ComponentOfTypeHK )
    {
      UFG::AiDriverComponent::SetAvoidPeds(ComponentOfTypeHK, this->mIsAvoidPeds);
      UFG::AiDriverComponent::SetAllowedToPass(v6, this->mIsAllowedToPass);
      UFG::AiDriverComponent::SetStayOffSidewalk(v6, this->mIsStaysOffSidewalk);
      UFG::AiDriverComponent::SetRespectSpeedLimit(v6, this->mIsRespectSpeedLimit);
      UFG::AiDriverComponent::SetCanTurnAround(v6, this->mIsCanTurnAround);
    }
    v7 = pSimObject->m_Flags;
    if ( (v7 & 0x4000) != 0 )
    {
      m_pComponent = pSimObject->m_Components.p[24].m_pComponent;
    }
    else if ( v7 >= 0 )
    {
      if ( (v7 & 0x2000) != 0 || (v7 & 0x1000) != 0 )
        ComponentOfType = UFG::SimObjectGame::GetComponentOfTypeHK(pSimObject, UFG::RoadSpaceComponent::_TypeUID);
      else
        ComponentOfType = UFG::SimObject::GetComponentOfType(pSimObject, UFG::RoadSpaceComponent::_TypeUID);
      m_pComponent = ComponentOfType;
    }
    else
    {
      m_pComponent = pSimObject->m_Components.p[24].m_pComponent;
    }
    if ( m_pComponent )
    {
      UFG::RoadSpaceComponent::SetLaneFlags((UFG::RoadSpaceComponent *)m_pComponent, 1u);
      v10 = this->mHeatLevel != HEATLEVEL_NONE;
      m_pComponent[30].m_TypeUID &= ~2u;
      m_pComponent[30].m_TypeUID |= 2 * v10;
    }
  }
}

// File Line: 736
// RVA: 0x3F3DC0
bool __fastcall UFG::EncounterBase::FindGoodSpawnLocationCharacter(
        UFG::EncounterBase *this,
        UFG::qPropertySet *pProperties,
        UFG::TransformNodeComponent *pTargetTransform,
        UFG::qVector3 *pResult)
{
  unsigned int size; // ecx
  int v8; // eax
  bool v9; // al
  UFG::qPropertySet *mpPropSet; // rbx
  float v11; // xmm6_4
  float *v12; // rax
  float v13; // xmm6_4
  UFG::qNode<UFG::AIMarker,UFG::AIMarker> *v14; // rdi
  UFG::qNode<UFG::AIMarker,UFG::AIMarker> *v15; // rbp
  UFG::qNode<UFG::AIMarker,UFG::AIMarker> *mNext; // rbx
  UFG::TransformNodeComponent *v17; // rbx
  __m128 y_low; // xmm2
  float v19; // xmm1_4
  float v20; // xmm1_4
  float *v21; // rbx
  float v22; // xmm0_4
  float v23; // xmm1_4
  UFG::qVector3 result; // [rsp+30h] [rbp-38h] BYREF

  size = this->mHumanSpawnRegions.size;
  if ( size )
  {
    v8 = UFG::qRandom(size, (unsigned int *)&UFG::qDefaultSeed);
    UFG::RegionComponent::GetRandomPosition(this->mHumanSpawnRegions.p[v8], &result);
    return UFG::SimObjectUtility::PlaceOnGround(pResult, &result, 0.050000001, 5.0)
        && (!*UFG::qPropertySet::Get<bool>(
                pProperties,
                (UFG::qArray<unsigned long,0> *)&EncounterSym_offscreen_spawn_only,
                DEPTH_RECURSE)
         || !UFG::SimObjectUtility::IsPositionOnScreen(&result, 2.0, 0));
  }
  else
  {
    UFG::PropertySetHandle::Bind(&this->mProperties);
    mpPropSet = this->mProperties.mpPropSet;
    v11 = *UFG::qPropertySet::Get<float>(
             mpPropSet,
             (UFG::qArray<unsigned long,0> *)&EncounterSym_character_generic_spawn_min_radius,
             DEPTH_RECURSE);
    v12 = UFG::qPropertySet::Get<float>(
            mpPropSet,
            (UFG::qArray<unsigned long,0> *)&EncounterSym_character_generic_spawn_max_radius,
            DEPTH_RECURSE);
    if ( (unsigned __int8)UFG::SimObjectUtility::FindSpawnCharacterPosition(&this->mFocusTargetPosition, v11, *v12, 1) )
    {
      return 1;
    }
    else if ( this->mFocusTargetContext.mIsInsideInterior )
    {
      v13 = FLOAT_N1_0;
      v14 = UFG::AIMarker::s_AIReinforcementPointList.mNode.mNext - 7;
      v15 = 0i64;
      if ( (UFG::qList<UFG::AIMarker,UFG::AIMarker,1,0> *)&UFG::AIMarker::s_AIReinforcementPointList.mNode.mNext[-7] == &UFG::AIMarker::s_AIReinforcementPointList - 7 )
        return 0;
      do
      {
        mNext = v14[6].mNext;
        if ( mNext )
        {
          UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v14[6].mNext);
          if ( !this->vfptr[59].__vecDelDtor(this, &mNext[11]) )
          {
            v17 = (UFG::TransformNodeComponent *)v14[6].mNext;
            UFG::TransformNodeComponent::UpdateWorldTransform(v17);
            y_low = (__m128)LODWORD(this->mFocusTargetPosition.y);
            v19 = this->mFocusTargetPosition.x - v17->mWorldTransform.v3.x;
            y_low.m128_f32[0] = (float)((float)((float)(y_low.m128_f32[0] - v17->mWorldTransform.v3.y)
                                              * (float)(y_low.m128_f32[0] - v17->mWorldTransform.v3.y))
                                      + (float)(v19 * v19))
                              + (float)((float)(this->mFocusTargetPosition.z - v17->mWorldTransform.v3.z)
                                      * (float)(this->mFocusTargetPosition.z - v17->mWorldTransform.v3.z));
            LODWORD(v20) = _mm_sqrt_ps(y_low).m128_u32[0];
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
        pResult->x = v21[44];
        v9 = 1;
        pResult->y = v22;
        pResult->z = v23;
      }
      else
      {
        return 0;
      }
    }
    else
    {
      return 0;
    }
  }
  return v9;
}

// File Line: 808
// RVA: 0x3F5FC0
__int64 __fastcall UFG::EncounterBase::GetDesiredVehiclePopulation(
        UFG::EncounterBase *this,
        UFG::qPropertySet *heatPropSet)
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
        return (unsigned int)v3;
    }
    else
    {
      return (unsigned int)this->mNumDesiredVehicleGroups;
    }
  }
  return result;
}

// File Line: 825
// RVA: 0x3F5FB0
__int64 __fastcall UFG::EncounterBase::GetDesiredOnFootPopulation(
        UFG::EncounterBase *this,
        UFG::qPropertySet *heatPropSet)
{
  if ( this->mEnable )
    return (unsigned int)this->mNumDesiredCharacterGroups;
  else
    return 0i64;
}

// File Line: 835
// RVA: 0x3F4150
void __fastcall UFG::EncounterBase::Forget(
        UFG::EncounterBase *this,
        UFG::EncounterUnitComponent *pEncounterUnitComponent)
{
  UFG::SimObject *m_pSimObject; // rdi
  UFG::SimObjectGame *v5; // r8
  __int16 v6; // cx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  bool v8; // zf
  UFG::qPropertySet *v9; // rax
  float *v10; // rax
  float v11; // xmm0_4
  __int16 v12; // cx
  UFG::VehicleOccupantComponent *v13; // rsi
  UFG::SimComponent *ComponentOfType; // rax
  unsigned int v15; // ebx
  unsigned int NumberOfOccupants; // ebp
  UFG::SimObjectGame *Occupant; // rax
  __int16 v18; // dx
  UFG::SimComponent *v19; // rax
  __int16 v20; // cx
  UFG::SimComponent *v21; // rbx
  UFG::SimComponent *v22; // rax
  UFG::SimObjectGame *CurrentVehicle; // rax
  __int16 v24; // dx
  UFG::SimComponent *v25; // rax
  __int16 v26; // cx
  UFG::StreamedResourceComponent *v27; // rbx
  UFG::SimComponent *v28; // rax
  __int16 v29; // cx
  UFG::SimComponent *v30; // rax
  __int16 v31; // cx
  UFG::AiDriverComponent *v32; // rax
  UFG::AiDriverComponent *v33; // rbx
  __int16 v34; // cx
  UFG::ActiveAIEntityComponent *v35; // rax
  UFG::ActiveAIEntityComponent *v36; // rbx
  UFG::eAIObjective mPostObjective; // edx
  __int16 v38; // cx
  UFG::SimComponent *v39; // rsi
  UFG::SimComponent *v40; // rax
  unsigned __int8 v41; // cl
  __int64 v42; // rbx
  UFG::PedSpawnManager *Instance; // rax
  UFG::SimObjectCharacter *v44; // rax
  __int16 v45; // dx
  UFG::SimComponent *v46; // rax
  UFG::VehicleOccupantComponent *v47; // rsi
  unsigned int i; // edi
  UFG::SimObjectGame *v49; // rax
  UFG::SimObjectGame *v50; // r8
  __int16 v51; // dx
  UFG::SimComponent *v52; // rbx
  UFG::SimObjectGame *v53; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rax
  UFG::qSymbol symbol; // [rsp+48h] [rbp+10h] BYREF

  m_pSimObject = pEncounterUnitComponent->m_pSimObject;
  if ( !m_pSimObject )
  {
LABEL_148:
    v53 = (UFG::SimObjectGame *)pEncounterUnitComponent->m_pSimObject;
    if ( v53 )
    {
      m_Flags = v53->m_Flags;
      if ( (m_Flags & 0x4000) != 0 )
      {
        m_pComponent = v53->m_Components.p[17].m_pComponent;
      }
      else if ( m_Flags >= 0 )
      {
        if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
          m_pComponent = UFG::SimObjectGame::GetComponentOfTypeHK(v53, UFG::CopUnitComponent::_TypeUID);
        else
          m_pComponent = UFG::SimObject::GetComponentOfType(v53, UFG::CopUnitComponent::_TypeUID);
      }
      else
      {
        m_pComponent = v53->m_Components.p[17].m_pComponent;
      }
      if ( m_pComponent )
      {
        LOBYTE(m_pComponent[7].m_Flags) &= ~1u;
        LOBYTE(m_pComponent[7].m_Flags) |= 4u;
        pEncounterUnitComponent->mAcquiredTimer = 0.0;
      }
    }
    UFG::EncounterUnitComponent::ReleaseByEncounter(pEncounterUnitComponent);
    return;
  }
  UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&m_pSimObject->m_Name);
  UFG::qPrintChannel::Print(
    &UFG::gPrintChannel_HK_Encounters,
    OUTPUT_LEVEL_DEBUG,
    "[Encounters]: Forgetting unit (%s)\n");
  if ( pEncounterUnitComponent->mEnableKillCount )
  {
    v5 = (UFG::SimObjectGame *)pEncounterUnitComponent->m_pSimObject;
    pEncounterUnitComponent->mEnableKillCount = 0;
    if ( v5 )
    {
      v6 = v5->m_Flags;
      if ( (v6 & 0x4000) == 0 )
      {
        if ( v6 < 0 )
        {
          ComponentOfTypeHK = v5->m_Components.p[34].m_pComponent;
          goto LABEL_11;
        }
        if ( (v6 & 0x2000) == 0 )
        {
          if ( (v6 & 0x1000) != 0 )
            ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(v5, UFG::PhysicsMoverInterface::_TypeUID);
          else
            ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(v5, UFG::PhysicsMoverInterface::_TypeUID);
LABEL_11:
          if ( ComponentOfTypeHK )
          {
            if ( !pEncounterUnitComponent->mUnitDisabled )
              goto LABEL_68;
            ++this->mVehicleKillCount;
            v8 = !this->mEnableWaveTimerChangesByDisabledUnits;
            this->mDisabledUnitForCurrentWave = 1;
            if ( !v8 && this->mWaveTimer >= 0.0 )
            {
              v9 = (UFG::qPropertySet *)((__int64 (__fastcall *)(UFG::EncounterBase *))this->vfptr[33].__vecDelDtor)(this);
              if ( v9
                && (v10 = UFG::qPropertySet::Get<float>(
                            v9,
                            (UFG::qArray<unsigned long,0> *)&EncounterSym_vehicle_kill_bonus_timer,
                            DEPTH_RECURSE)) != 0i64 )
              {
                v11 = *v10;
              }
              else
              {
                v11 = FLOAT_2_0;
              }
              this->mWaveTimer = v11 + this->mWaveTimer;
            }
            v12 = m_pSimObject->m_Flags;
            if ( (v12 & 0x4000) != 0 )
              goto LABEL_26;
            if ( v12 < 0 )
            {
              v13 = (UFG::VehicleOccupantComponent *)m_pSimObject->m_Components.p[30].m_pComponent;
LABEL_29:
              if ( v13 )
              {
                v15 = 0;
                NumberOfOccupants = UFG::VehicleOccupantComponent::GetNumberOfOccupants(v13);
                if ( NumberOfOccupants )
                {
                  do
                  {
                    Occupant = (UFG::SimObjectGame *)UFG::VehicleOccupantComponent::GetOccupant(v13, v15, 0i64);
                    if ( Occupant )
                    {
                      v18 = Occupant->m_Flags;
                      if ( (v18 & 0x4000) != 0 )
                      {
                        v19 = Occupant->m_Components.p[16].m_pComponent;
                      }
                      else if ( v18 >= 0 )
                      {
                        v19 = (v18 & 0x2000) != 0 || (v18 & 0x1000) != 0
                            ? UFG::SimObjectGame::GetComponentOfTypeHK(Occupant, UFG::EncounterUnitComponent::_TypeUID)
                            : UFG::SimObject::GetComponentOfType(Occupant, UFG::EncounterUnitComponent::_TypeUID);
                      }
                      else
                      {
                        v19 = Occupant->m_Components.p[16].m_pComponent;
                      }
                      if ( v19 )
                        LOBYTE(v19[2].m_SafePointerList.mNode.mNext) = 0;
                    }
                    ++v15;
                  }
                  while ( v15 < NumberOfOccupants );
                }
              }
              goto LABEL_68;
            }
            if ( (v12 & 0x2000) != 0 || (v12 & 0x1000) != 0 )
LABEL_26:
              ComponentOfType = UFG::SimObjectGame::GetComponentOfTypeHK(
                                  (UFG::SimObjectGame *)m_pSimObject,
                                  UFG::VehicleOccupantComponent::_TypeUID);
            else
              ComponentOfType = UFG::SimObject::GetComponentOfType(
                                  m_pSimObject,
                                  UFG::VehicleOccupantComponent::_TypeUID);
            v13 = (UFG::VehicleOccupantComponent *)ComponentOfType;
            goto LABEL_29;
          }
        }
      }
    }
    if ( !this->vfptr[78].__vecDelDtor(this, pEncounterUnitComponent) )
      ++this->mCharacterKillCount;
    v20 = m_pSimObject->m_Flags;
    if ( (v20 & 0x4000) != 0 )
    {
      v21 = m_pSimObject->m_Components.p[44].m_pComponent;
    }
    else
    {
      if ( v20 < 0 || (v20 & 0x2000) != 0 || (v20 & 0x1000) != 0 )
        v22 = UFG::SimObjectGame::GetComponentOfTypeHK(
                (UFG::SimObjectGame *)m_pSimObject,
                UFG::CharacterOccupantComponent::_TypeUID);
      else
        v22 = UFG::SimObject::GetComponentOfType(m_pSimObject, UFG::CharacterOccupantComponent::_TypeUID);
      v21 = v22;
    }
    if ( v21 )
    {
      CurrentVehicle = (UFG::SimObjectGame *)UFG::CharacterOccupantComponent::GetCurrentVehicle((UFG::CharacterOccupantComponent *)v21);
      if ( CurrentVehicle )
      {
        if ( LODWORD(v21[1].m_SafePointerList.mNode.mNext) == 4 )
        {
          v24 = CurrentVehicle->m_Flags;
          if ( (v24 & 0x4000) != 0 )
          {
            v25 = CurrentVehicle->m_Components.p[16].m_pComponent;
          }
          else if ( v24 >= 0 )
          {
            v25 = (v24 & 0x2000) != 0 || (v24 & 0x1000) != 0
                ? UFG::SimObjectGame::GetComponentOfTypeHK(CurrentVehicle, UFG::EncounterUnitComponent::_TypeUID)
                : UFG::SimObject::GetComponentOfType(CurrentVehicle, UFG::EncounterUnitComponent::_TypeUID);
          }
          else
          {
            v25 = CurrentVehicle->m_Components.p[16].m_pComponent;
          }
          if ( v25 )
            LOBYTE(v25[2].m_SafePointerList.mNode.mNext) = 0;
        }
      }
    }
  }
LABEL_68:
  v26 = m_pSimObject->m_Flags;
  if ( (v26 & 0x4000) != 0 )
  {
    v27 = (UFG::StreamedResourceComponent *)m_pSimObject->m_Components.p[10].m_pComponent;
  }
  else if ( v26 >= 0 )
  {
    if ( (v26 & 0x2000) != 0 )
    {
      v27 = (UFG::StreamedResourceComponent *)m_pSimObject->m_Components.p[7].m_pComponent;
    }
    else
    {
      if ( (v26 & 0x1000) != 0 )
        v28 = UFG::SimObjectGame::GetComponentOfTypeHK(
                (UFG::SimObjectGame *)m_pSimObject,
                UFG::StreamedResourceComponent::_TypeUID);
      else
        v28 = UFG::SimObject::GetComponentOfType(m_pSimObject, UFG::StreamedResourceComponent::_TypeUID);
      v27 = (UFG::StreamedResourceComponent *)v28;
    }
  }
  else
  {
    v27 = (UFG::StreamedResourceComponent *)m_pSimObject->m_Components.p[10].m_pComponent;
  }
  if ( v27 )
  {
    symbol.mUID = v27->mActivePriority.mUID;
    UFG::StreamedResourceComponent::IncrementPriorityReferenceCount(v27, &qSymbol_Low);
    UFG::StreamedResourceComponent::DecrementPriorityReferenceCount(v27, &symbol);
  }
  v29 = m_pSimObject->m_Flags;
  if ( (v29 & 0x4000) != 0 )
  {
    v30 = m_pSimObject->m_Components.p[24].m_pComponent;
  }
  else if ( v29 >= 0 )
  {
    if ( (v29 & 0x2000) != 0 || (v29 & 0x1000) != 0 )
      v30 = UFG::SimObjectGame::GetComponentOfTypeHK(
              (UFG::SimObjectGame *)m_pSimObject,
              UFG::RoadSpaceComponent::_TypeUID);
    else
      v30 = UFG::SimObject::GetComponentOfType(m_pSimObject, UFG::RoadSpaceComponent::_TypeUID);
  }
  else
  {
    v30 = m_pSimObject->m_Components.p[24].m_pComponent;
  }
  if ( v30 )
  {
    v31 = m_pSimObject->m_Flags;
    if ( (v31 & 0x4000) != 0 || v31 < 0 )
      v32 = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>((UFG::SimObjectCVBase *)m_pSimObject);
    else
      v32 = (UFG::AiDriverComponent *)((v31 & 0x2000) != 0 || (v31 & 0x1000) != 0
                                     ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                         (UFG::SimObjectGame *)m_pSimObject,
                                         UFG::AiDriverComponent::_TypeUID)
                                     : UFG::SimObject::GetComponentOfType(
                                         m_pSimObject,
                                         UFG::AiDriverComponent::_TypeUID));
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
  v34 = m_pSimObject->m_Flags;
  if ( (v34 & 0x4000) != 0 || v34 < 0 )
  {
    v35 = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>((UFG::SimObjectCVBase *)m_pSimObject);
  }
  else if ( (v34 & 0x2000) != 0 || (v34 & 0x1000) != 0 )
  {
    v35 = (UFG::ActiveAIEntityComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                            (UFG::SimObjectGame *)m_pSimObject,
                                            UFG::ActiveAIEntityComponent::_TypeUID);
  }
  else
  {
    v35 = (UFG::ActiveAIEntityComponent *)UFG::SimObject::GetComponentOfType(
                                            m_pSimObject,
                                            UFG::ActiveAIEntityComponent::_TypeUID);
  }
  v36 = v35;
  if ( v35 )
  {
    mPostObjective = this->mPostObjective;
    if ( mPostObjective >= NUM_AI_OBJECTIVES )
      mPostObjective = eAI_OBJECTIVE_NONE;
    UFG::ActiveAIEntityComponent::SetCurrentObjective(v35, mPostObjective, "EncounterBase::Forget");
    v36->m_bCanWander = 1;
  }
  v38 = m_pSimObject->m_Flags;
  if ( (v38 & 0x4000) != 0 )
  {
    v39 = m_pSimObject->m_Components.p[20].m_pComponent;
  }
  else if ( v38 >= 0 )
  {
    if ( (v38 & 0x2000) != 0 || (v38 & 0x1000) != 0 )
      v40 = UFG::SimObjectGame::GetComponentOfTypeHK(
              (UFG::SimObjectGame *)m_pSimObject,
              UFG::TargetingSystemBaseComponent::_TypeUID);
    else
      v40 = UFG::SimObject::GetComponentOfType(m_pSimObject, UFG::TargetingSystemBaseComponent::_TypeUID);
    v39 = v40;
  }
  else
  {
    v39 = m_pSimObject->m_Components.p[20].m_pComponent;
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
  Instance = UFG::PedSpawnManager::GetInstance();
  UFG::PedSpawnManager::SetSuspendOption(Instance, m_pSimObject, DeleteOnSuspend);
  v44 = UFG::PedSpawnManager::ReleaseOwnership(m_pSimObject, 4u, 1);
  if ( v44 )
  {
    v45 = v44->m_Flags;
    if ( (v45 & 0x4000) != 0 )
      goto LABEL_124;
    if ( v45 < 0 )
    {
      v47 = (UFG::VehicleOccupantComponent *)v44->m_Components.p[30].m_pComponent;
LABEL_132:
      if ( v47 )
      {
        for ( i = 0; i < (unsigned int)UFG::VehicleOccupantComponent::GetNumberOfOccupants(v47); ++i )
        {
          v49 = (UFG::SimObjectGame *)UFG::VehicleOccupantComponent::GetOccupant(v47, i, 0i64);
          v50 = v49;
          if ( v49 )
          {
            v51 = v49->m_Flags;
            if ( (v51 & 0x4000) != 0 )
            {
              v52 = v49->m_Components.p[16].m_pComponent;
            }
            else if ( v51 >= 0 )
            {
              if ( (v51 & 0x2000) != 0 || (v51 & 0x1000) != 0 )
                v52 = UFG::SimObjectGame::GetComponentOfTypeHK(v49, UFG::EncounterUnitComponent::_TypeUID);
              else
                v52 = UFG::SimObject::GetComponentOfType(v49, UFG::EncounterUnitComponent::_TypeUID);
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
          if ( v52 && this == *(UFG::EncounterBase **)&v52[1].m_TypeUID )
          {
            ((void (__fastcall *)(UFG::EncounterBase *, UFG::SimComponent *, UFG::SimObjectGame *))this->vfptr[37].__vecDelDtor)(
              this,
              v52,
              v50);
            this->vfptr[24].__vecDelDtor(this, (unsigned int)v52);
          }
        }
      }
      goto LABEL_148;
    }
    if ( (v45 & 0x2000) != 0 || (v45 & 0x1000) != 0 )
LABEL_124:
      v46 = UFG::SimObjectGame::GetComponentOfTypeHK(v44, UFG::VehicleOccupantComponent::_TypeUID);
    else
      v46 = UFG::SimObject::GetComponentOfType(v44, UFG::VehicleOccupantComponent::_TypeUID);
    v47 = (UFG::VehicleOccupantComponent *)v46;
    goto LABEL_132;
  }
}

// File Line: 994
// RVA: 0x3FB760
void __fastcall UFG::EncounterBase::UpdateVehicleStatus(
        UFG::EncounterBase *this,
        float deltaTime,
        UFG::EncounterUnitComponent *pEncounterUnitComponent)
{
  UFG::SimObjectVehicle *m_pSimObject; // rcx
  float v5; // xmm0_4

  m_pSimObject = (UFG::SimObjectVehicle *)pEncounterUnitComponent->m_pSimObject;
  if ( m_pSimObject )
    v5 = deltaTime + pEncounterUnitComponent->mAcquiredTimer;
  else
    v5 = 0.0;
  pEncounterUnitComponent->mAcquiredTimer = v5;
  if ( (unsigned int)UFG::VehicleUtility::GetVehicleOrientation(m_pSimObject, 0, 0i64) )
    pEncounterUnitComponent->mVehicleFlipTimer = deltaTime + pEncounterUnitComponent->mVehicleFlipTimer;
  else
    pEncounterUnitComponent->mVehicleFlipTimer = 0.0;
}

// File Line: 1012
// RVA: 0x3FA780
void __fastcall UFG::EncounterBase::UpdatePopulation(UFG::EncounterBase *this, float deltaTime)
{
  __int64 v3; // r12
  __int64 v4; // rax
  __int64 v5; // r13
  UFG::qPropertySet *mpPropSet; // rsi
  __int64 v7; // r14
  UFG::qSymbol *v8; // r15
  UFG::SimObject *mpVehicle; // r8
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rax
  UFG::SimObjectGame *v12; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mPrev; // rbx
  bool *v14; // rax
  bool *v15; // rax
  bool *v16; // rax
  bool *v17; // rax
  bool *v18; // rax
  bool *v19; // rax
  bool *v20; // rax
  unsigned int mUID; // ecx
  int v22; // eax
  __int64 v23; // rdx
  unsigned int i; // ebp
  __int64 v25; // r15
  UFG::EncounterUnitComponent *v26; // rsi
  UFG::SimObjectGame *m_pSimObject; // rbx
  float v28; // xmm0_4
  __int16 v29; // cx
  UFG::SimComponent *v30; // rax
  unsigned int j; // ebx
  __int64 v32; // rbp
  UFG::EncounterUnitComponent *v33; // rsi
  UFG::SimObject *v34; // r15
  UFG::EncounterBase::ReplenishStyle mReplenishStyle; // ecx
  unsigned int mNumWaveGroupTypes; // edx
  bool v37; // r8
  unsigned int v38; // ebx
  unsigned int v39; // esi
  unsigned int v40; // ebp
  unsigned int v41; // r14d
  bool v42; // cf
  __int64 v43; // [rsp+70h] [rbp+8h]

  v3 = ((__int64 (__fastcall *)(UFG::EncounterBase *))this->vfptr[33].__vecDelDtor)(this);
  v4 = ((__int64 (__fastcall *)(UFG::EncounterBase *))this->vfptr[18].__vecDelDtor)(this);
  v5 = v4;
  if ( v3 )
  {
    if ( v4 )
    {
      UFG::PropertySetHandle::Bind(&this->mProperties);
      mpPropSet = this->mProperties.mpPropSet;
      v43 = *(_QWORD *)(v5 + 88);
      if ( v43 )
      {
        v7 = 0i64;
        if ( this->mHeatLevel )
        {
          v8 = UFG::qPropertySet::Get<UFG::qSymbol>(
                 mpPropSet,
                 (UFG::qArray<unsigned long,0> *)&EncounterSym_formation_style,
                 DEPTH_RECURSE);
          if ( v8 )
          {
            mpVehicle = this->mFocusTargetContext.mpVehicle;
            if ( mpVehicle )
            {
              m_Flags = mpVehicle->m_Flags;
              if ( (m_Flags & 0x4000) != 0 )
              {
                m_pComponent = mpVehicle->m_Components.p[24].m_pComponent;
              }
              else if ( m_Flags >= 0 )
              {
                v12 = (UFG::SimObjectGame *)this->mFocusTargetContext.mpVehicle;
                if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
                  m_pComponent = UFG::SimObjectGame::GetComponentOfTypeHK(v12, UFG::RoadSpaceComponent::_TypeUID);
                else
                  m_pComponent = UFG::SimObject::GetComponentOfType(v12, UFG::RoadSpaceComponent::_TypeUID);
              }
              else
              {
                m_pComponent = mpVehicle->m_Components.p[24].m_pComponent;
              }
              if ( m_pComponent )
              {
                mPrev = m_pComponent[26].m_BoundComponentHandles.mNode.mPrev;
                m_pComponent[30].m_TypeUID |= 2u;
                if ( mPrev )
                {
                  BYTE4(mPrev[38].mPrev) = 1;
                  v14 = UFG::qPropertySet::Get<bool>(
                          mpPropSet,
                          (UFG::qArray<unsigned long,0> *)&EncounterSym_formation_slot_follow,
                          DEPTH_RECURSE);
                  UFG::VehicleFormations::SetSlotUsability((UFG::VehicleFormations *)mPrev, Follow, *v14);
                  v15 = UFG::qPropertySet::Get<bool>(
                          mpPropSet,
                          (UFG::qArray<unsigned long,0> *)&EncounterSym_formation_slot_behind,
                          DEPTH_RECURSE);
                  UFG::VehicleFormations::SetSlotUsability((UFG::VehicleFormations *)mPrev, Behind, *v15);
                  v16 = UFG::qPropertySet::Get<bool>(
                          mpPropSet,
                          (UFG::qArray<unsigned long,0> *)&EncounterSym_formation_slot_rearcorner,
                          DEPTH_RECURSE);
                  UFG::VehicleFormations::SetSlotUsability((UFG::VehicleFormations *)mPrev, RearCorner, *v16);
                  v17 = UFG::qPropertySet::Get<bool>(
                          mpPropSet,
                          (UFG::qArray<unsigned long,0> *)&EncounterSym_formation_slot_pitposition,
                          DEPTH_RECURSE);
                  UFG::VehicleFormations::SetSlotUsability((UFG::VehicleFormations *)mPrev, PitPosition, *v17);
                  v18 = UFG::qPropertySet::Get<bool>(
                          mpPropSet,
                          (UFG::qArray<unsigned long,0> *)&EncounterSym_formation_slot_beside,
                          DEPTH_RECURSE);
                  UFG::VehicleFormations::SetSlotUsability((UFG::VehicleFormations *)mPrev, Beside, *v18);
                  v19 = UFG::qPropertySet::Get<bool>(
                          mpPropSet,
                          (UFG::qArray<unsigned long,0> *)&EncounterSym_formation_slot_frontcorner,
                          DEPTH_RECURSE);
                  UFG::VehicleFormations::SetSlotUsability((UFG::VehicleFormations *)mPrev, FrontCorner, *v19);
                  v20 = UFG::qPropertySet::Get<bool>(
                          mpPropSet,
                          (UFG::qArray<unsigned long,0> *)&EncounterSym_formation_slot_front,
                          DEPTH_RECURSE);
                  UFG::VehicleFormations::SetSlotUsability((UFG::VehicleFormations *)mPrev, Front, *v20);
                  UFG::VehicleFormations::OverrideSlotOffsets((UFG::VehicleFormations *)mPrev, mpPropSet);
                  mUID = v8->mUID;
                  if ( v8->mUID == EncounterSym_escort.mUID )
                  {
                    LODWORD(mPrev[1].mPrev) = 3;
                  }
                  else if ( mUID == EncounterSym_generic_favor_front.mUID )
                  {
                    LODWORD(mPrev[1].mPrev) = 1;
                  }
                  else
                  {
                    v22 = 0;
                    if ( mUID == EncounterSym_generic_favor_back.mUID )
                      v22 = 2;
                    LODWORD(mPrev[1].mPrev) = v22;
                  }
                  UFG::VehicleFormations::SetSecondaryTarget(
                    (UFG::VehicleFormations *)mPrev,
                    this->mpSecondaryTarget.m_pPointer);
                }
              }
            }
          }
        }
        this->vfptr[35].__vecDelDtor(this, v3);
        this->vfptr[36].__vecDelDtor(this, v3);
        for ( i = 0; i < this->mHumans.size; ++i )
        {
          v25 = i;
          v26 = this->mHumans.p[i];
          m_pSimObject = (UFG::SimObjectGame *)v26->m_pSimObject;
          if ( m_pSimObject )
            v28 = deltaTime + v26->mAcquiredTimer;
          else
            v28 = 0.0;
          v26->mAcquiredTimer = v28;
          if ( m_pSimObject )
          {
            if ( this->vfptr[71].__vecDelDtor(this, v26) && this->vfptr[73].__vecDelDtor(this, v26) )
              continue;
            if ( this->mHumans.size == 1 && !this->vfptr[78].__vecDelDtor(this, v26) )
            {
              v29 = m_pSimObject->m_Flags;
              if ( (v29 & 0x4000) != 0 )
                v30 = m_pSimObject->m_Components.p[44].m_pComponent;
              else
                v30 = v29 < 0 || (v29 & 0x2000) != 0 || (v29 & 0x1000) != 0
                    ? UFG::SimObjectGame::GetComponentOfTypeHK(m_pSimObject, UFG::CharacterOccupantComponent::_TypeUID)
                    : UFG::SimObject::GetComponentOfType(m_pSimObject, UFG::CharacterOccupantComponent::_TypeUID);
              if ( !v30 )
                this->vfptr[70].__vecDelDtor(this, (unsigned int)v26);
            }
            this->vfptr[37].__vecDelDtor(this, (unsigned int)v26);
          }
          --this->mHumans.size;
          --i;
          this->mHumans.p[v25] = this->mHumans.p[this->mHumans.size];
        }
        for ( j = 0; j < this->mVehicles.size; ++j )
        {
          v32 = j;
          v33 = this->mVehicles.p[j];
          v34 = v33->m_pSimObject;
          ((void (__fastcall *)(UFG::EncounterBase *, __int64, UFG::EncounterUnitComponent *))this->vfptr[80].__vecDelDtor)(
            this,
            v23,
            v33);
          if ( v34 )
          {
            if ( this->vfptr[72].__vecDelDtor(this, v33) )
            {
              if ( this->vfptr[74].__vecDelDtor(this, v33) )
              {
                if ( this->vfptr[73].__vecDelDtor(this, v33) )
                {
                  this->vfptr[51].__vecDelDtor(this, (unsigned int)v34);
                  continue;
                }
              }
              else
              {
                v33->mUnitDisabled = 1;
              }
            }
            this->vfptr[37].__vecDelDtor(this, (unsigned int)v33);
          }
          --this->mVehicles.size;
          --j;
          this->mVehicles.p[v32] = this->mVehicles.p[this->mVehicles.size];
        }
        if ( this->mFocusTargetContext.mWaterContextTimer == 0.0 )
        {
          if ( this->mIsReplenishing )
          {
            mReplenishStyle = this->mReplenishStyle;
            if ( mReplenishStyle )
            {
              if ( mReplenishStyle == ReplenishStyle_TopUpByWaveType )
              {
                mNumWaveGroupTypes = this->mNumWaveGroupTypes;
                v37 = 0;
                if ( mNumWaveGroupTypes )
                {
                  while ( this->mWaveGroupInstances[v7] >= this->mWaveGroupInstancesRequired[v7] )
                  {
                    v7 = (unsigned int)(v7 + 1);
                    if ( (unsigned int)v7 >= mNumWaveGroupTypes )
                    {
                      this->mIsReplenishing = 0;
                      goto LABEL_73;
                    }
                  }
                  v37 = 1;
                }
                this->mIsReplenishing = v37;
              }
            }
            else
            {
              v38 = (unsigned int)this->vfptr[35].__vecDelDtor(this, v3);
              v39 = (unsigned int)this->vfptr[36].__vecDelDtor(this, v3);
              v40 = (unsigned int)this->vfptr[75].__vecDelDtor(this, 2i64);
              v41 = (unsigned int)this->vfptr[75].__vecDelDtor(this, 1i64);
              if ( this->mIsReplenishing )
              {
                if ( ((unsigned __int8 (__fastcall *)(UFG::EncounterBase *))this->vfptr[61].__vecDelDtor)(this) )
                  v42 = v41 < v39;
                else
                  v42 = v40 < v38;
                if ( !v42 )
                  this->mIsReplenishing = 0;
              }
            }
          }
LABEL_73:
          ((void (__fastcall *)(UFG::EncounterBase *, __int64, __int64))this->vfptr[42].__vecDelDtor)(this, v5, v43);
          ((void (__fastcall *)(UFG::EncounterBase *, UFG::SimObject *, __int64))this->vfptr[43].__vecDelDtor)(
            this,
            this->mFocusTargetContext.mpVehicle,
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
  __int64 size; // r15
  UFG::GroupComponent *SharedGroupComponent; // r12
  UFG::EncounterUnitComponent *v3; // rbp
  float v4; // xmm6_4
  UFG::EncounterUnitComponent **p; // rbx
  __int64 v7; // rsi
  UFG::EncounterUnitComponent *v8; // rdi
  UFG::SimObjectCVBase *m_pSimObject; // rcx
  UFG::ActiveAIEntityComponent *ComponentOfTypeHK; // rax
  __int16 m_Flags; // dx
  UFG::GroupComponent *m_pPointer; // rcx
  UFG::qVector3 *Position; // rax
  __m128 y_low; // xmm2
  float v15; // xmm1_4
  UFG::SimObjectCVBase *v16; // rcx
  UFG::ActiveAIEntityComponent *v17; // rax
  __int16 v18; // dx
  UFG::GroupComponent *v19; // rcx
  UFG::EncounterUnitComponent **v20; // rbx
  __int64 v21; // rbp
  UFG::EncounterUnitComponent *v22; // rdi
  UFG::GroupComponent *v23; // rsi
  UFG::SimObjectCVBase *v24; // rcx
  UFG::ActiveAIEntityComponent *ComponentOfType; // rax
  __int16 v26; // dx
  UFG::GroupComponent *v27; // rcx
  UFG::qVector3 result; // [rsp+20h] [rbp-38h] BYREF

  size = this->mHumans.size;
  SharedGroupComponent = 0i64;
  v3 = 0i64;
  v4 = FLOAT_3_4028235e38;
  if ( (_DWORD)size )
  {
    p = this->mHumans.p;
    v7 = (unsigned int)size;
    do
    {
      v8 = *p;
      m_pSimObject = (UFG::SimObjectCVBase *)(*p)->m_pSimObject;
      if ( m_pSimObject )
      {
        m_Flags = m_pSimObject->m_Flags;
        if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
        {
          ComponentOfTypeHK = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>(m_pSimObject);
        }
        else if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
        {
          ComponentOfTypeHK = (UFG::ActiveAIEntityComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                m_pSimObject,
                                                                UFG::ActiveAIEntityComponent::_TypeUID);
        }
        else
        {
          ComponentOfTypeHK = (UFG::ActiveAIEntityComponent *)UFG::SimObject::GetComponentOfType(
                                                                m_pSimObject,
                                                                UFG::ActiveAIEntityComponent::_TypeUID);
        }
      }
      else
      {
        ComponentOfTypeHK = 0i64;
      }
      m_pPointer = ComponentOfTypeHK->m_pGroupComponent.m_pPointer;
      if ( m_pPointer )
      {
        Position = UFG::GroupComponent::GetPosition(m_pPointer, &result);
        y_low = (__m128)LODWORD(Position->y);
        y_low.m128_f32[0] = (float)((float)((float)(y_low.m128_f32[0] - this->mFocusTargetPosition.y)
                                          * (float)(y_low.m128_f32[0] - this->mFocusTargetPosition.y))
                                  + (float)((float)(Position->x - this->mFocusTargetPosition.x)
                                          * (float)(Position->x - this->mFocusTargetPosition.x)))
                          + (float)((float)(Position->z - this->mFocusTargetPosition.z)
                                  * (float)(Position->z - this->mFocusTargetPosition.z));
        v15 = _mm_sqrt_ps(y_low).m128_f32[0];
        if ( v15 < v4 )
        {
          v4 = v15;
          v3 = v8;
        }
      }
      ++p;
      --v7;
    }
    while ( v7 );
    if ( v3 )
    {
      v16 = (UFG::SimObjectCVBase *)v3->m_pSimObject;
      if ( v16 )
      {
        v18 = v16->m_Flags;
        if ( (v18 & 0x4000) != 0 || v18 < 0 )
          v17 = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>(v16);
        else
          v17 = (UFG::ActiveAIEntityComponent *)((v18 & 0x2000) != 0 || (v18 & 0x1000) != 0
                                               ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                   v16,
                                                   UFG::ActiveAIEntityComponent::_TypeUID)
                                               : UFG::SimObject::GetComponentOfType(
                                                   v16,
                                                   UFG::ActiveAIEntityComponent::_TypeUID));
      }
      else
      {
        v17 = 0i64;
      }
      v19 = v17->m_pGroupComponent.m_pPointer;
      if ( v19 )
        SharedGroupComponent = UFG::GroupComponent::GetSharedGroupComponent(v19);
    }
  }
  if ( (_DWORD)size )
  {
    v20 = this->mHumans.p;
    v21 = size;
    do
    {
      v22 = *v20;
      v23 = 0i64;
      v24 = (UFG::SimObjectCVBase *)(*v20)->m_pSimObject;
      if ( v24 )
      {
        v26 = v24->m_Flags;
        if ( (v26 & 0x4000) != 0 || v26 < 0 )
        {
          ComponentOfType = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>(v24);
        }
        else if ( (v26 & 0x2000) != 0 || (v26 & 0x1000) != 0 )
        {
          ComponentOfType = (UFG::ActiveAIEntityComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                              v24,
                                                              UFG::ActiveAIEntityComponent::_TypeUID);
        }
        else
        {
          ComponentOfType = (UFG::ActiveAIEntityComponent *)UFG::SimObject::GetComponentOfType(
                                                              v24,
                                                              UFG::ActiveAIEntityComponent::_TypeUID);
        }
      }
      else
      {
        ComponentOfType = 0i64;
      }
      v27 = ComponentOfType->m_pGroupComponent.m_pPointer;
      if ( v27 )
        v23 = UFG::GroupComponent::GetSharedGroupComponent(v27);
      ++v20;
      v22->mRole = (v23 != SharedGroupComponent) + 1;
      --v21;
    }
    while ( v21 );
  }
}

// File Line: 1290
// RVA: 0x3F82D0
char __fastcall UFG::EncounterBase::IsGoodVehicleSpawnTransform(UFG::EncounterBase *this, UFG::qMatrix44 *pTransform)
{
  __int64 i; // rbx
  UFG::SimObject *m_pSimObject; // rsi
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rsi
  UFG::SimObjectGame *v7; // rax
  __int16 m_Flags; // dx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  char *p_mNext; // rax
  bool j; // zf
  __int64 v13; // rbx
  __int64 v14; // rax
  __int64 v15; // rax
  float *v16; // rdi
  UFG::SensorPhantomIterator v17; // [rsp+28h] [rbp-30h] BYREF

  if ( this->vfptr[60].__vecDelDtor(this, &pTransform->v3) )
    return 0;
  for ( i = 0i64; (unsigned int)i < this->mVehicles.size; i = (unsigned int)(i + 1) )
  {
    m_pSimObject = this->mVehicles.p[i]->m_pSimObject;
    if ( m_pSimObject )
    {
      m_pTransformNodeComponent = m_pSimObject->m_pTransformNodeComponent;
      if ( m_pTransformNodeComponent )
      {
        UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
        if ( (float)((float)((float)((float)(pTransform->v3.y - m_pTransformNodeComponent->mWorldTransform.v3.y)
                                   * (float)(pTransform->v3.y - m_pTransformNodeComponent->mWorldTransform.v3.y))
                           + (float)((float)(pTransform->v3.x - m_pTransformNodeComponent->mWorldTransform.v3.x)
                                   * (float)(pTransform->v3.x - m_pTransformNodeComponent->mWorldTransform.v3.x)))
                   + (float)((float)(pTransform->v3.z - m_pTransformNodeComponent->mWorldTransform.v3.z)
                           * (float)(pTransform->v3.z - m_pTransformNodeComponent->mWorldTransform.v3.z))) < 81.0 )
          return 0;
      }
    }
  }
  UFG::SensorPhantom::SetTransform(this->mpVehicleSpawnSensor, pTransform);
  UFG::SensorPhantomIterator::SensorPhantomIterator(&v17, this->mpVehicleSpawnSensor, 0);
  while ( UFG::SensorPhantomIterator::operator*(&v17) )
  {
    v7 = (UFG::SimObjectGame *)UFG::SensorPhantomIterator::operator*(&v17);
    if ( v7 )
    {
      m_Flags = v7->m_Flags;
      if ( (m_Flags & 0x4000) == 0 )
      {
        if ( m_Flags >= 0 )
        {
          if ( (m_Flags & 0x2000) != 0 )
            goto LABEL_18;
          if ( (m_Flags & 0x1000) != 0 )
            ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(v7, UFG::PhysicsMoverInterface::_TypeUID);
          else
            ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(v7, UFG::PhysicsMoverInterface::_TypeUID);
        }
        else
        {
          ComponentOfTypeHK = v7->m_Components.p[34].m_pComponent;
        }
        if ( ComponentOfTypeHK )
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
  p_mNext = (char *)&UFG::PhysicsMoverInterface::s_PhysicsMoverInterfaceList.mNode.mNext[-5].mNext;
  for ( j = &UFG::PhysicsMoverInterface::s_PhysicsMoverInterfaceList.mNode.mNext[-5].mNext == (UFG::qNode<UFG::PhysicsMoverInterface,UFG::PhysicsMoverInterface> **)((char *)&UFG::PhysicsMoverInterface::s_PhysicsMoverInterfaceList - 72);
        !j;
        j = v13 == (_QWORD)&UFG::PhysicsMoverInterface::s_PhysicsMoverInterfaceList - 72 )
  {
    v13 = *((_QWORD *)p_mNext + 10) - 72i64;
    v14 = *((_QWORD *)p_mNext + 5);
    if ( v14 )
    {
      v15 = *(_QWORD *)(v14 + 104);
      v16 = *(float **)(v15 + 32);
      if ( v16 )
      {
        UFG::TransformNodeComponent::UpdateWorldTransform(*(UFG::TransformNodeComponent **)(v15 + 32));
        if ( (float)((float)((float)((float)(pTransform->v3.y - v16[45]) * (float)(pTransform->v3.y - v16[45]))
                           + (float)((float)(pTransform->v3.x - v16[44]) * (float)(pTransform->v3.x - v16[44])))
                   + (float)((float)(pTransform->v3.z - v16[46]) * (float)(pTransform->v3.z - v16[46]))) < 81.0 )
          return 0;
      }
    }
    p_mNext = (char *)v13;
  }
  return 1;
}< 81.0 )
          return 0;
      }
    }
 

// File Line: 1344
// RVA: 0x3F89B0
__int64 __fastcall UFG::EncounterBase::IsSuitableSpawnPointByRoadProperty(
        UFG::EncounterBase *this,
        __int64 unitType,
        UFG::RoadNetworkSpawnPoint *pSpawnPoint)
{
  return ((__int64 (__fastcall *)(UFG::EncounterBase *, __int64, UFG::RoadNetworkSegment *))this->vfptr[55].__vecDelDtor)(
           this,
           unitType,
           pSpawnPoint->mSubSegment->mParentNode);
}

// File Line: 1354
// RVA: 0x3F88E0
bool __fastcall UFG::EncounterBase::IsSuitableByRoadProperty(
        UFG::EncounterBase *this,
        UFG::EncounterUnit::UnitType unitType,
        UFG::RoadNetworkSegment *pSegment)
{
  int RoadNetworkType; // eax
  UFG::RoadNetworkSegment::RoadSegmentBits mBits; // ecx

  RoadNetworkType = UFG::RoadNetworkSegment::GetRoadNetworkType(pSegment);
  if ( unitType == F3_1Pt44_512 )
  {
    if ( RoadNetworkType )
      return 0;
  }
  else if ( unitType == F3_2Pt88_512 && RoadNetworkType != 3 )
  {
    return 0;
  }
  if ( this->mHeatLevel <= HEATLEVEL_NONE )
    return (*(_DWORD *)&pSegment->mBits & 0x10) == 0;
  mBits = pSegment->mBits;
  return (*(_BYTE *)&mBits & 2) == 0 && (*(_BYTE *)&mBits & 8) == 0;
}

// File Line: 1379
// RVA: 0x3F4A80
bool __fastcall UFG::EncounterBase::GenerateVehicleSpawnTransform(
        UFG::EncounterBase *this,
        bool enableForwardSpawning,
        UFG::SimObjectGame *pTargetVehicle,
        UFG::TransformNodeComponent *pTargetTransform,
        UFG::qMatrix44 *pTransform,
        bool *location_is_on_screen,
        bool enableDebugDraw)
{
  UFG::qVector4 v7; // xmm1
  UFG::qVector4 v8; // xmm2
  UFG::EncounterBase *v9; // r12
  UFG::qVector4 v12; // xmm3
  UFG::qPropertySet *mpPropSet; // rdi
  UFG::qVector4 v14; // xmm3
  UFG::qVector4 v15; // xmm2
  UFG::qVector4 v16; // xmm1
  float *v17; // rbx
  float *v18; // rax
  float x; // xmm0_4
  float y; // xmm1_4
  __int64 v21; // rax
  float z; // xmm0_4
  float v23; // xmm6_4
  float *v24; // rax
  UFG::TransformNodeComponent *ChaseSpawnTransform; // rax
  UFG::TransformNodeComponent *v26; // rbx
  UFG::qVector4 v27; // xmm3
  UFG::qVector4 v28; // xmm2
  UFG::qVector4 v29; // xmm1
  float v30; // xmm12_4
  float v31; // xmm7_4
  UFG::RoadNetworkResource *RoadNetwork; // rax
  float *p_x; // r13
  UFG::RoadNetworkSegment *ClosestSegment; // rax
  Render::DebugDrawContext *Context; // rax
  float v36; // xmm1_4
  Render::DebugDrawContext *v37; // rbx
  float v38; // xmm0_4
  float v39; // xmm1_4
  float v40; // xmm0_4
  signed int v41; // ebx
  UFG::RoadNetworkGraph *RoadNetworkGraph; // r15
  UFG::WayTraversal *WayTraversal; // rax
  UFG::WayTraversal *v44; // rax
  int v45; // xmm12_4
  signed __int16 m_Flags; // cx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::qMatrix44 *p_m_pSimObject; // rax
  float v49; // xmm3_4
  __m128 x_low; // xmm4
  float v51; // xmm5_4
  __m128 v52; // xmm2
  float v53; // xmm1_4
  __int64 m_NumWayEdges; // rbx
  float v55; // xmm6_4
  float v56; // xmm0_4
  bool v57; // zf
  unsigned int v58; // r14d
  float v59; // xmm6_4
  unsigned __int16 v60; // bx
  unsigned __int16 v61; // di
  UFG::RoadNetworkResource *v62; // rsi
  UFG::RoadNetworkSegment *Segment; // rdi
  int v64; // eax
  UFG::RoadNetworkIntersection *Intersection; // rsi
  unsigned int v66; // ebx
  UFG::RoadNetworkConnection *IncomingConnection; // rax
  UFG::RoadNetworkGate *v68; // r13
  UFG::RoadNetworkIntersection *mOffset; // rcx
  __int64 v70; // rbx
  bool v71; // al
  unsigned int v72; // r12d
  UFG::RoadNetworkConnection *OutgoingConnection; // rax
  UFG::RoadNetworkConnection *v74; // rsi
  __int64 v75; // rax
  char *v76; // rax
  __int64 v77; // rax
  unsigned int *v78; // r15
  unsigned int i; // r14d
  unsigned int j; // edi
  unsigned int k; // r12d
  UFG::RoadNetworkConnection *v82; // rax
  UFG::RoadNetworkConnection *v83; // rsi
  __int64 v84; // rax
  char *v85; // rax
  __int64 v86; // rax
  unsigned int *v87; // r15
  unsigned int m; // r14d
  unsigned int n; // edi
  Render::DebugDrawManager *v90; // rax
  Render::DebugDrawContext *v91; // rsi
  __int64 *v92; // r14
  __int64 v93; // r15
  UFG::RoadNetworkLane *v94; // rdi
  float v95; // xmm15_4
  float Length; // xmm0_4
  float v97; // xmm11_4
  bool IsReversedInNode; // al
  float *v99; // r13
  UFG::qColour *v100; // rcx
  float v101; // xmm1_4
  float v102; // xmm0_4
  float r; // eax
  float g; // eax
  float b; // eax
  float v106; // xmm13_4
  float v107; // xmm3_4
  __m128 y_low; // xmm2
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
  bool IsPositionOnScreen; // bl
  UFG::BaseCameraComponent *mCurrentCamera; // rcx
  UFG::RoadNetworkNode *v121; // rcx
  __m128 z_low; // xmm3
  __m128 v123; // xmm2
  float v124; // xmm1_4
  float v125; // xmm4_4
  float v126; // xmm9_4
  __m128 v127; // xmm2
  float v128; // xmm5_4
  float v129; // xmm1_4
  float v130; // xmm10_4
  float v131; // xmm5_4
  float v132; // xmm1_4
  float v133; // xmm10_4
  float v134; // xmm11_4
  float v135; // xmm5_4
  float v136; // xmm10_4
  float v137; // xmm2_4
  float v138; // xmm8_4
  float v139; // xmm1_4
  float v140; // xmm2_4
  unsigned int v141; // xmm8_4
  float v142; // xmm5_4
  float v143; // xmm0_4
  float v144; // xmm4_4
  __m128 v145; // xmm2
  float v146; // xmm7_4
  UFG::qSafePointerNode<UFG::EncounterBase>Vtbl *vfptr; // rax
  char v148; // al
  UFG::qVector4 v149; // xmm1
  UFG::qVector4 v150; // xmm1
  bool v152; // [rsp+40h] [rbp-C0h]
  char v153; // [rsp+41h] [rbp-BFh]
  UFG::qVector3 p1; // [rsp+48h] [rbp-B8h] BYREF
  UFG::qVector3 position; // [rsp+58h] [rbp-A8h] BYREF
  UFG::qVector3 p0; // [rsp+68h] [rbp-98h] BYREF
  float laneT; // [rsp+78h] [rbp-88h] BYREF
  UFG::qVector3 result; // [rsp+80h] [rbp-80h] BYREF
  float v159; // [rsp+90h] [rbp-70h]
  UFG::qVector3 v160; // [rsp+98h] [rbp-68h] BYREF
  unsigned int v161; // [rsp+A8h] [rbp-58h]
  float v162; // [rsp+ACh] [rbp-54h]
  int v163; // [rsp+B0h] [rbp-50h]
  float v164; // [rsp+B4h] [rbp-4Ch]
  UFG::qMatrix44 v165; // [rsp+C0h] [rbp-40h] BYREF
  UFG::qColour colour; // [rsp+100h] [rbp+0h] BYREF
  float v167; // [rsp+110h] [rbp+10h]
  float v168; // [rsp+114h] [rbp+14h]
  __int64 v169; // [rsp+118h] [rbp+18h] BYREF
  float nearestT; // [rsp+120h] [rbp+20h] BYREF
  float v171; // [rsp+124h] [rbp+24h]
  float v172; // [rsp+128h] [rbp+28h]
  UFG::qVector3 *p_mFocusTargetPosition; // [rsp+130h] [rbp+30h]
  float v174; // [rsp+138h] [rbp+38h]
  float v175; // [rsp+13Ch] [rbp+3Ch]
  __int64 v176; // [rsp+140h] [rbp+40h] BYREF
  UFG::RoadNetworkGraph *v177; // [rsp+148h] [rbp+48h]
  __int64 v178; // [rsp+150h] [rbp+50h]
  __int64 v179; // [rsp+158h] [rbp+58h]
  __int64 *v180; // [rsp+160h] [rbp+60h]
  UFG::qVector3 v181; // [rsp+168h] [rbp+68h] BYREF
  int v182[3]; // [rsp+174h] [rbp+74h] BYREF
  UFG::qVector3 centre; // [rsp+180h] [rbp+80h] BYREF
  UFG::qVector3 v184; // [rsp+190h] [rbp+90h] BYREF
  UFG::qVector3 v185; // [rsp+1A0h] [rbp+A0h] BYREF
  UFG::qVector3 v186; // [rsp+1ACh] [rbp+ACh] BYREF
  UFG::qVector3 v187; // [rsp+1B8h] [rbp+B8h] BYREF
  UFG::qVector3 v188; // [rsp+1C4h] [rbp+C4h] BYREF
  UFG::qVector3 v189; // [rsp+1D0h] [rbp+D0h] BYREF
  UFG::qVector3 v190; // [rsp+1DCh] [rbp+DCh] BYREF
  UFG::qVector3 v191; // [rsp+1E8h] [rbp+E8h] BYREF
  UFG::qVector3 v192; // [rsp+1F4h] [rbp+F4h] BYREF
  UFG::RoadNetworkSegment *v193; // [rsp+200h] [rbp+100h]
  __int64 v194; // [rsp+208h] [rbp+108h]
  UFG::RoadNetworkResource *v195; // [rsp+210h] [rbp+110h]
  __int64 v196; // [rsp+218h] [rbp+118h]
  __int64 v197; // [rsp+220h] [rbp+120h]
  __int64 v198[12]; // [rsp+230h] [rbp+130h] BYREF

  v7 = UFG::qMatrix44::msIdentity.v1;
  v8 = UFG::qMatrix44::msIdentity.v2;
  v9 = this;
  v12 = UFG::qMatrix44::msIdentity.v3;
  pTransform->v0 = UFG::qMatrix44::msIdentity.v0;
  pTransform->v1 = v7;
  pTransform->v2 = v8;
  pTransform->v3 = v12;
  v165 = UFG::qMatrix44::msIdentity;
  UFG::PropertySetHandle::Bind(&this->mProperties);
  mpPropSet = v9->mProperties.mpPropSet;
  if ( v9->mFocusTargetContext.mIsInWater )
  {
    UFG::TransformNodeComponent::UpdateWorldTransform(pTargetTransform);
    v14 = pTargetTransform->mWorldTransform.v1;
    v15 = pTargetTransform->mWorldTransform.v2;
    v16 = pTargetTransform->mWorldTransform.v3;
    pTransform->v0 = pTargetTransform->mWorldTransform.v0;
    pTransform->v1 = v14;
    pTransform->v2 = v15;
    pTransform->v3 = v16;
    UFG::TransformNodeComponent::UpdateWorldTransform(pTargetTransform);
    v17 = UFG::qPropertySet::Get<float>(
            mpPropSet,
            (UFG::qArray<unsigned long,0> *)&EncounterSym_water_offset_max_range,
            DEPTH_RECURSE);
    v18 = UFG::qPropertySet::Get<float>(
            mpPropSet,
            (UFG::qArray<unsigned long,0> *)&EncounterSym_water_offset_min_range,
            DEPTH_RECURSE);
    if ( UFG::SimObjectUtility::FindSpawnBoatPosition(
           (UFG::qVector3 *)&pTargetTransform->mWorldTransform.v3,
           *v18,
           *v17,
           1,
           &p1) )
    {
      x = p1.x;
      y = p1.y;
      pTransform->v3.w = 1.0;
      LOBYTE(v21) = 1;
      pTransform->v3.x = x;
      z = p1.z;
      pTransform->v3.y = y;
      pTransform->v3.z = z;
    }
    else
    {
      LOBYTE(v21) = 0;
    }
    return v21;
  }
  v153 = 0;
  v23 = *UFG::qPropertySet::Get<float>(
           mpPropSet,
           (UFG::qArray<unsigned long,0> *)&EncounterSym_vehicle_spawn_behind_probability,
           DEPTH_RECURSE);
  if ( v9->mHeatLevel > HEATLEVEL_NONE
    && !v9->mFocusTargetContext.mIsOnFootHeuristic
    && (UFG::Metrics::msInstance.mSimTimeMSec - v9->mStartTimestamp < 0x7530
     || !v9->mCoolingDown && !v9->mInsideDynamicRadiusCount)
    && UFG::qRandom(1.0, (unsigned int *)&UFG::qDefaultSeed) < v23 )
  {
    v24 = UFG::qPropertySet::Get<float>(
            mpPropSet,
            (UFG::qArray<unsigned long,0> *)&EncounterSym_vehicle_chase_spawn_distance,
            DEPTH_RECURSE);
    ChaseSpawnTransform = UFG::VehicleUtility::GetChaseSpawnTransform(pTargetVehicle, *v24);
    v26 = ChaseSpawnTransform;
    if ( ChaseSpawnTransform )
    {
      UFG::TransformNodeComponent::UpdateWorldTransform(ChaseSpawnTransform);
      if ( v9->vfptr[57].__vecDelDtor(v9, (unsigned int)&v26->mWorldTransform) )
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
  v30 = *UFG::qPropertySet::Get<float>(
           mpPropSet,
           (UFG::qArray<unsigned long,0> *)&EncounterSym_vehicle_generic_spawn_min_radius,
           DEPTH_RECURSE);
  v31 = *UFG::qPropertySet::Get<float>(
           mpPropSet,
           (UFG::qArray<unsigned long,0> *)&EncounterSym_vehicle_generic_spawn_max_radius,
           DEPTH_RECURSE);
  if ( v31 < 68.0 )
    v31 = FLOAT_68_0;
  if ( v9->mWaveCount <= 1 )
  {
    v30 = v30 * FIRST_WAVE_MODIFIER;
    v31 = v31 * FIRST_WAVE_MODIFIER;
  }
  RoadNetwork = UFG::WheeledVehicleNavigationData::GetRoadNetwork(UFG::WheeledVehicleManager::m_Instance->m_NavigationData);
  v195 = RoadNetwork;
  if ( !RoadNetwork )
  {
    printWarning = 0;
    goto LABEL_20;
  }
  p_x = &v9->mFocusTargetPosition.x;
  p_mFocusTargetPosition = &v9->mFocusTargetPosition;
  ClosestSegment = UFG::RoadNetworkResource::GetClosestSegment(RoadNetwork, &v9->mFocusTargetPosition, 0i64, 0);
  LODWORD(nearestT) = (_DWORD)FLOAT_1_0;
  v193 = ClosestSegment;
  UFG::RoadNetworkNode::GetClosestPosition(ClosestSegment, &result, &v9->mFocusTargetPosition, &nearestT);
  if ( enableDebugDraw )
  {
    Context = (Render::DebugDrawContext *)Render::DebugDrawManager::GetContext(Render::DebugDrawManager::mInstance, 2u);
    p1.x = result.x;
    p1.y = result.y;
    v36 = v9->mFocusTargetPosition.y;
    v37 = Context;
    p1.z = result.z + 0.5;
    v38 = *p_x;
    p0.y = v36;
    p0.x = v38;
    p0.z = v9->mFocusTargetPosition.z + 0.5;
    Render::DebugDrawContext::DrawLine(Context, &p0, &p1, &UFG::qColour::Blue, &UFG::qMatrix44::msIdentity, 0i64, 0);
    v39 = v9->mFocusTargetPosition.y;
    p1.x = *p_x;
    v40 = v9->mFocusTargetPosition.z;
    p1.y = v39;
    p1.z = v40 + 0.5;
    Render::DebugDrawContext::DrawSphere(v37, &p1, 0.5, &UFG::qColour::Blue, &UFG::qMatrix44::msIdentity, 0i64);
    p1.x = result.x;
    p1.y = result.y;
    p1.z = result.z + 0.5;
    Render::DebugDrawContext::DrawSphere(v37, &p1, 0.5, &UFG::qColour::Blue, &UFG::qMatrix44::msIdentity, 0i64);
  }
  v41 = v9->mFocusTargetContext.mIsInWater ? 3 : 0;
  RoadNetworkGraph = UFG::WheeledVehicleNavigationData::GetRoadNetworkGraph(
                       UFG::WheeledVehicleManager::m_Instance->m_NavigationData,
                       (UFG::RoadNetworkNode::RoadNetworkType)v41);
  v177 = RoadNetworkGraph;
  UFG::VehicleWayFinderClient::SetRoadNetworkType(&v9->mWayTraversalClient, v41);
  UFG::GetWayTraversal()->pWayGraph = RoadNetworkGraph;
  WayTraversal = UFG::GetWayTraversal();
  UFG::WayTraversal::FindConnectedEdgesInRange(
    WayTraversal,
    &v9->mWayTraversalClient,
    &v9->mFocusTargetPosition,
    &result,
    v30,
    v31);
  v44 = UFG::GetWayTraversal();
  UFG::WayTraversal::Service(v44, 0.0);
  *(float *)&v45 = v30 * v30;
  v163 = v45;
  v168 = v31 * v31;
  UFG::TransformNodeComponent::UpdateWorldTransform(pTargetTransform);
  if ( pTargetVehicle
    && ((m_Flags = pTargetVehicle->m_Flags, (m_Flags & 0x4000) == 0)
      ? (m_Flags >= 0
       ? ((m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
        ? (ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(
                                 pTargetVehicle,
                                 UFG::RoadSpaceComponent::_TypeUID))
        : (ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(pTargetVehicle, UFG::RoadSpaceComponent::_TypeUID)))
       : (ComponentOfTypeHK = pTargetVehicle->m_Components.p[24].m_pComponent))
      : (ComponentOfTypeHK = pTargetVehicle->m_Components.p[24].m_pComponent),
        ComponentOfTypeHK) )
  {
    p_m_pSimObject = (UFG::qMatrix44 *)&ComponentOfTypeHK[27].m_pSimObject;
  }
  else
  {
    UFG::TransformNodeComponent::UpdateWorldTransform(pTargetTransform);
    p_m_pSimObject = &pTargetTransform->mWorldTransform;
  }
  v49 = p_m_pSimObject->v0.y;
  x_low = (__m128)LODWORD(p_m_pSimObject->v0.x);
  v51 = p_m_pSimObject->v0.z;
  v52 = x_low;
  v52.m128_f32[0] = (float)((float)(x_low.m128_f32[0] * x_low.m128_f32[0]) + (float)(v49 * v49)) + (float)(v51 * v51);
  if ( v52.m128_f32[0] == 0.0 )
    v53 = 0.0;
  else
    v53 = 1.0 / _mm_sqrt_ps(v52).m128_f32[0];
  m_NumWayEdges = v9->mWayTraversalClient.m_NumWayEdges;
  v172 = v53 * x_low.m128_f32[0];
  v174 = v53 * v51;
  v167 = v53 * v49;
  v55 = UFG::qRandom(6.2831855, (unsigned int *)&UFG::qDefaultSeed);
  v175 = sinf(v55);
  v56 = cosf(v55);
  v194 = m_NumWayEdges;
  v57 = !v9->mFocusTargetContext.mIsInWater;
  v171 = v56;
  v21 = 0i64;
  v162 = FLOAT_N2_0;
  v58 = !v57 + 2;
  v178 = 0i64;
  v161 = v58;
  if ( (int)m_NumWayEdges > 0 )
  {
    v59 = FLOAT_0_30000001;
    while ( 1 )
    {
      v60 = v9->mWayTraversalClient.aWayNodes[v21];
      v61 = v9->mWayTraversalClient.m_WayEdges[v21];
      if ( !RoadNetworkGraph->vfptr->IsEdge(RoadNetworkGraph, v60) )
      {
        v62 = v195;
        Segment = UFG::RoadNetworkResource::GetSegment(v195, v61);
        if ( ((unsigned __int8 (__fastcall *)(UFG::EncounterBase *, _QWORD, UFG::RoadNetworkSegment *))v9->vfptr[55].__vecDelDtor)(
               v9,
               v58,
               Segment) )
        {
          if ( v60 )
          {
            v64 = RoadNetworkGraph->vfptr->GetNumEdges(RoadNetworkGraph);
            Intersection = UFG::RoadNetworkResource::GetIntersection(v62, (unsigned int)v60 - v64);
          }
          else
          {
            Intersection = 0i64;
          }
          v66 = 0;
          if ( Segment->mNumGates )
          {
            while ( 1 )
            {
              IncomingConnection = UFG::RoadNetworkGate::GetIncomingConnection((UFG::RoadNetworkGate *)Segment, v66);
              v68 = (UFG::RoadNetworkGate *)IncomingConnection;
              mOffset = (UFG::RoadNetworkIntersection *)IncomingConnection->mLaneList.mOffset;
              if ( mOffset )
                mOffset = (UFG::RoadNetworkIntersection *)((char *)&mOffset->mDataHash + (_QWORD)IncomingConnection);
              if ( mOffset == Intersection )
                break;
              if ( ++v66 >= (unsigned __int8)Segment->mNumGates )
                goto LABEL_148;
            }
            if ( IncomingConnection )
            {
              v70 = 0i64;
              v71 = Segment == v193;
              v72 = 0;
              v152 = Segment == v193;
              if ( v68->mNumOutgoingConnections )
              {
                while ( 1 )
                {
                  OutgoingConnection = UFG::RoadNetworkGate::GetOutgoingConnection(v68, v72);
                  v74 = OutgoingConnection;
                  if ( OutgoingConnection )
                  {
                    v75 = OutgoingConnection->mConnection.mOffset;
                    if ( v75 && (v76 = (char *)&v74->mConnection + v75) != 0i64 )
                    {
                      v77 = v76 - (char *)&v176;
                      v176 = v77;
                      if ( v77 )
                      {
                        v78 = (unsigned int *)((char *)&v176 + v77);
                        goto LABEL_61;
                      }
                    }
                    else
                    {
                      v176 = 0i64;
                    }
                  }
                  else
                  {
                    v197 = 0i64;
                  }
                  v78 = 0i64;
LABEL_61:
                  if ( v74 )
                  {
                    if ( v78 )
                    {
                      for ( i = 0; i < *v78; ++i )
                      {
                        for ( j = 0; j < v74->mNumLanes; ++j )
                        {
                          if ( (unsigned int)v70 < 0xC )
                          {
                            v198[v70] = (__int64)UFG::qBezierPathCollectionMemImaged::GetPath(v74, j);
                            v70 = (unsigned int)(v70 + 1);
                          }
                        }
                      }
                    }
                  }
                  if ( ++v72 >= v68->mNumOutgoingConnections )
                  {
                    v71 = v152;
                    break;
                  }
                }
              }
              if ( v71 )
              {
                for ( k = 0; k < v68->mNumIncomingConnections; ++k )
                {
                  v82 = UFG::RoadNetworkGate::GetIncomingConnection(v68, k);
                  v83 = v82;
                  if ( v82 )
                  {
                    v84 = v82->mConnection.mOffset;
                    if ( v84 && (v85 = (char *)&v83->mConnection + v84) != 0i64 )
                    {
                      v86 = v85 - (char *)&v169;
                      v169 = v86;
                      if ( v86 )
                      {
                        v87 = (unsigned int *)((char *)&v169 + v86);
                        goto LABEL_81;
                      }
                    }
                    else
                    {
                      v169 = 0i64;
                    }
                  }
                  else
                  {
                    v196 = 0i64;
                  }
                  v87 = 0i64;
LABEL_81:
                  if ( v83 )
                  {
                    if ( v87 )
                    {
                      for ( m = 0; m < *v87; ++m )
                      {
                        for ( n = 0; n < v83->mNumLanes; ++n )
                        {
                          if ( (unsigned int)v70 < 0xC )
                          {
                            v198[v70] = (__int64)UFG::qBezierPathCollectionMemImaged::GetPath(v83, n);
                            v70 = (unsigned int)(v70 + 1);
                          }
                        }
                      }
                    }
                  }
                }
              }
              v90 = Render::DebugDrawManager::GetContext(Render::DebugDrawManager::mInstance, 2u);
              *(_QWORD *)&p0.x = 0i64;
              p0.z = 0.0;
              v91 = (Render::DebugDrawContext *)v90;
              if ( (_DWORD)v70 )
              {
                v92 = v198;
                v93 = (unsigned int)v70;
                v180 = v198;
                v179 = (unsigned int)v70;
                while ( 1 )
                {
                  v94 = (UFG::RoadNetworkLane *)*v92;
                  v95 = 0.0;
                  Length = UFG::RoadNetworkLane::GetLength((UFG::RoadNetworkLane *)*v92);
                  v97 = *(float *)&FLOAT_1_0;
                  v159 = *(float *)&FLOAT_1_0;
                  v164 = 3.0 / Length;
                  if ( (float)(3.0 / Length) >= 1.0 )
                    v164 = *(float *)&FLOAT_1_0;
                  if ( v152
                    && (laneT = 0.0,
                        UFG::RoadNetworkLane::GetNearestPoint(v94, &v160, &result, &laneT),
                        UFG::RoadNetworkLane::GetPos(v94, &p1, laneT),
                        v97 = laneT,
                        v159 = laneT,
                        enableDebugDraw) )
                  {
                    IsReversedInNode = UFG::RoadNetworkLane::IsReversedInNode(v94);
                    v99 = &p_mFocusTargetPosition->x;
                    v100 = &UFG::qColour::White;
                    v101 = p_mFocusTargetPosition->y;
                    v189.x = p_mFocusTargetPosition->x;
                    v102 = p_mFocusTargetPosition->z;
                    v189.y = v101;
                    if ( IsReversedInNode )
                      v100 = &UFG::qColour::Cyan;
                    r = v100->r;
                    v189.z = v102 + 1.0;
                    v192.y = v160.y;
                    colour.r = r;
                    g = v100->g;
                    v192.x = v160.x;
                    colour.g = g;
                    b = v100->b;
                    v192.z = v160.z + 1.0;
                    colour.b = b;
                    colour.a = v100->a;
                    Render::DebugDrawContext::DrawLine(v91, &v192, &v189, &colour, &UFG::qMatrix44::msIdentity, 0i64, 0);
                    centre.x = v160.x;
                    centre.y = v160.y;
                    centre.z = v160.z + 1.0;
                    Render::DebugDrawContext::DrawSphere(v91, &centre, v59, &colour, &UFG::qMatrix44::msIdentity, 0i64);
                    v191.x = result.x;
                    v191.y = result.y;
                    v191.z = result.z + 1.0;
                    Render::DebugDrawContext::DrawSphere(v91, &v191, v59, &colour, &UFG::qMatrix44::msIdentity, 0i64);
                    v185.x = v160.x;
                    v185.y = v160.y;
                    v185.z = v160.z + 1.0;
                    v181.y = p1.y;
                    v181.x = p1.x;
                    v181.z = p1.z + 1.0;
                    Render::DebugDrawContext::DrawLine(v91, &v181, &v185, &colour, &UFG::qMatrix44::msIdentity, 0i64, 0);
                    v187.x = p1.x;
                    v187.y = p1.y;
                    v187.z = p1.z + 1.0;
                    Render::DebugDrawContext::DrawSphere(v91, &v187, v59, &colour, &UFG::qMatrix44::msIdentity, 0i64);
                  }
                  else
                  {
                    v99 = &p_mFocusTargetPosition->x;
                  }
                  v106 = 0.0;
                  if ( v97 > 0.0 )
                    break;
LABEL_143:
                  if ( enableDebugDraw && v95 > 0.0 )
                  {
                    v190.x = p0.x;
                    v190.y = p0.y;
                    v190.z = p0.z + 2.0;
                    Render::DebugDrawContext::DrawLine(
                      v91,
                      &p0,
                      &v190,
                      &UFG::qColour::Green,
                      &UFG::qMatrix44::msIdentity,
                      0i64,
                      0);
                  }
                  ++v92;
                  v179 = --v93;
                  v180 = v92;
                  if ( !v93 )
                    goto LABEL_147;
                }
                while ( 2 )
                {
                  UFG::RoadNetworkLane::GetPos(v94, &position, v106);
                  y_low = (__m128)LODWORD(position.y);
                  v107 = position.x - *v99;
                  y_low.m128_f32[0] = position.y - v99[1];
                  v109 = position.z - v99[2];
                  v111 = y_low;
                  v110 = (float)((float)(y_low.m128_f32[0] * y_low.m128_f32[0]) + (float)(v107 * v107))
                       + (float)(v109 * v109);
                  v111.m128_f32[0] = v110;
                  if ( v110 == 0.0 )
                    v112 = 0.0;
                  else
                    v112 = 1.0 / _mm_sqrt_ps(v111).m128_f32[0];
                  v113 = y_low.m128_f32[0] * v112;
                  v114 = v107 * v112;
                  v115 = v109 * v112;
                  if ( v110 >= *(float *)&v45 )
                  {
                    if ( v110 <= v168 )
                    {
                      if ( enableForwardSpawning
                        || (float)((float)((float)(v113 * v167) + (float)(v114 * v172)) + (float)(v115 * v174)) <= -0.1 )
                      {
                        v118 = (float)((float)(v110 - *(float *)&v45) / (float)(v168 - *(float *)&v45))
                             + (float)((float)((float)((float)((float)((float)(v114 * v171) + (float)(v113 * v175))
                                                             + v115)
                                                     + 1.0)
                                             * 0.5)
                                     + 100.0);
                        IsPositionOnScreen = UFG::SimObjectUtility::IsPositionOnScreen(&position, 4.0, 0);
                        if ( IsPositionOnScreen )
                        {
                          mCurrentCamera = UFG::Director::Get()->mCurrentCamera;
                          if ( mCurrentCamera )
                            mCurrentCamera = (UFG::BaseCameraComponent *)((char *)mCurrentCamera + 80);
                          if ( (float)((float)((float)((float)(mCurrentCamera->mCamera.mView.v2.y - position.y)
                                                     * (float)(mCurrentCamera->mCamera.mView.v2.y - position.y))
                                             + (float)((float)(mCurrentCamera->mCamera.mView.v2.x - position.x)
                                                     * (float)(mCurrentCamera->mCamera.mView.v2.x - position.x)))
                                     + (float)((float)(mCurrentCamera->mCamera.mView.v2.z - position.z)
                                             * (float)(mCurrentCamera->mCamera.mView.v2.z - position.z))) < 3364.0 )
                            v118 = FLOAT_N99_0;
                        }
                        if ( v118 > v162 )
                        {
                          v121 = v94->mNode.mOffset ? (UFG::RoadNetworkNode *)((char *)v94 + v94->mNode.mOffset) : 0i64;
                          UFG::RoadNetworkNode::GetTangent(v121, &v184, v94->mLaneIndex, v106);
                          z_low = (__m128)LODWORD(v184.z);
                          v123 = (__m128)LODWORD(v184.x);
                          v123.m128_f32[0] = (float)((float)(v123.m128_f32[0] * v123.m128_f32[0])
                                                   + (float)(v184.y * v184.y))
                                           + (float)(z_low.m128_f32[0] * z_low.m128_f32[0]);
                          v124 = v123.m128_f32[0] == 0.0 ? 0.0 : 1.0 / _mm_sqrt_ps(v123).m128_f32[0];
                          v125 = v184.x * v124;
                          v126 = v184.y * v124;
                          z_low.m128_f32[0] = v184.z * v124;
                          v127 = (__m128)LODWORD(UFG::qVector3::msDirUp.x);
                          v165.v0.x = v184.x * v124;
                          v165.v0.y = v184.y * v124;
                          *(_QWORD *)&v165.v0.z = COERCE_UNSIGNED_INT(v184.z * v124);
                          v127.m128_f32[0] = (float)((float)(v127.m128_f32[0] * v127.m128_f32[0])
                                                   + (float)(UFG::qVector3::msDirUp.y * UFG::qVector3::msDirUp.y))
                                           + (float)(UFG::qVector3::msDirUp.z * UFG::qVector3::msDirUp.z);
                          v128 = v127.m128_f32[0] == 0.0 ? 0.0 : 1.0 / _mm_sqrt_ps(v127).m128_f32[0];
                          v129 = v128;
                          v130 = v128;
                          v131 = v128 * UFG::qVector3::msDirUp.z;
                          v132 = v129 * UFG::qVector3::msDirUp.y;
                          v133 = v130 * UFG::qVector3::msDirUp.x;
                          v134 = (float)(v132 * z_low.m128_f32[0]) - (float)(v131 * v126);
                          v135 = (float)(v131 * v125) - (float)(v133 * z_low.m128_f32[0]);
                          v136 = (float)(v133 * v126) - (float)(v132 * v125);
                          v137 = (float)((float)(v135 * v135) + (float)(v134 * v134)) + (float)(v136 * v136);
                          v138 = v137 == 0.0 ? 0.0 : 1.0 / fsqrt(v137);
                          v139 = v138;
                          v140 = v138;
                          *(float *)&v141 = v138 * v136;
                          *(_QWORD *)&v165.v1.z = v141;
                          v165.v1.x = v140 * v134;
                          v165.v1.y = v139 * v135;
                          v142 = (float)(v126 * *(float *)&v141) - (float)(z_low.m128_f32[0] * (float)(v139 * v135));
                          v143 = v125;
                          v144 = (float)(v125 * v165.v1.y) - (float)(v126 * (float)(v140 * v134));
                          z_low.m128_f32[0] = (float)(z_low.m128_f32[0] * (float)(v140 * v134))
                                            - (float)(v143 * *(float *)&v141);
                          v145 = z_low;
                          v145.m128_f32[0] = (float)((float)(z_low.m128_f32[0] * z_low.m128_f32[0])
                                                   + (float)(v142 * v142))
                                           + (float)(v144 * v144);
                          v146 = v145.m128_f32[0] == 0.0 ? 0.0 : 1.0 / _mm_sqrt_ps(v145).m128_f32[0];
                          vfptr = this->vfptr;
                          *(_QWORD *)&v165.v3.x = *(_QWORD *)&position.x;
                          *(_QWORD *)&v165.v3.z = LODWORD(position.z) | 0x3F80000000000000i64;
                          v165.v2.x = v142 * v146;
                          v165.v2.y = z_low.m128_f32[0] * v146;
                          *(_QWORD *)&v165.v2.z = COERCE_UNSIGNED_INT(v144 * v146);
                          v148 = (char)vfptr[57].__vecDelDtor(this, (unsigned int)&v165);
                          v97 = v159;
                          v45 = v163;
                          if ( v148 )
                          {
                            v149 = v165.v1;
                            v162 = v118;
                            v153 = 1;
                            pTransform->v0 = v165.v0;
                            pTransform->v1 = v149;
                            v150 = v165.v3;
                            pTransform->v2 = v165.v2;
                            pTransform->v3 = v150;
                            *location_is_on_screen = IsPositionOnScreen;
                          }
                        }
                        if ( enableDebugDraw )
                        {
                          v186.x = position.x;
                          v186.y = position.y;
                          v186.z = position.z + 1.0;
                          Render::DebugDrawContext::DrawLine(
                            v91,
                            &position,
                            &v186,
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
                        v182[0] = LODWORD(position.x);
                        v182[1] = LODWORD(position.y);
                        v116 = &UFG::qColour::Cyan;
                        v117 = (UFG::qVector3 *)v182;
                        *(float *)&v182[2] = position.z + 1.0;
                        goto LABEL_140;
                      }
                      goto LABEL_141;
                    }
                    if ( v110 >= *(float *)&v45 )
                      goto LABEL_141;
                  }
                  if ( enableDebugDraw )
                  {
                    v188.x = position.x;
                    v188.y = position.y;
                    v116 = &UFG::qColour::Red;
                    v117 = &v188;
                    v188.z = position.z + 1.0;
LABEL_140:
                    Render::DebugDrawContext::DrawLine(v91, &position, v117, v116, &UFG::qMatrix44::msIdentity, 0i64, 0);
                  }
LABEL_141:
                  v106 = v106 + v164;
                  if ( v106 >= v97 )
                  {
                    v59 = FLOAT_0_30000001;
                    v92 = v180;
                    v93 = v179;
                    goto LABEL_143;
                  }
                  continue;
                }
              }
LABEL_147:
              v58 = v161;
              RoadNetworkGraph = v177;
              v9 = this;
            }
          }
        }
      }
LABEL_148:
      v21 = v178 + 1;
      v178 = v21;
      if ( v21 >= v194 )
      {
        LOBYTE(v21) = v153;
        return v21;
      }
    }
  }
  return v21;
}

// File Line: 1757
// RVA: 0x3F63A0
UFG::EncounterUnitComponent *__fastcall UFG::EncounterBase::HandleOnFootSpawn(
        UFG::EncounterBase *this,
        UFG::qMatrix44 *pSpawnTransform,
        UFG::qPropertySet *pGroupPropertySet,
        UFG::qSymbol *pSpecificCharacterResource)
{
  UFG::qPropertySet *mpPropSet; // r12
  __int64 v10; // rsi
  UFG::qPropertySet *v11; // rax
  UFG::qPropertyList *v12; // rbx
  unsigned int RandomIndex; // eax
  UFG::EncounterBase::ReplenishStyle mReplenishStyle; // edx
  unsigned int mNumWaveGroupTypes; // r8d
  unsigned int v16; // r9d
  unsigned int v17; // ecx
  char *ValuePtr; // rax
  UFG::qPropertySet *PropertySet; // rbx
  UFG::ObjectResourceManager *v20; // rax
  __int64 v21; // rdx
  const char *v22; // rax
  UFG::qSymbol *v23; // rax
  UFG::EncounterUnitComponent *m_pComponent; // r14
  UFG::SimObject *v25; // rax
  UFG::SimObjectCVBase *v26; // rbx
  UFG::PedSpawnManager *Instance; // rax
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rax
  UFG::PedSpawnManager *v29; // rax
  __int16 m_Flags; // cx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::qMemoryPool *SimulationMemoryPool; // rax
  UFG::allocator::free_link *v33; // rax
  UFG::EncounterUnitComponent *v34; // rax
  __int16 v35; // cx
  unsigned int v36; // r15d
  UFG::SimObjectGame *m_pSimObject; // rcx
  __int16 v38; // dx
  UFG::SimComponent *v39; // rax
  UFG::qSymbol *v40; // rax
  UFG::qSymbol *v41; // r15
  UFG::GameStatTracker *v42; // rax
  UFG::qSymbol *v43; // rax
  UFG::qSymbol *v44; // r15
  UFG::qPropertySet *v45; // rax
  UFG::SimObjectGame *v46; // rax
  UFG::SimObject *v47; // rsi
  __int16 v48; // dx
  UFG::RigidBody *v49; // rax
  __int16 v50; // cx
  UFG::InventoryComponent *v51; // rax
  UFG::SceneObjectProperties *m_pSceneObj; // rax
  UFG::qPropertySet *mpWritableProperties; // r12
  __int16 v54; // cx
  UFG::TSActorComponent *ComponentOfType; // r15
  UFG::qSymbol *v56; // rax
  UFG::TSActor *Actor; // rax
  UFG::qSymbol *v58; // rax
  UFG::TSActor *v59; // rax
  UFG::qSymbol *v60; // rax
  UFG::qPropertySet *v61; // rax
  UFG::qSymbol objName; // [rsp+30h] [rbp-40h] BYREF
  UFG::qSymbol result[2]; // [rsp+38h] [rbp-38h] BYREF
  __int64 v64; // [rsp+40h] [rbp-30h]
  UFG::SimObjectModifier v65; // [rsp+48h] [rbp-28h] BYREF
  UFG::qSymbol propSetName; // [rsp+A0h] [rbp+30h] BYREF

  v64 = -2i64;
  if ( this->mHumans.size >= 0x20 )
    return 0i64;
  UFG::PropertySetHandle::Bind(&this->mProperties);
  mpPropSet = this->mProperties.mpPropSet;
  propSetName.mUID = -1;
  v10 = 0i64;
  if ( pGroupPropertySet && pSpecificCharacterResource )
  {
    propSetName.mUID = pSpecificCharacterResource->mUID;
  }
  else
  {
    v11 = (UFG::qPropertySet *)((__int64 (__fastcall *)(UFG::EncounterBase *))this->vfptr[33].__vecDelDtor)(this);
    v12 = UFG::qPropertySet::Get<UFG::qPropertyList>(
            v11,
            (UFG::qArray<unsigned long,0> *)&EncounterSym_spawn_groups,
            DEPTH_RECURSE);
    RandomIndex = 0;
    mReplenishStyle = this->mReplenishStyle;
    if ( mReplenishStyle )
    {
      if ( mReplenishStyle == ReplenishStyle_TopUpByWaveType )
      {
        mNumWaveGroupTypes = this->mNumWaveGroupTypes;
        v16 = mNumWaveGroupTypes;
        v17 = 0;
        if ( mNumWaveGroupTypes )
        {
          while ( this->mWaveGroupTypes[v17] != F5_1Pt2_512
               || this->mWaveGroupInstances[v17] >= this->mWaveGroupInstancesRequired[v17] )
          {
            if ( ++v17 >= mNumWaveGroupTypes )
              goto LABEL_14;
          }
          v16 = v17;
        }
LABEL_14:
        RandomIndex = 0;
        if ( v16 < mNumWaveGroupTypes )
          RandomIndex = v16;
      }
    }
    else
    {
      RandomIndex = UFG::qPropertyList::GetRandomIndex(v12);
    }
    ValuePtr = UFG::qPropertyList::GetValuePtr(v12, 0x1Au, RandomIndex);
    if ( !ValuePtr || (pGroupPropertySet = (UFG::qPropertySet *)&ValuePtr[*(_QWORD *)ValuePtr], !*(_QWORD *)ValuePtr) )
      pGroupPropertySet = 0i64;
    propSetName.mUID = UFG::qPropertySet::Get<UFG::qSymbol>(
                         pGroupPropertySet,
                         (UFG::qArray<unsigned long,0> *)&EncounterSym_character,
                         DEPTH_RECURSE)->mUID;
  }
  PropertySet = UFG::PropertySetManager::GetPropertySet(&propSetName);
  v20 = UFG::ObjectResourceManager::Instance();
  if ( UFG::ObjectResourceManager::IsLoaded(v20, PropertySet) )
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
    v22 = (const char *)this->vfptr[82].__vecDelDtor(this, v21);
    v23 = UFG::qSymbol::create_from_string(result, v22);
    UFG::SimObjectUtility::GenerateUniqueActorName(&objName, v23);
    m_pComponent = 0i64;
    if ( pSpawnTransform )
      v25 = UFG::SpawnInfoInterface::SpawnObject(&objName, &propSetName, pSpawnTransform, UnReferenced, 0i64, 0i64);
    else
      v25 = UFG::SpawnInfoInterface::SpawnObject(&objName, &propSetName, UnReferenced, 0i64, 0i64, 0i64);
    v26 = (UFG::SimObjectCVBase *)v25;
    if ( v25 )
    {
      UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&v25->m_Name);
      UFG::qPrintChannel::Print(
        &UFG::gPrintChannel_HK_Encounters,
        OUTPUT_LEVEL_DEBUG,
        "[Encounters]: Spawned onfoot unit (%s)\n");
      UFG::PedSpawnManager::AquireOwnership(v26, 0, 1, -1);
      Instance = UFG::PedSpawnManager::GetInstance();
      UFG::PedSpawnManager::SetSuspendOption(Instance, v26, NoSuspend);
      m_pTransformNodeComponent = v26->m_pTransformNodeComponent;
      if ( m_pTransformNodeComponent && (m_pTransformNodeComponent->m_Flags & 3) != 1 )
      {
        v29 = UFG::PedSpawnManager::GetInstance();
        UFG::PedSpawnManager::ChangeActiveStatusOfSimObj(
          v29,
          Active,
          v26,
          "d:\\ufg\\madscience\\project\\sdhd\\sdhd_pc\\source\\ai\\encounters\\encounterbase.cpp",
          1854);
      }
      m_Flags = v26->m_Flags;
      if ( (m_Flags & 0x4000) != 0 )
      {
        m_pComponent = (UFG::EncounterUnitComponent *)v26->m_Components.p[16].m_pComponent;
      }
      else if ( m_Flags >= 0 )
      {
        if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
          ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(v26, UFG::EncounterUnitComponent::_TypeUID);
        else
          ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(v26, UFG::EncounterUnitComponent::_TypeUID);
        m_pComponent = (UFG::EncounterUnitComponent *)ComponentOfTypeHK;
      }
      else
      {
        m_pComponent = (UFG::EncounterUnitComponent *)v26->m_Components.p[16].m_pComponent;
      }
      if ( !m_pComponent )
      {
        SimulationMemoryPool = UFG::GetSimulationMemoryPool();
        v33 = UFG::qMemoryPool::Allocate(SimulationMemoryPool, 0xE0ui64, "EncounterUnitComponent", 0i64, 1u);
        *(_QWORD *)&result[0].mUID = v33;
        if ( v33 )
        {
          UFG::EncounterUnitComponent::EncounterUnitComponent((UFG::EncounterUnitComponent *)v33, v26->mNode.mUID);
          m_pComponent = v34;
        }
        else
        {
          m_pComponent = 0i64;
        }
        v35 = v26->m_Flags;
        if ( (v35 & 0x4000) != 0 )
        {
          v36 = 16;
        }
        else if ( v35 >= 0 )
        {
          v36 = -1;
        }
        else
        {
          v36 = 16;
        }
        UFG::SimObjectModifier::SimObjectModifier(&v65, v26, 1);
        UFG::SimObjectModifier::AttachComponent(&v65, m_pComponent, v36);
        UFG::SimObjectModifier::Close(&v65);
        UFG::SimObjectModifier::~SimObjectModifier(&v65);
      }
      this->mHumans.p[this->mHumans.size++] = m_pComponent;
      ((void (__fastcall *)(UFG::EncounterBase *, UFG::EncounterUnitComponent *, UFG::qPropertySet *))this->vfptr[69].__vecDelDtor)(
        this,
        m_pComponent,
        pGroupPropertySet);
      m_pSimObject = (UFG::SimObjectGame *)m_pComponent->m_pSimObject;
      if ( m_pSimObject )
      {
        v38 = m_pSimObject->m_Flags;
        if ( (v38 & 0x4000) != 0 )
        {
          v39 = m_pSimObject->m_Components.p[17].m_pComponent;
        }
        else if ( v38 >= 0 )
        {
          v39 = (v38 & 0x2000) != 0 || (v38 & 0x1000) != 0
              ? UFG::SimObjectGame::GetComponentOfTypeHK(m_pSimObject, UFG::CopUnitComponent::_TypeUID)
              : UFG::SimObject::GetComponentOfType(m_pSimObject, UFG::CopUnitComponent::_TypeUID);
        }
        else
        {
          v39 = m_pSimObject->m_Components.p[17].m_pComponent;
        }
        if ( v39 )
          LOBYTE(v39[7].m_Flags) |= 3u;
      }
      v40 = UFG::qPropertySet::Get<UFG::qSymbol>(
              mpPropSet,
              (UFG::qArray<unsigned long,0> *)&qSymbol_EncounterFactionClass,
              DEPTH_RECURSE);
      v41 = v40;
      if ( v40 && v40->mUID != -1 )
      {
        v42 = UFG::FactionInterface::Get();
        UFG::FactionInterface::SetFaction(&v42->mFactionInterface, v26, v41);
      }
      if ( !*UFG::qPropertySet::Get<bool>(
               mpPropSet,
               (UFG::qArray<unsigned long,0> *)&qSymbol_SuppressWeapon,
               DEPTH_RECURSE) )
      {
        v43 = UFG::qPropertySet::Get<UFG::qSymbol>(
                pGroupPropertySet,
                (UFG::qArray<unsigned long,0> *)&EncounterSym_weapon,
                DEPTH_RECURSE);
        v44 = v43;
        if ( !v43 || v43->mUID == -1 )
        {
          m_pSceneObj = v26->m_pSceneObj;
          if ( m_pSceneObj )
          {
            mpWritableProperties = m_pSceneObj->mpWritableProperties;
            if ( !mpWritableProperties )
              mpWritableProperties = m_pSceneObj->mpConstProperties;
          }
          else
          {
            mpWritableProperties = 0i64;
          }
          v54 = v26->m_Flags;
          if ( (v54 & 0x4000) != 0 )
          {
            ComponentOfType = (UFG::TSActorComponent *)v26->m_Components.p[4].m_pComponent;
          }
          else if ( v54 >= 0 )
          {
            if ( (v54 & 0x2000) != 0 )
            {
              ComponentOfType = (UFG::TSActorComponent *)v26->m_Components.p[3].m_pComponent;
            }
            else if ( (v54 & 0x1000) != 0 )
            {
              ComponentOfType = (UFG::TSActorComponent *)v26->m_Components.p[2].m_pComponent;
            }
            else
            {
              ComponentOfType = (UFG::TSActorComponent *)UFG::SimObject::GetComponentOfType(
                                                           v26,
                                                           UFG::TSActorComponent::_TypeUID);
            }
          }
          else
          {
            ComponentOfType = (UFG::TSActorComponent *)v26->m_Components.p[4].m_pComponent;
          }
          v56 = UFG::qPropertySet::Get<UFG::qSymbol>(
                  mpWritableProperties,
                  (UFG::qArray<unsigned long,0> *)&qSymbol_DefaultFirearm,
                  DEPTH_RECURSE);
          if ( v56 && v56->mUID != -1 )
          {
            *(_QWORD *)&result[0].mUID = SSSymbol::as_instance((ASymbol *)v56);
            Actor = UFG::TSActorComponent::GetActor(ComponentOfType);
            ((void (__fastcall *)(UFG::TSActor *, UFG::qStaticSymbol *, UFG::qSymbol *, bool, _QWORD, _QWORD))Actor->vfptr[1].set_data_by_name)(
              Actor,
              &qSymbol_equip_firearm,
              result,
              *(_QWORD *)&result[0].mUID != 0i64,
              0i64,
              0i64);
          }
          v58 = UFG::qPropertySet::Get<UFG::qSymbol>(
                  mpWritableProperties,
                  (UFG::qArray<unsigned long,0> *)&qSymbol_DefaultMelee,
                  DEPTH_RECURSE);
          if ( v58 && v58->mUID != -1 )
          {
            *(_QWORD *)&result[0].mUID = SSSymbol::as_instance((ASymbol *)v58);
            v59 = UFG::TSActorComponent::GetActor(ComponentOfType);
            ((void (__fastcall *)(UFG::TSActor *, UFG::qStaticSymbol *, UFG::qSymbol *, bool, _QWORD, _QWORD))v59->vfptr[1].set_data_by_name)(
              v59,
              &qSymbol_equip_melee,
              result,
              *(_QWORD *)&result[0].mUID != 0i64,
              0i64,
              0i64);
          }
        }
        else
        {
          UFG::Simulation::GenerateUniqueName(&UFG::gSim, result, "EncounterWeapon");
          v45 = UFG::PropertySetManager::FindPropertySet(v44);
          if ( v45 )
          {
            v46 = (UFG::SimObjectGame *)UFG::SpawnInfoInterface::SpawnObject(
                                          result,
                                          v45,
                                          UnReferenced,
                                          0i64,
                                          0i64,
                                          0i64);
            v47 = v46;
            if ( v46 )
            {
              v48 = v46->m_Flags;
              if ( (v48 & 0x4000) != 0 || v48 < 0 || (v48 & 0x2000) != 0 || (v48 & 0x1000) != 0 )
                v49 = (UFG::RigidBody *)UFG::SimObjectGame::GetComponentOfTypeHK(v46, UFG::RigidBodyComponent::_TypeUID);
              else
                v49 = (UFG::RigidBody *)UFG::SimObject::GetComponentOfType(v46, UFG::RigidBodyComponent::_TypeUID);
              if ( v49 )
                UFG::RigidBody::SetMotionType(v49, 0x100u);
              v50 = v26->m_Flags;
              if ( (v50 & 0x4000) != 0 )
              {
                v51 = (UFG::InventoryComponent *)v26->m_Components.p[39].m_pComponent;
              }
              else if ( v50 < 0 || (v50 & 0x2000) != 0 || (v50 & 0x1000) != 0 )
              {
                v51 = (UFG::InventoryComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                   v26,
                                                   UFG::InventoryComponent::_TypeUID);
              }
              else
              {
                v51 = (UFG::InventoryComponent *)UFG::SimObject::GetComponentOfType(
                                                   v26,
                                                   UFG::InventoryComponent::_TypeUID);
              }
              if ( v51 )
                UFG::InventoryComponent::Equip(v51, v47);
            }
          }
        }
      }
      v60 = UFG::qPropertySet::Get<UFG::qSymbol>(
              pGroupPropertySet,
              (UFG::qArray<unsigned long,0> *)&EncounterSym_helmet,
              DEPTH_RECURSE);
      if ( v60 && v60->mUID != -1 )
      {
        v61 = UFG::PropertySetManager::FindPropertySet(v60);
        if ( v61 )
          UFG::SimObjectUtility::CreateAndAttachProp(v61, v26, 1);
      }
      this->vfptr[68].__vecDelDtor(this, (unsigned int)v26);
    }
    else
    {
      UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&propSetName);
      UFG::qPrintChannel::Print(
        &UFG::gPrintChannel_HK_Encounters,
        OUTPUT_LEVEL_DEBUG,
        "[Encounters]: Unable to spawn onfoot unit (%s)\n");
    }
    return m_pComponent;
  }
  UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&propSetName);
  UFG::qPrintChannel::Print(
    &UFG::gPrintChannel_HK_Encounters,
    OUTPUT_LEVEL_DEBUG,
    "[Encounters]: Character not spawning, resource not loaded yet (%s)\n");
  return (UFG::EncounterUnitComponent *)v10;
}

// File Line: 1961
// RVA: 0x3F6BC0
void __fastcall UFG::EncounterBase::HandleOnFootSpawnPost(UFG::EncounterBase *this, UFG::SimObjectCVBase *pOnFootSpawn)
{
  UFG::eAIObjective mObjective; // ebp
  signed __int16 v5; // dx
  UFG::SimComponent *m_pComponent; // rsi
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::qMemoryPool *SimulationMemoryPool; // rax
  UFG::allocator::free_link *v9; // rax
  UFG::SimComponent *v10; // rax
  signed __int16 m_Flags; // cx
  unsigned int v12; // ebx
  UFG::qPropertySet *mpPropSet; // r15
  UFG::qPropertySet *WritableProperties; // rbx
  UFG::qArray<unsigned long,0> *v15; // rax
  signed __int16 v16; // cx
  UFG::ActiveAIEntityComponent *ComponentOfType; // rax
  UFG::ActiveAIEntityComponent *v18; // rbx
  char *v19; // rax
  UFG::CombatRegion *m_pPointer; // rdx
  signed __int16 v21; // cx
  UFG::TargetingSystemBaseComponent *v22; // rbx
  UFG::SimComponent *v23; // rax
  UFG::SimObject *v24; // rax
  UFG::SimObjectModifier v25; // [rsp+38h] [rbp-40h] BYREF
  UFG::allocator::free_link *result; // [rsp+80h] [rbp+8h] BYREF

  mObjective = eAI_OBJECTIVE_NONE;
  if ( !pOnFootSpawn
    || ((v5 = pOnFootSpawn->m_Flags, (v5 & 0x4000) == 0)
      ? (v5 >= 0
       ? ((v5 & 0x2000) != 0 || (v5 & 0x1000) != 0
        ? (ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(
                                 pOnFootSpawn,
                                 UFG::EncounterUnitComponent::_TypeUID))
        : (ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(pOnFootSpawn, UFG::EncounterUnitComponent::_TypeUID)),
          m_pComponent = ComponentOfTypeHK)
       : (m_pComponent = pOnFootSpawn->m_Components.p[16].m_pComponent))
      : (m_pComponent = pOnFootSpawn->m_Components.p[16].m_pComponent),
        !m_pComponent) )
  {
    SimulationMemoryPool = UFG::GetSimulationMemoryPool();
    v9 = UFG::qMemoryPool::Allocate(SimulationMemoryPool, 0xE0ui64, "EncounterUnitComponent", 0i64, 1u);
    result = v9;
    if ( v9 )
    {
      UFG::EncounterUnitComponent::EncounterUnitComponent((UFG::EncounterUnitComponent *)v9, pOnFootSpawn->mNode.mUID);
      m_pComponent = v10;
    }
    else
    {
      m_pComponent = 0i64;
    }
    m_Flags = pOnFootSpawn->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      v12 = 16;
    }
    else if ( m_Flags >= 0 )
    {
      v12 = -1;
    }
    else
    {
      v12 = 16;
    }
    UFG::SimObjectModifier::SimObjectModifier(&v25, pOnFootSpawn, 1);
    UFG::SimObjectModifier::AttachComponent(&v25, m_pComponent, v12);
    UFG::SimObjectModifier::Close(&v25);
    UFG::SimObjectModifier::~SimObjectModifier(&v25);
    ((void (__fastcall *)(UFG::EncounterBase *, UFG::SimComponent *, _QWORD))this->vfptr[69].__vecDelDtor)(
      this,
      m_pComponent,
      0i64);
  }
  UFG::PropertySetHandle::Bind(&this->mProperties);
  mpPropSet = this->mProperties.mpPropSet;
  WritableProperties = UFG::SceneObjectProperties::GetWritableProperties(pOnFootSpawn->m_pSceneObj);
  UFG::qPropertySet::Set<bool>(WritableProperties, (UFG::qArray<unsigned long,0> *)&qSymbol_CanEnterExitVehicle, 1);
  v15 = (UFG::qArray<unsigned long,0> *)UFG::qSymbol::create_from_string((UFG::qSymbol *)&result, "SkipCombatEntry");
  UFG::qPropertySet::Set<bool>(WritableProperties, v15, 1);
  v16 = pOnFootSpawn->m_Flags;
  if ( (v16 & 0x4000) != 0 || v16 < 0 )
  {
    ComponentOfType = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>(pOnFootSpawn);
  }
  else if ( (v16 & 0x2000) != 0 || (v16 & 0x1000) != 0 )
  {
    ComponentOfType = (UFG::ActiveAIEntityComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                        pOnFootSpawn,
                                                        UFG::ActiveAIEntityComponent::_TypeUID);
  }
  else
  {
    ComponentOfType = (UFG::ActiveAIEntityComponent *)UFG::SimObject::GetComponentOfType(
                                                        pOnFootSpawn,
                                                        UFG::ActiveAIEntityComponent::_TypeUID);
  }
  v18 = ComponentOfType;
  if ( ComponentOfType )
  {
    v19 = UFG::qPropertySet::Get<char const *>(
            mpPropSet,
            (UFG::qArray<unsigned long,0> *)&qSymbol_OverrideAIBehaviour,
            DEPTH_RECURSE);
    if ( v19 && *v19 )
      UFG::ActiveAIEntityComponent::SetBehaviourTree(v18, v19);
    v18->m_MaxEngagementDistanceXY = 1000.0;
    v18->m_MaxEngagementDistanceZ = 1000.0;
    if ( this->mHeatLevel > HEATLEVEL_NONE )
      mObjective = this->mObjective;
    UFG::ActiveAIEntityComponent::SetCurrentObjective(v18, mObjective, "EncounterBase::HandleOnFootSpawnPost");
    m_pPointer = this->mpCombatRegion.m_pPointer;
    if ( m_pPointer )
      UFG::AIEntityComponent::SetCombatRegion(v18, m_pPointer);
  }
  v21 = pOnFootSpawn->m_Flags;
  if ( (v21 & 0x4000) != 0 )
  {
    v22 = (UFG::TargetingSystemBaseComponent *)pOnFootSpawn->m_Components.p[20].m_pComponent;
  }
  else if ( v21 >= 0 )
  {
    if ( (v21 & 0x2000) != 0 || (v21 & 0x1000) != 0 )
      v23 = UFG::SimObjectGame::GetComponentOfTypeHK(pOnFootSpawn, UFG::TargetingSystemBaseComponent::_TypeUID);
    else
      v23 = UFG::SimObject::GetComponentOfType(pOnFootSpawn, UFG::TargetingSystemBaseComponent::_TypeUID);
    v22 = (UFG::TargetingSystemBaseComponent *)v23;
  }
  else
  {
    v22 = (UFG::TargetingSystemBaseComponent *)pOnFootSpawn->m_Components.p[20].m_pComponent;
  }
  if ( v22 )
  {
    v24 = (UFG::SimObject *)((__int64 (__fastcall *)(UFG::EncounterBase *))this->vfptr[18].__vecDelDtor)(this);
    UFG::TargetingSystemBaseComponent::SetTarget(v22, eTARGET_TYPE_AI_OBJECTIVE, v24);
  }
  if ( this->mWaveCount <= 1 )
    HIDWORD(m_pComponent[2].m_SafePointerList.mNode.mNext) = m_pComponent[2].m_TypeUID;
}

// File Line: 2021
// RVA: 0x3F8130
char __fastcall UFG::EncounterBase::IsCorrectResourceType(UFG::EncounterBase *this, UFG::SimObject *pCop)
{
  UFG::SceneObjectProperties *m_pSceneObj; // rax
  UFG::qPropertySet *v4; // rax
  UFG::qPropertyList *v5; // rbp
  UFG::qResourceData *ArchetypeProperties; // rax
  unsigned int mNumElements; // edi
  unsigned int v8; // ebx
  UFG::qResourceData *v9; // rsi

  if ( !pCop )
    return 0;
  m_pSceneObj = pCop->m_pSceneObj;
  if ( !m_pSceneObj || !m_pSceneObj->mpWritableProperties && !m_pSceneObj->mpConstProperties )
    return 0;
  v4 = (UFG::qPropertySet *)((__int64 (__fastcall *)(UFG::EncounterBase *))this->vfptr[33].__vecDelDtor)(this);
  v5 = UFG::qPropertySet::Get<UFG::qPropertyList>(
         v4,
         (UFG::qArray<unsigned long,0> *)&EncounterSym_persistent_resources,
         DEPTH_RECURSE);
  ArchetypeProperties = UFG::SceneObjectProperties::GetArchetypeProperties(pCop->m_pSceneObj);
  mNumElements = v5->mNumElements;
  v8 = 0;
  v9 = ArchetypeProperties;
  if ( !mNumElements )
    return 0;
  while ( UFG::qPropertyList::Get<UFG::qSymbol>(v5, v8)->mUID != *(_DWORD *)&v9->mDebugName[12] )
  {
    if ( ++v8 >= mNumElements )
      return 0;
  }
  return 1;
}

// File Line: 2054
// RVA: 0x3F6090
float __fastcall UFG::EncounterBase::GetSpawnTimeout(UFG::EncounterBase *this)
{
  ((void (__fastcall *)(UFG::EncounterBase *))this->vfptr[32].__vecDelDtor)(this);
  return FLOAT_1_2;
}

// File Line: 2070
// RVA: 0x3FA530
void __fastcall UFG::EncounterBase::UpdateOnFootPopulation(
        UFG::EncounterBase *this,
        UFG::SimObject *pTarget,
        UFG::TransformNodeComponent *pTargetTransform)
{
  __int64 v6; // rbx
  unsigned int v7; // eax
  UFG::qSafePointerNode<UFG::EncounterBase>Vtbl *vfptr; // r10
  unsigned int v9; // ebx
  char v10; // r15
  unsigned int v11; // eax
  int v12; // ecx
  UFG::qSafePointerNode<UFG::EncounterBase>Vtbl *v13; // rax
  UFG::qSafePointerNode<UFG::EncounterBase>Vtbl *v14; // rax
  UFG::qSafePointerNode<UFG::EncounterBase>Vtbl *v15; // rax
  __int64 v16; // [rsp+10h] [rbp-19h] BYREF
  int v17; // [rsp+18h] [rbp-11h]
  __int128 v18[3]; // [rsp+20h] [rbp-9h] BYREF
  __int64 v19; // [rsp+50h] [rbp+27h]
  int v20; // [rsp+58h] [rbp+2Fh]
  int v21; // [rsp+5Ch] [rbp+33h]
  __int64 v22[2]; // [rsp+90h] [rbp+67h] BYREF
  void *retaddr; // [rsp+A8h] [rbp+7Fh] BYREF

  if ( !this->mFocusTargetContext.mIsInWater )
  {
    v6 = ((__int64 (__fastcall *)(UFG::EncounterBase *))this->vfptr[33].__vecDelDtor)(this);
    this->vfptr[35].__vecDelDtor(this, v6);
    v7 = (unsigned int)this->vfptr[36].__vecDelDtor(this, v6);
    vfptr = this->vfptr;
    v9 = v7;
    v22[0] = 0i64;
    if ( ((unsigned __int8 (__fastcall *)(UFG::EncounterBase *, __int64, UFG::SimObject *, UFG::TransformNodeComponent *, __int64 *))vfptr[48].__vecDelDtor)(
           this,
           1i64,
           pTarget,
           pTargetTransform,
           v22) )
    {
      do
        this->vfptr[68].__vecDelDtor(this, v22[0]);
      while ( ((unsigned __int8 (__fastcall *)(UFG::EncounterBase *, __int64, UFG::SimObject *, UFG::TransformNodeComponent *, __int64 *))this->vfptr[48].__vecDelDtor)(
                this,
                1i64,
                pTarget,
                pTargetTransform,
                v22) );
    }
    v10 = ((__int64 (__fastcall *)(UFG::EncounterBase *))this->vfptr[61].__vecDelDtor)(this);
    if ( v10 )
    {
      v11 = (unsigned int)this->vfptr[44].__vecDelDtor(this, 1i64);
      if ( v11 + v9 > 0x20 )
      {
        v12 = 32;
        if ( v11 < 0x20 )
          v12 = v11;
        v9 = 32 - v12;
      }
    }
    if ( this->mIsReplenishing && v10 && this->mHumans.size < v9 )
    {
      retaddr = 0i64;
      if ( ((unsigned __int8 (__fastcall *)(UFG::EncounterBase *, __int64, UFG::SimObject *, UFG::TransformNodeComponent *, void **))this->vfptr[48].__vecDelDtor)(
             this,
             1i64,
             pTarget,
             pTargetTransform,
             &retaddr) )
      {
        v13 = this->vfptr;
        ++this->mCharacterSpawnCount;
        v13[68].__vecDelDtor(this, (unsigned int)retaddr);
      }
      else if ( this->mSpawnTimeout <= 0.0 )
      {
        UFG::PropertySetHandle::Bind(&this->mProperties);
        if ( ((unsigned __int8 (__fastcall *)(UFG::EncounterBase *, UFG::qPropertySet *, UFG::TransformNodeComponent *, __int64 *))this->vfptr[34].__vecDelDtor)(
               this,
               this->mProperties.mpPropSet,
               pTargetTransform,
               &v16) )
        {
          v14 = this->vfptr;
          v18[0] = (__int128)UFG::qMatrix44::msIdentity.v0;
          v21 = (int)FLOAT_1_0;
          v18[1] = (__int128)UFG::qMatrix44::msIdentity.v1;
          v18[2] = (__int128)UFG::qMatrix44::msIdentity.v2;
          v19 = v16;
          v20 = v17;
          if ( *(_QWORD *)(((__int64 (__fastcall *)(UFG::EncounterBase *, __int128 *, _QWORD, _QWORD))v14[67].__vecDelDtor)(
                             this,
                             v18,
                             0i64,
                             0i64)
                         + 40) )
          {
            v15 = this->vfptr;
            ++this->mCharacterSpawnCount;
            this->mSpawnTimeout = ((float (__fastcall *)(UFG::EncounterBase *))v15[84].__vecDelDtor)(this);
          }
        }
      }
    }
  }
}

// File Line: 2142
// RVA: 0x3FB670
void __fastcall UFG::EncounterBase::UpdateVehiclePopulation(
        UFG::EncounterBase *this,
        UFG::SimObject *pTargetVehicle,
        UFG::TransformNodeComponent *pTargetTransform)
{
  __int64 v6; // rax
  int v7; // eax
  UFG::qSafePointerNode<UFG::EncounterBase>Vtbl *vfptr; // r9
  int v9; // ebp
  __int64 v10; // rsi
  UFG::qSafePointerNode<UFG::EncounterBase>Vtbl *v11; // rax
  __int64 v12; // [rsp+50h] [rbp+8h] BYREF

  v6 = ((__int64 (__fastcall *)(UFG::EncounterBase *))this->vfptr[33].__vecDelDtor)(this);
  v7 = (int)this->vfptr[35].__vecDelDtor(this, v6);
  vfptr = this->vfptr;
  v9 = v7;
  v12 = 0i64;
  v10 = ((__int64 (__fastcall *)(UFG::EncounterBase *))vfptr[18].__vecDelDtor)(this);
  while ( ((unsigned __int8 (__fastcall *)(UFG::EncounterBase *, __int64, __int64, UFG::TransformNodeComponent *, __int64 *))this->vfptr[48].__vecDelDtor)(
            this,
            2i64,
            v10,
            pTargetTransform,
            &v12) )
    ;
  if ( this->mIsReplenishing
    && this->mSpawnTimeout <= 0.0
    && this->mVehicles.size < 8
    && this->vfptr[75].__vecDelDtor(this, 2i64) < (void *)v9 )
  {
    if ( ((unsigned __int8 (__fastcall *)(UFG::EncounterBase *, UFG::SimObject *, UFG::TransformNodeComponent *))this->vfptr[66].__vecDelDtor)(
           this,
           pTargetVehicle,
           pTargetTransform) )
    {
      v11 = this->vfptr;
      ++this->mVehicleSpawnCount;
      this->mSpawnTimeout = ((float (__fastcall *)(UFG::EncounterBase *))v11[84].__vecDelDtor)(this);
    }
  }
}

// File Line: 2178
// RVA: 0x3F70B0
void __fastcall UFG::EncounterBase::HandleVehicleAcquired(
        UFG::EncounterBase *this,
        UFG::EncounterUnitComponent *pEncounterUnitComponent,
        UFG::qPropertySet *pEncounterPropertySet,
        UFG::qPropertySet *pGroupPropertySet)
{
  UFG::SimObjectGame *m_pSimObject; // rcx
  __int16 m_Flags; // r8
  UFG::SimComponent *m_pComponent; // rbx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  float *v11; // rax
  float *v12; // rax
  float *v13; // rax
  float *v14; // rax
  float *v15; // rax

  m_pSimObject = (UFG::SimObjectGame *)pEncounterUnitComponent->m_pSimObject;
  if ( !m_pSimObject )
    goto LABEL_22;
  m_Flags = m_pSimObject->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
    goto LABEL_22;
  if ( m_Flags >= 0 )
  {
    if ( (m_Flags & 0x2000) != 0 )
      goto LABEL_22;
    if ( (m_Flags & 0x1000) != 0 )
      ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(m_pSimObject, UFG::PhysicsMoverInterface::_TypeUID);
    else
      ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pSimObject, UFG::PhysicsMoverInterface::_TypeUID);
    m_pComponent = ComponentOfTypeHK;
  }
  else
  {
    m_pComponent = m_pSimObject->m_Components.p[34].m_pComponent;
  }
  if ( m_pComponent && pGroupPropertySet )
  {
    v11 = UFG::qPropertySet::Get<float>(
            pGroupPropertySet,
            (UFG::qArray<unsigned long,0> *)&EncounterSym_vehicle_damage_multiplier_world_collision,
            DEPTH_RECURSE);
    if ( v11 )
      *((float *)&m_pComponent[10].m_BoundComponentHandles.mNode.mNext + 1) = *v11;
    v12 = UFG::qPropertySet::Get<float>(
            pGroupPropertySet,
            (UFG::qArray<unsigned long,0> *)&EncounterSym_vehicle_damage_multiplier_vehicle_collision,
            DEPTH_RECURSE);
    if ( v12 )
      *(float *)&m_pComponent[11].vfptr = *v12;
    v13 = UFG::qPropertySet::Get<float>(
            pGroupPropertySet,
            (UFG::qArray<unsigned long,0> *)&EncounterSym_vehicle_damage_multiplier_attacks,
            DEPTH_RECURSE);
    if ( v13 )
      *((float *)&m_pComponent[11].vfptr + 1) = *v13;
    v14 = UFG::qPropertySet::Get<float>(
            pGroupPropertySet,
            (UFG::qArray<unsigned long,0> *)&EncounterSym_vehicle_damage_multiplier_bullets,
            DEPTH_RECURSE);
    if ( v14 )
      *(float *)&m_pComponent[11].m_SafePointerList.mNode.mPrev = *v14;
    v15 = UFG::qPropertySet::Get<float>(
            pGroupPropertySet,
            (UFG::qArray<unsigned long,0> *)&EncounterSym_vehicle_damage_multiplier_tires,
            DEPTH_RECURSE);
    if ( v15 )
      *((float *)&m_pComponent[11].m_SafePointerList.mNode.mPrev + 1) = *v15;
  }
LABEL_22:
  if ( this->mWaveCount <= 1 )
    pEncounterUnitComponent->mInsideRadiusTimer = pEncounterUnitComponent->mAcquiredTimer;
}

// File Line: 2220
// RVA: 0x3F7260
char __fastcall UFG::EncounterBase::HandleVehicleSpawn(
        UFG::EncounterBase *this,
        UFG::SimObjectGame *pTargetVehicle,
        UFG::TransformNodeComponent *pTargetTransform)
{
  UFG::qPropertyList *v5; // r15
  unsigned int v6; // esi
  UFG::EncounterBase::ReplenishStyle mReplenishStyle; // edx
  unsigned int mNumWaveGroupTypes; // r8d
  unsigned int v9; // r9d
  __int64 v10; // rcx
  int v11; // ebx
  unsigned int RandomIndex; // eax
  char *ValuePtr; // rax
  UFG::qPropertySet *v14; // r12
  UFG::qSymbol *v15; // rbx
  UFG::qSymbol *v16; // r13
  bool *v17; // rax
  unsigned __int8 v18; // si
  UFG::qPropertySet *PropertySet; // rbx
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
  char *MemImagePtr; // rax
  UFG::qPropertySet *m_Flags; // rdx
  UFG::qPropertySet *v32; // r13
  __int64 v33; // rsi
  float v34; // xmm8_4
  float v35; // xmm7_4
  UFG::SimComponent *m_pComponent; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qPropertySet *ComponentData; // rax
  float v39; // xmm6_4
  UFG::qArray<unsigned long,0> *v40; // rax
  UFG::qPropertySet *v41; // r13
  float v42; // xmm6_4
  UFG::TransformNodeComponent *v43; // rbx
  signed __int16 v44; // cx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  float *p_m_pSimObject; // rax
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
  __m128 x_low; // xmm2
  __m128 v58; // xmm4
  float v59; // xmm2_4
  float v60; // xmm3_4
  UFG::EncounterUnitComponent *v61; // rsi
  UFG::qMemoryPool *SimulationMemoryPool; // rax
  UFG::allocator::free_link *v63; // rax
  UFG::EncounterUnitComponent *v64; // rax
  __int16 mUID; // cx
  unsigned int v66; // ebx
  UFG::SimObjectGame *m_pSimObject; // rcx
  __int16 v68; // dx
  UFG::SimComponent *ComponentOfType; // rax
  UFG::CompositeLookComponent *v70; // rax
  UFG::CompositeLookComponent *v71; // rbx
  UFG::qSymbol v73; // [rsp+40h] [rbp-88h] BYREF
  UFG::qSymbol result; // [rsp+44h] [rbp-84h] BYREF
  UFG::qPropertySet *mpPropSet; // [rsp+48h] [rbp-80h]
  unsigned int v76; // [rsp+50h] [rbp-78h]
  UFG::qSymbol objName; // [rsp+54h] [rbp-74h] BYREF
  UFG::qMatrix44 xform; // [rsp+58h] [rbp-70h] BYREF
  char v79[16]; // [rsp+148h] [rbp+80h] BYREF
  UFG::TransformNodeComponent *v80; // [rsp+158h] [rbp+90h]
  UFG::qSymbol propSetName; // [rsp+160h] [rbp+98h] BYREF

  *(_QWORD *)&xform.v1.x = -2i64;
  *(_QWORD *)&xform.v0.z = 0i64;
  if ( ((unsigned __int8 (__fastcall *)(UFG::EncounterBase *, __int64, UFG::SimObjectGame *, UFG::TransformNodeComponent *, float *))this->vfptr[48].__vecDelDtor)(
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
  *(_QWORD *)&xform.v0.x = ((__int64 (__fastcall *)(UFG::EncounterBase *))this->vfptr[33].__vecDelDtor)(this);
  v5 = UFG::qPropertySet::Get<UFG::qPropertyList>(
         *(UFG::qPropertySet **)&xform.v0.x,
         (UFG::qArray<unsigned long,0> *)&EncounterSym_spawn_groups,
         DEPTH_RECURSE);
  v6 = 0;
  mReplenishStyle = this->mReplenishStyle;
  if ( mReplenishStyle )
  {
    if ( mReplenishStyle == ReplenishStyle_TopUpByWaveType )
    {
      mNumWaveGroupTypes = this->mNumWaveGroupTypes;
      v9 = mNumWaveGroupTypes;
      v10 = 0i64;
      if ( mNumWaveGroupTypes )
      {
        while ( this->mWaveGroupTypes[v10] != F3_1Pt44_512
             || this->mWaveGroupInstances[v10] >= this->mWaveGroupInstancesRequired[v10] )
        {
          v10 = (unsigned int)(v10 + 1);
          if ( (unsigned int)v10 >= mNumWaveGroupTypes )
            goto LABEL_11;
        }
        v9 = v10;
      }
LABEL_11:
      if ( v9 < mNumWaveGroupTypes )
        v6 = v9;
    }
  }
  else
  {
    v11 = 0;
    while ( 1 )
    {
      RandomIndex = UFG::qPropertyList::GetRandomIndex(v5);
      v6 = RandomIndex;
      if ( this->mWaveGroupTypes[RandomIndex] == F3_1Pt44_512 )
        break;
      if ( ++v11 >= 10 )
      {
        if ( this->mWaveGroupTypes[RandomIndex] != F3_1Pt44_512 )
          return 0;
        break;
      }
    }
  }
  UFG::PropertySetHandle::Bind(&this->mProperties);
  mpPropSet = this->mProperties.mpPropSet;
  ValuePtr = UFG::qPropertyList::GetValuePtr(v5, 0x1Au, v6);
  if ( ValuePtr && *(_QWORD *)ValuePtr )
    v14 = (UFG::qPropertySet *)&ValuePtr[*(_QWORD *)ValuePtr];
  else
    v14 = 0i64;
  v15 = UFG::qPropertySet::Get<UFG::qSymbol>(v14, (UFG::qArray<unsigned long,0> *)&EncounterSym_boat, DEPTH_RECURSE);
  v16 = UFG::qPropertySet::Get<UFG::qSymbol>(v14, (UFG::qArray<unsigned long,0> *)&EncounterSym_vehicle, DEPTH_RECURSE);
  v73.mUID = UFG::qPropertySet::Get<UFG::qSymbol>(
               v14,
               (UFG::qArray<unsigned long,0> *)&EncounterSym_character,
               DEPTH_RECURSE)->mUID;
  if ( v16 )
    v15 = v16;
  propSetName.mUID = v15->mUID;
  v76 = ((__int64 (__fastcall *)(UFG::EncounterBase *, UFG::qPropertySet *, UFG::qSymbol *))this->vfptr[52].__vecDelDtor)(
          this,
          v14,
          &propSetName);
  if ( v76 + this->mHumans.size < 0x20 )
  {
    v17 = UFG::qPropertySet::Get<bool>(
            *(UFG::qPropertySet **)&xform.v0.x,
            (UFG::qArray<unsigned long,0> *)&EncounterSym_enable_forward_spawning,
            DEPTH_RECURSE);
    if ( v17 )
      v18 = *v17;
    else
      v18 = 0;
    if ( this->mFocusTargetContext.mIsOnFootHeuristic )
    {
      v18 = 1;
    }
    else if ( this->mEnableWaveTimerChangesByDisabledUnits
           && UFG::Metrics::msInstance.mSimTimeMSec - this->mStartTimestamp > 0x1D4C0 )
    {
      v18 &= !this->mHasSpawnedInFrontForCurrentWave;
    }
    PropertySet = UFG::PropertySetManager::GetPropertySet(&propSetName);
    v20 = UFG::PropertySetManager::GetPropertySet(&v73);
    v21 = UFG::ObjectResourceManager::Instance();
    if ( !UFG::ObjectResourceManager::IsLoaded(v21, PropertySet)
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
    v79[0] = 0;
    if ( !((unsigned __int8 (__fastcall *)(UFG::EncounterBase *, _QWORD, UFG::SimObjectGame *, UFG::TransformNodeComponent *, UFG::qMatrix44 *, char *, _BYTE))this->vfptr[56].__vecDelDtor)(
            this,
            v18,
            pTargetVehicle,
            v80,
            &xform,
            v79,
            0) )
      return 0;
    v23 = (const char *)this->vfptr[82].__vecDelDtor(this, 0i64);
    v24 = UFG::qSymbol::create_from_string(&result, v23);
    UFG::SimObjectUtility::GenerateUniqueActorName(&objName, v24);
    v25 = (UFG::qSymbolUC *)UFG::SpawnInfoInterface::SpawnObject(
                              &objName,
                              &propSetName,
                              &xform,
                              UnReferenced,
                              0i64,
                              0i64);
    v26 = v25;
    if ( !v25 )
    {
      UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)v16);
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
            (UFG::qArray<unsigned long,0> *)&component_PhysicsMover::sPropertyName,
            DEPTH_RECURSE);
    if ( v29 )
      MemImagePtr = UFG::qPropertySet::GetMemImagePtr(v29);
    else
      MemImagePtr = 0i64;
    result.mUID = *((_DWORD *)MemImagePtr + 1);
    v32 = UFG::PropertySetManager::FindPropertySet(&result);
    v33 = *(_QWORD *)(*(_QWORD *)&v26[26].mUID + 32i64);
    v34 = 0.0;
    v35 = 0.0;
    if ( !pTargetVehicle )
      goto LABEL_62;
    m_Flags = (UFG::qPropertySet *)pTargetVehicle->m_Flags;
    if ( ((unsigned __int16)m_Flags & 0x4000) == 0 )
    {
      if ( (__int16)m_Flags < 0 )
      {
        m_pComponent = pTargetVehicle->m_Components.p[34].m_pComponent;
        goto LABEL_55;
      }
      if ( ((unsigned __int16)m_Flags & 0x2000) == 0 )
      {
        if ( ((unsigned __int16)m_Flags & 0x1000) != 0 )
          m_pComponent = UFG::SimObjectGame::GetComponentOfTypeHK(pTargetVehicle, UFG::PhysicsMoverInterface::_TypeUID);
        else
          m_pComponent = UFG::SimObject::GetComponentOfType(pTargetVehicle, UFG::PhysicsMoverInterface::_TypeUID);
LABEL_55:
        if ( m_pComponent )
        {
          mPrev = m_pComponent[10].m_SafePointerList.mNode.mPrev;
LABEL_59:
          if ( m_pComponent && mPrev )
            v35 = *((float *)&mPrev[36].mNext + 1);
LABEL_62:
          if ( v33 && v32 )
          {
            ComponentData = UFG::PropertySetManager::GetComponentDataPtr<Vehicles_BasePhysicsProperties>(
                              (UFG::PropertySetManager *)v28,
                              m_Flags);
            if ( ComponentData )
              v39 = *((float *)&ComponentData->mNext + 1);
            else
              v39 = FLOAT_70_0;
            v40 = (UFG::qArray<unsigned long,0> *)UFG::qSymbol::create_from_string(
                                                    (UFG::qSymbol *)&xform,
                                                    "vehicle_initial_speed_ratio");
            v41 = mpPropSet;
            v42 = v39 * *UFG::qPropertySet::Get<float>(mpPropSet, v40, DEPTH_RECURSE);
            v43 = v80;
            UFG::TransformNodeComponent::UpdateWorldTransform(v80);
            if ( pTargetVehicle
              && ((v44 = pTargetVehicle->m_Flags, (v44 & 0x4000) == 0)
                ? (v44 >= 0
                 ? ((v44 & 0x2000) != 0 || (v44 & 0x1000) != 0
                  ? (ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(
                                           pTargetVehicle,
                                           UFG::RoadSpaceComponent::_TypeUID))
                  : (ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(
                                           pTargetVehicle,
                                           UFG::RoadSpaceComponent::_TypeUID)))
                 : (ComponentOfTypeHK = pTargetVehicle->m_Components.p[24].m_pComponent))
                : (ComponentOfTypeHK = pTargetVehicle->m_Components.p[24].m_pComponent),
                  ComponentOfTypeHK) )
            {
              p_m_pSimObject = (float *)&ComponentOfTypeHK[27].m_pSimObject;
            }
            else
            {
              UFG::TransformNodeComponent::UpdateWorldTransform(v43);
              p_m_pSimObject = &v43->mWorldTransform.v0.x;
            }
            v47 = p_m_pSimObject[1];
            v48 = (__m128)*(unsigned int *)p_m_pSimObject;
            v49 = p_m_pSimObject[2];
            v50 = v48;
            v50.m128_f32[0] = (float)((float)(v48.m128_f32[0] * v48.m128_f32[0]) + (float)(v47 * v47))
                            + (float)(v49 * v49);
            if ( v50.m128_f32[0] == 0.0 )
              v51 = 0.0;
            else
              v51 = 1.0 / _mm_sqrt_ps(v50).m128_f32[0];
            v52 = v49 * v51;
            v53 = v47 * v51;
            v54 = v48.m128_f32[0] * v51;
            v55 = xform.v3.z - v43->mWorldTransform.v3.z;
            v56 = xform.v3.y - v43->mWorldTransform.v3.y;
            x_low = (__m128)LODWORD(xform.v3.x);
            x_low.m128_f32[0] = xform.v3.x - v43->mWorldTransform.v3.x;
            v58 = x_low;
            v58.m128_f32[0] = (float)((float)(x_low.m128_f32[0] * x_low.m128_f32[0]) + (float)(v56 * v56))
                            + (float)(v55 * v55);
            if ( v58.m128_f32[0] != 0.0 )
              v34 = 1.0 / _mm_sqrt_ps(v58).m128_f32[0];
            v59 = (float)((float)((float)(x_low.m128_f32[0] * v34) * v54) + (float)((float)(v56 * v34) * v53))
                + (float)((float)(v55 * v34) * v52);
            v60 = 1.0 - (float)((float)(v59 + 1.0) * 0.5);
            if ( v60 < 0.1 )
              v60 = FLOAT_0_1;
            if ( v59 > -0.1 )
              this->mHasSpawnedInFrontForCurrentWave = 1;
            if ( v35 <= v42 )
              v35 = v42;
            UFG::VehicleUtility::OverrideForwardSpeedKPH((UFG::SimObjectVehicle *)v26, v35 * v60);
          }
          else
          {
            v41 = mpPropSet;
          }
          v61 = *(UFG::EncounterUnitComponent **)(*(_QWORD *)&v26[26].mUID + 256i64);
          if ( !v61 )
          {
            SimulationMemoryPool = UFG::GetSimulationMemoryPool();
            v63 = UFG::qMemoryPool::Allocate(SimulationMemoryPool, 0xE0ui64, "EncounterUnitComponent", 0i64, 1u);
            mpPropSet = (UFG::qPropertySet *)v63;
            if ( v63 )
            {
              UFG::EncounterUnitComponent::EncounterUnitComponent((UFG::EncounterUnitComponent *)v63, v26[16].mUID);
              v61 = v64;
            }
            else
            {
              v61 = 0i64;
            }
            mUID = v26[19].mUID;
            if ( (mUID & 0x4000) != 0 )
            {
              v66 = 16;
            }
            else if ( mUID >= 0 )
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
          if ( ((unsigned __int8 (__fastcall *)(UFG::EncounterBase *, UFG::qMatrix44 *, _QWORD, UFG::qPropertySet *, UFG::qSymbolUC *, UFG::qSymbol *))this->vfptr[53].__vecDelDtor)(
                 this,
                 &xform,
                 v76,
                 v14,
                 v26,
                 &v73) )
          {
            this->mVehicles.p[this->mVehicles.size++] = v61;
            ((void (__fastcall *)(UFG::EncounterBase *, UFG::EncounterUnitComponent *, UFG::qPropertySet *))this->vfptr[69].__vecDelDtor)(
              this,
              v61,
              v14);
            m_pSimObject = (UFG::SimObjectGame *)v61->m_pSimObject;
            if ( m_pSimObject )
            {
              v68 = m_pSimObject->m_Flags;
              if ( (v68 & 0x4000) != 0 )
              {
                ComponentOfType = m_pSimObject->m_Components.p[17].m_pComponent;
              }
              else if ( v68 >= 0 )
              {
                if ( (v68 & 0x2000) != 0 || (v68 & 0x1000) != 0 )
                  ComponentOfType = UFG::SimObjectGame::GetComponentOfTypeHK(
                                      m_pSimObject,
                                      UFG::CopUnitComponent::_TypeUID);
                else
                  ComponentOfType = UFG::SimObject::GetComponentOfType(m_pSimObject, UFG::CopUnitComponent::_TypeUID);
              }
              else
              {
                ComponentOfType = m_pSimObject->m_Components.p[17].m_pComponent;
              }
              if ( ComponentOfType )
                LOBYTE(ComponentOfType[7].m_Flags) |= 3u;
            }
            ((void (__fastcall *)(UFG::EncounterBase *, UFG::EncounterUnitComponent *, UFG::qPropertySet *, UFG::qPropertySet *))this->vfptr[81].__vecDelDtor)(
              this,
              v61,
              v41,
              v14);
            if ( v79[0] )
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
        mPrev = 0i64;
        goto LABEL_59;
      }
    }
    m_pComponent = 0i64;
    goto LABEL_58;
  }
  return 0;
}

// File Line: 2466
// RVA: 0x3F5E40
__int64 __fastcall UFG::EncounterBase::GetDesiredNumOccupants(
        UFG::EncounterBase *this,
        UFG::qPropertySet *pGroupPropertySet,
        UFG::qSymbol *vehicleResource)
{
  int v4; // edi
  UFG::qPropertySet *PropertySet; // rbx
  signed int v6; // esi
  UFG::qPropertySet *v7; // rax
  char *MemImagePtr; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *mPrev; // rax
  unsigned int *v10; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v11; // rcx
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *mNext; // rax
  TracksEnumBinding<unsigned long> pTrackEnumBinding; // [rsp+28h] [rbp-28h] BYREF

  v4 = 2;
  PropertySet = UFG::PropertySetManager::FindPropertySet(vehicleResource);
  v6 = *UFG::qPropertySet::Get<unsigned long>(
          PropertySet,
          (UFG::qArray<unsigned long,0> *)&qSymbol_SeatCount,
          DEPTH_RECURSE);
  v7 = UFG::qPropertySet::Get<UFG::qPropertySet>(
         PropertySet,
         (UFG::qArray<unsigned long,0> *)&component_VehicleProperties::sPropertyName,
         DEPTH_RECURSE);
  if ( v7 )
    MemImagePtr = UFG::qPropertySet::GetMemImagePtr(v7);
  else
    MemImagePtr = 0i64;
  pTrackEnumBinding.mPrev = &pTrackEnumBinding;
  pTrackEnumBinding.mNext = &pTrackEnumBinding;
  pTrackEnumBinding.m_EnumSymbol.mUID = -1;
  pTrackEnumBinding.m_EnumSymbol.mUID = *((_DWORD *)MemImagePtr + 2);
  *(_QWORD *)&pTrackEnumBinding.m_EnumValue = 0i64;
  pTrackEnumBinding.m_uEnumUID = 0;
  if ( UFG::gSimObjectVehicleTypeTracksEnum.m_enumLists.size )
  {
    TracksEnum<unsigned long>::ResolveBinding(&UFG::gSimObjectVehicleTypeTracksEnum, &pTrackEnumBinding);
  }
  else
  {
    mPrev = UFG::gSimObjectVehicleTypeTracksEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev;
    UFG::gSimObjectVehicleTypeTracksEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev->mNext = &pTrackEnumBinding;
    pTrackEnumBinding.mPrev = mPrev;
    pTrackEnumBinding.mNext = &UFG::gSimObjectVehicleTypeTracksEnum.m_UnresolvedTracksEnumBindingList.mNode;
    UFG::gSimObjectVehicleTypeTracksEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev = &pTrackEnumBinding;
  }
  if ( pTrackEnumBinding.m_EnumValue == 3 )
    v4 = 4;
  v10 = UFG::qPropertySet::Get<unsigned long>(
          pGroupPropertySet,
          (UFG::qArray<unsigned long,0> *)&EncounterSym_num_passengers,
          DEPTH_RECURSE);
  if ( v10 )
  {
    v4 = *v10 + 1;
  }
  else if ( v4 >= v6 )
  {
    v4 = v6;
  }
  v11 = pTrackEnumBinding.mPrev;
  mNext = pTrackEnumBinding.mNext;
  pTrackEnumBinding.mPrev->mNext = pTrackEnumBinding.mNext;
  mNext->mPrev = v11;
  return (unsigned int)v4;
}

// File Line: 2507
// RVA: 0x3F3AE0
char __fastcall UFG::EncounterBase::FillVehicleOccupants(
        UFG::EncounterBase *this,
        UFG::qMatrix44 *pSpawnTransform,
        unsigned int desiredNumOccupants,
        UFG::qPropertySet *pGroupPropertySet,
        UFG::SimObjectVehicle *pVehicle,
        UFG::qSymbol *characterResource)
{
  __int64 v8; // rax
  UFG::EncounterUnitComponent *v9; // rdi
  UFG::SimObjectCVBase *v10; // rbx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *p_mGroupVehicle; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v14; // rax
  UFG::qList<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList,1,0> *p_m_SafePointerList; // r13
  __int16 m_Flags; // cx
  UFG::ActiveAIEntityComponent *ComponentOfTypeHK; // rax
  UFG::GroupComponent *m_pPointer; // rbp
  UFG::eTargetTypeEnum v19; // r14d
  __int64 v20; // rsi
  __int64 v21; // rax
  UFG::EncounterUnitComponent *v22; // rdi
  UFG::SimObjectCVBase *v23; // rbx
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v24; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v25; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v26; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v27; // rax
  __int16 v28; // cx
  UFG::ActiveAIEntityComponent *ComponentOfType; // rax
  UFG::GroupComponent *v30; // rdi
  unsigned int mUID; // edx
  UFG::qBaseTreeRB *v32; // rbx

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
  p_mGroupVehicle = &v9->mGroupVehicle;
  if ( v9->mGroupVehicle.m_pPointer )
  {
    mPrev = p_mGroupVehicle->mPrev;
    mNext = v9->mGroupVehicle.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_mGroupVehicle->mPrev = p_mGroupVehicle;
    v9->mGroupVehicle.mNext = &v9->mGroupVehicle;
  }
  v9->mGroupVehicle.m_pPointer = pVehicle;
  v14 = pVehicle->m_SafePointerList.UFG::SimObjectCVBase::UFG::SimObjectGame::UFG::SimObject::UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev;
  p_m_SafePointerList = &pVehicle->m_SafePointerList;
  v14->mNext = p_mGroupVehicle;
  p_mGroupVehicle->mPrev = v14;
  v9->mGroupVehicle.mNext = &pVehicle->m_SafePointerList.UFG::SimObjectCVBase::UFG::SimObjectGame::UFG::SimObject::UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode;
  pVehicle->m_SafePointerList.UFG::SimObjectCVBase::UFG::SimObjectGame::UFG::SimObject::UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev = p_mGroupVehicle;
  UFG::EncounterUnitComponent::IncrementGroupVehicleUsageCount(v9);
  m_Flags = v10->m_Flags;
  if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
  {
    ComponentOfTypeHK = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>(v10);
  }
  else if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
  {
    ComponentOfTypeHK = (UFG::ActiveAIEntityComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                          v10,
                                                          UFG::ActiveAIEntityComponent::_TypeUID);
  }
  else
  {
    ComponentOfTypeHK = (UFG::ActiveAIEntityComponent *)UFG::SimObject::GetComponentOfType(
                                                          v10,
                                                          UFG::ActiveAIEntityComponent::_TypeUID);
  }
  if ( ComponentOfTypeHK )
    m_pPointer = ComponentOfTypeHK->m_pGroupComponent.m_pPointer;
  else
    m_pPointer = 0i64;
  v19 = eTARGET_TYPE_VEHICLE_PASSENGER;
  if ( desiredNumOccupants > 1 )
  {
    v20 = desiredNumOccupants - 1;
    do
    {
      v21 = ((__int64 (__fastcall *)(UFG::EncounterBase *, _QWORD, UFG::qPropertySet *, UFG::qSymbol *))this->vfptr[67].__vecDelDtor)(
              this,
              0i64,
              pGroupPropertySet,
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
          v24->mPrev = v24;
          v22->mGroupVehicle.mNext = &v22->mGroupVehicle;
        }
        v22->mGroupVehicle.m_pPointer = pVehicle;
        v27 = p_m_SafePointerList->mNode.mPrev;
        v27->mNext = v24;
        v24->mPrev = v27;
        v22->mGroupVehicle.mNext = &p_m_SafePointerList->mNode;
        p_m_SafePointerList->mNode.mPrev = v24;
        UFG::EncounterUnitComponent::IncrementGroupVehicleUsageCount(v22);
        v28 = v23->m_Flags;
        if ( (v28 & 0x4000) != 0 || v28 < 0 )
        {
          ComponentOfType = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>(v23);
        }
        else if ( (v28 & 0x2000) != 0 || (v28 & 0x1000) != 0 )
        {
          ComponentOfType = (UFG::ActiveAIEntityComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                              v23,
                                                              UFG::ActiveAIEntityComponent::_TypeUID);
        }
        else
        {
          ComponentOfType = (UFG::ActiveAIEntityComponent *)UFG::SimObject::GetComponentOfType(
                                                              v23,
                                                              UFG::ActiveAIEntityComponent::_TypeUID);
        }
        if ( ComponentOfType )
          v30 = ComponentOfType->m_pGroupComponent.m_pPointer;
        else
          v30 = 0i64;
        if ( m_pPointer && v30 )
        {
          UFG::PropertySetHandle::Bind(&this->mProperties);
          mUID = UFG::qPropertySet::Get<UFG::qSymbol>(
                   this->mProperties.mpPropSet,
                   (UFG::qArray<unsigned long,0> *)&EncounterSym_group_formation,
                   DEPTH_RECURSE)->mUID;
          if ( mUID )
            v32 = UFG::qBaseTreeRB::Get(&UFG::PedFormationManagerComponent::s_Profiles.mTree, mUID);
          else
            v32 = 0i64;
          if ( !UFG::GroupComponent::JoinExistingGroup(v30, m_pPointer, (UFG::PedFormationProfile *)v32) )
            UFG::GroupComponent::JoinNewGroup(v30, m_pPointer, (UFG::PedFormationProfile *)v32);
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
float __fastcall UFG::EncounterBase::GetHeatRadius(
        UFG::EncounterBase *this,
        __int64 isOnfoot,
        UFG::EncounterUnitComponent *pEncounterUnitComponent)
{
  char v3; // si
  float v5; // xmm6_4
  UFG::qStaticSymbol *v6; // rdx

  v3 = isOnfoot;
  if ( this->mInstantCooldownActive )
  {
    v5 = 0.0;
  }
  else
  {
    UFG::PropertySetHandle::Bind(&this->mProperties);
    v6 = &EncounterSym_heat_radius_vehicle;
    if ( v3 )
      v6 = &EncounterSym_heat_radius_onfoot;
    v5 = *UFG::qPropertySet::Get<float>(this->mProperties.mpPropSet, (UFG::qArray<unsigned long,0> *)v6, DEPTH_RECURSE);
  }
  if ( ((unsigned __int8 (__fastcall *)(UFG::EncounterBase *, __int64, UFG::EncounterUnitComponent *))this->vfptr[16].__vecDelDtor)(
         this,
         isOnfoot,
         pEncounterUnitComponent) )
  {
    return v5 * this->mReducedRadiusPercentage;
  }
  return v5;
}

// File Line: 2587
// RVA: 0x3F96A0
void __fastcall UFG::EncounterBase::SetSecondaryTarget(UFG::EncounterBase *this, UFG::SimObject *pTarget)
{
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *p_mpSecondaryTarget; // r9
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mPrev; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::SimObjectGame *mpVehicle; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v10; // rdx
  UFG::SimObject *m_pPointer; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *p_mNext; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v13; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v14; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v15; // rax

  if ( this->mpSecondaryTarget.m_pPointer != pTarget )
  {
    p_mpSecondaryTarget = &this->mpSecondaryTarget;
    if ( this->mpSecondaryTarget.m_pPointer )
    {
      mPrev = p_mpSecondaryTarget->mPrev;
      mNext = this->mpSecondaryTarget.mNext;
      mPrev->mNext = mNext;
      mNext->mPrev = mPrev;
      p_mpSecondaryTarget->mPrev = p_mpSecondaryTarget;
      this->mpSecondaryTarget.mNext = &this->mpSecondaryTarget;
    }
    this->mpSecondaryTarget.m_pPointer = pTarget;
    if ( pTarget )
    {
      v6 = pTarget->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev;
      v6->mNext = p_mpSecondaryTarget;
      p_mpSecondaryTarget->mPrev = v6;
      this->mpSecondaryTarget.mNext = &pTarget->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode;
      pTarget->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev = p_mpSecondaryTarget;
    }
    mpVehicle = (UFG::SimObjectGame *)this->mFocusTargetContext.mpVehicle;
    if ( mpVehicle )
    {
      m_Flags = mpVehicle->m_Flags;
      if ( (m_Flags & 0x4000) != 0 )
      {
        m_pComponent = mpVehicle->m_Components.p[24].m_pComponent;
      }
      else if ( m_Flags >= 0 )
      {
        m_pComponent = (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
                     ? UFG::SimObjectGame::GetComponentOfTypeHK(mpVehicle, UFG::RoadSpaceComponent::_TypeUID)
                     : UFG::SimObject::GetComponentOfType(mpVehicle, UFG::RoadSpaceComponent::_TypeUID);
      }
      else
      {
        m_pComponent = mpVehicle->m_Components.p[24].m_pComponent;
      }
      if ( m_pComponent )
      {
        v10 = m_pComponent[26].m_BoundComponentHandles.mNode.mPrev;
        if ( v10 )
        {
          m_pPointer = this->mpSecondaryTarget.m_pPointer;
          p_mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v10[1].mNext;
          if ( p_mNext[1].mPrev )
          {
            v13 = p_mNext->mPrev;
            v14 = p_mNext->mNext;
            v13->mNext = v14;
            v14->mPrev = v13;
            p_mNext->mPrev = p_mNext;
            p_mNext->mNext = p_mNext;
          }
          p_mNext[1].mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)m_pPointer;
          if ( m_pPointer )
          {
            v15 = m_pPointer->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev;
            v15->mNext = p_mNext;
            p_mNext->mPrev = v15;
            p_mNext->mNext = &m_pPointer->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode;
            m_pPointer->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev = p_mNext;
          }
        }
      }
    }
  }
}

// File Line: 2605
// RVA: 0x3FC290
void __fastcall UFG::EncounterBase::VisualizeNearByRoads(
        UFG::EncounterBase *this,
        UFG::qPropertySet *pProperties,
        UFG::TransformNodeComponent *pTargetTransform)
{
  char v3; // [rsp+30h] [rbp-58h]
  __int64 v4; // [rsp+40h] [rbp-48h] BYREF
  __int64 v5; // [rsp+90h] [rbp+8h] BYREF

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
  const char *v2; // rdx
  const char *v3; // rdx
  Render::DebugDrawContext *Context; // rbx
  UFG::qString v5; // [rsp+38h] [rbp-60h] BYREF
  UFG::qString v6; // [rsp+60h] [rbp-38h] BYREF

  v2 = "on land";
  if ( this->mFocusTargetContext.mIsInWater )
    v2 = "in open water";
  UFG::qString::qString(&v6, v2);
  v3 = "outside";
  if ( this->mFocusTargetContext.mIsInsideInterior )
    v3 = "inside";
  UFG::qString::qString(&v5, v3);
  Context = (Render::DebugDrawContext *)Render::DebugDrawManager::GetContext(Render::DebugDrawManager::mInstance, 1u);
  Render::DebugDrawContext::DrawTextA(Context, 60, 300, &UFG::qColour::Green, "(Player is %s)", v6.mData);
  Render::DebugDrawContext::DrawTextA(Context, 60, 315, &UFG::qColour::Green, "(Player is %s)", v5.mData);
  UFG::qString::~qString(&v5);
  UFG::qString::~qString(&v6);
}

// File Line: 2622
// RVA: 0x3FC2D0
void __fastcall UFG::EncounterBase::VisualizeRoles(UFG::EncounterBase *this)
{
  Render::DebugDrawContext *Context; // r14
  unsigned int i; // edi
  UFG::EncounterUnitComponent *v4; // rbp
  UFG::SimObjectCVBase *m_pSimObject; // rcx
  __int16 m_Flags; // dx
  UFG::ActiveAIEntityComponent *v7; // rax
  UFG::GroupComponent *m_pPointer; // rbx
  bool v9; // bp
  UFG::GroupComponent *SharedGroupComponent; // rax
  UFG::qColour *v11; // r9
  float v12; // xmm2_4
  UFG::qColour *v13; // r9
  UFG::qVector3 result; // [rsp+40h] [rbp-68h] BYREF
  UFG::qVector3 p0; // [rsp+50h] [rbp-58h] BYREF

  Context = (Render::DebugDrawContext *)Render::DebugDrawManager::GetContext(Render::DebugDrawManager::mInstance, 2u);
  for ( i = 0; i < this->mHumans.size; ++i )
  {
    v4 = this->mHumans.p[i];
    m_pSimObject = (UFG::SimObjectCVBase *)v4->m_pSimObject;
    if ( m_pSimObject )
    {
      m_Flags = m_pSimObject->m_Flags;
      if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
        v7 = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>(m_pSimObject);
      else
        v7 = (UFG::ActiveAIEntityComponent *)((m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
                                            ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                m_pSimObject,
                                                UFG::ActiveAIEntityComponent::_TypeUID)
                                            : UFG::SimObject::GetComponentOfType(
                                                m_pSimObject,
                                                UFG::ActiveAIEntityComponent::_TypeUID));
      if ( v7 )
      {
        m_pPointer = v7->m_pGroupComponent.m_pPointer;
        if ( m_pPointer )
        {
          UFG::GroupComponent::GetPosition(v7->m_pGroupComponent.m_pPointer, &result);
          v9 = v4->mRole == eENCOUNTER_ROLE_ENFORCER;
          result.z = result.z + 0.5;
          SharedGroupComponent = UFG::GroupComponent::GetSharedGroupComponent(m_pPointer);
          if ( SharedGroupComponent == m_pPointer )
          {
            v11 = &UFG::qColour::Blue;
            v12 = FLOAT_0_5;
            if ( v9 )
              v11 = &UFG::qColour::ForestGreen;
          }
          else
          {
            UFG::GroupComponent::GetPosition(SharedGroupComponent, &p0);
            p0.z = p0.z + 0.5;
            Render::DebugDrawContext::DrawLine(
              Context,
              &p0,
              &result,
              &UFG::qColour::Yellow,
              &UFG::qMatrix44::msIdentity,
              0i64,
              0);
            v12 = FLOAT_0_30000001;
            v11 = &UFG::qColour::Yellow;
          }
          Render::DebugDrawContext::DrawSphere(Context, &result, v12, v11, &UFG::qMatrix44::msIdentity, 0i64);
          v13 = &UFG::qColour::Yellow;
          if ( v9 )
            v13 = &UFG::qColour::ForestGreen;
          Render::DebugDrawContext::DrawLine(
            Context,
            &this->mFocusTargetPosition,
            &result,
            v13,
            &UFG::qMatrix44::msIdentity,
            0i64,
            0);
        }
      }
    }
  }
}

// File Line: 2656
// RVA: 0x3FB920
__int64 __fastcall UFG::EncounterBase::VisualizeEncounterUnitsInfo(UFG::EncounterBase *this, int x, int startY)
{
  int v3; // r12d
  int v4; // r13d
  Render::DebugDrawContext *Context; // rsi
  int v7; // ebp
  UFG::qPropertySet *v8; // r15
  const char *v9; // rsi
  const char *v10; // rdi
  int v11; // ebx
  int v12; // eax
  const char *v13; // rdx
  int v14; // eax
  double v15; // xmm2_8
  const char *v16; // rcx
  const char *v17; // rax
  unsigned int v18; // r12d
  unsigned int v19; // ebx
  UFG::qColour *v20; // rdi
  const char *v21; // rcx
  int v22; // ebp
  __int64 v23; // rax
  UFG::EncounterUnitComponent *v24; // rsi
  UFG::SimObject *m_pSimObject; // rbx
  char *v26; // rax
  char v27; // r15
  UFG::SimObjectCVBase *v28; // rcx
  UFG::ActiveAIEntityComponent *v29; // rax
  __int16 m_Flags; // dx
  __int64 m_CurrentObjective; // r13
  float v32; // xmm8_4
  float v33; // xmm7_4
  __int16 v34; // cx
  UFG::AiDriverComponent *ComponentOfTypeHK; // rax
  __int16 v36; // cx
  UFG::SimComponent *m_pComponent; // rax
  float v38; // xmm6_4
  UFG::qColour *v39; // rdi
  char *mData; // rbx
  double v41; // xmm6_8
  double v42; // xmm7_8
  double v43; // xmm8_8
  char *v44; // rax
  int v45; // r10d
  UFG::EncounterUnitComponent *v46; // rsi
  UFG::qSymbolUC *v47; // rbx
  char *v48; // rax
  char v49; // r15
  UFG::qColour *v50; // rdi
  char *v51; // rbx
  double mVehicleFlipTimer; // xmm6_8
  char *v53; // rax
  int v54; // r8d
  __int64 v56; // [rsp+28h] [rbp-120h]
  const char *v57; // [rsp+28h] [rbp-120h]
  __int64 v58; // [rsp+30h] [rbp-118h]
  __int64 v59; // [rsp+30h] [rbp-118h]
  __int64 v60; // [rsp+30h] [rbp-118h]
  __int64 v61; // [rsp+38h] [rbp-110h]
  __int64 v62; // [rsp+38h] [rbp-110h]
  const char *v63; // [rsp+40h] [rbp-108h]
  __int64 v64; // [rsp+48h] [rbp-100h]
  Render::DebugDrawContext *v65; // [rsp+70h] [rbp-D8h]
  UFG::qString v66; // [rsp+80h] [rbp-C8h] BYREF
  int v69; // [rsp+168h] [rbp+20h]

  v3 = startY;
  v4 = x;
  Context = (Render::DebugDrawContext *)Render::DebugDrawManager::GetContext(Render::DebugDrawManager::mInstance, 1u);
  v65 = Context;
  v7 = v3;
  if ( UFG::EncounterBase::sVisualizeWavesInfo )
  {
    v8 = (UFG::qPropertySet *)((__int64 (__fastcall *)(UFG::EncounterBase *))this->vfptr[33].__vecDelDtor)(this);
    if ( v8 )
    {
      v9 = "No";
      v10 = "No";
      if ( this->mIsReplenishing )
        v10 = "Yes";
      v11 = (int)this->vfptr[36].__vecDelDtor(this, v8);
      v12 = (int)this->vfptr[35].__vecDelDtor(this, v8);
      v13 = "By Wave";
      if ( this->mReplenishStyle == ReplenishStyle_TopUpByPopulation )
        v13 = "By Population";
      Render::DebugDrawContext::DrawTextA(
        v65,
        v4,
        v3,
        &UFG::qColour::White,
        "Style:%15s  DesiredVehicleGroups:%d/%d  DesiredFootGroups:%d/%d  IsReplenishing:%s",
        v13,
        v12,
        this->mNumDesiredVehicleGroups,
        v11,
        this->mNumDesiredCharacterGroups,
        v10);
      v14 = ((__int64 (__fastcall *)(UFG::EncounterBase *))this->vfptr[31].__vecDelDtor)(this);
      LODWORD(v62) = this->mCharacterKillCount;
      LODWORD(v59) = this->mVehicleKillCount;
      LODWORD(v56) = v14;
      Render::DebugDrawContext::DrawTextA(
        v65,
        v4,
        v3 + 10,
        &UFG::qColour::White,
        "KillCount:%d (Vehicles:%d, Characters:%d)",
        v56,
        v59,
        v62);
      v15 = *UFG::qPropertySet::Get<float>(
               v8,
               (UFG::qArray<unsigned long,0> *)&EncounterSym_cooldown_timer,
               DEPTH_RECURSE);
      v16 = "No";
      if ( this->mCoolingDown )
        v16 = "Yes";
      v17 = "No";
      if ( this->mCooldownAllowed )
        v17 = "Yes";
      if ( this->mInstantCooldownActive )
        v9 = "Yes";
      v57 = v9;
      Context = v65;
      Render::DebugDrawContext::DrawTextA(
        v65,
        v4,
        v3 + 20,
        &UFG::qColour::White,
        "InstantCooldownActive:%s  IsCoolDownAllowed:%s  IsCoolingDown:%s (%.2f/%.2f)",
        v57,
        v17,
        v16,
        (float)(UFG::Metrics::msInstance.mSimTime_Temp - this->mNonEventfulCooldownTimestamp),
        v15);
      v7 = v3 + 30;
    }
    v18 = 0;
    v19 = 0;
    if ( this->mNumWaveGroupTypes )
    {
      v20 = &UFG::qColour::White;
      if ( this->mWaveGroupInstances >= this->mWaveGroupInstancesRequired )
        v20 = &UFG::qColour::Green;
      do
      {
        v21 = "CharacterGroup";
        if ( this->mWaveGroupTypes[v19] == F3_1Pt44_512 )
          v21 = "VehicleGroup";
        LODWORD(v61) = this->mWaveGroupInstancesRequired[v19];
        LODWORD(v58) = this->mWaveGroupInstances[v19];
        Render::DebugDrawContext::DrawTextA(Context, v4, v7, v20, "Type:%s  Instances:%d/%d", v21, v58, v61);
        v7 += 10;
        ++v19;
      }
      while ( v19 < this->mNumWaveGroupTypes );
      v18 = 0;
    }
    Render::DebugDrawContext::DrawTextA(
      Context,
      v4,
      v7,
      &UFG::qColour::White,
      "%20s - Type  Role  Engaged   %35s  [Ref]WaveType  FlipTimer",
      "Name",
      "Objective");
    v22 = v7 + 10;
    v23 = 0i64;
    v69 = 0;
    if ( this->mHumans.size )
    {
      while ( 1 )
      {
        v24 = this->mHumans.p[v23];
        m_pSimObject = v24->m_pSimObject;
        UFG::qString::qString(&v66);
        v26 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&m_pSimObject->m_Name);
        UFG::qString::Format(&v66, "%20s", v26);
        UFG::qString::operator+=(&v66, " - Char");
        if ( v24->mRole == eENCOUNTER_ROLE_ENFORCER )
          v27 = 69;
        else
          v27 = v24->mRole == eENCOUNTER_ROLE_SUPPORTER ? 83 : 78;
        v28 = (UFG::SimObjectCVBase *)v24->m_pSimObject;
        if ( v28 )
        {
          m_Flags = v28->m_Flags;
          if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
            v29 = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>(v28);
          else
            v29 = (UFG::ActiveAIEntityComponent *)((m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
                                                 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                     v28,
                                                     UFG::ActiveAIEntityComponent::_TypeUID)
                                                 : UFG::SimObject::GetComponentOfType(
                                                     v28,
                                                     UFG::ActiveAIEntityComponent::_TypeUID));
        }
        else
        {
          v29 = 0i64;
        }
        m_CurrentObjective = v29->m_CurrentObjective;
        v32 = FLOAT_N1_0;
        v33 = FLOAT_N1_0;
        if ( !m_pSimObject )
          break;
        v34 = m_pSimObject->m_Flags;
        if ( (v34 & 0x4000) != 0 || v34 < 0 )
        {
          ComponentOfTypeHK = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>((UFG::SimObjectCVBase *)m_pSimObject);
        }
        else if ( (v34 & 0x2000) != 0 || (v34 & 0x1000) != 0 )
        {
          ComponentOfTypeHK = (UFG::AiDriverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                          (UFG::SimObjectGame *)m_pSimObject,
                                                          UFG::AiDriverComponent::_TypeUID);
        }
        else
        {
          ComponentOfTypeHK = (UFG::AiDriverComponent *)UFG::SimObject::GetComponentOfType(
                                                          m_pSimObject,
                                                          UFG::AiDriverComponent::_TypeUID);
        }
        if ( ComponentOfTypeHK )
          v32 = ComponentOfTypeHK->m_fDesiredSpeed * 3.5999999;
        v36 = m_pSimObject->m_Flags;
        if ( (v36 & 0x4000) != 0 )
          break;
        if ( v36 >= 0 )
        {
          if ( (v36 & 0x2000) != 0 )
            break;
          m_pComponent = (v36 & 0x1000) != 0
                       ? UFG::SimObjectGame::GetComponentOfTypeHK(
                           (UFG::SimObjectGame *)m_pSimObject,
                           UFG::PhysicsMoverInterface::_TypeUID)
                       : UFG::SimObject::GetComponentOfType(m_pSimObject, UFG::PhysicsMoverInterface::_TypeUID);
        }
        else
        {
          m_pComponent = m_pSimObject->m_Components.p[34].m_pComponent;
        }
        if ( !m_pComponent )
          break;
        v33 = *((float *)&m_pComponent[10].m_BoundComponentHandles.mNode.mPrev + 1) * 3.5999999;
        if ( v33 <= 0.0 )
          break;
        v38 = v33 / v32;
LABEL_57:
        v39 = &UFG::qColour::White;
        if ( *(_DWORD *)((__int64 (__fastcall *)(UFG::EncounterBase *))this->vfptr[26].__vecDelDtor)(this) == v24->mWaveType.mUID )
          v39 = &UFG::qColour::Yellow;
        mData = v66.mData;
        v41 = v38;
        v42 = v33;
        v43 = v32;
        v44 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&v24->mWaveType);
        v45 = 78;
        if ( v24->mEngaged )
          v45 = 89;
        LODWORD(v64) = v24->mUsageCount;
        v63 = UFG::AIObjectiveNames[m_CurrentObjective];
        LODWORD(v61) = v45;
        LODWORD(v60) = v27;
        v4 = x;
        Render::DebugDrawContext::DrawTextA(
          v65,
          x,
          v22,
          v39,
          "%s  %c      %c        %35s  [%3d]%s  %03.2f   %03.2f   %03.2f",
          mData,
          v60,
          v61,
          v63,
          v64,
          v44,
          v43,
          v42,
          v41);
        v22 += 10;
        UFG::qString::~qString(&v66);
        v23 = (unsigned int)(v69 + 1);
        v69 = v23;
        if ( (unsigned int)v23 >= this->mHumans.size )
          goto LABEL_62;
      }
      v38 = 0.0;
      goto LABEL_57;
    }
LABEL_62:
    if ( this->mVehicles.size )
    {
      do
      {
        v46 = this->mVehicles.p[v18];
        v47 = (UFG::qSymbolUC *)v46->m_pSimObject;
        UFG::qString::qString(&v66);
        v48 = UFG::qSymbol::as_cstr_dbg(v47 + 18);
        UFG::qString::Format(&v66, "%20s", v48);
        UFG::qString::operator+=(&v66, " - Vehi");
        if ( v46->mRole == eENCOUNTER_ROLE_ENFORCER )
        {
          v49 = 69;
        }
        else if ( v46->mRole == eENCOUNTER_ROLE_SUPPORTER )
        {
          v49 = 83;
        }
        else
        {
          v49 = 78;
        }
        v50 = &UFG::qColour::White;
        if ( *(_DWORD *)((__int64 (__fastcall *)(UFG::EncounterBase *))this->vfptr[26].__vecDelDtor)(this) == v46->mWaveType.mUID )
          v50 = &UFG::qColour::Yellow;
        v51 = v66.mData;
        mVehicleFlipTimer = v46->mVehicleFlipTimer;
        v53 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&v46->mWaveType);
        v54 = 78;
        if ( v46->mEngaged )
          v54 = 89;
        LODWORD(v64) = v46->mUsageCount;
        LODWORD(v61) = v54;
        LODWORD(v60) = v49;
        Render::DebugDrawContext::DrawTextA(
          v65,
          v4,
          v22,
          v50,
          "%s  %c      %c        %35s  [%3d]%s  %.2f",
          v51,
          v60,
          v61,
          &customCaption,
          v64,
          v53,
          mVehicleFlipTimer);
        v22 += 10;
        UFG::qString::~qString(&v66);
        ++v18;
      }
      while ( v18 < this->mVehicles.size );
    }
    v7 = v22 + 20;
    v3 = startY;
  }
  return (unsigned int)(v7 - v3);
}

// File Line: 2810
// RVA: 0x3F9A10
void __fastcall UFG::EncounterBase::Update(UFG::EncounterBase *this, float deltaTime)
{
  __int64 v4; // rax
  __int64 v5; // rdi
  UFG::qVector3 *v6; // rdi
  float y; // xmm0_4
  float z; // xmm1_4
  UFG::qSafePointerNode<UFG::EncounterBase>Vtbl *vfptr; // rax
  UFG::SimObject *v10; // rax

  UFG::OnlineManager::Instance();
  v4 = ((__int64 (__fastcall *)(UFG::EncounterBase *))this->vfptr[18].__vecDelDtor)(this);
  if ( v4 && (v5 = *(_QWORD *)(v4 + 88)) != 0 )
  {
    UFG::TransformNodeComponent::UpdateWorldTransform(*(UFG::TransformNodeComponent **)(v4 + 88));
    v6 = (UFG::qVector3 *)(v5 + 176);
  }
  else
  {
    v6 = &UFG::qVector3::msZero;
  }
  y = v6->y;
  z = v6->z;
  this->mFocusTargetPosition.x = v6->x;
  vfptr = this->vfptr;
  this->mFocusTargetPosition.y = y;
  this->mFocusTargetPosition.z = z;
  v10 = (UFG::SimObject *)((__int64 (__fastcall *)(UFG::EncounterBase *))vfptr[18].__vecDelDtor)(this);
  UFG::EncounterUnitContext::Update(&this->mFocusTargetContext, v10, deltaTime);
  ((void (__fastcall *)(UFG::EncounterBase *))this->vfptr[38].__vecDelDtor)(this);
  ((void (__fastcall *)(UFG::EncounterBase *))this->vfptr[40].__vecDelDtor)(this);
  ((void (__fastcall *)(UFG::EncounterBase *))this->vfptr[39].__vecDelDtor)(this);
  ((void (__fastcall *)(UFG::EncounterBase *))this->vfptr[76].__vecDelDtor)(this);
  ((void (__fastcall *)(UFG::EncounterBase *))this->vfptr[41].__vecDelDtor)(this);
  ((void (__fastcall *)(UFG::EncounterBase *))this->vfptr[83].__vecDelDtor)(this);
}

// File Line: 2842
// RVA: 0x3F36D0
void __fastcall UFG::EncounterBase::CountInsideRadiusObjects(UFG::EncounterBase *this)
{
  __int64 v1; // r15
  unsigned int i; // r12d
  UFG::EncounterUnitComponent *v4; // rsi
  UFG::SimObjectGame *m_pSimObject; // rcx
  __int64 m_Flags; // rdx
  UFG::SimComponent *m_pComponent; // rcx
  UFG::SimComponent *v8; // rax
  double v9; // xmm0_8
  UFG::SimObject *v10; // rax
  float v11; // xmm6_4
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // r14
  unsigned int j; // edi
  UFG::EncounterUnitComponent *v14; // rcx
  UFG::SimObject *v15; // rax
  UFG::TransformNodeComponent *v16; // rbp
  UFG::EncounterUnitComponent *v17; // rdi
  double v18; // xmm0_8
  UFG::SimObject *v19; // rsi
  UFG::TransformNodeComponent *v20; // rsi
  float v21; // xmm1_4

  v1 = 0i64;
  this->mInsideDynamicRadiusCount = 0;
  for ( i = 0; i < this->mHumans.size; ++i )
  {
    v4 = this->mHumans.p[i];
    m_pSimObject = (UFG::SimObjectGame *)v4->m_pSimObject;
    if ( m_pSimObject )
    {
      m_Flags = m_pSimObject->m_Flags;
      if ( (m_Flags & 0x4000) != 0 )
      {
        m_pComponent = m_pSimObject->m_Components.p[44].m_pComponent;
      }
      else
      {
        v8 = (m_Flags & 0x8000u) != 0i64 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
           ? UFG::SimObjectGame::GetComponentOfTypeHK(m_pSimObject, UFG::CharacterOccupantComponent::_TypeUID)
           : UFG::SimObject::GetComponentOfType(m_pSimObject, UFG::CharacterOccupantComponent::_TypeUID);
        m_pComponent = v8;
      }
      LOBYTE(m_Flags) = m_pComponent == 0i64;
      v9 = ((double (__fastcall *)(UFG::EncounterBase *, __int64, UFG::EncounterUnitComponent *))this->vfptr[17].__vecDelDtor)(
             this,
             m_Flags,
             v4);
      v10 = v4->m_pSimObject;
      v11 = *(float *)&v9 * *(float *)&v9;
      if ( v10 )
      {
        m_pTransformNodeComponent = v10->m_pTransformNodeComponent;
        if ( m_pTransformNodeComponent )
        {
          UFG::TransformNodeComponent::UpdateWorldTransform(v10->m_pTransformNodeComponent);
          if ( (float)((float)((float)(this->mFocusTargetPosition.y - m_pTransformNodeComponent->mWorldTransform.v3.y)
                             * (float)(this->mFocusTargetPosition.y - m_pTransformNodeComponent->mWorldTransform.v3.y))
                     + (float)((float)(this->mFocusTargetPosition.x - m_pTransformNodeComponent->mWorldTransform.v3.x)
                             * (float)(this->mFocusTargetPosition.x - m_pTransformNodeComponent->mWorldTransform.v3.x))) < v11 )
          {
            if ( v4->mInsideRadiusTimer < 0.0 )
              v4->mInsideRadiusTimer = v4->mAcquiredTimer;
            ++this->mInsideDynamicRadiusCount;
            v4->mEngaged = 1;
          }
          if ( v4->mInsideRadiusTimer < 0.0 )
          {
            for ( j = 0; j < this->mVehicles.size; ++j )
            {
              v14 = this->mVehicles.p[j];
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
                      if ( (float)((float)((float)(m_pTransformNodeComponent->mWorldTransform.v3.y
                                                 - v16->mWorldTransform.v3.y)
                                         * (float)(m_pTransformNodeComponent->mWorldTransform.v3.y
                                                 - v16->mWorldTransform.v3.y))
                                 + (float)((float)(m_pTransformNodeComponent->mWorldTransform.v3.x
                                                 - v16->mWorldTransform.v3.x)
                                         * (float)(m_pTransformNodeComponent->mWorldTransform.v3.x
                                                 - v16->mWorldTransform.v3.x))) < v11 )
                        v4->mInsideRadiusTimer = v4->mAcquiredTimer;
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
  if ( this->mVehicles.size )
  {
    do
    {
      v17 = this->mVehicles.p[v1];
      if ( v17->m_pSimObject )
      {
        v18 = ((double (__fastcall *)(UFG::EncounterBase *, _QWORD, UFG::EncounterUnitComponent *))this->vfptr[17].__vecDelDtor)(
                this,
                0i64,
                this->mVehicles.p[v1]);
        v19 = v17->m_pSimObject;
        if ( v19 )
        {
          v20 = v19->m_pTransformNodeComponent;
          if ( v20 )
          {
            UFG::TransformNodeComponent::UpdateWorldTransform(v20);
            v21 = (float)((float)(this->mFocusTargetPosition.y - v20->mWorldTransform.v3.y)
                        * (float)(this->mFocusTargetPosition.y - v20->mWorldTransform.v3.y))
                + (float)((float)(this->mFocusTargetPosition.x - v20->mWorldTransform.v3.x)
                        * (float)(this->mFocusTargetPosition.x - v20->mWorldTransform.v3.x));
            if ( v21 < (float)(*(float *)&v18 * *(float *)&v18) )
            {
              if ( v17->mInsideRadiusTimer < 0.0 )
                v17->mInsideRadiusTimer = v17->mAcquiredTimer;
              if ( v21 < 900.0 )
                v17->mEngaged = 1;
            }
          }
        }
      }
      v1 = (unsigned int)(v1 + 1);
    }
    while ( (unsigned int)v1 < this->mVehicles.size );
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
  float mReducedRadiusTimer; // xmm0_4
  float v4; // xmm6_4
  float v6; // xmm0_4
  bool v7; // zf
  UFG::qPropertySet *v8; // rax
  float *v9; // rax
  float v10; // xmm0_4
  UFG::qSafePointerNode<UFG::EncounterBase>Vtbl *vfptr; // rax
  UFG::qPropertySet *v12; // rax
  UFG::qPropertySet *v13; // rax
  float mWaveTimer; // xmm0_4
  float v15; // xmm0_4

  mReducedRadiusTimer = this->mReducedRadiusTimer;
  v4 = 0.0;
  this->mCoolingDown = 0;
  v6 = mReducedRadiusTimer - deltaTime;
  if ( v6 <= 0.0 )
    v6 = 0.0;
  v7 = this->mHeatLevel == HEATLEVEL_NONE;
  this->mReducedRadiusTimer = v6;
  if ( !v7 )
  {
    if ( this->mIsReplenishing && this->mReplenishTimeout > 0.0 )
    {
      v8 = (UFG::qPropertySet *)((__int64 (__fastcall *)(UFG::EncounterBase *))this->vfptr[33].__vecDelDtor)(this);
      v9 = UFG::qPropertySet::Get<float>(
             v8,
             (UFG::qArray<unsigned long,0> *)&EncounterSym_heatwave_timer,
             DEPTH_RECURSE);
      v10 = this->mReplenishTimeout - deltaTime;
      this->mWaveTimer = *v9;
      if ( v10 <= 0.0 )
        v10 = 0.0;
      this->mReplenishTimeout = v10;
    }
    else if ( !((unsigned int (__fastcall *)(UFG::EncounterBase *))this->vfptr[32].__vecDelDtor)(this) )
    {
      goto LABEL_11;
    }
    this->mCooldownAllowed = 0;
  }
LABEL_11:
  UFG::PropertySetHandle::Bind(&this->mProperties);
  if ( *UFG::qPropertySet::Get<bool>(
          this->mProperties.mpPropSet,
          (UFG::qArray<unsigned long,0> *)&EncounterSym_show_blip_radius,
          DEPTH_RECURSE) )
  {
    if ( this->mCooldownAllowed )
    {
      this->mCoolingDown = 1;
    }
    else
    {
      vfptr = this->vfptr;
      this->mCooldownAllowed = 1;
      v12 = (UFG::qPropertySet *)((__int64 (__fastcall *)(UFG::EncounterBase *))vfptr[33].__vecDelDtor)(this);
      this->mNonEventfulCooldownTimestamp = UFG::Metrics::msInstance.mSimTime_Temp
                                          + *UFG::qPropertySet::Get<float>(
                                               v12,
                                               (UFG::qArray<unsigned long,0> *)&EncounterSym_cooldown_timer,
                                               DEPTH_RECURSE);
    }
  }
  else
  {
    this->mCooldownAllowed = 0;
  }
  if ( this->mInstantCooldownActive )
    *(_WORD *)&this->mCoolingDown = 257;
  if ( this->mCooldownAllowed && this->mCoolingDown && currentTime > this->mNonEventfulCooldownTimestamp )
  {
    this->mHeatLevel = HEATLEVEL_NONE;
    this->mStartTimestamp = UFG::Metrics::msInstance.mSimTimeMSec;
    v13 = (UFG::qPropertySet *)((__int64 (__fastcall *)(UFG::EncounterBase *))this->vfptr[33].__vecDelDtor)(this);
    if ( v13 )
      v4 = *UFG::qPropertySet::Get<float>(
              v13,
              (UFG::qArray<unsigned long,0> *)&EncounterSym_cooldown_timer,
              DEPTH_RECURSE);
    this->mNonEventfulCooldownTimestamp = UFG::Metrics::msInstance.mSimTime_Temp + v4;
  }
  else if ( !this->mIsReplenishing )
  {
    mWaveTimer = this->mWaveTimer;
    if ( mWaveTimer != -1.0 )
    {
      v15 = mWaveTimer - deltaTime;
      this->mWaveTimer = v15;
      if ( v15 <= 0.0 )
        ((void (__fastcall *)(UFG::EncounterBase *))this->vfptr[23].__vecDelDtor)(this);
    }
  }
}

// File Line: 3037
// RVA: 0x3F7EE0
bool __fastcall UFG::EncounterBase::IsAlive(
        UFG::EncounterBase *this,
        UFG::EncounterUnitComponent *pEncounterUnitComponent)
{
  UFG::SimObjectGame *m_pSimObject; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rax
  bool result; // al

  m_pSimObject = (UFG::SimObjectGame *)pEncounterUnitComponent->m_pSimObject;
  result = 0;
  if ( m_pSimObject )
  {
    m_Flags = m_pSimObject->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = m_pSimObject->m_Components.p[6].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      m_pComponent = (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
                   ? UFG::SimObjectGame::GetComponentOfTypeHK(m_pSimObject, UFG::HealthComponent::_TypeUID)
                   : UFG::SimObject::GetComponentOfType(m_pSimObject, UFG::HealthComponent::_TypeUID);
    }
    else
    {
      m_pComponent = m_pSimObject->m_Components.p[6].m_pComponent;
    }
    if ( m_pComponent && !BYTE4(m_pComponent[1].m_BoundComponentHandles.mNode.mPrev) )
      return 1;
  }
  return result;
}

// File Line: 3047
// RVA: 0x3F8530
char __fastcall UFG::EncounterBase::IsInFight(
        UFG::EncounterBase *this,
        UFG::EncounterUnitComponent *pEncounterUnitComponent)
{
  UFG::SimObjectGame *m_pSimObject; // rcx
  __int16 m_Flags; // r8
  UFG::PhysicsMoverInterface *m_pComponent; // rsi
  UFG::SimComponent *v7; // rax
  int mNumWheels; // r14d
  int v10; // ebp
  int i; // edi
  bool IsTireBlown; // al
  UFG::SimObjectGame *v13; // rcx
  UFG::SimComponent *v14; // rbx
  __int16 v15; // dx
  UFG::SimComponent *ComponentOfTypeHK; // rax

  m_pSimObject = (UFG::SimObjectGame *)pEncounterUnitComponent->m_pSimObject;
  if ( !m_pSimObject )
    goto LABEL_22;
  m_Flags = m_pSimObject->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
    goto LABEL_22;
  if ( m_Flags >= 0 )
  {
    if ( (m_Flags & 0x2000) != 0 )
      goto LABEL_22;
    v7 = (m_Flags & 0x1000) != 0
       ? UFG::SimObjectGame::GetComponentOfTypeHK(m_pSimObject, UFG::PhysicsMoverInterface::_TypeUID)
       : UFG::SimObject::GetComponentOfType(m_pSimObject, UFG::PhysicsMoverInterface::_TypeUID);
    m_pComponent = (UFG::PhysicsMoverInterface *)v7;
  }
  else
  {
    m_pComponent = (UFG::PhysicsMoverInterface *)m_pSimObject->m_Components.p[34].m_pComponent;
  }
  if ( !m_pComponent )
  {
LABEL_22:
    v13 = (UFG::SimObjectGame *)pEncounterUnitComponent->m_pSimObject;
    if ( v13 )
    {
      v15 = v13->m_Flags;
      if ( (v15 & 0x4000) != 0 )
      {
        v14 = v13->m_Components.p[5].m_pComponent;
      }
      else if ( v15 >= 0 )
      {
        if ( (v15 & 0x2000) != 0 || (v15 & 0x1000) != 0 )
          ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(v13, UFG::AIScriptInterfaceComponent::_TypeUID);
        else
          ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(v13, UFG::AIScriptInterfaceComponent::_TypeUID);
        v14 = ComponentOfTypeHK;
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
    return this->vfptr[77].__vecDelDtor(this, pEncounterUnitComponent)
        && v14
        && ((__int64)v14[32].m_BoundComponentHandles.mNode.mPrev & 0x20) == 0;
  }
  if ( pEncounterUnitComponent->mVehicleFlipTimer >= 2.0 || pEncounterUnitComponent->mUnitDisabled )
    return 0;
  mNumWheels = m_pComponent->mNumWheels;
  if ( !mNumWheels )
    return 1;
  v10 = 0;
  for ( i = 0; i < mNumWheels; v10 += IsTireBlown )
    IsTireBlown = UFG::PhysicsMoverInterface::IsTireBlown(m_pComponent, i++);
  return v10 < mNumWheels / 2
      && (v10 < 1 || UFG::PhysicsMoverInterface::GetLinearVelocityMagnitudeKPH(m_pComponent) > 40.0);
}

// File Line: 3109
// RVA: 0x3F8D60
bool __fastcall UFG::EncounterBase::IsVisible(
        UFG::EncounterBase *this,
        UFG::EncounterUnitComponent *pEncounterUnitComponent)
{
  UFG::SimObject *m_pSimObject; // rbx
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rbx
  bool result; // al

  m_pSimObject = pEncounterUnitComponent->m_pSimObject;
  result = 0;
  if ( m_pSimObject )
  {
    m_pTransformNodeComponent = m_pSimObject->m_pTransformNodeComponent;
    if ( m_pTransformNodeComponent )
    {
      UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
      if ( UFG::SimObjectUtility::IsPositionOnScreen(
             (UFG::qVector3 *)&m_pTransformNodeComponent->mWorldTransform.v3,
             2.0,
             0) )
      {
        return 1;
      }
    }
  }
  return result;
}

// File Line: 3119
// RVA: 0x3F9120
void __fastcall UFG::EncounterBase::Replenish(UFG::EncounterBase *this)
{
  __int64 v2; // rax
  UFG::qPropertySet *v3; // rsi
  float v4; // ecx
  float *v5; // rax
  bool v6; // zf
  float v7; // xmm1_4
  float *v8; // rax
  float v9; // xmm1_4

  if ( !this->mIsReplenishing )
  {
    ++this->mWaveCount;
    if ( this->mDisabledUnitForCurrentWave )
      ++this->mWavesDisabledUnitCount;
    *(_WORD *)&this->mHasSpawnedInFrontForCurrentWave = 0;
  }
  v2 = ((__int64 (__fastcall *)(UFG::EncounterBase *))this->vfptr[33].__vecDelDtor)(this);
  this->mIsReplenishing = 1;
  v3 = (UFG::qPropertySet *)v2;
  UFG::PropertySetHandle::Bind(&this->mProperties);
  v4 = *UFG::qPropertySet::Get<float>(
          this->mProperties.mpPropSet,
          (UFG::qArray<unsigned long,0> *)&EncounterSym_replenish_timeout,
          DEPTH_RECURSE);
  this->mSpawnTimeout = 0.0;
  this->mReplenishTimeout = v4;
  v5 = UFG::qPropertySet::Get<float>(v3, (UFG::qArray<unsigned long,0> *)&EncounterSym_heatwave_timer, DEPTH_RECURSE);
  v6 = !this->mEnableWaveTimerChangesByDisabledUnits;
  v7 = *v5;
  this->mWaveTimer = *v5;
  if ( !v6 && v7 >= 0.0 )
  {
    if ( v3
      && (v8 = UFG::qPropertySet::Get<float>(
                 v3,
                 (UFG::qArray<unsigned long,0> *)&EncounterSym_vehicle_kill_bonus_timer,
                 DEPTH_RECURSE)) != 0i64 )
    {
      v9 = *v8;
    }
    else
    {
      v9 = FLOAT_2_0;
    }
    this->mWaveTimer = (float)((float)this->mWavesDisabledUnitCount * v9) + this->mWaveTimer;
  }
}

// File Line: 3150
// RVA: 0x3F8E50
void __fastcall UFG::EncounterBase::OnDetachEncounterUnitComponent(
        UFG::EncounterBase *this,
        UFG::EncounterUnitComponent *pComponent)
{
  unsigned int size; // r10d
  __int64 v3; // r8
  unsigned int v5; // r9d
  UFG::EncounterUnitComponent **p; // rax
  __int64 v7; // rax
  unsigned int v8; // ecx
  UFG::EncounterUnitComponent **i; // rax
  __int64 v10; // rax

  size = this->mHumans.size;
  v3 = 0i64;
  v5 = 0;
  if ( size )
  {
    p = this->mHumans.p;
    while ( *p != pComponent )
    {
      ++v5;
      ++p;
      if ( v5 >= size )
        goto LABEL_7;
    }
    v7 = size - 1;
    this->mHumans.size = v7;
    this->mHumans.p[v5] = this->mHumans.p[v7];
  }
LABEL_7:
  v8 = this->mVehicles.size;
  if ( v8 )
  {
    for ( i = this->mVehicles.p; *i != pComponent; ++i )
    {
      v3 = (unsigned int)(v3 + 1);
      if ( (unsigned int)v3 >= v8 )
        return;
    }
    v10 = v8 - 1;
    this->mVehicles.size = v10;
    this->mVehicles.p[v3] = this->mVehicles.p[v10];
  }
}

// File Line: 3175
// RVA: 0x3F7F70
bool __fastcall UFG::EncounterBase::IsCharacterInUseHeuristic(
        UFG::EncounterBase *this,
        UFG::EncounterUnitComponent *pEncounterUnitComponent)
{
  UFG::SimObjectGame *m_pSimObject; // rcx
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // r12
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rax
  UFG::qStaticSymbol *v9; // rbp
  UFG::qPropertySet *mpPropSet; // rdi
  UFG::qPropertySet *v11; // rsi
  float *v12; // rbx
  float v13; // xmm6_4

  if ( !((unsigned __int8 (__fastcall *)(UFG::EncounterBase *))this->vfptr[78].__vecDelDtor)(this) )
    return 0;
  m_pSimObject = (UFG::SimObjectGame *)pEncounterUnitComponent->m_pSimObject;
  m_pTransformNodeComponent = 0i64;
  if ( m_pSimObject )
  {
    m_Flags = m_pSimObject->m_Flags;
    m_pTransformNodeComponent = m_pSimObject->m_pTransformNodeComponent;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = m_pSimObject->m_Components.p[44].m_pComponent;
    }
    else if ( m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
    {
      m_pComponent = UFG::SimObjectGame::GetComponentOfTypeHK(m_pSimObject, UFG::CharacterOccupantComponent::_TypeUID);
    }
    else
    {
      m_pComponent = UFG::SimObject::GetComponentOfType(m_pSimObject, UFG::CharacterOccupantComponent::_TypeUID);
    }
  }
  else
  {
    m_pComponent = 0i64;
  }
  v9 = &EncounterSym_invalid_vehicle_distance;
  if ( !m_pComponent )
    v9 = &EncounterSym_invalid_onfoot_distance;
  if ( this->mFocusTargetContext.mIsInWater )
    v9 = &EncounterSym_invalid_water_vehicle_distance;
  UFG::PropertySetHandle::Bind(&this->mProperties);
  mpPropSet = this->mProperties.mpPropSet;
  UFG::PropertySetHandle::Bind(&this->mProperties);
  v11 = this->mProperties.mpPropSet;
  v12 = UFG::qPropertySet::Get<float>(mpPropSet, (UFG::qArray<unsigned long,0> *)v9, DEPTH_RECURSE);
  v13 = *v12
      + *UFG::qPropertySet::Get<float>(
           v11,
           (UFG::qArray<unsigned long,0> *)&EncounterSym_invalid_buffer_distance,
           DEPTH_RECURSE);
  UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
  return (float)((float)((float)(m_pTransformNodeComponent->mWorldTransform.v3.y - this->mFocusTargetPosition.y)
                       * (float)(m_pTransformNodeComponent->mWorldTransform.v3.y - this->mFocusTargetPosition.y))
               + (float)((float)(m_pTransformNodeComponent->mWorldTransform.v3.x - this->mFocusTargetPosition.x)
                       * (float)(m_pTransformNodeComponent->mWorldTransform.v3.x - this->mFocusTargetPosition.x))) <= (float)(v13 * v13);
}

// File Line: 3216
// RVA: 0x3F89D0
char __fastcall UFG::EncounterBase::IsVehicleInUseHeuristic(
        UFG::EncounterBase *this,
        UFG::EncounterUnitComponent *pEncounterUnitComponent)
{
  UFG::SimObjectCVBase *m_pSimObject; // rsi
  float v5; // xmm6_4
  char v6; // r14
  __int16 m_Flags; // cx
  UFG::HumanDriverComponent *v8; // rax
  __int16 v9; // cx
  hkSimpleLocalFrame *m_pComponent; // rdi
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::SimObjectGame *Texture; // rax
  UFG::SimObjectGame *v13; // rbx
  __int16 v14; // dx
  UFG::SimComponent *v15; // rdi
  UFG::SimComponent *ComponentOfType; // rax
  __int16 v17; // cx
  UFG::SimComponent *v18; // rax
  __int16 v19; // cx
  UFG::SimComponent *v20; // rax

  m_pSimObject = (UFG::SimObjectCVBase *)pEncounterUnitComponent->m_pSimObject;
  UFG::PropertySetHandle::Bind(&this->mProperties);
  v5 = *UFG::qPropertySet::Get<float>(
          this->mProperties.mpPropSet,
          (UFG::qArray<unsigned long,0> *)&EncounterSym_minimum_acquired_time,
          DEPTH_RECURSE);
  v6 = (__int64)this->vfptr[78].__vecDelDtor(this, pEncounterUnitComponent) & 1;
  if ( !v6 )
    return v6;
  if ( pEncounterUnitComponent->mEngaged )
    v5 = FLOAT_5_0;
  if ( m_pSimObject )
  {
    m_Flags = m_pSimObject->m_Flags;
    if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
      v8 = UFG::SimObjectCVBase::GetComponent<UFG::HumanDriverComponent>(m_pSimObject);
    else
      v8 = (UFG::HumanDriverComponent *)((m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
                                       ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                           m_pSimObject,
                                           UFG::HumanDriverComponent::_TypeUID)
                                       : UFG::SimObject::GetComponentOfType(
                                           m_pSimObject,
                                           UFG::HumanDriverComponent::_TypeUID));
    if ( v8 )
      return 0;
  }
  if ( pEncounterUnitComponent->mUsageCount == 1 )
    return 0;
  if ( v5 >= pEncounterUnitComponent->mAcquiredTimer )
    return v6;
  if ( !m_pSimObject )
    return 0;
  v9 = m_pSimObject->m_Flags;
  if ( (v9 & 0x4000) != 0 )
    goto LABEL_22;
  if ( v9 < 0 )
  {
    m_pComponent = (hkSimpleLocalFrame *)m_pSimObject->m_Components.p[30].m_pComponent;
    goto LABEL_25;
  }
  if ( (v9 & 0x2000) != 0 || (v9 & 0x1000) != 0 )
LABEL_22:
    ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(m_pSimObject, UFG::VehicleOccupantComponent::_TypeUID);
  else
    ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pSimObject, UFG::VehicleOccupantComponent::_TypeUID);
  m_pComponent = (hkSimpleLocalFrame *)ComponentOfTypeHK;
LABEL_25:
  if ( !m_pComponent )
    return 0;
  Texture = (UFG::SimObjectGame *)Scaleform::Render::RBGenericImpl::RenderTarget::GetTexture(m_pComponent);
  v13 = Texture;
  if ( !Texture )
    return UFG::VehicleOccupantComponent::HasPassengers((UFG::VehicleOccupantComponent *)m_pComponent) != 0;
  v14 = Texture->m_Flags;
  if ( (v14 & 0x4000) != 0 )
  {
    v15 = Texture->m_Components.p[6].m_pComponent;
  }
  else if ( v14 >= 0 )
  {
    if ( (v14 & 0x2000) != 0 || (v14 & 0x1000) != 0 )
      ComponentOfType = UFG::SimObjectGame::GetComponentOfTypeHK(Texture, UFG::HealthComponent::_TypeUID);
    else
      ComponentOfType = UFG::SimObject::GetComponentOfType(Texture, UFG::HealthComponent::_TypeUID);
    v15 = ComponentOfType;
  }
  else
  {
    v15 = Texture->m_Components.p[6].m_pComponent;
  }
  v17 = v13->m_Flags;
  if ( (v17 & 0x4000) != 0 )
  {
    v18 = v13->m_Components.p[5].m_pComponent;
  }
  else if ( v17 >= 0 )
  {
    if ( (v17 & 0x2000) != 0 || (v17 & 0x1000) != 0 )
      v18 = UFG::SimObjectGame::GetComponentOfTypeHK(v13, UFG::AIScriptInterfaceComponent::_TypeUID);
    else
      v18 = UFG::SimObject::GetComponentOfType(v13, UFG::AIScriptInterfaceComponent::_TypeUID);
  }
  else
  {
    v18 = v13->m_Components.p[5].m_pComponent;
  }
  if ( !v15
    || BYTE4(v15[1].m_BoundComponentHandles.mNode.mPrev)
    || !v18
    || ((__int64)v18[32].m_BoundComponentHandles.mNode.mPrev & 0x20) != 0 )
  {
    return 0;
  }
  v19 = v13->m_Flags;
  if ( (v19 & 0x4000) != 0 )
  {
    v20 = v13->m_Components.p[16].m_pComponent;
  }
  else if ( v19 >= 0 )
  {
    v20 = (v19 & 0x2000) != 0 || (v19 & 0x1000) != 0
        ? UFG::SimObjectGame::GetComponentOfTypeHK(v13, UFG::EncounterUnitComponent::_TypeUID)
        : UFG::SimObject::GetComponentOfType(v13, UFG::EncounterUnitComponent::_TypeUID);
  }
  else
  {
    v20 = v13->m_Components.p[16].m_pComponent;
  }
  if ( !v20 || *(UFG::EncounterBase **)&v20[1].m_TypeUID != pEncounterUnitComponent->mpEncounter.m_pPointer )
    return 0;
  return v6;
}

// File Line: 3299
// RVA: 0x3F8D00
bool __fastcall UFG::EncounterBase::IsVehicleUsableByDistance(
        UFG::EncounterBase *this,
        UFG::EncounterUnitComponent *pEncounterUnitComponent)
{
  UFG::SimObject *m_pSimObject; // rbx
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rbx

  m_pSimObject = pEncounterUnitComponent->m_pSimObject;
  if ( !m_pSimObject )
    return 0;
  m_pTransformNodeComponent = m_pSimObject->m_pTransformNodeComponent;
  if ( !m_pTransformNodeComponent )
    return 0;
  UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
  return this->vfptr[60].__vecDelDtor(this, &m_pTransformNodeComponent->mWorldTransform.v3) == 0;
}

// File Line: 3315
// RVA: 0x3F81E0
bool __fastcall UFG::EncounterBase::IsCorrectWaveHeuristic(
        UFG::EncounterBase *this,
        UFG::EncounterUnitComponent *pEncounterUnitComponent)
{
  UFG::SimObject *m_pSimObject; // rbx
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rbx
  float *v6; // rax
  bool result; // al

  result = 1;
  if ( pEncounterUnitComponent->mWaveType.mUID != *(_DWORD *)((__int64 (__fastcall *)(UFG::EncounterBase *))this->vfptr[26].__vecDelDtor)(this) )
  {
    m_pSimObject = pEncounterUnitComponent->m_pSimObject;
    if ( !m_pSimObject )
      return 0;
    m_pTransformNodeComponent = m_pSimObject->m_pTransformNodeComponent;
    if ( !m_pTransformNodeComponent )
      return 0;
    UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
    if ( !UFG::SimObjectUtility::IsPositionOnScreen(
            (UFG::qVector3 *)&m_pTransformNodeComponent->mWorldTransform.v3,
            5.0,
            1) )
    {
      UFG::PropertySetHandle::Bind(&this->mProperties);
      v6 = UFG::qPropertySet::Get<float>(
             this->mProperties.mpPropSet,
             (UFG::qArray<unsigned long,0> *)&EncounterSym_invalid_wave_distance,
             DEPTH_RECURSE);
      if ( (float)((float)((float)(m_pTransformNodeComponent->mWorldTransform.v3.y - this->mFocusTargetPosition.y)
                         * (float)(m_pTransformNodeComponent->mWorldTransform.v3.y - this->mFocusTargetPosition.y))
                 + (float)((float)(m_pTransformNodeComponent->mWorldTransform.v3.x - this->mFocusTargetPosition.x)
                         * (float)(m_pTransformNodeComponent->mWorldTransform.v3.x - this->mFocusTargetPosition.x))) > (float)(*v6 * *v6) )
        return 0;
    }
  }
  return result;
}

// File Line: 3343
// RVA: 0x3F35E0
__int64 __fastcall UFG::EncounterBase::CountActiveUnits(
        UFG::EncounterBase *this,
        UFG::EncounterUnit::UnitType unitType)
{
  bool v3; // r15
  unsigned int v4; // ebx
  unsigned int size; // eax
  UFG::EncounterUnitComponent **p; // rsi
  __int64 v7; // rbp
  UFG::EncounterUnitComponent *v8; // r14
  unsigned int v9; // eax
  UFG::EncounterUnitComponent **v10; // rsi
  __int64 v11; // rbp
  UFG::EncounterUnitComponent *v12; // r14

  v3 = this->mReplenishStyle == ReplenishStyle_TopUpByWaveType;
  v4 = 0;
  if ( unitType == F5_1Pt2_512 )
  {
    size = this->mHumans.size;
    if ( size )
    {
      p = this->mHumans.p;
      v7 = size;
      do
      {
        v8 = *p;
        if ( !v3
          || v8->mWaveType.mUID == *(_DWORD *)((__int64 (__fastcall *)(UFG::EncounterBase *))this->vfptr[26].__vecDelDtor)(this) )
        {
          if ( this->vfptr[71].__vecDelDtor(this, v8) )
            ++v4;
        }
        ++p;
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
           || v12->mWaveType.mUID == *(_DWORD *)((__int64 (__fastcall *)(UFG::EncounterBase *))this->vfptr[26].__vecDelDtor)(this))
          && this->vfptr[72].__vecDelDtor(this, v12) )
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
    return "encounter_character_";
  return result;
}

// File Line: 3384
// RVA: 0x3F9350
void __fastcall UFG::EncounterBase::SetCurrentWaveType(UFG::EncounterBase *this, UFG::qSymbol *waveId)
{
  UFG::HeatLevelEnum v3; // edi
  UFG::qPropertyList *v4; // rax
  UFG::qPropertyList *v5; // rbx

  if ( this->mCurrentWaveType.mUID != waveId->mUID )
  {
    this->mCurrentWaveType = (UFG::qSymbol)waveId->mUID;
    UFG::PropertySetHandle::Bind(&this->mProperties);
    v3 = HEATLEVEL_ONE;
    v4 = UFG::qPropertySet::Get<UFG::qPropertyList>(
           this->mProperties.mpPropSet,
           (UFG::qArray<unsigned long,0> *)&EncounterSym_wave_definitions,
           DEPTH_RECURSE);
    v5 = v4;
    if ( this->mHeatLevel == HEATLEVEL_ONE )
      v3 = HEATLEVEL_THREE;
    this->mHeatLevel = v3;
    this->mHeatLevelProperties[this->mHeatLevel] = UFG::FindWave(v4, &this->mCurrentWaveType);
    this->mWaterHeatLevelProperties[this->mHeatLevel] = UFG::FindWave(v5, &this->mCurrentWaveType);
    ((void (__fastcall *)(UFG::EncounterBase *))this->vfptr[50].__vecDelDtor)(this);
    ((void (__fastcall *)(UFG::EncounterBase *))this->vfptr[23].__vecDelDtor)(this);
  }
}

// File Line: 3407
// RVA: 0x3F31E0
UFG::EncounterUnitComponent *__fastcall UFG::EncounterBase::AddExternalVehicleIntoSystem(
        UFG::EncounterBase *this,
        UFG::SimObjectGame *pVehicle)
{
  UFG::EncounterUnitComponent *m_pComponent; // rdi
  signed __int16 m_Flags; // cx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::qMemoryPool *SimulationMemoryPool; // rax
  UFG::allocator::free_link *v8; // rax
  UFG::EncounterUnitComponent *v9; // rax
  signed __int16 v10; // cx
  unsigned int v11; // esi
  UFG::SimObjectModifier v13; // [rsp+38h] [rbp-30h] BYREF

  if ( this->mVehicles.size >= 8 )
    return 0i64;
  if ( pVehicle )
  {
    m_Flags = pVehicle->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = (UFG::EncounterUnitComponent *)pVehicle->m_Components.p[16].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
        ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(pVehicle, UFG::EncounterUnitComponent::_TypeUID);
      else
        ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(pVehicle, UFG::EncounterUnitComponent::_TypeUID);
      m_pComponent = (UFG::EncounterUnitComponent *)ComponentOfTypeHK;
    }
    else
    {
      m_pComponent = (UFG::EncounterUnitComponent *)pVehicle->m_Components.p[16].m_pComponent;
    }
  }
  else
  {
    m_pComponent = 0i64;
  }
  if ( !m_pComponent )
  {
    SimulationMemoryPool = UFG::GetSimulationMemoryPool();
    v8 = UFG::qMemoryPool::Allocate(SimulationMemoryPool, 0xE0ui64, "EncounterUnitComponent", 0i64, 1u);
    if ( v8 )
    {
      UFG::EncounterUnitComponent::EncounterUnitComponent((UFG::EncounterUnitComponent *)v8, pVehicle->mNode.mUID);
      m_pComponent = v9;
    }
    else
    {
      m_pComponent = 0i64;
    }
    v10 = pVehicle->m_Flags;
    if ( (v10 & 0x4000) != 0 || v10 < 0 )
      v11 = 16;
    else
      v11 = -1;
    UFG::SimObjectModifier::SimObjectModifier(&v13, pVehicle, 1);
    UFG::SimObjectModifier::AttachComponent(&v13, m_pComponent, v11);
    UFG::SimObjectModifier::Close(&v13);
    UFG::SimObjectModifier::~SimObjectModifier(&v13);
  }
  this->mVehicles.p[this->mVehicles.size++] = m_pComponent;
  ((void (__fastcall *)(UFG::EncounterBase *, UFG::EncounterUnitComponent *, _QWORD))this->vfptr[69].__vecDelDtor)(
    this,
    m_pComponent,
    0i64);
  UFG::PropertySetHandle::Bind(&this->mProperties);
  ((void (__fastcall *)(UFG::EncounterBase *, UFG::EncounterUnitComponent *, UFG::qPropertySet *, _QWORD))this->vfptr[81].__vecDelDtor)(
    this,
    m_pComponent,
    this->mProperties.mpPropSet,
    0i64);
  return m_pComponent;
}

// File Line: 3440
// RVA: 0x3F2F90
UFG::EncounterUnitComponent *__fastcall UFG::EncounterBase::AddExternalCharacterIntoSystem(
        UFG::EncounterBase *this,
        UFG::SimObjectCVBase *pCharacter)
{
  UFG::PedSpawnManager *Instance; // rax
  UFG::EncounterUnitComponent *m_pComponent; // rsi
  signed __int16 m_Flags; // cx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::qMemoryPool *SimulationMemoryPool; // rax
  UFG::allocator::free_link *v9; // rax
  UFG::EncounterUnitComponent *v10; // rax
  signed __int16 v11; // cx
  unsigned int v12; // ebx
  UFG::qSymbol *v13; // rax
  UFG::qSymbol *v14; // rbx
  UFG::GameStatTracker *v15; // rax
  UFG::SimObjectModifier v17; // [rsp+38h] [rbp-30h] BYREF

  if ( this->mHumans.size >= 0x20 )
    return 0i64;
  Instance = UFG::PedSpawnManager::GetInstance();
  UFG::PedSpawnManager::SetSuspendOption(Instance, pCharacter, NoSuspend);
  if ( pCharacter )
  {
    m_Flags = pCharacter->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = (UFG::EncounterUnitComponent *)pCharacter->m_Components.p[16].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
        ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(pCharacter, UFG::EncounterUnitComponent::_TypeUID);
      else
        ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(pCharacter, UFG::EncounterUnitComponent::_TypeUID);
      m_pComponent = (UFG::EncounterUnitComponent *)ComponentOfTypeHK;
    }
    else
    {
      m_pComponent = (UFG::EncounterUnitComponent *)pCharacter->m_Components.p[16].m_pComponent;
    }
  }
  else
  {
    m_pComponent = 0i64;
  }
  if ( !m_pComponent )
  {
    SimulationMemoryPool = UFG::GetSimulationMemoryPool();
    v9 = UFG::qMemoryPool::Allocate(SimulationMemoryPool, 0xE0ui64, "EncounterUnitComponent", 0i64, 1u);
    if ( v9 )
    {
      UFG::EncounterUnitComponent::EncounterUnitComponent((UFG::EncounterUnitComponent *)v9, pCharacter->mNode.mUID);
      m_pComponent = v10;
    }
    else
    {
      m_pComponent = 0i64;
    }
    v11 = pCharacter->m_Flags;
    if ( (v11 & 0x4000) != 0 )
    {
      v12 = 16;
    }
    else if ( v11 >= 0 )
    {
      v12 = -1;
    }
    else
    {
      v12 = 16;
    }
    UFG::SimObjectModifier::SimObjectModifier(&v17, pCharacter, 1);
    UFG::SimObjectModifier::AttachComponent(&v17, m_pComponent, v12);
    UFG::SimObjectModifier::Close(&v17);
    UFG::SimObjectModifier::~SimObjectModifier(&v17);
  }
  this->mHumans.p[this->mHumans.size++] = m_pComponent;
  ((void (__fastcall *)(UFG::EncounterBase *, UFG::EncounterUnitComponent *, _QWORD))this->vfptr[69].__vecDelDtor)(
    this,
    m_pComponent,
    0i64);
  UFG::PropertySetHandle::Bind(&this->mProperties);
  v13 = UFG::qPropertySet::Get<UFG::qSymbol>(
          this->mProperties.mpPropSet,
          (UFG::qArray<unsigned long,0> *)&qSymbol_EncounterFactionClass,
          DEPTH_RECURSE);
  v14 = v13;
  if ( v13 )
  {
    if ( v13->mUID != -1 )
    {
      v15 = UFG::FactionInterface::Get();
      UFG::FactionInterface::SetFaction(&v15->mFactionInterface, pCharacter, v14);
    }
  }
  UFG::TSCharacter::EnableScriptControlOnSimObject(pCharacter, 0);
  this->vfptr[68].__vecDelDtor(this, (unsigned int)pCharacter);
  return m_pComponent;
}

// File Line: 3486
// RVA: 0x3F2DF0
void __fastcall UFG::EncounterBase::Acquire(
        UFG::EncounterBase *this,
        UFG::EncounterUnitComponent *pEncounterUnitComponent,
        UFG::qPropertySet *pGroupPropertySet)
{
  UFG::EncounterUnitComponent::AcquireBy(pEncounterUnitComponent, this, pGroupPropertySet);
}

// File Line: 3493
// RVA: 0x3FB7E0
void __fastcall UFG::EncounterBase::UpdateWaveGroupStats(UFG::EncounterBase *this)
{
  unsigned int i; // ecx
  __int64 v3; // rax
  unsigned int size; // eax
  UFG::EncounterUnitComponent **p; // rdi
  __int64 v6; // r14
  UFG::EncounterUnitComponent *v7; // rsi
  char mWaveTypeGroupIndex; // al
  __int64 v9; // rbp
  unsigned int v10; // eax
  UFG::EncounterUnitComponent **v11; // rdi
  __int64 v12; // r14
  UFG::EncounterUnitComponent *v13; // rsi
  char v14; // al
  __int64 v15; // rbp

  for ( i = 0; i < this->mNumWaveGroupTypes; this->mWaveGroupInstances[v3] = 0 )
    v3 = i++;
  size = this->mHumans.size;
  if ( size )
  {
    p = this->mHumans.p;
    v6 = size;
    do
    {
      v7 = *p;
      if ( v7->mWaveType.mUID == *(_DWORD *)((__int64 (__fastcall *)(UFG::EncounterBase *))this->vfptr[26].__vecDelDtor)(this) )
      {
        mWaveTypeGroupIndex = v7->mWaveTypeGroupIndex;
        if ( mWaveTypeGroupIndex != -1 )
        {
          v9 = mWaveTypeGroupIndex;
          if ( this->mWaveGroupTypes[mWaveTypeGroupIndex] == F5_1Pt2_512 )
          {
            if ( this->vfptr[71].__vecDelDtor(this, v7) )
              ++this->mWaveGroupInstances[v9];
          }
        }
      }
      ++p;
      --v6;
    }
    while ( v6 );
  }
  v10 = this->mVehicles.size;
  if ( v10 )
  {
    v11 = this->mVehicles.p;
    v12 = v10;
    do
    {
      v13 = *v11;
      if ( v13->mWaveType.mUID == *(_DWORD *)((__int64 (__fastcall *)(UFG::EncounterBase *))this->vfptr[26].__vecDelDtor)(this) )
      {
        v14 = v13->mWaveTypeGroupIndex;
        if ( v14 != -1 )
        {
          v15 = v14;
          if ( this->mWaveGroupTypes[v14] == F3_1Pt44_512 )
          {
            if ( this->vfptr[72].__vecDelDtor(this, v13) )
              ++this->mWaveGroupInstances[v15];
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
  UFG::qSafePointer<UFG::CombatRegion,UFG::CombatRegion> *p_mpCombatRegion; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::CombatRegion>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::CombatRegion>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::CombatRegion>,UFG::qSafePointerNodeList> *v5; // rax

  p_mpCombatRegion = &this->mpCombatRegion;
  if ( this->mpCombatRegion.m_pPointer )
  {
    mPrev = p_mpCombatRegion->mPrev;
    mNext = p_mpCombatRegion->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_mpCombatRegion->mPrev = p_mpCombatRegion;
    p_mpCombatRegion->mNext = p_mpCombatRegion;
  }
  p_mpCombatRegion->m_pPointer = pRegion;
  if ( pRegion )
  {
    v5 = pRegion->UFG::qSafePointerNode<UFG::CombatRegion>::m_SafePointerList.UFG::qSafePointerNode<UFG::CombatRegion>::mNode.mPrev;
    v5->mNext = p_mpCombatRegion;
    p_mpCombatRegion->mPrev = v5;
    p_mpCombatRegion->mNext = &pRegion->UFG::qSafePointerNode<UFG::CombatRegion>::m_SafePointerList.UFG::qSafePointerNode<UFG::CombatRegion>::mNode;
    pRegion->UFG::qSafePointerNode<UFG::CombatRegion>::m_SafePointerList.UFG::qSafePointerNode<UFG::CombatRegion>::mNode.mPrev = p_mpCombatRegion;
  }
}

