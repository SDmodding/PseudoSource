// File Line: 67
// RVA: 0xA34940
void __fastcall UFG::WwiseDefaultIOHookDeferred::WwiseDefaultIOHookDeferred(UFG::WwiseDefaultIOHookDeferred *this)
{
  UFG::WwiseDefaultIOHookDeferred *v1; // rbx

  v1 = this;
  UFG::WwiseDefaultIOHookDeferredBase::WwiseDefaultIOHookDeferredBase((UFG::WwiseDefaultIOHookDeferredBase *)&this->vfptr);
  v1->vfptr = (AK::StreamMgr::IAkFileLocationResolverVtbl *)&UFG::WwiseDefaultIOHookDeferred::`vftable'{for `AK::StreamMgr::IAkFileLocationResolver'};
  v1->vfptr = (AK::StreamMgr::IAkLowLevelIOHookVtbl *)&UFG::WwiseDefaultIOHookDeferred::`vftable'{for `AK::StreamMgr::IAkIOHookDeferred'};
  v1->vfptr = (UFG::WwiseFileLocationBaseVtbl *)&UFG::WwiseDefaultIOHookDeferred::`vftable'{for `UFG::WwiseFileLocationBase'};
}

// File Line: 71
// RVA: 0xA34990
void __fastcall UFG::WwiseDefaultIOHookDeferred::~WwiseDefaultIOHookDeferred(UFG::WwiseDefaultIOHookDeferred *this)
{
  this->vfptr = (AK::StreamMgr::IAkFileLocationResolverVtbl *)&UFG::WwiseDefaultIOHookDeferred::`vftable'{for `AK::StreamMgr::IAkFileLocationResolver'};
  this->vfptr = (AK::StreamMgr::IAkLowLevelIOHookVtbl *)&UFG::WwiseDefaultIOHookDeferred::`vftable'{for `AK::StreamMgr::IAkIOHookDeferred'};
  this->vfptr = (UFG::WwiseFileLocationBaseVtbl *)&UFG::WwiseDefaultIOHookDeferred::`vftable'{for `UFG::WwiseFileLocationBase'};
  UFG::WwiseDefaultIOHookDeferredBase::~WwiseDefaultIOHookDeferredBase((UFG::WwiseDefaultIOHookDeferredBase *)&this->vfptr);
}

// File Line: 81
// RVA: 0xA360D0
signed __int64 __fastcall UFG::WwiseDefaultIOHookDeferred::Init(UFG::WwiseDefaultIOHookDeferred *this, AkDeviceSettings *in_deviceSettings, bool in_bAsyncOpen)
{
  AkDeviceSettings *v3; // rdi
  UFG::WwiseDefaultIOHookDeferred *v4; // rbx
  unsigned int v6; // eax

  v3 = in_deviceSettings;
  v4 = this;
  if ( in_deviceSettings->uSchedulerTypeFlags != 2 )
    return 2i64;
  this->m_bAsyncOpen = in_bAsyncOpen;
  this->m_blockSize = 2048;
  if ( !AK::StreamMgr::GetFileLocationResolver() )
    AK::StreamMgr::SetFileLocationResolver((AK::StreamMgr::IAkFileLocationResolver *)&v4->vfptr);
  v6 = AK::StreamMgr::CreateDevice(v3, (AK::StreamMgr::IAkLowLevelIOHook *)&v4->vfptr);
  v4->m_WwiseDevice = v6;
  return (unsigned int)(v6 == -1) + 1;
}

// File Line: 111
// RVA: 0xA365A0
void __fastcall UFG::WwiseDefaultIOHookDeferred::Term(UFG::WwiseDefaultIOHookDeferred *this)
{
  UFG::WwiseDefaultIOHookDeferred *v1; // rbx

  v1 = this;
  if ( AK::StreamMgr::GetFileLocationResolver() == (AK::StreamMgr::IAkFileLocationResolver *)this )
    AK::StreamMgr::SetFileLocationResolver(0i64);
  AK::StreamMgr::DestroyDevice(v1->m_WwiseDevice);
  if ( UFG::WwiseDefaultIOHookDeferred::m_poolID != -1 )
  {
    AK::MemoryMgr::DestroyPool(UFG::WwiseDefaultIOHookDeferred::m_poolID);
    UFG::WwiseDefaultIOHookDeferred::m_poolID = -1;
  }
}

