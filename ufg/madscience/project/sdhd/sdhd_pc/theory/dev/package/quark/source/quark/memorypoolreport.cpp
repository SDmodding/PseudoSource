// File Line: 23
// RVA: 0x1606E0
void __fastcall UFG::NamedAllocTable::NamedAllocTable(UFG::NamedAllocTable *this, void *buffer, unsigned __int64 buffer_size)
{
  unsigned __int64 v3; // r8
  unsigned __int128 v4; // cx

  v3 = buffer_size >> 4;
  this->mNamedAllocs = (UFG::NamedAllocTable::NamedAlloc *)buffer;
  *(_QWORD *)&this->mMaxNamedAllocs = (unsigned int)v3;
  this->mOverflowed = 0;
  v4 = __PAIR__((unsigned __int64)this, (unsigned __int64)buffer);
  UFG::qMemSet((void *)v4, 0, 16 * v3);
  *(_DWORD *)(*((_QWORD *)&v4 + 1) + 12i64) = 0;
  *(_BYTE *)(*((_QWORD *)&v4 + 1) + 16i64) = 0;
}

// File Line: 36
// RVA: 0x167D90
void __fastcall UFG::NamedAllocTable::Clear(UFG::NamedAllocTable *this)
{
  UFG::NamedAllocTable *v1; // rbx

  v1 = this;
  UFG::qMemSet(this->mNamedAllocs, 0, 16 * this->mMaxNamedAllocs);
  v1->mNumNamedAllocs = 0;
  v1->mOverflowed = 0;
}

// File Line: 44
// RVA: 0x165000
void __fastcall UFG::NamedAllocTable::Add(UFG::NamedAllocTable *this, const char *name, unsigned int size)
{
  const char *v3; // rbx
  UFG::NamedAllocTable *v4; // r11
  signed int v5; // er9
  int v6; // edi
  UFG::NamedAllocTable::NamedAlloc *v7; // r10
  const char *v8; // rax
  const char *v9; // rcx
  signed int v10; // edx
  signed __int64 v11; // rcx
  int v12; // ecx

  v3 = name;
  v4 = this;
  if ( name )
  {
    if ( name == UFG::gGlobalNewName )
    {
      v5 = 1;
    }
    else
    {
      v6 = this->mNumNamedAllocs;
      v5 = 2;
      if ( v6 > 2 )
      {
        v7 = this->mNamedAllocs + 2;
        do
        {
          v8 = v7->mName;
          if ( !v7->mName )
            break;
          v9 = v3;
          v10 = -1;
          while ( *v8 && *v8 == *v9 )
          {
            ++v8;
            ++v9;
            if ( !--v10 )
              goto LABEL_15;
          }
          if ( *(unsigned __int8 *)v8 == *(unsigned __int8 *)v9 )
            break;
          ++v5;
          ++v7;
        }
        while ( v5 < v6 );
      }
    }
  }
  else
  {
    v5 = 0;
  }
LABEL_15:
  if ( v5 >= v4->mMaxNamedAllocs )
  {
    v4->mOverflowed = 1;
  }
  else
  {
    v11 = v5;
    v4->mNamedAllocs[v11].mName = v3;
    v4->mNamedAllocs[v11].mSize += size;
    ++v4->mNamedAllocs[v11].mCount;
    v12 = v4->mNumNamedAllocs;
    if ( v5 + 1 > v12 )
      v12 = v5 + 1;
    v4->mNumNamedAllocs = v12;
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
  UFG::MemoryPoolReporter *v2; // rsi
  UFG::qMemoryPoolData *v3; // rdi
  __int64 v4; // rax

  v1 = 0;
  v2 = this;
  v3 = this->mMemoryPool->mData;
  v4 = 0i64;
  do
  {
    UFG::qMutex::Unlock((LPCRITICAL_SECTION)&v3->mAllocator.mBuckets[v4]);
    v4 = ++v1;
  }
  while ( (unsigned __int64)v1 < 0x20 );
  UFG::qMutex::Unlock((LPCRITICAL_SECTION)&v3->mAllocator.mTreeMutex);
  v2->mMemoryPool = 0i64;
}

// File Line: 147
// RVA: 0x170AA0
UFG::MemoryPoolSmallBlockInfo *__fastcall UFG::MemoryPoolReporter::GetFirstSmallBlockInfo(UFG::MemoryPoolReporter *this, int bucket_index)
{
  UFG::MemoryPoolSmallBlockInfo *v2; // rbx
  bool v3; // al
  UFG::MemoryPoolSmallBlockInfo *v4; // rcx

  v2 = &this->mSmallInfo;
  v3 = UFG::allocator::report_get_first_small_block_info(
         &this->mMemoryPool->mData->mAllocator,
         &this->mSmallInfo,
         bucket_index);
  v4 = 0i64;
  if ( v3 )
    v4 = v2;
  return v4;
}

// File Line: 154
// RVA: 0x171560
UFG::MemoryPoolSmallBlockInfo *__fastcall UFG::MemoryPoolReporter::GetNextSmallBlockInfo(UFG::MemoryPoolReporter *this)
{
  UFG::MemoryPoolSmallBlockInfo *v1; // rbx
  bool v2; // al
  UFG::MemoryPoolSmallBlockInfo *v3; // rcx

  v1 = &this->mSmallInfo;
  v2 = UFG::allocator::report_get_next_small_block_info(&this->mMemoryPool->mData->mAllocator, &this->mSmallInfo);
  v3 = 0i64;
  if ( v2 )
    v3 = v1;
  return v3;
}

// File Line: 161
// RVA: 0x170A70
UFG::MemoryPoolLargeBlockInfo *__fastcall UFG::MemoryPoolReporter::GetFirstLargeBlockInfo(UFG::MemoryPoolReporter *this)
{
  UFG::MemoryPoolLargeBlockInfo *v1; // rbx
  bool v2; // al
  UFG::MemoryPoolLargeBlockInfo *v3; // rcx

  v1 = &this->mLargeInfo;
  v2 = UFG::allocator::report_get_first_large_block_info(&this->mMemoryPool->mData->mAllocator, &this->mLargeInfo);
  v3 = 0i64;
  if ( v2 )
    v3 = v1;
  return v3;
}

// File Line: 168
// RVA: 0x171530
UFG::MemoryPoolLargeBlockInfo *__fastcall UFG::MemoryPoolReporter::GetNextLargeBlockInfo(UFG::MemoryPoolReporter *this)
{
  UFG::MemoryPoolLargeBlockInfo *v1; // rbx
  bool v2; // al
  UFG::MemoryPoolLargeBlockInfo *v3; // rcx

  v1 = &this->mLargeInfo;
  v2 = UFG::allocator::report_get_next_large_block_info(&this->mMemoryPool->mData->mAllocator, &this->mLargeInfo);
  v3 = 0i64;
  if ( v2 )
    v3 = v1;
  return v3;
}

