// File Line: 92
// RVA: 0x495E10
void __fastcall UFG::GameLayerActivationBehaviour::CachePropertySetData(UFG::GameLayerActivationBehaviour *this, UFG::SceneLayer *scene_layer, UFG::qPropertySet *property_set)
{
  UFG::qPropertySet *v3; // rbp
  UFG::GameLayerActivationBehaviour *v4; // rdi
  UFG::qSymbol *v5; // rax
  UFG::qSymbol *v6; // r14
  UFG::qSymbol *v7; // rdx
  unsigned int *v8; // rax
  unsigned int *v9; // rcx
  UFG::qSymbol *v10; // rax
  UFG::qSymbol *v11; // rcx
  unsigned int *v12; // rax
  unsigned int *v13; // rcx
  unsigned int v14; // esi
  unsigned int v15; // eax
  UFG::qSymbol *v16; // rax
  UFG::qSymbol *v17; // rcx
  UFG::qSymbol *v18; // rax
  unsigned int *v19; // rax
  int *v20; // rcx
  UFG::GameStat::MapInt32Stat v21; // eax
  unsigned int *v22; // rax
  signed int *v23; // rcx
  signed int v24; // eax
  unsigned int *v25; // rax
  signed int *v26; // rcx
  signed int v27; // eax
  float *v28; // rax
  int *v29; // rcx
  int v30; // eax
  float *v31; // rax
  int *v32; // rcx
  int v33; // eax
  bool *v34; // rax
  int *v35; // rcx
  UFG::qSymbol *v36; // rcx
  UFG::qSymbol *v37; // rbx
  UFG::qPropertyList *v38; // rax
  unsigned int v39; // er15
  UFG::qPropertyList *v40; // r13
  UFG::qSymbol *v41; // rax
  __int64 v42; // rbp
  unsigned int v43; // edx
  unsigned int v44; // ebx
  UFG::qSymbol *v45; // r14
  unsigned int v46; // edx
  UFG::qSymbol *v47; // rcx
  int v48; // [rsp+60h] [rbp+8h]
  UFG::qSymbol name; // [rsp+78h] [rbp+20h]

  v3 = property_set;
  v4 = this;
  v5 = UFG::qPropertySet::Get<UFG::qSymbol>(property_set, (UFG::qSymbol *)&SimSym_LayerUnlocksAfter.mUID, DEPTH_RECURSE);
  v6 = &UFG::gNullQSymbol;
  v7 = &UFG::gNullQSymbol;
  if ( v5 )
    v7 = v5;
  v4->mGeoProgressionStart = (UFG::qSymbol)v7->mUID;
  v4->mGeoProgressionStartCondition = 8;
  v8 = UFG::qPropertySet::Get<unsigned long>(v3, (UFG::qSymbol *)&SimSym_LayerUnlocksAfterCondition.mUID, DEPTH_RECURSE);
  v9 = &v4->mGeoProgressionStartCondition;
  if ( v8 )
    v9 = v8;
  v4->mGeoProgressionStartCondition = *v9;
  v10 = UFG::qPropertySet::Get<UFG::qSymbol>(v3, (UFG::qSymbol *)&SimSym_LayerLocksAfter.mUID, DEPTH_RECURSE);
  v11 = &UFG::gNullQSymbol;
  if ( v10 )
    v11 = v10;
  v4->mGeoProgressionEnd = (UFG::qSymbol)v11->mUID;
  v4->mGeoProgressionEndCondition = 8;
  v12 = UFG::qPropertySet::Get<unsigned long>(v3, (UFG::qSymbol *)&SimSym_LayerLocksAfterCondition.mUID, DEPTH_RECURSE);
  v13 = &v4->mGeoProgressionEndCondition;
  if ( v12 )
    v13 = v12;
  v14 = 0;
  v15 = *v13;
  v4->mCollectibleCategory = 47;
  v4->mGeoProgressionEndCondition = v15;
  v4->mCollectibleItem = UFG::gNullQSymbol;
  v4->mCollectibleItemStage = 0;
  v4->mIsCollectibleCategory = 0;
  v16 = UFG::qPropertySet::Get<UFG::qSymbol>(v3, (UFG::qSymbol *)&SimSym_CollectibleCategory.mUID, DEPTH_RECURSE);
  v17 = &UFG::gNullQSymbol;
  if ( v16 )
    v17 = v16;
  name.mUID = v17->mUID;
  if ( name.mUID != -1 )
  {
    v18 = UFG::qPropertySet::Get<UFG::qSymbol>(v3, (UFG::qSymbol *)&SimSym_CollectibleItem.mUID, DEPTH_RECURSE);
    v48 = -1;
    if ( v18 )
      v6 = v18;
    v4->mCollectibleItem = (UFG::qSymbol)v6->mUID;
    v19 = UFG::qPropertySet::Get<unsigned long>(v3, (UFG::qSymbol *)&SimSym_CollectibleItemStage.mUID, DEPTH_RECURSE);
    v20 = &v48;
    if ( v19 )
      v20 = (int *)v19;
    v4->mCollectibleItemStage = *v20;
    v21 = UFG::GameStat::GetMapInt32StatEnum(&name, 1);
    v4->mIsCollectibleCategory = 1;
    v4->mCollectibleCategory = v21;
  }
  v48 = 0;
  v22 = UFG::qPropertySet::Get<unsigned long>(v3, (UFG::qSymbol *)&SimSym_LayerTimeBegin.mUID, DEPTH_RECURSE);
  v23 = &v48;
  if ( v22 )
    v23 = (signed int *)v22;
  v24 = *v23;
  v48 = 0;
  v4->mTimeBegin = (float)v24 * 3600.0;
  v25 = UFG::qPropertySet::Get<unsigned long>(v3, (UFG::qSymbol *)&SimSym_LayerTimeEnd.mUID, DEPTH_RECURSE);
  v26 = &v48;
  if ( v25 )
    v26 = (signed int *)v25;
  v27 = *v26;
  v48 = -1082130432;
  v4->mTimeEnd = (float)v27 * 3600.0;
  v28 = UFG::qPropertySet::Get<float>(v3, (UFG::qSymbol *)&SimSym_GeoWeatherMin.mUID, DEPTH_RECURSE);
  v29 = &v48;
  if ( v28 )
    v29 = (int *)v28;
  v30 = *v29;
  v48 = -1082130432;
  LODWORD(v4->mGeoWeatherMin) = v30;
  v31 = UFG::qPropertySet::Get<float>(v3, (UFG::qSymbol *)&SimSym_GeoWeatherMax.mUID, DEPTH_RECURSE);
  v32 = &v48;
  if ( v31 )
    v32 = (int *)v31;
  v33 = *v32;
  LOBYTE(v48) = 0;
  LODWORD(v4->mGeoWeatherMax) = v33;
  v34 = UFG::qPropertySet::Get<bool>(v3, (UFG::qSymbol *)&SimSym_OffDuringMissions.mUID, DEPTH_RECURSE);
  v35 = &v48;
  if ( v34 )
    v35 = (int *)v34;
  v4->mOffDuringMissions = *(_BYTE *)v35;
  v36 = v4->mFlowList.p;
  if ( v36 )
  {
    v37 = v36 - 1;
    `eh vector destructor iterator(v36, 4ui64, v36[-1].mUID, (void (__fastcall *)(void *))_);
    operator delete[](v37);
  }
  v4->mFlowList.p = 0i64;
  *(_QWORD *)&v4->mFlowList.size = 0i64;
  v38 = UFG::qPropertySet::Get<UFG::qPropertyList>(v3, (UFG::qSymbol *)&SimSym_Flow.mUID, DEPTH_RECURSE);
  v39 = v38->mNumElements;
  v40 = v38;
  if ( v39 )
  {
    do
    {
      v41 = UFG::qPropertyList::Get<UFG::qSymbol>(v40, v14);
      v42 = v4->mFlowList.size;
      v43 = v4->mFlowList.capacity;
      v44 = v42 + 1;
      v45 = v41;
      if ( (signed int)v42 + 1 > v43 )
      {
        if ( v43 )
          v46 = 2 * v43;
        else
          v46 = 1;
        for ( ; v46 < v44; v46 *= 2 )
          ;
        if ( v46 <= 4 )
          v46 = 4;
        if ( v46 - v44 > 0x10000 )
          v46 = v42 + 65537;
        UFG::qArray<UFG::qSymbol,0>::Reallocate(&v4->mFlowList, v46, "qArray.Add");
      }
      v47 = v4->mFlowList.p;
      v4->mFlowList.size = v44;
      ++v14;
      v47[v42] = (UFG::qSymbol)v45->mUID;
    }
    while ( v14 < v39 );
  }
}

// File Line: 150
// RVA: 0x4AC930
char __fastcall UFG::GameLayerActivationBehaviour::IsGeoTimeOfDay(UFG::GameLayerActivationBehaviour *this, UFG::SceneLayer *scene_layer, float currentTOD)
{
  float v3; // xmm0_4
  float v5; // xmm1_4

  v3 = this->mTimeBegin;
  if ( v3 > 0.0 )
    goto LABEL_14;
  if ( this->mTimeEnd <= 0.0 )
    return 1;
  if ( v3 >= 0.0 )
  {
LABEL_14:
    v5 = this->mTimeEnd;
    if ( v3 == v5 )
      return 1;
    if ( v3 > v5 )
    {
      if ( currentTOD >= v3 )
        return 1;
    }
    else if ( currentTOD < v3 )
    {
      return 0;
    }
    if ( currentTOD < v5 )
      return 1;
  }
  return 0;
}

// File Line: 180
// RVA: 0x4AC080
bool __fastcall UFG::GameLayerActivationBehaviour::IsGeoInFrustum(UFG::GameLayerActivationBehaviour *this, UFG::SceneLayer *scene_layer)
{
  UFG::SceneLayer *v2; // r14
  UFG::BaseCameraComponent *v3; // rcx
  UFG::Camera *v4; // rdi
  UFG::qMatrix44 *v5; // rbx
  UFG::qMatrix44 *v6; // rax
  int v7; // xmm6_4
  float v8; // xmm12_4
  float v9; // ST40_4
  float v10; // ST44_4
  float v11; // xmm11_4
  float v12; // xmm10_4
  float v13; // xmm13_4
  float v14; // xmm14_4
  float v15; // xmm15_4
  float v16; // ST28_4
  float v17; // ST34_4
  float v18; // ST20_4
  float v19; // xmm0_4
  float v20; // xmm0_4
  float v21; // xmm0_4
  __m128 v22; // xmm2
  float v23; // xmm0_4
  __m128 v24; // xmm2
  float v25; // xmm0_4
  float v26; // xmm5_4
  __m128 v27; // xmm2
  float v28; // xmm0_4
  UFG::qMatrix44 result; // [rsp+50h] [rbp-88h]
  float v31; // [rsp+90h] [rbp-48h]
  float v32; // [rsp+94h] [rbp-44h]
  float v33; // [rsp+98h] [rbp-40h]
  float v34; // [rsp+9Ch] [rbp-3Ch]
  float v35; // [rsp+A0h] [rbp-38h]
  float v36; // [rsp+A4h] [rbp-34h]
  float v37; // [rsp+A8h] [rbp-30h]
  float v38; // [rsp+ACh] [rbp-2Ch]
  float v39; // [rsp+B0h] [rbp-28h]
  float v40; // [rsp+B4h] [rbp-24h]
  float v41; // [rsp+B8h] [rbp-20h]
  float v42; // [rsp+BCh] [rbp-1Ch]
  float v43; // [rsp+C0h] [rbp-18h]
  float v44; // [rsp+C4h] [rbp-14h]
  float centre_distance_to_nearplan; // [rsp+1A0h] [rbp+C8h]
  float v46; // [rsp+1A8h] [rbp+D0h]
  float vars0; // [rsp+1B0h] [rbp+D8h]

  v2 = scene_layer;
  v3 = UFG::Director::Get()->mCurrentCamera;
  v4 = &v3->mCamera;
  if ( !v3 )
    v4 = 0i64;
  v5 = UFG::Camera::GetViewProjection(v4);
  v6 = UFG::Camera::GetWorldView(v4);
  UFG::qMatrix44::operator*(v6, &result, v5);
  v7 = LODWORD(result.v1.z) ^ _xmm[0];
  LODWORD(v8) = COERCE_UNSIGNED_INT(result.v0.x + result.v0.w) ^ _xmm[0];
  LODWORD(v9) = COERCE_UNSIGNED_INT(result.v2.w - result.v2.y) ^ _xmm[0];
  LODWORD(v10) = COERCE_UNSIGNED_INT(result.v1.w - result.v1.y) ^ _xmm[0];
  LODWORD(v11) = COERCE_UNSIGNED_INT(result.v1.x + result.v1.w) ^ _xmm[0];
  LODWORD(v12) = COERCE_UNSIGNED_INT(result.v2.x + result.v2.w) ^ _xmm[0];
  LODWORD(v46) = COERCE_UNSIGNED_INT(result.v0.y + result.v0.w) ^ _xmm[0];
  LODWORD(centre_distance_to_nearplan) = COERCE_UNSIGNED_INT(result.v1.y + result.v1.w) ^ _xmm[0];
  LODWORD(v13) = COERCE_UNSIGNED_INT(result.v0.w - result.v0.x) ^ _xmm[0];
  LODWORD(v14) = COERCE_UNSIGNED_INT(result.v1.w - result.v1.x) ^ _xmm[0];
  LODWORD(vars0) = COERCE_UNSIGNED_INT(result.v2.y + result.v2.w) ^ _xmm[0];
  LODWORD(v15) = COERCE_UNSIGNED_INT(result.v2.w - result.v2.x) ^ _xmm[0];
  LODWORD(v16) = COERCE_UNSIGNED_INT(result.v0.w - result.v0.y) ^ _xmm[0];
  LODWORD(v17) = COERCE_UNSIGNED_INT(result.v1.w - result.v1.z) ^ _xmm[0];
  LODWORD(v18) = COERCE_UNSIGNED_INT(result.v2.w - result.v2.z) ^ _xmm[0];
  v19 = fsqrt(
          (float)((float)(*(float *)&v7 * *(float *)&v7)
                + (float)(COERCE_FLOAT(LODWORD(result.v0.z) ^ _xmm[0]) * COERCE_FLOAT(LODWORD(result.v0.z) ^ _xmm[0])))
        + (float)(COERCE_FLOAT(LODWORD(result.v2.z) ^ _xmm[0]) * COERCE_FLOAT(LODWORD(result.v2.z) ^ _xmm[0])));
  result.v2.y = (float)(1.0 / v19) * COERCE_FLOAT(LODWORD(result.v1.x) ^ _xmm[0]);
  result.v1.z = (float)(1.0 / v19) * COERCE_FLOAT(LODWORD(result.v0.z) ^ _xmm[0]);
  result.v2.x = (float)(1.0 / v19) * COERCE_FLOAT(LODWORD(result.v2.z) ^ _xmm[0]);
  result.v1.w = (float)(1.0 / v19) * *(float *)&v7;
  v20 = fsqrt((float)((float)(v11 * v11) + (float)(v8 * v8)) + (float)(v12 * v12));
  result.v2.z = (float)(1.0 / v20) * v8;
  result.v2.w = (float)(1.0 / v20) * v11;
  result.v3.y = (float)(1.0 / v20) * COERCE_FLOAT(COERCE_UNSIGNED_INT(result.v0.z + result.v1.y) ^ _xmm[0]);
  result.v3.x = (float)(1.0 / v20) * v12;
  v21 = fsqrt((float)((float)(v14 * v14) + (float)(v13 * v13)) + (float)(v15 * v15));
  v32 = (float)(1.0 / v21) * COERCE_FLOAT(COERCE_UNSIGNED_INT(result.v1.y - result.v0.z) ^ _xmm[0]);
  result.v3.z = (float)(1.0 / v21) * v13;
  v31 = (float)(1.0 / v21) * v15;
  result.v3.w = (float)(1.0 / v21) * v14;
  v22 = (__m128)LODWORD(centre_distance_to_nearplan);
  v22.m128_f32[0] = (float)((float)(v22.m128_f32[0] * v22.m128_f32[0]) + (float)(v46 * v46)) + (float)(vars0 * vars0);
  LODWORD(v23) = (unsigned __int128)_mm_sqrt_ps(v22);
  v33 = (float)(1.0 / v23) * v46;
  v35 = (float)(1.0 / v23) * vars0;
  v34 = (float)(1.0 / v23) * centre_distance_to_nearplan;
  v24 = (__m128)LODWORD(v10);
  v36 = (float)(1.0 / v23) * COERCE_FLOAT(COERCE_UNSIGNED_INT(result.v0.w + result.v1.y) ^ _xmm[0]);
  v24.m128_f32[0] = (float)((float)(v24.m128_f32[0] * v24.m128_f32[0]) + (float)(v16 * v16)) + (float)(v9 * v9);
  v25 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v24));
  v40 = v25 * COERCE_FLOAT(COERCE_UNSIGNED_INT(result.v1.y - result.v0.w) ^ _xmm[0]);
  v37 = v25 * v16;
  v38 = v25 * v10;
  v39 = v25 * v9;
  LODWORD(v26) = COERCE_UNSIGNED_INT(result.v0.w - result.v0.z) ^ _xmm[0];
  v27 = (__m128)LODWORD(v17);
  v27.m128_f32[0] = (float)((float)(v27.m128_f32[0] * v27.m128_f32[0]) + (float)(v26 * v26)) + (float)(v18 * v18);
  v28 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v27));
  v44 = v28 * COERCE_FLOAT(COERCE_UNSIGNED_INT(result.v1.y - result.v1.x) ^ _xmm[0]);
  v43 = v28 * v18;
  v41 = v28 * v26;
  v42 = v28 * v17;
  centre_distance_to_nearplan = 0.0;
  return (unsigned int)IntersectAABBFrustum(
                         (UFG::qVector4 *)((char *)&result.v1 + 8),
                         &v2->mBox.mMin,
                         &v2->mBox.mMax,
                         &centre_distance_to_nearplan) <= 1;
}

// File Line: 196
// RVA: 0x4AC630
char __fastcall UFG::GameLayerActivationBehaviour::IsGeoProgression(UFG::GameLayerActivationBehaviour *this, UFG::SceneLayer *scene_layer)
{
  UFG::GameLayerActivationBehaviour *v2; // rsi
  char v3; // di
  unsigned int v4; // edx
  UFG::qBaseTreeRB *v5; // rcx
  float v6; // er14
  UFG::qBaseTreeRB *v7; // rbp
  UFG::qBaseTreeRB *v8; // rbx
  bool v9; // r15
  bool v10; // r12
  bool v11; // r13
  unsigned int v12; // eax
  unsigned int v13; // eax
  int v15; // eax
  unsigned int v16; // edx
  unsigned int v17; // edx
  int v18; // eax
  bool v19; // dl
  int v20; // ecx
  unsigned int v21; // eax
  char v22; // al
  unsigned int v23; // eax
  bool v24; // zf
  __int64 v25; // rbx
  UFG::PersistentData::MapInt *v26; // r8
  __int64 v27; // rax
  UFG::PersistentData::KeyValue *v28; // rcx
  UFG::qBaseTreeRB *v29; // [rsp+60h] [rbp+8h]

  v2 = this;
  v3 = 1;
  v4 = _S19_1;
  if ( !(_S19_1 & 1) )
  {
    _S19_1 |= 1u;
    UFG::ProgressionTracker::ProgressionTracker(&sProgressionTracker);
    atexit(UFG::ProgressionTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sProgressionTracker__);
    v4 = _S19_1;
  }
  UFG::ProgressionTracker::mspInstance = &sProgressionTracker;
  v5 = (UFG::qBaseTreeRB *)unk_14240B6D0;
  v29 = (UFG::qBaseTreeRB *)unk_14240B6D0;
  v6 = 0.0;
  v7 = 0i64;
  v8 = 0i64;
  v9 = 0;
  v10 = 0;
  v11 = 0;
  if ( v2->mGeoProgressionStart.mUID != -1 )
  {
    if ( !(v4 & 1) )
    {
      _S19_1 = v4 | 1;
      UFG::ProgressionTracker::ProgressionTracker(&sProgressionTracker);
      atexit(UFG::ProgressionTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sProgressionTracker__);
      v4 = _S19_1;
    }
    UFG::ProgressionTracker::mspInstance = &sProgressionTracker;
    v12 = v2->mGeoProgressionStart.mUID;
    if ( !v12 || (v7 = UFG::qBaseTreeRB::Get(&stru_14240A100, v12), v4 = _S19_1, !v7) )
    {
      v13 = v2->mGeoProgressionStart.mUID;
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
    if ( v7 == v29 )
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
  if ( v2->mGeoProgressionEnd.mUID == -1 )
    goto LABEL_28;
  if ( !(v4 & 1) )
  {
    _S19_1 = v4 | 1;
    UFG::ProgressionTracker::ProgressionTracker(&sProgressionTracker);
    atexit(UFG::ProgressionTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sProgressionTracker__);
  }
  UFG::ProgressionTracker::mspInstance = &sProgressionTracker;
  v16 = v2->mGeoProgressionEnd.mUID;
  if ( !v16 || (v8 = UFG::qBaseTreeRB::Get(&stru_14240A100, v16)) == 0i64 )
  {
    v17 = v2->mGeoProgressionEnd.mUID;
    if ( v17 )
      v8 = UFG::qBaseTreeRB::Get(&stru_14240A148, v17);
    else
      v8 = 0i64;
  }
  if ( !v8 )
    return 0;
  v5 = v29;
  if ( v8 == v29 )
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
  if ( v2->mOffDuringMissions && v5 )
  {
    v20 = HIDWORD(v5[3].mNULL.mChild[1]);
    v3 = (v20 - 7) & 0xFFFFFFFA || v20 == 12;
  }
  if ( v7 )
  {
    v21 = v2->mGeoProgressionStartCondition;
    if ( v21 == 4 )
    {
      v3 &= v9;
    }
    else if ( v21 == 12 )
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
  v23 = v2->mGeoProgressionEndCondition;
  if ( v23 == 4 )
  {
    v24 = v11 == 0;
LABEL_50:
    v3 &= v24;
    goto LABEL_51;
  }
  if ( v23 != 12 )
  {
    v24 = v19 == 0;
    goto LABEL_50;
  }
  v3 &= v11 == 0 && v19 == 0;
LABEL_51:
  if ( v2->mIsCollectibleCategory )
  {
    v25 = v2->mCollectibleCategory;
    v26 = UFG::GameStatTracker::Instance()->mpSnapshots[0]->mpMapInts[v25];
    v27 = 0i64;
    if ( v26->mValues.size )
    {
      v28 = v26->mValues.p;
      while ( v28->mKey.mUID != v2->mCollectibleItem.mUID )
      {
        v27 = (unsigned int)(v27 + 1);
        ++v28;
        if ( (unsigned int)v27 >= v26->mValues.size )
          goto LABEL_59;
      }
      if ( (_DWORD)v27 != -1 )
        v6 = v26->mValues.p[v27].mFloatValue;
    }
LABEL_59:
    v3 &= LODWORD(v6) == v2->mCollectibleItemStage;
  }
  return v3;
}

// File Line: 324
// RVA: 0x4BE710
bool __fastcall UFG::GameLayerActivationBehaviour::ShouldLayerBeActive(UFG::GameLayerActivationBehaviour *this, UFG::SceneLayer *scene_layer, UFG::qVector3 *testPoint, bool activeState)
{
  bool v4; // r12
  UFG::qVector3 *v5; // r15
  UFG::SceneLayer *v6; // rbx
  UFG::GameLayerActivationBehaviour *v7; // r14
  bool v8; // di
  __int128 v9; // xmm7
  __int128 v10; // xmm6
  UFG::qSymbol *v12; // rbp
  char v13; // al
  float v14; // xmm1_4
  bool v15; // si
  float v16; // xmm0_4
  bool v17; // cf
  float v18; // xmm0_4
  UFG::qSymbol result; // [rsp+80h] [rbp+8h]

  v4 = activeState;
  v5 = testPoint;
  v6 = scene_layer;
  v7 = this;
  v8 = 0;
  v9 = LODWORD(UFG::TimeOfDayManager::GetInstance()->m_SecondsSinceMidnight);
  v10 = LODWORD(UFG::TimeOfDayManager::GetInstance()->m_WeatherState);
  if ( !v7->vfptr->LayerBelongsToCurrentFlow((UFG::ILayerActivationBehaviour *)&v7->vfptr, v6) )
    return 0;
  if ( !((v6->mFlags >> 10) & 1) )
  {
    v12 = UFG::GeographicalLayerManager::GetActiveCategory();
    v13 = v12->mUID == -1 ? ~(LOWORD(v6->mFlags) >> 8) & 1 : v12->mUID != UFG::SceneLayer::GetIndoorCategory(
                                                                            v6,
                                                                            &result)->mUID;
    if ( v13 )
      return 0;
  }
  v14 = UFG::qBox::DistanceSqrPoint(&v6->mBox, v5);
  if ( v14 >= gLayer_OutFrustum_ActDistSqrd )
  {
    v15 = gLayer_InFrustum_ActDistSqrd > v14;
    if ( gLayer_InFrustum_ActDistSqrd > v14 )
      v15 = UFG::GameLayerActivationBehaviour::IsGeoInFrustum(v7, v6);
  }
  else
  {
    v15 = 1;
  }
  if ( !UFG::GameLayerActivationBehaviour::IsGeoProgression(v7, v6) )
    goto LABEL_32;
  if ( v4 )
  {
    v8 = v15 || v6->mDeactivateTimer > 0.0;
    if ( UFG::GeographicalLayerManager::GetInstance()->mAllowImmediateActivation )
    {
      if ( !v8 || !UFG::GameLayerActivationBehaviour::IsGeoTimeOfDay(v7, v6, *(float *)&v9) )
      {
        v8 = 0;
        goto LABEL_32;
      }
      goto LABEL_31;
    }
    goto LABEL_32;
  }
  if ( !v15 )
    goto LABEL_36;
  if ( !UFG::GameLayerActivationBehaviour::IsGeoTimeOfDay(v7, v6, *(float *)&v9) )
    goto LABEL_32;
  v16 = v7->mGeoWeatherMin;
  if ( v16 <= -0.001 )
  {
    v18 = v7->mGeoWeatherMax;
    if ( v18 <= -0.001 )
      goto LABEL_29;
    v17 = v18 < *(float *)&v10;
  }
  else
  {
    v17 = *(float *)&v10 < v16;
  }
  if ( v17 )
    goto LABEL_32;
LABEL_29:
  if ( UFG::GeographicalLayerManager::GetInstance()->mAllowImmediateActivation || !((v6->mFlags >> 11) & 1) )
LABEL_31:
    v8 = 1;
LABEL_32:
  if ( v15 )
  {
    if ( v8 )
      v6->mDeactivateTimer = gDelayBeforeDeactivation;
    v6->mFlags |= 0x800u;
    return v8;
  }
LABEL_36:
  v6->mFlags &= 0xFFFFF7FF;
  return v8;
}

// File Line: 468
// RVA: 0x4AD4A0
bool __fastcall UFG::GameLayerActivationBehaviour::LayerBelongsToCurrentFlow(UFG::GameLayerActivationBehaviour *this, UFG::SceneLayer *scene_layer)
{
  UFG::GameLayerActivationBehaviour *v2; // rbx
  unsigned int v3; // ecx
  unsigned int v4; // edx

  v2 = this;
  if ( !(_S19_1 & 1) )
  {
    _S19_1 |= 1u;
    UFG::ProgressionTracker::ProgressionTracker(&sProgressionTracker);
    atexit(UFG::ProgressionTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sProgressionTracker__);
  }
  UFG::ProgressionTracker::mspInstance = &sProgressionTracker;
  v3 = 0;
  v4 = v2->mFlowList.size;
  if ( v4 )
  {
    while ( unk_14240BAE0 != v2->mFlowList.p[v3].mUID )
    {
      if ( ++v3 >= v4 )
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

