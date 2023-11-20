// File Line: 31
// RVA: 0x1465940
__int64 UFG::_dynamic_initializer_for__gSmoketestStartTrack__()
{
  UFG::qString::qString(&UFG::gSmoketestStartTrack);
  return atexit(UFG::_dynamic_atexit_destructor_for__gSmoketestStartTrack__);
}

// File Line: 41
// RVA: 0x1465920
__int64 UFG::_dynamic_initializer_for__gProfileSliceName__()
{
  UFG::qString::qString(&UFG::gProfileSliceName);
  return atexit(UFG::_dynamic_atexit_destructor_for__gProfileSliceName__);
}

// File Line: 45
// RVA: 0x1465990
__int64 UFG::_dynamic_initializer_for__mTestType__()
{
  UFG::qString::qString(&UFG::mTestType);
  return atexit(UFG::_dynamic_atexit_destructor_for__mTestType__);
}

// File Line: 51
// RVA: 0x1465960
__int64 UFG::_dynamic_initializer_for__mPlatformName__()
{
  UFG::qString::qString(&UFG::mPlatformName, "PC");
  return atexit(UFG::_dynamic_atexit_destructor_for__mPlatformName__);
}

// File Line: 74
// RVA: 0x151580
void __fastcall UFG::SetCL(int changelist_number)
{
  UFG::CL_number = changelist_number;
}

// File Line: 213
// RVA: 0x1512D0
void __fastcall UFG::CollectMemoryStats(UFG *this)
{
  UFG::qMemoryPool *i; // r14
  int j; // ebx
  UFG::MemoryPoolSmallBlockInfo *k; // rax
  UFG::MemoryPoolLargeBlockInfo *l; // rax
  int v5; // edx
  int v6; // ebp
  int v7; // esi
  int v8; // ebx
  __int64 v9; // rdi
  UFG::MemoryPoolReporter v10; // [rsp+20h] [rbp-40C8h]
  UFG::NamedAllocTable v11; // [rsp+C0h] [rbp-4028h]
  char buffer; // [rsp+D8h] [rbp-4010h]

  UFG::NamedAllocTable::NamedAllocTable(&v11, &buffer, 0x4000ui64);
  for ( i = UFG::qGetMemoryPool(0i64); i; i = UFG::qGetMemoryPool(i) )
  {
    UFG::MemoryPoolReporter::Begin(&v10, i);
    for ( j = 0; UFG::MemoryPoolReporter::GetFirstSmallBlockInfo(&v10, j); ++j )
    {
      for ( k = UFG::MemoryPoolReporter::GetFirstSmallBlockInfo(&v10, j);
            k;
            k = UFG::MemoryPoolReporter::GetNextSmallBlockInfo(&v10) )
      {
        if ( !k->mIsFreeBlock )
          UFG::NamedAllocTable::Add(&v11, k->mName, k->mNumBytes);
      }
    }
    for ( l = UFG::MemoryPoolReporter::GetFirstLargeBlockInfo(&v10);
          l;
          l = UFG::MemoryPoolReporter::GetNextLargeBlockInfo(&v10) )
    {
      if ( !l->mIsFreeBlock )
        UFG::NamedAllocTable::Add(&v11, l->mName, l->mNumBytes);
    }
    UFG::MemoryPoolReporter::End(&v10);
    v5 = v11.mNumNamedAllocs;
    v6 = 0;
    v7 = 0;
    v8 = 0;
    if ( v11.mNumNamedAllocs > 0 )
    {
      v9 = 0i64;
      do
      {
        if ( v11.mNamedAllocs[v9].mCount && v11.mNamedAllocs[v9].mSize >= 0x10000 )
        {
          UFG::qMemoryPool::GetName(i);
          v5 = v11.mNumNamedAllocs;
        }
        else
        {
          v6 += v11.mNamedAllocs[v9].mSize;
          ++v7;
        }
        ++v8;
        ++v9;
      }
      while ( v8 < v5 );
      if ( v6 )
      {
        if ( v7 )
          UFG::qMemoryPool::GetName(i);
      }
    }
    UFG::NamedAllocTable::Clear(&v11);
  }
}

// File Line: 418
// RVA: 0x1514A0
UFG::CensusHelper *__fastcall UFG::CensusHelper::GetInstance()
{
  UFG::qString *v0; // rax
  UFG::qString result; // [rsp+28h] [rbp-30h]

  if ( !(_S1_20 & 1) )
  {
    _S1_20 |= 1u;
    UFG::qString::qString(&gInstance.mStateFileName);
    gInstance.mNumRetries = 2;
    gInstance.mFirstAttempt = 1;
    gInstance.mCurrentNodeID = 0;
    v0 = UFG::qGetLocalIP(&result);
    UFG::qString::Format(&gInstance.mStateFileName, "CensusState\\CurrentState_%s.xml", v0->mData);
    UFG::qString::~qString(&result);
    atexit(UFG::CensusHelper::GetInstance_::_2_::_dynamic_atexit_destructor_for__gInstance__);
  }
  return &gInstance;
}

// File Line: 452
// RVA: 0x151540
UFG::qVector3 *__fastcall UFG::CensusHelper::RetrieveNextVector(UFG::CensusHelper *this, UFG::qVector3 *result, UFG::qString *filename)
{
  UFG::qVector3 *v3; // rbx

  v3 = result;
  if ( this->mFirstAttempt == 1 )
  {
    this->mFirstAttempt = 0;
    ++this->mAttemptNumber;
  }
  else
  {
    this->mAttemptNumber = 1;
  }
  UFG::qString::~qString(filename);
  return v3;
}

