// File Line: 193
// RVA: 0x227020
void __fastcall UFG::StreamFileWrapper::StreamReadQueue::StreamReadQueue(UFG::StreamFileWrapper::StreamReadQueue *this)
{
  UFG::StreamFileWrapper::StreamReadQueue *v1; // rbx
  UFG::qList<UFG::StreamFileWrapper::StreamReadOp,UFG::StreamFileWrapper::StreamReadOp,1,0> *v2; // [rsp+48h] [rbp+10h]

  v1 = this;
  this->mLastDiskSortKey = -1i64;
  UFG::qMutex::qMutex(&this->mQueueMutex, &customWorldMapCaption);
  v2 = &v1->mPendingReads;
  v2->mNode.mPrev = &v2->mNode;
  v2->mNode.mNext = &v2->mNode;
}

// File Line: 198
// RVA: 0x22E320
void __fastcall UFG::StreamFileWrapper::StreamReadQueue::Sort(UFG::StreamFileWrapper::StreamReadQueue *this, bool (__fastcall *fnSort)(UFG::StreamFileWrapper::StreamReadOp *, UFG::StreamFileWrapper::StreamReadOp *))
{
  bool (__fastcall *v2)(UFG::StreamFileWrapper::StreamReadOp *, UFG::StreamFileWrapper::StreamReadOp *); // r14
  UFG::qList<UFG::StreamFileWrapper::StreamReadOp,UFG::StreamFileWrapper::StreamReadOp,1,0> *v3; // rsi
  UFG::StreamFileWrapper::StreamReadOp *v4; // rbx
  char v5; // bp
  UFG::StreamFileWrapper::StreamReadOp *v6; // rdi
  UFG::qNode<UFG::StreamFileWrapper::StreamReadOp,UFG::StreamFileWrapper::StreamReadOp> *v7; // rdx
  UFG::qNode<UFG::StreamFileWrapper::StreamReadOp,UFG::StreamFileWrapper::StreamReadOp> *v8; // rax
  UFG::qNode<UFG::StreamFileWrapper::StreamReadOp,UFG::StreamFileWrapper::StreamReadOp> *v9; // r8
  UFG::qNode<UFG::StreamFileWrapper::StreamReadOp,UFG::StreamFileWrapper::StreamReadOp> *v10; // rax
  UFG::qNode<UFG::StreamFileWrapper::StreamReadOp,UFG::StreamFileWrapper::StreamReadOp> *v11; // rcx
  UFG::qNode<UFG::StreamFileWrapper::StreamReadOp,UFG::StreamFileWrapper::StreamReadOp> *v12; // rax
  UFG::qNode<UFG::StreamFileWrapper::StreamReadOp,UFG::StreamFileWrapper::StreamReadOp> *v13; // rax

  v2 = fnSort;
  v3 = &this->mPendingReads;
  do
  {
    v4 = (UFG::StreamFileWrapper::StreamReadOp *)v3->mNode.mNext;
    v5 = 0;
    if ( v4 == (UFG::StreamFileWrapper::StreamReadOp *)v3 )
      break;
    do
    {
      v6 = (UFG::StreamFileWrapper::StreamReadOp *)v4->mNext;
      if ( v6 == (UFG::StreamFileWrapper::StreamReadOp *)v3 )
        break;
      if ( v2(v4, (UFG::StreamFileWrapper::StreamReadOp *)v4->mNext) )
      {
        v7 = v4->mPrev;
        v8 = v4->mNext;
        v9 = v6->mNext;
        v7->mNext = v8;
        v8->mPrev = v7;
        v4->mPrev = (UFG::qNode<UFG::StreamFileWrapper::StreamReadOp,UFG::StreamFileWrapper::StreamReadOp> *)&v4->mPrev;
        v4->mNext = (UFG::qNode<UFG::StreamFileWrapper::StreamReadOp,UFG::StreamFileWrapper::StreamReadOp> *)&v4->mPrev;
        v10 = v6->mNext;
        v11 = v6->mPrev;
        v11->mNext = v10;
        v10->mPrev = v11;
        v6->mPrev = (UFG::qNode<UFG::StreamFileWrapper::StreamReadOp,UFG::StreamFileWrapper::StreamReadOp> *)&v6->mPrev;
        v6->mNext = (UFG::qNode<UFG::StreamFileWrapper::StreamReadOp,UFG::StreamFileWrapper::StreamReadOp> *)&v6->mPrev;
        v12 = v7->mNext;
        v7->mNext = (UFG::qNode<UFG::StreamFileWrapper::StreamReadOp,UFG::StreamFileWrapper::StreamReadOp> *)&v6->mPrev;
        v6->mPrev = v7;
        v6->mNext = v12;
        v12->mPrev = (UFG::qNode<UFG::StreamFileWrapper::StreamReadOp,UFG::StreamFileWrapper::StreamReadOp> *)&v6->mPrev;
        v13 = v9->mPrev;
        v5 = 1;
        v13->mNext = (UFG::qNode<UFG::StreamFileWrapper::StreamReadOp,UFG::StreamFileWrapper::StreamReadOp> *)&v4->mPrev;
        v4->mPrev = v13;
        v4->mNext = v9;
        v9->mPrev = (UFG::qNode<UFG::StreamFileWrapper::StreamReadOp,UFG::StreamFileWrapper::StreamReadOp> *)&v4->mPrev;
      }
      else
      {
        v4 = v6;
      }
    }
    while ( v4 != (UFG::StreamFileWrapper::StreamReadOp *)v3 );
  }
  while ( v5 );
}

// File Line: 286
// RVA: 0x146FC40
__int64 UFG::StreamFileWrapper::_dynamic_initializer_for__smAudioStreamFiles__()
{
  return atexit(UFG::StreamFileWrapper::_dynamic_atexit_destructor_for__smAudioStreamFiles__);
}

// File Line: 287
// RVA: 0x146FC90
__int64 UFG::StreamFileWrapper::_dynamic_initializer_for__smClosedAudioStreamFiles__()
{
  return atexit(UFG::StreamFileWrapper::_dynamic_atexit_destructor_for__smClosedAudioStreamFiles__);
}

// File Line: 288
// RVA: 0x146FC10
__int64 UFG::StreamFileWrapper::_dynamic_initializer_for__smAudioStreamFileMutex__()
{
  UFG::qMutex::qMutex(&UFG::StreamFileWrapper::smAudioStreamFileMutex, &customWorldMapCaption);
  return atexit(UFG::StreamFileWrapper::_dynamic_atexit_destructor_for__smAudioStreamFileMutex__);
}

// File Line: 290
// RVA: 0x146FE10
__int64 UFG::StreamFileWrapper::_dynamic_initializer_for__smStreamFiles__()
{
  return atexit(UFG::StreamFileWrapper::_dynamic_atexit_destructor_for__smStreamFiles__);
}

// File Line: 291
// RVA: 0x146FCB0
__int64 UFG::StreamFileWrapper::_dynamic_initializer_for__smClosedStreamFiles__()
{
  return atexit(UFG::StreamFileWrapper::_dynamic_atexit_destructor_for__smClosedStreamFiles__);
}

