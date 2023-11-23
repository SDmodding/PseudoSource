// File Line: 25
// RVA: 0xA340E0
void __fastcall UFG::HDDmanager::HDDmanager(UFG::HDDmanager *this)
{
  UFG::HDDmanager *i; // rax
  __int64 v3; // r8
  UFG::HddFileContainer *mFileContainer; // rdx

  UFG::qMutex::qMutex(&this->mSaveDataFileMutex, &customCaption);
  this->mSaveDataFiles.mNode.mPrev = &this->mSaveDataFiles.mNode;
  this->mSaveDataFiles.mNode.mNext = &this->mSaveDataFiles.mNode;
  this->mStatus = eHDD_STATUS_IDLE;
  this->mReCreateData = 0;
  UFG::qMemSet(this->mSaveDataExists, 0, 0x23u);
  this->mReCreateData = 0;
  this->m_eSaveLoadPermission = -1;
  UFG::qMutex::Lock((LPCRITICAL_SECTION)&this->mSaveDataFileMutex);
  for ( i = (UFG::HDDmanager *)this->mSaveDataFiles.mNode.mNext;
        i != (UFG::HDDmanager *)&this->mSaveDataFiles;
        i = (UFG::HDDmanager *)this->mSaveDataFiles.mNode.mNext )
  {
    v3 = *(_QWORD *)&i->mStatus;
    mFileContainer = i->mFileContainer;
    *(_QWORD *)(v3 + 8) = mFileContainer;
    *(_QWORD *)&mFileContainer->TotalFileSize = v3;
    *(_QWORD *)&i->mStatus = i;
    i->mFileContainer = (UFG::HddFileContainer *)i;
  }
  UFG::qMutex::Unlock((LPCRITICAL_SECTION)&this->mSaveDataFileMutex);
}

// File Line: 40
// RVA: 0xA34580
void UFG::HDDmanager::Instantiate(void)
{
  UFG::allocator::free_link *v0; // rax

  if ( !UFG::HDDmanager::mInstance )
  {
    v0 = UFG::qMalloc(0xA0ui64, "HDDmanager", 0i64);
    if ( v0 )
      UFG::HDDmanager::HDDmanager((UFG::HDDmanager *)v0);
    UFG::HDDmanager::mInstance = (UFG::HDDmanager *)v0;
  }
}

// File Line: 47
// RVA: 0xA34630
void UFG::HDDmanager::ShutDown(void)
{
  UFG::HDDmanager *v0; // rdi
  UFG::qList<UFG::qString,UFG::qString,1,0> *p_mSaveDataFiles; // rbx
  UFG::qNode<UFG::qString,UFG::qString> *mPrev; // rdx
  UFG::qNode<UFG::qString,UFG::qString> *mNext; // rax

  v0 = UFG::HDDmanager::mInstance;
  if ( UFG::HDDmanager::mInstance )
  {
    p_mSaveDataFiles = &UFG::HDDmanager::mInstance->mSaveDataFiles;
    UFG::qList<UFG::qString,UFG::qString,1,0>::DeleteNodes(&UFG::HDDmanager::mInstance->mSaveDataFiles);
    mPrev = p_mSaveDataFiles->mNode.mPrev;
    mNext = v0->mSaveDataFiles.mNode.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_mSaveDataFiles->mNode.mPrev = &p_mSaveDataFiles->mNode;
    v0->mSaveDataFiles.mNode.mNext = &v0->mSaveDataFiles.mNode;
    Scaleform::Lock::~Lock((LPCRITICAL_SECTION)&v0->mSaveDataFileMutex);
    operator delete[](v0);
  }
}

