// File Line: 37
// RVA: 0x140BE0
void __fastcall UFG::WwiseFileLocationBase::WwiseFileLocationBase(UFG::WwiseFileLocationBase *this)
{
  this->vfptr = (UFG::WwiseFileLocationBaseVtbl *)&UFG::WwiseFileLocationBase::`vftable;
  UFG::qString::qString(&this->m_WwiseBasePath, &customCaption);
  UFG::qString::qString(&this->m_WwiseBankPath, &customCaption);
  UFG::qString::qString(&this->m_WwiseLangPath, &customCaption);
  UFG::qString::qString(&this->m_WwiseSrcPath, &customCaption);
  UFG::qString::qString(&this->m_WwiseExternalsPath);
  UFG::qString::qString(&this->m_WwiseDLCPath);
}

// File Line: 42
// RVA: 0x141810
void __fastcall UFG::WwiseFileLocationBase::~WwiseFileLocationBase(UFG::WwiseFileLocationBase *this)
{
  this->vfptr = (UFG::WwiseFileLocationBaseVtbl *)&UFG::WwiseFileLocationBase::`vftable;
  UFG::qString::~qString(&this->m_WwiseDLCPath);
  UFG::qString::~qString(&this->m_WwiseExternalsPath);
  UFG::qString::~qString(&this->m_WwiseSrcPath);
  UFG::qString::~qString(&this->m_WwiseLangPath);
  UFG::qString::~qString(&this->m_WwiseBankPath);
  UFG::qString::~qString(&this->m_WwiseBasePath);
}

// File Line: 85
// RVA: 0x143760
signed __int64 __fastcall UFG::WwiseFileLocationBase::BuildFilePath(
        UFG::WwiseFileLocationBase *this,
        const wchar_t *in_FileName,
        AkFileSystemFlags *in_pFlags,
        UFG::qString *out_FullFilePath)
{
  char v8; // bp
  char *pCustomParam; // rax
  int mLength; // r8d
  char *mData; // rdx
  char *v12; // rbx
  unsigned int v13; // eax
  UFG::qString result; // [rsp+38h] [rbp-30h] BYREF

  if ( !in_FileName )
    return 1i64;
  v8 = 0;
  if ( in_pFlags )
  {
    pCustomParam = (char *)in_pFlags->pCustomParam;
    if ( pCustomParam )
      v8 = *pCustomParam;
  }
  UFG::qString::Set(out_FullFilePath, this->m_WwiseBasePath.mData, this->m_WwiseBasePath.mLength, 0i64, 0);
  if ( v8 )
  {
    mLength = this->m_WwiseDLCPath.mLength;
    mData = this->m_WwiseDLCPath.mData;
  }
  else
  {
    if ( !in_pFlags || in_pFlags->uCompanyID || in_pFlags->uCodecID )
      goto LABEL_12;
    mLength = this->m_WwiseBankPath.mLength;
    mData = this->m_WwiseBankPath.mData;
  }
  UFG::qString::append(out_FullFilePath, mData, mLength);
LABEL_12:
  UFG::ConvertAkLpCtstrToChar(&result, in_FileName);
  if ( !(unsigned int)UFG::qString::StartsWith(&result, "\\", -1)
    && !(unsigned int)UFG::qString::EndsWith(out_FullFilePath, "\\", -1) )
  {
    UFG::qString::operator+=(out_FullFilePath, "\\");
  }
  v12 = result.mData;
  v13 = UFG::qStringLength(result.mData);
  UFG::qString::append(out_FullFilePath, v12, v13);
  UFG::qString::~qString(&result);
  return 1i64;
}

