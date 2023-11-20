// File Line: 331
// RVA: 0x418B10
void __fastcall UFG::qMatrix44_MakeFaceDir2(UFG::qMatrix44 *output, UFG::qVector3 *origin, UFG::qVector3 *dir, UFG::qVector3 *upDir)
{
  float v4; // xmm0_4
  float v5; // xmm1_4
  float v6; // eax
  float v7; // xmm8_4
  __m128 v8; // xmm3
  float v9; // xmm9_4
  __m128 v10; // xmm2
  float v11; // xmm1_4
  float v12; // xmm3_4
  float v13; // xmm8_4
  float v14; // xmm9_4
  __int128 v15; // xmm5
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

  v4 = origin->y;
  v5 = origin->z;
  v6 = origin->x;
  output->v3.w = 1.0;
  output->v3.x = v6;
  output->v3.y = v4;
  output->v3.z = v5;
  v7 = upDir->y;
  v8 = (__m128)LODWORD(upDir->x);
  v9 = upDir->z;
  v10 = v8;
  v10.m128_f32[0] = (float)((float)(v8.m128_f32[0] * v8.m128_f32[0]) + (float)(v7 * v7)) + (float)(v9 * v9);
  if ( v10.m128_f32[0] == 0.0 )
    v11 = 0.0;
  else
    v11 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v10));
  v12 = v8.m128_f32[0] * v11;
  v13 = v7 * v11;
  v14 = v9 * v11;
  output->v2.w = 0.0;
  output->v2.x = v12;
  output->v2.y = v13;
  output->v2.z = v14;
  v15 = LODWORD(dir->y);
  v16 = (__m128)LODWORD(dir->x);
  v17 = dir->z;
  v18 = v16;
  v18.m128_f32[0] = (float)((float)(v16.m128_f32[0] * v16.m128_f32[0]) + (float)(*(float *)&v15 * *(float *)&v15))
                  + (float)(v17 * v17);
  if ( v18.m128_f32[0] == 0.0 )
    v19 = 0.0;
  else
    v19 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v18));
  v20 = *(float *)&v15 * v19;
  v16.m128_f32[0] = v16.m128_f32[0] * v19;
  v21 = v17 * v19;
  v23 = v16;
  v22 = (float)(v21 * v13) - (float)(v20 * v14);
  v23.m128_f32[0] = (float)(v16.m128_f32[0] * v14) - (float)(v21 * v12);
  *(float *)&v15 = (float)(v20 * v12) - (float)(v16.m128_f32[0] * v13);
  v24 = v23;
  v24.m128_f32[0] = (float)((float)(v23.m128_f32[0] * v23.m128_f32[0]) + (float)(v22 * v22))
                  + (float)(*(float *)&v15 * *(float *)&v15);
  if ( v24.m128_f32[0] == 0.0 )
    v25 = 0.0;
  else
    v25 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v24));
  *(float *)&v15 = *(float *)&v15 * v25;
  v26 = v22 * v25;
  v27 = v23.m128_f32[0] * v25;
  v28 = v13;
  output->v1.w = 0.0;
  LODWORD(output->v1.z) = v15;
  output->v1.x = v26;
  output->v1.y = v27;
  v29 = (float)(v27 * v14) - (float)(*(float *)&v15 * v13);
  *(float *)&v15 = (float)(*(float *)&v15 * v12) - (float)(v26 * v14);
  v30 = (float)(v26 * v28) - (float)(v27 * v12);
  v31 = (__m128)v15;
  v31.m128_f32[0] = (float)((float)(*(float *)&v15 * *(float *)&v15) + (float)(v29 * v29)) + (float)(v30 * v30);
  if ( v31.m128_f32[0] == 0.0 )
    v32 = 0.0;
  else
    v32 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v31));
  output->v0.w = 0.0;
  output->v0.x = v29 * v32;
  output->v0.z = v30 * v32;
  output->v0.y = *(float *)&v15 * v32;
}

// File Line: 344
// RVA: 0x40C3D0
void __fastcall UFG::GetInterestPointUpRightMatrix(UFG::InterestPoint *interestPoint, UFG::qMatrix44 *outputMatrix)
{
  UFG::TransformNodeComponent *v2; // rbx
  UFG::qMatrix44 *v3; // rdi
  float v4; // xmm4_4
  float v5; // xmm5_4
  float v6; // xmm0_4
  float v7; // xmm1_4
  float v8; // xmm2_4
  UFG::qVector3 dir; // [rsp+20h] [rbp-28h]
  UFG::qVector3 origin; // [rsp+2Ch] [rbp-1Ch]

  v2 = interestPoint->mpXformNode;
  v3 = outputMatrix;
  UFG::TransformNodeComponent::UpdateWorldTransform(interestPoint->mpXformNode);
  v4 = v2->mWorldTransform.v0.y;
  v5 = v2->mWorldTransform.v0.z;
  v6 = v2->mWorldTransform.v3.x;
  v7 = v2->mWorldTransform.v3.y;
  v8 = v2->mWorldTransform.v3.z;
  dir.x = v2->mWorldTransform.v0.x;
  dir.y = v4;
  dir.z = v5;
  origin.x = v6;
  origin.y = v7;
  origin.z = v8;
  UFG::qMatrix44_MakeFaceDir2(v3, &origin, &dir, &UFG::qVector3::msDirUp);
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
  return atexit(dynamic_atexit_destructor_for__UFG::PedSpawnManager::msSpawnZoneList__);
}

// File Line: 521
// RVA: 0x14E9130
__int64 dynamic_initializer_for__UFG::PedSpawnManager::msActiveZoneList__()
{
  return atexit(dynamic_atexit_destructor_for__UFG::PedSpawnManager::msActiveZoneList__);
}

// File Line: 522
// RVA: 0x14E9310
__int64 dynamic_initializer_for__UFG::PedSpawnManager::msShouldBeActiveZoneList__()
{
  return atexit(dynamic_atexit_destructor_for__UFG::PedSpawnManager::msShouldBeActiveZoneList__);
}

// File Line: 526
// RVA: 0x14E9150
__int64 dynamic_initializer_for__UFG::PedSpawnManager::msAmbientList__()
{
  `eh vector constructor iterator'(
    UFG::PedSpawnManager::msAmbientList,
    0x10ui64,
    6,
    (void (__fastcall *)(void *))UFG::TargetSphere::TargetSphere);
  return atexit(dynamic_atexit_destructor_for__UFG::PedSpawnManager::msAmbientList__);
}

// File Line: 529
// RVA: 0x14E92A0
__int64 dynamic_initializer_for__UFG::PedSpawnManager::msScriptedList__()
{
  `eh vector constructor iterator'(
    UFG::PedSpawnManager::msScriptedList,
    0x10ui64,
    6,
    (void (__fastcall *)(void *))UFG::TargetSphere::TargetSphere);
  return atexit(dynamic_atexit_destructor_for__UFG::PedSpawnManager::msScriptedList__);
}

// File Line: 538
// RVA: 0x14E91F0
__int64 dynamic_initializer_for__UFG::PedSpawnManager::msDisabledThugZones__()
{
  `eh vector constructor iterator'(
    &UFG::PedSpawnManager::msDisabledThugZones,
    8ui64,
    10,
    (void (__fastcall *)(void *))UFG::DisabledThugZone::DisabledThugZone);
  return atexit(dynamic_atexit_destructor_for__UFG::PedSpawnManager::msDisabledThugZones__);
}

// File Line: 569
// RVA: 0x14E9230
__int64 dynamic_initializer_for__UFG::PedSpawnManager::msLowLODHandles__()
{
  `eh vector constructor iterator'(
    &UFG::PedSpawnManager::msLowLODHandles,
    0x20ui64,
    15,
    (void (__fastcall *)(void *))Illusion::ModelHandle::ModelHandle);
  return atexit(dynamic_atexit_destructor_for__UFG::PedSpawnManager::msLowLODHandles__);
}

// File Line: 668
// RVA: 0x405580
void __fastcall UFG::SpawnZone::SpawnZone(UFG::SpawnZone *this)
{
  UFG::SpawnZone *v1; // rbx
  UFG::qNode<UFG::SpawnZone,UFG::SpawnZoneList> *v2; // rax
  UFG::qNode<UFG::SpawnZone,UFG::SpawnRegionList> *v3; // rax

  v1 = this;
  v2 = (UFG::qNode<UFG::SpawnZone,UFG::SpawnZoneList> *)&this->mPrev;
  v2->mPrev = v2;
  v2->mNext = v2;
  v3 = (UFG::qNode<UFG::SpawnZone,UFG::SpawnRegionList> *)&this->mPrev;
  v3->mPrev = v3;
  v3->mNext = v3;
  UFG::qSafePointerNode<UFG::SpawnZone>::qSafePointerNode<UFG::SpawnZone>((UFG::qSafePointerNode<UFG::SpawnZone> *)&this->vfptr);
  v1->vfptr = (UFG::qSafePointerNode<UFG::SpawnZone>Vtbl *)&UFG::SpawnZone::`vftable';
  *(_QWORD *)&v1->mLocalAABB.mMin.x = 0i64;
  *(_QWORD *)&v1->mLocalAABB.mMin.z = 0i64;
  *(_QWORD *)&v1->mLocalAABB.mMax.y = 0i64;
  v1->mpRegion = 0i64;
  v1->mpPoint = 0i64;
  v1->mpInterestPoint = 0i64;
  *(_WORD *)&v1->mHasBeenActivated = 0;
  v1->mTimeStamp = -999.0;
  v1->mSpawnSetIndex = 0;
  v1->mIsRegion = 1;
  v1->mSpawnCount = 0;
  *(_QWORD *)&v1->mNumDeadPeds = 0i64;
  v1->mCullResults = 0i64;
  v1->mCullInfo = 0i64;
  v1->mZoneActiveStatus = 0;
}

// File Line: 794
// RVA: 0x406810
void __fastcall UFG::SpawnZone::~SpawnZone(UFG::SpawnZone *this)
{
  UFG::SpawnZone *v1; // rdi
  UFG::qNode<UFG::qSafePointerBase<UFG::SpawnZone>,UFG::qSafePointerNodeList> *v2; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SpawnZone>,UFG::qSafePointerNodeList> *v3; // rax
  UFG::qNode<UFG::SpawnZone,UFG::SpawnRegionList> *v4; // rdx
  UFG::qNode<UFG::SpawnZone,UFG::SpawnRegionList> *v5; // rcx
  UFG::qNode<UFG::SpawnZone,UFG::SpawnRegionList> *v6; // rax
  UFG::qNode<UFG::SpawnZone,UFG::SpawnZoneList> *v7; // rdx
  UFG::qNode<UFG::SpawnZone,UFG::SpawnZoneList> *v8; // rcx
  UFG::qNode<UFG::SpawnZone,UFG::SpawnZoneList> *v9; // rax

  v1 = this;
  this->vfptr = (UFG::qSafePointerNode<UFG::SpawnZone>Vtbl *)&UFG::SpawnZone::`vftable';
  this->vfptr = (UFG::qSafePointerNode<UFG::SpawnZone>Vtbl *)&UFG::qSafePointerNode<UFG::SpawnZone>::`vftable';
  UFG::qSafePointerNode<UFG::DynamicCoverCorner>::SetAllPointersToNull((UFG::qSafePointerNode<UFG::ParkourHandle> *)this);
  UFG::qList<UFG::qSafePointerBase<CanAttackConditionGroup>,UFG::qSafePointerNodeList,1,0>::DeleteNodes((UFG::qList<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList,1,0> *)&v1->m_SafePointerList);
  v2 = v1->m_SafePointerList.mNode.mPrev;
  v3 = v1->m_SafePointerList.mNode.mNext;
  v2->mNext = v3;
  v3->mPrev = v2;
  v1->m_SafePointerList.mNode.mPrev = &v1->m_SafePointerList.mNode;
  v1->m_SafePointerList.mNode.mNext = &v1->m_SafePointerList.mNode;
  v4 = (UFG::qNode<UFG::SpawnZone,UFG::SpawnRegionList> *)&v1->mPrev;
  v5 = v1->mPrev;
  v6 = v1->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  v4->mPrev = v4;
  v4->mNext = v4;
  v7 = (UFG::qNode<UFG::SpawnZone,UFG::SpawnZoneList> *)&v1->mPrev;
  v8 = v1->mPrev;
  v9 = v1->mNext;
  v8->mNext = v9;
  v9->mPrev = v8;
  v7->mPrev = v7;
  v7->mNext = v7;
}

// File Line: 807
// RVA: 0x413530
void __fastcall UFG::SpawnZone::OnZoneFree(UFG::SpawnZone *this)
{
  UFG::qNode<UFG::SpawnZone,UFG::SpawnZoneList> *v1; // rdx
  UFG::qNode<UFG::SpawnZone,UFG::SpawnZoneList> *v2; // rax
  UFG::qNode<UFG::SpawnZone,UFG::SpawnZoneList> *v3; // r8
  UFG::SpawnZone *v4; // rbx
  int v5; // eax
  CullManager *v6; // rax

  v1 = this->mPrev;
  v2 = this->mNext;
  v3 = (UFG::qNode<UFG::SpawnZone,UFG::SpawnZoneList> *)&this->mPrev;
  v1->mNext = v2;
  v2->mPrev = v1;
  v3->mPrev = v3;
  v3->mNext = v3;
  v4 = this;
  if ( this->mIsThugZone )
  {
    v5 = this->mNumDeadPeds;
    if ( v5 )
    {
      if ( v5 >= this->mSpawnCount )
        UFG::PedSpawnManager::AddZoneToThugSpawningExceptionsArrary(UFG::gpPedSpawnManager, this);
    }
  }
  --UFG::PedSpawnManager::msNumOfRegisteredSpawnZones;
  v4->mTimeStamp = -999.0;
  v4->mpRegion = 0i64;
  v4->mpPoint = 0i64;
  v4->mpInterestPoint = 0i64;
  *(_WORD *)&v4->mHasBeenActivated = 0;
  v4->mSpawnSetIndex = 0;
  v4->mSpawnCount = 0;
  v4->mNumDeadPeds = 0;
  v4->mIsRegion = 1;
  v6 = CullManager::Instance();
  CullManager::FreePersistentCullInfo(v6, v4->mCullResults, v4->mCullInfo);
  v4->mCullInfo = 0i64;
  v4->mCullResults = 0i64;
  v4->mZoneActiveStatus = 0;
  v4->mAliveCountValidationTag = 0;
  UFG::qSafePointerNode<UFG::DynamicCoverCorner>::SetAllPointersToNull((UFG::qSafePointerNode<UFG::ParkourHandle> *)v4);
}

// File Line: 880
// RVA: 0x407780
void __fastcall UFG::SpawnZone::AllocatePersistentCullInfo(UFG::SpawnZone *this)
{
  UFG::SpawnZone *v1; // rdi
  CullInfo **v2; // rsi
  CullManager *v3; // rax
  char *v4; // rax
  CullInfo *v5; // rcx
  CullInfo *v6; // rcx
  CullInfo *v7; // rax
  CullInfo *v8; // rax
  void *v9; // rax
  CullInfo *v10; // rax
  __int64 v11; // rbx

  v1 = this;
  v2 = &this->mCullInfo;
  v3 = CullManager::Instance();
  CullManager::AllocPersistentCullInfo(v3, &v1->mCullResults, v2, 0i64, 0i64, 0i64);
  (*v2)->mViewsCulled = ~(1 << gMainCullIndex);
  (*v2)->mPixelScaleBias = CullManager::Instance()->mPixelDensityDynamicBias;
  if ( gMainCullIndex <= 16 && gMainCullIndex >= 0 )
  {
    v4 = &v1->mCullResults->mViewResult[gMainCullIndex];
    if ( v4 )
      *v4 = 2;
  }
  if ( v1->mIsRegion )
  {
    v5 = *v2;
    v5->mAABBMin[0] = v1->mLocalAABB.mMin.x;
    v5->mAABBMin[1] = v1->mLocalAABB.mMin.y;
    v5->mAABBMin[2] = v1->mLocalAABB.mMin.z;
    v6 = *v2;
    v6->mAABBMax[0] = v1->mLocalAABB.mMax.x;
    v6->mAABBMax[1] = v1->mLocalAABB.mMax.y;
    v6->mAABBMax[2] = v1->mLocalAABB.mMax.z;
    (*v2)->mpLocalWorld = &v1->mpRegion->mWorldXForm->v0.x;
  }
  else
  {
    v7 = *v2;
    if ( v1->mpPoint )
    {
      v7->mAABBMin[0] = minOffset.x;
      v7->mAABBMin[1] = minOffset.y;
      v7->mAABBMin[2] = minOffset.z;
      v8 = *v2;
      v8->mAABBMax[0] = maxOffset.x;
      v8->mAABBMax[1] = maxOffset.y;
      v8->mAABBMax[2] = maxOffset.z;
      v9 = v1->mpPoint;
    }
    else
    {
      v7->mAABBMin[0] = minOffsetPOI.x;
      v7->mAABBMin[1] = minOffsetPOI.y;
      v7->mAABBMin[2] = minOffsetPOI.z;
      v10 = *v2;
      v10->mAABBMax[0] = maxOffsetPOI.x;
      v10->mAABBMax[1] = maxOffsetPOI.y;
      v10->mAABBMax[2] = maxOffsetPOI.z;
      v9 = v1->mpInterestPoint;
    }
    v11 = *((_QWORD *)v9 + 13);
    UFG::TransformNodeComponent::UpdateWorldTransform(*((UFG::TransformNodeComponent **)v9 + 13));
    (*v2)->mpLocalWorld = (float *)(v11 + 128);
  }
}

// File Line: 977
// RVA: 0x4080A0
char __fastcall UFG::SpawnZone::CalcSpawnPoint(UFG::SpawnZone *this, UFG::qVector3 *newPoint)
{
  UFG::qVector3 *v2; // rdi
  UFG::SpawnZone *v3; // rbx
  UFG::qVector3 *v4; // rax
  float v5; // xmm3_4
  float v6; // xmm5_4
  float *v7; // rcx
  float v8; // xmm4_4
  float v9; // xmm2_4
  float v10; // xmm6_4
  unsigned int v11; // xmm1_4
  char v12; // al
  float v13; // xmm0_4
  UFG::qVector3 rayStart; // [rsp+20h] [rbp-D8h]
  UFG::qVector3 rayEnd; // [rsp+30h] [rbp-C8h]
  UFG::qVector3 result; // [rsp+40h] [rbp-B8h]
  UFG::RayCastData data; // [rsp+50h] [rbp-A8h]

  v2 = newPoint;
  v3 = this;
  v4 = UFG::qBox::GetRandomPosition(&this->mLocalAABB, &result);
  v5 = v4->y;
  v6 = v4->z;
  v2->x = v4->x;
  v2->y = v5;
  v2->z = v6;
  v7 = &v3->mpRegion->mWorldXForm->v0.x;
  v8 = (float)((float)((float)(v5 * v7[4]) + (float)(v2->x * *v7)) + (float)(v6 * v7[8])) + v7[12];
  v9 = (float)((float)((float)(v2->x * v7[1]) + (float)(v5 * v7[5])) + (float)(v6 * v7[9])) + v7[13];
  v10 = (float)((float)((float)(v2->x * v7[2]) + (float)(v5 * v7[6])) + (float)(v6 * v7[10])) + v7[14];
  v2->x = v8;
  v2->y = v9;
  data.mInput.m_filterInfo = 0;
  data.mInput.m_userData = 0i64;
  data.mOutput.m_shapeKeys[6] = 0;
  *((_QWORD *)&data.mOutput.m_shapeKeyIndex + 1) = 0i64;
  v2->z = v10;
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
  v11 = data.mCollisionModelName.mUID;
  v12 = 1;
  v2->x = *((float *)&data.mDebugName + 1);
  v13 = data.point.x;
  LODWORD(v2->y) = v11;
  v2->z = v13;
  return v12;
}

// File Line: 1086
// RVA: 0x416FD0
__int64 __fastcall UFG::SpawnZone::ShouldSpawnZoneActivate(UFG::SpawnZone *this)
{
  UFG::SpawnZone *v1; // rbx
  CullResults *v2; // rcx
  unsigned __int8 v3; // di
  UFG::qVector3 *v5; // rax
  UFG::InterestPoint *v6; // rcx
  float v7; // xmm2_4
  float v8; // xmm0_4
  float v9; // xmm1_4
  bool v10; // cf
  bool v11; // zf

  v1 = this;
  v2 = this->mCullResults;
  v3 = 0;
  if ( !v2 )
    return v3;
  if ( gMainCullIndex < 0 || v2->mViewResult[gMainCullIndex] <= 1u )
  {
    v5 = UFG::SectionChooser::GetViewerPosition();
    v6 = v1->mpInterestPoint;
    v7 = (float)((float)((float)(v5->y - v1->mZoneCentre.y) * (float)(v5->y - v1->mZoneCentre.y))
               + (float)((float)(v5->x - v1->mZoneCentre.x) * (float)(v5->x - v1->mZoneCentre.x)))
       + (float)((float)(v5->z - v1->mZoneCentre.z) * (float)(v5->z - v1->mZoneCentre.z));
    v1->mDistSquareToCamera = v7;
    if ( v6 )
    {
      v8 = UFG::InterestPoint::GetSpawnAmbientUserDistance(v6);
      v9 = v1->mDistSquareToCamera;
      if ( v9 >= (float)(v8 * v8) )
        return v3;
      v10 = v9 < 36.0;
      v11 = v9 == 36.0;
    }
    else
    {
      if ( v7 >= (float)(UFG::PedSpawnManager::msZoneActivateDist * UFG::PedSpawnManager::msZoneActivateDist) )
        return v3;
      v10 = UFG::PedSpawnManager::msElapsedTotal < v1->mRetryTime;
      v11 = UFG::PedSpawnManager::msElapsedTotal == v1->mRetryTime;
    }
    if ( !v10 && !v11 )
      v3 = 1;
    return v3;
  }
  if ( UFG::PedSpawnManager::msPedInfoForLocalZoneChecks
    && (float)((float)((float)((float)(v1->mZoneCentre.y
                                     - UFG::PedSpawnManager::msPedInfoForLocalZoneChecks->mCurrentLocation.y)
                             * (float)(v1->mZoneCentre.y
                                     - UFG::PedSpawnManager::msPedInfoForLocalZoneChecks->mCurrentLocation.y))
                     + (float)((float)(v1->mZoneCentre.x
                                     - UFG::PedSpawnManager::msPedInfoForLocalZoneChecks->mCurrentLocation.x)
                             * (float)(v1->mZoneCentre.x
                                     - UFG::PedSpawnManager::msPedInfoForLocalZoneChecks->mCurrentLocation.x)))
             + (float)((float)(v1->mZoneCentre.z - UFG::PedSpawnManager::msPedInfoForLocalZoneChecks->mCurrentLocation.z)
                     * (float)(v1->mZoneCentre.z - UFG::PedSpawnManager::msPedInfoForLocalZoneChecks->mCurrentLocation.z))) < 9.0 )
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
  UFG::SpawnZone *v1; // rbx
  UFG::qVector3 *v2; // rax
  float v3; // xmm2_4
  float v4; // xmm0_4
  bool result; // al

  v1 = this;
  if ( !this->mCullResults )
    return 0;
  v2 = UFG::SectionChooser::GetViewerPosition();
  v3 = (float)((float)((float)(v2->y - v1->mZoneCentre.y) * (float)(v2->y - v1->mZoneCentre.y))
             + (float)((float)(v2->x - v1->mZoneCentre.x) * (float)(v2->x - v1->mZoneCentre.x)))
     + (float)((float)(v2->z - v1->mZoneCentre.z) * (float)(v2->z - v1->mZoneCentre.z));
  if ( gMainCullIndex < 0 || v1->mCullResults->mViewResult[gMainCullIndex] <= 1u )
  {
    result = 1;
    if ( v3 > (float)((float)(UFG::PedSpawnManager::msZoneActivateDist * 1.2)
                    * (float)(UFG::PedSpawnManager::msZoneActivateDist * 1.2)) )
      return result;
    return 0;
  }
  v4 = (float)(UFG::PedSpawnManager::msZoneActivateDist * 0.80000001)
     * (float)(UFG::PedSpawnManager::msZoneActivateDist * 0.80000001);
  if ( v3 > v4 )
    return 1;
  if ( v3 <= (float)(v4 * 0.5) || !v1->mSpawnCount )
    return 0;
  result = 0;
  if ( !v1->mAliveCount )
    result = 1;
  return result;
}

// File Line: 1186
// RVA: 0x40DE90
char __fastcall UFG::SpawnZone::IsValidForTopUpSpawning(UFG::SpawnZone *this)
{
  char v1; // di
  UFG::SpawnZone *v2; // rbx
  UFG::qVector3 *v4; // rax
  float v5; // xmm2_4
  CullInfo *v6; // rax
  float v7; // xmm1_4
  float v8; // xmm2_4
  UFG::qMatrix44 *v9; // rcx
  float v10; // xmm1_4
  float v11; // xmm2_4
  UFG::qMatrix44 *v12; // rax
  UFG::qVector4 v13; // xmm2
  UFG::qVector4 v14; // xmm1
  UFG::qVector4 v15; // xmm0
  NISManager *v16; // rax
  UFG::qVector3 min; // [rsp+20h] [rbp-29h]
  UFG::qVector3 max; // [rsp+30h] [rbp-19h]
  UFG::qBox box; // [rsp+40h] [rbp-9h]
  UFG::qMatrix44 m; // [rsp+60h] [rbp+17h]

  v1 = 0;
  v2 = this;
  if ( this->mIsThugZone )
    return 0;
  if ( (float)(UFG::PedSpawnManager::msElapsedTotal - this->mTimeStamp) > 4.0 && this->mCullResults )
  {
    v4 = UFG::SectionChooser::GetViewerPosition();
    v5 = (float)((float)((float)(v4->y - v2->mZoneCentre.y) * (float)(v4->y - v2->mZoneCentre.y))
               + (float)((float)(v4->x - v2->mZoneCentre.x) * (float)(v4->x - v2->mZoneCentre.x)))
       + (float)((float)(v4->z - v2->mZoneCentre.z) * (float)(v4->z - v2->mZoneCentre.z));
    if ( gMainCullIndex < 0 || v2->mCullResults->mViewResult[gMainCullIndex] <= 1u )
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
      v1 = 0;
      if ( v5 > 100.0 )
        v1 = 1;
    }
  }
  if ( NISManager::GetInstance()->mSpatialDataHandle.mData )
  {
    if ( v1 == 1 )
    {
      if ( v2->mpRegion )
      {
        v6 = v2->mCullInfo;
        if ( v6 )
        {
          v7 = v6->mAABBMin[1];
          v8 = v6->mAABBMin[2];
          v9 = &UFG::qMatrix44::msIdentity;
          min.x = v6->mAABBMin[0];
          min.y = v7;
          min.z = v8;
          v10 = v6->mAABBMax[1];
          v11 = v6->mAABBMax[2];
          max.x = v6->mAABBMax[0];
          max.y = v10;
          max.z = v11;
          v12 = (UFG::qMatrix44 *)v6->mpLocalWorld;
          if ( v12 )
            v9 = v12;
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
          v16 = NISManager::GetInstance();
          if ( NISManager::IntersectsSpatialBoundingBox(v16, &box) )
            v1 = 0;
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
  return atexit(dynamic_atexit_destructor_for__UFG::PedSpawningInfo::smDrawList__);
}

// File Line: 1265
// RVA: 0x14EA8E0
__int64 dynamic_initializer_for__UFG::PedSpawningInfo::smNoDrawList__()
{
  return atexit(dynamic_atexit_destructor_for__UFG::PedSpawningInfo::smNoDrawList__);
}

// File Line: 1267
// RVA: 0x14EA8A0
__int64 dynamic_initializer_for__UFG::PedSpawningInfo::s_PedSpawningInfoList__()
{
  return atexit(dynamic_atexit_destructor_for__UFG::PedSpawningInfo::s_PedSpawningInfoList__);
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
  UFG::PedSpawningInfo *v1; // rbx
  UFG::qNode<UFG::PedSpawningInfo,UFG::PedInfoList> *v2; // rax
  UFG::qNode<UFG::PedSpawningInfo,UFG::PedSpawningInfo_DrawList> *v3; // rsi
  UFG::qNode<UFG::PedSpawningInfo,UFG::PedSpawningInfo> *v4; // rdi
  signed int v5; // ecx
  UFG::qColour **v6; // rax
  UFG::qNode<UFG::PedSpawningInfo,UFG::PedSpawningInfo> *v7; // rax
  UFG::qNode<UFG::PedSpawningInfo,UFG::PedSpawningInfo_DrawList> *v8; // rax
  UFG::qSafePointer<UFG::SpawnZone,UFG::SpawnZone> *v9; // [rsp+68h] [rbp+10h]
  UFG::qSafePointerWithCallbacks<UFG::SimObject,UFG::SimObjectCharacter> *v10; // [rsp+68h] [rbp+10h]
  UFG::qSafePointer<UFG::SimComponent,UFG::InterestPoint> *v11; // [rsp+68h] [rbp+10h]

  v1 = this;
  UFG::SimComponent::SimComponent((UFG::SimComponent *)&this->vfptr, 0xFFFFFFFF);
  v2 = (UFG::qNode<UFG::PedSpawningInfo,UFG::PedInfoList> *)&v1->mPrev;
  v2->mPrev = v2;
  v2->mNext = v2;
  v3 = (UFG::qNode<UFG::PedSpawningInfo,UFG::PedSpawningInfo_DrawList> *)&v1->mPrev;
  v3->mPrev = v3;
  v3->mNext = v3;
  v4 = (UFG::qNode<UFG::PedSpawningInfo,UFG::PedSpawningInfo> *)&v1->mPrev;
  v4->mPrev = v4;
  v4->mNext = v4;
  v1->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::PedSpawningInfo::`vftable';
  *(_QWORD *)&v1->mSuspendedTime = 0i64;
  v1->mPrevCulledTime = 0.0;
  v9 = &v1->mCreationSpawnZone;
  v9->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SpawnZone>,UFG::qSafePointerNodeList> *)&v9->mPrev;
  v9->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SpawnZone>,UFG::qSafePointerNodeList> *)&v9->mPrev;
  v1->mCreationSpawnZone.m_pPointer = 0i64;
  *(_QWORD *)&v1->mActiveStatus = 0i64;
  v10 = &v1->mSimObjectPtr;
  v10->mPrev = (UFG::qNode<UFG::qSafePointerWithCallbacksBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v10->mPrev;
  v10->mNext = (UFG::qNode<UFG::qSafePointerWithCallbacksBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v10->mPrev;
  v1->mSimObjectPtr.m_BindCallback.m_Closure.m_pthis = 0i64;
  v1->mSimObjectPtr.m_BindCallback.m_Closure.m_pFunction = 0i64;
  v1->mSimObjectPtr.m_UnbindCallback.m_Closure.m_pthis = 0i64;
  v1->mSimObjectPtr.m_UnbindCallback.m_Closure.m_pFunction = 0i64;
  v1->mSimObjectPtr.m_pPointer = 0i64;
  v1->mSimObjectPtr.m_Changed = 0;
  UFG::RebindingComponentHandle<UFG::CharacterOccupantComponent,0>::RebindingComponentHandle<UFG::CharacterOccupantComponent,0>(&v1->mCharacterOccupantComponent);
  v1->mIsDead = 0;
  v1->mLifetimeInstanceNameSymbol.mUID = -1;
  v5 = 15;
  v6 = &v1->mTrueCrowdSignature.mPart[0].mColourTint;
  do
  {
    *(v6 - 1) = 0i64;
    *v6 = 0i64;
    v6 += 2;
    --v5;
  }
  while ( v5 >= 0 );
  v1->mTrueCrowdSignature.mSet = 0i64;
  v1->mTrueCrowdSignature.mNumParts = 0;
  v1->mRigNameSymbol = UFG::gNullQSymbolUC;
  v1->mPropSetSymbol = UFG::gNullQSymbol;
  v1->mArchetypePropSetSymbol = UFG::gNullQSymbol;
  v1->mFactionSymbol.mUID = -1;
  `eh vector constructor iterator'(v1->mAttachedPropNames, 4ui64, 4, (void (__fastcall *)(void *))BackInfo::BackInfo);
  v1->mCanSuspendScripted = 1;
  v11 = &v1->mUpgradePOI;
  v11->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v11->mPrev;
  v11->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v11->mPrev;
  v1->mUpgradePOI.m_pPointer = 0i64;
  v1->mCullInfo = 0i64;
  v1->mCullResults = 0i64;
  v7 = UFG::PedSpawningInfo::s_PedSpawningInfoList.mNode.mPrev;
  UFG::PedSpawningInfo::s_PedSpawningInfoList.mNode.mPrev->mNext = v4;
  v4->mPrev = v7;
  v1->mNext = (UFG::qNode<UFG::PedSpawningInfo,UFG::PedSpawningInfo> *)&UFG::PedSpawningInfo::s_PedSpawningInfoList;
  UFG::PedSpawningInfo::s_PedSpawningInfoList.mNode.mPrev = (UFG::qNode<UFG::PedSpawningInfo,UFG::PedSpawningInfo> *)&v1->mPrev;
  UFG::SimComponent::AddType(
    (UFG::SimComponent *)&v1->vfptr,
    UFG::PedSpawningInfo::_PedSpawningInfoTypeUID,
    "PedSpawningInfo");
  v8 = UFG::PedSpawningInfo::smDrawList.mNode.mPrev;
  UFG::PedSpawningInfo::smDrawList.mNode.mPrev->mNext = v3;
  v3->mPrev = v8;
  v1->mNext = (UFG::qNode<UFG::PedSpawningInfo,UFG::PedSpawningInfo_DrawList> *)&UFG::PedSpawningInfo::smDrawList;
  UFG::PedSpawningInfo::smDrawList.mNode.mPrev = (UFG::qNode<UFG::PedSpawningInfo,UFG::PedSpawningInfo_DrawList> *)&v1->mPrev;
  v1->m_Flags &= 0xFFF7u;
}

// File Line: 1284
// RVA: 0x405EC0
void __fastcall UFG::PedSpawningInfo::~PedSpawningInfo(UFG::PedSpawningInfo *this)
{
  UFG::PedSpawningInfo *v1; // rbx
  UFG::qNode<UFG::PedSpawningInfo,UFG::PedSpawningInfo> *v2; // rdi
  UFG::qNode<UFG::PedSpawningInfo,UFG::PedSpawningInfo> *v3; // rcx
  UFG::qNode<UFG::PedSpawningInfo,UFG::PedSpawningInfo> *v4; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::InterestPoint> *v5; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v7; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qSafePointer<UFG::SpawnZone,UFG::SpawnZone> *v10; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SpawnZone>,UFG::qSafePointerNodeList> *v11; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SpawnZone>,UFG::qSafePointerNodeList> *v12; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SpawnZone>,UFG::qSafePointerNodeList> *v13; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SpawnZone>,UFG::qSafePointerNodeList> *v14; // rax
  UFG::qNode<UFG::PedSpawningInfo,UFG::PedSpawningInfo> *v15; // rcx
  UFG::qNode<UFG::PedSpawningInfo,UFG::PedSpawningInfo> *v16; // rax
  UFG::qNode<UFG::PedSpawningInfo,UFG::PedSpawningInfo_DrawList> *v17; // rdx
  UFG::qNode<UFG::PedSpawningInfo,UFG::PedSpawningInfo_DrawList> *v18; // rcx
  UFG::qNode<UFG::PedSpawningInfo,UFG::PedSpawningInfo_DrawList> *v19; // rax
  UFG::qNode<UFG::PedSpawningInfo,UFG::PedInfoList> *v20; // rdx
  UFG::qNode<UFG::PedSpawningInfo,UFG::PedInfoList> *v21; // rcx
  UFG::qNode<UFG::PedSpawningInfo,UFG::PedInfoList> *v22; // rax

  v1 = this;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::PedSpawningInfo::`vftable';
  if ( this == UFG::PedSpawningInfo::s_PedSpawningInfopCurrentIterator )
    UFG::PedSpawningInfo::s_PedSpawningInfopCurrentIterator = (UFG::PedSpawningInfo *)&this->mPrev[-6];
  v2 = (UFG::qNode<UFG::PedSpawningInfo,UFG::PedSpawningInfo> *)&this->mPrev;
  v3 = this->mPrev;
  v4 = v2->mNext;
  v3->mNext = v4;
  v4->mPrev = v3;
  v2->mPrev = v2;
  v2->mNext = v2;
  v5 = &v1->mUpgradePOI;
  if ( v1->mUpgradePOI.m_pPointer )
  {
    v6 = v5->mPrev;
    v7 = v1->mUpgradePOI.mNext;
    v6->mNext = v7;
    v7->mPrev = v6;
    v5->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v5->mPrev;
    v1->mUpgradePOI.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->mUpgradePOI.mPrev;
  }
  v1->mUpgradePOI.m_pPointer = 0i64;
  v8 = v5->mPrev;
  v9 = v1->mUpgradePOI.mNext;
  v8->mNext = v9;
  v9->mPrev = v8;
  v5->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v5->mPrev;
  v1->mUpgradePOI.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->mUpgradePOI.mPrev;
  `eh vector destructor iterator'(v1->mAttachedPropNames, 4ui64, 4, (void (__fastcall *)(void *))_);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&v1->mCharacterOccupantComponent);
  UFG::qSafePointerWithCallbacksBase<UFG::SimObject>::~qSafePointerWithCallbacksBase<UFG::SimObject>((UFG::qSafePointerWithCallbacksBase<UFG::SimObject> *)&v1->mSimObjectPtr.mPrev);
  v10 = &v1->mCreationSpawnZone;
  if ( v1->mCreationSpawnZone.m_pPointer )
  {
    v11 = v10->mPrev;
    v12 = v1->mCreationSpawnZone.mNext;
    v11->mNext = v12;
    v12->mPrev = v11;
    v10->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SpawnZone>,UFG::qSafePointerNodeList> *)&v10->mPrev;
    v1->mCreationSpawnZone.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SpawnZone>,UFG::qSafePointerNodeList> *)&v1->mCreationSpawnZone.mPrev;
  }
  v1->mCreationSpawnZone.m_pPointer = 0i64;
  v13 = v10->mPrev;
  v14 = v1->mCreationSpawnZone.mNext;
  v13->mNext = v14;
  v14->mPrev = v13;
  v10->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SpawnZone>,UFG::qSafePointerNodeList> *)&v10->mPrev;
  v1->mCreationSpawnZone.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SpawnZone>,UFG::qSafePointerNodeList> *)&v1->mCreationSpawnZone.mPrev;
  v15 = v2->mPrev;
  v16 = v2->mNext;
  v15->mNext = v16;
  v16->mPrev = v15;
  v2->mPrev = v2;
  v2->mNext = v2;
  v17 = (UFG::qNode<UFG::PedSpawningInfo,UFG::PedSpawningInfo_DrawList> *)&v1->mPrev;
  v18 = v1->mPrev;
  v19 = v1->mNext;
  v18->mNext = v19;
  v19->mPrev = v18;
  v17->mPrev = v17;
  v17->mNext = v17;
  v20 = (UFG::qNode<UFG::PedSpawningInfo,UFG::PedInfoList> *)&v1->mPrev;
  v21 = v1->mPrev;
  v22 = v1->mNext;
  v21->mNext = v22;
  v22->mPrev = v21;
  v20->mPrev = v20;
  v20->mNext = v20;
  UFG::SimComponent::~SimComponent((UFG::SimComponent *)&v1->vfptr);
}

// File Line: 1317
// RVA: 0x4076B0
void __fastcall UFG::PedSpawningInfo::AllocatePersistentCullInfo(UFG::PedSpawningInfo *this)
{
  CullResults **v1; // rdi
  CullInfo **v2; // rbx
  CullManager *v3; // rax
  CullInfo *v4; // rax
  CullInfo *v5; // rax

  v1 = &this->mCullResults;
  if ( !this->mCullResults )
  {
    v2 = &this->mCullInfo;
    v3 = CullManager::Instance();
    CullManager::AllocPersistentCullInfo(v3, v1, v2, 0i64, 0i64, 0i64);
    (*v2)->mViewsCulled = ~(1 << gMainCullIndex);
    (*v2)->mPixelScaleBias = 3;
    v4 = *v2;
    v4->mAABBMin[0] = minOffset.x;
    v4->mAABBMin[1] = minOffset.y;
    v4->mAABBMin[2] = minOffset.z;
    v5 = *v2;
    v5->mAABBMax[0] = maxOffset.x;
    v5->mAABBMax[1] = maxOffset.y;
    v5->mAABBMax[2] = maxOffset.z;
    (*v1)->mViewResult[0] = 2;
  }
}

// File Line: 1339
// RVA: 0x4187D0
void __fastcall UFG::PedSpawningInfo::UpdatePersistentCullInfo(UFG::PedSpawningInfo *this)
{
  UFG::PedSpawningInfo::eActiveStatus v1; // eax
  UFG::PedSpawningInfo *v2; // rbx
  UFG::TransformNodeComponent *v3; // rdi

  v1 = this->mActiveStatus;
  v2 = this;
  if ( (signed int)v1 >= 2 )
  {
    v3 = this->mTransformNodePtr;
    if ( !v3 || v1 == 2 )
      v3 = this->mProxyTransformNode;
    UFG::TransformNodeComponent::UpdateWorldTransform(v3);
    v2->mCullInfo->mpLocalWorld = &v3->mWorldTransform.v0.x;
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
  Render::View *v2; // rsi
  UFG::PedSpawningInfo *v3; // rbx
  UFG::TransformNodeComponent *v4; // rdi
  unsigned int v5; // eax
  CullResults *v6; // rcx
  int *v7; // rdx
  Render::ViewSettings *v8; // rdx
  __int64 v9; // rax
  __int64 v10; // rax
  int v11; // xmm0_4
  Illusion::SubmitContext *v12; // rax
  float v13; // [rsp+30h] [rbp+8h]
  int v14; // [rsp+34h] [rbp+Ch]

  v2 = view;
  v3 = this;
  if ( this->mCulledTime == 0.0 && (this->mPrevCulledTime <= 0.0 || this->mLocationClassification) )
  {
    v4 = this->mTransformNodePtr;
    if ( !v4 || this->mActiveStatus == 2 )
      v4 = this->mProxyTransformNode;
    v5 = this->mProxyOverDrawFrames;
    if ( v5 )
      this->mProxyOverDrawFrames = v5 - 1;
    if ( v4 )
    {
      v6 = this->mCullResults;
      v7 = 0i64;
      if ( v6 )
      {
        v8 = v2->mSettings;
        v9 = v2->mSettings->mCullIndex;
        if ( (signed int)v9 >= 6 )
          v13 = 0.0;
        else
          v13 = v6->mDistance[v9];
        v10 = v8->mCullIndex;
        if ( (signed int)v10 >= 6 )
          v11 = (signed int)FLOAT_1_0;
        else
          v11 = LODWORD(v6->mPixelCoverage[v10]);
        v14 = v11;
        v7 = (int *)&v13;
      }
      v12 = v2->mSubmitContext;
      v12[1].vfptr = (Illusion::SubmitContextVtbl *)v7;
      v12[1].mStateValues.mSetValueMask.mFlags[0] = 0i64;
      UFG::TransformNodeComponent::UpdateWorldTransform(v4);
      SubmitRenderModel(
        v2,
        *((Illusion::Model **)&UFG::PedSpawnManager::msLowLODHandles.mData + 4 * v3->mProxyModelHandleIndex),
        &v4->mWorldTransform);
    }
  }
}

// File Line: 1458
// RVA: 0x40AE20
void __fastcall UFG::PedSpawningInfo::DrawAll(Render::View *view)
{
  Render::View *v1; // rsi
  char *v2; // rbx
  UFG::qColour *v3; // r8
  Illusion::StateValues *v4; // rax
  UFG::qNode<UFG::PedSpawningInfo,UFG::PedSpawningInfo_DrawList> *v5; // rcx
  UFG::qList<UFG::PedSpawningInfo,UFG::PedSpawningInfo_DrawList,1,0> *v6; // rbx
  UFG::qNode<UFG::PedSpawningInfo,UFG::PedSpawningInfo_DrawList> *v7; // rcx
  UFG::qList<UFG::PedSpawningInfo,UFG::PedSpawningInfo_DrawList,1,0> *v8; // rbx

  v1 = view;
  v2 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x40u, 0x10u);
  v3 = &UFG::proxyColours[UFG::g_ped_colour_index];
  *(float *)v2 = v3->r;
  *((_DWORD *)v2 + 1) = LODWORD(v3->g);
  *((_DWORD *)v2 + 2) = LODWORD(v3->b);
  *((_DWORD *)v2 + 3) = LODWORD(v3->a);
  v4 = Render::View::GetStateValues(v1);
  v4->mSetValueMask.mFlags[0] |= 0x400000000ui64;
  v4->mParamValues[34] = v2;
  v5 = UFG::PedSpawningInfo::smDrawList.mNode.mNext - 5;
  if ( (UFG::qList<UFG::PedSpawningInfo,UFG::PedSpawningInfo_DrawList,1,0> *)&UFG::PedSpawningInfo::smDrawList.mNode.mNext[-5] != &UFG::PedSpawningInfo::smDrawList - 5 )
  {
    do
    {
      v6 = (UFG::qList<UFG::PedSpawningInfo,UFG::PedSpawningInfo_DrawList,1,0> *)&v5[5].mNext[-5];
      if ( LODWORD(v5[10].mNext) == 2 || LODWORD(v5[17].mPrev) )
        UFG::PedSpawningInfo::Draw((UFG::PedSpawningInfo *)v5, v1);
      v5 = &v6->mNode;
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
          UFG::PedSpawningInfo::Draw((UFG::PedSpawningInfo *)v7, v1);
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
  UFG::PedSpawningInfo *v2; // rbx
  CullResults *v3; // rdi
  CullManager *v4; // rax

  v2 = this;
  UFG::PedSpawningInfo::MakeCompletelyInactive(this);
  v3 = v2->mCullResults;
  if ( v3 )
  {
    v4 = CullManager::Instance();
    CullManager::FreePersistentCullInfo(v4, v3, v2->mCullInfo);
    v2->mCullResults = 0i64;
    v2->mCullInfo = 0i64;
  }
  v2->mTransformNodePtr = 0i64;
}

// File Line: 1655
// RVA: 0x407FD0
void __fastcall UFG::PedSpawningInfo::AttachGroupComponent(UFG::PedSpawningInfo *this, bool ownsAIEntity)
{
  bool v2; // di
  UFG::PedSpawningInfo *v3; // rbx
  UFG::SimObject *v4; // rdx
  UFG::SimObject *v5; // rax
  UFG::AIEntityComponent *v6; // rcx
  UFG::SimObjectModifier v7; // [rsp+28h] [rbp-30h]

  v2 = ownsAIEntity;
  v3 = this;
  if ( this->mGroupComponent )
  {
    v4 = this->mProxySimObjectPtr;
    if ( v4 )
    {
      UFG::SimObjectModifier::SimObjectModifier(&v7, v4, 1);
      UFG::SimObjectModifier::AttachComponent(&v7, (UFG::SimComponent *)&v3->mGroupComponent->vfptr, 0xFFFFFFFFi64);
      UFG::SimObjectModifier::Close(&v7);
      UFG::SimObjectModifier::~SimObjectModifier(&v7);
    }
    UFG::GroupComponent::SetOwner(v3->mGroupComponent, v3);
  }
  if ( v2 )
  {
    v5 = v3->mSimObjectPtr.m_pPointer;
    if ( v5 )
    {
      v6 = (UFG::AIEntityComponent *)v5->m_Components.p[22].m_pComponent;
      if ( v6 )
        UFG::AIEntityComponent::SetGroupComponent(v6, v3->mGroupComponent);
    }
  }
}

// File Line: 1676
// RVA: 0x40AC20
void __fastcall UFG::PedSpawningInfo::DetachGroupComponent(UFG::PedSpawningInfo *this)
{
  UFG::PedSpawningInfo *v1; // rbx
  UFG::SimObject *v2; // rdx
  UFG::GroupComponent *v3; // rdx
  UFG::SimObject *v4; // rax
  UFG::SimComponent *v5; // rdx
  UFG::qList<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase,0,0> *v6; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v7; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v8; // rax
  UFG::SimObjectModifier v9; // [rsp+28h] [rbp-30h]

  v1 = this;
  if ( this->mGroupComponent )
  {
    v2 = this->mProxySimObjectPtr;
    if ( v2 )
    {
      UFG::SimObjectModifier::SimObjectModifier(&v9, v2, 1);
      v3 = v1->mGroupComponent;
      ArrayOfTuplesImplementation::clear((ArrayOfTuplesImplementation *)&v9);
      UFG::SimObjectModifier::Close(&v9);
      UFG::SimObjectModifier::~SimObjectModifier(&v9);
    }
    UFG::GroupComponent::SetOwner(v1->mGroupComponent, 0i64);
  }
  v4 = v1->mSimObjectPtr.m_pPointer;
  if ( v4 )
  {
    v5 = v4->m_Components.p[22].m_pComponent;
    if ( v5 )
    {
      if ( v5[15].vfptr == (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)v1->mGroupComponent )
      {
        v6 = &v5[14].m_BoundComponentHandles;
        if ( v6[1].mNode.mPrev )
        {
          v7 = v6->mNode.mPrev;
          v8 = v6->mNode.mNext;
          v7->mNext = v8;
          v8->mPrev = v7;
          v6->mNode.mPrev = &v6->mNode;
          v6->mNode.mNext = &v6->mNode;
        }
        v6[1].mNode.mPrev = 0i64;
      }
    }
  }
}

// File Line: 1700
// RVA: 0x417BA0
void __fastcall UFG::PedSpawningInfo::SwapGroupComponent(UFG::PedSpawningInfo *this, UFG::PedSpawningInfo *other)
{
  UFG::PedSpawningInfo *v2; // rbx
  UFG::PedSpawningInfo *v3; // rdi
  UFG::GroupComponent *v4; // r8

  if ( this != other )
  {
    v2 = other;
    v3 = this;
    UFG::PedSpawningInfo::DetachGroupComponent(this);
    UFG::PedSpawningInfo::DetachGroupComponent(v2);
    v4 = v3->mGroupComponent;
    v3->mGroupComponent = v2->mGroupComponent;
    v2->mGroupComponent = v4;
    UFG::PedSpawningInfo::AttachGroupComponent(v3, 1);
    UFG::PedSpawningInfo::AttachGroupComponent(v2, v2->mSimObjectPtr.m_pPointer != v3->mSimObjectPtr.m_pPointer);
  }
}

// File Line: 1723
// RVA: 0x416920
void __fastcall UFG::PedSpawningInfo::SetSimObjectPtr(UFG::PedSpawningInfo *this, UFG::SimObjectCharacter *simObj)
{
  UFG::SimObject *v2; // rax
  UFG::SimObjectCharacter *v3; // rdi
  UFG::PedSpawningInfo *v4; // rbx
  UFG::SimComponent *v5; // rdx
  UFG::qList<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase,0,0> *v6; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v7; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v8; // rax
  UFG::SimObject *v9; // rax
  UFG::SimComponent *v10; // rdx
  UFG::GroupComponent *v11; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::GroupComponent>,UFG::qSafePointerNodeList> *v12; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::GroupComponent>,UFG::qSafePointerNodeList> *v13; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::GroupComponent>,UFG::qSafePointerNodeList> *v14; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::GroupComponent>,UFG::qSafePointerNodeList> *v15; // rax
  UFG::qSafePointerWithCallbacks<UFG::SimObject,UFG::SimObjectCharacter> *v16; // rdx
  UFG::qNode<UFG::qSafePointerWithCallbacksBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v17; // rcx
  UFG::qNode<UFG::qSafePointerWithCallbacksBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v18; // rax

  v2 = this->mSimObjectPtr.m_pPointer;
  v3 = simObj;
  v4 = this;
  if ( v2 )
  {
    v5 = v2->m_Components.p[22].m_pComponent;
    if ( v5 )
    {
      if ( v5[15].vfptr == (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)this->mGroupComponent )
      {
        v6 = &v5[14].m_BoundComponentHandles;
        if ( v6[1].mNode.mPrev )
        {
          v7 = v6->mNode.mPrev;
          v8 = v6->mNode.mNext;
          v7->mNext = v8;
          v8->mPrev = v7;
          v6->mNode.mPrev = &v6->mNode;
          v6->mNode.mNext = &v6->mNode;
        }
        v6[1].mNode.mPrev = 0i64;
      }
    }
  }
  if ( v3 )
  {
    UFG::qSafePointerWithCallbacks<UFG::SimObject,UFG::SimObjectVehicle>::Set(
      (UFG::qSafePointerWithCallbacks<UFG::EncounterBase,UFG::EncounterBase> *)&v4->mSimObjectPtr,
      (UFG::EncounterBase *)v3);
    v4->mTransformNodePtr = (UFG::TransformNodeComponent *)v3->m_Components.p[2].m_pComponent;
    UFG::RebindingComponentHandle<UFG::CharacterOccupantComponent,0>::Bind<UFG::SimObjectCharacter>(
      &v4->mCharacterOccupantComponent,
      v3);
    v9 = v4->mSimObjectPtr.m_pPointer;
    if ( v9 )
    {
      v10 = v9->m_Components.p[22].m_pComponent;
      if ( v10 )
      {
        v11 = v4->mGroupComponent;
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
        v12[1].mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::GroupComponent>,UFG::qSafePointerNodeList> *)v11;
        if ( v11 )
        {
          v15 = v11->m_SafePointerList.mNode.mPrev;
          v15->mNext = v12;
          v12->mPrev = v15;
          v12->mNext = &v11->m_SafePointerList.mNode;
          v11->m_SafePointerList.mNode.mPrev = v12;
        }
      }
    }
  }
  else
  {
    v16 = &v4->mSimObjectPtr;
    if ( v4->mSimObjectPtr.m_pPointer )
    {
      v17 = v16->mPrev;
      v18 = v4->mSimObjectPtr.mNext;
      v17->mNext = v18;
      v18->mPrev = v17;
      v16->mPrev = (UFG::qNode<UFG::qSafePointerWithCallbacksBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v16->mPrev;
      v4->mSimObjectPtr.mNext = (UFG::qNode<UFG::qSafePointerWithCallbacksBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v4->mSimObjectPtr.mPrev;
      v4->mSimObjectPtr.m_Changed = 1;
    }
    v4->mSimObjectPtr.m_pPointer = 0i64;
    v4->mTransformNodePtr = 0i64;
    UFG::RebindingComponentHandleBase::Unbind((UFG::RebindingComponentHandleBase *)&v4->mCharacterOccupantComponent.mPrev);
  }
}eBase::Unbind((UFG::RebindingComponentHandleBase *)&v4->mCharacterOccupantComponent.mPrev

// File Line: 1770
// RVA: 0x40DD80
char __fastcall UFG::PedSpawningInfo::IsUsingPOI(UFG::PedSpawningInfo *this, UFG::InterestPoint **ppInterestPoint)
{
  UFG::SimObject *v2; // rax
  UFG::InterestPoint **v3; // rbx
  UFG::PedSpawningInfo *v4; // rdi
  UFG::SimComponent *v5; // r8
  __int64 v6; // rax
  signed __int64 v7; // rcx
  UFG::SimObject *v8; // rcx
  unsigned __int16 v9; // dx
  UFG::InterestPoint *v10; // rcx

  v2 = this->mSimObjectPtr.m_pPointer;
  v3 = ppInterestPoint;
  v4 = this;
  if ( !v2 )
    return 0;
  v5 = v2->m_Components.p[20].m_pComponent;
  if ( !v5 )
    return 0;
  v6 = *(_QWORD *)&v5[1].m_TypeUID;
  v7 = 56i64 * *(unsigned __int8 *)(*(_QWORD *)&v5[1].m_Flags + 34i64);
  if ( !*(_QWORD *)(v7 + v6 + 40) )
    return 0;
  if ( !*(_BYTE *)(v7 + v6 + 49) )
    return 0;
  v8 = *(UFG::SimObject **)(v7 + v6 + 40);
  if ( !v8 )
    return 0;
  v9 = v8->m_Flags;
  if ( (v9 >> 14) & 1 )
  {
    v10 = (UFG::InterestPoint *)v8->m_Components.p[25].m_pComponent;
  }
  else if ( (v9 & 0x8000u) == 0 )
  {
    if ( (v9 >> 13) & 1 )
      v10 = (UFG::InterestPoint *)v8->m_Components.p[10].m_pComponent;
    else
      v10 = (UFG::InterestPoint *)((v9 >> 12) & 1 ? v8->m_Components.p[3].m_pComponent : UFG::SimObject::GetComponentOfType(
                                                                                           v8,
                                                                                           UFG::InterestPoint::_TypeUID));
  }
  else
  {
    v10 = (UFG::InterestPoint *)v8->m_Components.p[25].m_pComponent;
  }
  if ( v10->mpUser.m_pPointer != v4->mSimObjectPtr.m_pPointer )
    return 0;
  if ( v3 )
    *v3 = v10;
  return 1;
}

// File Line: 1798
// RVA: 0x418410
void __fastcall UFG::PedSpawningInfo::UpdateDeadStatus(UFG::PedSpawningInfo *this)
{
  UFG::SimObject *v1; // rax
  UFG::SimComponent *v2; // rdx
  UFG::SpawnZone *v3; // rax

  if ( !this->mIsDead )
  {
    v1 = this->mSimObjectPtr.m_pPointer;
    if ( v1 )
    {
      v2 = v1->m_Components.p[6].m_pComponent;
      if ( v2 )
      {
        if ( BYTE4(v2[1].m_BoundComponentHandles.mNode.mPrev) )
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
  UFG::SimObject *v1; // rax
  UFG::SimComponent *v2; // rax
  UFG::SimObjectGame *v3; // rcx
  unsigned __int16 v4; // dx

  if ( !this->mIsDead )
    return 0.0;
  v1 = this->mSimObjectPtr.m_pPointer;
  if ( v1 )
  {
    v2 = v1->m_Components.p[6].m_pComponent;
  }
  else
  {
    v3 = (UFG::SimObjectGame *)this->mProxySimObjectPtr;
    if ( !v3 )
      return 0.0;
    v4 = v3->m_Flags;
    if ( (v4 >> 14) & 1 )
    {
      v2 = v3->m_Components.p[6].m_pComponent;
    }
    else if ( (v4 & 0x8000u) == 0 )
    {
      if ( (v4 >> 13) & 1 )
      {
        v2 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::HealthComponent::_TypeUID);
      }
      else if ( (v4 >> 12) & 1 )
      {
        v2 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::HealthComponent::_TypeUID);
      }
      else
      {
        v2 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::HealthComponent::_TypeUID);
      }
    }
    else
    {
      v2 = v3->m_Components.p[6].m_pComponent;
    }
  }
  if ( v2 )
    return UFG::Metrics::msInstance.mSimTime_Temp - *(float *)&v2[3].m_pSimObject;
  return 0.0;
}

// File Line: 1842
// RVA: 0x416410
void __fastcall UFG::PedSpawningInfo::SetActiveStatus(UFG::PedSpawningInfo *this, UFG::PedSpawningInfo::eActiveStatus newStatus)
{
  __int64 v2; // rdi
  __int64 v3; // rdx
  UFG::PedSpawningInfo *v4; // rbx
  UFG::qNode<UFG::PedSpawningInfo,UFG::PedInfoList> *v5; // rax
  UFG::qNode<UFG::PedSpawningInfo,UFG::PedInfoList> *v6; // r8
  UFG::qNode<UFG::PedSpawningInfo,UFG::PedInfoList> *v7; // r9
  UFG::qList<UFG::PedSpawningInfo,UFG::PedInfoList,1,0> *v8; // rcx
  UFG::qNode<UFG::PedSpawningInfo,UFG::PedInfoList> *v9; // rax
  UFG::qNode<UFG::PedSpawningInfo,UFG::PedInfoList> *v10; // rax
  UFG::qNode<UFG::PedSpawningInfo,UFG::PedInfoList> *v11; // r8
  UFG::qNode<UFG::PedSpawningInfo,UFG::PedInfoList> *v12; // rcx
  UFG::qList<UFG::PedSpawningInfo,UFG::PedInfoList,1,0> *v13; // rcx
  UFG::qNode<UFG::PedSpawningInfo,UFG::PedInfoList> *v14; // rax
  CullResults *v15; // rdi
  CullManager *v16; // rax

  v2 = newStatus;
  v3 = this->mActiveStatus;
  v4 = this;
  if ( (_DWORD)v2 != (_DWORD)v3 )
  {
    if ( this->mPedType == AmbientPed )
    {
      v5 = this->mNext;
      v6 = this->mPrev;
      v7 = (UFG::qNode<UFG::PedSpawningInfo,UFG::PedInfoList> *)&this->mPrev;
      v6->mNext = v5;
      v5->mPrev = v6;
      v7->mPrev = v7;
      v7->mNext = v7;
      --UFG::PedSpawnManager::msAmbientCount[v3];
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
      v10 = this->mNext;
      v11 = (UFG::qNode<UFG::PedSpawningInfo,UFG::PedInfoList> *)&this->mPrev;
      v12 = this->mPrev;
      v12->mNext = v10;
      v10->mPrev = v12;
      v11->mPrev = v11;
      v11->mNext = v11;
      --UFG::PedSpawnManager::msScriptedCount[v3];
      v13 = &UFG::PedSpawnManager::msScriptedList[v2];
      v14 = v13->mNode.mPrev;
      v14->mNext = v11;
      v11->mPrev = v14;
      v11->mNext = &v13->mNode;
      ++UFG::PedSpawnManager::msScriptedCount[v2];
      v13->mNode.mPrev = v11;
    }
    if ( !(_DWORD)v2 )
    {
      if ( v4->mTrueCrowdSignature.mSet )
        UFG::TrueCrowdSet::Instance::RemoveProxyReference(&v4->mTrueCrowdSignature, v4);
      v4->mTrueCrowdSignature.mSet = 0i64;
      v4->mTrueCrowdSignature.mNumParts = 0;
    }
    v4->mActiveStatus = v2;
    if ( (signed int)v2 < ExtraLowPower )
    {
      v15 = v4->mCullResults;
      if ( v15 )
      {
        v16 = CullManager::Instance();
        CullManager::FreePersistentCullInfo(v16, v15, v4->mCullInfo);
        v4->mCullResults = 0i64;
        v4->mCullInfo = 0i64;
      }
    }
    else
    {
      UFG::PedSpawningInfo::AllocatePersistentCullInfo(v4);
      UFG::PedSpawningInfo::UpdatePersistentCullInfo(v4);
    }
  }
}

// File Line: 1926
// RVA: 0x40D610
void __fastcall UFG::PedSpawningInfo::Init(UFG::PedSpawningInfo *this, int index, UFG::ePedType pedType)
{
  UFG::qSafePointerWithCallbacks<UFG::SimObject,UFG::SimObjectCharacter> *v3; // rdi
  UFG::ePedType v4; // esi
  int v5; // ebp
  UFG::PedSpawningInfo *v6; // rbx
  UFG::qNode<UFG::qSafePointerWithCallbacksBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v7; // r9
  UFG::qNode<UFG::qSafePointerWithCallbacksBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v8; // rax
  fastdelegate::detail::GenericClass *v9; // rcx
  UFG::RebindingComponentHandle<UFG::CharacterOccupantComponent,0> *v10; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v11; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v12; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v13; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v14; // rax
  UFG::qSafePointer<UFG::SpawnZone,UFG::SpawnZone> *v15; // rdx
  float v16; // xmm1_4
  float v17; // xmm2_4
  UFG::qNode<UFG::qSafePointerBase<UFG::SpawnZone>,UFG::qSafePointerNodeList> *v18; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SpawnZone>,UFG::qSafePointerNodeList> *v19; // rax
  UFG::qNode<UFG::PedSpawningInfo,UFG::PedInfoList> *v20; // rcx
  UFG::qNode<UFG::PedSpawningInfo,UFG::PedInfoList> *v21; // rax
  UFG::qNode<UFG::PedSpawningInfo,UFG::PedInfoList> *v22; // rax
  hkSeekableStreamReader *v23; // rax
  float v24; // xmm0_4

  v3 = &this->mSimObjectPtr;
  v4 = pedType;
  v5 = index;
  v6 = this;
  if ( this->mSimObjectPtr.m_pPointer )
  {
    v7 = v3->mPrev;
    v8 = this->mSimObjectPtr.mNext;
    v7->mNext = v8;
    v8->mPrev = v7;
    v3->mPrev = (UFG::qNode<UFG::qSafePointerWithCallbacksBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v3->mPrev;
    this->mSimObjectPtr.mNext = (UFG::qNode<UFG::qSafePointerWithCallbacksBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&this->mSimObjectPtr.mPrev;
    this->mSimObjectPtr.m_Changed = 1;
    v9 = this->mSimObjectPtr.m_UnbindCallback.m_Closure.m_pthis;
    if ( v9 || v3->m_UnbindCallback.m_Closure.m_pFunction )
      ((void (__fastcall *)(fastdelegate::detail::GenericClass *, UFG::SimObject *))v3->m_UnbindCallback.m_Closure.m_pFunction)(
        v9,
        v3->m_pPointer);
  }
  v10 = &v6->mCharacterOccupantComponent;
  v3->m_pPointer = 0i64;
  v6->mTransformNodePtr = 0i64;
  if ( v6->mCharacterOccupantComponent.m_pSimComponent )
  {
    v11 = v10->mPrev;
    v12 = v6->mCharacterOccupantComponent.mNext;
    v11->mNext = v12;
    v12->mPrev = v11;
    v6->mCharacterOccupantComponent.m_pSimComponent = 0i64;
LABEL_11:
    v6->mCharacterOccupantComponent.m_pSimObject = 0i64;
    v6->mCharacterOccupantComponent.mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v6->mCharacterOccupantComponent.mPrev;
    v10->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v10->mPrev;
    goto LABEL_12;
  }
  if ( v6->mCharacterOccupantComponent.m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::CharacterOccupantComponent,0> *)v10->mPrev != v10
     || (UFG::RebindingComponentHandle<UFG::CharacterOccupantComponent,0> *)v6->mCharacterOccupantComponent.mNext != &v6->mCharacterOccupantComponent) )
  {
    v13 = v10->mPrev;
    v14 = v6->mCharacterOccupantComponent.mNext;
    v13->mNext = v14;
    v14->mPrev = v13;
    goto LABEL_11;
  }
LABEL_12:
  v6->mCharacterOccupantComponent.m_Changed = 1;
  v6->mCharacterOccupantComponent.m_TypeUID = UFG::CharacterOccupantComponent::_TypeUID;
  v6->mSpawnLocation.x = -10000.0;
  v6->mSpawnLocation.y = -10000.0;
  v6->mSpawnLocation.z = -10000.0;
  v6->mSpawnTime = 0.0;
  v6->mCanSuspendScripted = 1;
  v6->mIsDead = 0;
  v6->mIsNearDeactivatedZones = 0;
  v6->mShouldCheckZoneInAreaTime = 0.0;
  *(_QWORD *)&v6->mSuspendedTime = 0i64;
  v6->mTeleportOnResumeRequired = 1;
  v15 = &v6->mCreationSpawnZone;
  v16 = UFG::qVector3::msZero.y;
  v17 = UFG::qVector3::msZero.z;
  v6->mSuspendedPos.x = UFG::qVector3::msZero.x;
  v6->mSuspendedPos.y = v16;
  v6->mSuspendedPos.z = v17;
  *(_QWORD *)&v6->mRestoreAttempts = 0i64;
  v6->mHowSpawned = 0;
  v6->mPedType = v4;
  v6->mPedIndex = v5;
  v6->mStatusChangedFrame = 0;
  if ( v6->mCreationSpawnZone.m_pPointer )
  {
    v18 = v15->mPrev;
    v19 = v6->mCreationSpawnZone.mNext;
    v18->mNext = v19;
    v19->mPrev = v18;
    v15->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SpawnZone>,UFG::qSafePointerNodeList> *)&v15->mPrev;
    v6->mCreationSpawnZone.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SpawnZone>,UFG::qSafePointerNodeList> *)&v6->mCreationSpawnZone.mPrev;
  }
  v6->mCreationSpawnZone.m_pPointer = 0i64;
  v20 = (UFG::qNode<UFG::PedSpawningInfo,UFG::PedInfoList> *)&v6->mPrev;
  v6->mActiveStatus = 0;
  v6->mLocationClassification = 0;
  if ( v4 == 1 )
  {
    v21 = (UFG::qNode<UFG::PedSpawningInfo,UFG::PedInfoList> *)qword_1423DEF68;
    qword_1423DEF68 = (__int64)&v6->mPrev;
    v6->mNext = v21;
    v20->mPrev = (UFG::qNode<UFG::PedSpawningInfo,UFG::PedInfoList> *)UFG::PedSpawnManager::msAmbientList;
    v21->mPrev = v20;
    ++UFG::PedSpawnManager::msAmbientCount[0];
  }
  else
  {
    v22 = UFG::PedSpawnManager::msScriptedList[0].mNode.mNext;
    UFG::PedSpawnManager::msScriptedList[0].mNode.mNext = (UFG::qNode<UFG::PedSpawningInfo,UFG::PedInfoList> *)&v6->mPrev;
    v6->mNext = v22;
    v20->mPrev = (UFG::qNode<UFG::PedSpawningInfo,UFG::PedInfoList> *)UFG::PedSpawnManager::msScriptedList;
    v22->mPrev = v20;
    ++UFG::PedSpawnManager::msScriptedCount[0];
  }
  v23 = Assembly::GetRCX(v6);
  v6->mSimObjectPtr.m_UnbindCallback.m_Closure.m_pFunction = (void (__fastcall *)(fastdelegate::detail::GenericClass *))UFG::PedSpawningInfo::SimObjectPtrGoingNull;
  v6->mSimObjectPtr.m_UnbindCallback.m_Closure.m_pthis = (fastdelegate::detail::GenericClass *)v23;
  v6->mProxySimObjectPtr = 0i64;
  UFG::PedSpawningInfo::InitProxySimObject(v6, v5);
  *(_QWORD *)&v6->mProxyModelHandleIndex = 0i64;
  v6->mProxyTimeSinceLastFrameUpdate = 0.0;
  v24 = UFG::qRandom(0.30000001, &UFG::qDefaultSeed);
  v6->mProxyOverDrawFrames = 0;
  v6->mDumpResourcePriorityScore = 0.0;
  v6->mProxyIndividualTimeScale = v24 + 0.40000001;
  if ( v6->mTrueCrowdSignature.mSet )
    UFG::TrueCrowdSet::Instance::RemoveProxyReference(&v6->mTrueCrowdSignature, v6);
  v6->mTrueCrowdSignature.mSet = 0i64;
  v6->mTrueCrowdSignature.mNumParts = 0;
  v6->mNumAttachedProps = 0;
  v6->mPropSetSymbol = UFG::gNullQSymbol;
  v6->mFactionSymbol = UFG::gNullQSymbol;
  v6->mRigNameSymbol = UFG::gNullQSymbolUC;
}

// File Line: 2006
// RVA: 0x40D8F0
void __fastcall UFG::PedSpawningInfo::InitProxySimObject(UFG::PedSpawningInfo *this, int index)
{
  UFG::PedSpawningInfo *v2; // rdi
  __int64 v3; // r8
  UFG::qMemoryPool *v4; // rax
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
  UFG::SimComponent *v17; // rax
  UFG::SimComponent *v18; // r14
  UFG::qMemoryPool *v19; // rax
  UFG::allocator::free_link *v20; // rax
  UFG::GroupComponent *v21; // rbx
  unsigned int v22; // eax
  UFG::qVector4 v23; // xmm3
  float v24; // xmm1_4
  float v25; // xmm2_4
  unsigned __int16 v26; // cx
  unsigned int v27; // ebx
  UFG::SimObjectModifier v28; // [rsp+10h] [rbp-61h]
  UFG::qMatrix44 m; // [rsp+38h] [rbp-39h]
  __int64 v30; // [rsp+78h] [rbp+7h]
  UFG::qString result; // [rsp+80h] [rbp+Fh]
  UFG::allocator::free_link *v32; // [rsp+D8h] [rbp+67h]
  UFG::qSymbol v33; // [rsp+E8h] [rbp+77h]

  v30 = -2i64;
  v2 = this;
  if ( !this->mProxySimObjectPtr )
  {
    v3 = (unsigned int)this->mPedIndex;
    if ( this->mPedType != 1 )
      v3 = (unsigned int)(v3 + 1000);
    UFG::qString::FormatEx(&result, "ProxyPed%d", v3);
    v4 = UFG::GetSimulationMemoryPool();
    v5 = UFG::qMemoryPool::Allocate(v4, 0x80ui64, "ProxyPedSimObject", 0i64, 1u);
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
    v2->mProxySimObjectPtr = v8;
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
    v2->mProxyTransformNode = v13;
    v2->mProxyAIComponent = (UFG::AILightWeightComponent *)v18;
    v2->mNetworkComponent = 0i64;
    v2->mGroupComponent = (UFG::GroupComponent *)v20;
    v23 = 0i64;
    v23.x = (float)1;
    m.v0 = v23;
    m.v1 = (UFG::qVector4)_mm_shuffle_ps((__m128)v23, (__m128)v23, 81);
    m.v2 = (UFG::qVector4)_mm_shuffle_ps((__m128)v23, (__m128)v23, 69);
    m.v3 = (UFG::qVector4)_mm_shuffle_ps((__m128)v23, (__m128)v23, 21);
    v24 = v2->mSpawnLocation.y;
    v25 = v2->mSpawnLocation.z;
    m.v3.x = v2->mSpawnLocation.x;
    m.v3.y = v24;
    m.v3.z = v25;
    LODWORD(m.v3.w) = (_DWORD)FLOAT_1_0;
    UFG::TransformNodeComponent::SetWorldTransform(v13, &m);
    v26 = v8->m_Flags;
    if ( (v26 >> 14) & 1 || (v26 & 0x8000u) != 0 || (v26 >> 13) & 1 )
    {
      v27 = 2;
    }
    else
    {
      v27 = -1;
      if ( (v26 >> 12) & 1 )
        v27 = 1;
    }
    UFG::SimObjectModifier::SimObjectModifier(&v28, v8, 1);
    UFG::SimObjectModifier::AttachComponent(&v28, (UFG::SimComponent *)&v13->vfptr, v27);
    UFG::SimObjectModifier::Close(&v28);
    UFG::SimObjectModifier::~SimObjectModifier(&v28);
    UFG::SimObjectModifier::SimObjectModifier(&v28, v8, 1);
    UFG::SimObjectModifier::AttachComponent(&v28, v18, 0xFFFFFFFFi64);
    UFG::SimObjectModifier::Close(&v28);
    UFG::SimObjectModifier::~SimObjectModifier(&v28);
    UFG::PedSpawningInfo::AttachGroupComponent(v2, 1);
    UFG::qString::~qString(&result);
  }
}

// File Line: 2048
// RVA: 0x415820
void __fastcall UFG::PedSpawningInfo::Reset(UFG::PedSpawningInfo *this, bool preserveProxies)
{
  UFG::PedSpawningInfo *v2; // rbx
  UFG::SimObject *v3; // rcx
  bool v4; // si
  UFG::SimObject *v5; // rcx
  UFG::qSafePointer<UFG::SimComponent,UFG::InterestPoint> *v6; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v7; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v8; // rax
  UFG::qSafePointer<UFG::SpawnZone,UFG::SpawnZone> *v9; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SpawnZone>,UFG::qSafePointerNodeList> *v10; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SpawnZone>,UFG::qSafePointerNodeList> *v11; // rax

  v2 = this;
  v3 = this->mSimObjectPtr.m_pPointer;
  v4 = preserveProxies;
  if ( v3 )
  {
    if ( v3->m_pSceneObj->mpParent )
      UFG::SceneObjectProperties::DeactivateDeferred(v3->m_pSceneObj);
    else
      UFG::SimObject::Destroy(v3);
  }
  UFG::PedSpawningInfo::MakeCompletelyInactive(v2);
  v2->mNumAttachedProps = 0;
  if ( v2->mTrueCrowdSignature.mSet )
    UFG::TrueCrowdSet::Instance::RemoveProxyReference(&v2->mTrueCrowdSignature, v2);
  v2->mTrueCrowdSignature.mSet = 0i64;
  v2->mTrueCrowdSignature.mNumParts = 0;
  v2->mRigNameSymbol = UFG::gNullQSymbolUC;
  v2->mFactionSymbol = UFG::gNullQSymbol;
  v2->mLifetimeInstanceNameSymbol = UFG::gNullQSymbol;
  if ( !v4 )
  {
    v5 = v2->mProxySimObjectPtr;
    if ( v5 )
    {
      UFG::SimObject::Destroy(v5);
      v2->mProxySimObjectPtr = 0i64;
    }
    v2->mTransformNodePtr = 0i64;
    v2->mProxyAIComponent = 0i64;
    v2->mGroupComponent = 0i64;
  }
  v6 = &v2->mUpgradePOI;
  *(_QWORD *)&v2->mProxyTimeSinceLastAIUpdate = 0i64;
  if ( v2->mUpgradePOI.m_pPointer )
  {
    v7 = v6->mPrev;
    v8 = v2->mUpgradePOI.mNext;
    v7->mNext = v8;
    v8->mPrev = v7;
    v6->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v6->mPrev;
    v2->mUpgradePOI.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->mUpgradePOI.mPrev;
  }
  v2->mUpgradePOI.m_pPointer = 0i64;
  v9 = &v2->mCreationSpawnZone;
  if ( v2->mCreationSpawnZone.m_pPointer )
  {
    v10 = v9->mPrev;
    v11 = v2->mCreationSpawnZone.mNext;
    v10->mNext = v11;
    v11->mPrev = v10;
    v9->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SpawnZone>,UFG::qSafePointerNodeList> *)&v9->mPrev;
    v2->mCreationSpawnZone.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SpawnZone>,UFG::qSafePointerNodeList> *)&v2->mCreationSpawnZone.mPrev;
  }
  v2->mCreationSpawnZone.m_pPointer = 0i64;
  v2->mIsDead = 0;
  v2->mIsNearDeactivatedZones = 0;
  v2->mShouldCheckZoneInAreaTime = 0.0;
  *(_QWORD *)&v2->mSuspendedTime = 0i64;
  v2->mTeleportOnResumeRequired = 1;
  v2->mStatusChangedFrame = -1;
}

// File Line: 2096
// RVA: 0x40E4E0
void __fastcall UFG::PedSpawningInfo::MakeCompletelyInactive(UFG::PedSpawningInfo *this)
{
  UFG::PedSpawningInfo *v1; // rbx
  UFG::GroupComponent *v2; // rcx
  UFG::InterestPoint *v3; // rcx
  UFG::qSafePointer<UFG::SimComponent,UFG::InterestPoint> *v4; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rax

  v1 = this;
  v2 = this->mGroupComponent;
  if ( v2 )
    UFG::GroupComponent::Reset(v2);
  v3 = (UFG::InterestPoint *)v1->mUpgradePOI.m_pPointer;
  v1->mIsNearDeactivatedZones = 0;
  v1->mShouldCheckZoneInAreaTime = 0.0;
  v1->mNumAttachedProps = 0;
  v1->mBlipActive = 0;
  if ( v3 && v3->mpPedInfoUser == v1 )
    UFG::InterestPoint::SetPedInfoUser(v3, 0i64);
  v4 = &v1->mUpgradePOI;
  if ( v1->mUpgradePOI.m_pPointer )
  {
    v5 = v4->mPrev;
    v6 = v1->mUpgradePOI.mNext;
    v5->mNext = v6;
    v6->mPrev = v5;
    v4->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v4->mPrev;
    v1->mUpgradePOI.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->mUpgradePOI.mPrev;
  }
  v1->mUpgradePOI.m_pPointer = 0i64;
  UFG::PedSpawningInfo::SetActiveStatus(v1, 0);
}

// File Line: 2149
// RVA: 0x4157B0
void __fastcall UFG::PedSpawningInfo::RemoveProps(UFG::PedSpawningInfo *this)
{
  UFG::SimObject *v1; // rax
  UFG::InventoryComponent *v2; // rbx

  v1 = this->mSimObjectPtr.m_pPointer;
  if ( v1 )
  {
    v2 = (UFG::InventoryComponent *)v1->m_Components.p[39].m_pComponent;
    UFG::InventoryComponent::UnEquip(v2, 0, 1);
    UFG::InventoryComponent::UnEquip(v2, eINVENTORY_EQUIP_SLOT_LEFT_HAND, 1);
    UFG::InventoryComponent::UnEquip(v2, eINVENTORY_EQUIP_SLOT_HAT, 1);
    UFG::InventoryComponent::UnEquip(v2, eINVENTORY_EQUIP_SLOT_GLASSES, 1);
  }
}

// File Line: 2193
// RVA: 0x416B70
void __fastcall UFG::PedSpawningInfo::SetTrueCrowdSignature(UFG::PedSpawningInfo *this, UFG::TrueCrowdSet::Instance *tcs)
{
  UFG::TrueCrowdSet::Instance *v2; // rdi
  UFG::TrueCrowdSet::Instance *v3; // rbx
  UFG::PedSpawningInfo *v4; // rsi
  UFG::TrueCrowdSet::Instance *v5; // rdx
  signed __int64 v6; // rax
  UFG::ModelTextureCombination v7; // xmm0

  v2 = &this->mTrueCrowdSignature;
  v3 = tcs;
  v4 = this;
  if ( this->mTrueCrowdSignature.mSet )
    UFG::TrueCrowdSet::Instance::RemoveProxyReference(v2, this);
  v5 = v2;
  if ( ((unsigned __int8)v2 | (unsigned __int8)v3) & 0xF )
  {
    memmove(v2, v3, 0x118ui64);
  }
  else
  {
    v6 = 2i64;
    do
    {
      v7 = *(UFG::ModelTextureCombination *)&v3->mSet;
      v5 = (UFG::TrueCrowdSet::Instance *)((char *)v5 + 128);
      v3 = (UFG::TrueCrowdSet::Instance *)((char *)v3 + 128);
      v5[-1].mPart[8] = v7;
      v5[-1].mPart[9] = v3[-1].mPart[9];
      v5[-1].mPart[10] = v3[-1].mPart[10];
      v5[-1].mPart[11] = v3[-1].mPart[11];
      v5[-1].mPart[12] = v3[-1].mPart[12];
      v5[-1].mPart[13] = v3[-1].mPart[13];
      v5[-1].mPart[14] = v3[-1].mPart[14];
      v5[-1].mPart[15] = v3[-1].mPart[15];
      --v6;
    }
    while ( v6 );
    *(_OWORD *)&v5->mSet = *(_OWORD *)&v3->mSet;
    *(_QWORD *)&v5->mMorphWeights[1] = *(_QWORD *)&v3->mMorphWeights[1];
  }
  UFG::TrueCrowdSet::Instance::AddProxyReference(v2, v4);
}

// File Line: 2203
// RVA: 0x416C40
void __fastcall UFG::PedSpawningInfo::SetTrueCrowdSignatureFromCurrentSimObject(UFG::PedSpawningInfo *this)
{
  UFG::SimObjectCVBase *v1; // rbx
  const char *v2; // rdi
  UFG::PedSpawningInfo *v3; // rsi
  UFG::SimComponent *v4; // rax
  unsigned __int16 v5; // cx
  unsigned __int16 v6; // cx
  UFG::SimComponent *v7; // rax
  UFG::SceneObjectProperties *v8; // rax
  UFG::qPropertySet *v9; // rcx
  UFG::qPropertySet *v10; // rax
  char *v11; // rax
  __int64 v12; // rcx
  unsigned __int16 v13; // cx
  UFG::SimObjectCharacterPropertiesComponent *v14; // rax
  UFG::SimObjectGame *v15; // rcx
  bool v16; // zf
  UFG::eFactionClassEnum v17; // ebx
  UFG::GameStatTracker *v18; // rax
  UFG::qWiseSymbol result; // [rsp+30h] [rbp+8h]

  v1 = (UFG::SimObjectCVBase *)this->mSimObjectPtr.m_pPointer;
  v2 = 0i64;
  v3 = this;
  if ( v1 )
  {
    v5 = v1->m_Flags;
    if ( (v5 >> 14) & 1 )
    {
      v4 = v1->m_Components.p[10].m_pComponent;
    }
    else if ( (v5 & 0x8000u) == 0 )
    {
      if ( (v5 >> 13) & 1 )
      {
        v4 = v1->m_Components.p[7].m_pComponent;
      }
      else if ( (v5 >> 12) & 1 )
      {
        v4 = UFG::SimObjectGame::GetComponentOfTypeHK(
               (UFG::SimObjectGame *)&v1->vfptr,
               UFG::StreamedResourceComponent::_TypeUID);
      }
      else
      {
        v4 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v1->vfptr, UFG::StreamedResourceComponent::_TypeUID);
      }
    }
    else
    {
      v4 = v1->m_Components.p[10].m_pComponent;
    }
  }
  else
  {
    v4 = 0i64;
  }
  UFG::PedSpawningInfo::SetTrueCrowdSignature(v3, (UFG::TrueCrowdSet::Instance *)&v4[4].m_SafePointerList.mNode.mNext);
  if ( v1 )
  {
    v6 = v1->m_Flags;
    if ( (v6 >> 14) & 1 )
    {
      v7 = v1->m_Components.p[9].m_pComponent;
    }
    else if ( (v6 & 0x8000u) == 0 )
    {
      if ( (v6 >> 13) & 1 )
        v7 = v1->m_Components.p[8].m_pComponent;
      else
        v7 = (v6 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                (UFG::SimObjectGame *)&v1->vfptr,
                                UFG::BaseAnimationComponent::_TypeUID) : UFG::SimObject::GetComponentOfType(
                                                                           (UFG::SimObject *)&v1->vfptr,
                                                                           UFG::BaseAnimationComponent::_TypeUID);
    }
    else
    {
      v7 = v1->m_Components.p[9].m_pComponent;
    }
    if ( v7 )
    {
      v3->mRigNameSymbol.mUID = UFG::qSymbol::qSymbol(&result, HIDWORD(v7[3].vfptr))->mUID;
      goto LABEL_35;
    }
  }
  v8 = v1->m_pSceneObj;
  if ( !v8 )
  {
    v9 = 0i64;
LABEL_28:
    if ( !v9 )
      goto LABEL_35;
    goto LABEL_29;
  }
  v9 = v8->mpWritableProperties;
  if ( !v9 )
  {
    v9 = v8->mpConstProperties;
    goto LABEL_28;
  }
LABEL_29:
  v10 = UFG::qPropertySet::Get<UFG::qPropertySet>(
          v9,
          (UFG::qSymbol *)&component_BaseAnimation::sPropertyName.mUID,
          DEPTH_RECURSE);
  if ( v10 )
    v11 = UFG::qPropertySet::GetMemImagePtr(v10);
  else
    v11 = 0i64;
  v12 = *((_QWORD *)v11 + 1);
  if ( v12 )
    v2 = &v11[v12 + 8];
  v3->mRigNameSymbol = (UFG::qSymbolUC)UFG::qSymbolUC::create_from_string((UFG::qSymbolUC *)&result, v2)->mUID;
LABEL_35:
  v13 = v1->m_Flags;
  if ( (v13 >> 14) & 1 || (v13 & 0x8000u) != 0 )
  {
    v14 = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectCharacterPropertiesComponent>(v1);
  }
  else
  {
    if ( (v13 >> 13) & 1 )
    {
      v15 = (UFG::SimObjectGame *)&v1->vfptr;
    }
    else
    {
      v16 = ((v13 >> 12) & 1) == 0;
      v15 = (UFG::SimObjectGame *)&v1->vfptr;
      if ( v16 )
      {
        v14 = (UFG::SimObjectCharacterPropertiesComponent *)UFG::SimObject::GetComponentOfType(
                                                              (UFG::SimObject *)&v1->vfptr,
                                                              UFG::SimObjectCharacterPropertiesComponent::_TypeUID);
        goto LABEL_43;
      }
    }
    v14 = (UFG::SimObjectCharacterPropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                          v15,
                                                          UFG::SimObjectCharacterPropertiesComponent::_TypeUID);
  }
LABEL_43:
  v17 = v14->m_eFactionClass;
  v18 = UFG::FactionInterface::Get();
  v3->mFactionSymbol.mUID = UFG::FactionInterface::MapFactionToSymbol(&v18->mFactionInterface, v17)->mUID;
}

// File Line: 2307
// RVA: 0x4167A0
void __fastcall UFG::PedSpawningInfo::SetPropListFromCurrentSimObject(UFG::PedSpawningInfo *this)
{
  UFG::PedSpawningInfo *v1; // rbx
  UFG::SimObjectGame *v2; // rcx
  UFG::SimComponent *v3; // rax
  unsigned __int16 v4; // dx
  Creature *v5; // rcx
  unsigned int v6; // eax
  unsigned int v7; // edx
  UFG::qSymbol *v8; // r8
  __int64 v9; // rdx
  UFG::qSymbol *v10; // rcx
  __int64 v11; // r8
  UFG::qSymbol *v12; // rbx
  UFG::qArray<UFG::qSymbol,0> nameList; // [rsp+28h] [rbp-20h]

  v1 = this;
  v2 = (UFG::SimObjectGame *)this->mSimObjectPtr.m_pPointer;
  if ( v2 )
  {
    v4 = v2->m_Flags;
    if ( (v4 >> 14) & 1 )
    {
      v3 = v2->m_Components.p[9].m_pComponent;
    }
    else if ( (v4 & 0x8000u) == 0 )
    {
      if ( (v4 >> 13) & 1 )
      {
        v3 = v2->m_Components.p[8].m_pComponent;
      }
      else if ( (v4 >> 12) & 1 )
      {
        v3 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::BaseAnimationComponent::_TypeUID);
      }
      else
      {
        v3 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v2->vfptr, UFG::BaseAnimationComponent::_TypeUID);
      }
    }
    else
    {
      v3 = v2->m_Components.p[9].m_pComponent;
    }
  }
  else
  {
    v3 = 0i64;
  }
  nameList.p = 0i64;
  *(_QWORD *)&nameList.size = 0i64;
  v5 = *(Creature **)&v3[2].m_TypeUID;
  if ( v5 )
    Creature::GetResourceSystemAttachments(v5, &nameList);
  v6 = nameList.size;
  if ( nameList.size > 4 )
    v6 = 4;
  v1->mNumAttachedProps = v6;
  v7 = 0;
  if ( v6 > 0 )
  {
    v8 = nameList.p;
    do
    {
      v1->mAttachedPropNames[v7] = v8[v7];
      ++v7;
    }
    while ( v7 < v1->mNumAttachedProps );
  }
  v9 = v1->mNumAttachedProps;
  if ( (unsigned int)v9 < 4 )
  {
    v10 = &v1->mAttachedPropNames[v9];
    v11 = (unsigned int)(4 - v9);
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
    `eh vector destructor iterator'(nameList.p, 4ui64, nameList.p[-1].mUID, (void (__fastcall *)(void *))_);
    operator delete[](v12);
  }
}

// File Line: 2559
// RVA: 0x4189F0
void __fastcall UFG::PedSpawningInfo::UpdateProxyAIandAnimation(UFG::PedSpawningInfo *this, float elapsedTime)
{
  UFG::PedSpawningInfo *v2; // rbx
  float v3; // xmm1_4
  char v4; // al
  float v5; // xmm1_4
  float v6; // xmm1_4
  signed int v7; // eax
  int v8; // eax

  v2 = this;
  if ( !UFG::AICharacterControllerComponent::s_AIEnabled )
    return;
  if ( this->mHowSpawned == 2 )
    return;
  if ( this->mIsDead == 1 )
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
  v2->mTeleportOnResumeRequired = 1;
  v5 = v2->mProxyTimeSinceLastAIUpdate;
  v2->mProxyTimeSinceLastAIUpdate = 0.0;
  v6 = v5 + v2->mProxyTimeSinceLastFrameUpdate;
  v2->mProxyTimeSinceLastFrameUpdate = v6;
  if ( UFG::gGlobalProxyAnimSpeed >= v6 )
  {
LABEL_14:
    v2->mProxyTimeSinceLastAIUpdate = 0.0;
    return;
  }
  if ( v4 )
  {
    v7 = v2->mProxyModelHandleIndex;
    if ( v7 <= 13 )
      v8 = v7 + 1;
    else
      v8 = 0;
    v2->mProxyModelHandleIndex = v8;
  }
  v2->mProxyTimeSinceLastFrameUpdate = 0.0;
  v2->mProxyTimeSinceLastAIUpdate = 0.0;
}

// File Line: 2690
// RVA: 0x40A070
signed __int64 __fastcall UFG::PedSpawningInfo::ConvertSymbolToSuspendActionEnum(UFG::qSymbol *sSuspendActionSymbol)
{
  unsigned int v1; // eax
  unsigned int v2; // edx

  v1 = sSuspendActionSymbol->mUID;
  v2 = 0;
  if ( sSuspendActionSymbol->mUID == qSymbol_PedSuspendOption_NoSuspend.mUID )
    return 1i64;
  if ( v1 == qSymbol_PedSuspendOption_LockActive.mUID )
    return 2i64;
  if ( v1 != qSymbol_PedSuspendOption_SuspendAllowed.mUID )
  {
    if ( v1 == qSymbol_PedSuspendOption_DeleteOnSuspend.mUID )
      return 4i64;
    if ( v1 == qSymbol_PedSuspendOption_DeleteNow.mUID )
      return 8i64;
    if ( v1 == qSymbol_PedSuspendOption_CleanUpWhenDead.mUID )
      v2 = 16;
  }
  return v2;
}

// File Line: 2707
// RVA: 0x404DC0
void __fastcall UFG::PedSpawnManager::PedSpawnManager(UFG::PedSpawnManager *this)
{
  UFG::PedSpawnManager *v1; // rbx

  v1 = this;
  this->vfptr = (UFG::PedSpawnManagerVtbl *)&UFG::PedSpawnManager::`vftable';
  `eh vector constructor iterator'(
    this->mAmbientPed,
    0x338ui64,
    260,
    (void (__fastcall *)(void *))UFG::PedSpawningInfo::PedSpawningInfo);
  `eh vector constructor iterator'(
    v1->mScriptedPed,
    0x338ui64,
    120,
    (void (__fastcall *)(void *))UFG::PedSpawningInfo::PedSpawningInfo);
  `eh vector constructor iterator'(
    v1->mActiveSpawnSets,
    0x38ui64,
    40,
    (void (__fastcall *)(void *))UFG::ActiveSpawnSetInfo::ActiveSpawnSetInfo);
  v1->mNetRecycleCounter = 0;
  UFG::gpPedSpawnManager = v1;
  UFG::PedSpawnManager::Init(v1);
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
  UFG::TimeOfDayManager *v3; // rax
  float v4; // xmm2_4
  float v5; // xmm1_4
  UFG::TransformNodeComponent *v6; // rbx
  __m128 v7; // xmm2
  float v8; // xmm3_4
  float v9; // xmm2_4
  signed int v10; // eax
  Render::RenderOutputParams outSettings; // [rsp+20h] [rbp-88h]

  Render::RenderOutputParams::RenderOutputParams(&outSettings);
  Render::GetCurrentDisplaySettings(&outSettings);
  if ( outSettings.mLODSetting )
  {
    if ( outSettings.mLODSetting == 1 )
    {
      v0 = FLOAT_40_0;
      v1 = FLOAT_95_0;
      v2 = FLOAT_0_80000001;
      UFG::gTargetPedCountDefLowSpeed = 45;
      UFG::gTargetPedCountDefHighSpeed = 35;
    }
    else if ( outSettings.mLODSetting == 3 )
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
  v3 = UFG::TimeOfDayManager::GetInstance();
  if ( v3 )
  {
    v4 = *(float *)&FLOAT_1_0;
    if ( v3->m_WeatherState > 1.0 )
      v4 = UFG::PedSpawnManager::msPedDensityScaleRainAdjust;
    v5 = (float)(UFG::PedSpawnManager::msBasePedsPerSquareMetre * v4)
       * UFG::PedSpawnManager::msPedDensityScaleTimeTable[(float)(v3->m_SecondsSinceMidnight * 0.00027777778)];
  }
  else
  {
    v5 = UFG::PedSpawnManager::msPedsPerSquareMetre;
  }
  UFG::PedSpawnManager::msPedsPerSquareMetre = v5 * (float)(UFG::PedSpawnManager::msPedDensityScaleCopSystemAdjust * v2);
  if ( LocalPlayer )
  {
    v6 = LocalPlayer->m_pTransformNodeComponent;
    if ( v6 )
    {
      UFG::TransformNodeComponent::UpdateWorldTransform(LocalPlayer->m_pTransformNodeComponent);
      v7 = (__m128)LODWORD(v6->mWorldVelocity.x);
      v7.m128_f32[0] = (float)((float)(v7.m128_f32[0] * v7.m128_f32[0])
                             + (float)(v6->mWorldVelocity.y * v6->mWorldVelocity.y))
                     + (float)(v6->mWorldVelocity.z * v6->mWorldVelocity.z);
      v8 = (float)(COERCE_FLOAT(_mm_sqrt_ps(v7)) - 5.0) * 0.043478262;
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
      v10 = (signed int)(float)((float)((float)((float)UFG::gTargetPedCountDefHighSpeed
                                              - (float)UFG::gTargetPedCountDefLowSpeed)
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
void __fastcall UFG::PedSpawnManager::AddZoneToThugSpawningExceptionsArrary(UFG::PedSpawnManager *this, UFG::SpawnZone *pZone)
{
  _DWORD *v2; // rax
  unsigned int v3; // ebx
  float v4; // xmm1_4
  signed int v5; // er14
  char v6; // bp
  UFG::qSymbol *v7; // rdi
  signed int v8; // esi
  __int64 v9; // rax

  v2 = pZone->mpRegion;
  if ( !v2 )
    v2 = pZone->mpPoint;
  v3 = v2[16];
  v4 = UFG::PedSpawnManager::msElapsedTotal;
  v5 = -1;
  v6 = 0;
  v7 = &UFG::PedSpawnManager::msDisabledThugZones;
  v8 = 0;
  do
  {
    if ( v7->mUID == -1 )
    {
      v5 = v8;
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
    ++v8;
    v7 += 2;
  }
  while ( v8 < 10 );
  if ( v5 >= 0 && !v6 )
  {
    v9 = v5;
    *(&UFG::PedSpawnManager::msDisabledThugZones.mUID + 2 * v9) = v3;
    *((float *)&UFG::PedSpawnManager::msDisabledThugZones + 2 * v9 + 1) = v4;
  }
}

// File Line: 3008
// RVA: 0x417C10
__int64 __fastcall UFG::PedSpawnManager::ThugZoneDisabled(UFG::PedSpawnManager *this, UFG::SpawnZone *pZone)
{
  signed __int64 v2; // rsi
  unsigned __int8 v3; // di
  UFG::SpawnZone *v4; // rbp
  UFG::qSymbol *v5; // rbx
  _DWORD *v6; // rax

  v2 = 10i64;
  v3 = 0;
  v4 = pZone;
  v5 = &UFG::PedSpawnManager::msDisabledThugZones;
  do
  {
    if ( v5->mUID != -1 )
    {
      if ( (float)(UFG::PedSpawnManager::msElapsedTotal - *(float *)&v5[1].mUID) < 900.0 )
      {
        v6 = v4->mpRegion;
        if ( !v6 )
          v6 = v4->mpPoint;
        if ( v5->mUID == v6[16] )
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
  UFG::PedSpawnManager *v1; // rdi
  UFG::TimeOfDayManager *v2; // rax
  int v3; // er12
  UFG::qNode<UFG::PedSpawningInfo,UFG::PedSpawningInfo_DrawList> **v4; // rsi
  _DWORD *v5; // r14
  UFG::qNode<UFG::PedSpawningInfo,UFG::PedSpawningInfo_DrawList> **v6; // rbx
  int v7; // ebp
  int v8; // eax
  _QWORD *v9; // r8
  UFG::qNode<UFG::PedSpawningInfo,UFG::PedSpawningInfo_DrawList> *v10; // rcx
  UFG::qNode<UFG::PedSpawningInfo,UFG::PedSpawningInfo_DrawList> *v11; // rax
  UFG::qNode<UFG::SpawnZone,UFG::SpawnZoneList> *v12; // rax
  bool v13; // zf
  __int64 v14; // rcx
  UFG::qVector3 *v15; // rax

  v1 = this;
  v2 = UFG::TimeOfDayManager::GetInstance();
  ++update_counter;
  v3 = (signed int)(float)(v2->m_SecondsSinceMidnight * 0.00027777778);
  if ( UFG::PedSpawnManager::msForceDensityUpdateCount >= 0 )
    --UFG::PedSpawnManager::msForceDensityUpdateCount;
  if ( UFG::GetLocalPlayer() )
  {
    UFG::PedSpawnManager::msNumValidTopUpZones = 0;
    v1->mTargetNumActive = 0;
    v4 = (UFG::qNode<UFG::PedSpawningInfo,UFG::PedSpawningInfo_DrawList> **)&UFG::PedSpawnManager::msActiveZoneList.mNode.mNext[-2].mNext;
    while ( v4 != &UFG::PedSpawningInfo::smNoDrawList.mNode.mNext )
    {
      v5 = v4 + 17;
      v6 = v4;
      v7 = *((_DWORD *)v4 + 34);
      v1->mTargetNumActive += v7;
      v4 = &v4[4][-2].mNext;
      if ( *((_BYTE *)v6 + 112) )
      {
        v8 = *((_DWORD *)v6 + 33);
        if ( UFG::PedSpawnManager::msForceDensityUpdateCount < 0 )
        {
          if ( !(((unsigned __int8)update_counter ^ (unsigned __int8)v8) & 0x3F) )
            UFG::SpawnRegion::UpdateSpawnSetAndDenisty((UFG::SpawnRegion *)v6[8], v3);
        }
        else if ( !(((unsigned __int8)UFG::PedSpawnManager::msForceDensityUpdateCount ^ (unsigned __int8)v8) & 0x3F) )
        {
          UFG::PedSpawnManager::UpdateActiveSpawnRegion(v1, (UFG::SpawnRegion *)v6[8], 1);
        }
        if ( (float)(UFG::PedSpawnManager::msElapsedTotal - *((float *)v6 + 29)) > 2.2 )
        {
          if ( UFG::SpawnZone::ShouldSpawnZoneDeactivate((UFG::SpawnZone *)v6) )
          {
            v9 = v6 + 3;
            v1->mTargetNumActive -= *v5;
            *((_DWORD *)v6 + 14) = 1;
            v10 = v6[3];
            v11 = v6[4];
            v10->mNext = v11;
            v11->mPrev = v10;
            *v9 = v9;
            v9[1] = v9;
            v12 = UFG::PedSpawnManager::msSpawnZoneList.mNode.mNext;
            UFG::PedSpawnManager::msSpawnZoneList.mNode.mNext = (UFG::qNode<UFG::SpawnZone,UFG::SpawnZoneList> *)(v6 + 3);
            v9[1] = v12;
            *v9 = &UFG::PedSpawnManager::msSpawnZoneList;
            v12->mPrev = (UFG::qNode<UFG::SpawnZone,UFG::SpawnZoneList> *)(v6 + 3);
            *((float *)v6 + 29) = UFG::PedSpawnManager::msElapsedTotal;
            v13 = *((_BYTE *)v6 + 114) == 0;
            *((_DWORD *)v6 + 31) = -1082130432;
            if ( !v13 && *((_DWORD *)v6 + 36) >= *v5 )
              UFG::PedSpawnManager::AddZoneToThugSpawningExceptionsArrary(v1, (UFG::SpawnZone *)v6);
          }
          else if ( UFG::PedSpawnManager::msNumValidTopUpZones < 25
                 && UFG::SpawnZone::IsValidForTopUpSpawning((UFG::SpawnZone *)v6) )
          {
            v14 = UFG::PedSpawnManager::msNumValidTopUpZones;
            UFG::PedSpawnManager::msValidTopUpZones[v14] = (UFG::SpawnZone *)v6;
            UFG::PedSpawnManager::msNumValidTopUpZones = v14 + 1;
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
        v15 = UFG::SectionChooser::GetViewerPosition();
        if ( (float)((float)((float)((float)(v15->y - *((float *)v6 + 39)) * (float)(v15->y - *((float *)v6 + 39)))
                           + (float)((float)(v15->x - *((float *)v6 + 38)) * (float)(v15->x - *((float *)v6 + 38))))
                   + (float)((float)(v15->z - *((float *)v6 + 40)) * (float)(v15->z - *((float *)v6 + 40)))) > 4225.0 )
          v1->mTargetNumActive -= v7;
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
  UFG::qNode<UFG::SpawnZone,UFG::SpawnZoneList> **v4; // r13
  int v5; // er15
  UFG::qNode<UFG::SpawnZone,UFG::SpawnZoneList> **v6; // r12
  UFG::qNode<UFG::SpawnZone,UFG::SpawnZoneList> **v7; // rsi
  UFG::qNode<UFG::SpawnZone,UFG::SpawnZoneList> *v8; // rdi
  UFG::qNode<UFG::SpawnZone,UFG::SpawnZoneList> *v9; // rcx
  UFG::qNode<UFG::SpawnZone,UFG::SpawnZoneList> *v10; // rax
  UFG::qNode<UFG::SpawnZone,UFG::SpawnZoneList> *v11; // rax
  float v12; // xmm1_4
  int v13; // er13
  int v14; // ebx
  char v15; // di
  UFG::qNode<UFG::SpawnZone,UFG::SpawnZoneList> *v16; // rdx
  float v17; // xmm1_4
  int v18; // ebp
  UFG::GroupManager *v19; // rax
  int v20; // er15
  int v21; // er12
  UFG::qPropertySet *v22; // rdi
  int v23; // eax
  UFG::PedSpawningInfo *v24; // rax
  float v25; // xmm1_4
  float v26; // xmm2_4
  UFG::SimObject *v27; // rbx
  UFG::InterestPoint *v28; // rbp
  UFG::SimComponent *v29; // rdi
  UFG::InterestPointUserComponent *v30; // r14
  UFG::allocator::free_link *v31; // rax
  UFG::SimObjectCVBase *v32; // rbp
  UFG::PedSpawningInfo *v33; // rbx
  UFG::qSafePointer<UFG::SpawnZone,UFG::SpawnZone> *v34; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SpawnZone>,UFG::qSafePointerNodeList> *v35; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SpawnZone>,UFG::qSafePointerNodeList> *v36; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SpawnZone>,UFG::qSafePointerNodeList> *v37; // rax
  UFG::SimComponent *v38; // r8
  UFG::qSafePointer<UFG::SimComponent,UFG::InterestPoint> *v39; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v40; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v41; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v42; // rax
  UFG::ActiveAIEntityComponent *v43; // rax
  UFG::InterestPointUserComponent *v44; // r14
  UFG::allocator::free_link *v45; // rax
  UFG::qNode<UFG::SpawnZone,UFG::SpawnZoneList> *v46; // rcx
  UFG::qNode<UFG::SpawnZone,UFG::SpawnZoneList> *v47; // rax
  UFG::qNode<UFG::SpawnZone,UFG::SpawnZoneList> *v48; // rax
  UFG::qNode<UFG::SpawnZone,UFG::SpawnZoneList> *v49; // rcx
  UFG::SceneObjectProperties *v50; // rcx
  UFG::SceneObjectProperties *v51; // rax
  UFG::qNode<UFG::SpawnZone,UFG::SpawnZoneList> *v52; // rcx
  UFG::qNode<UFG::SpawnZone,UFG::SpawnZoneList> *v53; // rax
  UFG::qNode<UFG::SpawnZone,UFG::SpawnZoneList> *v54; // rax
  UFG::SimObjectGame *v55; // rbx
  UFG::qNode<UFG::SpawnZone,UFG::SpawnZoneList> *v56; // rcx
  UFG::qNode<UFG::SpawnZone,UFG::SpawnZoneList> *v57; // rax
  UFG::qNode<UFG::SpawnZone,UFG::SpawnZoneList> *v58; // rax
  int v59; // [rsp+30h] [rbp-E8h]
  int v60; // [rsp+34h] [rbp-E4h]
  UFG::qVector3 newPoint; // [rsp+38h] [rbp-E0h]
  UFG::qSymbol skipIntoLabel; // [rsp+48h] [rbp-D0h]
  UFG::qSymbol v63; // [rsp+4Ch] [rbp-CCh]
  UFG::qList<UFG::SpawnZone,UFG::SpawnZoneList,1,0> *v64; // [rsp+50h] [rbp-C8h]
  UFG::qNode<UFG::SpawnZone,UFG::SpawnZoneList> **v65; // [rsp+58h] [rbp-C0h]
  UFG::allocator::free_link *v66; // [rsp+60h] [rbp-B8h]
  __int64 v67; // [rsp+68h] [rbp-B0h]
  UFG::qMatrix44 outputMatrix; // [rsp+70h] [rbp-A8h]
  UFG::PedSpawnManager *v69; // [rsp+120h] [rbp+8h]
  UFG::PedSpawningInfo *newPedInfo; // [rsp+128h] [rbp+10h]
  char v71; // [rsp+130h] [rbp+18h]
  int v72; // [rsp+138h] [rbp+20h]

  v69 = this;
  v67 = -2i64;
  v1 = this;
  UFG::qList<UFG::SpawnZone,UFG::SpawnZoneList,1,0>::MergeSort(
    &UFG::PedSpawnManager::msShouldBeActiveZoneList,
    UFG::ZoneSortCompare);
  v2 = UFG::CopSystem::Instance();
  v3 = UFG::CopSystem::AllowSpawnRegionSpawning(v2);
  v71 = v3;
  v4 = &UFG::PedSpawnManager::msShouldBeActiveZoneList.mNode.mNext[-2].mNext;
  v5 = 0;
  v72 = 0;
  v6 = (UFG::qNode<UFG::SpawnZone,UFG::SpawnZoneList> **)((char *)&UFG::PedSpawnManager::msShouldBeActiveZoneList - 24);
  v64 = (UFG::qList<UFG::SpawnZone,UFG::SpawnZoneList,1,0> *)((char *)&UFG::PedSpawnManager::msShouldBeActiveZoneList
                                                            - 24);
  if ( &UFG::PedSpawnManager::msShouldBeActiveZoneList.mNode.mNext[-2].mNext != (UFG::qNode<UFG::SpawnZone,UFG::SpawnZoneList> **)((char *)&UFG::PedSpawnManager::msShouldBeActiveZoneList - 24) )
  {
    while ( 1 )
    {
      if ( v5 >= UFG::gZoneSpawnsPerFrame )
      {
        UFG::PedSpawnManager::msDryFireNearSpawnZones = 0;
        return;
      }
      v7 = v4;
      v8 = (UFG::qNode<UFG::SpawnZone,UFG::SpawnZoneList> *)(v4 + 3);
      v4 = &v4[4][-2].mNext;
      v65 = v4;
      if ( UFG::PedSpawnManager::msDryFireNearSpawnZones )
        goto LABEL_65;
      if ( !*((_BYTE *)v7 + 112) )
      {
        if ( !v7[10] )
        {
          v49 = v7[9][2].mNext;
          if ( v49 )
            v50 = (UFG::SceneObjectProperties *)v49[5].mPrev;
          else
            v50 = 0i64;
          v51 = UFG::SceneObjectProperties::GetChildAsSceneObject(v50, 0);
          if ( PropertyUtils::HasComponentPropertySet(v51, (UFG::qSymbol *)&SimSymX_propset_componentCopUnit.mUID) && v3
            || *((_BYTE *)v7 + 114) && UFG::PedSpawnManager::ThugZoneDisabled(v1, (UFG::SpawnZone *)v7) )
          {
            v52 = v8->mPrev;
            v53 = v8->mNext;
            v52->mNext = v53;
            v53->mPrev = v52;
            v8->mPrev = v8;
            v8->mNext = v8;
            v54 = UFG::PedSpawnManager::msActiveZoneList.mNode.mNext;
            UFG::PedSpawnManager::msActiveZoneList.mNode.mNext = v8;
            v8->mPrev = (UFG::qNode<UFG::SpawnZone,UFG::SpawnZoneList> *)&UFG::PedSpawnManager::msActiveZoneList;
            v8->mNext = v54;
            v54->mPrev = v8;
            *((_DWORD *)v7 + 14) = 3;
            *((float *)v7 + 29) = UFG::PedSpawnManager::msElapsedTotal;
          }
          else
          {
            UFG::PedSpawnManager::msZoneDoingSpawnNow = (UFG::SpawnZone *)v7;
            v1->mSpawningModeNow = 2;
            v55 = UFG::SpawnPoint::Spawn((UFG::SpawnPoint *)v7[9], 0, 0);
            UFG::SpawnPoint::UpdateLinks((UFG::SpawnPoint *)v7[9], 0);
            if ( v55 || HIDWORD(v7[9][12].mPrev) || *((float *)v7 + 31) >= 0.0 )
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
              *((_DWORD *)v7 + 14) = 3;
              *((float *)v7 + 29) = UFG::PedSpawnManager::msElapsedTotal;
              v72 = ++v5;
            }
            else
            {
              *((float *)v7 + 31) = UFG::PedSpawnManager::msElapsedTotal + 1.25;
            }
            v1->mSpawningModeNow = 1;
          }
          UFG::PedSpawnManager::msZoneDoingSpawnNow = 0i64;
          goto LABEL_81;
        }
        newPedInfo = 0i64;
        v32 = (UFG::SimObjectCVBase *)UFG::PedSpawnManager::GetAmbientPedForVehicle(v1, 0i64, 0i64, &newPedInfo);
        if ( v32 )
        {
          v33 = newPedInfo;
          v34 = &newPedInfo->mCreationSpawnZone;
          if ( newPedInfo->mCreationSpawnZone.m_pPointer )
          {
            v35 = v34->mPrev;
            v36 = newPedInfo->mCreationSpawnZone.mNext;
            v35->mNext = v36;
            v36->mPrev = v35;
            v34->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SpawnZone>,UFG::qSafePointerNodeList> *)&v34->mPrev;
            v34->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SpawnZone>,UFG::qSafePointerNodeList> *)&v34->mPrev;
          }
          v34->m_pPointer = (UFG::SpawnZone *)v7;
          v37 = (UFG::qNode<UFG::qSafePointerBase<UFG::SpawnZone>,UFG::qSafePointerNodeList> *)v7[1];
          v37->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SpawnZone>,UFG::qSafePointerNodeList> *)&v34->mPrev;
          v34->mPrev = v37;
          v34->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SpawnZone>,UFG::qSafePointerNodeList> *)(v7 + 1);
          v7[1] = (UFG::qNode<UFG::SpawnZone,UFG::SpawnZoneList> *)v34;
          v38 = (UFG::SimComponent *)v7[10];
          v39 = &v33->mUpgradePOI;
          if ( v33->mUpgradePOI.m_pPointer )
          {
            v40 = v39->mPrev;
            v41 = v33->mUpgradePOI.mNext;
            v40->mNext = v41;
            v41->mPrev = v40;
            v39->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v39->mPrev;
            v33->mUpgradePOI.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v33->mUpgradePOI.mPrev;
          }
          v33->mUpgradePOI.m_pPointer = v38;
          if ( v38 )
          {
            v42 = v38->m_SafePointerList.mNode.mPrev;
            v42->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v39->mPrev;
            v39->mPrev = v42;
            v33->mUpgradePOI.mNext = &v38->m_SafePointerList.mNode;
            v38->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v39->mPrev;
          }
          v43 = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>(v32);
          v44 = (UFG::InterestPointUserComponent *)v32->m_Components.p[43].m_pComponent;
          if ( v44 && v43 )
          {
            UFG::GetInterestPointUpRightMatrix((UFG::InterestPoint *)v33->mUpgradePOI.m_pPointer, &outputMatrix);
            v45 = UFG::qMalloc(0x90ui64, "TeleportEvent", 0i64);
            newPedInfo = (UFG::PedSpawningInfo *)v45;
            if ( v45 )
              UFG::TeleportEvent::TeleportEvent(
                (UFG::TeleportEvent *)v45,
                &outputMatrix,
                v32->mNode.mUID,
                0,
                UFG::TeleportEvent::m_Name,
                0);
            UFG::EventDispatcher::DispatchEvent(&UFG::EventDispatcher::mInstance, (UFG::Event *)v45);
            v63.mUID = qSymbol_Link.mUID;
            UFG::InterestPointUserComponent::UsePOI(
              v44,
              (UFG::InterestPoint *)v33->mUpgradePOI.m_pPointer,
              ePOIUseType_Script,
              &v63);
          }
          v33->mLockActiveFrameCount = 10;
          v72 = ++v5;
          v1 = v69;
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
        *((_DWORD *)v7 + 14) = 3;
        *((float *)v7 + 29) = UFG::PedSpawnManager::msElapsedTotal;
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
      *((_DWORD *)v7 + 14) = 3;
      if ( !*((_BYTE *)v7 + 113) )
        break;
      v12 = UFG::PedSpawnManager::msElapsedTotal;
      if ( (float)(UFG::PedSpawnManager::msElapsedTotal - *((float *)v7 + 29)) > 5.0 )
        break;
LABEL_50:
      *((float *)v7 + 29) = v12;
LABEL_81:
      v3 = v71;
      if ( v4 == v6 )
        goto LABEL_84;
    }
    if ( *((_BYTE *)v7 + 114) && UFG::PedSpawnManager::ThugZoneDisabled(v1, (UFG::SpawnZone *)v7) )
    {
      v13 = 0;
LABEL_49:
      v5 += v13;
      v72 = v5;
      v1->mTargetNumActive += *((_DWORD *)v7 + 34);
      v12 = UFG::PedSpawnManager::msElapsedTotal;
      v4 = v65;
      goto LABEL_50;
    }
    *((_BYTE *)v7 + 113) = 1;
    v14 = *((_DWORD *)v7 + 34);
    v60 = *((_DWORD *)v7 + 34);
    if ( *((_DWORD *)v7 + 37) == UFG::Metrics::msFrameCount )
    {
      if ( *((_BYTE *)v7 + 114) )
      {
        if ( *((_DWORD *)v7 + 35) > 0 )
        {
          v13 = 0;
          goto LABEL_49;
        }
      }
      else if ( *((_DWORD *)v7 + 35) >= v14 )
      {
        v13 = 0;
        goto LABEL_49;
      }
    }
    v15 = 0;
    LOBYTE(newPedInfo) = 0;
    v16 = v7[22];
    if ( v16 && (gMainCullIndex < 0 || *((_BYTE *)&v16->mPrev + gMainCullIndex) <= 1u) )
    {
      if ( gMainCullIndex >= 6 )
        v17 = 0.0;
      else
        v17 = *((float *)&v16[1].mPrev + gMainCullIndex);
      v15 = (float)(UFG::PedSpawnManager::msWorkingFullyActiveDistance * 0.75) > v17;
      LOBYTE(newPedInfo) = (float)(UFG::PedSpawnManager::msWorkingFullyActiveDistance * 0.75) > v17;
    }
    v13 = 0;
    if ( v14 )
    {
      v18 = v14;
      v59 = v14;
      if ( UFG::SpawnRegion::IsGroupsAllowed((UFG::SpawnRegion *)v7[8]) )
      {
        v19 = UFG::GroupManager::GetInstance();
        v18 = v14 - (unsigned __int64)UFG::GroupManager::GetNumGroupMembersToSpawn(v19, v14);
        v59 = v18;
      }
      v20 = 0;
      if ( v14 > 0 )
      {
        v21 = v14;
        do
        {
          if ( 260 - UFG::PedSpawnManager::msAmbientCount[0] >= 245 )
          {
            UFG::PedSpawnManager::MakeRoomForMorePeds(v1, v21, v15);
            if ( 260 - UFG::PedSpawnManager::msAmbientCount[0] >= 245 )
              break;
          }
          UFG::SpawnZone::CalcSpawnPoint((UFG::SpawnZone *)v7, &newPoint);
          v22 = UFG::SpawnRegion::GetSpawnableResource((UFG::SpawnRegion *)v7[8], 1, &newPoint);
          if ( v22 )
          {
            UFG::PedSpawnManager::msZoneDoingSpawnNow = (UFG::SpawnZone *)v7;
            v23 = 260
                - UFG::PedSpawnManager::msAmbientCount[0]
                + 120
                - UFG::PedSpawnManager::msScriptedCount[0]
                - UFG::gMaxTotalFullSimPeds;
            if ( 260 - UFG::PedSpawnManager::msAmbientCount[0] - UFG::gMaxAmbientSimObjects > v23 )
              v23 = 260 - UFG::PedSpawnManager::msAmbientCount[0] - UFG::gMaxAmbientSimObjects;
            if ( v23 + 1 <= 0 )
            {
              if ( UFG::SpawnRegion::Spawn((UFG::SpawnRegion *)v7[8], 1, &newPoint, 0) )
              {
                ++v13;
                v24 = UFG::PedSpawnManager::msLastRegisteredPedInfo;
                v25 = newPoint.y;
                v26 = newPoint.z;
                UFG::PedSpawnManager::msLastRegisteredPedInfo->mCurrentLocation.x = newPoint.x;
                v24->mCurrentLocation.y = v25;
                v24->mCurrentLocation.z = v26;
                if ( v18 > 0
                  && !UFG::PedSpawnManager::msLastRegisteredPedInfo->mCharacterOccupantComponent.m_pSimComponent )
                {
                  v27 = UFG::PedSpawnManager::msLastRegisteredPedInfo->mSimObjectPtr.m_pPointer;
                  v28 = UFG::SpawnRegion::GetInterestPoint(
                          (UFG::SpawnRegion *)v7[8],
                          &newPoint,
                          v22,
                          v20 + 1,
                          UFG::PedSpawnManager::msLastRegisteredPedInfo->mSimObjectPtr.m_pPointer);
                  if ( v28 )
                  {
                    v29 = UFG::SimObject::GetComponentOfType(v27, UFG::ActiveAIEntityComponent::_TypeUID);
                    v30 = (UFG::InterestPointUserComponent *)UFG::SimObject::GetComponentOfType(
                                                               v27,
                                                               UFG::InterestPointUserComponent::_TypeUID);
                    if ( v30 && v29 )
                    {
                      --v59;
                      UFG::GetInterestPointUpRightMatrix(v28, &outputMatrix);
                      v31 = UFG::qMalloc(0x90ui64, "TeleportEvent", 0i64);
                      v66 = v31;
                      if ( v31 )
                        UFG::TeleportEvent::TeleportEvent(
                          (UFG::TeleportEvent *)v31,
                          &outputMatrix,
                          v27->mNode.mUID,
                          0,
                          UFG::TeleportEvent::m_Name,
                          0);
                      UFG::EventDispatcher::DispatchEvent(&UFG::EventDispatcher::mInstance, (UFG::Event *)v31);
                      skipIntoLabel.mUID = -1;
                      UFG::InterestPointUserComponent::UsePOI(v30, v28, ePOIUseType_Script, &skipIntoLabel);
                    }
                    v1 = v69;
                  }
                  v14 = v60;
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
        while ( v20 < v14 );
        v6 = &v64->mNode.mPrev;
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
  UFG::PedSpawnManager *v1; // r15
  UFG::TimeOfDayManager *v2; // rax
  unsigned __int8 v3; // dl
  float v4; // xmm0_4
  UFG::qList<UFG::SpawnZone,UFG::SpawnZoneList,1,0> *v5; // rdi
  int v6; // er12
  UFG::qList<UFG::SpawnZone,UFG::SpawnZoneList,1,0> *v7; // rbx
  int v8; // eax
  char v9; // si
  UFG::qNode<UFG::SpawnZone,UFG::SpawnZoneList> *v10; // rax
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
  UFG::qNode<UFG::SpawnZone,UFG::SpawnZoneList> *v22; // rax
  UFG::qNode<UFG::SpawnZone,UFG::SpawnZoneList> *v23; // rdx
  UFG::qNode<UFG::SpawnZone,UFG::SpawnZoneList> *v24; // rax
  UFG::qNode<UFG::SpawnZone,UFG::SpawnZoneList> *v25; // rcx
  UFG::qNode<UFG::SpawnZone,UFG::SpawnZoneList> *v26; // rax
  UFG::qNode<UFG::SpawnZone,UFG::SpawnZoneList> *v27; // rax
  UFG::qVector3 min; // [rsp+10h] [rbp-49h]
  UFG::qVector3 max; // [rsp+20h] [rbp-39h]
  UFG::qBox box; // [rsp+30h] [rbp-29h]
  UFG::qMatrix44 m; // [rsp+50h] [rbp-9h]

  v1 = this;
  v2 = UFG::TimeOfDayManager::GetInstance();
  v3 = update_counter_0 + 1;
  v4 = v2->m_SecondsSinceMidnight * 0.00027777778;
  v5 = (UFG::qList<UFG::SpawnZone,UFG::SpawnZoneList,1,0> *)&UFG::PedSpawnManager::msSpawnZoneList.mNode.mNext[-2].mNext;
  ++update_counter_0;
  v6 = (signed int)v4;
  if ( &UFG::PedSpawnManager::msSpawnZoneList.mNode.mNext[-2].mNext != (UFG::qNode<UFG::SpawnZone,UFG::SpawnZoneList> **)((char *)&UFG::PedSpawnManager::msSpawnZoneList - 24) )
  {
    while ( 1 )
    {
      v7 = v5;
      v5 = (UFG::qList<UFG::SpawnZone,UFG::SpawnZoneList,1,0> *)&v5[2].mNode.mPrev[-2].mNext;
      if ( !LOBYTE(v7[7].mNode.mPrev) )
        break;
      v8 = HIDWORD(v7[8].mNode.mPrev);
      if ( UFG::PedSpawnManager::msForceDensityUpdateCount < 0 )
      {
        if ( !((v3 ^ (unsigned __int8)v8) & 0x3F) )
          UFG::SpawnRegion::UpdateSpawnSetAndDenisty((UFG::SpawnRegion *)v7[4].mNode.mPrev, v6);
      }
      else if ( !(((unsigned __int8)UFG::PedSpawnManager::msForceDensityUpdateCount ^ (unsigned __int8)v8) & 0x3F) )
      {
        UFG::PedSpawnManager::UpdateActiveSpawnRegion(v1, (UFG::SpawnRegion *)v7[4].mNode.mPrev, 1);
      }
      if ( UFG::SpawnZone::ShouldSpawnZoneActivate((UFG::SpawnZone *)v7) )
      {
        v9 = 0;
        if ( NISManager::GetInstance()->mSpatialDataHandle.mData )
        {
          v10 = v7[10].mNode.mNext;
          if ( v10 )
          {
            if ( !UFG::BenchmarkHelper::gBenchmarkHelper.mTiming )
            {
              v11 = *((float *)&v10->mPrev + 1);
              v12 = *(float *)&v10->mNext;
              v13 = &UFG::qMatrix44::msIdentity;
              min.x = *(float *)&v10->mPrev;
              min.y = v11;
              min.z = v12;
              v14 = *((float *)&v10[1].mPrev + 1);
              v15 = *(float *)&v10[1].mNext;
              max.x = *(float *)&v10[1].mPrev;
              max.y = v14;
              max.z = v15;
              v16 = (UFG::qMatrix44 *)v10[3].mNext;
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
              v9 = 0;
              if ( NISManager::IntersectsSpatialBoundingBox(v20, &box) )
                v9 = 1;
            }
          }
        }
        v21 = v7[1].mNode.mNext;
        v22 = v7[2].mNode.mPrev;
        v23 = (UFG::qNode<UFG::SpawnZone,UFG::SpawnZoneList> *)((char *)&v7[1].mNode + 8);
        v21->mNext = v22;
        v22->mPrev = v21;
        v23->mPrev = v23;
        v23->mNext = v23;
        if ( v9 )
        {
          v24 = UFG::PedSpawnManager::msActiveZoneList.mNode.mNext;
          UFG::PedSpawnManager::msActiveZoneList.mNode.mNext = (UFG::qNode<UFG::SpawnZone,UFG::SpawnZoneList> *)((char *)&v7[1].mNode + 8);
          v7[2].mNode.mPrev = v24;
          v23->mPrev = (UFG::qNode<UFG::SpawnZone,UFG::SpawnZoneList> *)&UFG::PedSpawnManager::msActiveZoneList;
          v24->mPrev = v23;
          LODWORD(v7[3].mNode.mNext) = 3;
          *((float *)&v7[7].mNode.mPrev + 1) = UFG::PedSpawnManager::msElapsedTotal;
          goto LABEL_21;
        }
LABEL_20:
        v27 = UFG::PedSpawnManager::msShouldBeActiveZoneList.mNode.mPrev;
        UFG::PedSpawnManager::msShouldBeActiveZoneList.mNode.mPrev->mNext = v23;
        v23->mPrev = v27;
        v23->mNext = (UFG::qNode<UFG::SpawnZone,UFG::SpawnZoneList> *)&UFG::PedSpawnManager::msShouldBeActiveZoneList;
        UFG::PedSpawnManager::msShouldBeActiveZoneList.mNode.mPrev = v23;
      }
LABEL_21:
      if ( v5 == (UFG::qList<UFG::SpawnZone,UFG::SpawnZoneList,1,0> *)((char *)&UFG::PedSpawnManager::msSpawnZoneList
                                                                     - 24) )
        goto LABEL_23;
      v3 = update_counter_0;
    }
    if ( !UFG::SpawnZone::ShouldSpawnZoneActivate((UFG::SpawnZone *)v7) )
      goto LABEL_21;
    v25 = v7[1].mNode.mNext;
    v26 = v7[2].mNode.mPrev;
    v23 = (UFG::qNode<UFG::SpawnZone,UFG::SpawnZoneList> *)((char *)&v7[1].mNode + 8);
    v25->mNext = v26;
    v26->mPrev = v25;
    v23->mPrev = v23;
    v23->mNext = v23;
    goto LABEL_20;
  }
LABEL_23:
  if ( UFG::PedSpawnManager::msPedInfoForLocalZoneChecks )
  {
    UFG::PedSpawnManager::msPedInfoForLocalZoneChecks->mIsNearDeactivatedZones = 0;
    UFG::PedSpawnManager::msPedInfoForLocalZoneChecks->mShouldCheckZoneInAreaTime = 0.0;
  }
  UFG::PedSpawnManager::ProcessZonesDueToSpawn(v1);
}

// File Line: 3532
// RVA: 0x417710
void __fastcall UFG::PedSpawnManager::SpawnZonesNearCamera(UFG::PedSpawnManager *this, const float dist)
{
  UFG::PedSpawnManager *v2; // rbp
  UFG::qList<UFG::SpawnZone,UFG::SpawnZoneList,1,0> *v3; // rbx
  UFG::qList<UFG::SpawnZone,UFG::SpawnZoneList,1,0> *v4; // rdi
  UFG::qVector3 *v5; // rax
  UFG::qNode<UFG::SpawnZone,UFG::SpawnZoneList> *v6; // rax
  UFG::qNode<UFG::SpawnZone,UFG::SpawnZoneList> *v7; // rcx
  UFG::qNode<UFG::SpawnZone,UFG::SpawnZoneList> **v8; // rdx
  UFG::qNode<UFG::SpawnZone,UFG::SpawnZoneList> *v9; // rax

  v2 = this;
  if ( UFG::PedSpawnManager::msAmbientSpawningEnable )
  {
    v3 = (UFG::qList<UFG::SpawnZone,UFG::SpawnZoneList,1,0> *)&UFG::PedSpawnManager::msSpawnZoneList.mNode.mNext[-2].mNext;
    while ( v3 != (UFG::qList<UFG::SpawnZone,UFG::SpawnZoneList,1,0> *)((char *)&UFG::PedSpawnManager::msSpawnZoneList
                                                                      - 24) )
    {
      v4 = v3;
      v3 = (UFG::qList<UFG::SpawnZone,UFG::SpawnZoneList,1,0> *)&v3[2].mNode.mPrev[-2].mNext;
      v5 = UFG::SectionChooser::GetViewerPosition();
      if ( (float)((float)((float)((float)(v5->y - *((float *)&v4[9].mNode.mNext + 1))
                                 * (float)(v5->y - *((float *)&v4[9].mNode.mNext + 1)))
                         + (float)((float)(v5->x - *(float *)&v4[9].mNode.mNext)
                                 * (float)(v5->x - *(float *)&v4[9].mNode.mNext)))
                 + (float)((float)(v5->z - *(float *)&v4[10].mNode.mPrev)
                         * (float)(v5->z - *(float *)&v4[10].mNode.mPrev))) < (float)(dist * dist) )
      {
        v6 = v4[2].mNode.mPrev;
        v7 = v4[1].mNode.mNext;
        v8 = &v4[1].mNode.mNext;
        v7->mNext = v6;
        v6->mPrev = v7;
        *v8 = (UFG::qNode<UFG::SpawnZone,UFG::SpawnZoneList> *)v8;
        v8[1] = (UFG::qNode<UFG::SpawnZone,UFG::SpawnZoneList> *)v8;
        v9 = UFG::PedSpawnManager::msShouldBeActiveZoneList.mNode.mPrev;
        UFG::PedSpawnManager::msShouldBeActiveZoneList.mNode.mPrev->mNext = (UFG::qNode<UFG::SpawnZone,UFG::SpawnZoneList> *)((char *)&v4[1].mNode + 8);
        *v8 = v9;
        v8[1] = (UFG::qNode<UFG::SpawnZone,UFG::SpawnZoneList> *)&UFG::PedSpawnManager::msShouldBeActiveZoneList;
        UFG::PedSpawnManager::msShouldBeActiveZoneList.mNode.mPrev = (UFG::qNode<UFG::SpawnZone,UFG::SpawnZoneList> *)((char *)&v4[1].mNode + 8);
      }
    }
    UFG::PedSpawnManager::ProcessZonesDueToSpawn(v2);
  }
}

// File Line: 3773
// RVA: 0x40E300
void __fastcall UFG::PedSpawnManager::LoadPedDensityTable(UFG::Event *__formal)
{
  UFG::qPropertySet *v1; // r15
  unsigned int v2; // ebp
  signed __int64 v3; // rbx
  int v4; // esi
  signed __int64 v5; // rdi
  float *v6; // r14
  signed __int64 v7; // [rsp+20h] [rbp-68h]
  UFG::qString v8; // [rsp+28h] [rbp-60h]
  UFG::qSymbol result; // [rsp+98h] [rbp+10h]
  UFG::qSymbol propName; // [rsp+A0h] [rbp+18h]
  UFG::qSymbol v11; // [rsp+A8h] [rbp+20h]

  v7 = -2i64;
  UFG::qSymbol::create_from_string(&result, "config-PedDensityScale");
  v1 = UFG::PropertySetManager::GetPropertySet(&result);
  v2 = 0;
  v3 = 0i64;
  do
  {
    v4 = v2 + 1;
    v5 = v3 + 1;
    v6 = 0i64;
    if ( (signed int)(v2 + 1) < 25 )
    {
      while ( 1 )
      {
        UFG::qString::FormatEx(&v8, "Hours_%02d_%02d", v2, (unsigned int)v4, v7);
        UFG::qSymbol::create_from_string(&propName, v8.mData);
        v6 = PropertyUtils::Get<float>(v1, &propName, DEPTH_RECURSE);
        if ( v6 )
          break;
        UFG::qString::~qString(&v8);
        ++v4;
        ++v5;
        if ( v4 >= 25 )
          goto LABEL_7;
      }
      UFG::qString::~qString(&v8);
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
  UFG::qSymbol::create_from_string(&v11, "Rain_Adjust");
  UFG::PedSpawnManager::msPedDensityScaleRainAdjust = *PropertyUtils::Get<float>(v1, &v11, DEPTH_RECURSE);
}

// File Line: 4022
// RVA: 0x40D080
void __fastcall UFG::PedSpawnManager::Init(UFG::PedSpawnManager *this)
{
  UFG::PedSpawnManager *v1; // rsi
  unsigned int v2; // ebx
  UFG::qResourceInventory *v3; // rax
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
  UFG::PedSpawningInfo *v48; // rdi
  int v49; // ebx
  UFG::PedSpawningInfo *v50; // rdi
  UFG::qSymbol *v51; // rbx

  v1 = this;
  unk_14207A98C = 3;
  v2 = UFG::qStringHash32("ULTRALOWPED_FRAME00", 0xFFFFFFFF);
  v3 = `UFG::qGetResourceInventory<Illusion::Model>'::`2'::result;
  if ( !`UFG::qGetResourceInventory<Illusion::Model>'::`2'::result )
  {
    v4 = UFG::qResourceWarehouse::Instance();
    v3 = UFG::qResourceWarehouse::GetInventory(v4, 0xA2ADCD77);
    `UFG::qGetResourceInventory<Illusion::Model>'::`2'::result = v3;
  }
  UFG::qResourceHandle::Init(&UFG::PedSpawnManager::msLowLODHandles, 0xA2ADCD77, v2, v3);
  v5 = UFG::qStringHash32("ULTRALOWPED_FRAME01", 0xFFFFFFFF);
  v6 = `UFG::qGetResourceInventory<Illusion::Model>'::`2'::result;
  if ( !`UFG::qGetResourceInventory<Illusion::Model>'::`2'::result )
  {
    v7 = UFG::qResourceWarehouse::Instance();
    v6 = UFG::qResourceWarehouse::GetInventory(v7, 0xA2ADCD77);
    `UFG::qGetResourceInventory<Illusion::Model>'::`2'::result = v6;
  }
  UFG::qResourceHandle::Init(&stru_1423DE6D0, 0xA2ADCD77, v5, v6);
  v8 = UFG::qStringHash32("ULTRALOWPED_FRAME02", 0xFFFFFFFF);
  v9 = `UFG::qGetResourceInventory<Illusion::Model>'::`2'::result;
  if ( !`UFG::qGetResourceInventory<Illusion::Model>'::`2'::result )
  {
    v10 = UFG::qResourceWarehouse::Instance();
    v9 = UFG::qResourceWarehouse::GetInventory(v10, 0xA2ADCD77);
    `UFG::qGetResourceInventory<Illusion::Model>'::`2'::result = v9;
  }
  UFG::qResourceHandle::Init(&stru_1423DE6F0, 0xA2ADCD77, v8, v9);
  v11 = UFG::qStringHash32("ULTRALOWPED_FRAME03", 0xFFFFFFFF);
  v12 = `UFG::qGetResourceInventory<Illusion::Model>'::`2'::result;
  if ( !`UFG::qGetResourceInventory<Illusion::Model>'::`2'::result )
  {
    v13 = UFG::qResourceWarehouse::Instance();
    v12 = UFG::qResourceWarehouse::GetInventory(v13, 0xA2ADCD77);
    `UFG::qGetResourceInventory<Illusion::Model>'::`2'::result = v12;
  }
  UFG::qResourceHandle::Init(&stru_1423DE710, 0xA2ADCD77, v11, v12);
  v14 = UFG::qStringHash32("ULTRALOWPED_FRAME04", 0xFFFFFFFF);
  v15 = `UFG::qGetResourceInventory<Illusion::Model>'::`2'::result;
  if ( !`UFG::qGetResourceInventory<Illusion::Model>'::`2'::result )
  {
    v16 = UFG::qResourceWarehouse::Instance();
    v15 = UFG::qResourceWarehouse::GetInventory(v16, 0xA2ADCD77);
    `UFG::qGetResourceInventory<Illusion::Model>'::`2'::result = v15;
  }
  UFG::qResourceHandle::Init(&stru_1423DE730, 0xA2ADCD77, v14, v15);
  v17 = UFG::qStringHash32("ULTRALOWPED_FRAME05", 0xFFFFFFFF);
  v18 = `UFG::qGetResourceInventory<Illusion::Model>'::`2'::result;
  if ( !`UFG::qGetResourceInventory<Illusion::Model>'::`2'::result )
  {
    v19 = UFG::qResourceWarehouse::Instance();
    v18 = UFG::qResourceWarehouse::GetInventory(v19, 0xA2ADCD77);
    `UFG::qGetResourceInventory<Illusion::Model>'::`2'::result = v18;
  }
  UFG::qResourceHandle::Init(&stru_1423DE750, 0xA2ADCD77, v17, v18);
  v20 = UFG::qStringHash32("ULTRALOWPED_FRAME06", 0xFFFFFFFF);
  v21 = `UFG::qGetResourceInventory<Illusion::Model>'::`2'::result;
  if ( !`UFG::qGetResourceInventory<Illusion::Model>'::`2'::result )
  {
    v22 = UFG::qResourceWarehouse::Instance();
    v21 = UFG::qResourceWarehouse::GetInventory(v22, 0xA2ADCD77);
    `UFG::qGetResourceInventory<Illusion::Model>'::`2'::result = v21;
  }
  UFG::qResourceHandle::Init(&stru_1423DE770, 0xA2ADCD77, v20, v21);
  v23 = UFG::qStringHash32("ULTRALOWPED_FRAME07", 0xFFFFFFFF);
  v24 = `UFG::qGetResourceInventory<Illusion::Model>'::`2'::result;
  if ( !`UFG::qGetResourceInventory<Illusion::Model>'::`2'::result )
  {
    v25 = UFG::qResourceWarehouse::Instance();
    v24 = UFG::qResourceWarehouse::GetInventory(v25, 0xA2ADCD77);
    `UFG::qGetResourceInventory<Illusion::Model>'::`2'::result = v24;
  }
  UFG::qResourceHandle::Init(&stru_1423DE790, 0xA2ADCD77, v23, v24);
  v26 = UFG::qStringHash32("ULTRALOWPED_FRAME08", 0xFFFFFFFF);
  v27 = `UFG::qGetResourceInventory<Illusion::Model>'::`2'::result;
  if ( !`UFG::qGetResourceInventory<Illusion::Model>'::`2'::result )
  {
    v28 = UFG::qResourceWarehouse::Instance();
    v27 = UFG::qResourceWarehouse::GetInventory(v28, 0xA2ADCD77);
    `UFG::qGetResourceInventory<Illusion::Model>'::`2'::result = v27;
  }
  UFG::qResourceHandle::Init(&stru_1423DE7B0, 0xA2ADCD77, v26, v27);
  v29 = UFG::qStringHash32("ULTRALOWPED_FRAME09", 0xFFFFFFFF);
  v30 = `UFG::qGetResourceInventory<Illusion::Model>'::`2'::result;
  if ( !`UFG::qGetResourceInventory<Illusion::Model>'::`2'::result )
  {
    v31 = UFG::qResourceWarehouse::Instance();
    v30 = UFG::qResourceWarehouse::GetInventory(v31, 0xA2ADCD77);
    `UFG::qGetResourceInventory<Illusion::Model>'::`2'::result = v30;
  }
  UFG::qResourceHandle::Init(&stru_1423DE7D0, 0xA2ADCD77, v29, v30);
  v32 = UFG::qStringHash32("ULTRALOWPED_FRAME10", 0xFFFFFFFF);
  v33 = `UFG::qGetResourceInventory<Illusion::Model>'::`2'::result;
  if ( !`UFG::qGetResourceInventory<Illusion::Model>'::`2'::result )
  {
    v34 = UFG::qResourceWarehouse::Instance();
    v33 = UFG::qResourceWarehouse::GetInventory(v34, 0xA2ADCD77);
    `UFG::qGetResourceInventory<Illusion::Model>'::`2'::result = v33;
  }
  UFG::qResourceHandle::Init(&stru_1423DE7F0, 0xA2ADCD77, v32, v33);
  v35 = UFG::qStringHash32("ULTRALOWPED_FRAME11", 0xFFFFFFFF);
  v36 = `UFG::qGetResourceInventory<Illusion::Model>'::`2'::result;
  if ( !`UFG::qGetResourceInventory<Illusion::Model>'::`2'::result )
  {
    v37 = UFG::qResourceWarehouse::Instance();
    v36 = UFG::qResourceWarehouse::GetInventory(v37, 0xA2ADCD77);
    `UFG::qGetResourceInventory<Illusion::Model>'::`2'::result = v36;
  }
  UFG::qResourceHandle::Init(&stru_1423DE810, 0xA2ADCD77, v35, v36);
  v38 = UFG::qStringHash32("ULTRALOWPED_FRAME12", 0xFFFFFFFF);
  v39 = `UFG::qGetResourceInventory<Illusion::Model>'::`2'::result;
  if ( !`UFG::qGetResourceInventory<Illusion::Model>'::`2'::result )
  {
    v40 = UFG::qResourceWarehouse::Instance();
    v39 = UFG::qResourceWarehouse::GetInventory(v40, 0xA2ADCD77);
    `UFG::qGetResourceInventory<Illusion::Model>'::`2'::result = v39;
  }
  UFG::qResourceHandle::Init(&stru_1423DE830, 0xA2ADCD77, v38, v39);
  v41 = UFG::qStringHash32("ULTRALOWPED_FRAME13", 0xFFFFFFFF);
  v42 = `UFG::qGetResourceInventory<Illusion::Model>'::`2'::result;
  if ( !`UFG::qGetResourceInventory<Illusion::Model>'::`2'::result )
  {
    v43 = UFG::qResourceWarehouse::Instance();
    v42 = UFG::qResourceWarehouse::GetInventory(v43, 0xA2ADCD77);
    `UFG::qGetResourceInventory<Illusion::Model>'::`2'::result = v42;
  }
  UFG::qResourceHandle::Init(&stru_1423DE850, 0xA2ADCD77, v41, v42);
  v44 = UFG::qStringHash32("ULTRALOWPED_FRAME14", 0xFFFFFFFF);
  v45 = `UFG::qGetResourceInventory<Illusion::Model>'::`2'::result;
  if ( !`UFG::qGetResourceInventory<Illusion::Model>'::`2'::result )
  {
    v46 = UFG::qResourceWarehouse::Instance();
    v45 = UFG::qResourceWarehouse::GetInventory(v46, 0xA2ADCD77);
    `UFG::qGetResourceInventory<Illusion::Model>'::`2'::result = v45;
  }
  UFG::qResourceHandle::Init(&stru_1423DE870, 0xA2ADCD77, v44, v45);
  v1->mTargetNumActive = 0;
  *(_QWORD *)UFG::PedSpawnManager::msAmbientCount = 0i64;
  qword_1423DC628 = 0i64;
  qword_1423DC630 = 0i64;
  *(_QWORD *)UFG::PedSpawnManager::msScriptedCount = 0i64;
  UFG::PedSpawnManager::msElapsedTotal = 0.0;
  qword_1423DC640 = 0i64;
  qword_1423DC648 = 0i64;
  v1->mUpdateDelta = 0.0;
  UFG::PedSpawnManager::msProxyPedsEnabled = 1;
  UFG::PedSpawnManager::LoadPedDensityTable(0i64);
  v47 = 0;
  v48 = v1->mAmbientPed;
  do
  {
    UFG::PedSpawningInfo::Init(v48, v47++, AmbientPed);
    ++v48;
  }
  while ( v47 < 260 );
  v49 = 0;
  v50 = v1->mScriptedPed;
  do
  {
    UFG::PedSpawningInfo::Init(v50, v49++, ScriptedPed);
    ++v50;
  }
  while ( v49 < 120 );
  v51 = &UFG::PedSpawnManager::msDisabledThugZones;
  do
  {
    UFG::qSymbol::set_null(v51);
    v51[1].mUID = 0;
    v51 += 2;
  }
  while ( (signed __int64)v51 < (signed __int64)&UFG::mgSym_Face );
  v1->mPedSpawnHistoryIndex = 0;
}

// File Line: 4243
// RVA: 0x411260
void __fastcall UFG::PedSpawnManager::OnGameEnter(UFG::PedSpawnManager *this)
{
  UFG::PedSpawnManager *v1; // rsi
  void (__fastcall *v2)(fastdelegate::FastDelegate1<char const *,void> *, const char *); // rbx
  void (__fastcall *v3)(fastdelegate::FastDelegate1<char const *,void> *, const char *); // rax
  int v4; // ebx
  UFG::PedSpawningInfo *v5; // rdi
  int v6; // ebx
  UFG::PedSpawningInfo *v7; // rdi
  UFG::allocator::free_link *v8; // rax
  UFG::SpawnZone *v9; // rbx
  signed int v10; // ecx
  __int64 v11; // rdx
  UFG::SpawnZone **v12; // r8
  __int64 v13; // r9
  void (__fastcall *v14)(UFG::Event *); // [rsp+38h] [rbp-30h]
  void (__fastcall *v15)(fastdelegate::FastDelegate1<char const *,void> *, const char *); // [rsp+40h] [rbp-28h]
  void (__fastcall *v16)(UFG::Event *); // [rsp+48h] [rbp-20h]
  void (__fastcall *v17)(fastdelegate::FastDelegate1<char const *,void> *, const char *); // [rsp+50h] [rbp-18h]

  v1 = this;
  v2 = fastdelegate::FastDelegate1<char const *,void>::InvokeStaticFunction;
  v3 = fastdelegate::FastDelegate1<char const *,void>::InvokeStaticFunction;
  if ( !UFG::PedSpawnManager::SceneLayerActivatedEventHandler )
    v3 = 0i64;
  v17 = v3;
  v16 = UFG::PedSpawnManager::SceneLayerActivatedEventHandler;
  v15 = v3;
  v14 = UFG::PedSpawnManager::SceneLayerActivatedEventHandler;
  UFG::EventDispatcher::Register(
    &UFG::EventDispatcher::mInstance,
    (fastdelegate::FastDelegate1<UFG::Event *,void> *)&v14,
    UFG::gSceneLayerActivatedChannel.mUID,
    0i64,
    0);
  if ( !UFG::PedSpawnManager::SceneLayerActivatedEventHandler )
    v2 = 0i64;
  v17 = v2;
  v16 = UFG::PedSpawnManager::SceneLayerActivatedEventHandler;
  v15 = v2;
  v14 = UFG::PedSpawnManager::SceneLayerActivatedEventHandler;
  UFG::EventDispatcher::Register(
    &UFG::EventDispatcher::mInstance,
    (fastdelegate::FastDelegate1<UFG::Event *,void> *)&v14,
    UFG::gSceneLayerDeactivatedChannel.mUID,
    0i64,
    0);
  v4 = 0;
  v5 = v1->mAmbientPed;
  do
  {
    UFG::PedSpawningInfo::InitProxySimObject(v5, v4++);
    ++v5;
  }
  while ( v4 < 260 );
  v6 = 0;
  v7 = v1->mScriptedPed;
  do
  {
    UFG::PedSpawningInfo::InitProxySimObject(v7, v6++);
    ++v7;
  }
  while ( v6 < 120 );
  v8 = UFG::qMalloc(0x286E8ui64, "spawn zones", 0i64);
  if ( v8 )
  {
    LODWORD(v8->mNext) = 900;
    v9 = (UFG::SpawnZone *)&v8[1];
    `eh vector constructor iterator'(&v8[1], 0xB8ui64, 900, (void (__fastcall *)(void *))UFG::SpawnZone::SpawnZone);
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
  UFG::PedSpawnManager *v1; // rsi
  UFG::PedSpawningInfo *v2; // rbx
  signed __int64 v3; // rdi
  UFG::PedSpawningInfo *v4; // rbx
  signed __int64 v5; // rdi
  void (__fastcall *v6)(fastdelegate::FastDelegate1<char const *,void> *, const char *); // rbx
  void (__fastcall *v7)(fastdelegate::FastDelegate1<char const *,void> *, const char *); // rax
  signed __int64 v8; // rbx
  signed __int64 v9; // rdi
  void *v10; // rcx
  void (__fastcall *v11)(UFG::Event *); // [rsp+20h] [rbp-18h]
  void (__fastcall *v12)(fastdelegate::FastDelegate1<char const *,void> *, const char *); // [rsp+28h] [rbp-10h]

  v1 = this;
  v2 = this->mAmbientPed;
  v3 = 260i64;
  do
  {
    UFG::PedSpawningInfo::Reset(v2, 0);
    ++v2;
    --v3;
  }
  while ( v3 );
  v4 = v1->mScriptedPed;
  v5 = 120i64;
  do
  {
    UFG::PedSpawningInfo::Reset(v4, 0);
    ++v4;
    --v5;
  }
  while ( v5 );
  v6 = fastdelegate::FastDelegate1<char const *,void>::InvokeStaticFunction;
  v7 = fastdelegate::FastDelegate1<char const *,void>::InvokeStaticFunction;
  v11 = UFG::PedSpawnManager::SceneLayerActivatedEventHandler;
  if ( !UFG::PedSpawnManager::SceneLayerActivatedEventHandler )
    v7 = 0i64;
  v12 = v7;
  UFG::EventDispatcher::UnRegister(
    &UFG::EventDispatcher::mInstance,
    (fastdelegate::FastDelegate1<UFG::Event *,void> *)&v11,
    UFG::gSceneLayerActivatedChannel.mUID);
  if ( !UFG::PedSpawnManager::SceneLayerActivatedEventHandler )
    v6 = 0i64;
  v11 = UFG::PedSpawnManager::SceneLayerActivatedEventHandler;
  v12 = v6;
  UFG::EventDispatcher::UnRegister(
    &UFG::EventDispatcher::mInstance,
    (fastdelegate::FastDelegate1<UFG::Event *,void> *)&v11,
    UFG::gSceneLayerDeactivatedChannel.mUID);
  if ( UFG::PedSpawnManager::msSpawnZoneStructs )
  {
    if ( LODWORD(UFG::PedSpawnManager::msSpawnZoneStructs[-1].mCullResults) )
      UFG::PedSpawnManager::msSpawnZoneStructs->vfptr->__vecDelDtor(
        (UFG::qSafePointerNode<UFG::SpawnZone> *)UFG::PedSpawnManager::msSpawnZoneStructs,
        3u);
    else
      operator delete[](&UFG::PedSpawnManager::msSpawnZoneStructs[-1].mCullResults);
  }
  UFG::PedSpawnManager::msSpawnZoneStructs = 0i64;
  UFG::PedSpawnManager::msAmbientSpawningEnable = 1;
  UFG::PedSpawnManager::msCheckStatusMode = 1;
  UFG::PedSpawnManager::msAmbientStatusCheckEnable = 1;
  UFG::PedSpawnManager::msScriptedStatusCheckEnable = 1;
  v8 = (signed __int64)&v1->mActiveSpawnSets[0].mSpawnInfoArray.p;
  v9 = 40i64;
  do
  {
    *(_QWORD *)(v8 - 32) = 0i64;
    if ( *(_QWORD *)v8 )
      operator delete[](*(void **)v8);
    *(_QWORD *)v8 = 0i64;
    *(_QWORD *)(v8 - 8) = 0i64;
    v10 = *(void **)(v8 + 16);
    if ( v10 )
      operator delete[](v10);
    *(_QWORD *)(v8 + 16) = 0i64;
    *(_QWORD *)(v8 + 8) = 0i64;
    *(_QWORD *)(v8 - 24) = 0i64;
    *(_DWORD *)(v8 - 16) = 0;
    *(_BYTE *)(v8 - 12) = 0;
    v8 += 56i64;
    --v9;
  }
  while ( v9 );
}

// File Line: 4319
// RVA: 0x416A80
void __fastcall UFG::PedSpawnManager::SetStartMode(UFG::PedSpawnManager *this, UFG::SimObject *pObj, UFG::qPropertySet *pPropSet, UFG::qVector3 *startPos)
{
  if ( UFG::PedSpawnManager::msLastRegisteredPedInfo->mPedType == 1 )
    UFG::PedSpawnManager::SetAmbientStartingMode(this, UFG::PedSpawnManager::msLastRegisteredPedInfo, startPos);
}

// File Line: 4332
// RVA: 0x40E180
bool __fastcall UFG::PedSpawnManager::JoinGroup(UFG::PedSpawnManager *this, UFG::SimObject *pObj, UFG::qPropertySet *pPropSet, UFG::qVector3 *startPos, UFG::SpawnRegion *pSourceRegion)
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
_BOOL8 __fastcall UFG::PedSpawnManager::TryJoinGroup(UFG::PedSpawnManager *this, UFG::PedSpawningInfo *pPed, UFG::qVector3 *pos, const bool groupIsNotAllowed, UFG::SpawnRegion *pSourceRegion)
{
  bool v5; // bp
  UFG::qVector3 *v6; // rdi
  UFG::PedSpawningInfo *v7; // rsi
  bool v8; // bl
  float v9; // xmm1_4
  float v10; // xmm0_4
  UFG::GroupManager *v11; // rax
  float v12; // xmm1_4
  float v13; // xmm2_4
  UFG::qVector3 followerPosition; // [rsp+38h] [rbp-80h]
  UFG::qFixedArray<UFG::PedSpawningInfo *,10> closePeds; // [rsp+50h] [rbp-68h]

  v5 = groupIsNotAllowed;
  v6 = pos;
  v7 = pPed;
  v8 = 0;
  if ( groupIsNotAllowed )
    goto LABEL_12;
  closePeds.size = 0;
  v9 = pos->y;
  v10 = pos->z;
  followerPosition.x = pos->x;
  followerPosition.y = v9;
  followerPosition.z = v10;
  UFG::PedSpawnManager::GetGroupCandidates(this, pPed, &closePeds, &followerPosition, 8.0);
  if ( closePeds.size )
  {
    v11 = UFG::GroupManager::GetInstance();
    v8 = UFG::GroupManager::JoinGroup(v11, v7, &closePeds);
    if ( v8 )
    {
      v12 = v6->y;
      v13 = v6->z;
      followerPosition.x = v6->x;
      followerPosition.y = v12;
      followerPosition.z = v13;
      if ( UFG::GroupComponent::GetDefaultFollowerPosition(v7->mGroupComponent, &followerPosition)
        && UFG::RegionComponent::IsHitPoint(pSourceRegion->mpRegion, &followerPosition) )
      {
        v6->x = followerPosition.x;
        v6->y = followerPosition.y;
        v6->z = followerPosition.z;
      }
    }
  }
  closePeds.size = 0;
  if ( !v8 )
LABEL_12:
    UFG::GroupComponent::MakeSingle(v7->mGroupComponent, v5 == 0);
  return v8;
}

// File Line: 4404
// RVA: 0x40AB40
void __fastcall UFG::PedSpawnManager::DeletePedsFromDeactivatedRegions(UFG::PedSpawnManager *this)
{
  UFG::PedSpawningInfo *v1; // rbx
  UFG::PedSpawningInfo *v2; // rsi
  signed __int64 v3; // rbp
  UFG::SimObject *v4; // rdi
  UFG::SimComponent *v5; // rcx
  UFG::SceneObjectProperties *v6; // rcx

  v1 = (UFG::PedSpawningInfo *)((char *)this->mAmbientPed + 0x168);
  v2 = this->mAmbientPed;
  v3 = 260i64;
  do
  {
    if ( !*(_QWORD *)&v1[-1].mTrueCrowdSignature.mPart[15].mModelIndex && !*(_QWORD *)&v1[-1].mLocationInCameraSpace.y )
    {
      v4 = *(UFG::SimObject **)&v1[-1].mNumAttachedProps;
      if ( v4 )
      {
        v5 = v4->m_Components.p[27].m_pComponent;
        if ( v5 && v5[9].m_TypeUID )
          goto LABEL_14;
        UFG::PedSpawningInfo::RemoveProps(v2);
        v6 = v4->m_pSceneObj;
        if ( v6->mpParent )
          UFG::SceneObjectProperties::DeactivateDeferred(v6);
        else
          UFG::SimObject::Destroy(v4);
      }
      else
      {
        UFG::PedSpawningInfo::MakeCompletelyInactive(v2);
      }
      if ( v1->vfptr )
        UFG::TrueCrowdSet::Instance::RemoveProxyReference(
          (UFG::TrueCrowdSet::Instance *)v1,
          (UFG::PedSpawningInfo *)((char *)v1 - 360));
      v1->vfptr = 0i64;
      LODWORD(v1->m_SafePointerList.mNode.mPrev) = 0;
    }
LABEL_14:
    ++v2;
    ++v1;
    --v3;
  }
  while ( v3 );
}

// File Line: 4446
// RVA: 0x40A770
void __fastcall UFG::PedSpawnManager::DeleteAmbientPedsFromNISBoundingVolume(UFG::PedSpawnManager *this, UFG::qVector3 *aabbMin, UFG::qVector3 *aabbMax)
{
  float v3; // xmm6_4
  float v4; // xmm7_4
  UFG::qVector3 *v5; // rbp
  UFG::qVector3 *v6; // r14
  float *v7; // rbx
  signed __int64 v8; // r15
  float v9; // xmm8_4
  float v10; // xmm9_4
  float v11; // xmm10_4
  float v12; // xmm11_4
  UFG::SimObject *v13; // rdi
  UFG::SimComponent *v14; // rcx
  float *v15; // rax
  float v16; // xmm1_4
  float v17; // xmm0_4
  float v18; // xmm1_4
  float v19; // xmm0_4
  float v20; // xmm1_4
  UFG::SceneObjectProperties *v21; // rcx
  float v22; // xmm0_4
  float v23; // xmm0_4
  UFG::qVector3 max; // [rsp+20h] [rbp-98h]
  UFG::qVector3 min; // [rsp+30h] [rbp-88h]

  v3 = aabbMin->y;
  v4 = aabbMin->z;
  v5 = aabbMax;
  v6 = aabbMin;
  v7 = &this->mAmbientPed[0].mCurrentLocation.z;
  v8 = 260i64;
  v9 = aabbMax->x;
  v10 = aabbMax->y;
  v11 = aabbMax->z;
  v12 = aabbMin->x;
  do
  {
    if ( *((_DWORD *)v7 - 8) != 1 )
      goto LABEL_25;
    v13 = (UFG::SimObject *)*((_QWORD *)v7 - 73);
    if ( v13 )
    {
      v14 = v13->m_Components.p[14].m_pComponent;
      if ( !v14 )
        goto LABEL_25;
      v15 = (float *)v14[22].m_SafePointerList.mNode.mNext;
      if ( !v15 )
        goto LABEL_25;
      v16 = v15[33];
      min.x = v15[32];
      v17 = v15[34];
      min.y = v16;
      v18 = v15[35];
      min.z = v17;
      v19 = v15[36];
      max.x = v18;
      v20 = v15[37];
      max.y = v19;
      max.z = v20;
      TransformAABB((UFG::qMatrix44 *)&v14[20], &min, &max);
      if ( v12 > max.x || v9 < min.x || v3 > max.y || v10 < min.y || v4 > max.z || v11 < min.z )
        goto LABEL_25;
      UFG::PedSpawningInfo::RemoveProps((UFG::PedSpawningInfo *)(v7 - 194));
      v21 = v13->m_pSceneObj;
      if ( v21->mpParent )
        UFG::SceneObjectProperties::DeactivateDeferred(v21);
      else
        UFG::SimObject::Destroy(v13);
    }
    else
    {
      v22 = *(v7 - 2);
      if ( v22 < v6->x )
        goto LABEL_25;
      if ( v22 > v5->x )
        goto LABEL_25;
      v23 = *(v7 - 1);
      if ( v23 < v6->y || v23 > v5->y || *v7 < v6->z || *v7 > v5->z )
        goto LABEL_25;
      UFG::PedSpawningInfo::MakeCompletelyInactive((UFG::PedSpawningInfo *)(v7 - 194));
    }
    if ( *((_QWORD *)v7 - 52) )
      UFG::TrueCrowdSet::Instance::RemoveProxyReference(
        (UFG::TrueCrowdSet::Instance *)(v7 - 104),
        (UFG::PedSpawningInfo *)(v7 - 194));
    *(v7 - 102) = 0.0;
    *((_QWORD *)v7 - 52) = 0i64;
LABEL_25:
    v7 += 206;
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
UFG::SimObject *__fastcall UFG::PedSpawnManager::GetAmbientPedForVehicle(UFG::PedSpawnManager *this, UFG::qPropertyList *classPriorities, UFG::qPropertyList *classExclusions, UFG::PedSpawningInfo **newPedInfo)
{
  UFG::PedSpawningInfo **v4; // r12
  UFG::qPropertyList *v5; // rsi
  UFG::qPropertyList *v6; // rbp
  UFG::PedSpawnManager *v7; // r15
  UFG::SimComponent *v8; // rdi
  UFG::PedSpawningInfo *v9; // rax
  UFG::PedSpawningInfo *v10; // rbx
  UFG::SimObject *v11; // rsi
  UFG::ObjectResourceManager *v12; // rax
  UFG::qPropertySet *pParentPropertySet; // rsi
  UFG::eHowSpawned v14; // ebp
  UFG::OnlineManager *v15; // rax
  unsigned int v16; // eax
  UFG::qString *v17; // rax
  UFG::SceneObjectProperties *v18; // rbx
  UFG::qSafePointer<UFG::SpawnZone,UFG::SpawnZone> *v19; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SpawnZone>,UFG::qSafePointerNodeList> *v20; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SpawnZone>,UFG::qSafePointerNodeList> *v21; // rcx
  UFG::SpawnRegion *v22; // r14
  unsigned int v23; // ebp
  UFG::SpawnZone *i; // rbx
  UFG::SpawnRegion *v25; // rax
  UFG::SimObject *v26; // rdx
  Creature *v27; // rcx
  UFG::SimComponentHolder *v28; // rax
  UFG::InventoryComponent *v29; // rbx
  UFG::qSymbol objName; // [rsp+40h] [rbp-68h]
  UFG::SpawnInfoInterface::SpawnPriority pPriority; // [rsp+44h] [rbp-64h]
  UFG::qSymbol v33; // [rsp+48h] [rbp-60h]
  __int64 v34; // [rsp+50h] [rbp-58h]
  UFG::qString result; // [rsp+58h] [rbp-50h]

  v34 = -2i64;
  v4 = newPedInfo;
  v5 = classExclusions;
  v6 = classPriorities;
  v7 = this;
  v8 = 0i64;
  v9 = (UFG::PedSpawningInfo *)UFG::PedSpawnManager::FindPedToRepurposeForVehicle(
                                 this,
                                 classPriorities,
                                 classExclusions);
  v10 = v9;
  if ( v9 && !v9->mCharacterOccupantComponent.m_pSimComponent )
  {
    UFG::PedSpawnManager::ChangeStatusToActive(v7, v9);
    v10->mSpawnTime = UFG::PedSpawnManager::msElapsedTotal;
    v11 = v10->mSimObjectPtr.m_pPointer;
    UFG::GroupComponent::MakeSingle(v10->mGroupComponent, 1);
    UFG::doing_reinit = 1;
    UFG::SimObjectUtility::ReinitializeSimObject(v11, 1, 0);
    UFG::doing_reinit = 0;
    goto LABEL_21;
  }
  v12 = UFG::ObjectResourceManager::Instance();
  pParentPropertySet = UFG::ObjectResourceManager::GetAvailableDriver(v12, v6, v5);
  if ( pParentPropertySet )
  {
    ++v7->mNetRecycleCounter;
    objName.mUID = -1;
    v14 = v7->mSpawningModeNow;
    v7->mSpawningModeNow = 2;
    UFG::PedSpawnManager::msZoneDoingSpawnNow = 0i64;
    v15 = UFG::OnlineManager::Instance();
    v16 = UFG::OnlineManager::GetOnlineIdStringHash32(v15);
    v17 = UFG::qString::FormatEx(&result, "CreatedForVehicle:Spawn_%d_%d", v16, v7->mNetRecycleCounter);
    objName.mUID = UFG::qSymbol::create_from_string(&v33, v17->mData)->mUID;
    UFG::qString::~qString(&result);
    v18 = UFG::SceneObjectProperties::Create(&objName, 0i64, pParentPropertySet);
    UFG::SpawnInfoInterface::GetSpawnPriority(pParentPropertySet, &pPriority);
    v11 = UFG::SpawnInfoInterface::ActivateObject(v18, pPriority, 0i64, 0i64, pParentPropertySet, 3u, 0);
    v19 = &UFG::PedSpawnManager::msLastRegisteredPedInfo->mCreationSpawnZone;
    if ( UFG::PedSpawnManager::msLastRegisteredPedInfo->mCreationSpawnZone.m_pPointer )
    {
      v20 = v19->mPrev;
      v21 = UFG::PedSpawnManager::msLastRegisteredPedInfo->mCreationSpawnZone.mNext;
      v20->mNext = v21;
      v21->mPrev = v20;
      v19->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SpawnZone>,UFG::qSafePointerNodeList> *)&v19->mPrev;
      v19->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SpawnZone>,UFG::qSafePointerNodeList> *)&v19->mPrev;
    }
    v19->m_pPointer = 0i64;
    v7->mSpawningModeNow = v14;
    if ( v4 )
      *v4 = UFG::PedSpawnManager::msLastRegisteredPedInfo;
    goto LABEL_23;
  }
  v22 = 0i64;
  v23 = 0;
  for ( i = (UFG::SpawnZone *)&UFG::PedSpawnManager::msActiveZoneList.mNode.mNext[-2].mNext;
        ;
        i = (UFG::SpawnZone *)&i->mNext[-2].mNext )
  {
    if ( i == (UFG::SpawnZone *)((char *)&UFG::PedSpawnManager::msActiveZoneList - 24) )
      return 0i64;
    v25 = i->mpRegion;
    if ( v25 )
    {
      if ( v25 != v22 )
        break;
    }
LABEL_16:
    ++v23;
  }
  v22 = i->mpRegion;
  if ( v23 >= 0xA )
    return 0i64;
  UFG::PedSpawnManager::msZoneDoingSpawnNow = i;
  v7->mSpawningModeNow = 1;
  v11 = UFG::SpawnRegion::Spawn(i->mpRegion, 0, 0i64, 1);
  if ( !v11 )
  {
    UFG::PedSpawnManager::msZoneDoingSpawnNow = 0i64;
    goto LABEL_16;
  }
  v10 = UFG::PedSpawnManager::msLastRegisteredPedInfo;
  UFG::GroupComponent::MakeSingle(UFG::PedSpawnManager::msLastRegisteredPedInfo->mGroupComponent, 1);
  UFG::PedSpawnManager::ChangeStatusToActive(v7, v10);
  v26 = v10->mSimObjectPtr.m_pPointer;
  if ( v26 )
    v8 = v26->m_Components.p[9].m_pComponent;
  v27 = *(Creature **)&v8[2].m_TypeUID;
  if ( v27 )
    Creature::DestroyAllAttachments(v27, v26, 0);
LABEL_21:
  if ( v4 )
    *v4 = v10;
LABEL_23:
  if ( v11 )
  {
    v28 = v11->m_Components.p;
    v29 = (UFG::InventoryComponent *)v28[39].m_pComponent;
    if ( v29 )
    {
      UFG::InventoryComponent::UnEquip((UFG::InventoryComponent *)v28[39].m_pComponent, 0, 1);
      UFG::InventoryComponent::UnEquip(v29, eINVENTORY_EQUIP_SLOT_LEFT_HAND, 1);
    }
  }
  return v11;
}

// File Line: 4722
// RVA: 0x414B60
void __fastcall UFG::PedSpawnManager::RegisterPed(UFG::PedSpawnManager *this, UFG::SimObjectCharacter *pedToRegister, UFG::qPropertySet *pArchetypePropSet, UFG::qPropertySet *pInstancePropertySet, bool IsAmbientRegionPed, bool canSuspend, bool called_from_skookum)
{
  UFG::qPropertySet *v7; // rdi
  UFG::qPropertySet *v8; // r15
  UFG::SimObjectCharacter *v9; // rbp
  UFG::PedSpawnManager *v10; // rsi
  UFG::qPropertySet *v11; // rax
  UFG::SimComponent *v12; // r14
  UFG::SimObjectCharacterPropertiesComponent *v13; // rax
  char v14; // r12
  UFG::PedSpawningInfo *v15; // rbx
  UFG::PedSpawningInfo::eActiveStatus v16; // edx
  UFG::SpawnZone *v17; // r8
  UFG::qSafePointer<UFG::SpawnZone,UFG::SpawnZone> *v18; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SpawnZone>,UFG::qSafePointerNodeList> *v19; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SpawnZone>,UFG::qSafePointerNodeList> *v20; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SpawnZone>,UFG::qSafePointerNodeList> *v21; // rax
  unsigned int v22; // eax
  __int64 v23; // r8
  UFG::AnimationLODComponent *v24; // rcx
  UFG::qPropertySet *v25; // rcx
  bool *v26; // rax
  bool v27; // di
  unsigned int v28; // edi
  __int64 v29; // rsi
  UFG::SceneObjectProperties *v30; // rcx
  UFG::qPropertySet *v31; // rax
  unsigned int v32; // ebx
  UFG::PedSpawningInfo::eActiveStatus v33; // edx
  UFG::SpawnZone *v34; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SpawnZone>,UFG::qSafePointerNodeList> *v35; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SpawnZone>,UFG::qSafePointerNodeList> *v36; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SpawnZone>,UFG::qSafePointerNodeList> *v37; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SpawnZone>,UFG::qSafePointerNodeList> *v38; // rax
  unsigned int v39; // eax
  bool *v40; // rax
  bool v41; // bl
  unsigned int *v42; // rax
  bool *v43; // rax
  unsigned int v44; // edi
  UFG::SimObjectModifier v45; // [rsp+38h] [rbp-50h]
  UFG::PedSpawnManager *v46; // [rsp+90h] [rbp+8h]

  v46 = this;
  v7 = pInstancePropertySet;
  v8 = pArchetypePropSet;
  v9 = pedToRegister;
  v10 = this;
  if ( pInstancePropertySet )
  {
    v11 = (UFG::qPropertySet *)UFG::qPropertySet::GetParentFromIdx(pInstancePropertySet, 0);
    if ( v8 != v11 )
    {
      v7 = v11;
      UFG::qPropertySet::GetParentFromIdx(v11, 0);
    }
  }
  v12 = 0i64;
  if ( v9 )
    v13 = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectCharacterPropertiesComponent>((UFG::SimObjectCVBase *)&v9->vfptr);
  else
    v13 = 0i64;
  v14 = (LOBYTE(v13->m_Flags) >> 1) & 1;
  UFG::PedSpawnManager::msLastRegistered = v9;
  if ( !IsAmbientRegionPed )
  {
    if ( UFG::PedSpawnManager::msScriptedCount[0] <= 0 )
      return;
    v15 = (UFG::PedSpawningInfo *)&UFG::PedSpawnManager::msScriptedList[0].mNode.mNext[-4];
    UFG::PedSpawningInfo::SetSimObjectPtr(
      (UFG::PedSpawningInfo *)&UFG::PedSpawnManager::msScriptedList[0].mNode.mNext[-4],
      v9);
    UFG::PedSpawningInfo::SetTrueCrowdSignatureFromCurrentSimObject(v15);
    UFG::PedSpawningInfo::SetPropListFromCurrentSimObject(v15);
    v16 = 1;
    if ( v14 )
      v16 = 3;
    UFG::PedSpawningInfo::SetActiveStatus(v15, v16);
    if ( UFG::PedSpawnManager::msScriptedStatusCheckEnable || called_from_skookum )
      goto LABEL_18;
    if ( v15->mActiveStatus == 1 )
    {
      UFG::SimObject::Suspend(v15->mSimObjectPtr.m_pPointer);
      v15->mTeleportOnResumeRequired = 0;
    }
    else if ( v15->mActiveStatus != 2 )
    {
LABEL_18:
      v15->mCanSuspendScripted = canSuspend == 0;
      v15->mTeleportOnResumeRequired = 0;
      v15->mSpawnTime = UFG::PedSpawnManager::msElapsedTotal;
      v15->mIsDead = 0;
      v15->mHowSpawned = v10->mSpawningModeNow;
      v17 = UFG::PedSpawnManager::msZoneDoingSpawnNow;
      v18 = &v15->mCreationSpawnZone;
      if ( v15->mCreationSpawnZone.m_pPointer )
      {
        v19 = v18->mPrev;
        v20 = v15->mCreationSpawnZone.mNext;
        v19->mNext = v20;
        v20->mPrev = v19;
        v18->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SpawnZone>,UFG::qSafePointerNodeList> *)&v18->mPrev;
        v15->mCreationSpawnZone.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SpawnZone>,UFG::qSafePointerNodeList> *)&v15->mCreationSpawnZone.mPrev;
      }
      v15->mCreationSpawnZone.m_pPointer = v17;
      if ( v17 )
      {
        v21 = v17->m_SafePointerList.mNode.mPrev;
        v21->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SpawnZone>,UFG::qSafePointerNodeList> *)&v18->mPrev;
        v18->mPrev = v21;
        v15->mCreationSpawnZone.mNext = &v17->m_SafePointerList.mNode;
        v17->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SpawnZone>,UFG::qSafePointerNodeList> *)&v18->mPrev;
      }
      if ( v8 )
        v22 = v8->mName.mUID;
      else
        v22 = UFG::gNullQSymbol.mUID;
      v15->mArchetypePropSetSymbol.mUID = v22;
      if ( v7 )
      {
        v15->mPropSetSymbol.mUID = v7->mName.mUID;
        if ( UFG::SpawnInfoInterface::ShouldLockActive(v7) )
        {
          UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&v7->mName);
          v23 = (unsigned int)v15->mPedIndex;
          UFG::qPrintChannel::Print(&UFG::gPrintChannel_HK_Spawning, "Index %d - Locking scripted ped %s active!\n");
          v15->mCanSuspendScripted |= 2u;
        }
        if ( v9 )
        {
          v24 = (UFG::AnimationLODComponent *)v9->m_Components.p[13].m_pComponent;
          if ( v24 )
            UFG::AnimationLODComponent::SetExtendedLOD(v24, 1);
        }
        v25 = v7;
      }
      else
      {
        v15->mPropSetSymbol.mUID = v8->mName.mUID;
        v25 = v8;
      }
      v26 = UFG::qPropertySet::Get<bool>(v25, (UFG::qSymbol *)&qSymbol_AllowedToUseCrosswalks.mUID, DEPTH_RECURSE);
      if ( v26 )
        v27 = *v26;
      else
        v27 = 0;
      UFG::GroupComponent::Reset(v15->mGroupComponent);
      v15->mProxyAIComponent->mAILCanUseCrosswalks = v27;
      if ( v9 )
        v12 = v9->m_Components.p[22].m_pComponent;
      HIBYTE(v12[20].m_BoundComponentHandles.mNode.mPrev) = v27;
      UFG::PedSpawnManager::msLastRegisteredPedInfo = v15;
      v15->mLifetimeInstanceNameSymbol.mUID = UFG::qSymbol::qSymbol(
                                                (UFG::qWiseSymbol *)&IsAmbientRegionPed,
                                                v9->mNode.mUID)->mUID;
      if ( (v9->m_Flags >> 14) & 1 )
        v28 = 48;
      else
        v28 = -1;
      UFG::SimObjectModifier::SimObjectModifier(&v45, (UFG::SimObject *)&v9->vfptr, 1);
      UFG::SimObjectModifier::AttachComponent(&v45, (UFG::SimComponent *)&v15->vfptr, v28);
      UFG::SimObjectModifier::Close(&v45);
      UFG::SimObjectModifier::~SimObjectModifier(&v45);
      v15->m_Flags &= 0xFFF7u;
      return;
    }
    v15->mSuspendedTime = 0.0;
    UFG::PedSpawningInfo::SetActiveStatus(v15, NormalSuspend);
    goto LABEL_18;
  }
  if ( UFG::PedSpawnManager::msAmbientCount[0] > 0 )
  {
    v29 = qword_1423DEF68 - 64;
    v30 = v9->m_pSceneObj;
    v31 = v30->mpWritableProperties;
    if ( !v31 )
      v31 = v30->mpConstProperties;
    v32 = v31->mName.mUID;
    UFG::PedSpawningInfo::SetSimObjectPtr((UFG::PedSpawningInfo *)(qword_1423DEF68 - 64), v9);
    UFG::PedSpawningInfo::SetTrueCrowdSignatureFromCurrentSimObject((UFG::PedSpawningInfo *)v29);
    UFG::PedSpawningInfo::SetPropListFromCurrentSimObject((UFG::PedSpawningInfo *)v29);
    v33 = 1;
    if ( v14 )
      v33 = 3;
    UFG::PedSpawningInfo::SetActiveStatus((UFG::PedSpawningInfo *)v29, v33);
    *(_DWORD *)(v29 + 676) = 0;
    *(_BYTE *)(v29 + 764) = 0;
    *(float *)(v29 + 760) = UFG::PedSpawnManager::msElapsedTotal;
    *(_BYTE *)(v29 + 348) = 0;
    *(_DWORD *)(v29 + 744) = v46->mSpawningModeNow;
    v34 = UFG::PedSpawnManager::msZoneDoingSpawnNow;
    v35 = (UFG::qNode<UFG::qSafePointerBase<UFG::SpawnZone>,UFG::qSafePointerNodeList> *)(v29 + 144);
    if ( *(_QWORD *)(v29 + 160) )
    {
      v36 = v35->mPrev;
      v37 = *(UFG::qNode<UFG::qSafePointerBase<UFG::SpawnZone>,UFG::qSafePointerNodeList> **)(v29 + 152);
      v36->mNext = v37;
      v37->mPrev = v36;
      v35->mPrev = v35;
      *(_QWORD *)(v29 + 152) = v29 + 144;
    }
    *(_QWORD *)(v29 + 160) = v34;
    if ( v34 )
    {
      v38 = v34->m_SafePointerList.mNode.mPrev;
      v38->mNext = v35;
      v35->mPrev = v38;
      *(_QWORD *)(v29 + 152) = (char *)v34 + 8;
      v34->m_SafePointerList.mNode.mPrev = v35;
    }
    *(_DWORD *)(v29 + 644) = v32;
    UFG::GroupComponent::Reset(*(UFG::GroupComponent **)(v29 + 256));
    if ( v8 )
      v39 = v8->mName.mUID;
    else
      v39 = UFG::gNullQSymbol.mUID;
    *(_DWORD *)(v29 + 648) = v39;
    if ( v46->mSpawningModeNow == 2 && v7 )
    {
      *(_DWORD *)(v29 + 644) = v7->mName.mUID;
      v40 = UFG::qPropertySet::Get<bool>(v7, (UFG::qSymbol *)&qSymbol_AllowedToUseCrosswalks.mUID, DEPTH_RECURSE);
      if ( v40 )
        v41 = *v40;
      else
        v41 = 0;
      v42 = UFG::qPropertySet::Get<unsigned long>(v7, (UFG::qSymbol *)&qSymbol_ThugBlip.mUID, DEPTH_RECURSE);
      if ( v42 )
        LODWORD(v12) = *v42;
      *(_DWORD *)(v29 + 740) = (_DWORD)v12;
      if ( (_DWORD)v12 )
        UFG::SimObjectUtility::AttachHudSymbol(
          *(UFG::SimObject **)(v29 + 192),
          "enemy_noncombat",
          0,
          0.0,
          &customWorldMapCaption);
    }
    else
    {
      *(_DWORD *)(v29 + 644) = v8->mName.mUID;
      v43 = UFG::qPropertySet::Get<bool>(v8, (UFG::qSymbol *)&qSymbol_AllowedToUseCrosswalks.mUID, DEPTH_RECURSE);
      if ( v43 )
        v41 = *v43;
      else
        v41 = 0;
    }
    *(_BYTE *)(*(_QWORD *)(v29 + 248) + 88i64) = v41;
    HIBYTE(v9->m_Components.p[22].m_pComponent[20].m_BoundComponentHandles.mNode.mPrev) = v41;
    UFG::PedSpawnManager::msLastRegisteredPedInfo = (UFG::PedSpawningInfo *)v29;
    *(UFG::qWiseSymbol *)(v29 + 352) = (UFG::qWiseSymbol)UFG::qSymbol::qSymbol(
                                                           (UFG::qWiseSymbol *)&IsAmbientRegionPed,
                                                           v9->mNode.mUID)->mUID;
    if ( (v9->m_Flags >> 14) & 1 )
      v44 = 48;
    else
      v44 = -1;
    UFG::SimObjectModifier::SimObjectModifier(&v45, (UFG::SimObject *)&v9->vfptr, 1);
    UFG::SimObjectModifier::AttachComponent(&v45, (UFG::SimComponent *)v29, v44);
    UFG::SimObjectModifier::Close(&v45);
    UFG::SimObjectModifier::~SimObjectModifier(&v45);
    *(_WORD *)(v29 + 32) &= 0xFFF7u;
  }
}

// File Line: 4978
// RVA: 0x416AA0
char __fastcall UFG::PedSpawnManager::SetSuspendOption(UFG::PedSpawnManager *this, UFG::SimObject *pedSimObj, UFG::PedSpawningInfo::eSuspendAction suspendAction)
{
  UFG::PedSpawningInfo::eSuspendAction v3; // ebx
  unsigned __int16 v4; // cx
  UFG::PedSpawningInfo *v5; // rcx
  UFG::PedSpawningInfo *v6; // rax

  v3 = suspendAction;
  if ( !pedSimObj )
    return 0;
  v4 = pedSimObj->m_Flags;
  if ( (v4 >> 14) & 1 )
  {
    v5 = (UFG::PedSpawningInfo *)pedSimObj->m_Components.p[48].m_pComponent;
  }
  else
  {
    if ( (v4 & 0x8000u) == 0 )
    {
      if ( (v4 >> 13) & 1 )
        v6 = (UFG::PedSpawningInfo *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                       (UFG::SimObjectGame *)pedSimObj,
                                       UFG::PedSpawningInfo::_TypeUID);
      else
        v6 = (UFG::PedSpawningInfo *)((v4 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                         (UFG::SimObjectGame *)pedSimObj,
                                                         UFG::PedSpawningInfo::_TypeUID) : UFG::SimObject::GetComponentOfType(
                                                                                             pedSimObj,
                                                                                             UFG::PedSpawningInfo::_TypeUID));
    }
    else
    {
      v6 = (UFG::PedSpawningInfo *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                     (UFG::SimObjectGame *)pedSimObj,
                                     UFG::PedSpawningInfo::_TypeUID);
    }
    v5 = v6;
  }
  if ( !v5 || v5->mPedType != 2 )
    return 0;
  v5->mCanSuspendScripted = v3 | v5->mCanSuspendScripted & 0x20;
  return 1;
}

// File Line: 5039
// RVA: 0x4172C0
signed __int64 __fastcall UFG::PedSpawnManager::SpawnPedsInActiveZones(UFG::PedSpawnManager *this, int howManyToSpawn)
{
  int v2; // edi
  UFG::PedSpawnManager *v3; // rbx
  int v4; // er13
  int v5; // esi
  signed __int64 v6; // rax
  __int64 v7; // rbp
  UFG::SpawnZone *v8; // r14
  CullResults *v9; // r8
  float v10; // xmm1_4
  signed int v11; // er12
  UFG::GroupManager *v12; // rax
  signed int v13; // er15
  bool v14; // r13
  int v15; // eax
  __int64 v16; // rbx
  __int64 v17; // rdi
  UFG::SimObject *v18; // rcx
  UFG::qPropertySet *v19; // rdi
  int v20; // eax
  UFG::PedSpawningInfo *v21; // rax
  float v22; // xmm1_4
  float v23; // xmm2_4
  UFG::SimObject *v24; // rbx
  UFG::InterestPoint *v25; // rsi
  UFG::SimComponent *v26; // rdi
  UFG::InterestPointUserComponent *v27; // rbp
  UFG::allocator::free_link *v28; // rax
  int v29; // er13
  int v30; // ecx
  int v32; // [rsp+30h] [rbp-D8h]
  UFG::qVector3 newPoint; // [rsp+38h] [rbp-D0h]
  UFG::qSymbol skipIntoLabel; // [rsp+48h] [rbp-C0h]
  __int64 v35; // [rsp+50h] [rbp-B8h]
  __int64 v36; // [rsp+58h] [rbp-B0h]
  UFG::allocator::free_link *v37; // [rsp+60h] [rbp-A8h]
  UFG::qMatrix44 outputMatrix; // [rsp+70h] [rbp-98h]
  UFG::PedSpawnManager *v39; // [rsp+110h] [rbp+8h]
  int v40; // [rsp+118h] [rbp+10h]
  bool v41; // [rsp+120h] [rbp+18h]
  int v42; // [rsp+128h] [rbp+20h]

  v40 = howManyToSpawn;
  v39 = this;
  v36 = -2i64;
  v2 = howManyToSpawn;
  v3 = this;
  if ( UFG::PedSpawnManager::msNumValidTopUpZones > 0 )
  {
    v4 = UFG::qRandom(UFG::PedSpawnManager::msNumValidTopUpZones, &UFG::qDefaultSeed);
    v32 = v4;
    v5 = 0;
    v42 = 0;
    if ( v2 > 0 )
    {
      v6 = 5368709120i64;
      do
      {
        v7 = v4;
        v35 = v4;
        v8 = UFG::PedSpawnManager::msValidTopUpZones[v4];
        if ( !v8 )
          break;
        if ( !v8->mIsThugZone
          || !UFG::PedSpawnManager::ThugZoneDisabled(
                v3,
                *(UFG::SpawnZone **)((char *)&UFG::PedSpawnManager::msValidTopUpZones[v4 - 671088640] + v6)) )
        {
          v8->mHasBeenActivated = 1;
          v41 = 0;
          v9 = v8->mCullResults;
          if ( v9 && (gMainCullIndex < 0 || v9->mViewResult[gMainCullIndex] <= 1u) )
          {
            if ( gMainCullIndex >= 6 )
              v10 = 0.0;
            else
              v10 = v9->mDistance[gMainCullIndex];
            v41 = (float)(UFG::PedSpawnManager::msWorkingFullyActiveDistance * 0.75) > v10;
          }
          v11 = 1;
          if ( UFG::SpawnRegion::IsGroupsAllowed(v8->mpRegion) )
          {
            v12 = UFG::GroupManager::GetInstance();
            v11 = 1 - (unsigned __int64)UFG::GroupManager::GetNumGroupMembersToSpawn(v12, 1);
          }
          v13 = 0;
          v14 = v41;
          do
          {
            if ( 260 - UFG::PedSpawnManager::msAmbientCount[0] >= 245 )
            {
              v15 = UFG::PedSpawnManager::FindPedsToRepurpose(v3, -1, 1 - v13, v14);
              v16 = 0i64;
              v17 = v15;
              if ( v15 > 0 )
              {
                do
                {
                  v18 = UFG::PedSpawnManager::mNewRepurposeList[v16]->mSimObjectPtr.m_pPointer;
                  if ( v18 )
                  {
                    if ( v18->m_pSceneObj->mpParent )
                      UFG::SceneObjectProperties::DeactivateDeferred(v18->m_pSceneObj);
                    else
                      UFG::SimObject::Destroy(v18);
                  }
                  ++v16;
                }
                while ( v16 < v17 );
                v14 = v41;
              }
              if ( 260 - UFG::PedSpawnManager::msAmbientCount[0] >= 245 )
                break;
            }
            UFG::SpawnZone::CalcSpawnPoint(v8, &newPoint);
            v19 = UFG::SpawnRegion::GetSpawnableResource(v8->mpRegion, 1, &newPoint);
            if ( v19 )
            {
              UFG::PedSpawnManager::msZoneDoingSpawnNow = v8;
              v20 = 260
                  - UFG::PedSpawnManager::msAmbientCount[0]
                  + 120
                  - UFG::PedSpawnManager::msScriptedCount[0]
                  - UFG::gMaxTotalFullSimPeds;
              if ( 260 - UFG::PedSpawnManager::msAmbientCount[0] - UFG::gMaxAmbientSimObjects > v20 )
                v20 = 260 - UFG::PedSpawnManager::msAmbientCount[0] - UFG::gMaxAmbientSimObjects;
              if ( v20 + 1 <= 0 )
              {
                if ( UFG::SpawnRegion::Spawn(v8->mpRegion, 1, &newPoint, 0) )
                {
                  v21 = UFG::PedSpawnManager::msLastRegisteredPedInfo;
                  v22 = newPoint.y;
                  v23 = newPoint.z;
                  UFG::PedSpawnManager::msLastRegisteredPedInfo->mCurrentLocation.x = newPoint.x;
                  v21->mCurrentLocation.y = v22;
                  v21->mCurrentLocation.z = v23;
                  if ( v11 > 0
                    && !UFG::PedSpawnManager::msLastRegisteredPedInfo->mCharacterOccupantComponent.m_pSimComponent )
                  {
                    v24 = UFG::PedSpawnManager::msLastRegisteredPedInfo->mSimObjectPtr.m_pPointer;
                    v25 = UFG::SpawnRegion::GetInterestPoint(
                            v8->mpRegion,
                            &newPoint,
                            v19,
                            v13 + 1,
                            UFG::PedSpawnManager::msLastRegisteredPedInfo->mSimObjectPtr.m_pPointer);
                    if ( v25 )
                    {
                      v26 = UFG::SimObject::GetComponentOfType(v24, UFG::ActiveAIEntityComponent::_TypeUID);
                      v27 = (UFG::InterestPointUserComponent *)UFG::SimObject::GetComponentOfType(
                                                                 v24,
                                                                 UFG::InterestPointUserComponent::_TypeUID);
                      if ( v27 )
                      {
                        if ( v26 )
                        {
                          --v11;
                          UFG::GetInterestPointUpRightMatrix(v25, &outputMatrix);
                          v28 = UFG::qMalloc(0x90ui64, "TeleportEvent", 0i64);
                          v37 = v28;
                          if ( v28 )
                            UFG::TeleportEvent::TeleportEvent(
                              (UFG::TeleportEvent *)v28,
                              &outputMatrix,
                              v24->mNode.mUID,
                              0,
                              UFG::TeleportEvent::m_Name,
                              0);
                          UFG::EventDispatcher::DispatchEvent(&UFG::EventDispatcher::mInstance, (UFG::Event *)v28);
                          skipIntoLabel.mUID = -1;
                          UFG::InterestPointUserComponent::UsePOI(v27, v25, ePOIUseType_Script, &skipIntoLabel);
                        }
                      }
                    }
                  }
                }
              }
              UFG::PedSpawnManager::msZoneDoingSpawnNow = 0i64;
            }
            ++v13;
            v3 = v39;
          }
          while ( v13 < 1 );
          v4 = v32;
          v3 = v39;
          v5 = v42;
          v7 = v35;
          v2 = v40;
        }
        v6 = 5368709120i64;
        UFG::PedSpawnManager::msValidTopUpZones[v7] = 0i64;
        v8->mTimeStamp = UFG::PedSpawnManager::msElapsedTotal;
        v42 = ++v5;
        v29 = v4 + 1;
        v30 = 0;
        if ( v29 < UFG::PedSpawnManager::msNumValidTopUpZones )
          v30 = v29;
        v4 = v30;
        v32 = v30;
      }
      while ( v5 < v2 );
    }
  }
  return 1i64;
}

// File Line: 5079
// RVA: 0x40DD00
char __fastcall UFG::PedSpawnManager::IsPedValidForSet(UFG::PedSpawnManager *this, int indexOfRequiredSpawnSet, UFG::PedSpawningInfo *pedInfo)
{
  __int64 v3; // rbx
  UFG::PedSpawnManager *v4; // rdi
  UFG::qSymbol *v5; // rax
  UFG::qPropertySet *v6; // rax
  unsigned int v7; // edx
  unsigned int v8; // er8
  UFG::qPropertySet **v9; // rcx
  UFG::qSymbol result; // [rsp+48h] [rbp+20h]

  v3 = indexOfRequiredSpawnSet;
  v4 = this;
  v5 = UFG::PedSpawningInfo::GetArchetypePropertySetName(pedInfo, &result);
  v6 = UFG::PropertySetManager::FindPropertySet(v5);
  if ( !v6 )
    return 0;
  v7 = 0;
  v8 = v4->mActiveSpawnSets[v3].mSpawnInfoArray.size;
  if ( !v8 )
    return 0;
  v9 = v4->mActiveSpawnSets[v3].mSpawnInfoArray.p;
  while ( v6 != *v9 )
  {
    ++v7;
    ++v9;
    if ( v7 >= v8 )
      return 0;
  }
  return 1;
}

// File Line: 5099
// RVA: 0x40E0C0
bool __fastcall UFG::PedSpawnManager::IsValidPedForRepurpose(UFG::PedSpawnManager *this, UFG::PedSpawningInfo *pedInfo, bool isHighPriority, float *dist)
{
  UFG::PedSpawningInfo::eActiveStatus v4; // eax
  bool result; // al
  float v6; // xmm1_4
  float v7; // xmm2_4

  *dist = UFG::PedSpawnManager::msZoneActivateDist;
  v4 = pedInfo->mActiveStatus;
  if ( v4 == ExtraLowPower )
  {
    *dist = pedInfo->mDistInCameraSpace;
    if ( pedInfo->mCulledTime > 3.0 || isHighPriority )
      return 1;
    return 0;
  }
  if ( v4 != 3 || pedInfo->mCulledTime <= 1.0 )
    return 0;
  v6 = pedInfo->mDistInCameraSpace;
  *dist = v6;
  if ( isHighPriority )
    v7 = FLOAT_0_44999999;
  else
    v7 = FLOAT_0_69999999;
  if ( pedInfo->mCreationSpawnZone.m_pPointer && v6 <= (float)(UFG::PedSpawnManager::msWorkingFullyActiveDistance * v7) )
  {
    result = 0;
    *dist = v6 * 0.5;
  }
  else
  {
    result = 1;
    *dist = v6 * 0.5;
  }
  return result;
}

// File Line: 5121
// RVA: 0x40C5D0
void __fastcall UFG::PedSpawnManager::GetNewNearestFromArray(UFG::PedSpawnManager *this, UFG::PedSpawningInfo **arrayOfInfo, unsigned int *index, float *dist, unsigned int how_many_needed)
{
  unsigned int v5; // ecx
  signed __int64 v6; // rsi
  unsigned int v7; // er11
  UFG::PedSpawningInfo **v8; // r10
  float v9; // xmm0_4
  float v10; // xmm0_4
  float v11; // xmm0_4
  float v12; // xmm0_4
  UFG::PedSpawningInfo **v13; // rdx
  float v14; // xmm0_4

  v5 = 0;
  *dist = 3.4028235e38;
  v6 = 0i64;
  if ( (signed int)how_many_needed >= 4 )
  {
    v7 = 2;
    v8 = arrayOfInfo + 2;
    v6 = 4i64 * (((how_many_needed - 4) >> 2) + 1);
    do
    {
      v9 = (*(v8 - 2))->mBiasedDist;
      if ( v9 < *dist )
      {
        *dist = v9;
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
__int64 __fastcall UFG::PedSpawnManager::FindPedsToRepurpose(UFG::PedSpawnManager *this, const int indexOfRequiredSpawnSet, unsigned int how_many_needed, bool isHighPriority)
{
  unsigned int v4; // ebx
  unsigned int v5; // esi
  float v6; // xmm6_4
  bool v7; // r13
  int v8; // er12
  UFG::PedSpawnManager *v9; // r15
  UFG::BaseCameraComponent *v10; // rax
  signed __int64 v11; // r14
  UFG::eHowSpawned *v12; // rdi
  UFG::SimObject *v13; // rcx
  UFG::PedSpawningInfo *v14; // rbp
  float v15; // xmm0_4
  __int64 v16; // rax
  float dist; // [rsp+30h] [rbp-58h]
  unsigned int index; // [rsp+34h] [rbp-54h]
  float v20; // [rsp+A0h] [rbp+18h]

  v4 = 0;
  v5 = 5;
  v6 = 0.0;
  v7 = isHighPriority;
  if ( how_many_needed < 5 )
    v5 = how_many_needed;
  v8 = indexOfRequiredSpawnSet;
  v9 = this;
  v20 = 0.0;
  index = 0;
  if ( v5 )
    memset(UFG::PedSpawnManager::mNewRepurposeList, 0, 8i64 * v5);
  v10 = UFG::Director::Get()->mCurrentCamera;
  if ( v10 && v10 != (UFG::BaseCameraComponent *)-80i64 && v5 )
  {
    v11 = 0i64;
    v12 = &v9->mAmbientPed[0].mHowSpawned;
    while ( 1 )
    {
      v13 = (UFG::SimObject *)*((_QWORD *)v12 - 69);
      if ( v13
        && *v12 == 1
        && v13->m_Components.p[27].m_pComponent
        && !UFG::SkookumMgr::IsReferencedByScripts(v13)
        && *((_BYTE *)v12 - 396) != 1
        && (v8 < 0 || UFG::PedSpawnManager::IsPedValidForSet(v9, v8, (UFG::PedSpawningInfo *)(v12 - 186))) )
      {
        v14 = (UFG::PedSpawningInfo *)(v12 - 186);
        dist = 0.0;
        if ( UFG::PedSpawnManager::IsValidPedForRepurpose(v9, (UFG::PedSpawningInfo *)(v12 - 186), v7, &dist) )
        {
          v15 = dist;
          if ( v4 >= v5 )
          {
            if ( dist > v6 )
            {
              UFG::PedSpawnManager::mNewRepurposeList[index] = v14;
              *((float *)v12 + 13) = v15;
              UFG::PedSpawnManager::GetNewNearestFromArray(
                v9,
                UFG::PedSpawnManager::mNewRepurposeList,
                &index,
                &v20,
                v5);
              v6 = v20;
            }
          }
          else
          {
            v16 = v4++;
            UFG::PedSpawnManager::mNewRepurposeList[v16] = v14;
            *((float *)v12 + 13) = v15;
            if ( v4 == v5 )
            {
              UFG::PedSpawnManager::GetNewNearestFromArray(
                v9,
                UFG::PedSpawnManager::mNewRepurposeList,
                &index,
                &v20,
                v5);
              v6 = v20;
              if ( v20 > (float)(UFG::PedSpawnManager::msZoneActivateDist - 1.0) )
                return v4;
            }
          }
        }
      }
      ++v11;
      v12 += 206;
      if ( v11 >= 260 )
        return v4;
    }
  }
  return 0i64;
}

// File Line: 5209
// RVA: 0x40B550
UFG::SimObject **__fastcall UFG::PedSpawnManager::FindPedToRepurposeForVehicle(UFG::PedSpawnManager *this, UFG::qPropertyList *classPriorities, UFG::qPropertyList *classExclusions)
{
  UFG::qPropertyList *v3; // r12
  UFG::qPropertyList *v4; // r15
  UFG::PedSpawnManager *v5; // r13
  signed __int64 v6; // rbp
  signed __int64 v7; // rsi
  UFG::SimObject **v8; // rbx
  UFG::SimObject *v9; // rdi
  int v10; // eax
  UFG::SimObject *v11; // rdi
  int v12; // eax

  v3 = classExclusions;
  v4 = classPriorities;
  v5 = this;
  v6 = 259i64;
  if ( classPriorities )
  {
    v7 = 259i64;
    v8 = &this->mAmbientPed[259].mSimObjectPtr.m_pPointer;
    while ( 1 )
    {
      v9 = *v8;
      if ( *v8 )
      {
        if ( *((_DWORD *)v8 + 138) == 1
          && !v8[16]
          && UFG::VehicleUtility::IsDriverTypeInList(*v8, v4)
          && !UFG::VehicleUtility::IsDriverTypeInList(*v8, v3) )
        {
          if ( v9->m_Components.p[27].m_pComponent )
          {
            if ( !UFG::SkookumMgr::IsReferencedByScripts(v9) && *((_BYTE *)v8 + 156) != 1 )
            {
              v10 = *((_DWORD *)v8 - 6);
              if ( v10 == 2
                || v10 == 3
                && *((float *)v8 - 14) > 1.0
                && (!*(v8 - 4)
                 || *((float *)v8 + 150) > (float)(UFG::PedSpawnManager::msWorkingFullyActiveDistance * 0.44999999)) )
              {
                break;
              }
            }
          }
        }
      }
      v8 -= 103;
      if ( --v7 < 0 )
        goto LABEL_17;
    }
  }
  else
  {
LABEL_17:
    v8 = &v5->mAmbientPed[259].mSimObjectPtr.m_pPointer;
    while ( 1 )
    {
      v11 = *v8;
      if ( *v8 )
      {
        if ( *((_DWORD *)v8 + 138) == 1 && !UFG::VehicleUtility::IsDriverTypeInList(*v8, v3) )
        {
          if ( v11->m_Components.p[27].m_pComponent )
          {
            if ( !UFG::SkookumMgr::IsReferencedByScripts(v11) && !v8[16] && *((_BYTE *)v8 + 156) != 1 )
            {
              v12 = *((_DWORD *)v8 - 6);
              if ( v12 == 2
                || v12 == 3
                && *((float *)v8 - 14) > 1.0
                && (!*(v8 - 4)
                 || *((float *)v8 + 150) > (float)(UFG::PedSpawnManager::msWorkingFullyActiveDistance * 0.44999999)) )
              {
                break;
              }
            }
          }
        }
      }
      v8 -= 103;
      if ( --v6 < 0 )
        return 0i64;
    }
  }
  return v8 - 24;
}

// File Line: 5332
// RVA: 0x414210
void __fastcall UFG::PedSpawnManager::ReducePedsWithSpecificModel(UFG::TrueCrowdModel *model, bool allowForcedRemoval)
{
  bool v2; // si
  UFG::ResourceRequest *v3; // rdi
  int v4; // eax
  __int64 i; // rbx
  UFG::PedSpawningInfo *v6; // rdx
  UFG::SimObject *v7; // rcx
  unsigned int v8; // ecx
  signed __int64 v9; // rbx
  __int64 v10; // r9
  __int64 v11; // rdx
  char *v12; // r8
  UFG::MeshResourceLoader **v13; // rcx
  _QWORD *v14; // rax
  UFG::SimObject *v15; // rcx

  v2 = allowForcedRemoval;
  if ( UFG::gpPedSpawnManager )
  {
    v3 = model->mRequest;
    if ( v3 )
    {
      v4 = v3->mProxies.size - 1;
      for ( i = v4; i >= 0; --i )
      {
        v6 = v3->mProxies.p[i];
        if ( v2 )
        {
          if ( v6->mActiveStatus <= 3u )
          {
LABEL_6:
            v7 = v6->mSimObjectPtr.m_pPointer;
            if ( v7 )
            {
              if ( v7->m_pSceneObj->mpParent )
                UFG::SceneObjectProperties::DeactivateDeferred(v7->m_pSceneObj);
              else
                UFG::SimObject::Destroy(v7);
            }
          }
        }
        else
        {
          switch ( v6->mActiveStatus )
          {
            case 2:
              goto LABEL_6;
            default:
              continue;
          }
        }
      }
      v8 = v3->mInstances.size;
      if ( v8 )
      {
        v9 = 213416i64;
        do
        {
          v10 = v8;
          v11 = 0i64;
          v12 = (char *)UFG::gpPedSpawnManager + v9;
          if ( (signed __int64)v8 > 0 )
          {
            v13 = v3->mInstances.p;
            while ( 1 )
            {
              v14 = (*v13)->mUserContext;
              if ( v14 )
              {
                if ( *((_QWORD *)v12 + 30) == v14[5] )
                  break;
              }
              ++v11;
              ++v13;
              if ( v11 >= v10 )
                goto $LN131;
            }
            if ( v2 )
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
          }
$LN131:
          v8 = v3->mInstances.size;
          if ( !v8 )
            break;
          v9 -= 824i64;
        }
        while ( v9 >= 0 );
      }
    }
  }
}

// File Line: 5479
// RVA: 0x40BAB0
signed __int64 __fastcall UFG::PedSpawnManager::GetActiveZoneFromPoint(UFG::PedSpawnManager *this, UFG::qVector3 *raw_pos, UFG::PedSpawningInfo::eActiveStatus current_status)
{
  float v3; // xmm0_4
  float v4; // xmm1_4
  float v5; // xmm7_4
  float v6; // xmm6_4
  float v7; // xmm0_4
  float v8; // xmm6_4
  signed __int64 result; // rax
  float v10; // xmm2_4
  UFG::qVector3 point; // [rsp+20h] [rbp-38h]

  v3 = raw_pos->z;
  v4 = raw_pos->x;
  v5 = *(float *)&FLOAT_1_0;
  v6 = raw_pos->y;
  point.x = raw_pos->x;
  v7 = v3 + 1.0;
  point.y = v6;
  point.z = v7;
  if ( current_status != 1 )
    v5 = 0.0;
  v8 = (float)((float)((float)(v6 - UFG::PedSpawnManager::msZone_centre.y)
                     * (float)(v6 - UFG::PedSpawnManager::msZone_centre.y))
             + (float)((float)(v4 - UFG::PedSpawnManager::msZone_centre.x)
                     * (float)(v4 - UFG::PedSpawnManager::msZone_centre.x)))
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
      result = (unsigned int)(UFG::PedSpawnManager::msPreferActiveMargin <= v10) + 3;
    }
    else
    {
      result = 3i64;
      if ( UFG::PedSpawnManager::msPreferActiveMargin > v10 )
        result = 1i64;
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
      result = (unsigned int)(result + 1);
    }
  }
  return result;
}

// File Line: 5572
// RVA: 0x40C1E0
signed __int64 __fastcall UFG::PedSpawnManager::GetIdealActiveStatus(UFG::PedSpawnManager *this, UFG::PedSpawningInfo *info)
{
  UFG::PedSpawningInfo::eActiveStatus v2; // ecx
  UFG::PedSpawningInfo *v3; // r8
  UFG::eActiveZoneClass v5; // er9
  UFG::eHowSpawned v6; // edx
  int v7; // ecx
  int v8; // ecx
  float *v9; // rax

  v2 = info->mActiveStatus;
  v3 = info;
  if ( !info->mPhysicsLoadedForLocation )
    return info->mCreationSpawnZone.m_pPointer != 0i64 ? 3 : 0;
  v5 = info->mLocationClassification;
  v6 = FromRegion;
  if ( v5 == 5 )
    return 0i64;
  v7 = v2 - 1;
  if ( v7 )
  {
    v8 = v7 - 1;
    if ( v8 )
    {
      if ( v8 == 1 && v5 > (unsigned int)FromRegion )
      {
        if ( v3->mCulledTime <= 0.0 )
          return (unsigned int)(v3->mIsDead != 0) + 2;
        if ( v3->mHowSpawned == FromRegion && !v3->mCreationSpawnZone.m_pPointer )
        {
          if ( !v3->mIsDead )
            return 0i64;
          goto LABEL_25;
        }
        return 3i64;
      }
      return (unsigned int)v6;
    }
    v6 = 2;
    if ( v5 == Always_Active )
      return FromRegion;
    v9 = (float *)v3->mCreationSpawnZone.m_pPointer;
    if ( !v9 && v3->mCulledTime > 0.0 )
      return 0i64;
    if ( v3->mIsDead )
    {
      if ( v3->mCulledTime > 5.0 && UFG::PedSpawnManager::msNumDeadAmbientPeds > 14 )
      {
LABEL_25:
        ++UFG::PedSpawnManager::msDowngradesThisFrame;
        return 0i64;
      }
      return (unsigned int)v6;
    }
    if ( v3->mCulledTime > 10.0
      && ((float)((float)((float)((float)(v3->mCurrentLocation.y - v9[39]) * (float)(v3->mCurrentLocation.y - v9[39]))
                        + (float)((float)(v3->mCurrentLocation.x - v9[38]) * (float)(v3->mCurrentLocation.x - v9[38])))
                + (float)((float)(v3->mCurrentLocation.z - v9[40]) * (float)(v3->mCurrentLocation.z - v9[40]))) > 400.0
       || v3->mIsNearDeactivatedZones == FromRegion) )
    {
      return 0i64;
    }
  }
  else
  {
    if ( v5 == Always_Active )
      return (unsigned int)v6;
    if ( !v3->mIsDead )
    {
      v6 = 2;
      if ( v5 == FromRegion
        && UFG::PedSpawnManager::msTargetPedCount
         - UFG::PedSpawnManager::msScriptedCount[1]
         - UFG::PedSpawnManager::msAmbientCount[1] > 4 )
      {
        v6 = FromRegion;
      }
      return (unsigned int)v6;
    }
    if ( UFG::PedSpawnManager::msNumDeadAmbientPeds > 24
      || UFG::PedSpawnManager::msNumDeadAmbientPeds > 14 && v3->mCulledTime > 2.0 )
    {
      return 0i64;
    }
    if ( v5 != FromRegion )
      return 3i64;
  }
  return (unsigned int)v6;
}

// File Line: 5781
// RVA: 0x40E570
__int64 __fastcall UFG::PedSpawnManager::MakeRoomForMorePeds(UFG::PedSpawnManager *this, int how_many, bool high_priority)
{
  int v3; // eax
  __int64 v4; // rbx
  __int64 v5; // rsi
  UFG::SimObject *v6; // rcx

  v3 = UFG::PedSpawnManager::FindPedsToRepurpose(this, -1, how_many, high_priority);
  v4 = 0i64;
  v5 = v3;
  if ( v3 > 0 )
  {
    do
    {
      v6 = UFG::PedSpawnManager::mNewRepurposeList[v4]->mSimObjectPtr.m_pPointer;
      if ( v6 )
      {
        if ( v6->m_pSceneObj->mpParent )
          UFG::SceneObjectProperties::DeactivateDeferred(v6->m_pSceneObj);
        else
          UFG::SimObject::Destroy(v6);
      }
      ++v4;
    }
    while ( v4 < v5 );
  }
  return (unsigned int)v5;
}

// File Line: 5803
// RVA: 0x417CB0
void UFG::PedSpawnManager::ToggleResourceResolution(void)
{
  bool v0; // si
  UFG::qNode<UFG::PedSpawningInfo,UFG::PedInfoList> **v1; // r14
  signed __int64 v2; // rbp
  UFG::qList<UFG::PedSpawningInfo,UFG::PedInfoList,1,0> *v3; // rdi
  signed __int64 i; // rbx
  UFG::SimObject *v5; // rcx

  v0 = NISManager::GetInstance()->mHighDefModelsEnabled == 0;
  v1 = &UFG::PedSpawnManager::msScriptedList[0].mNode.mNext;
  v2 = 6i64;
  NISManager::GetInstance()->mHighDefModelsEnabled = v0;
  v3 = &UFG::PedSpawnManager::msScriptedList[-4];
  do
  {
    for ( i = (signed __int64)&(*v1)[-4];
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
    v1 += 2;
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
  UFG::PedSpawningInfo *v2; // rbx
  UFG::SpawnZone *v3; // rax
  UFG::SimObject *v4; // rcx

  v2 = pedInfo;
  if ( pedInfo->mSimObjectPtr.m_pPointer )
  {
    if ( pedInfo->mHowSpawned == FromPoint && pedInfo->mPedType == AmbientPed )
    {
      v3 = pedInfo->mCreationSpawnZone.m_pPointer;
      if ( v3 )
      {
        if ( (float)((float)((float)((float)(v3->mZoneCentre.y - pedInfo->mCurrentLocation.y)
                                   * (float)(v3->mZoneCentre.y - pedInfo->mCurrentLocation.y))
                           + (float)((float)(v3->mZoneCentre.x - pedInfo->mCurrentLocation.x)
                                   * (float)(v3->mZoneCentre.x - pedInfo->mCurrentLocation.x)))
                   + (float)((float)(v3->mZoneCentre.z - pedInfo->mCurrentLocation.z)
                           * (float)(v3->mZoneCentre.z - pedInfo->mCurrentLocation.z))) < 4.0
          && v3->mZoneActiveStatus == 3 )
        {
          v3->mZoneActiveStatus = 1;
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
  if ( v2->mTrueCrowdSignature.mSet )
    UFG::TrueCrowdSet::Instance::RemoveProxyReference(&v2->mTrueCrowdSignature, v2);
  v2->mTrueCrowdSignature.mNumParts = 0;
  v2->mTrueCrowdSignature.mSet = 0i64;
}

// File Line: 5993
// RVA: 0x408460
void __fastcall UFG::PedSpawnManager::ChangeStatusToActive(UFG::PedSpawnManager *this, UFG::PedSpawningInfo *pedInfo)
{
  UFG::PedSpawningInfo *v2; // rdi
  UFG::SimObject *v3; // rsi
  UFG::TransformNodeComponent *v4; // r14
  UFG::allocator::free_link *v5; // rax
  UFG::TeleportEvent *v6; // rbp
  unsigned int v7; // ebx
  UFG::TransformNodeComponent *v8; // r14
  UFG::allocator::free_link *v9; // rax
  UFG::TeleportEvent *v10; // rbp
  unsigned int v11; // ebx
  UFG::SimComponent *v12; // rcx

  v2 = pedInfo;
  v3 = pedInfo->mSimObjectPtr.m_pPointer;
  if ( pedInfo->mActiveStatus == 2 )
  {
    if ( pedInfo->mTeleportOnResumeRequired == 1 )
    {
      v8 = pedInfo->mProxyTransformNode;
      v9 = UFG::qMalloc(0x90ui64, "TeleportEvent", 0i64);
      v10 = (UFG::TeleportEvent *)v9;
      if ( v9 )
      {
        v11 = v3->mNode.mUID;
        UFG::TransformNodeComponent::UpdateWorldTransform(v8);
        UFG::TeleportEvent::TeleportEvent(v10, &v8->mWorldTransform, v11, 0, UFG::TeleportEvent::m_Name, 0);
      }
      UFG::EventDispatcher::DispatchEvent(&UFG::EventDispatcher::mInstance, (UFG::Event *)v9);
    }
    v2->mTeleportOnResumeRequired = 0;
    UFG::SimObject::Restore(v3);
  }
  else
  {
    if ( pedInfo->mActiveStatus != 3 )
      goto LABEL_14;
    if ( pedInfo->mTeleportOnResumeRequired == 1 )
    {
      v4 = pedInfo->mProxyTransformNode;
      v5 = UFG::qMalloc(0x90ui64, "TeleportEvent", 0i64);
      v6 = (UFG::TeleportEvent *)v5;
      if ( v5 )
      {
        v7 = v3->mNode.mUID;
        UFG::TransformNodeComponent::UpdateWorldTransform(v4);
        UFG::TeleportEvent::TeleportEvent(v6, &v4->mWorldTransform, v7, 0, UFG::TeleportEvent::m_Name, 0);
      }
      UFG::EventDispatcher::DispatchEvent(&UFG::EventDispatcher::mInstance, (UFG::Event *)v5);
    }
    UFG::SimObject::Restore(v3);
    v2->mTeleportOnResumeRequired = 0;
  }
  UFG::PedSpawningInfo::SetActiveStatus(v2, Active);
LABEL_14:
  if ( v3 )
  {
    v12 = v3->m_Components.p[22].m_pComponent;
    if ( v12 )
      BYTE6(v12[20].m_BoundComponentHandles.mNode.mPrev) = 1;
  }
}

// File Line: 6065
// RVA: 0x4085E0
void __fastcall UFG::PedSpawnManager::ChangeStatusToExtraLowPower(UFG::PedSpawnManager *this, UFG::PedSpawningInfo *pedInfo)
{
  UFG::PedSpawningInfo *v2; // rdi
  UFG::SimObject *v3; // r15
  UFG::TransformNodeComponent *v4; // rbp
  UFG::allocator::free_link *v5; // r14
  UFG::SimComponent *v6; // rsi
  unsigned int v7; // ebx
  UFG::Event *v8; // rax
  UFG::SimObject *v9; // rax
  UFG::AILightWeightComponent *v10; // rbx
  UFG::TransformNodeComponent *v11; // rbp
  UFG::allocator::free_link *v12; // r14
  unsigned int v13; // ebx
  UFG::Event *v14; // rax
  UFG::SimObject *v15; // rax
  UFG::SimComponent *v16; // rbx
  UFG::AILightWeightComponent *v17; // rbp
  UFG::qSafePointer<UFG::SimComponent,UFG::InterestPoint> *v18; // rdi
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v19; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v20; // rax
  UFG::InterestPoint *v21; // rcx
  UFG::qList<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList,1,0> *v22; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v23; // rax
  UFG::InterestPoint *ppInterestPoint; // [rsp+68h] [rbp+10h]

  v2 = pedInfo;
  v3 = pedInfo->mSimObjectPtr.m_pPointer;
  if ( pedInfo->mActiveStatus == 1 )
  {
    v11 = pedInfo->mTransformNodePtr;
    if ( !v11 )
      v11 = pedInfo->mProxyTransformNode;
    v12 = UFG::qMalloc(0x90ui64, "TeleportEvent", 0i64);
    ppInterestPoint = (UFG::InterestPoint *)v12;
    if ( v12 )
    {
      v13 = v2->mProxySimObjectPtr->mNode.mUID;
      UFG::TransformNodeComponent::UpdateWorldTransform(v11);
      UFG::TeleportEvent::TeleportEvent(
        (UFG::TeleportEvent *)v12,
        &v11->mWorldTransform,
        v13,
        0,
        UFG::TeleportEvent::m_Name,
        0);
    }
    else
    {
      v14 = 0i64;
    }
    UFG::EventDispatcher::DispatchEvent(&UFG::EventDispatcher::mInstance, v14);
    v15 = v2->mSimObjectPtr.m_pPointer;
    if ( v15 )
      v16 = v15->m_Components.p[22].m_pComponent;
    else
      v16 = 0i64;
    v17 = v2->mProxyAIComponent;
    if ( v16 && v17 )
    {
      UFG::AILightWeightComponent::SetWanderData(v2->mProxyAIComponent, (UFG::SidewalkWanderData *)&v16[8].m_Flags);
      v17->mAILCanUseCrosswalks = HIBYTE(v16[20].m_BoundComponentHandles.mNode.mPrev);
    }
    UFG::SimObject::Suspend(v3);
    v2->mSuspendedTime = 0.0;
    v2->mTeleportOnResumeRequired = 0;
    UFG::PedSpawningInfo::SetActiveStatus(v2, ExtraLowPower);
    ppInterestPoint = 0i64;
    if ( UFG::PedSpawningInfo::IsUsingPOI(v2, &ppInterestPoint) )
    {
      v18 = &v2->mUpgradePOI;
      if ( v18->m_pPointer )
      {
        v19 = v18->mPrev;
        v20 = v18->mNext;
        v19->mNext = v20;
        v20->mPrev = v19;
        v18->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v18->mPrev;
        v18->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v18->mPrev;
      }
      v21 = ppInterestPoint;
      v18->m_pPointer = (UFG::SimComponent *)&ppInterestPoint->vfptr;
      if ( v21 )
      {
        v22 = &v21->m_SafePointerList;
        v23 = v22->mNode.mPrev;
        v23->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v18->mPrev;
        v18->mPrev = v23;
        v18->mNext = &v22->mNode;
        v22->mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v18->mPrev;
      }
    }
  }
  else if ( pedInfo->mActiveStatus == 3 )
  {
    v4 = pedInfo->mTransformNodePtr;
    if ( !v4 )
      v4 = pedInfo->mProxyTransformNode;
    v5 = UFG::qMalloc(0x90ui64, "TeleportEvent", 0i64);
    ppInterestPoint = (UFG::InterestPoint *)v5;
    v6 = 0i64;
    if ( v5 )
    {
      v7 = v2->mProxySimObjectPtr->mNode.mUID;
      UFG::TransformNodeComponent::UpdateWorldTransform(v4);
      UFG::TeleportEvent::TeleportEvent(
        (UFG::TeleportEvent *)v5,
        &v4->mWorldTransform,
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
    v9 = v2->mSimObjectPtr.m_pPointer;
    if ( v9 )
      v6 = v9->m_Components.p[22].m_pComponent;
    v10 = v2->mProxyAIComponent;
    if ( v6 )
    {
      if ( v10 )
      {
        UFG::AILightWeightComponent::SetWanderData(v2->mProxyAIComponent, (UFG::SidewalkWanderData *)&v6[8].m_Flags);
        v10->mAILCanUseCrosswalks = HIBYTE(v6[20].m_BoundComponentHandles.mNode.mPrev);
      }
    }
    UFG::PedSpawningInfo::SetActiveStatus(v2, ExtraLowPower);
  }
}

// File Line: 6171
// RVA: 0x408260
void __fastcall UFG::PedSpawnManager::ChangeActiveStatus(UFG::PedSpawnManager *this, UFG::PedSpawningInfo::eActiveStatus targetPedStatus, UFG::PedSpawningInfo *pedInfo)
{
  UFG::PedSpawningInfo *v3; // rbx
  __int32 v4; // edx
  int v5; // edx

  v3 = pedInfo;
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
          if ( pedInfo->mActiveStatus == 1 )
          {
            UFG::SimObject::Suspend(pedInfo->mSimObjectPtr.m_pPointer);
            v3->mSuspendedTime = 0.0;
            v3->mTeleportOnResumeRequired = 0;
            UFG::PedSpawningInfo::SetActiveStatus(v3, NormalSuspend);
          }
          else if ( pedInfo->mActiveStatus == 2 )
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
char __fastcall UFG::PedSpawnManager::ChangeActiveStatusOfSimObj(UFG::PedSpawnManager *this, UFG::PedSpawningInfo::eActiveStatus targetPedStatus, UFG::SimObject *simObj, const char *file, int line)
{
  UFG::SimObject *v5; // r11
  UFG::PedSpawnManager *v6; // r9
  signed int v7; // er10
  UFG::SimObject **v8; // rax
  signed __int64 v9; // rcx
  UFG::SimObject **v10; // rcx
  signed __int64 v11; // r8
  signed __int64 v13; // rbx
  signed __int64 v14; // rbx
  __int32 v15; // edx
  int v16; // edx

  v5 = simObj;
  v6 = this;
  if ( !simObj )
    return 0;
  v7 = 119;
  v8 = &this->mScriptedPed[119].mSimObjectPtr.m_pPointer;
  v9 = 119i64;
  do
  {
    if ( simObj == *v8 )
    {
      v13 = (signed __int64)v6->mScriptedPed;
      goto LABEL_11;
    }
    --v7;
    v8 -= 103;
    --v9;
  }
  while ( v9 >= 0 );
  v7 = 259;
  v10 = &v6->mAmbientPed[259].mSimObjectPtr.m_pPointer;
  v11 = 259i64;
  while ( v5 != *v10 )
  {
    --v7;
    v10 -= 103;
    if ( --v11 < 0 )
      return 0;
  }
  v13 = (signed __int64)v6->mAmbientPed;
LABEL_11:
  v14 = 824i64 * v7 + v13;
  if ( targetPedStatus )
  {
    v15 = targetPedStatus - 1;
    if ( !v15 )
    {
      UFG::PedSpawnManager::ChangeStatusToActive(v6, (UFG::PedSpawningInfo *)v14);
      return 1;
    }
    v16 = v15 - 1;
    if ( !v16 )
    {
      UFG::PedSpawnManager::ChangeStatusToExtraLowPower(v6, (UFG::PedSpawningInfo *)v14);
      return 1;
    }
    if ( v16 == 1 )
    {
      if ( *(_DWORD *)(v14 + 168) == 1 )
      {
        UFG::SimObject::Suspend(*(UFG::SimObject **)(v14 + 192));
        *(_DWORD *)(v14 + 132) = 0;
        *(_BYTE *)(v14 + 764) = 0;
        UFG::PedSpawningInfo::SetActiveStatus((UFG::PedSpawningInfo *)v14, NormalSuspend);
        return 1;
      }
      if ( *(_DWORD *)(v14 + 168) == 2 )
      {
        *(_DWORD *)(v14 + 132) = 0;
        UFG::PedSpawningInfo::SetActiveStatus((UFG::PedSpawningInfo *)v14, NormalSuspend);
        return 1;
      }
    }
  }
  else
  {
    UFG::PedSpawnManager::ChangeStatusToInactive(v6, (UFG::PedSpawningInfo *)v14);
  }
  return 1;
}

// File Line: 6363
// RVA: 0x409340
signed __int64 __fastcall UFG::PedSpawnManager::CheckAmbientActiveStatus(UFG::PedSpawnManager *this, UFG::PedSpawningInfo *pedInfo, float elapsedTime)
{
  UFG::PedSpawningInfo::eActiveStatus v3; // esi
  UFG::PedSpawningInfo *v4; // rbx
  UFG::SimObject *v5; // rax
  UFG::SimComponent *v6; // rdx
  UFG::SpawnZone *v7; // rax
  signed __int64 result; // rax
  UFG::SimObject *v9; // rbp
  unsigned int v10; // edi
  float v11; // xmm6_4

  v3 = pedInfo->mActiveStatus;
  v4 = pedInfo;
  if ( !pedInfo->mIsDead )
  {
    v5 = pedInfo->mSimObjectPtr.m_pPointer;
    if ( v5 )
    {
      v6 = v5->m_Components.p[6].m_pComponent;
      if ( v6 )
      {
        if ( BYTE4(v6[1].m_BoundComponentHandles.mNode.mPrev) )
        {
          v7 = v4->mCreationSpawnZone.m_pPointer;
          v4->mIsDead = 1;
          if ( v7 )
            ++v7->mNumDeadPeds;
        }
      }
    }
  }
  if ( UFG::PedSpawnManager::msAmbientStatusCheckEnable || UFG::PedSpawnManager::msCheckStatusMode != 1 )
  {
    if ( v3 == Inactive || v4->mCharacterOccupantComponent.m_pSimComponent )
      return (unsigned int)v4->mActiveStatus;
    v9 = v4->mSimObjectPtr.m_pPointer;
    result = UFG::PedSpawnManager::GetIdealActiveStatus(this, v4);
    v10 = result;
    if ( (_DWORD)result == v3 )
      goto LABEL_27;
    if ( v3 != 1 )
    {
      if ( (signed int)result <= 2 )
        return result;
      v11 = elapsedTime + v4->mSuspendedTime;
      v4->mSuspendedTime = v11;
      if ( v11 > 3.0 && !UFG::SkookumMgr::IsReferencedByScripts(v9) )
        goto LABEL_28;
    }
    if ( v10 == 1 || !(v4->mCanSuspendScripted & 4) )
LABEL_27:
      result = v10;
    else
LABEL_28:
      result = 0i64;
  }
  else if ( v4->mPhysicsLoadedForLocation )
  {
    result = (unsigned int)v3;
  }
  else
  {
    result = v4->mCreationSpawnZone.m_pPointer != 0i64 ? 3 : 0;
  }
  return result;
}

// File Line: 6511
// RVA: 0x408940
void __fastcall UFG::PedSpawnManager::CheckActiveStatusOfPeds(UFG::PedSpawnManager *this)
{
  UFG::PedSpawnManager *v1; // rbp
  float v2; // xmm12_4
  bool v3; // bl
  UFG::SimObjectCharacter *v4; // rax
  UFG::PedSpawningInfo *v5; // r15
  int v6; // ecx
  UFG::SimObjectCharacter *v7; // r13
  bool v8; // r8
  UFG::BaseCameraComponent *v9; // rax
  __int64 v10; // rbx
  int v11; // er14
  __int64 v12; // r12
  UFG::PedSpawningInfo *v13; // rdi
  UFG::SimObject *v14; // rbp
  UFG::PedSpawningInfo::eActiveStatus v15; // esi
  UFG::SimComponent *v16; // rax
  UFG::SimObject *v17; // rbx
  NISManager *v18; // rax
  float v19; // xmm0_4
  float v20; // xmm0_4
  __int64 v21; // rax
  UFG::SimObject *v22; // rbx
  NISManager *v23; // rax
  char v24; // al
  float v25; // xmm0_4
  unsigned int v26; // eax
  float v27; // xmm0_4
  bool v28; // zf
  float v29; // xmm0_4
  __int64 v30; // rax
  __int64 v31; // rax
  __int64 v32; // rax
  __int64 v33; // rdi
  UFG::PedSpawnManager *v34; // r13
  signed __int64 v35; // rcx
  char v36; // al
  UFG::PedSpawningInfo::eActiveStatus v37; // edx
  UFG::PedSpawnManager *v38; // r15
  UFG::PedSpawningInfo *v39; // rdi
  char v40; // r14
  __int64 v41; // r12
  UFG::PedSpawningInfo *v42; // rbp
  UFG::PedSpawningInfo *v43; // rbx
  UFG::PedSpawningInfo *v44; // rsi
  UFG::PedSpawningInfo::eActiveStatus v45; // eax
  UFG::SimObject *v46; // rcx
  UFG::PedSpawningInfo::eActiveStatus v47; // er8
  UFG::SimComponent *v48; // rdx
  __int64 v49; // rcx
  int v50; // eax
  UFG::SimObject *v51; // rax
  UFG::SimComponent *v52; // rdx
  float v53; // xmm0_4
  float v54; // xmm0_4
  __int64 v55; // rdi
  signed __int64 v56; // rbx
  UFG::PedSpawningInfo::eActiveStatus v57; // ecx
  int v58; // ecx
  int v59; // ecx
  UFG::PedSpawnManager *v60; // [rsp+E0h] [rbp+8h]
  UFG::PedSpawnManager *v61; // [rsp+E0h] [rbp+8h]
  char v62; // [rsp+E8h] [rbp+10h]
  bool v63; // [rsp+F0h] [rbp+18h]
  __int64 v64; // [rsp+F8h] [rbp+20h]

  v60 = this;
  v1 = this;
  v2 = UFG::PedSpawnManager::msElapsedTotal - this->mTimeOfLastEnableCheck;
  this->mTimeOfLastEnableCheck = UFG::PedSpawnManager::msElapsedTotal;
  v3 = (float)((float)(signed int)Illusion::gEngine.FrameWriteMemory->mLastFrameNumFreeBytes * 0.00000095367432) < 0.40000001;
  v4 = UFG::GetLocalPlayer();
  v5 = 0i64;
  v6 = 260 - UFG::PedSpawnManager::msAmbientCount[0];
  v7 = v4;
  v8 = 120 - UFG::PedSpawnManager::msScriptedCount[0] > 115
    || v3
    || v6 + 120 - UFG::PedSpawnManager::msScriptedCount[0] > UFG::gMaxTotalFullSimPeds;
  v63 = v6 > UFG::gMaxTotalFullSimPeds / 2 + 10;
  if ( v8 || (v62 = 0, UFG::PedSpawnManager::msRunRagdollDelete) )
    v62 = 1;
  v9 = UFG::Director::Get()->mCurrentCamera;
  if ( !v9 || v9 == (UFG::BaseCameraComponent *)-80i64 )
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
    v14 = v1->mScriptedPed[v12].mSimObjectPtr.m_pPointer;
    v15 = v13->mActiveStatus;
    if ( v14 )
    {
      v16 = UFG::SimObject::GetComponentOfType(v14, UFG::InterestPointUserComponent::_TypeUID);
      if ( v16 && LODWORD(v16[8].m_BoundComponentHandles.mNode.mPrev) == UFG::Metrics::msInstance.mSimFrameCount )
        goto LABEL_26;
      LODWORD(v10) = num_changes_queued;
    }
    if ( !UFG::PedSpawnManager::msScriptedStatusCheckEnable && UFG::PedSpawnManager::msCheckStatusMode == 1 )
    {
      if ( v15 == 1 && !v13->mPhysicsLoadedForLocation )
      {
        v17 = v13->mSimObjectPtr.m_pPointer;
        v18 = NISManager::GetInstance();
        if ( !NISManager::IsActiveInNIS(v18, v17) )
        {
          if ( v13->mActiveStatus == 1 )
          {
            UFG::SimObject::Suspend(v13->mSimObjectPtr.m_pPointer);
            v13->mTeleportOnResumeRequired = 0;
            goto LABEL_25;
          }
          if ( v13->mActiveStatus == 2 )
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
    if ( v14 != (UFG::SimObject *)v7 )
    {
      if ( v15 == Inactive )
        goto LABEL_97;
      if ( v13->mCharacterOccupantComponent.m_pSimComponent )
      {
        if ( v15 == 1 )
          goto LABEL_97;
LABEL_95:
        v32 = (unsigned int)v10;
        change_queue[v32].index = v11;
        change_queue[v32].newStatus = 1;
LABEL_96:
        LODWORD(v10) = v10 + 1;
        num_changes_queued = v10;
        goto LABEL_97;
      }
      if ( v13->mCanSuspendScripted & 8 )
      {
        v30 = (unsigned int)v10;
        change_queue[v30].index = v11;
        change_queue[v30].newStatus = 0;
        goto LABEL_96;
      }
      UFG::PedSpawningInfo::UpdateDeadStatus(v13);
      if ( v13->mIsDead != 1 || (v13->mCanSuspendScripted &= 0xFFFFFFFE, v13->mCanSuspendScripted & 2) )
      {
LABEL_48:
        if ( v13->mCanSuspendScripted & 4 && v13->mCulledTime > 15.0 )
        {
          v21 = (unsigned int)v10;
          change_queue[v21].index = v11;
          change_queue[v21].newStatus = 0;
          goto LABEL_96;
        }
        v22 = v13->mSimObjectPtr.m_pPointer;
        v23 = NISManager::GetInstance();
        v24 = NISManager::IsActiveInNIS(v23, v22);
        if ( v15 == 1 )
        {
          if ( v24 )
            goto LABEL_59;
          if ( v13->mPhysicsLoadedForLocation )
          {
            if ( v13->mCanSuspendScripted & 3 )
              goto LABEL_59;
            if ( v13->mIsDead )
            {
              v25 = v13->mCulledTime;
              if ( v25 <= 15.0 && (120 - UFG::PedSpawnManager::msScriptedCount[0] <= 40 || v25 <= 3.0) )
                goto LABEL_59;
            }
            else if ( (v13->mLocationClassification < 3
                    || (float)(UFG::PedSpawnManager::msPreferActiveMargin + UFG::PedSpawnManager::msAlwaysActiveDistance) >= v13->mDistInCameraSpace)
                   && v13->mCulledTime <= 4.0 )
            {
LABEL_59:
              if ( v13->mCanSuspendScripted & 2 && !UFG::SkookumMgr::IsReferencedByScripts(v14) )
                v13->mCanSuspendScripted &= 0xFFFFFFFD;
              goto LABEL_26;
            }
          }
          v10 = num_changes_queued;
          v26 = v13->mCanSuspendScripted & 4;
          change_queue[num_changes_queued].index = v11;
          if ( (_BYTE)v26 )
          {
            change_queue[v10].newStatus = 0;
            goto LABEL_96;
          }
LABEL_84:
          change_queue[v10].newStatus = 3;
          goto LABEL_96;
        }
        if ( !v24 )
        {
          if ( !v13->mPhysicsLoadedForLocation )
            goto LABEL_77;
          if ( !(v13->mCanSuspendScripted & 3) )
          {
            if ( v13->mIsDead )
            {
              v27 = v13->mCulledTime;
              if ( v27 <= 15.0 && (120 - UFG::PedSpawnManager::msScriptedCount[0] <= 40 || v27 <= 3.0) )
                goto LABEL_74;
            }
            else if ( 0.0 == v13->mCulledTime && v13->mLocationClassification <= 1 )
            {
              goto LABEL_74;
            }
LABEL_77:
            v28 = v13->mIsDead == 1;
            v29 = v2 + v13->mSuspendedTime;
            v13->mSuspendedTime = v29;
            if ( !v28 || v29 <= 3.0 || v13->mDistInCameraSpace <= 5.0 || v13->mCanSuspendScripted & 2 )
              goto LABEL_26;
            change_queue[num_changes_queued].index = v11;
            if ( !UFG::SkookumMgr::IsReferencedByScripts(v14) )
            {
              LODWORD(v10) = num_changes_queued;
              change_queue[num_changes_queued].newStatus = 0;
              goto LABEL_96;
            }
            if ( v15 == 3 )
              goto LABEL_26;
            v10 = num_changes_queued;
            goto LABEL_84;
          }
        }
LABEL_74:
        v10 = num_changes_queued;
        change_queue[v10].index = v11;
        change_queue[v10].newStatus = 1;
        goto LABEL_96;
      }
      if ( UFG::PedSpawningInfo::GetHowLongDead(v13) > 3.0 )
      {
        if ( v62 )
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
          v20 = v13->mDistInCameraSpace;
          goto LABEL_40;
        }
        if ( v63 && v13->mCulledTime > 10.0 )
        {
          v20 = v13->mDistInCameraSpace;
          if ( v20 > 20.0 )
          {
            if ( !v5 )
            {
LABEL_41:
              v5 = v13;
              goto LABEL_26;
            }
LABEL_40:
            if ( v20 > v5->mDistInCameraSpace )
              goto LABEL_41;
            goto LABEL_47;
          }
        }
      }
LABEL_47:
      LODWORD(v10) = num_changes_queued;
      goto LABEL_48;
    }
    if ( v15 == 1 )
    {
      if ( v13->mPhysicsLoadedForLocation )
        goto LABEL_97;
      v31 = (unsigned int)v10;
      UFG::PedSpawnManager::msRestoreWeiOnPhysicsLoad = 1;
      change_queue[v31].index = v11;
      change_queue[v31].newStatus = 3;
      goto LABEL_96;
    }
    if ( v15 == 3 && v13->mPhysicsLoadedForLocation )
    {
      UFG::PedSpawnManager::msRestoreWeiOnPhysicsLoad = 0;
      goto LABEL_95;
    }
LABEL_97:
    v1 = v60;
    ++v11;
    ++v12;
  }
  while ( v11 < 120 );
  v33 = 0i64;
  v34 = v60;
  if ( (_DWORD)v10 )
  {
    do
    {
      v35 = change_queue[v33].index;
      if ( v60->mScriptedPed[v35].mStatusChangedFrame != UFG::Metrics::msFrameCount )
      {
        UFG::PedSpawnManager::ChangeActiveStatus(v60, change_queue[v33].newStatus, &v60->mScriptedPed[v35]);
        LODWORD(v10) = num_changes_queued;
        v60->mScriptedPed[change_queue[v33].index].mStatusChangedFrame = UFG::Metrics::msFrameCount;
      }
      v33 = (unsigned int)(v33 + 1);
    }
    while ( (unsigned int)v33 < (unsigned int)v10 );
  }
  if ( v5 && v5->mStatusChangedFrame != UFG::Metrics::msFrameCount )
  {
    v36 = UFG::SkookumMgr::IsReferencedByScripts(v5->mSimObjectPtr.m_pPointer);
    v37 = Inactive;
    if ( v36 )
      v37 = NormalSuspend;
    if ( v37 != v5->mActiveStatus )
      UFG::PedSpawnManager::ChangeActiveStatus(v60, v37, v5);
  }
  v38 = (UFG::PedSpawnManager *)&stru_1423DEF70.mNode.mNext;
  v39 = 0i64;
  v40 = 0;
  num_changes_queued = 0;
  v41 = NormalSuspend;
  v61 = (UFG::PedSpawnManager *)&stru_1423DEF70.mNode.mNext;
  v64 = NormalSuspend;
  v42 = (UFG::PedSpawningInfo *)&UFG::PedSpawnManager::msAmbientList[-3];
  do
  {
    v43 = (UFG::PedSpawningInfo *)&v38->vfptr[-3].OnAttach;
    if ( v43 == v42 )
      goto LABEL_137;
    do
    {
      v44 = (UFG::PedSpawningInfo *)&v43->mNext[-4];
      v45 = (unsigned int)UFG::PedSpawnManager::CheckAmbientActiveStatus(v34, v43, v2);
      v46 = v43->mSimObjectPtr.m_pPointer;
      v47 = v45;
      if ( !v46
        || (v48 = v46->m_Components.p[43].m_pComponent) == 0i64
        || LODWORD(v48[8].m_BoundComponentHandles.mNode.mPrev) != UFG::Metrics::msInstance.mSimFrameCount )
      {
        if ( v45 != v43->mActiveStatus )
        {
          v49 = num_changes_queued;
          v50 = v43->mPedIndex;
          ++num_changes_queued;
          change_queue[v49].index = v50;
          change_queue[v49].newStatus = v47;
          goto LABEL_135;
        }
        if ( v43->mIsDead == 1
          && !v43->mCharacterOccupantComponent.m_pSimComponent
          && UFG::PedSpawningInfo::GetHowLongDead(v43) > 3.0 )
        {
          if ( v62 )
          {
            if ( v39 )
            {
              v51 = v43->mSimObjectPtr.m_pPointer;
              if ( v51 )
                v52 = v51->m_Components.p[42].m_pComponent;
              else
                v52 = 0i64;
              if ( (v52 != 0i64) == v40 )
              {
                v53 = v39->mCulledTime;
                if ( v53 >= v43->mCulledTime )
                {
                  if ( v53 != 0.0 )
                    goto LABEL_135;
                  v54 = v43->mDistInCameraSpace;
                  goto LABEL_133;
                }
              }
              else
              {
                if ( !v52 )
                  goto LABEL_135;
                v40 = 1;
              }
            }
            goto LABEL_134;
          }
          if ( v63 && v43->mCulledTime > 10.0 )
          {
            v54 = v43->mDistInCameraSpace;
            if ( v54 > 20.0 )
            {
              if ( v39 )
              {
LABEL_133:
                if ( v54 <= v39->mDistInCameraSpace )
                  goto LABEL_135;
              }
LABEL_134:
              v39 = v43;
              goto LABEL_135;
            }
          }
        }
      }
LABEL_135:
      v43 = v44;
    }
    while ( v44 != v42 );
    v38 = v61;
    v41 = v64;
LABEL_137:
    v38 = (UFG::PedSpawnManager *)((char *)v38 + 16);
    v42 = (UFG::PedSpawningInfo *)((char *)v42 + 16);
    v64 = --v41;
    v61 = v38;
  }
  while ( v41 );
  if ( v39 )
  {
    if ( v39->mStatusChangedFrame != UFG::Metrics::msFrameCount )
      UFG::PedSpawnManager::ChangeStatusToInactive(v34, v39);
  }
  v55 = 0i64;
  if ( num_changes_queued )
  {
    while ( 1 )
    {
      v56 = (signed __int64)&v34->mAmbientPed[change_queue[v55].index];
      if ( *(_DWORD *)(v56 + 820) != UFG::Metrics::msFrameCount )
        break;
LABEL_155:
      v55 = (unsigned int)(v55 + 1);
      if ( (unsigned int)v55 >= num_changes_queued )
      {
        UFG::PedSpawnManager::msRunRagdollDelete = 0;
        return;
      }
    }
    v57 = change_queue[v55].newStatus;
    if ( v57 )
    {
      v58 = v57 - 1;
      if ( v58 )
      {
        v59 = v58 - 1;
        if ( v59 )
        {
          if ( v59 == 1 )
          {
            if ( *(_DWORD *)(v56 + 168) == 1 )
            {
              UFG::SimObject::Suspend(*(UFG::SimObject **)(v56 + 192));
              *(_BYTE *)(v56 + 764) = 0;
LABEL_149:
              *(_DWORD *)(v56 + 132) = 0;
              UFG::PedSpawningInfo::SetActiveStatus((UFG::PedSpawningInfo *)v56, NormalSuspend);
            }
            else if ( *(_DWORD *)(v56 + 168) == 2 )
            {
              goto LABEL_149;
            }
          }
        }
        else
        {
          UFG::PedSpawnManager::ChangeStatusToExtraLowPower(v34, &v34->mAmbientPed[change_queue[v55].index]);
        }
      }
      else
      {
        UFG::PedSpawnManager::ChangeStatusToActive(v34, &v34->mAmbientPed[change_queue[v55].index]);
      }
    }
    else
    {
      UFG::PedSpawnManager::ChangeStatusToInactive(v34, &v34->mAmbientPed[change_queue[v55].index]);
    }
    *(_DWORD *)(v56 + 820) = UFG::Metrics::msFrameCount;
    goto LABEL_155;
  }
  UFG::PedSpawnManager::msRunRagdollDelete = 0;
}

// File Line: 7084
// RVA: 0x4153B0
UFG::SimObjectCharacter *__fastcall UFG::PedSpawnManager::ReleaseOwnership(UFG::SimObject *_a_pObj, unsigned int desired_suspend_option, bool returning_from_mission_use)
{
  bool v3; // r14
  unsigned int v4; // ebp
  UFG::SimObjectCharacter *v5; // rbx
  unsigned __int16 v6; // cx
  UFG::SimComponent *v7; // rdi
  UFG::SimComponent *v8; // rax
  unsigned int v9; // esi
  __int64 v10; // rbp
  UFG::AnimationLODComponent *v11; // rcx
  UFG::SceneObjectProperties *v12; // rcx
  UFG::SimObjectModifier v14; // [rsp+28h] [rbp-40h]
  UFG::qSymbol result; // [rsp+70h] [rbp+8h]

  v3 = returning_from_mission_use;
  v4 = desired_suspend_option;
  v5 = (UFG::SimObjectCharacter *)_a_pObj;
  if ( !_a_pObj )
    return 0i64;
  v6 = _a_pObj->m_Flags;
  if ( (v6 >> 14) & 1 )
  {
    v7 = v5->m_Components.p[48].m_pComponent;
  }
  else
  {
    if ( (v6 & 0x8000u) == 0 )
    {
      if ( (v6 >> 13) & 1 )
        v8 = UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&v5->vfptr, UFG::PedSpawningInfo::_TypeUID);
      else
        v8 = (v6 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                (UFG::SimObjectGame *)&v5->vfptr,
                                UFG::PedSpawningInfo::_TypeUID) : UFG::SimObject::GetComponentOfType(
                                                                    (UFG::SimObject *)&v5->vfptr,
                                                                    UFG::PedSpawningInfo::_TypeUID);
    }
    else
    {
      v8 = UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&v5->vfptr, UFG::PedSpawningInfo::_TypeUID);
    }
    v7 = v8;
  }
  if ( !v7 )
    return 0i64;
  if ( LODWORD(v7[12].m_BoundComponentHandles.mNode.mPrev) == 2 )
  {
    v9 = -1;
    if ( v3 )
    {
      if ( *(_BYTE *)(&v7[10].m_SimObjIndex + 1) & 0x20 )
      {
        *(_DWORD *)(&v7[10].m_SimObjIndex + 1) &= 0xFFFFFFDF;
LABEL_20:
        if ( UFG::PedSpawnManager::msAmbientCount[0] > 0 )
        {
          v10 = qword_1423DEF68 - 64;
          UFG::PedSpawningInfo::SetActiveStatus(
            (UFG::PedSpawningInfo *)(qword_1423DEF68 - 64),
            (UFG::PedSpawningInfo::eActiveStatus)v7[2].m_pSimObject);
          UFG::PedSpawningInfo::SetSimObjectPtr((UFG::PedSpawningInfo *)v10, v5);
          v11 = (UFG::AnimationLODComponent *)v5->m_Components.p[13].m_pComponent;
          if ( v11 )
            UFG::AnimationLODComponent::SetExtendedLOD(v11, 0);
          *(_DWORD *)(v10 + 676) = *(_DWORD *)(&v7[10].m_SimObjIndex + 1);
          *(_BYTE *)(v10 + 348) = v7[5].m_NameUID;
          *(_DWORD *)(v10 + 132) = HIDWORD(v7[2].vfptr);
          *(_DWORD *)(v10 + 736) = 0;
          *(_DWORD *)(v10 + 740) = *(_DWORD *)(&v7[11].m_SimObjIndex + 1);
          *(_DWORD *)(v10 + 744) = v7[11].m_pSimObject;
          UFG::qSafePointer<UFG::SpawnZone,UFG::SpawnZone>::operator=(
            (UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *)(v10 + 144),
            (UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *)&v7[2].m_SafePointerList.mNode.mNext);
          *(_DWORD *)(v10 + 760) = v7[11].m_BoundComponentHandles.mNode.mNext;
          *(_BYTE *)(v10 + 764) = BYTE4(v7[11].m_BoundComponentHandles.mNode.mNext);
          *(UFG::qSymbol *)(v10 + 644) = (UFG::qSymbol)UFG::PedSpawningInfo::GetPropertySetName(
                                                         (UFG::PedSpawningInfo *)v7,
                                                         &result)->mUID;
          *(UFG::qSymbol *)(v10 + 648) = (UFG::qSymbol)UFG::PedSpawningInfo::GetArchetypePropertySetName(
                                                         (UFG::PedSpawningInfo *)v7,
                                                         &result)->mUID;
          *(UFG::qSymbolUC *)(v10 + 640) = (UFG::qSymbolUC)UFG::PedSpawningInfo::GetRigNameSymbol(
                                                             (UFG::PedSpawningInfo *)v7,
                                                             (UFG::qSymbolUC *)&result)->mUID;
          *(UFG::qSymbol *)(v10 + 652) = (UFG::qSymbol)UFG::PedSpawningInfo::GetFactionSymbol(
                                                         (UFG::PedSpawningInfo *)v7,
                                                         &result)->mUID;
          UFG::PedSpawningInfo::SetTrueCrowdSignature(
            (UFG::PedSpawningInfo *)v10,
            (UFG::TrueCrowdSet::Instance *)&v7[5].m_pSimObject);
          *(UFG::qSymbol *)(v10 + 352) = (UFG::qSymbol)UFG::PedSpawningInfo::GetLifetimeNameSymbol(
                                                         (UFG::PedSpawningInfo *)v7,
                                                         &result)->mUID;
          UFG::PedSpawningInfo::SwapGroupComponent((UFG::PedSpawningInfo *)v10, (UFG::PedSpawningInfo *)v7);
          UFG::SimObjectModifier::SimObjectModifier(&v14, (UFG::SimObject *)&v5->vfptr, 1);
          ArrayOfTuplesImplementation::clear((ArrayOfTuplesImplementation *)&v14);
          UFG::SimObjectModifier::Close(&v14);
          UFG::SimObjectModifier::~SimObjectModifier(&v14);
          if ( (v5->m_Flags >> 14) & 1 )
            v9 = 48;
          UFG::SimObjectModifier::SimObjectModifier(&v14, (UFG::SimObject *)&v5->vfptr, 1);
          UFG::SimObjectModifier::AttachComponent(&v14, (UFG::SimComponent *)v10, v9);
          UFG::SimObjectModifier::Close(&v14);
          UFG::SimObjectModifier::~SimObjectModifier(&v14);
          UFG::PedSpawningInfo::SetSimObjectPtr((UFG::PedSpawningInfo *)v7, 0i64);
          UFG::PedSpawningInfo::SetActiveStatus((UFG::PedSpawningInfo *)v7, 0);
          return v5;
        }
        v12 = v5->m_pSceneObj;
        if ( v12->mpParent )
          UFG::SceneObjectProperties::DeactivateDeferred(v12);
        else
          UFG::SimObject::Destroy((UFG::SimObject *)&v5->vfptr);
        return 0i64;
      }
    }
    else if ( !(*(_BYTE *)(&v7[10].m_SimObjIndex + 1) & 0x20) )
    {
      if ( v4 != -1 )
        *(_DWORD *)(&v7[10].m_SimObjIndex + 1) = v4;
      goto LABEL_20;
    }
  }
  return v5;
}

// File Line: 7254
// RVA: 0x407C90
char __fastcall UFG::PedSpawnManager::AquireOwnership(UFG::SimObject *_a_pObj, bool bAmbient, bool loaning_to_mission_script, int creation_zone_index)
{
  bool v4; // r14
  bool v5; // si
  UFG::SimObjectCharacter *v6; // rbx
  unsigned __int16 v7; // cx
  UFG::PedSpawningInfo *v8; // rdi
  UFG::PedSpawningInfo *v9; // rax
  UFG::PedSpawningInfo *v10; // rbp
  unsigned int v11; // eax
  UFG::AnimationLODComponent *v12; // rcx
  unsigned int v13; // esi
  UFG::SceneObjectProperties *v15; // rcx
  UFG::SimObjectModifier v16; // [rsp+28h] [rbp-40h]
  UFG::qSymbol result; // [rsp+70h] [rbp+8h]

  v4 = loaning_to_mission_script;
  v5 = bAmbient;
  v6 = (UFG::SimObjectCharacter *)_a_pObj;
  if ( !_a_pObj )
    return 0;
  v7 = _a_pObj->m_Flags;
  if ( (v7 >> 14) & 1 )
  {
    v8 = (UFG::PedSpawningInfo *)v6->m_Components.p[48].m_pComponent;
  }
  else
  {
    if ( (v7 & 0x8000u) == 0 )
    {
      if ( (v7 >> 13) & 1 )
        v9 = (UFG::PedSpawningInfo *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                       (UFG::SimObjectGame *)&v6->vfptr,
                                       UFG::PedSpawningInfo::_TypeUID);
      else
        v9 = (UFG::PedSpawningInfo *)((v7 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                         (UFG::SimObjectGame *)&v6->vfptr,
                                                         UFG::PedSpawningInfo::_TypeUID) : UFG::SimObject::GetComponentOfType(
                                                                                             (UFG::SimObject *)&v6->vfptr,
                                                                                             UFG::PedSpawningInfo::_TypeUID));
    }
    else
    {
      v9 = (UFG::PedSpawningInfo *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                     (UFG::SimObjectGame *)&v6->vfptr,
                                     UFG::PedSpawningInfo::_TypeUID);
    }
    v8 = v9;
  }
  if ( !v8 || v8->mPedType != 1 )
    return 0;
  UFG::PedSpawnManager::ChangeStatusToActive(UFG::gpPedSpawnManager, v8);
  if ( v5 )
    return 1;
  if ( UFG::PedSpawnManager::msScriptedCount[0] <= 0 )
  {
    v15 = v6->m_pSceneObj;
    if ( !v15->mpParent )
    {
      UFG::SimObject::Destroy((UFG::SimObject *)&v6->vfptr);
      return 1;
    }
    UFG::SceneObjectProperties::DeactivateDeferred(v15);
    return 1;
  }
  v10 = (UFG::PedSpawningInfo *)&UFG::PedSpawnManager::msScriptedList[0].mNode.mNext[-4];
  UFG::PedSpawningInfo::SetActiveStatus(
    (UFG::PedSpawningInfo *)&UFG::PedSpawnManager::msScriptedList[0].mNode.mNext[-4],
    v8->mActiveStatus);
  UFG::PedSpawningInfo::SetSimObjectPtr(v10, v6);
  v11 = v8->mCanSuspendScripted;
  v10->mCanSuspendScripted = v11;
  if ( v4 )
    v10->mCanSuspendScripted = v11 | 0x20;
  v12 = (UFG::AnimationLODComponent *)v6->m_Components.p[13].m_pComponent;
  if ( v12 )
    UFG::AnimationLODComponent::SetExtendedLOD(v12, 1);
  v10->mIsDead = v8->mIsDead;
  v10->mSuspendedTime = v8->mSuspendedTime;
  v10->mRestoreAttempts = 0;
  v10->mBlipActive = v8->mBlipActive;
  v10->mHowSpawned = v8->mHowSpawned;
  UFG::qSafePointer<UFG::SpawnZone,UFG::SpawnZone>::operator=(
    (UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *)&v10->mCreationSpawnZone,
    (UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *)&v8->mCreationSpawnZone);
  v10->mSpawnTime = v8->mSpawnTime;
  v10->mTeleportOnResumeRequired = v8->mTeleportOnResumeRequired;
  v10->mPropSetSymbol = (UFG::qSymbol)UFG::PedSpawningInfo::GetPropertySetName(v8, &result)->mUID;
  v10->mArchetypePropSetSymbol = (UFG::qSymbol)UFG::PedSpawningInfo::GetArchetypePropertySetName(v8, &result)->mUID;
  v10->mRigNameSymbol = (UFG::qSymbolUC)UFG::PedSpawningInfo::GetRigNameSymbol(v8, (UFG::qSymbolUC *)&result)->mUID;
  v10->mFactionSymbol = (UFG::qSymbol)UFG::PedSpawningInfo::GetFactionSymbol(v8, &result)->mUID;
  UFG::PedSpawningInfo::SetTrueCrowdSignature(v10, &v8->mTrueCrowdSignature);
  v10->mLifetimeInstanceNameSymbol = (UFG::qSymbol)UFG::PedSpawningInfo::GetLifetimeNameSymbol(v8, &result)->mUID;
  UFG::PedSpawningInfo::SwapGroupComponent(v10, v8);
  UFG::SimObjectModifier::SimObjectModifier(&v16, (UFG::SimObject *)&v6->vfptr, 1);
  ArrayOfTuplesImplementation::clear((ArrayOfTuplesImplementation *)&v16);
  UFG::SimObjectModifier::Close(&v16);
  UFG::SimObjectModifier::~SimObjectModifier(&v16);
  if ( (v6->m_Flags >> 14) & 1 )
    v13 = 48;
  else
    v13 = -1;
  UFG::SimObjectModifier::SimObjectModifier(&v16, (UFG::SimObject *)&v6->vfptr, 1);
  UFG::SimObjectModifier::AttachComponent(&v16, (UFG::SimComponent *)&v10->vfptr, v13);
  UFG::SimObjectModifier::Close(&v16);
  UFG::SimObjectModifier::~SimObjectModifier(&v16);
  UFG::PedSpawningInfo::SetSimObjectPtr(v8, 0i64);
  UFG::PedSpawningInfo::SetActiveStatus(v8, 0);
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
void __fastcall UFG::PedSpawnManager::CollectInfoForOne(UFG::PedSpawnManager *this, UFG::PedSpawningInfo *info, UFG::qMatrix44 *camWorldView, float elapsedTime)
{
  UFG::TransformNodeComponent *v4; // rdi
  UFG::qMatrix44 *v5; // rbp
  UFG::PedSpawningInfo *v6; // rbx
  UFG::PedSpawnManager *v7; // r14
  UFG::TransformNodeComponent *v8; // rsi
  UFG::PedSpawningInfo::eActiveStatus v9; // eax
  CullResults *v10; // rdi
  UFG::SimObject *v11; // rax
  UFG::SimComponent *v12; // rcx
  float v13; // xmm7_4
  float v14; // xmm8_4
  float v15; // xmm9_4
  unsigned int v16; // esi
  unsigned int v17; // eax
  UFG::SpawnZone *v18; // rax
  float *v19; // rdx
  float v20; // xmm0_4
  __m128 v21; // xmm2
  float v22; // xmm1_4
  bool v23; // zf
  __int64 v24; // rax
  float v25; // xmm0_4
  UFG::qNode<UFG::PedSpawningInfo,UFG::PedSpawningInfo_DrawList> *v26; // rax
  UFG::qNode<UFG::PedSpawningInfo,UFG::PedSpawningInfo_DrawList> *v27; // rcx
  UFG::qNode<UFG::PedSpawningInfo,UFG::PedSpawningInfo_DrawList> *v28; // rdx
  UFG::qNode<UFG::PedSpawningInfo,UFG::PedSpawningInfo_DrawList> *v29; // rax
  UFG::qNode<UFG::PedSpawningInfo,UFG::PedSpawningInfo_DrawList> *v30; // rax
  UFG::qNode<UFG::PedSpawningInfo,UFG::PedSpawningInfo_DrawList> *v31; // rcx
  UFG::qNode<UFG::PedSpawningInfo,UFG::PedSpawningInfo_DrawList> *v32; // rdx
  UFG::qNode<UFG::PedSpawningInfo,UFG::PedSpawningInfo_DrawList> *v33; // rax
  int v34; // eax
  UFG::qVector4 row_vec4; // [rsp+20h] [rbp-68h]
  UFG::qVector4 result; // [rsp+30h] [rbp-58h]

  v4 = info->mTransformNodePtr;
  v5 = camWorldView;
  v6 = info;
  v7 = this;
  if ( !v4 || (v8 = info->mTransformNodePtr, info->mActiveStatus == 2) )
    v8 = info->mProxyTransformNode;
  v9 = info->mActiveStatus;
  if ( (signed int)v9 >= 2 )
  {
    if ( !v4 || v9 == 2 )
      v4 = info->mProxyTransformNode;
    UFG::TransformNodeComponent::UpdateWorldTransform(v4);
    v6->mCullInfo->mpLocalWorld = &v4->mWorldTransform.v0.x;
  }
  v10 = v6->mCullResults;
  if ( v6->mActiveStatus < 2 )
  {
    v11 = v6->mSimObjectPtr.m_pPointer;
    if ( v11 )
    {
      v12 = v11->m_Components.p[14].m_pComponent;
      if ( v12 )
        v10 = (CullResults *)v12[19].m_pSimObject;
    }
  }
  UFG::TransformNodeComponent::UpdateWorldTransform(v8);
  v13 = v8->mWorldTransform.v3.x;
  v14 = v8->mWorldTransform.v3.y;
  v15 = v8->mWorldTransform.v3.z;
  row_vec4.x = v8->mWorldTransform.v3.x;
  row_vec4.y = v14;
  row_vec4.z = v15;
  LODWORD(row_vec4.w) = (_DWORD)FLOAT_1_0;
  UFG::operator*(&result, &row_vec4, v5);
  v16 = UFG::Metrics::msFrameCount;
  if ( !v6->mPhysicsLoadedForLocation || !(((unsigned __int8)UFG::Metrics::msFrameCount ^ LOBYTE(v6->mPedIndex)) & 7) )
  {
    row_vec4.x = v13;
    row_vec4.y = v14;
    row_vec4.z = v15;
    v17 = UFG::SectionChooser::GetVisIndexAtPosition((UFG::qVector3 *)&row_vec4, 0);
    v6->mPhysicsLoadedForLocation = UFG::SectionChooser::IsSectionVisible_VisIndex(v17, SCENERY_LAYER_STD, 0);
  }
  v18 = v6->mCreationSpawnZone.m_pPointer;
  if ( v18 )
  {
    if ( v18->mAliveCountValidationTag == v16 )
    {
      ++v18->mAliveCount;
    }
    else
    {
      v18->mAliveCount = 1;
      v6->mCreationSpawnZone.m_pPointer->mAliveCountValidationTag = v16;
    }
  }
  v19 = &v6->mCurrentLocation.x;
  *v19 = v13;
  v19[1] = v14;
  v19[2] = v15;
  v6->mLocationClassification = UFG::PedSpawnManager::GetActiveZoneFromPoint(
                                  v7,
                                  &v6->mCurrentLocation,
                                  v6->mActiveStatus);
  v20 = result.x;
  v21 = (__m128)LODWORD(result.y);
  v22 = result.z;
  v6->mLocationInCameraSpace.x = result.x;
  LODWORD(v6->mLocationInCameraSpace.y) = v21.m128_i32[0];
  v6->mLocationInCameraSpace.z = v22;
  v23 = v6->mIsDead == 0;
  v21.m128_f32[0] = (float)((float)((float)(v21.m128_f32[0] * v21.m128_f32[0]) + (float)(v20 * v20)) + (float)(v22 * v22))
                  + (float)(result.w * result.w);
  LODWORD(v6->mDistInCameraSpace) = (unsigned __int128)_mm_sqrt_ps(v21);
  if ( !v23 )
  {
    if ( v6->mPedType == 1 )
      ++UFG::PedSpawnManager::msNumDeadAmbientPeds;
    else
      ++UFG::PedSpawnManager::msNumDeadScriptedPeds;
  }
  if ( v10 )
  {
    v24 = gMainCullIndex;
    v25 = v6->mCulledTime;
    v6->mPrevCulledTime = v25;
    if ( (signed int)v24 < 0 || v10->mViewResult[v24] <= 1u )
    {
      v23 = v6->mDrawList == 1;
      v6->mCulledTime = 0.0;
      if ( !v23 )
      {
        v30 = v6->mNext;
        v31 = v6->mPrev;
        v32 = (UFG::qNode<UFG::PedSpawningInfo,UFG::PedSpawningInfo_DrawList> *)&v6->mPrev;
        v31->mNext = v30;
        v30->mPrev = v31;
        v32->mPrev = v32;
        v32->mNext = v32;
        v33 = UFG::PedSpawningInfo::smDrawList.mNode.mPrev;
        UFG::PedSpawningInfo::smDrawList.mNode.mPrev->mNext = (UFG::qNode<UFG::PedSpawningInfo,UFG::PedSpawningInfo_DrawList> *)&v6->mPrev;
        v32->mPrev = v33;
        v32->mNext = (UFG::qNode<UFG::PedSpawningInfo,UFG::PedSpawningInfo_DrawList> *)&UFG::PedSpawningInfo::smDrawList;
        UFG::PedSpawningInfo::smDrawList.mNode.mPrev = (UFG::qNode<UFG::PedSpawningInfo,UFG::PedSpawningInfo_DrawList> *)&v6->mPrev;
        v6->mDrawList = 1;
      }
    }
    else
    {
      v23 = v6->mDrawList == 2;
      v6->mCulledTime = v25 + elapsedTime;
      if ( !v23 )
      {
        v26 = v6->mNext;
        v27 = v6->mPrev;
        v28 = (UFG::qNode<UFG::PedSpawningInfo,UFG::PedSpawningInfo_DrawList> *)&v6->mPrev;
        v27->mNext = v26;
        v26->mPrev = v27;
        v28->mPrev = v28;
        v28->mNext = v28;
        v29 = UFG::PedSpawningInfo::smNoDrawList.mNode.mPrev;
        UFG::PedSpawningInfo::smNoDrawList.mNode.mPrev->mNext = (UFG::qNode<UFG::PedSpawningInfo,UFG::PedSpawningInfo_DrawList> *)&v6->mPrev;
        v28->mPrev = v29;
        v28->mNext = (UFG::qNode<UFG::PedSpawningInfo,UFG::PedSpawningInfo_DrawList> *)&UFG::PedSpawningInfo::smNoDrawList;
        UFG::PedSpawningInfo::smNoDrawList.mNode.mPrev = (UFG::qNode<UFG::PedSpawningInfo,UFG::PedSpawningInfo_DrawList> *)&v6->mPrev;
        v6->mDrawList = 2;
      }
    }
  }
  else
  {
    v6->mCulledTime = elapsedTime + v6->mCulledTime;
  }
  v34 = v6->mLockActiveFrameCount;
  if ( v34 <= 0 )
    v6->mLockActiveFrameCount = 0;
  else
    v6->mLockActiveFrameCount = v34 - 1;
}

// File Line: 8163
// RVA: 0x409990
void __fastcall UFG::PedSpawnManager::CollectPedInfo(UFG::PedSpawnManager *this, float elapsedTime)
{
  UFG::PedSpawnManager *v2; // rsi
  UFG::BaseCameraComponent *v3; // rcx
  signed __int64 v4; // rdi
  float v5; // xmm1_4
  float v6; // xmm2_4
  UFG::qMatrix44 *v7; // rbx
  UFG::qMatrix44 *v8; // rax
  float v9; // ST44_4
  float v10; // ST48_4
  float v11; // xmm12_4
  float v12; // xmm10_4
  float v13; // ST38_4
  float v14; // xmm11_4
  float v15; // ST34_4
  float v16; // xmm13_4
  float v17; // xmm14_4
  float v18; // xmm15_4
  float v19; // ST3C_4
  float v20; // ST24_4
  float v21; // xmm0_4
  float v22; // xmm0_4
  float v23; // xmm0_4
  __m128 v24; // xmm2
  float v25; // xmm0_4
  __m128 v26; // xmm2
  float v27; // xmm0_4
  float v28; // xmm5_4
  __m128 v29; // xmm2
  float v30; // xmm8_4
  UFG::BaseCameraComponent *v31; // rcx
  UFG::Camera *v32; // rcx
  UFG::qMatrix44 *v33; // rax
  float *v34; // rbx
  UFG::qMatrix44 *v35; // r14
  signed __int64 v36; // rbp
  signed __int64 v37; // rbx
  signed __int64 v38; // rdi
  UFG::qMatrix44 result; // [rsp+50h] [rbp-108h]
  float elapsedTimea; // [rsp+168h] [rbp+10h]
  float v41; // [rsp+170h] [rbp+18h]
  float v42; // [rsp+178h] [rbp+20h]

  elapsedTimea = elapsedTime;
  v2 = this;
  UFG::PedSpawnManager::msNumDeadScriptedPeds = 0;
  UFG::PedSpawnManager::msNumDeadAmbientPeds = 0;
  v3 = UFG::Director::Get()->mCurrentCamera;
  v4 = (signed __int64)&v3->mCamera;
  if ( !v3 )
    v4 = 0i64;
  v5 = *(float *)(v4 + 180);
  v6 = *(float *)(v4 + 184);
  UFG::PedSpawnManager::msZone_centre.x = *(float *)(v4 + 176);
  UFG::PedSpawnManager::msZone_centre.y = v5;
  UFG::PedSpawnManager::msZone_centre.z = v6;
  v7 = UFG::Camera::GetViewProjection((UFG::Camera *)v4);
  v8 = UFG::Camera::GetWorldView((UFG::Camera *)v4);
  UFG::qMatrix44::operator*(v8, &result, v7);
  LODWORD(v41) = COERCE_UNSIGNED_INT(result.v0.y + result.v0.w) ^ _xmm[0];
  LODWORD(v9) = COERCE_UNSIGNED_INT(result.v2.w - result.v2.y) ^ _xmm[0];
  LODWORD(v10) = COERCE_UNSIGNED_INT(result.v1.w - result.v1.y) ^ _xmm[0];
  LODWORD(v11) = COERCE_UNSIGNED_INT(result.v0.x + result.v0.w) ^ _xmm[0];
  LODWORD(v42) = COERCE_UNSIGNED_INT(result.v1.y + result.v1.w) ^ _xmm[0];
  LODWORD(v12) = COERCE_UNSIGNED_INT(result.v2.x + result.v2.w) ^ _xmm[0];
  LODWORD(v13) = COERCE_UNSIGNED_INT(result.v2.y + result.v2.w) ^ _xmm[0];
  LODWORD(v14) = COERCE_UNSIGNED_INT(result.v1.x + result.v1.w) ^ _xmm[0];
  LODWORD(v15) = COERCE_UNSIGNED_INT(result.v0.w - result.v0.y) ^ _xmm[0];
  LODWORD(v16) = COERCE_UNSIGNED_INT(result.v0.w - result.v0.x) ^ _xmm[0];
  LODWORD(v17) = COERCE_UNSIGNED_INT(result.v1.w - result.v1.x) ^ _xmm[0];
  LODWORD(v18) = COERCE_UNSIGNED_INT(result.v2.w - result.v2.x) ^ _xmm[0];
  LODWORD(v19) = COERCE_UNSIGNED_INT(result.v1.w - result.v1.z) ^ _xmm[0];
  LODWORD(v20) = COERCE_UNSIGNED_INT(result.v2.w - result.v2.z) ^ _xmm[0];
  v21 = fsqrt(
          (float)((float)(COERCE_FLOAT(LODWORD(result.v0.z) ^ _xmm[0]) * COERCE_FLOAT(LODWORD(result.v0.z) ^ _xmm[0]))
                + (float)(COERCE_FLOAT(LODWORD(result.v1.z) ^ _xmm[0]) * COERCE_FLOAT(LODWORD(result.v1.z) ^ _xmm[0])))
        + (float)(COERCE_FLOAT(LODWORD(result.v2.z) ^ _xmm[0]) * COERCE_FLOAT(LODWORD(result.v2.z) ^ _xmm[0])));
  *(float *)&dword_1423DEC6C = (float)(1.0 / v21) * COERCE_FLOAT(LODWORD(result.v3.z) ^ _xmm[0]);
  UFG::PedSpawnManager::msFrustum_planes[0].x = (float)(1.0 / v21) * COERCE_FLOAT(LODWORD(result.v0.z) ^ _xmm[0]);
  *(float *)&dword_1423DEC68 = (float)(1.0 / v21) * COERCE_FLOAT(LODWORD(result.v2.z) ^ _xmm[0]);
  *(float *)&dword_1423DEC64 = (float)(1.0 / v21) * COERCE_FLOAT(LODWORD(result.v1.z) ^ _xmm[0]);
  v22 = fsqrt((float)((float)(v11 * v11) + (float)(v14 * v14)) + (float)(v12 * v12));
  *(float *)&dword_1423DEC7C = (float)(1.0 / v22)
                             * COERCE_FLOAT(COERCE_UNSIGNED_INT(result.v3.x + result.v3.w) ^ _xmm[0]);
  *(float *)&dword_1423DEC70 = (float)(1.0 / v22) * v11;
  *(float *)&dword_1423DEC78 = (float)(1.0 / v22) * v12;
  *(float *)&dword_1423DEC74 = (float)(1.0 / v22) * v14;
  v23 = fsqrt((float)((float)(v16 * v16) + (float)(v17 * v17)) + (float)(v18 * v18));
  *(float *)&dword_1423DEC8C = (float)(1.0 / v23)
                             * COERCE_FLOAT(COERCE_UNSIGNED_INT(result.v3.w - result.v3.x) ^ _xmm[0]);
  *(float *)&dword_1423DEC80 = (float)(1.0 / v23) * v16;
  *(float *)&dword_1423DEC88 = (float)(1.0 / v23) * v18;
  *(float *)&dword_1423DEC84 = (float)(1.0 / v23) * v17;
  v24 = (__m128)LODWORD(v41);
  v24.m128_f32[0] = (float)((float)(v24.m128_f32[0] * v24.m128_f32[0]) + (float)(v42 * v42)) + (float)(v13 * v13);
  LODWORD(v25) = (unsigned __int128)_mm_sqrt_ps(v24);
  *(float *)&dword_1423DEC90 = (float)(1.0 / v25) * v41;
  *(float *)&dword_1423DEC98 = (float)(1.0 / v25) * v13;
  *(float *)&dword_1423DEC94 = (float)(1.0 / v25) * v42;
  v26 = (__m128)LODWORD(v15);
  *(float *)&dword_1423DEC9C = (float)(1.0 / v25)
                             * COERCE_FLOAT(COERCE_UNSIGNED_INT(result.v3.y + result.v3.w) ^ _xmm[0]);
  v26.m128_f32[0] = (float)((float)(v26.m128_f32[0] * v26.m128_f32[0]) + (float)(v10 * v10)) + (float)(v9 * v9);
  v27 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v26));
  LODWORD(v28) = COERCE_UNSIGNED_INT(result.v0.w - result.v0.z) ^ _xmm[0];
  *(float *)&dword_1423DECA0 = v27 * v15;
  *(float *)&dword_1423DECA4 = v27 * v10;
  *(float *)&dword_1423DECAC = v27 * COERCE_FLOAT(COERCE_UNSIGNED_INT(result.v3.w - result.v3.y) ^ _xmm[0]);
  v29 = (__m128)LODWORD(v19);
  *(float *)&dword_1423DECA8 = v27 * v9;
  v29.m128_f32[0] = (float)((float)(v29.m128_f32[0] * v29.m128_f32[0]) + (float)(v28 * v28)) + (float)(v20 * v20);
  v30 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v29));
  *(float *)&dword_1423DECBC = v30 * COERCE_FLOAT(COERCE_UNSIGNED_INT(result.v3.w - result.v3.z) ^ _xmm[0]);
  *(float *)&dword_1423DECB0 = v30 * v28;
  *(float *)&dword_1423DECB4 = v30 * v19;
  *(float *)&dword_1423DECB8 = v30 * v20;
  v31 = UFG::Director::Get()->mCurrentCamera;
  if ( v31 )
    v32 = &v31->mCamera;
  else
    v32 = 0i64;
  v33 = UFG::Camera::GetWorldView(v32);
  UFG::PedSpawnManager::msPedInfoForLocalZoneChecks = 0i64;
  v34 = &v2->mAmbientPed[0].mShouldCheckZoneInAreaTime;
  v35 = v33;
  v36 = 260i64;
  do
  {
    if ( *((_DWORD *)v34 - 137) )
    {
      UFG::PedSpawnManager::CollectInfoForOne(v2, (UFG::PedSpawningInfo *)(v34 - 179), v35, elapsedTimea);
      if ( *v34 > 0.0
        && (!UFG::PedSpawnManager::msPedInfoForLocalZoneChecks
         || *v34 > UFG::PedSpawnManager::msPedInfoForLocalZoneChecks->mShouldCheckZoneInAreaTime) )
      {
        UFG::PedSpawnManager::msPedInfoForLocalZoneChecks = (UFG::PedSpawningInfo *)(v34 - 179);
      }
    }
    v34 += 206;
    --v36;
  }
  while ( v36 );
  v37 = (signed __int64)v2->mScriptedPed;
  v38 = 120i64;
  do
  {
    if ( *(_DWORD *)(v37 + 168) )
      UFG::PedSpawnManager::CollectInfoForOne(v2, (UFG::PedSpawningInfo *)v37, v35, elapsedTimea);
    v37 += 824i64;
    --v38;
  }
  while ( v38 );
}

// File Line: 8309
// RVA: 0x418180
void __fastcall UFG::PedSpawnManager::Update(UFG::PedSpawnManager *this, float fElapsedTime)
{
  UFG::PedSpawnManager *v2; // rdi
  signed __int64 i; // rbx
  int v4; // edx

  this->mSpawningModeNow = 1;
  v2 = this;
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
  UFG::PedSpawnManager::FrameRateThrottle(v2);
  if ( UFG::PedSpawnManager::msAmbientSpawningEnable )
  {
    UFG::PedSpawnManager::ExamineActiveZones(v2);
    UFG::PedSpawnManager::ExamineInactiveZones(v2);
  }
  UFG::PedSpawnManager::CollectPedInfo(v2, fElapsedTime);
  if ( UFG::PedSpawnManager::msAmbientSpawningEnable || NISManager::GetInstance()->mState == STATE_INVALID )
  {
    for ( i = qword_1423DEF80[0] - 64i64; (_QWORD *)i != &qword_1423DEF80[-8]; i = *(_QWORD *)(i + 64) - 64i64 )
    {
      if ( *(_DWORD *)(i + 344) != 5 )
        UFG::PedSpawningInfo::UpdateProxyAIandAnimation((UFG::PedSpawningInfo *)i, fElapsedTime);
    }
  }
  UFG::PedSpawnManager::CheckActiveStatusOfPeds(v2);
  if ( UFG::PedSpawnManager::msAmbientSpawningEnable )
  {
    v4 = v2->mTargetNumActive + UFG::PedSpawnManager::msAmbientCount[0] - 260;
    if ( v4 < 2 )
    {
      if ( v4 <= 0 )
        goto LABEL_16;
    }
    else
    {
      v4 = 2;
    }
    UFG::PedSpawnManager::SpawnPedsInActiveZones(v2, v4);
  }
LABEL_16:
  if ( UFG::PedSpawnManager::msRequestEmergencyDump )
  {
    UFG::PedSpawnManager::msRequestEmergencyDump = 0;
    UFG::ObjectResourceManager::PerformEmergencyDump();
  }
  v2->mSpawningModeNow = 0;
}

// File Line: 8424
// RVA: 0x4094A0
void __fastcall UFG::PedSpawnManager::CollectAllSpawnInfos(UFG::PedSpawnManager *this, UFG::qPropertyList *list, UFG::qArray<UFG::qPropertySet *,0> *spawnInfoArray)
{
  signed int v3; // ebp
  UFG::qArray<UFG::qPropertySet *,0> *v4; // rdi
  UFG::qPropertyList *v5; // r8
  UFG::PedSpawnManager *v6; // rbx
  UFG::qSymbol *v7; // rax
  UFG::qPropertySet *v8; // rax
  UFG::qPropertyList *v9; // rax
  __int64 v10; // rcx
  unsigned int v11; // ebx
  unsigned int v12; // esi
  unsigned int v13; // ebx
  unsigned __int64 v14; // rax
  UFG::allocator::free_link *v15; // rax
  UFG::qPropertySet **v16; // rbp
  signed __int64 v17; // r9
  signed __int64 v18; // r8
  UFG::qPropertySet **v19; // rax
  unsigned int v20; // [rsp+20h] [rbp-28h]
  signed int v21; // [rsp+24h] [rbp-24h]
  UFG::qPropertySet *v22; // [rsp+28h] [rbp-20h]
  UFG::PedSpawnManager *v23; // [rsp+50h] [rbp+8h]
  UFG::qPropertyList *v24; // [rsp+58h] [rbp+10h]
  signed int v25; // [rsp+68h] [rbp+20h]

  v24 = list;
  v23 = this;
  v3 = 0;
  v4 = spawnInfoArray;
  v5 = list;
  v6 = this;
  v21 = list->mNumElements;
  v25 = 0;
  if ( v21 > 0 )
  {
    do
    {
      v7 = UFG::qPropertyList::Get<UFG::qSymbol>(v5, v3);
      v8 = UFG::PropertySetManager::FindPropertySet(v7);
      v22 = v8;
      v9 = UFG::qPropertySet::Get<UFG::qPropertyList>(v8, (UFG::qSymbol *)&qSymbol_SpawnSet.mUID, DEPTH_RECURSE);
      if ( v9 )
      {
        UFG::PedSpawnManager::CollectAllSpawnInfos(v6, v9, v4);
      }
      else
      {
        v10 = v4->size;
        v11 = v4->capacity;
        v12 = v10 + 1;
        v20 = v4->size;
        if ( (signed int)v10 + 1 > v11 )
        {
          if ( v11 )
            v13 = 2 * v11;
          else
            v13 = 1;
          for ( ; v13 < v12; v13 *= 2 )
            ;
          if ( v13 <= 2 )
            v13 = 2;
          if ( v13 - v12 > 0x10000 )
            v13 = v10 + 65537;
          if ( v13 != (_DWORD)v10 )
          {
            v14 = 8i64 * v13;
            if ( !is_mul_ok(v13, 8ui64) )
              v14 = -1i64;
            v15 = UFG::qMalloc(v14, "spawnInfoArray", 0i64);
            v16 = (UFG::qPropertySet **)v15;
            if ( v4->p )
            {
              v17 = 0i64;
              if ( v4->size )
              {
                do
                {
                  v18 = v17;
                  v17 = (unsigned int)(v17 + 1);
                  v15[v18] = (UFG::allocator::free_link)v4->p[v18];
                }
                while ( (unsigned int)v17 < v4->size );
              }
              operator delete[](v4->p);
            }
            v10 = v20;
            v4->p = v16;
            v3 = v25;
            v4->capacity = v13;
          }
        }
        v19 = v4->p;
        v6 = v23;
        v4->size = v12;
        v19[v10] = v22;
      }
      v5 = v24;
      v25 = ++v3;
    }
    while ( v3 < v21 );
  }
}

// File Line: 8451
// RVA: 0x4150F0
signed __int64 __fastcall UFG::PedSpawnManager::RegisterSpawnSet(UFG::PedSpawnManager *this, UFG::qPropertySet *pSpawnInfoSet, bool needed_for_thug_region)
{
  bool v3; // r12
  UFG::qPropertySet *v4; // r15
  UFG::PedSpawnManager *v5; // rdi
  signed int v6; // ebp
  UFG::ActiveSpawnSetInfo *v7; // rax
  signed int v8; // er9
  __int64 v9; // rax
  signed __int64 v10; // r14
  UFG::qArray<UFG::qPropertySet *,0> *v11; // rsi
  UFG::qPropertySet **v12; // rcx
  signed __int64 v13; // rbx
  void *v14; // rcx
  unsigned int v15; // ebx
  UFG::qPropertyList *v16; // rax
  __int64 v18; // r14
  unsigned int v19; // eax
  unsigned int v20; // edi
  UFG::qPropertySet **v21; // rax

  v3 = needed_for_thug_region;
  v4 = pSpawnInfoSet;
  v5 = this;
  v6 = -1;
  v7 = this->mActiveSpawnSets;
  v8 = 0;
  while ( !v7->mpPropertySet )
  {
    v6 = v8;
LABEL_5:
    ++v8;
    ++v7;
    if ( v8 >= 40 )
      goto LABEL_8;
  }
  if ( v7->mpPropertySet != pSpawnInfoSet )
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
  v11 = &this->mActiveSpawnSets[v10].mSpawnInfoArray;
  v12 = v11->p;
  if ( v12 )
    operator delete[](v12);
  v11->p = 0i64;
  *(_QWORD *)&v11->size = 0i64;
  v13 = 56 * (v6 + 5593i64);
  v14 = *(void **)((char *)&v5->mNumAmbientCurrentlyActive + v13);
  if ( v14 )
    operator delete[](v14);
  *(_QWORD *)((char *)&v5->mNumAmbientCurrentlyActive + v13) = 0i64;
  *(UFG::PedSpawnManagerVtbl **)((char *)&v5->vfptr + v13) = 0i64;
  v15 = 1;
  v5->mActiveSpawnSets[v10].mpPropertySet = v4;
  *(_QWORD *)&v5->mActiveSpawnSets[v10].mRefCount = 1i64;
  v5->mActiveSpawnSets[v10].mPercentOfGlobalPopulation = 0.0;
  v5->mActiveSpawnSets[v10].mMediumPriorityOverride = v3;
  v16 = UFG::qPropertySet::Get<UFG::qPropertyList>(v4, (UFG::qSymbol *)&qSymbol_SpawnSet.mUID, DEPTH_RECURSE);
  if ( v16 )
  {
    UFG::PedSpawnManager::CollectAllSpawnInfos(v5, v16, v11);
  }
  else
  {
    v18 = v11->size;
    v19 = v11->capacity;
    v20 = v18 + 1;
    if ( (signed int)v18 + 1 > v19 )
    {
      if ( v19 )
        v15 = 2 * v19;
      for ( ; v15 < v20; v15 *= 2 )
        ;
      if ( v15 <= 2 )
        v15 = 2;
      if ( v15 - v20 > 0x10000 )
        v15 = v18 + 65537;
      UFG::qArray<UFG::CompositeDrawableComponent *,32>::Reallocate(
        (UFG::qArray<UFG::qReflectInventoryBase *,0> *)v11,
        v15,
        "mActiveSpawnSets");
    }
    v21 = v11->p;
    v11->size = v20;
    v21[v18] = v4;
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
  return atexit(UFG::_dynamic_atexit_destructor_for__gSymDebugSpawnSet__);
}

// File Line: 8634
// RVA: 0x414530
void __fastcall UFG::PedSpawnManager::RegisterActiveSpawnRegion(UFG::PedSpawnManager *this, UFG::SpawnRegion *pRegion, UFG::SceneObjectProperties *pSceneObj)
{
  UFG::qBox *v3; // rdi
  bool v4; // r12
  UFG::qPropertySet *v5; // rax
  int v6; // esi
  UFG::SpawnRegion *v7; // r15
  UFG::PedSpawnManager *v8; // rbx
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
  UFG::qNode<UFG::SpawnZone,UFG::SpawnZoneList> *v32; // rcx
  int v33; // ecx
  UFG::SpawnZone *v34; // rbx
  int v35; // eax
  int v36; // ecx
  float v37; // xmm4_4
  UFG::SpawnRegion *v38; // rax
  float v39; // xmm0_4
  float *v40; // rcx
  float v41; // xmm4_4
  float v42; // xmm6_4
  float v43; // xmm5_4
  float v44; // xmm3_4
  float v45; // xmm2_4
  float v46; // xmm6_4
  UFG::SpawnRegion *v47; // rcx
  float v48; // xmm8_4
  UFG::qNode<UFG::SpawnZone,UFG::SpawnZoneList> *v49; // rax
  UFG::qNode<UFG::SpawnZone,UFG::SpawnZoneList> *v50; // rcx
  UFG::PedSpawnManager *v51; // [rsp+E0h] [rbp+8h]
  int v52; // [rsp+E8h] [rbp+10h]

  v51 = this;
  v3 = pRegion->mRawAABB;
  v4 = pRegion->mIsThugRegion;
  v5 = pRegion->mpCachedSpawnSet;
  v6 = 0;
  v7 = pRegion;
  v8 = this;
  if ( UFG::gUseDebugSpawnset )
  {
    v5 = UFG::PropertySetManager::FindPropertySet((UFG::qSymbol *)&UFG::gSymDebugSpawnSet.mUID);
    v4 = 0;
  }
  v52 = UFG::PedSpawnManager::RegisterSpawnSet(v8, v5, v4);
  v9 = FLOAT_8_0;
  v10 = 0.0;
  v11 = v3->mMax.x - v3->mMin.x;
  v12 = v3->mMax.y - v3->mMin.y;
  if ( v4 )
    v9 = FLOAT_1000_0;
  v13 = 0;
  v14 = 0.0;
  if ( v11 <= v12 )
  {
    do
    {
      v33 = UFG::PedSpawnManager::msSpawnZoneFreeIndex;
      if ( UFG::PedSpawnManager::msSpawnZoneFreeIndex >= 900 )
        break;
      v34 = UFG::PedSpawnManager::msSpawnZoneFreePtrs[UFG::PedSpawnManager::msSpawnZoneFreeIndex];
      UFG::PedSpawnManager::msSpawnZoneFreePtrs[UFG::PedSpawnManager::msSpawnZoneFreeIndex] = 0i64;
      UFG::PedSpawnManager::msSpawnZoneFreeIndex = v33 + 1;
      if ( !v34 )
        break;
      v34->mpPoint = 0i64;
      v34->mpInterestPoint = 0i64;
      v34->mpRegion = v7;
      v34->mIsThugZone = v4;
      UFG::SpawnRegion::AddZone(v7, v34);
      v34->mTimeStamp = -999.0;
      v34->mSpawnSetIndex = v52;
      *(_WORD *)&v34->mIsRegion = 1;
      v34->mZoneActiveStatus = 1;
      *(_QWORD *)&v34->mSpawnCount = 0i64;
      *(_QWORD *)&v34->mNumDeadPeds = 0i64;
      v35 = UFG::PedSpawnManager::msMaxNumOfRegisteredZones;
      v36 = UFG::PedSpawnManager::msNumOfRegisteredSpawnZones + 1;
      UFG::PedSpawnManager::msNumOfRegisteredSpawnZones = v36;
      if ( v36 > UFG::PedSpawnManager::msMaxNumOfRegisteredZones )
        v35 = v36;
      UFG::PedSpawnManager::msMaxNumOfRegisteredZones = v35;
      v34->mRetryTime = -1.0;
      v34->mLocalAABB.mMin.x = v3->mMin.x;
      v34->mLocalAABB.mMin.z = v3->mMin.z;
      v34->mLocalAABB.mMax.x = v3->mMax.x;
      v34->mLocalAABB.mMax.z = v3->mMax.z + 0.69999999;
      v34->mLocalAABB.mMin.y = v10 + v3->mMin.y;
      v34->mTimeLoaded = UFG::PedSpawnManager::msElapsedTotal;
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
      v37 = v34->mLocalAABB.mMin.x;
      v38 = v34->mpRegion;
      v39 = v10 + v3->mMin.y;
      v34->mLocalAABB.mMax.y = v39;
      v40 = &v38->mWorldXForm->v0.x;
      v41 = (float)(v37 + v34->mLocalAABB.mMax.x) * 0.5;
      v42 = (float)(v34->mLocalAABB.mMin.y + v39) * 0.5;
      v43 = (float)(v34->mLocalAABB.mMin.z + v34->mLocalAABB.mMax.z) * 0.5;
      v44 = (float)(v42 * v40[4]) + (float)(v41 * *v40);
      v45 = (float)((float)((float)(v42 * v40[5]) + (float)(v41 * v40[1])) + (float)(v43 * v40[9])) + v40[13];
      v46 = (float)((float)((float)(v42 * v40[6]) + (float)(v41 * v40[2])) + (float)(v43 * v40[10])) + v40[14];
      v34->mZoneCentre.x = (float)(v44 + (float)(v43 * v40[8])) + v40[12];
      v34->mZoneCentre.y = v45;
      v34->mZoneCentre.z = v46;
      v47 = v34->mpRegion;
      if ( v47 )
      {
        v48 = UFG::SpawnRegion::GetTargetPopulation(
                v47,
                (float)(v34->mLocalAABB.mMax.y - v34->mLocalAABB.mMin.y)
              * (float)(v34->mLocalAABB.mMax.x - v34->mLocalAABB.mMin.x))
            + v14;
        v34->mSpawnCount = (signed int)(float)(v48 + 0.5);
        v14 = v48 - (float)(signed int)(float)(v48 + 0.5);
      }
      else
      {
        v34->mSpawnCount = 1;
        v14 = 0.0;
      }
      v6 += v34->mSpawnCount;
      UFG::SpawnZone::AllocatePersistentCullInfo(v34);
      v49 = UFG::PedSpawnManager::msSpawnZoneList.mNode.mNext;
      v50 = (UFG::qNode<UFG::SpawnZone,UFG::SpawnZoneList> *)&v34->mPrev;
      UFG::PedSpawnManager::msSpawnZoneList.mNode.mNext = v50;
      v50->mPrev = (UFG::qNode<UFG::SpawnZone,UFG::SpawnZoneList> *)&UFG::PedSpawnManager::msSpawnZoneList;
      v50->mNext = v49;
      v49->mPrev = (UFG::qNode<UFG::SpawnZone,UFG::SpawnZoneList> *)&v34->mPrev;
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
      v16->mpRegion = v7;
      v16->mIsThugZone = v4;
      UFG::SpawnRegion::AddZone(v7, v16);
      v16->mTimeStamp = -999.0;
      v16->mSpawnSetIndex = v52;
      *(_WORD *)&v16->mIsRegion = 1;
      v16->mZoneActiveStatus = 1;
      *(_QWORD *)&v16->mSpawnCount = 0i64;
      *(_QWORD *)&v16->mNumDeadPeds = 0i64;
      v17 = UFG::PedSpawnManager::msMaxNumOfRegisteredZones;
      v18 = UFG::PedSpawnManager::msNumOfRegisteredSpawnZones + 1;
      UFG::PedSpawnManager::msNumOfRegisteredSpawnZones = v18;
      if ( v18 > UFG::PedSpawnManager::msMaxNumOfRegisteredZones )
        v17 = v18;
      UFG::PedSpawnManager::msMaxNumOfRegisteredZones = v17;
      v16->mRetryTime = -1.0;
      v16->mLocalAABB.mMin.y = v3->mMin.y;
      v16->mLocalAABB.mMin.z = v3->mMin.z;
      v16->mLocalAABB.mMax.y = v3->mMax.y;
      v16->mLocalAABB.mMax.z = v3->mMax.z + 0.69999999;
      v16->mLocalAABB.mMin.x = v10 + v3->mMin.x;
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
      v21 = v10 + v3->mMin.x;
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
        v16->mSpawnCount = (signed int)(float)(v30 + 0.5);
        v14 = v30 - (float)(signed int)(float)(v30 + 0.5);
      }
      else
      {
        v16->mSpawnCount = 1;
        v14 = 0.0;
      }
      v6 += v16->mSpawnCount;
      UFG::SpawnZone::AllocatePersistentCullInfo(v16);
      v31 = UFG::PedSpawnManager::msSpawnZoneList.mNode.mNext;
      v32 = (UFG::qNode<UFG::SpawnZone,UFG::SpawnZoneList> *)&v16->mPrev;
      UFG::PedSpawnManager::msSpawnZoneList.mNode.mNext = v32;
      v32->mPrev = (UFG::qNode<UFG::SpawnZone,UFG::SpawnZoneList> *)&UFG::PedSpawnManager::msSpawnZoneList;
      v32->mNext = v31;
      v31->mPrev = (UFG::qNode<UFG::SpawnZone,UFG::SpawnZoneList> *)&v16->mPrev;
    }
    while ( !v13 );
  }
  v51->mActiveSpawnSets[v52].mPopulationPotential += v6;
}

// File Line: 8798
// RVA: 0x4143C0
signed __int64 __fastcall UFG::PedSpawnManager::RegisterActiveSpawnPoint(UFG::PedSpawnManager *this, UFG::SpawnPoint *pPoint, UFG::SceneObjectProperties *pSpawnSceneObj)
{
  int v3; // er9
  UFG::SpawnPoint *v4; // rbp
  UFG::PedSpawnManager *v5; // r14
  UFG::TransformNodeComponent *v6; // rsi
  UFG::SpawnZone *v7; // rdi
  bool v8; // bl
  UFG::qPropertySet *v9; // rax
  int v10; // eax
  UFG::SpawnPoint *v11; // rax
  UFG::SimObject *v12; // rcx
  float v13; // eax
  UFG::qNode<UFG::SpawnZone,UFG::SpawnZoneList> *v14; // rdx
  float v15; // xmm1_4
  UFG::qNode<UFG::SpawnZone,UFG::SpawnZoneList> *v16; // rcx

  v3 = UFG::PedSpawnManager::msSpawnZoneFreeIndex;
  v4 = pPoint;
  v5 = this;
  if ( UFG::PedSpawnManager::msSpawnZoneFreeIndex >= 900 )
    return 0xFFFFFFFFi64;
  v6 = 0i64;
  v7 = UFG::PedSpawnManager::msSpawnZoneFreePtrs[UFG::PedSpawnManager::msSpawnZoneFreeIndex];
  UFG::PedSpawnManager::msSpawnZoneFreePtrs[UFG::PedSpawnManager::msSpawnZoneFreeIndex] = 0i64;
  UFG::PedSpawnManager::msSpawnZoneFreeIndex = v3 + 1;
  if ( !v7 )
    return 0xFFFFFFFFi64;
  v8 = pPoint->mThugPoint;
  v9 = (UFG::qPropertySet *)UFG::SceneObjectProperties::GetArchetypeProperties(pSpawnSceneObj);
  v10 = UFG::PedSpawnManager::RegisterSpawnSet(v5, v9, 0);
  v7->mpPoint = v4;
  v7->mIsThugZone = v8;
  v7->mSpawnSetIndex = v10;
  v7->mpRegion = 0i64;
  v7->mpInterestPoint = 0i64;
  v7->mTimeStamp = -999.0;
  *(_WORD *)&v7->mIsRegion = 0;
  *(_QWORD *)&v7->mSpawnCount = 1i64;
  *(_QWORD *)&v7->mNumDeadPeds = 0i64;
  v7->mZoneActiveStatus = 1;
  ++UFG::PedSpawnManager::msNumOfRegisteredSpawnZones;
  v11 = v7->mpPoint;
  v7->mRetryTime = -1.0;
  v12 = v11->m_pSimObject;
  if ( v12 )
    v6 = v12->m_pTransformNodeComponent;
  UFG::TransformNodeComponent::UpdateWorldTransform(v6);
  v13 = v6->mWorldTransform.v3.x;
  v14 = (UFG::qNode<UFG::SpawnZone,UFG::SpawnZoneList> *)&v7->mPrev;
  v15 = v6->mWorldTransform.v3.z;
  v7->mZoneCentre.y = v6->mWorldTransform.v3.y;
  v7->mZoneCentre.z = v15;
  v7->mZoneCentre.x = v13;
  v16 = UFG::PedSpawnManager::msSpawnZoneList.mNode.mNext;
  UFG::PedSpawnManager::msSpawnZoneList.mNode.mNext = v14;
  v14->mNext = v16;
  v14->mPrev = (UFG::qNode<UFG::SpawnZone,UFG::SpawnZoneList> *)&UFG::PedSpawnManager::msSpawnZoneList;
  v16->mPrev = (UFG::qNode<UFG::SpawnZone,UFG::SpawnZoneList> *)&v7->mPrev;
  v7->mTimeLoaded = UFG::PedSpawnManager::msElapsedTotal;
  v7->mHasBeenActivated = 0;
  UFG::SpawnZone::AllocatePersistentCullInfo(v7);
  return (unsigned int)v7->mZoneIndex;
}

// File Line: 8843
// RVA: 0x4152A0
void __fastcall UFG::PedSpawnManager::RegisterSpawningPOI(UFG::PedSpawnManager *this, UFG::InterestPoint *pPOI, UFG::SceneObjectProperties *pSceneObj)
{
  int v3; // ecx
  UFG::SpawnZone *v4; // rbx
  UFG::qVector3 *v5; // rax
  UFG::qNode<UFG::SpawnZone,UFG::SpawnZoneList> *v6; // rdx
  float v7; // xmm0_4
  float v8; // xmm1_4
  UFG::qNode<UFG::SpawnZone,UFG::SpawnZoneList> *v9; // rax
  float v10; // xmm0_4

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
      v4->mZoneActiveStatus = 1;
      ++UFG::PedSpawnManager::msNumOfRegisteredSpawnZones;
      v4->mRetryTime = -1.0;
      v5 = UFG::InterestPoint::GetPosition(pPOI);
      v6 = (UFG::qNode<UFG::SpawnZone,UFG::SpawnZoneList> *)&v4->mPrev;
      v7 = v5->y;
      v8 = v5->z;
      v4->mZoneCentre.x = v5->x;
      v4->mZoneCentre.y = v7;
      v4->mZoneCentre.z = v8;
      v9 = UFG::PedSpawnManager::msSpawnZoneList.mNode.mNext;
      UFG::PedSpawnManager::msSpawnZoneList.mNode.mNext = v6;
      v6->mPrev = (UFG::qNode<UFG::SpawnZone,UFG::SpawnZoneList> *)&UFG::PedSpawnManager::msSpawnZoneList;
      v6->mNext = v9;
      v9->mPrev = (UFG::qNode<UFG::SpawnZone,UFG::SpawnZoneList> *)&v4->mPrev;
      v10 = UFG::PedSpawnManager::msElapsedTotal;
      v4->mHasBeenActivated = 0;
      v4->mTimeLoaded = v10;
      UFG::SpawnZone::AllocatePersistentCullInfo(v4);
    }
  }
}

// File Line: 8876
// RVA: 0x4180C0
void __fastcall UFG::PedSpawnManager::UnRegisterSpawningPOI(UFG::PedSpawnManager *this, UFG::InterestPoint *pPOI, UFG::SceneObjectProperties *pSceneObj)
{
  UFG::SpawnZone *v3; // rcx

  v3 = (UFG::SpawnZone *)&UFG::PedSpawnManager::msActiveZoneList.mNode.mNext[-2].mNext;
  if ( (UFG::qNode<UFG::PedSpawningInfo,UFG::PedSpawningInfo_DrawList> **)&UFG::PedSpawnManager::msActiveZoneList.mNode.mNext[-2].mNext == &UFG::PedSpawningInfo::smNoDrawList.mNode.mNext )
  {
LABEL_4:
    v3 = (UFG::SpawnZone *)&UFG::PedSpawnManager::msSpawnZoneList.mNode.mNext[-2].mNext;
    if ( (UFG::qNode<UFG::PedSpawningInfo,UFG::PedSpawningInfo_DrawList> **)&UFG::PedSpawnManager::msSpawnZoneList.mNode.mNext[-2].mNext == &UFG::PedSpawningInfo::smDrawList.mNode.mNext )
    {
LABEL_7:
      v3 = (UFG::SpawnZone *)&UFG::PedSpawnManager::msShouldBeActiveZoneList.mNode.mNext[-2].mNext;
      if ( &UFG::PedSpawnManager::msShouldBeActiveZoneList.mNode.mNext[-2].mNext == &UFG::PedSpawnManager::msSpawnZoneList.mNode.mNext )
        return;
      while ( v3->mpInterestPoint != pPOI )
      {
        v3 = (UFG::SpawnZone *)&v3->mNext[-2].mNext;
        if ( v3 == (UFG::SpawnZone *)&UFG::PedSpawnManager::msSpawnZoneList.mNode.mNext )
          return;
      }
    }
    else
    {
      while ( v3->mpInterestPoint != pPOI )
      {
        v3 = (UFG::SpawnZone *)&v3->mNext[-2].mNext;
        if ( v3 == (UFG::SpawnZone *)&UFG::PedSpawningInfo::smDrawList.mNode.mNext )
          goto LABEL_7;
      }
    }
  }
  else
  {
    while ( v3->mpInterestPoint != pPOI )
    {
      v3 = (UFG::SpawnZone *)&v3->mNext[-2].mNext;
      if ( v3 == (UFG::SpawnZone *)&UFG::PedSpawningInfo::smNoDrawList.mNode.mNext )
        goto LABEL_4;
    }
  }
  UFG::PedSpawnManager::msSpawnZoneFreePtrs[--UFG::PedSpawnManager::msSpawnZoneFreeIndex] = v3;
  UFG::SpawnZone::OnZoneFree(v3);
}

// File Line: 8935
// RVA: 0x4156C0
signed __int64 __fastcall UFG::PedSpawnManager::ReleaseRefToSpawnInfo(UFG::PedSpawnManager *this, UFG::qPropertySet *pSpawnInfoSet)
{
  UFG::qPropertySet *v2; // r8
  UFG::PedSpawnManager *v3; // rdi
  UFG::ActiveSpawnSetInfo *v4; // rax
  signed int v5; // edx
  signed __int64 v6; // rcx
  __int64 v8; // rsi
  signed __int64 v9; // rbx
  bool v10; // zf
  void *v11; // rcx
  UFG::PedSpawnManagerVtbl **v12; // rbx
  UFG::PedSpawnManagerVtbl *v13; // rcx

  v2 = pSpawnInfoSet;
  v3 = this;
  if ( UFG::gUseDebugSpawnset )
    v2 = UFG::PropertySetManager::FindPropertySet((UFG::qSymbol *)&UFG::gSymDebugSpawnSet.mUID);
  if ( !v2 )
    return 0xFFFFFFFFi64;
  v4 = v3->mActiveSpawnSets;
  v5 = 0;
  v6 = 0i64;
  while ( v4->mpPropertySet != v2 )
  {
    ++v6;
    ++v5;
    ++v4;
    if ( v6 >= 40 )
      return 0xFFFFFFFFi64;
  }
  v8 = v5;
  v9 = (signed __int64)v3 + 56 * v5;
  v10 = (*(_DWORD *)(v9 + 313176))-- == 1;
  if ( v10 )
  {
    *(_QWORD *)(v9 + 313168) = 0i64;
    *(_BYTE *)(v9 + 313188) = 0;
    v11 = *(void **)(v9 + 313200);
    if ( v11 )
      operator delete[](v11);
    *(_QWORD *)(v9 + 313200) = 0i64;
    *(_QWORD *)(v9 + 313192) = 0i64;
    v12 = &v3->vfptr + 7 * (v8 + 5593);
    v13 = v12[1];
    if ( v13 )
      operator delete[](v13);
    v12[1] = 0i64;
    *v12 = 0i64;
    v5 = -1;
  }
  return (unsigned int)v5;
}

// File Line: 8973
// RVA: 0x416620
void __fastcall UFG::PedSpawnManager::SetAmbientStartingMode(UFG::PedSpawnManager *this, UFG::PedSpawningInfo *info, UFG::qVector3 *pos)
{
  UFG::PedSpawningInfo::eActiveStatus v3; // esi
  UFG::PedSpawningInfo *v4; // rbx
  UFG::PedSpawnManager *v5; // rdi
  UFG::PedSpawningInfo::eActiveStatus v6; // edx

  v3 = info->mActiveStatus;
  v4 = info;
  v5 = this;
  if ( UFG::PedSpawnManager::msAmbientSpawningEnable && UFG::PedSpawnManager::msAmbientStatusCheckEnable )
  {
    if ( (signed int)UFG::PedSpawnManager::GetActiveZoneFromPoint(this, pos, Active) <= 1 )
      return;
    v6 = 2;
  }
  else
  {
    v6 = 3;
  }
  if ( v6 != v3 )
    UFG::PedSpawnManager::ChangeActiveStatus(v5, v6, v4);
}

// File Line: 9002
// RVA: 0x416240
void __fastcall UFG::PedSpawnManager::SceneLayerActivatedEventHandler(UFG::Event *event)
{
  UFG::PedSpawnManager::msShouldUpdatePopulationStats = 1;
}

// File Line: 9009
// RVA: 0x418040
void __fastcall UFG::PedSpawnManager::UnRegisterActiveSpawnRegion(UFG::PedSpawnManager *this, UFG::SpawnRegion *pRegion)
{
  UFG::SpawnRegion *v2; // rbx
  UFG::PedSpawnManager *v3; // rdi
  int v4; // eax
  signed __int64 v5; // r8
  signed __int64 v6; // rcx
  int v7; // eax

  v2 = pRegion;
  v3 = this;
  v4 = UFG::PedSpawnManager::ReleaseRefToSpawnInfo(this, pRegion->mpCachedSpawnSet);
  if ( v4 >= 0 )
  {
    v5 = (signed __int64)&v2->mZones.mNode.mNext[-3].mNext;
    if ( (UFG::SpawnRegion *)v5 != (UFG::SpawnRegion *)&v2->mWorldToLocal.v2.z )
    {
      v6 = v4;
      v7 = v3->mActiveSpawnSets[v6].mPopulationPotential;
      do
      {
        v7 -= *(_DWORD *)(v5 + 136);
        v3->mActiveSpawnSets[v6].mPopulationPotential = v7;
        v5 = *(_QWORD *)(v5 + 48) - 40i64;
      }
      while ( (UFG::SpawnRegion *)v5 != (UFG::SpawnRegion *)&v2->mWorldToLocal.v2.z );
    }
  }
}

// File Line: 9025
// RVA: 0x4182E0
void __fastcall UFG::PedSpawnManager::UpdateActiveSpawnRegion(UFG::PedSpawnManager *this, UFG::SpawnRegion *pRegion, bool regionIsRegistered)
{
  UFG::SpawnRegion *v3; // rbp
  UFG::PedSpawnManager *v4; // rdi
  bool v5; // r8
  UFG::qPropertySet *v6; // rax
  int v7; // eax
  UFG::qNode<UFG::SpawnZone,UFG::SpawnRegionList> *v8; // rbx
  float v9; // xmm6_4
  signed __int64 v10; // rbp
  signed __int64 v11; // rbx
  signed __int64 i; // rsi
  UFG::SpawnRegion *v13; // rcx
  float v14; // xmm6_4

  v3 = pRegion;
  v4 = this;
  if ( regionIsRegistered )
    UFG::PedSpawnManager::UnRegisterActiveSpawnRegion(this, pRegion);
  v5 = v3->mIsThugRegion;
  v6 = v3->mpCachedSpawnSet;
  if ( UFG::gUseDebugSpawnset )
  {
    v6 = UFG::PropertySetManager::FindPropertySet((UFG::qSymbol *)&UFG::gSymDebugSpawnSet.mUID);
    v5 = 0;
  }
  v7 = UFG::PedSpawnManager::RegisterSpawnSet(v4, v6, v5);
  if ( v7 >= 0 )
  {
    v8 = v3->mZones.mNode.mNext;
    v9 = 0.0;
    v10 = (signed __int64)&v3->mWorldToLocal.v2.z;
    v11 = (signed __int64)&v8[-3].mNext;
    for ( i = v7; v11 != v10; v11 = *(_QWORD *)(v11 + 48) - 40i64 )
    {
      v13 = *(UFG::SpawnRegion **)(v11 + 64);
      if ( v13 )
      {
        v14 = UFG::SpawnRegion::GetTargetPopulation(
                v13,
                (float)(*(float *)(v11 + 104) - *(float *)(v11 + 92))
              * (float)(*(float *)(v11 + 100) - *(float *)(v11 + 88)))
            + v9;
        *(_DWORD *)(v11 + 136) = (signed int)(float)(v14 + 0.5);
        v9 = v14 - (float)(signed int)(float)(v14 + 0.5);
      }
      else
      {
        *(_DWORD *)(v11 + 136) = 1;
        v9 = 0.0;
      }
      v4->mActiveSpawnSets[i].mPopulationPotential += *(_DWORD *)(v11 + 136);
    }
  }
}

// File Line: 9057
// RVA: 0x417EC0
void __fastcall UFG::PedSpawnManager::UnRegisterActiveSpawnPoint(UFG::PedSpawnManager *this, UFG::SpawnPoint *pPoint, UFG::SceneObjectProperties *pSceneObj)
{
  UFG::PedSpawnManager *v3; // rbp
  UFG::SceneObjectProperties *v4; // r14
  UFG::SpawnZone *v5; // rcx
  unsigned int v6; // esi
  unsigned int v7; // edi
  UFG::SceneObjectProperties *v8; // rax
  UFG::SceneObjectProperties *v9; // rbx
  UFG::qResourceData *v10; // rax
  signed __int64 v11; // rcx
  UFG::ActiveSpawnSetInfo *v12; // rdx
  signed __int64 v13; // rcx
  bool v14; // zf

  v3 = this;
  v4 = pSceneObj;
  v5 = (UFG::SpawnZone *)&UFG::PedSpawnManager::msActiveZoneList.mNode.mNext[-2].mNext;
  if ( (UFG::qNode<UFG::PedSpawningInfo,UFG::PedSpawningInfo_DrawList> **)&UFG::PedSpawnManager::msActiveZoneList.mNode.mNext[-2].mNext == &UFG::PedSpawningInfo::smNoDrawList.mNode.mNext )
  {
LABEL_4:
    v5 = (UFG::SpawnZone *)&UFG::PedSpawnManager::msSpawnZoneList.mNode.mNext[-2].mNext;
    if ( (UFG::qNode<UFG::PedSpawningInfo,UFG::PedSpawningInfo_DrawList> **)&UFG::PedSpawnManager::msSpawnZoneList.mNode.mNext[-2].mNext == &UFG::PedSpawningInfo::smDrawList.mNode.mNext )
    {
LABEL_7:
      v5 = (UFG::SpawnZone *)&UFG::PedSpawnManager::msShouldBeActiveZoneList.mNode.mNext[-2].mNext;
      if ( &UFG::PedSpawnManager::msShouldBeActiveZoneList.mNode.mNext[-2].mNext == &UFG::PedSpawnManager::msSpawnZoneList.mNode.mNext )
        return;
      while ( v5->mpPoint != pPoint )
      {
        v5 = (UFG::SpawnZone *)&v5->mNext[-2].mNext;
        if ( v5 == (UFG::SpawnZone *)&UFG::PedSpawnManager::msSpawnZoneList.mNode.mNext )
          return;
      }
    }
    else
    {
      while ( v5->mpPoint != pPoint )
      {
        v5 = (UFG::SpawnZone *)&v5->mNext[-2].mNext;
        if ( v5 == (UFG::SpawnZone *)&UFG::PedSpawningInfo::smDrawList.mNode.mNext )
          goto LABEL_7;
      }
    }
  }
  else
  {
    while ( v5->mpPoint != pPoint )
    {
      v5 = (UFG::SpawnZone *)&v5->mNext[-2].mNext;
      if ( v5 == (UFG::SpawnZone *)&UFG::PedSpawningInfo::smNoDrawList.mNode.mNext )
        goto LABEL_4;
    }
  }
  UFG::PedSpawnManager::msSpawnZoneFreePtrs[--UFG::PedSpawnManager::msSpawnZoneFreeIndex] = v5;
  UFG::SpawnZone::OnZoneFree(v5);
  v6 = v4->mChildren.mCount;
  v7 = 0;
  if ( v6 )
  {
    do
    {
      v8 = UFG::SceneObjectProperties::GetChildAsSceneObject(v4, v7);
      v9 = v8;
      if ( v8 )
      {
        if ( (unsigned int)UFG::SimObjectPropertiesComponent::GetChildType(v8) == 1 )
        {
          v10 = UFG::SceneObjectProperties::GetArchetypeProperties(v9);
          if ( v10 )
          {
            v11 = 0i64;
            v12 = v3->mActiveSpawnSets;
            while ( (UFG::qResourceData *)v12->mpPropertySet != v10 )
            {
              ++v11;
              ++v12;
              if ( v11 >= 40 )
                goto LABEL_21;
            }
            v13 = v11;
            v14 = v3->mActiveSpawnSets[v13].mRefCount-- == 1;
            if ( v14 )
              v3->mActiveSpawnSets[v13].mpPropertySet = 0i64;
          }
        }
      }
LABEL_21:
      ++v7;
    }
    while ( v7 < v6 );
  }
}

// File Line: 9154
// RVA: 0x418830
void __fastcall UFG::PedSpawnManager::UpdatePopulationResourceStats(UFG::PedSpawnManager *this)
{
  signed int v1; // edx
  int *v2; // rcx
  int *v3; // rax
  signed __int64 v4; // r8
  float v5; // xmm1_4
  signed __int64 v6; // rax

  v1 = 0;
  v2 = &this->mActiveSpawnSets[0].mPopulationPotential;
  v3 = v2;
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
    if ( *(_QWORD *)(v2 - 3) )
      *((float *)v2 + 1) = (float)*v2 * v5;
    if ( *(_QWORD *)(v2 + 11) )
      *((float *)v2 + 15) = (float)v2[14] * v5;
    if ( *(_QWORD *)(v2 + 25) )
      *((float *)v2 + 29) = (float)v2[28] * v5;
    if ( *(_QWORD *)(v2 + 39) )
      *((float *)v2 + 43) = (float)v2[42] * v5;
    if ( *(_QWORD *)(v2 + 53) )
      *((float *)v2 + 57) = (float)v2[56] * v5;
    if ( *(_QWORD *)(v2 + 67) )
      *((float *)v2 + 71) = (float)v2[70] * v5;
    if ( *(_QWORD *)(v2 + 81) )
      *((float *)v2 + 85) = (float)v2[84] * v5;
    if ( *(_QWORD *)(v2 + 95) )
      *((float *)v2 + 99) = (float)v2[98] * v5;
    if ( *(_QWORD *)(v2 + 109) )
      *((float *)v2 + 113) = (float)v2[112] * v5;
    if ( *(_QWORD *)(v2 + 123) )
      *((float *)v2 + 127) = (float)v2[126] * v5;
    v2 += 140;
    --v6;
  }
  while ( v6 );
}

// File Line: 9536
// RVA: 0x413F20
void __fastcall UFG::PedSpawnManager::ReInitAmbient(UFG::PedSpawnManager *this)
{
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> **v1; // rbx
  signed __int64 v2; // rbp
  UFG::SimObject *v3; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v4; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rax
  _QWORD *v6; // rax
  __int64 v7; // rcx

  v1 = &this->mAmbientPed[0].mUpgradePOI.mNext;
  v2 = 260i64;
  do
  {
    v3 = (UFG::SimObject *)*(v1 - 63);
    if ( v3 )
    {
      if ( v3->m_pSceneObj->mpParent )
        UFG::SceneObjectProperties::DeactivateDeferred(v3->m_pSceneObj);
      else
        UFG::SimObject::Destroy(v3);
    }
    UFG::PedSpawningInfo::MakeCompletelyInactive((UFG::PedSpawningInfo *)(v1 - 87));
    *((_DWORD *)v1 - 10) = 0;
    if ( *(v1 - 42) )
      UFG::TrueCrowdSet::Instance::RemoveProxyReference(
        (UFG::TrueCrowdSet::Instance *)(v1 - 42),
        (UFG::PedSpawningInfo *)(v1 - 87));
    *(v1 - 42) = 0i64;
    *((_DWORD *)v1 - 82) = 0;
    *((UFG::qSymbolUC *)v1 - 14) = UFG::gNullQSymbolUC;
    *((UFG::qSymbol *)v1 - 11) = UFG::gNullQSymbol;
    *((UFG::qSymbol *)v1 - 86) = UFG::gNullQSymbol;
    *(v1 - 52) = 0i64;
    if ( v1[1] )
    {
      v4 = *(v1 - 1);
      v5 = *v1;
      v4->mNext = *v1;
      v5->mPrev = v4;
      *(v1 - 1) = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)(v1 - 1);
      *v1 = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)(v1 - 1);
    }
    v1[1] = 0i64;
    if ( *(v1 - 67) )
    {
      v6 = *(v1 - 68);
      v7 = (__int64)*(v1 - 69);
      *(_QWORD *)(v7 + 8) = v6;
      *v6 = v7;
      *(v1 - 69) = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)(v1 - 69);
      *(v1 - 68) = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)(v1 - 69);
    }
    *(v1 - 67) = 0i64;
    *((_BYTE *)v1 - 348) = 0;
    *((_BYTE *)v1 + 24) = 0;
    *((_DWORD *)v1 + 5) = 0;
    *(UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> **)((char *)v1 - 564) = 0i64;
    *((_BYTE *)v1 + 68) = 1;
    *((_DWORD *)v1 + 31) = -1;
    v1 += 103;
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
  signed __int64 v2; // rsi
  __int64 v3; // rdx
  bool v4; // zf
  UFG::qNode<UFG::PedSpawningInfo,UFG::PedInfoList> *v5; // rcx
  UFG::qNode<UFG::PedSpawningInfo,UFG::PedInfoList> *v6; // rax
  UFG::qNode<UFG::PedSpawningInfo,UFG::PedInfoList> *v7; // rax
  UFG::qNode<UFG::PedSpawningInfo,UFG::PedInfoList> *v8; // rax
  signed int v9; // eax
  UFG::TransformNodeComponent *v10; // rdi

  v1 = (UFG::qNode<UFG::PedSpawningInfo,UFG::PedInfoList> *)&this->mScriptedPed[0].mPrev;
  v2 = 120i64;
  do
  {
    if ( (unsigned int)(LODWORD(v1[6].mNext) - 1) <= 1 )
    {
      UFG::SimObject::Suspend((UFG::SimObject *)v1[8].mPrev);
      v3 = SLODWORD(v1[6].mNext);
      HIDWORD(v1[4].mPrev) = 0;
      BYTE4(v1[43].mNext) = 0;
      if ( (_DWORD)v3 != 3 )
      {
        v4 = LODWORD(v1[47].mPrev) == 1;
        v5 = v1->mPrev;
        v6 = v1->mNext;
        v5->mNext = v6;
        v6->mPrev = v5;
        v1->mPrev = v1;
        v1->mNext = v1;
        if ( v4 )
        {
          v7 = (UFG::qNode<UFG::PedSpawningInfo,UFG::PedInfoList> *)unk_1423DEF98;
          --UFG::PedSpawnManager::msAmbientCount[v3];
          unk_1423DEF98 = v1;
          v1->mNext = v7;
          v1->mPrev = (UFG::qNode<UFG::PedSpawningInfo,UFG::PedInfoList> *)&unk_1423DEF90;
          v7->mPrev = v1;
          ++HIDWORD(qword_1423DC628);
        }
        else
        {
          v8 = UFG::PedSpawnManager::msScriptedList[3].mNode.mPrev;
          --UFG::PedSpawnManager::msScriptedCount[v3];
          v8->mNext = v1;
          v1->mPrev = v8;
          v1->mNext = &UFG::PedSpawnManager::msScriptedList[3].mNode;
          ++HIDWORD(qword_1423DC640);
          UFG::PedSpawnManager::msScriptedList[3].mNode.mPrev = v1;
        }
        LODWORD(v1[6].mNext) = 3;
        UFG::PedSpawningInfo::AllocatePersistentCullInfo((UFG::PedSpawningInfo *)&v1[-4]);
        v9 = (signed int)v1[6].mNext;
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
  bool v2; // bp
  UFG::PedSpawnManager *v3; // rsi
  UFG::SimObjectGame **v4; // rbx
  signed __int64 v5; // rdi
  UFG::SimObjectGame *v6; // rcx
  unsigned __int16 v7; // r8
  UFG::FaceActionComponent *v8; // rax
  UFG::SimObjectGame **v9; // rbx
  signed __int64 v10; // rdi
  UFG::SimObjectGame *v11; // rcx
  unsigned __int16 v12; // dx
  UFG::FaceActionComponent *v13; // rax

  v2 = bNISStarting;
  v3 = this;
  v4 = (UFG::SimObjectGame **)&this->mScriptedPed[0].mSimObjectPtr.m_pPointer;
  v5 = 120i64;
  do
  {
    v6 = *v4;
    if ( *v4 )
    {
      v7 = v6->m_Flags;
      if ( (v7 >> 14) & 1 )
      {
        v8 = (UFG::FaceActionComponent *)v6->m_Components.p[45].m_pComponent;
      }
      else if ( (v7 & 0x8000u) == 0 )
      {
        if ( (v7 >> 13) & 1 )
          v8 = (UFG::FaceActionComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                             v6,
                                             UFG::FaceActionComponent::_TypeUID);
        else
          v8 = (UFG::FaceActionComponent *)((v7 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                               v6,
                                                               UFG::FaceActionComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v6->vfptr, UFG::FaceActionComponent::_TypeUID));
      }
      else
      {
        v8 = (UFG::FaceActionComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                           v6,
                                           UFG::FaceActionComponent::_TypeUID);
      }
      if ( v8 )
        UFG::FaceActionComponent::SetupSocialForNIS(v8, v2);
    }
    v4 += 103;
    --v5;
  }
  while ( v5 );
  v9 = (UFG::SimObjectGame **)&v3->mAmbientPed[0].mSimObjectPtr.m_pPointer;
  v10 = 260i64;
  do
  {
    v11 = *v9;
    if ( *v9 )
    {
      v12 = v11->m_Flags;
      if ( (v12 >> 14) & 1 )
      {
        v13 = (UFG::FaceActionComponent *)v11->m_Components.p[45].m_pComponent;
      }
      else if ( (v12 & 0x8000u) == 0 )
      {
        if ( (v12 >> 13) & 1 )
        {
          v13 = (UFG::FaceActionComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                              v11,
                                              UFG::FaceActionComponent::_TypeUID);
        }
        else if ( (v12 >> 12) & 1 )
        {
          v13 = (UFG::FaceActionComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                              v11,
                                              UFG::FaceActionComponent::_TypeUID);
        }
        else
        {
          v13 = (UFG::FaceActionComponent *)UFG::SimObject::GetComponentOfType(
                                              (UFG::SimObject *)&v11->vfptr,
                                              UFG::FaceActionComponent::_TypeUID);
        }
      }
      else
      {
        v13 = (UFG::FaceActionComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                            v11,
                                            UFG::FaceActionComponent::_TypeUID);
      }
      if ( v13 )
        UFG::FaceActionComponent::SetupSocialForNIS(v13, v2);
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
  UFG::qNode<UFG::SpawnZone,UFG::SpawnZoneList> *v3; // r9
  UFG::qNode<UFG::SpawnZone,UFG::SpawnZoneList> *v4; // rax
  UFG::qNode<UFG::SpawnZone,UFG::SpawnZoneList> *v5; // rcx
  UFG::qNode<UFG::SpawnZone,UFG::SpawnZoneList> **v6; // rdx
  UFG::qNode<UFG::SpawnZone,UFG::SpawnZoneList> *v7; // rax

  for ( i = (UFG::qList<UFG::SpawnZone,UFG::SpawnZoneList,1,0> *)&UFG::PedSpawnManager::msActiveZoneList.mNode.mNext[-2].mNext;
        i != (UFG::qList<UFG::SpawnZone,UFG::SpawnZoneList,1,0> *)((char *)&UFG::PedSpawnManager::msActiveZoneList - 24);
        BYTE1(v2[7].mNode.mPrev) = 0 )
  {
    v2 = i;
    v3 = i[2].mNode.mPrev;
    v4 = v2[2].mNode.mPrev;
    v5 = v2[1].mNode.mNext;
    v6 = &v2[1].mNode.mNext;
    v5->mNext = v4;
    v4->mPrev = v5;
    *v6 = (UFG::qNode<UFG::SpawnZone,UFG::SpawnZoneList> *)v6;
    v6[1] = (UFG::qNode<UFG::SpawnZone,UFG::SpawnZoneList> *)v6;
    v7 = UFG::PedSpawnManager::msSpawnZoneList.mNode.mNext;
    UFG::PedSpawnManager::msSpawnZoneList.mNode.mNext = (UFG::qNode<UFG::SpawnZone,UFG::SpawnZoneList> *)((char *)&v2[1].mNode + 8);
    *v6 = (UFG::qNode<UFG::SpawnZone,UFG::SpawnZoneList> *)&UFG::PedSpawnManager::msSpawnZoneList;
    v6[1] = v7;
    v7->mPrev = (UFG::qNode<UFG::SpawnZone,UFG::SpawnZoneList> *)((char *)&v2[1].mNode + 8);
    i = (UFG::qList<UFG::SpawnZone,UFG::SpawnZoneList,1,0> *)&v3[-2].mNext;
    LODWORD(v2[3].mNode.mNext) = 1;
    HIDWORD(v2[7].mNode.mPrev) = 0;
  }
}

// File Line: 9685
// RVA: 0x4161D0
void __fastcall UFG::PedSpawnManager::RestoreAllScriptedToFullyActive(UFG::PedSpawnManager *this)
{
  UFG::PedSpawnManager *v1; // rbp
  UFG::PedSpawningInfo::eActiveStatus *v2; // rbx
  UFG::PedSpawningInfo *v3; // rdi
  signed __int64 v4; // rsi

  v1 = this;
  v2 = &this->mScriptedPed[0].mActiveStatus;
  v3 = this->mScriptedPed;
  v4 = 120i64;
  do
  {
    if ( *v2 )
      UFG::PedSpawnManager::ChangeStatusToActive(v1, v3);
    ++v3;
    v2 += 206;
    --v4;
  }
  while ( v4 );
}

// File Line: 9704
// RVA: 0x40B4E0
UFG::SimComponent *__fastcall UFG::PedSpawnManager::FindPedInfoFromSimObject(UFG::PedSpawnManager *this, UFG::SimObject *simObj)
{
  UFG::SimObject *v2; // r8
  unsigned __int16 v4; // cx
  unsigned int v5; // edx
  UFG::SimObjectGame *v6; // rcx
  bool v7; // zf

  v2 = simObj;
  if ( !simObj )
    return 0i64;
  v4 = simObj->m_Flags;
  if ( (v4 >> 14) & 1 )
    return simObj->m_Components.p[48].m_pComponent;
  if ( (v4 & 0x8000u) != 0 || (v4 >> 13) & 1 )
  {
    v5 = UFG::PedSpawningInfo::_TypeUID;
    v6 = (UFG::SimObjectGame *)v2;
    return UFG::SimObjectGame::GetComponentOfTypeHK(v6, v5);
  }
  v5 = UFG::PedSpawningInfo::_TypeUID;
  v7 = ((v4 >> 12) & 1) == 0;
  v6 = (UFG::SimObjectGame *)v2;
  if ( !v7 )
    return UFG::SimObjectGame::GetComponentOfTypeHK(v6, v5);
  return UFG::SimObject::GetComponentOfType(v2, UFG::PedSpawningInfo::_TypeUID);
}

// File Line: 9751
// RVA: 0x40C030
void __fastcall UFG::PedSpawnManager::GetGroupCandidates(UFG::PedSpawnManager *this, UFG::PedSpawningInfo *pPed, UFG::qFixedArray<UFG::PedSpawningInfo *,10> *closePeds, UFG::qVector3 *pos, const float radius)
{
  unsigned int v5; // er10
  UFG::PedSpawningInfo *v6; // rbx
  signed int v7; // er11
  UFG::qNode<UFG::PedSpawningInfo,UFG::PedInfoList> **v8; // rsi
  signed __int64 v9; // rcx
  __int64 v10; // rdx

  v5 = closePeds->size;
  v6 = pPed;
  v7 = 1;
  if ( closePeds->size < 0xA )
  {
    v8 = &stru_1423DEF70.mNode.mNext;
    do
    {
      if ( v7 > 3 )
        break;
      v9 = (signed __int64)&(*v8)[-4];
      if ( v5 < 0xA )
      {
        do
        {
          if ( (UFG::qList<UFG::PedSpawningInfo,UFG::PedInfoList,1,0> *)v9 == &UFG::PedSpawnManager::msAmbientList[v7 - 4] )
            break;
          v10 = *(_QWORD *)(v9 + 72);
          if ( v6 != (UFG::PedSpawningInfo *)v9
            && (float)((float)((float)((float)(pos->y - *(float *)(v9 + 772)) * (float)(pos->y - *(float *)(v9 + 772)))
                             + (float)((float)(pos->x - *(float *)(v9 + 768)) * (float)(pos->x - *(float *)(v9 + 768))))
                     + (float)((float)(pos->z - *(float *)(v9 + 776)) * (float)(pos->z - *(float *)(v9 + 776)))) <= (float)(radius * radius) )
          {
            closePeds->p[v5] = (UFG::PedSpawningInfo *)v9;
            ++closePeds->size;
          }
          v5 = closePeds->size;
          v9 = v10 - 64;
        }
        while ( closePeds->size < 0xA );
      }
      v5 = closePeds->size;
      ++v7;
      v8 += 2;
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
    else if ( UFG::PedSpawnManager::msAmbientSpawningEnable == 1 )
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