// File Line: 81
// RVA: 0xA34330
void __fastcall UFG::HDDmanager::HDDFileList(UFG::HDDmanager *this, void (__fastcall *callBack)(UFG::errCode))
{
  unsigned int i; // ebx
  UFG::GameSaveLoad *v4; // rax
  int v5[4]; // [rsp+30h] [rbp-48h] BYREF
  UFG::qString result; // [rsp+40h] [rbp-38h] BYREF

  if ( (this->m_eSaveLoadPermission & 1) != 0 )
  {
    this->mCallBack = callBack;
    UFG::HDDmanager::ResetSaveDataFileNameList(this);
    for ( i = 0; i < 8; ++i )
    {
      v4 = UFG::GameSaveLoad::Instance();
      UFG::GameSaveLoad::GetSlotFullFilename(v4, &result, i);
      if ( UFG::qFileExists(result.mData) )
        UFG::HDDmanager::AddSaveDataFileName(this, result.mData);
      UFG::qString::~qString(&result);
    }
    *(_QWORD *)&this->mError.eCode = 0i64;
    this->mError.eType = eHDD_STATUS_FILELIST;
    this->mStatus = eHDD_STATUS_IDLE;
    v5[0] = this->mError.eCode;
    v5[1] = this->mError.errArg;
    v5[2] = this->mError.eType;
    ((void (__fastcall *)(int *))this->mCallBack)(v5);
  }
}

// File Line: 120
// RVA: 0xA344A0
void __fastcall UFG::HDDmanager::HDDSave(
        UFG::HDDmanager *this,
        UFG::HddFileContainer *files,
        void (__fastcall *callBack)(UFG::errCode),
        UFG::qString *folderName_PS3,
        bool reCreate)
{
  if ( (this->m_eSaveLoadPermission & 2) != 0 && files && files->ContainerCount )
  {
    this->mFileContainer = files;
    this->mCallBack = callBack;
    this->mReCreateData = reCreate;
    UFG::HDDmanager::HDDSaveNext(this);
  }
  UFG::qString::~qString(folderName_PS3);
}

// File Line: 141
// RVA: 0xA34500
void __fastcall UFG::HDDmanager::HDDSaveNext(UFG::HDDmanager *this)
{
  hkResourceContainer *UsedSpace; // rdi

  UsedSpace = Scaleform::SysAllocPagedMalloc::GetUsedSpace((hkMemoryResourceContainer *)this->mFileContainer);
  UFG::qPrintf(
    "Writing %s, File Size %d\n",
    (const char *)UsedSpace[3].vfptr,
    *(unsigned int *)&UsedSpace[6].m_memSizeAndFlags);
  this->mStatus = eHDD_STATUS_SAVE;
  UFG::qWriteAsync(
    (const char *)UsedSpace[3].vfptr,
    UsedSpace[7].vfptr,
    *(unsigned int *)&UsedSpace[6].m_memSizeAndFlags,
    0i64,
    QSEEK_CUR,
    UFG::HDDmanager::onWriteAsyncCallback,
    this,
    QPRIORITY_NORMAL);
}

// File Line: 152
// RVA: 0xA34870
void __fastcall UFG::HDDmanager::onWriteAsyncCallback(UFG::qFileOp *file_op, UFG::HDDmanager *callback_param)
{
  UFG::HddFileContainer *mFileContainer; // rsi
  __int64 m_iSlotNum; // rax
  UFG::HDDmanager *v5; // rax
  UFG::HDDmanager *v6; // rdx
  UFG::eHDD_RETURN_CODE eCode; // eax
  int v8[6]; // [rsp+20h] [rbp-18h] BYREF

  mFileContainer = callback_param->mFileContainer;
  m_iSlotNum = UFG::HDDmanager::mInstance->m_iSlotNum;
  if ( file_op )
  {
    UFG::HDDmanager::mInstance->mSaveDataExists[m_iSlotNum] = 1;
    v5 = UFG::HDDmanager::mInstance;
    *(_QWORD *)&UFG::HDDmanager::mInstance->mError.eCode = 0i64;
  }
  else
  {
    UFG::HDDmanager::mInstance->mSaveDataExists[m_iSlotNum] = 0;
    v5 = UFG::HDDmanager::mInstance;
    *(_QWORD *)&UFG::HDDmanager::mInstance->mError.eCode = 2i64;
  }
  v5->mError.eType = eHDD_STATUS_SAVE;
  UFG::HddFileContainer::SetCurrentFileToNext(mFileContainer);
  if ( UFG::HddFileContainer::IsEndOfList(mFileContainer) )
  {
    v6 = UFG::HDDmanager::mInstance;
    eCode = UFG::HDDmanager::mInstance->mError.eCode;
    UFG::HDDmanager::mInstance->mStatus = eHDD_STATUS_IDLE;
    v8[0] = eCode;
    v8[1] = v6->mError.errArg;
    v8[2] = v6->mError.eType;
    ((void (__fastcall *)(int *))v6->mCallBack)(v8);
  }
  else
  {
    UFG::HDDmanager::HDDSaveNext(callback_param);
  }
}

