// File Line: 126
// RVA: 0x1513C40
__int64 dynamic_initializer_for__UFG::ExplosionManager::mActiveExplosions__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::ExplosionManager::mActiveExplosions__);
}

// File Line: 142
// RVA: 0x46BD30
void __fastcall UFG::ExplosionTypeInfo::LoadRangeValueSet(
        UFG::ExplosionTypeInfo *this,
        UFG::qPropertyList *list,
        UFG::qArray<unsigned long,0> *rangeSymbol,
        UFG::qArray<unsigned long,0> *valueSymbol,
        UFG::ExplosionTypeInfo::RangeValue *rangeValueArray,
        int rangeValueArraySize)
{
  unsigned int mNumElements; // ebp
  __int64 v7; // rbx
  UFG::ExplosionTypeInfo::RangeValue *v11; // rsi
  char *ValuePtr; // rax
  UFG::qPropertySet *v13; // rdi
  UFG::ExplosionTypeInfo::RangeValue *v14; // rax
  float *v15; // rax

  mNumElements = list->mNumElements;
  v7 = 0i64;
  if ( mNumElements )
  {
    v11 = rangeValueArray;
    do
    {
      ValuePtr = UFG::qPropertyList::GetValuePtr(list, 0x1Au, v7);
      if ( ValuePtr && *(_QWORD *)ValuePtr )
        v13 = (UFG::qPropertySet *)&ValuePtr[*(_QWORD *)ValuePtr];
      else
        v13 = 0i64;
      v14 = (UFG::ExplosionTypeInfo::RangeValue *)UFG::qPropertySet::Get<float>(v13, rangeSymbol, DEPTH_RECURSE);
      if ( !v14 )
        v14 = &rangeValueArray[v7];
      v11->range = v14->range;
      v15 = UFG::qPropertySet::Get<float>(v13, valueSymbol, DEPTH_RECURSE);
      if ( v15 )
        v11->value = *v15;
      v7 = (unsigned int)(v7 + 1);
      ++v11;
    }
    while ( (unsigned int)v7 < mNumElements );
  }
}

// File Line: 166
// RVA: 0x4694B0
void __fastcall UFG::ExplosionTypeInfo::Initialize(UFG::ExplosionTypeInfo *this, UFG::qPropertySet *properties)
{
  UFG::qPropertySet *v3; // rsi
  char *v5; // rax
  unsigned int v6; // eax
  float *v7; // rax
  float *v8; // rcx
  float v9; // eax
  bool *v10; // rax
  int *v11; // rcx
  char v12; // al
  bool *v13; // rax
  int *v14; // rcx
  UFG::qSymbol *v15; // rax
  UFG::qSymbol *v16; // rcx
  float *p_mCameraShakeAmplitude; // rax
  float *p_mCameraShakeMaxDistanceSquared; // rax
  UFG::qPropertyList *v19; // rax
  UFG::qPropertyList *v20; // rbx
  char *ValuePtr; // rax
  float *v22; // rax
  float *p_mExplosionRadius; // rcx
  int v24; // [rsp+40h] [rbp+8h] BYREF

  v3 = 0i64;
  this->mPropertySetName.mUID = properties->mName.mUID;
  this->mExplosionRadius = 0.0;
  v5 = PropertyUtils::Get<char const *>(
         properties,
         (UFG::qArray<unsigned long,0> *)&PhysicsSym_ExplosionEffectID,
         DEPTH_RECURSE);
  if ( v5 )
    v6 = UFG::qStringHashUpper32(v5, -1);
  else
    v6 = 0;
  this->mExplosionEffectID = v6;
  v24 = 0;
  v7 = UFG::qPropertySet::Get<float>(
         properties,
         (UFG::qArray<unsigned long,0> *)&PhysicsSym_ExplosionDuration,
         DEPTH_RECURSE);
  v8 = (float *)&v24;
  if ( v7 )
    v8 = v7;
  v9 = *v8;
  LOBYTE(v24) = 0;
  this->mExplosionDuration = v9;
  v10 = UFG::qPropertySet::Get<bool>(
          properties,
          (UFG::qArray<unsigned long,0> *)&PhysicsSym_ExplosionNoDamage,
          DEPTH_RECURSE);
  v11 = &v24;
  if ( v10 )
    v11 = (int *)v10;
  v12 = *(_BYTE *)v11 ^ *((_BYTE *)this + 188);
  LOBYTE(v24) = 0;
  *((_BYTE *)this + 188) ^= v12 & 1;
  v13 = UFG::qPropertySet::Get<bool>(
          properties,
          (UFG::qArray<unsigned long,0> *)&PhysicsSym_CanTriggerVehicleExplosion,
          DEPTH_RECURSE);
  v14 = &v24;
  if ( v13 )
    v14 = (int *)v13;
  *((_BYTE *)this + 188) ^= (*((_BYTE *)this + 188) ^ (2 * *(_BYTE *)v14)) & 2;
  v15 = UFG::qPropertySet::Get<UFG::qSymbol>(
          properties,
          (UFG::qArray<unsigned long,0> *)&PhysicsSym_SimObjectToSpawn,
          DEPTH_RECURSE);
  v16 = &UFG::gNullQSymbol;
  if ( v15 )
    v16 = v15;
  this->mSimObjectToSpawn = (UFG::qSymbol)v16->mUID;
  p_mCameraShakeAmplitude = UFG::qPropertySet::Get<float>(
                              properties,
                              (UFG::qArray<unsigned long,0> *)&PhysicsSym_CameraShakeAmplitude,
                              DEPTH_RECURSE);
  if ( !p_mCameraShakeAmplitude )
    p_mCameraShakeAmplitude = &this->mCameraShakeAmplitude;
  this->mCameraShakeAmplitude = *p_mCameraShakeAmplitude;
  p_mCameraShakeMaxDistanceSquared = UFG::qPropertySet::Get<float>(
                                       properties,
                                       (UFG::qArray<unsigned long,0> *)&PhysicsSym_CameraShakeMaxDistance,
                                       DEPTH_RECURSE);
  if ( !p_mCameraShakeMaxDistanceSquared )
    p_mCameraShakeMaxDistanceSquared = &this->mCameraShakeMaxDistanceSquared;
  this->mCameraShakeMaxDistanceSquared = *p_mCameraShakeMaxDistanceSquared * *p_mCameraShakeMaxDistanceSquared;
  v19 = UFG::qPropertySet::Get<UFG::qPropertyList>(
          properties,
          (UFG::qArray<unsigned long,0> *)&PhysicsSym_MassMagnitudeTable,
          DEPTH_RECURSE);
  UFG::ExplosionTypeInfo::LoadRangeValueSet(
    this,
    v19,
    &PhysicsSym_ExplosionMass,
    &PhysicsSym_ExplosionMagnitude,
    this->mMassMagnitudeValue,
    10);
  v20 = UFG::qPropertySet::Get<UFG::qPropertyList>(
          properties,
          (UFG::qArray<unsigned long,0> *)&PhysicsSym_DistanceMagnitudeRatioTable,
          DEPTH_RECURSE);
  UFG::ExplosionTypeInfo::LoadRangeValueSet(
    this,
    v20,
    &PhysicsSym_Distance,
    &PhysicsSym_Ratio,
    this->mDistanceMagnitudeRatio,
    10);
  ValuePtr = UFG::qPropertyList::GetValuePtr(v20, 0x1Au, v20->mNumElements - 1);
  if ( ValuePtr && *(_QWORD *)ValuePtr )
    v3 = (UFG::qPropertySet *)&ValuePtr[*(_QWORD *)ValuePtr];
  v22 = UFG::qPropertySet::Get<float>(v3, (UFG::qArray<unsigned long,0> *)&PhysicsSym_Distance, DEPTH_RECURSE);
  p_mExplosionRadius = &this->mExplosionRadius;
  if ( v22 )
    p_mExplosionRadius = v22;
  this->mExplosionRadius = *p_mExplosionRadius;
}

// File Line: 213
// RVA: 0x4665B0
float __fastcall UFG::ExplosionTypeInfo::GetExplosionMagnitude(
        UFG::ExplosionTypeInfo *this,
        float mass,
        float distance,
        float *ratio)
{
  int v4; // edx
  float v5; // xmm3_4
  UFG::ExplosionTypeInfo::RangeValue *mMassMagnitudeValue; // rax
  int v8; // r10d
  __int64 v9; // r8
  float value; // xmm5_4
  __int64 v11; // rcx
  UFG::ExplosionTypeInfo::RangeValue *mDistanceMagnitudeRatio; // rax

  v4 = 0;
  v5 = 0.0;
  mMassMagnitudeValue = this->mMassMagnitudeValue;
  v8 = 0;
  v9 = 0i64;
  value = 0.0;
  while ( mass >= mMassMagnitudeValue->range )
  {
    ++v9;
    ++v8;
    ++mMassMagnitudeValue;
    if ( v9 >= 10 )
      goto LABEL_8;
  }
  if ( v8 )
    value = (float)((float)((float)(mass - *(&this->mCameraShakeAmplitude + 2 * v8))
                          / (float)(this->mMassMagnitudeValue[v8].range - *(&this->mCameraShakeAmplitude + 2 * v8)))
                  * (float)(this->mMassMagnitudeValue[v8].value - this->mMassMagnitudeValue[v8 - 1].value))
          + this->mMassMagnitudeValue[v8 - 1].value;
  else
    value = this->mMassMagnitudeValue[0].value;
LABEL_8:
  v11 = 0i64;
  mDistanceMagnitudeRatio = this->mDistanceMagnitudeRatio;
  while ( distance >= mDistanceMagnitudeRatio->range )
  {
    ++v11;
    ++v4;
    ++mDistanceMagnitudeRatio;
    if ( v11 >= 10 )
      goto LABEL_15;
  }
  if ( v4 )
    v5 = (float)((float)((float)(distance - this->mMassMagnitudeValue[v4 + 9].range)
                       / (float)(this->mDistanceMagnitudeRatio[v4].range - this->mMassMagnitudeValue[v4 + 9].range))
               * (float)(this->mDistanceMagnitudeRatio[v4].value - this->mMassMagnitudeValue[v4 + 9].value))
       + this->mMassMagnitudeValue[v4 + 9].value;
  else
    v5 = this->mDistanceMagnitudeRatio[0].value;
LABEL_15:
  if ( ratio )
    *ratio = v5;
  return v5 * value;
}

