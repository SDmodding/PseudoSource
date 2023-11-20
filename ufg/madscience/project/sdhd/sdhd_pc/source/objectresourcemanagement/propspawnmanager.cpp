// File Line: 12
// RVA: 0x4433F0
bool __fastcall UFG::ShouldUmbrellasBeOut()
{
  UFG::TimeOfDayManager *v0; // rax

  v0 = UFG::TimeOfDayManager::GetInstance();
  return UFG::TimeOfDayManager::IsAboutToRain(v0);
}

// File Line: 17
// RVA: 0x4432F0
bool __fastcall UFG::ShouldParasolsBeAway()
{
  return 0.1 > UFG::TimeOfDayManager::GetInstance()->m_WeatherState;
}

// File Line: 22
// RVA: 0x443310
char __fastcall UFG::ShouldUmbrellasBeExcluded(UFG::qPropertySet *spawningPropertySet, UFG::qPropertySet *spawnPointPropertySet)
{
  UFG::qPropertySet *v2; // rsi
  UFG::qPropertySet *v3; // rdi
  UFG::qPropertySet *v4; // rax
  unsigned int *v5; // rbx
  bool *v6; // rbx

  v2 = spawningPropertySet;
  v3 = spawnPointPropertySet;
  v4 = UFG::PropertySetManager::FindPropertySet((UFG::qSymbol *)&qSymbolX_propset_objectUmbrella.mUID);
  v5 = UFG::qPropertySet::Get<unsigned long>(v4, (UFG::qSymbol *)&qSymbol_GlobalSpawnPropability.mUID, DEPTH_RECURSE);
  if ( v5 && (signed int)UFG::qRandom(100, &UFG::qDefaultSeed) < (signed int)*v5 )
    return 1;
  v6 = UFG::qPropertySet::Get<bool>(v2, (UFG::qSymbol *)&qSymbol_Sheltered.mUID, DEPTH_RECURSE);
  if ( v3 )
  {
    if ( UFG::qPropertySet::Get<UFG::qPropertyList>(v3, (UFG::qSymbol *)&SimSym_Links.mUID, DEPTH_RECURSE) )
      return 1;
  }
  if ( !v6 )
  {
    if ( !v3 )
      return 1;
    v6 = UFG::qPropertySet::Get<bool>(v3, (UFG::qSymbol *)&qSymbol_Sheltered.mUID, DEPTH_RECURSE);
    if ( !v6 )
      return 0;
  }
  if ( *v6 != 1 )
    return 0;
  return 1;
}

