// File Line: 170
// RVA: 0x1468400
__int64 UFG::qChunkFileSystem::_dynamic_initializer_for__mHotswappedFiles__()
{
  UFG::qChunkFileSystem::mHotswappedFiles.mTree.mNULL.mParent = (UFG::qBaseNodeRB *)((unsigned __int64)&UFG::qChunkFileSystem::mHotswappedFiles.mTree.mNULL & 0xFFFFFFFFFFFFFFFEui64);
  UFG::qChunkFileSystem::mHotswappedFiles.mTree.mRoot.mParent = (UFG::qBaseNodeRB *)((unsigned __int64)&UFG::qChunkFileSystem::mHotswappedFiles.mTree.mNULL & 0xFFFFFFFFFFFFFFFEui64);
  return atexit(UFG::qChunkFileSystem::_dynamic_atexit_destructor_for__mHotswappedFiles__);
}

// File Line: 172
// RVA: 0x1468590
__int64 UFG::qChunkFileSystem::_dynamic_initializer_for__mResourceChannel__()
{
  UFG::qChunkFileSystem::mResourceChannel.mLogFilename.mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&UFG::qChunkFileSystem::mResourceChannel.mLogFilename.mPrev;
  UFG::qChunkFileSystem::mResourceChannel.mLogFilename.mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&UFG::qChunkFileSystem::mResourceChannel.mLogFilename.mPrev;
  *(_QWORD *)&UFG::qChunkFileSystem::mResourceChannel.mLogFilename.mMagic = 16909060i64;
  UFG::qChunkFileSystem::mResourceChannel.mLogFilename.mData = (char *)UFG::qString::sEmptyString;
  *(_QWORD *)&UFG::qChunkFileSystem::mResourceChannel.mLogFilename.mStringHash32 = -1i64;
  return atexit(UFG::qChunkFileSystem::_dynamic_atexit_destructor_for__mResourceChannel__);
}

// File Line: 176
// RVA: 0x14683B0
__int64 UFG::qChunkFileSystem::_dynamic_initializer_for__mFileHandles__()
{
  UFG::qChunkFileSystem::mFileHandles.mTree.mNULL.mParent = (UFG::qBaseNodeRB *)((unsigned __int64)&UFG::qChunkFileSystem::mFileHandles.mTree.mNULL & 0xFFFFFFFFFFFFFFFEui64);
  UFG::qChunkFileSystem::mFileHandles.mTree.mRoot.mParent = (UFG::qBaseNodeRB *)((unsigned __int64)&UFG::qChunkFileSystem::mFileHandles.mTree.mNULL & 0xFFFFFFFFFFFFFFFEui64);
  return atexit(UFG::qChunkFileSystem::_dynamic_atexit_destructor_for__mFileHandles__);
}

// File Line: 177
// RVA: 0x1468520
__int64 UFG::qChunkFileSystem::_dynamic_initializer_for__mLoadedChunks__()
{
  UFG::qChunkFileSystem::mLoadedChunks.mTree.mNULL.mParent = (UFG::qBaseNodeRB *)((unsigned __int64)&UFG::qChunkFileSystem::mLoadedChunks.mTree.mNULL & 0xFFFFFFFFFFFFFFFEui64);
  UFG::qChunkFileSystem::mLoadedChunks.mTree.mRoot.mParent = (UFG::qBaseNodeRB *)((unsigned __int64)&UFG::qChunkFileSystem::mLoadedChunks.mTree.mNULL & 0xFFFFFFFFFFFFFFFEui64);
  return atexit(UFG::qChunkFileSystem::_dynamic_atexit_destructor_for__mLoadedChunks__);
}

// File Line: 178
// RVA: 0x14684D0
__int64 UFG::qChunkFileSystem::_dynamic_initializer_for__mLoadedChunkFiles__()
{
  UFG::qChunkFileSystem::mLoadedChunkFiles.mTree.mNULL.mParent = (UFG::qBaseNodeRB *)((unsigned __int64)&UFG::qChunkFileSystem::mLoadedChunkFiles.mTree.mNULL & 0xFFFFFFFFFFFFFFFEui64);
  UFG::qChunkFileSystem::mLoadedChunkFiles.mTree.mRoot.mParent = (UFG::qBaseNodeRB *)((unsigned __int64)&UFG::qChunkFileSystem::mLoadedChunkFiles.mTree.mNULL & 0xFFFFFFFFFFFFFFFEui64);
  return atexit(UFG::qChunkFileSystem::_dynamic_atexit_destructor_for__mLoadedChunkFiles__);
}

// File Line: 179
// RVA: 0x1468570
__int64 UFG::qChunkFileSystem::_dynamic_initializer_for__mLoadedIndexFiles__()
{
  return atexit(UFG::qChunkFileSystem::_dynamic_atexit_destructor_for__mLoadedIndexFiles__);
}

// File Line: 183
// RVA: 0x14685F0
__int64 UFG::qChunkFileSystem::_dynamic_initializer_for__mSingleFileLoadTables__()
{
  UFG::qChunkFileSystem::mSingleFileLoadTables.mTree.mNULL.mParent = (UFG::qBaseNodeRB *)((unsigned __int64)&UFG::qChunkFileSystem::mSingleFileLoadTables.mTree.mNULL & 0xFFFFFFFFFFFFFFFEui64);
  UFG::qChunkFileSystem::mSingleFileLoadTables.mTree.mRoot.mParent = (UFG::qBaseNodeRB *)((unsigned __int64)&UFG::qChunkFileSystem::mSingleFileLoadTables.mTree.mNULL & 0xFFFFFFFFFFFFFFFEui64);
  return atexit(UFG::qChunkFileSystem::_dynamic_atexit_destructor_for__mSingleFileLoadTables__);
}

// File Line: 184
// RVA: 0x1468360
__int64 UFG::qChunkFileSystem::_dynamic_initializer_for__mCreatedLoadTables__()
{
  UFG::qChunkFileSystem::mCreatedLoadTables.mTree.mNULL.mParent = (UFG::qBaseNodeRB *)((unsigned __int64)&UFG::qChunkFileSystem::mCreatedLoadTables.mTree.mNULL & 0xFFFFFFFFFFFFFFFEui64);
  UFG::qChunkFileSystem::mCreatedLoadTables.mTree.mRoot.mParent = (UFG::qBaseNodeRB *)((unsigned __int64)&UFG::qChunkFileSystem::mCreatedLoadTables.mTree.mNULL & 0xFFFFFFFFFFFFFFFEui64);
  return atexit(UFG::qChunkFileSystem::_dynamic_atexit_destructor_for__mCreatedLoadTables__);
}

// File Line: 205
// RVA: 0x1468450
__int64 UFG::qChunkFileSystem::_dynamic_initializer_for__mLoadTablesBundleSort__()
{
  return atexit(UFG::qChunkFileSystem::_dynamic_atexit_destructor_for__mLoadTablesBundleSort__);
}

// File Line: 206
// RVA: 0x14684B0
__int64 UFG::qChunkFileSystem::_dynamic_initializer_for__mLoadTablesLoading__()
{
  return atexit(UFG::qChunkFileSystem::_dynamic_atexit_destructor_for__mLoadTablesLoading__);
}

// File Line: 207
// RVA: 0x1468470
__int64 UFG::qChunkFileSystem::_dynamic_initializer_for__mLoadTablesCallback__()
{
  return atexit(UFG::qChunkFileSystem::_dynamic_atexit_destructor_for__mLoadTablesCallback__);
}

// File Line: 208
// RVA: 0x1468490
__int64 UFG::qChunkFileSystem::_dynamic_initializer_for__mLoadTablesLoaded__()
{
  return atexit(UFG::qChunkFileSystem::_dynamic_atexit_destructor_for__mLoadTablesLoaded__);
}

// File Line: 605
// RVA: 0x1721F0
UFG::qTreeRB<UFG::ResourceFileHandle,UFG::ResourceFileHandle,1> *__fastcall UFG::qChunkFileSystem::GetResourceFileHandle(const char *filename)
{
  const char *v1; // rsi
  UFG::ResourceFileHandle *v2; // rdi
  unsigned int v3; // ebx
  const char *v4; // r8
  char i; // dl
  UFG::qTreeRB<UFG::ResourceFileHandle,UFG::ResourceFileHandle,1> *result; // rax
  unsigned int v7; // ecx
  UFG::ResourceFileHandle *j; // rcx
  UFG::qMemoryPool *v9; // rcx
  UFG::allocator::free_link *v10; // rax
  UFG::ResourceFileHandle *v11; // rax

  v1 = filename;
  v2 = 0i64;
  v3 = -1;
  if ( filename )
  {
    v4 = filename;
    for ( i = *filename; *v4; i = *v4 )
    {
      if ( i <= 122 && i >= 97 )
        i -= 32;
      ++v4;
      v3 = (v3 << 8) ^ sCrcTable32[(unsigned __int8)(i ^ HIBYTE(v3))];
    }
    if ( !v3 )
      goto LABEL_28;
  }
  result = &UFG::qChunkFileSystem::mFileHandles;
  while ( 1 )
  {
    v7 = result->mTree.mRoot.mUID;
    if ( result != &UFG::qChunkFileSystem::mFileHandles && v7 == v3 )
      break;
    if ( v3 > v7 )
      result = (UFG::qTreeRB<UFG::ResourceFileHandle,UFG::ResourceFileHandle,1> *)result->mTree.mRoot.mChild[1];
    else
      result = (UFG::qTreeRB<UFG::ResourceFileHandle,UFG::ResourceFileHandle,1> *)result->mTree.mRoot.mChild[0];
    if ( result == (UFG::qTreeRB<UFG::ResourceFileHandle,UFG::ResourceFileHandle,1> *)&UFG::qChunkFileSystem::mFileHandles.mTree.mNULL )
    {
      result = 0i64;
      goto LABEL_20;
    }
  }
  for ( j = (UFG::ResourceFileHandle *)result->mTree.mRoot.mChild[0]; j; j = (UFG::ResourceFileHandle *)j->mNode.mChild[0] )
  {
    if ( j->mNode.mUID != v3 )
      break;
    result = (UFG::qTreeRB<UFG::ResourceFileHandle,UFG::ResourceFileHandle,1> *)j;
  }
LABEL_20:
  if ( !result )
  {
LABEL_28:
    v9 = UFG::gMainMemoryPool;
    if ( !UFG::gMainMemoryPool )
    {
      UFG::InternalSetupMainMemoryPool((UFG *)UFG::gMainMemoryPool);
      v9 = UFG::gMainMemoryPool;
    }
    v10 = UFG::qMemoryPool::Allocate(v9, 0x50ui64, "ResourceFileHandle", 0i64, 1u);
    if ( v10 )
    {
      UFG::ResourceFileHandle::ResourceFileHandle((UFG::ResourceFileHandle *)v10, v1, v3);
      v2 = v11;
    }
    UFG::qBaseTreeRB::Add(&UFG::qChunkFileSystem::mFileHandles.mTree, &v2->mNode);
    result = (UFG::qTreeRB<UFG::ResourceFileHandle,UFG::ResourceFileHandle,1> *)v2;
  }
  return result;
}

// File Line: 621
// RVA: 0x16F520
char __fastcall UFG::qChunkFileSystem::GetChunkFileIndexEntry(UFG::LoadedIndexFile **out_index_file, UFG::qChunkFileIndexEntry **out_chunk_file_index, unsigned int filename_uid)
{
  UFG::qList<UFG::LoadedIndexFile,UFG::LoadedIndexFile,1,0> *v3; // rbx
  unsigned int v4; // er10
  UFG::LoadedIndexFile **v5; // rsi
  UFG::qNode<UFG::LoadedIndexFile,UFG::LoadedIndexFile> *v6; // rax
  UFG::qNode<UFG::LoadedIndexFile,UFG::LoadedIndexFile> *v7; // rcx
  signed __int64 v8; // r11
  int v9; // er8
  int v10; // er9
  int v11; // er8
  __int64 v12; // rax
  unsigned int v13; // ecx
  char result; // al
  UFG::qChunkFileIndexEntry *v15; // rcx

  v3 = (UFG::qList<UFG::LoadedIndexFile,UFG::LoadedIndexFile,1,0> *)UFG::qChunkFileSystem::mLoadedIndexFiles.mNode.mNext;
  v4 = filename_uid;
  v5 = out_index_file;
  if ( (UFG::qList<UFG::LoadedIndexFile,UFG::LoadedIndexFile,1,0> *)UFG::qChunkFileSystem::mLoadedIndexFiles.mNode.mNext == &UFG::qChunkFileSystem::mLoadedIndexFiles )
  {
LABEL_17:
    *v5 = 0i64;
    result = 0;
    *out_chunk_file_index = 0i64;
  }
  else
  {
    while ( 1 )
    {
      v6 = v3[8].mNode.mPrev;
      if ( v6 )
      {
        v7 = v6[5].mNext;
        v8 = (signed __int64)(v7 ? (UFG::qNode<UFG::LoadedIndexFile,UFG::LoadedIndexFile> **)((char *)&v6[5].mNext
                                                                                            + (_QWORD)v7) : 0i64);
        v9 = (int)v6[6].mPrev;
        if ( v8 )
        {
          if ( v9 )
          {
            v10 = 0;
            v11 = v9 - 1;
            if ( v11 >= 0 )
            {
              do
              {
                v12 = (unsigned int)(v11 + v10) >> 1;
                v13 = *(_DWORD *)(v8 + 20 * v12);
                if ( v13 >= v4 )
                {
                  if ( v13 <= v4 )
                    goto LABEL_15;
                  v11 = v12 - 1;
                }
                else
                {
                  v10 = v12 + 1;
                }
              }
              while ( v10 <= v11 );
            }
            LODWORD(v12) = -1 - v10;
LABEL_15:
            if ( (signed int)v12 >= 0 )
              break;
          }
        }
      }
      v3 = (UFG::qList<UFG::LoadedIndexFile,UFG::LoadedIndexFile,1,0> *)v3->mNode.mNext;
      if ( v3 == &UFG::qChunkFileSystem::mLoadedIndexFiles )
        goto LABEL_17;
    }
    *v5 = (UFG::LoadedIndexFile *)v3;
    v15 = (UFG::qChunkFileIndexEntry *)(v8 + 20i64 * (signed int)v12);
    result = 1;
    *out_chunk_file_index = v15;
  }
  return result;
}

// File Line: 655
// RVA: 0x16FAA0
UFG::ResourceLoadTable *__fastcall UFG::qChunkFileSystem::GetCreatedLoadTable(unsigned int load_table_uid)
{
  unsigned int v1; // edx
  UFG::qTreeRB<UFG::ResourceLoadTable,UFG::ResourceLoadTable,1> *v2; // rax
  unsigned int v3; // ecx
  UFG::ResourceLoadTable *result; // rax
  UFG::qTreeRB<UFG::ResourceLoadTable,UFG::ResourceLoadTable,1> *i; // rcx

  v1 = load_table_uid;
  if ( !load_table_uid )
    goto LABEL_9;
  v2 = &UFG::qChunkFileSystem::mCreatedLoadTables;
  while ( 1 )
  {
    v3 = v2->mTree.mRoot.mUID;
    if ( v2 != &UFG::qChunkFileSystem::mCreatedLoadTables && v3 == v1 )
      break;
    if ( v1 > v3 )
      v2 = (UFG::qTreeRB<UFG::ResourceLoadTable,UFG::ResourceLoadTable,1> *)v2->mTree.mRoot.mChild[1];
    else
      v2 = (UFG::qTreeRB<UFG::ResourceLoadTable,UFG::ResourceLoadTable,1> *)v2->mTree.mRoot.mChild[0];
    if ( v2 == (UFG::qTreeRB<UFG::ResourceLoadTable,UFG::ResourceLoadTable,1> *)&UFG::qChunkFileSystem::mCreatedLoadTables.mTree.mNULL )
      goto LABEL_9;
  }
  for ( i = (UFG::qTreeRB<UFG::ResourceLoadTable,UFG::ResourceLoadTable,1> *)v2->mTree.mRoot.mChild[0];
        i;
        i = (UFG::qTreeRB<UFG::ResourceLoadTable,UFG::ResourceLoadTable,1> *)i->mTree.mRoot.mChild[0] )
  {
    if ( i->mTree.mRoot.mUID != v1 )
      break;
    v2 = i;
  }
  if ( v2 )
    result = (UFG::ResourceLoadTable *)&v2[-1].mTree.mNULL.mUID;
  else
LABEL_9:
    result = 0i64;
  return result;
}

// File Line: 995
// RVA: 0x176AD0
void __fastcall UFG::qChunkFileSystem::Load(const char *filename, unsigned __int64 allocation_params, void (__fastcall *callback)(const char *, bool, void *), void *callback_param, UFG::ResourceFileContentType content_type)
{
  UFG::qChunkFileSystem::Load(filename, UFG::gMainMemoryPool, allocation_params, callback, callback_param, content_type);
}

