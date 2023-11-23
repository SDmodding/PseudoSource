// File Line: 33
// RVA: 0x328E70
void __fastcall UFG::InitFixedArrayFromPropertySet<UFG::qFixedArray<UFG::GroupManager::Restriction,8>,UFG::GroupManager::Restriction>(
        const char *pContext,
        UFG::qFixedArray<UFG::GroupManager::Restriction,8> *theArray,
        UFG::qPropertySet *pPropertySet,
        UFG::qArray<unsigned long,0> *symList)
{
  UFG::qPropertyList *v7; // rax
  UFG::qPropertyList *v8; // rbp
  unsigned int mNumElements; // edi
  unsigned int i; // ebx
  char *ValuePtr; // rax
  __int64 v12; // rcx
  UFG::qPropertySet *v13; // rdx
  __int64 size; // rax
  char *v15; // rax
  char *v16; // rax

  if ( pPropertySet )
  {
    v7 = UFG::qPropertySet::Get<UFG::qPropertyList>(pPropertySet, symList, DEPTH_RECURSE);
    v8 = v7;
    if ( v7 )
    {
      mNumElements = v7->mNumElements;
      if ( mNumElements > 8 )
      {
        UFG::qPrintf("WARNING: %s: Too many elements: %d max: %d\n", pContext, mNumElements, 8i64);
        mNumElements = 8;
      }
      for ( i = 0; i < mNumElements; ++i )
      {
        ValuePtr = UFG::qPropertyList::GetValuePtr(v8, 0x1Au, i);
        if ( ValuePtr && (v12 = *(_QWORD *)ValuePtr) != 0 && (v13 = (UFG::qPropertySet *)&ValuePtr[v12]) != 0i64 )
        {
          size = theArray->size;
          theArray->size = size + 1;
          UFG::GroupManager::Restriction::InitFromPropertySet(&theArray->p[size], v13);
        }
        else
        {
          UFG::qPrintf("WARNING: %s: Property set not found for index: %d\n", pContext, i);
        }
      }
    }
    else
    {
      v15 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)symList);
      UFG::qPrintf("WARNING: %s: Property list not found: %s\n", pContext, v15);
    }
  }
  else
  {
    v16 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)symList);
    UFG::qPrintf("WARNING: %s: Property set not found for list: %s\n", pContext, v16);
  }
}

// File Line: 81
// RVA: 0x332970
void __fastcall UFG::GroupManager::ValidatedPed::ValidatedPed(UFG::GroupManager::ValidatedPed *this)
{
  this->mInfo = 0i64;
  this->mGroupComponent = 0i64;
  this->mGender.mUID = -1;
  this->mPropertySet = 0i64;
}

// File Line: 85
// RVA: 0x366940
char __fastcall UFG::GroupManager::ValidatedPed::Init(
        UFG::GroupManager::ValidatedPed *this,
        UFG::PedSpawningInfo *pPed)
{
  UFG::GroupComponent *mGroupComponent; // rax
  UFG::qSymbol *PropertySetName; // rax
  UFG::qPropertySet *PropertySet; // rax
  UFG::qPropertySet *v7; // rdx
  UFG::SimObjectCVBase *m_pPointer; // rcx
  unsigned int mUID; // ebx
  UFG::SimObjectCharacterPropertiesComponent *v10; // rcx
  UFG::qStaticSymbol *v11; // rax
  UFG::qPropertySet *ComponentData; // rax
  UFG::qSymbol result; // [rsp+38h] [rbp+10h] BYREF

  if ( !pPed )
    return 0;
  mGroupComponent = pPed->mGroupComponent;
  this->mGroupComponent = mGroupComponent;
  if ( !mGroupComponent )
    return 0;
  this->mInfo = pPed;
  PropertySetName = UFG::PedSpawningInfo::GetPropertySetName(pPed, &result);
  PropertySet = UFG::PropertySetManager::FindPropertySet(PropertySetName);
  this->mPropertySet = PropertySet;
  if ( !PropertySet )
    return 0;
  m_pPointer = (UFG::SimObjectCVBase *)pPed->mSimObjectPtr.m_pPointer;
  mUID = UFG::gNullQSymbol.mUID;
  if ( !m_pPointer )
    goto LABEL_12;
  v10 = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectCharacterPropertiesComponent>(m_pPointer);
  if ( v10 )
  {
    v7 = (UFG::qPropertySet *)&qSymbol_Male;
    v11 = &qSymbol_Female;
    if ( v10->m_eGender == eGENDER_MALE )
      v11 = &qSymbol_Male;
    mUID = v11->mUID;
  }
  if ( mUID == UFG::gNullQSymbol.mUID )
  {
LABEL_12:
    ComponentData = UFG::PropertySetManager::GetComponentDataPtr<component_CharacterProperties>(
                      (UFG::PropertySetManager *)this->mPropertySet,
                      v7);
    if ( ComponentData )
      mUID = HIDWORD(ComponentData->mParents.mOffset);
    if ( mUID == UFG::gNullQSymbol.mUID )
      return 0;
  }
  this->mGender.mUID = mUID;
  return 1;
}

