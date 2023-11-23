// File Line: 12
// RVA: 0x4433F0
bool __fastcall UFG::ShouldUmbrellasBeOut()
{
  UFG::TimeOfDayManager *Instance; // rax

  Instance = UFG::TimeOfDayManager::GetInstance();
  return UFG::TimeOfDayManager::IsAboutToRain(Instance);
}

// File Line: 17
// RVA: 0x4432F0
bool __fastcall UFG::ShouldParasolsBeAway()
{
  return UFG::TimeOfDayManager::GetInstance()->m_WeatherState < 0.1;
}

// File Line: 22
// RVA: 0x443310
bool __fastcall UFG::ShouldUmbrellasBeExcluded(
        UFG::qPropertySet *spawningPropertySet,
        UFG::qPropertySet *spawnPointPropertySet)
{
  UFG::qPropertySet *PropertySet; // rax
  unsigned int *v5; // rbx
  bool *v6; // rbx

  PropertySet = UFG::PropertySetManager::FindPropertySet(&qSymbolX_propset_objectUmbrella);
  v5 = UFG::qPropertySet::Get<unsigned long>(
         PropertySet,
         (UFG::qArray<unsigned long,0> *)&qSymbol_GlobalSpawnPropability,
         DEPTH_RECURSE);
  if ( v5 && (int)UFG::qRandom(0x64u, (unsigned int *)&UFG::qDefaultSeed) < (int)*v5 )
    return 1;
  v6 = UFG::qPropertySet::Get<bool>(
         spawningPropertySet,
         (UFG::qArray<unsigned long,0> *)&qSymbol_Sheltered,
         DEPTH_RECURSE);
  if ( spawnPointPropertySet )
  {
    if ( UFG::qPropertySet::Get<UFG::qPropertyList>(
           spawnPointPropertySet,
           (UFG::qArray<unsigned long,0> *)&SimSym_Links,
           DEPTH_RECURSE) )
    {
      return 1;
    }
  }
  if ( !v6 )
  {
    if ( !spawnPointPropertySet )
      return 1;
    v6 = UFG::qPropertySet::Get<bool>(
           spawnPointPropertySet,
           (UFG::qArray<unsigned long,0> *)&qSymbol_Sheltered,
           DEPTH_RECURSE);
    if ( !v6 )
      return 0;
  }
  return *v6;
}

// File Line: 84
// RVA: 0x436CE0
void __fastcall UFG::PropSpawnManager::PropSpawnManager(UFG::PropSpawnManager *this)
{
  unsigned int v2; // edi
  unsigned __int64 v3; // rax
  UFG::PropSpawnManager::Override **v4; // rsi
  unsigned int i; // r8d
  unsigned __int64 v6; // rax
  UFG::allocator::free_link *v7; // rax
  UFG::PropSpawnManager::Excluder **v8; // rsi

  this->m_PropSpawnOveride = g_PropSpawnOveride;
  this->m_PropSpawnExcluder = g_PropSpawnExcluder;
  this->m_NumOverrides = 2;
  *(_QWORD *)&this->m_NumExcluders = 1i64;
  v2 = 0;
  this->m_ActiveOverride.p = 0i64;
  this->m_ActiveOverride.capacity = 0;
  this->m_ActiveExcluder.p = 0i64;
  *(_QWORD *)&this->m_ActiveExcluder.size = 0i64;
  if ( this->m_ActiveOverride.capacity < 4 && this->m_ActiveOverride.size != 4 )
  {
    v3 = 32i64;
    if ( !is_mul_ok(4ui64, 8ui64) )
      v3 = -1i64;
    v4 = (UFG::PropSpawnManager::Override **)UFG::qMalloc(v3, "qArray.Reserve.m_ActiveOverride", 0i64);
    if ( this->m_ActiveOverride.p )
    {
      for ( i = 0; i < this->m_ActiveOverride.size; ++i )
        v4[i] = this->m_ActiveOverride.p[i];
      operator delete[](this->m_ActiveOverride.p);
    }
    this->m_ActiveOverride.p = v4;
    this->m_ActiveOverride.capacity = 4;
  }
  if ( this->m_ActiveExcluder.capacity < 4 && this->m_ActiveExcluder.size != 4 )
  {
    v6 = 32i64;
    if ( !is_mul_ok(4ui64, 8ui64) )
      v6 = -1i64;
    v7 = UFG::qMalloc(v6, "qArray.Reserve.m_ActiveExcluder", 0i64);
    v8 = (UFG::PropSpawnManager::Excluder **)v7;
    if ( this->m_ActiveExcluder.p )
    {
      if ( this->m_ActiveExcluder.size )
      {
        do
        {
          v7[v2] = (UFG::allocator::free_link)this->m_ActiveExcluder.p[v2];
          ++v2;
        }
        while ( v2 < this->m_ActiveExcluder.size );
      }
      operator delete[](this->m_ActiveExcluder.p);
    }
    this->m_ActiveExcluder.p = v8;
    this->m_ActiveExcluder.capacity = 4;
  }
}

