// File Line: 71
// RVA: 0x152F730
__int64 UFG::_dynamic_initializer_for__qSymbol_MissionTierNone2__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("None", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&qSymbol_MissionTierNone2, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__qSymbol_MissionTierNone2__);
}

// File Line: 72
// RVA: 0x152F6B0
__int64 UFG::_dynamic_initializer_for__qSymbol_MissionTierMinor2__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("Minor", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&qSymbol_MissionTierMinor2, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__qSymbol_MissionTierMinor2__);
}

// File Line: 73
// RVA: 0x152F630
__int64 UFG::_dynamic_initializer_for__qSymbol_MissionTierMiddle2__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("Middle", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&qSymbol_MissionTierMiddle2, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__qSymbol_MissionTierMiddle2__);
}

// File Line: 74
// RVA: 0x152F5B0
__int64 UFG::_dynamic_initializer_for__qSymbol_MissionTierMajor2__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("Major", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&qSymbol_MissionTierMajor2, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__qSymbol_MissionTierMajor2__);
}

// File Line: 76
// RVA: 0x151C150
__int64 UFG::_dynamic_initializer_for__GameStatsSymbol_Set__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("Set", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&GameStatsSymbol_Set, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__GameStatsSymbol_Set__);
}

// File Line: 77
// RVA: 0x151C090
__int64 UFG::_dynamic_initializer_for__GameStatsSymbol_Names__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("Names", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&GameStatsSymbol_Names, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__GameStatsSymbol_Names__);
}

// File Line: 78
// RVA: 0x151C190
__int64 UFG::_dynamic_initializer_for__GameStatsSymbol_Values__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("Values", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&GameStatsSymbol_Values, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__GameStatsSymbol_Values__);
}

// File Line: 79
// RVA: 0x151C0D0
__int64 UFG::_dynamic_initializer_for__GameStatsSymbol_PointsRequired__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("PointsRequired", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&GameStatsSymbol_PointsRequired, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__GameStatsSymbol_PointsRequired__);
}

// File Line: 80
// RVA: 0x151C110
__int64 UFG::_dynamic_initializer_for__GameStatsSymbol_PriceDiscount__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("PriceDiscount", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&GameStatsSymbol_PriceDiscount, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__GameStatsSymbol_PriceDiscount__);
}

// File Line: 102
// RVA: 0x4AB690
UFG::GameStatTracker *__fastcall UFG::GameStatTracker::Instance()
{
  UFG::GameStatTracker *v0; // rbx

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
  return v0;
}

// File Line: 121
// RVA: 0x48CAF0
void __fastcall UFG::GameStatTracker::GameStatTracker(UFG::GameStatTracker *this)
{
  UFG::qSymbol *v2; // rax
  UFG::qSymbol *v3; // rax
  UFG::qPropertySet *PropertySet; // rax
  UFG::qPropertySet *ResourceSet; // rax
  UFG::qSymbol *v6; // rax
  UFG::qArray<unsigned long,0> *v7; // rax
  UFG::qPropertyList *v8; // rax
  UFG::qSymbol *v9; // rax
  UFG::qArray<unsigned long,0> *v10; // rax
  UFG::qArray<unsigned long,0> *v11; // rax
  UFG::qPropertyList *v12; // rax
  UFG::GameSnapshot **mpSnapshots; // rbx
  __int64 v14; // rsi
  UFG::allocator::free_link *v15; // rax
  UFG::GameSnapshot *v16; // rax
  void (__fastcall *v17)(fastdelegate::detail::GenericClass *); // rax
  fastdelegate::FastDelegate1<UFG::Event *,void> v18; // [rsp+38h] [rbp-60h] BYREF
  void (__fastcall *v19)(UFG::Event *); // [rsp+48h] [rbp-50h]
  void (__fastcall *v20)(fastdelegate::detail::GenericClass *); // [rsp+50h] [rbp-48h]
  UFG::qString v21; // [rsp+58h] [rbp-40h] BYREF
  UFG::allocator::free_link *result; // [rsp+A8h] [rbp+10h] BYREF

  UFG::FactionInterface::FactionInterface(&this->mFactionInterface);
  this->mpDefaultData = 0i64;
  this->mpRuntimeData = 0i64;
  this->mpFaceLevelPropertySet = 0i64;
  this->m_iMaxFaceLevel = 10;
  UFG::SimpleTimer::SimpleTimer(&this->mSessionTimer);
  unk_14207A8EC = 3;
  UFG::GameSnapshot::StaticInitialize();
  UFG::qString::qString(&v21);
  v2 = UFG::qSymbol::create_from_string((UFG::qSymbol *)&result, UFG::GameStats_SaveGameDefaults);
  this->mpDefaultData = UFG::PropertySetManager::GetPropertySet(v2);
  v3 = UFG::qSymbol::create_from_string((UFG::qSymbol *)&result, UFG::GameStats_GameStats);
  PropertySet = UFG::PropertySetManager::FindPropertySet(v3);
  if ( PropertySet )
  {
    this->mpRuntimeData = UFG::qPropertySet::Clone(PropertySet);
  }
  else
  {
    UFG::qSymbol::create_from_string((UFG::qSymbol *)&result, UFG::GameStats_GameStats);
    ResourceSet = UFG::qPropertySet::CreateResourceSet((UFG::qSymbolUC *)&result, "PS_GameStats_GameStats");
    this->mpRuntimeData = ResourceSet;
    UFG::PSWrapper::AppendParentLocal(ResourceSet, this->mpDefaultData);
  }
  v6 = UFG::qSymbol::create_from_string((UFG::qSymbol *)&result, UFG::GameStats_FaceLevels);
  this->mpFaceLevelPropertySet = UFG::PropertySetManager::GetPropertySet(v6);
  v7 = (UFG::qArray<unsigned long,0> *)UFG::qSymbol::create_from_string((UFG::qSymbol *)&result, "Levels");
  v8 = UFG::qPropertySet::Get<UFG::qPropertyList>(this->mpFaceLevelPropertySet, v7, DEPTH_RECURSE);
  this->mpFaceLevelPropertyList = v8;
  this->m_iMaxFaceLevel = v8->mNumElements;
  v9 = UFG::qSymbol::create_from_string((UFG::qSymbol *)&result, UFG::GameStats_XPThresholds);
  this->mpXPThresholdPropertySet = UFG::PropertySetManager::GetPropertySet(v9);
  v10 = (UFG::qArray<unsigned long,0> *)UFG::qSymbol::create_from_string((UFG::qSymbol *)&result, "CopThresholds");
  this->mpXPThresholdPropertyList[0] = UFG::qPropertySet::Get<UFG::qPropertyList>(
                                         this->mpXPThresholdPropertySet,
                                         v10,
                                         DEPTH_RECURSE);
  v11 = (UFG::qArray<unsigned long,0> *)UFG::qSymbol::create_from_string((UFG::qSymbol *)&result, "TriadThresholds");
  v12 = UFG::qPropertySet::Get<UFG::qPropertyList>(this->mpXPThresholdPropertySet, v11, DEPTH_RECURSE);
  this->mpXPThresholdPropertyList[1] = v12;
  this->mMaxXPThresholdLevels[0] = this->mpXPThresholdPropertyList[0]->mNumElements;
  this->mMaxXPThresholdLevels[1] = v12->mNumElements;
  mpSnapshots = this->mpSnapshots;
  v14 = 5i64;
  do
  {
    v15 = UFG::qMalloc(0x10F8ui64, "GameStatTracker", 0i64);
    result = v15;
    if ( v15 )
      UFG::GameSnapshot::GameSnapshot((UFG::GameSnapshot *)v15);
    else
      v16 = 0i64;
    *mpSnapshots++ = v16;
    --v14;
  }
  while ( v14 );
  *((_BYTE *)this + 6216) &= ~1u;
  v17 = (void (__fastcall *)(fastdelegate::detail::GenericClass *))fastdelegate::FastDelegate1<char const *,void>::InvokeStaticFunction;
  if ( !UFG::GameStatTracker::HandleZoneLayoutEvent )
    v17 = 0i64;
  v20 = v17;
  v19 = UFG::GameStatTracker::HandleZoneLayoutEvent;
  v18.m_Closure.m_pFunction = v17;
  v18.m_Closure.m_pthis = (fastdelegate::detail::GenericClass *)UFG::GameStatTracker::HandleZoneLayoutEvent;
  UFG::EventDispatcher::Register(&UFG::EventDispatcher::mInstance, &v18, UFG::gZoneLayoutEvent.mUID, 0i64, 0);
  UFG::qString::~qString(&v21);
}

// File Line: 210
// RVA: 0x4909E0
void __fastcall UFG::GameStatTracker::~GameStatTracker(UFG::GameStatTracker *this)
{
  UFG::GameSnapshot **mpSnapshots; // rdi
  __int64 v3; // rsi
  UFG::GameSnapshot *v4; // rbx
  UFG::qPropertySet *mpRuntimeData; // rcx
  void (__fastcall *v6)(fastdelegate::detail::GenericClass *); // rax
  fastdelegate::FastDelegate1<UFG::Event *,void> v7; // [rsp+28h] [rbp-20h] BYREF

  mpSnapshots = this->mpSnapshots;
  v3 = 5i64;
  do
  {
    v4 = *mpSnapshots;
    if ( *mpSnapshots )
    {
      UFG::GameSnapshot::~GameSnapshot(*mpSnapshots);
      operator delete[](v4);
    }
    ++mpSnapshots;
    --v3;
  }
  while ( v3 );
  mpRuntimeData = this->mpRuntimeData;
  if ( mpRuntimeData )
  {
    UFG::qPropertySet::Destroy(mpRuntimeData);
    this->mpRuntimeData = 0i64;
  }
  v6 = (void (__fastcall *)(fastdelegate::detail::GenericClass *))fastdelegate::FastDelegate1<char const *,void>::InvokeStaticFunction;
  if ( !UFG::GameStatTracker::HandleZoneLayoutEvent )
    v6 = 0i64;
  v7.m_Closure.m_pFunction = v6;
  v7.m_Closure.m_pthis = (fastdelegate::detail::GenericClass *)UFG::GameStatTracker::HandleZoneLayoutEvent;
  UFG::EventDispatcher::UnRegister(&UFG::EventDispatcher::mInstance, &v7, UFG::gZoneLayoutEvent.mUID);
  _((AMD_HD3D *)&this->mSessionTimer);
  UFG::FactionInterface::~FactionInterface(&this->mFactionInterface);
}

// File Line: 238
// RVA: 0x4B73F0
void __fastcall UFG::GameStatTracker::ResetSnapshot(
        UFG::GameStatTracker *this,
        UFG::GameStatTracker::SnapshotType type)
{
  char *v2; // rdi
  void *v3; // rbx
  UFG::allocator::free_link *v4; // rax
  __int64 v5; // rax

  v2 = (char *)this + 8 * type;
  v3 = (void *)*((_QWORD *)v2 + 770);
  if ( v3 )
  {
    UFG::GameSnapshot::~GameSnapshot(*((UFG::GameSnapshot **)v2 + 770));
    operator delete[](v3);
  }
  v4 = UFG::qMalloc(0x10F8ui64, "GameStatTracker", 0i64);
  if ( v4 )
  {
    UFG::GameSnapshot::GameSnapshot((UFG::GameSnapshot *)v4);
    *((_QWORD *)v2 + 770) = v5;
  }
  else
  {
    *((_QWORD *)v2 + 770) = 0i64;
  }
}

// File Line: 261
// RVA: 0x499500
void __fastcall UFG::GameStatTracker::CommitPermanentDataTo(
        UFG::GameStatTracker *this,
        UFG::GameStatTracker::SnapshotType type)
{
  UFG::GameSnapshot **v3; // rbx

  v3 = (UFG::GameSnapshot **)((char *)this + 8 * type);
  UFG::GameSnapshot::CommitByFilter(v3[770], this->mpSnapshots[0], 0xFFFFFFF8, 2u, 1u);
  UFG::GameSnapshot::CommitByFilter(v3[770], this->mpSnapshots[0], 4u, 2u, 0);
}

