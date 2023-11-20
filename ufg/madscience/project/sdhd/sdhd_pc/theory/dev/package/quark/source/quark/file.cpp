// File Line: 48
// RVA: 0x1467F20
__int64 UFG::_dynamic_initializer_for__gQuarkFileSystem__()
{
  UFG::qFileSystem::qFileSystem(&UFG::gQuarkFileSystem);
  return atexit(UFG::_dynamic_atexit_destructor_for__gQuarkFileSystem__);
}

// File Line: 581
// RVA: 0x160D20
void __fastcall UFG::qFile::qFile(UFG::qFile *this, UFG::qFileDevice *device, const char *filename, int access_type)
{
  int v4; // esi
  const char *v5; // rdi
  UFG::qFileDevice *v6; // rbp
  UFG::qFile *v7; // rbx
  signed int v8; // edx
  char *v9; // rax
  signed __int64 v10; // rdi
  char v11; // cl

  v4 = access_type;
  v5 = filename;
  v6 = device;
  v7 = this;
  this->mPrev = (UFG::qNode<UFG::qFile,UFG::qFile> *)&this->mPrev;
  this->mNext = (UFG::qNode<UFG::qFile,UFG::qFile> *)&this->mPrev;
  UFG::qMutex::qMutex(&this->mFileHandleMutex, "qFile::mOperationMutex");
  UFG::qMutex::qMutex(&v7->mStateMutex, "qFile::mStateMutex");
  v8 = 0x104;
  v9 = v7->mFilename;
  if ( v7 != (UFG::qFile *)0xFFFFFFFFFFFFFF60i64 )
  {
    if ( !v5 )
      goto LABEL_11;
    v10 = v5 - v9;
    do
    {
      v11 = v9[v10];
      *v9++ = v11;
      if ( !v11 )
        break;
      --v8;
    }
    while ( v8 > 1 );
    if ( *(v9 - 1) )
LABEL_11:
      *v9 = 0;
  }
  v7->mDevice = v6;
  v7->mAccessType = v4;
  *(_QWORD *)&v7->mOpenState = 0i64;
  v7->mNumAsyncOps = 0;
  v7->mAsyncCloseOp = 0i64;
  v7->mFileHandle = 0i64;
}

// File Line: 626
// RVA: 0x160F30
UFG::qFileOp::qFileOp

// File Line: 666
// RVA: 0x161110
void __fastcall UFG::qFileOp::qFileOp(UFG::qFileOp *this, const char *filename, UFG::qFileOp::OpType type, void (__fastcall *callback)(UFG::qFileOp *, void *), void *callback_param)
{
  void (__fastcall *v5)(UFG::qFileOp *, void *); // rbp
  UFG::qFileOp::OpType v6; // ebx
  const char *v7; // rsi
  UFG::qFileOp *v8; // rdi
  UFG::qString *v9; // r14
  UFG::qString *v10; // rcx
  UFG::qString *v11; // rcx
  UFG::qList<UFG::qString,UFG::qString,1,0> *v12; // rax
  UFG::qList<UFG::qString,UFG::qString,1,0> *v13; // rax
  const char *v14; // rcx
  char v15; // al
  int v16; // ecx
  unsigned __int64 v17; // rax

  v5 = callback;
  v6 = type;
  v7 = filename;
  v8 = this;
  this->mPrev = (UFG::qNode<UFG::qFileOp,UFG::qFileOp> *)&this->mPrev;
  this->mNext = (UFG::qNode<UFG::qFileOp,UFG::qFileOp> *)&this->mPrev;
  v9 = &this->mFilename;
  v9->mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&v9->mPrev;
  v9->mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&v9->mPrev;
  this->mFilename.mMagic = 16909060;
  this->mFilename.mData = (char *)UFG::qString::sEmptyString;
  this->mFilename.mLength = 0;
  *(_QWORD *)&this->mFilename.mStringHash32 = -1i64;
  v10 = &this->mAllocationName;
  v10->mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&v10->mPrev;
  v10->mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&v10->mPrev;
  v10->mMagic = 16909060;
  v10->mData = (char *)UFG::qString::sEmptyString;
  v10->mLength = 0;
  *(_QWORD *)&v10->mStringHash32 = -1i64;
  v11 = &v8->mDestinationFilename;
  v11->mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&v11->mPrev;
  v11->mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&v11->mPrev;
  v8->mDestinationFilename.mMagic = 16909060;
  v8->mDestinationFilename.mData = (char *)UFG::qString::sEmptyString;
  v8->mDestinationFilename.mLength = 0;
  *(_QWORD *)&v8->mDestinationFilename.mStringHash32 = -1i64;
  v12 = &v8->mPatterns;
  v12->mNode.mPrev = &v12->mNode;
  v12->mNode.mNext = &v12->mNode;
  v13 = &v8->mResultFiles;
  v13->mNode.mPrev = &v13->mNode;
  v13->mNode.mNext = &v13->mNode;
  v8->mDevice = UFG::qFileSystem::MapFilenameToDevice(&UFG::gQuarkFileSystem, filename);
  v8->mType = v6;
  *(_DWORD *)v8->mStatus = 0;
  v8->mFile = 0i64;
  if ( v7 && v7 != UFG::qString::sEmptyString )
  {
    v14 = v7;
    do
      v15 = *v14++;
    while ( v15 );
    v16 = (_DWORD)v14 - (_DWORD)v7 - 1;
  }
  else
  {
    v16 = 0;
  }
  UFG::qString::Set(v9, v7, v16, 0i64, 0);
  v17 = UFG::qGetTicks();
  v8->mStartTime = UFG::qGetTickTime(UFG::gQuarkFileSystem.mStartTicks, v17);
  *(_QWORD *)&v8->mQueuedTime = 0i64;
  v8->mDoneTime = 0.0;
  v8->mWarnOnFail = 0;
  v8->mCallback = v5;
  v8->mCallbackParam = callback_param;
  v8->mSeekType = 1;
  v8->mSeekOffset = 0i64;
  v8->mBuffer = 0i64;
  v8->mNumBytes = 0i64;
  v8->mScratchBuffer = 0i64;
  v8->mScratchBufferSize = 0i64;
  v8->mReadOffset = 0i64;
  v8->mReadBytes = 0i64;
  v8->mReadDataOffset = 0i64;
  v8->mAllocationParams = 1i64;
  v8->mMemoryPool = 0i64;
  v8->mPreviousChecksum = 0i64;
  v8->mResult0 = 0i64;
  v8->mResult1 = 0i64;
}

// File Line: 706
// RVA: 0x163950
UFG::qFileOp::~qFileOp

// File Line: 710
// RVA: 0x172470
const char *__fastcall UFG::qFileOp::GetStatusName(UFG::qFileOp *this)
{
  __int64 v1; // rax
  const char *result; // rax
  const char *v3; // [rsp+0h] [rbp-48h]
  const char *v4; // [rsp+8h] [rbp-40h]
  const char *v5; // [rsp+10h] [rbp-38h]
  const char *v6; // [rsp+18h] [rbp-30h]
  const char *v7; // [rsp+20h] [rbp-28h]
  const char *v8; // [rsp+28h] [rbp-20h]
  const char *v9; // [rsp+30h] [rbp-18h]
  const char *v10; // [rsp+38h] [rbp-10h]

  v3 = "NONE";
  v4 = "QUEUED";
  v5 = "EXECUTING";
  v6 = "DONE";
  v7 = "CANCELLED";
  v8 = "ERROR";
  v9 = "ERROR_NOT_ENOUGH_SPACE";
  v10 = "ERROR_DECOMPRESSION";
  v1 = *(signed int *)this->mStatus;
  if ( (unsigned int)v1 > 7 )
    result = "<unknown>";
  else
    result = (&v3)[v1];
  return result;
}

// File Line: 733
// RVA: 0x172CD0
const char *__fastcall UFG::qFileOp::GetTypeName(UFG::qFileOp *this)
{
  __int64 v1; // rax
  const char *result; // rax
  const char *v3; // [rsp+0h] [rbp-A8h]
  const char *v4; // [rsp+8h] [rbp-A0h]
  const char *v5; // [rsp+10h] [rbp-98h]
  const char *v6; // [rsp+18h] [rbp-90h]
  const char *v7; // [rsp+20h] [rbp-88h]
  const char *v8; // [rsp+28h] [rbp-80h]
  const char *v9; // [rsp+30h] [rbp-78h]
  const char *v10; // [rsp+38h] [rbp-70h]
  const char *v11; // [rsp+40h] [rbp-68h]
  const char *v12; // [rsp+48h] [rbp-60h]
  const char *v13; // [rsp+50h] [rbp-58h]
  const char *v14; // [rsp+58h] [rbp-50h]
  const char *v15; // [rsp+60h] [rbp-48h]
  const char *v16; // [rsp+68h] [rbp-40h]
  const char *v17; // [rsp+70h] [rbp-38h]
  const char *v18; // [rsp+78h] [rbp-30h]
  const char *v19; // [rsp+80h] [rbp-28h]
  const char *v20; // [rsp+88h] [rbp-20h]
  const char *v21; // [rsp+90h] [rbp-18h]
  const char *v22; // [rsp+98h] [rbp-10h]

  v3 = "OPEN";
  v4 = "CLOSE";
  v5 = "READ";
  v6 = "WRITE";
  v7 = "TIME";
  v8 = "SET_FILE_TIME";
  v9 = "OPEN_READ_CLOSE";
  v10 = "OPEN_WRITE_CLOSE";
  v11 = "OPEN_APPEND_CLOSE";
  v12 = "READ_AND_DECOMPRESS";
  v13 = "WRITE_AND_COMPRESS";
  v14 = "GET_SIZE";
  v15 = "READ_ENTIRE_FILE";
  v16 = "EXISTS";
  v17 = "CHECKSUM_32";
  v18 = "CHECKSUM_64";
  v19 = "COPY_FILE";
  v20 = "DELETE_FILE";
  v21 = "RENAME_FILE";
  v22 = "WRITE_WITH_BACKUP";
  v1 = this->mType;
  if ( (unsigned int)v1 > 0x13 )
    result = "<unknown>";
  else
    result = (&v3)[v1];
  return result;
}

// File Line: 793
// RVA: 0x1708D0
char *__fastcall UFG::qFileOp::GetFilename(UFG::qFileOp *this)
{
  UFG::qFile *v1; // rax
  char *result; // rax

  v1 = this->mFile;
  if ( v1 )
    result = v1->mFilename;
  else
    result = this->mFilename.mData;
  return result;
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
  UFG::qFileOp::OpType v1; // eax
  UFG::qFileOp *v2; // rdi
  unsigned int v3; // ebx
  char v4; // al
  __int64 v5; // rax
  __int64 v6; // rax
  unsigned __int64 v7; // rax
  bool v8; // zf
  __int64 v9; // rax
  __int64 v10; // rax
  __int64 v11; // rax
  __int64 v12; // rax
  signed int v13; // ecx
  char *v14; // rax
  unsigned __int64 v15; // rax
  float v16; // xmm0_4
  unsigned __int64 result; // rax
  bool not_enough_space; // [rsp+70h] [rbp+8h]

  v1 = this->mType;
  v2 = this;
  v3 = 5;
  not_enough_space = 1;
  switch ( v1 )
  {
    case 0:
      v4 = UFG::qOpenInternal(this->mFile, this->mWarnOnFail);
      goto LABEL_45;
    case 1:
      v4 = UFG::qCloseInternal(this->mFile);
      goto LABEL_45;
    case 2:
      v5 = UFG::qRead(this->mFile, this->mBuffer, this->mNumBytes, this->mSeekOffset, this->mSeekType);
      goto LABEL_5;
    case 3:
      v6 = UFG::qWrite(
             this->mFile,
             this->mBuffer,
             this->mNumBytes,
             this->mSeekOffset,
             this->mSeekType,
             &not_enough_space);
      v2->mResult1 = v6;
      if ( v6 == v2->mNumBytes )
        goto LABEL_32;
      v3 = (not_enough_space != 0) + 5;
      break;
    case 4:
      v7 = UFG::qGetFileTime(this->mFilename.mData);
      v2->mResult0 = v7;
      v8 = v7 == 0;
      goto LABEL_46;
    case 5:
      v4 = UFG::qSetFileTime(this->mFilename.mData, this->mFileTime);
      goto LABEL_45;
    case 6:
      v9 = UFG::qRead(this->mFilename.mData, this->mBuffer, this->mNumBytes, this->mSeekOffset);
      v8 = v9 == v2->mNumBytes;
      v2->mResult0 = v9;
      if ( v8 )
        v3 = 3;
      break;
    case 7:
      v10 = UFG::qWrite(this->mFilename.mData, this->mBuffer, this->mNumBytes, this->mSeekOffset, this->mSeekType, 0i64);
      goto LABEL_16;
    case 8:
      v10 = UFG::qWriteAppend(
              this->mFilename.mData,
              this->mBuffer,
              this->mNumBytes,
              this->mSeekOffset,
              this->mSeekType,
              0i64);
      goto LABEL_16;
    case 9:
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
      v2->mResult1 = v11;
      if ( v11 >= 0 )
        v3 = 3;
      break;
    case 10:
      v12 = UFG::qWriteAndCompress(
              this->mFile,
              this->mBuffer,
              this->mNumBytes,
              this->mScratchBuffer,
              this->mScratchBufferSize,
              &not_enough_space);
      v8 = not_enough_space == 0;
      v2->mResult1 = v12;
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
    case 11:
      v5 = UFG::qGetFileSize(this->mFilename.mData);
LABEL_5:
      v2->mResult0 = v5;
      if ( v5 >= 0 )
        v3 = 3;
      break;
    case 12:
      v14 = UFG::qReadEntireFile(
              this->mFilename.mData,
              (__int64 *)&this->336,
              this->mMemoryPool,
              this->mAllocationParams,
              this->mAllocationName.mData);
      v2->mResult1 = (unsigned __int64)v14;
      v8 = v14 == 0i64;
      goto LABEL_46;
    case 13:
      v4 = UFG::qFileExists(this->mFilename.mData);
      goto LABEL_45;
    case 14:
      this->mResultChecksum32 = UFG::qGetFileChecksum32(this->mFilename.mData, this->mPreviousChecksum);
LABEL_32:
      v3 = 3;
      break;
    case 15:
      v3 = 3;
      this->mResult0 = UFG::qGetFileChecksum64(this->mFilename.mData, this->mPreviousChecksum);
      break;
    case 16:
      v4 = UFG::qCopyFile(this->mFilename.mData, this->mDestinationFilename.mData);
      goto LABEL_45;
    case 17:
      v4 = UFG::qDeleteFile(this->mFilename.mData);
      goto LABEL_45;
    case 18:
      v4 = UFG::qRenameFile(this->mFilename.mData, this->mDestinationFilename.mData);
      goto LABEL_45;
    case 19:
      v10 = UFG::qWriteWithBackup(this->mFilename.mData, this->mBuffer, this->mNumBytes);
LABEL_16:
      v8 = v10 == v2->mNumBytes;
      v2->mResult1 = v10;
      if ( v8 )
        v3 = 3;
      break;
    case 20:
      if ( UFG::qGetFiles(&this->mResultFiles, this->mFilename.mData, this->mRecursive, &this->mPatterns) > 0 )
        v3 = 3;
      break;
    case 21:
      if ( UFG::qGetDirectories(&this->mResultFiles, this->mFilename.mData, this->mRecursive, &this->mPatterns) > 0 )
        v3 = 3;
      break;
    case 22:
      v4 = UFG::qCreateDirectory(this->mFilename.mData);
LABEL_45:
      v8 = v4 == 0;
LABEL_46:
      if ( !v8 )
        v3 = 3;
      break;
    default:
      break;
  }
  v15 = UFG::qGetTicks();
  v16 = UFG::qGetTickTime(UFG::gQuarkFileSystem.mStartTicks, v15);
  result = v3;
  v2->mExecuteTime = (float)(v16 - v2->mStartTime) - v2->mQueuedTime;
  return result;
}