// File Line: 140
// RVA: 0x331EB0
void __fastcall UFG::GroupManager::SpawnTask::SpawnTask(UFG::GroupManager::SpawnTask *this)
{
  this->mProfile = 0i64;
  this->mFormation.mUID = -1;
  this->mWeight = 0.0;
  *(_QWORD *)&this->mIndex = 0i64;
  this->mTaskCompletionScore = 0.0;
  *(_QWORD *)&this->mUseDifferentGenders = 2i64;
}

// File Line: 148
// RVA: 0x3686B0
void __fastcall UFG::GroupManager::SpawnTask::InitFromPropertySet(
        UFG::GroupManager::SpawnTask *this,
        UFG::qPropertySet *pPropertySet)
{
  UFG::qArray<unsigned long,0> *v4; // rax
  UFG::qArray<unsigned long,0> *v5; // rax
  UFG::qArray<unsigned long,0> *v6; // rax
  bool *v7; // rax
  UFG::qSymbol result; // [rsp+30h] [rbp+8h] BYREF

  v4 = (UFG::qArray<unsigned long,0> *)UFG::qSymbol::create_from_string(&result, "Formation");
  this->mFormation = (UFG::qSymbol)UFG::qPropertySet::Get<UFG::qSymbol>(pPropertySet, v4, DEPTH_RECURSE)->mUID;
  v5 = (UFG::qArray<unsigned long,0> *)UFG::qSymbol::create_from_string(&result, "Weight");
  this->mWeight = *UFG::qPropertySet::Get<float>(pPropertySet, v5, DEPTH_RECURSE);
  v6 = (UFG::qArray<unsigned long,0> *)UFG::qSymbol::create_from_string(&result, "UseDifferentGenders");
  v7 = UFG::qPropertySet::Get<bool>(pPropertySet, v6, DEPTH_RECURSE);
  if ( v7 )
    this->mUseDifferentGenders = *v7;
  else
    this->mUseDifferentGenders = OptionalBool_DontCare;
}

// File Line: 165
// RVA: 0x388380
__int64 __fastcall UFG::GroupManager::SpawnTask::Sort(float *a, float *b)
{
  float v2; // xmm0_4
  float v3; // xmm1_4
  float v5; // xmm0_4
  float v6; // xmm1_4
  unsigned int v7; // r8d
  unsigned int v8; // ecx

  v2 = a[7];
  v3 = b[7];
  if ( v2 < v3 )
    return 0xFFFFFFFFi64;
  if ( v2 > v3 )
    return 1i64;
  v5 = a[8];
  v6 = b[8];
  if ( v5 < v6 )
    return 0xFFFFFFFFi64;
  if ( v5 > v6 )
    return 1i64;
  v7 = *((_DWORD *)a + 6);
  v8 = *((_DWORD *)b + 6);
  if ( v7 < v8 )
    return 0xFFFFFFFFi64;
  return v7 > v8;
}

