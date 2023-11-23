// File Line: 67
// RVA: 0xA34940
void __fastcall UFG::WwiseDefaultIOHookDeferred::WwiseDefaultIOHookDeferred(UFG::WwiseDefaultIOHookDeferred *this)
{
  UFG::WwiseDefaultIOHookDeferredBase::WwiseDefaultIOHookDeferredBase(this);
  this->UFG::WwiseDefaultIOHookDeferredBase::AK::StreamMgr::IAkFileLocationResolver::vfptr = (AK::StreamMgr::IAkFileLocationResolverVtbl *)&UFG::WwiseDefaultIOHookDeferred::`vftable{for `AK::StreamMgr::IAkFileLocationResolver};
  this->UFG::WwiseDefaultIOHookDeferredBase::AK::StreamMgr::IAkIOHookDeferred::AK::StreamMgr::IAkLowLevelIOHook::vfptr = (AK::StreamMgr::IAkLowLevelIOHookVtbl *)&UFG::WwiseDefaultIOHookDeferred::`vftable{for `AK::StreamMgr::IAkIOHookDeferred};
  this->UFG::WwiseDefaultIOHookDeferredBase::UFG::WwiseFileLocationBase::vfptr = (UFG::WwiseFileLocationBaseVtbl *)&UFG::WwiseDefaultIOHookDeferred::`vftable{for `UFG::WwiseFileLocationBase};
}

// File Line: 71
// RVA: 0xA34990
void __fastcall UFG::WwiseDefaultIOHookDeferred::~WwiseDefaultIOHookDeferred(UFG::WwiseDefaultIOHookDeferred *this)
{
  this->UFG::WwiseDefaultIOHookDeferredBase::AK::StreamMgr::IAkFileLocationResolver::vfptr = (AK::StreamMgr::IAkFileLocationResolverVtbl *)&UFG::WwiseDefaultIOHookDeferred::`vftable{for `AK::StreamMgr::IAkFileLocationResolver};
  this->UFG::WwiseDefaultIOHookDeferredBase::AK::StreamMgr::IAkIOHookDeferred::AK::StreamMgr::IAkLowLevelIOHook::vfptr = (AK::StreamMgr::IAkLowLevelIOHookVtbl *)&UFG::WwiseDefaultIOHookDeferred::`vftable{for `AK::StreamMgr::IAkIOHookDeferred};
  this->UFG::WwiseDefaultIOHookDeferredBase::UFG::WwiseFileLocationBase::vfptr = (UFG::WwiseFileLocationBaseVtbl *)&UFG::WwiseDefaultIOHookDeferred::`vftable{for `UFG::WwiseFileLocationBase};
  UFG::WwiseDefaultIOHookDeferredBase::~WwiseDefaultIOHookDeferredBase(this);
}

// File Line: 81
// RVA: 0xA360D0
__int64 __fastcall UFG::WwiseDefaultIOHookDeferred::Init(
        UFG::WwiseDefaultIOHookDeferred *this,
        AkDeviceSettings *in_deviceSettings,
        bool in_bAsyncOpen)
{
  unsigned int Device; // eax

  if ( in_deviceSettings->uSchedulerTypeFlags != 2 )
    return 2i64;
  this->m_bAsyncOpen = in_bAsyncOpen;
  this->m_blockSize = 2048;
  if ( !AK::StreamMgr::GetFileLocationResolver() )
    AK::StreamMgr::SetFileLocationResolver(this);
  Device = AK::StreamMgr::CreateDevice(in_deviceSettings, &this->AK::StreamMgr::IAkIOHookDeferred);
  this->m_WwiseDevice = Device;
  return (unsigned int)(Device == -1) + 1;
}

