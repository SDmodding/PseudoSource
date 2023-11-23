// File Line: 29
// RVA: 0x155EB80
__int64 UFG::_dynamic_initializer_for__sSubfolders__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("subfolders", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&sSubfolders, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__sSubfolders__);
}

// File Line: 30
// RVA: 0x155EA80
__int64 UFG::_dynamic_initializer_for__sArchetypes__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("archetypes", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&sArchetypes, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__sArchetypes__);
}

// File Line: 31
// RVA: 0x155EAC0
__int64 UFG::_dynamic_initializer_for__sArchetypesGrouped__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("archetypesGrouped", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&sArchetypesGrouped, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__sArchetypesGrouped__);
}

// File Line: 32
// RVA: 0x155EA40
__int64 UFG::_dynamic_initializer_for__sAddToResourcecache__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("AddToResourceCache", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&sAddToResourcecache, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__sAddToResourcecache__);
}

// File Line: 33
// RVA: 0x155EB00
__int64 UFG::_dynamic_initializer_for__sCharacter__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("character", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&sCharacter, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__sCharacter__);
}

// File Line: 34
// RVA: 0x155EBC0
__int64 UFG::_dynamic_initializer_for__sVehicle__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("vehicle", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&sVehicle, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__sVehicle__);
}

// File Line: 35
// RVA: 0x155EB40
__int64 UFG::_dynamic_initializer_for__sProp__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("prop", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&sProp, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__sProp__);
}

// File Line: 36
// RVA: 0x155EC00
__int64 UFG::_dynamic_initializer_for__sWeapon__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("weapon", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&sWeapon, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__sWeapon__);
}

// File Line: 90
// RVA: 0x5B1F60
void __fastcall UFG::SpawnResourceInfoCache::~SpawnResourceInfoCache(UFG::SpawnResourceInfoCache *this)
{
  unsigned int i; // esi
  UFG::SpawnResourceInfoCache::CachedResource **p; // rcx
  UFG::qPropertySet **v4; // rcx
  UFG::qPropertySet **v5; // rcx
  UFG::qPropertySet **v6; // rcx
  UFG::SpawnResourceInfoCache::CachedResource **v7; // rcx

  this->mpCharacterResources = 0i64;
  this->mpVehicleResources = 0i64;
  this->mpPropResources = 0i64;
  this->mpWeaponResources = 0i64;
  for ( i = 0; i < this->mCachedResources.size; ++i )
  {
    operator delete[](this->mCachedResources.p[i]->mppResources);
    this->mCachedResources.p[i]->mppResources = 0i64;
  }
  p = this->mCachedResources.p;
  if ( p )
    operator delete[](p);
  this->mCachedResources.p = 0i64;
  *(_QWORD *)&this->mCachedResources.size = 0i64;
  v4 = this->mVehicleSpawnSet.p;
  if ( v4 )
    operator delete[](v4);
  this->mVehicleSpawnSet.p = 0i64;
  *(_QWORD *)&this->mVehicleSpawnSet.size = 0i64;
  v5 = this->mTimeSet.p;
  if ( v5 )
    operator delete[](v5);
  this->mTimeSet.p = 0i64;
  *(_QWORD *)&this->mTimeSet.size = 0i64;
  v6 = this->mSpawnSet.p;
  if ( v6 )
    operator delete[](v6);
  this->mSpawnSet.p = 0i64;
  *(_QWORD *)&this->mSpawnSet.size = 0i64;
  v7 = this->mCachedResources.p;
  if ( v7 )
    operator delete[](v7);
  this->mCachedResources.p = 0i64;
  *(_QWORD *)&this->mCachedResources.size = 0i64;
}

