// File Line: 48
// RVA: 0x1467F20
__int64 UFG::_dynamic_initializer_for__gQuarkFileSystem__()
{
  UFG::qFileSystem::qFileSystem(&UFG::gQuarkFileSystem);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__gQuarkFileSystem__);
}

// File Line: 581
// RVA: 0x160D20
void __fastcall UFG::qFile::qFile(
        UFG::qFile *this,
        UFG::qFileDevice *device,
        const char *filename,
        UFG::qFileAccessType access_type)
{
  int v8; // edx
  char *mFilename; // rax
  const char *v10; // rdi
  char v11; // cl

  this->mPrev = this;
  this->mNext = this;
  UFG::qMutex::qMutex(&this->mFileHandleMutex, "qFile::mOperationMutex");
  UFG::qMutex::qMutex(&this->mStateMutex, "qFile::mStateMutex");
  v8 = 0x104;
  mFilename = this->mFilename;
  if ( this != (UFG::qFile *)0xFFFFFFFFFFFFFF60i64 )
  {
    if ( !filename )
      goto LABEL_7;
    v10 = (const char *)(filename - mFilename);
    do
    {
      v11 = mFilename[(_QWORD)v10];
      *mFilename++ = v11;
      if ( !v11 )
        break;
      --v8;
    }
    while ( v8 > 1 );
    if ( *(mFilename - 1) )
LABEL_7:
      *mFilename = 0;
  }
  this->mDevice = device;
  this->mAccessType = access_type;
  *(_QWORD *)&this->mOpenState = 0i64;
  this->mNumAsyncOps = 0;
  this->mAsyncCloseOp = 0i64;
  this->mFileHandle = 0i64;
}

// File Line: 626
// RVA: 0x160F30
void __fastcall UFG::qFileOp::qFileOp(
        UFG::qFileOp *this,
        UFG::qFile *file,
        UFG::qFileOp::OpType type,
        void (__fastcall *callback)(UFG::qFileOp *, void *),
        void *callback_param)
{
  UFG::qString *p_mFilename; // r10
  UFG::qString *p_mAllocationName; // rcx
  char *mFilename; // rdx
  char *v10; // rcx
  int v12; // ecx
  unsigned __int64 Ticks; // rax

  this->mPrev = this;
  this->mNext = this;
  p_mFilename = &this->mFilename;
  this->mFilename.mPrev = &this->mFilename;
  this->mFilename.mNext = &this->mFilename;
  this->mFilename.mMagic = 16909060;
  this->mFilename.mData = (char *)UFG::qString::sEmptyString;
  this->mFilename.mLength = 0;
  *(_QWORD *)&this->mFilename.mStringHash32 = -1i64;
  p_mAllocationName = &this->mAllocationName;
  p_mAllocationName->mPrev = p_mAllocationName;
  p_mAllocationName->mNext = p_mAllocationName;
  p_mAllocationName->mMagic = 16909060;
  p_mAllocationName->mData = (char *)UFG::qString::sEmptyString;
  p_mAllocationName->mLength = 0;
  *(_QWORD *)&p_mAllocationName->mStringHash32 = -1i64;
  this->mDestinationFilename.mPrev = &this->mDestinationFilename;
  this->mDestinationFilename.mNext = &this->mDestinationFilename;
  this->mDestinationFilename.mMagic = 16909060;
  this->mDestinationFilename.mData = (char *)UFG::qString::sEmptyString;
  this->mDestinationFilename.mLength = 0;
  *(_QWORD *)&this->mDestinationFilename.mStringHash32 = -1i64;
  this->mPatterns.mNode.mPrev = &this->mPatterns.mNode;
  this->mPatterns.mNode.mNext = &this->mPatterns.mNode;
  this->mResultFiles.mNode.mPrev = &this->mResultFiles.mNode;
  this->mResultFiles.mNode.mNext = &this->mResultFiles.mNode;
  this->mDevice = file->mDevice;
  this->mType = type;
  *(_DWORD *)this->mStatus = 0;
  this->mFile = file;
  mFilename = file->mFilename;
  if ( !mFilename || mFilename == UFG::qString::sEmptyString )
  {
    v12 = 0;
  }
  else
  {
    v10 = mFilename;
    while ( *v10++ )
      ;
    v12 = (_DWORD)v10 - (_DWORD)mFilename - 1;
  }
  UFG::qString::Set(p_mFilename, mFilename, v12, 0i64, 0);
  Ticks = UFG::qGetTicks();
  this->mStartTime = UFG::qGetTickTime(UFG::gQuarkFileSystem.mStartTicks, Ticks);
  *(_QWORD *)&this->mQueuedTime = 0i64;
  this->mDoneTime = 0.0;
  this->mWarnOnFail = 0;
  this->mCallback = callback;
  this->mCallbackParam = callback_param;
  this->mSeekType = QSEEK_CUR;
  this->mSeekOffset = 0i64;
  this->mBuffer = 0i64;
  this->mNumBytes = 0i64;
  this->mScratchBuffer = 0i64;
  this->mScratchBufferSize = 0i64;
  this->mReadOffset = 0i64;
  this->mReadBytes = 0i64;
  this->mReadDataOffset = 0i64;
  this->mAllocationParams = 1i64;
  this->mMemoryPool = 0i64;
  this->mPreviousChecksum = 0i64;
  this->mResult0 = 0i64;
  this->mResult1 = 0i64;
}

// File Line: 666
// RVA: 0x161110
void __fastcall UFG::qFileOp::qFileOp(
        UFG::qFileOp *this,
        const char *filename,
        UFG::qFileOp::OpType type,
        void (__fastcall *callback)(UFG::qFileOp *, void *),
        void *callback_param)
{
  UFG::qString *p_mFilename; // r14
  UFG::qString *p_mAllocationName; // rcx
  const char *v11; // rcx
  int v13; // ecx
  unsigned __int64 Ticks; // rax

  this->mPrev = this;
  this->mNext = this;
  p_mFilename = &this->mFilename;
  this->mFilename.mPrev = &this->mFilename;
  this->mFilename.mNext = &this->mFilename;
  this->mFilename.mMagic = 16909060;
  this->mFilename.mData = (char *)UFG::qString::sEmptyString;
  this->mFilename.mLength = 0;
  *(_QWORD *)&this->mFilename.mStringHash32 = -1i64;
  p_mAllocationName = &this->mAllocationName;
  p_mAllocationName->mPrev = p_mAllocationName;
  p_mAllocationName->mNext = p_mAllocationName;
  p_mAllocationName->mMagic = 16909060;
  p_mAllocationName->mData = (char *)UFG::qString::sEmptyString;
  p_mAllocationName->mLength = 0;
  *(_QWORD *)&p_mAllocationName->mStringHash32 = -1i64;
  this->mDestinationFilename.mPrev = &this->mDestinationFilename;
  this->mDestinationFilename.mNext = &this->mDestinationFilename;
  this->mDestinationFilename.mMagic = 16909060;
  this->mDestinationFilename.mData = (char *)UFG::qString::sEmptyString;
  this->mDestinationFilename.mLength = 0;
  *(_QWORD *)&this->mDestinationFilename.mStringHash32 = -1i64;
  this->mPatterns.mNode.mPrev = &this->mPatterns.mNode;
  this->mPatterns.mNode.mNext = &this->mPatterns.mNode;
  this->mResultFiles.mNode.mPrev = &this->mResultFiles.mNode;
  this->mResultFiles.mNode.mNext = &this->mResultFiles.mNode;
  this->mDevice = UFG::qFileSystem::MapFilenameToDevice(&UFG::gQuarkFileSystem, filename);
  this->mType = type;
  *(_DWORD *)this->mStatus = 0;
  this->mFile = 0i64;
  if ( !filename || filename == UFG::qString::sEmptyString )
  {
    v13 = 0;
  }
  else
  {
    v11 = filename;
    while ( *v11++ )
      ;
    v13 = (_DWORD)v11 - (_DWORD)filename - 1;
  }
  UFG::qString::Set(p_mFilename, filename, v13, 0i64, 0);
  Ticks = UFG::qGetTicks();
  this->mStartTime = UFG::qGetTickTime(UFG::gQuarkFileSystem.mStartTicks, Ticks);
  *(_QWORD *)&this->mQueuedTime = 0i64;
  this->mDoneTime = 0.0;
  this->mWarnOnFail = 0;
  this->mCallback = callback;
  this->mCallbackParam = callback_param;
  this->mSeekType = QSEEK_CUR;
  this->mSeekOffset = 0i64;
  this->mBuffer = 0i64;
  this->mNumBytes = 0i64;
  this->mScratchBuffer = 0i64;
  this->mScratchBufferSize = 0i64;
  this->mReadOffset = 0i64;
  this->mReadBytes = 0i64;
  this->mReadDataOffset = 0i64;
  this->mAllocationParams = 1i64;
  this->mMemoryPool = 0i64;
  this->mPreviousChecksum = 0i64;
  this->mResult0 = 0i64;
  this->mResult1 = 0i64;
}

// File Line: 706
// RVA: 0x163950
void __fastcall UFG::qFileOp::~qFileOp(UFG::qFileOp *this)
{
  UFG::qList<UFG::qString,UFG::qString,1,0> *p_mResultFiles; // rbx
  UFG::qNode<UFG::qString,UFG::qString> *mPrev; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *mNext; // rax
  UFG::qNode<UFG::qString,UFG::qString> *v5; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *v6; // rax
  UFG::qString *p_mDestinationFilename; // rbx
  char *mData; // rdx
  UFG::qNode<UFG::qString,UFG::qString> *v9; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *v10; // rax
  UFG::qString *p_mAllocationName; // rbx
  char *v12; // rdx
  UFG::qNode<UFG::qString,UFG::qString> *v13; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *v14; // rax
  UFG::qString *p_mFilename; // rbx
  char *v16; // rdx
  UFG::qNode<UFG::qString,UFG::qString> *v17; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *v18; // rax
  UFG::qNode<UFG::qFileOp,UFG::qFileOp> *v19; // rcx
  UFG::qNode<UFG::qFileOp,UFG::qFileOp> *v20; // rax

  p_mResultFiles = &this->mResultFiles;
  UFG::qList<UFG::qString,UFG::qString,1,0>::DeleteNodes(&this->mResultFiles);
  mPrev = p_mResultFiles->mNode.mPrev;
  mNext = p_mResultFiles->mNode.mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  p_mResultFiles->mNode.mPrev = &p_mResultFiles->mNode;
  p_mResultFiles->mNode.mNext = &p_mResultFiles->mNode;
  UFG::qList<UFG::qString,UFG::qString,1,0>::DeleteNodes(&this->mPatterns);
  v5 = this->mPatterns.mNode.mPrev;
  v6 = this->mPatterns.mNode.mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  this->mPatterns.mNode.mPrev = &this->mPatterns.mNode;
  this->mPatterns.mNode.mNext = &this->mPatterns.mNode;
  p_mDestinationFilename = &this->mDestinationFilename;
  mData = this->mDestinationFilename.mData;
  if ( mData != UFG::qString::sEmptyString && mData )
    UFG::qMemoryPool::Free(UFG::gMainMemoryPool, mData);
  this->mDestinationFilename.mMagic = 0;
  v9 = p_mDestinationFilename->mPrev;
  v10 = this->mDestinationFilename.mNext;
  v9->mNext = v10;
  v10->mPrev = v9;
  p_mDestinationFilename->mPrev = p_mDestinationFilename;
  this->mDestinationFilename.mNext = &this->mDestinationFilename;
  p_mAllocationName = &this->mAllocationName;
  v12 = this->mAllocationName.mData;
  if ( v12 != UFG::qString::sEmptyString && v12 )
    UFG::qMemoryPool::Free(UFG::gMainMemoryPool, v12);
  this->mAllocationName.mMagic = 0;
  v13 = p_mAllocationName->mPrev;
  v14 = this->mAllocationName.mNext;
  v13->mNext = v14;
  v14->mPrev = v13;
  p_mAllocationName->mPrev = p_mAllocationName;
  this->mAllocationName.mNext = &this->mAllocationName;
  p_mFilename = &this->mFilename;
  v16 = this->mFilename.mData;
  if ( v16 != UFG::qString::sEmptyString && v16 )
    UFG::qMemoryPool::Free(UFG::gMainMemoryPool, v16);
  this->mFilename.mMagic = 0;
  v17 = p_mFilename->mPrev;
  v18 = this->mFilename.mNext;
  v17->mNext = v18;
  v18->mPrev = v17;
  p_mFilename->mPrev = p_mFilename;
  this->mFilename.mNext = &this->mFilename;
  v19 = this->mPrev;
  v20 = this->mNext;
  v19->mNext = v20;
  v20->mPrev = v19;
  this->mPrev = this;
  this->mNext = this;
}

// File Line: 710
// RVA: 0x172470
const char *__fastcall UFG::qFileOp::GetStatusName(UFG::qFileOp *this)
{
  __int64 v1; // rax
  __int64 v3[9]; // [rsp+0h] [rbp-48h]

  v3[0] = (__int64)"NONE";
  v3[1] = (__int64)"QUEUED";
  v3[2] = (__int64)"EXECUTING";
  v3[3] = (__int64)"DONE";
  v3[4] = (__int64)"CANCELLED";
  v3[5] = (__int64)"ERROR";
  v3[6] = (__int64)"ERROR_NOT_ENOUGH_SPACE";
  v3[7] = (__int64)"ERROR_DECOMPRESSION";
  v1 = *(int *)this->mStatus;
  if ( (unsigned int)v1 > 7 )
    return "<unknown>";
  else
    return (const char *)v3[v1];
}

// File Line: 733
// RVA: 0x172CD0
const char *__fastcall UFG::qFileOp::GetTypeName(UFG::qFileOp *this)
{
  __int64 mType; // rax
  __int64 v3[21]; // [rsp+0h] [rbp-A8h]

  v3[0] = (__int64)"OPEN";
  v3[1] = (__int64)"CLOSE";
  v3[2] = (__int64)"READ";
  v3[3] = (__int64)"WRITE";
  v3[4] = (__int64)"TIME";
  v3[5] = (__int64)"SET_FILE_TIME";
  v3[6] = (__int64)"OPEN_READ_CLOSE";
  v3[7] = (__int64)"OPEN_WRITE_CLOSE";
  v3[8] = (__int64)"OPEN_APPEND_CLOSE";
  v3[9] = (__int64)"READ_AND_DECOMPRESS";
  v3[10] = (__int64)"WRITE_AND_COMPRESS";
  v3[11] = (__int64)"GET_SIZE";
  v3[12] = (__int64)"READ_ENTIRE_FILE";
  v3[13] = (__int64)"EXISTS";
  v3[14] = (__int64)"CHECKSUM_32";
  v3[15] = (__int64)"CHECKSUM_64";
  v3[16] = (__int64)"COPY_FILE";
  v3[17] = (__int64)"DELETE_FILE";
  v3[18] = (__int64)"RENAME_FILE";
  v3[19] = (__int64)"WRITE_WITH_BACKUP";
  mType = this->mType;
  if ( (unsigned int)mType > 0x13 )
    return "<unknown>";
  else
    return (const char *)v3[mType];
}

// File Line: 793
// RVA: 0x1708D0
char *__fastcall UFG::qFileOp::GetFilename(UFG::qFileOp *this)
{
  UFG::qFile *mFile; // rax

  mFile = this->mFile;
  if ( mFile )
    return mFile->mFilename;
  else
    return this->mFilename.mData;
}

// File Line: 862
// RVA: 0x1720B0
__int64 __fastcall UFG::qFileOp::GetReadEntireFileSize(UFG::qFileOp *this)
{
  return this->mResultNumBytesRead;
}

// File Line: 869
// RVA: 0x171590
char *__fastcall UFG::qFileOp::GetReadEntireFileBuffer(UFG::qFileOp *this)
{
  return (char *)this->mResult1;
}

// File Line: 963
// RVA: 0x170400
float __fastcall UFG::qFileOp::GetExecuteTime(UFG::qFileOp *this)
{
  return this->mExecuteTime;
}

// File Line: 968
// RVA: 0x16D680
unsigned __int64 __fastcall UFG::qFileOp::Execute(UFG::qFileOp *this)
{
  UFG::qFileOp::OpType mType; // eax
  unsigned int v3; // ebx
  char Directory; // al
  signed __int64 FileSize; // rax
  unsigned __int64 v6; // rax
  unsigned __int64 FileTime; // rax
  bool v8; // zf
  unsigned __int64 v9; // rax
  unsigned __int64 v10; // rax
  signed __int64 v11; // rax
  signed __int64 v12; // rax
  int v13; // ecx
  char *EntireFile; // rax
  unsigned __int64 Ticks; // rax
  float TickTime; // xmm0_4
  unsigned __int64 result; // rax
  bool not_enough_space; // [rsp+70h] [rbp+8h] BYREF

  mType = this->mType;
  v3 = 5;
  not_enough_space = 1;
  switch ( mType )
  {
    case OP_OPEN:
      Directory = UFG::qOpenInternal(this->mFile, this->mWarnOnFail);
      goto LABEL_45;
    case OP_CLOSE:
      Directory = UFG::qCloseInternal(this->mFile);
      goto LABEL_45;
    case OP_READ:
      FileSize = UFG::qRead(this->mFile, this->mBuffer, this->mNumBytes, this->mSeekOffset, this->mSeekType);
      goto LABEL_5;
    case OP_WRITE:
      v6 = UFG::qWrite(
             this->mFile,
             this->mBuffer,
             this->mNumBytes,
             this->mSeekOffset,
             this->mSeekType,
             &not_enough_space);
      this->mResult1 = v6;
      if ( v6 == this->mNumBytes )
        goto LABEL_32;
      v3 = not_enough_space + 5;
      break;
    case OP_TIME:
      FileTime = UFG::qGetFileTime(this->mFilename.mData);
      this->mResult0 = FileTime;
      v8 = FileTime == 0;
      goto LABEL_46;
    case OP_SET_FILENAME_TIME:
      Directory = UFG::qSetFileTime(this->mFilename.mData, this->mFileTime);
      goto LABEL_45;
    case OP_OPEN_READ_CLOSE:
      v9 = UFG::qRead(this->mFilename.mData, this->mBuffer, this->mNumBytes, this->mSeekOffset);
      v8 = v9 == this->mNumBytes;
      this->mResult0 = v9;
      if ( v8 )
        v3 = 3;
      break;
    case OP_OPEN_WRITE_CLOSE:
      v10 = UFG::qWrite(this->mFilename.mData, this->mBuffer, this->mNumBytes, this->mSeekOffset, this->mSeekType, 0i64);
      goto LABEL_16;
    case OP_OPEN_APPEND_CLOSE:
      v10 = UFG::qWriteAppend(
              this->mFilename.mData,
              this->mBuffer,
              this->mNumBytes,
              this->mSeekOffset,
              this->mSeekType,
              0i64);
      goto LABEL_16;
    case OP_READ_AND_DECOMPRESS:
      v11 = UFG::qReadAndDecompress(
              this->mFile,
              this->mBuffer,
              this->mNumBytes,
              this->mSeekOffset,
              this->mSeekType,
              this->mReadOffset,
              this->mReadBytes,
              this->mReadDataOffset,
              this->mScratchBuffer,
              this->mScratchBufferSize,
              this->mInPlace);
      this->mResult1 = v11;
      if ( v11 >= 0 )
        v3 = 3;
      break;
    case OP_WRITE_AND_COMPRESS:
      v12 = UFG::qWriteAndCompress(
              this->mFile,
              this->mBuffer,
              this->mNumBytes,
              this->mScratchBuffer,
              this->mScratchBufferSize,
              &not_enough_space);
      v8 = !not_enough_space;
      this->mResult1 = v12;
      if ( v8 )
      {
        v13 = 3;
        if ( v12 < 0 )
          v13 = 5;
        v3 = v13;
      }
      else
      {
        v3 = 6;
      }
      break;
    case OP_GET_SIZE:
      FileSize = UFG::qGetFileSize(this->mFilename.mData);
LABEL_5:
      this->mResult0 = FileSize;
      if ( FileSize >= 0 )
        v3 = 3;
      break;
    case OP_READ_ENTIRE_FILE:
      EntireFile = UFG::qReadEntireFile(
                     this->mFilename.mData,
                     (__int64 *)&this->336,
                     this->mMemoryPool,
                     this->mAllocationParams,
                     this->mAllocationName.mData);
      this->mResult1 = (unsigned __int64)EntireFile;
      v8 = EntireFile == 0i64;
      goto LABEL_46;
    case OP_EXISTS:
      Directory = UFG::qFileExists(this->mFilename.mData);
      goto LABEL_45;
    case OP_CHECKSUM_32:
      this->mResultChecksum32 = UFG::qGetFileChecksum32(this->mFilename.mData, this->mPreviousChecksum);
LABEL_32:
      v3 = 3;
      break;
    case OP_CHECKSUM_64:
      v3 = 3;
      this->mResult0 = UFG::qGetFileChecksum64(this->mFilename.mData, this->mPreviousChecksum);
      break;
    case OP_COPY_FILE:
      Directory = UFG::qCopyFile(this->mFilename.mData, this->mDestinationFilename.mData);
      goto LABEL_45;
    case OP_DELETE_FILE:
      Directory = UFG::qDeleteFile(this->mFilename.mData);
      goto LABEL_45;
    case OP_RENAME_FILE:
      Directory = UFG::qRenameFile(this->mFilename.mData, this->mDestinationFilename.mData);
      goto LABEL_45;
    case OP_WRITE_WITH_BACKUP:
      v10 = UFG::qWriteWithBackup(this->mFilename.mData, this->mBuffer, this->mNumBytes);
LABEL_16:
      v8 = v10 == this->mNumBytes;
      this->mResult1 = v10;
      if ( v8 )
        v3 = 3;
      break;
    case OP_GET_FILES:
      if ( UFG::qGetFiles(&this->mResultFiles, this->mFilename.mData, this->mRecursive, &this->mPatterns) > 0 )
        v3 = 3;
      break;
    case OP_GET_DIRECTORIES:
      if ( UFG::qGetDirectories(&this->mResultFiles, this->mFilename.mData, this->mRecursive, &this->mPatterns) > 0 )
        v3 = 3;
      break;
    case OP_CREATE_DIRECTORY:
      Directory = UFG::qCreateDirectory(this->mFilename.mData);
LABEL_45:
      v8 = Directory == 0;
LABEL_46:
      if ( !v8 )
        v3 = 3;
      break;
    default:
      break;
  }
  Ticks = UFG::qGetTicks();
  TickTime = UFG::qGetTickTime(UFG::gQuarkFileSystem.mStartTicks, Ticks);
  result = v3;
  this->mExecuteTime = (float)(TickTime - this->mStartTime) - this->mQueuedTime;
  return result;
}