// File Line: 1210
// RVA: 0x161300
void __fastcall UFG::qFileOpList::qFileOpList(UFG::qFileOpList *this, const char *name)
{
  UFG::qFileOpList *v2; // rbx
  UFG::qList<UFG::qFileOp,UFG::qFileOp,1,0> *v3; // [rsp+60h] [rbp+18h]
  UFG::qList<UFG::qFileOp,UFG::qFileOp,1,0> *v4; // [rsp+60h] [rbp+18h]

  v2 = this;
  this->mPrev = (UFG::qNode<UFG::qFileOpList,UFG::qFileOpList> *)&this->mPrev;
  this->mNext = (UFG::qNode<UFG::qFileOpList,UFG::qFileOpList> *)&this->mPrev;
  UFG::qEvent::qEvent(&this->mEvent, "qFileOpList", 1);
  UFG::qMutex::qMutex(&v2->mMutex, &customWorldMapCaption);
  `eh vector constructor iterator'(
    v2->mQueuedOps,
    0x10ui64,
    3,
    (void (__fastcall *)(void *))UFG::qReflectHandleBase::qReflectHandleBase);
  v3 = &v2->mExecutingOps;
  v3->mNode.mPrev = &v3->mNode;
  v3->mNode.mNext = &v3->mNode;
  v4 = &v2->mDoneOps;
  v4->mNode.mPrev = &v4->mNode;
  v4->mNode.mNext = &v4->mNode;
  v2->mFileSystem = 0i64;
}

// File Line: 1215
// RVA: 0x163AB0
void __fastcall UFG::qFileOpList::~qFileOpList(UFG::qFileOpList *this)
{
  UFG::qFileOpList *v1; // rdi
  UFG::qList<UFG::qFileOp,UFG::qFileOp,1,0> *v2; // rbx
  UFG::qNode<UFG::qFileOp,UFG::qFileOp> *v3; // rcx
  UFG::qNode<UFG::qFileOp,UFG::qFileOp> *v4; // rax
  UFG::qNode<UFG::qFileOp,UFG::qFileOp> *v5; // rcx
  UFG::qNode<UFG::qFileOp,UFG::qFileOp> *v6; // rax
  UFG::qNode<UFG::qFileOpList,UFG::qFileOpList> *v7; // rcx
  UFG::qNode<UFG::qFileOpList,UFG::qFileOpList> *v8; // rax

  v1 = this;
  v2 = &this->mDoneOps;
  UFG::qList<UFG::qFileOp,UFG::qFileOp,1,0>::DeleteNodes(&this->mDoneOps);
  v3 = v2->mNode.mPrev;
  v4 = v2->mNode.mNext;
  v3->mNext = v4;
  v4->mPrev = v3;
  v2->mNode.mPrev = &v2->mNode;
  v2->mNode.mNext = &v2->mNode;
  UFG::qList<UFG::qFileOp,UFG::qFileOp,1,0>::DeleteNodes(&v1->mExecutingOps);
  v5 = v1->mExecutingOps.mNode.mPrev;
  v6 = v1->mExecutingOps.mNode.mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  v1->mExecutingOps.mNode.mPrev = &v1->mExecutingOps.mNode;
  v1->mExecutingOps.mNode.mNext = &v1->mExecutingOps.mNode;
  `eh vector destructor iterator'(
    v1->mQueuedOps,
    0x10ui64,
    3,
    (void (__fastcall *)(void *))UFG::qList<UFG::qFileOp,UFG::qFileOp,1,0>::~qList<UFG::qFileOp,UFG::qFileOp,1,0>);
  Scaleform::Lock::~Lock((LPCRITICAL_SECTION)&v1->mMutex);
  UFG::qEvent::~qEvent(&v1->mEvent);
  v7 = v1->mPrev;
  v8 = v1->mNext;
  v7->mNext = v8;
  v8->mPrev = v7;
  v1->mPrev = (UFG::qNode<UFG::qFileOpList,UFG::qFileOpList> *)&v1->mPrev;
  v1->mNext = (UFG::qNode<UFG::qFileOpList,UFG::qFileOpList> *)&v1->mPrev;
}

// File Line: 1219
// RVA: 0x1795F0
void __fastcall UFG::qFileOpList::Queue(UFG::qFileOpList *this, UFG::qFileOp *file_op, int priority)
{
  UFG::qFileOp *v3; // rsi
  __int64 v4; // r12
  UFG::qFileOpList *v5; // r14
  UFG::qFileOp *v6; // rbp
  UFG::qFile *v7; // rdi
  bool v8; // al
  UFG::qNode<UFG::qFileOp,UFG::qFileOp> *v9; // rcx
  UFG::qNode<UFG::qFileOp,UFG::qFileOp> *v10; // rax
  UFG::qFileSystem *v11; // rbx
  UFG::qNode<UFG::qFileOp,UFG::qFileOp> *v12; // rax

  v3 = file_op;
  v4 = priority;
  v5 = this;
  v6 = 0i64;
  UFG::qMutex::Lock((LPCRITICAL_SECTION)&this->mMutex);
  v7 = v3->mFile;
  v8 = v7 && v3->mType != 1 && v7->mCloseState;
  if ( v3->mDevice != 0i64 && v8 == 0 && v5->mFileSystem->mFatalIOError == 0 )
  {
    *(_DWORD *)v3->mStatus = 1;
    if ( v7 )
    {
      UFG::qMutex::Lock((LPCRITICAL_SECTION)&v7->mStateMutex);
      ++v7->mNumAsyncOps;
      UFG::qMutex::Unlock((LPCRITICAL_SECTION)&v7->mStateMutex);
    }
    v9 = (UFG::qNode<UFG::qFileOp,UFG::qFileOp> *)(&v5->mPrev + 2 * (v4 + 6));
    v10 = v9->mPrev;
    v10->mNext = (UFG::qNode<UFG::qFileOp,UFG::qFileOp> *)&v3->mPrev;
    v3->mNext = v9;
    v3->mPrev = v10;
    v9->mPrev = (UFG::qNode<UFG::qFileOp,UFG::qFileOp> *)&v3->mPrev;
    UFG::qEvent::Signal(&v5->mEvent);
  }
  else
  {
    *(_DWORD *)v3->mStatus = 5;
    v6 = v3;
  }
  UFG::qMutex::Unlock((LPCRITICAL_SECTION)&v5->mMutex);
  if ( v6 )
  {
    v11 = v5->mFileSystem;
    UFG::qMutex::Lock((LPCRITICAL_SECTION)&v11->mMutex);
    v12 = v11->mDoneFileOps.mNode.mPrev;
    v12->mNext = (UFG::qNode<UFG::qFileOp,UFG::qFileOp> *)&v3->mPrev;
    v3->mPrev = v12;
    v3->mNext = &v11->mDoneFileOps.mNode;
    v11->mDoneFileOps.mNode.mPrev = (UFG::qNode<UFG::qFileOp,UFG::qFileOp> *)&v3->mPrev;
    UFG::qMutex::Unlock((LPCRITICAL_SECTION)&v11->mMutex);
  }
}

// File Line: 1278
// RVA: 0x169A70
UFG::qFileOp *__fastcall UFG::qFileOpList::Completed(UFG::qFileOpList *this, UFG::qFileOp *file_op)
{
  UFG::qFile *v2; // rbx
  UFG::qFileOp *v3; // rdi
  UFG::qFileOp *v4; // rsi
  UFG::qFileOpList *v5; // r14
  bool v6; // zf
  UFG::qNode<UFG::qFileOp,UFG::qFileOp> *v7; // rdx

  v2 = file_op->mFile;
  v3 = 0i64;
  v4 = file_op;
  v5 = this;
  if ( v2 )
  {
    UFG::qMutex::Lock((LPCRITICAL_SECTION)&v2->mStateMutex);
    v6 = v2->mNumAsyncOps-- == 1;
    if ( v6 && v2->mAsyncCloseOp )
      v3 = v2->mAsyncCloseOp;
    UFG::qMutex::Unlock((LPCRITICAL_SECTION)&v2->mStateMutex);
  }
  UFG::qMutex::Lock((LPCRITICAL_SECTION)&v5->mMutex);
  v7 = v5->mDoneOps.mNode.mPrev;
  v7->mNext = (UFG::qNode<UFG::qFileOp,UFG::qFileOp> *)&v4->mPrev;
  v4->mPrev = v7;
  v4->mNext = &v5->mDoneOps.mNode;
  v5->mDoneOps.mNode.mPrev = (UFG::qNode<UFG::qFileOp,UFG::qFileOp> *)&v4->mPrev;
  UFG::qMutex::Unlock((LPCRITICAL_SECTION)&v5->mMutex);
  return v3;
}

// File Line: 1327
// RVA: 0x160EE0
void __fastcall UFG::qFileIoThread::qFileIoThread(UFG::qFileIoThread *this, const char *name)
{
  const char *v2; // rbx
  UFG::qFileIoThread *v3; // rdi

  v2 = name;
  v3 = this;
  UFG::qThread::qThread(&this->mThread, name);
  v3->mName = v2;
  v3->mDevice = 0i64;
  v3->mFileOpList = 0i64;
}

// File Line: 1335
// RVA: 0x163930
void __fastcall UFG::qFileIoThread::~qFileIoThread(UFG::qFileIoThread *this)
{
  _((AMD_HD3D *)&this->mThread);
}

// File Line: 1339
// RVA: 0x17DEB0
void __fastcall UFG::qFileIoThread::Start(UFG::qFileIoThread *this, UFG::qFileDevice *device, UFG::qFileOpList *file_op_list, int thread_stack_size, int thread_priority, int thread_logical_core_id)
{
  UFG::qFileIoThread *v6; // rdi
  UFG::qBaseNodeRB *v7; // rcx

  v6 = this;
  v7 = (UFG::qBaseNodeRB *)&this->mThread;
  file_op_list->mFileSystem = device->mFileSystem;
  v7[2].mChild[1] = (UFG::qBaseNodeRB *)device;
  *(_QWORD *)&v7[2].mUID = file_op_list;
  LOBYTE(v7[3].mParent) = 0;
  UFG::qBaseNodeRB::SetUID(v7, thread_stack_size);
  UFG::qThread::SetThreadPriority(&v6->mThread, thread_priority);
  UFG::qThread::SetLogicalCoreID(&v6->mThread, thread_logical_core_id);
  UFG::qThread::Start(&v6->mThread, UFG::qFileIoThread::ThreadFuncBridge, v6);
}

// File Line: 1357
// RVA: 0x17DFA0
void __fastcall UFG::qFileIoThread::Stop(UFG::qFileIoThread *this)
{
  UFG::qFileIoThread *v1; // rbx

  v1 = this;
  this->mStopRequested = 1;
  UFG::qEvent::Signal(&this->mFileOpList->mEvent);
  UFG::qThread::WaitForCompletion(&v1->mThread);
}

// File Line: 1368
// RVA: 0x17E5D0
void __fastcall UFG::qFileIoThread::ThreadFuncBridge(void *param)
{
  UFG::qFileIoThread::ThreadFunc((UFG::qFileIoThread *)param);
}

// File Line: 1373
// RVA: 0x17E350
void __fastcall UFG::qFileIoThread::ThreadFunc(UFG::qFileIoThread *this)
{
  UFG::qFileOpList *v1; // r13
  UFG::qFileSystem *v2; // r12
  UFG::qFileIoThread *v3; // r14
  UFG::qEvent *v4; // r15
  _RTL_CRITICAL_SECTION *v5; // rsi
  UFG::qNode<UFG::qFileOp,UFG::qFileOp> **v6; // rdi
  bool v7; // bl
  signed __int64 v8; // rbp
  signed __int64 v9; // r8
  signed __int64 v10; // rdx
  __int64 *v11; // rax
  __int64 v12; // rcx
  _QWORD *v13; // rax
  unsigned __int64 v14; // rax
  UFG::qNode<UFG::qFileOp,UFG::qFileOp> *v15; // rax
  signed __int64 v16; // rcx
  signed __int64 v17; // rax
  int v18; // ebx
  UFG::qNode<UFG::qFileOp,UFG::qFileOp> *v19; // rdx
  UFG::qNode<UFG::qFileOp,UFG::qFileOp> *v20; // rcx
  UFG::qFileOp *v21; // rax
  UFG::qNode<UFG::qFileOp,UFG::qFileOp> *v22; // r14
  signed __int64 v23; // r15
  __int64 *v24; // rbx
  __int64 *v25; // rsi
  unsigned __int64 v26; // rax
  float v27; // xmm0_4
  __int64 v28; // rcx
  _QWORD *v29; // rax
  UFG::qFileIoThread *v30; // [rsp+50h] [rbp+8h]

  v30 = this;
  v1 = this->mFileOpList;
  v2 = this->mDevice->mFileSystem;
  v3 = this;
  if ( !this->mStopRequested )
  {
    v4 = &v1->mEvent;
    do
    {
      UFG::qEvent::Wait(v4);
      if ( v3->mStopRequested )
        break;
      v5 = (_RTL_CRITICAL_SECTION *)&v1->mMutex;
      v6 = 0i64;
      v7 = 0;
      UFG::qMutex::Lock((LPCRITICAL_SECTION)&v1->mMutex);
      v8 = (signed __int64)v1->mQueuedOps;
      v9 = 0i64;
      v10 = (signed __int64)v1->mQueuedOps;
      while ( v9 < 3 )
      {
        v11 = *(__int64 **)(v10 + 8);
        if ( v11 != (__int64 *)v10 )
        {
          v12 = *v11;
          v6 = *(UFG::qNode<UFG::qFileOp,UFG::qFileOp> ***)(v10 + 8);
          v13 = (_QWORD *)v11[1];
          *(_QWORD *)(v12 + 8) = v13;
          *v13 = v12;
          *v6 = (UFG::qNode<UFG::qFileOp,UFG::qFileOp> *)v6;
          v6[1] = (UFG::qNode<UFG::qFileOp,UFG::qFileOp> *)v6;
        }
        ++v9;
        v10 += 16i64;
        if ( v6 )
          goto LABEL_11;
      }
      if ( !v6 )
        goto LABEL_12;
LABEL_11:
      *((_DWORD *)v6 + 7) = 2;
      v14 = UFG::qGetTicks();
      *((float *)v6 + 25) = UFG::qGetTickTime(v2->mStartTicks, v14) - *((float *)v6 + 24);
      v15 = v1->mExecutingOps.mNode.mPrev;
      v15->mNext = (UFG::qNode<UFG::qFileOp,UFG::qFileOp> *)v6;
      *v6 = v15;
      v6[1] = &v1->mExecutingOps.mNode;
      v1->mExecutingOps.mNode.mPrev = (UFG::qNode<UFG::qFileOp,UFG::qFileOp> *)v6;
LABEL_12:
      v16 = 0i64;
      v17 = (signed __int64)v1->mQueuedOps;
      do
      {
        if ( v16 >= 3 )
          break;
        v7 = *(_QWORD *)(v17 + 8) != v17;
        ++v16;
        v17 += 16i64;
      }
      while ( !v7 );
      UFG::qMutex::Unlock((LPCRITICAL_SECTION)&v1->mMutex);
      if ( v7 )
        UFG::qEvent::Signal(v4);
      if ( v6 )
      {
        v18 = UFG::qFileOp::Execute((UFG::qFileOp *)v6);
        UFG::qMutex::Lock((LPCRITICAL_SECTION)&v1->mMutex);
        v19 = *v6;
        v20 = v6[1];
        v19->mNext = v20;
        v20->mPrev = v19;
        *v6 = (UFG::qNode<UFG::qFileOp,UFG::qFileOp> *)v6;
        v6[1] = (UFG::qNode<UFG::qFileOp,UFG::qFileOp> *)v6;
        v21 = UFG::qFileOpList::Completed(v1, (UFG::qFileOp *)v6);
        if ( *((_DWORD *)v6 + 7) == 2 )
          *((_DWORD *)v6 + 7) = v18;
        if ( !*((_DWORD *)v6 + 6) && *((_DWORD *)v6 + 7) != 3 )
        {
          v22 = v6[9];
          v23 = 3i64;
          do
          {
            v24 = *(__int64 **)(v8 + 8);
            if ( v24 != (__int64 *)v8 )
            {
              do
              {
                v25 = (__int64 *)v24[1];
                if ( (UFG::qNode<UFG::qFileOp,UFG::qFileOp> *)v24[9] == v22 && *((_DWORD *)v24 + 6) != 1 )
                {
                  v26 = UFG::qGetTicks();
                  v27 = UFG::qGetTickTime(v2->mStartTicks, v26);
                  v28 = *v24;
                  v29 = (_QWORD *)v24[1];
                  *((_DWORD *)v24 + 7) = 5;
                  *((float *)v24 + 25) = v27 - *((float *)v6 + 24);
                  *((float *)v24 + 26) = (float)(v27 - *((float *)v6 + 24)) - *((float *)v6 + 25);
                  *(_QWORD *)(v28 + 8) = v29;
                  *v29 = v28;
                  *v24 = (__int64)v24;
                  v24[1] = (__int64)v24;
                  v21 = UFG::qFileOpList::Completed(v1, (UFG::qFileOp *)v24);
                }
                v24 = v25;
              }
              while ( v25 != (__int64 *)v8 );
            }
            v8 += 16i64;
            --v23;
          }
          while ( v23 );
          v3 = v30;
          v5 = (_RTL_CRITICAL_SECTION *)&v1->mMutex;
          v4 = &v1->mEvent;
        }
        if ( v21 )
          UFG::qFileOpList::Queue(v1, v21, 0);
        UFG::qMutex::Unlock(v5);
      }
    }
    while ( !v3->mStopRequested );
  }
}

