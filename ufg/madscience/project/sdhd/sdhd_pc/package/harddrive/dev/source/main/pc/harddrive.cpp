// File Line: 25
// RVA: 0xA340E0
void __fastcall UFG::HDDmanager::HDDmanager(UFG::HDDmanager *this)
{
  UFG::HDDmanager *v1; // rdi
  UFG::qList<UFG::qString,UFG::qString,1,0> *v2; // rbx
  UFG::qList<UFG::qString,UFG::qString,1,0> *v3; // rax
  UFG::qNode<UFG::qString,UFG::qString> *v4; // r8
  UFG::qNode<UFG::qString,UFG::qString> *v5; // rdx

  v1 = this;
  UFG::qMutex::qMutex(&this->mSaveDataFileMutex, &customWorldMapCaption);
  v2 = &v1->mSaveDataFiles;
  v2->mNode.mPrev = &v2->mNode;
  v2->mNode.mNext = &v2->mNode;
  v1->mStatus = 0;
  v1->mReCreateData = 0;
  UFG::qMemSet(v1->mSaveDataExists, 0, 0x23u);
  v1->mReCreateData = 0;
  v1->m_eSaveLoadPermission = -1;
  UFG::qMutex::Lock((LPCRITICAL_SECTION)&v1->mSaveDataFileMutex);
  v3 = (UFG::qList<UFG::qString,UFG::qString,1,0> *)v1->mSaveDataFiles.mNode.mNext;
  if ( v3 != &v1->mSaveDataFiles )
  {
    do
    {
      v4 = v3->mNode.mPrev;
      v5 = v3->mNode.mNext;
      v4->mNext = v5;
      v5->mPrev = v4;
      v3->mNode.mPrev = &v3->mNode;
      v3->mNode.mNext = &v3->mNode;
      v3 = (UFG::qList<UFG::qString,UFG::qString,1,0> *)v1->mSaveDataFiles.mNode.mNext;
    }
    while ( v3 != v2 );
  }
  UFG::qMutex::Unlock((LPCRITICAL_SECTION)&v1->mSaveDataFileMutex);
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
  UFG::qList<UFG::qString,UFG::qString,1,0> *v1; // rbx
  UFG::qNode<UFG::qString,UFG::qString> *v2; // rdx
  UFG::qNode<UFG::qString,UFG::qString> *v3; // rax

  v0 = UFG::HDDmanager::mInstance;
  if ( UFG::HDDmanager::mInstance )
  {
    v1 = &UFG::HDDmanager::mInstance->mSaveDataFiles;
    UFG::qList<UFG::qString,UFG::qString,1,0>::DeleteNodes(&UFG::HDDmanager::mInstance->mSaveDataFiles);
    v2 = v1->mNode.mPrev;
    v3 = v0->mSaveDataFiles.mNode.mNext;
    v2->mNext = v3;
    v3->mPrev = v2;
    v1->mNode.mPrev = &v1->mNode;
    v0->mSaveDataFiles.mNode.mNext = &v0->mSaveDataFiles.mNode;
    Scaleform::Lock::~Lock((LPCRITICAL_SECTION)&v0->mSaveDataFileMutex);
    operator delete[](v0);
  }
}

// File Line: 81
// RVA: 0xA34330
void __fastcall UFG::HDDmanager::HDDFileList(UFG::HDDmanager *this, void (__fastcall *callBack)(UFG::errCode *__struct_ptr))
{
  UFG::HDDmanager *v2; // rdi
  UFG::GameSaveLoad::eGameSlotNum v3; // ebx
  UFG::GameSaveLoad *v4; // rax
  UFG::eHDD_RETURN_CODE v5; // [rsp+30h] [rbp-48h]
  unsigned int v6; // [rsp+34h] [rbp-44h]
  UFG::eHDD_STATUS v7; // [rsp+38h] [rbp-40h]
  UFG::qString result; // [rsp+40h] [rbp-38h]

  v2 = this;
  if ( this->m_eSaveLoadPermission & 1 )
  {
    this->mCallBack = (void (__fastcall *)(UFG::errCode))callBack;
    UFG::HDDmanager::ResetSaveDataFileNameList(this);
    v3 = 0;
    do
    {
      v4 = UFG::GameSaveLoad::Instance();
      UFG::GameSaveLoad::GetSlotFullFilename(v4, &result, v3);
      if ( (unsigned __int8)UFG::qFileExists(result.mData) )
        UFG::HDDmanager::AddSaveDataFileName(v2, result.mData);
      UFG::qString::~qString(&result);
      ++v3;
    }
    while ( (unsigned int)v3 < 8 );
    *(_QWORD *)&v2->mError.eCode = 0i64;
    v2->mError.eType = 5;
    v2->mStatus = 0;
    v5 = v2->mError.eCode;
    v6 = v2->mError.errArg;
    v7 = v2->mError.eType;
    ((void (__fastcall *)(UFG::eHDD_RETURN_CODE *))v2->mCallBack)(&v5);
  }
}

