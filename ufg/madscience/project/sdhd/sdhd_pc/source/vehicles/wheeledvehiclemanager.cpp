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

  v0 = (float)(signed int)UFG::WheeledVehicleManager::mBaseMaxTrafficCars
     * UFG::WheeledVehicleManager::mMaxTrafficCarsScale;
  result = (unsigned int)(signed int)v0;
  UFG::WheeledVehicleManager::mMaxTrafficCars = (signed int)v0;
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
  UFG::WheeledVehicleManager *v1; // rbx
  UFG::SensorPhantom *v2; // rdi
  UFG::qSafePointer<UFG::SimComponent,UFG::TrafficRegion> *v3; // rsi
  UFG::qArray<UFG::WheeledVehicleManager::RoadSpawningRecord,0> *v4; // r14
  UFG::qArray<UFG::WheeledVehicleManager::RoadSpawningRecord,0> *v5; // r15
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v7; // rax
  UFG::allocator::free_link *v8; // rax
  UFG::WheeledVehicleNavigationData *v9; // rax
  UFG::allocator::free_link *v10; // rax
  UFG::RoadNetworkVisibleArea *v11; // rax
  UFG::allocator::free_link *v12; // rax
  UFG::TrueDirectionManager *v13; // rax
  UFG::allocator::free_link *v14; // rax
  unsigned int v15; // ecx
  int v16; // eax
  unsigned int v17; // esi
  unsigned int v18; // edx
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
  unsigned int i; // er9
  UFG::allocator::free_link *v31; // rax
  UFG::SensorPhantom *v32; // rax
  hkAabb aabb; // [rsp+40h] [rbp-48h]

  v1 = this;
  v2 = 0i64;
  this->m_TrueDirectionManager = 0i64;
  this->m_ReinitializeQueued = 0;
  this->m_SecondsQueued = 0.0;
  v3 = &this->mCurrentTrafficRegion;
  v3->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v3->mPrev;
  v3->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v3->mPrev;
  this->mCurrentTrafficRegion.m_pPointer = 0i64;
  this->m_TrafficSetOverride = UFG::gNullQSymbol;
  this->m_SimObject = 0i64;
  `eh vector constructor iterator(
    this->mCarsWithDeletionPending,
    0x18ui64,
    100,
    (void (__fastcall *)(void *))UFG::qSafePointer<UFG::SimObject,UFG::SimObjectCharacter>::qSafePointer<UFG::SimObject,UFG::SimObjectCharacter>);
  *(_QWORD *)&v1->mTotalNumParkedCarsCreated = 0i64;
  `eh vector constructor iterator(
    v1->mParkedCar,
    0x40ui64,
    100,
    (void (__fastcall *)(void *))UFG::qSafePointerWithCallbacks<UFG::SimObject,UFG::SimObjectVehicle>::qSafePointerWithCallbacks<UFG::SimObject,UFG::SimObjectVehicle>);
  *(_QWORD *)&v1->mTotalNumTrafficCarsCreated = 0i64;
  `eh vector constructor iterator(
    v1->mTrafficCar,
    0x40ui64,
    100,
    (void (__fastcall *)(void *))UFG::qSafePointerWithCallbacks<UFG::SimObject,UFG::SimObjectVehicle>::qSafePointerWithCallbacks<UFG::SimObject,UFG::SimObjectVehicle>);
  v4 = &v1->mSpawningRecordCollection;
  v4->p = 0i64;
  *(_QWORD *)&v4->size = 0i64;
  v5 = &v1->mParkingSpawningRecordCollection;
  v5->p = 0i64;
  *(_QWORD *)&v5->size = 0i64;
  v1->mSpawningLaneTendency = 0;
  v1->mPercentageSpawningInFavouredLane = 1.0;
  v1->mSpawnPointExpectedCarsTimer = UFG::WheeledVehicleManager::mSpawnPointExpectedCarsMaxTime;
  *(_QWORD *)&v1->mCurrentSpawnIndex = 0i64;
  v1->mSpawningSelectionArray.p = 0i64;
  v1->mSpawningSelectionArray.capacity = 0;
  *(_WORD *)&v1->m_PlaceTransitVehiclePending = 0;
  v1->m_PlaceTransitVehicleFrames = 0;
  v1->m_TrueDirectionUpdateEnabled = 1;
  if ( v3->m_pPointer )
  {
    v6 = v3->mPrev;
    v7 = v3->mNext;
    v6->mNext = v7;
    v7->mPrev = v6;
    v3->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v3->mPrev;
    v3->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v3->mPrev;
  }
  v3->m_pPointer = 0i64;
  v8 = UFG::qMalloc(0x118ui64, "WheeledVehicleNavigationData", 0i64);
  if ( v8 )
    UFG::WheeledVehicleNavigationData::WheeledVehicleNavigationData((UFG::WheeledVehicleNavigationData *)v8);
  else
    v9 = 0i64;
  v1->m_NavigationData = v9;
  v10 = UFG::qMalloc(0x178ui64, "RoadNetworkVisibleArea", 0i64);
  if ( v10 )
    UFG::RoadNetworkVisibleArea::RoadNetworkVisibleArea((UFG::RoadNetworkVisibleArea *)v10);
  else
    v11 = 0i64;
  v1->m_VisibleArea = v11;
  v12 = UFG::qMalloc(0x40ui64, "TrueDirectionManager", 0i64);
  if ( v12 )
    UFG::TrueDirectionManager::TrueDirectionManager((UFG::TrueDirectionManager *)v12);
  else
    v13 = 0i64;
  v1->m_TrueDirectionManager = v13;
  v14 = UFG::qMalloc(0x10ui64, "RoadPropertyNameData", 0i64);
  if ( v14 )
  {
    v14[1].mNext = 0i64;
    v14->mNext = 0i64;
  }
  else
  {
    v14 = 0i64;
  }
  v1->m_RoadPropertyCollection = (UFG::qArray<UFG::qSymbol,0> *)v14;
  v15 = v4->size;
  v16 = 100 - v4->size;
  if ( (signed int)(100 - v4->size) <= 0 )
  {
    v20 = v4->size - 100;
    if ( v4->size != 100 )
    {
      if ( v20 < v15 )
        v4->size = v15 - v20;
      else
        v4->size = 0;
    }
  }
  else
  {
    v17 = v15 + v16;
    v18 = v1->mSpawningRecordCollection.capacity;
    if ( v15 + v16 > v18 )
    {
      if ( v18 )
        v19 = 2 * v18;
      else
        v19 = 1;
      for ( ; v19 < v17; v19 *= 2 )
        ;
      if ( v19 - v17 > 0x10000 )
        v19 = v17 + 0x10000;
      UFG::qArray<UFG::WheeledVehicleManager::RoadSpawningRecord,0>::Reallocate(
        &v1->mSpawningRecordCollection,
        v19,
        "mSpawningRecordCollection");
    }
    v4->size = v17;
  }
  v21 = v5->size;
  v22 = 100 - v5->size;
  if ( v22 <= 0 )
  {
    v26 = v5->size - 100;
    if ( v5->size != 100 )
    {
      if ( v26 < v21 )
        v5->size = v21 - v26;
      else
        v5->size = 0;
    }
  }
  else
  {
    v23 = v21 + v22;
    v24 = v1->mParkingSpawningRecordCollection.capacity;
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
        &v1->mParkingSpawningRecordCollection,
        v25,
        "mParkingSpawningRecordCollection");
    }
    v5->size = v23;
  }
  if ( v1->mSpawningSelectionArray.capacity < 0xA && v1->mSpawningSelectionArray.size != 10 )
  {
    v27 = 80i64;
    if ( !is_mul_ok(0xAui64, 8ui64) )
      v27 = -1i64;
    v28 = UFG::qMalloc(v27, "WheeledVehicleManager", 0i64);
    v29 = (UFG::qPropertySet **)v28;
    if ( v1->mSpawningSelectionArray.p )
    {
      for ( i = 0; i < v1->mSpawningSelectionArray.size; ++i )
        v28[i] = (UFG::allocator::free_link)v1->mSpawningSelectionArray.p[i];
      operator delete[](v1->mSpawningSelectionArray.p);
    }
    v1->mSpawningSelectionArray.p = v29;
    v1->mSpawningSelectionArray.capacity = 10;
  }
  aabb.m_min = (hkVector4f)_xmm;
  aabb.m_max = (hkVector4f)_xmm;
  v31 = UFG::qMemoryPool::Allocate(&gPhysicsMemoryPool, 0x18ui64, "SpawnSensor", 0i64, 1u);
  if ( v31 )
  {
    UFG::SensorPhantom::SensorPhantom((UFG::SensorPhantom *)v31, &aabb, 0x18u, "VehicleSpawnSensor");
    v2 = v32;
  }
  v1->mSpawnSensor = v2;
}

// File Line: 241
// RVA: 0x658210
void __fastcall UFG::WheeledVehicleManager::ResetTrafficSystem(UFG::WheeledVehicleManager *this)
{
  UFG::WheeledVehicleManager *v1; // rbx

  UFG::WheeledVehicleManager::mBaseMaxTrafficCars = UFG::WheeledVehicleManager::mDefaultMaxTrafficCars;
  v1 = this;
  UFG::WheeledVehicleManager::m_TrafficSystemLocked = 0;
  UFG::WheeledVehicleManager::mMaxTrafficCarsScale = 1.0;
  UFG::WheeledVehicleManager::mMaxTrafficCars = (signed int)(float)(signed int)UFG::WheeledVehicleManager::mDefaultMaxTrafficCars;
  UFG::WheeledVehicleManager::mMaxParkedCars = UFG::WheeledVehicleManager::mDefaultMaxParkedCars;
  UFG::WheeledVehicleManager::SetTrafficDensityScale(1.0);
  v1->m_TrafficSetOverride = UFG::gNullQSymbol;
  if ( UFG::ObjectResourceManager::Instance()->mAmbientVehicles.size <= 2 )
  {
    v1->m_ReinitializeQueued = 1;
  }
  else
  {
    UFG::RoadNetworkVisibleArea::Reinitialize(v1->m_VisibleArea);
    v1->m_ReinitializeQueued = 0;
    v1->mCurrentSpawnIndex = 0;
  }
  v1->m_SecondsQueued = 0.0;
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
    UFG::WheeledVehicleManager::mMaxTrafficCars = (signed int)(float)((float)(signed int)UFG::WheeledVehicleManager::mBaseMaxTrafficCars
                                                                    * scaleFactor);
  }
}

// File Line: 265
// RVA: 0x6595D0
void __fastcall UFG::WheeledVehicleManager::SetMaxTrafficCars(unsigned int maxNumCars)
{
  if ( maxNumCars <= UFG::WheeledVehicleManager::mDefaultMaxTrafficCars )
  {
    UFG::WheeledVehicleManager::mBaseMaxTrafficCars = maxNumCars;
    UFG::WheeledVehicleManager::mMaxTrafficCars = (signed int)(float)((float)(signed int)maxNumCars
                                                                    * UFG::WheeledVehicleManager::mMaxTrafficCarsScale);
  }
}

// File Line: 281
// RVA: 0x6581E0
void UFG::WheeledVehicleManager::ResetMaxTrafficCars(void)
{
  LODWORD(UFG::WheeledVehicleManager::mMaxTrafficCarsScale) = (_DWORD)FLOAT_1_0;
  UFG::WheeledVehicleManager::mBaseMaxTrafficCars = UFG::WheeledVehicleManager::mDefaultMaxTrafficCars;
  UFG::WheeledVehicleManager::mMaxTrafficCars = (signed int)(float)(signed int)UFG::WheeledVehicleManager::mDefaultMaxTrafficCars;
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
  signed __int64 v1; // rdx
  bool v2; // al
  signed int v3; // ecx

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
    UFG::WheeledVehicleManager::mMaxTrafficCars = (signed int)(float)(signed int)UFG::WheeledVehicleManager::mDefaultMaxTrafficCars;
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
UFG::qPropertySet *__fastcall UFG::WheeledVehicleManager::ChooseWeightedEntryFromSpawningList(UFG::WheeledVehicleManager *this)
{
  UFG::WheeledVehicleManager *v1; // rbp
  unsigned int v3; // ebx
  UFG::qPropertySet *v4; // rsi
  UFG::qSymbol *v5; // rax
  UFG::qPropertySet *v6; // rax
  UFG::qPropertyList *v7; // rax
  __int64 v8; // rcx
  unsigned int v9; // er12
  int *v10; // rdi
  __int64 v11; // r14
  UFG::qSymbol *v12; // r15
  signed __int64 v13; // r15
  __int64 v14; // r9
  unsigned int v15; // eax
  UFG::qPropertySet **v16; // rdx
  int v17; // er8
  int v18; // er9
  int v19; // er10
  __int64 v20; // rcx
  unsigned int v21; // eax
  unsigned int v22; // eax
  __int64 v23; // rdx
  int v24; // eax
  __int64 v25; // rcx
  int *v26; // rdx
  UFG::qPropertySet **v27; // rax
  __int64 v28; // rdx
  int dest; // [rsp+20h] [rbp-A8h]
  int v30[31]; // [rsp+24h] [rbp-A4h]
  UFG::qSymbol result; // [rsp+D8h] [rbp+10h]

  v1 = this;
  if ( UFG::WheeledVehicleManager::GetCurrentTrafficSet(this, &result)->mUID == UFG::gNullQSymbol.mUID )
    return 0i64;
  v3 = v1->mSpawningSelectionArray.size;
  v4 = 0i64;
  if ( v3 )
  {
    v5 = UFG::WheeledVehicleManager::GetCurrentTrafficSet(v1, &result);
    v6 = UFG::PropertySetManager::CreateOrFindPropertySet(v5);
    v7 = UFG::qPropertySet::Get<UFG::qPropertyList>(v6, (UFG::qSymbol *)&qSymbol_SpawnSet.mUID, DEPTH_RECURSE);
    v8 = v7->mWeights.mOffset;
    v9 = v7->mTypeUID;
    if ( v8 )
      v10 = (int *)((char *)&v7->mWeights + v8);
    else
      v10 = 0i64;
    v11 = v7->mNumElements;
    if ( (_DWORD)v11 )
      v12 = UFG::qPropertyList::Get<UFG::qSymbol>(v7, 0);
    else
      v12 = 0i64;
    if ( v9 == 22 && v10 && v3 > 1 )
    {
      UFG::qMemSet(&dest, 0, 0x80u);
      if ( (_DWORD)v11 )
      {
        v13 = (char *)v12 - (char *)v10;
        v14 = v11;
        do
        {
          v15 = 0;
          if ( v3 )
          {
            v16 = v1->mSpawningSelectionArray.p;
            while ( (*v16)->mName.mUID != *(int *)((char *)v10 + v13) )
            {
              ++v15;
              ++v16;
              if ( v15 >= v3 )
                goto LABEL_21;
            }
            *(&dest + v15) = *v10;
          }
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
      *(&dest + (v1->mCurrentSpawnIndex & 0x1F)) = 0;
      v21 = 0;
      if ( (signed int)v3 >= 2 )
      {
        v22 = ((v3 - 2) >> 1) + 1;
        v23 = v22;
        v21 = 2 * v22;
        do
        {
          v17 += *(&dest + v20);
          v18 += v30[v20];
          v20 += 2i64;
          --v23;
        }
        while ( v23 );
      }
      if ( v21 < v3 )
        v19 = *(&dest + v20);
      v24 = UFG::qRandom(v19 + v18 + v17, &UFG::qDefaultSeed);
      v25 = 0i64;
      if ( v3 )
      {
        v26 = &dest;
        while ( 1 )
        {
          v24 -= *v26;
          if ( v24 < 0 )
            break;
          v25 = (unsigned int)(v25 + 1);
          ++v26;
          if ( (unsigned int)v25 >= v3 )
            return v4;
        }
        v27 = v1->mSpawningSelectionArray.p;
        v1->mCurrentSpawnIndex = v25;
        v4 = v27[v25];
      }
    }
    else
    {
      v28 = (v1->mCurrentSpawnIndex + 1) % v1->mSpawningSelectionArray.size;
      v4 = v1->mSpawningSelectionArray.p[v28];
      v1->mCurrentSpawnIndex = v28;
    }
  }
  return v4;
}

// File Line: 426
// RVA: 0x6484D0
UFG::qPropertySet *__fastcall UFG::WheeledVehicleManager::ChooseAmbientVehicle(UFG::WheeledVehicleManager *this, unsigned int roadType, UFG::WheeledVehicleManager::VehicleJob vehicleJobType)
{
  unsigned int v3; // er12
  UFG::WheeledVehicleManager::VehicleJob v4; // er15
  UFG::WheeledVehicleManager *v5; // r13
  UFG::ObjectResourceManager *v7; // rdi
  UFG::qPropertySet *v8; // rbx
  __int64 v9; // rdi
  UFG::qArray<UFG::qPropertySet *,0> *v10; // r14
  UFG::ObjectResourceManager *v11; // rbp
  UFG::qPropertySet **v12; // rax
  UFG::qPropertySet *v13; // rsi
  __int64 v14; // r15
  unsigned int v15; // edx
  unsigned int v16; // ebx
  unsigned int v17; // edx
  UFG::qPropertySet **v18; // rax
  UFG::qSymbol result; // [rsp+20h] [rbp-48h]
  UFG::WheeledVehicleManager::VehicleJob v20; // [rsp+80h] [rbp+18h]
  UFG::qSymbol propSetName; // [rsp+88h] [rbp+20h]

  v20 = vehicleJobType;
  v3 = roadType;
  v4 = vehicleJobType;
  v5 = this;
  if ( UFG::WheeledVehicleManager::GetCurrentTrafficSet(this, &result)->mUID == UFG::gNullQSymbol.mUID )
    return 0i64;
  v7 = UFG::ObjectResourceManager::Instance();
  propSetName.mUID = UFG::EntityTypeState::GetSpawnableRareEntity(&v7->mEntityStates[1])->mUID;
  if ( propSetName.mUID != UFG::gNullQSymbol.mUID
    && (v8 = UFG::PropertySetManager::GetPropertySet(&propSetName), UFG::VehicleUtility::IsClassTypeRoadTypeMatch(
                                                                      v8,
                                                                      v3))
    && UFG::WheeledVehicleManager::IsVehicleJobMatch(v5, v8, v4) )
  {
    UFG::EntityTypeState::RareEntitySpawned(&v7->mEntityStates[1], &propSetName);
  }
  else
  {
    v9 = 0i64;
    v10 = &v5->mSpawningSelectionArray;
    v11 = UFG::ObjectResourceManager::Instance();
    v5->mSpawningSelectionArray.size = 0;
    if ( v11->mAmbientVehicles.size )
    {
      do
      {
        v12 = v11->mAmbientVehicles.p;
        v13 = v12[v9];
        if ( v13
          && UFG::VehicleUtility::IsClassTypeRoadTypeMatch(v12[v9], v3)
          && UFG::WheeledVehicleManager::IsVehicleJobMatch(v5, v13, v4) )
        {
          v14 = v10->size;
          v15 = v5->mSpawningSelectionArray.capacity;
          v16 = v14 + 1;
          if ( (signed int)v14 + 1 > v15 )
          {
            if ( v15 )
              v17 = 2 * v15;
            else
              v17 = 1;
            for ( ; v17 < v16; v17 *= 2 )
              ;
            if ( v17 <= 2 )
              v17 = 2;
            if ( v17 - v16 > 0x10000 )
              v17 = v14 + 65537;
            UFG::qArray<UFG::CompositeDrawableComponent *,32>::Reallocate(
              (UFG::qArray<UFG::qReflectInventoryBase *,0> *)&v5->mSpawningSelectionArray,
              v17,
              "qArray.Add");
          }
          v18 = v5->mSpawningSelectionArray.p;
          v10->size = v16;
          v18[v14] = v13;
          v4 = v20;
        }
        v9 = (unsigned int)(v9 + 1);
      }
      while ( (unsigned int)v9 < v11->mAmbientVehicles.size );
    }
    v8 = UFG::WheeledVehicleManager::ChooseWeightedEntryFromSpawningList(v5);
  }
  return v8;
}

// File Line: 485
// RVA: 0x652110
_BOOL8 __fastcall UFG::WheeledVehicleManager::IsTrueDirectionUpdateEnabled(UFG::WheeledVehicleManager *this)
{
  return this->m_TrueDirectionUpdateEnabled;
}

// File Line: 490
// RVA: 0x659A30
void __fastcall UFG::WheeledVehicleManager::SetTrueDirectionUpdateEnabled(UFG::WheeledVehicleManager *this, bool isEnabled)
{
  this->m_TrueDirectionUpdateEnabled = isEnabled;
}

// File Line: 496
// RVA: 0x652120
_BOOL8 __fastcall UFG::WheeledVehicleManager::IsVehicleJobMatch(UFG::WheeledVehicleManager *this, UFG::qPropertySet *vehiclePropSet, UFG::WheeledVehicleManager::VehicleJob jobType)
{
  UFG::qPropertySet *v3; // rsi
  bool v4; // bl
  bool v5; // di
  char v7; // al
  bool v8; // dl
  UFG::qSymbol targetClassType; // [rsp+40h] [rbp+18h]

  v3 = vehiclePropSet;
  v4 = jobType == 0;
  v5 = jobType == 1;
  if ( !vehiclePropSet )
    return v4;
  targetClassType.mUID = qSymbol_Minibus.mUID;
  if ( UFG::SimObjectUtility::IsClassType(vehiclePropSet, &targetClassType) )
    return v4 || v5;
  targetClassType.mUID = qSymbol_Tram.mUID;
  if ( UFG::SimObjectUtility::IsClassType(v3, &targetClassType) )
    return v4 || v5;
  targetClassType.mUID = qSymbol_Ferry.mUID;
  v7 = UFG::SimObjectUtility::IsClassType(v3, &targetClassType);
  v8 = v4;
  if ( v7 )
    v8 = v5;
  return v8;
}

// File Line: 517
// RVA: 0x648400
UFG::qPropertySet *__fastcall UFG::WheeledVehicleManager::ChooseAmbientParkedVehicle(UFG::WheeledVehicleManager *this, unsigned int roadType)
{
  unsigned int v2; // er15
  UFG::WheeledVehicleManager *v3; // rbp
  signed __int64 v4; // rbx
  UFG::ObjectResourceManager *v5; // rdi
  signed __int64 v6; // rsi
  bool *v7; // rax

  v2 = roadType;
  v3 = this;
  v4 = 0i64;
  v5 = UFG::ObjectResourceManager::Instance();
  v3->mSpawningSelectionArray.size = 0;
  if ( v5->mAmbientVehicles.size )
  {
    do
    {
      v6 = v4;
      if ( UFG::VehicleUtility::IsClassTypeRoadTypeMatch(v5->mAmbientVehicles.p[v4], v2) )
      {
        v7 = UFG::qPropertySet::Get<bool>(
               v5->mAmbientVehicles.p[v6],
               (UFG::qSymbol *)&qSymbol_Parkable.mUID,
               DEPTH_RECURSE);
        if ( v7 )
        {
          if ( *v7 == 1 )
            UFG::qArray<UFG::PedSpawningInfo *,0>::Add(
              &v3->mSpawningSelectionArray,
              &v5->mAmbientVehicles.p[v6],
              "qArray.Add");
        }
      }
      v4 = (unsigned int)(v4 + 1);
    }
    while ( (unsigned int)v4 < v5->mAmbientVehicles.size );
  }
  return UFG::WheeledVehicleManager::ChooseWeightedEntryFromSpawningList(v3);
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
UFG::SimObjectVehicle *__fastcall UFG::WheeledVehicleManager::CreateWheeledVehicle(UFG::WheeledVehicleManager *this, UFG::qPropertySet *vehiclePropSet)
{
  unsigned int v2; // ebx
  UFG::qPropertySet *v3; // rdi
  UFG::WheeledVehicleManager *v4; // rsi
  UFG::OnlineManager *v5; // rax
  unsigned int v6; // eax
  UFG::qSymbol *v7; // rax
  unsigned int v8; // ebx
  UFG::SimObjectVehicle *v9; // rax
  UFG::SimObject **v10; // rcx
  UFG::SimObjectVehicle *v11; // rdi
  char dest; // [rsp+30h] [rbp-28h]
  UFG::SpawnInfoInterface::SpawnPriority pPriority; // [rsp+60h] [rbp+8h]
  UFG::qSymbol result; // [rsp+70h] [rbp+18h]

  v2 = this->mTotalNumTrafficCarsCreated;
  v3 = vehiclePropSet;
  v4 = this;
  this->mTotalNumTrafficCarsCreated = v2 + 1;
  v5 = UFG::OnlineManager::Instance();
  v6 = UFG::OnlineManager::GetOnlineIdStringHash32(v5);
  UFG::qSPrintf(&dest, UFG::WheeledVehicleManager::mTrafficCarName, v6, v2);
  UFG::SpawnInfoInterface::GetSpawnPriority(v3, &pPriority);
  v7 = UFG::qSymbol::create_from_string(&result, &dest);
  v8 = 0;
  v9 = (UFG::SimObjectVehicle *)UFG::SpawnInfoInterface::SpawnObject(v7, v3, pPriority, 0i64, 0i64, 0i64);
  ++v4->mNumTrafficCars;
  v10 = &v4->mTrafficCar[0].m_pPointer;
  v11 = v9;
  while ( *v10 )
  {
    ++v8;
    v10 += 8;
    if ( v8 >= 0x64 )
      return v9;
  }
  UFG::qSafePointerWithCallbacks<UFG::SimObject,UFG::SimObjectVehicle>::Set(
    (UFG::qSafePointerWithCallbacks<UFG::EncounterBase,UFG::EncounterBase> *)&v4->mTrafficCar[(unsigned __int64)v8],
    (UFG::EncounterBase *)v9);
  return v11;
}

// File Line: 575
// RVA: 0x15788F0
__int64 dynamic_initializer_for__gsymAIActionTreeComponentUC__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("AIActionTreeComponent", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&gsymAIActionTreeComponentUC, v0);
  return atexit(dynamic_atexit_destructor_for__gsymAIActionTreeComponentUC__);
}

// File Line: 578
// RVA: 0x645360
void __fastcall UFG::WheeledVehicleManager::AttachTrafficAI(UFG::WheeledVehicleManager *this, UFG::SimObjectVehicle *pCar)
{
  UFG::SimObjectVehicle *v2; // r14
  UFG::qMemoryPool *v3; // rax
  UFG::allocator::free_link *v4; // rax
  UFG::SimComponent *v5; // rbp
  __int64 v6; // rax
  __int64 v7; // rdi
  unsigned __int16 v8; // cx
  unsigned int v9; // ebx
  unsigned int v10; // esi
  UFG::qMemoryPool *v11; // rax
  UFG::allocator::free_link *v12; // rax
  UFG::SimComponent *v13; // rax
  UFG::SimComponent *v14; // rsi
  unsigned __int16 v15; // cx
  unsigned int v16; // edi
  UFG::qMemoryPool *v17; // rax
  UFG::allocator::free_link *v18; // rax
  UFG::SimComponent *v19; // rax
  unsigned __int16 v20; // cx
  UFG::SimObjectModifier v21; // [rsp+38h] [rbp-60h]
  UFG::SimObjectModifier v22; // [rsp+58h] [rbp-40h]

  v2 = pCar;
  UFG::SimObjectModifier::SimObjectModifier(&v22, (UFG::SimObject *)&pCar->vfptr, 1);
  v3 = UFG::GetSimulationMemoryPool();
  v4 = UFG::qMemoryPool::Allocate(v3, 0x628ui64, "AiDriverComponent", 0i64, 1u);
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
  v8 = v2->m_Flags;
  v9 = -1;
  if ( (v8 >> 14) & 1 )
  {
    v10 = 23;
  }
  else if ( (v8 & 0x8000u) == 0 )
  {
    v10 = -1;
  }
  else
  {
    v10 = 23;
  }
  UFG::SimObjectModifier::SimObjectModifier(&v21, (UFG::SimObject *)&v2->vfptr, 1);
  UFG::SimObjectModifier::AttachComponent(&v21, (UFG::SimComponent *)v7, v10);
  UFG::SimObjectModifier::Close(&v21);
  UFG::SimObjectModifier::~SimObjectModifier(&v21);
  if ( !v2->m_Components.p[24].m_pComponent )
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
    v15 = v2->m_Flags;
    if ( (v15 >> 14) & 1 )
    {
      v16 = 24;
    }
    else if ( (v15 & 0x8000u) == 0 )
    {
      v16 = -1;
    }
    else
    {
      v16 = 24;
    }
    UFG::SimObjectModifier::SimObjectModifier(&v21, (UFG::SimObject *)&v2->vfptr, 1);
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
  v20 = v2->m_Flags;
  if ( (v20 >> 14) & 1 || (v20 & 0x8000u) != 0 )
    v9 = 19;
  UFG::SimObjectModifier::SimObjectModifier(&v21, (UFG::SimObject *)&v2->vfptr, 1);
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
  UFG::WheeledVehicleManager *v2; // rbx
  UFG::ObjectResourceManager *v3; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::TrafficRegion> *v4; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::ObjectResourceManager *v7; // rax
  UFG::ObjectResourceManager *v8; // rax

  v2 = this;
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
      UFG::WheeledVehicleManager::Reinitialize(v2);
      UFG::WheeledVehicleManager::UpdateTrafficSet(v2);
    }
    else
    {
      UFG::WheeledVehicleManager::DestroyAllWheeledVehicles(this);
      v3 = UFG::ObjectResourceManager::Instance();
      UFG::ObjectResourceManager::UnloadAmbientVehicles(v3);
      v4 = &v2->mCurrentTrafficRegion;
      if ( v2->mCurrentTrafficRegion.m_pPointer )
      {
        v5 = v4->mPrev;
        v6 = v2->mCurrentTrafficRegion.mNext;
        v5->mNext = v6;
        v6->mPrev = v5;
        v4->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v4->mPrev;
        v2->mCurrentTrafficRegion.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->mCurrentTrafficRegion.mPrev;
      }
      v2->mCurrentTrafficRegion.m_pPointer = 0i64;
      v7 = UFG::ObjectResourceManager::Instance();
      UFG::ObjectResourceManager::SetActiveAmbience(v7, 0, 1);
      UFG::RoadNetworkVisibleArea::Reinitialize(v2->m_VisibleArea);
    }
  }
}

// File Line: 658
// RVA: 0x64A440
UFG::SimObjectVehicle *__fastcall UFG::WheeledVehicleManager::CreateParkedWheeledVehicle(UFG::WheeledVehicleManager *this, UFG::qPropertySet *vehiclePropSet, UFG::ParkingSpot *spot)
{
  unsigned int v3; // ebx
  UFG::ParkingSpot *v4; // rsi
  UFG::qPropertySet *v5; // rdi
  UFG::WheeledVehicleManager *v6; // rbp
  UFG::qSymbol *v7; // rax
  UFG::SimObjectVehicle *v8; // rbx
  __int64 v9; // rcx
  UFG::SimObject **v10; // rdx
  char dest; // [rsp+20h] [rbp-28h]
  UFG::qSymbol result; // [rsp+50h] [rbp+8h]

  v3 = this->mTotalNumParkedCarsCreated;
  v4 = spot;
  v5 = vehiclePropSet;
  v6 = this;
  this->mTotalNumParkedCarsCreated = v3 + 1;
  UFG::OnlineManager::Instance();
  UFG::qSPrintf(&dest, UFG::WheeledVehicleManager::mParkedCarName, 0i64, v3);
  ++v6->mNumParkedCars;
  v7 = UFG::qSymbol::create_from_string(&result, &dest);
  v8 = (UFG::SimObjectVehicle *)UFG::ParkingSpot::Spawn(v4, v7, v5, High);
  UFG::VehicleUtility::SetRadiostation(v8);
  v9 = 0i64;
  v10 = &v6->mParkedCar[0].m_pPointer;
  while ( *v10 )
  {
    v9 = (unsigned int)(v9 + 1);
    v10 += 8;
    if ( (unsigned int)v9 >= 0x64 )
      return v8;
  }
  UFG::qSafePointerWithCallbacks<UFG::SimObject,UFG::SimObjectVehicle>::Set(
    (UFG::qSafePointerWithCallbacks<UFG::EncounterBase,UFG::EncounterBase> *)v6 + v9 + 39,
    (UFG::EncounterBase *)v8);
  return v8;
}

// File Line: 687
// RVA: 0x64A200
void __fastcall UFG::WheeledVehicleManager::CreateParkedCarsOnSubSegment(UFG::WheeledVehicleManager *this, UFG::RoadNetworkSubSegment *subSegment, unsigned int numParkedCars)
{
  unsigned int v3; // esi
  UFG::RoadNetworkSubSegment *v4; // r14
  UFG::WheeledVehicleManager *v5; // rbp
  unsigned int v6; // eax
  unsigned __int64 v7; // rdi
  UFG::ParkingSpot *j; // rbx
  unsigned int v9; // eax
  UFG::qPropertySet *v10; // rax
  unsigned __int64 v11; // rax
  UFG::allocator::free_link *v12; // rax
  UFG::ParkingSpot **v13; // rbx
  UFG::ParkingSpot **v14; // r9
  unsigned int i; // er8
  __int64 v16; // rbx
  __int64 v17; // r14
  __int64 v18; // rdx
  UFG::ParkingSpot *v19; // rbx
  unsigned int v20; // eax
  UFG::qPropertySet *v21; // rax
  UFG::qArray<UFG::ParkingSpot *,0> availableParkingSpots; // [rsp+28h] [rbp-30h]

  v3 = numParkedCars;
  v4 = subSegment;
  v5 = this;
  v6 = UFG::RoadNetworkSubSegment::GetNumAvailableParkingSpots(subSegment);
  v7 = v6;
  if ( v6 )
  {
    if ( v3 < (unsigned int)v7 )
    {
      availableParkingSpots.p = 0i64;
      *(_QWORD *)&availableParkingSpots.size = 0i64;
      if ( (unsigned int)v7 > 0 && (_DWORD)v7 != availableParkingSpots.size )
      {
        v11 = 8i64 * v6;
        if ( !is_mul_ok(v7, 8ui64) )
          v11 = -1i64;
        v12 = UFG::qMalloc(v11, "WheeledVehicleManager", 0i64);
        v13 = (UFG::ParkingSpot **)v12;
        v14 = availableParkingSpots.p;
        if ( availableParkingSpots.p )
        {
          for ( i = 0; i < availableParkingSpots.size; v14 = availableParkingSpots.p )
          {
            v12[i].mNext = (UFG::allocator::free_link *)v14[i];
            ++i;
          }
          operator delete[](v14);
        }
        availableParkingSpots.p = v13;
        availableParkingSpots.capacity = v7;
      }
      UFG::RoadNetworkSubSegment::GetAvailableParkingSpots(v4, &availableParkingSpots);
      for ( ; v3; --v3 )
      {
        v16 = (unsigned int)UFG::qRandom(v7, &UFG::qDefaultSeed);
        v17 = v16;
        if ( !((unsigned __int8 (__cdecl *)(UFG::ParkingSpot *))availableParkingSpots.p[v17]->vfptr[18].__vecDelDtor)(availableParkingSpots.p[v17])
          && !((unsigned __int8 (__cdecl *)(UFG::ParkingSpot *))availableParkingSpots.p[v17]->vfptr[18].__vecDelDtor)(availableParkingSpots.p[v17]) )
        {
          do
          {
            v18 = ((signed int)v16 + 1) % (unsigned int)v7;
            v16 = ((signed int)v16 + 1) % (unsigned int)v7;
          }
          while ( !((unsigned __int8 (__cdecl *)(UFG::ParkingSpot *))availableParkingSpots.p[v18]->vfptr[18].__vecDelDtor)(availableParkingSpots.p[v18]) );
        }
        v19 = availableParkingSpots.p[v16];
        v20 = ((__int64 (__fastcall *)(UFG::ParkingSpot *))v19->vfptr[17].__vecDelDtor)(v19);
        v21 = UFG::WheeledVehicleManager::ChooseAmbientParkedVehicle(v5, v20);
        if ( v21 )
          UFG::WheeledVehicleManager::SpawnParkedVehicle(v5, v21, v19);
      }
      if ( availableParkingSpots.p )
        operator delete[](availableParkingSpots.p);
    }
    else
    {
      for ( j = (UFG::ParkingSpot *)&v4->mParkingSpotCollection.mNode.mNext[-12];
            j != (UFG::ParkingSpot *)&v4[-1].mPosition.z;
            j = (UFG::ParkingSpot *)&j->mNext[-12] )
      {
        if ( ((unsigned __int8 (__fastcall *)(UFG::ParkingSpot *))j->vfptr[18].__vecDelDtor)(j) )
        {
          v9 = ((__int64 (__fastcall *)(UFG::ParkingSpot *))j->vfptr[17].__vecDelDtor)(j);
          v10 = UFG::WheeledVehicleManager::ChooseAmbientParkedVehicle(v5, v9);
          if ( v10 )
            UFG::WheeledVehicleManager::SpawnParkedVehicle(v5, v10, j);
        }
      }
    }
  }
}

// File Line: 767
// RVA: 0x64A510
void __fastcall UFG::WheeledVehicleManager::CreateTrafficCarsOnSubSegment(UFG::WheeledVehicleManager *this, UFG::RoadNetworkSubSegment *subSegment, unsigned int numCars)
{
  unsigned int v3; // ebx
  UFG::RoadNetworkSubSegment *v4; // r13
  UFG::WheeledVehicleManager *v5; // r15
  unsigned __int64 v6; // r12
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
  unsigned int v18; // er14
  __int64 *v19; // r12
  __int64 v20; // rdi
  UFG::RoadNetworkLane *v21; // rbx
  float v22; // xmm8_4
  float v23; // xmm0_4
  float v24; // xmm7_4
  float v25; // xmm6_4
  __int64 v26; // rsi
  unsigned int v27; // er13
  UFG::qPropertySet *v28; // rdi
  UFG::ObjectResourceManager *v29; // rax
  UFG::RoadNetworkNode *v30; // r8
  void *mem; // [rsp+10h] [rbp-71h]
  UFG::allocator::free_link *t; // [rsp+20h] [rbp-61h]
  __int64 v33; // [rsp+28h] [rbp-59h]
  UFG::RoadNetworkNode *v34; // [rsp+30h] [rbp-51h]
  __int64 v35; // [rsp+38h] [rbp-49h]
  __int64 v36; // [rsp+40h] [rbp-41h]
  __int64 v37; // [rsp+48h] [rbp-39h]
  UFG::RoadNetworkSubSegment *v38; // [rsp+F0h] [rbp+6Fh]
  unsigned int roadType; // [rsp+F8h] [rbp+77h]
  unsigned int v40; // [rsp+100h] [rbp+7Fh]

  if ( numCars >= 1 )
  {
    v35 = -2i64;
    v3 = numCars;
    v4 = subSegment;
    v5 = this;
    v34 = (UFG::RoadNetworkNode *)&subSegment->mParentNode->mType;
    roadType = UFG::RoadNetworkSegment::GetRoadNetworkType((UFG::RoadNetworkSegment *)v34);
    v6 = (unsigned __int8)v34->mNumLanes;
    v40 = v6;
    if ( (unsigned int)(v6 - 1) <= 9 )
    {
      v7 = v3 / (unsigned int)v6;
      v8 = v3 % (unsigned int)v6;
      v9 = v7;
      v33 = 0i64;
      v34 = 0i64;
      v35 = 0i64;
      v36 = 0i64;
      v37 = 0i64;
      v10 = 4 * v6;
      if ( !is_mul_ok(v6, 4ui64) )
        v10 = -1i64;
      t = UFG::qMalloc(v10, "WheeledVehicleManager", 0i64);
      v11 = 4 * v6;
      if ( !is_mul_ok(v6, 4ui64) )
        v11 = -1i64;
      UFG::qMalloc(v11, "WheeledVehicleManager", 0i64);
      if ( (_DWORD)v6 )
      {
        v12 = v9;
        v13 = &v33;
        for ( i = (unsigned int)v6; i; --i )
        {
          *(_DWORD *)v13 = v12;
          v13 = (__int64 *)((char *)v13 + 4);
        }
      }
      v15 = UFG::qRandom(v6, &UFG::qDefaultSeed);
      if ( (_DWORD)v8 )
      {
        v16 = v8;
        do
        {
          ++*((_DWORD *)&v33 + v15);
          v15 = (v15 + 1) % (unsigned int)v6;
          --v16;
        }
        while ( v16 );
      }
      v17 = v4->mLength - 8.0;
      if ( v17 <= 0.0 )
        v17 = 0.0;
      v18 = 0;
      if ( (_DWORD)v6 )
      {
        v19 = &v33;
        do
        {
          v20 = *(unsigned int *)v19;
          if ( (unsigned int)v20 <= 0x19 && (_DWORD)v20 )
          {
            v21 = UFG::RoadNetworkNode::GetLane(v34, v18);
            if ( UFG::RoadNetworkLane::IsReversedInNode(v21) )
            {
              v22 = UFG::RoadNetworkSubSegment::GetEndT(v4, v18);
              UFG::RoadNetworkSubSegment::GetBeginT(v4, v18);
            }
            else
            {
              v22 = UFG::RoadNetworkSubSegment::GetBeginT(v4, v18);
              UFG::RoadNetworkSubSegment::GetEndT(v4, v18);
            }
            v23 = UFG::RoadNetworkLane::GetLength(v21);
            v24 = (float)(1.0 / v23) * (float)(v17 / (float)(signed int)v20);
            v25 = (float)((float)(1.0 / v23) * 4.0) + v22;
            if ( (_DWORD)v20 )
            {
              v26 = v20;
              v27 = roadType;
              do
              {
                v28 = UFG::WheeledVehicleManager::ChooseAmbientVehicle(v5, v27, 0);
                if ( v28 )
                {
                  v29 = UFG::ObjectResourceManager::Instance();
                  if ( UFG::ObjectResourceManager::CanSpawnAmbient(v29, v28, 0i64, 0) )
                  {
                    if ( v21->mNode.mOffset )
                      v30 = (UFG::RoadNetworkNode *)((char *)v21 + v21->mNode.mOffset);
                    else
                      v30 = 0i64;
                    UFG::WheeledVehicleManager::SpawnTrafficVehicle(v5, v28, v30, v21->mLaneIndex, v23, v25);
                  }
                }
                v25 = v25 + v24;
                --v26;
              }
              while ( v26 );
              v4 = v38;
            }
          }
          ++v18;
          v19 = (__int64 *)((char *)v19 + 4);
        }
        while ( v18 < v40 );
      }
      if ( mem )
        operator delete[](mem);
      if ( t )
        operator delete[](t);
    }
  }
}

// File Line: 934
// RVA: 0x652200
char __fastcall UFG::WheeledVehicleManager::IsVehicleSpawnCollision(UFG::qPropertySet *vehiclePropSet, UFG::RoadNetworkLane *targetRoadLane, float targetLaneT)
{
  UFG::RoadNetworkLane *v3; // rdi
  UFG::qPropertySet *v4; // rax
  unsigned int v5; // esi
  char *v6; // rax
  float targetRear; // xmm8_4
  float targetFront; // xmm9_4
  UFG::RoadNetworkGuide *v9; // rbx
  float v10; // xmm11_4
  float v11; // xmm7_4
  float v12; // xmm6_4
  float v13; // xmm7_4
  __int64 v14; // rax
  UFG::RoadNetworkConnection *v15; // r14
  char v16; // al
  unsigned int v17; // ebp
  unsigned int v18; // ebx
  UFG::RoadNetworkLane *v19; // rax
  __int64 v20; // rax
  UFG::RoadNetworkConnection *v21; // rbx
  unsigned int v22; // ebp
  UFG::RoadNetworkLane *v23; // rax
  UFG::qVector3 result; // [rsp+30h] [rbp-88h]
  UFG::qVector3 v25; // [rsp+40h] [rbp-78h]

  v3 = targetRoadLane;
  v4 = UFG::qPropertySet::Get<UFG::qPropertySet>(
         vehiclePropSet,
         (UFG::qSymbol *)&component_PhysicsMover::sPropertyName.mUID,
         DEPTH_RECURSE);
  v5 = 0;
  if ( v4 )
    v6 = UFG::qPropertySet::GetMemImagePtr(v4);
  else
    v6 = 0i64;
  targetRear = 0.0;
  LODWORD(targetFront) = *((_DWORD *)v6 + 12) & _xmm;
  if ( targetFront < 0.0 )
    targetFront = 0.0;
  if ( COERCE_FLOAT(*((_DWORD *)v6 + 9) & _xmm) >= 0.0 )
    LODWORD(targetRear) = *((_DWORD *)v6 + 9) & _xmm;
  UFG::RoadNetworkLane::GetPos(v3, &result, targetLaneT);
  if ( (UFG::qOffset64<UFG::RoadNetworkConnection *> *)&v3->mCars.mNode.mNext[-2].mNext == &v3->mStartConnection
    || (v9 = (UFG::RoadNetworkGuide *)&v3->mCars.mNode.mNext[-2].mNext,
        v9 == (UFG::RoadNetworkGuide *)&v3->mStartConnection) )
  {
LABEL_15:
    v14 = v3->mStartConnection.mOffset;
    if ( v14 )
      v15 = (UFG::RoadNetworkConnection *)((char *)&v3->mStartConnection + v14);
    else
      v15 = 0i64;
    v17 = v15->mNumLanes;
    v18 = 0;
    if ( v15->mNumLanes )
    {
      while ( 1 )
      {
        v19 = UFG::qBezierPathCollectionMemImaged::GetPath(v15, v18);
        if ( v3 != v19 )
        {
          if ( UFG::WheeledVehicleManager::IsSpawnCollisionOnMergeLane(
                 v19,
                 v3,
                 targetLaneT,
                 &result,
                 targetRear,
                 targetFront) )
          {
            break;
          }
        }
        if ( ++v18 >= v17 )
          goto LABEL_23;
      }
    }
    else
    {
LABEL_23:
      v20 = v3->mEndConnection.mOffset;
      if ( v20 )
        v21 = (UFG::RoadNetworkConnection *)((char *)&v3->mEndConnection + v20);
      else
        v21 = 0i64;
      v22 = v21->mNumLanes;
      if ( !v21->mNumLanes )
        return 0;
      while ( 1 )
      {
        v23 = UFG::qBezierPathCollectionMemImaged::GetPath(v21, v5);
        if ( v3 != v23 )
        {
          if ( UFG::WheeledVehicleManager::IsSpawnCollisionOnMergeLane(
                 v23,
                 v3,
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
    v16 = 1;
  }
  else
  {
    while ( 1 )
    {
      v10 = v9->m_FrontBoundary;
      v11 = v9->m_RearBoundary;
      v12 = Scaleform::GFx::AS3::Instances::fl::XML::GetName(v9)->m_LaneT;
      UFG::RoadNetworkLane::GetPos(v3, &v25, v12);
      v13 = v12 <= targetLaneT ? v10 + targetRear : v11 + targetFront;
      if ( (float)((float)((float)((float)(result.y - v25.y) * (float)(result.y - v25.y))
                         + (float)((float)(result.x - v25.x) * (float)(result.x - v25.x)))
                 + (float)((float)(result.z - v25.z) * (float)(result.z - v25.z))) < (float)((float)(v13 + 0.2)
                                                                                           * (float)(v13 + 0.2)) )
        break;
      v9 = (UFG::RoadNetworkGuide *)&v9->mNext[-2].mNext;
      if ( v9 == (UFG::RoadNetworkGuide *)&v3->mStartConnection )
        goto LABEL_15;
    }
    v16 = 1;
  }
  return v16;
}    if ( v9 == (UF

// File Line: 991
// RVA: 0x651F30
char __fastcall UFG::WheeledVehicleManager::IsSpawnCollisionOnMergeLane(UFG::RoadNetworkLane *mergeLane, UFG::RoadNetworkLane *targetRoadLane, float targetLaneT, UFG::qVector3 *targetPos, float targetRear, float targetFront)
{
  UFG::qOffset64<UFG::RoadNetworkConnection *> *v6; // rdi
  float *v7; // rbx
  UFG::qVector3 *v8; // r14
  UFG::RoadNetworkLane *v9; // rbp
  UFG::RoadNetworkLane *v10; // rsi
  float v11; // xmm7_4
  float v12; // xmm6_4
  float v13; // xmm8_4
  float v14; // xmm6_4
  UFG::qVector3 result; // [rsp+20h] [rbp-A8h]
  UFG::qVector3 v17; // [rsp+30h] [rbp-98h]
  UFG::qVector3 v18; // [rsp+40h] [rbp-88h]

  v6 = &mergeLane->mStartConnection;
  v7 = (float *)&mergeLane->mCars.mNode.mNext[-2].mNext;
  v8 = targetPos;
  v9 = targetRoadLane;
  v10 = mergeLane;
  if ( v7 == (float *)&mergeLane->mStartConnection )
    return 0;
  while ( 1 )
  {
    v11 = v7[24];
    v12 = v7[25];
    v13 = Scaleform::GFx::AS3::Instances::fl::XML::GetName((UFG::RoadNetworkGuide *)v7)->m_LaneT;
    UFG::RoadNetworkLane::GetPos(v9, &result, v13);
    v14 = v13 <= targetLaneT ? v11 + targetRear : v12 + targetFront;
    if ( (float)((float)((float)((float)(v8->x - result.x) * (float)(v8->x - result.x))
                       + (float)((float)(v8->y - result.y) * (float)(v8->y - result.y)))
               + (float)((float)(v8->z - result.z) * (float)(v8->z - result.z))) < (float)((float)(v14 + 0.2)
                                                                                         * (float)(v14 + 0.2)) )
    {
      UFG::RoadNetworkLane::GetPos(v10, &v17, v13);
      UFG::RoadNetworkLane::GetPos(v9, &v18, v13);
      if ( (float)((float)((float)((float)(v17.y - v18.y) * (float)(v17.y - v18.y))
                         + (float)((float)(v17.x - v18.x) * (float)(v17.x - v18.x)))
                 + (float)((float)(v17.z - v18.z) * (float)(v17.z - v18.z))) < 10.240001 )
        break;
    }
    v7 = (float *)(*((_QWORD *)v7 + 4) - 24i64);
    if ( v7 == (float *)v6 )
      return 0;
  }
  return 1;
}

// File Line: 1017
// RVA: 0x64B740
void __fastcall UFG::WheeledVehicleManager::DestroyTrafficVehiclesOnSubSegment(UFG::WheeledVehicleManager *this, UFG::RoadNetworkSubSegment *subSegment, bool queueForDeletion, UFG::RoadNetworkLane *specificLane)
{
  UFG::RoadNetworkSegment *v4; // rdi
  unsigned int v5; // ebp
  UFG::RoadNetworkLane *v6; // r12
  bool v7; // r15
  UFG::WheeledVehicleManager *v8; // r13
  UFG::RoadNetworkLane *v9; // r14
  UFG::RoadNetworkGuide *v10; // rbx
  signed __int64 v11; // rdi
  UFG::RoadNetworkLocation *v12; // rax
  UFG::SimObjectCVBase *v13; // rbx
  unsigned __int16 v14; // cx
  UFG::AiDriverComponent *v15; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v16; // rdx
  signed __int64 v17; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v18; // rax
  UFG::RoadNetworkSegment *v19; // [rsp+20h] [rbp-48h]
  UFG::RoadNetworkSubSegment *v20; // [rsp+78h] [rbp+10h]
  UFG::RoadNetworkLane *v21; // [rsp+88h] [rbp+20h]

  v21 = specificLane;
  v20 = subSegment;
  v4 = subSegment->mParentNode;
  v5 = 0;
  v6 = specificLane;
  v7 = queueForDeletion;
  v8 = this;
  v19 = v4;
  if ( v4->mNumLanes )
  {
    do
    {
      if ( !v6 || v5 == v6->mLaneIndex )
      {
        v9 = UFG::RoadNetworkNode::GetLane((UFG::RoadNetworkNode *)&v4->mType, v5);
        v10 = (UFG::RoadNetworkGuide *)&v9->mCars.mNode.mNext[-2].mNext;
        if ( v10 != (UFG::RoadNetworkGuide *)&v9->mStartConnection )
        {
          do
          {
            v11 = (signed __int64)&v10->mNext[-2].mNext;
            v12 = Scaleform::GFx::AS3::Instances::fl::XML::GetName(v10);
            if ( UFG::RoadNetworkSubSegment::IsWithinSubSegment(v20, v9, v12->m_LaneT) )
            {
              v13 = (UFG::SimObjectCVBase *)v10->m_SimObj;
              if ( v13 )
              {
                v14 = v13->m_Flags;
                if ( (v14 >> 14) & 1 )
                {
                  v15 = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(v13);
                }
                else if ( (v14 & 0x8000u) == 0 )
                {
                  if ( (v14 >> 13) & 1 )
                    v15 = (UFG::AiDriverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                      (UFG::SimObjectGame *)&v13->vfptr,
                                                      UFG::AiDriverComponent::_TypeUID);
                  else
                    v15 = (UFG::AiDriverComponent *)((v14 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                         (UFG::SimObjectGame *)&v13->vfptr,
                                                                         UFG::AiDriverComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v13->vfptr, UFG::AiDriverComponent::_TypeUID));
                }
                else
                {
                  v15 = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(v13);
                }
                if ( v15 && ((unsigned __int8 (__fastcall *)(UFG::AiDriverComponent *))v15->vfptr[16].__vecDelDtor)(v15) )
                {
                  if ( v7 )
                  {
                    v16 = v8->mCarsWithDeletionPending;
                    v17 = 100i64;
                    do
                    {
                      if ( !v16->m_pPointer )
                      {
                        v16->m_pPointer = (UFG::SimObject *)&v13->vfptr;
                        v18 = v13->m_SafePointerList.mNode.mPrev;
                        v18->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v16->mPrev;
                        v16->mPrev = v18;
                        v16->mNext = &v13->m_SafePointerList.mNode;
                        v13->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v16->mPrev;
                      }
                      ++v16;
                      --v17;
                    }
                    while ( v17 );
                  }
                  else
                  {
                    UFG::Simulation::DestroySimObject(&UFG::gSim, (UFG::SimObject *)&v13->vfptr);
                  }
                }
              }
            }
            v10 = (UFG::RoadNetworkGuide *)v11;
          }
          while ( (UFG::qOffset64<UFG::RoadNetworkConnection *> *)v11 != &v9->mStartConnection );
          v6 = v21;
          v4 = v19;
        }
      }
      ++v5;
    }
    while ( v5 < (unsigned __int8)v4->mNumLanes );
  }
}

// File Line: 1052
// RVA: 0x64B1A0
void __fastcall UFG::WheeledVehicleManager::DestroyParkedCarsOnSubSegment(UFG::WheeledVehicleManager *this, UFG::RoadNetworkSubSegment *subSegment)
{
  UFG::RoadNetworkSubSegment *v2; // rsi
  UFG::qNode<UFG::ParkingSpot,UFG::ParkingSpot> *v3; // rbp
  UFG::qNode<UFG::ParkingSpot,UFG::ParkingSpot> *v4; // rdi
  UFG::SimObject *v5; // rbx
  unsigned __int16 v6; // cx
  UFG::VehicleOccupantComponent *v7; // rax
  bool v8; // zf
  UFG::SimObjectGame *v9; // rcx
  UFG::RoadNetworkNode *v10; // rdi
  __int64 v11; // rax
  unsigned int v12; // ebx
  UFG::RoadNetworkLane *v13; // rax

  v2 = subSegment;
  if ( subSegment->mNumParkingSpots )
  {
    v3 = (UFG::qNode<UFG::ParkingSpot,UFG::ParkingSpot> *)&subSegment[-1].mPosition.z;
    v4 = subSegment->mParkingSpotCollection.mNode.mNext - 12;
    if ( v4 != (UFG::qNode<UFG::ParkingSpot,UFG::ParkingSpot> *)&subSegment[-1].mPosition.z )
    {
      do
      {
        v5 = (UFG::SimObject *)v4[11].mNext;
        if ( v5 )
        {
          v6 = v5->m_Flags;
          if ( (v6 >> 14) & 1 )
          {
            v7 = (UFG::VehicleOccupantComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                    (UFG::SimObjectGame *)v4[11].mNext,
                                                    UFG::VehicleOccupantComponent::_TypeUID);
          }
          else if ( (v6 & 0x8000u) == 0 )
          {
            if ( (v6 >> 13) & 1 )
            {
              v7 = (UFG::VehicleOccupantComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                      (UFG::SimObjectGame *)v4[11].mNext,
                                                      UFG::VehicleOccupantComponent::_TypeUID);
            }
            else
            {
              v8 = ((v6 >> 12) & 1) == 0;
              v9 = (UFG::SimObjectGame *)v4[11].mNext;
              v7 = (UFG::VehicleOccupantComponent *)(v8 ? UFG::SimObject::GetComponentOfType(
                                                            (UFG::SimObject *)&v9->vfptr,
                                                            UFG::VehicleOccupantComponent::_TypeUID) : UFG::SimObjectGame::GetComponentOfTypeHK(v9, UFG::VehicleOccupantComponent::_TypeUID));
            }
          }
          else
          {
            v7 = (UFG::VehicleOccupantComponent *)v5->m_Components.p[30].m_pComponent;
          }
          if ( UFG::VehicleOccupantComponent::IsParked(v7) )
            UFG::Simulation::DestroySimObject(&UFG::gSim, v5);
        }
        v4 = v4[12].mNext - 12;
      }
      while ( v4 != v3 );
    }
    v10 = (UFG::RoadNetworkNode *)&v2->mParentNode->mType;
    v11 = v10[1].mPathCollection.mOffset;
    if ( (unsigned int *)v11 == &v10[1].mIndex )
    {
LABEL_19:
      v12 = 0;
      if ( v10->mNumLanes )
      {
        do
        {
          v13 = UFG::RoadNetworkNode::GetLane(v10, v12++);
          v13->mOffset = 0.0;
        }
        while ( v12 < (unsigned __int8)v10->mNumLanes );
      }
    }
    else
    {
      while ( !*(_WORD *)(v11 + 96) )
      {
        v11 = *(_QWORD *)(v11 + 8);
        if ( (unsigned int *)v11 == &v10[1].mIndex )
          goto LABEL_19;
      }
    }
  }
}

// File Line: 1094
// RVA: 0x64B540
__int64 __fastcall UFG::WheeledVehicleManager::DestroyTrafficVehiclesInRange(UFG::WheeledVehicleManager *this, UFG::qVector3 *pos, float radius)
{
  unsigned int v3; // ebp
  UFG::qNode<UFG::RoadSpaceComponent,UFG::RoadSpaceComponent> *v4; // rdi
  UFG::qVector3 *v5; // r15
  UFG::qNode<UFG::RoadSpaceComponent,UFG::RoadSpaceComponent> *v6; // rsi
  UFG::SimObjectVehicle *v7; // rdi
  UFG::qList<UFG::RoadSpaceComponent,UFG::RoadSpaceComponent,1,0> *v8; // rsi
  unsigned __int16 v9; // cx
  UFG::AiDriverComponent *v10; // rax
  unsigned __int16 v11; // cx
  UFG::VehicleSubjectComponent *v12; // rax
  float *v13; // rbx
  float v14; // xmm0_4

  v3 = 0;
  v4 = UFG::RoadSpaceComponent::s_RoadSpaceComponentList.mNode.mNext - 4;
  v5 = pos;
  if ( (UFG::qList<UFG::RoadSpaceComponent,UFG::RoadSpaceComponent,1,0> *)&UFG::RoadSpaceComponent::s_RoadSpaceComponentList.mNode.mNext[-4] != &UFG::RoadSpaceComponent::s_RoadSpaceComponentList - 4 )
  {
    do
    {
      v6 = v4[4].mNext;
      v7 = (UFG::SimObjectVehicle *)v4[2].mNext;
      v8 = (UFG::qList<UFG::RoadSpaceComponent,UFG::RoadSpaceComponent,1,0> *)&v6[-4];
      if ( v7 )
      {
        v9 = v7->m_Flags;
        if ( (v9 >> 14) & 1 )
        {
          v10 = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>((UFG::SimObjectCVBase *)&v7->vfptr);
        }
        else if ( (v9 & 0x8000u) == 0 )
        {
          if ( (v9 >> 13) & 1 )
            v10 = (UFG::AiDriverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                              (UFG::SimObjectGame *)&v7->vfptr,
                                              UFG::AiDriverComponent::_TypeUID);
          else
            v10 = (UFG::AiDriverComponent *)((v9 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                (UFG::SimObjectGame *)&v7->vfptr,
                                                                UFG::AiDriverComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v7->vfptr, UFG::AiDriverComponent::_TypeUID));
        }
        else
        {
          v10 = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>((UFG::SimObjectCVBase *)&v7->vfptr);
        }
        if ( v10 && ((unsigned __int8 (__fastcall *)(UFG::AiDriverComponent *))v10->vfptr[16].__vecDelDtor)(v10) )
        {
          v11 = v7->m_Flags;
          if ( (v11 >> 14) & 1 )
          {
            v12 = (UFG::VehicleSubjectComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                    (UFG::SimObjectGame *)&v7->vfptr,
                                                    UFG::VehicleSubjectComponent::_TypeUID);
          }
          else if ( (v11 & 0x8000u) == 0 )
          {
            if ( (v11 >> 13) & 1 )
              v12 = (UFG::VehicleSubjectComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                      (UFG::SimObjectGame *)&v7->vfptr,
                                                      UFG::VehicleSubjectComponent::_TypeUID);
            else
              v12 = (UFG::VehicleSubjectComponent *)((v11 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                         (UFG::SimObjectGame *)&v7->vfptr,
                                                                         UFG::VehicleSubjectComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v7->vfptr, UFG::VehicleSubjectComponent::_TypeUID));
          }
          else
          {
            v12 = UFG::SimObjectVehicle::GetComponent<UFG::VehicleSubjectComponent>(v7);
          }
          if ( !v12
            || !((unsigned __int8 (__fastcall *)(UFG::VehicleSubjectComponent *))v12->vfptr[46].__vecDelDtor)(v12) )
          {
            v13 = (float *)v7->m_pTransformNodeComponent;
            UFG::TransformNodeComponent::UpdateWorldTransform(v7->m_pTransformNodeComponent);
            v14 = v5->y - v13[45];
            if ( (float)((float)((float)((float)(v5->x - v13[44]) * (float)(v5->x - v13[44])) + (float)(v14 * v14))
                       + (float)((float)(v5->z - v13[46]) * (float)(v5->z - v13[46]))) <= (float)(radius * radius) )
            {
              UFG::Simulation::DestroySimObject(&UFG::gSim, (UFG::SimObject *)&v7->vfptr);
              ++v3;
            }
          }
        }
      }
      v4 = &v8->mNode;
    }
    while ( v8 != &UFG::RoadSpaceComponent::s_RoadSpaceComponentList - 4 );
  }
  return v3;
}

// File Line: 1123
// RVA: 0x64B2F0
__int64 __fastcall UFG::WheeledVehicleManager::DestroyParkedVehiclesInRange(UFG::WheeledVehicleManager *this, UFG::qVector3 *pos, float radius)
{
  UFG::VehicleOccupantComponent *v3; // rdi
  unsigned int v4; // ebp
  UFG::qVector3 *v5; // r15
  UFG::LinearGraph<float> *v6; // rbx
  UFG::SimObject *v7; // rdi
  UFG::TransformNodeComponent *v8; // rsi
  float v9; // xmm0_4
  char *v10; // rsi
  __int64 v11; // rdi
  UFG::SimObject *v12; // rsi
  const float *v13; // rdi
  UFG::StreamedResourceComponent *v14; // rcx
  UFG::TransformNodeComponent *v15; // rbx
  float v16; // xmm0_4

  v3 = (UFG::VehicleOccupantComponent *)&UFG::VehicleOccupantComponent::s_VehicleOccupantComponentList.mNode.mNext[-4];
  v4 = 0;
  v5 = pos;
  if ( (const float **)&UFG::VehicleOccupantComponent::s_VehicleOccupantComponentList.mNode.mNext[-4] != &stru_142091488.fDomain )
  {
    do
    {
      v6 = (UFG::LinearGraph<float> *)&v3->mNext[-4];
      if ( UFG::VehicleOccupantComponent::IsParked(v3) )
      {
        v7 = v3->m_pSimObject;
        v8 = v7 ? v7->m_pTransformNodeComponent : 0i64;
        UFG::TransformNodeComponent::UpdateWorldTransform(v8);
        v9 = v5->y - v8->mWorldTransform.v3.y;
        if ( (float)((float)((float)((float)(v5->x - v8->mWorldTransform.v3.x)
                                   * (float)(v5->x - v8->mWorldTransform.v3.x))
                           + (float)(v9 * v9))
                   + (float)((float)(v5->z - v8->mWorldTransform.v3.z) * (float)(v5->z - v8->mWorldTransform.v3.z))) <= (float)(radius * radius) )
        {
          UFG::Simulation::DestroySimObject(&UFG::gSim, v7);
          ++v4;
        }
      }
      v3 = (UFG::VehicleOccupantComponent *)v6;
    }
    while ( v6 != (UFG::LinearGraph<float> *)&stru_142091488.fDomain );
  }
  v10 = (char *)&UFG::PhysicsMoverInterface::s_PhysicsMoverInterfaceList.mNode.mNext[-5].mNext;
  if ( (const float *)&UFG::PhysicsMoverInterface::s_PhysicsMoverInterfaceList.mNode.mNext[-5].mNext != &A_cos_280_deg_40 )
  {
    do
    {
      v11 = *((_QWORD *)v10 + 10);
      v12 = (UFG::SimObject *)*((_QWORD *)v10 + 5);
      v13 = (const float *)(v11 - 72);
      if ( v12 )
      {
        v14 = (UFG::StreamedResourceComponent *)v12->m_Components.p[10].m_pComponent;
        if ( v14 )
        {
          if ( UFG::StreamedResourceComponent::GetSpawnPriority(v14, 0i64)->mUID == qSymbol_Low.mUID )
          {
            v15 = (UFG::TransformNodeComponent *)v12->m_Components.p[2].m_pComponent;
            UFG::TransformNodeComponent::UpdateWorldTransform(v15);
            v16 = v5->z - v15->mWorldTransform.v3.z;
            if ( (float)((float)((float)((float)(v5->y - v15->mWorldTransform.v3.y)
                                       * (float)(v5->y - v15->mWorldTransform.v3.y))
                               + (float)((float)(v5->x - v15->mWorldTransform.v3.x)
                                       * (float)(v5->x - v15->mWorldTransform.v3.x)))
                       + (float)(v16 * v16)) <= (float)(radius * radius) )
            {
              UFG::Simulation::DestroySimObject(&UFG::gSim, v12);
              ++v4;
            }
          }
        }
      }
      v10 = (char *)v13;
    }
    while ( v13 != &A_cos_280_deg_40 );
  }
  return v4;
}

// File Line: 1166
// RVA: 0x6575C0
void __fastcall UFG::WheeledVehicleManager::OnVisibleAreaChange(UFG::WheeledVehicleManager *this, UFG::qArray<UFG::RoadNetworkSubSegment *,0> *deactivateSubSegments, UFG::qArray<UFG::RoadNetworkSubSegment *,0> *activateSubSegments)
{
  __int64 v3; // r12
  UFG::qArray<UFG::RoadNetworkSubSegment *,0> *v4; // rax
  UFG::qArray<UFG::RoadNetworkSubSegment *,0> *v5; // rbx
  UFG::WheeledVehicleManager *v6; // rdi
  unsigned int v7; // ebp
  __int64 v8; // rcx
  UFG::RoadNetworkSubSegment *v9; // r13
  UFG::RoadNetworkNode *v10; // r15
  UFG::RoadNetworkLane *v11; // r14
  UFG::RoadNetworkGuide *v12; // rbx
  signed __int64 v13; // rdi
  UFG::RoadNetworkLocation *v14; // rax
  UFG::SimObjectCVBase *v15; // rbx
  unsigned __int16 v16; // cx
  UFG::AiDriverComponent *v17; // rax
  UFG::WheeledVehicleManager *v18; // [rsp+60h] [rbp+8h]
  UFG::qArray<UFG::RoadNetworkSubSegment *,0> *v19; // [rsp+68h] [rbp+10h]
  UFG::qArray<UFG::RoadNetworkSubSegment *,0> *v20; // [rsp+70h] [rbp+18h]

  v20 = activateSubSegments;
  v19 = deactivateSubSegments;
  v18 = this;
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
      v10 = (UFG::RoadNetworkNode *)&v9->mParentNode->mType;
      if ( v10->mNumLanes )
      {
        do
        {
          v11 = UFG::RoadNetworkNode::GetLane(v10, v7);
          v12 = (UFG::RoadNetworkGuide *)&v11->mCars.mNode.mNext[-2].mNext;
          if ( v12 != (UFG::RoadNetworkGuide *)&v11->mStartConnection )
          {
            do
            {
              v13 = (signed __int64)&v12->mNext[-2].mNext;
              v14 = Scaleform::GFx::AS3::Instances::fl::XML::GetName(v12);
              if ( UFG::RoadNetworkSubSegment::IsWithinSubSegment(v9, v11, v14->m_LaneT) )
              {
                v15 = (UFG::SimObjectCVBase *)v12->m_SimObj;
                if ( v15 )
                {
                  v16 = v15->m_Flags;
                  if ( (v16 >> 14) & 1 )
                  {
                    v17 = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(v15);
                  }
                  else if ( (v16 & 0x8000u) == 0 )
                  {
                    if ( (v16 >> 13) & 1 )
                    {
                      v17 = (UFG::AiDriverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                        (UFG::SimObjectGame *)&v15->vfptr,
                                                        UFG::AiDriverComponent::_TypeUID);
                    }
                    else if ( (v16 >> 12) & 1 )
                    {
                      v17 = (UFG::AiDriverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                        (UFG::SimObjectGame *)&v15->vfptr,
                                                        UFG::AiDriverComponent::_TypeUID);
                    }
                    else
                    {
                      v17 = (UFG::AiDriverComponent *)UFG::SimObject::GetComponentOfType(
                                                        (UFG::SimObject *)&v15->vfptr,
                                                        UFG::AiDriverComponent::_TypeUID);
                    }
                  }
                  else
                  {
                    v17 = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(v15);
                  }
                  if ( v17
                    && ((unsigned __int8 (__fastcall *)(UFG::AiDriverComponent *))v17->vfptr[16].__vecDelDtor)(v17) )
                  {
                    UFG::Simulation::DestroySimObject(&UFG::gSim, (UFG::SimObject *)&v15->vfptr);
                  }
                }
              }
              v12 = (UFG::RoadNetworkGuide *)v13;
            }
            while ( (UFG::qOffset64<UFG::RoadNetworkConnection *> *)v13 != &v11->mStartConnection );
          }
          ++v7;
        }
        while ( v7 < (unsigned __int8)v10->mNumLanes );
        v5 = v19;
        v6 = v18;
        v8 = (unsigned int)v3;
      }
      UFG::WheeledVehicleManager::DestroyParkedCarsOnSubSegment(v6, v5->p[v8]);
      v3 = (unsigned int)(v3 + 1);
    }
    while ( (unsigned int)v3 < v5->size );
    v4 = v20;
  }
  UFG::WheeledVehicleManager::ActivateSubSegments(v6, v4);
}

// File Line: 1225
// RVA: 0x64B080
void __fastcall UFG::WheeledVehicleManager::DestroyCarsOnRoad(UFG::WheeledVehicleManager *this, UFG::RoadNetworkNode *node)
{
  unsigned int v2; // ebp
  UFG::RoadNetworkNode *v3; // r14
  UFG::RoadNetworkLane *v4; // rax
  signed __int64 v5; // rsi
  signed __int64 v6; // rbx
  __int64 v7; // rdi
  UFG::SimObjectCVBase *v8; // rbx
  signed __int64 v9; // rdi
  unsigned __int16 v10; // cx
  UFG::AiDriverComponent *v11; // rax

  v2 = 0;
  v3 = node;
  if ( node->mNumLanes )
  {
    do
    {
      v4 = UFG::RoadNetworkNode::GetLane(v3, v2);
      v5 = (signed __int64)&v4->mStartConnection;
      v6 = (signed __int64)&v4->mCars.mNode.mNext[-2].mNext;
      if ( (UFG::qOffset64<UFG::RoadNetworkConnection *> *)v6 != &v4->mStartConnection )
      {
        do
        {
          v7 = *(_QWORD *)(v6 + 32);
          v8 = *(UFG::SimObjectCVBase **)(v6 + 72);
          v9 = v7 - 24;
          if ( v8 )
          {
            v10 = v8->m_Flags;
            if ( (v10 >> 14) & 1 )
            {
              v11 = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(v8);
            }
            else if ( (v10 & 0x8000u) == 0 )
            {
              if ( (v10 >> 13) & 1 )
              {
                v11 = (UFG::AiDriverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                  (UFG::SimObjectGame *)&v8->vfptr,
                                                  UFG::AiDriverComponent::_TypeUID);
              }
              else if ( (v10 >> 12) & 1 )
              {
                v11 = (UFG::AiDriverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                  (UFG::SimObjectGame *)&v8->vfptr,
                                                  UFG::AiDriverComponent::_TypeUID);
              }
              else
              {
                v11 = (UFG::AiDriverComponent *)UFG::SimObject::GetComponentOfType(
                                                  (UFG::SimObject *)&v8->vfptr,
                                                  UFG::AiDriverComponent::_TypeUID);
              }
            }
            else
            {
              v11 = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(v8);
            }
            if ( v11 )
            {
              if ( ((unsigned __int8 (__fastcall *)(UFG::AiDriverComponent *))v11->vfptr[16].__vecDelDtor)(v11) )
                UFG::Simulation::DestroySimObject(&UFG::gSim, (UFG::SimObject *)&v8->vfptr);
            }
          }
          v6 = v9;
        }
        while ( v9 != v5 );
      }
      ++v2;
    }
    while ( v2 < (unsigned __int8)v3->mNumLanes );
  }
}

// File Line: 1268
// RVA: 0x64AB10
void __fastcall UFG::WheeledVehicleManager::DestroyAllNonParkedWheeledVehicles(UFG::WheeledVehicleManager *this)
{
  UFG::qNode<UFG::RoadSpaceComponent,UFG::RoadSpaceComponent> *v1; // rbx
  UFG::qNode<UFG::RoadSpaceComponent,UFG::RoadSpaceComponent> *v2; // rbp
  UFG::SimObjectCVBase *v3; // rbx
  UFG::qVector3 *v4; // rbp
  unsigned __int16 v5; // cx
  UFG::AiDriverComponent *v6; // rax
  unsigned __int16 v7; // cx
  UFG::AiDriverComponent *v8; // rsi
  UFG::SimComponent *v9; // rax
  UFG::VehicleOccupantComponent *v10; // rdi
  char *v11; // rbx
  __int64 v12; // rbp
  UFG::SimObjectGame *v13; // rbx
  const float *v14; // rbp
  unsigned __int16 v15; // cx
  UFG::StreamedResourceComponent *v16; // rsi
  UFG::SimComponent *v17; // rax
  unsigned __int16 v18; // cx
  UFG::SimComponent *v19; // rax
  UFG::VehicleOccupantComponent *v20; // rdi

  v1 = UFG::RoadSpaceComponent::s_RoadSpaceComponentList.mNode.mNext - 4;
  if ( (UFG::qVector3 *)&UFG::RoadSpaceComponent::s_RoadSpaceComponentList.mNode.mNext[-4] != &UFG::AiDriverComponent::mCombatBoatOffsets[2] )
  {
    while ( 1 )
    {
      v2 = v1[4].mNext;
      v3 = (UFG::SimObjectCVBase *)v1[2].mNext;
      v4 = (UFG::qVector3 *)&v2[-4];
      if ( v3 )
        break;
LABEL_27:
      v1 = (UFG::qNode<UFG::RoadSpaceComponent,UFG::RoadSpaceComponent> *)v4;
      if ( v4 == &UFG::AiDriverComponent::mCombatBoatOffsets[2] )
        goto LABEL_28;
    }
    v5 = v3->m_Flags;
    if ( (v5 >> 14) & 1 )
    {
      v6 = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(v3);
    }
    else if ( (v5 & 0x8000u) == 0 )
    {
      if ( (v5 >> 13) & 1 )
      {
        v6 = (UFG::AiDriverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                         (UFG::SimObjectGame *)&v3->vfptr,
                                         UFG::AiDriverComponent::_TypeUID);
      }
      else if ( (v5 >> 12) & 1 )
      {
        v6 = (UFG::AiDriverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                         (UFG::SimObjectGame *)&v3->vfptr,
                                         UFG::AiDriverComponent::_TypeUID);
      }
      else
      {
        v6 = (UFG::AiDriverComponent *)UFG::SimObject::GetComponentOfType(
                                         (UFG::SimObject *)&v3->vfptr,
                                         UFG::AiDriverComponent::_TypeUID);
      }
    }
    else
    {
      v6 = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(v3);
    }
    v7 = v3->m_Flags;
    v8 = v6;
    if ( (v7 >> 14) & 1 )
    {
      v9 = UFG::SimObjectGame::GetComponentOfTypeHK(
             (UFG::SimObjectGame *)&v3->vfptr,
             UFG::VehicleOccupantComponent::_TypeUID);
    }
    else
    {
      if ( (v7 & 0x8000u) != 0 )
      {
        v10 = (UFG::VehicleOccupantComponent *)v3->m_Components.p[30].m_pComponent;
LABEL_22:
        if ( v8
          && ((unsigned __int8 (__fastcall *)(UFG::AiDriverComponent *))v8->vfptr[16].__vecDelDtor)(v8)
          && v10
          && !UFG::VehicleOccupantComponent::IsParked(v10) )
        {
          UFG::Simulation::DestroySimObject(&UFG::gSim, (UFG::SimObject *)&v3->vfptr);
        }
        goto LABEL_27;
      }
      if ( (v7 >> 13) & 1 )
      {
        v9 = UFG::SimObjectGame::GetComponentOfTypeHK(
               (UFG::SimObjectGame *)&v3->vfptr,
               UFG::VehicleOccupantComponent::_TypeUID);
      }
      else if ( (v7 >> 12) & 1 )
      {
        v9 = UFG::SimObjectGame::GetComponentOfTypeHK(
               (UFG::SimObjectGame *)&v3->vfptr,
               UFG::VehicleOccupantComponent::_TypeUID);
      }
      else
      {
        v9 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::VehicleOccupantComponent::_TypeUID);
      }
    }
    v10 = (UFG::VehicleOccupantComponent *)v9;
    goto LABEL_22;
  }
LABEL_28:
  v11 = (char *)&UFG::PhysicsMoverInterface::s_PhysicsMoverInterfaceList.mNode.mNext[-5].mNext;
  if ( (const float *)&UFG::PhysicsMoverInterface::s_PhysicsMoverInterfaceList.mNode.mNext[-5].mNext != &A_cos_280_deg_40 )
  {
    while ( 1 )
    {
      v12 = *((_QWORD *)v11 + 10);
      v13 = (UFG::SimObjectGame *)*((_QWORD *)v11 + 5);
      v14 = (const float *)(v12 - 72);
      if ( v13 )
        break;
LABEL_55:
      v11 = (char *)v14;
      if ( v14 == &A_cos_280_deg_40 )
        return;
    }
    v15 = v13->m_Flags;
    if ( (v15 >> 14) & 1 )
    {
      v16 = (UFG::StreamedResourceComponent *)v13->m_Components.p[10].m_pComponent;
    }
    else if ( (v15 & 0x8000u) == 0 )
    {
      if ( (v15 >> 13) & 1 )
      {
        v16 = (UFG::StreamedResourceComponent *)v13->m_Components.p[7].m_pComponent;
      }
      else
      {
        if ( (v15 >> 12) & 1 )
          v17 = UFG::SimObjectGame::GetComponentOfTypeHK(v13, UFG::StreamedResourceComponent::_TypeUID);
        else
          v17 = UFG::SimObject::GetComponentOfType(
                  (UFG::SimObject *)&v13->vfptr,
                  UFG::StreamedResourceComponent::_TypeUID);
        v16 = (UFG::StreamedResourceComponent *)v17;
      }
    }
    else
    {
      v16 = (UFG::StreamedResourceComponent *)v13->m_Components.p[10].m_pComponent;
    }
    v18 = v13->m_Flags;
    if ( (v18 >> 14) & 1 )
    {
      v19 = UFG::SimObjectGame::GetComponentOfTypeHK(v13, UFG::VehicleOccupantComponent::_TypeUID);
    }
    else
    {
      if ( (v18 & 0x8000u) != 0 )
      {
        v20 = (UFG::VehicleOccupantComponent *)v13->m_Components.p[30].m_pComponent;
LABEL_50:
        if ( v16
          && UFG::StreamedResourceComponent::GetSpawnPriority(v16, 0i64)->mUID == qSymbol_Low.mUID
          && v20
          && !UFG::VehicleOccupantComponent::IsParked(v20) )
        {
          UFG::Simulation::DestroySimObject(&UFG::gSim, (UFG::SimObject *)&v13->vfptr);
        }
        goto LABEL_55;
      }
      if ( (v18 >> 13) & 1 )
      {
        v19 = UFG::SimObjectGame::GetComponentOfTypeHK(v13, UFG::VehicleOccupantComponent::_TypeUID);
      }
      else if ( (v18 >> 12) & 1 )
      {
        v19 = UFG::SimObjectGame::GetComponentOfTypeHK(v13, UFG::VehicleOccupantComponent::_TypeUID);
      }
      else
      {
        v19 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v13->vfptr, UFG::VehicleOccupantComponent::_TypeUID);
      }
    }
    v20 = (UFG::VehicleOccupantComponent *)v19;
    goto LABEL_50;
  }
}

// File Line: 1300
// RVA: 0x64ADF0
void __fastcall UFG::WheeledVehicleManager::DestroyAllWheeledVehicles(UFG::WheeledVehicleManager *this)
{
  UFG::qNode<UFG::RoadSpaceComponent,UFG::RoadSpaceComponent> *v1; // rbx
  UFG::qNode<UFG::RoadSpaceComponent,UFG::RoadSpaceComponent> *v2; // rdi
  UFG::SimObjectCVBase *v3; // rbx
  UFG::qVector3 *v4; // rdi
  unsigned __int16 v5; // cx
  UFG::AiDriverComponent *v6; // rax
  UFG::qNode<UFG::VehicleOccupantComponent,UFG::VehicleOccupantComponent> *v7; // rbx
  UFG::qNode<UFG::VehicleOccupantComponent,UFG::VehicleOccupantComponent> *v8; // rdi
  UFG::SimObjectGame *v9; // rbx
  UFG::LinearGraph<float> *v10; // rdi
  UFG::VehicleOccupantComponent *v11; // rax
  unsigned __int16 v12; // cx
  UFG::qList<UFG::PhysicsMoverInterface,UFG::PhysicsMoverInterface,1,0> *v13; // rbx
  UFG::qNode<UFG::PhysicsMoverInterface,UFG::PhysicsMoverInterface> *v14; // rdi
  UFG::SimObjectGame *v15; // rbx
  UFG::qList<UFG::PhysicsMoverInterface,UFG::PhysicsMoverInterface,1,0> *v16; // rdi
  unsigned __int16 v17; // cx
  UFG::StreamedResourceComponent *v18; // rax

  v1 = UFG::RoadSpaceComponent::s_RoadSpaceComponentList.mNode.mNext - 4;
  if ( (UFG::qVector3 *)&UFG::RoadSpaceComponent::s_RoadSpaceComponentList.mNode.mNext[-4] != &UFG::AiDriverComponent::mCombatBoatOffsets[2] )
  {
    do
    {
      v2 = v1[4].mNext;
      v3 = (UFG::SimObjectCVBase *)v1[2].mNext;
      v4 = (UFG::qVector3 *)&v2[-4];
      if ( v3 )
      {
        v5 = v3->m_Flags;
        if ( (v5 >> 14) & 1 )
        {
          v6 = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(v3);
        }
        else if ( (v5 & 0x8000u) == 0 )
        {
          if ( (v5 >> 13) & 1 )
            v6 = (UFG::AiDriverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                             (UFG::SimObjectGame *)&v3->vfptr,
                                             UFG::AiDriverComponent::_TypeUID);
          else
            v6 = (UFG::AiDriverComponent *)((v5 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                               (UFG::SimObjectGame *)&v3->vfptr,
                                                               UFG::AiDriverComponent::_TypeUID) : UFG::SimObject::GetComponentOfType(
                                                                                                     (UFG::SimObject *)&v3->vfptr,
                                                                                                     UFG::AiDriverComponent::_TypeUID));
        }
        else
        {
          v6 = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(v3);
        }
        if ( v6 && ((unsigned __int8 (__fastcall *)(UFG::AiDriverComponent *))v6->vfptr[16].__vecDelDtor)(v6) )
          UFG::Simulation::DestroySimObject(&UFG::gSim, (UFG::SimObject *)&v3->vfptr);
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
        if ( (v12 >> 14) & 1 )
        {
          v11 = (UFG::VehicleOccupantComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                   v9,
                                                   UFG::VehicleOccupantComponent::_TypeUID);
        }
        else if ( (v12 & 0x8000u) == 0 )
        {
          if ( (v12 >> 13) & 1 )
          {
            v11 = (UFG::VehicleOccupantComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                     v9,
                                                     UFG::VehicleOccupantComponent::_TypeUID);
          }
          else if ( (v12 >> 12) & 1 )
          {
            v11 = (UFG::VehicleOccupantComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                     v9,
                                                     UFG::VehicleOccupantComponent::_TypeUID);
          }
          else
          {
            v11 = (UFG::VehicleOccupantComponent *)UFG::SimObject::GetComponentOfType(
                                                     (UFG::SimObject *)&v9->vfptr,
                                                     UFG::VehicleOccupantComponent::_TypeUID);
          }
        }
        else
        {
          v11 = (UFG::VehicleOccupantComponent *)v9->m_Components.p[30].m_pComponent;
        }
      }
      else
      {
        v11 = 0i64;
      }
      if ( UFG::VehicleOccupantComponent::IsParked(v11) == 1 )
        UFG::Simulation::DestroySimObject(&UFG::gSim, (UFG::SimObject *)&v9->vfptr);
      v7 = (UFG::qNode<UFG::VehicleOccupantComponent,UFG::VehicleOccupantComponent> *)v10;
    }
    while ( v10 != (UFG::LinearGraph<float> *)&stru_142091488.fDomain );
  }
  v13 = (UFG::qList<UFG::PhysicsMoverInterface,UFG::PhysicsMoverInterface,1,0> *)&UFG::PhysicsMoverInterface::s_PhysicsMoverInterfaceList.mNode.mNext[-5].mNext;
  if ( (const float *)&UFG::PhysicsMoverInterface::s_PhysicsMoverInterfaceList.mNode.mNext[-5].mNext != &A_cos_280_deg_40 )
  {
    do
    {
      v14 = v13[5].mNode.mPrev;
      v15 = (UFG::SimObjectGame *)v13[2].mNode.mNext;
      v16 = (UFG::qList<UFG::PhysicsMoverInterface,UFG::PhysicsMoverInterface,1,0> *)&v14[-5].mNext;
      if ( v15 )
      {
        v17 = v15->m_Flags;
        if ( (v17 >> 14) & 1 )
        {
          v18 = (UFG::StreamedResourceComponent *)v15->m_Components.p[10].m_pComponent;
        }
        else if ( (v17 & 0x8000u) == 0 )
        {
          if ( (v17 >> 13) & 1 )
          {
            v18 = (UFG::StreamedResourceComponent *)v15->m_Components.p[7].m_pComponent;
          }
          else if ( (v17 >> 12) & 1 )
          {
            v18 = (UFG::StreamedResourceComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                      v15,
                                                      UFG::StreamedResourceComponent::_TypeUID);
          }
          else
          {
            v18 = (UFG::StreamedResourceComponent *)UFG::SimObject::GetComponentOfType(
                                                      (UFG::SimObject *)&v15->vfptr,
                                                      UFG::StreamedResourceComponent::_TypeUID);
          }
        }
        else
        {
          v18 = (UFG::StreamedResourceComponent *)v15->m_Components.p[10].m_pComponent;
        }
        if ( v18 )
        {
          if ( UFG::StreamedResourceComponent::GetSpawnPriority(v18, 0i64)->mUID == qSymbol_Low.mUID )
            UFG::Simulation::DestroySimObject(&UFG::gSim, (UFG::SimObject *)&v15->vfptr);
        }
      }
      v13 = v16;
    }
    while ( v16 != (UFG::qList<UFG::PhysicsMoverInterface,UFG::PhysicsMoverInterface,1,0> *)&A_cos_280_deg_40 );
  }
}

// File Line: 1343
// RVA: 0x64BA90
void __fastcall UFG::WheeledVehicleManager::DestroyWheeledVehiclesInNISBoundingVolume(UFG::WheeledVehicleManager *this, UFG::qVector3 *aabbMin, UFG::qVector3 *aabbMax)
{
  float v3; // xmm6_4
  float v4; // xmm7_4
  UFG::qNode<UFG::RoadSpaceComponent,UFG::RoadSpaceComponent> *v5; // rbx
  float v6; // xmm8_4
  float v7; // xmm9_4
  float v8; // xmm10_4
  float v9; // xmm11_4
  UFG::qNode<UFG::RoadSpaceComponent,UFG::RoadSpaceComponent> *v10; // rdi
  UFG::SimObjectCVBase *v11; // rbx
  UFG::qVector3 *v12; // rdi
  unsigned __int16 v13; // cx
  UFG::AiDriverComponent *v14; // rax
  unsigned __int16 v15; // cx
  UFG::SimComponent *v16; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v17; // rcx
  float v18; // xmm1_4
  float v19; // xmm2_4
  __int128 v20; // xmm1
  __int128 v21; // xmm0
  UFG::qNode<UFG::VehicleOccupantComponent,UFG::VehicleOccupantComponent> *v22; // rbx
  UFG::qNode<UFG::VehicleOccupantComponent,UFG::VehicleOccupantComponent> *v23; // rdi
  UFG::SimObjectGame *v24; // rbx
  UFG::LinearGraph<float> *v25; // rdi
  UFG::VehicleOccupantComponent *v26; // rax
  unsigned __int16 v27; // cx
  unsigned __int16 v28; // cx
  UFG::SimComponent *v29; // rax
  float *v30; // rcx
  float v31; // xmm1_4
  float v32; // xmm2_4
  float v33; // xmm1_4
  float v34; // xmm2_4
  char *v35; // rdi
  __int64 v36; // rbx
  UFG::SimObject *v37; // rdi
  const float *v38; // rbx
  UFG::StreamedResourceComponent *v39; // rcx
  UFG::SimComponent *v40; // rcx
  float *v41; // rax
  float v42; // xmm1_4
  float v43; // xmm2_4
  float v44; // xmm1_4
  float v45; // xmm2_4
  UFG::qVector3 max; // [rsp+18h] [rbp-29h]
  UFG::qVector3 min; // [rsp+28h] [rbp-19h]

  v3 = aabbMin->y;
  v4 = aabbMin->z;
  v5 = UFG::RoadSpaceComponent::s_RoadSpaceComponentList.mNode.mNext - 4;
  v6 = aabbMax->x;
  v7 = aabbMax->y;
  v8 = aabbMax->z;
  v9 = aabbMin->x;
  if ( (UFG::qVector3 *)&UFG::RoadSpaceComponent::s_RoadSpaceComponentList.mNode.mNext[-4] != &UFG::AiDriverComponent::mCombatBoatOffsets[2] )
  {
    do
    {
      v10 = v5[4].mNext;
      v11 = (UFG::SimObjectCVBase *)v5[2].mNext;
      v12 = (UFG::qVector3 *)&v10[-4];
      if ( v11 )
      {
        v13 = v11->m_Flags;
        if ( (v13 >> 14) & 1 )
        {
          v14 = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(v11);
        }
        else if ( (v13 & 0x8000u) == 0 )
        {
          if ( (v13 >> 13) & 1 )
            v14 = (UFG::AiDriverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                              (UFG::SimObjectGame *)&v11->vfptr,
                                              UFG::AiDriverComponent::_TypeUID);
          else
            v14 = (UFG::AiDriverComponent *)((v13 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                 (UFG::SimObjectGame *)&v11->vfptr,
                                                                 UFG::AiDriverComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v11->vfptr, UFG::AiDriverComponent::_TypeUID));
        }
        else
        {
          v14 = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(v11);
        }
        if ( v14 && ((unsigned __int8 (__fastcall *)(UFG::AiDriverComponent *))v14->vfptr[16].__vecDelDtor)(v14) )
        {
          v15 = v11->m_Flags;
          if ( (v15 >> 14) & 1 )
          {
            v16 = v11->m_Components.p[14].m_pComponent;
          }
          else if ( (v15 & 0x8000u) == 0 )
          {
            if ( (v15 >> 13) & 1 )
              v16 = v11->m_Components.p[9].m_pComponent;
            else
              v16 = (v15 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                        (UFG::SimObjectGame *)&v11->vfptr,
                                        UFG::CompositeDrawableComponent::_TypeUID) : UFG::SimObject::GetComponentOfType(
                                                                                       (UFG::SimObject *)&v11->vfptr,
                                                                                       UFG::CompositeDrawableComponent::_TypeUID);
          }
          else
          {
            v16 = v11->m_Components.p[14].m_pComponent;
          }
          if ( v16 )
          {
            v17 = v16[22].m_SafePointerList.mNode.mNext;
            if ( v17 )
            {
              v18 = *((float *)&v17[8].mPrev + 1);
              v19 = *(float *)&v17[8].mNext;
              min.x = *(float *)&v17[8].mPrev;
              min.y = v18;
              min.z = v19;
              v20 = LODWORD(v17[9].mPrev);
              v21 = HIDWORD(v17[8].mNext);
              max.z = *((float *)&v17[9].mPrev + 1);
              TransformAABB((UFG::qMatrix44 *)&v16[20], &min, &max);
              if ( v9 <= max.x && v6 >= min.x && v3 <= max.y && v7 >= min.y && v4 <= max.z && v8 >= min.z )
                UFG::Simulation::DestroySimObject(&UFG::gSim, (UFG::SimObject *)&v11->vfptr);
            }
          }
        }
      }
      v5 = (UFG::qNode<UFG::RoadSpaceComponent,UFG::RoadSpaceComponent> *)v12;
    }
    while ( v12 != &UFG::AiDriverComponent::mCombatBoatOffsets[2] );
  }
  v22 = UFG::VehicleOccupantComponent::s_VehicleOccupantComponentList.mNode.mNext - 4;
  if ( (const float **)&UFG::VehicleOccupantComponent::s_VehicleOccupantComponentList.mNode.mNext[-4] != &stru_142091488.fDomain )
  {
    do
    {
      v23 = v22[4].mNext;
      v24 = (UFG::SimObjectGame *)v22[2].mNext;
      v25 = (UFG::LinearGraph<float> *)&v23[-4];
      if ( v24 )
      {
        v27 = v24->m_Flags;
        if ( (v27 >> 14) & 1 )
        {
          v26 = (UFG::VehicleOccupantComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                   v24,
                                                   UFG::VehicleOccupantComponent::_TypeUID);
        }
        else if ( (v27 & 0x8000u) == 0 )
        {
          if ( (v27 >> 13) & 1 )
          {
            v26 = (UFG::VehicleOccupantComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                     v24,
                                                     UFG::VehicleOccupantComponent::_TypeUID);
          }
          else if ( (v27 >> 12) & 1 )
          {
            v26 = (UFG::VehicleOccupantComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                     v24,
                                                     UFG::VehicleOccupantComponent::_TypeUID);
          }
          else
          {
            v26 = (UFG::VehicleOccupantComponent *)UFG::SimObject::GetComponentOfType(
                                                     (UFG::SimObject *)&v24->vfptr,
                                                     UFG::VehicleOccupantComponent::_TypeUID);
          }
        }
        else
        {
          v26 = (UFG::VehicleOccupantComponent *)v24->m_Components.p[30].m_pComponent;
        }
      }
      else
      {
        v26 = 0i64;
      }
      if ( UFG::VehicleOccupantComponent::IsParked(v26) == 1 && v24 )
      {
        v28 = v24->m_Flags;
        if ( (v28 >> 14) & 1 )
        {
          v29 = v24->m_Components.p[14].m_pComponent;
        }
        else if ( (v28 & 0x8000u) == 0 )
        {
          if ( (v28 >> 13) & 1 )
            v29 = v24->m_Components.p[9].m_pComponent;
          else
            v29 = (v28 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                      v24,
                                      UFG::CompositeDrawableComponent::_TypeUID) : UFG::SimObject::GetComponentOfType(
                                                                                     (UFG::SimObject *)&v24->vfptr,
                                                                                     UFG::CompositeDrawableComponent::_TypeUID);
        }
        else
        {
          v29 = v24->m_Components.p[14].m_pComponent;
        }
        if ( v29 )
        {
          v30 = (float *)v29[22].m_SafePointerList.mNode.mNext;
          if ( v30 )
          {
            v31 = v30[33];
            v32 = v30[34];
            max.x = v30[32];
            max.y = v31;
            max.z = v32;
            v33 = v30[36];
            v34 = v30[37];
            min.x = v30[35];
            min.y = v33;
            min.z = v34;
            TransformAABB((UFG::qMatrix44 *)&v29[20], &max, &min);
            if ( v9 <= min.x && v6 >= max.x && v3 <= min.y && v7 >= max.y && v4 <= min.z && v8 >= max.z )
              UFG::Simulation::DestroySimObject(&UFG::gSim, (UFG::SimObject *)&v24->vfptr);
          }
        }
      }
      v22 = (UFG::qNode<UFG::VehicleOccupantComponent,UFG::VehicleOccupantComponent> *)v25;
    }
    while ( v25 != (UFG::LinearGraph<float> *)&stru_142091488.fDomain );
  }
  v35 = (char *)&UFG::PhysicsMoverInterface::s_PhysicsMoverInterfaceList.mNode.mNext[-5].mNext;
  if ( (const float *)&UFG::PhysicsMoverInterface::s_PhysicsMoverInterfaceList.mNode.mNext[-5].mNext != &A_cos_280_deg_40 )
  {
    do
    {
      v36 = *((_QWORD *)v35 + 10);
      v37 = (UFG::SimObject *)*((_QWORD *)v35 + 5);
      v38 = (const float *)(v36 - 72);
      if ( v37 )
      {
        v39 = (UFG::StreamedResourceComponent *)v37->m_Components.p[10].m_pComponent;
        if ( v39 )
        {
          if ( UFG::StreamedResourceComponent::GetSpawnPriority(v39, 0i64)->mUID == qSymbol_Low.mUID )
          {
            v40 = v37->m_Components.p[14].m_pComponent;
            if ( v40 )
            {
              v41 = (float *)v40[22].m_SafePointerList.mNode.mNext;
              if ( v41 )
              {
                v42 = v41[33];
                v43 = v41[34];
                max.x = v41[32];
                max.y = v42;
                max.z = v43;
                v44 = v41[36];
                v45 = v41[37];
                min.x = v41[35];
                min.y = v44;
                min.z = v45;
                TransformAABB((UFG::qMatrix44 *)&v40[20], &max, &min);
                if ( v9 <= min.x && v6 >= max.x && v3 <= min.y && v7 >= max.y && v4 <= min.z && v8 >= max.z )
                  UFG::Simulation::DestroySimObject(&UFG::gSim, v37);
              }
            }
          }
        }
      }
      v35 = (char *)v38;
    }
    while ( v38 != &A_cos_280_deg_40 );
  }
}

// File Line: 1473
// RVA: 0x658080
void __fastcall UFG::WheeledVehicleManager::RemoveWheeledVehicleFromList(UFG::WheeledVehicleManager *this, UFG::SimObjectVehicle *object)
{
  UFG::WheeledVehicleManager *v2; // rbx
  __int64 v3; // rax
  UFG::SimObjectVehicle **v4; // r8
  unsigned int v5; // eax
  UFG::SimObjectVehicle **v6; // rcx
  unsigned int v7; // esi
  signed __int64 v8; // rdi
  __int64 v9; // rcx
  _QWORD *v10; // rax
  __int64 v11; // rcx
  unsigned int v12; // eax
  unsigned int v13; // esi
  UFG::qSafePointerWithCallbacks<UFG::SimObject,UFG::SimObjectVehicle> *v14; // rdi
  UFG::qNode<UFG::qSafePointerWithCallbacksBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v15; // rcx
  UFG::qNode<UFG::qSafePointerWithCallbacksBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v16; // rax
  fastdelegate::detail::GenericClass *v17; // rcx
  unsigned int v18; // eax

  v2 = this;
  v3 = 0i64;
  v4 = (UFG::SimObjectVehicle **)&this->mTrafficCar[0].m_pPointer;
  do
  {
    if ( object == *v4 )
    {
      v13 = this->mNumTrafficCars;
      v14 = &this->mTrafficCar[v3];
      if ( v14->m_pPointer )
      {
        v15 = v14->mPrev;
        v16 = v14->mNext;
        v15->mNext = v16;
        v16->mPrev = v15;
        v14->mPrev = (UFG::qNode<UFG::qSafePointerWithCallbacksBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v14->mPrev;
        v14->mNext = (UFG::qNode<UFG::qSafePointerWithCallbacksBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v14->mPrev;
        v14->m_Changed = 1;
        v17 = v14->m_UnbindCallback.m_Closure.m_pthis;
        if ( v17 || v14->m_UnbindCallback.m_Closure.m_pFunction )
          ((void (__fastcall *)(fastdelegate::detail::GenericClass *, UFG::SimObject *))v14->m_UnbindCallback.m_Closure.m_pFunction)(
            v17,
            v14->m_pPointer);
      }
      v14->m_pPointer = 0i64;
      v18 = v2->mNumTrafficCars;
      if ( v13 == v18 )
        v2->mNumTrafficCars = v18 - 1;
      return;
    }
    v3 = (unsigned int)(v3 + 1);
    v4 += 8;
  }
  while ( (unsigned int)v3 < 0x64 );
  v5 = 0;
  v6 = (UFG::SimObjectVehicle **)&this->mParkedCar[0].m_pPointer;
  while ( object != *v6 )
  {
    ++v5;
    v6 += 8;
    if ( v5 >= 0x64 )
      return;
  }
  v7 = v2->mNumParkedCars;
  v8 = (signed __int64)v2 + 64 * (v5 + 39i64);
  if ( *(_QWORD *)(v8 + 16) )
  {
    v9 = *(_QWORD *)v8;
    v10 = *(_QWORD **)(v8 + 8);
    *(_QWORD *)(v9 + 8) = v10;
    *v10 = v9;
    *(_QWORD *)v8 = v8;
    *(_QWORD *)(v8 + 8) = v8;
    *(_DWORD *)(v8 + 24) = 1;
    v11 = *(_QWORD *)(v8 + 48);
    if ( v11 || *(_QWORD *)(v8 + 56) )
      (*(void (__fastcall **)(__int64, _QWORD, UFG::SimObjectVehicle **))(v8 + 56))(v11, *(_QWORD *)(v8 + 16), v4);
  }
  *(_QWORD *)(v8 + 16) = 0i64;
  v12 = v2->mNumParkedCars;
  if ( v7 == v12 )
    v2->mNumParkedCars = v12 - 1;
}

// File Line: 1529
// RVA: 0x657E10
void __fastcall UFG::WheeledVehicleManager::Reinitialize(UFG::WheeledVehicleManager *this)
{
  UFG::WheeledVehicleManager *v1; // rbx

  v1 = this;
  if ( UFG::ObjectResourceManager::Instance()->mAmbientVehicles.size <= 2 )
  {
    v1->m_ReinitializeQueued = 1;
  }
  else
  {
    UFG::RoadNetworkVisibleArea::Reinitialize(v1->m_VisibleArea);
    v1->m_ReinitializeQueued = 0;
    v1->mCurrentSpawnIndex = 0;
  }
  v1->m_SecondsQueued = 0.0;
}

// File Line: 1545
// RVA: 0x6517B0
void __fastcall UFG::WheeledVehicleManager::InitLevelData(UFG::WheeledVehicleManager *this)
{
  UFG::WheeledVehicleManager *v1; // rdi
  UFG::qSymbol *v2; // rax
  UFG::TSActor *v3; // rax
  UFG::WheeledVehicleManagerScriptInterface *v4; // rbx
  UFG::SimComponent *v5; // rsi
  UFG::SimObject *v6; // r8
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v7; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v10; // rax
  UFG::qMemoryPool *v11; // rax
  UFG::allocator::free_link *v12; // rax
  UFG::SimComponent *v13; // rax
  UFG::SimObject *v14; // rdx
  unsigned __int16 v15; // cx
  unsigned int v16; // ebx
  UFG::SimObjectModifier v17; // [rsp+38h] [rbp-30h]
  UFG::qSymbol result; // [rsp+70h] [rbp+8h]

  v1 = this;
  UFG::RoadNetworkVisibleArea::Init(this->m_VisibleArea, UFG::gpRoadNetworkResource);
  v2 = UFG::qSymbol::create_from_string(&result, "RoadNetwork");
  v1->m_SimObject = UFG::Simulation::CreateSimObject(&UFG::gSim, v2);
  v3 = (UFG::TSActor *)AMemory::c_malloc_func(0xE0ui64, "WheeledVehicleManagerScriptInterface");
  v4 = (UFG::WheeledVehicleManagerScriptInterface *)v3;
  *(_QWORD *)&result.mUID = v3;
  v5 = 0i64;
  if ( v3 )
  {
    UFG::TSActor::TSActor(
      v3,
      (ASymbol *)&UFG::WheeledVehicleManagerScriptInterface::mInstanceNameSymbol,
      UFG::WheeledVehicleManagerScriptInterface::mClass);
    v4->vfptr = (SSObjectBaseVtbl *)&UFG::WheeledVehicleManagerScriptInterface::`vftable;
    v4->m_WheeledVehicleManager = v1;
    UFG::WheeledVehicleManagerScriptInterface::mScriptInterfaceInstance = v4;
  }
  else
  {
    v4 = 0i64;
  }
  v6 = v1->m_SimObject;
  v7 = &v4->mpSimObj;
  if ( v4->mpSimObj.m_pPointer )
  {
    v8 = v7->mPrev;
    v9 = v4->mpSimObj.mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    v7->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v7->mPrev;
    v4->mpSimObj.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v4->mpSimObj.mPrev;
  }
  v4->mpSimObj.m_pPointer = v6;
  if ( v6 )
  {
    v10 = v6->m_SafePointerList.mNode.mPrev;
    v10->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v7->mPrev;
    v7->mPrev = v10;
    v4->mpSimObj.mNext = &v6->m_SafePointerList.mNode;
    v6->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v7->mPrev;
  }
  v11 = UFG::GetSimulationMemoryPool();
  v12 = UFG::qMemoryPool::Allocate(v11, 0x58ui64, "WheeledVehicleManager::TSActorComponent", 0i64, 1u);
  *(_QWORD *)&result.mUID = v12;
  if ( v12 )
  {
    UFG::TSActorComponent::TSActorComponent((UFG::TSActorComponent *)v12, (UFG::TSActor *)&v4->vfptr);
    v5 = v13;
  }
  v14 = v1->m_SimObject;
  v15 = v14->m_Flags;
  if ( (v15 >> 14) & 1 || (v15 & 0x8000u) != 0 )
  {
    v16 = 4;
  }
  else if ( (v15 >> 13) & 1 )
  {
    v16 = 3;
  }
  else
  {
    v16 = -1;
    if ( (v15 >> 12) & 1 )
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
  UFG::WheeledVehicleManager *v1; // rbx
  signed __int64 v2; // rcx
  _QWORD *v3; // rax
  signed __int64 v4; // rdx
  _QWORD *v5; // rax
  AMD_HD3D *v6; // rcx
  AMD_HD3D *v7; // rcx
  AMD_HD3D *v8; // rcx
  bool v9; // al

  v1 = this;
  UFG::WheeledVehicleNavigationData::InitGlobalData(this->m_NavigationData);
  v2 = 100i64;
  v3 = &v1->mTrafficCar[0].m_UnbindCallback.m_Closure.m_pthis;
  v4 = 100i64;
  do
  {
    v3[1] = UFG::WheeledVehicleManager::TrafficCarBeingDeleted;
    *v3 = v1;
    v3 += 8;
    --v4;
  }
  while ( v4 );
  v5 = &v1->mParkedCar[0].m_UnbindCallback.m_Closure.m_pthis;
  do
  {
    v5[1] = UFG::WheeledVehicleManager::ParkedCarBeingDeleted;
    *v5 = v1;
    v5 += 8;
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
  UFG::WheeledVehicleManager::InitLevelData(v1);
}

// File Line: 1673
// RVA: 0x657B50
void __fastcall UFG::WheeledVehicleManager::QueueDeletion(UFG::WheeledVehicleManager *this, UFG::SimObject *pCarToDelete)
{
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v2; // rax
  signed __int64 v3; // r9
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v4; // rcx

  v2 = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)this->mCarsWithDeletionPending;
  v3 = 100i64;
  do
  {
    if ( !v2[1].mPrev )
    {
      v2[1].mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)pCarToDelete;
      if ( pCarToDelete )
      {
        v4 = pCarToDelete->m_SafePointerList.mNode.mPrev;
        v4->mNext = v2;
        v2->mPrev = v4;
        v2->mNext = &pCarToDelete->m_SafePointerList.mNode;
        pCarToDelete->m_SafePointerList.mNode.mPrev = v2;
      }
    }
    v2 = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)((char *)v2 + 24);
    --v3;
  }
  while ( v3 );
}