// File Line: 293
// RVA: 0x146FD80
__int64 UFG::StreamFileWrapper::_dynamic_initializer_for__smPendingQueues__()
{
  `eh vector constructor iterator'(
    UFG::StreamFileWrapper::smPendingQueues,
    0x48ui64,
    4,
    (void (__fastcall *)(void *))UFG::StreamFileWrapper::StreamReadQueue::StreamReadQueue);
  return atexit(UFG::StreamFileWrapper::_dynamic_atexit_destructor_for__smPendingQueues__);
}

// File Line: 294
// RVA: 0x146FD30
__int64 UFG::StreamFileWrapper::_dynamic_initializer_for__smInProgressReads__()
{
  return atexit(UFG::StreamFileWrapper::_dynamic_atexit_destructor_for__smInProgressReads__);
}

// File Line: 295
// RVA: 0x146FCD0
__int64 UFG::StreamFileWrapper::_dynamic_initializer_for__smCompletedReads__()
{
  return atexit(UFG::StreamFileWrapper::_dynamic_atexit_destructor_for__smCompletedReads__);
}

// File Line: 297
// RVA: 0x146FE30
__int64 UFG::StreamFileWrapper::_dynamic_initializer_for__smStreamLogEntries__()
{
  return atexit(UFG::StreamFileWrapper::_dynamic_atexit_destructor_for__smStreamLogEntries__);
}

// File Line: 299
// RVA: 0x146FDE0
__int64 UFG::StreamFileWrapper::_dynamic_initializer_for__smStreamFilemMutex__()
{
  UFG::qMutex::qMutex(&UFG::StreamFileWrapper::smStreamFilemMutex, &customWorldMapCaption);
  return atexit(UFG::StreamFileWrapper::_dynamic_atexit_destructor_for__smStreamFilemMutex__);
}

// File Line: 310
// RVA: 0x22BBD0
UFG::allocator::free_link *__fastcall UFG::StreamFileWrapper::Open(const char *filename, UFG::qFileAccessType accessType, bool bWarnIfFail, void (__fastcall *callback)(UFG::qFileOp *, void *), void *callback_param)
{
  void (__fastcall *v5)(UFG::qFileOp *, void *); // rdi
  bool v6; // bp
  UFG::qFileAccessType v7; // er14
  const char *v8; // rsi
  char v9; // bl
  UFG::BIGFileIndex::Entry *v10; // rdi
  UFG::allocator::free_link *v11; // rax
  UFG::allocator::free_link *v12; // rbx
  UFG::BIGFileIndex *v13; // r8
  UFG::qNode<UFG::StreamFileWrapper::StreamFile,UFG::StreamFileWrapper::StreamFile> *v14; // rax
  UFG::qFile *v15; // rax
  UFG::qFile *v16; // rdi
  UFG::allocator::free_link *v17; // rax
  UFG::qNode<UFG::StreamFileWrapper::StreamFile,UFG::StreamFileWrapper::StreamFile> *v18; // rcx
  UFG::BIGFileIndex::Entry *_entry; // [rsp+30h] [rbp-38h]
  UFG::BIGFileIndex *_bigFile; // [rsp+38h] [rbp-30h]
  __int64 v22; // [rsp+40h] [rbp-28h]

  v22 = -2i64;
  v5 = callback;
  v6 = bWarnIfFail;
  v7 = accessType;
  v8 = filename;
  _bigFile = 0i64;
  _entry = 0i64;
  UFG::qMutex::Lock((LPCRITICAL_SECTION)&UFG::StreamFileWrapper::smStreamFilemMutex);
  v9 = UFG::BigFileSystem::GetFileInfoFromBigFile(v8, &_bigFile, &_entry);
  UFG::qMutex::Unlock((LPCRITICAL_SECTION)&UFG::StreamFileWrapper::smStreamFilemMutex);
  if ( v9 == 1 )
  {
    v10 = _entry;
    if ( _entry->size.uncompressed_size > 0 )
    {
      v11 = UFG::qMalloc(0x40ui64, "StreamFile", 0x800ui64);
      v12 = v11;
      _entry = (UFG::BIGFileIndex::Entry *)v11;
      if ( v11 )
      {
        v11->mNext = v11;
        v11[1].mNext = v11;
        v11[2].mNext = (UFG::allocator::free_link *)-1i64;
        LODWORD(v11[3].mNext) = 0;
        v11[4].mNext = 0i64;
        v11[5].mNext = 0i64;
        v11[6].mNext = 0i64;
        v11[7].mNext = 0i64;
      }
      else
      {
        v12 = 0i64;
      }
      LODWORD(v12[3].mNext) = 1;
      v13 = _bigFile;
      v12[4].mNext = (UFG::allocator::free_link *)_bigFile;
      v12[5].mNext = (UFG::allocator::free_link *)v10;
      v12[7].mNext = (UFG::allocator::free_link *)v13->mpFile;
      v12[2].mNext = (UFG::allocator::free_link *)v13->mSortKey;
      UFG::qMutex::Lock((LPCRITICAL_SECTION)&UFG::StreamFileWrapper::smStreamFilemMutex);
      v14 = UFG::StreamFileWrapper::smStreamFiles.mNode.mPrev;
      UFG::StreamFileWrapper::smStreamFiles.mNode.mPrev->mNext = (UFG::qNode<UFG::StreamFileWrapper::StreamFile,UFG::StreamFileWrapper::StreamFile> *)v12;
      v12->mNext = (UFG::allocator::free_link *)v14;
LABEL_15:
      v12[1].mNext = (UFG::allocator::free_link *)&UFG::StreamFileWrapper::smStreamFiles;
      UFG::StreamFileWrapper::smStreamFiles.mNode.mPrev = (UFG::qNode<UFG::StreamFileWrapper::StreamFile,UFG::StreamFileWrapper::StreamFile> *)v12;
      UFG::qMutex::Unlock((LPCRITICAL_SECTION)&UFG::StreamFileWrapper::smStreamFilemMutex);
      return v12;
    }
  }
  else
  {
    if ( v5 )
      v15 = UFG::qOpenAsync(v8, v7, v6, v5, callback_param, QPRIORITY_NORMAL);
    else
      v15 = UFG::qOpen(v8, v7, v6);
    v16 = v15;
    if ( v15 )
    {
      v17 = UFG::qMalloc(0x40ui64, "StreamFile", 0x800ui64);
      v12 = v17;
      _bigFile = (UFG::BIGFileIndex *)v17;
      if ( v17 )
      {
        v17->mNext = v17;
        v17[1].mNext = v17;
        v17[2].mNext = (UFG::allocator::free_link *)-1i64;
        LODWORD(v17[3].mNext) = 0;
        v17[4].mNext = 0i64;
        v17[5].mNext = 0i64;
        v17[6].mNext = 0i64;
        v17[7].mNext = 0i64;
      }
      else
      {
        v12 = 0i64;
      }
      LODWORD(v12[3].mNext) = 0;
      v12[7].mNext = (UFG::allocator::free_link *)v16;
      v12[2].mNext = (UFG::allocator::free_link *)UFG::qGetDiskPosSortKey(v16);
      UFG::qMutex::Lock((LPCRITICAL_SECTION)&UFG::StreamFileWrapper::smStreamFilemMutex);
      v18 = UFG::StreamFileWrapper::smStreamFiles.mNode.mPrev;
      UFG::StreamFileWrapper::smStreamFiles.mNode.mPrev->mNext = (UFG::qNode<UFG::StreamFileWrapper::StreamFile,UFG::StreamFileWrapper::StreamFile> *)v12;
      v12->mNext = (UFG::allocator::free_link *)v18;
      goto LABEL_15;
    }
  }
  return 0i64;
}

// File Line: 377
// RVA: 0x22B990
UFG::allocator::free_link *__fastcall UFG::StreamFileWrapper::OnPackedAudioFileOpen(unsigned int fileId, void *packFile, __int64 fileSize, unsigned int startBlock, UFG::TidoFilePackage *in_pPackage)
{
  _QWORD *v5; // rbp
  unsigned int v6; // esi
  UFG::allocator::free_link *v7; // rax
  UFG::allocator::free_link *v8; // rbx
  UFG::allocator::free_link *v9; // rax
  __int64 v10; // rax
  UFG::qNode<UFG::StreamFileWrapper::StreamFile,UFG::StreamFileWrapper::StreamFile> *v11; // rdx

  v5 = packFile;
  v6 = fileId;
  v7 = UFG::qMalloc(0x40ui64, "StreamFile", 0x800ui64);
  v8 = v7;
  if ( v7 )
  {
    v7->mNext = v7;
    v7[1].mNext = v7;
    v7[2].mNext = (UFG::allocator::free_link *)-1i64;
    LODWORD(v7[3].mNext) = 0;
    v7[4].mNext = 0i64;
    v7[5].mNext = 0i64;
    v7[6].mNext = 0i64;
    v7[7].mNext = 0i64;
  }
  else
  {
    v8 = 0i64;
  }
  LODWORD(v8[3].mNext) = 2;
  v8[7].mNext = *(UFG::allocator::free_link **)((char *)v5 + 56);
  v8[4].mNext = 0i64;
  v8[5].mNext = 0i64;
  v9 = UFG::qMalloc(0x18ui64, "StreamFile:PackedAudioFileData", 0x800ui64);
  if ( v9 )
  {
    v9->mNext = (UFG::allocator::free_link *)&UFG::StreamFileWrapper::PackedAudioFileData::`vftable';
    LODWORD(v9[1].mNext) = 0;
    BYTE4(v9[1].mNext) = 0;
    v9[2].mNext = 0i64;
  }
  else
  {
    v9 = 0i64;
  }
  v8[6].mNext = v9;
  LODWORD(v9[1].mNext) = v6;
  v10 = in_pPackage->m_iDiscFilePosition;
  if ( !v10 )
  {
    v10 = UFG::qGetDiskPosSortKey((UFG::qFile *)v8[7].mNext);
    in_pPackage->m_iDiscFilePosition = v10;
  }
  v8[2].mNext = (UFG::allocator::free_link *)v10;
  UFG::qMutex::Lock((LPCRITICAL_SECTION)&UFG::StreamFileWrapper::smAudioStreamFileMutex);
  v11 = UFG::StreamFileWrapper::smAudioStreamFiles.mNode.mPrev;
  UFG::StreamFileWrapper::smAudioStreamFiles.mNode.mPrev->mNext = (UFG::qNode<UFG::StreamFileWrapper::StreamFile,UFG::StreamFileWrapper::StreamFile> *)v8;
  v8->mNext = (UFG::allocator::free_link *)v11;
  v8[1].mNext = (UFG::allocator::free_link *)&UFG::StreamFileWrapper::smAudioStreamFiles;
  UFG::StreamFileWrapper::smAudioStreamFiles.mNode.mPrev = (UFG::qNode<UFG::StreamFileWrapper::StreamFile,UFG::StreamFileWrapper::StreamFile> *)v8;
  UFG::qMutex::Unlock((LPCRITICAL_SECTION)&UFG::StreamFileWrapper::smAudioStreamFileMutex);
  return v8;
}

