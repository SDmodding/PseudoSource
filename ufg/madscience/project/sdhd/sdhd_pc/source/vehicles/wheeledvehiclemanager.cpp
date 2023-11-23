// File Line: 172
// RVA: 0x1573850
__int64 dynamic_initializer_for__UFG::WheeledVehicleManager::mBaseMaxTrafficCars__()
{
  __int64 result; // rax

  result = UFG::WheeledVehicleManager::mDefaultMaxTrafficCars;
  UFG::WheeledVehicleManager::mBaseMaxTrafficCars = UFG::WheeledVehicleManager::mDefaultMaxTrafficCars;
  return result;
}

// File Line: 174
// RVA: 0x1573880
__int64 dynamic_initializer_for__UFG::WheeledVehicleManager::mMaxTrafficCars__()
{
  float v0; // xmm0_4
  __int64 result; // rax

  v0 = (float)(int)UFG::WheeledVehicleManager::mBaseMaxTrafficCars * UFG::WheeledVehicleManager::mMaxTrafficCarsScale;
  result = (unsigned int)(int)v0;
  UFG::WheeledVehicleManager::mMaxTrafficCars = (int)v0;
  return result;
}

// File Line: 177
// RVA: 0x1573870
__int64 dynamic_initializer_for__UFG::WheeledVehicleManager::mMaxParkedCars__()
{
  __int64 result; // rax

  result = UFG::WheeledVehicleManager::mDefaultMaxParkedCars;
  UFG::WheeledVehicleManager::mMaxParkedCars = UFG::WheeledVehicleManager::mDefaultMaxParkedCars;
  return result;
}

// File Line: 182
// RVA: 0x1573900
void dynamic_initializer_for__UFG::WheeledVehicleManager::mSpawnPointExpectedCarsMaxTime__()
{
  UFG::WheeledVehicleManager::mSpawnPointExpectedCarsMaxTime = UFG::TrafficSettings::mMinSpawnTime;
}

