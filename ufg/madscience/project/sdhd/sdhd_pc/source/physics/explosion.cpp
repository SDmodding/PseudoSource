// File Line: 126
// RVA: 0x1513C40
__int64 dynamic_initializer_for__UFG::ExplosionManager::mActiveExplosions__()
{
  return atexit(dynamic_atexit_destructor_for__UFG::ExplosionManager::mActiveExplosions__);
}

// File Line: 142
// RVA: 0x46BD30
void __fastcall UFG::ExplosionTypeInfo::LoadRangeValueSet(UFG::ExplosionTypeInfo *this, UFG::qPropertyList *list, UFG::qSymbol *rangeSymbol, UFG::qSymbol *valueSymbol, UFG::ExplosionTypeInfo::RangeValue *rangeValueArray, const int rangeValueArraySize)
{
  unsigned int v6; // ebp
  __int64 v7; // rbx
  UFG::qSymbol *v8; // r13
  UFG::qSymbol *v9; // r12
  UFG::qPropertyList *v10; // r15
  UFG::ExplosionTypeInfo::RangeValue *v11; // rsi
  char *v12; // rax
  UFG::qPropertySet *v13; // rdi
  UFG::ExplosionTypeInfo::RangeValue *v14; // rax
  float *v15; // rax

  v6 = list->mNumElements;
  v7 = 0i64;
  v8 = valueSymbol;
  v9 = rangeSymbol;
  v10 = list;
  if ( v6 )
  {
    v11 = rangeValueArray;
    do
    {
      v12 = UFG::qPropertyList::GetValuePtr(v10, 0x1Au, v7);
      if ( v12 && *(_QWORD *)v12 )
        v13 = (UFG::qPropertySet *)&v12[*(_QWORD *)v12];
      else
        v13 = 0i64;
      v14 = (UFG::ExplosionTypeInfo::RangeValue *)UFG::qPropertySet::Get<float>(v13, v9, DEPTH_RECURSE);
      if ( !v14 )
        v14 = &rangeValueArray[v7];
      v11->range = v14->range;
      v15 = UFG::qPropertySet::Get<float>(v13, v8, DEPTH_RECURSE);
      if ( v15 )
        v11->value = *v15;
      v7 = (unsigned int)(v7 + 1);
      ++v11;
    }
    while ( (unsigned int)v7 < v6 );
  }
}

// File Line: 166
// RVA: 0x4694B0
void __fastcall UFG::ExplosionTypeInfo::Initialize(UFG::ExplosionTypeInfo *this, UFG::qPropertySet *properties)
{
  UFG::qPropertySet *v2; // rbx
  UFG::qPropertySet *v3; // rsi
  UFG::ExplosionTypeInfo *v4; // rdi
  char *v5; // rax
  unsigned int v6; // eax
  float *v7; // rax
  int *v8; // rcx
  int v9; // eax
  bool *v10; // rax
  int *v11; // rcx
  char v12; // al
  bool *v13; // rax
  int *v14; // rcx
  UFG::qSymbol *v15; // rax
  UFG::qSymbol *v16; // rcx
  float *v17; // rax
  float *v18; // rax
  UFG::qPropertyList *v19; // rax
  UFG::qPropertyList *v20; // rbx
  char *v21; // rax
  float *v22; // rax
  float *v23; // rcx
  int v24; // [rsp+40h] [rbp+8h]

  v2 = properties;
  v3 = 0i64;
  this->mPropertySetName.mUID = properties->mName.mUID;
  v4 = this;
  this->mExplosionRadius = 0.0;
  v5 = PropertyUtils::Get<char const *>(properties, (UFG::qSymbol *)&PhysicsSym_ExplosionEffectID.mUID, DEPTH_RECURSE);
  if ( v5 )
    v6 = UFG::qStringHashUpper32(v5, 0xFFFFFFFF);
  else
    v6 = 0;
  v4->mExplosionEffectID = v6;
  v24 = 0;
  v7 = UFG::qPropertySet::Get<float>(v2, (UFG::qSymbol *)&PhysicsSym_ExplosionDuration.mUID, DEPTH_RECURSE);
  v8 = &v24;
  if ( v7 )
    v8 = (int *)v7;
  v9 = *v8;
  LOBYTE(v24) = 0;
  LODWORD(v4->mExplosionDuration) = v9;
  v10 = UFG::qPropertySet::Get<bool>(v2, (UFG::qSymbol *)&PhysicsSym_ExplosionNoDamage.mUID, DEPTH_RECURSE);
  v11 = &v24;
  if ( v10 )
    v11 = (int *)v10;
  v12 = *(_BYTE *)v11 ^ *((_BYTE *)v4 + 188);
  LOBYTE(v24) = 0;
  *((_BYTE *)v4 + 188) ^= v12 & 1;
  v13 = UFG::qPropertySet::Get<bool>(v2, (UFG::qSymbol *)&PhysicsSym_CanTriggerVehicleExplosion.mUID, DEPTH_RECURSE);
  v14 = &v24;
  if ( v13 )
    v14 = (int *)v13;
  *((_BYTE *)v4 + 188) ^= (*((_BYTE *)v4 + 188) ^ 2 * *(_BYTE *)v14) & 2;
  v15 = UFG::qPropertySet::Get<UFG::qSymbol>(v2, (UFG::qSymbol *)&PhysicsSym_SimObjectToSpawn.mUID, DEPTH_RECURSE);
  v16 = &UFG::gNullQSymbol;
  if ( v15 )
    v16 = v15;
  v4->mSimObjectToSpawn = (UFG::qSymbol)v16->mUID;
  v17 = UFG::qPropertySet::Get<float>(v2, (UFG::qSymbol *)&PhysicsSym_CameraShakeAmplitude.mUID, DEPTH_RECURSE);
  if ( !v17 )
    v17 = &v4->mCameraShakeAmplitude;
  v4->mCameraShakeAmplitude = *v17;
  v18 = UFG::qPropertySet::Get<float>(v2, (UFG::qSymbol *)&PhysicsSym_CameraShakeMaxDistance.mUID, DEPTH_RECURSE);
  if ( !v18 )
    v18 = &v4->mCameraShakeMaxDistanceSquared;
  v4->mCameraShakeMaxDistanceSquared = *v18 * *v18;
  v19 = UFG::qPropertySet::Get<UFG::qPropertyList>(
          v2,
          (UFG::qSymbol *)&PhysicsSym_MassMagnitudeTable.mUID,
          DEPTH_RECURSE);
  UFG::ExplosionTypeInfo::LoadRangeValueSet(
    v4,
    v19,
    (UFG::qSymbol *)&PhysicsSym_ExplosionMass.mUID,
    (UFG::qSymbol *)&PhysicsSym_ExplosionMagnitude.mUID,
    v4->mMassMagnitudeValue,
    10);
  v20 = UFG::qPropertySet::Get<UFG::qPropertyList>(
          v2,
          (UFG::qSymbol *)&PhysicsSym_DistanceMagnitudeRatioTable.mUID,
          DEPTH_RECURSE);
  UFG::ExplosionTypeInfo::LoadRangeValueSet(
    v4,
    v20,
    (UFG::qSymbol *)&PhysicsSym_Distance.mUID,
    (UFG::qSymbol *)&PhysicsSym_Ratio.mUID,
    v4->mDistanceMagnitudeRatio,
    10);
  v21 = UFG::qPropertyList::GetValuePtr(v20, 0x1Au, v20->mNumElements - 1);
  if ( v21 && *(_QWORD *)v21 )
    v3 = (UFG::qPropertySet *)&v21[*(_QWORD *)v21];
  v22 = UFG::qPropertySet::Get<float>(v3, (UFG::qSymbol *)&PhysicsSym_Distance.mUID, DEPTH_RECURSE);
  v23 = &v4->mExplosionRadius;
  if ( v22 )
    v23 = v22;
  v4->mExplosionRadius = *v23;
}

// File Line: 213
// RVA: 0x4665B0
float __fastcall UFG::ExplosionTypeInfo::GetExplosionMagnitude(UFG::ExplosionTypeInfo *this, float mass, float distance, float *ratio)
{
  int v4; // edx
  float v5; // xmm3_4
  UFG::ExplosionTypeInfo *v6; // r11
  float *v7; // rax
  int v8; // er10
  signed __int64 v9; // r8
  float v10; // xmm5_4
  signed __int64 v11; // rcx
  float *v12; // rax

  v4 = 0;
  v5 = 0.0;
  v6 = this;
  v7 = (float *)this->mMassMagnitudeValue;
  v8 = 0;
  v9 = 0i64;
  v10 = 0.0;
  while ( mass >= *v7 )
  {
    ++v9;
    ++v8;
    v7 += 2;
    if ( v9 >= 10 )
      goto LABEL_8;
  }
  if ( v8 )
    v10 = (float)((float)((float)(mass - *(&this->mCameraShakeAmplitude + 2 * v8))
                        / (float)(this->mMassMagnitudeValue[v8].range - *(&this->mCameraShakeAmplitude + 2 * v8)))
                * (float)(this->mMassMagnitudeValue[v8].value - this->mMassMagnitudeValue[v8 - 1].value))
        + this->mMassMagnitudeValue[v8 - 1].value;
  else
    v10 = this->mMassMagnitudeValue[0].value;
LABEL_8:
  v11 = 0i64;
  v12 = (float *)v6->mDistanceMagnitudeRatio;
  while ( distance >= *v12 )
  {
    ++v11;
    ++v4;
    v12 += 2;
    if ( v11 >= 10 )
      goto LABEL_15;
  }
  if ( v4 )
    v5 = (float)((float)((float)(distance - v6->mMassMagnitudeValue[v4 + 9].range)
                       / (float)(v6->mDistanceMagnitudeRatio[v4].range - v6->mMassMagnitudeValue[v4 + 9].range))
               * (float)(v6->mDistanceMagnitudeRatio[v4].value - v6->mDistanceMagnitudeRatio[v4 - 1].value))
       + v6->mDistanceMagnitudeRatio[v4 - 1].value;
  else
    v5 = v6->mDistanceMagnitudeRatio[0].value;
LABEL_15:
  if ( ratio )
    *ratio = v5;
  return v5 * v10;
}

// File Line: 269
// RVA: 0x464730
UFG::qPropertySet *__fastcall UFG::FindInList(UFG::qPropertyList *list, __int64 symbol)
{
  unsigned int v2; // edi
  unsigned int v3; // ebx
  _DWORD *v4; // rsi
  UFG::qPropertyList *v5; // rbp
  char *v6; // rax
  UFG::qPropertySet *result; // rax

  v2 = list->mNumElements;
  v3 = 0;
  v4 = (_DWORD *)symbol;
  v5 = list;
  if ( !v2 )
    return 0i64;
  while ( 1 )
  {
    v6 = UFG::qPropertyList::GetValuePtr(v5, 0x1Au, v3);
    if ( v6 && *(_QWORD *)v6 )
      result = (UFG::qPropertySet *)&v6[*(_QWORD *)v6];
    else
      result = 0i64;
    if ( result->mName.mUID == *v4 )
      break;
    if ( ++v3 >= v2 )
      return 0i64;
  }
  return result;
}