// File Line: 1522
// RVA: 0x160DF0
void __fastcall UFG::qFileDevice::qFileDevice(UFG::qFileDevice *this, const char *name, int supported_access_modes, int max_open_files, UFG::qFileDevice::Casing casing)
{
  int v5; // esi
  int v6; // ebp
  const char *v7; // rdi
  UFG::qFileDevice *v8; // rbx
  UFG::qNode<UFG::qFileDevice,UFG::qFileDevice> *v9; // rax
  unsigned int v10; // edx
  char i; // al
  UFG::qList<UFG::qFileOpList,UFG::qFileOpList,1,0> *v12; // [rsp+58h] [rbp+10h]
  UFG::qList<UFG::qFile,UFG::qFile,1,0> *v13; // [rsp+58h] [rbp+10h]
  UFG::qList<UFG::qFile,UFG::qFile,1,0> *v14; // [rsp+58h] [rbp+10h]

  v5 = max_open_files;
  v6 = supported_access_modes;
  v7 = name;
  v8 = this;
  v9 = (UFG::qNode<UFG::qFileDevice,UFG::qFileDevice> *)&this->mPrev;
  v9->mPrev = v9;
  v9->mNext = v9;
  this->vfptr = (UFG::qFileDeviceVtbl *)&UFG::qFileDevice::`vftable';
  v12 = &this->mFileOpLists;
  v12->mNode.mPrev = &v12->mNode;
  v12->mNode.mNext = &v12->mNode;
  UFG::qMutex::qMutex(&this->mMutex, &customWorldMapCaption);
  v13 = &v8->mOpenFiles;
  v13->mNode.mPrev = &v13->mNode;
  v13->mNode.mNext = &v13->mNode;
  v14 = &v8->mClosedFiles;
  v14->mNode.mPrev = &v14->mNode;
  v14->mNode.mNext = &v14->mNode;
  v8->mFileSystem = 0i64;
  v8->mName = v7;
  v10 = -1;
  if ( v7 )
  {
    for ( i = *v7; *v7; i = *v7 )
    {
      v10 = (v10 << 8) ^ sCrcTable32[(unsigned __int8)(i ^ HIBYTE(v10))];
      ++v7;
    }
  }
  v8->mNameHash = v10;
  v8->mSupportedAccessModes = v6;
  v8->mMaxOpenFiles = v5;
  v8->mCaseSensitive = casing;
}

// File Line: 1534
// RVA: 0x163860
void __fastcall UFG::qFileDevice::~qFileDevice(UFG::qFileDevice *this)
{
  UFG::qFileDevice *v1; // rdi
  UFG::qList<UFG::qFile,UFG::qFile,1,0> *v2; // rbx
  UFG::qNode<UFG::qFile,UFG::qFile> *v3; // rcx
  UFG::qNode<UFG::qFile,UFG::qFile> *v4; // rax
  UFG::qNode<UFG::qFile,UFG::qFile> *v5; // rcx
  UFG::qNode<UFG::qFile,UFG::qFile> *v6; // rax
  UFG::qNode<UFG::qFileOpList,UFG::qFileOpList> *v7; // rcx
  UFG::qNode<UFG::qFileOpList,UFG::qFileOpList> *v8; // rax
  UFG::qNode<UFG::qFileDevice,UFG::qFileDevice> *v9; // rdx
  UFG::qNode<UFG::qFileDevice,UFG::qFileDevice> *v10; // rcx
  UFG::qNode<UFG::qFileDevice,UFG::qFileDevice> *v11; // rax

  v1 = this;
  this->vfptr = (UFG::qFileDeviceVtbl *)&UFG::qFileDevice::`vftable';
  v2 = &this->mClosedFiles;
  UFG::qList<UFG::qFile,UFG::qFile,1,0>::DeleteNodes(&this->mClosedFiles);
  v3 = v2->mNode.mPrev;
  v4 = v2->mNode.mNext;
  v3->mNext = v4;
  v4->mPrev = v3;
  v2->mNode.mPrev = &v2->mNode;
  v2->mNode.mNext = &v2->mNode;
  UFG::qList<UFG::qFile,UFG::qFile,1,0>::DeleteNodes(&v1->mOpenFiles);
  v5 = v1->mOpenFiles.mNode.mPrev;
  v6 = v1->mOpenFiles.mNode.mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  v1->mOpenFiles.mNode.mPrev = &v1->mOpenFiles.mNode;
  v1->mOpenFiles.mNode.mNext = &v1->mOpenFiles.mNode;
  Scaleform::Lock::~Lock((LPCRITICAL_SECTION)&v1->mMutex);
  UFG::qList<UFG::qFileOpList,UFG::qFileOpList,1,0>::DeleteNodes(&v1->mFileOpLists);
  v7 = v1->mFileOpLists.mNode.mPrev;
  v8 = v1->mFileOpLists.mNode.mNext;
  v7->mNext = v8;
  v8->mPrev = v7;
  v1->mFileOpLists.mNode.mPrev = &v1->mFileOpLists.mNode;
  v1->mFileOpLists.mNode.mNext = &v1->mFileOpLists.mNode;
  v9 = (UFG::qNode<UFG::qFileDevice,UFG::qFileDevice> *)&v1->mPrev;
  v10 = v1->mPrev;
  v11 = v1->mNext;
  v10->mNext = v11;
  v11->mPrev = v10;
  v9->mPrev = v9;
  v9->mNext = v9;
}

// File Line: 1547
// RVA: 0x1613A0
void __fastcall UFG::qFileSystem::qFileSystem(UFG::qFileSystem *this)
{
  UFG::qFileSystem *v1; // rdi
  _QWORD *v2; // rcx
  UFG::qList<UFG::qFileDevice,UFG::qFileDevice,1,0> *v3; // [rsp+48h] [rbp+10h]
  UFG::qList<UFG::qFileMappingCallback,UFG::qFileMappingCallback,1,0> *v4; // [rsp+48h] [rbp+10h]
  signed __int64 v5; // [rsp+48h] [rbp+10h]
  UFG::qList<UFG::qFileOp,UFG::qFileOp,1,0> *v6; // [rsp+48h] [rbp+10h]

  v1 = this;
  v3 = &this->mDevices;
  v3->mNode.mPrev = &v3->mNode;
  v3->mNode.mNext = &v3->mNode;
  UFG::qMutex::qMutex(&this->mMappingMutex, &customWorldMapCaption);
  v4 = &v1->mMappingCallbacks;
  v4->mNode.mPrev = &v4->mNode;
  v4->mNode.mNext = &v4->mNode;
  v5 = (signed __int64)&v1->mMappingLocations;
  *(_OWORD *)v5 = 0ui64;
  *(_QWORD *)(v5 + 16) = 0i64;
  v2 = &v1->mMappingLocations.mTree.mNULL.mParent;
  *v2 = 0i64;
  v2[1] = 0i64;
  v2[2] = 0i64;
  *v2 = (unsigned __int64)&v1->mMappingLocations.mTree.mNULL | (_QWORD)v1->mMappingLocations.mTree.mNULL.mParent & 1;
  *(_QWORD *)(v5 + 40) = (char *)v1 + 128;
  *(_QWORD *)(v5 + 48) = (char *)v1 + 128;
  *v2 &= 0xFFFFFFFFFFFFFFFEui64;
  *(_DWORD *)(v5 + 56) = 0;
  *(_QWORD *)v5 = (unsigned __int64)&v1->mMappingLocations.mTree.mNULL | (_QWORD)v1->mMappingLocations.mTree.mRoot.mParent & 1;
  *(_QWORD *)(v5 + 8) = (char *)v1 + 128;
  *(_QWORD *)(v5 + 16) = (char *)v1 + 128;
  *(_QWORD *)v5 &= 0xFFFFFFFFFFFFFFFEui64;
  *(_DWORD *)(v5 + 24) = -1;
  *(_DWORD *)(v5 + 64) = 0;
  UFG::qMutex::qMutex(&v1->mMutex, &customWorldMapCaption);
  UFG::qEvent::qEvent(&v1->mEvent);
  v6 = &v1->mDoneFileOps;
  v6->mNode.mPrev = &v6->mNode;
  v6->mNode.mNext = &v6->mNode;
  *(_WORD *)&v1->mReportSyncFileOps = 0;
  v1->mFatalIOError = 0;
  v1->mMapFilenameToDeviceCallback = 0i64;
  UFG::qEvent::Create(&v1->mEvent, "qFileSystem", 0);
}

// File Line: 1563
// RVA: 0x163B70
UFG::qFileSystem::~qFileSystem

// File Line: 1613
// RVA: 0x173940
void __fastcall UFG::qFileSystem::InitDevice(UFG::qFileSystem *this, UFG::qFileDevice *device)
{
  UFG::qNode<UFG::qFileDevice,UFG::qFileDevice> *v2; // rax
  UFG::qNode<UFG::qFileDevice,UFG::qFileDevice> *v3; // r8
  UFG::qFileDeviceVtbl *v4; // rax

  v2 = this->mDevices.mNode.mPrev;
  v3 = (UFG::qNode<UFG::qFileDevice,UFG::qFileDevice> *)&device->mPrev;
  v2->mNext = (UFG::qNode<UFG::qFileDevice,UFG::qFileDevice> *)&device->mPrev;
  v3->mPrev = v2;
  v3->mNext = &this->mDevices.mNode;
  this->mDevices.mNode.mPrev = (UFG::qNode<UFG::qFileDevice,UFG::qFileDevice> *)&device->mPrev;
  v4 = device->vfptr;
  device->mFileSystem = this;
  (*(void (__fastcall **)(UFG::qFileDevice *))v4->gap8)(device);
}

// File Line: 1624
// RVA: 0x168400
void __fastcall UFG::qFileSystem::CloseDevice(UFG::qFileSystem *this, UFG::qFileDevice *device)
{
  UFG::qFileDevice *v2; // rbx
  UFG::qNode<UFG::qFileDevice,UFG::qFileDevice> *v3; // rcx
  UFG::qNode<UFG::qFileDevice,UFG::qFileDevice> *v4; // rax
  UFG::qNode<UFG::qFileDevice,UFG::qFileDevice> *v5; // rdx

  v2 = device;
  if ( device->mFileSystem )
  {
    (*(void (__fastcall **)(UFG::qFileDevice *))&device->vfptr->gap8[8])(device);
    v2->mFileSystem = 0i64;
    v3 = v2->mPrev;
    v4 = v2->mNext;
    v5 = (UFG::qNode<UFG::qFileDevice,UFG::qFileDevice> *)&v2->mPrev;
    v3->mNext = v4;
    v4->mPrev = v3;
    v5->mPrev = v5;
    v5->mNext = v5;
  }
}

// File Line: 1715
// RVA: 0x170560
UFG::qString *__fastcall UFG::qFileSystem::GetFileMapping(UFG::qFileSystem *this, UFG::qString *result, UFG::qFileMapType file_map_type, const char *mapping_name)
{
  const char *v4; // rdi
  __int64 v5; // rsi
  UFG::qString *v6; // rbx
  UFG::qFileSystem *v7; // r14
  unsigned int v8; // eax
  UFG::qSharedStringData *v9; // rax
  UFG::qNode<UFG::qString,UFG::qString> *v10; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *v11; // rax
  UFG::qString v13; // [rsp+40h] [rbp-30h]

  v4 = mapping_name;
  v5 = file_map_type;
  v6 = result;
  v7 = this;
  v13.mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&v13;
  v13.mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&v13;
  *(_QWORD *)&v13.mMagic = 16909060i64;
  v13.mData = (char *)UFG::qString::sEmptyString;
  *(_QWORD *)&v13.mStringHash32 = -1i64;
  if ( mapping_name && *mapping_name && (unsigned int)v5 <= 1 )
  {
    UFG::qMutex::Lock((LPCRITICAL_SECTION)&this->mMappingMutex);
    v8 = UFG::qStringHashUpper32(v4, 0xFFFFFFFF);
    v9 = UFG::qTreeRB<UFG::qFileMapLocation,UFG::qFileMapLocation,1>::Get(
           (UFG::qTreeRB<UFG::qSharedStringData,UFG::qSharedStringData,0> *)&v7->mMappingLocations,
           v8);
    if ( v9 )
      UFG::qString::Set(
        &v13,
        *((const char **)&v9->mNode.mUID + 5 * (v5 + 1)),
        HIDWORD(v9->mNode.mChild[5 * (v5 + 1) + 1]),
        0i64,
        0);
    UFG::qMutex::Unlock((LPCRITICAL_SECTION)&v7->mMappingMutex);
    v6->mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&v6->mPrev;
    v6->mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&v6->mPrev;
    v6->mMagic = 16909060;
    v6->mData = (char *)UFG::qString::sEmptyString;
    v6->mLength = 0;
    UFG::qString::Set(v6, v13.mData, v13.mLength, 0i64, 0);
    v6->mStringHash32 = v13.mStringHash32;
    v6->mStringHashUpper32 = v13.mStringHashUpper32;
    if ( v13.mData != UFG::qString::sEmptyString && v13.mData )
      UFG::qMemoryPool::Free(UFG::gMainMemoryPool, v13.mData);
    v13.mMagic = 0;
  }
  else
  {
    result->mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&result->mPrev;
    result->mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&result->mPrev;
    result->mMagic = 16909060;
    result->mData = (char *)UFG::qString::sEmptyString;
    result->mLength = 0;
    UFG::qString::Set(result, v13.mData, v13.mLength, 0i64, 0);
    v6->mStringHash32 = v13.mStringHash32;
    v6->mStringHashUpper32 = v13.mStringHashUpper32;
    if ( v13.mData != UFG::qString::sEmptyString && v13.mData )
      UFG::qMemoryPool::Free(UFG::gMainMemoryPool, v13.mData);
    v13.mMagic = 0;
  }
  v10 = v13.mPrev;
  v11 = v13.mNext;
  v13.mPrev->mNext = v13.mNext;
  v11->mPrev = v10;
  return v6;
}

// File Line: 1740
// RVA: 0x177680
UFG::qString *__fastcall UFG::qFileSystem::MapFilename(UFG::qFileSystem *this, UFG::qString *result, UFG::qFileMapType file_map_type, const char *filename)
{
  const char *v4; // rsi
  UFG::qFileMapType v5; // er15
  UFG::qString *v6; // rdi
  UFG::qFileSystem *v7; // r14
  _RTL_CRITICAL_SECTION *v8; // r13
  char *v9; // rbx
  const char *v10; // r9
  int v11; // eax
  char *v12; // rcx
  char v13; // al
  UFG::qNode<UFG::qString,UFG::qString> *v14; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *v15; // rax
  UFG::qNode<UFG::qString,UFG::qString> *v16; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *v17; // rax
  UFG::qNode<UFG::qFileMappingCallback,UFG::qFileMappingCallback> *v18; // rbx
  signed __int64 i; // r14
  UFG::qNode<UFG::qString,UFG::qString> *v20; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *v21; // rax
  UFG::qString v23; // [rsp+10h] [rbp-51h]
  UFG::qString v24; // [rsp+38h] [rbp-29h]
  UFG::qString resulta; // [rsp+60h] [rbp-1h]
  __int64 v26; // [rsp+88h] [rbp+27h]

  v26 = -2i64;
  v4 = filename;
  v5 = file_map_type;
  v6 = result;
  v7 = this;
  UFG::qString::qString(&v24, filename);
  if ( v4 && *v4 )
  {
    v8 = (_RTL_CRITICAL_SECTION *)&v7->mMappingMutex;
    UFG::qMutex::Lock((LPCRITICAL_SECTION)&v7->mMappingMutex);
    if ( *v4 == 36 && v4[1] == 40 )
    {
      v9 = UFG::qStringFind(v4 + 2, ")");
      if ( v9 )
      {
        v24.mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&v24;
        v24.mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&v24;
        *(_QWORD *)&v24.mMagic = 16909060i64;
        v24.mData = (char *)UFG::qString::sEmptyString;
        *(_QWORD *)&v24.mStringHash32 = -1i64;
        UFG::qString::Set(&v24, v4 + 2, (_DWORD)v9 - (_DWORD)v4 - 2, 0i64, 0);
        UFG::qFileSystem::GetFileMapping(v7, &resulta, v5, v24.mData);
        v10 = v9 + 1;
        if ( v9 == (char *)-1i64 )
        {
          v11 = 0;
        }
        else
        {
          v12 = v9 + 1;
          do
            v13 = *v12++;
          while ( v13 );
          v11 = (_DWORD)v12 - (_DWORD)v10 - 1;
        }
        UFG::qString::Set(&v23, resulta.mData, resulta.mLength, v10, v11);
        if ( resulta.mData != UFG::qString::sEmptyString && resulta.mData )
          UFG::qMemoryPool::Free(UFG::gMainMemoryPool, resulta.mData);
        resulta.mMagic = 0;
        v14 = resulta.mPrev;
        v15 = resulta.mNext;
        resulta.mPrev->mNext = resulta.mNext;
        v15->mPrev = v14;
        resulta.mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&resulta;
        resulta.mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&resulta;
        if ( v24.mData != UFG::qString::sEmptyString && v24.mData )
          UFG::qMemoryPool::Free(UFG::gMainMemoryPool, v24.mData);
        v24.mMagic = 0;
        v16 = v24.mPrev;
        v17 = v24.mNext;
        v24.mPrev->mNext = v24.mNext;
        v17->mPrev = v16;
        v24.mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&v24;
        v24.mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&v24;
      }
      else
      {
        UFG::qPrintf(
          "ERROR: 'filename' has an incorrect File Mapping location!\n"
          " filename = %s\n"
          " Message  = If a filename starts with '$(' it must have a trailing ')'\n"
          "            i.e. '$(InstallDir)\blah.bin\n",
          v4);
      }
    }
    v18 = v7->mMappingCallbacks.mNode.mNext;
    for ( i = (signed __int64)&v7->mMappingCallbacks;
          v18 != (UFG::qNode<UFG::qFileMappingCallback,UFG::qFileMappingCallback> *)i;
          v18 = v18->mNext )
    {
      ((void (__fastcall *)(_QWORD, const char *, UFG::qString *, UFG::qNode<UFG::qFileMappingCallback,UFG::qFileMappingCallback> *))v18[1].mPrev)(
        (unsigned int)v5,
        v4,
        &v23,
        v18[1].mNext);
    }
    UFG::qMutex::Unlock(v8);
    v6->mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&v6->mPrev;
    v6->mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&v6->mPrev;
    v6->mMagic = 16909060;
    v6->mData = (char *)UFG::qString::sEmptyString;
    v6->mLength = 0;
    UFG::qString::Set(v6, v23.mData, v23.mLength, 0i64, 0);
    v6->mStringHash32 = v23.mStringHash32;
    v6->mStringHashUpper32 = v23.mStringHashUpper32;
    if ( v23.mData != UFG::qString::sEmptyString && v23.mData )
      UFG::qMemoryPool::Free(UFG::gMainMemoryPool, v23.mData);
    v23.mMagic = 0;
  }
  else
  {
    v6->mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&v6->mPrev;
    v6->mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&v6->mPrev;
    v6->mMagic = 16909060;
    v6->mData = (char *)UFG::qString::sEmptyString;
    v6->mLength = 0;
    UFG::qString::Set(v6, v23.mData, v23.mLength, 0i64, 0);
    v6->mStringHash32 = v23.mStringHash32;
    v6->mStringHashUpper32 = v23.mStringHashUpper32;
    if ( v23.mData != UFG::qString::sEmptyString && v23.mData )
      UFG::qMemoryPool::Free(UFG::gMainMemoryPool, v23.mData);
    v23.mMagic = 0;
  }
  v20 = v23.mPrev;
  v21 = v23.mNext;
  v23.mPrev->mNext = v23.mNext;
  v21->mPrev = v20;
  return v6;
}