// File Line: 1682
// RVA: 0x657EE0
void __fastcall UFG::WheeledVehicleManager::ReleaseGlobalData(UFG::WheeledVehicleManager *this)
{
  UFG::WheeledVehicleManager *v1; // rbx
  AMD_HD3D *v2; // rcx
  AMD_HD3D *v3; // rcx
  AMD_HD3D *v4; // rcx
  AMD_HD3D *v5; // rcx
  AMD_HD3D *v6; // rcx
  AMD_HD3D *v7; // rcx
  AMD_HD3D *v8; // rcx
  UFG::SimObject *v9; // rcx
  UFG::SimComponent *v10; // rax

  v1 = this;
  UFG::RoadNetworkVisibleArea::Release(this->m_VisibleArea);
  _(v2);
  _(v3);
  _(v4);
  _(v5);
  _(v6);
  _(v7);
  _(v8);
  v9 = v1->m_SimObject;
  if ( v9 )
  {
    v10 = UFG::SimObject::GetComponentOfType(v9, UFG::RoadNetworkDebugComponent::_TypeUID);
    if ( v10 )
      UFG::Simulation::DestroySimComponent(&UFG::gSim, v10);
  }
}

// File Line: 1710
// RVA: 0x64EB70
__int64 __fastcall UFG::WheeledVehicleManager::GetNumTrams(UFG::WheeledVehicleManager *this)
{
  unsigned int v1; // edi
  UFG::SimObject **v2; // rbx
  signed __int64 v3; // rsi

  v1 = 0;
  v2 = &this->mTrafficCar[0].m_pPointer;
  v3 = 100i64;
  do
  {
    if ( *v2 && UFG::SimObjectUtility::IsClassType(*v2, (UFG::qSymbol *)&qSymbol_Tram.mUID) )
      ++v1;
    v2 += 8;
    --v3;
  }
  while ( v3 );
  return v1;
}

