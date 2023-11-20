// File Line: 32
// RVA: 0x1467F70
__int64 UFG::_dynamic_initializer_for__gResourceFileInventory__()
{
  UFG::qResourceInventory::qResourceInventory(
    (UFG::qResourceInventory *)&UFG::gResourceFileInventory.vfptr,
    "Resource File Inventory",
    0xA428072C,
    0,
    0,
    0x40u);
  UFG::gResourceFileInventory.vfptr = (UFG::qResourceInventoryVtbl *)&UFG::qResourceFileInventory::`vftable;
  stru_14235B120.mNode.mPrev = (UFG::qNode<UFG::ResourceFile,UFG::ZeroRefResourceFile> *)&stru_14235B120;
  stru_14235B120.mNode.mNext = (UFG::qNode<UFG::ResourceFile,UFG::ZeroRefResourceFile> *)&stru_14235B120;
  return atexit(UFG::_dynamic_atexit_destructor_for__gResourceFileInventory__);
}

// File Line: 40
// RVA: 0x1467AF0
__int64 dynamic_initializer_for__UFG::AllocationProfile::sProfiles__()
{
  `eh vector constructor iterator(
    UFG::AllocationProfile::sProfiles,
    0x10ui64,
    3,
    (void (__fastcall *)(void *))UFG::qReflectHandleBase::qReflectHandleBase);
  return atexit(dynamic_atexit_destructor_for__UFG::AllocationProfile::sProfiles__);
}

// File Line: 116
// RVA: 0x16AC80
UFG::qList<UFG::AllocationProfile,UFG::AllocationProfile,1,0> *__fastcall UFG::AllocationProfile::CreateAllocationProfile(UFG::qMemoryPool *memory_pool, unsigned __int64 allocation_params)
{
  unsigned __int64 v2; // rbx
  UFG::qMemoryPool *v3; // rdi
  UFG::qList<UFG::AllocationProfile,UFG::AllocationProfile,1,0> *result; // rax
  UFG::qNode<UFG::AllocationProfile,UFG::AllocationProfile> *v5; // rdx
  UFG::qNode<UFG::AllocationProfile,UFG::AllocationProfile> *v6; // rcx
  UFG::qNode<UFG::AllocationProfile,UFG::AllocationProfile> *v7; // rcx
  UFG::qMemoryPool *v8; // rcx
  UFG::qNode<UFG::AllocationProfile,UFG::AllocationProfile> *v9; // rcx

  v2 = allocation_params;
  v3 = memory_pool;
  for ( result = (UFG::qList<UFG::AllocationProfile,UFG::AllocationProfile,1,0> *)UFG::AllocationProfile::sProfiles[0].mNode.mNext;
        result != UFG::AllocationProfile::sProfiles;
        result = (UFG::qList<UFG::AllocationProfile,UFG::AllocationProfile,1,0> *)result->mNode.mNext )
  {
    if ( *(_OWORD *)&result[1].mNode.mNext == __PAIR__((unsigned __int64)memory_pool, allocation_params) )
    {
      v5 = result->mNode.mPrev;
      v6 = result->mNode.mNext;
      v5->mNext = v6;
      v6->mPrev = v5;
      result->mNode.mPrev = &result->mNode;
      result->mNode.mNext = &result->mNode;
      v7 = UFG::AllocationProfile::sProfiles[0].mNode.mNext;
      UFG::AllocationProfile::sProfiles[0].mNode.mNext = &result->mNode;
      result->mNode.mPrev = (UFG::qNode<UFG::AllocationProfile,UFG::AllocationProfile> *)UFG::AllocationProfile::sProfiles;
      result->mNode.mNext = v7;
      v7->mPrev = &result->mNode;
      ++LODWORD(result[1].mNode.mPrev);
      return result;
    }
  }
  v8 = UFG::gMainMemoryPool;
  if ( !UFG::gMainMemoryPool )
  {
    UFG::InternalSetupMainMemoryPool((UFG *)UFG::gMainMemoryPool);
    v8 = UFG::gMainMemoryPool;
  }
  result = (UFG::qList<UFG::AllocationProfile,UFG::AllocationProfile,1,0> *)UFG::qMemoryPool::Allocate(
                                                                              v8,
                                                                              0x28ui64,
                                                                              "AllocationProfile",
                                                                              0i64,
                                                                              1u);
  if ( result )
  {
    result->mNode.mPrev = &result->mNode;
    result->mNode.mNext = &result->mNode;
    result[1].mNode.mPrev = (UFG::qNode<UFG::AllocationProfile,UFG::AllocationProfile> *)1;
    result[1].mNode.mNext = (UFG::qNode<UFG::AllocationProfile,UFG::AllocationProfile> *)v2;
    result[2].mNode.mPrev = (UFG::qNode<UFG::AllocationProfile,UFG::AllocationProfile> *)v3;
    ++UFG::AllocationProfile::sActiveProfilesCount[0];
  }
  v9 = UFG::AllocationProfile::sProfiles[0].mNode.mNext;
  UFG::AllocationProfile::sProfiles[0].mNode.mNext = &result->mNode;
  result->mNode.mPrev = (UFG::qNode<UFG::AllocationProfile,UFG::AllocationProfile> *)UFG::AllocationProfile::sProfiles;
  result->mNode.mNext = v9;
  v9->mPrev = &result->mNode;
  return result;
}

// File Line: 169
// RVA: 0x16AB80
UFG::AllocationProfile::CreateAllocationProfile

// File Line: 223
// RVA: 0x1609E0
void __fastcall UFG::ResourceMemoryHandle::ResourceMemoryHandle(UFG::ResourceMemoryHandle *this, UFG::AllocationProfile *profile)
{
  UFG::AllocationProfile *v2; // rdi
  UFG::ResourceMemoryHandle *v3; // rbx

  v2 = profile;
  v3 = this;
  this->mVRAMemoryHandle.mPrev = (UFG::qNode<UFG::qVRAMemoryHandle,UFG::qVRAMemoryPoolOnly> *)&this->mVRAMemoryHandle.mPrev;
  this->mVRAMemoryHandle.mNext = (UFG::qNode<UFG::qVRAMemoryHandle,UFG::qVRAMemoryPoolOnly> *)&this->mVRAMemoryHandle.mPrev;
  this->mVRAMemoryHandle.mData = 0i64;
  *(_DWORD *)&this->mVRAMemoryHandle.mReadOnlyAndPoolID = 0;
  UFG::qPrintChannel::Print(
    &UFG::VRAMChannel,
    OUTPUT_LEVEL_DEBUG,
    "[VRAM Channel] - Creating new empty qVRAMemoryHandle(%p)\n");
  v3->mAllocationSize = 0i64;
  v3->mAllocateReturned = 0i64;
  ++v2->mRefCount;
  v3->mAllocationProfile = v2;
  if ( v2->mProfileType == 2 )
  {
    v3->mAllocationSize = v2->mMemory.mVRAMemoryPool.mAlignment;
    v3->mAllocateReturned = v2->mMemory.mVRAMemoryPool.mPool;
  }
}

// File Line: 257
// RVA: 0x163200
UFG::ResourceMemoryHandle::~ResourceMemoryHandle

// File Line: 271
// RVA: 0x16F4B0
char *__fastcall UFG::ResourceMemoryHandle::GetBuffer(UFG::ResourceMemoryHandle *this)
{
  UFG::AllocationProfile *v1; // rax
  UFG::eProfileType v2; // eax

  v1 = this->mAllocationProfile;
  if ( !v1 )
    return this->mVRAMemoryHandle.mData;
  v2 = v1->mProfileType;
  switch ( v2 )
  {
    case 0:
      return (char *)this->mAllocateReturned;
    case 1:
      return this->mVRAMemoryHandle.mData;
    case 2:
      return (char *)this->mAllocateReturned;
  }
  return 0i64;
}

// File Line: 296
// RVA: 0x16F4E0
unsigned __int64 __fastcall UFG::ResourceMemoryHandle::GetBufferSize(UFG::ResourceMemoryHandle *this)
{
  UFG::AllocationProfile *v1; // rax
  UFG::eProfileType v2; // eax

  v1 = this->mAllocationProfile;
  if ( !v1 )
    return UFG::qVRAMemoryPools::GetRequestedSize(&this->mVRAMemoryHandle);
  v2 = v1->mProfileType;
  switch ( v2 )
  {
    case 0:
      return this->mAllocationSize;
    case 1:
      return UFG::qVRAMemoryPools::GetRequestedSize(&this->mVRAMemoryHandle);
    case 2:
      return this->mAllocationSize;
  }
  return 0i64;
}

// File Line: 321
// RVA: 0x1675F0
char *__fastcall UFG::ResourceMemoryHandle::AllocateBuffer(UFG::ResourceMemoryHandle *this, unsigned int buffer_size, const char *allocation_name, unsigned __int64 userdata64, unsigned int userdata32)
{
  UFG::ResourceMemoryHandle *v5; // rdi
  UFG::AllocationProfile *v6; // rcx
  UFG::eProfileType v7; // eax
  unsigned __int64 v8; // rbx
  UFG::allocator::free_link *v9; // rax
  char *v11; // rbx

  v5 = this;
  v6 = this->mAllocationProfile;
  if ( !v6 )
  {
LABEL_10:
    v11 = v5->mVRAMemoryHandle.mData;
    UFG::qVRAMemoryPools::GetRequestedSize(&v5->mVRAMemoryHandle);
    return v11;
  }
  v7 = v6->mProfileType;
  switch ( v7 )
  {
    case 0:
      if ( !v5->mAllocateReturned )
      {
        v8 = buffer_size;
        v9 = UFG::qMemoryPool::Allocate(
               v6->mMemory.mMemoryPool.mPool,
               buffer_size,
               allocation_name,
               v6->mMemory.mMemoryPool.mAllocationParams,
               1u);
        v5->mAllocateReturned = v9;
        if ( v9 )
          v5->mAllocationSize = v8;
      }
      return (char *)v5->mAllocateReturned;
    case 1:
      if ( !v5->mVRAMemoryHandle.mData )
        UFG::qVRAMemoryPool::Allocate(
          v6->mMemory.mVRAMemoryPool.mPool,
          &v5->mVRAMemoryHandle,
          buffer_size,
          (unsigned __int8)v6->mMemory.mVRAMemoryPool.mUsage,
          allocation_name,
          v6->mMemory.mVRAMemoryPool.mAlignment,
          v6->mMemory.mVRAMemoryPool.mFlags,
          0i64,
          userdata64,
          userdata32);
      goto LABEL_10;
    case 2:
      return (char *)v5->mAllocateReturned;
  }
  return 0i64;
}

// File Line: 381
// RVA: 0x16EDF0
void __fastcall UFG::ResourceMemoryHandle::FreeBuffer(UFG::ResourceMemoryHandle *this)
{
  UFG::ResourceMemoryHandle *v1; // rbx
  UFG::AllocationProfile *v2; // rcx
  UFG::eProfileType v3; // eax
  void *v4; // rdx

  v1 = this;
  v2 = this->mAllocationProfile;
  if ( v2 )
  {
    v3 = v2->mProfileType;
    if ( v3 )
    {
      if ( v3 == 1 && v1->mVRAMemoryHandle.mData )
        UFG::qVRAMemoryPool::Free(
          v2->mMemory.mVRAMemoryPool.mPool,
          &v1->mVRAMemoryHandle,
          (unsigned __int8)v2->mMemory.mVRAMemoryPool.mFreeDelay);
    }
    else
    {
      v4 = v1->mAllocateReturned;
      if ( v4 )
      {
        UFG::qMemoryPool::Free(v2->mMemory.mMemoryPool.mPool, v4);
        v1->mAllocateReturned = 0i64;
        v1->mAllocationSize = 0i64;
      }
    }
  }
  else
  {
    UFG::qVRAMemoryHandle::Close(&v1->mVRAMemoryHandle);
  }
}