// File Line: 120
// RVA: 0xA344A0
void __fastcall UFG::HDDmanager::HDDSave(UFG::HDDmanager *this, UFG::HddFileContainer *files, void (__fastcall *callBack)(UFG::errCode *__struct_ptr), UFG::qString *folderName_PS3, bool reCreate)
{
  UFG::qString *v5; // rbx

  v5 = folderName_PS3;
  if ( (this->m_eSaveLoadPermission >> 1) & 1 && files && files->ContainerCount >= 1 )
  {
    this->mFileContainer = files;
    this->mCallBack = (void (__fastcall *)(UFG::errCode))callBack;
    this->mReCreateData = reCreate;
    UFG::HDDmanager::HDDSaveNext(this);
  }
  UFG::qString::~qString(v5);
}

// File Line: 141
// RVA: 0xA34500
void __fastcall UFG::HDDmanager::HDDSaveNext(UFG::HDDmanager *this)
{
  UFG::HDDmanager *callback_param; // rbx
  hkResourceContainer *v2; // rdi

  callback_param = this;
  v2 = Scaleform::SysAllocPagedMalloc::GetUsedSpace((hkMemoryResourceContainer *)this->mFileContainer);
  UFG::qPrintf("Writing %s, File Size %d\n", v2[3].vfptr, *(unsigned int *)&v2[6].m_memSizeAndFlags);
  callback_param->mStatus = 2;
  UFG::qWriteAsync(
    (const char *)v2[3].vfptr,
    v2[7].vfptr,
    *(unsigned int *)&v2[6].m_memSizeAndFlags,
    0i64,
    QSEEK_CUR,
    UFG::HDDmanager::onWriteAsyncCallback,
    callback_param,
    QPRIORITY_NORMAL);
}

// File Line: 152
// RVA: 0xA34870
void __fastcall UFG::HDDmanager::onWriteAsyncCallback(UFG::qFileOp *file_op, void *callback_param)
{
  UFG::HddFileContainer *v2; // rsi
  UFG::HDDmanager *v3; // rdi
  __int64 v4; // rax
  UFG::HDDmanager *v5; // rax
  UFG::HDDmanager *v6; // rdx
  UFG::eHDD_RETURN_CODE v7; // eax
  UFG::eHDD_RETURN_CODE v8; // [rsp+20h] [rbp-18h]
  unsigned int v9; // [rsp+24h] [rbp-14h]
  UFG::eHDD_STATUS v10; // [rsp+28h] [rbp-10h]

  v2 = (UFG::HddFileContainer *)*((_QWORD *)callback_param + 1);
  v3 = (UFG::HDDmanager *)callback_param;
  v4 = UFG::HDDmanager::mInstance->m_iSlotNum;
  if ( file_op )
  {
    UFG::HDDmanager::mInstance->mSaveDataExists[v4] = 1;
    v5 = UFG::HDDmanager::mInstance;
    *(_QWORD *)&UFG::HDDmanager::mInstance->mError.eCode = 0i64;
  }
  else
  {
    UFG::HDDmanager::mInstance->mSaveDataExists[v4] = 0;
    v5 = UFG::HDDmanager::mInstance;
    *(_QWORD *)&UFG::HDDmanager::mInstance->mError.eCode = 2i64;
  }
  v5->mError.eType = 2;
  UFG::HddFileContainer::SetCurrentFileToNext(v2);
  if ( UFG::HddFileContainer::IsEndOfList(v2) )
  {
    v6 = UFG::HDDmanager::mInstance;
    v7 = UFG::HDDmanager::mInstance->mError.eCode;
    UFG::HDDmanager::mInstance->mStatus = 0;
    v8 = v7;
    v9 = v6->mError.errArg;
    v10 = v6->mError.eType;
    ((void (__fastcall *)(UFG::eHDD_RETURN_CODE *))v6->mCallBack)(&v8);
  }
  else
  {
    UFG::HDDmanager::HDDSaveNext(v3);
  }
}