// File Line: 441
// RVA: 0x22B920
void __fastcall UFG::StreamFileWrapper::OnPackedAudioFileClose(void *hFile)
{
  UFG::qNode<UFG::StreamFileWrapper::StreamFile,UFG::StreamFileWrapper::StreamFile> *v1; // rbx
  UFG::qNode<UFG::StreamFileWrapper::StreamFile,UFG::StreamFileWrapper::StreamFile> *v2; // rax
  UFG::qNode<UFG::StreamFileWrapper::StreamFile,UFG::StreamFileWrapper::StreamFile> *v3; // rdx
  UFG::qNode<UFG::StreamFileWrapper::StreamFile,UFG::StreamFileWrapper::StreamFile> *v4; // rax

  v1 = (UFG::qNode<UFG::StreamFileWrapper::StreamFile,UFG::StreamFileWrapper::StreamFile> *)hFile;
  UFG::qMutex::Lock((LPCRITICAL_SECTION)&UFG::StreamFileWrapper::smAudioStreamFileMutex);
  v2 = v1->mNext;
  v3 = v1->mPrev;
  v3->mNext = v2;
  v2->mPrev = v3;
  v1->mPrev = v1;
  v1->mNext = v1;
  v4 = UFG::StreamFileWrapper::smClosedAudioStreamFiles.mNode.mPrev;
  UFG::StreamFileWrapper::smClosedAudioStreamFiles.mNode.mPrev->mNext = v1;
  v1->mPrev = v4;
  v1->mNext = (UFG::qNode<UFG::StreamFileWrapper::StreamFile,UFG::StreamFileWrapper::StreamFile> *)&UFG::StreamFileWrapper::smClosedAudioStreamFiles;
  UFG::StreamFileWrapper::smClosedAudioStreamFiles.mNode.mPrev = v1;
  UFG::qMutex::Unlock((LPCRITICAL_SECTION)&UFG::StreamFileWrapper::smAudioStreamFileMutex);
}

// File Line: 454
// RVA: 0x22C7F0
UFG::allocator::free_link *__fastcall UFG::StreamFileWrapper::ReadEntireFile(const char *filename, __int64 *loaded_size, UFG::qMemoryPool *memory_pool, unsigned int alloc_flags, const char *dbg_tag)
{
  UFG::qMemoryPool *v5; // rbp
  __int64 *v6; // r12
  const char *v7; // rbx
  int v8; // er13
  unsigned int v9; // er14
  int v10; // er15
  unsigned int v11; // edi
  UFG::allocator::free_link *result; // rax
  UFG::BIGFileIndex *v13; // rsi
  UFG::allocator::free_link *v14; // rbp
  UFG::allocator::free_link *v15; // rax
  __int64 v16; // rbx
  __int64 v17; // rdx
  _QWORD *v18; // rax
  _DWORD *v19; // [rsp+30h] [rbp-48h]
  __int64 v20; // [rsp+38h] [rbp-40h]
  __int64 v21; // [rsp+40h] [rbp-38h]
  unsigned int allocation_params; // [rsp+98h] [rbp+20h]

  allocation_params = alloc_flags;
  v20 = -2i64;
  v5 = memory_pool;
  v6 = loaded_size;
  v7 = filename;
  v19 = 0i64;
  if ( UFG::BigFileSystem::GetFileInfoFromBigFile(
         filename,
         (UFG::BIGFileIndex **)&v21,
         (UFG::BIGFileIndex::Entry **)&v19) == 1 )
  {
    v8 = v19[2];
    v9 = v19[3];
    v10 = v19[4];
    v11 = v19[5];
  }
  else
  {
    v9 = UFG::qGetFileSize(v7);
    v8 = 0;
    v11 = v9;
    v10 = 0;
  }
  result = UFG::StreamFileWrapper::Open(v7, QACCESS_READ, 1, 0i64, 0i64);
  v13 = (UFG::BIGFileIndex *)result;
  if ( result )
  {
    if ( !v5 )
      v5 = UFG::gMainMemoryPool;
    v14 = UFG::qMemoryPool::Allocate(v5, v11 + v10, dbg_tag, allocation_params, 1u);
    if ( v14 )
    {
      v15 = UFG::qMalloc(0x58ui64, "StreamReadOp", 0x800ui64);
      v16 = (__int64)v15;
      v21 = (__int64)v15;
      if ( v15 )
      {
        v15->mNext = v15;
        v15[1].mNext = v15;
        v15[2].mNext = 0i64;
        LODWORD(v15[3].mNext) = 1;
        WORD2(v15[3].mNext) = 3;
        v15[4].mNext = 0i64;
        v15[5].mNext = 0i64;
        v15[6].mNext = 0i64;
        v15[7].mNext = 0i64;
        v15[8].mNext = 0i64;
        v15[9].mNext = 0i64;
        ++UFG::StreamFileWrapper::StreamReadOp::smTotalReadOpCount;
      }
      else
      {
        v16 = 0i64;
      }
      *(_QWORD *)(v16 + 32) = v13;
      *(_DWORD *)(v16 + 26) = 0x20000;
      *(_QWORD *)(v16 + 56) = v14;
      *(_DWORD *)(v16 + 64) = v8;
      *(_DWORD *)(v16 + 68) = v9;
      *(_DWORD *)(v16 + 72) = v10;
      *(_DWORD *)(v16 + 76) = v11;
      *(_QWORD *)(v16 + 16) = 0i64;
      *(_WORD *)(v16 + 24) = 0;
      *(_QWORD *)(v16 + 40) = 0i64;
      *(_QWORD *)(v16 + 48) = 0i64;
      *(_DWORD *)(v16 + 80) = 0;
      UFG::StreamFileWrapper::ExecuteReadOp((UFG::StreamFileWrapper::StreamReadOp *)v16);
      v21 = v16;
      --UFG::StreamFileWrapper::StreamReadOp::smTotalReadOpCount;
      v17 = *(_QWORD *)v16;
      v18 = *(_QWORD **)(v16 + 8);
      *(_QWORD *)(v17 + 8) = v18;
      *v18 = v17;
      *(_QWORD *)v16 = v16;
      *(_QWORD *)(v16 + 8) = v16;
      operator delete[]((void *)v16);
      if ( v6 )
        *v6 = v11;
    }
    UFG::StreamFileWrapper::Close(v13);
    result = v14;
  }
  return result;
}

// File Line: 486
// RVA: 0x22E400
void __fastcall UFG::StreamFileWrapper::StreamFileWrapperEntireFileCallback(UFG::qFileOp *file_op, void *param)
{
  unsigned int *v2; // rbx
  UFG::qFileOp *v3; // rdi
  _QWORD *v4; // rcx
  _QWORD *v5; // rax

  v2 = (unsigned int *)param;
  v3 = file_op;
  if ( (unsigned int)Scaleform::Render::FileImageSource::GetUse(file_op) == 3 )
  {
    UFG::gFileExecuteTime = UFG::qFileOp::GetExecuteTime(v3);
    (*((void (__fastcall **)(_QWORD, _QWORD, _QWORD, _QWORD, signed __int64))v2 + 10))(
      *((_QWORD *)v2 + 8),
      *((_QWORD *)v2 + 12),
      v2[9],
      *((_QWORD *)v2 + 11),
      -2i64);
    UFG::gFileExecuteTime = FLOAT_N1_0;
    UFG::StreamFileWrapper::Close(*((void **)v2 + 2));
    UFG::qString::~qString((UFG::qString *)v2 + 1);
    v4 = *(_QWORD **)v2;
    v5 = (_QWORD *)*((_QWORD *)v2 + 1);
    v4[1] = v5;
    *v5 = v4;
    *(_QWORD *)v2 = v2;
    *((_QWORD *)v2 + 1) = v2;
    operator delete[](v2);
  }
}