// File Line: 1000
// RVA: 0x1768F0
void __fastcall UFG::qChunkFileSystem::Load(const char *filename, UFG::qMemoryPool *memory_pool, unsigned __int64 allocation_params, void (__fastcall *callback)(const char *, bool, void *), void *callback_param, UFG::ResourceFileContentType content_type)
{
  void (__fastcall *v6)(const char *, bool, void *); // r15
  unsigned __int64 v7; // rbp
  UFG::qMemoryPool *v8; // r14
  const char *v9; // rsi
  unsigned int v10; // edi
  const char *v11; // r8
  char i; // al
  UFG::qMemoryPool *v13; // rcx
  UFG::allocator::free_link *v14; // rbx
  int v15; // ecx
  UFG::allocator::free_link *v16; // ST48_8
  int scratch_buffer_size; // ST28_4
  int check_null; // ST20_4

  v6 = callback;
  v7 = allocation_params;
  v8 = memory_pool;
  v9 = filename;
  v10 = -1;
  if ( filename )
  {
    v11 = filename;
    for ( i = *filename; *v11; i = *v11 )
    {
      if ( i <= 122 && i >= 97 )
        i -= 32;
      ++v11;
      v10 = (v10 << 8) ^ sCrcTable32[(unsigned __int8)(i ^ HIBYTE(v10))];
    }
  }
  UFG::qPrintChannel::Print(
    &UFG::qChunkFileSystem::mResourceChannel,
    OUTPUT_LEVEL_WARNING,
    "[Resource - SingleLoad] uid=0x%08x MemoryPool(%p) params(%u64) '%s'\n");
  v13 = UFG::gMainMemoryPool;
  if ( !UFG::gMainMemoryPool )
  {
    UFG::InternalSetupMainMemoryPool((UFG *)UFG::gMainMemoryPool);
    v13 = UFG::gMainMemoryPool;
  }
  v14 = UFG::qMemoryPool::Allocate(v13, 0x70ui64, "OneOffLoadTable", 0i64, 1u);
  if ( v14 )
  {
    v15 = (signed int)UFG::qChunkFileSystem::mNextLoadTableUID;
    LODWORD(UFG::qChunkFileSystem::mNextLoadTableUID) = (_DWORD)UFG::qChunkFileSystem::mNextLoadTableUID + 1;
    v14->mNext = v14;
    v14[1].mNext = v14;
    v14[2].mNext = 0i64;
    v14[3].mNext = 0i64;
    v14[4].mNext = 0i64;
    LODWORD(v14[5].mNext) = v10;
    LODWORD(v14[6].mNext) = 0;
    v16 = v14 + 9;
    v16->mNext = v16;
    v16[1].mNext = v16;
    LODWORD(v14[11].mNext) = 0;
    HIDWORD(v14[11].mNext) = v15;
    LODWORD(v14[12].mNext) = v10;
    v14[13].mNext = 0i64;
    v14[7].mNext = (UFG::allocator::free_link *)v6;
    v14[8].mNext = (UFG::allocator::free_link *)callback_param;
  }
  else
  {
    v14 = 0i64;
  }
  scratch_buffer_size = (int)v14[6].mNext;
  check_null = HIDWORD(v14[11].mNext);
  UFG::qPrintChannel::Print(
    &UFG::qChunkFileSystem::mResourceChannel,
    OUTPUT_LEVEL_DEBUG,
    "[Resource - Created_Table] tab=%p uid=0x%08x  state=%d\n");
  UFG::qBaseTreeRB::Add(&UFG::qChunkFileSystem::mSingleFileLoadTables.mTree, (UFG::qBaseNodeRB *)&v14[2]);
  UFG::ResourceLoadTable::Add((UFG::ResourceLoadTable *)v14, v9, v8, v7, 0i64, 0, content_type);
  UFG::qChunkFileSystem::Internal_Load((UFG::ResourceLoadTable *)v14);
}

// File Line: 1123
// RVA: 0x17F0C0
void __fastcall UFG::qChunkFileSystem::Unload(const char *filename)
{
  signed int v1; // er8
  char v2; // al
  const char *i; // r10

  v1 = -1;
  if ( filename )
  {
    v2 = *filename;
    for ( i = filename; *i; v2 = *i )
    {
      if ( v2 <= 122 && v2 >= 97 )
        v2 -= 32;
      ++i;
      v1 = (v1 << 8) ^ sCrcTable32[(unsigned __int8)(v2 ^ HIBYTE(v1))];
    }
  }
  UFG::qChunkFileSystem::Unload(v1, filename);
}

// File Line: 1130
// RVA: 0x17ED90
void __fastcall UFG::qChunkFileSystem::Unload(unsigned int filename_uid, const char *filename)
{
  unsigned int v2; // ebx
  UFG::qTreeRB<UFG::ResourceLoadTable,UFG::ResourceLoadTable,1> *v3; // rax
  unsigned int v4; // ecx
  UFG::qTreeRB<UFG::qValueNodeRB<UFG::LoadedChunkFile *>,UFG::qValueNodeRB<UFG::LoadedChunkFile *>,1> *v5; // rax
  unsigned int v6; // ecx
  UFG::qTreeRB<UFG::ResourceLoadTable,UFG::ResourceLoadTable,1> *i; // rcx
  UFG::qTreeRB<UFG::qValueNodeRB<UFG::LoadedChunkFile *>,UFG::qValueNodeRB<UFG::LoadedChunkFile *>,1> *j; // rcx
  UFG::LoadedChunkFile *v9; // rcx

  v2 = filename_uid;
  UFG::qPrintChannel::Print(
    &UFG::qChunkFileSystem::mResourceChannel,
    OUTPUT_LEVEL_WARNING,
    "[Resource - SingleUnload] uid=0x%08x '%s'\n");
  if ( v2 )
  {
    v3 = &UFG::qChunkFileSystem::mSingleFileLoadTables;
    while ( 1 )
    {
      v4 = v3->mTree.mRoot.mUID;
      if ( v3 != &UFG::qChunkFileSystem::mSingleFileLoadTables && v4 == v2 )
        break;
      if ( v2 > v4 )
        v3 = (UFG::qTreeRB<UFG::ResourceLoadTable,UFG::ResourceLoadTable,1> *)v3->mTree.mRoot.mChild[1];
      else
        v3 = (UFG::qTreeRB<UFG::ResourceLoadTable,UFG::ResourceLoadTable,1> *)v3->mTree.mRoot.mChild[0];
      if ( v3 == (UFG::qTreeRB<UFG::ResourceLoadTable,UFG::ResourceLoadTable,1> *)&UFG::qChunkFileSystem::mSingleFileLoadTables.mTree.mNULL )
        goto LABEL_9;
    }
    for ( i = (UFG::qTreeRB<UFG::ResourceLoadTable,UFG::ResourceLoadTable,1> *)v3->mTree.mRoot.mChild[0];
          i;
          i = (UFG::qTreeRB<UFG::ResourceLoadTable,UFG::ResourceLoadTable,1> *)i->mTree.mRoot.mChild[0] )
    {
      if ( i->mTree.mRoot.mUID != v2 )
        break;
      v3 = i;
    }
    if ( v3 && v3 != (UFG::qTreeRB<UFG::ResourceLoadTable,UFG::ResourceLoadTable,1> *)16 )
    {
      UFG::qChunkFileSystem::Internal_Unload((UFG::ResourceLoadTable *)&v3[-1].mTree.mNULL.mUID, 0);
      return;
    }
LABEL_9:
    v5 = &UFG::qChunkFileSystem::mLoadedChunkFiles;
    while ( 1 )
    {
      v6 = v5->mTree.mRoot.mUID;
      if ( v5 != &UFG::qChunkFileSystem::mLoadedChunkFiles && v6 == v2 )
        break;
      if ( v2 > v6 )
        v5 = (UFG::qTreeRB<UFG::qValueNodeRB<UFG::LoadedChunkFile *>,UFG::qValueNodeRB<UFG::LoadedChunkFile *>,1> *)v5->mTree.mRoot.mChild[1];
      else
        v5 = (UFG::qTreeRB<UFG::qValueNodeRB<UFG::LoadedChunkFile *>,UFG::qValueNodeRB<UFG::LoadedChunkFile *>,1> *)v5->mTree.mRoot.mChild[0];
      if ( v5 == (UFG::qTreeRB<UFG::qValueNodeRB<UFG::LoadedChunkFile *>,UFG::qValueNodeRB<UFG::LoadedChunkFile *>,1> *)&UFG::qChunkFileSystem::mLoadedChunkFiles.mTree.mNULL )
        return;
    }
    for ( j = (UFG::qTreeRB<UFG::qValueNodeRB<UFG::LoadedChunkFile *>,UFG::qValueNodeRB<UFG::LoadedChunkFile *>,1> *)v5->mTree.mRoot.mChild[0];
          j;
          j = (UFG::qTreeRB<UFG::qValueNodeRB<UFG::LoadedChunkFile *>,UFG::qValueNodeRB<UFG::LoadedChunkFile *>,1> *)j->mTree.mRoot.mChild[0] )
    {
      if ( j->mTree.mRoot.mUID != v2 )
        break;
      v5 = j;
    }
    if ( v5 )
    {
      v9 = (UFG::LoadedChunkFile *)v5->mTree.mNULL.mParent;
      if ( v9 )
        UFG::qChunkFileSystem::Unload(v9);
    }
  }
}

// File Line: 1307
// RVA: 0x17EEB0
void __fastcall UFG::qChunkFileSystem::Unload(UFG::LoadedChunk *loaded_chunk)
{
  UFG::LoadedChunk *v1; // rbx
  bool v2; // zf
  UFG::ResourceFile::State v3; // eax

  if ( loaded_chunk )
  {
    v1 = loaded_chunk;
    v2 = loaded_chunk->mRefs-- == 1;
    if ( v2 )
    {
      UFG::qUserCallback_WaitForGPU((UFG *)loaded_chunk);
      v3 = v1->mState;
      switch ( v3 )
      {
        case 2:
          UFG::ResourceFile::WarehouseUnload((UFG::ResourceFile *)&v1->mNode);
          UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
            (UFG::qBaseTreeVariableRB<unsigned __int64> *)&UFG::qChunkFileSystem::mLoadedChunks,
            (UFG::qBaseNodeVariableRB<unsigned __int64> *)&v1->mNode);
          --UFG::LoadedChunk::sLoadedChunkCount;
          v1->mTransactionNum = -v1->mTransactionNum;
LABEL_9:
          UFG::ResourceFile::~ResourceFile((UFG::ResourceFile *)&v1->mNode);
          UFG::qMemoryPool::Free(UFG::gMainMemoryPool, v1);
          return;
        case 1:
          v1->mState = 3;
          UFG::qFileSystem::KillAsyncOps(
            &UFG::gQuarkFileSystem,
            1,
            1,
            UFG::qChunkFileSystem::ResourceSystem_LoadedChunkCallback,
            (void *)v1->mNode.mUID,
            0i64);
          return;
        case 0:
          UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
            (UFG::qBaseTreeVariableRB<unsigned __int64> *)&UFG::qChunkFileSystem::mLoadedChunks,
            (UFG::qBaseNodeVariableRB<unsigned __int64> *)&v1->mNode);
          --UFG::LoadedChunk::sLoadedChunkCount;
          v1->mTransactionNum = -v1->mTransactionNum;
          goto LABEL_9;
      }
    }
  }
}

// File Line: 1379
// RVA: 0x17EFB0
void __fastcall UFG::qChunkFileSystem::Unload(UFG::LoadedChunkFile *chunk_file)
{
  __int64 v1; // r9
  UFG::LoadedChunkFile *v2; // rbx
  char *file; // ST28_8
  unsigned int callback_param; // ST20_4
  UFG *v5; // rcx
  bool v6; // zf
  UFG::ResourceFile::State v7; // eax
  void *v8; // ST20_8

  if ( chunk_file )
  {
    v1 = chunk_file->mNode.mUID;
    v2 = chunk_file;
    file = chunk_file->mFilename.mData;
    callback_param = chunk_file->mRefs;
    UFG::qPrintChannel::Print(
      &UFG::qChunkFileSystem::mResourceChannel,
      OUTPUT_LEVEL_DEBUG,
      "[Resource - Unload] loaded_chunk_file_uid=0x%08x refs=%4d '%s'\n");
    v6 = v2->mRefs-- == 1;
    if ( v6 )
    {
      UFG::qUserCallback_WaitForGPU(v5);
      v7 = v2->mState;
      switch ( v7 )
      {
        case 2:
          UFG::ResourceFile::WarehouseUnload((UFG::ResourceFile *)&v2->mNode);
LABEL_8:
          UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
            (UFG::qBaseTreeVariableRB<unsigned __int64> *)&UFG::qChunkFileSystem::mLoadedChunkFiles,
            (UFG::qBaseNodeVariableRB<unsigned __int64> *)&v2->mNode);
          UFG::LoadedChunkFile::~LoadedChunkFile(v2);
          UFG::qMemoryPool::Free(UFG::gMainMemoryPool, v2);
          return;
        case 1:
          v8 = (void *)v2->mNode.mUID;
          v2->mState = 3;
          UFG::qFileSystem::KillAsyncOps(
            &UFG::gQuarkFileSystem,
            1,
            1,
            UFG::qChunkFileSystem::ResourceSystem_LoadedChunkFileGetSize,
            v8,
            0i64);
          UFG::qFileSystem::KillAsyncOps(
            &UFG::gQuarkFileSystem,
            1,
            1,
            UFG::qChunkFileSystem::ResourceSystem_LoadedChunkFileCallback,
            (void *)v2->mNode.mUID,
            0i64);
          return;
        case 0:
          goto LABEL_8;
      }
    }
  }
}

// File Line: 1447
// RVA: 0x17B1B0
void __fastcall UFG::qChunkFileSystem::ResourceSystem_LoadedChunkCallback(UFG::qFileOp *file_op, void *callback_param)
{
  UFG::qFileOp *v2; // rdi
  UFG::qTreeRB<UFG::qValueNodeRB<UFG::LoadedChunk *>,UFG::qValueNodeRB<UFG::LoadedChunk *>,1> *v3; // rax
  unsigned int v4; // er8
  UFG::qTreeRB<UFG::qValueNodeRB<UFG::LoadedChunk *>,UFG::qValueNodeRB<UFG::LoadedChunk *>,1> *i; // rcx
  UFG::qBaseNodeRB *v6; // rbx
  __int64 v7; // rax
  bool v8; // zf
  __int64 v9; // rax
  UFG::qFileOp::OpType v10; // eax
  unsigned __int64 v11; // rax
  const char *v12; // rcx
  void *v13; // [rsp+28h] [rbp-20h]

  v2 = file_op;
  if ( !(_DWORD)callback_param )
    goto LABEL_15;
  v3 = &UFG::qChunkFileSystem::mLoadedChunks;
  while ( 1 )
  {
    v4 = v3->mTree.mRoot.mUID;
    if ( v3 != &UFG::qChunkFileSystem::mLoadedChunks && v4 == (_DWORD)callback_param )
      break;
    if ( (unsigned int)callback_param > v4 )
      v3 = (UFG::qTreeRB<UFG::qValueNodeRB<UFG::LoadedChunk *>,UFG::qValueNodeRB<UFG::LoadedChunk *>,1> *)v3->mTree.mRoot.mChild[1];
    else
      v3 = (UFG::qTreeRB<UFG::qValueNodeRB<UFG::LoadedChunk *>,UFG::qValueNodeRB<UFG::LoadedChunk *>,1> *)v3->mTree.mRoot.mChild[0];
    if ( v3 == (UFG::qTreeRB<UFG::qValueNodeRB<UFG::LoadedChunk *>,UFG::qValueNodeRB<UFG::LoadedChunk *>,1> *)&UFG::qChunkFileSystem::mLoadedChunks.mTree.mNULL )
      goto LABEL_15;
  }
  for ( i = (UFG::qTreeRB<UFG::qValueNodeRB<UFG::LoadedChunk *>,UFG::qValueNodeRB<UFG::LoadedChunk *>,1> *)v3->mTree.mRoot.mChild[0];
        i;
        i = (UFG::qTreeRB<UFG::qValueNodeRB<UFG::LoadedChunk *>,UFG::qValueNodeRB<UFG::LoadedChunk *>,1> *)i->mTree.mRoot.mChild[0] )
  {
    if ( i->mTree.mRoot.mUID != (_DWORD)callback_param )
      break;
    v3 = i;
  }
  if ( v3 )
    v6 = v3->mTree.mNULL.mParent;
  else
LABEL_15:
    v6 = 0i64;
  *(_DWORD *)v2->mStatus;
  v13 = v2->mBuffer;
  UFG::qPrintChannel::Print(
    &UFG::qChunkFileSystem::mResourceChannel,
    OUTPUT_LEVEL_DEBUG,
    "[Resource - LoadedChunkCallback]   %s file op uid=0x%08x to buffer %p\n");
  if ( v6 )
  {
    v7 = *(_QWORD *)&v6[4].mUID;
    if ( !v7 || *(_DWORD *)(v7 + 20) == 1 && *(_QWORD *)&v6[3].mUID )
      UFG::qVRAMemoryPools::Unlock((UFG::qVRAMemoryHandle *)v6[3].mChild);
    v8 = HIDWORD(v6[5].mChild[0])-- == 1;
    if ( v8 )
      UFG::ResourceFile::NotifyWaitingTables((UFG::ResourceFile *)v6);
    v9 = SLODWORD(v6[5].mChild[1]);
    if ( (_DWORD)v9 == 3 )
    {
      if ( !HIDWORD(v6[5].mChild[0]) )
      {
        UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
          (UFG::qBaseTreeVariableRB<unsigned __int64> *)&UFG::qChunkFileSystem::mLoadedChunks,
          (UFG::qBaseNodeVariableRB<unsigned __int64> *)&v6[6].mUID);
        --UFG::LoadedChunk::sLoadedChunkCount;
        LODWORD(v6[6].mChild[1]) = -LODWORD(v6[6].mChild[1]);
        UFG::ResourceFile::~ResourceFile((UFG::ResourceFile *)v6);
        UFG::qMemoryPool::Free(UFG::gMainMemoryPool, v6);
        UFG::qChunkFileSystem::mCheckTablesForCallbacks = 1;
        return;
      }
      goto LABEL_35;
    }
    if ( (_DWORD)v9 == 1 )
    {
      if ( *(_DWORD *)v2->mStatus == 4 )
      {
LABEL_35:
        UFG::qChunkFileSystem::mCheckTablesForCallbacks = 1;
        return;
      }
      if ( *(_DWORD *)v2->mStatus == 3 )
      {
        v10 = v2->mType;
        if ( v10 == 9 )
        {
          v11 = v2->mResult1;
        }
        else
        {
          if ( v10 != 2 )
          {
LABEL_34:
            UFG::ResourceFile::WarehouseLoad((UFG::ResourceFile *)v6);
            goto LABEL_35;
          }
          v11 = v2->mResult0;
        }
        v6[5].mParent = (UFG::qBaseNodeRB *)v11;
        goto LABEL_34;
      }
    }
    if ( (unsigned int)v9 > 3 )
      v12 = "<uknown>";
    else
      v12 = off_14203C5B0[v9];
    LODWORD(v13) = *(_DWORD *)v2->mStatus;
    UFG::qPrintf(
      0i64,
      "[qChunkFileSystem] ERROR: Unhandled async loading state! uid=0x%08x  num=%4d  chk=%s  op=%d \n",
      v6->mUID,
      LODWORD(v6[6].mChild[1]),
      v12,
      v13,
      -2i64);
  }
}d  chk=%s  op=%d \n",
      v6->mUID,
      L