// File Line: 275
// RVA: 0x49C610
void __fastcall UFG::GameStatTracker::DeserializeSnapshotByPropertySet(
        UFG::GameStatTracker *this,
        unsigned int filterMask,
        unsigned int persistenceMask,
        UFG::qPropertySet *pSaveGamePropertySet)
{
  UFG::qPropertySet *v4; // r12
  __int64 v5; // rdi
  unsigned int v6; // r8d
  __int64 v8; // r14
  UFG::qArray<unsigned long,0> **v9; // r15
  unsigned int *v10; // rbx
  __int64 v11; // rbp
  float *v12; // rax
  __int64 v13; // rbx
  UFG::qArray<unsigned long,0> **v14; // r14
  __int64 v15; // rbp
  int v16; // eax
  UFG::qSymbol *v17; // rax
  __int64 v18; // rbx
  __int64 v19; // rbp
  unsigned int v20; // eax
  bool *v21; // rax
  int v22; // ebx
  __int64 v23; // r14
  UFG::qArray<unsigned long,0> **v24; // r15
  int v25; // eax
  int *v26; // rax
  int *v27; // rax
  __int64 v28; // rbx
  UFG::qArray<unsigned long,0> **v29; // r14
  __int64 v30; // rbp
  int v31; // eax
  float *v32; // rax
  __int64 v33; // rbx
  unsigned int *v34; // r14
  __int64 v35; // rbp
  UFG::qRangedValue<long> *v36; // rax
  UFG::qRangedValue<long> *v37; // r9
  int mRange; // eax
  UFG::GameSnapshot *v39; // r8
  int mValue; // edx
  UFG::GameSnapshot *v41; // rdx
  int v42; // ecx
  int v43; // eax
  UFG::qRangedValue<float> *v44; // rax
  UFG::GameSnapshot *v45; // rcx
  float v46; // xmm0_4
  float v47; // xmm0_4
  UFG::GameSnapshot *v48; // rax
  UFG::qArray<unsigned long,0> **v49; // r14
  unsigned int *v50; // rbx
  __int64 v51; // rbp
  __int64 v52; // r15
  char *v53; // rax
  __int64 v54; // r15
  unsigned int *v55; // rax
  __int64 v56; // rbp
  unsigned int v57; // eax
  UFG::qArray<unsigned long,0> *v58; // rdx
  UFG::PersistentData::MapBool *v59; // r13
  UFG::qPropertySet *v60; // rax
  UFG::qPropertySet *v61; // rbx
  UFG::qPropertyList *v62; // r14
  UFG::qPropertyList *v63; // rax
  UFG::qPropertyList *v64; // r12
  unsigned int mNumElements; // r15d
  unsigned int i; // ebp
  bool *v67; // rbx
  UFG::qSymbol *v68; // rax
  __int64 v69; // r15
  unsigned int *v70; // rax
  __int64 v71; // r12
  unsigned int v72; // eax
  UFG::qArray<unsigned long,0> *v73; // rbp
  UFG::PersistentData::MapInt *v74; // r14
  UFG::PersistentData::KeyValue *p; // rcx
  $CCFB32CF948EEB04FF452B3FEB4ECF53 *v76; // rbx
  UFG::qPropertySet *v77; // r13
  UFG::qPropertySet *v78; // rax
  UFG::qPropertySet *v79; // rbx
  UFG::qPropertyList *v80; // r13
  UFG::qPropertyList *v81; // rax
  UFG::qPropertyList *v82; // r12
  unsigned int v83; // r15d
  unsigned int v84; // ebp
  int *v85; // rbx
  UFG::qSymbol *v86; // rax
  UFG::qArray<unsigned long,0> *v87; // rbp
  UFG::PersistentData::MapUInt64 *v88; // r14
  UFG::PersistentData::KeyValue64 *v89; // rcx
  unsigned __int64 *p_mIntValue; // rbx
  UFG::qPropertySet *v91; // rax
  UFG::qPropertySet *v92; // rbx
  UFG::qPropertyList *v93; // r15
  UFG::qPropertyList *v94; // rax
  UFG::qPropertyList *v95; // r13
  unsigned int v96; // r12d
  unsigned int v97; // ebp
  unsigned __int64 v98; // rbx
  UFG::qSymbol *v99; // rax
  __int64 v100; // r15
  unsigned int *v101; // rax
  __int64 v102; // r12
  unsigned int v103; // eax
  UFG::qArray<unsigned long,0> *v104; // rbp
  UFG::PersistentData::MapFloat *v105; // r14
  UFG::PersistentData::KeyValue *v106; // rcx
  $CCFB32CF948EEB04FF452B3FEB4ECF53 *v107; // rbx
  UFG::qPropertySet *v108; // rax
  UFG::qPropertySet *v109; // rbx
  UFG::qPropertyList *v110; // r13
  UFG::qPropertyList *v111; // rax
  UFG::qPropertyList *v112; // r12
  unsigned int v113; // r15d
  unsigned int v114; // ebp
  float *v115; // rbx
  UFG::qSymbol *v116; // rax
  __int64 v117; // [rsp+30h] [rbp-88h]
  __int64 v118; // [rsp+30h] [rbp-88h]
  __int64 v119; // [rsp+30h] [rbp-88h]
  __int64 v120; // [rsp+38h] [rbp-80h]
  __int64 v121; // [rsp+38h] [rbp-80h]
  __int64 v122; // [rsp+38h] [rbp-80h]
  unsigned int *v123; // [rsp+40h] [rbp-78h]
  unsigned int *v124; // [rsp+40h] [rbp-78h]
  unsigned int *v125; // [rsp+40h] [rbp-78h]
  UFG::qString v126; // [rsp+50h] [rbp-68h] BYREF

  v4 = pSaveGamePropertySet;
  v5 = persistenceMask;
  v6 = filterMask;
  v8 = 0i64;
  v9 = (UFG::qArray<unsigned long,0> **)TimeSymbols;
  v10 = UFG::GameSnapshot::sDefinitionTimes;
  v11 = 30i64;
  do
  {
    if ( (*v10 & v6) != 0 && ((unsigned int)v5 & *v10) == (_DWORD)v5 )
    {
      v12 = UFG::qPropertySet::Get<float>(v4, *v9, DEPTH_RECURSE);
      if ( v12 )
        UFG::SimpleTimer::SetElapsedTime((UFG::SimpleTimer *)((char *)this->mpSnapshots[0] + v8), *v12);
      v6 = filterMask;
    }
    v8 += 16i64;
    ++v10;
    ++v9;
    --v11;
  }
  while ( v11 );
  v13 = 480i64;
  v14 = (UFG::qArray<unsigned long,0> **)IDSymbols;
  v15 = 44i64;
  do
  {
    v16 = *(const unsigned int *)((char *)&UI_HASH_THUMBSTICK_RIGHT_LEFT_21 + v13);
    if ( (v16 & v6) != 0 && ((unsigned int)v5 & v16) == (_DWORD)v5 )
    {
      v17 = UFG::qPropertySet::Get<UFG::qSymbol>(v4, *v14, DEPTH_RECURSE);
      v6 = filterMask;
      if ( v17 )
      {
        if ( (*((_BYTE *)this + 6216) & 1) == 0 )
          *(UFG::qSymbol *)((char *)&this->mpSnapshots[0]->mTimes[0].mTimer.mTimestamp + v13) = (UFG::qSymbol)v17->mUID;
      }
    }
    v13 += 4i64;
    ++v14;
    --v15;
  }
  while ( v15 );
  v18 = 0i64;
  v19 = 58i64;
  do
  {
    v20 = UFG::GameSnapshot::sDefinitionBools[v18];
    if ( (v20 & v6) != 0 && ((unsigned int)v5 & v20) == (_DWORD)v5 )
    {
      v21 = UFG::qPropertySet::Get<bool>(v4, (UFG::qArray<unsigned long,0> *)BoolSymbols[v18], DEPTH_RECURSE);
      v6 = filterMask;
      if ( v21 )
      {
        if ( (*((_BYTE *)this + 6216) & 1) == 0 )
          this->mpSnapshots[0]->mBools[v18].mValue = *v21;
      }
    }
    ++v18;
    --v19;
  }
  while ( v19 );
  v22 = 0;
  v23 = 716i64;
  v24 = (UFG::qArray<unsigned long,0> **)Int32Symbols;
  do
  {
    v25 = *(_DWORD *)((char *)&UFG::GUIProgressionEditor::mpInstance + v23 + 4);
    if ( (v25 & v6) != 0 && ((unsigned int)v5 & v25) == (_DWORD)v5 )
    {
      v26 = UFG::qPropertySet::Get<long>(v4, *v24, DEPTH_RECURSE);
      if ( v26 )
      {
        if ( (*((_BYTE *)this + 6216) & 1) == 0 )
        {
          *(_DWORD *)((char *)&this->mpSnapshots[0]->mTimes[0].mTimer.mTimestamp + v23) = *v26;
          if ( UFG::GameStatAction::PostStat::sIsEnabled )
            UFG::GameStatAction::PostStat::AchieveInt((UFG::GameStat::Int32Stat)v22);
        }
      }
      v6 = filterMask;
    }
    ++v22;
    v23 += 4i64;
    ++v24;
  }
  while ( v22 < 163 );
  if ( (v6 & UFG::GameSnapshot::sDefinitionUInt64s[0]) != 0 && (UFG::GameSnapshot::sDefinitionUInt64s[0] & v5) == v5 )
  {
    v27 = UFG::qPropertySet::Get<long>(v4, (UFG::qArray<unsigned long,0> *)UInt64Symbols[0], DEPTH_RECURSE);
    v6 = filterMask;
    if ( v27 )
    {
      if ( (*((_BYTE *)this + 6216) & 1) == 0 )
        this->mpSnapshots[0]->mUInt64s[0].mValue = *v27;
    }
  }
  v28 = 1376i64;
  v29 = (UFG::qArray<unsigned long,0> **)FloatSymbols;
  v30 = 139i64;
  do
  {
    v31 = *(_DWORD *)((char *)&UFG::GUIProgressionEditor::mpInstance + v28);
    if ( (v31 & v6) != 0 && ((unsigned int)v5 & v31) == (_DWORD)v5 )
    {
      v32 = UFG::qPropertySet::Get<float>(v4, *v29, DEPTH_RECURSE);
      v6 = filterMask;
      if ( v32 )
      {
        if ( (*((_BYTE *)this + 6216) & 1) == 0 )
          *(float *)((char *)&this->mpSnapshots[0]->mTimes[0].mTimer.mTimestamp + v28) = *v32;
      }
    }
    v28 += 4i64;
    ++v29;
    --v30;
  }
  while ( v30 );
  v33 = 0i64;
  v34 = UFG::GameSnapshot::sDefinitionIntsRanged;
  v35 = 7i64;
  do
  {
    if ( (*v34 & v6) != 0 && ((unsigned int)v5 & *v34) == (_DWORD)v5 )
    {
      v36 = UFG::qPropertySet::Get<UFG::qRangedValue<long>>(
              v4,
              (UFG::qArray<unsigned long,0> *)Int32RangedSymbols[v33],
              DEPTH_RECURSE);
      v37 = v36;
      if ( v36 )
      {
        mRange = v36->mRange;
        if ( (*((_BYTE *)this + 6216) & 1) == 0 )
        {
          v39 = this->mpSnapshots[0];
          v39->mIntsRanged[v33].mRange = mRange;
          mValue = 0;
          if ( v39->mIntsRanged[v33].mValue > 0 )
            mValue = v39->mIntsRanged[v33].mValue;
          if ( mValue < mRange )
            mRange = mValue;
          v39->mIntsRanged[v33].mValue = mRange;
        }
        v6 = filterMask;
        if ( (*((_BYTE *)this + 6216) & 1) == 0 )
        {
          v41 = this->mpSnapshots[0];
          v42 = 0;
          if ( v37->mValue > 0 )
            v42 = v37->mValue;
          v43 = v41->mIntsRanged[v33].mRange;
          if ( v42 < v43 )
            v43 = v42;
          v41->mIntsRanged[v33].mValue = v43;
        }
      }
      else
      {
        v6 = filterMask;
      }
    }
    ++v34;
    ++v33;
    --v35;
  }
  while ( v35 );
  if ( (UFG::GameSnapshot::sDefinitionFloatsRanged[0] & v6) != 0
    && ((unsigned int)v5 & UFG::GameSnapshot::sDefinitionFloatsRanged[0]) == (_DWORD)v5 )
  {
    v44 = UFG::qPropertySet::Get<UFG::qRangedValue<float>>(
            v4,
            (UFG::qArray<unsigned long,0> *)FloatRangedSymbols[0],
            DEPTH_RECURSE);
    if ( v44 )
    {
      if ( (*((_BYTE *)this + 6216) & 1) == 0 )
      {
        v45 = this->mpSnapshots[0];
        v45->mFloatsRanged[0].mRange = v44->mRange;
        v46 = v45->mFloatsRanged[0].mValue;
        if ( v46 <= 0.0 )
          v46 = 0.0;
        if ( v46 >= v45->mFloatsRanged[0].mRange )
          v46 = v45->mFloatsRanged[0].mRange;
        v45->mFloatsRanged[0].mValue = v46;
      }
      v47 = v44->mValue;
      if ( (*((_BYTE *)this + 6216) & 1) == 0 )
      {
        v48 = this->mpSnapshots[0];
        if ( v47 <= 0.0 )
          v47 = 0.0;
        if ( v47 >= v48->mFloatsRanged[0].mRange )
          v47 = v48->mFloatsRanged[0].mRange;
        v48->mFloatsRanged[0].mValue = v47;
      }
    }
    v6 = filterMask;
  }
  v49 = (UFG::qArray<unsigned long,0> **)StringSymbols;
  v50 = UFG::GameSnapshot::sDefinitionStrings;
  v51 = 25i64;
  v52 = 2000i64;
  do
  {
    if ( (*v50 & v6) != 0 && ((unsigned int)v5 & *v50) == (_DWORD)v5 )
    {
      v53 = UFG::qPropertySet::Get<char const *>(v4, *v49, DEPTH_RECURSE);
      if ( v53 )
      {
        UFG::qString::qString(&v126, v53);
        if ( (*((_BYTE *)this + 6216) & 1) == 0 )
          UFG::qString::Set((UFG::qString *)((char *)this->mpSnapshots[0] + v52), v126.mData, v126.mLength, 0i64, 0);
        UFG::qString::~qString(&v126);
      }
      v6 = filterMask;
    }
    v52 += 40i64;
    ++v50;
    ++v49;
    --v51;
  }
  while ( v51 );
  v54 = 3048i64;
  v117 = 3048i64;
  v55 = UFG::GameSnapshot::sDefinitionMapBools;
  v123 = UFG::GameSnapshot::sDefinitionMapBools;
  v56 = 93i64;
  v120 = 93i64;
  do
  {
    v57 = *v55;
    if ( (v57 & v6) != 0 && ((unsigned int)v5 & v57) == (_DWORD)v5 )
    {
      v58 = *(UFG::qArray<unsigned long,0> **)((char *)off_142084538 + v54);
      v59 = *(UFG::PersistentData::MapBool **)((char *)&this->mpSnapshots[0]->mTimes[0].mTimer.mTimestamp + v54);
      v59->mValues.size = 0;
      v59->mNames.size = 0;
      v60 = UFG::qPropertySet::Get<UFG::qPropertySet>(v4, v58, DEPTH_RECURSE);
      v61 = v60;
      if ( v60 )
      {
        v62 = UFG::qPropertySet::Get<UFG::qPropertyList>(
                v60,
                (UFG::qArray<unsigned long,0> *)&GameStatsSymbol_Names,
                DEPTH_RECURSE);
        v63 = UFG::qPropertySet::Get<UFG::qPropertyList>(
                v61,
                (UFG::qArray<unsigned long,0> *)&GameStatsSymbol_Values,
                DEPTH_RECURSE);
        v64 = v63;
        if ( v62 && v63 )
        {
          mNumElements = v62->mNumElements;
          for ( i = 0; i < mNumElements; ++i )
          {
            v67 = UFG::qPropertyList::Get<bool>(v64, i);
            v68 = UFG::qPropertyList::Get<UFG::qSymbol>(v62, i);
            UFG::PersistentData::MapBool::SetStatus(v59, v68, *v67);
          }
          v54 = v117;
          v56 = v120;
        }
        v4 = pSaveGamePropertySet;
      }
      v6 = filterMask;
    }
    v55 = ++v123;
    v54 += 8i64;
    v117 = v54;
    v120 = --v56;
  }
  while ( v56 );
  v69 = 3792i64;
  v121 = 3792i64;
  v70 = UFG::GameSnapshot::sDefinitionMapInts;
  v124 = UFG::GameSnapshot::sDefinitionMapInts;
  v71 = 47i64;
  v118 = 47i64;
  do
  {
    v72 = *v70;
    if ( (v72 & v6) == 0 || ((unsigned int)v5 & v72) != (_DWORD)v5 )
      goto LABEL_113;
    v73 = *(UFG::qArray<unsigned long,0> **)((char *)off_142084540 + v69);
    v74 = *(UFG::PersistentData::MapInt **)((char *)&this->mpSnapshots[0]->mTimes[0].mTimer.mTimestamp + v69);
    p = v74->mValues.p;
    if ( p )
    {
      v76 = &p[-1].4;
      `eh vector destructor iterator(p, 8ui64, p[-1].mIntValue, (void (__fastcall *)(void *))_);
      operator delete[](v76);
    }
    v74->mValues.p = 0i64;
    *(_QWORD *)&v74->mValues.size = 0i64;
    v77 = pSaveGamePropertySet;
    v78 = UFG::qPropertySet::Get<UFG::qPropertySet>(pSaveGamePropertySet, v73, DEPTH_RECURSE);
    v79 = v78;
    if ( !v78 )
    {
      v6 = filterMask;
      goto LABEL_114;
    }
    v80 = UFG::qPropertySet::Get<UFG::qPropertyList>(
            v78,
            (UFG::qArray<unsigned long,0> *)&GameStatsSymbol_Names,
            DEPTH_RECURSE);
    v81 = UFG::qPropertySet::Get<UFG::qPropertyList>(
            v79,
            (UFG::qArray<unsigned long,0> *)&GameStatsSymbol_Values,
            DEPTH_RECURSE);
    v82 = v81;
    if ( !v80 )
      goto LABEL_112;
    if ( v81 )
    {
      v83 = v80->mNumElements;
      v84 = 0;
      if ( v83 )
      {
        do
        {
          v85 = (int *)UFG::qPropertyList::Get<long>(v82, v84);
          v86 = UFG::qPropertyList::Get<UFG::qSymbol>(v80, v84);
          UFG::PersistentData::MapInt::SetStatus(v74, v86, *v85);
          ++v84;
        }
        while ( v84 < v83 );
        v69 = v121;
LABEL_112:
        v71 = v118;
        v6 = filterMask;
        goto LABEL_113;
      }
      v69 = v121;
    }
    v6 = filterMask;
    v71 = v118;
LABEL_113:
    v77 = pSaveGamePropertySet;
LABEL_114:
    v70 = ++v124;
    v69 += 8i64;
    v121 = v69;
    v118 = --v71;
  }
  while ( v71 );
  if ( (UFG::GameSnapshot::sDefinitionMapUInt64s[0] & v6) != 0
    && ((unsigned int)v5 & UFG::GameSnapshot::sDefinitionMapUInt64s[0]) == (_DWORD)v5 )
  {
    v87 = (UFG::qArray<unsigned long,0> *)MapUInt64Symbols[0];
    v88 = this->mpSnapshots[0]->mpMapUInt64s[0];
    v89 = v88->mValues.p;
    if ( v89 )
    {
      p_mIntValue = &v89[-1].mIntValue;
      `eh vector destructor iterator(v89, 0x10ui64, v89[-1].mIntValue, (void (__fastcall *)(void *))_);
      operator delete[](p_mIntValue);
    }
    v88->mValues.p = 0i64;
    *(_QWORD *)&v88->mValues.size = 0i64;
    v91 = UFG::qPropertySet::Get<UFG::qPropertySet>(v77, v87, DEPTH_RECURSE);
    v92 = v91;
    if ( v91
      && (v93 = UFG::qPropertySet::Get<UFG::qPropertyList>(
                  v91,
                  (UFG::qArray<unsigned long,0> *)&GameStatsSymbol_Names,
                  DEPTH_RECURSE),
          v94 = UFG::qPropertySet::Get<UFG::qPropertyList>(
                  v92,
                  (UFG::qArray<unsigned long,0> *)&GameStatsSymbol_Values,
                  DEPTH_RECURSE),
          v95 = v94,
          v93) )
    {
      if ( v94 )
      {
        v96 = v93->mNumElements;
        v97 = 0;
        if ( v96 )
        {
          do
          {
            v98 = *(int *)UFG::qPropertyList::Get<long>(v95, v97);
            v99 = UFG::qPropertyList::Get<UFG::qSymbol>(v93, v97);
            UFG::PersistentData::MapUInt64::SetStatus(v88, v99, v98);
            ++v97;
          }
          while ( v97 < v96 );
          goto LABEL_126;
        }
      }
      v6 = filterMask;
    }
    else
    {
LABEL_126:
      v6 = filterMask;
    }
  }
  v100 = 4176i64;
  v122 = 4176i64;
  v101 = UFG::GameSnapshot::sDefinitionMapFloats;
  v125 = UFG::GameSnapshot::sDefinitionMapFloats;
  v102 = 18i64;
  v119 = 18i64;
  do
  {
    v103 = *v101;
    if ( (v103 & v6) != 0 && ((unsigned int)v5 & v103) == (_DWORD)v5 )
    {
      v104 = *(UFG::qArray<unsigned long,0> **)((char *)off_142084540 + v100);
      v105 = *(UFG::PersistentData::MapFloat **)((char *)&this->mpSnapshots[0]->mTimes[0].mTimer.mTimestamp + v100);
      v106 = v105->mValues.p;
      if ( v106 )
      {
        v107 = &v106[-1].4;
        `eh vector destructor iterator(v106, 8ui64, v106[-1].mIntValue, (void (__fastcall *)(void *))_);
        operator delete[](v107);
      }
      v105->mValues.p = 0i64;
      *(_QWORD *)&v105->mValues.size = 0i64;
      v108 = UFG::qPropertySet::Get<UFG::qPropertySet>(pSaveGamePropertySet, v104, DEPTH_RECURSE);
      v109 = v108;
      if ( v108 )
      {
        v110 = UFG::qPropertySet::Get<UFG::qPropertyList>(
                 v108,
                 (UFG::qArray<unsigned long,0> *)&GameStatsSymbol_Names,
                 DEPTH_RECURSE);
        v111 = UFG::qPropertySet::Get<UFG::qPropertyList>(
                 v109,
                 (UFG::qArray<unsigned long,0> *)&GameStatsSymbol_Values,
                 DEPTH_RECURSE);
        v112 = v111;
        if ( v110 && v111 )
        {
          v113 = v110->mNumElements;
          v114 = 0;
          if ( v113 )
          {
            do
            {
              v115 = UFG::qPropertyList::Get<float>(v112, v114);
              v116 = UFG::qPropertyList::Get<UFG::qSymbol>(v110, v114);
              UFG::PersistentData::MapFloat::SetStatus(v105, v116, *v115);
              ++v114;
            }
            while ( v114 < v113 );
            v100 = v122;
          }
          else
          {
            v100 = v122;
          }
        }
        v102 = v119;
      }
      v6 = filterMask;
    }
    v101 = ++v125;
    v100 += 8i64;
    v122 = v100;
    v119 = --v102;
  }
  while ( v102 );
}

// File Line: 772
// RVA: 0x4AA8B0
void __fastcall UFG::GameStatTracker::Initialize(UFG::GameStatTracker *this)
{
  UFG::qSymbol *v2; // rax
  UFG::qPropertySet *PropertySet; // rax
  UFG::qPropertySet *mpRuntimeData; // r9
  UFG::qSymbol result; // [rsp+30h] [rbp+8h] BYREF

  v2 = UFG::qSymbol::create_from_string(&result, UFG::GameStats_SaveGameDefaults);
  PropertySet = UFG::PropertySetManager::GetPropertySet(v2);
  mpRuntimeData = this->mpRuntimeData;
  this->mpDefaultData = PropertySet;
  UFG::GameStatTracker::DeserializeSnapshotByPropertySet(this, 0xFFFFFFFC, 2u, mpRuntimeData);
}

// File Line: 781
// RVA: 0x4B67D0
void __fastcall UFG::GameStatTracker::Reset(UFG::GameStatTracker *this, bool resetOptions)
{
  UFG::allocator::free_link *v4; // rax
  UFG::GameSnapshot *v5; // rax
  UFG::GameSnapshot *v6; // rsi
  UFG::GameSnapshot *v7; // rdi
  UFG::qSymbol *v8; // rax
  unsigned int v9; // edx
  UFG::GameStatTracker *v10; // rbx
  UFG::qSymbol result; // [rsp+68h] [rbp+10h] BYREF

  UFG::FactionInterface::Reset(&this->mFactionInterface);
  UFG::qPropertySet::RemovePropertiesAllLocal(this->mpRuntimeData);
  UFG::qPropertySet::RemoveParentsAll(this->mpRuntimeData);
  UFG::PSWrapper::AppendParentLocal(this->mpRuntimeData, this->mpDefaultData);
  UFG::GameStatTracker::ResetSnapshot(this, Snapshot_OpenWorld);
  UFG::GameStatTracker::ResetSnapshot(this, Snapshot_Mission);
  UFG::GameStatTracker::ResetSnapshot(this, Snapshot_Replay);
  UFG::GameStatTracker::ResetSnapshot(this, Snapshot_Save);
  v4 = UFG::qMalloc(0x10F8ui64, "GameStatTracker", 0i64);
  if ( v4 )
  {
    UFG::GameSnapshot::GameSnapshot((UFG::GameSnapshot *)v4);
    v6 = v5;
  }
  else
  {
    v6 = 0i64;
  }
  if ( !resetOptions )
    UFG::GameSnapshot::CommitByFilter(v6, this->mpSnapshots[0], 4u, 2u, 0);
  v7 = this->mpSnapshots[0];
  if ( v7 )
  {
    UFG::GameSnapshot::~GameSnapshot(this->mpSnapshots[0]);
    operator delete[](v7);
  }
  this->mpSnapshots[0] = v6;
  v8 = UFG::qSymbol::create_from_string(&result, UFG::GameStats_SaveGameDefaults);
  this->mpDefaultData = UFG::PropertySetManager::GetPropertySet(v8);
  v9 = -4;
  if ( !resetOptions )
    v9 = -8;
  UFG::GameStatTracker::DeserializeSnapshotByPropertySet(this, v9, 2u, this->mpRuntimeData);
  if ( (_S19_1 & 1) == 0 )
  {
    _S19_1 |= 1u;
    UFG::ProgressionTracker::ProgressionTracker(&sProgressionTracker);
    atexit(UFG::ProgressionTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sProgressionTracker__);
  }
  UFG::ProgressionTracker::mspInstance = &sProgressionTracker;
  if ( (*((_BYTE *)this + 6216) & 1) == 0 )
    this->mpSnapshots[0]->mIDs[25].mValue.mUID = unk_14240BAE0;
  v10 = &sGameStatTracker;
  if ( (_S12_6 & 1) == 0 )
  {
    _S12_6 |= 1u;
    UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
    atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
  }
  if ( UFG::GameStatTracker::mspInstance )
    v10 = UFG::GameStatTracker::mspInstance;
  UFG::GameStatTracker::mspInstance = v10;
  UFG::gUIViewportScale = UFG::UIHKScreenOptionsDisplay::ConvertScaleOption(v10->mpSnapshots[0]->mInts[124].mValue);
}

// File Line: 824
// RVA: 0x4AED70
void __fastcall UFG::GameStatTracker::LoadPresetGame(UFG::GameStatTracker *this, UFG::qSymbol *propertySetName)
{
  UFG::qPropertySet *PropertySet; // rax
  UFG::OSuiteLeaderboardManager *v5; // rax

  UFG::GameStatTracker::Reset(this, 0);
  PropertySet = UFG::PropertySetManager::FindPropertySet(propertySetName);
  if ( PropertySet )
  {
    UFG::qPropertySet::CopyFrom(this->mpRuntimeData, PropertySet, 1);
    UFG::GameStatTracker::DeserializeSnapshotByPropertySet(this, 0xFFFFFFF8, 2u, this->mpRuntimeData);
  }
  if ( (_S19_1 & 1) == 0 )
  {
    _S19_1 |= 1u;
    UFG::ProgressionTracker::ProgressionTracker(&sProgressionTracker);
    atexit(UFG::ProgressionTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sProgressionTracker__);
  }
  UFG::ProgressionTracker::mspInstance = &sProgressionTracker;
  unk_14240B9A8 = 0;
  unk_14240B6E8 = 0;
  UFG::GameStatAction::Snapshot::Initialize();
  UFG::GameStatAction::TemporaryData::Update();
  v5 = UFG::OSuiteLeaderboardManager::Instance();
  UFG::OSuiteLeaderboardManager::ResetStatSumsOnLoad(v5);
}

// File Line: 859
// RVA: 0x4C4290
void __fastcall UFG::GameStatTracker::Update(UFG::GameStatTracker *this, float realTimeDelta)
{
  if ( (_S13_4 & 1) == 0 )
  {
    _S13_4 |= 1u;
    UFG::GameSaveLoad::GameSaveLoad(&sGameSaveLoad);
    atexit(UFG::GameSaveLoad::Instance_::_2_::_dynamic_atexit_destructor_for__sGameSaveLoad__);
  }
  if ( UFG::StatGameManager::sInstance )
    UFG::StatGameManager::Update(UFG::StatGameManager::sInstance, realTimeDelta);
}

// File Line: 917
// RVA: 0x4C8220
void __fastcall UFG::GameStatTracker::UpdateSim(UFG::GameStatTracker *this, float gameTimeDelta)
{
  UFG::GameSnapshot *v3; // rax
  float mValue; // xmm9_4
  float v5; // xmm5_4
  float v6; // xmm7_4
  float v7; // xmm8_4
  float v8; // xmm10_4
  float v9; // xmm11_4
  float v10; // xmm3_4
  float v11; // xmm2_4
  float v12; // xmm3_4
  float v13; // xmm2_4

  if ( UFG::gFlowController.mCurrentState
    && !UFG::gFlowController.mCurrentState->vfptr->ModeIsSet(UFG::gFlowController.mCurrentState, eGSM_PAUSED) )
  {
    v3 = this->mpSnapshots[0];
    mValue = v3->mFloats[4].mValue;
    v5 = v3->mFloats[8].mValue;
    v6 = v3->mFloats[21].mValue;
    v7 = v3->mFloats[26].mValue;
    v8 = v3->mFloats[31].mValue;
    v9 = v3->mFloats[34].mValue;
    v10 = v3->mFloats[13].mValue;
    v11 = v3->mFloats[38].mValue;
    if ( mValue > 0.0 && (*((_BYTE *)this + 6216) & 1) == 0 )
      v3->mFloats[4].mValue = mValue - (float)(gameTimeDelta * 1000.0);
    if ( v5 > 0.0 && (*((_BYTE *)this + 6216) & 1) == 0 )
      this->mpSnapshots[0]->mFloats[8].mValue = v5 - (float)(gameTimeDelta * 1000.0);
    if ( v6 > 0.0 && (*((_BYTE *)this + 6216) & 1) == 0 )
      this->mpSnapshots[0]->mFloats[21].mValue = v6 - (float)(gameTimeDelta * 1000.0);
    if ( v7 > 0.0 && (*((_BYTE *)this + 6216) & 1) == 0 )
      this->mpSnapshots[0]->mFloats[26].mValue = v7 - (float)(gameTimeDelta * 1000.0);
    if ( v8 > 0.0 && (*((_BYTE *)this + 6216) & 1) == 0 )
      this->mpSnapshots[0]->mFloats[31].mValue = v8 - (float)(gameTimeDelta * 1000.0);
    if ( v9 > 0.0 && (*((_BYTE *)this + 6216) & 1) == 0 )
      this->mpSnapshots[0]->mFloats[34].mValue = v9 - (float)(gameTimeDelta * 1000.0);
    if ( v10 > 0.0 )
    {
      v12 = v10 + (float)(gameTimeDelta * -1000.0);
      if ( v12 <= 0.0 )
        v12 = FLOAT_N1_0;
      if ( (*((_BYTE *)this + 6216) & 1) == 0 )
        this->mpSnapshots[0]->mFloats[13].mValue = v12;
    }
    if ( v11 > 0.0 )
    {
      v13 = v11 + (float)(gameTimeDelta * -1000.0);
      if ( v13 <= 0.0 )
        v13 = FLOAT_N1_0;
      if ( (*((_BYTE *)this + 6216) & 1) == 0 )
        this->mpSnapshots[0]->mFloats[38].mValue = v13;
    }
  }
}

// File Line: 1018
// RVA: 0x4A53B0
__int64 __fastcall UFG::GameStatTracker::GetMaxStanding(UFG::GameStatTracker *this)
{
  int m_iMaxFaceLevel; // eax
  signed int v2; // r8d
  char *ValuePtr; // rax
  UFG::qPropertySet *v4; // rcx

  m_iMaxFaceLevel = this->m_iMaxFaceLevel;
  v2 = m_iMaxFaceLevel - 1;
  if ( m_iMaxFaceLevel - 1 < 0 || v2 >= m_iMaxFaceLevel )
    return 0xFFFFFFFFi64;
  ValuePtr = UFG::qPropertyList::GetValuePtr(this->mpFaceLevelPropertyList, 0x1Au, v2);
  if ( ValuePtr && *(_QWORD *)ValuePtr )
    v4 = (UFG::qPropertySet *)&ValuePtr[*(_QWORD *)ValuePtr];
  else
    v4 = 0i64;
  return (unsigned int)*UFG::qPropertySet::Get<long>(
                          v4,
                          (UFG::qArray<unsigned long,0> *)&GameStatsSymbol_PointsRequired,
                          DEPTH_RECURSE);
}

// File Line: 1023
// RVA: 0x4A2740
__int64 __fastcall UFG::GameStatTracker::GetFaceLevel(UFG::GameStatTracker *this)
{
  return UFG::GameStatTracker::GetFaceLevelFromExperience(this, this->mpSnapshots[0]->mInts[29].mValue);
}

// File Line: 1034
// RVA: 0x4A26D0
__int64 __fastcall UFG::GameStatTracker::GetExperienceForFaceLevel(UFG::GameStatTracker *this, int iFaceLevel)
{
  int m_iMaxFaceLevel; // r8d
  char *ValuePtr; // rax
  UFG::qPropertySet *v4; // rcx

  m_iMaxFaceLevel = this->m_iMaxFaceLevel;
  if ( iFaceLevel >= m_iMaxFaceLevel - 1 )
    iFaceLevel = m_iMaxFaceLevel - 1;
  if ( iFaceLevel < 0 || iFaceLevel >= m_iMaxFaceLevel )
    return 0xFFFFFFFFi64;
  ValuePtr = UFG::qPropertyList::GetValuePtr(this->mpFaceLevelPropertyList, 0x1Au, iFaceLevel);
  if ( ValuePtr && *(_QWORD *)ValuePtr )
    v4 = (UFG::qPropertySet *)&ValuePtr[*(_QWORD *)ValuePtr];
  else
    v4 = 0i64;
  return (unsigned int)*UFG::qPropertySet::Get<long>(
                          v4,
                          (UFG::qArray<unsigned long,0> *)&GameStatsSymbol_PointsRequired,
                          DEPTH_RECURSE);
}

// File Line: 1051
// RVA: 0x4A2760
__int64 __fastcall UFG::GameStatTracker::GetFaceLevelFromExperience(UFG::GameStatTracker *this, int standingExperience)
{
  int m_iMaxFaceLevel; // r9d
  int v3; // ebx
  int v5; // eax
  int i; // edi
  signed int v8; // r8d
  char *ValuePtr; // rax
  char *v10; // rcx
  __int64 v11; // rax
  UFG::qPropertySet *v12; // rcx
  int v13; // ecx

  m_iMaxFaceLevel = this->m_iMaxFaceLevel;
  v3 = 0;
  v5 = m_iMaxFaceLevel - 1;
  if ( m_iMaxFaceLevel - 1 <= 0 )
    return (unsigned int)(this->m_iMaxFaceLevel - 1);
  for ( i = 1; ; ++i )
  {
    v8 = i;
    if ( i >= v5 )
      v8 = v5;
    if ( v8 < 0 || v8 >= m_iMaxFaceLevel )
    {
      v13 = -1;
    }
    else
    {
      ValuePtr = UFG::qPropertyList::GetValuePtr(this->mpFaceLevelPropertyList, 0x1Au, v8);
      v10 = ValuePtr;
      if ( ValuePtr && (v11 = *(_QWORD *)ValuePtr) != 0 )
        v12 = (UFG::qPropertySet *)&v10[v11];
      else
        v12 = 0i64;
      v13 = *UFG::qPropertySet::Get<long>(
               v12,
               (UFG::qArray<unsigned long,0> *)&GameStatsSymbol_PointsRequired,
               DEPTH_RECURSE);
    }
    if ( standingExperience < v13 )
      break;
    m_iMaxFaceLevel = this->m_iMaxFaceLevel;
    ++v3;
    v5 = m_iMaxFaceLevel - 1;
    if ( v3 >= m_iMaxFaceLevel - 1 )
      return (unsigned int)(this->m_iMaxFaceLevel - 1);
  }
  return (unsigned int)v3;
}

// File Line: 1063
// RVA: 0x4A2540
signed __int64 __fastcall UFG::GameStatTracker::GetDiscountForFaceLevel(UFG::GameStatTracker *this, int iFaceLevel)
{
  int m_iMaxFaceLevel; // r8d
  char *ValuePtr; // rax
  UFG::qPropertySet *v4; // rcx

  m_iMaxFaceLevel = this->m_iMaxFaceLevel;
  if ( iFaceLevel >= m_iMaxFaceLevel - 1 )
    iFaceLevel = m_iMaxFaceLevel - 1;
  if ( iFaceLevel < 0 || iFaceLevel >= m_iMaxFaceLevel )
    return 0xFFFFFFFFi64;
  ValuePtr = UFG::qPropertyList::GetValuePtr(this->mpFaceLevelPropertyList, 0x1Au, iFaceLevel);
  if ( ValuePtr && *(_QWORD *)ValuePtr )
    v4 = (UFG::qPropertySet *)&ValuePtr[*(_QWORD *)ValuePtr];
  else
    v4 = 0i64;
  return (unsigned int)*UFG::qPropertySet::Get<long>(
                          v4,
                          (UFG::qArray<unsigned long,0> *)&GameStatsSymbol_PriceDiscount,
                          DEPTH_RECURSE);
}

// File Line: 1080
// RVA: 0x4A5BF0
signed __int64 __fastcall UFG::GameStatTracker::GetPercentageToNextFaceLevel(UFG::GameStatTracker *this)
{
  return UFG::GameStatTracker::GetPercentageToNextLevel(this, Standing);
}

// File Line: 1085
// RVA: 0x4A5C00
signed __int64 __fastcall UFG::GameStatTracker::GetPercentageToNextLevel(
        UFG::GameStatTracker *this,
        UFG::GameStat::Int32Stat stat)
{
  __int64 v2; // rsi
  int FaceLevelFromExperience; // eax
  int v6; // ebp
  int v7; // esi
  int ExperienceForFaceLevel; // ebx
  int v9; // ecx

  v2 = stat;
  if ( (int)UFG::GameStatTracker::GetFaceLevelFromExperience(this, this->mpSnapshots[0]->mInts[stat].mValue) >= this->m_iMaxFaceLevel - 1 )
    return 100i64;
  FaceLevelFromExperience = UFG::GameStatTracker::GetFaceLevelFromExperience(
                              this,
                              this->mpSnapshots[0]->mInts[v2].mValue);
  v6 = FaceLevelFromExperience;
  if ( FaceLevelFromExperience >= this->m_iMaxFaceLevel - 1 )
  {
    v7 = 0;
LABEL_6:
    v9 = 1;
    return (unsigned int)(int)(float)((float)((float)v7 / (float)v9) * 100.0);
  }
  ExperienceForFaceLevel = UFG::GameStatTracker::GetExperienceForFaceLevel(this, FaceLevelFromExperience);
  v7 = this->mpSnapshots[0]->mInts[v2].mValue - ExperienceForFaceLevel;
  v9 = UFG::GameStatTracker::GetExperienceForFaceLevel(this, v6 + 1) - ExperienceForFaceLevel;
  if ( !v9 )
    goto LABEL_6;
  return (unsigned int)(int)(float)((float)((float)v7 / (float)v9) * 100.0);
}

// File Line: 1106
// RVA: 0x4A5FE0
__int64 __fastcall UFG::GameStatTracker::GetRageTimerForFaceLevel(UFG::GameStatTracker *this, int iFaceLevel)
{
  int m_iMaxFaceLevel; // r8d
  char *ValuePtr; // rax
  UFG::qPropertySet *v4; // rbx
  UFG::qArray<unsigned long,0> *v5; // rax
  UFG::qSymbol result; // [rsp+38h] [rbp+10h] BYREF

  m_iMaxFaceLevel = this->m_iMaxFaceLevel;
  if ( iFaceLevel >= m_iMaxFaceLevel - 1 )
    iFaceLevel = m_iMaxFaceLevel - 1;
  if ( iFaceLevel < 0 || iFaceLevel >= m_iMaxFaceLevel )
    return 0xFFFFFFFFi64;
  ValuePtr = UFG::qPropertyList::GetValuePtr(this->mpFaceLevelPropertyList, 0x1Au, iFaceLevel);
  if ( ValuePtr && *(_QWORD *)ValuePtr )
    v4 = (UFG::qPropertySet *)&ValuePtr[*(_QWORD *)ValuePtr];
  else
    v4 = 0i64;
  v5 = (UFG::qArray<unsigned long,0> *)UFG::qSymbol::create_from_string(&result, "RageTimer");
  return (unsigned int)*UFG::qPropertySet::Get<long>(v4, v5, DEPTH_RECURSE);
}

// File Line: 1124
// RVA: 0x4A2820
bool __fastcall UFG::GameStatTracker::GetFavoursUnlockedForFaceLevel(UFG::GameStatTracker *this, int iFaceLevel)
{
  int m_iMaxFaceLevel; // r8d
  char *ValuePtr; // rax
  UFG::qPropertySet *v4; // rbx
  UFG::qArray<unsigned long,0> *v5; // rax
  UFG::qSymbol result; // [rsp+38h] [rbp+10h] BYREF

  m_iMaxFaceLevel = this->m_iMaxFaceLevel;
  if ( iFaceLevel >= m_iMaxFaceLevel - 1 )
    iFaceLevel = m_iMaxFaceLevel - 1;
  if ( iFaceLevel < 0 || iFaceLevel >= m_iMaxFaceLevel )
    return 0;
  ValuePtr = UFG::qPropertyList::GetValuePtr(this->mpFaceLevelPropertyList, 0x1Au, iFaceLevel);
  if ( ValuePtr && *(_QWORD *)ValuePtr )
    v4 = (UFG::qPropertySet *)&ValuePtr[*(_QWORD *)ValuePtr];
  else
    v4 = 0i64;
  v5 = (UFG::qArray<unsigned long,0> *)UFG::qSymbol::create_from_string(&result, "Favours");
  return *UFG::qPropertySet::Get<bool>(v4, v5, DEPTH_RECURSE);
}

// File Line: 1142
// RVA: 0x4A5950
__int64 __fastcall UFG::GameStatTracker::GetNumSafeHousesUnlockedForFaceLevel(
        UFG::GameStatTracker *this,
        int iFaceLevel)
{
  int m_iMaxFaceLevel; // r8d
  char *ValuePtr; // rax
  char *v4; // rcx
  __int64 v5; // rax
  UFG::qPropertySet *v6; // rbx
  UFG::qArray<unsigned long,0> *v7; // rax
  UFG::qPropertyList *v8; // rax
  UFG::qSymbol result; // [rsp+38h] [rbp+10h] BYREF

  m_iMaxFaceLevel = this->m_iMaxFaceLevel;
  if ( iFaceLevel >= m_iMaxFaceLevel - 1 )
    iFaceLevel = m_iMaxFaceLevel - 1;
  if ( iFaceLevel >= 0
    && iFaceLevel < m_iMaxFaceLevel
    && ((ValuePtr = UFG::qPropertyList::GetValuePtr(this->mpFaceLevelPropertyList, 0x1Au, iFaceLevel),
         (v4 = ValuePtr) == 0i64)
     || (v5 = *(_QWORD *)ValuePtr) == 0
      ? (v6 = 0i64)
      : (v6 = (UFG::qPropertySet *)&v4[v5]),
        v7 = (UFG::qArray<unsigned long,0> *)UFG::qSymbol::create_from_string(&result, "SafeHouseList"),
        (v8 = UFG::qPropertySet::Get<UFG::qPropertyList>(v6, v7, DEPTH_RECURSE)) != 0i64) )
  {
    return v8->mNumElements;
  }
  else
  {
    return 0i64;
  }
}

// File Line: 1163
// RVA: 0x4A6330
void __fastcall UFG::GameStatTracker::GetStandingPointsSinceLastLevel(
        UFG::GameStatTracker *this,
        unsigned int *iExpTowardsNextLevel,
        unsigned int *iDiffBetweenLevels)
{
  UFG::GameStatTracker::GetPointsSinceLastLevel(this, 29, iExpTowardsNextLevel, iDiffBetweenLevels);
}

// File Line: 1168
// RVA: 0x4A5F10
void __fastcall UFG::GameStatTracker::GetPointsSinceLastLevel(
        UFG::GameStatTracker *this,
        int stat,
        unsigned int *iExpTowardsNextLevel,
        unsigned int *iDiffBetweenLevels)
{
  __int64 v6; // r15
  int FaceLevelFromExperience; // eax
  int v9; // ebp
  unsigned int v10; // eax
  int ExperienceForFaceLevel; // ebx

  v6 = 4i64 * stat + 716;
  FaceLevelFromExperience = UFG::GameStatTracker::GetFaceLevelFromExperience(
                              this,
                              *(_DWORD *)((char *)&this->mpSnapshots[0]->mTimes[0].mTimer.mTimestamp + v6));
  v9 = FaceLevelFromExperience;
  if ( FaceLevelFromExperience < this->m_iMaxFaceLevel - 1 )
  {
    ExperienceForFaceLevel = UFG::GameStatTracker::GetExperienceForFaceLevel(this, FaceLevelFromExperience);
    *iExpTowardsNextLevel = *(_DWORD *)((char *)&this->mpSnapshots[0]->mTimes[0].mTimer.mTimestamp + v6)
                          - ExperienceForFaceLevel;
    v10 = UFG::GameStatTracker::GetExperienceForFaceLevel(this, v9 + 1) - ExperienceForFaceLevel;
  }
  else
  {
    v10 = 0;
    *iExpTowardsNextLevel = 0;
  }
  *iDiffBetweenLevels = v10;
}

// File Line: 1187
// RVA: 0x4A7310
__int64 __fastcall UFG::GameStatTracker::GetXPLevel(
        UFG::GameStatTracker *this,
        UFG::GameStatTracker::ThresholdType thresholdType,
        int totalXP)
{
  __int64 v3; // rsi
  unsigned int v6; // ebx

  v3 = thresholdType;
  if ( !this->mpXPThresholdPropertyList[thresholdType] )
    return this->mMaxXPThresholdLevels[v3];
  v6 = 0;
  if ( !this->mMaxXPThresholdLevels[thresholdType] )
    return this->mMaxXPThresholdLevels[v3];
  while ( totalXP >= *(_DWORD *)UFG::qPropertyList::Get<long>(this->mpXPThresholdPropertyList[v3], v6) )
  {
    if ( ++v6 >= this->mMaxXPThresholdLevels[v3] )
      return this->mMaxXPThresholdLevels[v3];
  }
  return v6;
}

// File Line: 1230
// RVA: 0x4A5CE0
signed __int64 __fastcall UFG::GameStatTracker::GetPercentageToNextXPLevel(
        UFG::GameStatTracker *this,
        UFG::GameStatTracker::ThresholdType thresholdType,
        int totalXP)
{
  __int64 v3; // rbx
  int XPLevel; // eax
  __int64 v7; // r14
  float v8; // xmm0_4
  int v9; // ebx
  int v10; // esi
  UFG::qPropertyList *v11; // rcx
  char *v12; // rax
  int v13; // edi
  UFG::qPropertyList *v14; // rcx
  char *v15; // rax
  int v16; // ecx
  int v17; // r15d
  int v18; // ecx
  int v19; // eax

  v3 = thresholdType;
  XPLevel = UFG::GameStatTracker::GetXPLevel(this, thresholdType, totalXP);
  v7 = v3;
  v8 = (float)(XPLevel + 1);
  if ( v8 >= (float)(int)this->mMaxXPThresholdLevels[v3] )
    v8 = (float)(int)this->mMaxXPThresholdLevels[v3];
  v9 = 0;
  v10 = (int)v8;
  if ( XPLevel > 0
    && (v11 = this->mpXPThresholdPropertyList[v7]) != 0i64
    && (v12 = UFG::qPropertyList::Get<long>(v11, XPLevel - 1)) != 0i64 )
  {
    v13 = *(_DWORD *)v12;
  }
  else
  {
    v13 = 0;
  }
  if ( v10 > 0
    && (v14 = this->mpXPThresholdPropertyList[v7]) != 0i64
    && (v15 = UFG::qPropertyList::Get<long>(v14, v10 - 1)) != 0i64 )
  {
    v16 = *(_DWORD *)v15;
  }
  else
  {
    v16 = 0;
  }
  v17 = totalXP - v13;
  v18 = v16 - v13;
  v19 = v18;
  if ( v17 > 0 )
    v9 = v17;
  if ( v9 < v18 )
    v19 = v9;
  if ( v18 <= 0 )
    return 100i64;
  else
    return (unsigned int)(100 * v19 / v18);
}

// File Line: 1251
// RVA: 0x4A5670
__int64 __fastcall UFG::GameStatTracker::GetNumHealthShrinesCollected(UFG::GameStatTracker *this)
{
  unsigned int v1; // ecx
  UFG::GameStatTracker *v2; // rbx
  UFG::GameStatTracker *v3; // rdx
  UFG::PersistentData::MapBool *v4; // rdi
  UFG::GameStatTracker *v5; // r8
  UFG::PersistentData::MapBool *v6; // rsi
  UFG::GameStatTracker *v7; // rdx
  UFG::PersistentData::MapBool *v8; // r14
  UFG::PersistentData::MapBool *v9; // r11
  unsigned int v10; // ecx
  unsigned int size; // r10d
  __int64 v12; // rdx
  $CCFB32CF948EEB04FF452B3FEB4ECF53 *v13; // rax
  unsigned int v14; // r9d
  __int64 v15; // rdx
  $CCFB32CF948EEB04FF452B3FEB4ECF53 *v16; // rax
  unsigned int v17; // edx
  __int64 v18; // r8
  $CCFB32CF948EEB04FF452B3FEB4ECF53 *v19; // rax
  __int64 v20; // r8
  $CCFB32CF948EEB04FF452B3FEB4ECF53 *v21; // rax

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
  v4 = v3->mpSnapshots[0]->mpMapBools[Collectible_HealthShrineAB];
  if ( (v1 & 1) == 0 )
  {
    _S12_6 = v1 | 1;
    UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
    atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
    v1 = _S12_6;
    v3 = UFG::GameStatTracker::mspInstance;
  }
  v5 = &sGameStatTracker;
  if ( v3 )
    v5 = v3;
  UFG::GameStatTracker::mspInstance = v5;
  v6 = v5->mpSnapshots[0]->mpMapBools[Collectible_HealthShrineCN];
  if ( (v1 & 1) == 0 )
  {
    _S12_6 = v1 | 1;
    UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
    atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
    v1 = _S12_6;
    v5 = UFG::GameStatTracker::mspInstance;
  }
  v7 = &sGameStatTracker;
  if ( v5 )
    v7 = v5;
  UFG::GameStatTracker::mspInstance = v7;
  v8 = v7->mpSnapshots[0]->mpMapBools[Collectible_HealthShrineKT];
  if ( (v1 & 1) == 0 )
  {
    _S12_6 = v1 | 1;
    UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
    atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
    v7 = UFG::GameStatTracker::mspInstance;
  }
  if ( v7 )
    v2 = v7;
  UFG::GameStatTracker::mspInstance = v2;
  v9 = v2->mpSnapshots[0]->mpMapBools[Collectible_HealthShrineNP];
  v10 = 0;
  if ( v4->mKeepType == KEEP_FALSE )
  {
    size = 0;
  }
  else if ( v4->mKeepType == KEEP_TRUE )
  {
    size = v4->mNames.size;
  }
  else
  {
    size = 0;
    v12 = v4->mValues.size;
    if ( (_DWORD)v12 )
    {
      v13 = &v4->mValues.p->4;
      do
      {
        if ( v13->mBoolValue )
          ++size;
        v13 += 2;
        --v12;
      }
      while ( v12 );
    }
  }
  if ( v6->mKeepType == KEEP_FALSE )
  {
    v14 = 0;
  }
  else if ( v6->mKeepType == KEEP_TRUE )
  {
    v14 = v6->mNames.size;
  }
  else
  {
    v14 = 0;
    v15 = v6->mValues.size;
    if ( (_DWORD)v15 )
    {
      v16 = &v6->mValues.p->4;
      do
      {
        if ( v16->mBoolValue )
          ++v14;
        v16 += 2;
        --v15;
      }
      while ( v15 );
    }
  }
  if ( v8->mKeepType == KEEP_FALSE )
  {
    v17 = 0;
  }
  else if ( v8->mKeepType == KEEP_TRUE )
  {
    v17 = v8->mNames.size;
  }
  else
  {
    v17 = 0;
    v18 = v8->mValues.size;
    if ( (_DWORD)v18 )
    {
      v19 = &v8->mValues.p->4;
      do
      {
        if ( v19->mBoolValue )
          ++v17;
        v19 += 2;
        --v18;
      }
      while ( v18 );
    }
  }
  if ( v9->mKeepType != KEEP_FALSE )
  {
    if ( v9->mKeepType == KEEP_TRUE )
    {
      v10 = v9->mNames.size;
    }
    else
    {
      v20 = v9->mValues.size;
      if ( (_DWORD)v20 )
      {
        v21 = &v9->mValues.p->4;
        do
        {
          if ( v21->mBoolValue )
            ++v10;
          v21 += 2;
          --v20;
        }
        while ( v20 );
      }
    }
  }
  return size + v14 + v10 + v17;
}

// File Line: 1264
// RVA: 0x4A3440
__int64 __fastcall UFG::GameStatTracker::GetHealthLevel(UFG::GameStatTracker *this)
{
  return (unsigned int)UFG::GameStatTracker::GetNumHealthShrinesCollected(this) / 5;
}

// File Line: 1285
// RVA: 0x4A6C60
UFG::GameSnapshot *__fastcall UFG::GameStatTracker::GetTimeStat(
        UFG::GameStatTracker *this,
        UFG::GameStat::TimeStat stat)
{
  return (UFG::GameSnapshot *)((char *)this->mpSnapshots[0] + 16 * stat);
}

// File Line: 1286
// RVA: 0x4A6720
_BOOL8 __fastcall UFG::GameStatTracker::GetStat(UFG::GameStatTracker *this, UFG::GameStat::BoolStat stat)
{
  return this->mpSnapshots[0]->mBools[stat].mValue;
}

// File Line: 1287
// RVA: 0x4A65D0
__int64 __fastcall UFG::GameStatTracker::GetStat(UFG::GameStatTracker *this, UFG::GameStat::Int32Stat stat)
{
  return (unsigned int)this->mpSnapshots[0]->mInts[stat].mValue;
}

// File Line: 1289
// RVA: 0x4A6660
float __fastcall UFG::GameStatTracker::GetStat(UFG::GameStatTracker *this, UFG::GameStat::FloatStat stat)
{
  return this->mpSnapshots[0]->mFloats[stat].mValue;
}

// File Line: 1290
// RVA: 0x4A65B0
__int64 __fastcall UFG::GameStatTracker::GetStat(UFG::GameStatTracker *this, UFG::GameStat::Int32RangedStat stat)
{
  return (unsigned int)this->mpSnapshots[0]->mIntsRanged[stat].mValue;
}

// File Line: 1291
// RVA: 0x4A6640
float __fastcall UFG::GameStatTracker::GetStat(UFG::GameStatTracker *this, UFG::GameStat::FloatRangedStat stat)
{
  return this->mpSnapshots[0]->mFloatsRanged[stat].mValue;
}

// File Line: 1292
// RVA: 0x4A6760
__int64 __fastcall UFG::GameStatTracker::GetStatRange(UFG::GameStatTracker *this, UFG::GameStat::Int32RangedStat stat)
{
  return (unsigned int)this->mpSnapshots[0]->mIntsRanged[stat].mRange;
}

// File Line: 1293
// RVA: 0x4A6780
float __fastcall UFG::GameStatTracker::GetStatRange(UFG::GameStatTracker *this, UFG::GameStat::FloatRangedStat stat)
{
  return this->mpSnapshots[0]->mFloatsRanged[stat].mRange;
}

// File Line: 1294
// RVA: 0x4A6570
UFG::PersistentData::String *__fastcall UFG::GameStatTracker::GetStat(
        UFG::GameStatTracker *this,
        UFG::GameStat::StringStat stat)
{
  return &this->mpSnapshots[0]->mStrings[stat];
}

// File Line: 1295
// RVA: 0x4A6550
UFG::PersistentData::Binary *__fastcall UFG::GameStatTracker::GetStat(
        UFG::GameStatTracker *this,
        UFG::GameStat::BinaryStat stat)
{
  return &this->mpSnapshots[0]->mBinaries[stat];
}

// File Line: 1298
// RVA: 0x4BD250
void __fastcall UFG::GameStatTracker::SetStat(UFG::GameStatTracker *this, UFG::GameStat::BoolStat stat, bool status)
{
  if ( (*((_BYTE *)this + 6216) & 1) == 0 )
    this->mpSnapshots[0]->mBools[stat].mValue = status;
}

// File Line: 1306
// RVA: 0x4BD390
void __fastcall UFG::GameStatTracker::SetStat(UFG::GameStatTracker *this, UFG::GameStat::Int32Stat stat, int number)
{
  UFG::qSymbol mapid; // [rsp+40h] [rbp+8h] BYREF
  UFG::qSymbol *p_mapid; // [rsp+58h] [rbp+20h]

  if ( (*((_BYTE *)this + 6216) & 1) == 0 )
  {
    this->mpSnapshots[0]->mInts[stat].mValue = number;
    p_mapid = &mapid;
    mapid.mUID = UFG::gNullQSymbol.mUID;
    UFG::GameStatAction::PostStat::Achieve(PDT_INT, stat, &mapid.mUID);
  }
}

// File Line: 1322
// RVA: 0x4BD2D0
void __fastcall UFG::GameStatTracker::SetStat(UFG::GameStatTracker *this, UFG::GameStat::FloatStat stat, float number)
{
  if ( (*((_BYTE *)this + 0x1848) & 1) == 0 )
    this->mpSnapshots[0]->mFloats[stat].mValue = number;
}

// File Line: 1330
// RVA: 0x4BD340
void __fastcall UFG::GameStatTracker::SetStat(
        UFG::GameStatTracker *this,
        UFG::GameStat::Int32RangedStat stat,
        int number)
{
  char *v3; // r9
  int v4; // ecx
  int v5; // eax

  if ( (*((_BYTE *)this + 6216) & 1) == 0 )
  {
    v3 = (char *)this->mpSnapshots[0] + 8 * stat;
    v4 = 0;
    if ( number > 0 )
      v4 = number;
    v5 = *((_DWORD *)v3 + 484);
    if ( v4 < v5 )
      v5 = v4;
    *((_DWORD *)v3 + 483) = v5;
  }
}

// File Line: 1338
// RVA: 0x4BD280
void __fastcall UFG::GameStatTracker::SetStat(UFG::GameStatTracker *this, int stat, float number)
{
  UFG::GameSnapshot *v3; // rcx

  if ( (*((_BYTE *)this + 6216) & 1) == 0 )
  {
    v3 = this->mpSnapshots[0];
    if ( number <= 0.0 )
      number = 0.0;
    if ( number >= v3->mFloatsRanged[stat].mRange )
      number = v3->mFloatsRanged[stat].mRange;
    v3->mFloatsRanged[stat].mValue = number;
  }
}

// File Line: 1346
// RVA: 0x4BD610
void __fastcall UFG::GameStatTracker::SetStatHigh(
        UFG::GameStatTracker *this,
        UFG::GameStat::Int32Stat stat,
        int number)
{
  UFG::GameSnapshot *v3; // rax

  if ( (*((_BYTE *)this + 6216) & 1) == 0 )
  {
    v3 = this->mpSnapshots[0];
    if ( v3->mInts[stat].mValue < number )
      v3->mInts[stat].mValue = number;
    if ( UFG::GameStatAction::PostStat::sIsEnabled )
      UFG::GameStatAction::PostStat::AchieveInt(stat);
  }
}

// File Line: 1354
// RVA: 0x4BD5D0
void __fastcall UFG::GameStatTracker::SetStatHigh(UFG::GameStatTracker *this, int stat, float number)
{
  UFG::GameSnapshot *v3; // rcx

  if ( (*((_BYTE *)this + 6216) & 1) == 0 )
  {
    v3 = this->mpSnapshots[0];
    if ( number > v3->mFloats[stat].mValue )
      v3->mFloats[stat].mValue = number;
  }
}

// File Line: 1362
// RVA: 0x4BD6B0
void __fastcall UFG::GameStatTracker::SetStatRange(UFG::GameStatTracker *this, int stat, int number)
{
  UFG::GameSnapshot *v3; // rax
  int v4; // ecx
  char *v5; // r9
  int v6; // eax

  if ( (*((_BYTE *)this + 6216) & 1) == 0 )
  {
    v3 = this->mpSnapshots[0];
    v4 = 0;
    v5 = (char *)v3 + 8 * stat;
    v6 = *((_DWORD *)v5 + 483);
    *((_DWORD *)v5 + 484) = number;
    if ( v6 > 0 )
      v4 = v6;
    if ( v4 < number )
      number = v4;
    *((_DWORD *)v5 + 483) = number;
  }
}

// File Line: 1369
// RVA: 0x4BD660
void __fastcall UFG::GameStatTracker::SetStatRange(UFG::GameStatTracker *this, int stat, float number)
{
  UFG::GameSnapshot *v3; // rcx
  float mValue; // xmm0_4

  if ( (*((_BYTE *)this + 6216) & 1) == 0 )
  {
    v3 = this->mpSnapshots[0];
    mValue = v3->mFloatsRanged[stat].mValue;
    v3->mFloatsRanged[stat].mRange = number;
    if ( mValue <= 0.0 )
      mValue = 0.0;
    if ( mValue >= number )
      mValue = number;
    v3->mFloatsRanged[stat].mValue = mValue;
  }
}

// File Line: 1376
// RVA: 0x4BD580
void __fastcall UFG::GameStatTracker::SetStat(
        UFG::GameStatTracker *this,
        UFG::GameStat::StringStat stat,
        UFG::qString *string)
{
  if ( (*((_BYTE *)this + 6216) & 1) == 0 )
    UFG::qString::Set(&this->mpSnapshots[0]->mStrings[stat].mValue, string->mData, string->mLength, 0i64, 0);
}

// File Line: 1384
// RVA: 0x4BD1C0
void __fastcall UFG::GameStatTracker::SetStat(
        UFG::GameStatTracker *this,
        UFG::GameStat::BinaryStat stat,
        UFG::PersistentData::Binary *binary)
{
  unsigned int mSize; // edi
  void *mpBuffer; // rsi
  void **v5; // rbx

  if ( (*((_BYTE *)this + 6216) & 1) == 0 )
  {
    mSize = binary->mSize;
    mpBuffer = binary->mpBuffer;
    v5 = (void **)&this->mpSnapshots[0]->mTimes[stat];
    if ( *((_DWORD *)v5 + 752) )
      operator delete[](v5[375]);
    v5[375] = mpBuffer;
    *((_DWORD *)v5 + 752) = mSize;
  }
}

// File Line: 1393
// RVA: 0x4B0D90
void __fastcall UFG::GameStatTracker::MoneyHackSoWeCanShipThisGame(UFG::GameStatTracker *this, int money)
{
  if ( (*((_BYTE *)this + 6216) & 1) == 0 )
  {
    this->mpSnapshots[0]->mInts[62].mValue += money;
    this->mpSnapshots[1]->mInts[62].mValue += money;
    this->mpSnapshots[2]->mInts[62].mValue += money;
    this->mpSnapshots[3]->mInts[62].mValue += money;
    this->mpSnapshots[0]->mInts[61].mValue += money;
    this->mpSnapshots[1]->mInts[61].mValue += money;
    this->mpSnapshots[2]->mInts[61].mValue += money;
    this->mpSnapshots[3]->mInts[61].mValue += money;
  }
}

// File Line: 1409
// RVA: 0x4C2770
void __fastcall UFG::GameStatTracker::SynchronizeCurrentSnapshotWithCurrentGameState(UFG::GameStatTracker *this)
{
  unsigned int mUID; // edi
  unsigned int v2; // ebx
  UFG::SimObjectCharacter *LocalPlayer; // rax
  UFG::SimComponent *m_pComponent; // rdx
  unsigned __int8 *v5; // rcx
  __int64 v6; // r14
  __int64 v7; // rax
  UFG::SimObjectWeaponPropertiesComponent *v8; // rsi
  UFG::SimObjectProp *v9; // r15
  __int64 v10; // rax
  UFG::SimObjectProp *v11; // r13
  __int64 v12; // rax
  UFG::SimObjectProp *v13; // r14
  UFG::SimObjectWeaponPropertiesComponent *v14; // rbp
  __int16 m_Flags; // cx
  UFG::SimObjectWeaponPropertiesComponent *ComponentOfTypeHK; // rax
  UFG::SimObjectWeaponPropertiesComponent *v17; // r13
  __int16 v18; // cx
  UFG::SimObjectWeaponPropertiesComponent *ComponentOfType; // rax
  __int16 v20; // cx
  UFG::SimObjectWeaponPropertiesComponent *v21; // rax
  bool v22; // r12
  UFG::SceneObjectProperties *m_pSceneObj; // rcx
  char v25; // [rsp+78h] [rbp+10h]
  UFG::SimObjectProp *v26; // [rsp+80h] [rbp+18h]

  mUID = -1;
  v2 = -1;
  LocalPlayer = UFG::GetLocalPlayer();
  if ( !LocalPlayer )
    goto LABEL_64;
  m_pComponent = LocalPlayer->m_Components.p[20].m_pComponent;
  if ( !m_pComponent )
    goto LABEL_64;
  v5 = *(unsigned __int8 **)&m_pComponent[1].m_Flags;
  v6 = *(_QWORD *)&m_pComponent[1].m_TypeUID;
  v7 = 56i64 * v5[25];
  v8 = 0i64;
  if ( *(_QWORD *)(v7 + v6 + 40) && *(_BYTE *)(v7 + v6 + 49) )
    v9 = *(UFG::SimObjectProp **)(v7 + v6 + 40);
  else
    v9 = 0i64;
  v10 = 56i64 * v5[51];
  if ( *(_QWORD *)(v10 + v6 + 40) && *(_BYTE *)(v10 + v6 + 49) )
    v11 = *(UFG::SimObjectProp **)(v10 + v6 + 40);
  else
    v11 = 0i64;
  v26 = v11;
  v12 = 56i64 * v5[50];
  if ( *(_QWORD *)(v12 + v6 + 40) && *(_BYTE *)(v12 + v6 + 49) )
    v13 = *(UFG::SimObjectProp **)(v12 + v6 + 40);
  else
    v13 = 0i64;
  if ( !v9 )
  {
    v14 = 0i64;
    goto LABEL_26;
  }
  m_Flags = v9->m_Flags;
  if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
  {
LABEL_23:
    ComponentOfTypeHK = (UFG::SimObjectWeaponPropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                     v9,
                                                                     UFG::SimObjectWeaponPropertiesComponent::_TypeUID);
    goto LABEL_25;
  }
  if ( (m_Flags & 0x2000) == 0 )
  {
    if ( (m_Flags & 0x1000) == 0 )
    {
      ComponentOfTypeHK = (UFG::SimObjectWeaponPropertiesComponent *)UFG::SimObject::GetComponentOfType(
                                                                       v9,
                                                                       UFG::SimObjectWeaponPropertiesComponent::_TypeUID);
      goto LABEL_25;
    }
    goto LABEL_23;
  }
  ComponentOfTypeHK = UFG::SimObjectProp::GetComponent<UFG::SimObjectWeaponPropertiesComponent>(v9);
LABEL_25:
  v14 = ComponentOfTypeHK;
LABEL_26:
  if ( !v11 )
  {
    v17 = 0i64;
    goto LABEL_37;
  }
  v18 = v11->m_Flags;
  if ( (v18 & 0x4000) != 0 || v18 < 0 )
  {
LABEL_34:
    ComponentOfType = (UFG::SimObjectWeaponPropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                   v11,
                                                                   UFG::SimObjectWeaponPropertiesComponent::_TypeUID);
    goto LABEL_36;
  }
  if ( (v18 & 0x2000) == 0 )
  {
    if ( (v18 & 0x1000) == 0 )
    {
      ComponentOfType = (UFG::SimObjectWeaponPropertiesComponent *)UFG::SimObject::GetComponentOfType(
                                                                     v11,
                                                                     UFG::SimObjectWeaponPropertiesComponent::_TypeUID);
      goto LABEL_36;
    }
    goto LABEL_34;
  }
  ComponentOfType = UFG::SimObjectProp::GetComponent<UFG::SimObjectWeaponPropertiesComponent>(v11);
LABEL_36:
  v17 = ComponentOfType;
LABEL_37:
  if ( !v13 )
    goto LABEL_47;
  v20 = v13->m_Flags;
  if ( (v20 & 0x4000) != 0 || v20 < 0 )
  {
LABEL_44:
    v21 = (UFG::SimObjectWeaponPropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                       v13,
                                                       UFG::SimObjectWeaponPropertiesComponent::_TypeUID);
    goto LABEL_46;
  }
  if ( (v20 & 0x2000) == 0 )
  {
    if ( (v20 & 0x1000) == 0 )
    {
      v21 = (UFG::SimObjectWeaponPropertiesComponent *)UFG::SimObject::GetComponentOfType(
                                                         v13,
                                                         UFG::SimObjectWeaponPropertiesComponent::_TypeUID);
      goto LABEL_46;
    }
    goto LABEL_44;
  }
  v21 = UFG::SimObjectProp::GetComponent<UFG::SimObjectWeaponPropertiesComponent>(v13);
LABEL_46:
  v8 = v21;
LABEL_47:
  if ( !v14 || (v25 = 1, !v14->mWeaponTypeInfo->mFireModes[v14->mFireMode]->mStowable) )
    v25 = 0;
  v22 = v8 && v8->mWeaponTypeInfo->mFireModes[v8->mFireMode]->mStowable;
  if ( v17 )
  {
    mUID = UFG::SceneObjectProperties::GetArchetypePropertiesName(v26->m_pSceneObj)->mUID;
    if ( v14 && v25 )
    {
      m_pSceneObj = v9->m_pSceneObj;
LABEL_63:
      v2 = UFG::SceneObjectProperties::GetArchetypePropertiesName(m_pSceneObj)->mUID;
      goto LABEL_64;
    }
  }
  else if ( v14 )
  {
    mUID = UFG::SceneObjectProperties::GetArchetypePropertiesName(v9->m_pSceneObj)->mUID;
  }
  if ( v8 && v22 )
  {
    m_pSceneObj = v13->m_pSceneObj;
    goto LABEL_63;
  }
LABEL_64:
  if ( (*((_BYTE *)this + 6216) & 1) == 0 )
  {
    this->mpSnapshots[0]->mIDs[23].mValue.mUID = mUID;
    if ( (*((_BYTE *)this + 6216) & 1) == 0 )
      this->mpSnapshots[0]->mIDs[24].mValue.mUID = v2;
  }
}

// File Line: 1472
// RVA: 0x494160
void __fastcall UFG::GameStatTracker::ApplyDelta(UFG::GameStatTracker *this, UFG::GameStat::Int32Stat stat, int delta)
{
  if ( (*((_BYTE *)this + 6216) & 1) == 0 )
  {
    this->mpSnapshots[0]->mInts[stat].mValue += delta;
    if ( UFG::GameStatAction::PostStat::sIsEnabled )
      UFG::GameStatAction::PostStat::AchieveInt(stat);
  }
}

// File Line: 1481
// RVA: 0x4940D0
void __fastcall UFG::GameStatTracker::ApplyDelta(
        UFG::GameStatTracker *this,
        UFG::GameStat::FloatStat stat,
        float delta)
{
  if ( (*((_BYTE *)this + 6216) & 1) == 0 )
    this->mpSnapshots[0]->mFloats[stat].mValue = delta + this->mpSnapshots[0]->mFloats[stat].mValue;
}

// File Line: 1490
// RVA: 0x494110
void __fastcall UFG::GameStatTracker::ApplyDelta(
        UFG::GameStatTracker *this,
        UFG::GameStat::Int32RangedStat stat,
        int delta)
{
  char *v3; // r9
  int v4; // edx
  int v5; // eax

  if ( (*((_BYTE *)this + 6216) & 1) == 0 )
  {
    v3 = (char *)this->mpSnapshots[0] + 8 * stat;
    v4 = 0;
    if ( delta + *((_DWORD *)v3 + 483) > 0 )
      v4 = delta + *((_DWORD *)v3 + 483);
    v5 = *((_DWORD *)v3 + 484);
    if ( v4 < v5 )
      v5 = v4;
    *((_DWORD *)v3 + 483) = v5;
  }
}

// File Line: 1499
// RVA: 0x494070
void __fastcall UFG::GameStatTracker::ApplyDelta(UFG::GameStatTracker *this, int stat, float delta)
{
  UFG::GameSnapshot *v3; // rcx
  float mRange; // xmm2_4

  if ( (*((_BYTE *)this + 6216) & 1) == 0 )
  {
    v3 = this->mpSnapshots[0];
    mRange = delta + v3->mFloatsRanged[stat].mValue;
    if ( mRange <= 0.0 )
      mRange = 0.0;
    if ( mRange >= v3->mFloatsRanged[stat].mRange )
      mRange = v3->mFloatsRanged[stat].mRange;
    v3->mFloatsRanged[stat].mValue = mRange;
  }
}

// File Line: 1508
// RVA: 0x494480
void __fastcall UFG::GameStatTracker::ApplyDeltaRange(UFG::GameStatTracker *this, int stat, int delta)
{
  UFG::GameSnapshot *v3; // rax
  int v4; // ecx
  char *v5; // r9
  int v6; // eax
  int v7; // edx

  if ( (*((_BYTE *)this + 6216) & 1) == 0 )
  {
    v3 = this->mpSnapshots[0];
    v4 = 0;
    v5 = (char *)v3 + 8 * stat;
    v6 = *((_DWORD *)v5 + 483);
    *((_DWORD *)v5 + 484) += delta;
    v7 = *((_DWORD *)v5 + 484);
    if ( v6 > 0 )
      v4 = v6;
    if ( v4 < v7 )
      v7 = v4;
    *((_DWORD *)v5 + 483) = v7;
  }
}

// File Line: 1516
// RVA: 0x494430
void __fastcall UFG::GameStatTracker::ApplyDeltaRange(UFG::GameStatTracker *this, int stat, float delta)
{
  UFG::GameSnapshot *v3; // rcx
  float v4; // xmm2_4
  float mValue; // xmm0_4

  if ( (*((_BYTE *)this + 6216) & 1) == 0 )
  {
    v3 = this->mpSnapshots[0];
    v4 = delta + v3->mFloatsRanged[stat].mRange;
    mValue = v3->mFloatsRanged[stat].mValue;
    v3->mFloatsRanged[stat].mRange = v4;
    if ( mValue <= 0.0 )
      mValue = 0.0;
    if ( mValue >= v4 )
      mValue = v4;
    v3->mFloatsRanged[stat].mValue = mValue;
  }
}

// File Line: 1595
// RVA: 0x4A6590
UFG::PersistentData::ID *__fastcall UFG::GameStatTracker::GetStat(
        UFG::GameStatTracker *this,
        UFG::GameStat::IDStat stat)
{
  return &this->mpSnapshots[0]->mIDs[stat];
}

// File Line: 1597
// RVA: 0x4BD300
void __fastcall UFG::GameStatTracker::SetStat(UFG::GameStatTracker *this, UFG::GameStat::IDStat stat, UFG::qSymbol *id)
{
  if ( (*((_BYTE *)this + 6216) & 1) == 0 )
    this->mpSnapshots[0]->mIDs[stat].mValue = (UFG::qSymbol)id->mUID;
}

// File Line: 1605
// RVA: 0x4A6740
bool __fastcall UFG::GameStatTracker::GetStat(
        UFG::GameStatTracker *this,
        UFG::GameStat::MapBoolStat stat,
        UFG::qSymbol *name)
{
  return UFG::PersistentData::MapBool::GetStatus(this->mpSnapshots[0]->mpMapBools[stat], name);
}

// File Line: 1606
// RVA: 0x4A65F0
__int64 __fastcall UFG::GameStatTracker::GetStat(
        UFG::GameStatTracker *this,
        UFG::GameStat::MapInt32Stat stat,
        UFG::qSymbol *name)
{
  UFG::PersistentData::MapInt *v3; // r10
  __int64 v4; // rax
  unsigned int size; // r9d
  UFG::PersistentData::KeyValue *p; // r10
  UFG::PersistentData::KeyValue *i; // rcx

  v3 = this->mpSnapshots[0]->mpMapInts[stat];
  v4 = 0i64;
  size = v3->mValues.size;
  if ( !v3->mValues.size )
    return 0i64;
  p = v3->mValues.p;
  for ( i = p; i->mKey.mUID != name->mUID; ++i )
  {
    v4 = (unsigned int)(v4 + 1);
    if ( (unsigned int)v4 >= size )
      return 0i64;
  }
  if ( (_DWORD)v4 == -1 )
    return 0i64;
  else
    return (unsigned int)p[v4].mIntValue;
}

// File Line: 1607
// RVA: 0x4A66D0
unsigned __int64 __fastcall UFG::GameStatTracker::GetStat(
        UFG::GameStatTracker *this,
        UFG::GameStat::MapUInt64Stat stat,
        UFG::qSymbol *name)
{
  UFG::PersistentData::MapUInt64 *v3; // r10
  __int64 v4; // rax
  unsigned int size; // r9d
  UFG::PersistentData::KeyValue64 *p; // r10
  UFG::PersistentData::KeyValue64 *i; // rcx

  v3 = this->mpSnapshots[0]->mpMapUInt64s[stat];
  v4 = 0i64;
  size = v3->mValues.size;
  if ( !v3->mValues.size )
    return 0i64;
  p = v3->mValues.p;
  for ( i = p; i->mKey.mUID != name->mUID; ++i )
  {
    v4 = (unsigned int)(v4 + 1);
    if ( (unsigned int)v4 >= size )
      return 0i64;
  }
  if ( (_DWORD)v4 == -1 )
    return 0i64;
  else
    return p[v4].mIntValue;
}

// File Line: 1608
// RVA: 0x4A6680
float __fastcall UFG::GameStatTracker::GetStat(
        UFG::GameStatTracker *this,
        UFG::GameStat::MapFloatStat stat,
        UFG::qSymbol *name)
{
  UFG::PersistentData::MapFloat *v3; // r10
  __int64 v4; // rax
  unsigned int size; // r9d
  UFG::PersistentData::KeyValue *p; // r10
  UFG::PersistentData::KeyValue *i; // rcx

  v3 = this->mpSnapshots[0]->mpMapFloats[stat];
  v4 = 0i64;
  size = v3->mValues.size;
  if ( !v3->mValues.size )
    return 0.0;
  p = v3->mValues.p;
  for ( i = p; i->mKey.mUID != name->mUID; ++i )
  {
    v4 = (unsigned int)(v4 + 1);
    if ( (unsigned int)v4 >= size )
      return 0.0;
  }
  if ( (_DWORD)v4 == -1 )
    return 0.0;
  else
    return p[v4].mFloatValue;
}

// File Line: 1610
// RVA: 0x4BD3E0
void __fastcall UFG::GameStatTracker::SetStat(
        UFG::GameStatTracker *this,
        UFG::GameStat::MapBoolStat stat,
        UFG::qSymbol *name,
        bool state)
{
  UFG::qSymbol keyname; // [rsp+40h] [rbp+8h] BYREF

  if ( (*((_BYTE *)this + 6216) & 1) == 0 )
  {
    UFG::PersistentData::MapBool::SetStatus(this->mpSnapshots[0]->mpMapBools[stat], name, state);
    if ( UFG::GameStatAction::PostStat::sIsEnabled )
    {
      keyname.mUID = name->mUID;
      UFG::GameStatAction::PostStat::AchieveMapBool(stat, (UFG::qSymbol)&keyname);
    }
  }
}

// File Line: 1618
// RVA: 0x4BD4B0
void __fastcall UFG::GameStatTracker::SetStat(
        UFG::GameStatTracker *this,
        UFG::GameStat::MapInt32Stat stat,
        UFG::qSymbol *name,
        int state)
{
  UFG::qSymbol mapid; // [rsp+40h] [rbp+8h] BYREF

  if ( (*((_BYTE *)this + 6216) & 1) == 0 )
  {
    UFG::PersistentData::MapInt::SetStatus(this->mpSnapshots[0]->mpMapInts[stat], name, state);
    if ( UFG::GameStatAction::PostStat::sIsEnabled )
    {
      mapid.mUID = name->mUID;
      UFG::GameStatAction::PostStat::AchieveMapInt(stat, (UFG::qSymbol)&mapid);
    }
  }
}

// File Line: 1626
// RVA: 0x4BD520
void __fastcall UFG::GameStatTracker::SetStat(
        UFG::GameStatTracker *this,
        UFG::GameStat::MapUInt64Stat stat,
        UFG::qSymbol *name,
        unsigned __int64 state)
{
  if ( (*((_BYTE *)this + 6216) & 1) == 0 )
    UFG::PersistentData::MapUInt64::SetStatus(this->mpSnapshots[0]->mpMapUInt64s[stat], name, state);
}

// File Line: 1634
// RVA: 0x4BD450
void __fastcall UFG::GameStatTracker::SetStat(
        UFG::GameStatTracker *this,
        UFG::GameStat::MapFloatStat stat,
        UFG::qSymbol *name,
        float state)
{
  if ( (*((_BYTE *)this + 6216) & 1) == 0 )
    UFG::PersistentData::MapFloat::SetStatus(this->mpSnapshots[0]->mpMapFloats[stat], name, state);
}

// File Line: 1642
// RVA: 0x494200
void __fastcall UFG::GameStatTracker::ApplyDelta(
        UFG::GameStatTracker *this,
        UFG::GameStat::MapInt32Stat stat,
        UFG::qSymbol *name,
        int delta)
{
  UFG::qSymbol mapid; // [rsp+40h] [rbp+8h] BYREF

  if ( (*((_BYTE *)this + 6216) & 1) == 0 )
  {
    UFG::PersistentData::MapInt::ApplyDelta(this->mpSnapshots[0]->mpMapInts[stat], name, delta);
    if ( UFG::GameStatAction::PostStat::sIsEnabled )
    {
      mapid.mUID = name->mUID;
      UFG::GameStatAction::PostStat::AchieveMapInt(stat, (UFG::qSymbol)&mapid);
    }
  }
}

// File Line: 1660
// RVA: 0x4941A0
void __fastcall UFG::GameStatTracker::ApplyDelta(
        UFG::GameStatTracker *this,
        UFG::GameStat::MapFloatStat stat,
        UFG::qSymbol *name,
        float delta)
{
  if ( (*((_BYTE *)this + 6216) & 1) == 0 )
    UFG::PersistentData::MapFloat::ApplyDelta(this->mpSnapshots[0]->mpMapFloats[stat], name, delta);
}

// File Line: 1669
// RVA: 0x4A47A0
UFG::PersistentData::MapBool *__fastcall UFG::GameStatTracker::GetMapBool(
        UFG::GameStatTracker *this,
        UFG::GameStat::MapBoolStat stat)
{
  return this->mpSnapshots[0]->mpMapBools[stat];
}

// File Line: 1670
// RVA: 0x4A5100
UFG::PersistentData::MapInt *__fastcall UFG::GameStatTracker::GetMapInt(
        UFG::GameStatTracker *this,
        UFG::GameStat::MapInt32Stat stat)
{
  return this->mpSnapshots[0]->mpMapInts[stat];
}

// File Line: 1672
// RVA: 0x4A4D20
UFG::PersistentData::MapFloat *__fastcall UFG::GameStatTracker::GetMapFloat(
        UFG::GameStatTracker *this,
        UFG::GameStat::MapFloatStat stat)
{
  return this->mpSnapshots[0]->mpMapFloats[stat];
}

// File Line: 1673
// RVA: 0x4A4780
UFG::PersistentData::MapBinary *__fastcall UFG::GameStatTracker::GetMapBinary(
        UFG::GameStatTracker *this,
        UFG::GameStat::MapBinaryStat stat)
{
  return this->mpSnapshots[0]->mpMapBinaries[stat];
}

// File Line: 1682
// RVA: 0x4BB660
char __fastcall UFG::GameStatTracker::SerializeSnapshotByFilter(
        UFG::GameStatTracker *this,
        unsigned int filterMask,
        unsigned int persistenceMask,
        int headerSize,
        char **ppBuffer,
        int *finalSize)
{
  __int64 v7; // rsi
  signed int v10; // edi
  UFG::allocator::free_link *v11; // rbx
  UFG::GameSnapshot *v12; // rcx

  v7 = headerSize;
  v10 = headerSize + UFG::GameSnapshot::CalculateSerializeSize(this->mpSnapshots[4], filterMask, persistenceMask);
  v11 = UFG::qMalloc(v10, "GameStatTracker", 0i64);
  UFG::qMemSet(v11, 0, v10);
  *ppBuffer = (char *)v11;
  *finalSize = v10;
  v12 = this->mpSnapshots[4];
  ppBuffer = (char **)((char *)v11 + v7);
  UFG::GameSnapshot::SerializeByFilter(v12, filterMask, persistenceMask, (char **)&ppBuffer);
  return 1;
}

// File Line: 1702
// RVA: 0x494D10
void __fastcall UFG::GameStatTracker::ApplySnapshotEffects(UFG::GameStatTracker *this, unsigned int *weaponOverride)
{
  signed __int16 m_Flags; // r8
  UFG::InventoryComponent *m_pComponent; // rbx
  UFG::SimComponent *v6; // rax
  AnimationGroupHandle *i; // rbx
  UFG::GameStatTracker *v8; // rbx
  UFG::GameSnapshot *v9; // rdx
  UFG::qSymbolUC *v10; // rax
  UFG::qSymbol weaponOverridea; // [rsp+40h] [rbp+8h] BYREF
  UFG::qSymbol *p_weaponOverridea; // [rsp+50h] [rbp+18h]

  *((_BYTE *)this + 6216) |= 1u;
  if ( LocalPlayer )
  {
    m_Flags = LocalPlayer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = (UFG::InventoryComponent *)LocalPlayer->m_Components.p[39].m_pComponent;
    }
    else
    {
      v6 = m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
         ? UFG::SimObjectGame::GetComponentOfTypeHK(LocalPlayer, UFG::InventoryComponent::_TypeUID)
         : UFG::SimObject::GetComponentOfType(LocalPlayer, UFG::InventoryComponent::_TypeUID);
      m_pComponent = (UFG::InventoryComponent *)v6;
    }
    if ( m_pComponent )
    {
      p_weaponOverridea = &weaponOverridea;
      weaponOverridea.mUID = *weaponOverride;
      UFG::GameStatAction::Inventory::RestoreEquipped(m_pComponent, (UFG::qSymbol)&weaponOverridea);
      UFG::GameStatAction::Inventory::RestoreItems(m_pComponent);
    }
  }
  *((_BYTE *)this + 6216) &= ~1u;
  UFG::GameStatAction::GameState::Start();
  UFG::GameStatAction::Player::ClampAndSetCombatMeter(0.0);
  if ( (_S19_1 & 1) == 0 )
  {
    _S19_1 |= 1u;
    UFG::ProgressionTracker::ProgressionTracker(&sProgressionTracker);
    atexit(UFG::ProgressionTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sProgressionTracker__);
  }
  UFG::ProgressionTracker::mspInstance = &sProgressionTracker;
  for ( i = (AnimationGroupHandle *)&stru_14240B9C0.mNode.mNext[-1];
        i != (AnimationGroupHandle *)&unk_14240B9B0;
        i = (AnimationGroupHandle *)&i->UFG::qNode<AnimationGroupHandle,AnimationGroupHandleContainer>::mNext[-1] )
  {
    AnimationGroupHandle::Unbind(i);
  }
  unk_14240B9D0 = 0;
  UFG::qList<AnimationGroupHandle,AnimationGroupHandleContainer,1,0>::DeleteNodes(&stru_14240B9C0);
  v8 = &sGameStatTracker;
  if ( (_S12_6 & 1) == 0 )
  {
    _S12_6 |= 1u;
    UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
    atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
  }
  if ( UFG::GameStatTracker::mspInstance )
    v8 = UFG::GameStatTracker::mspInstance;
  UFG::GameStatTracker::mspInstance = v8;
  v9 = v8->mpSnapshots[0];
  if ( v9->mStrings[6].mValue.mLength )
  {
    v10 = UFG::qSymbolUC::create_from_string((UFG::qSymbolUC *)&weaponOverridea, v9->mStrings[6].mValue.mData);
    AnimationGroupHandleContainer::Add(
      (AnimationGroupHandleContainer *)&stru_14240B9C0,
      v10,
      eANIM_PRIORITY_CHARACTER_FLAVOUR);
    AnimationGroupHandleContainer::Bind((AnimationGroupHandleContainer *)&stru_14240B9C0);
  }
}

// File Line: 1733
// RVA: 0x4B6F20
__int64 __fastcall UFG::GameStatTracker::ResetFromLoadedBuffer(
        UFG::GameStatTracker *this,
        int offset,
        char *buffer,
        unsigned int bufferSize)
{
  __int64 v5; // r14
  UFG::allocator::free_link *v7; // rax
  UFG::GameSnapshot *v8; // rax
  UFG::GameSnapshot *v9; // rbx
  UFG::GameSnapshot *v10; // rdi
  unsigned __int8 v11; // bl
  UFG::OSuiteLeaderboardManager *v12; // rax

  v5 = offset;
  v7 = UFG::qMalloc(0x10F8ui64, "GameStatTracker", 0i64);
  if ( v7 )
  {
    UFG::GameSnapshot::GameSnapshot((UFG::GameSnapshot *)v7);
    v9 = v8;
  }
  else
  {
    v9 = 0i64;
  }
  UFG::GameSnapshot::CommitByFilter(v9, this->mpSnapshots[0], 4u, 2u, 0);
  v10 = this->mpSnapshots[0];
  if ( v10 )
  {
    UFG::GameSnapshot::~GameSnapshot(this->mpSnapshots[0]);
    operator delete[](v10);
  }
  this->mpSnapshots[0] = v9;
  v11 = UFG::GameSnapshot::DeserializeByFilter(v9, 0xFFFFFFF8, 2u, &buffer[v5]);
  if ( (_S19_1 & 1) == 0 )
  {
    _S19_1 |= 1u;
    UFG::ProgressionTracker::ProgressionTracker(&sProgressionTracker);
    atexit(UFG::ProgressionTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sProgressionTracker__);
  }
  UFG::ProgressionTracker::mspInstance = &sProgressionTracker;
  unk_14240B9A8 = 0;
  unk_14240B6E8 = 0;
  UFG::GameStatAction::Snapshot::Initialize();
  UFG::GameStatAction::TemporaryData::Update();
  v12 = UFG::OSuiteLeaderboardManager::Instance();
  UFG::OSuiteLeaderboardManager::ResetStatSumsOnLoad(v12);
  return v11;
}

// File Line: 1759
// RVA: 0x4BF700
void __fastcall UFG::GameStatTracker::StartGameStatTimers(UFG::GameStatTracker *this)
{
  UFG::SimpleTimer::Resume(&this->mpSnapshots[0]->mTimes[2].mTimer);
  UFG::SimpleTimer::Resume(&this->mpSnapshots[0]->mTimes[18].mTimer);
  UFG::SimpleTimer::Resume(&this->mpSnapshots[0]->mTimes[4].mTimer);
  UFG::SimpleTimer::Resume(&this->mpSnapshots[0]->mTimes[19].mTimer);
  UFG::SimpleTimer::Resume(&this->mSessionTimer);
}

// File Line: 1768
// RVA: 0x4B2410
void __fastcall UFG::GameStatTracker::PauseGameStatTimers(UFG::GameStatTracker *this)
{
  UFG::SimpleTimer::Stop(&this->mpSnapshots[0]->mTimes[2].mTimer);
  UFG::SimpleTimer::Stop(&this->mpSnapshots[0]->mTimes[18].mTimer);
  UFG::SimpleTimer::Stop(&this->mpSnapshots[0]->mTimes[4].mTimer);
  UFG::SimpleTimer::Stop(&this->mSessionTimer);
}

// File Line: 1776
// RVA: 0x4AA7F0
void __fastcall UFG::GameStatTracker::HandleZoneLayoutEvent(UFG::Event *event)
{
  unsigned int CurrentZone; // eax

  if ( (unsigned int)UFG::FlowController::GetCurrentState(&UFG::gFlowController) == uidGameStateInGame_9 )
  {
    CurrentZone = UFG::ZoneTag::GetCurrentZone();
    UFG::GameStatAction::World::RegisterZone(CurrentZone);
  }
}