// File Line: 511
// RVA: 0x22C9C0
char __fastcall UFG::StreamFileWrapper::ReadEntireFileAsync(const char *filename, UFG::StreamFileWrapper::QUEUE_CLASS queueClass, void (__fastcall *callback)(const char *, void *, int, void *), void *callback_param, UFG::qMemoryPool *memory_pool, unsigned int alloc_flags, const char *dbg_tag)
{
  UFG::allocator::free_link *v7; // rbp
  void (__fastcall *v8)(const char *, void *, int, void *); // r12
  UFG::StreamFileWrapper::QUEUE_CLASS v9; // er14
  const char *v10; // r15
  UFG::allocator::free_link *v11; // rax
  UFG::allocator::free_link *callbackParam; // rbx
  UFG::allocator::free_link *v13; // rax
  UFG::qMemoryPool *v14; // rcx
  UFG::allocator::free_link *v15; // rax
  UFG::allocator::free_link *v17; // rdx
  UFG::allocator::free_link *v18; // rax
  UFG::allocator::free_link *v19; // rcx
  UFG::allocator::free_link *v20; // rax

  v7 = (UFG::allocator::free_link *)callback_param;
  v8 = callback;
  v9 = queueClass;
  v10 = filename;
  v11 = UFG::qMalloc(0x68ui64, "AsyncFileRead", 0i64);
  callbackParam = v11;
  if ( v11 )
  {
    v11->mNext = v11;
    v11[1].mNext = v11;
    v11[3].mNext = 0i64;
    v11[4].mNext = 0i64;
    UFG::qString::qString((UFG::qString *)&v11[5]);
  }
  else
  {
    callbackParam = 0i64;
  }
  UFG::qString::Set((UFG::qString *)&callbackParam[5], v10);
  callbackParam[10].mNext = (UFG::allocator::free_link *)v8;
  callbackParam[11].mNext = v7;
  UFG::StreamFileWrapper::GetFileSize((const char *)callbackParam[8].mNext, (UFG::BIGFileSize *)&callbackParam[3]);
  v13 = UFG::StreamFileWrapper::Open(v10, QACCESS_READ, 1, 0i64, 0i64);
  callbackParam[2].mNext = v13;
  if ( v13 )
  {
    v14 = memory_pool;
    if ( !memory_pool )
      v14 = UFG::gMainMemoryPool;
    v15 = UFG::qMemoryPool::Allocate(
            v14,
            (unsigned int)(LODWORD(callbackParam[4].mNext) + HIDWORD(callbackParam[4].mNext)),
            dbg_tag,
            alloc_flags,
            1u);
    callbackParam[12].mNext = v15;
    if ( v15 )
    {
      UFG::StreamFileWrapper::Read(
        callbackParam[2].mNext,
        v9,
        v15,
        (UFG::BIGFileSize *)&callbackParam[3],
        0i64,
        0,
        UFG::StreamFileWrapper::StreamFileWrapperEntireFileCallback,
        callbackParam,
        0);
      return 1;
    }
    UFG::StreamFileWrapper::Close(callbackParam[2].mNext);
    callbackParam[2].mNext = 0i64;
    UFG::qString::~qString((UFG::qString *)&callbackParam[5]);
    v17 = callbackParam->mNext;
    v18 = callbackParam[1].mNext;
    v17[1].mNext = v18;
    v18->mNext = v17;
  }
  else
  {
    UFG::qString::~qString((UFG::qString *)&callbackParam[5]);
    v19 = callbackParam->mNext;
    v20 = callbackParam[1].mNext;
    v19[1].mNext = v20;
    v20->mNext = v19;
  }
  callbackParam->mNext = callbackParam;
  callbackParam[1].mNext = callbackParam;
  operator delete[](callbackParam);
  return 0;
}

// File Line: 567
// RVA: 0x228530
void __fastcall UFG::StreamFileWrapper::Close(void *hFile)
{
  UFG::qNode<UFG::StreamFileWrapper::StreamFile,UFG::StreamFileWrapper::StreamFile> *v1; // rbx
  UFG::qNode<UFG::StreamFileWrapper::StreamFile,UFG::StreamFileWrapper::StreamFile> *v2; // rax
  UFG::qNode<UFG::StreamFileWrapper::StreamFile,UFG::StreamFileWrapper::StreamFile> *v3; // rdx
  UFG::qNode<UFG::StreamFileWrapper::StreamFile,UFG::StreamFileWrapper::StreamFile> *v4; // rax

  v1 = (UFG::qNode<UFG::StreamFileWrapper::StreamFile,UFG::StreamFileWrapper::StreamFile> *)hFile;
  if ( !*((_QWORD *)hFile + 4) )
  {
    UFG::qClose(*((UFG::qFile **)hFile + 7));
    v1[3].mNext = 0i64;
  }
  UFG::qMutex::Lock((LPCRITICAL_SECTION)&UFG::StreamFileWrapper::smStreamFilemMutex);
  v2 = v1->mNext;
  v3 = v1->mPrev;
  v3->mNext = v2;
  v2->mPrev = v3;
  v1->mPrev = v1;
  v1->mNext = v1;
  v4 = UFG::StreamFileWrapper::smClosedStreamFiles.mNode.mPrev;
  UFG::StreamFileWrapper::smClosedStreamFiles.mNode.mPrev->mNext = v1;
  v1->mPrev = v4;
  v1->mNext = (UFG::qNode<UFG::StreamFileWrapper::StreamFile,UFG::StreamFileWrapper::StreamFile> *)&UFG::StreamFileWrapper::smClosedStreamFiles;
  UFG::StreamFileWrapper::smClosedStreamFiles.mNode.mPrev = v1;
  UFG::qMutex::Unlock((LPCRITICAL_SECTION)&UFG::StreamFileWrapper::smStreamFilemMutex);
}

// File Line: 587
// RVA: 0x2290D0
bool __fastcall UFG::StreamFileWrapper::FileExists(const char *filename)
{
  bool result; // al
  UFG::BIGFileIndex::Entry *_entry; // [rsp+38h] [rbp+10h]
  UFG::BIGFileIndex *_bigFile; // [rsp+40h] [rbp+18h]

  _entry = 0i64;
  if ( UFG::BigFileSystem::GetFileInfoFromBigFile(filename, &_bigFile, &_entry) == 1 )
    result = _entry->size.uncompressed_size > 0;
  else
    result = 0;
  return result;
}

// File Line: 641
// RVA: 0x229AF0
__int64 __fastcall UFG::StreamFileWrapper::GetFileSizeRaw(void *hFile)
{
  __int64 result; // rax

  if ( *((_QWORD *)hFile + 4) )
    result = 0i64;
  else
    result = UFG::qGetFileSize(*((UFG::qFile **)hFile + 7));
  return result;
}

// File Line: 656
// RVA: 0x229A70
void __fastcall UFG::StreamFileWrapper::GetFileSize(const char *filename, UFG::BIGFileSize *fileSize)
{
  UFG::BIGFileSize *v2; // rbx
  const char *v3; // rdi
  UFG::BIGFileIndex::Entry *v4; // rcx
  unsigned int v5; // eax
  UFG::BIGFileIndex::Entry *_entry; // [rsp+40h] [rbp+18h]
  UFG::BIGFileIndex *_bigFile; // [rsp+48h] [rbp+20h]

  v2 = fileSize;
  v3 = filename;
  _entry = 0i64;
  if ( UFG::BigFileSystem::GetFileInfoFromBigFile(filename, &_bigFile, &_entry) == 1 )
  {
    v4 = _entry;
    v2->load_offset = _entry->size.load_offset;
    v2->compressed_size = v4->size.compressed_size;
    v2->compressed_extra = v4->size.compressed_extra;
    v2->uncompressed_size = v4->size.uncompressed_size;
  }
  else
  {
    v5 = UFG::qGetFileSize(v3);
    v2->load_offset = 0;
    v2->compressed_extra = 0;
    v2->compressed_size = v5;
    v2->uncompressed_size = v5;
  }
}

// File Line: 670
// RVA: 0x229610
__int64 __fastcall UFG::StreamFileWrapper::GetAllocationSize(const char *filename)
{
  const char *v1; // rbx
  __int64 result; // rax
  UFG::BIGFileIndex::Entry *_entry; // [rsp+38h] [rbp+10h]
  UFG::BIGFileIndex *_bigFile; // [rsp+40h] [rbp+18h]

  v1 = filename;
  _entry = 0i64;
  if ( UFG::BigFileSystem::GetFileInfoFromBigFile(filename, &_bigFile, &_entry) == 1 )
    result = _entry->size.compressed_extra + _entry->size.uncompressed_size;
  else
    result = UFG::qGetFileSize(v1);
  return result;
}

// File Line: 684
// RVA: 0x228D10
void __fastcall UFG::StreamFileWrapper::EnableLogging(bool bEnable)
{
  UFG::StreamFileWrapper::smbEnableLogging = bEnable;
}

// File Line: 737
// RVA: 0x22E2E0
void __fastcall UFG::StreamFileWrapper::SetQueueMode(UFG::StreamFileWrapper::QUEUE_MODE eQueueMode)
{
  UFG::StreamFileWrapper::smeQueueMode = eQueueMode;
}