// File Line: 1793
// RVA: 0x1779A0
UFG::qFileDevice *__fastcall UFG::qFileSystem::MapFilenameToDevice(UFG::qFileSystem *this, const char *filename)
{
  const char *v2; // rbx
  UFG::qFileSystem *v3; // rdi
  UFG::qFileDevice *(__fastcall *v4)(const char *); // rax
  UFG::qFileDevice *v5; // rbx
  UFG::qNode<UFG::qString,UFG::qString> *v6; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *v7; // rax
  UFG::qString result; // [rsp+28h] [rbp-30h]

  v2 = filename;
  v3 = this;
  UFG::qFileSystem::MapFilename(this, &result, 0, filename);
  v4 = v3->mMapFilenameToDeviceCallback;
  if ( !v4 || (v5 = v4(v2)) == 0i64 )
    v5 = UFG::qFileSystem::MapFilenameToDevicePlat(v3, result.mData);
  if ( result.mData != UFG::qString::sEmptyString && result.mData )
    UFG::qMemoryPool::Free(UFG::gMainMemoryPool, result.mData);
  v6 = result.mPrev;
  v7 = result.mNext;
  result.mPrev->mNext = result.mNext;
  v7->mPrev = v6;
  return v5;
}

// File Line: 1823
// RVA: 0x179740
void __fastcall UFG::qFileSystem::QueueAsyncOp(UFG::qFileSystem *this, UFG::qFileOp *file_op, __int64 priority)
{
  UFG::qFileSystem *v3; // rsi
  UFG::qFileDevice *v4; // rcx
  UFG::qFileOp *v5; // rdi
  UFG::qNode<UFG::qFileOp,UFG::qFileOp> *v6; // rax

  v3 = this;
  v4 = file_op->mDevice;
  v5 = file_op;
  if ( v4 )
  {
    (*(void (__fastcall **)(UFG::qFileDevice *, UFG::qFileOp *, __int64))&v4->vfptr->gap8[16])(v4, file_op, priority);
  }
  else
  {
    *(_DWORD *)file_op->mStatus = 5;
    UFG::qMutex::Lock((LPCRITICAL_SECTION)&v3->mMutex);
    v6 = v3->mDoneFileOps.mNode.mPrev;
    v6->mNext = (UFG::qNode<UFG::qFileOp,UFG::qFileOp> *)&v5->mPrev;
    v5->mPrev = v6;
    v5->mNext = &v3->mDoneFileOps.mNode;
    v3->mDoneFileOps.mNode.mPrev = (UFG::qNode<UFG::qFileOp,UFG::qFileOp> *)&v5->mPrev;
    UFG::qMutex::Unlock((LPCRITICAL_SECTION)&v3->mMutex);
  }
}