// File Line: 141
// RVA: 0x143600
__int64 __fastcall UFG::WwiseFileLocationBase::BuildFilePath(
        UFG::WwiseFileLocationBase *this,
        unsigned int in_fileID,
        AkFileSystemFlags *in_pFlags,
        UFG::qString *out_FullFilePath)
{
  int mLength; // r8d
  char *mData; // rdx
  __int64 v11; // r8
  unsigned int uCodecID; // eax
  const char *v13; // rdx
  char dest; // [rsp+30h] [rbp-28h] BYREF
  __int64 v15; // [rsp+31h] [rbp-27h]
  __int64 v16; // [rsp+39h] [rbp-1Fh]
  __int64 v17; // [rsp+41h] [rbp-17h]
  int v18; // [rsp+49h] [rbp-Fh]
  __int16 v19; // [rsp+4Dh] [rbp-Bh]
  char v20; // [rsp+4Fh] [rbp-9h]

  if ( !in_pFlags )
    return 2i64;
  UFG::qString::Set(out_FullFilePath, this->m_WwiseBasePath.mData, this->m_WwiseBasePath.mLength, 0i64, 0);
  if ( in_pFlags->uCodecID )
  {
    mLength = this->m_WwiseSrcPath.mLength;
    mData = this->m_WwiseSrcPath.mData;
  }
  else
  {
    mLength = this->m_WwiseBankPath.mLength;
    mData = this->m_WwiseBankPath.mData;
  }
  UFG::qString::append(out_FullFilePath, mData, mLength);
  if ( in_pFlags->uCompanyID == 1 )
    UFG::qString::append(out_FullFilePath, this->m_WwiseExternalsPath.mData, this->m_WwiseExternalsPath.mLength);
  if ( in_pFlags->bIsLanguageSpecific && in_fileID != 1355168291 )
    UFG::qString::append(out_FullFilePath, this->m_WwiseLangPath.mData, this->m_WwiseLangPath.mLength);
  dest = 0;
  v15 = 0i64;
  v16 = 0i64;
  v17 = 0i64;
  v18 = 0;
  v19 = 0;
  v20 = 0;
  UFG::qSPrintf(&dest, "\\%u", in_fileID);
  v11 = -1i64;
  do
    ++v11;
  while ( *(&dest + v11) );
  UFG::qString::append(out_FullFilePath, &dest, v11);
  uCodecID = in_pFlags->uCodecID;
  if ( uCodecID )
  {
    if ( uCodecID == 3 )
    {
      v13 = ".xma";
    }
    else
    {
      v13 = ".ogg";
      if ( uCodecID != 4 )
        v13 = ".wav";
    }
  }
  else
  {
    v13 = ".bnk";
  }
  UFG::qString::append(out_FullFilePath, v13, 4u);
  return 1i64;
}

// File Line: 544
// RVA: 0x149CC0
__int64 __fastcall UFG::LowLevelIODispatcher::Open(
        UFG::LowLevelIODispatcher *this,
        const wchar_t *in_pszFileName,
        unsigned int in_eOpenMode,
        AkFileSystemFlags *in_pFlags,
        bool *io_bSyncOpen,
        AkFileDesc *out_fileDesc)
{
  __int64 result; // rax
  unsigned int v10; // edi
  AK::StreamMgr::IAkFileLocationResolver **m_arDevices; // rbx

  result = 66i64;
  *io_bSyncOpen = 1;
  v10 = 0;
  m_arDevices = this->m_arDevices;
  do
  {
    if ( (_DWORD)result == 1 )
      break;
    if ( *m_arDevices )
      result = ((__int64 (__fastcall *)(AK::StreamMgr::IAkFileLocationResolver *, const wchar_t *, _QWORD, AkFileSystemFlags *, bool *, AkFileDesc *))(*m_arDevices)->vfptr->Open)(
                 *m_arDevices,
                 in_pszFileName,
                 in_eOpenMode,
                 in_pFlags,
                 io_bSyncOpen,
                 out_fileDesc);
    ++v10;
    ++m_arDevices;
  }
  while ( v10 < 3 );
  return result;
}

// File Line: 585
// RVA: 0x149C30
__int64 __fastcall UFG::LowLevelIODispatcher::Open(
        UFG::LowLevelIODispatcher *this,
        unsigned int in_fileID,
        unsigned int in_eOpenMode,
        AkFileSystemFlags *in_pFlags,
        bool *io_bSyncOpen,
        AkFileDesc *out_fileDesc)
{
  __int64 result; // rax
  unsigned int v10; // edi
  AK::StreamMgr::IAkFileLocationResolver **m_arDevices; // rbx

  result = 66i64;
  *io_bSyncOpen = 1;
  v10 = 0;
  m_arDevices = this->m_arDevices;
  do
  {
    if ( (_DWORD)result == 1 )
      break;
    if ( *m_arDevices )
      result = ((__int64 (__fastcall *)(AK::StreamMgr::IAkFileLocationResolver *, _QWORD, _QWORD, AkFileSystemFlags *, bool *, AkFileDesc *))(*m_arDevices)->vfptr->Open)(
                 *m_arDevices,
                 in_fileID,
                 in_eOpenMode,
                 in_pFlags,
                 io_bSyncOpen,
                 out_fileDesc);
    ++v10;
    ++m_arDevices;
  }
  while ( v10 < 3 );
  return result;
}