// File Line: 1726
// RVA: 0x65AC90
UFG::SimObjectVehicle *__usercall UFG::WheeledVehicleManager::SpawnTrafficVehicle@<rax>(UFG::WheeledVehicleManager *this@<rcx>, UFG::qPropertySet *vehiclePropSet@<rdx>, UFG::RoadNetworkNode *node@<r8>, const unsigned int lane@<r9d>, float a5@<xmm0>, const float t)
{
  unsigned int v6; // ebp
  UFG::RoadNetworkNode *v7; // r14
  UFG::qPropertySet *v8; // rdi
  UFG::WheeledVehicleManager *v9; // rbx
  UFG::SimObjectVehicle *v10; // rax
  UFG::RoadNetworkLane *v11; // rax
  UFG::RoadNetworkLane *v12; // rax
  UFG::SimObjectVehicle *v13; // rsi
  UFG::CompositeLookComponent *v14; // rax
  UFG::RoadSpaceComponent *v15; // rdi
  UFG::RoadNetworkLocation *v16; // rax
  UFG::qSymbol targetClassType; // [rsp+30h] [rbp-38h]
  UFG::qVector3 result; // [rsp+38h] [rbp-30h]

  v6 = lane;
  v7 = node;
  v8 = vehiclePropSet;
  v9 = this;
  if ( !UFG::WheeledVehicleManager::mTrafficCarSpawningEnabled )
    return 0i64;
  if ( this->mNumTrafficCars >= UFG::WheeledVehicleManager::mMaxTrafficCars )
    return 0i64;
  targetClassType.mUID = qSymbol_Tram.mUID;
  if ( UFG::SimObjectUtility::IsClassType(vehiclePropSet, &targetClassType) )
  {
    if ( (unsigned int)UFG::WheeledVehicleManager::GetNumTrams(v9) >= 4 )
      return 0i64;
  }
  v11 = UFG::RoadNetworkNode::GetLane(v7, v6);
  if ( UFG::WheeledVehicleManager::IsVehicleSpawnCollision(v8, v11, t) )
    return 0i64;
  v12 = UFG::RoadNetworkNode::GetLane(v7, v6);
  UFG::RoadNetworkLane::GetPos(v12, &result, t);
  if ( UFG::WheeledVehicleManager::SpawnLocationContainsObjectConditional(v9, v8, &result)
    || UFG::WheeledVehicleManager::IsNearPlayerVehicleGuide(&result, a5) )
  {
    return 0i64;
  }
  v10 = UFG::WheeledVehicleManager::CreateWheeledVehicle(v9, v8);
  v13 = v10;
  if ( v10 )
  {
    v14 = (UFG::CompositeLookComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                           (UFG::SimObjectGame *)&v10->vfptr,
                                           UFG::CompositeLookComponent::_TypeUID);
    if ( v14 )
      UFG::CompositeLookComponent::ForceInvisibleTransparency(v14);
    UFG::WheeledVehicleManager::AttachTrafficAI(v9, v13);
    v15 = (UFG::RoadSpaceComponent *)v13->m_Components.p[24].m_pComponent;
    UFG::RoadNetworkGuide::AttachToNetwork(&v15->mGuide, v15->m_pSimObject, v7, v6, t);
    v16 = Scaleform::GFx::AS3::Instances::fl::XML::GetName(&v15->mGuide);
    UFG::RoadSpaceComponent::MoveCarToRoadNetworkPosition(v15, v16, 0);
    v10 = v13;
  }
  return v10;
}

