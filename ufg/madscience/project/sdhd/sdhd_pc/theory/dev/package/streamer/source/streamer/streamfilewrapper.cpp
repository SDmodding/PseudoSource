// File Line: 193
// RVA: 0x227020
void __fastcall UFG::StreamFileWrapper::StreamReadQueue::StreamReadQueue(UFG::StreamFileWrapper::StreamReadQueue *this)
{
  this->mLastDiskSortKey = -1i64;
  UFG::qMutex::qMutex(&this->mQueueMutex, &customCaption);
  this->mPendingReads.mNode.mPrev = &this->mPendingReads.mNode;
  this->mPendingReads.mNode.mNext = &this->mPendingReads.mNode;
}

// File Line: 198
// RVA: 0x22E320
void __fastcall UFG::StreamFileWrapper::StreamReadQueue::Sort(
        UFG::StreamFileWrapper::StreamReadQueue *this,
        bool (__fastcall *fnSort)(UFG::StreamFileWrapper::StreamReadOp *, UFG::StreamFileWrapper::StreamReadOp *))
{
  UFG::qList<UFG::StreamFileWrapper::StreamReadOp,UFG::StreamFileWrapper::StreamReadOp,1,0> *p_mPendingReads; // rsi
  UFG::qNode<UFG::StreamFileWrapper::StreamReadOp,UFG::StreamFileWrapper::StreamReadOp> *mNext; // rbx
  char v5; // bp
  UFG::qList<UFG::StreamFileWrapper::StreamReadOp,UFG::StreamFileWrapper::StreamReadOp,1,0> *v6; // rdi
  UFG::qNode<UFG::StreamFileWrapper::StreamReadOp,UFG::StreamFileWrapper::StreamReadOp> *mPrev; // rdx
  UFG::qNode<UFG::StreamFileWrapper::StreamReadOp,UFG::StreamFileWrapper::StreamReadOp> *v8; // rax
  UFG::qNode<UFG::StreamFileWrapper::StreamReadOp,UFG::StreamFileWrapper::StreamReadOp> *v9; // r8
  UFG::qNode<UFG::StreamFileWrapper::StreamReadOp,UFG::StreamFileWrapper::StreamReadOp> *v10; // rax
  UFG::qNode<UFG::StreamFileWrapper::StreamReadOp,UFG::StreamFileWrapper::StreamReadOp> *v11; // rcx
  UFG::qList<UFG::StreamFileWrapper::StreamReadOp,UFG::StreamFileWrapper::StreamReadOp,1,0> **v12; // rax
  UFG::qNode<UFG::StreamFileWrapper::StreamReadOp,UFG::StreamFileWrapper::StreamReadOp> *v13; // rax

  p_mPendingReads = &this->mPendingReads;
  do
  {
    mNext = p_mPendingReads->mNode.mNext;
    v5 = 0;
    if ( mNext == (UFG::qNode<UFG::StreamFileWrapper::StreamReadOp,UFG::StreamFileWrapper::StreamReadOp> *)p_mPendingReads )
      break;
    do
    {
      v6 = (UFG::qList<UFG::StreamFileWrapper::StreamReadOp,UFG::StreamFileWrapper::StreamReadOp,1,0> *)mNext->mNext;
      if ( v6 == p_mPendingReads )
        break;
      if ( fnSort((UFG::StreamFileWrapper::StreamReadOp *)mNext, (UFG::StreamFileWrapper::StreamReadOp *)mNext->mNext) )
      {
        mPrev = mNext->mPrev;
        v8 = mNext->mNext;
        v9 = v6->mNode.mNext;
        mPrev->mNext = v8;
        v8->mPrev = mPrev;
        mNext->mPrev = mNext;
        mNext->mNext = mNext;
        v10 = v6->mNode.mNext;
        v11 = v6->mNode.mPrev;
        v11->mNext = v10;
        v10->mPrev = v11;
        v6->mNode.mPrev = &v6->mNode;
        v6->mNode.mNext = &v6->mNode;
        v12 = (UFG::qList<UFG::StreamFileWrapper::StreamReadOp,UFG::StreamFileWrapper::StreamReadOp,1,0> **)mPrev->mNext;
        mPrev->mNext = &v6->mNode;
        v6->mNode.mPrev = mPrev;
        v6->mNode.mNext = (UFG::qNode<UFG::StreamFileWrapper::StreamReadOp,UFG::StreamFileWrapper::StreamReadOp> *)v12;
        *v12 = v6;
        v13 = v9->mPrev;
        v5 = 1;
        v13->mNext = mNext;
        mNext->mPrev = v13;
        mNext->mNext = v9;
        v9->mPrev = mNext;
      }
      else
      {
        mNext = &v6->mNode;
      }
    }
    while ( mNext != (UFG::qNode<UFG::StreamFileWrapper::StreamReadOp,UFG::StreamFileWrapper::StreamReadOp> *)p_mPendingReads );
  }
  while ( v5 );
}

// File Line: 286
// RVA: 0x146FC40
__int64 UFG::StreamFileWrapper::_dynamic_initializer_for__smAudioStreamFiles__()
{
  return atexit((int (__fastcall *)())UFG::StreamFileWrapper::_dynamic_atexit_destructor_for__smAudioStreamFiles__);
}

// File Line: 287
// RVA: 0x146FC90
__int64 UFG::StreamFileWrapper::_dynamic_initializer_for__smClosedAudioStreamFiles__()
{
  return atexit((int (__fastcall *)())UFG::StreamFileWrapper::_dynamic_atexit_destructor_for__smClosedAudioStreamFiles__);
}

// File Line: 288
// RVA: 0x146FC10
__int64 UFG::StreamFileWrapper::_dynamic_initializer_for__smAudioStreamFileMutex__()
{
  UFG::qMutex::qMutex(&UFG::StreamFileWrapper::smAudioStreamFileMutex, &customCaption);
  return atexit((int (__fastcall *)())UFG::StreamFileWrapper::_dynamic_atexit_destructor_for__smAudioStreamFileMutex__);
}

// File Line: 290
// RVA: 0x146FE10
__int64 UFG::StreamFileWrapper::_dynamic_initializer_for__smStreamFiles__()
{
  return atexit((int (__fastcall *)())UFG::StreamFileWrapper::_dynamic_atexit_destructor_for__smStreamFiles__);
}

// File Line: 291
// RVA: 0x146FCB0
__int64 UFG::StreamFileWrapper::_dynamic_initializer_for__smClosedStreamFiles__()
{
  return atexit((int (__fastcall *)())UFG::StreamFileWrapper::_dynamic_atexit_destructor_for__smClosedStreamFiles__);
}