// File Line: 482
// RVA: 0x1603A0
void __fastcall UFG::LoadTableEntry::LoadTableEntry(UFG::LoadTableEntry *this, const char *filename, UFG::AllocationProfile *profile, char *scratch_buffer, unsigned int scratch_buffer_size, UFG::ResourceFileContentType content_type)
{
  const char *v6; // rsi
  UFG::LoadTableEntry *v7; // rbx
  UFG::qString *v8; // rdi
  UFG::qMemoryPool *v9; // rcx
  char *v10; // rax
  UFG::qString *v11; // rax

  v6 = filename;
  v7 = this;
  this->mPrev = (UFG::qNode<UFG::LoadTableEntry,UFG::LoadTableEntry> *)&this->mPrev;
  this->mNext = (UFG::qNode<UFG::LoadTableEntry,UFG::LoadTableEntry> *)&this->mPrev;
  ++profile->mRefCount;
  this->mAllocationProfile = profile;
  this->mScratchBuffer = scratch_buffer;
  this->mScratchBufferSize = scratch_buffer_size;
  v8 = 0i64;
  this->mFilename = 0i64;
  this->mFilenameUID = -1;
  this->mContentType = content_type;
  v9 = UFG::gMainMemoryPool;
  if ( !UFG::gMainMemoryPool )
  {
    UFG::InternalSetupMainMemoryPool((UFG *)UFG::gMainMemoryPool);
    v9 = UFG::gMainMemoryPool;
  }
  v10 = UFG::qMemoryPool::Allocate(v9, 0x28ui64, "LoadTableString", 0i64, 1u);
  if ( v10 )
  {
    UFG::qString::qString((UFG::qString *)v10, v6);
    v8 = v11;
  }
  v7->mFilename = v8;
  v7->mFilenameUID = UFG::qString::GetStringHashUpper32(v8);
}

// File Line: 509
// RVA: 0x1602E0
void __fastcall UFG::LoadTableEntry::LoadTableEntry(UFG::LoadTableEntry *this, UFG::LoadTableEntry *entry)
{
  UFG::LoadTableEntry *v2; // rdi
  UFG::LoadTableEntry *v3; // rbx
  UFG::AllocationProfile *v4; // rax
  UFG::qString *v5; // rsi
  UFG::qMemoryPool *v6; // rcx
  char *v7; // rax
  UFG::qString *v8; // rax

  v2 = entry;
  v3 = this;
  this->mPrev = (UFG::qNode<UFG::LoadTableEntry,UFG::LoadTableEntry> *)&this->mPrev;
  this->mNext = (UFG::qNode<UFG::LoadTableEntry,UFG::LoadTableEntry> *)&this->mPrev;
  v4 = entry->mAllocationProfile;
  ++v4->mRefCount;
  this->mAllocationProfile = v4;
  this->mScratchBuffer = entry->mScratchBuffer;
  this->mScratchBufferSize = entry->mScratchBufferSize;
  v5 = 0i64;
  this->mFilename = 0i64;
  this->mFilenameUID = entry->mFilenameUID;
  this->mContentType = entry->mContentType;
  if ( entry->mFilename )
  {
    v6 = UFG::gMainMemoryPool;
    if ( !UFG::gMainMemoryPool )
    {
      UFG::InternalSetupMainMemoryPool((UFG *)UFG::gMainMemoryPool);
      v6 = UFG::gMainMemoryPool;
    }
    v7 = UFG::qMemoryPool::Allocate(v6, 0x28ui64, "LoadTableString", 0i64, 1u);
    if ( v7 )
    {
      UFG::qString::qString((UFG::qString *)v7, v2->mFilename);
      v5 = v8;
    }
    v3->mFilename = v5;
  }
}

// File Line: 520
// RVA: 0x162E50
void __fastcall UFG::LoadTableEntry::~LoadTableEntry(UFG::LoadTableEntry *this)
{
  UFG::LoadTableEntry *v1; // rbx
  UFG::AllocationProfile *v2; // rdx
  bool v3; // zf
  UFG::qNode<UFG::AllocationProfile,UFG::AllocationProfile> *v4; // rcx
  UFG::qNode<UFG::AllocationProfile,UFG::AllocationProfile> *v5; // rax
  UFG::qString *v6; // rdi
  char *v7; // rdx
  UFG::qNode<UFG::qString,UFG::qString> *v8; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *v9; // rax
  UFG::qNode<UFG::LoadTableEntry,UFG::LoadTableEntry> *v10; // rcx
  UFG::qNode<UFG::LoadTableEntry,UFG::LoadTableEntry> *v11; // rax

  v1 = this;
  v2 = this->mAllocationProfile;
  v3 = v2->mRefCount-- == 1;
  if ( v3 )
  {
    --UFG::AllocationProfile::sActiveProfilesCount[v2->mProfileType];
    v4 = v2->mPrev;
    v5 = v2->mNext;
    v4->mNext = v5;
    v5->mPrev = v4;
    v2->mPrev = (UFG::qNode<UFG::AllocationProfile,UFG::AllocationProfile> *)&v2->mPrev;
    v2->mNext = (UFG::qNode<UFG::AllocationProfile,UFG::AllocationProfile> *)&v2->mPrev;
    UFG::qMemoryPool::Free(UFG::gMainMemoryPool, v2);
  }
  v6 = v1->mFilename;
  if ( v6 )
  {
    v7 = v6->mData;
    if ( v7 != UFG::qString::sEmptyString && v7 )
      UFG::qMemoryPool::Free(UFG::gMainMemoryPool, v7);
    v6->mMagic = 0;
    v8 = v6->mPrev;
    v9 = v6->mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    v6->mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&v6->mPrev;
    v6->mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&v6->mPrev;
    UFG::qMemoryPool::Free(UFG::gMainMemoryPool, v6);
    v1->mFilename = 0i64;
  }
  v10 = v1->mPrev;
  v11 = v1->mNext;
  v10->mNext = v11;
  v11->mPrev = v10;
  v1->mPrev = (UFG::qNode<UFG::LoadTableEntry,UFG::LoadTableEntry> *)&v1->mPrev;
  v1->mNext = (UFG::qNode<UFG::LoadTableEntry,UFG::LoadTableEntry> *)&v1->mPrev;
}

// File Line: 581
// RVA: 0x163140
void __fastcall UFG::ResourceLoadTable::~ResourceLoadTable(UFG::ResourceLoadTable *this)
{
  UFG::ResourceLoadTable *v1; // rdi
  UFG::qList<UFG::LoadTableEntry,UFG::LoadTableEntry,1,0> *v2; // rsi
  UFG::LoadTableEntry *v3; // rbx
  UFG::qNode<UFG::LoadTableEntry,UFG::LoadTableEntry> *v4; // rcx
  UFG::qNode<UFG::LoadTableEntry,UFG::LoadTableEntry> *v5; // rax
  bool v6; // zf
  UFG::qMemoryPool *v7; // rcx
  UFG::qNode<UFG::LoadTableEntry,UFG::LoadTableEntry> *v8; // rcx
  UFG::qNode<UFG::LoadTableEntry,UFG::LoadTableEntry> *v9; // rax
  UFG::qNode<UFG::ResourceLoadTable,UFG::ResourceLoadTable> *v10; // rcx
  UFG::qNode<UFG::ResourceLoadTable,UFG::ResourceLoadTable> *v11; // rax

  v1 = this;
  v2 = &this->mTableEntries;
  if ( (UFG::qList<UFG::LoadTableEntry,UFG::LoadTableEntry,1,0> *)this->mTableEntries.mNode.mNext != &this->mTableEntries )
  {
    do
    {
      v3 = (UFG::LoadTableEntry *)v1->mTableEntries.mNode.mNext;
      v4 = v3->mPrev;
      v5 = v3->mNext;
      v6 = v1->mMemoryPool == 0i64;
      v4->mNext = v5;
      v5->mPrev = v4;
      v3->mPrev = (UFG::qNode<UFG::LoadTableEntry,UFG::LoadTableEntry> *)&v3->mPrev;
      v3->mNext = (UFG::qNode<UFG::LoadTableEntry,UFG::LoadTableEntry> *)&v3->mPrev;
      if ( v6 )
      {
        UFG::LoadTableEntry::~LoadTableEntry(v3);
        v7 = UFG::gMainMemoryPool;
      }
      else
      {
        UFG::LoadTableEntry::~LoadTableEntry(v3);
        v7 = v1->mMemoryPool;
      }
      UFG::qMemoryPool::Free(v7, v3);
    }
    while ( (UFG::qList<UFG::LoadTableEntry,UFG::LoadTableEntry,1,0> *)v2->mNode.mNext != v2 );
  }
  UFG::qList<UFG::LoadTableEntry,UFG::LoadTableEntry,1,0>::DeleteNodes(v2);
  v8 = v2->mNode.mPrev;
  v9 = v2->mNode.mNext;
  v8->mNext = v9;
  v9->mPrev = v8;
  v2->mNode.mPrev = &v2->mNode;
  v2->mNode.mNext = &v2->mNode;
  v10 = v1->mPrev;
  v11 = v1->mNext;
  v10->mNext = v11;
  v11->mPrev = v10;
  v1->mPrev = (UFG::qNode<UFG::ResourceLoadTable,UFG::ResourceLoadTable> *)&v1->mPrev;
  v1->mNext = (UFG::qNode<UFG::ResourceLoadTable,UFG::ResourceLoadTable> *)&v1->mPrev;
}

// File Line: 608
// RVA: 0x1650D0
void __fastcall UFG::ResourceLoadTable::Add(UFG::ResourceLoadTable *this, const char *filename, UFG::qMemoryPool *memory_pool, unsigned __int64 allocation_params, char *scratch_buffer, unsigned int scratch_buffer_size, UFG::ResourceFileContentType content_type)
{
  const char *v7; // rbx
  UFG::ResourceLoadTable *v8; // rsi
  UFG::qMemoryPool *v9; // rcx
  UFG::AllocationProfile *v10; // rdi
  UFG::qMemoryPool *v11; // rcx
  UFG::qMemoryPool *v12; // rcx
  char *v13; // rax
  UFG::qNode<UFG::LoadTableEntry,UFG::LoadTableEntry> *v14; // rax
  UFG::qNode<UFG::LoadTableEntry,UFG::LoadTableEntry> *v15; // rbx
  char *v16; // rax
  UFG::qNode<UFG::LoadTableEntry,UFG::LoadTableEntry> *v17; // rax
  bool v18; // zf
  UFG::qNode<UFG::AllocationProfile,UFG::AllocationProfile> *v19; // rcx
  UFG::qNode<UFG::AllocationProfile,UFG::AllocationProfile> *v20; // rax
  UFG::qNode<UFG::LoadTableEntry,UFG::LoadTableEntry> *v21; // rax

  v7 = filename;
  v8 = this;
  v9 = UFG::gMainMemoryPool;
  if ( memory_pool )
    v9 = memory_pool;
  v10 = UFG::AllocationProfile::CreateAllocationProfile(v9, allocation_params);
  v11 = v8->mMemoryPool;
  if ( v11 )
  {
    v16 = UFG::qMemoryPool::Allocate(v11, 0x38ui64, "LoadTableEntry", 0i64, 1u);
    if ( v16 )
    {
      UFG::LoadTableEntry::LoadTableEntry(
        (UFG::LoadTableEntry *)v16,
        v7,
        v10,
        scratch_buffer,
        scratch_buffer_size,
        content_type);
      v15 = v17;
    }
    else
    {
      v15 = 0i64;
    }
  }
  else
  {
    v12 = UFG::gMainMemoryPool;
    if ( !UFG::gMainMemoryPool )
    {
      UFG::InternalSetupMainMemoryPool((UFG *)UFG::gMainMemoryPool);
      v12 = UFG::gMainMemoryPool;
    }
    v13 = UFG::qMemoryPool::Allocate(v12, 0x38ui64, "LoadTableEntry", 0i64, 1u);
    if ( v13 )
    {
      UFG::LoadTableEntry::LoadTableEntry(
        (UFG::LoadTableEntry *)v13,
        v7,
        v10,
        scratch_buffer,
        scratch_buffer_size,
        content_type);
      v15 = v14;
    }
    else
    {
      v15 = 0i64;
    }
  }
  v18 = v10->mRefCount-- == 1;
  if ( v18 )
  {
    --UFG::AllocationProfile::sActiveProfilesCount[v10->mProfileType];
    v19 = v10->mPrev;
    v20 = v10->mNext;
    v19->mNext = v20;
    v20->mPrev = v19;
    v10->mPrev = (UFG::qNode<UFG::AllocationProfile,UFG::AllocationProfile> *)&v10->mPrev;
    v10->mNext = (UFG::qNode<UFG::AllocationProfile,UFG::AllocationProfile> *)&v10->mPrev;
    UFG::qMemoryPool::Free(UFG::gMainMemoryPool, v10);
  }
  v21 = v8->mTableEntries.mNode.mPrev;
  v21->mNext = v15;
  v15->mPrev = v21;
  v15->mNext = &v8->mTableEntries.mNode;
  v8->mTableEntries.mNode.mPrev = v15;
}