// File Line: 203
// RVA: 0x6433A0
void __fastcall UFG::WheeledVehicleManager::WheeledVehicleManager(UFG::WheeledVehicleManager *this)
{
  UFG::SensorPhantom *v2; // rdi
  UFG::qSafePointer<UFG::SimComponent,UFG::TrafficRegion> *p_mCurrentTrafficRegion; // rsi
  UFG::qArray<UFG::WheeledVehicleManager::RoadSpawningRecord,0> *p_mSpawningRecordCollection; // r14
  UFG::qArray<UFG::WheeledVehicleManager::RoadSpawningRecord,0> *p_mParkingSpawningRecordCollection; // r15
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::allocator::free_link *v8; // rax
  UFG::WheeledVehicleNavigationData *v9; // rax
  UFG::allocator::free_link *v10; // rax
  UFG::RoadNetworkVisibleArea *v11; // rax
  UFG::allocator::free_link *v12; // rax
  UFG::TrueDirectionManager *v13; // rax
  UFG::qArray<UFG::qSymbol,0> *v14; // rax
  unsigned int size; // ecx
  int v16; // eax
  unsigned int v17; // esi
  unsigned int capacity; // edx
  unsigned int v19; // edx
  unsigned int v20; // eax
  unsigned int v21; // eax
  int v22; // ebp
  unsigned int v23; // esi
  unsigned int v24; // edx
  unsigned int v25; // edx
  unsigned int v26; // ebp
  unsigned __int64 v27; // rax
  UFG::allocator::free_link *v28; // rax
  UFG::qPropertySet **v29; // rsi
  unsigned int i; // r9d
  UFG::allocator::free_link *v31; // rax
  UFG::SensorPhantom *v32; // rax
  hkAabb aabb; // [rsp+40h] [rbp-48h] BYREF

  v2 = 0i64;
  this->m_TrueDirectionManager = 0i64;
  this->m_ReinitializeQueued = 0;
  this->m_SecondsQueued = 0.0;
  p_mCurrentTrafficRegion = &this->mCurrentTrafficRegion;
  this->mCurrentTrafficRegion.mPrev = &this->mCurrentTrafficRegion;
  this->mCurrentTrafficRegion.mNext = &this->mCurrentTrafficRegion;
  this->mCurrentTrafficRegion.m_pPointer = 0i64;
  this->m_TrafficSetOverride = UFG::gNullQSymbol;
  this->m_SimObject = 0i64;
  `eh vector constructor iterator(
    this->mCarsWithDeletionPending,
    0x18ui64,
    100,
    (void (__fastcall *)(void *))UFG::qSafePointer<UFG::SimObject,UFG::SimObjectCharacter>::qSafePointer<UFG::SimObject,UFG::SimObjectCharacter>);
  *(_QWORD *)&this->mTotalNumParkedCarsCreated = 0i64;
  `eh vector constructor iterator(
    this->mParkedCar,
    0x40ui64,
    100,
    (void (__fastcall *)(void *))UFG::qSafePointerWithCallbacks<UFG::SimObject,UFG::SimObjectVehicle>::qSafePointerWithCallbacks<UFG::SimObject,UFG::SimObjectVehicle>);
  *(_QWORD *)&this->mTotalNumTrafficCarsCreated = 0i64;
  `eh vector constructor iterator(
    this->mTrafficCar,
    0x40ui64,
    100,
    (void (__fastcall *)(void *))UFG::qSafePointerWithCallbacks<UFG::SimObject,UFG::SimObjectVehicle>::qSafePointerWithCallbacks<UFG::SimObject,UFG::SimObjectVehicle>);
  p_mSpawningRecordCollection = &this->mSpawningRecordCollection;
  this->mSpawningRecordCollection.p = 0i64;
  *(_QWORD *)&this->mSpawningRecordCollection.size = 0i64;
  p_mParkingSpawningRecordCollection = &this->mParkingSpawningRecordCollection;
  this->mParkingSpawningRecordCollection.p = 0i64;
  *(_QWORD *)&this->mParkingSpawningRecordCollection.size = 0i64;
  this->mSpawningLaneTendency = Random;
  this->mPercentageSpawningInFavouredLane = 1.0;
  this->mSpawnPointExpectedCarsTimer = UFG::WheeledVehicleManager::mSpawnPointExpectedCarsMaxTime;
  *(_QWORD *)&this->mCurrentSpawnIndex = 0i64;
  this->mSpawningSelectionArray.p = 0i64;
  this->mSpawningSelectionArray.capacity = 0;
  *(_WORD *)&this->m_PlaceTransitVehiclePending = 0;
  this->m_PlaceTransitVehicleFrames = 0;
  this->m_TrueDirectionUpdateEnabled = 1;
  if ( p_mCurrentTrafficRegion->m_pPointer )
  {
    mPrev = p_mCurrentTrafficRegion->mPrev;
    mNext = p_mCurrentTrafficRegion->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_mCurrentTrafficRegion->mPrev = p_mCurrentTrafficRegion;
    p_mCurrentTrafficRegion->mNext = p_mCurrentTrafficRegion;
  }
  p_mCurrentTrafficRegion->m_pPointer = 0i64;
  v8 = UFG::qMalloc(0x118ui64, "WheeledVehicleNavigationData", 0i64);
  if ( v8 )
    UFG::WheeledVehicleNavigationData::WheeledVehicleNavigationData((UFG::WheeledVehicleNavigationData *)v8);
  else
    v9 = 0i64;
  this->m_NavigationData = v9;
  v10 = UFG::qMalloc(0x178ui64, "RoadNetworkVisibleArea", 0i64);
  if ( v10 )
    UFG::RoadNetworkVisibleArea::RoadNetworkVisibleArea((UFG::RoadNetworkVisibleArea *)v10);
  else
    v11 = 0i64;
  this->m_VisibleArea = v11;
  v12 = UFG::qMalloc(0x40ui64, "TrueDirectionManager", 0i64);
  if ( v12 )
    UFG::TrueDirectionManager::TrueDirectionManager((UFG::TrueDirectionManager *)v12);
  else
    v13 = 0i64;
  this->m_TrueDirectionManager = v13;
  v14 = (UFG::qArray<UFG::qSymbol,0> *)UFG::qMalloc(0x10ui64, "RoadPropertyNameData", 0i64);
  if ( v14 )
  {
    v14->p = 0i64;
    *(_QWORD *)&v14->size = 0i64;
  }
  else
  {
    v14 = 0i64;
  }
  this->m_RoadPropertyCollection = v14;
  size = p_mSpawningRecordCollection->size;
  v16 = 100 - p_mSpawningRecordCollection->size;
  if ( v16 <= 0 )
  {
    v20 = p_mSpawningRecordCollection->size - 100;
    if ( p_mSpawningRecordCollection->size != 100 )
    {
      if ( v20 < size )
        p_mSpawningRecordCollection->size = size - v20;
      else
        p_mSpawningRecordCollection->size = 0;
    }
  }
  else
  {
    v17 = size + v16;
    capacity = this->mSpawningRecordCollection.capacity;
    if ( size + v16 > capacity )
    {
      if ( capacity )
        v19 = 2 * capacity;
      else
        v19 = 1;
      for ( ; v19 < v17; v19 *= 2 )
        ;
      if ( v19 - v17 > 0x10000 )
        v19 = v17 + 0x10000;
      UFG::qArray<UFG::WheeledVehicleManager::RoadSpawningRecord,0>::Reallocate(
        &this->mSpawningRecordCollection,
        v19,
        "mSpawningRecordCollection");
    }
    p_mSpawningRecordCollection->size = v17;
  }
  v21 = p_mParkingSpawningRecordCollection->size;
  v22 = 100 - p_mParkingSpawningRecordCollection->size;
  if ( v22 <= 0 )
  {
    v26 = p_mParkingSpawningRecordCollection->size - 100;
    if ( p_mParkingSpawningRecordCollection->size != 100 )
    {
      if ( v26 < v21 )
        p_mParkingSpawningRecordCollection->size = v21 - v26;
      else
        p_mParkingSpawningRecordCollection->size = 0;
    }
  }
  else
  {
    v23 = v21 + v22;
    v24 = this->mParkingSpawningRecordCollection.capacity;
    if ( v21 + v22 > v24 )
    {
      if ( v24 )
        v25 = 2 * v24;
      else
        v25 = 1;
      for ( ; v25 < v23; v25 *= 2 )
        ;
      if ( v25 - v23 > 0x10000 )
        v25 = v23 + 0x10000;
      UFG::qArray<UFG::WheeledVehicleManager::RoadSpawningRecord,0>::Reallocate(
        &this->mParkingSpawningRecordCollection,
        v25,
        "mParkingSpawningRecordCollection");
    }
    p_mParkingSpawningRecordCollection->size = v23;
  }
  if ( this->mSpawningSelectionArray.capacity < 0xA && this->mSpawningSelectionArray.size != 10 )
  {
    v27 = 80i64;
    if ( !is_mul_ok(0xAui64, 8ui64) )
      v27 = -1i64;
    v28 = UFG::qMalloc(v27, "WheeledVehicleManager", 0i64);
    v29 = (UFG::qPropertySet **)v28;
    if ( this->mSpawningSelectionArray.p )
    {
      for ( i = 0; i < this->mSpawningSelectionArray.size; ++i )
        v28[i] = (UFG::allocator::free_link)this->mSpawningSelectionArray.p[i];
      operator delete[](this->mSpawningSelectionArray.p);
    }
    this->mSpawningSelectionArray.p = v29;
    this->mSpawningSelectionArray.capacity = 10;
  }
  aabb.m_min = (hkVector4f)_xmm;
  aabb.m_max = (hkVector4f)_xmm;
  v31 = UFG::qMemoryPool::Allocate(&gPhysicsMemoryPool, 0x18ui64, "SpawnSensor", 0i64, 1u);
  if ( v31 )
  {
    UFG::SensorPhantom::SensorPhantom((UFG::SensorPhantom *)v31, &aabb, 0x18u, "VehicleSpawnSensor");
    v2 = v32;
  }
  this->mSpawnSensor = v2;
}

// File Line: 241
// RVA: 0x658210
void __fastcall UFG::WheeledVehicleManager::ResetTrafficSystem(UFG::WheeledVehicleManager *this)
{
  UFG::WheeledVehicleManager::mBaseMaxTrafficCars = UFG::WheeledVehicleManager::mDefaultMaxTrafficCars;
  UFG::WheeledVehicleManager::m_TrafficSystemLocked = 0;
  UFG::WheeledVehicleManager::mMaxTrafficCarsScale = 1.0;
  UFG::WheeledVehicleManager::mMaxTrafficCars = (int)(float)(int)UFG::WheeledVehicleManager::mDefaultMaxTrafficCars;
  UFG::WheeledVehicleManager::mMaxParkedCars = UFG::WheeledVehicleManager::mDefaultMaxParkedCars;
  UFG::WheeledVehicleManager::SetTrafficDensityScale(1.0);
  this->m_TrafficSetOverride = UFG::gNullQSymbol;
  if ( UFG::ObjectResourceManager::Instance()->mAmbientVehicles.size <= 2 )
  {
    this->m_ReinitializeQueued = 1;
  }
  else
  {
    UFG::RoadNetworkVisibleArea::Reinitialize(this->m_VisibleArea);
    this->m_ReinitializeQueued = 0;
    this->mCurrentSpawnIndex = 0;
  }
  this->m_SecondsQueued = 0.0;
}

// File Line: 252
// RVA: 0x6599A0
void __fastcall UFG::WheeledVehicleManager::SetTrafficDensityScale(float scaleFactor)
{
  bool v1; // cl
  bool v2; // al

  v1 = scaleFactor >= 0.0 && scaleFactor <= 1.0;
  v2 = UFG::WheeledVehicleManager::mMaxTrafficCarsScale == scaleFactor
    && UFG::WheeledVehicleManager::mRoadDensityScale == scaleFactor;
  if ( v1 && !v2 )
  {
    UFG::WheeledVehicleManager::mMaxTrafficCarsScale = scaleFactor;
    UFG::WheeledVehicleManager::mRoadDensityScale = scaleFactor;
    UFG::WheeledVehicleManager::mMaxTrafficCars = (int)(float)((float)(int)UFG::WheeledVehicleManager::mBaseMaxTrafficCars
                                                             * scaleFactor);
  }
}

// File Line: 265
// RVA: 0x6595D0
void __fastcall UFG::WheeledVehicleManager::SetMaxTrafficCars(int maxNumCars)
{
  if ( maxNumCars <= UFG::WheeledVehicleManager::mDefaultMaxTrafficCars )
  {
    UFG::WheeledVehicleManager::mBaseMaxTrafficCars = maxNumCars;
    UFG::WheeledVehicleManager::mMaxTrafficCars = (int)(float)((float)maxNumCars
                                                             * UFG::WheeledVehicleManager::mMaxTrafficCarsScale);
  }
}

// File Line: 281
// RVA: 0x6581E0
void UFG::WheeledVehicleManager::ResetMaxTrafficCars(void)
{
  LODWORD(UFG::WheeledVehicleManager::mMaxTrafficCarsScale) = (_DWORD)FLOAT_1_0;
  UFG::WheeledVehicleManager::mBaseMaxTrafficCars = UFG::WheeledVehicleManager::mDefaultMaxTrafficCars;
  UFG::WheeledVehicleManager::mMaxTrafficCars = (int)(float)(int)UFG::WheeledVehicleManager::mDefaultMaxTrafficCars;
}

// File Line: 288
// RVA: 0x6595B0
void __fastcall UFG::WheeledVehicleManager::SetMaxParkedCars(unsigned int maxNumCars)
{
  unsigned int v1; // eax

  v1 = UFG::WheeledVehicleManager::mMaxParkedCars;
  if ( maxNumCars <= UFG::WheeledVehicleManager::mDefaultMaxParkedCars )
    v1 = maxNumCars;
  UFG::WheeledVehicleManager::mMaxParkedCars = v1;
}

// File Line: 296
// RVA: 0x6581D0
void UFG::WheeledVehicleManager::ResetMaxParkedCars(void)
{
  UFG::WheeledVehicleManager::mMaxParkedCars = UFG::WheeledVehicleManager::mDefaultMaxParkedCars;
}

// File Line: 301
// RVA: 0x644EF0
void __fastcall UFG::WheeledVehicleManager::ApplyDefaultMaxCars(UFG::WheeledVehicleManager *this)
{
  __int64 v1; // rdx
  bool v2; // al
  int v3; // ecx

  v2 = 1;
  if ( UFG::WheeledVehicleManager::mMaxTrafficCars <= 34 )
  {
    v1 = 0x440408000i64;
    if ( _bittest64(&v1, UFG::WheeledVehicleManager::mMaxTrafficCars) )
      v2 = 0;
  }
  if ( UFG::WheeledVehicleManager::mMaxTrafficCarsScale >= 0.99998999 && !v2 )
  {
    LODWORD(UFG::WheeledVehicleManager::mMaxTrafficCarsScale) = (_DWORD)FLOAT_1_0;
    UFG::WheeledVehicleManager::mBaseMaxTrafficCars = UFG::WheeledVehicleManager::mDefaultMaxTrafficCars;
    UFG::WheeledVehicleManager::mMaxTrafficCars = (int)(float)(int)UFG::WheeledVehicleManager::mDefaultMaxTrafficCars;
  }
  if ( UFG::WheeledVehicleManager::mMaxParkedCars <= 25 )
  {
    v3 = 34637824;
    if ( _bittest(&v3, UFG::WheeledVehicleManager::mMaxParkedCars) )
      UFG::WheeledVehicleManager::mMaxParkedCars = UFG::WheeledVehicleManager::mDefaultMaxParkedCars;
  }
}

// File Line: 322
// RVA: 0x65A5A0
void __fastcall UFG::WheeledVehicleManager::SimJustClosed(UFG::WheeledVehicleManager *this)
{
  this->mNumTrafficCars = 0;
}

// File Line: 328
// RVA: 0x656980
void __fastcall UFG::WheeledVehicleManager::OnChangeLocationFinished(UFG::WheeledVehicleManager *this)
{
  if ( this->m_PlaceTransitVehiclePending )
  {
    *(_WORD *)&this->m_PlaceTransitVehiclePending = 256;
    this->m_PlaceTransitVehicleFrames = 1;
  }
}

// File Line: 343
// RVA: 0x648E10
UFG::qPropertySet *__fastcall UFG::WheeledVehicleManager::ChooseWeightedEntryFromSpawningList(
        UFG::WheeledVehicleManager *this)
{
  unsigned int size; // ebx
  UFG::qPropertySet *v4; // rsi
  UFG::qSymbol *CurrentTrafficSet; // rax
  UFG::qPropertySet *PropertySet; // rax
  UFG::qPropertyList *v7; // rax
  __int64 mOffset; // rcx
  unsigned int mTypeUID; // r12d
  int *v10; // rdi
  __int64 mNumElements; // r14
  UFG::qSymbol *v12; // r15
  signed __int64 v13; // r15
  __int64 v14; // r9
  unsigned int v15; // eax
  UFG::qPropertySet **p; // rdx
  int v17; // r8d
  int v18; // r9d
  int v19; // r10d
  __int64 v20; // rcx
  unsigned int v21; // eax
  __int64 v22; // rdx
  int v23; // eax
  __int64 v24; // rcx
  int *i; // rdx
  UFG::qPropertySet **v26; // rax
  __int64 v27; // rdx
  int dest[32]; // [rsp+20h] [rbp-A8h] BYREF
  UFG::qSymbol result; // [rsp+D8h] [rbp+10h] BYREF

  if ( UFG::WheeledVehicleManager::GetCurrentTrafficSet(this, &result)->mUID == UFG::gNullQSymbol.mUID )
    return 0i64;
  size = this->mSpawningSelectionArray.size;
  v4 = 0i64;
  if ( size )
  {
    CurrentTrafficSet = UFG::WheeledVehicleManager::GetCurrentTrafficSet(this, &result);
    PropertySet = UFG::PropertySetManager::CreateOrFindPropertySet(CurrentTrafficSet);
    v7 = UFG::qPropertySet::Get<UFG::qPropertyList>(
           PropertySet,
           (UFG::qArray<unsigned long,0> *)&qSymbol_SpawnSet,
           DEPTH_RECURSE);
    mOffset = v7->mWeights.mOffset;
    mTypeUID = v7->mTypeUID;
    if ( mOffset )
      v10 = (int *)((char *)&v7->mWeights + mOffset);
    else
      v10 = 0i64;
    mNumElements = v7->mNumElements;
    if ( (_DWORD)mNumElements )
      v12 = UFG::qPropertyList::Get<UFG::qSymbol>(v7, 0);
    else
      v12 = 0i64;
    if ( mTypeUID == 22 && v10 && size > 1 )
    {
      UFG::qMemSet(dest, 0, 0x80u);
      if ( (_DWORD)mNumElements )
      {
        v13 = (char *)v12 - (char *)v10;
        v14 = mNumElements;
        do
        {
          v15 = 0;
          p = this->mSpawningSelectionArray.p;
          while ( (*p)->mName.mUID != *(int *)((char *)v10 + v13) )
          {
            ++v15;
            ++p;
            if ( v15 >= size )
              goto LABEL_21;
          }
          dest[v15] = *v10;
LABEL_21:
          ++v10;
          --v14;
        }
        while ( v14 );
      }
      v17 = 0;
      v18 = 0;
      v19 = 0;
      v20 = 0i64;
      dest[this->mCurrentSpawnIndex & 0x1F] = 0;
      v21 = 0;
      if ( (int)size >= 2 )
      {
        v22 = ((size - 2) >> 1) + 1;
        v21 = 2 * v22;
        do
        {
          v17 += dest[v20];
          v18 += dest[v20 + 1];
          v20 += 2i64;
          --v22;
        }
        while ( v22 );
      }
      if ( v21 < size )
        v19 = dest[v20];
      v23 = UFG::qRandom(v19 + v18 + v17, (unsigned int *)&UFG::qDefaultSeed);
      v24 = 0i64;
      for ( i = dest; ; ++i )
      {
        v23 -= *i;
        if ( v23 < 0 )
          break;
        v24 = (unsigned int)(v24 + 1);
        if ( (unsigned int)v24 >= size )
          return v4;
      }
      v26 = this->mSpawningSelectionArray.p;
      this->mCurrentSpawnIndex = v24;
      return v26[v24];
    }
    else
    {
      v27 = (this->mCurrentSpawnIndex + 1) % this->mSpawningSelectionArray.size;
      v4 = this->mSpawningSelectionArray.p[v27];
      this->mCurrentSpawnIndex = v27;
    }
  }
  return v4;
}

// File Line: 426
// RVA: 0x6484D0
UFG::qPropertySet *__fastcall UFG::WheeledVehicleManager::ChooseAmbientVehicle(
        UFG::WheeledVehicleManager *this,
        unsigned int roadType,
        UFG::WheeledVehicleManager::VehicleJob vehicleJobType)
{
  UFG::WheeledVehicleManager::VehicleJob v4; // r15d
  UFG::ObjectResourceManager *v7; // rdi
  UFG::qPropertySet *PropertySet; // rbx
  __int64 v9; // rdi
  UFG::qArray<UFG::qPropertySet *,0> *p_mSpawningSelectionArray; // r14
  UFG::ObjectResourceManager *v11; // rbp
  UFG::qPropertySet **p; // rax
  UFG::qPropertySet *v13; // rsi
  __int64 size; // r15
  unsigned int capacity; // edx
  unsigned int v16; // ebx
  unsigned int v17; // edx
  UFG::qPropertySet **v18; // rax
  UFG::qSymbol result; // [rsp+20h] [rbp-48h] BYREF
  UFG::qSymbol propSetName; // [rsp+88h] [rbp+20h] BYREF

  v4 = vehicleJobType;
  if ( UFG::WheeledVehicleManager::GetCurrentTrafficSet(this, &result)->mUID == UFG::gNullQSymbol.mUID )
    return 0i64;
  v7 = UFG::ObjectResourceManager::Instance();
  propSetName.mUID = UFG::EntityTypeState::GetSpawnableRareEntity(&v7->mEntityStates[1])->mUID;
  if ( propSetName.mUID != UFG::gNullQSymbol.mUID
    && (PropertySet = UFG::PropertySetManager::GetPropertySet(&propSetName),
        UFG::VehicleUtility::IsClassTypeRoadTypeMatch(PropertySet, roadType))
    && UFG::WheeledVehicleManager::IsVehicleJobMatch(this, PropertySet, v4) )
  {
    UFG::EntityTypeState::RareEntitySpawned(&v7->mEntityStates[1], &propSetName);
  }
  else
  {
    v9 = 0i64;
    p_mSpawningSelectionArray = &this->mSpawningSelectionArray;
    v11 = UFG::ObjectResourceManager::Instance();
    this->mSpawningSelectionArray.size = 0;
    if ( v11->mAmbientVehicles.size )
    {
      do
      {
        p = v11->mAmbientVehicles.p;
        v13 = p[v9];
        if ( v13
          && UFG::VehicleUtility::IsClassTypeRoadTypeMatch(p[v9], roadType)
          && UFG::WheeledVehicleManager::IsVehicleJobMatch(this, v13, v4) )
        {
          size = p_mSpawningSelectionArray->size;
          capacity = this->mSpawningSelectionArray.capacity;
          v16 = size + 1;
          if ( (int)size + 1 > capacity )
          {
            if ( capacity )
              v17 = 2 * capacity;
            else
              v17 = 1;
            for ( ; v17 < v16; v17 *= 2 )
              ;
            if ( v17 <= 2 )
              v17 = 2;
            if ( v17 - v16 > 0x10000 )
              v17 = size + 65537;
            UFG::qArray<UFG::CompositeDrawableComponent *,32>::Reallocate(
              (UFG::qArray<UFG::qReflectInventoryBase *,0> *)&this->mSpawningSelectionArray,
              v17,
              "qArray.Add");
          }
          v18 = this->mSpawningSelectionArray.p;
          p_mSpawningSelectionArray->size = v16;
          v18[size] = v13;
          v4 = vehicleJobType;
        }
        v9 = (unsigned int)(v9 + 1);
      }
      while ( (unsigned int)v9 < v11->mAmbientVehicles.size );
    }
    return UFG::WheeledVehicleManager::ChooseWeightedEntryFromSpawningList(this);
  }
  return PropertySet;
}

// File Line: 485
// RVA: 0x652110
_BOOL8 __fastcall UFG::WheeledVehicleManager::IsTrueDirectionUpdateEnabled(UFG::WheeledVehicleManager *this)
{
  return this->m_TrueDirectionUpdateEnabled;
}

// File Line: 490
// RVA: 0x659A30
void __fastcall UFG::WheeledVehicleManager::SetTrueDirectionUpdateEnabled(
        UFG::WheeledVehicleManager *this,
        bool isEnabled)
{
  this->m_TrueDirectionUpdateEnabled = isEnabled;
}

// File Line: 496
// RVA: 0x652120
_BOOL8 __fastcall UFG::WheeledVehicleManager::IsVehicleJobMatch(
        UFG::WheeledVehicleManager *this,
        UFG::qPropertySet *vehiclePropSet,
        UFG::WheeledVehicleManager::VehicleJob jobType)
{
  bool v4; // bl
  bool v5; // di
  char IsClassType; // al
  bool v8; // dl
  UFG::qSymbol targetClassType; // [rsp+40h] [rbp+18h] BYREF

  v4 = jobType == Traffic;
  v5 = jobType == Tram;
  if ( !vehiclePropSet )
    return v4;
  targetClassType.mUID = qSymbol_Minibus.mUID;
  if ( UFG::SimObjectUtility::IsClassType(vehiclePropSet, &targetClassType) )
    return v4 || v5;
  targetClassType.mUID = qSymbol_Tram.mUID;
  if ( UFG::SimObjectUtility::IsClassType(vehiclePropSet, &targetClassType) )
    return v4 || v5;
  targetClassType.mUID = qSymbol_Ferry.mUID;
  IsClassType = UFG::SimObjectUtility::IsClassType(vehiclePropSet, &targetClassType);
  v8 = v4;
  if ( IsClassType )
    return v5;
  return v8;
}

// File Line: 517
// RVA: 0x648400
UFG::qPropertySet *__fastcall UFG::WheeledVehicleManager::ChooseAmbientParkedVehicle(
        UFG::WheeledVehicleManager *this,
        unsigned int roadType)
{
  __int64 v4; // rbx
  UFG::ObjectResourceManager *v5; // rdi
  __int64 v6; // rsi
  bool *v7; // rax

  v4 = 0i64;
  v5 = UFG::ObjectResourceManager::Instance();
  this->mSpawningSelectionArray.size = 0;
  if ( v5->mAmbientVehicles.size )
  {
    do
    {
      v6 = v4;
      if ( UFG::VehicleUtility::IsClassTypeRoadTypeMatch(v5->mAmbientVehicles.p[v4], roadType) )
      {
        v7 = UFG::qPropertySet::Get<bool>(
               v5->mAmbientVehicles.p[v6],
               (UFG::qArray<unsigned long,0> *)&qSymbol_Parkable,
               DEPTH_RECURSE);
        if ( v7 )
        {
          if ( *v7 )
            UFG::qArray<UFG::PedSpawningInfo *,0>::Add(
              &this->mSpawningSelectionArray,
              &v5->mAmbientVehicles.p[v6],
              "qArray.Add");
        }
      }
      v4 = (unsigned int)(v4 + 1);
    }
    while ( (unsigned int)v4 < v5->mAmbientVehicles.size );
  }
  return UFG::WheeledVehicleManager::ChooseWeightedEntryFromSpawningList(this);
}

// File Line: 540
// RVA: 0x64A1B0
void UFG::WheeledVehicleManager::Create(void)
{
  UFG::allocator::free_link *v0; // rax
  UFG::WheeledVehicleManager *v1; // rax

  v0 = UFG::qMalloc(0x3C18ui64, "WheeledVehicleManager", 0i64);
  if ( v0 )
  {
    UFG::WheeledVehicleManager::WheeledVehicleManager((UFG::WheeledVehicleManager *)v0);
    UFG::WheeledVehicleManager::m_Instance = v1;
  }
  else
  {
    UFG::WheeledVehicleManager::m_Instance = 0i64;
  }
}

// File Line: 546
// RVA: 0x64A820
UFG::SimObjectVehicle *__fastcall UFG::WheeledVehicleManager::CreateWheeledVehicle(
        UFG::WheeledVehicleManager *this,
        UFG::qPropertySet *vehiclePropSet)
{
  unsigned int mTotalNumTrafficCarsCreated; // ebx
  UFG::OnlineManager *v5; // rax
  unsigned int OnlineIdStringHash32; // eax
  UFG::qSymbol *v7; // rax
  unsigned int v8; // ebx
  UFG::SimObjectVehicle *v9; // rax
  UFG::SimObject **p_m_pPointer; // rcx
  UFG::SimObjectVehicle *v11; // rdi
  char dest[40]; // [rsp+30h] [rbp-28h] BYREF
  UFG::SpawnInfoInterface::SpawnPriority pPriority; // [rsp+60h] [rbp+8h] BYREF
  UFG::qSymbol result; // [rsp+70h] [rbp+18h] BYREF

  mTotalNumTrafficCarsCreated = this->mTotalNumTrafficCarsCreated;
  this->mTotalNumTrafficCarsCreated = mTotalNumTrafficCarsCreated + 1;
  v5 = UFG::OnlineManager::Instance();
  OnlineIdStringHash32 = UFG::OnlineManager::GetOnlineIdStringHash32(v5);
  UFG::qSPrintf(dest, UFG::WheeledVehicleManager::mTrafficCarName, OnlineIdStringHash32, mTotalNumTrafficCarsCreated);
  UFG::SpawnInfoInterface::GetSpawnPriority(vehiclePropSet, &pPriority);
  v7 = UFG::qSymbol::create_from_string(&result, dest);
  v8 = 0;
  v9 = (UFG::SimObjectVehicle *)UFG::SpawnInfoInterface::SpawnObject(v7, vehiclePropSet, pPriority, 0i64, 0i64, 0i64);
  ++this->mNumTrafficCars;
  p_m_pPointer = &this->mTrafficCar[0].m_pPointer;
  v11 = v9;
  while ( *p_m_pPointer )
  {
    ++v8;
    p_m_pPointer += 8;
    if ( v8 >= 0x64 )
      return v9;
  }
  UFG::qSafePointerWithCallbacks<UFG::SimObject,UFG::SimObjectVehicle>::Set(
    (UFG::qSafePointerWithCallbacks<UFG::EncounterBase,UFG::EncounterBase> *)&this->mTrafficCar[(unsigned __int64)v8],
    (UFG::EncounterBase *)v9);
  return v11;
}

// File Line: 575
// RVA: 0x15788F0
__int64 dynamic_initializer_for__gsymAIActionTreeComponentUC__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("AIActionTreeComponent", -1);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&gsymAIActionTreeComponentUC, v0);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__gsymAIActionTreeComponentUC__);
}

// File Line: 578
// RVA: 0x645360
void __fastcall UFG::WheeledVehicleManager::AttachTrafficAI(
        UFG::WheeledVehicleManager *this,
        UFG::SimObjectVehicle *pCar)
{
  UFG::qMemoryPool *SimulationMemoryPool; // rax
  UFG::allocator::free_link *v4; // rax
  UFG::SimComponent *v5; // rbp
  __int64 v6; // rax
  __int64 v7; // rdi
  signed __int16 m_Flags; // cx
  unsigned int v9; // ebx
  unsigned int v10; // esi
  UFG::qMemoryPool *v11; // rax
  UFG::allocator::free_link *v12; // rax
  UFG::SimComponent *v13; // rax
  UFG::SimComponent *v14; // rsi
  signed __int16 v15; // cx
  unsigned int v16; // edi
  UFG::qMemoryPool *v17; // rax
  UFG::allocator::free_link *v18; // rax
  UFG::SimComponent *v19; // rax
  signed __int16 v20; // cx
  UFG::SimObjectModifier v21; // [rsp+38h] [rbp-60h] BYREF
  UFG::SimObjectModifier v22; // [rsp+58h] [rbp-40h] BYREF

  UFG::SimObjectModifier::SimObjectModifier(&v22, pCar, 1);
  SimulationMemoryPool = UFG::GetSimulationMemoryPool();
  v4 = UFG::qMemoryPool::Allocate(SimulationMemoryPool, 0x628ui64, "AiDriverComponent", 0i64, 1u);
  v5 = 0i64;
  if ( v4 )
  {
    UFG::AiDriverComponent::AiDriverComponent((UFG::AiDriverComponent *)v4, 1);
    v7 = v6;
  }
  else
  {
    v7 = 0i64;
  }
  if ( *(_DWORD *)(v7 + 840) != 1 )
  {
    *(_DWORD *)(v7 + 840) = 1;
    *(_DWORD *)(v7 + 1228) = 0;
    *(_DWORD *)(v7 + 1548) = 0;
    *(_BYTE *)(v7 + 1196) = 0;
    *(_BYTE *)(v7 + 1204) = 0;
    *(_BYTE *)(v7 + 1464) = 0;
  }
  m_Flags = pCar->m_Flags;
  v9 = -1;
  if ( (m_Flags & 0x4000) != 0 )
  {
    v10 = 23;
  }
  else if ( m_Flags >= 0 )
  {
    v10 = -1;
  }
  else
  {
    v10 = 23;
  }
  UFG::SimObjectModifier::SimObjectModifier(&v21, pCar, 1);
  UFG::SimObjectModifier::AttachComponent(&v21, (UFG::SimComponent *)v7, v10);
  UFG::SimObjectModifier::Close(&v21);
  UFG::SimObjectModifier::~SimObjectModifier(&v21);
  if ( !pCar->m_Components.p[24].m_pComponent )
  {
    v11 = UFG::GetSimulationMemoryPool();
    v12 = UFG::qMemoryPool::Allocate(v11, 0x7A0ui64, "RoadSpaceComponent", 0i64, 1u);
    if ( v12 )
    {
      UFG::RoadSpaceComponent::RoadSpaceComponent((UFG::RoadSpaceComponent *)v12);
      v14 = v13;
    }
    else
    {
      v14 = 0i64;
    }
    v15 = pCar->m_Flags;
    if ( (v15 & 0x4000) != 0 )
    {
      v16 = 24;
    }
    else if ( v15 >= 0 )
    {
      v16 = -1;
    }
    else
    {
      v16 = 24;
    }
    UFG::SimObjectModifier::SimObjectModifier(&v21, pCar, 1);
    UFG::SimObjectModifier::AttachComponent(&v21, v14, v16);
    UFG::SimObjectModifier::Close(&v21);
    UFG::SimObjectModifier::~SimObjectModifier(&v21);
  }
  v17 = UFG::GetSimulationMemoryPool();
  v18 = UFG::qMemoryPool::Allocate(v17, 0x678ui64, "AIActionTreeComponent", 0i64, 1u);
  if ( v18 )
  {
    UFG::AIActionTreeComponent::AIActionTreeComponent(
      (UFG::AIActionTreeComponent *)v18,
      gsymAIActionTreeComponentUC.mUID,
      "Data\\Global\\Act\\CarAI.act");
    v5 = v19;
  }
  v20 = pCar->m_Flags;
  if ( (v20 & 0x4000) != 0 || v20 < 0 )
    v9 = 19;
  UFG::SimObjectModifier::SimObjectModifier(&v21, pCar, 1);
  UFG::SimObjectModifier::AttachComponent(&v21, v5, v9);
  UFG::SimObjectModifier::Close(&v21);
  UFG::SimObjectModifier::~SimObjectModifier(&v21);
  UFG::SimObjectModifier::Close(&v22);
  UFG::SimObjectModifier::~SimObjectModifier(&v22);
}

// File Line: 605
// RVA: 0x64C700
void __fastcall UFG::WheeledVehicleManager::EnableTrafficSpawningUpdates(bool enable)
{
  UFG::WheeledVehicleManager::m_TrafficSpawningUpdatesEnabled = enable;
}

// File Line: 615
// RVA: 0x659A20
void __fastcall UFG::WheeledVehicleManager::SetTrafficSystemLocked(bool locked)
{
  UFG::WheeledVehicleManager::m_TrafficSystemLocked = locked;
}

// File Line: 625
// RVA: 0x64C710
void __fastcall UFG::WheeledVehicleManager::EnableTrafficSystem(UFG::WheeledVehicleManager *this, bool enable)
{
  UFG::ObjectResourceManager *v3; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::TrafficRegion> *p_mCurrentTrafficRegion; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::ObjectResourceManager *v7; // rax
  UFG::ObjectResourceManager *v8; // rax

  if ( !UFG::WheeledVehicleManager::m_TrafficSystemLocked
    && UFG::WheeledVehicleManager::m_TrafficSystemEnabled != enable )
  {
    UFG::WheeledVehicleManager::m_TrafficSystemEnabled = enable;
    UFG::WheeledVehicleManager::mTrafficCarSpawningEnabled = enable;
    UFG::WheeledVehicleManager::mParkedCarSpawningEnabled = enable;
    UFG::WheeledVehicleManager::mUpdateTrafficRegionEnabled = enable;
    if ( enable )
    {
      v8 = UFG::ObjectResourceManager::Instance();
      UFG::ObjectResourceManager::SetActiveAmbience(v8, 1, 1);
      UFG::WheeledVehicleManager::Reinitialize(this);
      UFG::WheeledVehicleManager::UpdateTrafficSet(this);
    }
    else
    {
      UFG::WheeledVehicleManager::DestroyAllWheeledVehicles(this);
      v3 = UFG::ObjectResourceManager::Instance();
      UFG::ObjectResourceManager::UnloadAmbientVehicles(v3);
      p_mCurrentTrafficRegion = &this->mCurrentTrafficRegion;
      if ( this->mCurrentTrafficRegion.m_pPointer )
      {
        mPrev = p_mCurrentTrafficRegion->mPrev;
        mNext = this->mCurrentTrafficRegion.mNext;
        mPrev->mNext = mNext;
        mNext->mPrev = mPrev;
        p_mCurrentTrafficRegion->mPrev = p_mCurrentTrafficRegion;
        this->mCurrentTrafficRegion.mNext = &this->mCurrentTrafficRegion;
      }
      this->mCurrentTrafficRegion.m_pPointer = 0i64;
      v7 = UFG::ObjectResourceManager::Instance();
      UFG::ObjectResourceManager::SetActiveAmbience(v7, 0, 1);
      UFG::RoadNetworkVisibleArea::Reinitialize(this->m_VisibleArea);
    }
  }
}

// File Line: 658
// RVA: 0x64A440
UFG::SimObjectVehicle *__fastcall UFG::WheeledVehicleManager::CreateParkedWheeledVehicle(
        UFG::WheeledVehicleManager *this,
        UFG::qPropertySet *vehiclePropSet,
        UFG::ParkingSpot *spot)
{
  unsigned int mTotalNumParkedCarsCreated; // ebx
  UFG::qSymbol *v7; // rax
  UFG::SimObjectVehicle *v8; // rbx
  __int64 v9; // rcx
  UFG::SimObject **i; // rdx
  char dest[40]; // [rsp+20h] [rbp-28h] BYREF
  UFG::qSymbol result; // [rsp+50h] [rbp+8h] BYREF

  mTotalNumParkedCarsCreated = this->mTotalNumParkedCarsCreated;
  this->mTotalNumParkedCarsCreated = mTotalNumParkedCarsCreated + 1;
  UFG::OnlineManager::Instance();
  UFG::qSPrintf(dest, UFG::WheeledVehicleManager::mParkedCarName, 0i64, mTotalNumParkedCarsCreated);
  ++this->mNumParkedCars;
  v7 = UFG::qSymbol::create_from_string(&result, dest);
  v8 = (UFG::SimObjectVehicle *)UFG::ParkingSpot::Spawn(spot, v7, vehiclePropSet, 3);
  UFG::VehicleUtility::SetRadiostation(v8);
  v9 = 0i64;
  for ( i = &this->mParkedCar[0].m_pPointer; *i; i += 8 )
  {
    v9 = (unsigned int)(v9 + 1);
    if ( (unsigned int)v9 >= 0x64 )
      return v8;
  }
  UFG::qSafePointerWithCallbacks<UFG::SimObject,UFG::SimObjectVehicle>::Set(
    (UFG::qSafePointerWithCallbacks<UFG::EncounterBase,UFG::EncounterBase> *)&this->mParkedCar[v9],
    (UFG::EncounterBase *)v8);
  return v8;
}

// File Line: 687
// RVA: 0x64A200
void __fastcall UFG::WheeledVehicleManager::CreateParkedCarsOnSubSegment(
        UFG::WheeledVehicleManager *this,
        UFG::RoadNetworkSubSegment *subSegment,
        unsigned int numParkedCars)
{
  unsigned int NumAvailableParkingSpots; // eax
  unsigned __int64 v7; // rdi
  UFG::ParkingSpot *i; // rbx
  unsigned int v9; // eax
  UFG::qPropertySet *v10; // rax
  unsigned __int64 v11; // rax
  __int64 v12; // rbx
  __int64 v13; // r14
  __int64 v14; // rdx
  UFG::ParkingSpot *v15; // rbx
  unsigned int v16; // eax
  UFG::qPropertySet *v17; // rax
  UFG::qArray<UFG::ParkingSpot *,0> availableParkingSpots; // [rsp+28h] [rbp-30h] BYREF

  NumAvailableParkingSpots = UFG::RoadNetworkSubSegment::GetNumAvailableParkingSpots(subSegment);
  v7 = NumAvailableParkingSpots;
  if ( NumAvailableParkingSpots )
  {
    if ( numParkedCars < NumAvailableParkingSpots )
    {
      availableParkingSpots.p = 0i64;
      *(_QWORD *)&availableParkingSpots.size = 0i64;
      v11 = 8i64 * NumAvailableParkingSpots;
      if ( !is_mul_ok(v7, 8ui64) )
        v11 = -1i64;
      availableParkingSpots.p = (UFG::ParkingSpot **)UFG::qMalloc(v11, "WheeledVehicleManager", 0i64);
      availableParkingSpots.capacity = v7;
      UFG::RoadNetworkSubSegment::GetAvailableParkingSpots(subSegment, &availableParkingSpots);
      for ( ; numParkedCars; --numParkedCars )
      {
        v12 = (unsigned int)UFG::qRandom(v7, (unsigned int *)&UFG::qDefaultSeed);
        v13 = v12;
        if ( !((unsigned __int8 (__fastcall *)(UFG::ParkingSpot *))availableParkingSpots.p[v13]->vfptr[18].__vecDelDtor)(availableParkingSpots.p[v13])
          && !((unsigned __int8 (__fastcall *)(UFG::ParkingSpot *))availableParkingSpots.p[v13]->vfptr[18].__vecDelDtor)(availableParkingSpots.p[v13]) )
        {
          do
          {
            v14 = ((int)v12 + 1) % (unsigned int)v7;
            v12 = v14;
          }
          while ( !((unsigned __int8 (__fastcall *)(UFG::ParkingSpot *))availableParkingSpots.p[v14]->vfptr[18].__vecDelDtor)(availableParkingSpots.p[v14]) );
        }
        v15 = availableParkingSpots.p[v12];
        v16 = ((__int64 (__fastcall *)(UFG::ParkingSpot *))v15->vfptr[17].__vecDelDtor)(v15);
        v17 = UFG::WheeledVehicleManager::ChooseAmbientParkedVehicle(this, v16);
        if ( v17 )
          UFG::WheeledVehicleManager::SpawnParkedVehicle(this, v17, v15);
      }
      if ( availableParkingSpots.p )
        operator delete[](availableParkingSpots.p);
    }
    else
    {
      for ( i = (UFG::ParkingSpot *)&subSegment->mParkingSpotCollection.mNode.mNext[-12];
            i != (UFG::ParkingSpot *)&subSegment[-1].mPosition.z;
            i = (UFG::ParkingSpot *)&i->UFG::qNode<UFG::ParkingSpot,UFG::ParkingSpot>::mNext[-12] )
      {
        if ( ((unsigned __int8 (__fastcall *)(UFG::ParkingSpot *))i->vfptr[18].__vecDelDtor)(i) )
        {
          v9 = ((__int64 (__fastcall *)(UFG::ParkingSpot *))i->vfptr[17].__vecDelDtor)(i);
          v10 = UFG::WheeledVehicleManager::ChooseAmbientParkedVehicle(this, v9);
          if ( v10 )
            UFG::WheeledVehicleManager::SpawnParkedVehicle(this, v10, i);
        }
      }
    }
  }
}

// File Line: 767
// RVA: 0x64A510
void __fastcall UFG::WheeledVehicleManager::CreateTrafficCarsOnSubSegment(
        UFG::WheeledVehicleManager *this,
        UFG::RoadNetworkSubSegment *subSegment,
        unsigned int numCars)
{
  UFG::RoadNetworkSubSegment *v4; // r13
  unsigned __int64 mNumLanes; // r12
  unsigned int v7; // eax
  __int64 v8; // rbx
  unsigned int v9; // edi
  unsigned __int64 v10; // rax
  unsigned __int64 v11; // rax
  unsigned int v12; // eax
  __int64 *v13; // rdi
  __int64 i; // rcx
  int v15; // edx
  __int64 v16; // rdi
  float v17; // xmm9_4
  unsigned int v18; // r14d
  __int64 *v19; // r12
  __int64 v20; // rdi
  UFG::RoadNetworkLane *Lane; // rbx
  float EndT; // xmm8_4
  float Length; // xmm0_4
  float v24; // xmm7_4
  float v25; // xmm6_4
  __int64 v26; // rsi
  unsigned int v27; // r13d
  UFG::qPropertySet *v28; // rdi
  UFG::ObjectResourceManager *v29; // rax
  UFG::RoadNetworkNode *v30; // r8
  void *mem; // [rsp+10h] [rbp-71h]
  UFG::allocator::free_link *t; // [rsp+20h] [rbp-61h]
  __int64 v33; // [rsp+28h] [rbp-59h] BYREF
  UFG::RoadNetworkNode *mParentNode; // [rsp+30h] [rbp-51h]
  __int64 v35; // [rsp+38h] [rbp-49h]
  __int64 v36; // [rsp+40h] [rbp-41h]
  __int64 v37; // [rsp+48h] [rbp-39h]
  UFG::RoadNetworkSubSegment *v38; // [rsp+F0h] [rbp+6Fh]
  unsigned int roadType; // [rsp+F8h] [rbp+77h]
  unsigned int v40; // [rsp+100h] [rbp+7Fh]

  if ( numCars )
  {
    v35 = -2i64;
    v4 = subSegment;
    mParentNode = subSegment->mParentNode;
    roadType = UFG::RoadNetworkSegment::GetRoadNetworkType((UFG::RoadNetworkSegment *)mParentNode);
    mNumLanes = (unsigned __int8)mParentNode->mNumLanes;
    v40 = mNumLanes;
    if ( (unsigned int)(mNumLanes - 1) <= 9 )
    {
      v7 = numCars / (unsigned int)mNumLanes;
      v8 = numCars % (unsigned int)mNumLanes;
      v9 = v7;
      v33 = 0i64;
      mParentNode = 0i64;
      v35 = 0i64;
      v36 = 0i64;
      v37 = 0i64;
      v10 = 4 * mNumLanes;
      if ( !is_mul_ok(mNumLanes, 4ui64) )
        v10 = -1i64;
      t = UFG::qMalloc(v10, "WheeledVehicleManager", 0i64);
      v11 = 4 * mNumLanes;
      if ( !is_mul_ok(mNumLanes, 4ui64) )
        v11 = -1i64;
      UFG::qMalloc(v11, "WheeledVehicleManager", 0i64);
      v12 = v9;
      v13 = &v33;
      for ( i = (unsigned int)mNumLanes; i; --i )
      {
        *(_DWORD *)v13 = v12;
        v13 = (__int64 *)((char *)v13 + 4);
      }
      v15 = UFG::qRandom(mNumLanes, (unsigned int *)&UFG::qDefaultSeed);
      if ( (_DWORD)v8 )
      {
        v16 = v8;
        do
        {
          ++*((_DWORD *)&v33 + v15);
          v15 = (v15 + 1) % (unsigned int)mNumLanes;
          --v16;
        }
        while ( v16 );
      }
      v17 = v4->mLength - 8.0;
      if ( v17 <= 0.0 )
        v17 = 0.0;
      v18 = 0;
      v19 = &v33;
      do
      {
        v20 = *(unsigned int *)v19;
        if ( (unsigned int)v20 <= 0x19 && (_DWORD)v20 )
        {
          Lane = UFG::RoadNetworkNode::GetLane(mParentNode, v18);
          if ( UFG::RoadNetworkLane::IsReversedInNode(Lane) )
          {
            EndT = UFG::RoadNetworkSubSegment::GetEndT(v4, v18);
            UFG::RoadNetworkSubSegment::GetBeginT(v4, v18);
          }
          else
          {
            EndT = UFG::RoadNetworkSubSegment::GetBeginT(v4, v18);
            UFG::RoadNetworkSubSegment::GetEndT(v4, v18);
          }
          Length = UFG::RoadNetworkLane::GetLength(Lane);
          v24 = (float)(1.0 / Length) * (float)(v17 / (float)(int)v20);
          v25 = (float)((float)(1.0 / Length) * 4.0) + EndT;
          v26 = v20;
          v27 = roadType;
          do
          {
            v28 = UFG::WheeledVehicleManager::ChooseAmbientVehicle(this, v27, Traffic);
            if ( v28 )
            {
              v29 = UFG::ObjectResourceManager::Instance();
              if ( UFG::ObjectResourceManager::CanSpawnAmbient(v29, v28, 0i64, 0) )
              {
                if ( Lane->mNode.mOffset )
                  v30 = (UFG::RoadNetworkNode *)((char *)Lane + Lane->mNode.mOffset);
                else
                  v30 = 0i64;
                UFG::WheeledVehicleManager::SpawnTrafficVehicle(this, v28, v30, Lane->mLaneIndex, Length, v25);
              }
            }
            v25 = v25 + v24;
            --v26;
          }
          while ( v26 );
          v4 = v38;
        }
        ++v18;
        v19 = (__int64 *)((char *)v19 + 4);
      }
      while ( v18 < v40 );
      if ( mem )
        operator delete[](mem);
      if ( t )
        operator delete[](t);
    }
  }
}

// File Line: 934
// RVA: 0x652200
char __fastcall UFG::WheeledVehicleManager::IsVehicleSpawnCollision(
        UFG::qPropertySet *vehiclePropSet,
        UFG::RoadNetworkLane *targetRoadLane,
        float targetLaneT)
{
  UFG::qPropertySet *v4; // rax
  unsigned int v5; // esi
  char *MemImagePtr; // rax
  float targetRear; // xmm8_4
  float targetFront; // xmm9_4
  UFG::RoadNetworkGuide *p_mNext; // rbx
  float m_FrontBoundary; // xmm11_4
  float m_RearBoundary; // xmm7_4
  float m_LaneT; // xmm6_4
  float v13; // xmm7_4
  __int64 mOffset; // rax
  UFG::RoadNetworkConnection *v15; // r14
  unsigned int mNumLanes; // ebp
  unsigned int v18; // ebx
  UFG::RoadNetworkLane *Path; // rax
  __int64 v20; // rax
  UFG::RoadNetworkConnection *v21; // rbx
  unsigned int v22; // ebp
  UFG::RoadNetworkLane *v23; // rax
  UFG::qVector3 result; // [rsp+30h] [rbp-88h] BYREF
  UFG::qVector3 v25; // [rsp+40h] [rbp-78h] BYREF

  v4 = UFG::qPropertySet::Get<UFG::qPropertySet>(
         vehiclePropSet,
         (UFG::qArray<unsigned long,0> *)&component_PhysicsMover::sPropertyName,
         DEPTH_RECURSE);
  v5 = 0;
  if ( v4 )
    MemImagePtr = UFG::qPropertySet::GetMemImagePtr(v4);
  else
    MemImagePtr = 0i64;
  targetRear = 0.0;
  LODWORD(targetFront) = *((_DWORD *)MemImagePtr + 12) & _xmm;
  if ( targetFront < 0.0 )
    targetFront = 0.0;
  if ( COERCE_FLOAT(*((_DWORD *)MemImagePtr + 9) & _xmm) >= 0.0 )
    LODWORD(targetRear) = *((_DWORD *)MemImagePtr + 9) & _xmm;
  UFG::RoadNetworkLane::GetPos(targetRoadLane, &result, targetLaneT);
  if ( (UFG::qOffset64<UFG::RoadNetworkConnection *> *)&targetRoadLane->mCars.mNode.mNext[-2].mNext == &targetRoadLane->mStartConnection
    || (p_mNext = (UFG::RoadNetworkGuide *)&targetRoadLane->mCars.mNode.mNext[-2].mNext,
        p_mNext == (UFG::RoadNetworkGuide *)&targetRoadLane->mStartConnection) )
  {
LABEL_15:
    mOffset = targetRoadLane->mStartConnection.mOffset;
    if ( mOffset )
      v15 = (UFG::RoadNetworkConnection *)((char *)&targetRoadLane->mStartConnection + mOffset);
    else
      v15 = 0i64;
    mNumLanes = v15->mNumLanes;
    v18 = 0;
    if ( v15->mNumLanes )
    {
      while ( 1 )
      {
        Path = UFG::qBezierPathCollectionMemImaged::GetPath(v15, v18);
        if ( targetRoadLane != Path )
        {
          if ( UFG::WheeledVehicleManager::IsSpawnCollisionOnMergeLane(
                 Path,
                 targetRoadLane,
                 targetLaneT,
                 &result,
                 targetRear,
                 targetFront) )
          {
            break;
          }
        }
        if ( ++v18 >= mNumLanes )
          goto LABEL_23;
      }
    }
    else
    {
LABEL_23:
      v20 = targetRoadLane->mEndConnection.mOffset;
      if ( v20 )
        v21 = (UFG::RoadNetworkConnection *)((char *)&targetRoadLane->mEndConnection + v20);
      else
        v21 = 0i64;
      v22 = v21->mNumLanes;
      if ( !v21->mNumLanes )
        return 0;
      while ( 1 )
      {
        v23 = UFG::qBezierPathCollectionMemImaged::GetPath(v21, v5);
        if ( targetRoadLane != v23 )
        {
          if ( UFG::WheeledVehicleManager::IsSpawnCollisionOnMergeLane(
                 v23,
                 targetRoadLane,
                 targetLaneT,
                 &result,
                 targetRear,
                 targetFront) )
          {
            break;
          }
        }
        if ( ++v5 >= v22 )
          return 0;
      }
    }
    return 1;
  }
  while ( 1 )
  {
    m_FrontBoundary = p_mNext->m_FrontBoundary;
    m_RearBoundary = p_mNext->m_RearBoundary;
    m_LaneT = Scaleform::GFx::AS3::Instances::fl::XML::GetName(p_mNext)->m_LaneT;
    UFG::RoadNetworkLane::GetPos(targetRoadLane, &v25, m_LaneT);
    v13 = m_LaneT <= targetLaneT ? m_FrontBoundary + targetRear : m_RearBoundary + targetFront;
    if ( (float)((float)((float)((float)(result.y - v25.y) * (float)(result.y - v25.y))
                       + (float)((float)(result.x - v25.x) * (float)(result.x - v25.x)))
               + (float)((float)(result.z - v25.z) * (float)(result.z - v25.z))) < (float)((float)(v13 + 0.2)
                                                                                         * (float)(v13 + 0.2)) )
      return 1;
    p_mNext = (UFG::RoadNetworkGuide *)&p_mNext->mNext[-2].mNext;
    if ( p_mNext == (UFG::RoadNetworkGuide *)&targetRoadLane->mStartConnection )
      goto LABEL_15;
  }
}

// File Line: 991
// RVA: 0x651F30
char __fastcall UFG::WheeledVehicleManager::IsSpawnCollisionOnMergeLane(
        UFG::RoadNetworkLane *mergeLane,
        UFG::RoadNetworkLane *targetRoadLane,
        float targetLaneT,
        UFG::qVector3 *targetPos,
        float targetRear,
        float targetFront)
{
  UFG::qOffset64<UFG::RoadNetworkConnection *> *p_mStartConnection; // rdi
  UFG::RoadNetworkGuide *p_mNext; // rbx
  float m_FrontBoundary; // xmm7_4
  float m_RearBoundary; // xmm6_4
  float m_LaneT; // xmm8_4
  float v14; // xmm6_4
  UFG::qVector3 result; // [rsp+20h] [rbp-A8h] BYREF
  UFG::qVector3 v17; // [rsp+30h] [rbp-98h] BYREF
  UFG::qVector3 v18; // [rsp+40h] [rbp-88h] BYREF

  p_mStartConnection = &mergeLane->mStartConnection;
  p_mNext = (UFG::RoadNetworkGuide *)&mergeLane->mCars.mNode.mNext[-2].mNext;
  if ( p_mNext == (UFG::RoadNetworkGuide *)&mergeLane->mStartConnection )
    return 0;
  while ( 1 )
  {
    m_FrontBoundary = p_mNext->m_FrontBoundary;
    m_RearBoundary = p_mNext->m_RearBoundary;
    m_LaneT = Scaleform::GFx::AS3::Instances::fl::XML::GetName(p_mNext)->m_LaneT;
    UFG::RoadNetworkLane::GetPos(targetRoadLane, &result, m_LaneT);
    v14 = m_LaneT <= targetLaneT ? m_FrontBoundary + targetRear : m_RearBoundary + targetFront;
    if ( (float)((float)((float)((float)(targetPos->x - result.x) * (float)(targetPos->x - result.x))
                       + (float)((float)(targetPos->y - result.y) * (float)(targetPos->y - result.y)))
               + (float)((float)(targetPos->z - result.z) * (float)(targetPos->z - result.z))) < (float)((float)(v14 + 0.2) * (float)(v14 + 0.2)) )
    {
      UFG::RoadNetworkLane::GetPos(mergeLane, &v17, m_LaneT);
      UFG::RoadNetworkLane::GetPos(targetRoadLane, &v18, m_LaneT);
      if ( (float)((float)((float)((float)(v17.y - v18.y) * (float)(v17.y - v18.y))
                         + (float)((float)(v17.x - v18.x) * (float)(v17.x - v18.x)))
                 + (float)((float)(v17.z - v18.z) * (float)(v17.z - v18.z))) < 10.240001 )
        break;
    }
    p_mNext = (UFG::RoadNetworkGuide *)&p_mNext->mNext[-2].mNext;
    if ( p_mNext == (UFG::RoadNetworkGuide *)p_mStartConnection )
      return 0;
  }
  return 1;
}

// File Line: 1017
// RVA: 0x64B740
void __fastcall UFG::WheeledVehicleManager::DestroyTrafficVehiclesOnSubSegment(
        UFG::WheeledVehicleManager *this,
        UFG::RoadNetworkSubSegment *subSegment,
        bool queueForDeletion,
        UFG::RoadNetworkLane *specificLane)
{
  UFG::RoadNetworkSegment *mParentNode; // rdi
  unsigned int v5; // ebp
  UFG::RoadNetworkLane *v6; // r12
  UFG::RoadNetworkLane *Lane; // r14
  UFG::RoadNetworkGuide *p_mNext; // rbx
  __int64 v11; // rdi
  UFG::RoadNetworkLocation *Name; // rax
  UFG::SimObjectCVBase *m_SimObj; // rbx
  __int16 m_Flags; // cx
  UFG::AiDriverComponent *v15; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *mCarsWithDeletionPending; // rdx
  __int64 v17; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mPrev; // rax
  UFG::RoadNetworkSegment *i; // [rsp+20h] [rbp-48h]

  mParentNode = subSegment->mParentNode;
  v5 = 0;
  v6 = specificLane;
  for ( i = mParentNode; v5 < (unsigned __int8)mParentNode->mNumLanes; ++v5 )
  {
    if ( !v6 || v5 == v6->mLaneIndex )
    {
      Lane = UFG::RoadNetworkNode::GetLane(mParentNode, v5);
      p_mNext = (UFG::RoadNetworkGuide *)&Lane->mCars.mNode.mNext[-2].mNext;
      if ( p_mNext != (UFG::RoadNetworkGuide *)&Lane->mStartConnection )
      {
        do
        {
          v11 = (__int64)&p_mNext->mNext[-2].mNext;
          Name = Scaleform::GFx::AS3::Instances::fl::XML::GetName(p_mNext);
          if ( UFG::RoadNetworkSubSegment::IsWithinSubSegment(subSegment, Lane, Name->m_LaneT) )
          {
            m_SimObj = (UFG::SimObjectCVBase *)p_mNext->m_SimObj;
            if ( m_SimObj )
            {
              m_Flags = m_SimObj->m_Flags;
              if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
                v15 = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(m_SimObj);
              else
                v15 = (UFG::AiDriverComponent *)((m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
                                               ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                   m_SimObj,
                                                   UFG::AiDriverComponent::_TypeUID)
                                               : UFG::SimObject::GetComponentOfType(
                                                   m_SimObj,
                                                   UFG::AiDriverComponent::_TypeUID));
              if ( v15
                && ((unsigned __int8 (__fastcall *)(UFG::AiDriverComponent *))v15->UFG::VehicleDriverInterface::UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr[16].__vecDelDtor)(v15) )
              {
                if ( queueForDeletion )
                {
                  mCarsWithDeletionPending = this->mCarsWithDeletionPending;
                  v17 = 100i64;
                  do
                  {
                    if ( !mCarsWithDeletionPending->m_pPointer )
                    {
                      mCarsWithDeletionPending->m_pPointer = m_SimObj;
                      mPrev = m_SimObj->m_SafePointerList.UFG::SimObjectGame::UFG::SimObject::UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev;
                      mPrev->mNext = mCarsWithDeletionPending;
                      mCarsWithDeletionPending->mPrev = mPrev;
                      mCarsWithDeletionPending->mNext = &m_SimObj->m_SafePointerList.UFG::SimObjectGame::UFG::SimObject::UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode;
                      m_SimObj->m_SafePointerList.UFG::SimObjectGame::UFG::SimObject::UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev = mCarsWithDeletionPending;
                    }
                    ++mCarsWithDeletionPending;
                    --v17;
                  }
                  while ( v17 );
                }
                else
                {
                  UFG::Simulation::DestroySimObject(&UFG::gSim, m_SimObj);
                }
              }
            }
          }
          p_mNext = (UFG::RoadNetworkGuide *)v11;
        }
        while ( (UFG::qOffset64<UFG::RoadNetworkConnection *> *)v11 != &Lane->mStartConnection );
        v6 = specificLane;
        mParentNode = i;
      }
    }
  }
}

// File Line: 1052
// RVA: 0x64B1A0
void __fastcall UFG::WheeledVehicleManager::DestroyParkedCarsOnSubSegment(
        UFG::WheeledVehicleManager *this,
        UFG::RoadNetworkSubSegment *subSegment)
{
  UFG::qNode<UFG::ParkingSpot,UFG::ParkingSpot> *p_z; // rbp
  UFG::qNode<UFG::ParkingSpot,UFG::ParkingSpot> *v4; // rdi
  UFG::SimObject *mNext; // rbx
  __int16 m_Flags; // cx
  UFG::VehicleOccupantComponent *ComponentOfTypeHK; // rax
  bool v8; // zf
  UFG::SimObjectGame *v9; // rcx
  UFG::RoadNetworkSegment *mParentNode; // rdi
  UFG::qNode<UFG::RoadNetworkSubSegment,UFG::RoadNetworkSubSegment> *v11; // rax
  unsigned int i; // ebx
  UFG::RoadNetworkLane *Lane; // rax

  if ( subSegment->mNumParkingSpots )
  {
    p_z = (UFG::qNode<UFG::ParkingSpot,UFG::ParkingSpot> *)&subSegment[-1].mPosition.z;
    v4 = subSegment->mParkingSpotCollection.mNode.mNext - 12;
    if ( v4 != (UFG::qNode<UFG::ParkingSpot,UFG::ParkingSpot> *)&subSegment[-1].mPosition.z )
    {
      while ( 1 )
      {
        mNext = (UFG::SimObject *)v4[11].mNext;
        if ( mNext )
          break;
LABEL_14:
        v4 = v4[12].mNext - 12;
        if ( v4 == p_z )
          goto LABEL_15;
      }
      m_Flags = mNext->m_Flags;
      if ( (m_Flags & 0x4000) != 0 )
        goto LABEL_5;
      if ( m_Flags >= 0 )
      {
        if ( (m_Flags & 0x2000) != 0 )
        {
LABEL_5:
          ComponentOfTypeHK = (UFG::VehicleOccupantComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                 (UFG::SimObjectGame *)v4[11].mNext,
                                                                 UFG::VehicleOccupantComponent::_TypeUID);
          goto LABEL_12;
        }
        v8 = (m_Flags & 0x1000) == 0;
        v9 = (UFG::SimObjectGame *)v4[11].mNext;
        if ( v8 )
          ComponentOfTypeHK = (UFG::VehicleOccupantComponent *)UFG::SimObject::GetComponentOfType(
                                                                 v9,
                                                                 UFG::VehicleOccupantComponent::_TypeUID);
        else
          ComponentOfTypeHK = (UFG::VehicleOccupantComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                 v9,
                                                                 UFG::VehicleOccupantComponent::_TypeUID);
      }
      else
      {
        ComponentOfTypeHK = (UFG::VehicleOccupantComponent *)mNext->m_Components.p[30].m_pComponent;
      }
LABEL_12:
      if ( UFG::VehicleOccupantComponent::IsParked(ComponentOfTypeHK) )
        UFG::Simulation::DestroySimObject(&UFG::gSim, mNext);
      goto LABEL_14;
    }
LABEL_15:
    mParentNode = subSegment->mParentNode;
    v11 = mParentNode->mSubSegmentCollection.mNode.mNext;
    if ( v11 == (UFG::qNode<UFG::RoadNetworkSubSegment,UFG::RoadNetworkSubSegment> *)&mParentNode->mSubSegmentCollection )
    {
LABEL_18:
      for ( i = 0; i < (unsigned __int8)mParentNode->mNumLanes; Lane->mOffset = 0.0 )
        Lane = UFG::RoadNetworkNode::GetLane(mParentNode, i++);
    }
    else
    {
      while ( !LOWORD(v11[6].mPrev) )
      {
        v11 = v11->mNext;
        if ( v11 == (UFG::qNode<UFG::RoadNetworkSubSegment,UFG::RoadNetworkSubSegment> *)&mParentNode->mSubSegmentCollection )
          goto LABEL_18;
      }
    }
  }
}

// File Line: 1094
// RVA: 0x64B540
__int64 __fastcall UFG::WheeledVehicleManager::DestroyTrafficVehiclesInRange(
        UFG::WheeledVehicleManager *this,
        UFG::qVector3 *pos,
        float radius)
{
  unsigned int v3; // ebp
  UFG::qNode<UFG::RoadSpaceComponent,UFG::RoadSpaceComponent> *p_mNode; // rdi
  UFG::qNode<UFG::RoadSpaceComponent,UFG::RoadSpaceComponent> *mNext; // rsi
  UFG::SimObjectVehicle *v7; // rdi
  UFG::qList<UFG::RoadSpaceComponent,UFG::RoadSpaceComponent,1,0> *v8; // rsi
  __int16 m_Flags; // cx
  UFG::AiDriverComponent *v10; // rax
  __int16 v11; // cx
  UFG::VehicleSubjectComponent *ComponentOfType; // rax
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rbx
  float v14; // xmm0_4

  v3 = 0;
  p_mNode = UFG::RoadSpaceComponent::s_RoadSpaceComponentList.mNode.mNext - 4;
  if ( (UFG::qList<UFG::RoadSpaceComponent,UFG::RoadSpaceComponent,1,0> *)&UFG::RoadSpaceComponent::s_RoadSpaceComponentList.mNode.mNext[-4] != &UFG::RoadSpaceComponent::s_RoadSpaceComponentList - 4 )
  {
    while ( 1 )
    {
      mNext = p_mNode[4].mNext;
      v7 = (UFG::SimObjectVehicle *)p_mNode[2].mNext;
      v8 = (UFG::qList<UFG::RoadSpaceComponent,UFG::RoadSpaceComponent,1,0> *)&mNext[-4];
      if ( !v7 )
        goto LABEL_24;
      m_Flags = v7->m_Flags;
      if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
        v10 = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(v7);
      else
        v10 = (UFG::AiDriverComponent *)((m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
                                       ? UFG::SimObjectGame::GetComponentOfTypeHK(v7, UFG::AiDriverComponent::_TypeUID)
                                       : UFG::SimObject::GetComponentOfType(v7, UFG::AiDriverComponent::_TypeUID));
      if ( !v10
        || !((unsigned __int8 (__fastcall *)(UFG::AiDriverComponent *))v10->UFG::VehicleDriverInterface::UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr[16].__vecDelDtor)(v10) )
      {
        goto LABEL_24;
      }
      v11 = v7->m_Flags;
      if ( (v11 & 0x4000) != 0 )
        goto LABEL_18;
      if ( v11 >= 0 )
        break;
      ComponentOfType = UFG::SimObjectVehicle::GetComponent<UFG::VehicleSubjectComponent>(v7);
LABEL_20:
      if ( !ComponentOfType
        || !((unsigned __int8 (__fastcall *)(UFG::VehicleSubjectComponent *))ComponentOfType->vfptr[46].__vecDelDtor)(ComponentOfType) )
      {
        m_pTransformNodeComponent = v7->m_pTransformNodeComponent;
        UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
        v14 = pos->y - m_pTransformNodeComponent->mWorldTransform.v3.y;
        if ( (float)((float)((float)((float)(pos->x - m_pTransformNodeComponent->mWorldTransform.v3.x)
                                   * (float)(pos->x - m_pTransformNodeComponent->mWorldTransform.v3.x))
                           + (float)(v14 * v14))
                   + (float)((float)(pos->z - m_pTransformNodeComponent->mWorldTransform.v3.z)
                           * (float)(pos->z - m_pTransformNodeComponent->mWorldTransform.v3.z))) <= (float)(radius * radius) )
        {
          UFG::Simulation::DestroySimObject(&UFG::gSim, v7);
          ++v3;
        }
      }
LABEL_24:
      p_mNode = &v8->mNode;
      if ( v8 == &UFG::RoadSpaceComponent::s_RoadSpaceComponentList - 4 )
        return v3;
    }
    if ( (v11 & 0x2000) == 0 && (v11 & 0x1000) == 0 )
    {
      ComponentOfType = (UFG::VehicleSubjectComponent *)UFG::SimObject::GetComponentOfType(
                                                          v7,
                                                          UFG::VehicleSubjectComponent::_TypeUID);
      goto LABEL_20;
    }
LABEL_18:
    ComponentOfType = (UFG::VehicleSubjectComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                        v7,
                                                        UFG::VehicleSubjectComponent::_TypeUID);
    goto LABEL_20;
  }
  return v3;
}

// File Line: 1123
// RVA: 0x64B2F0
__int64 __fastcall UFG::WheeledVehicleManager::DestroyParkedVehiclesInRange(
        UFG::WheeledVehicleManager *this,
        UFG::qVector3 *pos,
        float radius)
{
  UFG::VehicleOccupantComponent *v3; // rdi
  unsigned int v4; // ebp
  UFG::LinearGraph<float> *v6; // rbx
  UFG::SimObject *m_pSimObject; // rdi
  UFG::TransformNodeComponent *v8; // rsi
  float v9; // xmm0_4
  char *p_mNext; // rsi
  __int64 v11; // rdi
  UFG::SimObject *v12; // rsi
  const float *v13; // rdi
  UFG::StreamedResourceComponent *m_pComponent; // rcx
  UFG::TransformNodeComponent *v15; // rbx
  float v16; // xmm0_4

  v3 = (UFG::VehicleOccupantComponent *)&UFG::VehicleOccupantComponent::s_VehicleOccupantComponentList.mNode.mNext[-4];
  v4 = 0;
  if ( (const float **)&UFG::VehicleOccupantComponent::s_VehicleOccupantComponentList.mNode.mNext[-4] != &stru_142091488.fDomain )
  {
    do
    {
      v6 = (UFG::LinearGraph<float> *)&v3->mNext[-4];
      if ( UFG::VehicleOccupantComponent::IsParked(v3) )
      {
        m_pSimObject = v3->m_pSimObject;
        v8 = m_pSimObject ? m_pSimObject->m_pTransformNodeComponent : 0i64;
        UFG::TransformNodeComponent::UpdateWorldTransform(v8);
        v9 = pos->y - v8->mWorldTransform.v3.y;
        if ( (float)((float)((float)((float)(pos->x - v8->mWorldTransform.v3.x)
                                   * (float)(pos->x - v8->mWorldTransform.v3.x))
                           + (float)(v9 * v9))
                   + (float)((float)(pos->z - v8->mWorldTransform.v3.z) * (float)(pos->z - v8->mWorldTransform.v3.z))) <= (float)(radius * radius) )
        {
          UFG::Simulation::DestroySimObject(&UFG::gSim, m_pSimObject);
          ++v4;
        }
      }
      v3 = (UFG::VehicleOccupantComponent *)v6;
    }
    while ( v6 != (UFG::LinearGraph<float> *)&stru_142091488.fDomain );
  }
  p_mNext = (char *)&UFG::PhysicsMoverInterface::s_PhysicsMoverInterfaceList.mNode.mNext[-5].mNext;
  if ( (const float *)&UFG::PhysicsMoverInterface::s_PhysicsMoverInterfaceList.mNode.mNext[-5].mNext != &A_cos_280_deg_40 )
  {
    do
    {
      v11 = *((_QWORD *)p_mNext + 10);
      v12 = (UFG::SimObject *)*((_QWORD *)p_mNext + 5);
      v13 = (const float *)(v11 - 72);
      if ( v12 )
      {
        m_pComponent = (UFG::StreamedResourceComponent *)v12->m_Components.p[10].m_pComponent;
        if ( m_pComponent )
        {
          if ( UFG::StreamedResourceComponent::GetSpawnPriority(m_pComponent, 0i64)->mUID == qSymbol_Low.mUID )
          {
            v15 = (UFG::TransformNodeComponent *)v12->m_Components.p[2].m_pComponent;
            UFG::TransformNodeComponent::UpdateWorldTransform(v15);
            v16 = pos->z - v15->mWorldTransform.v3.z;
            if ( (float)((float)((float)((float)(pos->y - v15->mWorldTransform.v3.y)
                                       * (float)(pos->y - v15->mWorldTransform.v3.y))
                               + (float)((float)(pos->x - v15->mWorldTransform.v3.x)
                                       * (float)(pos->x - v15->mWorldTransform.v3.x)))
                       + (float)(v16 * v16)) <= (float)(radius * radius) )
            {
              UFG::Simulation::DestroySimObject(&UFG::gSim, v12);
              ++v4;
            }
          }
        }
      }
      p_mNext = (char *)v13;
    }
    while ( v13 != &A_cos_280_deg_40 );
  }
  return v4;
}

// File Line: 1166
// RVA: 0x6575C0
void __fastcall UFG::WheeledVehicleManager::OnVisibleAreaChange(
        UFG::WheeledVehicleManager *this,
        UFG::qArray<UFG::RoadNetworkSubSegment *,0> *deactivateSubSegments,
        UFG::qArray<UFG::RoadNetworkSubSegment *,0> *activateSubSegments)
{
  __int64 v3; // r12
  UFG::qArray<UFG::RoadNetworkSubSegment *,0> *v4; // rax
  UFG::qArray<UFG::RoadNetworkSubSegment *,0> *v5; // rbx
  UFG::WheeledVehicleManager *v6; // rdi
  unsigned int v7; // ebp
  __int64 v8; // rcx
  UFG::RoadNetworkSubSegment *v9; // r13
  UFG::RoadNetworkNode *mParentNode; // r15
  UFG::RoadNetworkLane *Lane; // r14
  UFG::RoadNetworkGuide *p_mNext; // rbx
  __int64 v13; // rdi
  UFG::RoadNetworkLocation *Name; // rax
  UFG::SimObjectCVBase *m_SimObj; // rbx
  __int16 m_Flags; // cx
  UFG::AiDriverComponent *ComponentOfTypeHK; // rax

  v3 = 0i64;
  v4 = activateSubSegments;
  v5 = deactivateSubSegments;
  v6 = this;
  if ( deactivateSubSegments->size )
  {
    do
    {
      v7 = 0;
      v8 = (unsigned int)v3;
      v9 = v5->p[v3];
      mParentNode = v9->mParentNode;
      if ( mParentNode->mNumLanes )
      {
        do
        {
          Lane = UFG::RoadNetworkNode::GetLane(mParentNode, v7);
          p_mNext = (UFG::RoadNetworkGuide *)&Lane->mCars.mNode.mNext[-2].mNext;
          if ( p_mNext != (UFG::RoadNetworkGuide *)&Lane->mStartConnection )
          {
            do
            {
              v13 = (__int64)&p_mNext->mNext[-2].mNext;
              Name = Scaleform::GFx::AS3::Instances::fl::XML::GetName(p_mNext);
              if ( UFG::RoadNetworkSubSegment::IsWithinSubSegment(v9, Lane, Name->m_LaneT) )
              {
                m_SimObj = (UFG::SimObjectCVBase *)p_mNext->m_SimObj;
                if ( m_SimObj )
                {
                  m_Flags = m_SimObj->m_Flags;
                  if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
                  {
                    ComponentOfTypeHK = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(m_SimObj);
                  }
                  else if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
                  {
                    ComponentOfTypeHK = (UFG::AiDriverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                    m_SimObj,
                                                                    UFG::AiDriverComponent::_TypeUID);
                  }
                  else
                  {
                    ComponentOfTypeHK = (UFG::AiDriverComponent *)UFG::SimObject::GetComponentOfType(
                                                                    m_SimObj,
                                                                    UFG::AiDriverComponent::_TypeUID);
                  }
                  if ( ComponentOfTypeHK
                    && ((unsigned __int8 (__fastcall *)(UFG::AiDriverComponent *))ComponentOfTypeHK->UFG::VehicleDriverInterface::UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr[16].__vecDelDtor)(ComponentOfTypeHK) )
                  {
                    UFG::Simulation::DestroySimObject(&UFG::gSim, m_SimObj);
                  }
                }
              }
              p_mNext = (UFG::RoadNetworkGuide *)v13;
            }
            while ( (UFG::qOffset64<UFG::RoadNetworkConnection *> *)v13 != &Lane->mStartConnection );
          }
          ++v7;
        }
        while ( v7 < (unsigned __int8)mParentNode->mNumLanes );
        v5 = deactivateSubSegments;
        v6 = this;
        v8 = (unsigned int)v3;
      }
      UFG::WheeledVehicleManager::DestroyParkedCarsOnSubSegment(v6, v5->p[v8]);
      v3 = (unsigned int)(v3 + 1);
    }
    while ( (unsigned int)v3 < v5->size );
    v4 = activateSubSegments;
  }
  UFG::WheeledVehicleManager::ActivateSubSegments(v6, v4);
}

// File Line: 1225
// RVA: 0x64B080
void __fastcall UFG::WheeledVehicleManager::DestroyCarsOnRoad(
        UFG::WheeledVehicleManager *this,
        UFG::RoadNetworkNode *node)
{
  unsigned int i; // ebp
  UFG::RoadNetworkLane *Lane; // rax
  UFG::qOffset64<UFG::RoadNetworkConnection *> *p_mStartConnection; // rsi
  __int64 p_mNext; // rbx
  __int64 v7; // rdi
  UFG::SimObjectCVBase *v8; // rbx
  __int64 v9; // rdi
  __int16 m_Flags; // cx
  UFG::AiDriverComponent *ComponentOfTypeHK; // rax

  for ( i = 0; i < (unsigned __int8)node->mNumLanes; ++i )
  {
    Lane = UFG::RoadNetworkNode::GetLane(node, i);
    p_mStartConnection = &Lane->mStartConnection;
    p_mNext = (__int64)&Lane->mCars.mNode.mNext[-2].mNext;
    if ( (UFG::qOffset64<UFG::RoadNetworkConnection *> *)p_mNext != &Lane->mStartConnection )
    {
      do
      {
        v7 = *(_QWORD *)(p_mNext + 32);
        v8 = *(UFG::SimObjectCVBase **)(p_mNext + 72);
        v9 = v7 - 24;
        if ( v8 )
        {
          m_Flags = v8->m_Flags;
          if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
          {
            ComponentOfTypeHK = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(v8);
          }
          else if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
          {
            ComponentOfTypeHK = (UFG::AiDriverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                            v8,
                                                            UFG::AiDriverComponent::_TypeUID);
          }
          else
          {
            ComponentOfTypeHK = (UFG::AiDriverComponent *)UFG::SimObject::GetComponentOfType(
                                                            v8,
                                                            UFG::AiDriverComponent::_TypeUID);
          }
          if ( ComponentOfTypeHK )
          {
            if ( ((unsigned __int8 (__fastcall *)(UFG::AiDriverComponent *))ComponentOfTypeHK->UFG::VehicleDriverInterface::UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr[16].__vecDelDtor)(ComponentOfTypeHK) )
              UFG::Simulation::DestroySimObject(&UFG::gSim, v8);
          }
        }
        p_mNext = v9;
      }
      while ( (UFG::qOffset64<UFG::RoadNetworkConnection *> *)v9 != p_mStartConnection );
    }
  }
}

// File Line: 1268
// RVA: 0x64AB10
void __fastcall UFG::WheeledVehicleManager::DestroyAllNonParkedWheeledVehicles(UFG::WheeledVehicleManager *this)
{
  UFG::qNode<UFG::RoadSpaceComponent,UFG::RoadSpaceComponent> *v1; // rbx
  UFG::qNode<UFG::RoadSpaceComponent,UFG::RoadSpaceComponent> *mNext; // rbp
  UFG::SimObjectCVBase *v3; // rbx
  UFG::qVector3 *v4; // rbp
  __int16 m_Flags; // cx
  UFG::AiDriverComponent *ComponentOfTypeHK; // rax
  __int16 v7; // cx
  UFG::AiDriverComponent *v8; // rsi
  UFG::VehicleOccupantComponent *m_pComponent; // rdi
  UFG::SimComponent *ComponentOfType; // rax
  char *p_mNext; // rbx
  __int64 v12; // rbp
  UFG::SimObjectGame *v13; // rbx
  const float *v14; // rbp
  __int16 v15; // cx
  UFG::StreamedResourceComponent *v16; // rsi
  UFG::SimComponent *v17; // rax
  __int16 v18; // cx
  UFG::VehicleOccupantComponent *v19; // rdi
  UFG::SimComponent *v20; // rax

  v1 = UFG::RoadSpaceComponent::s_RoadSpaceComponentList.mNode.mNext - 4;
  if ( (UFG::qVector3 *)&UFG::RoadSpaceComponent::s_RoadSpaceComponentList.mNode.mNext[-4] != &UFG::AiDriverComponent::mCombatBoatOffsets[2] )
  {
    while ( 1 )
    {
      mNext = v1[4].mNext;
      v3 = (UFG::SimObjectCVBase *)v1[2].mNext;
      v4 = (UFG::qVector3 *)&mNext[-4];
      if ( v3 )
        break;
LABEL_24:
      v1 = (UFG::qNode<UFG::RoadSpaceComponent,UFG::RoadSpaceComponent> *)v4;
      if ( v4 == &UFG::AiDriverComponent::mCombatBoatOffsets[2] )
        goto LABEL_25;
    }
    m_Flags = v3->m_Flags;
    if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
    {
      ComponentOfTypeHK = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(v3);
    }
    else if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
    {
      ComponentOfTypeHK = (UFG::AiDriverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                      v3,
                                                      UFG::AiDriverComponent::_TypeUID);
    }
    else
    {
      ComponentOfTypeHK = (UFG::AiDriverComponent *)UFG::SimObject::GetComponentOfType(
                                                      v3,
                                                      UFG::AiDriverComponent::_TypeUID);
    }
    v7 = v3->m_Flags;
    v8 = ComponentOfTypeHK;
    if ( (v7 & 0x4000) != 0 )
      goto LABEL_16;
    if ( v7 < 0 )
    {
      m_pComponent = (UFG::VehicleOccupantComponent *)v3->m_Components.p[30].m_pComponent;
LABEL_19:
      if ( v8
        && ((unsigned __int8 (__fastcall *)(UFG::AiDriverComponent *))v8->UFG::VehicleDriverInterface::UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr[16].__vecDelDtor)(v8)
        && m_pComponent
        && !UFG::VehicleOccupantComponent::IsParked(m_pComponent) )
      {
        UFG::Simulation::DestroySimObject(&UFG::gSim, v3);
      }
      goto LABEL_24;
    }
    if ( (v7 & 0x2000) != 0 || (v7 & 0x1000) != 0 )
LABEL_16:
      ComponentOfType = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::VehicleOccupantComponent::_TypeUID);
    else
      ComponentOfType = UFG::SimObject::GetComponentOfType(v3, UFG::VehicleOccupantComponent::_TypeUID);
    m_pComponent = (UFG::VehicleOccupantComponent *)ComponentOfType;
    goto LABEL_19;
  }
LABEL_25:
  p_mNext = (char *)&UFG::PhysicsMoverInterface::s_PhysicsMoverInterfaceList.mNode.mNext[-5].mNext;
  if ( (const float *)&UFG::PhysicsMoverInterface::s_PhysicsMoverInterfaceList.mNode.mNext[-5].mNext != &A_cos_280_deg_40 )
  {
    while ( 1 )
    {
      v12 = *((_QWORD *)p_mNext + 10);
      v13 = (UFG::SimObjectGame *)*((_QWORD *)p_mNext + 5);
      v14 = (const float *)(v12 - 72);
      if ( v13 )
        break;
LABEL_51:
      p_mNext = (char *)v14;
      if ( v14 == &A_cos_280_deg_40 )
        return;
    }
    v15 = v13->m_Flags;
    if ( (v15 & 0x4000) != 0 )
    {
      v16 = (UFG::StreamedResourceComponent *)v13->m_Components.p[10].m_pComponent;
    }
    else if ( v15 >= 0 )
    {
      if ( (v15 & 0x2000) != 0 )
      {
        v16 = (UFG::StreamedResourceComponent *)v13->m_Components.p[7].m_pComponent;
      }
      else
      {
        if ( (v15 & 0x1000) != 0 )
          v17 = UFG::SimObjectGame::GetComponentOfTypeHK(v13, UFG::StreamedResourceComponent::_TypeUID);
        else
          v17 = UFG::SimObject::GetComponentOfType(v13, UFG::StreamedResourceComponent::_TypeUID);
        v16 = (UFG::StreamedResourceComponent *)v17;
      }
    }
    else
    {
      v16 = (UFG::StreamedResourceComponent *)v13->m_Components.p[10].m_pComponent;
    }
    v18 = v13->m_Flags;
    if ( (v18 & 0x4000) != 0 )
      goto LABEL_43;
    if ( v18 < 0 )
    {
      v19 = (UFG::VehicleOccupantComponent *)v13->m_Components.p[30].m_pComponent;
LABEL_46:
      if ( v16
        && UFG::StreamedResourceComponent::GetSpawnPriority(v16, 0i64)->mUID == qSymbol_Low.mUID
        && v19
        && !UFG::VehicleOccupantComponent::IsParked(v19) )
      {
        UFG::Simulation::DestroySimObject(&UFG::gSim, v13);
      }
      goto LABEL_51;
    }
    if ( (v18 & 0x2000) != 0 || (v18 & 0x1000) != 0 )
LABEL_43:
      v20 = UFG::SimObjectGame::GetComponentOfTypeHK(v13, UFG::VehicleOccupantComponent::_TypeUID);
    else
      v20 = UFG::SimObject::GetComponentOfType(v13, UFG::VehicleOccupantComponent::_TypeUID);
    v19 = (UFG::VehicleOccupantComponent *)v20;
    goto LABEL_46;
  }
}

// File Line: 1300
// RVA: 0x64ADF0
void __fastcall UFG::WheeledVehicleManager::DestroyAllWheeledVehicles(UFG::WheeledVehicleManager *this)
{
  UFG::qNode<UFG::RoadSpaceComponent,UFG::RoadSpaceComponent> *v1; // rbx
  UFG::qNode<UFG::RoadSpaceComponent,UFG::RoadSpaceComponent> *mNext; // rdi
  UFG::SimObjectCVBase *v3; // rbx
  UFG::qVector3 *v4; // rdi
  __int16 m_Flags; // cx
  UFG::AiDriverComponent *v6; // rax
  UFG::qNode<UFG::VehicleOccupantComponent,UFG::VehicleOccupantComponent> *v7; // rbx
  UFG::qNode<UFG::VehicleOccupantComponent,UFG::VehicleOccupantComponent> *v8; // rdi
  UFG::SimObjectGame *v9; // rbx
  UFG::LinearGraph<float> *v10; // rdi
  UFG::VehicleOccupantComponent *ComponentOfType; // rax
  __int16 v12; // cx
  UFG::qList<UFG::PhysicsMoverInterface,UFG::PhysicsMoverInterface,1,0> *p_mNext; // rbx
  UFG::qNode<UFG::PhysicsMoverInterface,UFG::PhysicsMoverInterface> *mPrev; // rdi
  UFG::SimObjectGame *v15; // rbx
  UFG::qList<UFG::PhysicsMoverInterface,UFG::PhysicsMoverInterface,1,0> *v16; // rdi
  __int16 v17; // cx
  UFG::StreamedResourceComponent *m_pComponent; // rax

  v1 = UFG::RoadSpaceComponent::s_RoadSpaceComponentList.mNode.mNext - 4;
  if ( (UFG::qVector3 *)&UFG::RoadSpaceComponent::s_RoadSpaceComponentList.mNode.mNext[-4] != &UFG::AiDriverComponent::mCombatBoatOffsets[2] )
  {
    do
    {
      mNext = v1[4].mNext;
      v3 = (UFG::SimObjectCVBase *)v1[2].mNext;
      v4 = (UFG::qVector3 *)&mNext[-4];
      if ( v3 )
      {
        m_Flags = v3->m_Flags;
        if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
          v6 = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(v3);
        else
          v6 = (UFG::AiDriverComponent *)((m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
                                        ? UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::AiDriverComponent::_TypeUID)
                                        : UFG::SimObject::GetComponentOfType(v3, UFG::AiDriverComponent::_TypeUID));
        if ( v6
          && ((unsigned __int8 (__fastcall *)(UFG::AiDriverComponent *))v6->UFG::VehicleDriverInterface::UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr[16].__vecDelDtor)(v6) )
        {
          UFG::Simulation::DestroySimObject(&UFG::gSim, v3);
        }
      }
      v1 = (UFG::qNode<UFG::RoadSpaceComponent,UFG::RoadSpaceComponent> *)v4;
    }
    while ( v4 != &UFG::AiDriverComponent::mCombatBoatOffsets[2] );
  }
  v7 = UFG::VehicleOccupantComponent::s_VehicleOccupantComponentList.mNode.mNext - 4;
  if ( (const float **)&UFG::VehicleOccupantComponent::s_VehicleOccupantComponentList.mNode.mNext[-4] != &stru_142091488.fDomain )
  {
    do
    {
      v8 = v7[4].mNext;
      v9 = (UFG::SimObjectGame *)v7[2].mNext;
      v10 = (UFG::LinearGraph<float> *)&v8[-4];
      if ( v9 )
      {
        v12 = v9->m_Flags;
        if ( (v12 & 0x4000) != 0 )
          goto LABEL_23;
        if ( v12 >= 0 )
        {
          if ( (v12 & 0x2000) == 0 && (v12 & 0x1000) == 0 )
          {
            ComponentOfType = (UFG::VehicleOccupantComponent *)UFG::SimObject::GetComponentOfType(
                                                                 v9,
                                                                 UFG::VehicleOccupantComponent::_TypeUID);
            goto LABEL_25;
          }
LABEL_23:
          ComponentOfType = (UFG::VehicleOccupantComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                               v9,
                                                               UFG::VehicleOccupantComponent::_TypeUID);
          goto LABEL_25;
        }
        ComponentOfType = (UFG::VehicleOccupantComponent *)v9->m_Components.p[30].m_pComponent;
      }
      else
      {
        ComponentOfType = 0i64;
      }
LABEL_25:
      if ( UFG::VehicleOccupantComponent::IsParked(ComponentOfType) )
        UFG::Simulation::DestroySimObject(&UFG::gSim, v9);
      v7 = (UFG::qNode<UFG::VehicleOccupantComponent,UFG::VehicleOccupantComponent> *)v10;
    }
    while ( v10 != (UFG::LinearGraph<float> *)&stru_142091488.fDomain );
  }
  p_mNext = (UFG::qList<UFG::PhysicsMoverInterface,UFG::PhysicsMoverInterface,1,0> *)&UFG::PhysicsMoverInterface::s_PhysicsMoverInterfaceList.mNode.mNext[-5].mNext;
  if ( (const float *)&UFG::PhysicsMoverInterface::s_PhysicsMoverInterfaceList.mNode.mNext[-5].mNext != &A_cos_280_deg_40 )
  {
    do
    {
      mPrev = p_mNext[5].mNode.mPrev;
      v15 = (UFG::SimObjectGame *)p_mNext[2].mNode.mNext;
      v16 = (UFG::qList<UFG::PhysicsMoverInterface,UFG::PhysicsMoverInterface,1,0> *)&mPrev[-5].mNext;
      if ( v15 )
      {
        v17 = v15->m_Flags;
        if ( (v17 & 0x4000) != 0 )
        {
          m_pComponent = (UFG::StreamedResourceComponent *)v15->m_Components.p[10].m_pComponent;
        }
        else if ( v17 >= 0 )
        {
          if ( (v17 & 0x2000) != 0 )
          {
            m_pComponent = (UFG::StreamedResourceComponent *)v15->m_Components.p[7].m_pComponent;
          }
          else if ( (v17 & 0x1000) != 0 )
          {
            m_pComponent = (UFG::StreamedResourceComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                               v15,
                                                               UFG::StreamedResourceComponent::_TypeUID);
          }
          else
          {
            m_pComponent = (UFG::StreamedResourceComponent *)UFG::SimObject::GetComponentOfType(
                                                               v15,
                                                               UFG::StreamedResourceComponent::_TypeUID);
          }
        }
        else
        {
          m_pComponent = (UFG::StreamedResourceComponent *)v15->m_Components.p[10].m_pComponent;
        }
        if ( m_pComponent )
        {
          if ( UFG::StreamedResourceComponent::GetSpawnPriority(m_pComponent, 0i64)->mUID == qSymbol_Low.mUID )
            UFG::Simulation::DestroySimObject(&UFG::gSim, v15);
        }
      }
      p_mNext = v16;
    }
    while ( v16 != (UFG::qList<UFG::PhysicsMoverInterface,UFG::PhysicsMoverInterface,1,0> *)&A_cos_280_deg_40 );
  }
}

// File Line: 1343
// RVA: 0x64BA90
void __fastcall UFG::WheeledVehicleManager::DestroyWheeledVehiclesInNISBoundingVolume(
        UFG::WheeledVehicleManager *this,
        UFG::qVector3 *aabbMin,
        UFG::qVector3 *aabbMax)
{
  float y; // xmm6_4
  float z; // xmm7_4
  UFG::qNode<UFG::RoadSpaceComponent,UFG::RoadSpaceComponent> *v5; // rbx
  float x; // xmm8_4
  float v7; // xmm9_4
  float v8; // xmm10_4
  float v9; // xmm11_4
  UFG::qNode<UFG::RoadSpaceComponent,UFG::RoadSpaceComponent> *mNext; // rdi
  UFG::SimObjectCVBase *v11; // rbx
  UFG::qVector3 *v12; // rdi
  __int16 m_Flags; // cx
  UFG::AiDriverComponent *v14; // rax
  __int16 v15; // cx
  UFG::SimComponent *m_pComponent; // rax
  float *v17; // rcx
  float v18; // xmm1_4
  float v19; // xmm2_4
  UFG::qNode<UFG::VehicleOccupantComponent,UFG::VehicleOccupantComponent> *v20; // rbx
  UFG::qNode<UFG::VehicleOccupantComponent,UFG::VehicleOccupantComponent> *v21; // rdi
  UFG::SimObjectGame *v22; // rbx
  UFG::LinearGraph<float> *v23; // rdi
  UFG::VehicleOccupantComponent *ComponentOfType; // rax
  __int16 v25; // cx
  __int16 v26; // cx
  UFG::SimComponent *v27; // rax
  float *v28; // rcx
  float v29; // xmm1_4
  float v30; // xmm2_4
  float v31; // xmm1_4
  float v32; // xmm2_4
  char *p_mNext; // rdi
  __int64 v34; // rbx
  UFG::SimObject *v35; // rdi
  const float *v36; // rbx
  UFG::StreamedResourceComponent *v37; // rcx
  UFG::SimComponent *v38; // rcx
  float *v39; // rax
  float v40; // xmm1_4
  float v41; // xmm2_4
  float v42; // xmm1_4
  float v43; // xmm2_4
  UFG::qVector3 max; // [rsp+18h] [rbp-29h] BYREF
  UFG::qVector3 min; // [rsp+28h] [rbp-19h] BYREF

  y = aabbMin->y;
  z = aabbMin->z;
  v5 = UFG::RoadSpaceComponent::s_RoadSpaceComponentList.mNode.mNext - 4;
  x = aabbMax->x;
  v7 = aabbMax->y;
  v8 = aabbMax->z;
  v9 = aabbMin->x;
  if ( (UFG::qVector3 *)&UFG::RoadSpaceComponent::s_RoadSpaceComponentList.mNode.mNext[-4] != &UFG::AiDriverComponent::mCombatBoatOffsets[2] )
  {
    do
    {
      mNext = v5[4].mNext;
      v11 = (UFG::SimObjectCVBase *)v5[2].mNext;
      v12 = (UFG::qVector3 *)&mNext[-4];
      if ( v11 )
      {
        m_Flags = v11->m_Flags;
        if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
          v14 = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(v11);
        else
          v14 = (UFG::AiDriverComponent *)((m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
                                         ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                             v11,
                                             UFG::AiDriverComponent::_TypeUID)
                                         : UFG::SimObject::GetComponentOfType(v11, UFG::AiDriverComponent::_TypeUID));
        if ( v14
          && ((unsigned __int8 (__fastcall *)(UFG::AiDriverComponent *))v14->UFG::VehicleDriverInterface::UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr[16].__vecDelDtor)(v14) )
        {
          v15 = v11->m_Flags;
          if ( (v15 & 0x4000) != 0 )
          {
            m_pComponent = v11->m_Components.p[14].m_pComponent;
          }
          else if ( v15 >= 0 )
          {
            if ( (v15 & 0x2000) != 0 )
              m_pComponent = v11->m_Components.p[9].m_pComponent;
            else
              m_pComponent = (v15 & 0x1000) != 0
                           ? UFG::SimObjectGame::GetComponentOfTypeHK(v11, UFG::CompositeDrawableComponent::_TypeUID)
                           : UFG::SimObject::GetComponentOfType(v11, UFG::CompositeDrawableComponent::_TypeUID);
          }
          else
          {
            m_pComponent = v11->m_Components.p[14].m_pComponent;
          }
          if ( m_pComponent )
          {
            v17 = (float *)m_pComponent[22].m_SafePointerList.mNode.mNext;
            if ( v17 )
            {
              v18 = v17[33];
              v19 = v17[34];
              min.x = v17[32];
              min.y = v18;
              min.z = v19;
              max.z = v17[37];
              TransformAABB((UFG::qMatrix44 *)&m_pComponent[20], &min, &max);
              if ( v9 <= max.x && x >= min.x && y <= max.y && v7 >= min.y && z <= max.z && v8 >= min.z )
                UFG::Simulation::DestroySimObject(&UFG::gSim, v11);
            }
          }
        }
      }
      v5 = (UFG::qNode<UFG::RoadSpaceComponent,UFG::RoadSpaceComponent> *)v12;
    }
    while ( v12 != &UFG::AiDriverComponent::mCombatBoatOffsets[2] );
  }
  v20 = UFG::VehicleOccupantComponent::s_VehicleOccupantComponentList.mNode.mNext - 4;
  if ( (const float **)&UFG::VehicleOccupantComponent::s_VehicleOccupantComponentList.mNode.mNext[-4] != &stru_142091488.fDomain )
  {
    do
    {
      v21 = v20[4].mNext;
      v22 = (UFG::SimObjectGame *)v20[2].mNext;
      v23 = (UFG::LinearGraph<float> *)&v21[-4];
      if ( v22 )
      {
        v25 = v22->m_Flags;
        if ( (v25 & 0x4000) != 0 )
          goto LABEL_40;
        if ( v25 >= 0 )
        {
          if ( (v25 & 0x2000) == 0 && (v25 & 0x1000) == 0 )
          {
            ComponentOfType = (UFG::VehicleOccupantComponent *)UFG::SimObject::GetComponentOfType(
                                                                 v22,
                                                                 UFG::VehicleOccupantComponent::_TypeUID);
            goto LABEL_42;
          }
LABEL_40:
          ComponentOfType = (UFG::VehicleOccupantComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                               v22,
                                                               UFG::VehicleOccupantComponent::_TypeUID);
          goto LABEL_42;
        }
        ComponentOfType = (UFG::VehicleOccupantComponent *)v22->m_Components.p[30].m_pComponent;
      }
      else
      {
        ComponentOfType = 0i64;
      }
LABEL_42:
      if ( UFG::VehicleOccupantComponent::IsParked(ComponentOfType) && v22 )
      {
        v26 = v22->m_Flags;
        if ( (v26 & 0x4000) != 0 )
        {
          v27 = v22->m_Components.p[14].m_pComponent;
        }
        else if ( v26 >= 0 )
        {
          if ( (v26 & 0x2000) != 0 )
            v27 = v22->m_Components.p[9].m_pComponent;
          else
            v27 = (v26 & 0x1000) != 0
                ? UFG::SimObjectGame::GetComponentOfTypeHK(v22, UFG::CompositeDrawableComponent::_TypeUID)
                : UFG::SimObject::GetComponentOfType(v22, UFG::CompositeDrawableComponent::_TypeUID);
        }
        else
        {
          v27 = v22->m_Components.p[14].m_pComponent;
        }
        if ( v27 )
        {
          v28 = (float *)v27[22].m_SafePointerList.mNode.mNext;
          if ( v28 )
          {
            v29 = v28[33];
            v30 = v28[34];
            max.x = v28[32];
            max.y = v29;
            max.z = v30;
            v31 = v28[36];
            v32 = v28[37];
            min.x = v28[35];
            min.y = v31;
            min.z = v32;
            TransformAABB((UFG::qMatrix44 *)&v27[20], &max, &min);
            if ( v9 <= min.x && x >= max.x && y <= min.y && v7 >= max.y && z <= min.z && v8 >= max.z )
              UFG::Simulation::DestroySimObject(&UFG::gSim, v22);
          }
        }
      }
      v20 = (UFG::qNode<UFG::VehicleOccupantComponent,UFG::VehicleOccupantComponent> *)v23;
    }
    while ( v23 != (UFG::LinearGraph<float> *)&stru_142091488.fDomain );
  }
  p_mNext = (char *)&UFG::PhysicsMoverInterface::s_PhysicsMoverInterfaceList.mNode.mNext[-5].mNext;
  if ( (const float *)&UFG::PhysicsMoverInterface::s_PhysicsMoverInterfaceList.mNode.mNext[-5].mNext != &A_cos_280_deg_40 )
  {
    do
    {
      v34 = *((_QWORD *)p_mNext + 10);
      v35 = (UFG::SimObject *)*((_QWORD *)p_mNext + 5);
      v36 = (const float *)(v34 - 72);
      if ( v35 )
      {
        v37 = (UFG::StreamedResourceComponent *)v35->m_Components.p[10].m_pComponent;
        if ( v37 )
        {
          if ( UFG::StreamedResourceComponent::GetSpawnPriority(v37, 0i64)->mUID == qSymbol_Low.mUID )
          {
            v38 = v35->m_Components.p[14].m_pComponent;
            if ( v38 )
            {
              v39 = (float *)v38[22].m_SafePointerList.mNode.mNext;
              if ( v39 )
              {
                v40 = v39[33];
                v41 = v39[34];
                max.x = v39[32];
                max.y = v40;
                max.z = v41;
                v42 = v39[36];
                v43 = v39[37];
                min.x = v39[35];
                min.y = v42;
                min.z = v43;
                TransformAABB((UFG::qMatrix44 *)&v38[20], &max, &min);
                if ( v9 <= min.x && x >= max.x && y <= min.y && v7 >= max.y && z <= min.z && v8 >= max.z )
                  UFG::Simulation::DestroySimObject(&UFG::gSim, v35);
              }
            }
          }
        }
      }
      p_mNext = (char *)v36;
    }
    while ( v36 != &A_cos_280_deg_40 );
  }
}

// File Line: 1473
// RVA: 0x658080
void __fastcall UFG::WheeledVehicleManager::RemoveWheeledVehicleFromList(
        UFG::WheeledVehicleManager *this,
        UFG::SimObjectVehicle *object)
{
  __int64 v3; // rax
  UFG::SimObject **p_m_pPointer; // r8
  int v5; // eax
  UFG::SimObject **i; // rcx
  unsigned int mNumParkedCars; // esi
  UFG::qSafePointerWithCallbacks<UFG::SimObject,UFG::SimObjectVehicle> *v8; // rdi
  UFG::qNode<UFG::qSafePointerWithCallbacksBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v9; // rcx
  UFG::qNode<UFG::qSafePointerWithCallbacksBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v10; // rax
  fastdelegate::detail::GenericClass *v11; // rcx
  unsigned int v12; // eax
  unsigned int mNumTrafficCars; // esi
  UFG::qSafePointerWithCallbacks<UFG::SimObject,UFG::SimObjectVehicle> *v14; // rdi
  UFG::qNode<UFG::qSafePointerWithCallbacksBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerWithCallbacksBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mNext; // rax
  fastdelegate::detail::GenericClass *m_pthis; // rcx
  unsigned int v18; // eax

  v3 = 0i64;
  p_m_pPointer = &this->mTrafficCar[0].m_pPointer;
  do
  {
    if ( object == *p_m_pPointer )
    {
      mNumTrafficCars = this->mNumTrafficCars;
      v14 = &this->mTrafficCar[v3];
      if ( v14->m_pPointer )
      {
        mPrev = v14->mPrev;
        mNext = v14->mNext;
        mPrev->mNext = mNext;
        mNext->mPrev = mPrev;
        v14->mPrev = v14;
        v14->mNext = v14;
        v14->m_Changed = 1;
        m_pthis = v14->m_UnbindCallback.m_Closure.m_pthis;
        if ( m_pthis || v14->m_UnbindCallback.m_Closure.m_pFunction )
          ((void (__fastcall *)(fastdelegate::detail::GenericClass *, UFG::SimObject *))v14->m_UnbindCallback.m_Closure.m_pFunction)(
            m_pthis,
            v14->m_pPointer);
      }
      v14->m_pPointer = 0i64;
      v18 = this->mNumTrafficCars;
      if ( mNumTrafficCars == v18 )
        this->mNumTrafficCars = v18 - 1;
      return;
    }
    v3 = (unsigned int)(v3 + 1);
    p_m_pPointer += 8;
  }
  while ( (unsigned int)v3 < 0x64 );
  v5 = 0;
  for ( i = &this->mParkedCar[0].m_pPointer; object != *i; i += 8 )
  {
    if ( (unsigned int)++v5 >= 0x64 )
      return;
  }
  mNumParkedCars = this->mNumParkedCars;
  v8 = &this->mParkedCar[v5];
  if ( v8->m_pPointer )
  {
    v9 = v8->mPrev;
    v10 = v8->mNext;
    v9->mNext = v10;
    v10->mPrev = v9;
    v8->mPrev = v8;
    v8->mNext = v8;
    v8->m_Changed = 1;
    v11 = v8->m_UnbindCallback.m_Closure.m_pthis;
    if ( v11 || v8->m_UnbindCallback.m_Closure.m_pFunction )
      ((void (__fastcall *)(fastdelegate::detail::GenericClass *, UFG::SimObject *, UFG::SimObject **))v8->m_UnbindCallback.m_Closure.m_pFunction)(
        v11,
        v8->m_pPointer,
        p_m_pPointer);
  }
  v8->m_pPointer = 0i64;
  v12 = this->mNumParkedCars;
  if ( mNumParkedCars == v12 )
    this->mNumParkedCars = v12 - 1;
}

// File Line: 1529
// RVA: 0x657E10
void __fastcall UFG::WheeledVehicleManager::Reinitialize(UFG::WheeledVehicleManager *this)
{
  if ( UFG::ObjectResourceManager::Instance()->mAmbientVehicles.size <= 2 )
  {
    this->m_ReinitializeQueued = 1;
  }
  else
  {
    UFG::RoadNetworkVisibleArea::Reinitialize(this->m_VisibleArea);
    this->m_ReinitializeQueued = 0;
    this->mCurrentSpawnIndex = 0;
  }
  this->m_SecondsQueued = 0.0;
}

// File Line: 1545
// RVA: 0x6517B0
void __fastcall UFG::WheeledVehicleManager::InitLevelData(UFG::WheeledVehicleManager *this)
{
  UFG::qSymbol *v2; // rax
  UFG::TSActor *v3; // rax
  UFG::WheeledVehicleManagerScriptInterface *v4; // rbx
  UFG::SimComponent *v5; // rsi
  UFG::SimObject *m_SimObject; // r8
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *p_mpSimObj; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v10; // rax
  UFG::qMemoryPool *SimulationMemoryPool; // rax
  UFG::allocator::free_link *v12; // rax
  UFG::SimComponent *v13; // rax
  UFG::SimObject *v14; // rdx
  __int16 m_Flags; // cx
  unsigned int v16; // ebx
  UFG::SimObjectModifier v17; // [rsp+38h] [rbp-30h] BYREF
  void *result; // [rsp+70h] [rbp+8h] BYREF

  UFG::RoadNetworkVisibleArea::Init(this->m_VisibleArea, UFG::gpRoadNetworkResource);
  v2 = UFG::qSymbol::create_from_string((UFG::qSymbol *)&result, "RoadNetwork");
  this->m_SimObject = UFG::Simulation::CreateSimObject(&UFG::gSim, v2);
  v3 = (UFG::TSActor *)AMemory::c_malloc_func(0xE0ui64, "WheeledVehicleManagerScriptInterface");
  v4 = (UFG::WheeledVehicleManagerScriptInterface *)v3;
  result = v3;
  v5 = 0i64;
  if ( v3 )
  {
    UFG::TSActor::TSActor(
      v3,
      (ASymbol *)&UFG::WheeledVehicleManagerScriptInterface::mInstanceNameSymbol,
      UFG::WheeledVehicleManagerScriptInterface::mClass);
    v4->vfptr = (SSObjectBaseVtbl *)&UFG::WheeledVehicleManagerScriptInterface::`vftable;
    v4->m_WheeledVehicleManager = this;
    UFG::WheeledVehicleManagerScriptInterface::mScriptInterfaceInstance = v4;
  }
  else
  {
    v4 = 0i64;
  }
  m_SimObject = this->m_SimObject;
  p_mpSimObj = &v4->mpSimObj;
  if ( v4->mpSimObj.m_pPointer )
  {
    mPrev = p_mpSimObj->mPrev;
    mNext = v4->mpSimObj.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_mpSimObj->mPrev = p_mpSimObj;
    v4->mpSimObj.mNext = &v4->mpSimObj;
  }
  v4->mpSimObj.m_pPointer = m_SimObject;
  if ( m_SimObject )
  {
    v10 = m_SimObject->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev;
    v10->mNext = p_mpSimObj;
    p_mpSimObj->mPrev = v10;
    v4->mpSimObj.mNext = &m_SimObject->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode;
    m_SimObject->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev = p_mpSimObj;
  }
  SimulationMemoryPool = UFG::GetSimulationMemoryPool();
  v12 = UFG::qMemoryPool::Allocate(SimulationMemoryPool, 0x58ui64, "WheeledVehicleManager::TSActorComponent", 0i64, 1u);
  result = v12;
  if ( v12 )
  {
    UFG::TSActorComponent::TSActorComponent((UFG::TSActorComponent *)v12, v4);
    v5 = v13;
  }
  v14 = this->m_SimObject;
  m_Flags = v14->m_Flags;
  if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
  {
    v16 = 4;
  }
  else if ( (m_Flags & 0x2000) != 0 )
  {
    v16 = 3;
  }
  else
  {
    v16 = -1;
    if ( (m_Flags & 0x1000) != 0 )
      v16 = 2;
  }
  UFG::SimObjectModifier::SimObjectModifier(&v17, v14, 1);
  UFG::SimObjectModifier::AttachComponent(&v17, v5, v16);
  UFG::SimObjectModifier::Close(&v17);
  UFG::SimObjectModifier::~SimObjectModifier(&v17);
}

