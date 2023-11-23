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
  unsigned int mUID; // edx
  UFG::qPropertySet *v4; // rbp
  UFG::qBaseTreeRB *v5; // rbx
  UFG::qBaseTreeRB *result; // rax
  UFG::qPropertySet *PropertySet; // rax
  UFG::qPropertyList *v8; // r13
  unsigned int mNumElements; // r12d
  UFG::allocator::free_link *v10; // rax
  UFG::allocator::free_link *v11; // rdi
  unsigned int v12; // ecx
  unsigned int v13; // r15d
  char *ValuePtr; // rax
  __int64 mNext_low; // r14
  unsigned int v16; // ebx
  unsigned int mNext_high; // edx
  unsigned int v18; // edx
  __int64 v19; // rbx
  int *v20; // rax
  __int64 *v21; // rcx
  int *v22; // rax
  int *v23; // rcx
  int *v24; // rax
  int *v25; // rdx
  UFG::qSymbol *v26; // rax
  UFG::qSymbol *v27; // rcx
  UFG::allocator::free_link *v29; // [rsp+88h] [rbp+10h] BYREF
  int v30; // [rsp+90h] [rbp+18h] BYREF
  int v31; // [rsp+98h] [rbp+20h] BYREF

  mUID = timeSetName->mUID;
  v4 = 0i64;
  if ( mUID )
  {
    result = UFG::qBaseTreeRB::Get(&this->mTimeSets.mTree, mUID);
    v5 = result;
    if ( result )
      return result;
  }
  else
  {
    v5 = 0i64;
  }
  PropertySet = UFG::PropertySetManager::GetPropertySet(timeSetName);
  if ( !PropertySet )
    return v5;
  v8 = UFG::qPropertySet::Get<UFG::qPropertyList>(
         PropertySet,
         (UFG::qArray<unsigned long,0> *)&qSymbol_TimeSetList,
         DEPTH_RECURSE);
  mNumElements = v8->mNumElements;
  v10 = UFG::qMalloc(0x30ui64, "TimeSet", 0i64);
  v11 = v10;
  v29 = v10;
  if ( v10 )
  {
    v12 = timeSetName->mUID;
    v10->mNext = 0i64;
    v10[1].mNext = 0i64;
    v10[2].mNext = 0i64;
    LODWORD(v10[3].mNext) = v12;
    v10[5].mNext = 0i64;
    v10[4].mNext = 0i64;
  }
  else
  {
    v11 = 0i64;
  }
  if ( mNumElements > HIDWORD(v11[4].mNext) )
    UFG::qArray<UFG::TimeBand,0>::Reallocate((UFG::qArray<UFG::TimeBand,0> *)&v11[4], mNumElements, "TimeSetCache");
  v13 = 0;
  if ( mNumElements )
  {
    LODWORD(v29) = -3;
    v30 = -1;
    v31 = -1;
    do
    {
      ValuePtr = UFG::qPropertyList::GetValuePtr(v8, 0x1Au, v13);
      if ( ValuePtr && *(_QWORD *)ValuePtr )
        v4 = (UFG::qPropertySet *)&ValuePtr[*(_QWORD *)ValuePtr];
      mNext_low = LODWORD(v11[4].mNext);
      v16 = mNext_low + 1;
      mNext_high = HIDWORD(v11[4].mNext);
      if ( (int)mNext_low + 1 > mNext_high )
      {
        if ( mNext_high )
          v18 = 2 * mNext_high;
        else
          v18 = 1;
        for ( ; v18 < v16; v18 *= 2 )
          ;
        if ( v18 - v16 > 0x10000 )
          v18 = mNext_low + 65537;
        UFG::qArray<UFG::TimeBand,0>::Reallocate((UFG::qArray<UFG::TimeBand,0> *)&v11[4], v18, "qArray.Add");
      }
      LODWORD(v11[4].mNext) = v16;
      v19 = (__int64)&v11[5].mNext[4 * mNext_low];
      v20 = UFG::qPropertySet::Get<long>(
              v4,
              (UFG::qArray<unsigned long,0> *)&qSymbol_TimeSetSpawnPopulation,
              DEPTH_RECURSE);
      v21 = (__int64 *)&v29;
      if ( v20 )
        v21 = (__int64 *)v20;
      *(_DWORD *)(v19 + 24) = *(_DWORD *)v21;
      v22 = UFG::qPropertySet::Get<long>(v4, (UFG::qArray<unsigned long,0> *)&qSymbol_OnTime, DEPTH_RECURSE);
      v23 = &v30;
      if ( v22 )
        v23 = v22;
      *(_DWORD *)(v19 + 16) = *v23;
      v24 = UFG::qPropertySet::Get<long>(v4, (UFG::qArray<unsigned long,0> *)&qSymbol_OffTime, DEPTH_RECURSE);
      v25 = &v31;
      if ( v24 )
        v25 = v24;
      *(_DWORD *)(v19 + 20) = *v25;
      v26 = UFG::qPropertySet::Get<UFG::qSymbol>(v4, (UFG::qArray<unsigned long,0> *)&qSymbol_SpawnSet, DEPTH_RECURSE);
      v27 = &UFG::gNullQSymbol;
      if ( v26 )
        v27 = v26;
      *(UFG::qSymbol *)v19 = (UFG::qSymbol)v27->mUID;
      *(_QWORD *)(v19 + 8) = UFG::PropertySetManager::GetPropertySet((UFG::qSymbol *)v19);
      ++v13;
      v4 = 0i64;
    }
    while ( v13 < mNumElements );
  }
  UFG::qBaseTreeRB::Add(&this->mTimeSets.mTree, (UFG::qBaseNodeRB *)v11);
  return (UFG::qBaseTreeRB *)v11;
}mElements );
  }
  UFG::qBaseTreeRB::Add(&this->mTimeSets.mTree, (U