// File Line: 242
// RVA: 0x36CE70
char __fastcall UFG::GroupManager::SpawnTask::JoinGroup(
        UFG::GroupManager::SpawnTask *this,
        UFG::GroupManager::ValidatedPed *ped,
        UFG::qFixedArray<UFG::GroupManager::ValidatedPed,10> *closePeds)
{
  unsigned int mUID; // edx
  UFG::PedFormationProfile *v7; // rax
  UFG::PedFormationProfile *v8; // rsi
  unsigned int mMaxFollowers; // r15d
  UFG::GroupComponent *v11; // rbx
  unsigned int v12; // r9d
  unsigned int size; // r11d
  UFG::GroupManager::OptionalBool mUseDifferentGenders; // r10d
  __int64 v15; // rcx
  __int64 v16; // r8
  UFG::GroupComponent *mGroupComponent; // rdx
  UFG::PedFormationProfile *mFormationProfile; // rax
  __int64 v19; // rcx
  unsigned int j; // edi
  UFG::PedFormationProfile *v21; // rcx
  unsigned int v22; // eax
  UFG::GroupComponent *v23; // rdi
  unsigned int i; // ebx
  unsigned int v25; // [rsp+40h] [rbp-168h]
  __int64 ptr; // [rsp+48h] [rbp-160h] BYREF
  UFG::GroupComponent *leader[40]; // [rsp+50h] [rbp-158h]

  mUID = this->mFormation.mUID;
  if ( !mUID )
    return 0;
  v7 = (UFG::PedFormationProfile *)UFG::qBaseTreeRB::Get(&UFG::PedFormationManagerComponent::s_Profiles.mTree, mUID);
  v8 = v7;
  if ( !v7 || this->mWeight <= 0.0 )
    return 0;
  mMaxFollowers = v7->mMaxFollowers;
  if ( !mMaxFollowers )
  {
    UFG::GroupComponent::SetFormationProfile(ped->mGroupComponent, v7);
    ++this->mNumCompletedGroups;
    return 1;
  }
  v11 = 0i64;
  `eh vector constructor iterator(
    &ptr,
    0x20ui64,
    10,
    (void (__fastcall *)(void *))UFG::GroupManager::ValidatedPed::ValidatedPed);
  v25 = 0;
  v12 = 0;
  size = closePeds->size;
  if ( !closePeds->size )
  {
    LODWORD(v15) = 0;
    goto LABEL_30;
  }
  mUseDifferentGenders = this->mUseDifferentGenders;
  v15 = 0i64;
  do
  {
    v16 = v12;
    if ( mUseDifferentGenders == OptionalBool_DontCare
      || mUseDifferentGenders == OptionalBool_True && ped->mGender.mUID != closePeds->p[v16].mGender.mUID )
    {
      mGroupComponent = closePeds->p[v16].mGroupComponent;
      if ( mGroupComponent->mGroupLeader.mFormationProfile == v8 )
      {
        if ( !v11 || mGroupComponent->mGroupLeader.mFollowers.size > v11->mGroupLeader.mFollowers.size )
          v11 = closePeds->p[v16].mGroupComponent;
      }
      else if ( !mGroupComponent->mGroupLeader.mFormationProfile
             || (mFormationProfile = mGroupComponent->mGroupLeader.mFormationProfile) != 0i64
             && !mFormationProfile->mMaxFollowers )
      {
        v19 = 4 * v15;
        leader[v19 - 1] = (UFG::GroupComponent *)closePeds->p[v16].mInfo;
        leader[v19] = mGroupComponent;
        LODWORD(leader[v19 + 1]) = closePeds->p[v16].mGender.mUID;
        leader[v19 + 2] = (UFG::GroupComponent *)closePeds->p[v16].mPropertySet;
        v15 = ++v25;
      }
    }
    ++v12;
  }
  while ( v12 < size );
  if ( !v11 )
  {
LABEL_30:
    if ( (_DWORD)v15 && (unsigned int)v15 >= mMaxFollowers )
    {
      v23 = leader[0];
      if ( UFG::GroupComponent::JoinNewGroup(ped->mGroupComponent, leader[0], v8) )
      {
        for ( i = 1; i < v25; UFG::GroupComponent::JoinExistingGroup(leader[4 * i++], v23, v8) )
        {
          if ( UFG::GroupComponent::IsFormationFull(v23) )
            break;
        }
      }
      if ( !v23->mGroupLeader.mFormationProfile )
        goto LABEL_41;
      v21 = v23->mGroupLeader.mFormationProfile;
      if ( !v21 )
        goto LABEL_41;
      v22 = v23->mGroupLeader.mFollowers.size;
      goto LABEL_39;
    }
    goto LABEL_42;
  }
  if ( v11->mGroupLeader.mFollowers.size + (int)v15 + 1 >= mMaxFollowers )
  {
    if ( UFG::GroupComponent::JoinExistingGroup(ped->mGroupComponent, v11, v8) )
    {
      for ( j = 0; j < v25; UFG::GroupComponent::JoinExistingGroup(leader[4 * j++], v11, v8) )
      {
        if ( UFG::GroupComponent::IsFormationFull(v11) )
          break;
      }
    }
    if ( !v11->mGroupLeader.mFormationProfile )
      goto LABEL_41;
    v21 = v11->mGroupLeader.mFormationProfile;
    if ( !v21 )
      goto LABEL_41;
    v22 = v11->mGroupLeader.mFollowers.size;
LABEL_39:
    if ( v22 >= v21->mMaxFollowers )
      ++this->mNumCompletedGroups;
LABEL_41:
    `eh vector destructor iterator(&ptr, 0x20ui64, 10, (void (__fastcall *)(void *))_);
    return 1;
  }
LABEL_42:
  `eh vector destructor iterator(&ptr, 0x20ui64, 10, (void (__fastcall *)(void *))_);
  return 0;
}

// File Line: 354
// RVA: 0x331520
void __fastcall UFG::GroupManager::Profile::Profile(UFG::GroupManager::Profile *this)
{
  `eh vector constructor iterator(
    this->mSpawnTasks.p,
    0x28ui64,
    8,
    (void (__fastcall *)(void *))UFG::GroupManager::SpawnTask::SpawnTask);
  this->mSpawnTasks.size = 0;
  *(_QWORD *)&this->mMinGroupSpacing = 0i64;
  this->mDesiredGroupRatios.size = 0;
}