// File Line: 293
// RVA: 0x146FD80
__int64 UFG::StreamFileWrapper::_dynamic_initializer_for__smPendingQueues__()
{
  `eh vector constructor iterator(
    (char *)UFG::StreamFileWrapper::smPendingQueues,
    0x48ui64,
    4,
    (void (__fastcall *)(void *))UFG::StreamFileWrapper::StreamReadQueue::StreamReadQueue);
  return atexit((int (__fastcall *)())UFG::StreamFileWrapper::_dynamic_atexit_destructor_for__smPendingQueues__);
}

// File Line: 294
// RVA: 0x146FD30
__int64 UFG::StreamFileWrapper::_dynamic_initializer_for__smInProgressReads__()
{
  return atexit((int (__fastcall *)())UFG::StreamFileWrapper::_dynamic_atexit_destructor_for__smInProgressReads__);
}

// File Line: 295
// RVA: 0x146FCD0
__int64 UFG::StreamFileWrapper::_dynamic_initializer_for__smCompletedReads__()
{
  return atexit((int (__fastcall *)())UFG::StreamFileWrapper::_dynamic_atexit_destructor_for__smCompletedReads__);
}

// File Line: 297
// RVA: 0x146FE30
__int64 UFG::StreamFileWrapper::_dynamic_initializer_for__smStreamLogEntries__()
{
  return atexit((int (__fastcall *)())UFG::StreamFileWrapper::_dynamic_atexit_destructor_for__smStreamLogEntries__);
}

// File Line: 299
// RVA: 0x146FDE0
__int64 UFG::StreamFileWrapper::_dynamic_initializer_for__smStreamFilemMutex__()
{
  UFG::qMutex::qMutex(&UFG::StreamFileWrapper::smStreamFilemMutex, &customCaption);
  return atexit((int (__fastcall *)())UFG::StreamFileWrapper::_dynamic_atexit_destructor_for__smStreamFilemMutex__);
}

// File Line: 310
// RVA: 0x22BBD0
UFG::allocator::free_link *__fastcall UFG::StreamFileWrapper::Open(
        char *filename,
        UFG::qFileAccessType accessType,
        bool bWarnIfFail,
        void (__fastcall *callback)(UFG::qFileOp *, void *),
        void *callback_param)
{
  char FileInfoFromBigFile; // bl
  UFG::BIGFileIndex::Entry *v10; // rdi
  UFG::allocator::free_link *v11; // rax
  UFG::allocator::free_link *v12; // rbx
  UFG::BIGFileIndex *v13; // r8
  UFG::qNode<UFG::StreamFileWrapper::StreamFile,UFG::StreamFileWrapper::StreamFile> *mPrev; // rax
  UFG::qFile *v15; // rax
  UFG::qFile *v16; // rdi
  UFG::allocator::free_link *v17; // rax
  UFG::qNode<UFG::StreamFileWrapper::StreamFile,UFG::StreamFileWrapper::StreamFile> *v18; // rcx
  UFG::BIGFileIndex::Entry *_entry; // [rsp+30h] [rbp-38h] BYREF
  UFG::BIGFileIndex *_bigFile[6]; // [rsp+38h] [rbp-30h] BYREF

  _bigFile[1] = (UFG::BIGFileIndex *)-2i64;
  _bigFile[0] = 0i64;
  _entry = 0i64;
  UFG::qMutex::Lock((LPCRITICAL_SECTION)&UFG::StreamFileWrapper::smStreamFilemMutex);
  FileInfoFromBigFile = UFG::BigFileSystem::GetFileInfoFromBigFile(filename, _bigFile, &_entry);
  UFG::qMutex::Unlock((LPCRITICAL_SECTION)&UFG::StreamFileWrapper::smStreamFilemMutex);
  if ( FileInfoFromBigFile == 1 )
  {
    v10 = _entry;
    if ( _entry->size.uncompressed_size )
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
      v13 = _bigFile[0];
      v12[4].mNext = (UFG::allocator::free_link *)_bigFile[0];
      v12[5].mNext = (UFG::allocator::free_link *)v10;
      v12[7].mNext = (UFG::allocator::free_link *)v13->mpFile;
      v12[2].mNext = (UFG::allocator::free_link *)v13->mSortKey;
      UFG::qMutex::Lock((LPCRITICAL_SECTION)&UFG::StreamFileWrapper::smStreamFilemMutex);
      mPrev = UFG::StreamFileWrapper::smStreamFiles.mNode.mPrev;
      UFG::StreamFileWrapper::smStreamFiles.mNode.mPrev->mNext = (UFG::qNode<UFG::StreamFileWrapper::StreamFile,UFG::StreamFileWrapper::StreamFile> *)v12;
      v12->mNext = (UFG::allocator::free_link *)mPrev;
LABEL_15:
      v12[1].mNext = (UFG::allocator::free_link *)&UFG::StreamFileWrapper::smStreamFiles;
      UFG::StreamFileWrapper::smStreamFiles.mNode.mPrev = (UFG::qNode<UFG::StreamFileWrapper::StreamFile,UFG::StreamFileWrapper::StreamFile> *)v12;
      UFG::qMutex::Unlock((LPCRITICAL_SECTION)&UFG::StreamFileWrapper::smStreamFilemMutex);
      return v12;
    }
  }
  else
  {
    if ( callback )
      v15 = UFG::qOpenAsync(filename, accessType, bWarnIfFail, callback, callback_param, QPRIORITY_NORMAL);
    else
      v15 = UFG::qOpen(filename, accessType, bWarnIfFail);
    v16 = v15;
    if ( v15 )
    {
      v17 = UFG::qMalloc(0x40ui64, "StreamFile", 0x800ui64);
      v12 = v17;
      _bigFile[0] = (UFG::BIGFileIndex *)v17;
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
UFG::allocator::free_link *__fastcall UFG::StreamFileWrapper::OnPackedAudioFileOpen(
        unsigned int fileId,
        _QWORD *packFile,
        __int64 fileSize,
        unsigned int startBlock,
        UFG::TidoFilePackage *in_pPackage)
{
  UFG::allocator::free_link *v7; // rax
  UFG::allocator::free_link *v8; // rbx
  UFG::allocator::free_link *v9; // rax
  __int64 m_iDiscFilePosition; // rax
  UFG::qNode<UFG::StreamFileWrapper::StreamFile,UFG::StreamFileWrapper::StreamFile> *mPrev; // rdx

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
  v8[7].mNext = (UFG::allocator::free_link *)packFile[7];
  v8[4].mNext = 0i64;
  v8[5].mNext = 0i64;
  v9 = UFG::qMalloc(0x18ui64, "StreamFile:PackedAudioFileData", 0x800ui64);
  if ( v9 )
  {
    v9->mNext = (UFG::allocator::free_link *)&UFG::StreamFileWrapper::PackedAudioFileData::`vftable;
    LODWORD(v9[1].mNext) = 0;
    BYTE4(v9[1].mNext) = 0;
    v9[2].mNext = 0i64;
  }
  else
  {
    v9 = 0i64;
  }
  v8[6].mNext = v9;
  LODWORD(v9[1].mNext) = fileId;
  m_iDiscFilePosition = in_pPackage->m_iDiscFilePosition;
  if ( !m_iDiscFilePosition )
  {
    m_iDiscFilePosition = UFG::qGetDiskPosSortKey((UFG::qFile *)v8[7].mNext);
    in_pPackage->m_iDiscFilePosition = m_iDiscFilePosition;
  }
  v8[2].mNext = (UFG::allocator::free_link *)m_iDiscFilePosition;
  UFG::qMutex::Lock((LPCRITICAL_SECTION)&UFG::StreamFileWrapper::smAudioStreamFileMutex);
  mPrev = UFG::StreamFileWrapper::smAudioStreamFiles.mNode.mPrev;
  UFG::StreamFileWrapper::smAudioStreamFiles.mNode.mPrev->mNext = (UFG::qNode<UFG::StreamFileWrapper::StreamFile,UFG::StreamFileWrapper::StreamFile> *)v8;
  v8->mNext = (UFG::allocator::free_link *)mPrev;
  v8[1].mNext = (UFG::allocator::free_link *)&UFG::StreamFileWrapper::smAudioStreamFiles;
  UFG::StreamFileWrapper::smAudioStreamFiles.mNode.mPrev = (UFG::qNode<UFG::StreamFileWrapper::StreamFile,UFG::StreamFileWrapper::StreamFile> *)v8;
  UFG::qMutex::Unlock((LPCRITICAL_SECTION)&UFG::StreamFileWrapper::smAudioStreamFileMutex);
  return v8;
}