// File Line: 111
// RVA: 0xA365A0
void __fastcall UFG::WwiseDefaultIOHookDeferred::Term(UFG::WwiseDefaultIOHookDeferred *this)
{
  if ( AK::StreamMgr::GetFileLocationResolver() == this )
    AK::StreamMgr::SetFileLocationResolver(0i64);
  AK::StreamMgr::DestroyDevice(this->m_WwiseDevice);
  if ( UFG::WwiseDefaultIOHookDeferred::m_poolID != -1 )
  {
    AK::MemoryMgr::DestroyPool(UFG::WwiseDefaultIOHookDeferred::m_poolID);
    UFG::WwiseDefaultIOHookDeferred::m_poolID = -1;
  }
}

// File Line: 132
// RVA: 0xA36250
__int64 __fastcall UFG::WwiseDefaultIOHookDeferred::Open(
        UFG::WwiseDefaultIOHookDeferred *this,
        const wchar_t *in_pszFileName,
        AkOpenMode in_eOpenMode,
        AkFileSystemFlags *in_pFlags,
        bool *io_bSyncOpen,
        AkFileDesc *out_fileDesc)
{
  int v9; // eax
  unsigned int v10; // edi
  UFG::BIGFileIndex *v11; // rax
  UFG::qString out_FullFilePath; // [rsp+38h] [rbp-30h] BYREF

  *io_bSyncOpen = 1;
  UFG::qString::qString(&out_FullFilePath);
  UFG::WwiseFileLocationBase::BuildFilePath(
    &this->UFG::WwiseFileLocationBase,
    in_pszFileName,
    in_pFlags,
    &out_FullFilePath);
  v9 = UFG::WwiseDefaultIOHookDeferredBase::DetermineStreamPriority(this, in_pszFileName, in_pFlags);
  if ( out_FullFilePath.mLength > 0
    && (out_fileDesc->pCustomParam = (void *)v9,
        *(_QWORD *)&out_fileDesc->uSector = 0i64,
        v10 = 1,
        v11 = WWiseOSFileWrapper::Open(out_FullFilePath.mData, QACCESS_READ, 0, 0i64, 0i64),
        (out_fileDesc->hFile = v11) != 0i64) )
  {
    out_fileDesc->iFileSize = WWiseOSFileWrapper::GetFileSize(v11);
    out_fileDesc->deviceID = this->m_WwiseDevice;
  }
  else
  {
    v10 = 2;
  }
  UFG::qString::~qString(&out_FullFilePath);
  return v10;
}

// File Line: 180
// RVA: 0xA36150
__int64 __fastcall UFG::WwiseDefaultIOHookDeferred::Open(
        UFG::WwiseDefaultIOHookDeferred *this,
        unsigned int in_fileID,
        AkOpenMode in_eOpenMode,
        AkFileSystemFlags *in_pFlags,
        bool *io_bSyncOpen,
        AkFileDesc *out_fileDesc)
{
  unsigned int v9; // ebp
  int v10; // eax
  UFG::BIGFileIndex *v11; // rax
  UFG::qString out_FullFilePath; // [rsp+38h] [rbp-30h] BYREF

  v9 = 2;
  *io_bSyncOpen = 1;
  out_fileDesc->iFileSize = 0i64;
  *(_QWORD *)&out_fileDesc->uSector = 0i64;
  out_fileDesc->pCustomParam = 0i64;
  out_fileDesc->hFile = 0i64;
  *(_QWORD *)&out_fileDesc->deviceID = 0i64;
  UFG::qString::qString(&out_FullFilePath);
  UFG::WwiseFileLocationBase::BuildFilePath(&this->UFG::WwiseFileLocationBase, in_fileID, in_pFlags, &out_FullFilePath);
  v10 = UFG::WwiseDefaultIOHookDeferredBase::DetermineStreamPriority(this, in_fileID, in_pFlags);
  if ( out_FullFilePath.mLength > 0 )
  {
    out_fileDesc->pCustomParam = (void *)v10;
    *(_QWORD *)&out_fileDesc->uSector = 0i64;
    v11 = WWiseOSFileWrapper::Open(out_FullFilePath.mData, QACCESS_READ, 0, 0i64, 0i64);
    out_fileDesc->hFile = v11;
    if ( v11 )
    {
      out_fileDesc->iFileSize = WWiseOSFileWrapper::GetFileSize(v11);
      out_fileDesc->deviceID = this->m_WwiseDevice;
      v9 = 1;
    }
  }
  UFG::qString::~qString(&out_FullFilePath);
  return v9;
}