// File Line: 1563
// RVA: 0x651430
void __fastcall UFG::WheeledVehicleManager::InitGlobalData(UFG::WheeledVehicleManager *this)
{
  __int64 v2; // rcx
  fastdelegate::FastDelegate1<UFG::SimObject *,void> *p_m_UnbindCallback; // rax
  __int64 v4; // rdx
  fastdelegate::FastDelegate1<UFG::SimObject *,void> *v5; // rax
  AMD_HD3D *v6; // rcx
  AMD_HD3D *v7; // rcx
  AMD_HD3D *v8; // rcx
  bool v9; // al

  UFG::WheeledVehicleNavigationData::InitGlobalData(this->m_NavigationData);
  v2 = 100i64;
  p_m_UnbindCallback = &this->mTrafficCar[0].m_UnbindCallback;
  v4 = 100i64;
  do
  {
    p_m_UnbindCallback->m_Closure.m_pFunction = (void (__fastcall *)(fastdelegate::detail::GenericClass *))UFG::WheeledVehicleManager::TrafficCarBeingDeleted;
    p_m_UnbindCallback->m_Closure.m_pthis = (fastdelegate::detail::GenericClass *)this;
    p_m_UnbindCallback += 4;
    --v4;
  }
  while ( v4 );
  v5 = &this->mParkedCar[0].m_UnbindCallback;
  do
  {
    v5->m_Closure.m_pFunction = (void (__fastcall *)(fastdelegate::detail::GenericClass *))UFG::WheeledVehicleManager::ParkedCarBeingDeleted;
    v5->m_Closure.m_pthis = (fastdelegate::detail::GenericClass *)this;
    v5 += 4;
    --v2;
  }
  while ( v2 );
  _(0i64);
  UFG::BrakingBehavior::AddToTweaker();
  UFG::TrafficCarDebugDrawSettings::AddToTweaker();
  UFG::TrafficSettings::AddToTweaker();
  UFG::AiDriverComponent::AddTweakables();
  _(v6);
  _(v7);
  _(v8);
  v9 = UFG::WheeledVehicleManager::m_TrafficSpawningUpdatesEnabled;
  if ( !UFG::gpRoadNetworkResource )
    v9 = 0;
  UFG::WheeledVehicleManager::m_TrafficSpawningUpdatesEnabled = v9;
  UFG::WheeledVehicleManager::InitLevelData(this);
}

