// File Line: 331
// RVA: 0x418B10
void __fastcall UFG::qMatrix44_MakeFaceDir2(
        UFG::qMatrix44 *output,
        UFG::qVector3 *origin,
        UFG::qVector3 *dir,
        UFG::qVector3 *upDir)
{
  float y; // xmm0_4
  float z; // xmm1_4
  float x; // eax
  float v7; // xmm8_4
  __m128 x_low; // xmm3
  float v9; // xmm9_4
  __m128 v10; // xmm2
  float v11; // xmm1_4
  float v12; // xmm3_4
  float v13; // xmm8_4
  float v14; // xmm9_4
  __int128 y_low; // xmm5
  __m128 v16; // xmm10
  float v17; // xmm11_4
  __m128 v18; // xmm2
  float v19; // xmm1_4
  float v20; // xmm5_4
  float v21; // xmm11_4
  float v22; // xmm7_4
  __m128 v23; // xmm12
  __m128 v24; // xmm2
  float v25; // xmm1_4
  float v26; // xmm7_4
  float v27; // xmm12_4
  float v28; // xmm2_4
  float v29; // xmm8_4
  float v30; // xmm7_4
  __m128 v31; // xmm2
  float v32; // xmm4_4

  y = origin->y;
  z = origin->z;
  x = origin->x;
  output->v3.w = 1.0;
  output->v3.x = x;
  output->v3.y = y;
  output->v3.z = z;
  v7 = upDir->y;
  x_low = (__m128)LODWORD(upDir->x);
  v9 = upDir->z;
  v10 = x_low;
  v10.m128_f32[0] = (float)((float)(x_low.m128_f32[0] * x_low.m128_f32[0]) + (float)(v7 * v7)) + (float)(v9 * v9);
  if ( v10.m128_f32[0] == 0.0 )
    v11 = 0.0;
  else
    v11 = 1.0 / _mm_sqrt_ps(v10).m128_f32[0];
  v12 = x_low.m128_f32[0] * v11;
  v13 = v7 * v11;
  v14 = v9 * v11;
  output->v2.w = 0.0;
  output->v2.x = v12;
  output->v2.y = v13;
  output->v2.z = v14;
  y_low = LODWORD(dir->y);
  v16 = (__m128)LODWORD(dir->x);
  v17 = dir->z;
  v18 = v16;
  v18.m128_f32[0] = (float)((float)(v16.m128_f32[0] * v16.m128_f32[0]) + (float)(*(float *)&y_low * *(float *)&y_low))
                  + (float)(v17 * v17);
  if ( v18.m128_f32[0] == 0.0 )
    v19 = 0.0;
  else
    v19 = 1.0 / _mm_sqrt_ps(v18).m128_f32[0];
  v20 = *(float *)&y_low * v19;
  v16.m128_f32[0] = v16.m128_f32[0] * v19;
  v21 = v17 * v19;
  v23 = v16;
  v22 = (float)(v21 * v13) - (float)(v20 * v14);
  v23.m128_f32[0] = (float)(v16.m128_f32[0] * v14) - (float)(v21 * v12);
  *(float *)&y_low = (float)(v20 * v12) - (float)(v16.m128_f32[0] * v13);
  v24 = v23;
  v24.m128_f32[0] = (float)((float)(v23.m128_f32[0] * v23.m128_f32[0]) + (float)(v22 * v22))
                  + (float)(*(float *)&y_low * *(float *)&y_low);
  if ( v24.m128_f32[0] == 0.0 )
    v25 = 0.0;
  else
    v25 = 1.0 / _mm_sqrt_ps(v24).m128_f32[0];
  *(float *)&y_low = *(float *)&y_low * v25;
  v26 = v22 * v25;
  v27 = v23.m128_f32[0] * v25;
  v28 = v13;
  output->v1.w = 0.0;
  LODWORD(output->v1.z) = y_low;
  output->v1.x = v26;
  output->v1.y = v27;
  v29 = (float)(v27 * v14) - (float)(*(float *)&y_low * v13);
  *(float *)&y_low = (float)(*(float *)&y_low * v12) - (float)(v26 * v14);
  v30 = (float)(v26 * v28) - (float)(v27 * v12);
  v31 = (__m128)y_low;
  v31.m128_f32[0] = (float)((float)(*(float *)&y_low * *(float *)&y_low) + (float)(v29 * v29)) + (float)(v30 * v30);
  if ( v31.m128_f32[0] == 0.0 )
    v32 = 0.0;
  else
    v32 = 1.0 / _mm_sqrt_ps(v31).m128_f32[0];
  output->v0.w = 0.0;
  output->v0.x = v29 * v32;
  output->v0.z = v30 * v32;
  output->v0.y = *(float *)&y_low * v32;
}

// File Line: 344
// RVA: 0x40C3D0
void __fastcall UFG::GetInterestPointUpRightMatrix(UFG::InterestPoint *interestPoint, UFG::qMatrix44 *outputMatrix)
{
  UFG::TransformNodeComponent *mpXformNode; // rbx
  float y; // xmm4_4
  float z; // xmm5_4
  float x; // xmm0_4
  float v7; // xmm1_4
  float v8; // xmm2_4
  UFG::qVector3 dir; // [rsp+20h] [rbp-28h] BYREF
  UFG::qVector3 origin; // [rsp+2Ch] [rbp-1Ch] BYREF

  mpXformNode = interestPoint->mpXformNode;
  UFG::TransformNodeComponent::UpdateWorldTransform(mpXformNode);
  y = mpXformNode->mWorldTransform.v0.y;
  z = mpXformNode->mWorldTransform.v0.z;
  x = mpXformNode->mWorldTransform.v3.x;
  v7 = mpXformNode->mWorldTransform.v3.y;
  v8 = mpXformNode->mWorldTransform.v3.z;
  dir.x = mpXformNode->mWorldTransform.v0.x;
  dir.y = y;
  dir.z = z;
  origin.x = x;
  origin.y = v7;
  origin.z = v8;
  UFG::qMatrix44_MakeFaceDir2(outputMatrix, &origin, &dir, &UFG::qVector3::msDirUp);
}

// File Line: 355
// RVA: 0x413600
bool __fastcall UFG::PedInfoCompare(UFG::PedSpawningInfo *a, UFG::PedSpawningInfo *b)
{
  return a->mDistInCameraSpace <= b->mDistInCameraSpace;
}

// File Line: 520
// RVA: 0x14E9330
__int64 dynamic_initializer_for__UFG::PedSpawnManager::msSpawnZoneList__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::PedSpawnManager::msSpawnZoneList__);
}

// File Line: 521
// RVA: 0x14E9130
__int64 dynamic_initializer_for__UFG::PedSpawnManager::msActiveZoneList__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::PedSpawnManager::msActiveZoneList__);
}

// File Line: 522
// RVA: 0x14E9310
__int64 dynamic_initializer_for__UFG::PedSpawnManager::msShouldBeActiveZoneList__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::PedSpawnManager::msShouldBeActiveZoneList__);
}

// File Line: 526
// RVA: 0x14E9150
__int64 dynamic_initializer_for__UFG::PedSpawnManager::msAmbientList__()
{
  `eh vector constructor iterator(
    (char *)UFG::PedSpawnManager::msAmbientList,
    0x10ui64,
    6,
    (void (__fastcall *)(void *))UFG::TargetSphere::TargetSphere);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::PedSpawnManager::msAmbientList__);
}

// File Line: 529
// RVA: 0x14E92A0
__int64 dynamic_initializer_for__UFG::PedSpawnManager::msScriptedList__()
{
  `eh vector constructor iterator(
    (char *)UFG::PedSpawnManager::msScriptedList,
    0x10ui64,
    6,
    (void (__fastcall *)(void *))UFG::TargetSphere::TargetSphere);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::PedSpawnManager::msScriptedList__);
}

// File Line: 538
// RVA: 0x14E91F0
__int64 dynamic_initializer_for__UFG::PedSpawnManager::msDisabledThugZones__()
{
  `eh vector constructor iterator(
    (char *)&UFG::PedSpawnManager::msDisabledThugZones,
    8ui64,
    10,
    (void (__fastcall *)(void *))UFG::DisabledThugZone::DisabledThugZone);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::PedSpawnManager::msDisabledThugZones__);
}

// File Line: 569
// RVA: 0x14E9230
__int64 dynamic_initializer_for__UFG::PedSpawnManager::msLowLODHandles__()
{
  `eh vector constructor iterator(
    (char *)&UFG::PedSpawnManager::msLowLODHandles,
    0x20ui64,
    15,
    (void (__fastcall *)(void *))Illusion::ModelHandle::ModelHandle);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::PedSpawnManager::msLowLODHandles__);
}

// File Line: 668
// RVA: 0x405580
void __fastcall UFG::SpawnZone::SpawnZone(UFG::SpawnZone *this)
{
  this->UFG::qNode<UFG::SpawnZone,UFG::SpawnZoneList>::mPrev = &this->UFG::qNode<UFG::SpawnZone,UFG::SpawnZoneList>;
  this->UFG::qNode<UFG::SpawnZone,UFG::SpawnZoneList>::mNext = &this->UFG::qNode<UFG::SpawnZone,UFG::SpawnZoneList>;
  this->UFG::qNode<UFG::SpawnZone,UFG::SpawnRegionList>::mPrev = &this->UFG::qNode<UFG::SpawnZone,UFG::SpawnRegionList>;
  this->UFG::qNode<UFG::SpawnZone,UFG::SpawnRegionList>::mNext = &this->UFG::qNode<UFG::SpawnZone,UFG::SpawnRegionList>;
  UFG::qSafePointerNode<UFG::SpawnZone>::qSafePointerNode<UFG::SpawnZone>(this);
  this->vfptr = (UFG::qSafePointerNode<UFG::SpawnZone>Vtbl *)&UFG::SpawnZone::`vftable;
  *(_QWORD *)&this->mLocalAABB.mMin.x = 0i64;
  *(_QWORD *)&this->mLocalAABB.mMin.z = 0i64;
  *(_QWORD *)&this->mLocalAABB.mMax.y = 0i64;
  this->mpRegion = 0i64;
  this->mpPoint = 0i64;
  this->mpInterestPoint = 0i64;
  *(_WORD *)&this->mHasBeenActivated = 0;
  this->mTimeStamp = -999.0;
  this->mSpawnSetIndex = 0;
  this->mIsRegion = 1;
  this->mSpawnCount = 0;
  *(_QWORD *)&this->mNumDeadPeds = 0i64;
  this->mCullResults = 0i64;
  this->mCullInfo = 0i64;
  this->mZoneActiveStatus = ZoneFree;
}

// File Line: 794
// RVA: 0x406810
void __fastcall UFG::SpawnZone::~SpawnZone(UFG::SpawnZone *this)
{
  UFG::qNode<UFG::qSafePointerBase<UFG::SpawnZone>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SpawnZone>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::SpawnZone,UFG::SpawnRegionList> *v4; // rcx
  UFG::qNode<UFG::SpawnZone,UFG::SpawnRegionList> *v5; // rax
  UFG::qNode<UFG::SpawnZone,UFG::SpawnZoneList> *v6; // rcx
  UFG::qNode<UFG::SpawnZone,UFG::SpawnZoneList> *v7; // rax

  this->vfptr = (UFG::qSafePointerNode<UFG::SpawnZone>Vtbl *)&UFG::SpawnZone::`vftable;
  this->vfptr = (UFG::qSafePointerNode<UFG::SpawnZone>Vtbl *)&UFG::qSafePointerNode<UFG::SpawnZone>::`vftable;
  UFG::qSafePointerNode<UFG::DynamicCoverCorner>::SetAllPointersToNull((UFG::qSafePointerNode<UFG::ParkourHandle> *)this);
  UFG::qList<UFG::qSafePointerBase<CanAttackConditionGroup>,UFG::qSafePointerNodeList,1,0>::DeleteNodes((UFG::qList<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList,1,0> *)&this->m_SafePointerList);
  mPrev = this->m_SafePointerList.mNode.UFG::qSafePointerNode<UFG::SpawnZone>::mPrev;
  mNext = this->m_SafePointerList.mNode.mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  this->m_SafePointerList.mNode.UFG::qSafePointerNode<UFG::SpawnZone>::mPrev = &this->m_SafePointerList.mNode;
  this->m_SafePointerList.mNode.mNext = &this->m_SafePointerList.mNode;
  v4 = this->UFG::qNode<UFG::SpawnZone,UFG::SpawnRegionList>::mPrev;
  v5 = this->UFG::qNode<UFG::SpawnZone,UFG::SpawnRegionList>::mNext;
  v4->mNext = v5;
  v5->mPrev = v4;
  this->UFG::qNode<UFG::SpawnZone,UFG::SpawnRegionList>::mPrev = &this->UFG::qNode<UFG::SpawnZone,UFG::SpawnRegionList>;
  this->UFG::qNode<UFG::SpawnZone,UFG::SpawnRegionList>::mNext = &this->UFG::qNode<UFG::SpawnZone,UFG::SpawnRegionList>;
  v6 = this->UFG::qNode<UFG::SpawnZone,UFG::SpawnZoneList>::mPrev;
  v7 = this->UFG::qNode<UFG::SpawnZone,UFG::SpawnZoneList>::mNext;
  v6->mNext = v7;
  v7->mPrev = v6;
  this->UFG::qNode<UFG::SpawnZone,UFG::SpawnZoneList>::mPrev = &this->UFG::qNode<UFG::SpawnZone,UFG::SpawnZoneList>;
  this->UFG::qNode<UFG::SpawnZone,UFG::SpawnZoneList>::mNext = &this->UFG::qNode<UFG::SpawnZone,UFG::SpawnZoneList>;
}

// File Line: 807
// RVA: 0x413530
void __fastcall UFG::SpawnZone::OnZoneFree(UFG::SpawnZone *this)
{
  UFG::qNode<UFG::SpawnZone,UFG::SpawnZoneList> *mPrev; // rdx
  UFG::qNode<UFG::SpawnZone,UFG::SpawnZoneList> *mNext; // rax
  int mNumDeadPeds; // eax
  CullManager *v5; // rax

  mPrev = this->UFG::qNode<UFG::SpawnZone,UFG::SpawnZoneList>::mPrev;
  mNext = this->UFG::qNode<UFG::SpawnZone,UFG::SpawnZoneList>::mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  this->UFG::qNode<UFG::SpawnZone,UFG::SpawnZoneList>::mPrev = &this->UFG::qNode<UFG::SpawnZone,UFG::SpawnZoneList>;
  this->UFG::qNode<UFG::SpawnZone,UFG::SpawnZoneList>::mNext = &this->UFG::qNode<UFG::SpawnZone,UFG::SpawnZoneList>;
  if ( this->mIsThugZone )
  {
    mNumDeadPeds = this->mNumDeadPeds;
    if ( mNumDeadPeds )
    {
      if ( mNumDeadPeds >= this->mSpawnCount )
        UFG::PedSpawnManager::AddZoneToThugSpawningExceptionsArrary(UFG::gpPedSpawnManager, this);
    }
  }
  --UFG::PedSpawnManager::msNumOfRegisteredSpawnZones;
  this->mTimeStamp = -999.0;
  this->mpRegion = 0i64;
  this->mpPoint = 0i64;
  this->mpInterestPoint = 0i64;
  *(_WORD *)&this->mHasBeenActivated = 0;
  this->mSpawnSetIndex = 0;
  this->mSpawnCount = 0;
  this->mNumDeadPeds = 0;
  this->mIsRegion = 1;
  v5 = CullManager::Instance();
  CullManager::FreePersistentCullInfo(v5, this->mCullResults, this->mCullInfo);
  this->mCullInfo = 0i64;
  this->mCullResults = 0i64;
  this->mZoneActiveStatus = ZoneFree;
  this->mAliveCountValidationTag = 0;
  UFG::qSafePointerNode<UFG::DynamicCoverCorner>::SetAllPointersToNull((UFG::qSafePointerNode<UFG::ParkourHandle> *)this);
}

// File Line: 880
// RVA: 0x407780
void __fastcall UFG::SpawnZone::AllocatePersistentCullInfo(UFG::SpawnZone *this)
{
  CullInfo **p_mCullInfo; // rsi
  CullManager *v3; // rax
  char *v4; // rax
  CullInfo *v5; // rcx
  CullInfo *v6; // rcx
  CullInfo *v7; // rax
  void *mpPoint; // rax
  UFG::TransformNodeComponent *v9; // rbx

  p_mCullInfo = &this->mCullInfo;
  v3 = CullManager::Instance();
  CullManager::AllocPersistentCullInfo(v3, &this->mCullResults, p_mCullInfo, 0i64, 0i64, 0i64);
  (*p_mCullInfo)->mViewsCulled = ~(1 << gMainCullIndex);
  (*p_mCullInfo)->mPixelScaleBias = CullManager::Instance()->mPixelDensityDynamicBias;
  if ( gMainCullIndex <= 16 && gMainCullIndex >= 0 )
  {
    v4 = &this->mCullResults->mViewResult[gMainCullIndex];
    if ( v4 )
      *v4 = 2;
  }
  if ( this->mIsRegion )
  {
    v5 = *p_mCullInfo;
    v5->mAABBMin[0] = this->mLocalAABB.mMin.x;
    v5->mAABBMin[1] = this->mLocalAABB.mMin.y;
    v5->mAABBMin[2] = this->mLocalAABB.mMin.z;
    v6 = *p_mCullInfo;
    v6->mAABBMax[0] = this->mLocalAABB.mMax.x;
    v6->mAABBMax[1] = this->mLocalAABB.mMax.y;
    v6->mAABBMax[2] = this->mLocalAABB.mMax.z;
    (*p_mCullInfo)->mpLocalWorld = &this->mpRegion->mWorldXForm->v0.x;
  }
  else
  {
    v7 = *p_mCullInfo;
    if ( this->mpPoint )
    {
      *(UFG::qVector3 *)v7->mAABBMin = minOffset;
      *(UFG::qVector3 *)(*p_mCullInfo)->mAABBMax = maxOffset;
      mpPoint = this->mpPoint;
    }
    else
    {
      *(UFG::qVector3 *)v7->mAABBMin = minOffsetPOI;
      *(UFG::qVector3 *)(*p_mCullInfo)->mAABBMax = maxOffsetPOI;
      mpPoint = this->mpInterestPoint;
    }
    v9 = (UFG::TransformNodeComponent *)*((_QWORD *)mpPoint + 13);
    UFG::TransformNodeComponent::UpdateWorldTransform(v9);
    (*p_mCullInfo)->mpLocalWorld = &v9->mWorldTransform.v0.x;
  }
}

// File Line: 977
// RVA: 0x4080A0
char __fastcall UFG::SpawnZone::CalcSpawnPoint(UFG::SpawnZone *this, UFG::qVector3 *newPoint)
{
  UFG::qVector3 *RandomPosition; // rax
  float y; // xmm3_4
  float z; // xmm5_4
  UFG::qMatrix44 *mWorldXForm; // rcx
  float v8; // xmm4_4
  float v9; // xmm2_4
  float v10; // xmm6_4
  float v11; // xmm1_4
  char v12; // al
  float x; // xmm0_4
  UFG::qVector3 rayStart; // [rsp+20h] [rbp-D8h] BYREF
  UFG::qVector3 rayEnd; // [rsp+30h] [rbp-C8h] BYREF
  UFG::qVector3 result; // [rsp+40h] [rbp-B8h] BYREF
  UFG::RayCastData data; // [rsp+50h] [rbp-A8h] BYREF

  RandomPosition = UFG::qBox::GetRandomPosition(&this->mLocalAABB, &result);
  y = RandomPosition->y;
  z = RandomPosition->z;
  newPoint->x = RandomPosition->x;
  newPoint->y = y;
  newPoint->z = z;
  mWorldXForm = this->mpRegion->mWorldXForm;
  v8 = (float)((float)((float)(y * mWorldXForm->v1.x) + (float)(newPoint->x * mWorldXForm->v0.x))
             + (float)(z * mWorldXForm->v2.x))
     + mWorldXForm->v3.x;
  v9 = (float)((float)((float)(newPoint->x * mWorldXForm->v0.y) + (float)(y * mWorldXForm->v1.y))
             + (float)(z * mWorldXForm->v2.y))
     + mWorldXForm->v3.y;
  v10 = (float)((float)((float)(newPoint->x * mWorldXForm->v0.z) + (float)(y * mWorldXForm->v1.z))
              + (float)(z * mWorldXForm->v2.z))
      + mWorldXForm->v3.z;
  newPoint->x = v8;
  newPoint->y = v9;
  data.mInput.m_filterInfo = 0;
  data.mInput.m_userData = 0i64;
  data.mOutput.m_shapeKeys[6] = 0;
  *((_QWORD *)&data.mOutput.m_shapeKeyIndex + 1) = 0i64;
  newPoint->z = v10;
  data.mInput.m_enableShapeCollectionFilter.m_bool = 0;
  data.mOutput.m_normal.m_quad.m128_u64[1] = -3229614080i64;
  rayStart.z = v10 + 1.0;
  rayStart.x = v8;
  rayStart.y = v9;
  data.mOutput.m_pad[0] = -1;
  *((_QWORD *)&data.mOutput.m_rootCollidable + 1) = "CalcSpawnPoint";
  LODWORD(data.mDebugName) = -1;
  rayEnd.x = v8;
  rayEnd.y = v9;
  rayEnd.z = v10 - 5.0;
  UFG::RayCastData::Init(&data, &rayStart, &rayEnd, 0xCu);
  if ( !UFG::BasePhysicsSystem::CastRay(UFG::BasePhysicsSystem::mInstance, &data) )
    return 0;
  v11 = *(float *)&data.mCollisionModelName.mUID;
  v12 = 1;
  newPoint->x = *((float *)&data.mDebugName + 1);
  x = data.point.x;
  newPoint->y = v11;
  newPoint->z = x;
  return v12;
}

// File Line: 1086
// RVA: 0x416FD0
__int64 __fastcall UFG::SpawnZone::ShouldSpawnZoneActivate(UFG::SpawnZone *this)
{
  CullResults *mCullResults; // rcx
  unsigned __int8 v3; // di
  UFG::qVector3 *ViewerPosition; // rax
  UFG::InterestPoint *mpInterestPoint; // rcx
  float v7; // xmm2_4
  float SpawnAmbientUserDistance; // xmm0_4
  float mDistSquareToCamera; // xmm1_4
  bool v10; // cc

  mCullResults = this->mCullResults;
  v3 = 0;
  if ( !mCullResults )
    return v3;
  if ( gMainCullIndex < 0 || mCullResults->mViewResult[gMainCullIndex] <= 1u )
  {
    ViewerPosition = UFG::SectionChooser::GetViewerPosition();
    mpInterestPoint = this->mpInterestPoint;
    v7 = (float)((float)((float)(ViewerPosition->y - this->mZoneCentre.y)
                       * (float)(ViewerPosition->y - this->mZoneCentre.y))
               + (float)((float)(ViewerPosition->x - this->mZoneCentre.x)
                       * (float)(ViewerPosition->x - this->mZoneCentre.x)))
       + (float)((float)(ViewerPosition->z - this->mZoneCentre.z) * (float)(ViewerPosition->z - this->mZoneCentre.z));
    this->mDistSquareToCamera = v7;
    if ( mpInterestPoint )
    {
      SpawnAmbientUserDistance = UFG::InterestPoint::GetSpawnAmbientUserDistance(mpInterestPoint);
      mDistSquareToCamera = this->mDistSquareToCamera;
      if ( mDistSquareToCamera >= (float)(SpawnAmbientUserDistance * SpawnAmbientUserDistance) )
        return v3;
      v10 = mDistSquareToCamera <= 36.0;
    }
    else
    {
      if ( v7 >= (float)(UFG::PedSpawnManager::msZoneActivateDist * UFG::PedSpawnManager::msZoneActivateDist) )
        return v3;
      v10 = UFG::PedSpawnManager::msElapsedTotal <= this->mRetryTime;
    }
    if ( !v10 )
      return 1;
    return v3;
  }
  if ( UFG::PedSpawnManager::msPedInfoForLocalZoneChecks
    && (float)((float)((float)((float)(this->mZoneCentre.y
                                     - UFG::PedSpawnManager::msPedInfoForLocalZoneChecks->mCurrentLocation.y)
                             * (float)(this->mZoneCentre.y
                                     - UFG::PedSpawnManager::msPedInfoForLocalZoneChecks->mCurrentLocation.y))
                     + (float)((float)(this->mZoneCentre.x
                                     - UFG::PedSpawnManager::msPedInfoForLocalZoneChecks->mCurrentLocation.x)
                             * (float)(this->mZoneCentre.x
                                     - UFG::PedSpawnManager::msPedInfoForLocalZoneChecks->mCurrentLocation.x)))
             + (float)((float)(this->mZoneCentre.z
                             - UFG::PedSpawnManager::msPedInfoForLocalZoneChecks->mCurrentLocation.z)
                     * (float)(this->mZoneCentre.z
                             - UFG::PedSpawnManager::msPedInfoForLocalZoneChecks->mCurrentLocation.z))) < 9.0 )
  {
    UFG::PedSpawnManager::msPedInfoForLocalZoneChecks->mIsNearDeactivatedZones = 1;
    UFG::PedSpawnManager::msPedInfoForLocalZoneChecks->mShouldCheckZoneInAreaTime = 0.0;
    UFG::PedSpawnManager::msPedInfoForLocalZoneChecks = 0i64;
    return 0i64;
  }
  return v3;
}

// File Line: 1144
// RVA: 0x417140
bool __fastcall UFG::SpawnZone::ShouldSpawnZoneDeactivate(UFG::SpawnZone *this)
{
  UFG::qVector3 *ViewerPosition; // rax
  float v3; // xmm2_4
  float v4; // xmm0_4
  bool result; // al

  if ( this->mCullResults )
  {
    ViewerPosition = UFG::SectionChooser::GetViewerPosition();
    v3 = (float)((float)((float)(ViewerPosition->y - this->mZoneCentre.y)
                       * (float)(ViewerPosition->y - this->mZoneCentre.y))
               + (float)((float)(ViewerPosition->x - this->mZoneCentre.x)
                       * (float)(ViewerPosition->x - this->mZoneCentre.x)))
       + (float)((float)(ViewerPosition->z - this->mZoneCentre.z) * (float)(ViewerPosition->z - this->mZoneCentre.z));
    if ( gMainCullIndex < 0 || this->mCullResults->mViewResult[gMainCullIndex] <= 1u )
    {
      result = 1;
      if ( v3 > (float)((float)(UFG::PedSpawnManager::msZoneActivateDist * 1.2)
                      * (float)(UFG::PedSpawnManager::msZoneActivateDist * 1.2)) )
        return result;
    }
    else
    {
      v4 = (float)(UFG::PedSpawnManager::msZoneActivateDist * 0.80000001)
         * (float)(UFG::PedSpawnManager::msZoneActivateDist * 0.80000001);
      if ( v3 > v4 )
        return 1;
      if ( v3 > (float)(v4 * 0.5) && this->mSpawnCount )
        return this->mAliveCount == 0;
    }
  }
  return 0;
}

// File Line: 1186
// RVA: 0x40DE90
bool __fastcall UFG::SpawnZone::IsValidForTopUpSpawning(UFG::SpawnZone *this)
{
  bool v1; // di
  UFG::qVector3 *ViewerPosition; // rax
  float v5; // xmm2_4
  CullInfo *mCullInfo; // rax
  float v7; // xmm1_4
  float v8; // xmm2_4
  UFG::qMatrix44 *v9; // rcx
  float v10; // xmm1_4
  float v11; // xmm2_4
  UFG::qMatrix44 *mpLocalWorld; // rax
  UFG::qVector4 v13; // xmm2
  UFG::qVector4 v14; // xmm1
  UFG::qVector4 v15; // xmm0
  NISManager *Instance; // rax
  UFG::qVector3 min; // [rsp+20h] [rbp-29h] BYREF
  UFG::qVector3 max; // [rsp+30h] [rbp-19h] BYREF
  UFG::qBox box; // [rsp+40h] [rbp-9h] BYREF
  UFG::qMatrix44 m; // [rsp+60h] [rbp+17h] BYREF

  v1 = 0;
  if ( this->mIsThugZone )
    return 0;
  if ( (float)(UFG::PedSpawnManager::msElapsedTotal - this->mTimeStamp) > 4.0 && this->mCullResults )
  {
    ViewerPosition = UFG::SectionChooser::GetViewerPosition();
    v5 = (float)((float)((float)(ViewerPosition->y - this->mZoneCentre.y)
                       * (float)(ViewerPosition->y - this->mZoneCentre.y))
               + (float)((float)(ViewerPosition->x - this->mZoneCentre.x)
                       * (float)(ViewerPosition->x - this->mZoneCentre.x)))
       + (float)((float)(ViewerPosition->z - this->mZoneCentre.z) * (float)(ViewerPosition->z - this->mZoneCentre.z));
    if ( gMainCullIndex < 0 || this->mCullResults->mViewResult[gMainCullIndex] <= 1u )
    {
      if ( v5 > (float)((float)(UFG::PedSpawnManager::msZoneActivateDist * 0.64999998)
                      * (float)(UFG::PedSpawnManager::msZoneActivateDist * 0.64999998)) )
        v1 = 1;
    }
    else if ( v5 < (float)((float)(UFG::PedSpawnManager::mTestingForRestoreMultiplier
                                 * UFG::PedSpawnManager::msWorkingFullyActiveDistance)
                         * (float)(UFG::PedSpawnManager::mTestingForRestoreMultiplier
                                 * UFG::PedSpawnManager::msWorkingFullyActiveDistance)) )
    {
      v1 = v5 > 100.0;
    }
  }
  if ( NISManager::GetInstance()->mSpatialDataHandle.mData )
  {
    if ( v1 )
    {
      if ( this->mpRegion )
      {
        mCullInfo = this->mCullInfo;
        if ( mCullInfo )
        {
          v7 = mCullInfo->mAABBMin[1];
          v8 = mCullInfo->mAABBMin[2];
          v9 = &UFG::qMatrix44::msIdentity;
          min.x = mCullInfo->mAABBMin[0];
          min.y = v7;
          min.z = v8;
          v10 = mCullInfo->mAABBMax[1];
          v11 = mCullInfo->mAABBMax[2];
          max.x = mCullInfo->mAABBMax[0];
          max.y = v10;
          max.z = v11;
          mpLocalWorld = (UFG::qMatrix44 *)mCullInfo->mpLocalWorld;
          if ( mpLocalWorld )
            v9 = mpLocalWorld;
          v13 = v9->v2;
          v14 = v9->v3;
          v15 = v9->v0;
          m.v1 = v9->v1;
          m.v2 = v13;
          m.v0 = v15;
          m.v3 = v14;
          TransformAABB(&m, &min, &max);
          box.mMin = min;
          box.mMax = max;
          Instance = NISManager::GetInstance();
          if ( NISManager::IntersectsSpatialBoundingBox(Instance, &box) )
            return 0;
        }
      }
    }
  }
  return v1;
}

// File Line: 1264
// RVA: 0x14EA8C0
__int64 dynamic_initializer_for__UFG::PedSpawningInfo::smDrawList__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::PedSpawningInfo::smDrawList__);
}

// File Line: 1265
// RVA: 0x14EA8E0
__int64 dynamic_initializer_for__UFG::PedSpawningInfo::smNoDrawList__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::PedSpawningInfo::smNoDrawList__);
}

// File Line: 1267
// RVA: 0x14EA8A0
__int64 dynamic_initializer_for__UFG::PedSpawningInfo::s_PedSpawningInfoList__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::PedSpawningInfo::s_PedSpawningInfoList__);
}

// File Line: 1268
// RVA: 0x40CDD0
const char *__fastcall UFG::PedSpawningInfo::GetTypeName(UFG::PedSpawningInfo *this)
{
  return "PedSpawningInfo";
}

// File Line: 1275
// RVA: 0x404E90
void __fastcall UFG::PedSpawningInfo::PedSpawningInfo(UFG::PedSpawningInfo *this)
{
  UFG::qNode<UFG::PedSpawningInfo,UFG::PedSpawningInfo_DrawList> *v2; // rsi
  UFG::qNode<UFG::PedSpawningInfo,UFG::PedSpawningInfo> *v3; // rdi
  int v4; // ecx
  UFG::qColour **p_mColourTint; // rax
  UFG::qNode<UFG::PedSpawningInfo,UFG::PedSpawningInfo> *mPrev; // rax
  UFG::qNode<UFG::PedSpawningInfo,UFG::PedSpawningInfo_DrawList> *v7; // rax

  UFG::SimComponent::SimComponent(this, 0xFFFFFFFF);
  this->UFG::qNode<UFG::PedSpawningInfo,UFG::PedInfoList>::mPrev = &this->UFG::qNode<UFG::PedSpawningInfo,UFG::PedInfoList>;
  this->UFG::qNode<UFG::PedSpawningInfo,UFG::PedInfoList>::mNext = &this->UFG::qNode<UFG::PedSpawningInfo,UFG::PedInfoList>;
  v2 = &this->UFG::qNode<UFG::PedSpawningInfo,UFG::PedSpawningInfo_DrawList>;
  this->UFG::qNode<UFG::PedSpawningInfo,UFG::PedSpawningInfo_DrawList>::mPrev = &this->UFG::qNode<UFG::PedSpawningInfo,UFG::PedSpawningInfo_DrawList>;
  this->UFG::qNode<UFG::PedSpawningInfo,UFG::PedSpawningInfo_DrawList>::mNext = &this->UFG::qNode<UFG::PedSpawningInfo,UFG::PedSpawningInfo_DrawList>;
  v3 = &this->UFG::qNode<UFG::PedSpawningInfo,UFG::PedSpawningInfo>;
  this->UFG::qNode<UFG::PedSpawningInfo,UFG::PedSpawningInfo>::mPrev = &this->UFG::qNode<UFG::PedSpawningInfo,UFG::PedSpawningInfo>;
  this->UFG::qNode<UFG::PedSpawningInfo,UFG::PedSpawningInfo>::mNext = &this->UFG::qNode<UFG::PedSpawningInfo,UFG::PedSpawningInfo>;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::PedSpawningInfo::`vftable;
  *(_QWORD *)&this->mSuspendedTime = 0i64;
  this->mPrevCulledTime = 0.0;
  this->mCreationSpawnZone.mPrev = &this->mCreationSpawnZone;
  this->mCreationSpawnZone.mNext = &this->mCreationSpawnZone;
  this->mCreationSpawnZone.m_pPointer = 0i64;
  *(_QWORD *)&this->mActiveStatus = 0i64;
  this->mSimObjectPtr.mPrev = &this->mSimObjectPtr;
  this->mSimObjectPtr.mNext = &this->mSimObjectPtr;
  this->mSimObjectPtr.m_BindCallback.m_Closure.m_pthis = 0i64;
  this->mSimObjectPtr.m_BindCallback.m_Closure.m_pFunction = 0i64;
  this->mSimObjectPtr.m_UnbindCallback.m_Closure.m_pthis = 0i64;
  this->mSimObjectPtr.m_UnbindCallback.m_Closure.m_pFunction = 0i64;
  this->mSimObjectPtr.m_pPointer = 0i64;
  this->mSimObjectPtr.m_Changed = 0;
  UFG::RebindingComponentHandle<UFG::CharacterOccupantComponent,0>::RebindingComponentHandle<UFG::CharacterOccupantComponent,0>(&this->mCharacterOccupantComponent);
  this->mIsDead = 0;
  this->mLifetimeInstanceNameSymbol.mUID = -1;
  v4 = 15;
  p_mColourTint = &this->mTrueCrowdSignature.mPart[0].mColourTint;
  do
  {
    *(p_mColourTint - 1) = 0i64;
    *p_mColourTint = 0i64;
    p_mColourTint += 2;
    --v4;
  }
  while ( v4 >= 0 );
  this->mTrueCrowdSignature.mSet = 0i64;
  this->mTrueCrowdSignature.mNumParts = 0;
  this->mRigNameSymbol = UFG::gNullQSymbolUC;
  this->mPropSetSymbol = UFG::gNullQSymbol;
  this->mArchetypePropSetSymbol = UFG::gNullQSymbol;
  this->mFactionSymbol.mUID = -1;
  `eh vector constructor iterator(this->mAttachedPropNames, 4ui64, 4, (void (__fastcall *)(void *))BackInfo::BackInfo);
  this->mCanSuspendScripted = 1;
  this->mUpgradePOI.mPrev = &this->mUpgradePOI;
  this->mUpgradePOI.mNext = &this->mUpgradePOI;
  this->mUpgradePOI.m_pPointer = 0i64;
  this->mCullInfo = 0i64;
  this->mCullResults = 0i64;
  mPrev = UFG::PedSpawningInfo::s_PedSpawningInfoList.mNode.mPrev;
  UFG::PedSpawningInfo::s_PedSpawningInfoList.mNode.mPrev->mNext = v3;
  v3->mPrev = mPrev;
  this->UFG::qNode<UFG::PedSpawningInfo,UFG::PedSpawningInfo>::mNext = (UFG::qNode<UFG::PedSpawningInfo,UFG::PedSpawningInfo> *)&UFG::PedSpawningInfo::s_PedSpawningInfoList;
  UFG::PedSpawningInfo::s_PedSpawningInfoList.mNode.mPrev = &this->UFG::qNode<UFG::PedSpawningInfo,UFG::PedSpawningInfo>;
  UFG::SimComponent::AddType(this, UFG::PedSpawningInfo::_PedSpawningInfoTypeUID, "PedSpawningInfo");
  v7 = UFG::PedSpawningInfo::smDrawList.mNode.mPrev;
  UFG::PedSpawningInfo::smDrawList.mNode.mPrev->mNext = v2;
  v2->mPrev = v7;
  this->UFG::qNode<UFG::PedSpawningInfo,UFG::PedSpawningInfo_DrawList>::mNext = (UFG::qNode<UFG::PedSpawningInfo,UFG::PedSpawningInfo_DrawList> *)&UFG::PedSpawningInfo::smDrawList;
  UFG::PedSpawningInfo::smDrawList.mNode.mPrev = &this->UFG::qNode<UFG::PedSpawningInfo,UFG::PedSpawningInfo_DrawList>;
  this->m_Flags &= ~8u;
}

// File Line: 1284
// RVA: 0x405EC0
void __fastcall UFG::PedSpawningInfo::~PedSpawningInfo(UFG::PedSpawningInfo *this)
{
  UFG::qNode<UFG::PedSpawningInfo,UFG::PedSpawningInfo> *v2; // rdi
  UFG::qNode<UFG::PedSpawningInfo,UFG::PedSpawningInfo> *mPrev; // rcx
  UFG::qNode<UFG::PedSpawningInfo,UFG::PedSpawningInfo> *mNext; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::InterestPoint> *p_mUpgradePOI; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v7; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qSafePointer<UFG::SpawnZone,UFG::SpawnZone> *p_mCreationSpawnZone; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SpawnZone>,UFG::qSafePointerNodeList> *v11; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SpawnZone>,UFG::qSafePointerNodeList> *v12; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SpawnZone>,UFG::qSafePointerNodeList> *v13; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SpawnZone>,UFG::qSafePointerNodeList> *v14; // rax
  UFG::qNode<UFG::PedSpawningInfo,UFG::PedSpawningInfo> *v15; // rcx
  UFG::qNode<UFG::PedSpawningInfo,UFG::PedSpawningInfo> *v16; // rax
  UFG::qNode<UFG::PedSpawningInfo,UFG::PedSpawningInfo_DrawList> *v17; // rcx
  UFG::qNode<UFG::PedSpawningInfo,UFG::PedSpawningInfo_DrawList> *v18; // rax
  UFG::qNode<UFG::PedSpawningInfo,UFG::PedInfoList> *v19; // rcx
  UFG::qNode<UFG::PedSpawningInfo,UFG::PedInfoList> *v20; // rax

  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::PedSpawningInfo::`vftable;
  if ( this == UFG::PedSpawningInfo::s_PedSpawningInfopCurrentIterator )
    UFG::PedSpawningInfo::s_PedSpawningInfopCurrentIterator = (UFG::PedSpawningInfo *)&this->UFG::qNode<UFG::PedSpawningInfo,UFG::PedSpawningInfo>::mPrev[-6];
  v2 = &this->UFG::qNode<UFG::PedSpawningInfo,UFG::PedSpawningInfo>;
  mPrev = this->UFG::qNode<UFG::PedSpawningInfo,UFG::PedSpawningInfo>::mPrev;
  mNext = v2->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  v2->mPrev = v2;
  v2->mNext = v2;
  p_mUpgradePOI = &this->mUpgradePOI;
  if ( this->mUpgradePOI.m_pPointer )
  {
    v6 = p_mUpgradePOI->mPrev;
    v7 = this->mUpgradePOI.mNext;
    v6->mNext = v7;
    v7->mPrev = v6;
    p_mUpgradePOI->mPrev = p_mUpgradePOI;
    this->mUpgradePOI.mNext = &this->mUpgradePOI;
  }
  this->mUpgradePOI.m_pPointer = 0i64;
  v8 = p_mUpgradePOI->mPrev;
  v9 = this->mUpgradePOI.mNext;
  v8->mNext = v9;
  v9->mPrev = v8;
  p_mUpgradePOI->mPrev = p_mUpgradePOI;
  this->mUpgradePOI.mNext = &this->mUpgradePOI;
  `eh vector destructor iterator(this->mAttachedPropNames, 4ui64, 4, (void (__fastcall *)(void *))_);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&this->mCharacterOccupantComponent);
  UFG::qSafePointerWithCallbacksBase<UFG::SimObject>::~qSafePointerWithCallbacksBase<UFG::SimObject>(&this->mSimObjectPtr);
  p_mCreationSpawnZone = &this->mCreationSpawnZone;
  if ( this->mCreationSpawnZone.m_pPointer )
  {
    v11 = p_mCreationSpawnZone->mPrev;
    v12 = this->mCreationSpawnZone.mNext;
    v11->mNext = v12;
    v12->mPrev = v11;
    p_mCreationSpawnZone->mPrev = p_mCreationSpawnZone;
    this->mCreationSpawnZone.mNext = &this->mCreationSpawnZone;
  }
  this->mCreationSpawnZone.m_pPointer = 0i64;
  v13 = p_mCreationSpawnZone->mPrev;
  v14 = this->mCreationSpawnZone.mNext;
  v13->mNext = v14;
  v14->mPrev = v13;
  p_mCreationSpawnZone->mPrev = p_mCreationSpawnZone;
  this->mCreationSpawnZone.mNext = &this->mCreationSpawnZone;
  v15 = v2->mPrev;
  v16 = v2->mNext;
  v15->mNext = v16;
  v16->mPrev = v15;
  v2->mPrev = v2;
  v2->mNext = v2;
  v17 = this->UFG::qNode<UFG::PedSpawningInfo,UFG::PedSpawningInfo_DrawList>::mPrev;
  v18 = this->UFG::qNode<UFG::PedSpawningInfo,UFG::PedSpawningInfo_DrawList>::mNext;
  v17->mNext = v18;
  v18->mPrev = v17;
  this->UFG::qNode<UFG::PedSpawningInfo,UFG::PedSpawningInfo_DrawList>::mPrev = &this->UFG::qNode<UFG::PedSpawningInfo,UFG::PedSpawningInfo_DrawList>;
  this->UFG::qNode<UFG::PedSpawningInfo,UFG::PedSpawningInfo_DrawList>::mNext = &this->UFG::qNode<UFG::PedSpawningInfo,UFG::PedSpawningInfo_DrawList>;
  v19 = this->UFG::qNode<UFG::PedSpawningInfo,UFG::PedInfoList>::mPrev;
  v20 = this->UFG::qNode<UFG::PedSpawningInfo,UFG::PedInfoList>::mNext;
  v19->mNext = v20;
  v20->mPrev = v19;
  this->UFG::qNode<UFG::PedSpawningInfo,UFG::PedInfoList>::mPrev = &this->UFG::qNode<UFG::PedSpawningInfo,UFG::PedInfoList>;
  this->UFG::qNode<UFG::PedSpawningInfo,UFG::PedInfoList>::mNext = &this->UFG::qNode<UFG::PedSpawningInfo,UFG::PedInfoList>;
  UFG::SimComponent::~SimComponent(this);
}

// File Line: 1317
// RVA: 0x4076B0
void __fastcall UFG::PedSpawningInfo::AllocatePersistentCullInfo(UFG::PedSpawningInfo *this)
{
  CullResults **p_mCullResults; // rdi
  CullInfo **p_mCullInfo; // rbx
  CullManager *v3; // rax

  p_mCullResults = &this->mCullResults;
  if ( !this->mCullResults )
  {
    p_mCullInfo = &this->mCullInfo;
    v3 = CullManager::Instance();
    CullManager::AllocPersistentCullInfo(v3, p_mCullResults, p_mCullInfo, 0i64, 0i64, 0i64);
    (*p_mCullInfo)->mViewsCulled = ~(1 << gMainCullIndex);
    (*p_mCullInfo)->mPixelScaleBias = 3;
    *(UFG::qVector3 *)(*p_mCullInfo)->mAABBMin = minOffset;
    *(UFG::qVector3 *)(*p_mCullInfo)->mAABBMax = maxOffset;
    (*p_mCullResults)->mViewResult[0] = 2;
  }
}

// File Line: 1339
// RVA: 0x4187D0
void __fastcall UFG::PedSpawningInfo::UpdatePersistentCullInfo(UFG::PedSpawningInfo *this)
{
  UFG::PedSpawningInfo::eActiveStatus mActiveStatus; // eax
  UFG::TransformNodeComponent *mTransformNodePtr; // rdi

  mActiveStatus = this->mActiveStatus;
  if ( mActiveStatus >= ExtraLowPower )
  {
    mTransformNodePtr = this->mTransformNodePtr;
    if ( !mTransformNodePtr || mActiveStatus == ExtraLowPower )
      mTransformNodePtr = this->mProxyTransformNode;
    UFG::TransformNodeComponent::UpdateWorldTransform(mTransformNodePtr);
    this->mCullInfo->mpLocalWorld = &mTransformNodePtr->mWorldTransform.v0.x;
  }
}

// File Line: 1371
// RVA: 0x14F0390
void UFG::_dynamic_initializer_for__proxyColours__()
{
  UFG::proxyColours[0] = UFG::qColour::White;
  xmmword_1423DE520 = (__int128)UFG::qColour::Grey;
  xmmword_1423DE530 = (__int128)UFG::qColour::Black;
  xmmword_1423DE540 = (__int128)UFG::qColour::Red;
  xmmword_1423DE550 = (__int128)UFG::qColour::Maroon;
  xmmword_1423DE560 = (__int128)UFG::qColour::Orange;
  xmmword_1423DE570 = (__int128)UFG::qColour::Gold;
  xmmword_1423DE580 = (__int128)UFG::qColour::Yellow;
  xmmword_1423DE590 = (__int128)UFG::qColour::Kaki;
  xmmword_1423DE5A0 = (__int128)UFG::qColour::Green;
  xmmword_1423DE5B0 = (__int128)UFG::qColour::Lime;
  xmmword_1423DE5C0 = (__int128)UFG::qColour::ForestGreen;
  xmmword_1423DE5D0 = (__int128)UFG::qColour::Cyan;
  xmmword_1423DE5E0 = (__int128)UFG::qColour::Teal;
  xmmword_1423DE5F0 = (__int128)UFG::qColour::Blue;
  xmmword_1423DE600 = (__int128)UFG::qColour::DogerBlue;
  xmmword_1423DE610 = (__int128)UFG::qColour::Magenta;
  xmmword_1423DE620 = (__int128)UFG::qColour::DarkViolet;
  xmmword_1423DE630 = (__int128)UFG::qColour::Purple;
  xmmword_1423DE640 = (__int128)UFG::qColour::Pink;
  xmmword_1423DE650 = (__int128)UFG::qColour::DeepPink;
  xmmword_1423DE660 = (__int128)UFG::qColour::Brown;
  xmmword_1423DE670 = (__int128)UFG::qColour::SaddleBrown;
}

// File Line: 1400
// RVA: 0x40AD00
void __fastcall UFG::PedSpawningInfo::Draw(UFG::PedSpawningInfo *this, Render::View *view)
{
  UFG::TransformNodeComponent *mTransformNodePtr; // rdi
  unsigned int mProxyOverDrawFrames; // eax
  CullResults *mCullResults; // rcx
  int *v7; // rdx
  Render::ViewSettings *mSettings; // rdx
  __int64 mCullIndex; // rax
  __int64 v10; // rax
  int v11; // xmm0_4
  Illusion::SubmitContext *mSubmitContext; // rax
  float v13; // [rsp+30h] [rbp+8h] BYREF
  int v14; // [rsp+34h] [rbp+Ch]

  if ( this->mCulledTime == 0.0 && (this->mPrevCulledTime <= 0.0 || this->mLocationClassification) )
  {
    mTransformNodePtr = this->mTransformNodePtr;
    if ( !mTransformNodePtr || this->mActiveStatus == ExtraLowPower )
      mTransformNodePtr = this->mProxyTransformNode;
    mProxyOverDrawFrames = this->mProxyOverDrawFrames;
    if ( mProxyOverDrawFrames )
      this->mProxyOverDrawFrames = mProxyOverDrawFrames - 1;
    if ( mTransformNodePtr )
    {
      mCullResults = this->mCullResults;
      v7 = 0i64;
      if ( mCullResults )
      {
        mSettings = view->mSettings;
        mCullIndex = view->mSettings->mCullIndex;
        if ( (int)mCullIndex >= 6 )
          v13 = 0.0;
        else
          v13 = mCullResults->mDistance[mCullIndex];
        v10 = mSettings->mCullIndex;
        if ( (int)v10 >= 6 )
          v11 = (int)FLOAT_1_0;
        else
          v11 = LODWORD(mCullResults->mPixelCoverage[v10]);
        v14 = v11;
        v7 = (int *)&v13;
      }
      mSubmitContext = view->mSubmitContext;
      mSubmitContext[1].vfptr = (Illusion::SubmitContextVtbl *)v7;
      mSubmitContext[1].mStateValues.mSetValueMask.mFlags[0] = 0i64;
      UFG::TransformNodeComponent::UpdateWorldTransform(mTransformNodePtr);
      SubmitRenderModel(
        view,
        *((Illusion::Model **)&UFG::PedSpawnManager::msLowLODHandles.mData + 4 * this->mProxyModelHandleIndex),
        &mTransformNodePtr->mWorldTransform);
    }
  }
}

// File Line: 1458
// RVA: 0x40AE20
void __fastcall UFG::PedSpawningInfo::DrawAll(Render::View *view)
{
  char *v2; // rbx
  UFG::qColour *v3; // r8
  Illusion::StateValues *StateValues; // rax
  UFG::qNode<UFG::PedSpawningInfo,UFG::PedSpawningInfo_DrawList> *p_mNode; // rcx
  UFG::qList<UFG::PedSpawningInfo,UFG::PedSpawningInfo_DrawList,1,0> *v6; // rbx
  UFG::qNode<UFG::PedSpawningInfo,UFG::PedSpawningInfo_DrawList> *v7; // rcx
  UFG::qList<UFG::PedSpawningInfo,UFG::PedSpawningInfo_DrawList,1,0> *v8; // rbx

  v2 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x40u, 0x10u);
  v3 = &UFG::proxyColours[UFG::g_ped_colour_index];
  *(float *)v2 = v3->r;
  *((_DWORD *)v2 + 1) = LODWORD(v3->g);
  *((_DWORD *)v2 + 2) = LODWORD(v3->b);
  *((_DWORD *)v2 + 3) = LODWORD(v3->a);
  StateValues = Render::View::GetStateValues(view);
  StateValues->mSetValueMask.mFlags[0] |= 0x400000000ui64;
  StateValues->mParamValues[34] = v2;
  p_mNode = UFG::PedSpawningInfo::smDrawList.mNode.mNext - 5;
  if ( (UFG::qList<UFG::PedSpawningInfo,UFG::PedSpawningInfo_DrawList,1,0> *)&UFG::PedSpawningInfo::smDrawList.mNode.mNext[-5] != &UFG::PedSpawningInfo::smDrawList - 5 )
  {
    do
    {
      v6 = (UFG::qList<UFG::PedSpawningInfo,UFG::PedSpawningInfo_DrawList,1,0> *)&p_mNode[5].mNext[-5];
      if ( LODWORD(p_mNode[10].mNext) == 2 || LODWORD(p_mNode[17].mPrev) )
        UFG::PedSpawningInfo::Draw((UFG::PedSpawningInfo *)p_mNode, view);
      p_mNode = &v6->mNode;
    }
    while ( v6 != &UFG::PedSpawningInfo::smDrawList - 5 );
  }
  if ( !UFG::PedSpawnManager::msAmbientStatusCheckEnable )
  {
    v7 = UFG::PedSpawningInfo::smNoDrawList.mNode.mNext - 5;
    if ( (UFG::qList<UFG::PedSpawningInfo,UFG::PedSpawningInfo_DrawList,1,0> *)&UFG::PedSpawningInfo::smNoDrawList.mNode.mNext[-5] != &UFG::PedSpawningInfo::smNoDrawList - 5 )
    {
      do
      {
        v8 = (UFG::qList<UFG::PedSpawningInfo,UFG::PedSpawningInfo_DrawList,1,0> *)&v7[5].mNext[-5];
        if ( LODWORD(v7[10].mNext) == 2 || LODWORD(v7[17].mPrev) )
          UFG::PedSpawningInfo::Draw((UFG::PedSpawningInfo *)v7, view);
        v7 = &v8->mNode;
      }
      while ( v8 != &UFG::PedSpawningInfo::smNoDrawList - 5 );
    }
  }
}

// File Line: 1561
// RVA: 0x417250
void __fastcall UFG::PedSpawningInfo::SimObjectPtrGoingNull(UFG::PedSpawningInfo *this, UFG::SimObject *byeBye)
{
  CullResults *mCullResults; // rdi
  CullManager *v4; // rax

  UFG::PedSpawningInfo::MakeCompletelyInactive(this);
  mCullResults = this->mCullResults;
  if ( mCullResults )
  {
    v4 = CullManager::Instance();
    CullManager::FreePersistentCullInfo(v4, mCullResults, this->mCullInfo);
    this->mCullResults = 0i64;
    this->mCullInfo = 0i64;
  }
  this->mTransformNodePtr = 0i64;
}

// File Line: 1655
// RVA: 0x407FD0
void __fastcall UFG::PedSpawningInfo::AttachGroupComponent(UFG::PedSpawningInfo *this, bool ownsAIEntity)
{
  UFG::SimObject *mProxySimObjectPtr; // rdx
  UFG::SimObject *m_pPointer; // rax
  UFG::AIEntityComponent *m_pComponent; // rcx
  UFG::SimObjectModifier v7; // [rsp+28h] [rbp-30h] BYREF

  if ( this->mGroupComponent )
  {
    mProxySimObjectPtr = this->mProxySimObjectPtr;
    if ( mProxySimObjectPtr )
    {
      UFG::SimObjectModifier::SimObjectModifier(&v7, mProxySimObjectPtr, 1);
      UFG::SimObjectModifier::AttachComponent(&v7, this->mGroupComponent, 0xFFFFFFFFi64);
      UFG::SimObjectModifier::Close(&v7);
      UFG::SimObjectModifier::~SimObjectModifier(&v7);
    }
    UFG::GroupComponent::SetOwner(this->mGroupComponent, this);
  }
  if ( ownsAIEntity )
  {
    m_pPointer = this->mSimObjectPtr.m_pPointer;
    if ( m_pPointer )
    {
      m_pComponent = (UFG::AIEntityComponent *)m_pPointer->m_Components.p[22].m_pComponent;
      if ( m_pComponent )
        UFG::AIEntityComponent::SetGroupComponent(m_pComponent, this->mGroupComponent);
    }
  }
}

// File Line: 1676
// RVA: 0x40AC20
void __fastcall UFG::PedSpawningInfo::DetachGroupComponent(UFG::PedSpawningInfo *this)
{
  UFG::SimObject *mProxySimObjectPtr; // rdx
  UFG::SimObject *m_pPointer; // rax
  UFG::SimComponent *m_pComponent; // rdx
  UFG::qList<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase,0,0> *p_m_BoundComponentHandles; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mPrev; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mNext; // rax
  ArrayOfTuplesImplementation v8; // [rsp+28h] [rbp-30h] BYREF

  if ( this->mGroupComponent )
  {
    mProxySimObjectPtr = this->mProxySimObjectPtr;
    if ( mProxySimObjectPtr )
    {
      UFG::SimObjectModifier::SimObjectModifier((UFG::SimObjectModifier *)&v8, mProxySimObjectPtr, 1);
      ArrayOfTuplesImplementation::clear(&v8);
      UFG::SimObjectModifier::Close((UFG::SimObjectModifier *)&v8);
      UFG::SimObjectModifier::~SimObjectModifier((UFG::SimObjectModifier *)&v8);
    }
    UFG::GroupComponent::SetOwner(this->mGroupComponent, 0i64);
  }
  m_pPointer = this->mSimObjectPtr.m_pPointer;
  if ( m_pPointer )
  {
    m_pComponent = m_pPointer->m_Components.p[22].m_pComponent;
    if ( m_pComponent )
    {
      if ( m_pComponent[15].vfptr == (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)this->mGroupComponent )
      {
        p_m_BoundComponentHandles = &m_pComponent[14].m_BoundComponentHandles;
        if ( p_m_BoundComponentHandles[1].mNode.mPrev )
        {
          mPrev = p_m_BoundComponentHandles->mNode.mPrev;
          mNext = p_m_BoundComponentHandles->mNode.mNext;
          mPrev->mNext = mNext;
          mNext->mPrev = mPrev;
          p_m_BoundComponentHandles->mNode.mPrev = &p_m_BoundComponentHandles->mNode;
          p_m_BoundComponentHandles->mNode.mNext = &p_m_BoundComponentHandles->mNode;
        }
        p_m_BoundComponentHandles[1].mNode.mPrev = 0i64;
      }
    }
  }
}

// File Line: 1700
// RVA: 0x417BA0
void __fastcall UFG::PedSpawningInfo::SwapGroupComponent(UFG::PedSpawningInfo *this, UFG::PedSpawningInfo *other)
{
  UFG::GroupComponent *mGroupComponent; // r8

  if ( this != other )
  {
    UFG::PedSpawningInfo::DetachGroupComponent(this);
    UFG::PedSpawningInfo::DetachGroupComponent(other);
    mGroupComponent = this->mGroupComponent;
    this->mGroupComponent = other->mGroupComponent;
    other->mGroupComponent = mGroupComponent;
    UFG::PedSpawningInfo::AttachGroupComponent(this, 1);
    UFG::PedSpawningInfo::AttachGroupComponent(other, other->mSimObjectPtr.m_pPointer != this->mSimObjectPtr.m_pPointer);
  }
}

// File Line: 1723
// RVA: 0x416920
void __fastcall UFG::PedSpawningInfo::SetSimObjectPtr(UFG::PedSpawningInfo *this, UFG::EncounterBase *simObj)
{
  UFG::SimObject *m_pPointer; // rax
  UFG::SimComponent *m_pComponent; // rdx
  UFG::qList<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase,0,0> *p_m_BoundComponentHandles; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mPrev; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mNext; // rax
  UFG::SimObject *v9; // rax
  UFG::SimComponent *v10; // rdx
  UFG::GroupComponent *mGroupComponent; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::GroupComponent>,UFG::qSafePointerNodeList> *v12; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::GroupComponent>,UFG::qSafePointerNodeList> *v13; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::GroupComponent>,UFG::qSafePointerNodeList> *v14; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::GroupComponent>,UFG::qSafePointerNodeList> *v15; // rax
  UFG::qSafePointerWithCallbacks<UFG::SimObject,UFG::SimObjectCharacter> *p_mSimObjectPtr; // rdx
  UFG::qNode<UFG::qSafePointerWithCallbacksBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v17; // rcx
  UFG::qNode<UFG::qSafePointerWithCallbacksBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v18; // rax

  m_pPointer = this->mSimObjectPtr.m_pPointer;
  if ( m_pPointer )
  {
    m_pComponent = m_pPointer->m_Components.p[22].m_pComponent;
    if ( m_pComponent )
    {
      if ( m_pComponent[15].vfptr == (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)this->mGroupComponent )
      {
        p_m_BoundComponentHandles = &m_pComponent[14].m_BoundComponentHandles;
        if ( p_m_BoundComponentHandles[1].mNode.mPrev )
        {
          mPrev = p_m_BoundComponentHandles->mNode.mPrev;
          mNext = p_m_BoundComponentHandles->mNode.mNext;
          mPrev->mNext = mNext;
          mNext->mPrev = mPrev;
          p_m_BoundComponentHandles->mNode.mPrev = &p_m_BoundComponentHandles->mNode;
          p_m_BoundComponentHandles->mNode.mNext = &p_m_BoundComponentHandles->mNode;
        }
        p_m_BoundComponentHandles[1].mNode.mPrev = 0i64;
      }
    }
  }
  if ( simObj )
  {
    UFG::qSafePointerWithCallbacks<UFG::SimObject,UFG::SimObjectVehicle>::Set(
      (UFG::qSafePointerWithCallbacks<UFG::EncounterBase,UFG::EncounterBase> *)&this->mSimObjectPtr,
      simObj);
    this->mTransformNodePtr = *(UFG::TransformNodeComponent **)(*(_QWORD *)&simObj->mWaterHeatLevelPropertiesName[0].mUID
                                                              + 32i64);
    UFG::RebindingComponentHandle<UFG::CharacterOccupantComponent,0>::Bind<UFG::SimObjectCharacter>(
      &this->mCharacterOccupantComponent,
      (UFG::SimObjectCharacter *)simObj);
    v9 = this->mSimObjectPtr.m_pPointer;
    if ( v9 )
    {
      v10 = v9->m_Components.p[22].m_pComponent;
      if ( v10 )
      {
        mGroupComponent = this->mGroupComponent;
        v12 = (UFG::qNode<UFG::qSafePointerBase<UFG::GroupComponent>,UFG::qSafePointerNodeList> *)&v10[14].m_BoundComponentHandles;
        if ( v12[1].mPrev )
        {
          v13 = v12->mPrev;
          v14 = v12->mNext;
          v13->mNext = v14;
          v14->mPrev = v13;
          v12->mPrev = v12;
          v12->mNext = v12;
        }
        v12[1].mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::GroupComponent>,UFG::qSafePointerNodeList> *)mGroupComponent;
        if ( mGroupComponent )
        {
          v15 = mGroupComponent->UFG::qSafePointerNode<UFG::GroupComponent>::m_SafePointerList.mNode.UFG::qSafePointerNode<UFG::GroupComponent>::mPrev;
          v15->mNext = v12;
          v12->mPrev = v15;
          v12->mNext = &mGroupComponent->UFG::qSafePointerNode<UFG::GroupComponent>::m_SafePointerList.mNode;
          mGroupComponent->UFG::qSafePointerNode<UFG::GroupComponent>::m_SafePointerList.mNode.UFG::qSafePointerNode<UFG::GroupComponent>::mPrev = v12;
        }
      }
    }
  }
  else
  {
    p_mSimObjectPtr = &this->mSimObjectPtr;
    if ( this->mSimObjectPtr.m_pPointer )
    {
      v17 = p_mSimObjectPtr->mPrev;
      v18 = this->mSimObjectPtr.mNext;
      v17->mNext = v18;
      v18->mPrev = v17;
      p_mSimObjectPtr->mPrev = p_mSimObjectPtr;
      this->mSimObjectPtr.mNext = &this->mSimObjectPtr;
      this->mSimObjectPtr.m_Changed = 1;
    }
    this->mSimObjectPtr.m_pPointer = 0i64;
    this->mTransformNodePtr = 0i64;
    UFG::RebindingComponentHandleBase::Unbind(&this->mCharacterOccupantComponent);
  }
}

// File Line: 1770
// RVA: 0x40DD80
char __fastcall UFG::PedSpawningInfo::IsUsingPOI(UFG::PedSpawningInfo *this, UFG::InterestPoint **ppInterestPoint)
{
  UFG::SimObject *m_pPointer; // rax
  UFG::SimComponent *m_pComponent; // r8
  __int64 v6; // rax
  __int64 v7; // rcx
  UFG::SimObject *v8; // rcx
  __int16 m_Flags; // dx
  UFG::InterestPoint *v10; // rcx

  m_pPointer = this->mSimObjectPtr.m_pPointer;
  if ( !m_pPointer )
    return 0;
  m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
  if ( !m_pComponent )
    return 0;
  v6 = *(_QWORD *)&m_pComponent[1].m_TypeUID;
  v7 = 56i64 * *(unsigned __int8 *)(*(_QWORD *)&m_pComponent[1].m_Flags + 34i64);
  if ( !*(_QWORD *)(v7 + v6 + 40) )
    return 0;
  if ( !*(_BYTE *)(v7 + v6 + 49) )
    return 0;
  v8 = *(UFG::SimObject **)(v7 + v6 + 40);
  if ( !v8 )
    return 0;
  m_Flags = v8->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
  {
    v10 = (UFG::InterestPoint *)v8->m_Components.p[25].m_pComponent;
  }
  else if ( m_Flags >= 0 )
  {
    if ( (m_Flags & 0x2000) != 0 )
      v10 = (UFG::InterestPoint *)v8->m_Components.p[10].m_pComponent;
    else
      v10 = (UFG::InterestPoint *)((m_Flags & 0x1000) != 0
                                 ? v8->m_Components.p[3].m_pComponent
                                 : UFG::SimObject::GetComponentOfType(v8, UFG::InterestPoint::_TypeUID));
  }
  else
  {
    v10 = (UFG::InterestPoint *)v8->m_Components.p[25].m_pComponent;
  }
  if ( v10->mpUser.m_pPointer != this->mSimObjectPtr.m_pPointer )
    return 0;
  if ( ppInterestPoint )
    *ppInterestPoint = v10;
  return 1;
}

// File Line: 1798
// RVA: 0x418410
void __fastcall UFG::PedSpawningInfo::UpdateDeadStatus(UFG::PedSpawningInfo *this)
{
  UFG::SimObject *m_pPointer; // rax
  UFG::SimComponent *m_pComponent; // rdx
  UFG::SpawnZone *v3; // rax

  if ( !this->mIsDead )
  {
    m_pPointer = this->mSimObjectPtr.m_pPointer;
    if ( m_pPointer )
    {
      m_pComponent = m_pPointer->m_Components.p[6].m_pComponent;
      if ( m_pComponent )
      {
        if ( BYTE4(m_pComponent[1].m_BoundComponentHandles.mNode.mPrev) )
        {
          v3 = this->mCreationSpawnZone.m_pPointer;
          this->mIsDead = 1;
          if ( v3 )
            ++v3->mNumDeadPeds;
        }
      }
    }
  }
}

// File Line: 1817
// RVA: 0x40C120
float __fastcall UFG::PedSpawningInfo::GetHowLongDead(UFG::PedSpawningInfo *this)
{
  UFG::SimObject *m_pPointer; // rax
  UFG::SimComponent *m_pComponent; // rax
  UFG::SimObjectGame *mProxySimObjectPtr; // rcx
  __int16 m_Flags; // dx

  if ( !this->mIsDead )
    return 0.0;
  m_pPointer = this->mSimObjectPtr.m_pPointer;
  if ( m_pPointer )
  {
    m_pComponent = m_pPointer->m_Components.p[6].m_pComponent;
  }
  else
  {
    mProxySimObjectPtr = (UFG::SimObjectGame *)this->mProxySimObjectPtr;
    if ( !mProxySimObjectPtr )
      return 0.0;
    m_Flags = mProxySimObjectPtr->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = mProxySimObjectPtr->m_Components.p[6].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
        m_pComponent = UFG::SimObjectGame::GetComponentOfTypeHK(mProxySimObjectPtr, UFG::HealthComponent::_TypeUID);
      else
        m_pComponent = UFG::SimObject::GetComponentOfType(mProxySimObjectPtr, UFG::HealthComponent::_TypeUID);
    }
    else
    {
      m_pComponent = mProxySimObjectPtr->m_Components.p[6].m_pComponent;
    }
  }
  if ( m_pComponent )
    return UFG::Metrics::msInstance.mSimTime_Temp - *(float *)&m_pComponent[3].m_pSimObject;
  return 0.0;
}

// File Line: 1842
// RVA: 0x416410
void __fastcall UFG::PedSpawningInfo::SetActiveStatus(
        UFG::PedSpawningInfo *this,
        UFG::PedSpawningInfo::eActiveStatus newStatus)
{
  __int64 v2; // rdi
  __int64 mActiveStatus; // rdx
  UFG::qNode<UFG::PedSpawningInfo,UFG::PedInfoList> *mNext; // rax
  UFG::qNode<UFG::PedSpawningInfo,UFG::PedInfoList> *mPrev; // r8
  UFG::qNode<UFG::PedSpawningInfo,UFG::PedInfoList> *v7; // r9
  UFG::qList<UFG::PedSpawningInfo,UFG::PedInfoList,1,0> *v8; // rcx
  UFG::qNode<UFG::PedSpawningInfo,UFG::PedInfoList> *v9; // rax
  UFG::qNode<UFG::PedSpawningInfo,UFG::PedInfoList> *v10; // r8
  UFG::qNode<UFG::PedSpawningInfo,UFG::PedInfoList> *v11; // rcx
  UFG::qList<UFG::PedSpawningInfo,UFG::PedInfoList,1,0> *v12; // rcx
  UFG::qNode<UFG::PedSpawningInfo,UFG::PedInfoList> *v13; // rax
  CullResults *mCullResults; // rdi
  CullManager *v15; // rax

  v2 = newStatus;
  mActiveStatus = this->mActiveStatus;
  if ( (_DWORD)v2 != (_DWORD)mActiveStatus )
  {
    mNext = this->UFG::qNode<UFG::PedSpawningInfo,UFG::PedInfoList>::mNext;
    if ( this->mPedType == AmbientPed )
    {
      mPrev = this->UFG::qNode<UFG::PedSpawningInfo,UFG::PedInfoList>::mPrev;
      v7 = &this->UFG::qNode<UFG::PedSpawningInfo,UFG::PedInfoList>;
      mPrev->mNext = mNext;
      mNext->mPrev = mPrev;
      this->UFG::qNode<UFG::PedSpawningInfo,UFG::PedInfoList>::mPrev = &this->UFG::qNode<UFG::PedSpawningInfo,UFG::PedInfoList>;
      this->UFG::qNode<UFG::PedSpawningInfo,UFG::PedInfoList>::mNext = &this->UFG::qNode<UFG::PedSpawningInfo,UFG::PedInfoList>;
      --UFG::PedSpawnManager::msAmbientCount[mActiveStatus];
      v8 = &UFG::PedSpawnManager::msAmbientList[v2];
      v9 = v8->mNode.mNext;
      v8->mNode.mNext = v7;
      v7->mPrev = &v8->mNode;
      v7->mNext = v9;
      v9->mPrev = v7;
      ++UFG::PedSpawnManager::msAmbientCount[v2];
    }
    else
    {
      v10 = &this->UFG::qNode<UFG::PedSpawningInfo,UFG::PedInfoList>;
      v11 = this->UFG::qNode<UFG::PedSpawningInfo,UFG::PedInfoList>::mPrev;
      v11->mNext = mNext;
      mNext->mPrev = v11;
      v10->mPrev = v10;
      v10->mNext = v10;
      --UFG::PedSpawnManager::msScriptedCount[mActiveStatus];
      v12 = &UFG::PedSpawnManager::msScriptedList[v2];
      v13 = v12->mNode.mPrev;
      v13->mNext = v10;
      v10->mPrev = v13;
      v10->mNext = &v12->mNode;
      ++UFG::PedSpawnManager::msScriptedCount[v2];
      v12->mNode.mPrev = v10;
    }
    if ( !(_DWORD)v2 )
    {
      if ( this->mTrueCrowdSignature.mSet )
        UFG::TrueCrowdSet::Instance::RemoveProxyReference(&this->mTrueCrowdSignature, this);
      this->mTrueCrowdSignature.mSet = 0i64;
      this->mTrueCrowdSignature.mNumParts = 0;
    }
    this->mActiveStatus = v2;
    if ( (int)v2 < ExtraLowPower )
    {
      mCullResults = this->mCullResults;
      if ( mCullResults )
      {
        v15 = CullManager::Instance();
        CullManager::FreePersistentCullInfo(v15, mCullResults, this->mCullInfo);
        this->mCullResults = 0i64;
        this->mCullInfo = 0i64;
      }
    }
    else
    {
      UFG::PedSpawningInfo::AllocatePersistentCullInfo(this);
      UFG::PedSpawningInfo::UpdatePersistentCullInfo(this);
    }
  }
}

// File Line: 1926
// RVA: 0x40D610
void __fastcall UFG::PedSpawningInfo::Init(UFG::PedSpawningInfo *this, int index, UFG::ePedType pedType)
{
  UFG::qSafePointerWithCallbacks<UFG::SimObject,UFG::SimObjectCharacter> *p_mSimObjectPtr; // rdi
  UFG::qNode<UFG::qSafePointerWithCallbacksBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mPrev; // r9
  UFG::qNode<UFG::qSafePointerWithCallbacksBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mNext; // rax
  fastdelegate::detail::GenericClass *m_pthis; // rcx
  UFG::RebindingComponentHandle<UFG::CharacterOccupantComponent,0> *p_mCharacterOccupantComponent; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v11; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v12; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v13; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v14; // rax
  UFG::qSafePointer<UFG::SpawnZone,UFG::SpawnZone> *p_mCreationSpawnZone; // rdx
  float y; // xmm1_4
  float z; // xmm2_4
  UFG::qNode<UFG::qSafePointerBase<UFG::SpawnZone>,UFG::qSafePointerNodeList> *v18; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SpawnZone>,UFG::qSafePointerNodeList> *v19; // rax
  UFG::qNode<UFG::PedSpawningInfo,UFG::PedInfoList> *v20; // rcx
  UFG::qNode<UFG::PedSpawningInfo,UFG::PedInfoList> *v21; // rax
  UFG::qNode<UFG::PedSpawningInfo,UFG::PedInfoList> *v22; // rax
  fastdelegate::detail::GenericClass *RCX; // rax
  float v24; // xmm0_4

  p_mSimObjectPtr = &this->mSimObjectPtr;
  if ( this->mSimObjectPtr.m_pPointer )
  {
    mPrev = p_mSimObjectPtr->mPrev;
    mNext = this->mSimObjectPtr.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_mSimObjectPtr->mPrev = p_mSimObjectPtr;
    this->mSimObjectPtr.mNext = &this->mSimObjectPtr;
    this->mSimObjectPtr.m_Changed = 1;
    m_pthis = this->mSimObjectPtr.m_UnbindCallback.m_Closure.m_pthis;
    if ( m_pthis || p_mSimObjectPtr->m_UnbindCallback.m_Closure.m_pFunction )
      ((void (__fastcall *)(fastdelegate::detail::GenericClass *, UFG::SimObject *))p_mSimObjectPtr->m_UnbindCallback.m_Closure.m_pFunction)(
        m_pthis,
        p_mSimObjectPtr->m_pPointer);
  }
  p_mCharacterOccupantComponent = &this->mCharacterOccupantComponent;
  p_mSimObjectPtr->m_pPointer = 0i64;
  this->mTransformNodePtr = 0i64;
  if ( this->mCharacterOccupantComponent.m_pSimComponent )
  {
    v11 = p_mCharacterOccupantComponent->mPrev;
    v12 = this->mCharacterOccupantComponent.mNext;
    v11->mNext = v12;
    v12->mPrev = v11;
    this->mCharacterOccupantComponent.m_pSimComponent = 0i64;
LABEL_11:
    this->mCharacterOccupantComponent.m_pSimObject = 0i64;
    this->mCharacterOccupantComponent.mNext = &this->mCharacterOccupantComponent;
    p_mCharacterOccupantComponent->mPrev = p_mCharacterOccupantComponent;
    goto LABEL_12;
  }
  if ( this->mCharacterOccupantComponent.m_pSimObject
    && (p_mCharacterOccupantComponent->mPrev != p_mCharacterOccupantComponent
     || this->mCharacterOccupantComponent.mNext != &this->mCharacterOccupantComponent) )
  {
    v13 = p_mCharacterOccupantComponent->mPrev;
    v14 = this->mCharacterOccupantComponent.mNext;
    v13->mNext = v14;
    v14->mPrev = v13;
    goto LABEL_11;
  }
LABEL_12:
  this->mCharacterOccupantComponent.m_Changed = 1;
  this->mCharacterOccupantComponent.m_TypeUID = UFG::CharacterOccupantComponent::_TypeUID;
  this->mSpawnLocation.x = -10000.0;
  this->mSpawnLocation.y = -10000.0;
  this->mSpawnLocation.z = -10000.0;
  this->mSpawnTime = 0.0;
  this->mCanSuspendScripted = 1;
  this->mIsDead = 0;
  this->mIsNearDeactivatedZones = 0;
  this->mShouldCheckZoneInAreaTime = 0.0;
  *(_QWORD *)&this->mSuspendedTime = 0i64;
  this->mTeleportOnResumeRequired = 1;
  p_mCreationSpawnZone = &this->mCreationSpawnZone;
  y = UFG::qVector3::msZero.y;
  z = UFG::qVector3::msZero.z;
  this->mSuspendedPos.x = UFG::qVector3::msZero.x;
  this->mSuspendedPos.y = y;
  this->mSuspendedPos.z = z;
  *(_QWORD *)&this->mRestoreAttempts = 0i64;
  this->mHowSpawned = FromScript;
  this->mPedType = pedType;
  this->mPedIndex = index;
  this->mStatusChangedFrame = 0;
  if ( this->mCreationSpawnZone.m_pPointer )
  {
    v18 = p_mCreationSpawnZone->mPrev;
    v19 = this->mCreationSpawnZone.mNext;
    v18->mNext = v19;
    v19->mPrev = v18;
    p_mCreationSpawnZone->mPrev = p_mCreationSpawnZone;
    this->mCreationSpawnZone.mNext = &this->mCreationSpawnZone;
  }
  this->mCreationSpawnZone.m_pPointer = 0i64;
  v20 = &this->UFG::qNode<UFG::PedSpawningInfo,UFG::PedInfoList>;
  this->mActiveStatus = Inactive;
  this->mLocationClassification = Always_Active;
  if ( pedType == AmbientPed )
  {
    v21 = (UFG::qNode<UFG::PedSpawningInfo,UFG::PedInfoList> *)qword_1423DEF68;
    qword_1423DEF68 = (__int64)&this->UFG::qNode<UFG::PedSpawningInfo,UFG::PedInfoList>;
    this->UFG::qNode<UFG::PedSpawningInfo,UFG::PedInfoList>::mNext = v21;
    v20->mPrev = (UFG::qNode<UFG::PedSpawningInfo,UFG::PedInfoList> *)UFG::PedSpawnManager::msAmbientList;
    v21->mPrev = v20;
    ++UFG::PedSpawnManager::msAmbientCount[0];
  }
  else
  {
    v22 = UFG::PedSpawnManager::msScriptedList[0].mNode.mNext;
    UFG::PedSpawnManager::msScriptedList[0].mNode.mNext = &this->UFG::qNode<UFG::PedSpawningInfo,UFG::PedInfoList>;
    this->UFG::qNode<UFG::PedSpawningInfo,UFG::PedInfoList>::mNext = v22;
    v20->mPrev = (UFG::qNode<UFG::PedSpawningInfo,UFG::PedInfoList> *)UFG::PedSpawnManager::msScriptedList;
    v22->mPrev = v20;
    ++UFG::PedSpawnManager::msScriptedCount[0];
  }
  RCX = (fastdelegate::detail::GenericClass *)Assembly::GetRCX(this);
  this->mSimObjectPtr.m_UnbindCallback.m_Closure.m_pFunction = (void (__fastcall *)(fastdelegate::detail::GenericClass *))UFG::PedSpawningInfo::SimObjectPtrGoingNull;
  this->mSimObjectPtr.m_UnbindCallback.m_Closure.m_pthis = RCX;
  this->mProxySimObjectPtr = 0i64;
  UFG::PedSpawningInfo::InitProxySimObject(this, index);
  *(_QWORD *)&this->mProxyModelHandleIndex = 0i64;
  this->mProxyTimeSinceLastFrameUpdate = 0.0;
  v24 = UFG::qRandom(0.30000001, (unsigned int *)&UFG::qDefaultSeed);
  this->mProxyOverDrawFrames = 0;
  this->mDumpResourcePriorityScore = 0.0;
  this->mProxyIndividualTimeScale = v24 + 0.40000001;
  if ( this->mTrueCrowdSignature.mSet )
    UFG::TrueCrowdSet::Instance::RemoveProxyReference(&this->mTrueCrowdSignature, this);
  this->mTrueCrowdSignature.mSet = 0i64;
  this->mTrueCrowdSignature.mNumParts = 0;
  this->mNumAttachedProps = 0;
  this->mPropSetSymbol = UFG::gNullQSymbol;
  this->mFactionSymbol = UFG::gNullQSymbol;
  this->mRigNameSymbol = UFG::gNullQSymbolUC;
}

// File Line: 2006
// RVA: 0x40D8F0
void __fastcall UFG::PedSpawningInfo::InitProxySimObject(UFG::PedSpawningInfo *this, int index)
{
  __int64 mPedIndex; // r8
  UFG::qMemoryPool *SimulationMemoryPool; // rax
  UFG::allocator::free_link *v5; // rsi
  UFG::qSymbol *v6; // rax
  UFG::SimObject *v7; // rax
  UFG::SimObject *v8; // rsi
  UFG::qMemoryPool *v9; // rax
  UFG::allocator::free_link *v10; // rbx
  unsigned int v11; // eax
  UFG::TransformNodeComponent *v12; // rax
  UFG::TransformNodeComponent *v13; // r15
  UFG::qMemoryPool *v14; // rax
  UFG::allocator::free_link *v15; // rbx
  unsigned int v16; // eax
  UFG::AILightWeightComponent *v17; // rax
  UFG::AILightWeightComponent *v18; // r14
  UFG::qMemoryPool *v19; // rax
  UFG::allocator::free_link *v20; // rax
  UFG::GroupComponent *v21; // rbx
  unsigned int v22; // eax
  UFG::qVector4 v23; // xmm3
  float y; // xmm1_4
  float z; // xmm2_4
  __int16 m_Flags; // cx
  unsigned int v27; // ebx
  UFG::SimObjectModifier v28; // [rsp+10h] [rbp-61h] BYREF
  UFG::qMatrix44 m; // [rsp+38h] [rbp-39h] BYREF
  __int64 v30; // [rsp+78h] [rbp+7h]
  UFG::qString result; // [rsp+80h] [rbp+Fh] BYREF
  UFG::allocator::free_link *v32; // [rsp+D8h] [rbp+67h]
  UFG::qSymbol v33; // [rsp+E8h] [rbp+77h] BYREF

  v30 = -2i64;
  if ( !this->mProxySimObjectPtr )
  {
    mPedIndex = (unsigned int)this->mPedIndex;
    if ( this->mPedType != AmbientPed )
      mPedIndex = (unsigned int)(mPedIndex + 1000);
    UFG::qString::FormatEx(&result, "ProxyPed%d", mPedIndex);
    SimulationMemoryPool = UFG::GetSimulationMemoryPool();
    v5 = UFG::qMemoryPool::Allocate(SimulationMemoryPool, 0x80ui64, "ProxyPedSimObject", 0i64, 1u);
    v32 = v5;
    if ( v5 )
    {
      v6 = UFG::qSymbol::create_from_string(&v33, result.mData);
      UFG::SimObject::SimObject((UFG::SimObject *)v5, v6);
      v8 = v7;
    }
    else
    {
      v8 = 0i64;
    }
    this->mProxySimObjectPtr = v8;
    UFG::Simulation::TrackSimObject(&UFG::gSim, v8);
    v9 = UFG::GetSimulationMemoryPool();
    v10 = UFG::qMemoryPool::Allocate(v9, 0x110ui64, "TransformNodeComponent", 0i64, 1u);
    v32 = v10;
    if ( v10 )
    {
      v11 = UFG::qStringHash32("ProxyPedTransform", 0xFFFFFFFF);
      UFG::TransformNodeComponent::TransformNodeComponent((UFG::TransformNodeComponent *)v10, v11, 0i64, 0);
      v13 = v12;
    }
    else
    {
      v13 = 0i64;
    }
    v14 = UFG::GetSimulationMemoryPool();
    v15 = UFG::qMemoryPool::Allocate(v14, 0x1E0ui64, "AILightWeightComponent", 0i64, 1u);
    v32 = v15;
    if ( v15 )
    {
      v16 = UFG::qStringHash32("ProxyPedAI", 0xFFFFFFFF);
      UFG::AILightWeightComponent::AILightWeightComponent((UFG::AILightWeightComponent *)v15, v16);
      v18 = v17;
    }
    else
    {
      v18 = 0i64;
    }
    v19 = UFG::GetSimulationMemoryPool();
    v20 = UFG::qMemoryPool::Allocate(v19, 0x118ui64, "GroupComponent", 0i64, 1u);
    v21 = (UFG::GroupComponent *)v20;
    v32 = v20;
    if ( v20 )
    {
      v22 = UFG::qStringHash32("ProxyPedGroup", 0xFFFFFFFF);
      UFG::GroupComponent::GroupComponent(v21, v22);
    }
    this->mProxyTransformNode = v13;
    this->mProxyAIComponent = v18;
    this->mNetworkComponent = 0i64;
    this->mGroupComponent = (UFG::GroupComponent *)v20;
    v23 = 0i64;
    v23.x = (float)1;
    m.v0 = v23;
    m.v1 = (UFG::qVector4)_mm_shuffle_ps((__m128)v23, (__m128)v23, 81);
    m.v2 = (UFG::qVector4)_mm_shuffle_ps((__m128)v23, (__m128)v23, 69);
    m.v3 = (UFG::qVector4)_mm_shuffle_ps((__m128)v23, (__m128)v23, 21);
    y = this->mSpawnLocation.y;
    z = this->mSpawnLocation.z;
    m.v3.x = this->mSpawnLocation.x;
    m.v3.y = y;
    m.v3.z = z;
    LODWORD(m.v3.w) = (_DWORD)FLOAT_1_0;
    UFG::TransformNodeComponent::SetWorldTransform(v13, &m);
    m_Flags = v8->m_Flags;
    if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 || (m_Flags & 0x2000) != 0 )
    {
      v27 = 2;
    }
    else
    {
      v27 = -1;
      if ( (m_Flags & 0x1000) != 0 )
        v27 = 1;
    }
    UFG::SimObjectModifier::SimObjectModifier(&v28, v8, 1);
    UFG::SimObjectModifier::AttachComponent(&v28, v13, v27);
    UFG::SimObjectModifier::Close(&v28);
    UFG::SimObjectModifier::~SimObjectModifier(&v28);
    UFG::SimObjectModifier::SimObjectModifier(&v28, v8, 1);
    UFG::SimObjectModifier::AttachComponent(&v28, v18, 0xFFFFFFFFi64);
    UFG::SimObjectModifier::Close(&v28);
    UFG::SimObjectModifier::~SimObjectModifier(&v28);
    UFG::PedSpawningInfo::AttachGroupComponent(this, 1);
    UFG::qString::~qString(&result);
  }
}

// File Line: 2048
// RVA: 0x415820
void __fastcall UFG::PedSpawningInfo::Reset(UFG::PedSpawningInfo *this, bool preserveProxies)
{
  UFG::SimObject *m_pPointer; // rcx
  UFG::SimObject *mProxySimObjectPtr; // rcx
  UFG::qSafePointer<UFG::SimComponent,UFG::InterestPoint> *p_mUpgradePOI; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qSafePointer<UFG::SpawnZone,UFG::SpawnZone> *p_mCreationSpawnZone; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SpawnZone>,UFG::qSafePointerNodeList> *v10; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SpawnZone>,UFG::qSafePointerNodeList> *v11; // rax

  m_pPointer = this->mSimObjectPtr.m_pPointer;
  if ( m_pPointer )
  {
    if ( m_pPointer->m_pSceneObj->mpParent )
      UFG::SceneObjectProperties::DeactivateDeferred(m_pPointer->m_pSceneObj);
    else
      UFG::SimObject::Destroy(m_pPointer);
  }
  UFG::PedSpawningInfo::MakeCompletelyInactive(this);
  this->mNumAttachedProps = 0;
  if ( this->mTrueCrowdSignature.mSet )
    UFG::TrueCrowdSet::Instance::RemoveProxyReference(&this->mTrueCrowdSignature, this);
  this->mTrueCrowdSignature.mSet = 0i64;
  this->mTrueCrowdSignature.mNumParts = 0;
  this->mRigNameSymbol = UFG::gNullQSymbolUC;
  this->mFactionSymbol = UFG::gNullQSymbol;
  this->mLifetimeInstanceNameSymbol = UFG::gNullQSymbol;
  if ( !preserveProxies )
  {
    mProxySimObjectPtr = this->mProxySimObjectPtr;
    if ( mProxySimObjectPtr )
    {
      UFG::SimObject::Destroy(mProxySimObjectPtr);
      this->mProxySimObjectPtr = 0i64;
    }
    this->mTransformNodePtr = 0i64;
    this->mProxyAIComponent = 0i64;
    this->mGroupComponent = 0i64;
  }
  p_mUpgradePOI = &this->mUpgradePOI;
  *(_QWORD *)&this->mProxyTimeSinceLastAIUpdate = 0i64;
  if ( this->mUpgradePOI.m_pPointer )
  {
    mPrev = p_mUpgradePOI->mPrev;
    mNext = this->mUpgradePOI.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_mUpgradePOI->mPrev = p_mUpgradePOI;
    this->mUpgradePOI.mNext = &this->mUpgradePOI;
  }
  this->mUpgradePOI.m_pPointer = 0i64;
  p_mCreationSpawnZone = &this->mCreationSpawnZone;
  if ( this->mCreationSpawnZone.m_pPointer )
  {
    v10 = p_mCreationSpawnZone->mPrev;
    v11 = this->mCreationSpawnZone.mNext;
    v10->mNext = v11;
    v11->mPrev = v10;
    p_mCreationSpawnZone->mPrev = p_mCreationSpawnZone;
    this->mCreationSpawnZone.mNext = &this->mCreationSpawnZone;
  }
  this->mCreationSpawnZone.m_pPointer = 0i64;
  this->mIsDead = 0;
  this->mIsNearDeactivatedZones = 0;
  this->mShouldCheckZoneInAreaTime = 0.0;
  *(_QWORD *)&this->mSuspendedTime = 0i64;
  this->mTeleportOnResumeRequired = 1;
  this->mStatusChangedFrame = -1;
}

// File Line: 2096
// RVA: 0x40E4E0
void __fastcall UFG::PedSpawningInfo::MakeCompletelyInactive(UFG::PedSpawningInfo *this)
{
  UFG::GroupComponent *mGroupComponent; // rcx
  UFG::InterestPoint *m_pPointer; // rcx
  UFG::qSafePointer<UFG::SimComponent,UFG::InterestPoint> *p_mUpgradePOI; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax

  mGroupComponent = this->mGroupComponent;
  if ( mGroupComponent )
    UFG::GroupComponent::Reset(mGroupComponent);
  m_pPointer = (UFG::InterestPoint *)this->mUpgradePOI.m_pPointer;
  this->mIsNearDeactivatedZones = 0;
  this->mShouldCheckZoneInAreaTime = 0.0;
  this->mNumAttachedProps = 0;
  this->mBlipActive = 0;
  if ( m_pPointer && m_pPointer->mpPedInfoUser == this )
    UFG::InterestPoint::SetPedInfoUser(m_pPointer, 0i64);
  p_mUpgradePOI = &this->mUpgradePOI;
  if ( this->mUpgradePOI.m_pPointer )
  {
    mPrev = p_mUpgradePOI->mPrev;
    mNext = this->mUpgradePOI.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_mUpgradePOI->mPrev = p_mUpgradePOI;
    this->mUpgradePOI.mNext = &this->mUpgradePOI;
  }
  this->mUpgradePOI.m_pPointer = 0i64;
  UFG::PedSpawningInfo::SetActiveStatus(this, Inactive);
}

// File Line: 2149
// RVA: 0x4157B0
void __fastcall UFG::PedSpawningInfo::RemoveProps(UFG::PedSpawningInfo *this)
{
  UFG::SimObject *m_pPointer; // rax
  UFG::InventoryComponent *m_pComponent; // rbx

  m_pPointer = this->mSimObjectPtr.m_pPointer;
  if ( m_pPointer )
  {
    m_pComponent = (UFG::InventoryComponent *)m_pPointer->m_Components.p[39].m_pComponent;
    UFG::InventoryComponent::UnEquip(m_pComponent, eINVENTORY_EQUIP_SLOT_RIGHT_HAND, 1);
    UFG::InventoryComponent::UnEquip(m_pComponent, eINVENTORY_EQUIP_SLOT_LEFT_HAND, 1);
    UFG::InventoryComponent::UnEquip(m_pComponent, eINVENTORY_EQUIP_SLOT_HAT, 1);
    UFG::InventoryComponent::UnEquip(m_pComponent, eINVENTORY_EQUIP_SLOT_GLASSES, 1);
  }
}

// File Line: 2193
// RVA: 0x416B70
void __fastcall UFG::PedSpawningInfo::SetTrueCrowdSignature(
        UFG::PedSpawningInfo *this,
        UFG::TrueCrowdSet::Instance *tcs)
{
  UFG::TrueCrowdSet::Instance *p_mTrueCrowdSignature; // rdi
  UFG::TrueCrowdSet::Instance *v5; // rdx
  __int64 v6; // rax
  UFG::ModelTextureCombination v7; // xmm0

  p_mTrueCrowdSignature = &this->mTrueCrowdSignature;
  if ( this->mTrueCrowdSignature.mSet )
    UFG::TrueCrowdSet::Instance::RemoveProxyReference(p_mTrueCrowdSignature, this);
  v5 = p_mTrueCrowdSignature;
  if ( (((unsigned __int8)p_mTrueCrowdSignature | (unsigned __int8)tcs) & 0xF) != 0 )
  {
    memmove(p_mTrueCrowdSignature, tcs, 0x118ui64);
  }
  else
  {
    v6 = 2i64;
    do
    {
      v7 = *(UFG::ModelTextureCombination *)&tcs->mSet;
      v5 = (UFG::TrueCrowdSet::Instance *)((char *)v5 + 128);
      tcs = (UFG::TrueCrowdSet::Instance *)((char *)tcs + 128);
      v5[-1].mPart[8] = v7;
      v5[-1].mPart[9] = tcs[-1].mPart[9];
      v5[-1].mPart[10] = tcs[-1].mPart[10];
      v5[-1].mPart[11] = tcs[-1].mPart[11];
      v5[-1].mPart[12] = tcs[-1].mPart[12];
      v5[-1].mPart[13] = tcs[-1].mPart[13];
      v5[-1].mPart[14] = tcs[-1].mPart[14];
      v5[-1].mPart[15] = tcs[-1].mPart[15];
      --v6;
    }
    while ( v6 );
    *(_OWORD *)&v5->mSet = *(_OWORD *)&tcs->mSet;
    *(_QWORD *)&v5->mMorphWeights[1] = *(_QWORD *)&tcs->mMorphWeights[1];
  }
  UFG::TrueCrowdSet::Instance::AddProxyReference(p_mTrueCrowdSignature, this);
}

// File Line: 2203
// RVA: 0x416C40
void __fastcall UFG::PedSpawningInfo::SetTrueCrowdSignatureFromCurrentSimObject(UFG::PedSpawningInfo *this)
{
  UFG::SimObjectCVBase *m_pPointer; // rbx
  const char *v2; // rdi
  UFG::SimComponent *m_pComponent; // rax
  __int16 m_Flags; // cx
  __int16 v6; // cx
  UFG::SimComponent *v7; // rax
  UFG::SceneObjectProperties *m_pSceneObj; // rax
  UFG::qPropertySet *mpWritableProperties; // rcx
  UFG::qPropertySet *v10; // rax
  char *MemImagePtr; // rax
  __int64 v12; // rcx
  __int16 v13; // cx
  UFG::SimObjectCharacterPropertiesComponent *ComponentOfType; // rax
  UFG::SimObjectGame *v15; // rcx
  bool v16; // zf
  UFG::eFactionClassEnum m_eFactionClass; // ebx
  UFG::GameStatTracker *v18; // rax
  UFG::qWiseSymbol result; // [rsp+30h] [rbp+8h] BYREF

  m_pPointer = (UFG::SimObjectCVBase *)this->mSimObjectPtr.m_pPointer;
  v2 = 0i64;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = m_pPointer->m_Components.p[10].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      if ( (m_Flags & 0x2000) != 0 )
      {
        m_pComponent = m_pPointer->m_Components.p[7].m_pComponent;
      }
      else if ( (m_Flags & 0x1000) != 0 )
      {
        m_pComponent = UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::StreamedResourceComponent::_TypeUID);
      }
      else
      {
        m_pComponent = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::StreamedResourceComponent::_TypeUID);
      }
    }
    else
    {
      m_pComponent = m_pPointer->m_Components.p[10].m_pComponent;
    }
  }
  else
  {
    m_pComponent = 0i64;
  }
  UFG::PedSpawningInfo::SetTrueCrowdSignature(
    this,
    (UFG::TrueCrowdSet::Instance *)&m_pComponent[4].m_SafePointerList.mNode.mNext);
  if ( m_pPointer )
  {
    v6 = m_pPointer->m_Flags;
    if ( (v6 & 0x4000) != 0 )
    {
      v7 = m_pPointer->m_Components.p[9].m_pComponent;
    }
    else if ( v6 >= 0 )
    {
      if ( (v6 & 0x2000) != 0 )
        v7 = m_pPointer->m_Components.p[8].m_pComponent;
      else
        v7 = (v6 & 0x1000) != 0
           ? UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::BaseAnimationComponent::_TypeUID)
           : UFG::SimObject::GetComponentOfType(m_pPointer, UFG::BaseAnimationComponent::_TypeUID);
    }
    else
    {
      v7 = m_pPointer->m_Components.p[9].m_pComponent;
    }
    if ( v7 )
    {
      this->mRigNameSymbol.mUID = UFG::qSymbol::qSymbol(&result, HIDWORD(v7[3].vfptr))->mUID;
      goto LABEL_35;
    }
  }
  m_pSceneObj = m_pPointer->m_pSceneObj;
  if ( !m_pSceneObj )
  {
    mpWritableProperties = 0i64;
LABEL_28:
    if ( !mpWritableProperties )
      goto LABEL_35;
    goto LABEL_29;
  }
  mpWritableProperties = m_pSceneObj->mpWritableProperties;
  if ( !mpWritableProperties )
  {
    mpWritableProperties = m_pSceneObj->mpConstProperties;
    goto LABEL_28;
  }
LABEL_29:
  v10 = UFG::qPropertySet::Get<UFG::qPropertySet>(
          mpWritableProperties,
          (UFG::qArray<unsigned long,0> *)&component_BaseAnimation::sPropertyName,
          DEPTH_RECURSE);
  if ( v10 )
    MemImagePtr = UFG::qPropertySet::GetMemImagePtr(v10);
  else
    MemImagePtr = 0i64;
  v12 = *((_QWORD *)MemImagePtr + 1);
  if ( v12 )
    v2 = &MemImagePtr[v12 + 8];
  this->mRigNameSymbol = (UFG::qSymbolUC)UFG::qSymbolUC::create_from_string((UFG::qSymbolUC *)&result, v2)->mUID;
LABEL_35:
  v13 = m_pPointer->m_Flags;
  if ( (v13 & 0x4000) != 0 || v13 < 0 )
  {
    ComponentOfType = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectCharacterPropertiesComponent>(m_pPointer);
  }
  else
  {
    if ( (v13 & 0x2000) != 0 )
    {
      v15 = m_pPointer;
    }
    else
    {
      v16 = (v13 & 0x1000) == 0;
      v15 = m_pPointer;
      if ( v16 )
      {
        ComponentOfType = (UFG::SimObjectCharacterPropertiesComponent *)UFG::SimObject::GetComponentOfType(
                                                                          m_pPointer,
                                                                          UFG::SimObjectCharacterPropertiesComponent::_TypeUID);
        goto LABEL_43;
      }
    }
    ComponentOfType = (UFG::SimObjectCharacterPropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                      v15,
                                                                      UFG::SimObjectCharacterPropertiesComponent::_TypeUID);
  }
LABEL_43:
  m_eFactionClass = ComponentOfType->m_eFactionClass;
  v18 = UFG::FactionInterface::Get();
  this->mFactionSymbol.mUID = UFG::FactionInterface::MapFactionToSymbol(&v18->mFactionInterface, m_eFactionClass)->mUID;
}

// File Line: 2307
// RVA: 0x4167A0
void __fastcall UFG::PedSpawningInfo::SetPropListFromCurrentSimObject(UFG::PedSpawningInfo *this)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  UFG::SimComponent *m_pComponent; // rax
  __int16 m_Flags; // dx
  Creature *v5; // rcx
  unsigned int size; // eax
  unsigned int v7; // edx
  UFG::qSymbol *p; // r8
  __int64 mNumAttachedProps; // rdx
  UFG::qSymbol *v10; // rcx
  __int64 v11; // r8
  UFG::qSymbol *v12; // rbx
  UFG::qArray<UFG::qSymbol,0> nameList; // [rsp+28h] [rbp-20h] BYREF

  m_pPointer = (UFG::SimObjectGame *)this->mSimObjectPtr.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = m_pPointer->m_Components.p[9].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      if ( (m_Flags & 0x2000) != 0 )
      {
        m_pComponent = m_pPointer->m_Components.p[8].m_pComponent;
      }
      else if ( (m_Flags & 0x1000) != 0 )
      {
        m_pComponent = UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::BaseAnimationComponent::_TypeUID);
      }
      else
      {
        m_pComponent = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::BaseAnimationComponent::_TypeUID);
      }
    }
    else
    {
      m_pComponent = m_pPointer->m_Components.p[9].m_pComponent;
    }
  }
  else
  {
    m_pComponent = 0i64;
  }
  nameList.p = 0i64;
  *(_QWORD *)&nameList.size = 0i64;
  v5 = *(Creature **)&m_pComponent[2].m_TypeUID;
  if ( v5 )
    Creature::GetResourceSystemAttachments(v5, &nameList);
  size = nameList.size;
  if ( nameList.size > 4 )
    size = 4;
  this->mNumAttachedProps = size;
  v7 = 0;
  if ( size )
  {
    p = nameList.p;
    do
    {
      this->mAttachedPropNames[v7] = p[v7];
      ++v7;
    }
    while ( v7 < this->mNumAttachedProps );
  }
  mNumAttachedProps = this->mNumAttachedProps;
  if ( (unsigned int)mNumAttachedProps < 4 )
  {
    v10 = &this->mAttachedPropNames[mNumAttachedProps];
    v11 = (unsigned int)(4 - mNumAttachedProps);
    do
    {
      v10->mUID = UFG::gNullQSymbol.mUID;
      ++v10;
      --v11;
    }
    while ( v11 );
  }
  if ( nameList.p )
  {
    v12 = nameList.p - 1;
    `eh vector destructor iterator(nameList.p, 4ui64, nameList.p[-1].mUID, (void (__fastcall *)(void *))_);
    operator delete[](v12);
  }
}

// File Line: 2559
// RVA: 0x4189F0
void __fastcall UFG::PedSpawningInfo::UpdateProxyAIandAnimation(UFG::PedSpawningInfo *this, float elapsedTime)
{
  float v3; // xmm1_4
  char v4; // al
  float mProxyTimeSinceLastAIUpdate; // xmm1_4
  float v6; // xmm1_4
  int mProxyModelHandleIndex; // eax
  int v8; // eax

  if ( !UFG::AICharacterControllerComponent::s_AIEnabled )
    return;
  if ( this->mHowSpawned == FromPoint )
    return;
  if ( this->mIsDead )
    return;
  v3 = (float)(elapsedTime * this->mProxyIndividualTimeScale) + this->mProxyTimeSinceLastAIUpdate;
  this->mProxyTimeSinceLastAIUpdate = v3;
  if ( v3 <= UFG::gGlobalProxyAIFrequencey )
    return;
  if ( this->mUpgradePOI.m_pPointer )
  {
    this->mProxyModelHandleIndex = 7;
    goto LABEL_14;
  }
  v4 = UFG::AILightWeightComponent::Update(this->mProxyAIComponent, v3, this);
  this->mTeleportOnResumeRequired = 1;
  mProxyTimeSinceLastAIUpdate = this->mProxyTimeSinceLastAIUpdate;
  this->mProxyTimeSinceLastAIUpdate = 0.0;
  v6 = mProxyTimeSinceLastAIUpdate + this->mProxyTimeSinceLastFrameUpdate;
  this->mProxyTimeSinceLastFrameUpdate = v6;
  if ( UFG::gGlobalProxyAnimSpeed >= v6 )
  {
LABEL_14:
    this->mProxyTimeSinceLastAIUpdate = 0.0;
    return;
  }
  if ( v4 )
  {
    mProxyModelHandleIndex = this->mProxyModelHandleIndex;
    if ( mProxyModelHandleIndex <= 13 )
      v8 = mProxyModelHandleIndex + 1;
    else
      v8 = 0;
    this->mProxyModelHandleIndex = v8;
  }
  this->mProxyTimeSinceLastFrameUpdate = 0.0;
  this->mProxyTimeSinceLastAIUpdate = 0.0;
}

// File Line: 2690
// RVA: 0x40A070
__int64 __fastcall UFG::PedSpawningInfo::ConvertSymbolToSuspendActionEnum(UFG::qSymbol *sSuspendActionSymbol)
{
  unsigned int mUID; // eax
  unsigned int v2; // edx

  mUID = sSuspendActionSymbol->mUID;
  v2 = 0;
  if ( sSuspendActionSymbol->mUID == qSymbol_PedSuspendOption_NoSuspend.mUID )
    return 1i64;
  if ( mUID == qSymbol_PedSuspendOption_LockActive.mUID )
    return 2i64;
  if ( mUID != qSymbol_PedSuspendOption_SuspendAllowed.mUID )
  {
    if ( mUID == qSymbol_PedSuspendOption_DeleteOnSuspend.mUID )
      return 4i64;
    if ( mUID == qSymbol_PedSuspendOption_DeleteNow.mUID )
      return 8i64;
    if ( mUID == qSymbol_PedSuspendOption_CleanUpWhenDead.mUID )
      return 16;
  }
  return v2;
}

// File Line: 2707
// RVA: 0x404DC0
void __fastcall UFG::PedSpawnManager::PedSpawnManager(UFG::PedSpawnManager *this)
{
  this->vfptr = (UFG::PedSpawnManagerVtbl *)&UFG::PedSpawnManager::`vftable;
  `eh vector constructor iterator(
    this->mAmbientPed,
    0x338ui64,
    260,
    (void (__fastcall *)(void *))UFG::PedSpawningInfo::PedSpawningInfo);
  `eh vector constructor iterator(
    this->mScriptedPed,
    0x338ui64,
    120,
    (void (__fastcall *)(void *))UFG::PedSpawningInfo::PedSpawningInfo);
  `eh vector constructor iterator(
    this->mActiveSpawnSets,
    0x38ui64,
    40,
    (void (__fastcall *)(void *))UFG::ActiveSpawnSetInfo::ActiveSpawnSetInfo);
  this->mNetRecycleCounter = 0;
  UFG::gpPedSpawnManager = this;
  UFG::PedSpawnManager::Init(this);
}

// File Line: 2724
// RVA: 0x40A4E0
void UFG::PedSpawnManager::CreateInstance(void)
{
  UFG::allocator::free_link *v0; // rax
  UFG::PedSpawnManager *v1; // rax

  v0 = UFG::qMalloc(0x4D018ui64, "PedSpawnManager", 0i64);
  if ( v0 )
  {
    UFG::PedSpawnManager::PedSpawnManager((UFG::PedSpawnManager *)v0);
    UFG::gpPedSpawnManager = v1;
  }
  else
  {
    UFG::gpPedSpawnManager = 0i64;
  }
}

// File Line: 2731
// RVA: 0x40C3C0
UFG::PedSpawnManager *__fastcall UFG::PedSpawnManager::GetInstance()
{
  return UFG::gpPedSpawnManager;
}

// File Line: 2769
// RVA: 0x40AF40
void UFG::PedSpawnManager::DryFireNearSpawnZones(void)
{
  UFG::PedSpawnManager::msDryFireNearSpawnZones = 1;
}

// File Line: 2774
// RVA: 0x416600
void __fastcall UFG::PedSpawnManager::SetAmbientSpawningEnable(bool b)
{
  UFG::PedSpawnManager::msAmbientSpawningEnable = b;
  UFG::PedSpawnManager::msCheckStatusMode = 1;
}

// File Line: 2796
// RVA: 0x416910
void __fastcall UFG::PedSpawnManager::SetScriptedStatusCheckEnable(bool b)
{
  UFG::PedSpawnManager::msScriptedStatusCheckEnable = b;
}

// File Line: 2823
// RVA: 0x416B50
void __fastcall UFG::PedSpawnManager::SetTargetPedCount(int targetPedCount)
{
  if ( targetPedCount == -1 )
    targetPedCount = 42;
  UFG::PedSpawnManager::msTargetPedCount = targetPedCount;
}

// File Line: 2844
// RVA: 0x418520
void UFG::PedSpawnManager::UpdatePedDensity(void)
{
  float v0; // xmm0_4
  float v1; // xmm1_4
  float v2; // xmm6_4
  UFG::TimeOfDayManager *Instance; // rax
  float v4; // xmm2_4
  float v5; // xmm1_4
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rbx
  __m128 x_low; // xmm2
  float v8; // xmm3_4
  float v9; // xmm2_4
  int v10; // eax
  Render::RenderOutputParams outSettings; // [rsp+20h] [rbp-88h] BYREF

  Render::RenderOutputParams::RenderOutputParams(&outSettings);
  Render::GetCurrentDisplaySettings(&outSettings);
  if ( outSettings.mLODSetting )
  {
    if ( outSettings.mLODSetting == LOD_SETTING_NORMAL )
    {
      v0 = FLOAT_40_0;
      v1 = FLOAT_95_0;
      v2 = FLOAT_0_80000001;
      UFG::gTargetPedCountDefLowSpeed = 45;
      UFG::gTargetPedCountDefHighSpeed = 35;
    }
    else if ( outSettings.mLODSetting == LOD_SETTING_EXTREME )
    {
      v0 = FLOAT_90_0;
      v1 = FLOAT_175_0;
      v2 = FLOAT_2_0;
      UFG::gTargetPedCountDefLowSpeed = 80;
      UFG::gTargetPedCountDefHighSpeed = 53;
    }
    else
    {
      v0 = FLOAT_60_0;
      v1 = FLOAT_135_0;
      UFG::gTargetPedCountDefLowSpeed = 55;
      UFG::gTargetPedCountDefHighSpeed = 40;
      v2 = *(float *)&FLOAT_1_0;
    }
  }
  else
  {
    v0 = FLOAT_35_0;
    v1 = FLOAT_85_0;
    v2 = FLOAT_0_60000002;
    UFG::gTargetPedCountDefLowSpeed = 40;
    UFG::gTargetPedCountDefHighSpeed = 30;
  }
  UFG::PedSpawnManager::msMinFullyActiveDistance = v0;
  UFG::PedSpawnManager::msMaxFullyActiveDistance = v1;
  if ( COERCE_FLOAT(COERCE_UNSIGNED_INT(UFG::PedSpawnManager::msBasePedsPerSquareMetre - 0.032000002) & _xmm) > 0.0099999998 )
    v2 = *(float *)&FLOAT_1_0;
  Instance = UFG::TimeOfDayManager::GetInstance();
  if ( Instance )
  {
    v4 = *(float *)&FLOAT_1_0;
    if ( Instance->m_WeatherState > 1.0 )
      v4 = UFG::PedSpawnManager::msPedDensityScaleRainAdjust;
    v5 = (float)(UFG::PedSpawnManager::msBasePedsPerSquareMetre * v4)
       * UFG::PedSpawnManager::msPedDensityScaleTimeTable[(float)(Instance->m_SecondsSinceMidnight * 0.00027777778)];
  }
  else
  {
    v5 = UFG::PedSpawnManager::msPedsPerSquareMetre;
  }
  UFG::PedSpawnManager::msPedsPerSquareMetre = v5 * (float)(UFG::PedSpawnManager::msPedDensityScaleCopSystemAdjust * v2);
  if ( LocalPlayer )
  {
    m_pTransformNodeComponent = LocalPlayer->m_pTransformNodeComponent;
    if ( m_pTransformNodeComponent )
    {
      UFG::TransformNodeComponent::UpdateWorldTransform(LocalPlayer->m_pTransformNodeComponent);
      x_low = (__m128)LODWORD(m_pTransformNodeComponent->mWorldVelocity.x);
      x_low.m128_f32[0] = (float)((float)(x_low.m128_f32[0] * x_low.m128_f32[0])
                                + (float)(m_pTransformNodeComponent->mWorldVelocity.y
                                        * m_pTransformNodeComponent->mWorldVelocity.y))
                        + (float)(m_pTransformNodeComponent->mWorldVelocity.z
                                * m_pTransformNodeComponent->mWorldVelocity.z);
      v8 = (float)(_mm_sqrt_ps(x_low).m128_f32[0] - 5.0) * 0.043478262;
      if ( v8 <= 0.0 )
      {
        v9 = 0.0;
      }
      else
      {
        v9 = v8;
        if ( v8 >= 1.0 )
          v9 = *(float *)&FLOAT_1_0;
      }
      v10 = (int)(float)((float)((float)((float)UFG::gTargetPedCountDefHighSpeed - (float)UFG::gTargetPedCountDefLowSpeed)
                               * v9)
                       + (float)UFG::gTargetPedCountDefLowSpeed);
      if ( v10 == -1 )
        v10 = 42;
      UFG::PedSpawnManager::msTargetPedCount = v10;
      if ( v8 <= 0.0 )
      {
        v8 = 0.0;
      }
      else if ( v8 >= 1.0 )
      {
        v8 = *(float *)&FLOAT_1_0;
      }
      UFG::PedSpawnManager::msPedsPerSquareMetre = UFG::PedSpawnManager::msPedsPerSquareMetre
                                                 * (float)(1.0 - (float)(v8 * 0.75));
    }
  }
}

// File Line: 2946
// RVA: 0x407680
void __fastcall UFG::PedSpawnManager::AdjustPedDensity(float d)
{
  UFG::PedSpawnManager::msBasePedsPerSquareMetre = d * 0.032000002;
}

// File Line: 2954
// RVA: 0x418460
void UFG::PedSpawnManager::UpdateDensityOfActiveZones(void)
{
  UFG::PedSpawnManager::msForceDensityUpdateCount = 63;
}

// File Line: 2959
// RVA: 0x407670
void __fastcall UFG::PedSpawnManager::AdjustCopSystemDensityModifier(float d)
{
  UFG::PedSpawnManager::msPedDensityScaleCopSystemAdjust = d;
}

// File Line: 2964
// RVA: 0x4076A0
void __fastcall UFG::PedSpawnManager::AdjustSpawnPointDensityModifier(float d)
{
  UFG::PedSpawnManager::msPedDensityScaleSpawnPointAdjust = d;
}

// File Line: 2970
// RVA: 0x4075A0
void __fastcall UFG::PedSpawnManager::AddZoneToThugSpawningExceptionsArrary(
        UFG::PedSpawnManager *this,
        UFG::SpawnZone *pZone)
{
  _DWORD *mpRegion; // rax
  unsigned int v3; // ebx
  float v4; // xmm1_4
  int v5; // r14d
  char v6; // bp
  UFG::qSymbol *v7; // rdi
  int i; // esi

  mpRegion = pZone->mpRegion;
  if ( !mpRegion )
    mpRegion = pZone->mpPoint;
  v3 = mpRegion[16];
  v4 = UFG::PedSpawnManager::msElapsedTotal;
  v5 = -1;
  v6 = 0;
  v7 = &UFG::PedSpawnManager::msDisabledThugZones;
  for ( i = 0; i < 10; ++i )
  {
    if ( v7->mUID == -1 )
    {
      v5 = i;
    }
    else
    {
      if ( (float)(v4 - *(float *)&v7[1].mUID) >= 900.0 )
      {
        UFG::qSymbol::set_null(v7);
        v7[1].mUID = 0;
        v4 = UFG::PedSpawnManager::msElapsedTotal;
      }
      if ( v7->mUID == v3 )
        v6 = 1;
    }
    v7 += 2;
  }
  if ( v5 >= 0 && !v6 )
  {
    *(&UFG::PedSpawnManager::msDisabledThugZones.mUID + 2 * v5) = v3;
    *((float *)&UFG::PedSpawnManager::msDisabledThugZones + 2 * v5 + 1) = v4;
  }
}

// File Line: 3008
// RVA: 0x417C10
__int64 __fastcall UFG::PedSpawnManager::ThugZoneDisabled(UFG::PedSpawnManager *this, UFG::SpawnZone *pZone)
{
  __int64 v2; // rsi
  unsigned __int8 v3; // di
  UFG::qSymbol *v5; // rbx
  _DWORD *mpRegion; // rax

  v2 = 10i64;
  v3 = 0;
  v5 = &UFG::PedSpawnManager::msDisabledThugZones;
  do
  {
    if ( v5->mUID != -1 )
    {
      if ( (float)(UFG::PedSpawnManager::msElapsedTotal - *(float *)&v5[1].mUID) < 900.0 )
      {
        mpRegion = pZone->mpRegion;
        if ( !mpRegion )
          mpRegion = pZone->mpPoint;
        if ( v5->mUID == mpRegion[16] )
          v3 = 1;
      }
      else
      {
        UFG::qSymbol::set_null(v5);
        v5[1].mUID = 0;
      }
    }
    v5 += 2;
    --v2;
  }
  while ( v2 );
  return v3;
}

// File Line: 3063
// RVA: 0x40AF60
void __fastcall UFG::PedSpawnManager::ExamineActiveZones(UFG::PedSpawnManager *this)
{
  UFG::TimeOfDayManager *Instance; // rax
  int v3; // r12d
  UFG::qNode<UFG::PedSpawningInfo,UFG::PedSpawningInfo_DrawList> **p_mNext; // rsi
  _DWORD *v5; // r14
  UFG::qNode<UFG::PedSpawningInfo,UFG::PedSpawningInfo_DrawList> **v6; // rbx
  int v7; // ebp
  int v8; // eax
  UFG::qNode<UFG::PedSpawningInfo,UFG::PedSpawningInfo_DrawList> *v9; // rcx
  UFG::qNode<UFG::PedSpawningInfo,UFG::PedSpawningInfo_DrawList> *v10; // rax
  UFG::qNode<UFG::SpawnZone,UFG::SpawnZoneList> *mNext; // rax
  bool v12; // zf
  int v13; // ecx
  UFG::qVector3 *ViewerPosition; // rax

  Instance = UFG::TimeOfDayManager::GetInstance();
  ++update_counter;
  v3 = (int)(float)(Instance->m_SecondsSinceMidnight * 0.00027777778);
  if ( UFG::PedSpawnManager::msForceDensityUpdateCount >= 0 )
    --UFG::PedSpawnManager::msForceDensityUpdateCount;
  if ( UFG::GetLocalPlayer() )
  {
    UFG::PedSpawnManager::msNumValidTopUpZones = 0;
    this->mTargetNumActive = 0;
    p_mNext = (UFG::qNode<UFG::PedSpawningInfo,UFG::PedSpawningInfo_DrawList> **)&UFG::PedSpawnManager::msActiveZoneList.mNode.mNext[-2].mNext;
    while ( p_mNext != &UFG::PedSpawningInfo::smNoDrawList.mNode.mNext )
    {
      v5 = p_mNext + 17;
      v6 = p_mNext;
      v7 = *((_DWORD *)p_mNext + 34);
      this->mTargetNumActive += v7;
      p_mNext = &p_mNext[4][-2].mNext;
      if ( *((_BYTE *)v6 + 112) )
      {
        v8 = *((_DWORD *)v6 + 33);
        if ( UFG::PedSpawnManager::msForceDensityUpdateCount < 0 )
        {
          if ( (((unsigned __int8)update_counter ^ (unsigned __int8)v8) & 0x3F) == 0 )
            UFG::SpawnRegion::UpdateSpawnSetAndDenisty((UFG::SpawnRegion *)v6[8], v3);
        }
        else if ( (((unsigned __int8)UFG::PedSpawnManager::msForceDensityUpdateCount ^ (unsigned __int8)v8) & 0x3F) == 0 )
        {
          UFG::PedSpawnManager::UpdateActiveSpawnRegion(this, (UFG::SpawnRegion *)v6[8], 1);
        }
        if ( (float)(UFG::PedSpawnManager::msElapsedTotal - *((float *)v6 + 29)) > 2.2 )
        {
          if ( UFG::SpawnZone::ShouldSpawnZoneDeactivate((UFG::SpawnZone *)v6) )
          {
            this->mTargetNumActive -= *v5;
            *((_DWORD *)v6 + 14) = 1;
            v9 = v6[3];
            v10 = v6[4];
            v9->mNext = v10;
            v10->mPrev = v9;
            v6[3] = (UFG::qNode<UFG::PedSpawningInfo,UFG::PedSpawningInfo_DrawList> *)(v6 + 3);
            v6[4] = (UFG::qNode<UFG::PedSpawningInfo,UFG::PedSpawningInfo_DrawList> *)(v6 + 3);
            mNext = UFG::PedSpawnManager::msSpawnZoneList.mNode.mNext;
            UFG::PedSpawnManager::msSpawnZoneList.mNode.mNext = (UFG::qNode<UFG::SpawnZone,UFG::SpawnZoneList> *)(v6 + 3);
            v6[4] = (UFG::qNode<UFG::PedSpawningInfo,UFG::PedSpawningInfo_DrawList> *)mNext;
            v6[3] = (UFG::qNode<UFG::PedSpawningInfo,UFG::PedSpawningInfo_DrawList> *)&UFG::PedSpawnManager::msSpawnZoneList;
            mNext->mPrev = (UFG::qNode<UFG::SpawnZone,UFG::SpawnZoneList> *)(v6 + 3);
            *((float *)v6 + 29) = UFG::PedSpawnManager::msElapsedTotal;
            v12 = *((_BYTE *)v6 + 114) == 0;
            *((_DWORD *)v6 + 31) = -1082130432;
            if ( !v12 && *((_DWORD *)v6 + 36) >= *v5 )
              UFG::PedSpawnManager::AddZoneToThugSpawningExceptionsArrary(this, (UFG::SpawnZone *)v6);
          }
          else if ( UFG::PedSpawnManager::msNumValidTopUpZones < 25
                 && UFG::SpawnZone::IsValidForTopUpSpawning((UFG::SpawnZone *)v6) )
          {
            v13 = UFG::PedSpawnManager::msNumValidTopUpZones;
            UFG::PedSpawnManager::msValidTopUpZones[UFG::PedSpawnManager::msNumValidTopUpZones] = (UFG::SpawnZone *)v6;
            UFG::PedSpawnManager::msNumValidTopUpZones = v13 + 1;
            *((_DWORD *)v6 + 14) = 2;
          }
          else
          {
            *((_DWORD *)v6 + 14) = 3;
          }
        }
      }
      else
      {
        ViewerPosition = UFG::SectionChooser::GetViewerPosition();
        if ( (float)((float)((float)((float)(ViewerPosition->y - *((float *)v6 + 39))
                                   * (float)(ViewerPosition->y - *((float *)v6 + 39)))
                           + (float)((float)(ViewerPosition->x - *((float *)v6 + 38))
                                   * (float)(ViewerPosition->x - *((float *)v6 + 38))))
                   + (float)((float)(ViewerPosition->z - *((float *)v6 + 40))
                           * (float)(ViewerPosition->z - *((float *)v6 + 40)))) > 4225.0 )
          this->mTargetNumActive -= v7;
      }
    }
  }
}

// File Line: 3189
// RVA: 0x418AF0
bool __fastcall UFG::ZoneSortCompare(UFG::SpawnZone *a, UFG::SpawnZone *b)
{
  return a->mDistSquareToCamera <= b->mDistSquareToCamera;
}

// File Line: 3194
// RVA: 0x4136F0
void __fastcall UFG::PedSpawnManager::ProcessZonesDueToSpawn(UFG::PedSpawnManager *this)
{
  UFG::PedSpawnManager *v1; // r14
  UFG::CopSystem *v2; // rax
  char v3; // bl
  UFG::qNode<UFG::SpawnZone,UFG::SpawnZoneList> **p_mNext; // r13
  int v5; // r15d
  UFG::qNode<UFG::SpawnZone,UFG::SpawnZoneList> **v6; // r12
  UFG::SpawnZone *v7; // rsi
  UFG::qNode<UFG::SpawnZone,UFG::SpawnZoneList> *v8; // rdi
  UFG::qNode<UFG::SpawnZone,UFG::SpawnZoneList> *v9; // rcx
  UFG::qNode<UFG::SpawnZone,UFG::SpawnZoneList> *v10; // rax
  UFG::qNode<UFG::SpawnZone,UFG::SpawnZoneList> *v11; // rax
  float v12; // xmm1_4
  int v13; // r13d
  int mSpawnCount; // ebx
  char v15; // di
  UFG::qNode<UFG::SpawnZone,UFG::SpawnZoneList> *mCullResults; // rdx
  float v17; // xmm1_4
  int v18; // ebp
  UFG::GroupManager *Instance; // rax
  int v20; // r15d
  unsigned int v21; // r12d
  UFG::qPropertySet *SpawnableResource; // rdi
  int v23; // eax
  UFG::PedSpawningInfo *v24; // rax
  float y; // xmm1_4
  float z; // xmm2_4
  UFG::SimObject *m_pPointer; // rbx
  UFG::InterestPoint *InterestPoint; // rbp
  UFG::SimComponent *ComponentOfType; // rdi
  UFG::InterestPointUserComponent *v30; // r14
  UFG::allocator::free_link *v31; // rax
  UFG::SimObjectCharacter *AmbientPedForVehicle; // rbp
  UFG::PedSpawningInfo *v33; // rbx
  UFG::qSafePointer<UFG::SpawnZone,UFG::SpawnZone> *p_mCreationSpawnZone; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SpawnZone>,UFG::qSafePointerNodeList> *v35; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SpawnZone>,UFG::qSafePointerNodeList> *v36; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SpawnZone>,UFG::qSafePointerNodeList> *v37; // rax
  UFG::SimComponent *mpInterestPoint; // r8
  UFG::qSafePointer<UFG::SimComponent,UFG::InterestPoint> *p_mUpgradePOI; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v40; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v41; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v42; // rax
  UFG::ActiveAIEntityComponent *v43; // rax
  UFG::InterestPointUserComponent *m_pComponent; // r14
  UFG::allocator::free_link *v45; // rax
  UFG::qNode<UFG::SpawnZone,UFG::SpawnZoneList> *v46; // rcx
  UFG::qNode<UFG::SpawnZone,UFG::SpawnZoneList> *v47; // rax
  UFG::qNode<UFG::SpawnZone,UFG::SpawnZoneList> *v48; // rax
  UFG::qNode<UFG::SpawnZone,UFG::SpawnZoneList> *m_pSimObject; // rcx
  UFG::SceneObjectProperties *mPrev; // rcx
  UFG::SceneObjectProperties *ChildAsSceneObject; // rax
  UFG::qNode<UFG::SpawnZone,UFG::SpawnZoneList> *v52; // rcx
  UFG::qNode<UFG::SpawnZone,UFG::SpawnZoneList> *mNext; // rax
  UFG::qNode<UFG::SpawnZone,UFG::SpawnZoneList> *v54; // rax
  UFG::SimObjectGame *v55; // rbx
  UFG::qNode<UFG::SpawnZone,UFG::SpawnZoneList> *v56; // rcx
  UFG::qNode<UFG::SpawnZone,UFG::SpawnZoneList> *v57; // rax
  UFG::qNode<UFG::SpawnZone,UFG::SpawnZoneList> *v58; // rax
  int v59; // [rsp+30h] [rbp-E8h]
  int v60; // [rsp+34h] [rbp-E4h]
  UFG::qVector3 newPoint; // [rsp+38h] [rbp-E0h] BYREF
  UFG::qSymbol skipIntoLabel; // [rsp+48h] [rbp-D0h] BYREF
  UFG::qSymbol v63; // [rsp+4Ch] [rbp-CCh] BYREF
  UFG::qNode<UFG::SpawnZone,UFG::SpawnZoneList> **v64; // [rsp+50h] [rbp-C8h]
  UFG::qNode<UFG::SpawnZone,UFG::SpawnZoneList> **v65; // [rsp+58h] [rbp-C0h]
  UFG::allocator::free_link *v66; // [rsp+60h] [rbp-B8h]
  __int64 v67; // [rsp+68h] [rbp-B0h]
  UFG::qMatrix44 outputMatrix; // [rsp+70h] [rbp-A8h] BYREF
  UFG::PedSpawningInfo *newPedInfo; // [rsp+128h] [rbp+10h] BYREF
  char v71; // [rsp+130h] [rbp+18h]
  int v72; // [rsp+138h] [rbp+20h]

  v67 = -2i64;
  v1 = this;
  UFG::qList<UFG::SpawnZone,UFG::SpawnZoneList,1,0>::MergeSort(
    &UFG::PedSpawnManager::msShouldBeActiveZoneList,
    UFG::ZoneSortCompare);
  v2 = UFG::CopSystem::Instance();
  v3 = UFG::CopSystem::AllowSpawnRegionSpawning(v2);
  v71 = v3;
  p_mNext = &UFG::PedSpawnManager::msShouldBeActiveZoneList.mNode.mNext[-2].mNext;
  v5 = 0;
  v72 = 0;
  v6 = (UFG::qNode<UFG::SpawnZone,UFG::SpawnZoneList> **)&UFG::PedSpawnManager::msShouldBeActiveZoneList - 3;
  v64 = (UFG::qNode<UFG::SpawnZone,UFG::SpawnZoneList> **)&UFG::PedSpawnManager::msShouldBeActiveZoneList - 3;
  if ( &UFG::PedSpawnManager::msShouldBeActiveZoneList.mNode.mNext[-2].mNext != (UFG::qNode<UFG::SpawnZone,UFG::SpawnZoneList> **)((char *)&UFG::PedSpawnManager::msShouldBeActiveZoneList - 24) )
  {
    while ( 1 )
    {
      if ( v5 >= UFG::gZoneSpawnsPerFrame )
      {
        UFG::PedSpawnManager::msDryFireNearSpawnZones = 0;
        return;
      }
      v7 = (UFG::SpawnZone *)p_mNext;
      v8 = (UFG::qNode<UFG::SpawnZone,UFG::SpawnZoneList> *)(p_mNext + 3);
      p_mNext = &p_mNext[4][-2].mNext;
      v65 = p_mNext;
      if ( UFG::PedSpawnManager::msDryFireNearSpawnZones )
        goto LABEL_65;
      if ( !v7->mIsRegion )
      {
        if ( !v7->mpInterestPoint )
        {
          m_pSimObject = (UFG::qNode<UFG::SpawnZone,UFG::SpawnZoneList> *)v7->mpPoint->m_pSimObject;
          if ( m_pSimObject )
            mPrev = (UFG::SceneObjectProperties *)m_pSimObject[5].mPrev;
          else
            mPrev = 0i64;
          ChildAsSceneObject = UFG::SceneObjectProperties::GetChildAsSceneObject(mPrev, 0);
          if ( PropertyUtils::HasComponentPropertySet(
                 ChildAsSceneObject,
                 (UFG::qArray<unsigned long,0> *)&SimSymX_propset_componentCopUnit)
            && v3
            || v7->mIsThugZone && UFG::PedSpawnManager::ThugZoneDisabled(v1, v7) )
          {
            v52 = v8->mPrev;
            mNext = v8->mNext;
            v52->mNext = mNext;
            mNext->mPrev = v52;
            v8->mPrev = v8;
            v8->mNext = v8;
            v54 = UFG::PedSpawnManager::msActiveZoneList.mNode.mNext;
            UFG::PedSpawnManager::msActiveZoneList.mNode.mNext = v8;
            v8->mPrev = (UFG::qNode<UFG::SpawnZone,UFG::SpawnZoneList> *)&UFG::PedSpawnManager::msActiveZoneList;
            v8->mNext = v54;
            v54->mPrev = v8;
            v7->mZoneActiveStatus = ZoneActive;
            v7->mTimeStamp = UFG::PedSpawnManager::msElapsedTotal;
          }
          else
          {
            UFG::PedSpawnManager::msZoneDoingSpawnNow = v7;
            v1->mSpawningModeNow = FromPoint;
            v55 = UFG::SpawnPoint::Spawn(v7->mpPoint, 0, 0);
            UFG::SpawnPoint::UpdateLinks(v7->mpPoint, 0);
            if ( v55 || v7->mpPoint->mSkipSpawnChancePercent || v7->mRetryTime >= 0.0 )
            {
              v56 = v8->mPrev;
              v57 = v8->mNext;
              v56->mNext = v57;
              v57->mPrev = v56;
              v8->mPrev = v8;
              v8->mNext = v8;
              v58 = UFG::PedSpawnManager::msActiveZoneList.mNode.mNext;
              UFG::PedSpawnManager::msActiveZoneList.mNode.mNext = v8;
              v8->mPrev = (UFG::qNode<UFG::SpawnZone,UFG::SpawnZoneList> *)&UFG::PedSpawnManager::msActiveZoneList;
              v8->mNext = v58;
              v58->mPrev = v8;
              v7->mZoneActiveStatus = ZoneActive;
              v7->mTimeStamp = UFG::PedSpawnManager::msElapsedTotal;
              v72 = ++v5;
            }
            else
            {
              v7->mRetryTime = UFG::PedSpawnManager::msElapsedTotal + 1.25;
            }
            v1->mSpawningModeNow = FromRegion;
          }
          UFG::PedSpawnManager::msZoneDoingSpawnNow = 0i64;
          goto LABEL_81;
        }
        newPedInfo = 0i64;
        AmbientPedForVehicle = UFG::PedSpawnManager::GetAmbientPedForVehicle(v1, 0i64, 0i64, &newPedInfo);
        if ( AmbientPedForVehicle )
        {
          v33 = newPedInfo;
          p_mCreationSpawnZone = &newPedInfo->mCreationSpawnZone;
          if ( newPedInfo->mCreationSpawnZone.m_pPointer )
          {
            v35 = p_mCreationSpawnZone->mPrev;
            v36 = newPedInfo->mCreationSpawnZone.mNext;
            v35->mNext = v36;
            v36->mPrev = v35;
            p_mCreationSpawnZone->mPrev = p_mCreationSpawnZone;
            p_mCreationSpawnZone->mNext = p_mCreationSpawnZone;
          }
          p_mCreationSpawnZone->m_pPointer = v7;
          v37 = v7->m_SafePointerList.mNode.UFG::qSafePointerNode<UFG::SpawnZone>::mPrev;
          v37->mNext = p_mCreationSpawnZone;
          p_mCreationSpawnZone->mPrev = v37;
          p_mCreationSpawnZone->mNext = &v7->m_SafePointerList.mNode;
          v7->m_SafePointerList.mNode.UFG::qSafePointerNode<UFG::SpawnZone>::mPrev = p_mCreationSpawnZone;
          mpInterestPoint = v7->mpInterestPoint;
          p_mUpgradePOI = &v33->mUpgradePOI;
          if ( v33->mUpgradePOI.m_pPointer )
          {
            v40 = p_mUpgradePOI->mPrev;
            v41 = v33->mUpgradePOI.mNext;
            v40->mNext = v41;
            v41->mPrev = v40;
            p_mUpgradePOI->mPrev = p_mUpgradePOI;
            v33->mUpgradePOI.mNext = &v33->mUpgradePOI;
          }
          v33->mUpgradePOI.m_pPointer = mpInterestPoint;
          if ( mpInterestPoint )
          {
            v42 = mpInterestPoint->m_SafePointerList.mNode.mPrev;
            v42->mNext = p_mUpgradePOI;
            p_mUpgradePOI->mPrev = v42;
            v33->mUpgradePOI.mNext = &mpInterestPoint->m_SafePointerList.mNode;
            mpInterestPoint->m_SafePointerList.mNode.mPrev = p_mUpgradePOI;
          }
          v43 = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>(AmbientPedForVehicle);
          m_pComponent = (UFG::InterestPointUserComponent *)AmbientPedForVehicle->m_Components.p[43].m_pComponent;
          if ( m_pComponent && v43 )
          {
            UFG::GetInterestPointUpRightMatrix((UFG::InterestPoint *)v33->mUpgradePOI.m_pPointer, &outputMatrix);
            v45 = UFG::qMalloc(0x90ui64, "TeleportEvent", 0i64);
            newPedInfo = (UFG::PedSpawningInfo *)v45;
            if ( v45 )
              UFG::TeleportEvent::TeleportEvent(
                (UFG::TeleportEvent *)v45,
                &outputMatrix,
                AmbientPedForVehicle->mNode.mUID,
                0,
                UFG::TeleportEvent::m_Name,
                0);
            UFG::EventDispatcher::DispatchEvent(&UFG::EventDispatcher::mInstance, (UFG::Event *)v45);
            v63.mUID = qSymbol_Link.mUID;
            UFG::InterestPointUserComponent::UsePOI(
              m_pComponent,
              (UFG::InterestPoint *)v33->mUpgradePOI.m_pPointer,
              ePOIUseType_Script,
              &v63);
          }
          v33->mLockActiveFrameCount = 10;
          v72 = ++v5;
          v1 = this;
        }
LABEL_65:
        v46 = v8->mPrev;
        v47 = v8->mNext;
        v46->mNext = v47;
        v47->mPrev = v46;
        v8->mPrev = v8;
        v8->mNext = v8;
        v48 = UFG::PedSpawnManager::msActiveZoneList.mNode.mNext;
        UFG::PedSpawnManager::msActiveZoneList.mNode.mNext = v8;
        v8->mPrev = (UFG::qNode<UFG::SpawnZone,UFG::SpawnZoneList> *)&UFG::PedSpawnManager::msActiveZoneList;
        v8->mNext = v48;
        v48->mPrev = v8;
        v7->mZoneActiveStatus = ZoneActive;
        v7->mTimeStamp = UFG::PedSpawnManager::msElapsedTotal;
        goto LABEL_81;
      }
      v9 = v8->mPrev;
      v10 = v8->mNext;
      v9->mNext = v10;
      v10->mPrev = v9;
      v8->mPrev = v8;
      v8->mNext = v8;
      v11 = UFG::PedSpawnManager::msActiveZoneList.mNode.mNext;
      UFG::PedSpawnManager::msActiveZoneList.mNode.mNext = v8;
      v8->mPrev = (UFG::qNode<UFG::SpawnZone,UFG::SpawnZoneList> *)&UFG::PedSpawnManager::msActiveZoneList;
      v8->mNext = v11;
      v11->mPrev = v8;
      v7->mZoneActiveStatus = ZoneActive;
      if ( !v7->mHasBeenActivated )
        break;
      v12 = UFG::PedSpawnManager::msElapsedTotal;
      if ( (float)(UFG::PedSpawnManager::msElapsedTotal - v7->mTimeStamp) > 5.0 )
        break;
LABEL_50:
      v7->mTimeStamp = v12;
LABEL_81:
      v3 = v71;
      if ( p_mNext == v6 )
        goto LABEL_84;
    }
    if ( v7->mIsThugZone && UFG::PedSpawnManager::ThugZoneDisabled(v1, v7) )
    {
      v13 = 0;
LABEL_49:
      v5 += v13;
      v72 = v5;
      v1->mTargetNumActive += v7->mSpawnCount;
      v12 = UFG::PedSpawnManager::msElapsedTotal;
      p_mNext = v65;
      goto LABEL_50;
    }
    v7->mHasBeenActivated = 1;
    mSpawnCount = v7->mSpawnCount;
    v60 = mSpawnCount;
    if ( v7->mAliveCountValidationTag == UFG::Metrics::msFrameCount )
    {
      if ( v7->mIsThugZone )
      {
        if ( v7->mAliveCount > 0 )
        {
          v13 = 0;
          goto LABEL_49;
        }
      }
      else if ( v7->mAliveCount >= mSpawnCount )
      {
        v13 = 0;
        goto LABEL_49;
      }
    }
    v15 = 0;
    LOBYTE(newPedInfo) = 0;
    mCullResults = (UFG::qNode<UFG::SpawnZone,UFG::SpawnZoneList> *)v7->mCullResults;
    if ( mCullResults && (gMainCullIndex < 0 || *((_BYTE *)&mCullResults->mPrev + gMainCullIndex) <= 1u) )
    {
      if ( gMainCullIndex >= 6 )
        v17 = 0.0;
      else
        v17 = *((float *)&mCullResults[1].mPrev + gMainCullIndex);
      v15 = (float)(UFG::PedSpawnManager::msWorkingFullyActiveDistance * 0.75) > v17;
      LOBYTE(newPedInfo) = v15;
    }
    v13 = 0;
    if ( mSpawnCount )
    {
      v18 = mSpawnCount;
      v59 = mSpawnCount;
      if ( UFG::SpawnRegion::IsGroupsAllowed(v7->mpRegion) )
      {
        Instance = UFG::GroupManager::GetInstance();
        v18 = mSpawnCount - UFG::GroupManager::GetNumGroupMembersToSpawn(Instance, mSpawnCount);
        v59 = v18;
      }
      v20 = 0;
      if ( mSpawnCount > 0 )
      {
        v21 = mSpawnCount;
        do
        {
          if ( 260 - UFG::PedSpawnManager::msAmbientCount[0] >= 245 )
          {
            UFG::PedSpawnManager::MakeRoomForMorePeds(v1, v21, v15);
            if ( 260 - UFG::PedSpawnManager::msAmbientCount[0] >= 245 )
              break;
          }
          UFG::SpawnZone::CalcSpawnPoint(v7, &newPoint);
          SpawnableResource = UFG::SpawnRegion::GetSpawnableResource(v7->mpRegion, 1, &newPoint);
          if ( SpawnableResource )
          {
            UFG::PedSpawnManager::msZoneDoingSpawnNow = v7;
            v23 = 260
                - UFG::PedSpawnManager::msAmbientCount[0]
                + 120
                - UFG::PedSpawnManager::msScriptedCount[0]
                - UFG::gMaxTotalFullSimPeds;
            if ( 260 - UFG::PedSpawnManager::msAmbientCount[0] - UFG::gMaxAmbientSimObjects > v23 )
              v23 = 260 - UFG::PedSpawnManager::msAmbientCount[0] - UFG::gMaxAmbientSimObjects;
            if ( v23 + 1 <= 0 )
            {
              if ( UFG::SpawnRegion::Spawn(v7->mpRegion, 1, &newPoint, 0) )
              {
                ++v13;
                v24 = UFG::PedSpawnManager::msLastRegisteredPedInfo;
                y = newPoint.y;
                z = newPoint.z;
                UFG::PedSpawnManager::msLastRegisteredPedInfo->mCurrentLocation.x = newPoint.x;
                v24->mCurrentLocation.y = y;
                v24->mCurrentLocation.z = z;
                if ( v18 > 0
                  && !UFG::PedSpawnManager::msLastRegisteredPedInfo->mCharacterOccupantComponent.m_pSimComponent )
                {
                  m_pPointer = UFG::PedSpawnManager::msLastRegisteredPedInfo->mSimObjectPtr.m_pPointer;
                  InterestPoint = UFG::SpawnRegion::GetInterestPoint(
                                    v7->mpRegion,
                                    &newPoint,
                                    SpawnableResource,
                                    v20 + 1,
                                    m_pPointer);
                  if ( InterestPoint )
                  {
                    ComponentOfType = UFG::SimObject::GetComponentOfType(
                                        m_pPointer,
                                        UFG::ActiveAIEntityComponent::_TypeUID);
                    v30 = (UFG::InterestPointUserComponent *)UFG::SimObject::GetComponentOfType(
                                                               m_pPointer,
                                                               UFG::InterestPointUserComponent::_TypeUID);
                    if ( v30 && ComponentOfType )
                    {
                      --v59;
                      UFG::GetInterestPointUpRightMatrix(InterestPoint, &outputMatrix);
                      v31 = UFG::qMalloc(0x90ui64, "TeleportEvent", 0i64);
                      v66 = v31;
                      if ( v31 )
                        UFG::TeleportEvent::TeleportEvent(
                          (UFG::TeleportEvent *)v31,
                          &outputMatrix,
                          m_pPointer->mNode.mUID,
                          0,
                          UFG::TeleportEvent::m_Name,
                          0);
                      UFG::EventDispatcher::DispatchEvent(&UFG::EventDispatcher::mInstance, (UFG::Event *)v31);
                      skipIntoLabel.mUID = -1;
                      UFG::InterestPointUserComponent::UsePOI(v30, InterestPoint, ePOIUseType_Script, &skipIntoLabel);
                    }
                    v1 = this;
                  }
                  mSpawnCount = v60;
                }
              }
            }
            UFG::PedSpawnManager::msZoneDoingSpawnNow = 0i64;
          }
          ++v20;
          --v21;
          v18 = v59;
          v15 = (char)newPedInfo;
        }
        while ( v20 < mSpawnCount );
        v6 = v64;
      }
      v5 = v72;
    }
    goto LABEL_49;
  }
LABEL_84:
  UFG::PedSpawnManager::msDryFireNearSpawnZones = 0;
}

// File Line: 3424
// RVA: 0x40B1D0
void __fastcall UFG::PedSpawnManager::ExamineInactiveZones(UFG::PedSpawnManager *this)
{
  UFG::TimeOfDayManager *Instance; // rax
  unsigned __int8 v3; // dl
  float v4; // xmm0_4
  UFG::qList<UFG::SpawnZone,UFG::SpawnZoneList,1,0> *p_mNext; // rdi
  int v6; // r12d
  UFG::qList<UFG::SpawnZone,UFG::SpawnZoneList,1,0> *v7; // rbx
  int mPrev_high; // eax
  bool v9; // si
  UFG::qNode<UFG::SpawnZone,UFG::SpawnZoneList> *mNext; // rax
  float v11; // xmm1_4
  float v12; // xmm2_4
  UFG::qMatrix44 *v13; // rcx
  float v14; // xmm1_4
  float v15; // xmm2_4
  UFG::qMatrix44 *v16; // rax
  UFG::qVector4 v17; // xmm2
  UFG::qVector4 v18; // xmm1
  UFG::qVector4 v19; // xmm0
  NISManager *v20; // rax
  UFG::qNode<UFG::SpawnZone,UFG::SpawnZoneList> *v21; // rcx
  UFG::qNode<UFG::SpawnZone,UFG::SpawnZoneList> *mPrev; // rax
  UFG::qNode<UFG::SpawnZone,UFG::SpawnZoneList> *v23; // rdx
  UFG::qNode<UFG::SpawnZone,UFG::SpawnZoneList> *v24; // rax
  UFG::qNode<UFG::SpawnZone,UFG::SpawnZoneList> *v25; // rcx
  UFG::qNode<UFG::SpawnZone,UFG::SpawnZoneList> *v26; // rax
  UFG::qNode<UFG::SpawnZone,UFG::SpawnZoneList> *v27; // rax
  UFG::qVector3 min; // [rsp+10h] [rbp-49h] BYREF
  UFG::qVector3 max; // [rsp+20h] [rbp-39h] BYREF
  UFG::qBox box; // [rsp+30h] [rbp-29h] BYREF
  UFG::qMatrix44 m; // [rsp+50h] [rbp-9h] BYREF

  Instance = UFG::TimeOfDayManager::GetInstance();
  v3 = update_counter_0 + 1;
  v4 = Instance->m_SecondsSinceMidnight * 0.00027777778;
  p_mNext = (UFG::qList<UFG::SpawnZone,UFG::SpawnZoneList,1,0> *)&UFG::PedSpawnManager::msSpawnZoneList.mNode.mNext[-2].mNext;
  ++update_counter_0;
  v6 = (int)v4;
  if ( &UFG::PedSpawnManager::msSpawnZoneList.mNode.mNext[-2].mNext != (UFG::qNode<UFG::SpawnZone,UFG::SpawnZoneList> **)((char *)&UFG::PedSpawnManager::msSpawnZoneList - 24) )
  {
    while ( 1 )
    {
      v7 = p_mNext;
      p_mNext = (UFG::qList<UFG::SpawnZone,UFG::SpawnZoneList,1,0> *)&p_mNext[2].mNode.mPrev[-2].mNext;
      if ( !LOBYTE(v7[7].mNode.mPrev) )
        break;
      mPrev_high = HIDWORD(v7[8].mNode.mPrev);
      if ( UFG::PedSpawnManager::msForceDensityUpdateCount < 0 )
      {
        if ( ((v3 ^ (unsigned __int8)mPrev_high) & 0x3F) == 0 )
          UFG::SpawnRegion::UpdateSpawnSetAndDenisty((UFG::SpawnRegion *)v7[4].mNode.mPrev, v6);
      }
      else if ( (((unsigned __int8)UFG::PedSpawnManager::msForceDensityUpdateCount ^ (unsigned __int8)mPrev_high) & 0x3F) == 0 )
      {
        UFG::PedSpawnManager::UpdateActiveSpawnRegion(this, (UFG::SpawnRegion *)v7[4].mNode.mPrev, 1);
      }
      if ( UFG::SpawnZone::ShouldSpawnZoneActivate((UFG::SpawnZone *)v7) )
      {
        v9 = 0;
        if ( NISManager::GetInstance()->mSpatialDataHandle.mData )
        {
          mNext = v7[10].mNode.mNext;
          if ( mNext )
          {
            if ( !UFG::BenchmarkHelper::gBenchmarkHelper.mTiming )
            {
              v11 = *((float *)&mNext->mPrev + 1);
              v12 = *(float *)&mNext->mNext;
              v13 = &UFG::qMatrix44::msIdentity;
              min.x = *(float *)&mNext->mPrev;
              min.y = v11;
              min.z = v12;
              v14 = *((float *)&mNext[1].mPrev + 1);
              v15 = *(float *)&mNext[1].mNext;
              max.x = *(float *)&mNext[1].mPrev;
              max.y = v14;
              max.z = v15;
              v16 = (UFG::qMatrix44 *)mNext[3].mNext;
              if ( v16 )
                v13 = v16;
              v17 = v13->v2;
              v18 = v13->v3;
              v19 = v13->v0;
              m.v1 = v13->v1;
              m.v2 = v17;
              m.v0 = v19;
              m.v3 = v18;
              TransformAABB(&m, &min, &max);
              box.mMin = min;
              box.mMax = max;
              v20 = NISManager::GetInstance();
              v9 = NISManager::IntersectsSpatialBoundingBox(v20, &box);
            }
          }
        }
        v21 = v7[1].mNode.mNext;
        mPrev = v7[2].mNode.mPrev;
        v23 = (UFG::qNode<UFG::SpawnZone,UFG::SpawnZoneList> *)&v7[1].mNode.mNext;
        v21->mNext = mPrev;
        mPrev->mPrev = v21;
        v7[1].mNode.mNext = (UFG::qNode<UFG::SpawnZone,UFG::SpawnZoneList> *)&v7[1].mNode.mNext;
        v7[2].mNode.mPrev = (UFG::qNode<UFG::SpawnZone,UFG::SpawnZoneList> *)&v7[1].mNode.mNext;
        if ( v9 )
        {
          v24 = UFG::PedSpawnManager::msActiveZoneList.mNode.mNext;
          UFG::PedSpawnManager::msActiveZoneList.mNode.mNext = (UFG::qNode<UFG::SpawnZone,UFG::SpawnZoneList> *)&v7[1].mNode.mNext;
          v7[2].mNode.mPrev = v24;
          v23->mPrev = (UFG::qNode<UFG::SpawnZone,UFG::SpawnZoneList> *)&UFG::PedSpawnManager::msActiveZoneList;
          v24->mPrev = v23;
          LODWORD(v7[3].mNode.mNext) = 3;
          *((float *)&v7[7].mNode.mPrev + 1) = UFG::PedSpawnManager::msElapsedTotal;
          goto LABEL_20;
        }
LABEL_19:
        v27 = UFG::PedSpawnManager::msShouldBeActiveZoneList.mNode.mPrev;
        UFG::PedSpawnManager::msShouldBeActiveZoneList.mNode.mPrev->mNext = v23;
        v23->mPrev = v27;
        v23->mNext = (UFG::qNode<UFG::SpawnZone,UFG::SpawnZoneList> *)&UFG::PedSpawnManager::msShouldBeActiveZoneList;
        UFG::PedSpawnManager::msShouldBeActiveZoneList.mNode.mPrev = v23;
      }
LABEL_20:
      if ( p_mNext == (UFG::qList<UFG::SpawnZone,UFG::SpawnZoneList,1,0> *)((char *)&UFG::PedSpawnManager::msSpawnZoneList
                                                                          - 24) )
        goto LABEL_22;
      v3 = update_counter_0;
    }
    if ( !UFG::SpawnZone::ShouldSpawnZoneActivate((UFG::SpawnZone *)v7) )
      goto LABEL_20;
    v25 = v7[1].mNode.mNext;
    v26 = v7[2].mNode.mPrev;
    v23 = (UFG::qNode<UFG::SpawnZone,UFG::SpawnZoneList> *)&v7[1].mNode.mNext;
    v25->mNext = v26;
    v26->mPrev = v25;
    v7[1].mNode.mNext = (UFG::qNode<UFG::SpawnZone,UFG::SpawnZoneList> *)&v7[1].mNode.mNext;
    v7[2].mNode.mPrev = (UFG::qNode<UFG::SpawnZone,UFG::SpawnZoneList> *)&v7[1].mNode.mNext;
    goto LABEL_19;
  }
LABEL_22:
  if ( UFG::PedSpawnManager::msPedInfoForLocalZoneChecks )
  {
    UFG::PedSpawnManager::msPedInfoForLocalZoneChecks->mIsNearDeactivatedZones = 0;
    UFG::PedSpawnManager::msPedInfoForLocalZoneChecks->mShouldCheckZoneInAreaTime = 0.0;
  }
  UFG::PedSpawnManager::ProcessZonesDueToSpawn(this);
}

// File Line: 3532
// RVA: 0x417710
void __fastcall UFG::PedSpawnManager::SpawnZonesNearCamera(UFG::PedSpawnManager *this, const float dist)
{
  UFG::qList<UFG::SpawnZone,UFG::SpawnZoneList,1,0> *p_mNext; // rbx
  UFG::qList<UFG::SpawnZone,UFG::SpawnZoneList,1,0> *v4; // rdi
  UFG::qVector3 *ViewerPosition; // rax
  UFG::qNode<UFG::SpawnZone,UFG::SpawnZoneList> *mPrev; // rax
  UFG::qNode<UFG::SpawnZone,UFG::SpawnZoneList> *mNext; // rcx
  UFG::qNode<UFG::SpawnZone,UFG::SpawnZoneList> *v8; // rax

  if ( UFG::PedSpawnManager::msAmbientSpawningEnable )
  {
    p_mNext = (UFG::qList<UFG::SpawnZone,UFG::SpawnZoneList,1,0> *)&UFG::PedSpawnManager::msSpawnZoneList.mNode.mNext[-2].mNext;
    while ( p_mNext != (UFG::qList<UFG::SpawnZone,UFG::SpawnZoneList,1,0> *)((char *)&UFG::PedSpawnManager::msSpawnZoneList
                                                                           - 24) )
    {
      v4 = p_mNext;
      p_mNext = (UFG::qList<UFG::SpawnZone,UFG::SpawnZoneList,1,0> *)&p_mNext[2].mNode.mPrev[-2].mNext;
      ViewerPosition = UFG::SectionChooser::GetViewerPosition();
      if ( (float)((float)((float)((float)(ViewerPosition->y - *((float *)&v4[9].mNode.mNext + 1))
                                 * (float)(ViewerPosition->y - *((float *)&v4[9].mNode.mNext + 1)))
                         + (float)((float)(ViewerPosition->x - *(float *)&v4[9].mNode.mNext)
                                 * (float)(ViewerPosition->x - *(float *)&v4[9].mNode.mNext)))
                 + (float)((float)(ViewerPosition->z - *(float *)&v4[10].mNode.mPrev)
                         * (float)(ViewerPosition->z - *(float *)&v4[10].mNode.mPrev))) < (float)(dist * dist) )
      {
        mPrev = v4[2].mNode.mPrev;
        mNext = v4[1].mNode.mNext;
        mNext->mNext = mPrev;
        mPrev->mPrev = mNext;
        v4[1].mNode.mNext = (UFG::qNode<UFG::SpawnZone,UFG::SpawnZoneList> *)&v4[1].mNode.mNext;
        v4[2].mNode.mPrev = (UFG::qNode<UFG::SpawnZone,UFG::SpawnZoneList> *)&v4[1].mNode.mNext;
        v8 = UFG::PedSpawnManager::msShouldBeActiveZoneList.mNode.mPrev;
        UFG::PedSpawnManager::msShouldBeActiveZoneList.mNode.mPrev->mNext = (UFG::qNode<UFG::SpawnZone,UFG::SpawnZoneList> *)&v4[1].mNode.mNext;
        v4[1].mNode.mNext = v8;
        v4[2].mNode.mPrev = (UFG::qNode<UFG::SpawnZone,UFG::SpawnZoneList> *)&UFG::PedSpawnManager::msShouldBeActiveZoneList;
        UFG::PedSpawnManager::msShouldBeActiveZoneList.mNode.mPrev = (UFG::qNode<UFG::SpawnZone,UFG::SpawnZoneList> *)&v4[1].mNode.mNext;
      }
    }
    UFG::PedSpawnManager::ProcessZonesDueToSpawn(this);
  }
}

// File Line: 3773
// RVA: 0x40E300
void __fastcall UFG::PedSpawnManager::LoadPedDensityTable(UFG::Event *__formal)
{
  UFG::qPropertySet *PropertySet; // r15
  unsigned int v2; // ebp
  __int64 v3; // rbx
  int v4; // esi
  __int64 v5; // rdi
  float *v6; // r14
  UFG::qString v7; // [rsp+28h] [rbp-60h] BYREF
  UFG::qSymbol result; // [rsp+98h] [rbp+10h] BYREF
  UFG::qArray<unsigned long,0> propName; // [rsp+A0h] [rbp+18h] BYREF

  UFG::qSymbol::create_from_string(&result, "config-PedDensityScale");
  PropertySet = UFG::PropertySetManager::GetPropertySet(&result);
  v2 = 0;
  v3 = 0i64;
  do
  {
    v4 = v2 + 1;
    v5 = v3 + 1;
    v6 = 0i64;
    if ( (int)(v2 + 1) < 25 )
    {
      while ( 1 )
      {
        UFG::qString::FormatEx(&v7, "Hours_%02d_%02d", v2, (unsigned int)v4);
        UFG::qSymbol::create_from_string((UFG::qSymbol *)&propName, v7.mData);
        v6 = PropertyUtils::Get<float>(PropertySet, &propName, DEPTH_RECURSE);
        if ( v6 )
          break;
        UFG::qString::~qString(&v7);
        ++v4;
        ++v5;
        if ( v4 >= 25 )
          goto LABEL_7;
      }
      UFG::qString::~qString(&v7);
    }
LABEL_7:
    if ( v3 < v5 )
    {
      if ( v5 - v3 >= 4 )
      {
        do
        {
          UFG::PedSpawnManager::msPedDensityScaleTimeTable[v3] = *v6;
          UFG::PedSpawnManager::msPedDensityScaleTimeTable[v3 + 1] = *v6;
          UFG::PedSpawnManager::msPedDensityScaleTimeTable[v3 + 2] = *v6;
          UFG::PedSpawnManager::msPedDensityScaleTimeTable[v3 + 3] = *v6;
          v3 += 4i64;
        }
        while ( v3 < v5 - 3 );
      }
      for ( ; v3 < v5; ++v3 )
        UFG::PedSpawnManager::msPedDensityScaleTimeTable[v3] = *v6;
    }
    v2 = v4;
    v3 = v5;
  }
  while ( v4 < 24 );
  UFG::qSymbol::create_from_string((UFG::qSymbol *)&propName.p, "Rain_Adjust");
  UFG::PedSpawnManager::msPedDensityScaleRainAdjust = *PropertyUtils::Get<float>(
                                                         PropertySet,
                                                         (UFG::qArray<unsigned long,0> *)&propName.p,
                                                         DEPTH_RECURSE);
}

// File Line: 4022
// RVA: 0x40D080
void __fastcall UFG::PedSpawnManager::Init(UFG::PedSpawnManager *this)
{
  unsigned int v2; // ebx
  UFG::qResourceInventory *Inventory; // rax
  UFG::qResourceWarehouse *v4; // rax
  unsigned int v5; // ebx
  UFG::qResourceInventory *v6; // rax
  UFG::qResourceWarehouse *v7; // rax
  unsigned int v8; // ebx
  UFG::qResourceInventory *v9; // rax
  UFG::qResourceWarehouse *v10; // rax
  unsigned int v11; // ebx
  UFG::qResourceInventory *v12; // rax
  UFG::qResourceWarehouse *v13; // rax
  unsigned int v14; // ebx
  UFG::qResourceInventory *v15; // rax
  UFG::qResourceWarehouse *v16; // rax
  unsigned int v17; // ebx
  UFG::qResourceInventory *v18; // rax
  UFG::qResourceWarehouse *v19; // rax
  unsigned int v20; // ebx
  UFG::qResourceInventory *v21; // rax
  UFG::qResourceWarehouse *v22; // rax
  unsigned int v23; // ebx
  UFG::qResourceInventory *v24; // rax
  UFG::qResourceWarehouse *v25; // rax
  unsigned int v26; // ebx
  UFG::qResourceInventory *v27; // rax
  UFG::qResourceWarehouse *v28; // rax
  unsigned int v29; // ebx
  UFG::qResourceInventory *v30; // rax
  UFG::qResourceWarehouse *v31; // rax
  unsigned int v32; // ebx
  UFG::qResourceInventory *v33; // rax
  UFG::qResourceWarehouse *v34; // rax
  unsigned int v35; // ebx
  UFG::qResourceInventory *v36; // rax
  UFG::qResourceWarehouse *v37; // rax
  unsigned int v38; // ebx
  UFG::qResourceInventory *v39; // rax
  UFG::qResourceWarehouse *v40; // rax
  unsigned int v41; // ebx
  UFG::qResourceInventory *v42; // rax
  UFG::qResourceWarehouse *v43; // rax
  unsigned int v44; // ebx
  UFG::qResourceInventory *v45; // rax
  UFG::qResourceWarehouse *v46; // rax
  int v47; // ebx
  UFG::PedSpawningInfo *mAmbientPed; // rdi
  int v49; // ebx
  UFG::PedSpawningInfo *mScriptedPed; // rdi
  UFG::qSymbol *v51; // rbx

  unk_14207A98C = 3;
  v2 = UFG::qStringHash32("ULTRALOWPED_FRAME00", 0xFFFFFFFF);
  Inventory = `UFG::qGetResourceInventory<Illusion::Model>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::Model>::`2::result )
  {
    v4 = UFG::qResourceWarehouse::Instance();
    Inventory = UFG::qResourceWarehouse::GetInventory(v4, 0xA2ADCD77);
    `UFG::qGetResourceInventory<Illusion::Model>::`2::result = Inventory;
  }
  UFG::qResourceHandle::Init(&UFG::PedSpawnManager::msLowLODHandles, 0xA2ADCD77, v2, Inventory);
  v5 = UFG::qStringHash32("ULTRALOWPED_FRAME01", 0xFFFFFFFF);
  v6 = `UFG::qGetResourceInventory<Illusion::Model>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::Model>::`2::result )
  {
    v7 = UFG::qResourceWarehouse::Instance();
    v6 = UFG::qResourceWarehouse::GetInventory(v7, 0xA2ADCD77);
    `UFG::qGetResourceInventory<Illusion::Model>::`2::result = v6;
  }
  UFG::qResourceHandle::Init(&stru_1423DE6D0, 0xA2ADCD77, v5, v6);
  v8 = UFG::qStringHash32("ULTRALOWPED_FRAME02", 0xFFFFFFFF);
  v9 = `UFG::qGetResourceInventory<Illusion::Model>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::Model>::`2::result )
  {
    v10 = UFG::qResourceWarehouse::Instance();
    v9 = UFG::qResourceWarehouse::GetInventory(v10, 0xA2ADCD77);
    `UFG::qGetResourceInventory<Illusion::Model>::`2::result = v9;
  }
  UFG::qResourceHandle::Init(&stru_1423DE6F0, 0xA2ADCD77, v8, v9);
  v11 = UFG::qStringHash32("ULTRALOWPED_FRAME03", 0xFFFFFFFF);
  v12 = `UFG::qGetResourceInventory<Illusion::Model>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::Model>::`2::result )
  {
    v13 = UFG::qResourceWarehouse::Instance();
    v12 = UFG::qResourceWarehouse::GetInventory(v13, 0xA2ADCD77);
    `UFG::qGetResourceInventory<Illusion::Model>::`2::result = v12;
  }
  UFG::qResourceHandle::Init(&stru_1423DE710, 0xA2ADCD77, v11, v12);
  v14 = UFG::qStringHash32("ULTRALOWPED_FRAME04", 0xFFFFFFFF);
  v15 = `UFG::qGetResourceInventory<Illusion::Model>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::Model>::`2::result )
  {
    v16 = UFG::qResourceWarehouse::Instance();
    v15 = UFG::qResourceWarehouse::GetInventory(v16, 0xA2ADCD77);
    `UFG::qGetResourceInventory<Illusion::Model>::`2::result = v15;
  }
  UFG::qResourceHandle::Init(&stru_1423DE730, 0xA2ADCD77, v14, v15);
  v17 = UFG::qStringHash32("ULTRALOWPED_FRAME05", 0xFFFFFFFF);
  v18 = `UFG::qGetResourceInventory<Illusion::Model>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::Model>::`2::result )
  {
    v19 = UFG::qResourceWarehouse::Instance();
    v18 = UFG::qResourceWarehouse::GetInventory(v19, 0xA2ADCD77);
    `UFG::qGetResourceInventory<Illusion::Model>::`2::result = v18;
  }
  UFG::qResourceHandle::Init(&stru_1423DE750, 0xA2ADCD77, v17, v18);
  v20 = UFG::qStringHash32("ULTRALOWPED_FRAME06", 0xFFFFFFFF);
  v21 = `UFG::qGetResourceInventory<Illusion::Model>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::Model>::`2::result )
  {
    v22 = UFG::qResourceWarehouse::Instance();
    v21 = UFG::qResourceWarehouse::GetInventory(v22, 0xA2ADCD77);
    `UFG::qGetResourceInventory<Illusion::Model>::`2::result = v21;
  }
  UFG::qResourceHandle::Init(&stru_1423DE770, 0xA2ADCD77, v20, v21);
  v23 = UFG::qStringHash32("ULTRALOWPED_FRAME07", 0xFFFFFFFF);
  v24 = `UFG::qGetResourceInventory<Illusion::Model>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::Model>::`2::result )
  {
    v25 = UFG::qResourceWarehouse::Instance();
    v24 = UFG::qResourceWarehouse::GetInventory(v25, 0xA2ADCD77);
    `UFG::qGetResourceInventory<Illusion::Model>::`2::result = v24;
  }
  UFG::qResourceHandle::Init(&stru_1423DE790, 0xA2ADCD77, v23, v24);
  v26 = UFG::qStringHash32("ULTRALOWPED_FRAME08", 0xFFFFFFFF);
  v27 = `UFG::qGetResourceInventory<Illusion::Model>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::Model>::`2::result )
  {
    v28 = UFG::qResourceWarehouse::Instance();
    v27 = UFG::qResourceWarehouse::GetInventory(v28, 0xA2ADCD77);
    `UFG::qGetResourceInventory<Illusion::Model>::`2::result = v27;
  }
  UFG::qResourceHandle::Init(&stru_1423DE7B0, 0xA2ADCD77, v26, v27);
  v29 = UFG::qStringHash32("ULTRALOWPED_FRAME09", 0xFFFFFFFF);
  v30 = `UFG::qGetResourceInventory<Illusion::Model>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::Model>::`2::result )
  {
    v31 = UFG::qResourceWarehouse::Instance();
    v30 = UFG::qResourceWarehouse::GetInventory(v31, 0xA2ADCD77);
    `UFG::qGetResourceInventory<Illusion::Model>::`2::result = v30;
  }
  UFG::qResourceHandle::Init(&stru_1423DE7D0, 0xA2ADCD77, v29, v30);
  v32 = UFG::qStringHash32("ULTRALOWPED_FRAME10", 0xFFFFFFFF);
  v33 = `UFG::qGetResourceInventory<Illusion::Model>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::Model>::`2::result )
  {
    v34 = UFG::qResourceWarehouse::Instance();
    v33 = UFG::qResourceWarehouse::GetInventory(v34, 0xA2ADCD77);
    `UFG::qGetResourceInventory<Illusion::Model>::`2::result = v33;
  }
  UFG::qResourceHandle::Init(&stru_1423DE7F0, 0xA2ADCD77, v32, v33);
  v35 = UFG::qStringHash32("ULTRALOWPED_FRAME11", 0xFFFFFFFF);
  v36 = `UFG::qGetResourceInventory<Illusion::Model>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::Model>::`2::result )
  {
    v37 = UFG::qResourceWarehouse::Instance();
    v36 = UFG::qResourceWarehouse::GetInventory(v37, 0xA2ADCD77);
    `UFG::qGetResourceInventory<Illusion::Model>::`2::result = v36;
  }
  UFG::qResourceHandle::Init(&stru_1423DE810, 0xA2ADCD77, v35, v36);
  v38 = UFG::qStringHash32("ULTRALOWPED_FRAME12", 0xFFFFFFFF);
  v39 = `UFG::qGetResourceInventory<Illusion::Model>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::Model>::`2::result )
  {
    v40 = UFG::qResourceWarehouse::Instance();
    v39 = UFG::qResourceWarehouse::GetInventory(v40, 0xA2ADCD77);
    `UFG::qGetResourceInventory<Illusion::Model>::`2::result = v39;
  }
  UFG::qResourceHandle::Init(&stru_1423DE830, 0xA2ADCD77, v38, v39);
  v41 = UFG::qStringHash32("ULTRALOWPED_FRAME13", 0xFFFFFFFF);
  v42 = `UFG::qGetResourceInventory<Illusion::Model>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::Model>::`2::result )
  {
    v43 = UFG::qResourceWarehouse::Instance();
    v42 = UFG::qResourceWarehouse::GetInventory(v43, 0xA2ADCD77);
    `UFG::qGetResourceInventory<Illusion::Model>::`2::result = v42;
  }
  UFG::qResourceHandle::Init(&stru_1423DE850, 0xA2ADCD77, v41, v42);
  v44 = UFG::qStringHash32("ULTRALOWPED_FRAME14", 0xFFFFFFFF);
  v45 = `UFG::qGetResourceInventory<Illusion::Model>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::Model>::`2::result )
  {
    v46 = UFG::qResourceWarehouse::Instance();
    v45 = UFG::qResourceWarehouse::GetInventory(v46, 0xA2ADCD77);
    `UFG::qGetResourceInventory<Illusion::Model>::`2::result = v45;
  }
  UFG::qResourceHandle::Init(&stru_1423DE870, 0xA2ADCD77, v44, v45);
  this->mTargetNumActive = 0;
  *(_QWORD *)UFG::PedSpawnManager::msAmbientCount = 0i64;
  qword_1423DC628 = 0i64;
  qword_1423DC630 = 0i64;
  *(_QWORD *)UFG::PedSpawnManager::msScriptedCount = 0i64;
  UFG::PedSpawnManager::msElapsedTotal = 0.0;
  qword_1423DC640 = 0i64;
  qword_1423DC648 = 0i64;
  this->mUpdateDelta = 0.0;
  UFG::PedSpawnManager::msProxyPedsEnabled = 1;
  UFG::PedSpawnManager::LoadPedDensityTable(0i64);
  v47 = 0;
  mAmbientPed = this->mAmbientPed;
  do
    UFG::PedSpawningInfo::Init(mAmbientPed++, v47++, AmbientPed);
  while ( v47 < 260 );
  v49 = 0;
  mScriptedPed = this->mScriptedPed;
  do
    UFG::PedSpawningInfo::Init(mScriptedPed++, v49++, ScriptedPed);
  while ( v49 < 120 );
  v51 = &UFG::PedSpawnManager::msDisabledThugZones;
  do
  {
    UFG::qSymbol::set_null(v51);
    v51[1].mUID = 0;
    v51 += 2;
  }
  while ( (__int64)v51 < (__int64)&UFG::mgSym_Face );
  this->mPedSpawnHistoryIndex = 0;
}

// File Line: 4243
// RVA: 0x411260
void __fastcall UFG::PedSpawnManager::OnGameEnter(UFG::PedSpawnManager *this)
{
  void (__fastcall *v2)(fastdelegate::detail::GenericClass *); // rbx
  void (__fastcall *v3)(fastdelegate::detail::GenericClass *); // rax
  int v4; // ebx
  UFG::PedSpawningInfo *mAmbientPed; // rdi
  int v6; // ebx
  UFG::PedSpawningInfo *mScriptedPed; // rdi
  UFG::allocator::free_link *v8; // rax
  UFG::SpawnZone *v9; // rbx
  int v10; // ecx
  __int64 v11; // rdx
  UFG::SpawnZone **v12; // r8
  __int64 v13; // r9
  fastdelegate::FastDelegate1<UFG::Event *,void> v14; // [rsp+38h] [rbp-30h] BYREF
  void (__fastcall *v15)(UFG::Event *); // [rsp+48h] [rbp-20h]
  void (__fastcall *v16)(fastdelegate::detail::GenericClass *); // [rsp+50h] [rbp-18h]

  v2 = (void (__fastcall *)(fastdelegate::detail::GenericClass *))fastdelegate::FastDelegate1<char const *,void>::InvokeStaticFunction;
  v3 = (void (__fastcall *)(fastdelegate::detail::GenericClass *))fastdelegate::FastDelegate1<char const *,void>::InvokeStaticFunction;
  if ( !UFG::PedSpawnManager::SceneLayerActivatedEventHandler )
    v3 = 0i64;
  v16 = v3;
  v15 = UFG::PedSpawnManager::SceneLayerActivatedEventHandler;
  v14.m_Closure.m_pFunction = v3;
  v14.m_Closure.m_pthis = (fastdelegate::detail::GenericClass *)UFG::PedSpawnManager::SceneLayerActivatedEventHandler;
  UFG::EventDispatcher::Register(&UFG::EventDispatcher::mInstance, &v14, UFG::gSceneLayerActivatedChannel.mUID, 0i64, 0);
  if ( !UFG::PedSpawnManager::SceneLayerActivatedEventHandler )
    v2 = 0i64;
  v16 = v2;
  v15 = UFG::PedSpawnManager::SceneLayerActivatedEventHandler;
  v14.m_Closure.m_pFunction = v2;
  v14.m_Closure.m_pthis = (fastdelegate::detail::GenericClass *)UFG::PedSpawnManager::SceneLayerActivatedEventHandler;
  UFG::EventDispatcher::Register(
    &UFG::EventDispatcher::mInstance,
    &v14,
    UFG::gSceneLayerDeactivatedChannel.mUID,
    0i64,
    0);
  v4 = 0;
  mAmbientPed = this->mAmbientPed;
  do
    UFG::PedSpawningInfo::InitProxySimObject(mAmbientPed++, v4++);
  while ( v4 < 260 );
  v6 = 0;
  mScriptedPed = this->mScriptedPed;
  do
    UFG::PedSpawningInfo::InitProxySimObject(mScriptedPed++, v6++);
  while ( v6 < 120 );
  v8 = UFG::qMalloc(0x286E8ui64, "spawn zones", 0i64);
  if ( v8 )
  {
    LODWORD(v8->mNext) = 900;
    v9 = (UFG::SpawnZone *)&v8[1];
    `eh vector constructor iterator(&v8[1], 0xB8ui64, 900, (void (__fastcall *)(void *))UFG::SpawnZone::SpawnZone);
  }
  else
  {
    v9 = 0i64;
  }
  UFG::PedSpawnManager::msSpawnZoneStructs = v9;
  v10 = 0;
  v11 = 0i64;
  v12 = UFG::PedSpawnManager::msSpawnZoneFreePtrs;
  v13 = 0i64;
  while ( 1 )
  {
    *v12 = &v9[v13];
    v9[v11].mZoneIndex = v10++;
    ++v13;
    ++v12;
    ++v11;
    if ( v10 >= 900 )
      break;
    v9 = UFG::PedSpawnManager::msSpawnZoneStructs;
  }
  UFG::PedSpawnManager::msSpawnZoneFreeIndex = 0;
  UFG::PedSpawnManager::msRestoreWeiOnPhysicsLoad = 0;
}

// File Line: 4277
// RVA: 0x40A600
void __fastcall UFG::PedSpawnManager::DeInit(UFG::PedSpawnManager *this)
{
  UFG::PedSpawningInfo *mAmbientPed; // rbx
  __int64 v3; // rdi
  UFG::PedSpawningInfo *mScriptedPed; // rbx
  __int64 v5; // rdi
  void (__fastcall *v6)(fastdelegate::detail::GenericClass *); // rbx
  void (__fastcall *v7)(fastdelegate::detail::GenericClass *); // rax
  UFG::qPropertySet ***p_p; // rbx
  __int64 v9; // rdi
  UFG::qPropertySet **v10; // rcx
  fastdelegate::FastDelegate1<UFG::Event *,void> v11; // [rsp+20h] [rbp-18h] BYREF

  mAmbientPed = this->mAmbientPed;
  v3 = 260i64;
  do
  {
    UFG::PedSpawningInfo::Reset(mAmbientPed++, 0);
    --v3;
  }
  while ( v3 );
  mScriptedPed = this->mScriptedPed;
  v5 = 120i64;
  do
  {
    UFG::PedSpawningInfo::Reset(mScriptedPed++, 0);
    --v5;
  }
  while ( v5 );
  v6 = (void (__fastcall *)(fastdelegate::detail::GenericClass *))fastdelegate::FastDelegate1<char const *,void>::InvokeStaticFunction;
  v7 = (void (__fastcall *)(fastdelegate::detail::GenericClass *))fastdelegate::FastDelegate1<char const *,void>::InvokeStaticFunction;
  v11.m_Closure.m_pthis = (fastdelegate::detail::GenericClass *)UFG::PedSpawnManager::SceneLayerActivatedEventHandler;
  if ( !UFG::PedSpawnManager::SceneLayerActivatedEventHandler )
    v7 = 0i64;
  v11.m_Closure.m_pFunction = v7;
  UFG::EventDispatcher::UnRegister(&UFG::EventDispatcher::mInstance, &v11, UFG::gSceneLayerActivatedChannel.mUID);
  if ( !UFG::PedSpawnManager::SceneLayerActivatedEventHandler )
    v6 = 0i64;
  v11.m_Closure.m_pthis = (fastdelegate::detail::GenericClass *)UFG::PedSpawnManager::SceneLayerActivatedEventHandler;
  v11.m_Closure.m_pFunction = v6;
  UFG::EventDispatcher::UnRegister(&UFG::EventDispatcher::mInstance, &v11, UFG::gSceneLayerDeactivatedChannel.mUID);
  if ( UFG::PedSpawnManager::msSpawnZoneStructs )
  {
    if ( LODWORD(UFG::PedSpawnManager::msSpawnZoneStructs[-1].mCullResults) )
      UFG::PedSpawnManager::msSpawnZoneStructs->vfptr->__vecDelDtor(UFG::PedSpawnManager::msSpawnZoneStructs, 3i64);
    else
      operator delete[](&UFG::PedSpawnManager::msSpawnZoneStructs[-1].mCullResults);
  }
  UFG::PedSpawnManager::msSpawnZoneStructs = 0i64;
  UFG::PedSpawnManager::msAmbientSpawningEnable = 1;
  UFG::PedSpawnManager::msCheckStatusMode = 1;
  UFG::PedSpawnManager::msAmbientStatusCheckEnable = 1;
  UFG::PedSpawnManager::msScriptedStatusCheckEnable = 1;
  p_p = &this->mActiveSpawnSets[0].mSpawnInfoArray.p;
  v9 = 40i64;
  do
  {
    *(p_p - 4) = 0i64;
    if ( *p_p )
      operator delete[](*p_p);
    *p_p = 0i64;
    *(p_p - 1) = 0i64;
    v10 = p_p[2];
    if ( v10 )
      operator delete[](v10);
    p_p[2] = 0i64;
    p_p[1] = 0i64;
    *(p_p - 3) = 0i64;
    *((_DWORD *)p_p - 4) = 0;
    *((_BYTE *)p_p - 12) = 0;
    p_p += 7;
    --v9;
  }
  while ( v9 );
}

// File Line: 4319
// RVA: 0x416A80
void __fastcall UFG::PedSpawnManager::SetStartMode(
        UFG::PedSpawnManager *this,
        UFG::SimObject *pObj,
        UFG::qPropertySet *pPropSet,
        UFG::qVector3 *startPos)
{
  if ( UFG::PedSpawnManager::msLastRegisteredPedInfo->mPedType == AmbientPed )
    UFG::PedSpawnManager::SetAmbientStartingMode(this, UFG::PedSpawnManager::msLastRegisteredPedInfo, startPos);
}

// File Line: 4332
// RVA: 0x40E180
bool __fastcall UFG::PedSpawnManager::JoinGroup(
        UFG::PedSpawnManager *this,
        UFG::SimObject *pObj,
        UFG::qPropertySet *pPropSet,
        UFG::qVector3 *startPos,
        UFG::SpawnRegion *pSourceRegion)
{
  return UFG::PedSpawnManager::TryJoinGroup(
           this,
           UFG::PedSpawnManager::msLastRegisteredPedInfo,
           startPos,
           0,
           pSourceRegion);
}

// File Line: 4361
// RVA: 0x417D70
_BOOL8 __fastcall UFG::PedSpawnManager::TryJoinGroup(
        UFG::PedSpawnManager *this,
        UFG::PedSpawningInfo *pPed,
        UFG::qVector3 *pos,
        const bool groupIsNotAllowed,
        UFG::SpawnRegion *pSourceRegion)
{
  bool v8; // bl
  float y; // xmm1_4
  float z; // xmm0_4
  UFG::GroupManager *Instance; // rax
  float v12; // xmm1_4
  float v13; // xmm2_4
  UFG::qVector3 followerPosition; // [rsp+38h] [rbp-80h] BYREF
  UFG::qFixedArray<UFG::PedSpawningInfo *,10> closePeds; // [rsp+50h] [rbp-68h] BYREF

  v8 = 0;
  if ( groupIsNotAllowed )
    goto LABEL_8;
  closePeds.size = 0;
  y = pos->y;
  z = pos->z;
  followerPosition.x = pos->x;
  followerPosition.y = y;
  followerPosition.z = z;
  UFG::PedSpawnManager::GetGroupCandidates(this, pPed, &closePeds, &followerPosition, 8.0);
  if ( closePeds.size )
  {
    Instance = UFG::GroupManager::GetInstance();
    v8 = UFG::GroupManager::JoinGroup(Instance, pPed, &closePeds);
    if ( v8 )
    {
      v12 = pos->y;
      v13 = pos->z;
      followerPosition.x = pos->x;
      followerPosition.y = v12;
      followerPosition.z = v13;
      if ( UFG::GroupComponent::GetDefaultFollowerPosition(pPed->mGroupComponent, &followerPosition)
        && UFG::RegionComponent::IsHitPoint(pSourceRegion->mpRegion, &followerPosition) )
      {
        *pos = followerPosition;
      }
    }
  }
  closePeds.size = 0;
  if ( !v8 )
LABEL_8:
    UFG::GroupComponent::MakeSingle(pPed->mGroupComponent, !groupIsNotAllowed);
  return v8;
}

// File Line: 4404
// RVA: 0x40AB40
void __fastcall UFG::PedSpawnManager::DeletePedsFromDeactivatedRegions(UFG::PedSpawnManager *this)
{
  UFG::PedSpawningInfo *p_mTrueCrowdSignature; // rbx
  UFG::PedSpawningInfo *mAmbientPed; // rsi
  __int64 v3; // rbp
  UFG::SimObject *v4; // rdi
  UFG::SimComponent *m_pComponent; // rcx
  UFG::SceneObjectProperties *m_pSceneObj; // rcx

  p_mTrueCrowdSignature = (UFG::PedSpawningInfo *)&this->mAmbientPed[0].mTrueCrowdSignature;
  mAmbientPed = this->mAmbientPed;
  v3 = 260i64;
  do
  {
    if ( !*(_QWORD *)&p_mTrueCrowdSignature[-1].mTrueCrowdSignature.mPart[15].mModelIndex
      && !*(_QWORD *)&p_mTrueCrowdSignature[-1].mLocationInCameraSpace.y )
    {
      v4 = *(UFG::SimObject **)&p_mTrueCrowdSignature[-1].mNumAttachedProps;
      if ( v4 )
      {
        m_pComponent = v4->m_Components.p[27].m_pComponent;
        if ( m_pComponent && m_pComponent[9].m_TypeUID )
          goto LABEL_14;
        UFG::PedSpawningInfo::RemoveProps(mAmbientPed);
        m_pSceneObj = v4->m_pSceneObj;
        if ( m_pSceneObj->mpParent )
          UFG::SceneObjectProperties::DeactivateDeferred(m_pSceneObj);
        else
          UFG::SimObject::Destroy(v4);
      }
      else
      {
        UFG::PedSpawningInfo::MakeCompletelyInactive(mAmbientPed);
      }
      if ( p_mTrueCrowdSignature->vfptr )
        UFG::TrueCrowdSet::Instance::RemoveProxyReference(
          (UFG::TrueCrowdSet::Instance *)p_mTrueCrowdSignature,
          (UFG::PedSpawningInfo *)((char *)p_mTrueCrowdSignature - 360));
      p_mTrueCrowdSignature->vfptr = 0i64;
      LODWORD(p_mTrueCrowdSignature->m_SafePointerList.mNode.UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::mPrev) = 0;
    }
LABEL_14:
    ++mAmbientPed;
    ++p_mTrueCrowdSignature;
    --v3;
  }
  while ( v3 );
}

// File Line: 4446
// RVA: 0x40A770
void __fastcall UFG::PedSpawnManager::DeleteAmbientPedsFromNISBoundingVolume(
        UFG::PedSpawnManager *this,
        UFG::qVector3 *aabbMin,
        UFG::qVector3 *aabbMax)
{
  float y; // xmm6_4
  float z; // xmm7_4
  float *p_z; // rbx
  __int64 v8; // r15
  float x; // xmm8_4
  float v10; // xmm9_4
  float v11; // xmm10_4
  float v12; // xmm11_4
  UFG::SimObject *v13; // rdi
  UFG::SimComponent *m_pComponent; // rcx
  float *mNext; // rax
  float v16; // xmm1_4
  float v17; // xmm0_4
  float v18; // xmm1_4
  float v19; // xmm0_4
  float v20; // xmm1_4
  UFG::SceneObjectProperties *m_pSceneObj; // rcx
  float v22; // xmm0_4
  float v23; // xmm0_4
  UFG::qVector3 max; // [rsp+20h] [rbp-98h] BYREF
  UFG::qVector3 min; // [rsp+30h] [rbp-88h] BYREF

  y = aabbMin->y;
  z = aabbMin->z;
  p_z = &this->mAmbientPed[0].mCurrentLocation.z;
  v8 = 260i64;
  x = aabbMax->x;
  v10 = aabbMax->y;
  v11 = aabbMax->z;
  v12 = aabbMin->x;
  do
  {
    if ( *((_DWORD *)p_z - 8) != 1 )
      goto LABEL_25;
    v13 = (UFG::SimObject *)*((_QWORD *)p_z - 73);
    if ( v13 )
    {
      m_pComponent = v13->m_Components.p[14].m_pComponent;
      if ( !m_pComponent )
        goto LABEL_25;
      mNext = (float *)m_pComponent[22].m_SafePointerList.mNode.mNext;
      if ( !mNext )
        goto LABEL_25;
      v16 = mNext[33];
      min.x = mNext[32];
      v17 = mNext[34];
      min.y = v16;
      v18 = mNext[35];
      min.z = v17;
      v19 = mNext[36];
      max.x = v18;
      v20 = mNext[37];
      max.y = v19;
      max.z = v20;
      TransformAABB((UFG::qMatrix44 *)&m_pComponent[20], &min, &max);
      if ( v12 > max.x || x < min.x || y > max.y || v10 < min.y || z > max.z || v11 < min.z )
        goto LABEL_25;
      UFG::PedSpawningInfo::RemoveProps((UFG::PedSpawningInfo *)(p_z - 194));
      m_pSceneObj = v13->m_pSceneObj;
      if ( m_pSceneObj->mpParent )
        UFG::SceneObjectProperties::DeactivateDeferred(m_pSceneObj);
      else
        UFG::SimObject::Destroy(v13);
    }
    else
    {
      v22 = *(p_z - 2);
      if ( v22 < aabbMin->x )
        goto LABEL_25;
      if ( v22 > aabbMax->x )
        goto LABEL_25;
      v23 = *(p_z - 1);
      if ( v23 < aabbMin->y || v23 > aabbMax->y || *p_z < aabbMin->z || *p_z > aabbMax->z )
        goto LABEL_25;
      UFG::PedSpawningInfo::MakeCompletelyInactive((UFG::PedSpawningInfo *)(p_z - 194));
    }
    if ( *((_QWORD *)p_z - 52) )
      UFG::TrueCrowdSet::Instance::RemoveProxyReference(
        (UFG::TrueCrowdSet::Instance *)(p_z - 104),
        (UFG::PedSpawningInfo *)(p_z - 194));
    *(p_z - 102) = 0.0;
    *((_QWORD *)p_z - 52) = 0i64;
LABEL_25:
    p_z += 206;
    --v8;
  }
  while ( v8 );
}

// File Line: 4497
// RVA: 0x40ACF0
void __fastcall UFG::PedSpawnManager::DisableProxyPeds(UFG::PedSpawnManager *this)
{
  UFG::PedSpawnManager::msProxyPedsEnabled = 0;
}

// File Line: 4502
// RVA: 0x40AF50
void __fastcall UFG::PedSpawnManager::EnableProxyPeds(UFG::PedSpawnManager *this)
{
  UFG::PedSpawnManager::msProxyPedsEnabled = 1;
}

// File Line: 4511
// RVA: 0x40BC30
UFG::SimObjectCharacter *__fastcall UFG::PedSpawnManager::GetAmbientPedForVehicle(
        UFG::PedSpawnManager *this,
        UFG::qPropertyList *classPriorities,
        UFG::qPropertyList *classExclusions,
        UFG::PedSpawningInfo **newPedInfo)
{
  UFG::SimComponent *m_pComponent; // rdi
  UFG::PedSpawningInfo *PedToRepurposeForVehicle; // rax
  UFG::PedSpawningInfo *v10; // rbx
  UFG::SimObject *m_pPointer; // rsi
  UFG::ObjectResourceManager *v12; // rax
  UFG::qPropertySet *pParentPropertySet; // rsi
  UFG::eHowSpawned mSpawningModeNow; // ebp
  UFG::OnlineManager *v15; // rax
  unsigned int OnlineIdStringHash32; // eax
  UFG::qString *v17; // rax
  UFG::SceneObjectProperties *v18; // rbx
  UFG::qSafePointer<UFG::SpawnZone,UFG::SpawnZone> *p_mCreationSpawnZone; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SpawnZone>,UFG::qSafePointerNodeList> *mPrev; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SpawnZone>,UFG::qSafePointerNodeList> *mNext; // rcx
  UFG::SpawnRegion *v22; // r14
  unsigned int v23; // ebp
  UFG::SpawnZone *i; // rbx
  UFG::SpawnRegion *mpRegion; // rax
  UFG::SimObject *v26; // rdx
  Creature *v27; // rcx
  UFG::SimComponentHolder *p; // rax
  UFG::InventoryComponent *v29; // rbx
  UFG::qSymbol objName; // [rsp+40h] [rbp-68h] BYREF
  UFG::SpawnInfoInterface::SpawnPriority pPriority; // [rsp+44h] [rbp-64h] BYREF
  UFG::qSymbol v33; // [rsp+48h] [rbp-60h] BYREF
  __int64 v34; // [rsp+50h] [rbp-58h]
  UFG::qString result; // [rsp+58h] [rbp-50h] BYREF

  v34 = -2i64;
  m_pComponent = 0i64;
  PedToRepurposeForVehicle = (UFG::PedSpawningInfo *)UFG::PedSpawnManager::FindPedToRepurposeForVehicle(
                                                       this,
                                                       classPriorities,
                                                       classExclusions);
  v10 = PedToRepurposeForVehicle;
  if ( PedToRepurposeForVehicle && !PedToRepurposeForVehicle->mCharacterOccupantComponent.m_pSimComponent )
  {
    UFG::PedSpawnManager::ChangeStatusToActive(this, PedToRepurposeForVehicle);
    v10->mSpawnTime = UFG::PedSpawnManager::msElapsedTotal;
    m_pPointer = v10->mSimObjectPtr.m_pPointer;
    UFG::GroupComponent::MakeSingle(v10->mGroupComponent, 1);
    UFG::doing_reinit = 1;
    UFG::SimObjectUtility::ReinitializeSimObject(m_pPointer, 1, 0);
    UFG::doing_reinit = 0;
    goto LABEL_21;
  }
  v12 = UFG::ObjectResourceManager::Instance();
  pParentPropertySet = UFG::ObjectResourceManager::GetAvailableDriver(v12, classPriorities, classExclusions);
  if ( pParentPropertySet )
  {
    ++this->mNetRecycleCounter;
    objName.mUID = -1;
    mSpawningModeNow = this->mSpawningModeNow;
    this->mSpawningModeNow = FromPoint;
    UFG::PedSpawnManager::msZoneDoingSpawnNow = 0i64;
    v15 = UFG::OnlineManager::Instance();
    OnlineIdStringHash32 = UFG::OnlineManager::GetOnlineIdStringHash32(v15);
    v17 = UFG::qString::FormatEx(
            &result,
            "CreatedForVehicle:Spawn_%d_%d",
            OnlineIdStringHash32,
            this->mNetRecycleCounter);
    objName.mUID = UFG::qSymbol::create_from_string(&v33, v17->mData)->mUID;
    UFG::qString::~qString(&result);
    v18 = UFG::SceneObjectProperties::Create(&objName, 0i64, pParentPropertySet);
    UFG::SpawnInfoInterface::GetSpawnPriority(pParentPropertySet, &pPriority);
    m_pPointer = UFG::SpawnInfoInterface::ActivateObject(v18, pPriority, 0i64, 0i64, pParentPropertySet, 3u, 0);
    p_mCreationSpawnZone = &UFG::PedSpawnManager::msLastRegisteredPedInfo->mCreationSpawnZone;
    if ( UFG::PedSpawnManager::msLastRegisteredPedInfo->mCreationSpawnZone.m_pPointer )
    {
      mPrev = p_mCreationSpawnZone->mPrev;
      mNext = UFG::PedSpawnManager::msLastRegisteredPedInfo->mCreationSpawnZone.mNext;
      mPrev->mNext = mNext;
      mNext->mPrev = mPrev;
      p_mCreationSpawnZone->mPrev = p_mCreationSpawnZone;
      p_mCreationSpawnZone->mNext = p_mCreationSpawnZone;
    }
    p_mCreationSpawnZone->m_pPointer = 0i64;
    this->mSpawningModeNow = mSpawningModeNow;
    if ( newPedInfo )
      *newPedInfo = UFG::PedSpawnManager::msLastRegisteredPedInfo;
    goto LABEL_23;
  }
  v22 = 0i64;
  v23 = 0;
  for ( i = (UFG::SpawnZone *)&UFG::PedSpawnManager::msActiveZoneList.mNode.mNext[-2].mNext;
        ;
        i = (UFG::SpawnZone *)&i->UFG::qNode<UFG::SpawnZone,UFG::SpawnZoneList>::mNext[-2].mNext )
  {
    if ( i == (UFG::SpawnZone *)((char *)&UFG::PedSpawnManager::msActiveZoneList - 24) )
      return 0i64;
    mpRegion = i->mpRegion;
    if ( mpRegion )
    {
      if ( mpRegion != v22 )
        break;
    }
LABEL_16:
    ++v23;
  }
  v22 = i->mpRegion;
  if ( v23 >= 0xA )
    return 0i64;
  UFG::PedSpawnManager::msZoneDoingSpawnNow = i;
  this->mSpawningModeNow = FromRegion;
  m_pPointer = UFG::SpawnRegion::Spawn(i->mpRegion, 0, 0i64, 1);
  if ( !m_pPointer )
  {
    UFG::PedSpawnManager::msZoneDoingSpawnNow = 0i64;
    goto LABEL_16;
  }
  v10 = UFG::PedSpawnManager::msLastRegisteredPedInfo;
  UFG::GroupComponent::MakeSingle(UFG::PedSpawnManager::msLastRegisteredPedInfo->mGroupComponent, 1);
  UFG::PedSpawnManager::ChangeStatusToActive(this, v10);
  v26 = v10->mSimObjectPtr.m_pPointer;
  if ( v26 )
    m_pComponent = v26->m_Components.p[9].m_pComponent;
  v27 = *(Creature **)&m_pComponent[2].m_TypeUID;
  if ( v27 )
    Creature::DestroyAllAttachments(v27, v26, 0);
LABEL_21:
  if ( newPedInfo )
    *newPedInfo = v10;
LABEL_23:
  if ( m_pPointer )
  {
    p = m_pPointer->m_Components.p;
    v29 = (UFG::InventoryComponent *)p[39].m_pComponent;
    if ( v29 )
    {
      UFG::InventoryComponent::UnEquip(
        (UFG::InventoryComponent *)p[39].m_pComponent,
        eINVENTORY_EQUIP_SLOT_RIGHT_HAND,
        1);
      UFG::InventoryComponent::UnEquip(v29, eINVENTORY_EQUIP_SLOT_LEFT_HAND, 1);
    }
  }
  return (UFG::SimObjectCharacter *)m_pPointer;
}

// File Line: 4722
// RVA: 0x414B60
void __fastcall UFG::PedSpawnManager::RegisterPed(
        UFG::PedSpawnManager *this,
        UFG::SimObjectCharacter *pedToRegister,
        UFG::qPropertySet *pArchetypePropSet,
        UFG::qPropertySet *pInstancePropertySet,
        UFG::qWiseSymbol IsAmbientRegionPed,
        bool canSuspend,
        bool called_from_skookum)
{
  UFG::qPropertySet *v7; // rdi
  UFG::qPropertySet *ParentFromIdx; // rax
  UFG::SimComponent *v12; // r14
  UFG::SimObjectCharacterPropertiesComponent *v13; // rax
  bool v14; // r12
  UFG::PedSpawningInfo *v15; // rbx
  UFG::PedSpawningInfo::eActiveStatus v16; // edx
  UFG::SpawnZone *v17; // r8
  UFG::qSafePointer<UFG::SpawnZone,UFG::SpawnZone> *p_mCreationSpawnZone; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SpawnZone>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SpawnZone>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SpawnZone>,UFG::qSafePointerNodeList> *v21; // rax
  unsigned int mUID; // eax
  UFG::AnimationLODComponent *m_pComponent; // rcx
  UFG::qPropertySet *v24; // rcx
  bool *v25; // rax
  bool v26; // di
  unsigned int v27; // edi
  __int64 v28; // rsi
  UFG::SceneObjectProperties *m_pSceneObj; // rcx
  UFG::qPropertySet *mpWritableProperties; // rax
  unsigned int v31; // ebx
  UFG::PedSpawningInfo::eActiveStatus v32; // edx
  UFG::SpawnZone *v33; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SpawnZone>,UFG::qSafePointerNodeList> *v34; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SpawnZone>,UFG::qSafePointerNodeList> *v35; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SpawnZone>,UFG::qSafePointerNodeList> *v36; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SpawnZone>,UFG::qSafePointerNodeList> *v37; // rax
  unsigned int v38; // eax
  bool *v39; // rax
  bool v40; // bl
  unsigned int *v41; // rax
  bool *v42; // rax
  unsigned int v43; // edi
  UFG::SimObjectModifier v44; // [rsp+38h] [rbp-50h] BYREF

  v7 = pInstancePropertySet;
  if ( pInstancePropertySet )
  {
    ParentFromIdx = (UFG::qPropertySet *)UFG::qPropertySet::GetParentFromIdx(pInstancePropertySet, 0);
    if ( pArchetypePropSet != ParentFromIdx )
    {
      v7 = ParentFromIdx;
      UFG::qPropertySet::GetParentFromIdx(ParentFromIdx, 0);
    }
  }
  v12 = 0i64;
  if ( pedToRegister )
    v13 = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectCharacterPropertiesComponent>(pedToRegister);
  else
    v13 = 0i64;
  v14 = (v13->m_Flags & 2) != 0;
  UFG::PedSpawnManager::msLastRegistered = pedToRegister;
  if ( !LOBYTE(IsAmbientRegionPed.mUID) )
  {
    if ( UFG::PedSpawnManager::msScriptedCount[0] <= 0 )
      return;
    v15 = (UFG::PedSpawningInfo *)&UFG::PedSpawnManager::msScriptedList[0].mNode.mNext[-4];
    UFG::PedSpawningInfo::SetSimObjectPtr(
      (UFG::PedSpawningInfo *)&UFG::PedSpawnManager::msScriptedList[0].mNode.mNext[-4],
      pedToRegister);
    UFG::PedSpawningInfo::SetTrueCrowdSignatureFromCurrentSimObject(v15);
    UFG::PedSpawningInfo::SetPropListFromCurrentSimObject(v15);
    v16 = Active;
    if ( v14 )
      v16 = NormalSuspend;
    UFG::PedSpawningInfo::SetActiveStatus(v15, v16);
    if ( UFG::PedSpawnManager::msScriptedStatusCheckEnable || called_from_skookum )
      goto LABEL_18;
    if ( v15->mActiveStatus == Active )
    {
      UFG::SimObject::Suspend(v15->mSimObjectPtr.m_pPointer);
      v15->mTeleportOnResumeRequired = 0;
    }
    else if ( v15->mActiveStatus != ExtraLowPower )
    {
LABEL_18:
      v15->mCanSuspendScripted = !canSuspend;
      v15->mTeleportOnResumeRequired = 0;
      v15->mSpawnTime = UFG::PedSpawnManager::msElapsedTotal;
      v15->mIsDead = 0;
      v15->mHowSpawned = this->mSpawningModeNow;
      v17 = UFG::PedSpawnManager::msZoneDoingSpawnNow;
      p_mCreationSpawnZone = &v15->mCreationSpawnZone;
      if ( v15->mCreationSpawnZone.m_pPointer )
      {
        mPrev = p_mCreationSpawnZone->mPrev;
        mNext = v15->mCreationSpawnZone.mNext;
        mPrev->mNext = mNext;
        mNext->mPrev = mPrev;
        p_mCreationSpawnZone->mPrev = p_mCreationSpawnZone;
        v15->mCreationSpawnZone.mNext = &v15->mCreationSpawnZone;
      }
      v15->mCreationSpawnZone.m_pPointer = v17;
      if ( v17 )
      {
        v21 = v17->m_SafePointerList.mNode.UFG::qSafePointerNode<UFG::SpawnZone>::mPrev;
        v21->mNext = p_mCreationSpawnZone;
        p_mCreationSpawnZone->mPrev = v21;
        v15->mCreationSpawnZone.mNext = &v17->m_SafePointerList.mNode;
        v17->m_SafePointerList.mNode.UFG::qSafePointerNode<UFG::SpawnZone>::mPrev = p_mCreationSpawnZone;
      }
      if ( pArchetypePropSet )
        mUID = pArchetypePropSet->mName.mUID;
      else
        mUID = UFG::gNullQSymbol.mUID;
      v15->mArchetypePropSetSymbol.mUID = mUID;
      if ( v7 )
      {
        v15->mPropSetSymbol.mUID = v7->mName.mUID;
        if ( UFG::SpawnInfoInterface::ShouldLockActive(v7) )
        {
          UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&v7->mName);
          UFG::qPrintChannel::Print(&UFG::gPrintChannel_HK_Spawning, "Index %d - Locking scripted ped %s active!\n");
          v15->mCanSuspendScripted |= 2u;
        }
        if ( pedToRegister )
        {
          m_pComponent = (UFG::AnimationLODComponent *)pedToRegister->m_Components.p[13].m_pComponent;
          if ( m_pComponent )
            UFG::AnimationLODComponent::SetExtendedLOD(m_pComponent, 1);
        }
        v24 = v7;
      }
      else
      {
        v15->mPropSetSymbol.mUID = pArchetypePropSet->mName.mUID;
        v24 = pArchetypePropSet;
      }
      v25 = UFG::qPropertySet::Get<bool>(
              v24,
              (UFG::qArray<unsigned long,0> *)&qSymbol_AllowedToUseCrosswalks,
              DEPTH_RECURSE);
      if ( v25 )
        v26 = *v25;
      else
        v26 = 0;
      UFG::GroupComponent::Reset(v15->mGroupComponent);
      v15->mProxyAIComponent->mAILCanUseCrosswalks = v26;
      if ( pedToRegister )
        v12 = pedToRegister->m_Components.p[22].m_pComponent;
      HIBYTE(v12[20].m_BoundComponentHandles.mNode.mPrev) = v26;
      UFG::PedSpawnManager::msLastRegisteredPedInfo = v15;
      v15->mLifetimeInstanceNameSymbol.mUID = UFG::qSymbol::qSymbol(&IsAmbientRegionPed, pedToRegister->mNode.mUID)->mUID;
      if ( (pedToRegister->m_Flags & 0x4000) != 0 )
        v27 = 48;
      else
        v27 = -1;
      UFG::SimObjectModifier::SimObjectModifier(&v44, pedToRegister, 1);
      UFG::SimObjectModifier::AttachComponent(&v44, v15, v27);
      UFG::SimObjectModifier::Close(&v44);
      UFG::SimObjectModifier::~SimObjectModifier(&v44);
      v15->m_Flags &= ~8u;
      return;
    }
    v15->mSuspendedTime = 0.0;
    UFG::PedSpawningInfo::SetActiveStatus(v15, NormalSuspend);
    goto LABEL_18;
  }
  if ( UFG::PedSpawnManager::msAmbientCount[0] > 0 )
  {
    v28 = qword_1423DEF68 - 64;
    m_pSceneObj = pedToRegister->m_pSceneObj;
    mpWritableProperties = m_pSceneObj->mpWritableProperties;
    if ( !mpWritableProperties )
      mpWritableProperties = m_pSceneObj->mpConstProperties;
    v31 = mpWritableProperties->mName.mUID;
    UFG::PedSpawningInfo::SetSimObjectPtr((UFG::PedSpawningInfo *)(qword_1423DEF68 - 64), pedToRegister);
    UFG::PedSpawningInfo::SetTrueCrowdSignatureFromCurrentSimObject((UFG::PedSpawningInfo *)v28);
    UFG::PedSpawningInfo::SetPropListFromCurrentSimObject((UFG::PedSpawningInfo *)v28);
    v32 = Active;
    if ( v14 )
      v32 = NormalSuspend;
    UFG::PedSpawningInfo::SetActiveStatus((UFG::PedSpawningInfo *)v28, v32);
    *(_DWORD *)(v28 + 676) = 0;
    *(_BYTE *)(v28 + 764) = 0;
    *(float *)(v28 + 760) = UFG::PedSpawnManager::msElapsedTotal;
    *(_BYTE *)(v28 + 348) = 0;
    *(_DWORD *)(v28 + 744) = this->mSpawningModeNow;
    v33 = UFG::PedSpawnManager::msZoneDoingSpawnNow;
    v34 = (UFG::qNode<UFG::qSafePointerBase<UFG::SpawnZone>,UFG::qSafePointerNodeList> *)(v28 + 144);
    if ( *(_QWORD *)(v28 + 160) )
    {
      v35 = v34->mPrev;
      v36 = *(UFG::qNode<UFG::qSafePointerBase<UFG::SpawnZone>,UFG::qSafePointerNodeList> **)(v28 + 152);
      v35->mNext = v36;
      v36->mPrev = v35;
      v34->mPrev = v34;
      *(_QWORD *)(v28 + 152) = v28 + 144;
    }
    *(_QWORD *)(v28 + 160) = v33;
    if ( v33 )
    {
      v37 = v33->m_SafePointerList.mNode.UFG::qSafePointerNode<UFG::SpawnZone>::mPrev;
      v37->mNext = v34;
      v34->mPrev = v37;
      *(_QWORD *)(v28 + 152) = &v33->m_SafePointerList;
      v33->m_SafePointerList.mNode.UFG::qSafePointerNode<UFG::SpawnZone>::mPrev = v34;
    }
    *(_DWORD *)(v28 + 644) = v31;
    UFG::GroupComponent::Reset(*(UFG::GroupComponent **)(v28 + 256));
    if ( pArchetypePropSet )
      v38 = pArchetypePropSet->mName.mUID;
    else
      v38 = UFG::gNullQSymbol.mUID;
    *(_DWORD *)(v28 + 648) = v38;
    if ( this->mSpawningModeNow == FromPoint && v7 )
    {
      *(_DWORD *)(v28 + 644) = v7->mName.mUID;
      v39 = UFG::qPropertySet::Get<bool>(
              v7,
              (UFG::qArray<unsigned long,0> *)&qSymbol_AllowedToUseCrosswalks,
              DEPTH_RECURSE);
      if ( v39 )
        v40 = *v39;
      else
        v40 = 0;
      v41 = UFG::qPropertySet::Get<unsigned long>(v7, (UFG::qArray<unsigned long,0> *)&qSymbol_ThugBlip, DEPTH_RECURSE);
      if ( v41 )
        LODWORD(v12) = *v41;
      *(_DWORD *)(v28 + 740) = (_DWORD)v12;
      if ( (_DWORD)v12 )
        UFG::SimObjectUtility::AttachHudSymbol(
          *(UFG::SimObject **)(v28 + 192),
          "enemy_noncombat",
          0,
          0.0,
          &customCaption);
    }
    else
    {
      *(_DWORD *)(v28 + 644) = pArchetypePropSet->mName.mUID;
      v42 = UFG::qPropertySet::Get<bool>(
              pArchetypePropSet,
              (UFG::qArray<unsigned long,0> *)&qSymbol_AllowedToUseCrosswalks,
              DEPTH_RECURSE);
      if ( v42 )
        v40 = *v42;
      else
        v40 = 0;
    }
    *(_BYTE *)(*(_QWORD *)(v28 + 248) + 88i64) = v40;
    HIBYTE(pedToRegister->m_Components.p[22].m_pComponent[20].m_BoundComponentHandles.mNode.mPrev) = v40;
    UFG::PedSpawnManager::msLastRegisteredPedInfo = (UFG::PedSpawningInfo *)v28;
    *(UFG::qWiseSymbol *)(v28 + 352) = (UFG::qWiseSymbol)UFG::qSymbol::qSymbol(
                                                           &IsAmbientRegionPed,
                                                           pedToRegister->mNode.mUID)->mUID;
    if ( (pedToRegister->m_Flags & 0x4000) != 0 )
      v43 = 48;
    else
      v43 = -1;
    UFG::SimObjectModifier::SimObjectModifier(&v44, pedToRegister, 1);
    UFG::SimObjectModifier::AttachComponent(&v44, (UFG::SimComponent *)v28, v43);
    UFG::SimObjectModifier::Close(&v44);
    UFG::SimObjectModifier::~SimObjectModifier(&v44);
    *(_WORD *)(v28 + 32) &= ~8u;
  }
}

// File Line: 4978
// RVA: 0x416AA0
char __fastcall UFG::PedSpawnManager::SetSuspendOption(
        UFG::PedSpawnManager *this,
        UFG::SimObjectGame *pedSimObj,
        UFG::PedSpawningInfo::eSuspendAction suspendAction)
{
  signed __int16 m_Flags; // cx
  UFG::PedSpawningInfo *m_pComponent; // rcx
  UFG::PedSpawningInfo *v6; // rax

  if ( !pedSimObj )
    return 0;
  m_Flags = pedSimObj->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
  {
    m_pComponent = (UFG::PedSpawningInfo *)pedSimObj->m_Components.p[48].m_pComponent;
  }
  else
  {
    v6 = (UFG::PedSpawningInfo *)(m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
                                ? UFG::SimObjectGame::GetComponentOfTypeHK(pedSimObj, UFG::PedSpawningInfo::_TypeUID)
                                : UFG::SimObject::GetComponentOfType(pedSimObj, UFG::PedSpawningInfo::_TypeUID));
    m_pComponent = v6;
  }
  if ( !m_pComponent || m_pComponent->mPedType != ScriptedPed )
    return 0;
  m_pComponent->mCanSuspendScripted = suspendAction | m_pComponent->mCanSuspendScripted & 0x20;
  return 1;
}

// File Line: 5039
// RVA: 0x4172C0
signed __int64 __fastcall UFG::PedSpawnManager::SpawnPedsInActiveZones(UFG::PedSpawnManager *this, int howManyToSpawn)
{
  int v2; // edi
  UFG::PedSpawnManager *v3; // rbx
  int v4; // r13d
  int v5; // esi
  __int64 v6; // rbp
  UFG::SpawnZone *v7; // r14
  CullResults *mCullResults; // r8
  float v9; // xmm1_4
  int v10; // r12d
  UFG::GroupManager *Instance; // rax
  int v12; // r15d
  bool v13; // r13
  int PedsToRepurpose; // eax
  __int64 v15; // rbx
  __int64 v16; // rdi
  UFG::SimObject *m_pPointer; // rcx
  UFG::qPropertySet *SpawnableResource; // rdi
  int v19; // eax
  UFG::PedSpawningInfo *v20; // rax
  float y; // xmm1_4
  float z; // xmm2_4
  UFG::SimObject *v23; // rbx
  UFG::InterestPoint *InterestPoint; // rsi
  UFG::SimComponent *ComponentOfType; // rdi
  UFG::InterestPointUserComponent *v26; // rbp
  UFG::allocator::free_link *v27; // rax
  int v28; // r13d
  int v29; // ecx
  int v31; // [rsp+30h] [rbp-D8h]
  UFG::qVector3 newPoint; // [rsp+38h] [rbp-D0h] BYREF
  UFG::qSymbol skipIntoLabel; // [rsp+48h] [rbp-C0h] BYREF
  __int64 v34; // [rsp+50h] [rbp-B8h]
  __int64 v35; // [rsp+58h] [rbp-B0h]
  UFG::allocator::free_link *v36; // [rsp+60h] [rbp-A8h]
  UFG::qMatrix44 outputMatrix; // [rsp+70h] [rbp-98h] BYREF
  bool v40; // [rsp+120h] [rbp+18h]
  int i; // [rsp+128h] [rbp+20h]

  v35 = -2i64;
  v2 = howManyToSpawn;
  v3 = this;
  if ( UFG::PedSpawnManager::msNumValidTopUpZones > 0 )
  {
    v4 = UFG::qRandom(UFG::PedSpawnManager::msNumValidTopUpZones, (unsigned int *)&UFG::qDefaultSeed);
    v31 = v4;
    v5 = 0;
    for ( i = 0; v5 < v2; v31 = v29 )
    {
      v6 = v4;
      v34 = v4;
      v7 = UFG::PedSpawnManager::msValidTopUpZones[v4];
      if ( !v7 )
        break;
      if ( !v7->mIsThugZone || !UFG::PedSpawnManager::ThugZoneDisabled(v3, UFG::PedSpawnManager::msValidTopUpZones[v4]) )
      {
        v7->mHasBeenActivated = 1;
        v40 = 0;
        mCullResults = v7->mCullResults;
        if ( mCullResults && (gMainCullIndex < 0 || mCullResults->mViewResult[gMainCullIndex] <= 1u) )
        {
          if ( gMainCullIndex >= 6 )
            v9 = 0.0;
          else
            v9 = mCullResults->mDistance[gMainCullIndex];
          v40 = (float)(UFG::PedSpawnManager::msWorkingFullyActiveDistance * 0.75) > v9;
        }
        v10 = 1;
        if ( UFG::SpawnRegion::IsGroupsAllowed(v7->mpRegion) )
        {
          Instance = UFG::GroupManager::GetInstance();
          v10 = 1 - UFG::GroupManager::GetNumGroupMembersToSpawn(Instance, 1);
        }
        v12 = 0;
        v13 = v40;
        do
        {
          if ( 260 - UFG::PedSpawnManager::msAmbientCount[0] >= 245 )
          {
            PedsToRepurpose = UFG::PedSpawnManager::FindPedsToRepurpose(v3, -1, 1 - v12, v13);
            v15 = 0i64;
            v16 = PedsToRepurpose;
            if ( PedsToRepurpose > 0 )
            {
              do
              {
                m_pPointer = UFG::PedSpawnManager::mNewRepurposeList[v15]->mSimObjectPtr.m_pPointer;
                if ( m_pPointer )
                {
                  if ( m_pPointer->m_pSceneObj->mpParent )
                    UFG::SceneObjectProperties::DeactivateDeferred(m_pPointer->m_pSceneObj);
                  else
                    UFG::SimObject::Destroy(m_pPointer);
                }
                ++v15;
              }
              while ( v15 < v16 );
              v13 = v40;
            }
            if ( 260 - UFG::PedSpawnManager::msAmbientCount[0] >= 245 )
              break;
          }
          UFG::SpawnZone::CalcSpawnPoint(v7, &newPoint);
          SpawnableResource = UFG::SpawnRegion::GetSpawnableResource(v7->mpRegion, 1, &newPoint);
          if ( SpawnableResource )
          {
            UFG::PedSpawnManager::msZoneDoingSpawnNow = v7;
            v19 = 260
                - UFG::PedSpawnManager::msAmbientCount[0]
                + 120
                - UFG::PedSpawnManager::msScriptedCount[0]
                - UFG::gMaxTotalFullSimPeds;
            if ( 260 - UFG::PedSpawnManager::msAmbientCount[0] - UFG::gMaxAmbientSimObjects > v19 )
              v19 = 260 - UFG::PedSpawnManager::msAmbientCount[0] - UFG::gMaxAmbientSimObjects;
            if ( v19 + 1 <= 0 )
            {
              if ( UFG::SpawnRegion::Spawn(v7->mpRegion, 1, &newPoint, 0) )
              {
                v20 = UFG::PedSpawnManager::msLastRegisteredPedInfo;
                y = newPoint.y;
                z = newPoint.z;
                UFG::PedSpawnManager::msLastRegisteredPedInfo->mCurrentLocation.x = newPoint.x;
                v20->mCurrentLocation.y = y;
                v20->mCurrentLocation.z = z;
                if ( v10 > 0
                  && !UFG::PedSpawnManager::msLastRegisteredPedInfo->mCharacterOccupantComponent.m_pSimComponent )
                {
                  v23 = UFG::PedSpawnManager::msLastRegisteredPedInfo->mSimObjectPtr.m_pPointer;
                  InterestPoint = UFG::SpawnRegion::GetInterestPoint(
                                    v7->mpRegion,
                                    &newPoint,
                                    SpawnableResource,
                                    v12 + 1,
                                    v23);
                  if ( InterestPoint )
                  {
                    ComponentOfType = UFG::SimObject::GetComponentOfType(v23, UFG::ActiveAIEntityComponent::_TypeUID);
                    v26 = (UFG::InterestPointUserComponent *)UFG::SimObject::GetComponentOfType(
                                                               v23,
                                                               UFG::InterestPointUserComponent::_TypeUID);
                    if ( v26 )
                    {
                      if ( ComponentOfType )
                      {
                        --v10;
                        UFG::GetInterestPointUpRightMatrix(InterestPoint, &outputMatrix);
                        v27 = UFG::qMalloc(0x90ui64, "TeleportEvent", 0i64);
                        v36 = v27;
                        if ( v27 )
                          UFG::TeleportEvent::TeleportEvent(
                            (UFG::TeleportEvent *)v27,
                            &outputMatrix,
                            v23->mNode.mUID,
                            0,
                            UFG::TeleportEvent::m_Name,
                            0);
                        UFG::EventDispatcher::DispatchEvent(&UFG::EventDispatcher::mInstance, (UFG::Event *)v27);
                        skipIntoLabel.mUID = -1;
                        UFG::InterestPointUserComponent::UsePOI(v26, InterestPoint, ePOIUseType_Script, &skipIntoLabel);
                      }
                    }
                  }
                }
              }
            }
            UFG::PedSpawnManager::msZoneDoingSpawnNow = 0i64;
          }
          ++v12;
          v3 = this;
        }
        while ( v12 < 1 );
        v4 = v31;
        v3 = this;
        v5 = i;
        v6 = v34;
        v2 = howManyToSpawn;
      }
      UFG::PedSpawnManager::msValidTopUpZones[v6] = 0i64;
      v7->mTimeStamp = UFG::PedSpawnManager::msElapsedTotal;
      i = ++v5;
      v28 = v4 + 1;
      v29 = 0;
      if ( v28 < UFG::PedSpawnManager::msNumValidTopUpZones )
        v29 = v28;
      v4 = v29;
    }
  }
  return 1i64;
}

// File Line: 5079
// RVA: 0x40DD00
char __fastcall UFG::PedSpawnManager::IsPedValidForSet(
        UFG::PedSpawnManager *this,
        int indexOfRequiredSpawnSet,
        UFG::PedSpawningInfo *pedInfo)
{
  __int64 v3; // rbx
  UFG::qSymbol *ArchetypePropertySetName; // rax
  UFG::qPropertySet *PropertySet; // rax
  int v7; // edx
  unsigned int size; // r8d
  UFG::qPropertySet **i; // rcx
  UFG::qSymbol result; // [rsp+48h] [rbp+20h] BYREF

  v3 = indexOfRequiredSpawnSet;
  ArchetypePropertySetName = UFG::PedSpawningInfo::GetArchetypePropertySetName(pedInfo, &result);
  PropertySet = UFG::PropertySetManager::FindPropertySet(ArchetypePropertySetName);
  if ( !PropertySet )
    return 0;
  v7 = 0;
  size = this->mActiveSpawnSets[v3].mSpawnInfoArray.size;
  if ( !size )
    return 0;
  for ( i = this->mActiveSpawnSets[v3].mSpawnInfoArray.p; PropertySet != *i; ++i )
  {
    if ( ++v7 >= size )
      return 0;
  }
  return 1;
}

// File Line: 5099
// RVA: 0x40E0C0
bool __fastcall UFG::PedSpawnManager::IsValidPedForRepurpose(
        UFG::PedSpawnManager *this,
        UFG::PedSpawningInfo *pedInfo,
        bool isHighPriority,
        float *dist)
{
  UFG::PedSpawningInfo::eActiveStatus mActiveStatus; // eax
  bool result; // al
  float mDistInCameraSpace; // xmm1_4
  float v7; // xmm2_4

  *dist = UFG::PedSpawnManager::msZoneActivateDist;
  mActiveStatus = pedInfo->mActiveStatus;
  if ( mActiveStatus == ExtraLowPower )
  {
    *dist = pedInfo->mDistInCameraSpace;
    return pedInfo->mCulledTime > 3.0 || isHighPriority;
  }
  if ( mActiveStatus != NormalSuspend || pedInfo->mCulledTime <= 1.0 )
    return 0;
  mDistInCameraSpace = pedInfo->mDistInCameraSpace;
  *dist = mDistInCameraSpace;
  if ( isHighPriority )
    v7 = FLOAT_0_44999999;
  else
    v7 = FLOAT_0_69999999;
  if ( pedInfo->mCreationSpawnZone.m_pPointer
    && mDistInCameraSpace <= (float)(UFG::PedSpawnManager::msWorkingFullyActiveDistance * v7) )
  {
    result = 0;
    *dist = mDistInCameraSpace * 0.5;
  }
  else
  {
    result = 1;
    *dist = mDistInCameraSpace * 0.5;
  }
  return result;
}

// File Line: 5121
// RVA: 0x40C5D0
void __fastcall UFG::PedSpawnManager::GetNewNearestFromArray(
        UFG::PedSpawnManager *this,
        UFG::PedSpawningInfo **arrayOfInfo,
        unsigned int *index,
        float *dist,
        int how_many_needed)
{
  unsigned int v5; // ecx
  __int64 v6; // rsi
  unsigned int v7; // r11d
  UFG::PedSpawningInfo **v8; // r10
  float mBiasedDist; // xmm0_4
  float v10; // xmm0_4
  float v11; // xmm0_4
  float v12; // xmm0_4
  UFG::PedSpawningInfo **v13; // rdx
  float v14; // xmm0_4

  v5 = 0;
  *dist = 3.4028235e38;
  v6 = 0i64;
  if ( how_many_needed >= 4 )
  {
    v7 = 2;
    v8 = arrayOfInfo + 2;
    v6 = 4i64 * (((unsigned int)(how_many_needed - 4) >> 2) + 1);
    do
    {
      mBiasedDist = (*(v8 - 2))->mBiasedDist;
      if ( mBiasedDist < *dist )
      {
        *dist = mBiasedDist;
        *index = v5;
      }
      v10 = (*(v8 - 1))->mBiasedDist;
      if ( v10 < *dist )
      {
        *dist = v10;
        *index = v7 - 1;
      }
      v11 = (*v8)->mBiasedDist;
      if ( v11 < *dist )
      {
        *dist = v11;
        *index = v7;
      }
      v12 = v8[1]->mBiasedDist;
      if ( v12 < *dist )
      {
        *dist = v12;
        *index = v7 + 1;
      }
      v5 += 4;
      v8 += 4;
      v7 += 4;
    }
    while ( v5 < how_many_needed - 3 );
  }
  if ( v5 < how_many_needed )
  {
    v13 = &arrayOfInfo[v6];
    do
    {
      v14 = (*v13)->mBiasedDist;
      if ( v14 < *dist )
      {
        *dist = v14;
        *index = v5;
      }
      ++v5;
      ++v13;
    }
    while ( v5 < how_many_needed );
  }
}

// File Line: 5135
// RVA: 0x40B740
__int64 __fastcall UFG::PedSpawnManager::FindPedsToRepurpose(
        UFG::PedSpawnManager *this,
        int indexOfRequiredSpawnSet,
        unsigned int how_many_needed,
        bool isHighPriority)
{
  unsigned int v4; // ebx
  unsigned int v5; // esi
  float v6; // xmm6_4
  UFG::BaseCameraComponent *mCurrentCamera; // rax
  __int64 v11; // r14
  UFG::eHowSpawned *i; // rdi
  UFG::SimObject *v13; // rcx
  UFG::PedSpawningInfo *v14; // rbp
  float v15; // xmm0_4
  __int64 v16; // rax
  float dist; // [rsp+30h] [rbp-58h] BYREF
  unsigned int index[3]; // [rsp+34h] [rbp-54h] BYREF
  float v20; // [rsp+A0h] [rbp+18h] BYREF

  v4 = 0;
  v5 = 5;
  v6 = 0.0;
  if ( how_many_needed < 5 )
    v5 = how_many_needed;
  v20 = 0.0;
  index[0] = 0;
  if ( v5 )
    memset(UFG::PedSpawnManager::mNewRepurposeList, 0, 8i64 * v5);
  mCurrentCamera = UFG::Director::Get()->mCurrentCamera;
  if ( mCurrentCamera && mCurrentCamera != (UFG::BaseCameraComponent *)-80i64 && v5 )
  {
    v11 = 0i64;
    for ( i = &this->mAmbientPed[0].mHowSpawned; ; i += 206 )
    {
      v13 = (UFG::SimObject *)*((_QWORD *)i - 69);
      if ( v13
        && *i == FromRegion
        && v13->m_Components.p[27].m_pComponent
        && !UFG::SkookumMgr::IsReferencedByScripts(v13)
        && *((_BYTE *)i - 396) != 1
        && (indexOfRequiredSpawnSet < 0
         || UFG::PedSpawnManager::IsPedValidForSet(this, indexOfRequiredSpawnSet, (UFG::PedSpawningInfo *)(i - 186))) )
      {
        v14 = (UFG::PedSpawningInfo *)(i - 186);
        dist = 0.0;
        if ( UFG::PedSpawnManager::IsValidPedForRepurpose(
               this,
               (UFG::PedSpawningInfo *)(i - 186),
               isHighPriority,
               &dist) )
        {
          v15 = dist;
          if ( v4 >= v5 )
          {
            if ( dist > v6 )
            {
              UFG::PedSpawnManager::mNewRepurposeList[index[0]] = v14;
              *((float *)i + 13) = v15;
              UFG::PedSpawnManager::GetNewNearestFromArray(
                this,
                UFG::PedSpawnManager::mNewRepurposeList,
                index,
                &v20,
                v5);
              v6 = v20;
            }
          }
          else
          {
            v16 = v4++;
            UFG::PedSpawnManager::mNewRepurposeList[v16] = v14;
            *((float *)i + 13) = v15;
            if ( v4 == v5 )
            {
              UFG::PedSpawnManager::GetNewNearestFromArray(
                this,
                UFG::PedSpawnManager::mNewRepurposeList,
                index,
                &v20,
                v5);
              v6 = v20;
              if ( v20 > (float)(UFG::PedSpawnManager::msZoneActivateDist - 1.0) )
                return v4;
            }
          }
        }
      }
      if ( ++v11 >= 260 )
        return v4;
    }
  }
  return 0i64;
}

// File Line: 5209
// RVA: 0x40B550
UFG::SimObject **__fastcall UFG::PedSpawnManager::FindPedToRepurposeForVehicle(
        UFG::PedSpawnManager *this,
        UFG::qPropertyList *classPriorities,
        UFG::qPropertyList *classExclusions)
{
  __int64 v6; // rbp
  __int64 v7; // rsi
  UFG::SimObject **p_m_pPointer; // rbx
  UFG::SimObject *v9; // rdi
  int v10; // eax
  UFG::SimObject *v11; // rdi
  int v12; // eax

  v6 = 259i64;
  if ( classPriorities )
  {
    v7 = 259i64;
    p_m_pPointer = &this->mAmbientPed[259].mSimObjectPtr.m_pPointer;
    while ( 1 )
    {
      v9 = *p_m_pPointer;
      if ( *p_m_pPointer )
      {
        if ( *((_DWORD *)p_m_pPointer + 138) == 1
          && !p_m_pPointer[16]
          && UFG::VehicleUtility::IsDriverTypeInList(*p_m_pPointer, classPriorities)
          && !UFG::VehicleUtility::IsDriverTypeInList(*p_m_pPointer, classExclusions) )
        {
          if ( v9->m_Components.p[27].m_pComponent )
          {
            if ( !UFG::SkookumMgr::IsReferencedByScripts(v9) && *((_BYTE *)p_m_pPointer + 156) != 1 )
            {
              v10 = *((_DWORD *)p_m_pPointer - 6);
              if ( v10 == 2
                || v10 == 3
                && *((float *)p_m_pPointer - 14) > 1.0
                && (!*(p_m_pPointer - 4)
                 || *((float *)p_m_pPointer + 150) > (float)(UFG::PedSpawnManager::msWorkingFullyActiveDistance
                                                           * 0.44999999)) )
              {
                break;
              }
            }
          }
        }
      }
      p_m_pPointer -= 103;
      if ( --v7 < 0 )
        goto LABEL_17;
    }
  }
  else
  {
LABEL_17:
    for ( p_m_pPointer = &this->mAmbientPed[259].mSimObjectPtr.m_pPointer; ; p_m_pPointer -= 103 )
    {
      v11 = *p_m_pPointer;
      if ( *p_m_pPointer )
      {
        if ( *((_DWORD *)p_m_pPointer + 138) == 1
          && !UFG::VehicleUtility::IsDriverTypeInList(*p_m_pPointer, classExclusions) )
        {
          if ( v11->m_Components.p[27].m_pComponent )
          {
            if ( !UFG::SkookumMgr::IsReferencedByScripts(v11)
              && !p_m_pPointer[16]
              && *((_BYTE *)p_m_pPointer + 156) != 1 )
            {
              v12 = *((_DWORD *)p_m_pPointer - 6);
              if ( v12 == 2
                || v12 == 3
                && *((float *)p_m_pPointer - 14) > 1.0
                && (!*(p_m_pPointer - 4)
                 || *((float *)p_m_pPointer + 150) > (float)(UFG::PedSpawnManager::msWorkingFullyActiveDistance
                                                           * 0.44999999)) )
              {
                break;
              }
            }
          }
        }
      }
      if ( --v6 < 0 )
        return 0i64;
    }
  }
  return p_m_pPointer - 24;
}

// File Line: 5332
// RVA: 0x414210
void __fastcall UFG::PedSpawnManager::ReducePedsWithSpecificModel(UFG::TrueCrowdModel *model, bool allowForcedRemoval)
{
  UFG::ResourceRequest *mRequest; // rdi
  int v4; // eax
  __int64 i; // rbx
  UFG::PedSpawningInfo *v6; // rdx
  UFG::SimObject *m_pPointer; // rcx
  unsigned int size; // ecx
  __int64 j; // rbx
  __int64 v10; // r9
  __int64 v11; // rdx
  char *v12; // r8
  UFG::MeshResourceLoader **p; // rcx
  _QWORD *mUserContext; // rax
  UFG::SimObject *v15; // rcx

  if ( UFG::gpPedSpawnManager )
  {
    mRequest = model->mRequest;
    if ( mRequest )
    {
      v4 = mRequest->mProxies.size - 1;
      for ( i = v4; i >= 0; --i )
      {
        v6 = mRequest->mProxies.p[i];
        if ( allowForcedRemoval )
        {
          if ( v6->mActiveStatus <= (unsigned int)NormalSuspend )
          {
LABEL_6:
            m_pPointer = v6->mSimObjectPtr.m_pPointer;
            if ( m_pPointer )
            {
              if ( m_pPointer->m_pSceneObj->mpParent )
                UFG::SceneObjectProperties::DeactivateDeferred(m_pPointer->m_pSceneObj);
              else
                UFG::SimObject::Destroy(m_pPointer);
            }
          }
        }
        else
        {
          switch ( v6->mActiveStatus )
          {
            case ExtraLowPower:
              goto LABEL_6;
            default:
              continue;
          }
        }
      }
      size = mRequest->mInstances.size;
      if ( size )
      {
        for ( j = 213416i64; j >= 0; j -= 824i64 )
        {
          v10 = size;
          v11 = 0i64;
          v12 = (char *)UFG::gpPedSpawnManager + j;
          p = mRequest->mInstances.p;
          while ( 1 )
          {
            mUserContext = (*p)->mUserContext;
            if ( mUserContext )
            {
              if ( *((_QWORD *)v12 + 30) == mUserContext[5] )
                break;
            }
            ++v11;
            ++p;
            if ( v11 >= v10 )
              goto $LN131;
          }
          if ( allowForcedRemoval )
          {
            if ( *((_DWORD *)v12 + 54) <= 3u )
            {
LABEL_22:
              v15 = (UFG::SimObject *)*((_QWORD *)v12 + 30);
              if ( v15 )
              {
                if ( v15->m_pSceneObj->mpParent )
                  UFG::SceneObjectProperties::DeactivateDeferred(v15->m_pSceneObj);
                else
                  UFG::SimObject::Destroy(v15);
              }
            }
          }
          else
          {
            switch ( *((_DWORD *)v12 + 54) )
            {
              case 2:
                goto LABEL_22;
              default:
                break;
            }
          }
$LN131:
          size = mRequest->mInstances.size;
          if ( !size )
            break;
        }
      }
    }
  }
}

// File Line: 5479
// RVA: 0x40BAB0
__int64 __fastcall UFG::PedSpawnManager::GetActiveZoneFromPoint(
        UFG::PedSpawnManager *this,
        UFG::qVector3 *raw_pos,
        UFG::PedSpawningInfo::eActiveStatus current_status)
{
  float z; // xmm0_4
  float x; // xmm1_4
  float v5; // xmm7_4
  float y; // xmm6_4
  float v7; // xmm0_4
  float v8; // xmm6_4
  __int64 result; // rax
  float v10; // xmm2_4
  UFG::qVector3 point; // [rsp+20h] [rbp-38h] BYREF

  z = raw_pos->z;
  x = raw_pos->x;
  v5 = *(float *)&FLOAT_1_0;
  y = raw_pos->y;
  point.x = raw_pos->x;
  v7 = z + 1.0;
  point.y = y;
  point.z = v7;
  if ( current_status != Active )
    v5 = 0.0;
  v8 = (float)((float)((float)(y - UFG::PedSpawnManager::msZone_centre.y)
                     * (float)(y - UFG::PedSpawnManager::msZone_centre.y))
             + (float)((float)(x - UFG::PedSpawnManager::msZone_centre.x)
                     * (float)(x - UFG::PedSpawnManager::msZone_centre.x)))
     + (float)((float)(v7 - UFG::PedSpawnManager::msZone_centre.z) * (float)(v7 - UFG::PedSpawnManager::msZone_centre.z));
  if ( v8 < (float)((float)(UFG::PedSpawnManager::msAlwaysActiveDistance + v5)
                  * (float)(UFG::PedSpawnManager::msAlwaysActiveDistance + v5)) )
    return 0i64;
  if ( v8 > (float)(UFG::PedSpawnManager::msAlwaysInactiveDistance * UFG::PedSpawnManager::msAlwaysInactiveDistance) )
    return 5i64;
  v10 = DistanceToFrustum(UFG::PedSpawnManager::msFrustum_planes, &point);
  if ( v10 >= (float)(v5 + 1.5) )
  {
    if ( v8 >= (float)((float)(UFG::PedSpawnManager::msPreferActiveMargin
                             + UFG::PedSpawnManager::msWorkingFullyActiveDistance)
                     * (float)(UFG::PedSpawnManager::msPreferActiveMargin
                             + UFG::PedSpawnManager::msWorkingFullyActiveDistance)) )
    {
      return (unsigned int)(UFG::PedSpawnManager::msPreferActiveMargin <= v10) + 3;
    }
    else
    {
      result = 3i64;
      if ( UFG::PedSpawnManager::msPreferActiveMargin > v10 )
        return 1i64;
    }
  }
  else
  {
    result = 0i64;
    if ( v8 >= (float)((float)(UFG::PedSpawnManager::msWorkingFullyActiveDistance + v5)
                     * (float)(UFG::PedSpawnManager::msWorkingFullyActiveDistance + v5)) )
    {
      LOBYTE(result) = (float)((float)(UFG::PedSpawnManager::msPreferActiveMargin
                                     + UFG::PedSpawnManager::msWorkingFullyActiveDistance)
                             * (float)(UFG::PedSpawnManager::msPreferActiveMargin
                                     + UFG::PedSpawnManager::msWorkingFullyActiveDistance)) <= v8;
      return (unsigned int)(result + 1);
    }
  }
  return result;
}

// File Line: 5572
// RVA: 0x40C1E0
signed __int64 __fastcall UFG::PedSpawnManager::GetIdealActiveStatus(
        UFG::PedSpawnManager *this,
        UFG::PedSpawningInfo *info)
{
  UFG::PedSpawningInfo::eActiveStatus mActiveStatus; // ecx
  UFG::eActiveZoneClass mLocationClassification; // r9d
  UFG::eHowSpawned v6; // edx
  __int32 v7; // ecx
  __int32 v8; // ecx
  UFG::SpawnZone *m_pPointer; // rax

  mActiveStatus = info->mActiveStatus;
  if ( !info->mPhysicsLoadedForLocation )
    return info->mCreationSpawnZone.m_pPointer != 0i64 ? 3 : 0;
  mLocationClassification = info->mLocationClassification;
  v6 = FromRegion;
  if ( mLocationClassification == Always_Inactive )
    return 0i64;
  v7 = mActiveStatus - 1;
  if ( v7 )
  {
    v8 = v7 - 1;
    if ( v8 )
    {
      if ( v8 == 1 && mLocationClassification > (unsigned int)FromRegion )
      {
        if ( info->mCulledTime <= 0.0 )
          return (unsigned int)info->mIsDead + 2;
        if ( info->mHowSpawned == FromRegion && !info->mCreationSpawnZone.m_pPointer )
        {
          if ( !info->mIsDead )
            return 0i64;
          goto LABEL_25;
        }
        return 3i64;
      }
      return (unsigned int)v6;
    }
    v6 = FromPoint;
    if ( mLocationClassification == Always_Active )
      return FromRegion;
    m_pPointer = info->mCreationSpawnZone.m_pPointer;
    if ( !m_pPointer && info->mCulledTime > 0.0 )
      return 0i64;
    if ( info->mIsDead )
    {
      if ( info->mCulledTime > 5.0 && UFG::PedSpawnManager::msNumDeadAmbientPeds > 14 )
      {
LABEL_25:
        ++UFG::PedSpawnManager::msDowngradesThisFrame;
        return 0i64;
      }
      return (unsigned int)v6;
    }
    if ( info->mCulledTime > 10.0
      && ((float)((float)((float)((float)(info->mCurrentLocation.y - m_pPointer->mZoneCentre.y)
                                * (float)(info->mCurrentLocation.y - m_pPointer->mZoneCentre.y))
                        + (float)((float)(info->mCurrentLocation.x - m_pPointer->mZoneCentre.x)
                                * (float)(info->mCurrentLocation.x - m_pPointer->mZoneCentre.x)))
                + (float)((float)(info->mCurrentLocation.z - m_pPointer->mZoneCentre.z)
                        * (float)(info->mCurrentLocation.z - m_pPointer->mZoneCentre.z))) > 400.0
       || info->mIsNearDeactivatedZones) )
    {
      return 0i64;
    }
  }
  else
  {
    if ( mLocationClassification == Always_Active )
      return (unsigned int)v6;
    if ( !info->mIsDead )
    {
      v6 = FromPoint;
      if ( mLocationClassification == FromRegion
        && UFG::PedSpawnManager::msTargetPedCount
         - UFG::PedSpawnManager::msScriptedCount[1]
         - UFG::PedSpawnManager::msAmbientCount[1] > 4 )
      {
        return FromRegion;
      }
      return (unsigned int)v6;
    }
    if ( UFG::PedSpawnManager::msNumDeadAmbientPeds > 24
      || UFG::PedSpawnManager::msNumDeadAmbientPeds > 14 && info->mCulledTime > 2.0 )
    {
      return 0i64;
    }
    if ( mLocationClassification != FromRegion )
      return 3i64;
  }
  return (unsigned int)v6;
}

// File Line: 5781
// RVA: 0x40E570
__int64 __fastcall UFG::PedSpawnManager::MakeRoomForMorePeds(
        UFG::PedSpawnManager *this,
        unsigned int how_many,
        bool high_priority)
{
  int PedsToRepurpose; // eax
  __int64 v4; // rbx
  __int64 i; // rsi
  UFG::SimObject *m_pPointer; // rcx

  PedsToRepurpose = UFG::PedSpawnManager::FindPedsToRepurpose(this, -1, how_many, high_priority);
  v4 = 0i64;
  for ( i = PedsToRepurpose; v4 < i; ++v4 )
  {
    m_pPointer = UFG::PedSpawnManager::mNewRepurposeList[v4]->mSimObjectPtr.m_pPointer;
    if ( m_pPointer )
    {
      if ( m_pPointer->m_pSceneObj->mpParent )
        UFG::SceneObjectProperties::DeactivateDeferred(m_pPointer->m_pSceneObj);
      else
        UFG::SimObject::Destroy(m_pPointer);
    }
  }
  return (unsigned int)i;
}

// File Line: 5803
// RVA: 0x417CB0
void UFG::PedSpawnManager::ToggleResourceResolution(void)
{
  bool v0; // si
  UFG::qNode<UFG::PedSpawningInfo,UFG::PedInfoList> **p_mNext; // r14
  __int64 v2; // rbp
  UFG::qList<UFG::PedSpawningInfo,UFG::PedInfoList,1,0> *v3; // rdi
  __int64 i; // rbx
  UFG::SimObject *v5; // rcx

  v0 = !NISManager::GetInstance()->mHighDefModelsEnabled;
  p_mNext = &UFG::PedSpawnManager::msScriptedList[0].mNode.mNext;
  v2 = 6i64;
  NISManager::GetInstance()->mHighDefModelsEnabled = v0;
  v3 = &UFG::PedSpawnManager::msScriptedList[-4];
  do
  {
    for ( i = (__int64)&(*p_mNext)[-4];
          (UFG::qList<UFG::PedSpawningInfo,UFG::PedInfoList,1,0> *)i != v3;
          i = *(_QWORD *)(i + 72) - 64i64 )
    {
      v5 = *(UFG::SimObject **)(i + 192);
      if ( v5 )
      {
        if ( v0 )
          UFG::SimObjectUtility::UpgradeModelResolution(v5);
        else
          UFG::SimObjectUtility::DowngradeModelResolution(v5);
      }
    }
    ++v3;
    p_mNext += 2;
    --v2;
  }
  while ( v2 );
}

// File Line: 5829
// RVA: 0x4166F0
void __fastcall UFG::PedSpawnManager::SetHighDefSpawning(UFG::PedSpawnManager *this, bool hi_def_setting)
{
  if ( NISManager::GetInstance()->mHighDefModelsEnabled != hi_def_setting )
    UFG::PedSpawnManager::ToggleResourceResolution();
}

// File Line: 5939
// RVA: 0x408850
void __fastcall UFG::PedSpawnManager::ChangeStatusToInactive(UFG::PedSpawnManager *this, UFG::PedSpawningInfo *pedInfo)
{
  UFG::SpawnZone *m_pPointer; // rax
  UFG::SimObject *v4; // rcx

  if ( pedInfo->mSimObjectPtr.m_pPointer )
  {
    if ( pedInfo->mHowSpawned == FromPoint && pedInfo->mPedType == AmbientPed )
    {
      m_pPointer = pedInfo->mCreationSpawnZone.m_pPointer;
      if ( m_pPointer )
      {
        if ( (float)((float)((float)((float)(m_pPointer->mZoneCentre.y - pedInfo->mCurrentLocation.y)
                                   * (float)(m_pPointer->mZoneCentre.y - pedInfo->mCurrentLocation.y))
                           + (float)((float)(m_pPointer->mZoneCentre.x - pedInfo->mCurrentLocation.x)
                                   * (float)(m_pPointer->mZoneCentre.x - pedInfo->mCurrentLocation.x)))
                   + (float)((float)(m_pPointer->mZoneCentre.z - pedInfo->mCurrentLocation.z)
                           * (float)(m_pPointer->mZoneCentre.z - pedInfo->mCurrentLocation.z))) < 4.0
          && m_pPointer->mZoneActiveStatus == ZoneActive )
        {
          m_pPointer->mZoneActiveStatus = ZoneNotActive;
        }
      }
    }
    v4 = pedInfo->mSimObjectPtr.m_pPointer;
    if ( v4 )
    {
      if ( v4->m_pSceneObj->mpParent )
        UFG::SceneObjectProperties::DeactivateDeferred(v4->m_pSceneObj);
      else
        UFG::SimObject::Destroy(v4);
    }
  }
  else
  {
    UFG::PedSpawningInfo::MakeCompletelyInactive(pedInfo);
  }
  if ( pedInfo->mTrueCrowdSignature.mSet )
    UFG::TrueCrowdSet::Instance::RemoveProxyReference(&pedInfo->mTrueCrowdSignature, pedInfo);
  pedInfo->mTrueCrowdSignature.mNumParts = 0;
  pedInfo->mTrueCrowdSignature.mSet = 0i64;
}

// File Line: 5993
// RVA: 0x408460
void __fastcall UFG::PedSpawnManager::ChangeStatusToActive(UFG::PedSpawnManager *this, UFG::PedSpawningInfo *pedInfo)
{
  UFG::SimObject *m_pPointer; // rsi
  UFG::TransformNodeComponent *v4; // r14
  UFG::allocator::free_link *v5; // rax
  UFG::TeleportEvent *v6; // rbp
  unsigned int v7; // ebx
  UFG::TransformNodeComponent *mProxyTransformNode; // r14
  UFG::allocator::free_link *v9; // rax
  UFG::TeleportEvent *v10; // rbp
  unsigned int mUID; // ebx
  UFG::SimComponent *m_pComponent; // rcx

  m_pPointer = pedInfo->mSimObjectPtr.m_pPointer;
  if ( pedInfo->mActiveStatus == ExtraLowPower )
  {
    if ( pedInfo->mTeleportOnResumeRequired )
    {
      mProxyTransformNode = pedInfo->mProxyTransformNode;
      v9 = UFG::qMalloc(0x90ui64, "TeleportEvent", 0i64);
      v10 = (UFG::TeleportEvent *)v9;
      if ( v9 )
      {
        mUID = m_pPointer->mNode.mUID;
        UFG::TransformNodeComponent::UpdateWorldTransform(mProxyTransformNode);
        UFG::TeleportEvent::TeleportEvent(
          v10,
          &mProxyTransformNode->mWorldTransform,
          mUID,
          0,
          UFG::TeleportEvent::m_Name,
          0);
      }
      UFG::EventDispatcher::DispatchEvent(&UFG::EventDispatcher::mInstance, (UFG::Event *)v9);
    }
    pedInfo->mTeleportOnResumeRequired = 0;
    UFG::SimObject::Restore(m_pPointer);
  }
  else
  {
    if ( pedInfo->mActiveStatus != NormalSuspend )
      goto LABEL_14;
    if ( pedInfo->mTeleportOnResumeRequired )
    {
      v4 = pedInfo->mProxyTransformNode;
      v5 = UFG::qMalloc(0x90ui64, "TeleportEvent", 0i64);
      v6 = (UFG::TeleportEvent *)v5;
      if ( v5 )
      {
        v7 = m_pPointer->mNode.mUID;
        UFG::TransformNodeComponent::UpdateWorldTransform(v4);
        UFG::TeleportEvent::TeleportEvent(v6, &v4->mWorldTransform, v7, 0, UFG::TeleportEvent::m_Name, 0);
      }
      UFG::EventDispatcher::DispatchEvent(&UFG::EventDispatcher::mInstance, (UFG::Event *)v5);
    }
    UFG::SimObject::Restore(m_pPointer);
    pedInfo->mTeleportOnResumeRequired = 0;
  }
  UFG::PedSpawningInfo::SetActiveStatus(pedInfo, Active);
LABEL_14:
  if ( m_pPointer )
  {
    m_pComponent = m_pPointer->m_Components.p[22].m_pComponent;
    if ( m_pComponent )
      BYTE6(m_pComponent[20].m_BoundComponentHandles.mNode.mPrev) = 1;
  }
}

// File Line: 6065
// RVA: 0x4085E0
void __fastcall UFG::PedSpawnManager::ChangeStatusToExtraLowPower(
        UFG::PedSpawnManager *this,
        UFG::PedSpawningInfo *pedInfo)
{
  UFG::SimObject *m_pPointer; // r15
  UFG::TransformNodeComponent *mProxyTransformNode; // rbp
  UFG::allocator::free_link *v5; // r14
  UFG::SimComponent *v6; // rsi
  unsigned int v7; // ebx
  UFG::Event *v8; // rax
  UFG::SimObject *v9; // rax
  UFG::AILightWeightComponent *v10; // rbx
  UFG::TransformNodeComponent *mTransformNodePtr; // rbp
  UFG::allocator::free_link *v12; // r14
  unsigned int mUID; // ebx
  UFG::Event *v14; // rax
  UFG::SimObject *v15; // rax
  UFG::SimComponent *m_pComponent; // rbx
  UFG::AILightWeightComponent *mProxyAIComponent; // rbp
  UFG::qSafePointer<UFG::SimComponent,UFG::InterestPoint> *p_mUpgradePOI; // rdi
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::InterestPoint *v21; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *p_mNode; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v23; // rax
  UFG::InterestPoint *ppInterestPoint; // [rsp+68h] [rbp+10h] BYREF

  m_pPointer = pedInfo->mSimObjectPtr.m_pPointer;
  if ( pedInfo->mActiveStatus == Active )
  {
    mTransformNodePtr = pedInfo->mTransformNodePtr;
    if ( !mTransformNodePtr )
      mTransformNodePtr = pedInfo->mProxyTransformNode;
    v12 = UFG::qMalloc(0x90ui64, "TeleportEvent", 0i64);
    ppInterestPoint = (UFG::InterestPoint *)v12;
    if ( v12 )
    {
      mUID = pedInfo->mProxySimObjectPtr->mNode.mUID;
      UFG::TransformNodeComponent::UpdateWorldTransform(mTransformNodePtr);
      UFG::TeleportEvent::TeleportEvent(
        (UFG::TeleportEvent *)v12,
        &mTransformNodePtr->mWorldTransform,
        mUID,
        0,
        UFG::TeleportEvent::m_Name,
        0);
    }
    else
    {
      v14 = 0i64;
    }
    UFG::EventDispatcher::DispatchEvent(&UFG::EventDispatcher::mInstance, v14);
    v15 = pedInfo->mSimObjectPtr.m_pPointer;
    if ( v15 )
      m_pComponent = v15->m_Components.p[22].m_pComponent;
    else
      m_pComponent = 0i64;
    mProxyAIComponent = pedInfo->mProxyAIComponent;
    if ( m_pComponent && mProxyAIComponent )
    {
      UFG::AILightWeightComponent::SetWanderData(
        pedInfo->mProxyAIComponent,
        (UFG::SidewalkWanderData *)&m_pComponent[8].m_Flags);
      mProxyAIComponent->mAILCanUseCrosswalks = HIBYTE(m_pComponent[20].m_BoundComponentHandles.mNode.mPrev);
    }
    UFG::SimObject::Suspend(m_pPointer);
    pedInfo->mSuspendedTime = 0.0;
    pedInfo->mTeleportOnResumeRequired = 0;
    UFG::PedSpawningInfo::SetActiveStatus(pedInfo, ExtraLowPower);
    ppInterestPoint = 0i64;
    if ( UFG::PedSpawningInfo::IsUsingPOI(pedInfo, &ppInterestPoint) )
    {
      p_mUpgradePOI = &pedInfo->mUpgradePOI;
      if ( p_mUpgradePOI->m_pPointer )
      {
        mPrev = p_mUpgradePOI->mPrev;
        mNext = p_mUpgradePOI->mNext;
        mPrev->mNext = mNext;
        mNext->mPrev = mPrev;
        p_mUpgradePOI->mPrev = p_mUpgradePOI;
        p_mUpgradePOI->mNext = p_mUpgradePOI;
      }
      v21 = ppInterestPoint;
      p_mUpgradePOI->m_pPointer = ppInterestPoint;
      if ( v21 )
      {
        p_mNode = &v21->UFG::MarkerBase::UFG::HintComponentBase::UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::m_SafePointerList.UFG::MarkerBase::UFG::HintComponentBase::UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::mNode;
        v23 = p_mNode->mPrev;
        v23->mNext = p_mUpgradePOI;
        p_mUpgradePOI->mPrev = v23;
        p_mUpgradePOI->mNext = p_mNode;
        p_mNode->mPrev = p_mUpgradePOI;
      }
    }
  }
  else if ( pedInfo->mActiveStatus == NormalSuspend )
  {
    mProxyTransformNode = pedInfo->mTransformNodePtr;
    if ( !mProxyTransformNode )
      mProxyTransformNode = pedInfo->mProxyTransformNode;
    v5 = UFG::qMalloc(0x90ui64, "TeleportEvent", 0i64);
    ppInterestPoint = (UFG::InterestPoint *)v5;
    v6 = 0i64;
    if ( v5 )
    {
      v7 = pedInfo->mProxySimObjectPtr->mNode.mUID;
      UFG::TransformNodeComponent::UpdateWorldTransform(mProxyTransformNode);
      UFG::TeleportEvent::TeleportEvent(
        (UFG::TeleportEvent *)v5,
        &mProxyTransformNode->mWorldTransform,
        v7,
        0,
        UFG::TeleportEvent::m_Name,
        0);
    }
    else
    {
      v8 = 0i64;
    }
    UFG::EventDispatcher::DispatchEvent(&UFG::EventDispatcher::mInstance, v8);
    v9 = pedInfo->mSimObjectPtr.m_pPointer;
    if ( v9 )
      v6 = v9->m_Components.p[22].m_pComponent;
    v10 = pedInfo->mProxyAIComponent;
    if ( v6 )
    {
      if ( v10 )
      {
        UFG::AILightWeightComponent::SetWanderData(
          pedInfo->mProxyAIComponent,
          (UFG::SidewalkWanderData *)&v6[8].m_Flags);
        v10->mAILCanUseCrosswalks = HIBYTE(v6[20].m_BoundComponentHandles.mNode.mPrev);
      }
    }
    UFG::PedSpawningInfo::SetActiveStatus(pedInfo, ExtraLowPower);
  }
}

// File Line: 6171
// RVA: 0x408260
void __fastcall UFG::PedSpawnManager::ChangeActiveStatus(
        UFG::PedSpawnManager *this,
        UFG::PedSpawningInfo::eActiveStatus targetPedStatus,
        UFG::PedSpawningInfo *pedInfo)
{
  int v4; // edx
  int v5; // edx

  if ( targetPedStatus )
  {
    v4 = targetPedStatus - 1;
    if ( v4 )
    {
      v5 = v4 - 1;
      if ( v5 )
      {
        if ( v5 == 1 )
        {
          if ( pedInfo->mActiveStatus == Active )
          {
            UFG::SimObject::Suspend(pedInfo->mSimObjectPtr.m_pPointer);
            pedInfo->mSuspendedTime = 0.0;
            pedInfo->mTeleportOnResumeRequired = 0;
            UFG::PedSpawningInfo::SetActiveStatus(pedInfo, NormalSuspend);
          }
          else if ( pedInfo->mActiveStatus == ExtraLowPower )
          {
            pedInfo->mSuspendedTime = 0.0;
            UFG::PedSpawningInfo::SetActiveStatus(pedInfo, NormalSuspend);
          }
        }
      }
      else
      {
        UFG::PedSpawnManager::ChangeStatusToExtraLowPower(this, pedInfo);
      }
    }
    else
    {
      UFG::PedSpawnManager::ChangeStatusToActive(this, pedInfo);
    }
  }
  else
  {
    UFG::PedSpawnManager::ChangeStatusToInactive(this, pedInfo);
  }
}

// File Line: 6225
// RVA: 0x408300
char __fastcall UFG::PedSpawnManager::ChangeActiveStatusOfSimObj(
        UFG::PedSpawnManager *this,
        UFG::PedSpawningInfo::eActiveStatus targetPedStatus,
        UFG::SimObject *simObj,
        const char *file,
        int line)
{
  int v7; // r10d
  UFG::SimObject **p_m_pPointer; // rax
  __int64 i; // rcx
  UFG::SimObject **v10; // rcx
  __int64 v11; // r8
  UFG::PedSpawningInfo *mScriptedPed; // rbx
  UFG::PedSpawningInfo *v14; // rbx
  int v15; // edx
  int v16; // edx

  if ( !simObj )
    return 0;
  v7 = 119;
  p_m_pPointer = &this->mScriptedPed[119].mSimObjectPtr.m_pPointer;
  for ( i = 119i64; i >= 0; --i )
  {
    if ( simObj == *p_m_pPointer )
    {
      mScriptedPed = this->mScriptedPed;
      goto LABEL_11;
    }
    --v7;
    p_m_pPointer -= 103;
  }
  v7 = 259;
  v10 = &this->mAmbientPed[259].mSimObjectPtr.m_pPointer;
  v11 = 259i64;
  while ( simObj != *v10 )
  {
    --v7;
    v10 -= 103;
    if ( --v11 < 0 )
      return 0;
  }
  mScriptedPed = this->mAmbientPed;
LABEL_11:
  v14 = &mScriptedPed[v7];
  if ( targetPedStatus )
  {
    v15 = targetPedStatus - 1;
    if ( !v15 )
    {
      UFG::PedSpawnManager::ChangeStatusToActive(this, v14);
      return 1;
    }
    v16 = v15 - 1;
    if ( !v16 )
    {
      UFG::PedSpawnManager::ChangeStatusToExtraLowPower(this, v14);
      return 1;
    }
    if ( v16 == 1 )
    {
      if ( v14->mActiveStatus == Active )
      {
        UFG::SimObject::Suspend(v14->mSimObjectPtr.m_pPointer);
        v14->mSuspendedTime = 0.0;
        v14->mTeleportOnResumeRequired = 0;
        UFG::PedSpawningInfo::SetActiveStatus(v14, NormalSuspend);
        return 1;
      }
      if ( v14->mActiveStatus == ExtraLowPower )
      {
        v14->mSuspendedTime = 0.0;
        UFG::PedSpawningInfo::SetActiveStatus(v14, NormalSuspend);
        return 1;
      }
    }
  }
  else
  {
    UFG::PedSpawnManager::ChangeStatusToInactive(this, v14);
  }
  return 1;
}

// File Line: 6363
// RVA: 0x409340
signed __int64 __fastcall UFG::PedSpawnManager::CheckAmbientActiveStatus(
        UFG::PedSpawnManager *this,
        UFG::PedSpawningInfo *pedInfo,
        float elapsedTime)
{
  UFG::PedSpawningInfo::eActiveStatus mActiveStatus; // esi
  UFG::SimObject *m_pPointer; // rax
  UFG::SimComponent *m_pComponent; // rdx
  UFG::SpawnZone *v7; // rax
  signed __int64 result; // rax
  UFG::SimObject *v9; // rbp
  unsigned int v10; // edi
  float v11; // xmm6_4

  mActiveStatus = pedInfo->mActiveStatus;
  if ( !pedInfo->mIsDead )
  {
    m_pPointer = pedInfo->mSimObjectPtr.m_pPointer;
    if ( m_pPointer )
    {
      m_pComponent = m_pPointer->m_Components.p[6].m_pComponent;
      if ( m_pComponent )
      {
        if ( BYTE4(m_pComponent[1].m_BoundComponentHandles.mNode.mPrev) )
        {
          v7 = pedInfo->mCreationSpawnZone.m_pPointer;
          pedInfo->mIsDead = 1;
          if ( v7 )
            ++v7->mNumDeadPeds;
        }
      }
    }
  }
  if ( UFG::PedSpawnManager::msAmbientStatusCheckEnable || UFG::PedSpawnManager::msCheckStatusMode != 1 )
  {
    if ( mActiveStatus == Inactive || pedInfo->mCharacterOccupantComponent.m_pSimComponent )
      return (unsigned int)pedInfo->mActiveStatus;
    v9 = pedInfo->mSimObjectPtr.m_pPointer;
    result = UFG::PedSpawnManager::GetIdealActiveStatus(this, pedInfo);
    v10 = result;
    if ( (_DWORD)result == mActiveStatus )
      return v10;
    if ( mActiveStatus == Active )
      goto LABEL_20;
    if ( (int)result <= 2 )
      return result;
    v11 = elapsedTime + pedInfo->mSuspendedTime;
    pedInfo->mSuspendedTime = v11;
    if ( v11 <= 3.0 || UFG::SkookumMgr::IsReferencedByScripts(v9) )
    {
LABEL_20:
      if ( v10 == 1 || (pedInfo->mCanSuspendScripted & 4) == 0 )
        return v10;
    }
    return 0i64;
  }
  else if ( pedInfo->mPhysicsLoadedForLocation )
  {
    return (unsigned int)mActiveStatus;
  }
  else
  {
    return pedInfo->mCreationSpawnZone.m_pPointer != 0i64 ? 3 : 0;
  }
}

// File Line: 6511
// RVA: 0x408940
void __fastcall UFG::PedSpawnManager::CheckActiveStatusOfPeds(UFG::PedSpawnManager *this)
{
  UFG::PedSpawnManager *v1; // rbp
  float v2; // xmm12_4
  bool v3; // bl
  UFG::SimObjectCharacter *LocalPlayer; // rax
  UFG::PedSpawningInfo *v5; // r15
  int v6; // ecx
  UFG::SimObjectCharacter *v7; // r13
  bool v8; // r8
  UFG::BaseCameraComponent *mCurrentCamera; // rax
  __int64 v10; // rbx
  int v11; // r14d
  __int64 v12; // r12
  UFG::PedSpawningInfo *v13; // rdi
  UFG::SimObject *m_pPointer; // rbp
  UFG::PedSpawningInfo::eActiveStatus mActiveStatus; // esi
  UFG::SimComponent *ComponentOfType; // rax
  UFG::SimObject *v17; // rbx
  NISManager *Instance; // rax
  float v19; // xmm0_4
  float mDistInCameraSpace; // xmm0_4
  UFG::SimObject *v21; // rbx
  NISManager *v22; // rax
  char IsActiveInNIS; // al
  float mCulledTime; // xmm0_4
  unsigned int v25; // eax
  float v26; // xmm0_4
  bool mIsDead; // zf
  float v28; // xmm0_4
  __int64 v29; // rdi
  UFG::PedSpawnManager *i; // r13
  __int64 index; // rcx
  char IsReferencedByScripts; // al
  UFG::PedSpawningInfo::eActiveStatus v33; // edx
  UFG::qNode<UFG::PedSpawningInfo,UFG::PedInfoList> **p_mNext; // r15
  UFG::PedSpawningInfo *v35; // rdi
  char v36; // r14
  __int64 v37; // r12
  UFG::PedSpawningInfo *v38; // rbp
  UFG::PedSpawningInfo *v39; // rbx
  UFG::PedSpawningInfo *v40; // rsi
  UFG::PedSpawningInfo::eActiveStatus v41; // eax
  UFG::SimObject *v42; // rcx
  UFG::PedSpawningInfo::eActiveStatus v43; // r8d
  UFG::SimComponent *v44; // rdx
  __int64 v45; // rcx
  int mPedIndex; // eax
  UFG::SimObject *v47; // rax
  UFG::SimComponent *m_pComponent; // rdx
  float v49; // xmm0_4
  float v50; // xmm0_4
  __int64 v51; // rdi
  __int64 v52; // rbx
  UFG::PedSpawningInfo::eActiveStatus newStatus; // ecx
  __int32 v54; // ecx
  __int32 v55; // ecx
  UFG::qNode<UFG::PedSpawningInfo,UFG::PedInfoList> **v57; // [rsp+E0h] [rbp+8h]
  char v58; // [rsp+E8h] [rbp+10h]
  bool v59; // [rsp+F0h] [rbp+18h]
  __int64 v60; // [rsp+F8h] [rbp+20h]

  v1 = this;
  v2 = UFG::PedSpawnManager::msElapsedTotal - this->mTimeOfLastEnableCheck;
  this->mTimeOfLastEnableCheck = UFG::PedSpawnManager::msElapsedTotal;
  v3 = (float)((float)(int)Illusion::gEngine.FrameWriteMemory->mLastFrameNumFreeBytes * 0.00000095367432) < 0.40000001;
  LocalPlayer = UFG::GetLocalPlayer();
  v5 = 0i64;
  v6 = 260 - UFG::PedSpawnManager::msAmbientCount[0];
  v7 = LocalPlayer;
  v8 = 120 - UFG::PedSpawnManager::msScriptedCount[0] > 115
    || v3
    || v6 + 120 - UFG::PedSpawnManager::msScriptedCount[0] > UFG::gMaxTotalFullSimPeds;
  v59 = v6 > UFG::gMaxTotalFullSimPeds / 2 + 10;
  if ( v8 || (v58 = 0, UFG::PedSpawnManager::msRunRagdollDelete) )
    v58 = 1;
  mCurrentCamera = UFG::Director::Get()->mCurrentCamera;
  if ( !mCurrentCamera || mCurrentCamera == (UFG::BaseCameraComponent *)-80i64 )
  {
    UFG::PedSpawnManager::msRunRagdollDelete = 0;
    return;
  }
  LODWORD(v10) = 0;
  v11 = 0;
  num_changes_queued = 0;
  v12 = 0i64;
  do
  {
    v13 = &v1->mScriptedPed[v12];
    m_pPointer = v1->mScriptedPed[v12].mSimObjectPtr.m_pPointer;
    mActiveStatus = v13->mActiveStatus;
    if ( m_pPointer )
    {
      ComponentOfType = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::InterestPointUserComponent::_TypeUID);
      if ( ComponentOfType
        && LODWORD(ComponentOfType[8].m_BoundComponentHandles.mNode.mPrev) == UFG::Metrics::msInstance.mSimFrameCount )
      {
        goto LABEL_26;
      }
      LODWORD(v10) = num_changes_queued;
    }
    if ( !UFG::PedSpawnManager::msScriptedStatusCheckEnable && UFG::PedSpawnManager::msCheckStatusMode == 1 )
    {
      if ( mActiveStatus == Active && !v13->mPhysicsLoadedForLocation )
      {
        v17 = v13->mSimObjectPtr.m_pPointer;
        Instance = NISManager::GetInstance();
        if ( !NISManager::IsActiveInNIS(Instance, v17) )
        {
          if ( v13->mActiveStatus == Active )
          {
            UFG::SimObject::Suspend(v13->mSimObjectPtr.m_pPointer);
            v13->mTeleportOnResumeRequired = 0;
            goto LABEL_25;
          }
          if ( v13->mActiveStatus == ExtraLowPower )
          {
LABEL_25:
            v13->mSuspendedTime = 0.0;
            UFG::PedSpawningInfo::SetActiveStatus(v13, NormalSuspend);
          }
        }
LABEL_26:
        LODWORD(v10) = num_changes_queued;
        goto LABEL_97;
      }
      goto LABEL_97;
    }
    if ( m_pPointer != v7 )
    {
      if ( mActiveStatus == Inactive )
        goto LABEL_97;
      if ( v13->mCharacterOccupantComponent.m_pSimComponent )
      {
        if ( mActiveStatus == Active )
          goto LABEL_97;
LABEL_95:
        change_queue[(unsigned int)v10].index = v11;
        change_queue[(unsigned int)v10].newStatus = Active;
LABEL_96:
        LODWORD(v10) = v10 + 1;
        num_changes_queued = v10;
        goto LABEL_97;
      }
      if ( (v13->mCanSuspendScripted & 8) != 0 )
      {
        change_queue[(unsigned int)v10].index = v11;
        change_queue[(unsigned int)v10].newStatus = Inactive;
        goto LABEL_96;
      }
      UFG::PedSpawningInfo::UpdateDeadStatus(v13);
      if ( !v13->mIsDead || (v13->mCanSuspendScripted &= ~1u, (v13->mCanSuspendScripted & 2) != 0) )
      {
LABEL_48:
        if ( (v13->mCanSuspendScripted & 4) != 0 && v13->mCulledTime > 15.0 )
        {
          change_queue[(unsigned int)v10].index = v11;
          change_queue[(unsigned int)v10].newStatus = Inactive;
          goto LABEL_96;
        }
        v21 = v13->mSimObjectPtr.m_pPointer;
        v22 = NISManager::GetInstance();
        IsActiveInNIS = NISManager::IsActiveInNIS(v22, v21);
        if ( mActiveStatus == Active )
        {
          if ( IsActiveInNIS )
            goto LABEL_59;
          if ( v13->mPhysicsLoadedForLocation )
          {
            if ( (v13->mCanSuspendScripted & 3) != 0 )
              goto LABEL_59;
            if ( v13->mIsDead )
            {
              mCulledTime = v13->mCulledTime;
              if ( mCulledTime <= 15.0 && (120 - UFG::PedSpawnManager::msScriptedCount[0] <= 40 || mCulledTime <= 3.0) )
                goto LABEL_59;
            }
            else if ( (v13->mLocationClassification < PreferExtraLow_Proxy_Ok
                    || (float)(UFG::PedSpawnManager::msPreferActiveMargin + UFG::PedSpawnManager::msAlwaysActiveDistance) >= v13->mDistInCameraSpace)
                   && v13->mCulledTime <= 4.0 )
            {
LABEL_59:
              if ( (v13->mCanSuspendScripted & 2) != 0 && !UFG::SkookumMgr::IsReferencedByScripts(m_pPointer) )
                v13->mCanSuspendScripted &= ~2u;
              goto LABEL_26;
            }
          }
          v10 = num_changes_queued;
          v25 = v13->mCanSuspendScripted & 4;
          change_queue[num_changes_queued].index = v11;
          if ( (_BYTE)v25 )
          {
            change_queue[v10].newStatus = Inactive;
            goto LABEL_96;
          }
LABEL_84:
          change_queue[v10].newStatus = NormalSuspend;
          goto LABEL_96;
        }
        if ( !IsActiveInNIS )
        {
          if ( !v13->mPhysicsLoadedForLocation )
            goto LABEL_77;
          if ( (v13->mCanSuspendScripted & 3) == 0 )
          {
            if ( v13->mIsDead )
            {
              v26 = v13->mCulledTime;
              if ( v26 <= 15.0 && (120 - UFG::PedSpawnManager::msScriptedCount[0] <= 40 || v26 <= 3.0) )
                goto LABEL_74;
            }
            else if ( v13->mCulledTime == 0.0 && v13->mLocationClassification <= PreferActive_ExtraLow_Ok )
            {
              goto LABEL_74;
            }
LABEL_77:
            mIsDead = v13->mIsDead;
            v28 = v2 + v13->mSuspendedTime;
            v13->mSuspendedTime = v28;
            if ( !mIsDead || v28 <= 3.0 || v13->mDistInCameraSpace <= 5.0 || (v13->mCanSuspendScripted & 2) != 0 )
              goto LABEL_26;
            change_queue[num_changes_queued].index = v11;
            if ( !UFG::SkookumMgr::IsReferencedByScripts(m_pPointer) )
            {
              LODWORD(v10) = num_changes_queued;
              change_queue[num_changes_queued].newStatus = Inactive;
              goto LABEL_96;
            }
            if ( mActiveStatus == NormalSuspend )
              goto LABEL_26;
            v10 = num_changes_queued;
            goto LABEL_84;
          }
        }
LABEL_74:
        v10 = num_changes_queued;
        change_queue[num_changes_queued].index = v11;
        change_queue[v10].newStatus = Active;
        goto LABEL_96;
      }
      if ( UFG::PedSpawningInfo::GetHowLongDead(v13) > 3.0 )
      {
        if ( v58 )
        {
          if ( !v5 )
          {
            v5 = v13;
            goto LABEL_26;
          }
          v19 = v5->mCulledTime;
          if ( v19 < v13->mCulledTime )
            goto LABEL_41;
          if ( v19 != 0.0 )
            goto LABEL_47;
          mDistInCameraSpace = v13->mDistInCameraSpace;
          goto LABEL_40;
        }
        if ( v59 && v13->mCulledTime > 10.0 )
        {
          mDistInCameraSpace = v13->mDistInCameraSpace;
          if ( mDistInCameraSpace > 20.0 )
          {
            if ( !v5 )
            {
LABEL_41:
              v5 = v13;
              goto LABEL_26;
            }
LABEL_40:
            if ( mDistInCameraSpace > v5->mDistInCameraSpace )
              goto LABEL_41;
          }
        }
      }
LABEL_47:
      LODWORD(v10) = num_changes_queued;
      goto LABEL_48;
    }
    if ( mActiveStatus == Active )
    {
      if ( v13->mPhysicsLoadedForLocation )
        goto LABEL_97;
      UFG::PedSpawnManager::msRestoreWeiOnPhysicsLoad = 1;
      change_queue[(unsigned int)v10].index = v11;
      change_queue[(unsigned int)v10].newStatus = NormalSuspend;
      goto LABEL_96;
    }
    if ( mActiveStatus == NormalSuspend && v13->mPhysicsLoadedForLocation )
    {
      UFG::PedSpawnManager::msRestoreWeiOnPhysicsLoad = 0;
      goto LABEL_95;
    }
LABEL_97:
    v1 = this;
    ++v11;
    ++v12;
  }
  while ( v11 < 120 );
  v29 = 0i64;
  for ( i = this; (unsigned int)v29 < (unsigned int)v10; v29 = (unsigned int)(v29 + 1) )
  {
    index = change_queue[v29].index;
    if ( this->mScriptedPed[index].mStatusChangedFrame != UFG::Metrics::msFrameCount )
    {
      UFG::PedSpawnManager::ChangeActiveStatus(this, change_queue[v29].newStatus, &this->mScriptedPed[index]);
      LODWORD(v10) = num_changes_queued;
      this->mScriptedPed[change_queue[v29].index].mStatusChangedFrame = UFG::Metrics::msFrameCount;
    }
  }
  if ( v5 && v5->mStatusChangedFrame != UFG::Metrics::msFrameCount )
  {
    IsReferencedByScripts = UFG::SkookumMgr::IsReferencedByScripts(v5->mSimObjectPtr.m_pPointer);
    v33 = Inactive;
    if ( IsReferencedByScripts )
      v33 = NormalSuspend;
    if ( v33 != v5->mActiveStatus )
      UFG::PedSpawnManager::ChangeActiveStatus(this, v33, v5);
  }
  p_mNext = &stru_1423DEF70.mNode.mNext;
  v35 = 0i64;
  v36 = 0;
  num_changes_queued = 0;
  v37 = NormalSuspend;
  v57 = &stru_1423DEF70.mNode.mNext;
  v60 = NormalSuspend;
  v38 = (UFG::PedSpawningInfo *)&UFG::PedSpawnManager::msAmbientList[-3];
  do
  {
    v39 = (UFG::PedSpawningInfo *)&(*p_mNext)[-4];
    if ( v39 == v38 )
      goto LABEL_137;
    do
    {
      v40 = (UFG::PedSpawningInfo *)&v39->UFG::qNode<UFG::PedSpawningInfo,UFG::PedInfoList>::mNext[-4];
      v41 = (unsigned int)UFG::PedSpawnManager::CheckAmbientActiveStatus(i, v39, v2);
      v42 = v39->mSimObjectPtr.m_pPointer;
      v43 = v41;
      if ( !v42
        || (v44 = v42->m_Components.p[43].m_pComponent) == 0i64
        || LODWORD(v44[8].m_BoundComponentHandles.mNode.mPrev) != UFG::Metrics::msInstance.mSimFrameCount )
      {
        if ( v41 != v39->mActiveStatus )
        {
          v45 = num_changes_queued;
          mPedIndex = v39->mPedIndex;
          ++num_changes_queued;
          change_queue[v45].index = mPedIndex;
          change_queue[v45].newStatus = v43;
          goto LABEL_135;
        }
        if ( v39->mIsDead
          && !v39->mCharacterOccupantComponent.m_pSimComponent
          && UFG::PedSpawningInfo::GetHowLongDead(v39) > 3.0 )
        {
          if ( v58 )
          {
            if ( v35 )
            {
              v47 = v39->mSimObjectPtr.m_pPointer;
              if ( v47 )
                m_pComponent = v47->m_Components.p[42].m_pComponent;
              else
                m_pComponent = 0i64;
              if ( (m_pComponent != 0i64) == v36 )
              {
                v49 = v35->mCulledTime;
                if ( v49 >= v39->mCulledTime )
                {
                  if ( v49 != 0.0 )
                    goto LABEL_135;
                  v50 = v39->mDistInCameraSpace;
                  goto LABEL_133;
                }
              }
              else
              {
                if ( !m_pComponent )
                  goto LABEL_135;
                v36 = 1;
              }
            }
            goto LABEL_134;
          }
          if ( v59 && v39->mCulledTime > 10.0 )
          {
            v50 = v39->mDistInCameraSpace;
            if ( v50 > 20.0 )
            {
              if ( v35 )
              {
LABEL_133:
                if ( v50 <= v35->mDistInCameraSpace )
                  goto LABEL_135;
              }
LABEL_134:
              v35 = v39;
            }
          }
        }
      }
LABEL_135:
      v39 = v40;
    }
    while ( v40 != v38 );
    p_mNext = v57;
    v37 = v60;
LABEL_137:
    p_mNext += 2;
    v38 = (UFG::PedSpawningInfo *)((char *)v38 + 16);
    v60 = --v37;
    v57 = p_mNext;
  }
  while ( v37 );
  if ( v35 )
  {
    if ( v35->mStatusChangedFrame != UFG::Metrics::msFrameCount )
      UFG::PedSpawnManager::ChangeStatusToInactive(i, v35);
  }
  v51 = 0i64;
  if ( num_changes_queued )
  {
    while ( 1 )
    {
      v52 = (__int64)&i->mAmbientPed[change_queue[v51].index];
      if ( *(_DWORD *)(v52 + 820) != UFG::Metrics::msFrameCount )
        break;
LABEL_155:
      v51 = (unsigned int)(v51 + 1);
      if ( (unsigned int)v51 >= num_changes_queued )
      {
        UFG::PedSpawnManager::msRunRagdollDelete = 0;
        return;
      }
    }
    newStatus = change_queue[v51].newStatus;
    if ( newStatus )
    {
      v54 = newStatus - 1;
      if ( v54 )
      {
        v55 = v54 - 1;
        if ( v55 )
        {
          if ( v55 == 1 )
          {
            if ( *(_DWORD *)(v52 + 168) == 1 )
            {
              UFG::SimObject::Suspend(*(UFG::SimObject **)(v52 + 192));
              *(_BYTE *)(v52 + 764) = 0;
LABEL_149:
              *(_DWORD *)(v52 + 132) = 0;
              UFG::PedSpawningInfo::SetActiveStatus((UFG::PedSpawningInfo *)v52, NormalSuspend);
            }
            else if ( *(_DWORD *)(v52 + 168) == 2 )
            {
              goto LABEL_149;
            }
          }
        }
        else
        {
          UFG::PedSpawnManager::ChangeStatusToExtraLowPower(i, &i->mAmbientPed[change_queue[v51].index]);
        }
      }
      else
      {
        UFG::PedSpawnManager::ChangeStatusToActive(i, &i->mAmbientPed[change_queue[v51].index]);
      }
    }
    else
    {
      UFG::PedSpawnManager::ChangeStatusToInactive(i, &i->mAmbientPed[change_queue[v51].index]);
    }
    *(_DWORD *)(v52 + 820) = UFG::Metrics::msFrameCount;
    goto LABEL_155;
  }
  UFG::PedSpawnManager::msRunRagdollDelete = 0;
}

// File Line: 7084
// RVA: 0x4153B0
UFG::SimObjectCharacter *__fastcall UFG::PedSpawnManager::ReleaseOwnership(
        UFG::SimObjectCharacter *_a_pObj,
        unsigned int desired_suspend_option,
        bool returning_from_mission_use)
{
  signed __int16 m_Flags; // cx
  UFG::SimComponent *m_pComponent; // rdi
  UFG::SimComponent *v8; // rax
  unsigned int v9; // esi
  __int64 v10; // rbp
  UFG::AnimationLODComponent *v11; // rcx
  UFG::SceneObjectProperties *m_pSceneObj; // rcx
  ArrayOfTuplesImplementation v14; // [rsp+28h] [rbp-40h] BYREF
  UFG::qSymbol result; // [rsp+70h] [rbp+8h] BYREF

  if ( !_a_pObj )
    return 0i64;
  m_Flags = _a_pObj->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
  {
    m_pComponent = _a_pObj->m_Components.p[48].m_pComponent;
  }
  else
  {
    v8 = m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
       ? UFG::SimObjectGame::GetComponentOfTypeHK(_a_pObj, UFG::PedSpawningInfo::_TypeUID)
       : UFG::SimObject::GetComponentOfType(_a_pObj, UFG::PedSpawningInfo::_TypeUID);
    m_pComponent = v8;
  }
  if ( !m_pComponent )
    return 0i64;
  if ( LODWORD(m_pComponent[12].m_BoundComponentHandles.mNode.mPrev) == 2 )
  {
    v9 = -1;
    if ( returning_from_mission_use )
    {
      if ( (*(_BYTE *)(&m_pComponent[10].m_SimObjIndex + 1) & 0x20) != 0 )
      {
        *(_DWORD *)(&m_pComponent[10].m_SimObjIndex + 1) &= ~0x20u;
LABEL_19:
        if ( UFG::PedSpawnManager::msAmbientCount[0] > 0 )
        {
          v10 = qword_1423DEF68 - 64;
          UFG::PedSpawningInfo::SetActiveStatus(
            (UFG::PedSpawningInfo *)(qword_1423DEF68 - 64),
            (UFG::PedSpawningInfo::eActiveStatus)m_pComponent[2].m_pSimObject);
          UFG::PedSpawningInfo::SetSimObjectPtr((UFG::PedSpawningInfo *)v10, _a_pObj);
          v11 = (UFG::AnimationLODComponent *)_a_pObj->m_Components.p[13].m_pComponent;
          if ( v11 )
            UFG::AnimationLODComponent::SetExtendedLOD(v11, 0);
          *(_DWORD *)(v10 + 676) = *(_DWORD *)(&m_pComponent[10].m_SimObjIndex + 1);
          *(_BYTE *)(v10 + 348) = m_pComponent[5].m_NameUID;
          *(_DWORD *)(v10 + 132) = HIDWORD(m_pComponent[2].vfptr);
          *(_DWORD *)(v10 + 736) = 0;
          *(_DWORD *)(v10 + 740) = *(_DWORD *)(&m_pComponent[11].m_SimObjIndex + 1);
          *(_DWORD *)(v10 + 744) = m_pComponent[11].m_pSimObject;
          UFG::qSafePointer<UFG::SpawnZone,UFG::SpawnZone>::operator=(
            (UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *)(v10 + 144),
            (UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *)&m_pComponent[2].m_SafePointerList.mNode.mNext);
          *(_DWORD *)(v10 + 760) = m_pComponent[11].m_BoundComponentHandles.mNode.mNext;
          *(_BYTE *)(v10 + 764) = BYTE4(m_pComponent[11].m_BoundComponentHandles.mNode.mNext);
          *(UFG::qSymbol *)(v10 + 644) = (UFG::qSymbol)UFG::PedSpawningInfo::GetPropertySetName(
                                                         (UFG::PedSpawningInfo *)m_pComponent,
                                                         &result)->mUID;
          *(UFG::qSymbol *)(v10 + 648) = (UFG::qSymbol)UFG::PedSpawningInfo::GetArchetypePropertySetName(
                                                         (UFG::PedSpawningInfo *)m_pComponent,
                                                         &result)->mUID;
          *(UFG::qSymbolUC *)(v10 + 640) = (UFG::qSymbolUC)UFG::PedSpawningInfo::GetRigNameSymbol(
                                                             (UFG::PedSpawningInfo *)m_pComponent,
                                                             (UFG::qSymbolUC *)&result)->mUID;
          *(UFG::qSymbol *)(v10 + 652) = (UFG::qSymbol)UFG::PedSpawningInfo::GetFactionSymbol(
                                                         (UFG::PedSpawningInfo *)m_pComponent,
                                                         &result)->mUID;
          UFG::PedSpawningInfo::SetTrueCrowdSignature(
            (UFG::PedSpawningInfo *)v10,
            (UFG::TrueCrowdSet::Instance *)&m_pComponent[5].m_pSimObject);
          *(UFG::qSymbol *)(v10 + 352) = (UFG::qSymbol)UFG::PedSpawningInfo::GetLifetimeNameSymbol(
                                                         (UFG::PedSpawningInfo *)m_pComponent,
                                                         &result)->mUID;
          UFG::PedSpawningInfo::SwapGroupComponent((UFG::PedSpawningInfo *)v10, (UFG::PedSpawningInfo *)m_pComponent);
          UFG::SimObjectModifier::SimObjectModifier((UFG::SimObjectModifier *)&v14, _a_pObj, 1);
          ArrayOfTuplesImplementation::clear(&v14);
          UFG::SimObjectModifier::Close((UFG::SimObjectModifier *)&v14);
          UFG::SimObjectModifier::~SimObjectModifier((UFG::SimObjectModifier *)&v14);
          if ( (_a_pObj->m_Flags & 0x4000) != 0 )
            v9 = 48;
          UFG::SimObjectModifier::SimObjectModifier((UFG::SimObjectModifier *)&v14, _a_pObj, 1);
          UFG::SimObjectModifier::AttachComponent((UFG::SimObjectModifier *)&v14, (UFG::SimComponent *)v10, v9);
          UFG::SimObjectModifier::Close((UFG::SimObjectModifier *)&v14);
          UFG::SimObjectModifier::~SimObjectModifier((UFG::SimObjectModifier *)&v14);
          UFG::PedSpawningInfo::SetSimObjectPtr((UFG::PedSpawningInfo *)m_pComponent, 0i64);
          UFG::PedSpawningInfo::SetActiveStatus((UFG::PedSpawningInfo *)m_pComponent, Inactive);
          return _a_pObj;
        }
        m_pSceneObj = _a_pObj->m_pSceneObj;
        if ( m_pSceneObj->mpParent )
          UFG::SceneObjectProperties::DeactivateDeferred(m_pSceneObj);
        else
          UFG::SimObject::Destroy(_a_pObj);
        return 0i64;
      }
    }
    else if ( (*(_BYTE *)(&m_pComponent[10].m_SimObjIndex + 1) & 0x20) == 0 )
    {
      if ( desired_suspend_option != -1 )
        *(_DWORD *)(&m_pComponent[10].m_SimObjIndex + 1) = desired_suspend_option;
      goto LABEL_19;
    }
  }
  return _a_pObj;
}

// File Line: 7254
// RVA: 0x407C90
char __fastcall UFG::PedSpawnManager::AquireOwnership(
        UFG::SimObjectCharacter *_a_pObj,
        bool bAmbient,
        bool loaning_to_mission_script,
        int creation_zone_index)
{
  signed __int16 m_Flags; // cx
  UFG::PedSpawningInfo *m_pComponent; // rdi
  UFG::PedSpawningInfo *v9; // rax
  UFG::PedSpawningInfo *v10; // rbp
  unsigned int mCanSuspendScripted; // eax
  UFG::AnimationLODComponent *v12; // rcx
  unsigned int v13; // esi
  UFG::SceneObjectProperties *m_pSceneObj; // rcx
  ArrayOfTuplesImplementation v16; // [rsp+28h] [rbp-40h] BYREF
  UFG::qSymbol v17; // [rsp+70h] [rbp+8h] BYREF

  if ( !_a_pObj )
    return 0;
  m_Flags = _a_pObj->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
  {
    m_pComponent = (UFG::PedSpawningInfo *)_a_pObj->m_Components.p[48].m_pComponent;
  }
  else
  {
    v9 = (UFG::PedSpawningInfo *)(m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
                                ? UFG::SimObjectGame::GetComponentOfTypeHK(_a_pObj, UFG::PedSpawningInfo::_TypeUID)
                                : UFG::SimObject::GetComponentOfType(_a_pObj, UFG::PedSpawningInfo::_TypeUID));
    m_pComponent = v9;
  }
  if ( !m_pComponent || m_pComponent->mPedType != AmbientPed )
    return 0;
  UFG::PedSpawnManager::ChangeStatusToActive(UFG::gpPedSpawnManager, m_pComponent);
  if ( bAmbient )
    return 1;
  if ( UFG::PedSpawnManager::msScriptedCount[0] <= 0 )
  {
    m_pSceneObj = _a_pObj->m_pSceneObj;
    if ( !m_pSceneObj->mpParent )
    {
      UFG::SimObject::Destroy(_a_pObj);
      return 1;
    }
    UFG::SceneObjectProperties::DeactivateDeferred(m_pSceneObj);
    return 1;
  }
  v10 = (UFG::PedSpawningInfo *)&UFG::PedSpawnManager::msScriptedList[0].mNode.mNext[-4];
  UFG::PedSpawningInfo::SetActiveStatus(
    (UFG::PedSpawningInfo *)&UFG::PedSpawnManager::msScriptedList[0].mNode.mNext[-4],
    m_pComponent->mActiveStatus);
  UFG::PedSpawningInfo::SetSimObjectPtr(v10, _a_pObj);
  mCanSuspendScripted = m_pComponent->mCanSuspendScripted;
  v10->mCanSuspendScripted = mCanSuspendScripted;
  if ( loaning_to_mission_script )
    v10->mCanSuspendScripted = mCanSuspendScripted | 0x20;
  v12 = (UFG::AnimationLODComponent *)_a_pObj->m_Components.p[13].m_pComponent;
  if ( v12 )
    UFG::AnimationLODComponent::SetExtendedLOD(v12, 1);
  v10->mIsDead = m_pComponent->mIsDead;
  v10->mSuspendedTime = m_pComponent->mSuspendedTime;
  v10->mRestoreAttempts = 0;
  v10->mBlipActive = m_pComponent->mBlipActive;
  v10->mHowSpawned = m_pComponent->mHowSpawned;
  UFG::qSafePointer<UFG::SpawnZone,UFG::SpawnZone>::operator=(
    (UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *)&v10->mCreationSpawnZone,
    (UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *)&m_pComponent->mCreationSpawnZone);
  v10->mSpawnTime = m_pComponent->mSpawnTime;
  v10->mTeleportOnResumeRequired = m_pComponent->mTeleportOnResumeRequired;
  v10->mPropSetSymbol = (UFG::qSymbol)UFG::PedSpawningInfo::GetPropertySetName(m_pComponent, &v17)->mUID;
  v10->mArchetypePropSetSymbol = (UFG::qSymbol)UFG::PedSpawningInfo::GetArchetypePropertySetName(m_pComponent, &v17)->mUID;
  v10->mRigNameSymbol = (UFG::qSymbolUC)UFG::PedSpawningInfo::GetRigNameSymbol(m_pComponent, (UFG::qSymbolUC *)&v17)->mUID;
  v10->mFactionSymbol = (UFG::qSymbol)UFG::PedSpawningInfo::GetFactionSymbol(m_pComponent, &v17)->mUID;
  UFG::PedSpawningInfo::SetTrueCrowdSignature(v10, &m_pComponent->mTrueCrowdSignature);
  v10->mLifetimeInstanceNameSymbol = (UFG::qSymbol)UFG::PedSpawningInfo::GetLifetimeNameSymbol(m_pComponent, &v17)->mUID;
  UFG::PedSpawningInfo::SwapGroupComponent(v10, m_pComponent);
  UFG::SimObjectModifier::SimObjectModifier((UFG::SimObjectModifier *)&v16, _a_pObj, 1);
  ArrayOfTuplesImplementation::clear(&v16);
  UFG::SimObjectModifier::Close((UFG::SimObjectModifier *)&v16);
  UFG::SimObjectModifier::~SimObjectModifier((UFG::SimObjectModifier *)&v16);
  if ( (_a_pObj->m_Flags & 0x4000) != 0 )
    v13 = 48;
  else
    v13 = -1;
  UFG::SimObjectModifier::SimObjectModifier((UFG::SimObjectModifier *)&v16, _a_pObj, 1);
  UFG::SimObjectModifier::AttachComponent((UFG::SimObjectModifier *)&v16, v10, v13);
  UFG::SimObjectModifier::Close((UFG::SimObjectModifier *)&v16);
  UFG::SimObjectModifier::~SimObjectModifier((UFG::SimObjectModifier *)&v16);
  UFG::PedSpawningInfo::SetSimObjectPtr(m_pComponent, 0i64);
  UFG::PedSpawningInfo::SetActiveStatus(m_pComponent, Inactive);
  return 1;
}

// File Line: 7886
// RVA: 0x40B960
void __fastcall UFG::PedSpawnManager::FrameRateThrottle(UFG::PedSpawnManager *this)
{
  int v1; // eax
  float v2; // xmm0_4
  float v3; // xmm0_4
  float v4; // xmm1_4
  float v5; // xmm0_4
  float v6; // xmm0_4
  float v7; // xmm1_4
  bool v8; // al

  v1 = UFG::PedSpawnManager::msTargetPedCount
     - UFG::PedSpawnManager::msScriptedCount[1]
     - UFG::PedSpawnManager::msAmbientCount[1];
  if ( v1 <= 4 )
  {
    if ( v1 >= -4 )
    {
      v4 = UFG::PedSpawnManager::msWorkingFullyActiveDistance;
      PrevAdjust = 0.0;
    }
    else
    {
      v5 = PrevAdjust;
      if ( PrevAdjust > 0.0 )
        v5 = 0.0;
      v6 = v5 + -0.1;
      v4 = UFG::PedSpawnManager::msWorkingFullyActiveDistance + v6;
      PrevAdjust = v6;
      if ( (float)(UFG::PedSpawnManager::msWorkingFullyActiveDistance + v6) <= UFG::PedSpawnManager::msMinFullyActiveDistance )
      {
        v4 = UFG::PedSpawnManager::msMinFullyActiveDistance;
        UFG::PedSpawnManager::msWorkingFullyActiveDistance = UFG::PedSpawnManager::msMinFullyActiveDistance;
      }
      else
      {
        UFG::PedSpawnManager::msWorkingFullyActiveDistance = UFG::PedSpawnManager::msWorkingFullyActiveDistance + v6;
      }
    }
  }
  else
  {
    v2 = PrevAdjust;
    if ( PrevAdjust < 0.0 )
      v2 = 0.0;
    v3 = v2 + 0.1;
    v4 = UFG::PedSpawnManager::msWorkingFullyActiveDistance + v3;
    PrevAdjust = v3;
    if ( (float)(UFG::PedSpawnManager::msWorkingFullyActiveDistance + v3) >= UFG::PedSpawnManager::msMaxFullyActiveDistance )
    {
      v4 = UFG::PedSpawnManager::msMaxFullyActiveDistance;
      UFG::PedSpawnManager::msWorkingFullyActiveDistance = UFG::PedSpawnManager::msMaxFullyActiveDistance;
    }
    else
    {
      UFG::PedSpawnManager::msWorkingFullyActiveDistance = UFG::PedSpawnManager::msWorkingFullyActiveDistance + v3;
    }
  }
  v7 = (float)(v4 - UFG::PedSpawnManager::msMinFullyActiveDistance)
     / (float)(UFG::PedSpawnManager::msMaxFullyActiveDistance - UFG::PedSpawnManager::msMinFullyActiveDistance);
  UFG::PedSpawnManager::msAlwaysActiveDistance = (float)(v7 * 4.5) + 3.5;
  if ( v7 >= 0.079999998 )
  {
    v8 = UFG::PedSpawnManager::msProxyExclusionZoneActive_2;
    if ( v7 > 0.15000001 )
      v8 = 0;
    UFG::PedSpawnManager::msProxyExclusionZoneActive_2 = v8;
  }
  else
  {
    UFG::PedSpawnManager::msProxyExclusionZoneActive_2 = 1;
  }
}

// File Line: 7985
// RVA: 0x409610
void __fastcall UFG::PedSpawnManager::CollectInfoForOne(
        UFG::PedSpawnManager *this,
        UFG::PedSpawningInfo *info,
        UFG::qMatrix44 *camWorldView,
        float elapsedTime)
{
  UFG::TransformNodeComponent *mTransformNodePtr; // rdi
  UFG::TransformNodeComponent *mProxyTransformNode; // rsi
  UFG::PedSpawningInfo::eActiveStatus mActiveStatus; // eax
  CullResults *mCullResults; // rdi
  UFG::SimObject *m_pPointer; // rax
  UFG::SimComponent *m_pComponent; // rcx
  float x; // xmm7_4
  float y; // xmm8_4
  float z; // xmm9_4
  unsigned int v16; // esi
  unsigned int VisIndexAtPosition; // eax
  UFG::SpawnZone *v18; // rax
  float v19; // xmm0_4
  __m128 y_low; // xmm2
  float v21; // xmm1_4
  bool v22; // zf
  __int64 v23; // rax
  float mCulledTime; // xmm0_4
  UFG::qNode<UFG::PedSpawningInfo,UFG::PedSpawningInfo_DrawList> *v25; // rax
  UFG::qNode<UFG::PedSpawningInfo,UFG::PedSpawningInfo_DrawList> *v26; // rcx
  UFG::qNode<UFG::PedSpawningInfo,UFG::PedSpawningInfo_DrawList> *v27; // rax
  UFG::qNode<UFG::PedSpawningInfo,UFG::PedSpawningInfo_DrawList> *mNext; // rax
  UFG::qNode<UFG::PedSpawningInfo,UFG::PedSpawningInfo_DrawList> *mPrev; // rcx
  UFG::qNode<UFG::PedSpawningInfo,UFG::PedSpawningInfo_DrawList> *v30; // rax
  int mLockActiveFrameCount; // eax
  UFG::qVector4 row_vec4; // [rsp+20h] [rbp-68h] BYREF
  UFG::qVector4 result; // [rsp+30h] [rbp-58h] BYREF

  mTransformNodePtr = info->mTransformNodePtr;
  if ( !mTransformNodePtr || (mProxyTransformNode = info->mTransformNodePtr, info->mActiveStatus == ExtraLowPower) )
    mProxyTransformNode = info->mProxyTransformNode;
  mActiveStatus = info->mActiveStatus;
  if ( mActiveStatus >= ExtraLowPower )
  {
    if ( !mTransformNodePtr || mActiveStatus == ExtraLowPower )
      mTransformNodePtr = info->mProxyTransformNode;
    UFG::TransformNodeComponent::UpdateWorldTransform(mTransformNodePtr);
    info->mCullInfo->mpLocalWorld = &mTransformNodePtr->mWorldTransform.v0.x;
  }
  mCullResults = info->mCullResults;
  if ( info->mActiveStatus < ExtraLowPower )
  {
    m_pPointer = info->mSimObjectPtr.m_pPointer;
    if ( m_pPointer )
    {
      m_pComponent = m_pPointer->m_Components.p[14].m_pComponent;
      if ( m_pComponent )
        mCullResults = (CullResults *)m_pComponent[19].m_pSimObject;
    }
  }
  UFG::TransformNodeComponent::UpdateWorldTransform(mProxyTransformNode);
  x = mProxyTransformNode->mWorldTransform.v3.x;
  y = mProxyTransformNode->mWorldTransform.v3.y;
  z = mProxyTransformNode->mWorldTransform.v3.z;
  row_vec4.x = x;
  row_vec4.y = y;
  row_vec4.z = z;
  LODWORD(row_vec4.w) = (_DWORD)FLOAT_1_0;
  UFG::operator*(&result, &row_vec4, camWorldView);
  v16 = UFG::Metrics::msFrameCount;
  if ( !info->mPhysicsLoadedForLocation
    || (((unsigned __int8)UFG::Metrics::msFrameCount ^ LOBYTE(info->mPedIndex)) & 7) == 0 )
  {
    row_vec4.x = x;
    row_vec4.y = y;
    row_vec4.z = z;
    VisIndexAtPosition = UFG::SectionChooser::GetVisIndexAtPosition((UFG::qVector3 *)&row_vec4, 0);
    info->mPhysicsLoadedForLocation = UFG::SectionChooser::IsSectionVisible_VisIndex(
                                        VisIndexAtPosition,
                                        SCENERY_LAYER_STD,
                                        0);
  }
  v18 = info->mCreationSpawnZone.m_pPointer;
  if ( v18 )
  {
    if ( v18->mAliveCountValidationTag == v16 )
    {
      ++v18->mAliveCount;
    }
    else
    {
      v18->mAliveCount = 1;
      info->mCreationSpawnZone.m_pPointer->mAliveCountValidationTag = v16;
    }
  }
  info->mCurrentLocation.x = x;
  info->mCurrentLocation.y = y;
  info->mCurrentLocation.z = z;
  info->mLocationClassification = UFG::PedSpawnManager::GetActiveZoneFromPoint(
                                    this,
                                    &info->mCurrentLocation,
                                    info->mActiveStatus);
  v19 = result.x;
  y_low = (__m128)LODWORD(result.y);
  v21 = result.z;
  info->mLocationInCameraSpace.x = result.x;
  LODWORD(info->mLocationInCameraSpace.y) = y_low.m128_i32[0];
  info->mLocationInCameraSpace.z = v21;
  v22 = !info->mIsDead;
  y_low.m128_f32[0] = (float)((float)((float)(y_low.m128_f32[0] * y_low.m128_f32[0]) + (float)(v19 * v19))
                            + (float)(v21 * v21))
                    + (float)(result.w * result.w);
  LODWORD(info->mDistInCameraSpace) = _mm_sqrt_ps(y_low).m128_u32[0];
  if ( !v22 )
  {
    if ( info->mPedType == AmbientPed )
      ++UFG::PedSpawnManager::msNumDeadAmbientPeds;
    else
      ++UFG::PedSpawnManager::msNumDeadScriptedPeds;
  }
  if ( mCullResults )
  {
    v23 = gMainCullIndex;
    mCulledTime = info->mCulledTime;
    info->mPrevCulledTime = mCulledTime;
    if ( (int)v23 < 0 || mCullResults->mViewResult[v23] <= 1u )
    {
      v22 = info->mDrawList == DrawList_Draw;
      info->mCulledTime = 0.0;
      if ( !v22 )
      {
        mNext = info->UFG::qNode<UFG::PedSpawningInfo,UFG::PedSpawningInfo_DrawList>::mNext;
        mPrev = info->UFG::qNode<UFG::PedSpawningInfo,UFG::PedSpawningInfo_DrawList>::mPrev;
        mPrev->mNext = mNext;
        mNext->mPrev = mPrev;
        info->UFG::qNode<UFG::PedSpawningInfo,UFG::PedSpawningInfo_DrawList>::mPrev = &info->UFG::qNode<UFG::PedSpawningInfo,UFG::PedSpawningInfo_DrawList>;
        info->UFG::qNode<UFG::PedSpawningInfo,UFG::PedSpawningInfo_DrawList>::mNext = &info->UFG::qNode<UFG::PedSpawningInfo,UFG::PedSpawningInfo_DrawList>;
        v30 = UFG::PedSpawningInfo::smDrawList.mNode.mPrev;
        UFG::PedSpawningInfo::smDrawList.mNode.mPrev->mNext = &info->UFG::qNode<UFG::PedSpawningInfo,UFG::PedSpawningInfo_DrawList>;
        info->UFG::qNode<UFG::PedSpawningInfo,UFG::PedSpawningInfo_DrawList>::mPrev = v30;
        info->UFG::qNode<UFG::PedSpawningInfo,UFG::PedSpawningInfo_DrawList>::mNext = (UFG::qNode<UFG::PedSpawningInfo,UFG::PedSpawningInfo_DrawList> *)&UFG::PedSpawningInfo::smDrawList;
        UFG::PedSpawningInfo::smDrawList.mNode.mPrev = &info->UFG::qNode<UFG::PedSpawningInfo,UFG::PedSpawningInfo_DrawList>;
        info->mDrawList = DrawList_Draw;
      }
    }
    else
    {
      v22 = info->mDrawList == DrawList_NoDraw;
      info->mCulledTime = mCulledTime + elapsedTime;
      if ( !v22 )
      {
        v25 = info->UFG::qNode<UFG::PedSpawningInfo,UFG::PedSpawningInfo_DrawList>::mNext;
        v26 = info->UFG::qNode<UFG::PedSpawningInfo,UFG::PedSpawningInfo_DrawList>::mPrev;
        v26->mNext = v25;
        v25->mPrev = v26;
        info->UFG::qNode<UFG::PedSpawningInfo,UFG::PedSpawningInfo_DrawList>::mPrev = &info->UFG::qNode<UFG::PedSpawningInfo,UFG::PedSpawningInfo_DrawList>;
        info->UFG::qNode<UFG::PedSpawningInfo,UFG::PedSpawningInfo_DrawList>::mNext = &info->UFG::qNode<UFG::PedSpawningInfo,UFG::PedSpawningInfo_DrawList>;
        v27 = UFG::PedSpawningInfo::smNoDrawList.mNode.mPrev;
        UFG::PedSpawningInfo::smNoDrawList.mNode.mPrev->mNext = &info->UFG::qNode<UFG::PedSpawningInfo,UFG::PedSpawningInfo_DrawList>;
        info->UFG::qNode<UFG::PedSpawningInfo,UFG::PedSpawningInfo_DrawList>::mPrev = v27;
        info->UFG::qNode<UFG::PedSpawningInfo,UFG::PedSpawningInfo_DrawList>::mNext = (UFG::qNode<UFG::PedSpawningInfo,UFG::PedSpawningInfo_DrawList> *)&UFG::PedSpawningInfo::smNoDrawList;
        UFG::PedSpawningInfo::smNoDrawList.mNode.mPrev = &info->UFG::qNode<UFG::PedSpawningInfo,UFG::PedSpawningInfo_DrawList>;
        info->mDrawList = DrawList_NoDraw;
      }
    }
  }
  else
  {
    info->mCulledTime = elapsedTime + info->mCulledTime;
  }
  mLockActiveFrameCount = info->mLockActiveFrameCount;
  if ( mLockActiveFrameCount <= 0 )
    info->mLockActiveFrameCount = 0;
  else
    info->mLockActiveFrameCount = mLockActiveFrameCount - 1;
}

// File Line: 8163
// RVA: 0x409990
void __fastcall UFG::PedSpawnManager::CollectPedInfo(UFG::PedSpawnManager *this, float elapsedTime)
{
  UFG::BaseCameraComponent *mCurrentCamera; // rcx
  UFG::Camera *p_mCamera; // rdi
  float y; // xmm1_4
  float z; // xmm2_4
  UFG::qMatrix44 *ViewProjection; // rbx
  UFG::qMatrix44 *WorldView; // rax
  float v9; // xmm12_4
  float v10; // xmm10_4
  float v11; // xmm11_4
  float v12; // xmm13_4
  float v13; // xmm14_4
  float v14; // xmm15_4
  float v15; // xmm0_4
  float v16; // xmm0_4
  float v17; // xmm5_4
  float v18; // xmm4_4
  float v19; // xmm0_4
  __m128 v20; // xmm2
  float v21; // xmm0_4
  int v22; // xmm1_4
  float v23; // xmm5_4
  __m128 v24; // xmm2
  float v25; // xmm0_4
  __m128 v26; // xmm2
  float v27; // xmm8_4
  UFG::BaseCameraComponent *v28; // rcx
  UFG::Camera *v29; // rcx
  UFG::qMatrix44 *v30; // rax
  float *p_mShouldCheckZoneInAreaTime; // rbx
  UFG::qMatrix44 *v32; // r14
  __int64 v33; // rbp
  UFG::PedSpawningInfo *mScriptedPed; // rbx
  __int64 v35; // rdi
  float v36; // [rsp+20h] [rbp-138h]
  float v37; // [rsp+24h] [rbp-134h]
  float v38; // [rsp+34h] [rbp-124h]
  float v39; // [rsp+3Ch] [rbp-11Ch]
  float v40; // [rsp+44h] [rbp-114h]
  UFG::qMatrix44 result; // [rsp+50h] [rbp-108h] BYREF
  float v43; // [rsp+170h] [rbp+18h]

  UFG::PedSpawnManager::msNumDeadScriptedPeds = 0;
  UFG::PedSpawnManager::msNumDeadAmbientPeds = 0;
  mCurrentCamera = UFG::Director::Get()->mCurrentCamera;
  p_mCamera = &mCurrentCamera->mCamera;
  if ( !mCurrentCamera )
    p_mCamera = 0i64;
  y = p_mCamera->mTransformation.v3.y;
  z = p_mCamera->mTransformation.v3.z;
  UFG::PedSpawnManager::msZone_centre.x = p_mCamera->mTransformation.v3.x;
  UFG::PedSpawnManager::msZone_centre.y = y;
  UFG::PedSpawnManager::msZone_centre.z = z;
  ViewProjection = UFG::Camera::GetViewProjection(p_mCamera);
  WorldView = UFG::Camera::GetWorldView(p_mCamera);
  UFG::qMatrix44::operator*(WorldView, &result, ViewProjection);
  LODWORD(v43) = COERCE_UNSIGNED_INT(result.v0.y + result.v0.w) ^ _xmm[0];
  LODWORD(v40) = COERCE_UNSIGNED_INT(result.v2.w - result.v2.y) ^ _xmm[0];
  LODWORD(v9) = COERCE_UNSIGNED_INT(result.v0.x + result.v0.w) ^ _xmm[0];
  LODWORD(v10) = COERCE_UNSIGNED_INT(result.v2.x + result.v2.w) ^ _xmm[0];
  LODWORD(v11) = COERCE_UNSIGNED_INT(result.v1.x + result.v1.w) ^ _xmm[0];
  LODWORD(v38) = COERCE_UNSIGNED_INT(result.v0.w - result.v0.y) ^ _xmm[0];
  LODWORD(v12) = COERCE_UNSIGNED_INT(result.v0.w - result.v0.x) ^ _xmm[0];
  LODWORD(v13) = COERCE_UNSIGNED_INT(result.v1.w - result.v1.x) ^ _xmm[0];
  LODWORD(v14) = COERCE_UNSIGNED_INT(result.v2.w - result.v2.x) ^ _xmm[0];
  LODWORD(v36) = COERCE_UNSIGNED_INT(result.v0.w - result.v0.z) ^ _xmm[0];
  LODWORD(v39) = COERCE_UNSIGNED_INT(result.v1.w - result.v1.z) ^ _xmm[0];
  LODWORD(v37) = COERCE_UNSIGNED_INT(result.v2.w - result.v2.z) ^ _xmm[0];
  v15 = fsqrt(
          (float)((float)(COERCE_FLOAT(LODWORD(result.v0.z) ^ _xmm[0]) * COERCE_FLOAT(LODWORD(result.v0.z) ^ _xmm[0]))
                + (float)(COERCE_FLOAT(LODWORD(result.v1.z) ^ _xmm[0]) * COERCE_FLOAT(LODWORD(result.v1.z) ^ _xmm[0])))
        + (float)(COERCE_FLOAT(LODWORD(result.v2.z) ^ _xmm[0]) * COERCE_FLOAT(LODWORD(result.v2.z) ^ _xmm[0])));
  *(float *)&dword_1423DEC6C = (float)(1.0 / v15) * COERCE_FLOAT(LODWORD(result.v3.z) ^ _xmm[0]);
  UFG::PedSpawnManager::msFrustum_planes[0].x = (float)(1.0 / v15) * COERCE_FLOAT(LODWORD(result.v0.z) ^ _xmm[0]);
  *(float *)&dword_1423DEC68 = (float)(1.0 / v15) * COERCE_FLOAT(LODWORD(result.v2.z) ^ _xmm[0]);
  *(float *)&dword_1423DEC64 = (float)(1.0 / v15) * COERCE_FLOAT(LODWORD(result.v1.z) ^ _xmm[0]);
  v16 = fsqrt((float)((float)(v9 * v9) + (float)(v11 * v11)) + (float)(v10 * v10));
  LODWORD(v17) = COERCE_UNSIGNED_INT(result.v1.y + result.v1.w) ^ _xmm[0];
  LODWORD(v18) = COERCE_UNSIGNED_INT(result.v2.y + result.v2.w) ^ _xmm[0];
  *(float *)&dword_1423DEC7C = (float)(1.0 / v16)
                             * COERCE_FLOAT(COERCE_UNSIGNED_INT(result.v3.x + result.v3.w) ^ _xmm[0]);
  *(float *)&dword_1423DEC70 = (float)(1.0 / v16) * v9;
  *(float *)&dword_1423DEC78 = (float)(1.0 / v16) * v10;
  *(float *)&dword_1423DEC74 = (float)(1.0 / v16) * v11;
  v19 = fsqrt((float)((float)(v12 * v12) + (float)(v13 * v13)) + (float)(v14 * v14));
  *(float *)&dword_1423DEC8C = (float)(1.0 / v19)
                             * COERCE_FLOAT(COERCE_UNSIGNED_INT(result.v3.w - result.v3.x) ^ _xmm[0]);
  *(float *)&dword_1423DEC80 = (float)(1.0 / v19) * v12;
  *(float *)&dword_1423DEC88 = (float)(1.0 / v19) * v14;
  *(float *)&dword_1423DEC84 = (float)(1.0 / v19) * v13;
  v20 = (__m128)LODWORD(v43);
  v20.m128_f32[0] = (float)((float)(v20.m128_f32[0] * v20.m128_f32[0]) + (float)(v17 * v17)) + (float)(v18 * v18);
  v21 = _mm_sqrt_ps(v20).m128_f32[0];
  *(float *)&v22 = (float)(1.0 / v21) * v17;
  LODWORD(v23) = COERCE_UNSIGNED_INT(result.v1.w - result.v1.y) ^ _xmm[0];
  *(float *)&dword_1423DEC90 = (float)(1.0 / v21) * v43;
  *(float *)&dword_1423DEC98 = (float)(1.0 / v21) * v18;
  dword_1423DEC94 = v22;
  v24 = (__m128)LODWORD(v38);
  *(float *)&dword_1423DEC9C = (float)(1.0 / v21)
                             * COERCE_FLOAT(COERCE_UNSIGNED_INT(result.v3.y + result.v3.w) ^ _xmm[0]);
  v24.m128_f32[0] = (float)((float)(v24.m128_f32[0] * v24.m128_f32[0]) + (float)(v23 * v23)) + (float)(v40 * v40);
  v25 = 1.0 / _mm_sqrt_ps(v24).m128_f32[0];
  *(float *)&dword_1423DECA0 = v25 * v38;
  *(float *)&dword_1423DECA4 = v25 * v23;
  *(float *)&dword_1423DECAC = v25 * COERCE_FLOAT(COERCE_UNSIGNED_INT(result.v3.w - result.v3.y) ^ _xmm[0]);
  v26 = (__m128)LODWORD(v39);
  *(float *)&dword_1423DECA8 = v25 * v40;
  v26.m128_f32[0] = (float)((float)(v26.m128_f32[0] * v26.m128_f32[0]) + (float)(v36 * v36)) + (float)(v37 * v37);
  v27 = 1.0 / _mm_sqrt_ps(v26).m128_f32[0];
  *(float *)&dword_1423DECBC = v27 * COERCE_FLOAT(COERCE_UNSIGNED_INT(result.v3.w - result.v3.z) ^ _xmm[0]);
  *(float *)&dword_1423DECB0 = v27 * v36;
  *(float *)&dword_1423DECB4 = v27 * v39;
  *(float *)&dword_1423DECB8 = v27 * v37;
  v28 = UFG::Director::Get()->mCurrentCamera;
  if ( v28 )
    v29 = &v28->mCamera;
  else
    v29 = 0i64;
  v30 = UFG::Camera::GetWorldView(v29);
  UFG::PedSpawnManager::msPedInfoForLocalZoneChecks = 0i64;
  p_mShouldCheckZoneInAreaTime = &this->mAmbientPed[0].mShouldCheckZoneInAreaTime;
  v32 = v30;
  v33 = 260i64;
  do
  {
    if ( *((_DWORD *)p_mShouldCheckZoneInAreaTime - 137) )
    {
      UFG::PedSpawnManager::CollectInfoForOne(
        this,
        (UFG::PedSpawningInfo *)(p_mShouldCheckZoneInAreaTime - 179),
        v32,
        elapsedTime);
      if ( *p_mShouldCheckZoneInAreaTime > 0.0
        && (!UFG::PedSpawnManager::msPedInfoForLocalZoneChecks
         || *p_mShouldCheckZoneInAreaTime > UFG::PedSpawnManager::msPedInfoForLocalZoneChecks->mShouldCheckZoneInAreaTime) )
      {
        UFG::PedSpawnManager::msPedInfoForLocalZoneChecks = (UFG::PedSpawningInfo *)(p_mShouldCheckZoneInAreaTime - 179);
      }
    }
    p_mShouldCheckZoneInAreaTime += 206;
    --v33;
  }
  while ( v33 );
  mScriptedPed = this->mScriptedPed;
  v35 = 120i64;
  do
  {
    if ( mScriptedPed->mActiveStatus )
      UFG::PedSpawnManager::CollectInfoForOne(this, mScriptedPed, v32, elapsedTime);
    ++mScriptedPed;
    --v35;
  }
  while ( v35 );
}

// File Line: 8309
// RVA: 0x418180
void __fastcall UFG::PedSpawnManager::Update(UFG::PedSpawnManager *this, float fElapsedTime)
{
  __int64 i; // rbx
  int v4; // edx

  this->mSpawningModeNow = FromRegion;
  UFG::PedSpawnManager::msElapsedTotal = UFG::PedSpawnManager::msElapsedTotal + fElapsedTime;
  if ( UFG::PedSpawnManager::msShouldUpdatePopulationStats )
  {
    UFG::PedSpawnManager::msShouldUpdatePopulationStats = 0;
    UFG::PedSpawnManager::UpdatePopulationResourceStats(this);
    UFG::ObjectResourceManager::Instance()->mEntityStates[0].mUpdateRequired = 1;
  }
  UFG::qList<UFG::PedSpawningInfo,UFG::PedInfoList,1,0>::MergeSort(&stru_1423DEF70, UFG::PedInfoCompare);
  UFG::PedSpawnManager::msDowngradesThisFrame = 0;
  UFG::PedSpawnManager::UpdatePedDensity();
  UFG::PedSpawnManager::FrameRateThrottle(this);
  if ( UFG::PedSpawnManager::msAmbientSpawningEnable )
  {
    UFG::PedSpawnManager::ExamineActiveZones(this);
    UFG::PedSpawnManager::ExamineInactiveZones(this);
  }
  UFG::PedSpawnManager::CollectPedInfo(this, fElapsedTime);
  if ( UFG::PedSpawnManager::msAmbientSpawningEnable || NISManager::GetInstance()->mState == STATE_INVALID )
  {
    for ( i = qword_1423DEF80[0] - 64i64; (_QWORD *)i != &qword_1423DEF80[-8]; i = *(_QWORD *)(i + 64) - 64i64 )
    {
      if ( *(_DWORD *)(i + 344) != 5 )
        UFG::PedSpawningInfo::UpdateProxyAIandAnimation((UFG::PedSpawningInfo *)i, fElapsedTime);
    }
  }
  UFG::PedSpawnManager::CheckActiveStatusOfPeds(this);
  if ( UFG::PedSpawnManager::msAmbientSpawningEnable )
  {
    v4 = this->mTargetNumActive + UFG::PedSpawnManager::msAmbientCount[0] - 260;
    if ( v4 < 2 )
    {
      if ( v4 <= 0 )
        goto LABEL_16;
    }
    else
    {
      v4 = 2;
    }
    UFG::PedSpawnManager::SpawnPedsInActiveZones(this, v4);
  }
LABEL_16:
  if ( UFG::PedSpawnManager::msRequestEmergencyDump )
  {
    UFG::PedSpawnManager::msRequestEmergencyDump = 0;
    UFG::ObjectResourceManager::PerformEmergencyDump();
  }
  this->mSpawningModeNow = FromScript;
}

// File Line: 8424
// RVA: 0x4094A0
void __fastcall UFG::PedSpawnManager::CollectAllSpawnInfos(
        UFG::PedSpawnManager *this,
        UFG::qPropertyList *list,
        UFG::qArray<UFG::qPropertySet *,0> *spawnInfoArray)
{
  signed int v3; // ebp
  UFG::qPropertyList *v5; // r8
  UFG::PedSpawnManager *v6; // rbx
  UFG::qSymbol *v7; // rax
  UFG::qPropertyList *v8; // rax
  __int64 size; // rcx
  unsigned int capacity; // ebx
  unsigned int v11; // esi
  unsigned int v12; // ebx
  unsigned __int64 v13; // rax
  UFG::allocator::free_link *v14; // rax
  UFG::qPropertySet **v15; // rbp
  __int64 i; // r9
  __int64 v17; // r8
  UFG::qPropertySet **p; // rax
  unsigned int v19; // [rsp+20h] [rbp-28h]
  signed int mNumElements; // [rsp+24h] [rbp-24h]
  UFG::qPropertySet *PropertySet; // [rsp+28h] [rbp-20h]
  signed int v24; // [rsp+68h] [rbp+20h]

  v3 = 0;
  v5 = list;
  v6 = this;
  mNumElements = list->mNumElements;
  v24 = 0;
  if ( mNumElements > 0 )
  {
    do
    {
      v7 = UFG::qPropertyList::Get<UFG::qSymbol>(v5, v3);
      PropertySet = UFG::PropertySetManager::FindPropertySet(v7);
      v8 = UFG::qPropertySet::Get<UFG::qPropertyList>(
             PropertySet,
             (UFG::qArray<unsigned long,0> *)&qSymbol_SpawnSet,
             DEPTH_RECURSE);
      if ( v8 )
      {
        UFG::PedSpawnManager::CollectAllSpawnInfos(v6, v8, spawnInfoArray);
      }
      else
      {
        size = spawnInfoArray->size;
        capacity = spawnInfoArray->capacity;
        v11 = size + 1;
        v19 = spawnInfoArray->size;
        if ( (int)size + 1 > capacity )
        {
          if ( capacity )
            v12 = 2 * capacity;
          else
            v12 = 1;
          for ( ; v12 < v11; v12 *= 2 )
            ;
          if ( v12 <= 2 )
            v12 = 2;
          if ( v12 - v11 > 0x10000 )
            v12 = size + 65537;
          if ( v12 != (_DWORD)size )
          {
            v13 = 8i64 * v12;
            if ( !is_mul_ok(v12, 8ui64) )
              v13 = -1i64;
            v14 = UFG::qMalloc(v13, "spawnInfoArray", 0i64);
            v15 = (UFG::qPropertySet **)v14;
            if ( spawnInfoArray->p )
            {
              for ( i = 0i64;
                    (unsigned int)i < spawnInfoArray->size;
                    v14[v17] = (UFG::allocator::free_link)spawnInfoArray->p[v17] )
              {
                v17 = i;
                i = (unsigned int)(i + 1);
              }
              operator delete[](spawnInfoArray->p);
            }
            size = v19;
            spawnInfoArray->p = v15;
            v3 = v24;
            spawnInfoArray->capacity = v12;
          }
        }
        p = spawnInfoArray->p;
        v6 = this;
        spawnInfoArray->size = v11;
        p[size] = PropertySet;
      }
      v5 = list;
      v24 = ++v3;
    }
    while ( v3 < mNumElements );
  }
}

// File Line: 8451
// RVA: 0x4150F0
signed __int64 __fastcall UFG::PedSpawnManager::RegisterSpawnSet(
        UFG::PedSpawnManager *this,
        UFG::qPropertySet *pSpawnInfoSet,
        bool needed_for_thug_region)
{
  int v6; // ebp
  UFG::ActiveSpawnSetInfo *mActiveSpawnSets; // rax
  int v8; // r9d
  __int64 v9; // rax
  __int64 v10; // r14
  UFG::qArray<UFG::qPropertySet *,0> *p_mSpawnInfoArray; // rsi
  UFG::qPropertySet **p; // rcx
  __int64 v13; // rbx
  void *v14; // rcx
  unsigned int v15; // ebx
  UFG::qPropertyList *v16; // rax
  __int64 size; // r14
  unsigned int capacity; // eax
  unsigned int v20; // edi
  UFG::qPropertySet **v21; // rax

  v6 = -1;
  mActiveSpawnSets = this->mActiveSpawnSets;
  v8 = 0;
  while ( !mActiveSpawnSets->mpPropertySet )
  {
    v6 = v8;
LABEL_5:
    ++v8;
    ++mActiveSpawnSets;
    if ( v8 >= 40 )
      goto LABEL_8;
  }
  if ( mActiveSpawnSets->mpPropertySet != pSpawnInfoSet )
    goto LABEL_5;
  v9 = v8;
  ++this->mActiveSpawnSets[v9].mRefCount;
  this->mActiveSpawnSets[v9].mMediumPriorityOverride |= needed_for_thug_region;
LABEL_8:
  if ( v8 != 40 )
    return (unsigned int)v8;
  if ( v6 < 0 )
    return 39i64;
  v10 = v6;
  p_mSpawnInfoArray = &this->mActiveSpawnSets[v10].mSpawnInfoArray;
  p = p_mSpawnInfoArray->p;
  if ( p )
    operator delete[](p);
  p_mSpawnInfoArray->p = 0i64;
  *(_QWORD *)&p_mSpawnInfoArray->size = 0i64;
  v13 = 56 * (v6 + 5593i64);
  v14 = *(void **)((char *)&this->mNumAmbientCurrentlyActive + v13);
  if ( v14 )
    operator delete[](v14);
  *(_QWORD *)((char *)&this->mNumAmbientCurrentlyActive + v13) = 0i64;
  *(UFG::PedSpawnManagerVtbl **)((char *)&this->vfptr + v13) = 0i64;
  v15 = 1;
  this->mActiveSpawnSets[v10].mpPropertySet = pSpawnInfoSet;
  *(_QWORD *)&this->mActiveSpawnSets[v10].mRefCount = 1i64;
  this->mActiveSpawnSets[v10].mPercentOfGlobalPopulation = 0.0;
  this->mActiveSpawnSets[v10].mMediumPriorityOverride = needed_for_thug_region;
  v16 = UFG::qPropertySet::Get<UFG::qPropertyList>(
          pSpawnInfoSet,
          (UFG::qArray<unsigned long,0> *)&qSymbol_SpawnSet,
          DEPTH_RECURSE);
  if ( v16 )
  {
    UFG::PedSpawnManager::CollectAllSpawnInfos(this, v16, p_mSpawnInfoArray);
  }
  else
  {
    size = p_mSpawnInfoArray->size;
    capacity = p_mSpawnInfoArray->capacity;
    v20 = size + 1;
    if ( (int)size + 1 > capacity )
    {
      if ( capacity )
        v15 = 2 * capacity;
      for ( ; v15 < v20; v15 *= 2 )
        ;
      if ( v15 <= 2 )
        v15 = 2;
      if ( v15 - v20 > 0x10000 )
        v15 = size + 65537;
      UFG::qArray<UFG::CompositeDrawableComponent *,32>::Reallocate(
        (UFG::qArray<UFG::qReflectInventoryBase *,0> *)p_mSpawnInfoArray,
        v15,
        "mActiveSpawnSets");
    }
    v21 = p_mSpawnInfoArray->p;
    p_mSpawnInfoArray->size = v20;
    v21[size] = pSpawnInfoSet;
  }
  return (unsigned int)v6;
}

// File Line: 8611
// RVA: 0x40BA90
void __fastcall UFG::PedSpawnManager::FreeSpawnZone(UFG::SpawnZone *ptr)
{
  UFG::PedSpawnManager::msSpawnZoneFreePtrs[--UFG::PedSpawnManager::msSpawnZoneFreeIndex] = ptr;
  UFG::SpawnZone::OnZoneFree(ptr);
}

// File Line: 8631
// RVA: 0x14EF590
__int64 UFG::_dynamic_initializer_for__gSymDebugSpawnSet__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("default-spawnset-debug", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::gSymDebugSpawnSet, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__gSymDebugSpawnSet__);
}

// File Line: 8634
// RVA: 0x414530
void __fastcall UFG::PedSpawnManager::RegisterActiveSpawnRegion(
        UFG::PedSpawnManager *this,
        UFG::SpawnRegion *pRegion,
        UFG::SceneObjectProperties *pSceneObj)
{
  UFG::qBox *mRawAABB; // rdi
  bool mIsThugRegion; // r12
  UFG::qPropertySet *mpCachedSpawnSet; // rax
  int v6; // esi
  float v9; // xmm9_4
  float v10; // xmm7_4
  float v11; // xmm10_4
  float v12; // xmm11_4
  char v13; // bp
  float v14; // xmm8_4
  int v15; // ecx
  UFG::SpawnZone *v16; // rbx
  int v17; // eax
  int v18; // ecx
  float v19; // xmm4_4
  UFG::SpawnRegion *v20; // rax
  float v21; // xmm0_4
  float *v22; // rcx
  float v23; // xmm4_4
  float v24; // xmm6_4
  float v25; // xmm5_4
  float v26; // xmm3_4
  float v27; // xmm2_4
  float v28; // xmm6_4
  UFG::SpawnRegion *v29; // rcx
  float v30; // xmm8_4
  UFG::qNode<UFG::SpawnZone,UFG::SpawnZoneList> *v31; // rax
  int v32; // ecx
  UFG::SpawnZone *v33; // rbx
  int v34; // eax
  int v35; // ecx
  float x; // xmm4_4
  UFG::SpawnRegion *mpRegion; // rax
  float v38; // xmm0_4
  float *p_x; // rcx
  float v40; // xmm4_4
  float v41; // xmm6_4
  float v42; // xmm5_4
  float v43; // xmm3_4
  float v44; // xmm2_4
  float v45; // xmm6_4
  UFG::SpawnRegion *v46; // rcx
  float v47; // xmm8_4
  UFG::qNode<UFG::SpawnZone,UFG::SpawnZoneList> *mNext; // rax
  int v50; // [rsp+E8h] [rbp+10h]

  mRawAABB = pRegion->mRawAABB;
  mIsThugRegion = pRegion->mIsThugRegion;
  mpCachedSpawnSet = pRegion->mpCachedSpawnSet;
  v6 = 0;
  if ( UFG::gUseDebugSpawnset )
  {
    mpCachedSpawnSet = UFG::PropertySetManager::FindPropertySet(&UFG::gSymDebugSpawnSet);
    mIsThugRegion = 0;
  }
  v50 = UFG::PedSpawnManager::RegisterSpawnSet(this, mpCachedSpawnSet, mIsThugRegion);
  v9 = FLOAT_8_0;
  v10 = 0.0;
  v11 = mRawAABB->mMax.x - mRawAABB->mMin.x;
  v12 = mRawAABB->mMax.y - mRawAABB->mMin.y;
  if ( mIsThugRegion )
    v9 = FLOAT_1000_0;
  v13 = 0;
  v14 = 0.0;
  if ( v11 <= v12 )
  {
    do
    {
      v32 = UFG::PedSpawnManager::msSpawnZoneFreeIndex;
      if ( UFG::PedSpawnManager::msSpawnZoneFreeIndex >= 900 )
        break;
      v33 = UFG::PedSpawnManager::msSpawnZoneFreePtrs[UFG::PedSpawnManager::msSpawnZoneFreeIndex];
      UFG::PedSpawnManager::msSpawnZoneFreePtrs[UFG::PedSpawnManager::msSpawnZoneFreeIndex] = 0i64;
      UFG::PedSpawnManager::msSpawnZoneFreeIndex = v32 + 1;
      if ( !v33 )
        break;
      v33->mpPoint = 0i64;
      v33->mpInterestPoint = 0i64;
      v33->mpRegion = pRegion;
      v33->mIsThugZone = mIsThugRegion;
      UFG::SpawnRegion::AddZone(pRegion, v33);
      v33->mTimeStamp = -999.0;
      v33->mSpawnSetIndex = v50;
      *(_WORD *)&v33->mIsRegion = 1;
      v33->mZoneActiveStatus = ZoneNotActive;
      *(_QWORD *)&v33->mSpawnCount = 0i64;
      *(_QWORD *)&v33->mNumDeadPeds = 0i64;
      v34 = UFG::PedSpawnManager::msMaxNumOfRegisteredZones;
      v35 = UFG::PedSpawnManager::msNumOfRegisteredSpawnZones + 1;
      UFG::PedSpawnManager::msNumOfRegisteredSpawnZones = v35;
      if ( v35 > UFG::PedSpawnManager::msMaxNumOfRegisteredZones )
        v34 = v35;
      UFG::PedSpawnManager::msMaxNumOfRegisteredZones = v34;
      v33->mRetryTime = -1.0;
      v33->mLocalAABB.mMin.x = mRawAABB->mMin.x;
      v33->mLocalAABB.mMin.z = mRawAABB->mMin.z;
      v33->mLocalAABB.mMax.x = mRawAABB->mMax.x;
      v33->mLocalAABB.mMax.z = mRawAABB->mMax.z + 0.69999999;
      v33->mLocalAABB.mMin.y = v10 + mRawAABB->mMin.y;
      v33->mTimeLoaded = UFG::PedSpawnManager::msElapsedTotal;
      if ( v12 >= (float)(v9 * 1.5) )
      {
        v10 = v10 + v9;
        v12 = v12 - v9;
      }
      else
      {
        v10 = v10 + v12;
        v13 = 1;
      }
      x = v33->mLocalAABB.mMin.x;
      mpRegion = v33->mpRegion;
      v38 = v10 + mRawAABB->mMin.y;
      v33->mLocalAABB.mMax.y = v38;
      p_x = &mpRegion->mWorldXForm->v0.x;
      v40 = (float)(x + v33->mLocalAABB.mMax.x) * 0.5;
      v41 = (float)(v33->mLocalAABB.mMin.y + v38) * 0.5;
      v42 = (float)(v33->mLocalAABB.mMin.z + v33->mLocalAABB.mMax.z) * 0.5;
      v43 = (float)(v41 * p_x[4]) + (float)(v40 * *p_x);
      v44 = (float)((float)((float)(v41 * p_x[5]) + (float)(v40 * p_x[1])) + (float)(v42 * p_x[9])) + p_x[13];
      v45 = (float)((float)((float)(v41 * p_x[6]) + (float)(v40 * p_x[2])) + (float)(v42 * p_x[10])) + p_x[14];
      v33->mZoneCentre.x = (float)(v43 + (float)(v42 * p_x[8])) + p_x[12];
      v33->mZoneCentre.y = v44;
      v33->mZoneCentre.z = v45;
      v46 = v33->mpRegion;
      if ( v46 )
      {
        v47 = UFG::SpawnRegion::GetTargetPopulation(
                v46,
                (float)(v33->mLocalAABB.mMax.y - v33->mLocalAABB.mMin.y)
              * (float)(v33->mLocalAABB.mMax.x - v33->mLocalAABB.mMin.x))
            + v14;
        v33->mSpawnCount = (int)(float)(v47 + 0.5);
        v14 = v47 - (float)(int)(float)(v47 + 0.5);
      }
      else
      {
        v33->mSpawnCount = 1;
        v14 = 0.0;
      }
      v6 += v33->mSpawnCount;
      UFG::SpawnZone::AllocatePersistentCullInfo(v33);
      mNext = UFG::PedSpawnManager::msSpawnZoneList.mNode.mNext;
      UFG::PedSpawnManager::msSpawnZoneList.mNode.mNext = &v33->UFG::qNode<UFG::SpawnZone,UFG::SpawnZoneList>;
      v33->UFG::qNode<UFG::SpawnZone,UFG::SpawnZoneList>::mPrev = (UFG::qNode<UFG::SpawnZone,UFG::SpawnZoneList> *)&UFG::PedSpawnManager::msSpawnZoneList;
      v33->UFG::qNode<UFG::SpawnZone,UFG::SpawnZoneList>::mNext = mNext;
      mNext->mPrev = &v33->UFG::qNode<UFG::SpawnZone,UFG::SpawnZoneList>;
    }
    while ( !v13 );
  }
  else
  {
    do
    {
      v15 = UFG::PedSpawnManager::msSpawnZoneFreeIndex;
      if ( UFG::PedSpawnManager::msSpawnZoneFreeIndex >= 900 )
        break;
      v16 = UFG::PedSpawnManager::msSpawnZoneFreePtrs[UFG::PedSpawnManager::msSpawnZoneFreeIndex];
      UFG::PedSpawnManager::msSpawnZoneFreePtrs[UFG::PedSpawnManager::msSpawnZoneFreeIndex] = 0i64;
      UFG::PedSpawnManager::msSpawnZoneFreeIndex = v15 + 1;
      if ( !v16 )
        break;
      v16->mpPoint = 0i64;
      v16->mpInterestPoint = 0i64;
      v16->mpRegion = pRegion;
      v16->mIsThugZone = mIsThugRegion;
      UFG::SpawnRegion::AddZone(pRegion, v16);
      v16->mTimeStamp = -999.0;
      v16->mSpawnSetIndex = v50;
      *(_WORD *)&v16->mIsRegion = 1;
      v16->mZoneActiveStatus = ZoneNotActive;
      *(_QWORD *)&v16->mSpawnCount = 0i64;
      *(_QWORD *)&v16->mNumDeadPeds = 0i64;
      v17 = UFG::PedSpawnManager::msMaxNumOfRegisteredZones;
      v18 = UFG::PedSpawnManager::msNumOfRegisteredSpawnZones + 1;
      UFG::PedSpawnManager::msNumOfRegisteredSpawnZones = v18;
      if ( v18 > UFG::PedSpawnManager::msMaxNumOfRegisteredZones )
        v17 = v18;
      UFG::PedSpawnManager::msMaxNumOfRegisteredZones = v17;
      v16->mRetryTime = -1.0;
      v16->mLocalAABB.mMin.y = mRawAABB->mMin.y;
      v16->mLocalAABB.mMin.z = mRawAABB->mMin.z;
      v16->mLocalAABB.mMax.y = mRawAABB->mMax.y;
      v16->mLocalAABB.mMax.z = mRawAABB->mMax.z + 0.69999999;
      v16->mLocalAABB.mMin.x = v10 + mRawAABB->mMin.x;
      v16->mTimeLoaded = UFG::PedSpawnManager::msElapsedTotal;
      if ( v11 >= (float)(v9 * 1.5) )
      {
        v10 = v10 + v9;
        v11 = v11 - v9;
      }
      else
      {
        v10 = v10 + v11;
        v13 = 1;
      }
      v19 = v16->mLocalAABB.mMin.x;
      v20 = v16->mpRegion;
      v21 = v10 + mRawAABB->mMin.x;
      v16->mLocalAABB.mMax.x = v21;
      v22 = &v20->mWorldXForm->v0.x;
      v23 = (float)(v19 + v21) * 0.5;
      v24 = (float)(v16->mLocalAABB.mMin.y + v16->mLocalAABB.mMax.y) * 0.5;
      v25 = (float)(v16->mLocalAABB.mMin.z + v16->mLocalAABB.mMax.z) * 0.5;
      v26 = (float)((float)((float)(v24 * v22[4]) + (float)(v23 * *v22)) + (float)(v25 * v22[8])) + v22[12];
      v27 = (float)((float)((float)(v24 * v22[5]) + (float)(v23 * v22[1])) + (float)(v25 * v22[9])) + v22[13];
      v28 = (float)((float)((float)(v24 * v22[6]) + (float)(v23 * v22[2])) + (float)(v25 * v22[10])) + v22[14];
      v16->mZoneCentre.y = v27;
      v16->mZoneCentre.x = v26;
      v16->mZoneCentre.z = v28;
      v29 = v16->mpRegion;
      if ( v29 )
      {
        v30 = UFG::SpawnRegion::GetTargetPopulation(
                v29,
                (float)(v16->mLocalAABB.mMax.y - v16->mLocalAABB.mMin.y)
              * (float)(v16->mLocalAABB.mMax.x - v16->mLocalAABB.mMin.x))
            + v14;
        v16->mSpawnCount = (int)(float)(v30 + 0.5);
        v14 = v30 - (float)(int)(float)(v30 + 0.5);
      }
      else
      {
        v16->mSpawnCount = 1;
        v14 = 0.0;
      }
      v6 += v16->mSpawnCount;
      UFG::SpawnZone::AllocatePersistentCullInfo(v16);
      v31 = UFG::PedSpawnManager::msSpawnZoneList.mNode.mNext;
      UFG::PedSpawnManager::msSpawnZoneList.mNode.mNext = &v16->UFG::qNode<UFG::SpawnZone,UFG::SpawnZoneList>;
      v16->UFG::qNode<UFG::SpawnZone,UFG::SpawnZoneList>::mPrev = (UFG::qNode<UFG::SpawnZone,UFG::SpawnZoneList> *)&UFG::PedSpawnManager::msSpawnZoneList;
      v16->UFG::qNode<UFG::SpawnZone,UFG::SpawnZoneList>::mNext = v31;
      v31->mPrev = &v16->UFG::qNode<UFG::SpawnZone,UFG::SpawnZoneList>;
    }
    while ( !v13 );
  }
  this->mActiveSpawnSets[v50].mPopulationPotential += v6;
}

// File Line: 8798
// RVA: 0x4143C0
__int64 __fastcall UFG::PedSpawnManager::RegisterActiveSpawnPoint(
        UFG::PedSpawnManager *this,
        UFG::SpawnPoint *pPoint,
        UFG::SceneObjectProperties *pSpawnSceneObj)
{
  int v3; // r9d
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rsi
  UFG::SpawnZone *v7; // rdi
  bool mThugPoint; // bl
  UFG::qPropertySet *ArchetypeProperties; // rax
  int v10; // eax
  UFG::SpawnPoint *mpPoint; // rax
  UFG::SimObject *m_pSimObject; // rcx
  float x; // eax
  float z; // xmm1_4
  UFG::qNode<UFG::SpawnZone,UFG::SpawnZoneList> *mNext; // rcx

  v3 = UFG::PedSpawnManager::msSpawnZoneFreeIndex;
  if ( UFG::PedSpawnManager::msSpawnZoneFreeIndex >= 900 )
    return 0xFFFFFFFFi64;
  m_pTransformNodeComponent = 0i64;
  v7 = UFG::PedSpawnManager::msSpawnZoneFreePtrs[UFG::PedSpawnManager::msSpawnZoneFreeIndex];
  UFG::PedSpawnManager::msSpawnZoneFreePtrs[UFG::PedSpawnManager::msSpawnZoneFreeIndex] = 0i64;
  UFG::PedSpawnManager::msSpawnZoneFreeIndex = v3 + 1;
  if ( !v7 )
    return 0xFFFFFFFFi64;
  mThugPoint = pPoint->mThugPoint;
  ArchetypeProperties = (UFG::qPropertySet *)UFG::SceneObjectProperties::GetArchetypeProperties(pSpawnSceneObj);
  v10 = UFG::PedSpawnManager::RegisterSpawnSet(this, ArchetypeProperties, 0);
  v7->mpPoint = pPoint;
  v7->mIsThugZone = mThugPoint;
  v7->mSpawnSetIndex = v10;
  v7->mpRegion = 0i64;
  v7->mpInterestPoint = 0i64;
  v7->mTimeStamp = -999.0;
  *(_WORD *)&v7->mIsRegion = 0;
  *(_QWORD *)&v7->mSpawnCount = 1i64;
  *(_QWORD *)&v7->mNumDeadPeds = 0i64;
  v7->mZoneActiveStatus = ZoneNotActive;
  ++UFG::PedSpawnManager::msNumOfRegisteredSpawnZones;
  mpPoint = v7->mpPoint;
  v7->mRetryTime = -1.0;
  m_pSimObject = mpPoint->m_pSimObject;
  if ( m_pSimObject )
    m_pTransformNodeComponent = m_pSimObject->m_pTransformNodeComponent;
  UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
  x = m_pTransformNodeComponent->mWorldTransform.v3.x;
  z = m_pTransformNodeComponent->mWorldTransform.v3.z;
  v7->mZoneCentre.y = m_pTransformNodeComponent->mWorldTransform.v3.y;
  v7->mZoneCentre.z = z;
  v7->mZoneCentre.x = x;
  mNext = UFG::PedSpawnManager::msSpawnZoneList.mNode.mNext;
  UFG::PedSpawnManager::msSpawnZoneList.mNode.mNext = &v7->UFG::qNode<UFG::SpawnZone,UFG::SpawnZoneList>;
  v7->UFG::qNode<UFG::SpawnZone,UFG::SpawnZoneList>::mNext = mNext;
  v7->UFG::qNode<UFG::SpawnZone,UFG::SpawnZoneList>::mPrev = (UFG::qNode<UFG::SpawnZone,UFG::SpawnZoneList> *)&UFG::PedSpawnManager::msSpawnZoneList;
  mNext->mPrev = &v7->UFG::qNode<UFG::SpawnZone,UFG::SpawnZoneList>;
  v7->mTimeLoaded = UFG::PedSpawnManager::msElapsedTotal;
  v7->mHasBeenActivated = 0;
  UFG::SpawnZone::AllocatePersistentCullInfo(v7);
  return (unsigned int)v7->mZoneIndex;
}

// File Line: 8843
// RVA: 0x4152A0
void __fastcall UFG::PedSpawnManager::RegisterSpawningPOI(
        UFG::PedSpawnManager *this,
        UFG::InterestPoint *pPOI,
        UFG::SceneObjectProperties *pSceneObj)
{
  int v3; // ecx
  UFG::SpawnZone *v4; // rbx
  UFG::qVector3 *Position; // rax
  float y; // xmm0_4
  float z; // xmm1_4
  UFG::qNode<UFG::SpawnZone,UFG::SpawnZoneList> *mNext; // rax
  float v9; // xmm0_4

  v3 = UFG::PedSpawnManager::msSpawnZoneFreeIndex;
  if ( UFG::PedSpawnManager::msSpawnZoneFreeIndex < 900 )
  {
    v4 = UFG::PedSpawnManager::msSpawnZoneFreePtrs[UFG::PedSpawnManager::msSpawnZoneFreeIndex];
    UFG::PedSpawnManager::msSpawnZoneFreePtrs[UFG::PedSpawnManager::msSpawnZoneFreeIndex] = 0i64;
    UFG::PedSpawnManager::msSpawnZoneFreeIndex = v3 + 1;
    if ( v4 )
    {
      v4->mpRegion = 0i64;
      v4->mpPoint = 0i64;
      v4->mpInterestPoint = pPOI;
      *(_WORD *)&v4->mHasBeenActivated = 0;
      v4->mTimeStamp = -999.0;
      v4->mSpawnSetIndex = -1;
      v4->mIsRegion = 0;
      *(_QWORD *)&v4->mSpawnCount = 1i64;
      *(_QWORD *)&v4->mNumDeadPeds = 0i64;
      v4->mZoneActiveStatus = ZoneNotActive;
      ++UFG::PedSpawnManager::msNumOfRegisteredSpawnZones;
      v4->mRetryTime = -1.0;
      Position = UFG::InterestPoint::GetPosition(pPOI);
      y = Position->y;
      z = Position->z;
      v4->mZoneCentre.x = Position->x;
      v4->mZoneCentre.y = y;
      v4->mZoneCentre.z = z;
      mNext = UFG::PedSpawnManager::msSpawnZoneList.mNode.mNext;
      UFG::PedSpawnManager::msSpawnZoneList.mNode.mNext = &v4->UFG::qNode<UFG::SpawnZone,UFG::SpawnZoneList>;
      v4->UFG::qNode<UFG::SpawnZone,UFG::SpawnZoneList>::mPrev = (UFG::qNode<UFG::SpawnZone,UFG::SpawnZoneList> *)&UFG::PedSpawnManager::msSpawnZoneList;
      v4->UFG::qNode<UFG::SpawnZone,UFG::SpawnZoneList>::mNext = mNext;
      mNext->mPrev = &v4->UFG::qNode<UFG::SpawnZone,UFG::SpawnZoneList>;
      v9 = UFG::PedSpawnManager::msElapsedTotal;
      v4->mHasBeenActivated = 0;
      v4->mTimeLoaded = v9;
      UFG::SpawnZone::AllocatePersistentCullInfo(v4);
    }
  }
}

// File Line: 8876
// RVA: 0x4180C0
void __fastcall UFG::PedSpawnManager::UnRegisterSpawningPOI(
        UFG::PedSpawnManager *this,
        UFG::InterestPoint *pPOI,
        UFG::SceneObjectProperties *pSceneObj)
{
  UFG::SpawnZone *p_mNext; // rcx

  p_mNext = (UFG::SpawnZone *)&UFG::PedSpawnManager::msActiveZoneList.mNode.mNext[-2].mNext;
  if ( (UFG::qNode<UFG::PedSpawningInfo,UFG::PedSpawningInfo_DrawList> **)&UFG::PedSpawnManager::msActiveZoneList.mNode.mNext[-2].mNext == &UFG::PedSpawningInfo::smNoDrawList.mNode.mNext )
  {
LABEL_4:
    p_mNext = (UFG::SpawnZone *)&UFG::PedSpawnManager::msSpawnZoneList.mNode.mNext[-2].mNext;
    if ( (UFG::qNode<UFG::PedSpawningInfo,UFG::PedSpawningInfo_DrawList> **)&UFG::PedSpawnManager::msSpawnZoneList.mNode.mNext[-2].mNext == &UFG::PedSpawningInfo::smDrawList.mNode.mNext )
    {
LABEL_7:
      p_mNext = (UFG::SpawnZone *)&UFG::PedSpawnManager::msShouldBeActiveZoneList.mNode.mNext[-2].mNext;
      if ( &UFG::PedSpawnManager::msShouldBeActiveZoneList.mNode.mNext[-2].mNext == &UFG::PedSpawnManager::msSpawnZoneList.mNode.mNext )
        return;
      while ( p_mNext->mpInterestPoint != pPOI )
      {
        p_mNext = (UFG::SpawnZone *)&p_mNext->UFG::qNode<UFG::SpawnZone,UFG::SpawnZoneList>::mNext[-2].mNext;
        if ( p_mNext == (UFG::SpawnZone *)&UFG::PedSpawnManager::msSpawnZoneList.mNode.mNext )
          return;
      }
    }
    else
    {
      while ( p_mNext->mpInterestPoint != pPOI )
      {
        p_mNext = (UFG::SpawnZone *)&p_mNext->UFG::qNode<UFG::SpawnZone,UFG::SpawnZoneList>::mNext[-2].mNext;
        if ( p_mNext == (UFG::SpawnZone *)&UFG::PedSpawningInfo::smDrawList.mNode.mNext )
          goto LABEL_7;
      }
    }
  }
  else
  {
    while ( p_mNext->mpInterestPoint != pPOI )
    {
      p_mNext = (UFG::SpawnZone *)&p_mNext->UFG::qNode<UFG::SpawnZone,UFG::SpawnZoneList>::mNext[-2].mNext;
      if ( p_mNext == (UFG::SpawnZone *)&UFG::PedSpawningInfo::smNoDrawList.mNode.mNext )
        goto LABEL_4;
    }
  }
  UFG::PedSpawnManager::msSpawnZoneFreePtrs[--UFG::PedSpawnManager::msSpawnZoneFreeIndex] = p_mNext;
  UFG::SpawnZone::OnZoneFree(p_mNext);
}

// File Line: 8935
// RVA: 0x4156C0
__int64 __fastcall UFG::PedSpawnManager::ReleaseRefToSpawnInfo(
        UFG::PedSpawnManager *this,
        UFG::qPropertySet *pSpawnInfoSet)
{
  UFG::ActiveSpawnSetInfo *mActiveSpawnSets; // rax
  unsigned int v5; // edx
  __int64 v6; // rcx
  __int64 v8; // rsi
  char *v9; // rbx
  void *v11; // rcx
  UFG::qArray<UFG::qPropertySet *,0> *p_mRareSpawnInfoArray; // rbx
  UFG::qPropertySet **p; // rcx

  if ( UFG::gUseDebugSpawnset )
    pSpawnInfoSet = UFG::PropertySetManager::FindPropertySet(&UFG::gSymDebugSpawnSet);
  if ( !pSpawnInfoSet )
    return 0xFFFFFFFFi64;
  mActiveSpawnSets = this->mActiveSpawnSets;
  v5 = 0;
  v6 = 0i64;
  while ( mActiveSpawnSets->mpPropertySet != pSpawnInfoSet )
  {
    ++v6;
    ++v5;
    ++mActiveSpawnSets;
    if ( v6 >= 40 )
      return 0xFFFFFFFFi64;
  }
  v8 = (int)v5;
  v9 = (char *)this + 56 * (int)v5;
  if ( (*((_DWORD *)v9 + 78294))-- == 1 )
  {
    *((_QWORD *)v9 + 39146) = 0i64;
    v9[313188] = 0;
    v11 = (void *)*((_QWORD *)v9 + 39150);
    if ( v11 )
      operator delete[](v11);
    *((_QWORD *)v9 + 39150) = 0i64;
    *((_QWORD *)v9 + 39149) = 0i64;
    p_mRareSpawnInfoArray = &this->mActiveSpawnSets[v8].mRareSpawnInfoArray;
    p = p_mRareSpawnInfoArray->p;
    if ( p )
      operator delete[](p);
    p_mRareSpawnInfoArray->p = 0i64;
    *(_QWORD *)&p_mRareSpawnInfoArray->size = 0i64;
    return (unsigned int)-1;
  }
  return v5;
}

// File Line: 8973
// RVA: 0x416620
void __fastcall UFG::PedSpawnManager::SetAmbientStartingMode(
        UFG::PedSpawnManager *this,
        UFG::PedSpawningInfo *info,
        UFG::qVector3 *pos)
{
  UFG::PedSpawningInfo::eActiveStatus mActiveStatus; // esi
  UFG::PedSpawningInfo::eActiveStatus v6; // edx

  mActiveStatus = info->mActiveStatus;
  if ( UFG::PedSpawnManager::msAmbientSpawningEnable && UFG::PedSpawnManager::msAmbientStatusCheckEnable )
  {
    if ( (int)UFG::PedSpawnManager::GetActiveZoneFromPoint(this, pos, Active) <= 1 )
      return;
    v6 = ExtraLowPower;
  }
  else
  {
    v6 = NormalSuspend;
  }
  if ( v6 != mActiveStatus )
    UFG::PedSpawnManager::ChangeActiveStatus(this, v6, info);
}

// File Line: 9002
// RVA: 0x416240
void __fastcall UFG::PedSpawnManager::SceneLayerActivatedEventHandler(UFG::Event *event)
{
  UFG::PedSpawnManager::msShouldUpdatePopulationStats = 1;
}

// File Line: 9009
// RVA: 0x418040
void __fastcall UFG::PedSpawnManager::UnRegisterActiveSpawnRegion(
        UFG::PedSpawnManager *this,
        UFG::SpawnRegion *pRegion)
{
  int v4; // eax
  UFG::qNode<UFG::SpawnZone,UFG::SpawnRegionList> **p_mNext; // r8
  __int64 v6; // rcx
  int mPopulationPotential; // eax

  v4 = UFG::PedSpawnManager::ReleaseRefToSpawnInfo(this, pRegion->mpCachedSpawnSet);
  if ( v4 >= 0 )
  {
    p_mNext = &pRegion->mZones.mNode.mNext[-3].mNext;
    if ( p_mNext != (UFG::qNode<UFG::SpawnZone,UFG::SpawnRegionList> **)&pRegion->mWorldToLocal.v2.z )
    {
      v6 = v4;
      mPopulationPotential = this->mActiveSpawnSets[v6].mPopulationPotential;
      do
      {
        mPopulationPotential -= *((_DWORD *)p_mNext + 34);
        this->mActiveSpawnSets[v6].mPopulationPotential = mPopulationPotential;
        p_mNext = &p_mNext[6][-3].mNext;
      }
      while ( p_mNext != (UFG::qNode<UFG::SpawnZone,UFG::SpawnRegionList> **)&pRegion->mWorldToLocal.v2.z );
    }
  }
}

// File Line: 9025
// RVA: 0x4182E0
void __fastcall UFG::PedSpawnManager::UpdateActiveSpawnRegion(
        UFG::PedSpawnManager *this,
        UFG::SpawnRegion *pRegion,
        bool regionIsRegistered)
{
  bool mIsThugRegion; // r8
  UFG::qPropertySet *mpCachedSpawnSet; // rax
  int v7; // eax
  UFG::qNode<UFG::SpawnZone,UFG::SpawnRegionList> *mNext; // rbx
  float v9; // xmm6_4
  float *p_z; // rbp
  __int64 p_mNext; // rbx
  __int64 i; // rsi
  UFG::SpawnRegion *v13; // rcx
  float v14; // xmm6_4

  if ( regionIsRegistered )
    UFG::PedSpawnManager::UnRegisterActiveSpawnRegion(this, pRegion);
  mIsThugRegion = pRegion->mIsThugRegion;
  mpCachedSpawnSet = pRegion->mpCachedSpawnSet;
  if ( UFG::gUseDebugSpawnset )
  {
    mpCachedSpawnSet = UFG::PropertySetManager::FindPropertySet(&UFG::gSymDebugSpawnSet);
    mIsThugRegion = 0;
  }
  v7 = UFG::PedSpawnManager::RegisterSpawnSet(this, mpCachedSpawnSet, mIsThugRegion);
  if ( v7 >= 0 )
  {
    mNext = pRegion->mZones.mNode.mNext;
    v9 = 0.0;
    p_z = &pRegion->mWorldToLocal.v2.z;
    p_mNext = (__int64)&mNext[-3].mNext;
    for ( i = v7; (float *)p_mNext != p_z; p_mNext = *(_QWORD *)(p_mNext + 48) - 40i64 )
    {
      v13 = *(UFG::SpawnRegion **)(p_mNext + 64);
      if ( v13 )
      {
        v14 = UFG::SpawnRegion::GetTargetPopulation(
                v13,
                (float)(*(float *)(p_mNext + 104) - *(float *)(p_mNext + 92))
              * (float)(*(float *)(p_mNext + 100) - *(float *)(p_mNext + 88)))
            + v9;
        *(_DWORD *)(p_mNext + 136) = (int)(float)(v14 + 0.5);
        v9 = v14 - (float)(int)(float)(v14 + 0.5);
      }
      else
      {
        *(_DWORD *)(p_mNext + 136) = 1;
        v9 = 0.0;
      }
      this->mActiveSpawnSets[i].mPopulationPotential += *(_DWORD *)(p_mNext + 136);
    }
  }
}

// File Line: 9057
// RVA: 0x417EC0
void __fastcall UFG::PedSpawnManager::UnRegisterActiveSpawnPoint(
        UFG::PedSpawnManager *this,
        UFG::SpawnPoint *pPoint,
        UFG::SceneObjectProperties *pSceneObj)
{
  UFG::SpawnZone *p_mNext; // rcx
  unsigned int mCount; // esi
  unsigned int i; // edi
  UFG::SceneObjectProperties *ChildAsSceneObject; // rax
  UFG::SceneObjectProperties *v9; // rbx
  UFG::qResourceData *ArchetypeProperties; // rax
  __int64 v11; // rcx
  UFG::ActiveSpawnSetInfo *mActiveSpawnSets; // rdx
  __int64 v13; // rcx

  p_mNext = (UFG::SpawnZone *)&UFG::PedSpawnManager::msActiveZoneList.mNode.mNext[-2].mNext;
  if ( (UFG::qNode<UFG::PedSpawningInfo,UFG::PedSpawningInfo_DrawList> **)&UFG::PedSpawnManager::msActiveZoneList.mNode.mNext[-2].mNext == &UFG::PedSpawningInfo::smNoDrawList.mNode.mNext )
  {
LABEL_4:
    p_mNext = (UFG::SpawnZone *)&UFG::PedSpawnManager::msSpawnZoneList.mNode.mNext[-2].mNext;
    if ( (UFG::qNode<UFG::PedSpawningInfo,UFG::PedSpawningInfo_DrawList> **)&UFG::PedSpawnManager::msSpawnZoneList.mNode.mNext[-2].mNext == &UFG::PedSpawningInfo::smDrawList.mNode.mNext )
    {
LABEL_7:
      p_mNext = (UFG::SpawnZone *)&UFG::PedSpawnManager::msShouldBeActiveZoneList.mNode.mNext[-2].mNext;
      if ( &UFG::PedSpawnManager::msShouldBeActiveZoneList.mNode.mNext[-2].mNext == &UFG::PedSpawnManager::msSpawnZoneList.mNode.mNext )
        return;
      while ( p_mNext->mpPoint != pPoint )
      {
        p_mNext = (UFG::SpawnZone *)&p_mNext->UFG::qNode<UFG::SpawnZone,UFG::SpawnZoneList>::mNext[-2].mNext;
        if ( p_mNext == (UFG::SpawnZone *)&UFG::PedSpawnManager::msSpawnZoneList.mNode.mNext )
          return;
      }
    }
    else
    {
      while ( p_mNext->mpPoint != pPoint )
      {
        p_mNext = (UFG::SpawnZone *)&p_mNext->UFG::qNode<UFG::SpawnZone,UFG::SpawnZoneList>::mNext[-2].mNext;
        if ( p_mNext == (UFG::SpawnZone *)&UFG::PedSpawningInfo::smDrawList.mNode.mNext )
          goto LABEL_7;
      }
    }
  }
  else
  {
    while ( p_mNext->mpPoint != pPoint )
    {
      p_mNext = (UFG::SpawnZone *)&p_mNext->UFG::qNode<UFG::SpawnZone,UFG::SpawnZoneList>::mNext[-2].mNext;
      if ( p_mNext == (UFG::SpawnZone *)&UFG::PedSpawningInfo::smNoDrawList.mNode.mNext )
        goto LABEL_4;
    }
  }
  UFG::PedSpawnManager::msSpawnZoneFreePtrs[--UFG::PedSpawnManager::msSpawnZoneFreeIndex] = p_mNext;
  UFG::SpawnZone::OnZoneFree(p_mNext);
  mCount = pSceneObj->mChildren.mCount;
  for ( i = 0; i < mCount; ++i )
  {
    ChildAsSceneObject = UFG::SceneObjectProperties::GetChildAsSceneObject(pSceneObj, i);
    v9 = ChildAsSceneObject;
    if ( ChildAsSceneObject )
    {
      if ( (unsigned int)UFG::SimObjectPropertiesComponent::GetChildType(ChildAsSceneObject) == 1 )
      {
        ArchetypeProperties = UFG::SceneObjectProperties::GetArchetypeProperties(v9);
        if ( ArchetypeProperties )
        {
          v11 = 0i64;
          mActiveSpawnSets = this->mActiveSpawnSets;
          while ( (UFG::qResourceData *)mActiveSpawnSets->mpPropertySet != ArchetypeProperties )
          {
            ++v11;
            ++mActiveSpawnSets;
            if ( v11 >= 40 )
              goto LABEL_21;
          }
          v13 = v11;
          if ( this->mActiveSpawnSets[v13].mRefCount-- == 1 )
            this->mActiveSpawnSets[v13].mpPropertySet = 0i64;
        }
      }
    }
LABEL_21:
    ;
  }
}

// File Line: 9154
// RVA: 0x418830
void __fastcall UFG::PedSpawnManager::UpdatePopulationResourceStats(UFG::PedSpawnManager *this)
{
  int v1; // edx
  int *p_mPopulationPotential; // rcx
  int *v3; // rax
  __int64 v4; // r8
  float v5; // xmm1_4
  __int64 v6; // rax

  v1 = 0;
  p_mPopulationPotential = &this->mActiveSpawnSets[0].mPopulationPotential;
  v3 = p_mPopulationPotential;
  v4 = 8i64;
  do
  {
    if ( *(_QWORD *)(v3 - 3) )
      v1 += *v3;
    if ( *(_QWORD *)(v3 + 11) )
      v1 += v3[14];
    if ( *(_QWORD *)(v3 + 25) )
      v1 += v3[28];
    if ( *(_QWORD *)(v3 + 39) )
      v1 += v3[42];
    if ( *(_QWORD *)(v3 + 53) )
      v1 += v3[56];
    v3 += 70;
    --v4;
  }
  while ( v4 );
  v5 = 0.0;
  if ( v1 > 0 )
    v5 = 1.0 / (float)v1;
  v6 = 4i64;
  do
  {
    if ( *(_QWORD *)(p_mPopulationPotential - 3) )
      *((float *)p_mPopulationPotential + 1) = (float)*p_mPopulationPotential * v5;
    if ( *(_QWORD *)(p_mPopulationPotential + 11) )
      *((float *)p_mPopulationPotential + 15) = (float)p_mPopulationPotential[14] * v5;
    if ( *(_QWORD *)(p_mPopulationPotential + 25) )
      *((float *)p_mPopulationPotential + 29) = (float)p_mPopulationPotential[28] * v5;
    if ( *(_QWORD *)(p_mPopulationPotential + 39) )
      *((float *)p_mPopulationPotential + 43) = (float)p_mPopulationPotential[42] * v5;
    if ( *(_QWORD *)(p_mPopulationPotential + 53) )
      *((float *)p_mPopulationPotential + 57) = (float)p_mPopulationPotential[56] * v5;
    if ( *(_QWORD *)(p_mPopulationPotential + 67) )
      *((float *)p_mPopulationPotential + 71) = (float)p_mPopulationPotential[70] * v5;
    if ( *(_QWORD *)(p_mPopulationPotential + 81) )
      *((float *)p_mPopulationPotential + 85) = (float)p_mPopulationPotential[84] * v5;
    if ( *(_QWORD *)(p_mPopulationPotential + 95) )
      *((float *)p_mPopulationPotential + 99) = (float)p_mPopulationPotential[98] * v5;
    if ( *(_QWORD *)(p_mPopulationPotential + 109) )
      *((float *)p_mPopulationPotential + 113) = (float)p_mPopulationPotential[112] * v5;
    if ( *(_QWORD *)(p_mPopulationPotential + 123) )
      *((float *)p_mPopulationPotential + 127) = (float)p_mPopulationPotential[126] * v5;
    p_mPopulationPotential += 140;
    --v6;
  }
  while ( v6 );
}

// File Line: 9536
// RVA: 0x413F20
void __fastcall UFG::PedSpawnManager::ReInitAmbient(UFG::PedSpawnManager *this)
{
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> **p_mNext; // rbx
  __int64 v2; // rbp
  UFG::SimObject *v3; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v4; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rax
  _QWORD *v6; // rax
  __int64 v7; // rcx

  p_mNext = &this->mAmbientPed[0].mUpgradePOI.mNext;
  v2 = 260i64;
  do
  {
    v3 = (UFG::SimObject *)*(p_mNext - 63);
    if ( v3 )
    {
      if ( v3->m_pSceneObj->mpParent )
        UFG::SceneObjectProperties::DeactivateDeferred(v3->m_pSceneObj);
      else
        UFG::SimObject::Destroy(v3);
    }
    UFG::PedSpawningInfo::MakeCompletelyInactive((UFG::PedSpawningInfo *)(p_mNext - 87));
    *((_DWORD *)p_mNext - 10) = 0;
    if ( *(p_mNext - 42) )
      UFG::TrueCrowdSet::Instance::RemoveProxyReference(
        (UFG::TrueCrowdSet::Instance *)(p_mNext - 42),
        (UFG::PedSpawningInfo *)(p_mNext - 87));
    *(p_mNext - 42) = 0i64;
    *((_DWORD *)p_mNext - 82) = 0;
    *((UFG::qSymbolUC *)p_mNext - 14) = UFG::gNullQSymbolUC;
    *((UFG::qSymbol *)p_mNext - 11) = UFG::gNullQSymbol;
    *((UFG::qSymbol *)p_mNext - 86) = UFG::gNullQSymbol;
    *(p_mNext - 52) = 0i64;
    if ( p_mNext[1] )
    {
      v4 = *(p_mNext - 1);
      v5 = *p_mNext;
      v4->mNext = *p_mNext;
      v5->mPrev = v4;
      *(p_mNext - 1) = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)(p_mNext - 1);
      *p_mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)(p_mNext - 1);
    }
    p_mNext[1] = 0i64;
    if ( *(p_mNext - 67) )
    {
      v6 = *(p_mNext - 68);
      v7 = (__int64)*(p_mNext - 69);
      *(_QWORD *)(v7 + 8) = v6;
      *v6 = v7;
      *(p_mNext - 69) = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)(p_mNext - 69);
      *(p_mNext - 68) = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)(p_mNext - 69);
    }
    *(p_mNext - 67) = 0i64;
    *((_BYTE *)p_mNext - 348) = 0;
    *((_BYTE *)p_mNext + 24) = 0;
    *((_DWORD *)p_mNext + 5) = 0;
    *(UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> **)((char *)p_mNext - 564) = 0i64;
    *((_BYTE *)p_mNext + 68) = 1;
    *((_DWORD *)p_mNext + 31) = -1;
    p_mNext += 103;
    --v2;
  }
  while ( v2 );
}

// File Line: 9545
// RVA: 0x417830
bool __fastcall UFG::PedSpawnManager::SpawnsQueued()
{
  return &UFG::PedSpawnManager::msShouldBeActiveZoneList.mNode.mNext[-2].mNext != (UFG::qNode<UFG::SpawnZone,UFG::SpawnZoneList> **)((char *)&UFG::PedSpawnManager::msShouldBeActiveZoneList - 24)
      && UFG::PedSpawnManager::msAmbientSpawningEnable;
}

// File Line: 9600
// RVA: 0x417A40
void __fastcall UFG::PedSpawnManager::SuspendAllScripted(UFG::PedSpawnManager *this)
{
  UFG::qNode<UFG::PedSpawningInfo,UFG::PedInfoList> *v1; // rbx
  __int64 v2; // rsi
  __int64 mNext_low; // rdx
  bool v4; // zf
  UFG::qNode<UFG::PedSpawningInfo,UFG::PedInfoList> *mPrev; // rcx
  UFG::qNode<UFG::PedSpawningInfo,UFG::PedInfoList> *mNext; // rax
  UFG::qNode<UFG::PedSpawningInfo,UFG::PedInfoList> *v7; // rax
  UFG::qNode<UFG::PedSpawningInfo,UFG::PedInfoList> *v8; // rax
  int v9; // eax
  UFG::TransformNodeComponent *v10; // rdi

  v1 = &this->mScriptedPed[0].UFG::qNode<UFG::PedSpawningInfo,UFG::PedInfoList>;
  v2 = 120i64;
  do
  {
    if ( (unsigned int)(LODWORD(v1[6].mNext) - 1) <= 1 )
    {
      UFG::SimObject::Suspend((UFG::SimObject *)v1[8].mPrev);
      mNext_low = SLODWORD(v1[6].mNext);
      HIDWORD(v1[4].mPrev) = 0;
      BYTE4(v1[43].mNext) = 0;
      if ( (_DWORD)mNext_low != 3 )
      {
        v4 = LODWORD(v1[47].mPrev) == 1;
        mPrev = v1->mPrev;
        mNext = v1->mNext;
        mPrev->mNext = mNext;
        mNext->mPrev = mPrev;
        v1->mPrev = v1;
        v1->mNext = v1;
        if ( v4 )
        {
          v7 = (UFG::qNode<UFG::PedSpawningInfo,UFG::PedInfoList> *)unk_1423DEF98;
          --UFG::PedSpawnManager::msAmbientCount[mNext_low];
          unk_1423DEF98 = v1;
          v1->mNext = v7;
          v1->mPrev = (UFG::qNode<UFG::PedSpawningInfo,UFG::PedInfoList> *)&unk_1423DEF90;
          v7->mPrev = v1;
          ++HIDWORD(qword_1423DC628);
        }
        else
        {
          v8 = UFG::PedSpawnManager::msScriptedList[3].mNode.mPrev;
          --UFG::PedSpawnManager::msScriptedCount[mNext_low];
          v8->mNext = v1;
          v1->mPrev = v8;
          v1->mNext = &UFG::PedSpawnManager::msScriptedList[3].mNode;
          ++HIDWORD(qword_1423DC640);
          UFG::PedSpawnManager::msScriptedList[3].mNode.mPrev = v1;
        }
        LODWORD(v1[6].mNext) = 3;
        UFG::PedSpawningInfo::AllocatePersistentCullInfo((UFG::PedSpawningInfo *)&v1[-4]);
        v9 = (int)v1[6].mNext;
        if ( v9 >= 2 )
        {
          v10 = (UFG::TransformNodeComponent *)v1[11].mPrev;
          if ( !v10 || v9 == 2 )
            v10 = (UFG::TransformNodeComponent *)v1[3].mNext;
          UFG::TransformNodeComponent::UpdateWorldTransform(v10);
          v1[46].mPrev[3].mNext = (UFG::qNode<UFG::PedSpawningInfo,UFG::PedInfoList> *)&v10->mWorldTransform;
        }
      }
    }
    v1 = (UFG::qNode<UFG::PedSpawningInfo,UFG::PedInfoList> *)((char *)v1 + 824);
    --v2;
  }
  while ( v2 );
  UFG::PedSpawnManager::msRestoreWeiOnPhysicsLoad = 0;
}

// File Line: 9626
// RVA: 0x416E60
void __fastcall UFG::PedSpawnManager::SetupSocialForNIS(UFG::PedSpawnManager *this, bool bNISStarting)
{
  UFG::SimObject **p_m_pPointer; // rbx
  __int64 v5; // rdi
  UFG::SimObjectGame *v6; // rcx
  __int16 m_Flags; // r8
  UFG::FaceActionComponent *m_pComponent; // rax
  UFG::SimObject **v9; // rbx
  __int64 v10; // rdi
  UFG::SimObjectGame *v11; // rcx
  __int16 v12; // dx
  UFG::FaceActionComponent *ComponentOfTypeHK; // rax

  p_m_pPointer = &this->mScriptedPed[0].mSimObjectPtr.m_pPointer;
  v5 = 120i64;
  do
  {
    v6 = (UFG::SimObjectGame *)*p_m_pPointer;
    if ( *p_m_pPointer )
    {
      m_Flags = v6->m_Flags;
      if ( (m_Flags & 0x4000) != 0 )
        m_pComponent = (UFG::FaceActionComponent *)v6->m_Components.p[45].m_pComponent;
      else
        m_pComponent = (UFG::FaceActionComponent *)(m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
                                                  ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                      v6,
                                                      UFG::FaceActionComponent::_TypeUID)
                                                  : UFG::SimObject::GetComponentOfType(
                                                      v6,
                                                      UFG::FaceActionComponent::_TypeUID));
      if ( m_pComponent )
        UFG::FaceActionComponent::SetupSocialForNIS(m_pComponent, bNISStarting);
    }
    p_m_pPointer += 103;
    --v5;
  }
  while ( v5 );
  v9 = &this->mAmbientPed[0].mSimObjectPtr.m_pPointer;
  v10 = 260i64;
  do
  {
    v11 = (UFG::SimObjectGame *)*v9;
    if ( *v9 )
    {
      v12 = v11->m_Flags;
      if ( (v12 & 0x4000) != 0 )
      {
        ComponentOfTypeHK = (UFG::FaceActionComponent *)v11->m_Components.p[45].m_pComponent;
      }
      else if ( v12 < 0 || (v12 & 0x2000) != 0 || (v12 & 0x1000) != 0 )
      {
        ComponentOfTypeHK = (UFG::FaceActionComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                          v11,
                                                          UFG::FaceActionComponent::_TypeUID);
      }
      else
      {
        ComponentOfTypeHK = (UFG::FaceActionComponent *)UFG::SimObject::GetComponentOfType(
                                                          v11,
                                                          UFG::FaceActionComponent::_TypeUID);
      }
      if ( ComponentOfTypeHK )
        UFG::FaceActionComponent::SetupSocialForNIS(ComponentOfTypeHK, bNISStarting);
    }
    v9 += 103;
    --v10;
  }
  while ( v10 );
}

// File Line: 9665
// RVA: 0x416140
void __fastcall UFG::PedSpawnManager::ResetSpawnZones(UFG::PedSpawnManager *this)
{
  UFG::qList<UFG::SpawnZone,UFG::SpawnZoneList,1,0> *i; // r9
  UFG::qList<UFG::SpawnZone,UFG::SpawnZoneList,1,0> *v2; // r8
  UFG::qNode<UFG::SpawnZone,UFG::SpawnZoneList> *mPrev; // r9
  UFG::qNode<UFG::SpawnZone,UFG::SpawnZoneList> *v4; // rax
  UFG::qNode<UFG::SpawnZone,UFG::SpawnZoneList> *mNext; // rcx
  UFG::qNode<UFG::SpawnZone,UFG::SpawnZoneList> *v6; // rax

  for ( i = (UFG::qList<UFG::SpawnZone,UFG::SpawnZoneList,1,0> *)&UFG::PedSpawnManager::msActiveZoneList.mNode.mNext[-2].mNext;
        i != (UFG::qList<UFG::SpawnZone,UFG::SpawnZoneList,1,0> *)((char *)&UFG::PedSpawnManager::msActiveZoneList - 24);
        BYTE1(v2[7].mNode.mPrev) = 0 )
  {
    v2 = i;
    mPrev = i[2].mNode.mPrev;
    v4 = v2[2].mNode.mPrev;
    mNext = v2[1].mNode.mNext;
    mNext->mNext = v4;
    v4->mPrev = mNext;
    v2[1].mNode.mNext = (UFG::qNode<UFG::SpawnZone,UFG::SpawnZoneList> *)&v2[1].mNode.mNext;
    v2[2].mNode.mPrev = (UFG::qNode<UFG::SpawnZone,UFG::SpawnZoneList> *)&v2[1].mNode.mNext;
    v6 = UFG::PedSpawnManager::msSpawnZoneList.mNode.mNext;
    UFG::PedSpawnManager::msSpawnZoneList.mNode.mNext = (UFG::qNode<UFG::SpawnZone,UFG::SpawnZoneList> *)&v2[1].mNode.mNext;
    v2[1].mNode.mNext = (UFG::qNode<UFG::SpawnZone,UFG::SpawnZoneList> *)&UFG::PedSpawnManager::msSpawnZoneList;
    v2[2].mNode.mPrev = v6;
    v6->mPrev = (UFG::qNode<UFG::SpawnZone,UFG::SpawnZoneList> *)&v2[1].mNode.mNext;
    i = (UFG::qList<UFG::SpawnZone,UFG::SpawnZoneList,1,0> *)&mPrev[-2].mNext;
    LODWORD(v2[3].mNode.mNext) = 1;
    HIDWORD(v2[7].mNode.mPrev) = 0;
  }
}

// File Line: 9685
// RVA: 0x4161D0
void __fastcall UFG::PedSpawnManager::RestoreAllScriptedToFullyActive(UFG::PedSpawnManager *this)
{
  UFG::PedSpawningInfo::eActiveStatus *p_mActiveStatus; // rbx
  UFG::PedSpawningInfo *mScriptedPed; // rdi
  __int64 v4; // rsi

  p_mActiveStatus = &this->mScriptedPed[0].mActiveStatus;
  mScriptedPed = this->mScriptedPed;
  v4 = 120i64;
  do
  {
    if ( *p_mActiveStatus )
      UFG::PedSpawnManager::ChangeStatusToActive(this, mScriptedPed);
    ++mScriptedPed;
    p_mActiveStatus += 206;
    --v4;
  }
  while ( v4 );
}

// File Line: 9704
// RVA: 0x40B4E0
UFG::SimComponent *__fastcall UFG::PedSpawnManager::FindPedInfoFromSimObject(
        UFG::PedSpawnManager *this,
        UFG::SimObjectGame *simObj)
{
  signed __int16 m_Flags; // cx
  unsigned int v5; // edx
  UFG::SimObjectGame *v6; // rcx
  bool v7; // zf

  if ( !simObj )
    return 0i64;
  m_Flags = simObj->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
    return simObj->m_Components.p[48].m_pComponent;
  if ( m_Flags < 0 || (m_Flags & 0x2000) != 0 )
  {
    v5 = UFG::PedSpawningInfo::_TypeUID;
    v6 = simObj;
    return UFG::SimObjectGame::GetComponentOfTypeHK(v6, v5);
  }
  v5 = UFG::PedSpawningInfo::_TypeUID;
  v7 = (m_Flags & 0x1000) == 0;
  v6 = simObj;
  if ( !v7 )
    return UFG::SimObjectGame::GetComponentOfTypeHK(v6, v5);
  return UFG::SimObject::GetComponentOfType(simObj, UFG::PedSpawningInfo::_TypeUID);
}

// File Line: 9751
// RVA: 0x40C030
void __fastcall UFG::PedSpawnManager::GetGroupCandidates(
        UFG::PedSpawnManager *this,
        UFG::PedSpawningInfo *pPed,
        UFG::qFixedArray<UFG::PedSpawningInfo *,10> *closePeds,
        UFG::qVector3 *pos,
        const float radius)
{
  unsigned int size; // r10d
  int v7; // r11d
  UFG::qNode<UFG::PedSpawningInfo,UFG::PedInfoList> **p_mNext; // rsi
  __int64 v9; // rcx
  __int64 v10; // rdx

  size = closePeds->size;
  v7 = 1;
  if ( closePeds->size < 0xA )
  {
    p_mNext = &stru_1423DEF70.mNode.mNext;
    do
    {
      if ( v7 > 3 )
        break;
      v9 = (__int64)&(*p_mNext)[-4];
      if ( size < 0xA )
      {
        do
        {
          if ( (UFG::qList<UFG::PedSpawningInfo,UFG::PedInfoList,1,0> *)v9 == &UFG::PedSpawnManager::msAmbientList[v7 - 4] )
            break;
          v10 = *(_QWORD *)(v9 + 72);
          if ( pPed != (UFG::PedSpawningInfo *)v9
            && (float)((float)((float)((float)(pos->y - *(float *)(v9 + 772)) * (float)(pos->y - *(float *)(v9 + 772)))
                             + (float)((float)(pos->x - *(float *)(v9 + 768)) * (float)(pos->x - *(float *)(v9 + 768))))
                     + (float)((float)(pos->z - *(float *)(v9 + 776)) * (float)(pos->z - *(float *)(v9 + 776)))) <= (float)(radius * radius) )
          {
            closePeds->p[size] = (UFG::PedSpawningInfo *)v9;
            ++closePeds->size;
          }
          size = closePeds->size;
          v9 = v10 - 64;
        }
        while ( closePeds->size < 0xA );
      }
      size = closePeds->size;
      ++v7;
      p_mNext += 2;
    }
    while ( closePeds->size < 0xA );
  }
}

// File Line: 9809
// RVA: 0x4136D0
void __fastcall UFG::PedSpawning_AmbientPedEnableLockHelper(bool lock)
{
  sAmbientPedEnableLocked = lock;
}

// File Line: 9814
// RVA: 0x413620
void __fastcall UFG::PedSpawning_AmbientPedEnableHelper(bool enablePeds)
{
  UFG::PedSpawnManager *v1; // rbx

  if ( !sAmbientPedEnableLocked )
  {
    if ( enablePeds )
    {
      if ( !UFG::PedSpawnManager::msAmbientSpawningEnable )
      {
        UFG::PedSpawnManager::msAmbientSpawningEnable = 1;
        UFG::PedSpawnManager::msCheckStatusMode = 1;
        UFG::PedSpawnManager::msAmbientStatusCheckEnable = 1;
        UFG::PedSpawnManager::msResourcesSuspended = 0;
        UFG::ObjectResourceManager::Instance()->mEntityStates[0].mUpdateRequired = 1;
      }
    }
    else if ( UFG::PedSpawnManager::msAmbientSpawningEnable )
    {
      v1 = UFG::gpPedSpawnManager;
      UFG::PedSpawnManager::ReInitAmbient(UFG::gpPedSpawnManager);
      UFG::PedSpawnManager::ResetSpawnZones(v1);
      UFG::PedSpawnManager::msAmbientSpawningEnable = 0;
      UFG::PedSpawnManager::msCheckStatusMode = 1;
      UFG::PedSpawnManager::msAmbientStatusCheckEnable = 0;
      UFG::PedSpawnManager::msResourcesSuspended = 1;
      UFG::ObjectResourceManager::Instance()->mEntityStates[0].mUpdateRequired = 1;
    }
  }
}

