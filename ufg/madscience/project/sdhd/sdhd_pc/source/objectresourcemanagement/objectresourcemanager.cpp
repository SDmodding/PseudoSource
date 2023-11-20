// File Line: 51
// RVA: 0x43DEA0
UFG::qSymbol *__fastcall UFG::EntityTypeState::GetSpawnableRareEntity(UFG::EntityTypeState *this)
{
  unsigned int v1; // er8
  __int64 v2; // rax

  v1 = this->mRareSpawnIsReady.size;
  v2 = 0i64;
  if ( !v1 )
    return &UFG::gNullQSymbol;
  while ( !this->mRareSpawnIsReady.p[v2] )
  {
    v2 = (unsigned int)(v2 + 1);
    if ( (unsigned int)v2 >= v1 )
      return &UFG::gNullQSymbol;
  }
  return &this->mRareSpawnPropertySets.p[(unsigned int)v2];
}

// File Line: 63
// RVA: 0x441240
void __fastcall UFG::EntityTypeState::RareEntitySpawned(UFG::EntityTypeState *this, UFG::qSymbol *spawnedEntity)
{
  __int64 v2; // r9
  UFG::qSymbol *v3; // rdi
  __int64 v4; // rdx
  __int64 v5; // rax
  unsigned int v6; // er8
  __int64 v7; // rbx
  __int64 v8; // rdx
  __int64 v9; // rdx
  unsigned __int64 v10; // rax

  v2 = 0i64;
  v3 = spawnedEntity;
  if ( this->mRareSpawnPropertySets.size )
  {
    do
    {
      if ( this->mRareSpawnPropertySets.p[v2].mUID == v3->mUID )
      {
        this->mRareSpawnIsReady.p[v2] = 0;
        v4 = (signed int)this->mEntityType;
        v5 = 0i64;
        v6 = UFG::ObjectResourceManager::sInstance->mRareSpawnList[v4].size;
        if ( v6 )
        {
          v7 = *((_QWORD *)&UFG::ObjectResourceManager::sInstance->mPool.mQueued.size + 2 * (v4 + 29));
          v8 = *((_QWORD *)&UFG::ObjectResourceManager::sInstance->mPool.mQueued.size + 2 * (v4 + 29));
          while ( *(_DWORD *)(*(_QWORD *)v8 + 16i64) != this->mRareSpawnPropertySets.p[v2].mUID )
          {
            v5 = (unsigned int)(v5 + 1);
            v8 += 8i64;
            if ( (unsigned int)v5 >= v6 )
              goto LABEL_7;
          }
          v9 = *(_QWORD *)(v7 + 8 * v5);
        }
        else
        {
LABEL_7:
          v9 = 0i64;
        }
        v10 = UFG::Metrics::msInstance.mSimTimeMSec;
        ++*(_DWORD *)(v9 + 28);
        *(_QWORD *)(v9 + 56) = v10;
      }
      v2 = (unsigned int)(v2 + 1);
    }
    while ( (unsigned int)v2 < this->mRareSpawnPropertySets.size );
  }
}

// File Line: 76
// RVA: 0x445BC0
void UFG::EntityTypeState::UpdateCharacterPreloads(void)
{
  UFG::ObjectResourceManager::UpdateCharacterPreloads(UFG::ObjectResourceManager::sInstance);
}

// File Line: 81
// RVA: 0x447530
void UFG::EntityTypeState::UpdateVehiclePreloads(void)
{
  UFG::ObjectResourceManager::UpdateVehiclePreloads(UFG::ObjectResourceManager::sInstance);
}

// File Line: 86
// RVA: 0x4466C0
void UFG::EntityTypeState::UpdatePropPreloads(void)
{
  UFG::ObjectResourceManager::UpdatePropPreloads(UFG::ObjectResourceManager::sInstance);
}

// File Line: 117
// RVA: 0x436E40
void __fastcall UFG::ObjectResourceManager::RareSpawnRecord::RareSpawnRecord(UFG::ObjectResourceManager::RareSpawnRecord *this)
{
  signed int v1; // edx
  UFG::qColour **v2; // rax

  this->mPrev = (UFG::qNode<UFG::ObjectResourceManager::RareSpawnRecord,UFG::ObjectResourceManager::RareSpawnRecord> *)&this->mPrev;
  this->mNext = (UFG::qNode<UFG::ObjectResourceManager::RareSpawnRecord,UFG::ObjectResourceManager::RareSpawnRecord> *)&this->mPrev;
  *(_QWORD *)&this->mPropertySetName.mUID = -1i64;
  this->mMaxSpawnsBeforeCycles = -1;
  this->mTotalNumInstancesSpawned = 0;
  this->mWeight = -1;
  this->mMinTimeBetweenSpawns = 0i64;
  this->mLastTimeAssetLoaded = 0i64;
  this->mLastTimeAssetSpawned = 0i64;
  this->mRequestTime = 0i64;
  v1 = 15;
  v2 = &this->mInstance.mPart[0].mColourTint;
  do
  {
    *(v2 - 1) = 0i64;
    *v2 = 0i64;
    v2 += 2;
    --v1;
  }
  while ( v1 >= 0 );
  this->mInstance.mSet = 0i64;
  this->mInstance.mNumParts = 0;
}

// File Line: 121
// RVA: 0x43E170
void __fastcall UFG::ObjectResourceManager::RareSpawnRecord::Init(UFG::ObjectResourceManager::RareSpawnRecord *this, UFG::qPropertySet *propertySet)
{
  UFG::qPropertySet *v2; // rdi
  UFG::ObjectResourceManager::RareSpawnRecord *v3; // rbx
  UFG::qSymbol *v4; // rax
  UFG::qSymbol *v5; // rcx
  unsigned int v6; // eax
  UFG::qPropertySet *v7; // rax
  int *v8; // rax
  int *v9; // rax
  int *v10; // rax
  float *v11; // rax
  signed __int64 v12; // rcx
  float v13; // xmm0_4

  v2 = propertySet;
  v3 = this;
  v4 = UFG::qPropertySet::Get<UFG::qSymbol>(propertySet, (UFG::qSymbol *)&qSymbol_PropertySet.mUID, DEPTH_RECURSE);
  v5 = &v3->mPropertySetName;
  v6 = v4->mUID;
  if ( v3->mPropertySetName.mUID != v6 )
  {
    v5->mUID = v6;
    v7 = UFG::PropertySetManager::FindPropertySet(v5);
    UFG::TrueCrowdDataBase::QueryInstance(UFG::TrueCrowdDataBase::sTrueCrowdDataBase, v7, &v3->mInstance);
  }
  v3->mMaxConcurrentInstances = 1000;
  v8 = UFG::qPropertySet::Get<long>(v2, (UFG::qSymbol *)&qSymbol_MaxInstances.mUID, DEPTH_RECURSE);
  if ( v8 )
    v3->mMaxConcurrentInstances = *v8;
  v3->mMaxSpawnsBeforeCycles = 10000;
  v9 = UFG::qPropertySet::Get<long>(v2, (UFG::qSymbol *)&qSymbol_MaxSpawnsBeforeCycle.mUID, DEPTH_RECURSE);
  if ( v9 )
    v3->mMaxSpawnsBeforeCycles = *v9;
  v3->mWeight = 0;
  v10 = UFG::qPropertySet::Get<long>(v2, (UFG::qSymbol *)&qSymbol_Weight.mUID, DEPTH_RECURSE);
  if ( v10 )
    v3->mWeight = *v10;
  v3->mMinTimeBetweenSpawns = 0i64;
  v11 = UFG::qPropertySet::Get<float>(v2, (UFG::qSymbol *)&qSymbol_MinTimeBetweenSpawns.mUID, DEPTH_RECURSE);
  if ( v11 )
  {
    v12 = 0i64;
    v13 = *v11 * 1000.0;
    if ( v13 >= 9.223372e18 )
    {
      v13 = v13 - 9.223372e18;
      if ( v13 < 9.223372e18 )
        v12 = 0x8000000000000000i64;
    }
    v3->mMinTimeBetweenSpawns = v12 + (unsigned int)(signed int)v13;
  }
  v3->mTotalNumInstancesSpawned = 0;
  v3->mLastTimeAssetLoaded = UFG::Metrics::msInstance.mSimTimeMSec;
  v3->mRequestTime = UFG::Metrics::msInstance.mSimTimeMSec;
  v3->mLastTimeAssetSpawned = UFG::Metrics::msInstance.mSimTimeMSec - v3->mMinTimeBetweenSpawns;
}

// File Line: 166
// RVA: 0x444C00
void __fastcall UFG::ObjectResourceManager::RareSpawnRecord::Update(UFG::ObjectResourceManager::RareSpawnRecord *this, UFG::qPropertySet *propertySet)
{
  UFG::qPropertySet *v2; // rdi
  UFG::ObjectResourceManager::RareSpawnRecord *v3; // rbx
  int *v4; // rax
  int v5; // eax
  int v6; // er8
  int *v7; // rax
  int v8; // eax
  int v9; // ecx
  int *v10; // rax
  int v11; // eax
  int v12; // ecx
  float *v13; // rax
  float v14; // xmm0_4
  signed __int64 v15; // rax
  float v16; // xmm0_4
  unsigned __int64 v17; // rcx
  unsigned __int64 v18; // rax

  v2 = propertySet;
  v3 = this;
  v4 = UFG::qPropertySet::Get<long>(propertySet, (UFG::qSymbol *)&qSymbol_MaxInstances.mUID, DEPTH_RECURSE);
  if ( v4 )
  {
    v5 = *v4;
    v6 = v3->mMaxConcurrentInstances;
    if ( v5 > v6 )
      v6 = v5;
    v3->mMaxConcurrentInstances = v6;
  }
  v7 = UFG::qPropertySet::Get<long>(v2, (UFG::qSymbol *)&qSymbol_MaxSpawnsBeforeCycle.mUID, DEPTH_RECURSE);
  if ( v7 )
  {
    v8 = *v7;
    v9 = v3->mMaxSpawnsBeforeCycles;
    if ( v8 > v9 )
      v9 = v8;
    v3->mMaxSpawnsBeforeCycles = v9;
  }
  v10 = UFG::qPropertySet::Get<long>(v2, (UFG::qSymbol *)&qSymbol_Weight.mUID, DEPTH_RECURSE);
  if ( v10 )
  {
    v11 = *v10;
    v12 = v3->mWeight;
    if ( v11 > v12 )
      v12 = v11;
    v3->mWeight = v12;
  }
  v13 = UFG::qPropertySet::Get<float>(v2, (UFG::qSymbol *)&qSymbol_MinTimeBetweenSpawns.mUID, DEPTH_RECURSE);
  if ( v13 )
  {
    v14 = *v13;
    v15 = 0i64;
    v16 = v14 * 1000.0;
    if ( v16 >= 9.223372e18 )
    {
      v16 = v16 - 9.223372e18;
      if ( v16 < 9.223372e18 )
        v15 = 0x8000000000000000i64;
    }
    v17 = v15 + (unsigned int)(signed int)v16;
    v18 = v3->mMinTimeBetweenSpawns;
    if ( v17 > v18 )
      v18 = v17;
    v3->mMinTimeBetweenSpawns = v18;
  }
}

// File Line: 214
// RVA: 0x436800
void __fastcall UFG::ObjectResourceManager::ObjectResourceManager(UFG::ObjectResourceManager *this)
{
  UFG::ObjectResourceManager *v1; // rbx
  UFG::qArray<UFG::ObjectResourceManager::RareSpawnRecord *,0> *v2; // rdi
  UFG::allocator::free_link *v3; // rsi
  unsigned __int64 v4; // rax
  UFG::allocator::free_link *v5; // rax
  UFG::qPropertySet **v6; // rbp
  unsigned int i; // er9
  unsigned __int64 v8; // rax
  UFG::allocator::free_link *v9; // rax
  UFG::qPropertySet **v10; // rbp
  unsigned int j; // er9
  unsigned __int64 v12; // rax
  UFG::allocator::free_link *v13; // rax
  UFG::ObjectResourceManager::RareSpawnRecord **v14; // rbp
  unsigned int k; // er9
  unsigned __int64 v16; // rax
  UFG::allocator::free_link *v17; // rax
  UFG::ObjectResourceManager::RareSpawnRecord **v18; // rdi
  unsigned int l; // er9
  unsigned __int64 v20; // rax
  UFG::allocator::free_link *v21; // rax
  UFG::ObjectResourceManager::RareSpawnRecord **v22; // rdi
  unsigned int m; // er9
  signed __int64 v24; // rdi
  UFG::allocator::free_link *v25; // rax
  signed int v26; // edx
  UFG::allocator::free_link *v27; // rcx
  UFG::allocator::free_link *v28; // rcx

  v1 = this;
  UFG::ResourcePool::ResourcePool(&this->mPool);
  `eh vector constructor iterator(
    v1->mEntityStates,
    0x48ui64,
    3,
    (void (__fastcall *)(void *))UFG::EntityTypeState::EntityTypeState);
  v1->mCurrentSpawnset = UFG::gNullQSymbol;
  v1->mAmbientVehicles.p = 0i64;
  *(_QWORD *)&v1->mAmbientVehicles.size = 0i64;
  v1->mAvailableDrivers.p = 0i64;
  *(_QWORD *)&v1->mAvailableDrivers.size = 0i64;
  v1->mDefaultDriver = 0i64;
  v2 = v1->mRareSpawnList;
  `eh vector constructor iterator(
    v1->mRareSpawnList,
    0x10ui64,
    3,
    (void (__fastcall *)(void *))UFG::qArray<UFG::qSymbolUC,0>::qArray<UFG::qSymbolUC,0>);
  v3 = (UFG::allocator::free_link *)&v1->mEmptyRareSpawnList;
  v3->mNext = v3;
  v3[1].mNext = v3;
  UFG::ObjectResourceManager::InitDescriptors(v1);
  UFG::ObjectResourceManager::InitPools(v1);
  if ( v1->mAmbientVehicles.capacity < 0x20 && v1->mAmbientVehicles.size != 32 )
  {
    v4 = 256i64;
    if ( !is_mul_ok(0x20ui64, 8ui64) )
      v4 = -1i64;
    v5 = UFG::qMalloc(v4, "qArray.Reserve.AmbientVehicleList", 0i64);
    v6 = (UFG::qPropertySet **)v5;
    if ( v1->mAmbientVehicles.p )
    {
      for ( i = 0; i < v1->mAmbientVehicles.size; ++i )
        v5[i] = (UFG::allocator::free_link)v1->mAmbientVehicles.p[i];
      operator delete[](v1->mAmbientVehicles.p);
    }
    v1->mAmbientVehicles.p = v6;
    v1->mAmbientVehicles.capacity = 32;
  }
  if ( v1->mAvailableDrivers.capacity < 0x20 && v1->mAvailableDrivers.size != 32 )
  {
    v8 = 256i64;
    if ( !is_mul_ok(0x20ui64, 8ui64) )
      v8 = -1i64;
    v9 = UFG::qMalloc(v8, "qArray.Reserve.mAvailableDrivers", 0i64);
    v10 = (UFG::qPropertySet **)v9;
    if ( v1->mAvailableDrivers.p )
    {
      for ( j = 0; j < v1->mAvailableDrivers.size; ++j )
        v9[j] = (UFG::allocator::free_link)v1->mAvailableDrivers.p[j];
      operator delete[](v1->mAvailableDrivers.p);
    }
    v1->mAvailableDrivers.p = v10;
    v1->mAvailableDrivers.capacity = 32;
  }
  if ( v1->mRareSpawnList[0].capacity < 8 && v2->size != 8 )
  {
    v12 = 64i64;
    if ( !is_mul_ok(8ui64, 8ui64) )
      v12 = -1i64;
    v13 = UFG::qMalloc(v12, "mRareSpawnList", 0i64);
    v14 = (UFG::ObjectResourceManager::RareSpawnRecord **)v13;
    if ( v1->mRareSpawnList[0].p )
    {
      for ( k = 0; k < v2->size; ++k )
        v13[k] = (UFG::allocator::free_link)v1->mRareSpawnList[0].p[k];
      operator delete[](v1->mRareSpawnList[0].p);
    }
    v1->mRareSpawnList[0].p = v14;
    v1->mRareSpawnList[0].capacity = 8;
  }
  if ( v1->mRareSpawnList[1].capacity < 8 && v1->mRareSpawnList[1].size != 8 )
  {
    v16 = 64i64;
    if ( !is_mul_ok(8ui64, 8ui64) )
      v16 = -1i64;
    v17 = UFG::qMalloc(v16, "mRareSpawnList", 0i64);
    v18 = (UFG::ObjectResourceManager::RareSpawnRecord **)v17;
    if ( v1->mRareSpawnList[1].p )
    {
      for ( l = 0; l < v1->mRareSpawnList[1].size; ++l )
        v17[l] = (UFG::allocator::free_link)v1->mRareSpawnList[1].p[l];
      operator delete[](v1->mRareSpawnList[1].p);
    }
    v1->mRareSpawnList[1].p = v18;
    v1->mRareSpawnList[1].capacity = 8;
  }
  if ( v1->mRareSpawnList[2].capacity < 8 && v1->mRareSpawnList[2].size != 8 )
  {
    v20 = 64i64;
    if ( !is_mul_ok(8ui64, 8ui64) )
      v20 = -1i64;
    v21 = UFG::qMalloc(v20, "mRareSpawnList", 0i64);
    v22 = (UFG::ObjectResourceManager::RareSpawnRecord **)v21;
    if ( v1->mRareSpawnList[2].p )
    {
      for ( m = 0; m < v1->mRareSpawnList[2].size; ++m )
        v21[m] = (UFG::allocator::free_link)v1->mRareSpawnList[2].p[m];
      operator delete[](v1->mRareSpawnList[2].p);
    }
    v1->mRareSpawnList[2].p = v22;
    v1->mRareSpawnList[2].capacity = 8;
  }
  v24 = 24i64;
  do
  {
    v25 = UFG::qMalloc(0x160ui64, "RareSpawnRecord", 0i64);
    if ( v25 )
    {
      v25->mNext = v25;
      v25[1].mNext = v25;
      LODWORD(v25[2].mNext) = -1;
      HIDWORD(v25[2].mNext) = -1;
      LODWORD(v25[3].mNext) = -1;
      HIDWORD(v25[3].mNext) = 0;
      LODWORD(v25[4].mNext) = -1;
      v25[5].mNext = 0i64;
      v25[6].mNext = 0i64;
      v25[7].mNext = 0i64;
      v25[8].mNext = 0i64;
      v26 = 15;
      v27 = v25 + 13;
      do
      {
        v27[-1].mNext = 0i64;
        v27->mNext = 0i64;
        v27 += 2;
        --v26;
      }
      while ( v26 >= 0 );
      v25[9].mNext = 0i64;
      LODWORD(v25[10].mNext) = 0;
    }
    else
    {
      v25 = 0i64;
    }
    v28 = v3->mNext;
    v28[1].mNext = v25;
    v25->mNext = v28;
    v25[1].mNext = v3;
    v3->mNext = v25;
    --v24;
  }
  while ( v24 );
}