// File Line: 90
// RVA: 0x43DBC0
UFG::PropSpawnManager *__fastcall UFG::PropSpawnManager::GetInstance()
{
  return UFG::PropSpawnManager::m_pInstance;
}

// File Line: 95
// RVA: 0x43E120
void UFG::PropSpawnManager::Init(void)
{
  UFG::allocator::free_link *v0; // rax

  if ( !UFG::PropSpawnManager::m_pInstance )
  {
    v0 = UFG::qMalloc(0x38ui64, "PropSpawnManager", 0i64);
    if ( v0 )
      UFG::PropSpawnManager::PropSpawnManager((UFG::PropSpawnManager *)v0);
    UFG::PropSpawnManager::m_pInstance = (UFG::PropSpawnManager *)v0;
  }
}

// File Line: 106
// RVA: 0x43B080
void UFG::PropSpawnManager::DeInit(void)
{
  UFG::PropSpawnManager *v0; // rbx
  UFG::PropSpawnManager::Excluder **p; // rcx
  UFG::PropSpawnManager::Override **v2; // rcx

  v0 = UFG::PropSpawnManager::m_pInstance;
  if ( UFG::PropSpawnManager::m_pInstance )
  {
    p = UFG::PropSpawnManager::m_pInstance->m_ActiveExcluder.p;
    if ( p )
      operator delete[](p);
    v0->m_ActiveExcluder.p = 0i64;
    *(_QWORD *)&v0->m_ActiveExcluder.size = 0i64;
    v2 = v0->m_ActiveOverride.p;
    if ( v2 )
      operator delete[](v2);
    v0->m_ActiveOverride.p = 0i64;
    *(_QWORD *)&v0->m_ActiveOverride.size = 0i64;
    operator delete[](v0);
  }
}

// File Line: 116
// RVA: 0x43DB10
UFG::qPropertySet *__fastcall UFG::PropSpawnManager::GetGlobalProp(
        UFG::PropSpawnManager *this,
        UFG::qPropertySet *spawningPropertySet,
        UFG::qPropertySet *spawnPointPropertySet)
{
  __int64 v3; // rbx
  bool *v7; // rax

  v3 = 0i64;
  if ( !this->m_ActiveOverride.size )
    return 0i64;
  while ( 1 )
  {
    v7 = UFG::qPropertySet::Get<bool>(
           spawningPropertySet,
           (UFG::qArray<unsigned long,0> *)this->m_ActiveOverride.p[v3]->m_CharacterPropertySetFlag,
           DEPTH_RECURSE);
    if ( v7 )
    {
      if ( *v7 && !this->m_ActiveOverride.p[v3]->m_ExclusionCallback(spawningPropertySet, spawnPointPropertySet) )
        break;
    }
    v3 = (unsigned int)(v3 + 1);
    if ( (unsigned int)v3 >= this->m_ActiveOverride.size )
      return 0i64;
  }
  return UFG::PropertySetManager::FindPropertySet(this->m_ActiveOverride.p[v3]->m_PropPropertySet);
}