// File Line: 1673
// RVA: 0x657B50
void __fastcall UFG::WheeledVehicleManager::QueueDeletion(
        UFG::WheeledVehicleManager *this,
        UFG::SimObject *pCarToDelete)
{
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *mCarsWithDeletionPending; // rax
  __int64 v3; // r9
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mPrev; // rcx

  mCarsWithDeletionPending = this->mCarsWithDeletionPending;
  v3 = 100i64;
  do
  {
    if ( !mCarsWithDeletionPending->m_pPointer )
    {
      mCarsWithDeletionPending->m_pPointer = pCarToDelete;
      if ( pCarToDelete )
      {
        mPrev = pCarToDelete->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev;
        mPrev->mNext = mCarsWithDeletionPending;
        mCarsWithDeletionPending->mPrev = mPrev;
        mCarsWithDeletionPending->mNext = &pCarToDelete->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode;
        pCarToDelete->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev = mCarsWithDeletionPending;
      }
    }
    ++mCarsWithDeletionPending;
    --v3;
  }
  while ( v3 );
}

// File Line: 1682
// RVA: 0x657EE0
void __fastcall UFG::WheeledVehicleManager::ReleaseGlobalData(UFG::WheeledVehicleManager *this)
{
  AMD_HD3D *v2; // rcx
  AMD_HD3D *v3; // rcx
  AMD_HD3D *v4; // rcx
  AMD_HD3D *v5; // rcx
  AMD_HD3D *v6; // rcx
  AMD_HD3D *v7; // rcx
  AMD_HD3D *v8; // rcx
  UFG::SimObject *m_SimObject; // rcx
  UFG::SimComponent *ComponentOfType; // rax

  UFG::RoadNetworkVisibleArea::Release(this->m_VisibleArea);
  _(v2);
  _(v3);
  _(v4);
  _(v5);
  _(v6);
  _(v7);
  _(v8);
  m_SimObject = this->m_SimObject;
  if ( m_SimObject )
  {
    ComponentOfType = UFG::SimObject::GetComponentOfType(m_SimObject, UFG::RoadNetworkDebugComponent::_TypeUID);
    if ( ComponentOfType )
      UFG::Simulation::DestroySimComponent(&UFG::gSim, ComponentOfType);
  }
}

