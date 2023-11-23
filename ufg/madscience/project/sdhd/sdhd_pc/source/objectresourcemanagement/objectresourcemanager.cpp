// File Line: 51
// RVA: 0x43DEA0
UFG::qSymbol *__fastcall UFG::EntityTypeState::GetSpawnableRareEntity(UFG::EntityTypeState *this)
{
  unsigned int size; // r8d
  __int64 v2; // rax

  size = this->mRareSpawnIsReady.size;
  v2 = 0i64;
  if ( !size )
    return &UFG::gNullQSymbol;
  while ( !this->mRareSpawnIsReady.p[v2] )
  {
    v2 = (unsigned int)(v2 + 1);
    if ( (unsigned int)v2 >= size )
      return &UFG::gNullQSymbol;
  }
  return &this->mRareSpawnPropertySets.p[(unsigned int)v2];
}

// File Line: 63
// RVA: 0x441240
void __fastcall UFG::EntityTypeState::RareEntitySpawned(UFG::EntityTypeState *this, UFG::qSymbol *spawnedEntity)
{
  __int64 i; // r9
  __int64 mEntityType; // rdx
  __int64 v5; // rax
  unsigned int size; // r8d
  UFG::ObjectResourceManager::RareSpawnRecord **p; // rbx
  UFG::ObjectResourceManager::RareSpawnRecord **v8; // rdx
  UFG::ObjectResourceManager::RareSpawnRecord *v9; // rdx
  unsigned __int64 mSimTimeMSec; // rax

  for ( i = 0i64; (unsigned int)i < this->mRareSpawnPropertySets.size; i = (unsigned int)(i + 1) )
  {
    if ( this->mRareSpawnPropertySets.p[i].mUID == spawnedEntity->mUID )
    {
      this->mRareSpawnIsReady.p[i] = 0;
      mEntityType = this->mEntityType;
      v5 = 0i64;
      size = UFG::ObjectResourceManager::sInstance->mRareSpawnList[mEntityType].size;
      if ( size )
      {
        p = UFG::ObjectResourceManager::sInstance->mRareSpawnList[mEntityType].p;
        v8 = p;
        while ( (*v8)->mPropertySetName.mUID != this->mRareSpawnPropertySets.p[i].mUID )
        {
          v5 = (unsigned int)(v5 + 1);
          ++v8;
          if ( (unsigned int)v5 >= size )
            goto LABEL_7;
        }
        v9 = p[v5];
      }
      else
      {
LABEL_7:
        v9 = 0i64;
      }
      mSimTimeMSec = UFG::Metrics::msInstance.mSimTimeMSec;
      ++v9->mTotalNumInstancesSpawned;
      v9->mLastTimeAssetSpawned = mSimTimeMSec;
    }
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
void __fastcall UFG::ObjectResourceManager::RareSpawnRecord::RareSpawnRecord(
        UFG::ObjectResourceManager::RareSpawnRecord *this)
{
  int v1; // edx
  UFG::qColour **p_mColourTint; // rax

  this->mPrev = this;
  this->mNext = this;
  *(_QWORD *)&this->mPropertySetName.mUID = -1i64;
  this->mMaxSpawnsBeforeCycles = -1;
  this->mTotalNumInstancesSpawned = 0;
  this->mWeight = -1;
  this->mMinTimeBetweenSpawns = 0i64;
  this->mLastTimeAssetLoaded = 0i64;
  this->mLastTimeAssetSpawned = 0i64;
  this->mRequestTime = 0i64;
  v1 = 15;
  p_mColourTint = &this->mInstance.mPart[0].mColourTint;
  do
  {
    *(p_mColourTint - 1) = 0i64;
    *p_mColourTint = 0i64;
    p_mColourTint += 2;
    --v1;
  }
  while ( v1 >= 0 );
  this->mInstance.mSet = 0i64;
  this->mInstance.mNumParts = 0;
}

// File Line: 121
// RVA: 0x43E170
void __fastcall UFG::ObjectResourceManager::RareSpawnRecord::Init(
        UFG::ObjectResourceManager::RareSpawnRecord *this,
        UFG::qPropertySet *propertySet)
{
  UFG::qSymbol *v4; // rax
  UFG::qSymbol *p_mPropertySetName; // rcx
  unsigned int mUID; // eax
  UFG::qPropertySet *v7; // rax
  int *v8; // rax
  int *v9; // rax
  int *v10; // rax
  float *v11; // rax
  unsigned __int64 v12; // rcx
  float v13; // xmm0_4

  v4 = UFG::qPropertySet::Get<UFG::qSymbol>(
         propertySet,
         (UFG::qArray<unsigned long,0> *)&qSymbol_PropertySet,
         DEPTH_RECURSE);
  p_mPropertySetName = &this->mPropertySetName;
  mUID = v4->mUID;
  if ( this->mPropertySetName.mUID != mUID )
  {
    p_mPropertySetName->mUID = mUID;
    v7 = UFG::PropertySetManager::FindPropertySet(p_mPropertySetName);
    UFG::TrueCrowdDataBase::QueryInstance(UFG::TrueCrowdDataBase::sTrueCrowdDataBase, v7, &this->mInstance);
  }
  this->mMaxConcurrentInstances = 1000;
  v8 = UFG::qPropertySet::Get<long>(propertySet, (UFG::qArray<unsigned long,0> *)&qSymbol_MaxInstances, DEPTH_RECURSE);
  if ( v8 )
    this->mMaxConcurrentInstances = *v8;
  this->mMaxSpawnsBeforeCycles = 10000;
  v9 = UFG::qPropertySet::Get<long>(
         propertySet,
         (UFG::qArray<unsigned long,0> *)&qSymbol_MaxSpawnsBeforeCycle,
         DEPTH_RECURSE);
  if ( v9 )
    this->mMaxSpawnsBeforeCycles = *v9;
  this->mWeight = 0;
  v10 = UFG::qPropertySet::Get<long>(propertySet, (UFG::qArray<unsigned long,0> *)&qSymbol_Weight, DEPTH_RECURSE);
  if ( v10 )
    this->mWeight = *v10;
  this->mMinTimeBetweenSpawns = 0i64;
  v11 = UFG::qPropertySet::Get<float>(
          propertySet,
          (UFG::qArray<unsigned long,0> *)&qSymbol_MinTimeBetweenSpawns,
          DEPTH_RECURSE);
  if ( v11 )
  {
    v12 = 0i64;
    v13 = *v11 * 1000.0;
    if ( v13 >= 9.223372e18 )
    {
      v13 = v13 - 9.223372e18;
      if ( v13 < 9.223372e18 )
        v12 = 0x8000000000000000ui64;
    }
    this->mMinTimeBetweenSpawns = v12 + (unsigned int)(int)v13;
  }
  this->mTotalNumInstancesSpawned = 0;
  this->mLastTimeAssetLoaded = UFG::Metrics::msInstance.mSimTimeMSec;
  this->mRequestTime = UFG::Metrics::msInstance.mSimTimeMSec;
  this->mLastTimeAssetSpawned = UFG::Metrics::msInstance.mSimTimeMSec - this->mMinTimeBetweenSpawns;
}

// File Line: 166
// RVA: 0x444C00
void __fastcall UFG::ObjectResourceManager::RareSpawnRecord::Update(
        UFG::ObjectResourceManager::RareSpawnRecord *this,
        UFG::qPropertySet *propertySet)
{
  int *v4; // rax
  int v5; // eax
  int mMaxConcurrentInstances; // r8d
  int *v7; // rax
  int v8; // eax
  int mMaxSpawnsBeforeCycles; // ecx
  int *v10; // rax
  int v11; // eax
  int mWeight; // ecx
  float *v13; // rax
  float v14; // xmm0_4
  unsigned __int64 v15; // rax
  float v16; // xmm0_4
  unsigned __int64 v17; // rcx
  unsigned __int64 mMinTimeBetweenSpawns; // rax

  v4 = UFG::qPropertySet::Get<long>(propertySet, (UFG::qArray<unsigned long,0> *)&qSymbol_MaxInstances, DEPTH_RECURSE);
  if ( v4 )
  {
    v5 = *v4;
    mMaxConcurrentInstances = this->mMaxConcurrentInstances;
    if ( v5 > mMaxConcurrentInstances )
      mMaxConcurrentInstances = v5;
    this->mMaxConcurrentInstances = mMaxConcurrentInstances;
  }
  v7 = UFG::qPropertySet::Get<long>(
         propertySet,
         (UFG::qArray<unsigned long,0> *)&qSymbol_MaxSpawnsBeforeCycle,
         DEPTH_RECURSE);
  if ( v7 )
  {
    v8 = *v7;
    mMaxSpawnsBeforeCycles = this->mMaxSpawnsBeforeCycles;
    if ( v8 > mMaxSpawnsBeforeCycles )
      mMaxSpawnsBeforeCycles = v8;
    this->mMaxSpawnsBeforeCycles = mMaxSpawnsBeforeCycles;
  }
  v10 = UFG::qPropertySet::Get<long>(propertySet, (UFG::qArray<unsigned long,0> *)&qSymbol_Weight, DEPTH_RECURSE);
  if ( v10 )
  {
    v11 = *v10;
    mWeight = this->mWeight;
    if ( v11 > mWeight )
      mWeight = v11;
    this->mWeight = mWeight;
  }
  v13 = UFG::qPropertySet::Get<float>(
          propertySet,
          (UFG::qArray<unsigned long,0> *)&qSymbol_MinTimeBetweenSpawns,
          DEPTH_RECURSE);
  if ( v13 )
  {
    v14 = *v13;
    v15 = 0i64;
    v16 = v14 * 1000.0;
    if ( v16 >= 9.223372e18 )
    {
      v16 = v16 - 9.223372e18;
      if ( v16 < 9.223372e18 )
        v15 = 0x8000000000000000ui64;
    }
    v17 = v15 + (unsigned int)(int)v16;
    mMinTimeBetweenSpawns = this->mMinTimeBetweenSpawns;
    if ( v17 > mMinTimeBetweenSpawns )
      mMinTimeBetweenSpawns = v17;
    this->mMinTimeBetweenSpawns = mMinTimeBetweenSpawns;
  }
}

// File Line: 214
// RVA: 0x436800
void __fastcall UFG::ObjectResourceManager::ObjectResourceManager(UFG::ObjectResourceManager *this)
{
  UFG::qArray<UFG::ObjectResourceManager::RareSpawnRecord *,0> *mRareSpawnList; // rdi
  UFG::qList<UFG::ObjectResourceManager::RareSpawnRecord,UFG::ObjectResourceManager::RareSpawnRecord,1,0> *p_mEmptyRareSpawnList; // rsi
  unsigned __int64 v4; // rax
  UFG::allocator::free_link *v5; // rax
  UFG::qPropertySet **v6; // rbp
  unsigned int i; // r9d
  unsigned __int64 v8; // rax
  UFG::allocator::free_link *v9; // rax
  UFG::qPropertySet **v10; // rbp
  unsigned int j; // r9d
  unsigned __int64 v12; // rax
  UFG::allocator::free_link *v13; // rax
  UFG::ObjectResourceManager::RareSpawnRecord **v14; // rbp
  unsigned int k; // r9d
  unsigned __int64 v16; // rax
  UFG::allocator::free_link *v17; // rax
  UFG::ObjectResourceManager::RareSpawnRecord **v18; // rdi
  unsigned int m; // r9d
  unsigned __int64 v20; // rax
  UFG::allocator::free_link *v21; // rax
  UFG::ObjectResourceManager::RareSpawnRecord **v22; // rdi
  unsigned int n; // r9d
  __int64 v24; // rdi
  UFG::allocator::free_link *v25; // rax
  int v26; // edx
  UFG::allocator::free_link *v27; // rcx
  UFG::allocator::free_link *mPrev; // rcx

  UFG::ResourcePool::ResourcePool(&this->mPool);
  `eh vector constructor iterator(
    this->mEntityStates,
    0x48ui64,
    3,
    (void (__fastcall *)(void *))UFG::EntityTypeState::EntityTypeState);
  this->mCurrentSpawnset = UFG::gNullQSymbol;
  this->mAmbientVehicles.p = 0i64;
  *(_QWORD *)&this->mAmbientVehicles.size = 0i64;
  this->mAvailableDrivers.p = 0i64;
  *(_QWORD *)&this->mAvailableDrivers.size = 0i64;
  this->mDefaultDriver = 0i64;
  mRareSpawnList = this->mRareSpawnList;
  `eh vector constructor iterator(
    this->mRareSpawnList,
    0x10ui64,
    3,
    (void (__fastcall *)(void *))UFG::qArray<UFG::qSymbolUC,0>::qArray<UFG::qSymbolUC,0>);
  p_mEmptyRareSpawnList = &this->mEmptyRareSpawnList;
  this->mEmptyRareSpawnList.mNode.mPrev = &this->mEmptyRareSpawnList.mNode;
  this->mEmptyRareSpawnList.mNode.mNext = &this->mEmptyRareSpawnList.mNode;
  UFG::ObjectResourceManager::InitDescriptors(this);
  UFG::ObjectResourceManager::InitPools(this);
  if ( this->mAmbientVehicles.capacity < 0x20 && this->mAmbientVehicles.size != 32 )
  {
    v4 = 256i64;
    if ( !is_mul_ok(0x20ui64, 8ui64) )
      v4 = -1i64;
    v5 = UFG::qMalloc(v4, "qArray.Reserve.AmbientVehicleList", 0i64);
    v6 = (UFG::qPropertySet **)v5;
    if ( this->mAmbientVehicles.p )
    {
      for ( i = 0; i < this->mAmbientVehicles.size; ++i )
        v5[i] = (UFG::allocator::free_link)this->mAmbientVehicles.p[i];
      operator delete[](this->mAmbientVehicles.p);
    }
    this->mAmbientVehicles.p = v6;
    this->mAmbientVehicles.capacity = 32;
  }
  if ( this->mAvailableDrivers.capacity < 0x20 && this->mAvailableDrivers.size != 32 )
  {
    v8 = 256i64;
    if ( !is_mul_ok(0x20ui64, 8ui64) )
      v8 = -1i64;
    v9 = UFG::qMalloc(v8, "qArray.Reserve.mAvailableDrivers", 0i64);
    v10 = (UFG::qPropertySet **)v9;
    if ( this->mAvailableDrivers.p )
    {
      for ( j = 0; j < this->mAvailableDrivers.size; ++j )
        v9[j] = (UFG::allocator::free_link)this->mAvailableDrivers.p[j];
      operator delete[](this->mAvailableDrivers.p);
    }
    this->mAvailableDrivers.p = v10;
    this->mAvailableDrivers.capacity = 32;
  }
  if ( this->mRareSpawnList[0].capacity < 8 && mRareSpawnList->size != 8 )
  {
    v12 = 64i64;
    if ( !is_mul_ok(8ui64, 8ui64) )
      v12 = -1i64;
    v13 = UFG::qMalloc(v12, "mRareSpawnList", 0i64);
    v14 = (UFG::ObjectResourceManager::RareSpawnRecord **)v13;
    if ( this->mRareSpawnList[0].p )
    {
      for ( k = 0; k < mRareSpawnList->size; ++k )
        v13[k] = (UFG::allocator::free_link)this->mRareSpawnList[0].p[k];
      operator delete[](this->mRareSpawnList[0].p);
    }
    this->mRareSpawnList[0].p = v14;
    this->mRareSpawnList[0].capacity = 8;
  }
  if ( this->mRareSpawnList[1].capacity < 8 && this->mRareSpawnList[1].size != 8 )
  {
    v16 = 64i64;
    if ( !is_mul_ok(8ui64, 8ui64) )
      v16 = -1i64;
    v17 = UFG::qMalloc(v16, "mRareSpawnList", 0i64);
    v18 = (UFG::ObjectResourceManager::RareSpawnRecord **)v17;
    if ( this->mRareSpawnList[1].p )
    {
      for ( m = 0; m < this->mRareSpawnList[1].size; ++m )
        v17[m] = (UFG::allocator::free_link)this->mRareSpawnList[1].p[m];
      operator delete[](this->mRareSpawnList[1].p);
    }
    this->mRareSpawnList[1].p = v18;
    this->mRareSpawnList[1].capacity = 8;
  }
  if ( this->mRareSpawnList[2].capacity < 8 && this->mRareSpawnList[2].size != 8 )
  {
    v20 = 64i64;
    if ( !is_mul_ok(8ui64, 8ui64) )
      v20 = -1i64;
    v21 = UFG::qMalloc(v20, "mRareSpawnList", 0i64);
    v22 = (UFG::ObjectResourceManager::RareSpawnRecord **)v21;
    if ( this->mRareSpawnList[2].p )
    {
      for ( n = 0; n < this->mRareSpawnList[2].size; ++n )
        v21[n] = (UFG::allocator::free_link)this->mRareSpawnList[2].p[n];
      operator delete[](this->mRareSpawnList[2].p);
    }
    this->mRareSpawnList[2].p = v22;
    this->mRareSpawnList[2].capacity = 8;
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
    mPrev = (UFG::allocator::free_link *)p_mEmptyRareSpawnList->mNode.mPrev;
    mPrev[1].mNext = v25;
    v25->mNext = mPrev;
    v25[1].mNext = (UFG::allocator::free_link *)p_mEmptyRareSpawnList;
    p_mEmptyRareSpawnList->mNode.mPrev = (UFG::qNode<UFG::ObjectResourceManager::RareSpawnRecord,UFG::ObjectResourceManager::RareSpawnRecord> *)v25;
    --v24;
  }
  while ( v24 );
}

// File Line: 233
// RVA: 0x437C20
void __fastcall UFG::ObjectResourceManager::~ObjectResourceManager(UFG::ObjectResourceManager *this)
{
  UFG::qList<UFG::ObjectResourceManager::RareSpawnRecord,UFG::ObjectResourceManager::RareSpawnRecord,1,0> *p_mEmptyRareSpawnList; // rbx
  UFG::qNode<UFG::ObjectResourceManager::RareSpawnRecord,UFG::ObjectResourceManager::RareSpawnRecord> *mPrev; // rcx
  UFG::qNode<UFG::ObjectResourceManager::RareSpawnRecord,UFG::ObjectResourceManager::RareSpawnRecord> *mNext; // rax
  UFG::qPropertySet **p; // rcx
  UFG::qPropertySet **v6; // rcx

  p_mEmptyRareSpawnList = &this->mEmptyRareSpawnList;
  UFG::qList<UFG::FractureConnectivity::Connection,UFG::FractureConnectivity::Connection,1,0>::DeleteNodes((UFG::qList<UFG::qReflectField,UFG::qReflectField,1,0> *)&this->mEmptyRareSpawnList);
  mPrev = p_mEmptyRareSpawnList->mNode.mPrev;
  mNext = p_mEmptyRareSpawnList->mNode.mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  p_mEmptyRareSpawnList->mNode.mPrev = &p_mEmptyRareSpawnList->mNode;
  p_mEmptyRareSpawnList->mNode.mNext = &p_mEmptyRareSpawnList->mNode;
  `eh vector destructor iterator(
    this->mRareSpawnList,
    0x10ui64,
    3,
    (void (__fastcall *)(void *))UFG::qArray<UFG::PartRequest *,0>::~qArray<UFG::PartRequest *,0>);
  p = this->mAvailableDrivers.p;
  if ( p )
    operator delete[](p);
  this->mAvailableDrivers.p = 0i64;
  *(_QWORD *)&this->mAvailableDrivers.size = 0i64;
  v6 = this->mAmbientVehicles.p;
  if ( v6 )
    operator delete[](v6);
  this->mAmbientVehicles.p = 0i64;
  *(_QWORD *)&this->mAmbientVehicles.size = 0i64;
  `eh vector destructor iterator(
    this->mEntityStates,
    0x48ui64,
    3,
    (void (__fastcall *)(void *))UFG::EntityTypeState::~EntityTypeState);
  UFG::ResourcePool::~ResourcePool(&this->mPool);
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
  UFG::qPropertySet *PropertySet; // rax
  UFG::ObjectResourceManager *v5; // rdi
  int v6; // edx
  UFG::qColour **p_mColourTint; // rcx
  UFG::PreloadRequest *v8; // rax
  UFG::TrueCrowdSet::Instance instance; // [rsp+30h] [rbp-128h] BYREF
  UFG::allocator::free_link *result; // [rsp+160h] [rbp+8h] BYREF

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
    PropertySet = UFG::PropertySetManager::GetPropertySet(v3);
    if ( PropertySet )
    {
      v5 = UFG::ObjectResourceManager::sInstance;
      v6 = 15;
      p_mColourTint = &instance.mPart[0].mColourTint;
      do
      {
        *(p_mColourTint - 1) = 0i64;
        *p_mColourTint = 0i64;
        p_mColourTint += 2;
        --v6;
      }
      while ( v6 >= 0 );
      instance.mSet = 0i64;
      instance.mNumParts = 0;
      UFG::TrueCrowdDataBase::QueryInstance(UFG::TrueCrowdDataBase::sTrueCrowdDataBase, PropertySet, &instance);
      v8 = UFG::ResourcePool::RequestPreload(&v5->mPool, &instance, 1u, 1);
      UFG::ResourcePool::PreloadInstance(&v5->mPool, v8, &instance);
    }
    ++v2;
  }
  while ( (__int64)v2 < (__int64)&sDrawX );
}

// File Line: 260
// RVA: 0x441190
void UFG::ObjectResourceManager::Quit(void)
{
  const char **v0; // rbx
  UFG::qSymbol *v1; // rax
  UFG::qPropertySet *PropertySet; // rax
  UFG::ObjectResourceManager *v3; // rdi
  UFG::TrueCrowdSet *DataBase; // rax
  UFG::ObjectResourceManager *v5; // rbx
  UFG::qSymbol result; // [rsp+30h] [rbp+8h] BYREF

  v0 = UFG::TodoMoveToXmlPreloadCriticalResources;
  do
  {
    v1 = UFG::qSymbol::create_from_string(&result, *v0);
    PropertySet = UFG::PropertySetManager::GetPropertySet(v1);
    if ( PropertySet )
    {
      v3 = UFG::ObjectResourceManager::sInstance;
      DataBase = (UFG::TrueCrowdSet *)UFG::TrueCrowdDataBase::QueryDataBase(
                                        UFG::TrueCrowdDataBase::sTrueCrowdDataBase,
                                        PropertySet,
                                        0i64);
      UFG::ResourcePool::ReleasePreload(&v3->mPool, DataBase, 1u, 1);
    }
    ++v0;
  }
  while ( (__int64)v0 < (__int64)&sDrawX );
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
  UFG::qArray<UFG::qSymbol,0> *p_mRareSpawnPropertySets; // r12
  UFG::allocator::free_link *v3; // rax
  bool *v4; // rdi
  unsigned int i; // r9d
  __int64 v6; // r8
  __int64 v7; // r13
  unsigned int v8; // r14d
  __int64 size; // rsi
  unsigned int capacity; // edx
  unsigned int v11; // edi
  unsigned int v12; // edx
  UFG::qSymbol *p; // rcx
  __int64 v14; // r15
  unsigned int v15; // edi
  unsigned int v16; // esi
  unsigned int v17; // edi
  UFG::allocator::free_link *v18; // rax
  bool *v19; // rbp
  __int64 j; // r9
  bool *v21; // rax
  UFG::qArray<UFG::qSymbol,0> *v22; // rsi
  UFG::allocator::free_link *v23; // rax
  bool *v24; // rdi
  unsigned int k; // r9d
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
  __int64 m; // r9
  bool *v38; // rax

  p_mRareSpawnPropertySets = &this->mEntityStates[0].mRareSpawnPropertySets;
  *(_WORD *)&this->mEntityStates[0].mUpdateRequired = 256;
  this->mEntityStates[0].mHasMinimumAmbienceRequirement = 1;
  *(_QWORD *)&this->mEntityStates[0].mAmbientModelRatioTarget = 1050253722i64;
  this->mEntityStates[0].mResourceUpdateCallback = UFG::EntityTypeState::UpdateCharacterPreloads;
  this->mEntityStates[0].mEntityType = Character;
  *(_QWORD *)&this->mEntityStates[0].mAmbientTextureRatio = 0i64;
  this->mEntityStates[0].mAmbientTextureRatioTarget = 0.64999998;
  this->mEntityStates[0].mAvailableAmbientTextureMemory = 0;
  if ( this->mEntityStates[0].mRareSpawnPropertySets.capacity < 2 )
    UFG::qArray<UFG::qSymbol,0>::Reallocate(&this->mEntityStates[0].mRareSpawnPropertySets, 2u, "ObjectResourceManager");
  if ( this->mEntityStates[0].mRareSpawnIsReady.capacity < 2 && this->mEntityStates[0].mRareSpawnIsReady.size != 2 )
  {
    v3 = UFG::qMalloc(2ui64, "ObjectResourceManager", 0i64);
    v4 = (bool *)v3;
    if ( this->mEntityStates[0].mRareSpawnIsReady.p )
    {
      for ( i = 0;
            i < this->mEntityStates[0].mRareSpawnIsReady.size;
            *((_BYTE *)&v3->mNext + v6) = this->mEntityStates[0].mRareSpawnIsReady.p[v6] )
      {
        v6 = i++;
      }
      operator delete[](this->mEntityStates[0].mRareSpawnIsReady.p);
    }
    this->mEntityStates[0].mRareSpawnIsReady.p = v4;
    this->mEntityStates[0].mRareSpawnIsReady.capacity = 2;
  }
  v7 = 2i64;
  v8 = 1;
  do
  {
    size = p_mRareSpawnPropertySets->size;
    capacity = p_mRareSpawnPropertySets->capacity;
    v11 = size + 1;
    if ( (int)size + 1 > capacity )
    {
      if ( capacity )
        v12 = 2 * capacity;
      else
        v12 = 1;
      for ( ; v12 < v11; v12 *= 2 )
        ;
      if ( v12 <= 4 )
        v12 = 4;
      if ( v12 - v11 > 0x10000 )
        v12 = size + 65537;
      UFG::qArray<UFG::qSymbol,0>::Reallocate(p_mRareSpawnPropertySets, v12, "qArray.Add");
    }
    p = p_mRareSpawnPropertySets->p;
    p_mRareSpawnPropertySets->size = v11;
    p[size] = UFG::gNullQSymbol;
    v14 = this->mEntityStates[0].mRareSpawnIsReady.size;
    v15 = this->mEntityStates[0].mRareSpawnIsReady.capacity;
    v16 = v14 + 1;
    if ( (int)v14 + 1 > v15 )
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
        if ( this->mEntityStates[0].mRareSpawnIsReady.p )
        {
          for ( j = 0i64; (unsigned int)j < this->mEntityStates[0].mRareSpawnIsReady.size; j = (unsigned int)(j + 1) )
            *((_BYTE *)&v18->mNext + j) = this->mEntityStates[0].mRareSpawnIsReady.p[j];
          operator delete[](this->mEntityStates[0].mRareSpawnIsReady.p);
        }
        this->mEntityStates[0].mRareSpawnIsReady.p = v19;
        this->mEntityStates[0].mRareSpawnIsReady.capacity = v17;
      }
    }
    v21 = this->mEntityStates[0].mRareSpawnIsReady.p;
    this->mEntityStates[0].mRareSpawnIsReady.size = v16;
    v21[v14] = 0;
    --v7;
  }
  while ( v7 );
  v22 = &this->mEntityStates[1].mRareSpawnPropertySets;
  this->mEntityStates[1].mEntityType = Vehicle;
  *(_WORD *)&this->mEntityStates[1].mUpdateRequired = 256;
  this->mEntityStates[1].mHasMinimumAmbienceRequirement = 1;
  this->mEntityStates[1].mResourceUpdateCallback = UFG::EntityTypeState::UpdateVehiclePreloads;
  *(_QWORD *)&this->mEntityStates[1].mAmbientModelRatioTarget = 1059481190i64;
  *(_QWORD *)&this->mEntityStates[1].mAmbientTextureRatio = 0i64;
  this->mEntityStates[1].mAmbientTextureRatioTarget = 0.30000001;
  this->mEntityStates[1].mAvailableAmbientTextureMemory = 0;
  if ( !this->mEntityStates[1].mRareSpawnPropertySets.capacity )
    UFG::qArray<UFG::qSymbol,0>::Reallocate(&this->mEntityStates[1].mRareSpawnPropertySets, 1u, "ObjectResourceManager");
  if ( !this->mEntityStates[1].mRareSpawnIsReady.capacity && this->mEntityStates[1].mRareSpawnIsReady.size != 1 )
  {
    v23 = UFG::qMalloc(1ui64, "ObjectResourceManager", 0i64);
    v24 = (bool *)v23;
    if ( this->mEntityStates[1].mRareSpawnIsReady.p )
    {
      for ( k = 0;
            k < this->mEntityStates[1].mRareSpawnIsReady.size;
            *((_BYTE *)&v23->mNext + v26) = this->mEntityStates[1].mRareSpawnIsReady.p[v26] )
      {
        v26 = k++;
      }
      operator delete[](this->mEntityStates[1].mRareSpawnIsReady.p);
    }
    this->mEntityStates[1].mRareSpawnIsReady.p = v24;
    this->mEntityStates[1].mRareSpawnIsReady.capacity = 1;
  }
  v27 = v22->size;
  v28 = this->mEntityStates[1].mRareSpawnPropertySets.capacity;
  v29 = v27 + 1;
  if ( (int)v27 + 1 > v28 )
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
    UFG::qArray<UFG::qSymbol,0>::Reallocate(&this->mEntityStates[1].mRareSpawnPropertySets, v30, "qArray.Add");
  }
  v31 = this->mEntityStates[1].mRareSpawnPropertySets.p;
  v22->size = v29;
  v31[v27] = UFG::gNullQSymbol;
  v32 = this->mEntityStates[1].mRareSpawnIsReady.size;
  v33 = this->mEntityStates[1].mRareSpawnIsReady.capacity;
  v34 = v32 + 1;
  if ( (int)v32 + 1 > v33 )
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
      if ( this->mEntityStates[1].mRareSpawnIsReady.p )
      {
        for ( m = 0i64; (unsigned int)m < this->mEntityStates[1].mRareSpawnIsReady.size; m = (unsigned int)(m + 1) )
          *((_BYTE *)&v35->mNext + m) = this->mEntityStates[1].mRareSpawnIsReady.p[m];
        operator delete[](this->mEntityStates[1].mRareSpawnIsReady.p);
      }
      this->mEntityStates[1].mRareSpawnIsReady.p = v36;
      this->mEntityStates[1].mRareSpawnIsReady.capacity = v8;
    }
  }
  v38 = this->mEntityStates[1].mRareSpawnIsReady.p;
  this->mEntityStates[1].mRareSpawnIsReady.size = v34;
  v38[v32] = 0;
  *(_QWORD *)&this->mEntityStates[2].mAmbientTextureRatio = 0i64;
  this->mEntityStates[2].mAvailableAmbientTextureMemory = 0;
  this->mEntityStates[2].mEntityType = Prop;
  *(_WORD *)&this->mEntityStates[2].mUpdateRequired = 256;
  this->mEntityStates[2].mHasMinimumAmbienceRequirement = 0;
  this->mEntityStates[2].mResourceUpdateCallback = UFG::EntityTypeState::UpdatePropPreloads;
  *(_QWORD *)&this->mEntityStates[2].mAmbientModelRatioTarget = 1028443341i64;
  this->mEntityStates[2].mAmbientTextureRatioTarget = 0.050000001;
}RatioTarget = 1028443341i64;
  this->mEntityStates[2].mAmbientTextureRatioTarget = 0.050000001;
}