// File Line: 148
// RVA: 0x444890
void __fastcall UFG::PropSpawnManager::Update(UFG::PropSpawnManager *this)
{
  unsigned int i; // ebp
  __int64 v3; // rbx
  UFG::qPropertySet *PropertySet; // r14
  UFG::PropSpawnManager::Override *v5; // r12
  __int64 size; // r15
  unsigned int v7; // ebx
  unsigned int capacity; // edx
  unsigned int v9; // edx
  unsigned int j; // r14d
  __int64 v11; // rbx
  UFG::PropSpawnManager::Excluder *v12; // r12
  __int64 v13; // r15
  unsigned int v14; // esi
  unsigned int v15; // ebx
  unsigned int v16; // ebx
  unsigned __int64 v17; // rax
  UFG::allocator::free_link *v18; // rax
  UFG::PropSpawnManager::Excluder **v19; // rbp
  unsigned int k; // r9d
  UFG::RoadNetworkNode **p; // r12
  UFG::qSymbol ***v22; // rbx
  __int64 v23; // rbp
  UFG::qPropertySet *v24; // rax
  UFG::qPropertySet *property_set; // rdi
  UFG::ObjectResourceManager *v26; // r15
  UFG::TrueCrowdDataBase *v27; // r14
  UFG::qPropertySet *v28; // rax
  char *MemImagePtr; // rax
  UFG::qPropertyList *v30; // rsi
  __int64 v31; // rcx
  hkMemoryResourceContainer *v32; // r11
  __int64 v33; // rcx
  UFG::qPropertyList *textureSetList; // r10
  __int64 v35; // rcx
  UFG::qPropertyList *overrides; // r9
  unsigned int v37; // edx
  unsigned int mEntityCount; // ecx
  UFG::TrueCrowdSet *CharacterDataBase; // rax
  UFG::qArray<UFG::RoadNetworkNode *,0> v40; // [rsp+48h] [rbp-40h] BYREF

  v40.p = 0i64;
  *(_QWORD *)&v40.size = 0i64;
  UFG::qArray<UFG::qPropertySet *,0>::Clone((UFG::qArray<UFG::RoadNetworkNode *,0> *)&this->m_ActiveOverride, &v40);
  this->m_ActiveOverride.size = 0;
  this->m_ActiveExcluder.size = 0;
  for ( i = 0; i < this->m_NumOverrides; ++i )
  {
    v3 = i;
    if ( this->m_PropSpawnOveride[v3].m_ActivationCallback() )
    {
      PropertySet = UFG::PropertySetManager::FindPropertySet(this->m_PropSpawnOveride[v3].m_PropPropertySet);
      if ( PropertySet )
      {
        v5 = &this->m_PropSpawnOveride[v3];
        size = this->m_ActiveOverride.size;
        v7 = size + 1;
        capacity = this->m_ActiveOverride.capacity;
        if ( (int)size + 1 > capacity )
        {
          if ( capacity )
            v9 = 2 * capacity;
          else
            v9 = 1;
          for ( ; v9 < v7; v9 *= 2 )
            ;
          if ( v9 <= 2 )
            v9 = 2;
          if ( v9 - v7 > 0x10000 )
            v9 = size + 65537;
          UFG::qArray<UFG::CompositeDrawableComponent *,32>::Reallocate(
            (UFG::qArray<UFG::qReflectInventoryBase *,0> *)&this->m_ActiveOverride,
            v9,
            "qArray.Add");
        }
        this->m_ActiveOverride.size = v7;
        this->m_ActiveOverride.p[size] = v5;
        UFG::ObjectResourceManager::PreLoadCriticalResource(UFG::ObjectResourceManager::sInstance, PropertySet);
      }
    }
  }
  for ( j = 0; j < this->m_NumExcluders; ++j )
  {
    v11 = j;
    if ( this->m_PropSpawnExcluder[v11].m_ActivationCallback() )
    {
      v12 = &this->m_PropSpawnExcluder[v11];
      v13 = this->m_ActiveExcluder.size;
      v14 = v13 + 1;
      v15 = this->m_ActiveExcluder.capacity;
      if ( (int)v13 + 1 > v15 )
      {
        if ( v15 )
          v16 = 2 * v15;
        else
          v16 = 1;
        for ( ; v16 < v14; v16 *= 2 )
          ;
        if ( v16 <= 2 )
          v16 = 2;
        if ( v16 - v14 > 0x10000 )
          v16 = v13 + 65537;
        if ( v16 != (_DWORD)v13 )
        {
          v17 = 8i64 * v16;
          if ( !is_mul_ok(v16, 8ui64) )
            v17 = -1i64;
          v18 = UFG::qMalloc(v17, "qArray.Add", 0i64);
          v19 = (UFG::PropSpawnManager::Excluder **)v18;
          if ( this->m_ActiveExcluder.p )
          {
            for ( k = 0; k < this->m_ActiveExcluder.size; ++k )
              v18[k] = (UFG::allocator::free_link)this->m_ActiveExcluder.p[k];
            operator delete[](this->m_ActiveExcluder.p);
          }
          this->m_ActiveExcluder.p = v19;
          this->m_ActiveExcluder.capacity = v16;
        }
      }
      this->m_ActiveExcluder.size = v14;
      this->m_ActiveExcluder.p[v13] = v12;
    }
  }
  p = v40.p;
  if ( v40.size )
  {
    v22 = (UFG::qSymbol ***)v40.p;
    v23 = v40.size;
    do
    {
      v24 = UFG::PropertySetManager::FindPropertySet(**v22);
      property_set = v24;
      if ( v24 )
      {
        v26 = UFG::ObjectResourceManager::sInstance;
        v27 = UFG::TrueCrowdDataBase::sTrueCrowdDataBase;
        v28 = UFG::qPropertySet::Get<UFG::qPropertySet>(
                v24,
                (UFG::qArray<unsigned long,0> *)&component_StreamedResource::sPropertyName,
                DEPTH_RECURSE);
        if ( v28 )
          MemImagePtr = UFG::qPropertySet::GetMemImagePtr(v28);
        else
          MemImagePtr = 0i64;
        v30 = (UFG::qPropertyList *)&MemImagePtr[*(_QWORD *)MemImagePtr];
        if ( !*(_QWORD *)MemImagePtr )
          v30 = 0i64;
        v31 = *((_QWORD *)MemImagePtr + 2);
        if ( v31 )
          v32 = (hkMemoryResourceContainer *)&MemImagePtr[v31 + 16];
        else
          v32 = 0i64;
        v33 = *((_QWORD *)MemImagePtr + 3);
        if ( v33 )
          textureSetList = (UFG::qPropertyList *)&MemImagePtr[v33 + 24];
        else
          textureSetList = 0i64;
        v35 = *((_QWORD *)MemImagePtr + 1);
        if ( v35 )
          overrides = (UFG::qPropertyList *)&MemImagePtr[v35 + 8];
        else
          overrides = 0i64;
        v37 = 0;
        mEntityCount = v27->mDefinition.mEntityCount;
        if ( mEntityCount )
        {
          while ( v27->mDefinition.mEntities[v37].mNameUID != *((_DWORD *)MemImagePtr + 8) )
          {
            if ( ++v37 >= mEntityCount )
              goto LABEL_59;
          }
        }
        else
        {
LABEL_59:
          v37 = -1;
        }
        CharacterDataBase = (UFG::TrueCrowdSet *)UFG::TrueCrowdDataBase::QueryCharacterDataBase(
                                                   v27,
                                                   v37,
                                                   v30,
                                                   v32,
                                                   overrides,
                                                   textureSetList,
                                                   property_set);
        UFG::ResourcePool::ReleasePreload(&v26->mPool, CharacterDataBase, 1u, 1);
      }
      ++v22;
      --v23;
    }
    while ( v23 );
  }
  if ( p )
    operator delete[](p);
}