// File Line: 289
// RVA: 0x469160
void UFG::ExplosionManager::Initialize(void)
{
  UFG::ExplosionTypeInfo **v0; // rbx
  UFG::qSymbol *v1; // rax
  UFG::qPropertySet *v2; // rax
  UFG::qPropertyList *v3; // rcx
  UFG::qPropertySet *v4; // rax
  UFG::qPropertyList *v5; // rcx
  UFG::qPropertySet *v6; // rax
  UFG::qPropertyList *v7; // rsi
  unsigned int v8; // er14
  unsigned int v9; // edi
  UFG::allocator::free_link *v10; // rax
  UFG::ExplosionTypeInfo *v11; // rax
  UFG::qSymbol *v12; // rax
  UFG::qPropertySet *v13; // rax
  signed __int64 v14; // rdi
  char v15; // dl
  __int64 v16; // rax
  char v17; // cl
  _QWORD **v18; // rax
  hkpSphereShape *v19; // rax
  hkpSphereShape *v20; // rax
  char v21; // al
  char v22; // dl
  __int64 v23; // rax
  char v24; // cl
  _QWORD **v25; // rax
  __int64 v26; // rax
  __int64 v27; // rsi
  signed __int64 v28; // rbx
  char v29; // al
  UFG::qSymbol v30; // [rsp+30h] [rbp-39h]
  UFG::qSymbol result; // [rsp+34h] [rbp-35h]
  __int64 v32; // [rsp+38h] [rbp-31h]
  UFG::qSymbol *v33; // [rsp+40h] [rbp-29h]
  __m128 v34; // [rsp+50h] [rbp-19h]
  __m128 v35; // [rsp+60h] [rbp-9h]
  __m128 v36; // [rsp+70h] [rbp+7h]
  __int128 v37; // [rsp+80h] [rbp+17h]
  UFG::qSymbol symbol; // [rsp+D0h] [rbp+67h]
  UFG::qSymbol name; // [rsp+D8h] [rbp+6Fh]
  UFG::qSymbol v40; // [rsp+E0h] [rbp+77h]
  UFG::qSymbol v41; // [rsp+E8h] [rbp+7Fh]

  v32 = -2i64;
  if ( UFG::ExplosionManager::sIsInitialized )
    UFG::ExplosionManager::Shutdown();
  UFG::ExplosionManager::sIsInitialized = 1;
  v0 = UFG::ExplosionManager::sExplosionTypeInfos;
  memset(UFG::ExplosionManager::sExplosionTypeInfos, 0, 0x110ui64);
  UFG::qSymbol::create_from_string(&result, "archetypes");
  UFG::qSymbol::create_from_string(&name, "subfolders");
  UFG::qSymbol::create_from_string(&v41, "physical");
  UFG::qSymbol::create_from_string(&v30, "explosion");
  v1 = UFG::qSymbol::create_from_string(&v40, "object-manifest");
  v2 = UFG::PropertySetManager::GetPropertySet(v1);
  v33 = &symbol;
  symbol.mUID = v41.mUID;
  v3 = UFG::qPropertySet::Get<UFG::qPropertyList>(v2, &name, DEPTH_RECURSE);
  v4 = UFG::FindInList(v3, (__int64)&symbol);
  v33 = &v40;
  v40.mUID = v30.mUID;
  v5 = UFG::qPropertySet::Get<UFG::qPropertyList>(v4, &name, DEPTH_RECURSE);
  v6 = UFG::FindInList(v5, (__int64)&v40);
  v7 = UFG::qPropertySet::Get<UFG::qPropertyList>(v6, &result, DEPTH_RECURSE);
  v8 = v7->mNumElements;
  v9 = 0;
  if ( v8 )
  {
    do
    {
      v10 = UFG::qMemoryPool::Allocate(&gPhysicsMemoryPool, 0xC0ui64, "ExplosionTypeInfo", 0i64, 1u);
      *(_QWORD *)&symbol.mUID = v10;
      if ( v10 )
        UFG::ExplosionTypeInfo::ExplosionTypeInfo((UFG::ExplosionTypeInfo *)v10);
      else
        v11 = 0i64;
      *v0 = v11;
      v12 = UFG::qPropertyList::Get<UFG::qSymbol>(v7, v9);
      v13 = UFG::PropertySetManager::GetPropertySet(v12);
      UFG::ExplosionTypeInfo::Initialize(*v0, v13);
      ++v9;
      ++v0;
    }
    while ( v9 < v8 );
  }
  v14 = *((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 16i64;
  v15 = ++*(_BYTE *)(v14 + 80);
  v16 = v15;
  *(_DWORD *)(v14 + 4 * v16) = 3;
  *(_QWORD *)(v14 + 8 * v16 + 16) = "Explosion::hkpSphereShape";
  *(_QWORD *)(v14 + 8 * v16 + 48) = 0i64;
  v17 = *(_BYTE *)(v14 + 81);
  if ( v15 > v17 )
    v17 = v15;
  *(_BYTE *)(v14 + 81) = v17;
  v18 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v19 = (hkpSphereShape *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v18[11] + 8i64))(v18[11], 56i64);
  *(_QWORD *)&symbol.mUID = v19;
  if ( v19 )
    hkpSphereShape::hkpSphereShape(v19, 0.1);
  else
    v20 = 0i64;
  UFG::ExplosionManager::mClosestPointsSphere = v20;
  v21 = *(_BYTE *)(v14 + 80);
  if ( v21 > 0 )
  {
    *(_BYTE *)(v14 + 80) = v21 - 1;
  }
  else
  {
    *(_BYTE *)(v14 + 80) = 0;
    *(_DWORD *)v14 = 3;
    *(_QWORD *)(v14 + 16) = 0i64;
    *(_QWORD *)(v14 + 48) = 0i64;
  }
  v34 = transform.m_quad;
  v35 = direction.m_quad;
  v36 = stru_141A71280.m_quad;
  v37 = 0i64;
  v22 = ++*(_BYTE *)(v14 + 80);
  v23 = v22;
  *(_DWORD *)(v14 + 4 * v23) = 3;
  *(_QWORD *)(v14 + 8 * v23 + 16) = "Explosion::hkpCdBody";
  *(_QWORD *)(v14 + 8 * v23 + 48) = 0i64;
  v24 = *(_BYTE *)(v14 + 81);
  if ( v22 > v24 )
    v24 = v22;
  *(_BYTE *)(v14 + 81) = v24;
  v25 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v26 = (*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v25[11] + 8i64))(v25[11], 112i64);
  v27 = v26;
  *(_QWORD *)&symbol.mUID = v26;
  if ( v26 )
  {
    *(_QWORD *)v26 = UFG::ExplosionManager::mClosestPointsSphere;
    *(_QWORD *)(v26 + 16) = &v34;
    *(_QWORD *)(v26 + 24) = 0i64;
    *(_DWORD *)(v26 + 8) = -1;
    *(_BYTE *)(v26 + 32) = 0;
    v28 = v26 + 36;
    *(_DWORD *)v28 = 0;
    *(_WORD *)(v28 + 4) = 32512;
    *(_DWORD *)(v28 + 8) = 0;
    *(_BYTE *)(v28 + 6) = -1;
    hkpCollidable::BoundingVolumeData::BoundingVolumeData((hkpCollidable::BoundingVolumeData *)(v26 + 48));
    *(_DWORD *)(v27 + 104) = -1082130432;
    *(_BYTE *)(v27 + 41) = -36;
    *(_BYTE *)(v27 + 33) = 8;
    *(_WORD *)(v27 + 34) = 0;
  }
  else
  {
    v27 = 0i64;
  }
  UFG::ExplosionManager::mClosestPointsCollidable = (hkpCollidable *)v27;
  *(_DWORD *)(v27 + 44) = 0;
  v29 = *(_BYTE *)(v14 + 80);
  if ( v29 > 0 )
  {
    *(_BYTE *)(v14 + 80) = v29 - 1;
  }
  else
  {
    *(_BYTE *)(v14 + 80) = 0;
    *(_DWORD *)v14 = 3;
    *(_QWORD *)(v14 + 16) = 0i64;
    *(_QWORD *)(v14 + 48) = 0i64;
  }
}

// File Line: 356
// RVA: 0x475E40
void UFG::ExplosionManager::Shutdown(void)
{
  signed __int64 v0; // rdi
  void **v1; // rbx
  hkpCollidable *v2; // rbx
  _QWORD **v3; // rax

  if ( UFG::ExplosionManager::sIsInitialized )
  {
    v0 = 34i64;
    v1 = (void **)UFG::ExplosionManager::sExplosionTypeInfos;
    do
    {
      if ( *v1 )
      {
        UFG::qMemoryPool::Free(&gPhysicsMemoryPool, *v1);
        *v1 = 0i64;
      }
      ++v1;
      --v0;
    }
    while ( v0 );
    v2 = UFG::ExplosionManager::mClosestPointsCollidable;
    UFG::ExplosionManager::sIsInitialized = 0;
    if ( UFG::ExplosionManager::mClosestPointsCollidable )
    {
      v3 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      (*(void (__fastcall **)(_QWORD *, hkpCollidable *, signed __int64))(*v3[11] + 16i64))(v3[11], v2, 112i64);
    }
    hkReferencedObject::removeReference((hkReferencedObject *)&UFG::ExplosionManager::mClosestPointsSphere->vfptr);
  }
}

// File Line: 377
// RVA: 0x4666E0
UFG::ExplosionTypeInfo *__fastcall UFG::ExplosionManager::GetExplosionTypeInfo(UFG::qSymbol *explosionPropertySet)
{
  signed int v1; // edx
  UFG::ExplosionTypeInfo **v2; // r8

  v1 = 0;
  v2 = UFG::ExplosionManager::sExplosionTypeInfos;
  while ( 1 )
  {
    if ( !*v2 )
      return 0i64;
    if ( (*v2)->mPropertySetName.mUID == explosionPropertySet->mUID )
      break;
    ++v1;
    ++v2;
    if ( v1 >= 34 )
      return 0i64;
  }
  return *v2;
}

// File Line: 398
// RVA: 0x45C900
void __fastcall UFG::ExplosionManager::CreateExplosion(UFG::qVector3 *pos, UFG::qSymbol *explosionPropertySet, UFG::SimObject *source, UFG::SimObject *attacker)
{
  UFG::SimObject *v4; // rdi
  UFG::qSymbol *v5; // rsi
  UFG::qVector3 *v6; // rbp
  UFG::allocator::free_link *v7; // rax
  UFG::qNode<UFG::ExplosionManager::Explosion,UFG::ExplosionManager::Explosion> *v8; // rcx
  UFG::qNode<UFG::ExplosionManager::Explosion,UFG::ExplosionManager::Explosion> *v9; // rax

  v4 = source;
  v5 = explosionPropertySet;
  v6 = pos;
  v7 = UFG::qMalloc(0xB0ui64, UFG::gGlobalNewName, 0i64);
  if ( v7 )
    UFG::ExplosionManager::Explosion::Explosion((UFG::ExplosionManager::Explosion *)v7, v6, v5, v4);
  v8 = (UFG::qNode<UFG::ExplosionManager::Explosion,UFG::ExplosionManager::Explosion> *)&v7[1];
  v9 = UFG::ExplosionManager::mActiveExplosions.mNode.mNext;
  UFG::ExplosionManager::mActiveExplosions.mNode.mNext = v8;
  v8->mPrev = (UFG::qNode<UFG::ExplosionManager::Explosion,UFG::ExplosionManager::Explosion> *)&UFG::ExplosionManager::mActiveExplosions;
  v8->mNext = v9;
  v9->mPrev = v8;
}

// File Line: 406
// RVA: 0x479570
void __fastcall UFG::ExplosionManager::Update(float deltaT)
{
  UFG::ExplosionManager::Explosion *v1; // rbx
  UFG::qList<UFG::ExplosionManager::Explosion,UFG::ExplosionManager::Explosion,1,0> *v2; // rdi
  UFG::qNode<UFG::ExplosionManager::Explosion,UFG::ExplosionManager::Explosion> *v3; // rdx
  UFG::qNode<UFG::ExplosionManager::Explosion,UFG::ExplosionManager::Explosion> *v4; // rax
  UFG::qNode<UFG::ExplosionManager::Explosion,UFG::ExplosionManager::Explosion> *v5; // r8

  v1 = (UFG::ExplosionManager::Explosion *)&UFG::ExplosionManager::mActiveExplosions.mNode.mNext[-1].mNext;
  if ( &UFG::ExplosionManager::mActiveExplosions.mNode.mNext[-1].mNext != (UFG::qNode<UFG::ExplosionManager::Explosion,UFG::ExplosionManager::Explosion> **)((char *)&UFG::ExplosionManager::mActiveExplosions - 8) )
  {
    do
    {
      v2 = (UFG::qList<UFG::ExplosionManager::Explosion,UFG::ExplosionManager::Explosion,1,0> *)&v1->mNext[-1].mNext;
      if ( (unsigned __int8)UFG::ExplosionManager::Explosion::Update(v1, deltaT) )
      {
        v3 = v1->mPrev;
        v4 = v1->mNext;
        v5 = (UFG::qNode<UFG::ExplosionManager::Explosion,UFG::ExplosionManager::Explosion> *)&v1->mPrev;
        v3->mNext = v4;
        v4->mPrev = v3;
        v5->mPrev = v5;
        v5->mNext = v5;
        v1->vfptr->__vecDelDtor(v1, 1u);
      }
      v1 = (UFG::ExplosionManager::Explosion *)v2;
    }
    while ( v2 != (UFG::qList<UFG::ExplosionManager::Explosion,UFG::ExplosionManager::Explosion,1,0> *)((char *)&UFG::ExplosionManager::mActiveExplosions - 8) );
  }
}