// File Line: 1210
// RVA: 0x161300
void __fastcall UFG::qFileOpList::qFileOpList(UFG::qFileOpList *this, const char *name)
{
  this->mPrev = this;
  this->mNext = this;
  UFG::qEvent::qEvent(&this->mEvent, "qFileOpList", 1);
  UFG::qMutex::qMutex(&this->mMutex, &customCaption);
  `eh vector constructor iterator(
    this->mQueuedOps,
    0x10ui64,
    3,
    (void (__fastcall *)(void *))UFG::qReflectHandleBase::qReflectHandleBase);
  this->mExecutingOps.mNode.mPrev = &this->mExecutingOps.mNode;
  this->mExecutingOps.mNode.mNext = &this->mExecutingOps.mNode;
  this->mDoneOps.mNode.mPrev = &this->mDoneOps.mNode;
  this->mDoneOps.mNode.mNext = &this->mDoneOps.mNode;
  this->mFileSystem = 0i64;
}

// File Line: 1215
// RVA: 0x163AB0
void __fastcall UFG::qFileOpList::~qFileOpList(UFG::qFileOpList *this)
{
  UFG::qList<UFG::qFileOp,UFG::qFileOp,1,0> *p_mDoneOps; // rbx
  UFG::qNode<UFG::qFileOp,UFG::qFileOp> *mPrev; // rcx
  UFG::qNode<UFG::qFileOp,UFG::qFileOp> *mNext; // rax
  UFG::qNode<UFG::qFileOp,UFG::qFileOp> *v5; // rcx
  UFG::qNode<UFG::qFileOp,UFG::qFileOp> *v6; // rax
  UFG::qNode<UFG::qFileOpList,UFG::qFileOpList> *v7; // rcx
  UFG::qNode<UFG::qFileOpList,UFG::qFileOpList> *v8; // rax

  p_mDoneOps = &this->mDoneOps;
  UFG::qList<UFG::qFileOp,UFG::qFileOp,1,0>::DeleteNodes(&this->mDoneOps);
  mPrev = p_mDoneOps->mNode.mPrev;
  mNext = p_mDoneOps->mNode.mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  p_mDoneOps->mNode.mPrev = &p_mDoneOps->mNode;
  p_mDoneOps->mNode.mNext = &p_mDoneOps->mNode;
  UFG::qList<UFG::qFileOp,UFG::qFileOp,1,0>::DeleteNodes(&this->mExecutingOps);
  v5 = this->mExecutingOps.mNode.mPrev;
  v6 = this->mExecutingOps.mNode.mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  this->mExecutingOps.mNode.mPrev = &this->mExecutingOps.mNode;
  this->mExecutingOps.mNode.mNext = &this->mExecutingOps.mNode;
  `eh vector destructor iterator(
    this->mQueuedOps,
    0x10ui64,
    3,
    (void (__fastcall *)(void *))UFG::qList<UFG::qFileOp,UFG::qFileOp,1,0>::~qList<UFG::qFileOp,UFG::qFileOp,1,0>);
  Scaleform::Lock::~Lock((LPCRITICAL_SECTION)&this->mMutex);
  UFG::qEvent::~qEvent(&this->mEvent);
  v7 = this->mPrev;
  v8 = this->mNext;
  v7->mNext = v8;
  v8->mPrev = v7;
  this->mPrev = this;
  this->mNext = this;
}

// File Line: 1219
// RVA: 0x1795F0
void __fastcall UFG::qFileOpList::Queue(UFG::qFileOpList *this, UFG::qFileOp *file_op, int priority)
{
  __int64 v4; // r12
  UFG::qFileOp *v6; // rbp
  UFG::qFile *mFile; // rdi
  bool v8; // al
  UFG::qList<UFG::qFileOp,UFG::qFileOp,1,0> *v9; // rcx
  UFG::qNode<UFG::qFileOp,UFG::qFileOp> *mPrev; // rax
  UFG::qFileSystem *mFileSystem; // rbx
  UFG::qNode<UFG::qFileOp,UFG::qFileOp> *v12; // rax

  v4 = priority;
  v6 = 0i64;
  UFG::qMutex::Lock((LPCRITICAL_SECTION)&this->mMutex);
  mFile = file_op->mFile;
  v8 = mFile && file_op->mType != OP_CLOSE && mFile->mCloseState;
  if ( file_op->mDevice != 0i64 && !v8 && !this->mFileSystem->mFatalIOError )
  {
    *(_DWORD *)file_op->mStatus = 1;
    if ( mFile )
    {
      UFG::qMutex::Lock((LPCRITICAL_SECTION)&mFile->mStateMutex);
      ++mFile->mNumAsyncOps;
      UFG::qMutex::Unlock((LPCRITICAL_SECTION)&mFile->mStateMutex);
    }
    v9 = &this->mQueuedOps[v4];
    mPrev = v9->mNode.mPrev;
    mPrev->mNext = file_op;
    file_op->mNext = &v9->mNode;
    file_op->mPrev = mPrev;
    v9->mNode.mPrev = file_op;
    UFG::qEvent::Signal(&this->mEvent);
  }
  else
  {
    *(_DWORD *)file_op->mStatus = 5;
    v6 = file_op;
  }
  UFG::qMutex::Unlock((LPCRITICAL_SECTION)&this->mMutex);
  if ( v6 )
  {
    mFileSystem = this->mFileSystem;
    UFG::qMutex::Lock((LPCRITICAL_SECTION)&mFileSystem->mMutex);
    v12 = mFileSystem->mDoneFileOps.mNode.mPrev;
    v12->mNext = file_op;
    file_op->mPrev = v12;
    file_op->mNext = &mFileSystem->mDoneFileOps.mNode;
    mFileSystem->mDoneFileOps.mNode.mPrev = file_op;
    UFG::qMutex::Unlock((LPCRITICAL_SECTION)&mFileSystem->mMutex);
  }
}

// File Line: 1278
// RVA: 0x169A70
UFG::qFileOp *__fastcall UFG::qFileOpList::Completed(UFG::qFileOpList *this, UFG::qFileOp *file_op)
{
  UFG::qFile *mFile; // rbx
  UFG::qFileOp *mAsyncCloseOp; // rdi
  bool v6; // zf
  UFG::qNode<UFG::qFileOp,UFG::qFileOp> *mPrev; // rdx

  mFile = file_op->mFile;
  mAsyncCloseOp = 0i64;
  if ( mFile )
  {
    UFG::qMutex::Lock((LPCRITICAL_SECTION)&mFile->mStateMutex);
    v6 = mFile->mNumAsyncOps-- == 1;
    if ( v6 && mFile->mAsyncCloseOp )
      mAsyncCloseOp = mFile->mAsyncCloseOp;
    UFG::qMutex::Unlock((LPCRITICAL_SECTION)&mFile->mStateMutex);
  }
  UFG::qMutex::Lock((LPCRITICAL_SECTION)&this->mMutex);
  mPrev = this->mDoneOps.mNode.mPrev;
  mPrev->mNext = file_op;
  file_op->mPrev = mPrev;
  file_op->mNext = &this->mDoneOps.mNode;
  this->mDoneOps.mNode.mPrev = file_op;
  UFG::qMutex::Unlock((LPCRITICAL_SECTION)&this->mMutex);
  return mAsyncCloseOp;
}

// File Line: 1327
// RVA: 0x160EE0
void __fastcall UFG::qFileIoThread::qFileIoThread(UFG::qFileIoThread *this, const char *name)
{
  UFG::qThread::qThread(&this->mThread, name);
  this->mName = name;
  this->mDevice = 0i64;
  this->mFileOpList = 0i64;
}

// File Line: 1335
// RVA: 0x163930
void __fastcall UFG::qFileIoThread::~qFileIoThread(UFG::qFileIoThread *this)
{
  _((AMD_HD3D *)&this->mThread);
}

// File Line: 1339
// RVA: 0x17DEB0
void __fastcall UFG::qFileIoThread::Start(
        UFG::qFileIoThread *this,
        UFG::qFileDevice *device,
        UFG::qFileOpList *file_op_list,
        unsigned int thread_stack_size,
        int thread_priority,
        int thread_logical_core_id)
{
  UFG::qThread *p_mThread; // rcx

  p_mThread = &this->mThread;
  file_op_list->mFileSystem = device->mFileSystem;
  p_mThread[1].mThreadParam = device;
  *(_QWORD *)&p_mThread[1].mStacksize = file_op_list;
  LOBYTE(p_mThread[1].mLogicalCoreID) = 0;
  UFG::qBaseNodeRB::SetUID((UFG::qBaseNodeRB *)p_mThread, thread_stack_size);
  UFG::qThread::SetThreadPriority(&this->mThread, thread_priority);
  UFG::qThread::SetLogicalCoreID(&this->mThread, thread_logical_core_id);
  UFG::qThread::Start(&this->mThread, UFG::qFileIoThread::ThreadFuncBridge, this);
}

// File Line: 1357
// RVA: 0x17DFA0
void __fastcall UFG::qFileIoThread::Stop(UFG::qFileIoThread *this)
{
  this->mStopRequested = 1;
  UFG::qEvent::Signal(&this->mFileOpList->mEvent);
  UFG::qThread::WaitForCompletion(&this->mThread);
}

// File Line: 1368
// RVA: 0x17E5D0
// attributes: thunk
void __fastcall UFG::qFileIoThread::ThreadFuncBridge(UFG::qFileIoThread *param)
{
  UFG::qFileIoThread::ThreadFunc(param);
}

// File Line: 1373
// RVA: 0x17E350
void __fastcall UFG::qFileIoThread::ThreadFunc(UFG::qFileIoThread *this)
{
  UFG::qFileOpList *mFileOpList; // r13
  UFG::qFileSystem *mFileSystem; // r12
  UFG::qFileIoThread *v3; // r14
  UFG::qEvent *p_mEvent; // r15
  _RTL_CRITICAL_SECTION *p_mMutex; // rsi
  UFG::qNode<UFG::qFileOp,UFG::qFileOp> *v6; // rdi
  bool v7; // bl
  UFG::qList<UFG::qFileOp,UFG::qFileOp,1,0> *mQueuedOps; // rbp
  __int64 v9; // r8
  UFG::qList<UFG::qFileOp,UFG::qFileOp,1,0> *v10; // rdx
  UFG::qList<UFG::qFileOp,UFG::qFileOp,1,0> *mNext; // rax
  UFG::qNode<UFG::qFileOp,UFG::qFileOp> *mPrev; // rcx
  UFG::qNode<UFG::qFileOp,UFG::qFileOp> *v13; // rax
  unsigned __int64 Ticks; // rax
  UFG::qNode<UFG::qFileOp,UFG::qFileOp> *v15; // rax
  __int64 v16; // rcx
  UFG::qList<UFG::qFileOp,UFG::qFileOp,1,0> *v17; // rax
  int v18; // ebx
  UFG::qNode<UFG::qFileOp,UFG::qFileOp> *v19; // rdx
  UFG::qNode<UFG::qFileOp,UFG::qFileOp> *v20; // rcx
  UFG::qFileOp *v21; // rax
  UFG::qNode<UFG::qFileOp,UFG::qFileOp> *v22; // r14
  __int64 v23; // r15
  UFG::qNode<UFG::qFileOp,UFG::qFileOp> *p_mNode; // rbx
  UFG::qList<UFG::qFileOp,UFG::qFileOp,1,0> *v25; // rsi
  unsigned __int64 v26; // rax
  float TickTime; // xmm0_4
  UFG::qNode<UFG::qFileOp,UFG::qFileOp> *v28; // rcx
  UFG::qNode<UFG::qFileOp,UFG::qFileOp> *v29; // rax

  mFileOpList = this->mFileOpList;
  mFileSystem = this->mDevice->mFileSystem;
  v3 = this;
  if ( !this->mStopRequested )
  {
    p_mEvent = &mFileOpList->mEvent;
    do
    {
      UFG::qEvent::Wait(p_mEvent);
      if ( v3->mStopRequested )
        break;
      p_mMutex = (_RTL_CRITICAL_SECTION *)&mFileOpList->mMutex;
      v6 = 0i64;
      v7 = 0;
      UFG::qMutex::Lock((LPCRITICAL_SECTION)&mFileOpList->mMutex);
      mQueuedOps = mFileOpList->mQueuedOps;
      v9 = 0i64;
      v10 = mFileOpList->mQueuedOps;
      while ( v9 < 3 )
      {
        mNext = (UFG::qList<UFG::qFileOp,UFG::qFileOp,1,0> *)v10->mNode.mNext;
        if ( mNext != v10 )
        {
          mPrev = mNext->mNode.mPrev;
          v6 = v10->mNode.mNext;
          v13 = mNext->mNode.mNext;
          mPrev->mNext = v13;
          v13->mPrev = mPrev;
          v6->mPrev = v6;
          v6->mNext = v6;
        }
        ++v9;
        ++v10;
        if ( v6 )
        {
          HIDWORD(v6[1].mNext) = 2;
          Ticks = UFG::qGetTicks();
          *((float *)&v6[6].mPrev + 1) = UFG::qGetTickTime(mFileSystem->mStartTicks, Ticks) - *(float *)&v6[6].mPrev;
          v15 = mFileOpList->mExecutingOps.mNode.mPrev;
          v15->mNext = v6;
          v6->mPrev = v15;
          v6->mNext = &mFileOpList->mExecutingOps.mNode;
          mFileOpList->mExecutingOps.mNode.mPrev = v6;
          break;
        }
      }
      v16 = 0i64;
      v17 = mFileOpList->mQueuedOps;
      do
      {
        if ( v16 >= 3 )
          break;
        v7 = v17->mNode.mNext != (UFG::qNode<UFG::qFileOp,UFG::qFileOp> *)v17;
        ++v16;
        ++v17;
      }
      while ( !v7 );
      UFG::qMutex::Unlock((LPCRITICAL_SECTION)&mFileOpList->mMutex);
      if ( v7 )
        UFG::qEvent::Signal(p_mEvent);
      if ( v6 )
      {
        v18 = UFG::qFileOp::Execute((UFG::qFileOp *)v6);
        UFG::qMutex::Lock((LPCRITICAL_SECTION)&mFileOpList->mMutex);
        v19 = v6->mPrev;
        v20 = v6->mNext;
        v19->mNext = v20;
        v20->mPrev = v19;
        v6->mPrev = v6;
        v6->mNext = v6;
        v21 = UFG::qFileOpList::Completed(mFileOpList, (UFG::qFileOp *)v6);
        if ( HIDWORD(v6[1].mNext) == 2 )
          HIDWORD(v6[1].mNext) = v18;
        if ( !LODWORD(v6[1].mNext) && HIDWORD(v6[1].mNext) != 3 )
        {
          v22 = v6[4].mNext;
          v23 = 3i64;
          do
          {
            p_mNode = mQueuedOps->mNode.mNext;
            if ( p_mNode != (UFG::qNode<UFG::qFileOp,UFG::qFileOp> *)mQueuedOps )
            {
              do
              {
                v25 = (UFG::qList<UFG::qFileOp,UFG::qFileOp,1,0> *)p_mNode->mNext;
                if ( p_mNode[4].mNext == v22 && LODWORD(p_mNode[1].mNext) != 1 )
                {
                  v26 = UFG::qGetTicks();
                  TickTime = UFG::qGetTickTime(mFileSystem->mStartTicks, v26);
                  v28 = p_mNode->mPrev;
                  v29 = p_mNode->mNext;
                  HIDWORD(p_mNode[1].mNext) = 5;
                  *((float *)&p_mNode[6].mPrev + 1) = TickTime - *(float *)&v6[6].mPrev;
                  *(float *)&p_mNode[6].mNext = (float)(TickTime - *(float *)&v6[6].mPrev)
                                              - *((float *)&v6[6].mPrev + 1);
                  v28->mNext = v29;
                  v29->mPrev = v28;
                  p_mNode->mPrev = p_mNode;
                  p_mNode->mNext = p_mNode;
                  v21 = UFG::qFileOpList::Completed(mFileOpList, (UFG::qFileOp *)p_mNode);
                }
                p_mNode = &v25->mNode;
              }
              while ( v25 != mQueuedOps );
            }
            ++mQueuedOps;
            --v23;
          }
          while ( v23 );
          v3 = this;
          p_mMutex = (_RTL_CRITICAL_SECTION *)&mFileOpList->mMutex;
          p_mEvent = &mFileOpList->mEvent;
        }
        if ( v21 )
          UFG::qFileOpList::Queue(mFileOpList, v21, 0);
        UFG::qMutex::Unlock(p_mMutex);
      }
    }
    while ( !v3->mStopRequested );
  }
}

