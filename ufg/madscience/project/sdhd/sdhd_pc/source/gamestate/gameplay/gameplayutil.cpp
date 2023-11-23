// File Line: 56
// RVA: 0x418F70
char __fastcall UFG::GameplayUtil::ChooseSpawnTarget(UFG::qSymbol *targetNameOut, UFG::qPropertySet *propSet)
{
  UFG::qSymbol *v3; // rax
  UFG::qPropertySet *PropertySet; // rax
  UFG::qPropertySet *v5; // r13
  UFG::qPropertyList *v6; // rax
  unsigned int mNumElements; // r12d
  UFG::qSymbol *p; // rsi
  unsigned int size; // ebx
  unsigned int capacity; // edi
  unsigned int v11; // r14d
  const char *v12; // r15
  bool *v13; // rax
  char *v14; // rcx
  char *v15; // rax
  __int64 v16; // r15
  unsigned int v17; // edx
  UFG::qSymbol v19; // [rsp+20h] [rbp-58h] BYREF
  UFG::qPropertyList *v20; // [rsp+28h] [rbp-50h]
  UFG::qPropertySet *v21; // [rsp+30h] [rbp-48h]
  __int64 v22; // [rsp+38h] [rbp-40h]
  UFG::qArray<UFG::qSymbol,0> v23; // [rsp+40h] [rbp-38h] BYREF
  UFG::qStringBuilder v24; // [rsp+50h] [rbp-28h] BYREF
  UFG::qStringBuilder v25; // [rsp+60h] [rbp-18h] BYREF
  char v27; // [rsp+C8h] [rbp+50h] BYREF
  UFG::qArray<unsigned long,0> result; // [rsp+D0h] [rbp+58h] BYREF

  v22 = -2i64;
  if ( !propSet )
    return 0;
  v3 = UFG::qPropertySet::Get<UFG::qSymbol>(
         propSet,
         (UFG::qArray<unsigned long,0> *)&qSymbol_SpawnTargetType,
         DEPTH_RECURSE);
  if ( !v3 )
    return 0;
  if ( v3->mUID != qSymbol_Character.mUID )
    return 0;
  v21 = UFG::qPropertySet::Get<UFG::qPropertySet>(
          propSet,
          (UFG::qArray<unsigned long,0> *)&qSymbolX_propset_gameplayEnemyTypesAllowed,
          DEPTH_RECURSE);
  if ( !v21 )
    return 0;
  PropertySet = UFG::PropertySetManager::GetPropertySet(&qSymbolX_propset_gameplayEnemyTypes);
  v5 = PropertySet;
  if ( !PropertySet )
    return 0;
  v6 = UFG::qPropertySet::Get<UFG::qPropertyList>(
         PropertySet,
         (UFG::qArray<unsigned long,0> *)&qSymbol_EnemyTypes,
         DEPTH_RECURSE);
  v20 = v6;
  if ( !v6 )
    return 0;
  mNumElements = v6->mNumElements;
  p = 0i64;
  v23.p = 0i64;
  size = 0;
  v23.size = 0;
  capacity = 0;
  v23.capacity = 0;
  if ( mNumElements )
  {
    UFG::qArray<UFG::qSymbol,0>::Reallocate(&v23, mNumElements, "qArray.Reallocate(Reserve)");
    p = v23.p;
    capacity = v23.capacity;
    size = v23.size;
    v6 = v20;
  }
  v11 = 0;
  if ( mNumElements )
  {
    v27 = 0;
    do
    {
      v12 = UFG::qPropertyList::Get<char const *>(v6, v11);
      UFG::qStringBuilder::qStringBuilder(&v24);
      UFG::qStringBuilder::Add(&v24, "EnemyTypeAllowed_", -1);
      UFG::qStringBuilder::Add(&v24, v12, -1);
      UFG::qSymbol::create_from_string((UFG::qSymbol *)&result, v24.mBuffer);
      v13 = UFG::qPropertySet::Get<bool>(v21, &result, DEPTH_RECURSE);
      v14 = &v27;
      if ( v13 )
        v14 = (char *)v13;
      if ( *v14 )
      {
        UFG::qStringBuilder::qStringBuilder(&v25);
        UFG::qStringBuilder::Add(&v25, "CharacterPropSet_", -1);
        UFG::qStringBuilder::Add(&v25, v12, -1);
        UFG::qSymbol::create_from_string((UFG::qSymbol *)&result.p, v25.mBuffer);
        v15 = UFG::qPropertySet::Get<char const *>(v5, (UFG::qArray<unsigned long,0> *)&result.p, DEPTH_RECURSE);
        if ( v15 )
        {
          UFG::qSymbol::create_from_string(&v19, v15);
          v16 = size++;
          if ( size > capacity )
          {
            v17 = 1;
            if ( capacity )
              v17 = 2 * capacity;
            for ( ; v17 < size; v17 *= 2 )
              ;
            if ( v17 <= 4 )
              v17 = 4;
            if ( v17 - size > 0x10000 )
              v17 = size + 0x10000;
            UFG::qArray<UFG::qSymbol,0>::Reallocate(&v23, v17, "qArray.Add");
            p = v23.p;
            capacity = v23.capacity;
          }
          v23.size = size;
          p[v16] = v19;
        }
        UFG::qStringBuilder::~qStringBuilder(&v25);
      }
      UFG::qStringBuilder::~qStringBuilder(&v24);
      ++v11;
      v6 = v20;
    }
    while ( v11 < mNumElements );
  }
  targetNameOut->mUID = (unsigned int)p[(unsigned int)UFG::qRandom(size, (unsigned int *)&UFG::qDefaultSeed)];
  if ( p )
  {
    `eh vector destructor iterator(p, 4ui64, p[-1].mUID, (void (__fastcall *)(void *))_);
    operator delete[](&p[-1]);
  }
  v23.p = 0i64;
  *(_QWORD *)&v23.size = 0i64;
  return 1;
}

// File Line: 158
// RVA: 0x4192D0
__int64 __fastcall UFG::GameplayUtil::GetLocalPlayerOwnerPlayerId()
{
  signed __int16 m_Flags; // dx
  UFG::SimComponent *ComponentOfType; // rax

  if ( LocalPlayer
    && ((m_Flags = LocalPlayer->m_Flags, (m_Flags & 0x4000) == 0)
     && m_Flags >= 0
     && (m_Flags & 0x2000) == 0
     && (m_Flags & 0x1000) == 0
      ? (ComponentOfType = UFG::SimObject::GetComponentOfType(LocalPlayer, UFG::TriadWarsComponent::_TypeUID))
      : (ComponentOfType = UFG::SimObjectGame::GetComponentOfTypeHK(LocalPlayer, UFG::TriadWarsComponent::_TypeUID)),
        ComponentOfType) )
  {
    return LODWORD(ComponentOfType[1].m_BoundComponentHandles.mNode.mPrev);
  }
  else
  {
    return 0i64;
  }
}