// File Line: 437
// RVA: 0x449A10
void __fastcall UFG::ExplosionManager::Explosion::Explosion(UFG::ExplosionManager::Explosion *this, UFG::qVector3 *pos, UFG::qSymbol *explosionPropertySet, UFG::SimObject *source)
{
  UFG::SimObject *v4; // r11
  UFG::qSymbol *v5; // r10
  UFG::qVector3 *v6; // r15
  UFG::ExplosionManager::Explosion *v7; // rdi
  UFG::qNode<UFG::ExplosionManager::Explosion,UFG::ExplosionManager::Explosion> *v8; // rax
  signed int v9; // er9
  UFG::ExplosionTypeInfo **v10; // r8
  UFG::ExplosionTypeInfo *v11; // rcx
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v12; // r8
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v13; // rdx
  __m128 v14; // xmm3
  float v15; // xmm1_4
  float v16; // xmm0_4
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v17; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v18; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v19; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v20; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v21; // rax
  __int64 v22; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v23; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v24; // rax
  unsigned int v25; // edx
  UFG::ExplosionTypeInfo *v26; // rcx
  float v27; // xmm0_4
  __m128 v28; // xmm9
  float v29; // xmm7_4
  signed __int64 v30; // rsi
  char v31; // dl
  __int64 v32; // rax
  char v33; // cl
  _QWORD **v34; // rax
  hkpSphereShape *v35; // rax
  hkpSphereShape *v36; // rax
  char v37; // al
  signed __int64 v38; // rbx
  char v39; // dl
  __int64 v40; // rax
  char v41; // cl
  _QWORD **v42; // rax
  __int64 v43; // rax
  __int64 v44; // r14
  signed __int64 v45; // rbx
  char v46; // al
  UFG::SimObject *v47; // r9
  UFG::SimComponent *v48; // rax
  UFG::GameCameraComponent *v49; // rbx
  float *v50; // rax
  float v51; // xmm0_4
  float v52; // xmm3_4
  UFG::ExplosionTypeInfo *v53; // rax
  float v54; // xmm0_4
  UFG::qSymbol *v55; // rcx
  UFG::qPropertySet *v56; // rbx
  __int64 v57; // r8
  UFG::StimulusParameters stimulus_parameters; // [rsp+30h] [rbp-89h]
  char *pszSymbolString[2]; // [rsp+48h] [rbp-71h]
  UFG::qMatrix44 basis; // [rsp+58h] [rbp-61h]
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v61; // [rsp+110h] [rbp+57h]
  UFG::SimObject *v62; // [rsp+128h] [rbp+6Fh]
  char vars0; // [rsp+130h] [rbp+77h]
  void *retaddr; // [rsp+138h] [rbp+7Fh]

  *(_QWORD *)&basis.v1.x = -2i64;
  v4 = source;
  v5 = explosionPropertySet;
  v6 = pos;
  v7 = this;
  v8 = (UFG::qNode<UFG::ExplosionManager::Explosion,UFG::ExplosionManager::Explosion> *)&this->mPrev;
  v8->mPrev = v8;
  v8->mNext = v8;
  this->vfptr = (UFG::ExplosionManager::ExplosionVtbl *)&UFG::ExplosionManager::Explosion::`vftable;
  v9 = 0;
  v10 = UFG::ExplosionManager::sExplosionTypeInfos;
  do
  {
    v11 = *v10;
    if ( !*v10 )
      break;
    if ( v11->mPropertySetName.mUID == v5->mUID )
      goto LABEL_6;
    ++v9;
    ++v10;
  }
  while ( v9 < 34 );
  v11 = 0i64;
LABEL_6:
  v7->mExplosionInfo = v11;
  v12 = &v7->mSource;
  v12->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v12->mPrev;
  v12->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v12->mPrev;
  v7->mSource.m_pPointer = 0i64;
  v13 = &v7->mAttacker;
  v61 = v13;
  v13->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v13->mPrev;
  v13->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v13->mPrev;
  v7->mAttacker.m_pPointer = 0i64;
  v14 = 0i64;
  v14.m128_f32[0] = (float)1;
  *(__m128 *)&basis.v0.z = v14;
  *(__m128 *)&basis.v1.z = _mm_shuffle_ps(v14, v14, 81);
  *(__m128 *)pszSymbolString = _mm_shuffle_ps(v14, v14, 69);
  basis.v0 = (UFG::qVector4)_mm_shuffle_ps(v14, v14, 21);
  v15 = v6->y;
  v16 = v6->z;
  basis.v0.x = v6->x;
  basis.v0.y = v15;
  basis.v0.z = v16;
  basis.v0.w = 1.0;
  if ( v7->mSource.m_pPointer )
  {
    v17 = v12->mPrev;
    v18 = v7->mSource.mNext;
    v17->mNext = v18;
    v18->mPrev = v17;
    v12->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v12->mPrev;
    v7->mSource.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v7->mSource.mPrev;
  }
  v7->mSource.m_pPointer = v4;
  if ( v4 )
  {
    v19 = v4->m_SafePointerList.mNode.mPrev;
    v19->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v12->mPrev;
    v12->mPrev = v19;
    v7->mSource.mNext = &v4->m_SafePointerList.mNode;
    v4->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v12->mPrev;
  }
  if ( v7->mAttacker.m_pPointer )
  {
    v20 = v13->mPrev;
    v21 = v7->mAttacker.mNext;
    v20->mNext = v21;
    v21->mPrev = v20;
    v13->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v13->mPrev;
    v7->mAttacker.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v7->mAttacker.mPrev;
  }
  v22 = (__int64)v62;
  v7->mAttacker.m_pPointer = v62;
  if ( v22 )
  {
    v23 = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)(v22 + 8);
    v24 = v23->mPrev;
    v24->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v13->mPrev;
    v13->mPrev = v24;
    v7->mAttacker.mNext = v23;
    v23->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v13->mPrev;
  }
  v25 = v7->mExplosionInfo->mExplosionEffectID;
  if ( v25 )
    Render::FXManager::CreateEffect(&Render::gFXManager, v25, (UFG::qMatrix44 *)((char *)&basis + 8), 0xFFFFFFFF);
  v26 = v7->mExplosionInfo;
  v27 = v26->mExplosionDuration;
  v7->mTimeRemaining = v27;
  v7->mUseForce = v27 > 0.0;
  v28 = _mm_unpacklo_ps(
          _mm_unpacklo_ps((__m128)LODWORD(v6->x), (__m128)LODWORD(v6->z)),
          _mm_unpacklo_ps((__m128)LODWORD(v6->y), (__m128)0i64));
  v29 = v26->mExplosionRadius;
  v30 = *((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 16i64;
  v31 = ++*(_BYTE *)(v30 + 80);
  v32 = v31;
  *(_DWORD *)(v30 + 4 * v32) = 3;
  *(_QWORD *)(v30 + 8 * v32 + 16) = "hkpSphereShape";
  *(_QWORD *)(v30 + 8 * v32 + 48) = 0i64;
  v33 = *(_BYTE *)(v30 + 81);
  if ( v31 > v33 )
    v33 = v31;
  *(_BYTE *)(v30 + 81) = v33;
  v34 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v35 = (hkpSphereShape *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v34[11] + 8i64))(v34[11], 56i64);
  v62 = (UFG::SimObject *)v35;
  if ( v35 )
    hkpSphereShape::hkpSphereShape(v35, v29);
  else
    v36 = 0i64;
  v7->mInfluenceSphere = v36;
  v37 = *(_BYTE *)(v30 + 80);
  if ( v37 > 0 )
  {
    *(_BYTE *)(v30 + 80) = v37 - 1;
  }
  else
  {
    *(_BYTE *)(v30 + 80) = 0;
    *(_DWORD *)v30 = 3;
    *(_QWORD *)(v30 + 16) = 0i64;
    *(_QWORD *)(v30 + 48) = 0i64;
  }
  v38 = (signed __int64)&v7->mTransform;
  *(hkVector4f *)v38 = (hkVector4f)transform.m_quad;
  *(hkVector4f *)(v38 + 16) = (hkVector4f)direction.m_quad;
  *(hkVector4f *)(v38 + 32) = (hkVector4f)stru_141A71280.m_quad;
  *(_OWORD *)(v38 + 48) = 0i64;
  v7->mTransform.m_translation.m_quad = v28;
  v39 = ++*(_BYTE *)(v30 + 80);
  v40 = v39;
  *(_DWORD *)(v30 + 4 * v40) = 3;
  *(_QWORD *)(v30 + 8 * v40 + 16) = "hkpCollidable";
  *(_QWORD *)(v30 + 8 * v40 + 48) = 0i64;
  v41 = *(_BYTE *)(v30 + 81);
  if ( v39 > v41 )
    v41 = v39;
  *(_BYTE *)(v30 + 81) = v41;
  v42 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v43 = (*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v42[11] + 8i64))(v42[11], 112i64);
  v44 = v43;
  v62 = (UFG::SimObject *)v43;
  if ( v43 )
  {
    *(_QWORD *)v43 = v7->mInfluenceSphere;
    *(_QWORD *)(v43 + 16) = v38;
    *(_QWORD *)(v43 + 24) = 0i64;
    *(_DWORD *)(v43 + 8) = -1;
    *(_BYTE *)(v43 + 32) = 0;
    v45 = v43 + 36;
    *(_DWORD *)v45 = 0;
    *(_WORD *)(v45 + 4) = 32512;
    *(_DWORD *)(v45 + 8) = 0;
    *(_BYTE *)(v45 + 6) = -1;
    hkpCollidable::BoundingVolumeData::BoundingVolumeData((hkpCollidable::BoundingVolumeData *)(v43 + 48));
    *(_DWORD *)(v44 + 104) = -1082130432;
    *(_BYTE *)(v45 + 5) = v44 - v45;
    *(_BYTE *)(v44 + 33) = 8;
    *(_WORD *)(v44 + 34) = 0;
  }
  else
  {
    v44 = 0i64;
  }
  v7->mCollidable = (hkpCollidable *)v44;
  v46 = *(_BYTE *)(v30 + 80);
  if ( v46 > 0 )
  {
    *(_BYTE *)(v30 + 80) = v46 - 1;
  }
  else
  {
    *(_BYTE *)(v30 + 80) = 0;
    *(_DWORD *)v30 = 3;
    *(_QWORD *)(v30 + 16) = 0i64;
    *(_QWORD *)(v30 + 48) = 0i64;
  }
  v7->mCollidable->m_broadPhaseHandle.m_collisionFilterInfo = 25;
  if ( (_BYTE)retaddr )
  {
    stimulus_parameters.m_StimulusProducerOffset = UFG::qVector3::msZero;
    stimulus_parameters.m_EmitUntilSpeedLessThan = FLOAT_N1_0;
    stimulus_parameters.m_StimulusEmissionType = 1;
    stimulus_parameters.m_MaxStimulusDuration = 1.0;
    if ( vars0 || (v47 = v7->mAttacker.m_pPointer) == 0i64 || (LOBYTE(v47->m_Flags) >> 1) & 1 )
      UFG::StimulusManager::BeginStimulus(
        UFG::StimulusManager::s_pInstance,
        eSTIMULUS_EXPLOSION,
        &stimulus_parameters,
        v6);
    else
      UFG::StimulusManager::BeginStimulus(
        UFG::StimulusManager::s_pInstance,
        eSTIMULUS_EXPLOSION,
        &stimulus_parameters,
        v47);
  }
  if ( v7->mExplosionInfo->mCameraShakeAmplitude > 0.0 )
  {
    v48 = UFG::GetCurrentGameCamera();
    v49 = (UFG::GameCameraComponent *)v48;
    if ( v48 )
    {
      v50 = (float *)((__int64 (__fastcall *)(UFG::SimComponent *))v48->vfptr[35].__vecDelDtor)(v48);
      v51 = v50[1] - v6->y;
      v52 = (float)((float)((float)(*v50 - v6->x) * (float)(*v50 - v6->x)) + (float)(v51 * v51))
          + (float)((float)(v50[2] - v6->z) * (float)(v50[2] - v6->z));
      v53 = v7->mExplosionInfo;
      v54 = v53->mCameraShakeMaxDistanceSquared;
      if ( v52 < v54 )
        UFG::GameCameraComponent::AddShakeAmplitude(v49, (float)(1.0 - (float)(v52 / v54)) * v53->mCameraShakeAmplitude);
    }
  }
  v55 = &v7->mExplosionInfo->mSimObjectToSpawn;
  if ( v55->mUID != -1 )
  {
    v56 = UFG::PropertySetManager::FindPropertySet(v55);
    if ( v56 )
    {
      v57 = (unsigned int)count_1++;
      UFG::qString::qString((UFG::qString *)&stimulus_parameters, "Explosion-%d", v57);
      UFG::qSymbol::create_from_string((UFG::qSymbol *)&retaddr, pszSymbolString[0]);
      UFG::SpawnInfoInterface::SpawnObject(
        (UFG::qSymbol *)&retaddr,
        v56,
        (UFG::qMatrix44 *)((char *)&basis + 8),
        Count,
        0i64,
        0i64);
      UFG::qString::~qString((UFG::qString *)&stimulus_parameters);
    }
  }
}

// File Line: 537
// RVA: 0x44FF40
void __fastcall UFG::ExplosionManager::Explosion::~Explosion(UFG::ExplosionManager::Explosion *this)
{
  UFG::ExplosionManager::Explosion *v1; // rbx
  hkpCollidable *v2; // rdi
  _QWORD **v3; // rax
  hkpSphereShape *v4; // rcx
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v5; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v6; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v7; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v10; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v11; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v12; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v13; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v14; // rax
  UFG::qNode<UFG::ExplosionManager::Explosion,UFG::ExplosionManager::Explosion> *v15; // rdx
  UFG::qNode<UFG::ExplosionManager::Explosion,UFG::ExplosionManager::Explosion> *v16; // rcx
  UFG::qNode<UFG::ExplosionManager::Explosion,UFG::ExplosionManager::Explosion> *v17; // rax

  v1 = this;
  this->vfptr = (UFG::ExplosionManager::ExplosionVtbl *)&UFG::ExplosionManager::Explosion::`vftable;
  v2 = this->mCollidable;
  if ( v2 )
  {
    v3 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    (*(void (__fastcall **)(_QWORD *, hkpCollidable *, signed __int64))(*v3[11] + 16i64))(v3[11], v2, 112i64);
  }
  v4 = v1->mInfluenceSphere;
  if ( v4 )
    v4->vfptr->__vecDelDtor((hkBaseObject *)&v4->vfptr, 1u);
  v5 = &v1->mAttacker;
  if ( v1->mAttacker.m_pPointer )
  {
    v6 = v5->mPrev;
    v7 = v1->mAttacker.mNext;
    v6->mNext = v7;
    v7->mPrev = v6;
    v5->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v5->mPrev;
    v1->mAttacker.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v1->mAttacker.mPrev;
  }
  v1->mAttacker.m_pPointer = 0i64;
  v8 = v5->mPrev;
  v9 = v1->mAttacker.mNext;
  v8->mNext = v9;
  v9->mPrev = v8;
  v5->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v5->mPrev;
  v1->mAttacker.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v1->mAttacker.mPrev;
  v10 = &v1->mSource;
  if ( v1->mSource.m_pPointer )
  {
    v11 = v10->mPrev;
    v12 = v1->mSource.mNext;
    v11->mNext = v12;
    v12->mPrev = v11;
    v10->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v10->mPrev;
    v1->mSource.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v1->mSource.mPrev;
  }
  v1->mSource.m_pPointer = 0i64;
  v13 = v10->mPrev;
  v14 = v1->mSource.mNext;
  v13->mNext = v14;
  v14->mPrev = v13;
  v10->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v10->mPrev;
  v1->mSource.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v1->mSource.mPrev;
  v15 = (UFG::qNode<UFG::ExplosionManager::Explosion,UFG::ExplosionManager::Explosion> *)&v1->mPrev;
  v16 = v1->mPrev;
  v17 = v1->mNext;
  v16->mNext = v17;
  v17->mPrev = v16;
  v15->mPrev = v15;
  v15->mNext = v15;
}