// File Line: 1783
// RVA: 0x65AA50
UFG::SimObjectVehicle *__usercall UFG::WheeledVehicleManager::SpawnParkedVehicle@<rax>(UFG::WheeledVehicleManager *this@<rcx>, UFG::qPropertySet *vehiclePropSet@<rdx>, UFG::ParkingSpot *spot@<r8>, float a4@<xmm0>)
{
  UFG::ParkingSpot *v4; // r14
  UFG::qPropertySet *v5; // rsi
  UFG::WheeledVehicleManager *v6; // rdi
  UFG::TransformNodeComponent *v8; // rbx
  UFG::qVector3 *v9; // rbx
  UFG::RoadNetworkSegment *v10; // rax
  UFG::RoadNetworkLane *v11; // rbp
  float v12; // xmm6_4
  float v13; // xmm0_4
  UFG::SimObjectVehicle *v14; // rax
  UFG::SimObjectVehicle *v15; // rsi
  unsigned __int16 v16; // dx
  UFG::CompositeLookComponent *v17; // rax
  UFG::allocator::free_link *v18; // rax
  UFG::TeleportEvent *v19; // rbp
  unsigned int v20; // edi
  UFG::qMatrix44 *v21; // rbx

  v4 = spot;
  v5 = vehiclePropSet;
  v6 = this;
  if ( !UFG::WheeledVehicleManager::mParkedCarSpawningEnabled )
    return 0i64;
  if ( this->mNumParkedCars >= UFG::WheeledVehicleManager::mMaxParkedCars )
    return 0i64;
  v8 = spot->mpXformNode;
  UFG::TransformNodeComponent::UpdateWorldTransform(spot->mpXformNode);
  v9 = (UFG::qVector3 *)&v8->mWorldTransform.v3;
  if ( UFG::WheeledVehicleManager::SpawnLocationContainsObjectConditional(v6, v5, v9)
    || UFG::WheeledVehicleManager::IsNearPlayerVehicleGuide(v9, a4) )
  {
    return 0i64;
  }
  v10 = UFG::RoadNetworkResource::GetSegment(UFG::gpRoadNetworkResource, v4->mRoadSegmentID);
  v11 = UFG::RoadNetworkNode::GetClosestLane((UFG::RoadNetworkNode *)&v10->mType, v9);
  v12 = v11->mOffset;
  v13 = UFG::RoadNetworkLane::CalculateParkingOffset(v11, v9);
  if ( v13 <= v12 )
    v13 = v12;
  v11->mOffset = v13;
  v14 = UFG::WheeledVehicleManager::CreateParkedWheeledVehicle(v6, v5, v4);
  v15 = v14;
  if ( v14 )
  {
    v16 = v14->m_Flags;
    if ( (v16 >> 14) & 1 )
    {
      v17 = (UFG::CompositeLookComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                             (UFG::SimObjectGame *)&v14->vfptr,
                                             UFG::CompositeLookComponent::_TypeUID);
    }
    else if ( (v16 & 0x8000u) == 0 )
    {
      if ( (v16 >> 13) & 1 )
        v17 = (UFG::CompositeLookComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                               (UFG::SimObjectGame *)&v14->vfptr,
                                               UFG::CompositeLookComponent::_TypeUID);
      else
        v17 = (UFG::CompositeLookComponent *)((v16 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                  (UFG::SimObjectGame *)&v14->vfptr,
                                                                  UFG::CompositeLookComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v14->vfptr, UFG::CompositeLookComponent::_TypeUID));
    }
    else
    {
      v17 = (UFG::CompositeLookComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                             (UFG::SimObjectGame *)&v14->vfptr,
                                             UFG::CompositeLookComponent::_TypeUID);
    }
    if ( v17 )
      UFG::CompositeLookComponent::ForceInvisibleTransparency(v17);
  }
  v18 = UFG::qMalloc(0x90ui64, "TeleportEvent", 0i64);
  v19 = (UFG::TeleportEvent *)v18;
  if ( v18 )
  {
    v20 = v15->mNode.mUID;
    v21 = (UFG::qMatrix44 *)v4->mpXformNode;
    UFG::TransformNodeComponent::UpdateWorldTransform(v4->mpXformNode);
    UFG::TeleportEvent::TeleportEvent(v19, v21 + 2, v20, 0, UFG::TeleportEvent::m_Name, 0);
  }
  UFG::EventDispatcher::DispatchEvent(&UFG::EventDispatcher::mInstance, (UFG::Event *)v18);
  return v15;
}