// File Line: 232
// RVA: 0xA35AC0
void __fastcall UFG::WwiseDefaultIOHookDeferred::FileIOCompletionRoutine(
        UFG::qFileOp *file_op,
        void (__fastcall **cookie)(_QWORD, _QWORD))
{
  if ( cookie )
    cookie[3](cookie, 1i64);
}

// File Line: 248
// RVA: 0xA36330
signed __int64 __fastcall UFG::WwiseDefaultIOHookDeferred::Read(
        UFG::WwiseDefaultIOHookDeferred *this,
        AkFileDesc *in_fileDesc,
        AkIoHeuristics *in_heuristics,
        AkAsyncIOTransferInfo *io_transferInfo)
{
  BOOL priority; // eax

  if ( io_transferInfo->uRequestedSize > io_transferInfo->uBufferSize )
    return 2i64;
  priority = UFG::WwiseDefaultIOHookDeferredBase::DetermineStreamPriority(
               (UFG::WwiseDefaultIOHookDeferred *)((char *)this - 8),
               in_heuristics,
               (WWiseOSFileWrapper::QUEUE_CLASS)LODWORD(in_fileDesc->pCustomParam));
  WWiseOSFileWrapper::Read(
    in_fileDesc->hFile,
    io_transferInfo->pBuffer,
    io_transferInfo->uRequestedSize,
    io_transferInfo->uFilePosition,
    QSEEK_SET,
    (void (__fastcall *)(UFG::qFileOp *, void *))UFG::WwiseDefaultIOHookDeferred::FileIOCompletionRoutine,
    io_transferInfo,
    (WWiseOSFileWrapper::QUEUE_CLASS)priority,
    in_heuristics->priority);
  return 1i64;
}

// File Line: 344
// RVA: 0xA35750
__int64 __fastcall UFG::WwiseDefaultIOHookDeferred::Close(
        UFG::WwiseDefaultIOHookDeferred *this,
        AkFileDesc *in_fileDesc)
{
  return (*(__int64 (__fastcall **)(WWiseOSFileWrapper::QUEUE_CLASS *, void **))(*(_QWORD *)&this[-1].m_priority + 24i64))(
           &this[-1].m_priority,
           &in_fileDesc->hFile);
}

// File Line: 349
// RVA: 0xA35730
__int64 __fastcall UFG::WwiseDefaultIOHookDeferred::Close(UFG::WwiseDefaultIOHookDeferred *this, void **handle)
{
  WWiseOSFileWrapper::Close(*handle);
  return 1i64;
}

// File Line: 358
// RVA: 0xA35B80
__int64 __fastcall UFG::WwiseDefaultIOHookDeferred::FindFileSize(
        UFG::WwiseDefaultIOHookDeferred *this,
        const wchar_t *in_pszFileName,
        AkFileSystemFlags *in_pFlags)
{
  __int64 FileSize; // rdi
  UFG::BIGFileIndex *v6; // rax
  UFG::BIGFileIndex *v7; // rbx
  UFG::qString out_FullFilePath; // [rsp+38h] [rbp-30h] BYREF

  UFG::qString::qString(&out_FullFilePath);
  UFG::WwiseFileLocationBase::BuildFilePath(&this->UFG::WwiseFileLocationBase, in_pszFileName, 0i64, &out_FullFilePath);
  FileSize = 0i64;
  if ( out_FullFilePath.mLength > 0 )
  {
    v6 = WWiseOSFileWrapper::Open(out_FullFilePath.mData, QACCESS_READ, 0, 0i64, 0i64);
    v7 = v6;
    if ( v6 )
    {
      FileSize = WWiseOSFileWrapper::GetFileSize(v6);
      WWiseOSFileWrapper::Close(v7);
    }
  }
  UFG::qString::~qString(&out_FullFilePath);
  return FileSize;
}

