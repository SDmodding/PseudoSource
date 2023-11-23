// File Line: 32
// RVA: 0x1467F70
__int64 UFG::_dynamic_initializer_for__gResourceFileInventory__()
{
  UFG::qResourceInventory::qResourceInventory(
    &UFG::gResourceFileInventory,
    "Resource File Inventory",
    0xA428072C,
    0,
    0,
    0x40u);
  UFG::gResourceFileInventory.vfptr = (UFG::qResourceInventoryVtbl *)&UFG::qResourceFileInventory::`vftable;
  stru_14235B120.mNode.mPrev = (UFG::qNode<UFG::ResourceFile,UFG::ZeroRefResourceFile> *)&stru_14235B120;
  stru_14235B120.mNode.mNext = (UFG::qNode<UFG::ResourceFile,UFG::ZeroRefResourceFile> *)&stru_14235B120;
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__gResourceFileInventory__);
}

// File Line: 40
// RVA: 0x1467AF0
__int64 dynamic_initializer_for__UFG::AllocationProfile::sProfiles__()
{
  `eh vector constructor iterator(
    (char *)UFG::AllocationProfile::sProfiles,
    0x10ui64,
    3,
    (void (__fastcall *)(void *))UFG::qReflectHandleBase::qReflectHandleBase);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::AllocationProfile::sProfiles__);
}