// File Line: 1537
// RVA: 0x17B580
void __fastcall UFG::qChunkFileSystem::ResourceSystem_LoadedChunkFileGetSize(UFG::qFileOp *file_op, void *callback_param)
{
  void *v2; // rdi
  UFG::qFileOp *v3; // rbp
  UFG::qTreeRB<UFG::qValueNodeRB<UFG::LoadedChunkFile *>,UFG::qValueNodeRB<UFG::LoadedChunkFile *>,1> *v4; // rax
  unsigned int v5; // edx
  UFG::qBaseNodeRB *v6; // rbx
  void *v7; // ST28_8
  __int64 v8; // rbp
  unsigned int userdata32; // ST20_4
  const char *v10; // r8
  char *v11; // rax
  __int64 v12; // rcx
  char *v13; // r14
  UFG::qTreeRB<UFG::qValueNodeRB<UFG::LoadedChunkFile *>,UFG::qValueNodeRB<UFG::LoadedChunkFile *>,1> *i; // rcx
  UFG::qBaseNodeRB *v15; // ST20_8
  UFG::qBaseNodeRB *v16; // r9
  char *callback_parama; // [rsp+28h] [rbp-30h]

  v2 = callback_param;
  v3 = file_op;
  if ( !(_DWORD)callback_param )
    goto LABEL_9;
  v4 = &UFG::qChunkFileSystem::mLoadedChunkFiles;
  while ( 1 )
  {
    v5 = v4->mTree.mRoot.mUID;
    if ( v4 != &UFG::qChunkFileSystem::mLoadedChunkFiles && v5 == (_DWORD)v2 )
      break;
    if ( (unsigned int)v2 > v5 )
      v4 = (UFG::qTreeRB<UFG::qValueNodeRB<UFG::LoadedChunkFile *>,UFG::qValueNodeRB<UFG::LoadedChunkFile *>,1> *)v4->mTree.mRoot.mChild[1];
    else
      v4 = (UFG::qTreeRB<UFG::qValueNodeRB<UFG::LoadedChunkFile *>,UFG::qValueNodeRB<UFG::LoadedChunkFile *>,1> *)v4->mTree.mRoot.mChild[0];
    if ( v4 == (UFG::qTreeRB<UFG::qValueNodeRB<UFG::LoadedChunkFile *>,UFG::qValueNodeRB<UFG::LoadedChunkFile *>,1> *)&UFG::qChunkFileSystem::mLoadedChunkFiles.mTree.mNULL )
      goto LABEL_9;
  }
  for ( i = (UFG::qTreeRB<UFG::qValueNodeRB<UFG::LoadedChunkFile *>,UFG::qValueNodeRB<UFG::LoadedChunkFile *>,1> *)v4->mTree.mRoot.mChild[0];
        i;
        i = (UFG::qTreeRB<UFG::qValueNodeRB<UFG::LoadedChunkFile *>,UFG::qValueNodeRB<UFG::LoadedChunkFile *>,1> *)i->mTree.mRoot.mChild[0] )
  {
    if ( i->mTree.mRoot.mUID != (_DWORD)v2 )
      break;
    v4 = i;
  }
  if ( v4 )
    v6 = v4->mTree.mNULL.mParent;
  else
LABEL_9:
    v6 = 0i64;
  *(_DWORD *)v3->mStatus;
  v7 = (void *)v3->mResult0;
  UFG::qPrintChannel::Print(
    &UFG::qChunkFileSystem::mResourceChannel,
    OUTPUT_LEVEL_DEBUG,
    "[Resource - ResourceSystem_LoadedChunkFileGetSize]   %s file op uid=0x%08x size %u64\n");
  if ( v6 )
  {
    --HIDWORD(v6[5].mChild[0]);
    if ( *(_DWORD *)v3->mStatus == 3 )
    {
      v8 = v3->mResultNumBytesRead;
      if ( HIDWORD(v6[5].mChild[0]) )
        return;
      if ( v8 > 0 )
      {
        callback_parama = UFG::LoadedChunkFile::GetChunkFilename((UFG::LoadedChunkFile *)v6);
        userdata32 = v6->mUID;
        UFG::qPrintChannel::Print(
          &UFG::qChunkFileSystem::mResourceChannel,
          OUTPUT_LEVEL_WARNING,
          "[Resource - FileSizeCallback]     Starting read of 0x%08x64 bytes for uid:0x%08x from file '%s'\n");
        v10 = (const char *)v6[7].mChild[0];
        if ( !v10 )
          v10 = (char *)&v6[1].mChild[1] + 4;
        v11 = UFG::ResourceMemoryHandle::AllocateBuffer(
                (UFG::ResourceMemoryHandle *)v6[3].mChild,
                v8,
                v10,
                (unsigned __int64)v6->mUID << 32,
                0xE8C45525);
        v12 = *(_QWORD *)&v6[4].mUID;
        v13 = v11;
        if ( !v12 || *(_DWORD *)(v12 + 20) == 1 && *(_QWORD *)&v6[3].mUID )
          UFG::qVRAMemoryPools::Lock((UFG::qVRAMemoryHandle *)v6[3].mChild);
        UFG::qReadAsync(
          callback_parama,
          v13,
          v8,
          0i64,
          UFG::qChunkFileSystem::ResourceSystem_LoadedChunkFileCallback,
          v2,
          QPRIORITY_NORMAL);
        ++HIDWORD(v6[5].mChild[0]);
        return;
      }
      v15 = v6[7].mChild[0];
      UFG::qPrintChannel::Print(
        &UFG::qChunkFileSystem::mResourceChannel,
        OUTPUT_LEVEL_ERROR,
        "[Resource - LoadChunkFile] skipping uid=0x%08x, file '%s' does not exist or size is 0\n");
    }
    else
    {
      v16 = v6[7].mChild[0];
      UFG::qPrintChannel::Print(
        &UFG::qChunkFileSystem::mResourceChannel,
        OUTPUT_LEVEL_ERROR,
        "[Resource - LoadChunkFile] Error Getting file size for '%s'\n");
      if ( HIDWORD(v6[5].mChild[0]) )
        return;
    }
    UFG::ResourceFile::NotifyWaitingTables((UFG::ResourceFile *)v6);
    --LODWORD(v6[5].mChild[0]);
    LODWORD(v6[5].mChild[1]) = 3;
    UFG::qChunkFileSystem::mCheckTablesForCallbacks = 1;
    UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
      (UFG::qBaseTreeVariableRB<unsigned __int64> *)&UFG::qChunkFileSystem::mLoadedChunkFiles,
      (UFG::qBaseNodeVariableRB<unsigned __int64> *)&v6[7].mUID);
    UFG::LoadedChunkFile::~LoadedChunkFile((UFG::LoadedChunkFile *)v6);
    UFG::qMemoryPool::Free(UFG::gMainMemoryPool, v6);
  }
}

// File Line: 1601
// RVA: 0x17B3A0
void __fastcall UFG::qChunkFileSystem::ResourceSystem_LoadedChunkFileCallback(UFG::qFileOp *file_op, void *callback_param)
{
  UFG::qFileOp *v2; // rdi
  UFG::qTreeRB<UFG::qValueNodeRB<UFG::LoadedChunkFile *>,UFG::qValueNodeRB<UFG::LoadedChunkFile *>,1> *v3; // rax
  unsigned int v4; // er8
  UFG::qBaseNodeRB *v5; // rbx
  void *v6; // ST28_8
  __int64 v7; // rax
  bool v8; // zf
  __int64 v9; // rax
  UFG::qTreeRB<UFG::qValueNodeRB<UFG::LoadedChunkFile *>,UFG::qValueNodeRB<UFG::LoadedChunkFile *>,1> *i; // rcx
  char *v11; // rcx
  __int64 v12; // r9
  int v13; // ST28_4

  v2 = file_op;
  if ( !(_DWORD)callback_param )
    goto LABEL_9;
  v3 = &UFG::qChunkFileSystem::mLoadedChunkFiles;
  while ( 1 )
  {
    v4 = v3->mTree.mRoot.mUID;
    if ( v3 != &UFG::qChunkFileSystem::mLoadedChunkFiles && v4 == (_DWORD)callback_param )
      break;
    if ( (unsigned int)callback_param > v4 )
      v3 = (UFG::qTreeRB<UFG::qValueNodeRB<UFG::LoadedChunkFile *>,UFG::qValueNodeRB<UFG::LoadedChunkFile *>,1> *)v3->mTree.mRoot.mChild[1];
    else
      v3 = (UFG::qTreeRB<UFG::qValueNodeRB<UFG::LoadedChunkFile *>,UFG::qValueNodeRB<UFG::LoadedChunkFile *>,1> *)v3->mTree.mRoot.mChild[0];
    if ( v3 == (UFG::qTreeRB<UFG::qValueNodeRB<UFG::LoadedChunkFile *>,UFG::qValueNodeRB<UFG::LoadedChunkFile *>,1> *)&UFG::qChunkFileSystem::mLoadedChunkFiles.mTree.mNULL )
      goto LABEL_9;
  }
  for ( i = (UFG::qTreeRB<UFG::qValueNodeRB<UFG::LoadedChunkFile *>,UFG::qValueNodeRB<UFG::LoadedChunkFile *>,1> *)v3->mTree.mRoot.mChild[0];
        i;
        i = (UFG::qTreeRB<UFG::qValueNodeRB<UFG::LoadedChunkFile *>,UFG::qValueNodeRB<UFG::LoadedChunkFile *>,1> *)i->mTree.mRoot.mChild[0] )
  {
    if ( i->mTree.mRoot.mUID != (_DWORD)callback_param )
      break;
    v3 = i;
  }
  if ( v3 )
    v5 = v3->mTree.mNULL.mParent;
  else
LABEL_9:
    v5 = 0i64;
  *(_DWORD *)v2->mStatus;
  v6 = v2->mBuffer;
  UFG::qPrintChannel::Print(
    &UFG::qChunkFileSystem::mResourceChannel,
    OUTPUT_LEVEL_DEBUG,
    "[Resource - LoadedChunkFileCallback]   %s file op uid=0x%08x to buffer %p\n");
  if ( v5 )
  {
    v7 = *(_QWORD *)&v5[4].mUID;
    if ( !v7 || *(_DWORD *)(v7 + 20) == 1 && *(_QWORD *)&v5[3].mUID )
      UFG::qVRAMemoryPools::Unlock((UFG::qVRAMemoryHandle *)v5[3].mChild);
    v8 = HIDWORD(v5[5].mChild[0])-- == 1;
    if ( v8 )
      UFG::ResourceFile::NotifyWaitingTables((UFG::ResourceFile *)v5);
    v9 = SLODWORD(v5[5].mChild[1]);
    if ( (_DWORD)v9 == 3 )
    {
      if ( !HIDWORD(v5[5].mChild[0]) )
      {
        UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
          (UFG::qBaseTreeVariableRB<unsigned __int64> *)&UFG::qChunkFileSystem::mLoadedChunkFiles,
          (UFG::qBaseNodeVariableRB<unsigned __int64> *)&v5[7].mUID);
        UFG::LoadedChunkFile::~LoadedChunkFile((UFG::LoadedChunkFile *)v5);
        UFG::qMemoryPool::Free(UFG::gMainMemoryPool, v5);
        UFG::qChunkFileSystem::mCheckTablesForCallbacks = 1;
        return;
      }
      goto LABEL_29;
    }
    if ( (_DWORD)v9 == 1 )
    {
      if ( *(_DWORD *)v2->mStatus == 4 )
      {
LABEL_29:
        UFG::qChunkFileSystem::mCheckTablesForCallbacks = 1;
        return;
      }
      if ( *(_DWORD *)v2->mStatus == 3 )
      {
        v5[5].mParent = (UFG::qBaseNodeRB *)v2->mResult0;
        UFG::ResourceFile::WarehouseLoad((UFG::ResourceFile *)v5);
        goto LABEL_29;
      }
    }
    if ( (unsigned int)v9 <= 3 )
      v11 = off_14203C5B0[v9];
    v12 = v5->mUID;
    v13 = *(_DWORD *)v2->mStatus;
    UFG::qPrintChannel::Print(
      &UFG::qChunkFileSystem::mResourceChannel,
      OUTPUT_LEVEL_ERROR,
      "[qChunkFileSystem] ERROR: Unhandled async loading state! uid=0x%08x  chk=%s  op=%d \n");
  }
}

// File Line: 1712
// RVA: 0x17AF90
_BOOL8 __fastcall UFG::qChunkFileSystem::ResourceSystem_CheckForUnusedFileHandles(bool header_printed)
{
  bool v1; // si
  UFG::qTreeRB<UFG::ResourceFileHandle,UFG::ResourceFileHandle,1> *v2; // rdx
  UFG::qTreeRB<UFG::ResourceFileHandle,UFG::ResourceFileHandle,1> *v3; // r8
  UFG::qTreeRB<UFG::ResourceFileHandle,UFG::ResourceFileHandle,1> *i; // rax
  UFG::qTreeRB<UFG::ResourceFileHandle,UFG::ResourceFileHandle,1> *v5; // rax
  UFG::qTreeRB<UFG::ResourceFileHandle,UFG::ResourceFileHandle,1> *j; // rax
  UFG::qTreeRB<UFG::ResourceFileHandle,UFG::ResourceFileHandle,1> *v7; // rbx
  UFG::qBaseNodeRB *v8; // rax
  UFG::qTreeRB<UFG::ResourceFileHandle,UFG::ResourceFileHandle,1> *v9; // rcx
  UFG::qTreeRB<UFG::ResourceFileHandle,UFG::ResourceFileHandle,1> *l; // rax
  UFG::qTreeRB<UFG::ResourceFileHandle,UFG::ResourceFileHandle,1> *v11; // rax
  UFG::qTreeRB<UFG::ResourceFileHandle,UFG::ResourceFileHandle,1> *v12; // rcx
  char v13; // al
  __int64 v14; // ST20_8
  __int64 v15; // r9
  UFG::qFile *v16; // rcx
  UFG::qBaseNodeRB *v17; // rdi
  char *v18; // rdx
  UFG::qBaseNodeRB *v19; // rcx
  UFG::qBaseNodeRB *v20; // rax
  UFG::qTreeRB<UFG::ResourceFileHandle,UFG::ResourceFileHandle,1> *v21; // rcx
  UFG::qTreeRB<UFG::ResourceFileHandle,UFG::ResourceFileHandle,1> *k; // rax
  UFG::qTreeRB<UFG::ResourceFileHandle,UFG::ResourceFileHandle,1> *v23; // rax

  v1 = header_printed;
  v2 = (UFG::qTreeRB<UFG::ResourceFileHandle,UFG::ResourceFileHandle,1> *)UFG::qChunkFileSystem::mFileHandles.mTree.mRoot.mChild[0];
  v3 = (UFG::qTreeRB<UFG::ResourceFileHandle,UFG::ResourceFileHandle,1> *)UFG::qChunkFileSystem::mFileHandles.mTree.mRoot.mChild[0];
  for ( i = (UFG::qTreeRB<UFG::ResourceFileHandle,UFG::ResourceFileHandle,1> *)UFG::qChunkFileSystem::mFileHandles.mTree.mRoot.mChild[0]->mChild[0];
        i != (UFG::qTreeRB<UFG::ResourceFileHandle,UFG::ResourceFileHandle,1> *)&UFG::qChunkFileSystem::mFileHandles.mTree.mNULL;
        i = (UFG::qTreeRB<UFG::ResourceFileHandle,UFG::ResourceFileHandle,1> *)i->mTree.mRoot.mChild[0] )
  {
    v3 = i;
  }
  v5 = 0i64;
  if ( v3 != (UFG::qTreeRB<UFG::ResourceFileHandle,UFG::ResourceFileHandle,1> *)&UFG::qChunkFileSystem::mFileHandles.mTree.mNULL )
    v5 = v3;
  if ( v5 )
  {
LABEL_6:
    for ( j = (UFG::qTreeRB<UFG::ResourceFileHandle,UFG::ResourceFileHandle,1> *)v2->mTree.mRoot.mChild[0];
          j != (UFG::qTreeRB<UFG::ResourceFileHandle,UFG::ResourceFileHandle,1> *)&UFG::qChunkFileSystem::mFileHandles.mTree.mNULL;
          j = (UFG::qTreeRB<UFG::ResourceFileHandle,UFG::ResourceFileHandle,1> *)j->mTree.mRoot.mChild[0] )
    {
      v2 = j;
    }
    v7 = 0i64;
    if ( v2 != (UFG::qTreeRB<UFG::ResourceFileHandle,UFG::ResourceFileHandle,1> *)&UFG::qChunkFileSystem::mFileHandles.mTree.mNULL )
      v7 = v2;
    while ( v7 )
    {
      v8 = v7[1].mTree.mRoot.mParent;
      if ( !v8 || !LODWORD(v8[4].mChild[1]) )
      {
        v13 = v1;
        if ( !v1 )
          v13 = 1;
        v1 = v13;
        v14 = *(_QWORD *)&v7->mTree.mNULL.mUID;
        v15 = v7->mTree.mRoot.mUID;
        UFG::qPrintChannel::Print(
          &UFG::qChunkFileSystem::mResourceChannel,
          OUTPUT_LEVEL_WARNING,
          "[Resource - Service]       Closing unused file handle uid:0x%08x '%s'\n");
        UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
          (UFG::qBaseTreeVariableRB<unsigned __int64> *)&UFG::qChunkFileSystem::mFileHandles,
          (UFG::qBaseNodeVariableRB<unsigned __int64> *)v7);
        v16 = (UFG::qFile *)v7[1].mTree.mRoot.mParent;
        if ( v16 )
        {
          UFG::qCloseAsync(v16, 0i64, 0i64, QPRIORITY_NORMAL);
          v7[1].mTree.mRoot.mParent = 0i64;
        }
        v17 = &v7->mTree.mNULL;
        v18 = *(char **)&v7->mTree.mNULL.mUID;
        if ( v18 != UFG::qString::sEmptyString && v18 )
          UFG::qMemoryPool::Free(UFG::gMainMemoryPool, v18);
        LODWORD(v7->mTree.mNULL.mChild[1]) = 0;
        v19 = v17->mParent;
        v20 = v7->mTree.mNULL.mChild[0];
        v19->mChild[0] = v20;
        v20->mParent = v19;
        v17->mParent = v17;
        v7->mTree.mNULL.mChild[0] = &v7->mTree.mNULL;
        UFG::qMemoryPool::Free(UFG::gMainMemoryPool, v7);
        if ( UFG::qChunkFileSystem::mFileHandles.mTree.mCount )
        {
          v2 = (UFG::qTreeRB<UFG::ResourceFileHandle,UFG::ResourceFileHandle,1> *)UFG::qChunkFileSystem::mFileHandles.mTree.mRoot.mChild[0];
          v21 = (UFG::qTreeRB<UFG::ResourceFileHandle,UFG::ResourceFileHandle,1> *)UFG::qChunkFileSystem::mFileHandles.mTree.mRoot.mChild[0];
          for ( k = (UFG::qTreeRB<UFG::ResourceFileHandle,UFG::ResourceFileHandle,1> *)UFG::qChunkFileSystem::mFileHandles.mTree.mRoot.mChild[0]->mChild[0];
                k != (UFG::qTreeRB<UFG::ResourceFileHandle,UFG::ResourceFileHandle,1> *)&UFG::qChunkFileSystem::mFileHandles.mTree.mNULL;
                k = (UFG::qTreeRB<UFG::ResourceFileHandle,UFG::ResourceFileHandle,1> *)k->mTree.mRoot.mChild[0] )
          {
            v21 = k;
          }
          v23 = 0i64;
          if ( v21 != (UFG::qTreeRB<UFG::ResourceFileHandle,UFG::ResourceFileHandle,1> *)&UFG::qChunkFileSystem::mFileHandles.mTree.mNULL )
            v23 = v21;
          if ( v23 )
            goto LABEL_6;
        }
        return v1;
      }
      v9 = (UFG::qTreeRB<UFG::ResourceFileHandle,UFG::ResourceFileHandle,1> *)v7->mTree.mRoot.mChild[1];
      if ( &UFG::qChunkFileSystem::mFileHandles.mTree.mNULL == (UFG::qBaseNodeRB *)v9 )
      {
        v11 = (UFG::qTreeRB<UFG::ResourceFileHandle,UFG::ResourceFileHandle,1> *)((_QWORD)v7->mTree.mRoot.mParent & 0xFFFFFFFFFFFFFFFEui64);
        if ( v7 == (UFG::qTreeRB<UFG::ResourceFileHandle,UFG::ResourceFileHandle,1> *)v11->mTree.mRoot.mChild[1] )
        {
          do
          {
            v12 = v11;
            v11 = (UFG::qTreeRB<UFG::ResourceFileHandle,UFG::ResourceFileHandle,1> *)((_QWORD)v11->mTree.mRoot.mParent & 0xFFFFFFFFFFFFFFFEui64);
          }
          while ( v12 == (UFG::qTreeRB<UFG::ResourceFileHandle,UFG::ResourceFileHandle,1> *)v11->mTree.mRoot.mChild[1] );
        }
        v7 = v11;
        if ( v11 == &UFG::qChunkFileSystem::mFileHandles )
          v7 = 0i64;
      }
      else
      {
        for ( l = (UFG::qTreeRB<UFG::ResourceFileHandle,UFG::ResourceFileHandle,1> *)v9->mTree.mRoot.mChild[0];
              l != (UFG::qTreeRB<UFG::ResourceFileHandle,UFG::ResourceFileHandle,1> *)&UFG::qChunkFileSystem::mFileHandles.mTree.mNULL;
              l = (UFG::qTreeRB<UFG::ResourceFileHandle,UFG::ResourceFileHandle,1> *)l->mTree.mRoot.mChild[0] )
        {
          v9 = l;
        }
        v7 = v9;
      }
    }
  }
  return v1;
}