// File Line: 441
// RVA: 0x22B920
void __fastcall UFG::StreamFileWrapper::OnPackedAudioFileClose(
        UFG::qNode<UFG::StreamFileWrapper::StreamFile,UFG::StreamFileWrapper::StreamFile> *hFile)
{
  UFG::qNode<UFG::StreamFileWrapper::StreamFile,UFG::StreamFileWrapper::StreamFile> *mNext; // rax
  UFG::qNode<UFG::StreamFileWrapper::StreamFile,UFG::StreamFileWrapper::StreamFile> *mPrev; // rdx
  UFG::qNode<UFG::StreamFileWrapper::StreamFile,UFG::StreamFileWrapper::StreamFile> *v4; // rax

  UFG::qMutex::Lock((LPCRITICAL_SECTION)&UFG::StreamFileWrapper::smAudioStreamFileMutex);
  mNext = hFile->mNext;
  mPrev = hFile->mPrev;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  hFile->mPrev = hFile;
  hFile->mNext = hFile;
  v4 = UFG::StreamFileWrapper::smClosedAudioStreamFiles.mNode.mPrev;
  UFG::StreamFileWrapper::smClosedAudioStreamFiles.mNode.mPrev->mNext = hFile;
  hFile->mPrev = v4;
  hFile->mNext = (UFG::qNode<UFG::StreamFileWrapper::StreamFile,UFG::StreamFileWrapper::StreamFile> *)&UFG::StreamFileWrapper::smClosedAudioStreamFiles;
  UFG::StreamFileWrapper::smClosedAudioStreamFiles.mNode.mPrev = hFile;
  UFG::qMutex::Unlock((LPCRITICAL_SECTION)&UFG::StreamFileWrapper::smAudioStreamFileMutex);
}

// File Line: 454
// RVA: 0x22C7F0
UFG::allocator::free_link *__fastcall UFG::StreamFileWrapper::ReadEntireFile(
        char *filename,
        __int64 *loaded_size,
        UFG::qMemoryPool *memory_pool,
        unsigned int alloc_flags,
        const char *dbg_tag)
{
  unsigned int load_offset; // r13d
  unsigned int compressed_size; // r14d
  unsigned int compressed_extra; // r15d
  unsigned int uncompressed_size; // edi
  UFG::allocator::free_link *result; // rax
  UFG::qFile **v13; // rsi
  UFG::allocator::free_link *v14; // rbp
  UFG::allocator::free_link *v15; // rax
  UFG::allocator::free_link *v16; // rbx
  UFG::allocator::free_link *mNext; // rdx
  UFG::allocator::free_link *v18; // rax
  UFG::BIGFileIndex::Entry *v19[2]; // [rsp+30h] [rbp-48h] BYREF
  UFG::allocator::free_link *v20; // [rsp+40h] [rbp-38h] BYREF

  v19[1] = (UFG::BIGFileIndex::Entry *)-2i64;
  v19[0] = 0i64;
  if ( UFG::BigFileSystem::GetFileInfoFromBigFile(filename, (UFG::BIGFileIndex **)&v20, v19) == 1 )
  {
    load_offset = v19[0]->size.load_offset;
    compressed_size = v19[0]->size.compressed_size;
    compressed_extra = v19[0]->size.compressed_extra;
    uncompressed_size = v19[0]->size.uncompressed_size;
  }
  else
  {
    compressed_size = UFG::qGetFileSize(filename);
    load_offset = 0;
    uncompressed_size = compressed_size;
    compressed_extra = 0;
  }
  result = UFG::StreamFileWrapper::Open(filename, QACCESS_READ, 1, 0i64, 0i64);
  v13 = (UFG::qFile **)result;
  if ( result )
  {
    if ( !memory_pool )
      memory_pool = UFG::gMainMemoryPool;
    v14 = UFG::qMemoryPool::Allocate(memory_pool, uncompressed_size + compressed_extra, dbg_tag, alloc_flags, 1u);
    if ( v14 )
    {
      v15 = UFG::qMalloc(0x58ui64, "StreamReadOp", 0x800ui64);
      v16 = v15;
      v20 = v15;
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
      v16[4].mNext = (UFG::allocator::free_link *)v13;
      *(_DWORD *)((char *)&v16[3].mNext + 2) = 0x20000;
      v16[7].mNext = v14;
      LODWORD(v16[8].mNext) = load_offset;
      HIDWORD(v16[8].mNext) = compressed_size;
      LODWORD(v16[9].mNext) = compressed_extra;
      HIDWORD(v16[9].mNext) = uncompressed_size;
      v16[2].mNext = 0i64;
      LOWORD(v16[3].mNext) = 0;
      v16[5].mNext = 0i64;
      v16[6].mNext = 0i64;
      LODWORD(v16[10].mNext) = 0;
      UFG::StreamFileWrapper::ExecuteReadOp((UFG::StreamFileWrapper::StreamReadOp *)v16);
      v20 = v16;
      --UFG::StreamFileWrapper::StreamReadOp::smTotalReadOpCount;
      mNext = v16->mNext;
      v18 = v16[1].mNext;
      mNext[1].mNext = v18;
      v18->mNext = mNext;
      v16->mNext = v16;
      v16[1].mNext = v16;
      operator delete[](v16);
      if ( loaded_size )
        *loaded_size = uncompressed_size;
    }
    UFG::StreamFileWrapper::Close(v13);
    return v14;
  }
  return result;
}

// File Line: 486
// RVA: 0x22E400
void __fastcall UFG::StreamFileWrapper::StreamFileWrapperEntireFileCallback(UFG::qFileOp *file_op, unsigned int *param)
{
  _QWORD *v4; // rcx
  _QWORD *v5; // rax

  if ( (unsigned int)Scaleform::Render::FileImageSource::GetUse(file_op) == STATUS_WAIT_3 )
  {
    UFG::gFileExecuteTime = UFG::qFileOp::GetExecuteTime(file_op);
    (*((void (__fastcall **)(_QWORD, _QWORD, _QWORD, _QWORD, __int64))param + 10))(
      *((_QWORD *)param + 8),
      *((_QWORD *)param + 12),
      param[9],
      *((_QWORD *)param + 11),
      -2i64);
    UFG::gFileExecuteTime = FLOAT_N1_0;
    UFG::StreamFileWrapper::Close(*((UFG::qFile ***)param + 2));
    UFG::qString::~qString((UFG::qString *)param + 1);
    v4 = *(_QWORD **)param;
    v5 = (_QWORD *)*((_QWORD *)param + 1);
    v4[1] = v5;
    *v5 = v4;
    *(_QWORD *)param = param;
    *((_QWORD *)param + 1) = param;
    operator delete[](param);
  }
}