// File Line: 188
// RVA: 0xA34400
void __fastcall UFG::HDDmanager::HDDLoad(UFG::HDDmanager *this, UFG::HddFileContainer *files, void (__fastcall *callBack)(UFG::errCode *__struct_ptr))
{
  if ( this->m_eSaveLoadPermission & 1 && files && files->ContainerCount >= 1 )
  {
    this->mFileContainer = files;
    this->mCallBack = (void (__fastcall *)(UFG::errCode))callBack;
    UFG::HDDmanager::HDDLoadNext(this);
  }
}

// File Line: 208
// RVA: 0xA34430
void __fastcall UFG::HDDmanager::HDDLoadNext(UFG::HDDmanager *this)
{
  UFG::HDDmanager *v1; // rdi
  hkResourceContainer *v2; // rbx

  v1 = this;
  v2 = Scaleform::SysAllocPagedMalloc::GetUsedSpace((hkMemoryResourceContainer *)this->mFileContainer);
  UFG::qPrintf("Loading %s File Size = %d\n", v2[3].vfptr, *(unsigned int *)&v2[6].m_memSizeAndFlags);
  v1->mStatus = 3;
  UFG::qReadEntireFileAsync(
    (const char *)v2[3].vfptr,
    UFG::HDDmanager::onReadAsyncCallback,
    v1,
    0i64,
    0i64,
    0i64,
    QPRIORITY_NORMAL);
}

// File Line: 217
// RVA: 0xA346A0
void __fastcall UFG::HDDmanager::onReadAsyncCallback(UFG::qFileOp *file_op, void *callback_param)
{
  __int64 v2; // r12
  UFG::HddFileContainer *v3; // r14
  UFG::qNode<UFG::HddSaveFile,UFG::HddSaveFile> *v4; // rdi
  UFG::HDDmanager *v5; // r15
  UFG::qFileOp *v6; // rsi
  const char *v7; // rbx
  char *v8; // rax
  unsigned int v9; // eax
  unsigned int v10; // ebx
  UFG::allocator::free_link *v11; // rax
  char *v12; // rax
  char *v13; // rax
  UFG::HDDmanager *v14; // rax
  UFG::HDDmanager *v15; // rax
  UFG::HDDmanager *v16; // rdx
  UFG::eHDD_RETURN_CODE v17; // eax
  UFG::eHDD_RETURN_CODE v18; // [rsp+20h] [rbp-38h]
  unsigned int v19; // [rsp+24h] [rbp-34h]
  UFG::eHDD_STATUS v20; // [rsp+28h] [rbp-30h]

  v2 = UFG::HDDmanager::mInstance->m_iSlotNum;
  v3 = (UFG::HddFileContainer *)*((_QWORD *)callback_param + 1);
  v4 = v3->FileList.mNode.mNext;
  v5 = (UFG::HDDmanager *)callback_param;
  v6 = file_op;
  if ( v4 != (UFG::qNode<UFG::HddSaveFile,UFG::HddSaveFile> *)&v3->FileList )
  {
    while ( 1 )
    {
      v7 = (const char *)v4[3].mPrev;
      v8 = UFG::qFileOp::GetFilename(v6);
      if ( !(unsigned int)UFG::qStringCompare(v8, v7, -1) )
        break;
      v4 = v4->mNext;
      if ( v4 == (UFG::qNode<UFG::HddSaveFile,UFG::HddSaveFile> *)&v3->FileList )
        goto LABEL_11;
    }
    if ( v6 && UFG::qFileOp::GetReadEntireFileBuffer(v6) )
    {
      v9 = UFG::qFileOp::GetReadEntireFileSize(v6);
      v10 = v9;
      if ( LOBYTE(v4[1].mPrev) )
      {
        v11 = UFG::qRealloc(v4[7].mPrev, v9, "Hdd File Data", 0i64);
        LODWORD(v4[6].mNext) = v10;
        v4[7].mPrev = (UFG::qNode<UFG::HddSaveFile,UFG::HddSaveFile> *)v11;
      }
      v12 = UFG::qFileOp::GetReadEntireFileBuffer(v6);
      UFG::qMemCopy(v4[7].mPrev, v12, (unsigned int)v4[6].mNext);
    }
    else
    {
      operator delete[](v4[7].mPrev);
      v4[7].mPrev = 0i64;
    }
  }
LABEL_11:
  if ( v6 && UFG::qFileOp::GetReadEntireFileBuffer(v6) )
  {
    v13 = UFG::qFileOp::GetReadEntireFileBuffer(v6);
    UFG::qFreeEntireFile(v13, 0i64);
    v14 = UFG::HDDmanager::mInstance;
    *(_QWORD *)&UFG::HDDmanager::mInstance->mError.eCode = 0i64;
    v14->mError.eType = 3;
    UFG::HDDmanager::mInstance->mSaveDataExists[v2] = 1;
  }
  else
  {
    v15 = UFG::HDDmanager::mInstance;
    *(_QWORD *)&UFG::HDDmanager::mInstance->mError.eCode = 3i64;
    v15->mError.eType = 3;
    UFG::HDDmanager::mInstance->mSaveDataExists[v2] = 0;
  }
  UFG::HddFileContainer::SetCurrentFileToNext(v3);
  if ( UFG::HddFileContainer::IsEndOfList(v3) )
  {
    v16 = UFG::HDDmanager::mInstance;
    v17 = UFG::HDDmanager::mInstance->mError.eCode;
    UFG::HDDmanager::mInstance->mStatus = 0;
    v18 = v17;
    v19 = v16->mError.errArg;
    v20 = v16->mError.eType;
    ((void (__fastcall *)(UFG::eHDD_RETURN_CODE *))v16->mCallBack)(&v18);
  }
  else
  {
    UFG::HDDmanager::HDDLoadNext(v5);
  }
}