// File Line: 116
// RVA: 0x16AC80
UFG::qList<UFG::AllocationProfile,UFG::AllocationProfile,1,0> *__fastcall UFG::AllocationProfile::CreateAllocationProfile(
        UFG::qNode<UFG::AllocationProfile,UFG::AllocationProfile> *memory_pool,
        UFG::qNode<UFG::AllocationProfile,UFG::AllocationProfile> *allocation_params)
{
  UFG::qList<UFG::AllocationProfile,UFG::AllocationProfile,1,0> *result; // rax
  UFG::qNode<UFG::AllocationProfile,UFG::AllocationProfile> *mPrev; // rdx
  UFG::qNode<UFG::AllocationProfile,UFG::AllocationProfile> *mNext; // rcx
  UFG::qNode<UFG::AllocationProfile,UFG::AllocationProfile> *v7; // rcx
  UFG::qMemoryPool *v8; // rcx
  UFG::qNode<UFG::AllocationProfile,UFG::AllocationProfile> *v9; // rcx

  for ( result = (UFG::qList<UFG::AllocationProfile,UFG::AllocationProfile,1,0> *)UFG::AllocationProfile::sProfiles[0].mNode.mNext;
        result != UFG::AllocationProfile::sProfiles;
        result = (UFG::qList<UFG::AllocationProfile,UFG::AllocationProfile,1,0> *)result->mNode.mNext )
  {
    if ( result[1].mNode.mNext == allocation_params && result[2].mNode.mPrev == memory_pool )
    {
      mPrev = result->mNode.mPrev;
      mNext = result->mNode.mNext;
      mPrev->mNext = mNext;
      mNext->mPrev = mPrev;
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
    result[1].mNode.mNext = allocation_params;
    result[2].mNode.mPrev = memory_pool;
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
UFG::qList<UFG::AllocationProfile,UFG::AllocationProfile,1,0> *__fastcall UFG::AllocationProfile::CreateAllocationProfile(
        UFG::qNode<UFG::AllocationProfile,UFG::AllocationProfile> *memory_location,
        UFG::qNode<UFG::AllocationProfile,UFG::AllocationProfile> *location_size)
{
  UFG::qList<UFG::AllocationProfile,UFG::AllocationProfile,1,0> *result; // rax
  UFG::qNode<UFG::AllocationProfile,UFG::AllocationProfile> *mPrev; // rdx
  UFG::qNode<UFG::AllocationProfile,UFG::AllocationProfile> *mNext; // rcx
  UFG::qNode<UFG::AllocationProfile,UFG::AllocationProfile> *v7; // rcx
  UFG::qMemoryPool *v8; // rcx
  UFG::qNode<UFG::AllocationProfile,UFG::AllocationProfile> *v9; // rcx

  for ( result = (UFG::qList<UFG::AllocationProfile,UFG::AllocationProfile,1,0> *)UFG::AllocationProfile::sProfiles[2].mNode.mNext;
        result != &UFG::AllocationProfile::sProfiles[2];
        result = (UFG::qList<UFG::AllocationProfile,UFG::AllocationProfile,1,0> *)result->mNode.mNext )
  {
    if ( result[1].mNode.mNext == memory_location && result[2].mNode.mPrev == location_size )
    {
      mPrev = result->mNode.mPrev;
      mNext = result->mNode.mNext;
      mPrev->mNext = mNext;
      mNext->mPrev = mPrev;
      result->mNode.mPrev = &result->mNode;
      result->mNode.mNext = &result->mNode;
      v7 = UFG::AllocationProfile::sProfiles[2].mNode.mNext;
      UFG::AllocationProfile::sProfiles[2].mNode.mNext = &result->mNode;
      result->mNode.mPrev = &UFG::AllocationProfile::sProfiles[2].mNode;
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
    LODWORD(result[1].mNode.mPrev) = 1;
    HIDWORD(result[1].mNode.mPrev) = 2;
    result[1].mNode.mNext = memory_location;
    result[2].mNode.mPrev = location_size;
    ++dword_14225A668;
  }
  v9 = UFG::AllocationProfile::sProfiles[2].mNode.mNext;
  UFG::AllocationProfile::sProfiles[2].mNode.mNext = &result->mNode;
  result->mNode.mPrev = &UFG::AllocationProfile::sProfiles[2].mNode;
  result->mNode.mNext = v9;
  v9->mPrev = &result->mNode;
  return result;
}

// File Line: 223
// RVA: 0x1609E0
void __fastcall UFG::ResourceMemoryHandle::ResourceMemoryHandle(
        UFG::ResourceMemoryHandle *this,
        UFG::AllocationProfile *profile)
{
  this->mVRAMemoryHandle.mPrev = &this->mVRAMemoryHandle;
  this->mVRAMemoryHandle.mNext = &this->mVRAMemoryHandle;
  this->mVRAMemoryHandle.mData = 0i64;
  *(_DWORD *)&this->mVRAMemoryHandle.mReadOnlyAndPoolID = 0;
  UFG::qPrintChannel::Print(
    &UFG::VRAMChannel,
    OUTPUT_LEVEL_DEBUG,
    "[VRAM Channel] - Creating new empty qVRAMemoryHandle(%p)\n");
  this->mAllocationSize = 0i64;
  this->mAllocateReturned = 0i64;
  ++profile->mRefCount;
  this->mAllocationProfile = profile;
  if ( profile->mProfileType == eProfileType_PassedIn )
  {
    this->mAllocationSize = profile->mMemory.mVRAMemoryPool.mAlignment;
    this->mAllocateReturned = profile->mMemory.mVRAMemoryPool.mPool;
  }
}

// File Line: 257
// RVA: 0x163200
void __fastcall UFG::ResourceMemoryHandle::~ResourceMemoryHandle(UFG::ResourceMemoryHandle *this)
{
  UFG::AllocationProfile *mAllocationProfile; // rdx
  UFG::qNode<UFG::AllocationProfile,UFG::AllocationProfile> *mPrev; // rcx
  UFG::qNode<UFG::AllocationProfile,UFG::AllocationProfile> *mNext; // rax

  UFG::ResourceMemoryHandle::FreeBuffer(this);
  mAllocationProfile = this->mAllocationProfile;
  if ( mAllocationProfile )
  {
    if ( mAllocationProfile->mRefCount-- == 1 )
    {
      --UFG::AllocationProfile::sActiveProfilesCount[mAllocationProfile->mProfileType];
      mPrev = mAllocationProfile->mPrev;
      mNext = mAllocationProfile->mNext;
      mPrev->mNext = mNext;
      mNext->mPrev = mPrev;
      mAllocationProfile->mPrev = mAllocationProfile;
      mAllocationProfile->mNext = mAllocationProfile;
      UFG::qMemoryPool::Free(UFG::gMainMemoryPool, mAllocationProfile);
    }
  }
  UFG::qVRAMemoryHandle::~qVRAMemoryHandle(&this->mVRAMemoryHandle);
}

// File Line: 271
// RVA: 0x16F4B0
char *__fastcall UFG::ResourceMemoryHandle::GetBuffer(UFG::ResourceMemoryHandle *this)
{
  UFG::AllocationProfile *mAllocationProfile; // rax
  UFG::eProfileType mProfileType; // eax

  mAllocationProfile = this->mAllocationProfile;
  if ( !mAllocationProfile )
    return this->mVRAMemoryHandle.mData;
  mProfileType = mAllocationProfile->mProfileType;
  switch ( mProfileType )
  {
    case eProfileType_MemoryPool:
      return (char *)this->mAllocateReturned;
    case eProfileType_VRAMemoryPool:
      return this->mVRAMemoryHandle.mData;
    case eProfileType_PassedIn:
      return (char *)this->mAllocateReturned;
  }
  return 0i64;
}

// File Line: 296
// RVA: 0x16F4E0
unsigned __int64 __fastcall UFG::ResourceMemoryHandle::GetBufferSize(UFG::ResourceMemoryHandle *this)
{
  UFG::AllocationProfile *mAllocationProfile; // rax
  UFG::eProfileType mProfileType; // eax

  mAllocationProfile = this->mAllocationProfile;
  if ( !mAllocationProfile )
    return UFG::qVRAMemoryPools::GetRequestedSize(&this->mVRAMemoryHandle);
  mProfileType = mAllocationProfile->mProfileType;
  switch ( mProfileType )
  {
    case eProfileType_MemoryPool:
      return this->mAllocationSize;
    case eProfileType_VRAMemoryPool:
      return UFG::qVRAMemoryPools::GetRequestedSize(&this->mVRAMemoryHandle);
    case eProfileType_PassedIn:
      return this->mAllocationSize;
  }
  return 0i64;
}

// File Line: 321
// RVA: 0x1675F0
char *__fastcall UFG::ResourceMemoryHandle::AllocateBuffer(
        UFG::ResourceMemoryHandle *this,
        unsigned int buffer_size,
        const char *allocation_name,
        unsigned __int64 userdata64,
        unsigned int userdata32)
{
  UFG::AllocationProfile *mAllocationProfile; // rcx
  UFG::eProfileType mProfileType; // eax
  unsigned __int64 v8; // rbx
  UFG::allocator::free_link *v9; // rax
  char *mData; // rbx

  mAllocationProfile = this->mAllocationProfile;
  if ( !mAllocationProfile )
  {
LABEL_10:
    mData = this->mVRAMemoryHandle.mData;
    UFG::qVRAMemoryPools::GetRequestedSize(&this->mVRAMemoryHandle);
    return mData;
  }
  mProfileType = mAllocationProfile->mProfileType;
  switch ( mProfileType )
  {
    case eProfileType_MemoryPool:
      if ( !this->mAllocateReturned )
      {
        v8 = buffer_size;
        v9 = UFG::qMemoryPool::Allocate(
               mAllocationProfile->mMemory.mMemoryPool.mPool,
               buffer_size,
               allocation_name,
               mAllocationProfile->mMemory.mMemoryPool.mAllocationParams,
               1u);
        this->mAllocateReturned = v9;
        if ( v9 )
          this->mAllocationSize = v8;
      }
      return (char *)this->mAllocateReturned;
    case eProfileType_VRAMemoryPool:
      if ( !this->mVRAMemoryHandle.mData )
        UFG::qVRAMemoryPool::Allocate(
          mAllocationProfile->mMemory.mVRAMemoryPool.mPool,
          &this->mVRAMemoryHandle,
          buffer_size,
          (unsigned __int8)mAllocationProfile->mMemory.mVRAMemoryPool.mUsage,
          allocation_name,
          mAllocationProfile->mMemory.mVRAMemoryPool.mAlignment,
          mAllocationProfile->mMemory.mVRAMemoryPool.mFlags,
          0i64,
          userdata64,
          userdata32);
      goto LABEL_10;
    case eProfileType_PassedIn:
      return (char *)this->mAllocateReturned;
  }
  return 0i64;
}

// File Line: 381
// RVA: 0x16EDF0
void __fastcall UFG::ResourceMemoryHandle::FreeBuffer(UFG::ResourceMemoryHandle *this)
{
  UFG::AllocationProfile *mAllocationProfile; // rcx
  UFG::eProfileType mProfileType; // eax
  char *mAllocateReturned; // rdx

  mAllocationProfile = this->mAllocationProfile;
  if ( mAllocationProfile )
  {
    mProfileType = mAllocationProfile->mProfileType;
    if ( mProfileType )
    {
      if ( mProfileType == eProfileType_VRAMemoryPool && this->mVRAMemoryHandle.mData )
        UFG::qVRAMemoryPool::Free(
          mAllocationProfile->mMemory.mVRAMemoryPool.mPool,
          &this->mVRAMemoryHandle,
          (unsigned __int8)mAllocationProfile->mMemory.mVRAMemoryPool.mFreeDelay);
    }
    else
    {
      mAllocateReturned = (char *)this->mAllocateReturned;
      if ( mAllocateReturned )
      {
        UFG::qMemoryPool::Free(mAllocationProfile->mMemory.mMemoryPool.mPool, mAllocateReturned);
        this->mAllocateReturned = 0i64;
        this->mAllocationSize = 0i64;
      }
    }
  }
  else
  {
    UFG::qVRAMemoryHandle::Close(&this->mVRAMemoryHandle);
  }
}

// File Line: 482
// RVA: 0x1603A0
void __fastcall UFG::LoadTableEntry::LoadTableEntry(
        UFG::LoadTableEntry *this,
        const char *filename,
        UFG::AllocationProfile *profile,
        char *scratch_buffer,
        unsigned int scratch_buffer_size,
        UFG::ResourceFileContentType content_type)
{
  UFG::qString *v8; // rdi
  UFG::qMemoryPool *v9; // rcx
  char *v10; // rax
  UFG::qString *v11; // rax

  this->mPrev = this;
  this->mNext = this;
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
    UFG::qString::qString((UFG::qString *)v10, filename);
    v8 = v11;
  }
  this->mFilename = v8;
  this->mFilenameUID = UFG::qString::GetStringHashUpper32(v8);
}

// File Line: 509
// RVA: 0x1602E0
void __fastcall UFG::LoadTableEntry::LoadTableEntry(UFG::LoadTableEntry *this, UFG::LoadTableEntry *entry)
{
  UFG::AllocationProfile *mAllocationProfile; // rax
  UFG::qString *v5; // rsi
  UFG::qMemoryPool *v6; // rcx
  char *v7; // rax
  UFG::qString *v8; // rax

  this->mPrev = this;
  this->mNext = this;
  mAllocationProfile = entry->mAllocationProfile;
  ++mAllocationProfile->mRefCount;
  this->mAllocationProfile = mAllocationProfile;
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
      UFG::qString::qString((UFG::qString *)v7, entry->mFilename);
      v5 = v8;
    }
    this->mFilename = v5;
  }
}

// File Line: 520
// RVA: 0x162E50
void __fastcall UFG::LoadTableEntry::~LoadTableEntry(UFG::LoadTableEntry *this)
{
  UFG::AllocationProfile *mAllocationProfile; // rdx
  UFG::qNode<UFG::AllocationProfile,UFG::AllocationProfile> *mPrev; // rcx
  UFG::qNode<UFG::AllocationProfile,UFG::AllocationProfile> *mNext; // rax
  UFG::qString *mFilename; // rdi
  char *mData; // rdx
  UFG::qNode<UFG::qString,UFG::qString> *v8; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *v9; // rax
  UFG::qNode<UFG::LoadTableEntry,UFG::LoadTableEntry> *v10; // rcx
  UFG::qNode<UFG::LoadTableEntry,UFG::LoadTableEntry> *v11; // rax

  mAllocationProfile = this->mAllocationProfile;
  if ( mAllocationProfile->mRefCount-- == 1 )
  {
    --UFG::AllocationProfile::sActiveProfilesCount[mAllocationProfile->mProfileType];
    mPrev = mAllocationProfile->mPrev;
    mNext = mAllocationProfile->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    mAllocationProfile->mPrev = mAllocationProfile;
    mAllocationProfile->mNext = mAllocationProfile;
    UFG::qMemoryPool::Free(UFG::gMainMemoryPool, mAllocationProfile);
  }
  mFilename = this->mFilename;
  if ( mFilename )
  {
    mData = mFilename->mData;
    if ( mData != UFG::qString::sEmptyString && mData )
      UFG::qMemoryPool::Free(UFG::gMainMemoryPool, mData);
    mFilename->mMagic = 0;
    v8 = mFilename->mPrev;
    v9 = mFilename->mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    mFilename->mPrev = mFilename;
    mFilename->mNext = mFilename;
    UFG::qMemoryPool::Free(UFG::gMainMemoryPool, mFilename);
    this->mFilename = 0i64;
  }
  v10 = this->mPrev;
  v11 = this->mNext;
  v10->mNext = v11;
  v11->mPrev = v10;
  this->mPrev = this;
  this->mNext = this;
}

// File Line: 581
// RVA: 0x163140
void __fastcall UFG::ResourceLoadTable::~ResourceLoadTable(UFG::ResourceLoadTable *this)
{
  UFG::qList<UFG::LoadTableEntry,UFG::LoadTableEntry,1,0> *p_mTableEntries; // rsi
  UFG::LoadTableEntry *mNext; // rbx
  UFG::qNode<UFG::LoadTableEntry,UFG::LoadTableEntry> *mPrev; // rcx
  UFG::qNode<UFG::LoadTableEntry,UFG::LoadTableEntry> *v5; // rax
  bool v6; // zf
  UFG::qMemoryPool *mMemoryPool; // rcx
  UFG::qNode<UFG::LoadTableEntry,UFG::LoadTableEntry> *v8; // rcx
  UFG::qNode<UFG::LoadTableEntry,UFG::LoadTableEntry> *v9; // rax
  UFG::qNode<UFG::ResourceLoadTable,UFG::ResourceLoadTable> *v10; // rcx
  UFG::qNode<UFG::ResourceLoadTable,UFG::ResourceLoadTable> *v11; // rax

  p_mTableEntries = &this->mTableEntries;
  if ( (UFG::qList<UFG::LoadTableEntry,UFG::LoadTableEntry,1,0> *)this->mTableEntries.mNode.mNext != &this->mTableEntries )
  {
    do
    {
      mNext = (UFG::LoadTableEntry *)this->mTableEntries.mNode.mNext;
      mPrev = mNext->mPrev;
      v5 = mNext->mNext;
      v6 = this->mMemoryPool == 0i64;
      mPrev->mNext = v5;
      v5->mPrev = mPrev;
      mNext->mPrev = mNext;
      mNext->mNext = mNext;
      if ( v6 )
      {
        UFG::LoadTableEntry::~LoadTableEntry(mNext);
        mMemoryPool = UFG::gMainMemoryPool;
      }
      else
      {
        UFG::LoadTableEntry::~LoadTableEntry(mNext);
        mMemoryPool = this->mMemoryPool;
      }
      UFG::qMemoryPool::Free(mMemoryPool, mNext);
    }
    while ( (UFG::qList<UFG::LoadTableEntry,UFG::LoadTableEntry,1,0> *)p_mTableEntries->mNode.mNext != p_mTableEntries );
  }
  UFG::qList<UFG::LoadTableEntry,UFG::LoadTableEntry,1,0>::DeleteNodes(p_mTableEntries);
  v8 = p_mTableEntries->mNode.mPrev;
  v9 = p_mTableEntries->mNode.mNext;
  v8->mNext = v9;
  v9->mPrev = v8;
  p_mTableEntries->mNode.mPrev = &p_mTableEntries->mNode;
  p_mTableEntries->mNode.mNext = &p_mTableEntries->mNode;
  v10 = this->mPrev;
  v11 = this->mNext;
  v10->mNext = v11;
  v11->mPrev = v10;
  this->mPrev = this;
  this->mNext = this;
}

// File Line: 608
// RVA: 0x1650D0
void __fastcall UFG::ResourceLoadTable::Add(
        UFG::ResourceLoadTable *this,
        const char *filename,
        UFG::qMemoryPool *memory_pool,
        unsigned __int64 allocation_params,
        char *scratch_buffer,
        unsigned int scratch_buffer_size,
        UFG::ResourceFileContentType content_type)
{
  UFG::qMemoryPool *v9; // rcx
  UFG::AllocationProfile *AllocationProfile; // rdi
  UFG::qMemoryPool *mMemoryPool; // rcx
  UFG::qMemoryPool *v12; // rcx
  char *v13; // rax
  UFG::qNode<UFG::LoadTableEntry,UFG::LoadTableEntry> *v14; // rbx
  UFG::qNode<UFG::LoadTableEntry,UFG::LoadTableEntry> *v15; // rax
  UFG::qNode<UFG::AllocationProfile,UFG::AllocationProfile> *mPrev; // rcx
  UFG::qNode<UFG::AllocationProfile,UFG::AllocationProfile> *mNext; // rax
  UFG::qNode<UFG::LoadTableEntry,UFG::LoadTableEntry> *v19; // rax

  v9 = UFG::gMainMemoryPool;
  if ( memory_pool )
    v9 = memory_pool;
  AllocationProfile = UFG::AllocationProfile::CreateAllocationProfile(v9, allocation_params);
  mMemoryPool = this->mMemoryPool;
  if ( !mMemoryPool )
  {
    v12 = UFG::gMainMemoryPool;
    if ( !UFG::gMainMemoryPool )
    {
      UFG::InternalSetupMainMemoryPool((UFG *)UFG::gMainMemoryPool);
      v12 = UFG::gMainMemoryPool;
    }
    v13 = UFG::qMemoryPool::Allocate(v12, 0x38ui64, "LoadTableEntry", 0i64, 1u);
    if ( !v13 )
    {
      v14 = 0i64;
      goto LABEL_11;
    }
    goto LABEL_9;
  }
  v13 = UFG::qMemoryPool::Allocate(mMemoryPool, 0x38ui64, "LoadTableEntry", 0i64, 1u);
  if ( v13 )
  {
LABEL_9:
    UFG::LoadTableEntry::LoadTableEntry(
      (UFG::LoadTableEntry *)v13,
      filename,
      AllocationProfile,
      scratch_buffer,
      scratch_buffer_size,
      content_type);
    v14 = v15;
    goto LABEL_11;
  }
  v14 = 0i64;
LABEL_11:
  if ( AllocationProfile->mRefCount-- == 1 )
  {
    --UFG::AllocationProfile::sActiveProfilesCount[AllocationProfile->mProfileType];
    mPrev = AllocationProfile->mPrev;
    mNext = AllocationProfile->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    AllocationProfile->mPrev = AllocationProfile;
    AllocationProfile->mNext = AllocationProfile;
    UFG::qMemoryPool::Free(UFG::gMainMemoryPool, AllocationProfile);
  }
  v19 = this->mTableEntries.mNode.mPrev;
  v19->mNext = v14;
  v14->mPrev = v19;
  v14->mNext = &this->mTableEntries.mNode;
  this->mTableEntries.mNode.mPrev = v14;
}

// File Line: 765
// RVA: 0x16AA60
__int64 __fastcall UFG::ResourceLoadTable::CopyTableEntries(
        UFG::ResourceLoadTable *this,
        UFG::ResourceLoadTable *load_table)
{
  unsigned __int8 v3; // di
  UFG::LoadTableEntry *mNext; // rbx
  UFG::qList<UFG::LoadTableEntry,UFG::LoadTableEntry,1,0> *p_mTableEntries; // r14
  UFG::qList<UFG::LoadTableEntry,UFG::LoadTableEntry,1,0> *v6; // rsi
  UFG::qMemoryPool *mMemoryPool; // rcx
  UFG::qMemoryPool *v8; // rcx
  UFG::allocator::free_link *v9; // rax
  UFG::qNode<UFG::LoadTableEntry,UFG::LoadTableEntry> *v10; // rax
  UFG::qNode<UFG::LoadTableEntry,UFG::LoadTableEntry> *mPrev; // rcx

  v3 = 1;
  mNext = (UFG::LoadTableEntry *)load_table->mTableEntries.mNode.mNext;
  p_mTableEntries = &load_table->mTableEntries;
  if ( mNext != (UFG::LoadTableEntry *)&load_table->mTableEntries )
  {
    v6 = &this->mTableEntries;
    while ( 1 )
    {
      mMemoryPool = this->mMemoryPool;
      if ( mMemoryPool )
        break;
      v8 = UFG::gMainMemoryPool;
      if ( !UFG::gMainMemoryPool )
      {
        UFG::InternalSetupMainMemoryPool((UFG *)UFG::gMainMemoryPool);
        v8 = UFG::gMainMemoryPool;
      }
      v9 = UFG::qMemoryPool::Allocate(v8, 0x38ui64, "LoadTableEntry", 0i64, 1u);
      if ( v9 )
        goto LABEL_9;
      v10 = 0i64;
LABEL_11:
      if ( !v10 )
        v3 = 0;
      mPrev = v6->mNode.mPrev;
      mPrev->mNext = v10;
      v10->mPrev = mPrev;
      v10->mNext = &v6->mNode;
      v6->mNode.mPrev = v10;
      mNext = (UFG::LoadTableEntry *)mNext->mNext;
      if ( mNext == (UFG::LoadTableEntry *)p_mTableEntries )
        return v3;
    }
    v9 = UFG::qMemoryPool::Allocate(mMemoryPool, 0x38ui64, "LoadTableEntry", 0i64, 1u);
    if ( !v9 )
    {
      v10 = 0i64;
      goto LABEL_11;
    }
LABEL_9:
    UFG::LoadTableEntry::LoadTableEntry((UFG::LoadTableEntry *)v9, mNext);
    goto LABEL_11;
  }
  return v3;
}

// File Line: 817
// RVA: 0x17BAC0
void __fastcall UFG::ResourceSystem_OpennedFileCallback(UFG::qFileOp *file_op, void *callback_param)
{
  if ( *(_DWORD *)file_op->mStatus == 5 )
    UFG::qPrintChannel::Print(
      &UFG::qChunkFileSystem::mResourceChannel,
      OUTPUT_LEVEL_WARNING,
      "WARNING: Async qOpen returned an error on file %s\n");
}

// File Line: 829
// RVA: 0x160910
void __fastcall UFG::ResourceFileHandle::ResourceFileHandle(
        UFG::ResourceFileHandle *this,
        const char *filename,
        unsigned int filename_uid)
{
  UFG::qString *p_mFilename; // r10
  const char *v5; // rax
  int v7; // eax

  this->mNode.mParent = 0i64;
  this->mNode.mChild[0] = 0i64;
  this->mNode.mChild[1] = 0i64;
  this->mNode.mUID = filename_uid;
  p_mFilename = &this->mFilename;
  this->mFilename.mPrev = &this->mFilename;
  this->mFilename.mNext = &this->mFilename;
  this->mFilename.mMagic = 16909060;
  this->mFilename.mData = (char *)UFG::qString::sEmptyString;
  this->mFilename.mLength = 0;
  *(_QWORD *)&this->mFilename.mStringHash32 = -1i64;
  if ( !filename || filename == UFG::qString::sEmptyString )
  {
    v7 = 0;
  }
  else
  {
    v5 = filename;
    while ( *v5++ )
      ;
    v7 = (_DWORD)v5 - (_DWORD)filename - 1;
  }
  UFG::qString::Set(p_mFilename, filename, v7, 0i64, 0);
  this->mFile = UFG::qOpenAsync(
                  this->mFilename.mData,
                  QACCESS_READ,
                  0,
                  UFG::ResourceSystem_OpennedFileCallback,
                  this,
                  QPRIORITY_NORMAL);
}

// File Line: 861
// RVA: 0x160850
void __fastcall UFG::ResourceFile::ResourceFile(
        UFG::ResourceFile *this,
        unsigned int resource_uid,
        UFG::AllocationProfile *profile)
{
  this->mNode.mParent = 0i64;
  this->mNode.mChild[0] = 0i64;
  this->mNode.mChild[1] = 0i64;
  this->mNode.mUID = resource_uid;
  this->mResourceHandles.UFG::qResourceData::mNode.UFG::qResourceData::mPrev = &this->mResourceHandles.UFG::qResourceData::mNode;
  this->mResourceHandles.UFG::qResourceData::mNode.mNext = &this->mResourceHandles.UFG::qResourceData::mNode;
  this->mTypeUID = -1540880596;
  UFG::qMemSet(this->mDebugName, 0, 0x24u);
  this->mPrev = &this->UFG::qNode<UFG::ResourceFile,UFG::ZeroRefResourceFile>;
  this->mNext = &this->UFG::qNode<UFG::ResourceFile,UFG::ZeroRefResourceFile>;
  UFG::ResourceMemoryHandle::ResourceMemoryHandle(&this->mMemoryHandle, profile);
  this->mValidDataSize = 0i64;
  *(_QWORD *)&this->mRefs = 0i64;
  this->mState = STATE_IDLE;
  this->mWaitingLoadTables.mNode.mPrev = &this->mWaitingLoadTables.mNode;
  this->mWaitingLoadTables.mNode.mNext = &this->mWaitingLoadTables.mNode;
  this->mUserData = 0i64;
  ++UFG::ResourceFile::sResourceFileCount;
  ++UFG::ResourceFile::sResourceFileTotal;
}

// File Line: 874
// RVA: 0x160780
void __fastcall UFG::ResourceFile::ResourceFile(
        UFG::ResourceFile *this,
        unsigned int resource_uid,
        UFG::qVRAMemoryHandle *handle)
{
  this->mNode.mParent = 0i64;
  this->mNode.mChild[0] = 0i64;
  this->mNode.mChild[1] = 0i64;
  this->mNode.mUID = resource_uid;
  this->mResourceHandles.UFG::qResourceData::mNode.UFG::qResourceData::mPrev = &this->mResourceHandles.UFG::qResourceData::mNode;
  this->mResourceHandles.UFG::qResourceData::mNode.mNext = &this->mResourceHandles.UFG::qResourceData::mNode;
  this->mTypeUID = -1540880596;
  UFG::qMemSet(this->mDebugName, 0, 0x24u);
  this->mPrev = &this->UFG::qNode<UFG::ResourceFile,UFG::ZeroRefResourceFile>;
  this->mNext = &this->UFG::qNode<UFG::ResourceFile,UFG::ZeroRefResourceFile>;
  UFG::qVRAMemoryHandle::qVRAMemoryHandle(&this->mMemoryHandle.mVRAMemoryHandle, handle);
  this->mMemoryHandle.mAllocationSize = 0i64;
  this->mMemoryHandle.mAllocateReturned = 0i64;
  this->mMemoryHandle.mAllocationProfile = 0i64;
  this->mValidDataSize = 0i64;
  *(_QWORD *)&this->mRefs = 0i64;
  this->mState = STATE_IDLE;
  this->mWaitingLoadTables.mNode.mPrev = &this->mWaitingLoadTables.mNode;
  this->mWaitingLoadTables.mNode.mNext = &this->mWaitingLoadTables.mNode;
  this->mUserData = 0i64;
  ++UFG::ResourceFile::sResourceFileCount;
  ++UFG::ResourceFile::sResourceFileTotal;
}

// File Line: 880
// RVA: 0x163080
void __fastcall UFG::ResourceFile::~ResourceFile(UFG::ResourceFile *this)
{
  UFG::qNode<UFG::qValueNode<UFG::ResourceLoadTable *>,UFG::qValueNode<UFG::ResourceLoadTable *> > *mPrev; // rdx
  UFG::qNode<UFG::qValueNode<UFG::ResourceLoadTable *>,UFG::qValueNode<UFG::ResourceLoadTable *> > *mNext; // rax
  UFG::qNode<UFG::ResourceFile,UFG::ZeroRefResourceFile> *v4; // rcx
  UFG::qNode<UFG::ResourceFile,UFG::ZeroRefResourceFile> *v5; // rax
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v6; // rcx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v7; // rax

  UFG::ResourceMemoryHandle::FreeBuffer(&this->mMemoryHandle);
  --UFG::ResourceFile::sResourceFileCount;
  UFG::qList<UFG::qTaskFunctionDecl,UFG::qTaskFunctionDecl,1,0>::DeleteNodes((UFG::qList<UFG::tChunkPosition,UFG::tChunkPosition,1,0> *)&this->mWaitingLoadTables);
  mPrev = this->mWaitingLoadTables.mNode.mPrev;
  mNext = this->mWaitingLoadTables.mNode.mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  this->mWaitingLoadTables.mNode.mPrev = &this->mWaitingLoadTables.mNode;
  this->mWaitingLoadTables.mNode.mNext = &this->mWaitingLoadTables.mNode;
  UFG::ResourceMemoryHandle::~ResourceMemoryHandle(&this->mMemoryHandle);
  v4 = this->mPrev;
  v5 = this->mNext;
  v4->mNext = v5;
  v5->mPrev = v4;
  this->mPrev = &this->UFG::qNode<UFG::ResourceFile,UFG::ZeroRefResourceFile>;
  this->mNext = &this->UFG::qNode<UFG::ResourceFile,UFG::ZeroRefResourceFile>;
  UFG::qList<UFG::qResourceHandle,UFG::qResourceHandle,1,0>::DeleteNodes(&this->mResourceHandles);
  v6 = this->mResourceHandles.UFG::qResourceData::mNode.UFG::qResourceData::mPrev;
  v7 = this->mResourceHandles.UFG::qResourceData::mNode.mNext;
  v6->mNext = v7;
  v7->mPrev = v6;
  this->mResourceHandles.UFG::qResourceData::mNode.UFG::qResourceData::mPrev = &this->mResourceHandles.UFG::qResourceData::mNode;
  this->mResourceHandles.UFG::qResourceData::mNode.mNext = &this->mResourceHandles.UFG::qResourceData::mNode;
}

// File Line: 933
// RVA: 0x17FC80
void __fastcall UFG::ResourceFile::WarehouseLoad(UFG::ResourceFile *this)
{
  char *mAllocateReturned; // rdi
  UFG::AllocationProfile *mAllocationProfile; // rax
  UFG::eProfileType mProfileType; // eax
  UFG::qResourceWarehouse *v5; // rax
  UFG::qNode<UFG::ResourceFile,UFG::ZeroRefResourceFile> *mPrev; // rax

  mAllocateReturned = 0i64;
  UFG::qPrintChannel::Print(
    &UFG::qChunkFileSystem::mResourceChannel,
    OUTPUT_LEVEL_WARNING,
    "[Resource - Load ResourceFile] uid=0x%08x  address=0x%08x sz=%d\n");
  mAllocationProfile = this->mMemoryHandle.mAllocationProfile;
  if ( !mAllocationProfile )
    goto LABEL_7;
  mProfileType = mAllocationProfile->mProfileType;
  switch ( mProfileType )
  {
    case eProfileType_MemoryPool:
      mAllocateReturned = (char *)this->mMemoryHandle.mAllocateReturned;
      break;
    case eProfileType_VRAMemoryPool:
LABEL_7:
      mAllocateReturned = this->mMemoryHandle.mVRAMemoryHandle.mData;
      break;
    case eProfileType_PassedIn:
      mAllocateReturned = (char *)this->mMemoryHandle.mAllocateReturned;
      break;
  }
  v5 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Load(
    v5,
    mAllocateReturned,
    (UFG::qNode<UFG::qResourceInventory,UFG::qResourceInventory> *)LODWORD(this->mValidDataSize));
  if ( this->mUserData )
  {
    mPrev = stru_14235B120.mNode.mPrev;
    stru_14235B120.mNode.mPrev->mNext = &this->UFG::qNode<UFG::ResourceFile,UFG::ZeroRefResourceFile>;
    this->mPrev = mPrev;
    this->mNext = (UFG::qNode<UFG::ResourceFile,UFG::ZeroRefResourceFile> *)&stru_14235B120;
    stru_14235B120.mNode.mPrev = &this->UFG::qNode<UFG::ResourceFile,UFG::ZeroRefResourceFile>;
  }
  UFG::qResourceInventory::Add(&UFG::gResourceFileInventory, this);
  this->mState = STATE_PHONE_CONTACTS;
}

// File Line: 952
// RVA: 0x17FD90
void __fastcall UFG::ResourceFile::WarehouseUnload(UFG::ResourceFile *this)
{
  UFG::AllocationProfile *mAllocationProfile; // rax
  UFG::eProfileType mProfileType; // eax
  char *mData; // rdi
  UFG::qResourceWarehouse *v5; // rax

  UFG::qPrintChannel::Print(
    &UFG::qChunkFileSystem::mResourceChannel,
    OUTPUT_LEVEL_WARNING,
    "[Resource - Unload ResourceFile] uid=0x%08x  address=0x%08x sz=%d\n");
  mAllocationProfile = this->mMemoryHandle.mAllocationProfile;
  if ( !mAllocationProfile )
    goto LABEL_7;
  mProfileType = mAllocationProfile->mProfileType;
  if ( mProfileType == eProfileType_MemoryPool )
    goto LABEL_3;
  if ( mProfileType == eProfileType_VRAMemoryPool )
  {
LABEL_7:
    mData = this->mMemoryHandle.mVRAMemoryHandle.mData;
    goto LABEL_8;
  }
  if ( mProfileType != eProfileType_PassedIn )
  {
    mData = 0i64;
    goto LABEL_8;
  }
LABEL_3:
  mData = (char *)this->mMemoryHandle.mAllocateReturned;
LABEL_8:
  v5 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Unload(
    v5,
    mData,
    (UFG::qNode<UFG::qResourceInventory,UFG::qResourceInventory> *)LODWORD(this->mValidDataSize));
  UFG::qResourceInventory::Remove(&UFG::gResourceFileInventory, this);
  this->mValidDataSize = 0i64;
  this->mState = STATE_IDLE;
}

// File Line: 972
// RVA: 0x1669C0
char __fastcall UFG::ResourceFile::AddWaitingTable(UFG::ResourceFile *this, UFG::ResourceLoadTable *load_table)
{
  UFG::qMemoryPool *v4; // rcx
  char *v5; // rax
  UFG::qNode<UFG::qValueNode<UFG::ResourceLoadTable *>,UFG::qValueNode<UFG::ResourceLoadTable *> > *v6; // rbx
  UFG::qNode<UFG::qValueNode<UFG::ResourceLoadTable *>,UFG::qValueNode<UFG::ResourceLoadTable *> > *mPrev; // rax

  v4 = UFG::gMainMemoryPool;
  if ( !UFG::gMainMemoryPool )
  {
    UFG::InternalSetupMainMemoryPool((UFG *)UFG::gMainMemoryPool);
    v4 = UFG::gMainMemoryPool;
  }
  v5 = UFG::qMemoryPool::Allocate(v4, 0x18ui64, "ResourceFile::WaitingTableEntry", 0i64, 1u);
  v6 = (UFG::qNode<UFG::qValueNode<UFG::ResourceLoadTable *>,UFG::qValueNode<UFG::ResourceLoadTable *> > *)v5;
  if ( v5 )
  {
    *(_QWORD *)v5 = v5;
    *((_QWORD *)v5 + 1) = v5;
    *((_QWORD *)v5 + 2) = load_table;
  }
  else
  {
    v6 = 0i64;
  }
  if ( !v6 )
    return 0;
  UFG::qAtomicIncrement((volatile int *)&v6[1].mPrev[5].mNext);
  mPrev = this->mWaitingLoadTables.mNode.mPrev;
  mPrev->mNext = v6;
  v6->mPrev = mPrev;
  v6->mNext = &this->mWaitingLoadTables.mNode;
  this->mWaitingLoadTables.mNode.mPrev = v6;
  return 1;
}

// File Line: 984
// RVA: 0x1781F0
char __fastcall UFG::ResourceFile::NotifyWaitingTables(UFG::ResourceFile *this)
{
  UFG::qList<UFG::qValueNode<UFG::ResourceLoadTable *>,UFG::qValueNode<UFG::ResourceLoadTable *>,1,0> *p_mWaitingLoadTables; // rdi
  UFG::qNode<UFG::qValueNode<UFG::ResourceLoadTable *>,UFG::qValueNode<UFG::ResourceLoadTable *> > *mNext; // rbx
  UFG::qNode<UFG::qValueNode<UFG::ResourceLoadTable *>,UFG::qValueNode<UFG::ResourceLoadTable *> > *mPrev; // rdx
  UFG::qNode<UFG::qValueNode<UFG::ResourceLoadTable *>,UFG::qValueNode<UFG::ResourceLoadTable *> > *v5; // rax
  UFG::qNode<UFG::qValueNode<UFG::ResourceLoadTable *>,UFG::qValueNode<UFG::ResourceLoadTable *> > *v6; // rcx
  UFG::qNode<UFG::qValueNode<UFG::ResourceLoadTable *>,UFG::qValueNode<UFG::ResourceLoadTable *> > *v7; // rax

  p_mWaitingLoadTables = &this->mWaitingLoadTables;
  if ( (UFG::qList<UFG::qValueNode<UFG::ResourceLoadTable *>,UFG::qValueNode<UFG::ResourceLoadTable *>,1,0> *)this->mWaitingLoadTables.mNode.mNext != &this->mWaitingLoadTables )
  {
    do
    {
      mNext = this->mWaitingLoadTables.mNode.mNext;
      mPrev = mNext->mPrev;
      v5 = mNext->mNext;
      mPrev->mNext = v5;
      v5->mPrev = mPrev;
      mNext->mPrev = mNext;
      mNext->mNext = mNext;
      UFG::qAtomicDecrement((volatile int *)&mNext[1].mPrev[5].mNext);
      v6 = mNext->mPrev;
      v7 = mNext->mNext;
      v6->mNext = v7;
      v7->mPrev = v6;
      mNext->mPrev = mNext;
      mNext->mNext = mNext;
      UFG::qMemoryPool::Free(UFG::gMainMemoryPool, (char *)mNext);
    }
    while ( (UFG::qList<UFG::qValueNode<UFG::ResourceLoadTable *>,UFG::qValueNode<UFG::ResourceLoadTable *>,1,0> *)p_mWaitingLoadTables->mNode.mNext != p_mWaitingLoadTables );
  }
  return 1;
}

// File Line: 1036
// RVA: 0x160530
void __fastcall UFG::LoadedChunkFile::LoadedChunkFile(
        UFG::LoadedChunkFile *this,
        unsigned int filename_uid,
        unsigned int resource_uid,
        const char *filename,
        UFG::AllocationProfile *profile)
{
  unsigned int mStringHashUpper32; // r9d
  char *mData; // r8
  char i; // al
  UFG::qNode<UFG::qString,UFG::qString> *mPrev; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *mNext; // rax
  UFG::qString result; // [rsp+38h] [rbp-30h] BYREF

  UFG::ResourceFile::ResourceFile(this, resource_uid, profile);
  UFG::qString::qString(&this->mFilename, filename);
  this->mNode.mNode.mParent = 0i64;
  this->mNode.mNode.mChild[0] = 0i64;
  this->mNode.mNode.mChild[1] = 0i64;
  this->mNode.mNode.mUID = 1;
  this->mHotswapFilenameUID = 0;
  this->mNode.mNode.mUID = filename_uid;
  this->mNode.mValue = this;
  UFG::qSPrintf(this->mDebugName, 36, "RF-LoadedChunkFile uid: 0x%08x", filename_uid);
  ++UFG::LoadedChunkFile::sLoadedChunkFileCount;
  ++UFG::LoadedChunkFile::sLoadedChunkFileTotal;
  UFG::qFileMapFilename(&result, FILE_MAP_TYPE_HOT_SWAP, filename);
  mStringHashUpper32 = result.mStringHashUpper32;
  if ( result.mStringHashUpper32 == -1 )
  {
    if ( result.mData )
    {
      mData = result.mData;
      for ( i = *result.mData; *mData; i = *mData )
      {
        if ( i <= 122 && i >= 97 )
          i -= 32;
        ++mData;
        mStringHashUpper32 = (mStringHashUpper32 << 8) ^ sCrcTable32[(unsigned __int8)(i ^ HIBYTE(mStringHashUpper32))];
      }
    }
    result.mStringHashUpper32 = mStringHashUpper32;
  }
  this->mHotswapFilenameUID = mStringHashUpper32;
  UFG::qPrintChannel::Print(
    &UFG::qChunkFileSystem::mResourceChannel,
    OUTPUT_LEVEL_WARNING,
    "Created hotswap uid 0x%08x (%10u) for filename %s\n");
  if ( result.mData != UFG::qString::sEmptyString && result.mData )
    UFG::qMemoryPool::Free(UFG::gMainMemoryPool, result.mData);
  mPrev = result.mPrev;
  mNext = result.mNext;
  result.mPrev->mNext = result.mNext;
  mNext->mPrev = mPrev;
}

// File Line: 1051
// RVA: 0x162F30
void __fastcall UFG::LoadedChunkFile::~LoadedChunkFile(UFG::LoadedChunkFile *this)
{
  UFG::qString *p_mFilename; // rbx
  char *mData; // rdx
  UFG::qNode<UFG::qString,UFG::qString> *mPrev; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *mNext; // rax

  --UFG::LoadedChunkFile::sLoadedChunkFileCount;
  p_mFilename = &this->mFilename;
  mData = this->mFilename.mData;
  if ( mData != UFG::qString::sEmptyString && mData )
    UFG::qMemoryPool::Free(UFG::gMainMemoryPool, mData);
  p_mFilename->mMagic = 0;
  mPrev = p_mFilename->mPrev;
  mNext = p_mFilename->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  p_mFilename->mPrev = p_mFilename;
  p_mFilename->mNext = p_mFilename;
  UFG::ResourceFile::~ResourceFile(this);
}

// File Line: 1123
// RVA: 0x1770F0
bool __fastcall UFG::LoadedChunkFile::LoadSync(UFG::LoadedChunkFile *this)
{
  char *ChunkFilename; // rsi
  __int64 FileSize; // r14
  UFG::qFile *v4; // rax
  UFG::qFile *v5; // rbp
  char *mData; // r8
  char *Buffer; // r15
  UFG::AllocationProfile *mAllocationProfile; // rax
  UFG::AllocationProfile *v9; // rax

  ChunkFilename = UFG::LoadedChunkFile::GetChunkFilename(this);
  FileSize = UFG::qGetFileSize(ChunkFilename);
  if ( FileSize <= 0 )
  {
    UFG::qPrintChannel::Print(
      &UFG::qChunkFileSystem::mResourceChannel,
      OUTPUT_LEVEL_ERROR,
      "[Resource - LoadChunkFile] skipping uid=0x%08x, file %s does not exist or size is 0\n");
    this->mState = STATE_PHONE_CONTACTS;
    LOBYTE(v4) = 0;
  }
  else
  {
    v4 = UFG::qOpen(ChunkFilename, QACCESS_READ, 1);
    v5 = v4;
    if ( v4 )
    {
      mData = this->mFilename.mData;
      if ( !mData )
        mData = this->mDebugName;
      Buffer = UFG::ResourceMemoryHandle::AllocateBuffer(
                 &this->mMemoryHandle,
                 FileSize,
                 mData,
                 (unsigned __int64)this->UFG::ResourceFile::UFG::qResourceData::UFG::qNodeRB<UFG::qResourceData>::mNode.mUID << 32,
                 0xE8C45525);
      UFG::qPrintChannel::Print(
        &UFG::qChunkFileSystem::mResourceChannel,
        OUTPUT_LEVEL_WARNING,
        "[Resource - LoadSync]     Starting read of 0x%08x64 bytes to buffer 0x%08x for uid:0x%08x from file %s\n");
      mAllocationProfile = this->mMemoryHandle.mAllocationProfile;
      if ( !mAllocationProfile
        || mAllocationProfile->mProfileType == eProfileType_VRAMemoryPool && this->mMemoryHandle.mVRAMemoryHandle.mData )
      {
        UFG::qVRAMemoryPools::Lock(&this->mMemoryHandle.mVRAMemoryHandle);
      }
      this->mValidDataSize = UFG::qRead(v5, Buffer, FileSize, 0i64, QSEEK_CUR);
      v9 = this->mMemoryHandle.mAllocationProfile;
      if ( !v9 || v9->mProfileType == eProfileType_VRAMemoryPool && this->mMemoryHandle.mVRAMemoryHandle.mData )
        UFG::qVRAMemoryPools::Unlock(&this->mMemoryHandle.mVRAMemoryHandle);
      UFG::qClose(v5);
      UFG::ResourceFile::WarehouseLoad(this);
      LOBYTE(v4) = 1;
    }
  }
  return (char)v4;
}

// File Line: 1178
// RVA: 0x16F610
char *__fastcall UFG::LoadedChunkFile::GetChunkFilename(UFG::LoadedChunkFile *this)
{
  unsigned int mHotswapFilenameUID; // edx
  UFG::qTreeRB<UFG::qHotswappedFile,UFG::qHotswappedFile,1> *v3; // rax
  unsigned int mUID; // r8d
  UFG::qTreeRB<UFG::qHotswappedFile,UFG::qHotswappedFile,1> *i; // rcx

  mHotswapFilenameUID = this->mHotswapFilenameUID;
  if ( !mHotswapFilenameUID )
    return this->mFilename.mData;
  v3 = &UFG::qChunkFileSystem::mHotswappedFiles;
  while ( 1 )
  {
    mUID = v3->mTree.mRoot.mUID;
    if ( v3 != &UFG::qChunkFileSystem::mHotswappedFiles && mUID == mHotswapFilenameUID )
      break;
    if ( mHotswapFilenameUID > mUID )
      v3 = (UFG::qTreeRB<UFG::qHotswappedFile,UFG::qHotswappedFile,1> *)v3->mTree.mRoot.mChild[1];
    else
      v3 = (UFG::qTreeRB<UFG::qHotswappedFile,UFG::qHotswappedFile,1> *)v3->mTree.mRoot.mChild[0];
    if ( v3 == (UFG::qTreeRB<UFG::qHotswappedFile,UFG::qHotswappedFile,1> *)&UFG::qChunkFileSystem::mHotswappedFiles.mTree.mNULL )
      return this->mFilename.mData;
  }
  for ( i = (UFG::qTreeRB<UFG::qHotswappedFile,UFG::qHotswappedFile,1> *)v3->mTree.mRoot.mChild[0];
        i;
        i = (UFG::qTreeRB<UFG::qHotswappedFile,UFG::qHotswappedFile,1> *)i->mTree.mRoot.mChild[0] )
  {
    if ( i->mTree.mRoot.mUID != mHotswapFilenameUID )
      break;
    v3 = i;
  }
  if ( v3 )
    return *(char **)&v3->mTree.mNULL.mUID;
  else
    return this->mFilename.mData;
}

// File Line: 1203
// RVA: 0x160460
void __fastcall UFG::LoadedChunk::LoadedChunk(
        UFG::LoadedChunk *this,
        unsigned int uid,
        UFG::AllocationProfile *profile,
        unsigned int allocation_size)
{
  UFG::ResourceFile::ResourceFile(this, uid, profile);
  this->mTransactionNum = ++UFG::LoadedChunk::sLoadedChunkTotal;
  this->mNode.mNode.mParent = 0i64;
  this->mNode.mNode.mChild[0] = 0i64;
  this->mNode.mNode.mChild[1] = 0i64;
  this->mNode.mNode.mUID = 1;
  this->mNode.mNode.mUID = uid;
  this->mNode.mValue = this;
  UFG::qSPrintf(this->mDebugName, 36, "RF-LoadedChunk     uid: 0x%08x", uid);
  UFG::ResourceMemoryHandle::AllocateBuffer(
    &this->mMemoryHandle,
    allocation_size,
    this->mDebugName,
    (unsigned __int64)this->UFG::ResourceFile::UFG::qResourceData::UFG::qNodeRB<UFG::qResourceData>::mNode.mUID << 32,
    0xE8C45525);
  ++UFG::LoadedChunk::sLoadedChunkCount;
}

// File Line: 1343
// RVA: 0x160090
void __fastcall UFG::ExternallyLoadedChunk::ExternallyLoadedChunk(
        UFG::ExternallyLoadedChunk *this,
        unsigned int uid,
        void *user_data,
        UFG::AllocationProfile *profile)
{
  UFG::ResourceFile::ResourceFile(this, uid, profile);
  this->mUserData = user_data;
  UFG::qSPrintf(this->mDebugName, 36, "RF-ExternalChunk   uid: 0x%08x", uid);
  ++UFG::ExternallyLoadedChunk::sLoadedChunkCount;
  ++UFG::ExternallyLoadedChunk::sLoadedChunkTotal;
}

// File Line: 1354
// RVA: 0x15FFB0
void __fastcall UFG::ExternallyLoadedChunk::ExternallyLoadedChunk(
        UFG::ExternallyLoadedChunk *this,
        unsigned int uid,
        void *user_data,
        UFG::qVRAMemoryHandle *handle)
{
  UFG::ResourceFile::ResourceFile(this, uid, handle);
  this->mUserData = user_data;
  UFG::qSPrintf(this->mDebugName, 36, "RF-ExternalChunk   uid: 0x%08x", uid);
  UFG::qPrintChannel::Print(
    &UFG::qChunkFileSystem::mResourceChannel,
    OUTPUT_LEVEL_WARNING,
    "[Resource - ReloadSync]     Creating ExternallyLoadedChunk for %s at memory location 0x%08x from 0x%08x\n");
  ++UFG::ExternallyLoadedChunk::sLoadedChunkCount;
  ++UFG::ExternallyLoadedChunk::sLoadedChunkTotal;
}

// File Line: 1370
// RVA: 0x16DDF0
UFG::qTreeRB<UFG::qResourceData,UFG::qResourceData,1> *__fastcall UFG::ExternallyLoadedChunk::FindExistingChunk(
        unsigned int filename_uid,
        char *memory_location)
{
  UFG::qTreeRB<UFG::qResourceData,UFG::qResourceData,1> *v4; // rdi
  UFG::qTreeRB<UFG::qResourceData,UFG::qResourceData,1> *v5; // rbx
  unsigned int mUID; // eax
  UFG::qBaseNodeRB *v7; // rax
  int v8; // eax
  char *mParent; // rax
  UFG::qTreeRB<UFG::qResourceData,UFG::qResourceData,1> *i; // rax
  UFG::qTreeRB<UFG::qResourceData,UFG::qResourceData,1> *Prev; // rax
  UFG::qBaseNodeRB *v13; // rcx
  int v14; // ecx
  char *v15; // rcx
  UFG::qTreeRB<UFG::qResourceData,UFG::qResourceData,1> *j; // rcx
  UFG::qTreeRB<UFG::qResourceData,UFG::qResourceData,1> *v17; // rcx
  UFG::qTreeRB<UFG::qResourceData,UFG::qResourceData,1> *Next; // rcx
  UFG::qBaseNodeRB *v19; // rax
  int v20; // eax
  char *v21; // rax
  UFG::qTreeRB<UFG::qResourceData,UFG::qResourceData,1> *k; // rax
  UFG::qTreeRB<UFG::qResourceData,UFG::qResourceData,1> *v23; // rax

  v4 = 0i64;
  if ( !filename_uid )
    return 0i64;
  v5 = &stru_14235B050;
  while ( 1 )
  {
    mUID = v5->mTree.mRoot.mUID;
    if ( v5 != &stru_14235B050 && mUID == filename_uid )
      break;
    if ( filename_uid > mUID )
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
    goto LABEL_22;
  v8 = HIDWORD(v7->mChild[1]);
  switch ( v8 )
  {
    case 0:
      mParent = (char *)v5[2].mTree.mRoot.mParent;
      break;
    case 1:
LABEL_22:
      mParent = (char *)v5[1].mTree.mNULL.mChild[1];
      break;
    case 2:
      mParent = (char *)v5[2].mTree.mRoot.mParent;
      break;
    default:
      mParent = 0i64;
      break;
  }
  if ( mParent == memory_location )
    return v5;
  Prev = (UFG::qTreeRB<UFG::qResourceData,UFG::qResourceData,1> *)UFG::qTreeRB<UFG::qResourceData,UFG::qResourceData,1>::GetPrev(
                                                                    &stru_14235B050,
                                                                    (UFG::qNodeRB<UFG::qResourceData> *)v5);
  while ( Prev && Prev->mTree.mRoot.mUID == filename_uid )
  {
    v13 = Prev[2].mTree.mRoot.mChild[0];
    if ( !v13 )
      goto LABEL_35;
    v14 = HIDWORD(v13->mChild[1]);
    if ( v14 )
    {
      if ( v14 != 1 )
      {
        if ( v14 == 2 )
          v15 = (char *)Prev[2].mTree.mRoot.mParent;
        else
          v15 = 0i64;
        goto LABEL_36;
      }
LABEL_35:
      v15 = (char *)Prev[1].mTree.mNULL.mChild[1];
      goto LABEL_36;
    }
    v15 = (char *)Prev[2].mTree.mRoot.mParent;
LABEL_36:
    if ( v15 == memory_location )
      v4 = Prev;
    Prev = (UFG::qTreeRB<UFG::qResourceData,UFG::qResourceData,1> *)v5->mTree.mRoot.mChild[0];
    if ( &stru_14235B050.mTree.mNULL == (UFG::qBaseNodeRB *)Prev )
    {
      Prev = (UFG::qTreeRB<UFG::qResourceData,UFG::qResourceData,1> *)((unsigned __int64)v5->mTree.mRoot.mParent & 0xFFFFFFFFFFFFFFFEui64);
      if ( v5 == (UFG::qTreeRB<UFG::qResourceData,UFG::qResourceData,1> *)Prev->mTree.mRoot.mChild[0] )
      {
        while ( Prev != &stru_14235B050 )
        {
          v17 = Prev;
          Prev = (UFG::qTreeRB<UFG::qResourceData,UFG::qResourceData,1> *)((unsigned __int64)Prev->mTree.mRoot.mParent & 0xFFFFFFFFFFFFFFFEui64);
          if ( v17 != (UFG::qTreeRB<UFG::qResourceData,UFG::qResourceData,1> *)Prev->mTree.mRoot.mChild[0] )
            goto LABEL_47;
        }
        Prev = 0i64;
      }
    }
    else
    {
      for ( j = (UFG::qTreeRB<UFG::qResourceData,UFG::qResourceData,1> *)Prev->mTree.mRoot.mChild[1];
            j != (UFG::qTreeRB<UFG::qResourceData,UFG::qResourceData,1> *)&stru_14235B050.mTree.mNULL;
            j = (UFG::qTreeRB<UFG::qResourceData,UFG::qResourceData,1> *)j->mTree.mRoot.mChild[1] )
      {
        Prev = j;
      }
    }
LABEL_47:
    if ( v4 )
      break;
  }
  Next = (UFG::qTreeRB<UFG::qResourceData,UFG::qResourceData,1> *)UFG::qTreeRB<UFG::qResourceData,UFG::qResourceData,1>::GetNext(
                                                                    &stru_14235B050,
                                                                    &v5->mTree.mRoot);
  if ( !v4 )
  {
    while ( 1 )
    {
      if ( !Next || Next->mTree.mRoot.mUID != filename_uid )
        return v4;
      v19 = Next[2].mTree.mRoot.mChild[0];
      if ( !v19 )
        goto LABEL_58;
      v20 = HIDWORD(v19->mChild[1]);
      if ( v20 )
        break;
      v21 = (char *)Next[2].mTree.mRoot.mParent;
LABEL_59:
      if ( v21 == memory_location )
        v4 = Next;
      Next = (UFG::qTreeRB<UFG::qResourceData,UFG::qResourceData,1> *)v5->mTree.mRoot.mChild[1];
      if ( &stru_14235B050.mTree.mNULL == (UFG::qBaseNodeRB *)Next )
      {
        Next = (UFG::qTreeRB<UFG::qResourceData,UFG::qResourceData,1> *)((unsigned __int64)v5->mTree.mRoot.mParent & 0xFFFFFFFFFFFFFFFEui64);
        if ( v5 == (UFG::qTreeRB<UFG::qResourceData,UFG::qResourceData,1> *)Next->mTree.mRoot.mChild[1] )
        {
          do
          {
            v23 = Next;
            Next = (UFG::qTreeRB<UFG::qResourceData,UFG::qResourceData,1> *)((unsigned __int64)Next->mTree.mRoot.mParent & 0xFFFFFFFFFFFFFFFEui64);
          }
          while ( v23 == (UFG::qTreeRB<UFG::qResourceData,UFG::qResourceData,1> *)Next->mTree.mRoot.mChild[1] );
        }
        if ( Next == &stru_14235B050 )
          Next = 0i64;
      }
      else
      {
        for ( k = (UFG::qTreeRB<UFG::qResourceData,UFG::qResourceData,1> *)Next->mTree.mRoot.mChild[0];
              k != (UFG::qTreeRB<UFG::qResourceData,UFG::qResourceData,1> *)&stru_14235B050.mTree.mNULL;
              k = (UFG::qTreeRB<UFG::qResourceData,UFG::qResourceData,1> *)k->mTree.mRoot.mChild[0] )
        {
          Next = k;
        }
      }
      if ( v4 )
        return v4;
    }
    if ( v20 != 1 )
    {
      if ( v20 == 2 )
        v21 = (char *)Next[2].mTree.mRoot.mParent;
      else
        v21 = 0i64;
      goto LABEL_59;
    }
LABEL_58:
    v21 = (char *)Next[1].mTree.mNULL.mChild[1];
    goto LABEL_59;
  }
  return v4;
}

// File Line: 1416
// RVA: 0x166560
void __fastcall UFG::ExternallyLoadedChunk::AddNewChunk(
        unsigned int filename_uid,
        char *memory_location,
        unsigned __int64 location_size,
        void *user_data)
{
  UFG::AllocationProfile *AllocationProfile; // rbx
  const char *v7; // rdi
  UFG::qMemoryPool *v8; // rcx
  char *v9; // rax
  __int64 v10; // rax
  __int64 v11; // rdx
  UFG::qNode<UFG::ResourceFile,UFG::ZeroRefResourceFile> *mPrev; // rax
  UFG::qNode<UFG::AllocationProfile,UFG::AllocationProfile> *v14; // rcx
  UFG::qNode<UFG::AllocationProfile,UFG::AllocationProfile> *mNext; // rax

  AllocationProfile = UFG::AllocationProfile::CreateAllocationProfile(memory_location, location_size);
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
    UFG::ExternallyLoadedChunk::ExternallyLoadedChunk(
      (UFG::ExternallyLoadedChunk *)v9,
      filename_uid,
      user_data,
      AllocationProfile);
    v11 = v10;
  }
  else
  {
    v11 = 0i64;
  }
  if ( *(_QWORD *)(v11 + 200) )
  {
    mPrev = stru_14235B120.mNode.mPrev;
    stru_14235B120.mNode.mPrev->mNext = (UFG::qNode<UFG::ResourceFile,UFG::ZeroRefResourceFile> *)(v11 + 88);
    *(_QWORD *)(v11 + 88) = mPrev;
    *(_QWORD *)(v11 + 96) = &stru_14235B120;
    stru_14235B120.mNode.mPrev = (UFG::qNode<UFG::ResourceFile,UFG::ZeroRefResourceFile> *)(v11 + 88);
  }
  UFG::qResourceInventory::Add(&UFG::gResourceFileInventory, (UFG::qResourceData *)v11);
  if ( AllocationProfile->mRefCount-- == 1 )
  {
    --UFG::AllocationProfile::sActiveProfilesCount[AllocationProfile->mProfileType];
    v14 = AllocationProfile->mPrev;
    mNext = AllocationProfile->mNext;
    v14->mNext = mNext;
    mNext->mPrev = v14;
    AllocationProfile->mPrev = AllocationProfile;
    AllocationProfile->mNext = AllocationProfile;
    UFG::qMemoryPool::Free(UFG::gMainMemoryPool, AllocationProfile);
  }
}

// File Line: 1425
// RVA: 0x166490
void __fastcall UFG::ExternallyLoadedChunk::AddNewChunk(
        unsigned int filename_uid,
        UFG::qVRAMemoryHandle *handle,
        void *user_data)
{
  const char *v6; // rbx
  UFG::qMemoryPool *v7; // rcx
  char *v8; // rax
  __int64 v9; // rax
  __int64 v10; // rdx
  UFG::qNode<UFG::ResourceFile,UFG::ZeroRefResourceFile> *mPrev; // rax

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
    UFG::ExternallyLoadedChunk::ExternallyLoadedChunk((UFG::ExternallyLoadedChunk *)v8, filename_uid, user_data, handle);
    v10 = v9;
  }
  else
  {
    v10 = 0i64;
  }
  if ( *(_QWORD *)(v10 + 200) )
  {
    mPrev = stru_14235B120.mNode.mPrev;
    stru_14235B120.mNode.mPrev->mNext = (UFG::qNode<UFG::ResourceFile,UFG::ZeroRefResourceFile> *)(v10 + 88);
    *(_QWORD *)(v10 + 88) = mPrev;
    *(_QWORD *)(v10 + 96) = &stru_14235B120;
    stru_14235B120.mNode.mPrev = (UFG::qNode<UFG::ResourceFile,UFG::ZeroRefResourceFile> *)(v10 + 88);
  }
  UFG::qResourceInventory::Add(&UFG::gResourceFileInventory, (UFG::qResourceData *)v10);
}