// File Line: 1832
// RVA: 0x65ED80
void __fastcall UFG::WheeledVehicleManager::TrafficCarBeingDeleted(UFG::WheeledVehicleManager *this, UFG::SimObject *pDeletedCar)
{
  unsigned int v2; // er8
  UFG::SimObject **v3; // rax

  v2 = 0;
  v3 = &this->mTrafficCar[0].m_pPointer;
  while ( pDeletedCar != *v3 )
  {
    ++v2;
    v3 += 8;
    if ( v2 >= 0x64 )
      return;
  }
  --this->mNumTrafficCars;
}

// File Line: 1845
// RVA: 0x657780
void __fastcall UFG::WheeledVehicleManager::ParkedCarBeingDeleted(UFG::WheeledVehicleManager *this, UFG::SimObject *pDeletedCar)
{
  unsigned int v2; // er8
  UFG::SimObject **v3; // rax

  v2 = 0;
  v3 = &this->mParkedCar[0].m_pPointer;
  while ( pDeletedCar != *v3 )
  {
    ++v2;
    v3 += 8;
    if ( v2 >= 0x64 )
      return;
  }
  --this->mNumParkedCars;
}

// File Line: 1858
// RVA: 0x651DC0
bool __usercall UFG::WheeledVehicleManager::IsNearPlayerVehicleGuide@<al>(UFG::qVector3 *pos@<rcx>, float a2@<xmm0>)
{
  UFG::qVector3 *v2; // rsi
  unsigned __int16 v3; // dx
  UFG::CharacterOccupantComponent *v4; // rax
  UFG::SimObjectVehicle *v5; // rax
  UFG::SimObjectVehicle *v6; // rdi
  UFG::VehicleSubjectComponent *v7; // rax
  UFG::VehicleSubjectComponent *v8; // rbx
  UFG::SimComponent *v9; // rdi
  float v10; // xmm3_4
  float *v11; // rdi
  float v12; // xmm0_4
  float v13; // xmm1_4

  v2 = pos;
  if ( LocalPlayer
    && ((v3 = LocalPlayer->m_Flags, !((v3 >> 14) & 1)) ? ((v3 & 0x8000u) == 0 ? (!((v3 >> 13) & 1) ? (!((v3 >> 12) & 1) ? (v4 = (UFG::CharacterOccupantComponent *)UFG::SimObject::GetComponentOfType((UFG::SimObject *)&LocalPlayer->vfptr, UFG::CharacterOccupantComponent::_TypeUID)) : (v4 = (UFG::CharacterOccupantComponent *)UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&LocalPlayer->vfptr, UFG::CharacterOccupantComponent::_TypeUID))) : (v4 = (UFG::CharacterOccupantComponent *)UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&LocalPlayer->vfptr, UFG::CharacterOccupantComponent::_TypeUID))) : (v4 = (UFG::CharacterOccupantComponent *)UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&LocalPlayer->vfptr, UFG::CharacterOccupantComponent::_TypeUID))) : (v4 = (UFG::CharacterOccupantComponent *)LocalPlayer->m_Components.p[44].m_pComponent),
        v4) )
  {
    v5 = (UFG::SimObjectVehicle *)UFG::CharacterOccupantComponent::GetCurrentVehicle(v4);
    v6 = v5;
    if ( v5 )
    {
      v7 = UFG::SimObjectVehicle::GetComponent<UFG::VehicleSubjectComponent>(v5);
      v8 = v7;
      if ( v7
        && ((unsigned __int8 (__fastcall *)(UFG::VehicleSubjectComponent *))v7->vfptr[46].__vecDelDtor)(v7)
        && (v9 = v6->m_Components.p[24].m_pComponent) != 0i64
        && (((void (__fastcall *)(UFG::VehicleSubjectComponent *))v8->vfptr[21].__vecDelDtor)(v8),
            v10 = a2,
            (v11 = (float *)&v9[5].m_BoundComponentHandles.mNode.mNext) != 0i64) )
      {
        v12 = v2->y - v11[30];
        v13 = v2->z - v11[31];
        LOBYTE(v5) = (float)((float)(v10 + 20.0) * (float)(v10 + 20.0)) > (float)((float)((float)((float)(v2->x - v11[29])
                                                                                                * (float)(v2->x - v11[29]))
                                                                                        + (float)(v12 * v12))
                                                                                + (float)(v13 * v13));
      }
      else
      {
        LOBYTE(v5) = 0;
      }
    }
  }
  else
  {
    LOBYTE(v5) = 0;
  }
  return (char)v5;
}