// File Line: 331
// RVA: 0x43EB30
void __fastcall UFG::ObjectResourceManager::InitPools(UFG::ObjectResourceManager *this)
{
  unsigned int v2; // esi
  unsigned int v3; // ebp
  unsigned __int64 v4; // rax
  UFG::EntityTypeState **v5; // r15
  UFG::EntityTypeState *mEntityStates; // r14
  __int64 v7; // r12
  __int64 v8; // r13
  unsigned int v9; // edi
  unsigned int v10; // ebx
  unsigned __int64 v11; // rax
  UFG::allocator::free_link *v12; // rax
  UFG::EntityTypeState **v13; // rbp
  UFG::allocator::free_link *v14; // rdx
  __int64 v15; // r8
  int AllocationSize; // ebp
  int v17; // esi
  int v18; // edi
  int v19; // r14d
  int v20; // r14d
  int v21; // ebx
  int v22; // ebx
  UFG::PartDatabase *v23; // rax
  UFG::ResourcePriorityBucket *mCriticalBucket; // rax
  UFG::qArray<UFG::EntityTypeState *,0> resourceDescriptorList; // [rsp+28h] [rbp-40h] BYREF

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
  mEntityStates = this->mEntityStates;
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
    v5[v8] = mEntityStates++;
    --v7;
  }
  while ( v7 );
  AllocationSize = UFG::StreamFileWrapper::GetAllocationSize("Data\\Characters\\characterrigs.bin");
  v17 = UFG::StreamFileWrapper::GetAllocationSize("Data\\Characters_New\\characterrigs.bin");
  v18 = UFG::StreamFileWrapper::GetAllocationSize("Data\\Vehicles_New\\dummyvehiclerig.perm.bin");
  v19 = UFG::StreamFileWrapper::GetAllocationSize("Data\\props_new\\proprigs.bin");
  v20 = ((AllocationSize + 4095) & 0xFFFFF000)
      + ((v17 + 4095) & 0xFFFFF000)
      + ((v18 + 4095) & 0xFFFFF000)
      + ((UFG::StreamFileWrapper::GetAllocationSize("Data\\Props_new\\PropPhysics.bin") + 4095) & 0xFFFFF000)
      + ((v19 + 4095) & 0xFFFFF000);
  v21 = UFG::StreamFileWrapper::GetAllocationSize("Data\\Vehicles_New\\Global.temp.bin");
  v22 = ((UFG::StreamFileWrapper::GetAllocationSize("Data\\Characters_New\\Global.temp.bin") + 4095) & 0xFFFFF000)
      + ((v21 + 4095) & 0xFFFFF000);
  v23 = UFG::PartDatabase::Instance();
  UFG::PartPool::Init(&v23->mPool, v23->mPool.mMaxModelMemory - v20, v23->mPool.mMaxTextureMemory - v22);
  UFG::ResourcePool::Init(
    &this->mPool,
    DATA_TRUECROWD_RESOURCE,
    DATA_TRUECROWD_TEXTURE_RESOURCE,
    &resourceDescriptorList);
  if ( qSymbol_Reserved.mUID == qSymbol_Critical.mUID )
  {
    mCriticalBucket = this->mPool.mCriticalBucket;
  }
  else if ( qSymbol_Reserved.mUID == qSymbol_High.mUID )
  {
    mCriticalBucket = this->mPool.mHighBucket;
  }
  else if ( qSymbol_Reserved.mUID == qSymbol_Medium.mUID || qSymbol_Reserved.mUID == qSymbol_Low.mUID )
  {
    mCriticalBucket = this->mPool.mLowBucket;
  }
  else
  {
    mCriticalBucket = this->mPool.mReservedBucket;
  }
  mCriticalBucket->mReserveSize[0] = 3145728;
  mCriticalBucket->mReserveSize[1] = 0x100000;
  mCriticalBucket->mMaxSize[0] = 3145728;
  mCriticalBucket->mMaxSize[1] = 0x100000;
  if ( v5 )
    operator delete[](v5);
}