// File Line: 1747
// RVA: 0x17AE60
_BOOL8 __fastcall UFG::qChunkFileSystem::ResourceSystem_CheckForFinishedLoadTables(bool header_printed)
{
  bool v1; // si
  UFG::qNode<UFG::ResourceLoadTable,UFG::ResourceLoadTable> *v2; // rbx
  UFG::qList<UFG::ResourceLoadTable,UFG::ResourceLoadTable,1,0> *v3; // rdi
  UFG::qNode<UFG::ResourceLoadTable,UFG::ResourceLoadTable> *v4; // rcx
  UFG::qNode<UFG::ResourceLoadTable,UFG::ResourceLoadTable> *v5; // rax
  __int64 v6; // r9
  char v7; // al
  UFG::qNode<UFG::ResourceLoadTable,UFG::ResourceLoadTable> *v8; // rax

  v1 = header_printed;
  if ( UFG::qChunkFileSystem::mCheckTablesForCallbacks == 1 )
  {
    v2 = UFG::qChunkFileSystem::mLoadTablesLoading.mNode.mNext;
    if ( (UFG::qList<UFG::ResourceLoadTable,UFG::ResourceLoadTable,1,0> *)UFG::qChunkFileSystem::mLoadTablesLoading.mNode.mNext != &UFG::qChunkFileSystem::mLoadTablesLoading )
    {
      do
      {
        v3 = (UFG::qList<UFG::ResourceLoadTable,UFG::ResourceLoadTable,1,0> *)v2->mNext;
        if ( !LODWORD(v2[5].mNext) )
        {
          v4 = v2->mPrev;
          v5 = v2->mNext;
          v4->mNext = v5;
          v5->mPrev = v4;
          v6 = HIDWORD(v2[5].mNext);
          v7 = v1;
          v2->mPrev = v2;
          v2->mNext = v2;
          if ( !v1 )
            v7 = 1;
          v1 = v7;
          if ( LODWORD(v2[3].mPrev) == 3 )
          {
            UFG::qPrintChannel::Print(
              &UFG::qChunkFileSystem::mResourceChannel,
              OUTPUT_LEVEL_WARNING,
              "[Resource - Service]       Scheduling cancel callback on load table uid:0x%08x at %p\n");
            LODWORD(v2[3].mPrev) = 5;
          }
          else
          {
            UFG::qPrintChannel::Print(
              &UFG::qChunkFileSystem::mResourceChannel,
              OUTPUT_LEVEL_WARNING,
              "[Resource - Service]       Scheduling complete callback on load table uid:0x%08x at %p\n");
            LODWORD(v2[3].mPrev) = 4;
          }
          v8 = UFG::qChunkFileSystem::mLoadTablesCallback.mNode.mPrev;
          UFG::qChunkFileSystem::mLoadTablesCallback.mNode.mPrev->mNext = v2;
          v2->mPrev = v8;
          v2->mNext = (UFG::qNode<UFG::ResourceLoadTable,UFG::ResourceLoadTable> *)&UFG::qChunkFileSystem::mLoadTablesCallback;
          UFG::qChunkFileSystem::mLoadTablesCallback.mNode.mPrev = v2;
        }
        v2 = &v3->mNode;
      }
      while ( v3 != &UFG::qChunkFileSystem::mLoadTablesLoading );
    }
    UFG::qChunkFileSystem::mCheckTablesForCallbacks = 0;
  }
  return v1;
}

// File Line: 1799
// RVA: 0x17B7F0
__int64 __fastcall UFG::qChunkFileSystem::ResourceSystem_MakeLoadTableCallbacks(bool header_printed)
{
  bool v1; // dl
  UFG::qNode<UFG::ResourceLoadTable,UFG::ResourceLoadTable> *v2; // rbx
  UFG::qNode<UFG::ResourceLoadTable,UFG::ResourceLoadTable> *v3; // rcx
  UFG::qNode<UFG::ResourceLoadTable,UFG::ResourceLoadTable> *v4; // rax
  char v5; // al
  __int64 v6; // r9
  UFG::qNode<UFG::ResourceLoadTable,UFG::ResourceLoadTable> *v7; // rsi
  UFG::qNode<UFG::ResourceLoadTable,UFG::ResourceLoadTable> *v8; // r15
  UFG::qNode<UFG::ResourceLoadTable,UFG::ResourceLoadTable> *v9; // r14
  bool v10; // bp
  unsigned int v11; // edi
  UFG::qNode<UFG::ResourceLoadTable,UFG::ResourceLoadTable> *v12; // r12
  unsigned int v13; // er13
  UFG::qNode<UFG::ResourceLoadTable,UFG::ResourceLoadTable> *v14; // rax
  UFG::qNode<UFG::ResourceLoadTable,UFG::ResourceLoadTable> *v15; // rdx
  const char *v16; // rdx
  const char *v17; // rcx
  char v18; // al
  int v19; // ecx
  UFG::qNode<UFG::ResourceLoadTable,UFG::ResourceLoadTable> *v20; // rax
  int lengthb; // ST20_4
  UFG::qTreeRB<UFG::ResourceLoadTable,UFG::ResourceLoadTable,1> *v22; // rcx
  UFG::qMemoryPool *v23; // rdi
  UFG::qMemoryPool *v24; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *v25; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *v26; // rax
  UFG::qString v28; // [rsp+38h] [rbp-60h]
  unsigned __int8 v29; // [rsp+A0h] [rbp+8h]
  unsigned int v30; // [rsp+A8h] [rbp+10h]

  v1 = header_printed;
  v2 = UFG::qChunkFileSystem::mLoadTablesCallback.mNode.mNext;
  if ( (UFG::qList<UFG::ResourceLoadTable,UFG::ResourceLoadTable,1,0> *)UFG::qChunkFileSystem::mLoadTablesCallback.mNode.mNext == &UFG::qChunkFileSystem::mLoadTablesCallback )
    return header_printed;
  while ( 1 )
  {
    v3 = v2->mPrev;
    v4 = v2->mNext;
    v3->mNext = v4;
    v4->mPrev = v3;
    v2->mPrev = v2;
    v2->mNext = v2;
    v5 = v1;
    if ( !v1 )
      v5 = 1;
    v29 = v5;
    v6 = HIDWORD(v2[5].mNext);
    UFG::qPrintChannel::Print(
      &UFG::qChunkFileSystem::mResourceChannel,
      OUTPUT_LEVEL_WARNING,
      "[Resource - Service]       Invoking Callback on table uid:0x%08x at %p\n");
    v7 = 0i64;
    v8 = 0i64;
    v9 = 0i64;
    v10 = LODWORD(v2[3].mPrev) == 4;
    v11 = HIDWORD(v2[5].mNext);
    v30 = HIDWORD(v2[5].mNext);
    v12 = v2[4].mPrev;
    v28.mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&v28;
    v28.mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&v28;
    *(_QWORD *)&v28.mMagic = 16909060i64;
    v28.mData = (char *)UFG::qString::sEmptyString;
    *(_QWORD *)&v28.mStringHash32 = -1i64;
    v13 = 0;
    if ( LODWORD(v2[6].mPrev) == -1 )
    {
      v9 = v2[3].mNext;
    }
    else
    {
      v14 = v2[5].mPrev;
      v15 = v14[2].mNext;
      if ( v15 && HIDWORD(v15[1].mPrev) )
      {
        v16 = (const char *)v15[1].mNext;
        if ( v16 && v16 != UFG::qString::sEmptyString )
        {
          v17 = v16;
          do
            v18 = *v17++;
          while ( v18 );
          v19 = (_DWORD)v17 - (_DWORD)v16 - 1;
        }
        else
        {
          v19 = 0;
        }
        UFG::qString::Set(&v28, v16, v19, 0i64, 0);
        v7 = v2[3].mNext;
      }
      else
      {
        v13 = (unsigned int)v14[3].mPrev;
        v8 = v2[3].mNext;
      }
    }
    if ( v10 == 1 )
    {
      LODWORD(v2[3].mPrev) = 7;
      v20 = UFG::qChunkFileSystem::mLoadTablesLoaded.mNode.mPrev;
      UFG::qChunkFileSystem::mLoadTablesLoaded.mNode.mPrev->mNext = v2;
      v2->mPrev = v20;
      v2->mNext = (UFG::qNode<UFG::ResourceLoadTable,UFG::ResourceLoadTable> *)&UFG::qChunkFileSystem::mLoadTablesLoaded;
      UFG::qChunkFileSystem::mLoadTablesLoaded.mNode.mPrev = v2;
    }
    else
    {
      LODWORD(v2[3].mPrev) = 0;
      lengthb = HIDWORD(v2[5].mNext);
      UFG::qPrintChannel::Print(
        &UFG::qChunkFileSystem::mResourceChannel,
        OUTPUT_LEVEL_DEBUG,
        "[Resource - Internal_Destroy] tab=%p uid=0x%08x  state=%d\n");
      v22 = &UFG::qChunkFileSystem::mSingleFileLoadTables;
      if ( LODWORD(v2[6].mPrev) == -1 )
        v22 = &UFG::qChunkFileSystem::mCreatedLoadTables;
      UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
        (UFG::qBaseTreeVariableRB<unsigned __int64> *)v22,
        (UFG::qBaseNodeVariableRB<unsigned __int64> *)&v2[1]);
      v23 = (UFG::qMemoryPool *)v2[6].mNext;
      UFG::ResourceLoadTable::~ResourceLoadTable((UFG::ResourceLoadTable *)v2);
      v24 = UFG::gMainMemoryPool;
      if ( v23 )
        v24 = v23;
      UFG::qMemoryPool::Free(v24, v2);
      v11 = v30;
    }
    if ( v7 )
    {
      ((void (__fastcall *)(char *, bool, UFG::qNode<UFG::ResourceLoadTable,UFG::ResourceLoadTable> *))v7)(
        v28.mData,
        v10,
        v12);
    }
    else if ( v8 )
    {
      ((void (__fastcall *)(_QWORD, bool, UFG::qNode<UFG::ResourceLoadTable,UFG::ResourceLoadTable> *))v8)(
        v13,
        v10,
        v12);
    }
    else if ( v9 )
    {
      ((void (__fastcall *)(_QWORD, bool, UFG::qNode<UFG::ResourceLoadTable,UFG::ResourceLoadTable> *))v9)(
        v11,
        v10,
        v12);
    }
    if ( v28.mData != UFG::qString::sEmptyString )
    {
      if ( v28.mData )
        UFG::qMemoryPool::Free(UFG::gMainMemoryPool, v28.mData);
    }
    v28.mMagic = 0;
    v25 = v28.mPrev;
    v26 = v28.mNext;
    v28.mPrev->mNext = v28.mNext;
    v26->mPrev = v25;
    v28.mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&v28;
    v28.mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&v28;
    v2 = UFG::qChunkFileSystem::mLoadTablesCallback.mNode.mNext;
    if ( (UFG::qList<UFG::ResourceLoadTable,UFG::ResourceLoadTable,1,0> *)UFG::qChunkFileSystem::mLoadTablesCallback.mNode.mNext == &UFG::qChunkFileSystem::mLoadTablesCallback )
      break;
    v1 = v29;
  }
  return v29;
}