// File Line: 765
// RVA: 0x16AA60
__int64 __fastcall UFG::ResourceLoadTable::CopyTableEntries(UFG::ResourceLoadTable *this, UFG::ResourceLoadTable *load_table)
{
  UFG::ResourceLoadTable *v2; // rbp
  unsigned __int8 v3; // di
  UFG::LoadTableEntry *v4; // rbx
  UFG::qList<UFG::LoadTableEntry,UFG::LoadTableEntry,1,0> *v5; // r14
  UFG::qList<UFG::LoadTableEntry,UFG::LoadTableEntry,1,0> *v6; // rsi
  UFG::qMemoryPool *v7; // rcx
  UFG::qMemoryPool *v8; // rcx
  UFG::allocator::free_link *v9; // rax
  UFG::qNode<UFG::LoadTableEntry,UFG::LoadTableEntry> *v10; // rax
  UFG::allocator::free_link *v11; // rax
  UFG::qNode<UFG::LoadTableEntry,UFG::LoadTableEntry> *v12; // rcx

  v2 = this;
  v3 = 1;
  v4 = (UFG::LoadTableEntry *)load_table->mTableEntries.mNode.mNext;
  v5 = &load_table->mTableEntries;
  if ( v4 != (UFG::LoadTableEntry *)&load_table->mTableEntries )
  {
    v6 = &this->mTableEntries;
    do
    {
      v7 = v2->mMemoryPool;
      if ( v7 )
      {
        v11 = UFG::qMemoryPool::Allocate(v7, 0x38ui64, "LoadTableEntry", 0i64, 1u);
        if ( v11 )
          UFG::LoadTableEntry::LoadTableEntry((UFG::LoadTableEntry *)v11, v4);
        else
          v10 = 0i64;
      }
      else
      {
        v8 = UFG::gMainMemoryPool;
        if ( !UFG::gMainMemoryPool )
        {
          UFG::InternalSetupMainMemoryPool((UFG *)UFG::gMainMemoryPool);
          v8 = UFG::gMainMemoryPool;
        }
        v9 = UFG::qMemoryPool::Allocate(v8, 0x38ui64, "LoadTableEntry", 0i64, 1u);
        if ( v9 )
          UFG::LoadTableEntry::LoadTableEntry((UFG::LoadTableEntry *)v9, v4);
        else
          v10 = 0i64;
      }
      if ( !v10 )
        v3 = 0;
      v12 = v6->mNode.mPrev;
      v12->mNext = v10;
      v10->mPrev = v12;
      v10->mNext = &v6->mNode;
      v6->mNode.mPrev = v10;
      v4 = (UFG::LoadTableEntry *)v4->mNext;
    }
    while ( v4 != (UFG::LoadTableEntry *)v5 );
  }
  return v3;
}

// File Line: 817
// RVA: 0x17BAC0
void __fastcall UFG::ResourceSystem_OpennedFileCallback(UFG::qFileOp *file_op, void *callback_param)
{
  char *v2; // r9

  if ( *(_DWORD *)file_op->mStatus == 5 )
  {
    if ( !file_op->mFile )
      v2 = file_op->mFilename.mData;
    UFG::qPrintChannel::Print(
      &UFG::qChunkFileSystem::mResourceChannel,
      OUTPUT_LEVEL_WARNING,
      "WARNING: Async qOpen returned an error on file %s\n");
  }
}

// File Line: 829
// RVA: 0x160910
void __fastcall UFG::ResourceFileHandle::ResourceFileHandle(UFG::ResourceFileHandle *this, const char *filename, unsigned int filename_uid)
{
  UFG::ResourceFileHandle *v3; // rbx
  UFG::qString *v4; // r10
  const char *v5; // rax
  char v6; // cl
  int v7; // eax

  v3 = this;
  this->mNode.mParent = 0i64;
  this->mNode.mChild[0] = 0i64;
  this->mNode.mChild[1] = 0i64;
  this->mNode.mUID = filename_uid;
  v4 = &this->mFilename;
  v4->mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&v4->mPrev;
  v4->mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&v4->mPrev;
  this->mFilename.mMagic = 16909060;
  this->mFilename.mData = (char *)UFG::qString::sEmptyString;
  this->mFilename.mLength = 0;
  *(_QWORD *)&this->mFilename.mStringHash32 = -1i64;
  if ( filename && filename != UFG::qString::sEmptyString )
  {
    v5 = filename;
    do
      v6 = *v5++;
    while ( v6 );
    v7 = (_DWORD)v5 - (_DWORD)filename - 1;
  }
  else
  {
    v7 = 0;
  }
  UFG::qString::Set(v4, filename, v7, 0i64, 0);
  v3->mFile = UFG::qOpenAsync(
                v3->mFilename.mData,
                QACCESS_READ,
                0,
                UFG::ResourceSystem_OpennedFileCallback,
                v3,
                QPRIORITY_NORMAL);
}

// File Line: 861
// RVA: 0x160850
void __fastcall UFG::ResourceFile::ResourceFile(UFG::ResourceFile *this, unsigned int resource_uid, UFG::AllocationProfile *profile)
{
  UFG::AllocationProfile *v3; // rbx
  UFG::ResourceFile *v4; // rdi
  UFG::qNode<UFG::ResourceFile,UFG::ZeroRefResourceFile> *v5; // rax
  UFG::qList<UFG::qResourceHandle,UFG::qResourceHandle,1,0> *v6; // [rsp+58h] [rbp+20h]
  UFG::qList<UFG::qValueNode<UFG::ResourceLoadTable *>,UFG::qValueNode<UFG::ResourceLoadTable *>,1,0> *v7; // [rsp+58h] [rbp+20h]

  v3 = profile;
  v4 = this;
  this->mNode.mParent = 0i64;
  this->mNode.mChild[0] = 0i64;
  this->mNode.mChild[1] = 0i64;
  this->mNode.mUID = resource_uid;
  v6 = &this->mResourceHandles;
  v6->mNode.mPrev = &v6->mNode;
  v6->mNode.mNext = &v6->mNode;
  this->mTypeUID = -1540880596;
  UFG::qMemSet(this->mDebugName, 0, 0x24u);
  v5 = (UFG::qNode<UFG::ResourceFile,UFG::ZeroRefResourceFile> *)&v4->mPrev;
  v5->mPrev = v5;
  v5->mNext = v5;
  UFG::ResourceMemoryHandle::ResourceMemoryHandle(&v4->mMemoryHandle, v3);
  v4->mValidDataSize = 0i64;
  *(_QWORD *)&v4->mRefs = 0i64;
  v4->mState = 0;
  v7 = &v4->mWaitingLoadTables;
  v7->mNode.mPrev = &v7->mNode;
  v7->mNode.mNext = &v7->mNode;
  v4->mUserData = 0i64;
  ++UFG::ResourceFile::sResourceFileCount;
  ++UFG::ResourceFile::sResourceFileTotal;
}

// File Line: 874
// RVA: 0x160780
void __fastcall UFG::ResourceFile::ResourceFile(UFG::ResourceFile *this, unsigned int resource_uid, UFG::qVRAMemoryHandle *handle)
{
  UFG::qVRAMemoryHandle *v3; // rdi
  UFG::ResourceFile *v4; // rsi
  UFG::qNode<UFG::ResourceFile,UFG::ZeroRefResourceFile> *v5; // rax
  UFG::qList<UFG::qResourceHandle,UFG::qResourceHandle,1,0> *v6; // [rsp+68h] [rbp+20h]
  UFG::qList<UFG::qValueNode<UFG::ResourceLoadTable *>,UFG::qValueNode<UFG::ResourceLoadTable *>,1,0> *v7; // [rsp+68h] [rbp+20h]

  v3 = handle;
  v4 = this;
  this->mNode.mParent = 0i64;
  this->mNode.mChild[0] = 0i64;
  this->mNode.mChild[1] = 0i64;
  this->mNode.mUID = resource_uid;
  v6 = &this->mResourceHandles;
  v6->mNode.mPrev = &v6->mNode;
  v6->mNode.mNext = &v6->mNode;
  this->mTypeUID = -1540880596;
  UFG::qMemSet(this->mDebugName, 0, 0x24u);
  v5 = (UFG::qNode<UFG::ResourceFile,UFG::ZeroRefResourceFile> *)&v4->mPrev;
  v5->mPrev = v5;
  v5->mNext = v5;
  UFG::qVRAMemoryHandle::qVRAMemoryHandle(&v4->mMemoryHandle.mVRAMemoryHandle, v3);
  v4->mMemoryHandle.mAllocationSize = 0i64;
  v4->mMemoryHandle.mAllocateReturned = 0i64;
  v4->mMemoryHandle.mAllocationProfile = 0i64;
  v4->mValidDataSize = 0i64;
  *(_QWORD *)&v4->mRefs = 0i64;
  v4->mState = 0;
  v7 = &v4->mWaitingLoadTables;
  v7->mNode.mPrev = &v7->mNode;
  v7->mNode.mNext = &v7->mNode;
  v4->mUserData = 0i64;
  ++UFG::ResourceFile::sResourceFileCount;
  ++UFG::ResourceFile::sResourceFileTotal;
}