// File Line: 269
// RVA: 0x464730
UFG::qPropertySet *__fastcall UFG::FindInList(UFG::qPropertyList *list, _DWORD *symbol)
{
  unsigned int mNumElements; // edi
  unsigned int v3; // ebx
  char *ValuePtr; // rax
  UFG::qPropertySet *result; // rax

  mNumElements = list->mNumElements;
  v3 = 0;
  if ( !mNumElements )
    return 0i64;
  while ( 1 )
  {
    ValuePtr = UFG::qPropertyList::GetValuePtr(list, 0x1Au, v3);
    if ( ValuePtr && *(_QWORD *)ValuePtr )
      result = (UFG::qPropertySet *)&ValuePtr[*(_QWORD *)ValuePtr];
    else
      result = 0i64;
    if ( result->mName.mUID == *symbol )
      break;
    if ( ++v3 >= mNumElements )
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
  UFG::qPropertySet *PropertySet; // rax
  UFG::qPropertyList *v3; // rcx
  UFG::qPropertySet *v4; // rax
  UFG::qPropertyList *v5; // rcx
  UFG::qPropertySet *v6; // rax
  UFG::qPropertyList *v7; // rsi
  unsigned int mNumElements; // r14d
  unsigned int i; // edi
  UFG::allocator::free_link *v10; // rax
  UFG::ExplosionTypeInfo *v11; // rax
  UFG::qSymbol *v12; // rax
  UFG::qPropertySet *v13; // rax
  __int64 v14; // rdi
  char v15; // dl
  char v16; // cl
  _QWORD **Value; // rax
  hkpSphereShape *v18; // rax
  hkpSphereShape *v19; // rax
  char v20; // al
  char v21; // dl
  char v22; // cl
  _QWORD **v23; // rax
  __int64 v24; // rax
  __int64 v25; // rsi
  char v26; // al
  UFG::qSymbol v27; // [rsp+30h] [rbp-39h] BYREF
  UFG::qSymbol result; // [rsp+34h] [rbp-35h] BYREF
  __int64 v29; // [rsp+38h] [rbp-31h]
  unsigned int **p_symbol; // [rsp+40h] [rbp-29h]
  __int128 v31[7]; // [rsp+50h] [rbp-19h] BYREF
  __int64 symbol; // [rsp+D0h] [rbp+67h] BYREF
  UFG::qArray<unsigned long,0> name; // [rsp+D8h] [rbp+6Fh] BYREF
  UFG::qSymbol v34; // [rsp+E8h] [rbp+7Fh] BYREF

  v29 = -2i64;
  if ( UFG::ExplosionManager::sIsInitialized )
    UFG::ExplosionManager::Shutdown();
  UFG::ExplosionManager::sIsInitialized = 1;
  v0 = UFG::ExplosionManager::sExplosionTypeInfos;
  memset(UFG::ExplosionManager::sExplosionTypeInfos, 0, sizeof(UFG::ExplosionManager::sExplosionTypeInfos));
  UFG::qSymbol::create_from_string(&result, "archetypes");
  UFG::qSymbol::create_from_string((UFG::qSymbol *)&name, "subfolders");
  UFG::qSymbol::create_from_string(&v34, "physical");
  UFG::qSymbol::create_from_string(&v27, "explosion");
  v1 = UFG::qSymbol::create_from_string((UFG::qSymbol *)&name.p, "object-manifest");
  PropertySet = UFG::PropertySetManager::GetPropertySet(v1);
  p_symbol = (unsigned int **)&symbol;
  LODWORD(symbol) = v34;
  v3 = UFG::qPropertySet::Get<UFG::qPropertyList>(PropertySet, &name, DEPTH_RECURSE);
  v4 = UFG::FindInList(v3, &symbol);
  p_symbol = &name.p;
  LODWORD(name.p) = v27;
  v5 = UFG::qPropertySet::Get<UFG::qPropertyList>(v4, &name, DEPTH_RECURSE);
  v6 = UFG::FindInList(v5, &name.p);
  v7 = UFG::qPropertySet::Get<UFG::qPropertyList>(v6, (UFG::qArray<unsigned long,0> *)&result, DEPTH_RECURSE);
  mNumElements = v7->mNumElements;
  for ( i = 0; i < mNumElements; ++v0 )
  {
    v10 = UFG::qMemoryPool::Allocate(&gPhysicsMemoryPool, 0xC0ui64, "ExplosionTypeInfo", 0i64, 1u);
    symbol = (__int64)v10;
    if ( v10 )
      UFG::ExplosionTypeInfo::ExplosionTypeInfo((UFG::ExplosionTypeInfo *)v10);
    else
      v11 = 0i64;
    *v0 = v11;
    v12 = UFG::qPropertyList::Get<UFG::qSymbol>(v7, i);
    v13 = UFG::PropertySetManager::GetPropertySet(v12);
    UFG::ExplosionTypeInfo::Initialize(*v0, v13);
    ++i;
  }
  v14 = *((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 16i64;
  v15 = ++*(_BYTE *)(v14 + 80);
  *(_DWORD *)(v14 + 4i64 * v15) = 3;
  *(_QWORD *)(v14 + 8i64 * v15 + 16) = "Explosion::hkpSphereShape";
  *(_QWORD *)(v14 + 8i64 * v15 + 48) = 0i64;
  v16 = *(_BYTE *)(v14 + 81);
  if ( v15 > v16 )
    v16 = v15;
  *(_BYTE *)(v14 + 81) = v16;
  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v18 = (hkpSphereShape *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 56i64);
  symbol = (__int64)v18;
  if ( v18 )
    hkpSphereShape::hkpSphereShape(v18, 0.1);
  else
    v19 = 0i64;
  UFG::ExplosionManager::mClosestPointsSphere = v19;
  v20 = *(_BYTE *)(v14 + 80);
  if ( v20 > 0 )
  {
    *(_BYTE *)(v14 + 80) = v20 - 1;
  }
  else
  {
    *(_BYTE *)(v14 + 80) = 0;
    *(_DWORD *)v14 = 3;
    *(_QWORD *)(v14 + 16) = 0i64;
    *(_QWORD *)(v14 + 48) = 0i64;
  }
  v31[0] = (__int128)transform.m_quad;
  v31[1] = (__int128)direction.m_quad;
  v31[2] = (__int128)stru_141A71280.m_quad;
  v31[3] = 0i64;
  v21 = ++*(_BYTE *)(v14 + 80);
  *(_DWORD *)(v14 + 4i64 * v21) = 3;
  *(_QWORD *)(v14 + 8i64 * v21 + 16) = "Explosion::hkpCdBody";
  *(_QWORD *)(v14 + 8i64 * v21 + 48) = 0i64;
  v22 = *(_BYTE *)(v14 + 81);
  if ( v21 > v22 )
    v22 = v21;
  *(_BYTE *)(v14 + 81) = v22;
  v23 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v24 = (*(__int64 (__fastcall **)(_QWORD *, __int64))(*v23[11] + 8i64))(v23[11], 112i64);
  v25 = v24;
  symbol = v24;
  if ( v24 )
  {
    *(_QWORD *)v24 = UFG::ExplosionManager::mClosestPointsSphere;
    *(_QWORD *)(v24 + 16) = v31;
    *(_QWORD *)(v24 + 24) = 0i64;
    *(_DWORD *)(v24 + 8) = -1;
    *(_BYTE *)(v24 + 32) = 0;
    *(_DWORD *)(v24 + 36) = 0;
    *(_WORD *)(v24 + 40) = 32512;
    *(_DWORD *)(v24 + 44) = 0;
    *(_BYTE *)(v24 + 42) = -1;
    hkpCollidable::BoundingVolumeData::BoundingVolumeData((hkpCollidable::BoundingVolumeData *)(v24 + 48));
    *(_DWORD *)(v25 + 104) = -1082130432;
    *(_BYTE *)(v25 + 41) = -36;
    *(_BYTE *)(v25 + 33) = 8;
    *(_WORD *)(v25 + 34) = 0;
  }
  else
  {
    v25 = 0i64;
  }
  UFG::ExplosionManager::mClosestPointsCollidable = (hkpCollidable *)v25;
  *(_DWORD *)(v25 + 44) = 0;
  v26 = *(_BYTE *)(v14 + 80);
  if ( v26 > 0 )
  {
    *(_BYTE *)(v14 + 80) = v26 - 1;
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
  __int64 v0; // rdi
  char **v1; // rbx
  hkpCollidable *v2; // rbx
  _QWORD **Value; // rax

  if ( UFG::ExplosionManager::sIsInitialized )
  {
    v0 = 34i64;
    v1 = (char **)UFG::ExplosionManager::sExplosionTypeInfos;
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
      Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      (*(void (__fastcall **)(_QWORD *, hkpCollidable *, __int64))(*Value[11] + 16i64))(Value[11], v2, 112i64);
    }
    hkReferencedObject::removeReference(UFG::ExplosionManager::mClosestPointsSphere);
  }
}

// File Line: 377
// RVA: 0x4666E0
UFG::ExplosionTypeInfo *__fastcall UFG::ExplosionManager::GetExplosionTypeInfo(UFG::qSymbol *explosionPropertySet)
{
  int v1; // edx
  UFG::ExplosionTypeInfo **i; // r8

  v1 = 0;
  for ( i = UFG::ExplosionManager::sExplosionTypeInfos; ; ++i )
  {
    if ( !*i )
      return 0i64;
    if ( (*i)->mPropertySetName.mUID == explosionPropertySet->mUID )
      break;
    if ( ++v1 >= 34 )
      return 0i64;
  }
  return *i;
}

// File Line: 398
// RVA: 0x45C900
void __fastcall UFG::ExplosionManager::CreateExplosion(
        UFG::qVector3 *pos,
        UFG::qSymbol *explosionPropertySet,
        UFG::SimObject *source,
        UFG::SimObject *attacker)
{
  UFG::allocator::free_link *v7; // rax
  UFG::qNode<UFG::ExplosionManager::Explosion,UFG::ExplosionManager::Explosion> *v8; // rcx
  UFG::qNode<UFG::ExplosionManager::Explosion,UFG::ExplosionManager::Explosion> *mNext; // rax

  v7 = UFG::qMalloc(0xB0ui64, UFG::gGlobalNewName, 0i64);
  if ( v7 )
    UFG::ExplosionManager::Explosion::Explosion(
      (UFG::ExplosionManager::Explosion *)v7,
      pos,
      explosionPropertySet,
      source);
  v8 = (UFG::qNode<UFG::ExplosionManager::Explosion,UFG::ExplosionManager::Explosion> *)&v7[1];
  mNext = UFG::ExplosionManager::mActiveExplosions.mNode.mNext;
  UFG::ExplosionManager::mActiveExplosions.mNode.mNext = v8;
  v8->mPrev = (UFG::qNode<UFG::ExplosionManager::Explosion,UFG::ExplosionManager::Explosion> *)&UFG::ExplosionManager::mActiveExplosions;
  v8->mNext = mNext;
  mNext->mPrev = v8;
}

// File Line: 406
// RVA: 0x479570
void __fastcall UFG::ExplosionManager::Update(float deltaT)
{
  UFG::ExplosionManager::Explosion *p_mNext; // rbx
  UFG::qList<UFG::ExplosionManager::Explosion,UFG::ExplosionManager::Explosion,1,0> *v2; // rdi
  UFG::qNode<UFG::ExplosionManager::Explosion,UFG::ExplosionManager::Explosion> *mPrev; // rdx
  UFG::qNode<UFG::ExplosionManager::Explosion,UFG::ExplosionManager::Explosion> *mNext; // rax

  p_mNext = (UFG::ExplosionManager::Explosion *)&UFG::ExplosionManager::mActiveExplosions.mNode.mNext[-1].mNext;
  if ( &UFG::ExplosionManager::mActiveExplosions.mNode.mNext[-1].mNext != (UFG::qNode<UFG::ExplosionManager::Explosion,UFG::ExplosionManager::Explosion> **)((char *)&UFG::ExplosionManager::mActiveExplosions - 8) )
  {
    do
    {
      v2 = (UFG::qList<UFG::ExplosionManager::Explosion,UFG::ExplosionManager::Explosion,1,0> *)&p_mNext->mNext[-1].mNext;
      if ( UFG::ExplosionManager::Explosion::Update(p_mNext, deltaT) )
      {
        mPrev = p_mNext->mPrev;
        mNext = p_mNext->mNext;
        mPrev->mNext = mNext;
        mNext->mPrev = mPrev;
        p_mNext->mPrev = &p_mNext->UFG::qNode<UFG::ExplosionManager::Explosion,UFG::ExplosionManager::Explosion>;
        p_mNext->mNext = &p_mNext->UFG::qNode<UFG::ExplosionManager::Explosion,UFG::ExplosionManager::Explosion>;
        p_mNext->vfptr->__vecDelDtor(p_mNext, 1u);
      }
      p_mNext = (UFG::ExplosionManager::Explosion *)v2;
    }
    while ( v2 != (UFG::qList<UFG::ExplosionManager::Explosion,UFG::ExplosionManager::Explosion,1,0> *)((char *)&UFG::ExplosionManager::mActiveExplosions - 8) );
  }
}

// File Line: 437
// RVA: 0x449A10
void __fastcall UFG::ExplosionManager::Explosion::Explosion(
        UFG::ExplosionManager::Explosion *this,
        UFG::qVector3 *pos,
        UFG::qSymbol *explosionPropertySet,
        UFG::SimObject *source)
{
  int v8; // r9d
  UFG::ExplosionTypeInfo **v9; // r8
  UFG::ExplosionTypeInfo *v10; // rcx
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *p_mSource; // r8
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *p_mAttacker; // rdx
  __m128 v13; // xmm3
  float y; // xmm1_4
  float z; // xmm0_4
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v18; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v19; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v20; // rax
  UFG::SimObject *v21; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *p_mNode; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v23; // rax
  unsigned int mExplosionEffectID; // edx
  UFG::ExplosionTypeInfo *mExplosionInfo; // rcx
  float mExplosionDuration; // xmm0_4
  hkVector4f v27; // xmm9
  float mExplosionRadius; // xmm7_4
  __int64 v29; // rsi
  char v30; // dl
  char v31; // cl
  _QWORD **Value; // rax
  hkpSphereShape *v33; // rax
  hkpSphereShape *v34; // rax
  char v35; // al
  char v36; // dl
  char v37; // cl
  _QWORD **v38; // rax
  UFG::SimObject *v39; // rax
  UFG::SimObject *v40; // r14
  char *v41; // rbx
  char v42; // al
  UFG::SimObject *m_pPointer; // r9
  UFG::qNode<UFG::BaseCameraComponent,UFG::BaseCameraComponent> *CurrentGameCamera; // rax
  UFG::GameCameraComponent *v45; // rbx
  float *v46; // rax
  float v47; // xmm0_4
  float v48; // xmm3_4
  UFG::ExplosionTypeInfo *v49; // rax
  float mCameraShakeMaxDistanceSquared; // xmm0_4
  UFG::qSymbol *p_mSimObjectToSpawn; // rcx
  UFG::qPropertySet *PropertySet; // rbx
  __int64 v53; // r8
  UFG::qString stimulus_parameters; // [rsp+30h] [rbp-89h] BYREF
  UFG::qMatrix44 basis; // [rsp+58h] [rbp-61h] BYREF
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v56; // [rsp+110h] [rbp+57h]
  UFG::SimObject *v57; // [rsp+128h] [rbp+6Fh]
  char vars0; // [rsp+130h] [rbp+77h]
  void *retaddr; // [rsp+138h] [rbp+7Fh] BYREF

  *(_QWORD *)&basis.v1.x = -2i64;
  this->mPrev = &this->UFG::qNode<UFG::ExplosionManager::Explosion,UFG::ExplosionManager::Explosion>;
  this->mNext = &this->UFG::qNode<UFG::ExplosionManager::Explosion,UFG::ExplosionManager::Explosion>;
  this->vfptr = (UFG::ExplosionManager::ExplosionVtbl *)&UFG::ExplosionManager::Explosion::`vftable;
  v8 = 0;
  v9 = UFG::ExplosionManager::sExplosionTypeInfos;
  do
  {
    v10 = *v9;
    if ( !*v9 )
      break;
    if ( v10->mPropertySetName.mUID == explosionPropertySet->mUID )
      goto LABEL_6;
    ++v8;
    ++v9;
  }
  while ( v8 < 34 );
  v10 = 0i64;
LABEL_6:
  this->mExplosionInfo = v10;
  p_mSource = &this->mSource;
  this->mSource.mPrev = &this->mSource;
  this->mSource.mNext = &this->mSource;
  this->mSource.m_pPointer = 0i64;
  p_mAttacker = &this->mAttacker;
  v56 = &this->mAttacker;
  this->mAttacker.mPrev = &this->mAttacker;
  this->mAttacker.mNext = &this->mAttacker;
  this->mAttacker.m_pPointer = 0i64;
  v13 = 0i64;
  v13.m128_f32[0] = (float)1;
  *(_QWORD *)&basis.v1.x = 0i64;
  *(__m128 *)&basis.v1.z = _mm_shuffle_ps(v13, v13, 81);
  *(__m128 *)&stimulus_parameters.mData = _mm_shuffle_ps(v13, v13, 69);
  basis.v0 = (UFG::qVector4)_mm_shuffle_ps(v13, v13, 21);
  y = pos->y;
  z = pos->z;
  basis.v0.x = pos->x;
  basis.v0.y = y;
  basis.v0.z = z;
  basis.v0.w = 1.0;
  if ( this->mSource.m_pPointer )
  {
    mPrev = p_mSource->mPrev;
    mNext = this->mSource.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_mSource->mPrev = p_mSource;
    this->mSource.mNext = &this->mSource;
  }
  this->mSource.m_pPointer = source;
  if ( source )
  {
    v18 = source->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev;
    v18->mNext = p_mSource;
    p_mSource->mPrev = v18;
    this->mSource.mNext = &source->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode;
    source->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev = p_mSource;
  }
  if ( this->mAttacker.m_pPointer )
  {
    v19 = p_mAttacker->mPrev;
    v20 = this->mAttacker.mNext;
    v19->mNext = v20;
    v20->mPrev = v19;
    p_mAttacker->mPrev = p_mAttacker;
    this->mAttacker.mNext = &this->mAttacker;
  }
  v21 = v57;
  this->mAttacker.m_pPointer = v57;
  if ( v21 )
  {
    p_mNode = &v21->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode;
    v23 = p_mNode->mPrev;
    v23->mNext = p_mAttacker;
    p_mAttacker->mPrev = v23;
    this->mAttacker.mNext = p_mNode;
    p_mNode->mPrev = p_mAttacker;
  }
  mExplosionEffectID = this->mExplosionInfo->mExplosionEffectID;
  if ( mExplosionEffectID )
    Render::FXManager::CreateEffect(&Render::gFXManager, mExplosionEffectID, (UFG::qMatrix44 *)&basis.v0.z, 0xFFFFFFFF);
  mExplosionInfo = this->mExplosionInfo;
  mExplosionDuration = mExplosionInfo->mExplosionDuration;
  this->mTimeRemaining = mExplosionDuration;
  this->mUseForce = mExplosionDuration > 0.0;
  v27.m_quad = _mm_unpacklo_ps(
                 _mm_unpacklo_ps((__m128)LODWORD(pos->x), (__m128)LODWORD(pos->z)),
                 _mm_unpacklo_ps((__m128)LODWORD(pos->y), (__m128)0i64));
  mExplosionRadius = mExplosionInfo->mExplosionRadius;
  v29 = *((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 16i64;
  v30 = ++*(_BYTE *)(v29 + 80);
  *(_DWORD *)(v29 + 4i64 * v30) = 3;
  *(_QWORD *)(v29 + 8i64 * v30 + 16) = "hkpSphereShape";
  *(_QWORD *)(v29 + 8i64 * v30 + 48) = 0i64;
  v31 = *(_BYTE *)(v29 + 81);
  if ( v30 > v31 )
    v31 = v30;
  *(_BYTE *)(v29 + 81) = v31;
  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v33 = (hkpSphereShape *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 56i64);
  v57 = (UFG::SimObject *)v33;
  if ( v33 )
    hkpSphereShape::hkpSphereShape(v33, mExplosionRadius);
  else
    v34 = 0i64;
  this->mInfluenceSphere = v34;
  v35 = *(_BYTE *)(v29 + 80);
  if ( v35 > 0 )
  {
    *(_BYTE *)(v29 + 80) = v35 - 1;
  }
  else
  {
    *(_BYTE *)(v29 + 80) = 0;
    *(_DWORD *)v29 = 3;
    *(_QWORD *)(v29 + 16) = 0i64;
    *(_QWORD *)(v29 + 48) = 0i64;
  }
  this->mTransform.m_rotation.m_col0 = (hkVector4f)transform.m_quad;
  this->mTransform.m_rotation.m_col1 = (hkVector4f)direction.m_quad;
  this->mTransform.m_rotation.m_col2 = (hkVector4f)stru_141A71280.m_quad;
  this->mTransform.m_translation = 0i64;
  this->mTransform.m_translation = (hkVector4f)v27.m_quad;
  v36 = ++*(_BYTE *)(v29 + 80);
  *(_DWORD *)(v29 + 4i64 * v36) = 3;
  *(_QWORD *)(v29 + 8i64 * v36 + 16) = "hkpCollidable";
  *(_QWORD *)(v29 + 8i64 * v36 + 48) = 0i64;
  v37 = *(_BYTE *)(v29 + 81);
  if ( v36 > v37 )
    v37 = v36;
  *(_BYTE *)(v29 + 81) = v37;
  v38 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v39 = (UFG::SimObject *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v38[11] + 8i64))(v38[11], 112i64);
  v40 = v39;
  v57 = v39;
  if ( v39 )
  {
    v39->vfptr = (UFG::qSafePointerNode<UFG::SimObject>Vtbl *)this->mInfluenceSphere;
    v39->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&this->mTransform;
    v39->m_SafePointerWithCallbackList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::mNode.mPrev = 0i64;
    LODWORD(v39->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev) = -1;
    LOBYTE(v39->m_SafePointerWithCallbackList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::mNode.mNext) = 0;
    v41 = (char *)&v39->m_SafePointerWithCallbackList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::mNode.mNext
        + 4;
    HIDWORD(v39->m_SafePointerWithCallbackList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::mNode.mNext) = 0;
    LOWORD(v39->mNode.mParent) = 32512;
    HIDWORD(v39->mNode.mParent) = 0;
    BYTE2(v39->mNode.mParent) = -1;
    hkpCollidable::BoundingVolumeData::BoundingVolumeData((hkpCollidable::BoundingVolumeData *)v39->mNode.mChild);
    LODWORD(v40->m_Components.p) = -1082130432;
    v41[5] = (_BYTE)v40 - (_BYTE)v41;
    BYTE1(v40->m_SafePointerWithCallbackList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::mNode.mNext) = 8;
    WORD1(v40->m_SafePointerWithCallbackList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::mNode.mNext) = 0;
  }
  else
  {
    v40 = 0i64;
  }
  this->mCollidable = (hkpCollidable *)v40;
  v42 = *(_BYTE *)(v29 + 80);
  if ( v42 > 0 )
  {
    *(_BYTE *)(v29 + 80) = v42 - 1;
  }
  else
  {
    *(_BYTE *)(v29 + 80) = 0;
    *(_DWORD *)v29 = 3;
    *(_QWORD *)(v29 + 16) = 0i64;
    *(_QWORD *)(v29 + 48) = 0i64;
  }
  this->mCollidable->m_broadPhaseHandle.m_collisionFilterInfo = 25;
  if ( (_BYTE)retaddr )
  {
    stimulus_parameters.mPrev = *(UFG::qNode<UFG::qString,UFG::qString> **)&UFG::qVector3::msZero.x;
    stimulus_parameters.mNext = (UFG::qNode<UFG::qString,UFG::qString> *)(LODWORD(UFG::qVector3::msZero.z) | 0x100000000i64);
    *(float *)&stimulus_parameters.mLength = FLOAT_N1_0;
    stimulus_parameters.mMagic = 1065353216;
    if ( vars0 || (m_pPointer = this->mAttacker.m_pPointer) == 0i64 || (m_pPointer->m_Flags & 2) != 0 )
      UFG::StimulusManager::BeginStimulus(
        UFG::StimulusManager::s_pInstance,
        eSTIMULUS_EXPLOSION,
        (UFG::StimulusParameters *)&stimulus_parameters,
        pos);
    else
      UFG::StimulusManager::BeginStimulus(
        UFG::StimulusManager::s_pInstance,
        eSTIMULUS_EXPLOSION,
        (UFG::StimulusParameters *)&stimulus_parameters,
        m_pPointer);
  }
  if ( this->mExplosionInfo->mCameraShakeAmplitude > 0.0 )
  {
    CurrentGameCamera = UFG::GetCurrentGameCamera();
    v45 = (UFG::GameCameraComponent *)CurrentGameCamera;
    if ( CurrentGameCamera )
    {
      v46 = (float *)((__int64 (__fastcall *)(UFG::qNode<UFG::BaseCameraComponent,UFG::BaseCameraComponent> *))CurrentGameCamera->mPrev[17].mNext)(CurrentGameCamera);
      v47 = v46[1] - pos->y;
      v48 = (float)((float)((float)(*v46 - pos->x) * (float)(*v46 - pos->x)) + (float)(v47 * v47))
          + (float)((float)(v46[2] - pos->z) * (float)(v46[2] - pos->z));
      v49 = this->mExplosionInfo;
      mCameraShakeMaxDistanceSquared = v49->mCameraShakeMaxDistanceSquared;
      if ( v48 < mCameraShakeMaxDistanceSquared )
        UFG::GameCameraComponent::AddShakeAmplitude(
          v45,
          (float)(1.0 - (float)(v48 / mCameraShakeMaxDistanceSquared)) * v49->mCameraShakeAmplitude);
    }
  }
  p_mSimObjectToSpawn = &this->mExplosionInfo->mSimObjectToSpawn;
  if ( p_mSimObjectToSpawn->mUID != -1 )
  {
    PropertySet = UFG::PropertySetManager::FindPropertySet(p_mSimObjectToSpawn);
    if ( PropertySet )
    {
      v53 = (unsigned int)count_1++;
      UFG::qString::qString(&stimulus_parameters, "Explosion-%d", v53);
      UFG::qSymbol::create_from_string((UFG::qSymbol *)&retaddr, stimulus_parameters.mData);
      UFG::SpawnInfoInterface::SpawnObject(
        (UFG::qSymbol *)&retaddr,
        PropertySet,
        (UFG::qMatrix44 *)&basis.v0.z,
        Count,
        0i64,
        0i64);
      UFG::qString::~qString(&stimulus_parameters);
    }
  }
}i64,
        0i64);
      UFG::qString::~qString(&stimulus_parameters);
    }
  }
}

// File Line: 537
// RVA: 0x44FF40
void __fastcall UFG::ExplosionManager::Explosion::~Explosion(UFG::ExplosionManager::Explosion *this)
{
  hkpCollidable *mCollidable; // rdi
  _QWORD **Value; // rax
  hkpSphereShape *mInfluenceSphere; // rcx
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *p_mAttacker; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *p_mSource; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v11; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v12; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v13; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v14; // rax
  UFG::qNode<UFG::ExplosionManager::Explosion,UFG::ExplosionManager::Explosion> *v15; // rcx
  UFG::qNode<UFG::ExplosionManager::Explosion,UFG::ExplosionManager::Explosion> *v16; // rax

  this->vfptr = (UFG::ExplosionManager::ExplosionVtbl *)&UFG::ExplosionManager::Explosion::`vftable;
  mCollidable = this->mCollidable;
  if ( mCollidable )
  {
    Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    (*(void (__fastcall **)(_QWORD *, hkpCollidable *, __int64))(*Value[11] + 16i64))(Value[11], mCollidable, 112i64);
  }
  mInfluenceSphere = this->mInfluenceSphere;
  if ( mInfluenceSphere )
    mInfluenceSphere->vfptr->__vecDelDtor(mInfluenceSphere, 1u);
  p_mAttacker = &this->mAttacker;
  if ( this->mAttacker.m_pPointer )
  {
    mPrev = p_mAttacker->mPrev;
    mNext = this->mAttacker.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_mAttacker->mPrev = p_mAttacker;
    this->mAttacker.mNext = &this->mAttacker;
  }
  this->mAttacker.m_pPointer = 0i64;
  v8 = p_mAttacker->mPrev;
  v9 = this->mAttacker.mNext;
  v8->mNext = v9;
  v9->mPrev = v8;
  p_mAttacker->mPrev = p_mAttacker;
  this->mAttacker.mNext = &this->mAttacker;
  p_mSource = &this->mSource;
  if ( this->mSource.m_pPointer )
  {
    v11 = p_mSource->mPrev;
    v12 = this->mSource.mNext;
    v11->mNext = v12;
    v12->mPrev = v11;
    p_mSource->mPrev = p_mSource;
    this->mSource.mNext = &this->mSource;
  }
  this->mSource.m_pPointer = 0i64;
  v13 = p_mSource->mPrev;
  v14 = this->mSource.mNext;
  v13->mNext = v14;
  v14->mPrev = v13;
  p_mSource->mPrev = p_mSource;
  this->mSource.mNext = &this->mSource;
  v15 = this->mPrev;
  v16 = this->mNext;
  v15->mNext = v16;
  v16->mPrev = v15;
  this->mPrev = &this->UFG::qNode<UFG::ExplosionManager::Explosion,UFG::ExplosionManager::Explosion>;
  this->mNext = &this->UFG::qNode<UFG::ExplosionManager::Explosion,UFG::ExplosionManager::Explosion>;
}

// File Line: 545
// RVA: 0x477EB0
_BOOL8 __fastcall UFG::ExplosionManager::Explosion::Update(UFG::ExplosionManager::Explosion *this, float deltaT)
{
  float v2; // xmm11_4
  hkpWorld *mWorld; // rcx
  hkVector4f *p_m_translation; // r13
  float v6; // xmm0_4
  __int64 v7; // rax
  __m128 v8; // xmm10
  unsigned int v9; // r14d
  hkpRootCdBodyPair *v10; // rax
  unsigned int m_shapeKeyA; // r12d
  __int64 v12; // rdi
  hkpCollidable *m_rootCollidableB; // rcx
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
  __int64 v27; // rbx
  float ExplosionMagnitude; // xmm7_4
  float Mass; // xmm0_4
  bool mUseForce; // cl
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
  UFG::CollisionMeshData::PartDetails *PartDetails; // rax
  int v48; // r15d
  hkpWorld *v49; // r13
  UFG::CollisionMeshData::Part *Part; // rbx
  UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject> *v51; // rcx
  const char *TypeName; // rax
  __int64 v53; // r8
  __m128 v54; // xmm6
  __m128 v55; // xmm3
  __m128 v56; // xmm3
  __m128 v57; // xmm5
  __m128 v58; // xmm1
  hkpRigidBody **m_data; // rbx
  hkpShape *m_shape; // rcx
  __m128 v61; // xmm8
  __m128 v62; // xmm7
  __m128 v63; // xmm6
  __m128 v64; // xmm0
  hkpEntity *v65; // rbx
  __int64 v66; // rdx
  __int64 m_size; // rdi
  hkpRigidBody **v68; // r15
  int v69; // r14d
  int v70; // r9d
  hkpEntity **v71; // rax
  hkpEntity **v72; // rdx
  signed __int64 v73; // r15
  __int64 v74; // rcx
  float v75; // xmm7_4
  UFG::SimObjectCVBase *v76; // rdi
  hkpRigidBody *v77; // r13
  __m128 m_quad; // xmm2
  UFG::SimComponent *v79; // r12
  UFG::PhysicsMoverInterface *v80; // r15
  __int16 m_Flags; // cx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  __int16 v83; // cx
  UFG::SimComponent *m_pComponent; // rbx
  UFG::SimComponent *ComponentOfType; // rax
  __int16 v86; // cx
  UFG::SimComponent *v87; // rax
  __int16 v88; // cx
  UFG::CharacterOccupantComponent *v89; // rax
  UFG::SimObjectVehicle *CurrentVehicle; // rax
  hkVector4f *v91; // rbx
  UFG::PhysicsVehicle *RigidBody; // rax
  __m128 v93; // xmm2
  hkpMotion *p_m_motion; // rbx
  __m128 v95; // xmm2
  __m128 v96; // xmm2
  __m128 v97; // xmm0
  float v98; // xmm6_4
  float v99; // xmm0_4
  __m128 v100; // xmm6
  __m128 v101; // xmm4
  __m128 v102; // xmm4
  __m128 v103; // xmm5
  __m128 v104; // xmm0
  __m128 v105; // xmm2
  __m128 v106; // xmm0
  __m128 v107; // xmm1
  __m128 v108; // xmm5
  hkpEntity *v109; // rax
  hkpEntity *v110; // rbx
  __int64 v111; // rdx
  char v112; // bl
  char m_storage; // cl
  __int64 v114; // rdx
  char v115; // cl
  float v116; // xmm10_4
  __int16 v117; // cx
  UFG::SimComponent *v118; // rax
  char v119; // al
  __int16 v120; // cx
  UFG::CharacterAnimationComponent *v121; // rax
  __int16 v122; // cx
  UFG::HitReactionComponent *v123; // rbx
  UFG::SimComponent *v124; // rax
  float v125; // xmm6_4
  __int16 v126; // cx
  UFG::SimComponent *v127; // rax
  int v128; // edi
  float v129; // xmm5_4
  float v130; // xmm2_4
  float v131; // xmm6_4
  float v132; // xmm3_4
  float v133; // xmm4_4
  float v134; // xmm8_4
  int m_EnumValue; // eax
  __m128 v136; // xmm4
  float v137; // xmm3_4
  UFG::SimObject *m_pPointer; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v141; // rax
  UFG::StateMachineComponent *vfptr; // rcx
  bool v143; // bl
  int maxImpulse; // [rsp+20h] [rbp-E0h]
  hkVector4f *normal; // [rsp+28h] [rbp-D8h]
  hkVector4f *position; // [rsp+30h] [rbp-D0h]
  hkArray<unsigned int,hkContainerHeapAllocator> *keysBrokenOffOut; // [rsp+38h] [rbp-C8h]
  hkpPhysicsSystem *bodiesOut; // [rsp+40h] [rbp-C0h]
  hkVector4f pos; // [rsp+50h] [rbp-B0h] BYREF
  hkArray<unsigned int,hkContainerHeapAllocator> v151; // [rsp+60h] [rbp-A0h] BYREF
  __m128 v152; // [rsp+70h] [rbp-90h]
  __int64 v153; // [rsp+80h] [rbp-80h]
  UFG::Destruction *v154; // [rsp+88h] [rbp-78h]
  __m128 v155; // [rsp+90h] [rbp-70h] BYREF
  __m128 v156; // [rsp+A0h] [rbp-60h] BYREF
  UFG::HitRecord hitrecord; // [rsp+B0h] [rbp-50h] BYREF
  UFG::qReflectHandleBase v158; // [rsp+1E0h] [rbp+E0h] BYREF
  hkVector4f v159; // [rsp+210h] [rbp+110h] BYREF
  __int64 v160; // [rsp+220h] [rbp+120h]
  hkVector4f v161; // [rsp+230h] [rbp+130h] BYREF
  hkpPhysicsSystem sys; // [rsp+240h] [rbp+140h] BYREF
  __m128 v163[2]; // [rsp+2B0h] [rbp+1B0h] BYREF
  __int128 v164[4]; // [rsp+2D0h] [rbp+1D0h] BYREF
  hkpAllCdBodyPairCollector collector; // [rsp+310h] [rbp+210h] BYREF
  char *array; // [rsp+530h] [rbp+430h] BYREF
  unsigned int v167; // [rsp+538h] [rbp+438h]
  int v168; // [rsp+53Ch] [rbp+43Ch]
  char v169; // [rsp+540h] [rbp+440h] BYREF
  hkpEntity **entityBatch; // [rsp+940h] [rbp+840h] BYREF
  int v171; // [rsp+948h] [rbp+848h]
  int v172; // [rsp+94Ch] [rbp+84Ch]
  __int64 v173; // [rsp+950h] [rbp+850h] BYREF
  char *v174; // [rsp+D50h] [rbp+C50h] BYREF
  int v175; // [rsp+D58h] [rbp+C58h]
  int v176; // [rsp+D5Ch] [rbp+C5Ch]
  char v177; // [rsp+D60h] [rbp+C60h] BYREF
  char *v178; // [rsp+1160h] [rbp+1060h] BYREF
  int v179; // [rsp+1168h] [rbp+1068h]
  int v180; // [rsp+116Ch] [rbp+106Ch]
  char v181; // [rsp+1170h] [rbp+1070h] BYREF
  hkInplaceArray<hkpRootCdBodyPair,16,hkContainerHeapAllocator> *adjustedMagnitude; // [rsp+1A60h] [rbp+1960h] BYREF
  float v183; // [rsp+1A68h] [rbp+1968h]
  hkResult result; // [rsp+1A70h] [rbp+1970h] BYREF
  __int64 ratio; // [rsp+1A78h] [rbp+1978h] BYREF

  v160 = -2i64;
  v2 = deltaT;
  mWorld = UFG::BasePhysicsSystem::mInstance->mWorld;
  collector.vfptr = (hkpCdBodyPairCollectorVtbl *)&hkpAllCdBodyPairCollector::`vftable;
  adjustedMagnitude = &collector.m_hits;
  collector.m_hits.m_data = collector.m_hits.m_storage;
  collector.m_hits.m_capacityAndFlags = -2147483632;
  collector.m_hits.m_size = 0;
  collector.m_earlyOut.m_bool = 0;
  hkpWorld::getPenetrations(mWorld, this->mCollidable, mWorld->m_collisionInput, &collector);
  p_m_translation = &this->mTransform.m_translation;
  UFG::ExplosionManager::mClosestPointsCollidable->m_motion = &this->mTransform;
  v6 = this->mTimeRemaining - deltaT;
  this->mTimeRemaining = v6;
  if ( v6 < 0.0 )
    v2 = deltaT - (float)(v6 * -1.0);
  array = &v169;
  v167 = 0;
  v168 = -2147483520;
  v174 = &v177;
  v175 = 0;
  v176 = -2147483520;
  v178 = &v181;
  v179 = 0;
  v180 = -2147483520;
  v154 = UFG::Destruction::mInstance;
  v183 = 0.0;
  v7 = 0i64;
  v153 = 0i64;
  v152.m128_u64[0] = collector.m_hits.m_size;
  v8 = (__m128)(unsigned int)FLOAT_1_0;
  v9 = 0;
  if ( collector.m_hits.m_size > 0 )
  {
    do
    {
      v10 = &collector.m_hits.m_data[v7];
      m_shapeKeyA = v10->m_shapeKeyA;
      if ( v10->m_rootCollidableA->m_broadPhaseHandle.m_type == 1 )
        v12 = (__int64)v10->m_rootCollidableA + v10->m_rootCollidableA->m_ownerOffset;
      else
        v12 = 0i64;
      if ( !v12 )
      {
        m_shapeKeyA = v10->m_shapeKeyB;
        m_rootCollidableB = v10->m_rootCollidableB;
        v12 = m_rootCollidableB->m_broadPhaseHandle.m_type == 1
            ? (__int64)m_rootCollidableB + m_rootCollidableB->m_ownerOffset
            : 0i64;
        if ( !v12 )
          goto LABEL_83;
      }
      if ( *(_BYTE *)(v12 + 352) == 5 && (*(_BYTE *)(v12 + 76) & 0x1F) == 9 )
      {
        v14 = *(_QWORD *)(v12 + 32);
        if ( *(_BYTE *)(v14 + 16) == (*(_BYTE *)(v12 + 76) & 0x1F) && *(_BYTE *)(*(_QWORD *)(v14 + 88) + 16i64) == 13 )
          goto LABEL_83;
      }
      v15 = *(_QWORD *)(v12 + 24);
      if ( !v15 )
        goto LABEL_83;
      v16 = *(_QWORD *)(v15 + 24);
      if ( v16 )
        v16 = *(_QWORD *)(v16 + 40);
      if ( !v16 )
        goto LABEL_83;
      UFG::ExplosionManager::Explosion::FindClosestPointToExplosion(this, (hkpRigidBody *)v12, &pos);
      if ( !UFG::ExplosionManager::Explosion::IsBlockedByGeometry(this, (hkpRigidBody *)v12, p_m_translation, &pos) )
      {
        v17 = 0;
        v9 = v167;
        if ( v167 )
        {
          v18 = array;
          while ( *(_QWORD *)v18 != v16 )
          {
            ++v17;
            v18 += 8;
            if ( v17 >= v167 )
              goto LABEL_25;
          }
        }
        else
        {
LABEL_25:
          if ( v167 < 0x80 )
          {
            if ( v167 == (v168 & 0x3FFFFFFF) )
            {
              hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, &array, 8);
              v9 = v167;
            }
            *(_QWORD *)&array[8 * v9] = v16;
            ++v167;
            v19 = v175;
            if ( v175 == (v176 & 0x3FFFFFFF) )
            {
              hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, &v174, 8);
              v19 = v175;
            }
            *(_QWORD *)&v174[8 * v19] = v12;
            ++v175;
            v20 = v179;
            if ( v179 == (v180 & 0x3FFFFFFF) )
            {
              hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, &v178, 16);
              v20 = v179;
            }
            *(hkVector4f *)&v178[16 * v20] = (hkVector4f)pos.m_quad;
            ++v179;
            v9 = v167;
          }
        }
        v21 = *(_QWORD *)(v15 + 24);
        if ( !v21 )
          goto LABEL_83;
        if ( UFG::SimComponent::IsType((UFG::SimComponent *)v21, UFG::RagdollComponent::_RagdollComponentTypeUID) )
        {
          v22 = _mm_sub_ps(pos.m_quad, p_m_translation->m_quad);
          v23 = _mm_mul_ps(v22, v22);
          v24 = _mm_add_ps(
                  _mm_shuffle_ps(v23, v23, 170),
                  _mm_add_ps(_mm_shuffle_ps(v23, v23, 85), _mm_shuffle_ps(v23, v23, 0)));
          v25 = _mm_rsqrt_ps(v24);
          LODWORD(v26) = _mm_andnot_ps(
                           _mm_cmple_ps(v24, (__m128)0i64),
                           _mm_mul_ps(
                             v24,
                             _mm_mul_ps(
                               _mm_mul_ps(*(__m128 *)_xmm, v25),
                               _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v25, v24), v25))))).m128_u32[0];
          v27 = v12 + 336;
          v25.m128_f32[0] = hkpMotion::getMass((hkpMotion *)(v12 + 336));
          ExplosionMagnitude = UFG::ExplosionTypeInfo::GetExplosionMagnitude(
                                 this->mExplosionInfo,
                                 v25.m128_f32[0],
                                 v26,
                                 (float *)&ratio);
          Mass = hkpMotion::getMass((hkpMotion *)(v12 + 336));
          if ( Mass <= 0.0 )
          {
            ExplosionMagnitude = 0.0;
          }
          else if ( (float)(ExplosionMagnitude / Mass) > 20.0 )
          {
            ExplosionMagnitude = ExplosionMagnitude * (float)((float)(Mass * 20.0) / ExplosionMagnitude);
          }
          mUseForce = this->mUseForce;
          if ( mUseForce )
            ExplosionMagnitude = (float)(ExplosionMagnitude / this->mExplosionInfo->mExplosionDuration) * v2;
          v31 = _mm_sub_ps(pos.m_quad, p_m_translation->m_quad);
          v32 = _mm_mul_ps(v31, v31);
          v33 = _mm_add_ps(
                  _mm_shuffle_ps(v32, v32, 170),
                  _mm_add_ps(_mm_shuffle_ps(v32, v32, 85), _mm_shuffle_ps(v32, v32, 0)));
          v34 = _mm_rsqrt_ps(v33);
          v35 = _mm_andnot_ps(
                  _mm_cmple_ps(v33, (__m128)0i64),
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
          v39 = _mm_cmplt_ps(_mm_sub_ps((__m128)0i64, v38), (__m128)0i64);
          v40 = _mm_rsqrt_ps(v38);
          v41 = _mm_mul_ps(_mm_mul_ps(v40, v38), v40);
          v42 = _mm_mul_ps(
                  _mm_andnot_ps(
                    _mm_cmple_ps(v38, (__m128)0i64),
                    _mm_mul_ps(_mm_mul_ps(v40, *(__m128 *)_xmm), _mm_sub_ps((__m128)_xmm, v41))),
                  v36);
          v41.m128_f32[0] = ExplosionMagnitude;
          v155 = _mm_mul_ps(_mm_or_ps(_mm_andnot_ps(v39, v36), _mm_and_ps(v39, v42)), _mm_shuffle_ps(v41, v41, 0));
          if ( mUseForce )
          {
            hkpEntity::activate((hkpEntity *)v12);
            (*(void (__fastcall **)(__int64, __int64, __m128 *, hkVector4f *, int, hkVector4f *, hkVector4f *, hkArray<unsigned int,hkContainerHeapAllocator> *, hkpPhysicsSystem *))(*(_QWORD *)v27 + 200i64))(
              v12 + 336,
              v43,
              &v155,
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
            (*(void (__fastcall **)(__int64, __m128 *, hkVector4f *))(*(_QWORD *)v27 + 184i64))(v12 + 336, &v155, &pos);
          }
          v8 = (__m128)(unsigned int)FLOAT_1_0;
        }
        if ( UFG::SimComponent::IsType((UFG::SimComponent *)v21, UFG::RigidBodyComponent::_RigidBodyComponentTypeUID) )
        {
          v44 = *(UFG::CollisionMeshData **)(v21 + 160);
          if ( v44 )
          {
            if ( m_shapeKeyA != -1 )
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
                    PartDetails = UFG::CollisionMeshData::GetPartDetails(
                                    *(UFG::CollisionMeshData **)(v21 + 160),
                                    m_shapeKeyA);
                    if ( PartDetails )
                    {
                      if ( PartDetails->mShearImpulse > 0.0 )
                      {
                        v48 = LODWORD(v183);
                        if ( SLODWORD(v183) < 15 )
                        {
                          v151.m_data = 0i64;
                          v151.m_size = 0;
                          v151.m_capacityAndFlags = 0x80000000;
                          hkpPhysicsSystem::hkpPhysicsSystem(&sys);
                          v49 = *(hkpWorld **)(v12 + 16);
                          Part = UFG::CollisionMeshData::GetPart(v44, m_shapeKeyA);
                          UFG::qReflectHandleBase::qReflectHandleBase(&v158);
                          TypeName = UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject>::GetTypeName(v51);
                          v158.mTypeUID = UFG::qStringHash64(TypeName, 0xFFFFFFFFFFFFFFFFui64);
                          UFG::qReflectHandleBase::Init(
                            &v158,
                            v158.mTypeUID,
                            Part->mBaseProperty.objectPropertyHandleId);
                          if ( v158.mData && BYTE4(v158.mData[1].mHandles.mNode.mNext) )
                          {
                            v161.m_quad = *(__m128 *)(v12 + 448);
                            v159.m_quad = (__m128)_xmm;
                            bodiesOut = &sys;
                            keysBrokenOffOut = &v151;
                            position = &v161;
                            normal = &v159;
                            maxImpulse = 0;
                            UFG::Destruction::breakOffSubPart(v154, 0i64, (hkpRigidBody *)v12, m_shapeKeyA);
                            LODWORD(v183) = v48 + 1;
                          }
                          hkpWorld::addPhysicsSystem(v49, &sys);
                          if ( sys.m_rigidBodies.m_size > 0 && *sys.m_rigidBodies.m_data )
                          {
                            UFG::ExplosionManager::Explosion::ComputeExplosionMagnitudeAndRatio(
                              this,
                              &pos,
                              &this->mTransform.m_translation,
                              *sys.m_rigidBodies.m_data,
                              v2,
                              (float *)&adjustedMagnitude,
                              (float *)&ratio);
                            v54 = _mm_sub_ps(pos.m_quad, this->mTransform.m_translation.m_quad);
                            v55 = _mm_mul_ps(v54, v54);
                            v56 = _mm_add_ps(
                                    _mm_shuffle_ps(v55, v55, 170),
                                    _mm_add_ps(_mm_shuffle_ps(v55, v55, 85), _mm_shuffle_ps(v55, v55, 0)));
                            v57 = _mm_cmplt_ps(_mm_sub_ps((__m128)0i64, v56), (__m128)0i64);
                            v58 = _mm_rsqrt_ps(v56);
                            v156 = _mm_mul_ps(
                                     _mm_or_ps(
                                       _mm_andnot_ps(v57, v54),
                                       _mm_and_ps(
                                         _mm_mul_ps(
                                           _mm_andnot_ps(
                                             _mm_cmple_ps(v56, (__m128)0i64),
                                             _mm_mul_ps(
                                               _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v58, v56), v58)),
                                               _mm_mul_ps(*(__m128 *)_xmm, v58))),
                                           v54),
                                         v57)),
                                     _mm_shuffle_ps(
                                       (__m128)(unsigned int)adjustedMagnitude,
                                       (__m128)(unsigned int)adjustedMagnitude,
                                       0));
                            m_data = sys.m_rigidBodies.m_data;
                            if ( *sys.m_rigidBodies.m_data != (hkpRigidBody *)-32i64 )
                            {
                              m_shape = (*sys.m_rigidBodies.m_data)->m_collidable.m_shape;
                              if ( m_shape )
                              {
                                v164[0] = (__int128)transform.m_quad;
                                v164[1] = (__int128)direction.m_quad;
                                v164[2] = (__int128)stru_141A71280.m_quad;
                                v164[3] = 0i64;
                                ((void (__fastcall *)(hkpShape *, __int128 *, __int64, __m128 *))m_shape->vfptr[2].__vecDelDtor)(
                                  m_shape,
                                  v164,
                                  v53,
                                  v163);
                                v61 = _mm_sub_ps(v163[1], v163[0]);
                                v62 = v8;
                                v62.m128_f32[0] = UFG::qRandom(v8.m128_f32[0], (unsigned int *)&UFG::qDefaultSeed) - 0.5;
                                v63 = v8;
                                v63.m128_f32[0] = UFG::qRandom(v8.m128_f32[0], (unsigned int *)&UFG::qDefaultSeed) - 0.5;
                                v64 = v8;
                                v64.m128_f32[0] = UFG::qRandom(v8.m128_f32[0], (unsigned int *)&UFG::qDefaultSeed) - 0.5;
                                pos.m_quad = _mm_add_ps(
                                               pos.m_quad,
                                               _mm_mul_ps(
                                                 _mm_unpacklo_ps(
                                                   _mm_unpacklo_ps(v64, v62),
                                                   _mm_unpacklo_ps(v63, (__m128)0i64)),
                                                 v61));
                                m_data = sys.m_rigidBodies.m_data;
                              }
                            }
                            v65 = *m_data;
                            if ( this->mUseForce )
                            {
                              hkpEntity::activate(v65);
                              ((void (__fastcall *)(hkpMaxSizeMotion *, __int64, __m128 *, hkVector4f *))v65->m_motion.vfptr[12].__first_virtual_table_function__)(
                                &v65->m_motion,
                                v66,
                                &v156,
                                &pos);
                            }
                            else
                            {
                              hkpEntity::activate(v65);
                              ((void (__fastcall *)(hkpMaxSizeMotion *, __m128 *, hkVector4f *))v65->m_motion.vfptr[11].__first_virtual_table_function__)(
                                &v65->m_motion,
                                &v156,
                                &pos);
                            }
                          }
                          entityBatch = (hkpEntity **)&v173;
                          v172 = -2147483520;
                          v173 = v12;
                          v171 = 1;
                          m_size = sys.m_rigidBodies.m_size;
                          v68 = sys.m_rigidBodies.m_data;
                          v69 = sys.m_rigidBodies.m_size + 1;
                          if ( sys.m_rigidBodies.m_size + 1 > 128 )
                          {
                            v70 = sys.m_rigidBodies.m_size + 1;
                            if ( v69 < 2 * (v172 & 0x3FFFFFFF) )
                              v70 = 2 * (v172 & 0x3FFFFFFF);
                            hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, &entityBatch, v70, 8);
                          }
                          hkMemUtil::memMove(&entityBatch[m_size + 1], entityBatch + 1, 0);
                          v71 = entityBatch;
                          v72 = entityBatch + 1;
                          if ( m_size > 0 )
                          {
                            v73 = (char *)v68 - (char *)v72;
                            do
                            {
                              *v72 = *(hkpEntity **)((char *)v72 + v73);
                              ++v72;
                              --m_size;
                            }
                            while ( m_size );
                            v71 = entityBatch;
                          }
                          v171 = v69;
                          if ( v69 )
                          {
                            hkpWorld::reintegrateAndRecollideEntities(v49, v71, v69, RR_MODE_RECOLLIDE_NARROWPHASE);
                            hkReferencedObject::lockAll();
                            hkpPhysicsSystem::removeAll(&sys);
                            hkReferencedObject::unlockAll();
                          }
                          v171 = 0;
                          if ( v172 >= 0 )
                            hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
                              &hkContainerHeapAllocator::s_alloc,
                              entityBatch,
                              8 * v172);
                          entityBatch = 0i64;
                          v172 = 0x80000000;
                          UFG::qReflectHandleBase::~qReflectHandleBase(&v158);
                          hkpPhysicsSystem::~hkpPhysicsSystem(&sys);
                          v151.m_size = 0;
                          if ( v151.m_capacityAndFlags >= 0 )
                            hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
                              &hkContainerHeapAllocator::s_alloc,
                              v151.m_data,
                              4 * v151.m_capacityAndFlags);
                          v151.m_data = 0i64;
                          v151.m_capacityAndFlags = 0x80000000;
                          p_m_translation = &this->mTransform.m_translation;
                        }
                      }
                    }
                  }
                }
                goto LABEL_82;
              }
              if ( v46 == 8 )
                goto LABEL_51;
            }
          }
        }
      }
LABEL_82:
      v9 = v167;
LABEL_83:
      v7 = v153 + 1;
      v153 = v7;
    }
    while ( v7 < v152.m128_i64[0] );
  }
  result.m_enum = HK_SUCCESS;
  v74 = 0i64;
  ratio = 0i64;
  if ( v9 )
  {
    v75 = v183;
    while ( 1 )
    {
      v76 = *(UFG::SimObjectCVBase **)&array[8 * v74];
      v77 = *(hkpRigidBody **)&v174[8 * v74];
      m_quad = *(__m128 *)&v178[16 * v74];
      pos.m_quad = m_quad;
      LOBYTE(v183) = 0;
      if ( !v76 )
        break;
      m_Flags = v76->m_Flags;
      if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
        ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(v76, UFG::RigidBodyComponent::_TypeUID);
      else
        ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(v76, UFG::RigidBodyComponent::_TypeUID);
      v79 = ComponentOfTypeHK;
      v83 = v76->m_Flags;
      if ( (v83 & 0x4000) != 0 )
      {
        m_pComponent = v76->m_Components.p[27].m_pComponent;
      }
      else
      {
        if ( v83 < 0 || (v83 & 0x2000) != 0 || (v83 & 0x1000) != 0 )
          ComponentOfType = UFG::SimObjectGame::GetComponentOfTypeHK(v76, UFG::CharacterPhysicsComponent::_TypeUID);
        else
          ComponentOfType = UFG::SimObject::GetComponentOfType(v76, UFG::CharacterPhysicsComponent::_TypeUID);
        m_pComponent = ComponentOfType;
      }
      v86 = v76->m_Flags;
      if ( (v86 & 0x4000) != 0 )
      {
        v80 = 0i64;
      }
      else if ( v86 >= 0 )
      {
        if ( (v86 & 0x2000) != 0 )
        {
          v80 = 0i64;
        }
        else
        {
          if ( (v86 & 0x1000) != 0 )
            v87 = UFG::SimObjectGame::GetComponentOfTypeHK(v76, UFG::PhysicsMoverInterface::_TypeUID);
          else
            v87 = UFG::SimObject::GetComponentOfType(v76, UFG::PhysicsMoverInterface::_TypeUID);
          v80 = (UFG::PhysicsMoverInterface *)v87;
        }
      }
      else
      {
        v80 = (UFG::PhysicsMoverInterface *)v76->m_Components.p[34].m_pComponent;
      }
      v88 = v76->m_Flags;
      if ( (v88 & 0x4000) != 0 )
      {
        v89 = (UFG::CharacterOccupantComponent *)v76->m_Components.p[44].m_pComponent;
      }
      else if ( v88 < 0 || (v88 & 0x2000) != 0 || (v88 & 0x1000) != 0 )
      {
        v89 = (UFG::CharacterOccupantComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                   v76,
                                                   UFG::CharacterOccupantComponent::_TypeUID);
      }
      else
      {
        v89 = (UFG::CharacterOccupantComponent *)UFG::SimObject::GetComponentOfType(
                                                   v76,
                                                   UFG::CharacterOccupantComponent::_TypeUID);
      }
      if ( !v89
        || (CurrentVehicle = (UFG::SimObjectVehicle *)UFG::CharacterOccupantComponent::GetCurrentVehicle(v89)) == 0i64
        || UFG::SimObjectVehicle::GetComponent<UFG::BikePhysicsMoverComponent>(CurrentVehicle) )
      {
        if ( !m_pComponent )
        {
          v91 = &this->mTransform.m_translation;
LABEL_129:
          if ( v80 )
          {
            RigidBody = UFG::PhysicsMoverInterface::GetRigidBody(v80);
            if ( RigidBody )
            {
              v93 = _mm_sub_ps(pos.m_quad, v91->m_quad);
              p_m_motion = (hkpMotion *)&RigidBody->mVolumeOffset.v1;
              goto LABEL_134;
            }
LABEL_140:
            v100 = _mm_sub_ps(pos.m_quad, this->mTransform.m_translation.m_quad);
            v101 = _mm_mul_ps(v100, v100);
            v102 = _mm_add_ps(
                     _mm_shuffle_ps(v101, v101, 170),
                     _mm_add_ps(_mm_shuffle_ps(v101, v101, 85), _mm_shuffle_ps(v101, v101, 0)));
            v103 = _mm_cmplt_ps(_mm_sub_ps((__m128)0i64, v102), (__m128)0i64);
            v104 = _mm_rsqrt_ps(v102);
            v105 = _mm_mul_ps(*(__m128 *)_xmm, v104);
            v106 = _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v104, v102), v104));
            v107 = _mm_andnot_ps(v103, v100);
            v108 = _mm_and_ps(
                     v103,
                     _mm_mul_ps(_mm_andnot_ps(_mm_cmple_ps(v102, (__m128)0i64), _mm_mul_ps(v105, v106)), v100));
            v106.m128_f32[0] = v75;
            v151 = (hkArray<unsigned int,hkContainerHeapAllocator>)_mm_mul_ps(
                                                                     _mm_or_ps(v107, v108),
                                                                     _mm_shuffle_ps(v106, v106, 0));
            if ( v80 )
            {
              UFG::PhysicsMoverInterface::LockHighLod(v80, ELODLockMode_UNTIL_AT_REST, 0.0);
              LOBYTE(maxImpulse) = 1;
              UFG::PhysicsMoverInterface::DamageEngine(
                v80,
                this->mAttacker.m_pPointer,
                *(float *)&adjustedMagnitude * 0.75,
                dtBULLET);
              v109 = (hkpEntity *)UFG::PhysicsMoverInterface::GetRigidBody(v80);
              v110 = v109;
              if ( v109 )
              {
                if ( this->mUseForce )
                {
                  hkpEntity::activate(v109);
                  ((void (__fastcall *)(hkpMaxSizeMotion *, __int64, hkArray<unsigned int,hkContainerHeapAllocator> *, hkVector4f *, int))v110->m_motion.vfptr[12].__first_virtual_table_function__)(
                    &v110->m_motion,
                    v111,
                    &v151,
                    &pos,
                    maxImpulse);
                }
                else
                {
                  hkpEntity::activate(v109);
                  ((void (__fastcall *)(hkpMaxSizeMotion *, hkArray<unsigned int,hkContainerHeapAllocator> *, hkVector4f *))v110->m_motion.vfptr[11].__first_virtual_table_function__)(
                    &v110->m_motion,
                    &v151,
                    &pos);
                }
              }
            }
            v112 = LOBYTE(v183);
            if ( v77 )
            {
              m_storage = v77->m_motion.m_type.m_storage;
              if ( m_storage != 5 && m_storage != 4 && !LOBYTE(v183) )
              {
                if ( this->mUseForce == (m_storage == 4) )
                {
                  hkpEntity::activate(v77);
                  ((void (__fastcall *)(hkpMaxSizeMotion *, hkArray<unsigned int,hkContainerHeapAllocator> *, hkVector4f *))v77->m_motion.hkpEntity::vfptr[11].__first_virtual_table_function__)(
                    &v77->m_motion,
                    &v151,
                    &pos);
                }
                else
                {
                  hkpEntity::activate(v77);
                  ((void (__fastcall *)(hkpMaxSizeMotion *, __int64, hkArray<unsigned int,hkContainerHeapAllocator> *, hkVector4f *))v77->m_motion.hkpEntity::vfptr[12].__first_virtual_table_function__)(
                    &v77->m_motion,
                    v114,
                    &v151,
                    &pos);
                }
              }
            }
            v115 = *((_BYTE *)this->mExplosionInfo + 188) & 1;
            if ( v115 )
              v116 = 0.0;
            else
              v116 = *(float *)&adjustedMagnitude;
            if ( v112
              && !v115
              && (!v76
               || ((v117 = v76->m_Flags, (v117 & 0x4000) == 0)
                 ? (v117 >= 0 && (v117 & 0x2000) == 0 && (v117 & 0x1000) == 0
                  ? (v118 = UFG::SimObject::GetComponentOfType(v76, UFG::CharacterEffectsComponent::_TypeUID))
                  : (v118 = UFG::SimObjectGame::GetComponentOfTypeHK(v76, UFG::CharacterEffectsComponent::_TypeUID)))
                 : (v118 = v76->m_Components.p[38].m_pComponent),
                   !v118 || !LOBYTE(v118[1].m_SafePointerList.mNode.mNext))
                ? (v119 = 1)
                : (v119 = 0),
                  v116 > 0.1 && v119 == 1) )
            {
              if ( v76 )
              {
                v120 = v76->m_Flags;
                if ( (v120 & 0x4000) != 0 || v120 < 0 )
                {
                  v121 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v76);
                }
                else if ( (v120 & 0x2000) != 0 )
                {
                  v121 = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectProp *)v76);
                }
                else if ( (v120 & 0x1000) != 0 )
                {
                  v121 = (UFG::CharacterAnimationComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                               v76,
                                                               UFG::CharacterAnimationComponent::_TypeUID);
                }
                else
                {
                  v121 = (UFG::CharacterAnimationComponent *)UFG::SimObject::GetComponentOfType(
                                                               v76,
                                                               UFG::CharacterAnimationComponent::_TypeUID);
                }
                if ( v121 )
                  UFG::CharacterAnimationComponent::ApplyCharredEffect(v121, v116 + 0.15);
                goto LABEL_183;
              }
            }
            else
            {
LABEL_183:
              if ( v76 )
              {
                v122 = v76->m_Flags;
                if ( (v122 & 0x4000) != 0 )
                {
                  v123 = (UFG::HitReactionComponent *)v76->m_Components.p[15].m_pComponent;
                }
                else if ( v122 >= 0 )
                {
                  v124 = (v122 & 0x2000) != 0 || (v122 & 0x1000) != 0
                       ? UFG::SimObjectGame::GetComponentOfTypeHK(v76, UFG::HitReactionComponent::_TypeUID)
                       : UFG::SimObject::GetComponentOfType(v76, UFG::HitReactionComponent::_TypeUID);
                  v123 = (UFG::HitReactionComponent *)v124;
                }
                else
                {
                  v123 = (UFG::HitReactionComponent *)v76->m_Components.p[15].m_pComponent;
                }
                if ( v123 )
                {
                  v125 = FLOAT_100_0;
                  v126 = v76->m_Flags;
                  if ( (v126 & 0x4000) != 0 )
                  {
                    v127 = v76->m_Components.p[6].m_pComponent;
                  }
                  else if ( v126 >= 0 )
                  {
                    if ( (v126 & 0x2000) != 0 || (v126 & 0x1000) != 0 )
                      v127 = UFG::SimObjectGame::GetComponentOfTypeHK(v76, UFG::HealthComponent::_TypeUID);
                    else
                      v127 = UFG::SimObject::GetComponentOfType(v76, UFG::HealthComponent::_TypeUID);
                  }
                  else
                  {
                    v127 = v76->m_Components.p[6].m_pComponent;
                  }
                  if ( v127 )
                    v125 = (float)(int)*(float *)&v127[1].m_NameUID;
                  v128 = (int)(float)(v125 * v116);
                  UFG::HitRecord::HitRecord(&hitrecord);
                  v152 = _mm_sub_ps(pos.m_quad, this->mTransform.m_translation.m_quad);
                  v129 = v152.m128_f32[2];
                  v130 = v152.m128_f32[1];
                  v131 = v152.m128_f32[0];
                  if ( (*((_BYTE *)this->mExplosionInfo + 188) & 1) != 0
                    || *(float *)&adjustedMagnitude < 0.00000011920929 )
                  {
                    v136 = (__m128)v152.m128_u32[1];
                    v136.m128_f32[0] = (float)((float)(v152.m128_f32[1] * v152.m128_f32[1])
                                             + (float)(v152.m128_f32[0] * v152.m128_f32[0]))
                                     + (float)(v152.m128_f32[2] * v152.m128_f32[2]);
                    if ( v136.m128_f32[0] == 0.0 )
                      v137 = 0.0;
                    else
                      v137 = 1.0 / _mm_sqrt_ps(v136).m128_f32[0];
                    v134 = v137 * v152.m128_f32[2];
                    v133 = v137 * v152.m128_f32[1];
                    v132 = v137 * v152.m128_f32[0];
                    m_EnumValue = gAttackCollisionExplosionNoDamage.m_EnumValue;
                  }
                  else
                  {
                    v132 = *(float *)&v151.m_data;
                    v133 = *((float *)&v151.m_data + 1);
                    v134 = *(float *)&v151.m_size;
                    m_EnumValue = gAttackCollisionExplosion.m_EnumValue;
                  }
                  hitrecord.mDamage = v128;
                  hitrecord.mAttackTypeID = m_EnumValue;
                  m_pPointer = this->mAttacker.m_pPointer;
                  if ( hitrecord.mAttacker.m_pPointer )
                  {
                    mPrev = hitrecord.mAttacker.mPrev;
                    mNext = hitrecord.mAttacker.mNext;
                    hitrecord.mAttacker.mPrev->mNext = hitrecord.mAttacker.mNext;
                    mNext->mPrev = mPrev;
                    hitrecord.mAttacker.mPrev = &hitrecord.mAttacker;
                    hitrecord.mAttacker.mNext = &hitrecord.mAttacker;
                  }
                  hitrecord.mAttacker.m_pPointer = m_pPointer;
                  if ( m_pPointer )
                  {
                    v141 = m_pPointer->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev;
                    v141->mNext = &hitrecord.mAttacker;
                    hitrecord.mAttacker.mPrev = v141;
                    hitrecord.mAttacker.mNext = &m_pPointer->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode;
                    m_pPointer->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev = &hitrecord.mAttacker;
                  }
                  *(_QWORD *)&hitrecord.mTimeSinceHit = 0i64;
                  hitrecord.mDistanceFromExplosionSquared = (float)((float)(v130 * v130) + (float)(v131 * v131))
                                                          + (float)(v129 * v129);
                  hitrecord.mExplosionInfo = this->mExplosionInfo;
                  memset(&hitrecord.mCollisionInfo, 0, 32);
                  hitrecord.mCollisionInfo.mHitLocation = UFG::qVector3::msZero;
                  hitrecord.mCollisionInfo.mHitImpulse.x = v132;
                  hitrecord.mCollisionInfo.mHitImpulse.y = v133;
                  hitrecord.mCollisionInfo.mHitImpulse.z = v134;
                  hitrecord.mCollisionInfo.mOtherVelocity = UFG::qVector3::msZero;
                  hitrecord.mCollisionInfo.mSpeed = v75;
                  hitrecord.mCollisionInfo.mForwardSpeed = v75;
                  hitrecord.mCollisionInfo.mEstimatedImpulseMagnitude = -1.0;
                  UFG::HitReactionComponent::HandleHitReaction(v123, &hitrecord);
                  UFG::HitRecord::~HitRecord(&hitrecord);
                }
              }
            }
            if ( v79 )
            {
              vfptr = (UFG::StateMachineComponent *)v79[6].vfptr;
              if ( vfptr )
                UFG::StateMachineComponent::ApplyDamage(vfptr, v116, EXPLOSION_DAMAGE, this->mAttacker.m_pPointer);
            }
            goto LABEL_219;
          }
          m_quad = pos.m_quad;
LABEL_133:
          v93 = _mm_sub_ps(m_quad, this->mTransform.m_translation.m_quad);
          p_m_motion = &v77->m_motion;
LABEL_134:
          v95 = _mm_mul_ps(v93, v93);
          v96 = _mm_add_ps(
                  _mm_shuffle_ps(v95, v95, 170),
                  _mm_add_ps(_mm_shuffle_ps(v95, v95, 85), _mm_shuffle_ps(v95, v95, 0)));
          v97 = _mm_rsqrt_ps(v96);
          LODWORD(v98) = _mm_andnot_ps(
                           _mm_cmple_ps(v96, (__m128)0i64),
                           _mm_mul_ps(
                             v96,
                             _mm_mul_ps(
                               _mm_mul_ps(*(__m128 *)_xmm, v97),
                               _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v97, v96), v97))))).m128_u32[0];
          v97.m128_f32[0] = hkpMotion::getMass(p_m_motion);
          v75 = UFG::ExplosionTypeInfo::GetExplosionMagnitude(
                  this->mExplosionInfo,
                  v97.m128_f32[0],
                  v98,
                  (float *)&adjustedMagnitude);
          v99 = hkpMotion::getMass(p_m_motion);
          if ( v99 <= 0.0 )
          {
            v75 = 0.0;
          }
          else if ( (float)(v75 / v99) > 20.0 )
          {
            v75 = v75 * (float)((float)(v99 * 20.0) / v75);
          }
          if ( this->mUseForce )
            v75 = (float)(v75 / this->mExplosionInfo->mExplosionDuration) * v2;
          goto LABEL_140;
        }
        LOBYTE(v183) = 1;
        v77 = (hkpRigidBody *)m_pComponent[6].m_BoundComponentHandles.mNode.mPrev[2].mPrev;
        pos.m_quad = (__m128)v77->m_motion.m_motionState.m_sweptTransform.m_centerOfMass1;
        v91 = &this->mTransform.m_translation;
        if ( !UFG::ExplosionManager::Explosion::IsBlockedByGeometry(this, v77, &this->mTransform.m_translation, &pos) )
          goto LABEL_129;
      }
LABEL_219:
      ++result.m_enum;
      v74 = ++ratio;
      if ( result.m_enum >= v9 )
        goto LABEL_220;
    }
    v79 = 0i64;
    v80 = 0i64;
    goto LABEL_133;
  }
LABEL_220:
  v143 = this->mTimeRemaining <= 0.0;
  v179 = 0;
  if ( v180 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v178, 16 * v180);
  v178 = 0i64;
  v180 = 0x80000000;
  v175 = 0;
  if ( v176 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v174, 8 * v176);
  v174 = 0i64;
  v176 = 0x80000000;
  v167 = 0;
  if ( v168 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, array, 8 * v168);
  array = 0i64;
  v168 = 0x80000000;
  hkpAllCdBodyPairCollector::~hkpAllCdBodyPairCollector(&collector);
  return v143;
}

// File Line: 1003
// RVA: 0x4645A0
void __fastcall UFG::ExplosionManager::Explosion::FindClosestPointToExplosion(
        UFG::ExplosionManager::Explosion *this,
        hkpRigidBody *body,
        hkVector4f *pos)
{
  char m_storage; // cl
  hkpWorld *m_world; // r10
  hkpProcessCollisionInput *m_collisionInput; // rcx
  void **v8; // [rsp+18h] [rbp-79h] BYREF
  hkVector4f v9; // [rsp+28h] [rbp-69h]
  __m128 v10; // [rsp+38h] [rbp-59h]
  __int64 v11; // [rsp+48h] [rbp-49h]
  __int64 v12; // [rsp+78h] [rbp-19h]
  hkpCollisionDispatcher *v13; // [rsp+88h] [rbp-9h] BYREF
  unsigned int v14; // [rsp+90h] [rbp-1h]
  unsigned int v15; // [rsp+94h] [rbp+3h]
  float v16; // [rsp+98h] [rbp+7h]
  hkpCollisionFilter *v17; // [rsp+A0h] [rbp+Fh]
  hkpConvexListFilter *v18; // [rsp+A8h] [rbp+17h]
  unsigned int v19; // [rsp+B0h] [rbp+1Fh]
  hkpCollisionInput::Aabb32Info m_aabb32Info; // [rsp+B8h] [rbp+27h]

  v12 = -2i64;
  m_storage = body->m_motion.m_type.m_storage;
  if ( m_storage != 5 && m_storage != 4 )
  {
    m_world = body->m_world;
    m_collisionInput = m_world->m_collisionInput;
    v13 = m_collisionInput->m_dispatcher.m_storage;
    v14 = m_collisionInput->m_weldClosestPoints.m_storage;
    v15 = m_collisionInput->m_forceAcceptContactPoints.m_storage;
    v16 = m_collisionInput->m_tolerance.m_storage;
    v17 = m_collisionInput->m_filter.m_storage;
    v18 = m_collisionInput->m_convexListFilter.m_storage;
    v19 = m_collisionInput->m_createPredictiveAgents.m_storage;
    m_aabb32Info = m_collisionInput->m_aabb32Info;
    v16 = FLOAT_10_0;
    v8 = &hkpClosestCdPointCollector::`vftable;
    v11 = 0i64;
    v10 = _mm_shuffle_ps(v10, _mm_unpackhi_ps(v10, (__m128)xmmword_141A712A0), 196);
    ((void (__fastcall *)(hkpCollidable *, hkpLinkedCollidable *, hkpCollisionDispatcher **, void ***, int))m_world->m_collisionDispatcher->m_agent2Func[(unsigned __int8)m_world->m_collisionDispatcher->m_agent2Types[(unsigned __int8)UFG::ExplosionManager::mClosestPointsCollidable->m_shape->m_type.m_storage][(unsigned __int8)body->m_collidable.m_shape->m_type.m_storage]].m_getClosestPointFunc)(
      UFG::ExplosionManager::mClosestPointsCollidable,
      &body->m_collidable,
      &v13,
      &v8,
      2139095022);
    if ( v11 )
    {
      *pos = (hkVector4f)v9.m_quad;
      v8 = &hkpCdPointCollector::`vftable;
      return;
    }
    v8 = &hkpCdPointCollector::`vftable;
  }
  *pos = body->m_motion.m_motionState.m_sweptTransform.m_centerOfMass1;
}

// File Line: 1033
// RVA: 0x46AB40
_BOOL8 __fastcall UFG::ExplosionManager::Explosion::IsBlockedByGeometry(
        UFG::ExplosionManager::Explosion *this,
        hkpRigidBody *body,
        hkVector4f *_start,
        hkVector4f *_end)
{
  unsigned __int64 m_userData; // rsi
  UFG::SimObject *v7; // rbx
  __int64 v8; // rsi
  UFG::SimObject *v9; // rsi
  bool v10; // di
  char v11; // dl
  __int64 v12; // rax
  __int64 v13; // rax
  UFG::SimObject *v14; // rax
  UFG::qReflectObjectType<UFG::PhysicsSurfaceProperties,UFG::qReflectObject> *v15; // rcx
  const char *TypeName; // rax
  __m128 v17; // xmm5
  __m128 v18; // xmm4
  __m128 v19; // xmm4
  __m128 v20; // xmm0
  char v21; // dl
  __int64 v22; // rax
  __int64 v23; // rcx
  UFG::qReflectObjectType<UFG::PhysicsSurfaceProperties,UFG::qReflectObject> *v24; // rcx
  const char *v25; // rax
  hkVector4f rayStart; // [rsp+20h] [rbp-C8h] BYREF
  hkVector4f rayEnd; // [rsp+30h] [rbp-B8h] BYREF
  UFG::qReflectHandleBase v29; // [rsp+40h] [rbp-A8h] BYREF
  __int64 v30; // [rsp+68h] [rbp-80h]
  UFG::RayCastData data; // [rsp+70h] [rbp-78h] BYREF

  v30 = -2i64;
  rayStart.m_quad = _start->m_quad;
  rayEnd.m_quad = _end->m_quad;
  m_userData = body->m_userData;
  v7 = 0i64;
  if ( m_userData && (v8 = *(_QWORD *)(m_userData + 24)) != 0 )
    v9 = *(UFG::SimObject **)(v8 + 40);
  else
    v9 = 0i64;
  v10 = 0;
  rayStart.m_quad.m128_f32[2] = rayStart.m_quad.m128_f32[2] + 0.1;
  rayEnd.m_quad.m128_f32[2] = rayEnd.m_quad.m128_f32[2] + 0.1;
  data.mInput.m_from.m_quad.m128_i8[8] = 0;
  data.mInput.m_from.m_quad.m128_i32[3] = 0;
  data.mInput.m_to.m_quad.m128_u64[0] = 0i64;
  data.mInput.m_userData = (unsigned int)FLOAT_1_0 | 0xFFFFFFFF00000000ui64;
  data.mOutput.m_shapeKeys[2] = 0;
  data.mOutput.m_normal.m_quad.m128_i32[2] = -1;
  *(_QWORD *)&data.mOutput.m_shapeKeys[6] = 0i64;
  *((_QWORD *)&data.mOutput.m_shapeKeyIndex + 1) = "Explosion";
  LODWORD(data.mOutput.m_rootCollidable) = -1;
  UFG::RayCastData::Init(&data, &rayStart, &rayEnd, 0x19u);
  if ( UFG::BasePhysicsSystem::CastRay(UFG::BasePhysicsSystem::mInstance, &data)
    && *(_QWORD *)&data.point.y
    && *(hkpRigidBody **)&data.point.y != body )
  {
    v11 = *(_BYTE *)(*(_QWORD *)&data.point.y + 352i64);
    if ( v11 != 5 && v11 != 4 )
      goto LABEL_19;
    v12 = *(_QWORD *)(*(_QWORD *)&data.point.y + 24i64);
    if ( v12 && (v13 = *(_QWORD *)(v12 + 24)) != 0 )
      v14 = *(UFG::SimObject **)(v13 + 40);
    else
      v14 = 0i64;
    if ( v14 == this->mSource.m_pPointer || v14 == v9 )
      goto LABEL_19;
    UFG::qReflectHandleBase::qReflectHandleBase(&v29);
    TypeName = UFG::qReflectObjectType<UFG::PhysicsSurfaceProperties,UFG::qReflectObject>::GetTypeName(v15);
    v29.mTypeUID = UFG::qStringHash64(TypeName, 0xFFFFFFFFFFFFFFFFui64);
    UFG::qReflectHandleBase::Init(&v29, v29.mTypeUID, (unsigned __int64)data.mHavokPhantom);
    if ( v29.mData )
      v10 = BYTE5(v29.mData[1].mBaseNode.mParent) == 0;
    UFG::qReflectHandleBase::~qReflectHandleBase(&v29);
    if ( !v10 )
    {
LABEL_19:
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
                                _mm_cmple_ps(v19, (__m128)0i64),
                                _mm_mul_ps(
                                  _mm_mul_ps(*(__m128 *)_xmm, v20),
                                  _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v20, v19), v20))))),
                            (__m128)_xmm));
      UFG::RayCastData::Init(&data, &rayStart, &rayEnd, 0x19u);
      if ( UFG::BasePhysicsSystem::CastRay(UFG::BasePhysicsSystem::mInstance, &data) )
      {
        if ( *(_QWORD *)&data.point.y )
        {
          if ( *(hkpRigidBody **)&data.point.y != body )
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
              if ( v7 != this->mSource.m_pPointer && v7 != v9 )
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
void __fastcall UFG::ExplosionManager::Explosion::ComputeExplosionMagnitudeAndRatio(
        UFG::ExplosionManager::Explosion *this,
        hkVector4f *_impulsePos,
        hkVector4f *_explosionPos,
        hkpRigidBody *body,
        float fTime,
        float *adjustedMagnitude,
        float *ratio)
{
  hkpMaxSizeMotion *p_m_motion; // rbx
  __m128 v9; // xmm1
  __m128 v10; // xmm1
  __m128 v11; // xmm2
  __m128 v12; // xmm1
  float Mass; // xmm0_4
  float v14; // xmm0_4

  p_m_motion = &body->m_motion;
  v9 = _mm_sub_ps(_impulsePos->m_quad, _explosionPos->m_quad);
  v10 = _mm_mul_ps(v9, v9);
  v11 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v10, v10, 85), _mm_shuffle_ps(v10, v10, 0)), _mm_shuffle_ps(v10, v10, 170));
  v12 = _mm_rsqrt_ps(v11);
  Mass = hkpMotion::getMass(&body->m_motion);
  *adjustedMagnitude = UFG::ExplosionTypeInfo::GetExplosionMagnitude(
                         this->mExplosionInfo,
                         Mass,
                         _mm_andnot_ps(
                           _mm_cmple_ps(v11, (__m128)0i64),
                           _mm_mul_ps(
                             _mm_mul_ps(
                               _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v12, v11), v12)),
                               _mm_mul_ps(*(__m128 *)_xmm, v12)),
                             v11)).m128_f32[0],
                         ratio);
  v14 = hkpMotion::getMass(p_m_motion);
  if ( v14 <= 0.0 )
  {
    *adjustedMagnitude = 0.0;
  }
  else if ( (float)(*adjustedMagnitude / v14) > 20.0 )
  {
    *adjustedMagnitude = (float)((float)(v14 * 20.0) / *adjustedMagnitude) * *adjustedMagnitude;
  }
  if ( this->mUseForce )
    *adjustedMagnitude = (float)(*adjustedMagnitude / this->mExplosionInfo->mExplosionDuration) * fTime;
}