// File Line: 367
// RVA: 0x443080
void __fastcall UFG::ObjectResourceManager::SetActiveAmbience(
        UFG::ObjectResourceManager *this,
        bool vehicles,
        bool characters)
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
void __fastcall UFG::ObjectResourceManager::SetFragmentationReservePercentage(
        UFG::ObjectResourceManager *this,
        float percent)
{
  this->mPool.mFragmentationReservePercentage = percent;
  this->mPool.mDirty = 1;
}

// File Line: 412
// RVA: 0x43D4D0
__int64 __fastcall UFG::ObjectResourceManager::GetBytesRemainingToLoad(UFG::ObjectResourceManager *this)
{
  unsigned int v1; // r8d
  UFG::ResourceRequest **p; // r9
  __int64 size; // r10
  __int64 v4; // rax
  unsigned int v5; // edx
  UFG::ResourceRequest **v6; // rax
  __int64 v7; // r9
  __int64 v8; // rcx

  v1 = 0;
  if ( this->mPool.mQueued.size )
  {
    p = this->mPool.mQueued.p;
    size = this->mPool.mQueued.size;
    do
    {
      v4 = (__int64)*p++;
      v1 += *(_DWORD *)(*(_QWORD *)(v4 + 32) + 16i64) + *(_DWORD *)(*(_QWORD *)(v4 + 32) + 20i64);
      --size;
    }
    while ( size );
  }
  v5 = this->mPool.mLoading.size;
  if ( v5 )
  {
    v6 = this->mPool.mLoading.p;
    v7 = v5;
    do
    {
      v8 = (__int64)*v6++;
      v1 += *(_DWORD *)(*(_QWORD *)(v8 + 32) + 16i64) + *(_DWORD *)(*(_QWORD *)(v8 + 32) + 20i64);
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
  unsigned int v2; // esi
  bool updated; // bl
  UFG::ResourcePriorityBucket *mHighBucket; // r9
  UFG::ResourcePriorityBucket *mLowBucket; // r8
  bool v6; // dl
  bool v7; // al

  v2 = 0;
  do
  {
    updated = UFG::ResourcePool::UpdateAmbientPreloads(&this->mPool);
    UFG::ResourcePool::UpdateRequests(&this->mPool);
    mHighBucket = this->mPool.mHighBucket;
    mLowBucket = this->mPool.mLowBucket;
    v6 = updated;
    if ( mHighBucket->mMemoryUsage[0][1]
       + mHighBucket->mMemoryUsage[1][1]
       + mHighBucket->mMemoryUsage[2][1]
       + mLowBucket->mMemoryUsage[0][1]
       + mLowBucket->mMemoryUsage[1][1]
       + mLowBucket->mMemoryUsage[2][1] > 0xA00000 )
      v6 = 0;
    v7 = v6;
    if ( mLowBucket->mMemoryUsage[0][0]
       + mLowBucket->mMemoryUsage[1][0]
       + mLowBucket->mMemoryUsage[2][0]
       + mHighBucket->mMemoryUsage[0][0]
       + mHighBucket->mMemoryUsage[1][0]
       + mHighBucket->mMemoryUsage[2][0] > 0x2D00000 )
      v7 = 0;
    ++v2;
  }
  while ( v2 < 0xF && v7 );
}

// File Line: 448
// RVA: 0x444680
void __fastcall UFG::ObjectResourceManager::Update(UFG::ObjectResourceManager *this, float deltaTime)
{
  bool *p_mUpdateRequired; // rbx
  __int64 v4; // rsi
  UFG::UIHKTextOverlay *Instance; // rax
  UFG::qString *v6; // rax
  __int64 i; // rbx
  char *v8; // rax
  UFG::qString *v9; // rax
  UFG::qString v10; // [rsp+38h] [rbp-B0h] BYREF
  UFG::qString v11; // [rsp+60h] [rbp-88h] BYREF
  UFG::qString text; // [rsp+88h] [rbp-60h] BYREF
  UFG::qString v13; // [rsp+B0h] [rbp-38h] BYREF

  p_mUpdateRequired = &this->mEntityStates[0].mUpdateRequired;
  v4 = 3i64;
  do
  {
    if ( *p_mUpdateRequired )
    {
      (*(void (**)(void))(p_mUpdateRequired + 28))();
      *p_mUpdateRequired = 0;
    }
    p_mUpdateRequired += 72;
    --v4;
  }
  while ( v4 );
  UFG::ResourcePool::UpdateAmbientPreloads(&this->mPool);
  UFG::ObjectResourceManager::UpdateRareRequests(this);
  UFG::ObjectResourceManager::UpdateRareObjectAvailability(this);
  UFG::ResourcePool::UpdateRequests(&this->mPool);
  UFG::ObjectResourceManager::UpdateAvailableVehicles(this);
  this->mPool.mDirty = 0;
  if ( UFG::UIHKTweakables::TrafficAvailableVehicles )
  {
    Instance = UFG::UIHKTextOverlay::getInstance();
    if ( Instance )
    {
      if ( !UFG::UISubtitleMessageQueue::IsPlaying(&Instance->mSubtitleQueue) )
      {
        UFG::qString::qString(&text, "ff7f50");
        UFG::qString::qString(&v11);
        UFG::qString::Format(&v11, "%d ambient traffic vehicles available", this->mAmbientVehicles.size);
        UFG::qString::qString(&v13, &text);
        UFG::UIHKTextOverlay::ShowMessageOnScreen(v11.mData, 2.0, 2.0, 100.0, v6);
        UFG::qString::qString(&v10, &customCaption);
        for ( i = 0i64; (unsigned int)i < this->mAmbientVehicles.size; i = (unsigned int)(i + 1) )
        {
          if ( (_DWORD)i )
            UFG::qString::operator+=(&v10, ", ");
          v8 = PropertyUtils::Get<char const *>(
                 this->mAmbientVehicles.p[i],
                 (UFG::qArray<unsigned long,0> *)&qSymbol_Description_13,
                 DEPTH_RECURSE);
          UFG::qString::operator+=(&v10, v8);
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
  if ( forceFlush )
  {
    UFG::ObjectResourceManager::ResetAllRarePreloadStatuses(this, Character);
    UFG::ObjectResourceManager::ResetAllRarePreloadStatuses(this, Vehicle);
    UFG::ObjectResourceManager::ResetAllRarePreloadStatuses(this, Prop);
    UFG::ObjectResourceManager::RemoveAllUnwantedRareRequests(this, Character, forceFlush);
    UFG::ObjectResourceManager::RemoveAllUnwantedRareRequests(this, Vehicle, forceFlush);
    UFG::ObjectResourceManager::RemoveAllUnwantedRareRequests(this, Prop, forceFlush);
  }
  UFG::ResourcePool::FlushResources(&this->mPool, forceFlush);
}

// File Line: 530
// RVA: 0x439950
void __fastcall UFG::ObjectResourceManager::ChangeObjectPriority(
        UFG::ObjectResourceManager *this,
        UFG::StreamedResourceComponent *resourceComponent,
        UFG::qSymbol *newPriority)
{
  unsigned int mUID; // eax
  unsigned int v4; // ebx
  int v7; // r11d
  int v8; // edi
  unsigned int v9; // ebx
  __int64 i; // rsi
  UFG::TrueCrowdModel *v11; // r8
  __int64 mOffset; // rax
  UFG::TrueCrowdModel *v13; // rax
  UFG::ResourceRequest *mRequest; // rdx
  UFG::TrueCrowdTextureSet *Texture; // rax
  UFG::ResourceRequest *v16; // rcx

  mUID = resourceComponent->mActivePriority.mUID;
  v4 = newPriority->mUID;
  if ( newPriority->mUID != mUID && resourceComponent->mMeshLoader.mTrueCrowdInstance.mNumParts )
  {
    v7 = 2;
    if ( mUID == qSymbol_Critical.mUID )
    {
      v8 = 2;
    }
    else if ( mUID == qSymbol_High.mUID )
    {
      v8 = 3;
    }
    else if ( mUID == qSymbol_Medium.mUID || mUID == qSymbol_Low.mUID )
    {
      v8 = 4;
    }
    else
    {
      v8 = 4;
      if ( mUID == qSymbol_Reserved.mUID )
        v8 = 1;
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
    for ( i = v7; v9 < resourceComponent->mMeshLoader.mTrueCrowdInstance.mNumParts; ++v9 )
    {
      if ( resourceComponent->mMeshLoader.mTrueCrowdInstance.mPart[v9].mModelIndex != -1 )
      {
        v11 = resourceComponent->mMeshLoader.mTrueCrowdInstance.mSet->mFiles[v9].p[resourceComponent->mMeshLoader.mTrueCrowdInstance.mPart[v9].mModelIndex];
        if ( resourceComponent->mMeshLoader.mHighDefinition )
        {
          mOffset = v11->mHighResolutionResource.mOffset;
          if ( mOffset )
          {
            v13 = (UFG::TrueCrowdModel *)((char *)&v11->mHighResolutionResource + mOffset);
            if ( v13 )
              v11 = v13;
          }
        }
        mRequest = v11->mRequest;
        if ( mRequest )
        {
          ++mRequest->mPriorityRefCounts[i];
          mRequest->mLastReferencedFrame = Illusion::gEngine.mFrameCount;
          --mRequest->mPriorityRefCounts[v8];
          mRequest->mLastReferencedFrame = Illusion::gEngine.mFrameCount;
          this->mPool.mDirty = 1;
        }
        Texture = UFG::MeshResourceLoader::GetTexture(&resourceComponent->mMeshLoader, v9);
        if ( Texture )
        {
          v16 = Texture->mRequest;
          if ( v16 )
          {
            ++v16->mPriorityRefCounts[i];
            v16->mLastReferencedFrame = Illusion::gEngine.mFrameCount;
            --v16->mPriorityRefCounts[v8];
            v16->mLastReferencedFrame = Illusion::gEngine.mFrameCount;
            this->mPool.mDirty = 1;
          }
        }
      }
    }
  }
}

// File Line: 578
// RVA: 0x442790
UFG::PreloadRequest *__fastcall UFG::ObjectResourceManager::RequestPreload(
        UFG::ObjectResourceManager *this,
        UFG::qPropertySet *propertySet,
        int *priority,
        bool directRequest)
{
  int v7; // r10d
  UFG::qColour **p_mColourTint; // rax
  UFG::TrueCrowdSet *DataBase; // rax
  unsigned int size; // r8d
  unsigned int v11; // ecx
  UFG::EntityTypeState **p; // rdx
  unsigned int v13; // r8d
  int v14; // eax
  UFG::TrueCrowdSet::Instance instance; // [rsp+20h] [rbp-128h] BYREF

  v7 = 15;
  p_mColourTint = &instance.mPart[0].mColourTint;
  do
  {
    --v7;
    *(p_mColourTint - 1) = 0i64;
    *p_mColourTint = 0i64;
    p_mColourTint += 2;
  }
  while ( v7 >= 0 );
  instance.mSet = 0i64;
  instance.mNumParts = 0;
  if ( *priority == qSymbol_Low.mUID )
  {
    DataBase = (UFG::TrueCrowdSet *)UFG::TrueCrowdDataBase::QueryDataBase(
                                      UFG::TrueCrowdDataBase::sTrueCrowdDataBase,
                                      propertySet,
                                      0i64);
    instance.mSet = DataBase;
  }
  else
  {
    UFG::TrueCrowdDataBase::QueryInstance(UFG::TrueCrowdDataBase::sTrueCrowdDataBase, propertySet, &instance);
    DataBase = instance.mSet;
  }
  size = this->mPool.mEntityStates.size;
  v11 = 0;
  if ( size )
  {
    p = this->mPool.mEntityStates.p;
    while ( (*DataBase->mFiles[0].p)->mType.mValue != (*p)->mEntityType )
    {
      ++v11;
      ++p;
      if ( v11 >= size )
        goto LABEL_10;
    }
    v13 = v11 + 3;
  }
  else
  {
LABEL_10:
    v13 = -1;
  }
  v14 = *priority;
  if ( *priority == qSymbol_Reserved.mUID )
    v13 = 0;
  if ( v14 == qSymbol_Critical.mUID )
    v13 = 1;
  if ( v14 == qSymbol_High.mUID )
    v13 = 2;
  return UFG::ResourcePool::RequestPreload(&this->mPool, &instance, v13, directRequest);
}

// File Line: 612
// RVA: 0x43FBE0
void __fastcall UFG::ObjectResourceManager::PreLoadCriticalResource(
        UFG::ObjectResourceManager *this,
        UFG::qPropertySet *propertySet)
{
  int v3; // r8d
  UFG::qColour **p_mColourTint; // rax
  UFG::PreloadRequest *v5; // rax
  UFG::TrueCrowdSet::Instance instance; // [rsp+20h] [rbp-128h] BYREF

  v3 = 15;
  p_mColourTint = &instance.mPart[0].mColourTint;
  do
  {
    --v3;
    *(p_mColourTint - 1) = 0i64;
    *p_mColourTint = 0i64;
    p_mColourTint += 2;
  }
  while ( v3 >= 0 );
  instance.mSet = 0i64;
  instance.mNumParts = 0;
  UFG::TrueCrowdDataBase::QueryInstance(UFG::TrueCrowdDataBase::sTrueCrowdDataBase, propertySet, &instance);
  v5 = UFG::ResourcePool::RequestPreload(&this->mPool, &instance, 1u, 1);
  UFG::ResourcePool::PreloadInstance(&this->mPool, v5, &instance);
}

// File Line: 620
// RVA: 0x441910
void __fastcall UFG::ObjectResourceManager::ReleaseCriticalResource(
        UFG::ObjectResourceManager *this,
        UFG::qPropertySet *propertySet)
{
  UFG::TrueCrowdSet *DataBase; // rax

  DataBase = (UFG::TrueCrowdSet *)UFG::TrueCrowdDataBase::QueryDataBase(
                                    UFG::TrueCrowdDataBase::sTrueCrowdDataBase,
                                    propertySet,
                                    0i64);
  UFG::ResourcePool::ReleasePreload(&this->mPool, DataBase, 1u, 1);
}

// File Line: 626
// RVA: 0x441570
void __fastcall UFG::ObjectResourceManager::ReleaseAllAmbientPreloads(UFG::ObjectResourceManager *this)
{
  UFG::ResourcePool::ReleaseAmbientPreloads(&this->mPool, Vehicle);
  this->mCurrentSpawnset = UFG::gNullQSymbol;
  UFG::ObjectResourceManager::ResetAllRarePreloadStatuses(this, Vehicle);
  UFG::ObjectResourceManager::RemoveAllUnwantedRareRequests(this, Vehicle, 1);
  UFG::ObjectResourceManager::UpdateAvailableVehicles(this);
  UFG::ResourcePool::ReleaseAllAmbientPreloads(&this->mPool);
}

// File Line: 632
// RVA: 0x439850
bool __fastcall UFG::ObjectResourceManager::CanSpawnAmbient(
        UFG::ObjectResourceManager *this,
        UFG::qPropertySet *propertySet,
        component_StreamedResource *dataPtr,
        bool preloadedOnly)
{
  UFG::TrueCrowdSet *DataBase; // rax

  if ( !propertySet )
    return 0;
  DataBase = (UFG::TrueCrowdSet *)UFG::TrueCrowdDataBase::QueryDataBase(
                                    UFG::TrueCrowdDataBase::sTrueCrowdDataBase,
                                    propertySet,
                                    dataPtr);
  return UFG::ResourcePool::CanSpawnAmbient(&this->mPool, DataBase, preloadedOnly);
}

// File Line: 642
// RVA: 0x43F280
bool __fastcall UFG::ObjectResourceManager::IsLoaded(UFG::ObjectResourceManager *this, UFG::qPropertySet *propertySet)
{
  UFG::TrueCrowdSet *DataBase; // rax

  DataBase = (UFG::TrueCrowdSet *)UFG::TrueCrowdDataBase::QueryDataBase(
                                    UFG::TrueCrowdDataBase::sTrueCrowdDataBase,
                                    propertySet,
                                    0i64);
  if ( DataBase )
    LOBYTE(DataBase) = UFG::TrueCrowdSet::IsLoaded(DataBase);
  return (char)DataBase;
}

// File Line: 668
// RVA: 0x445BD0
void __fastcall UFG::ObjectResourceManager::UpdateCharacterPreloads(UFG::ObjectResourceManager *this)
{
  int v2; // edx
  unsigned int size; // r8d
  unsigned int v4; // ebx
  unsigned int v5; // r8d
  __int64 v6; // rdi
  UFG::PreloadRequest *v7; // rax
  UFG::qArray<UFG::qPropertySet *,0> *p_mAvailableDrivers; // r12
  unsigned int v9; // r13d
  int *p_mRefCount; // r15
  __int64 v11; // rdi
  UFG::qPropertyList *v12; // rsi
  int v13; // ebx
  UFG::PreloadRequest *v14; // rax
  __int64 v15; // rdi
  __int64 v16; // rbp
  __int64 mOffset; // rax
  char *v18; // rcx
  float v19; // xmm1_4
  int mTotalWeight; // eax
  int v21; // ebx
  UFG::PreloadRequest *v22; // rax
  unsigned int mUID; // eax
  unsigned int v24; // ebx
  unsigned int capacity; // edx
  unsigned int v26; // edx
  UFG::qPropertySet *PropertySet; // rax
  UFG::qPropertyList *v28; // rax
  UFG::qPropertySet *v29; // rax
  UFG::qPropertySet *v30; // rsi
  int v31; // edx
  UFG::qColour **p_mColourTint; // rcx
  UFG::PreloadRequest *v33; // rax
  __int64 v34; // rbp
  unsigned int v35; // ebx
  unsigned int v36; // eax
  signed int v37; // ebp
  __int64 v38; // rsi
  int v39; // ebp
  __int64 v40; // rcx
  __int64 v41; // rbx
  UFG::qNode<UFG::PreloadRequest,UFG::PreloadRequest> *mPrev; // rax
  UFG::qArray<UFG::PreloadRequest *,0> *mPreloadBuckets; // r8
  int v44; // r9d
  __int64 v45; // rdx
  unsigned int v46; // eax
  UFG::qPropertySet *v47; // [rsp+20h] [rbp-198h]
  __int64 v48; // [rsp+28h] [rbp-190h]
  UFG::TrueCrowdSet::Instance instance; // [rsp+40h] [rbp-178h] BYREF
  UFG::qSymbol priority; // [rsp+1C0h] [rbp+8h] BYREF
  UFG::qSymbol propSetName; // [rsp+1C8h] [rbp+10h] BYREF
  UFG::qSymbol *p_priority; // [rsp+1D0h] [rbp+18h]
  __int64 v53; // [rsp+1D8h] [rbp+20h]

  v2 = 0;
  size = this->mPool.mEntityStates.size;
  if ( size )
  {
    while ( this->mPool.mEntityStates.p[v2]->mEntityType )
    {
      if ( ++v2 >= size )
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
  if ( *(unsigned int *)((char *)&this->mPool.mPreloadBuckets->size + v6) )
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
  UFG::ObjectResourceManager::ResetAllRarePreloadStatuses(this, Character);
  p_mAvailableDrivers = &this->mAvailableDrivers;
  this->mAvailableDrivers.size = 0;
  this->mDefaultDriver = 0i64;
  v9 = 1;
  if ( UFG::PedSpawnManager::GetInstance() && !UFG::PedSpawnManager::msResourcesSuspended )
  {
    p_mRefCount = &UFG::PedSpawnManager::GetInstance()->mActiveSpawnSets[0].mRefCount;
    v11 = 40i64;
    v53 = 40i64;
    do
    {
      if ( *p_mRefCount > 0 )
      {
        v12 = UFG::qPropertySet::Get<UFG::qPropertyList>(
                *((UFG::qPropertySet **)p_mRefCount - 1),
                (UFG::qArray<unsigned long,0> *)&qSymbol_SpawnSet,
                DEPTH_RECURSE);
        if ( v12 )
        {
          if ( p_mRefCount[1] >= 0 )
          {
            if ( p_mRefCount[4] )
            {
              v15 = 0i64;
              v16 = 0i64;
              p_priority = (UFG::qSymbol *)(unsigned int)p_mRefCount[4];
              do
              {
                mOffset = v12->mWeights.mOffset;
                if ( mOffset && (v18 = (char *)&v12->mWeights + mOffset) != 0i64 )
                {
                  v19 = (float)*(int *)&v18[v16];
                  mTotalWeight = v12->mTotalWeight;
                }
                else
                {
                  mTotalWeight = v12->mNumElements;
                  v19 = *(float *)&FLOAT_1_0;
                }
                v21 = (int)(float)((float)p_mRefCount[1] * (float)(v19 / (float)mTotalWeight));
                if ( v21 )
                {
                  v47 = *(UFG::qPropertySet **)(v15 + *((_QWORD *)p_mRefCount + 3));
                  priority.mUID = qSymbol_Low.mUID;
                  v22 = UFG::ObjectResourceManager::RequestPreload(this, v47, (int *)&priority, 0);
                  v22->mDesiredInstanceCount += v21;
                  mUID = p_mAvailableDrivers->size;
                  priority.mUID = mUID;
                  v24 = mUID + 1;
                  capacity = this->mAvailableDrivers.capacity;
                  if ( mUID + 1 > capacity )
                  {
                    if ( capacity )
                      v26 = 2 * capacity;
                    else
                      v26 = 1;
                    for ( ; v26 < v24; v26 *= 2 )
                      ;
                    if ( v26 <= 2 )
                      v26 = 2;
                    if ( v26 - v24 > 0x10000 )
                      v26 = mUID + 65537;
                    UFG::qArray<UFG::CompositeDrawableComponent *,32>::Reallocate(
                      (UFG::qArray<UFG::qReflectInventoryBase *,0> *)&this->mAvailableDrivers,
                      v26,
                      "qArray.Add");
                    mUID = priority.mUID;
                  }
                  p_mAvailableDrivers->size = v24;
                  this->mAvailableDrivers.p[mUID] = v47;
                }
                v16 += 4i64;
                v15 += 8i64;
                p_priority = (UFG::qSymbol *)((char *)p_priority - 1);
              }
              while ( p_priority );
              v11 = v53;
            }
            UFG::ObjectResourceManager::UpdateRareSpawnResourcesFromPropertySet(
              this,
              Character,
              *((UFG::qPropertySet **)p_mRefCount - 1));
          }
        }
        else
        {
          v13 = *p_mRefCount;
          p_priority = &priority;
          priority.mUID = qSymbol_Low.mUID;
          v14 = UFG::ObjectResourceManager::RequestPreload(
                  this,
                  *((UFG::qPropertySet **)p_mRefCount - 1),
                  (int *)&priority,
                  0);
          v14->mDesiredInstanceCount += v13;
        }
      }
      p_mRefCount += 14;
      v53 = --v11;
    }
    while ( v11 );
    v6 = v48;
    v4 = propSetName.mUID;
  }
  if ( this->mEntityStates[1].mActive )
  {
    PropertySet = UFG::PropertySetManager::FindPropertySet(&qSymbolX_spawnset_default);
    v28 = UFG::qPropertySet::Get<UFG::qPropertyList>(
            PropertySet,
            (UFG::qArray<unsigned long,0> *)&qSymbol_SpawnSet,
            DEPTH_RECURSE);
    if ( v28->mNumElements )
    {
      propSetName.mUID = UFG::qPropertyList::Get<UFG::qSymbol>(v28, 0)->mUID;
      v29 = UFG::PropertySetManager::FindPropertySet(&propSetName);
      v30 = v29;
      this->mDefaultDriver = v29;
      v31 = 15;
      p_mColourTint = &instance.mPart[0].mColourTint;
      do
      {
        *(p_mColourTint - 1) = 0i64;
        *p_mColourTint = 0i64;
        p_mColourTint += 2;
        --v31;
      }
      while ( v31 >= 0 );
      instance.mSet = 0i64;
      instance.mNumParts = 0;
      UFG::TrueCrowdDataBase::QueryInstance(UFG::TrueCrowdDataBase::sTrueCrowdDataBase, v29, &instance);
      p_priority = &priority;
      priority.mUID = qSymbol_Low.mUID;
      v33 = UFG::ObjectResourceManager::RequestPreload(this, v30, (int *)&priority, 0);
      v33->mDesiredInstanceCount = 1;
      UFG::ResourcePool::PreloadInstance(&this->mPool, v33, &instance);
      v34 = p_mAvailableDrivers->size;
      v35 = v34 + 1;
      v36 = this->mAvailableDrivers.capacity;
      if ( (int)v34 + 1 > v36 )
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
          (UFG::qArray<UFG::qReflectInventoryBase *,0> *)&this->mAvailableDrivers,
          v9,
          "qArray.Add");
      }
      p_mAvailableDrivers->size = v35;
      this->mAvailableDrivers.p[v34] = v30;
    }
    v37 = *(unsigned int *)((char *)&this->mPool.mPreloadBuckets->size + v6) - 1;
    v38 = v37;
    if ( v37 >= 0 )
    {
      v39 = *(unsigned int *)((char *)&this->mPool.mPreloadBuckets->size + v6);
      do
      {
        v40 = *(__int64 *)((char *)&this->mPool.mPreloadBuckets->p + v6);
        v41 = *(_QWORD *)(v40 + 8 * v38);
        if ( !*(_BYTE *)(v41 + 313) && !*(_DWORD *)(v41 + 316) )
        {
          UFG::ResourcePool::ReleaseResourceSetFiles(&this->mPool, *(UFG::PreloadRequest **)(v40 + 8 * v38));
          *(_QWORD *)(v41 + 16) = 0i64;
          *(_DWORD *)(v41 + 24) = 0;
          mPrev = this->mPool.mEmptyRequestList.mNode.mPrev;
          mPrev->mNext = (UFG::qNode<UFG::PreloadRequest,UFG::PreloadRequest> *)v41;
          *(_QWORD *)v41 = mPrev;
          *(_QWORD *)(v41 + 8) = &this->mPool.mEmptyRequestList;
          this->mPool.mEmptyRequestList.mNode.mPrev = (UFG::qNode<UFG::PreloadRequest,UFG::PreloadRequest> *)v41;
          mPreloadBuckets = this->mPool.mPreloadBuckets;
          v44 = v39;
          if ( v39 != *(unsigned int *)((char *)&mPreloadBuckets->size + v6) )
          {
            v45 = 8 * v38 + 8;
            do
            {
              *(UFG::PreloadRequest **)(*(char **)((char *)&mPreloadBuckets->p + v6) + v45 - 8) = *(UFG::PreloadRequest **)(*(char **)((char *)&mPreloadBuckets->p + v6) + v45);
              ++v44;
              v45 += 8i64;
            }
            while ( v44 != *(unsigned int *)((char *)&mPreloadBuckets->size + v6) );
          }
          v46 = *(unsigned int *)((char *)&mPreloadBuckets->size + v6);
          if ( v46 > 1 )
            *(unsigned int *)((char *)&mPreloadBuckets->size + v6) = v46 - 1;
          else
            *(unsigned int *)((char *)&mPreloadBuckets->size + v6) = 0;
        }
        --v39;
        --v38;
      }
      while ( v38 >= 0 );
    }
  }
  else
  {
    UFG::ResourcePool::ReleaseAllUnReferencedPreloads(&this->mPool, v4, UFG::PedSpawnManager::msResourcesSuspended);
  }
  UFG::ObjectResourceManager::RemoveAllUnwantedRareRequests(this, 0, UFG::PedSpawnManager::msResourcesSuspended);
  this->mEntityStates[2].mUpdateRequired = 1;
  this->mPool.mDirty = 1;
}

// File Line: 762
// RVA: 0x4466D0
void __fastcall UFG::ObjectResourceManager::UpdatePropPreloads(UFG::ObjectResourceManager *this)
{
  int v2; // edx
  unsigned int size; // r8d
  unsigned int v4; // edx
  unsigned int v5; // r8d
  __int64 v6; // r12
  UFG::PreloadRequest *v7; // rdx
  UFG::PedSpawnManager *Instance; // rax
  UFG::qArray<UFG::qPropertySet *,0> *p_mSpawnInfoArray; // r15
  __int64 v10; // r13
  UFG::qPropertyList *v11; // rax
  UFG::qPropertyList *v12; // rsi
  unsigned int v13; // ebp
  unsigned int v14; // ebx
  UFG::qSymbol *v15; // rax
  UFG::qPropertySet *v16; // rax
  __int64 i; // r14
  UFG::qPropertyList *v18; // rax
  UFG::qPropertyList *v19; // rbp
  unsigned int mNumElements; // esi
  unsigned int j; // ebx
  UFG::qSymbol *v22; // rax
  UFG::qPropertySet *PropertySet; // rax
  signed int v24; // eax
  __int64 v25; // rbp
  unsigned int v26; // r14d
  UFG::ObjectResourceManager::RareSpawnRecord *v27; // rsi
  int v28; // ecx
  UFG::qArray<UFG::PreloadRequest *,0> *mPreloadBuckets; // r9
  unsigned int v30; // r8d
  UFG::PreloadRequest **p; // r9
  UFG::TrueCrowdSet *mSet; // r10
  UFG::PreloadRequest *v33; // rdx
  int v34; // ecx
  UFG::PreloadRequest *v35; // rbx
  UFG::qArray<UFG::PreloadRequest *,0> *v36; // r9
  __int64 v37; // rcx
  unsigned int v38; // edx
  UFG::PreloadRequest **v39; // r8
  UFG::qNode<UFG::PreloadRequest,UFG::PreloadRequest> *mPrev; // rax
  UFG::qNode<UFG::ObjectResourceManager::RareSpawnRecord,UFG::ObjectResourceManager::RareSpawnRecord> *v41; // rax
  unsigned int v42; // r8d
  __int64 v43; // rdx
  unsigned int v44; // eax
  signed int v45; // ebp
  __int64 v46; // rsi
  unsigned int v47; // ebp
  UFG::PreloadRequest **v48; // rcx
  UFG::PreloadRequest *v49; // rbx
  UFG::qNode<UFG::PreloadRequest,UFG::PreloadRequest> *v50; // rax
  UFG::qArray<UFG::PreloadRequest *,0> *v51; // r8
  unsigned int v52; // r9d
  __int64 v53; // rdx
  unsigned int v54; // eax
  UFG::qSymbol priority; // [rsp+70h] [rbp+8h] BYREF
  UFG::qSymbol *p_priority; // [rsp+78h] [rbp+10h]

  v2 = 0;
  size = this->mPool.mEntityStates.size;
  if ( size )
  {
    while ( this->mPool.mEntityStates.p[v2]->mEntityType != Prop )
    {
      if ( ++v2 >= size )
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
  if ( this->mPool.mPreloadBuckets[v4].size )
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
  Instance = UFG::PedSpawnManager::GetInstance();
  if ( Instance && !UFG::PedSpawnManager::msResourcesSuspended )
  {
    p_mSpawnInfoArray = &Instance->mActiveSpawnSets[0].mSpawnInfoArray;
    v10 = 40i64;
    do
    {
      if ( (int)p_mSpawnInfoArray[-1].size > 0 )
      {
        if ( p_mSpawnInfoArray->size )
        {
          for ( i = 0i64; (unsigned int)i < p_mSpawnInfoArray->size; i = (unsigned int)(i + 1) )
          {
            v18 = UFG::qPropertySet::Get<UFG::qPropertyList>(
                    p_mSpawnInfoArray->p[i],
                    (UFG::qArray<unsigned long,0> *)&qSymbol_PropList,
                    DEPTH_RECURSE);
            v19 = v18;
            if ( v18 )
            {
              mNumElements = v18->mNumElements;
              for ( j = 0; j < mNumElements; ++j )
              {
                v22 = UFG::qPropertyList::Get<UFG::qSymbol>(v19, j);
                if ( v22->mUID != UFG::gNullQSymbol.mUID )
                {
                  PropertySet = UFG::PropertySetManager::FindPropertySet(v22);
                  p_priority = &priority;
                  priority.mUID = qSymbol_Low.mUID;
                  UFG::ObjectResourceManager::RequestPreload(this, PropertySet, (int *)&priority, 0);
                }
              }
            }
          }
        }
        else
        {
          v11 = UFG::qPropertySet::Get<UFG::qPropertyList>(
                  (UFG::qPropertySet *)p_mSpawnInfoArray[-2].p,
                  (UFG::qArray<unsigned long,0> *)&qSymbol_PropList,
                  DEPTH_RECURSE);
          v12 = v11;
          if ( v11 )
          {
            v13 = v11->mNumElements;
            v14 = 0;
            if ( v13 )
            {
              p_priority = &priority;
              do
              {
                v15 = UFG::qPropertyList::Get<UFG::qSymbol>(v12, v14);
                v16 = UFG::PropertySetManager::FindPropertySet(v15);
                priority.mUID = qSymbol_Low.mUID;
                UFG::ObjectResourceManager::RequestPreload(this, v16, (int *)&priority, 0);
                ++v14;
              }
              while ( v14 < v13 );
            }
          }
        }
      }
      p_mSpawnInfoArray = (UFG::qArray<UFG::qPropertySet *,0> *)((char *)p_mSpawnInfoArray + 56);
      --v10;
    }
    while ( v10 );
  }
  v24 = this->mRareSpawnList[2].size - 1;
  v25 = v24;
  if ( v24 >= 0 )
  {
    v26 = this->mRareSpawnList[2].size;
    do
    {
      v27 = this->mRareSpawnList[2].p[v25];
      v28 = 0;
      mPreloadBuckets = this->mPool.mPreloadBuckets;
      v30 = mPreloadBuckets->size;
      if ( mPreloadBuckets->size )
      {
        p = mPreloadBuckets->p;
        mSet = v27->mInstance.mSet;
        while ( 1 )
        {
          v33 = p[v28];
          if ( v33->mInstance.mSet == mSet )
            break;
          if ( ++v28 >= v30 )
            goto LABEL_57;
        }
        if ( !v33->mSpawnSetValid && !v33->mDirectRequestCount )
        {
          v34 = 0;
          while ( 1 )
          {
            v35 = p[v34];
            if ( v35->mInstance.mSet == mSet )
              break;
            if ( ++v34 >= v30 )
              goto LABEL_51;
          }
          v35->mSpawnSetValid = 0;
          if ( !v35->mDirectRequestCount )
          {
            UFG::ResourcePool::ReleaseResourceSetFiles(&this->mPool, v35);
            v36 = this->mPool.mPreloadBuckets;
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
              if ( (int)v37 >= 0 )
              {
                v39[v37] = v39[v38 - 1];
                if ( v36->size > 1 )
                  --v36->size;
                else
                  v36->size = 0;
              }
            }
LABEL_50:
            mPrev = this->mPool.mEmptyRequestList.mNode.mPrev;
            mPrev->mNext = v35;
            v35->mPrev = mPrev;
            v35->mNext = &this->mPool.mEmptyRequestList.mNode;
            this->mPool.mEmptyRequestList.mNode.mPrev = v35;
          }
LABEL_51:
          v41 = this->mEmptyRareSpawnList.mNode.mPrev;
          v41->mNext = v27;
          v27->mPrev = v41;
          v27->mNext = &this->mEmptyRareSpawnList.mNode;
          this->mEmptyRareSpawnList.mNode.mPrev = v27;
          v42 = v26;
          if ( v26 != this->mRareSpawnList[2].size )
          {
            v43 = 8 * v25 + 8;
            do
            {
              *(UFG::ObjectResourceManager::RareSpawnRecord **)((char *)this->mRareSpawnList[2].p + v43 - 8) = *(UFG::ObjectResourceManager::RareSpawnRecord **)((char *)this->mRareSpawnList[2].p + v43);
              ++v42;
              v43 += 8i64;
            }
            while ( v42 != this->mRareSpawnList[2].size );
          }
          v44 = this->mRareSpawnList[2].size;
          if ( v44 > 1 )
            this->mRareSpawnList[2].size = v44 - 1;
          else
            this->mRareSpawnList[2].size = 0;
        }
      }
LABEL_57:
      --v26;
      --v25;
    }
    while ( v25 >= 0 );
  }
  v45 = this->mPool.mPreloadBuckets[v6].size - 1;
  v46 = v45;
  if ( v45 >= 0 )
  {
    v47 = this->mPool.mPreloadBuckets[v6].size;
    do
    {
      v48 = this->mPool.mPreloadBuckets[v6].p;
      v49 = v48[v46];
      if ( !v49->mSpawnSetValid && !v49->mDirectRequestCount )
      {
        UFG::ResourcePool::ReleaseResourceSetFiles(&this->mPool, v48[v46]);
        *(_QWORD *)&v49->mDesiredInstanceCount = 0i64;
        v49->mVarietyRatio = 0.0;
        v50 = this->mPool.mEmptyRequestList.mNode.mPrev;
        v50->mNext = v49;
        v49->mPrev = v50;
        v49->mNext = &this->mPool.mEmptyRequestList.mNode;
        this->mPool.mEmptyRequestList.mNode.mPrev = v49;
        v51 = this->mPool.mPreloadBuckets;
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
  this->mPool.mDirty = 1;
}

// File Line: 824
// RVA: 0x447540
void __fastcall UFG::ObjectResourceManager::UpdateVehiclePreloads(UFG::ObjectResourceManager *this)
{
  int v2; // edx
  unsigned int size; // r8d
  unsigned int v4; // edx
  unsigned int v5; // r8d
  __int64 v6; // rsi
  UFG::PreloadRequest *v7; // rdx
  unsigned int mNumTrafficCars; // r9d
  unsigned int mNumParkedCars; // edx
  unsigned int v10; // ecx
  unsigned int v11; // eax
  unsigned int v12; // ebp
  UFG::qSymbol *CurrentTrafficSet; // rax
  unsigned int mUID; // edx
  UFG::qPropertySet *PropertySet; // r12
  UFG::qPropertyList *v16; // r15
  unsigned int mNumElements; // r14d
  unsigned int v18; // edi
  int v19; // ebp
  UFG::qSymbol *v20; // rax
  UFG::qPropertySet *v21; // rax
  UFG::PreloadRequest *v22; // rax
  signed int v23; // eax
  __int64 v24; // rbp
  unsigned int v25; // r15d
  UFG::ObjectResourceManager::RareSpawnRecord *v26; // r14
  int v27; // ecx
  UFG::qArray<UFG::PreloadRequest *,0> *mPreloadBuckets; // r9
  unsigned int v29; // r8d
  UFG::PreloadRequest **p; // r9
  UFG::TrueCrowdSet *mSet; // r10
  UFG::PreloadRequest *v32; // rdx
  int v33; // ecx
  UFG::PreloadRequest *v34; // rdi
  UFG::qArray<UFG::PreloadRequest *,0> *v35; // r9
  __int64 v36; // rcx
  unsigned int v37; // edx
  UFG::PreloadRequest **v38; // r8
  UFG::qNode<UFG::PreloadRequest,UFG::PreloadRequest> *mPrev; // rax
  UFG::qNode<UFG::ObjectResourceManager::RareSpawnRecord,UFG::ObjectResourceManager::RareSpawnRecord> *v40; // rax
  unsigned int v41; // r8d
  __int64 v42; // rdx
  unsigned int v43; // eax
  signed int v44; // r14d
  __int64 v45; // rbp
  unsigned int v46; // r14d
  UFG::PreloadRequest **v47; // rcx
  UFG::PreloadRequest *v48; // rdi
  UFG::qNode<UFG::PreloadRequest,UFG::PreloadRequest> *v49; // rax
  UFG::qArray<UFG::PreloadRequest *,0> *v50; // r8
  unsigned int v51; // r9d
  __int64 v52; // rdx
  unsigned int v53; // eax
  UFG::qSymbol result; // [rsp+70h] [rbp+8h] BYREF
  UFG::qSymbol *p_result; // [rsp+78h] [rbp+10h]

  v2 = 0;
  size = this->mPool.mEntityStates.size;
  if ( size )
  {
    while ( this->mPool.mEntityStates.p[v2]->mEntityType != Vehicle )
    {
      if ( ++v2 >= size )
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
  if ( this->mPool.mPreloadBuckets[v4].size )
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
  if ( this->mEntityStates[1].mActive )
  {
    mNumTrafficCars = UFG::WheeledVehicleManager::m_Instance->mNumTrafficCars;
    mNumParkedCars = UFG::WheeledVehicleManager::m_Instance->mNumParkedCars;
    v10 = mNumTrafficCars < UFG::WheeledVehicleManager::mMaxTrafficCars
        ? UFG::WheeledVehicleManager::mMaxTrafficCars - mNumTrafficCars
        : 0;
    v11 = mNumParkedCars < UFG::WheeledVehicleManager::mMaxParkedCars
        ? UFG::WheeledVehicleManager::mMaxParkedCars - mNumParkedCars
        : 0;
    v12 = mNumTrafficCars + mNumParkedCars + v11 + v10;
    CurrentTrafficSet = UFG::WheeledVehicleManager::GetCurrentTrafficSet(
                          UFG::WheeledVehicleManager::m_Instance,
                          &result);
    mUID = CurrentTrafficSet->mUID;
    this->mCurrentSpawnset = (UFG::qSymbol)CurrentTrafficSet->mUID;
    if ( mUID != UFG::gNullQSymbol.mUID )
    {
      PropertySet = UFG::PropertySetManager::CreateOrFindPropertySet(&this->mCurrentSpawnset);
      v16 = UFG::qPropertySet::Get<UFG::qPropertyList>(
              PropertySet,
              (UFG::qArray<unsigned long,0> *)&qSymbol_SpawnSet,
              DEPTH_RECURSE);
      mNumElements = v16->mNumElements;
      v18 = 0;
      if ( mNumElements )
      {
        p_result = &result;
        v19 = v12 / mNumElements;
        do
        {
          v20 = UFG::qPropertyList::Get<UFG::qSymbol>(v16, v18);
          v21 = UFG::PropertySetManager::CreateOrFindPropertySet(v20);
          result.mUID = qSymbol_Low.mUID;
          v22 = UFG::ObjectResourceManager::RequestPreload(this, v21, (int *)&result, 0);
          v22->mDesiredInstanceCount += v19;
          ++v18;
        }
        while ( v18 < mNumElements );
      }
      UFG::ObjectResourceManager::UpdateRareSpawnResourcesFromPropertySet(this, Vehicle, PropertySet);
      UFG::ObjectResourceManager::UpdateAvailableVehicles(this);
    }
  }
  v23 = this->mRareSpawnList[1].size - 1;
  v24 = v23;
  if ( v23 >= 0 )
  {
    v25 = this->mRareSpawnList[1].size;
    do
    {
      v26 = this->mRareSpawnList[1].p[v24];
      v27 = 0;
      mPreloadBuckets = this->mPool.mPreloadBuckets;
      v29 = mPreloadBuckets->size;
      if ( mPreloadBuckets->size )
      {
        p = mPreloadBuckets->p;
        mSet = v26->mInstance.mSet;
        while ( 1 )
        {
          v32 = p[v27];
          if ( v32->mInstance.mSet == mSet )
            break;
          if ( ++v27 >= v29 )
            goto LABEL_51;
        }
        if ( !v32->mSpawnSetValid && !v32->mDirectRequestCount )
        {
          v33 = 0;
          while ( 1 )
          {
            v34 = p[v33];
            if ( v34->mInstance.mSet == mSet )
              break;
            if ( ++v33 >= v29 )
              goto LABEL_45;
          }
          v34->mSpawnSetValid = 0;
          if ( !v34->mDirectRequestCount )
          {
            UFG::ResourcePool::ReleaseResourceSetFiles(&this->mPool, v34);
            v35 = this->mPool.mPreloadBuckets;
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
              if ( (int)v36 >= 0 )
              {
                v38[v36] = v38[v37 - 1];
                if ( v35->size > 1 )
                  --v35->size;
                else
                  v35->size = 0;
              }
            }
LABEL_44:
            mPrev = this->mPool.mEmptyRequestList.mNode.mPrev;
            mPrev->mNext = v34;
            v34->mPrev = mPrev;
            v34->mNext = &this->mPool.mEmptyRequestList.mNode;
            this->mPool.mEmptyRequestList.mNode.mPrev = v34;
          }
LABEL_45:
          v40 = this->mEmptyRareSpawnList.mNode.mPrev;
          v40->mNext = v26;
          v26->mPrev = v40;
          v26->mNext = &this->mEmptyRareSpawnList.mNode;
          this->mEmptyRareSpawnList.mNode.mPrev = v26;
          v41 = v25;
          if ( v25 != this->mRareSpawnList[1].size )
          {
            v42 = 8 * v24 + 8;
            do
            {
              *(UFG::ObjectResourceManager::RareSpawnRecord **)((char *)this->mRareSpawnList[1].p + v42 - 8) = *(UFG::ObjectResourceManager::RareSpawnRecord **)((char *)this->mRareSpawnList[1].p + v42);
              ++v41;
              v42 += 8i64;
            }
            while ( v41 != this->mRareSpawnList[1].size );
          }
          v43 = this->mRareSpawnList[1].size;
          if ( v43 > 1 )
            this->mRareSpawnList[1].size = v43 - 1;
          else
            this->mRareSpawnList[1].size = 0;
        }
      }
LABEL_51:
      --v25;
      --v24;
    }
    while ( v24 >= 0 );
  }
  v44 = this->mPool.mPreloadBuckets[v6].size - 1;
  v45 = v44;
  if ( v44 >= 0 )
  {
    v46 = this->mPool.mPreloadBuckets[v6].size;
    do
    {
      v47 = this->mPool.mPreloadBuckets[v6].p;
      v48 = v47[v45];
      if ( !v48->mSpawnSetValid && !v48->mDirectRequestCount )
      {
        UFG::ResourcePool::ReleaseResourceSetFiles(&this->mPool, v47[v45]);
        *(_QWORD *)&v48->mDesiredInstanceCount = 0i64;
        v48->mVarietyRatio = 0.0;
        v49 = this->mPool.mEmptyRequestList.mNode.mPrev;
        v49->mNext = v48;
        v48->mPrev = v49;
        v48->mNext = &this->mPool.mEmptyRequestList.mNode;
        this->mPool.mEmptyRequestList.mNode.mPrev = v48;
        v50 = this->mPool.mPreloadBuckets;
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
  this->mPool.mDirty = 1;
}

// File Line: 874
// RVA: 0x43DDF0
UFG::qPropertySet *__fastcall UFG::ObjectResourceManager::GetRandomPropSetFromCurrentTrafficSet(
        UFG::ObjectResourceManager *this)
{
  UFG::qSymbol *p_mCurrentSpawnset; // rcx
  UFG::qPropertySet *PropertySet; // rax
  UFG::qPropertyList *v3; // rbx
  unsigned int RandomIndex; // eax
  UFG::qSymbol *v5; // rax

  p_mCurrentSpawnset = &this->mCurrentSpawnset;
  if ( p_mCurrentSpawnset->mUID == UFG::gNullQSymbol.mUID )
    return 0i64;
  PropertySet = UFG::PropertySetManager::CreateOrFindPropertySet(p_mCurrentSpawnset);
  v3 = UFG::qPropertySet::Get<UFG::qPropertyList>(
         PropertySet,
         (UFG::qArray<unsigned long,0> *)&qSymbol_SpawnSet,
         DEPTH_RECURSE);
  RandomIndex = UFG::qPropertyList::GetRandomIndex(v3);
  v5 = UFG::qPropertyList::Get<UFG::qSymbol>(v3, RandomIndex);
  return UFG::PropertySetManager::CreateOrFindPropertySet(v5);
}

// File Line: 893
// RVA: 0x444630
void __fastcall UFG::ObjectResourceManager::UnloadAmbientVehicles(UFG::ObjectResourceManager *this)
{
  UFG::ResourcePool::ReleaseAmbientPreloads(&this->mPool, Vehicle);
  this->mCurrentSpawnset = UFG::gNullQSymbol;
  UFG::ObjectResourceManager::ResetAllRarePreloadStatuses(this, Vehicle);
  UFG::ObjectResourceManager::RemoveAllUnwantedRareRequests(this, 1, 1);
  UFG::ObjectResourceManager::UpdateAvailableVehicles(this);
}

// File Line: 902
// RVA: 0x445850
void __fastcall UFG::ObjectResourceManager::UpdateAvailableVehicles(UFG::ObjectResourceManager *this)
{
  UFG::qArray<UFG::qReflectInventoryBase *,0> *p_mAmbientVehicles; // rsi
  unsigned int v3; // edi
  UFG::qSymbol *p_mCurrentSpawnset; // rcx
  UFG::qPropertySet *PropertySet; // rax
  UFG::qPropertyList *v6; // r13
  unsigned int mNumElements; // r12d
  UFG::qSymbol *v8; // rax
  UFG::qPropertySet *v9; // rax
  UFG::qPropertySet *v10; // rbp
  UFG::TrueCrowdSet *DataBase; // rax
  UFG::TrueCrowdSet *v12; // rax
  __int64 size; // r14
  unsigned int capacity; // edx
  unsigned int v15; // ebx
  unsigned int v16; // edx
  UFG::qReflectInventoryBase **p; // rax

  if ( this->mPool.mDirty )
  {
    p_mAmbientVehicles = (UFG::qArray<UFG::qReflectInventoryBase *,0> *)&this->mAmbientVehicles;
    v3 = 0;
    p_mCurrentSpawnset = &this->mCurrentSpawnset;
    p_mAmbientVehicles->size = 0;
    if ( p_mCurrentSpawnset->mUID != UFG::gNullQSymbol.mUID )
    {
      PropertySet = UFG::PropertySetManager::CreateOrFindPropertySet(p_mCurrentSpawnset);
      v6 = UFG::qPropertySet::Get<UFG::qPropertyList>(
             PropertySet,
             (UFG::qArray<unsigned long,0> *)&qSymbol_SpawnSet,
             DEPTH_RECURSE);
      mNumElements = v6->mNumElements;
      if ( mNumElements )
      {
        do
        {
          v8 = UFG::qPropertyList::Get<UFG::qSymbol>(v6, v3);
          v9 = UFG::PropertySetManager::CreateOrFindPropertySet(v8);
          v10 = v9;
          if ( v9 )
          {
            DataBase = (UFG::TrueCrowdSet *)UFG::TrueCrowdDataBase::QueryDataBase(
                                              UFG::TrueCrowdDataBase::sTrueCrowdDataBase,
                                              v9,
                                              0i64);
            if ( UFG::ResourcePool::CanSpawnAmbient(&this->mPool, DataBase, 1) )
            {
              v12 = (UFG::TrueCrowdSet *)UFG::TrueCrowdDataBase::QueryDataBase(
                                           UFG::TrueCrowdDataBase::sTrueCrowdDataBase,
                                           v10,
                                           0i64);
              if ( UFG::ResourcePool::CanSpawnAmbient(&this->mPool, v12, 1) )
              {
                size = p_mAmbientVehicles->size;
                capacity = p_mAmbientVehicles->capacity;
                v15 = size + 1;
                if ( (int)size + 1 > capacity )
                {
                  if ( capacity )
                    v16 = 2 * capacity;
                  else
                    v16 = 1;
                  for ( ; v16 < v15; v16 *= 2 )
                    ;
                  if ( v16 <= 2 )
                    v16 = 2;
                  if ( v16 - v15 > 0x10000 )
                    v16 = size + 65537;
                  UFG::qArray<UFG::CompositeDrawableComponent *,32>::Reallocate(p_mAmbientVehicles, v16, "qArray.Add");
                }
                p = p_mAmbientVehicles->p;
                p_mAmbientVehicles->size = v15;
                p[size] = (UFG::qReflectInventoryBase *)v10;
              }
            }
          }
          ++v3;
        }
        while ( v3 < mNumElements );
      }
    }
  }
}

// File Line: 930
// RVA: 0x43D150
UFG::qPropertySet *__fastcall UFG::ObjectResourceManager::GetAvailableDriver(
        UFG::ObjectResourceManager *this,
        UFG::qPropertyList *classPriorities,
        UFG::qPropertyList *classExclusions)
{
  unsigned int v3; // ebx
  UFG::qPropertyList *v5; // rax
  UFG::ObjectResourceManager *v6; // r13
  unsigned int v7; // r15d
  unsigned int v8; // edi
  UFG::TrueCrowdDataBase *v9; // rbp
  __int64 v10; // r14
  UFG::qPropertySet *v11; // rax
  char *MemImagePtr; // rax
  UFG::qPropertyList *v13; // rsi
  __int64 v14; // rcx
  UFG::qPropertyList *v15; // r11
  __int64 v16; // rcx
  UFG::qPropertyList *textureSetList; // r10
  __int64 v18; // rcx
  UFG::qPropertyList *overrides; // r9
  unsigned int mEntityCount; // ecx
  int v21; // r8d
  unsigned int v22; // edx
  UFG::TrueCrowdDefinition::Entity *mEntities; // rax
  UFG::TrueCrowdSet *CharacterDataBase; // rax
  __int64 v25; // rcx
  unsigned int v26; // edi
  UFG::qPropertySet **v27; // r14
  __int64 v28; // rbp
  UFG::qPropertySet *v29; // rsi
  __int64 v30; // rax
  UFG::qPropertySet **v32; // rsi
  __int64 v33; // r14
  UFG::qPropertySet *v34; // rbp
  __int64 v35; // rax
  UFG::qPropertySet *mDefaultDriver; // rdi
  UFG::TrueCrowdDataBase *v37; // rsi
  UFG::qPropertySet *v38; // rax
  char *v39; // rax
  UFG::qPropertyList *v40; // r11
  __int64 v41; // rcx
  UFG::qPropertyList *v42; // r10
  __int64 v43; // rcx
  UFG::qPropertyList *v44; // r9
  __int64 v45; // rcx
  UFG::qPropertyList *v46; // r8
  unsigned int v47; // ecx
  int v48; // edx
  UFG::TrueCrowdDefinition::Entity *v49; // rax
  UFG::TrueCrowdSet *v50; // rax
  __int64 v51[263]; // [rsp+40h] [rbp-838h] BYREF
  UFG::qPropertySet *property_set; // [rsp+898h] [rbp+20h]

  v3 = 0;
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
              property_set,
              (UFG::qArray<unsigned long,0> *)&component_StreamedResource::sPropertyName,
              DEPTH_RECURSE);
      if ( v11 )
        MemImagePtr = UFG::qPropertySet::GetMemImagePtr(v11);
      else
        MemImagePtr = 0i64;
      v13 = (UFG::qPropertyList *)&MemImagePtr[*(_QWORD *)MemImagePtr];
      if ( !*(_QWORD *)MemImagePtr )
        v13 = 0i64;
      v14 = *((_QWORD *)MemImagePtr + 2);
      if ( v14 )
        v15 = (UFG::qPropertyList *)&MemImagePtr[v14 + 16];
      else
        v15 = 0i64;
      v16 = *((_QWORD *)MemImagePtr + 3);
      if ( v16 )
        textureSetList = (UFG::qPropertyList *)&MemImagePtr[v16 + 24];
      else
        textureSetList = 0i64;
      v18 = *((_QWORD *)MemImagePtr + 1);
      if ( v18 )
        overrides = (UFG::qPropertyList *)&MemImagePtr[v18 + 8];
      else
        overrides = 0i64;
      mEntityCount = v9->mDefinition.mEntityCount;
      v21 = *((_DWORD *)MemImagePtr + 8);
      v22 = 0;
      if ( mEntityCount )
      {
        mEntities = v9->mDefinition.mEntities;
        while ( mEntities->mNameUID != v21 )
        {
          ++v22;
          ++mEntities;
          if ( v22 >= mEntityCount )
            goto LABEL_20;
        }
      }
      else
      {
LABEL_20:
        v22 = -1;
      }
      CharacterDataBase = (UFG::TrueCrowdSet *)UFG::TrueCrowdDataBase::QueryCharacterDataBase(
                                                 v9,
                                                 v22,
                                                 v13,
                                                 v15,
                                                 overrides,
                                                 textureSetList,
                                                 property_set);
      if ( CharacterDataBase && UFG::TrueCrowdSet::IsLoaded(CharacterDataBase) )
      {
        v25 = v7++;
        v51[v25] = (__int64)v6->mAvailableDrivers.p[v10];
      }
      ++v8;
    }
    while ( v8 < v6->mAvailableDrivers.size );
    v5 = classPriorities;
  }
  if ( v5 )
  {
    if ( v5->mNumElements )
    {
      v26 = 0;
      if ( v7 )
      {
        v27 = (UFG::qPropertySet **)v51;
        v28 = v7;
        do
        {
          v29 = *v27;
          if ( UFG::VehicleUtility::IsDriverTypeInList(*v27, classPriorities)
            && (!classExclusions || !UFG::VehicleUtility::IsDriverTypeInList(v29, classExclusions)) )
          {
            v30 = v26++;
            v51[v30 + 128] = (__int64)v29;
          }
          ++v27;
          --v28;
        }
        while ( v28 );
        v6 = this;
        if ( v26 )
          return (UFG::qPropertySet *)v51[(int)UFG::qRandom(v26, (unsigned int *)&UFG::qDefaultSeed) + 128];
      }
    }
  }
  if ( classExclusions )
  {
    if ( classExclusions->mNumElements )
    {
      v26 = 0;
      if ( v7 )
      {
        v32 = (UFG::qPropertySet **)v51;
        v33 = v7;
        do
        {
          v34 = *v32;
          if ( !UFG::VehicleUtility::IsDriverTypeInList(*v32, classExclusions) )
          {
            v35 = v26++;
            v51[v35 + 128] = (__int64)v34;
          }
          ++v32;
          --v33;
        }
        while ( v33 );
        if ( v26 )
          return (UFG::qPropertySet *)v51[(int)UFG::qRandom(v26, (unsigned int *)&UFG::qDefaultSeed) + 128];
      }
    }
  }
  mDefaultDriver = v6->mDefaultDriver;
  if ( mDefaultDriver )
  {
    v37 = UFG::TrueCrowdDataBase::sTrueCrowdDataBase;
    v38 = UFG::qPropertySet::Get<UFG::qPropertySet>(
            v6->mDefaultDriver,
            (UFG::qArray<unsigned long,0> *)&component_StreamedResource::sPropertyName,
            DEPTH_RECURSE);
    if ( v38 )
      v39 = UFG::qPropertySet::GetMemImagePtr(v38);
    else
      v39 = 0i64;
    v40 = (UFG::qPropertyList *)&v39[*(_QWORD *)v39];
    if ( !*(_QWORD *)v39 )
      v40 = 0i64;
    v41 = *((_QWORD *)v39 + 2);
    v42 = v41 ? (UFG::qPropertyList *)&v39[v41 + 16] : 0i64;
    v43 = *((_QWORD *)v39 + 3);
    v44 = v43 ? (UFG::qPropertyList *)&v39[v43 + 24] : 0i64;
    v45 = *((_QWORD *)v39 + 1);
    v46 = v45 ? (UFG::qPropertyList *)&v39[v45 + 8] : 0i64;
    v47 = v37->mDefinition.mEntityCount;
    v48 = *((_DWORD *)v39 + 8);
    if ( v47 )
    {
      v49 = v37->mDefinition.mEntities;
      while ( v49->mNameUID != v48 )
      {
        ++v3;
        ++v49;
        if ( v3 >= v47 )
          goto LABEL_64;
      }
    }
    else
    {
LABEL_64:
      v3 = -1;
    }
    v50 = (UFG::TrueCrowdSet *)UFG::TrueCrowdDataBase::QueryCharacterDataBase(
                                 v37,
                                 v3,
                                 v40,
                                 v42,
                                 v46,
                                 v44,
                                 mDefaultDriver);
    if ( v50 )
    {
      if ( UFG::TrueCrowdSet::IsLoaded(v50) )
        return v6->mDefaultDriver;
    }
  }
  if ( v7 )
    return (UFG::qPropertySet *)v51[(int)UFG::qRandom(v7, (unsigned int *)&UFG::qDefaultSeed)];
  return 0i64;
}

// File Line: 998
// RVA: 0x446EF0
void __fastcall UFG::ObjectResourceManager::UpdateRareSpawnResourcesFromPropertySet(
        UFG::ObjectResourceManager *this,
        UFG::TrueCrowdResource::EntityType type,
        UFG::qPropertySet *set)
{
  __int64 v3; // rbx
  UFG::qPropertyList *v5; // rax
  UFG::qPropertyList *v6; // r13
  unsigned int mNumElements; // r12d
  unsigned int v8; // r14d
  UFG::qArray<UFG::ObjectResourceManager::RareSpawnRecord *,0> *v9; // rsi
  char *ValuePtr; // rax
  UFG::qPropertySet *v11; // rdi
  UFG::qSymbol *v12; // rax
  __int64 v13; // rdx
  UFG::ObjectResourceManager::RareSpawnRecord *v14; // rcx
  UFG::allocator::free_link *v15; // rax
  UFG::ObjectResourceManager::RareSpawnRecord *v16; // rax
  UFG::ObjectResourceManager::RareSpawnRecord *mNext; // rbx
  UFG::qNode<UFG::ObjectResourceManager::RareSpawnRecord,UFG::ObjectResourceManager::RareSpawnRecord> *mPrev; // rcx
  UFG::qNode<UFG::ObjectResourceManager::RareSpawnRecord,UFG::ObjectResourceManager::RareSpawnRecord> *v19; // rax
  UFG::qArray<UFG::ResourceRequest *,0> *v20; // rsi
  __int64 p_low; // rbp
  unsigned int v22; // edi
  unsigned int p_high; // edx
  unsigned int v24; // edx
  UFG::qArray<UFG::ObjectResourceManager::RareSpawnRecord *,0> *v25; // [rsp+20h] [rbp-48h]
  __int64 v26; // [rsp+88h] [rbp+20h]

  v3 = type;
  v5 = UFG::qPropertySet::Get<UFG::qPropertyList>(
         set,
         (UFG::qArray<unsigned long,0> *)&qSymbol_RareSpawnList,
         DEPTH_RECURSE);
  v6 = v5;
  if ( v5 )
  {
    mNumElements = v5->mNumElements;
    v8 = 0;
    if ( mNumElements )
    {
      v26 = v3;
      v9 = &this->mRareSpawnList[v3];
      v25 = v9;
      do
      {
        ValuePtr = UFG::qPropertyList::GetValuePtr(v6, 0x1Au, v8);
        if ( ValuePtr && *(_QWORD *)ValuePtr )
          v11 = (UFG::qPropertySet *)&ValuePtr[*(_QWORD *)ValuePtr];
        else
          v11 = 0i64;
        v12 = UFG::qPropertySet::Get<UFG::qSymbol>(
                v11,
                (UFG::qArray<unsigned long,0> *)&qSymbol_PropertySet,
                DEPTH_RECURSE);
        v13 = 0i64;
        if ( !v9->size )
          goto LABEL_14;
        while ( 1 )
        {
          v14 = this->mRareSpawnList[v3].p[v13];
          if ( v14->mPropertySetName.mUID == v12->mUID )
            break;
          v13 = (unsigned int)(v13 + 1);
          if ( (unsigned int)v13 >= v9->size )
            goto LABEL_14;
        }
        if ( v14 )
        {
          UFG::ObjectResourceManager::RareSpawnRecord::Update(v14, v11);
        }
        else
        {
LABEL_14:
          if ( (UFG::qList<UFG::ObjectResourceManager::RareSpawnRecord,UFG::ObjectResourceManager::RareSpawnRecord,1,0> *)this->mEmptyRareSpawnList.mNode.mNext == &this->mEmptyRareSpawnList )
          {
            v15 = UFG::qMalloc(0x160ui64, UFG::gGlobalNewName, 0i64);
            if ( v15 )
            {
              UFG::ObjectResourceManager::RareSpawnRecord::RareSpawnRecord((UFG::ObjectResourceManager::RareSpawnRecord *)v15);
              mNext = v16;
            }
            else
            {
              mNext = 0i64;
            }
          }
          else
          {
            mNext = (UFG::ObjectResourceManager::RareSpawnRecord *)this->mEmptyRareSpawnList.mNode.mNext;
            mPrev = mNext->mPrev;
            v19 = mNext->mNext;
            mPrev->mNext = v19;
            v19->mPrev = mPrev;
            mNext->mPrev = mNext;
            mNext->mNext = mNext;
          }
          UFG::ObjectResourceManager::RareSpawnRecord::Init(mNext, v11);
          v20 = &this->mPool.mQueued + (int)(*mNext->mInstance.mSet->mFiles[0].p)->mType.mValue;
          p_low = LODWORD(v20[28].p);
          v22 = p_low + 1;
          p_high = HIDWORD(v20[28].p);
          if ( (int)p_low + 1 > p_high )
          {
            if ( p_high )
              v24 = 2 * p_high;
            else
              v24 = 1;
            for ( ; v24 < v22; v24 *= 2 )
              ;
            if ( v24 <= 2 )
              v24 = 2;
            if ( v24 - v22 > 0x10000 )
              v24 = p_low + 65537;
            UFG::qArray<UFG::CompositeDrawableComponent *,32>::Reallocate(
              (UFG::qArray<UFG::qReflectInventoryBase *,0> *)&v20[28].p,
              v24,
              "qArray.Add");
          }
          LODWORD(v20[28].p) = v22;
          *(_QWORD *)(*(_QWORD *)&v20[29].size + 8 * p_low) = mNext;
          v3 = v26;
          v9 = v25;
        }
        ++v8;
      }
      while ( v8 < mNumElements );
    }
  }
}

// File Line: 1032
// RVA: 0x446C90
void __fastcall UFG::ObjectResourceManager::UpdateRareRequests(UFG::ObjectResourceManager *this)
{
  UFG::qSymbol **p_p; // rdi
  __int64 v3; // r15
  __int64 j; // rbp
  unsigned int v5; // r8d
  UFG::qSymbol *v6; // r14
  __int64 v7; // rdx
  __int64 v8; // rcx
  unsigned int v9; // r9d
  UFG::ObjectResourceManager::RareSpawnRecord **v10; // r10
  UFG::ObjectResourceManager::RareSpawnRecord **v11; // rdx
  unsigned int v12; // r9d
  __int64 v13; // rdx
  __int64 v14; // rax
  unsigned int v15; // r8d
  UFG::ObjectResourceManager::RareSpawnRecord **v16; // rbx
  UFG::ObjectResourceManager::RareSpawnRecord **v17; // rdx
  UFG::ObjectResourceManager::RareSpawnRecord *v18; // rdx
  UFG::ObjectResourceManager::RareSpawnRecord *v19; // rbx
  UFG::PreloadRequest *v20; // rax
  __int64 i; // rbx
  unsigned int mUID; // r8d
  __int64 v23; // rdx
  __int64 v24; // rcx
  unsigned int size; // r9d
  UFG::ObjectResourceManager::RareSpawnRecord **p; // r10
  UFG::ObjectResourceManager::RareSpawnRecord **v27; // rdx
  UFG::ObjectResourceManager::RareSpawnRecord *v28; // rdx
  UFG::qSymbol result; // [rsp+48h] [rbp+10h] BYREF

  p_p = &this->mEntityStates[0].mRareSpawnPropertySets.p;
  v3 = 3i64;
  do
  {
    if ( !*((_BYTE *)p_p - 43) || NISManager::GetInstance()->mState )
    {
      for ( i = 0i64; (unsigned int)i < *((_DWORD *)p_p - 2); i = (unsigned int)(i + 1) )
      {
        mUID = (*p_p)[i].mUID;
        if ( mUID != UFG::gNullQSymbol.mUID )
        {
          v23 = *((int *)p_p - 12);
          v24 = 0i64;
          size = this->mRareSpawnList[v23].size;
          if ( size )
          {
            p = this->mRareSpawnList[v23].p;
            v27 = p;
            while ( (*v27)->mPropertySetName.mUID != mUID )
            {
              v24 = (unsigned int)(v24 + 1);
              ++v27;
              if ( (unsigned int)v24 >= size )
                goto LABEL_32;
            }
            v28 = p[v24];
            if ( v28 )
              UFG::ResourcePool::ReleasePreload(&this->mPool, v28->mInstance.mSet, 0, 0);
          }
LABEL_32:
          (*p_p)[i] = UFG::gNullQSymbol;
          *((_BYTE *)&p_p[2]->mUID + i) = 0;
        }
      }
    }
    else
    {
      for ( j = 0i64; (unsigned int)j < *((_DWORD *)p_p - 2); j = (unsigned int)(j + 1) )
      {
        v5 = (*p_p)[j].mUID;
        if ( v5 == UFG::gNullQSymbol.mUID )
          goto LABEL_10;
        v7 = *((int *)p_p - 12);
        v8 = 0i64;
        v9 = this->mRareSpawnList[v7].size;
        if ( !v9 )
          goto LABEL_10;
        v10 = this->mRareSpawnList[v7].p;
        v11 = v10;
        while ( (*v11)->mPropertySetName.mUID != v5 )
        {
          v8 = (unsigned int)(v8 + 1);
          ++v11;
          if ( (unsigned int)v8 >= v9 )
            goto LABEL_10;
        }
        v18 = v10[v8];
        if ( v18 )
        {
          v18->mLastTimeAssetLoaded = UFG::Metrics::msInstance.mSimTimeMSec;
          if ( v18->mTotalNumInstancesSpawned >= v18->mMaxSpawnsBeforeCycles )
          {
            (*p_p)[j] = UFG::gNullQSymbol;
            *((_BYTE *)&p_p[2]->mUID + j) = 0;
            UFG::ResourcePool::ReleasePreload(&this->mPool, v18->mInstance.mSet, 0, 0);
          }
        }
        else
        {
LABEL_10:
          v6 = &(*p_p)[j];
          v6->mUID = UFG::ObjectResourceManager::ChooseNewRareRequest(
                       this,
                       &result,
                       (UFG::TrueCrowdResource::EntityType)*((_DWORD *)p_p - 12))->mUID;
          v12 = (*p_p)[j].mUID;
          if ( v12 != UFG::gNullQSymbol.mUID )
          {
            v13 = *((int *)p_p - 12);
            v14 = 0i64;
            v15 = this->mRareSpawnList[v13].size;
            if ( v15 )
            {
              v16 = this->mRareSpawnList[v13].p;
              v17 = v16;
              while ( (*v17)->mPropertySetName.mUID != v12 )
              {
                v14 = (unsigned int)(v14 + 1);
                ++v17;
                if ( (unsigned int)v14 >= v15 )
                  goto LABEL_21;
              }
              v19 = v16[v14];
              if ( v19 )
              {
                v20 = UFG::ResourcePool::RequestPreload(&this->mPool, &v19->mInstance, 0, 0);
                UFG::ResourcePool::PreloadInstance(&this->mPool, v20, &v19->mInstance);
              }
            }
          }
        }
LABEL_21:
        ;
      }
    }
    p_p += 9;
    --v3;
  }
  while ( v3 );
}

// File Line: 1092
// RVA: 0x43A030
UFG::qSymbol *__fastcall UFG::ObjectResourceManager::ChooseNewRareRequest(
        UFG::ObjectResourceManager *this,
        UFG::qSymbol *result,
        UFG::TrueCrowdResource::EntityType type)
{
  unsigned int v3; // r10d
  unsigned int v6; // r9d
  __int64 v7; // rdx
  unsigned int size; // r8d
  unsigned __int64 mSimTimeMSec; // r14
  char *v10; // r15
  __int64 v11; // rbp
  UFG::ObjectResourceManager::RareSpawnRecord **p; // r11
  __int64 v13; // rbx
  __int64 v14; // rcx
  char v15; // al
  _DWORD *v16; // rdx
  __int64 v17; // r8
  unsigned __int64 v20; // rdx
  unsigned __int64 v21; // rax
  __int64 v22; // rax
  __int64 v23; // rbx
  UFG::ResourcePriorityBucket *mLowBucket; // rcx
  unsigned __int64 v25; // rax
  unsigned int mUID; // eax
  __int64 v27[32]; // [rsp+20h] [rbp-128h]

  v3 = -1;
  if ( this->mEntityStates[0].mEntityType == type )
    v3 = 0;
  if ( this->mEntityStates[1].mEntityType == type )
    v3 = 1;
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
  v7 = type;
  size = this->mRareSpawnList[type].size;
  if ( !size )
    goto LABEL_36;
  mSimTimeMSec = UFG::Metrics::msInstance.mSimTimeMSec;
  v10 = (char *)this + 72 * v3;
  v11 = *((unsigned int *)v10 + 58);
  p = this->mRareSpawnList[v7].p;
  v13 = size;
  do
  {
    v14 = (__int64)*p;
    v15 = 0;
    if ( !(_DWORD)v11 )
      goto LABEL_15;
    v16 = (_DWORD *)*((_QWORD *)v10 + 30);
    v17 = v11;
    do
    {
      if ( *v16++ == *(_DWORD *)(v14 + 16) )
        v15 = 1;
      --v17;
    }
    while ( v17 );
    if ( !v15 )
    {
LABEL_15:
      if ( mSimTimeMSec - *(_QWORD *)(v14 + 56) >= *(_QWORD *)(v14 + 40) )
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
            v27[0] = (__int64)*p;
            v6 = 1;
          }
        }
        else
        {
          v27[0] = (__int64)*p;
          v6 = 1;
        }
      }
    }
    ++p;
    --v13;
  }
  while ( v13 );
  if ( v6
    && ((v23 = v27[(unsigned int)UFG::qRandom(v6, (unsigned int *)&UFG::qDefaultSeed)],
         qSymbol_Reserved.mUID != qSymbol_Critical.mUID)
      ? (qSymbol_Reserved.mUID != qSymbol_High.mUID
       ? (qSymbol_Reserved.mUID == qSymbol_Medium.mUID || qSymbol_Reserved.mUID == qSymbol_Low.mUID
        ? (mLowBucket = this->mPool.mLowBucket)
        : (mLowBucket = this->mPool.mReservedBucket))
       : (mLowBucket = this->mPool.mHighBucket))
      : (mLowBucket = this->mPool.mCriticalBucket),
        UFG::ResourcePriorityBucket::WillFitWithinSizeConstraints(mLowBucket, (UFG::TrueCrowdSet::Instance *)(v23 + 72))) )
  {
    v25 = UFG::Metrics::msInstance.mSimTimeMSec;
    *(_DWORD *)(v23 + 28) = 0;
    *(_QWORD *)(v23 + 48) = v25;
    mUID = *(_DWORD *)(v23 + 16);
  }
  else
  {
LABEL_36:
    mUID = UFG::gNullQSymbol.mUID;
  }
  result->mUID = mUID;
  return result;
}

// File Line: 1176
// RVA: 0x446B60
void __fastcall UFG::ObjectResourceManager::UpdateRareObjectAvailability(UFG::ObjectResourceManager *this)
{
  UFG::qArray<UFG::qSymbol,0> *p_mRareSpawnPropertySets; // rbx
  __int64 v3; // r14
  unsigned int i; // edi
  unsigned int mUID; // r8d
  __int64 p_low; // rdx
  unsigned int v7; // eax
  unsigned int size; // r9d
  UFG::ObjectResourceManager::RareSpawnRecord **p; // r10
  UFG::ObjectResourceManager::RareSpawnRecord **v10; // rdx
  UFG::ObjectResourceManager::RareSpawnRecord *v11; // rdx
  bool v12; // cl
  UFG::TrueCrowdSet *mSet; // rcx

  p_mRareSpawnPropertySets = &this->mEntityStates[0].mRareSpawnPropertySets;
  v3 = 3i64;
  do
  {
    for ( i = 0; i < p_mRareSpawnPropertySets->size; ++i )
    {
      mUID = p_mRareSpawnPropertySets->p[i].mUID;
      if ( mUID == UFG::gNullQSymbol.mUID )
      {
        *((_BYTE *)&p_mRareSpawnPropertySets[1].p->mUID + i) = 0;
      }
      else
      {
        p_low = SLODWORD(p_mRareSpawnPropertySets[-3].p);
        v7 = 0;
        size = this->mRareSpawnList[p_low].size;
        if ( size )
        {
          p = this->mRareSpawnList[p_low].p;
          v10 = p;
          while ( (*v10)->mPropertySetName.mUID != mUID )
          {
            ++v7;
            ++v10;
            if ( v7 >= size )
              goto LABEL_9;
          }
          v11 = p[v7];
        }
        else
        {
LABEL_9:
          v11 = 0i64;
        }
        if ( v11->mTotalNumInstancesSpawned < v11->mMaxSpawnsBeforeCycles )
        {
          if ( UFG::Metrics::msInstance.mSimTimeMSec - v11->mLastTimeAssetSpawned >= v11->mMinTimeBetweenSpawns )
          {
            mSet = v11->mInstance.mSet;
            v12 = (signed int)mSet->mCurrentInstances < v11->mMaxConcurrentInstances
               && UFG::TrueCrowdSet::IsLoaded(mSet) != 0;
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
        *((_BYTE *)&p_mRareSpawnPropertySets[1].p->mUID + i) = v12;
      }
    }
    p_mRareSpawnPropertySets = (UFG::qArray<UFG::qSymbol,0> *)((char *)p_mRareSpawnPropertySets + 72);
    --v3;
  }
  while ( v3 );
}

// File Line: 1214
// RVA: 0x442CB0
void __fastcall UFG::ObjectResourceManager::ResetAllRarePreloadStatuses(
        UFG::ObjectResourceManager *this,
        UFG::TrueCrowdResource::EntityType type)
{
  __int64 i; // r9
  unsigned int v4; // ecx
  UFG::qArray<UFG::PreloadRequest *,0> *mPreloadBuckets; // rax
  unsigned int size; // r8d
  UFG::PreloadRequest **p; // rax

  for ( i = 0i64; (unsigned int)i < this->mRareSpawnList[type].size; i = (unsigned int)(i + 1) )
  {
    v4 = 0;
    mPreloadBuckets = this->mPool.mPreloadBuckets;
    size = mPreloadBuckets->size;
    if ( mPreloadBuckets->size )
    {
      p = mPreloadBuckets->p;
      while ( (*p)->mInstance.mSet != this->mRareSpawnList[type].p[i]->mInstance.mSet )
      {
        ++v4;
        ++p;
        if ( v4 >= size )
          goto LABEL_8;
      }
      (*p)->mSpawnSetValid = 0;
    }
LABEL_8:
    ;
  }
}

// File Line: 1240
// RVA: 0x441FD0
void __fastcall UFG::ObjectResourceManager::RemoveAllUnwantedRareRequests(
        UFG::ObjectResourceManager *this,
        int type,
        bool forceUnload)
{
  UFG::qArray<UFG::ObjectResourceManager::RareSpawnRecord *,0> *v5; // rbx
  __int64 v6; // rsi
  unsigned int size; // ebp
  __int64 v8; // r12
  unsigned int v9; // ecx
  __int64 v10; // rdi
  UFG::qArray<UFG::PreloadRequest *,0> *mPreloadBuckets; // rax
  unsigned int v12; // r8d
  UFG::PreloadRequest **p; // rax
  UFG::PreloadRequest *v14; // rdx
  unsigned int v15; // r8d
  UFG::qNode<UFG::ObjectResourceManager::RareSpawnRecord,UFG::ObjectResourceManager::RareSpawnRecord> *mPrev; // rax
  __int64 v17; // rax

  v5 = &this->mRareSpawnList[type];
  v6 = v5->size - 1;
  if ( (signed int)(v5->size - 1) >= 0 )
  {
    size = v5->size;
    v8 = 2 * (type + 29i64);
    do
    {
      v9 = 0;
      v10 = *(_QWORD *)(*((_QWORD *)&this->mPool.mQueued.size + v8) + 8 * v6);
      mPreloadBuckets = this->mPool.mPreloadBuckets;
      v12 = mPreloadBuckets->size;
      if ( mPreloadBuckets->size )
      {
        p = mPreloadBuckets->p;
        while ( 1 )
        {
          v14 = *p;
          if ( (*p)->mInstance.mSet == *(UFG::TrueCrowdSet **)(v10 + 72) )
            break;
          ++v9;
          ++p;
          if ( v9 >= v12 )
            goto LABEL_17;
        }
        if ( !v14->mSpawnSetValid && !v14->mDirectRequestCount || forceUnload )
        {
          UFG::ResourcePool::ReleasePreload(&this->mPool, *(UFG::TrueCrowdSet **)(v10 + 72), 0, 0);
          v15 = size;
          mPrev = this->mEmptyRareSpawnList.mNode.mPrev;
          mPrev->mNext = (UFG::qNode<UFG::ObjectResourceManager::RareSpawnRecord,UFG::ObjectResourceManager::RareSpawnRecord> *)v10;
          *(_QWORD *)v10 = mPrev;
          *(_QWORD *)(v10 + 8) = &this->mEmptyRareSpawnList;
          this->mEmptyRareSpawnList.mNode.mPrev = (UFG::qNode<UFG::ObjectResourceManager::RareSpawnRecord,UFG::ObjectResourceManager::RareSpawnRecord> *)v10;
          if ( size != v5->size )
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
      --size;
      --v6;
    }
    while ( v6 >= 0 );
  }
}