// File Line: 1892
// RVA: 0x1745A0
void __fastcall UFG::qChunkFileSystem::Internal_Load(UFG::ResourceLoadTable *load_table)
{
  UFG::ResourceLoadTable *v1; // r12
  UFG::ResourceLoadTable::State read_offset; // ST28_4
  unsigned int check_null; // ST20_4
  __int64 v4; // r13
  signed __int64 v5; // rdx
  unsigned int v6; // ebx
  UFG::qTreeRB<UFG::qValueNodeRB<UFG::LoadedChunk *>,UFG::qValueNodeRB<UFG::LoadedChunk *>,1> *v7; // rax
  unsigned int v8; // ecx
  UFG::qTreeRB<UFG::qValueNodeRB<UFG::LoadedChunk *>,UFG::qValueNodeRB<UFG::LoadedChunk *>,1> *i; // rcx
  UFG::qBaseNodeRB *v10; // rbp
  UFG::qList<UFG::LoadedIndexFile,UFG::LoadedIndexFile,1,0> *v11; // r15
  UFG::qChunkFileIndexEntry *v12; // rdi
  UFG::qNode<UFG::LoadedIndexFile,UFG::LoadedIndexFile> *v13; // rax
  UFG::qNode<UFG::LoadedIndexFile,UFG::LoadedIndexFile> *v14; // rcx
  signed __int64 v15; // r10
  int v16; // er8
  int v17; // er9
  int v18; // er8
  __int64 v19; // rax
  unsigned int v20; // ecx
  unsigned int v21; // ecx
  unsigned int v22; // eax
  unsigned int v23; // edx
  bool v24; // dl
  unsigned int v25; // esi
  UFG::qMemoryPool *v26; // rcx
  UFG::allocator::free_link *v27; // rax
  UFG::qBaseNodeRB *v28; // rax
  __int64 v29; // rdx
  UFG::qTreeRB<UFG::qValueNodeRB<UFG::LoadedChunkFile *>,UFG::qValueNodeRB<UFG::LoadedChunkFile *>,1> *v30; // rax
  unsigned int v31; // ecx
  UFG::qTreeRB<UFG::qValueNodeRB<UFG::LoadedChunkFile *>,UFG::qValueNodeRB<UFG::LoadedChunkFile *>,1> *j; // rcx
  UFG::qBaseNodeRB *v33; // rdi
  unsigned int v34; // edi
  UFG::ResourceFileContentType v35; // ecx
  UFG::qMemoryPool *v36; // rcx
  UFG::allocator::free_link *v37; // rax
  UFG::qBaseNodeRB *v38; // rax
  int v39; // eax
  char *v40; // rax
  __int64 v41; // rax
  __int64 v42; // rcx
  int v43; // eax
  UFG::qTreeRB<UFG::ResourceFileHandle,UFG::ResourceFileHandle,1> *v44; // r14
  char *v45; // rax
  UFG::qTreeRB<UFG::ResourceFileHandle,UFG::ResourceFileHandle,1> *v46; // rax
  bool v47; // cl
  __int64 v48; // rax
  __int64 v49; // r15
  unsigned int v50; // ecx
  __int64 v51; // r12
  __int64 v52; // rsi
  int v53; // eax
  unsigned int v54; // edx
  bool v55; // bl
  UFG::ResourceMemoryHandle *v56; // r13
  __int64 v57; // rax
  unsigned int v58; // ST28_4
  UFG::ResourceMemoryHandle *v59; // rcx
  bool v60; // zf
  void *callback_param; // rbx
  __int64 scratch_size; // rbp
  void *scratch_buffer; // r14
  __int64 v64; // r15
  char *v65; // rax
  __int64 v66; // rbp
  char *v67; // rax
  void *v68; // rbx
  char *v69; // rax
  UFG::ResourceMemoryHandle *v70; // rcx
  __int64 v71; // rbx
  void *v72; // rdi
  __int64 v73; // rsi
  char *v74; // rax
  __int64 v75; // rax
  __int64 v76; // rdi
  __int64 v77; // r15
  char *v78; // rsi
  signed __int64 v79; // rbx
  char *v80; // rax
  __int64 v81; // rax
  UFG::qNode<UFG::LoadedIndexFile,UFG::LoadedIndexFile> *v82; // r8
  __int64 v83; // rcx
  char *v84; // rdx
  char *v85; // rcx
  int read_bytes; // ST30_4
  unsigned int v87; // ST28_4
  UFG::qNode<UFG::ResourceLoadTable,UFG::ResourceLoadTable> *v88; // rax
  UFG::qNode<UFG::ResourceLoadTable,UFG::ResourceLoadTable> *v89; // rax
  UFG::qNode<UFG::ResourceLoadTable,UFG::ResourceLoadTable> *v90; // rax
  signed __int64 v91; // [rsp+70h] [rbp-78h]
  UFG::qTreeRB<UFG::ResourceFileHandle,UFG::ResourceFileHandle,1> *v92; // [rsp+80h] [rbp-68h]
  unsigned __int64 seek_offset; // [rsp+88h] [rbp-60h]
  UFG::ResourceLoadTable *load_tablea; // [rsp+F0h] [rbp+8h]
  UFG::LoadedIndexFile *out_index_file; // [rsp+F8h] [rbp+10h]
  UFG::qChunkFileIndexEntry *out_chunk_file_index; // [rsp+100h] [rbp+18h]
  __int64 v97; // [rsp+108h] [rbp+20h]

  load_tablea = load_table;
  v1 = load_table;
  read_offset = load_table->mState;
  check_null = load_table->mTableUID;
  UFG::qPrintChannel::Print(
    &UFG::qChunkFileSystem::mResourceChannel,
    OUTPUT_LEVEL_DEBUG,
    "[Resource - Internal_Load] tab=%p uid=0x%08x  state=%d\n");
  v1->mState = 1;
  v4 = (__int64)v1->mTableEntries.mNode.mNext;
  v97 = v4;
  v5 = (signed __int64)&v1->mTableEntries;
  v91 = (signed __int64)&v1->mTableEntries;
  if ( (UFG::qList<UFG::LoadTableEntry,UFG::LoadTableEntry,1,0> *)v4 != &v1->mTableEntries )
  {
    while ( 1 )
    {
      v6 = *(_DWORD *)(v4 + 48);
      if ( v6 != -1 )
      {
        if ( !v6 )
          goto LABEL_17;
        v7 = &UFG::qChunkFileSystem::mLoadedChunks;
        while ( 1 )
        {
          v8 = v7->mTree.mRoot.mUID;
          if ( v7 != &UFG::qChunkFileSystem::mLoadedChunks && v8 == v6 )
            break;
          if ( v6 > v8 )
            v7 = (UFG::qTreeRB<UFG::qValueNodeRB<UFG::LoadedChunk *>,UFG::qValueNodeRB<UFG::LoadedChunk *>,1> *)v7->mTree.mRoot.mChild[1];
          else
            v7 = (UFG::qTreeRB<UFG::qValueNodeRB<UFG::LoadedChunk *>,UFG::qValueNodeRB<UFG::LoadedChunk *>,1> *)v7->mTree.mRoot.mChild[0];
          if ( v7 == (UFG::qTreeRB<UFG::qValueNodeRB<UFG::LoadedChunk *>,UFG::qValueNodeRB<UFG::LoadedChunk *>,1> *)&UFG::qChunkFileSystem::mLoadedChunks.mTree.mNULL )
            goto LABEL_17;
        }
        for ( i = (UFG::qTreeRB<UFG::qValueNodeRB<UFG::LoadedChunk *>,UFG::qValueNodeRB<UFG::LoadedChunk *>,1> *)v7->mTree.mRoot.mChild[0];
              i;
              i = (UFG::qTreeRB<UFG::qValueNodeRB<UFG::LoadedChunk *>,UFG::qValueNodeRB<UFG::LoadedChunk *>,1> *)i->mTree.mRoot.mChild[0] )
        {
          if ( i->mTree.mRoot.mUID != v6 )
            break;
          v7 = i;
        }
        if ( v7 )
          v10 = v7->mTree.mNULL.mParent;
        else
LABEL_17:
          v10 = 0i64;
        v11 = 0i64;
        out_index_file = 0i64;
        v12 = 0i64;
        out_chunk_file_index = 0i64;
        if ( !v10 )
        {
          v11 = (UFG::qList<UFG::LoadedIndexFile,UFG::LoadedIndexFile,1,0> *)UFG::qChunkFileSystem::mLoadedIndexFiles.mNode.mNext;
          if ( (UFG::qList<UFG::LoadedIndexFile,UFG::LoadedIndexFile,1,0> *)UFG::qChunkFileSystem::mLoadedIndexFiles.mNode.mNext == &UFG::qChunkFileSystem::mLoadedIndexFiles )
          {
LABEL_60:
            v29 = *(_QWORD *)(v4 + 40);
            if ( !v29 || !*(_DWORD *)(v29 + 20) )
              goto LABEL_94;
            if ( !v6 )
              goto LABEL_76;
            v30 = &UFG::qChunkFileSystem::mLoadedChunkFiles;
            while ( 1 )
            {
              v31 = v30->mTree.mRoot.mUID;
              if ( v30 != &UFG::qChunkFileSystem::mLoadedChunkFiles && v31 == v6 )
                break;
              if ( v6 > v31 )
                v30 = (UFG::qTreeRB<UFG::qValueNodeRB<UFG::LoadedChunkFile *>,UFG::qValueNodeRB<UFG::LoadedChunkFile *>,1> *)v30->mTree.mRoot.mChild[1];
              else
                v30 = (UFG::qTreeRB<UFG::qValueNodeRB<UFG::LoadedChunkFile *>,UFG::qValueNodeRB<UFG::LoadedChunkFile *>,1> *)v30->mTree.mRoot.mChild[0];
              if ( v30 == (UFG::qTreeRB<UFG::qValueNodeRB<UFG::LoadedChunkFile *>,UFG::qValueNodeRB<UFG::LoadedChunkFile *>,1> *)&UFG::qChunkFileSystem::mLoadedChunkFiles.mTree.mNULL )
                goto LABEL_76;
            }
            for ( j = (UFG::qTreeRB<UFG::qValueNodeRB<UFG::LoadedChunkFile *>,UFG::qValueNodeRB<UFG::LoadedChunkFile *>,1> *)v30->mTree.mRoot.mChild[0];
                  j;
                  j = (UFG::qTreeRB<UFG::qValueNodeRB<UFG::LoadedChunkFile *>,UFG::qValueNodeRB<UFG::LoadedChunkFile *>,1> *)j->mTree.mRoot.mChild[0] )
            {
              if ( j->mTree.mRoot.mUID != v6 )
                break;
              v30 = j;
            }
            if ( v30 )
            {
              v33 = v30->mTree.mNULL.mParent;
            }
            else
            {
LABEL_76:
              v34 = v6;
              v35 = *(_DWORD *)(v4 + 52);
              if ( v35 )
                v34 = UFG::GenerateResourceFileUID(v35, *(const char **)(v29 + 24));
              v36 = UFG::gMainMemoryPool;
              if ( !UFG::gMainMemoryPool )
              {
                UFG::InternalSetupMainMemoryPool((UFG *)UFG::gMainMemoryPool);
                v36 = UFG::gMainMemoryPool;
              }
              v37 = UFG::qMemoryPool::Allocate(v36, 0x128ui64, "ResourceFileSystem.LoadedChunkFile", 0i64, 1u);
              out_index_file = (UFG::LoadedIndexFile *)v37;
              if ( v37 )
              {
                UFG::LoadedChunkFile::LoadedChunkFile(
                  (UFG::LoadedChunkFile *)v37,
                  v6,
                  v34,
                  *(const char **)(*(_QWORD *)(v4 + 40) + 24i64),
                  *(UFG::AllocationProfile **)(v4 + 16));
                v33 = v38;
              }
              else
              {
                v33 = 0i64;
              }
              UFG::qBaseTreeRB::Add(
                &UFG::qChunkFileSystem::mLoadedChunkFiles.mTree,
                (UFG::qBaseNodeRB *)((char *)v33 + 248));
            }
            if ( v33 )
            {
              ++LODWORD(v33[5].mChild[0]);
              v39 = (int)v33[5].mChild[1];
              if ( v39 != 2 )
              {
                if ( v39 == 1 )
                {
                  UFG::ResourceFile::AddWaitingTable((UFG::ResourceFile *)v33, v1);
                }
                else if ( !v39 || v39 == 3 )
                {
                  UFG::qPrintChannel::Print(
                    &UFG::qChunkFileSystem::mResourceChannel,
                    OUTPUT_LEVEL_DEBUG,
                    "[Resource - Internal_Load]     state change %s -> LOADING\n");
                  LODWORD(v33[5].mChild[1]) = 1;
                  v40 = UFG::LoadedChunkFile::GetChunkFilename((UFG::LoadedChunkFile *)v33);
                  if ( v1->mCallbacks.mFilename )
                  {
                    UFG::qGetFileSizeAsync(
                      v40,
                      UFG::qChunkFileSystem::ResourceSystem_LoadedChunkFileGetSize,
                      (void *)LODWORD(v33[8].mChild[1]),
                      QPRIORITY_NORMAL);
                    ++HIDWORD(v33[5].mChild[0]);
                    UFG::ResourceFile::AddWaitingTable((UFG::ResourceFile *)v33, v1);
                  }
                  else if ( !UFG::LoadedChunkFile::LoadSync((UFG::LoadedChunkFile *)v33) )
                  {
                    UFG::qPrintChannel::Print(
                      &UFG::qChunkFileSystem::mResourceChannel,
                      OUTPUT_LEVEL_ERROR,
                      "[Resource - Internal_Load]     failed to load file %s\n");
                  }
                }
              }
            }
            else
            {
LABEL_94:
              v41 = *(_QWORD *)(v4 + 40);
              if ( v41 )
                v42 = *(_QWORD *)(v41 + 24);
              UFG::qPrintChannel::Print(
                &UFG::qChunkFileSystem::mResourceChannel,
                OUTPUT_LEVEL_WARNING,
                "[Resource - Internal_Load]   Couldn't find index or filename for 0x%08x %s\n");
            }
LABEL_158:
            v5 = (signed __int64)&v1->mTableEntries;
            goto LABEL_159;
          }
          while ( 1 )
          {
            v13 = v11[8].mNode.mPrev;
            if ( v13 )
            {
              v14 = v13[5].mNext;
              v15 = (signed __int64)(v14 ? (UFG::qNode<UFG::LoadedIndexFile,UFG::LoadedIndexFile> **)((char *)&v13[5].mNext + (_QWORD)v14) : 0i64);
              v16 = (int)v13[6].mPrev;
              if ( v15 )
              {
                if ( v16 )
                {
                  v17 = 0;
                  v18 = v16 - 1;
                  if ( v18 >= 0 )
                  {
                    do
                    {
                      v19 = (unsigned int)(v18 + v17) >> 1;
                      v20 = *(_DWORD *)(v15 + 20 * v19);
                      if ( v20 >= v6 )
                      {
                        if ( v20 <= v6 )
                          goto LABEL_33;
                        v18 = v19 - 1;
                      }
                      else
                      {
                        v17 = v19 + 1;
                      }
                    }
                    while ( v17 <= v18 );
                  }
                  LODWORD(v19) = -1 - v17;
LABEL_33:
                  if ( (signed int)v19 >= 0 )
                    break;
                }
              }
            }
            v11 = (UFG::qList<UFG::LoadedIndexFile,UFG::LoadedIndexFile,1,0> *)v11->mNode.mNext;
            if ( v11 == &UFG::qChunkFileSystem::mLoadedIndexFiles )
              goto LABEL_60;
          }
          out_index_file = (UFG::LoadedIndexFile *)v11;
          v12 = (UFG::qChunkFileIndexEntry *)(v15 + 20i64 * (signed int)v19);
          out_chunk_file_index = v12;
          v21 = v12->mUncompressedSize;
          if ( v21 )
            v22 = v12->mUncompressedSize;
          else
            v22 = v12->mByteSize;
          v24 = 0;
          if ( *(_QWORD *)(v4 + 24) )
          {
            v23 = v21 ? v21
                      + ((unsigned __int8)v12->mDecompressionPaddingHi << 8)
                      + (unsigned __int8)v12->mDecompressionPaddingLow : v12->mByteSize;
            if ( *(_DWORD *)(v4 + 32) > v23 )
              v24 = 1;
          }
          if ( v21 )
            v25 = v21
                + ((unsigned __int8)v12->mDecompressionPaddingHi << 8)
                + (unsigned __int8)v12->mDecompressionPaddingLow;
          else
            v25 = v12->mByteSize;
          if ( (v22 != v12->mByteSize) == 1 && v24 == 1 )
          {
            v25 = v12->mUncompressedSize;
            if ( !v21 )
              v25 = v12->mByteSize;
          }
          v26 = UFG::gMainMemoryPool;
          if ( !UFG::gMainMemoryPool )
          {
            UFG::InternalSetupMainMemoryPool((UFG *)UFG::gMainMemoryPool);
            v26 = UFG::gMainMemoryPool;
          }
          v27 = UFG::qMemoryPool::Allocate(v26, 0x100ui64, "ResourceFileSystem.LoadedChunk", 0i64, 1u);
          if ( v27 )
          {
            UFG::LoadedChunk::LoadedChunk((UFG::LoadedChunk *)v27, v6, *(UFG::AllocationProfile **)(v4 + 16), v25);
            v10 = v28;
          }
          else
          {
            v10 = 0i64;
          }
          UFG::qBaseTreeRB::Add(&UFG::qChunkFileSystem::mLoadedChunks.mTree, (UFG::qBaseNodeRB *)((char *)v10 + 216));
          if ( !v10 )
            goto LABEL_94;
          v5 = (signed __int64)&v1->mTableEntries;
        }
        ++LODWORD(v10[5].mChild[0]);
        v43 = (int)v10[5].mChild[1];
        if ( v43 != 2 )
          break;
      }
LABEL_159:
      v4 = *(_QWORD *)(v4 + 8);
      v97 = v4;
      if ( v4 == v5 )
        goto LABEL_160;
    }
    if ( v43 == 1 )
    {
      UFG::ResourceFile::AddWaitingTable((UFG::ResourceFile *)v10, v1);
      goto LABEL_158;
    }
    if ( v43 && v43 != 3 )
      goto LABEL_159;
    if ( !v12 )
    {
      UFG::qChunkFileSystem::GetChunkFileIndexEntry(&out_index_file, &out_chunk_file_index, v6);
      v11 = (UFG::qList<UFG::LoadedIndexFile,UFG::LoadedIndexFile,1,0> *)out_index_file;
      v12 = out_chunk_file_index;
    }
    v44 = 0i64;
    v92 = 0i64;
    v47 = 0;
    if ( v11 )
    {
      v45 = UFG::LoadedIndexFile::GetChunkFilename((UFG::LoadedIndexFile *)v11);
      v46 = UFG::qChunkFileSystem::GetResourceFileHandle(v45);
      v44 = v46;
      v92 = v46;
      if ( v46 )
      {
        if ( v46[1].mTree.mRoot.mParent )
          v47 = 1;
      }
    }
    if ( !v12 || v47 != 1 )
    {
      if ( v11 )
        v82 = v11[2].mNode.mNext;
      if ( v44 )
        v44[1].mTree.mRoot.mParent;
      v83 = SLODWORD(v10[5].mChild[1]);
      if ( (unsigned int)v83 <= 3 )
        v84 = off_14203C5B0[v83];
      if ( (unsigned int)v83 <= 3 )
        v85 = off_14203C5B0[v83];
      read_bytes = (int)v10[6].mChild[1];
      v87 = v10->mUID;
      _((AMD_HD3D *)&UFG::qChunkFileSystem::mResourceChannel);
      goto LABEL_158;
    }
    UFG::qPrintChannel::Print(
      &UFG::qChunkFileSystem::mResourceChannel,
      OUTPUT_LEVEL_DEBUG,
      "[Resource - Internal_Load]     state change %s -> LOADING\n");
    LODWORD(v10[5].mChild[1]) = 1;
    v48 = v12->mLowerPosition;
    v49 = v48 | ((unsigned __int64)(unsigned __int8)v12->mUpperPosition << 32);
    seek_offset = v48 | ((unsigned __int64)(unsigned __int8)v12->mUpperPosition << 32);
    v50 = v12->mUncompressedSize;
    if ( v50 )
      v51 = v50
          + (unsigned __int8)v12->mDecompressionPaddingLow
          + ((unsigned __int8)v12->mDecompressionPaddingHi << 8)
          - v12->mByteSize;
    else
      v51 = 0i64;
    v52 = v12->mByteSize;
    LODWORD(out_chunk_file_index) = v12->mByteSize;
    v53 = v50;
    if ( !v50 )
      v53 = v52;
    LOBYTE(out_index_file) = v53 != (_DWORD)v52;
    v55 = 0;
    if ( *(_QWORD *)(v4 + 24) )
    {
      v54 = v50 ? v50
                + ((unsigned __int8)v12->mDecompressionPaddingHi << 8)
                + (unsigned __int8)v12->mDecompressionPaddingLow : (_DWORD)v52;
      if ( *(_DWORD *)(v4 + 32) > v54 )
        v55 = 1;
    }
    v56 = (UFG::ResourceMemoryHandle *)v10[3].mChild;
    v57 = *(_QWORD *)&v10[4].mUID;
    if ( !v57 || *(_DWORD *)(v57 + 20) == 1 && *(_QWORD *)&v10[3].mUID )
      UFG::qVRAMemoryPools::Lock((UFG::qVRAMemoryHandle *)v10[3].mChild);
    UFG::ResourceMemoryHandle::GetBuffer((UFG::ResourceMemoryHandle *)v10[3].mChild);
    v58 = v10->mUID;
    UFG::qPrintChannel::Print(
      &UFG::qChunkFileSystem::mResourceChannel,
      OUTPUT_LEVEL_WARNING,
      "[Resource - Internal_Load]     Starting read of 0x%08x bytes to buffer %p for uid:0x%08x from file '%s'\n");
    if ( load_tablea->mCallbacks.mFilename )
    {
      UFG::ResourceFile::AddWaitingTable((UFG::ResourceFile *)v10, load_tablea);
      ++HIDWORD(v10[5].mChild[0]);
      v59 = (UFG::ResourceMemoryHandle *)v10[3].mChild;
      if ( (_BYTE)out_index_file == 1 )
      {
        v60 = v55 == 1;
        callback_param = (void *)LODWORD(v10[7].mChild[1]);
        if ( v60 )
        {
          scratch_size = *(unsigned int *)(v97 + 32);
          scratch_buffer = *(void **)(v97 + 24);
          v64 = UFG::ResourceMemoryHandle::GetBufferSize(v59);
          v65 = UFG::ResourceMemoryHandle::GetBuffer(v56);
          UFG::qReadAndDecompressAsync(
            (UFG::qFile *)v92[1].mTree.mRoot.mParent,
            v65,
            v64,
            seek_offset,
            0,
            (unsigned int)v51,
            v52,
            0i64,
            scratch_buffer,
            scratch_size,
            1,
            UFG::qChunkFileSystem::ResourceSystem_LoadedChunkCallback,
            callback_param,
            QPRIORITY_NORMAL);
        }
        else
        {
          v66 = UFG::ResourceMemoryHandle::GetBufferSize(v59);
          v67 = UFG::ResourceMemoryHandle::GetBuffer(v56);
          UFG::qReadAndDecompressAsync(
            (UFG::qFile *)v44[1].mTree.mRoot.mParent,
            v67,
            v66,
            v49,
            0,
            (unsigned int)v51,
            v52,
            0i64,
            0i64,
            0i64,
            1,
            UFG::qChunkFileSystem::ResourceSystem_LoadedChunkCallback,
            callback_param,
            QPRIORITY_NORMAL);
        }
      }
      else
      {
        v68 = (void *)LODWORD(v10[7].mChild[1]);
        v69 = UFG::ResourceMemoryHandle::GetBuffer(v59);
        UFG::qReadAsync(
          (UFG::qFile *)v44[1].mTree.mRoot.mParent,
          v69,
          v52,
          v49,
          0,
          UFG::qChunkFileSystem::ResourceSystem_LoadedChunkCallback,
          v68,
          QPRIORITY_NORMAL);
      }
LABEL_148:
      v1 = load_tablea;
      v4 = v97;
      v5 = v91;
      goto LABEL_159;
    }
    v70 = (UFG::ResourceMemoryHandle *)v10[3].mChild;
    if ( (_BYTE)out_index_file != 1 )
    {
      v80 = UFG::ResourceMemoryHandle::GetBuffer(v70);
      v10[5].mParent = (UFG::qBaseNodeRB *)UFG::qRead((UFG::qFile *)v44[1].mTree.mRoot.mParent, v80, v52, v49, 0);
LABEL_143:
      v81 = *(_QWORD *)&v10[4].mUID;
      if ( !v81 || *(_DWORD *)(v81 + 20) == 1 && *(_QWORD *)&v10[3].mUID )
        UFG::qVRAMemoryPools::Unlock((UFG::qVRAMemoryHandle *)v10[3].mChild);
      UFG::ResourceFile::WarehouseLoad((UFG::ResourceFile *)v10);
      goto LABEL_148;
    }
    if ( v55 == 1 )
    {
      v71 = *(unsigned int *)(v97 + 32);
      v72 = *(void **)(v97 + 24);
      v73 = UFG::ResourceMemoryHandle::GetBufferSize(v70);
      v74 = UFG::ResourceMemoryHandle::GetBuffer((UFG::ResourceMemoryHandle *)v10[3].mChild);
      v75 = UFG::qReadAndDecompress(
              (UFG::qFile *)v44[1].mTree.mRoot.mParent,
              v74,
              v73,
              v49,
              0,
              (unsigned int)v51,
              (unsigned int)out_chunk_file_index,
              0i64,
              v72,
              v71,
              1);
    }
    else
    {
      v76 = v52;
      v77 = UFG::ResourceMemoryHandle::GetBufferSize(v70);
      v78 = UFG::ResourceMemoryHandle::GetBuffer((UFG::ResourceMemoryHandle *)v10[3].mChild);
      v79 = -1i64;
      if ( !v78
        || v77 < v51 + v76
        || UFG::qRead((UFG::qFile *)v44[1].mTree.mRoot.mParent, &v78[v51], v76, seek_offset, 0) != v76 )
      {
        goto LABEL_141;
      }
      v75 = UFG::qDecompressLZ((UFG::qCompressHeader *)&v78[v51], v76, v78, v77);
    }
    v79 = v75;
LABEL_141:
    v10[5].mParent = (UFG::qBaseNodeRB *)v79;
    goto LABEL_143;
  }
LABEL_160:
  if ( v1->mCallbacks.mFilename )
  {
    if ( v1->mNumPendingLoads )
    {
      v89 = UFG::qChunkFileSystem::mLoadTablesLoading.mNode.mPrev;
      UFG::qChunkFileSystem::mLoadTablesLoading.mNode.mPrev->mNext = (UFG::qNode<UFG::ResourceLoadTable,UFG::ResourceLoadTable> *)&v1->mPrev;
      v1->mPrev = v89;
      v1->mNext = (UFG::qNode<UFG::ResourceLoadTable,UFG::ResourceLoadTable> *)&UFG::qChunkFileSystem::mLoadTablesLoading;
      UFG::qChunkFileSystem::mLoadTablesLoading.mNode.mPrev = (UFG::qNode<UFG::ResourceLoadTable,UFG::ResourceLoadTable> *)&v1->mPrev;
    }
    else
    {
      v1->mState = 4;
      v88 = UFG::qChunkFileSystem::mLoadTablesCallback.mNode.mPrev;
      UFG::qChunkFileSystem::mLoadTablesCallback.mNode.mPrev->mNext = (UFG::qNode<UFG::ResourceLoadTable,UFG::ResourceLoadTable> *)&v1->mPrev;
      v1->mPrev = v88;
      v1->mNext = (UFG::qNode<UFG::ResourceLoadTable,UFG::ResourceLoadTable> *)&UFG::qChunkFileSystem::mLoadTablesCallback;
      UFG::qChunkFileSystem::mLoadTablesCallback.mNode.mPrev = (UFG::qNode<UFG::ResourceLoadTable,UFG::ResourceLoadTable> *)&v1->mPrev;
    }
  }
  else
  {
    v1->mState = 7;
    v90 = UFG::qChunkFileSystem::mLoadTablesLoaded.mNode.mPrev;
    UFG::qChunkFileSystem::mLoadTablesLoaded.mNode.mPrev->mNext = (UFG::qNode<UFG::ResourceLoadTable,UFG::ResourceLoadTable> *)&v1->mPrev;
    v1->mPrev = v90;
    v1->mNext = (UFG::qNode<UFG::ResourceLoadTable,UFG::ResourceLoadTable> *)&UFG::qChunkFileSystem::mLoadTablesLoaded;
    UFG::qChunkFileSystem::mLoadTablesLoaded.mNode.mPrev = (UFG::qNode<UFG::ResourceLoadTable,UFG::ResourceLoadTable> *)&v1->mPrev;
  }
}