// File Line: 817
// RVA: 0x22E4A0
void __fastcall UFG::StreamFileWrapper::StreamFileWrapperFileCallback(UFG::qFileOp *file_op, void *callback_param)
{
  void (__fastcall *v2)(UFG::qFileOp *, _QWORD); // rax
  UFG::qNode<UFG::StreamFileWrapper::StreamReadOp,UFG::StreamFileWrapper::StreamReadOp> *v3; // rbx
  UFG::qNode<UFG::StreamFileWrapper::StreamReadOp,UFG::StreamFileWrapper::StreamReadOp> *v4; // rax
  UFG::qNode<UFG::StreamFileWrapper::StreamReadOp,UFG::StreamFileWrapper::StreamReadOp> *v5; // rdx
  UFG::qNode<UFG::StreamFileWrapper::StreamReadOp,UFG::StreamFileWrapper::StreamReadOp> *v6; // rax

  v2 = (void (__fastcall *)(UFG::qFileOp *, _QWORD))*((_QWORD *)callback_param + 5);
  v3 = (UFG::qNode<UFG::StreamFileWrapper::StreamReadOp,UFG::StreamFileWrapper::StreamReadOp> *)callback_param;
  if ( v2 )
    v2(file_op, *((_QWORD *)callback_param + 6));
  UFG::qMutex::Lock((LPCRITICAL_SECTION)&UFG::StreamFileWrapper::smStreamFilemMutex);
  v4 = v3->mNext;
  v5 = v3->mPrev;
  v5->mNext = v4;
  v4->mPrev = v5;
  v3->mPrev = v3;
  v3->mNext = v3;
  WORD1(v3[1].mNext) = 2;
  v6 = UFG::StreamFileWrapper::smCompletedReads.mNode.mPrev;
  UFG::StreamFileWrapper::smCompletedReads.mNode.mPrev->mNext = v3;
  v3->mPrev = v6;
  v3->mNext = (UFG::qNode<UFG::StreamFileWrapper::StreamReadOp,UFG::StreamFileWrapper::StreamReadOp> *)&UFG::StreamFileWrapper::smCompletedReads;
  UFG::StreamFileWrapper::smCompletedReads.mNode.mPrev = v3;
  UFG::qMutex::Unlock((LPCRITICAL_SECTION)&UFG::StreamFileWrapper::smStreamFilemMutex);
}

// File Line: 841
// RVA: 0x2285B0
__int64 __fastcall UFG::StreamFileWrapper::DBGGetInfoFromFileOpParam(void *param, UFG::StreamFileWrapper::DebugInfo *info)
{
  UFG::StreamFileWrapper::DebugInfo *v2; // rsi
  UFG::qNode<UFG::StreamFileWrapper::StreamReadOp,UFG::StreamFileWrapper::StreamReadOp> *v3; // rdi
  unsigned __int8 v4; // bp
  UFG::qNode<UFG::StreamFileWrapper::StreamReadOp,UFG::StreamFileWrapper::StreamReadOp> *v5; // rbx
  UFG::qNode<UFG::StreamFileWrapper::StreamReadOp,UFG::StreamFileWrapper::StreamReadOp> *v6; // rax
  int v7; // ecx
  const char *v8; // rax
  bool v9; // zf
  UFG::qFile *v10; // rcx
  char *v11; // rax
  UFG::qNode<UFG::StreamFileWrapper::StreamReadOp,UFG::StreamFileWrapper::StreamReadOp> *v12; // rbx
  UFG::qNode<UFG::StreamFileWrapper::StreamReadOp,UFG::StreamFileWrapper::StreamReadOp> *v13; // rax
  const char *v14; // rax
  UFG::qFile *v15; // rcx
  char *v16; // rax

  v2 = info;
  v3 = (UFG::qNode<UFG::StreamFileWrapper::StreamReadOp,UFG::StreamFileWrapper::StreamReadOp> *)param;
  v4 = 0;
  UFG::qMutex::Lock((LPCRITICAL_SECTION)&UFG::StreamFileWrapper::smStreamFilemMutex);
  UFG::qString::Set(&v2->mFilename, 0i64);
  v2->mPriority = 0;
  v2->mSortKey = 0i64;
  v5 = UFG::StreamFileWrapper::smInProgressReads.mNode.mNext;
  if ( (UFG::qList<UFG::StreamFileWrapper::StreamReadOp,UFG::StreamFileWrapper::StreamReadOp,1,0> *)UFG::StreamFileWrapper::smInProgressReads.mNode.mNext != &UFG::StreamFileWrapper::smInProgressReads )
  {
    while ( v5 != v3 )
    {
      v5 = v5->mNext;
      if ( v5 == (UFG::qNode<UFG::StreamFileWrapper::StreamReadOp,UFG::StreamFileWrapper::StreamReadOp> *)&UFG::StreamFileWrapper::smInProgressReads )
        goto LABEL_11;
    }
    v2->mPriority = SWORD2(v5[1].mNext);
    v6 = v5[2].mPrev;
    v7 = (int)v6[1].mNext;
    if ( v7 == 1 )
    {
      v8 = UFG::BigFileSystem::GetFilenameDBG((unsigned int)v6[2].mNext->mPrev);
      UFG::qString::Set(&v2->mFilename, v8);
      v2->mSortKey = (unsigned __int64)v5[2].mPrev[1].mPrev
                   + (4 * (unsigned __int64)HIDWORD(v5[2].mPrev[2].mNext->mPrev) >> 11);
    }
    else
    {
      v9 = v7 == 2;
      v10 = (UFG::qFile *)v6[3].mNext;
      if ( v9 || v10 )
      {
        v11 = UFG::qGetFileName(v10);
        UFG::qString::Set(&v2->mFilename, v11);
        v2->mSortKey = (unsigned __int64)v5[2].mPrev[1].mPrev + (_QWORD)v5[1].mPrev / 2048i64;
      }
    }
    v4 = 1;
  }
LABEL_11:
  v12 = UFG::StreamFileWrapper::smCompletedReads.mNode.mNext;
  if ( (UFG::qList<UFG::StreamFileWrapper::StreamReadOp,UFG::StreamFileWrapper::StreamReadOp,1,0> *)UFG::StreamFileWrapper::smCompletedReads.mNode.mNext != &UFG::StreamFileWrapper::smCompletedReads )
  {
    while ( v12 != v3 )
    {
      v12 = v12->mNext;
      if ( v12 == (UFG::qNode<UFG::StreamFileWrapper::StreamReadOp,UFG::StreamFileWrapper::StreamReadOp> *)&UFG::StreamFileWrapper::smCompletedReads )
        goto LABEL_20;
    }
    v2->mPriority = SWORD2(v12[1].mNext);
    v13 = v12[2].mPrev;
    if ( v13[2].mPrev )
    {
      v14 = UFG::BigFileSystem::GetFilenameDBG((unsigned int)v13[2].mNext->mPrev);
      UFG::qString::Set(&v2->mFilename, v14);
      v2->mSortKey = (unsigned __int64)v12[2].mPrev[1].mPrev
                   + (4 * (unsigned __int64)HIDWORD(v12[2].mPrev[2].mNext->mPrev) >> 11);
    }
    else
    {
      v15 = (UFG::qFile *)v13[3].mNext;
      if ( v15 )
      {
        v16 = UFG::qGetFileName(v15);
        UFG::qString::Set(&v2->mFilename, v16);
        v2->mSortKey = (unsigned __int64)v12[2].mPrev[1].mPrev + (_QWORD)v12[1].mPrev / 2048i64;
      }
    }
    v4 = 1;
  }
LABEL_20:
  UFG::qMutex::Unlock((LPCRITICAL_SECTION)&UFG::StreamFileWrapper::smStreamFilemMutex);
  return v4;
}

// File Line: 916
// RVA: 0x228E80
__int64 __fastcall UFG::StreamFileWrapper::ExecuteReadOp(UFG::StreamFileWrapper::StreamReadOp *readOp)
{
  UFG::StreamFileWrapper::StreamFile *v1; // rax
  UFG::StreamFileWrapper::StreamReadOp *callback_param; // rdx
  UFG::qFileSeekType seek_type; // er10
  signed __int64 v4; // r9
  bool v5; // zf
  __int64 read_bytes; // rax
  bool v7; // cl
  unsigned int v8; // edi
  __int64 read_data_offset; // r11
  __int64 read_offset; // rdi
  __int64 v11; // r8
  UFG::qFile *v12; // rcx
  __int64 result; // rax
  __int64 v14; // r8
  UFG::qFile *v15; // rcx

  v1 = readOp->mpStreamFile;
  callback_param = readOp;
  if ( v1->mBigFile && v1->mFileType == 1 )
  {
    seek_type = 0;
    v4 = 4i64 * v1->mpEntry->offset_div_4;
  }
  else
  {
    if ( v1->mFileType == 2 )
      ++v1->mpPackedAudioFileData->mReadCount;
    seek_type = readOp->mSeekType.mValue;
    v4 = readOp->mSeekOffset;
  }
  v5 = readOp->mCallback == 0i64;
  read_bytes = readOp->mFileSize.compressed_size;
  readOp->mState.mValue = 1;
  v7 = !v5;
  if ( (_DWORD)read_bytes && (_DWORD)read_bytes != callback_param->mFileSize.uncompressed_size )
  {
    v8 = callback_param->mFileSize.load_offset;
    read_data_offset = v8 & 0xFFF;
    read_offset = v8 & 0xFFFFF000;
    v11 = callback_param->mFileSize.compressed_extra + callback_param->mFileSize.uncompressed_size;
    v5 = v7 == 0;
    v12 = callback_param->mpStreamFile->mpFile;
    if ( v5 )
    {
      result = UFG::qReadAndDecompress(
                 v12,
                 callback_param->mpBuffer,
                 v11,
                 v4,
                 seek_type,
                 read_offset,
                 read_bytes,
                 read_data_offset,
                 0i64,
                 0i64,
                 1);
    }
    else
    {
      UFG::qReadAndDecompressAsync(
        v12,
        callback_param->mpBuffer,
        v11,
        v4,
        seek_type,
        read_offset,
        read_bytes,
        read_data_offset,
        0i64,
        0i64,
        1,
        UFG::StreamFileWrapper::StreamFileWrapperFileCallback,
        callback_param,
        QPRIORITY_NORMAL);
      result = 0i64;
    }
  }
  else
  {
    v14 = callback_param->mFileSize.uncompressed_size;
    v5 = v7 == 0;
    v15 = callback_param->mpStreamFile->mpFile;
    if ( v5 )
    {
      result = UFG::qRead(v15, callback_param->mpBuffer, v14, v4, seek_type);
    }
    else
    {
      UFG::qReadAsync(
        v15,
        callback_param->mpBuffer,
        v14,
        v4,
        seek_type,
        UFG::StreamFileWrapper::StreamFileWrapperFileCallback,
        callback_param,
        QPRIORITY_NORMAL);
      result = 0i64;
    }
  }
  return result;
}