// File Line: 84
// RVA: 0x436CE0
void __fastcall UFG::PropSpawnManager::PropSpawnManager(UFG::PropSpawnManager *this)
{
  UFG::PropSpawnManager *v1; // rbx
  unsigned int v2; // edi
  unsigned __int64 v3; // rax
  UFG::allocator::free_link *v4; // rsi
  unsigned int i; // er8
  unsigned __int64 v6; // rax
  UFG::allocator::free_link *v7; // rax
  UFG::PropSpawnManager::Excluder **v8; // rsi

  v1 = this;
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
    v4 = UFG::qMalloc(v3, "qArray.Reserve.m_ActiveOverride", 0i64);
    if ( v1->m_ActiveOverride.p )
    {
      for ( i = 0; i < v1->m_ActiveOverride.size; ++i )
        v4[i] = (UFG::allocator::free_link)v1->m_ActiveOverride.p[i];
      operator delete[](v1->m_ActiveOverride.p);
    }
    v1->m_ActiveOverride.p = (UFG::PropSpawnManager::Override **)v4;
    v1->m_ActiveOverride.capacity = 4;
  }
  if ( v1->m_ActiveExcluder.capacity < 4 && v1->m_ActiveExcluder.size != 4 )
  {
    v6 = 32i64;
    if ( !is_mul_ok(4ui64, 8ui64) )
      v6 = -1i64;
    v7 = UFG::qMalloc(v6, "qArray.Reserve.m_ActiveExcluder", 0i64);
    v8 = (UFG::PropSpawnManager::Excluder **)v7;
    if ( v1->m_ActiveExcluder.p )
    {
      if ( v1->m_ActiveExcluder.size )
      {
        do
        {
          v7[v2] = (UFG::allocator::free_link)v1->m_ActiveExcluder.p[v2];
          ++v2;
        }
        while ( v2 < v1->m_ActiveExcluder.size );
      }
      operator delete[](v1->m_ActiveExcluder.p);
    }
    v1->m_ActiveExcluder.p = v8;
    v1->m_ActiveExcluder.capacity = 4;
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
  UFG::PropSpawnManager::Excluder **v1; // rcx
  UFG::PropSpawnManager::Override **v2; // rcx

  v0 = UFG::PropSpawnManager::m_pInstance;
  if ( UFG::PropSpawnManager::m_pInstance )
  {
    v1 = UFG::PropSpawnManager::m_pInstance->m_ActiveExcluder.p;
    if ( v1 )
      operator delete[](v1);
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
UFG::qPropertySet *__fastcall UFG::PropSpawnManager::GetGlobalProp(UFG::PropSpawnManager *this, UFG::qPropertySet *spawningPropertySet, UFG::qPropertySet *spawnPointPropertySet)
{
  __int64 v3; // rbx
  UFG::qPropertySet *v4; // r14
  UFG::qPropertySet *v5; // rbp
  UFG::PropSpawnManager *v6; // rdi
  bool *v7; // rax

  v3 = 0i64;
  v4 = spawnPointPropertySet;
  v5 = spawningPropertySet;
  v6 = this;
  if ( !this->m_ActiveOverride.size )
    return 0i64;
  while ( 1 )
  {
    v7 = UFG::qPropertySet::Get<bool>(v5, v6->m_ActiveOverride.p[v3]->m_CharacterPropertySetFlag, DEPTH_RECURSE);
    if ( v7 )
    {
      if ( *v7 == 1 && !v6->m_ActiveOverride.p[v3]->m_ExclusionCallback(v5, v4) )
        break;
    }
    v3 = (unsigned int)(v3 + 1);
    if ( (unsigned int)v3 >= v6->m_ActiveOverride.size )
      return 0i64;
  }
  return UFG::PropertySetManager::FindPropertySet(v6->m_ActiveOverride.p[v3]->m_PropPropertySet);
}

// File Line: 148
// RVA: 0x444890
void __fastcall UFG::PropSpawnManager::Update(UFG::PropSpawnManager *this)
{
  UFG::PropSpawnManager *v1; // rdi
  unsigned int i; // ebp
  signed __int64 v3; // rbx
  UFG::qPropertySet *v4; // r14
  UFG::PropSpawnManager::Override *v5; // r12
  __int64 v6; // r15
  unsigned int v7; // ebx
  unsigned int v8; // edx
  unsigned int v9; // edx
  unsigned int v10; // er14
  signed __int64 v11; // rbx
  UFG::PropSpawnManager::Excluder *v12; // r12
  __int64 v13; // r15
  unsigned int v14; // esi
  unsigned int v15; // ebx
  unsigned int v16; // ebx
  unsigned __int64 v17; // rax
  UFG::allocator::free_link *v18; // rax
  UFG::PropSpawnManager::Excluder **v19; // rbp
  unsigned int v20; // er9
  void *v21; // r12
  UFG::qSymbol ***v22; // rbx
  __int64 v23; // rbp
  UFG::qPropertySet *v24; // rax
  UFG::qPropertySet *property_set; // rdi
  UFG::ObjectResourceManager *v26; // r15
  UFG::TrueCrowdDataBase *v27; // r14
  UFG::qPropertySet *v28; // rax
  char *v29; // rax
  UFG::qPropertyList *v30; // rsi
  __int64 v31; // rcx
  UFG::qPropertyList *v32; // r11
  __int64 v33; // rcx
  UFG::qPropertyList *textureSetList; // r10
  __int64 v35; // rcx
  UFG::qPropertyList *overrides; // r9
  unsigned int v37; // edx
  unsigned int v38; // ecx
  UFG::TrueCrowdSet *v39; // rax
  __int64 v40; // [rsp+48h] [rbp-40h]
  void *mem; // [rsp+50h] [rbp-38h]

  v1 = this;
  mem = 0i64;
  v40 = 0i64;
  UFG::qArray<UFG::qPropertySet *,0>::Clone(
    (UFG::qArray<UFG::RoadNetworkNode *,0> *)&this->m_ActiveOverride,
    (UFG::qArray<UFG::RoadNetworkNode *,0> *)&v40);
  v1->m_ActiveOverride.size = 0;
  v1->m_ActiveExcluder.size = 0;
  for ( i = 0; i < v1->m_NumOverrides; ++i )
  {
    v3 = i;
    if ( v1->m_PropSpawnOveride[v3].m_ActivationCallback() )
    {
      v4 = UFG::PropertySetManager::FindPropertySet(v1->m_PropSpawnOveride[v3].m_PropPropertySet);
      if ( v4 )
      {
        v5 = &v1->m_PropSpawnOveride[v3];
        v6 = v1->m_ActiveOverride.size;
        v7 = v6 + 1;
        v8 = v1->m_ActiveOverride.capacity;
        if ( (signed int)v6 + 1 > v8 )
        {
          if ( v8 )
            v9 = 2 * v8;
          else
            v9 = 1;
          for ( ; v9 < v7; v9 *= 2 )
            ;
          if ( v9 <= 2 )
            v9 = 2;
          if ( v9 - v7 > 0x10000 )
            v9 = v6 + 65537;
          UFG::qArray<UFG::CompositeDrawableComponent *,32>::Reallocate(
            (UFG::qArray<UFG::qReflectInventoryBase *,0> *)&v1->m_ActiveOverride,
            v9,
            "qArray.Add");
        }
        v1->m_ActiveOverride.size = v7;
        v1->m_ActiveOverride.p[v6] = v5;
        UFG::ObjectResourceManager::PreLoadCriticalResource(UFG::ObjectResourceManager::sInstance, v4);
      }
    }
  }
  v10 = 0;
  if ( v1->m_NumExcluders )
  {
    do
    {
      v11 = v10;
      if ( v1->m_PropSpawnExcluder[v11].m_ActivationCallback() )
      {
        v12 = &v1->m_PropSpawnExcluder[v11];
        v13 = v1->m_ActiveExcluder.size;
        v14 = v13 + 1;
        v15 = v1->m_ActiveExcluder.capacity;
        if ( (signed int)v13 + 1 > v15 )
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
            if ( v1->m_ActiveExcluder.p )
            {
              v20 = 0;
              if ( v1->m_ActiveExcluder.size )
              {
                do
                {
                  v18[v20] = (UFG::allocator::free_link)v1->m_ActiveExcluder.p[v20];
                  ++v20;
                }
                while ( v20 < v1->m_ActiveExcluder.size );
              }
              operator delete[](v1->m_ActiveExcluder.p);
            }
            v1->m_ActiveExcluder.p = v19;
            v1->m_ActiveExcluder.capacity = v16;
          }
        }
        v1->m_ActiveExcluder.size = v14;
        v1->m_ActiveExcluder.p[v13] = v12;
      }
      ++v10;
    }
    while ( v10 < v1->m_NumExcluders );
  }
  v21 = mem;
  if ( (_DWORD)v40 )
  {
    v22 = (UFG::qSymbol ***)mem;
    v23 = (unsigned int)v40;
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
                (UFG::qSymbol *)&component_StreamedResource::sPropertyName.mUID,
                DEPTH_RECURSE);
        if ( v28 )
          v29 = UFG::qPropertySet::GetMemImagePtr(v28);
        else
          v29 = 0i64;
        v30 = (UFG::qPropertyList *)&v29[*(_QWORD *)v29];
        if ( !*(_QWORD *)v29 )
          v30 = 0i64;
        v31 = *((_QWORD *)v29 + 2);
        if ( v31 )
          v32 = (UFG::qPropertyList *)&v29[v31 + 16];
        else
          v32 = 0i64;
        v33 = *((_QWORD *)v29 + 3);
        if ( v33 )
          textureSetList = (UFG::qPropertyList *)&v29[v33 + 24];
        else
          textureSetList = 0i64;
        v35 = *((_QWORD *)v29 + 1);
        if ( v35 )
          overrides = (UFG::qPropertyList *)&v29[v35 + 8];
        else
          overrides = 0i64;
        v37 = 0;
        v38 = v27->mDefinition.mEntityCount;
        if ( v38 )
        {
          while ( v27->mDefinition.mEntities[v37].mNameUID != *((_DWORD *)v29 + 8) )
          {
            if ( ++v37 >= v38 )
              goto LABEL_59;
          }
        }
        else
        {
LABEL_59:
          v37 = -1;
        }
        v39 = (UFG::TrueCrowdSet *)UFG::TrueCrowdDataBase::QueryCharacterDataBase(
                                     v27,
                                     v37,
                                     v30,
                                     v32,
                                     overrides,
                                     textureSetList,
                                     property_set);
        UFG::ResourcePool::ReleasePreload(&v26->mPool, v39, 1u, 1);
      }
      ++v22;
      --v23;
    }
    while ( v23 );
  }
  if ( v21 )
    operator delete[](v21);
}