// File Line: 545
// RVA: 0x477EB0
_BOOL8 __fastcall UFG::ExplosionManager::Explosion::Update(UFG::ExplosionManager::Explosion *this, float deltaT)
{
  float v2; // xmm11_4
  UFG::ExplosionManager::Explosion *v3; // rsi
  hkpWorld *v4; // rcx
  hkVector4f *v5; // r13
  float v6; // xmm0_4
  __int64 v7; // rax
  __m128 v8; // xmm10
  unsigned int v9; // er14
  __int64 v10; // rax
  unsigned int v11; // er12
  __int64 v12; // rdi
  __int64 v13; // rcx
  __int64 v14; // rcx
  __int64 v15; // r15
  __int64 v16; // rbx
  unsigned int v17; // ecx
  char *v18; // rax
  int v19; // ecx
  int v20; // ecx
  __int64 v21; // r15
  __m128 v22; // xmm2
  __m128 v23; // xmm2
  __m128 v24; // xmm2
  __m128 v25; // xmm0
  float v26; // xmm6_4
  signed __int64 v27; // rbx
  float v28; // xmm7_4
  float v29; // xmm0_4
  bool v30; // cl
  __m128 v31; // xmm6
  __m128 v32; // xmm4
  __m128 v33; // xmm4
  __m128 v34; // xmm0
  __m128 v35; // xmm3
  __m128 v36; // xmm6
  __m128 v37; // xmm4
  __m128 v38; // xmm4
  __m128 v39; // xmm5
  __m128 v40; // xmm1
  __m128 v41; // xmm0
  __m128 v42; // xmm3
  __int64 v43; // rdx
  UFG::CollisionMeshData *v44; // rbx
  __int64 v45; // rcx
  char v46; // dl
  signed __int64 v47; // rax
  int v48; // er15
  hkpWorld *v49; // r13
  signed __int64 v50; // rbx
  UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject> *v51; // rcx
  const char *v52; // rax
  __int64 v53; // r8
  __m128 v54; // xmm6
  __m128 v55; // xmm3
  __m128 v56; // xmm3
  __m128 v57; // xmm5
  __m128 v58; // xmm1
  hkpRigidBody **v59; // rbx
  hkpShape *v60; // rcx
  __m128 v61; // xmm8
  __m128 v62; // xmm0
  __m128 v63; // xmm7
  __m128 v64; // xmm0
  __m128 v65; // xmm6
  __m128 v66; // xmm0
  hkpEntity *v67; // rbx
  __int64 v68; // rdx
  __int64 v69; // rdi
  hkpRigidBody **v70; // r15
  int v71; // er14
  int v72; // er9
  hkpEntity **v73; // rax
  hkpEntity **v74; // rdx
  signed __int64 v75; // r15
  signed __int64 v76; // rcx
  float v77; // xmm7_4
  UFG::SimObjectCVBase *v78; // rdi
  hkpRigidBody *v79; // r13
  __m128 *v80; // rax
  __m128 v81; // xmm2
  UFG::SimComponent *v82; // r12
  UFG::PhysicsMoverInterface *v83; // r15
  unsigned __int16 v84; // cx
  UFG::SimComponent *v85; // rax
  unsigned __int16 v86; // cx
  UFG::SimComponent *v87; // rbx
  UFG::SimComponent *v88; // rax
  unsigned __int16 v89; // cx
  UFG::SimComponent *v90; // rax
  unsigned __int16 v91; // cx
  UFG::CharacterOccupantComponent *v92; // rax
  UFG::SimObjectVehicle *v93; // rax
  __m128 *v94; // rbx
  UFG::PhysicsVehicle *v95; // rax
  __m128 v96; // xmm2
  hkpMotion *v97; // rbx
  __m128 v98; // xmm2
  __m128 v99; // xmm2
  __m128 v100; // xmm0
  float v101; // xmm6_4
  float v102; // xmm0_4
  __m128 v103; // xmm6
  __m128 v104; // xmm4
  __m128 v105; // xmm4
  __m128 v106; // xmm5
  __m128 v107; // xmm0
  __m128 v108; // xmm2
  __m128 v109; // xmm0
  __m128 v110; // xmm1
  __m128 v111; // xmm5
  hkpEntity *v112; // rax
  hkpEntity *v113; // rbx
  __int64 v114; // rdx
  char v115; // bl
  char v116; // cl
  __int64 v117; // rdx
  char v118; // cl
  float v119; // xmm10_4
  unsigned __int16 v120; // cx
  UFG::SimComponent *v121; // rax
  char v122; // al
  unsigned __int16 v123; // cx
  UFG::CharacterAnimationComponent *v124; // rax
  unsigned __int16 v125; // cx
  UFG::HitReactionComponent *v126; // rbx
  UFG::SimComponent *v127; // rax
  float v128; // xmm6_4
  unsigned __int16 v129; // cx
  UFG::SimComponent *v130; // rax
  int v131; // edi
  float v132; // xmm5_4
  float v133; // xmm2_4
  float v134; // xmm6_4
  float v135; // xmm3_4
  float v136; // xmm4_4
  float v137; // xmm8_4
  int v138; // eax
  __m128 v139; // xmm4
  float v140; // xmm3_4
  UFG::SimObject *v141; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v142; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v143; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v144; // rax
  UFG::StateMachineComponent *v145; // rcx
  bool v146; // bl
  __int64 maxImpulse; // [rsp+20h] [rbp-E0h]
  hkVector4f *normal; // [rsp+28h] [rbp-D8h]
  hkVector4f *position; // [rsp+30h] [rbp-D0h]
  hkArray<unsigned int,hkContainerHeapAllocator> *keysBrokenOffOut; // [rsp+38h] [rbp-C8h]
  hkpPhysicsSystem *bodiesOut; // [rsp+40h] [rbp-C0h]
  hkVector4f pos; // [rsp+50h] [rbp-B0h]
  hkArray<unsigned int,hkContainerHeapAllocator> v154; // [rsp+60h] [rbp-A0h]
  __m128 v155; // [rsp+70h] [rbp-90h]
  __int64 v156; // [rsp+80h] [rbp-80h]
  UFG::Destruction *v157; // [rsp+88h] [rbp-78h]
  __m128 v158; // [rsp+90h] [rbp-70h]
  __m128 v159; // [rsp+A0h] [rbp-60h]
  UFG::HitRecord hitrecord; // [rsp+B0h] [rbp-50h]
  UFG::qReflectHandleBase v161; // [rsp+1E0h] [rbp+E0h]
  hkVector4f v162; // [rsp+210h] [rbp+110h]
  __int64 v163; // [rsp+220h] [rbp+120h]
  hkVector4f v164; // [rsp+230h] [rbp+130h]
  hkpPhysicsSystem sys; // [rsp+240h] [rbp+140h]
  __m128 v166; // [rsp+2B0h] [rbp+1B0h]
  __m128 v167; // [rsp+2C0h] [rbp+1C0h]
  __m128 v168; // [rsp+2D0h] [rbp+1D0h]
  __m128 v169; // [rsp+2E0h] [rbp+1E0h]
  __m128 v170; // [rsp+2F0h] [rbp+1F0h]
  __int128 v171; // [rsp+300h] [rbp+200h]
  hkpCdBodyPairCollector collector; // [rsp+310h] [rbp+210h]
  char *v173; // [rsp+320h] [rbp+220h]
  int v174; // [rsp+328h] [rbp+228h]
  int v175; // [rsp+32Ch] [rbp+22Ch]
  char v176; // [rsp+330h] [rbp+230h]
  char *array; // [rsp+530h] [rbp+430h]
  unsigned int v178; // [rsp+538h] [rbp+438h]
  int v179; // [rsp+53Ch] [rbp+43Ch]
  char v180; // [rsp+540h] [rbp+440h]
  hkpEntity **entityBatch; // [rsp+940h] [rbp+840h]
  int v182; // [rsp+948h] [rbp+848h]
  int v183; // [rsp+94Ch] [rbp+84Ch]
  char v184; // [rsp+950h] [rbp+850h]
  char *v185; // [rsp+D50h] [rbp+C50h]
  int v186; // [rsp+D58h] [rbp+C58h]
  int v187; // [rsp+D5Ch] [rbp+C5Ch]
  char v188; // [rsp+D60h] [rbp+C60h]
  char *v189; // [rsp+1160h] [rbp+1060h]
  int v190; // [rsp+1168h] [rbp+1068h]
  int v191; // [rsp+116Ch] [rbp+106Ch]
  char v192; // [rsp+1170h] [rbp+1070h]
  __int64 *adjustedMagnitude; // [rsp+1A60h] [rbp+1960h]
  float v194; // [rsp+1A68h] [rbp+1968h]
  hkResult result; // [rsp+1A70h] [rbp+1970h]
  float ratio; // [rsp+1A78h] [rbp+1978h]

  v163 = -2i64;
  v2 = deltaT;
  v3 = this;
  v4 = UFG::BasePhysicsSystem::mInstance->mWorld;
  collector.vfptr = (hkpCdBodyPairCollectorVtbl *)&hkpAllCdBodyPairCollector::`vftable;
  adjustedMagnitude = (__int64 *)&v173;
  v173 = &v176;
  v175 = -2147483632;
  v174 = 0;
  collector.m_earlyOut.m_bool = 0;
  hkpWorld::getPenetrations(v4, v3->mCollidable, (hkpCollisionInput *)&v4->m_collisionInput->m_dispatcher, &collector);
  v5 = &v3->mTransform.m_translation;
  UFG::ExplosionManager::mClosestPointsCollidable->m_motion = &v3->mTransform;
  v6 = v3->mTimeRemaining - deltaT;
  v3->mTimeRemaining = v6;
  if ( v6 < 0.0 )
    v2 = deltaT - (float)(v6 * -1.0);
  array = &v180;
  v178 = 0;
  v179 = -2147483520;
  v185 = &v188;
  v186 = 0;
  v187 = -2147483520;
  v189 = &v192;
  v190 = 0;
  v191 = -2147483520;
  v157 = UFG::Destruction::mInstance;
  v194 = 0.0;
  v7 = 0i64;
  v156 = 0i64;
  v155.m128_u64[0] = v174;
  v8 = (__m128)(unsigned int)FLOAT_1_0;
  v9 = 0;
  while ( v7 < (signed __int64)v155.m128_u64[0] )
  {
    v10 = (__int64)&v173[32 * v7];
    v11 = *(_DWORD *)(v10 + 8);
    if ( *(_BYTE *)(*(_QWORD *)v10 + 40i64) == 1 )
      v12 = *(_QWORD *)v10 + *(char *)(*(_QWORD *)v10 + 32i64);
    else
      v12 = 0i64;
    if ( !v12 )
    {
      v11 = *(_DWORD *)(v10 + 24);
      v13 = *(_QWORD *)(v10 + 16);
      v12 = *(_BYTE *)(v13 + 40) == 1 ? v13 + *(char *)(v13 + 32) : 0i64;
      if ( !v12 )
        goto LABEL_85;
    }
    if ( *(_BYTE *)(v12 + 352) == 5 && (*(_BYTE *)(v12 + 76) & 0x1F) == 9 )
    {
      v14 = *(_QWORD *)(v12 + 32);
      if ( *(_BYTE *)(v14 + 16) == (*(_BYTE *)(v12 + 76) & 0x1F) && *(_BYTE *)(*(_QWORD *)(v14 + 88) + 16i64) == 13 )
        goto LABEL_85;
    }
    v15 = *(_QWORD *)(v12 + 24);
    if ( !v15 )
      goto LABEL_85;
    v16 = *(_QWORD *)(v15 + 24);
    if ( v16 )
      v16 = *(_QWORD *)(v16 + 40);
    if ( !v16 )
      goto LABEL_85;
    UFG::ExplosionManager::Explosion::FindClosestPointToExplosion(v3, (hkpRigidBody *)v12, &pos);
    if ( !(unsigned __int8)UFG::ExplosionManager::Explosion::IsBlockedByGeometry(v3, (hkpRigidBody *)v12, v5, &pos) )
    {
      v17 = 0;
      v9 = v178;
      if ( v178 )
      {
        v18 = array;
        while ( *(_QWORD *)v18 != v16 )
        {
          ++v17;
          v18 += 8;
          if ( v17 >= v178 )
            goto LABEL_25;
        }
      }
      else
      {
LABEL_25:
        if ( v178 < 0x80 )
        {
          if ( v178 == (v179 & 0x3FFFFFFF) )
          {
            hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, 8);
            v9 = v178;
          }
          *(_QWORD *)&array[8 * v9] = v16;
          ++v178;
          v19 = v186;
          if ( v186 == (v187 & 0x3FFFFFFF) )
          {
            hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v185, 8);
            v19 = v186;
          }
          *(_QWORD *)&v185[8 * v19] = v12;
          ++v186;
          v20 = v190;
          if ( v190 == (v191 & 0x3FFFFFFF) )
          {
            hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v189, 16);
            v20 = v190;
          }
          *(hkVector4f *)&v189[16 * v20] = (hkVector4f)pos.m_quad;
          ++v190;
          v9 = v178;
        }
      }
      v21 = *(_QWORD *)(v15 + 24);
      if ( !v21 )
        goto LABEL_85;
      if ( UFG::SimComponent::IsType((UFG::SimComponent *)v21, UFG::RagdollComponent::_RagdollComponentTypeUID) )
      {
        v22 = _mm_sub_ps(pos.m_quad, v5->m_quad);
        v23 = _mm_mul_ps(v22, v22);
        v24 = _mm_add_ps(
                _mm_shuffle_ps(v23, v23, 170),
                _mm_add_ps(_mm_shuffle_ps(v23, v23, 85), _mm_shuffle_ps(v23, v23, 0)));
        v25 = _mm_rsqrt_ps(v24);
        LODWORD(v26) = (unsigned __int128)_mm_andnot_ps(
                                            _mm_cmpleps(v24, (__m128)0i64),
                                            _mm_mul_ps(
                                              v24,
                                              _mm_mul_ps(
                                                _mm_mul_ps(*(__m128 *)_xmm, v25),
                                                _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v25, v24), v25)))));
        v27 = v12 + 336;
        v25.m128_f32[0] = hkpMotion::getMass((hkpMotion *)(v12 + 336));
        v28 = UFG::ExplosionTypeInfo::GetExplosionMagnitude(v3->mExplosionInfo, v25.m128_f32[0], v26, &ratio);
        v29 = hkpMotion::getMass((hkpMotion *)(v12 + 336));
        if ( v29 <= 0.0 )
        {
          v28 = 0.0;
        }
        else if ( (float)(v28 / v29) > 20.0 )
        {
          v28 = v28 * (float)((float)(v29 * 20.0) / v28);
        }
        v30 = v3->mUseForce;
        if ( v30 )
          v28 = (float)(v28 / v3->mExplosionInfo->mExplosionDuration) * v2;
        v31 = _mm_sub_ps(pos.m_quad, v5->m_quad);
        v32 = _mm_mul_ps(v31, v31);
        v33 = _mm_add_ps(
                _mm_shuffle_ps(v32, v32, 170),
                _mm_add_ps(_mm_shuffle_ps(v32, v32, 85), _mm_shuffle_ps(v32, v32, 0)));
        v34 = _mm_rsqrt_ps(v33);
        v35 = _mm_andnot_ps(
                _mm_cmpleps(v33, (__m128)0i64),
                _mm_mul_ps(
                  v33,
                  _mm_mul_ps(
                    _mm_mul_ps(*(__m128 *)_xmm, v34),
                    _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v34, v33), v34)))));
        v35.m128_f32[0] = v35.m128_f32[0] * 0.5;
        v36 = _mm_add_ps(v31, _mm_unpacklo_ps(_mm_unpacklo_ps((__m128)0i64, v35), (__m128)0i64));
        v37 = _mm_mul_ps(v36, v36);
        v38 = _mm_add_ps(
                _mm_shuffle_ps(v37, v37, 170),
                _mm_add_ps(_mm_shuffle_ps(v37, v37, 85), _mm_shuffle_ps(v37, v37, 0)));
        v39 = _mm_cmpltps(_mm_sub_ps((__m128)0i64, v38), (__m128)0i64);
        v40 = _mm_rsqrt_ps(v38);
        v41 = _mm_mul_ps(_mm_mul_ps(v40, v38), v40);
        v42 = _mm_mul_ps(
                _mm_andnot_ps(
                  _mm_cmpleps(v38, (__m128)0i64),
                  _mm_mul_ps(_mm_mul_ps(v40, *(__m128 *)_xmm), _mm_sub_ps((__m128)_xmm, v41))),
                v36);
        v41.m128_f32[0] = v28;
        v158 = _mm_mul_ps(_mm_or_ps(_mm_andnot_ps(v39, v36), _mm_and_ps(v39, v42)), _mm_shuffle_ps(v41, v41, 0));
        if ( v30 )
        {
          hkpEntity::activate((hkpEntity *)v12);
          (*(void (__fastcall **)(__int64, __int64, __m128 *, hkVector4f *, __int64, hkVector4f *, hkVector4f *, hkArray<unsigned int,hkContainerHeapAllocator> *, hkpPhysicsSystem *))(*(_QWORD *)v27 + 200i64))(
            v12 + 336,
            v43,
            &v158,
            &pos,
            maxImpulse,
            normal,
            position,
            keysBrokenOffOut,
            bodiesOut);
        }
        else
        {
          hkpEntity::activate((hkpEntity *)v12);
          (*(void (__fastcall **)(__int64, __m128 *, hkVector4f *))(*(_QWORD *)v27 + 184i64))(v12 + 336, &v158, &pos);
        }
        v8 = (__m128)(unsigned int)FLOAT_1_0;
      }
      if ( UFG::SimComponent::IsType((UFG::SimComponent *)v21, UFG::RigidBodyComponent::_RigidBodyComponentTypeUID) )
      {
        v44 = *(UFG::CollisionMeshData **)(v21 + 160);
        if ( v44 )
        {
          if ( v11 != -1 )
          {
            v45 = *(_QWORD *)(v12 + 32);
            v46 = *(_BYTE *)(v45 + 16);
            if ( v46 == 9 )
            {
              v45 = *(_QWORD *)(v45 + 88);
LABEL_51:
              if ( v45 )
              {
                if ( *(_BYTE *)(v45 + 16) == 8 )
                {
                  v47 = UFG::CollisionMeshData::GetPartDetails(*(UFG::CollisionMeshData **)(v21 + 160), v11);
                  if ( v47 )
                  {
                    if ( *(float *)(v47 + 68) > 0.0 )
                    {
                      v48 = LODWORD(v194);
                      if ( SLODWORD(v194) < 15 )
                      {
                        v154.m_data = 0i64;
                        v154.m_size = 0;
                        v154.m_capacityAndFlags = 2147483648;
                        hkpPhysicsSystem::hkpPhysicsSystem(&sys);
                        v49 = *(hkpWorld **)(v12 + 16);
                        v50 = UFG::CollisionMeshData::GetPart(v44, v11);
                        UFG::qReflectHandleBase::qReflectHandleBase(&v161);
                        v52 = UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject>::GetTypeName(v51);
                        v161.mTypeUID = UFG::qStringHash64(v52, 0xFFFFFFFFFFFFFFFFui64);
                        UFG::qReflectHandleBase::Init(&v161, v161.mTypeUID, *(_QWORD *)(v50 + 16));
                        if ( v161.mData && BYTE4(v161.mData[1].mHandles.mNode.mNext) )
                        {
                          v164.m_quad = *(__m128 *)(v12 + 448);
                          v162.m_quad = (__m128)_xmm;
                          bodiesOut = &sys;
                          keysBrokenOffOut = &v154;
                          position = &v164;
                          normal = &v162;
                          LODWORD(maxImpulse) = 0;
                          UFG::Destruction::breakOffSubPart(v157, 0i64, (hkpRigidBody *)v12, v11);
                          LODWORD(v194) = v48 + 1;
                        }
                        hkpWorld::addPhysicsSystem(v49, &sys);
                        if ( sys.m_rigidBodies.m_size > 0 && *sys.m_rigidBodies.m_data )
                        {
                          UFG::ExplosionManager::Explosion::ComputeExplosionMagnitudeAndRatio(
                            v3,
                            &pos,
                            &v3->mTransform.m_translation,
                            *sys.m_rigidBodies.m_data,
                            v2,
                            (float *)&adjustedMagnitude,
                            &ratio);
                          v54 = _mm_sub_ps(pos.m_quad, v3->mTransform.m_translation.m_quad);
                          v55 = _mm_mul_ps(v54, v54);
                          v56 = _mm_add_ps(
                                  _mm_shuffle_ps(v55, v55, 170),
                                  _mm_add_ps(_mm_shuffle_ps(v55, v55, 85), _mm_shuffle_ps(v55, v55, 0)));
                          v57 = _mm_cmpltps(_mm_sub_ps((__m128)0i64, v56), (__m128)0i64);
                          v58 = _mm_rsqrt_ps(v56);
                          v159 = _mm_mul_ps(
                                   _mm_or_ps(
                                     _mm_andnot_ps(v57, v54),
                                     _mm_and_ps(
                                       _mm_mul_ps(
                                         _mm_andnot_ps(
                                           _mm_cmpleps(v56, (__m128)0i64),
                                           _mm_mul_ps(
                                             _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v58, v56), v58)),
                                             _mm_mul_ps(*(__m128 *)_xmm, v58))),
                                         v54),
                                       v57)),
                                   _mm_shuffle_ps(
                                     (__m128)(unsigned int)adjustedMagnitude,
                                     (__m128)(unsigned int)adjustedMagnitude,
                                     0));
                          v59 = sys.m_rigidBodies.m_data;
                          if ( *sys.m_rigidBodies.m_data != (hkpRigidBody *)-32i64 )
                          {
                            v60 = (*sys.m_rigidBodies.m_data)->m_collidable.m_shape;
                            if ( v60 )
                            {
                              v168 = transform.m_quad;
                              v169 = direction.m_quad;
                              v170 = stru_141A71280.m_quad;
                              v171 = 0i64;
                              ((void (__fastcall *)(hkpShape *, __m128 *, __int64, __m128 *))v60->vfptr[2].__vecDelDtor)(
                                v60,
                                &v168,
                                v53,
                                &v166);
                              v61 = _mm_sub_ps(v167, v166);
                              v62 = v8;
                              v62.m128_f32[0] = UFG::qRandom(v8.m128_f32[0], &UFG::qDefaultSeed);
                              v63 = v62;
                              v63.m128_f32[0] = v62.m128_f32[0] - 0.5;
                              v64 = v8;
                              v64.m128_f32[0] = UFG::qRandom(v8.m128_f32[0], &UFG::qDefaultSeed);
                              v65 = v64;
                              v65.m128_f32[0] = v64.m128_f32[0] - 0.5;
                              v66 = v8;
                              v66.m128_f32[0] = UFG::qRandom(v8.m128_f32[0], &UFG::qDefaultSeed) - 0.5;
                              pos.m_quad = _mm_add_ps(
                                             pos.m_quad,
                                             _mm_mul_ps(
                                               _mm_unpacklo_ps(
                                                 _mm_unpacklo_ps(v66, v63),
                                                 _mm_unpacklo_ps(v65, (__m128)0i64)),
                                               v61));
                              v59 = sys.m_rigidBodies.m_data;
                            }
                          }
                          v67 = (hkpEntity *)*v59;
                          if ( v3->mUseForce )
                          {
                            hkpEntity::activate(v67);
                            ((void (__fastcall *)(hkpMaxSizeMotion *, __int64, __m128 *, hkVector4f *))v67->m_motion.vfptr[12].__first_virtual_table_function__)(
                              &v67->m_motion,
                              v68,
                              &v159,
                              &pos);
                          }
                          else
                          {
                            hkpEntity::activate(v67);
                            ((void (__fastcall *)(hkpMaxSizeMotion *, __m128 *, hkVector4f *))v67->m_motion.vfptr[11].__first_virtual_table_function__)(
                              &v67->m_motion,
                              &v159,
                              &pos);
                          }
                        }
                        entityBatch = (hkpEntity **)&v184;
                        v183 = -2147483520;
                        *(_QWORD *)&v184 = v12;
                        v182 = 1;
                        v69 = sys.m_rigidBodies.m_size;
                        v70 = sys.m_rigidBodies.m_data;
                        v71 = sys.m_rigidBodies.m_size + 1;
                        if ( sys.m_rigidBodies.m_size + 1 > 128 )
                        {
                          if ( v71 <= 128 )
                          {
                            result.m_enum = 0;
                          }
                          else
                          {
                            v72 = sys.m_rigidBodies.m_size + 1;
                            if ( v71 < 256 )
                              v72 = 256;
                            hkArrayUtil::_reserve(
                              &result,
                              (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
                              &entityBatch,
                              v72,
                              8);
                          }
                        }
                        hkMemUtil::memMove(&entityBatch[v69 + 1], entityBatch + 1, 0);
                        v73 = entityBatch;
                        v74 = entityBatch + 1;
                        if ( v69 > 0 )
                        {
                          v75 = (char *)v70 - (char *)v74;
                          do
                          {
                            *v74 = *(hkpEntity **)((char *)v74 + v75);
                            ++v74;
                            --v69;
                          }
                          while ( v69 );
                          v73 = entityBatch;
                        }
                        v182 = v71;
                        if ( v71 )
                        {
                          hkpWorld::reintegrateAndRecollideEntities(v49, v73, v71, RR_MODE_RECOLLIDE_NARROWPHASE);
                          hkReferencedObject::lockAll();
                          hkpPhysicsSystem::removeAll(&sys);
                          hkReferencedObject::unlockAll();
                        }
                        v182 = 0;
                        if ( v183 >= 0 )
                          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
                            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                            entityBatch,
                            8 * v183);
                        entityBatch = 0i64;
                        v183 = 2147483648;
                        UFG::qReflectHandleBase::~qReflectHandleBase(&v161);
                        hkpPhysicsSystem::~hkpPhysicsSystem(&sys);
                        v154.m_size = 0;
                        if ( v154.m_capacityAndFlags >= 0 )
                          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
                            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                            v154.m_data,
                            4 * v154.m_capacityAndFlags);
                        v154.m_data = 0i64;
                        v154.m_capacityAndFlags = 2147483648;
                        v5 = &v3->mTransform.m_translation;
                      }
                    }
                  }
                }
              }
              goto LABEL_84;
            }
            if ( v46 == 8 )
              goto LABEL_51;
          }
        }
      }
    }
LABEL_84:
    v9 = v178;
LABEL_85:
    v7 = v156 + 1;
    v156 = v7;
  }
  result.m_enum = 0;
  v76 = 0i64;
  *(_QWORD *)&ratio = 0i64;
  if ( v9 )
  {
    v77 = v194;
    while ( 1 )
    {
      v78 = *(UFG::SimObjectCVBase **)&array[8 * v76];
      v79 = *(hkpRigidBody **)&v185[8 * v76];
      v80 = (__m128 *)&v189[16 * v76];
      v81 = *v80;
      pos.m_quad = *v80;
      LOBYTE(v194) = 0;
      if ( !v78 )
        break;
      v84 = v78->m_Flags;
      if ( (v84 >> 14) & 1 )
      {
        v85 = UFG::SimObjectGame::GetComponentOfTypeHK(
                (UFG::SimObjectGame *)&v78->vfptr,
                UFG::RigidBodyComponent::_TypeUID);
      }
      else if ( (v84 & 0x8000u) == 0 )
      {
        if ( (v84 >> 13) & 1 )
        {
          v85 = UFG::SimObjectGame::GetComponentOfTypeHK(
                  (UFG::SimObjectGame *)&v78->vfptr,
                  UFG::RigidBodyComponent::_TypeUID);
        }
        else if ( (v84 >> 12) & 1 )
        {
          v85 = UFG::SimObjectGame::GetComponentOfTypeHK(
                  (UFG::SimObjectGame *)&v78->vfptr,
                  UFG::RigidBodyComponent::_TypeUID);
        }
        else
        {
          v85 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v78->vfptr, UFG::RigidBodyComponent::_TypeUID);
        }
      }
      else
      {
        v85 = UFG::SimObjectGame::GetComponentOfTypeHK(
                (UFG::SimObjectGame *)&v78->vfptr,
                UFG::RigidBodyComponent::_TypeUID);
      }
      v82 = v85;
      v86 = v78->m_Flags;
      if ( (v86 >> 14) & 1 )
      {
        v87 = v78->m_Components.p[27].m_pComponent;
      }
      else
      {
        if ( (v86 & 0x8000u) == 0 )
        {
          if ( (v86 >> 13) & 1 )
          {
            v88 = UFG::SimObjectGame::GetComponentOfTypeHK(
                    (UFG::SimObjectGame *)&v78->vfptr,
                    UFG::CharacterPhysicsComponent::_TypeUID);
          }
          else if ( (v86 >> 12) & 1 )
          {
            v88 = UFG::SimObjectGame::GetComponentOfTypeHK(
                    (UFG::SimObjectGame *)&v78->vfptr,
                    UFG::CharacterPhysicsComponent::_TypeUID);
          }
          else
          {
            v88 = UFG::SimObject::GetComponentOfType(
                    (UFG::SimObject *)&v78->vfptr,
                    UFG::CharacterPhysicsComponent::_TypeUID);
          }
        }
        else
        {
          v88 = UFG::SimObjectGame::GetComponentOfTypeHK(
                  (UFG::SimObjectGame *)&v78->vfptr,
                  UFG::CharacterPhysicsComponent::_TypeUID);
        }
        v87 = v88;
      }
      v89 = v78->m_Flags;
      if ( (v89 >> 14) & 1 )
      {
        v83 = 0i64;
      }
      else if ( (v89 & 0x8000u) == 0 )
      {
        if ( (v89 >> 13) & 1 )
        {
          v83 = 0i64;
        }
        else
        {
          if ( (v89 >> 12) & 1 )
            v90 = UFG::SimObjectGame::GetComponentOfTypeHK(
                    (UFG::SimObjectGame *)&v78->vfptr,
                    UFG::PhysicsMoverInterface::_TypeUID);
          else
            v90 = UFG::SimObject::GetComponentOfType(
                    (UFG::SimObject *)&v78->vfptr,
                    UFG::PhysicsMoverInterface::_TypeUID);
          v83 = (UFG::PhysicsMoverInterface *)v90;
        }
      }
      else
      {
        v83 = (UFG::PhysicsMoverInterface *)v78->m_Components.p[34].m_pComponent;
      }
      v91 = v78->m_Flags;
      if ( (v91 >> 14) & 1 )
      {
        v92 = (UFG::CharacterOccupantComponent *)v78->m_Components.p[44].m_pComponent;
      }
      else if ( (v91 & 0x8000u) == 0 )
      {
        if ( (v91 >> 13) & 1 )
        {
          v92 = (UFG::CharacterOccupantComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                     (UFG::SimObjectGame *)&v78->vfptr,
                                                     UFG::CharacterOccupantComponent::_TypeUID);
        }
        else if ( (v91 >> 12) & 1 )
        {
          v92 = (UFG::CharacterOccupantComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                     (UFG::SimObjectGame *)&v78->vfptr,
                                                     UFG::CharacterOccupantComponent::_TypeUID);
        }
        else
        {
          v92 = (UFG::CharacterOccupantComponent *)UFG::SimObject::GetComponentOfType(
                                                     (UFG::SimObject *)&v78->vfptr,
                                                     UFG::CharacterOccupantComponent::_TypeUID);
        }
      }
      else
      {
        v92 = (UFG::CharacterOccupantComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                   (UFG::SimObjectGame *)&v78->vfptr,
                                                   UFG::CharacterOccupantComponent::_TypeUID);
      }
      if ( !v92
        || (v93 = (UFG::SimObjectVehicle *)UFG::CharacterOccupantComponent::GetCurrentVehicle(v92)) == 0i64
        || UFG::SimObjectVehicle::GetComponent<UFG::BikePhysicsMoverComponent>(v93) )
      {
        if ( !v87 )
        {
          v94 = &v3->mTransform.m_translation.m_quad;
LABEL_135:
          if ( v83 )
          {
            v95 = UFG::PhysicsMoverInterface::GetRigidBody(v83);
            if ( v95 )
            {
              v96 = _mm_sub_ps(pos.m_quad, *v94);
              v97 = (hkpMotion *)&v95->mVolumeOffset.v1;
              goto LABEL_140;
            }
LABEL_146:
            v103 = _mm_sub_ps(pos.m_quad, v3->mTransform.m_translation.m_quad);
            v104 = _mm_mul_ps(v103, v103);
            v105 = _mm_add_ps(
                     _mm_shuffle_ps(v104, v104, 170),
                     _mm_add_ps(_mm_shuffle_ps(v104, v104, 85), _mm_shuffle_ps(v104, v104, 0)));
            v106 = _mm_cmpltps(_mm_sub_ps((__m128)0i64, v105), (__m128)0i64);
            v107 = _mm_rsqrt_ps(v105);
            v108 = _mm_mul_ps(*(__m128 *)_xmm, v107);
            v109 = _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v107, v105), v107));
            v110 = _mm_andnot_ps(v106, v103);
            v111 = _mm_and_ps(
                     v106,
                     _mm_mul_ps(_mm_andnot_ps(_mm_cmpleps(v105, (__m128)0i64), _mm_mul_ps(v108, v109)), v103));
            v109.m128_f32[0] = v77;
            v154 = (hkArray<unsigned int,hkContainerHeapAllocator>)_mm_mul_ps(
                                                                     _mm_or_ps(v110, v111),
                                                                     _mm_shuffle_ps(v109, v109, 0));
            if ( v83 )
            {
              UFG::PhysicsMoverInterface::LockHighLod(v83, ELODLockMode_UNTIL_AT_REST, 0.0);
              LOBYTE(maxImpulse) = 1;
              UFG::PhysicsMoverInterface::DamageEngine(
                v83,
                v3->mAttacker.m_pPointer,
                *(float *)&adjustedMagnitude * 0.75,
                dtBULLET);
              v112 = (hkpEntity *)UFG::PhysicsMoverInterface::GetRigidBody(v83);
              v113 = v112;
              if ( v112 )
              {
                if ( v3->mUseForce )
                {
                  hkpEntity::activate(v112);
                  ((void (__fastcall *)(hkpMaxSizeMotion *, __int64, hkArray<unsigned int,hkContainerHeapAllocator> *, hkVector4f *, __int64, hkVector4f *, hkVector4f *, hkArray<unsigned int,hkContainerHeapAllocator> *, hkpPhysicsSystem *))v113->m_motion.vfptr[12].__first_virtual_table_function__)(
                    &v113->m_motion,
                    v114,
                    &v154,
                    &pos,
                    maxImpulse,
                    normal,
                    position,
                    keysBrokenOffOut,
                    bodiesOut);
                }
                else
                {
                  hkpEntity::activate(v112);
                  ((void (__fastcall *)(hkpMaxSizeMotion *, hkArray<unsigned int,hkContainerHeapAllocator> *, hkVector4f *))v113->m_motion.vfptr[11].__first_virtual_table_function__)(
                    &v113->m_motion,
                    &v154,
                    &pos);
                }
              }
            }
            v115 = LOBYTE(v194);
            if ( v79 )
            {
              v116 = v79->m_motion.m_type.m_storage;
              if ( v116 != 5 && v116 != 4 && !LOBYTE(v194) )
              {
                if ( v3->mUseForce == (v116 == 4) )
                {
                  hkpEntity::activate((hkpEntity *)&v79->vfptr);
                  ((void (__fastcall *)(hkpMaxSizeMotion *, hkArray<unsigned int,hkContainerHeapAllocator> *, hkVector4f *))v79->m_motion.vfptr[11].__first_virtual_table_function__)(
                    &v79->m_motion,
                    &v154,
                    &pos);
                }
                else
                {
                  hkpEntity::activate((hkpEntity *)&v79->vfptr);
                  ((void (__fastcall *)(hkpMaxSizeMotion *, __int64, hkArray<unsigned int,hkContainerHeapAllocator> *, hkVector4f *, __int64, hkVector4f *, hkVector4f *, hkArray<unsigned int,hkContainerHeapAllocator> *, hkpPhysicsSystem *))v79->m_motion.vfptr[12].__first_virtual_table_function__)(
                    &v79->m_motion,
                    v117,
                    &v154,
                    &pos,
                    maxImpulse,
                    normal,
                    position,
                    keysBrokenOffOut,
                    bodiesOut);
                }
              }
            }
            v118 = *((_BYTE *)v3->mExplosionInfo + 188) & 1;
            if ( v118 )
              v119 = 0.0;
            else
              v119 = *(float *)&adjustedMagnitude;
            if ( !v115
              || v118
              || (!v78
               || ((v120 = v78->m_Flags, !((v120 >> 14) & 1)) ? ((v120 & 0x8000u) == 0 ? (!((v120 >> 13) & 1) ? (!((v120 >> 12) & 1) ? (v121 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v78->vfptr, UFG::CharacterEffectsComponent::_TypeUID)) : (v121 = UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&v78->vfptr, UFG::CharacterEffectsComponent::_TypeUID))) : (v121 = UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&v78->vfptr, UFG::CharacterEffectsComponent::_TypeUID))) : (v121 = UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&v78->vfptr, UFG::CharacterEffectsComponent::_TypeUID))) : (v121 = v78->m_Components.p[38].m_pComponent),
                   !v121 || !LOBYTE(v121[1].m_SafePointerList.mNode.mNext)) ? (v122 = 1) : (v122 = 0),
                  v119 <= 0.1 || v122 != 1) )
            {
LABEL_191:
              if ( v78 )
              {
                v125 = v78->m_Flags;
                if ( (v125 >> 14) & 1 )
                {
                  v126 = (UFG::HitReactionComponent *)v78->m_Components.p[15].m_pComponent;
                }
                else if ( (v125 & 0x8000u) == 0 )
                {
                  if ( (v125 >> 13) & 1 )
                    v127 = UFG::SimObjectGame::GetComponentOfTypeHK(
                             (UFG::SimObjectGame *)&v78->vfptr,
                             UFG::HitReactionComponent::_TypeUID);
                  else
                    v127 = (v125 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                (UFG::SimObjectGame *)&v78->vfptr,
                                                UFG::HitReactionComponent::_TypeUID) : UFG::SimObject::GetComponentOfType(
                                                                                         (UFG::SimObject *)&v78->vfptr,
                                                                                         UFG::HitReactionComponent::_TypeUID);
                  v126 = (UFG::HitReactionComponent *)v127;
                }
                else
                {
                  v126 = (UFG::HitReactionComponent *)v78->m_Components.p[15].m_pComponent;
                }
                if ( v126 )
                {
                  v128 = FLOAT_100_0;
                  v129 = v78->m_Flags;
                  if ( (v129 >> 14) & 1 )
                  {
                    v130 = v78->m_Components.p[6].m_pComponent;
                  }
                  else if ( (v129 & 0x8000u) == 0 )
                  {
                    if ( (v129 >> 13) & 1 )
                    {
                      v130 = UFG::SimObjectGame::GetComponentOfTypeHK(
                               (UFG::SimObjectGame *)&v78->vfptr,
                               UFG::HealthComponent::_TypeUID);
                    }
                    else if ( (v129 >> 12) & 1 )
                    {
                      v130 = UFG::SimObjectGame::GetComponentOfTypeHK(
                               (UFG::SimObjectGame *)&v78->vfptr,
                               UFG::HealthComponent::_TypeUID);
                    }
                    else
                    {
                      v130 = UFG::SimObject::GetComponentOfType(
                               (UFG::SimObject *)&v78->vfptr,
                               UFG::HealthComponent::_TypeUID);
                    }
                  }
                  else
                  {
                    v130 = v78->m_Components.p[6].m_pComponent;
                  }
                  if ( v130 )
                    v128 = (float)(signed int)*(float *)&v130[1].m_NameUID;
                  v131 = (signed int)(float)(v128 * v119);
                  UFG::HitRecord::HitRecord(&hitrecord);
                  v155 = _mm_sub_ps(pos.m_quad, v3->mTransform.m_translation.m_quad);
                  v132 = v155.m128_f32[2];
                  v133 = v155.m128_f32[1];
                  v134 = v155.m128_f32[0];
                  if ( *((_BYTE *)v3->mExplosionInfo + 188) & 1 || *(float *)&adjustedMagnitude < 0.00000011920929 )
                  {
                    v139 = (__m128)v155.m128_u32[1];
                    v139.m128_f32[0] = (float)((float)(v155.m128_f32[1] * v155.m128_f32[1])
                                             + (float)(v155.m128_f32[0] * v155.m128_f32[0]))
                                     + (float)(v155.m128_f32[2] * v155.m128_f32[2]);
                    if ( v139.m128_f32[0] == 0.0 )
                      v140 = 0.0;
                    else
                      v140 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v139));
                    v137 = v140 * v155.m128_f32[2];
                    v136 = v140 * v155.m128_f32[1];
                    v135 = v140 * v155.m128_f32[0];
                    v138 = gAttackCollisionExplosionNoDamage.m_EnumValue;
                  }
                  else
                  {
                    v136 = *((float *)&v154.m_data + 1);
                    v135 = *(float *)&v154.m_data;
                    v137 = *(float *)&v154.m_size;
                    v138 = gAttackCollisionExplosion.m_EnumValue;
                  }
                  hitrecord.mDamage = v131;
                  hitrecord.mAttackTypeID = v138;
                  v141 = v3->mAttacker.m_pPointer;
                  if ( hitrecord.mAttacker.m_pPointer )
                  {
                    v142 = hitrecord.mAttacker.mPrev;
                    v143 = hitrecord.mAttacker.mNext;
                    hitrecord.mAttacker.mPrev->mNext = hitrecord.mAttacker.mNext;
                    v143->mPrev = v142;
                    hitrecord.mAttacker.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&hitrecord.mAttacker.mPrev;
                    hitrecord.mAttacker.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&hitrecord.mAttacker.mPrev;
                  }
                  hitrecord.mAttacker.m_pPointer = v141;
                  if ( v141 )
                  {
                    v144 = v141->m_SafePointerList.mNode.mPrev;
                    v144->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&hitrecord.mAttacker.mPrev;
                    hitrecord.mAttacker.mPrev = v144;
                    hitrecord.mAttacker.mNext = &v141->m_SafePointerList.mNode;
                    v141->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&hitrecord.mAttacker.mPrev;
                  }
                  *(_QWORD *)&hitrecord.mTimeSinceHit = 0i64;
                  hitrecord.mDistanceFromExplosionSquared = (float)((float)(v133 * v133) + (float)(v134 * v134))
                                                          + (float)(v132 * v132);
                  hitrecord.mExplosionInfo = v3->mExplosionInfo;
                  hitrecord.mCollisionInfo.mPhysicsObjectPropertyHandleUID = 0i64;
                  hitrecord.mCollisionInfo.mAttackerPhysicsObjectPropertyHandleUID = 0i64;
                  hitrecord.mCollisionInfo.mSurfacePropertyHandleUID = 0i64;
                  hitrecord.mCollisionInfo.mAttackerSurfacePropertyHandleUID = 0i64;
                  hitrecord.mCollisionInfo.mHitLocation = UFG::qVector3::msZero;
                  hitrecord.mCollisionInfo.mHitImpulse.x = v135;
                  hitrecord.mCollisionInfo.mHitImpulse.y = v136;
                  hitrecord.mCollisionInfo.mHitImpulse.z = v137;
                  hitrecord.mCollisionInfo.mOtherVelocity = UFG::qVector3::msZero;
                  hitrecord.mCollisionInfo.mSpeed = v77;
                  hitrecord.mCollisionInfo.mForwardSpeed = v77;
                  hitrecord.mCollisionInfo.mEstimatedImpulseMagnitude = -1.0;
                  UFG::HitReactionComponent::HandleHitReaction(v126, &hitrecord);
                  UFG::HitRecord::~HitRecord(&hitrecord);
                }
              }
            }
            else if ( v78 )
            {
              v123 = v78->m_Flags;
              if ( (v123 >> 14) & 1 )
              {
                v124 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v78);
              }
              else if ( (v123 & 0x8000u) == 0 )
              {
                if ( (v123 >> 13) & 1 )
                {
                  v124 = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectProp *)v78);
                }
                else if ( (v123 >> 12) & 1 )
                {
                  v124 = (UFG::CharacterAnimationComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                               (UFG::SimObjectGame *)&v78->vfptr,
                                                               UFG::CharacterAnimationComponent::_TypeUID);
                }
                else
                {
                  v124 = (UFG::CharacterAnimationComponent *)UFG::SimObject::GetComponentOfType(
                                                               (UFG::SimObject *)&v78->vfptr,
                                                               UFG::CharacterAnimationComponent::_TypeUID);
                }
              }
              else
              {
                v124 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v78);
              }
              if ( v124 )
                UFG::CharacterAnimationComponent::ApplyCharredEffect(v124, v119 + 0.15);
              goto LABEL_191;
            }
            if ( v82 )
            {
              v145 = (UFG::StateMachineComponent *)v82[6].vfptr;
              if ( v145 )
                UFG::StateMachineComponent::ApplyDamage(v145, v119, EXPLOSION_DAMAGE, v3->mAttacker.m_pPointer);
            }
            goto LABEL_229;
          }
          v81 = pos.m_quad;
LABEL_139:
          v96 = _mm_sub_ps(v81, v3->mTransform.m_translation.m_quad);
          v97 = (hkpMotion *)&v79->m_motion.vfptr;
LABEL_140:
          v98 = _mm_mul_ps(v96, v96);
          v99 = _mm_add_ps(
                  _mm_shuffle_ps(v98, v98, 170),
                  _mm_add_ps(_mm_shuffle_ps(v98, v98, 85), _mm_shuffle_ps(v98, v98, 0)));
          v100 = _mm_rsqrt_ps(v99);
          LODWORD(v101) = (unsigned __int128)_mm_andnot_ps(
                                               _mm_cmpleps(v99, (__m128)0i64),
                                               _mm_mul_ps(
                                                 v99,
                                                 _mm_mul_ps(
                                                   _mm_mul_ps(*(__m128 *)_xmm, v100),
                                                   _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v100, v99), v100)))));
          v100.m128_f32[0] = hkpMotion::getMass(v97);
          v77 = UFG::ExplosionTypeInfo::GetExplosionMagnitude(
                  v3->mExplosionInfo,
                  v100.m128_f32[0],
                  v101,
                  (float *)&adjustedMagnitude);
          v102 = hkpMotion::getMass(v97);
          if ( v102 <= 0.0 )
          {
            v77 = 0.0;
          }
          else if ( (float)(v77 / v102) > 20.0 )
          {
            v77 = v77 * (float)((float)(v102 * 20.0) / v77);
          }
          if ( v3->mUseForce )
            v77 = (float)(v77 / v3->mExplosionInfo->mExplosionDuration) * v2;
          goto LABEL_146;
        }
        LOBYTE(v194) = 1;
        v79 = (hkpRigidBody *)v87[6].m_BoundComponentHandles.mNode.mPrev[2].mPrev;
        pos.m_quad = (__m128)v79->m_motion.m_motionState.m_sweptTransform.m_centerOfMass1;
        v94 = &v3->mTransform.m_translation.m_quad;
        if ( !(unsigned __int8)UFG::ExplosionManager::Explosion::IsBlockedByGeometry(
                                 v3,
                                 v79,
                                 &v3->mTransform.m_translation,
                                 &pos) )
          goto LABEL_135;
      }
LABEL_229:
      ++result.m_enum;
      v76 = (*(_QWORD *)&ratio)++ + 1i64;
      if ( result.m_enum >= v9 )
        goto LABEL_230;
    }
    v82 = 0i64;
    v83 = 0i64;
    goto LABEL_139;
  }
LABEL_230:
  v146 = v3->mTimeRemaining <= 0.0;
  v190 = 0;
  if ( v191 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v189,
      16 * v191);
  v189 = 0i64;
  v191 = 2147483648;
  v186 = 0;
  if ( v187 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v185,
      8 * v187);
  v185 = 0i64;
  v187 = 2147483648;
  v178 = 0;
  if ( v179 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      array,
      8 * v179);
  array = 0i64;
  v179 = 2147483648;
  hkpAllCdBodyPairCollector::~hkpAllCdBodyPairCollector((hkpAllCdBodyPairCollector *)&collector);
  return v146;
}

// File Line: 1003
// RVA: 0x4645A0
void __fastcall UFG::ExplosionManager::Explosion::FindClosestPointToExplosion(UFG::ExplosionManager::Explosion *this, hkpRigidBody *body, hkVector4f *pos)
{
  hkVector4f *v3; // rdi
  hkpRigidBody *v4; // rbx
  char v5; // cl
  hkpWorld *v6; // r10
  hkpProcessCollisionInput *v7; // rcx
  void **v8; // [rsp+18h] [rbp-79h]
  int v9; // [rsp+20h] [rbp-71h]
  hkVector4f v10; // [rsp+28h] [rbp-69h]
  __m128 v11; // [rsp+38h] [rbp-59h]
  __int64 v12; // [rsp+48h] [rbp-49h]
  __int64 v13; // [rsp+78h] [rbp-19h]
  hkpCollisionDispatcher *v14; // [rsp+88h] [rbp-9h]
  unsigned int v15; // [rsp+90h] [rbp-1h]
  unsigned int v16; // [rsp+94h] [rbp+3h]
  float v17; // [rsp+98h] [rbp+7h]
  hkpCollisionFilter *v18; // [rsp+A0h] [rbp+Fh]
  hkpConvexListFilter *v19; // [rsp+A8h] [rbp+17h]
  unsigned int v20; // [rsp+B0h] [rbp+1Fh]
  hkVector4f v21; // [rsp+B8h] [rbp+27h]
  hkVector4f v22; // [rsp+C8h] [rbp+37h]
  hkVector4f v23; // [rsp+D8h] [rbp+47h]

  v13 = -2i64;
  v3 = pos;
  v4 = body;
  v5 = body->m_motion.m_type.m_storage;
  if ( v5 != 5 && v5 != 4 )
  {
    v6 = body->m_world;
    v7 = v6->m_collisionInput;
    v14 = v7->m_dispatcher.m_storage;
    v15 = v7->m_weldClosestPoints.m_storage;
    v16 = v7->m_forceAcceptContactPoints.m_storage;
    v17 = v7->m_tolerance.m_storage;
    v18 = v7->m_filter.m_storage;
    v19 = v7->m_convexListFilter.m_storage;
    v20 = v7->m_createPredictiveAgents.m_storage;
    v21.m_quad = (__m128)v7->m_aabb32Info.m_bitOffsetLow;
    v22.m_quad = (__m128)v7->m_aabb32Info.m_bitOffsetHigh;
    v23.m_quad = (__m128)v7->m_aabb32Info.m_bitScale;
    v17 = FLOAT_10_0;
    v8 = &hkpClosestCdPointCollector::`vftable;
    v12 = 0i64;
    v11 = _mm_shuffle_ps(v11, _mm_unpackhi_ps(v11, (__m128)xmmword_141A712A0), 196);
    v9 = 2139095022;
    (*((void (__fastcall **)(hkpCollidable *, hkpLinkedCollidable *, hkpCollisionDispatcher **, void ***, _QWORD))&v6->m_collisionDispatcher->vfptr
     + 5
     * ((unsigned __int8)v6->m_collisionDispatcher->m_agent2Types[(unsigned __int8)UFG::ExplosionManager::mClosestPointsCollidable->m_shape->m_type.m_storage][(unsigned __int8)body->m_collidable.m_shape->m_type.m_storage]
      + 79i64)))(
      UFG::ExplosionManager::mClosestPointsCollidable,
      &body->m_collidable,
      &v14,
      &v8,
      *(_QWORD *)&v9);
    if ( v12 )
    {
      *v3 = (hkVector4f)v10.m_quad;
      v8 = &hkpCdPointCollector::`vftable;
      return;
    }
    v8 = &hkpCdPointCollector::`vftable;
  }
  *v3 = v4->m_motion.m_motionState.m_sweptTransform.m_centerOfMass1;
}

