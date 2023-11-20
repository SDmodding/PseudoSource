// File Line: 33
// RVA: 0x328E70
void __fastcall UFG::InitFixedArrayFromPropertySet<UFG::qFixedArray<UFG::GroupManager::Restriction,8>,UFG::GroupManager::Restriction>(const char *pContext, UFG::qFixedArray<UFG::GroupManager::Restriction,8> *theArray, UFG::qPropertySet *pPropertySet, UFG::qSymbol *symList)
{
  UFG::qSymbol *v4; // rbx
  UFG::qFixedArray<UFG::GroupManager::Restriction,8> *v5; // r14
  const char *v6; // rsi
  UFG::qPropertyList *v7; // rax
  UFG::qPropertyList *v8; // rbp
  unsigned int v9; // edi
  unsigned int v10; // ebx
  char *v11; // rax
  __int64 v12; // rcx
  UFG::qPropertySet *v13; // rdx
  __int64 v14; // rax
  char *v15; // rax
  char *v16; // rax

  v4 = symList;
  v5 = theArray;
  v6 = pContext;
  if ( pPropertySet )
  {
    v7 = UFG::qPropertySet::Get<UFG::qPropertyList>(pPropertySet, symList, DEPTH_RECURSE);
    v8 = v7;
    if ( v7 )
    {
      v9 = v7->mNumElements;
      if ( v9 > 8 )
      {
        UFG::qPrintf("WARNING: %s: Too many elements: %d max: %d\n", v6, v9, 8i64);
        v9 = 8;
      }
      v10 = 0;
      if ( v9 )
      {
        do
        {
          v11 = UFG::qPropertyList::GetValuePtr(v8, 0x1Au, v10);
          if ( v11 && (v12 = *(_QWORD *)v11) != 0 && (v13 = (UFG::qPropertySet *)&v11[v12]) != 0i64 )
          {
            v14 = v5->size;
            v5->size = v14 + 1;
            UFG::GroupManager::Restriction::InitFromPropertySet(&v5->p[v14], v13);
          }
          else
          {
            UFG::qPrintf("WARNING: %s: Property set not found for index: %d\n", v6, v10);
          }
          ++v10;
        }
        while ( v10 < v9 );
      }
    }
    else
    {
      v15 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)v4);
      UFG::qPrintf("WARNING: %s: Property list not found: %s\n", v6, v15);
    }
  }
  else
  {
    v16 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)symList);
    UFG::qPrintf("WARNING: %s: Property set not found for list: %s\n", v6, v16);
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
char __fastcall UFG::GroupManager::ValidatedPed::Init(UFG::GroupManager::ValidatedPed *this, UFG::PedSpawningInfo *pPed)
{
  UFG::PedSpawningInfo *v2; // rdi
  UFG::GroupManager::ValidatedPed *v3; // rsi
  UFG::GroupComponent *v4; // rax
  UFG::qSymbol *v5; // rax
  UFG::qPropertySet *v6; // rax
  UFG::qPropertySet *v7; // rdx
  UFG::SimObjectCVBase *v8; // rcx
  unsigned int v9; // ebx
  UFG::SimObjectCharacterPropertiesComponent *v10; // rcx
  UFG::qStaticSymbol *v11; // rax
  UFG::qPropertySet *v12; // rax
  UFG::qSymbol result; // [rsp+38h] [rbp+10h]

  v2 = pPed;
  v3 = this;
  if ( !pPed )
    return 0;
  v4 = pPed->mGroupComponent;
  this->mGroupComponent = v4;
  if ( !v4 )
    return 0;
  this->mInfo = pPed;
  v5 = UFG::PedSpawningInfo::GetPropertySetName(pPed, &result);
  v6 = UFG::PropertySetManager::FindPropertySet(v5);
  v3->mPropertySet = v6;
  if ( !v6 )
    return 0;
  v8 = (UFG::SimObjectCVBase *)v2->mSimObjectPtr.m_pPointer;
  v9 = UFG::gNullQSymbol.mUID;
  if ( !v8 )
    goto LABEL_17;
  v10 = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectCharacterPropertiesComponent>(v8);
  if ( v10 )
  {
    v7 = (UFG::qPropertySet *)&qSymbol_Male;
    v11 = &qSymbol_Female;
    if ( v10->m_eGender == 1 )
      v11 = &qSymbol_Male;
    v9 = v11->mUID;
  }
  if ( v9 == UFG::gNullQSymbol.mUID )
  {
LABEL_17:
    v12 = UFG::PropertySetManager::GetComponentDataPtr<component_CharacterProperties>(
            (UFG::PropertySetManager *)v3->mPropertySet,
            v7);
    if ( v12 )
      v9 = HIDWORD(v12->mParents.mOffset);
    if ( v9 == UFG::gNullQSymbol.mUID )
      return 0;
  }
  v3->mGender.mUID = v9;
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
void __fastcall UFG::GroupManager::SpawnTask::InitFromPropertySet(UFG::GroupManager::SpawnTask *this, UFG::qPropertySet *pPropertySet)
{
  UFG::qPropertySet *v2; // rbx
  UFG::GroupManager::SpawnTask *v3; // rdi
  UFG::qSymbol *v4; // rax
  UFG::qSymbol *v5; // rax
  UFG::qSymbol *v6; // rax
  bool *v7; // rax
  UFG::qSymbol result; // [rsp+30h] [rbp+8h]

  v2 = pPropertySet;
  v3 = this;
  v4 = UFG::qSymbol::create_from_string(&result, "Formation");
  v3->mFormation = (UFG::qSymbol)UFG::qPropertySet::Get<UFG::qSymbol>(v2, v4, DEPTH_RECURSE)->mUID;
  v5 = UFG::qSymbol::create_from_string(&result, "Weight");
  v3->mWeight = *UFG::qPropertySet::Get<float>(v2, v5, DEPTH_RECURSE);
  v6 = UFG::qSymbol::create_from_string(&result, "UseDifferentGenders");
  v7 = UFG::qPropertySet::Get<bool>(v2, v6, DEPTH_RECURSE);
  if ( v7 )
    v3->mUseDifferentGenders = *v7 != 0;
  else
    v3->mUseDifferentGenders = 2;
}

// File Line: 165
// RVA: 0x388380
char __fastcall UFG::GroupManager::SpawnTask::Sort(const void *a, const void *b)
{
  float v2; // xmm0_4
  float v3; // xmm1_4
  float v5; // xmm0_4
  float v6; // xmm1_4
  unsigned int v7; // er8
  unsigned int v8; // ecx

  v2 = *((float *)a + 7);
  v3 = *((float *)b + 7);
  if ( v2 < v3 )
    return -1;
  if ( v2 > v3 )
    return 1;
  v5 = *((float *)a + 8);
  v6 = *((float *)b + 8);
  if ( v5 < v6 )
    return -1;
  if ( v5 > v6 )
    return 1;
  v7 = *((_DWORD *)a + 6);
  v8 = *((_DWORD *)b + 6);
  if ( v7 < v8 )
    return -1;
  return v7 > v8;
}

// File Line: 242
// RVA: 0x36CE70
char __fastcall UFG::GroupManager::SpawnTask::JoinGroup(UFG::GroupManager::SpawnTask *this, UFG::GroupManager::ValidatedPed *ped, UFG::qFixedArray<UFG::GroupManager::ValidatedPed,10> *closePeds)
{
  UFG::qFixedArray<UFG::GroupManager::ValidatedPed,10> *v3; // rdi
  UFG::GroupManager::ValidatedPed *v4; // r14
  UFG::GroupManager::SpawnTask *v5; // rbp
  unsigned int v6; // edx
  UFG::PedFormationProfile *v7; // rax
  UFG::PedFormationProfile *v8; // rsi
  unsigned int v9; // er15
  UFG::GroupComponent *v11; // rbx
  unsigned int v12; // er9
  unsigned int v13; // er11
  UFG::GroupManager::OptionalBool v14; // er10
  __int64 v15; // rcx
  signed __int64 v16; // r8
  UFG::GroupComponent *v17; // rdx
  UFG::PedFormationProfile *v18; // rax
  unsigned __int64 v19; // rcx
  unsigned int v20; // edi
  UFG::PedFormationProfile *v21; // rcx
  unsigned int v22; // eax
  UFG::GroupComponent *v23; // rdi
  unsigned int i; // ebx
  unsigned int v25; // [rsp+40h] [rbp-168h]
  __int64 ptr; // [rsp+48h] [rbp-160h]
  UFG::GroupComponent *leader; // [rsp+50h] [rbp-158h]
  int v28[2]; // [rsp+58h] [rbp-150h]
  __int64 v29[38]; // [rsp+60h] [rbp-148h]

  v3 = closePeds;
  v4 = ped;
  v5 = this;
  v6 = this->mFormation.mUID;
  if ( !v6 )
    return 0;
  v7 = (UFG::PedFormationProfile *)UFG::qBaseTreeRB::Get(&UFG::PedFormationManagerComponent::s_Profiles.mTree, v6);
  v8 = v7;
  if ( !v7 || v5->mWeight <= 0.0 )
    return 0;
  v9 = v7->mMaxFollowers;
  if ( !v9 )
  {
    UFG::GroupComponent::SetFormationProfile(v4->mGroupComponent, v7);
    ++v5->mNumCompletedGroups;
    return 1;
  }
  v11 = 0i64;
  `eh vector constructor iterator'(
    &ptr,
    0x20ui64,
    10,
    (void (__fastcall *)(void *))UFG::GroupManager::ValidatedPed::ValidatedPed);
  v25 = 0;
  v12 = 0;
  v13 = v3->size;
  if ( !v3->size )
  {
    LODWORD(v15) = 0;
    goto LABEL_30;
  }
  v14 = v5->mUseDifferentGenders;
  v15 = 0i64;
  do
  {
    v16 = v12;
    if ( v14 == 2 || v14 == 1 && v4->mGender.mUID != v3->p[v16].mGender.mUID )
    {
      v17 = v3->p[v16].mGroupComponent;
      if ( v17->mGroupLeader.mFormationProfile == v8 )
      {
        if ( !v11 || v17->mGroupLeader.mFollowers.size > v11->mGroupLeader.mFollowers.size )
          v11 = v3->p[v16].mGroupComponent;
      }
      else if ( !v17->mGroupLeader.mFormationProfile
             || (v18 = v17->mGroupLeader.mFormationProfile) != 0i64 && !v18->mMaxFollowers )
      {
        v19 = 32 * v15;
        *(__int64 *)((char *)&ptr + v19) = (__int64)v3->p[v16].mInfo;
        *(UFG::GroupComponent **)((char *)&leader + v19) = v17;
        v28[v19 / 4] = v3->p[v16].mGender.mUID;
        v29[v19 / 8] = (__int64)v3->p[v16].mPropertySet;
        v15 = v25++ + 1;
      }
    }
    ++v12;
  }
  while ( v12 < v13 );
  if ( !v11 )
  {
LABEL_30:
    if ( (_DWORD)v15 && (unsigned int)v15 >= v9 )
    {
      v23 = leader;
      if ( UFG::GroupComponent::JoinNewGroup(v4->mGroupComponent, leader, v8) )
      {
        for ( i = 1; i < v25; UFG::GroupComponent::JoinExistingGroup(*(&leader + 4 * i++), v23, v8) )
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
  if ( v11->mGroupLeader.mFollowers.size + (signed int)v15 + 1 >= v9 )
  {
    if ( UFG::GroupComponent::JoinExistingGroup(v4->mGroupComponent, v11, v8) )
    {
      v20 = 0;
      if ( v25 )
      {
        do
        {
          if ( UFG::GroupComponent::IsFormationFull(v11) )
            break;
          UFG::GroupComponent::JoinExistingGroup(*(&leader + 4 * v20++), v11, v8);
        }
        while ( v20 < v25 );
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
      ++v5->mNumCompletedGroups;
LABEL_41:
    `eh vector destructor iterator'(&ptr, 0x20ui64, 10, (void (__fastcall *)(void *))_);
    return 1;
  }
LABEL_42:
  `eh vector destructor iterator'(&ptr, 0x20ui64, 10, (void (__fastcall *)(void *))_);
  return 0;
}

// File Line: 354
// RVA: 0x331520
void __fastcall UFG::GroupManager::Profile::Profile(UFG::GroupManager::Profile *this)
{
  UFG::GroupManager::Profile *v1; // rbx

  v1 = this;
  `eh vector constructor iterator'(
    this->mSpawnTasks.p,
    0x28ui64,
    8,
    (void (__fastcall *)(void *))UFG::GroupManager::SpawnTask::SpawnTask);
  v1->mSpawnTasks.size = 0;
  *(_QWORD *)&v1->mMinGroupSpacing = 0i64;
  v1->mDesiredGroupRatios.size = 0;
}