// File Line: 254
// RVA: 0x5B4350
void UFG::SpawnResourceInfoCache::Init(void)
{
  UFG::allocator::free_link *v0; // rax
  UFG::qSymbol *v1; // rax
  UFG::SpawnResourceInfoCache *v2; // rbx
  UFG::qPropertySet *PropertySet; // rax
  UFG::PropertySetHandle v4; // [rsp+28h] [rbp-20h] BYREF
  UFG::allocator::free_link *result; // [rsp+50h] [rbp+8h] BYREF
  __int64 *p_result; // [rsp+58h] [rbp+10h]

  v0 = UFG::qMalloc(0x68ui64, "SpawnResourceInfoCache", 0i64);
  result = v0;
  if ( v0 )
  {
    v0[1].mNext = 0i64;
    v0->mNext = 0i64;
    v0[8].mNext = 0i64;
    v0[7].mNext = 0i64;
    v0[10].mNext = 0i64;
    v0[9].mNext = 0i64;
    v0[12].mNext = 0i64;
    v0[11].mNext = 0i64;
  }
  else
  {
    v0 = 0i64;
  }
  UFG::SpawnResourceInfoCache::mInstance = (UFG::SpawnResourceInfoCache *)v0;
  if ( v0 )
  {
    p_result = (__int64 *)&result;
    v1 = UFG::qSymbol::create_from_string((UFG::qSymbol *)&result, "object-manifest");
    v2 = UFG::SpawnResourceInfoCache::mInstance;
    PropertySet = UFG::PropertySetManager::GetPropertySet(v1);
    UFG::PropertySetHandle::PropertySetHandle(&v4, PropertySet);
    UFG::PropertySetHandle::Bind(&v4);
    UFG::SpawnResourceInfoCache::InitCachedResources(v2, v4.mpPropSet, 0i64, 0);
    UFG::PropertySetHandle::~PropertySetHandle(&v4);
    UFG::SpawnResourceInfoCache::InitSpawnSetInfo(UFG::SpawnResourceInfoCache::mInstance);
    UFG::SpawnResourceInfoCache::InitTimeSetInfo(UFG::SpawnResourceInfoCache::mInstance);
    UFG::SpawnResourceInfoCache::InitVehicleSpawnSetInfo(UFG::SpawnResourceInfoCache::mInstance);
  }
}