// File Line: 2020
// RVA: 0x17BF70
void __fastcall UFG::qFileSystem::Service(UFG::qFileSystem *this)
{
  UFG::qFileSystem *v1; // r12
  UFG::qList<UFG::qFileOp,UFG::qFileOp,1,0> *v2; // rdx
  UFG::qList<UFG::qFileOp,UFG::qFileOp,1,0> *v3; // r8
  __int64 *v4; // rax
  __int64 *v5; // rcx
  signed __int64 i; // rsi
  __int64 j; // rbx
  __int64 **v8; // r8
  __int64 **v9; // r9
  __int64 *v10; // rax
  __int64 *v11; // rdx
  UFG::qFileOp *k; // rbx
  UFG::qNode<UFG::qFileOp,UFG::qFileOp> *v13; // rcx
  UFG::qNode<UFG::qFileOp,UFG::qFileOp> *v14; // rax
  UFG::qFile *v15; // rdi
  unsigned __int64 v16; // rax
  void (__fastcall *v17)(UFG::qFileOp *, void *); // rax
  UFG::qNode<UFG::qFile,UFG::qFile> *v18; // rcx
  UFG::qNode<UFG::qFile,UFG::qFile> *v19; // rax
  UFG::qFileOp *l; // rbx
  UFG::qNode<UFG::qFileOp,UFG::qFileOp> *v21; // rcx
  UFG::qNode<UFG::qFileOp,UFG::qFileOp> *v22; // rax
  __int64 *v23; // rcx
  UFG::qFileOp *v24; // rax
  __int64 *v25; // [rsp+28h] [rbp-18h]
  UFG::qFileOp *v26; // [rsp+30h] [rbp-10h]

  v1 = this;
  v25 = (__int64 *)&v25;
  v26 = (UFG::qFileOp *)&v25;
  UFG::qMutex::Lock((LPCRITICAL_SECTION)&this->mMutex);
  v2 = &v1->mDoneFileOps;
  v3 = (UFG::qList<UFG::qFileOp,UFG::qFileOp,1,0> *)v1->mDoneFileOps.mNode.mNext;
  if ( v3 != &v1->mDoneFileOps )
  {
    v4 = v25;
    v5 = (__int64 *)v2->mNode.mPrev;
    v25[1] = (__int64)v3;
    v3->mNode.mPrev = (UFG::qNode<UFG::qFileOp,UFG::qFileOp> *)v4;
    v5[1] = (__int64)&v25;
    v25 = v5;
    v2->mNode.mPrev = &v2->mNode;
    v1->mDoneFileOps.mNode.mNext = &v1->mDoneFileOps.mNode;
  }
  for ( i = (signed __int64)&v1->mDevices.mNode.mNext[-1].mNext;
        (bool *)i != &v1->mReportSyncFileOps;
        i = *(_QWORD *)(i + 16) - 8i64 )
  {
    for ( j = *(_QWORD *)(i + 64); j != i + 56; j = *(_QWORD *)(j + 8) )
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
  UFG::qMutex::Unlock((LPCRITICAL_SECTION)&v1->mMutex);
  for ( k = v26; v26 != (UFG::qFileOp *)&v25; k = v26 )
  {
    v13 = k->mPrev;
    v14 = k->mNext;
    v13->mNext = v14;
    v14->mPrev = v13;
    k->mPrev = (UFG::qNode<UFG::qFileOp,UFG::qFileOp> *)&k->mPrev;
    k->mNext = (UFG::qNode<UFG::qFileOp,UFG::qFileOp> *)&k->mPrev;
    v15 = k->mFile;
    v16 = UFG::qGetTicks();
    k->mDoneTime = (float)((float)(UFG::qGetTickTime(v1->mStartTicks, v16) - k->mStartTime) - k->mQueuedTime)
                 - k->mExecuteTime;
    v17 = k->mCallback;
    if ( v17 )
      v17(k, k->mCallbackParam);
    if ( k->mType == 1 && v15 )
    {
      Scaleform::Lock::~Lock((LPCRITICAL_SECTION)&v15->mStateMutex);
      Scaleform::Lock::~Lock((LPCRITICAL_SECTION)&v15->mFileHandleMutex);
      v18 = v15->mPrev;
      v19 = v15->mNext;
      v18->mNext = v19;
      v19->mPrev = v18;
      v15->mPrev = (UFG::qNode<UFG::qFile,UFG::qFile> *)&v15->mPrev;
      v15->mNext = (UFG::qNode<UFG::qFile,UFG::qFile> *)&v15->mPrev;
      UFG::qMemoryPool::Free(UFG::gMainMemoryPool, v15);
    }
    UFG::qFileOp::~qFileOp(k);
    UFG::qMemoryPool::Free(UFG::gMainMemoryPool, k);
  }
  for ( l = v26; v26 != (UFG::qFileOp *)&v25; l = v26 )
  {
    v21 = l->mPrev;
    v22 = l->mNext;
    v21->mNext = v22;
    v22->mPrev = v21;
    l->mPrev = (UFG::qNode<UFG::qFileOp,UFG::qFileOp> *)&l->mPrev;
    l->mNext = (UFG::qNode<UFG::qFileOp,UFG::qFileOp> *)&l->mPrev;
    UFG::qFileOp::~qFileOp(l);
    UFG::qMemoryPool::Free(UFG::gMainMemoryPool, l);
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
  bool *v2; // rbp
  UFG::qNode<UFG::qFileDevice,UFG::qFileDevice> **v3; // rdi
  UFG::qNode<UFG::qFileDevice,UFG::qFileDevice> *i; // rax

  v1 = 0;
  v2 = &this->mReportSyncFileOps;
  v3 = &this->mDevices.mNode.mNext[-1].mNext;
  do
  {
    if ( v3 == (UFG::qNode<UFG::qFileDevice,UFG::qFileDevice> **)v2 )
      break;
    UFG::qMutex::Lock((LPCRITICAL_SECTION)(v3 + 9));
    for ( i = v3[16]; !v1; i = i->mNext )
    {
      if ( i == (UFG::qNode<UFG::qFileDevice,UFG::qFileDevice> *)(v3 + 15) )
        break;
      v1 = i ? LODWORD(i[9].mPrev) != 0 : 0;
    }
    UFG::qMutex::Unlock((LPCRITICAL_SECTION)(v3 + 9));
    v3 = &v3[2][-1].mNext;
  }
  while ( !v1 );
  return v1;
}

// File Line: 2128
// RVA: 0x176020
void __fastcall UFG::qFileSystem::KillAsyncOps(UFG::qFileSystem *this, bool use_callback, bool use_callback_param, void (__fastcall *callback)(UFG::qFileOp *, void *), void *callback_param, UFG::qFile *file)
{
  void (__fastcall *v6)(UFG::qFileOp *, void *); // r15
  bool v7; // r12
  bool v8; // r14
  UFG::qFileSystem *v9; // rbx
  UFG::qFile *v10; // rsi
  bool v11; // r13
  UFG::qNode<UFG::qFileOp,UFG::qFileOp> *v12; // rax
  UFG::qNode<UFG::qFileOpList,UFG::qFileOpList> *i; // rdi
  bool v14; // r8
  bool v15; // dl
  bool v16; // cl
  signed __int64 v17; // rax
  UFG::qNode<UFG::qFileOpList,UFG::qFileOpList> *v18; // rbp
  UFG::qNode<UFG::qFileOpList,UFG::qFileOpList> *k; // rax
  bool v20; // r8
  bool v21; // dl
  bool v22; // cl
  UFG::qNode<UFG::qFileOpList,UFG::qFileOpList> *l; // rax
  bool v24; // r8
  bool v25; // dl
  bool v26; // cl
  _QWORD *v27; // rsi
  signed __int64 v28; // rdi
  signed __int64 v29; // rbp
  _QWORD *v30; // rdx
  _QWORD *v31; // rbx
  bool v32; // r9
  bool v33; // cl
  bool v34; // al
  __int64 v35; // rax
  UFG::qFileOp *v36; // rax
  __int64 *v37; // rcx
  UFG::qFileOp *m; // rdx
  UFG::qNode<UFG::qFileOp,UFG::qFileOp> *v39; // rcx
  UFG::qNode<UFG::qFileOp,UFG::qFileOp> *v40; // rax
  UFG::qFileOp *n; // rbx
  UFG::qNode<UFG::qFileOp,UFG::qFileOp> *v42; // rcx
  UFG::qNode<UFG::qFileOp,UFG::qFileOp> *v43; // rax
  __int64 *v44; // rdx
  UFG::qFileOp *v45; // rax
  signed __int64 v46; // [rsp+20h] [rbp-78h]
  signed __int64 v47; // [rsp+28h] [rbp-70h]
  signed __int64 v48; // [rsp+30h] [rbp-68h]
  signed __int64 v49; // [rsp+38h] [rbp-60h]
  signed __int64 j; // [rsp+40h] [rbp-58h]
  _RTL_CRITICAL_SECTION *lpCriticalSection; // [rsp+48h] [rbp-50h]
  __int64 *v52; // [rsp+58h] [rbp-40h]
  UFG::qFileOp *file_op; // [rsp+60h] [rbp-38h]
  UFG::qFileOpList *v54; // [rsp+A0h] [rbp+8h]

  v6 = callback;
  v7 = use_callback_param;
  v8 = use_callback;
  v9 = this;
  UFG::qGetCurrentThreadID();
  lpCriticalSection = (_RTL_CRITICAL_SECTION *)&v9->mMutex;
  UFG::qMutex::Lock((LPCRITICAL_SECTION)&v9->mMutex);
  v10 = file;
  v11 = file != 0i64;
  v12 = v9->mDoneFileOps.mNode.mNext;
  for ( i = (UFG::qNode<UFG::qFileOpList,UFG::qFileOpList> *)callback_param;
        v12 != (UFG::qNode<UFG::qFileOp,UFG::qFileOp> *)&v9->mDoneFileOps;
        v12 = v12->mNext )
  {
    if ( v8 )
      v14 = v12[5].mPrev == (UFG::qNode<UFG::qFileOp,UFG::qFileOp> *)v6;
    else
      v14 = 1;
    if ( v7 )
      v15 = v12[5].mNext == callback_param;
    else
      v15 = 1;
    if ( v11 )
      v16 = v12[4].mNext == (UFG::qNode<UFG::qFileOp,UFG::qFileOp> *)file;
    else
      v16 = 1;
    if ( v14 && v15 && v16 )
      HIDWORD(v12[1].mNext) = 4;
  }
  v17 = (signed __int64)&v9->mDevices.mNode.mNext[-1].mNext;
  v48 = v17;
  for ( j = (signed __int64)&v9->mReportSyncFileOps; v17 != j; v48 = v17 )
  {
    v18 = *(UFG::qNode<UFG::qFileOpList,UFG::qFileOpList> **)(v17 + 64);
    v54 = (UFG::qFileOpList *)v18;
    v49 = v17 + 56;
    if ( v18 != (UFG::qNode<UFG::qFileOpList,UFG::qFileOpList> *)(v17 + 56) )
    {
      do
      {
        UFG::qMutex::Lock((LPCRITICAL_SECTION)&v18[3]);
        v52 = (__int64 *)&v52;
        file_op = (UFG::qFileOp *)&v52;
        for ( k = v18[9].mNext; k != &v18[9]; k = k->mNext )
        {
          if ( v8 )
            v20 = k[5].mPrev == (UFG::qNode<UFG::qFileOpList,UFG::qFileOpList> *)v6;
          else
            v20 = 1;
          if ( v7 )
            v21 = k[5].mNext == i;
          else
            v21 = 1;
          if ( v11 )
            v22 = k[4].mNext == (UFG::qNode<UFG::qFileOpList,UFG::qFileOpList> *)v10;
          else
            v22 = 1;
          if ( v20 && v21 && v22 && LODWORD(k[1].mNext) != 1 )
            HIDWORD(k[1].mNext) = 4;
        }
        for ( l = v18[10].mNext; l != &v18[10]; l = l->mNext )
        {
          if ( v8 )
            v24 = l[5].mPrev == (UFG::qNode<UFG::qFileOpList,UFG::qFileOpList> *)v6;
          else
            v24 = 1;
          if ( v7 )
            v25 = l[5].mNext == i;
          else
            v25 = 1;
          if ( v11 )
            v26 = l[4].mNext == (UFG::qNode<UFG::qFileOpList,UFG::qFileOpList> *)v10;
          else
            v26 = 1;
          if ( v24 && v25 && v26 && LODWORD(l[1].mNext) != 1 )
            HIDWORD(l[1].mNext) = 4;
        }
        v27 = &v18[6].mNext;
        v46 = (signed __int64)&v18[6].mNext;
        v28 = (signed __int64)&v18[6];
        v29 = 3i64;
        v47 = 3i64;
        do
        {
          v30 = (_QWORD *)*v27;
          if ( *v27 != v28 )
          {
            do
            {
              v31 = (_QWORD *)v30[1];
              if ( v8 )
                v32 = v30[10] == (_QWORD)v6;
              else
                v32 = 1;
              if ( v7 )
                v33 = v30[11] == (_QWORD)callback_param;
              else
                v33 = 1;
              if ( v11 )
                v34 = v30[9] == (_QWORD)file;
              else
                v34 = 1;
              if ( v32 && v33 && v34 && *((_DWORD *)v30 + 6) != 1 )
              {
                *((_DWORD *)v30 + 7) = 4;
                v35 = *v30;
                *(_QWORD *)(v35 + 8) = v31;
                *v31 = v35;
                *v30 = v30;
                v30[1] = v30;
                v36 = UFG::qFileOpList::Completed(v54, (UFG::qFileOp *)v30);
                if ( v36 )
                {
                  v37 = v52;
                  v52[1] = (__int64)v36;
                  v36->mPrev = (UFG::qNode<UFG::qFileOp,UFG::qFileOp> *)v37;
                  v36->mNext = (UFG::qNode<UFG::qFileOp,UFG::qFileOp> *)&v52;
                  v52 = (__int64 *)v36;
                }
              }
              v30 = v31;
            }
            while ( v31 != (_QWORD *)v28 );
            v27 = (_QWORD *)v46;
            v29 = v47;
          }
          v28 += 16i64;
          v27 += 2;
          v46 = (signed __int64)v27;
          v47 = --v29;
        }
        while ( v29 );
        for ( m = file_op; file_op != (UFG::qFileOp *)&v52; m = file_op )
        {
          v39 = m->mPrev;
          v40 = m->mNext;
          v39->mNext = v40;
          v40->mPrev = v39;
          m->mPrev = (UFG::qNode<UFG::qFileOp,UFG::qFileOp> *)&m->mPrev;
          m->mNext = (UFG::qNode<UFG::qFileOp,UFG::qFileOp> *)&m->mPrev;
          UFG::qFileOpList::Queue(v54, m, 0);
        }
        for ( n = file_op; file_op != (UFG::qFileOp *)&v52; n = file_op )
        {
          v42 = n->mPrev;
          v43 = n->mNext;
          v42->mNext = v43;
          v43->mPrev = v42;
          n->mPrev = (UFG::qNode<UFG::qFileOp,UFG::qFileOp> *)&n->mPrev;
          n->mNext = (UFG::qNode<UFG::qFileOp,UFG::qFileOp> *)&n->mPrev;
          UFG::qFileOp::~qFileOp(n);
          UFG::qMemoryPool::Free(UFG::gMainMemoryPool, n);
        }
        v44 = v52;
        v45 = file_op;
        v52[1] = (__int64)file_op;
        v45->mPrev = (UFG::qNode<UFG::qFileOp,UFG::qFileOp> *)v44;
        v52 = (__int64 *)&v52;
        file_op = (UFG::qFileOp *)&v52;
        UFG::qMutex::Unlock((LPCRITICAL_SECTION)&v54->mMutex);
        v18 = v54->mNext;
        v54 = (UFG::qFileOpList *)v18;
        i = (UFG::qNode<UFG::qFileOpList,UFG::qFileOpList> *)callback_param;
        v10 = file;
      }
      while ( v18 != (UFG::qNode<UFG::qFileOpList,UFG::qFileOpList> *)v49 );
      v17 = v48;
    }
    v17 = *(_QWORD *)(v17 + 16) - 8i64;
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
  UFG::qFile *v1; // rbx

  v1 = file;
  if ( unk_14235ACD8 || !file || !file->mDevice )
    return 0;
  if ( file->mOpenState == 0 || file->mOpenState == 2 )
    return 1;
  if ( file->mCloseState )
    return 0;
  if ( file->mOpenState == 1 )
  {
    do
      UFG::qSleep(0);
    while ( v1->mOpenState == 1 );
  }
  return v1->mOpenState == 2;
}

// File Line: 2382
// RVA: 0x183790
void __fastcall UFG::qFileWaitForCompletion(UFG *this)
{
  bool v1; // bl
  signed __int64 v2; // rdi
  __int64 i; // rax

  do
  {
LABEL_1:
    UFG::qFileSystem::Service(&UFG::gQuarkFileSystem);
    UFG::qSleep(1u);
    v1 = 0;
    v2 = unk_14235ABE8 - 8i64;
    while ( (_UNKNOWN *)v2 != &unk_14235ABD8 )
    {
      UFG::qMutex::Lock((LPCRITICAL_SECTION)(v2 + 72));
      for ( i = *(_QWORD *)(v2 + 128); !v1; i = *(_QWORD *)(i + 8) )
      {
        if ( i == v2 + 120 )
          break;
        v1 = i ? *(_DWORD *)(i + 144) != 0 : 0;
      }
      UFG::qMutex::Unlock((LPCRITICAL_SECTION)(v2 + 72));
      v2 = *(_QWORD *)(v2 + 16) - 8i64;
      if ( v1 )
        goto LABEL_1;
    }
  }
  while ( v1 );
}

// File Line: 2397
// RVA: 0x184500
char *__fastcall UFG::qGetFileName(UFG::qFile *file)
{
  char *result; // rax

  if ( file )
    result = file->mFilename;
  else
    result = 0i64;
  return result;
}

// File Line: 2447
// RVA: 0x1836F0
UFG::qString *__fastcall UFG::qFileMapFilename(UFG::qString *result, UFG::qFileMapType file_map_type, const char *filename)
{
  UFG::qString *v3; // rbx

  v3 = result;
  UFG::qFileSystem::MapFilename(&UFG::gQuarkFileSystem, result, file_map_type, filename);
  return v3;
}

// File Line: 2463
// RVA: 0x183A10
UFG::qString *__fastcall UFG::qFixUpDirectoryPath(UFG::qString *result, const char *directory)
{
  const char *v2; // r10
  UFG::qString *v3; // rbx
  const char *v4; // rax
  char v5; // cl
  int v6; // eax
  __int64 v7; // rcx
  char v8; // dl
  char v9; // dl
  UFG::qNode<UFG::qString,UFG::qString> *v10; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *v11; // rax
  UFG::qString *v12; // rax
  UFG::qString v13; // [rsp+40h] [rbp-30h]

  v2 = directory;
  v3 = result;
  if ( directory && *directory )
  {
    v13.mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&v13;
    v13.mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&v13;
    *(_QWORD *)&v13.mMagic = 16909060i64;
    v13.mData = (char *)UFG::qString::sEmptyString;
    *(_QWORD *)&v13.mStringHash32 = -1i64;
    v4 = directory;
    do
      v5 = *v4++;
    while ( v5 );
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
        v9 = v2[v7 - 1];
      }
      while ( v9 == 92 || v9 == 47 );
    }
    UFG::qString::Set(&v13, v2, v6, 0i64, 0);
    v3->mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&v3->mPrev;
    v3->mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&v3->mPrev;
    v3->mMagic = 16909060;
    v3->mData = (char *)UFG::qString::sEmptyString;
    v3->mLength = 0;
    UFG::qString::Set(v3, v13.mData, v13.mLength, 0i64, 0);
    v3->mStringHash32 = v13.mStringHash32;
    v3->mStringHashUpper32 = v13.mStringHashUpper32;
    if ( v13.mData != UFG::qString::sEmptyString )
    {
      if ( v13.mData )
        UFG::qMemoryPool::Free(UFG::gMainMemoryPool, v13.mData);
    }
    v13.mMagic = 0;
    v10 = v13.mPrev;
    v11 = v13.mNext;
    v13.mPrev->mNext = v13.mNext;
    v11->mPrev = v10;
    v13.mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&v13;
    v13.mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&v13;
    v12 = v3;
  }
  else
  {
    result->mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&result->mPrev;
    result->mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&result->mPrev;
    result->mMagic = 16909060;
    result->mData = (char *)UFG::qString::sEmptyString;
    result->mLength = 0;
    *(_QWORD *)&result->mStringHash32 = -1i64;
    v12 = result;
  }
  return v12;
}

// File Line: 2530
// RVA: 0x1887E0
bool __fastcall UFG::qOpenInternal(UFG::qFile *file, bool warn_if_fail)
{
  UFG::qFile *v2; // rdi
  UFG::qFileDevice *v4; // r12
  const char *v5; // rbx
  bool v6; // r15
  char v7; // r14
  UFG::qString *v8; // rax
  UFG::qNode<UFG::qString,UFG::qString> *v9; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *v10; // rax
  UFG::qNode<UFG::qString,UFG::qString> *v11; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *v12; // rax
  UFG::qNode<UFG::qString,UFG::qString> *v13; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *v14; // rax
  _BOOL8 v15; // r13
  UFG::qNode<UFG::qFile,UFG::qFile> *v16; // rax
  UFG::qString result; // [rsp+0h] [rbp-49h]
  UFG::qString v18; // [rsp+28h] [rbp-21h]
  UFG::qString v19; // [rsp+50h] [rbp+7h]
  __int64 v20; // [rsp+78h] [rbp+2Fh]
  unsigned __int8 v21; // [rsp+B8h] [rbp+6Fh]

  v20 = -2i64;
  v2 = file;
  if ( !file )
    return 0;
  v4 = file->mDevice;
  v5 = file->mFilename;
  v6 = file->mFilename[0] != 0 && v4 != 0i64 && unk_14235ACD8 == 0 && file->mFilename != 0i64;
  v7 = 1;
  if ( ((file->mAccessType & 0x12) != 0) | ((file->mAccessType | ((unsigned int)file->mAccessType >> 1)) >> 1) & 1 )
  {
    UFG::qString::qString(&v18, v5);
    UFG::qString::GetFilePath(&v18, &result);
    if ( v6 != 1 || v4->vfptr->CreateDirectoryA(v4, result.mData) != 1 )
    {
      v8 = UFG::qGetDirectory(&v19);
      UFG::qPrintf(
        "WARNING:  Could not create directory '%s' when opening '%s'.  Current Dir = '%s'\n",
        result.mData,
        v5,
        v8->mData);
      if ( v19.mData != UFG::qString::sEmptyString && v19.mData )
        UFG::qMemoryPool::Free(UFG::gMainMemoryPool, v19.mData);
      v19.mMagic = 0;
      v9 = v19.mPrev;
      v10 = v19.mNext;
      v19.mPrev->mNext = v19.mNext;
      v10->mPrev = v9;
      v19.mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&v19;
      v19.mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&v19;
      v7 = 0;
    }
    if ( result.mData != UFG::qString::sEmptyString && result.mData )
      UFG::qMemoryPool::Free(UFG::gMainMemoryPool, result.mData);
    result.mMagic = 0;
    v11 = result.mPrev;
    v12 = result.mNext;
    result.mPrev->mNext = result.mNext;
    v12->mPrev = v11;
    result.mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&result;
    result.mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&result;
    if ( v18.mData != UFG::qString::sEmptyString && v18.mData )
      UFG::qMemoryPool::Free(UFG::gMainMemoryPool, v18.mData);
    v18.mMagic = 0;
    v13 = v18.mPrev;
    v14 = v18.mNext;
    v18.mPrev->mNext = v18.mNext;
    v14->mPrev = v13;
    v18.mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&v18;
    v18.mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&v18;
  }
  LOBYTE(v15) = 0;
  if ( v6 == 1 && v7 == 1 )
  {
    UFG::qMutex::Lock((LPCRITICAL_SECTION)&v2->mFileHandleMutex);
    v15 = v4->vfptr->FileOpen(v4, v2, v21);
    UFG::qMutex::Unlock((LPCRITICAL_SECTION)&v2->mFileHandleMutex);
  }
  UFG::qMutex::Lock((LPCRITICAL_SECTION)&v2->mStateMutex);
  if ( v6 != 1 || v7 != 1 || (_BYTE)v15 != 1 )
  {
    v2->mOpenState = 0;
    v2->mCloseState = 4;
  }
  else
  {
    v2->mOpenState = 2;
  }
  UFG::qMutex::Unlock((LPCRITICAL_SECTION)&v2->mStateMutex);
  if ( v2->mOpenState == 2 )
  {
    UFG::qMutex::Lock((LPCRITICAL_SECTION)&v4->mMutex);
    v16 = v4->mOpenFiles.mNode.mPrev;
    v16->mNext = (UFG::qNode<UFG::qFile,UFG::qFile> *)&v2->mPrev;
    v2->mPrev = v16;
    v2->mNext = &v4->mOpenFiles.mNode;
    v4->mOpenFiles.mNode.mPrev = (UFG::qNode<UFG::qFile,UFG::qFile> *)&v2->mPrev;
    UFG::qMutex::Unlock((LPCRITICAL_SECTION)&v4->mMutex);
  }
  else if ( v21 == 1 )
  {
    UFG::qPrintf("ERROR: Unable to open file = '%s'\n", v2->mFilename);
  }
  return v2->mOpenState == 2;
}

// File Line: 2627
// RVA: 0x1823D0
char __fastcall UFG::qCloseInternal(UFG::qFile *file)
{
  UFG::qFile *v1; // rdi
  char v3; // bl
  UFG::qFileDevice *v4; // rsi
  UFG::qNode<UFG::qFile,UFG::qFile> *v5; // rdx
  UFG::qNode<UFG::qFile,UFG::qFile> *v6; // rax

  v1 = file;
  if ( !file )
    return 0;
  UFG::qMutex::Lock((LPCRITICAL_SECTION)&file->mStateMutex);
  v3 = 0;
  if ( v1->mCloseState == 3 )
    v3 = 1;
  UFG::qMutex::Unlock((LPCRITICAL_SECTION)&v1->mStateMutex);
  v4 = v1->mDevice;
  if ( v3 && v4 )
  {
    UFG::qMutex::Lock((LPCRITICAL_SECTION)&v1->mFileHandleMutex);
    v4->vfptr->FileClose(v4, v1);
    UFG::qMutex::Unlock((LPCRITICAL_SECTION)&v1->mFileHandleMutex);
  }
  UFG::qMutex::Lock((LPCRITICAL_SECTION)&v1->mStateMutex);
  v1->mOpenState = 0;
  v1->mCloseState = 4;
  v1->mAsyncCloseOp = 0i64;
  UFG::qMutex::Unlock((LPCRITICAL_SECTION)&v1->mStateMutex);
  if ( v4 )
  {
    UFG::qMutex::Lock((LPCRITICAL_SECTION)&v4->mMutex);
    v5 = v1->mPrev;
    v6 = v1->mNext;
    v5->mNext = v6;
    v6->mPrev = v5;
    v1->mPrev = (UFG::qNode<UFG::qFile,UFG::qFile> *)&v1->mPrev;
    v1->mNext = (UFG::qNode<UFG::qFile,UFG::qFile> *)&v1->mPrev;
    UFG::qMutex::Unlock((LPCRITICAL_SECTION)&v4->mMutex);
  }
  return 1;
}

// File Line: 2715
// RVA: 0x188440
UFG::qFile *__fastcall UFG::qOpen(const char *filename, UFG::qFileAccessType access_type, bool warn_if_fail)
{
  bool v3; // di
  int v4; // esi
  const char *v5; // rbx
  UFG::qFileDevice *v6; // rbx
  UFG::qMemoryPool *v7; // rcx
  UFG::allocator::free_link *v8; // rax
  UFG::qFile *v9; // rax
  UFG::qFile *v10; // rbx
  UFG::qNode<UFG::qFile,UFG::qFile> *v11; // rcx
  UFG::qNode<UFG::qFile,UFG::qFile> *v12; // rax
  UFG::qNode<UFG::qString,UFG::qString> *v13; // rdx
  UFG::qNode<UFG::qString,UFG::qString> *v14; // rcx
  UFG::qString result; // [rsp+38h] [rbp-30h]

  v3 = warn_if_fail;
  v4 = access_type;
  v5 = filename;
  UFG::qFileSystem::MapFilename(&UFG::gQuarkFileSystem, &result, 0, filename);
  v6 = UFG::qFileSystem::MapFilenameToDevice(&UFG::gQuarkFileSystem, v5);
  v7 = UFG::gMainMemoryPool;
  if ( !UFG::gMainMemoryPool )
  {
    UFG::InternalSetupMainMemoryPool((UFG *)UFG::gMainMemoryPool);
    v7 = UFG::gMainMemoryPool;
  }
  v8 = UFG::qMemoryPool::Allocate(v7, 0x1A8ui64, "qFile", 0i64, 1u);
  if ( v8 )
  {
    UFG::qFile::qFile((UFG::qFile *)v8, v6, result.mData, v4);
    v10 = v9;
  }
  else
  {
    v10 = 0i64;
  }
  v10->mOpenState = 1;
  if ( !UFG::qOpenInternal(v10, v3) )
  {
    Scaleform::Lock::~Lock((LPCRITICAL_SECTION)&v10->mStateMutex);
    Scaleform::Lock::~Lock((LPCRITICAL_SECTION)&v10->mFileHandleMutex);
    v11 = v10->mPrev;
    v12 = v10->mNext;
    v11->mNext = v12;
    v12->mPrev = v11;
    v10->mPrev = (UFG::qNode<UFG::qFile,UFG::qFile> *)&v10->mPrev;
    v10->mNext = (UFG::qNode<UFG::qFile,UFG::qFile> *)&v10->mPrev;
    UFG::qMemoryPool::Free(UFG::gMainMemoryPool, v10);
    v10 = 0i64;
  }
  if ( result.mData != UFG::qString::sEmptyString && result.mData )
    UFG::qMemoryPool::Free(UFG::gMainMemoryPool, result.mData);
  v13 = result.mPrev;
  v14 = result.mNext;
  result.mPrev->mNext = result.mNext;
  v14->mPrev = v13;
  return v10;
}

// File Line: 2738
// RVA: 0x1885B0
UFG::qFile *__fastcall UFG::qOpenAsync(const char *filename, UFG::qFileAccessType access_type, bool warn_if_fail, void (__fastcall *callback)(UFG::qFileOp *, void *), void *callback_param, UFG::qFilePriorityLevel priority)
{
  void (__fastcall *v6)(UFG::qFileOp *, void *); // r14
  bool v7; // bp
  int v8; // ebx
  const char *v9; // rdi
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
  char v20; // al
  int v21; // ecx
  __int64 v22; // rcx
  __int64 v23; // rax
  __int64 v24; // rcx
  __int64 *v25; // rax
  __int64 v27; // [rsp+38h] [rbp-40h]
  __int64 *v28; // [rsp+40h] [rbp-38h]
  char *filenamea; // [rsp+50h] [rbp-28h]

  v6 = callback;
  v7 = warn_if_fail;
  v8 = access_type;
  v9 = filename;
  UFG::qFileSystem::MapFilename(&UFG::gQuarkFileSystem, (UFG::qString *)&v27, 0, filename);
  v10 = UFG::qFileSystem::MapFilenameToDevice(&UFG::gQuarkFileSystem, v9);
  v11 = UFG::gMainMemoryPool;
  if ( !UFG::gMainMemoryPool )
  {
    UFG::InternalSetupMainMemoryPool((UFG *)UFG::gMainMemoryPool);
    v11 = UFG::gMainMemoryPool;
  }
  v12 = UFG::qMemoryPool::Allocate(v11, 0x1A8ui64, "qFile", 0i64, 1u);
  if ( v12 )
  {
    UFG::qFile::qFile((UFG::qFile *)v12, v10, filenamea, v8);
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
    UFG::qFileOp::qFileOp((UFG::qFileOp *)v16, (UFG::qFile *)v14, 0, v6, callback_param);
    v18 = v17;
  }
  else
  {
    v18 = 0i64;
  }
  *(_BYTE *)(v18 + 112) = v7;
  if ( v9 && v9 != UFG::qString::sEmptyString )
  {
    v19 = v9;
    do
      v20 = *v19++;
    while ( v20 );
    v21 = (_DWORD)v19 - (_DWORD)v9 - 1;
  }
  else
  {
    v21 = 0;
  }
  UFG::qString::Set((UFG::qString *)(v18 + 32), v9, v21, 0i64, 0);
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
  if ( filenamea != UFG::qString::sEmptyString && filenamea )
    UFG::qMemoryPool::Free(UFG::gMainMemoryPool, filenamea);
  v24 = v27;
  v25 = v28;
  *(_QWORD *)(v27 + 8) = v28;
  *v25 = v24;
  return (UFG::qFile *)v14;
}

// File Line: 2760
// RVA: 0x182160
void __fastcall UFG::qClose(UFG::qFile *file)
{
  UFG::qFile *v1; // rdi
  UFG::qNode<UFG::qFile,UFG::qFile> *v2; // rcx
  UFG::qNode<UFG::qFile,UFG::qFile> *v3; // rax

  if ( file )
  {
    v1 = file;
    UFG::qMutex::Lock((LPCRITICAL_SECTION)&file->mStateMutex);
    v1->mCloseState = 3;
    UFG::qMutex::Unlock((LPCRITICAL_SECTION)&v1->mStateMutex);
    UFG::qWaitForOpenFileHandle(v1);
    UFG::qCloseInternal(v1);
    Scaleform::Lock::~Lock((LPCRITICAL_SECTION)&v1->mStateMutex);
    Scaleform::Lock::~Lock((LPCRITICAL_SECTION)&v1->mFileHandleMutex);
    v2 = v1->mPrev;
    v3 = v1->mNext;
    v2->mNext = v3;
    v3->mPrev = v2;
    v1->mPrev = (UFG::qNode<UFG::qFile,UFG::qFile> *)&v1->mPrev;
    v1->mNext = (UFG::qNode<UFG::qFile,UFG::qFile> *)&v1->mPrev;
    UFG::qMemoryPool::Free(UFG::gMainMemoryPool, v1);
  }
}

// File Line: 2789
// RVA: 0x1822E0
void __fastcall UFG::qCloseAsync(UFG::qFile *file, void (__fastcall *callback)(UFG::qFileOp *, void *), void *callback_param, UFG::qFilePriorityLevel priority)
{
  void *v4; // rdi
  void (__fastcall *v5)(UFG::qFileOp *, void *); // rsi
  UFG::qFile *v6; // rbx
  UFG::qMemoryPool *v7; // rcx
  UFG::allocator::free_link *v8; // rax
  UFG::qFileOp *v9; // rax
  UFG::qFileOp *v10; // rdi

  if ( file )
  {
    v4 = callback_param;
    v5 = callback;
    v6 = file;
    v7 = UFG::gMainMemoryPool;
    if ( !UFG::gMainMemoryPool )
    {
      UFG::InternalSetupMainMemoryPool((UFG *)UFG::gMainMemoryPool);
      v7 = UFG::gMainMemoryPool;
    }
    v8 = UFG::qMemoryPool::Allocate(v7, 0x170ui64, "qFileOp.OP_CLOSE", 0i64, 1u);
    if ( v8 )
    {
      UFG::qFileOp::qFileOp((UFG::qFileOp *)v8, v6, OP_CLOSE, v5, v4);
      v10 = v9;
    }
    else
    {
      v10 = 0i64;
    }
    UFG::qMutex::Lock((LPCRITICAL_SECTION)&v6->mStateMutex);
    v6->mCloseState = 3;
    v6->mAsyncCloseOp = v10;
    if ( !v6->mNumAsyncOps )
      UFG::qFileSystem::QueueAsyncOp(&UFG::gQuarkFileSystem, v10, 0i64);
    UFG::qMutex::Unlock((LPCRITICAL_SECTION)&v6->mStateMutex);
  }
}

// File Line: 2845
// RVA: 0x184510
__int64 __fastcall UFG::qGetFileSize(UFG::qFile *file)
{
  UFG::qFile *v1; // rbx
  __int64 v3; // rax
  _RTL_CRITICAL_SECTION *v4; // rcx
  __int64 v5; // rbx

  v1 = file;
  if ( !UFG::qWaitForOpenFileHandle(file) )
    return -1i64;
  UFG::qMutex::Lock((LPCRITICAL_SECTION)&v1->mFileHandleMutex);
  v3 = v1->mDevice->vfptr->GetFileSize(v1->mDevice, v1);
  v4 = (_RTL_CRITICAL_SECTION *)&v1->mFileHandleMutex;
  v5 = v3;
  UFG::qMutex::Unlock(v4);
  return v5;
}

// File Line: 2917
// RVA: 0x184190
__int64 __fastcall UFG::qGetDiskPosSortKey(UFG::qFile *file)
{
  UFG::qFile *v1; // rsi
  UFG::qFileDevice *v3; // rbx
  __int64 v4; // rbx

  v1 = file;
  if ( !UFG::qWaitForOpenFileHandle(file) )
    return -1i64;
  v3 = v1->mDevice;
  UFG::qMutex::Lock((LPCRITICAL_SECTION)&v1->mFileHandleMutex);
  v4 = v3->vfptr->FileGetDiskPosSortKey(v3, v1);
  UFG::qMutex::Unlock((LPCRITICAL_SECTION)&v1->mFileHandleMutex);
  return v4;
}

// File Line: 2939
// RVA: 0x1896B0
__int64 __fastcall UFG::qRead(UFG::qFile *file, void *buffer, __int64 num_bytes, __int64 seek_offset, UFG::qFileSeekType seek_type)
{
  __int64 v5; // r15
  __int64 v6; // rbp
  void *v7; // r14
  UFG::qFile *v8; // rsi
  UFG::qFileDevice *v10; // rbx
  __int64 v11; // rbx

  v5 = seek_offset;
  v6 = num_bytes;
  v7 = buffer;
  v8 = file;
  if ( !UFG::qWaitForOpenFileHandle(file) || !v7 )
    return -1i64;
  if ( !v6 )
    return 0i64;
  v10 = v8->mDevice;
  UFG::qMutex::Lock((LPCRITICAL_SECTION)&v8->mFileHandleMutex);
  v10->vfptr->FileSeek(v10, v8, seek_type, v5);
  v11 = v10->vfptr->FileRead(v10, v8, v7, v6);
  UFG::qMutex::Unlock((LPCRITICAL_SECTION)&v8->mFileHandleMutex);
  return v11;
}

// File Line: 2967
// RVA: 0x189AF0
void __fastcall UFG::qReadAsync(UFG::qFile *file, void *buffer, __int64 size, __int64 seek_offset, UFG::qFileSeekType seek_type, void (__fastcall *callback)(UFG::qFileOp *, void *), void *callback_param, UFG::qFilePriorityLevel priority)
{
  __int64 v8; // rdi
  __int64 v9; // rsi
  void *v10; // rbp
  UFG::qFile *v11; // rbx
  UFG::qMemoryPool *v12; // rcx
  UFG::allocator::free_link *v13; // rax
  UFG::qFileOp *v14; // rax
  UFG::qFileOp *v15; // rbx
  UFG::qFileDevice *v16; // rcx
  UFG::qNode<UFG::qFileOp,UFG::qFileOp> *v17; // rax

  v8 = seek_offset;
  v9 = size;
  v10 = buffer;
  v11 = file;
  v12 = UFG::gMainMemoryPool;
  if ( !UFG::gMainMemoryPool )
  {
    UFG::InternalSetupMainMemoryPool((UFG *)UFG::gMainMemoryPool);
    v12 = UFG::gMainMemoryPool;
  }
  v13 = UFG::qMemoryPool::Allocate(v12, 0x170ui64, "qFileOp.OP_READ", 0i64, 1u);
  if ( v13 )
  {
    UFG::qFileOp::qFileOp((UFG::qFileOp *)v13, v11, OP_READ, callback, callback_param);
    v15 = v14;
  }
  else
  {
    v15 = 0i64;
  }
  v15->mSeekType = seek_type;
  v15->mSeekOffset = v8;
  v15->mBuffer = v10;
  v15->mNumBytes = v9;
  v16 = v15->mDevice;
  if ( v16 )
  {
    (*(void (__fastcall **)(UFG::qFileDevice *, UFG::qFileOp *, _QWORD))&v16->vfptr->gap8[16])(
      v16,
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
__int64 __fastcall UFG::qWrite(UFG::qFile *file, const void *buffer, __int64 num_bytes, __int64 seek_offset, UFG::qFileSeekType seek_type, bool *not_enough_space)
{
  __int64 v6; // r15
  __int64 v7; // rbp
  const void *v8; // r14
  UFG::qFile *v9; // rsi
  UFG::qFileDevice *v11; // rbx
  __int64 v12; // rbx
  bool v13; // [rsp+30h] [rbp-28h]

  v6 = seek_offset;
  v7 = num_bytes;
  v8 = buffer;
  v9 = file;
  if ( !UFG::qWaitForOpenFileHandle(file) || !v8 )
    return -1i64;
  if ( !v7 )
    return 0i64;
  v11 = v9->mDevice;
  v13 = 0;
  UFG::qMutex::Lock((LPCRITICAL_SECTION)&v9->mFileHandleMutex);
  v11->vfptr->FileSeek(v11, v9, seek_type, v6);
  v12 = v11->vfptr->FileWrite(v11, v9, v8, v7, &v13);
  UFG::qMutex::Unlock((LPCRITICAL_SECTION)&v9->mFileHandleMutex);
  if ( not_enough_space )
    *not_enough_space = v13;
  return v12;
}

// File Line: 3066
// RVA: 0x1829E0
__int64 __fastcall UFG::qCreateDirectory(char *a1)
{
  char *v1; // rbx
  UFG::qFileDevice *v2; // rbx
  UFG::qNode<UFG::qString,UFG::qString> *v3; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *v4; // rax
  bool v5; // bl
  UFG::qNode<UFG::qString,UFG::qString> *v6; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *v7; // rax
  UFG::qNode<UFG::qString,UFG::qString> *v8; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *v9; // rax
  UFG::qString v11; // [rsp+20h] [rbp-29h]
  UFG::qString v12; // [rsp+48h] [rbp-1h]
  UFG::qString result; // [rsp+70h] [rbp+27h]
  __int64 v14; // [rsp+98h] [rbp+4Fh]

  v14 = -2i64;
  UFG::qFixUpDirectoryPath(&result, a1);
  UFG::qFileSystem::MapFilename(&UFG::gQuarkFileSystem, &v11, 0, result.mData);
  v1 = v11.mData;
  UFG::qFileSystem::MapFilename(&UFG::gQuarkFileSystem, &v12, 0, v11.mData);
  if ( !qword_14235AC78 || (v2 = (UFG::qFileDevice *)qword_14235AC78(v1)) == 0i64 )
    v2 = UFG::qFileSystem::MapFilenameToDevicePlat(&UFG::gQuarkFileSystem, v12.mData);
  if ( v12.mData != UFG::qString::sEmptyString && v12.mData )
    UFG::qMemoryPool::Free(UFG::gMainMemoryPool, v12.mData);
  v12.mMagic = 0;
  v3 = v12.mPrev;
  v4 = v12.mNext;
  v12.mPrev->mNext = v12.mNext;
  v4->mPrev = v3;
  v12.mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&v12;
  v12.mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&v12;
  if ( unk_14235ACD8 || !v2 )
    v5 = 0;
  else
    v5 = v2->vfptr->CreateDirectoryA(v2, v11.mData);
  if ( v11.mData != UFG::qString::sEmptyString && v11.mData )
    UFG::qMemoryPool::Free(UFG::gMainMemoryPool, v11.mData);
  v11.mMagic = 0;
  v6 = v11.mPrev;
  v7 = v11.mNext;
  v11.mPrev->mNext = v11.mNext;
  v7->mPrev = v6;
  v11.mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&v11;
  v11.mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&v11;
  if ( result.mData != UFG::qString::sEmptyString && result.mData )
    UFG::qMemoryPool::Free(UFG::gMainMemoryPool, result.mData);
  v8 = result.mPrev;
  v9 = result.mNext;
  result.mPrev->mNext = result.mNext;
  v9->mPrev = v8;
  return v5;
}

// File Line: 3116
// RVA: 0x1847F0
__int64 __fastcall UFG::qGetFiles(UFG::qList<UFG::qString,UFG::qString,1,0> *files, const char *initial_directory, int recursive, UFG::qList<UFG::qString,UFG::qString,1,0> *patterns)
{
  UFG::qList<UFG::qString,UFG::qString,1,0> *v4; // rdi
  int v5; // esi
  const char *v6; // rbx
  UFG::qList<UFG::qString,UFG::qString,1,0> *v7; // rbp
  UFG::qFileDevice *v8; // rax
  __int64 v9; // r9
  unsigned int v10; // ebx
  __int64 v11; // rcx
  __int64 *v12; // rax
  __int64 v14; // [rsp+38h] [rbp-30h]
  __int64 *v15; // [rsp+40h] [rbp-28h]
  void *ptr; // [rsp+50h] [rbp-18h]

  v4 = patterns;
  v5 = recursive;
  v6 = initial_directory;
  v7 = files;
  UFG::qFileSystem::MapFilename(&UFG::gQuarkFileSystem, (UFG::qString *)&v14, 0, initial_directory);
  if ( !unk_14235ACD8 && v6 && *v6 && (v8 = UFG::qFileSystem::MapFilenameToDevice(&UFG::gQuarkFileSystem, v6)) != 0i64 )
  {
    LOBYTE(v9) = v5 != 0;
    v10 = ((__int64 (__fastcall *)(UFG::qFileDevice *, UFG::qList<UFG::qString,UFG::qString,1,0> *, void *, __int64, UFG::qList<UFG::qString,UFG::qString,1,0> *, _QWORD, signed __int64))v8->vfptr->FindFilesAndDirs)(
            v8,
            v7,
            ptr,
            v9,
            v4,
            0i64,
            -2i64);
  }
  else
  {
    v10 = 0;
  }
  if ( ptr != UFG::qString::sEmptyString && ptr )
    UFG::qMemoryPool::Free(UFG::gMainMemoryPool, ptr);
  v11 = v14;
  v12 = v15;
  *(_QWORD *)(v14 + 8) = v15;
  *v12 = v11;
  return v10;
}

// File Line: 3137
// RVA: 0x1848F0
__int64 __fastcall UFG::qGetFiles(UFG::qList<UFG::qString,UFG::qString,1,0> *files, const char *initial_directory, int recursive, const char *pattern)
{
  const char *v4; // rbx
  int v5; // edi
  UFG::qList<UFG::qString,UFG::qString,1,0> *v6; // rsi
  UFG::qMemoryPool *v7; // rcx
  UFG::qString *v8; // rax
  UFG::qNode<UFG::qString,UFG::qString> *v9; // rax
  UFG::qNode<UFG::qString,UFG::qString> *v10; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *v11; // rax
  unsigned int v12; // ebx
  UFG::qNode<UFG::qString,UFG::qString> *v13; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *v14; // rax
  UFG::qNode<UFG::qString,UFG::qString> *v15; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *v16; // rax
  UFG::qList<UFG::qString,UFG::qString,1,0> patterns; // [rsp+40h] [rbp-40h]
  UFG::qString result; // [rsp+50h] [rbp-30h]

  v4 = pattern;
  v5 = recursive;
  v6 = files;
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
    UFG::qString::qString(v8, v4);
    v10 = v9;
  }
  else
  {
    v10 = 0i64;
  }
  v11 = patterns.mNode.mPrev;
  patterns.mNode.mPrev->mNext = v10;
  v10->mPrev = v11;
  v10->mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&patterns;
  patterns.mNode.mPrev = v10;
  v12 = UFG::qGetFiles(v6, result.mData, v5, &patterns);
  if ( result.mData != UFG::qString::sEmptyString && result.mData )
    UFG::qMemoryPool::Free(UFG::gMainMemoryPool, result.mData);
  result.mMagic = 0;
  v13 = result.mPrev;
  v14 = result.mNext;
  result.mPrev->mNext = result.mNext;
  v14->mPrev = v13;
  result.mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&result;
  result.mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&result;
  UFG::qList<UFG::qString,UFG::qString,1,0>::DeleteNodes(&patterns);
  v15 = patterns.mNode.mPrev;
  v16 = patterns.mNode.mNext;
  patterns.mNode.mPrev->mNext = patterns.mNode.mNext;
  v16->mPrev = v15;
  return v12;
}

// File Line: 3199
// RVA: 0x184090
__int64 __fastcall UFG::qGetDirectories(UFG::qList<UFG::qString,UFG::qString,1,0> *directories, const char *base_directory, int recursive, UFG::qList<UFG::qString,UFG::qString,1,0> *patterns)
{
  UFG::qList<UFG::qString,UFG::qString,1,0> *v4; // rdi
  int v5; // esi
  const char *v6; // rbx
  UFG::qList<UFG::qString,UFG::qString,1,0> *v7; // rbp
  UFG::qFileDevice *v8; // rax
  __int64 v9; // r9
  unsigned int v10; // ebx
  __int64 v11; // rcx
  __int64 *v12; // rax
  __int64 v14; // [rsp+38h] [rbp-30h]
  __int64 *v15; // [rsp+40h] [rbp-28h]
  void *ptr; // [rsp+50h] [rbp-18h]

  v4 = patterns;
  v5 = recursive;
  v6 = base_directory;
  v7 = directories;
  UFG::qFileSystem::MapFilename(&UFG::gQuarkFileSystem, (UFG::qString *)&v14, 0, base_directory);
  if ( !unk_14235ACD8 && v6 && *v6 && (v8 = UFG::qFileSystem::MapFilenameToDevice(&UFG::gQuarkFileSystem, v6)) != 0i64 )
  {
    LOBYTE(v9) = v5 != 0;
    v10 = ((__int64 (__fastcall *)(UFG::qFileDevice *, UFG::qList<UFG::qString,UFG::qString,1,0> *, void *, __int64, _QWORD, UFG::qList<UFG::qString,UFG::qString,1,0> *, signed __int64))v8->vfptr->FindFilesAndDirs)(
            v8,
            v7,
            ptr,
            v9,
            0i64,
            v4,
            -2i64);
  }
  else
  {
    v10 = 0;
  }
  if ( ptr != UFG::qString::sEmptyString && ptr )
    UFG::qMemoryPool::Free(UFG::gMainMemoryPool, ptr);
  v11 = v14;
  v12 = v15;
  *(_QWORD *)(v14 + 8) = v15;
  *v12 = v11;
  return v10;
}

// File Line: 3282
// RVA: 0x18A2F0
_BOOL8 __fastcall UFG::qRenameFile(const char *src_filename, const char *dest_filename)
{
  const char *v2; // rsi
  const char *v3; // rbx
  UFG::qFileDevice *v4; // r14
  UFG::qFileDevice *v5; // rdi
  bool v6; // bl
  UFG::qNode<UFG::qString,UFG::qString> *v7; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *v8; // rax
  UFG::qNode<UFG::qString,UFG::qString> *v9; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *v10; // rax
  UFG::qString v12; // [rsp+28h] [rbp-60h]
  UFG::qString result; // [rsp+50h] [rbp-38h]

  v2 = dest_filename;
  v3 = src_filename;
  v4 = UFG::qFileSystem::MapFilenameToDevice(&UFG::gQuarkFileSystem, src_filename);
  v5 = UFG::qFileSystem::MapFilenameToDevice(&UFG::gQuarkFileSystem, v2);
  UFG::qFileSystem::MapFilename(&UFG::gQuarkFileSystem, &result, 0, v3);
  UFG::qFileSystem::MapFilename(&UFG::gQuarkFileSystem, &v12, 0, v2);
  if ( v4 == v5 )
    v6 = v4->vfptr->RenameFilename(v4, result.mData, v12.mData);
  else
    v6 = 0;
  if ( v12.mData != UFG::qString::sEmptyString && v12.mData )
    UFG::qMemoryPool::Free(UFG::gMainMemoryPool, v12.mData);
  v12.mMagic = 0;
  v7 = v12.mPrev;
  v8 = v12.mNext;
  v12.mPrev->mNext = v12.mNext;
  v8->mPrev = v7;
  v12.mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&v12;
  v12.mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&v12;
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
  const char *v1; // rbx
  UFG::qFileDevice *v2; // rdi
  bool v3; // bl
  UFG::qNode<UFG::qString,UFG::qString> *v4; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *v5; // rax
  UFG::qString result; // [rsp+28h] [rbp-30h]

  v1 = filename;
  v2 = UFG::qFileSystem::MapFilenameToDevice(&UFG::gQuarkFileSystem, filename);
  UFG::qFileSystem::MapFilename(&UFG::gQuarkFileSystem, &result, 0, v1);
  if ( unk_14235ACD8 || !v2 )
    v3 = 0;
  else
    v3 = v2->vfptr->DeleteFilename(v2, result.mData);
  if ( result.mData != UFG::qString::sEmptyString && result.mData )
    UFG::qMemoryPool::Free(UFG::gMainMemoryPool, result.mData);
  v4 = result.mPrev;
  v5 = result.mNext;
  result.mPrev->mNext = result.mNext;
  v5->mPrev = v4;
  return v3;
}

// File Line: 3345
// RVA: 0x183630
_BOOL8 __fastcall UFG::qFileExists(const char *filename)
{
  const char *v1; // rbx
  UFG::qFileDevice *v2; // rdi
  bool v3; // bl
  UFG::qNode<UFG::qString,UFG::qString> *v4; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *v5; // rax
  UFG::qString result; // [rsp+28h] [rbp-30h]

  v1 = filename;
  v2 = UFG::qFileSystem::MapFilenameToDevice(&UFG::gQuarkFileSystem, filename);
  UFG::qFileSystem::MapFilename(&UFG::gQuarkFileSystem, &result, 0, v1);
  if ( unk_14235ACD8 || !v2 )
    v3 = 0;
  else
    v3 = v2->vfptr->FilenameExists(v2, result.mData);
  if ( result.mData != UFG::qString::sEmptyString && result.mData )
    UFG::qMemoryPool::Free(UFG::gMainMemoryPool, result.mData);
  v4 = result.mPrev;
  v5 = result.mNext;
  result.mPrev->mNext = result.mNext;
  v5->mPrev = v4;
  return v3;
}

// File Line: 3410
// RVA: 0x184570
__int64 __fastcall UFG::qGetFileSize(const char *filename)
{
  const char *v1; // rbx
  UFG::qFileDevice *v2; // rdi
  __int64 v3; // rbx
  UFG::qNode<UFG::qString,UFG::qString> *v4; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *v5; // rax
  UFG::qString result; // [rsp+28h] [rbp-30h]

  v1 = filename;
  v2 = UFG::qFileSystem::MapFilenameToDevice(&UFG::gQuarkFileSystem, filename);
  UFG::qFileSystem::MapFilename(&UFG::gQuarkFileSystem, &result, 0, v1);
  if ( unk_14235ACD8 || !v2 )
    v3 = 0i64;
  else
    v3 = v2->vfptr->GetFilenameSize(v2, result.mData);
  if ( result.mData != UFG::qString::sEmptyString && result.mData )
    UFG::qMemoryPool::Free(UFG::gMainMemoryPool, result.mData);
  v4 = result.mPrev;
  v5 = result.mNext;
  result.mPrev->mNext = result.mNext;
  v5->mPrev = v4;
  return v3;
}

// File Line: 3425
// RVA: 0x184630
void __fastcall UFG::qGetFileSizeAsync(const char *filename, void (__fastcall *callback)(UFG::qFileOp *, void *), void *callback_param, UFG::qFilePriorityLevel priority)
{
  UFG::qFilePriorityLevel v4; // edi
  void *v5; // rbx
  void (__fastcall *v6)(UFG::qFileOp *, void *); // rsi
  const char *v7; // rbp
  UFG::qMemoryPool *v8; // rcx
  UFG::allocator::free_link *v9; // rax
  __int64 v10; // rax
  __int64 v11; // rbx
  __int64 v12; // rcx
  __int64 v13; // rax

  v4 = priority;
  v5 = callback_param;
  v6 = callback;
  v7 = filename;
  v8 = UFG::gMainMemoryPool;
  if ( !UFG::gMainMemoryPool )
  {
    UFG::InternalSetupMainMemoryPool((UFG *)UFG::gMainMemoryPool);
    v8 = UFG::gMainMemoryPool;
  }
  v9 = UFG::qMemoryPool::Allocate(v8, 0x170ui64, "qFileOp.OP_GET_SIZE", 0i64, 1u);
  if ( v9 )
  {
    UFG::qFileOp::qFileOp((UFG::qFileOp *)v9, v7, OP_GET_SIZE, v6, v5);
    v11 = v10;
  }
  else
  {
    v11 = 0i64;
  }
  v12 = *(_QWORD *)(v11 + 16);
  if ( v12 )
  {
    (*(void (__fastcall **)(__int64, __int64, _QWORD))(*(_QWORD *)v12 + 24i64))(v12, v11, (unsigned int)v4);
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
  const char *v1; // rbx
  UFG::qFileDevice *v2; // rdi
  __int64 v3; // rbx
  UFG::qNode<UFG::qString,UFG::qString> *v4; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *v5; // rax
  UFG::qString result; // [rsp+28h] [rbp-30h]

  v1 = filename;
  v2 = UFG::qFileSystem::MapFilenameToDevice(&UFG::gQuarkFileSystem, filename);
  UFG::qFileSystem::MapFilename(&UFG::gQuarkFileSystem, &result, 0, v1);
  if ( unk_14235ACD8 || !v2 )
    v3 = 0i64;
  else
    v3 = v2->vfptr->GetFilenameTime(v2, result.mData);
  if ( result.mData != UFG::qString::sEmptyString && result.mData )
    UFG::qMemoryPool::Free(UFG::gMainMemoryPool, result.mData);
  v4 = result.mPrev;
  v5 = result.mNext;
  result.mPrev->mNext = result.mNext;
  v5->mPrev = v4;
  return v3;
}

// File Line: 3465
// RVA: 0x18ABF0
_BOOL8 __fastcall UFG::qSetFileTime(const char *filename, unsigned __int64 file_time)
{
  unsigned __int64 v2; // rsi
  const char *v3; // rbx
  UFG::qFileDevice *v4; // rdi
  bool v5; // bl
  UFG::qNode<UFG::qString,UFG::qString> *v6; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *v7; // rax
  UFG::qString result; // [rsp+28h] [rbp-30h]

  v2 = file_time;
  v3 = filename;
  v4 = UFG::qFileSystem::MapFilenameToDevice(&UFG::gQuarkFileSystem, filename);
  UFG::qFileSystem::MapFilename(&UFG::gQuarkFileSystem, &result, 0, v3);
  if ( unk_14235ACD8 || !v4 )
    v5 = 0;
  else
    v5 = v4->vfptr->SetFilenameTime(v4, result.mData, v2);
  if ( result.mData != UFG::qString::sEmptyString && result.mData )
    UFG::qMemoryPool::Free(UFG::gMainMemoryPool, result.mData);
  v6 = result.mPrev;
  v7 = result.mNext;
  result.mPrev->mNext = result.mNext;
  v7->mPrev = v6;
  return v5;
}

// File Line: 3513
// RVA: 0x189780
__int64 __fastcall UFG::qRead(const char *filename, void *buffer, __int64 num_bytes, __int64 seek_position)
{
  __int64 v4; // rbp
  __int64 v5; // rsi
  void *v6; // r14
  UFG::qFile *v8; // rax
  __int64 v9; // rbx
  UFG::qFile *v10; // rdi

  v4 = seek_position;
  v5 = num_bytes;
  v6 = buffer;
  if ( !num_bytes )
    return 0i64;
  v8 = UFG::qOpen(filename, QACCESS_READ, 1);
  v9 = -1i64;
  v10 = v8;
  if ( v8 )
  {
    v9 = UFG::qRead(v8, v6, v5, v4, 0);
    UFG::qClose(v10);
  }
  return v9;
}

// File Line: 3537
// RVA: 0x189C20
void __fastcall UFG::qReadAsync(const char *filename, void *buffer, __int64 num_bytes, __int64 seek_position, void (__fastcall *callback)(UFG::qFileOp *, void *), void *callback_param, UFG::qFilePriorityLevel priority)
{
  __int64 v7; // rdi
  __int64 v8; // rsi
  void *v9; // rbp
  const char *v10; // rbx
  UFG::qMemoryPool *v11; // rcx
  UFG::allocator::free_link *v12; // rax
  __int64 v13; // rax
  __int64 v14; // rbx
  __int64 v15; // rcx
  __int64 v16; // rax

  v7 = seek_position;
  v8 = num_bytes;
  v9 = buffer;
  v10 = filename;
  v11 = UFG::gMainMemoryPool;
  if ( !UFG::gMainMemoryPool )
  {
    UFG::InternalSetupMainMemoryPool((UFG *)UFG::gMainMemoryPool);
    v11 = UFG::gMainMemoryPool;
  }
  v12 = UFG::qMemoryPool::Allocate(v11, 0x170ui64, "qFileOp.OP_OPEN_READ_CLOSE", 0i64, 1u);
  if ( v12 )
  {
    UFG::qFileOp::qFileOp((UFG::qFileOp *)v12, v10, OP_OPEN_READ_CLOSE, callback, callback_param);
    v14 = v13;
  }
  else
  {
    v14 = 0i64;
  }
  *(_DWORD *)(v14 + 128) = 0;
  *(_QWORD *)(v14 + 136) = v7;
  *(_QWORD *)(v14 + 120) = v9;
  *(_QWORD *)(v14 + 144) = v8;
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
__int64 __fastcall UFG::qWrite(const char *filename, const void *buffer, __int64 num_bytes, __int64 seek_offset, UFG::qFileSeekType seek_type, bool *not_enough_space)
{
  __int64 v6; // r14
  __int64 v7; // rsi
  const void *v8; // r15
  UFG::qFile *v10; // rax
  __int64 v11; // rdi
  UFG::qFile *v12; // rbp

  v6 = seek_offset;
  v7 = num_bytes;
  v8 = buffer;
  if ( not_enough_space )
    *not_enough_space = 0;
  if ( !num_bytes )
    return 0i64;
  v10 = UFG::qOpen(filename, QACCESS_WRITE, 1);
  v11 = -1i64;
  v12 = v10;
  if ( v10 )
  {
    v11 = UFG::qWrite(v10, v8, v7, v6, seek_type, not_enough_space);
    UFG::qClose(v12);
  }
  return v11;
}

// File Line: 3585
// RVA: 0x18D170
void __fastcall UFG::qWriteAsync(const char *filename, const void *buffer, __int64 num_bytes, __int64 seek_offset, UFG::qFileSeekType seek_type, void (__fastcall *callback)(UFG::qFileOp *, void *), void *callback_param, UFG::qFilePriorityLevel priority)
{
  __int64 v8; // rdi
  __int64 v9; // rsi
  const void *v10; // rbp
  const char *v11; // rbx
  UFG::qMemoryPool *v12; // rcx
  UFG::allocator::free_link *v13; // rax
  __int64 v14; // rax
  __int64 v15; // rbx
  __int64 v16; // rcx
  __int64 v17; // rax

  v8 = seek_offset;
  v9 = num_bytes;
  v10 = buffer;
  v11 = filename;
  v12 = UFG::gMainMemoryPool;
  if ( !UFG::gMainMemoryPool )
  {
    UFG::InternalSetupMainMemoryPool((UFG *)UFG::gMainMemoryPool);
    v12 = UFG::gMainMemoryPool;
  }
  v13 = UFG::qMemoryPool::Allocate(v12, 0x170ui64, "qFileOp.OP_OPEN_WRITE_CLOSE", 0i64, 1u);
  if ( v13 )
  {
    UFG::qFileOp::qFileOp((UFG::qFileOp *)v13, v11, OP_OPEN_WRITE_CLOSE, callback, callback_param);
    v15 = v14;
  }
  else
  {
    v15 = 0i64;
  }
  *(_DWORD *)(v15 + 128) = seek_type;
  *(_QWORD *)(v15 + 136) = v8;
  *(_QWORD *)(v15 + 120) = v10;
  *(_QWORD *)(v15 + 144) = v9;
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
__int64 __fastcall UFG::qWriteAppend(const char *filename, const void *buffer, __int64 num_bytes, __int64 seek_offset, UFG::qFileSeekType seek_type, bool *not_enough_space)
{
  __int64 v6; // r14
  __int64 v7; // rsi
  const void *v8; // r15
  UFG::qFile *v10; // rax
  __int64 v11; // rdi
  UFG::qFile *v12; // rbp

  v6 = seek_offset;
  v7 = num_bytes;
  v8 = buffer;
  if ( not_enough_space )
    *not_enough_space = 0;
  if ( !num_bytes )
    return 0i64;
  v10 = UFG::qOpen(filename, QACCESS_APPEND, 1);
  v11 = -1i64;
  v12 = v10;
  if ( v10 )
  {
    v11 = UFG::qWrite(v10, v8, v7, v6, seek_type, not_enough_space);
    UFG::qClose(v12);
  }
  return v11;
}

// File Line: 3653
// RVA: 0x18D2A0
__int64 __fastcall UFG::qWriteWithBackup(const char *filename, const void *buffer, __int64 num_bytes)
{
  __int64 v3; // r14
  const void *v4; // r15
  const char *v5; // rdi
  const char *v6; // rbx
  char v7; // al
  int v8; // ebx
  __int64 v9; // rbx
  UFG::qFile *v10; // rax
  UFG::qFile *v11; // rsi
  UFG::qNode<UFG::qString,UFG::qString> *v12; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *v13; // rax
  UFG::qNode<UFG::qString,UFG::qString> *v14; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *v15; // rax
  UFG::qString v17; // [rsp+20h] [rbp-11h]
  UFG::qString v18; // [rsp+48h] [rbp+17h]

  v3 = num_bytes;
  v4 = buffer;
  v5 = filename;
  if ( !filename || !*filename || !buffer )
    return -1i64;
  v6 = filename;
  do
    v7 = *v6++;
  while ( v7 );
  v8 = (_DWORD)v6 - (_DWORD)filename;
  v17.mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&v17;
  *(_QWORD *)&v17.mMagic = 16909060i64;
  v17.mData = (char *)UFG::qString::sEmptyString;
  *(_QWORD *)&v17.mStringHash32 = -1i64;
  v18.mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&v18;
  v18.mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&v18;
  *(_QWORD *)&v18.mMagic = 16909060i64;
  v18.mData = (char *)UFG::qString::sEmptyString;
  *(_QWORD *)&v18.mStringHash32 = -1i64;
  UFG::qString::Set(&v17, filename, v8 - 1, ".tmp", 4);
  UFG::qString::Set(&v18, v5, v8 - 1, ".bak", 4);
  UFG::qDeleteFile(v17.mData);
  if ( v3 )
  {
    v10 = UFG::qOpen(v17.mData, QACCESS_WRITE, 1);
    v11 = v10;
    v9 = -1i64;
    if ( v10 )
    {
      v9 = UFG::qWrite(v10, v4, v3, 0i64, QSEEK_CUR, 0i64);
      UFG::qClose(v11);
    }
    if ( v9 != v3 )
      goto LABEL_14;
  }
  else
  {
    v9 = 0i64;
  }
  UFG::qDeleteFile(v18.mData);
  UFG::qRenameFile(v5, v18.mData);
  if ( (unsigned __int8)UFG::qRenameFile(v17.mData, v5) )
  {
    UFG::qDeleteFile(v18.mData);
    goto LABEL_15;
  }
  UFG::qRenameFile(v18.mData, v5);
LABEL_14:
  UFG::qDeleteFile(v17.mData);
  v9 = -1i64;
LABEL_15:
  if ( v18.mData != UFG::qString::sEmptyString && v18.mData )
    UFG::qMemoryPool::Free(UFG::gMainMemoryPool, v18.mData);
  v18.mMagic = 0;
  v12 = v18.mPrev;
  v13 = v18.mNext;
  v18.mPrev->mNext = v18.mNext;
  v13->mPrev = v12;
  v18.mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&v18;
  v18.mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&v18;
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
  v17.mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&v17;
  v17.mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&v17;
  return v9;
}

// File Line: 3777
// RVA: 0x189820
__int64 __fastcall UFG::qReadAndDecompress(UFG::qFile *file, void *buffer, __int64 num_bytes, __int64 seek_offset, UFG::qFileSeekType seek_type, __int64 read_offset, __int64 read_bytes, __int64 read_data_offset, void *scratch_buffer, __int64 scratch_size, bool in_place)
{
  void *v11; // r14
  UFG::qFile *v12; // r10
  __int64 v14; // rax
  __int64 v15; // rbp
  __int64 v16; // r15
  char *v17; // rcx
  __int64 v18; // rdx
  void *v19; // r12
  signed __int64 v20; // rbx
  __int64 v21; // rax
  char *v22; // [rsp+68h] [rbp+10h]

  v11 = buffer;
  v12 = file;
  if ( !buffer )
    return -1i64;
  v14 = read_offset + read_bytes;
  if ( !scratch_buffer )
  {
    if ( num_bytes >= v14 )
    {
      v16 = read_data_offset;
      v17 = (char *)buffer + read_offset;
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
  v17 = (char *)scratch_buffer + read_offset;
  v18 = read_bytes + read_data_offset;
  v22 = (char *)scratch_buffer + read_offset;
  if ( in_place == 1 )
  {
    v19 = scratch_buffer;
    goto LABEL_11;
  }
LABEL_10:
  v15 = num_bytes;
  v19 = v11;
LABEL_11:
  v20 = -1i64;
  if ( UFG::qRead(v12, v17, v18, seek_offset, seek_type) == read_bytes + v16 )
  {
    v21 = UFG::qDecompressLZ((UFG::qCompressHeader *)&v22[v16], read_bytes, v19, v15);
    v20 = v21;
    if ( scratch_buffer )
    {
      if ( in_place == 1 )
        UFG::qMemCopy(v11, scratch_buffer, v21);
    }
  }
  return v20;
}

// File Line: 3859
// RVA: 0x189960
void __fastcall UFG::qReadAndDecompressAsync(UFG::qFile *file, void *buffer, __int64 num_bytes, __int64 seek_offset, UFG::qFileSeekType seek_type, __int64 read_offset, __int64 read_bytes, __int64 read_data_offset, void *scratch_buffer, __int64 scratch_size, bool in_place, void (__fastcall *callback)(UFG::qFileOp *, void *), void *callback_param, UFG::qFilePriorityLevel priority)
{
  __int64 v14; // rdi
  __int64 v15; // rsi
  void *v16; // rbp
  UFG::qFile *v17; // rbx
  UFG::qMemoryPool *v18; // rcx
  UFG::allocator::free_link *v19; // rax
  __int64 v20; // rax
  __int64 v21; // rbx
  __int64 v22; // rcx
  __int64 v23; // rax

  v14 = seek_offset;
  v15 = num_bytes;
  v16 = buffer;
  v17 = file;
  v18 = UFG::gMainMemoryPool;
  if ( !UFG::gMainMemoryPool )
  {
    UFG::InternalSetupMainMemoryPool((UFG *)UFG::gMainMemoryPool);
    v18 = UFG::gMainMemoryPool;
  }
  v19 = UFG::qMemoryPool::Allocate(v18, 0x170ui64, "qFileOp.OP_READ_AND_DECOMPRESS", 0i64, 1u);
  if ( v19 )
  {
    UFG::qFileOp::qFileOp((UFG::qFileOp *)v19, v17, OP_READ_AND_DECOMPRESS, callback, callback_param);
    v21 = v20;
  }
  else
  {
    v21 = 0i64;
  }
  *(_DWORD *)(v21 + 128) = seek_type;
  *(_QWORD *)(v21 + 136) = v14;
  *(_QWORD *)(v21 + 120) = v16;
  *(_QWORD *)(v21 + 144) = v15;
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
char __fastcall UFG::FileOpFlushBufferCallback(void *param, __int64 position, void *buffer, __int64 buffer_size)
{
  __int64 v4; // rdi
  _QWORD *v5; // rbx
  UFG::qFile *v6; // rcx
  __int64 v7; // rax
  _BYTE *v8; // rcx
  bool not_enough_space; // [rsp+40h] [rbp+8h]

  v4 = buffer_size;
  v5 = param;
  if ( *((_BYTE *)param + 16) )
  {
    v6 = *(UFG::qFile **)param;
    not_enough_space = 0;
    v7 = UFG::qWrite(v6, buffer, buffer_size, position, 0, &not_enough_space);
    if ( not_enough_space == 1 )
    {
      v8 = (_BYTE *)v5[1];
      if ( v8 )
        *v8 = 1;
      *((_BYTE *)v5 + 16) = 0;
    }
    if ( v7 != v4 )
      *((_BYTE *)v5 + 16) = 0;
  }
  return 1;
}

// File Line: 3937
// RVA: 0x18D000
__int64 __fastcall UFG::qWriteAndCompress(UFG::qFile *file, void *buffer, __int64 num_bytes, void *scratch_buffer, __int64 scratch_size, bool *not_enough_space)
{
  void *v6; // rsi
  __int64 v7; // rbp
  void *v8; // rbx
  UFG::qFile *v9; // rdi
  __int64 v10; // rdx
  bool v12; // [rsp+30h] [rbp-28h]
  UFG::qFile *callback_param; // [rsp+38h] [rbp-20h]
  bool *v14; // [rsp+40h] [rbp-18h]
  char v15; // [rsp+48h] [rbp-10h]

  v6 = scratch_buffer;
  v7 = num_bytes;
  v8 = buffer;
  v9 = file;
  if ( !UFG::qWaitForOpenFileHandle(file) || !v8 )
    return -1i64;
  v14 = &v12;
  v12 = 0;
  callback_param = v9;
  v15 = 1;
  v10 = UFG::qCompressBufferedLZ(
          v8,
          v7,
          v6,
          scratch_size,
          (bool (__fastcall *)(void *, __int64, void *, __int64))UFG::FileOpFlushBufferCallback,
          &callback_param);
  if ( not_enough_space )
    *not_enough_space = v12;
  if ( !v15 )
    v10 = -1i64;
  return v10;
}

// File Line: 4138
// RVA: 0x184380
unsigned __int64 __fastcall UFG::qGetFileChecksum64(const char *filename, unsigned __int64 previous_checksum)
{
  unsigned __int64 v2; // rbx
  UFG::qFile *v3; // rax
  UFG::qFile *v4; // rbp
  __int64 v5; // rsi
  UFG::qMemoryPool *v6; // rcx
  signed __int64 v7; // r14
  UFG::allocator::free_link *v8; // r15
  __int64 v9; // rdi
  unsigned int v10; // er8
  UFG::allocator::free_link *v11; // rdx
  char v12; // al

  v2 = previous_checksum;
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
            v12 = (char)v11->mNext;
            ++v10;
            v11 = (UFG::allocator::free_link *)((char *)v11 + 1);
            v2 = (v2 >> 8) ^ sCrcTable64[(unsigned __int8)(v2 ^ v12)];
          }
          while ( v10 < (unsigned __int64)(unsigned int)v9 );
        }
      }
      UFG::qMemoryPool::Free(UFG::gMainMemoryPool, v8);
    }
    UFG::qClose(v4);
  }
  return v2;
}

// File Line: 4178
// RVA: 0x184200
__int64 __fastcall UFG::qGetFileChecksum32(const char *filename, unsigned int previous_checksum)
{
  unsigned int v2; // ebx
  UFG::qFile *v3; // rax
  UFG::qFile *v4; // rbp
  __int64 v5; // rsi
  UFG::qMemoryPool *v6; // rcx
  signed __int64 v7; // r14
  UFG::allocator::free_link *v8; // r15
  __int64 v9; // rdi
  unsigned int v10; // er8
  UFG::allocator::free_link *v11; // rdx
  char v12; // al

  v2 = previous_checksum;
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
            v12 = (char)v11->mNext;
            ++v10;
            v11 = (UFG::allocator::free_link *)((char *)v11 + 1);
            v2 = (v2 << 8) ^ sCrcTable32[(unsigned __int8)(v12 ^ HIBYTE(v2))];
          }
          while ( v10 < (unsigned __int64)(unsigned int)v9 );
        }
      }
      UFG::qMemoryPool::Free(UFG::gMainMemoryPool, v8);
    }
    UFG::qClose(v4);
  }
  return v2;
}