// File Line: 358
// RVA: 0x33A380
void __fastcall UFG::GroupManager::Profile::~Profile(UFG::GroupManager::Profile *this)
{
  this->mDesiredGroupRatios.size = 0;
  this->mSpawnTasks.size = 0;
  `eh vector destructor iterator(this->mSpawnTasks.p, 0x28ui64, 8, (void (__fastcall *)(void *))_);
}

// File Line: 362
// RVA: 0x3680E0
void __fastcall UFG::GroupManager::Profile::InitFromPropertySet(
        UFG::GroupManager::Profile *this,
        UFG::qPropertySet *pPropertySet)
{
  UFG::qArray<unsigned long,0> *v4; // rax
  UFG::qArray<unsigned long,0> *v5; // rax
  unsigned int v6; // ecx
  __int64 v7; // rax
  unsigned int v8; // esi
  float i; // xmm6_4
  __int64 v10; // rbx
  unsigned int mUID; // edx
  UFG::qBaseTreeRB *v12; // rax
  __int64 v13; // rax
  float mWeight; // xmm0_4
  unsigned int j; // ecx
  UFG::qSymbol result; // [rsp+50h] [rbp+8h] BYREF

  this->mSinglesNeeded = 0;
  v4 = (UFG::qArray<unsigned long,0> *)UFG::qSymbol::create_from_string(&result, "MinGroupSpacing");
  this->mMinGroupSpacing = *UFG::qPropertySet::Get<unsigned long>(pPropertySet, v4, DEPTH_RECURSE);
  v5 = (UFG::qArray<unsigned long,0> *)UFG::qSymbol::create_from_string(&result, "SpawnTasks");
  UFG::InitFixedArrayFromPropertySet<UFG::qFixedArray<UFG::GroupManager::SpawnTask,8>,UFG::GroupManager::SpawnTask>(
    "GroupManager::Profile::InitFromPropertySet",
    &this->mSpawnTasks,
    pPropertySet,
    v5);
  this->mDesiredGroupRatios.size = 5;
  v6 = 0;
  do
  {
    v7 = v6++;
    this->mDesiredGroupRatios.p[v7] = 0.0;
  }
  while ( v6 < this->mDesiredGroupRatios.size );
  v8 = 0;
  for ( i = 0.0; v8 < this->mSpawnTasks.size; i = i + this->mSpawnTasks.p[v10].mWeight )
  {
    v10 = v8;
    this->mSpawnTasks.p[v10].mProfile = this;
    this->mSpawnTasks.p[v10].mIndex = v8;
    mUID = this->mSpawnTasks.p[v8].mFormation.mUID;
    if ( mUID && (v12 = UFG::qBaseTreeRB::Get(&UFG::PedFormationManagerComponent::s_Profiles.mTree, mUID)) != 0i64 )
      v13 = *(&v12[12].mNULL.mUID + 1);
    else
      v13 = 0i64;
    mWeight = this->mSpawnTasks.p[v8++].mWeight;
    this->mDesiredGroupRatios.p[v13] = mWeight + this->mDesiredGroupRatios.p[v13];
  }
  for ( j = 0; j < this->mDesiredGroupRatios.size; ++j )
  {
    if ( i <= 0.0 )
      this->mDesiredGroupRatios.p[j] = 0.0;
    else
      this->mDesiredGroupRatios.p[j] = this->mDesiredGroupRatios.p[j] / i;
  }
}

// File Line: 416
// RVA: 0x362BD0
float __fastcall UFG::GroupManager::Profile::GetTaskCompletionRatio(
        UFG::GroupManager::Profile *this,
        UFG::GroupManager::SpawnTask *spawnTask)
{
  __int64 v2; // rdi
  int v3; // r14d
  float v5; // xmm6_4
  unsigned int mUID; // edx
  UFG::qBaseTreeRB *v8; // rax
  int v9; // ebp
  unsigned int v10; // edx
  UFG::qBaseTreeRB *v11; // rax
  int v12; // eax
  float v13; // xmm2_4
  float v14; // xmm1_4

  v2 = 0i64;
  v3 = 0;
  v5 = 0.0;
  if ( !this->mSpawnTasks.size )
    goto LABEL_15;
  do
  {
    mUID = this->mSpawnTasks.p[v2].mFormation.mUID;
    if ( mUID && (v8 = UFG::qBaseTreeRB::Get(&UFG::PedFormationManagerComponent::s_Profiles.mTree, mUID)) != 0i64 )
      v9 = *(&v8[12].mNULL.mUID + 1);
    else
      v9 = 0;
    v10 = spawnTask->mFormation.mUID;
    if ( v10 && (v11 = UFG::qBaseTreeRB::Get(&UFG::PedFormationManagerComponent::s_Profiles.mTree, v10)) != 0i64 )
      v12 = *(&v11[12].mNULL.mUID + 1);
    else
      v12 = 0;
    if ( v9 == v12 )
    {
      v3 += this->mSpawnTasks.p[v2].mNumCompletedGroups;
      v5 = v5 + this->mSpawnTasks.p[v2].mWeight;
    }
    v2 = (unsigned int)(v2 + 1);
  }
  while ( (unsigned int)v2 < this->mSpawnTasks.size );
  if ( v5 > 0.0 )
    v13 = spawnTask->mWeight / v5;
  else
LABEL_15:
    v13 = 0.0;
  if ( v3 )
    v14 = (float)(int)spawnTask->mNumCompletedGroups / (float)v3;
  else
    v14 = 0.0;
  if ( v13 <= 0.0 )
    return 0.0;
  else
    return v14 / v13;
}

// File Line: 440
// RVA: 0x36CBC0
char __fastcall UFG::GroupManager::Profile::JoinGroup(
        UFG::GroupManager::Profile *this,
        UFG::GroupManager::ValidatedPed *ped,
        UFG::qFixedArray<UFG::GroupManager::ValidatedPed,10> *closePeds)
{
  __int64 v3; // rsi
  UFG::qFixedArray<UFG::GroupManager::ValidatedPed,10> *v4; // r14
  unsigned int mUID; // edx
  char *v8; // rdi
  UFG::qBaseTreeRB *v9; // rax
  unsigned int v10; // ecx
  signed int size; // r11d
  int v12; // r12d
  int v13; // r8d
  float v14; // xmm2_4
  int v15; // r9d
  unsigned int v16; // ebp
  unsigned int v17; // eax
  __int64 v18; // r14
  unsigned int *v19; // rcx
  __int64 v20; // rdx
  float v21; // xmm1_4
  float v22; // xmm1_4
  UFG::GroupManager::Profile *v23; // rcx
  __int64 v24; // rdi
  unsigned int v25; // edx
  UFG::qBaseTreeRB *v26; // rax
  int v27; // esi
  UFG::GroupComponent *mGroupComponent; // rdi
  UFG::GroupComponent *v29; // rcx
  UFG::qSafePointer<UFG::GroupComponent,UFG::GroupComponent> *p_mLeader; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::GroupComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::GroupComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  unsigned int mSinglesNeeded; // eax
  unsigned int mMinGroupSpacing; // eax
  UFG::GroupComponent *m_pPointer; // rcx
  UFG::PedFormationProfile *mFormationProfile; // rax

  v3 = 0i64;
  v4 = closePeds;
  if ( this->mSpawnTasks.size )
  {
    do
    {
      mUID = this->mSpawnTasks.p[v3].mFormation.mUID;
      v8 = (char *)this + 40 * v3;
      if ( mUID && (v9 = UFG::qBaseTreeRB::Get(&UFG::PedFormationManagerComponent::s_Profiles.mTree, mUID)) != 0i64 )
        v10 = *(&v9[12].mNULL.mUID + 1);
      else
        v10 = 0;
      size = UFG::gpGroupManager->mGroupTotals.size;
      v12 = UFG::gpGroupManager->mGroupTotals.p[v10];
      v13 = 0;
      v14 = *(float *)(*((_QWORD *)v8 + 1) + 4i64 * v10 + 340);
      v15 = 0;
      v16 = 0;
      v17 = 0;
      v18 = 0i64;
      if ( size >= 2 )
      {
        v19 = &UFG::gpGroupManager->mGroupTotals.p[1];
        v20 = ((unsigned int)(size - 2) >> 1) + 1;
        v17 = 2 * v20;
        v18 = 2 * v20;
        do
        {
          v13 += *(v19 - 1);
          v15 += *v19;
          v19 += 2;
          --v20;
        }
        while ( v20 );
      }
      if ( v17 < size )
        v16 = UFG::gpGroupManager->mGroupTotals.p[v18];
      if ( v16 + v13 + v15 )
        v21 = (float)v12 / (float)(int)(v16 + v13 + v15);
      else
        v21 = 0.0;
      if ( v14 <= 0.0 )
        v22 = 0.0;
      else
        v22 = v21 / v14;
      v23 = (UFG::GroupManager::Profile *)*((_QWORD *)v8 + 1);
      *((float *)v8 + 9) = v22;
      v3 = (unsigned int)(v3 + 1);
      *((float *)v8 + 10) = UFG::GroupManager::Profile::GetTaskCompletionRatio(
                              v23,
                              (UFG::GroupManager::SpawnTask *)(v8 + 8));
    }
    while ( (unsigned int)v3 < this->mSpawnTasks.size );
    v4 = closePeds;
  }
  qsort(this->mSpawnTasks.p, this->mSpawnTasks.size, 0x28ui64, UFG::GroupManager::SpawnTask::Sort);
  v24 = 0i64;
  if ( this->mSpawnTasks.size )
  {
    while ( 1 )
    {
      v25 = this->mSpawnTasks.p[v24].mFormation.mUID;
      if ( v25 && (v26 = UFG::qBaseTreeRB::Get(&UFG::PedFormationManagerComponent::s_Profiles.mTree, v25)) != 0i64 )
        v27 = *(&v26[12].mNULL.mUID + 1);
      else
        v27 = 0;
      if ( (!this->mSinglesNeeded || !v27)
        && UFG::GroupManager::SpawnTask::JoinGroup(&this->mSpawnTasks.p[v24], ped, v4) )
      {
        break;
      }
      v24 = (unsigned int)(v24 + 1);
      if ( (unsigned int)v24 >= this->mSpawnTasks.size )
        goto LABEL_28;
    }
    if ( v27 )
    {
      m_pPointer = ped->mGroupComponent->mGroupFollower.mLeader.m_pPointer;
      if ( m_pPointer )
      {
        if ( m_pPointer->mGroupLeader.mFormationProfile )
        {
          mFormationProfile = m_pPointer->mGroupLeader.mFormationProfile;
          if ( mFormationProfile )
          {
            if ( m_pPointer->mGroupLeader.mFollowers.size >= mFormationProfile->mMaxFollowers )
            {
              mMinGroupSpacing = this->mMinGroupSpacing;
              goto LABEL_37;
            }
          }
        }
      }
      return 1;
    }
  }
  else
  {
LABEL_28:
    mGroupComponent = ped->mGroupComponent;
    v29 = mGroupComponent->mGroupFollower.mLeader.m_pPointer;
    if ( v29 )
    {
      UFG::GroupLeader::Unregister(&v29->mGroupLeader, ped->mGroupComponent);
      p_mLeader = &mGroupComponent->mGroupFollower.mLeader;
      if ( mGroupComponent->mGroupFollower.mLeader.m_pPointer )
      {
        mPrev = p_mLeader->mPrev;
        mNext = mGroupComponent->mGroupFollower.mLeader.mNext;
        mPrev->mNext = mNext;
        mNext->mPrev = mPrev;
        p_mLeader->mPrev = p_mLeader;
        mGroupComponent->mGroupFollower.mLeader.mNext = &mGroupComponent->mGroupFollower.mLeader;
      }
      mGroupComponent->mGroupFollower.mLeader.m_pPointer = 0i64;
    }
    UFG::GroupLeader::Reset(&mGroupComponent->mGroupLeader);
    mGroupComponent->mFlags = 1;
    if ( mGroupComponent->mGroupLeader.mFormationProfile != &ptr )
    {
      UFG::GroupLeader::Reset(&mGroupComponent->mGroupLeader);
      mGroupComponent->mGroupLeader.mFormationProfile = &ptr;
      ++UFG::gpGroupManager->mGroupTotals.p[0];
    }
    mGroupComponent->mFlags |= 1u;
  }
  mSinglesNeeded = this->mSinglesNeeded;
  if ( mSinglesNeeded )
  {
    mMinGroupSpacing = mSinglesNeeded - 1;
LABEL_37:
    this->mSinglesNeeded = mMinGroupSpacing;
  }
  return 1;
}

// File Line: 513
// RVA: 0x3317B0
void __fastcall UFG::GroupManager::Restriction::Restriction(UFG::GroupManager::Restriction *this)
{
  this->mClassType.mUID = -1;
  this->mIsSameClass = OptionalBool_DontCare;
}

// File Line: 521
// RVA: 0x368240
void __fastcall UFG::GroupManager::Restriction::InitFromPropertySet(
        UFG::GroupManager::Restriction *this,
        UFG::qPropertySet *pPropertySet)
{
  UFG::qArray<unsigned long,0> *v4; // rax
  UFG::qArray<unsigned long,0> *v5; // rax
  bool *v6; // rax
  UFG::qSymbol result; // [rsp+30h] [rbp+8h] BYREF

  v4 = (UFG::qArray<unsigned long,0> *)UFG::qSymbol::create_from_string(&result, "ClassType");
  this->mClassType = (UFG::qSymbol)UFG::qPropertySet::Get<UFG::qSymbol>(pPropertySet, v4, DEPTH_RECURSE)->mUID;
  v5 = (UFG::qArray<unsigned long,0> *)UFG::qSymbol::create_from_string(&result, "IsSameClass");
  v6 = UFG::qPropertySet::Get<bool>(pPropertySet, v5, DEPTH_RECURSE);
  if ( v6 )
    this->mIsSameClass = *v6;
  else
    this->mIsSameClass = OptionalBool_DontCare;
}

// File Line: 530
// RVA: 0x3419F0
bool __fastcall UFG::GroupManager::Restriction::Allow(
        UFG::GroupManager::Restriction *this,
        UFG::GroupManager::ValidatedPed *pedA,
        UFG::GroupManager::ValidatedPed *pedB)
{
  bool v5; // bp
  bool v6; // al
  char IsClassType; // bl
  char v8; // al

  v5 = pedA->mInfo == pedB->mInfo;
  if ( this->mIsSameClass == OptionalBool_DontCare )
  {
    v6 = 1;
    return !v5 && v6;
  }
  IsClassType = UFG::SimObjectUtility::IsClassType(pedA->mPropertySet, (UFG::qSymbol *)this);
  v8 = UFG::SimObjectUtility::IsClassType(pedB->mPropertySet, (UFG::qSymbol *)this);
  if ( IsClassType )
  {
    if ( !v8 )
    {
LABEL_5:
      v6 = 0;
      goto LABEL_6;
    }
  }
  else if ( v8 )
  {
    goto LABEL_5;
  }
  v6 = 1;
LABEL_6:
  if ( this->mIsSameClass == OptionalBool_False )
    v6 = !v6;
  return !v5 && v6;
}

// File Line: 560
// RVA: 0x32F4E0
void __fastcall UFG::GroupManager::GroupManager(UFG::GroupManager *this)
{
  `eh vector constructor iterator(
    this->mProfiles.p,
    0x168ui64,
    2,
    (void (__fastcall *)(void *))UFG::GroupManager::Profile::Profile);
  this->mProfiles.size = 0;
  `eh vector constructor iterator(
    this->mRestrictions.p,
    8ui64,
    8,
    (void (__fastcall *)(void *))UFG::GroupManager::Restriction::Restriction);
  this->mRestrictions.size = 0;
  this->mCurrentProfile = 0i64;
  this->mGroupTotals.size = 0;
  UFG::GroupManager::Init(this);
}

// File Line: 570
// RVA: 0x350EF0
void UFG::GroupManager::CreateInstance(void)
{
  UFG::allocator::free_link *v0; // rax
  UFG::GroupManager *v1; // rax

  v0 = UFG::qMalloc(0x340ui64, "GroupManager", 0i64);
  if ( v0 )
  {
    UFG::GroupManager::GroupManager((UFG::GroupManager *)v0);
    UFG::gpGroupManager = v1;
  }
  else
  {
    UFG::gpGroupManager = 0i64;
  }
}

// File Line: 577
// RVA: 0x360870
UFG::GroupManager *__fastcall UFG::GroupManager::GetInstance()
{
  return UFG::gpGroupManager;
}

// File Line: 583
// RVA: 0x365FD0
void __fastcall UFG::GroupManager::Init(UFG::GroupManager *this)
{
  UFG::qPropertySet *PropertySet; // rdi
  UFG::qArray<unsigned long,0> *v3; // rax
  UFG::qArray<unsigned long,0> *v4; // rax
  unsigned int v5; // eax
  __int64 v6; // rcx
  UFG::qSymbol result; // [rsp+30h] [rbp+8h] BYREF
  UFG::qSymbol v8; // [rsp+38h] [rbp+10h] BYREF

  UFG::qSymbol::create_from_string(&result, "default-formation-GroupManager");
  PropertySet = UFG::PropertySetManager::GetPropertySet(&result);
  v3 = (UFG::qArray<unsigned long,0> *)UFG::qSymbol::create_from_string(&v8, "Profiles");
  UFG::InitFixedArrayFromPropertySet<UFG::qFixedArray<UFG::GroupManager::Profile,2>,UFG::GroupManager::Profile>(
    "GroupManager::Profile::InitFromPropertySet",
    &this->mProfiles,
    PropertySet,
    v3);
  if ( this->mProfiles.size )
    this->mCurrentProfile = this->mProfiles.p;
  v4 = (UFG::qArray<unsigned long,0> *)UFG::qSymbol::create_from_string(&v8, "Restrictions");
  UFG::InitFixedArrayFromPropertySet<UFG::qFixedArray<UFG::GroupManager::Restriction,8>,UFG::GroupManager::Restriction>(
    "GroupManager::Profile::InitFromPropertySet",
    &this->mRestrictions,
    PropertySet,
    v4);
  this->mGroupTotals.size = 5;
  v5 = 0;
  do
  {
    v6 = v5++;
    this->mGroupTotals.p[v6] = 0;
  }
  while ( v5 < this->mGroupTotals.size );
}

// File Line: 646
// RVA: 0x3697E0
char __fastcall UFG::GroupManager::IsAllowed(
        UFG::GroupManager *this,
        UFG::GroupManager::ValidatedPed *newPed,
        UFG::GroupManager::ValidatedPed *closePed)
{
  UFG::GroupComponent *mGroupComponent; // rcx
  UFG::PedFormationProfile *mFormationProfile; // rdx
  unsigned int mMaxFollowers; // eax
  bool *v9; // rax
  bool *v10; // rax
  UFG::qSymbol *v11; // rax
  UFG::qStaticSymbol *v12; // rdi
  UFG::qStaticSymbol *v13; // rbx
  UFG::qSymbol *v14; // rax
  __int64 v15; // rbx

  if ( closePed->mInfo->mCharacterOccupantComponent.m_pSimComponent )
    return 0;
  mGroupComponent = closePed->mGroupComponent;
  if ( (mGroupComponent->mFlags & 1) == 0 )
    return 0;
  if ( mGroupComponent->mGroupFollower.mLeader.m_pPointer )
    return 0;
  mFormationProfile = mGroupComponent->mGroupLeader.mFormationProfile;
  if ( mFormationProfile )
  {
    mMaxFollowers = mFormationProfile->mMaxFollowers;
    if ( mGroupComponent->mGroupLeader.mFollowers.size >= mMaxFollowers )
    {
      if ( mMaxFollowers )
        return 0;
    }
  }
  v9 = UFG::qPropertySet::Get<bool>(
         newPed->mPropertySet,
         (UFG::qArray<unsigned long,0> *)&qSymbol_CanJoinGroup,
         DEPTH_RECURSE);
  if ( !v9 )
    return 0;
  if ( !*v9 )
    return 0;
  v10 = UFG::qPropertySet::Get<bool>(
          closePed->mPropertySet,
          (UFG::qArray<unsigned long,0> *)&qSymbol_CanJoinGroup,
          DEPTH_RECURSE);
  if ( !v10 || !*v10 )
    return 0;
  v11 = UFG::qPropertySet::Get<UFG::qSymbol>(
          closePed->mPropertySet,
          (UFG::qArray<unsigned long,0> *)&qSymbol_walkCycle,
          DEPTH_RECURSE);
  v12 = &qSymbol_Default;
  v13 = &qSymbol_Default;
  if ( v11 )
    v13 = (UFG::qStaticSymbol *)v11;
  v14 = UFG::qPropertySet::Get<UFG::qSymbol>(
          newPed->mPropertySet,
          (UFG::qArray<unsigned long,0> *)&qSymbol_walkCycle,
          DEPTH_RECURSE);
  if ( v14 )
    v12 = (UFG::qStaticSymbol *)v14;
  if ( v12->mUID == v13->mUID && !UFG::PedSpawningInfo::IsUsingPOI(closePed->mInfo, 0i64) )
  {
    v15 = 0i64;
    if ( !this->mRestrictions.size )
      return 1;
    while ( UFG::GroupManager::Restriction::Allow(&this->mRestrictions.p[v15], newPed, closePed) )
    {
      v15 = (unsigned int)(v15 + 1);
      if ( (unsigned int)v15 >= this->mRestrictions.size )
        return 1;
    }
  }
  return 0;
}

// File Line: 705
// RVA: 0x36C9E0
bool __fastcall UFG::GroupManager::JoinGroup(
        UFG::GroupManager *this,
        UFG::PedSpawningInfo *pPed,
        UFG::qFixedArray<UFG::PedSpawningInfo *,10> *closePeds)
{
  UFG::PedFormationProfile *mFormationProfile; // rcx
  unsigned int i; // ebx
  _OWORD *v7; // rcx
  UFG::GroupManager::Profile *mCurrentProfile; // rcx
  bool v9; // bl
  UFG::GroupManager::ValidatedPed closePed; // [rsp+30h] [rbp-B8h] BYREF
  UFG::GroupManager::ValidatedPed newPed; // [rsp+50h] [rbp-98h] BYREF
  _QWORD ptr[31]; // [rsp+70h] [rbp-78h] BYREF

  ptr[0] = -2i64;
  newPed.mInfo = 0i64;
  newPed.mGroupComponent = 0i64;
  newPed.mGender.mUID = -1;
  newPed.mPropertySet = 0i64;
  if ( UFG::GroupManager::ValidatedPed::Init(&newPed, pPed) )
  {
    if ( !newPed.mInfo->mCharacterOccupantComponent.m_pSimComponent
      && (newPed.mGroupComponent->mFlags & 1) != 0
      && !newPed.mGroupComponent->mGroupFollower.mLeader.m_pPointer )
    {
      mFormationProfile = newPed.mGroupComponent->mGroupLeader.mFormationProfile;
      if ( !mFormationProfile
        || newPed.mGroupComponent->mGroupLeader.mFollowers.size < mFormationProfile->mMaxFollowers
        || !mFormationProfile->mMaxFollowers )
      {
        `eh vector constructor iterator(
          ptr,
          0x20ui64,
          10,
          (void (__fastcall *)(void *))UFG::GroupManager::ValidatedPed::ValidatedPed);
        LODWORD(newPed.mPropertySet) = 0;
        for ( i = 0; i < closePeds->size; ++i )
        {
          closePed.mInfo = 0i64;
          closePed.mGroupComponent = 0i64;
          closePed.mGender.mUID = -1;
          closePed.mPropertySet = 0i64;
          if ( UFG::GroupManager::ValidatedPed::Init(&closePed, closePeds->p[i]) )
          {
            if ( UFG::GroupManager::IsAllowed(this, &newPed, &closePed) )
            {
              v7 = &ptr[4 * LODWORD(newPed.mPropertySet)];
              *(_QWORD *)v7 = closePed.mInfo;
              *((_QWORD *)v7 + 1) = closePed.mGroupComponent;
              *((_DWORD *)v7 + 4) = closePed.mGender.mUID;
              *((_QWORD *)v7 + 3) = closePed.mPropertySet;
              ++LODWORD(newPed.mPropertySet);
            }
          }
        }
        mCurrentProfile = this->mCurrentProfile;
        if ( mCurrentProfile )
        {
          v9 = UFG::GroupManager::Profile::JoinGroup(
                 mCurrentProfile,
                 &newPed,
                 (UFG::qFixedArray<UFG::GroupManager::ValidatedPed,10> *)&newPed.mPropertySet);
          LODWORD(newPed.mPropertySet) = 0;
          `eh vector destructor iterator(ptr, 0x20ui64, 10, (void (__fastcall *)(void *))_);
          return v9;
        }
        LODWORD(newPed.mPropertySet) = 0;
        `eh vector destructor iterator(ptr, 0x20ui64, 10, (void (__fastcall *)(void *))_);
      }
    }
  }
  return 0;
}