// File Line: 880
// RVA: 0x163080
void __fastcall UFG::ResourceFile::~ResourceFile(UFG::ResourceFile *this)
{
  UFG::ResourceFile *v1; // rsi
  UFG::qNode<UFG::qValueNode<UFG::ResourceLoadTable *>,UFG::qValueNode<UFG::ResourceLoadTable *> > *v2; // rdx
  UFG::qNode<UFG::qValueNode<UFG::ResourceLoadTable *>,UFG::qValueNode<UFG::ResourceLoadTable *> > *v3; // rax
  UFG::qNode<UFG::ResourceFile,UFG::ZeroRefResourceFile> *v4; // rdx
  UFG::qNode<UFG::ResourceFile,UFG::ZeroRefResourceFile> *v5; // rcx
  UFG::qNode<UFG::ResourceFile,UFG::ZeroRefResourceFile> *v6; // rax
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v7; // rcx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v8; // rax

  v1 = this;
  UFG::ResourceMemoryHandle::FreeBuffer(&this->mMemoryHandle);
  --UFG::ResourceFile::sResourceFileCount;
  UFG::qList<UFG::qTaskFunctionDecl,UFG::qTaskFunctionDecl,1,0>::DeleteNodes((UFG::qList<UFG::tChunkPosition,UFG::tChunkPosition,1,0> *)&v1->mWaitingLoadTables);
  v2 = v1->mWaitingLoadTables.mNode.mPrev;
  v3 = v1->mWaitingLoadTables.mNode.mNext;
  v2->mNext = v3;
  v3->mPrev = v2;
  v1->mWaitingLoadTables.mNode.mPrev = &v1->mWaitingLoadTables.mNode;
  v1->mWaitingLoadTables.mNode.mNext = &v1->mWaitingLoadTables.mNode;
  UFG::ResourceMemoryHandle::~ResourceMemoryHandle(&v1->mMemoryHandle);
  v4 = (UFG::qNode<UFG::ResourceFile,UFG::ZeroRefResourceFile> *)&v1->mPrev;
  v5 = v1->mPrev;
  v6 = v1->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  v4->mPrev = v4;
  v4->mNext = v4;
  UFG::qList<UFG::qResourceHandle,UFG::qResourceHandle,1,0>::DeleteNodes(&v1->mResourceHandles);
  v7 = v1->mResourceHandles.mNode.mPrev;
  v8 = v1->mResourceHandles.mNode.mNext;
  v7->mNext = v8;
  v8->mPrev = v7;
  v1->mResourceHandles.mNode.mPrev = &v1->mResourceHandles.mNode;
  v1->mResourceHandles.mNode.mNext = &v1->mResourceHandles.mNode;
}

// File Line: 933
// RVA: 0x17FC80
void __fastcall UFG::ResourceFile::WarehouseLoad(UFG::ResourceFile *this)
{
  UFG::AllocationProfile *v1; // rax
  void *v2; // rdi
  UFG::ResourceFile *v3; // rbx
  UFG::eProfileType v4; // eax
  void *v5; // rcx
  void *v6; // rcx
  char *v7; // rcx
  __int64 v8; // r9
  __int64 v9; // ST28_8
  UFG::AllocationProfile *v10; // rax
  UFG::eProfileType v11; // eax
  UFG::qResourceWarehouse *v12; // rax
  UFG::qNode<UFG::ResourceFile,UFG::ZeroRefResourceFile> *v13; // rax
  UFG::qNode<UFG::ResourceFile,UFG::ZeroRefResourceFile> *v14; // rcx

  v1 = this->mMemoryHandle.mAllocationProfile;
  v2 = 0i64;
  v3 = this;
  if ( !v1 )
  {
LABEL_8:
    v7 = this->mMemoryHandle.mVRAMemoryHandle.mData;
    goto LABEL_9;
  }
  v4 = v1->mProfileType;
  if ( v4 )
  {
    if ( v4 != 1 )
    {
      if ( v4 == 2 )
        v6 = this->mMemoryHandle.mAllocateReturned;
      goto LABEL_9;
    }
    goto LABEL_8;
  }
  v5 = this->mMemoryHandle.mAllocateReturned;
LABEL_9:
  v8 = v3->mNode.mUID;
  v9 = v3->mValidDataSize;
  UFG::qPrintChannel::Print(
    &UFG::qChunkFileSystem::mResourceChannel,
    OUTPUT_LEVEL_WARNING,
    "[Resource - Load ResourceFile] uid=0x%08x  address=0x%08x sz=%d\n");
  v10 = v3->mMemoryHandle.mAllocationProfile;
  if ( !v10 )
    goto LABEL_21;
  v11 = v10->mProfileType;
  if ( v11 == eProfileType_MemoryPool )
  {
    v2 = v3->mMemoryHandle.mAllocateReturned;
    goto LABEL_16;
  }
  if ( v11 != 1 )
  {
    if ( v11 == 2 )
      v2 = v3->mMemoryHandle.mAllocateReturned;
  }
  else
  {
LABEL_21:
    v2 = v3->mMemoryHandle.mVRAMemoryHandle.mData;
  }
LABEL_16:
  v12 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Load(v12, v2, LODWORD(v3->mValidDataSize));
  if ( v3->mUserData )
  {
    v13 = stru_14235B120.mNode.mPrev;
    v14 = (UFG::qNode<UFG::ResourceFile,UFG::ZeroRefResourceFile> *)&v3->mPrev;
    stru_14235B120.mNode.mPrev->mNext = (UFG::qNode<UFG::ResourceFile,UFG::ZeroRefResourceFile> *)&v3->mPrev;
    v14->mPrev = v13;
    v14->mNext = (UFG::qNode<UFG::ResourceFile,UFG::ZeroRefResourceFile> *)&stru_14235B120;
    stru_14235B120.mNode.mPrev = (UFG::qNode<UFG::ResourceFile,UFG::ZeroRefResourceFile> *)&v3->mPrev;
  }
  UFG::qResourceInventory::Add(
    (UFG::qResourceInventory *)&UFG::gResourceFileInventory.vfptr,
    (UFG::qResourceData *)&v3->mNode);
  v3->mState = 2;
}

// File Line: 952
// RVA: 0x17FD90
void __fastcall UFG::ResourceFile::WarehouseUnload(UFG::ResourceFile *this)
{
  UFG::AllocationProfile *v1; // rax
  UFG::ResourceFile *v2; // rbx
  UFG::eProfileType v3; // eax
  void *v4; // rcx
  void *v5; // rcx
  char *v6; // rcx
  __int64 v7; // r9
  __int64 v8; // ST28_8
  UFG::AllocationProfile *v9; // rax
  UFG::eProfileType v10; // eax
  void *v11; // rdi
  UFG::qResourceWarehouse *v12; // rax

  v1 = this->mMemoryHandle.mAllocationProfile;
  v2 = this;
  if ( !v1 )
  {
LABEL_8:
    v6 = this->mMemoryHandle.mVRAMemoryHandle.mData;
    goto LABEL_9;
  }
  v3 = v1->mProfileType;
  if ( v3 )
  {
    if ( v3 != 1 )
    {
      if ( v3 == 2 )
        v5 = this->mMemoryHandle.mAllocateReturned;
      goto LABEL_9;
    }
    goto LABEL_8;
  }
  v4 = this->mMemoryHandle.mAllocateReturned;
LABEL_9:
  v7 = v2->mNode.mUID;
  v8 = v2->mValidDataSize;
  UFG::qPrintChannel::Print(
    &UFG::qChunkFileSystem::mResourceChannel,
    OUTPUT_LEVEL_WARNING,
    "[Resource - Unload ResourceFile] uid=0x%08x  address=0x%08x sz=%d\n");
  v9 = v2->mMemoryHandle.mAllocationProfile;
  if ( !v9 )
    goto LABEL_19;
  v10 = v9->mProfileType;
  if ( v10 == eProfileType_MemoryPool )
    goto LABEL_11;
  if ( v10 == 1 )
  {
LABEL_19:
    v11 = v2->mMemoryHandle.mVRAMemoryHandle.mData;
    goto LABEL_16;
  }
  if ( v10 != 2 )
  {
    v11 = 0i64;
    goto LABEL_16;
  }
LABEL_11:
  v11 = v2->mMemoryHandle.mAllocateReturned;
LABEL_16:
  v12 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Unload(v12, v11, LODWORD(v2->mValidDataSize));
  UFG::qResourceInventory::Remove(
    (UFG::qResourceInventory *)&UFG::gResourceFileInventory.vfptr,
    (UFG::qResourceData *)&v2->mNode);
  v2->mValidDataSize = 0i64;
  v2->mState = 0;
}

// File Line: 972
// RVA: 0x1669C0
char __fastcall UFG::ResourceFile::AddWaitingTable(UFG::ResourceFile *this, UFG::ResourceLoadTable *load_table)
{
  UFG::ResourceLoadTable *v2; // rdi
  UFG::ResourceFile *v3; // rsi
  UFG::qMemoryPool *v4; // rcx
  char *v5; // rax
  char *v6; // rbx
  UFG::qNode<UFG::qValueNode<UFG::ResourceLoadTable *>,UFG::qValueNode<UFG::ResourceLoadTable *> > *v7; // rax

  v2 = load_table;
  v3 = this;
  v4 = UFG::gMainMemoryPool;
  if ( !UFG::gMainMemoryPool )
  {
    UFG::InternalSetupMainMemoryPool((UFG *)UFG::gMainMemoryPool);
    v4 = UFG::gMainMemoryPool;
  }
  v5 = UFG::qMemoryPool::Allocate(v4, 0x18ui64, "ResourceFile::WaitingTableEntry", 0i64, 1u);
  v6 = v5;
  if ( v5 )
  {
    *(_QWORD *)v5 = v5;
    *((_QWORD *)v5 + 1) = v5;
    *((_QWORD *)v5 + 2) = v2;
  }
  else
  {
    v6 = 0i64;
  }
  if ( !v6 )
    return 0;
  UFG::qAtomicIncrement((volatile int *)(*((_QWORD *)v6 + 2) + 88i64));
  v7 = v3->mWaitingLoadTables.mNode.mPrev;
  v7->mNext = (UFG::qNode<UFG::qValueNode<UFG::ResourceLoadTable *>,UFG::qValueNode<UFG::ResourceLoadTable *> > *)v6;
  *(_QWORD *)v6 = v7;
  *((_QWORD *)v6 + 1) = (char *)v3 + 184;
  v3->mWaitingLoadTables.mNode.mPrev = (UFG::qNode<UFG::qValueNode<UFG::ResourceLoadTable *>,UFG::qValueNode<UFG::ResourceLoadTable *> > *)v6;
  return 1;
}

// File Line: 984
// RVA: 0x1781F0
char __fastcall UFG::ResourceFile::NotifyWaitingTables(UFG::ResourceFile *this)
{
  UFG::ResourceFile *v1; // rsi
  char **v2; // rdi
  UFG::qNode<UFG::qValueNode<UFG::ResourceLoadTable *>,UFG::qValueNode<UFG::ResourceLoadTable *> > *v3; // rbx
  UFG::qNode<UFG::qValueNode<UFG::ResourceLoadTable *>,UFG::qValueNode<UFG::ResourceLoadTable *> > *v4; // rdx
  UFG::qNode<UFG::qValueNode<UFG::ResourceLoadTable *>,UFG::qValueNode<UFG::ResourceLoadTable *> > *v5; // rax
  UFG::qNode<UFG::qValueNode<UFG::ResourceLoadTable *>,UFG::qValueNode<UFG::ResourceLoadTable *> > *v6; // rcx
  UFG::qNode<UFG::qValueNode<UFG::ResourceLoadTable *>,UFG::qValueNode<UFG::ResourceLoadTable *> > *v7; // rax

  v1 = this;
  v2 = (char **)&this->mWaitingLoadTables;
  if ( (UFG::qList<UFG::qValueNode<UFG::ResourceLoadTable *>,UFG::qValueNode<UFG::ResourceLoadTable *>,1,0> *)this->mWaitingLoadTables.mNode.mNext != &this->mWaitingLoadTables )
  {
    do
    {
      v3 = v1->mWaitingLoadTables.mNode.mNext;
      v4 = v3->mPrev;
      v5 = v3->mNext;
      v4->mNext = v5;
      v5->mPrev = v4;
      v3->mPrev = v3;
      v3->mNext = v3;
      UFG::qAtomicDecrement((volatile int *)&v3[1].mPrev[5].mNext);
      v6 = v3->mPrev;
      v7 = v3->mNext;
      v6->mNext = v7;
      v7->mPrev = v6;
      v3->mPrev = v3;
      v3->mNext = v3;
      UFG::qMemoryPool::Free(UFG::gMainMemoryPool, v3);
    }
    while ( v2[1] != (char *)v2 );
  }
  return 1;
}