// File Line: 277
// RVA: 0xA34240
void __fastcall UFG::HDDmanager::HDDDelete(UFG::HDDmanager *this, UFG::HddFileContainer *files, void (__fastcall *callBack)(UFG::errCode *__struct_ptr))
{
  if ( (this->m_eSaveLoadPermission >> 1) & 1 && files && files->ContainerCount >= 1 )
  {
    this->mFileContainer = files;
    this->mCallBack = (void (__fastcall *)(UFG::errCode))callBack;
    this->mReCreateData = 0;
    UFG::HDDmanager::HDDDeleteNext(this);
  }
}

// File Line: 302
// RVA: 0xA34270
void __fastcall UFG::HDDmanager::HDDDeleteNext(UFG::HDDmanager *this)
{
  UFG::HDDmanager *v1; // rbx
  hkResourceContainer *v2; // rdi
  UFG::HddFileContainer *v3; // rcx
  UFG::HDDmanager *v4; // rdx
  UFG::eHDD_RETURN_CODE v5; // eax
  UFG::eHDD_RETURN_CODE v6; // [rsp+20h] [rbp-18h]
  unsigned int v7; // [rsp+24h] [rbp-14h]
  UFG::eHDD_STATUS v8; // [rsp+28h] [rbp-10h]

  v1 = this;
  do
  {
    v2 = Scaleform::SysAllocPagedMalloc::GetUsedSpace((hkMemoryResourceContainer *)v1->mFileContainer);
    UFG::qPrintf("Deleting %s\n", v2[3].vfptr);
    v1->mStatus = 4;
    if ( (unsigned __int8)UFG::qDeleteFile((const char *)v2[3].vfptr) )
    {
      *(_QWORD *)&v1->mError.eCode = 3i64;
    }
    else
    {
      v1->mSaveDataExists[v1->m_iSlotNum] = 0;
      *(_QWORD *)&v1->mError.eCode = 0i64;
    }
    v3 = v1->mFileContainer;
    v1->mError.eType = 4;
    UFG::HddFileContainer::SetCurrentFileToNext(v3);
  }
  while ( !UFG::HddFileContainer::IsEndOfList(v1->mFileContainer) );
  v4 = UFG::HDDmanager::mInstance;
  v5 = UFG::HDDmanager::mInstance->mError.eCode;
  UFG::HDDmanager::mInstance->mStatus = 0;
  v6 = v5;
  v7 = v4->mError.errArg;
  v8 = v4->mError.eType;
  ((void (__fastcall *)(UFG::eHDD_RETURN_CODE *))v4->mCallBack)(&v6);
}