// File Line: 511
// RVA: 0x22C9C0
char __fastcall UFG::StreamFileWrapper::ReadEntireFileAsync(
        char *filename,
        UFG::StreamFileWrapper::QUEUE_CLASS queueClass,
        UFG::allocator::free_link *callback,
        UFG::allocator::free_link *callback_param,
        UFG::qMemoryPool *memory_pool,
        unsigned int alloc_flags,
        const char *dbg_tag)
{
  UFG::allocator::free_link *v11; // rax
  UFG::allocator::free_link *callbackParam; // rbx
  UFG::allocator::free_link *v13; // rax
  UFG::qMemoryPool *v14; // rcx
  UFG::allocator::free_link *v15; // rax
  UFG::allocator::free_link *mNext; // rdx
  UFG::allocator::free_link *v18; // rax
  UFG::allocator::free_link *v19; // rcx
  UFG::allocator::free_link *v20; // rax

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
  UFG::qString::Set((UFG::qString *)&callbackParam[5], filename);
  callbackParam[10].mNext = callback;
  callbackParam[11].mNext = callback_param;
  UFG::StreamFileWrapper::GetFileSize((char *)callbackParam[8].mNext, (UFG::BIGFileSize *)&callbackParam[3]);
  v13 = UFG::StreamFileWrapper::Open(filename, QACCESS_READ, 1, 0i64, 0i64);
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
        (UFG::StreamFileWrapper::StreamFile *)callbackParam[2].mNext,
        queueClass,
        v15,
        (UFG::BIGFileSize *)&callbackParam[3],
        0i64,
        QSEEK_SET,
        UFG::StreamFileWrapper::StreamFileWrapperEntireFileCallback,
        callbackParam,
        0);
      return 1;
    }
    UFG::StreamFileWrapper::Close((UFG::qFile **)callbackParam[2].mNext);
    callbackParam[2].mNext = 0i64;
    UFG::qString::~qString((UFG::qString *)&callbackParam[5]);
    mNext = callbackParam->mNext;
    v18 = callbackParam[1].mNext;
    mNext[1].mNext = v18;
    v18->mNext = mNext;
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
void __fastcall UFG::StreamFileWrapper::Close(UFG::qFile **hFile)
{
  UFG::qFile *v2; // rax
  UFG::qFile *v3; // rdx
  UFG::qNode<UFG::StreamFileWrapper::StreamFile,UFG::StreamFileWrapper::StreamFile> *mPrev; // rax

  if ( !hFile[4] )
  {
    UFG::qClose(hFile[7]);
    hFile[7] = 0i64;
  }
  UFG::qMutex::Lock((LPCRITICAL_SECTION)&UFG::StreamFileWrapper::smStreamFilemMutex);
  v2 = hFile[1];
  v3 = *hFile;
  v3->mNext = v2;
  v2->mPrev = v3;
  *hFile = (UFG::qFile *)hFile;
  hFile[1] = (UFG::qFile *)hFile;
  mPrev = UFG::StreamFileWrapper::smClosedStreamFiles.mNode.mPrev;
  UFG::StreamFileWrapper::smClosedStreamFiles.mNode.mPrev->mNext = (UFG::qNode<UFG::StreamFileWrapper::StreamFile,UFG::StreamFileWrapper::StreamFile> *)hFile;
  *hFile = (UFG::qFile *)mPrev;
  hFile[1] = (UFG::qFile *)&UFG::StreamFileWrapper::smClosedStreamFiles;
  UFG::StreamFileWrapper::smClosedStreamFiles.mNode.mPrev = (UFG::qNode<UFG::StreamFileWrapper::StreamFile,UFG::StreamFileWrapper::StreamFile> *)hFile;
  UFG::qMutex::Unlock((LPCRITICAL_SECTION)&UFG::StreamFileWrapper::smStreamFilemMutex);
}

// File Line: 587
// RVA: 0x2290D0
bool __fastcall UFG::StreamFileWrapper::FileExists(const char *filename)
{
  UFG::BIGFileIndex::Entry *_entry; // [rsp+38h] [rbp+10h] BYREF
  UFG::BIGFileIndex *_bigFile; // [rsp+40h] [rbp+18h] BYREF

  _entry = 0i64;
  return UFG::BigFileSystem::GetFileInfoFromBigFile(filename, &_bigFile, &_entry) == 1
      && _entry->size.uncompressed_size != 0;
}

// File Line: 641
// RVA: 0x229AF0
__int64 __fastcall UFG::StreamFileWrapper::GetFileSizeRaw(UFG::qFile **hFile)
{
  if ( hFile[4] )
    return 0i64;
  else
    return UFG::qGetFileSize(hFile[7]);
}

// File Line: 656
// RVA: 0x229A70
void __fastcall UFG::StreamFileWrapper::GetFileSize(char *filename, UFG::BIGFileSize *fileSize)
{
  unsigned int v4; // eax
  UFG::BIGFileIndex::Entry *_entry; // [rsp+40h] [rbp+18h] BYREF
  UFG::BIGFileIndex *_bigFile; // [rsp+48h] [rbp+20h] BYREF

  _entry = 0i64;
  if ( UFG::BigFileSystem::GetFileInfoFromBigFile(filename, &_bigFile, &_entry) == 1 )
  {
    *fileSize = _entry->size;
  }
  else
  {
    v4 = UFG::qGetFileSize(filename);
    fileSize->load_offset = 0;
    *(_QWORD *)&fileSize->compressed_size = v4;
    fileSize->uncompressed_size = v4;
  }
}