// File Line: 2244
// RVA: 0x17DA00
void __fastcall UFG::qChunkFileSystem::SortedLoadTableCallback(unsigned int load_table_uid, bool completed, void *callback_param)
{
  UFG::qChunkFileSystem::UnloadLoadTable(load_table_uid, 1);
}

// File Line: 2279
// RVA: 0x17D490
void __fastcall UFG::qChunkFileSystem::SortLoadTable(UFG::ResourceLoadTable *load_table)
{
  UFG::ResourceLoadTable *v1; // rbx
  UFG::qNode<UFG::LoadTableEntry,UFG::LoadTableEntry> *v2; // r12
  UFG::qList<UFG::LoadTableEntry,UFG::LoadTableEntry,1,0> *v3; // r15
  UFG::qList<UFG::LoadTableEntry,UFG::LoadTableEntry,1,0> *v4; // r13
  unsigned int v5; // ebx
  unsigned __int64 v6; // rsi
  UFG::qNode<UFG::LoadedIndexFile,UFG::LoadedIndexFile> *i; // r14
  UFG::qNode<UFG::LoadedIndexFile,UFG::LoadedIndexFile> *v8; // rcx
  UFG::qNode<UFG::LoadedIndexFile,UFG::LoadedIndexFile> *v9; // rdx
  signed __int64 v10; // r10
  int v11; // er8
  int v12; // er9
  int v13; // er8
  __int64 v14; // rdx
  unsigned int v15; // eax
  signed __int64 v16; // rdi
  char v17; // bl
  unsigned __int64 v18; // rax
  UFG::qNode<UFG::LoadTableEntry,UFG::LoadTableEntry> *v19; // rcx
  UFG::qNode<UFG::LoadTableEntry,UFG::LoadTableEntry> *v20; // rax
  unsigned __int64 v21; // rsi
  UFG::qNode<UFG::qChunkFileSystem::fileSortingNode,UFG::qChunkFileSystem::fileSortingNode> *v22; // rbx
  UFG *v23; // rcx
  UFG::allocator::free_link *v24; // rax
  _QWORD *v25; // rcx
  UFG::qNode<UFG::qChunkFileSystem::fileSortingNode,UFG::qChunkFileSystem::fileSortingNode> *v26; // rax
  UFG *v27; // rcx
  UFG::qBaseNodeRB *v28; // rdx
  unsigned int v29; // eax
  unsigned __int64 v30; // rax
  UFG::qNode<UFG::qChunkFileSystem::fileSortingNode,UFG::qChunkFileSystem::fileSortingNode> *j; // rsi
  UFG::qNode<UFG::qChunkFileSystem::fileSortingNode,UFG::qChunkFileSystem::fileSortingNode> *v32; // rcx
  UFG::qNode<UFG::qChunkFileSystem::fileSortingNode,UFG::qChunkFileSystem::fileSortingNode> *v33; // rax
  signed __int64 v34; // rdi
  UFG::qBaseNodeVariableRB<unsigned __int64> *v35; // rcx
  UFG::qBaseNodeVariableRB<unsigned __int64> *k; // rax
  UFG::qBaseNodeVariableRB<unsigned __int64> *v37; // rbx
  UFG::qBaseNodeVariableRB<unsigned __int64> *v38; // rcx
  UFG::qBaseNodeVariableRB<unsigned __int64> *v39; // rax
  Render::SkinningCacheNode *v40; // rdi
  UFG::qNode<UFG::qChunkFileSystem::fileSortingNode,UFG::qChunkFileSystem::fileSortingNode> *v41; // rcx
  UFG::qNode<UFG::qChunkFileSystem::fileSortingNode,UFG::qChunkFileSystem::fileSortingNode> *v42; // rax
  UFG::qNode<UFG::qChunkFileSystem::fileSortingNode,UFG::qChunkFileSystem::fileSortingNode> *v43; // rcx
  UFG::qNode<UFG::qChunkFileSystem::fileSortingNode,UFG::qChunkFileSystem::fileSortingNode> *v44; // rax
  UFG::qList<UFG::qChunkFileSystem::fileSortingNode,UFG::qChunkFileSystem::fileSortingNode,1,0> v45; // [rsp+38h] [rbp-18h]
  signed __int64 v46; // [rsp+98h] [rbp+48h]

  v1 = load_table;
  UFG::qGetTicks();
  v45.mNode.mPrev = (UFG::qNode<UFG::qChunkFileSystem::fileSortingNode,UFG::qChunkFileSystem::fileSortingNode> *)&v45;
  v45.mNode.mNext = (UFG::qNode<UFG::qChunkFileSystem::fileSortingNode,UFG::qChunkFileSystem::fileSortingNode> *)&v45;
  v2 = v1->mTableEntries.mNode.mNext;
  v3 = &v1->mTableEntries;
  if ( v2 != (UFG::qNode<UFG::LoadTableEntry,UFG::LoadTableEntry> *)&v1->mTableEntries )
  {
    do
    {
      v4 = (UFG::qList<UFG::LoadTableEntry,UFG::LoadTableEntry,1,0> *)v2->mNext;
      v5 = (unsigned int)v2[3].mPrev;
      v6 = UFG::qGetTicks();
      for ( i = UFG::qChunkFileSystem::mLoadedIndexFiles.mNode.mNext;
            i != (UFG::qNode<UFG::LoadedIndexFile,UFG::LoadedIndexFile> *)&UFG::qChunkFileSystem::mLoadedIndexFiles;
            i = i->mNext )
      {
        v8 = i[8].mPrev;
        if ( v8 )
        {
          v9 = v8[5].mNext;
          v10 = (signed __int64)(v9 ? (UFG::qNode<UFG::LoadedIndexFile,UFG::LoadedIndexFile> **)((char *)&v9[5].mNext
                                                                                               + (_QWORD)v8) : 0i64);
          v11 = (int)v8[6].mPrev;
          if ( v10 )
          {
            if ( v11 )
            {
              v12 = 0;
              v13 = v11 - 1;
              if ( v13 >= 0 )
              {
                do
                {
                  v14 = (unsigned int)(v13 + v12) >> 1;
                  v15 = *(_DWORD *)(v10 + 20 * v14);
                  if ( v15 >= v5 )
                  {
                    if ( v15 <= v5 )
                      goto LABEL_17;
                    v13 = v14 - 1;
                  }
                  else
                  {
                    v12 = v14 + 1;
                  }
                }
                while ( v12 <= v13 );
              }
              LODWORD(v14) = -1 - v12;
LABEL_17:
              if ( (signed int)v14 >= 0 )
              {
                v16 = v10 + 20i64 * (signed int)v14;
                v17 = 1;
                goto LABEL_21;
              }
            }
          }
        }
      }
      i = 0i64;
      v16 = 0i64;
      v17 = 0;
LABEL_21:
      v18 = UFG::qGetTicks();
      UFG::qGetTickTime(v6, v18);
      if ( v17 == 1 )
      {
        v19 = v2->mPrev;
        v20 = v2->mNext;
        v19->mNext = v20;
        v20->mPrev = v19;
        v2->mPrev = v2;
        v2->mNext = v2;
        v21 = UFG::qGetTicks();
        v22 = v45.mNode.mNext;
        if ( (UFG::qList<UFG::qChunkFileSystem::fileSortingNode,UFG::qChunkFileSystem::fileSortingNode,1,0> *)v45.mNode.mNext == &v45 )
        {
LABEL_25:
          if ( !UFG::gMainMemoryPool )
          {
            if ( (unsigned int)UFG::qAtomicIncrement(&sInitMallocSemaphore) == 1 )
            {
              UFG::gMainMemoryPool = &gMainMemoryPoolBuffer;
              UFG::qMemoryPool::qMemoryPool(&gMainMemoryPoolBuffer);
              UFG::qUserCallback_InitMainPool(v23);
              UFG::qAtomicDecrement(&sInitMallocSemaphore);
            }
            else
            {
              UFG::qAtomicDecrement(&sInitMallocSemaphore);
              while ( sInitMallocSemaphore > 0 )
                UFG::qSleep(1u);
            }
          }
          v24 = UFG::qMemoryPool::Allocate(UFG::gMainMemoryPool, 0x60ui64, "fileSortingNode", 0i64, 1u);
          v22 = (UFG::qNode<UFG::qChunkFileSystem::fileSortingNode,UFG::qChunkFileSystem::fileSortingNode> *)v24;
          if ( v24 )
          {
            v24->mNext = v24;
            v24[1].mNext = v24;
            v24[2].mNext = (UFG::allocator::free_link *)i;
            v46 = (signed __int64)&v24[3];
            *(_OWORD *)v46 = 0ui64;
            *(_QWORD *)(v46 + 16) = 0i64;
            v25 = &v24[7].mNext;
            *v25 = 0i64;
            v25[1] = 0i64;
            v25[2] = 0i64;
            *v25 = (unsigned __int64)&v24[7] | (_QWORD)v24[7].mNext & 1;
            *(_QWORD *)(v46 + 40) = v24 + 7;
            *(_QWORD *)(v46 + 48) = v24 + 7;
            *v25 &= 0xFFFFFFFFFFFFFFFEui64;
            *(_DWORD *)(v46 + 56) = 0;
            *(_QWORD *)v46 = (unsigned __int64)&v24[7] | (_QWORD)v24[3].mNext & 1;
            *(_QWORD *)(v46 + 8) = v24 + 7;
            *(_QWORD *)(v46 + 16) = v24 + 7;
            *(_QWORD *)v46 &= 0xFFFFFFFFFFFFFFFEui64;
            *(_DWORD *)(v46 + 24) = -1;
            *(_DWORD *)(v46 + 64) = 0;
          }
          else
          {
            v22 = 0i64;
          }
          v26 = v45.mNode.mPrev;
          v45.mNode.mPrev->mNext = v22;
          v22->mPrev = v26;
          v22->mNext = (UFG::qNode<UFG::qChunkFileSystem::fileSortingNode,UFG::qChunkFileSystem::fileSortingNode> *)&v45;
          v45.mNode.mPrev = v22;
        }
        else
        {
          while ( HIDWORD(v22[1].mPrev[6].mPrev) != HIDWORD(i[6].mPrev) )
          {
            v22 = v22->mNext;
            if ( v22 == (UFG::qNode<UFG::qChunkFileSystem::fileSortingNode,UFG::qChunkFileSystem::fileSortingNode> *)&v45 )
              goto LABEL_25;
          }
        }
        if ( !UFG::gMainMemoryPool )
        {
          if ( (unsigned int)UFG::qAtomicIncrement(&sInitMallocSemaphore) == 1 )
          {
            UFG::gMainMemoryPool = &gMainMemoryPoolBuffer;
            UFG::qMemoryPool::qMemoryPool(&gMainMemoryPoolBuffer);
            UFG::qUserCallback_InitMainPool(v27);
            UFG::qAtomicDecrement(&sInitMallocSemaphore);
          }
          else
          {
            UFG::qAtomicDecrement(&sInitMallocSemaphore);
            while ( sInitMallocSemaphore > 0 )
              UFG::qSleep(1u);
          }
        }
        v28 = (UFG::qBaseNodeRB *)UFG::qMemoryPool::Allocate(
                                    UFG::gMainMemoryPool,
                                    0x28ui64,
                                    "entrySortingNode",
                                    0i64,
                                    1u);
        if ( v28 )
        {
          v29 = *(_DWORD *)(v16 + 12);
          v28->mParent = 0i64;
          v28->mChild[0] = 0i64;
          v28->mChild[1] = 0i64;
          v28->mUID = v29;
          v28[1].mParent = (UFG::qBaseNodeRB *)v2;
        }
        else
        {
          v28 = 0i64;
        }
        UFG::qBaseTreeRB::Add((UFG::qBaseTreeRB *)&v22[1].mNext, v28);
        v30 = UFG::qGetTicks();
        UFG::qGetTickTime(v21, v30);
      }
      v2 = &v4->mNode;
    }
    while ( v4 != v3 );
  }
  UFG::qGetTicks();
  for ( j = v45.mNode.mNext;
        (UFG::qList<UFG::qChunkFileSystem::fileSortingNode,UFG::qChunkFileSystem::fileSortingNode,1,0> *)v45.mNode.mNext != &v45;
        j = v45.mNode.mNext )
  {
    v32 = j->mPrev;
    v33 = j->mNext;
    v32->mNext = v33;
    v33->mPrev = v32;
    j->mPrev = j;
    j->mNext = j;
    if ( LODWORD(j[5].mNext) )
    {
      v34 = (signed __int64)&j[3].mNext;
      do
      {
        v35 = (UFG::qBaseNodeVariableRB<unsigned __int64> *)j[2].mPrev;
        for ( k = v35->mChild[0]; k != (UFG::qBaseNodeVariableRB<unsigned __int64> *)v34; k = k->mChild[0] )
          v35 = k;
        v37 = 0i64;
        if ( v35 != (UFG::qBaseNodeVariableRB<unsigned __int64> *)v34 )
          v37 = v35;
        UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
          (UFG::qBaseTreeVariableRB<unsigned __int64> *)&j[1].mNext,
          v37);
        v38 = v37[1].mParent;
        v39 = (UFG::qBaseNodeVariableRB<unsigned __int64> *)v3->mNode.mPrev;
        v39->mChild[0] = v38;
        v38->mParent = v39;
        v38->mChild[0] = (UFG::qBaseNodeVariableRB<unsigned __int64> *)v3;
        v3->mNode.mPrev = (UFG::qNode<UFG::LoadTableEntry,UFG::LoadTableEntry> *)v38;
        UFG::qMemoryPool::Free(UFG::gMainMemoryPool, v37);
      }
      while ( LODWORD(j[5].mNext) );
    }
    while ( LODWORD(j[5].mNext) )
    {
      v40 = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&j[1].mNext);
      UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
        (UFG::qBaseTreeVariableRB<unsigned __int64> *)&j[1].mNext,
        &v40->mNode);
      if ( v40 )
        UFG::qMemoryPool::Free(UFG::gMainMemoryPool, v40);
    }
    j[1].mNext = (UFG::qNode<UFG::qChunkFileSystem::fileSortingNode,UFG::qChunkFileSystem::fileSortingNode> *)((unsigned __int64)&j[3].mNext | (_QWORD)j[1].mNext & 1);
    j[2].mPrev = (UFG::qNode<UFG::qChunkFileSystem::fileSortingNode,UFG::qChunkFileSystem::fileSortingNode> *)((char *)j + 56);
    j[2].mNext = (UFG::qNode<UFG::qChunkFileSystem::fileSortingNode,UFG::qChunkFileSystem::fileSortingNode> *)((char *)j + 56);
    LODWORD(j[5].mNext) = 0;
    v41 = j->mPrev;
    v42 = j->mNext;
    v41->mNext = v42;
    v42->mPrev = v41;
    j->mPrev = j;
    j->mNext = j;
    UFG::qMemoryPool::Free(UFG::gMainMemoryPool, j);
  }
  UFG::qList<UFG::qChunkFileSystem::fileSortingNode,UFG::qChunkFileSystem::fileSortingNode,1,0>::DeleteNodes(&v45);
  v43 = v45.mNode.mPrev;
  v44 = v45.mNode.mNext;
  v45.mNode.mPrev->mNext = v45.mNode.mNext;
  v44->mPrev = v43;
}