// File Line: 132
// RVA: 0xA36250
__int64 __fastcall UFG::WwiseDefaultIOHookDeferred::Open(UFG::WwiseDefaultIOHookDeferred *this, const wchar_t *in_pszFileName, AkOpenMode in_eOpenMode, AkFileSystemFlags *in_pFlags, bool *io_bSyncOpen, AkFileDesc *out_fileDesc)
{
  AkFileSystemFlags *v6; // rdi
  const wchar_t *v7; // rbx
  UFG::WwiseDefaultIOHookDeferred *v8; // rsi
  int v9; // eax
  unsigned int v10; // edi
  UFG::BIGFileIndex *v11; // rax
  UFG::qString out_FullFilePath; // [rsp+38h] [rbp-30h]

  v6 = in_pFlags;
  v7 = in_pszFileName;
  v8 = this;
  *io_bSyncOpen = 1;
  UFG::qString::qString(&out_FullFilePath);
  UFG::WwiseFileLocationBase::BuildFilePath((UFG::WwiseFileLocationBase *)&v8->vfptr, v7, v6, &out_FullFilePath);
  v9 = UFG::WwiseDefaultIOHookDeferredBase::DetermineStreamPriority(
         (UFG::WwiseDefaultIOHookDeferredBase *)&v8->vfptr,
         v7,
         v6);
  if ( out_FullFilePath.mLength > 0
    && (out_fileDesc->pCustomParam = (void *)v9,
        *(_QWORD *)&out_fileDesc->uSector = 0i64,
        v10 = 1,
        v11 = WWiseOSFileWrapper::Open(out_FullFilePath.mData, QACCESS_READ, 0, 0i64, 0i64),
        (out_fileDesc->hFile = v11) != 0i64) )
  {
    out_fileDesc->iFileSize = WWiseOSFileWrapper::GetFileSize(v11);
    out_fileDesc->deviceID = v8->m_WwiseDevice;
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
__int64 __fastcall UFG::WwiseDefaultIOHookDeferred::Open(UFG::WwiseDefaultIOHookDeferred *this, unsigned int in_fileID, AkOpenMode in_eOpenMode, AkFileSystemFlags *in_pFlags, bool *io_bSyncOpen, AkFileDesc *out_fileDesc)
{
  AkFileSystemFlags *v6; // rdi
  unsigned int v7; // ebx
  UFG::WwiseDefaultIOHookDeferred *v8; // r14
  unsigned int v9; // ebp
  int v10; // eax
  UFG::BIGFileIndex *v11; // rax
  UFG::qString out_FullFilePath; // [rsp+38h] [rbp-30h]

  v6 = in_pFlags;
  v7 = in_fileID;
  v8 = this;
  v9 = 2;
  *io_bSyncOpen = 1;
  *(_OWORD *)&out_fileDesc->iFileSize = 0ui64;
  out_fileDesc->pCustomParam = 0i64;
  out_fileDesc->hFile = 0i64;
  *(_QWORD *)&out_fileDesc->deviceID = 0i64;
  UFG::qString::qString(&out_FullFilePath);
  UFG::WwiseFileLocationBase::BuildFilePath((UFG::WwiseFileLocationBase *)&v8->vfptr, v7, v6, &out_FullFilePath);
  v10 = UFG::WwiseDefaultIOHookDeferredBase::DetermineStreamPriority(
          (UFG::WwiseDefaultIOHookDeferredBase *)&v8->vfptr,
          v7,
          v6);
  if ( out_FullFilePath.mLength > 0 )
  {
    out_fileDesc->pCustomParam = (void *)v10;
    *(_QWORD *)&out_fileDesc->uSector = 0i64;
    v11 = WWiseOSFileWrapper::Open(out_FullFilePath.mData, QACCESS_READ, 0, 0i64, 0i64);
    out_fileDesc->hFile = v11;
    if ( v11 )
    {
      out_fileDesc->iFileSize = WWiseOSFileWrapper::GetFileSize(v11);
      out_fileDesc->deviceID = v8->m_WwiseDevice;
      v9 = 1;
    }
  }
  UFG::qString::~qString(&out_FullFilePath);
  return v9;
}

// File Line: 232
// RVA: 0xA35AC0
void __fastcall UFG::WwiseDefaultIOHookDeferred::FileIOCompletionRoutine(UFG::qFileOp *file_op, void *cookie)
{
  if ( cookie )
    (*((void (__fastcall **)(void *, signed __int64))cookie + 3))(cookie, 1i64);
}

// File Line: 248
// RVA: 0xA36330
signed __int64 __fastcall UFG::WwiseDefaultIOHookDeferred::Read(UFG::WwiseDefaultIOHookDeferred *this, AkFileDesc *in_fileDesc, AkIoHeuristics *in_heuristics, AkAsyncIOTransferInfo *io_transferInfo)
{
  AkAsyncIOTransferInfo *callback_param; // rbx
  AkIoHeuristics *v5; // rdi
  AkFileDesc *v6; // rsi
  BOOL priority; // eax
  __int128 v9; // xmm0

  callback_param = io_transferInfo;
  v5 = in_heuristics;
  v6 = in_fileDesc;
  if ( io_transferInfo->uRequestedSize > io_transferInfo->uBufferSize )
    return 2i64;
  priority = UFG::WwiseDefaultIOHookDeferredBase::DetermineStreamPriority(
               (UFG::WwiseDefaultIOHookDeferredBase *)&this[-1].m_priority,
               in_heuristics,
               (WWiseOSFileWrapper::QUEUE_CLASS)LODWORD(in_fileDesc->pCustomParam));
  v9 = LODWORD(v5->fDeadline);
  WWiseOSFileWrapper::Read(
    v6->hFile,
    callback_param->pBuffer,
    callback_param->uRequestedSize,
    callback_param->uFilePosition,
    0,
    UFG::WwiseDefaultIOHookDeferred::FileIOCompletionRoutine,
    callback_param,
    (WWiseOSFileWrapper::QUEUE_CLASS)priority,
    v5->priority);
  return 1i64;
}

// File Line: 344
// RVA: 0xA35750
__int64 __fastcall UFG::WwiseDefaultIOHookDeferred::Close(UFG::WwiseDefaultIOHookDeferred *this, AkFileDesc *in_fileDesc)
{
  return (*(__int64 (__fastcall **)(WWiseOSFileWrapper::QUEUE_CLASS *, void **))(*(_QWORD *)&this[-1].m_priority + 24i64))(
           &this[-1].m_priority,
           &in_fileDesc->hFile);
}

// File Line: 349
// RVA: 0xA35730
signed __int64 __fastcall UFG::WwiseDefaultIOHookDeferred::Close(UFG::WwiseDefaultIOHookDeferred *this, void **handle)
{
  WWiseOSFileWrapper::Close(*handle);
  return 1i64;
}

// File Line: 358
// RVA: 0xA35B80
__int64 __fastcall UFG::WwiseDefaultIOHookDeferred::FindFileSize(UFG::WwiseDefaultIOHookDeferred *this, const wchar_t *in_pszFileName, AkFileSystemFlags *in_pFlags)
{
  const wchar_t *v3; // rdi
  UFG::WwiseDefaultIOHookDeferred *v4; // rbx
  __int64 v5; // rdi
  UFG::BIGFileIndex *v6; // rax
  UFG::BIGFileIndex *v7; // rbx
  UFG::qString out_FullFilePath; // [rsp+38h] [rbp-30h]

  v3 = in_pszFileName;
  v4 = this;
  UFG::qString::qString(&out_FullFilePath);
  UFG::WwiseFileLocationBase::BuildFilePath((UFG::WwiseFileLocationBase *)&v4->vfptr, v3, 0i64, &out_FullFilePath);
  v5 = 0i64;
  if ( out_FullFilePath.mLength > 0 )
  {
    v6 = WWiseOSFileWrapper::Open(out_FullFilePath.mData, QACCESS_READ, 0, 0i64, 0i64);
    v7 = v6;
    if ( v6 )
    {
      v5 = WWiseOSFileWrapper::GetFileSize(v6);
      WWiseOSFileWrapper::Close(v7);
    }
  }
  UFG::qString::~qString(&out_FullFilePath);
  return v5;
}

// File Line: 395
// RVA: 0xA35AE0
__int64 __fastcall UFG::WwiseDefaultIOHookDeferred::FindFileSize(UFG::WwiseDefaultIOHookDeferred *this, unsigned int in_fileId, AkFileSystemFlags *in_pFlags)
{
  AkFileSystemFlags *v3; // rdi
  unsigned int v4; // esi
  UFG::WwiseDefaultIOHookDeferred *v5; // rbx
  __int64 v6; // rdi
  UFG::BIGFileIndex *v7; // rax
  UFG::BIGFileIndex *v8; // rbx
  UFG::qString out_FullFilePath; // [rsp+38h] [rbp-30h]

  v3 = in_pFlags;
  v4 = in_fileId;
  v5 = this;
  UFG::qString::qString(&out_FullFilePath);
  UFG::WwiseFileLocationBase::BuildFilePath((UFG::WwiseFileLocationBase *)&v5->vfptr, v4, v3, &out_FullFilePath);
  v6 = 0i64;
  if ( out_FullFilePath.mLength > 0 )
  {
    v7 = WWiseOSFileWrapper::Open(out_FullFilePath.mData, QACCESS_READ, 0, 0i64, 0i64);
    v8 = v7;
    if ( v7 )
    {
      v6 = WWiseOSFileWrapper::GetFileSize(v7);
      WWiseOSFileWrapper::Close(v8);
    }
  }
  UFG::qString::~qString(&out_FullFilePath);
  return v6;
}

// File Line: 429
// RVA: 0xA35C10
__int64 __fastcall UFG::WwiseDefaultIOHookDeferred::GetBlockSize(UFG::WwiseDefaultIOHookDeferred *this, AkFileDesc *__formal)
{
  return this->m_WwiseDLCPath.mStringHash32;
}

// File Line: 437
// RVA: 0xA35C20
void __fastcall UFG::WwiseDefaultIOHookDeferred::GetDeviceDesc(UFG::WwiseDefaultIOHookDeferred *this, AkDeviceDesc *out_deviceDesc)
{
  AkDeviceDesc *v2; // r14
  UFG::WwiseDefaultIOHookDeferred *v3; // rbx
  unsigned int v4; // eax
  char *v5; // rax
  const wchar_t *v6; // rax
  signed __int64 v7; // rbx
  signed __int64 v8; // rcx
  unsigned __int64 v9; // rdi
  signed __int64 v10; // rdi
  UFG::qString result; // [rsp+28h] [rbp-30h]

  v2 = out_deviceDesc;
  v3 = this;
  v4 = this->m_WwiseDLCPath.mStringHashUpper32;
  if ( v4 != -1 )
  {
    out_deviceDesc->deviceID = v4;
    *(_WORD *)&out_deviceDesc->bCanWrite = 257;
    v5 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&this->m_WwiseDevice);
    UFG::qString::FormatEx(&result, "D%u_%s", v3->m_WwiseDLCPath.mStringHashUpper32, v5, -2i64);
    v6 = UFG::qString::GetWideName(&result);
    v7 = -1i64;
    v8 = -1i64;
    do
      ++v8;
    while ( v6[v8] );
    if ( (unsigned __int64)(v8 + 1) <= 0xF )
    {
      v10 = -1i64;
      do
        ++v10;
      while ( v6[v10] );
      v9 = v10 + 1;
    }
    else
    {
      v9 = 15i64;
    }
    wcsncpy_s(v2->szDeviceName, 0x10ui64, v6, v9);
    v2->szDeviceName[v9] = 0;
    do
      ++v7;
    while ( v2->szDeviceName[v7] );
    v2->uStringSize = v7 + 1;
    UFG::qString::~qString(&result);
  }
}