// File Line: 188
// RVA: 0xA34400
void __fastcall UFG::HDDmanager::HDDLoad(
        UFG::HDDmanager *this,
        UFG::HddFileContainer *files,
        void (__fastcall *callBack)(UFG::errCode))
{
  if ( (this->m_eSaveLoadPermission & 1) != 0 && files )
  {
    if ( files->ContainerCount )
    {
      this->mFileContainer = files;
      this->mCallBack = callBack;
      UFG::HDDmanager::HDDLoadNext(this);
    }
  }
}

// File Line: 208
// RVA: 0xA34430
void __fastcall UFG::HDDmanager::HDDLoadNext(UFG::HDDmanager *this)
{
  hkResourceContainer *UsedSpace; // rbx

  UsedSpace = Scaleform::SysAllocPagedMalloc::GetUsedSpace((hkMemoryResourceContainer *)this->mFileContainer);
  UFG::qPrintf(
    "Loading %s File Size = %d\n",
    (const char *)UsedSpace[3].vfptr,
    *(unsigned int *)&UsedSpace[6].m_memSizeAndFlags);
  this->mStatus = eHDD_STATUS_LOAD;
  UFG::qReadEntireFileAsync(
    (const char *)UsedSpace[3].vfptr,
    UFG::HDDmanager::onReadAsyncCallback,
    this,
    0i64,
    0i64,
    0i64,
    QPRIORITY_NORMAL);
}

// File Line: 217
// RVA: 0xA346A0
void __fastcall UFG::HDDmanager::onReadAsyncCallback(UFG::qFileOp *file_op, UFG::HDDmanager *callback_param)
{
  __int64 m_iSlotNum; // r12
  UFG::HddFileContainer *mFileContainer; // r14
  UFG::qNode<UFG::HddSaveFile,UFG::HddSaveFile> *mNext; // rdi
  const char *mPrev; // rbx
  char *Filename; // rax
  unsigned int EntireFileSize; // eax
  unsigned int v10; // ebx
  UFG::allocator::free_link *v11; // rax
  char *EntireFileBuffer; // rax
  char *v13; // rax
  UFG::HDDmanager *v14; // rax
  UFG::HDDmanager *v15; // rax
  UFG::HDDmanager *v16; // rdx
  UFG::eHDD_RETURN_CODE eCode; // eax
  int v18[4]; // [rsp+20h] [rbp-38h] BYREF

  m_iSlotNum = UFG::HDDmanager::mInstance->m_iSlotNum;
  mFileContainer = callback_param->mFileContainer;
  mNext = mFileContainer->FileList.mNode.mNext;
  if ( mNext != (UFG::qNode<UFG::HddSaveFile,UFG::HddSaveFile> *)&mFileContainer->FileList )
  {
    while ( 1 )
    {
      mPrev = (const char *)mNext[3].mPrev;
      Filename = UFG::qFileOp::GetFilename(file_op);
      if ( !(unsigned int)UFG::qStringCompare(Filename, mPrev, -1) )
        break;
      mNext = mNext->mNext;
      if ( mNext == (UFG::qNode<UFG::HddSaveFile,UFG::HddSaveFile> *)&mFileContainer->FileList )
        goto LABEL_11;
    }
    if ( file_op && UFG::qFileOp::GetReadEntireFileBuffer(file_op) )
    {
      EntireFileSize = UFG::qFileOp::GetReadEntireFileSize(file_op);
      v10 = EntireFileSize;
      if ( LOBYTE(mNext[1].mPrev) )
      {
        v11 = UFG::qRealloc(mNext[7].mPrev, EntireFileSize, "Hdd File Data", 0i64);
        LODWORD(mNext[6].mNext) = v10;
        mNext[7].mPrev = (UFG::qNode<UFG::HddSaveFile,UFG::HddSaveFile> *)v11;
      }
      EntireFileBuffer = UFG::qFileOp::GetReadEntireFileBuffer(file_op);
      UFG::qMemCopy(mNext[7].mPrev, EntireFileBuffer, (unsigned int)mNext[6].mNext);
    }
    else
    {
      operator delete[](mNext[7].mPrev);
      mNext[7].mPrev = 0i64;
    }
  }
LABEL_11:
  if ( file_op && UFG::qFileOp::GetReadEntireFileBuffer(file_op) )
  {
    v13 = UFG::qFileOp::GetReadEntireFileBuffer(file_op);
    UFG::qFreeEntireFile(v13, 0i64);
    v14 = UFG::HDDmanager::mInstance;
    *(_QWORD *)&UFG::HDDmanager::mInstance->mError.eCode = 0i64;
    v14->mError.eType = eHDD_STATUS_LOAD;
    UFG::HDDmanager::mInstance->mSaveDataExists[m_iSlotNum] = 1;
  }
  else
  {
    v15 = UFG::HDDmanager::mInstance;
    *(_QWORD *)&UFG::HDDmanager::mInstance->mError.eCode = 3i64;
    v15->mError.eType = eHDD_STATUS_LOAD;
    UFG::HDDmanager::mInstance->mSaveDataExists[m_iSlotNum] = 0;
  }
  UFG::HddFileContainer::SetCurrentFileToNext(mFileContainer);
  if ( UFG::HddFileContainer::IsEndOfList(mFileContainer) )
  {
    v16 = UFG::HDDmanager::mInstance;
    eCode = UFG::HDDmanager::mInstance->mError.eCode;
    UFG::HDDmanager::mInstance->mStatus = eHDD_STATUS_IDLE;
    v18[0] = eCode;
    v18[1] = v16->mError.errArg;
    v18[2] = v16->mError.eType;
    ((void (__fastcall *)(int *))v16->mCallBack)(v18);
  }
  else
  {
    UFG::HDDmanager::HDDLoadNext(callback_param);
  }
}