// File Line: 233
// RVA: 0x437C20
void __fastcall UFG::ObjectResourceManager::~ObjectResourceManager(UFG::ObjectResourceManager *this)
{
  UFG::ObjectResourceManager *v1; // rdi
  UFG::qList<UFG::ObjectResourceManager::RareSpawnRecord,UFG::ObjectResourceManager::RareSpawnRecord,1,0> *v2; // rbx
  UFG::qNode<UFG::ObjectResourceManager::RareSpawnRecord,UFG::ObjectResourceManager::RareSpawnRecord> *v3; // rcx
  UFG::qNode<UFG::ObjectResourceManager::RareSpawnRecord,UFG::ObjectResourceManager::RareSpawnRecord> *v4; // rax
  UFG::qPropertySet **v5; // rcx
  UFG::qPropertySet **v6; // rcx

  v1 = this;
  v2 = &this->mEmptyRareSpawnList;
  UFG::qList<UFG::FractureConnectivity::Connection,UFG::FractureConnectivity::Connection,1,0>::DeleteNodes((UFG::qList<UFG::qReflectField,UFG::qReflectField,1,0> *)&this->mEmptyRareSpawnList);
  v3 = v2->mNode.mPrev;
  v4 = v2->mNode.mNext;
  v3->mNext = v4;
  v4->mPrev = v3;
  v2->mNode.mPrev = &v2->mNode;
  v2->mNode.mNext = &v2->mNode;
  `eh vector destructor iterator(
    v1->mRareSpawnList,
    0x10ui64,
    3,
    (void (__fastcall *)(void *))UFG::qArray<UFG::PartRequest *,0>::~qArray<UFG::PartRequest *,0>);
  v5 = v1->mAvailableDrivers.p;
  if ( v5 )
    operator delete[](v5);
  v1->mAvailableDrivers.p = 0i64;
  *(_QWORD *)&v1->mAvailableDrivers.size = 0i64;
  v6 = v1->mAmbientVehicles.p;
  if ( v6 )
    operator delete[](v6);
  v1->mAmbientVehicles.p = 0i64;
  *(_QWORD *)&v1->mAmbientVehicles.size = 0i64;
  `eh vector destructor iterator(
    v1->mEntityStates,
    0x48ui64,
    3,
    (void (__fastcall *)(void *))UFG::EntityTypeState::~EntityTypeState);
  UFG::ResourcePool::~ResourcePool(&v1->mPool);
}

// File Line: 238
// RVA: 0x43F090
UFG::ObjectResourceManager *__fastcall UFG::ObjectResourceManager::Instance()
{
  return UFG::ObjectResourceManager::sInstance;
}

// File Line: 244
// RVA: 0x43E000
void UFG::ObjectResourceManager::Init(void)
{
  UFG::allocator::free_link *v0; // rax
  UFG::ObjectResourceManager *v1; // rax
  const char **v2; // rbx
  UFG::qSymbol *v3; // rax
  UFG::qPropertySet *v4; // rax
  UFG::ObjectResourceManager *v5; // rdi
  signed int v6; // edx
  UFG::qColour **v7; // rcx
  UFG::PreloadRequest *v8; // rax
  UFG::TrueCrowdSet::Instance instance; // [rsp+30h] [rbp-128h]
  UFG::allocator::free_link *result; // [rsp+160h] [rbp+8h]

  v0 = UFG::qMalloc(0x208ui64, "ObjectResourceManager", 0i64);
  result = v0;
  if ( v0 )
    UFG::ObjectResourceManager::ObjectResourceManager((UFG::ObjectResourceManager *)v0);
  else
    v1 = 0i64;
  UFG::ObjectResourceManager::sInstance = v1;
  v2 = UFG::TodoMoveToXmlPreloadCriticalResources;
  do
  {
    v3 = UFG::qSymbol::create_from_string((UFG::qSymbol *)&result, *v2);
    v4 = UFG::PropertySetManager::GetPropertySet(v3);
    if ( v4 )
    {
      v5 = UFG::ObjectResourceManager::sInstance;
      v6 = 15;
      v7 = &instance.mPart[0].mColourTint;
      do
      {
        *(v7 - 1) = 0i64;
        *v7 = 0i64;
        v7 += 2;
        --v6;
      }
      while ( v6 >= 0 );
      instance.mSet = 0i64;
      instance.mNumParts = 0;
      UFG::TrueCrowdDataBase::QueryInstance(UFG::TrueCrowdDataBase::sTrueCrowdDataBase, v4, &instance);
      v8 = UFG::ResourcePool::RequestPreload(&v5->mPool, &instance, 1u, 1);
      UFG::ResourcePool::PreloadInstance(&v5->mPool, v8, &instance);
    }
    ++v2;
  }
  while ( (signed __int64)v2 < (signed __int64)&sDrawX );
}

// File Line: 260
// RVA: 0x441190
void UFG::ObjectResourceManager::Quit(void)
{
  const char **v0; // rbx
  UFG::qSymbol *v1; // rax
  UFG::qPropertySet *v2; // rax
  UFG::ObjectResourceManager *v3; // rdi
  UFG::TrueCrowdSet *v4; // rax
  UFG::ObjectResourceManager *v5; // rbx
  UFG::qSymbol result; // [rsp+30h] [rbp+8h]

  v0 = UFG::TodoMoveToXmlPreloadCriticalResources;
  do
  {
    v1 = UFG::qSymbol::create_from_string(&result, *v0);
    v2 = UFG::PropertySetManager::GetPropertySet(v1);
    if ( v2 )
    {
      v3 = UFG::ObjectResourceManager::sInstance;
      v4 = (UFG::TrueCrowdSet *)UFG::TrueCrowdDataBase::QueryDataBase(
                                  UFG::TrueCrowdDataBase::sTrueCrowdDataBase,
                                  v2,
                                  0i64);
      UFG::ResourcePool::ReleasePreload(&v3->mPool, v4, 1u, 1);
    }
    ++v0;
  }
  while ( (signed __int64)v0 < (signed __int64)&sDrawX );
  v5 = UFG::ObjectResourceManager::sInstance;
  if ( UFG::ObjectResourceManager::sInstance )
  {
    UFG::ObjectResourceManager::~ObjectResourceManager(UFG::ObjectResourceManager::sInstance);
    operator delete[](v5);
  }
  UFG::ObjectResourceManager::sInstance = 0i64;
}