// File Line: 1036
// RVA: 0x160530
void __fastcall UFG::LoadedChunkFile::LoadedChunkFile(UFG::LoadedChunkFile *this, unsigned int filename_uid, unsigned int resource_uid, const char *filename, UFG::AllocationProfile *profile)
{
  const char *v5; // rdi
  unsigned int v6; // ebx
  UFG::LoadedChunkFile *v7; // rsi
  unsigned int v8; // er9
  char *v9; // r8
  char v10; // al
  UFG::qNode<UFG::qString,UFG::qString> *v11; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *v12; // rax
  UFG::qString result; // [rsp+38h] [rbp-30h]

  v5 = filename;
  v6 = filename_uid;
  v7 = this;
  UFG::ResourceFile::ResourceFile((UFG::ResourceFile *)&this->mNode, resource_uid, profile);
  UFG::qString::qString(&v7->mFilename, v5);
  v7->mNode.mNode.mParent = 0i64;
  v7->mNode.mNode.mChild[0] = 0i64;
  v7->mNode.mNode.mChild[1] = 0i64;
  v7->mNode.mNode.mUID = 1;
  v7->mHotswapFilenameUID = 0;
  v7->mNode.mNode.mUID = v6;
  v7->mNode.mValue = v7;
  UFG::qSPrintf(v7->mDebugName, 36, "RF-LoadedChunkFile uid: 0x%08x", v6);
  ++UFG::LoadedChunkFile::sLoadedChunkFileCount;
  ++UFG::LoadedChunkFile::sLoadedChunkFileTotal;
  UFG::qFileMapFilename(&result, FILE_MAP_TYPE_HOT_SWAP, v5);
  v8 = result.mStringHashUpper32;
  if ( result.mStringHashUpper32 == -1 )
  {
    if ( result.mData )
    {
      v9 = result.mData;
      v10 = *result.mData;
      if ( *result.mData )
      {
        do
        {
          if ( v10 <= 122 && v10 >= 97 )
            v10 -= 32;
          ++v9;
          v8 = (v8 << 8) ^ sCrcTable32[(unsigned __int8)(v10 ^ HIBYTE(v8))];
          v10 = *v9;
        }
        while ( *v9 );
      }
    }
    result.mStringHashUpper32 = v8;
  }
  v7->mHotswapFilenameUID = v8;
  UFG::qPrintChannel::Print(
    &UFG::qChunkFileSystem::mResourceChannel,
    OUTPUT_LEVEL_WARNING,
    "Created hotswap uid 0x%08x (%10u) for filename %s\n");
  if ( result.mData != UFG::qString::sEmptyString && result.mData )
    UFG::qMemoryPool::Free(UFG::gMainMemoryPool, result.mData);
  v11 = result.mPrev;
  v12 = result.mNext;
  result.mPrev->mNext = result.mNext;
  v12->mPrev = v11;
}

// File Line: 1051
// RVA: 0x162F30
UFG::LoadedChunkFile::~LoadedChunkFile

// File Line: 1123
// RVA: 0x1770F0
bool __fastcall UFG::LoadedChunkFile::LoadSync(UFG::LoadedChunkFile *this)
{
  UFG::LoadedChunkFile *v1; // rdi
  char *v2; // rsi
  __int64 v3; // r14
  UFG::qFile *v4; // rax
  UFG::qFile *v5; // rbp
  const char *v6; // r8
  char *v7; // rax
  UFG::AllocationProfile *v8; // rcx
  unsigned int v9; // edx
  char *v10; // r15
  UFG::eProfileType v11; // eax
  void *v12; // rax
  void *v13; // rax
  char *v14; // rax
  UFG::AllocationProfile *v15; // rax
  UFG::AllocationProfile *v16; // rax
  __int64 v17; // r9
  char *userdata32; // ST20_8

  v1 = this;
  v2 = UFG::LoadedChunkFile::GetChunkFilename(this);
  v3 = UFG::qGetFileSize(v2);
  if ( v3 <= 0 )
  {
    v17 = v1->mNode.mUID;
    userdata32 = v1->mFilename.mData;
    UFG::qPrintChannel::Print(
      &UFG::qChunkFileSystem::mResourceChannel,
      OUTPUT_LEVEL_ERROR,
      "[Resource - LoadChunkFile] skipping uid=0x%08x, file %s does not exist or size is 0\n");
    v1->mState = 2;
    LOBYTE(v4) = 0;
    return (char)v4;
  }
  v4 = UFG::qOpen(v2, QACCESS_READ, 1);
  v5 = v4;
  if ( !v4 )
    return (char)v4;
  v6 = v1->mFilename.mData;
  if ( !v6 )
    v6 = v1->mDebugName;
  v7 = UFG::ResourceMemoryHandle::AllocateBuffer(
         &v1->mMemoryHandle,
         v3,
         v6,
         (unsigned __int64)v1->mNode.mUID << 32,
         0xE8C45525);
  v8 = v1->mMemoryHandle.mAllocationProfile;
  v9 = v1->mNode.mUID;
  v10 = v7;
  if ( v8 )
  {
    v11 = v8->mProfileType;
    if ( v11 == eProfileType_MemoryPool )
    {
      v12 = v1->mMemoryHandle.mAllocateReturned;
      goto LABEL_13;
    }
    if ( v11 != 1 )
    {
      if ( v11 == 2 )
        v13 = v1->mMemoryHandle.mAllocateReturned;
      goto LABEL_13;
    }
  }
  v14 = v1->mMemoryHandle.mVRAMemoryHandle.mData;
LABEL_13:
  UFG::qPrintChannel::Print(
    &UFG::qChunkFileSystem::mResourceChannel,
    OUTPUT_LEVEL_WARNING,
    "[Resource - LoadSync]     Starting read of 0x%08x64 bytes to buffer 0x%08x for uid:0x%08x from file %s\n");
  v15 = v1->mMemoryHandle.mAllocationProfile;
  if ( !v15 || v15->mProfileType == 1 && v1->mMemoryHandle.mVRAMemoryHandle.mData )
    UFG::qVRAMemoryPools::Lock(&v1->mMemoryHandle.mVRAMemoryHandle);
  v1->mValidDataSize = UFG::qRead(v5, v10, v3, 0i64, QSEEK_CUR);
  v16 = v1->mMemoryHandle.mAllocationProfile;
  if ( !v16 || v16->mProfileType == 1 && v1->mMemoryHandle.mVRAMemoryHandle.mData )
    UFG::qVRAMemoryPools::Unlock(&v1->mMemoryHandle.mVRAMemoryHandle);
  UFG::qClose(v5);
  UFG::ResourceFile::WarehouseLoad((UFG::ResourceFile *)&v1->mNode);
  LOBYTE(v4) = 1;
  return (char)v4;
}

// File Line: 1178
// RVA: 0x16F610
char *__fastcall UFG::LoadedChunkFile::GetChunkFilename(UFG::LoadedChunkFile *this)
{
  unsigned int v1; // edx
  UFG::LoadedChunkFile *v2; // r9
  UFG::qTreeRB<UFG::qHotswappedFile,UFG::qHotswappedFile,1> *v3; // rax
  unsigned int v4; // er8
  char *result; // rax
  UFG::qTreeRB<UFG::qHotswappedFile,UFG::qHotswappedFile,1> *i; // rcx

  v1 = this->mHotswapFilenameUID;
  v2 = this;
  if ( !v1 )
    goto LABEL_9;
  v3 = &UFG::qChunkFileSystem::mHotswappedFiles;
  while ( 1 )
  {
    v4 = v3->mTree.mRoot.mUID;
    if ( v3 != &UFG::qChunkFileSystem::mHotswappedFiles && v4 == v1 )
      break;
    if ( v1 > v4 )
      v3 = (UFG::qTreeRB<UFG::qHotswappedFile,UFG::qHotswappedFile,1> *)v3->mTree.mRoot.mChild[1];
    else
      v3 = (UFG::qTreeRB<UFG::qHotswappedFile,UFG::qHotswappedFile,1> *)v3->mTree.mRoot.mChild[0];
    if ( v3 == (UFG::qTreeRB<UFG::qHotswappedFile,UFG::qHotswappedFile,1> *)&UFG::qChunkFileSystem::mHotswappedFiles.mTree.mNULL )
      goto LABEL_9;
  }
  for ( i = (UFG::qTreeRB<UFG::qHotswappedFile,UFG::qHotswappedFile,1> *)v3->mTree.mRoot.mChild[0];
        i;
        i = (UFG::qTreeRB<UFG::qHotswappedFile,UFG::qHotswappedFile,1> *)i->mTree.mRoot.mChild[0] )
  {
    if ( i->mTree.mRoot.mUID != v1 )
      break;
    v3 = i;
  }
  if ( v3 )
    result = *(char **)&v3->mTree.mNULL.mUID;
  else
LABEL_9:
    result = v2->mFilename.mData;
  return result;
}

// File Line: 1203
// RVA: 0x160460
void __fastcall UFG::LoadedChunk::LoadedChunk(UFG::LoadedChunk *this, unsigned int uid, UFG::AllocationProfile *profile, unsigned int allocation_size)
{
  unsigned int v4; // esi
  unsigned int v5; // edi
  UFG::LoadedChunk *v6; // rbp

  v4 = allocation_size;
  v5 = uid;
  v6 = this;
  UFG::ResourceFile::ResourceFile((UFG::ResourceFile *)&this->mNode, uid, profile);
  v6->mTransactionNum = ++UFG::LoadedChunk::sLoadedChunkTotal;
  v6->mNode.mNode.mParent = 0i64;
  v6->mNode.mNode.mChild[0] = 0i64;
  v6->mNode.mNode.mChild[1] = 0i64;
  v6->mNode.mNode.mUID = 1;
  v6->mNode.mNode.mUID = v5;
  v6->mNode.mValue = v6;
  UFG::qSPrintf(v6->mDebugName, 36, "RF-LoadedChunk     uid: 0x%08x", v5);
  UFG::ResourceMemoryHandle::AllocateBuffer(
    &v6->mMemoryHandle,
    v4,
    v6->mDebugName,
    (unsigned __int64)v6->mNode.mUID << 32,
    0xE8C45525);
  ++UFG::LoadedChunk::sLoadedChunkCount;
}

// File Line: 1343
// RVA: 0x160090
void __fastcall UFG::ExternallyLoadedChunk::ExternallyLoadedChunk(UFG::ExternallyLoadedChunk *this, unsigned int uid, void *user_data, UFG::AllocationProfile *profile)
{
  void *v4; // rbx
  unsigned int v5; // edi
  UFG::ExternallyLoadedChunk *v6; // rsi

  v4 = user_data;
  v5 = uid;
  v6 = this;
  UFG::ResourceFile::ResourceFile((UFG::ResourceFile *)&this->mNode, uid, profile);
  v6->mUserData = v4;
  UFG::qSPrintf(v6->mDebugName, 36, "RF-ExternalChunk   uid: 0x%08x", v5, -2i64);
  ++UFG::ExternallyLoadedChunk::sLoadedChunkCount;
  ++UFG::ExternallyLoadedChunk::sLoadedChunkTotal;
}