// File Line: 1050
// RVA: 0x22C5C0
__int64 __fastcall UFG::StreamFileWrapper::Read(void *hFile, UFG::StreamFileWrapper::QUEUE_CLASS queueClass, void *buffer, UFG::BIGFileSize *fileSize, void (__fastcall *callback)(UFG::qFileOp *, void *), void *callbackParam)
{
  return UFG::StreamFileWrapper::Read(hFile, queueClass, buffer, fileSize, 0i64, 0, callback, callbackParam, 0);
}

// File Line: 1064
// RVA: 0x22C610
__int64 __fastcall UFG::StreamFileWrapper::Read(void *hFile, UFG::StreamFileWrapper::QUEUE_CLASS queueClass, void *buffer, UFG::BIGFileSize *fileSize, __int64 seek_offset, UFG::qFileSeekType seek_type, void (__fastcall *callback)(UFG::qFileOp *, void *), void *callbackParam, unsigned int audioPriority)
{
  UFG::BIGFileSize *v9; // rbx
  void *v10; // r14
  __int64 v11; // rbp
  UFG::StreamFileWrapper::StreamFile *v12; // r15
  UFG::allocator::free_link *v13; // rax
  UFG::StreamFileWrapper::StreamReadOp *v14; // rdi
  __int64 v15; // rsi
  __int64 v16; // rbx
  UFG::StreamFileWrapper::StreamReadQueue *v17; // rbp
  UFG::StreamFileWrapper::StreamFile *v18; // rcx
  unsigned __int64 v19; // rsi
  UFG::qNode<UFG::StreamFileWrapper::StreamReadOp,UFG::StreamFileWrapper::StreamReadOp> *v20; // rdx
  UFG::qNode<UFG::StreamFileWrapper::StreamReadOp,UFG::StreamFileWrapper::StreamReadOp> *v21; // rax
  __int64 v23; // rbx
  UFG::qNode<UFG::StreamFileWrapper::StreamReadOp,UFG::StreamFileWrapper::StreamReadOp> *v24; // r8
  UFG::qNode<UFG::StreamFileWrapper::StreamReadOp,UFG::StreamFileWrapper::StreamReadOp> *v25; // rdx

  v9 = fileSize;
  v10 = buffer;
  v11 = queueClass;
  v12 = (UFG::StreamFileWrapper::StreamFile *)hFile;
  v13 = UFG::qMalloc(0x58ui64, "StreamReadOp", 0x800ui64);
  v14 = (UFG::StreamFileWrapper::StreamReadOp *)v13;
  if ( v13 )
  {
    v13->mNext = v13;
    v13[1].mNext = v13;
    v15 = 0i64;
    v13[2].mNext = 0i64;
    LODWORD(v13[3].mNext) = 1;
    WORD2(v13[3].mNext) = 3;
    v13[4].mNext = 0i64;
    v13[5].mNext = 0i64;
    v13[6].mNext = 0i64;
    v13[7].mNext = 0i64;
    v13[8].mNext = 0i64;
    v13[9].mNext = 0i64;
    ++UFG::StreamFileWrapper::StreamReadOp::smTotalReadOpCount;
  }
  else
  {
    v15 = 0i64;
    v14 = 0i64;
  }
  v14->mpStreamFile = v12;
  v14->mState.mValue = 0;
  v14->mQueueClass.mValue = v11;
  v14->mpBuffer = v10;
  v14->mFileSize.load_offset = v9->load_offset;
  v14->mFileSize.compressed_size = v9->compressed_size;
  v14->mFileSize.compressed_extra = v9->compressed_extra;
  v14->mFileSize.uncompressed_size = v9->uncompressed_size;
  v14->mSeekOffset = seek_offset;
  v14->mSeekType.mValue = seek_type;
  v14->mCallback = callback;
  v14->mCallbackParam = callbackParam;
  v14->mAudioPriority = audioPriority;
  if ( callback )
  {
    v16 = v11;
    v17 = &UFG::StreamFileWrapper::smPendingQueues[v11];
    UFG::qMutex::Lock((LPCRITICAL_SECTION)&v17->mQueueMutex);
    v18 = v14->mpStreamFile;
    if ( v18->mBigFile )
    {
      v19 = 4 * (unsigned __int64)v18->mpEntry->offset_div_4 >> 11;
    }
    else
    {
      if ( !v18->mpFile )
      {
LABEL_10:
        UFG::StreamFileWrapper::smPendingQueues[v16].mLastDiskSortKey = v15;
        v20 = &UFG::StreamFileWrapper::smPendingQueues[v16].mPendingReads.mNode;
        v21 = v20->mPrev;
        v21->mNext = (UFG::qNode<UFG::StreamFileWrapper::StreamReadOp,UFG::StreamFileWrapper::StreamReadOp> *)&v14->mPrev;
        v14->mPrev = v21;
        v14->mNext = v20;
        v20->mPrev = (UFG::qNode<UFG::StreamFileWrapper::StreamReadOp,UFG::StreamFileWrapper::StreamReadOp> *)&v14->mPrev;
        UFG::qMutex::Unlock((LPCRITICAL_SECTION)&v17->mQueueMutex);
        return 0i64;
      }
      v19 = v14->mSeekOffset / 2048;
    }
    v15 = v18->mSortKey + v19;
    goto LABEL_10;
  }
  v23 = UFG::StreamFileWrapper::ExecuteReadOp(v14);
  --UFG::StreamFileWrapper::StreamReadOp::smTotalReadOpCount;
  v24 = v14->mPrev;
  v25 = v14->mNext;
  v24->mNext = v25;
  v25->mPrev = v24;
  v14->mPrev = (UFG::qNode<UFG::StreamFileWrapper::StreamReadOp,UFG::StreamFileWrapper::StreamReadOp> *)&v14->mPrev;
  v14->mNext = (UFG::qNode<UFG::StreamFileWrapper::StreamReadOp,UFG::StreamFileWrapper::StreamReadOp> *)&v14->mPrev;
  operator delete[](v14);
  return v23;
}

// File Line: 1135
// RVA: 0x22EF50
bool __fastcall UFG::StreamFileWrapper::fnAudioPrioritySort(UFG::StreamFileWrapper::StreamReadOp *a, UFG::StreamFileWrapper::StreamReadOp *b)
{
  UFG::StreamFileWrapper::StreamFile *v2; // r9
  UFG::StreamFileWrapper::StreamReadOp *v3; // r10
  unsigned __int64 v4; // r8
  UFG::StreamFileWrapper::StreamFile *v5; // rdx
  unsigned int v6; // er8
  unsigned int v7; // ecx

  v2 = a->mpStreamFile;
  v3 = b;
  if ( v2->mBigFile )
    v4 = 4i64 * v2->mpEntry->offset_div_4;
  else
    v4 = a->mSeekOffset;
  v5 = b->mpStreamFile;
  v6 = LODWORD(v2->mSortKey) + (v4 >> 11);
  if ( v5->mBigFile )
    v7 = LODWORD(v5->mSortKey) + (4 * (unsigned __int64)v5->mpEntry->offset_div_4 >> 11);
  else
    v7 = LODWORD(v5->mSortKey) + ((unsigned __int64)v3->mSeekOffset >> 11);
  return v6 > v7;
}