// File Line: 1710
// RVA: 0x64EB70
__int64 __fastcall UFG::WheeledVehicleManager::GetNumTrams(UFG::WheeledVehicleManager *this)
{
  unsigned int v1; // edi
  UFG::SimObject **p_m_pPointer; // rbx
  __int64 v3; // rsi

  v1 = 0;
  p_m_pPointer = &this->mTrafficCar[0].m_pPointer;
  v3 = 100i64;
  do
  {
    if ( *p_m_pPointer && UFG::SimObjectUtility::IsClassType(*p_m_pPointer, &qSymbol_Tram) )
      ++v1;
    p_m_pPointer += 8;
    --v3;
  }
  while ( v3 );
  return v1;
}

// File Line: 1726
// RVA: 0x65AC90
UFG::SimObjectVehicle *__fastcall UFG::WheeledVehicleManager::SpawnTrafficVehicle(
        UFG::WheeledVehicleManager *this,
        UFG::qPropertySet *vehiclePropSet,
        UFG::RoadNetworkNode *node,
        unsigned int lane,
        float t)
{
  UFG::SimObjectVehicle *WheeledVehicle; // rax
  UFG::RoadNetworkLane *v10; // rax
  UFG::RoadNetworkLane *v11; // rax
  UFG::SimObjectVehicle *v12; // rsi
  UFG::CompositeLookComponent *ComponentOfTypeHK; // rax
  UFG::RoadSpaceComponent *m_pComponent; // rdi
  UFG::RoadNetworkLocation *Name; // rax
  UFG::qSymbol targetClassType; // [rsp+30h] [rbp-38h] BYREF
  UFG::qVector3 result; // [rsp+38h] [rbp-30h] BYREF

  if ( !UFG::WheeledVehicleManager::mTrafficCarSpawningEnabled )
    return 0i64;
  if ( this->mNumTrafficCars >= UFG::WheeledVehicleManager::mMaxTrafficCars )
    return 0i64;
  targetClassType.mUID = qSymbol_Tram.mUID;
  if ( UFG::SimObjectUtility::IsClassType(vehiclePropSet, &targetClassType) )
  {
    if ( (unsigned int)UFG::WheeledVehicleManager::GetNumTrams(this) >= 4 )
      return 0i64;
  }
  v10 = UFG::RoadNetworkNode::GetLane(node, lane);
  if ( UFG::WheeledVehicleManager::IsVehicleSpawnCollision(vehiclePropSet, v10, t) )
    return 0i64;
  v11 = UFG::RoadNetworkNode::GetLane(node, lane);
  UFG::RoadNetworkLane::GetPos(v11, &result, t);
  if ( UFG::WheeledVehicleManager::SpawnLocationContainsObjectConditional(this, vehiclePropSet, &result)
    || UFG::WheeledVehicleManager::IsNearPlayerVehicleGuide(&result) )
  {
    return 0i64;
  }
  WheeledVehicle = UFG::WheeledVehicleManager::CreateWheeledVehicle(this, vehiclePropSet);
  v12 = WheeledVehicle;
  if ( WheeledVehicle )
  {
    ComponentOfTypeHK = (UFG::CompositeLookComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                         WheeledVehicle,
                                                         UFG::CompositeLookComponent::_TypeUID);
    if ( ComponentOfTypeHK )
      UFG::CompositeLookComponent::ForceInvisibleTransparency(ComponentOfTypeHK);
    UFG::WheeledVehicleManager::AttachTrafficAI(this, v12);
    m_pComponent = (UFG::RoadSpaceComponent *)v12->m_Components.p[24].m_pComponent;
    UFG::RoadNetworkGuide::AttachToNetwork(&m_pComponent->mGuide, m_pComponent->m_pSimObject, node, lane, t);
    Name = Scaleform::GFx::AS3::Instances::fl::XML::GetName(&m_pComponent->mGuide);
    UFG::RoadSpaceComponent::MoveCarToRoadNetworkPosition(m_pComponent, Name, 0);
    return v12;
  }
  return WheeledVehicle;
}

// File Line: 1783
// RVA: 0x65AA50
UFG::SimObjectVehicle *__fastcall UFG::WheeledVehicleManager::SpawnParkedVehicle(
        UFG::WheeledVehicleManager *this,
        UFG::qPropertySet *vehiclePropSet,
        UFG::ParkingSpot *spot)
{
  UFG::TransformNodeComponent *mpXformNode; // rbx
  UFG::qVector3 *v8; // rbx
  UFG::RoadNetworkSegment *Segment; // rax
  UFG::RoadNetworkLane *ClosestLane; // rbp
  float mOffset; // xmm6_4
  float v12; // xmm0_4
  UFG::SimObjectVehicle *ParkedWheeledVehicle; // rax
  UFG::SimObjectVehicle *v14; // rsi
  __int16 m_Flags; // dx
  UFG::CompositeLookComponent *ComponentOfTypeHK; // rax
  UFG::allocator::free_link *v17; // rax
  UFG::TeleportEvent *v18; // rbp
  unsigned int mUID; // edi
  UFG::TransformNodeComponent *v20; // rbx

  if ( !UFG::WheeledVehicleManager::mParkedCarSpawningEnabled )
    return 0i64;
  if ( this->mNumParkedCars >= UFG::WheeledVehicleManager::mMaxParkedCars )
    return 0i64;
  mpXformNode = spot->mpXformNode;
  UFG::TransformNodeComponent::UpdateWorldTransform(mpXformNode);
  v8 = (UFG::qVector3 *)&mpXformNode->mWorldTransform.v3;
  if ( UFG::WheeledVehicleManager::SpawnLocationContainsObjectConditional(this, vehiclePropSet, v8)
    || UFG::WheeledVehicleManager::IsNearPlayerVehicleGuide(v8) )
  {
    return 0i64;
  }
  Segment = UFG::RoadNetworkResource::GetSegment(UFG::gpRoadNetworkResource, spot->mRoadSegmentID);
  ClosestLane = UFG::RoadNetworkNode::GetClosestLane(Segment, v8);
  mOffset = ClosestLane->mOffset;
  v12 = UFG::RoadNetworkLane::CalculateParkingOffset(ClosestLane, v8);
  if ( v12 <= mOffset )
    v12 = mOffset;
  ClosestLane->mOffset = v12;
  ParkedWheeledVehicle = UFG::WheeledVehicleManager::CreateParkedWheeledVehicle(this, vehiclePropSet, spot);
  v14 = ParkedWheeledVehicle;
  if ( ParkedWheeledVehicle )
  {
    m_Flags = ParkedWheeledVehicle->m_Flags;
    if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
      ComponentOfTypeHK = (UFG::CompositeLookComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                           ParkedWheeledVehicle,
                                                           UFG::CompositeLookComponent::_TypeUID);
    else
      ComponentOfTypeHK = (UFG::CompositeLookComponent *)UFG::SimObject::GetComponentOfType(
                                                           ParkedWheeledVehicle,
                                                           UFG::CompositeLookComponent::_TypeUID);
    if ( ComponentOfTypeHK )
      UFG::CompositeLookComponent::ForceInvisibleTransparency(ComponentOfTypeHK);
  }
  v17 = UFG::qMalloc(0x90ui64, "TeleportEvent", 0i64);
  v18 = (UFG::TeleportEvent *)v17;
  if ( v17 )
  {
    mUID = v14->mNode.mUID;
    v20 = spot->mpXformNode;
    UFG::TransformNodeComponent::UpdateWorldTransform(v20);
    UFG::TeleportEvent::TeleportEvent(v18, &v20->mWorldTransform, mUID, 0, UFG::TeleportEvent::m_Name, 0);
  }
  UFG::EventDispatcher::DispatchEvent(&UFG::EventDispatcher::mInstance, (UFG::Event *)v17);
  return v14;
}

// File Line: 1832
// RVA: 0x65ED80
void __fastcall UFG::WheeledVehicleManager::TrafficCarBeingDeleted(
        UFG::WheeledVehicleManager *this,
        UFG::SimObject *pDeletedCar)
{
  int v2; // r8d
  UFG::SimObject **i; // rax

  v2 = 0;
  for ( i = &this->mTrafficCar[0].m_pPointer; pDeletedCar != *i; i += 8 )
  {
    if ( (unsigned int)++v2 >= 0x64 )
      return;
  }
  --this->mNumTrafficCars;
}

// File Line: 1845
// RVA: 0x657780
void __fastcall UFG::WheeledVehicleManager::ParkedCarBeingDeleted(
        UFG::WheeledVehicleManager *this,
        UFG::SimObject *pDeletedCar)
{
  int v2; // r8d
  UFG::SimObject **i; // rax

  v2 = 0;
  for ( i = &this->mParkedCar[0].m_pPointer; pDeletedCar != *i; i += 8 )
  {
    if ( (unsigned int)++v2 >= 0x64 )
      return;
  }
  --this->mNumParkedCars;
}

// File Line: 1858
// RVA: 0x651DC0
bool __fastcall UFG::WheeledVehicleManager::IsNearPlayerVehicleGuide(UFG::qVector3 *pos)
{
  signed __int16 m_Flags; // dx
  UFG::CharacterOccupantComponent *ComponentOfType; // rax
  UFG::SimObjectVehicle *CurrentVehicle; // rax
  UFG::SimObjectVehicle *v5; // rdi
  UFG::VehicleSubjectComponent *v6; // rax
  UFG::VehicleSubjectComponent *v7; // rbx
  UFG::SimComponent *m_pComponent; // rdi
  double v9; // xmm0_8
  float v10; // xmm3_4
  float *p_mNext; // rdi
  float v12; // xmm0_4
  float v13; // xmm1_4

  if ( LocalPlayer
    && ((m_Flags = LocalPlayer->m_Flags, (m_Flags & 0x4000) == 0)
      ? (m_Flags >= 0 && (m_Flags & 0x2000) == 0 && (m_Flags & 0x1000) == 0
       ? (ComponentOfType = (UFG::CharacterOccupantComponent *)UFG::SimObject::GetComponentOfType(
                                                                 LocalPlayer,
                                                                 UFG::CharacterOccupantComponent::_TypeUID))
       : (ComponentOfType = (UFG::CharacterOccupantComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                 LocalPlayer,
                                                                 UFG::CharacterOccupantComponent::_TypeUID)))
      : (ComponentOfType = (UFG::CharacterOccupantComponent *)LocalPlayer->m_Components.p[44].m_pComponent),
        ComponentOfType) )
  {
    CurrentVehicle = (UFG::SimObjectVehicle *)UFG::CharacterOccupantComponent::GetCurrentVehicle(ComponentOfType);
    v5 = CurrentVehicle;
    if ( CurrentVehicle )
    {
      v6 = UFG::SimObjectVehicle::GetComponent<UFG::VehicleSubjectComponent>(CurrentVehicle);
      v7 = v6;
      if ( v6
        && ((unsigned __int8 (__fastcall *)(UFG::VehicleSubjectComponent *))v6->vfptr[46].__vecDelDtor)(v6)
        && (m_pComponent = v5->m_Components.p[24].m_pComponent) != 0i64
        && (v9 = ((double (__fastcall *)(UFG::VehicleSubjectComponent *))v7->vfptr[21].__vecDelDtor)(v7),
            v10 = *(float *)&v9,
            (p_mNext = (float *)&m_pComponent[5].m_BoundComponentHandles.mNode.mNext) != 0i64) )
      {
        v12 = pos->y - p_mNext[30];
        v13 = pos->z - p_mNext[31];
        LOBYTE(CurrentVehicle) = (float)((float)(v10 + 20.0) * (float)(v10 + 20.0)) > (float)((float)((float)((float)(pos->x - p_mNext[29]) * (float)(pos->x - p_mNext[29])) + (float)(v12 * v12))
                                                                                            + (float)(v13 * v13));
      }
      else
      {
        LOBYTE(CurrentVehicle) = 0;
      }
    }
  }
  else
  {
    LOBYTE(CurrentVehicle) = 0;
  }
  return (char)CurrentVehicle;
}

