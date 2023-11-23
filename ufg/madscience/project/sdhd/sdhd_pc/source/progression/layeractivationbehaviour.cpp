// File Line: 92
// RVA: 0x495E10
void __fastcall UFG::GameLayerActivationBehaviour::CachePropertySetData(
        UFG::GameLayerActivationBehaviour *this,
        UFG::SceneLayer *scene_layer,
        UFG::qPropertySet *property_set)
{
  UFG::qSymbol *v5; // rax
  UFG::qSymbol *v6; // r14
  UFG::qSymbol *v7; // rdx
  unsigned int *v8; // rax
  unsigned int *p_mGeoProgressionStartCondition; // rcx
  UFG::qSymbol *v10; // rax
  UFG::qSymbol *v11; // rcx
  unsigned int *v12; // rax
  unsigned int *p_mGeoProgressionEndCondition; // rcx
  unsigned int v14; // esi
  unsigned int v15; // eax
  UFG::qSymbol *v16; // rax
  UFG::qSymbol *v17; // rcx
  UFG::qSymbol *v18; // rax
  unsigned int *v19; // rax
  int *v20; // rcx
  UFG::GameStat::MapInt32Stat MapInt32StatEnum; // eax
  unsigned int *v22; // rax
  int *v23; // rcx
  int v24; // eax
  unsigned int *v25; // rax
  int *v26; // rcx
  int v27; // eax
  float *v28; // rax
  float *v29; // rcx
  float v30; // eax
  float *v31; // rax
  float *v32; // rcx
  float v33; // eax
  bool *v34; // rax
  bool *v35; // rcx
  UFG::qSymbol *p; // rcx
  UFG::qSymbol *v37; // rbx
  UFG::qPropertyList *v38; // rax
  unsigned int mNumElements; // r15d
  UFG::qPropertyList *v40; // r13
  UFG::qSymbol *v41; // rax
  __int64 size; // rbp
  unsigned int capacity; // edx
  unsigned int v44; // ebx
  UFG::qSymbol *v45; // r14
  unsigned int v46; // edx
  UFG::qSymbol *v47; // rcx
  int v48; // [rsp+60h] [rbp+8h] BYREF
  UFG::qSymbol name; // [rsp+78h] [rbp+20h] BYREF

  v5 = UFG::qPropertySet::Get<UFG::qSymbol>(
         property_set,
         (UFG::qArray<unsigned long,0> *)&SimSym_LayerUnlocksAfter,
         DEPTH_RECURSE);
  v6 = &UFG::gNullQSymbol;
  v7 = &UFG::gNullQSymbol;
  if ( v5 )
    v7 = v5;
  this->mGeoProgressionStart = (UFG::qSymbol)v7->mUID;
  this->mGeoProgressionStartCondition = 8;
  v8 = UFG::qPropertySet::Get<unsigned long>(
         property_set,
         (UFG::qArray<unsigned long,0> *)&SimSym_LayerUnlocksAfterCondition,
         DEPTH_RECURSE);
  p_mGeoProgressionStartCondition = &this->mGeoProgressionStartCondition;
  if ( v8 )
    p_mGeoProgressionStartCondition = v8;
  this->mGeoProgressionStartCondition = *p_mGeoProgressionStartCondition;
  v10 = UFG::qPropertySet::Get<UFG::qSymbol>(
          property_set,
          (UFG::qArray<unsigned long,0> *)&SimSym_LayerLocksAfter,
          DEPTH_RECURSE);
  v11 = &UFG::gNullQSymbol;
  if ( v10 )
    v11 = v10;
  this->mGeoProgressionEnd = (UFG::qSymbol)v11->mUID;
  this->mGeoProgressionEndCondition = 8;
  v12 = UFG::qPropertySet::Get<unsigned long>(
          property_set,
          (UFG::qArray<unsigned long,0> *)&SimSym_LayerLocksAfterCondition,
          DEPTH_RECURSE);
  p_mGeoProgressionEndCondition = &this->mGeoProgressionEndCondition;
  if ( v12 )
    p_mGeoProgressionEndCondition = v12;
  v14 = 0;
  v15 = *p_mGeoProgressionEndCondition;
  this->mCollectibleCategory = Num_MapInt32_Stats;
  this->mGeoProgressionEndCondition = v15;
  this->mCollectibleItem = UFG::gNullQSymbol;
  this->mCollectibleItemStage = 0;
  this->mIsCollectibleCategory = 0;
  v16 = UFG::qPropertySet::Get<UFG::qSymbol>(
          property_set,
          (UFG::qArray<unsigned long,0> *)&SimSym_CollectibleCategory,
          DEPTH_RECURSE);
  v17 = &UFG::gNullQSymbol;
  if ( v16 )
    v17 = v16;
  name.mUID = v17->mUID;
  if ( name.mUID != -1 )
  {
    v18 = UFG::qPropertySet::Get<UFG::qSymbol>(
            property_set,
            (UFG::qArray<unsigned long,0> *)&SimSym_CollectibleItem,
            DEPTH_RECURSE);
    v48 = -1;
    if ( v18 )
      v6 = v18;
    this->mCollectibleItem = (UFG::qSymbol)v6->mUID;
    v19 = UFG::qPropertySet::Get<unsigned long>(
            property_set,
            (UFG::qArray<unsigned long,0> *)&SimSym_CollectibleItemStage,
            DEPTH_RECURSE);
    v20 = &v48;
    if ( v19 )
      v20 = (int *)v19;
    this->mCollectibleItemStage = *v20;
    MapInt32StatEnum = UFG::GameStat::GetMapInt32StatEnum(&name, 1);
    this->mIsCollectibleCategory = 1;
    this->mCollectibleCategory = MapInt32StatEnum;
  }
  v48 = 0;
  v22 = UFG::qPropertySet::Get<unsigned long>(
          property_set,
          (UFG::qArray<unsigned long,0> *)&SimSym_LayerTimeBegin,
          DEPTH_RECURSE);
  v23 = &v48;
  if ( v22 )
    v23 = (int *)v22;
  v24 = *v23;
  v48 = 0;
  this->mTimeBegin = (float)v24 * 3600.0;
  v25 = UFG::qPropertySet::Get<unsigned long>(
          property_set,
          (UFG::qArray<unsigned long,0> *)&SimSym_LayerTimeEnd,
          DEPTH_RECURSE);
  v26 = &v48;
  if ( v25 )
    v26 = (int *)v25;
  v27 = *v26;
  v48 = -1082130432;
  this->mTimeEnd = (float)v27 * 3600.0;
  v28 = UFG::qPropertySet::Get<float>(
          property_set,
          (UFG::qArray<unsigned long,0> *)&SimSym_GeoWeatherMin,
          DEPTH_RECURSE);
  v29 = (float *)&v48;
  if ( v28 )
    v29 = v28;
  v30 = *v29;
  v48 = -1082130432;
  this->mGeoWeatherMin = v30;
  v31 = UFG::qPropertySet::Get<float>(
          property_set,
          (UFG::qArray<unsigned long,0> *)&SimSym_GeoWeatherMax,
          DEPTH_RECURSE);
  v32 = (float *)&v48;
  if ( v31 )
    v32 = v31;
  v33 = *v32;
  LOBYTE(v48) = 0;
  this->mGeoWeatherMax = v33;
  v34 = UFG::qPropertySet::Get<bool>(
          property_set,
          (UFG::qArray<unsigned long,0> *)&SimSym_OffDuringMissions,
          DEPTH_RECURSE);
  v35 = (bool *)&v48;
  if ( v34 )
    v35 = v34;
  this->mOffDuringMissions = *v35;
  p = this->mFlowList.p;
  if ( p )
  {
    v37 = p - 1;
    `eh vector destructor iterator(p, 4ui64, p[-1].mUID, (void (__fastcall *)(void *))_);
    operator delete[](v37);
  }
  this->mFlowList.p = 0i64;
  *(_QWORD *)&this->mFlowList.size = 0i64;
  v38 = UFG::qPropertySet::Get<UFG::qPropertyList>(
          property_set,
          (UFG::qArray<unsigned long,0> *)&SimSym_Flow,
          DEPTH_RECURSE);
  mNumElements = v38->mNumElements;
  v40 = v38;
  if ( mNumElements )
  {
    do
    {
      v41 = UFG::qPropertyList::Get<UFG::qSymbol>(v40, v14);
      size = this->mFlowList.size;
      capacity = this->mFlowList.capacity;
      v44 = size + 1;
      v45 = v41;
      if ( (int)size + 1 > capacity )
      {
        if ( capacity )
          v46 = 2 * capacity;
        else
          v46 = 1;
        for ( ; v46 < v44; v46 *= 2 )
          ;
        if ( v46 <= 4 )
          v46 = 4;
        if ( v46 - v44 > 0x10000 )
          v46 = size + 65537;
        UFG::qArray<UFG::qSymbol,0>::Reallocate(&this->mFlowList, v46, "qArray.Add");
      }
      v47 = this->mFlowList.p;
      this->mFlowList.size = v44;
      ++v14;
      v47[size] = (UFG::qSymbol)v45->mUID;
    }
    while ( v14 < mNumElements );
  }
}

// File Line: 150
// RVA: 0x4AC930
char __fastcall UFG::GameLayerActivationBehaviour::IsGeoTimeOfDay(
        UFG::GameLayerActivationBehaviour *this,
        UFG::SceneLayer *scene_layer,
        float currentTOD)
{
  float mTimeBegin; // xmm0_4
  float mTimeEnd; // xmm1_4

  mTimeBegin = this->mTimeBegin;
  if ( mTimeBegin > 0.0 )
    goto LABEL_5;
  if ( this->mTimeEnd <= 0.0 )
    return 1;
  if ( mTimeBegin >= 0.0 )
  {
LABEL_5:
    mTimeEnd = this->mTimeEnd;
    if ( mTimeBegin == mTimeEnd )
      return 1;
    if ( mTimeBegin > mTimeEnd )
    {
      if ( currentTOD >= mTimeBegin )
        return 1;
    }
    else if ( currentTOD < mTimeBegin )
    {
      return 0;
    }
    if ( currentTOD < mTimeEnd )
      return 1;
  }
  return 0;
}

// File Line: 180
// RVA: 0x4AC080
bool __fastcall UFG::GameLayerActivationBehaviour::IsGeoInFrustum(
        UFG::GameLayerActivationBehaviour *this,
        UFG::SceneLayer *scene_layer)
{
  UFG::BaseCameraComponent *mCurrentCamera; // rcx
  UFG::Camera *p_mCamera; // rdi
  UFG::qMatrix44 *ViewProjection; // rbx
  UFG::qMatrix44 *WorldView; // rax
  float v7; // xmm12_4
  float v8; // xmm11_4
  float v9; // xmm10_4
  float v10; // xmm13_4
  float v11; // xmm14_4
  float v12; // xmm15_4
  float v13; // xmm0_4
  float v14; // xmm1_4
  float v15; // xmm0_4
  float v16; // xmm2_4
  float v17; // xmm1_4
  float v18; // xmm0_4
  float v19; // xmm0_4
  __m128 v20; // xmm2
  float v21; // xmm0_4
  float v22; // xmm4_4
  __m128 v23; // xmm2
  float v24; // xmm0_4
  __m128 v25; // xmm2
  float v26; // xmm1_4
  float v28; // [rsp+20h] [rbp-B8h]
  float v29; // [rsp+2Ch] [rbp-ACh]
  float v30; // [rsp+34h] [rbp-A4h]
  float v31; // [rsp+40h] [rbp-98h]
  float v32; // [rsp+44h] [rbp-94h]
  UFG::qMatrix44 result; // [rsp+50h] [rbp-88h] BYREF
  float v34; // [rsp+90h] [rbp-48h]
  float v35; // [rsp+94h] [rbp-44h]
  float v36; // [rsp+98h] [rbp-40h]
  float v37; // [rsp+9Ch] [rbp-3Ch]
  float v38; // [rsp+A0h] [rbp-38h]
  float v39; // [rsp+A4h] [rbp-34h]
  float v40; // [rsp+A8h] [rbp-30h]
  float v41; // [rsp+ACh] [rbp-2Ch]
  float v42; // [rsp+B0h] [rbp-28h]
  float v43; // [rsp+B4h] [rbp-24h]
  float v44; // [rsp+B8h] [rbp-20h]
  float v45; // [rsp+BCh] [rbp-1Ch]
  float v46; // [rsp+C0h] [rbp-18h]
  float v47; // [rsp+C4h] [rbp-14h]
  float centre_distance_to_nearplan; // [rsp+1A0h] [rbp+C8h] BYREF
  float v49; // [rsp+1A8h] [rbp+D0h]
  float vars0; // [rsp+1B0h] [rbp+D8h]

  mCurrentCamera = UFG::Director::Get()->mCurrentCamera;
  p_mCamera = &mCurrentCamera->mCamera;
  if ( !mCurrentCamera )
    p_mCamera = 0i64;
  ViewProjection = UFG::Camera::GetViewProjection(p_mCamera);
  WorldView = UFG::Camera::GetWorldView(p_mCamera);
  UFG::qMatrix44::operator*(WorldView, &result, ViewProjection);
  LODWORD(v7) = COERCE_UNSIGNED_INT(result.v0.x + result.v0.w) ^ _xmm[0];
  LODWORD(v31) = COERCE_UNSIGNED_INT(result.v2.w - result.v2.y) ^ _xmm[0];
  LODWORD(v32) = COERCE_UNSIGNED_INT(result.v1.w - result.v1.y) ^ _xmm[0];
  LODWORD(v8) = COERCE_UNSIGNED_INT(result.v1.x + result.v1.w) ^ _xmm[0];
  LODWORD(v9) = COERCE_UNSIGNED_INT(result.v2.x + result.v2.w) ^ _xmm[0];
  LODWORD(v49) = COERCE_UNSIGNED_INT(result.v0.y + result.v0.w) ^ _xmm[0];
  LODWORD(centre_distance_to_nearplan) = COERCE_UNSIGNED_INT(result.v1.y + result.v1.w) ^ _xmm[0];
  LODWORD(v10) = COERCE_UNSIGNED_INT(result.v0.w - result.v0.x) ^ _xmm[0];
  LODWORD(v11) = COERCE_UNSIGNED_INT(result.v1.w - result.v1.x) ^ _xmm[0];
  LODWORD(vars0) = COERCE_UNSIGNED_INT(result.v2.y + result.v2.w) ^ _xmm[0];
  LODWORD(v12) = COERCE_UNSIGNED_INT(result.v2.w - result.v2.x) ^ _xmm[0];
  LODWORD(v29) = COERCE_UNSIGNED_INT(result.v0.w - result.v0.z) ^ _xmm[0];
  LODWORD(v30) = COERCE_UNSIGNED_INT(result.v1.w - result.v1.z) ^ _xmm[0];
  LODWORD(v28) = COERCE_UNSIGNED_INT(result.v2.w - result.v2.z) ^ _xmm[0];
  v13 = fsqrt(
          (float)((float)(COERCE_FLOAT(LODWORD(result.v1.z) ^ _xmm[0]) * COERCE_FLOAT(LODWORD(result.v1.z) ^ _xmm[0]))
                + (float)(COERCE_FLOAT(LODWORD(result.v0.z) ^ _xmm[0]) * COERCE_FLOAT(LODWORD(result.v0.z) ^ _xmm[0])))
        + (float)(COERCE_FLOAT(LODWORD(result.v2.z) ^ _xmm[0]) * COERCE_FLOAT(LODWORD(result.v2.z) ^ _xmm[0])));
  v14 = (float)(1.0 / v13) * COERCE_FLOAT(LODWORD(result.v1.z) ^ _xmm[0]);
  result.v2.y = (float)(1.0 / v13) * COERCE_FLOAT(LODWORD(result.v1.x) ^ _xmm[0]);
  result.v1.z = (float)(1.0 / v13) * COERCE_FLOAT(LODWORD(result.v0.z) ^ _xmm[0]);
  result.v2.x = (float)(1.0 / v13) * COERCE_FLOAT(LODWORD(result.v2.z) ^ _xmm[0]);
  result.v1.w = v14;
  v15 = fsqrt((float)((float)(v8 * v8) + (float)(v7 * v7)) + (float)(v9 * v9));
  v16 = (float)(1.0 / v15) * v7;
  v17 = (float)(1.0 / v15) * v8;
  v18 = 1.0 / v15;
  result.v2.z = v16;
  result.v2.w = v17;
  result.v3.y = v18 * COERCE_FLOAT(COERCE_UNSIGNED_INT(result.v0.z + result.v1.y) ^ _xmm[0]);
  result.v3.x = v18 * v9;
  v19 = fsqrt((float)((float)(v11 * v11) + (float)(v10 * v10)) + (float)(v12 * v12));
  v35 = (float)(1.0 / v19) * COERCE_FLOAT(COERCE_UNSIGNED_INT(result.v1.y - result.v0.z) ^ _xmm[0]);
  result.v3.z = (float)(1.0 / v19) * v10;
  v34 = (float)(1.0 / v19) * v12;
  result.v3.w = (float)(1.0 / v19) * v11;
  v20 = (__m128)LODWORD(centre_distance_to_nearplan);
  v20.m128_f32[0] = (float)((float)(v20.m128_f32[0] * v20.m128_f32[0]) + (float)(v49 * v49)) + (float)(vars0 * vars0);
  v21 = _mm_sqrt_ps(v20).m128_f32[0];
  LODWORD(v22) = COERCE_UNSIGNED_INT(result.v0.w - result.v0.y) ^ _xmm[0];
  v36 = (float)(1.0 / v21) * v49;
  v38 = (float)(1.0 / v21) * vars0;
  v37 = (float)(1.0 / v21) * centre_distance_to_nearplan;
  v23 = (__m128)LODWORD(v32);
  v39 = (float)(1.0 / v21) * COERCE_FLOAT(COERCE_UNSIGNED_INT(result.v0.w + result.v1.y) ^ _xmm[0]);
  v23.m128_f32[0] = (float)((float)(v23.m128_f32[0] * v23.m128_f32[0]) + (float)(v22 * v22)) + (float)(v31 * v31);
  v24 = 1.0 / _mm_sqrt_ps(v23).m128_f32[0];
  v43 = v24 * COERCE_FLOAT(COERCE_UNSIGNED_INT(result.v1.y - result.v0.w) ^ _xmm[0]);
  v40 = v24 * v22;
  v41 = v24 * v32;
  v42 = v24 * v31;
  v25 = (__m128)LODWORD(v30);
  v25.m128_f32[0] = (float)((float)(v25.m128_f32[0] * v25.m128_f32[0]) + (float)(v29 * v29)) + (float)(v28 * v28);
  v26 = 1.0 / _mm_sqrt_ps(v25).m128_f32[0];
  v47 = v26 * COERCE_FLOAT(COERCE_UNSIGNED_INT(result.v1.y - result.v1.x) ^ _xmm[0]);
  v46 = v26 * v28;
  v44 = v26 * v29;
  v45 = v26 * v30;
  centre_distance_to_nearplan = 0.0;
  return (unsigned int)IntersectAABBFrustum(
                         (UFG::qVector4 *)&result.v1.z,
                         &scene_layer->mBox.mMin,
                         &scene_layer->mBox.mMax,
                         &centre_distance_to_nearplan) <= 1;
}

// File Line: 196
// RVA: 0x4AC630
char __fastcall UFG::GameLayerActivationBehaviour::IsGeoProgression(
        UFG::GameLayerActivationBehaviour *this,
        UFG::SceneLayer *scene_layer)
{
  char v3; // di
  unsigned int v4; // edx
  __int64 v5; // rcx
  int mIntValue; // r14d
  UFG::qBaseTreeRB *v7; // rbp
  UFG::qBaseTreeRB *v8; // rbx
  bool v9; // r15
  bool v10; // r12
  bool v11; // r13
  unsigned int mUID; // eax
  unsigned int v13; // eax
  int v15; // eax
  unsigned int v16; // edx
  unsigned int v17; // edx
  int v18; // eax
  bool v19; // dl
  int v20; // ecx
  unsigned int mGeoProgressionStartCondition; // eax
  char v22; // al
  unsigned int mGeoProgressionEndCondition; // eax
  bool v24; // zf
  __int64 mCollectibleCategory; // rbx
  UFG::PersistentData::MapInt *v26; // r8
  __int64 v27; // rax
  UFG::PersistentData::KeyValue *i; // rcx
  __int64 v29; // [rsp+60h] [rbp+8h]

  v3 = 1;
  v4 = _S19_1;
  if ( (_S19_1 & 1) == 0 )
  {
    _S19_1 |= 1u;
    UFG::ProgressionTracker::ProgressionTracker(&sProgressionTracker);
    atexit(UFG::ProgressionTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sProgressionTracker__);
    v4 = _S19_1;
  }
  UFG::ProgressionTracker::mspInstance = &sProgressionTracker;
  v5 = qword_14240B6D0;
  v29 = qword_14240B6D0;
  mIntValue = 0;
  v7 = 0i64;
  v8 = 0i64;
  v9 = 0;
  v10 = 0;
  v11 = 0;
  if ( this->mGeoProgressionStart.mUID != -1 )
  {
    if ( (v4 & 1) == 0 )
    {
      _S19_1 = v4 | 1;
      UFG::ProgressionTracker::ProgressionTracker(&sProgressionTracker);
      atexit(UFG::ProgressionTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sProgressionTracker__);
      v4 = _S19_1;
    }
    UFG::ProgressionTracker::mspInstance = &sProgressionTracker;
    mUID = this->mGeoProgressionStart.mUID;
    if ( !mUID || (v7 = UFG::qBaseTreeRB::Get(&stru_14240A100, mUID), v4 = _S19_1, !v7) )
    {
      v13 = this->mGeoProgressionStart.mUID;
      if ( v13 )
      {
        v7 = UFG::qBaseTreeRB::Get(&stru_14240A148, v13);
        v4 = _S19_1;
      }
      else
      {
        v7 = 0i64;
      }
    }
    if ( !v7 )
      return 0;
    v5 = v29;
    if ( v7 == (UFG::qBaseTreeRB *)v29 )
    {
      v9 = 1;
      v10 = 0;
    }
    else
    {
      v15 = (int)v7[3].mNULL.mChild[1];
      v9 = v15 == 4;
      v10 = v15 == 8;
    }
  }
  if ( this->mGeoProgressionEnd.mUID == -1 )
    goto LABEL_28;
  if ( (v4 & 1) == 0 )
  {
    _S19_1 = v4 | 1;
    UFG::ProgressionTracker::ProgressionTracker(&sProgressionTracker);
    atexit(UFG::ProgressionTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sProgressionTracker__);
  }
  UFG::ProgressionTracker::mspInstance = &sProgressionTracker;
  v16 = this->mGeoProgressionEnd.mUID;
  if ( !v16 || (v8 = UFG::qBaseTreeRB::Get(&stru_14240A100, v16)) == 0i64 )
  {
    v17 = this->mGeoProgressionEnd.mUID;
    if ( v17 )
      v8 = UFG::qBaseTreeRB::Get(&stru_14240A148, v17);
    else
      v8 = 0i64;
  }
  if ( !v8 )
    return 0;
  v5 = v29;
  if ( v8 == (UFG::qBaseTreeRB *)v29 )
  {
    v11 = 1;
LABEL_28:
    v19 = 0;
    goto LABEL_29;
  }
  v18 = (int)v8[3].mNULL.mChild[1];
  v11 = v18 == 4;
  v19 = v18 == 8;
LABEL_29:
  if ( this->mOffDuringMissions && v5 )
  {
    v20 = *(_DWORD *)(v5 + 268);
    v3 = ((v20 - 7) & 0xFFFFFFFA) != 0 || v20 == 12;
  }
  if ( v7 )
  {
    mGeoProgressionStartCondition = this->mGeoProgressionStartCondition;
    if ( mGeoProgressionStartCondition == 4 )
    {
      v3 &= v9;
    }
    else if ( mGeoProgressionStartCondition == 12 )
    {
      if ( v9 || (v22 = 0, v10) )
        v22 = 1;
      v3 &= v22;
    }
    else
    {
      v3 &= v10;
    }
  }
  if ( !v8 )
    goto LABEL_51;
  mGeoProgressionEndCondition = this->mGeoProgressionEndCondition;
  if ( mGeoProgressionEndCondition == 4 )
  {
    v24 = !v11;
LABEL_50:
    v3 &= v24;
    goto LABEL_51;
  }
  if ( mGeoProgressionEndCondition != 12 )
  {
    v24 = !v19;
    goto LABEL_50;
  }
  v3 &= !v11 && !v19;
LABEL_51:
  if ( this->mIsCollectibleCategory )
  {
    mCollectibleCategory = this->mCollectibleCategory;
    v26 = UFG::GameStatTracker::Instance()->mpSnapshots[0]->mpMapInts[mCollectibleCategory];
    v27 = 0i64;
    if ( v26->mValues.size )
    {
      for ( i = v26->mValues.p; i->mKey.mUID != this->mCollectibleItem.mUID; ++i )
      {
        v27 = (unsigned int)(v27 + 1);
        if ( (unsigned int)v27 >= v26->mValues.size )
          return (mIntValue == this->mCollectibleItemStage) & v3;
      }
      if ( (_DWORD)v27 != -1 )
        mIntValue = v26->mValues.p[v27].mIntValue;
    }
    return (mIntValue == this->mCollectibleItemStage) & v3;
  }
  return v3;
}

// File Line: 324
// RVA: 0x4BE710
bool __fastcall UFG::GameLayerActivationBehaviour::ShouldLayerBeActive(
        UFG::GameLayerActivationBehaviour *this,
        UFG::SceneLayer *scene_layer,
        UFG::qVector3 *testPoint,
        bool activeState)
{
  bool v8; // di
  float m_SecondsSinceMidnight; // xmm7_4
  float m_WeatherState; // xmm6_4
  UFG::qSymbol *ActiveCategory; // rbp
  float v14; // xmm1_4
  bool IsGeoInFrustum; // si
  float mGeoWeatherMin; // xmm0_4
  bool v17; // cf
  float mGeoWeatherMax; // xmm0_4
  UFG::qSymbol result; // [rsp+80h] [rbp+8h] BYREF

  v8 = 0;
  m_SecondsSinceMidnight = UFG::TimeOfDayManager::GetInstance()->m_SecondsSinceMidnight;
  m_WeatherState = UFG::TimeOfDayManager::GetInstance()->m_WeatherState;
  if ( !this->vfptr->LayerBelongsToCurrentFlow(this, scene_layer) )
    return 0;
  if ( (scene_layer->mFlags & 0x400) == 0 )
  {
    ActiveCategory = UFG::GeographicalLayerManager::GetActiveCategory();
    if ( ActiveCategory->mUID == -1
       ? (scene_layer->mFlags & 0x100) == 0
       : ActiveCategory->mUID != UFG::SceneLayer::GetIndoorCategory(scene_layer, &result)->mUID )
    {
      return 0;
    }
  }
  v14 = UFG::qBox::DistanceSqrPoint(&scene_layer->mBox, testPoint);
  if ( v14 >= gLayer_OutFrustum_ActDistSqrd )
  {
    IsGeoInFrustum = gLayer_InFrustum_ActDistSqrd > v14;
    if ( gLayer_InFrustum_ActDistSqrd > v14 )
      IsGeoInFrustum = UFG::GameLayerActivationBehaviour::IsGeoInFrustum(this, scene_layer);
  }
  else
  {
    IsGeoInFrustum = 1;
  }
  if ( !UFG::GameLayerActivationBehaviour::IsGeoProgression(this, scene_layer) )
    goto LABEL_32;
  if ( activeState )
  {
    v8 = IsGeoInFrustum || scene_layer->mDeactivateTimer > 0.0;
    if ( UFG::GeographicalLayerManager::GetInstance()->mAllowImmediateActivation )
    {
      if ( !v8 || !UFG::GameLayerActivationBehaviour::IsGeoTimeOfDay(this, scene_layer, m_SecondsSinceMidnight) )
      {
        v8 = 0;
        goto LABEL_32;
      }
      goto LABEL_31;
    }
    goto LABEL_32;
  }
  if ( !IsGeoInFrustum )
    goto LABEL_36;
  if ( !UFG::GameLayerActivationBehaviour::IsGeoTimeOfDay(this, scene_layer, m_SecondsSinceMidnight) )
    goto LABEL_32;
  mGeoWeatherMin = this->mGeoWeatherMin;
  if ( mGeoWeatherMin <= -0.001 )
  {
    mGeoWeatherMax = this->mGeoWeatherMax;
    if ( mGeoWeatherMax <= -0.001 )
      goto LABEL_29;
    v17 = mGeoWeatherMax < m_WeatherState;
  }
  else
  {
    v17 = m_WeatherState < mGeoWeatherMin;
  }
  if ( v17 )
    goto LABEL_32;
LABEL_29:
  if ( UFG::GeographicalLayerManager::GetInstance()->mAllowImmediateActivation || (scene_layer->mFlags & 0x800) == 0 )
LABEL_31:
    v8 = 1;
LABEL_32:
  if ( IsGeoInFrustum )
  {
    if ( v8 )
      scene_layer->mDeactivateTimer = gDelayBeforeDeactivation;
    scene_layer->mFlags |= 0x800u;
    return v8;
  }
LABEL_36:
  scene_layer->mFlags &= ~0x800u;
  return v8;
}

// File Line: 468
// RVA: 0x4AD4A0
bool __fastcall UFG::GameLayerActivationBehaviour::LayerBelongsToCurrentFlow(
        UFG::GameLayerActivationBehaviour *this,
        UFG::SceneLayer *scene_layer)
{
  int v3; // ecx
  unsigned int size; // edx

  if ( (_S19_1 & 1) == 0 )
  {
    _S19_1 |= 1u;
    UFG::ProgressionTracker::ProgressionTracker(&sProgressionTracker);
    atexit(UFG::ProgressionTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sProgressionTracker__);
  }
  UFG::ProgressionTracker::mspInstance = &sProgressionTracker;
  v3 = 0;
  size = this->mFlowList.size;
  if ( size )
  {
    while ( unk_14240BAE0 != this->mFlowList.p[v3].mUID )
    {
      if ( ++v3 >= size )
        goto LABEL_6;
    }
  }
  else
  {
LABEL_6:
    v3 = -1;
  }
  return v3 != -1;
}

// File Line: 475
// RVA: 0x499DE0
UFG::allocator::free_link *__fastcall UFG::ILayerActivationBehaviour::Create(UFG::SceneLayer *scene_layer)
{
  UFG::allocator::free_link *result; // rax

  result = UFG::qMalloc(0x50ui64, "GameLayerActivationBehaviour", 0i64);
  if ( !result )
    return 0i64;
  result->mNext = (UFG::allocator::free_link *)&UFG::ILayerActivationBehaviour::`vftable;
  result->mNext = (UFG::allocator::free_link *)&UFG::GameLayerActivationBehaviour::`vftable;
  HIDWORD(result[1].mNext) = -1;
  LODWORD(result[3].mNext) = -1;
  HIDWORD(result[3].mNext) = 8;
  LODWORD(result[4].mNext) = -1;
  *(UFG::allocator::free_link **)((char *)&result[4].mNext + 4) = (UFG::allocator::free_link *)8;
  HIDWORD(result[5].mNext) = 0;
  LOBYTE(result[7].mNext) = 0;
  result[9].mNext = 0i64;
  result[8].mNext = 0i64;
  return result;
}