// File Line: 1221
// RVA: 0x228D70
__int64 __fastcall UFG::StreamFileWrapper::ExecuteQueue(unsigned int queueIndex, unsigned int *opsToExecute, bool onlyOneInProgressAtATime)
{
  unsigned int v3; // ebp
  bool v4; // r15
  unsigned int *v5; // r14
  UFG::StreamFileWrapper::StreamReadQueue *v6; // rsi
  UFG::StreamFileWrapper::StreamReadOp *v7; // rbx
  UFG::qNode<UFG::StreamFileWrapper::StreamReadOp,UFG::StreamFileWrapper::StreamReadOp> *v8; // rdx
  UFG::qNode<UFG::StreamFileWrapper::StreamReadOp,UFG::StreamFileWrapper::StreamReadOp> *v9; // rax
  UFG::qNode<UFG::StreamFileWrapper::StreamReadOp,UFG::StreamFileWrapper::StreamReadOp> *v10; // rcx

  v3 = *opsToExecute;
  v4 = onlyOneInProgressAtATime;
  v5 = opsToExecute;
  v6 = &UFG::StreamFileWrapper::smPendingQueues[queueIndex];
  if ( *opsToExecute )
  {
    do
    {
      if ( v4
        && (UFG::qList<UFG::StreamFileWrapper::StreamReadOp,UFG::StreamFileWrapper::StreamReadOp,1,0> *)UFG::StreamFileWrapper::smInProgressReads.mNode.mNext != &UFG::StreamFileWrapper::smInProgressReads )
      {
        break;
      }
      v7 = 0i64;
      UFG::qMutex::Lock((LPCRITICAL_SECTION)&v6->mQueueMutex);
      if ( (UFG::qList<UFG::StreamFileWrapper::StreamReadOp,UFG::StreamFileWrapper::StreamReadOp,1,0> *)v6->mPendingReads.mNode.mNext != &v6->mPendingReads )
      {
        v7 = (UFG::StreamFileWrapper::StreamReadOp *)v6->mPendingReads.mNode.mNext;
        v8 = v7->mPrev;
        v9 = v7->mNext;
        v8->mNext = v9;
        v9->mPrev = v8;
        v7->mPrev = (UFG::qNode<UFG::StreamFileWrapper::StreamReadOp,UFG::StreamFileWrapper::StreamReadOp> *)&v7->mPrev;
        v7->mNext = (UFG::qNode<UFG::StreamFileWrapper::StreamReadOp,UFG::StreamFileWrapper::StreamReadOp> *)&v7->mPrev;
      }
      UFG::qMutex::Unlock((LPCRITICAL_SECTION)&v6->mQueueMutex);
      if ( !v7 )
        break;
      UFG::StreamFileWrapper::ExecuteReadOp(v7);
      UFG::qMutex::Lock((LPCRITICAL_SECTION)&UFG::StreamFileWrapper::smStreamFilemMutex);
      v10 = UFG::StreamFileWrapper::smInProgressReads.mNode.mPrev;
      UFG::StreamFileWrapper::smInProgressReads.mNode.mPrev->mNext = (UFG::qNode<UFG::StreamFileWrapper::StreamReadOp,UFG::StreamFileWrapper::StreamReadOp> *)&v7->mPrev;
      v7->mPrev = v10;
      v7->mNext = (UFG::qNode<UFG::StreamFileWrapper::StreamReadOp,UFG::StreamFileWrapper::StreamReadOp> *)&UFG::StreamFileWrapper::smInProgressReads;
      UFG::StreamFileWrapper::smInProgressReads.mNode.mPrev = (UFG::qNode<UFG::StreamFileWrapper::StreamReadOp,UFG::StreamFileWrapper::StreamReadOp> *)&v7->mPrev;
      UFG::qMutex::Unlock((LPCRITICAL_SECTION)&UFG::StreamFileWrapper::smStreamFilemMutex);
    }
    while ( (*v5)-- != 1 );
  }
  return v3 - *v5;
}

// File Line: 1273
// RVA: 0x22E2F0
void __fastcall UFG::StreamFileWrapper::SetSupressCaching_HighSpeed(bool supress)
{
  UFG::StreamFileWrapper::smbSupressCaching_HighSpeed = supress;
}

// File Line: 1278
// RVA: 0x22E300
void __fastcall UFG::StreamFileWrapper::SetSupressCaching_Loading(bool supress)
{
  UFG::StreamFileWrapper::smbSupressCaching_Loading = supress;
}

// File Line: 1283
// RVA: 0x22E310
void __fastcall UFG::StreamFileWrapper::SetSupressCaching_Splash(bool supress)
{
  UFG::StreamFileWrapper::smbSupressCaching_Splash = supress;
}

// File Line: 1292
// RVA: 0x2284C0
void __fastcall UFG::StreamFileWrapper::CachingCallback(const char *filename, bool cached, void *callback_param)
{
  const char *v3; // rbx
  UFG::qList<UFG::StreamFileWrapper::StreamFile,UFG::StreamFileWrapper::StreamFile,1,0> *i; // rax
  UFG::qNode<UFG::StreamFileWrapper::StreamFile,UFG::StreamFileWrapper::StreamFile> *v5; // rdx

  v3 = filename;
  UFG::qMutex::Lock((LPCRITICAL_SECTION)&UFG::StreamFileWrapper::smStreamFilemMutex);
  UFG::BigFileSystem::ReopenBigFile(v3);
  for ( i = (UFG::qList<UFG::StreamFileWrapper::StreamFile,UFG::StreamFileWrapper::StreamFile,1,0> *)UFG::StreamFileWrapper::smStreamFiles.mNode.mNext;
        i != &UFG::StreamFileWrapper::smStreamFiles;
        i = (UFG::qList<UFG::StreamFileWrapper::StreamFile,UFG::StreamFileWrapper::StreamFile,1,0> *)i->mNode.mNext )
  {
    v5 = i[2].mNode.mPrev;
    if ( v5 )
      i[3].mNode.mNext = v5[7].mPrev;
  }
  UFG::qMutex::Unlock((LPCRITICAL_SECTION)&UFG::StreamFileWrapper::smStreamFilemMutex);
}

// File Line: 1344
// RVA: 0x228D00
void __fastcall UFG::StreamFileWrapper::EnableIncrementalMode(bool incremental)
{
  UFG::StreamFileWrapper::smbIncrementalMode = incremental;
}