// File Line: 291
// RVA: 0x5B4450
void __fastcall UFG::SpawnResourceInfoCache::InitCachedResources(
        UFG::SpawnResourceInfoCache *this,
        UFG::qPropertySet *pSet,
        UFG::SpawnResourceInfoCache::CachedResource *_pParentRes,
        bool _addToCache)
{
  UFG::SpawnResourceInfoCache::CachedResource *v4; // rdi
  UFG::SpawnResourceInfoCache *v5; // rsi
  UFG::SpawnResourceInfoCache::CachedResource *v6; // rbx
  bool *v7; // rax
  bool *v8; // r9
  int v9; // ebp
  UFG::allocator::free_link *v10; // rax
  UFG::qPropertyList *v11; // rax
  unsigned __int64 mNumElements; // rcx
  unsigned __int64 v13; // rax
  __int64 v14; // rdi
  UFG::qPropertyList *v15; // rsi
  UFG::qSymbol *v16; // rax
  UFG::qArray<UFG::qReflectInventoryBase *,0> *p_mCachedResources; // rbp
  unsigned int size; // eax
  unsigned int v19; // edi
  unsigned int capacity; // edx
  unsigned int v21; // edx
  __int64 v22; // rbp
  unsigned int v23; // edi
  unsigned int v24; // edx
  unsigned int v25; // edx
  unsigned int mUID; // eax
  UFG::qPropertyList *v27; // rax
  unsigned int v28; // ebp
  unsigned int i; // edi
  char *ValuePtr; // rax
  __int64 v31; // rcx
  UFG::qPropertyList *v32; // rax
  UFG::qPropertyList *v33; // rbp
  unsigned int j; // edi
  char *v35; // rax
  UFG::qPropertySet *v36; // rdx
  bool v37; // [rsp+20h] [rbp-38h] BYREF
  UFG::qPropertyList *v38; // [rsp+28h] [rbp-30h]
  __int64 v39; // [rsp+30h] [rbp-28h]
  unsigned int v43; // [rsp+70h] [rbp+18h]
  UFG::qPropertyList *v44; // [rsp+70h] [rbp+18h]
  unsigned int v45; // [rsp+70h] [rbp+18h]

  v39 = -2i64;
  v4 = _pParentRes;
  v5 = this;
  v6 = 0i64;
  v37 = 0;
  v7 = UFG::qPropertySet::Get<bool>(pSet, (UFG::qArray<unsigned long,0> *)&sAddToResourcecache, DEPTH_RECURSE);
  v8 = &v37;
  if ( v7 )
    v8 = v7;
  v37 = *v8;
  if ( v37 )
  {
    v9 = 0;
    v10 = UFG::qMalloc(0x20ui64, "CachedResource", 0i64);
    v6 = (UFG::SpawnResourceInfoCache::CachedResource *)v10;
    v38 = (UFG::qPropertyList *)v10;
    if ( v10 )
    {
      LODWORD(v10->mNext) = -1;
      v10[3].mNext = 0i64;
      v10[2].mNext = 0i64;
    }
    else
    {
      v6 = 0i64;
    }
    v6->mResourceId.mUID = pSet->mName.mUID;
    v6->mResourceCount = 0;
    v6->mppResources = 0i64;
    v11 = UFG::qPropertySet::Get<UFG::qPropertyList>(pSet, (UFG::qArray<unsigned long,0> *)&sArchetypes, DEPTH_RECURSE);
    v38 = v11;
    if ( v11 )
    {
      mNumElements = v11->mNumElements;
      v6->mResourceCount = mNumElements;
      v13 = 8 * mNumElements;
      if ( !is_mul_ok(mNumElements, 8ui64) )
        v13 = -1i64;
      v6->mppResources = (UFG::qPropertySet **)UFG::qMalloc(v13, "PropertySet*", 0i64);
      v14 = 0i64;
      if ( v6->mResourceCount )
      {
        v15 = v38;
        do
        {
          v16 = UFG::qPropertyList::Get<UFG::qSymbol>(v15, v14);
          v6->mppResources[v14] = UFG::PropertySetManager::GetPropertySet(v16);
          ++v9;
          v14 = (unsigned int)(v14 + 1);
        }
        while ( (unsigned int)v14 < v6->mResourceCount );
        v5 = this;
      }
      v4 = _pParentRes;
    }
    if ( v9 == v6->mResourceCount )
    {
      if ( v4 )
      {
        p_mCachedResources = (UFG::qArray<UFG::qReflectInventoryBase *,0> *)&v4->mCachedResources;
        size = v4->mCachedResources.size;
        v43 = size;
        v19 = size + 1;
        capacity = p_mCachedResources->capacity;
        if ( size + 1 > capacity )
        {
          if ( capacity )
            v21 = 2 * capacity;
          else
            v21 = 1;
          for ( ; v21 < v19; v21 *= 2 )
            ;
          if ( v21 <= 2 )
            v21 = 2;
          if ( v21 - v19 > 0x10000 )
            v21 = size + 65537;
          UFG::qArray<UFG::CompositeDrawableComponent *,32>::Reallocate(p_mCachedResources, v21, "qArray.Add");
          size = v43;
        }
        p_mCachedResources->size = v19;
        p_mCachedResources->p[size] = (UFG::qReflectInventoryBase *)v6;
      }
      else
      {
        v22 = v5->mCachedResources.size;
        v23 = v22 + 1;
        v24 = v5->mCachedResources.capacity;
        if ( (int)v22 + 1 > v24 )
        {
          if ( v24 )
            v25 = 2 * v24;
          else
            v25 = 1;
          for ( ; v25 < v23; v25 *= 2 )
            ;
          if ( v25 <= 2 )
            v25 = 2;
          if ( v25 - v23 > 0x10000 )
            v25 = v22 + 65537;
          UFG::qArray<UFG::CompositeDrawableComponent *,32>::Reallocate(
            (UFG::qArray<UFG::qReflectInventoryBase *,0> *)v5,
            v25,
            "qArray.Add");
        }
        v5->mCachedResources.size = v23;
        v5->mCachedResources.p[v22] = v6;
      }
      mUID = v6->mResourceId.mUID;
      if ( v6->mResourceId.mUID == sCharacter.mUID )
      {
        v5->mpCharacterResources = v6;
      }
      else if ( mUID == sVehicle.mUID )
      {
        v5->mpVehicleResources = v6;
      }
      else if ( mUID == sProp.mUID )
      {
        v5->mpPropResources = v6;
      }
      else if ( mUID == sWeapon.mUID )
      {
        v5->mpWeaponResources = v6;
      }
    }
    v27 = UFG::qPropertySet::Get<UFG::qPropertyList>(
            pSet,
            (UFG::qArray<unsigned long,0> *)&sArchetypesGrouped,
            DEPTH_RECURSE);
    v44 = v27;
    if ( v27 )
    {
      v28 = v27->mNumElements;
      for ( i = 0; i < v28; v27 = v44 )
      {
        ValuePtr = UFG::qPropertyList::GetValuePtr(v27, 0x1Au, i);
        if ( ValuePtr )
        {
          v31 = *(_QWORD *)ValuePtr;
          if ( *(_QWORD *)ValuePtr )
          {
            if ( &ValuePtr[v31] )
              UFG::SpawnResourceInfoCache::InitCachedResources(v5, (UFG::qPropertySet *)&ValuePtr[v31], v6, v37);
          }
        }
        ++i;
      }
    }
  }
  v32 = UFG::qPropertySet::Get<UFG::qPropertyList>(pSet, (UFG::qArray<unsigned long,0> *)&sSubfolders, DEPTH_RECURSE);
  v33 = v32;
  if ( v32 )
  {
    v45 = v32->mNumElements;
    for ( j = 0; j < v45; ++j )
    {
      v35 = UFG::qPropertyList::GetValuePtr(v33, 0x1Au, j);
      if ( v35 && *(_QWORD *)v35 )
        v36 = (UFG::qPropertySet *)&v35[*(_QWORD *)v35];
      else
        v36 = 0i64;
      UFG::SpawnResourceInfoCache::InitCachedResources(v5, v36, v6, 0);
    }
  }
}