// File Line: 1890
// RVA: 0x648380
bool __fastcall UFG::WheeledVehicleManager::CheckSpawnLocationSimple(
        UFG::WheeledVehicleManager *this,
        UFG::qVector3 *position)
{
  float y; // xmm1_4
  UFG::SensorPhantom *mSpawnSensor; // rcx
  UFG::qMatrix44 v6; // [rsp+20h] [rbp-48h] BYREF

  y = position->y;
  mSpawnSensor = this->mSpawnSensor;
  v6.v0 = UFG::qMatrix44::msIdentity.v0;
  v6.v3.y = y;
  LODWORD(v6.v3.w) = (_DWORD)FLOAT_1_0;
  v6.v1 = UFG::qMatrix44::msIdentity.v1;
  v6.v2 = UFG::qMatrix44::msIdentity.v2;
  v6.v3.x = position->x;
  v6.v3.z = position->z;
  UFG::SensorPhantom::SetTransform(mSpawnSensor, &v6);
  return !UFG::WheeledVehicleManager::SensorContainsObject(this);
}

// File Line: 1918
// RVA: 0x65A610
char __fastcall UFG::WheeledVehicleManager::SpawnLocationContainsObjectConditional(
        UFG::WheeledVehicleManager *this,
        UFG::qPropertySet *vehiclePropSet,
        UFG::qVector3 *position)
{
  UFG::SensorPhantom *mSpawnSensor; // rcx
  UFG::SensorPhantom *v6; // rcx
  float y; // xmm1_4
  int nbytes[4]; // [rsp+20h] [rbp-60h] BYREF
  int buf[4]; // [rsp+30h] [rbp-50h] BYREF
  UFG::qMatrix44 transform; // [rsp+40h] [rbp-40h] BYREF

  mSpawnSensor = this->mSpawnSensor;
  *(float *)&nbytes[2] = FLOAT_2_0;
  nbytes[0] = 1077936128;
  *(float *)&buf[2] = FLOAT_N2_0;
  nbytes[1] = 1077936128;
  buf[0] = -1069547520;
  buf[1] = -1069547520;
  Scaleform::Render::WrapperImageSource::GetFormat((hkSubStreamWriter *)mSpawnSensor, buf, (int)nbytes);
  v6 = this->mSpawnSensor;
  y = position->y;
  transform.v0 = UFG::qMatrix44::msIdentity.v0;
  transform.v3.y = y;
  LODWORD(transform.v3.w) = (_DWORD)FLOAT_1_0;
  transform.v1 = UFG::qMatrix44::msIdentity.v1;
  transform.v2 = UFG::qMatrix44::msIdentity.v2;
  transform.v3.x = position->x;
  transform.v3.z = position->z;
  UFG::SensorPhantom::SetTransform(v6, &transform);
  return UFG::WheeledVehicleManager::SensorContainsObjectConditional(this, position);
}

// File Line: 1932
// RVA: 0x658400
char __fastcall UFG::WheeledVehicleManager::SensorContainsObject(UFG::WheeledVehicleManager *this)
{
  _QWORD *v1; // rax
  UFG::SensorPhantomIterator v3; // [rsp+28h] [rbp-20h] BYREF

  UFG::SensorPhantomIterator::SensorPhantomIterator(&v3, this->mSpawnSensor, 0);
  while ( UFG::SensorPhantomIterator::operator*(&v3) )
  {
    v1 = UFG::SensorPhantomIterator::operator*(&v3);
    if ( v1 && v1[10] )
    {
      UFG::SensorPhantomIterator::~SensorPhantomIterator(&v3);
      return 1;
    }
    UFG::SensorPhantomIterator::operator++(&v3);
  }
  UFG::SensorPhantomIterator::~SensorPhantomIterator(&v3);
  return 0;
}

// File Line: 1943
// RVA: 0x658470
char __fastcall UFG::WheeledVehicleManager::SensorContainsObjectConditional(
        UFG::WheeledVehicleManager *this,
        UFG::qVector3 *position)
{
  void *v3; // rax
  UFG::SimObject *v4; // rbx
  float *v5; // rdi
  UFG::StreamedResourceComponent *ComponentOfType; // rax
  UFG::SensorPhantomIterator v8; // [rsp+28h] [rbp-20h] BYREF
  UFG::SpawnInfoInterface::SpawnPriority priority; // [rsp+50h] [rbp+8h] BYREF

  UFG::SensorPhantomIterator::SensorPhantomIterator(&v8, this->mSpawnSensor, 0);
  while ( UFG::SensorPhantomIterator::operator*(&v8) )
  {
    v3 = UFG::SensorPhantomIterator::operator*(&v8);
    v4 = (UFG::SimObject *)v3;
    if ( v3 && *((_QWORD *)v3 + 10) )
    {
      if ( (v5 = (float *)*((_QWORD *)v3 + 11)) != 0i64
        && (UFG::TransformNodeComponent::UpdateWorldTransform(*((UFG::TransformNodeComponent **)v3 + 11)),
            (float)((float)((float)((float)(position->y - v5[45]) * (float)(position->y - v5[45]))
                          + (float)((float)(position->x - v5[44]) * (float)(position->x - v5[44])))
                  + (float)((float)(position->z - v5[46]) * (float)(position->z - v5[46]))) < 1.0)
        || (ComponentOfType = (UFG::StreamedResourceComponent *)UFG::SimObject::GetComponentOfType(
                                                                  v4,
                                                                  UFG::StreamedResourceComponent::_TypeUID)) != 0i64
        && (UFG::StreamedResourceComponent::GetSpawnPriority(ComponentOfType, &priority), priority == UnReferenced) )
      {
        UFG::SensorPhantomIterator::~SensorPhantomIterator(&v8);
        return 1;
      }
    }
    UFG::SensorPhantomIterator::operator++(&v8);
  }
  UFG::SensorPhantomIterator::~SensorPhantomIterator(&v8);
  return 0;
}

// File Line: 1975
// RVA: 0x64B900
void __fastcall UFG::WheeledVehicleManager::DestroyVehiclesOutsideVisibleArea(UFG::WheeledVehicleManager *this)
{
  UFG::qNode<UFG::RoadSpaceComponent,UFG::RoadSpaceComponent> *p_mNode; // rbx
  UFG::SimObject *mNext; // rdi
  UFG::qList<UFG::RoadSpaceComponent,UFG::RoadSpaceComponent,1,0> *v3; // rbp
  __int16 m_Flags; // cx
  UFG::AiDriverComponent *ComponentOfTypeHK; // rax
  bool v6; // zf
  UFG::SimObjectGame *v7; // rcx
  UFG::RoadNetworkGuide *p_mNext; // rbx
  UFG::RoadNetworkLocation *Name; // rax
  UFG::RoadNetworkNode *RoadNetworkNode; // rax
  UFG::RoadNetworkNode *v11; // rsi
  float m_LaneT; // xmm6_4
  UFG::RoadNetworkLocation *v13; // rax
  UFG::RoadNetworkSubSegment *mOffset; // rbx
  UFG::RoadNetworkLane *m_CurrentLane; // r14
  UFG::RoadNetworkSubSegment *p_mIndex; // rsi

  p_mNode = UFG::RoadSpaceComponent::s_RoadSpaceComponentList.mNode.mNext - 4;
  if ( (UFG::qList<UFG::RoadSpaceComponent,UFG::RoadSpaceComponent,1,0> *)&UFG::RoadSpaceComponent::s_RoadSpaceComponentList.mNode.mNext[-4] != &UFG::RoadSpaceComponent::s_RoadSpaceComponentList - 4 )
  {
    while ( 1 )
    {
      mNext = (UFG::SimObject *)p_mNode[2].mNext;
      v3 = (UFG::qList<UFG::RoadSpaceComponent,UFG::RoadSpaceComponent,1,0> *)&p_mNode[4].mNext[-4];
      if ( !mNext )
        goto LABEL_21;
      m_Flags = mNext->m_Flags;
      if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
      {
        ComponentOfTypeHK = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>((UFG::SimObjectCVBase *)p_mNode[2].mNext);
      }
      else if ( (m_Flags & 0x2000) != 0 )
      {
        ComponentOfTypeHK = (UFG::AiDriverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                        (UFG::SimObjectGame *)p_mNode[2].mNext,
                                                        UFG::AiDriverComponent::_TypeUID);
      }
      else
      {
        v6 = (m_Flags & 0x1000) == 0;
        v7 = (UFG::SimObjectGame *)p_mNode[2].mNext;
        ComponentOfTypeHK = (UFG::AiDriverComponent *)(v6
                                                     ? UFG::SimObject::GetComponentOfType(
                                                         v7,
                                                         UFG::AiDriverComponent::_TypeUID)
                                                     : UFG::SimObjectGame::GetComponentOfTypeHK(
                                                         v7,
                                                         UFG::AiDriverComponent::_TypeUID));
      }
      if ( !ComponentOfTypeHK
        || !((unsigned __int8 (__fastcall *)(UFG::AiDriverComponent *))ComponentOfTypeHK->UFG::VehicleDriverInterface::UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr[16].__vecDelDtor)(ComponentOfTypeHK) )
      {
        goto LABEL_21;
      }
      p_mNext = (UFG::RoadNetworkGuide *)&p_mNode[23].mNext;
      if ( !p_mNext->m_Attached )
        goto LABEL_20;
      Name = Scaleform::GFx::AS3::Instances::fl::XML::GetName(p_mNext);
      RoadNetworkNode = UFG::RoadNetworkLocation::GetRoadNetworkNode(Name);
      v11 = RoadNetworkNode;
      if ( !RoadNetworkNode->mActive )
        break;
LABEL_21:
      p_mNode = &v3->mNode;
      if ( v3 == &UFG::RoadSpaceComponent::s_RoadSpaceComponentList - 4 )
        return;
    }
    if ( !RoadNetworkNode->mType.mValue )
    {
      m_LaneT = Scaleform::GFx::AS3::Instances::fl::XML::GetName(p_mNext)->m_LaneT;
      v13 = Scaleform::GFx::AS3::Instances::fl::XML::GetName(p_mNext);
      mOffset = (UFG::RoadNetworkSubSegment *)v11[1].mPathCollection.mOffset;
      m_CurrentLane = v13->m_CurrentLane;
      p_mIndex = (UFG::RoadNetworkSubSegment *)&v11[1].mIndex;
      if ( mOffset != p_mIndex )
      {
        while ( !mOffset->mActive || !UFG::RoadNetworkSubSegment::IsWithinSubSegment(mOffset, m_CurrentLane, m_LaneT) )
        {
          mOffset = (UFG::RoadNetworkSubSegment *)mOffset->mNext;
          if ( mOffset == p_mIndex )
            goto LABEL_20;
        }
        goto LABEL_21;
      }
    }
LABEL_20:
    UFG::Simulation::DestroySimObject(&UFG::gSim, mNext);
    goto LABEL_21;
  }
}

// File Line: 2052
// RVA: 0x6653B0
void __fastcall UFG::WheeledVehicleManager::UpdateVehicleFades(UFG::WheeledVehicleManager *this)
{
  __int64 v1; // rdi
  UFG::SimObject **p_m_pPointer; // rbx
  __int64 v4; // rsi
  UFG::SimObject **v5; // rbx

  v1 = 100i64;
  p_m_pPointer = &this->mTrafficCar[0].m_pPointer;
  v4 = 100i64;
  do
  {
    if ( *p_m_pPointer )
      UFG::WheeledVehicleManager::UpdateVehicleFade(this, (UFG::SimObjectGame *)*p_m_pPointer);
    p_m_pPointer += 8;
    --v4;
  }
  while ( v4 );
  v5 = &this->mParkedCar[0].m_pPointer;
  do
  {
    if ( *v5 )
      UFG::WheeledVehicleManager::UpdateVehicleFade(this, (UFG::SimObjectGame *)*v5);
    v5 += 8;
    --v1;
  }
  while ( v1 );
}

// File Line: 2112
// RVA: 0x665120
void __fastcall UFG::WheeledVehicleManager::UpdateVehicleFade(
        UFG::WheeledVehicleManager *this,
        UFG::SimObjectGame *vehicleObj)
{
  signed __int16 m_Flags; // dx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::CompositeLookComponent *v6; // rdi
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rsi
  signed __int16 v8; // cx
  char isWater; // r14
  float x; // xmm0_4
  float y; // xmm1_4
  float z; // xmm2_4
  bool v13; // si
  float v14; // xmm7_4
  UFG::SimComponent *m_pComponent; // rax
  UFG::RoadNetworkGuide *p_mNext; // rbx
  UFG::RoadNetworkLocation *Name; // rax
  UFG::RoadNetworkIntersection *RoadNetworkNode; // rax
  UFG::RoadNetworkNode *v19; // rbx
  float ValidDistance; // xmm6_4
  UFG::qVector3 result; // [rsp+30h] [rbp-48h] BYREF
  UFG::qVector3 position; // [rsp+40h] [rbp-38h] BYREF

  if ( vehicleObj )
  {
    m_Flags = vehicleObj->m_Flags;
    if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
      ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(vehicleObj, UFG::CompositeLookComponent::_TypeUID);
    else
      ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(vehicleObj, UFG::CompositeLookComponent::_TypeUID);
    v6 = (UFG::CompositeLookComponent *)ComponentOfTypeHK;
    if ( ComponentOfTypeHK )
    {
      m_pTransformNodeComponent = vehicleObj->m_pTransformNodeComponent;
      if ( m_pTransformNodeComponent )
      {
        UFG::RoadNetworkVisibleArea::GetSubjectPosition(this->m_VisibleArea, &result);
        UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
        v8 = vehicleObj->m_Flags;
        isWater = 0;
        x = m_pTransformNodeComponent->mWorldTransform.v3.x;
        y = m_pTransformNodeComponent->mWorldTransform.v3.y;
        z = m_pTransformNodeComponent->mWorldTransform.v3.z;
        v13 = 0;
        position.x = x;
        position.y = y;
        position.z = z;
        v14 = (float)((float)((float)(result.y - y) * (float)(result.y - y))
                    + (float)((float)(result.x - x) * (float)(result.x - x)))
            + (float)((float)(result.z - z) * (float)(result.z - z));
        if ( (v8 & 0x4000) != 0 )
        {
          m_pComponent = vehicleObj->m_Components.p[24].m_pComponent;
        }
        else if ( v8 >= 0 )
        {
          if ( (v8 & 0x2000) != 0 || (v8 & 0x1000) != 0 )
            m_pComponent = UFG::SimObjectGame::GetComponentOfTypeHK(vehicleObj, UFG::RoadSpaceComponent::_TypeUID);
          else
            m_pComponent = UFG::SimObject::GetComponentOfType(vehicleObj, UFG::RoadSpaceComponent::_TypeUID);
        }
        else
        {
          m_pComponent = vehicleObj->m_Components.p[24].m_pComponent;
        }
        if ( m_pComponent )
        {
          p_mNext = (UFG::RoadNetworkGuide *)&m_pComponent[5].m_BoundComponentHandles.mNode.mNext;
          if ( m_pComponent != (UFG::SimComponent *)-376i64
            && UFG::RoadNetworkGuide::IsCurrentLocationValid((UFG::RoadNetworkGuide *)&m_pComponent[5].m_BoundComponentHandles.mNode.mNext)
            && p_mNext->m_Attached )
          {
            Name = Scaleform::GFx::AS3::Instances::fl::XML::GetName(p_mNext);
            RoadNetworkNode = (UFG::RoadNetworkIntersection *)UFG::RoadNetworkLocation::GetRoadNetworkNode(Name);
            v19 = RoadNetworkNode;
            if ( RoadNetworkNode )
            {
              v13 = UFG::RoadNetworkVisibleArea::AllowVisibleExtension(this->m_VisibleArea, RoadNetworkNode);
              isWater = UFG::RoadNetworkNode::IsWater(v19);
            }
          }
        }
        ValidDistance = UFG::RoadNetworkVisibleArea::GetValidDistance(this->m_VisibleArea, &position, v13, 1, isWater);
        if ( v14 < (float)((float)(ValidDistance - 2.0) * (float)(ValidDistance - 2.0))
          && UFG::CompositeLookComponent::HasFadedOut(v6) )
        {
          UFG::CompositeLookComponent::ForceFadeIn(v6);
        }
        if ( v14 > (float)(ValidDistance * ValidDistance) && UFG::CompositeLookComponent::HasFadedIn(v6) )
          UFG::CompositeLookComponent::ForceFadeOut(v6);
      }
    }
  }
}

// File Line: 2156
// RVA: 0x64B4D0
void __fastcall UFG::WheeledVehicleManager::DestroyQueuedVehicles(UFG::WheeledVehicleManager *this)
{
  UFG::SimObject **p_m_pPointer; // rbx
  __int64 v2; // rdi
  __int64 v3; // rcx
  _QWORD *v4; // rax

  p_m_pPointer = &this->mCarsWithDeletionPending[0].m_pPointer;
  v2 = 100i64;
  do
  {
    if ( *p_m_pPointer )
    {
      UFG::Simulation::DestroySimObject(&UFG::gSim, *p_m_pPointer);
      if ( *p_m_pPointer )
      {
        v3 = (__int64)*(p_m_pPointer - 2);
        v4 = *(p_m_pPointer - 1);
        *(_QWORD *)(v3 + 8) = v4;
        *v4 = v3;
        *(p_m_pPointer - 2) = (UFG::SimObject *)(p_m_pPointer - 2);
        *(p_m_pPointer - 1) = (UFG::SimObject *)(p_m_pPointer - 2);
      }
      *p_m_pPointer = 0i64;
    }
    p_m_pPointer += 3;
    --v2;
  }
  while ( v2 );
}

// File Line: 2168
// RVA: 0x65FA60
void __fastcall UFG::WheeledVehicleManager::Update(UFG::WheeledVehicleManager *this, float seconds)
{
  float v4; // xmm1_4
  unsigned int m_PlaceTransitVehicleFrames; // eax
  unsigned int size; // edi
  float m_SecondsQueued; // xmm1_4
  Render::DebugDrawContext *Context; // rax
  float v9; // xmm1_4
  UFG::RoadNetworkResource *v10; // r14
  float VisibleDistance; // xmm8_4
  unsigned int mNumIntersectionsWithLights; // r13d
  unsigned int i; // eax
  unsigned int v14; // r15d
  UFG::RoadNetworkIntersection *IntersectionWithLights; // rdi
  UFG::RoadNetworkIntersection *v16; // rsi
  UFG::qArray<UFG::RoadNetworkSubSegment *,0> activateSubSegments; // [rsp+40h] [rbp-C0h] BYREF
  UFG::qArray<UFG::RoadNetworkSubSegment *,0> deactivateSubSegments; // [rsp+50h] [rbp-B0h] BYREF
  __int64 v19; // [rsp+60h] [rbp-A0h]
  Render::RenderOutputParams outSettings; // [rsp+70h] [rbp-90h] BYREF

  v19 = -2i64;
  Render::RenderOutputParams::RenderOutputParams(&outSettings);
  Render::GetCurrentDisplaySettings(&outSettings);
  if ( last_LOD_setting != outSettings.mLODSetting )
  {
    if ( outSettings.mLODSetting )
    {
      switch ( outSettings.mLODSetting )
      {
        case LOD_SETTING_NORMAL:
          UFG::WheeledVehicleManager::mDefaultMaxParkedCars = 15;
          UFG::WheeledVehicleManager::mDefaultMaxTrafficCars = 22;
          v4 = FLOAT_110_0;
          break;
        case LOD_SETTING_HIGH:
          UFG::WheeledVehicleManager::mDefaultMaxParkedCars = 20;
          UFG::WheeledVehicleManager::mDefaultMaxTrafficCars = 30;
          v4 = FLOAT_130_0;
          break;
        case LOD_SETTING_EXTREME:
          UFG::WheeledVehicleManager::mDefaultMaxParkedCars = 25;
          UFG::WheeledVehicleManager::mDefaultMaxTrafficCars = 34;
          v4 = FLOAT_155_0;
          break;
        default:
LABEL_11:
          UFG::WheeledVehicleManager::ApplyDefaultMaxCars(this);
          UFG::RoadNetworkVisibleArea::SetForceVisibleAreaUpdate(this->m_VisibleArea);
          last_LOD_setting = outSettings.mLODSetting;
          goto LABEL_12;
      }
    }
    else
    {
      UFG::WheeledVehicleManager::mDefaultMaxParkedCars = 11;
      UFG::WheeledVehicleManager::mDefaultMaxTrafficCars = 15;
      v4 = FLOAT_85_0;
    }
    UFG::RoadNetworkVisibleArea::SetVisibleDistance(this->m_VisibleArea, v4);
    goto LABEL_11;
  }
LABEL_12:
  if ( this->m_PlaceTransitVehicleReady )
  {
    m_PlaceTransitVehicleFrames = this->m_PlaceTransitVehicleFrames;
    if ( m_PlaceTransitVehicleFrames )
    {
      this->m_PlaceTransitVehicleFrames = m_PlaceTransitVehicleFrames - 1;
    }
    else
    {
      UFG::TransitUtility::PlaceTransitVehicle();
      UFG::UIHK_NISOverlay::HideCurtains(1.0, 0);
      this->m_PlaceTransitVehicleReady = 0;
      this->m_PlaceTransitVehicleFrames = 0;
    }
  }
  if ( UFG::WheeledVehicleManager::m_TrafficSpawningUpdatesEnabled && this->m_ReinitializeQueued )
  {
    size = UFG::ObjectResourceManager::Instance()->mAmbientVehicles.size;
    if ( size > 2
      || (m_SecondsQueued = this->m_SecondsQueued, m_SecondsQueued > UFG::WheeledVehicleManager::msMaxDelayToReinit)
      || size > 1 && m_SecondsQueued > (float)(UFG::WheeledVehicleManager::msMaxDelayToReinit * 0.5) )
    {
      UFG::RoadNetworkVisibleArea::Reinitialize(this->m_VisibleArea);
      this->m_ReinitializeQueued = 0;
      this->m_SecondsQueued = 0.0;
      this->mCurrentSpawnIndex = 0;
    }
    else
    {
      Context = (Render::DebugDrawContext *)Render::DebugDrawManager::GetContext(
                                              Render::DebugDrawManager::mInstance,
                                              3u);
      Render::DebugDrawContext::DrawTextA(
        Context,
        70,
        505,
        &UFG::qColour::Red,
        "Traffic reset in: %.1f, NumVehicles: %d ",
        (float)(UFG::WheeledVehicleManager::msMaxDelayToReinit - this->m_SecondsQueued),
        size);
    }
    this->m_SecondsQueued = seconds + this->m_SecondsQueued;
  }
  UFG::WheeledVehicleManager::DestroyVehiclesOutsideVisibleArea(this);
  if ( UFG::WheeledVehicleManager::m_TrafficSpawningUpdatesEnabled )
  {
    deactivateSubSegments.p = 0i64;
    *(_QWORD *)&deactivateSubSegments.size = 0i64;
    activateSubSegments.p = 0i64;
    *(_QWORD *)&activateSubSegments.size = 0i64;
    if ( UFG::RoadNetworkVisibleArea::Update(this->m_VisibleArea, &deactivateSubSegments, &activateSubSegments) )
      UFG::WheeledVehicleManager::OnVisibleAreaChange(this, &deactivateSubSegments, &activateSubSegments);
    UFG::WheeledVehicleManager::UpdateTrafficSet(this);
    if ( activateSubSegments.p )
      operator delete[](activateSubSegments.p);
    activateSubSegments.p = 0i64;
    *(_QWORD *)&activateSubSegments.size = 0i64;
    if ( deactivateSubSegments.p )
      operator delete[](deactivateSubSegments.p);
    deactivateSubSegments.p = 0i64;
    *(_QWORD *)&deactivateSubSegments.size = 0i64;
  }
  UFG::WheeledVehicleManager::DestroyQueuedVehicles(this);
  if ( UFG::WheeledVehicleManager::m_TrafficSpawningUpdatesEnabled )
  {
    v9 = this->mSpawnPointExpectedCarsTimer - seconds;
    this->mSpawnPointExpectedCarsTimer = v9;
    if ( v9 < 0.0 )
      UFG::WheeledVehicleManager::UpdateSpawnPointExpectedCars(this);
    UFG::WheeledVehicleManager::UpdateSpawnPoints(this, seconds);
  }
  UFG::WheeledVehicleManager::UpdateVehicleFades(this);
  v10 = UFG::gpRoadNetworkResource;
  if ( UFG::gpRoadNetworkResource )
  {
    UFG::RoadNetworkVisibleArea::GetSubjectPosition(this->m_VisibleArea, (UFG::qVector3 *)&activateSubSegments);
    VisibleDistance = UFG::RoadNetworkVisibleArea::GetVisibleDistance(this->m_VisibleArea);
    mNumIntersectionsWithLights = v10->mNumIntersectionsWithLights;
    i = current_update_index;
    v14 = current_update_index + 10;
    if ( mNumIntersectionsWithLights < current_update_index + 10 )
      v14 = v10->mNumIntersectionsWithLights;
    if ( current_update_index < v14 )
    {
      IntersectionWithLights = UFG::RoadNetworkResource::GetIntersectionWithLights(v10, current_update_index);
      for ( i = current_update_index; current_update_index < v14; i = current_update_index )
      {
        v16 = IntersectionWithLights;
        IntersectionWithLights = 0i64;
        if ( i < v14 - 1 )
        {
          IntersectionWithLights = UFG::RoadNetworkResource::GetIntersectionWithLights(v10, i + 1);
          i = current_update_index;
        }
        current_update_index = i + 1;
        UFG::RoadNetworkIntersection::UpdateLights(
          v16,
          (float)(mNumIntersectionsWithLights / 0xA) * seconds,
          (UFG::qVector3 *)&activateSubSegments,
          VisibleDistance);
      }
    }
    if ( i >= mNumIntersectionsWithLights )
      i = 0;
    current_update_index = i;
  }
  UFG::TrueDirectionManager::Update(this->m_TrueDirectionManager);
}

// File Line: 2508
// RVA: 0x64C6D0
void __fastcall UFG::WheeledVehicleManager::EnableParkedCarSpawning(UFG::WheeledVehicleManager *this, bool enable)
{
  UFG::WheeledVehicleManager::mParkedCarSpawningEnabled = enable;
}