// File Line: 1522
// RVA: 0x160DF0
void __fastcall UFG::qFileDevice::qFileDevice(
        UFG::qFileDevice *this,
        const char *name,
        int supported_access_modes,
        int max_open_files,
        UFG::qFileDevice::Casing casing)
{
  unsigned int v9; // edx
  char i; // al

  this->mPrev = &this->UFG::qNode<UFG::qFileDevice,UFG::qFileDevice>;
  this->mNext = &this->UFG::qNode<UFG::qFileDevice,UFG::qFileDevice>;
  this->vfptr = (UFG::qFileDeviceVtbl *)&UFG::qFileDevice::`vftable;
  this->mFileOpLists.mNode.mPrev = &this->mFileOpLists.mNode;
  this->mFileOpLists.mNode.mNext = &this->mFileOpLists.mNode;
  UFG::qMutex::qMutex(&this->mMutex, &customCaption);
  this->mOpenFiles.mNode.mPrev = &this->mOpenFiles.mNode;
  this->mOpenFiles.mNode.mNext = &this->mOpenFiles.mNode;
  this->mClosedFiles.mNode.mPrev = &this->mClosedFiles.mNode;
  this->mClosedFiles.mNode.mNext = &this->mClosedFiles.mNode;
  this->mFileSystem = 0i64;
  this->mName = name;
  v9 = -1;
  if ( name )
  {
    for ( i = *name; *name; i = *name )
    {
      v9 = (v9 << 8) ^ sCrcTable32[(unsigned __int8)(i ^ HIBYTE(v9))];
      ++name;
    }
  }
  this->mNameHash = v9;
  this->mSupportedAccessModes = supported_access_modes;
  this->mMaxOpenFiles = max_open_files;
  this->mCaseSensitive = casing;
}

// File Line: 1534
// RVA: 0x163860
void __fastcall UFG::qFileDevice::~qFileDevice(UFG::qFileDevice *this)
{
  UFG::qList<UFG::qFile,UFG::qFile,1,0> *p_mClosedFiles; // rbx
  UFG::qNode<UFG::qFile,UFG::qFile> *mPrev; // rcx
  UFG::qNode<UFG::qFile,UFG::qFile> *mNext; // rax
  UFG::qNode<UFG::qFile,UFG::qFile> *v5; // rcx
  UFG::qNode<UFG::qFile,UFG::qFile> *v6; // rax
  UFG::qNode<UFG::qFileOpList,UFG::qFileOpList> *v7; // rcx
  UFG::qNode<UFG::qFileOpList,UFG::qFileOpList> *v8; // rax
  UFG::qNode<UFG::qFileDevice,UFG::qFileDevice> *v9; // rcx
  UFG::qNode<UFG::qFileDevice,UFG::qFileDevice> *v10; // rax

  this->vfptr = (UFG::qFileDeviceVtbl *)&UFG::qFileDevice::`vftable;
  p_mClosedFiles = &this->mClosedFiles;
  UFG::qList<UFG::qFile,UFG::qFile,1,0>::DeleteNodes(&this->mClosedFiles);
  mPrev = p_mClosedFiles->mNode.mPrev;
  mNext = p_mClosedFiles->mNode.mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  p_mClosedFiles->mNode.mPrev = &p_mClosedFiles->mNode;
  p_mClosedFiles->mNode.mNext = &p_mClosedFiles->mNode;
  UFG::qList<UFG::qFile,UFG::qFile,1,0>::DeleteNodes(&this->mOpenFiles);
  v5 = this->mOpenFiles.mNode.mPrev;
  v6 = this->mOpenFiles.mNode.mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  this->mOpenFiles.mNode.mPrev = &this->mOpenFiles.mNode;
  this->mOpenFiles.mNode.mNext = &this->mOpenFiles.mNode;
  Scaleform::Lock::~Lock((LPCRITICAL_SECTION)&this->mMutex);
  UFG::qList<UFG::qFileOpList,UFG::qFileOpList,1,0>::DeleteNodes(&this->mFileOpLists);
  v7 = this->mFileOpLists.mNode.mPrev;
  v8 = this->mFileOpLists.mNode.mNext;
  v7->mNext = v8;
  v8->mPrev = v7;
  this->mFileOpLists.mNode.mPrev = &this->mFileOpLists.mNode;
  this->mFileOpLists.mNode.mNext = &this->mFileOpLists.mNode;
  v9 = this->mPrev;
  v10 = this->mNext;
  v9->mNext = v10;
  v10->mPrev = v9;
  this->mPrev = &this->UFG::qNode<UFG::qFileDevice,UFG::qFileDevice>;
  this->mNext = &this->UFG::qNode<UFG::qFileDevice,UFG::qFileDevice>;
}

// File Line: 1547
// RVA: 0x1613A0
void __fastcall UFG::qFileSystem::qFileSystem(UFG::qFileSystem *this)
{
  this->mDevices.mNode.mPrev = &this->mDevices.mNode;
  this->mDevices.mNode.mNext = &this->mDevices.mNode;
  UFG::qMutex::qMutex(&this->mMappingMutex, &customCaption);
  this->mMappingCallbacks.mNode.mPrev = &this->mMappingCallbacks.mNode;
  this->mMappingCallbacks.mNode.mNext = &this->mMappingCallbacks.mNode;
  this->mMappingLocations.mTree.mRoot.mParent = 0i64;
  this->mMappingLocations.mTree.mRoot.mChild[0] = 0i64;
  this->mMappingLocations.mTree.mRoot.mChild[1] = 0i64;
  this->mMappingLocations.mTree.mNULL.mParent = 0i64;
  this->mMappingLocations.mTree.mNULL.mChild[0] = 0i64;
  this->mMappingLocations.mTree.mNULL.mChild[1] = 0i64;
  this->mMappingLocations.mTree.mNULL.mParent = (UFG::qBaseNodeRB *)((unsigned __int64)&this->mMappingLocations.mTree.mNULL | (__int64)this->mMappingLocations.mTree.mNULL.mParent & 1);
  this->mMappingLocations.mTree.mNULL.mChild[0] = &this->mMappingLocations.mTree.mNULL;
  this->mMappingLocations.mTree.mNULL.mChild[1] = &this->mMappingLocations.mTree.mNULL;
  this->mMappingLocations.mTree.mNULL.mParent = (UFG::qBaseNodeRB *)((unsigned __int64)this->mMappingLocations.mTree.mNULL.mParent & ~1ui64);
  this->mMappingLocations.mTree.mNULL.mUID = 0;
  this->mMappingLocations.mTree.mRoot.mParent = (UFG::qBaseNodeRB *)((unsigned __int64)&this->mMappingLocations.mTree.mNULL | (__int64)this->mMappingLocations.mTree.mRoot.mParent & 1);
  this->mMappingLocations.mTree.mRoot.mChild[0] = &this->mMappingLocations.mTree.mNULL;
  this->mMappingLocations.mTree.mRoot.mChild[1] = &this->mMappingLocations.mTree.mNULL;
  this->mMappingLocations.mTree.mRoot.mParent = (UFG::qBaseNodeRB *)((unsigned __int64)this->mMappingLocations.mTree.mRoot.mParent & ~1ui64);
  this->mMappingLocations.mTree.mRoot.mUID = -1;
  this->mMappingLocations.mTree.mCount = 0;
  UFG::qMutex::qMutex(&this->mMutex, &customCaption);
  UFG::qEvent::qEvent(&this->mEvent);
  this->mDoneFileOps.mNode.mPrev = &this->mDoneFileOps.mNode;
  this->mDoneFileOps.mNode.mNext = &this->mDoneFileOps.mNode;
  *(_WORD *)&this->mReportSyncFileOps = 0;
  this->mFatalIOError = 0;
  this->mMapFilenameToDeviceCallback = 0i64;
  UFG::qEvent::Create(&this->mEvent, "qFileSystem", 0);
}

