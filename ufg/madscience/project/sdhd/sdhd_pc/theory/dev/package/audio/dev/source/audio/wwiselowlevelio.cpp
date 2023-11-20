// File Line: 37
// RVA: 0x140BE0
void __fastcall UFG::WwiseFileLocationBase::WwiseFileLocationBase(UFG::WwiseFileLocationBase *this)
{
  UFG::WwiseFileLocationBase *v1; // rbx

  v1 = this;
  this->vfptr = (UFG::WwiseFileLocationBaseVtbl *)&UFG::WwiseFileLocationBase::`vftable;
  UFG::qString::qString(&this->m_WwiseBasePath, &customWorldMapCaption);
  UFG::qString::qString(&v1->m_WwiseBankPath, &customWorldMapCaption);
  UFG::qString::qString(&v1->m_WwiseLangPath, &customWorldMapCaption);
  UFG::qString::qString(&v1->m_WwiseSrcPath, &customWorldMapCaption);
  UFG::qString::qString(&v1->m_WwiseExternalsPath);
  UFG::qString::qString(&v1->m_WwiseDLCPath);
}

// File Line: 42
// RVA: 0x141810
void __fastcall UFG::WwiseFileLocationBase::~WwiseFileLocationBase(UFG::WwiseFileLocationBase *this)
{
  UFG::WwiseFileLocationBase *v1; // rbx

  v1 = this;
  this->vfptr = (UFG::WwiseFileLocationBaseVtbl *)&UFG::WwiseFileLocationBase::`vftable;
  UFG::qString::~qString(&this->m_WwiseDLCPath);
  UFG::qString::~qString(&v1->m_WwiseExternalsPath);
  UFG::qString::~qString(&v1->m_WwiseSrcPath);
  UFG::qString::~qString(&v1->m_WwiseLangPath);
  UFG::qString::~qString(&v1->m_WwiseBankPath);
  UFG::qString::~qString(&v1->m_WwiseBasePath);
}

// File Line: 85
// RVA: 0x143760
signed __int64 __fastcall UFG::WwiseFileLocationBase::BuildFilePath(UFG::WwiseFileLocationBase *this, const wchar_t *in_FileName, AkFileSystemFlags *in_pFlags, UFG::qString *out_FullFilePath)
{
  UFG::qString *v4; // rdi
  AkFileSystemFlags *v5; // rbx
  const wchar_t *v6; // r14
  UFG::WwiseFileLocationBase *v7; // rsi
  char v8; // bp
  char *v9; // rax
  unsigned int v10; // er8
  const char *v11; // rdx
  char *v12; // rbx
  unsigned int v13; // eax
  UFG::qString result; // [rsp+38h] [rbp-30h]

  v4 = out_FullFilePath;
  v5 = in_pFlags;
  v6 = in_FileName;
  v7 = this;
  if ( !in_FileName )
    return 1i64;
  v8 = 0;
  if ( in_pFlags )
  {
    v9 = (char *)in_pFlags->pCustomParam;
    if ( v9 )
      v8 = *v9;
  }
  UFG::qString::Set(out_FullFilePath, this->m_WwiseBasePath.mData, this->m_WwiseBasePath.mLength, 0i64, 0);
  if ( v8 )
  {
    v10 = v7->m_WwiseDLCPath.mLength;
    v11 = v7->m_WwiseDLCPath.mData;
  }
  else
  {
    if ( !v5 || v5->uCompanyID || v5->uCodecID )
      goto LABEL_12;
    v10 = v7->m_WwiseBankPath.mLength;
    v11 = v7->m_WwiseBankPath.mData;
  }
  UFG::qString::append(v4, v11, v10);
LABEL_12:
  UFG::ConvertAkLpCtstrToChar(&result, v6);
  if ( !(unsigned int)UFG::qString::StartsWith(&result, "\\", -1) && !(unsigned int)UFG::qString::EndsWith(v4, "\\", -1) )
    UFG::qString::operator+=(v4, "\\");
  v12 = result.mData;
  v13 = UFG::qStringLength(result.mData);
  UFG::qString::append(v4, v12, v13);
  UFG::qString::~qString(&result);
  return 1i64;
}