// File Line: 670
// RVA: 0x229610
__int64 __fastcall UFG::StreamFileWrapper::GetAllocationSize(const char *filename)
{
  UFG::BIGFileIndex::Entry *_entry; // [rsp+38h] [rbp+10h] BYREF
  UFG::BIGFileIndex *_bigFile; // [rsp+40h] [rbp+18h] BYREF

  _entry = 0i64;
  if ( UFG::BigFileSystem::GetFileInfoFromBigFile(filename, &_bigFile, &_entry) == 1 )
    return _entry->size.compressed_extra + _entry->size.uncompressed_size;
  else
    return UFG::qGetFileSize(filename);
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
void __fastcall UFG::StreamFileWrapper::StreamFileWrapperFileCallback(
        UFG::qFileOp *file_op,
        UFG::qNode<UFG::StreamFileWrapper::StreamReadOp,UFG::StreamFileWrapper::StreamReadOp> *callback_param)
{
  UFG::qNode<UFG::StreamFileWrapper::StreamReadOp,UFG::StreamFileWrapper::StreamReadOp> *mNext; // rax
  UFG::qNode<UFG::StreamFileWrapper::StreamReadOp,UFG::StreamFileWrapper::StreamReadOp> *v4; // rax
  UFG::qNode<UFG::StreamFileWrapper::StreamReadOp,UFG::StreamFileWrapper::StreamReadOp> *mPrev; // rdx
  UFG::qNode<UFG::StreamFileWrapper::StreamReadOp,UFG::StreamFileWrapper::StreamReadOp> *v6; // rax

  mNext = callback_param[2].mNext;
  if ( mNext )
    ((void (__fastcall *)(UFG::qFileOp *, UFG::qNode<UFG::StreamFileWrapper::StreamReadOp,UFG::StreamFileWrapper::StreamReadOp> *))mNext)(
      file_op,
      callback_param[3].mPrev);
  UFG::qMutex::Lock((LPCRITICAL_SECTION)&UFG::StreamFileWrapper::smStreamFilemMutex);
  v4 = callback_param->mNext;
  mPrev = callback_param->mPrev;
  mPrev->mNext = v4;
  v4->mPrev = mPrev;
  callback_param->mPrev = callback_param;
  callback_param->mNext = callback_param;
  WORD1(callback_param[1].mNext) = 2;
  v6 = UFG::StreamFileWrapper::smCompletedReads.mNode.mPrev;
  UFG::StreamFileWrapper::smCompletedReads.mNode.mPrev->mNext = callback_param;
  callback_param->mPrev = v6;
  callback_param->mNext = (UFG::qNode<UFG::StreamFileWrapper::StreamReadOp,UFG::StreamFileWrapper::StreamReadOp> *)&UFG::StreamFileWrapper::smCompletedReads;
  UFG::StreamFileWrapper::smCompletedReads.mNode.mPrev = callback_param;
  UFG::qMutex::Unlock((LPCRITICAL_SECTION)&UFG::StreamFileWrapper::smStreamFilemMutex);
}

// File Line: 841
// RVA: 0x2285B0
__int64 __fastcall UFG::StreamFileWrapper::DBGGetInfoFromFileOpParam(
        UFG::qNode<UFG::StreamFileWrapper::StreamReadOp,UFG::StreamFileWrapper::StreamReadOp> *param,
        UFG::StreamFileWrapper::DebugInfo *info)
{
  unsigned __int8 v4; // bp
  UFG::qNode<UFG::StreamFileWrapper::StreamReadOp,UFG::StreamFileWrapper::StreamReadOp> *mNext; // rbx
  UFG::qNode<UFG::StreamFileWrapper::StreamReadOp,UFG::StreamFileWrapper::StreamReadOp> *mPrev; // rax
  int v7; // ecx
  const char *FilenameDBG; // rax
  bool v9; // zf
  UFG::qFile *v10; // rcx
  char *FileName; // rax
  UFG::qNode<UFG::StreamFileWrapper::StreamReadOp,UFG::StreamFileWrapper::StreamReadOp> *v12; // rbx
  UFG::qNode<UFG::StreamFileWrapper::StreamReadOp,UFG::StreamFileWrapper::StreamReadOp> *v13; // rax
  const char *v14; // rax
  UFG::qFile *v15; // rcx
  char *v16; // rax

  v4 = 0;
  UFG::qMutex::Lock((LPCRITICAL_SECTION)&UFG::StreamFileWrapper::smStreamFilemMutex);
  UFG::qString::Set(&info->mFilename, 0i64);
  info->mPriority = 0;
  info->mSortKey = 0i64;
  mNext = UFG::StreamFileWrapper::smInProgressReads.mNode.mNext;
  if ( (UFG::qList<UFG::StreamFileWrapper::StreamReadOp,UFG::StreamFileWrapper::StreamReadOp,1,0> *)UFG::StreamFileWrapper::smInProgressReads.mNode.mNext != &UFG::StreamFileWrapper::smInProgressReads )
  {
    while ( mNext != param )
    {
      mNext = mNext->mNext;
      if ( mNext == (UFG::qNode<UFG::StreamFileWrapper::StreamReadOp,UFG::StreamFileWrapper::StreamReadOp> *)&UFG::StreamFileWrapper::smInProgressReads )
        goto LABEL_11;
    }
    info->mPriority = SWORD2(mNext[1].mNext);
    mPrev = mNext[2].mPrev;
    v7 = (int)mPrev[1].mNext;
    if ( v7 == 1 )
    {
      FilenameDBG = UFG::BigFileSystem::GetFilenameDBG((unsigned int)mPrev[2].mNext->mPrev);
      UFG::qString::Set(&info->mFilename, FilenameDBG);
      info->mSortKey = (unsigned __int64)mNext[2].mPrev[1].mPrev
                     + ((4 * (unsigned __int64)HIDWORD(mNext[2].mPrev[2].mNext->mPrev)) >> 11);
    }
    else
    {
      v9 = v7 == 2;
      v10 = (UFG::qFile *)mPrev[3].mNext;
      if ( v9 || v10 )
      {
        FileName = UFG::qGetFileName(v10);
        UFG::qString::Set(&info->mFilename, FileName);
        info->mSortKey = (unsigned __int64)mNext[2].mPrev[1].mPrev + (__int64)mNext[1].mPrev / 2048;
      }
    }
    v4 = 1;
  }
LABEL_11:
  v12 = UFG::StreamFileWrapper::smCompletedReads.mNode.mNext;
  if ( (UFG::qList<UFG::StreamFileWrapper::StreamReadOp,UFG::StreamFileWrapper::StreamReadOp,1,0> *)UFG::StreamFileWrapper::smCompletedReads.mNode.mNext != &UFG::StreamFileWrapper::smCompletedReads )
  {
    while ( v12 != param )
    {
      v12 = v12->mNext;
      if ( v12 == (UFG::qNode<UFG::StreamFileWrapper::StreamReadOp,UFG::StreamFileWrapper::StreamReadOp> *)&UFG::StreamFileWrapper::smCompletedReads )
        goto LABEL_20;
    }
    info->mPriority = SWORD2(v12[1].mNext);
    v13 = v12[2].mPrev;
    if ( v13[2].mPrev )
    {
      v14 = UFG::BigFileSystem::GetFilenameDBG((unsigned int)v13[2].mNext->mPrev);
      UFG::qString::Set(&info->mFilename, v14);
      info->mSortKey = (unsigned __int64)v12[2].mPrev[1].mPrev
                     + ((4 * (unsigned __int64)HIDWORD(v12[2].mPrev[2].mNext->mPrev)) >> 11);
    }
    else
    {
      v15 = (UFG::qFile *)v13[3].mNext;
      if ( v15 )
      {
        v16 = UFG::qGetFileName(v15);
        UFG::qString::Set(&info->mFilename, v16);
        info->mSortKey = (unsigned __int64)v12[2].mPrev[1].mPrev + (__int64)v12[1].mPrev / 2048;
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
  UFG::StreamFileWrapper::StreamFile *mpStreamFile; // rax
  UFG::qFileSeekType seek_type; // r10d
  __int64 mSeekOffset; // r9
  bool v5; // zf
  __int64 read_bytes; // rax
  bool v7; // cl
  unsigned int load_offset; // edi
  __int64 read_data_offset; // r11
  __int64 read_offset; // rdi
  __int64 v11; // r8
  UFG::qFile *v12; // rcx
  __int64 uncompressed_size; // r8
  UFG::qFile *mpFile; // rcx

  mpStreamFile = readOp->mpStreamFile;
  if ( mpStreamFile->mBigFile && mpStreamFile->mFileType == FILE_TYPE_BIG )
  {
    seek_type = QSEEK_SET;
    mSeekOffset = 4i64 * mpStreamFile->mpEntry->offset_div_4;
  }
  else
  {
    if ( mpStreamFile->mFileType == FILE_TYPE_AUDIO_PACK )
      ++mpStreamFile->mpPackedAudioFileData->mReadCount;
    seek_type = readOp->mSeekType.mValue;
    mSeekOffset = readOp->mSeekOffset;
  }
  v5 = readOp->mCallback == 0i64;
  read_bytes = readOp->mFileSize.compressed_size;
  readOp->mState.mValue = 1;
  v7 = !v5;
  if ( !(_DWORD)read_bytes || (_DWORD)read_bytes == readOp->mFileSize.uncompressed_size )
  {
    uncompressed_size = readOp->mFileSize.uncompressed_size;
    v5 = !v7;
    mpFile = readOp->mpStreamFile->mpFile;
    if ( v5 )
    {
      return UFG::qRead(mpFile, readOp->mpBuffer, uncompressed_size, mSeekOffset, seek_type);
    }
    else
    {
      UFG::qReadAsync(
        mpFile,
        readOp->mpBuffer,
        uncompressed_size,
        mSeekOffset,
        seek_type,
        UFG::StreamFileWrapper::StreamFileWrapperFileCallback,
        readOp,
        QPRIORITY_NORMAL);
      return 0i64;
    }
  }
  else
  {
    load_offset = readOp->mFileSize.load_offset;
    read_data_offset = load_offset & 0xFFF;
    read_offset = load_offset & 0xFFFFF000;
    v11 = readOp->mFileSize.compressed_extra + readOp->mFileSize.uncompressed_size;
    v5 = !v7;
    v12 = readOp->mpStreamFile->mpFile;
    if ( v5 )
    {
      return UFG::qReadAndDecompress(
               v12,
               (unsigned __int8 *)readOp->mpBuffer,
               v11,
               mSeekOffset,
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
        readOp->mpBuffer,
        v11,
        mSeekOffset,
        seek_type,
        read_offset,
        read_bytes,
        read_data_offset,
        0i64,
        0i64,
        1,
        UFG::StreamFileWrapper::StreamFileWrapperFileCallback,
        readOp,
        QPRIORITY_NORMAL);
      return 0i64;
    }
  }
}

// File Line: 1050
// RVA: 0x22C5C0
__int64 __fastcall UFG::StreamFileWrapper::Read(
        void *hFile,
        UFG::StreamFileWrapper::QUEUE_CLASS queueClass,
        void *buffer,
        UFG::BIGFileSize *fileSize,
        void (__fastcall *callback)(UFG::qFileOp *, void *),
        void *callbackParam)
{
  return UFG::StreamFileWrapper::Read(hFile, queueClass, buffer, fileSize, 0i64, QSEEK_SET, callback, callbackParam, 0);
}

// File Line: 1064
// RVA: 0x22C610
__int64 __fastcall UFG::StreamFileWrapper::Read(
        UFG::StreamFileWrapper::StreamFile *hFile,
        UFG::StreamFileWrapper::QUEUE_CLASS queueClass,
        void *buffer,
        UFG::BIGFileSize *fileSize,
        __int64 seek_offset,
        UFG::qFileSeekType seek_type,
        void (__fastcall *callback)(UFG::qFileOp *, void *),
        void *callbackParam,
        unsigned int audioPriority)
{
  __int64 v11; // rbp
  UFG::allocator::free_link *v13; // rax
  UFG::StreamFileWrapper::StreamReadOp *v14; // rdi
  __int64 v15; // rsi
  __int64 v16; // rbx
  UFG::StreamFileWrapper::StreamReadQueue *v17; // rbp
  UFG::StreamFileWrapper::StreamFile *mpStreamFile; // rcx
  unsigned __int64 v19; // rsi
  UFG::qList<UFG::StreamFileWrapper::StreamReadOp,UFG::StreamFileWrapper::StreamReadOp,1,0> *p_mPendingReads; // rdx
  UFG::qNode<UFG::StreamFileWrapper::StreamReadOp,UFG::StreamFileWrapper::StreamReadOp> *mPrev; // rax
  __int64 Op; // rbx
  UFG::qNode<UFG::StreamFileWrapper::StreamReadOp,UFG::StreamFileWrapper::StreamReadOp> *v24; // r8
  UFG::qNode<UFG::StreamFileWrapper::StreamReadOp,UFG::StreamFileWrapper::StreamReadOp> *mNext; // rdx

  v11 = queueClass;
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
  v14->mpStreamFile = hFile;
  v14->mState.mValue = 0;
  v14->mQueueClass.mValue = v11;
  v14->mpBuffer = buffer;
  v14->mFileSize.load_offset = fileSize->load_offset;
  v14->mFileSize.compressed_size = fileSize->compressed_size;
  v14->mFileSize.compressed_extra = fileSize->compressed_extra;
  v14->mFileSize.uncompressed_size = fileSize->uncompressed_size;
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
    mpStreamFile = v14->mpStreamFile;
    if ( mpStreamFile->mBigFile )
    {
      v19 = (4 * (unsigned __int64)mpStreamFile->mpEntry->offset_div_4) >> 11;
    }
    else
    {
      if ( !mpStreamFile->mpFile )
      {
LABEL_10:
        UFG::StreamFileWrapper::smPendingQueues[v16].mLastDiskSortKey = v15;
        p_mPendingReads = &UFG::StreamFileWrapper::smPendingQueues[v16].mPendingReads;
        mPrev = p_mPendingReads->mNode.mPrev;
        mPrev->mNext = v14;
        v14->mPrev = mPrev;
        v14->mNext = &p_mPendingReads->mNode;
        p_mPendingReads->mNode.mPrev = v14;
        UFG::qMutex::Unlock((LPCRITICAL_SECTION)&v17->mQueueMutex);
        return 0i64;
      }
      v19 = v14->mSeekOffset / 2048;
    }
    v15 = mpStreamFile->mSortKey + v19;
    goto LABEL_10;
  }
  Op = UFG::StreamFileWrapper::ExecuteReadOp(v14);
  --UFG::StreamFileWrapper::StreamReadOp::smTotalReadOpCount;
  v24 = v14->mPrev;
  mNext = v14->mNext;
  v24->mNext = mNext;
  mNext->mPrev = v24;
  v14->mPrev = v14;
  v14->mNext = v14;
  operator delete[](v14);
  return Op;
}

// File Line: 1135
// RVA: 0x22EF50
bool __fastcall UFG::StreamFileWrapper::fnAudioPrioritySort(
        UFG::StreamFileWrapper::StreamReadOp *a,
        UFG::StreamFileWrapper::StreamReadOp *b)
{
  UFG::StreamFileWrapper::StreamFile *mpStreamFile; // r9
  unsigned __int64 mSeekOffset; // r8
  UFG::StreamFileWrapper::StreamFile *v5; // rdx
  unsigned int v6; // r8d
  unsigned int v7; // ecx

  mpStreamFile = a->mpStreamFile;
  if ( mpStreamFile->mBigFile )
    mSeekOffset = 4i64 * mpStreamFile->mpEntry->offset_div_4;
  else
    mSeekOffset = a->mSeekOffset;
  v5 = b->mpStreamFile;
  v6 = LODWORD(mpStreamFile->mSortKey) + (mSeekOffset >> 11);
  if ( v5->mBigFile )
    v7 = LODWORD(v5->mSortKey) + ((4 * (unsigned __int64)v5->mpEntry->offset_div_4) >> 11);
  else
    v7 = LODWORD(v5->mSortKey) + ((unsigned __int64)b->mSeekOffset >> 11);
  return v6 > v7;
}

// File Line: 1221
// RVA: 0x228D70
__int64 __fastcall UFG::StreamFileWrapper::ExecuteQueue(
        unsigned int queueIndex,
        unsigned int *opsToExecute,
        bool onlyOneInProgressAtATime)
{
  int v3; // ebp
  UFG::StreamFileWrapper::StreamReadQueue *v6; // rsi
  UFG::StreamFileWrapper::StreamReadOp *mNext; // rbx
  UFG::qNode<UFG::StreamFileWrapper::StreamReadOp,UFG::StreamFileWrapper::StreamReadOp> *mPrev; // rdx
  UFG::qNode<UFG::StreamFileWrapper::StreamReadOp,UFG::StreamFileWrapper::StreamReadOp> *v9; // rax
  UFG::qNode<UFG::StreamFileWrapper::StreamReadOp,UFG::StreamFileWrapper::StreamReadOp> *v10; // rcx

  v3 = *opsToExecute;
  v6 = &UFG::StreamFileWrapper::smPendingQueues[queueIndex];
  if ( *opsToExecute )
  {
    do
    {
      if ( onlyOneInProgressAtATime
        && (UFG::qList<UFG::StreamFileWrapper::StreamReadOp,UFG::StreamFileWrapper::StreamReadOp,1,0> *)UFG::StreamFileWrapper::smInProgressReads.mNode.mNext != &UFG::StreamFileWrapper::smInProgressReads )
      {
        break;
      }
      mNext = 0i64;
      UFG::qMutex::Lock((LPCRITICAL_SECTION)&v6->mQueueMutex);
      if ( (UFG::qList<UFG::StreamFileWrapper::StreamReadOp,UFG::StreamFileWrapper::StreamReadOp,1,0> *)v6->mPendingReads.mNode.mNext != &v6->mPendingReads )
      {
        mNext = (UFG::StreamFileWrapper::StreamReadOp *)v6->mPendingReads.mNode.mNext;
        mPrev = mNext->mPrev;
        v9 = mNext->mNext;
        mPrev->mNext = v9;
        v9->mPrev = mPrev;
        mNext->mPrev = mNext;
        mNext->mNext = mNext;
      }
      UFG::qMutex::Unlock((LPCRITICAL_SECTION)&v6->mQueueMutex);
      if ( !mNext )
        break;
      UFG::StreamFileWrapper::ExecuteReadOp(mNext);
      UFG::qMutex::Lock((LPCRITICAL_SECTION)&UFG::StreamFileWrapper::smStreamFilemMutex);
      v10 = UFG::StreamFileWrapper::smInProgressReads.mNode.mPrev;
      UFG::StreamFileWrapper::smInProgressReads.mNode.mPrev->mNext = mNext;
      mNext->mPrev = v10;
      mNext->mNext = (UFG::qNode<UFG::StreamFileWrapper::StreamReadOp,UFG::StreamFileWrapper::StreamReadOp> *)&UFG::StreamFileWrapper::smInProgressReads;
      UFG::StreamFileWrapper::smInProgressReads.mNode.mPrev = mNext;
      UFG::qMutex::Unlock((LPCRITICAL_SECTION)&UFG::StreamFileWrapper::smStreamFilemMutex);
    }
    while ( (*opsToExecute)-- != 1 );
  }
  return v3 - *opsToExecute;
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
  UFG::qList<UFG::StreamFileWrapper::StreamFile,UFG::StreamFileWrapper::StreamFile,1,0> *i; // rax
  UFG::qNode<UFG::StreamFileWrapper::StreamFile,UFG::StreamFileWrapper::StreamFile> *mPrev; // rdx

  UFG::qMutex::Lock((LPCRITICAL_SECTION)&UFG::StreamFileWrapper::smStreamFilemMutex);
  UFG::BigFileSystem::ReopenBigFile(filename);
  for ( i = (UFG::qList<UFG::StreamFileWrapper::StreamFile,UFG::StreamFileWrapper::StreamFile,1,0> *)UFG::StreamFileWrapper::smStreamFiles.mNode.mNext;
        i != &UFG::StreamFileWrapper::smStreamFiles;
        i = (UFG::qList<UFG::StreamFileWrapper::StreamFile,UFG::StreamFileWrapper::StreamFile,1,0> *)i->mNode.mNext )
  {
    mPrev = i[2].mNode.mPrev;
    if ( mPrev )
      i[3].mNode.mNext = mPrev[7].mPrev;
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
  int v1; // eax
  bool v2; // si
  int v3; // ebx
  unsigned int v4; // edi
  UFG::qList<UFG::StreamFileWrapper::StreamReadOp,UFG::StreamFileWrapper::StreamReadOp,1,0> *i; // rax
  UFG::qList<UFG::StreamFileWrapper::StreamReadOp,UFG::StreamFileWrapper::StreamReadOp,1,0> *j; // rax
  UFG::qNode<UFG::StreamFileWrapper::StreamReadOp,UFG::StreamFileWrapper::StreamReadOp> *k; // rdx
  UFG::qNode<UFG::StreamFileWrapper::StreamReadOp,UFG::StreamFileWrapper::StreamReadOp> *mPrev; // rcx
  UFG::qNode<UFG::StreamFileWrapper::StreamReadOp,UFG::StreamFileWrapper::StreamReadOp> *mNext; // rax
  UFG::qNode<UFG::StreamFileWrapper::StreamReadOp,UFG::StreamFileWrapper::StreamReadOp> *v10; // rcx
  UFG::qNode<UFG::StreamFileWrapper::StreamReadOp,UFG::StreamFileWrapper::StreamReadOp> *v11; // rax
  UFG::qNode<UFG::StreamFileWrapper::StreamFile,UFG::StreamFileWrapper::StreamFile> *m; // rbx
  UFG::qNode<UFG::StreamFileWrapper::StreamFile,UFG::StreamFileWrapper::StreamFile> *v13; // rcx
  UFG::qNode<UFG::StreamFileWrapper::StreamFile,UFG::StreamFileWrapper::StreamFile> *v14; // rax
  UFG::qNode<UFG::StreamFileWrapper::StreamFile,UFG::StreamFileWrapper::StreamFile> *v15; // rcx
  UFG::qNode<UFG::StreamFileWrapper::StreamFile,UFG::StreamFileWrapper::StreamFile> *v16; // rcx
  UFG::qNode<UFG::StreamFileWrapper::StreamFile,UFG::StreamFileWrapper::StreamFile> *v17; // rax
  bool v18; // di
  UFG::qNode<UFG::StreamFileWrapper::StreamFile,UFG::StreamFileWrapper::StreamFile> *n; // rbx
  UFG::qNode<UFG::StreamFileWrapper::StreamFile,UFG::StreamFileWrapper::StreamFile> *v20; // rcx
  UFG::qNode<UFG::StreamFileWrapper::StreamFile,UFG::StreamFileWrapper::StreamFile> *v21; // rax
  UFG::qNode<UFG::StreamFileWrapper::StreamFile,UFG::StreamFileWrapper::StreamFile> *v22; // rcx
  UFG::qNode<UFG::StreamFileWrapper::StreamFile,UFG::StreamFileWrapper::StreamFile> *v23; // rdx
  UFG::qNode<UFG::StreamFileWrapper::StreamFile,UFG::StreamFileWrapper::StreamFile> *v24; // rax
  AMD_HD3D *v25; // rcx
  int v26; // edx
  hkGeometryUtils::IVertices *v27; // rcx
  int v28; // r8d
  bool game_streaming; // [rsp+60h] [rbp+8h] BYREF
  bool disk_caching; // [rsp+68h] [rbp+10h] BYREF
  void *opsToExecute; // [rsp+70h] [rbp+18h] BYREF

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
    LODWORD(opsToExecute) = v1;
    UFG::qMutex::Lock(&stru_142377298);
    UFG::StreamFileWrapper::StreamReadQueue::Sort(
      UFG::StreamFileWrapper::smPendingQueues,
      UFG::StreamFileWrapper::fnAudioPrioritySort);
    UFG::qMutex::Unlock(&stru_142377298);
    if ( (unsigned int)UFG::StreamFileWrapper::ExecuteQueue(0, (unsigned int *)&opsToExecute, v2) )
      time_since_last_queue = 0.0;
    if ( (unsigned int)UFG::StreamFileWrapper::ExecuteQueue(2u, (unsigned int *)&opsToExecute, v2) )
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
    if ( v4 <= 1 && (unsigned int)UFG::StreamFileWrapper::ExecuteQueue(3u, (unsigned int *)&opsToExecute, v2) )
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
      UFG::StreamFileWrapper::ExecuteQueue(1u, (unsigned int *)&opsToExecute, v2);
      if ( accum_audio_low_priority > 2.0 )
        accum_audio_low_priority = accum_audio_low_priority + -2.0;
    }
  }
  UFG::qMutex::Lock((LPCRITICAL_SECTION)&UFG::StreamFileWrapper::smStreamFilemMutex);
  for ( k = UFG::StreamFileWrapper::smCompletedReads.mNode.mNext;
        (UFG::qList<UFG::StreamFileWrapper::StreamReadOp,UFG::StreamFileWrapper::StreamReadOp,1,0> *)UFG::StreamFileWrapper::smCompletedReads.mNode.mNext != &UFG::StreamFileWrapper::smCompletedReads;
        k = UFG::StreamFileWrapper::smCompletedReads.mNode.mNext )
  {
    mPrev = k->mPrev;
    mNext = k->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    k->mPrev = k;
    k->mNext = k;
    opsToExecute = k;
    --UFG::StreamFileWrapper::StreamReadOp::smTotalReadOpCount;
    v10 = k->mPrev;
    v11 = k->mNext;
    v10->mNext = v11;
    v11->mPrev = v10;
    k->mPrev = k;
    k->mNext = k;
    operator delete[](k);
  }
  for ( m = UFG::StreamFileWrapper::smClosedStreamFiles.mNode.mNext;
        (UFG::qList<UFG::StreamFileWrapper::StreamFile,UFG::StreamFileWrapper::StreamFile,1,0> *)UFG::StreamFileWrapper::smClosedStreamFiles.mNode.mNext != &UFG::StreamFileWrapper::smClosedStreamFiles;
        m = UFG::StreamFileWrapper::smClosedStreamFiles.mNode.mNext )
  {
    v13 = m->mPrev;
    v14 = m->mNext;
    v13->mNext = v14;
    v14->mPrev = v13;
    m->mPrev = m;
    m->mNext = m;
    opsToExecute = m;
    m[3].mNext = (UFG::qNode<UFG::StreamFileWrapper::StreamFile,UFG::StreamFileWrapper::StreamFile> *)-1i64;
    v15 = m[3].mPrev;
    if ( v15 )
      ((void (__fastcall *)(UFG::qNode<UFG::StreamFileWrapper::StreamFile,UFG::StreamFileWrapper::StreamFile> *, __int64))v15->mPrev->mPrev)(
        v15,
        1i64);
    v16 = m->mPrev;
    v17 = m->mNext;
    v16->mNext = v17;
    v17->mPrev = v16;
    m->mPrev = m;
    m->mNext = m;
    operator delete[](m);
  }
  v18 = (UFG::qList<UFG::StreamFileWrapper::StreamReadOp,UFG::StreamFileWrapper::StreamReadOp,1,0> *)UFG::StreamFileWrapper::smInProgressReads.mNode.mNext != &UFG::StreamFileWrapper::smInProgressReads
     || !disk_caching;
  UFG::qMutex::Unlock((LPCRITICAL_SECTION)&UFG::StreamFileWrapper::smStreamFilemMutex);
  UFG::qMutex::Lock((LPCRITICAL_SECTION)&UFG::StreamFileWrapper::smAudioStreamFileMutex);
  for ( n = UFG::StreamFileWrapper::smClosedAudioStreamFiles.mNode.mNext;
        (UFG::qList<UFG::StreamFileWrapper::StreamFile,UFG::StreamFileWrapper::StreamFile,1,0> *)UFG::StreamFileWrapper::smClosedAudioStreamFiles.mNode.mNext != &UFG::StreamFileWrapper::smClosedAudioStreamFiles;
        n = UFG::StreamFileWrapper::smClosedAudioStreamFiles.mNode.mNext )
  {
    v20 = n->mPrev;
    v21 = n->mNext;
    v20->mNext = v21;
    v21->mPrev = v20;
    n->mPrev = n;
    n->mNext = n;
    opsToExecute = n;
    n[3].mNext = (UFG::qNode<UFG::StreamFileWrapper::StreamFile,UFG::StreamFileWrapper::StreamFile> *)-1i64;
    v22 = n[3].mPrev;
    if ( v22 )
      ((void (__fastcall *)(UFG::qNode<UFG::StreamFileWrapper::StreamFile,UFG::StreamFileWrapper::StreamFile> *, __int64))v22->mPrev->mPrev)(
        v22,
        1i64);
    v23 = n->mPrev;
    v24 = n->mNext;
    v23->mNext = v24;
    v24->mPrev = v23;
    n->mPrev = n;
    n->mNext = n;
    operator delete[](n);
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