// File Line: 1890
// RVA: 0x648380
bool __fastcall UFG::WheeledVehicleManager::CheckSpawnLocationSimple(UFG::WheeledVehicleManager *this, UFG::qVector3 *position)
{
  float v2; // xmm1_4
  UFG::WheeledVehicleManager *v3; // rbx
  UFG::SensorPhantom *v4; // rcx
  UFG::qVector4 v6; // [rsp+20h] [rbp-48h]
  UFG::qVector4 v7; // [rsp+30h] [rbp-38h]
  UFG::qVector4 v8; // [rsp+40h] [rbp-28h]
  float v9; // [rsp+50h] [rbp-18h]
  float v10; // [rsp+54h] [rbp-14h]
  float v11; // [rsp+58h] [rbp-10h]
  int v12; // [rsp+5Ch] [rbp-Ch]

  v2 = position->y;
  v3 = this;
  v4 = this->mSpawnSensor;
  v6 = UFG::qMatrix44::msIdentity.v0;
  v10 = v2;
  v12 = (signed int)FLOAT_1_0;
  v7 = UFG::qMatrix44::msIdentity.v1;
  v8 = UFG::qMatrix44::msIdentity.v2;
  v9 = position->x;
  v11 = position->z;
  UFG::SensorPhantom::SetTransform(v4, (UFG::qMatrix44 *)&v6);
  return UFG::WheeledVehicleManager::SensorContainsObject(v3) == 0;
}

// File Line: 1918
// RVA: 0x65A610
char __fastcall UFG::WheeledVehicleManager::SpawnLocationContainsObjectConditional(UFG::WheeledVehicleManager *this, UFG::qPropertySet *vehiclePropSet, UFG::qVector3 *position)
{
  UFG::WheeledVehicleManager *v3; // rbx
  UFG::SensorPhantom *v4; // rcx
  UFG::qVector3 *v5; // rdi
  UFG::SensorPhantom *v6; // rcx
  float v7; // xmm1_4
  int nbytes; // [rsp+20h] [rbp-60h]
  int v10; // [rsp+24h] [rbp-5Ch]
  float v11; // [rsp+28h] [rbp-58h]
  int buf; // [rsp+30h] [rbp-50h]
  int v13; // [rsp+34h] [rbp-4Ch]
  float v14; // [rsp+38h] [rbp-48h]
  UFG::qMatrix44 transform; // [rsp+40h] [rbp-40h]

  v3 = this;
  v4 = this->mSpawnSensor;
  v11 = FLOAT_2_0;
  v5 = position;
  nbytes = 1077936128;
  v14 = FLOAT_N2_0;
  v10 = 1077936128;
  buf = -1069547520;
  v13 = -1069547520;
  Scaleform::Render::WrapperImageSource::GetFormat((hkSubStreamWriter *)v4, &buf, (unsigned __int64)&nbytes);
  v6 = v3->mSpawnSensor;
  v7 = v5->y;
  transform.v0 = UFG::qMatrix44::msIdentity.v0;
  transform.v3.y = v7;
  LODWORD(transform.v3.w) = (_DWORD)FLOAT_1_0;
  transform.v1 = UFG::qMatrix44::msIdentity.v1;
  transform.v2 = UFG::qMatrix44::msIdentity.v2;
  transform.v3.x = v5->x;
  transform.v3.z = v5->z;
  UFG::SensorPhantom::SetTransform(v6, &transform);
  return UFG::WheeledVehicleManager::SensorContainsObjectConditional(v3, v5);
}

// File Line: 1932
// RVA: 0x658400
char __fastcall UFG::WheeledVehicleManager::SensorContainsObject(UFG::WheeledVehicleManager *this)
{
  _QWORD *v1; // rax
  UFG::SensorPhantomIterator v3; // [rsp+28h] [rbp-20h]

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
char __fastcall UFG::WheeledVehicleManager::SensorContainsObjectConditional(UFG::WheeledVehicleManager *this, UFG::qVector3 *position)
{
  UFG::qVector3 *v2; // rsi
  void *v3; // rax
  UFG::SimObject *v4; // rbx
  float *v5; // rdi
  UFG::StreamedResourceComponent *v6; // rax
  UFG::SensorPhantomIterator v8; // [rsp+28h] [rbp-20h]
  UFG::SpawnInfoInterface::SpawnPriority priority; // [rsp+50h] [rbp+8h]

  v2 = position;
  UFG::SensorPhantomIterator::SensorPhantomIterator(&v8, this->mSpawnSensor, 0);
  while ( UFG::SensorPhantomIterator::operator*(&v8) )
  {
    v3 = UFG::SensorPhantomIterator::operator*(&v8);
    v4 = (UFG::SimObject *)v3;
    if ( v3 && *((_QWORD *)v3 + 10) )
    {
      if ( (v5 = (float *)*((_QWORD *)v3 + 11)) != 0i64
        && (UFG::TransformNodeComponent::UpdateWorldTransform(*((UFG::TransformNodeComponent **)v3 + 11)),
            (float)((float)((float)((float)(v2->y - v5[45]) * (float)(v2->y - v5[45]))
                          + (float)((float)(v2->x - v5[44]) * (float)(v2->x - v5[44])))
                  + (float)((float)(v2->z - v5[46]) * (float)(v2->z - v5[46]))) < 1.0)
        || (v6 = (UFG::StreamedResourceComponent *)UFG::SimObject::GetComponentOfType(
                                                     v4,
                                                     UFG::StreamedResourceComponent::_TypeUID)) != 0i64
        && (UFG::StreamedResourceComponent::GetSpawnPriority(v6, &priority), priority == UnReferenced) )
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
  UFG::qNode<UFG::RoadSpaceComponent,UFG::RoadSpaceComponent> *v1; // rbx
  UFG::SimObject *v2; // rdi
  UFG::qList<UFG::RoadSpaceComponent,UFG::RoadSpaceComponent,1,0> *v3; // rbp
  unsigned __int16 v4; // cx
  UFG::AiDriverComponent *v5; // rax
  bool v6; // zf
  UFG::SimObjectGame *v7; // rcx
  UFG::RoadNetworkGuide *v8; // rbx
  UFG::RoadNetworkLocation *v9; // rax
  UFG::RoadNetworkNode *v10; // rax
  UFG::RoadNetworkNode *v11; // rsi
  __int128 v12; // xmm6
  UFG::RoadNetworkLocation *v13; // rax
  UFG::RoadNetworkSubSegment *v14; // rbx
  UFG::RoadNetworkLane *v15; // r14
  signed __int64 v16; // rsi

  v1 = UFG::RoadSpaceComponent::s_RoadSpaceComponentList.mNode.mNext - 4;
  if ( (UFG::qList<UFG::RoadSpaceComponent,UFG::RoadSpaceComponent,1,0> *)&UFG::RoadSpaceComponent::s_RoadSpaceComponentList.mNode.mNext[-4] != &UFG::RoadSpaceComponent::s_RoadSpaceComponentList - 4 )
  {
    while ( 1 )
    {
      v2 = (UFG::SimObject *)v1[2].mNext;
      v3 = (UFG::qList<UFG::RoadSpaceComponent,UFG::RoadSpaceComponent,1,0> *)&v1[4].mNext[-4];
      if ( !v2 )
        goto LABEL_22;
      v4 = v2->m_Flags;
      if ( (v4 >> 14) & 1 )
      {
        v5 = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>((UFG::SimObjectCVBase *)v1[2].mNext);
      }
      else if ( (v4 & 0x8000u) == 0 )
      {
        if ( (v4 >> 13) & 1 )
        {
          v5 = (UFG::AiDriverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                           (UFG::SimObjectGame *)v1[2].mNext,
                                           UFG::AiDriverComponent::_TypeUID);
        }
        else
        {
          v6 = ((v4 >> 12) & 1) == 0;
          v7 = (UFG::SimObjectGame *)v1[2].mNext;
          v5 = (UFG::AiDriverComponent *)(v6 ? UFG::SimObject::GetComponentOfType(
                                                 (UFG::SimObject *)&v7->vfptr,
                                                 UFG::AiDriverComponent::_TypeUID) : UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                                       v7,
                                                                                       UFG::AiDriverComponent::_TypeUID));
        }
      }
      else
      {
        v5 = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>((UFG::SimObjectCVBase *)v1[2].mNext);
      }
      if ( !v5 || !((unsigned __int8 (__fastcall *)(UFG::AiDriverComponent *))v5->vfptr[16].__vecDelDtor)(v5) )
        goto LABEL_22;
      v8 = (UFG::RoadNetworkGuide *)&v1[23].mNext;
      if ( !v8->m_Attached )
        goto LABEL_21;
      v9 = Scaleform::GFx::AS3::Instances::fl::XML::GetName(v8);
      v10 = UFG::RoadNetworkLocation::GetRoadNetworkNode(v9);
      v11 = v10;
      if ( !v10->mActive )
        break;
LABEL_22:
      v1 = &v3->mNode;
      if ( v3 == &UFG::RoadSpaceComponent::s_RoadSpaceComponentList - 4 )
        return;
    }
    if ( !v10->mType.mValue )
    {
      v12 = LODWORD(Scaleform::GFx::AS3::Instances::fl::XML::GetName(v8)->m_LaneT);
      v13 = Scaleform::GFx::AS3::Instances::fl::XML::GetName(v8);
      v14 = (UFG::RoadNetworkSubSegment *)v11[1].mPathCollection.mOffset;
      v15 = v13->m_CurrentLane;
      v16 = (signed __int64)&v11[1].mIndex;
      if ( v14 != (UFG::RoadNetworkSubSegment *)v16 )
      {
        while ( !v14->mActive || !UFG::RoadNetworkSubSegment::IsWithinSubSegment(v14, v15, *(float *)&v12) )
        {
          v14 = (UFG::RoadNetworkSubSegment *)v14->mNext;
          if ( v14 == (UFG::RoadNetworkSubSegment *)v16 )
            goto LABEL_21;
        }
        goto LABEL_22;
      }
    }
LABEL_21:
    UFG::Simulation::DestroySimObject(&UFG::gSim, v2);
    goto LABEL_22;
  }
}

// File Line: 2052
// RVA: 0x6653B0
void __fastcall UFG::WheeledVehicleManager::UpdateVehicleFades(UFG::WheeledVehicleManager *this)
{
  signed __int64 v1; // rdi
  UFG::WheeledVehicleManager *v2; // rbp
  UFG::SimObject **v3; // rbx
  signed __int64 v4; // rsi
  UFG::SimObject **v5; // rbx

  v1 = 100i64;
  v2 = this;
  v3 = &this->mTrafficCar[0].m_pPointer;
  v4 = 100i64;
  do
  {
    if ( *v3 )
      UFG::WheeledVehicleManager::UpdateVehicleFade(v2, *v3);
    v3 += 8;
    --v4;
  }
  while ( v4 );
  v5 = &v2->mParkedCar[0].m_pPointer;
  do
  {
    if ( *v5 )
      UFG::WheeledVehicleManager::UpdateVehicleFade(v2, *v5);
    v5 += 8;
    --v1;
  }
  while ( v1 );
}

// File Line: 2112
// RVA: 0x665120
void __fastcall UFG::WheeledVehicleManager::UpdateVehicleFade(UFG::WheeledVehicleManager *this, UFG::SimObject *vehicleObj)
{
  UFG::SimObjectGame *v2; // rbx
  unsigned __int16 v3; // dx
  UFG::WheeledVehicleManager *v4; // rbp
  UFG::SimComponent *v5; // rax
  UFG::CompositeLookComponent *v6; // rdi
  UFG::TransformNodeComponent *v7; // rsi
  unsigned __int16 v8; // cx
  char isWater; // r14
  float v10; // xmm0_4
  float v11; // xmm1_4
  float v12; // xmm2_4
  char v13; // si
  float v14; // xmm7_4
  UFG::SimComponent *v15; // rax
  UFG::RoadNetworkGuide *v16; // rbx
  UFG::RoadNetworkLocation *v17; // rax
  UFG::RoadNetworkNode *v18; // rax
  UFG::RoadNetworkNode *v19; // rbx
  float v20; // xmm6_4
  UFG::qVector3 result; // [rsp+30h] [rbp-48h]
  UFG::qVector3 position; // [rsp+40h] [rbp-38h]

  if ( vehicleObj )
  {
    v2 = (UFG::SimObjectGame *)vehicleObj;
    v3 = vehicleObj->m_Flags;
    v4 = this;
    if ( (v3 >> 14) & 1 )
    {
      v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::CompositeLookComponent::_TypeUID);
    }
    else if ( (v3 & 0x8000u) == 0 )
    {
      if ( (v3 >> 13) & 1 )
        v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::CompositeLookComponent::_TypeUID);
      else
        v5 = (v3 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::CompositeLookComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v2->vfptr, UFG::CompositeLookComponent::_TypeUID);
    }
    else
    {
      v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::CompositeLookComponent::_TypeUID);
    }
    v6 = (UFG::CompositeLookComponent *)v5;
    if ( v5 )
    {
      v7 = v2->m_pTransformNodeComponent;
      if ( v7 )
      {
        UFG::RoadNetworkVisibleArea::GetSubjectPosition(v4->m_VisibleArea, &result);
        UFG::TransformNodeComponent::UpdateWorldTransform(v7);
        v8 = v2->m_Flags;
        isWater = 0;
        v10 = v7->mWorldTransform.v3.x;
        v11 = v7->mWorldTransform.v3.y;
        v12 = v7->mWorldTransform.v3.z;
        v13 = 0;
        position.x = v10;
        position.y = v11;
        position.z = v12;
        v14 = (float)((float)((float)(result.y - v11) * (float)(result.y - v11))
                    + (float)((float)(result.x - v10) * (float)(result.x - v10)))
            + (float)((float)(result.z - v12) * (float)(result.z - v12));
        if ( (v8 >> 14) & 1 )
        {
          v15 = v2->m_Components.p[24].m_pComponent;
        }
        else if ( (v8 & 0x8000u) == 0 )
        {
          if ( (v8 >> 13) & 1 )
          {
            v15 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::RoadSpaceComponent::_TypeUID);
          }
          else if ( (v8 >> 12) & 1 )
          {
            v15 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::RoadSpaceComponent::_TypeUID);
          }
          else
          {
            v15 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v2->vfptr, UFG::RoadSpaceComponent::_TypeUID);
          }
        }
        else
        {
          v15 = v2->m_Components.p[24].m_pComponent;
        }
        if ( v15 )
        {
          v16 = (UFG::RoadNetworkGuide *)&v15[5].m_BoundComponentHandles.mNode.mNext;
          if ( v15 != (UFG::SimComponent *)-376i64 )
          {
            if ( (unsigned __int8)UFG::RoadNetworkGuide::IsCurrentLocationValid((UFG::RoadNetworkGuide *)&v15[5].m_BoundComponentHandles.mNode.mNext) )
            {
              if ( v16->m_Attached )
              {
                v17 = Scaleform::GFx::AS3::Instances::fl::XML::GetName(v16);
                v18 = UFG::RoadNetworkLocation::GetRoadNetworkNode(v17);
                v19 = v18;
                if ( v18 )
                {
                  v13 = UFG::RoadNetworkVisibleArea::AllowVisibleExtension(v4->m_VisibleArea, v18);
                  isWater = UFG::RoadNetworkNode::IsWater(v19);
                }
              }
            }
          }
        }
        v20 = UFG::RoadNetworkVisibleArea::GetValidDistance(v4->m_VisibleArea, &position, v13, 1, isWater);
        if ( v14 < (float)((float)(v20 - 2.0) * (float)(v20 - 2.0))
          && (unsigned __int8)UFG::CompositeLookComponent::HasFadedOut(v6) )
        {
          UFG::CompositeLookComponent::ForceFadeIn(v6);
        }
        if ( v14 > (float)(v20 * v20) && UFG::CompositeLookComponent::HasFadedIn(v6) )
          UFG::CompositeLookComponent::ForceFadeOut(v6);
      }
    }
  }
}

// File Line: 2156
// RVA: 0x64B4D0
void __fastcall UFG::WheeledVehicleManager::DestroyQueuedVehicles(UFG::WheeledVehicleManager *this)
{
  UFG::SimObject **v1; // rbx
  signed __int64 v2; // rdi
  __int64 v3; // rcx
  _QWORD *v4; // rax

  v1 = &this->mCarsWithDeletionPending[0].m_pPointer;
  v2 = 100i64;
  do
  {
    if ( *v1 )
    {
      UFG::Simulation::DestroySimObject(&UFG::gSim, *v1);
      if ( *v1 )
      {
        v3 = (__int64)*(v1 - 2);
        v4 = *(v1 - 1);
        *(_QWORD *)(v3 + 8) = v4;
        *v4 = v3;
        *(v1 - 2) = (UFG::SimObject *)(v1 - 2);
        *(v1 - 1) = (UFG::SimObject *)(v1 - 2);
      }
      *v1 = 0i64;
    }
    v1 += 3;
    --v2;
  }
  while ( v2 );
}