// File Line: 414
// RVA: 0x5B4770
void __fastcall UFG::SpawnResourceInfoCache::InitSpawnSetInfo(UFG::SpawnResourceInfoCache *this)
{
  UFG::qSymbol *v2; // rax
  UFG::qPropertySet *PropertySet; // rax
  UFG::qPropertyList *v4; // rax
  UFG::qPropertyList *v5; // r13
  unsigned int mNumElements; // r15d
  unsigned int i; // edi
  UFG::qPropertySet *v8; // r14
  __int64 size; // rbp
  unsigned int capacity; // edx
  unsigned int v11; // ebx
  unsigned int v12; // edx
  UFG::qPropertySet **p; // rax
  UFG::qSymbol result; // [rsp+58h] [rbp+10h] BYREF

  v2 = UFG::qSymbol::create_from_string(&result, "default-spawnset-manifest");
  PropertySet = UFG::PropertySetManager::GetPropertySet(v2);
  if ( PropertySet )
  {
    v4 = UFG::qPropertySet::Get<UFG::qPropertyList>(
           PropertySet,
           (UFG::qArray<unsigned long,0> *)&sArchetypes,
           DEPTH_RECURSE);
    v5 = v4;
    if ( v4 )
    {
      mNumElements = v4->mNumElements;
      for ( i = 0; i < mNumElements; ++i )
      {
        result.mUID = UFG::qPropertyList::Get<UFG::qSymbol>(v5, i)->mUID;
        v8 = UFG::PropertySetManager::GetPropertySet(&result);
        if ( v8 )
        {
          size = this->mSpawnSet.size;
          capacity = this->mSpawnSet.capacity;
          v11 = size + 1;
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
            UFG::qArray<UFG::CompositeDrawableComponent *,32>::Reallocate(
              (UFG::qArray<UFG::qReflectInventoryBase *,0> *)&this->mSpawnSet,
              v12,
              "mSpawnSet");
          }
          p = this->mSpawnSet.p;
          this->mSpawnSet.size = v11;
          p[size] = v8;
        }
      }
    }
  }
}