// File Line: 1033
// RVA: 0x46AB40
__int64 __fastcall UFG::ExplosionManager::Explosion::IsBlockedByGeometry(UFG::ExplosionManager::Explosion *this, hkpRigidBody *body, hkVector4f *_start, hkVector4f *_end)
{
  hkpRigidBody *v4; // r14
  UFG::ExplosionManager::Explosion *v5; // r15
  unsigned __int64 v6; // rsi
  UFG::SimObject *v7; // rbx
  __int64 v8; // rsi
  UFG::SimObject *v9; // rsi
  unsigned __int8 v10; // di
  char v11; // dl
  __int64 v12; // rax
  __int64 v13; // rax
  UFG::SimObject *v14; // rax
  UFG::qReflectObjectType<UFG::PhysicsSurfaceProperties,UFG::qReflectObject> *v15; // rcx
  const char *v16; // rax
  __m128 v17; // xmm5
  __m128 v18; // xmm4
  __m128 v19; // xmm4
  __m128 v20; // xmm0
  char v21; // dl
  __int64 v22; // rax
  __int64 v23; // rcx
  UFG::qReflectObjectType<UFG::PhysicsSurfaceProperties,UFG::qReflectObject> *v24; // rcx
  const char *v25; // rax
  hkVector4f rayStart; // [rsp+20h] [rbp-C8h]
  hkVector4f rayEnd; // [rsp+30h] [rbp-B8h]
  UFG::qReflectHandleBase v29; // [rsp+40h] [rbp-A8h]
  __int64 v30; // [rsp+68h] [rbp-80h]
  UFG::RayCastData data; // [rsp+70h] [rbp-78h]

  v30 = -2i64;
  v4 = body;
  v5 = this;
  rayStart.m_quad = _start->m_quad;
  rayEnd.m_quad = _end->m_quad;
  v6 = body->m_userData;
  v7 = 0i64;
  if ( v6 && (v8 = *(_QWORD *)(v6 + 24)) != 0 )
    v9 = *(UFG::SimObject **)(v8 + 40);
  else
    v9 = 0i64;
  v10 = 0;
  rayStart.m_quad.m128_f32[2] = rayStart.m_quad.m128_f32[2] + 0.1;
  rayEnd.m_quad.m128_f32[2] = rayEnd.m_quad.m128_f32[2] + 0.1;
  data.mInput.m_from.m_quad.m128_i8[8] = 0;
  data.mInput.m_from.m_quad.m128_i32[3] = 0;
  data.mInput.m_to.m_quad.m128_u64[0] = 0i64;
  data.mInput.m_userData = __PAIR__(-1, (unsigned int)FLOAT_1_0);
  data.mOutput.m_shapeKeys[2] = 0;
  data.mOutput.m_normal.m_quad.m128_i32[2] = -1;
  *(_QWORD *)&data.mOutput.m_shapeKeys[6] = 0i64;
  *((_QWORD *)&data.mOutput.m_shapeKeyIndex + 1) = "Explosion";
  LODWORD(data.mOutput.m_rootCollidable) = -1;
  UFG::RayCastData::Init(&data, &rayStart, &rayEnd, 0x19u);
  if ( UFG::BasePhysicsSystem::CastRay(UFG::BasePhysicsSystem::mInstance, &data)
    && *(_QWORD *)&data.point.y
    && *(hkpRigidBody **)&data.point.y != v4 )
  {
    v11 = *(_BYTE *)(*(_QWORD *)&data.point.y + 352i64);
    if ( v11 != 5 && v11 != 4 )
      goto LABEL_37;
    v12 = *(_QWORD *)(*(_QWORD *)&data.point.y + 24i64);
    if ( v12 && (v13 = *(_QWORD *)(v12 + 24)) != 0 )
      v14 = *(UFG::SimObject **)(v13 + 40);
    else
      v14 = 0i64;
    if ( v14 == v5->mSource.m_pPointer || v14 == v9 )
      goto LABEL_37;
    UFG::qReflectHandleBase::qReflectHandleBase(&v29);
    v16 = UFG::qReflectObjectType<UFG::PhysicsSurfaceProperties,UFG::qReflectObject>::GetTypeName(v15);
    v29.mTypeUID = UFG::qStringHash64(v16, 0xFFFFFFFFFFFFFFFFui64);
    UFG::qReflectHandleBase::Init(&v29, v29.mTypeUID, (unsigned __int64)data.mHavokPhantom);
    if ( v29.mData )
    {
      v10 = 0;
      if ( !BYTE5(v29.mData[1].mBaseNode.mParent) )
        v10 = 1;
    }
    UFG::qReflectHandleBase::~qReflectHandleBase(&v29);
    if ( !v10 )
    {
LABEL_37:
      v17 = _mm_sub_ps(rayEnd.m_quad, rayStart.m_quad);
      v18 = _mm_mul_ps(v17, v17);
      v19 = _mm_add_ps(
              _mm_shuffle_ps(v18, v18, 170),
              _mm_add_ps(_mm_shuffle_ps(v18, v18, 85), _mm_shuffle_ps(v18, v18, 0)));
      v20 = _mm_rsqrt_ps(v19);
      rayStart.m_quad = _mm_add_ps(
                          _mm_unpacklo_ps(
                            _mm_unpacklo_ps(
                              (__m128)HIDWORD(data.mOutput.m_rootCollidable),
                              (__m128)*((unsigned int *)&data.mOutput.m_rootCollidable + 3)),
                            _mm_unpacklo_ps((__m128)*((unsigned int *)&data.mOutput.m_rootCollidable + 2), (__m128)0i64)),
                          _mm_mul_ps(
                            _mm_mul_ps(
                              v17,
                              _mm_andnot_ps(
                                _mm_cmpleps(v19, (__m128)0i64),
                                _mm_mul_ps(
                                  _mm_mul_ps(*(__m128 *)_xmm, v20),
                                  _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v20, v19), v20))))),
                            (__m128)_xmm));
      UFG::RayCastData::Init(&data, &rayStart, &rayEnd, 0x19u);
      if ( UFG::BasePhysicsSystem::CastRay(UFG::BasePhysicsSystem::mInstance, &data) )
      {
        if ( *(_QWORD *)&data.point.y )
        {
          if ( *(hkpRigidBody **)&data.point.y != v4 )
          {
            v21 = *(_BYTE *)(*(_QWORD *)&data.point.y + 352i64);
            if ( v21 == 5 || v21 == 4 )
            {
              v22 = *(_QWORD *)(*(_QWORD *)&data.point.y + 24i64);
              if ( v22 )
              {
                v23 = *(_QWORD *)(v22 + 24);
                if ( v23 )
                  v7 = *(UFG::SimObject **)(v23 + 40);
              }
              if ( v7 != v5->mSource.m_pPointer && v7 != v9 )
              {
                UFG::qReflectHandleBase::qReflectHandleBase(&v29);
                v25 = UFG::qReflectObjectType<UFG::PhysicsSurfaceProperties,UFG::qReflectObject>::GetTypeName(v24);
                v29.mTypeUID = UFG::qStringHash64(v25, 0xFFFFFFFFFFFFFFFFui64);
                UFG::qReflectHandleBase::Init(&v29, v29.mTypeUID, (unsigned __int64)data.mHavokPhantom);
                if ( v29.mData && !BYTE5(v29.mData[1].mBaseNode.mParent) )
                  v10 = 1;
                UFG::qReflectHandleBase::~qReflectHandleBase(&v29);
              }
            }
          }
        }
      }
    }
  }
  return v10;
}

