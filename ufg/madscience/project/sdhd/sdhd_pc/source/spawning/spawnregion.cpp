// File Line: 91
// RVA: 0x5B42A0
signed __int64 __fastcall UFG::SpawnRegion::GetTypeSize(UFG::SpawnRegion *this)
{
  return 392i64;
}

// File Line: 111
// RVA: 0x5B1980
void __fastcall UFG::SpawnRegion::SpawnRegion(UFG::SpawnRegion *this, UFG::qSymbol *name, UFG::SimObject *pSimObj)
{
  UFG::SimObject *v3; // rdi
  UFG::SpawnRegion *v4; // rsi
  UFG::qList<UFG::SpawnZone,UFG::SpawnRegionList,1,0> *v5; // [rsp+58h] [rbp+20h]

  v3 = pSimObj;
  v4 = this;
  UFG::MarkerBase::MarkerBase((UFG::MarkerBase *)&this->vfptr, name, pSimObj, 0x30000u);
  v4->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::SpawnPointInterface::`vftable;
  UFG::qSafePointerNodeWithCallbacks<UFG::SpawnRegion>::qSafePointerNodeWithCallbacks<UFG::SpawnRegion>((UFG::qSafePointerNodeWithCallbacks<UFG::SpawnRegion> *)&v4->vfptr);
  v4->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::SpawnRegion::`vftable{for `UFG::SpawnPointInterface};
  v4->vfptr = (UFG::qSafePointerNode<UFG::SpawnRegion>Vtbl *)&UFG::SpawnRegion::`vftable{for `UFG::qSafePointerNodeWithCallbacks<UFG::SpawnRegion>};
  *(_QWORD *)&v4->mAABBOnActivate.mMin.x = 0i64;
  *(_QWORD *)&v4->mAABBOnActivate.mMin.z = 0i64;
  *(_QWORD *)&v4->mAABBOnActivate.mMax.y = 0i64;
  v5 = &v4->mZones;
  v5->mNode.mPrev = &v5->mNode;
  v5->mNode.mNext = &v5->mNode;
  v4->mpNearbyIntestPoints = 0i64;
  v4->mCanPathTo = 3;
  UFG::SimComponent::AddType((UFG::SimComponent *)&v4->vfptr, UFG::SpawnRegion::_SpawnRegionTypeUID, "SpawnRegion");
  UFG::SpawnRegion::Initialize(v4, v3);
}

// File Line: 122
// RVA: 0x5B4B30
void __fastcall UFG::SpawnRegion::Initialize(UFG::SpawnRegion *this, UFG::SimObject *pSimObj)
{
  UFG::SpawnRegion *v2; // rbx
  UFG::SimComponent *v3; // rax
  unsigned __int16 v4; // cx
  UFG::SimObject *v5; // rax
  UFG::SceneObjectProperties *v6; // rax

  v2 = this;
  if ( pSimObj )
  {
    v4 = pSimObj->m_Flags;
    if ( (v4 >> 14) & 1 )
    {
      v3 = UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)pSimObj, UFG::RegionComponent::_TypeUID);
    }
    else if ( (v4 & 0x8000u) == 0 )
    {
      if ( (v4 >> 13) & 1 )
      {
        v3 = UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)pSimObj, UFG::RegionComponent::_TypeUID);
      }
      else if ( (v4 >> 12) & 1 )
      {
        v3 = UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)pSimObj, UFG::RegionComponent::_TypeUID);
      }
      else
      {
        v3 = UFG::SimObject::GetComponentOfType(pSimObj, UFG::RegionComponent::_TypeUID);
      }
    }
    else
    {
      v3 = UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)pSimObj, UFG::RegionComponent::_TypeUID);
    }
  }
  else
  {
    v3 = 0i64;
  }
  v2->mpRegion = (UFG::RegionComponent *)v3;
  v5 = v2->m_pSimObject;
  v2->mpNearbyIntestPoints = 0i64;
  if ( v5 )
  {
    v6 = v5->m_pSceneObj;
    v2->mIndexOfLastSpawned = 0;
    v2->mpSceneObjProps = v6;
  }
  else
  {
    v2->mpSceneObjProps = 0i64;
    v2->mIndexOfLastSpawned = 0;
  }
}

// File Line: 179
// RVA: 0x5B1E90
void __fastcall UFG::SpawnRegion::~SpawnRegion(UFG::SpawnRegion *this)
{
  UFG::SpawnRegion *v1; // rdi
  UFG::qList<SimObjectFlagSetTask,SimObjectFlagSetList,1,0> *v2; // rbx
  UFG::SpawnZone *v3; // rcx
  UFG::qNode<UFG::SpawnZone,UFG::SpawnRegionList> *v4; // r8
  UFG::qNode<UFG::SpawnZone,UFG::SpawnRegionList> *v5; // rdx
  UFG::qNode<UFG::SpawnZone,UFG::SpawnRegionList> *v6; // rax
  UFG::qNode<SimObjectFlagSetTask,SimObjectFlagSetList> *v7; // rdx
  UFG::qNode<SimObjectFlagSetTask,SimObjectFlagSetList> *v8; // rax

  v1 = this;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::SpawnRegion::`vftable{for `UFG::SpawnPointInterface};
  this->vfptr = (UFG::qSafePointerNode<UFG::SpawnRegion>Vtbl *)&UFG::SpawnRegion::`vftable{for `UFG::qSafePointerNodeWithCallbacks<UFG::SpawnRegion>};
  v2 = (UFG::qList<SimObjectFlagSetTask,SimObjectFlagSetList,1,0> *)&this->mZones;
  if ( &this->mZones.mNode.mNext[-3].mNext != (UFG::qNode<UFG::SpawnZone,UFG::SpawnRegionList> **)&this->mWorldToLocal.v2.z )
  {
    do
    {
      v3 = (UFG::SpawnZone *)&v1->mZones.mNode.mNext[-3].mNext;
      v4 = v1->mZones.mNode.mNext;
      v5 = v1->mZones.mNode.mNext->mPrev;
      v6 = v3->mNext;
      v5->mNext = v6;
      v6->mPrev = v5;
      v4->mPrev = v4;
      v4->mNext = v4;
      UFG::PedSpawnManager::FreeSpawnZone(v3);
    }
    while ( &v2->mNode.mNext[-3].mNext != &v2[-3].mNode.mNext );
  }
  UFG::qList<SimObjectFlagSetTask,SimObjectFlagSetList,1,0>::DeleteNodes(v2);
  v7 = v2->mNode.mPrev;
  v8 = v2->mNode.mNext;
  v7->mNext = v8;
  v8->mPrev = v7;
  v2->mNode.mPrev = &v2->mNode;
  v2->mNode.mNext = &v2->mNode;
  UFG::qSafePointerNodeWithCallbacks<UFG::SpawnRegion>::~qSafePointerNodeWithCallbacks<UFG::SpawnRegion>((UFG::qSafePointerNodeWithCallbacks<UFG::SpawnRegion> *)&v1->vfptr);
  UFG::MarkerBase::~MarkerBase((UFG::MarkerBase *)&v1->vfptr);
}

// File Line: 265
// RVA: 0x5B41A0
float __fastcall UFG::SpawnRegion::GetTargetPopulationFromDensity(UFG::SpawnRegion::eDensity density, float area)
{
  switch ( density )
  {
    case 0xFFFFFFFB:
      return (float)(UFG::PedSpawnManager::msPedsPerSquareMetre * area) * 0.33000001;
    case 0xFFFFFFFC:
      return (float)(UFG::PedSpawnManager::msPedsPerSquareMetre * area) * 0.66000003;
    case 0xFFFFFFFE:
      return (float)(UFG::PedSpawnManager::msPedsPerSquareMetre * area) * 1.3;
    case 0xFFFFFFFF:
      return (float)(UFG::PedSpawnManager::msPedsPerSquareMetre * area) * 1.5;
  }
  return (float)(UFG::PedSpawnManager::msPedsPerSquareMetre * area) * 0.89999998;
}

// File Line: 297
// RVA: 0x5B4150
void __fastcall UFG::SpawnRegion::GetTargetPopulation(UFG::SpawnRegion *this, float subArea)
{
  int v2; // edx

  v2 = this->mCachedPopulationSetting;
  if ( v2 < 0 )
    UFG::SpawnRegion::GetTargetPopulationFromDensity((UFG::SpawnRegion::eDensity)v2, subArea);
  else
    (*((void (**)(void))&this->mpRegion->mpRegion.mPtr->vfptr->__vecDelDtor + 2))();
}

// File Line: 357
// RVA: 0x5B2AB0
bool __fastcall UFG::SpawnRegion::CacheSpawnSetandDensity(UFG::SpawnRegion *this, component_SpawnRegion *dataPtr)
{
  component_SpawnRegion *v2; // rbx
  UFG::SpawnRegion *v3; // rdi
  UFG::qBaseTreeRB *v4; // rbx
  UFG::TimeOfDayManager *v5; // rax
  unsigned int v6; // er9
  signed int v7; // er8
  unsigned int v8; // er10
  UFG::qBaseNodeRB *v9; // rdx
  signed int v10; // eax
  signed int v11; // ecx
  bool result; // al
  UFG::qPropertySet *v13; // rax
  signed int v14; // eax
  UFG::qSymbol timeSetName; // [rsp+38h] [rbp+10h]
  UFG::qSymbol propSetName; // [rsp+40h] [rbp+18h]

  v2 = dataPtr;
  v3 = this;
  timeSetName.mUID = dataPtr->TimeSet.mUID;
  if ( timeSetName.mUID == UFG::gNullQSymbol.mUID )
  {
    propSetName.mUID = dataPtr->SpawnInfo.mUID;
    v13 = UFG::PropertySetManager::GetPropertySet(&propSetName);
    v3->mGameHourWhenSpawnSetWasCached = -1;
    v3->mpCachedSpawnSet = v13;
    v14 = v2->SpawnPopulation;
    if ( v14 == -100 )
      v14 = -3;
    v3->mCachedPopulationSetting = v14;
    result = 1;
  }
  else
  {
    v4 = UFG::TimeSetCache::ObtainTimeSet(&UFG::gTimeSetCache, &timeSetName);
    v5 = UFG::TimeOfDayManager::GetInstance();
    v6 = 0;
    v7 = (signed int)(float)(v5->m_SecondsSinceMidnight * 0.00027777778);
    v3->mGameHourWhenSpawnSetWasCached = v7;
    v8 = (unsigned int)v4->mNULL.mParent;
    if ( v8 )
    {
      v9 = v4->mNULL.mChild[0];
      do
      {
        v10 = (signed int)v9->mChild[1];
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
                v3->mpCachedSpawnSet = (UFG::qPropertySet *)v9->mChild[0];
                v3->mCachedPopulationSetting = v9->mUID;
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
      while ( v6 < v8 );
    }
    result = 0;
  }
  return result;
}

// File Line: 402
// RVA: 0x5B7660
void __fastcall UFG::SpawnRegion::UpdateSpawnSetAndDenisty(UFG::SpawnRegion *this, int game_hour)
{
  UFG::SceneObjectProperties *v2; // rax
  UFG::SpawnRegion *v3; // rsi
  int v4; // ebx
  UFG::qPropertySet *v5; // rcx
  UFG::qPropertySet *v6; // rax
  unsigned int v7; // edi
  char *v8; // rax
  UFG::qBaseTreeRB *v9; // rax
  unsigned int v10; // er8
  UFG::qBaseNodeRB *v11; // rdx
  int v12; // eax
  int v13; // ecx
  int v14; // edi
  UFG::qPropertySet *v15; // rbx
  UFG::PedSpawnManager *v16; // rax
  UFG::PedSpawnManager *v17; // rax
  UFG::qSymbol timeSetName; // [rsp+30h] [rbp+8h]

  v2 = this->mpSceneObjProps;
  v3 = this;
  v4 = game_hour;
  v5 = v2->mpWritableProperties;
  if ( !v5 )
    v5 = v2->mpConstProperties;
  v6 = UFG::qPropertySet::Get<UFG::qPropertySet>(
         v5,
         (UFG::qSymbol *)&component_SpawnRegion::sPropertyName.mUID,
         DEPTH_RECURSE);
  v7 = 0;
  if ( v6 )
    v8 = UFG::qPropertySet::GetMemImagePtr(v6);
  else
    v8 = 0i64;
  timeSetName.mUID = *((_DWORD *)v8 + 3);
  if ( timeSetName.mUID != UFG::gNullQSymbol.mUID && v4 != v3->mGameHourWhenSpawnSetWasCached )
  {
    v9 = UFG::TimeSetCache::ObtainTimeSet(&UFG::gTimeSetCache, &timeSetName);
    v3->mGameHourWhenSpawnSetWasCached = v4;
    v10 = (unsigned int)v9->mNULL.mParent;
    if ( v10 )
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
              else if ( v13 > v4 || v12 <= v4 )
              {
LABEL_15:
                v14 = v11->mUID;
                v15 = (UFG::qPropertySet *)v11->mChild[0];
                if ( v14 != v3->mCachedPopulationSetting || v15 != v3->mpCachedSpawnSet )
                {
                  v16 = UFG::PedSpawnManager::GetInstance();
                  UFG::PedSpawnManager::UnRegisterActiveSpawnRegion(v16, v3);
                  v3->mpCachedSpawnSet = v15;
                  v3->mCachedPopulationSetting = v14;
                  v17 = UFG::PedSpawnManager::GetInstance();
                  UFG::PedSpawnManager::UpdateActiveSpawnRegion(v17, v3, 0);
                  UFG::PedSpawnManager::msShouldUpdatePopulationStats = 1;
                }
                return;
              }
            }
            else if ( v12 <= v4 && v4 < v13 )
            {
              goto LABEL_15;
            }
          }
        }
        ++v7;
        ++v11;
      }
      while ( v7 < v10 );
    }
  }
}

// File Line: 461
// RVA: 0x5B5410
UFG::SpawnRegion *__fastcall UFG::SpawnRegion::PropertiesOnActivateNew(UFG::SceneObjectProperties *pSceneObj, bool required)
{
  bool v2; // r14
  UFG::SceneObjectProperties *v3; // rsi
  UFG::qPropertySet *v4; // rcx
  UFG::qPropertySet *v5; // rax
  component_SpawnRegion *v6; // rbp
  UFG::qMemoryPool *v8; // rax
  UFG::allocator::free_link *v9; // r14
  UFG::SimObject *v10; // rbx
  UFG::qSymbol *v11; // rax
  UFG::SpawnRegion *v12; // rax
  UFG::SpawnRegion *v13; // rbx
  UFG::PedSpawnManager *v14; // rax
  UFG::qSymbol result; // [rsp+60h] [rbp+8h]
  UFG::allocator::free_link *v16; // [rsp+70h] [rbp+18h]

  v2 = required;
  v3 = pSceneObj;
  v4 = pSceneObj->mpWritableProperties;
  if ( !v4 )
    v4 = v3->mpConstProperties;
  v5 = UFG::qPropertySet::Get<UFG::qPropertySet>(
         v4,
         (UFG::qSymbol *)&component_SpawnRegion::sPropertyName.mUID,
         DEPTH_RECURSE);
  if ( v5 )
  {
    v6 = (component_SpawnRegion *)UFG::qPropertySet::GetMemImagePtr(v5);
    if ( v6 )
      goto LABEL_9;
  }
  else
  {
    v6 = 0i64;
  }
  if ( !v2 )
    return 0i64;
LABEL_9:
  v8 = UFG::GetSimulationMemoryPool();
  v9 = UFG::qMemoryPool::Allocate(v8, 0x188ui64, "SpawnRegion", 0i64, 1u);
  v16 = v9;
  if ( v9 )
  {
    v10 = v3->m_pSimObject;
    v11 = UFG::SceneObjectProperties::operator UFG::qSymbol const(v3, &result);
    UFG::SpawnRegion::SpawnRegion((UFG::SpawnRegion *)v9, v11, v10);
    v13 = v12;
  }
  else
  {
    v13 = 0i64;
  }
  if ( UFG::SpawnRegion::msAllowSpawn )
  {
    UFG::SpawnRegion::TransformBoundingBox(v13);
    v13->mIsThugRegion = v6->ThugRegion;
    if ( UFG::SpawnRegion::CacheSpawnSetandDensity(v13, v6) )
    {
      v14 = UFG::PedSpawnManager::GetInstance();
      UFG::PedSpawnManager::RegisterActiveSpawnRegion(v14, v13, v3);
    }
  }
  return v13;
}

// File Line: 498
// RVA: 0x5B7500
void __fastcall UFG::SpawnRegion::TransformBoundingBox(UFG::SpawnRegion *this)
{
  UFG::TransformNodeComponent *v1; // rbx
  UFG::SpawnRegion *v2; // rbp
  float *v3; // r8
  signed __int64 v4; // rax
  UFG::TransformNodeComponent *v5; // rbx
  float v6; // xmm1_4
  float v7; // xmm0_4
  float v8; // xmm1_4

  v1 = this->mpXformNode;
  v2 = this;
  this->mRawAABB = (UFG::qBox *)&this->mpRegion->mpRegion.mPtr[1];
  UFG::TransformNodeComponent::UpdateWorldTransform(v1);
  v3 = &v2->mRawAABB->mMin.x;
  v4 = (signed __int64)&v1->mWorldTransform;
  v5 = v2->mpXformNode;
  v2->mWorldXForm = (UFG::qMatrix44 *)v4;
  *(float *)&v4 = *v3;
  v6 = v3[2];
  v2->mAABBOnActivate.mMin.y = v3[1];
  v2->mAABBOnActivate.mMin.z = v6;
  LODWORD(v2->mAABBOnActivate.mMin.x) = v4;
  v7 = v3[4];
  v8 = v3[5];
  v2->mAABBOnActivate.mMax.x = v3[3];
  v2->mAABBOnActivate.mMax.y = v7;
  v2->mAABBOnActivate.mMax.z = v8;
  UFG::TransformNodeComponent::UpdateWorldTransform(v5);
  TransformAABB(&v5->mWorldTransform, &v2->mAABBOnActivate.mMin, &v2->mAABBOnActivate.mMax);
  UFG::qInverseAffine(&v2->mWorldToLocal, v2->mWorldXForm);
}

// File Line: 524
// RVA: 0x5B3AB0
UFG::allocator::free_link *__fastcall UFG::SpawnRegion::GetNearbyInterestPoints(UFG::SpawnRegion *this)
{
  UFG::SpawnRegion *v1; // rsi
  float v2; // xmm7_4
  float v3; // xmm6_4
  __m128 v4; // xmm1
  float v5; // xmm8_4
  float v6; // xmm6_4
  float v7; // xmm7_4
  UFG::allocator::free_link *v8; // r8
  UFG::GridIntrusive<UFG::InterestPoint> *v9; // r9
  float v10; // xmm2_4
  signed int v11; // ebx
  int v12; // er11
  int v13; // ecx
  signed int v14; // er10
  int v15; // edi
  int v16; // ecx
  int i; // edx

  v1 = this;
  if ( this->mpNearbyIntestPoints )
    return (UFG::allocator::free_link *)this->mpNearbyIntestPoints;
  v2 = this->mAABBOnActivate.mMin.y;
  v3 = this->mAABBOnActivate.mMin.x;
  v4 = (__m128)LODWORD(this->mAABBOnActivate.mMax.x);
  v4.m128_f32[0] = (float)((float)((float)(v4.m128_f32[0] - v3) * (float)(v4.m128_f32[0] - v3))
                         + (float)((float)(this->mAABBOnActivate.mMax.y - v2)
                                 * (float)(this->mAABBOnActivate.mMax.y - v2)))
                 + (float)((float)(this->mAABBOnActivate.mMax.z - this->mAABBOnActivate.mMin.z)
                         * (float)(this->mAABBOnActivate.mMax.z - this->mAABBOnActivate.mMin.z));
  v5 = COERCE_FLOAT(_mm_sqrt_ps(v4)) * 0.5;
  v6 = (float)(v3 + this->mAABBOnActivate.mMax.x) * 0.5;
  v7 = (float)(v2 + this->mAABBOnActivate.mMax.y) * 0.5;
  v8 = UFG::qMalloc(0xD0ui64, "InterestPoints Nearby", 0i64);
  if ( v8 )
  {
    v9 = UFG::InterestPoint::mspUseInterestPointGrid;
    v10 = UFG::InterestPoint::mspUseInterestPointGrid->mGridSizeInv;
    v11 = (signed int)(float)((float)((float)(v6 - v5) - UFG::InterestPoint::mspUseInterestPointGrid->mXMin) * v10);
    if ( v11 < 0 )
      v11 = 0;
    v12 = (signed int)(float)((float)((float)(v6 + v5) - UFG::InterestPoint::mspUseInterestPointGrid->mXMin) * v10);
    v13 = UFG::InterestPoint::mspUseInterestPointGrid->mXDim;
    if ( v12 >= v13 )
      v12 = v13 - 1;
    v14 = (signed int)(float)((float)((float)(v7 - v5) - UFG::InterestPoint::mspUseInterestPointGrid->mYMin) * v10);
    if ( v14 < 0 )
      v14 = 0;
    v15 = (signed int)(float)((float)((float)(v7 + v5) - UFG::InterestPoint::mspUseInterestPointGrid->mYMin) * v10);
    v16 = UFG::InterestPoint::mspUseInterestPointGrid->mYDim;
    if ( v15 >= v16 )
      v15 = v16 - 1;
    for ( LODWORD(v8[25].mNext) = 0; v14 <= v15; ++v14 )
    {
      for ( i = v11; i <= v12; ++i )
        v8[LODWORD(v8[25].mNext)++].mNext = (UFG::allocator::free_link *)&v9->mGridNodes[i + v9->mXDim * v14];
    }
  }
  else
  {
    v8 = 0i64;
  }
  v1->mpNearbyIntestPoints = (UFG::GridIntrusiveNodesArray<UFG::InterestPoint> *)v8;
  return v8;
}

// File Line: 540
// RVA: 0x5B2BD0
char __fastcall UFG::SpawnRegion::CalcSpawnPoint(UFG::SpawnRegion *this, UFG::qVector3 *pos)
{
  UFG::qVector3 *v2; // rbx
  UFG::qVector3 *v3; // rax
  float v4; // xmm2_4
  float v5; // xmm1_4
  float v6; // xmm0_4
  float v7; // xmm1_4
  char v8; // al
  float v9; // xmm0_4
  UFG::qVector3 rayStart; // [rsp+20h] [rbp-E0h]
  UFG::qVector3 rayEnd; // [rsp+30h] [rbp-D0h]
  UFG::qVector3 result; // [rsp+40h] [rbp-C0h]
  UFG::RayCastData data; // [rsp+50h] [rbp-B0h]

  v2 = pos;
  v3 = UFG::RegionComponent::GetRandomPosition(this->mpRegion, &result);
  v4 = v3->z;
  v5 = v3->y;
  *(float *)&v3 = v3->x;
  data.mInput.m_enableShapeCollectionFilter.m_bool = 0;
  data.mOutput.m_hitFraction = 1.0;
  v2->y = v5;
  rayStart.y = v5;
  rayEnd.y = v5;
  LODWORD(v2->x) = (_DWORD)v3;
  data.mOutput.m_extraInfo = -1;
  v2->z = v4;
  data.mInput.m_filterInfo = 0;
  data.mInput.m_userData = 0i64;
  data.mOutput.m_shapeKeyIndex = 0;
  v6 = v2->x;
  rayStart.z = v4 + 1.0;
  rayEnd.z = v4 - 2.0;
  data.mOutput.m_rootCollidable = 0i64;
  data.mOutput.m_shapeKeys[0] = -1;
  rayStart.x = v6;
  rayEnd.x = v6;
  data.mDebugName = "CalcSpawnPoint";
  data.mCollisionModelName.mUID = -1;
  UFG::RayCastData::Init(&data, &rayStart, &rayEnd, 0xCu);
  if ( !UFG::BasePhysicsSystem::CastRay(UFG::BasePhysicsSystem::mInstance, &data) )
    return 0;
  v7 = data.point.y;
  v8 = 1;
  v2->x = data.point.x;
  v9 = data.point.z;
  v2->y = v7;
  v2->z = v9;
  return v8;
}

// File Line: 572
// RVA: 0x5B36E0
UFG::InterestPoint *__fastcall UFG::SpawnRegion::GetInterestPoint(UFG::SpawnRegion *this, UFG::qVector3 *spawnPos, UFG::qPropertySet *properties_that_must_match, int which_rank_to_get, UFG::SimObject *pSpawnedSimObj)
{
  int v5; // ebx
  UFG::qPropertySet *v6; // rbp
  UFG::qVector3 *v7; // r13
  UFG::SpawnRegion *v8; // r15
  UFG::InterestPoint *v9; // rax
  UFG::InterestPoint *v10; // rdx
  unsigned int v11; // eax
  signed __int64 i; // rdi
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl *v13; // rax
  signed __int64 v14; // r12
  UFG::InterestPoint *v15; // rbx
  signed __int64 v16; // rsi
  UFG::qVector3 *v17; // rax
  float v18; // xmm6_4
  float v19; // xmm3_4
  float v20; // xmm2_4
  float *v21; // rax
  float v22; // xmm5_4
  float v23; // xmm4_4
  float v24; // xmm3_4
  float v25; // xmm0_4
  signed __int64 v26; // rdx
  float *v27; // rax
  __int64 *v28; // r8
  signed __int64 v29; // r9
  __int64 v30; // rax
  signed __int64 v31; // rdx
  UFG::InterestPoint *v32; // rbx
  UFG::qVector3 *v33; // rax
  float v34; // xmm0_4
  float v35; // xmm1_4
  UFG::InterestPoint *result; // rax
  UFG::InterestPoint *v37[2]; // [rsp+20h] [rbp-D8h]
  __int64 v38; // [rsp+30h] [rbp-C8h]
  int v39[2]; // [rsp+38h] [rbp-C0h]
  __int64 v40; // [rsp+40h] [rbp-B8h]
  int v41; // [rsp+48h] [rbp-B0h]
  __int64 v42; // [rsp+50h] [rbp-A8h]
  int v43; // [rsp+58h] [rbp-A0h]
  __int64 v44; // [rsp+60h] [rbp-98h]
  int v45; // [rsp+68h] [rbp-90h]
  __int64 v46; // [rsp+70h] [rbp-88h]
  int v47; // [rsp+78h] [rbp-80h]
  __int64 v48; // [rsp+80h] [rbp-78h]
  int v49; // [rsp+88h] [rbp-70h]
  __int64 v50; // [rsp+90h] [rbp-68h]
  int v51; // [rsp+98h] [rbp-60h]
  unsigned int v52; // [rsp+118h] [rbp+20h]

  v38 = 0i64;
  v39[0] = 0;
  v40 = 0i64;
  v41 = 0;
  v42 = 0i64;
  v43 = 0;
  v44 = 0i64;
  v45 = 0;
  v46 = 0i64;
  v5 = 7;
  v47 = 0;
  v48 = 0i64;
  v49 = 0;
  v50 = 0i64;
  v51 = 0;
  v6 = properties_that_must_match;
  if ( which_rank_to_get <= 7 )
    v5 = which_rank_to_get;
  v7 = spawnPos;
  v8 = this;
  v9 = (UFG::InterestPoint *)UFG::SpawnRegion::GetNearbyInterestPoints(this);
  v10 = v9;
  v37[0] = v9;
  v11 = 0;
  v52 = 0;
  for ( i = v5; v11 < LODWORD(v10->mAnimGroupHandles[0].m_AnimationGroupHandleList.mNode.mPrev); v52 = v11 )
  {
    v13 = (&v10->vfptr)[v11];
    v14 = (signed __int64)&v13[-23];
    v15 = (UFG::InterestPoint *)((char *)v13[1].__vecDelDtor - 184);
    if ( v15 != (UFG::InterestPoint *)&v13[-23] )
    {
      do
      {
        v16 = (signed __int64)&v15->mNext[-12].mNext;
        if ( v15->mActive )
        {
          if ( !v15->mLinkObject.m_pPointer )
          {
            v17 = UFG::InterestPoint::GetPosition(v15);
            v18 = v17->x;
            v19 = v17->y;
            if ( (float)((float)((float)(v7->y - v19) * (float)(v7->y - v19))
                       + (float)((float)(v7->x - v18) * (float)(v7->x - v18))) < 16.0 )
            {
              v20 = v17->z;
              v21 = &v8->mRawAABB->mMin.x;
              v22 = (float)((float)((float)(v19 * v8->mWorldToLocal.v1.x) + (float)(v18 * v8->mWorldToLocal.v0.x))
                          + (float)(v20 * v8->mWorldToLocal.v2.x))
                  + v8->mWorldToLocal.v3.x;
              v23 = (float)((float)((float)(v19 * v8->mWorldToLocal.v1.y) + (float)(v18 * v8->mWorldToLocal.v0.y))
                          + (float)(v20 * v8->mWorldToLocal.v2.y))
                  + v8->mWorldToLocal.v3.y;
              v24 = (float)((float)((float)(v19 * v8->mWorldToLocal.v1.z) + (float)(v18 * v8->mWorldToLocal.v0.z))
                          + (float)(v20 * v8->mWorldToLocal.v2.z))
                  + v8->mWorldToLocal.v3.z;
              if ( v22 >= *v21
                && v22 <= v21[3]
                && v23 >= v21[1]
                && v23 <= v21[4]
                && v24 >= (float)(v21[2] - 0.15000001)
                && v24 <= (float)(v21[5] + 0.15000001)
                && pSpawnedSimObj
                && UFG::InterestPoint::IsRelevantToCharacter(v15, pSpawnedSimObj, 0)
                && (!v6 || UFG::InterestPoint::IsRelevantToPropertySet(v15, v6)) )
              {
                v25 = UFG::InterestPoint::GetRawAppeal(v15);
                v26 = 0i64;
                if ( i > 0 )
                {
                  v27 = (float *)v39;
                  while ( v25 <= *v27 )
                  {
                    ++v26;
                    v27 += 4;
                    if ( v26 >= i )
                      goto LABEL_27;
                  }
                  if ( i - 1 > v26 )
                  {
                    v28 = &v38 + 2 * (i - 1);
                    v29 = i - v26 - 1;
                    do
                    {
                      v30 = *(v28 - 2);
                      v28 -= 2;
                      v28[2] = v30;
                      v28[3] = v28[1];
                      --v29;
                    }
                    while ( v29 );
                  }
                  v31 = 2 * v26;
                  *(float *)&v39[2 * v31] = v25;
                  *(&v38 + v31) = (__int64)v15;
                }
              }
            }
          }
        }
LABEL_27:
        v15 = (UFG::InterestPoint *)v16;
      }
      while ( v16 != v14 );
      v10 = v37[0];
    }
    v11 = v52 + 1;
  }
  v32 = v37[2 * i];
  if ( !v32 )
    return 0i64;
  v33 = UFG::InterestPoint::GetPosition(v32);
  v34 = v33->y;
  v35 = v33->z;
  v7->x = v33->x;
  result = v32;
  v7->y = v34;
  v7->z = v35;
  return result;
}

// File Line: 670
// RVA: 0x5B4040
UFG::qPropertySet *__fastcall UFG::SpawnRegion::GetSpawnableResource(UFG::SpawnRegion *this, bool includeRareCharacters, UFG::qVector3 *preDeterminedPosition)
{
  UFG::SpawnRegion *v3; // rbx
  UFG::qPropertySet *v4; // rax
  UFG::qPropertySet *v5; // r14
  UFG::qPropertyList *v6; // rbp
  unsigned int v7; // esi
  UFG::qPropertyList *v8; // rbx
  unsigned int v9; // eax
  UFG::qSymbol *v10; // rax
  UFG::qPropertySet *v11; // rax
  UFG::qPropertySet *v12; // rdi
  UFG::ObjectResourceManager *v13; // rax
  UFG::qSymbol result; // [rsp+48h] [rbp+10h]

  v3 = this;
  if ( !includeRareCharacters || (v4 = UFG::SpawnRegion::GetRareSpawn(this, preDeterminedPosition)) == 0i64 )
  {
    v5 = v3->mpCachedSpawnSet;
    if ( UFG::gUseDebugSpawnset )
    {
      UFG::qSymbol::create_from_string(&result, "default-spawnset-debug");
      v5 = UFG::PropertySetManager::GetPropertySet(&result);
    }
    v6 = UFG::qPropertySet::Get<UFG::qPropertyList>(v5, (UFG::qSymbol *)&qSymbol_SpawnSet.mUID, DEPTH_RECURSE);
    v7 = v6->mNumElements;
    while ( 1 )
    {
      v8 = v6;
      do
      {
        v9 = UFG::qPropertyList::GetRandomIndex(v8);
        v10 = UFG::qPropertyList::Get<UFG::qSymbol>(v8, v9);
        v11 = UFG::PropertySetManager::FindPropertySet(v10);
        v12 = v11;
        if ( v11 )
          v8 = UFG::qPropertySet::Get<UFG::qPropertyList>(v11, (UFG::qSymbol *)&qSymbol_SpawnSet.mUID, DEPTH_RECURSE);
      }
      while ( v8 );
      if ( !v12 )
        v12 = v5;
      v13 = UFG::ObjectResourceManager::Instance();
      if ( UFG::ObjectResourceManager::CanSpawnAmbient(v13, v12, 0i64, 0) )
        break;
      if ( (signed int)--v7 <= 0 )
      {
        v12 = 0i64;
        break;
      }
    }
    v4 = v12;
  }
  return v4;
}

// File Line: 688
// RVA: 0x5B3C90
UFG::qPropertySet *__fastcall UFG::SpawnRegion::GetRareSpawn(UFG::SpawnRegion *this, UFG::qVector3 *preDeterminedPosition)
{
  UFG::qVector3 *v2; // r15
  UFG::SpawnRegion *v3; // rbx
  UFG::ObjectResourceManager *v4; // rsi
  UFG::qPropertySet *v6; // rax
  UFG::qPropertyList *v7; // rax
  __int64 v8; // rdi
  UFG::qPropertyList *v9; // r13
  unsigned int v10; // er12
  unsigned int v11; // ebp
  char *v12; // rax
  UFG::qPropertySet *v13; // rcx
  unsigned int v14; // ebx
  UFG::qSymbol *v15; // r14
  UFG::CopSystem *v16; // rax
  UFG::CopSystem *v17; // rax
  float *v18; // rax
  unsigned int v19; // er9
  unsigned int v20; // edx
  __int64 v21; // r8
  UFG::qSymbol result; // [rsp+70h] [rbp+18h]

  v2 = preDeterminedPosition;
  v3 = this;
  v4 = UFG::ObjectResourceManager::Instance();
  if ( UFG::EntityTypeState::GetSpawnableRareEntity(v4->mEntityStates)->mUID == UFG::gNullQSymbol.mUID )
    return 0i64;
  UFG::SpawnRegion::GetSpawnInfoName(v3, &result);
  v6 = UFG::PropertySetManager::GetPropertySet(&result);
  v7 = UFG::qPropertySet::Get<UFG::qPropertyList>(v6, (UFG::qSymbol *)&qSymbol_RareSpawnList.mUID, DEPTH_RECURSE);
  v8 = 0i64;
  v9 = v7;
  if ( v7 )
  {
    v10 = v7->mNumElements;
    v11 = 0;
    if ( v10 )
    {
      do
      {
        v12 = UFG::qPropertyList::GetValuePtr(v9, 0x1Au, v11);
        if ( v12 && *(_QWORD *)v12 )
          v13 = (UFG::qPropertySet *)&v12[*(_QWORD *)v12];
        else
          v13 = 0i64;
        v14 = v13->mName.mUID;
        v15 = UFG::qPropertySet::Get<UFG::qSymbol>(v13, (UFG::qSymbol *)&qSymbol_PropertySet.mUID, DEPTH_RECURSE);
        if ( v14 == qSymbol_Police.mUID )
        {
          v16 = UFG::CopSystem::Instance();
          if ( !UFG::CopSystem::AllowSpawnRegionSpawning(v16) )
            break;
          if ( v2 )
          {
            v17 = UFG::CopSystem::Instance();
            v18 = (float *)((__int64 (__fastcall *)(UFG::CopSystem *))v17->vfptr[20].__vecDelDtor)(v17);
            if ( (float)((float)((float)(v18[1] - v2->y) * (float)(v18[1] - v2->y))
                       + (float)((float)(*v18 - v2->x) * (float)(*v18 - v2->x))) < 7225.0 )
              break;
          }
        }
        v19 = v4->mEntityStates[0].mRareSpawnPropertySets.size;
        v20 = 0;
        if ( v19 )
        {
          v21 = 0i64;
          while ( !v4->mEntityStates[0].mRareSpawnIsReady.p[v20]
               || v4->mEntityStates[0].mRareSpawnPropertySets.p[v21].mUID != v15->mUID )
          {
            ++v20;
            ++v21;
            if ( v20 >= v19 )
              goto LABEL_18;
          }
          UFG::EntityTypeState::RareEntitySpawned(v4->mEntityStates, v15);
          return UFG::PropertySetManager::GetPropertySet(v15);
        }
LABEL_18:
        ++v11;
      }
      while ( v11 < v10 );
    }
  }
  return (UFG::qPropertySet *)v8;
}

// File Line: 746
// RVA: 0x5B4E70
bool __fastcall UFG::SpawnRegion::IsSheltered(UFG::SpawnRegion *this)
{
  UFG::SimObject *v1; // rax
  UFG::SceneObjectProperties *v2; // rcx
  UFG::qPropertySet *v3; // rax

  v1 = this->m_pSimObject;
  if ( v1 )
    v2 = v1->m_pSceneObj;
  else
    v2 = 0i64;
  v3 = PropertyUtils::Get<bool>(v2, (UFG::qSymbol *)&qSymbol_Sheltered.mUID);
  return v3 && LOBYTE(v3->mFlags) == 1;
}

// File Line: 755
// RVA: 0x5B4E30
signed __int64 __fastcall UFG::SpawnRegion::IsGroupsAllowed(UFG::SpawnRegion *this)
{
  UFG::SimObject *v1; // rax
  UFG::SceneObjectProperties *v2; // rcx
  UFG::qPropertySet *v3; // rax
  signed __int64 result; // rax

  v1 = this->m_pSimObject;
  if ( v1 )
    v2 = v1->m_pSceneObj;
  else
    v2 = 0i64;
  v3 = PropertyUtils::Get<bool>(v2, (UFG::qSymbol *)&qSymbol_AllowGroups.mUID);
  if ( v3 )
    result = LOBYTE(v3->mFlags);
  else
    result = 1i64;
  return result;
}

// File Line: 761
// RVA: 0x5B42B0
UFG::qSymbol *__fastcall UFG::SpawnRegion::GetUniqueNewName(UFG::SpawnRegion *this, UFG::qSymbol *result)
{
  UFG::qSymbol *v2; // rdi
  unsigned int v3; // ebx
  UFG::OnlineManager *v4; // rax
  _QWORD v6[2]; // [rsp+20h] [rbp-48h]
  UFG::qString resulta; // [rsp+38h] [rbp-30h]

  v2 = result;
  ++GlobalRegionSpawnCount;
  v3 = this->i_name.mUID;
  v4 = UFG::OnlineManager::Instance();
  LODWORD(v6[0]) = UFG::OnlineManager::GetOnlineIdStringHash32(v4);
  UFG::qString::FormatEx(&resulta, "%x-%.3d-%d", v3, (unsigned int)GlobalRegionSpawnCount, v6[0]);
  UFG::qSymbol::create_from_string(v2, resulta.mData);
  UFG::qString::~qString(&resulta);
  return v2;
}

// File Line: 796
// RVA: 0x5B6FB0
UFG::SimObject *__fastcall UFG::SpawnRegion::Spawn(UFG::SpawnRegion *this, const bool includeRareCharacters, UFG::qVector3 *preDeterminedPosition, const bool skip_teleport)
{
  bool v4; // r12
  UFG::qVector3 *v5; // rsi
  UFG::SpawnRegion *v6; // r15
  UFG::Event *v7; // r13
  UFG::SimObject *v8; // rbx
  UFG::qPropertySet *v9; // r14
  UFG::ObjectResourceManager *v10; // rax
  char v11; // al
  float v12; // xmm1_4
  float v13; // xmm2_4
  UFG::SceneObjectProperties *v14; // rdi
  UFG::SceneObjectProperties *v15; // rbx
  UFG::PedSpawnManager *v16; // rax
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl *v17; // rax
  bool v18; // dl
  UFG::TeleportEvent *v19; // rax
  UFG::Event *v20; // rax
  UFG::PedSpawnManager *v21; // rax
  UFG::qSymbol result; // [rsp+18h] [rbp-49h]
  UFG::qPropertySet *pParentPropertySet; // [rsp+20h] [rbp-41h]
  UFG::qVector3 pos; // [rsp+28h] [rbp-39h]
  UFG::qVector3 startPos; // [rsp+38h] [rbp-29h]
  UFG::qMatrix44 dest; // [rsp+48h] [rbp-19h]
  UFG::qPropertySet *retaddr; // [rsp+D8h] [rbp+77h]
  char v29; // [rsp+E0h] [rbp+7Fh]

  pParentPropertySet = (UFG::qPropertySet *)-2i64;
  v4 = skip_teleport;
  v5 = preDeterminedPosition;
  v6 = this;
  v7 = 0i64;
  v8 = 0i64;
  v9 = retaddr;
  if ( !retaddr )
  {
    v9 = UFG::SpawnRegion::GetSpawnableResource(this, includeRareCharacters, preDeterminedPosition);
    if ( !v9 )
      return 0i64;
  }
  v10 = UFG::ObjectResourceManager::Instance();
  if ( !UFG::ObjectResourceManager::CanSpawnAmbient(v10, v9, 0i64, 0) )
    return 0i64;
  v11 = 1;
  if ( v5 )
  {
    v12 = v5->y;
    v13 = v5->z;
    pos.x = v5->x;
    pos.y = v12;
    pos.z = v13;
  }
  else
  {
    v11 = UFG::SpawnRegion::CalcSpawnPoint(v6, &pos);
  }
  if ( v4
    || v11
    && (UFG::gOmitMeshCheck
     || ((unsigned __int8 (__fastcall *)(UFG::NavManager *, UFG::qVector3 *))UFG::NavManager::ms_pInstance->vfptr->IsInsideAIMesh)(
          UFG::NavManager::ms_pInstance,
          &pos)) )
  {
    UFG::SpawnRegion::GetUniqueNewName(v6, &result);
    v14 = v6->mpSceneObjProps;
    v15 = UFG::SceneObjectProperties::Create(&result, 0i64, v9);
    PropertyUtils::SetRuntime<UFG::qSymbol>(
      v15,
      (UFG::qSymbol *)&qSymbol_SpawnPriority.mUID,
      (UFG::qSymbol *)&qSymbol_Low.mUID);
    v8 = UFG::SpawnInfoInterface::ActivateObject(v15, High, 0i64, v14, v9, 3u, 0);
    UFG::TransformNodeComponent::SetParentKeepWorld(
      (UFG::TransformNodeComponent *)v8->m_Components.p[2].m_pComponent,
      0i64,
      0);
    LOBYTE(retaddr) = UFG::SpawnRegion::IsGroupsAllowed(v6);
    if ( !(_BYTE)retaddr || v4 || v29 )
    {
      v17 = UFG::GroupComponent::GetGroupComponent(v8);
      if ( v17 )
      {
        v18 = (_BYTE)retaddr && !v29;
        UFG::GroupComponent::MakeSingle((UFG::GroupComponent *)v17, v18);
      }
    }
    else
    {
      startPos = pos;
      v16 = UFG::PedSpawnManager::GetInstance();
      if ( UFG::PedSpawnManager::JoinGroup(v16, v8, v9, &startPos, v6) )
        pos = startPos;
    }
    UFG::TSCharacter::EnableScriptControlOnSimObject(v8, 0);
    if ( !v4 )
    {
      ARandom::c_gen.i_seed = 1664525 * ARandom::c_gen.i_seed + 1013904223;
      UFG::qRotationMatrixZ(&dest, (float)(COERCE_FLOAT((ARandom::c_gen.i_seed >> 9) | 0x3F800000) - 1.0) * 6.2831855);
      *(UFG::qVector3 *)&dest.v3.x = pos;
      dest.v3.w = 1.0;
      v19 = (UFG::TeleportEvent *)UFG::qMalloc(0x90ui64, "TeleportEvent", 0i64);
      retaddr = (UFG::qPropertySet *)v19;
      if ( v19 )
      {
        UFG::TeleportEvent::TeleportEvent(v19, &dest, v8->mNode.mUID, 0, UFG::TeleportEvent::m_Name, 0);
        v7 = v20;
      }
      UFG::EventDispatcher::DispatchEvent(&UFG::EventDispatcher::mInstance, v7);
      if ( v5 )
      {
        v5->x = pos.x;
        v5->y = pos.y;
        v5->z = pos.z;
      }
    }
    v21 = UFG::PedSpawnManager::GetInstance();
    UFG::PedSpawnManager::SetStartMode(v21, v8, v9, &pos);
  }
  return v8;
}

// File Line: 934
// RVA: 0x5B5120
void __fastcall UFG::SpawnRegion::OnDetach(UFG::SpawnRegion *this)
{
  UFG::SpawnRegion *v1; // rbx
  UFG::PedSpawnManager *v2; // rax
  UFG::GridIntrusiveNodesArray<UFG::InterestPoint> *v3; // rcx

  v1 = this;
  v2 = UFG::PedSpawnManager::GetInstance();
  UFG::PedSpawnManager::UnRegisterActiveSpawnRegion(v2, v1);
  v3 = v1->mpNearbyIntestPoints;
  if ( v3 )
  {
    operator delete[](v3);
    v1->mpNearbyIntestPoints = 0i64;
  }
}

// File Line: 948
// RVA: 0x5B2A90
void __fastcall UFG::SpawnRegion::AddZone(UFG::SpawnRegion *this, UFG::SpawnZone *spawnZone)
{
  UFG::qNode<UFG::SpawnZone,UFG::SpawnRegionList> *v2; // rdx
  UFG::qList<UFG::SpawnZone,UFG::SpawnRegionList,1,0> *v3; // rcx
  UFG::qNode<UFG::SpawnZone,UFG::SpawnRegionList> *v4; // rax

  v2 = (UFG::qNode<UFG::SpawnZone,UFG::SpawnRegionList> *)&spawnZone->mPrev;
  v3 = &this->mZones;
  v4 = v3->mNode.mPrev;
  v4->mNext = v2;
  v2->mPrev = v4;
  v2->mNext = &v3->mNode;
  v3->mNode.mPrev = v2;
}

// File Line: 958
// RVA: 0x5B3E80
UFG::qSymbol *__fastcall UFG::SpawnRegion::GetSpawnInfoName(UFG::SpawnRegion *this, UFG::qSymbol *result)
{
  UFG::SceneObjectProperties *v2; // rax
  UFG::qSymbol *v3; // rbx
  UFG::qPropertySet *v4; // rcx
  UFG::qPropertySet *v5; // rax

  v2 = this->mpSceneObjProps;
  v3 = result;
  v4 = v2->mpWritableProperties;
  if ( !v4 )
    v4 = v2->mpConstProperties;
  v5 = UFG::qPropertySet::Get<UFG::qPropertySet>(
         v4,
         (UFG::qSymbol *)&component_SpawnRegion::sPropertyName.mUID,
         DEPTH_RECURSE);
  if ( v5 )
    v3->mUID = *(_DWORD *)(UFG::qPropertySet::GetMemImagePtr(v5) + 4);
  else
    v3->mUID = MEMORY[4];
  return v3;
}