// File Line: 1354
// RVA: 0x15FFB0
void __fastcall UFG::ExternallyLoadedChunk::ExternallyLoadedChunk(UFG::ExternallyLoadedChunk *this, unsigned int uid, void *user_data, UFG::qVRAMemoryHandle *handle)
{
  UFG::qVRAMemoryHandle *v4; // rsi
  void *v5; // rbx
  unsigned int v6; // edi
  UFG::ExternallyLoadedChunk *v7; // rbp
  UFG::AllocationProfile *v8; // rax
  UFG::eProfileType v9; // eax
  void *v10; // rax
  char *v11; // rax
  char *v12; // ST28_8

  v4 = handle;
  v5 = user_data;
  v6 = uid;
  v7 = this;
  UFG::ResourceFile::ResourceFile((UFG::ResourceFile *)&this->mNode, uid, handle);
  v7->mUserData = v5;
  UFG::qSPrintf(v7->mDebugName, 36, "RF-ExternalChunk   uid: 0x%08x", v6);
  v8 = v7->mMemoryHandle.mAllocationProfile;
  if ( !v8 )
    goto LABEL_7;
  v9 = v8->mProfileType;
  if ( v9 )
  {
    if ( v9 != 1 )
    {
      if ( v9 != 2 )
        goto LABEL_8;
      goto LABEL_3;
    }
LABEL_7:
    v11 = v7->mMemoryHandle.mVRAMemoryHandle.mData;
    goto LABEL_8;
  }
LABEL_3:
  v10 = v7->mMemoryHandle.mAllocateReturned;
LABEL_8:
  v12 = v4->mData;
  UFG::qPrintChannel::Print(
    &UFG::qChunkFileSystem::mResourceChannel,
    OUTPUT_LEVEL_WARNING,
    "[Resource - ReloadSync]     Creating ExternallyLoadedChunk for %s at memory location 0x%08x from 0x%08x\n");
  ++UFG::ExternallyLoadedChunk::sLoadedChunkCount;
  ++UFG::ExternallyLoadedChunk::sLoadedChunkTotal;
}

// File Line: 1370
// RVA: 0x16DDF0
UFG::qTreeRB<UFG::qResourceData,UFG::qResourceData,1> *__fastcall UFG::ExternallyLoadedChunk::FindExistingChunk(unsigned int filename_uid, char *memory_location)
{
  char *v2; // rbp
  unsigned int v3; // esi
  UFG::qTreeRB<UFG::qResourceData,UFG::qResourceData,1> *v4; // rdi
  UFG::qTreeRB<UFG::qResourceData,UFG::qResourceData,1> *v5; // rbx
  unsigned int v6; // eax
  UFG::qBaseNodeRB *v7; // rax
  int v8; // eax
  char *v9; // rax
  UFG::qTreeRB<UFG::qResourceData,UFG::qResourceData,1> *i; // rax
  UFG::qTreeRB<UFG::qResourceData,UFG::qResourceData,1> *v12; // rax
  UFG::qBaseNodeRB *v13; // rcx
  int v14; // ecx
  UFG::qBaseNodeRB *v15; // rcx
  UFG::qTreeRB<UFG::qResourceData,UFG::qResourceData,1> *j; // rcx
  UFG::qTreeRB<UFG::qResourceData,UFG::qResourceData,1> *v17; // rcx
  UFG::qTreeRB<UFG::qResourceData,UFG::qResourceData,1> *v18; // rcx
  UFG::qBaseNodeRB *v19; // rax
  int v20; // eax
  UFG::qBaseNodeRB *v21; // rax
  UFG::qTreeRB<UFG::qResourceData,UFG::qResourceData,1> *k; // rax
  UFG::qTreeRB<UFG::qResourceData,UFG::qResourceData,1> *v23; // rax

  v2 = memory_location;
  v3 = filename_uid;
  v4 = 0i64;
  if ( !filename_uid )
    return 0i64;
  v5 = &stru_14235B050;
  while ( 1 )
  {
    v6 = v5->mTree.mRoot.mUID;
    if ( v5 != &stru_14235B050 && v6 == filename_uid )
      break;
    if ( filename_uid > v6 )
      v5 = (UFG::qTreeRB<UFG::qResourceData,UFG::qResourceData,1> *)v5->mTree.mRoot.mChild[1];
    else
      v5 = (UFG::qTreeRB<UFG::qResourceData,UFG::qResourceData,1> *)v5->mTree.mRoot.mChild[0];
    if ( v5 == (UFG::qTreeRB<UFG::qResourceData,UFG::qResourceData,1> *)&stru_14235B050.mTree.mNULL )
    {
      v5 = 0i64;
      goto LABEL_10;
    }
  }
  for ( i = (UFG::qTreeRB<UFG::qResourceData,UFG::qResourceData,1> *)v5->mTree.mRoot.mChild[0];
        i;
        i = (UFG::qTreeRB<UFG::qResourceData,UFG::qResourceData,1> *)i->mTree.mRoot.mChild[0] )
  {
    if ( i->mTree.mRoot.mUID != filename_uid )
      break;
    v5 = i;
  }
LABEL_10:
  if ( !v5 )
    return 0i64;
  v7 = v5[2].mTree.mRoot.mChild[0];
  if ( !v7 )
    goto LABEL_75;
  v8 = HIDWORD(v7->mChild[1]);
  if ( !v8 )
  {
    v9 = (char *)v5[2].mTree.mRoot.mParent;
    goto LABEL_23;
  }
  if ( v8 != 1 )
  {
    if ( v8 == 2 )
      v9 = (char *)v5[2].mTree.mRoot.mParent;
    else
      v9 = 0i64;
  }
  else
  {
LABEL_75:
    v9 = (char *)v5[1].mTree.mNULL.mChild[1];
  }
LABEL_23:
  if ( v9 == memory_location )
    return v5;
  v12 = (UFG::qTreeRB<UFG::qResourceData,UFG::qResourceData,1> *)UFG::qTreeRB<UFG::qResourceData,UFG::qResourceData,1>::GetPrev(
                                                                   &stru_14235B050,
                                                                   (UFG::qNodeRB<UFG::qResourceData> *)v5);
  while ( v12 && v12->mTree.mRoot.mUID == v3 )
  {
    v13 = v12[2].mTree.mRoot.mChild[0];
    if ( !v13 )
      goto LABEL_35;
    v14 = HIDWORD(v13->mChild[1]);
    if ( v14 )
    {
      if ( v14 != 1 )
      {
        if ( v14 == 2 )
          v15 = v12[2].mTree.mRoot.mParent;
        else
          v15 = 0i64;
        goto LABEL_36;
      }
LABEL_35:
      v15 = v12[1].mTree.mNULL.mChild[1];
      goto LABEL_36;
    }
    v15 = v12[2].mTree.mRoot.mParent;
LABEL_36:
    if ( v15 == (UFG::qBaseNodeRB *)v2 )
      v4 = v12;
    v12 = (UFG::qTreeRB<UFG::qResourceData,UFG::qResourceData,1> *)v5->mTree.mRoot.mChild[0];
    if ( &stru_14235B050.mTree.mNULL == (UFG::qBaseNodeRB *)v12 )
    {
      v12 = (UFG::qTreeRB<UFG::qResourceData,UFG::qResourceData,1> *)((_QWORD)v5->mTree.mRoot.mParent & 0xFFFFFFFFFFFFFFFEui64);
      if ( v5 == (UFG::qTreeRB<UFG::qResourceData,UFG::qResourceData,1> *)v12->mTree.mRoot.mChild[0] )
      {
        while ( v12 != &stru_14235B050 )
        {
          v17 = v12;
          v12 = (UFG::qTreeRB<UFG::qResourceData,UFG::qResourceData,1> *)((_QWORD)v12->mTree.mRoot.mParent & 0xFFFFFFFFFFFFFFFEui64);
          if ( v17 != (UFG::qTreeRB<UFG::qResourceData,UFG::qResourceData,1> *)v12->mTree.mRoot.mChild[0] )
            goto LABEL_47;
        }
        v12 = 0i64;
      }
    }
    else
    {
      for ( j = (UFG::qTreeRB<UFG::qResourceData,UFG::qResourceData,1> *)v12->mTree.mRoot.mChild[1];
            j != (UFG::qTreeRB<UFG::qResourceData,UFG::qResourceData,1> *)&stru_14235B050.mTree.mNULL;
            j = (UFG::qTreeRB<UFG::qResourceData,UFG::qResourceData,1> *)j->mTree.mRoot.mChild[1] )
      {
        v12 = j;
      }
    }
LABEL_47:
    if ( v4 )
      break;
  }
  v18 = (UFG::qTreeRB<UFG::qResourceData,UFG::qResourceData,1> *)UFG::qTreeRB<UFG::qResourceData,UFG::qResourceData,1>::GetNext(
                                                                   &stru_14235B050,
                                                                   (UFG::qNodeRB<UFG::qResourceData> *)v5);
  if ( !v4 )
  {
    while ( 1 )
    {
      if ( !v18 || v18->mTree.mRoot.mUID != v3 )
        return v4;
      v19 = v18[2].mTree.mRoot.mChild[0];
      if ( !v19 )
        goto LABEL_58;
      v20 = HIDWORD(v19->mChild[1]);
      if ( v20 )
        break;
      v21 = v18[2].mTree.mRoot.mParent;
LABEL_59:
      if ( v21 == (UFG::qBaseNodeRB *)v2 )
        v4 = v18;
      v18 = (UFG::qTreeRB<UFG::qResourceData,UFG::qResourceData,1> *)v5->mTree.mRoot.mChild[1];
      if ( &stru_14235B050.mTree.mNULL == (UFG::qBaseNodeRB *)v18 )
      {
        v18 = (UFG::qTreeRB<UFG::qResourceData,UFG::qResourceData,1> *)((_QWORD)v5->mTree.mRoot.mParent & 0xFFFFFFFFFFFFFFFEui64);
        if ( v5 == (UFG::qTreeRB<UFG::qResourceData,UFG::qResourceData,1> *)v18->mTree.mRoot.mChild[1] )
        {
          do
          {
            v23 = v18;
            v18 = (UFG::qTreeRB<UFG::qResourceData,UFG::qResourceData,1> *)((_QWORD)v18->mTree.mRoot.mParent & 0xFFFFFFFFFFFFFFFEui64);
          }
          while ( v23 == (UFG::qTreeRB<UFG::qResourceData,UFG::qResourceData,1> *)v18->mTree.mRoot.mChild[1] );
        }
        if ( v18 == &stru_14235B050 )
          v18 = 0i64;
      }
      else
      {
        for ( k = (UFG::qTreeRB<UFG::qResourceData,UFG::qResourceData,1> *)v18->mTree.mRoot.mChild[0];
              k != (UFG::qTreeRB<UFG::qResourceData,UFG::qResourceData,1> *)&stru_14235B050.mTree.mNULL;
              k = (UFG::qTreeRB<UFG::qResourceData,UFG::qResourceData,1> *)k->mTree.mRoot.mChild[0] )
        {
          v18 = k;
        }
      }
      if ( v4 )
        return v4;
    }
    if ( v20 != 1 )
    {
      if ( v20 == 2 )
        v21 = v18[2].mTree.mRoot.mParent;
      else
        v21 = 0i64;
      goto LABEL_59;
    }
LABEL_58:
    v21 = v18[1].mTree.mNULL.mChild[1];
    goto LABEL_59;
  }
  return v4;
}