// File Line: 2360
// RVA: 0x17BB00
void __fastcall UFG::qChunkFileSystem::ResourceSystem_ServiceDelayedBundleTables(UFG::qChunkFileSystem *this)
{
  unsigned int v1; // eax
  unsigned int v2; // esi
  UFG::ResourceLoadTable *v3; // rax
  UFG::ResourceLoadTable *v4; // rbx
  UFG::ResourceLoadTable *i; // rdi
  UFG::ResourceLoadTable *v6; // rax
  UFG::qList<UFG::ResourceLoadTable,UFG::ResourceLoadTable,1,0> *v7; // rcx
  UFG::qNode<UFG::ResourceLoadTable,UFG::ResourceLoadTable> *v8; // rcx
  UFG::qNode<UFG::ResourceLoadTable,UFG::ResourceLoadTable> *v9; // rdx

  if ( (UFG::qList<UFG::ResourceLoadTable,UFG::ResourceLoadTable,1,0> *)UFG::qChunkFileSystem::mLoadTablesBundleSort.mNode.mNext != &UFG::qChunkFileSystem::mLoadTablesBundleSort )
  {
    v1 = UFG::qChunkFileSystem::CreateLoadTable(0i64);
    v2 = v1;
    v3 = UFG::qChunkFileSystem::GetCreatedLoadTable(v1);
    v4 = (UFG::ResourceLoadTable *)UFG::qChunkFileSystem::mLoadTablesBundleSort.mNode.mNext;
    for ( i = v3;
          v4 != (UFG::ResourceLoadTable *)&UFG::qChunkFileSystem::mLoadTablesBundleSort;
          v4 = (UFG::ResourceLoadTable *)v4->mNext )
    {
      UFG::ResourceLoadTable::CopyTableEntries(i, v4);
    }
    UFG::qChunkFileSystem::SortLoadTable(i);
    UFG::qChunkFileSystem::LoadLoadTable(v2, UFG::qChunkFileSystem::SortedLoadTableCallback, 0i64, 0);
    v6 = (UFG::ResourceLoadTable *)UFG::qChunkFileSystem::mLoadTablesBundleSort.mNode.mNext;
    v7 = (UFG::qList<UFG::ResourceLoadTable,UFG::ResourceLoadTable,1,0> *)UFG::qChunkFileSystem::mLoadTablesBundleSort.mNode.mNext;
    if ( (UFG::qList<UFG::ResourceLoadTable,UFG::ResourceLoadTable,1,0> *)UFG::qChunkFileSystem::mLoadTablesBundleSort.mNode.mNext != &UFG::qChunkFileSystem::mLoadTablesBundleSort )
    {
      do
        v7 = (UFG::qList<UFG::ResourceLoadTable,UFG::ResourceLoadTable,1,0> *)v7->mNode.mNext;
      while ( v7 != &UFG::qChunkFileSystem::mLoadTablesBundleSort );
      for ( ;
            (UFG::qList<UFG::ResourceLoadTable,UFG::ResourceLoadTable,1,0> *)UFG::qChunkFileSystem::mLoadTablesBundleSort.mNode.mNext != &UFG::qChunkFileSystem::mLoadTablesBundleSort;
            v6 = (UFG::ResourceLoadTable *)UFG::qChunkFileSystem::mLoadTablesBundleSort.mNode.mNext )
      {
        v8 = v6->mNext;
        v9 = v6->mPrev;
        v9->mNext = v8;
        v8->mPrev = v9;
        v6->mPrev = (UFG::qNode<UFG::ResourceLoadTable,UFG::ResourceLoadTable> *)&v6->mPrev;
        v6->mNext = (UFG::qNode<UFG::ResourceLoadTable,UFG::ResourceLoadTable> *)&v6->mPrev;
        UFG::qChunkFileSystem::Internal_Load(v6);
      }
    }
  }
}

// File Line: 2408
// RVA: 0x1750A0
void __fastcall UFG::qChunkFileSystem::Internal_Unload(UFG::ResourceLoadTable *load_table, bool reverse_order)
{
  UFG::ResourceLoadTable *v2; // r14
  UFG::ResourceLoadTable::State v3; // ST28_4
  bool v4; // bl
  unsigned int v5; // ST20_4
  UFG::ResourceLoadTable::State v6; // eax
  UFG::qNode<UFG::ResourceLoadTable,UFG::ResourceLoadTable> *v7; // rax
  UFG::qNode<UFG::ResourceLoadTable,UFG::ResourceLoadTable> *v8; // rcx
  UFG::qNode<UFG::ResourceLoadTable,UFG::ResourceLoadTable> *v9; // rax
  UFG::qList<UFG::LoadTableEntry,UFG::LoadTableEntry,1,0> *v10; // rdi
  UFG::qNode<UFG::LoadTableEntry,UFG::LoadTableEntry> *i; // rbx
  unsigned int v12; // edx
  UFG::qTreeRB<UFG::qValueNodeRB<UFG::LoadedChunk *>,UFG::qValueNodeRB<UFG::LoadedChunk *>,1> *v13; // rax
  unsigned int v14; // ecx
  UFG::qTreeRB<UFG::qValueNodeRB<UFG::LoadedChunkFile *>,UFG::qValueNodeRB<UFG::LoadedChunkFile *>,1> *v15; // rax
  unsigned int v16; // ecx
  UFG::qTreeRB<UFG::qValueNodeRB<UFG::LoadedChunk *>,UFG::qValueNodeRB<UFG::LoadedChunk *>,1> *j; // rcx
  UFG::LoadedChunk *v18; // rcx
  UFG::qTreeRB<UFG::qValueNodeRB<UFG::LoadedChunkFile *>,UFG::qValueNodeRB<UFG::LoadedChunkFile *>,1> *k; // rcx
  UFG::LoadedChunkFile *v20; // rcx
  UFG::qNode<UFG::LoadTableEntry,UFG::LoadTableEntry> *l; // rbx
  unsigned int v22; // edx
  UFG::qTreeRB<UFG::qValueNodeRB<UFG::LoadedChunk *>,UFG::qValueNodeRB<UFG::LoadedChunk *>,1> *v23; // rax
  unsigned int v24; // ecx
  UFG::qTreeRB<UFG::qValueNodeRB<UFG::LoadedChunkFile *>,UFG::qValueNodeRB<UFG::LoadedChunkFile *>,1> *v25; // rax
  unsigned int v26; // ecx
  UFG::qTreeRB<UFG::qValueNodeRB<UFG::LoadedChunk *>,UFG::qValueNodeRB<UFG::LoadedChunk *>,1> *m; // rcx
  UFG::LoadedChunk *v28; // rcx
  UFG::qTreeRB<UFG::qValueNodeRB<UFG::LoadedChunkFile *>,UFG::qValueNodeRB<UFG::LoadedChunkFile *>,1> *n; // rcx
  UFG::LoadedChunkFile *v30; // rcx

  v2 = load_table;
  v3 = load_table->mState;
  v4 = reverse_order;
  v5 = load_table->mTableUID;
  UFG::qPrintChannel::Print(
    &UFG::qChunkFileSystem::mResourceChannel,
    OUTPUT_LEVEL_DEBUG,
    "[Resource - Internal_Unload] tab=%p uid=0x%08x  state=%d\n");
  v6 = v2->mState;
  if ( v6 && v6 != 7 )
  {
    switch ( v6 )
    {
      case 2:
        v7 = v2->mNext;
        v8 = v2->mPrev;
        v2->mState = 6;
        v8->mNext = v7;
        v7->mPrev = v8;
        v2->mPrev = (UFG::qNode<UFG::ResourceLoadTable,UFG::ResourceLoadTable> *)&v2->mPrev;
        v2->mNext = (UFG::qNode<UFG::ResourceLoadTable,UFG::ResourceLoadTable> *)&v2->mPrev;
        v9 = UFG::qChunkFileSystem::mLoadTablesCallback.mNode.mPrev;
        UFG::qChunkFileSystem::mLoadTablesCallback.mNode.mPrev->mNext = (UFG::qNode<UFG::ResourceLoadTable,UFG::ResourceLoadTable> *)&v2->mPrev;
        v2->mPrev = v9;
        v2->mNext = (UFG::qNode<UFG::ResourceLoadTable,UFG::ResourceLoadTable> *)&UFG::qChunkFileSystem::mLoadTablesCallback;
        UFG::qChunkFileSystem::mLoadTablesCallback.mNode.mPrev = (UFG::qNode<UFG::ResourceLoadTable,UFG::ResourceLoadTable> *)&v2->mPrev;
        break;
      case 1:
        v2->mState = 3;
        break;
      case 4:
        v2->mState = 5;
        break;
    }
  }
  else
  {
    v2->mState = 0;
  }
  if ( v2->mState != 6 )
  {
    v10 = &v2->mTableEntries;
    if ( v4 == 1 )
    {
      for ( i = v10->mNode.mPrev; i != (UFG::qNode<UFG::LoadTableEntry,UFG::LoadTableEntry> *)v10; i = i->mPrev )
      {
        v12 = (unsigned int)i[3].mPrev;
        if ( v12 != -1 && v12 )
        {
          v13 = &UFG::qChunkFileSystem::mLoadedChunks;
          while ( 1 )
          {
            v14 = v13->mTree.mRoot.mUID;
            if ( v13 != &UFG::qChunkFileSystem::mLoadedChunks && v14 == v12 )
              break;
            if ( v12 > v14 )
              v13 = (UFG::qTreeRB<UFG::qValueNodeRB<UFG::LoadedChunk *>,UFG::qValueNodeRB<UFG::LoadedChunk *>,1> *)v13->mTree.mRoot.mChild[1];
            else
              v13 = (UFG::qTreeRB<UFG::qValueNodeRB<UFG::LoadedChunk *>,UFG::qValueNodeRB<UFG::LoadedChunk *>,1> *)v13->mTree.mRoot.mChild[0];
            if ( v13 == (UFG::qTreeRB<UFG::qValueNodeRB<UFG::LoadedChunk *>,UFG::qValueNodeRB<UFG::LoadedChunk *>,1> *)&UFG::qChunkFileSystem::mLoadedChunks.mTree.mNULL )
              goto LABEL_22;
          }
          for ( j = (UFG::qTreeRB<UFG::qValueNodeRB<UFG::LoadedChunk *>,UFG::qValueNodeRB<UFG::LoadedChunk *>,1> *)v13->mTree.mRoot.mChild[0];
                j;
                j = (UFG::qTreeRB<UFG::qValueNodeRB<UFG::LoadedChunk *>,UFG::qValueNodeRB<UFG::LoadedChunk *>,1> *)j->mTree.mRoot.mChild[0] )
          {
            if ( j->mTree.mRoot.mUID != v12 )
              break;
            v13 = j;
          }
          if ( v13 )
          {
            v18 = (UFG::LoadedChunk *)v13->mTree.mNULL.mParent;
            if ( v18 )
            {
              UFG::qChunkFileSystem::Unload(v18);
              continue;
            }
          }
LABEL_22:
          v15 = &UFG::qChunkFileSystem::mLoadedChunkFiles;
          while ( 1 )
          {
            v16 = v15->mTree.mRoot.mUID;
            if ( v15 != &UFG::qChunkFileSystem::mLoadedChunkFiles && v16 == v12 )
              break;
            if ( v12 > v16 )
              v15 = (UFG::qTreeRB<UFG::qValueNodeRB<UFG::LoadedChunkFile *>,UFG::qValueNodeRB<UFG::LoadedChunkFile *>,1> *)v15->mTree.mRoot.mChild[1];
            else
              v15 = (UFG::qTreeRB<UFG::qValueNodeRB<UFG::LoadedChunkFile *>,UFG::qValueNodeRB<UFG::LoadedChunkFile *>,1> *)v15->mTree.mRoot.mChild[0];
            if ( v15 == (UFG::qTreeRB<UFG::qValueNodeRB<UFG::LoadedChunkFile *>,UFG::qValueNodeRB<UFG::LoadedChunkFile *>,1> *)&UFG::qChunkFileSystem::mLoadedChunkFiles.mTree.mNULL )
              goto LABEL_42;
          }
          for ( k = (UFG::qTreeRB<UFG::qValueNodeRB<UFG::LoadedChunkFile *>,UFG::qValueNodeRB<UFG::LoadedChunkFile *>,1> *)v15->mTree.mRoot.mChild[0];
                k;
                k = (UFG::qTreeRB<UFG::qValueNodeRB<UFG::LoadedChunkFile *>,UFG::qValueNodeRB<UFG::LoadedChunkFile *>,1> *)k->mTree.mRoot.mChild[0] )
          {
            if ( k->mTree.mRoot.mUID != v12 )
              break;
            v15 = k;
          }
          if ( v15 )
          {
            v20 = (UFG::LoadedChunkFile *)v15->mTree.mNULL.mParent;
            if ( v20 )
              UFG::qChunkFileSystem::Unload(v20);
          }
        }
LABEL_42:
        ;
      }
    }
    else
    {
      for ( l = v2->mTableEntries.mNode.mNext; l != (UFG::qNode<UFG::LoadTableEntry,UFG::LoadTableEntry> *)v10; l = l->mNext )
      {
        v22 = (unsigned int)l[3].mPrev;
        if ( v22 != -1 && v22 )
        {
          v23 = &UFG::qChunkFileSystem::mLoadedChunks;
          while ( 1 )
          {
            v24 = v23->mTree.mRoot.mUID;
            if ( v23 != &UFG::qChunkFileSystem::mLoadedChunks && v24 == v22 )
              break;
            if ( v22 > v24 )
              v23 = (UFG::qTreeRB<UFG::qValueNodeRB<UFG::LoadedChunk *>,UFG::qValueNodeRB<UFG::LoadedChunk *>,1> *)v23->mTree.mRoot.mChild[1];
            else
              v23 = (UFG::qTreeRB<UFG::qValueNodeRB<UFG::LoadedChunk *>,UFG::qValueNodeRB<UFG::LoadedChunk *>,1> *)v23->mTree.mRoot.mChild[0];
            if ( v23 == (UFG::qTreeRB<UFG::qValueNodeRB<UFG::LoadedChunk *>,UFG::qValueNodeRB<UFG::LoadedChunk *>,1> *)&UFG::qChunkFileSystem::mLoadedChunks.mTree.mNULL )
              goto LABEL_54;
          }
          for ( m = (UFG::qTreeRB<UFG::qValueNodeRB<UFG::LoadedChunk *>,UFG::qValueNodeRB<UFG::LoadedChunk *>,1> *)v23->mTree.mRoot.mChild[0];
                m;
                m = (UFG::qTreeRB<UFG::qValueNodeRB<UFG::LoadedChunk *>,UFG::qValueNodeRB<UFG::LoadedChunk *>,1> *)m->mTree.mRoot.mChild[0] )
          {
            if ( m->mTree.mRoot.mUID != v22 )
              break;
            v23 = m;
          }
          if ( v23 )
          {
            v28 = (UFG::LoadedChunk *)v23->mTree.mNULL.mParent;
            if ( v28 )
            {
              UFG::qChunkFileSystem::Unload(v28);
              continue;
            }
          }
LABEL_54:
          v25 = &UFG::qChunkFileSystem::mLoadedChunkFiles;
          while ( 1 )
          {
            v26 = v25->mTree.mRoot.mUID;
            if ( v25 != &UFG::qChunkFileSystem::mLoadedChunkFiles && v26 == v22 )
              break;
            if ( v22 > v26 )
              v25 = (UFG::qTreeRB<UFG::qValueNodeRB<UFG::LoadedChunkFile *>,UFG::qValueNodeRB<UFG::LoadedChunkFile *>,1> *)v25->mTree.mRoot.mChild[1];
            else
              v25 = (UFG::qTreeRB<UFG::qValueNodeRB<UFG::LoadedChunkFile *>,UFG::qValueNodeRB<UFG::LoadedChunkFile *>,1> *)v25->mTree.mRoot.mChild[0];
            if ( v25 == (UFG::qTreeRB<UFG::qValueNodeRB<UFG::LoadedChunkFile *>,UFG::qValueNodeRB<UFG::LoadedChunkFile *>,1> *)&UFG::qChunkFileSystem::mLoadedChunkFiles.mTree.mNULL )
              goto LABEL_74;
          }
          for ( n = (UFG::qTreeRB<UFG::qValueNodeRB<UFG::LoadedChunkFile *>,UFG::qValueNodeRB<UFG::LoadedChunkFile *>,1> *)v25->mTree.mRoot.mChild[0];
                n;
                n = (UFG::qTreeRB<UFG::qValueNodeRB<UFG::LoadedChunkFile *>,UFG::qValueNodeRB<UFG::LoadedChunkFile *>,1> *)n->mTree.mRoot.mChild[0] )
          {
            if ( n->mTree.mRoot.mUID != v22 )
              break;
            v25 = n;
          }
          if ( v25 )
          {
            v30 = (UFG::LoadedChunkFile *)v25->mTree.mNULL.mParent;
            if ( v30 )
              UFG::qChunkFileSystem::Unload(v30);
          }
        }
LABEL_74:
        ;
      }
    }
  }
  if ( v2->mState == STATE_IDLE )
    UFG::qChunkFileSystem::Internal_Destroy(v2);
}