// File Line: 277
// RVA: 0xA34240
void __fastcall UFG::HDDmanager::HDDDelete(
        UFG::HDDmanager *this,
        UFG::HddFileContainer *files,
        void (__fastcall *callBack)(UFG::errCode))
{
  if ( (this->m_eSaveLoadPermission & 2) != 0 && files )
  {
    if ( files->ContainerCount )
    {
      this->mFileContainer = files;
      this->mCallBack = callBack;
      this->mReCreateData = 0;
      UFG::HDDmanager::HDDDeleteNext(this);
    }
  }
}

// File Line: 302
// RVA: 0xA34270
void __fastcall UFG::HDDmanager::HDDDeleteNext(UFG::HDDmanager *this)
{
  hkResourceContainer *UsedSpace; // rdi
  UFG::HddFileContainer *mFileContainer; // rcx
  UFG::HDDmanager *v4; // rdx
  UFG::eHDD_RETURN_CODE eCode; // eax
  int v6[6]; // [rsp+20h] [rbp-18h] BYREF

  do
  {
    UsedSpace = Scaleform::SysAllocPagedMalloc::GetUsedSpace((hkMemoryResourceContainer *)this->mFileContainer);
    UFG::qPrintf("Deleting %s\n", (const char *)UsedSpace[3].vfptr);
    this->mStatus = eHDD_STATUS_DELETE;
    if ( UFG::qDeleteFile((const char *)UsedSpace[3].vfptr) )
    {
      *(_QWORD *)&this->mError.eCode = 3i64;
    }
    else
    {
      this->mSaveDataExists[this->m_iSlotNum] = 0;
      *(_QWORD *)&this->mError.eCode = 0i64;
    }
    mFileContainer = this->mFileContainer;
    this->mError.eType = eHDD_STATUS_DELETE;
    UFG::HddFileContainer::SetCurrentFileToNext(mFileContainer);
  }
  while ( !UFG::HddFileContainer::IsEndOfList(this->mFileContainer) );
  v4 = UFG::HDDmanager::mInstance;
  eCode = UFG::HDDmanager::mInstance->mError.eCode;
  UFG::HDDmanager::mInstance->mStatus = eHDD_STATUS_IDLE;
  v6[0] = eCode;
  v6[1] = v4->mError.errArg;
  v6[2] = v4->mError.eType;
  ((void (__fastcall *)(int *))v4->mCallBack)(v6);
}

