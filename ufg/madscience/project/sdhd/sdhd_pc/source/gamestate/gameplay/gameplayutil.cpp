// File Line: 56
// RVA: 0x418F70
char __fastcall UFG::GameplayUtil::ChooseSpawnTarget(UFG::qSymbol *targetNameOut, UFG::qPropertySet *propSet)
{
  UFG::qPropertySet *v2; // rbx
  UFG::qSymbol *v3; // rax
  UFG::qPropertySet *v4; // rax
  UFG::qPropertySet *v5; // r13
  UFG::qPropertyList *v6; // rax
  unsigned int v7; // er12
  UFG::qSymbol *v8; // rsi
  unsigned int v9; // ebx
  unsigned int v10; // edi
  unsigned int v11; // er14
  const char *v12; // r15
  bool *v13; // rax
  char *v14; // rcx
  char *v15; // rax
  __int64 v16; // r15
  unsigned int v17; // edx
  UFG::qSymbol v19; // [rsp+20h] [rbp-58h]
  UFG::qPropertyList *v20; // [rsp+28h] [rbp-50h]
  UFG::qPropertySet *v21; // [rsp+30h] [rbp-48h]
  __int64 v22; // [rsp+38h] [rbp-40h]
  UFG::qArray<UFG::qSymbol,0> v23; // [rsp+40h] [rbp-38h]
  UFG::qStringBuilder v24; // [rsp+50h] [rbp-28h]
  UFG::qStringBuilder v25; // [rsp+60h] [rbp-18h]
  UFG::qSymbol *v26; // [rsp+C0h] [rbp+48h]
  char v27; // [rsp+C8h] [rbp+50h]
  UFG::qSymbol result; // [rsp+D0h] [rbp+58h]
  UFG::qSymbol name; // [rsp+D8h] [rbp+60h]

  v26 = targetNameOut;
  v22 = -2i64;
  v2 = propSet;
  if ( !propSet )
    return 0;
  v3 = UFG::qPropertySet::Get<UFG::qSymbol>(propSet, (UFG::qSymbol *)&qSymbol_SpawnTargetType.mUID, DEPTH_RECURSE);
  if ( !v3 )
    return 0;
  if ( v3->mUID != qSymbol_Character.mUID )
    return 0;
  v21 = UFG::qPropertySet::Get<UFG::qPropertySet>(
          v2,
          (UFG::qSymbol *)&qSymbolX_propset_gameplayEnemyTypesAllowed.mUID,
          DEPTH_RECURSE);
  if ( !v21 )
    return 0;
  v4 = UFG::PropertySetManager::GetPropertySet((UFG::qSymbol *)&qSymbolX_propset_gameplayEnemyTypes.mUID);
  v5 = v4;
  if ( !v4 )
    return 0;
  v6 = UFG::qPropertySet::Get<UFG::qPropertyList>(v4, (UFG::qSymbol *)&qSymbol_EnemyTypes.mUID, DEPTH_RECURSE);
  v20 = v6;
  if ( !v6 )
    return 0;
  v7 = v6->mNumElements;
  v8 = 0i64;
  v23.p = 0i64;
  v9 = 0;
  v23.size = 0;
  v10 = 0;
  v23.capacity = 0;
  if ( v7 )
  {
    UFG::qArray<UFG::qSymbol,0>::Reallocate(&v23, v7, "qArray.Reallocate(Reserve)");
    v8 = v23.p;
    v10 = v23.capacity;
    v9 = v23.size;
    v6 = v20;
  }
  v11 = 0;
  if ( v7 )
  {
    v27 = 0;
    do
    {
      v12 = UFG::qPropertyList::Get<char const *>(v6, v11);
      UFG::qStringBuilder::qStringBuilder(&v24);
      UFG::qStringBuilder::Add(&v24, "EnemyTypeAllowed_", -1);
      UFG::qStringBuilder::Add(&v24, v12, -1);
      UFG::qSymbol::create_from_string(&result, v24.mBuffer);
      v13 = UFG::qPropertySet::Get<bool>(v21, &result, DEPTH_RECURSE);
      v14 = &v27;
      if ( v13 )
        v14 = (char *)v13;
      if ( *v14 )
      {
        UFG::qStringBuilder::qStringBuilder(&v25);
        UFG::qStringBuilder::Add(&v25, "CharacterPropSet_", -1);
        UFG::qStringBuilder::Add(&v25, v12, -1);
        UFG::qSymbol::create_from_string(&name, v25.mBuffer);
        v15 = UFG::qPropertySet::Get<char const *>(v5, &name, DEPTH_RECURSE);
        if ( v15 )
        {
          UFG::qSymbol::create_from_string(&v19, v15);
          v16 = v9++;
          if ( v9 > v10 )
          {
            v17 = 1;
            if ( v10 )
              v17 = 2 * v10;
            for ( ; v17 < v9; v17 *= 2 )
              ;
            if ( v17 <= 4 )
              v17 = 4;
            if ( v17 - v9 > 0x10000 )
              v17 = v9 + 0x10000;
            UFG::qArray<UFG::qSymbol,0>::Reallocate(&v23, v17, "qArray.Add");
            v8 = v23.p;
            v10 = v23.capacity;
          }
          v23.size = v9;
          v8[v16] = v19;
        }
        UFG::qStringBuilder::~qStringBuilder(&v25);
      }
      UFG::qStringBuilder::~qStringBuilder(&v24);
      ++v11;
      v6 = v20;
    }
    while ( v11 < v7 );
  }
  v26->mUID = (unsigned int)v8[(unsigned int)UFG::qRandom(v9, &UFG::qDefaultSeed)];
  if ( v8 )
  {
    `eh vector destructor iterator(v8, 4ui64, v8[-1].mUID, (void (__fastcall *)(void *))_);
    operator delete[](&v8[-1]);
  }
  v23.p = 0i64;
  *(_QWORD *)&v23.size = 0i64;
  return 1;
} (__fastcall *)(void *))_);
    operator delete[](&v8[-1]);
  }
  v23.p = 0i64;
  *(_QWORD *)&v23.size = 0i64;
  re

// File Line: 158
// RVA: 0x4192D0
__int64 __fastcall UFG::GameplayUtil::GetLocalPlayerOwnerPlayerId()
{
  unsigned __int16 v0; // dx
  UFG::SimComponent *v1; // rax
  __int64 result; // rax

  if ( LocalPlayer
    && ((v0 = LocalPlayer->m_Flags, !((v0 >> 14) & 1)) ? ((v0 & 0x8000u) == 0 ? (!((v0 >> 13) & 1) ? (!((v0 >> 12) & 1) ? (v1 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&LocalPlayer->vfptr, UFG::TriadWarsComponent::_TypeUID)) : (v1 = UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&LocalPlayer->vfptr, UFG::TriadWarsComponent::_TypeUID))) : (v1 = UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&LocalPlayer->vfptr, UFG::TriadWarsComponent::_TypeUID))) : (v1 = UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&LocalPlayer->vfptr, UFG::TriadWarsComponent::_TypeUID))) : (v1 = UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&LocalPlayer->vfptr, UFG::TriadWarsComponent::_TypeUID)),
        v1) )
  {
    result = LODWORD(v1[1].m_BoundComponentHandles.mNode.mPrev);
  }
  else
  {
    result = 0i64;
  }
  return result;
}