// File Line: 395
// RVA: 0xA35AE0
__int64 __fastcall UFG::WwiseDefaultIOHookDeferred::FindFileSize(
        UFG::WwiseDefaultIOHookDeferred *this,
        unsigned int in_fileId,
        AkFileSystemFlags *in_pFlags)
{
  __int64 FileSize; // rdi
  UFG::BIGFileIndex *v7; // rax
  UFG::BIGFileIndex *v8; // rbx
  UFG::qString out_FullFilePath; // [rsp+38h] [rbp-30h] BYREF

  UFG::qString::qString(&out_FullFilePath);
  UFG::WwiseFileLocationBase::BuildFilePath(&this->UFG::WwiseFileLocationBase, in_fileId, in_pFlags, &out_FullFilePath);
  FileSize = 0i64;
  if ( out_FullFilePath.mLength > 0 )
  {
    v7 = WWiseOSFileWrapper::Open(out_FullFilePath.mData, QACCESS_READ, 0, 0i64, 0i64);
    v8 = v7;
    if ( v7 )
    {
      FileSize = WWiseOSFileWrapper::GetFileSize(v7);
      WWiseOSFileWrapper::Close(v8);
    }
  }
  UFG::qString::~qString(&out_FullFilePath);
  return FileSize;
}

// File Line: 429
// RVA: 0xA35C10
__int64 __fastcall UFG::WwiseDefaultIOHookDeferred::GetBlockSize(
        UFG::WwiseDefaultIOHookDeferred *this,
        AkFileDesc *__formal)
{
  return this->m_WwiseDLCPath.mStringHash32;
}

// File Line: 437
// RVA: 0xA35C20
void __fastcall UFG::WwiseDefaultIOHookDeferred::GetDeviceDesc(
        UFG::WwiseDefaultIOHookDeferred *this,
        AkDeviceDesc *out_deviceDesc)
{
  unsigned int mStringHashUpper32; // eax
  char *v5; // rax
  const wchar_t *WideName; // rax
  __int64 v7; // rbx
  __int64 v8; // rcx
  unsigned __int64 v9; // rdi
  __int64 v10; // rdi
  UFG::qString result; // [rsp+28h] [rbp-30h] BYREF

  mStringHashUpper32 = this->m_WwiseDLCPath.mStringHashUpper32;
  if ( mStringHashUpper32 != -1 )
  {
    out_deviceDesc->deviceID = mStringHashUpper32;
    *(_WORD *)&out_deviceDesc->bCanWrite = 257;
    v5 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&this->m_WwiseDevice);
    UFG::qString::FormatEx(&result, "D%u_%s", this->m_WwiseDLCPath.mStringHashUpper32, v5);
    WideName = UFG::qString::GetWideName(&result);
    v7 = -1i64;
    v8 = -1i64;
    do
      ++v8;
    while ( WideName[v8] );
    if ( (unsigned __int64)(v8 + 1) <= 0xF )
    {
      v10 = -1i64;
      do
        ++v10;
      while ( WideName[v10] );
      v9 = v10 + 1;
    }
    else
    {
      v9 = 15i64;
    }
    wcsncpy_s(out_deviceDesc->szDeviceName, 0x10ui64, WideName, v9);
    out_deviceDesc->szDeviceName[v9] = 0;
    do
      ++v7;
    while ( out_deviceDesc->szDeviceName[v7] );
    out_deviceDesc->uStringSize = v7 + 1;
    UFG::qString::~qString(&result);
  }
}