// File Line: 1416
// RVA: 0x166560
void __fastcall UFG::ExternallyLoadedChunk::AddNewChunk(unsigned int filename_uid, char *memory_location, unsigned __int64 location_size, void *user_data)
{
  void *v4; // rsi
  unsigned int v5; // ebp
  UFG::AllocationProfile *v6; // rbx
  const char *v7; // rdi
  UFG::qMemoryPool *v8; // rcx
  char *v9; // rax
  __int64 v10; // rax
  __int64 v11; // rdx
  UFG::qNode<UFG::ResourceFile,UFG::ZeroRefResourceFile> **v12; // rcx
  UFG::qNode<UFG::ResourceFile,UFG::ZeroRefResourceFile> *v13; // rax
  bool v14; // zf
  UFG::qNode<UFG::AllocationProfile,UFG::AllocationProfile> *v15; // rcx
  UFG::qNode<UFG::AllocationProfile,UFG::AllocationProfile> *v16; // rax

  v4 = user_data;
  v5 = filename_uid;
  v6 = UFG::AllocationProfile::CreateAllocationProfile(memory_location, location_size);
  v7 = UFG::gGlobalNewName;
  v8 = UFG::gMainMemoryPool;
  if ( !UFG::gMainMemoryPool )
  {
    UFG::InternalSetupMainMemoryPool((UFG *)UFG::gMainMemoryPool);
    v8 = UFG::gMainMemoryPool;
  }
  v9 = UFG::qMemoryPool::Allocate(v8, 0xD0ui64, v7, 0i64, 1u);
  if ( v9 )
  {
    UFG::ExternallyLoadedChunk::ExternallyLoadedChunk((UFG::ExternallyLoadedChunk *)v9, v5, v4, v6);
    v11 = v10;
  }
  else
  {
    v11 = 0i64;
  }
  if ( *(_QWORD *)(v11 + 200) )
  {
    v12 = (UFG::qNode<UFG::ResourceFile,UFG::ZeroRefResourceFile> **)(v11 + 88);
    v13 = stru_14235B120.mNode.mPrev;
    stru_14235B120.mNode.mPrev->mNext = (UFG::qNode<UFG::ResourceFile,UFG::ZeroRefResourceFile> *)(v11 + 88);
    *v12 = v13;
    v12[1] = (UFG::qNode<UFG::ResourceFile,UFG::ZeroRefResourceFile> *)&stru_14235B120;
    stru_14235B120.mNode.mPrev = (UFG::qNode<UFG::ResourceFile,UFG::ZeroRefResourceFile> *)(v11 + 88);
  }
  UFG::qResourceInventory::Add((UFG::qResourceInventory *)&UFG::gResourceFileInventory.vfptr, (UFG::qResourceData *)v11);
  v14 = v6->mRefCount-- == 1;
  if ( v14 )
  {
    --UFG::AllocationProfile::sActiveProfilesCount[v6->mProfileType];
    v15 = v6->mPrev;
    v16 = v6->mNext;
    v15->mNext = v16;
    v16->mPrev = v15;
    v6->mPrev = (UFG::qNode<UFG::AllocationProfile,UFG::AllocationProfile> *)&v6->mPrev;
    v6->mNext = (UFG::qNode<UFG::AllocationProfile,UFG::AllocationProfile> *)&v6->mPrev;
    UFG::qMemoryPool::Free(UFG::gMainMemoryPool, v6);
  }
}

// File Line: 1425
// RVA: 0x166490
void __fastcall UFG::ExternallyLoadedChunk::AddNewChunk(unsigned int filename_uid, UFG::qVRAMemoryHandle *handle, void *user_data)
{
  void *v3; // rdi
  UFG::qVRAMemoryHandle *v4; // rsi
  unsigned int v5; // ebp
  const char *v6; // rbx
  UFG::qMemoryPool *v7; // rcx
  char *v8; // rax
  __int64 v9; // rax
  __int64 v10; // rdx
  UFG::qNode<UFG::ResourceFile,UFG::ZeroRefResourceFile> **v11; // rcx
  UFG::qNode<UFG::ResourceFile,UFG::ZeroRefResourceFile> *v12; // rax

  v3 = user_data;
  v4 = handle;
  v5 = filename_uid;
  v6 = UFG::gGlobalNewName;
  v7 = UFG::gMainMemoryPool;
  if ( !UFG::gMainMemoryPool )
  {
    UFG::InternalSetupMainMemoryPool((UFG *)UFG::gMainMemoryPool);
    v7 = UFG::gMainMemoryPool;
  }
  v8 = UFG::qMemoryPool::Allocate(v7, 0xD0ui64, v6, 0i64, 1u);
  if ( v8 )
  {
    UFG::ExternallyLoadedChunk::ExternallyLoadedChunk((UFG::ExternallyLoadedChunk *)v8, v5, v3, v4);
    v10 = v9;
  }
  else
  {
    v10 = 0i64;
  }
  if ( *(_QWORD *)(v10 + 200) )
  {
    v11 = (UFG::qNode<UFG::ResourceFile,UFG::ZeroRefResourceFile> **)(v10 + 88);
    v12 = stru_14235B120.mNode.mPrev;
    stru_14235B120.mNode.mPrev->mNext = (UFG::qNode<UFG::ResourceFile,UFG::ZeroRefResourceFile> *)(v10 + 88);
    *v11 = v12;
    v11[1] = (UFG::qNode<UFG::ResourceFile,UFG::ZeroRefResourceFile> *)&stru_14235B120;
    stru_14235B120.mNode.mPrev = (UFG::qNode<UFG::ResourceFile,UFG::ZeroRefResourceFile> *)(v10 + 88);
  }
  UFG::qResourceInventory::Add((UFG::qResourceInventory *)&UFG::gResourceFileInventory.vfptr, (UFG::qResourceData *)v10);
}

// File Line: 1449
// RVA: 0x17A830
void __fastcall UFG::ExternallyLoadedChunk::RemoveExistingChunk(unsigned int filename_uid, UFG::qVRAMemoryHandle *handle)
{
  UFG::qVRAMemoryHandle *v2; // rbx
  unsigned int v3; // edi
  UFG::qResourceData *v4; // rax
  UFG::ResourceFile *v5; // rbx

  v2 = handle;
  v3 = filename_uid;
  UFG::qVRAMemoryPools::GetRequestedSize(handle);
  v4 = (UFG::qResourceData *)UFG::ExternallyLoadedChunk::FindExistingChunk(v3, v2->mData);
  v5 = (UFG::ResourceFile *)v4;
  if ( v4 )
  {
    UFG::qResourceInventory::Remove((UFG::qResourceInventory *)&UFG::gResourceFileInventory.vfptr, v4);
    --UFG::ExternallyLoadedChunk::sLoadedChunkCount;
    UFG::ResourceFile::~ResourceFile(v5);
    UFG::qMemoryPool::Free(UFG::gMainMemoryPool, v5);
  }
  else
  {
    UFG::qResourceFileInventory::PrintContents(&UFG::gResourceFileInventory);
  }
}

// File Line: 1493
// RVA: 0x162FB0
void __fastcall UFG::LoadedIndexFile::~LoadedIndexFile(UFG::LoadedIndexFile *this)
{
  UFG::LoadedIndexFile *v1; // rdi
  UFG::qString *v2; // rbx
  char *v3; // rdx
  UFG::qNode<UFG::qString,UFG::qString> *v4; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *v5; // rax
  UFG::qString *v6; // rbx
  char *v7; // rdx
  UFG::qNode<UFG::qString,UFG::qString> *v8; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *v9; // rax
  UFG::qNode<UFG::LoadedIndexFile,UFG::LoadedIndexFile> *v10; // rcx
  UFG::qNode<UFG::LoadedIndexFile,UFG::LoadedIndexFile> *v11; // rax

  v1 = this;
  UFG::qTypedResourceHandle<4117364251,UFG::qChunkFileIndex>::~qTypedResourceHandle<4117364251,UFG::qChunkFileIndex>((UFG::qTypedResourceHandle<4117364251,UFG::qChunkFileIndex> *)&this->mChunkFileIndexHandle.mPrev);
  v2 = &v1->mChunkFilename;
  v3 = v1->mChunkFilename.mData;
  if ( v3 != UFG::qString::sEmptyString && v3 )
    UFG::qMemoryPool::Free(UFG::gMainMemoryPool, v3);
  v1->mChunkFilename.mMagic = 0;
  v4 = v2->mPrev;
  v5 = v1->mChunkFilename.mNext;
  v4->mNext = v5;
  v5->mPrev = v4;
  v2->mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&v2->mPrev;
  v1->mChunkFilename.mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&v1->mChunkFilename.mPrev;
  v6 = &v1->mIndexFilename;
  v7 = v1->mIndexFilename.mData;
  if ( v7 != UFG::qString::sEmptyString && v7 )
    UFG::qMemoryPool::Free(UFG::gMainMemoryPool, v7);
  v1->mIndexFilename.mMagic = 0;
  v8 = v6->mPrev;
  v9 = v1->mIndexFilename.mNext;
  v8->mNext = v9;
  v9->mPrev = v8;
  v6->mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&v6->mPrev;
  v1->mIndexFilename.mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&v1->mIndexFilename.mPrev;
  v10 = v1->mPrev;
  v11 = v1->mNext;
  v10->mNext = v11;
  v11->mPrev = v10;
  v1->mPrev = (UFG::qNode<UFG::LoadedIndexFile,UFG::LoadedIndexFile> *)&v1->mPrev;
  v1->mNext = (UFG::qNode<UFG::LoadedIndexFile,UFG::LoadedIndexFile> *)&v1->mPrev;
}

// File Line: 1498
// RVA: 0x16F680
char *__fastcall UFG::LoadedIndexFile::GetChunkFilename(UFG::LoadedIndexFile *this)
{
  unsigned int v1; // edx
  UFG::LoadedIndexFile *v2; // r9
  UFG::qTreeRB<UFG::qHotswappedFile,UFG::qHotswappedFile,1> *v3; // rax
  unsigned int v4; // er8
  char *result; // rax
  UFG::qTreeRB<UFG::qHotswappedFile,UFG::qHotswappedFile,1> *i; // rcx

  v1 = this->mHotswapChunkFilenameUID;
  v2 = this;
  if ( !v1 )
    goto LABEL_9;
  v3 = &UFG::qChunkFileSystem::mHotswappedFiles;
  while ( 1 )
  {
    v4 = v3->mTree.mRoot.mUID;
    if ( v3 != &UFG::qChunkFileSystem::mHotswappedFiles && v4 == v1 )
      break;
    if ( v1 > v4 )
      v3 = (UFG::qTreeRB<UFG::qHotswappedFile,UFG::qHotswappedFile,1> *)v3->mTree.mRoot.mChild[1];
    else
      v3 = (UFG::qTreeRB<UFG::qHotswappedFile,UFG::qHotswappedFile,1> *)v3->mTree.mRoot.mChild[0];
    if ( v3 == (UFG::qTreeRB<UFG::qHotswappedFile,UFG::qHotswappedFile,1> *)&UFG::qChunkFileSystem::mHotswappedFiles.mTree.mNULL )
      goto LABEL_9;
  }
  for ( i = (UFG::qTreeRB<UFG::qHotswappedFile,UFG::qHotswappedFile,1> *)v3->mTree.mRoot.mChild[0];
        i;
        i = (UFG::qTreeRB<UFG::qHotswappedFile,UFG::qHotswappedFile,1> *)i->mTree.mRoot.mChild[0] )
  {
    if ( i->mTree.mRoot.mUID != v1 )
      break;
    v3 = i;
  }
  if ( v3 )
    result = *(char **)&v3->mTree.mNULL.mUID;
  else
LABEL_9:
    result = v2->mChunkFilename.mData;
  return result;
}