// File Line: 2168
// RVA: 0x65FA60
void __fastcall UFG::WheeledVehicleManager::Update(UFG::WheeledVehicleManager *this, const float seconds)
{
  float v2; // xmm6_4
  UFG::WheeledVehicleManager *v3; // rbx
  float v4; // xmm1_4
  unsigned int v5; // eax
  unsigned int v6; // edi
  float v7; // xmm1_4
  Render::DebugDrawContext *v8; // rax
  float v9; // xmm1_4
  UFG::RoadNetworkResource *v10; // r14
  float v11; // xmm8_4
  unsigned int v12; // er13
  unsigned int i; // eax
  unsigned int v14; // er15
  UFG::RoadNetworkIntersection *v15; // rdi
  UFG::RoadNetworkIntersection *v16; // rsi
  __int64 v17; // [rsp+30h] [rbp-A8h]
  UFG::qArray<UFG::RoadNetworkSubSegment *,0> activateSubSegments; // [rsp+40h] [rbp-98h]
  UFG::qArray<UFG::RoadNetworkSubSegment *,0> deactivateSubSegments; // [rsp+50h] [rbp-88h]
  __int64 v20; // [rsp+60h] [rbp-78h]
  Render::RenderOutputParams outSettings; // [rsp+70h] [rbp-68h]

  v20 = -2i64;
  v2 = seconds;
  v3 = this;
  Render::RenderOutputParams::RenderOutputParams(&outSettings);
  Render::GetCurrentDisplaySettings(&outSettings);
  if ( last_LOD_setting != outSettings.mAAQuality )
  {
    if ( outSettings.mAAQuality )
    {
      switch ( outSettings.mAAQuality )
      {
        case 1:
          UFG::WheeledVehicleManager::mDefaultMaxParkedCars = 15;
          UFG::WheeledVehicleManager::mDefaultMaxTrafficCars = 22;
          v4 = FLOAT_110_0;
          break;
        case 2:
          UFG::WheeledVehicleManager::mDefaultMaxParkedCars = 20;
          UFG::WheeledVehicleManager::mDefaultMaxTrafficCars = 30;
          v4 = FLOAT_130_0;
          break;
        case 3:
          UFG::WheeledVehicleManager::mDefaultMaxParkedCars = 25;
          UFG::WheeledVehicleManager::mDefaultMaxTrafficCars = 34;
          v4 = FLOAT_155_0;
          break;
        default:
LABEL_11:
          UFG::WheeledVehicleManager::ApplyDefaultMaxCars(v3);
          UFG::RoadNetworkVisibleArea::SetForceVisibleAreaUpdate(v3->m_VisibleArea);
          last_LOD_setting = outSettings.mAAQuality;
          goto LABEL_12;
      }
    }
    else
    {
      UFG::WheeledVehicleManager::mDefaultMaxParkedCars = 11;
      UFG::WheeledVehicleManager::mDefaultMaxTrafficCars = 15;
      v4 = FLOAT_85_0;
    }
    UFG::RoadNetworkVisibleArea::SetVisibleDistance(v3->m_VisibleArea, v4);
    goto LABEL_11;
  }
LABEL_12:
  if ( v3->m_PlaceTransitVehicleReady )
  {
    v5 = v3->m_PlaceTransitVehicleFrames;
    if ( v5 )
    {
      v3->m_PlaceTransitVehicleFrames = v5 - 1;
    }
    else
    {
      UFG::TransitUtility::PlaceTransitVehicle();
      UFG::UIHK_NISOverlay::HideCurtains(1.0, 0);
      v3->m_PlaceTransitVehicleReady = 0;
      v3->m_PlaceTransitVehicleFrames = 0;
    }
  }
  if ( UFG::WheeledVehicleManager::m_TrafficSpawningUpdatesEnabled && v3->m_ReinitializeQueued )
  {
    v6 = UFG::ObjectResourceManager::Instance()->mAmbientVehicles.size;
    if ( v6 > 2
      || (v7 = v3->m_SecondsQueued, v7 > UFG::WheeledVehicleManager::msMaxDelayToReinit)
      || v6 > 1 && v7 > (float)(UFG::WheeledVehicleManager::msMaxDelayToReinit * 0.5) )
    {
      UFG::RoadNetworkVisibleArea::Reinitialize(v3->m_VisibleArea);
      v3->m_ReinitializeQueued = 0;
      v3->m_SecondsQueued = 0.0;
      v3->mCurrentSpawnIndex = 0;
    }
    else
    {
      v8 = (Render::DebugDrawContext *)Render::DebugDrawManager::GetContext(Render::DebugDrawManager::mInstance, 3u);
      LODWORD(v17) = v6;
      Render::DebugDrawContext::DrawTextA(
        v8,
        70,
        505,
        &UFG::qColour::Red,
        "Traffic reset in: %.1f, NumVehicles: %d ",
        (float)(UFG::WheeledVehicleManager::msMaxDelayToReinit - v3->m_SecondsQueued),
        v17);
    }
    v3->m_SecondsQueued = v2 + v3->m_SecondsQueued;
  }
  UFG::WheeledVehicleManager::DestroyVehiclesOutsideVisibleArea(v3);
  if ( UFG::WheeledVehicleManager::m_TrafficSpawningUpdatesEnabled )
  {
    deactivateSubSegments.p = 0i64;
    *(_QWORD *)&deactivateSubSegments.size = 0i64;
    activateSubSegments.p = 0i64;
    *(_QWORD *)&activateSubSegments.size = 0i64;
    if ( UFG::RoadNetworkVisibleArea::Update(v3->m_VisibleArea, &deactivateSubSegments, &activateSubSegments) )
      UFG::WheeledVehicleManager::OnVisibleAreaChange(v3, &deactivateSubSegments, &activateSubSegments);
    UFG::WheeledVehicleManager::UpdateTrafficSet(v3);
    if ( activateSubSegments.p )
      operator delete[](activateSubSegments.p);
    activateSubSegments.p = 0i64;
    *(_QWORD *)&activateSubSegments.size = 0i64;
    if ( deactivateSubSegments.p )
      operator delete[](deactivateSubSegments.p);
    deactivateSubSegments.p = 0i64;
    *(_QWORD *)&deactivateSubSegments.size = 0i64;
  }
  UFG::WheeledVehicleManager::DestroyQueuedVehicles(v3);
  if ( UFG::WheeledVehicleManager::m_TrafficSpawningUpdatesEnabled )
  {
    v9 = v3->mSpawnPointExpectedCarsTimer - v2;
    v3->mSpawnPointExpectedCarsTimer = v9;
    if ( v9 < 0.0 )
      UFG::WheeledVehicleManager::UpdateSpawnPointExpectedCars(v3);
    UFG::WheeledVehicleManager::UpdateSpawnPoints(v3, v2);
  }
  UFG::WheeledVehicleManager::UpdateVehicleFades(v3);
  v10 = UFG::gpRoadNetworkResource;
  if ( UFG::gpRoadNetworkResource )
  {
    UFG::RoadNetworkVisibleArea::GetSubjectPosition(v3->m_VisibleArea, (UFG::qVector3 *)&activateSubSegments);
    v11 = UFG::RoadNetworkVisibleArea::GetVisibleDistance(v3->m_VisibleArea);
    v12 = v10->mNumIntersectionsWithLights;
    i = current_update_index;
    v14 = current_update_index + 10;
    if ( v12 < current_update_index + 10 )
      v14 = v10->mNumIntersectionsWithLights;
    if ( current_update_index < v14 )
    {
      v15 = UFG::RoadNetworkResource::GetIntersectionWithLights(v10, current_update_index);
      for ( i = current_update_index; current_update_index < v14; i = current_update_index )
      {
        v16 = v15;
        v15 = 0i64;
        if ( i < v14 - 1 )
        {
          v15 = UFG::RoadNetworkResource::GetIntersectionWithLights(v10, i + 1);
          i = current_update_index;
        }
        current_update_index = i + 1;
        UFG::RoadNetworkIntersection::UpdateLights(
          v16,
          (float)(v12 / 0xA) * v2,
          (UFG::qVector3 *)&activateSubSegments,
          v11);
      }
    }
    if ( i >= v12 )
      i = 0;
    current_update_index = i;
  }
  UFG::TrueDirectionManager::Update(v3->m_TrueDirectionManager);
}

// File Line: 2508
// RVA: 0x64C6D0
void __fastcall UFG::WheeledVehicleManager::EnableParkedCarSpawning(UFG::WheeledVehicleManager *this, bool enable)
{
  UFG::WheeledVehicleManager::mParkedCarSpawningEnabled = enable;
}

// File Line: 2513
// RVA: 0x6445D0
void __fastcall UFG::WheeledVehicleManager::ActivateSubSegments(UFG::WheeledVehicleManager *this, UFG::qArray<UFG::RoadNetworkSubSegment *,0> *activateSubSegments)
{
  UFG::qArray<UFG::RoadNetworkSubSegment *,0> *v2; // rbp
  UFG::WheeledVehicleManager *v3; // r13
  UFG::RoadNetworkSubSegment **v4; // r15
  unsigned int v5; // esi
  unsigned int v6; // er14
  unsigned __int64 v7; // rbx
  unsigned __int64 v8; // rax
  __int64 v9; // r12
  unsigned int v10; // ecx
  unsigned int v11; // edi
  unsigned int v12; // ebx
  unsigned __int64 v13; // rax
  UFG::allocator::free_link *v14; // rax
  UFG::RoadNetworkSubSegment **v15; // rbp
  UFG::allocator::free_link *v16; // rdx
  __int64 v17; // r8
  unsigned int v18; // eax
  unsigned int v19; // er8
  __int64 v20; // rbx
  __int64 v21; // rdi
  UFG::qArray<UFG::RoadNetworkSubSegment *,0> subSegments; // [rsp+28h] [rbp-50h]
  UFG::qArray<UFG::RoadNetworkSubSegment *,0> *v23; // [rsp+88h] [rbp+10h]
  UFG::RoadNetworkSubSegment *v24; // [rsp+90h] [rbp+18h]

  v23 = activateSubSegments;
  v2 = activateSubSegments;
  v3 = this;
  v4 = 0i64;
  subSegments.p = 0i64;
  v5 = 0;
  *(_QWORD *)&subSegments.size = 0i64;
  v6 = 0;
  v7 = activateSubSegments->size;
  if ( (_DWORD)v7 )
  {
    v8 = 8i64 * activateSubSegments->size;
    if ( !is_mul_ok(v7, 8ui64) )
      v8 = -1i64;
    v4 = (UFG::RoadNetworkSubSegment **)UFG::qMalloc(v8, "WheeledVehicleManager", 0i64);
    subSegments.p = v4;
    v6 = v7;
    subSegments.capacity = v7;
  }
  v9 = 0i64;
  if ( v2->size )
  {
    do
    {
      v24 = v2->p[v9];
      if ( UFG::WheeledVehicleManager::ShouldSpawnOnSubSegment(v3, v2->p[v9]) )
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
            v2 = v23;
            v10 = v5;
          }
        }
        ++v5;
        subSegments.size = v11;
        v4[v10] = v24;
      }
      v9 = (unsigned int)(v9 + 1);
    }
    while ( (unsigned int)v9 < v2->size );
  }
  UFG::WheeledVehicleManager::SpawnParkedCars(v3, &subSegments);
  v18 = v3->mNumTrafficCars;
  if ( v18 < UFG::WheeledVehicleManager::mMaxTrafficCars )
    v19 = UFG::WheeledVehicleManager::mMaxTrafficCars - v18;
  else
    v19 = 0;
  UFG::WheeledVehicleManager::CalculateVehicleDistribution(v3, &subSegments, v19);
  if ( v5 > 0x190 )
    v5 = 400;
  if ( v5 )
  {
    v20 = 0i64;
    v21 = v5;
    do
    {
      UFG::WheeledVehicleManager::CreateTrafficCarsOnSubSegment(
        v3,
        v3->mSpawningRecordCollection.p[v20].m_pSubSegment,
        v3->mSpawningRecordCollection.p[v20].m_NumCarsToSpawn);
      ++v20;
      --v21;
    }
    while ( v21 );
  }
  UFG::WheeledVehicleManager::UpdateSpawnPointExpectedCars(v3);
  if ( v4 )
    operator delete[](v4);
}

// File Line: 2570
// RVA: 0x65A140
bool __fastcall UFG::WheeledVehicleManager::ShouldSpawnOnSubSegment(UFG::WheeledVehicleManager *this, UFG::RoadNetworkSubSegment *subSegment)
{
  UFG::RoadNetworkSegment *v2; // rbp
  UFG::WheeledVehicleManager *v3; // rsi
  UFG::RoadNetworkSubSegment *v4; // rdi
  UFG::RoadNetworkLane *v5; // rbx
  float v6; // xmm0_4
  float v7; // xmm0_4
  UFG::qVector3 *v8; // rbx
  UFG::qVector3 *v9; // rax
  float v10; // xmm2_4
  float v11; // xmm0_4
  bool v12; // al
  float v13; // xmm6_4
  bool v14; // al
  UFG::qVector3 result; // [rsp+20h] [rbp-58h]
  UFG::qVector3 pos; // [rsp+30h] [rbp-48h]
  UFG::qVector3 v17; // [rsp+40h] [rbp-38h]
  UFG::qVector3 v18; // [rsp+4Ch] [rbp-2Ch]

  v2 = subSegment->mParentNode;
  v3 = this;
  v4 = subSegment;
  v5 = UFG::RoadNetworkNode::GetCenterLane((UFG::RoadNetworkNode *)&v2->mType);
  v6 = UFG::RoadNetworkSubSegment::GetBeginT(v4, v5->mLaneIndex);
  UFG::RoadNetworkLane::GetPos(v5, &result, v6);
  v7 = UFG::RoadNetworkSubSegment::GetEndT(v4, v5->mLaneIndex);
  UFG::RoadNetworkLane::GetPos(v5, &pos, v7);
  v8 = UFG::RoadNetworkVisibleArea::GetStartPosition(v3->m_VisibleArea, &v17);
  v9 = UFG::RoadNetworkVisibleArea::GetPreviousStartPosition(v3->m_VisibleArea, &v18);
  v10 = v9->y - v8->y;
  v11 = v9->z - v8->z;
  v14 = 1;
  if ( (float)((float)((float)(v10 * v10) + (float)((float)(v9->x - v8->x) * (float)(v9->x - v8->x)))
             + (float)(v11 * v11)) < 900.0 )
  {
    v12 = UFG::RoadNetworkSegment::IsWater(v2);
    v13 = UFG::RoadNetworkVisibleArea::GetMinVisibleDistance(v3->m_VisibleArea, v12);
    if ( UFG::RoadNetworkVisibleArea::IsNearStartPosition(v3->m_VisibleArea, &result, v13)
      || UFG::RoadNetworkVisibleArea::IsNearStartPosition(v3->m_VisibleArea, &pos, v13) )
    {
      v14 = 0;
    }
  }
  return v14;
}

