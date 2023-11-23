// File Line: 23
// RVA: 0x1606E0
void __fastcall UFG::NamedAllocTable::NamedAllocTable(
        UFG::NamedAllocTable *this,
        UFG::NamedAllocTable::NamedAlloc *buffer,
        unsigned __int64 buffer_size)
{
  unsigned __int64 v3; // r8

  v3 = buffer_size >> 4;
  this->mNamedAllocs = buffer;
  this->mMaxNamedAllocs = v3;
  this->mNumNamedAllocs = 0;
  this->mOverflowed = 0;
  UFG::qMemSet(buffer, 0, 16 * v3);
  this->mNumNamedAllocs = 0;
  this->mOverflowed = 0;
}

// File Line: 36
// RVA: 0x167D90
void __fastcall UFG::NamedAllocTable::Clear(UFG::NamedAllocTable *this)
{
  UFG::qMemSet(this->mNamedAllocs, 0, 16 * this->mMaxNamedAllocs);
  this->mNumNamedAllocs = 0;
  this->mOverflowed = 0;
}

// File Line: 44
// RVA: 0x165000
void __fastcall UFG::NamedAllocTable::Add(UFG::NamedAllocTable *this, const char *name, unsigned int size)
{
  int v5; // r9d
  int mNumNamedAllocs; // edi
  UFG::NamedAllocTable::NamedAlloc *v7; // r10
  const char *mName; // rax
  const char *v9; // rcx
  int v10; // edx
  __int64 v11; // rcx
  int v12; // ecx

  if ( name )
  {
    if ( name == UFG::gGlobalNewName )
    {
      v5 = 1;
    }
    else
    {
      mNumNamedAllocs = this->mNumNamedAllocs;
      v5 = 2;
      if ( mNumNamedAllocs > 2 )
      {
        v7 = this->mNamedAllocs + 2;
        do
        {
          mName = v7->mName;
          if ( !v7->mName )
            break;
          v9 = name;
          v10 = -1;
          while ( *mName && *mName == *v9 )
          {
            ++mName;
            ++v9;
            if ( !--v10 )
              goto LABEL_15;
          }
          if ( *(unsigned __int8 *)mName == *(unsigned __int8 *)v9 )
            break;
          ++v5;
          ++v7;
        }
        while ( v5 < mNumNamedAllocs );
      }
    }
  }
  else
  {
    v5 = 0;
  }
LABEL_15:
  if ( v5 >= this->mMaxNamedAllocs )
  {
    this->mOverflowed = 1;
  }
  else
  {
    v11 = v5;
    this->mNamedAllocs[v11].mName = name;
    this->mNamedAllocs[v11].mSize += size;
    ++this->mNamedAllocs[v11].mCount;
    v12 = this->mNumNamedAllocs;
    if ( v5 + 1 > v12 )
      v12 = v5 + 1;
    this->mNumNamedAllocs = v12;
  }
}

// File Line: 114
// RVA: 0x167940
void __fastcall UFG::MemoryPoolReporter::Begin(UFG::MemoryPoolReporter *this, UFG::qMemoryPool *memory_pool)
{
  this->mMemoryPool = memory_pool;
  UFG::allocator::report_begin(&memory_pool->mData->mAllocator);
}

// File Line: 121
// RVA: 0x16D070
void __fastcall UFG::MemoryPoolReporter::End(UFG::MemoryPoolReporter *this)
{
  int v1; // ebx
  UFG::qMemoryPoolData *mData; // rdi
  __int64 v4; // rax

  v1 = 0;
  mData = this->mMemoryPool->mData;
  v4 = 0i64;
  do
  {
    UFG::qMutex::Unlock((LPCRITICAL_SECTION)&mData->mAllocator.mBuckets[v4]);
    v4 = ++v1;
  }
  while ( (unsigned __int64)v1 < 0x20 );
  UFG::qMutex::Unlock((LPCRITICAL_SECTION)&mData->mAllocator.mTreeMutex);
  this->mMemoryPool = 0i64;
}

// File Line: 147
// RVA: 0x170AA0
UFG::MemoryPoolSmallBlockInfo *__fastcall UFG::MemoryPoolReporter::GetFirstSmallBlockInfo(
        UFG::MemoryPoolReporter *this,
        int bucket_index)
{
  UFG::MemoryPoolSmallBlockInfo *p_mSmallInfo; // rbx
  bool first_small_block_info; // al
  __int64 v4; // rcx

  p_mSmallInfo = &this->mSmallInfo;
  first_small_block_info = UFG::allocator::report_get_first_small_block_info(
                             &this->mMemoryPool->mData->mAllocator,
                             &this->mSmallInfo,
                             bucket_index);
  v4 = 0i64;
  if ( first_small_block_info )
    return p_mSmallInfo;
  return (UFG::MemoryPoolSmallBlockInfo *)v4;
}

// File Line: 154
// RVA: 0x171560
UFG::MemoryPoolSmallBlockInfo *__fastcall UFG::MemoryPoolReporter::GetNextSmallBlockInfo(UFG::MemoryPoolReporter *this)
{
  UFG::MemoryPoolSmallBlockInfo *p_mSmallInfo; // rbx
  bool next_small_block_info; // al
  __int64 v3; // rcx

  p_mSmallInfo = &this->mSmallInfo;
  next_small_block_info = UFG::allocator::report_get_next_small_block_info(
                            &this->mMemoryPool->mData->mAllocator,
                            &this->mSmallInfo);
  v3 = 0i64;
  if ( next_small_block_info )
    return p_mSmallInfo;
  return (UFG::MemoryPoolSmallBlockInfo *)v3;
}

// File Line: 161
// RVA: 0x170A70
UFG::MemoryPoolLargeBlockInfo *__fastcall UFG::MemoryPoolReporter::GetFirstLargeBlockInfo(
        UFG::MemoryPoolReporter *this)
{
  UFG::MemoryPoolLargeBlockInfo *p_mLargeInfo; // rbx
  bool first_large_block_info; // al
  __int64 v3; // rcx

  p_mLargeInfo = &this->mLargeInfo;
  first_large_block_info = UFG::allocator::report_get_first_large_block_info(
                             &this->mMemoryPool->mData->mAllocator,
                             &this->mLargeInfo);
  v3 = 0i64;
  if ( first_large_block_info )
    return p_mLargeInfo;
  return (UFG::MemoryPoolLargeBlockInfo *)v3;
}

// File Line: 168
// RVA: 0x171530
UFG::MemoryPoolLargeBlockInfo *__fastcall UFG::MemoryPoolReporter::GetNextLargeBlockInfo(UFG::MemoryPoolReporter *this)
{
  UFG::MemoryPoolLargeBlockInfo *p_mLargeInfo; // rbx
  bool next_large_block_info; // al
  __int64 v3; // rcx

  p_mLargeInfo = &this->mLargeInfo;
  next_large_block_info = UFG::allocator::report_get_next_large_block_info(
                            &this->mMemoryPool->mData->mAllocator,
                            &this->mLargeInfo);
  v3 = 0i64;
  if ( next_large_block_info )
    return p_mLargeInfo;
  return (UFG::MemoryPoolLargeBlockInfo *)v3;
}

