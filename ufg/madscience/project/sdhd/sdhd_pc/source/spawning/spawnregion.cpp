// File Line: 91
// RVA: 0x5B42A0
__int64 __fastcall UFG::SpawnRegion::GetTypeSize(UFG::SpawnRegion *this)
{
  return 392i64;
}

// File Line: 111
// RVA: 0x5B1980
void __fastcall UFG::SpawnRegion::SpawnRegion(UFG::SpawnRegion *this, UFG::qSymbol *name, UFG::SimObject *pSimObj)
{
  UFG::MarkerBase::MarkerBase(this, name, pSimObj, 0x30000u);
  this->UFG::SpawnPointInterface::UFG::MarkerBase::UFG::HintComponentBase::UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::SpawnPointInterface::`vftable;
  UFG::qSafePointerNodeWithCallbacks<UFG::SpawnRegion>::qSafePointerNodeWithCallbacks<UFG::SpawnRegion>(&this->UFG::qSafePointerNodeWithCallbacks<UFG::SpawnRegion>);
  this->UFG::SpawnPointInterface::UFG::MarkerBase::UFG::HintComponentBase::UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::SpawnRegion::`vftable{for `UFG::SpawnPointInterface};
  this->UFG::qSafePointerNodeWithCallbacks<UFG::SpawnRegion>::UFG::qSafePointerNode<UFG::SpawnRegion>::vfptr = (UFG::qSafePointerNode<UFG::SpawnRegion>Vtbl *)&UFG::SpawnRegion::`vftable{for `UFG::qSafePointerNodeWithCallbacks<UFG::SpawnRegion>};
  *(_QWORD *)&this->mAABBOnActivate.mMin.x = 0i64;
  *(_QWORD *)&this->mAABBOnActivate.mMin.z = 0i64;
  *(_QWORD *)&this->mAABBOnActivate.mMax.y = 0i64;
  this->mZones.mNode.mPrev = &this->mZones.mNode;
  this->mZones.mNode.mNext = &this->mZones.mNode;
  this->mpNearbyIntestPoints = 0i64;
  this->mCanPathTo = eCanPathTo_Undetermined;
  UFG::SimComponent::AddType(this, UFG::SpawnRegion::_SpawnRegionTypeUID, "SpawnRegion");
  UFG::SpawnRegion::Initialize(this, pSimObj);
}

// File Line: 122
// RVA: 0x5B4B30
void __fastcall UFG::SpawnRegion::Initialize(UFG::SpawnRegion *this, UFG::SimObjectGame *pSimObj)
{
  UFG::RegionComponent *ComponentOfTypeHK; // rax
  signed __int16 m_Flags; // cx
  UFG::SimObject *m_pSimObject; // rax
  UFG::SceneObjectProperties *m_pSceneObj; // rax

  if ( pSimObj )
  {
    m_Flags = pSimObj->m_Flags;
    if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
      ComponentOfTypeHK = (UFG::RegionComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                    pSimObj,
                                                    UFG::RegionComponent::_TypeUID);
    else
      ComponentOfTypeHK = (UFG::RegionComponent *)UFG::SimObject::GetComponentOfType(
                                                    pSimObj,
                                                    UFG::RegionComponent::_TypeUID);
  }
  else
  {
    ComponentOfTypeHK = 0i64;
  }
  this->mpRegion = ComponentOfTypeHK;
  m_pSimObject = this->m_pSimObject;
  this->mpNearbyIntestPoints = 0i64;
  if ( m_pSimObject )
  {
    m_pSceneObj = m_pSimObject->m_pSceneObj;
    this->mIndexOfLastSpawned = 0;
    this->mpSceneObjProps = m_pSceneObj;
  }
  else
  {
    this->mpSceneObjProps = 0i64;
    this->mIndexOfLastSpawned = 0;
  }
}

// File Line: 179
// RVA: 0x5B1E90
void __fastcall UFG::SpawnRegion::~SpawnRegion(UFG::SpawnRegion *this)
{
  UFG::qList<SimObjectFlagSetTask,SimObjectFlagSetList,1,0> *p_mZones; // rbx
  UFG::SpawnZone *p_mNext; // rcx
  UFG::qNode<UFG::SpawnZone,UFG::SpawnRegionList> *mPrev; // rdx
  UFG::qNode<UFG::SpawnZone,UFG::SpawnRegionList> *mNext; // rax
  UFG::qNode<SimObjectFlagSetTask,SimObjectFlagSetList> *v6; // rdx
  UFG::qNode<SimObjectFlagSetTask,SimObjectFlagSetList> *v7; // rax

  this->UFG::SpawnPointInterface::UFG::MarkerBase::UFG::HintComponentBase::UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::SpawnRegion::`vftable{for `UFG::SpawnPointInterface};
  this->UFG::qSafePointerNodeWithCallbacks<UFG::SpawnRegion>::UFG::qSafePointerNode<UFG::SpawnRegion>::vfptr = (UFG::qSafePointerNode<UFG::SpawnRegion>Vtbl *)&UFG::SpawnRegion::`vftable{for `UFG::qSafePointerNodeWithCallbacks<UFG::SpawnRegion>};
  p_mZones = (UFG::qList<SimObjectFlagSetTask,SimObjectFlagSetList,1,0> *)&this->mZones;
  if ( &this->mZones.mNode.mNext[-3].mNext != (UFG::qNode<UFG::SpawnZone,UFG::SpawnRegionList> **)&this->mWorldToLocal.v2.z )
  {
    do
    {
      p_mNext = (UFG::SpawnZone *)&this->mZones.mNode.mNext[-3].mNext;
      mPrev = this->mZones.mNode.mNext->mPrev;
      mNext = p_mNext->UFG::qNode<UFG::SpawnZone,UFG::SpawnRegionList>::mNext;
      mPrev->mNext = mNext;
      mNext->mPrev = mPrev;
      p_mNext->UFG::qNode<UFG::SpawnZone,UFG::SpawnRegionList>::mPrev = &p_mNext->UFG::qNode<UFG::SpawnZone,UFG::SpawnRegionList>;
      p_mNext->UFG::qNode<UFG::SpawnZone,UFG::SpawnRegionList>::mNext = &p_mNext->UFG::qNode<UFG::SpawnZone,UFG::SpawnRegionList>;
      UFG::PedSpawnManager::FreeSpawnZone(p_mNext);
    }
    while ( &p_mZones->mNode.mNext[-3].mNext != &p_mZones[-3].mNode.mNext );
  }
  UFG::qList<SimObjectFlagSetTask,SimObjectFlagSetList,1,0>::DeleteNodes(p_mZones);
  v6 = p_mZones->mNode.mPrev;
  v7 = p_mZones->mNode.mNext;
  v6->mNext = v7;
  v7->mPrev = v6;
  p_mZones->mNode.mPrev = &p_mZones->mNode;
  p_mZones->mNode.mNext = &p_mZones->mNode;
  UFG::qSafePointerNodeWithCallbacks<UFG::SpawnRegion>::~qSafePointerNodeWithCallbacks<UFG::SpawnRegion>(&this->UFG::qSafePointerNodeWithCallbacks<UFG::SpawnRegion>);
  UFG::MarkerBase::~MarkerBase(this);
}

// File Line: 265
// RVA: 0x5B41A0
float __fastcall UFG::SpawnRegion::GetTargetPopulationFromDensity(UFG::SpawnRegion::eDensity density, float area)
{
  switch ( density )
  {
    case Density_area_very_low:
      return (float)(UFG::PedSpawnManager::msPedsPerSquareMetre * area) * 0.33000001;
    case Density_area_low:
      return (float)(UFG::PedSpawnManager::msPedsPerSquareMetre * area) * 0.66000003;
    case Density_area_high:
      return (float)(UFG::PedSpawnManager::msPedsPerSquareMetre * area) * 1.3;
    case Density_area_very_high:
      return (float)(UFG::PedSpawnManager::msPedsPerSquareMetre * area) * 1.5;
  }
  return (float)(UFG::PedSpawnManager::msPedsPerSquareMetre * area) * 0.89999998;
}

// File Line: 297
// RVA: 0x5B4150
double __fastcall UFG::SpawnRegion::GetTargetPopulation(UFG::SpawnRegion *this, float subArea)
{
  int mCachedPopulationSetting; // edx
  double v3; // xmm6_8
  double result; // xmm0_8

  mCachedPopulationSetting = this->mCachedPopulationSetting;
  if ( mCachedPopulationSetting < 0 )
  {
    *(float *)&result = UFG::SpawnRegion::GetTargetPopulationFromDensity(
                          (UFG::SpawnRegion::eDensity)mCachedPopulationSetting,
                          subArea);
  }
  else
  {
    *(_QWORD *)&v3 = COERCE_UNSIGNED_INT((float)mCachedPopulationSetting);
    *(float *)&v3 = (float)(*(float *)&v3 * subArea)
                  / (*((float (__fastcall **)(UFG::RegionBase *))&this->mpRegion->mpRegion.mPtr->vfptr->__vecDelDtor + 2))(this->mpRegion->mpRegion.mPtr);
    return v3;
  }
  return result;
}

// File Line: 357
// RVA: 0x5B2AB0
char __fastcall UFG::SpawnRegion::CacheSpawnSetandDensity(UFG::SpawnRegion *this, component_SpawnRegion *dataPtr)
{
  UFG::qBaseTreeRB *v4; // rbx
  UFG::TimeOfDayManager *Instance; // rax
  unsigned int v6; // r9d
  int v7; // r8d
  unsigned int mParent; // r10d
  UFG::qBaseNodeRB *v9; // rdx
  int v10; // eax
  int v11; // ecx
  UFG::qPropertySet *PropertySet; // rax
  int SpawnPopulation; // eax
  UFG::qSymbol timeSetName; // [rsp+38h] [rbp+10h] BYREF
  UFG::qSymbol propSetName; // [rsp+40h] [rbp+18h] BYREF

  timeSetName.mUID = dataPtr->TimeSet.mUID;
  if ( timeSetName.mUID == UFG::gNullQSymbol.mUID )
  {
    propSetName.mUID = dataPtr->SpawnInfo.mUID;
    PropertySet = UFG::PropertySetManager::GetPropertySet(&propSetName);
    this->mGameHourWhenSpawnSetWasCached = -1;
    this->mpCachedSpawnSet = PropertySet;
    SpawnPopulation = dataPtr->SpawnPopulation;
    if ( SpawnPopulation == -100 )
      SpawnPopulation = -3;
    this->mCachedPopulationSetting = SpawnPopulation;
    return 1;
  }
  else
  {
    v4 = UFG::TimeSetCache::ObtainTimeSet(&UFG::gTimeSetCache, &timeSetName);
    Instance = UFG::TimeOfDayManager::GetInstance();
    v6 = 0;
    v7 = (int)(float)(Instance->m_SecondsSinceMidnight * 0.00027777778);
    this->mGameHourWhenSpawnSetWasCached = v7;
    mParent = (unsigned int)v4->mNULL.mParent;
    if ( mParent )
    {
      v9 = v4->mNULL.mChild[0];
      do
      {
        v10 = (int)v9->mChild[1];
        if ( v10 != -1 )
        {
          v11 = HIDWORD(v9->mChild[1]);
          if ( v11 != -1 )
          {
            if ( v11 <= v10 )
            {
              if ( v11 >= v10 )
              {
                if ( v11 == v10 )
                  goto LABEL_9;
              }
              else if ( v11 > v7 || v10 <= v7 )
              {
LABEL_9:
                this->mpCachedSpawnSet = (UFG::qPropertySet *)v9->mChild[0];
                this->mCachedPopulationSetting = v9->mUID;
                return 1;
              }
            }
            else if ( v10 <= v7 && v7 < v11 )
            {
              goto LABEL_9;
            }
          }
        }
        ++v6;
        ++v9;
      }
      while ( v6 < mParent );
    }
    return 0;
  }
}

// File Line: 402
// RVA: 0x5B7660
void __fastcall UFG::SpawnRegion::UpdateSpawnSetAndDenisty(UFG::SpawnRegion *this, int game_hour)
{
  UFG::SceneObjectProperties *mpSceneObjProps; // rax
  UFG::qPropertySet *mpWritableProperties; // rcx
  UFG::qPropertySet *v6; // rax
  unsigned int v7; // edi
  char *MemImagePtr; // rax
  UFG::qBaseTreeRB *v9; // rax
  unsigned int mParent; // r8d
  UFG::qBaseNodeRB *v11; // rdx
  int v12; // eax
  int v13; // ecx
  int mUID; // edi
  UFG::qPropertySet *v15; // rbx
  UFG::PedSpawnManager *Instance; // rax
  UFG::PedSpawnManager *v17; // rax
  UFG::qSymbol timeSetName; // [rsp+30h] [rbp+8h] BYREF

  mpSceneObjProps = this->mpSceneObjProps;
  mpWritableProperties = mpSceneObjProps->mpWritableProperties;
  if ( !mpWritableProperties )
    mpWritableProperties = mpSceneObjProps->mpConstProperties;
  v6 = UFG::qPropertySet::Get<UFG::qPropertySet>(
         mpWritableProperties,
         (UFG::qArray<unsigned long,0> *)&component_SpawnRegion::sPropertyName,
         DEPTH_RECURSE);
  v7 = 0;
  if ( v6 )
    MemImagePtr = UFG::qPropertySet::GetMemImagePtr(v6);
  else
    MemImagePtr = 0i64;
  timeSetName.mUID = *((_DWORD *)MemImagePtr + 3);
  if ( timeSetName.mUID != UFG::gNullQSymbol.mUID && game_hour != this->mGameHourWhenSpawnSetWasCached )
  {
    v9 = UFG::TimeSetCache::ObtainTimeSet(&UFG::gTimeSetCache, &timeSetName);
    this->mGameHourWhenSpawnSetWasCached = game_hour;
    mParent = (unsigned int)v9->mNULL.mParent;
    if ( mParent )
    {
      v11 = v9->mNULL.mChild[0];
      do
      {
        v12 = (int)v11->mChild[1];
        if ( v12 != -1 )
        {
          v13 = HIDWORD(v11->mChild[1]);
          if ( v13 != -1 )
          {
            if ( v13 <= v12 )
            {
              if ( v13 >= v12 )
              {
                if ( v13 == v12 )
                  goto LABEL_15;
              }
              else if ( v13 > game_hour || v12 <= game_hour )
              {
LABEL_15:
                mUID = v11->mUID;
                v15 = (UFG::qPropertySet *)v11->mChild[0];
                if ( mUID != this->mCachedPopulationSetting || v15 != this->mpCachedSpawnSet )
                {
                  Instance = UFG::PedSpawnManager::GetInstance();
                  UFG::PedSpawnManager::UnRegisterActiveSpawnRegion(Instance, this);
                  this->mpCachedSpawnSet = v15;
                  this->mCachedPopulationSetting = mUID;
                  v17 = UFG::PedSpawnManager::GetInstance();
                  UFG::PedSpawnManager::UpdateActiveSpawnRegion(v17, this, 0);
                  UFG::PedSpawnManager::msShouldUpdatePopulationStats = 1;
                }
                return;
              }
            }
            else if ( v12 <= game_hour && game_hour < v13 )
            {
              goto LABEL_15;
            }
          }
        }
        ++v7;
        ++v11;
      }
      while ( v7 < mParent );
    }
  }
}

// File Line: 461
// RVA: 0x5B5410
UFG::SpawnRegion *__fastcall UFG::SpawnRegion::PropertiesOnActivateNew(
        UFG::SceneObjectProperties *pSceneObj,
        bool required)
{
  UFG::qPropertySet *mpWritableProperties; // rcx
  UFG::qPropertySet *v5; // rax
  component_SpawnRegion *MemImagePtr; // rbp
  UFG::qMemoryPool *SimulationMemoryPool; // rax
  UFG::allocator::free_link *v9; // r14
  UFG::SimObject *m_pSimObject; // rbx
  UFG::qSymbol *v11; // rax
  UFG::SpawnRegion *v12; // rax
  UFG::SpawnRegion *v13; // rbx
  UFG::PedSpawnManager *Instance; // rax
  UFG::qSymbol result; // [rsp+60h] [rbp+8h] BYREF
  UFG::allocator::free_link *v16; // [rsp+70h] [rbp+18h]

  mpWritableProperties = pSceneObj->mpWritableProperties;
  if ( !mpWritableProperties )
    mpWritableProperties = pSceneObj->mpConstProperties;
  v5 = UFG::qPropertySet::Get<UFG::qPropertySet>(
         mpWritableProperties,
         (UFG::qArray<unsigned long,0> *)&component_SpawnRegion::sPropertyName,
         DEPTH_RECURSE);
  if ( v5 )
  {
    MemImagePtr = (component_SpawnRegion *)UFG::qPropertySet::GetMemImagePtr(v5);
    if ( MemImagePtr )
      goto LABEL_9;
  }
  else
  {
    MemImagePtr = 0i64;
  }
  if ( !required )
    return 0i64;
LABEL_9:
  SimulationMemoryPool = UFG::GetSimulationMemoryPool();
  v9 = UFG::qMemoryPool::Allocate(SimulationMemoryPool, 0x188ui64, "SpawnRegion", 0i64, 1u);
  v16 = v9;
  if ( v9 )
  {
    m_pSimObject = pSceneObj->m_pSimObject;
    v11 = (UFG::qSymbol *)UFG::SceneObjectProperties::operator UFG::qSymbol const(
                            pSceneObj,
                            (UFG::qWiseSymbol *)&result);
    UFG::SpawnRegion::SpawnRegion((UFG::SpawnRegion *)v9, v11, m_pSimObject);
    v13 = v12;
  }
  else
  {
    v13 = 0i64;
  }
  if ( UFG::SpawnRegion::msAllowSpawn )
  {
    UFG::SpawnRegion::TransformBoundingBox(v13);
    v13->mIsThugRegion = MemImagePtr->ThugRegion;
    if ( UFG::SpawnRegion::CacheSpawnSetandDensity(v13, MemImagePtr) )
    {
      Instance = UFG::PedSpawnManager::GetInstance();
      UFG::PedSpawnManager::RegisterActiveSpawnRegion(Instance, v13, pSceneObj);
    }
  }
  return v13;
}

// File Line: 498
// RVA: 0x5B7500
void __fastcall UFG::SpawnRegion::TransformBoundingBox(UFG::SpawnRegion *this)
{
  UFG::TransformNodeComponent *mpXformNode; // rbx
  UFG::qBox *mRawAABB; // r8
  UFG::qMatrix44 *p_mWorldTransform; // rax
  UFG::TransformNodeComponent *v5; // rbx
  float z; // xmm1_4
  float y; // xmm0_4
  float v8; // xmm1_4

  mpXformNode = this->mpXformNode;
  this->mRawAABB = (UFG::qBox *)&this->mpRegion->mpRegion.mPtr[1];
  UFG::TransformNodeComponent::UpdateWorldTransform(mpXformNode);
  mRawAABB = this->mRawAABB;
  p_mWorldTransform = &mpXformNode->mWorldTransform;
  v5 = this->mpXformNode;
  this->mWorldXForm = p_mWorldTransform;
  *(float *)&p_mWorldTransform = mRawAABB->mMin.x;
  z = mRawAABB->mMin.z;
  this->mAABBOnActivate.mMin.y = mRawAABB->mMin.y;
  this->mAABBOnActivate.mMin.z = z;
  LODWORD(this->mAABBOnActivate.mMin.x) = (_DWORD)p_mWorldTransform;
  y = mRawAABB->mMax.y;
  v8 = mRawAABB->mMax.z;
  this->mAABBOnActivate.mMax.x = mRawAABB->mMax.x;
  this->mAABBOnActivate.mMax.y = y;
  this->mAABBOnActivate.mMax.z = v8;
  UFG::TransformNodeComponent::UpdateWorldTransform(v5);
  TransformAABB(&v5->mWorldTransform, &this->mAABBOnActivate.mMin, &this->mAABBOnActivate.mMax);
  UFG::qInverseAffine(&this->mWorldToLocal, this->mWorldXForm);
}

// File Line: 524
// RVA: 0x5B3AB0
UFG::GridIntrusiveNodesArray<UFG::InterestPoint> *__fastcall UFG::SpawnRegion::GetNearbyInterestPoints(
        UFG::SpawnRegion *this)
{
  float y; // xmm7_4
  float x; // xmm6_4
  __m128 x_low; // xmm1
  float v5; // xmm8_4
  float v6; // xmm6_4
  float v7; // xmm7_4
  UFG::GridIntrusiveNodesArray<UFG::InterestPoint> *v8; // r8
  UFG::GridIntrusive<UFG::InterestPoint> *v9; // r9
  float mGridSizeInv; // xmm2_4
  int v11; // ebx
  int v12; // r11d
  int mXDim; // ecx
  int v14; // r10d
  int v15; // edi
  int mYDim; // ecx
  int i; // edx

  if ( this->mpNearbyIntestPoints )
    return this->mpNearbyIntestPoints;
  y = this->mAABBOnActivate.mMin.y;
  x = this->mAABBOnActivate.mMin.x;
  x_low = (__m128)LODWORD(this->mAABBOnActivate.mMax.x);
  x_low.m128_f32[0] = (float)((float)((float)(x_low.m128_f32[0] - x) * (float)(x_low.m128_f32[0] - x))
                            + (float)((float)(this->mAABBOnActivate.mMax.y - y)
                                    * (float)(this->mAABBOnActivate.mMax.y - y)))
                    + (float)((float)(this->mAABBOnActivate.mMax.z - this->mAABBOnActivate.mMin.z)
                            * (float)(this->mAABBOnActivate.mMax.z - this->mAABBOnActivate.mMin.z));
  v5 = _mm_sqrt_ps(x_low).m128_f32[0] * 0.5;
  v6 = (float)(x + this->mAABBOnActivate.mMax.x) * 0.5;
  v7 = (float)(y + this->mAABBOnActivate.mMax.y) * 0.5;
  v8 = (UFG::GridIntrusiveNodesArray<UFG::InterestPoint> *)UFG::qMalloc(0xD0ui64, "InterestPoints Nearby", 0i64);
  if ( v8 )
  {
    v9 = UFG::InterestPoint::mspUseInterestPointGrid;
    mGridSizeInv = UFG::InterestPoint::mspUseInterestPointGrid->mGridSizeInv;
    v11 = (int)(float)((float)((float)(v6 - v5) - UFG::InterestPoint::mspUseInterestPointGrid->mXMin) * mGridSizeInv);
    if ( v11 < 0 )
      v11 = 0;
    v12 = (int)(float)((float)((float)(v6 + v5) - UFG::InterestPoint::mspUseInterestPointGrid->mXMin) * mGridSizeInv);
    mXDim = UFG::InterestPoint::mspUseInterestPointGrid->mXDim;
    if ( v12 >= mXDim )
      v12 = mXDim - 1;
    v14 = (int)(float)((float)((float)(v7 - v5) - UFG::InterestPoint::mspUseInterestPointGrid->mYMin) * mGridSizeInv);
    if ( v14 < 0 )
      v14 = 0;
    v15 = (int)(float)((float)((float)(v7 + v5) - UFG::InterestPoint::mspUseInterestPointGrid->mYMin) * mGridSizeInv);
    mYDim = UFG::InterestPoint::mspUseInterestPointGrid->mYDim;
    if ( v15 >= mYDim )
      v15 = mYDim - 1;
    for ( v8->mNumValidNodes = 0; v14 <= v15; ++v14 )
    {
      for ( i = v11; i <= v12; ++i )
        v8->mGridNodeArray[v8->mNumValidNodes++] = &v9->mGridNodes[i + v9->mXDim * v14];
    }
  }
  else
  {
    v8 = 0i64;
  }
  this->mpNearbyIntestPoints = v8;
  return v8;
}

// File Line: 540
// RVA: 0x5B2BD0
bool __fastcall UFG::SpawnRegion::CalcSpawnPoint(UFG::SpawnRegion *this, UFG::qVector3 *pos)
{
  UFG::qVector3 *RandomPosition; // rax
  float z; // xmm2_4
  float y; // xmm1_4
  float x; // xmm0_4
  float v7; // xmm1_4
  bool v8; // al
  float v9; // xmm0_4
  UFG::qVector3 rayStart; // [rsp+20h] [rbp-E0h] BYREF
  UFG::qVector3 rayEnd; // [rsp+30h] [rbp-D0h] BYREF
  UFG::qVector3 result; // [rsp+40h] [rbp-C0h] BYREF
  UFG::RayCastData data; // [rsp+50h] [rbp-B0h] BYREF

  RandomPosition = UFG::RegionComponent::GetRandomPosition(this->mpRegion, &result);
  z = RandomPosition->z;
  y = RandomPosition->y;
  *(float *)&RandomPosition = RandomPosition->x;
  data.mInput.m_enableShapeCollectionFilter.m_bool = 0;
  data.mOutput.m_hitFraction = 1.0;
  pos->y = y;
  rayStart.y = y;
  rayEnd.y = y;
  LODWORD(pos->x) = (_DWORD)RandomPosition;
  data.mOutput.m_extraInfo = -1;
  pos->z = z;
  data.mInput.m_filterInfo = 0;
  data.mInput.m_userData = 0i64;
  data.mOutput.m_shapeKeyIndex = 0;
  x = pos->x;
  rayStart.z = z + 1.0;
  rayEnd.z = z - 2.0;
  data.mOutput.m_rootCollidable = 0i64;
  data.mOutput.m_shapeKeys[0] = -1;
  rayStart.x = x;
  rayEnd.x = x;
  data.mDebugName = "CalcSpawnPoint";
  data.mCollisionModelName.mUID = -1;
  UFG::RayCastData::Init(&data, &rayStart, &rayEnd, 0xCu);
  if ( !UFG::BasePhysicsSystem::CastRay(UFG::BasePhysicsSystem::mInstance, &data) )
    return 0;
  v7 = data.point.y;
  v8 = 1;
  pos->x = data.point.x;
  v9 = data.point.z;
  pos->y = v7;
  pos->z = v9;
  return v8;
}

// File Line: 572
// RVA: 0x5B36E0
UFG::InterestPoint *__fastcall UFG::SpawnRegion::GetInterestPoint(
        UFG::SpawnRegion *this,
        UFG::qVector3 *spawnPos,
        UFG::PropertySetManager *properties_that_must_match,
        int which_rank_to_get,
        UFG::SimObjectCharacter *pSpawnedSimObj)
{
  int v5; // ebx
  UFG::GridIntrusiveNodesArray<UFG::InterestPoint> *NearbyInterestPoints; // rdx
  unsigned int v10; // eax
  __int64 i; // rdi
  UFG::qList<UFG::InterestPoint,UFG::InterestPoint,1,0> *v12; // rax
  UFG::qNode<UFG::InterestPoint,UFG::InterestPoint> **p_mNext; // r12
  UFG::InterestPoint *v14; // rbx
  __int64 v15; // rsi
  UFG::qVector3 *Position; // rax
  float x; // xmm6_4
  float y; // xmm3_4
  float z; // xmm2_4
  UFG::qBox *mRawAABB; // rax
  float v21; // xmm5_4
  float v22; // xmm4_4
  float v23; // xmm3_4
  float RawAppeal; // xmm0_4
  __int64 v25; // rdx
  float *v26; // rax
  __int64 *v27; // r8
  __int64 v28; // r9
  __int64 v29; // rax
  __int64 v30; // rdx
  UFG::InterestPoint *v31; // rbx
  UFG::qVector3 *v32; // rax
  float v33; // xmm0_4
  float v34; // xmm1_4
  UFG::InterestPoint *result; // rax
  UFG::InterestPoint *v36[2]; // [rsp+20h] [rbp-D8h]
  __int64 v37; // [rsp+30h] [rbp-C8h] BYREF
  int v38[2]; // [rsp+38h] [rbp-C0h] BYREF
  __int64 v39; // [rsp+40h] [rbp-B8h]
  int v40; // [rsp+48h] [rbp-B0h]
  __int64 v41; // [rsp+50h] [rbp-A8h]
  int v42; // [rsp+58h] [rbp-A0h]
  __int64 v43; // [rsp+60h] [rbp-98h]
  int v44; // [rsp+68h] [rbp-90h]
  __int64 v45; // [rsp+70h] [rbp-88h]
  int v46; // [rsp+78h] [rbp-80h]
  __int64 v47; // [rsp+80h] [rbp-78h]
  int v48; // [rsp+88h] [rbp-70h]
  __int64 v49; // [rsp+90h] [rbp-68h]
  int v50; // [rsp+98h] [rbp-60h]
  unsigned int v51; // [rsp+118h] [rbp+20h]

  v37 = 0i64;
  v38[0] = 0;
  v39 = 0i64;
  v40 = 0;
  v41 = 0i64;
  v42 = 0;
  v43 = 0i64;
  v44 = 0;
  v45 = 0i64;
  v5 = 7;
  v46 = 0;
  v47 = 0i64;
  v48 = 0;
  v49 = 0i64;
  v50 = 0;
  if ( which_rank_to_get <= 7 )
    v5 = which_rank_to_get;
  NearbyInterestPoints = UFG::SpawnRegion::GetNearbyInterestPoints(this);
  v36[0] = (UFG::InterestPoint *)NearbyInterestPoints;
  v10 = 0;
  v51 = 0;
  for ( i = v5; v10 < NearbyInterestPoints->mNumValidNodes; v51 = v10 )
  {
    v12 = NearbyInterestPoints->mGridNodeArray[v10];
    p_mNext = &v12[-12].mNode.mNext;
    v14 = (UFG::InterestPoint *)&v12->mNode.mNext[-12].mNext;
    if ( v14 != (UFG::InterestPoint *)&v12[-12].mNode.mNext )
    {
      do
      {
        v15 = (__int64)&v14->UFG::GridIntrusiveNode<UFG::InterestPoint>::UFG::qNode<UFG::InterestPoint,UFG::InterestPoint>::mNext[-12].mNext;
        if ( v14->mActive )
        {
          if ( !v14->mLinkObject.m_pPointer )
          {
            Position = UFG::InterestPoint::GetPosition(v14);
            x = Position->x;
            y = Position->y;
            if ( (float)((float)((float)(spawnPos->y - y) * (float)(spawnPos->y - y))
                       + (float)((float)(spawnPos->x - x) * (float)(spawnPos->x - x))) < 16.0 )
            {
              z = Position->z;
              mRawAABB = this->mRawAABB;
              v21 = (float)((float)((float)(y * this->mWorldToLocal.v1.x) + (float)(x * this->mWorldToLocal.v0.x))
                          + (float)(z * this->mWorldToLocal.v2.x))
                  + this->mWorldToLocal.v3.x;
              v22 = (float)((float)((float)(y * this->mWorldToLocal.v1.y) + (float)(x * this->mWorldToLocal.v0.y))
                          + (float)(z * this->mWorldToLocal.v2.y))
                  + this->mWorldToLocal.v3.y;
              v23 = (float)((float)((float)(y * this->mWorldToLocal.v1.z) + (float)(x * this->mWorldToLocal.v0.z))
                          + (float)(z * this->mWorldToLocal.v2.z))
                  + this->mWorldToLocal.v3.z;
              if ( v21 >= mRawAABB->mMin.x
                && v21 <= mRawAABB->mMax.x
                && v22 >= mRawAABB->mMin.y
                && v22 <= mRawAABB->mMax.y
                && v23 >= (float)(mRawAABB->mMin.z - 0.15000001)
                && v23 <= (float)(mRawAABB->mMax.z + 0.15000001)
                && pSpawnedSimObj
                && UFG::InterestPoint::IsRelevantToCharacter(v14, pSpawnedSimObj, ReserveReason_none)
                && (!properties_that_must_match
                 || UFG::InterestPoint::IsRelevantToPropertySet(v14, properties_that_must_match)) )
              {
                RawAppeal = UFG::InterestPoint::GetRawAppeal(v14);
                v25 = 0i64;
                if ( i > 0 )
                {
                  v26 = (float *)v38;
                  while ( RawAppeal <= *v26 )
                  {
                    ++v25;
                    v26 += 4;
                    if ( v25 >= i )
                      goto LABEL_27;
                  }
                  if ( i - 1 > v25 )
                  {
                    v27 = &v37 + 2 * i - 2;
                    v28 = i - v25 - 1;
                    do
                    {
                      v29 = *(v27 - 2);
                      v27 -= 2;
                      v27[2] = v29;
                      v27[3] = v27[1];
                      --v28;
                    }
                    while ( v28 );
                  }
                  v30 = 2 * v25;
                  *(float *)&v38[2 * v30] = RawAppeal;
                  *(_QWORD *)&v38[2 * v30 - 2] = v14;
                }
              }
            }
          }
        }
LABEL_27:
        v14 = (UFG::InterestPoint *)v15;
      }
      while ( (UFG::qNode<UFG::InterestPoint,UFG::InterestPoint> **)v15 != p_mNext );
      NearbyInterestPoints = (UFG::GridIntrusiveNodesArray<UFG::InterestPoint> *)v36[0];
    }
    v10 = v51 + 1;
  }
  v31 = v36[2 * i];
  if ( !v31 )
    return 0i64;
  v32 = UFG::InterestPoint::GetPosition(v31);
  v33 = v32->y;
  v34 = v32->z;
  spawnPos->x = v32->x;
  result = v31;
  spawnPos->y = v33;
  spawnPos->z = v34;
  return result;
}

// File Line: 670
// RVA: 0x5B4040
UFG::qPropertySet *__fastcall UFG::SpawnRegion::GetSpawnableResource(
        UFG::SpawnRegion *this,
        bool includeRareCharacters,
        UFG::qVector3 *preDeterminedPosition)
{
  UFG::qPropertySet *RareSpawn; // rax
  UFG::qPropertySet *mpCachedSpawnSet; // r14
  UFG::qPropertyList *v6; // rbp
  unsigned int mNumElements; // esi
  UFG::qPropertyList *v8; // rbx
  unsigned int RandomIndex; // eax
  UFG::qSymbol *v10; // rax
  UFG::qPropertySet *PropertySet; // rax
  UFG::qPropertySet *v12; // rdi
  UFG::ObjectResourceManager *v13; // rax
  UFG::qSymbol result; // [rsp+48h] [rbp+10h] BYREF

  if ( !includeRareCharacters || (RareSpawn = UFG::SpawnRegion::GetRareSpawn(this, preDeterminedPosition)) == 0i64 )
  {
    mpCachedSpawnSet = this->mpCachedSpawnSet;
    if ( UFG::gUseDebugSpawnset )
    {
      UFG::qSymbol::create_from_string(&result, "default-spawnset-debug");
      mpCachedSpawnSet = UFG::PropertySetManager::GetPropertySet(&result);
    }
    v6 = UFG::qPropertySet::Get<UFG::qPropertyList>(
           mpCachedSpawnSet,
           (UFG::qArray<unsigned long,0> *)&qSymbol_SpawnSet,
           DEPTH_RECURSE);
    mNumElements = v6->mNumElements;
    while ( 1 )
    {
      v8 = v6;
      do
      {
        RandomIndex = UFG::qPropertyList::GetRandomIndex(v8);
        v10 = UFG::qPropertyList::Get<UFG::qSymbol>(v8, RandomIndex);
        PropertySet = UFG::PropertySetManager::FindPropertySet(v10);
        v12 = PropertySet;
        if ( PropertySet )
          v8 = UFG::qPropertySet::Get<UFG::qPropertyList>(
                 PropertySet,
                 (UFG::qArray<unsigned long,0> *)&qSymbol_SpawnSet,
                 DEPTH_RECURSE);
      }
      while ( v8 );
      if ( !v12 )
        v12 = mpCachedSpawnSet;
      v13 = UFG::ObjectResourceManager::Instance();
      if ( UFG::ObjectResourceManager::CanSpawnAmbient(v13, v12, 0i64, 0) )
        break;
      if ( (int)--mNumElements <= 0 )
        return 0i64;
    }
    return v12;
  }
  return RareSpawn;
}

// File Line: 688
// RVA: 0x5B3C90
UFG::qPropertySet *__fastcall UFG::SpawnRegion::GetRareSpawn(
        UFG::SpawnRegion *this,
        UFG::qVector3 *preDeterminedPosition)
{
  UFG::ObjectResourceManager *v4; // rsi
  UFG::qPropertySet *PropertySet; // rax
  UFG::qPropertyList *v7; // rax
  __int64 v8; // rdi
  UFG::qPropertyList *v9; // r13
  unsigned int mNumElements; // r12d
  unsigned int i; // ebp
  char *ValuePtr; // rax
  UFG::qPropertySet *v13; // rcx
  unsigned int mUID; // ebx
  UFG::qSymbol *v15; // r14
  UFG::CopSystem *v16; // rax
  UFG::CopSystem *v17; // rax
  float *v18; // rax
  unsigned int size; // r9d
  unsigned int v20; // edx
  __int64 v21; // r8
  UFG::qSymbol result; // [rsp+70h] [rbp+18h] BYREF

  v4 = UFG::ObjectResourceManager::Instance();
  if ( UFG::EntityTypeState::GetSpawnableRareEntity(v4->mEntityStates)->mUID == UFG::gNullQSymbol.mUID )
    return 0i64;
  UFG::SpawnRegion::GetSpawnInfoName(this, &result);
  PropertySet = UFG::PropertySetManager::GetPropertySet(&result);
  v7 = UFG::qPropertySet::Get<UFG::qPropertyList>(
         PropertySet,
         (UFG::qArray<unsigned long,0> *)&qSymbol_RareSpawnList,
         DEPTH_RECURSE);
  v8 = 0i64;
  v9 = v7;
  if ( v7 )
  {
    mNumElements = v7->mNumElements;
    for ( i = 0; i < mNumElements; ++i )
    {
      ValuePtr = UFG::qPropertyList::GetValuePtr(v9, 0x1Au, i);
      if ( ValuePtr && *(_QWORD *)ValuePtr )
        v13 = (UFG::qPropertySet *)&ValuePtr[*(_QWORD *)ValuePtr];
      else
        v13 = 0i64;
      mUID = v13->mName.mUID;
      v15 = UFG::qPropertySet::Get<UFG::qSymbol>(
              v13,
              (UFG::qArray<unsigned long,0> *)&qSymbol_PropertySet,
              DEPTH_RECURSE);
      if ( mUID == qSymbol_Police.mUID )
      {
        v16 = UFG::CopSystem::Instance();
        if ( !UFG::CopSystem::AllowSpawnRegionSpawning(v16) )
          break;
        if ( preDeterminedPosition )
        {
          v17 = UFG::CopSystem::Instance();
          v18 = (float *)((__int64 (__fastcall *)(UFG::CopSystem *))v17->vfptr[20].__vecDelDtor)(v17);
          if ( (float)((float)((float)(v18[1] - preDeterminedPosition->y) * (float)(v18[1] - preDeterminedPosition->y))
                     + (float)((float)(*v18 - preDeterminedPosition->x) * (float)(*v18 - preDeterminedPosition->x))) < 7225.0 )
            break;
        }
      }
      size = v4->mEntityStates[0].mRareSpawnPropertySets.size;
      v20 = 0;
      if ( size )
      {
        v21 = 0i64;
        while ( !v4->mEntityStates[0].mRareSpawnIsReady.p[v20]
             || v4->mEntityStates[0].mRareSpawnPropertySets.p[v21].mUID != v15->mUID )
        {
          ++v20;
          ++v21;
          if ( v20 >= size )
            goto LABEL_18;
        }
        UFG::EntityTypeState::RareEntitySpawned(v4->mEntityStates, v15);
        return UFG::PropertySetManager::GetPropertySet(v15);
      }
LABEL_18:
      ;
    }
  }
  return (UFG::qPropertySet *)v8;
}

// File Line: 746
// RVA: 0x5B4E70
bool __fastcall UFG::SpawnRegion::IsSheltered(UFG::SpawnRegion *this)
{
  UFG::SimObject *m_pSimObject; // rax
  UFG::SceneObjectProperties *m_pSceneObj; // rcx
  bool *v3; // rax

  m_pSimObject = this->m_pSimObject;
  if ( m_pSimObject )
    m_pSceneObj = m_pSimObject->m_pSceneObj;
  else
    m_pSceneObj = 0i64;
  v3 = PropertyUtils::Get<bool>(m_pSceneObj, (UFG::qArray<unsigned long,0> *)&qSymbol_Sheltered);
  return v3 && *v3;
}

// File Line: 755
// RVA: 0x5B4E30
__int64 __fastcall UFG::SpawnRegion::IsGroupsAllowed(UFG::SpawnRegion *this)
{
  UFG::SimObject *m_pSimObject; // rax
  UFG::SceneObjectProperties *m_pSceneObj; // rcx
  bool *v3; // rax

  m_pSimObject = this->m_pSimObject;
  if ( m_pSimObject )
    m_pSceneObj = m_pSimObject->m_pSceneObj;
  else
    m_pSceneObj = 0i64;
  v3 = PropertyUtils::Get<bool>(m_pSceneObj, (UFG::qArray<unsigned long,0> *)&qSymbol_AllowGroups);
  return !v3 || *v3;
}

// File Line: 761
// RVA: 0x5B42B0
UFG::qSymbol *__fastcall UFG::SpawnRegion::GetUniqueNewName(UFG::SpawnRegion *this, UFG::qSymbol *result)
{
  unsigned int mUID; // ebx
  UFG::OnlineManager *v4; // rax
  int OnlineIdStringHash32; // [rsp+20h] [rbp-48h]
  UFG::qString resulta; // [rsp+38h] [rbp-30h] BYREF

  ++GlobalRegionSpawnCount;
  mUID = this->i_name.mUID;
  v4 = UFG::OnlineManager::Instance();
  OnlineIdStringHash32 = UFG::OnlineManager::GetOnlineIdStringHash32(v4);
  UFG::qString::FormatEx(&resulta, "%x-%.3d-%d", mUID, (unsigned int)GlobalRegionSpawnCount, OnlineIdStringHash32);
  UFG::qSymbol::create_from_string(result, resulta.mData);
  UFG::qString::~qString(&resulta);
  return result;
}

// File Line: 796
// RVA: 0x5B6FB0
UFG::SimObjectGame *__fastcall UFG::SpawnRegion::Spawn(
        UFG::SpawnRegion *this,
        bool includeRareCharacters,
        UFG::qVector3 *preDeterminedPosition,
        const bool skip_teleport)
{
  UFG::Event *v7; // r13
  UFG::SimObjectGame *v8; // rbx
  UFG::qPropertySet *SpawnableResource; // r14
  UFG::ObjectResourceManager *v10; // rax
  bool v11; // al
  float y; // xmm1_4
  float z; // xmm2_4
  UFG::SceneObjectProperties *mpSceneObjProps; // rdi
  UFG::SceneObjectProperties *v15; // rbx
  UFG::PedSpawnManager *Instance; // rax
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl *GroupComponent; // rax
  bool v18; // dl
  UFG::TeleportEvent *v19; // rax
  UFG::Event *v20; // rax
  UFG::PedSpawnManager *v21; // rax
  UFG::qSymbol result; // [rsp+18h] [rbp-49h] BYREF
  UFG::qPropertySet *pParentPropertySet; // [rsp+20h] [rbp-41h]
  UFG::qVector3 pos; // [rsp+28h] [rbp-39h] BYREF
  UFG::qVector3 startPos; // [rsp+38h] [rbp-29h] BYREF
  UFG::qMatrix44 dest; // [rsp+48h] [rbp-19h] BYREF
  UFG::qPropertySet *retaddr; // [rsp+D8h] [rbp+77h]
  char v29; // [rsp+E0h] [rbp+7Fh]

  pParentPropertySet = (UFG::qPropertySet *)-2i64;
  v7 = 0i64;
  v8 = 0i64;
  SpawnableResource = retaddr;
  if ( !retaddr )
  {
    SpawnableResource = UFG::SpawnRegion::GetSpawnableResource(this, includeRareCharacters, preDeterminedPosition);
    if ( !SpawnableResource )
      return 0i64;
  }
  v10 = UFG::ObjectResourceManager::Instance();
  if ( !UFG::ObjectResourceManager::CanSpawnAmbient(v10, SpawnableResource, 0i64, 0) )
    return 0i64;
  v11 = 1;
  if ( preDeterminedPosition )
  {
    y = preDeterminedPosition->y;
    z = preDeterminedPosition->z;
    pos.x = preDeterminedPosition->x;
    pos.y = y;
    pos.z = z;
  }
  else
  {
    v11 = UFG::SpawnRegion::CalcSpawnPoint(this, &pos);
  }
  if ( skip_teleport
    || v11
    && (UFG::gOmitMeshCheck
     || ((unsigned __int8 (__fastcall *)(UFG::NavManager *, UFG::qVector3 *))UFG::NavManager::ms_pInstance->vfptr->IsInsideAIMesh)(
          UFG::NavManager::ms_pInstance,
          &pos)) )
  {
    UFG::SpawnRegion::GetUniqueNewName(this, &result);
    mpSceneObjProps = this->mpSceneObjProps;
    v15 = UFG::SceneObjectProperties::Create(&result, 0i64, SpawnableResource);
    PropertyUtils::SetRuntime<UFG::qSymbol>(v15, (UFG::qArray<unsigned long,0> *)&qSymbol_SpawnPriority, &qSymbol_Low);
    v8 = (UFG::SimObjectGame *)UFG::SpawnInfoInterface::ActivateObject(
                                 v15,
                                 High,
                                 0i64,
                                 mpSceneObjProps,
                                 SpawnableResource,
                                 3u,
                                 0);
    UFG::TransformNodeComponent::SetParentKeepWorld(
      (UFG::TransformNodeComponent *)v8->m_Components.p[2].m_pComponent,
      0i64,
      eInheritXform_Full);
    LOBYTE(retaddr) = UFG::SpawnRegion::IsGroupsAllowed(this);
    if ( !(_BYTE)retaddr || skip_teleport || v29 )
    {
      GroupComponent = UFG::GroupComponent::GetGroupComponent(v8);
      if ( GroupComponent )
      {
        v18 = (_BYTE)retaddr && !v29;
        UFG::GroupComponent::MakeSingle((UFG::GroupComponent *)GroupComponent, v18);
      }
    }
    else
    {
      startPos = pos;
      Instance = UFG::PedSpawnManager::GetInstance();
      if ( UFG::PedSpawnManager::JoinGroup(Instance, v8, SpawnableResource, &startPos, this) )
        pos = startPos;
    }
    UFG::TSCharacter::EnableScriptControlOnSimObject(v8, 0);
    if ( !skip_teleport )
    {
      ARandom::c_gen.i_seed = 1664525 * ARandom::c_gen.i_seed + 1013904223;
      UFG::qRotationMatrixZ(&dest, (float)(COERCE_FLOAT((ARandom::c_gen.i_seed >> 9) | 0x3F800000) - 1.0) * 6.2831855);
      dest.v3.x = pos.x;
      dest.v3.y = pos.y;
      dest.v3.z = pos.z;
      dest.v3.w = 1.0;
      v19 = (UFG::TeleportEvent *)UFG::qMalloc(0x90ui64, "TeleportEvent", 0i64);
      retaddr = (UFG::qPropertySet *)v19;
      if ( v19 )
      {
        UFG::TeleportEvent::TeleportEvent(v19, &dest, v8->mNode.mUID, 0, UFG::TeleportEvent::m_Name, 0);
        v7 = v20;
      }
      UFG::EventDispatcher::DispatchEvent(&UFG::EventDispatcher::mInstance, v7);
      if ( preDeterminedPosition )
        *preDeterminedPosition = pos;
    }
    v21 = UFG::PedSpawnManager::GetInstance();
    UFG::PedSpawnManager::SetStartMode(v21, v8, SpawnableResource, &pos);
  }
  return v8;
}

// File Line: 934
// RVA: 0x5B5120
void __fastcall UFG::SpawnRegion::OnDetach(UFG::SpawnRegion *this)
{
  UFG::PedSpawnManager *Instance; // rax
  UFG::GridIntrusiveNodesArray<UFG::InterestPoint> *mpNearbyIntestPoints; // rcx

  Instance = UFG::PedSpawnManager::GetInstance();
  UFG::PedSpawnManager::UnRegisterActiveSpawnRegion(Instance, this);
  mpNearbyIntestPoints = this->mpNearbyIntestPoints;
  if ( mpNearbyIntestPoints )
  {
    operator delete[](mpNearbyIntestPoints);
    this->mpNearbyIntestPoints = 0i64;
  }
}

// File Line: 948
// RVA: 0x5B2A90
void __fastcall UFG::SpawnRegion::AddZone(UFG::SpawnRegion *this, UFG::SpawnZone *spawnZone)
{
  UFG::qNode<UFG::SpawnZone,UFG::SpawnRegionList> *v2; // rdx
  UFG::qList<UFG::SpawnZone,UFG::SpawnRegionList,1,0> *p_mZones; // rcx
  UFG::qNode<UFG::SpawnZone,UFG::SpawnRegionList> *mPrev; // rax

  v2 = &spawnZone->UFG::qNode<UFG::SpawnZone,UFG::SpawnRegionList>;
  p_mZones = &this->mZones;
  mPrev = p_mZones->mNode.mPrev;
  mPrev->mNext = v2;
  v2->mPrev = mPrev;
  v2->mNext = &p_mZones->mNode;
  p_mZones->mNode.mPrev = v2;
}

// File Line: 958
// RVA: 0x5B3E80
UFG::qSymbol *__fastcall UFG::SpawnRegion::GetSpawnInfoName(UFG::SpawnRegion *this, UFG::qSymbol *result)
{
  UFG::SceneObjectProperties *mpSceneObjProps; // rax
  UFG::qPropertySet *mpWritableProperties; // rcx
  UFG::qPropertySet *v5; // rax

  mpSceneObjProps = this->mpSceneObjProps;
  mpWritableProperties = mpSceneObjProps->mpWritableProperties;
  if ( !mpWritableProperties )
    mpWritableProperties = mpSceneObjProps->mpConstProperties;
  v5 = UFG::qPropertySet::Get<UFG::qPropertySet>(
         mpWritableProperties,
         (UFG::qArray<unsigned long,0> *)&component_SpawnRegion::sPropertyName,
         DEPTH_RECURSE);
  if ( v5 )
    result->mUID = *(_DWORD *)(UFG::qPropertySet::GetMemImagePtr(v5) + 4);
  else
    result->mUID = MEMORY[4];
  return result;
}