// File Line: 1170
// RVA: 0x45B050
void __fastcall UFG::ExplosionManager::Explosion::ComputeExplosionMagnitudeAndRatio(UFG::ExplosionManager::Explosion *this, hkVector4f *_impulsePos, hkVector4f *_explosionPos, hkpRigidBody *body, float fTime, float *adjustedMagnitude, float *ratio)
{
  hkpMotion *v7; // rbx
  UFG::ExplosionManager::Explosion *v8; // rsi
  __m128 v9; // xmm1
  __m128 v10; // xmm1
  __m128 v11; // xmm2
  __m128 v12; // xmm1
  float v13; // xmm0_4
  float v14; // xmm0_4

  v7 = (hkpMotion *)&body->m_motion.vfptr;
  v8 = this;
  v9 = _mm_sub_ps(_impulsePos->m_quad, _explosionPos->m_quad);
  v10 = _mm_mul_ps(v9, v9);
  v11 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v10, v10, 85), _mm_shuffle_ps(v10, v10, 0)), _mm_shuffle_ps(v10, v10, 170));
  v12 = _mm_rsqrt_ps(v11);
  v13 = hkpMotion::getMass((hkpMotion *)&body->m_motion.vfptr);
  *adjustedMagnitude = UFG::ExplosionTypeInfo::GetExplosionMagnitude(
                         v8->mExplosionInfo,
                         v13,
                         COERCE_FLOAT(
                           _mm_andnot_ps(
                             _mm_cmpleps(v11, (__m128)0i64),
                             _mm_mul_ps(
                               _mm_mul_ps(
                                 _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v12, v11), v12)),
                                 _mm_mul_ps(*(__m128 *)_xmm, v12)),
                               v11))),
                         ratio);
  v14 = hkpMotion::getMass(v7);
  if ( v14 <= 0.0 )
  {
    *adjustedMagnitude = 0.0;
  }
  else if ( (float)(*adjustedMagnitude / v14) > 20.0 )
  {
    *adjustedMagnitude = (float)((float)(v14 * 20.0) / *adjustedMagnitude) * *adjustedMagnitude;
  }
  if ( v8->mUseForce )
    *adjustedMagnitude = (float)(*adjustedMagnitude / v8->mExplosionInfo->mExplosionDuration) * fTime;
}