// File Line: 358
// RVA: 0x33A380
void __fastcall UFG::GroupManager::Profile::~Profile(UFG::GroupManager::Profile *this)
{
  this->mDesiredGroupRatios.size = 0;
  this->mSpawnTasks.size = 0;
  `eh vector destructor iterator'(this->mSpawnTasks.p, 0x28ui64, 8, (void (__fastcall *)(void *))_);
}

// File Line: 362
// RVA: 0x3680E0
void __fastcall UFG::GroupManager::Profile::InitFromPropertySet(UFG::GroupManager::Profile *this, UFG::qPropertySet *pPropertySet)
{
  UFG::qPropertySet *v2; // rbx
  UFG::GroupManager::Profile *v3; // rdi
  UFG::qSymbol *v4; // rax
  UFG::qSymbol *v5; // rax
  unsigned int v6; // ecx
  __int64 v7; // rax
  unsigned int v8; // esi
  float i; // xmm6_4
  signed __int64 v10; // rbx
  unsigned int v11; // edx
  UFG::qBaseTreeRB *v12; // rax
  __int64 v13; // rax
  float v14; // xmm0_4
  unsigned int j; // ecx
  UFG::qSymbol result; // [rsp+50h] [rbp+8h]

  v2 = pPropertySet;
  v3 = this;
  this->mSinglesNeeded = 0;
  v4 = UFG::qSymbol::create_from_string(&result, "MinGroupSpacing");
  v3->mMinGroupSpacing = *UFG::qPropertySet::Get<unsigned long>(v2, v4, DEPTH_RECURSE);
  v5 = UFG::qSymbol::create_from_string(&result, "SpawnTasks");
  UFG::InitFixedArrayFromPropertySet<UFG::qFixedArray<UFG::GroupManager::SpawnTask,8>,UFG::GroupManager::SpawnTask>(
    "GroupManager::Profile::InitFromPropertySet",
    &v3->mSpawnTasks,
    v2,
    v5);
  v3->mDesiredGroupRatios.size = 5;
  v6 = 0;
  do
  {
    v7 = v6++;
    v3->mDesiredGroupRatios.p[v7] = 0.0;
  }
  while ( v6 < v3->mDesiredGroupRatios.size );
  v8 = 0;
  for ( i = 0.0; v8 < v3->mSpawnTasks.size; i = i + v3->mSpawnTasks.p[v10].mWeight )
  {
    v10 = v8;
    v3->mSpawnTasks.p[v10].mProfile = v3;
    v3->mSpawnTasks.p[v10].mIndex = v8;
    v11 = v3->mSpawnTasks.p[v8].mFormation.mUID;
    if ( v11 && (v12 = UFG::qBaseTreeRB::Get(&UFG::PedFormationManagerComponent::s_Profiles.mTree, v11)) != 0i64 )
      v13 = *(&v12[12].mNULL.mUID + 1);
    else
      v13 = 0i64;
    v14 = v3->mSpawnTasks.p[v8++].mWeight;
    v3->mDesiredGroupRatios.p[v13] = v14 + v3->mDesiredGroupRatios.p[v13];
  }
  for ( j = 0; j < v3->mDesiredGroupRatios.size; ++j )
  {
    if ( i <= 0.0 )
      v3->mDesiredGroupRatios.p[j] = 0.0;
    else
      v3->mDesiredGroupRatios.p[j] = v3->mDesiredGroupRatios.p[j] / i;
  }
}

// File Line: 416
// RVA: 0x362BD0
float __fastcall UFG::GroupManager::Profile::GetTaskCompletionRatio(UFG::GroupManager::Profile *this, UFG::GroupManager::SpawnTask *spawnTask)
{
  __int64 v2; // rdi
  signed int v3; // er14
  UFG::GroupManager::Profile *v4; // rbx
  float v5; // xmm6_4
  UFG::GroupManager::SpawnTask *v6; // r15
  unsigned int v7; // edx
  UFG::qBaseTreeRB *v8; // rax
  int v9; // ebp
  unsigned int v10; // edx
  UFG::qBaseTreeRB *v11; // rax
  int v12; // eax
  float v13; // xmm2_4
  float v14; // xmm1_4
  float result; // xmm0_4

  v2 = 0i64;
  v3 = 0;
  v4 = this;
  v5 = 0.0;
  v6 = spawnTask;
  if ( !this->mSpawnTasks.size )
    goto LABEL_24;
  do
  {
    v7 = v4->mSpawnTasks.p[v2].mFormation.mUID;
    if ( v7 && (v8 = UFG::qBaseTreeRB::Get(&UFG::PedFormationManagerComponent::s_Profiles.mTree, v7)) != 0i64 )
      v9 = *(&v8[12].mNULL.mUID + 1);
    else
      v9 = 0;
    v10 = v6->mFormation.mUID;
    if ( v10 && (v11 = UFG::qBaseTreeRB::Get(&UFG::PedFormationManagerComponent::s_Profiles.mTree, v10)) != 0i64 )
      v12 = *(&v11[12].mNULL.mUID + 1);
    else
      v12 = 0;
    if ( v9 == v12 )
    {
      v3 += v4->mSpawnTasks.p[v2].mNumCompletedGroups;
      v5 = v5 + v4->mSpawnTasks.p[v2].mWeight;
    }
    v2 = (unsigned int)(v2 + 1);
  }
  while ( (unsigned int)v2 < v4->mSpawnTasks.size );
  if ( v5 > 0.0 )
    v13 = v6->mWeight / v5;
  else
LABEL_24:
    v13 = 0.0;
  if ( v3 )
    v14 = (float)(signed int)v6->mNumCompletedGroups / (float)v3;
  else
    v14 = 0.0;
  if ( v13 <= 0.0 )
    result = 0.0;
  else
    result = v14 / v13;
  return result;
}

// File Line: 440
// RVA: 0x36CBC0
char __fastcall UFG::GroupManager::Profile::JoinGroup(UFG::GroupManager::Profile *this, UFG::GroupManager::ValidatedPed *ped, UFG::qFixedArray<UFG::GroupManager::ValidatedPed,10> *closePeds)
{
  __int64 v3; // rsi
  UFG::qFixedArray<UFG::GroupManager::ValidatedPed,10> *v4; // r14
  UFG::GroupManager::ValidatedPed *v5; // r13
  UFG::GroupManager::Profile *v6; // rbx
  unsigned int v7; // edx
  signed __int64 v8; // rdi
  UFG::qBaseTreeRB *v9; // rax
  unsigned int v10; // ecx
  unsigned int v11; // er11
  signed int v12; // er12
  int v13; // er8
  float v14; // xmm2_4
  int v15; // er9
  unsigned int v16; // ebp
  unsigned int v17; // eax
  signed __int64 v18; // r14
  unsigned int *v19; // rcx
  unsigned int v20; // eax
  __int64 v21; // rdx
  float v22; // xmm1_4
  float v23; // xmm1_4
  UFG::GroupManager::Profile *v24; // rcx
  __int64 v25; // rdi
  unsigned int v26; // edx
  UFG::qBaseTreeRB *v27; // rax
  int v28; // esi
  UFG::GroupComponent *v29; // rdi
  UFG::GroupComponent *v30; // rcx
  UFG::qSafePointer<UFG::GroupComponent,UFG::GroupComponent> *v31; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::GroupComponent>,UFG::qSafePointerNodeList> *v32; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::GroupComponent>,UFG::qSafePointerNodeList> *v33; // rax
  unsigned int v34; // eax
  int v35; // eax
  UFG::GroupComponent *v37; // rcx
  UFG::PedFormationProfile *v38; // rax
  UFG::qFixedArray<UFG::GroupManager::ValidatedPed,10> *v39; // [rsp+70h] [rbp+18h]

  v39 = closePeds;
  v3 = 0i64;
  v4 = closePeds;
  v5 = ped;
  v6 = this;
  if ( this->mSpawnTasks.size )
  {
    do
    {
      v7 = v6->mSpawnTasks.p[v3].mFormation.mUID;
      v8 = (signed __int64)v6 + 40 * v3;
      if ( v7 && (v9 = UFG::qBaseTreeRB::Get(&UFG::PedFormationManagerComponent::s_Profiles.mTree, v7)) != 0i64 )
        v10 = *(&v9[12].mNULL.mUID + 1);
      else
        v10 = 0;
      v11 = UFG::gpGroupManager->mGroupTotals.size;
      v12 = UFG::gpGroupManager->mGroupTotals.p[v10];
      v13 = 0;
      v14 = *(float *)(*(_QWORD *)(v8 + 8) + 4i64 * v10 + 340);
      v15 = 0;
      v16 = 0;
      v17 = 0;
      v18 = 0i64;
      if ( (signed int)v11 >= 2 )
      {
        v19 = &UFG::gpGroupManager->mGroupTotals.p[1];
        v20 = ((v11 - 2) >> 1) + 1;
        v21 = v20;
        v17 = 2 * v20;
        v18 = 2 * v21;
        do
        {
          v13 += *(v19 - 1);
          v15 += *v19;
          v19 += 2;
          --v21;
        }
        while ( v21 );
      }
      if ( v17 < v11 )
        v16 = UFG::gpGroupManager->mGroupTotals.p[v18];
      if ( v16 + v13 + v15 )
        v22 = (float)v12 / (float)(signed int)(v16 + v13 + v15);
      else
        v22 = 0.0;
      if ( v14 <= 0.0 )
        v23 = 0.0;
      else
        v23 = v22 / v14;
      v24 = *(UFG::GroupManager::Profile **)(v8 + 8);
      *(float *)(v8 + 36) = v23;
      v3 = (unsigned int)(v3 + 1);
      *(float *)(v8 + 40) = UFG::GroupManager::Profile::GetTaskCompletionRatio(
                              v24,
                              (UFG::GroupManager::SpawnTask *)(v8 + 8));
    }
    while ( (unsigned int)v3 < v6->mSpawnTasks.size );
    v4 = v39;
  }
  qsort(v6->mSpawnTasks.p, v6->mSpawnTasks.size, 0x28ui64, UFG::GroupManager::SpawnTask::Sort);
  v25 = 0i64;
  if ( v6->mSpawnTasks.size )
  {
    while ( 1 )
    {
      v26 = v6->mSpawnTasks.p[v25].mFormation.mUID;
      if ( v26 && (v27 = UFG::qBaseTreeRB::Get(&UFG::PedFormationManagerComponent::s_Profiles.mTree, v26)) != 0i64 )
        v28 = *(&v27[12].mNULL.mUID + 1);
      else
        v28 = 0;
      if ( (!v6->mSinglesNeeded || !v28) && UFG::GroupManager::SpawnTask::JoinGroup(&v6->mSpawnTasks.p[v25], v5, v4) )
        break;
      v25 = (unsigned int)(v25 + 1);
      if ( (unsigned int)v25 >= v6->mSpawnTasks.size )
        goto LABEL_28;
    }
    if ( v28 )
    {
      v37 = v5->mGroupComponent->mGroupFollower.mLeader.m_pPointer;
      if ( v37 )
      {
        if ( v37->mGroupLeader.mFormationProfile )
        {
          v38 = v37->mGroupLeader.mFormationProfile;
          if ( v38 )
          {
            if ( v37->mGroupLeader.mFollowers.size >= v38->mMaxFollowers )
            {
              v35 = v6->mMinGroupSpacing;
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
    v29 = v5->mGroupComponent;
    v30 = v29->mGroupFollower.mLeader.m_pPointer;
    if ( v30 )
    {
      UFG::GroupLeader::Unregister(&v30->mGroupLeader, v5->mGroupComponent);
      v31 = &v29->mGroupFollower.mLeader;
      if ( v29->mGroupFollower.mLeader.m_pPointer )
      {
        v32 = v31->mPrev;
        v33 = v29->mGroupFollower.mLeader.mNext;
        v32->mNext = v33;
        v33->mPrev = v32;
        v31->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::GroupComponent>,UFG::qSafePointerNodeList> *)&v31->mPrev;
        v29->mGroupFollower.mLeader.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::GroupComponent>,UFG::qSafePointerNodeList> *)&v29->mGroupFollower.mLeader.mPrev;
      }
      v29->mGroupFollower.mLeader.m_pPointer = 0i64;
    }
    UFG::GroupLeader::Reset(&v29->mGroupLeader);
    v29->mFlags = 1;
    if ( v29->mGroupLeader.mFormationProfile != &ptr )
    {
      UFG::GroupLeader::Reset(&v29->mGroupLeader);
      v29->mGroupLeader.mFormationProfile = &ptr;
      ++UFG::gpGroupManager->mGroupTotals.p[0];
    }
    v29->mFlags |= 1u;
  }
  v34 = v6->mSinglesNeeded;
  if ( v34 )
  {
    v35 = v34 - 1;
LABEL_37:
    v6->mSinglesNeeded = v35;
  }
  return 1;
}

// File Line: 513
// RVA: 0x3317B0
void __fastcall UFG::GroupManager::Restriction::Restriction(UFG::GroupManager::Restriction *this)
{
  this->mClassType.mUID = -1;
  this->mIsSameClass = 2;
}

// File Line: 521
// RVA: 0x368240
void __fastcall UFG::GroupManager::Restriction::InitFromPropertySet(UFG::GroupManager::Restriction *this, UFG::qPropertySet *pPropertySet)
{
  UFG::qPropertySet *v2; // rbx
  UFG::qSymbol *v3; // rdi
  UFG::qSymbol *v4; // rax
  UFG::qSymbol *v5; // rax
  bool *v6; // rax
  UFG::qSymbol result; // [rsp+30h] [rbp+8h]

  v2 = pPropertySet;
  v3 = (UFG::qSymbol *)this;
  v4 = UFG::qSymbol::create_from_string(&result, "ClassType");
  v3->mUID = UFG::qPropertySet::Get<UFG::qSymbol>(v2, v4, DEPTH_RECURSE)->mUID;
  v5 = UFG::qSymbol::create_from_string(&result, "IsSameClass");
  v6 = UFG::qPropertySet::Get<bool>(v2, v5, DEPTH_RECURSE);
  if ( v6 )
    v3[1].mUID = *v6 != 0;
  else
    v3[1].mUID = 2;
}

// File Line: 530
// RVA: 0x3419F0
bool __fastcall UFG::GroupManager::Restriction::Allow(UFG::GroupManager::Restriction *this, UFG::GroupManager::ValidatedPed *pedA, UFG::GroupManager::ValidatedPed *pedB)
{
  UFG::GroupManager::ValidatedPed *v3; // rsi
  UFG::qSymbol *v4; // rdi
  bool v5; // bp
  bool v6; // al
  char v7; // bl
  char v8; // al

  v3 = pedB;
  v4 = (UFG::qSymbol *)this;
  v5 = pedA->mInfo == pedB->mInfo;
  if ( this->mIsSameClass == 2 )
  {
    v6 = 1;
    return !v5 && v6;
  }
  v7 = UFG::SimObjectUtility::IsClassType(pedA->mPropertySet, (UFG::qSymbol *)this);
  v8 = UFG::SimObjectUtility::IsClassType(v3->mPropertySet, v4);
  if ( v7 )
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
  if ( !v4[1].mUID )
    v6 = v6 == 0;
  return !v5 && v6;
}

// File Line: 560
// RVA: 0x32F4E0
void __fastcall UFG::GroupManager::GroupManager(UFG::GroupManager *this)
{
  UFG::GroupManager *v1; // rdi

  v1 = this;
  `eh vector constructor iterator'(
    this->mProfiles.p,
    0x168ui64,
    2,
    (void (__fastcall *)(void *))UFG::GroupManager::Profile::Profile);
  v1->mProfiles.size = 0;
  `eh vector constructor iterator'(
    v1->mRestrictions.p,
    8ui64,
    8,
    (void (__fastcall *)(void *))UFG::GroupManager::Restriction::Restriction);
  v1->mRestrictions.size = 0;
  v1->mCurrentProfile = 0i64;
  v1->mGroupTotals.size = 0;
  UFG::GroupManager::Init(v1);
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
  UFG::GroupManager *v1; // rbx
  UFG::qPropertySet *v2; // rdi
  UFG::qSymbol *v3; // rax
  UFG::qSymbol *v4; // rax
  unsigned int v5; // eax
  __int64 v6; // rcx
  UFG::qSymbol result; // [rsp+30h] [rbp+8h]
  UFG::qSymbol v8; // [rsp+38h] [rbp+10h]

  v1 = this;
  UFG::qSymbol::create_from_string(&result, "default-formation-GroupManager");
  v2 = UFG::PropertySetManager::GetPropertySet(&result);
  v3 = UFG::qSymbol::create_from_string(&v8, "Profiles");
  UFG::InitFixedArrayFromPropertySet<UFG::qFixedArray<UFG::GroupManager::Profile,2>,UFG::GroupManager::Profile>(
    "GroupManager::Profile::InitFromPropertySet",
    &v1->mProfiles,
    v2,
    v3);
  if ( v1->mProfiles.size )
    v1->mCurrentProfile = v1->mProfiles.p;
  v4 = UFG::qSymbol::create_from_string(&v8, "Restrictions");
  UFG::InitFixedArrayFromPropertySet<UFG::qFixedArray<UFG::GroupManager::Restriction,8>,UFG::GroupManager::Restriction>(
    "GroupManager::Profile::InitFromPropertySet",
    &v1->mRestrictions,
    v2,
    v4);
  v1->mGroupTotals.size = 5;
  v5 = 0;
  do
  {
    v6 = v5++;
    v1->mGroupTotals.p[v6] = 0;
  }
  while ( v5 < v1->mGroupTotals.size );
}

// File Line: 646
// RVA: 0x3697E0
char __fastcall UFG::GroupManager::IsAllowed(UFG::GroupManager *this, UFG::GroupManager::ValidatedPed *newPed, UFG::GroupManager::ValidatedPed *closePed)
{
  UFG::GroupManager::ValidatedPed *v3; // r14
  UFG::GroupManager::ValidatedPed *v4; // rbp
  UFG::GroupManager *v5; // rsi
  UFG::GroupComponent *v6; // rcx
  UFG::PedFormationProfile *v7; // rdx
  unsigned int v8; // eax
  bool *v9; // rax
  bool *v10; // rax
  UFG::qSymbol *v11; // rax
  UFG::qStaticSymbol *v12; // rdi
  UFG::qStaticSymbol *v13; // rbx
  UFG::qSymbol *v14; // rax
  __int64 v15; // rbx

  v3 = closePed;
  v4 = newPed;
  v5 = this;
  if ( closePed->mInfo->mCharacterOccupantComponent.m_pSimComponent )
    return 0;
  v6 = closePed->mGroupComponent;
  if ( !(v6->mFlags & 1) )
    return 0;
  if ( v6->mGroupFollower.mLeader.m_pPointer )
    return 0;
  v7 = v6->mGroupLeader.mFormationProfile;
  if ( v7 )
  {
    v8 = v7->mMaxFollowers;
    if ( v6->mGroupLeader.mFollowers.size >= v8 )
    {
      if ( v8 )
        return 0;
    }
  }
  v9 = UFG::qPropertySet::Get<bool>(v4->mPropertySet, (UFG::qSymbol *)&qSymbol_CanJoinGroup.mUID, DEPTH_RECURSE);
  if ( !v9 )
    return 0;
  if ( !*v9 )
    return 0;
  v10 = UFG::qPropertySet::Get<bool>(v3->mPropertySet, (UFG::qSymbol *)&qSymbol_CanJoinGroup.mUID, DEPTH_RECURSE);
  if ( !v10 || !*v10 )
    return 0;
  v11 = UFG::qPropertySet::Get<UFG::qSymbol>(v3->mPropertySet, (UFG::qSymbol *)&qSymbol_walkCycle.mUID, DEPTH_RECURSE);
  v12 = &qSymbol_Default;
  v13 = &qSymbol_Default;
  if ( v11 )
    v13 = (UFG::qStaticSymbol *)v11;
  v14 = UFG::qPropertySet::Get<UFG::qSymbol>(v4->mPropertySet, (UFG::qSymbol *)&qSymbol_walkCycle.mUID, DEPTH_RECURSE);
  if ( v14 )
    v12 = (UFG::qStaticSymbol *)v14;
  if ( v12->mUID == v13->mUID && !UFG::PedSpawningInfo::IsUsingPOI(v3->mInfo, 0i64) )
  {
    v15 = 0i64;
    if ( !v5->mRestrictions.size )
      return 1;
    while ( UFG::GroupManager::Restriction::Allow(&v5->mRestrictions.p[v15], v4, v3) )
    {
      v15 = (unsigned int)(v15 + 1);
      if ( (unsigned int)v15 >= v5->mRestrictions.size )
        return 1;
    }
  }
  return 0;
}

// File Line: 705
// RVA: 0x36C9E0
bool __fastcall UFG::GroupManager::JoinGroup(UFG::GroupManager *this, UFG::PedSpawningInfo *pPed, UFG::qFixedArray<UFG::PedSpawningInfo *,10> *closePeds)
{
  UFG::qFixedArray<UFG::PedSpawningInfo *,10> *v3; // rdi
  UFG::GroupManager *v4; // rsi
  UFG::PedFormationProfile *v5; // rcx
  unsigned int i; // ebx
  UFG::GroupManager::Profile *v7; // rcx
  bool v8; // bl
  UFG::GroupManager::ValidatedPed closePed; // [rsp+30h] [rbp-B8h]
  UFG::GroupManager::ValidatedPed newPed; // [rsp+50h] [rbp-98h]
  __int64 ptr[31]; // [rsp+70h] [rbp-78h]

  ptr[0] = -2i64;
  v3 = closePeds;
  v4 = this;
  newPed.mInfo = 0i64;
  newPed.mGroupComponent = 0i64;
  newPed.mGender.mUID = -1;
  newPed.mPropertySet = 0i64;
  if ( UFG::GroupManager::ValidatedPed::Init(&newPed, pPed) )
  {
    if ( !newPed.mInfo->mCharacterOccupantComponent.m_pSimComponent )
    {
      if ( newPed.mGroupComponent->mFlags & 1 )
      {
        if ( !newPed.mGroupComponent->mGroupFollower.mLeader.m_pPointer )
        {
          v5 = newPed.mGroupComponent->mGroupLeader.mFormationProfile;
          if ( !v5
            || newPed.mGroupComponent->mGroupLeader.mFollowers.size < v5->mMaxFollowers
            || v5 && !v5->mMaxFollowers )
          {
            `eh vector constructor iterator'(
              ptr,
              0x20ui64,
              10,
              (void (__fastcall *)(void *))UFG::GroupManager::ValidatedPed::ValidatedPed);
            LODWORD(newPed.mPropertySet) = 0;
            for ( i = 0; i < v3->size; ++i )
            {
              closePed.mInfo = 0i64;
              closePed.mGroupComponent = 0i64;
              closePed.mGender.mUID = -1;
              closePed.mPropertySet = 0i64;
              if ( UFG::GroupManager::ValidatedPed::Init(&closePed, v3->p[i]) )
              {
                if ( UFG::GroupManager::IsAllowed(v4, &newPed, &closePed) )
                {
                  *(UFG::GroupManager::ValidatedPed *)&ptr[4 * LODWORD(newPed.mPropertySet)] = closePed;
                  ++LODWORD(newPed.mPropertySet);
                }
              }
            }
            v7 = v4->mCurrentProfile;
            if ( v7 )
            {
              v8 = UFG::GroupManager::Profile::JoinGroup(
                     v7,
                     &newPed,
                     (UFG::qFixedArray<UFG::GroupManager::ValidatedPed,10> *)&newPed.mPropertySet);
              LODWORD(newPed.mPropertySet) = 0;
              `eh vector destructor iterator'(ptr, 0x20ui64, 10, (void (__fastcall *)(void *))_);
              return v8;
            }
            LODWORD(newPed.mPropertySet) = 0;
            `eh vector destructor iterator'(ptr, 0x20ui64, 10, (void (__fastcall *)(void *))_);
          }
        }
      }
    }
  }
  return 0;
}