// File Line: 1351
// RVA: 0x22DE60
void __fastcall UFG::StreamFileWrapper::Service(float deltaTime)
{
  unsigned int v1; // eax
  bool v2; // si
  int v3; // ebx
  unsigned int v4; // edi
  UFG::qList<UFG::StreamFileWrapper::StreamReadOp,UFG::StreamFileWrapper::StreamReadOp,1,0> *i; // rax
  UFG::qList<UFG::StreamFileWrapper::StreamReadOp,UFG::StreamFileWrapper::StreamReadOp,1,0> *j; // rax
  UFG::qNode<UFG::StreamFileWrapper::StreamReadOp,UFG::StreamFileWrapper::StreamReadOp> *k; // rdx
  UFG::qNode<UFG::StreamFileWrapper::StreamReadOp,UFG::StreamFileWrapper::StreamReadOp> *v8; // rcx
  UFG::qNode<UFG::StreamFileWrapper::StreamReadOp,UFG::StreamFileWrapper::StreamReadOp> *v9; // rax
  UFG::qNode<UFG::StreamFileWrapper::StreamReadOp,UFG::StreamFileWrapper::StreamReadOp> *v10; // rcx
  UFG::qNode<UFG::StreamFileWrapper::StreamReadOp,UFG::StreamFileWrapper::StreamReadOp> *v11; // rax
  UFG::qNode<UFG::StreamFileWrapper::StreamFile,UFG::StreamFileWrapper::StreamFile> *l; // rbx
  UFG::qNode<UFG::StreamFileWrapper::StreamFile,UFG::StreamFileWrapper::StreamFile> *v13; // rcx
  UFG::qNode<UFG::StreamFileWrapper::StreamFile,UFG::StreamFileWrapper::StreamFile> *v14; // rax
  UFG::qNode<UFG::StreamFileWrapper::StreamFile,UFG::StreamFileWrapper::StreamFile> *v15; // rcx
  UFG::qNode<UFG::StreamFileWrapper::StreamFile,UFG::StreamFileWrapper::StreamFile> *v16; // rcx
  UFG::qNode<UFG::StreamFileWrapper::StreamFile,UFG::StreamFileWrapper::StreamFile> *v17; // rax
  bool v18; // di
  UFG::qNode<UFG::StreamFileWrapper::StreamFile,UFG::StreamFileWrapper::StreamFile> *m; // rbx
  UFG::qNode<UFG::StreamFileWrapper::StreamFile,UFG::StreamFileWrapper::StreamFile> *v20; // rcx
  UFG::qNode<UFG::StreamFileWrapper::StreamFile,UFG::StreamFileWrapper::StreamFile> *v21; // rax
  UFG::qNode<UFG::StreamFileWrapper::StreamFile,UFG::StreamFileWrapper::StreamFile> *v22; // rcx
  UFG::qNode<UFG::StreamFileWrapper::StreamFile,UFG::StreamFileWrapper::StreamFile> *v23; // rdx
  UFG::qNode<UFG::StreamFileWrapper::StreamFile,UFG::StreamFileWrapper::StreamFile> *v24; // rax
  AMD_HD3D *v25; // rcx
  int v26; // edx
  hkGeometryUtils::IVertices *v27; // rcx
  int v28; // er8
  bool game_streaming; // [rsp+60h] [rbp+8h]
  bool disk_caching; // [rsp+68h] [rbp+10h]
  unsigned int opsToExecute; // [rsp+70h] [rbp+18h]

  accum_audio_low_priority = accum_audio_low_priority + deltaTime;
  accum_audio_high_priority = accum_audio_high_priority + deltaTime;
  time_since_last_queue = time_since_last_queue + deltaTime;
  game_streaming = 0;
  disk_caching = 0;
  UFG::MovieHandler::ShouldAllowStreaming(&UFG::TheMovieHandler, &game_streaming, &disk_caching);
  if ( game_streaming )
  {
    v1 = 0x7FFFFFFF;
    v2 = UFG::StreamFileWrapper::smbIncrementalMode;
    if ( UFG::StreamFileWrapper::smbIncrementalMode )
      v1 = 1;
    opsToExecute = v1;
    UFG::qMutex::Lock(&stru_142377298);
    UFG::StreamFileWrapper::StreamReadQueue::Sort(
      UFG::StreamFileWrapper::smPendingQueues,
      UFG::StreamFileWrapper::fnAudioPrioritySort);
    UFG::qMutex::Unlock(&stru_142377298);
    if ( (unsigned int)UFG::StreamFileWrapper::ExecuteQueue(0, &opsToExecute, v2) )
      time_since_last_queue = 0.0;
    if ( (unsigned int)UFG::StreamFileWrapper::ExecuteQueue(2u, &opsToExecute, v2) )
      time_since_last_queue = 0.0;
    UFG::qMutex::Lock((LPCRITICAL_SECTION)&UFG::StreamFileWrapper::smStreamFilemMutex);
    v3 = 0;
    v4 = 0;
    for ( i = (UFG::qList<UFG::StreamFileWrapper::StreamReadOp,UFG::StreamFileWrapper::StreamReadOp,1,0> *)UFG::StreamFileWrapper::smInProgressReads.mNode.mNext;
          i != &UFG::StreamFileWrapper::smInProgressReads;
          i = (UFG::qList<UFG::StreamFileWrapper::StreamReadOp,UFG::StreamFileWrapper::StreamReadOp,1,0> *)i->mNode.mNext )
    {
      ++v4;
    }
    UFG::qMutex::Unlock((LPCRITICAL_SECTION)&UFG::StreamFileWrapper::smStreamFilemMutex);
    if ( v4 <= 1 && (unsigned int)UFG::StreamFileWrapper::ExecuteQueue(3u, &opsToExecute, v2) )
      time_since_last_queue = 0.0;
    UFG::qMutex::Lock((LPCRITICAL_SECTION)&UFG::StreamFileWrapper::smStreamFilemMutex);
    for ( j = (UFG::qList<UFG::StreamFileWrapper::StreamReadOp,UFG::StreamFileWrapper::StreamReadOp,1,0> *)UFG::StreamFileWrapper::smInProgressReads.mNode.mNext;
          j != &UFG::StreamFileWrapper::smInProgressReads;
          j = (UFG::qList<UFG::StreamFileWrapper::StreamReadOp,UFG::StreamFileWrapper::StreamReadOp,1,0> *)j->mNode.mNext )
    {
      ++v3;
    }
    UFG::qMutex::Unlock((LPCRITICAL_SECTION)&UFG::StreamFileWrapper::smStreamFilemMutex);
    if ( accum_audio_low_priority > 2.0 || !v3 && time_since_last_queue > 0.5 )
    {
      UFG::qMutex::Lock((LPCRITICAL_SECTION)&stru_1423772D8.mQueueMutex);
      UFG::StreamFileWrapper::StreamReadQueue::Sort(&stru_1423772D8, UFG::StreamFileWrapper::fnAudioPrioritySort);
      UFG::qMutex::Unlock((LPCRITICAL_SECTION)&stru_1423772D8.mQueueMutex);
      UFG::StreamFileWrapper::ExecuteQueue(1u, &opsToExecute, v2);
      if ( accum_audio_low_priority > 2.0 )
        accum_audio_low_priority = accum_audio_low_priority + -2.0;
    }
  }
  UFG::qMutex::Lock((LPCRITICAL_SECTION)&UFG::StreamFileWrapper::smStreamFilemMutex);
  for ( k = UFG::StreamFileWrapper::smCompletedReads.mNode.mNext;
        (UFG::qList<UFG::StreamFileWrapper::StreamReadOp,UFG::StreamFileWrapper::StreamReadOp,1,0> *)UFG::StreamFileWrapper::smCompletedReads.mNode.mNext != &UFG::StreamFileWrapper::smCompletedReads;
        k = UFG::StreamFileWrapper::smCompletedReads.mNode.mNext )
  {
    v8 = k->mPrev;
    v9 = k->mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    k->mPrev = k;
    k->mNext = k;
    *(_QWORD *)&opsToExecute = k;
    --UFG::StreamFileWrapper::StreamReadOp::smTotalReadOpCount;
    v10 = k->mPrev;
    v11 = k->mNext;
    v10->mNext = v11;
    v11->mPrev = v10;
    k->mPrev = k;
    k->mNext = k;
    operator delete[](k);
  }
  for ( l = UFG::StreamFileWrapper::smClosedStreamFiles.mNode.mNext;
        (UFG::qList<UFG::StreamFileWrapper::StreamFile,UFG::StreamFileWrapper::StreamFile,1,0> *)UFG::StreamFileWrapper::smClosedStreamFiles.mNode.mNext != &UFG::StreamFileWrapper::smClosedStreamFiles;
        l = UFG::StreamFileWrapper::smClosedStreamFiles.mNode.mNext )
  {
    v13 = l->mPrev;
    v14 = l->mNext;
    v13->mNext = v14;
    v14->mPrev = v13;
    l->mPrev = l;
    l->mNext = l;
    *(_QWORD *)&opsToExecute = l;
    l[3].mNext = (UFG::qNode<UFG::StreamFileWrapper::StreamFile,UFG::StreamFileWrapper::StreamFile> *)-1i64;
    v15 = l[3].mPrev;
    if ( v15 )
      ((void (__fastcall *)(UFG::qNode<UFG::StreamFileWrapper::StreamFile,UFG::StreamFileWrapper::StreamFile> *, signed __int64))v15->mPrev->mPrev)(
        v15,
        1i64);
    v16 = l->mPrev;
    v17 = l->mNext;
    v16->mNext = v17;
    v17->mPrev = v16;
    l->mPrev = l;
    l->mNext = l;
    operator delete[](l);
  }
  v18 = (UFG::qList<UFG::StreamFileWrapper::StreamReadOp,UFG::StreamFileWrapper::StreamReadOp,1,0> *)UFG::StreamFileWrapper::smInProgressReads.mNode.mNext != &UFG::StreamFileWrapper::smInProgressReads
     || !disk_caching;
  UFG::qMutex::Unlock((LPCRITICAL_SECTION)&UFG::StreamFileWrapper::smStreamFilemMutex);
  UFG::qMutex::Lock((LPCRITICAL_SECTION)&UFG::StreamFileWrapper::smAudioStreamFileMutex);
  for ( m = UFG::StreamFileWrapper::smClosedAudioStreamFiles.mNode.mNext;
        (UFG::qList<UFG::StreamFileWrapper::StreamFile,UFG::StreamFileWrapper::StreamFile,1,0> *)UFG::StreamFileWrapper::smClosedAudioStreamFiles.mNode.mNext != &UFG::StreamFileWrapper::smClosedAudioStreamFiles;
        m = UFG::StreamFileWrapper::smClosedAudioStreamFiles.mNode.mNext )
  {
    v20 = m->mPrev;
    v21 = m->mNext;
    v20->mNext = v21;
    v21->mPrev = v20;
    m->mPrev = m;
    m->mNext = m;
    *(_QWORD *)&opsToExecute = m;
    m[3].mNext = (UFG::qNode<UFG::StreamFileWrapper::StreamFile,UFG::StreamFileWrapper::StreamFile> *)-1i64;
    v22 = m[3].mPrev;
    if ( v22 )
      ((void (__fastcall *)(UFG::qNode<UFG::StreamFileWrapper::StreamFile,UFG::StreamFileWrapper::StreamFile> *, signed __int64))v22->mPrev->mPrev)(
        v22,
        1i64);
    v23 = m->mPrev;
    v24 = m->mNext;
    v23->mNext = v24;
    v24->mPrev = v23;
    m->mPrev = m;
    m->mNext = m;
    operator delete[](m);
  }
  UFG::qMutex::Unlock((LPCRITICAL_SECTION)&UFG::StreamFileWrapper::smAudioStreamFileMutex);
  UFG::DiskCache::SetCallback(UFG::StreamFileWrapper::CachingCallback, 0i64);
  _(v25);
  if ( UFG::StreamFileWrapper::smbSupressCaching_HighSpeed
    || UFG::StreamFileWrapper::smbSupressCaching_Loading
    || UFG::StreamFileWrapper::smbSupressCaching_Splash
    || v18 )
  {
    v27 = 0i64;
  }
  else
  {
    LOBYTE(v27) = 1;
  }
  Track<TriggerRecoilPostEffectTask>::DeleteTaskWhenItReturnsFalse(v27, v26, v28);
}