// File Line: 1519
// RVA: 0x170510
char *__fastcall UFG::qResourceFileHandle::GetFileData(UFG::qResourceFileHandle *this, int offset)
{
  UFG::qResourceData *v2; // rax
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v3; // r8
  __int64 v4; // rcx
  int v5; // ecx

  v2 = this->mData;
  v3 = 0i64;
  if ( !v2 )
    return 0i64;
  v4 = *(_QWORD *)&v2[1].mDebugName[12];
  if ( !v4 )
    goto LABEL_12;
  v5 = *(_DWORD *)(v4 + 20);
  if ( !v5 )
    return (char *)(*(_QWORD *)&v2[1].mDebugName[4] + offset);
  if ( v5 != 1 )
  {
    if ( v5 == 2 )
      return (char *)(*(_QWORD *)&v2[1].mDebugName[4] + offset);
  }
  else
  {
LABEL_12:
    v3 = v2[1].mResourceHandles.mNode.mPrev;
  }
  return (char *)v3 + offset;
}

// File Line: 1566
// RVA: 0x173590
void __fastcall UFG::qResourceInventory::Init(UFG::qResourceInventory *this)
{
  const char *v1; // r9

  v1 = this->mName;
  UFG::qPrintChannel::Print(&gInventoryChannel, OUTPUT_LEVEL_DEBUG, "[%s] Init()\n");
}

// File Line: 1571
// RVA: 0x167F30
void __fastcall UFG::qResourceFileInventory::Close(UFG::qResourceFileInventory *this)
{
  UFG::qResourceInventory::Close((UFG::qResourceInventory *)&this->vfptr);
}

// File Line: 1576
// RVA: 0x165730
void __fastcall UFG::qResourceFileInventory::Add(UFG::qResourceFileInventory *this, UFG::qResourceData *data)
{
  UFG::qResourceData *v2; // r8
  UFG::qNode<UFG::ResourceFile,UFG::ZeroRefResourceFile> *v3; // rax

  if ( *(_QWORD *)&data[2].mNode.mUID )
  {
    v2 = data + 1;
    v3 = this->mZeroRefResourceFiles.mNode.mPrev;
    v3->mNext = (UFG::qNode<UFG::ResourceFile,UFG::ZeroRefResourceFile> *)&data[1];
    v2->mNode.mParent = (UFG::qBaseNodeRB *)v3;
    v2->mNode.mChild[0] = (UFG::qBaseNodeRB *)&this->mZeroRefResourceFiles;
    this->mZeroRefResourceFiles.mNode.mPrev = (UFG::qNode<UFG::ResourceFile,UFG::ZeroRefResourceFile> *)&data[1];
  }
  UFG::qResourceInventory::Add((UFG::qResourceInventory *)&this->vfptr, data);
}

// File Line: 1588
// RVA: 0x178670
void __fastcall UFG::qResourceFileInventory::OnAttachHandle(UFG::qResourceFileInventory *this, UFG::qResourceHandle *handle, UFG::qResourceData *data)
{
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v3; // r9
  UFG::qResourceData *v4; // rbx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v5; // r8
  UFG::qResourceHandle *v6; // rcx
  UFG::qResourceData *v7; // rdx
  UFG::qBaseNodeRB *v8; // rax

  v3 = handle[1].mPrev;
  v4 = data;
  if ( v3 )
  {
    v5 = handle[1].mNext;
    v6 = handle;
    LOBYTE(handle) = 1;
    ((void (__fastcall *)(UFG::qResourceHandle *, UFG::qResourceHandle *, UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *))v3)(
      v6,
      handle,
      v5);
  }
  if ( *(_QWORD *)&v4[2].mNode.mUID )
  {
    v7 = (UFG::qResourceData *)v4[1].mNode.mParent;
    if ( v7 != &v4[1] || (UFG::qResourceData *)v4[1].mNode.mChild[0] != &v4[1] )
    {
      v8 = v4[1].mNode.mChild[0];
      v7->mNode.mChild[0] = v8;
      v8->mParent = &v7->mNode;
      v4[1].mNode.mParent = &v4[1].mNode;
      v4[1].mNode.mChild[0] = &v4[1].mNode;
    }
  }
}

// File Line: 1607
// RVA: 0x1786D0
void __fastcall UFG::qResourceFileInventory::OnDetachHandle(UFG::qResourceFileInventory *this, UFG::qResourceHandle *handle, UFG::qResourceData *data)
{
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v3; // r9
  UFG::qResourceData *v4; // rbx
  UFG::qResourceFileInventory *v5; // rdi
  UFG::qResourceData *v6; // rcx
  UFG::qNode<UFG::ResourceFile,UFG::ZeroRefResourceFile> *v7; // rax

  v3 = handle[1].mPrev;
  v4 = data;
  v5 = this;
  if ( v3 )
    ((void (__fastcall *)(UFG::qResourceHandle *, _QWORD, UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *))v3)(
      handle,
      0i64,
      handle[1].mNext);
  if ( *(_QWORD *)&v4[2].mNode.mUID )
  {
    if ( (UFG::qList<UFG::qResourceHandle,UFG::qResourceHandle,1,0> *)v4->mResourceHandles.mNode.mNext == &v4->mResourceHandles )
    {
      v6 = v4 + 1;
      v7 = v5->mZeroRefResourceFiles.mNode.mPrev;
      v7->mNext = (UFG::qNode<UFG::ResourceFile,UFG::ZeroRefResourceFile> *)&v4[1];
      v6->mNode.mParent = (UFG::qBaseNodeRB *)v7;
      v6->mNode.mChild[0] = (UFG::qBaseNodeRB *)&v5->mZeroRefResourceFiles;
      v5->mZeroRefResourceFiles.mNode.mPrev = (UFG::qNode<UFG::ResourceFile,UFG::ZeroRefResourceFile> *)&v4[1];
    }
  }
}

// File Line: 1627
// RVA: 0x179250
void __fastcall UFG::qResourceFileInventory::PrintContents(UFG::qResourceFileInventory *this)
{
  UFG::qResourceFileInventory *v1; // r13
  UFG::qBaseNodeRB *v2; // rcx
  signed __int64 v3; // r13
  UFG::qBaseNodeRB *v4; // rax
  signed __int64 i; // rbp
  UFG::qBaseNodeRB *v6; // rdi
  __int64 v7; // rax
  int v8; // eax
  UFG::qBaseNodeRB *v9; // rcx
  unsigned int v10; // er14
  unsigned __int16 v11; // ax
  UFG::qVRAMemoryPool *v12; // rsi
  unsigned __int16 v13; // ax
  unsigned __int16 v14; // cx
  UFG::BlockInfo *v15; // rax
  __int64 v16; // rax
  int v17; // eax
  signed __int64 v18; // r8
  signed __int64 v19; // r9
  UFG::qBaseNodeRB *v20; // rcx
  UFG::qBaseNodeRB *j; // rax
  UFG::qBaseNodeRB *v22; // rax
  UFG::qBaseNodeRB *v23; // rcx
  __int64 v24; // [rsp+20h] [rbp-48h]
  __int64 v25; // [rsp+28h] [rbp-40h]

  v1 = this;
  UFG::qPrintf("Contents of Inventory %.64s %d items\n", this->mName, (unsigned int)this->mResourceDatas.mTree.mCount);
  v2 = v1->mResourceDatas.mTree.mRoot.mChild[0];
  v3 = (signed __int64)&v1->mResourceDatas;
  v4 = v2->mChild[0];
  for ( i = v3 + 32; v4 != (UFG::qBaseNodeRB *)i; v4 = v4->mChild[0] )
    v2 = v4;
  v6 = 0i64;
  if ( v2 != (UFG::qBaseNodeRB *)i )
    v6 = v2;
  if ( v6 )
  {
    while ( 1 )
    {
      v7 = *(_QWORD *)&v6[4].mUID;
      if ( !v7 )
        break;
      v8 = *(_DWORD *)(v7 + 20);
      if ( v8 )
      {
        if ( v8 == 1 )
        {
          LODWORD(v9) = UFG::qVRAMemoryPools::GetRequestedSize((UFG::qVRAMemoryHandle *)v6[3].mChild);
        }
        else if ( v8 == 2 )
        {
          v9 = v6[4].mChild[0];
        }
        else
        {
          LODWORD(v9) = 0;
        }
      }
      else
      {
        v9 = v6[4].mChild[0];
      }
LABEL_27:
      v16 = *(_QWORD *)&v6[4].mUID;
      if ( !v16 )
        goto LABEL_34;
      v17 = *(_DWORD *)(v16 + 20);
      if ( v17 )
      {
        if ( v17 == 1 )
        {
LABEL_34:
          v18 = *(_QWORD *)&v6[3].mUID;
          goto LABEL_35;
        }
        if ( v17 == 2 )
          v18 = (signed __int64)v6[4].mChild[1];
        else
          v18 = 0i64;
      }
      else
      {
        v18 = (signed __int64)v6[4].mChild[1];
      }
LABEL_35:
      if ( (_DWORD)v9 )
        v19 = (unsigned int)v9 + v18 - 1;
      else
        v19 = v18;
      LODWORD(v25) = (_DWORD)v9;
      LODWORD(v24) = (_DWORD)v9;
      UFG::qPrintf(
        "  - Resource DataUID:0x%08x Memory:0x%08x-0x%08x Size:0x%08x (%9u) Name:%.36s\n",
        v6->mUID,
        v18,
        v19,
        v24,
        v25,
        (char *)&v6[1].mChild[1] + 4);
      v20 = v6->mChild[1];
      if ( (UFG::qBaseNodeRB *)i == v20 )
      {
        v22 = (UFG::qBaseNodeRB *)((_QWORD)v6->mParent & 0xFFFFFFFFFFFFFFFEui64);
        if ( v6 == v22->mChild[1] )
        {
          do
          {
            v23 = v22;
            v22 = (UFG::qBaseNodeRB *)((_QWORD)v22->mParent & 0xFFFFFFFFFFFFFFFEui64);
          }
          while ( v23 == v22->mChild[1] );
        }
        v6 = v22;
        if ( v22 == (UFG::qBaseNodeRB *)v3 )
          v6 = 0i64;
      }
      else
      {
        for ( j = v20->mChild[0]; j != (UFG::qBaseNodeRB *)i; j = j->mChild[0] )
          v20 = j;
        v6 = v20;
      }
      if ( !v6 )
        return;
    }
    v10 = 0;
    UFG::qMutex::Lock((LPCRITICAL_SECTION)&UFG::qVRAMemoryPools::sVRAMPoolsLock);
    if ( !*(_QWORD *)&v6[3].mUID
      || (v11 = (_QWORD)v6[4].mParent & 0x7FFF, v11 >= 0x10u)
      || (v12 = UFG::qVRAMemoryPools::sVRAMemoryPools[v11]) == 0i64 )
    {
LABEL_26:
      UFG::qMutex::Unlock((LPCRITICAL_SECTION)&UFG::qVRAMemoryPools::sVRAMPoolsLock);
      LODWORD(v9) = v10;
      goto LABEL_27;
    }
    UFG::qMutex::Lock((LPCRITICAL_SECTION)&v12->mPoolLock);
    UFG::qVRAMemoryPool::AssertValid(v12);
    if ( v12->mInitialized == 1 && ((_QWORD)v6[4].mParent & 0x7FFF) == v12->mPoolID )
    {
      v13 = v12->mNumBlocksTotal;
      v14 = WORD1(v6[4].mParent);
      if ( !v13 )
      {
        v15 = UFG::qVRAMemoryPools::GetBlock(v14);
LABEL_23:
        if ( v15 )
          v10 = v15->mRequestedSize;
        goto LABEL_25;
      }
      if ( v14 < v13 )
      {
        v15 = &v12->mBlocks[(unsigned __int64)v14];
        goto LABEL_23;
      }
    }
LABEL_25:
    UFG::qMutex::Unlock((LPCRITICAL_SECTION)&v12->mPoolLock);
    goto LABEL_26;
  }
}