// File Line: 790
// RVA: 0x3619F0
__int64 __fastcall UFG::GroupManager::GetNumGroupPeds(UFG::GroupManager *this)
{
  unsigned int v1; // esi
  int v2; // edx
  UFG::GroupManager *v3; // rbp
  int v4; // er10
  int v5; // ebx
  unsigned int v6; // edi
  signed __int64 v7; // r14
  signed int v8; // er8
  unsigned int *v9; // r9
  unsigned int v10; // eax
  __int64 v11; // r11
  int v12; // ecx
  int v13; // eax

  v1 = this->mGroupTotals.size;
  v2 = 0;
  v3 = this;
  v4 = 0;
  v5 = 0;
  v6 = 0;
  v7 = 0i64;
  if ( (signed int)v1 >= 2 )
  {
    v8 = 2;
    v9 = &this->mGroupTotals.p[1];
    v10 = ((v1 - 2) >> 1) + 1;
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
  if ( v6 < v1 )
    v5 = (v6 + 1) * v3->mGroupTotals.p[v7];
  return (unsigned int)(v5 + v4 + v2);
}

// File Line: 802
// RVA: 0x361930
__int64 __fastcall UFG::GroupManager::GetNumGroupMembersToSpawn(UFG::GroupManager *this, int numPedsToSpawn)
{
  UFG::GroupManager::Profile *v2; // rdi
  float v3; // xmm6_4
  float v4; // xmm1_4
  __int64 result; // rax

  v2 = this->mCurrentProfile;
  if ( !v2 )
    return 0i64;
  v3 = (float)numPedsToSpawn;
  v4 = (float)((float)((float)(signed int)UFG::GroupManager::GetNumGroupPeds(this) + (float)numPedsToSpawn)
             * v2->mDesiredGroupRatios.p[0])
     - (float)(signed int)this->mGroupTotals.p[0];
  if ( v4 <= 1.0 )
    v4 = *(float *)&FLOAT_1_0;
  if ( v4 >= v3 )
    v4 = v3;
  result = (unsigned int)(signed int)(float)(v3 - v4);
  if ( (signed int)result < 2 )
    result = 0i64;
  return result;
}