// File Line: 1563
// RVA: 0x163B70
void __fastcall UFG::qFileSystem::~qFileSystem(UFG::qFileSystem *this)
{
  bool *i; // rsi
  __int64 v3; // rbx
  char *v4; // rdi
  char *j; // r8
  __int64 v6; // rdx
  _QWORD *v7; // rax
  UFG::qList<UFG::qFileOp,UFG::qFileOp,1,0> *p_mDoneFileOps; // rdi
  UFG::qFileOp *mNext; // rbx
  UFG::qNode<UFG::qFileOp,UFG::qFileOp> *mPrev; // rcx
  UFG::qNode<UFG::qFileOp,UFG::qFileOp> *v11; // rax
  UFG::qNode<UFG::qFileOp,UFG::qFileOp> *v12; // rcx
  UFG::qNode<UFG::qFileOp,UFG::qFileOp> *v13; // rax
  Render::SkinningCacheNode *Head; // rdi
  UFG::qList<UFG::qFileMappingCallback,UFG::qFileMappingCallback,1,0> *p_mMappingCallbacks; // rbx
  UFG::qFileSystem *v16; // rdx
  __int64 mStartTicks; // rcx
  __int64 *v18; // rax
  __int64 v19; // rcx
  __int64 *v20; // rax
  UFG::qNode<UFG::qFileMappingCallback,UFG::qFileMappingCallback> *v21; // rcx
  UFG::qNode<UFG::qFileMappingCallback,UFG::qFileMappingCallback> *v22; // rax
  UFG::qList<UFG::qFileDevice,UFG::qFileDevice,1,0> *p_mDevices; // rbx
  bool *k; // rax
  _QWORD *v25; // rdx
  __int64 v26; // rcx
  _QWORD *v27; // rax
  UFG::qNode<UFG::qFileDevice,UFG::qFileDevice> *v28; // rcx
  UFG::qNode<UFG::qFileDevice,UFG::qFileDevice> *v29; // rax

  do
  {
    UFG::qFileSystem::Service(this);
    UFG::qSleep(1u);
  }
  while ( UFG::qFileSystem::IsBusy(this) );
  for ( i = (bool *)&this->mDevices.mNode.mNext[-1].mNext;
        i != &this->mReportSyncFileOps;
        i = (bool *)(*((_QWORD *)i + 2) - 8i64) )
  {
    UFG::qMutex::Lock((LPCRITICAL_SECTION)(i + 72));
    v3 = *((_QWORD *)i + 16);
    v4 = (char *)(i + 120);
    if ( (bool *)v3 != i + 120 )
    {
      do
      {
        UFG::qPrintf("WARNING: qFile was left open!  file = %s\n", (const char *)(v3 + 160));
        v3 = *(_QWORD *)(v3 + 8);
      }
      while ( (char *)v3 != v4 );
    }
    for ( j = (char *)*((_QWORD *)i + 16); j != v4; j = (char *)*((_QWORD *)i + 16) )
    {
      v6 = *(_QWORD *)j;
      v7 = (_QWORD *)*((_QWORD *)j + 1);
      *(_QWORD *)(v6 + 8) = v7;
      *v7 = v6;
      *(_QWORD *)j = j;
      *((_QWORD *)j + 1) = j;
    }
    UFG::qMutex::Unlock((LPCRITICAL_SECTION)(i + 72));
  }
  p_mDoneFileOps = &this->mDoneFileOps;
  mNext = (UFG::qFileOp *)this->mDoneFileOps.mNode.mNext;
  if ( mNext != (UFG::qFileOp *)&this->mDoneFileOps )
  {
    do
    {
      mPrev = mNext->mPrev;
      v11 = mNext->mNext;
      mPrev->mNext = v11;
      v11->mPrev = mPrev;
      mNext->mPrev = mNext;
      mNext->mNext = mNext;
      UFG::qFileOp::~qFileOp(mNext);
      UFG::qMemoryPool::Free(UFG::gMainMemoryPool, mNext);
      mNext = (UFG::qFileOp *)this->mDoneFileOps.mNode.mNext;
    }
    while ( mNext != (UFG::qFileOp *)p_mDoneFileOps );
  }
  v12 = p_mDoneFileOps->mNode.mPrev;
  v13 = this->mDoneFileOps.mNode.mNext;
  v12->mNext = v13;
  v13->mPrev = v12;
  p_mDoneFileOps->mNode.mPrev = &p_mDoneFileOps->mNode;
  this->mDoneFileOps.mNode.mNext = &this->mDoneFileOps.mNode;
  UFG::qEvent::~qEvent(&this->mEvent);
  Scaleform::Lock::~Lock((LPCRITICAL_SECTION)&this->mMutex);
  while ( this->mMappingLocations.mTree.mCount )
  {
    Head = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&this->mMappingLocations);
    UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
      (UFG::qBaseTreeVariableRB<unsigned __int64> *)&this->mMappingLocations,
      &Head->mNode);
    if ( Head )
    {
      `eh vector destructor iterator(&Head[1], 0x28ui64, 2, (void (__fastcall *)(void *))UFG::qString::~qString);
      UFG::qMemoryPool::Free(UFG::gMainMemoryPool, Head);
    }
  }
  this->mMappingLocations.mTree.mRoot.mParent = (UFG::qBaseNodeRB *)((unsigned __int64)&this->mMappingLocations.mTree.mNULL | (__int64)this->mMappingLocations.mTree.mRoot.mParent & 1);
  this->mMappingLocations.mTree.mRoot.mChild[0] = &this->mMappingLocations.mTree.mNULL;
  this->mMappingLocations.mTree.mRoot.mChild[1] = &this->mMappingLocations.mTree.mNULL;
  this->mMappingLocations.mTree.mCount = 0;
  p_mMappingCallbacks = &this->mMappingCallbacks;
  v16 = (UFG::qFileSystem *)this->mMappingCallbacks.mNode.mNext;
  if ( v16 != (UFG::qFileSystem *)&this->mMappingCallbacks )
  {
    do
    {
      mStartTicks = v16->mStartTicks;
      v18 = *(__int64 **)&v16->mReportSyncFileOps;
      *(_QWORD *)(mStartTicks + 8) = v18;
      *v18 = mStartTicks;
      v16->mStartTicks = (__int64)v16;
      *(_QWORD *)&v16->mReportSyncFileOps = v16;
      v19 = v16->mStartTicks;
      v20 = *(__int64 **)&v16->mReportSyncFileOps;
      *(_QWORD *)(v19 + 8) = v20;
      *v20 = v19;
      v16->mStartTicks = (__int64)v16;
      *(_QWORD *)&v16->mReportSyncFileOps = v16;
      UFG::qMemoryPool::Free(UFG::gMainMemoryPool, v16);
      v16 = (UFG::qFileSystem *)this->mMappingCallbacks.mNode.mNext;
    }
    while ( v16 != (UFG::qFileSystem *)p_mMappingCallbacks );
  }
  v21 = p_mMappingCallbacks->mNode.mPrev;
  v22 = this->mMappingCallbacks.mNode.mNext;
  v21->mNext = v22;
  v22->mPrev = v21;
  p_mMappingCallbacks->mNode.mPrev = &p_mMappingCallbacks->mNode;
  this->mMappingCallbacks.mNode.mNext = &this->mMappingCallbacks.mNode;
  Scaleform::Lock::~Lock((LPCRITICAL_SECTION)&this->mMappingMutex);
  p_mDevices = &this->mDevices;
  for ( k = (bool *)&this->mDevices.mNode.mNext[-1].mNext;
        k != &this->mReportSyncFileOps;
        k = (bool *)&this->mDevices.mNode.mNext[-1].mNext )
  {
    v25 = k + 8;
    v26 = *((_QWORD *)k + 1);
    v27 = (_QWORD *)*((_QWORD *)k + 2);
    *(_QWORD *)(v26 + 8) = v27;
    *v27 = v26;
    *v25 = v25;
    v25[1] = v25;
    if ( v25 != (_QWORD *)8 )
      (*(void (__fastcall **)(_QWORD *, __int64))*(v25 - 1))(v25 - 1, 1i64);
  }
  v28 = p_mDevices->mNode.mPrev;
  v29 = this->mDevices.mNode.mNext;
  v28->mNext = v29;
  v29->mPrev = v28;
  p_mDevices->mNode.mPrev = &p_mDevices->mNode;
  this->mDevices.mNode.mNext = &this->mDevices.mNode;
}

// File Line: 1613
// RVA: 0x173940
void __fastcall UFG::qFileSystem::InitDevice(UFG::qFileSystem *this, UFG::qFileDevice *device)
{
  UFG::qNode<UFG::qFileDevice,UFG::qFileDevice> *mPrev; // rax
  UFG::qFileDeviceVtbl *vfptr; // rax

  mPrev = this->mDevices.mNode.mPrev;
  mPrev->mNext = &device->UFG::qNode<UFG::qFileDevice,UFG::qFileDevice>;
  device->mPrev = mPrev;
  device->mNext = &this->mDevices.mNode;
  this->mDevices.mNode.mPrev = &device->UFG::qNode<UFG::qFileDevice,UFG::qFileDevice>;
  vfptr = device->vfptr;
  device->mFileSystem = this;
  (*(void (__fastcall **)(UFG::qFileDevice *))vfptr->gap8)(device);
}

// File Line: 1624
// RVA: 0x168400
void __fastcall UFG::qFileSystem::CloseDevice(UFG::qFileSystem *this, UFG::qFileDevice *device)
{
  UFG::qNode<UFG::qFileDevice,UFG::qFileDevice> *mPrev; // rcx
  UFG::qNode<UFG::qFileDevice,UFG::qFileDevice> *mNext; // rax

  if ( device->mFileSystem )
  {
    (*(void (__fastcall **)(UFG::qFileDevice *))&device->vfptr->gap8[8])(device);
    device->mFileSystem = 0i64;
    mPrev = device->mPrev;
    mNext = device->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    device->mPrev = &device->UFG::qNode<UFG::qFileDevice,UFG::qFileDevice>;
    device->mNext = &device->UFG::qNode<UFG::qFileDevice,UFG::qFileDevice>;
  }
}

// File Line: 1715
// RVA: 0x170560
UFG::qString *__fastcall UFG::qFileSystem::GetFileMapping(
        UFG::qFileSystem *this,
        UFG::qString *result,
        unsigned int file_map_type,
        const char *mapping_name)
{
  __int64 v5; // rsi
  unsigned int v8; // eax
  UFG::qTreeRB<UFG::qSharedStringData,UFG::qSharedStringData,0> *v9; // rax
  UFG::qNode<UFG::qString,UFG::qString> *mPrev; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *mNext; // rax
  UFG::qString v13; // [rsp+40h] [rbp-30h] BYREF

  v5 = (int)file_map_type;
  v13.mPrev = &v13;
  v13.mNext = &v13;
  *(_QWORD *)&v13.mMagic = 16909060i64;
  v13.mData = (char *)UFG::qString::sEmptyString;
  *(_QWORD *)&v13.mStringHash32 = -1i64;
  if ( mapping_name && *mapping_name && file_map_type <= 1 )
  {
    UFG::qMutex::Lock((LPCRITICAL_SECTION)&this->mMappingMutex);
    v8 = UFG::qStringHashUpper32(mapping_name, 0xFFFFFFFF);
    v9 = UFG::qTreeRB<UFG::qFileMapLocation,UFG::qFileMapLocation,1>::Get(
           (UFG::qTreeRB<UFG::qSharedStringData,UFG::qSharedStringData,0> *)&this->mMappingLocations,
           v8);
    if ( v9 )
      UFG::qString::Set(
        &v13,
        *((const char **)&v9->mTree.mCount + 5 * v5),
        HIDWORD(v9->mTree.mNULL.mChild[5 * v5 + 2]),
        0i64,
        0);
    UFG::qMutex::Unlock((LPCRITICAL_SECTION)&this->mMappingMutex);
    result->mPrev = result;
    result->mNext = result;
    result->mMagic = 16909060;
    result->mData = (char *)UFG::qString::sEmptyString;
    result->mLength = 0;
    UFG::qString::Set(result, v13.mData, v13.mLength, 0i64, 0);
    result->mStringHash32 = v13.mStringHash32;
    result->mStringHashUpper32 = v13.mStringHashUpper32;
    if ( v13.mData != UFG::qString::sEmptyString && v13.mData )
      UFG::qMemoryPool::Free(UFG::gMainMemoryPool, v13.mData);
    v13.mMagic = 0;
  }
  else
  {
    result->mPrev = result;
    result->mNext = result;
    result->mMagic = 16909060;
    result->mData = (char *)UFG::qString::sEmptyString;
    result->mLength = 0;
    UFG::qString::Set(result, v13.mData, v13.mLength, 0i64, 0);
    result->mStringHash32 = v13.mStringHash32;
    result->mStringHashUpper32 = v13.mStringHashUpper32;
    if ( v13.mData != UFG::qString::sEmptyString && v13.mData )
      UFG::qMemoryPool::Free(UFG::gMainMemoryPool, v13.mData);
    v13.mMagic = 0;
  }
  mPrev = v13.mPrev;
  mNext = v13.mNext;
  v13.mPrev->mNext = v13.mNext;
  mNext->mPrev = mPrev;
  return result;
}

// File Line: 1740
// RVA: 0x177680
UFG::qString *__fastcall UFG::qFileSystem::MapFilename(
        UFG::qFileSystem *this,
        UFG::qString *result,
        unsigned int file_map_type,
        const char *filename)
{
  _RTL_CRITICAL_SECTION *p_mMappingMutex; // r13
  char *v9; // rbx
  const char *v10; // r9
  int v11; // eax
  _BYTE *v12; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *mPrev; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *mNext; // rax
  UFG::qNode<UFG::qString,UFG::qString> *v16; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *v17; // rax
  UFG::qNode<UFG::qFileMappingCallback,UFG::qFileMappingCallback> *v18; // rbx
  UFG::qList<UFG::qFileMappingCallback,UFG::qFileMappingCallback,1,0> *i; // r14
  UFG::qNode<UFG::qString,UFG::qString> *v20; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *v21; // rax
  UFG::qString v23; // [rsp+10h] [rbp-51h] BYREF
  UFG::qString v24; // [rsp+38h] [rbp-29h] BYREF
  UFG::qString resulta; // [rsp+60h] [rbp-1h] BYREF
  __int64 v26; // [rsp+88h] [rbp+27h]

  v26 = -2i64;
  UFG::qString::qString(&v24, filename);
  if ( filename && *filename )
  {
    p_mMappingMutex = (_RTL_CRITICAL_SECTION *)&this->mMappingMutex;
    UFG::qMutex::Lock((LPCRITICAL_SECTION)&this->mMappingMutex);
    if ( *filename == 36 && filename[1] == 40 )
    {
      v9 = UFG::qStringFind(filename + 2, ")");
      if ( v9 )
      {
        v24.mPrev = &v24;
        v24.mNext = &v24;
        *(_QWORD *)&v24.mMagic = 16909060i64;
        v24.mData = (char *)UFG::qString::sEmptyString;
        *(_QWORD *)&v24.mStringHash32 = -1i64;
        UFG::qString::Set(&v24, filename + 2, (_DWORD)v9 - (_DWORD)filename - 2, 0i64, 0);
        UFG::qFileSystem::GetFileMapping(this, &resulta, file_map_type, v24.mData);
        v10 = v9 + 1;
        if ( v9 == (char *)-1i64 )
        {
          v11 = 0;
        }
        else
        {
          v12 = v9 + 1;
          while ( *v12++ )
            ;
          v11 = (_DWORD)v12 - (_DWORD)v10 - 1;
        }
        UFG::qString::Set(&v23, resulta.mData, resulta.mLength, v10, v11);
        if ( resulta.mData != UFG::qString::sEmptyString && resulta.mData )
          UFG::qMemoryPool::Free(UFG::gMainMemoryPool, resulta.mData);
        resulta.mMagic = 0;
        mPrev = resulta.mPrev;
        mNext = resulta.mNext;
        resulta.mPrev->mNext = resulta.mNext;
        mNext->mPrev = mPrev;
        resulta.mPrev = &resulta;
        resulta.mNext = &resulta;
        if ( v24.mData != UFG::qString::sEmptyString && v24.mData )
          UFG::qMemoryPool::Free(UFG::gMainMemoryPool, v24.mData);
        v24.mMagic = 0;
        v16 = v24.mPrev;
        v17 = v24.mNext;
        v24.mPrev->mNext = v24.mNext;
        v17->mPrev = v16;
        v24.mPrev = &v24;
        v24.mNext = &v24;
      }
      else
      {
        UFG::qPrintf(
          "ERROR: filename has an incorrect File Mapping location!\n"
          " filename = %s\n"
          " Message  = If a filename starts with $( it must have a trailing )\n"
          "            i.e. $(InstallDir)\blah.bin\n",
          filename);
      }
    }
    v18 = this->mMappingCallbacks.mNode.mNext;
    for ( i = &this->mMappingCallbacks;
          v18 != (UFG::qNode<UFG::qFileMappingCallback,UFG::qFileMappingCallback> *)i;
          v18 = v18->mNext )
    {
      ((void (__fastcall *)(_QWORD, const char *, UFG::qString *, UFG::qNode<UFG::qFileMappingCallback,UFG::qFileMappingCallback> *))v18[1].mPrev)(
        file_map_type,
        filename,
        &v23,
        v18[1].mNext);
    }
    UFG::qMutex::Unlock(p_mMappingMutex);
    result->mPrev = result;
    result->mNext = result;
    result->mMagic = 16909060;
    result->mData = (char *)UFG::qString::sEmptyString;
    result->mLength = 0;
    UFG::qString::Set(result, v23.mData, v23.mLength, 0i64, 0);
    result->mStringHash32 = v23.mStringHash32;
    result->mStringHashUpper32 = v23.mStringHashUpper32;
    if ( v23.mData != UFG::qString::sEmptyString && v23.mData )
      UFG::qMemoryPool::Free(UFG::gMainMemoryPool, v23.mData);
    v23.mMagic = 0;
  }
  else
  {
    result->mPrev = result;
    result->mNext = result;
    result->mMagic = 16909060;
    result->mData = (char *)UFG::qString::sEmptyString;
    result->mLength = 0;
    UFG::qString::Set(result, v23.mData, v23.mLength, 0i64, 0);
    result->mStringHash32 = v23.mStringHash32;
    result->mStringHashUpper32 = v23.mStringHashUpper32;
    if ( v23.mData != UFG::qString::sEmptyString && v23.mData )
      UFG::qMemoryPool::Free(UFG::gMainMemoryPool, v23.mData);
    v23.mMagic = 0;
  }
  v20 = v23.mPrev;
  v21 = v23.mNext;
  v23.mPrev->mNext = v23.mNext;
  v21->mPrev = v20;
  return result;
}

// File Line: 1793
// RVA: 0x1779A0
UFG::qFileDevice *__fastcall UFG::qFileSystem::MapFilenameToDevice(UFG::qFileSystem *this, const char *filename)
{
  UFG::qFileDevice *(__fastcall *mMapFilenameToDeviceCallback)(const char *); // rax
  UFG::qFileDevice *v5; // rbx
  UFG::qNode<UFG::qString,UFG::qString> *mPrev; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *mNext; // rax
  UFG::qString result; // [rsp+28h] [rbp-30h] BYREF

  UFG::qFileSystem::MapFilename(this, &result, 0, filename);
  mMapFilenameToDeviceCallback = this->mMapFilenameToDeviceCallback;
  if ( !mMapFilenameToDeviceCallback || (v5 = mMapFilenameToDeviceCallback(filename)) == 0i64 )
    v5 = UFG::qFileSystem::MapFilenameToDevicePlat(this, result.mData);
  if ( result.mData != UFG::qString::sEmptyString && result.mData )
    UFG::qMemoryPool::Free(UFG::gMainMemoryPool, result.mData);
  mPrev = result.mPrev;
  mNext = result.mNext;
  result.mPrev->mNext = result.mNext;
  mNext->mPrev = mPrev;
  return v5;
}

// File Line: 1823
// RVA: 0x179740
void __fastcall UFG::qFileSystem::QueueAsyncOp(UFG::qFileSystem *this, UFG::qFileOp *file_op, __int64 priority)
{
  UFG::qFileDevice *mDevice; // rcx
  UFG::qNode<UFG::qFileOp,UFG::qFileOp> *mPrev; // rax

  mDevice = file_op->mDevice;
  if ( mDevice )
  {
    (*(void (__fastcall **)(UFG::qFileDevice *, UFG::qFileOp *, __int64))&mDevice->vfptr->gap8[16])(
      mDevice,
      file_op,
      priority);
  }
  else
  {
    *(_DWORD *)file_op->mStatus = 5;
    UFG::qMutex::Lock((LPCRITICAL_SECTION)&this->mMutex);
    mPrev = this->mDoneFileOps.mNode.mPrev;
    mPrev->mNext = file_op;
    file_op->mPrev = mPrev;
    file_op->mNext = &this->mDoneFileOps.mNode;
    this->mDoneFileOps.mNode.mPrev = file_op;
    UFG::qMutex::Unlock((LPCRITICAL_SECTION)&this->mMutex);
  }
}

// File Line: 2020
// RVA: 0x17BF70
void __fastcall UFG::qFileSystem::Service(UFG::qFileSystem *this)
{
  UFG::qList<UFG::qFileOp,UFG::qFileOp,1,0> *p_mDoneFileOps; // rdx
  UFG::qFileSystem *mNext; // r8
  __int64 *v4; // rax
  __int64 *mPrev; // rcx
  bool *i; // rsi
  __int64 j; // rbx
  __int64 **v8; // r8
  __int64 **v9; // r9
  __int64 *v10; // rax
  __int64 *v11; // rdx
  UFG::qFileOp *k; // rbx
  UFG::qNode<UFG::qFileOp,UFG::qFileOp> *v13; // rcx
  UFG::qNode<UFG::qFileOp,UFG::qFileOp> *v14; // rax
  UFG::qFile *mFile; // rdi
  unsigned __int64 Ticks; // rax
  void (__fastcall *mCallback)(UFG::qFileOp *, void *); // rax
  UFG::qNode<UFG::qFile,UFG::qFile> *v18; // rcx
  UFG::qNode<UFG::qFile,UFG::qFile> *v19; // rax
  UFG::qFileOp *m; // rbx
  UFG::qNode<UFG::qFileOp,UFG::qFileOp> *v21; // rcx
  UFG::qNode<UFG::qFileOp,UFG::qFileOp> *v22; // rax
  __int64 *v23; // rcx
  UFG::qFileOp *v24; // rax
  __int64 *v25; // [rsp+28h] [rbp-18h] BYREF
  UFG::qFileOp *v26; // [rsp+30h] [rbp-10h]

  v25 = (__int64 *)&v25;
  v26 = (UFG::qFileOp *)&v25;
  UFG::qMutex::Lock((LPCRITICAL_SECTION)&this->mMutex);
  p_mDoneFileOps = &this->mDoneFileOps;
  mNext = (UFG::qFileSystem *)this->mDoneFileOps.mNode.mNext;
  if ( mNext != (UFG::qFileSystem *)&this->mDoneFileOps )
  {
    v4 = v25;
    mPrev = (__int64 *)p_mDoneFileOps->mNode.mPrev;
    v25[1] = (__int64)mNext;
    mNext->mStartTicks = (__int64)v4;
    mPrev[1] = (__int64)&v25;
    v25 = mPrev;
    p_mDoneFileOps->mNode.mPrev = &p_mDoneFileOps->mNode;
    this->mDoneFileOps.mNode.mNext = &this->mDoneFileOps.mNode;
  }
  for ( i = (bool *)&this->mDevices.mNode.mNext[-1].mNext;
        i != &this->mReportSyncFileOps;
        i = (bool *)(*((_QWORD *)i + 2) - 8i64) )
  {
    for ( j = *((_QWORD *)i + 8); (bool *)j != i + 56; j = *(_QWORD *)(j + 8) )
    {
      UFG::qMutex::Lock((LPCRITICAL_SECTION)(j + 48));
      v8 = (__int64 **)(j + 160);
      v9 = *(__int64 ***)(j + 168);
      if ( v9 != (__int64 **)(j + 160) )
      {
        v10 = v25;
        v11 = *v8;
        v25[1] = (__int64)v9;
        *v9 = v10;
        v11[1] = (__int64)&v25;
        v25 = v11;
        *v8 = (__int64 *)v8;
        *(_QWORD *)(j + 168) = j + 160;
      }
      UFG::qMutex::Unlock((LPCRITICAL_SECTION)(j + 48));
    }
  }
  UFG::qMutex::Unlock((LPCRITICAL_SECTION)&this->mMutex);
  for ( k = v26; v26 != (UFG::qFileOp *)&v25; k = v26 )
  {
    v13 = k->mPrev;
    v14 = k->mNext;
    v13->mNext = v14;
    v14->mPrev = v13;
    k->mPrev = k;
    k->mNext = k;
    mFile = k->mFile;
    Ticks = UFG::qGetTicks();
    k->mDoneTime = (float)((float)(UFG::qGetTickTime(this->mStartTicks, Ticks) - k->mStartTime) - k->mQueuedTime)
                 - k->mExecuteTime;
    mCallback = k->mCallback;
    if ( mCallback )
      mCallback(k, k->mCallbackParam);
    if ( k->mType == OP_CLOSE && mFile )
    {
      Scaleform::Lock::~Lock((LPCRITICAL_SECTION)&mFile->mStateMutex);
      Scaleform::Lock::~Lock((LPCRITICAL_SECTION)&mFile->mFileHandleMutex);
      v18 = mFile->mPrev;
      v19 = mFile->mNext;
      v18->mNext = v19;
      v19->mPrev = v18;
      mFile->mPrev = mFile;
      mFile->mNext = mFile;
      UFG::qMemoryPool::Free(UFG::gMainMemoryPool, (char *)mFile);
    }
    UFG::qFileOp::~qFileOp(k);
    UFG::qMemoryPool::Free(UFG::gMainMemoryPool, (char *)k);
  }
  for ( m = v26; v26 != (UFG::qFileOp *)&v25; m = v26 )
  {
    v21 = m->mPrev;
    v22 = m->mNext;
    v21->mNext = v22;
    v22->mPrev = v21;
    m->mPrev = m;
    m->mNext = m;
    UFG::qFileOp::~qFileOp(m);
    UFG::qMemoryPool::Free(UFG::gMainMemoryPool, (char *)m);
  }
  v23 = v25;
  v24 = v26;
  v25[1] = (__int64)v26;
  v24->mPrev = (UFG::qNode<UFG::qFileOp,UFG::qFileOp> *)v23;
}

// File Line: 2079
// RVA: 0x175410
_BOOL8 __fastcall UFG::qFileSystem::IsBusy(UFG::qFileSystem *this)
{
  bool v1; // bl
  bool *p_mReportSyncFileOps; // rbp
  bool *p_mNext; // rdi
  __int64 v4; // rax

  v1 = 0;
  p_mReportSyncFileOps = &this->mReportSyncFileOps;
  p_mNext = (bool *)&this->mDevices.mNode.mNext[-1].mNext;
  do
  {
    if ( p_mNext == p_mReportSyncFileOps )
      break;
    UFG::qMutex::Lock((LPCRITICAL_SECTION)(p_mNext + 72));
    v4 = *((_QWORD *)p_mNext + 16);
    do
    {
      if ( (bool *)v4 == p_mNext + 120 )
        break;
      v1 = v4 && *(_DWORD *)(v4 + 144) != 0;
      v4 = *(_QWORD *)(v4 + 8);
    }
    while ( !v1 );
    UFG::qMutex::Unlock((LPCRITICAL_SECTION)(p_mNext + 72));
    p_mNext = (bool *)(*((_QWORD *)p_mNext + 2) - 8i64);
  }
  while ( !v1 );
  return v1;
}

// File Line: 2128
// RVA: 0x176020
void __fastcall UFG::qFileSystem::KillAsyncOps(
        UFG::qFileSystem *this,
        bool use_callback,
        bool use_callback_param,
        UFG::qNode<UFG::qFileOp,UFG::qFileOp> *callback,
        UFG::qNode<UFG::qFileOp,UFG::qFileOp> *callback_param,
        UFG::qFile *file)
{
  UFG::qFile *v10; // rsi
  UFG::qNode<UFG::qFileOp,UFG::qFileOp> *mNext; // rax
  UFG::qNode<UFG::qFileOp,UFG::qFileOp> *i; // rdi
  bool v13; // r8
  bool v14; // dl
  bool v15; // cl
  bool *p_mNext; // rax
  UFG::qNode<UFG::qFileOpList,UFG::qFileOpList> *v17; // rbp
  UFG::qNode<UFG::qFileOpList,UFG::qFileOpList> *k; // rax
  bool v19; // r8
  bool v20; // dl
  bool v21; // cl
  UFG::qNode<UFG::qFileOpList,UFG::qFileOpList> *m; // rax
  bool v23; // r8
  bool v24; // dl
  bool v25; // cl
  UFG::qNode<UFG::qFileOpList,UFG::qFileOpList> **v26; // rsi
  UFG::qNode<UFG::qFileOpList,UFG::qFileOpList> *v27; // rdi
  __int64 v28; // rbp
  UFG::qNode<UFG::qFileOpList,UFG::qFileOpList> *v29; // rdx
  UFG::qNode<UFG::qFileOpList,UFG::qFileOpList> *v30; // rbx
  bool v31; // r9
  bool v32; // cl
  bool v33; // al
  UFG::qNode<UFG::qFileOpList,UFG::qFileOpList> *mPrev; // rax
  UFG::qFileOp *v35; // rax
  __int64 *v36; // rcx
  UFG::qFileOp *n; // rdx
  UFG::qNode<UFG::qFileOp,UFG::qFileOp> *v38; // rcx
  UFG::qNode<UFG::qFileOp,UFG::qFileOp> *v39; // rax
  UFG::qFileOp *ii; // rbx
  UFG::qNode<UFG::qFileOp,UFG::qFileOp> *v41; // rcx
  UFG::qNode<UFG::qFileOp,UFG::qFileOp> *v42; // rax
  __int64 *v43; // rdx
  UFG::qFileOp *v44; // rax
  UFG::qNode<UFG::qFileOpList,UFG::qFileOpList> **v45; // [rsp+20h] [rbp-78h]
  __int64 v46; // [rsp+28h] [rbp-70h]
  bool *v47; // [rsp+30h] [rbp-68h]
  char *v48; // [rsp+38h] [rbp-60h]
  bool *j; // [rsp+40h] [rbp-58h]
  _RTL_CRITICAL_SECTION *lpCriticalSection; // [rsp+48h] [rbp-50h]
  __int64 *v51; // [rsp+58h] [rbp-40h] BYREF
  UFG::qFileOp *file_op; // [rsp+60h] [rbp-38h]
  UFG::qFileOpList *v53; // [rsp+A0h] [rbp+8h]

  UFG::qGetCurrentThreadID();
  lpCriticalSection = (_RTL_CRITICAL_SECTION *)&this->mMutex;
  UFG::qMutex::Lock((LPCRITICAL_SECTION)&this->mMutex);
  v10 = file;
  mNext = this->mDoneFileOps.mNode.mNext;
  for ( i = callback_param; mNext != (UFG::qNode<UFG::qFileOp,UFG::qFileOp> *)&this->mDoneFileOps; mNext = mNext->mNext )
  {
    v13 = !use_callback || mNext[5].mPrev == callback;
    v14 = !use_callback_param || mNext[5].mNext == callback_param;
    if ( file )
      v15 = mNext[4].mNext == (UFG::qNode<UFG::qFileOp,UFG::qFileOp> *)file;
    else
      v15 = 1;
    if ( v13 && v14 && v15 )
      HIDWORD(mNext[1].mNext) = 4;
  }
  p_mNext = (bool *)&this->mDevices.mNode.mNext[-1].mNext;
  v47 = p_mNext;
  for ( j = &this->mReportSyncFileOps; p_mNext != j; v47 = p_mNext )
  {
    v17 = (UFG::qNode<UFG::qFileOpList,UFG::qFileOpList> *)*((_QWORD *)p_mNext + 8);
    v53 = (UFG::qFileOpList *)v17;
    v48 = (char *)(p_mNext + 56);
    if ( v17 != (UFG::qNode<UFG::qFileOpList,UFG::qFileOpList> *)(p_mNext + 56) )
    {
      do
      {
        UFG::qMutex::Lock((LPCRITICAL_SECTION)&v17[3]);
        v51 = (__int64 *)&v51;
        file_op = (UFG::qFileOp *)&v51;
        for ( k = v17[9].mNext; k != &v17[9]; k = k->mNext )
        {
          v19 = !use_callback || k[5].mPrev == (UFG::qNode<UFG::qFileOpList,UFG::qFileOpList> *)callback;
          v20 = !use_callback_param || k[5].mNext == (UFG::qNode<UFG::qFileOpList,UFG::qFileOpList> *)i;
          if ( file )
            v21 = k[4].mNext == (UFG::qNode<UFG::qFileOpList,UFG::qFileOpList> *)v10;
          else
            v21 = 1;
          if ( v19 && v20 && v21 && LODWORD(k[1].mNext) != 1 )
            HIDWORD(k[1].mNext) = 4;
        }
        for ( m = v17[10].mNext; m != &v17[10]; m = m->mNext )
        {
          v23 = !use_callback || m[5].mPrev == (UFG::qNode<UFG::qFileOpList,UFG::qFileOpList> *)callback;
          v24 = !use_callback_param || m[5].mNext == (UFG::qNode<UFG::qFileOpList,UFG::qFileOpList> *)i;
          if ( file )
            v25 = m[4].mNext == (UFG::qNode<UFG::qFileOpList,UFG::qFileOpList> *)v10;
          else
            v25 = 1;
          if ( v23 && v24 && v25 && LODWORD(m[1].mNext) != 1 )
            HIDWORD(m[1].mNext) = 4;
        }
        v26 = &v17[6].mNext;
        v45 = &v17[6].mNext;
        v27 = v17 + 6;
        v28 = 3i64;
        v46 = 3i64;
        do
        {
          v29 = *v26;
          if ( *v26 != v27 )
          {
            do
            {
              v30 = v29->mNext;
              v31 = !use_callback || v29[5].mPrev == (UFG::qNode<UFG::qFileOpList,UFG::qFileOpList> *)callback;
              v32 = !use_callback_param
                 || v29[5].mNext == (UFG::qNode<UFG::qFileOpList,UFG::qFileOpList> *)callback_param;
              if ( file )
                v33 = v29[4].mNext == (UFG::qNode<UFG::qFileOpList,UFG::qFileOpList> *)file;
              else
                v33 = 1;
              if ( v31 && v32 && v33 && LODWORD(v29[1].mNext) != 1 )
              {
                HIDWORD(v29[1].mNext) = 4;
                mPrev = v29->mPrev;
                mPrev->mNext = v30;
                v30->mPrev = mPrev;
                v29->mPrev = v29;
                v29->mNext = v29;
                v35 = UFG::qFileOpList::Completed(v53, (UFG::qFileOp *)v29);
                if ( v35 )
                {
                  v36 = v51;
                  v51[1] = (__int64)v35;
                  v35->mPrev = (UFG::qNode<UFG::qFileOp,UFG::qFileOp> *)v36;
                  v35->mNext = (UFG::qNode<UFG::qFileOp,UFG::qFileOp> *)&v51;
                  v51 = (__int64 *)v35;
                }
              }
              v29 = v30;
            }
            while ( v30 != v27 );
            v26 = v45;
            v28 = v46;
          }
          ++v27;
          v26 += 2;
          v45 = v26;
          v46 = --v28;
        }
        while ( v28 );
        for ( n = file_op; file_op != (UFG::qFileOp *)&v51; n = file_op )
        {
          v38 = n->mPrev;
          v39 = n->mNext;
          v38->mNext = v39;
          v39->mPrev = v38;
          n->mPrev = n;
          n->mNext = n;
          UFG::qFileOpList::Queue(v53, n, 0);
        }
        for ( ii = file_op; file_op != (UFG::qFileOp *)&v51; ii = file_op )
        {
          v41 = ii->mPrev;
          v42 = ii->mNext;
          v41->mNext = v42;
          v42->mPrev = v41;
          ii->mPrev = ii;
          ii->mNext = ii;
          UFG::qFileOp::~qFileOp(ii);
          UFG::qMemoryPool::Free(UFG::gMainMemoryPool, (char *)ii);
        }
        v43 = v51;
        v44 = file_op;
        v51[1] = (__int64)file_op;
        v44->mPrev = (UFG::qNode<UFG::qFileOp,UFG::qFileOp> *)v43;
        v51 = (__int64 *)&v51;
        file_op = (UFG::qFileOp *)&v51;
        UFG::qMutex::Unlock((LPCRITICAL_SECTION)&v53->mMutex);
        v17 = v53->mNext;
        v53 = (UFG::qFileOpList *)v17;
        i = callback_param;
        v10 = file;
      }
      while ( v17 != (UFG::qNode<UFG::qFileOpList,UFG::qFileOpList> *)v48 );
      p_mNext = v47;
    }
    p_mNext = (bool *)(*((_QWORD *)p_mNext + 2) - 8i64);
  }
  UFG::qMutex::Unlock(lpCriticalSection);
}

// File Line: 2317
// RVA: 0x183740
void __fastcall UFG::qFileService(UFG *this)
{
  UFG::qChunkFileSystem *v1; // rcx
  bool v2; // al
  bool v3; // al
  AMD_HD3D *v4; // rax

  UFG::qFileSystem::Service(&UFG::gQuarkFileSystem);
  UFG::qChunkFileSystem::ResourceSystem_ServiceDelayedBundleTables(v1);
  v2 = UFG::qChunkFileSystem::ResourceSystem_CheckForUnusedFileHandles(0);
  v3 = UFG::qChunkFileSystem::ResourceSystem_CheckForFinishedLoadTables(v2);
  UFG::qChunkFileSystem::ResourceSystem_MakeLoadTableCallbacks(v3);
  ++UFG::qChunkFileSystem::mServiceCounter;
  v4 = (AMD_HD3D *)UFG::qSpuManager::Instance();
  _(v4);
}

// File Line: 2334
// RVA: 0x18CA00
bool __fastcall UFG::qWaitForOpenFileHandle(UFG::qFile *file)
{
  if ( byte_14235ACD8 || !file || !file->mDevice )
    return 0;
  if ( file->mOpenState == STATE_NONE || file->mOpenState == STATE_WAITING )
    return 1;
  if ( file->mCloseState )
    return 0;
  while ( file->mOpenState == STATE_QUEUED )
    UFG::qSleep(0);
  return file->mOpenState == STATE_WAITING;
}

// File Line: 2382
// RVA: 0x183790
void __fastcall UFG::qFileWaitForCompletion(UFG *this)
{
  bool v1; // bl
  __int64 v2; // rdi
  __int64 v3; // rax

LABEL_1:
  UFG::qFileSystem::Service(&UFG::gQuarkFileSystem);
  UFG::qSleep(1u);
  v1 = 0;
  v2 = unk_14235ABE8 - 8i64;
  while ( (_UNKNOWN *)v2 != &unk_14235ABD8 )
  {
    UFG::qMutex::Lock((LPCRITICAL_SECTION)(v2 + 72));
    v3 = *(_QWORD *)(v2 + 128);
    do
    {
      if ( v3 == v2 + 120 )
        break;
      v1 = v3 && *(_DWORD *)(v3 + 144) != 0;
      v3 = *(_QWORD *)(v3 + 8);
    }
    while ( !v1 );
    UFG::qMutex::Unlock((LPCRITICAL_SECTION)(v2 + 72));
    v2 = *(_QWORD *)(v2 + 16) - 8i64;
    if ( v1 )
      goto LABEL_1;
  }
}

// File Line: 2397
// RVA: 0x184500
char *__fastcall UFG::qGetFileName(UFG::qFile *file)
{
  if ( file )
    return file->mFilename;
  else
    return 0i64;
}

// File Line: 2447
// RVA: 0x1836F0
UFG::qString *__fastcall UFG::qFileMapFilename(UFG::qString *result, unsigned int file_map_type, const char *filename)
{
  UFG::qFileSystem::MapFilename(&UFG::gQuarkFileSystem, result, file_map_type, filename);
  return result;
}

// File Line: 2463
// RVA: 0x183A10
UFG::qString *__fastcall UFG::qFixUpDirectoryPath(UFG::qString *result, const char *directory)
{
  const char *v4; // rax
  int v6; // eax
  __int64 v7; // rcx
  char v8; // dl
  char v9; // dl
  UFG::qNode<UFG::qString,UFG::qString> *mPrev; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *mNext; // rax
  UFG::qString v13; // [rsp+40h] [rbp-30h] BYREF

  if ( directory && *directory )
  {
    v13.mPrev = &v13;
    v13.mNext = &v13;
    *(_QWORD *)&v13.mMagic = 16909060i64;
    v13.mData = (char *)UFG::qString::sEmptyString;
    *(_QWORD *)&v13.mStringHash32 = -1i64;
    v4 = directory;
    while ( *v4++ )
      ;
    v6 = (_DWORD)v4 - (_DWORD)directory - 1;
    v7 = v6;
    v8 = directory[v6 - 1];
    if ( v8 == 92 || v8 == 47 )
    {
      do
      {
        --v6;
        if ( --v7 <= 0 )
          break;
        v9 = directory[v7 - 1];
      }
      while ( v9 == 92 || v9 == 47 );
    }
    UFG::qString::Set(&v13, directory, v6, 0i64, 0);
    result->mPrev = result;
    result->mNext = result;
    result->mMagic = 16909060;
    result->mData = (char *)UFG::qString::sEmptyString;
    result->mLength = 0;
    UFG::qString::Set(result, v13.mData, v13.mLength, 0i64, 0);
    result->mStringHash32 = v13.mStringHash32;
    result->mStringHashUpper32 = v13.mStringHashUpper32;
    if ( v13.mData != UFG::qString::sEmptyString )
    {
      if ( v13.mData )
        UFG::qMemoryPool::Free(UFG::gMainMemoryPool, v13.mData);
    }
    v13.mMagic = 0;
    mPrev = v13.mPrev;
    mNext = v13.mNext;
    v13.mPrev->mNext = v13.mNext;
    mNext->mPrev = mPrev;
    v13.mPrev = &v13;
    v13.mNext = &v13;
    return result;
  }
  else
  {
    result->mPrev = result;
    result->mNext = result;
    result->mMagic = 16909060;
    result->mData = (char *)UFG::qString::sEmptyString;
    result->mLength = 0;
    *(_QWORD *)&result->mStringHash32 = -1i64;
    return result;
  }
}

// File Line: 2530
// RVA: 0x1887E0
// bad sp value at call has been detected, the output may be wrong!
bool __fastcall UFG::qOpenInternal(UFG::qFile *file, bool warn_if_fail)
{
  UFG::qFileDevice *mDevice; // r12
  char *mFilename; // rbx
  bool v6; // r15
  char v7; // r14
  UFG::qString *Directory; // rax
  UFG::qNode<UFG::qString,UFG::qString> *mPrev; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *mNext; // rax
  UFG::qNode<UFG::qString,UFG::qString> *v11; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *v12; // rax
  UFG::qNode<UFG::qString,UFG::qString> *v13; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *v14; // rax
  bool v15; // r13
  UFG::qNode<UFG::qFile,UFG::qFile> *v16; // rax
  UFG::qString result; // [rsp+0h] [rbp-49h] BYREF
  UFG::qString v18; // [rsp+28h] [rbp-21h] BYREF
  UFG::qString v19; // [rsp+50h] [rbp+7h] BYREF
  __int64 v20; // [rsp+78h] [rbp+2Fh]
  unsigned __int8 v21; // [rsp+B8h] [rbp+6Fh]

  v20 = -2i64;
  if ( !file )
    return 0;
  mDevice = file->mDevice;
  mFilename = file->mFilename;
  v6 = file->mFilename[0] != 0 && mDevice != 0i64 && byte_14235ACD8 == 0 && file->mFilename != 0i64;
  v7 = 1;
  if ( ((file->mAccessType & 0x12) != 0) | ((file->mAccessType | ((unsigned int)file->mAccessType >> 1)) >> 1) & 1 )
  {
    UFG::qString::qString(&v18, mFilename);
    UFG::qString::GetFilePath(&v18, &result);
    if ( !v6 || !mDevice->vfptr->CreateDirectoryA(mDevice, result.mData) )
    {
      Directory = UFG::qGetDirectory(&v19);
      UFG::qPrintf(
        "WARNING:  Could not create directory %s when opening %s.  Current Dir = %s\n",
        result.mData,
        mFilename,
        Directory->mData);
      if ( v19.mData != UFG::qString::sEmptyString && v19.mData )
        UFG::qMemoryPool::Free(UFG::gMainMemoryPool, v19.mData);
      v19.mMagic = 0;
      mPrev = v19.mPrev;
      mNext = v19.mNext;
      v19.mPrev->mNext = v19.mNext;
      mNext->mPrev = mPrev;
      v19.mPrev = &v19;
      v19.mNext = &v19;
      v7 = 0;
    }
    if ( result.mData != UFG::qString::sEmptyString && result.mData )
      UFG::qMemoryPool::Free(UFG::gMainMemoryPool, result.mData);
    result.mMagic = 0;
    v11 = result.mPrev;
    v12 = result.mNext;
    result.mPrev->mNext = result.mNext;
    v12->mPrev = v11;
    result.mPrev = &result;
    result.mNext = &result;
    if ( v18.mData != UFG::qString::sEmptyString && v18.mData )
      UFG::qMemoryPool::Free(UFG::gMainMemoryPool, v18.mData);
    v18.mMagic = 0;
    v13 = v18.mPrev;
    v14 = v18.mNext;
    v18.mPrev->mNext = v18.mNext;
    v14->mPrev = v13;
    v18.mPrev = &v18;
    v18.mNext = &v18;
  }
  v15 = 0;
  if ( v6 && v7 == 1 )
  {
    UFG::qMutex::Lock((LPCRITICAL_SECTION)&file->mFileHandleMutex);
    v15 = mDevice->vfptr->FileOpen(mDevice, file, v21);
    UFG::qMutex::Unlock((LPCRITICAL_SECTION)&file->mFileHandleMutex);
  }
  UFG::qMutex::Lock((LPCRITICAL_SECTION)&file->mStateMutex);
  if ( v6 && v7 == 1 && v15 )
  {
    file->mOpenState = STATE_WAITING;
  }
  else
  {
    file->mOpenState = STATE_NONE;
    file->mCloseState = STATE_DONE;
  }
  UFG::qMutex::Unlock((LPCRITICAL_SECTION)&file->mStateMutex);
  if ( file->mOpenState == STATE_WAITING )
  {
    UFG::qMutex::Lock((LPCRITICAL_SECTION)&mDevice->mMutex);
    v16 = mDevice->mOpenFiles.mNode.mPrev;
    v16->mNext = file;
    file->mPrev = v16;
    file->mNext = &mDevice->mOpenFiles.mNode;
    mDevice->mOpenFiles.mNode.mPrev = file;
    UFG::qMutex::Unlock((LPCRITICAL_SECTION)&mDevice->mMutex);
  }
  else if ( v21 == 1 )
  {
    UFG::qPrintf("ERROR: Unable to open file = %s\n", file->mFilename);
  }
  return file->mOpenState == STATE_WAITING;
}

// File Line: 2627
// RVA: 0x1823D0
char __fastcall UFG::qCloseInternal(UFG::qFile *file)
{
  bool v3; // bl
  UFG::qFileDevice *mDevice; // rsi
  UFG::qNode<UFG::qFile,UFG::qFile> *mPrev; // rdx
  UFG::qNode<UFG::qFile,UFG::qFile> *mNext; // rax

  if ( !file )
    return 0;
  UFG::qMutex::Lock((LPCRITICAL_SECTION)&file->mStateMutex);
  v3 = file->mCloseState == STATE_EXECUTING;
  UFG::qMutex::Unlock((LPCRITICAL_SECTION)&file->mStateMutex);
  mDevice = file->mDevice;
  if ( v3 && mDevice )
  {
    UFG::qMutex::Lock((LPCRITICAL_SECTION)&file->mFileHandleMutex);
    mDevice->vfptr->FileClose(mDevice, file);
    UFG::qMutex::Unlock((LPCRITICAL_SECTION)&file->mFileHandleMutex);
  }
  UFG::qMutex::Lock((LPCRITICAL_SECTION)&file->mStateMutex);
  file->mOpenState = STATE_NONE;
  file->mCloseState = STATE_DONE;
  file->mAsyncCloseOp = 0i64;
  UFG::qMutex::Unlock((LPCRITICAL_SECTION)&file->mStateMutex);
  if ( mDevice )
  {
    UFG::qMutex::Lock((LPCRITICAL_SECTION)&mDevice->mMutex);
    mPrev = file->mPrev;
    mNext = file->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    file->mPrev = file;
    file->mNext = file;
    UFG::qMutex::Unlock((LPCRITICAL_SECTION)&mDevice->mMutex);
  }
  return 1;
}

// File Line: 2715
// RVA: 0x188440
UFG::qFile *__fastcall UFG::qOpen(const char *filename, UFG::qFileAccessType access_type, bool warn_if_fail)
{
  UFG::qFileDevice *v6; // rbx
  UFG::qMemoryPool *v7; // rcx
  UFG::allocator::free_link *v8; // rax
  __int64 *v9; // rax
  __int64 *v10; // rbx
  __int64 v11; // rcx
  _QWORD *v12; // rax
  UFG::qNode<UFG::qString,UFG::qString> *mPrev; // rdx
  UFG::qNode<UFG::qString,UFG::qString> *mNext; // rcx
  UFG::qString result; // [rsp+38h] [rbp-30h] BYREF

  UFG::qFileSystem::MapFilename(&UFG::gQuarkFileSystem, &result, 0, filename);
  v6 = UFG::qFileSystem::MapFilenameToDevice(&UFG::gQuarkFileSystem, filename);
  v7 = UFG::gMainMemoryPool;
  if ( !UFG::gMainMemoryPool )
  {
    UFG::InternalSetupMainMemoryPool((UFG *)UFG::gMainMemoryPool);
    v7 = UFG::gMainMemoryPool;
  }
  v8 = UFG::qMemoryPool::Allocate(v7, 0x1A8ui64, "qFile", 0i64, 1u);
  if ( v8 )
  {
    UFG::qFile::qFile((UFG::qFile *)v8, v6, result.mData, access_type);
    v10 = v9;
  }
  else
  {
    v10 = 0i64;
  }
  *((_DWORD *)v10 + 34) = 1;
  if ( !UFG::qOpenInternal((UFG::qFile *)v10, warn_if_fail) )
  {
    Scaleform::Lock::~Lock((LPCRITICAL_SECTION)(v10 + 11));
    Scaleform::Lock::~Lock((LPCRITICAL_SECTION)((char *)v10 + 28));
    v11 = *v10;
    v12 = (_QWORD *)v10[1];
    *(_QWORD *)(v11 + 8) = v12;
    *v12 = v11;
    *v10 = (__int64)v10;
    v10[1] = (__int64)v10;
    UFG::qMemoryPool::Free(UFG::gMainMemoryPool, (char *)v10);
    v10 = 0i64;
  }
  if ( result.mData != UFG::qString::sEmptyString && result.mData )
    UFG::qMemoryPool::Free(UFG::gMainMemoryPool, result.mData);
  mPrev = result.mPrev;
  mNext = result.mNext;
  result.mPrev->mNext = result.mNext;
  mNext->mPrev = mPrev;
  return (UFG::qFile *)v10;
}

// File Line: 2738
// RVA: 0x1885B0
UFG::qFile *__fastcall UFG::qOpenAsync(
        const char *filename,
        UFG::qFileAccessType access_type,
        bool warn_if_fail,
        void (__fastcall *callback)(UFG::qFileOp *, void *),
        void *callback_param,
        UFG::qFilePriorityLevel priority)
{
  UFG::qFileDevice *v10; // rsi
  UFG::qMemoryPool *v11; // rcx
  UFG::allocator::free_link *v12; // rax
  __int64 v13; // rax
  __int64 v14; // rsi
  UFG::qMemoryPool *v15; // rcx
  UFG::allocator::free_link *v16; // rax
  __int64 v17; // rax
  __int64 v18; // rbx
  const char *v19; // rcx
  int v21; // ecx
  __int64 v22; // rcx
  __int64 v23; // rax
  UFG::qNode<UFG::qString,UFG::qString> *mPrev; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *mNext; // rax
  UFG::qString v27; // [rsp+38h] [rbp-40h] BYREF

  UFG::qFileSystem::MapFilename(&UFG::gQuarkFileSystem, &v27, 0, filename);
  v10 = UFG::qFileSystem::MapFilenameToDevice(&UFG::gQuarkFileSystem, filename);
  v11 = UFG::gMainMemoryPool;
  if ( !UFG::gMainMemoryPool )
  {
    UFG::InternalSetupMainMemoryPool((UFG *)UFG::gMainMemoryPool);
    v11 = UFG::gMainMemoryPool;
  }
  v12 = UFG::qMemoryPool::Allocate(v11, 0x1A8ui64, "qFile", 0i64, 1u);
  if ( v12 )
  {
    UFG::qFile::qFile((UFG::qFile *)v12, v10, v27.mData, access_type);
    v14 = v13;
  }
  else
  {
    v14 = 0i64;
  }
  v15 = UFG::gMainMemoryPool;
  if ( !UFG::gMainMemoryPool )
  {
    UFG::InternalSetupMainMemoryPool((UFG *)UFG::gMainMemoryPool);
    v15 = UFG::gMainMemoryPool;
  }
  v16 = UFG::qMemoryPool::Allocate(v15, 0x170ui64, "qFileOp.OP_OPEN", 0i64, 1u);
  if ( v16 )
  {
    UFG::qFileOp::qFileOp((UFG::qFileOp *)v16, (UFG::qFile *)v14, OP_OPEN, callback, callback_param);
    v18 = v17;
  }
  else
  {
    v18 = 0i64;
  }
  *(_BYTE *)(v18 + 112) = warn_if_fail;
  if ( !filename || filename == UFG::qString::sEmptyString )
  {
    v21 = 0;
  }
  else
  {
    v19 = filename;
    while ( *v19++ )
      ;
    v21 = (_DWORD)v19 - (_DWORD)filename - 1;
  }
  UFG::qString::Set((UFG::qString *)(v18 + 32), filename, v21, 0i64, 0);
  *(_DWORD *)(v14 + 136) = 1;
  v22 = *(_QWORD *)(v18 + 16);
  if ( v22 )
  {
    (*(void (__fastcall **)(__int64, __int64, _QWORD))(*(_QWORD *)v22 + 24i64))(v22, v18, (unsigned int)priority);
  }
  else
  {
    *(_DWORD *)(v18 + 28) = 5;
    UFG::qMutex::Lock(&CriticalSection);
    v23 = qword_14235ACC8;
    *(_QWORD *)(qword_14235ACC8 + 8) = v18;
    *(_QWORD *)v18 = v23;
    *(_QWORD *)(v18 + 8) = &qword_14235ACC8;
    qword_14235ACC8 = v18;
    UFG::qMutex::Unlock(&CriticalSection);
  }
  if ( v27.mData != UFG::qString::sEmptyString && v27.mData )
    UFG::qMemoryPool::Free(UFG::gMainMemoryPool, v27.mData);
  mPrev = v27.mPrev;
  mNext = v27.mNext;
  v27.mPrev->mNext = v27.mNext;
  mNext->mPrev = mPrev;
  return (UFG::qFile *)v14;
}

// File Line: 2760
// RVA: 0x182160
void __fastcall UFG::qClose(UFG::qFile *file)
{
  UFG::qNode<UFG::qFile,UFG::qFile> *mPrev; // rcx
  UFG::qNode<UFG::qFile,UFG::qFile> *mNext; // rax

  if ( file )
  {
    UFG::qMutex::Lock((LPCRITICAL_SECTION)&file->mStateMutex);
    file->mCloseState = STATE_EXECUTING;
    UFG::qMutex::Unlock((LPCRITICAL_SECTION)&file->mStateMutex);
    UFG::qWaitForOpenFileHandle(file);
    UFG::qCloseInternal(file);
    Scaleform::Lock::~Lock((LPCRITICAL_SECTION)&file->mStateMutex);
    Scaleform::Lock::~Lock((LPCRITICAL_SECTION)&file->mFileHandleMutex);
    mPrev = file->mPrev;
    mNext = file->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    file->mPrev = file;
    file->mNext = file;
    UFG::qMemoryPool::Free(UFG::gMainMemoryPool, (char *)file);
  }
}

// File Line: 2789
// RVA: 0x1822E0
void __fastcall UFG::qCloseAsync(
        UFG::qFile *file,
        void (__fastcall *callback)(UFG::qFileOp *, void *),
        void *callback_param,
        UFG::qFilePriorityLevel priority)
{
  UFG::qMemoryPool *v7; // rcx
  UFG::allocator::free_link *v8; // rax
  UFG::qFileOp *v9; // rax
  UFG::qFileOp *v10; // rdi

  if ( file )
  {
    v7 = UFG::gMainMemoryPool;
    if ( !UFG::gMainMemoryPool )
    {
      UFG::InternalSetupMainMemoryPool((UFG *)UFG::gMainMemoryPool);
      v7 = UFG::gMainMemoryPool;
    }
    v8 = UFG::qMemoryPool::Allocate(v7, 0x170ui64, "qFileOp.OP_CLOSE", 0i64, 1u);
    if ( v8 )
    {
      UFG::qFileOp::qFileOp((UFG::qFileOp *)v8, file, OP_CLOSE, callback, callback_param);
      v10 = v9;
    }
    else
    {
      v10 = 0i64;
    }
    UFG::qMutex::Lock((LPCRITICAL_SECTION)&file->mStateMutex);
    file->mCloseState = STATE_EXECUTING;
    file->mAsyncCloseOp = v10;
    if ( !file->mNumAsyncOps )
      UFG::qFileSystem::QueueAsyncOp(&UFG::gQuarkFileSystem, v10, 0i64);
    UFG::qMutex::Unlock((LPCRITICAL_SECTION)&file->mStateMutex);
  }
}

// File Line: 2845
// RVA: 0x184510
__int64 __fastcall UFG::qGetFileSize(UFG::qFile *file)
{
  __int64 v3; // rax
  _RTL_CRITICAL_SECTION *p_mFileHandleMutex; // rcx
  __int64 v5; // rbx

  if ( !UFG::qWaitForOpenFileHandle(file) )
    return -1i64;
  UFG::qMutex::Lock((LPCRITICAL_SECTION)&file->mFileHandleMutex);
  v3 = file->mDevice->vfptr->GetFileSize(file->mDevice, file);
  p_mFileHandleMutex = (_RTL_CRITICAL_SECTION *)&file->mFileHandleMutex;
  v5 = v3;
  UFG::qMutex::Unlock(p_mFileHandleMutex);
  return v5;
}

// File Line: 2917
// RVA: 0x184190
__int64 __fastcall UFG::qGetDiskPosSortKey(UFG::qFile *file)
{
  UFG::qFileDevice *mDevice; // rbx
  __int64 v4; // rbx

  if ( !UFG::qWaitForOpenFileHandle(file) )
    return -1i64;
  mDevice = file->mDevice;
  UFG::qMutex::Lock((LPCRITICAL_SECTION)&file->mFileHandleMutex);
  v4 = mDevice->vfptr->FileGetDiskPosSortKey(mDevice, file);
  UFG::qMutex::Unlock((LPCRITICAL_SECTION)&file->mFileHandleMutex);
  return v4;
}

// File Line: 2939
// RVA: 0x1896B0
__int64 __fastcall UFG::qRead(
        UFG::qFile *file,
        void *buffer,
        __int64 num_bytes,
        __int64 seek_offset,
        UFG::qFileSeekType seek_type)
{
  UFG::qFileDevice *mDevice; // rbx
  __int64 v11; // rbx

  if ( !UFG::qWaitForOpenFileHandle(file) || !buffer )
    return -1i64;
  if ( !num_bytes )
    return 0i64;
  mDevice = file->mDevice;
  UFG::qMutex::Lock((LPCRITICAL_SECTION)&file->mFileHandleMutex);
  mDevice->vfptr->FileSeek(mDevice, file, seek_type, seek_offset);
  v11 = mDevice->vfptr->FileRead(mDevice, file, buffer, num_bytes);
  UFG::qMutex::Unlock((LPCRITICAL_SECTION)&file->mFileHandleMutex);
  return v11;
}

// File Line: 2967
// RVA: 0x189AF0
void __fastcall UFG::qReadAsync(
        UFG::qFile *file,
        void *buffer,
        __int64 size,
        __int64 seek_offset,
        UFG::qFileSeekType seek_type,
        void (__fastcall *callback)(UFG::qFileOp *, void *),
        void *callback_param,
        UFG::qFilePriorityLevel priority)
{
  UFG::qMemoryPool *v12; // rcx
  UFG::allocator::free_link *v13; // rax
  UFG::qFileOp *v14; // rax
  UFG::qFileOp *v15; // rbx
  UFG::qFileDevice *mDevice; // rcx
  UFG::qNode<UFG::qFileOp,UFG::qFileOp> *v17; // rax

  v12 = UFG::gMainMemoryPool;
  if ( !UFG::gMainMemoryPool )
  {
    UFG::InternalSetupMainMemoryPool((UFG *)UFG::gMainMemoryPool);
    v12 = UFG::gMainMemoryPool;
  }
  v13 = UFG::qMemoryPool::Allocate(v12, 0x170ui64, "qFileOp.OP_READ", 0i64, 1u);
  if ( v13 )
  {
    UFG::qFileOp::qFileOp((UFG::qFileOp *)v13, file, OP_READ, callback, callback_param);
    v15 = v14;
  }
  else
  {
    v15 = 0i64;
  }
  v15->mSeekType = seek_type;
  v15->mSeekOffset = seek_offset;
  v15->mBuffer = buffer;
  v15->mNumBytes = size;
  mDevice = v15->mDevice;
  if ( mDevice )
  {
    (*(void (__fastcall **)(UFG::qFileDevice *, UFG::qFileOp *, _QWORD))&mDevice->vfptr->gap8[16])(
      mDevice,
      v15,
      (unsigned int)priority);
  }
  else
  {
    *(_DWORD *)v15->mStatus = 5;
    UFG::qMutex::Lock(&CriticalSection);
    v17 = (UFG::qNode<UFG::qFileOp,UFG::qFileOp> *)qword_14235ACC8;
    *(_QWORD *)(qword_14235ACC8 + 8) = v15;
    v15->mPrev = v17;
    v15->mNext = (UFG::qNode<UFG::qFileOp,UFG::qFileOp> *)&qword_14235ACC8;
    qword_14235ACC8 = (__int64)v15;
    UFG::qMutex::Unlock(&CriticalSection);
  }
}

// File Line: 2985
// RVA: 0x18CE50
__int64 __fastcall UFG::qWrite(
        UFG::qFile *file,
        const void *buffer,
        __int64 num_bytes,
        __int64 seek_offset,
        UFG::qFileSeekType seek_type,
        bool *not_enough_space)
{
  UFG::qFileDevice *mDevice; // rbx
  __int64 v12; // rbx
  char v13[40]; // [rsp+30h] [rbp-28h] BYREF

  if ( !UFG::qWaitForOpenFileHandle(file) || !buffer )
    return -1i64;
  if ( !num_bytes )
    return 0i64;
  mDevice = file->mDevice;
  v13[0] = 0;
  UFG::qMutex::Lock((LPCRITICAL_SECTION)&file->mFileHandleMutex);
  mDevice->vfptr->FileSeek(mDevice, file, seek_type, seek_offset);
  v12 = mDevice->vfptr->FileWrite(mDevice, file, buffer, num_bytes, (bool *)v13);
  UFG::qMutex::Unlock((LPCRITICAL_SECTION)&file->mFileHandleMutex);
  if ( not_enough_space )
    *not_enough_space = v13[0];
  return v12;
}

// File Line: 3066
// RVA: 0x1829E0
__int64 __fastcall UFG::qCreateDirectory(char *a1)
{
  char *mData; // rbx
  UFG::qFileDevice *v2; // rbx
  UFG::qNode<UFG::qString,UFG::qString> *mPrev; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *mNext; // rax
  bool v5; // bl
  UFG::qNode<UFG::qString,UFG::qString> *v6; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *v7; // rax
  UFG::qNode<UFG::qString,UFG::qString> *v8; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *v9; // rax
  UFG::qString v11; // [rsp+20h] [rbp-29h] BYREF
  UFG::qString v12; // [rsp+48h] [rbp-1h] BYREF
  UFG::qString v13; // [rsp+70h] [rbp+27h] BYREF
  __int64 v14; // [rsp+98h] [rbp+4Fh]

  v14 = -2i64;
  UFG::qFixUpDirectoryPath(&v13, a1);
  UFG::qFileSystem::MapFilename(&UFG::gQuarkFileSystem, &v11, 0, v13.mData);
  mData = v11.mData;
  UFG::qFileSystem::MapFilename(&UFG::gQuarkFileSystem, &v12, 0, v11.mData);
  if ( !qword_14235AC78 || (v2 = (UFG::qFileDevice *)qword_14235AC78(mData)) == 0i64 )
    v2 = UFG::qFileSystem::MapFilenameToDevicePlat(&UFG::gQuarkFileSystem, v12.mData);
  if ( v12.mData != UFG::qString::sEmptyString && v12.mData )
    UFG::qMemoryPool::Free(UFG::gMainMemoryPool, v12.mData);
  v12.mMagic = 0;
  mPrev = v12.mPrev;
  mNext = v12.mNext;
  v12.mPrev->mNext = v12.mNext;
  mNext->mPrev = mPrev;
  v12.mPrev = &v12;
  v12.mNext = &v12;
  v5 = !byte_14235ACD8 && v2 && v2->vfptr->CreateDirectoryA(v2, v11.mData);
  if ( v11.mData != UFG::qString::sEmptyString && v11.mData )
    UFG::qMemoryPool::Free(UFG::gMainMemoryPool, v11.mData);
  v11.mMagic = 0;
  v6 = v11.mPrev;
  v7 = v11.mNext;
  v11.mPrev->mNext = v11.mNext;
  v7->mPrev = v6;
  v11.mPrev = &v11;
  v11.mNext = &v11;
  if ( v13.mData != UFG::qString::sEmptyString && v13.mData )
    UFG::qMemoryPool::Free(UFG::gMainMemoryPool, v13.mData);
  v8 = v13.mPrev;
  v9 = v13.mNext;
  v13.mPrev->mNext = v13.mNext;
  v9->mPrev = v8;
  return v5;
}

// File Line: 3116
// RVA: 0x1847F0
__int64 __fastcall UFG::qGetFiles(
        UFG::qList<UFG::qString,UFG::qString,1,0> *files,
        const char *initial_directory,
        int recursive,
        UFG::qList<UFG::qString,UFG::qString,1,0> *patterns)
{
  UFG::qFileDevice *v8; // rax
  __int64 v9; // r9
  unsigned int v10; // ebx
  UFG::qNode<UFG::qString,UFG::qString> *mPrev; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *mNext; // rax
  UFG::qString v14; // [rsp+38h] [rbp-30h] BYREF

  UFG::qFileSystem::MapFilename(&UFG::gQuarkFileSystem, &v14, 0, initial_directory);
  if ( !byte_14235ACD8
    && initial_directory
    && *initial_directory
    && (v8 = UFG::qFileSystem::MapFilenameToDevice(&UFG::gQuarkFileSystem, initial_directory)) != 0i64 )
  {
    LOBYTE(v9) = recursive != 0;
    v10 = ((__int64 (__fastcall *)(UFG::qFileDevice *, UFG::qList<UFG::qString,UFG::qString,1,0> *, char *, __int64, UFG::qList<UFG::qString,UFG::qString,1,0> *, _QWORD, __int64))v8->vfptr->FindFilesAndDirs)(
            v8,
            files,
            v14.mData,
            v9,
            patterns,
            0i64,
            -2i64);
  }
  else
  {
    v10 = 0;
  }
  if ( v14.mData != UFG::qString::sEmptyString && v14.mData )
    UFG::qMemoryPool::Free(UFG::gMainMemoryPool, v14.mData);
  mPrev = v14.mPrev;
  mNext = v14.mNext;
  v14.mPrev->mNext = v14.mNext;
  mNext->mPrev = mPrev;
  return v10;
}

// File Line: 3137
// RVA: 0x1848F0
__int64 __fastcall UFG::qGetFiles(
        UFG::qList<UFG::qString,UFG::qString,1,0> *files,
        const char *initial_directory,
        int recursive,
        const char *pattern)
{
  UFG::qMemoryPool *v7; // rcx
  UFG::qString *v8; // rax
  UFG::qNode<UFG::qString,UFG::qString> *v9; // rax
  UFG::qNode<UFG::qString,UFG::qString> *v10; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *mPrev; // rax
  unsigned int v12; // ebx
  UFG::qNode<UFG::qString,UFG::qString> *v13; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *mNext; // rax
  UFG::qNode<UFG::qString,UFG::qString> *v15; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *v16; // rax
  UFG::qList<UFG::qString,UFG::qString,1,0> patterns; // [rsp+40h] [rbp-40h] BYREF
  UFG::qString result; // [rsp+50h] [rbp-30h] BYREF

  patterns.mNode.mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&patterns;
  patterns.mNode.mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&patterns;
  UFG::qFileSystem::MapFilename(&UFG::gQuarkFileSystem, &result, 0, initial_directory);
  v7 = UFG::gMainMemoryPool;
  if ( !UFG::gMainMemoryPool )
  {
    UFG::InternalSetupMainMemoryPool((UFG *)UFG::gMainMemoryPool);
    v7 = UFG::gMainMemoryPool;
  }
  v8 = (UFG::qString *)UFG::qMemoryPool::Allocate(v7, 0x28ui64, "FilePlatString", 0i64, 1u);
  if ( v8 )
  {
    UFG::qString::qString(v8, pattern);
    v10 = v9;
  }
  else
  {
    v10 = 0i64;
  }
  mPrev = patterns.mNode.mPrev;
  patterns.mNode.mPrev->mNext = v10;
  v10->mPrev = mPrev;
  v10->mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&patterns;
  patterns.mNode.mPrev = v10;
  v12 = UFG::qGetFiles(files, result.mData, recursive, &patterns);
  if ( result.mData != UFG::qString::sEmptyString && result.mData )
    UFG::qMemoryPool::Free(UFG::gMainMemoryPool, result.mData);
  result.mMagic = 0;
  v13 = result.mPrev;
  mNext = result.mNext;
  result.mPrev->mNext = result.mNext;
  mNext->mPrev = v13;
  result.mPrev = &result;
  result.mNext = &result;
  UFG::qList<UFG::qString,UFG::qString,1,0>::DeleteNodes(&patterns);
  v15 = patterns.mNode.mPrev;
  v16 = patterns.mNode.mNext;
  patterns.mNode.mPrev->mNext = patterns.mNode.mNext;
  v16->mPrev = v15;
  return v12;
}

// File Line: 3199
// RVA: 0x184090
__int64 __fastcall UFG::qGetDirectories(
        UFG::qList<UFG::qString,UFG::qString,1,0> *directories,
        const char *base_directory,
        int recursive,
        UFG::qList<UFG::qString,UFG::qString,1,0> *patterns)
{
  UFG::qFileDevice *v8; // rax
  __int64 v9; // r9
  unsigned int v10; // ebx
  UFG::qNode<UFG::qString,UFG::qString> *mPrev; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *mNext; // rax
  UFG::qString v14; // [rsp+38h] [rbp-30h] BYREF

  UFG::qFileSystem::MapFilename(&UFG::gQuarkFileSystem, &v14, 0, base_directory);
  if ( !byte_14235ACD8
    && base_directory
    && *base_directory
    && (v8 = UFG::qFileSystem::MapFilenameToDevice(&UFG::gQuarkFileSystem, base_directory)) != 0i64 )
  {
    LOBYTE(v9) = recursive != 0;
    v10 = ((__int64 (__fastcall *)(UFG::qFileDevice *, UFG::qList<UFG::qString,UFG::qString,1,0> *, char *, __int64, _QWORD, UFG::qList<UFG::qString,UFG::qString,1,0> *, __int64))v8->vfptr->FindFilesAndDirs)(
            v8,
            directories,
            v14.mData,
            v9,
            0i64,
            patterns,
            -2i64);
  }
  else
  {
    v10 = 0;
  }
  if ( v14.mData != UFG::qString::sEmptyString && v14.mData )
    UFG::qMemoryPool::Free(UFG::gMainMemoryPool, v14.mData);
  mPrev = v14.mPrev;
  mNext = v14.mNext;
  v14.mPrev->mNext = v14.mNext;
  mNext->mPrev = mPrev;
  return v10;
}

// File Line: 3282
// RVA: 0x18A2F0
_BOOL8 __fastcall UFG::qRenameFile(const char *src_filename, const char *dest_filename)
{
  UFG::qFileDevice *v4; // r14
  UFG::qFileDevice *v5; // rdi
  bool v6; // bl
  UFG::qNode<UFG::qString,UFG::qString> *mPrev; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *mNext; // rax
  UFG::qNode<UFG::qString,UFG::qString> *v9; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *v10; // rax
  UFG::qString v12; // [rsp+28h] [rbp-60h] BYREF
  UFG::qString result; // [rsp+50h] [rbp-38h] BYREF

  v4 = UFG::qFileSystem::MapFilenameToDevice(&UFG::gQuarkFileSystem, src_filename);
  v5 = UFG::qFileSystem::MapFilenameToDevice(&UFG::gQuarkFileSystem, dest_filename);
  UFG::qFileSystem::MapFilename(&UFG::gQuarkFileSystem, &result, 0, src_filename);
  UFG::qFileSystem::MapFilename(&UFG::gQuarkFileSystem, &v12, 0, dest_filename);
  v6 = v4 == v5 && v4->vfptr->RenameFilename(v4, result.mData, v12.mData);
  if ( v12.mData != UFG::qString::sEmptyString && v12.mData )
    UFG::qMemoryPool::Free(UFG::gMainMemoryPool, v12.mData);
  v12.mMagic = 0;
  mPrev = v12.mPrev;
  mNext = v12.mNext;
  v12.mPrev->mNext = v12.mNext;
  mNext->mPrev = mPrev;
  v12.mPrev = &v12;
  v12.mNext = &v12;
  if ( result.mData != UFG::qString::sEmptyString && result.mData )
    UFG::qMemoryPool::Free(UFG::gMainMemoryPool, result.mData);
  v9 = result.mPrev;
  v10 = result.mNext;
  result.mPrev->mNext = result.mNext;
  v10->mPrev = v9;
  return v6;
}

// File Line: 3316
// RVA: 0x183250
_BOOL8 __fastcall UFG::qDeleteFile(const char *filename)
{
  UFG::qFileDevice *v2; // rdi
  bool v3; // bl
  UFG::qNode<UFG::qString,UFG::qString> *mPrev; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *mNext; // rax
  UFG::qString result; // [rsp+28h] [rbp-30h] BYREF

  v2 = UFG::qFileSystem::MapFilenameToDevice(&UFG::gQuarkFileSystem, filename);
  UFG::qFileSystem::MapFilename(&UFG::gQuarkFileSystem, &result, 0, filename);
  v3 = !byte_14235ACD8 && v2 && v2->vfptr->DeleteFilename(v2, result.mData);
  if ( result.mData != UFG::qString::sEmptyString && result.mData )
    UFG::qMemoryPool::Free(UFG::gMainMemoryPool, result.mData);
  mPrev = result.mPrev;
  mNext = result.mNext;
  result.mPrev->mNext = result.mNext;
  mNext->mPrev = mPrev;
  return v3;
}

// File Line: 3345
// RVA: 0x183630
_BOOL8 __fastcall UFG::qFileExists(const char *filename)
{
  UFG::qFileDevice *v2; // rdi
  bool v3; // bl
  UFG::qNode<UFG::qString,UFG::qString> *mPrev; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *mNext; // rax
  UFG::qString result; // [rsp+28h] [rbp-30h] BYREF

  v2 = UFG::qFileSystem::MapFilenameToDevice(&UFG::gQuarkFileSystem, filename);
  UFG::qFileSystem::MapFilename(&UFG::gQuarkFileSystem, &result, 0, filename);
  v3 = !byte_14235ACD8 && v2 && v2->vfptr->FilenameExists(v2, result.mData);
  if ( result.mData != UFG::qString::sEmptyString && result.mData )
    UFG::qMemoryPool::Free(UFG::gMainMemoryPool, result.mData);
  mPrev = result.mPrev;
  mNext = result.mNext;
  result.mPrev->mNext = result.mNext;
  mNext->mPrev = mPrev;
  return v3;
}

// File Line: 3410
// RVA: 0x184570
__int64 __fastcall UFG::qGetFileSize(const char *filename)
{
  UFG::qFileDevice *v2; // rdi
  __int64 v3; // rbx
  UFG::qNode<UFG::qString,UFG::qString> *mPrev; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *mNext; // rax
  UFG::qString result; // [rsp+28h] [rbp-30h] BYREF

  v2 = UFG::qFileSystem::MapFilenameToDevice(&UFG::gQuarkFileSystem, filename);
  UFG::qFileSystem::MapFilename(&UFG::gQuarkFileSystem, &result, 0, filename);
  if ( byte_14235ACD8 || !v2 )
    v3 = 0i64;
  else
    v3 = v2->vfptr->GetFilenameSize(v2, result.mData);
  if ( result.mData != UFG::qString::sEmptyString && result.mData )
    UFG::qMemoryPool::Free(UFG::gMainMemoryPool, result.mData);
  mPrev = result.mPrev;
  mNext = result.mNext;
  result.mPrev->mNext = result.mNext;
  mNext->mPrev = mPrev;
  return v3;
}

// File Line: 3425
// RVA: 0x184630
void __fastcall UFG::qGetFileSizeAsync(
        const char *filename,
        void (__fastcall *callback)(UFG::qFileOp *, void *),
        void *callback_param,
        unsigned int priority)
{
  UFG::qMemoryPool *v8; // rcx
  UFG::allocator::free_link *v9; // rax
  __int64 v10; // rax
  __int64 v11; // rbx
  __int64 v12; // rcx
  __int64 v13; // rax

  v8 = UFG::gMainMemoryPool;
  if ( !UFG::gMainMemoryPool )
  {
    UFG::InternalSetupMainMemoryPool((UFG *)UFG::gMainMemoryPool);
    v8 = UFG::gMainMemoryPool;
  }
  v9 = UFG::qMemoryPool::Allocate(v8, 0x170ui64, "qFileOp.OP_GET_SIZE", 0i64, 1u);
  if ( v9 )
  {
    UFG::qFileOp::qFileOp((UFG::qFileOp *)v9, filename, OP_GET_SIZE, callback, callback_param);
    v11 = v10;
  }
  else
  {
    v11 = 0i64;
  }
  v12 = *(_QWORD *)(v11 + 16);
  if ( v12 )
  {
    (*(void (__fastcall **)(__int64, __int64, _QWORD))(*(_QWORD *)v12 + 24i64))(v12, v11, priority);
  }
  else
  {
    *(_DWORD *)(v11 + 28) = 5;
    UFG::qMutex::Lock(&CriticalSection);
    v13 = qword_14235ACC8;
    *(_QWORD *)(qword_14235ACC8 + 8) = v11;
    *(_QWORD *)v11 = v13;
    *(_QWORD *)(v11 + 8) = &qword_14235ACC8;
    qword_14235ACC8 = v11;
    UFG::qMutex::Unlock(&CriticalSection);
  }
}

// File Line: 3437
// RVA: 0x184730
__int64 __fastcall UFG::qGetFileTime(const char *filename)
{
  UFG::qFileDevice *v2; // rdi
  __int64 v3; // rbx
  UFG::qNode<UFG::qString,UFG::qString> *mPrev; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *mNext; // rax
  UFG::qString result; // [rsp+28h] [rbp-30h] BYREF

  v2 = UFG::qFileSystem::MapFilenameToDevice(&UFG::gQuarkFileSystem, filename);
  UFG::qFileSystem::MapFilename(&UFG::gQuarkFileSystem, &result, 0, filename);
  if ( byte_14235ACD8 || !v2 )
    v3 = 0i64;
  else
    v3 = v2->vfptr->GetFilenameTime(v2, result.mData);
  if ( result.mData != UFG::qString::sEmptyString && result.mData )
    UFG::qMemoryPool::Free(UFG::gMainMemoryPool, result.mData);
  mPrev = result.mPrev;
  mNext = result.mNext;
  result.mPrev->mNext = result.mNext;
  mNext->mPrev = mPrev;
  return v3;
}

// File Line: 3465
// RVA: 0x18ABF0
_BOOL8 __fastcall UFG::qSetFileTime(const char *filename, unsigned __int64 file_time)
{
  UFG::qFileDevice *v4; // rdi
  bool v5; // bl
  UFG::qNode<UFG::qString,UFG::qString> *mPrev; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *mNext; // rax
  UFG::qString result; // [rsp+28h] [rbp-30h] BYREF

  v4 = UFG::qFileSystem::MapFilenameToDevice(&UFG::gQuarkFileSystem, filename);
  UFG::qFileSystem::MapFilename(&UFG::gQuarkFileSystem, &result, 0, filename);
  v5 = !byte_14235ACD8 && v4 && v4->vfptr->SetFilenameTime(v4, result.mData, file_time);
  if ( result.mData != UFG::qString::sEmptyString && result.mData )
    UFG::qMemoryPool::Free(UFG::gMainMemoryPool, result.mData);
  mPrev = result.mPrev;
  mNext = result.mNext;
  result.mPrev->mNext = result.mNext;
  mNext->mPrev = mPrev;
  return v5;
}

// File Line: 3513
// RVA: 0x189780
__int64 __fastcall UFG::qRead(const char *filename, void *buffer, __int64 num_bytes, __int64 seek_position)
{
  UFG::qFile *v8; // rax
  __int64 v9; // rbx
  UFG::qFile *v10; // rdi

  if ( !num_bytes )
    return 0i64;
  v8 = UFG::qOpen(filename, QACCESS_READ, 1);
  v9 = -1i64;
  v10 = v8;
  if ( v8 )
  {
    v9 = UFG::qRead(v8, buffer, num_bytes, seek_position, QSEEK_SET);
    UFG::qClose(v10);
  }
  return v9;
}

// File Line: 3537
// RVA: 0x189C20
void __fastcall UFG::qReadAsync(
        const char *filename,
        void *buffer,
        __int64 num_bytes,
        __int64 seek_position,
        void (__fastcall *callback)(UFG::qFileOp *, void *),
        void *callback_param,
        UFG::qFilePriorityLevel priority)
{
  UFG::qMemoryPool *v11; // rcx
  UFG::allocator::free_link *v12; // rax
  __int64 v13; // rax
  __int64 v14; // rbx
  __int64 v15; // rcx
  __int64 v16; // rax

  v11 = UFG::gMainMemoryPool;
  if ( !UFG::gMainMemoryPool )
  {
    UFG::InternalSetupMainMemoryPool((UFG *)UFG::gMainMemoryPool);
    v11 = UFG::gMainMemoryPool;
  }
  v12 = UFG::qMemoryPool::Allocate(v11, 0x170ui64, "qFileOp.OP_OPEN_READ_CLOSE", 0i64, 1u);
  if ( v12 )
  {
    UFG::qFileOp::qFileOp((UFG::qFileOp *)v12, filename, OP_OPEN_READ_CLOSE, callback, callback_param);
    v14 = v13;
  }
  else
  {
    v14 = 0i64;
  }
  *(_DWORD *)(v14 + 128) = 0;
  *(_QWORD *)(v14 + 136) = seek_position;
  *(_QWORD *)(v14 + 120) = buffer;
  *(_QWORD *)(v14 + 144) = num_bytes;
  v15 = *(_QWORD *)(v14 + 16);
  if ( v15 )
  {
    (*(void (__fastcall **)(__int64, __int64, _QWORD))(*(_QWORD *)v15 + 24i64))(v15, v14, (unsigned int)priority);
  }
  else
  {
    *(_DWORD *)(v14 + 28) = 5;
    UFG::qMutex::Lock(&CriticalSection);
    v16 = qword_14235ACC8;
    *(_QWORD *)(qword_14235ACC8 + 8) = v14;
    *(_QWORD *)v14 = v16;
    *(_QWORD *)(v14 + 8) = &qword_14235ACC8;
    qword_14235ACC8 = v14;
    UFG::qMutex::Unlock(&CriticalSection);
  }
}

// File Line: 3554
// RVA: 0x18CF50
__int64 __fastcall UFG::qWrite(
        const char *filename,
        const void *buffer,
        __int64 num_bytes,
        __int64 seek_offset,
        UFG::qFileSeekType seek_type,
        bool *not_enough_space)
{
  UFG::qFile *v10; // rax
  __int64 v11; // rdi
  UFG::qFile *v12; // rbp

  if ( not_enough_space )
    *not_enough_space = 0;
  if ( !num_bytes )
    return 0i64;
  v10 = UFG::qOpen(filename, QACCESS_WRITE, 1);
  v11 = -1i64;
  v12 = v10;
  if ( v10 )
  {
    v11 = UFG::qWrite(v10, buffer, num_bytes, seek_offset, seek_type, not_enough_space);
    UFG::qClose(v12);
  }
  return v11;
}

// File Line: 3585
// RVA: 0x18D170
void __fastcall UFG::qWriteAsync(
        const char *filename,
        const void *buffer,
        __int64 num_bytes,
        __int64 seek_offset,
        UFG::qFileSeekType seek_type,
        void (__fastcall *callback)(UFG::qFileOp *, void *),
        void *callback_param,
        UFG::qFilePriorityLevel priority)
{
  UFG::qMemoryPool *v12; // rcx
  UFG::allocator::free_link *v13; // rax
  __int64 v14; // rax
  __int64 v15; // rbx
  __int64 v16; // rcx
  __int64 v17; // rax

  v12 = UFG::gMainMemoryPool;
  if ( !UFG::gMainMemoryPool )
  {
    UFG::InternalSetupMainMemoryPool((UFG *)UFG::gMainMemoryPool);
    v12 = UFG::gMainMemoryPool;
  }
  v13 = UFG::qMemoryPool::Allocate(v12, 0x170ui64, "qFileOp.OP_OPEN_WRITE_CLOSE", 0i64, 1u);
  if ( v13 )
  {
    UFG::qFileOp::qFileOp((UFG::qFileOp *)v13, filename, OP_OPEN_WRITE_CLOSE, callback, callback_param);
    v15 = v14;
  }
  else
  {
    v15 = 0i64;
  }
  *(_DWORD *)(v15 + 128) = seek_type;
  *(_QWORD *)(v15 + 136) = seek_offset;
  *(_QWORD *)(v15 + 120) = buffer;
  *(_QWORD *)(v15 + 144) = num_bytes;
  v16 = *(_QWORD *)(v15 + 16);
  if ( v16 )
  {
    (*(void (__fastcall **)(__int64, __int64, _QWORD))(*(_QWORD *)v16 + 24i64))(v16, v15, (unsigned int)priority);
  }
  else
  {
    *(_DWORD *)(v15 + 28) = 5;
    UFG::qMutex::Lock(&CriticalSection);
    v17 = qword_14235ACC8;
    *(_QWORD *)(qword_14235ACC8 + 8) = v15;
    *(_QWORD *)v15 = v17;
    *(_QWORD *)(v15 + 8) = &qword_14235ACC8;
    qword_14235ACC8 = v15;
    UFG::qMutex::Unlock(&CriticalSection);
  }
}

// File Line: 3604
// RVA: 0x18D0C0
__int64 __fastcall UFG::qWriteAppend(
        const char *filename,
        const void *buffer,
        __int64 num_bytes,
        __int64 seek_offset,
        UFG::qFileSeekType seek_type,
        bool *not_enough_space)
{
  UFG::qFile *v10; // rax
  __int64 v11; // rdi
  UFG::qFile *v12; // rbp

  if ( not_enough_space )
    *not_enough_space = 0;
  if ( !num_bytes )
    return 0i64;
  v10 = UFG::qOpen(filename, QACCESS_APPEND, 1);
  v11 = -1i64;
  v12 = v10;
  if ( v10 )
  {
    v11 = UFG::qWrite(v10, buffer, num_bytes, seek_offset, seek_type, not_enough_space);
    UFG::qClose(v12);
  }
  return v11;
}

// File Line: 3653
// RVA: 0x18D2A0
__int64 __fastcall UFG::qWriteWithBackup(const char *filename, const void *buffer, __int64 num_bytes)
{
  const char *v6; // rbx
  int v8; // ebx
  __int64 v9; // rbx
  UFG::qFile *v10; // rax
  UFG::qFile *v11; // rsi
  UFG::qNode<UFG::qString,UFG::qString> *mPrev; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *mNext; // rax
  UFG::qNode<UFG::qString,UFG::qString> *v14; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *v15; // rax
  UFG::qString v17; // [rsp+20h] [rbp-11h] BYREF
  UFG::qString v18; // [rsp+48h] [rbp+17h] BYREF

  if ( !filename || !*filename || !buffer )
    return -1i64;
  v6 = filename;
  while ( *v6++ )
    ;
  v8 = (_DWORD)v6 - (_DWORD)filename;
  v17.mNext = &v17;
  *(_QWORD *)&v17.mMagic = 16909060i64;
  v17.mData = (char *)UFG::qString::sEmptyString;
  *(_QWORD *)&v17.mStringHash32 = -1i64;
  v18.mPrev = &v18;
  v18.mNext = &v18;
  *(_QWORD *)&v18.mMagic = 16909060i64;
  v18.mData = (char *)UFG::qString::sEmptyString;
  *(_QWORD *)&v18.mStringHash32 = -1i64;
  UFG::qString::Set(&v17, filename, v8 - 1, ".tmp", 4);
  UFG::qString::Set(&v18, filename, v8 - 1, ".bak", 4);
  UFG::qDeleteFile(v17.mData);
  if ( num_bytes )
  {
    v10 = UFG::qOpen(v17.mData, QACCESS_WRITE, 1);
    v11 = v10;
    v9 = -1i64;
    if ( v10 )
    {
      v9 = UFG::qWrite(v10, buffer, num_bytes, 0i64, QSEEK_CUR, 0i64);
      UFG::qClose(v11);
    }
    if ( v9 != num_bytes )
      goto LABEL_14;
  }
  else
  {
    v9 = 0i64;
  }
  UFG::qDeleteFile(v18.mData);
  UFG::qRenameFile(filename, v18.mData);
  if ( UFG::qRenameFile(v17.mData, filename) )
  {
    UFG::qDeleteFile(v18.mData);
    goto LABEL_15;
  }
  UFG::qRenameFile(v18.mData, filename);
LABEL_14:
  UFG::qDeleteFile(v17.mData);
  v9 = -1i64;
LABEL_15:
  if ( v18.mData != UFG::qString::sEmptyString && v18.mData )
    UFG::qMemoryPool::Free(UFG::gMainMemoryPool, v18.mData);
  v18.mMagic = 0;
  mPrev = v18.mPrev;
  mNext = v18.mNext;
  v18.mPrev->mNext = v18.mNext;
  mNext->mPrev = mPrev;
  v18.mPrev = &v18;
  v18.mNext = &v18;
  if ( v17.mData != UFG::qString::sEmptyString )
  {
    if ( v17.mData )
      UFG::qMemoryPool::Free(UFG::gMainMemoryPool, v17.mData);
  }
  v17.mMagic = 0;
  v14 = v17.mPrev;
  v15 = v17.mNext;
  v17.mPrev->mNext = v17.mNext;
  v15->mPrev = v14;
  v17.mPrev = &v17;
  v17.mNext = &v17;
  return v9;
}

// File Line: 3777
// RVA: 0x189820
__int64 __fastcall UFG::qReadAndDecompress(
        UFG::qFile *file,
        unsigned __int8 *buffer,
        __int64 num_bytes,
        __int64 seek_offset,
        UFG::qFileSeekType seek_type,
        __int64 read_offset,
        __int64 read_bytes,
        __int64 read_data_offset,
        unsigned __int8 *scratch_buffer,
        __int64 scratch_size,
        bool in_place)
{
  __int64 v14; // rax
  __int64 v15; // rbp
  __int64 v16; // r15
  char *v17; // rcx
  __int64 v18; // rdx
  unsigned __int8 *v19; // r12
  __int64 v20; // rbx
  __int64 v21; // rax
  char *v22; // [rsp+68h] [rbp+10h]

  if ( !buffer )
    return -1i64;
  v14 = read_offset + read_bytes;
  if ( !scratch_buffer )
  {
    if ( num_bytes >= v14 )
    {
      v16 = read_data_offset;
      v17 = (char *)&buffer[read_offset];
      v18 = read_bytes + read_data_offset;
      v22 = v17;
      goto LABEL_10;
    }
    return -1i64;
  }
  v15 = scratch_size;
  if ( scratch_size < v14 )
    return -1i64;
  v16 = read_data_offset;
  v17 = (char *)&scratch_buffer[read_offset];
  v18 = read_bytes + read_data_offset;
  v22 = (char *)&scratch_buffer[read_offset];
  if ( in_place )
  {
    v19 = scratch_buffer;
    goto LABEL_11;
  }
LABEL_10:
  v15 = num_bytes;
  v19 = buffer;
LABEL_11:
  v20 = -1i64;
  if ( UFG::qRead(file, v17, v18, seek_offset, seek_type) == read_bytes + v16 )
  {
    v21 = UFG::qDecompressLZ((UFG::qCompressHeader *)&v22[v16], read_bytes, v19, v15);
    v20 = v21;
    if ( scratch_buffer )
    {
      if ( in_place )
        UFG::qMemCopy(buffer, scratch_buffer, v21);
    }
  }
  return v20;
}

// File Line: 3859
// RVA: 0x189960
void __fastcall UFG::qReadAndDecompressAsync(
        UFG::qFile *file,
        void *buffer,
        __int64 num_bytes,
        __int64 seek_offset,
        UFG::qFileSeekType seek_type,
        __int64 read_offset,
        __int64 read_bytes,
        __int64 read_data_offset,
        void *scratch_buffer,
        __int64 scratch_size,
        bool in_place,
        void (__fastcall *callback)(UFG::qFileOp *, void *),
        void *callback_param,
        UFG::qFilePriorityLevel priority)
{
  UFG::qMemoryPool *v18; // rcx
  UFG::allocator::free_link *v19; // rax
  __int64 v20; // rax
  __int64 v21; // rbx
  __int64 v22; // rcx
  __int64 v23; // rax

  v18 = UFG::gMainMemoryPool;
  if ( !UFG::gMainMemoryPool )
  {
    UFG::InternalSetupMainMemoryPool((UFG *)UFG::gMainMemoryPool);
    v18 = UFG::gMainMemoryPool;
  }
  v19 = UFG::qMemoryPool::Allocate(v18, 0x170ui64, "qFileOp.OP_READ_AND_DECOMPRESS", 0i64, 1u);
  if ( v19 )
  {
    UFG::qFileOp::qFileOp((UFG::qFileOp *)v19, file, OP_READ_AND_DECOMPRESS, callback, callback_param);
    v21 = v20;
  }
  else
  {
    v21 = 0i64;
  }
  *(_DWORD *)(v21 + 128) = seek_type;
  *(_QWORD *)(v21 + 136) = seek_offset;
  *(_QWORD *)(v21 + 120) = buffer;
  *(_QWORD *)(v21 + 144) = num_bytes;
  *(_QWORD *)(v21 + 192) = scratch_buffer;
  *(_QWORD *)(v21 + 184) = scratch_size;
  *(_BYTE *)(v21 + 200) = in_place;
  *(_QWORD *)(v21 + 160) = read_offset;
  *(_QWORD *)(v21 + 168) = read_bytes;
  *(_QWORD *)(v21 + 176) = read_data_offset;
  v22 = *(_QWORD *)(v21 + 16);
  if ( v22 )
  {
    (*(void (__fastcall **)(__int64, __int64, _QWORD))(*(_QWORD *)v22 + 24i64))(v22, v21, (unsigned int)priority);
  }
  else
  {
    *(_DWORD *)(v21 + 28) = 5;
    UFG::qMutex::Lock(&CriticalSection);
    v23 = qword_14235ACC8;
    *(_QWORD *)(qword_14235ACC8 + 8) = v21;
    *(_QWORD *)v21 = v23;
    *(_QWORD *)(v21 + 8) = &qword_14235ACC8;
    qword_14235ACC8 = v21;
    UFG::qMutex::Unlock(&CriticalSection);
  }
}

// File Line: 3902
// RVA: 0x16DB50
char __fastcall UFG::FileOpFlushBufferCallback(UFG::qFile **param, __int64 position, void *buffer, __int64 buffer_size)
{
  UFG::qFile *v6; // rcx
  __int64 v7; // rax
  UFG::qFile *v8; // rcx
  bool not_enough_space; // [rsp+40h] [rbp+8h] BYREF

  if ( *((_BYTE *)param + 16) )
  {
    v6 = *param;
    not_enough_space = 0;
    v7 = UFG::qWrite(v6, buffer, buffer_size, position, QSEEK_SET, &not_enough_space);
    if ( not_enough_space )
    {
      v8 = param[1];
      if ( v8 )
        LOBYTE(v8->mPrev) = 1;
      *((_BYTE *)param + 16) = 0;
    }
    if ( v7 != buffer_size )
      *((_BYTE *)param + 16) = 0;
  }
  return 1;
}

// File Line: 3937
// RVA: 0x18D000
__int64 __fastcall UFG::qWriteAndCompress(
        UFG::qFile *file,
        void *buffer,
        __int64 num_bytes,
        void *scratch_buffer,
        __int64 scratch_size,
        bool *not_enough_space)
{
  __int64 v10; // rdx
  bool v12; // [rsp+30h] [rbp-28h] BYREF
  __int64 callback_param[2]; // [rsp+38h] [rbp-20h] BYREF
  char v14; // [rsp+48h] [rbp-10h]

  if ( !UFG::qWaitForOpenFileHandle(file) || !buffer )
    return -1i64;
  callback_param[1] = (__int64)&v12;
  v12 = 0;
  callback_param[0] = (__int64)file;
  v14 = 1;
  v10 = UFG::qCompressBufferedLZ(
          buffer,
          num_bytes,
          scratch_buffer,
          scratch_size,
          (bool (__fastcall *)(void *, __int64, void *, __int64))UFG::FileOpFlushBufferCallback,
          callback_param);
  if ( not_enough_space )
    *not_enough_space = v12;
  if ( !v14 )
    return -1i64;
  return v10;
}

// File Line: 4138
// RVA: 0x184380
unsigned __int64 __fastcall UFG::qGetFileChecksum64(const char *filename, unsigned __int64 previous_checksum)
{
  UFG::qFile *v3; // rax
  UFG::qFile *v4; // rbp
  __int64 v5; // rsi
  UFG::qMemoryPool *v6; // rcx
  signed __int64 v7; // r14
  UFG::allocator::free_link *v8; // r15
  __int64 v9; // rdi
  unsigned int v10; // r8d
  UFG::allocator::free_link *v11; // rdx
  char mNext; // al

  v3 = UFG::qOpen(filename, QACCESS_READ, 1);
  v4 = v3;
  if ( v3 )
  {
    if ( UFG::qWaitForOpenFileHandle(v3) )
    {
      UFG::qMutex::Lock((LPCRITICAL_SECTION)&v4->mFileHandleMutex);
      v5 = v4->mDevice->vfptr->GetFileSize(v4->mDevice, v4);
      UFG::qMutex::Unlock((LPCRITICAL_SECTION)&v4->mFileHandleMutex);
    }
    else
    {
      v5 = -1i64;
    }
    v6 = UFG::gMainMemoryPool;
    v7 = v5;
    if ( v5 > 0x10000 )
      v7 = 0x10000i64;
    if ( !UFG::gMainMemoryPool )
    {
      UFG::InternalSetupMainMemoryPool(0i64);
      v6 = UFG::gMainMemoryPool;
    }
    v8 = UFG::qMemoryPool::Allocate(v6, v7, "qGetFileChecksum64 buffer", 1ui64, 1u);
    if ( v8 )
    {
      for ( ; v5 > 0; v5 -= v9 )
      {
        v9 = v5;
        if ( v5 > v7 )
          v9 = v7;
        UFG::qRead(v4, v8, v9, 0i64, QSEEK_CUR);
        v10 = 0;
        v11 = v8;
        if ( (_DWORD)v9 )
        {
          do
          {
            mNext = (char)v11->mNext;
            ++v10;
            v11 = (UFG::allocator::free_link *)((char *)v11 + 1);
            previous_checksum = (previous_checksum >> 8) ^ sCrcTable64[(unsigned __int8)(previous_checksum ^ mNext)];
          }
          while ( v10 < (unsigned __int64)(unsigned int)v9 );
        }
      }
      UFG::qMemoryPool::Free(UFG::gMainMemoryPool, (char *)v8);
    }
    UFG::qClose(v4);
  }
  return previous_checksum;
}

// File Line: 4178
// RVA: 0x184200
__int64 __fastcall UFG::qGetFileChecksum32(const char *filename, unsigned int previous_checksum)
{
  UFG::qFile *v3; // rax
  UFG::qFile *v4; // rbp
  __int64 v5; // rsi
  UFG::qMemoryPool *v6; // rcx
  signed __int64 v7; // r14
  UFG::allocator::free_link *v8; // r15
  __int64 v9; // rdi
  unsigned int v10; // r8d
  UFG::allocator::free_link *v11; // rdx
  char mNext; // al

  v3 = UFG::qOpen(filename, QACCESS_READ, 1);
  v4 = v3;
  if ( v3 )
  {
    if ( UFG::qWaitForOpenFileHandle(v3) )
    {
      UFG::qMutex::Lock((LPCRITICAL_SECTION)&v4->mFileHandleMutex);
      v5 = v4->mDevice->vfptr->GetFileSize(v4->mDevice, v4);
      UFG::qMutex::Unlock((LPCRITICAL_SECTION)&v4->mFileHandleMutex);
    }
    else
    {
      v5 = -1i64;
    }
    v6 = UFG::gMainMemoryPool;
    v7 = v5;
    if ( v5 > 0x10000 )
      v7 = 0x10000i64;
    if ( !UFG::gMainMemoryPool )
    {
      UFG::InternalSetupMainMemoryPool(0i64);
      v6 = UFG::gMainMemoryPool;
    }
    v8 = UFG::qMemoryPool::Allocate(v6, v7, "qGetFileChecksum32 buffer", 1ui64, 1u);
    if ( v8 )
    {
      for ( ; v5 > 0; v5 -= v9 )
      {
        v9 = v5;
        if ( v5 > v7 )
          v9 = v7;
        UFG::qRead(v4, v8, v9, 0i64, QSEEK_CUR);
        v10 = 0;
        v11 = v8;
        if ( (_DWORD)v9 )
        {
          do
          {
            mNext = (char)v11->mNext;
            ++v10;
            v11 = (UFG::allocator::free_link *)((char *)v11 + 1);
            previous_checksum = (previous_checksum << 8) ^ sCrcTable32[(unsigned __int8)(mNext ^ HIBYTE(previous_checksum))];
          }
          while ( v10 < (unsigned __int64)(unsigned int)v9 );
        }
      }
      UFG::qMemoryPool::Free(UFG::gMainMemoryPool, (char *)v8);
    }
    UFG::qClose(v4);
  }
  return previous_checksum;
}

// File Line: 4356
// RVA: 0x182810
char __fastcall UFG::qCopyFile(const char *src_filename, const char *dest_filename)
{
  UFG::qFile *v4; // r12
  UFG::qFile *v5; // rax
  char v6; // bp
  UFG::qFile *v7; // rsi
  __int64 v8; // rdi
  signed __int64 v9; // r15
  char *v10; // r14
  __int64 v11; // rbx

  if ( !dest_filename || !*dest_filename || !src_filename || !*src_filename || !UFG::qFileExists(src_filename) )
    return 0;
  v4 = UFG::qOpen(dest_filename, QACCESS_WRITE, 1);
  v5 = UFG::qOpen(src_filename, QACCESS_READ, 1);
  v6 = 0;
  v7 = v5;
  if ( v4 )
  {
    if ( v5 )
    {
      if ( UFG::qWaitForOpenFileHandle(v5) )
      {
        UFG::qMutex::Lock((LPCRITICAL_SECTION)&v7->mFileHandleMutex);
        v8 = v7->mDevice->vfptr->GetFileSize(v7->mDevice, v7);
        UFG::qMutex::Unlock((LPCRITICAL_SECTION)&v7->mFileHandleMutex);
      }
      else
      {
        v8 = -1i64;
      }
      v9 = v8;
      v6 = 0;
      if ( v8 > 0x10000 )
        v9 = 0x10000i64;
      if ( !v8 )
        v6 = 1;
      v10 = UFG::qMalloc(v9, "qCopyFile buffer", 1ui64);
      if ( v10 )
      {
        v6 = 1;
        if ( v8 > 0 )
        {
          while ( 1 )
          {
            v11 = v8;
            if ( v8 > v9 )
              v11 = v9;
            if ( UFG::qRead(v7, v10, v11, 0i64, QSEEK_CUR) != v11
              || UFG::qWrite(v4, v10, v11, 0i64, QSEEK_CUR, 0i64) != v11 )
            {
              break;
            }
            v8 -= v11;
            if ( v8 <= 0 )
              goto LABEL_24;
          }
          v6 = 0;
        }
LABEL_24:
        UFG::qMemoryPool::Free(UFG::gMainMemoryPool, v10);
      }
    }
    UFG::qClose(v4);
  }
  if ( v7 )
    UFG::qClose(v7);
  return v6;
}

// File Line: 4571
// RVA: 0x189D50
char *__fastcall UFG::qReadEntireFile(
        const char *filename,
        __int64 *loaded_size,
        UFG::qMemoryPool *memory_pool,
        unsigned __int64 allocation_params,
        char *name)
{
  __int64 FileSize; // rax
  __int64 v10; // rbx
  UFG::qFile *v11; // rsi
  char *v12; // r8
  UFG::allocator::free_link *v13; // rax
  char *v14; // rdi
  char dest[384]; // [rsp+30h] [rbp-188h] BYREF

  if ( byte_14235ACD8 || !filename || !*filename )
    return 0i64;
  FileSize = UFG::qGetFileSize(filename);
  v10 = FileSize;
  if ( loaded_size )
    *loaded_size = FileSize;
  if ( FileSize > 0 )
  {
    if ( !memory_pool )
      memory_pool = UFG::gMainMemoryPool;
    v11 = UFG::qOpen(filename, QACCESS_READ, 1);
    if ( v11 )
    {
      if ( !name )
        UFG::qSPrintf(dest, "qReadEntireFile(%s)", filename);
      v12 = dest;
      if ( name )
        v12 = name;
      v13 = UFG::qMemoryPool::Allocate(memory_pool, v10 + 1, v12, allocation_params, 1u);
      v14 = (char *)v13;
      if ( v13 )
      {
        if ( (int)UFG::qRead(v11, v13, v10, 0i64, QSEEK_CUR) == v10 )
        {
          UFG::qClose(v11);
          v14[v10] = 0;
          return v14;
        }
        UFG::qClose(v11);
        UFG::qMemoryPool::Free(memory_pool, v14);
      }
      else
      {
        UFG::qClose(v11);
      }
    }
  }
  return 0i64;
}

// File Line: 4640
// RVA: 0x189EA0
void __fastcall UFG::qReadEntireFileAsync(
        const char *filename,
        void (__fastcall *callback)(UFG::qFileOp *, void *),
        void *callback_param,
        UFG::qMemoryPool *memory_pool,
        unsigned __int64 allocation_params,
        const char *name,
        UFG::qFilePriorityLevel priority)
{
  UFG::qMemoryPool *v11; // rcx
  UFG::allocator::free_link *v12; // rax
  __int64 v13; // rax
  __int64 v14; // rbx
  const char *v15; // r10
  const char *v16; // rdx
  int v18; // edx
  __int64 v19; // rcx
  __int64 v20; // rax

  v11 = UFG::gMainMemoryPool;
  if ( !UFG::gMainMemoryPool )
  {
    UFG::InternalSetupMainMemoryPool((UFG *)UFG::gMainMemoryPool);
    v11 = UFG::gMainMemoryPool;
  }
  v12 = UFG::qMemoryPool::Allocate(v11, 0x170ui64, "qFileOp.OP_READ_ENTIRE_FILE", 0i64, 1u);
  if ( v12 )
  {
    UFG::qFileOp::qFileOp((UFG::qFileOp *)v12, filename, OP_READ_ENTIRE_FILE, callback, callback_param);
    v14 = v13;
  }
  else
  {
    v14 = 0i64;
  }
  *(_QWORD *)(v14 + 264) = memory_pool;
  *(_QWORD *)(v14 + 216) = allocation_params;
  v15 = "ReadEntireFileAsync";
  if ( name )
    v15 = name;
  if ( !v15 || v15 == UFG::qString::sEmptyString )
  {
    v18 = 0;
  }
  else
  {
    v16 = v15;
    while ( *v16++ )
      ;
    v18 = (_DWORD)v16 - (_DWORD)v15 - 1;
  }
  UFG::qString::Set((UFG::qString *)(v14 + 224), v15, v18, 0i64, 0);
  v19 = *(_QWORD *)(v14 + 16);
  if ( v19 )
  {
    (*(void (__fastcall **)(__int64, __int64, _QWORD))(*(_QWORD *)v19 + 24i64))(v19, v14, (unsigned int)priority);
  }
  else
  {
    *(_DWORD *)(v14 + 28) = 5;
    UFG::qMutex::Lock(&CriticalSection);
    v20 = qword_14235ACC8;
    *(_QWORD *)(qword_14235ACC8 + 8) = v14;
    *(_QWORD *)v14 = v20;
    *(_QWORD *)(v14 + 8) = &qword_14235ACC8;
    qword_14235ACC8 = v14;
    UFG::qMutex::Unlock(&CriticalSection);
  }
}

// File Line: 4656
// RVA: 0x183C50
void __fastcall UFG::qFreeEntireFile(char *ptr, UFG::qMemoryPool *memory_pool)
{
  UFG::qMemoryPool *v2; // rax

  v2 = memory_pool;
  if ( ptr )
  {
    if ( !memory_pool )
      v2 = UFG::gMainMemoryPool;
    UFG::qMemoryPool::Free(v2, ptr);
  }
}

// File Line: 4670
// RVA: 0x18A010
UFG::qString *__fastcall UFG::qReadString(UFG::qString *result, const char *filename)
{
  __int64 FileSize; // rbp
  UFG::qMemoryPool *v5; // r14
  UFG::qFile *v6; // rsi
  UFG::allocator::free_link *v7; // rax
  char *v8; // rdi
  char *v10; // rcx
  int v12; // ecx
  char dest[384]; // [rsp+40h] [rbp-198h] BYREF

  result->mPrev = result;
  result->mNext = result;
  result->mMagic = 16909060;
  result->mData = (char *)UFG::qString::sEmptyString;
  result->mLength = 0;
  *(_QWORD *)&result->mStringHash32 = -1i64;
  if ( byte_14235ACD8 || !filename || !*filename )
    return result;
  FileSize = UFG::qGetFileSize(filename);
  if ( FileSize <= 0 )
    return result;
  v5 = UFG::gMainMemoryPool;
  v6 = UFG::qOpen(filename, QACCESS_READ, 1);
  if ( !v6 )
    return result;
  UFG::qSPrintf(dest, "qReadEntireFile(%s)", filename);
  v7 = UFG::qMemoryPool::Allocate(v5, FileSize + 1, dest, 0i64, 1u);
  v8 = (char *)v7;
  if ( !v7 )
  {
    UFG::qClose(v6);
    return result;
  }
  if ( (int)UFG::qRead(v6, v7, FileSize, 0i64, QSEEK_CUR) == FileSize )
  {
    UFG::qClose(v6);
    v8[FileSize] = 0;
    if ( v8 == UFG::qString::sEmptyString )
    {
      v12 = 0;
    }
    else
    {
      v10 = v8;
      while ( *v10++ )
        ;
      v12 = (_DWORD)v10 - (_DWORD)v8 - 1;
    }
    UFG::qString::Set(result, v8, v12, 0i64, 0);
    UFG::qMemoryPool::Free(UFG::gMainMemoryPool, v8);
    return result;
  }
  else
  {
    UFG::qClose(v6);
    UFG::qMemoryPool::Free(v5, v8);
    return result;
  }
}