// File Line: 1449
// RVA: 0x17A830
void __fastcall UFG::ExternallyLoadedChunk::RemoveExistingChunk(
        unsigned int filename_uid,
        UFG::qVRAMemoryHandle *handle)
{
  UFG::qResourceData *ExistingChunk; // rax
  UFG::ResourceFile *v5; // rbx

  UFG::qVRAMemoryPools::GetRequestedSize(handle);
  ExistingChunk = (UFG::qResourceData *)UFG::ExternallyLoadedChunk::FindExistingChunk(filename_uid, handle->mData);
  v5 = (UFG::ResourceFile *)ExistingChunk;
  if ( ExistingChunk )
  {
    UFG::qResourceInventory::Remove(&UFG::gResourceFileInventory, ExistingChunk);
    --UFG::ExternallyLoadedChunk::sLoadedChunkCount;
    UFG::ResourceFile::~ResourceFile(v5);
    UFG::qMemoryPool::Free(UFG::gMainMemoryPool, (char *)v5);
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
  UFG::qString *p_mChunkFilename; // rbx
  char *mData; // rdx
  UFG::qNode<UFG::qString,UFG::qString> *mPrev; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *mNext; // rax
  UFG::qString *p_mIndexFilename; // rbx
  char *v7; // rdx
  UFG::qNode<UFG::qString,UFG::qString> *v8; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *v9; // rax
  UFG::qNode<UFG::LoadedIndexFile,UFG::LoadedIndexFile> *v10; // rcx
  UFG::qNode<UFG::LoadedIndexFile,UFG::LoadedIndexFile> *v11; // rax

  UFG::qTypedResourceHandle<4117364251,UFG::qChunkFileIndex>::~qTypedResourceHandle<4117364251,UFG::qChunkFileIndex>(&this->mChunkFileIndexHandle);
  p_mChunkFilename = &this->mChunkFilename;
  mData = this->mChunkFilename.mData;
  if ( mData != UFG::qString::sEmptyString && mData )
    UFG::qMemoryPool::Free(UFG::gMainMemoryPool, mData);
  this->mChunkFilename.mMagic = 0;
  mPrev = p_mChunkFilename->mPrev;
  mNext = this->mChunkFilename.mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  p_mChunkFilename->mPrev = p_mChunkFilename;
  this->mChunkFilename.mNext = &this->mChunkFilename;
  p_mIndexFilename = &this->mIndexFilename;
  v7 = this->mIndexFilename.mData;
  if ( v7 != UFG::qString::sEmptyString && v7 )
    UFG::qMemoryPool::Free(UFG::gMainMemoryPool, v7);
  this->mIndexFilename.mMagic = 0;
  v8 = p_mIndexFilename->mPrev;
  v9 = this->mIndexFilename.mNext;
  v8->mNext = v9;
  v9->mPrev = v8;
  p_mIndexFilename->mPrev = p_mIndexFilename;
  this->mIndexFilename.mNext = &this->mIndexFilename;
  v10 = this->mPrev;
  v11 = this->mNext;
  v10->mNext = v11;
  v11->mPrev = v10;
  this->mPrev = this;
  this->mNext = this;
}

// File Line: 1498
// RVA: 0x16F680
char *__fastcall UFG::LoadedIndexFile::GetChunkFilename(UFG::LoadedIndexFile *this)
{
  unsigned int mHotswapChunkFilenameUID; // edx
  UFG::qTreeRB<UFG::qHotswappedFile,UFG::qHotswappedFile,1> *v3; // rax
  unsigned int mUID; // r8d
  UFG::qTreeRB<UFG::qHotswappedFile,UFG::qHotswappedFile,1> *i; // rcx

  mHotswapChunkFilenameUID = this->mHotswapChunkFilenameUID;
  if ( !mHotswapChunkFilenameUID )
    return this->mChunkFilename.mData;
  v3 = &UFG::qChunkFileSystem::mHotswappedFiles;
  while ( 1 )
  {
    mUID = v3->mTree.mRoot.mUID;
    if ( v3 != &UFG::qChunkFileSystem::mHotswappedFiles && mUID == mHotswapChunkFilenameUID )
      break;
    if ( mHotswapChunkFilenameUID > mUID )
      v3 = (UFG::qTreeRB<UFG::qHotswappedFile,UFG::qHotswappedFile,1> *)v3->mTree.mRoot.mChild[1];
    else
      v3 = (UFG::qTreeRB<UFG::qHotswappedFile,UFG::qHotswappedFile,1> *)v3->mTree.mRoot.mChild[0];
    if ( v3 == (UFG::qTreeRB<UFG::qHotswappedFile,UFG::qHotswappedFile,1> *)&UFG::qChunkFileSystem::mHotswappedFiles.mTree.mNULL )
      return this->mChunkFilename.mData;
  }
  for ( i = (UFG::qTreeRB<UFG::qHotswappedFile,UFG::qHotswappedFile,1> *)v3->mTree.mRoot.mChild[0];
        i;
        i = (UFG::qTreeRB<UFG::qHotswappedFile,UFG::qHotswappedFile,1> *)i->mTree.mRoot.mChild[0] )
  {
    if ( i->mTree.mRoot.mUID != mHotswapChunkFilenameUID )
      break;
    v3 = i;
  }
  if ( v3 )
    return *(char **)&v3->mTree.mNULL.mUID;
  else
    return this->mChunkFilename.mData;
}

// File Line: 1519
// RVA: 0x170510
char *__fastcall UFG::qResourceFileHandle::GetFileData(UFG::qResourceFileHandle *this, int offset)
{
  UFG::qResourceData *mData; // rax
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *mPrev; // r8
  __int64 v4; // rcx
  int v5; // ecx

  mData = this->mData;
  mPrev = 0i64;
  if ( !mData )
    return 0i64;
  v4 = *(_QWORD *)&mData[1].mDebugName[12];
  if ( !v4 )
    goto LABEL_7;
  v5 = *(_DWORD *)(v4 + 20);
  switch ( v5 )
  {
    case 0:
      return (char *)(*(_QWORD *)&mData[1].mDebugName[4] + offset);
    case 1:
LABEL_7:
      mPrev = mData[1].mResourceHandles.mNode.mPrev;
      break;
    case 2:
      return (char *)(*(_QWORD *)&mData[1].mDebugName[4] + offset);
  }
  return (char *)mPrev + offset;
}

// File Line: 1566
// RVA: 0x173590
void __fastcall UFG::qResourceInventory::Init(UFG::qResourceInventory *this)
{
  UFG::qPrintChannel::Print(&gInventoryChannel, OUTPUT_LEVEL_DEBUG, "[%s] Init()\n");
}

// File Line: 1571
// RVA: 0x167F30
// attributes: thunk
void __fastcall UFG::qResourceFileInventory::Close(UFG::qResourceFileInventory *this)
{
  UFG::qResourceInventory::Close(this);
}

// File Line: 1576
// RVA: 0x165730
void __fastcall UFG::qResourceFileInventory::Add(UFG::qResourceFileInventory *this, UFG::qResourceData *data)
{
  UFG::qBaseNodeRB *mPrev; // rax

  if ( *(_QWORD *)&data[2].mNode.mUID )
  {
    mPrev = (UFG::qBaseNodeRB *)this->mZeroRefResourceFiles.mNode.mPrev;
    mPrev->mChild[0] = &data[1].mNode;
    data[1].mNode.mParent = mPrev;
    data[1].mNode.mChild[0] = (UFG::qBaseNodeRB *)&this->mZeroRefResourceFiles;
    this->mZeroRefResourceFiles.mNode.mPrev = (UFG::qNode<UFG::ResourceFile,UFG::ZeroRefResourceFile> *)&data[1];
  }
  UFG::qResourceInventory::Add(this, data);
}

// File Line: 1588
// RVA: 0x178670
void __fastcall UFG::qResourceFileInventory::OnAttachHandle(
        UFG::qResourceFileInventory *this,
        UFG::qResourceHandle *handle,
        UFG::qResourceData *data)
{
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *mPrev; // r9
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *mNext; // r8
  UFG::qResourceHandle *v6; // rcx
  UFG::qResourceData *mParent; // rdx
  UFG::qBaseNodeRB *v8; // rax

  mPrev = handle[1].mPrev;
  if ( mPrev )
  {
    mNext = handle[1].mNext;
    v6 = handle;
    LOBYTE(handle) = 1;
    ((void (__fastcall *)(UFG::qResourceHandle *, UFG::qResourceHandle *, UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *))mPrev)(
      v6,
      handle,
      mNext);
  }
  if ( *(_QWORD *)&data[2].mNode.mUID )
  {
    mParent = (UFG::qResourceData *)data[1].mNode.mParent;
    if ( mParent != &data[1] || (UFG::qResourceData *)data[1].mNode.mChild[0] != &data[1] )
    {
      v8 = data[1].mNode.mChild[0];
      mParent->mNode.mChild[0] = v8;
      v8->mParent = &mParent->mNode;
      data[1].mNode.mParent = &data[1].mNode;
      data[1].mNode.mChild[0] = &data[1].mNode;
    }
  }
}

// File Line: 1607
// RVA: 0x1786D0
void __fastcall UFG::qResourceFileInventory::OnDetachHandle(
        UFG::qResourceFileInventory *this,
        UFG::qResourceHandle *handle,
        UFG::qResourceData *data)
{
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *mPrev; // r9
  UFG::qBaseNodeRB *v6; // rax

  mPrev = handle[1].mPrev;
  if ( mPrev )
    ((void (__fastcall *)(UFG::qResourceHandle *, _QWORD, UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *))mPrev)(
      handle,
      0i64,
      handle[1].mNext);
  if ( *(_QWORD *)&data[2].mNode.mUID )
  {
    if ( (UFG::qList<UFG::qResourceHandle,UFG::qResourceHandle,1,0> *)data->mResourceHandles.mNode.mNext == &data->mResourceHandles )
    {
      v6 = (UFG::qBaseNodeRB *)this->mZeroRefResourceFiles.mNode.mPrev;
      v6->mChild[0] = &data[1].mNode;
      data[1].mNode.mParent = v6;
      data[1].mNode.mChild[0] = (UFG::qBaseNodeRB *)&this->mZeroRefResourceFiles;
      this->mZeroRefResourceFiles.mNode.mPrev = (UFG::qNode<UFG::ResourceFile,UFG::ZeroRefResourceFile> *)&data[1];
    }
  }
}

// File Line: 1627
// RVA: 0x179250
void __fastcall UFG::qResourceFileInventory::PrintContents(UFG::qResourceFileInventory *this)
{
  UFG::qBaseNodeRB *v2; // rcx
  UFG::qTreeRB<UFG::qResourceData,UFG::qResourceData,1> *p_mResourceDatas; // r13
  UFG::qBaseNodeRB *v4; // rax
  UFG::qBaseNodeRB *i; // rbp
  UFG::qTreeRB<UFG::qResourceData,UFG::qResourceData,1> *v6; // rdi
  UFG::qBaseNodeRB *v7; // rax
  int v8; // eax
  __int64 v9; // rcx
  unsigned int mRequestedSize; // r14d
  unsigned __int16 v11; // ax
  UFG::qVRAMemoryPool *v12; // rsi
  unsigned __int16 mNumBlocksTotal; // ax
  unsigned __int16 mUID_high; // cx
  UFG::BlockInfo *Block; // rax
  UFG::qBaseNodeRB *v16; // rax
  int v17; // eax
  __int64 mParent; // r8
  __int64 v19; // r9
  UFG::qTreeRB<UFG::qResourceData,UFG::qResourceData,1> *v20; // rcx
  UFG::qBaseNodeRB *j; // rax
  UFG::qTreeRB<UFG::qResourceData,UFG::qResourceData,1> *v22; // rax
  UFG::qTreeRB<UFG::qResourceData,UFG::qResourceData,1> *v23; // rcx
  __int64 v24; // [rsp+20h] [rbp-48h]
  __int64 v25; // [rsp+28h] [rbp-40h]

  UFG::qPrintf("Contents of Inventory %.64s %d items\n", this->mName, (unsigned int)this->mResourceDatas.mTree.mCount);
  v2 = this->mResourceDatas.mTree.mRoot.mChild[0];
  p_mResourceDatas = &this->mResourceDatas;
  v4 = v2->mChild[0];
  for ( i = &p_mResourceDatas->mTree.mNULL; v4 != i; v4 = v4->mChild[0] )
    v2 = v4;
  v6 = 0i64;
  if ( v2 != i )
    v6 = (UFG::qTreeRB<UFG::qResourceData,UFG::qResourceData,1> *)v2;
  if ( v6 )
  {
    while ( 1 )
    {
      v7 = v6[2].mTree.mRoot.mChild[0];
      if ( !v7 )
        break;
      v8 = HIDWORD(v7->mChild[1]);
      if ( v8 )
      {
        if ( v8 == 1 )
        {
          LODWORD(v9) = UFG::qVRAMemoryPools::GetRequestedSize((UFG::qVRAMemoryHandle *)&v6[1].mTree.mNULL);
        }
        else if ( v8 == 2 )
        {
          v9 = *(_QWORD *)&v6[1].mTree.mCount;
        }
        else
        {
          LODWORD(v9) = 0;
        }
      }
      else
      {
        v9 = *(_QWORD *)&v6[1].mTree.mCount;
      }
LABEL_27:
      v16 = v6[2].mTree.mRoot.mChild[0];
      if ( !v16 )
        goto LABEL_34;
      v17 = HIDWORD(v16->mChild[1]);
      if ( v17 )
      {
        if ( v17 == 1 )
        {
LABEL_34:
          mParent = (__int64)v6[1].mTree.mNULL.mChild[1];
          goto LABEL_35;
        }
        if ( v17 == 2 )
          mParent = (__int64)v6[2].mTree.mRoot.mParent;
        else
          mParent = 0i64;
      }
      else
      {
        mParent = (__int64)v6[2].mTree.mRoot.mParent;
      }
LABEL_35:
      if ( (_DWORD)v9 )
        v19 = (unsigned int)v9 + mParent - 1;
      else
        v19 = mParent;
      LODWORD(v25) = v9;
      LODWORD(v24) = v9;
      UFG::qPrintf(
        "  - Resource DataUID:0x%08x Memory:0x%08x-0x%08x Size:0x%08x (%9u) Name:%.36s\n",
        v6->mTree.mRoot.mUID,
        mParent,
        v19,
        v24,
        v25,
        (const char *)&v6->mTree.mNULL.mChild[1] + 4);
      v20 = (UFG::qTreeRB<UFG::qResourceData,UFG::qResourceData,1> *)v6->mTree.mRoot.mChild[1];
      if ( i == (UFG::qBaseNodeRB *)v20 )
      {
        v22 = (UFG::qTreeRB<UFG::qResourceData,UFG::qResourceData,1> *)((unsigned __int64)v6->mTree.mRoot.mParent & 0xFFFFFFFFFFFFFFFEui64);
        if ( v6 == (UFG::qTreeRB<UFG::qResourceData,UFG::qResourceData,1> *)v22->mTree.mRoot.mChild[1] )
        {
          do
          {
            v23 = v22;
            v22 = (UFG::qTreeRB<UFG::qResourceData,UFG::qResourceData,1> *)((unsigned __int64)v22->mTree.mRoot.mParent & 0xFFFFFFFFFFFFFFFEui64);
          }
          while ( v23 == (UFG::qTreeRB<UFG::qResourceData,UFG::qResourceData,1> *)v22->mTree.mRoot.mChild[1] );
        }
        v6 = v22;
        if ( v22 == p_mResourceDatas )
          v6 = 0i64;
      }
      else
      {
        for ( j = v20->mTree.mRoot.mChild[0]; j != i; j = j->mChild[0] )
          v20 = (UFG::qTreeRB<UFG::qResourceData,UFG::qResourceData,1> *)j;
        v6 = v20;
      }
      if ( !v6 )
        return;
    }
    mRequestedSize = 0;
    UFG::qMutex::Lock((LPCRITICAL_SECTION)&UFG::qVRAMemoryPools::sVRAMPoolsLock);
    if ( !v6[1].mTree.mNULL.mChild[1]
      || (v11 = v6[1].mTree.mNULL.mUID & 0x7FFF, v11 >= 0x10u)
      || (v12 = UFG::qVRAMemoryPools::sVRAMemoryPools[v11]) == 0i64 )
    {
LABEL_26:
      UFG::qMutex::Unlock((LPCRITICAL_SECTION)&UFG::qVRAMemoryPools::sVRAMPoolsLock);
      LODWORD(v9) = mRequestedSize;
      goto LABEL_27;
    }
    UFG::qMutex::Lock((LPCRITICAL_SECTION)&v12->mPoolLock);
    UFG::qVRAMemoryPool::AssertValid(v12);
    if ( v12->mInitialized == 1 && (v6[1].mTree.mNULL.mUID & 0x7FFF) == v12->mPoolID )
    {
      mNumBlocksTotal = v12->mNumBlocksTotal;
      mUID_high = HIWORD(v6[1].mTree.mNULL.mUID);
      if ( !mNumBlocksTotal )
      {
        Block = UFG::qVRAMemoryPools::GetBlock(mUID_high);
LABEL_23:
        if ( Block )
          mRequestedSize = Block->mRequestedSize;
        goto LABEL_25;
      }
      if ( mUID_high < mNumBlocksTotal )
      {
        Block = &v12->mBlocks[(unsigned __int64)mUID_high];
        goto LABEL_23;
      }
    }
LABEL_25:
    UFG::qMutex::Unlock((LPCRITICAL_SECTION)&v12->mPoolLock);
    goto LABEL_26;
  }
}