// File Line: 2513
// RVA: 0x6445D0
void __fastcall UFG::WheeledVehicleManager::ActivateSubSegments(
        UFG::WheeledVehicleManager *this,
        UFG::qArray<UFG::RoadNetworkSubSegment *,0> *activateSubSegments)
{
  UFG::qArray<UFG::RoadNetworkSubSegment *,0> *v2; // rbp
  UFG::RoadNetworkSubSegment **v4; // r15
  unsigned int v5; // esi
  unsigned int v6; // r14d
  unsigned __int64 size; // rbx
  unsigned __int64 v8; // rax
  __int64 i; // r12
  unsigned int v10; // ecx
  unsigned int v11; // edi
  unsigned int v12; // ebx
  unsigned __int64 v13; // rax
  UFG::allocator::free_link *v14; // rax
  UFG::RoadNetworkSubSegment **v15; // rbp
  UFG::allocator::free_link *v16; // rdx
  __int64 v17; // r8
  unsigned int mNumTrafficCars; // eax
  unsigned int v19; // r8d
  __int64 v20; // rbx
  __int64 v21; // rdi
  UFG::qArray<UFG::RoadNetworkSubSegment *,0> subSegments; // [rsp+28h] [rbp-50h] BYREF
  UFG::RoadNetworkSubSegment *v24; // [rsp+90h] [rbp+18h]

  v2 = activateSubSegments;
  v4 = 0i64;
  subSegments.p = 0i64;
  v5 = 0;
  *(_QWORD *)&subSegments.size = 0i64;
  v6 = 0;
  size = activateSubSegments->size;
  if ( (_DWORD)size )
  {
    v8 = 8i64 * activateSubSegments->size;
    if ( !is_mul_ok(size, 8ui64) )
      v8 = -1i64;
    v4 = (UFG::RoadNetworkSubSegment **)UFG::qMalloc(v8, "WheeledVehicleManager", 0i64);
    subSegments.p = v4;
    v6 = size;
    subSegments.capacity = size;
  }
  for ( i = 0i64; (unsigned int)i < v2->size; i = (unsigned int)(i + 1) )
  {
    v24 = v2->p[i];
    if ( UFG::WheeledVehicleManager::ShouldSpawnOnSubSegment(this, v24) )
    {
      v10 = v5;
      v11 = v5 + 1;
      if ( v5 + 1 > v6 )
      {
        v12 = 1;
        if ( v6 )
          v12 = 2 * v6;
        for ( ; v12 < v11; v12 *= 2 )
          ;
        if ( v12 <= 2 )
          v12 = 2;
        if ( v12 - v11 > 0x10000 )
          v12 = v5 + 65537;
        if ( v12 != v5 )
        {
          v13 = 8i64 * v12;
          if ( !is_mul_ok(v12, 8ui64) )
            v13 = -1i64;
          v14 = UFG::qMalloc(v13, "qArray.Add", 0i64);
          v15 = (UFG::RoadNetworkSubSegment **)v14;
          if ( v4 )
          {
            if ( v5 )
            {
              v16 = v14;
              v17 = v5;
              do
              {
                v16->mNext = *(UFG::allocator::free_link **)((char *)v16 + (char *)v4 - (char *)v14);
                ++v16;
                --v17;
              }
              while ( v17 );
            }
            operator delete[](v4);
          }
          v4 = v15;
          subSegments.p = v15;
          v6 = v12;
          subSegments.capacity = v12;
          v2 = activateSubSegments;
          v10 = v5;
        }
      }
      ++v5;
      subSegments.size = v11;
      v4[v10] = v24;
    }
  }
  UFG::WheeledVehicleManager::SpawnParkedCars(this, &subSegments);
  mNumTrafficCars = this->mNumTrafficCars;
  if ( mNumTrafficCars < UFG::WheeledVehicleManager::mMaxTrafficCars )
    v19 = UFG::WheeledVehicleManager::mMaxTrafficCars - mNumTrafficCars;
  else
    v19 = 0;
  UFG::WheeledVehicleManager::CalculateVehicleDistribution(this, &subSegments, v19);
  if ( v5 > 0x190 )
    v5 = 400;
  if ( v5 )
  {
    v20 = 0i64;
    v21 = v5;
    do
    {
      UFG::WheeledVehicleManager::CreateTrafficCarsOnSubSegment(
        this,
        this->mSpawningRecordCollection.p[v20].m_pSubSegment,
        this->mSpawningRecordCollection.p[v20].m_NumCarsToSpawn);
      ++v20;
      --v21;
    }
    while ( v21 );
  }
  UFG::WheeledVehicleManager::UpdateSpawnPointExpectedCars(this);
  if ( v4 )
    operator delete[](v4);
}

// File Line: 2570
// RVA: 0x65A140
bool __fastcall UFG::WheeledVehicleManager::ShouldSpawnOnSubSegment(
        UFG::WheeledVehicleManager *this,
        UFG::RoadNetworkSubSegment *subSegment)
{
  UFG::RoadNetworkSegment *mParentNode; // rbp
  UFG::RoadNetworkLane *CenterLane; // rbx
  float BeginT; // xmm0_4
  float EndT; // xmm0_4
  UFG::qVector3 *StartPosition; // rbx
  UFG::qVector3 *PreviousStartPosition; // rax
  float v10; // xmm2_4
  float v11; // xmm0_4
  bool IsWater; // al
  float MinVisibleDistance; // xmm6_4
  bool v14; // al
  UFG::qVector3 result; // [rsp+20h] [rbp-58h] BYREF
  UFG::qVector3 pos; // [rsp+30h] [rbp-48h] BYREF
  UFG::qVector3 v17; // [rsp+40h] [rbp-38h] BYREF
  UFG::qVector3 v18; // [rsp+4Ch] [rbp-2Ch] BYREF

  mParentNode = subSegment->mParentNode;
  CenterLane = UFG::RoadNetworkNode::GetCenterLane(mParentNode);
  BeginT = UFG::RoadNetworkSubSegment::GetBeginT(subSegment, CenterLane->mLaneIndex);
  UFG::RoadNetworkLane::GetPos(CenterLane, &result, BeginT);
  EndT = UFG::RoadNetworkSubSegment::GetEndT(subSegment, CenterLane->mLaneIndex);
  UFG::RoadNetworkLane::GetPos(CenterLane, &pos, EndT);
  StartPosition = UFG::RoadNetworkVisibleArea::GetStartPosition(this->m_VisibleArea, &v17);
  PreviousStartPosition = UFG::RoadNetworkVisibleArea::GetPreviousStartPosition(this->m_VisibleArea, &v18);
  v10 = PreviousStartPosition->y - StartPosition->y;
  v11 = PreviousStartPosition->z - StartPosition->z;
  v14 = 1;
  if ( (float)((float)((float)(v10 * v10)
                     + (float)((float)(PreviousStartPosition->x - StartPosition->x)
                             * (float)(PreviousStartPosition->x - StartPosition->x)))
             + (float)(v11 * v11)) < 900.0 )
  {
    IsWater = UFG::RoadNetworkSegment::IsWater(mParentNode);
    MinVisibleDistance = UFG::RoadNetworkVisibleArea::GetMinVisibleDistance(this->m_VisibleArea, IsWater);
    if ( UFG::RoadNetworkVisibleArea::IsNearStartPosition(this->m_VisibleArea, &result, MinVisibleDistance)
      || UFG::RoadNetworkVisibleArea::IsNearStartPosition(this->m_VisibleArea, &pos, MinVisibleDistance) )
    {
      return 0;
    }
  }
  return v14;
}

// File Line: 2614
// RVA: 0x647510
void __fastcall UFG::WheeledVehicleManager::CalculateVehicleDistribution(
        UFG::WheeledVehicleManager *this,
        UFG::qArray<UFG::RoadNetworkSubSegment *,0> *subSegments,
        int numCarsAvailable)
{
  int v3; // r15d
  UFG::qArray<UFG::RoadNetworkSubSegment *,0> *v4; // r8
  UFG::WheeledVehicleManager *v5; // rsi
  unsigned int size; // r12d
  UFG::qArray<UFG::WheeledVehicleManager::RoadSpawningRecord,0> *p_mSpawningRecordCollection; // rdi
  unsigned int v8; // edx
  int v9; // r14d
  unsigned int capacity; // edx
  unsigned int v11; // edx
  float v12; // xmm7_4
  __int64 v13; // r15
  __int64 v14; // rbx
  __int64 v15; // r13
  UFG::WheeledVehicleManager *v16; // r12
  UFG::RoadNetworkSegment *mParentNode; // rdi
  float RoadDensity; // xmm1_4
  UFG::WheeledVehicleManager::RoadSpawningRecord *p; // rsi
  UFG::RoadNetworkSubSegment *v20; // rcx
  float mLength; // xmm6_4
  UFG::qNode<UFG::RoadBlock,UFG::RoadBlock> *mNext; // rcx
  __int64 p_m_RoadBlockList; // rax
  float v24; // xmm6_4
  int v25; // edi
  float m_MaxNumCarsToSpawn; // xmm0_4
  __int64 **v27; // rdx
  __int64 v28; // r9
  __int64 v29; // r10
  __int64 *v30; // r8
  __int64 **v31; // rcx
  __int64 v32; // rax
  float v33; // xmm7_4
  __int64 *v34; // rcx
  __int64 *v35; // rax
  unsigned int v36; // eax
  unsigned int v37; // ecx
  float v38; // xmm0_4
  __int64 *v39; // rcx
  __int64 *v40; // rax
  __int64 *v41; // rax
  __int64 *v42; // rax
  __int64 *i; // rdx
  __int64 v44; // rcx
  _QWORD *v45; // rax
  UFG::qArray<UFG::RoadNetworkSubSegment *,0> *j; // rcx
  UFG::RoadNetworkSubSegment *v47; // rdx
  UFG::RoadNetworkSubSegment **v48; // rax
  UFG::RoadNetworkSubSegment *v49; // rdx
  UFG::RoadNetworkSubSegment **v50; // rax
  __int64 *v51; // rcx
  _QWORD *v52; // rax
  unsigned int v53; // [rsp+0h] [rbp-49h]
  __int64 *v55; // [rsp+10h] [rbp-39h] BYREF
  void *mem; // [rsp+18h] [rbp-31h]
  UFG::WheeledVehicleManager *v57; // [rsp+B0h] [rbp+67h]
  UFG::qArray<UFG::RoadNetworkSubSegment *,0> *v58; // [rsp+B8h] [rbp+6Fh]
  int mNumLanes; // [rsp+C8h] [rbp+7Fh]

  v3 = numCarsAvailable;
  v4 = subSegments;
  v5 = this;
  size = subSegments->size;
  if ( subSegments->size )
  {
    if ( size > 0x190 )
      size = 400;
    v53 = size;
    p_mSpawningRecordCollection = &this->mSpawningRecordCollection;
    v8 = this->mSpawningRecordCollection.size;
    v9 = 0;
    if ( v8 < size )
    {
      if ( (int)(size - v8) <= 0 )
      {
        if ( v8 != size )
        {
          if ( v8 - size < v8 )
            p_mSpawningRecordCollection->size = size;
          else
            p_mSpawningRecordCollection->size = 0;
        }
      }
      else
      {
        capacity = this->mSpawningRecordCollection.capacity;
        if ( size > capacity )
        {
          if ( capacity )
            v11 = 2 * capacity;
          else
            v11 = 1;
          for ( ; v11 < size; v11 *= 2 )
            ;
          if ( v11 - size > 0x10000 )
            v11 = size + 0x10000;
          UFG::qArray<UFG::WheeledVehicleManager::RoadSpawningRecord,0>::Reallocate(
            &this->mSpawningRecordCollection,
            v11,
            "qArray.Reallocate(Resize)");
          v4 = v58;
        }
        p_mSpawningRecordCollection->size = size;
      }
    }
    v12 = 0.0;
    if ( size )
    {
      v13 = 0i64;
      v14 = 0i64;
      v15 = size;
      v16 = v57;
      while ( 1 )
      {
        mParentNode = v4->p[v13]->mParentNode;
        mNumLanes = (unsigned __int8)mParentNode->mNumLanes;
        RoadDensity = UFG::RoadNetworkSegment::GetRoadDensity(mParentNode);
        p = v16->mSpawningRecordCollection.p;
        *(_QWORD *)&p[v14].m_SpawnWeight = 0i64;
        p[v14].m_NumCarsToSpawn = 0;
        p[v14].m_pSubSegment = 0i64;
        v4 = v58;
        p[v14].m_pSubSegment = v58->p[v13];
        p[v14].m_NumCarsToSpawn = 0;
        v20 = v4->p[v13];
        mLength = v20->mLength;
        if ( (float)(mLength - 8.0) > 0.0 && RoadDensity > 0.0 && v20->mStatus.mValue == 4 )
        {
          mNext = v16->m_NavigationData->m_RoadBlockList.mNode.mNext;
          p_m_RoadBlockList = (__int64)&v16->m_NavigationData->m_RoadBlockList;
          if ( mNext == (UFG::qNode<UFG::RoadBlock,UFG::RoadBlock> *)p_m_RoadBlockList )
          {
LABEL_28:
            v24 = (float)(mLength * RoadDensity) * (float)mNumLanes;
            v25 = (int)v24;
            if ( UFG::qRandom(1.0, (unsigned int *)&UFG::qDefaultSeed) < (float)(v24 - (float)(int)v24) )
              ++v25;
            p[v14].m_MaxNumCarsToSpawn = v25;
            v4 = v58;
            goto LABEL_32;
          }
          while ( (UFG::RoadNetworkSegment *)mNext[1].mNext != mParentNode )
          {
            mNext = mNext->mNext;
            if ( mNext == (UFG::qNode<UFG::RoadBlock,UFG::RoadBlock> *)p_m_RoadBlockList )
              goto LABEL_28;
          }
        }
        p[v14].m_MaxNumCarsToSpawn = 0;
LABEL_32:
        m_MaxNumCarsToSpawn = (float)(int)p[v14].m_MaxNumCarsToSpawn;
        p[v14].m_SpawnWeight = m_MaxNumCarsToSpawn;
        v12 = v12 + m_MaxNumCarsToSpawn;
        ++v14;
        ++v13;
        if ( !--v15 )
        {
          size = v53;
          v5 = v57;
          v3 = numCarsAvailable;
          break;
        }
      }
    }
    v55 = (__int64 *)&v55;
    mem = &v55;
    v27 = &v55;
    if ( size )
    {
      v28 = 0i64;
      v29 = size;
      do
      {
        v30 = (__int64 *)&v5->mSpawningRecordCollection.p[v28];
        v31 = (__int64 **)mem;
        if ( mem == &v55 )
        {
LABEL_37:
          v27[1] = v30;
          *v30 = (__int64)v27;
          v30[1] = (__int64)&v55;
          v27 = (__int64 **)v30;
          v55 = v30;
        }
        else
        {
          while ( *((float *)v30 + 4) >= *((float *)v31 + 4) )
          {
            v31 = (__int64 **)v31[1];
            if ( v31 == &v55 )
              goto LABEL_37;
          }
          v32 = (__int64)*v31;
          *(_QWORD *)(v32 + 8) = v30;
          *v30 = v32;
          v30[1] = (__int64)v31;
          *v31 = v30;
          v27 = (__int64 **)v55;
        }
        ++v28;
        --v29;
      }
      while ( v29 );
    }
    if ( v3 )
    {
      v33 = v12 / (float)v3;
      while ( mem != &v55 )
      {
        v34 = *v27;
        v35 = v27[1];
        v34[1] = (__int64)v35;
        *v35 = (__int64)v34;
        *v27 = (__int64 *)v27;
        v27[1] = (__int64 *)v27;
        v36 = *((_DWORD *)v27 + 5);
        if ( v36 && (v37 = *((_DWORD *)v27 + 6), v37 < v36) )
        {
          *((_DWORD *)v27 + 6) = v37 + 1;
          v38 = *((float *)v27 + 4) - v33;
          *((float *)v27 + 4) = v38;
          v39 = v55;
          if ( v55 == (__int64 *)&v55 )
          {
LABEL_53:
            v41 = (__int64 *)mem;
            mem = v27;
            *v27 = (__int64 *)&v55;
            v27[1] = v41;
            *v41 = (__int64)v27;
          }
          else
          {
            while ( v38 <= *((float *)v39 + 4) )
            {
              v39 = (__int64 *)*v39;
              if ( v39 == (__int64 *)&v55 )
                goto LABEL_53;
            }
            v40 = (__int64 *)v39[1];
            v39[1] = (__int64)v27;
            *v27 = v39;
            v27[1] = v40;
            *v40 = (__int64)v27;
          }
        }
        else
        {
          v42 = (__int64 *)mem;
          mem = v27;
          *v27 = (__int64 *)&v55;
          v27[1] = v42;
          *v42 = (__int64)v27;
          if ( ++v9 == size )
            goto LABEL_57;
        }
        if ( !--v3 )
          goto LABEL_57;
        v27 = (__int64 **)v55;
      }
    }
    else
    {
LABEL_57:
      for ( i = (__int64 *)mem; mem != &v55; i = (__int64 *)mem )
      {
        v44 = *i;
        v45 = (_QWORD *)i[1];
        *(_QWORD *)(v44 + 8) = v45;
        *v45 = v44;
        *i = (__int64)i;
        i[1] = (__int64)i;
      }
    }
    for ( j = (UFG::qArray<UFG::RoadNetworkSubSegment *,0> *)mem;
          mem != &v55;
          j = (UFG::qArray<UFG::RoadNetworkSubSegment *,0> *)mem )
    {
      v47 = *(UFG::RoadNetworkSubSegment **)&j->size;
      v48 = j->p;
      v47->mNext = (UFG::qNode<UFG::RoadNetworkSubSegment,UFG::RoadNetworkSubSegment> *)v48;
      *v48 = v47;
      *(_QWORD *)&j->size = j;
      j->p = (UFG::RoadNetworkSubSegment **)j;
      v58 = j;
      v49 = *(UFG::RoadNetworkSubSegment **)&j->size;
      v50 = j->p;
      v49->mNext = (UFG::qNode<UFG::RoadNetworkSubSegment,UFG::RoadNetworkSubSegment> *)v50;
      *v50 = v49;
      *(_QWORD *)&j->size = j;
      j->p = (UFG::RoadNetworkSubSegment **)j;
      operator delete[](j);
    }
    v51 = v55;
    v52 = mem;
    v55[1] = (__int64)mem;
    *v52 = v51;
  }
}

// File Line: 2761
// RVA: 0x65AC20
void __fastcall UFG::WheeledVehicleManager::SpawnTrafficCarOnSpawnPoint(
        UFG::WheeledVehicleManager *this,
        UFG::RoadNetworkSpawnPoint *spawnPoint)
{
  unsigned int RoadNetworkType; // eax
  UFG::qPropertySet *v5; // rax
  UFG::RoadNetworkLane *mLane; // rcx
  __int64 mOffset; // rdx
  UFG::RoadNetworkNode *v8; // r8

  RoadNetworkType = UFG::RoadNetworkSegment::GetRoadNetworkType(spawnPoint->mSubSegment->mParentNode);
  v5 = UFG::WheeledVehicleManager::ChooseAmbientVehicle(this, RoadNetworkType, Traffic);
  if ( v5 )
  {
    mLane = spawnPoint->mLane;
    mOffset = spawnPoint->mLane->mNode.mOffset;
    if ( mOffset )
      v8 = (UFG::RoadNetworkNode *)((char *)mLane + mOffset);
    else
      v8 = 0i64;
    UFG::WheeledVehicleManager::SpawnTrafficVehicle(
      this,
      v5,
      v8,
      mLane->mLaneIndex,
      spawnPoint->mLane->mSpawnT,
      spawnPoint->mLane->mSpawnT);
  }
}

// File Line: 2797
// RVA: 0x6634E0
// bad sp value at call has been detected, the output may be wrong!
void __fastcall UFG::WheeledVehicleManager::UpdateSpawnPointExpectedCars(UFG::WheeledVehicleManager *this)
{
  UFG::qArray<UFG::RoadNetworkSubSegment *,0> *mPreviousVisibleSubSegments; // rdx
  float size; // xmm6_4
  unsigned int v4; // r15d
  UFG::WheeledVehicleManager::RoadSpawningRecord *p; // rcx
  unsigned int m_NumCarsToSpawn; // r14d
  UFG::RoadNetworkSegment *mParentNode; // rsi
  unsigned int mIndex; // edx
  unsigned int v9; // edi
  UFG::qBaseTreeRB *v10; // rbx
  UFG::allocator::free_link *v11; // rax
  unsigned int v12; // edx
  UFG::qBaseTreeRB *v13; // rax
  UFG::qBaseTreeRB **p_mNULL; // rax
  unsigned int v15; // r14d
  unsigned int v16; // edi
  UFG::qBaseTreeRB *v17; // rbx
  UFG::allocator::free_link *v18; // rax
  UFG::RoadNetworkResource *v19; // rbx
  UFG::qBaseTreeRB *i; // r13
  UFG::RoadNetworkSegment *Segment; // r14
  unsigned int mNumLanes; // esi
  int v23; // edi
  int v24; // r12d
  char v25; // r15
  unsigned int j; // ebx
  UFG::RoadNetworkSpawnPoint *mSpawnPoint; // rcx
  int k; // ebx
  UFG::RoadNetworkSpawnPoint *v29; // rcx
  unsigned int v30; // ebx
  Render::SkinningCacheNode *Head; // rbx
  UFG::qBaseTreeRB v32; // [rsp+10h] [rbp-39h] BYREF
  UFG::qBaseTreeRB *v33; // [rsp+B0h] [rbp+67h] BYREF
  UFG::allocator::free_link *v34; // [rsp+B8h] [rbp+6Fh]

  this->mSpawnPointExpectedCarsTimer = UFG::WheeledVehicleManager::mSpawnPointExpectedCarsMaxTime;
  mPreviousVisibleSubSegments = this->m_VisibleArea->mPreviousVisibleSubSegments;
  size = (float)(int)mPreviousVisibleSubSegments->size;
  if ( size > 400.0 )
    size = FLOAT_400_0;
  UFG::WheeledVehicleManager::CalculateVehicleDistribution(
    this,
    mPreviousVisibleSubSegments,
    UFG::WheeledVehicleManager::mDefaultMaxTrafficCars);
  v33 = &v32;
  UFG::qBaseTreeRB::qBaseTreeRB(&v32);
  v4 = 0;
  if ( size > 0.0 )
  {
    LODWORD(v33) = -1;
    do
    {
      p = this->mSpawningRecordCollection.p;
      m_NumCarsToSpawn = p[v4].m_NumCarsToSpawn;
      mParentNode = p[v4].m_pSubSegment->mParentNode;
      mIndex = mParentNode->mIndex;
      if ( !mIndex || !UFG::qBaseTreeRB::Get(&v32, mIndex) )
      {
        v9 = mParentNode->mIndex;
        if ( !v9 || (v10 = UFG::qBaseTreeRB::Get(&v32, v9)) == 0i64 )
        {
          v11 = UFG::qMalloc(0x28ui64, "qMap::qMapNode32", 0i64);
          v10 = (UFG::qBaseTreeRB *)v11;
          v34 = v11;
          if ( v11 )
          {
            v11->mNext = 0i64;
            v11[1].mNext = 0i64;
            v11[2].mNext = 0i64;
            LODWORD(v11[3].mNext) = v9;
            LODWORD(v11[4].mNext) = 0;
          }
          else
          {
            v10 = 0i64;
          }
          UFG::qBaseTreeRB::Add(&v32, &v10->mRoot);
        }
        LODWORD(v10->mNULL.mParent) = 0;
      }
      v12 = mParentNode->mIndex;
      if ( v12 && (v13 = UFG::qBaseTreeRB::Get(&v32, v12)) != 0i64 )
        p_mNULL = (UFG::qBaseTreeRB **)&v13->mNULL;
      else
        p_mNULL = &v33;
      v15 = *(_DWORD *)p_mNULL + m_NumCarsToSpawn;
      v16 = mParentNode->mIndex;
      if ( !v16 || (v17 = UFG::qBaseTreeRB::Get(&v32, v16)) == 0i64 )
      {
        v18 = UFG::qMalloc(0x28ui64, "qMap::qMapNode32", 0i64);
        v17 = (UFG::qBaseTreeRB *)v18;
        v34 = v18;
        if ( v18 )
        {
          v18->mNext = 0i64;
          v18[1].mNext = 0i64;
          v18[2].mNext = 0i64;
          LODWORD(v18[3].mNext) = v16;
          LODWORD(v18[4].mNext) = v15;
        }
        else
        {
          v17 = 0i64;
        }
        UFG::qBaseTreeRB::Add(&v32, &v17->mRoot);
      }
      LODWORD(v17->mNULL.mParent) = v15;
      ++v4;
    }
    while ( (float)(int)v4 < size );
  }
  v19 = UFG::gpRoadNetworkResource;
  v33 = (UFG::qBaseTreeRB *)UFG::gpRoadNetworkResource;
  for ( i = (UFG::qBaseTreeRB *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&v32);
        i;
        i = UFG::qBaseTreeRB::GetNext(&v32, &i->mRoot) )
  {
    Segment = UFG::RoadNetworkResource::GetSegment(v19, i->mRoot.mUID);
    mNumLanes = (unsigned __int8)Segment->mNumLanes;
    if ( Segment->mNumLanes )
    {
      v23 = LODWORD(i->mNULL.mParent) % mNumLanes;
      v24 = LODWORD(i->mNULL.mParent) / mNumLanes;
      v25 = 0;
      for ( j = 0; j < mNumLanes; ++j )
      {
        mSpawnPoint = UFG::RoadNetworkNode::GetLane(Segment, j)->mSpawnPoint;
        if ( mSpawnPoint )
        {
          mSpawnPoint->mNumExpectedCars = v24;
          v25 = 1;
        }
      }
      if ( v25 )
      {
        for ( k = 0; v23; k = v30 % mNumLanes )
        {
          v29 = UFG::RoadNetworkNode::GetLane(Segment, k)->mSpawnPoint;
          if ( v29 )
          {
            ++v29->mNumExpectedCars;
            --v23;
          }
          v30 = k + 1;
          if ( v30 > mNumLanes )
            v30 = 0;
        }
      }
      v19 = (UFG::RoadNetworkResource *)v33;
    }
  }
  while ( v32.mCount )
  {
    Head = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&v32);
    UFG::qBaseTreeVariableRB<unsigned __int64>::Remove((UFG::qBaseTreeVariableRB<unsigned __int64> *)&v32, &Head->mNode);
    operator delete[](Head);
  }
  v33 = &v32;
  UFG::qBaseTreeRB::~qBaseTreeRB((Render::Skinning *)&v32);
}

