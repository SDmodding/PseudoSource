// File Line: 29
// RVA: 0x5B1A50
void __fastcall UFG::TimeBand::TimeBand(UFG::TimeBand *this)
{
  this->mSpawnSetName.mUID = -1;
  this->mpCachedSpawnSet = 0i64;
  *(_QWORD *)&this->mOnTime = -1i64;
  this->mSpawnPopulation = 1;
}

// File Line: 87
// RVA: 0x5B4EB0
UFG::qBaseTreeRB *__fastcall UFG::TimeSetCache::ObtainTimeSet(UFG::TimeSetCache *this, UFG::qSymbol *timeSetName)
{
  UFG::qSymbol *v2; // rsi
  unsigned int v3; // edx
  UFG::qPropertySet *v4; // rbp
  UFG::qBaseTreeRB *v5; // rbx
  UFG::qBaseTreeRB *result; // rax
  UFG::qPropertySet *v7; // rax
  UFG::qPropertyList *v8; // rax
  UFG::qPropertyList *v9; // r13
  unsigned int v10; // er12
  UFG::allocator::free_link *v11; // rax
  UFG::allocator::free_link *v12; // rdi
  UFG::qSymbol v13; // ecx
  unsigned int v14; // er15
  char *v15; // rax
  __int64 v16; // r14
  unsigned int v17; // ebx
  unsigned int v18; // edx
  unsigned int v19; // edx
  signed __int64 v20; // rbx
  int *v21; // rax
  __int64 *v22; // rcx
  int *v23; // rax
  int *v24; // rcx
  int *v25; // rax
  int *v26; // rdx
  UFG::qSymbol *v27; // rax
  UFG::qSymbol *v28; // rcx
  UFG::TimeSetCache *v29; // [rsp+80h] [rbp+8h]
  UFG::allocator::free_link *v30; // [rsp+88h] [rbp+10h]
  int v31; // [rsp+90h] [rbp+18h]
  int v32; // [rsp+98h] [rbp+20h]

  v29 = this;
  v2 = timeSetName;
  v3 = timeSetName->mUID;
  v4 = 0i64;
  if ( v3 )
  {
    result = UFG::qBaseTreeRB::Get(&this->mTimeSets.mTree, v3);
    v5 = result;
    if ( result )
      return result;
  }
  else
  {
    v5 = 0i64;
  }
  v7 = UFG::PropertySetManager::GetPropertySet(v2);
  if ( !v7 )
    return v5;
  v8 = UFG::qPropertySet::Get<UFG::qPropertyList>(v7, (UFG::qSymbol *)&qSymbol_TimeSetList.mUID, DEPTH_RECURSE);
  v9 = v8;
  v10 = v8->mNumElements;
  v11 = UFG::qMalloc(0x30ui64, "TimeSet", 0i64);
  v12 = v11;
  v30 = v11;
  if ( v11 )
  {
    v13.mUID = v2->mUID;
    v11->mNext = 0i64;
    v11[1].mNext = 0i64;
    v11[2].mNext = 0i64;
    LODWORD(v11[3].mNext) = v13;
    v11[5].mNext = 0i64;
    v11[4].mNext = 0i64;
  }
  else
  {
    v12 = 0i64;
  }
  if ( v10 > HIDWORD(v12[4].mNext) )
    UFG::qArray<UFG::TimeBand,0>::Reallocate((UFG::qArray<UFG::TimeBand,0> *)&v12[4], v10, "TimeSetCache");
  v14 = 0;
  if ( v10 )
  {
    LODWORD(v30) = -3;
    v31 = -1;
    v32 = -1;
    do
    {
      v15 = UFG::qPropertyList::GetValuePtr(v9, 0x1Au, v14);
      if ( v15 && *(_QWORD *)v15 )
        v4 = (UFG::qPropertySet *)&v15[*(_QWORD *)v15];
      v16 = LODWORD(v12[4].mNext);
      v17 = v16 + 1;
      v18 = HIDWORD(v12[4].mNext);
      if ( (signed int)v16 + 1 > v18 )
      {
        if ( v18 )
          v19 = 2 * v18;
        else
          v19 = 1;
        for ( ; v19 < v17; v19 *= 2 )
          ;
        if ( v19 - v17 > 0x10000 )
          v19 = v16 + 65537;
        UFG::qArray<UFG::TimeBand,0>::Reallocate((UFG::qArray<UFG::TimeBand,0> *)&v12[4], v19, "qArray.Add");
      }
      LODWORD(v12[4].mNext) = v17;
      v20 = (signed __int64)&v12[5].mNext[4 * v16];
      v21 = UFG::qPropertySet::Get<long>(v4, (UFG::qSymbol *)&qSymbol_TimeSetSpawnPopulation.mUID, DEPTH_RECURSE);
      v22 = (__int64 *)&v30;
      if ( v21 )
        v22 = (__int64 *)v21;
      *(_DWORD *)(v20 + 24) = *(_DWORD *)v22;
      v23 = UFG::qPropertySet::Get<long>(v4, (UFG::qSymbol *)&qSymbol_OnTime.mUID, DEPTH_RECURSE);
      v24 = &v31;
      if ( v23 )
        v24 = v23;
      *(_DWORD *)(v20 + 16) = *v24;
      v25 = UFG::qPropertySet::Get<long>(v4, (UFG::qSymbol *)&qSymbol_OffTime.mUID, DEPTH_RECURSE);
      v26 = &v32;
      if ( v25 )
        v26 = v25;
      *(_DWORD *)(v20 + 20) = *v26;
      v27 = UFG::qPropertySet::Get<UFG::qSymbol>(v4, (UFG::qSymbol *)&qSymbol_SpawnSet.mUID, DEPTH_RECURSE);
      v28 = &UFG::gNullQSymbol;
      if ( v27 )
        v28 = v27;
      *(UFG::qSymbol *)v20 = (UFG::qSymbol)v28->mUID;
      *(_QWORD *)(v20 + 8) = UFG::PropertySetManager::GetPropertySet((UFG::qSymbol *)v20);
      ++v14;
      v4 = 0i64;
    }
    while ( v14 < v10 );
  }
  UFG::qBaseTreeRB::Add(&v29->mTimeSets.mTree, (UFG::qBaseNodeRB *)v12);
  return (UFG::qBaseTreeRB *)v12;
}