// File Line: 790
// RVA: 0x3619F0
__int64 __fastcall UFG::GroupManager::GetNumGroupPeds(UFG::GroupManager *this)
{
  signed int size; // esi
  int v2; // edx
  int v4; // r10d
  unsigned int v5; // ebx
  unsigned int v6; // edi
  __int64 v7; // r14
  int v8; // r8d
  unsigned int *v9; // r9
  unsigned int v10; // eax
  __int64 v11; // r11
  int v12; // ecx
  int v13; // eax

  size = this->mGroupTotals.size;
  v2 = 0;
  v4 = 0;
  v5 = 0;
  v6 = 0;
  v7 = 0i64;
  if ( size >= 2 )
  {
    v8 = 2;
    v9 = &this->mGroupTotals.p[1];
    v10 = ((unsigned int)(size - 2) >> 1) + 1;
    v11 = v10;
    v6 = 2 * v10;
    v7 = 2i64 * v10;
    do
    {
      v12 = *(v9 - 1);
      v9 += 2;
      v2 += (v8 - 1) * v12;
      v13 = v8 * *(v9 - 2);
      v8 += 2;
      v4 += v13;
      --v11;
    }
    while ( v11 );
  }
  if ( v6 < size )
    v5 = (v6 + 1) * this->mGroupTotals.p[v7];
  return v5 + v4 + v2;
}

// File Line: 802
// RVA: 0x361930
__int64 __fastcall UFG::GroupManager::GetNumGroupMembersToSpawn(UFG::GroupManager *this, int numPedsToSpawn)
{
  UFG::GroupManager::Profile *mCurrentProfile; // rdi
  float v3; // xmm6_4
  float v4; // xmm1_4
  __int64 result; // rax

  mCurrentProfile = this->mCurrentProfile;
  if ( !mCurrentProfile )
    return 0i64;
  v3 = (float)numPedsToSpawn;
  v4 = (float)((float)((float)(int)UFG::GroupManager::GetNumGroupPeds(this) + (float)numPedsToSpawn)
             * mCurrentProfile->mDesiredGroupRatios.p[0])
     - (float)(int)this->mGroupTotals.p[0];
  if ( v4 <= 1.0 )
    v4 = *(float *)&FLOAT_1_0;
  if ( v4 >= v3 )
    v4 = v3;
  result = (unsigned int)(int)(float)(v3 - v4);
  if ( (int)result < 2 )
    return 0i64;
  return result;
}