// File Line: 2940
// RVA: 0x663810
void __fastcall UFG::WheeledVehicleManager::UpdateSpawnPoints(UFG::WheeledVehicleManager *this, float seconds)
{
  UFG::RoadNetworkVisibleArea *m_VisibleArea; // rbp
  UFG::RoadNetworkSpawnPoint *CurrentEdgeSpawnPoint; // rax
  UFG::RoadNetworkVisibleArea *v5; // rsi
  UFG::RoadNetworkSpawnPoint *v6; // rdi
  UFG::qNode<UFG::RoadBlock,UFG::RoadBlock> *mNext; // rdx
  UFG::qList<UFG::RoadBlock,UFG::RoadBlock,1,0> *p_m_RoadBlockList; // rcx
  unsigned int v9; // edx
  __int64 p_mStartConnection; // rax
  __int64 p_mNext; // rcx
  UFG::RoadNetworkSpawnPoint *v12; // rax
  UFG::RoadNetworkSpawnPoint *v13; // rbx
  unsigned int v14; // r8d
  __int64 v15; // rcx
  __int64 i; // rdx
  UFG::RoadNetworkSpawnPoint *v17; // rdx

  m_VisibleArea = this->m_VisibleArea;
  UFG::RoadNetworkVisibleArea::FirstSpawnPoint(m_VisibleArea);
  if ( !(unsigned __int8)UFG::RoadNetworkVisibleArea::NoMoreSpawnPoints(m_VisibleArea) )
  {
    while ( 1 )
    {
      CurrentEdgeSpawnPoint = UFG::RoadNetworkVisibleArea::GetCurrentEdgeSpawnPoint(m_VisibleArea);
      v5 = this->m_VisibleArea;
      v6 = CurrentEdgeSpawnPoint;
      if ( UFG::RoadNetworkSpawnPoint::Update(CurrentEdgeSpawnPoint, seconds) )
      {
        mNext = this->m_NavigationData->m_RoadBlockList.mNode.mNext;
        p_m_RoadBlockList = &this->m_NavigationData->m_RoadBlockList;
        if ( mNext != (UFG::qNode<UFG::RoadBlock,UFG::RoadBlock> *)p_m_RoadBlockList )
        {
          while ( mNext[1].mNext != (UFG::qNode<UFG::RoadBlock,UFG::RoadBlock> *)v6->mSubSegment->mParentNode )
          {
            mNext = mNext->mNext;
            if ( mNext == (UFG::qNode<UFG::RoadBlock,UFG::RoadBlock> *)p_m_RoadBlockList )
              goto LABEL_6;
          }
          goto LABEL_24;
        }
LABEL_6:
        if ( UFG::RoadNetworkSpawnPoint::CanSpawnCar(v6) )
          break;
      }
LABEL_24:
      UFG::RoadNetworkVisibleArea::NextSpawnPoint(m_VisibleArea);
      if ( (unsigned __int8)UFG::RoadNetworkVisibleArea::NoMoreSpawnPoints(m_VisibleArea) )
        return;
    }
    v9 = 0;
    p_mStartConnection = (__int64)&v6->mLane->mStartConnection;
    p_mNext = (__int64)&v6->mLane->mCars.mNode.mNext[-2].mNext;
    if ( p_mNext != p_mStartConnection )
    {
      do
      {
        ++v9;
        p_mNext = *(_QWORD *)(p_mNext + 32) - 24i64;
      }
      while ( p_mNext != p_mStartConnection );
      if ( v9 )
        goto LABEL_20;
    }
    if ( v6->mNumExpectedCars )
    {
LABEL_20:
      if ( v6->mNumExpectedCars > v9 )
      {
        v17 = v6;
LABEL_22:
        UFG::WheeledVehicleManager::SpawnTrafficCarOnSpawnPoint(this, v17);
      }
    }
    else
    {
      UFG::RoadNetworkVisibleArea::FirstSpawnPoint(v5);
      if ( !(unsigned __int8)UFG::RoadNetworkVisibleArea::NoMoreSpawnPoints(v5) )
      {
        while ( 1 )
        {
          v12 = UFG::RoadNetworkVisibleArea::GetCurrentEdgeSpawnPoint(v5);
          v13 = v12;
          if ( v12 != v6 && UFG::RoadNetworkSpawnPoint::CanSpawnCar(v12) )
          {
            v14 = 0;
            v15 = (__int64)&v13->mLane->mStartConnection;
            for ( i = (__int64)&v13->mLane->mCars.mNode.mNext[-2].mNext; i != v15; i = *(_QWORD *)(i + 32) - 24i64 )
              ++v14;
            if ( v13->mNumExpectedCars > v14 )
              break;
          }
          UFG::RoadNetworkVisibleArea::NextSpawnPoint(v5);
          if ( (unsigned __int8)UFG::RoadNetworkVisibleArea::NoMoreSpawnPoints(v5) )
            goto LABEL_23;
        }
        v17 = v13;
        goto LABEL_22;
      }
    }
LABEL_23:
    UFG::RoadNetworkSpawnPoint::Reset(v6);
    goto LABEL_24;
  }
}

// File Line: 2950
// RVA: 0x65A6F0
void __fastcall UFG::WheeledVehicleManager::SpawnParkedCars(
        UFG::WheeledVehicleManager *this,
        UFG::qArray<UFG::RoadNetworkSubSegment *,0> *subSegments)
{
  UFG::qArray<UFG::RoadNetworkSubSegment *,0> *v2; // rax
  UFG::WheeledVehicleManager *v3; // r9
  unsigned int size; // r10d
  UFG::qArray<UFG::WheeledVehicleManager::RoadSpawningRecord,0> *p_mParkingSpawningRecordCollection; // rsi
  unsigned int v6; // ecx
  __int64 v7; // rdi
  unsigned int v8; // ebx
  unsigned int capacity; // edx
  unsigned int v10; // edx
  int v11; // r12d
  __int64 *v12; // rdx
  __int64 v13; // r15
  __int64 v14; // r14
  __int64 v15; // r13
  UFG::RoadNetworkSubSegment **p; // rax
  __int64 v17; // rsi
  UFG::RoadNetworkSegment *v18; // rbx
  __int64 **v19; // rcx
  __int64 *v20; // rax
  __int64 *v21; // rax
  __int64 v22; // rax
  unsigned int mNumParkedCars; // eax
  unsigned int v24; // r8d
  __int64 v25; // rcx
  __int64 *v26; // rax
  float v27; // xmm0_4
  __int64 **v28; // rcx
  __int64 *v29; // rax
  __int64 v30; // rbx
  UFG::WheeledVehicleManager::RoadSpawningRecord *v31; // rdx
  unsigned int m_NumCarsToSpawn; // r8d
  __int64 *i; // rdx
  __int64 v34; // rcx
  _QWORD *v35; // rax
  __int64 *j; // rcx
  __int64 v37; // rdx
  _QWORD *v38; // rax
  __int64 v39; // rdx
  _QWORD *v40; // rax
  __int64 *v41; // rcx
  _QWORD *v42; // rax
  __int64 *v43; // [rsp+28h] [rbp-20h] BYREF
  void *mem; // [rsp+30h] [rbp-18h]
  unsigned int v47; // [rsp+A0h] [rbp+58h]
  int NumAvailableParkingSpots; // [rsp+A8h] [rbp+60h]

  v2 = subSegments;
  v3 = this;
  size = subSegments->size;
  if ( subSegments->size )
  {
    if ( size > 0x190 )
      size = 400;
    v47 = size;
    p_mParkingSpawningRecordCollection = &this->mParkingSpawningRecordCollection;
    v6 = this->mParkingSpawningRecordCollection.size;
    v7 = 0i64;
    if ( v6 < size )
    {
      if ( (int)(size - v6) <= 0 )
      {
        if ( v6 != size )
        {
          if ( v6 - size < v6 )
            p_mParkingSpawningRecordCollection->size = size;
          else
            p_mParkingSpawningRecordCollection->size = 0;
        }
      }
      else
      {
        v8 = size;
        capacity = v3->mParkingSpawningRecordCollection.capacity;
        if ( size > capacity )
        {
          if ( capacity )
            v10 = 2 * capacity;
          else
            v10 = 1;
          for ( ; v10 < size; v10 *= 2 )
            ;
          if ( v10 - size > 0x10000 )
            v10 = size + 0x10000;
          UFG::qArray<UFG::WheeledVehicleManager::RoadSpawningRecord,0>::Reallocate(
            &v3->mParkingSpawningRecordCollection,
            v10,
            "qArray.Reallocate(Resize)");
          v3 = this;
          size = v47;
        }
        p_mParkingSpawningRecordCollection->size = v8;
      }
      v2 = subSegments;
    }
    v11 = 0;
    v43 = (__int64 *)&v43;
    mem = &v43;
    v12 = (__int64 *)&v43;
    if ( size )
    {
      v13 = 0i64;
      v14 = 0i64;
      v15 = size;
      do
      {
        p = v2->p;
        v17 = (__int64)p[v14];
        if ( *(_WORD *)(v17 + 44) == 4 )
        {
          v18 = *(UFG::RoadNetworkSegment **)(v17 + 16);
          NumAvailableParkingSpots = UFG::RoadNetworkSubSegment::GetNumAvailableParkingSpots(p[v14]);
          UFG::RoadNetworkSegment::GetRoadDensity(v18);
          v3 = this;
          v12 = (__int64 *)&this->mParkingSpawningRecordCollection.p[v13];
          *((_DWORD *)v12 + 6) = 0;
          v12[4] = v17;
          *((_DWORD *)v12 + 5) = NumAvailableParkingSpots;
          *((float *)v12 + 4) = (float)NumAvailableParkingSpots;
          v19 = (__int64 **)mem;
          if ( mem == &v43 )
          {
            v20 = v43;
            v43[1] = (__int64)v12;
            *v12 = (__int64)v20;
            v12[1] = (__int64)&v43;
            v43 = v12;
          }
          else
          {
            while ( (float)NumAvailableParkingSpots >= *((float *)v19 + 4) )
            {
              v19 = (__int64 **)v19[1];
              if ( v19 == &v43 )
              {
                v21 = v43;
                v43[1] = (__int64)v12;
                *v12 = (__int64)v21;
                v12[1] = (__int64)&v43;
                v43 = v12;
                goto LABEL_30;
              }
            }
            v22 = (__int64)*v19;
            *(_QWORD *)(v22 + 8) = v12;
            *v12 = v22;
            v12[1] = (__int64)v19;
            *v19 = v12;
            v12 = v43;
          }
LABEL_30:
          v11 += NumAvailableParkingSpots;
        }
        ++v14;
        ++v13;
        --v15;
        v2 = subSegments;
      }
      while ( v15 );
      size = v47;
    }
    mNumParkedCars = v3->mNumParkedCars;
    if ( mNumParkedCars < UFG::WheeledVehicleManager::mMaxParkedCars )
      v24 = UFG::WheeledVehicleManager::mMaxParkedCars - mNumParkedCars;
    else
      v24 = 0;
    if ( v11 && v24 )
    {
      while ( 1 )
      {
        v25 = *v12;
        v26 = (__int64 *)v12[1];
        *(_QWORD *)(v25 + 8) = v26;
        *v26 = v25;
        *v12 = (__int64)v12;
        v12[1] = (__int64)v12;
        ++*((_DWORD *)v12 + 6);
        v27 = *((float *)v12 + 4) - 1.0;
        *((float *)v12 + 4) = v27;
        v28 = (__int64 **)v43;
        if ( v43 == (__int64 *)&v43 )
        {
LABEL_43:
          v29 = (__int64 *)mem;
          mem = v12;
          v28 = &v43;
        }
        else
        {
          while ( v27 <= *((float *)v28 + 4) )
          {
            v28 = (__int64 **)*v28;
            if ( v28 == &v43 )
              goto LABEL_43;
          }
          v29 = v28[1];
          v28[1] = v12;
        }
        *v12 = (__int64)v28;
        v12[1] = (__int64)v29;
        *v29 = (__int64)v12;
        if ( !--v24 )
          break;
        v12 = v43;
      }
      if ( size )
      {
        v30 = size;
        do
        {
          v31 = v3->mParkingSpawningRecordCollection.p;
          m_NumCarsToSpawn = v31[v7].m_NumCarsToSpawn;
          if ( m_NumCarsToSpawn )
          {
            UFG::WheeledVehicleManager::CreateParkedCarsOnSubSegment(v3, v31[v7].m_pSubSegment, m_NumCarsToSpawn);
            v3 = this;
          }
          ++v7;
          --v30;
        }
        while ( v30 );
      }
    }
    for ( i = (__int64 *)mem; mem != &v43; i = (__int64 *)mem )
    {
      v34 = *i;
      v35 = (_QWORD *)i[1];
      *(_QWORD *)(v34 + 8) = v35;
      *v35 = v34;
      *i = (__int64)i;
      i[1] = (__int64)i;
    }
    for ( j = (__int64 *)mem; mem != &v43; j = (__int64 *)mem )
    {
      v37 = *j;
      v38 = (_QWORD *)j[1];
      *(_QWORD *)(v37 + 8) = v38;
      *v38 = v37;
      *j = (__int64)j;
      j[1] = (__int64)j;
      v39 = *j;
      v40 = (_QWORD *)j[1];
      *(_QWORD *)(v39 + 8) = v40;
      *v40 = v39;
      *j = (__int64)j;
      j[1] = (__int64)j;
      operator delete[](j);
    }
    v41 = v43;
    v42 = mem;
    v43[1] = (__int64)mem;
    *v42 = v41;
  }
}

// File Line: 3057
// RVA: 0x665070
char __fastcall UFG::WheeledVehicleManager::UpdateTrafficSet(UFG::WheeledVehicleManager *this)
{
  char v1; // di
  UFG::SimComponent *ClosestTrafficRegion; // r8
  UFG::qSafePointer<UFG::SimComponent,UFG::TrafficRegion> *p_mCurrentTrafficRegion; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v8; // rax
  UFG::SimComponent *m_pPointer; // rax

  v1 = 0;
  if ( !UFG::WheeledVehicleManager::mUpdateTrafficRegionEnabled )
    return 0;
  ClosestTrafficRegion = (UFG::SimComponent *)UFG::WheeledVehicleManager::GetClosestTrafficRegion(this);
  if ( ClosestTrafficRegion != this->mCurrentTrafficRegion.m_pPointer )
  {
    p_mCurrentTrafficRegion = &this->mCurrentTrafficRegion;
    if ( this->mCurrentTrafficRegion.m_pPointer )
    {
      mPrev = p_mCurrentTrafficRegion->mPrev;
      mNext = this->mCurrentTrafficRegion.mNext;
      mPrev->mNext = mNext;
      mNext->mPrev = mPrev;
      p_mCurrentTrafficRegion->mPrev = p_mCurrentTrafficRegion;
      this->mCurrentTrafficRegion.mNext = &this->mCurrentTrafficRegion;
    }
    this->mCurrentTrafficRegion.m_pPointer = ClosestTrafficRegion;
    if ( ClosestTrafficRegion )
    {
      v8 = ClosestTrafficRegion->m_SafePointerList.mNode.mPrev;
      v8->mNext = p_mCurrentTrafficRegion;
      p_mCurrentTrafficRegion->mPrev = v8;
      this->mCurrentTrafficRegion.mNext = &ClosestTrafficRegion->m_SafePointerList.mNode;
      ClosestTrafficRegion->m_SafePointerList.mNode.mPrev = p_mCurrentTrafficRegion;
    }
    m_pPointer = this->mCurrentTrafficRegion.m_pPointer;
    if ( m_pPointer )
    {
      if ( m_pPointer->m_pSimObject )
      {
        v1 = 1;
        UFG::ObjectResourceManager::Instance()->mEntityStates[1].mUpdateRequired = 1;
      }
    }
  }
  return v1;
}

// File Line: 3097
// RVA: 0x64D9D0
UFG::qSymbol *__fastcall UFG::WheeledVehicleManager::GetCurrentTrafficSet(
        UFG::WheeledVehicleManager *this,
        UFG::qSymbol *result)
{
  unsigned int mUID; // edx
  UFG::TrafficRegion *m_pPointer; // rcx
  UFG::SimObject *m_pSimObject; // rdx

  mUID = this->m_TrafficSetOverride.mUID;
  if ( mUID == UFG::gNullQSymbol.mUID )
  {
    m_pPointer = (UFG::TrafficRegion *)this->mCurrentTrafficRegion.m_pPointer;
    if ( m_pPointer && (m_pSimObject = m_pPointer->m_pSimObject) != 0i64 && m_pSimObject->m_pSceneObj )
    {
      UFG::TrafficRegion::GetSpawnSet_UseTimeSetIfPresent(m_pPointer, result);
      return result;
    }
    else
    {
      result->mUID = UFG::gNullQSymbol.mUID;
      return result;
    }
  }
  else
  {
    result->mUID = mUID;
    return result;
  }
}

// File Line: 3115
// RVA: 0x64D8B0
UFG::qNode<UFG::TrafficRegion,UFG::TrafficRegion> *__fastcall UFG::WheeledVehicleManager::GetClosestTrafficRegion(
        UFG::WheeledVehicleManager *this)
{
  float v1; // xmm6_4
  UFG::qNode<UFG::TrafficRegion,UFG::TrafficRegion> *v2; // rax
  UFG::qNode<UFG::TrafficRegion,UFG::TrafficRegion> *v3; // r8
  UFG::qList<UFG::TrafficRegion,UFG::TrafficRegion,1,0> *v4; // rcx
  UFG::qVector3 result; // [rsp+20h] [rbp-28h] BYREF

  v1 = FLOAT_3_4028235e38;
  UFG::RoadNetworkVisibleArea::GetSubjectPosition(this->m_VisibleArea, &result);
  v2 = UFG::TrafficRegion::s_TrafficRegionList.mNode.mNext - 7;
  v3 = 0i64;
  if ( (UFG::qList<UFG::TrafficRegion,UFG::TrafficRegion,1,0> *)&UFG::TrafficRegion::s_TrafficRegionList.mNode.mNext[-7] != &UFG::TrafficRegion::s_TrafficRegionList - 7 )
  {
    do
    {
      v4 = (UFG::qList<UFG::TrafficRegion,UFG::TrafficRegion,1,0> *)&v2[7].mNext[-7];
      if ( (float)((float)((float)((float)(*(float *)&v2[10].mPrev - result.y)
                                 * (float)(*(float *)&v2[10].mPrev - result.y))
                         + (float)((float)(*((float *)&v2[9].mNext + 1) - result.x)
                                 * (float)(*((float *)&v2[9].mNext + 1) - result.x)))
                 + (float)((float)(*((float *)&v2[10].mPrev + 1) - result.z)
                         * (float)(*((float *)&v2[10].mPrev + 1) - result.z))) < v1 )
      {
        v1 = (float)((float)((float)(*(float *)&v2[10].mPrev - result.y) * (float)(*(float *)&v2[10].mPrev - result.y))
                   + (float)((float)(*((float *)&v2[9].mNext + 1) - result.x)
                           * (float)(*((float *)&v2[9].mNext + 1) - result.x)))
           + (float)((float)(*((float *)&v2[10].mPrev + 1) - result.z)
                   * (float)(*((float *)&v2[10].mPrev + 1) - result.z));
        v3 = v2;
      }
      v2 = v2[7].mNext - 7;
    }
    while ( v4 != &UFG::TrafficRegion::s_TrafficRegionList - 7 );
  }
  return v3;
}

// File Line: 3202
// RVA: 0x15738F0
__int64 dynamic_initializer_for__UFG::WheeledVehicleManagerScriptInterface::mScriptClassNameSymbol__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::WheeledVehicleManagerScriptInterface::mScriptClassNameSymbol__);
}

// File Line: 3203
// RVA: 0x1573860
__int64 dynamic_initializer_for__UFG::WheeledVehicleManagerScriptInterface::mInstanceNameSymbol__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::WheeledVehicleManagerScriptInterface::mInstanceNameSymbol__);
}

// File Line: 3219
// RVA: 0x647360
void UFG::WheeledVehicleManagerScriptInterface::BindAtomics(void)
{
  void (__fastcall *v0)(UFG::WheeledVehicleManagerScriptInterface *, SSInvokedMethod *, SSInstance **); // [rsp+20h] [rbp-10h] BYREF
  int v1; // [rsp+28h] [rbp-8h]
  UFG::qSymbol result; // [rsp+40h] [rbp+10h] BYREF

  UFG::WheeledVehicleManagerScriptInterface::mScriptClassNameSymbol.mUID = UFG::qSymbol::create_from_string(
                                                                             &result,
                                                                             UFG::WheeledVehicleManagerScriptInterface::mScriptClassName)->mUID;
  UFG::WheeledVehicleManagerScriptInterface::mInstanceNameSymbol.mUID = UFG::qSymbol::create_from_string(
                                                                          &result,
                                                                          UFG::WheeledVehicleManagerScriptInterface::mInstanceName)->mUID;
  v0 = UFG::WheeledVehicleManagerScriptInterface::Mthd_EnableTraffic;
  v1 = 0;
  UFG::WheeledVehicleManagerScriptInterface::mClass = (SSActorClass *)SSBrain::get_class((ASymbol *)&UFG::WheeledVehicleManagerScriptInterface::mScriptClassNameSymbol);
  SSClass::register_method_mthd(
    UFG::WheeledVehicleManagerScriptInterface::mClass,
    "enable_traffic_",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v0,
    SSBindFlag_instance_no_rebind);
  v1 = 0;
  v0 = UFG::WheeledVehicleManagerScriptInterface::Mthd_SetTrafficDensityScale;
  SSClass::register_method_mthd(
    UFG::WheeledVehicleManagerScriptInterface::mClass,
    "set_traffic_density_scale",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v0,
    SSBindFlag_instance_no_rebind);
  v1 = 0;
  v0 = UFG::WheeledVehicleManagerScriptInterface::Mthd_ClearTraffic;
  SSClass::register_method_mthd(
    UFG::WheeledVehicleManagerScriptInterface::mClass,
    "clear_traffic",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v0,
    SSBindFlag_instance_no_rebind);
  v1 = 0;
  v0 = UFG::WheeledVehicleManagerScriptInterface::Mthd_ClearNonParkedTraffic;
  SSClass::register_method_mthd(
    UFG::WheeledVehicleManagerScriptInterface::mClass,
    "clear_non_parked_traffic",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v0,
    SSBindFlag_instance_no_rebind);
  v1 = 0;
  v0 = UFG::WheeledVehicleManagerScriptInterface::Mthd_LockTrafficSystem;
  SSClass::register_method_mthd(
    UFG::WheeledVehicleManagerScriptInterface::mClass,
    "lock_traffic_system",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v0,
    SSBindFlag_instance_no_rebind);
  v1 = 0;
  v0 = UFG::WheeledVehicleManagerScriptInterface::Mthd_UseSpecificTrafficSet;
  SSClass::register_method_mthd(
    UFG::WheeledVehicleManagerScriptInterface::mClass,
    "use_specific_traffic_set",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v0,
    SSBindFlag_instance_no_rebind);
  v1 = 0;
  v0 = UFG::WheeledVehicleManagerScriptInterface::Mthd_UseAmbientTrafficSet;
  SSClass::register_method_mthd(
    UFG::WheeledVehicleManagerScriptInterface::mClass,
    "use_ambient_traffic_set",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v0,
    SSBindFlag_instance_no_rebind);
}

// File Line: 3234
// RVA: 0x653150
void __fastcall UFG::WheeledVehicleManagerScriptInterface::Mthd_EnableTraffic(
        UFG::WheeledVehicleManagerScriptInterface *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::WheeledVehicleManager::EnableTrafficSystem(
    this->m_WheeledVehicleManager,
    (*pScope->i_data.i_array_p)->i_data_p->i_user_data != 0);
}

// File Line: 3240
// RVA: 0x653190
void __fastcall UFG::WheeledVehicleManagerScriptInterface::Mthd_SetTrafficDensityScale(
        UFG::WheeledVehicleManagerScriptInterface *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::WheeledVehicleManager::SetTrafficDensityScale(*(float *)&(*pScope->i_data.i_array_p)->i_data_p->i_user_data);
}

// File Line: 3246
// RVA: 0x653140
void __fastcall UFG::WheeledVehicleManagerScriptInterface::Mthd_ClearTraffic(
        UFG::WheeledVehicleManagerScriptInterface *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::WheeledVehicleManager::DestroyAllWheeledVehicles(this->m_WheeledVehicleManager);
}

// File Line: 3251
// RVA: 0x653130
void __fastcall UFG::WheeledVehicleManagerScriptInterface::Mthd_ClearNonParkedTraffic(
        UFG::WheeledVehicleManagerScriptInterface *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::WheeledVehicleManager::DestroyAllNonParkedWheeledVehicles(this->m_WheeledVehicleManager);
}

// File Line: 3258
// RVA: 0x653170
void __fastcall UFG::WheeledVehicleManagerScriptInterface::Mthd_LockTrafficSystem(
        UFG::WheeledVehicleManagerScriptInterface *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::WheeledVehicleManager::m_TrafficSystemLocked = (*pScope->i_data.i_array_p)->i_data_p->i_user_data != 0;
}

// File Line: 3264
// RVA: 0x6531E0
void __fastcall UFG::WheeledVehicleManagerScriptInterface::Mthd_UseSpecificTrafficSet(
        UFG::WheeledVehicleManagerScriptInterface *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  this->m_WheeledVehicleManager->m_TrafficSetOverride.mUID = (*pScope->i_data.i_array_p)->i_data_p->i_user_data;
  UFG::ObjectResourceManager::Instance()->mEntityStates[1].mUpdateRequired = 1;
}

// File Line: 3270
// RVA: 0x6531B0
void __fastcall UFG::WheeledVehicleManagerScriptInterface::Mthd_UseAmbientTrafficSet(
        UFG::WheeledVehicleManagerScriptInterface *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  this->m_WheeledVehicleManager->m_TrafficSetOverride = UFG::gNullQSymbol;
  UFG::ObjectResourceManager::Instance()->mEntityStates[1].mUpdateRequired = 1;
}