// File Line: 141
// RVA: 0x143600
signed __int64 __fastcall UFG::WwiseFileLocationBase::BuildFilePath(UFG::WwiseFileLocationBase *this, unsigned int in_fileID, AkFileSystemFlags *in_pFlags, UFG::qString *out_FullFilePath)
{
  UFG::qString *v4; // rbx
  AkFileSystemFlags *v5; // rsi
  unsigned int v6; // ebp
  UFG::WwiseFileLocationBase *v7; // rdi
  unsigned int v9; // er8
  const char *v10; // rdx
  signed __int64 v11; // r8
  unsigned int v12; // eax
  const char *v13; // rdx
  char dest; // [rsp+30h] [rbp-28h]
  __int64 v15; // [rsp+31h] [rbp-27h]
  __int64 v16; // [rsp+39h] [rbp-1Fh]
  __int64 v17; // [rsp+41h] [rbp-17h]
  int v18; // [rsp+49h] [rbp-Fh]
  __int16 v19; // [rsp+4Dh] [rbp-Bh]
  char v20; // [rsp+4Fh] [rbp-9h]

  v4 = out_FullFilePath;
  v5 = in_pFlags;
  v6 = in_fileID;
  v7 = this;
  if ( !in_pFlags )
    return 2i64;
  UFG::qString::Set(out_FullFilePath, this->m_WwiseBasePath.mData, this->m_WwiseBasePath.mLength, 0i64, 0);
  if ( v5->uCodecID )
  {
    v9 = v7->m_WwiseSrcPath.mLength;
    v10 = v7->m_WwiseSrcPath.mData;
  }
  else
  {
    v9 = v7->m_WwiseBankPath.mLength;
    v10 = v7->m_WwiseBankPath.mData;
  }
  UFG::qString::append(v4, v10, v9);
  if ( v5->uCompanyID == 1 )
    UFG::qString::append(v4, v7->m_WwiseExternalsPath.mData, v7->m_WwiseExternalsPath.mLength);
  if ( v5->bIsLanguageSpecific && v6 != 1355168291 )
    UFG::qString::append(v4, v7->m_WwiseLangPath.mData, v7->m_WwiseLangPath.mLength);
  dest = 0;
  v15 = 0i64;
  v16 = 0i64;
  v17 = 0i64;
  v18 = 0;
  v19 = 0;
  v20 = 0;
  UFG::qSPrintf(&dest, "\\%u", v6);
  v11 = -1i64;
  do
    ++v11;
  while ( *(&dest + v11) );
  UFG::qString::append(v4, &dest, v11);
  v12 = v5->uCodecID;
  if ( v12 )
  {
    if ( v12 == 3 )
    {
      v13 = ".xma";
    }
    else
    {
      v13 = ".ogg";
      if ( v12 != 4 )
        v13 = ".wav";
    }
  }
  else
  {
    v13 = ".bnk";
  }
  UFG::qString::append(v4, v13, 4u);
  return 1i64;
}

// File Line: 544
// RVA: 0x149CC0
__int64 __fastcall UFG::LowLevelIODispatcher::Open(UFG::LowLevelIODispatcher *this, const wchar_t *in_pszFileName, AkOpenMode in_eOpenMode, AkFileSystemFlags *in_pFlags, bool *io_bSyncOpen, AkFileDesc *out_fileDesc)
{
  AkFileSystemFlags *v6; // rbp
  AkOpenMode v7; // er14
  const wchar_t *v8; // r15
  __int64 result; // rax
  unsigned int v10; // edi
  AK::StreamMgr::IAkFileLocationResolver **v11; // rbx

  v6 = in_pFlags;
  v7 = in_eOpenMode;
  v8 = in_pszFileName;
  result = 66i64;
  *io_bSyncOpen = 1;
  v10 = 0;
  v11 = this->m_arDevices;
  do
  {
    if ( (_DWORD)result == 1 )
      break;
    if ( *v11 )
      result = (*v11)->vfptr->Open(*v11, v8, v7, v6, io_bSyncOpen, out_fileDesc);
    ++v10;
    ++v11;
  }
  while ( v10 < 3 );
  return result;
}

// File Line: 585
// RVA: 0x149C30
__int64 __fastcall UFG::LowLevelIODispatcher::Open(UFG::LowLevelIODispatcher *this, unsigned int in_fileID, AkOpenMode in_eOpenMode, AkFileSystemFlags *in_pFlags, bool *io_bSyncOpen, AkFileDesc *out_fileDesc)
{
  AkFileSystemFlags *v6; // rbp
  AkOpenMode v7; // er14
  unsigned int v8; // er15
  __int64 result; // rax
  unsigned int v10; // edi
  AK::StreamMgr::IAkFileLocationResolver **v11; // rbx

  v6 = in_pFlags;
  v7 = in_eOpenMode;
  v8 = in_fileID;
  result = 66i64;
  *io_bSyncOpen = 1;
  v10 = 0;
  v11 = this->m_arDevices;
  do
  {
    if ( (_DWORD)result == 1 )
      break;
    if ( *v11 )
      result = (*v11)->vfptr->Open(*v11, v8, v7, v6, io_bSyncOpen, out_fileDesc);
    ++v10;
    ++v11;
  }
  while ( v10 < 3 );
  return result;
}