// File Line: 4356
// RVA: 0x182810
char __fastcall UFG::qCopyFile(const char *src_filename, const char *dest_filename)
{
  const char *v2; // rdi
  const char *v3; // rbx
  UFG::qFile *v4; // r12
  UFG::qFile *v5; // rax
  char v6; // bp
  UFG::qFile *v7; // rsi
  __int64 v8; // rdi
  signed __int64 v9; // r15
  char *v10; // r14
  __int64 v11; // rbx

  v2 = dest_filename;
  v3 = src_filename;
  if ( !dest_filename || !*dest_filename || !src_filename || !*src_filename || !UFG::qFileExists(src_filename) )
    return 0;
  v4 = UFG::qOpen(v2, QACCESS_WRITE, 1);
  v5 = UFG::qOpen(v3, QACCESS_READ, 1);
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
UFG::allocator::free_link *__fastcall UFG::qReadEntireFile(const char *filename, __int64 *loaded_size, UFG::qMemoryPool *memory_pool, unsigned __int64 allocation_params, const char *name)
{
  unsigned __int64 v5; // r15
  UFG::qMemoryPool *v6; // rbp
  __int64 *v7; // rsi
  const char *v8; // rdi
  __int64 v9; // rax
  __int64 v10; // rbx
  UFG::qFile *v11; // rsi
  const char *v12; // r8
  UFG::allocator::free_link *v13; // rax
  UFG::allocator::free_link *v14; // rdi
  char dest; // [rsp+30h] [rbp-188h]

  v5 = allocation_params;
  v6 = memory_pool;
  v7 = loaded_size;
  v8 = filename;
  if ( unk_14235ACD8 || !filename || !*filename )
    return 0i64;
  v9 = UFG::qGetFileSize(filename);
  v10 = v9;
  if ( v7 )
    *v7 = v9;
  if ( v9 <= 0 )
    return 0i64;
  if ( !v6 )
    v6 = UFG::gMainMemoryPool;
  v11 = UFG::qOpen(v8, QACCESS_READ, 1);
  if ( !v11 )
    return 0i64;
  if ( !name )
    UFG::qSPrintf(&dest, "qReadEntireFile('%s')", v8);
  v12 = &dest;
  if ( name )
    v12 = name;
  v13 = UFG::qMemoryPool::Allocate(v6, v10 + 1, v12, v5, 1u);
  v14 = v13;
  if ( !v13 )
  {
    UFG::qClose(v11);
    return 0i64;
  }
  if ( (signed int)UFG::qRead(v11, v13, v10, 0i64, QSEEK_CUR) != v10 )
  {
    UFG::qClose(v11);
    UFG::qMemoryPool::Free(v6, v14);
    return 0i64;
  }
  UFG::qClose(v11);
  *((_BYTE *)&v14->mNext + v10) = 0;
  return v14;
}

// File Line: 4640
// RVA: 0x189EA0
void __fastcall UFG::qReadEntireFileAsync(const char *filename, void (__fastcall *callback)(UFG::qFileOp *, void *), void *callback_param, UFG::qMemoryPool *memory_pool, unsigned __int64 allocation_params, const char *name, UFG::qFilePriorityLevel priority)
{
  UFG::qMemoryPool *v7; // rdi
  void *v8; // rbx
  void (__fastcall *v9)(UFG::qFileOp *, void *); // rsi
  const char *v10; // rbp
  UFG::qMemoryPool *v11; // rcx
  UFG::allocator::free_link *v12; // rax
  __int64 v13; // rax
  __int64 v14; // rbx
  const char *v15; // r10
  const char *v16; // rdx
  char v17; // al
  int v18; // edx
  __int64 v19; // rcx
  __int64 v20; // rax

  v7 = memory_pool;
  v8 = callback_param;
  v9 = callback;
  v10 = filename;
  v11 = UFG::gMainMemoryPool;
  if ( !UFG::gMainMemoryPool )
  {
    UFG::InternalSetupMainMemoryPool((UFG *)UFG::gMainMemoryPool);
    v11 = UFG::gMainMemoryPool;
  }
  v12 = UFG::qMemoryPool::Allocate(v11, 0x170ui64, "qFileOp.OP_READ_ENTIRE_FILE", 0i64, 1u);
  if ( v12 )
  {
    UFG::qFileOp::qFileOp((UFG::qFileOp *)v12, v10, OP_READ_ENTIRE_FILE, v9, v8);
    v14 = v13;
  }
  else
  {
    v14 = 0i64;
  }
  *(_QWORD *)(v14 + 264) = v7;
  *(_QWORD *)(v14 + 216) = allocation_params;
  v15 = "ReadEntireFileAsync";
  if ( name )
    v15 = name;
  if ( v15 && v15 != UFG::qString::sEmptyString )
  {
    v16 = v15;
    do
      v17 = *v16++;
    while ( v17 );
    v18 = (_DWORD)v16 - (_DWORD)v15 - 1;
  }
  else
  {
    v18 = 0;
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
void __fastcall UFG::qFreeEntireFile(void *ptr, UFG::qMemoryPool *memory_pool)
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
  const char *v2; // rdi
  UFG::qString *v3; // rbx
  __int64 v4; // rbp
  UFG::qMemoryPool *v5; // r14
  UFG::qFile *v6; // rsi
  UFG::allocator::free_link *v7; // rax
  char *v8; // rdi
  UFG::qString *v9; // rax
  char *v10; // rcx
  char v11; // al
  int v12; // ecx
  char dest; // [rsp+40h] [rbp-198h]

  v2 = filename;
  v3 = result;
  result->mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&result->mPrev;
  result->mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&result->mPrev;
  result->mMagic = 16909060;
  result->mData = (char *)UFG::qString::sEmptyString;
  result->mLength = 0;
  *(_QWORD *)&result->mStringHash32 = -1i64;
  if ( unk_14235ACD8 || !filename || !*filename )
    return result;
  v4 = UFG::qGetFileSize(filename);
  if ( v4 <= 0 )
    return v3;
  v5 = UFG::gMainMemoryPool;
  v6 = UFG::qOpen(v2, QACCESS_READ, 1);
  if ( !v6 )
    return v3;
  UFG::qSPrintf(&dest, "qReadEntireFile('%s')", v2);
  v7 = UFG::qMemoryPool::Allocate(v5, v4 + 1, &dest, 0i64, 1u);
  v8 = (char *)v7;
  if ( !v7 )
  {
    UFG::qClose(v6);
    return v3;
  }
  if ( (signed int)UFG::qRead(v6, v7, v4, 0i64, QSEEK_CUR) == v4 )
  {
    UFG::qClose(v6);
    v8[v4] = 0;
    if ( v8 == UFG::qString::sEmptyString )
    {
      v12 = 0;
    }
    else
    {
      v10 = v8;
      do
        v11 = *v10++;
      while ( v11 );
      v12 = (_DWORD)v10 - (_DWORD)v8 - 1;
    }
    UFG::qString::Set(v3, v8, v12, 0i64, 0);
    UFG::qMemoryPool::Free(UFG::gMainMemoryPool, v8);
    v9 = v3;
  }
  else
  {
    UFG::qClose(v6);
    UFG::qMemoryPool::Free(v5, v8);
    v9 = v3;
  }
  return v9;
}