// File Line: 2614
// RVA: 0x647510
void __fastcall UFG::WheeledVehicleManager::CalculateVehicleDistribution(UFG::WheeledVehicleManager *this, UFG::qArray<UFG::RoadNetworkSubSegment *,0> *subSegments, unsigned int numCarsAvailable)
{
  signed int v3; // er15
  UFG::qArray<UFG::RoadNetworkSubSegment *,0> *v4; // r8
  UFG::WheeledVehicleManager *v5; // rsi
  unsigned int v6; // er12
  UFG::qArray<UFG::WheeledVehicleManager::RoadSpawningRecord,0> *v7; // rdi
  unsigned int v8; // edx
  int v9; // er14
  unsigned int v10; // edx
  unsigned int v11; // edx
  float v12; // xmm7_4
  __int64 v13; // r15
  __int64 v14; // rbx
  __int64 v15; // r13
  UFG::WheeledVehicleManager *v16; // r12
  UFG::RoadNetworkSegment *v17; // rdi
  float v18; // xmm1_4
  UFG::WheeledVehicleManager::RoadSpawningRecord *v19; // rsi
  UFG::RoadNetworkSubSegment *v20; // rcx
  float v21; // xmm6_4
  UFG::qNode<UFG::RoadBlock,UFG::RoadBlock> *v22; // rcx
  signed __int64 v23; // rax
  float v24; // xmm6_4
  signed int v25; // edi
  float v26; // xmm0_4
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
  unsigned int v54; // [rsp+4h] [rbp-45h]
  __int64 *v55; // [rsp+10h] [rbp-39h]
  void *mem; // [rsp+18h] [rbp-31h]
  UFG::WheeledVehicleManager *v57; // [rsp+B0h] [rbp+67h]
  UFG::qArray<UFG::RoadNetworkSubSegment *,0> *v58; // [rsp+B8h] [rbp+6Fh]
  int v59; // [rsp+C8h] [rbp+7Fh]

  v3 = numCarsAvailable;
  v54 = numCarsAvailable;
  v4 = subSegments;
  v5 = this;
  v6 = subSegments->size;
  if ( subSegments->size )
  {
    if ( v6 > 0x190 )
      v6 = 400;
    v53 = v6;
    v7 = &this->mSpawningRecordCollection;
    v8 = this->mSpawningRecordCollection.size;
    v9 = 0;
    if ( v8 < v6 )
    {
      if ( (signed int)(v6 - v8) <= 0 )
      {
        if ( v8 != v6 )
        {
          if ( v8 - v6 < v8 )
            v7->size = v6;
          else
            v7->size = 0;
        }
      }
      else
      {
        v10 = this->mSpawningRecordCollection.capacity;
        if ( v6 > v10 )
        {
          if ( v10 )
            v11 = 2 * v10;
          else
            v11 = 1;
          for ( ; v11 < v6; v11 *= 2 )
            ;
          if ( v11 - v6 > 0x10000 )
            v11 = v6 + 0x10000;
          UFG::qArray<UFG::WheeledVehicleManager::RoadSpawningRecord,0>::Reallocate(
            &this->mSpawningRecordCollection,
            v11,
            "qArray.Reallocate(Resize)");
          v4 = v58;
        }
        v7->size = v6;
      }
    }
    v12 = 0.0;
    if ( v6 )
    {
      v13 = 0i64;
      v14 = 0i64;
      v15 = v6;
      v16 = v57;
      while ( 1 )
      {
        v17 = v4->p[v13]->mParentNode;
        v59 = (unsigned __int8)v17->mNumLanes;
        v18 = UFG::RoadNetworkSegment::GetRoadDensity(v17);
        v19 = v16->mSpawningRecordCollection.p;
        *(_QWORD *)&v19[v14].m_SpawnWeight = 0i64;
        v19[v14].m_NumCarsToSpawn = 0;
        v19[v14].m_pSubSegment = 0i64;
        v4 = v58;
        v19[v14].m_pSubSegment = v58->p[v13];
        v19[v14].m_NumCarsToSpawn = 0;
        v20 = v4->p[v13];
        v21 = v20->mLength;
        if ( (float)(v20->mLength - 8.0) > 0.0 && v18 > 0.0 && v20->mStatus.mValue == 4 )
        {
          v22 = v16->m_NavigationData->m_RoadBlockList.mNode.mNext;
          v23 = (signed __int64)&v16->m_NavigationData->m_RoadBlockList;
          if ( v22 == (UFG::qNode<UFG::RoadBlock,UFG::RoadBlock> *)v23 )
          {
LABEL_28:
            v24 = (float)(v21 * v18) * (float)v59;
            v25 = (signed int)v24;
            if ( UFG::qRandom(1.0, &UFG::qDefaultSeed) < (float)(v24 - (float)(signed int)v24) )
              ++v25;
            v19[v14].m_MaxNumCarsToSpawn = v25;
            v4 = v58;
            goto LABEL_32;
          }
          while ( (UFG::RoadNetworkSegment *)v22[1].mNext != v17 )
          {
            v22 = v22->mNext;
            if ( v22 == (UFG::qNode<UFG::RoadBlock,UFG::RoadBlock> *)v23 )
              goto LABEL_28;
          }
        }
        v19[v14].m_MaxNumCarsToSpawn = 0;
LABEL_32:
        v26 = (float)(signed int)v19[v14].m_MaxNumCarsToSpawn;
        v19[v14].m_SpawnWeight = v26;
        v12 = v12 + v26;
        ++v14;
        ++v13;
        if ( !--v15 )
        {
          v6 = v53;
          v5 = v57;
          v3 = v54;
          break;
        }
      }
    }
    v55 = (__int64 *)&v55;
    mem = &v55;
    v27 = &v55;
    if ( v6 )
    {
      v28 = 0i64;
      v29 = v6;
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
          if ( ++v9 == v6 )
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
void __fastcall UFG::WheeledVehicleManager::SpawnTrafficCarOnSpawnPoint(UFG::WheeledVehicleManager *this, UFG::RoadNetworkSpawnPoint *spawnPoint)
{
  UFG::WheeledVehicleManager *v2; // rdi
  UFG::RoadNetworkSpawnPoint *v3; // rbx
  unsigned int v4; // eax
  UFG::qPropertySet *v5; // rax
  UFG::RoadNetworkLane *v6; // rcx
  __int64 v7; // rdx
  UFG::RoadNetworkNode *v8; // r8

  v2 = this;
  v3 = spawnPoint;
  v4 = UFG::RoadNetworkSegment::GetRoadNetworkType(spawnPoint->mSubSegment->mParentNode);
  v5 = UFG::WheeledVehicleManager::ChooseAmbientVehicle(v2, v4, 0);
  if ( v5 )
  {
    v6 = v3->mLane;
    v7 = v3->mLane->mNode.mOffset;
    if ( v7 )
      v8 = (UFG::RoadNetworkNode *)((char *)v6 + v7);
    else
      v8 = 0i64;
    UFG::WheeledVehicleManager::SpawnTrafficVehicle(v2, v5, v8, v6->mLaneIndex, v3->mLane->mSpawnT, v3->mLane->mSpawnT);
  }
}

// File Line: 2797
// RVA: 0x6634E0
void __fastcall UFG::WheeledVehicleManager::UpdateSpawnPointExpectedCars(UFG::WheeledVehicleManager *this)
{
  UFG::WheeledVehicleManager *v1; // r13
  UFG::qArray<UFG::RoadNetworkSubSegment *,0> *v2; // rdx
  float v3; // xmm6_4
  unsigned int v4; // er15
  UFG::WheeledVehicleManager::RoadSpawningRecord *v5; // rcx
  unsigned int v6; // er14
  UFG::RoadNetworkSegment *v7; // rsi
  unsigned int v8; // edx
  unsigned int v9; // edi
  UFG::qBaseTreeRB *v10; // rbx
  UFG::allocator::free_link *v11; // rax
  unsigned int v12; // edx
  UFG::qBaseTreeRB *v13; // rax
  UFG::qBaseTreeRB **v14; // rax
  int v15; // er14
  unsigned int v16; // edi
  UFG::qBaseTreeRB *v17; // rbx
  UFG::allocator::free_link *v18; // rax
  UFG::RoadNetworkResource *v19; // rbx
  UFG::qBaseTreeRB *i; // r13
  UFG::RoadNetworkSegment *v21; // r14
  unsigned int v22; // esi
  unsigned int v23; // ett
  int v24; // edi
  int v25; // er12
  char v26; // r15
  unsigned int v27; // ebx
  UFG::RoadNetworkSpawnPoint *v28; // rcx
  int j; // ebx
  UFG::RoadNetworkSpawnPoint *v30; // rcx
  unsigned int v31; // ebx
  Render::SkinningCacheNode *v32; // rbx
  Render::SkinningCacheNode *v33; // rbx
  UFG::qBaseTreeRB v34; // [rsp+10h] [rbp-39h]
  UFG::qBaseTreeRB *v35; // [rsp+B0h] [rbp+67h]
  UFG::allocator::free_link *v36; // [rsp+B8h] [rbp+6Fh]

  v1 = this;
  this->mSpawnPointExpectedCarsTimer = UFG::WheeledVehicleManager::mSpawnPointExpectedCarsMaxTime;
  v2 = this->m_VisibleArea->mPreviousVisibleSubSegments;
  v3 = (float)(signed int)v2->size;
  if ( v3 > 400.0 )
    v3 = FLOAT_400_0;
  UFG::WheeledVehicleManager::CalculateVehicleDistribution(this, v2, UFG::WheeledVehicleManager::mDefaultMaxTrafficCars);
  v35 = &v34;
  UFG::qBaseTreeRB::qBaseTreeRB(&v34);
  v4 = 0;
  if ( v3 > 0.0 )
  {
    LODWORD(v35) = -1;
    do
    {
      v5 = v1->mSpawningRecordCollection.p;
      v6 = v5[v4].m_NumCarsToSpawn;
      v7 = v5[v4].m_pSubSegment->mParentNode;
      v8 = v7->mIndex;
      if ( !v8 || !UFG::qBaseTreeRB::Get(&v34, v8) )
      {
        v9 = v7->mIndex;
        if ( !v9 || (v10 = UFG::qBaseTreeRB::Get(&v34, v9)) == 0i64 )
        {
          v11 = UFG::qMalloc(0x28ui64, "qMap::qMapNode32", 0i64);
          v10 = (UFG::qBaseTreeRB *)v11;
          v36 = v11;
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
          UFG::qBaseTreeRB::Add(&v34, &v10->mRoot);
        }
        LODWORD(v10->mNULL.mParent) = 0;
      }
      v12 = v7->mIndex;
      if ( v12 && (v13 = UFG::qBaseTreeRB::Get(&v34, v12)) != 0i64 )
        v14 = (UFG::qBaseTreeRB **)&v13->mNULL;
      else
        v14 = &v35;
      v15 = *(_DWORD *)v14 + v6;
      v16 = v7->mIndex;
      if ( !v16 || (v17 = UFG::qBaseTreeRB::Get(&v34, v16)) == 0i64 )
      {
        v18 = UFG::qMalloc(0x28ui64, "qMap::qMapNode32", 0i64);
        v17 = (UFG::qBaseTreeRB *)v18;
        v36 = v18;
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
        UFG::qBaseTreeRB::Add(&v34, &v17->mRoot);
      }
      LODWORD(v17->mNULL.mParent) = v15;
      ++v4;
    }
    while ( (float)(signed int)v4 < v3 );
  }
  v19 = UFG::gpRoadNetworkResource;
  v35 = (UFG::qBaseTreeRB *)UFG::gpRoadNetworkResource;
  for ( i = (UFG::qBaseTreeRB *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&v34);
        i;
        i = UFG::qBaseTreeRB::GetNext(&v34, &i->mRoot) )
  {
    v21 = UFG::RoadNetworkResource::GetSegment(v19, i->mRoot.mUID);
    v22 = (unsigned __int8)v21->mNumLanes;
    if ( v21->mNumLanes )
    {
      v23 = (unsigned int)i->mNULL.mParent;
      v24 = v23 % v22;
      v25 = v23 / v22;
      v26 = 0;
      v27 = 0;
      if ( v21->mNumLanes )
      {
        do
        {
          v28 = UFG::RoadNetworkNode::GetLane((UFG::RoadNetworkNode *)&v21->mType, v27)->mSpawnPoint;
          if ( v28 )
          {
            v28->mNumExpectedCars = v25;
            v26 = 1;
          }
          ++v27;
        }
        while ( v27 < v22 );
        if ( v26 )
        {
          for ( j = 0; v24; j = v31 % v22 )
          {
            v30 = UFG::RoadNetworkNode::GetLane((UFG::RoadNetworkNode *)&v21->mType, j)->mSpawnPoint;
            if ( v30 )
            {
              ++v30->mNumExpectedCars;
              --v24;
            }
            v31 = j + 1;
            if ( v31 > v22 )
              v31 = 0;
          }
        }
      }
      v19 = (UFG::RoadNetworkResource *)v35;
    }
  }
  while ( v34.mCount )
  {
    v32 = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&v34);
    UFG::qBaseTreeVariableRB<unsigned __int64>::Remove((UFG::qBaseTreeVariableRB<unsigned __int64> *)&v34, &v32->mNode);
    operator delete[](v32);
  }
  v35 = &v34;
  while ( v34.mCount )
  {
    v33 = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&v34);
    UFG::qBaseTreeVariableRB<unsigned __int64>::Remove((UFG::qBaseTreeVariableRB<unsigned __int64> *)&v34, &v33->mNode);
    operator delete[](v33);
  }
  UFG::qBaseTreeRB::~qBaseTreeRB((Render::Skinning *)&v34);
}

// File Line: 2940
// RVA: 0x663810
void __fastcall UFG::WheeledVehicleManager::UpdateSpawnPoints(UFG::WheeledVehicleManager *this, float seconds)
{
  UFG::RoadNetworkVisibleArea *v2; // rbp
  UFG::WheeledVehicleManager *v3; // r14
  UFG::RoadNetworkSpawnPoint *v4; // rax
  UFG::RoadNetworkVisibleArea *v5; // rsi
  UFG::RoadNetworkSpawnPoint *v6; // rdi
  UFG::qNode<UFG::RoadBlock,UFG::RoadBlock> *v7; // rdx
  signed __int64 v8; // rcx
  unsigned int v9; // edx
  signed __int64 v10; // rax
  signed __int64 v11; // rcx
  UFG::RoadNetworkSpawnPoint *v12; // rax
  UFG::RoadNetworkSpawnPoint *v13; // rbx
  unsigned int v14; // er8
  signed __int64 v15; // rcx
  signed __int64 i; // rdx
  UFG::RoadNetworkSpawnPoint *v17; // rdx

  v2 = this->m_VisibleArea;
  v3 = this;
  UFG::RoadNetworkVisibleArea::FirstSpawnPoint(this->m_VisibleArea);
  if ( !(unsigned __int8)UFG::RoadNetworkVisibleArea::NoMoreSpawnPoints(v2) )
  {
    while ( 1 )
    {
      v4 = UFG::RoadNetworkVisibleArea::GetCurrentEdgeSpawnPoint(v2);
      v5 = v3->m_VisibleArea;
      v6 = v4;
      if ( UFG::RoadNetworkSpawnPoint::Update(v4, seconds) )
      {
        v7 = v3->m_NavigationData->m_RoadBlockList.mNode.mNext;
        v8 = (signed __int64)&v3->m_NavigationData->m_RoadBlockList;
        if ( v7 != (UFG::qNode<UFG::RoadBlock,UFG::RoadBlock> *)v8 )
        {
          while ( v7[1].mNext != (UFG::qNode<UFG::RoadBlock,UFG::RoadBlock> *)v6->mSubSegment->mParentNode )
          {
            v7 = v7->mNext;
            if ( v7 == (UFG::qNode<UFG::RoadBlock,UFG::RoadBlock> *)v8 )
              goto LABEL_6;
          }
          goto LABEL_24;
        }
LABEL_6:
        if ( UFG::RoadNetworkSpawnPoint::CanSpawnCar(v6) )
          break;
      }
LABEL_24:
      UFG::RoadNetworkVisibleArea::NextSpawnPoint(v2);
      if ( (unsigned __int8)UFG::RoadNetworkVisibleArea::NoMoreSpawnPoints(v2) )
        return;
    }
    v9 = 0;
    v10 = (signed __int64)&v6->mLane->mStartConnection;
    v11 = (signed __int64)&v6->mLane->mCars.mNode.mNext[-2].mNext;
    if ( v11 != v10 )
    {
      do
      {
        ++v9;
        v11 = *(_QWORD *)(v11 + 32) - 24i64;
      }
      while ( v11 != v10 );
      if ( v9 )
        goto LABEL_27;
    }
    if ( v6->mNumExpectedCars )
    {
LABEL_27:
      if ( v6->mNumExpectedCars > v9 )
      {
        v17 = v6;
LABEL_22:
        UFG::WheeledVehicleManager::SpawnTrafficCarOnSpawnPoint(v3, v17);
        goto LABEL_23;
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
          if ( v12 != v6 )
          {
            if ( UFG::RoadNetworkSpawnPoint::CanSpawnCar(v12) )
            {
              v14 = 0;
              v15 = (signed __int64)&v13->mLane->mStartConnection;
              for ( i = (signed __int64)&v13->mLane->mCars.mNode.mNext[-2].mNext; i != v15; i = *(_QWORD *)(i + 32)
                                                                                              - 24i64 )
                ++v14;
              if ( v13->mNumExpectedCars > v14 )
                break;
            }
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
void __fastcall UFG::WheeledVehicleManager::SpawnParkedCars(UFG::WheeledVehicleManager *this, UFG::qArray<UFG::RoadNetworkSubSegment *,0> *subSegments)
{
  UFG::qArray<UFG::RoadNetworkSubSegment *,0> *v2; // rax
  UFG::WheeledVehicleManager *v3; // r9
  unsigned int v4; // er10
  UFG::qArray<UFG::WheeledVehicleManager::RoadSpawningRecord,0> *v5; // rsi
  unsigned int v6; // ecx
  __int64 v7; // rdi
  unsigned int v8; // ebx
  unsigned int v9; // edx
  unsigned int v10; // edx
  int v11; // er12
  __int64 *v12; // rdx
  __int64 v13; // r15
  __int64 v14; // r14
  __int64 v15; // r13
  UFG::RoadNetworkSubSegment **v16; // rax
  __int64 v17; // rsi
  UFG::RoadNetworkSegment *v18; // rbx
  __int64 **v19; // rcx
  __int64 *v20; // rax
  __int64 *v21; // rax
  __int64 v22; // rax
  unsigned int v23; // eax
  unsigned int v24; // er8
  __int64 v25; // rcx
  __int64 *v26; // rax
  float v27; // xmm0_4
  __int64 **v28; // rcx
  __int64 *v29; // rax
  __int64 v30; // rbx
  UFG::WheeledVehicleManager::RoadSpawningRecord *v31; // rdx
  unsigned int v32; // er8
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
  __int64 *v43; // [rsp+28h] [rbp-20h]
  void *mem; // [rsp+30h] [rbp-18h]
  UFG::WheeledVehicleManager *v45; // [rsp+90h] [rbp+48h]
  UFG::qArray<UFG::RoadNetworkSubSegment *,0> *v46; // [rsp+98h] [rbp+50h]
  unsigned int v47; // [rsp+A0h] [rbp+58h]
  signed int v48; // [rsp+A8h] [rbp+60h]

  v46 = subSegments;
  v45 = this;
  v2 = subSegments;
  v3 = this;
  v4 = subSegments->size;
  if ( subSegments->size )
  {
    if ( v4 > 0x190 )
      v4 = 400;
    v47 = v4;
    v5 = &this->mParkingSpawningRecordCollection;
    v6 = this->mParkingSpawningRecordCollection.size;
    v7 = 0i64;
    if ( v6 < v4 )
    {
      if ( (signed int)(v4 - v6) <= 0 )
      {
        if ( v6 != v4 )
        {
          if ( v6 - v4 < v6 )
            v5->size = v4;
          else
            v5->size = 0;
        }
      }
      else
      {
        v8 = v4;
        v9 = v3->mParkingSpawningRecordCollection.capacity;
        if ( v4 > v9 )
        {
          if ( v9 )
            v10 = 2 * v9;
          else
            v10 = 1;
          for ( ; v10 < v4; v10 *= 2 )
            ;
          if ( v10 - v4 > 0x10000 )
            v10 = v4 + 0x10000;
          UFG::qArray<UFG::WheeledVehicleManager::RoadSpawningRecord,0>::Reallocate(
            &v3->mParkingSpawningRecordCollection,
            v10,
            "qArray.Reallocate(Resize)");
          v3 = v45;
          v4 = v47;
        }
        v5->size = v8;
      }
      v2 = v46;
    }
    v11 = 0;
    v43 = (__int64 *)&v43;
    mem = &v43;
    v12 = (__int64 *)&v43;
    if ( v4 )
    {
      v13 = 0i64;
      v14 = 0i64;
      v15 = v4;
      do
      {
        v16 = v2->p;
        v17 = (__int64)v16[v14];
        if ( *(_WORD *)(v17 + 44) == 4 )
        {
          v18 = *(UFG::RoadNetworkSegment **)(v17 + 16);
          v48 = UFG::RoadNetworkSubSegment::GetNumAvailableParkingSpots(v16[v14]);
          UFG::RoadNetworkSegment::GetRoadDensity(v18);
          v3 = v45;
          v12 = (__int64 *)&v45->mParkingSpawningRecordCollection.p[v13];
          *((_DWORD *)v12 + 6) = 0;
          v12[4] = v17;
          *((_DWORD *)v12 + 5) = v48;
          *((float *)v12 + 4) = (float)v48;
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
            while ( (float)v48 >= *((float *)v19 + 4) )
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
          v11 += v48;
        }
        ++v14;
        ++v13;
        --v15;
        v2 = v46;
      }
      while ( v15 );
      v4 = v47;
    }
    v23 = v3->mNumParkedCars;
    if ( v23 < UFG::WheeledVehicleManager::mMaxParkedCars )
      v24 = UFG::WheeledVehicleManager::mMaxParkedCars - v23;
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
      if ( v4 )
      {
        v30 = v4;
        do
        {
          v31 = v3->mParkingSpawningRecordCollection.p;
          v32 = v31[v7].m_NumCarsToSpawn;
          if ( v32 )
          {
            UFG::WheeledVehicleManager::CreateParkedCarsOnSubSegment(v3, v31[v7].m_pSubSegment, v32);
            v3 = v45;
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
  UFG::WheeledVehicleManager *v2; // rbx
  UFG::qNode<UFG::TrafficRegion,UFG::TrafficRegion> *v4; // r8
  UFG::qSafePointer<UFG::SimComponent,UFG::TrafficRegion> *v5; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v7; // rax
  UFG::qNode<UFG::TrafficRegion,UFG::TrafficRegion> *v8; // rax
  UFG::SimComponent *v9; // rax

  v1 = 0;
  v2 = this;
  if ( !UFG::WheeledVehicleManager::mUpdateTrafficRegionEnabled )
    return 0;
  v4 = UFG::WheeledVehicleManager::GetClosestTrafficRegion(this);
  if ( v4 != (UFG::qNode<UFG::TrafficRegion,UFG::TrafficRegion> *)v2->mCurrentTrafficRegion.m_pPointer )
  {
    v5 = &v2->mCurrentTrafficRegion;
    if ( v2->mCurrentTrafficRegion.m_pPointer )
    {
      v6 = v5->mPrev;
      v7 = v2->mCurrentTrafficRegion.mNext;
      v6->mNext = v7;
      v7->mPrev = v6;
      v5->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v5->mPrev;
      v2->mCurrentTrafficRegion.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->mCurrentTrafficRegion.mPrev;
    }
    v2->mCurrentTrafficRegion.m_pPointer = (UFG::SimComponent *)v4;
    if ( v4 )
    {
      v8 = v4->mNext;
      v8->mNext = (UFG::qNode<UFG::TrafficRegion,UFG::TrafficRegion> *)v5;
      v5->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)v8;
      v2->mCurrentTrafficRegion.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v4->mNext;
      v4->mNext = (UFG::qNode<UFG::TrafficRegion,UFG::TrafficRegion> *)v5;
    }
    v9 = v2->mCurrentTrafficRegion.m_pPointer;
    if ( v9 )
    {
      if ( v9->m_pSimObject )
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
UFG::qSymbol *__fastcall UFG::WheeledVehicleManager::GetCurrentTrafficSet(UFG::WheeledVehicleManager *this, UFG::qSymbol *result)
{
  UFG::qSymbol *v2; // rbx
  unsigned int v3; // edx
  UFG::qSymbol *v4; // rax
  UFG::TrafficRegion *v5; // rcx
  UFG::SimObject *v6; // rdx

  v2 = result;
  v3 = this->m_TrafficSetOverride.mUID;
  if ( v3 == UFG::gNullQSymbol.mUID )
  {
    v5 = (UFG::TrafficRegion *)this->mCurrentTrafficRegion.m_pPointer;
    if ( v5 && (v6 = v5->m_pSimObject) != 0i64 && v6->m_pSceneObj )
    {
      UFG::TrafficRegion::GetSpawnSet_UseTimeSetIfPresent(v5, v2);
      v4 = v2;
    }
    else
    {
      v2->mUID = UFG::gNullQSymbol.mUID;
      v4 = v2;
    }
  }
  else
  {
    v2->mUID = v3;
    v4 = v2;
  }
  return v4;
}

// File Line: 3115
// RVA: 0x64D8B0
UFG::qNode<UFG::TrafficRegion,UFG::TrafficRegion> *__fastcall UFG::WheeledVehicleManager::GetClosestTrafficRegion(UFG::WheeledVehicleManager *this)
{
  float v1; // xmm6_4
  UFG::qNode<UFG::TrafficRegion,UFG::TrafficRegion> *v2; // rax
  UFG::qNode<UFG::TrafficRegion,UFG::TrafficRegion> *v3; // r8
  UFG::qList<UFG::TrafficRegion,UFG::TrafficRegion,1,0> *v4; // rcx
  UFG::qVector3 result; // [rsp+20h] [rbp-28h]

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
  return atexit(dynamic_atexit_destructor_for__UFG::WheeledVehicleManagerScriptInterface::mScriptClassNameSymbol__);
}

// File Line: 3203
// RVA: 0x1573860
__int64 dynamic_initializer_for__UFG::WheeledVehicleManagerScriptInterface::mInstanceNameSymbol__()
{
  return atexit(dynamic_atexit_destructor_for__UFG::WheeledVehicleManagerScriptInterface::mInstanceNameSymbol__);
}

// File Line: 3219
// RVA: 0x647360
void UFG::WheeledVehicleManagerScriptInterface::BindAtomics(void)
{
  SSActorClass *v0; // rax
  SSActorClass *v1; // rcx
  SSActorClass *v2; // rcx
  SSActorClass *v3; // rcx
  SSActorClass *v4; // rcx
  SSActorClass *v5; // rcx
  __m128i v6; // [rsp+20h] [rbp-10h]
  UFG::qSymbol result; // [rsp+40h] [rbp+10h]

  UFG::WheeledVehicleManagerScriptInterface::mScriptClassNameSymbol.mUID = UFG::qSymbol::create_from_string(
                                                                             &result,
                                                                             UFG::WheeledVehicleManagerScriptInterface::mScriptClassName)->mUID;
  UFG::WheeledVehicleManagerScriptInterface::mInstanceNameSymbol.mUID = UFG::qSymbol::create_from_string(
                                                                          &result,
                                                                          UFG::WheeledVehicleManagerScriptInterface::mInstanceName)->mUID;
  v0 = (SSActorClass *)SSBrain::get_class((ASymbol *)&UFG::WheeledVehicleManagerScriptInterface::mScriptClassNameSymbol);
  v6.m128i_i64[0] = (__int64)UFG::WheeledVehicleManagerScriptInterface::Mthd_EnableTraffic;
  v6.m128i_i32[2] = 0;
  _mm_store_si128(&v6, v6);
  UFG::WheeledVehicleManagerScriptInterface::mClass = v0;
  SSClass::register_method_mthd(
    (SSClass *)&v0->vfptr,
    "enable_traffic_",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v6,
    0);
  v1 = UFG::WheeledVehicleManagerScriptInterface::mClass;
  v6.m128i_i32[2] = 0;
  v6.m128i_i64[0] = (__int64)UFG::WheeledVehicleManagerScriptInterface::Mthd_SetTrafficDensityScale;
  _mm_store_si128(&v6, v6);
  SSClass::register_method_mthd(
    (SSClass *)&v1->vfptr,
    "set_traffic_density_scale",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v6,
    0);
  v2 = UFG::WheeledVehicleManagerScriptInterface::mClass;
  v6.m128i_i32[2] = 0;
  v6.m128i_i64[0] = (__int64)UFG::WheeledVehicleManagerScriptInterface::Mthd_ClearTraffic;
  _mm_store_si128(&v6, v6);
  SSClass::register_method_mthd(
    (SSClass *)&v2->vfptr,
    "clear_traffic",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v6,
    0);
  v3 = UFG::WheeledVehicleManagerScriptInterface::mClass;
  v6.m128i_i32[2] = 0;
  v6.m128i_i64[0] = (__int64)UFG::WheeledVehicleManagerScriptInterface::Mthd_ClearNonParkedTraffic;
  _mm_store_si128(&v6, v6);
  SSClass::register_method_mthd(
    (SSClass *)&v3->vfptr,
    "clear_non_parked_traffic",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v6,
    0);
  v4 = UFG::WheeledVehicleManagerScriptInterface::mClass;
  v6.m128i_i32[2] = 0;
  v6.m128i_i64[0] = (__int64)UFG::WheeledVehicleManagerScriptInterface::Mthd_LockTrafficSystem;
  _mm_store_si128(&v6, v6);
  SSClass::register_method_mthd(
    (SSClass *)&v4->vfptr,
    "lock_traffic_system",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v6,
    0);
  v5 = UFG::WheeledVehicleManagerScriptInterface::mClass;
  v6.m128i_i32[2] = 0;
  v6.m128i_i64[0] = (__int64)UFG::WheeledVehicleManagerScriptInterface::Mthd_UseSpecificTrafficSet;
  _mm_store_si128(&v6, v6);
  SSClass::register_method_mthd(
    (SSClass *)&v5->vfptr,
    "use_specific_traffic_set",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v6,
    0);
  v6.m128i_i32[2] = 0;
  v6.m128i_i64[0] = (__int64)UFG::WheeledVehicleManagerScriptInterface::Mthd_UseAmbientTrafficSet;
  _mm_store_si128(&v6, v6);
  SSClass::register_method_mthd(
    (SSClass *)&UFG::WheeledVehicleManagerScriptInterface::mClass->vfptr,
    "use_ambient_traffic_set",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v6,
    0);
}

// File Line: 3234
// RVA: 0x653150
void __fastcall UFG::WheeledVehicleManagerScriptInterface::Mthd_EnableTraffic(UFG::WheeledVehicleManagerScriptInterface *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::WheeledVehicleManager::EnableTrafficSystem(
    this->m_WheeledVehicleManager,
    (*pScope->i_data.i_array_p)->i_data_p->i_user_data != 0);
}

// File Line: 3240
// RVA: 0x653190
void __fastcall UFG::WheeledVehicleManagerScriptInterface::Mthd_SetTrafficDensityScale(UFG::WheeledVehicleManagerScriptInterface *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::WheeledVehicleManager::SetTrafficDensityScale(*(float *)&(*pScope->i_data.i_array_p)->i_data_p->i_user_data);
}

// File Line: 3246
// RVA: 0x653140
void __fastcall UFG::WheeledVehicleManagerScriptInterface::Mthd_ClearTraffic(UFG::WheeledVehicleManagerScriptInterface *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::WheeledVehicleManager::DestroyAllWheeledVehicles(this->m_WheeledVehicleManager);
}

// File Line: 3251
// RVA: 0x653130
void __fastcall UFG::WheeledVehicleManagerScriptInterface::Mthd_ClearNonParkedTraffic(UFG::WheeledVehicleManagerScriptInterface *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::WheeledVehicleManager::DestroyAllNonParkedWheeledVehicles(this->m_WheeledVehicleManager);
}

// File Line: 3258
// RVA: 0x653170
void __fastcall UFG::WheeledVehicleManagerScriptInterface::Mthd_LockTrafficSystem(UFG::WheeledVehicleManagerScriptInterface *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::WheeledVehicleManager::m_TrafficSystemLocked = (*pScope->i_data.i_array_p)->i_data_p->i_user_data != 0;
}

// File Line: 3264
// RVA: 0x6531E0
void __fastcall UFG::WheeledVehicleManagerScriptInterface::Mthd_UseSpecificTrafficSet(UFG::WheeledVehicleManagerScriptInterface *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  this->m_WheeledVehicleManager->m_TrafficSetOverride.mUID = (*pScope->i_data.i_array_p)->i_data_p->i_user_data;
  UFG::ObjectResourceManager::Instance()->mEntityStates[1].mUpdateRequired = 1;
}

// File Line: 3270
// RVA: 0x6531B0
void __fastcall UFG::WheeledVehicleManagerScriptInterface::Mthd_UseAmbientTrafficSet(UFG::WheeledVehicleManagerScriptInterface *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  this->m_WheeledVehicleManager->m_TrafficSetOverride = UFG::gNullQSymbol;
  UFG::ObjectResourceManager::Instance()->mEntityStates[1].mUpdateRequired = 1;
}