// File Line: 276
// RVA: 0x43E660
void __fastcall UFG::ObjectResourceManager::InitDescriptors(UFG::ObjectResourceManager *this)
{
  UFG::qArray<UFG::qSymbol,0> *v1; // r12
  UFG::ObjectResourceManager *v2; // rbx
  UFG::allocator::free_link *v3; // rax
  bool *v4; // rdi
  unsigned int i; // er9
  __int64 v6; // r8
  signed __int64 v7; // r13
  unsigned int v8; // er14
  __int64 v9; // rsi
  unsigned int v10; // edx
  unsigned int v11; // edi
  unsigned int v12; // edx
  UFG::qSymbol *v13; // rcx
  __int64 v14; // r15
  unsigned int v15; // edi
  unsigned int v16; // esi
  unsigned int v17; // edi
  UFG::allocator::free_link *v18; // rax
  bool *v19; // rbp
  __int64 v20; // r9
  bool *v21; // rax
  UFG::qArray<UFG::qSymbol,0> *v22; // rsi
  UFG::allocator::free_link *v23; // rax
  bool *v24; // rdi
  unsigned int j; // er9
  __int64 v26; // r8
  __int64 v27; // rbp
  unsigned int v28; // edx
  unsigned int v29; // edi
  unsigned int v30; // edx
  UFG::qSymbol *v31; // rcx
  __int64 v32; // rbp
  unsigned int v33; // eax
  unsigned int v34; // edi
  UFG::allocator::free_link *v35; // rax
  bool *v36; // rsi
  __int64 v37; // r9
  bool *v38; // rax

  v1 = &this->mEntityStates[0].mRareSpawnPropertySets;
  *(_WORD *)&this->mEntityStates[0].mUpdateRequired = 256;
  this->mEntityStates[0].mHasMinimumAmbienceRequirement = 1;
  *(_QWORD *)&this->mEntityStates[0].mAmbientModelRatioTarget = 1050253722i64;
  this->mEntityStates[0].mResourceUpdateCallback = (void (__fastcall *)())UFG::EntityTypeState::UpdateCharacterPreloads;
  this->mEntityStates[0].mEntityType = 0;
  *(_QWORD *)&this->mEntityStates[0].mAmbientTextureRatio = 0i64;
  this->mEntityStates[0].mAmbientTextureRatioTarget = 0.64999998;
  this->mEntityStates[0].mAvailableAmbientTextureMemory = 0;
  v2 = this;
  if ( this->mEntityStates[0].mRareSpawnPropertySets.capacity < 2 )
    UFG::qArray<UFG::qSymbol,0>::Reallocate(&this->mEntityStates[0].mRareSpawnPropertySets, 2u, "ObjectResourceManager");
  if ( v2->mEntityStates[0].mRareSpawnIsReady.capacity < 2 && v2->mEntityStates[0].mRareSpawnIsReady.size != 2 )
  {
    v3 = UFG::qMalloc(2ui64, "ObjectResourceManager", 0i64);
    v4 = (bool *)v3;
    if ( v2->mEntityStates[0].mRareSpawnIsReady.p )
    {
      for ( i = 0;
            i < v2->mEntityStates[0].mRareSpawnIsReady.size;
            *((_BYTE *)&v3->mNext + v6) = v2->mEntityStates[0].mRareSpawnIsReady.p[v6] )
      {
        v6 = i++;
      }
      operator delete[](v2->mEntityStates[0].mRareSpawnIsReady.p);
    }
    v2->mEntityStates[0].mRareSpawnIsReady.p = v4;
    v2->mEntityStates[0].mRareSpawnIsReady.capacity = 2;
  }
  v7 = 2i64;
  v8 = 1;
  do
  {
    v9 = v1->size;
    v10 = v1->capacity;
    v11 = v9 + 1;
    if ( (signed int)v9 + 1 > v10 )
    {
      if ( v10 )
        v12 = 2 * v10;
      else
        v12 = 1;
      for ( ; v12 < v11; v12 *= 2 )
        ;
      if ( v12 <= 4 )
        v12 = 4;
      if ( v12 - v11 > 0x10000 )
        v12 = v9 + 65537;
      UFG::qArray<UFG::qSymbol,0>::Reallocate(v1, v12, "qArray.Add");
    }
    v13 = v1->p;
    v1->size = v11;
    v13[v9] = UFG::gNullQSymbol;
    v14 = v2->mEntityStates[0].mRareSpawnIsReady.size;
    v15 = v2->mEntityStates[0].mRareSpawnIsReady.capacity;
    v16 = v14 + 1;
    if ( (signed int)v14 + 1 > v15 )
    {
      if ( v15 )
        v17 = 2 * v15;
      else
        v17 = 1;
      for ( ; v17 < v16; v17 *= 2 )
        ;
      if ( v17 <= 0x10 )
        v17 = 16;
      if ( v17 - v16 > 0x10000 )
        v17 = v14 + 65537;
      if ( v17 != (_DWORD)v14 )
      {
        v18 = UFG::qMalloc(v17, "qArray.Add", 0i64);
        v19 = (bool *)v18;
        if ( v2->mEntityStates[0].mRareSpawnIsReady.p )
        {
          v20 = 0i64;
          if ( v2->mEntityStates[0].mRareSpawnIsReady.size )
          {
            do
            {
              *((_BYTE *)&v18->mNext + v20) = v2->mEntityStates[0].mRareSpawnIsReady.p[v20];
              v20 = (unsigned int)(v20 + 1);
            }
            while ( (unsigned int)v20 < v2->mEntityStates[0].mRareSpawnIsReady.size );
          }
          operator delete[](v2->mEntityStates[0].mRareSpawnIsReady.p);
        }
        v2->mEntityStates[0].mRareSpawnIsReady.p = v19;
        v2->mEntityStates[0].mRareSpawnIsReady.capacity = v17;
      }
    }
    v21 = v2->mEntityStates[0].mRareSpawnIsReady.p;
    v2->mEntityStates[0].mRareSpawnIsReady.size = v16;
    v21[v14] = 0;
    --v7;
  }
  while ( v7 );
  v22 = &v2->mEntityStates[1].mRareSpawnPropertySets;
  v2->mEntityStates[1].mEntityType = 1;
  *(_WORD *)&v2->mEntityStates[1].mUpdateRequired = 256;
  v2->mEntityStates[1].mHasMinimumAmbienceRequirement = 1;
  v2->mEntityStates[1].mResourceUpdateCallback = (void (__fastcall *)())UFG::EntityTypeState::UpdateVehiclePreloads;
  *(_QWORD *)&v2->mEntityStates[1].mAmbientModelRatioTarget = 1059481190i64;
  *(_QWORD *)&v2->mEntityStates[1].mAmbientTextureRatio = 0i64;
  v2->mEntityStates[1].mAmbientTextureRatioTarget = 0.30000001;
  v2->mEntityStates[1].mAvailableAmbientTextureMemory = 0;
  if ( v2->mEntityStates[1].mRareSpawnPropertySets.capacity < 1 )
    UFG::qArray<UFG::qSymbol,0>::Reallocate(&v2->mEntityStates[1].mRareSpawnPropertySets, 1u, "ObjectResourceManager");
  if ( v2->mEntityStates[1].mRareSpawnIsReady.capacity < 1 && v2->mEntityStates[1].mRareSpawnIsReady.size != 1 )
  {
    v23 = UFG::qMalloc(1ui64, "ObjectResourceManager", 0i64);
    v24 = (bool *)v23;
    if ( v2->mEntityStates[1].mRareSpawnIsReady.p )
    {
      for ( j = 0;
            j < v2->mEntityStates[1].mRareSpawnIsReady.size;
            *((_BYTE *)&v23->mNext + v26) = v2->mEntityStates[1].mRareSpawnIsReady.p[v26] )
      {
        v26 = j++;
      }
      operator delete[](v2->mEntityStates[1].mRareSpawnIsReady.p);
    }
    v2->mEntityStates[1].mRareSpawnIsReady.p = v24;
    v2->mEntityStates[1].mRareSpawnIsReady.capacity = 1;
  }
  v27 = v22->size;
  v28 = v2->mEntityStates[1].mRareSpawnPropertySets.capacity;
  v29 = v27 + 1;
  if ( (signed int)v27 + 1 > v28 )
  {
    if ( v28 )
      v30 = 2 * v28;
    else
      v30 = 1;
    for ( ; v30 < v29; v30 *= 2 )
      ;
    if ( v30 <= 4 )
      v30 = 4;
    if ( v30 - v29 > 0x10000 )
      v30 = v27 + 65537;
    UFG::qArray<UFG::qSymbol,0>::Reallocate(&v2->mEntityStates[1].mRareSpawnPropertySets, v30, "qArray.Add");
  }
  v31 = v2->mEntityStates[1].mRareSpawnPropertySets.p;
  v22->size = v29;
  v31[v27] = UFG::gNullQSymbol;
  v32 = v2->mEntityStates[1].mRareSpawnIsReady.size;
  v33 = v2->mEntityStates[1].mRareSpawnIsReady.capacity;
  v34 = v32 + 1;
  if ( (signed int)v32 + 1 > v33 )
  {
    if ( v33 )
      v8 = 2 * v33;
    for ( ; v8 < v34; v8 *= 2 )
      ;
    if ( v8 <= 0x10 )
      v8 = 16;
    if ( v8 - v34 > 0x10000 )
      v8 = v32 + 65537;
    if ( v8 != (_DWORD)v32 )
    {
      v35 = UFG::qMalloc(v8, "qArray.Add", 0i64);
      v36 = (bool *)v35;
      if ( v2->mEntityStates[1].mRareSpawnIsReady.p )
      {
        v37 = 0i64;
        if ( v2->mEntityStates[1].mRareSpawnIsReady.size )
        {
          do
          {
            *((_BYTE *)&v35->mNext + v37) = v2->mEntityStates[1].mRareSpawnIsReady.p[v37];
            v37 = (unsigned int)(v37 + 1);
          }
          while ( (unsigned int)v37 < v2->mEntityStates[1].mRareSpawnIsReady.size );
        }
        operator delete[](v2->mEntityStates[1].mRareSpawnIsReady.p);
      }
      v2->mEntityStates[1].mRareSpawnIsReady.p = v36;
      v2->mEntityStates[1].mRareSpawnIsReady.capacity = v8;
    }
  }
  v38 = v2->mEntityStates[1].mRareSpawnIsReady.p;
  v2->mEntityStates[1].mRareSpawnIsReady.size = v34;
  v38[v32] = 0;
  *(_QWORD *)&v2->mEntityStates[2].mAmbientTextureRatio = 0i64;
  v2->mEntityStates[2].mAvailableAmbientTextureMemory = 0;
  v2->mEntityStates[2].mEntityType = 2;
  *(_WORD *)&v2->mEntityStates[2].mUpdateRequired = 256;
  v2->mEntityStates[2].mHasMinimumAmbienceRequirement = 0;
  v2->mEntityStates[2].mResourceUpdateCallback = (void (__fastcall *)())UFG::EntityTypeState::UpdatePropPreloads;
  *(_QWORD *)&v2->mEntityStates[2].mAmbientModelRatioTarget = 1028443341i64;
  v2->mEntityStates[2].mAmbientTextureRatioTarget = 0.050000001;
}rceUpdateCallback = (void (__fastcall *)())UFG::EntityTypeState::UpdatePropPreloads;
  *(

// File Line: 331
// RVA: 0x43EB30
void __fastcall UFG::ObjectResourceManager::InitPools(UFG::ObjectResourceManager *this)
{
  UFG::ObjectResourceManager *v1; // r14
  unsigned int v2; // esi
  unsigned int v3; // ebp
  unsigned __int64 v4; // rax
  UFG::EntityTypeState **v5; // r15
  signed __int64 v6; // r14
  signed __int64 v7; // r12
  __int64 v8; // r13
  unsigned int v9; // edi
  unsigned int v10; // ebx
  unsigned __int64 v11; // rax
  UFG::allocator::free_link *v12; // rax
  UFG::EntityTypeState **v13; // rbp
  UFG::allocator::free_link *v14; // rdx
  __int64 v15; // r8
  int v16; // ebp
  int v17; // esi
  int v18; // edi
  int v19; // er14
  int v20; // er14
  int v21; // ebx
  int v22; // ebx
  UFG::PartDatabase *v23; // rax
  UFG::ResourcePriorityBucket *v24; // rax
  UFG::qArray<UFG::EntityTypeState *,0> resourceDescriptorList; // [rsp+28h] [rbp-40h]
  UFG::ObjectResourceManager *v26; // [rsp+70h] [rbp+8h]

  v26 = this;
  v1 = this;
  resourceDescriptorList.p = 0i64;
  v2 = 0;
  *(_QWORD *)&resourceDescriptorList.size = 0i64;
  v3 = 4;
  v4 = 32i64;
  if ( !is_mul_ok(4ui64, 8ui64) )
    v4 = -1i64;
  v5 = (UFG::EntityTypeState **)UFG::qMalloc(v4, "ObjectResourceManager", 0i64);
  resourceDescriptorList.p = v5;
  resourceDescriptorList.capacity = 4;
  v6 = (signed __int64)v1->mEntityStates;
  v7 = 3i64;
  do
  {
    v8 = v2;
    v9 = v2 + 1;
    if ( v2 + 1 > v3 )
    {
      v10 = 1;
      if ( v3 )
        v10 = 2 * v3;
      for ( ; v10 < v9; v10 *= 2 )
        ;
      if ( v10 <= 2 )
        v10 = 2;
      if ( v10 - v9 > 0x10000 )
        v10 = v2 + 65537;
      if ( v10 != v2 )
      {
        v11 = 8i64 * v10;
        if ( !is_mul_ok(v10, 8ui64) )
          v11 = -1i64;
        v12 = UFG::qMalloc(v11, "qArray.Add", 0i64);
        v13 = (UFG::EntityTypeState **)v12;
        if ( v5 )
        {
          if ( v2 )
          {
            v14 = v12;
            v15 = v2;
            do
            {
              v14->mNext = *(UFG::allocator::free_link **)((char *)v14 + (char *)v5 - (char *)v12);
              ++v14;
              --v15;
            }
            while ( v15 );
          }
          operator delete[](v5);
        }
        v5 = v13;
        resourceDescriptorList.p = v13;
        v3 = v10;
        resourceDescriptorList.capacity = v10;
      }
    }
    ++v2;
    resourceDescriptorList.size = v9;
    v5[v8] = (UFG::EntityTypeState *)v6;
    v6 += 72i64;
    --v7;
  }
  while ( v7 );
  v16 = UFG::StreamFileWrapper::GetAllocationSize("Data\\Characters\\characterrigs.bin");
  v17 = UFG::StreamFileWrapper::GetAllocationSize("Data\\Characters_New\\characterrigs.bin");
  v18 = UFG::StreamFileWrapper::GetAllocationSize("Data\\Vehicles_New\\dummyvehiclerig.perm.bin");
  v19 = UFG::StreamFileWrapper::GetAllocationSize("Data\\props_new\\proprigs.bin");
  v20 = ((v16 + 4095) & 0xFFFFF000)
      + ((v17 + 4095) & 0xFFFFF000)
      + ((v18 + 4095) & 0xFFFFF000)
      + (((unsigned __int64)UFG::StreamFileWrapper::GetAllocationSize("Data\\Props_new\\PropPhysics.bin") + 4095) & 0xFFFFF000)
      + ((v19 + 4095) & 0xFFFFF000);
  v21 = UFG::StreamFileWrapper::GetAllocationSize("Data\\Vehicles_New\\Global.temp.bin");
  v22 = (((unsigned __int64)UFG::StreamFileWrapper::GetAllocationSize("Data\\Characters_New\\Global.temp.bin") + 4095) & 0xFFFFF000)
      + ((v21 + 4095) & 0xFFFFF000);
  v23 = UFG::PartDatabase::Instance();
  UFG::PartPool::Init(&v23->mPool, v23->mPool.mMaxModelMemory - v20, v23->mPool.mMaxTextureMemory - v22);
  UFG::ResourcePool::Init(
    &v26->mPool,
    DATA_TRUECROWD_RESOURCE,
    DATA_TRUECROWD_TEXTURE_RESOURCE,
    &resourceDescriptorList);
  if ( qSymbol_Reserved.mUID == qSymbol_Critical.mUID )
  {
    v24 = v26->mPool.mCriticalBucket;
  }
  else if ( qSymbol_Reserved.mUID == qSymbol_High.mUID )
  {
    v24 = v26->mPool.mHighBucket;
  }
  else if ( qSymbol_Reserved.mUID == qSymbol_Medium.mUID || qSymbol_Reserved.mUID == qSymbol_Low.mUID )
  {
    v24 = v26->mPool.mLowBucket;
  }
  else
  {
    v24 = v26->mPool.mReservedBucket;
  }
  v24->mReserveSize[0] = 3145728;
  v24->mReserveSize[1] = 0x100000;
  v24->mMaxSize[0] = 3145728;
  v24->mMaxSize[1] = 0x100000;
  if ( v5 )
    operator delete[](v5);
}

// File Line: 367
// RVA: 0x443080
void __fastcall UFG::ObjectResourceManager::SetActiveAmbience(UFG::ObjectResourceManager *this, bool vehicles, bool characters)
{
  this->mEntityStates[1].mActive = vehicles;
  this->mEntityStates[0].mActive = characters;
  if ( !vehicles )
  {
    if ( characters )
    {
      this->mEntityStates[0].mAmbientModelRatioTarget = 0.89999998;
      this->mEntityStates[0].mAmbientTextureRatioTarget = 0.89999998;
LABEL_6:
      this->mEntityStates[1].mAmbientTextureRatioTarget = 0.0;
      this->mEntityStates[1].mAmbientModelRatioTarget = 0.0;
      goto LABEL_7;
    }
LABEL_8:
    this->mEntityStates[0].mAmbientModelRatioTarget = 0.0;
    this->mEntityStates[0].mAmbientTextureRatioTarget = 0.0;
    if ( vehicles )
    {
      this->mEntityStates[1].mAmbientModelRatioTarget = 0.89999998;
      this->mEntityStates[1].mAmbientTextureRatioTarget = 0.89999998;
      goto LABEL_7;
    }
    goto LABEL_6;
  }
  if ( !characters )
    goto LABEL_8;
  this->mEntityStates[1].mAmbientModelRatioTarget = 0.64999998;
  this->mEntityStates[1].mAmbientTextureRatioTarget = 0.30000001;
  this->mEntityStates[0].mAmbientModelRatioTarget = 0.30000001;
  this->mEntityStates[0].mAmbientTextureRatioTarget = 0.64999998;
LABEL_7:
  this->mEntityStates[2].mActive = 1;
  this->mEntityStates[2].mAmbientModelRatioTarget = 0.1;
  this->mEntityStates[2].mAmbientTextureRatioTarget = 0.1;
}

// File Line: 407
// RVA: 0x443130
void __fastcall UFG::ObjectResourceManager::SetFragmentationReservePercentage(UFG::ObjectResourceManager *this, float percent)
{
  this->mPool.mFragmentationReservePercentage = percent;
  this->mPool.mDirty = 1;
}

// File Line: 412
// RVA: 0x43D4D0
__int64 __fastcall UFG::ObjectResourceManager::GetBytesRemainingToLoad(UFG::ObjectResourceManager *this)
{
  unsigned int v1; // er8
  UFG::ResourceRequest **v2; // r9
  __int64 v3; // r10
  UFG::ResourceRequest *v4; // rax
  unsigned int v5; // edx
  UFG::ResourceRequest **v6; // rax
  __int64 v7; // r9
  UFG::ResourceRequest *v8; // rcx

  v1 = 0;
  if ( this->mPool.mQueued.size )
  {
    v2 = this->mPool.mQueued.p;
    v3 = this->mPool.mQueued.size;
    do
    {
      v4 = *v2;
      ++v2;
      v1 += v4->mResource->mModelSize + v4->mResource->mTextureSize;
      --v3;
    }
    while ( v3 );
  }
  v5 = this->mPool.mLoading.size;
  if ( v5 )
  {
    v6 = this->mPool.mLoading.p;
    v7 = v5;
    do
    {
      v8 = *v6;
      ++v6;
      v1 += v8->mResource->mModelSize + v8->mResource->mTextureSize;
      --v7;
    }
    while ( v7 );
  }
  return v1;
}

// File Line: 417
// RVA: 0x43FAE0
void UFG::ObjectResourceManager::PerformEmergencyDump(void)
{
  UFG::ResourcePool::ContractAmbientModels(&UFG::ObjectResourceManager::sInstance->mPool, 0xAu);
}

// File Line: 423
// RVA: 0x43FB00
void __fastcall UFG::ObjectResourceManager::PopulateAmbience(UFG::ObjectResourceManager *this)
{
  UFG::ObjectResourceManager *v1; // rdi
  unsigned int v2; // esi
  bool v3; // bl
  UFG::ResourcePriorityBucket *v4; // r9
  UFG::ResourcePriorityBucket *v5; // r8
  bool v6; // dl
  bool v7; // al

  v1 = this;
  v2 = 0;
  do
  {
    v3 = UFG::ResourcePool::UpdateAmbientPreloads(&v1->mPool);
    UFG::ResourcePool::UpdateRequests(&v1->mPool);
    v4 = v1->mPool.mHighBucket;
    v5 = v1->mPool.mLowBucket;
    v6 = v3;
    if ( v4->mMemoryUsage[0][1]
       + v4->mMemoryUsage[1][1]
       + v4->mMemoryUsage[2][1]
       + v5->mMemoryUsage[0][1]
       + v5->mMemoryUsage[1][1]
       + v5->mMemoryUsage[2][1] > 0xA00000 )
      v6 = 0;
    v7 = v6;
    if ( v5->mMemoryUsage[0][0]
       + v5->mMemoryUsage[1][0]
       + v5->mMemoryUsage[2][0]
       + v4->mMemoryUsage[0][0]
       + v4->mMemoryUsage[1][0]
       + v4->mMemoryUsage[2][0] > 0x2D00000 )
      v7 = 0;
    ++v2;
  }
  while ( v2 < 0xF && v7 );
}

// File Line: 448
// RVA: 0x444680
void __fastcall UFG::ObjectResourceManager::Update(UFG::ObjectResourceManager *this, float deltaTime)
{
  UFG::ObjectResourceManager *v2; // rdi
  bool *v3; // rbx
  signed __int64 v4; // rsi
  UFG::UIHKTextOverlay *v5; // rax
  UFG::qString *v6; // rax
  __int64 v7; // rbx
  char *v8; // rax
  UFG::qString *v9; // rax
  UFG::qString v10; // [rsp+38h] [rbp-B0h]
  UFG::qString v11; // [rsp+60h] [rbp-88h]
  UFG::qString text; // [rsp+88h] [rbp-60h]
  UFG::qString v13; // [rsp+B0h] [rbp-38h]

  v2 = this;
  v3 = &this->mEntityStates[0].mUpdateRequired;
  v4 = 3i64;
  do
  {
    if ( *v3 )
    {
      (*(void (**)(void))(v3 + 28))();
      *v3 = 0;
    }
    v3 += 72;
    --v4;
  }
  while ( v4 );
  UFG::ResourcePool::UpdateAmbientPreloads(&v2->mPool);
  UFG::ObjectResourceManager::UpdateRareRequests(v2);
  UFG::ObjectResourceManager::UpdateRareObjectAvailability(v2);
  UFG::ResourcePool::UpdateRequests(&v2->mPool);
  UFG::ObjectResourceManager::UpdateAvailableVehicles(v2);
  v2->mPool.mDirty = 0;
  if ( UFG::UIHKTweakables::TrafficAvailableVehicles )
  {
    v5 = UFG::UIHKTextOverlay::getInstance();
    if ( v5 )
    {
      if ( !UFG::UISubtitleMessageQueue::IsPlaying(&v5->mSubtitleQueue) )
      {
        UFG::qString::qString(&text, "ff7f50");
        UFG::qString::qString(&v11);
        UFG::qString::Format(&v11, "%d ambient traffic vehicles available", v2->mAmbientVehicles.size);
        UFG::qString::qString(&v13, &text);
        UFG::UIHKTextOverlay::ShowMessageOnScreen(v11.mData, 2.0, 2.0, 100.0, v6);
        UFG::qString::qString(&v10, &customWorldMapCaption);
        v7 = 0i64;
        if ( v2->mAmbientVehicles.size )
        {
          do
          {
            if ( (_DWORD)v7 )
              UFG::qString::operator+=(&v10, ", ");
            v8 = PropertyUtils::Get<char const *>(
                   v2->mAmbientVehicles.p[v7],
                   (UFG::qSymbol *)&qSymbol_Description_13.mUID,
                   DEPTH_RECURSE);
            UFG::qString::operator+=(&v10, v8);
            v7 = (unsigned int)(v7 + 1);
          }
          while ( (unsigned int)v7 < v2->mAmbientVehicles.size );
        }
        UFG::qString::qString(&v13, &text);
        UFG::UIHKTextOverlay::ShowMessageOnScreen(v10.mData, 5.0, 100.0, 100.0, v9);
        UFG::qString::~qString(&v10);
        UFG::qString::~qString(&v11);
        UFG::qString::~qString(&text);
      }
    }
  }
}

// File Line: 501
// RVA: 0x43CDC0
void __fastcall UFG::ObjectResourceManager::FlushResources(UFG::ObjectResourceManager *this, bool forceFlush)
{
  bool v2; // bl
  UFG::ObjectResourceManager *v3; // rdi

  v2 = forceFlush;
  v3 = this;
  if ( forceFlush )
  {
    UFG::ObjectResourceManager::ResetAllRarePreloadStatuses(this, 0);
    UFG::ObjectResourceManager::ResetAllRarePreloadStatuses(v3, Vehicle);
    UFG::ObjectResourceManager::ResetAllRarePreloadStatuses(v3, Prop);
    UFG::ObjectResourceManager::RemoveAllUnwantedRareRequests(v3, 0, v2);
    UFG::ObjectResourceManager::RemoveAllUnwantedRareRequests(v3, Vehicle, v2);
    UFG::ObjectResourceManager::RemoveAllUnwantedRareRequests(v3, Prop, v2);
  }
  UFG::ResourcePool::FlushResources(&v3->mPool, v2);
}

// File Line: 530
// RVA: 0x439950
void __fastcall UFG::ObjectResourceManager::ChangeObjectPriority(UFG::ObjectResourceManager *this, UFG::StreamedResourceComponent *resourceComponent, UFG::qSymbol *newPriority)
{
  unsigned int v3; // eax
  unsigned int v4; // ebx
  UFG::StreamedResourceComponent *v5; // r15
  UFG::ObjectResourceManager *v6; // r14
  signed int v7; // er11
  __int64 v8; // rdi
  unsigned int v9; // ebx
  __int64 v10; // rsi
  UFG::TrueCrowdModel *v11; // r8
  __int64 v12; // rax
  signed __int64 v13; // rax
  UFG::ResourceRequest *v14; // rdx
  UFG::TrueCrowdTextureSet *v15; // rax
  UFG::ResourceRequest *v16; // rcx

  v3 = resourceComponent->mActivePriority.mUID;
  v4 = newPriority->mUID;
  v5 = resourceComponent;
  v6 = this;
  if ( newPriority->mUID != v3 && resourceComponent->mMeshLoader.mTrueCrowdInstance.mNumParts )
  {
    v7 = 2;
    if ( v3 == qSymbol_Critical.mUID )
    {
      LODWORD(v8) = 2;
    }
    else if ( v3 == qSymbol_High.mUID )
    {
      LODWORD(v8) = 3;
    }
    else if ( v3 == qSymbol_Medium.mUID || v3 == qSymbol_Low.mUID )
    {
      LODWORD(v8) = 4;
    }
    else
    {
      LODWORD(v8) = 4;
      if ( v3 == qSymbol_Reserved.mUID )
        LODWORD(v8) = 1;
    }
    if ( v4 != qSymbol_Critical.mUID )
    {
      if ( v4 == qSymbol_High.mUID )
      {
        v7 = 3;
      }
      else if ( v4 == qSymbol_Medium.mUID || v4 == qSymbol_Low.mUID )
      {
        v7 = 4;
      }
      else
      {
        v7 = 4;
        if ( v4 == qSymbol_Reserved.mUID )
          v7 = 1;
      }
    }
    v9 = 0;
    v10 = v7;
    v8 = (signed int)v8;
    if ( resourceComponent->mMeshLoader.mTrueCrowdInstance.mNumParts )
    {
      do
      {
        if ( v5->mMeshLoader.mTrueCrowdInstance.mPart[v9].mModelIndex != -1 )
        {
          v11 = v5->mMeshLoader.mTrueCrowdInstance.mSet->mFiles[v9].p[*((unsigned int *)&v5->mMeshLoader.mHighDefinition
                                                                      + 4 * (v9 + 13i64))];
          if ( v5->mMeshLoader.mHighDefinition )
          {
            v12 = v11->mHighResolutionResource.mOffset;
            if ( v12 )
            {
              v13 = (signed __int64)&v11->mHighResolutionResource + v12;
              if ( v13 )
                v11 = (UFG::TrueCrowdModel *)v13;
            }
          }
          v14 = v11->mRequest;
          if ( v14 )
          {
            ++v14->mPriorityRefCounts[v10];
            v14->mLastReferencedFrame = Illusion::gEngine.mFrameCount;
            --v14->mPriorityRefCounts[v8];
            v14->mLastReferencedFrame = Illusion::gEngine.mFrameCount;
            v6->mPool.mDirty = 1;
          }
          v15 = UFG::MeshResourceLoader::GetTexture(&v5->mMeshLoader, v9);
          if ( v15 )
          {
            v16 = v15->mRequest;
            if ( v16 )
            {
              ++v16->mPriorityRefCounts[v10];
              v16->mLastReferencedFrame = Illusion::gEngine.mFrameCount;
              --v16->mPriorityRefCounts[v8];
              v16->mLastReferencedFrame = Illusion::gEngine.mFrameCount;
              v6->mPool.mDirty = 1;
            }
          }
        }
        ++v9;
      }
      while ( v9 < v5->mMeshLoader.mTrueCrowdInstance.mNumParts );
    }
  }
}

// File Line: 578
// RVA: 0x442790
UFG::PreloadRequest *__fastcall UFG::ObjectResourceManager::RequestPreload(UFG::ObjectResourceManager *this, UFG::qPropertySet *propertySet, __int64 priority, bool directRequest)
{
  bool v4; // si
  int *v5; // rdi
  UFG::ObjectResourceManager *v6; // rbx
  signed int v7; // er10
  UFG::qColour **v8; // rax
  UFG::TrueCrowdSet *v9; // rax
  unsigned int v10; // er8
  unsigned int v11; // ecx
  UFG::EntityTypeState **v12; // rdx
  unsigned int v13; // er8
  int v14; // eax
  UFG::TrueCrowdSet::Instance instance; // [rsp+20h] [rbp-128h]

  v4 = directRequest;
  v5 = (int *)priority;
  v6 = this;
  v7 = 15;
  v8 = &instance.mPart[0].mColourTint;
  do
  {
    --v7;
    *(v8 - 1) = 0i64;
    *v8 = 0i64;
    v8 += 2;
  }
  while ( v7 >= 0 );
  instance.mSet = 0i64;
  instance.mNumParts = 0;
  if ( *(_DWORD *)priority == qSymbol_Low.mUID )
  {
    v9 = (UFG::TrueCrowdSet *)UFG::TrueCrowdDataBase::QueryDataBase(
                                UFG::TrueCrowdDataBase::sTrueCrowdDataBase,
                                propertySet,
                                0i64);
    instance.mSet = v9;
  }
  else
  {
    UFG::TrueCrowdDataBase::QueryInstance(UFG::TrueCrowdDataBase::sTrueCrowdDataBase, propertySet, &instance);
    v9 = instance.mSet;
  }
  v10 = v6->mPool.mEntityStates.size;
  v11 = 0;
  if ( v10 )
  {
    v12 = v6->mPool.mEntityStates.p;
    while ( (*v9->mFiles[0].p)->mType.mValue != (*v12)->mEntityType )
    {
      ++v11;
      ++v12;
      if ( v11 >= v10 )
        goto LABEL_10;
    }
    v13 = v11 + 3;
  }
  else
  {
LABEL_10:
    v13 = -1;
  }
  v14 = *v5;
  if ( *v5 == qSymbol_Reserved.mUID )
    v13 = 0;
  if ( v14 == qSymbol_Critical.mUID )
    v13 = 1;
  if ( v14 == qSymbol_High.mUID )
    v13 = 2;
  return UFG::ResourcePool::RequestPreload(&v6->mPool, &instance, v13, v4);
}

// File Line: 612
// RVA: 0x43FBE0
void __fastcall UFG::ObjectResourceManager::PreLoadCriticalResource(UFG::ObjectResourceManager *this, UFG::qPropertySet *propertySet)
{
  UFG::ObjectResourceManager *v2; // rbx
  signed int v3; // er8
  UFG::qColour **v4; // rax
  UFG::PreloadRequest *v5; // rax
  UFG::TrueCrowdSet::Instance instance; // [rsp+20h] [rbp-128h]

  v2 = this;
  v3 = 15;
  v4 = &instance.mPart[0].mColourTint;
  do
  {
    --v3;
    *(v4 - 1) = 0i64;
    *v4 = 0i64;
    v4 += 2;
  }
  while ( v3 >= 0 );
  instance.mSet = 0i64;
  instance.mNumParts = 0;
  UFG::TrueCrowdDataBase::QueryInstance(UFG::TrueCrowdDataBase::sTrueCrowdDataBase, propertySet, &instance);
  v5 = UFG::ResourcePool::RequestPreload(&v2->mPool, &instance, 1u, 1);
  UFG::ResourcePool::PreloadInstance(&v2->mPool, v5, &instance);
}

// File Line: 620
// RVA: 0x441910
void __fastcall UFG::ObjectResourceManager::ReleaseCriticalResource(UFG::ObjectResourceManager *this, UFG::qPropertySet *propertySet)
{
  UFG::ObjectResourceManager *v2; // rbx
  UFG::TrueCrowdSet *v3; // rax

  v2 = this;
  v3 = (UFG::TrueCrowdSet *)UFG::TrueCrowdDataBase::QueryDataBase(
                              UFG::TrueCrowdDataBase::sTrueCrowdDataBase,
                              propertySet,
                              0i64);
  UFG::ResourcePool::ReleasePreload(&v2->mPool, v3, 1u, 1);
}

// File Line: 626
// RVA: 0x441570
void __fastcall UFG::ObjectResourceManager::ReleaseAllAmbientPreloads(UFG::ObjectResourceManager *this)
{
  UFG::ObjectResourceManager *v1; // rbx

  v1 = this;
  UFG::ResourcePool::ReleaseAmbientPreloads(&this->mPool, Vehicle);
  v1->mCurrentSpawnset = UFG::gNullQSymbol;
  UFG::ObjectResourceManager::ResetAllRarePreloadStatuses(v1, Vehicle);
  UFG::ObjectResourceManager::RemoveAllUnwantedRareRequests(v1, Vehicle, 1);
  UFG::ObjectResourceManager::UpdateAvailableVehicles(v1);
  UFG::ResourcePool::ReleaseAllAmbientPreloads(&v1->mPool);
}

// File Line: 632
// RVA: 0x439850
bool __fastcall UFG::ObjectResourceManager::CanSpawnAmbient(UFG::ObjectResourceManager *this, UFG::qPropertySet *propertySet, component_StreamedResource *dataPtr, bool preloadedOnly)
{
  bool v4; // bl
  UFG::ObjectResourceManager *v5; // rdi
  UFG::TrueCrowdSet *v6; // rax

  v4 = preloadedOnly;
  v5 = this;
  if ( !propertySet )
    return 0;
  v6 = (UFG::TrueCrowdSet *)UFG::TrueCrowdDataBase::QueryDataBase(
                              UFG::TrueCrowdDataBase::sTrueCrowdDataBase,
                              propertySet,
                              dataPtr);
  return UFG::ResourcePool::CanSpawnAmbient(&v5->mPool, v6, v4);
}

// File Line: 642
// RVA: 0x43F280
bool __fastcall UFG::ObjectResourceManager::IsLoaded(UFG::ObjectResourceManager *this, UFG::qPropertySet *propertySet)
{
  UFG::TrueCrowdSet *v2; // rax

  v2 = (UFG::TrueCrowdSet *)UFG::TrueCrowdDataBase::QueryDataBase(
                              UFG::TrueCrowdDataBase::sTrueCrowdDataBase,
                              propertySet,
                              0i64);
  if ( v2 )
    LOBYTE(v2) = UFG::TrueCrowdSet::IsLoaded(v2);
  return (char)v2;
}

// File Line: 668
// RVA: 0x445BD0
void __fastcall UFG::ObjectResourceManager::UpdateCharacterPreloads(UFG::ObjectResourceManager *this)
{
  UFG::ObjectResourceManager *v1; // r14
  int v2; // edx
  unsigned int v3; // er8
  unsigned int v4; // ebx
  unsigned int v5; // er8
  signed __int64 v6; // rdi
  UFG::PreloadRequest *v7; // rax
  unsigned int *v8; // r12
  unsigned int v9; // er13
  int *v10; // r15
  signed __int64 v11; // rdi
  UFG::qPropertyList *v12; // rsi
  int v13; // ebx
  UFG::PreloadRequest *v14; // rax
  __int64 v15; // rdi
  __int64 v16; // rbp
  __int64 v17; // rax
  signed __int64 v18; // rcx
  float v19; // xmm1_4
  signed int v20; // eax
  signed int v21; // ebx
  UFG::PreloadRequest *v22; // rax
  unsigned int v23; // eax
  unsigned int v24; // ebx
  unsigned int v25; // edx
  unsigned int v26; // edx
  UFG::qPropertySet *v27; // rax
  UFG::qPropertyList *v28; // rax
  UFG::qPropertySet *v29; // rax
  UFG::qPropertySet *v30; // rsi
  signed int v31; // edx
  UFG::qColour **v32; // rcx
  UFG::PreloadRequest *v33; // rax
  __int64 v34; // rbp
  unsigned int v35; // ebx
  unsigned int v36; // eax
  int v37; // ebp
  __int64 v38; // rsi
  int v39; // ebp
  __int64 v40; // rcx
  __int64 v41; // rbx
  UFG::qNode<UFG::PreloadRequest,UFG::PreloadRequest> *v42; // rax
  UFG::qArray<UFG::PreloadRequest *,0> *v43; // r8
  int v44; // er9
  signed __int64 v45; // rdx
  unsigned int v46; // eax
  UFG::qPropertySet *v47; // [rsp+20h] [rbp-198h]
  signed __int64 v48; // [rsp+28h] [rbp-190h]
  UFG::TrueCrowdSet::Instance instance; // [rsp+40h] [rbp-178h]
  UFG::qSymbol priority; // [rsp+1C0h] [rbp+8h]
  UFG::qSymbol propSetName; // [rsp+1C8h] [rbp+10h]
  UFG::qSymbol *v52; // [rsp+1D0h] [rbp+18h]
  __int64 v53; // [rsp+1D8h] [rbp+20h]

  v1 = this;
  v2 = 0;
  v3 = this->mPool.mEntityStates.size;
  if ( v3 )
  {
    while ( this->mPool.mEntityStates.p[v2]->mEntityType )
    {
      if ( ++v2 >= v3 )
        goto LABEL_6;
    }
    v4 = v2 + 3;
  }
  else
  {
LABEL_6:
    v4 = -1;
  }
  propSetName.mUID = v4;
  v5 = 0;
  v6 = 16i64 * v4;
  v48 = v6;
  if ( *(unsigned int *)((char *)&this->mPool.mPreloadBuckets->size + v6) > 0 )
  {
    do
    {
      v7 = (*(UFG::PreloadRequest ***)((char *)&this->mPool.mPreloadBuckets->p + v6))[v5];
      *(_QWORD *)&v7->mDesiredInstanceCount = 0i64;
      v7->mVarietyRatio = 0.0;
      v7->mSpawnSetValid = 0;
      ++v5;
    }
    while ( v5 < *(unsigned int *)((char *)&this->mPool.mPreloadBuckets->size + v6) );
  }
  UFG::ObjectResourceManager::ResetAllRarePreloadStatuses(this, 0);
  v8 = &v1->mAvailableDrivers.size;
  v1->mAvailableDrivers.size = 0;
  v1->mDefaultDriver = 0i64;
  v9 = 1;
  if ( UFG::PedSpawnManager::GetInstance() && !UFG::PedSpawnManager::msResourcesSuspended )
  {
    v10 = &UFG::PedSpawnManager::GetInstance()->mActiveSpawnSets[0].mRefCount;
    v11 = 40i64;
    v53 = 40i64;
    do
    {
      if ( *v10 > 0 )
      {
        v12 = UFG::qPropertySet::Get<UFG::qPropertyList>(
                *((UFG::qPropertySet **)v10 - 1),
                (UFG::qSymbol *)&qSymbol_SpawnSet.mUID,
                DEPTH_RECURSE);
        if ( v12 )
        {
          if ( v10[1] >= 0 )
          {
            if ( v10[4] )
            {
              v15 = 0i64;
              v16 = 0i64;
              v52 = (UFG::qSymbol *)(unsigned int)v10[4];
              do
              {
                v17 = v12->mWeights.mOffset;
                if ( v17 && (v18 = (signed __int64)&v12->mWeights + v17) != 0 )
                {
                  v19 = (float)*(signed int *)(v18 + v16);
                  v20 = v12->mTotalWeight;
                }
                else
                {
                  v20 = v12->mNumElements;
                  v19 = *(float *)&FLOAT_1_0;
                }
                v21 = (signed int)(float)((float)v10[1] * (float)(v19 / (float)v20));
                if ( v21 )
                {
                  v47 = *(UFG::qPropertySet **)(v15 + *((_QWORD *)v10 + 3));
                  priority.mUID = qSymbol_Low.mUID;
                  v22 = UFG::ObjectResourceManager::RequestPreload(v1, v47, (__int64)&priority, 0);
                  v22->mDesiredInstanceCount += v21;
                  v23 = *v8;
                  priority.mUID = v23;
                  v24 = v23 + 1;
                  v25 = v1->mAvailableDrivers.capacity;
                  if ( v23 + 1 > v25 )
                  {
                    if ( v25 )
                      v26 = 2 * v25;
                    else
                      v26 = 1;
                    for ( ; v26 < v24; v26 *= 2 )
                      ;
                    if ( v26 <= 2 )
                      v26 = 2;
                    if ( v26 - v24 > 0x10000 )
                      v26 = v23 + 65537;
                    UFG::qArray<UFG::CompositeDrawableComponent *,32>::Reallocate(
                      (UFG::qArray<UFG::qReflectInventoryBase *,0> *)&v1->mAvailableDrivers,
                      v26,
                      "qArray.Add");
                    v23 = priority.mUID;
                  }
                  *v8 = v24;
                  v1->mAvailableDrivers.p[v23] = v47;
                }
                v16 += 4i64;
                v15 += 8i64;
                v52 = (UFG::qSymbol *)((char *)v52 - 1);
              }
              while ( v52 );
              v11 = v53;
            }
            UFG::ObjectResourceManager::UpdateRareSpawnResourcesFromPropertySet(v1, 0, *((UFG::qPropertySet **)v10 - 1));
          }
        }
        else
        {
          v13 = *v10;
          v52 = &priority;
          priority.mUID = qSymbol_Low.mUID;
          v14 = UFG::ObjectResourceManager::RequestPreload(v1, *((UFG::qPropertySet **)v10 - 1), (__int64)&priority, 0);
          v14->mDesiredInstanceCount += v13;
        }
      }
      v10 += 14;
      v53 = --v11;
    }
    while ( v11 );
    v6 = v48;
    v4 = propSetName.mUID;
  }
  if ( v1->mEntityStates[1].mActive )
  {
    v27 = UFG::PropertySetManager::FindPropertySet((UFG::qSymbol *)&qSymbolX_spawnset_default.mUID);
    v28 = UFG::qPropertySet::Get<UFG::qPropertyList>(v27, (UFG::qSymbol *)&qSymbol_SpawnSet.mUID, DEPTH_RECURSE);
    if ( v28->mNumElements )
    {
      propSetName.mUID = UFG::qPropertyList::Get<UFG::qSymbol>(v28, 0)->mUID;
      v29 = UFG::PropertySetManager::FindPropertySet(&propSetName);
      v30 = v29;
      v1->mDefaultDriver = v29;
      v31 = 15;
      v32 = &instance.mPart[0].mColourTint;
      do
      {
        *(v32 - 1) = 0i64;
        *v32 = 0i64;
        v32 += 2;
        --v31;
      }
      while ( v31 >= 0 );
      instance.mSet = 0i64;
      instance.mNumParts = 0;
      UFG::TrueCrowdDataBase::QueryInstance(UFG::TrueCrowdDataBase::sTrueCrowdDataBase, v29, &instance);
      v52 = &priority;
      priority.mUID = qSymbol_Low.mUID;
      v33 = UFG::ObjectResourceManager::RequestPreload(v1, v30, (__int64)&priority, 0);
      v33->mDesiredInstanceCount = 1;
      UFG::ResourcePool::PreloadInstance(&v1->mPool, v33, &instance);
      v34 = *v8;
      v35 = v34 + 1;
      v36 = v1->mAvailableDrivers.capacity;
      if ( (signed int)v34 + 1 > v36 )
      {
        if ( v36 )
          v9 = 2 * v36;
        for ( ; v9 < v35; v9 *= 2 )
          ;
        if ( v9 <= 2 )
          v9 = 2;
        if ( v9 - v35 > 0x10000 )
          v9 = v34 + 65537;
        UFG::qArray<UFG::CompositeDrawableComponent *,32>::Reallocate(
          (UFG::qArray<UFG::qReflectInventoryBase *,0> *)&v1->mAvailableDrivers,
          v9,
          "qArray.Add");
      }
      *v8 = v35;
      v1->mAvailableDrivers.p[v34] = v30;
    }
    v37 = *(unsigned int *)((char *)&v1->mPool.mPreloadBuckets->size + v6) - 1;
    v38 = v37;
    if ( v37 >= 0 )
    {
      v39 = *(unsigned int *)((char *)&v1->mPool.mPreloadBuckets->size + v6);
      do
      {
        v40 = *(__int64 *)((char *)&v1->mPool.mPreloadBuckets->p + v6);
        v41 = *(_QWORD *)(v40 + 8 * v38);
        if ( !*(_BYTE *)(v41 + 313) && !*(_DWORD *)(v41 + 316) )
        {
          UFG::ResourcePool::ReleaseResourceSetFiles(&v1->mPool, *(UFG::PreloadRequest **)(v40 + 8 * v38));
          *(_QWORD *)(v41 + 16) = 0i64;
          *(_DWORD *)(v41 + 24) = 0;
          v42 = v1->mPool.mEmptyRequestList.mNode.mPrev;
          v42->mNext = (UFG::qNode<UFG::PreloadRequest,UFG::PreloadRequest> *)v41;
          *(_QWORD *)v41 = v42;
          *(_QWORD *)(v41 + 8) = (char *)v1 + 144;
          v1->mPool.mEmptyRequestList.mNode.mPrev = (UFG::qNode<UFG::PreloadRequest,UFG::PreloadRequest> *)v41;
          v43 = v1->mPool.mPreloadBuckets;
          v44 = v39;
          if ( v39 != *(unsigned int *)((char *)&v43->size + v6) )
          {
            v45 = 8 * v38 + 8;
            do
            {
              *(UFG::PreloadRequest **)(*(char **)((char *)&v43->p + v6) + v45 - 8) = *(UFG::PreloadRequest **)(*(char **)((char *)&v43->p + v6) + v45);
              ++v44;
              v45 += 8i64;
            }
            while ( v44 != *(unsigned int *)((char *)&v43->size + v6) );
          }
          v46 = *(unsigned int *)((char *)&v43->size + v6);
          if ( v46 > 1 )
            *(unsigned int *)((char *)&v43->size + v6) = v46 - 1;
          else
            *(unsigned int *)((char *)&v43->size + v6) = 0;
        }
        --v39;
        --v38;
      }
      while ( v38 >= 0 );
    }
  }
  else
  {
    UFG::ResourcePool::ReleaseAllUnReferencedPreloads(&v1->mPool, v4, UFG::PedSpawnManager::msResourcesSuspended);
  }
  UFG::ObjectResourceManager::RemoveAllUnwantedRareRequests(v1, 0, UFG::PedSpawnManager::msResourcesSuspended);
  v1->mEntityStates[2].mUpdateRequired = 1;
  v1->mPool.mDirty = 1;
}

// File Line: 762
// RVA: 0x4466D0
void __fastcall UFG::ObjectResourceManager::UpdatePropPreloads(UFG::ObjectResourceManager *this)
{
  UFG::ObjectResourceManager *v1; // rdi
  int v2; // edx
  unsigned int v3; // er8
  unsigned int v4; // edx
  unsigned int v5; // er8
  __int64 v6; // r12
  UFG::PreloadRequest *v7; // rdx
  UFG::PedSpawnManager *v8; // rax
  signed __int64 v9; // r15
  signed __int64 v10; // r13
  UFG::qPropertyList *v11; // rax
  UFG::qPropertyList *v12; // rsi
  unsigned int v13; // ebp
  unsigned int v14; // ebx
  UFG::qSymbol *v15; // rax
  UFG::qPropertySet *v16; // rax
  __int64 v17; // r14
  UFG::qPropertyList *v18; // rax
  UFG::qPropertyList *v19; // rbp
  unsigned int v20; // esi
  unsigned int v21; // ebx
  UFG::qSymbol *v22; // rax
  UFG::qPropertySet *v23; // rax
  int v24; // eax
  __int64 v25; // rbp
  unsigned int v26; // er14
  UFG::ObjectResourceManager::RareSpawnRecord *v27; // rsi
  int v28; // ecx
  UFG::qArray<UFG::PreloadRequest *,0> *v29; // r9
  unsigned int v30; // er8
  UFG::PreloadRequest **v31; // r9
  UFG::TrueCrowdSet *v32; // r10
  UFG::PreloadRequest *v33; // rdx
  int v34; // ecx
  UFG::PreloadRequest *v35; // rbx
  UFG::qArray<UFG::PreloadRequest *,0> *v36; // r9
  __int64 v37; // rcx
  unsigned int v38; // edx
  UFG::PreloadRequest **v39; // r8
  UFG::qNode<UFG::PreloadRequest,UFG::PreloadRequest> *v40; // rax
  UFG::qNode<UFG::ObjectResourceManager::RareSpawnRecord,UFG::ObjectResourceManager::RareSpawnRecord> *v41; // rax
  unsigned int v42; // er8
  signed __int64 v43; // rdx
  unsigned int v44; // eax
  int v45; // ebp
  __int64 v46; // rsi
  unsigned int v47; // ebp
  UFG::PreloadRequest **v48; // rcx
  UFG::PreloadRequest *v49; // rbx
  UFG::qNode<UFG::PreloadRequest,UFG::PreloadRequest> *v50; // rax
  UFG::qArray<UFG::PreloadRequest *,0> *v51; // r8
  unsigned int v52; // er9
  signed __int64 v53; // rdx
  unsigned int v54; // eax
  UFG::qSymbol priority; // [rsp+70h] [rbp+8h]
  UFG::qSymbol *v56; // [rsp+78h] [rbp+10h]

  v1 = this;
  v2 = 0;
  v3 = this->mPool.mEntityStates.size;
  if ( v3 )
  {
    while ( this->mPool.mEntityStates.p[v2]->mEntityType != 2 )
    {
      if ( ++v2 >= v3 )
        goto LABEL_6;
    }
    v4 = v2 + 3;
  }
  else
  {
LABEL_6:
    v4 = -1;
  }
  v5 = 0;
  v6 = v4;
  if ( this->mPool.mPreloadBuckets[v4].size > 0 )
  {
    do
    {
      v7 = this->mPool.mPreloadBuckets[v6].p[v5];
      *(_QWORD *)&v7->mDesiredInstanceCount = 0i64;
      v7->mVarietyRatio = 0.0;
      v7->mSpawnSetValid = 0;
      ++v5;
    }
    while ( v5 < this->mPool.mPreloadBuckets[v6].size );
  }
  UFG::ObjectResourceManager::ResetAllRarePreloadStatuses(this, Prop);
  v8 = UFG::PedSpawnManager::GetInstance();
  if ( v8 && !UFG::PedSpawnManager::msResourcesSuspended )
  {
    v9 = (signed __int64)&v8->mActiveSpawnSets[0].mSpawnInfoArray;
    v10 = 40i64;
    do
    {
      if ( *(_DWORD *)(v9 - 16) > 0 )
      {
        if ( *(_DWORD *)v9 )
        {
          v17 = 0i64;
          if ( *(_DWORD *)v9 )
          {
            do
            {
              v18 = UFG::qPropertySet::Get<UFG::qPropertyList>(
                      *(UFG::qPropertySet **)(*(_QWORD *)(v9 + 8) + 8 * v17),
                      (UFG::qSymbol *)&qSymbol_PropList.mUID,
                      DEPTH_RECURSE);
              v19 = v18;
              if ( v18 )
              {
                v20 = v18->mNumElements;
                v21 = 0;
                if ( v20 )
                {
                  do
                  {
                    v22 = UFG::qPropertyList::Get<UFG::qSymbol>(v19, v21);
                    if ( v22->mUID != UFG::gNullQSymbol.mUID )
                    {
                      v23 = UFG::PropertySetManager::FindPropertySet(v22);
                      v56 = &priority;
                      priority.mUID = qSymbol_Low.mUID;
                      UFG::ObjectResourceManager::RequestPreload(v1, v23, (__int64)&priority, 0);
                    }
                    ++v21;
                  }
                  while ( v21 < v20 );
                }
              }
              v17 = (unsigned int)(v17 + 1);
            }
            while ( (unsigned int)v17 < *(_DWORD *)v9 );
          }
        }
        else
        {
          v11 = UFG::qPropertySet::Get<UFG::qPropertyList>(
                  *(UFG::qPropertySet **)(v9 - 24),
                  (UFG::qSymbol *)&qSymbol_PropList.mUID,
                  DEPTH_RECURSE);
          v12 = v11;
          if ( v11 )
          {
            v13 = v11->mNumElements;
            v14 = 0;
            if ( v13 )
            {
              v56 = &priority;
              do
              {
                v15 = UFG::qPropertyList::Get<UFG::qSymbol>(v12, v14);
                v16 = UFG::PropertySetManager::FindPropertySet(v15);
                priority.mUID = qSymbol_Low.mUID;
                UFG::ObjectResourceManager::RequestPreload(v1, v16, (__int64)&priority, 0);
                ++v14;
              }
              while ( v14 < v13 );
            }
          }
        }
      }
      v9 += 56i64;
      --v10;
    }
    while ( v10 );
  }
  v24 = v1->mRareSpawnList[2].size - 1;
  v25 = v24;
  if ( v24 >= 0 )
  {
    v26 = v1->mRareSpawnList[2].size;
    do
    {
      v27 = v1->mRareSpawnList[2].p[v25];
      v28 = 0;
      v29 = v1->mPool.mPreloadBuckets;
      v30 = v29->size;
      if ( v29->size )
      {
        v31 = v29->p;
        v32 = v27->mInstance.mSet;
        while ( 1 )
        {
          v33 = v31[v28];
          if ( v33->mInstance.mSet == v32 )
            break;
          if ( ++v28 >= v30 )
            goto LABEL_57;
        }
        if ( !v33->mSpawnSetValid && !v33->mDirectRequestCount )
        {
          v34 = 0;
          while ( 1 )
          {
            v35 = v31[v34];
            if ( v35->mInstance.mSet == v32 )
              break;
            if ( ++v34 >= v30 )
              goto LABEL_51;
          }
          v35->mSpawnSetValid = 0;
          if ( !v35->mDirectRequestCount )
          {
            UFG::ResourcePool::ReleaseResourceSetFiles(&v1->mPool, v35);
            v36 = v1->mPool.mPreloadBuckets;
            v37 = 0i64;
            v38 = v36->size;
            if ( v36->size )
            {
              v39 = v36->p;
              while ( v35 != v39[v37] )
              {
                v37 = (unsigned int)(v37 + 1);
                if ( (unsigned int)v37 >= v38 )
                  goto LABEL_50;
              }
              if ( (signed int)v37 >= 0 )
              {
                v39[v37] = v39[v38 - 1];
                if ( v36->size > 1 )
                  --v36->size;
                else
                  v36->size = 0;
              }
            }
LABEL_50:
            v40 = v1->mPool.mEmptyRequestList.mNode.mPrev;
            v40->mNext = (UFG::qNode<UFG::PreloadRequest,UFG::PreloadRequest> *)&v35->mPrev;
            v35->mPrev = v40;
            v35->mNext = &v1->mPool.mEmptyRequestList.mNode;
            v1->mPool.mEmptyRequestList.mNode.mPrev = (UFG::qNode<UFG::PreloadRequest,UFG::PreloadRequest> *)&v35->mPrev;
          }
LABEL_51:
          v41 = v1->mEmptyRareSpawnList.mNode.mPrev;
          v41->mNext = (UFG::qNode<UFG::ObjectResourceManager::RareSpawnRecord,UFG::ObjectResourceManager::RareSpawnRecord> *)&v27->mPrev;
          v27->mPrev = v41;
          v27->mNext = &v1->mEmptyRareSpawnList.mNode;
          v1->mEmptyRareSpawnList.mNode.mPrev = (UFG::qNode<UFG::ObjectResourceManager::RareSpawnRecord,UFG::ObjectResourceManager::RareSpawnRecord> *)&v27->mPrev;
          v42 = v26;
          if ( v26 != v1->mRareSpawnList[2].size )
          {
            v43 = 8 * v25 + 8;
            do
            {
              *(UFG::ObjectResourceManager::RareSpawnRecord **)((char *)v1->mRareSpawnList[2].p + v43 - 8) = *(UFG::ObjectResourceManager::RareSpawnRecord **)((char *)v1->mRareSpawnList[2].p + v43);
              ++v42;
              v43 += 8i64;
            }
            while ( v42 != v1->mRareSpawnList[2].size );
          }
          v44 = v1->mRareSpawnList[2].size;
          if ( v44 > 1 )
            v1->mRareSpawnList[2].size = v44 - 1;
          else
            v1->mRareSpawnList[2].size = 0;
        }
      }
LABEL_57:
      --v26;
      --v25;
    }
    while ( v25 >= 0 );
  }
  v45 = v1->mPool.mPreloadBuckets[v6].size - 1;
  v46 = v45;
  if ( v45 >= 0 )
  {
    v47 = v1->mPool.mPreloadBuckets[v6].size;
    do
    {
      v48 = v1->mPool.mPreloadBuckets[v6].p;
      v49 = v48[v46];
      if ( !v49->mSpawnSetValid && !v49->mDirectRequestCount )
      {
        UFG::ResourcePool::ReleaseResourceSetFiles(&v1->mPool, v48[v46]);
        *(_QWORD *)&v49->mDesiredInstanceCount = 0i64;
        v49->mVarietyRatio = 0.0;
        v50 = v1->mPool.mEmptyRequestList.mNode.mPrev;
        v50->mNext = (UFG::qNode<UFG::PreloadRequest,UFG::PreloadRequest> *)&v49->mPrev;
        v49->mPrev = v50;
        v49->mNext = &v1->mPool.mEmptyRequestList.mNode;
        v1->mPool.mEmptyRequestList.mNode.mPrev = (UFG::qNode<UFG::PreloadRequest,UFG::PreloadRequest> *)&v49->mPrev;
        v51 = v1->mPool.mPreloadBuckets;
        v52 = v47;
        if ( v47 != v51[v6].size )
        {
          v53 = 8 * v46 + 8;
          do
          {
            *(UFG::PreloadRequest **)((char *)v51[v6].p + v53 - 8) = *(UFG::PreloadRequest **)((char *)v51[v6].p + v53);
            ++v52;
            v53 += 8i64;
          }
          while ( v52 != v51[v6].size );
        }
        v54 = v51[v6].size;
        if ( v54 > 1 )
          v51[v6].size = v54 - 1;
        else
          v51[v6].size = 0;
      }
      --v47;
      --v46;
    }
    while ( v46 >= 0 );
  }
  v1->mPool.mDirty = 1;
}

// File Line: 824
// RVA: 0x447540
void __fastcall UFG::ObjectResourceManager::UpdateVehiclePreloads(UFG::ObjectResourceManager *this)
{
  UFG::ObjectResourceManager *v1; // rbx
  int v2; // edx
  unsigned int v3; // er8
  unsigned int v4; // edx
  unsigned int v5; // er8
  __int64 v6; // rsi
  UFG::PreloadRequest *v7; // rdx
  unsigned int v8; // er9
  unsigned int v9; // edx
  unsigned int v10; // ecx
  unsigned int v11; // eax
  unsigned int v12; // ebp
  UFG::qSymbol *v13; // rax
  unsigned int v14; // edx
  UFG::qPropertySet *v15; // r12
  UFG::qPropertyList *v16; // r15
  unsigned int v17; // er14
  unsigned int v18; // edi
  int v19; // ebp
  UFG::qSymbol *v20; // rax
  UFG::qPropertySet *v21; // rax
  UFG::PreloadRequest *v22; // rax
  int v23; // eax
  __int64 v24; // rbp
  unsigned int v25; // er15
  UFG::ObjectResourceManager::RareSpawnRecord *v26; // r14
  int v27; // ecx
  UFG::qArray<UFG::PreloadRequest *,0> *v28; // r9
  unsigned int v29; // er8
  UFG::PreloadRequest **v30; // r9
  UFG::TrueCrowdSet *v31; // r10
  UFG::PreloadRequest *v32; // rdx
  int v33; // ecx
  UFG::PreloadRequest *v34; // rdi
  UFG::qArray<UFG::PreloadRequest *,0> *v35; // r9
  __int64 v36; // rcx
  unsigned int v37; // edx
  UFG::PreloadRequest **v38; // r8
  UFG::qNode<UFG::PreloadRequest,UFG::PreloadRequest> *v39; // rax
  UFG::qNode<UFG::ObjectResourceManager::RareSpawnRecord,UFG::ObjectResourceManager::RareSpawnRecord> *v40; // rax
  unsigned int v41; // er8
  signed __int64 v42; // rdx
  unsigned int v43; // eax
  int v44; // er14
  __int64 v45; // rbp
  unsigned int v46; // er14
  UFG::PreloadRequest **v47; // rcx
  UFG::PreloadRequest *v48; // rdi
  UFG::qNode<UFG::PreloadRequest,UFG::PreloadRequest> *v49; // rax
  UFG::qArray<UFG::PreloadRequest *,0> *v50; // r8
  unsigned int v51; // er9
  signed __int64 v52; // rdx
  unsigned int v53; // eax
  UFG::qSymbol result; // [rsp+70h] [rbp+8h]
  UFG::qSymbol *v55; // [rsp+78h] [rbp+10h]

  v1 = this;
  v2 = 0;
  v3 = this->mPool.mEntityStates.size;
  if ( v3 )
  {
    while ( this->mPool.mEntityStates.p[v2]->mEntityType != 1 )
    {
      if ( ++v2 >= v3 )
        goto LABEL_6;
    }
    v4 = v2 + 3;
  }
  else
  {
LABEL_6:
    v4 = -1;
  }
  v5 = 0;
  v6 = v4;
  if ( this->mPool.mPreloadBuckets[v4].size > 0 )
  {
    do
    {
      v7 = this->mPool.mPreloadBuckets[v6].p[v5];
      *(_QWORD *)&v7->mDesiredInstanceCount = 0i64;
      v7->mVarietyRatio = 0.0;
      v7->mSpawnSetValid = 0;
      ++v5;
    }
    while ( v5 < this->mPool.mPreloadBuckets[v6].size );
  }
  UFG::ObjectResourceManager::ResetAllRarePreloadStatuses(this, Vehicle);
  if ( v1->mEntityStates[1].mActive )
  {
    v8 = UFG::WheeledVehicleManager::m_Instance->mNumTrafficCars;
    v9 = UFG::WheeledVehicleManager::m_Instance->mNumParkedCars;
    v10 = v8 < UFG::WheeledVehicleManager::mMaxTrafficCars ? UFG::WheeledVehicleManager::mMaxTrafficCars - v8 : 0;
    v11 = v9 < UFG::WheeledVehicleManager::mMaxParkedCars ? UFG::WheeledVehicleManager::mMaxParkedCars - v9 : 0;
    v12 = v8 + v9 + v11 + v10;
    v13 = UFG::WheeledVehicleManager::GetCurrentTrafficSet(UFG::WheeledVehicleManager::m_Instance, &result);
    v14 = v13->mUID;
    v1->mCurrentSpawnset = (UFG::qSymbol)v13->mUID;
    if ( v14 != UFG::gNullQSymbol.mUID )
    {
      v15 = UFG::PropertySetManager::CreateOrFindPropertySet(&v1->mCurrentSpawnset);
      v16 = UFG::qPropertySet::Get<UFG::qPropertyList>(v15, (UFG::qSymbol *)&qSymbol_SpawnSet.mUID, DEPTH_RECURSE);
      v17 = v16->mNumElements;
      v18 = 0;
      if ( v17 )
      {
        v55 = &result;
        v19 = v12 / v17;
        do
        {
          v20 = UFG::qPropertyList::Get<UFG::qSymbol>(v16, v18);
          v21 = UFG::PropertySetManager::CreateOrFindPropertySet(v20);
          result.mUID = qSymbol_Low.mUID;
          v22 = UFG::ObjectResourceManager::RequestPreload(v1, v21, (__int64)&result, 0);
          v22->mDesiredInstanceCount += v19;
          ++v18;
        }
        while ( v18 < v17 );
      }
      UFG::ObjectResourceManager::UpdateRareSpawnResourcesFromPropertySet(v1, Vehicle, v15);
      UFG::ObjectResourceManager::UpdateAvailableVehicles(v1);
    }
  }
  v23 = v1->mRareSpawnList[1].size - 1;
  v24 = v23;
  if ( v23 >= 0 )
  {
    v25 = v1->mRareSpawnList[1].size;
    do
    {
      v26 = v1->mRareSpawnList[1].p[v24];
      v27 = 0;
      v28 = v1->mPool.mPreloadBuckets;
      v29 = v28->size;
      if ( v28->size )
      {
        v30 = v28->p;
        v31 = v26->mInstance.mSet;
        while ( 1 )
        {
          v32 = v30[v27];
          if ( v32->mInstance.mSet == v31 )
            break;
          if ( ++v27 >= v29 )
            goto LABEL_51;
        }
        if ( !v32->mSpawnSetValid && !v32->mDirectRequestCount )
        {
          v33 = 0;
          while ( 1 )
          {
            v34 = v30[v33];
            if ( v34->mInstance.mSet == v31 )
              break;
            if ( ++v33 >= v29 )
              goto LABEL_45;
          }
          v34->mSpawnSetValid = 0;
          if ( !v34->mDirectRequestCount )
          {
            UFG::ResourcePool::ReleaseResourceSetFiles(&v1->mPool, v34);
            v35 = v1->mPool.mPreloadBuckets;
            v36 = 0i64;
            v37 = v35->size;
            if ( v35->size )
            {
              v38 = v35->p;
              while ( v34 != v38[v36] )
              {
                v36 = (unsigned int)(v36 + 1);
                if ( (unsigned int)v36 >= v37 )
                  goto LABEL_44;
              }
              if ( (signed int)v36 >= 0 )
              {
                v38[v36] = v38[v37 - 1];
                if ( v35->size > 1 )
                  --v35->size;
                else
                  v35->size = 0;
              }
            }
LABEL_44:
            v39 = v1->mPool.mEmptyRequestList.mNode.mPrev;
            v39->mNext = (UFG::qNode<UFG::PreloadRequest,UFG::PreloadRequest> *)&v34->mPrev;
            v34->mPrev = v39;
            v34->mNext = &v1->mPool.mEmptyRequestList.mNode;
            v1->mPool.mEmptyRequestList.mNode.mPrev = (UFG::qNode<UFG::PreloadRequest,UFG::PreloadRequest> *)&v34->mPrev;
          }
LABEL_45:
          v40 = v1->mEmptyRareSpawnList.mNode.mPrev;
          v40->mNext = (UFG::qNode<UFG::ObjectResourceManager::RareSpawnRecord,UFG::ObjectResourceManager::RareSpawnRecord> *)&v26->mPrev;
          v26->mPrev = v40;
          v26->mNext = &v1->mEmptyRareSpawnList.mNode;
          v1->mEmptyRareSpawnList.mNode.mPrev = (UFG::qNode<UFG::ObjectResourceManager::RareSpawnRecord,UFG::ObjectResourceManager::RareSpawnRecord> *)&v26->mPrev;
          v41 = v25;
          if ( v25 != v1->mRareSpawnList[1].size )
          {
            v42 = 8 * v24 + 8;
            do
            {
              *(UFG::ObjectResourceManager::RareSpawnRecord **)((char *)v1->mRareSpawnList[1].p + v42 - 8) = *(UFG::ObjectResourceManager::RareSpawnRecord **)((char *)v1->mRareSpawnList[1].p + v42);
              ++v41;
              v42 += 8i64;
            }
            while ( v41 != v1->mRareSpawnList[1].size );
          }
          v43 = v1->mRareSpawnList[1].size;
          if ( v43 > 1 )
            v1->mRareSpawnList[1].size = v43 - 1;
          else
            v1->mRareSpawnList[1].size = 0;
        }
      }
LABEL_51:
      --v25;
      --v24;
    }
    while ( v24 >= 0 );
  }
  v44 = v1->mPool.mPreloadBuckets[v6].size - 1;
  v45 = v44;
  if ( v44 >= 0 )
  {
    v46 = v1->mPool.mPreloadBuckets[v6].size;
    do
    {
      v47 = v1->mPool.mPreloadBuckets[v6].p;
      v48 = v47[v45];
      if ( !v48->mSpawnSetValid && !v48->mDirectRequestCount )
      {
        UFG::ResourcePool::ReleaseResourceSetFiles(&v1->mPool, v47[v45]);
        *(_QWORD *)&v48->mDesiredInstanceCount = 0i64;
        v48->mVarietyRatio = 0.0;
        v49 = v1->mPool.mEmptyRequestList.mNode.mPrev;
        v49->mNext = (UFG::qNode<UFG::PreloadRequest,UFG::PreloadRequest> *)&v48->mPrev;
        v48->mPrev = v49;
        v48->mNext = &v1->mPool.mEmptyRequestList.mNode;
        v1->mPool.mEmptyRequestList.mNode.mPrev = (UFG::qNode<UFG::PreloadRequest,UFG::PreloadRequest> *)&v48->mPrev;
        v50 = v1->mPool.mPreloadBuckets;
        v51 = v46;
        if ( v46 != v50[v6].size )
        {
          v52 = 8 * v45 + 8;
          do
          {
            *(UFG::PreloadRequest **)((char *)v50[v6].p + v52 - 8) = *(UFG::PreloadRequest **)((char *)v50[v6].p + v52);
            ++v51;
            v52 += 8i64;
          }
          while ( v51 != v50[v6].size );
        }
        v53 = v50[v6].size;
        if ( v53 > 1 )
          v50[v6].size = v53 - 1;
        else
          v50[v6].size = 0;
      }
      --v46;
      --v45;
    }
    while ( v45 >= 0 );
  }
  v1->mPool.mDirty = 1;
}

// File Line: 874
// RVA: 0x43DDF0
UFG::qPropertySet *__fastcall UFG::ObjectResourceManager::GetRandomPropSetFromCurrentTrafficSet(UFG::ObjectResourceManager *this)
{
  UFG::qSymbol *v1; // rcx
  UFG::qPropertySet *v2; // rax
  UFG::qPropertyList *v3; // rax
  UFG::qPropertyList *v4; // rbx
  unsigned int v5; // eax
  UFG::qSymbol *v6; // rax

  v1 = &this->mCurrentSpawnset;
  if ( v1->mUID == UFG::gNullQSymbol.mUID )
    return 0i64;
  v2 = UFG::PropertySetManager::CreateOrFindPropertySet(v1);
  v3 = UFG::qPropertySet::Get<UFG::qPropertyList>(v2, (UFG::qSymbol *)&qSymbol_SpawnSet.mUID, DEPTH_RECURSE);
  v4 = v3;
  v5 = UFG::qPropertyList::GetRandomIndex(v3);
  v6 = UFG::qPropertyList::Get<UFG::qSymbol>(v4, v5);
  return UFG::PropertySetManager::CreateOrFindPropertySet(v6);
}

// File Line: 893
// RVA: 0x444630
void __fastcall UFG::ObjectResourceManager::UnloadAmbientVehicles(UFG::ObjectResourceManager *this)
{
  UFG::ObjectResourceManager *v1; // rbx

  v1 = this;
  UFG::ResourcePool::ReleaseAmbientPreloads(&this->mPool, Vehicle);
  v1->mCurrentSpawnset = UFG::gNullQSymbol;
  UFG::ObjectResourceManager::ResetAllRarePreloadStatuses(v1, Vehicle);
  UFG::ObjectResourceManager::RemoveAllUnwantedRareRequests(v1, Vehicle, 1);
  UFG::ObjectResourceManager::UpdateAvailableVehicles(v1);
}

// File Line: 902
// RVA: 0x445850
void __fastcall UFG::ObjectResourceManager::UpdateAvailableVehicles(UFG::ObjectResourceManager *this)
{
  UFG::ObjectResourceManager *v1; // r15
  UFG::qArray<UFG::qReflectInventoryBase *,0> *v2; // rsi
  unsigned int v3; // edi
  UFG::qSymbol *v4; // rcx
  UFG::qPropertySet *v5; // rax
  UFG::qPropertyList *v6; // r13
  unsigned int v7; // er12
  UFG::qSymbol *v8; // rax
  UFG::qPropertySet *v9; // rax
  UFG::qPropertySet *v10; // rbp
  UFG::TrueCrowdSet *v11; // rax
  UFG::TrueCrowdSet *v12; // rax
  __int64 v13; // r14
  unsigned int v14; // edx
  unsigned int v15; // ebx
  unsigned int v16; // edx
  UFG::qReflectInventoryBase **v17; // rax

  v1 = this;
  if ( this->mPool.mDirty )
  {
    v2 = (UFG::qArray<UFG::qReflectInventoryBase *,0> *)&this->mAmbientVehicles;
    v3 = 0;
    v4 = &this->mCurrentSpawnset;
    v2->size = 0;
    if ( v4->mUID != UFG::gNullQSymbol.mUID )
    {
      v5 = UFG::PropertySetManager::CreateOrFindPropertySet(v4);
      v6 = UFG::qPropertySet::Get<UFG::qPropertyList>(v5, (UFG::qSymbol *)&qSymbol_SpawnSet.mUID, DEPTH_RECURSE);
      v7 = v6->mNumElements;
      if ( v7 )
      {
        do
        {
          v8 = UFG::qPropertyList::Get<UFG::qSymbol>(v6, v3);
          v9 = UFG::PropertySetManager::CreateOrFindPropertySet(v8);
          v10 = v9;
          if ( v9 )
          {
            v11 = (UFG::TrueCrowdSet *)UFG::TrueCrowdDataBase::QueryDataBase(
                                         UFG::TrueCrowdDataBase::sTrueCrowdDataBase,
                                         v9,
                                         0i64);
            if ( UFG::ResourcePool::CanSpawnAmbient(&v1->mPool, v11, 1) )
            {
              v12 = (UFG::TrueCrowdSet *)UFG::TrueCrowdDataBase::QueryDataBase(
                                           UFG::TrueCrowdDataBase::sTrueCrowdDataBase,
                                           v10,
                                           0i64);
              if ( UFG::ResourcePool::CanSpawnAmbient(&v1->mPool, v12, 1) )
              {
                v13 = v2->size;
                v14 = v2->capacity;
                v15 = v13 + 1;
                if ( (signed int)v13 + 1 > v14 )
                {
                  if ( v14 )
                    v16 = 2 * v14;
                  else
                    v16 = 1;
                  for ( ; v16 < v15; v16 *= 2 )
                    ;
                  if ( v16 <= 2 )
                    v16 = 2;
                  if ( v16 - v15 > 0x10000 )
                    v16 = v13 + 65537;
                  UFG::qArray<UFG::CompositeDrawableComponent *,32>::Reallocate(v2, v16, "qArray.Add");
                }
                v17 = v2->p;
                v2->size = v15;
                v17[v13] = (UFG::qReflectInventoryBase *)v10;
              }
            }
          }
          ++v3;
        }
        while ( v3 < v7 );
      }
    }
  }
}

// File Line: 930
// RVA: 0x43D150
UFG::qPropertySet *__fastcall UFG::ObjectResourceManager::GetAvailableDriver(UFG::ObjectResourceManager *this, UFG::qPropertyList *classPriorities, UFG::qPropertyList *classExclusions)
{
  unsigned int v3; // ebx
  UFG::qPropertyList *v4; // r12
  UFG::qPropertyList *v5; // rax
  UFG::ObjectResourceManager *v6; // r13
  unsigned int v7; // er15
  unsigned int v8; // edi
  UFG::TrueCrowdDataBase *v9; // rbp
  signed __int64 v10; // r14
  UFG::qPropertySet *v11; // rax
  char *v12; // rax
  UFG::qPropertyList *v13; // rsi
  __int64 v14; // rcx
  UFG::qPropertyList *v15; // r11
  __int64 v16; // rcx
  UFG::qPropertyList *textureSetList; // r10
  __int64 v18; // rcx
  UFG::qPropertyList *overrides; // r9
  unsigned int v20; // ecx
  int v21; // er8
  unsigned int v22; // edx
  UFG::TrueCrowdDefinition::Entity *v23; // rax
  UFG::TrueCrowdSet *v24; // rax
  __int64 v25; // rcx
  unsigned int v26; // edi
  UFG::qPropertySet **v27; // r14
  __int64 v28; // rbp
  UFG::qPropertySet *v29; // rsi
  __int64 v30; // rax
  unsigned int v32; // edi
  UFG::qPropertySet **v33; // rsi
  __int64 v34; // r14
  UFG::qPropertySet *v35; // rbp
  __int64 v36; // rax
  UFG::qPropertySet *v37; // rdi
  UFG::TrueCrowdDataBase *v38; // rsi
  UFG::qPropertySet *v39; // rax
  char *v40; // rax
  UFG::qPropertyList *v41; // r11
  __int64 v42; // rcx
  UFG::qPropertyList *v43; // r10
  __int64 v44; // rcx
  UFG::qPropertyList *v45; // r9
  __int64 v46; // rcx
  UFG::qPropertyList *v47; // r8
  unsigned int v48; // ecx
  int v49; // edx
  UFG::TrueCrowdDefinition::Entity *v50; // rax
  UFG::TrueCrowdSet *v51; // rax
  __int64 v52[128]; // [rsp+40h] [rbp-838h]
  __int64 v53[135]; // [rsp+440h] [rbp-438h]
  UFG::ObjectResourceManager *v54; // [rsp+880h] [rbp+8h]
  UFG::qPropertyList *list; // [rsp+888h] [rbp+10h]
  UFG::qPropertySet *property_set; // [rsp+898h] [rbp+20h]

  list = classPriorities;
  v54 = this;
  v3 = 0;
  v4 = classExclusions;
  v5 = classPriorities;
  v6 = this;
  v7 = 0;
  v8 = 0;
  if ( this->mAvailableDrivers.size )
  {
    do
    {
      v9 = UFG::TrueCrowdDataBase::sTrueCrowdDataBase;
      v10 = v8;
      property_set = v6->mAvailableDrivers.p[v10];
      v11 = UFG::qPropertySet::Get<UFG::qPropertySet>(
              v6->mAvailableDrivers.p[v10],
              (UFG::qSymbol *)&component_StreamedResource::sPropertyName.mUID,
              DEPTH_RECURSE);
      if ( v11 )
        v12 = UFG::qPropertySet::GetMemImagePtr(v11);
      else
        v12 = 0i64;
      v13 = (UFG::qPropertyList *)&v12[*(_QWORD *)v12];
      if ( !*(_QWORD *)v12 )
        v13 = 0i64;
      v14 = *((_QWORD *)v12 + 2);
      if ( v14 )
        v15 = (UFG::qPropertyList *)&v12[v14 + 16];
      else
        v15 = 0i64;
      v16 = *((_QWORD *)v12 + 3);
      if ( v16 )
        textureSetList = (UFG::qPropertyList *)&v12[v16 + 24];
      else
        textureSetList = 0i64;
      v18 = *((_QWORD *)v12 + 1);
      if ( v18 )
        overrides = (UFG::qPropertyList *)&v12[v18 + 8];
      else
        overrides = 0i64;
      v20 = v9->mDefinition.mEntityCount;
      v21 = *((_DWORD *)v12 + 8);
      v22 = 0;
      if ( v20 )
      {
        v23 = v9->mDefinition.mEntities;
        while ( v23->mNameUID != v21 )
        {
          ++v22;
          ++v23;
          if ( v22 >= v20 )
            goto LABEL_20;
        }
      }
      else
      {
LABEL_20:
        v22 = -1;
      }
      v24 = (UFG::TrueCrowdSet *)UFG::TrueCrowdDataBase::QueryCharacterDataBase(
                                   v9,
                                   v22,
                                   v13,
                                   v15,
                                   overrides,
                                   textureSetList,
                                   property_set);
      if ( v24 && UFG::TrueCrowdSet::IsLoaded(v24) )
      {
        v25 = v7++;
        v52[v25] = (__int64)v6->mAvailableDrivers.p[v10];
      }
      ++v8;
    }
    while ( v8 < v6->mAvailableDrivers.size );
    v5 = list;
  }
  if ( v5 )
  {
    if ( v5->mNumElements > 0 )
    {
      v26 = 0;
      if ( v7 )
      {
        v27 = (UFG::qPropertySet **)v52;
        v28 = v7;
        do
        {
          v29 = *v27;
          if ( UFG::VehicleUtility::IsDriverTypeInList(*v27, list)
            && (!v4 || !UFG::VehicleUtility::IsDriverTypeInList(v29, v4)) )
          {
            v30 = v26++;
            v53[v30] = (__int64)v29;
          }
          ++v27;
          --v28;
        }
        while ( v28 );
        v6 = v54;
        if ( v26 )
          return (UFG::qPropertySet *)v53[(signed int)UFG::qRandom(v26, &UFG::qDefaultSeed)];
      }
    }
  }
  if ( v4 )
  {
    if ( v4->mNumElements > 0 )
    {
      v32 = 0;
      if ( v7 )
      {
        v33 = (UFG::qPropertySet **)v52;
        v34 = v7;
        do
        {
          v35 = *v33;
          if ( !UFG::VehicleUtility::IsDriverTypeInList(*v33, v4) )
          {
            v36 = v32++;
            v53[v36] = (__int64)v35;
          }
          ++v33;
          --v34;
        }
        while ( v34 );
        if ( v32 )
          return (UFG::qPropertySet *)v53[(signed int)UFG::qRandom(v32, &UFG::qDefaultSeed)];
      }
    }
  }
  v37 = v6->mDefaultDriver;
  if ( v37 )
  {
    v38 = UFG::TrueCrowdDataBase::sTrueCrowdDataBase;
    v39 = UFG::qPropertySet::Get<UFG::qPropertySet>(
            v6->mDefaultDriver,
            (UFG::qSymbol *)&component_StreamedResource::sPropertyName.mUID,
            DEPTH_RECURSE);
    if ( v39 )
      v40 = UFG::qPropertySet::GetMemImagePtr(v39);
    else
      v40 = 0i64;
    v41 = (UFG::qPropertyList *)&v40[*(_QWORD *)v40];
    if ( !*(_QWORD *)v40 )
      v41 = 0i64;
    v42 = *((_QWORD *)v40 + 2);
    v43 = (UFG::qPropertyList *)(v42 ? &v40[v42 + 16] : 0i64);
    v44 = *((_QWORD *)v40 + 3);
    v45 = (UFG::qPropertyList *)(v44 ? &v40[v44 + 24] : 0i64);
    v46 = *((_QWORD *)v40 + 1);
    v47 = (UFG::qPropertyList *)(v46 ? &v40[v46 + 8] : 0i64);
    v48 = v38->mDefinition.mEntityCount;
    v49 = *((_DWORD *)v40 + 8);
    if ( v48 )
    {
      v50 = v38->mDefinition.mEntities;
      while ( v50->mNameUID != v49 )
      {
        ++v3;
        ++v50;
        if ( v3 >= v48 )
          goto LABEL_65;
      }
    }
    else
    {
LABEL_65:
      v3 = -1;
    }
    v51 = (UFG::TrueCrowdSet *)UFG::TrueCrowdDataBase::QueryCharacterDataBase(v38, v3, v41, v43, v47, v45, v37);
    if ( v51 )
    {
      if ( UFG::TrueCrowdSet::IsLoaded(v51) )
        return v6->mDefaultDriver;
    }
  }
  if ( v7 )
    return (UFG::qPropertySet *)v52[(signed int)UFG::qRandom(v7, &UFG::qDefaultSeed)];
  return 0i64;
}

// File Line: 998
// RVA: 0x446EF0
void __fastcall UFG::ObjectResourceManager::UpdateRareSpawnResourcesFromPropertySet(UFG::ObjectResourceManager *this, UFG::TrueCrowdResource::EntityType type, UFG::qPropertySet *set)
{
  __int64 v3; // rbx
  UFG::ObjectResourceManager *v4; // r15
  UFG::qPropertyList *v5; // rax
  UFG::qPropertyList *v6; // r13
  unsigned int v7; // er12
  unsigned int v8; // er14
  _DWORD *v9; // rsi
  char *v10; // rax
  UFG::qPropertySet *v11; // rdi
  UFG::qSymbol *v12; // rax
  __int64 v13; // rdx
  UFG::ObjectResourceManager::RareSpawnRecord *v14; // rcx
  UFG::allocator::free_link *v15; // rax
  UFG::ObjectResourceManager::RareSpawnRecord *v16; // rax
  UFG::ObjectResourceManager::RareSpawnRecord *v17; // rbx
  UFG::qNode<UFG::ObjectResourceManager::RareSpawnRecord,UFG::ObjectResourceManager::RareSpawnRecord> *v18; // rcx
  UFG::qNode<UFG::ObjectResourceManager::RareSpawnRecord,UFG::ObjectResourceManager::RareSpawnRecord> *v19; // rax
  signed __int64 v20; // rsi
  __int64 v21; // rbp
  unsigned int v22; // edi
  unsigned int v23; // edx
  unsigned int v24; // edx
  signed __int64 v25; // [rsp+20h] [rbp-48h]
  __int64 v26; // [rsp+88h] [rbp+20h]

  v3 = (signed int)type;
  v4 = this;
  v5 = UFG::qPropertySet::Get<UFG::qPropertyList>(set, (UFG::qSymbol *)&qSymbol_RareSpawnList.mUID, DEPTH_RECURSE);
  v6 = v5;
  if ( v5 )
  {
    v7 = v5->mNumElements;
    v8 = 0;
    if ( v7 )
    {
      v26 = v3;
      v9 = &v4->mRareSpawnList[v3].size;
      v25 = (signed __int64)&v4->mRareSpawnList[v3];
      do
      {
        v10 = UFG::qPropertyList::GetValuePtr(v6, 0x1Au, v8);
        if ( v10 && *(_QWORD *)v10 )
          v11 = (UFG::qPropertySet *)&v10[*(_QWORD *)v10];
        else
          v11 = 0i64;
        v12 = UFG::qPropertySet::Get<UFG::qSymbol>(v11, (UFG::qSymbol *)&qSymbol_PropertySet.mUID, DEPTH_RECURSE);
        v13 = 0i64;
        if ( !*v9 )
          goto LABEL_14;
        while ( 1 )
        {
          v14 = *(UFG::ObjectResourceManager::RareSpawnRecord **)(*((_QWORD *)&v4->mPool.mQueued.size + 2 * (v3 + 29))
                                                                + 8 * v13);
          if ( v14->mPropertySetName.mUID == v12->mUID )
            break;
          v13 = (unsigned int)(v13 + 1);
          if ( (unsigned int)v13 >= *v9 )
            goto LABEL_14;
        }
        if ( v14 )
        {
          UFG::ObjectResourceManager::RareSpawnRecord::Update(v14, v11);
        }
        else
        {
LABEL_14:
          if ( (UFG::qList<UFG::ObjectResourceManager::RareSpawnRecord,UFG::ObjectResourceManager::RareSpawnRecord,1,0> *)v4->mEmptyRareSpawnList.mNode.mNext == &v4->mEmptyRareSpawnList )
          {
            v15 = UFG::qMalloc(0x160ui64, UFG::gGlobalNewName, 0i64);
            if ( v15 )
            {
              UFG::ObjectResourceManager::RareSpawnRecord::RareSpawnRecord((UFG::ObjectResourceManager::RareSpawnRecord *)v15);
              v17 = v16;
            }
            else
            {
              v17 = 0i64;
            }
          }
          else
          {
            v17 = (UFG::ObjectResourceManager::RareSpawnRecord *)v4->mEmptyRareSpawnList.mNode.mNext;
            v18 = v17->mPrev;
            v19 = v17->mNext;
            v18->mNext = v19;
            v19->mPrev = v18;
            v17->mPrev = (UFG::qNode<UFG::ObjectResourceManager::RareSpawnRecord,UFG::ObjectResourceManager::RareSpawnRecord> *)&v17->mPrev;
            v17->mNext = (UFG::qNode<UFG::ObjectResourceManager::RareSpawnRecord,UFG::ObjectResourceManager::RareSpawnRecord> *)&v17->mPrev;
          }
          UFG::ObjectResourceManager::RareSpawnRecord::Init(v17, v11);
          v20 = (signed __int64)v4 + 16 * (signed int)(*v17->mInstance.mSet->mFiles[0].p)->mType.mValue;
          v21 = *(unsigned int *)(v20 + 456);
          v22 = v21 + 1;
          v23 = *(_DWORD *)(v20 + 460);
          if ( (signed int)v21 + 1 > v23 )
          {
            if ( v23 )
              v24 = 2 * v23;
            else
              v24 = 1;
            for ( ; v24 < v22; v24 *= 2 )
              ;
            if ( v24 <= 2 )
              v24 = 2;
            if ( v24 - v22 > 0x10000 )
              v24 = v21 + 65537;
            UFG::qArray<UFG::CompositeDrawableComponent *,32>::Reallocate(
              (UFG::qArray<UFG::qReflectInventoryBase *,0> *)(v20 + 456),
              v24,
              "qArray.Add");
          }
          *(_DWORD *)(v20 + 456) = v22;
          *(_QWORD *)(*(_QWORD *)(v20 + 464) + 8 * v21) = v17;
          v3 = v26;
          v9 = (_DWORD *)v25;
        }
        ++v8;
      }
      while ( v8 < v7 );
    }
  }
}

// File Line: 1032
// RVA: 0x446C90
void __fastcall UFG::ObjectResourceManager::UpdateRareRequests(UFG::ObjectResourceManager *this)
{
  UFG::ObjectResourceManager *v1; // rsi
  UFG::qSymbol **v2; // rdi
  signed __int64 v3; // r15
  __int64 v4; // rbp
  unsigned int v5; // er8
  UFG::qSymbol *v6; // r14
  __int64 v7; // rdx
  __int64 v8; // rcx
  unsigned int v9; // er9
  __int64 v10; // r10
  __int64 v11; // rdx
  unsigned int v12; // er9
  __int64 v13; // rdx
  __int64 v14; // rax
  unsigned int v15; // er8
  __int64 v16; // rbx
  __int64 v17; // rdx
  __int64 v18; // rdx
  __int64 v19; // rbx
  UFG::PreloadRequest *v20; // rax
  __int64 v21; // rbx
  unsigned int v22; // er8
  __int64 v23; // rdx
  __int64 v24; // rcx
  unsigned int v25; // er9
  __int64 v26; // r10
  __int64 v27; // rdx
  __int64 v28; // rdx
  UFG::qSymbol result; // [rsp+48h] [rbp+10h]

  v1 = this;
  v2 = &this->mEntityStates[0].mRareSpawnPropertySets.p;
  v3 = 3i64;
  do
  {
    if ( !*((_BYTE *)v2 - 43) || NISManager::GetInstance()->mState )
    {
      v21 = 0i64;
      if ( *((_DWORD *)v2 - 2) )
      {
        do
        {
          v22 = (*v2)[v21].mUID;
          if ( v22 != UFG::gNullQSymbol.mUID )
          {
            v23 = *((signed int *)v2 - 12);
            v24 = 0i64;
            v25 = v1->mRareSpawnList[v23].size;
            if ( v25 )
            {
              v26 = *((_QWORD *)&v1->mPool.mQueued.size + 2 * (v23 + 29));
              v27 = *((_QWORD *)&v1->mPool.mQueued.size + 2 * (v23 + 29));
              while ( *(_DWORD *)(*(_QWORD *)v27 + 16i64) != v22 )
              {
                v24 = (unsigned int)(v24 + 1);
                v27 += 8i64;
                if ( (unsigned int)v24 >= v25 )
                  goto LABEL_32;
              }
              v28 = *(_QWORD *)(v26 + 8 * v24);
              if ( v28 )
                UFG::ResourcePool::ReleasePreload(&v1->mPool, *(UFG::TrueCrowdSet **)(v28 + 72), 0, 0);
            }
LABEL_32:
            (*v2)[v21] = UFG::gNullQSymbol;
            *((_BYTE *)&v2[2]->mUID + v21) = 0;
          }
          v21 = (unsigned int)(v21 + 1);
        }
        while ( (unsigned int)v21 < *((_DWORD *)v2 - 2) );
      }
    }
    else
    {
      v4 = 0i64;
      if ( *((_DWORD *)v2 - 2) )
      {
        do
        {
          v5 = (*v2)[v4].mUID;
          if ( v5 == UFG::gNullQSymbol.mUID )
            goto LABEL_10;
          v7 = *((signed int *)v2 - 12);
          v8 = 0i64;
          v9 = v1->mRareSpawnList[v7].size;
          if ( !v9 )
            goto LABEL_10;
          v10 = *((_QWORD *)&v1->mPool.mQueued.size + 2 * (v7 + 29));
          v11 = *((_QWORD *)&v1->mPool.mQueued.size + 2 * (v7 + 29));
          while ( *(_DWORD *)(*(_QWORD *)v11 + 16i64) != v5 )
          {
            v8 = (unsigned int)(v8 + 1);
            v11 += 8i64;
            if ( (unsigned int)v8 >= v9 )
              goto LABEL_10;
          }
          v18 = *(_QWORD *)(v10 + 8 * v8);
          if ( v18 )
          {
            *(_QWORD *)(v18 + 48) = UFG::Metrics::msInstance.mSimTimeMSec;
            if ( *(_DWORD *)(v18 + 28) >= *(_DWORD *)(v18 + 24) )
            {
              (*v2)[v4] = UFG::gNullQSymbol;
              *((_BYTE *)&v2[2]->mUID + v4) = 0;
              UFG::ResourcePool::ReleasePreload(&v1->mPool, *(UFG::TrueCrowdSet **)(v18 + 72), 0, 0);
            }
          }
          else
          {
LABEL_10:
            v6 = &(*v2)[v4];
            v6->mUID = UFG::ObjectResourceManager::ChooseNewRareRequest(
                         v1,
                         &result,
                         (UFG::TrueCrowdResource::EntityType)*((_DWORD *)v2 - 12))->mUID;
            v12 = (*v2)[v4].mUID;
            if ( v12 != UFG::gNullQSymbol.mUID )
            {
              v13 = *((signed int *)v2 - 12);
              v14 = 0i64;
              v15 = v1->mRareSpawnList[v13].size;
              if ( v15 )
              {
                v16 = *((_QWORD *)&v1->mPool.mQueued.size + 2 * (v13 + 29));
                v17 = *((_QWORD *)&v1->mPool.mQueued.size + 2 * (v13 + 29));
                while ( *(_DWORD *)(*(_QWORD *)v17 + 16i64) != v12 )
                {
                  v14 = (unsigned int)(v14 + 1);
                  v17 += 8i64;
                  if ( (unsigned int)v14 >= v15 )
                    goto LABEL_21;
                }
                v19 = *(_QWORD *)(v16 + 8 * v14);
                if ( v19 )
                {
                  v20 = UFG::ResourcePool::RequestPreload(&v1->mPool, (UFG::TrueCrowdSet::Instance *)(v19 + 72), 0, 0);
                  UFG::ResourcePool::PreloadInstance(&v1->mPool, v20, (UFG::TrueCrowdSet::Instance *)(v19 + 72));
                }
              }
            }
          }
LABEL_21:
          v4 = (unsigned int)(v4 + 1);
        }
        while ( (unsigned int)v4 < *((_DWORD *)v2 - 2) );
      }
    }
    v2 += 9;
    --v3;
  }
  while ( v3 );
}

// File Line: 1092
// RVA: 0x43A030
UFG::qSymbol *__fastcall UFG::ObjectResourceManager::ChooseNewRareRequest(UFG::ObjectResourceManager *this, UFG::qSymbol *result, UFG::TrueCrowdResource::EntityType type)
{
  unsigned int v3; // er10
  UFG::qSymbol *v4; // rdi
  UFG::ObjectResourceManager *v5; // rsi
  unsigned int v6; // er9
  __int64 v7; // rdx
  unsigned int v8; // er8
  unsigned __int64 v9; // r14
  char *v10; // r15
  __int64 v11; // rbp
  __int64 *v12; // r11
  __int64 v13; // rbx
  __int64 v14; // rcx
  char v15; // al
  _DWORD *v16; // rdx
  __int64 v17; // r8
  bool v18; // zf
  unsigned __int64 v20; // rdx
  unsigned __int64 v21; // rax
  __int64 v22; // rax
  __int64 v23; // rbx
  UFG::ResourcePriorityBucket *v24; // rcx
  unsigned __int64 v25; // rax
  unsigned int v26; // eax
  __int64 v27[32]; // [rsp+20h] [rbp-128h]

  v3 = -1;
  if ( this->mEntityStates[0].mEntityType == type )
    v3 = 0;
  if ( this->mEntityStates[1].mEntityType == type )
    v3 = 1;
  v4 = result;
  v5 = this;
  v6 = 0;
  if ( this->mEntityStates[2].mEntityType == type )
  {
    v3 = 2;
  }
  else if ( v3 == -1 )
  {
    result->mUID = UFG::gNullQSymbol.mUID;
    return result;
  }
  v7 = (signed int)type;
  v8 = this->mRareSpawnList[type].size;
  if ( !v8 )
    goto LABEL_40;
  v9 = UFG::Metrics::msInstance.mSimTimeMSec;
  v10 = (char *)this + 72 * v3;
  v11 = *((unsigned int *)v10 + 58);
  v12 = (__int64 *)*((_QWORD *)&this->mPool.mQueued.size + 2 * (v7 + 29));
  v13 = v8;
  do
  {
    v14 = *v12;
    v15 = 0;
    if ( !(_DWORD)v11 )
      goto LABEL_41;
    v16 = (_DWORD *)*((_QWORD *)v10 + 30);
    v17 = v11;
    do
    {
      v18 = *v16 == *(_DWORD *)(v14 + 16);
      ++v16;
      if ( v18 )
        v15 = 1;
      --v17;
    }
    while ( v17 );
    if ( !v15 )
    {
LABEL_41:
      if ( v9 - *(_QWORD *)(v14 + 56) >= *(_QWORD *)(v14 + 40) )
      {
        if ( v6 )
        {
          v20 = *(_QWORD *)(v27[0] + 48);
          v21 = *(_QWORD *)(v14 + 48);
          if ( v21 >= v20 )
          {
            if ( v21 == v20 )
            {
              v22 = v6++;
              v27[v22] = v14;
            }
          }
          else
          {
            v27[0] = *v12;
            v6 = 1;
          }
        }
        else
        {
          v27[0] = *v12;
          v6 = 1;
        }
      }
    }
    ++v12;
    --v13;
  }
  while ( v13 );
  if ( v6
    && ((v23 = v27[(unsigned int)UFG::qRandom(v6, &UFG::qDefaultSeed)], qSymbol_Reserved.mUID != qSymbol_Critical.mUID) ? (qSymbol_Reserved.mUID != qSymbol_High.mUID ? (qSymbol_Reserved.mUID == qSymbol_Medium.mUID || qSymbol_Reserved.mUID == qSymbol_Low.mUID ? (v24 = v5->mPool.mLowBucket) : (v24 = v5->mPool.mReservedBucket)) : (v24 = v5->mPool.mHighBucket)) : (v24 = v5->mPool.mCriticalBucket),
        UFG::ResourcePriorityBucket::WillFitWithinSizeConstraints(v24, (UFG::TrueCrowdSet::Instance *)(v23 + 72))) )
  {
    v25 = UFG::Metrics::msInstance.mSimTimeMSec;
    *(_DWORD *)(v23 + 28) = 0;
    *(_QWORD *)(v23 + 48) = v25;
    v26 = *(_DWORD *)(v23 + 16);
  }
  else
  {
LABEL_40:
    v26 = UFG::gNullQSymbol.mUID;
  }
  v4->mUID = v26;
  return v4;
}

// File Line: 1176
// RVA: 0x446B60
void __fastcall UFG::ObjectResourceManager::UpdateRareObjectAvailability(UFG::ObjectResourceManager *this)
{
  UFG::ObjectResourceManager *v1; // rbp
  UFG::qArray<UFG::qSymbol,0> *v2; // rbx
  signed __int64 v3; // r14
  unsigned int i; // edi
  unsigned int v5; // er8
  __int64 v6; // rdx
  unsigned int v7; // eax
  unsigned int v8; // er9
  __int64 v9; // r10
  __int64 v10; // rdx
  __int64 v11; // rdx
  char v12; // cl
  UFG::TrueCrowdSet *v13; // rcx
  char v14; // al

  v1 = this;
  v2 = &this->mEntityStates[0].mRareSpawnPropertySets;
  v3 = 3i64;
  do
  {
    for ( i = 0; i < v2->size; ++i )
    {
      v5 = v2->p[i].mUID;
      if ( v5 == UFG::gNullQSymbol.mUID )
      {
        *((_BYTE *)&v2[1].p->mUID + i) = 0;
      }
      else
      {
        v6 = SLODWORD(v2[-3].p);
        v7 = 0;
        v8 = v1->mRareSpawnList[v6].size;
        if ( v8 )
        {
          v9 = *((_QWORD *)&v1->mPool.mQueued.size + 2 * (v6 + 29));
          v10 = *((_QWORD *)&v1->mPool.mQueued.size + 2 * (v6 + 29));
          while ( *(_DWORD *)(*(_QWORD *)v10 + 16i64) != v5 )
          {
            ++v7;
            v10 += 8i64;
            if ( v7 >= v8 )
              goto LABEL_9;
          }
          v11 = *(_QWORD *)(v9 + 8i64 * v7);
        }
        else
        {
LABEL_9:
          v11 = 0i64;
        }
        if ( *(_DWORD *)(v11 + 28) < *(_DWORD *)(v11 + 24) )
        {
          if ( UFG::Metrics::msInstance.mSimTimeMSec - *(_QWORD *)(v11 + 56) >= *(_QWORD *)(v11 + 40) )
          {
            v13 = *(UFG::TrueCrowdSet **)(v11 + 72);
            if ( (signed int)v13->mCurrentInstances < *(_DWORD *)(v11 + 20) )
            {
              v14 = UFG::TrueCrowdSet::IsLoaded(v13);
              v12 = 1;
              if ( !v14 )
                v12 = 0;
            }
            else
            {
              v12 = 0;
            }
          }
          else
          {
            v12 = 0;
          }
        }
        else
        {
          v12 = 0;
        }
        *((_BYTE *)&v2[1].p->mUID + i) = v12;
      }
    }
    v2 = (UFG::qArray<UFG::qSymbol,0> *)((char *)v2 + 72);
    --v3;
  }
  while ( v3 );
}

// File Line: 1214
// RVA: 0x442CB0
void __fastcall UFG::ObjectResourceManager::ResetAllRarePreloadStatuses(UFG::ObjectResourceManager *this, UFG::TrueCrowdResource::EntityType type)
{
  __int64 v2; // r9
  UFG::ObjectResourceManager *v3; // rbx
  unsigned int v4; // ecx
  UFG::qArray<UFG::PreloadRequest *,0> *v5; // rax
  unsigned int v6; // er8
  UFG::PreloadRequest **v7; // rax

  v2 = 0i64;
  v3 = this;
  if ( this->mRareSpawnList[type].size )
  {
    do
    {
      v4 = 0;
      v5 = v3->mPool.mPreloadBuckets;
      v6 = v5->size;
      if ( v5->size )
      {
        v7 = v5->p;
        while ( (*v7)->mInstance.mSet != *(UFG::TrueCrowdSet **)(*(_QWORD *)(*((_QWORD *)&v3->mPool.mQueued.size
                                                                             + 2 * ((signed int)type + 29i64))
                                                                           + 8 * v2)
                                                               + 72i64) )
        {
          ++v4;
          ++v7;
          if ( v4 >= v6 )
            goto LABEL_8;
        }
        (*v7)->mSpawnSetValid = 0;
      }
LABEL_8:
      v2 = (unsigned int)(v2 + 1);
    }
    while ( (unsigned int)v2 < v3->mRareSpawnList[type].size );
  }
}

// File Line: 1240
// RVA: 0x441FD0
void __fastcall UFG::ObjectResourceManager::RemoveAllUnwantedRareRequests(UFG::ObjectResourceManager *this, UFG::TrueCrowdResource::EntityType type, bool forceUnload)
{
  bool v3; // r15
  UFG::ObjectResourceManager *v4; // r14
  UFG::qArray<UFG::ObjectResourceManager::RareSpawnRecord *,0> *v5; // rbx
  __int64 v6; // rsi
  unsigned int v7; // ebp
  signed __int64 v8; // r12
  unsigned int v9; // ecx
  __int64 v10; // rdi
  UFG::qArray<UFG::PreloadRequest *,0> *v11; // rax
  unsigned int v12; // er8
  UFG::PreloadRequest **v13; // rax
  UFG::PreloadRequest *v14; // rdx
  unsigned int v15; // er8
  UFG::qNode<UFG::ObjectResourceManager::RareSpawnRecord,UFG::ObjectResourceManager::RareSpawnRecord> *v16; // rax
  signed __int64 v17; // rax

  v3 = forceUnload;
  v4 = this;
  v5 = &this->mRareSpawnList[type];
  v6 = v5->size - 1;
  if ( (signed int)(v5->size - 1) >= 0 )
  {
    v7 = v5->size;
    v8 = 2 * ((signed int)type + 29i64);
    do
    {
      v9 = 0;
      v10 = *(_QWORD *)(*((_QWORD *)&v4->mPool.mQueued.size + v8) + 8 * v6);
      v11 = v4->mPool.mPreloadBuckets;
      v12 = v11->size;
      if ( v11->size )
      {
        v13 = v11->p;
        while ( 1 )
        {
          v14 = *v13;
          if ( (*v13)->mInstance.mSet == *(UFG::TrueCrowdSet **)(v10 + 72) )
            break;
          ++v9;
          ++v13;
          if ( v9 >= v12 )
            goto LABEL_17;
        }
        if ( !v14->mSpawnSetValid && v14->mDirectRequestCount <= 0 || v3 )
        {
          UFG::ResourcePool::ReleasePreload(&v4->mPool, *(UFG::TrueCrowdSet **)(v10 + 72), 0, 0);
          v15 = v7;
          v16 = v4->mEmptyRareSpawnList.mNode.mPrev;
          v16->mNext = (UFG::qNode<UFG::ObjectResourceManager::RareSpawnRecord,UFG::ObjectResourceManager::RareSpawnRecord> *)v10;
          *(_QWORD *)v10 = v16;
          *(_QWORD *)(v10 + 8) = (char *)v4 + 504;
          v4->mEmptyRareSpawnList.mNode.mPrev = (UFG::qNode<UFG::ObjectResourceManager::RareSpawnRecord,UFG::ObjectResourceManager::RareSpawnRecord> *)v10;
          if ( v7 != v5->size )
          {
            v17 = 8 * v6 + 8;
            do
            {
              ++v15;
              v17 += 8i64;
              *(UFG::ObjectResourceManager::RareSpawnRecord **)((char *)v5->p + v17 - 16) = *(UFG::ObjectResourceManager::RareSpawnRecord **)((char *)v5->p + v17 - 8);
            }
            while ( v15 != v5->size );
          }
          if ( v5->size > 1 )
            --v5->size;
          else
            v5->size = 0;
        }
      }
LABEL_17:
      --v7;
      --v6;
    }
    while ( v6 >= 0 );
  }
}