// File Line: 2530
// RVA: 0x174520
void __fastcall UFG::qChunkFileSystem::Internal_Destroy(UFG::ResourceLoadTable *load_table)
{
  UFG::ResourceLoadTable *v1; // rbx
  UFG::ResourceLoadTable::State v2; // ST28_4
  unsigned int v3; // ST20_4
  UFG::qTreeRB<UFG::ResourceLoadTable,UFG::ResourceLoadTable,1> *v4; // rcx
  UFG::qMemoryPool *v5; // rdi
  UFG::qMemoryPool *v6; // rcx

  v1 = load_table;
  v2 = load_table->mState;
  v3 = load_table->mTableUID;
  UFG::qPrintChannel::Print(
    &UFG::qChunkFileSystem::mResourceChannel,
    OUTPUT_LEVEL_DEBUG,
    "[Resource - Internal_Destroy] tab=%p uid=0x%08x  state=%d\n");
  v4 = &UFG::qChunkFileSystem::mSingleFileLoadTables;
  if ( v1->mSingleFileUID == -1 )
    v4 = &UFG::qChunkFileSystem::mCreatedLoadTables;
  UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
    (UFG::qBaseTreeVariableRB<unsigned __int64> *)v4,
    (UFG::qBaseNodeVariableRB<unsigned __int64> *)&v1->mNode);
  v5 = v1->mMemoryPool;
  UFG::ResourceLoadTable::~ResourceLoadTable(v1);
  v6 = UFG::gMainMemoryPool;
  if ( v5 )
    v6 = v5;
  UFG::qMemoryPool::Free(v6, v1);
}

// File Line: 2578
// RVA: 0x16B050
__int64 __fastcall UFG::qChunkFileSystem::CreateLoadTable(UFG::qMemoryPool *memory_pool)
{
  UFG::qMemoryPool *v1; // rsi
  UFG::qMemoryPool *v2; // rcx
  UFG::allocator::free_link *v3; // rbx
  int v4; // ecx
  unsigned int v5; // edi
  int v6; // ecx
  UFG::allocator::free_link *v8; // [rsp+68h] [rbp+10h]
  UFG::allocator::free_link *v9; // [rsp+70h] [rbp+18h]

  v1 = memory_pool;
  if ( memory_pool )
  {
    v3 = UFG::qMemoryPool::Allocate(memory_pool, 0x70ui64, "CreatedLoadTable", 0i64, 1u);
    if ( v3 )
    {
      v6 = (signed int)UFG::qChunkFileSystem::mNextLoadTableUID;
      LODWORD(UFG::qChunkFileSystem::mNextLoadTableUID) = (_DWORD)UFG::qChunkFileSystem::mNextLoadTableUID + 1;
      v3->mNext = v3;
      v3[1].mNext = v3;
      v5 = 0;
      v3[2].mNext = 0i64;
      v3[3].mNext = 0i64;
      v3[4].mNext = 0i64;
      LODWORD(v3[5].mNext) = v6;
      LODWORD(v3[6].mNext) = 0;
      v9 = v3 + 9;
      v9->mNext = v9;
      v9[1].mNext = v9;
      LODWORD(v3[11].mNext) = 0;
      HIDWORD(v3[11].mNext) = v6;
      LODWORD(v3[12].mNext) = -1;
      v3[13].mNext = (UFG::allocator::free_link *)v1;
      v3[7].mNext = 0i64;
      v3[8].mNext = 0i64;
    }
    else
    {
      v5 = 0;
      v3 = 0i64;
    }
  }
  else
  {
    v2 = UFG::gMainMemoryPool;
    if ( !UFG::gMainMemoryPool )
    {
      UFG::InternalSetupMainMemoryPool((UFG *)UFG::gMainMemoryPool);
      v2 = UFG::gMainMemoryPool;
    }
    v3 = UFG::qMemoryPool::Allocate(v2, 0x70ui64, "CreatedLoadTable", 0i64, 1u);
    if ( v3 )
    {
      v4 = (signed int)UFG::qChunkFileSystem::mNextLoadTableUID;
      LODWORD(UFG::qChunkFileSystem::mNextLoadTableUID) = (_DWORD)UFG::qChunkFileSystem::mNextLoadTableUID + 1;
      v3->mNext = v3;
      v3[1].mNext = v3;
      v5 = 0;
      v3[2].mNext = 0i64;
      v3[3].mNext = 0i64;
      v3[4].mNext = 0i64;
      LODWORD(v3[5].mNext) = v4;
      LODWORD(v3[6].mNext) = 0;
      v8 = v3 + 9;
      v8->mNext = v8;
      v8[1].mNext = v8;
      LODWORD(v3[11].mNext) = 0;
      HIDWORD(v3[11].mNext) = v4;
      LODWORD(v3[12].mNext) = -1;
      v3[13].mNext = 0i64;
      v3[7].mNext = 0i64;
      v3[8].mNext = 0i64;
    }
    else
    {
      v5 = 0;
      v3 = 0i64;
    }
  }
  if ( v3 )
    v5 = HIDWORD(v3[11].mNext);
  UFG::qPrintChannel::Print(
    &UFG::qChunkFileSystem::mResourceChannel,
    OUTPUT_LEVEL_WARNING,
    "[Resource - CreateLoadTable] tab=%p uid=0x%08x Table: %s\n");
  if ( !v3 )
    return v5;
  UFG::qBaseTreeRB::Add(&UFG::qChunkFileSystem::mCreatedLoadTables.mTree, (UFG::qBaseNodeRB *)&v3[2]);
  return HIDWORD(v3[11].mNext);
}

// File Line: 2764
// RVA: 0x176FB0
bool __fastcall UFG::qChunkFileSystem::LoadLoadTable(unsigned int load_table_uid, void (__fastcall *callback)(unsigned int, bool, void *), void *callback_param, bool bundle_and_sort)
{
  bool v4; // r14
  void *v5; // rsi
  void (__fastcall *v6)(unsigned int, bool, void *); // rbp
  unsigned int v7; // er9
  UFG::qTreeRB<UFG::ResourceLoadTable,UFG::ResourceLoadTable,1> *v8; // rax
  unsigned int v9; // ecx
  UFG::qTreeRB<UFG::ResourceLoadTable,UFG::ResourceLoadTable,1> *i; // rcx
  signed __int64 v11; // rbx
  bool v12; // zf
  UFG::qNode<UFG::ResourceLoadTable,UFG::ResourceLoadTable> *v13; // rax

  v4 = bundle_and_sort;
  v5 = callback_param;
  v6 = callback;
  v7 = load_table_uid;
  if ( !load_table_uid )
    goto LABEL_14;
  v8 = &UFG::qChunkFileSystem::mCreatedLoadTables;
  while ( 1 )
  {
    v9 = v8->mTree.mRoot.mUID;
    if ( v8 != &UFG::qChunkFileSystem::mCreatedLoadTables && v9 == v7 )
      break;
    if ( v7 > v9 )
      v8 = (UFG::qTreeRB<UFG::ResourceLoadTable,UFG::ResourceLoadTable,1> *)v8->mTree.mRoot.mChild[1];
    else
      v8 = (UFG::qTreeRB<UFG::ResourceLoadTable,UFG::ResourceLoadTable,1> *)v8->mTree.mRoot.mChild[0];
    if ( v8 == (UFG::qTreeRB<UFG::ResourceLoadTable,UFG::ResourceLoadTable,1> *)&UFG::qChunkFileSystem::mCreatedLoadTables.mTree.mNULL )
      goto LABEL_14;
  }
  for ( i = (UFG::qTreeRB<UFG::ResourceLoadTable,UFG::ResourceLoadTable,1> *)v8->mTree.mRoot.mChild[0];
        i;
        i = (UFG::qTreeRB<UFG::ResourceLoadTable,UFG::ResourceLoadTable,1> *)i->mTree.mRoot.mChild[0] )
  {
    if ( i->mTree.mRoot.mUID != v7 )
      break;
    v8 = i;
  }
  v11 = (signed __int64)&v8[-1].mTree.mNULL.mUID;
  if ( !v8 )
LABEL_14:
    v11 = 0i64;
  UFG::qPrintChannel::Print(
    &UFG::qChunkFileSystem::mResourceChannel,
    OUTPUT_LEVEL_WARNING,
    "[Resource - LoadLoadTable] uid=0x%08x Table: %s Callback %p param(%p)\n");
  v12 = v11 == 0;
  if ( v11 )
  {
    *(_QWORD *)(v11 + 56) = v6;
    *(_QWORD *)(v11 + 64) = v5;
    if ( v4 != 1 || *(_QWORD *)(v11 + 80) == v11 + 72 )
    {
      UFG::qChunkFileSystem::Internal_Load((UFG::ResourceLoadTable *)v11);
    }
    else
    {
      *(_DWORD *)(v11 + 48) = 2;
      v13 = UFG::qChunkFileSystem::mLoadTablesBundleSort.mNode.mPrev;
      UFG::qChunkFileSystem::mLoadTablesBundleSort.mNode.mPrev->mNext = (UFG::qNode<UFG::ResourceLoadTable,UFG::ResourceLoadTable> *)v11;
      *(_QWORD *)v11 = v13;
      *(_QWORD *)(v11 + 8) = &UFG::qChunkFileSystem::mLoadTablesBundleSort;
      UFG::qChunkFileSystem::mLoadTablesBundleSort.mNode.mPrev = (UFG::qNode<UFG::ResourceLoadTable,UFG::ResourceLoadTable> *)v11;
    }
    v12 = v11 == 0;
  }
  return !v12;
}

// File Line: 2797
// RVA: 0x17F290
bool __fastcall UFG::qChunkFileSystem::UnloadLoadTable(unsigned int load_table_uid, bool reverse_order)
{
  bool v2; // si
  unsigned int v3; // er9
  UFG::qTreeRB<UFG::ResourceLoadTable,UFG::ResourceLoadTable,1> *v4; // rax
  unsigned int v5; // ecx
  UFG::qTreeRB<UFG::ResourceLoadTable,UFG::ResourceLoadTable,1> *i; // rcx
  UFG::ResourceLoadTable *v7; // rbx
  bool v8; // zf

  v2 = reverse_order;
  v3 = load_table_uid;
  if ( !load_table_uid )
    goto LABEL_14;
  v4 = &UFG::qChunkFileSystem::mCreatedLoadTables;
  while ( 1 )
  {
    v5 = v4->mTree.mRoot.mUID;
    if ( v4 != &UFG::qChunkFileSystem::mCreatedLoadTables && v5 == v3 )
      break;
    if ( v3 > v5 )
      v4 = (UFG::qTreeRB<UFG::ResourceLoadTable,UFG::ResourceLoadTable,1> *)v4->mTree.mRoot.mChild[1];
    else
      v4 = (UFG::qTreeRB<UFG::ResourceLoadTable,UFG::ResourceLoadTable,1> *)v4->mTree.mRoot.mChild[0];
    if ( v4 == (UFG::qTreeRB<UFG::ResourceLoadTable,UFG::ResourceLoadTable,1> *)&UFG::qChunkFileSystem::mCreatedLoadTables.mTree.mNULL )
      goto LABEL_14;
  }
  for ( i = (UFG::qTreeRB<UFG::ResourceLoadTable,UFG::ResourceLoadTable,1> *)v4->mTree.mRoot.mChild[0];
        i;
        i = (UFG::qTreeRB<UFG::ResourceLoadTable,UFG::ResourceLoadTable,1> *)i->mTree.mRoot.mChild[0] )
  {
    if ( i->mTree.mRoot.mUID != v3 )
      break;
    v4 = i;
  }
  v7 = (UFG::ResourceLoadTable *)&v4[-1].mTree.mNULL.mUID;
  if ( !v4 )
LABEL_14:
    v7 = 0i64;
  UFG::qPrintChannel::Print(
    &UFG::qChunkFileSystem::mResourceChannel,
    OUTPUT_LEVEL_WARNING,
    "[Resource - UnloadLoadTable] uid=0x%08x Table: %s\n");
  v8 = v7 == 0i64;
  if ( v7 )
  {
    UFG::qChunkFileSystem::Internal_Unload(v7, v2);
    v8 = v7 == 0i64;
  }
  return !v8;
}

// File Line: 2849
// RVA: 0x166130
void __fastcall UFG::qChunkFileSystem::AddExternalResourceFileReference(unsigned int filename_uid, char *memory_location, unsigned __int64 location_size, void *user_data)
{
  UFG::ExternallyLoadedChunk::AddNewChunk(filename_uid, memory_location, location_size, user_data);
}

// File Line: 2854
// RVA: 0x166120
void __fastcall UFG::qChunkFileSystem::AddExternalResourceFileReference(unsigned int filename_uid, UFG::qVRAMemoryHandle *handle, void *user_data)
{
  UFG::ExternallyLoadedChunk::AddNewChunk(filename_uid, handle, user_data);
}

// File Line: 2859
// RVA: 0x17A8C0
void __fastcall UFG::qChunkFileSystem::RemoveExternalResourceFileReference(unsigned int filename_uid, char *memory_location, unsigned __int64 location_size)
{
  UFG::qResourceData *v3; // rax
  UFG::ResourceFile *v4; // rbx

  v3 = (UFG::qResourceData *)UFG::ExternallyLoadedChunk::FindExistingChunk(filename_uid, memory_location);
  v4 = (UFG::ResourceFile *)v3;
  if ( v3 )
  {
    UFG::qResourceInventory::Remove((UFG::qResourceInventory *)&UFG::gResourceFileInventory.vfptr, v3);
    --UFG::ExternallyLoadedChunk::sLoadedChunkCount;
    UFG::ResourceFile::~ResourceFile(v4);
    UFG::qMemoryPool::Free(UFG::gMainMemoryPool, v4);
  }
  else
  {
    UFG::qResourceFileInventory::PrintContents(&UFG::gResourceFileInventory);
  }
}

// File Line: 2864
// RVA: 0x17A8B0
void __fastcall UFG::qChunkFileSystem::RemoveExternalResourceFileReference(unsigned int filename_uid, UFG::qVRAMemoryHandle *handle)
{
  UFG::ExternallyLoadedChunk::RemoveExistingChunk(filename_uid, handle);
}

// File Line: 2869
// RVA: 0x172F70
__int64 __fastcall UFG::qChunkFileSystem::GetZeroRefResourceFileUserData(void **user_datas, unsigned int max_values)
{
  __int64 v2; // r8
  UFG::qNode<UFG::ResourceFile,UFG::ZeroRefResourceFile> **i; // rax
  UFG::qNode<UFG::ResourceFile,UFG::ZeroRefResourceFile> *v4; // r9

  v2 = 0i64;
  for ( i = &stru_14235B120.mNode.mNext[-6].mNext;
        i != (UFG::qNode<UFG::ResourceFile,UFG::ZeroRefResourceFile> **)&unk_14235B0C8;
        i = &i[12][-6].mNext )
  {
    v4 = i[25];
    if ( v4 )
    {
      user_datas[v2] = v4;
      v2 = (unsigned int)(v2 + 1);
      if ( (_DWORD)v2 == max_values )
        break;
    }
  }
  return (unsigned int)v2;
}

// File Line: 2874
// RVA: 0x16DB00
bool __fastcall UFG::qChunkFileSystem::ExternalChunkMoved(unsigned int filename_uid, char *old_memory_location, char *new_memory_location)
{
  char *v3; // rbx
  UFG::ExternallyLoadedChunk *v4; // rax
  UFG::ExternallyLoadedChunk *v5; // rdx
  UFG::qVRAMemoryPool *v6; // rcx

  v3 = new_memory_location;
  v4 = UFG::ExternallyLoadedChunk::FindExistingChunk(filename_uid, old_memory_location);
  v5 = v4;
  if ( v4 )
  {
    v4->mMemoryHandle.mAllocationProfile->mMemory.mMemoryPool.mAllocationParams = (unsigned __int64)v3;
    v6 = v4->mMemoryHandle.mAllocationProfile->mMemory.mVRAMemoryPool.mPool;
    LOBYTE(v4) = 1;
    v5->mMemoryHandle.mAllocateReturned = v6;
  }
  return (char)v4;
}