// File Line: 447
// RVA: 0x5B48B0
void __fastcall UFG::SpawnResourceInfoCache::InitTimeSetInfo(UFG::SpawnResourceInfoCache *this)
{
  UFG::qSymbol *v2; // rax
  UFG::qPropertySet *PropertySet; // rax
  UFG::qPropertyList *v4; // rax
  UFG::qPropertyList *v5; // r13
  unsigned int mNumElements; // r15d
  unsigned int i; // edi
  UFG::qPropertySet *v8; // r14
  __int64 size; // rbp
  unsigned int capacity; // edx
  unsigned int v11; // ebx
  unsigned int v12; // edx
  UFG::qPropertySet **p; // rax
  UFG::qSymbol result; // [rsp+58h] [rbp+10h] BYREF

  v2 = UFG::qSymbol::create_from_string(&result, "default-timeset-manifest");
  PropertySet = UFG::PropertySetManager::GetPropertySet(v2);
  if ( PropertySet )
  {
    v4 = UFG::qPropertySet::Get<UFG::qPropertyList>(
           PropertySet,
           (UFG::qArray<unsigned long,0> *)&sArchetypes,
           DEPTH_RECURSE);
    v5 = v4;
    if ( v4 )
    {
      mNumElements = v4->mNumElements;
      for ( i = 0; i < mNumElements; ++i )
      {
        result.mUID = UFG::qPropertyList::Get<UFG::qSymbol>(v5, i)->mUID;
        v8 = UFG::PropertySetManager::GetPropertySet(&result);
        if ( v8 )
        {
          size = this->mTimeSet.size;
          capacity = this->mTimeSet.capacity;
          v11 = size + 1;
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
            UFG::qArray<UFG::CompositeDrawableComponent *,32>::Reallocate(
              (UFG::qArray<UFG::qReflectInventoryBase *,0> *)&this->mTimeSet,
              v12,
              "mTimeSet");
          }
          p = this->mTimeSet.p;
          this->mTimeSet.size = v11;
          p[size] = v8;
        }
      }
    }
  }
}

// File Line: 480
// RVA: 0x5B49F0
void __fastcall UFG::SpawnResourceInfoCache::InitVehicleSpawnSetInfo(UFG::SpawnResourceInfoCache *this)
{
  UFG::qSymbol *v2; // rax
  UFG::qPropertySet *PropertySet; // rax
  UFG::qPropertyList *v4; // rax
  UFG::qPropertyList *v5; // r13
  unsigned int mNumElements; // r15d
  unsigned int i; // edi
  UFG::qPropertySet *v8; // r14
  __int64 size; // rbp
  unsigned int capacity; // edx
  unsigned int v11; // ebx
  unsigned int v12; // edx
  UFG::qPropertySet **p; // rax
  UFG::qSymbol result; // [rsp+58h] [rbp+10h] BYREF

  v2 = UFG::qSymbol::create_from_string(&result, "default-vehiclespawnset-manifest");
  PropertySet = UFG::PropertySetManager::GetPropertySet(v2);
  if ( PropertySet )
  {
    v4 = UFG::qPropertySet::Get<UFG::qPropertyList>(
           PropertySet,
           (UFG::qArray<unsigned long,0> *)&sArchetypes,
           DEPTH_RECURSE);
    v5 = v4;
    if ( v4 )
    {
      mNumElements = v4->mNumElements;
      for ( i = 0; i < mNumElements; ++i )
      {
        result.mUID = UFG::qPropertyList::Get<UFG::qSymbol>(v5, i)->mUID;
        v8 = UFG::PropertySetManager::GetPropertySet(&result);
        if ( v8 )
        {
          size = this->mVehicleSpawnSet.size;
          capacity = this->mVehicleSpawnSet.capacity;
          v11 = size + 1;
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
            UFG::qArray<UFG::CompositeDrawableComponent *,32>::Reallocate(
              (UFG::qArray<UFG::qReflectInventoryBase *,0> *)&this->mVehicleSpawnSet,
              v12,
              "mVehicleSpawnSet");
          }
          p = this->mVehicleSpawnSet.p;
          this->mVehicleSpawnSet.size = v11;
          p[size] = v8;
        }
      }
    }
  }
}

// File Line: 535
// RVA: 0x5B5760
void UFG::SpawnResourceInfoCache::Release(void)
{
  UFG::SpawnResourceInfoCache *v0; // rbx

  v0 = UFG::SpawnResourceInfoCache::mInstance;
  if ( UFG::SpawnResourceInfoCache::mInstance )
  {
    UFG::SpawnResourceInfoCache::~SpawnResourceInfoCache(UFG::SpawnResourceInfoCache::mInstance);
    operator delete[](v0);
  }
  UFG::SpawnResourceInfoCache::mInstance = 0i64;
}

