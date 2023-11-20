// File Line: 45
// RVA: 0xA5AD80
void __fastcall CAkBankReader::CAkBankReader(CAkBankReader *this)
{
  this->m_pBuffer = 0i64;
  this->m_pReadBufferPtr = 0i64;
  *(_QWORD *)&this->m_ulRemainingBytes = 0i64;
  this->m_ulDeviceBlockSize = 0;
  this->m_pUserReadBuffer = 0i64;
  this->m_pInMemoryBankReaderPtr = 0i64;
  this->m_pStream = 0i64;
  this->m_bIsInitDone = 0;
}

// File Line: 53
// RVA: 0xA5B0F0
signed __int64 __fastcall CAkBankReader::Init(CAkBankReader *this)
{
  if ( this->m_bIsInitDone )
    return 2i64;
  *(_WORD *)&this->m_priority = 306;
  this->m_fThroughput = 1048.576;
  *(_QWORD *)&this->m_ulRemainingBytes = 0i64;
  this->m_pBuffer = 0i64;
  this->m_pReadBufferPtr = 0i64;
  return 1i64;
}

// File Line: 76
// RVA: 0xA5B150
void __fastcall CAkBankReader::Reset(CAkBankReader *this)
{
  this->m_pReadBufferPtr = this->m_pBuffer;
  this->m_ulRemainingBytes = 0;
  this->m_pInMemoryBankReaderPtr = 0i64;
}

// File Line: 84
// RVA: 0xA5B630
signed __int64 __fastcall CAkBankReader::Term(CAkBankReader *this)
{
  CAkBankReader *v1; // rbx

  v1 = this;
  if ( this->m_pBuffer )
  {
    AK::MemoryMgr::Free(g_DefaultPoolId, this->m_pBuffer);
    v1->m_pBuffer = 0i64;
    v1->m_pReadBufferPtr = 0i64;
  }
  else
  {
    this->m_pReadBufferPtr = 0i64;
  }
  return 1i64;
}

// File Line: 110
// RVA: 0xA5B310
signed __int64 __fastcall CAkBankReader::SetFile(CAkBankReader *this, const char *in_pszFilename, unsigned int in_uFileOffset, void *in_pCookie)
{
  __int64 v4; // rsi
  CAkBankReader *v5; // rdi
  signed __int64 v6; // rax
  unsigned __int64 v8; // rax
  signed __int64 v9; // rcx
  signed __int64 v10; // rcx
  void *v11; // rsp
  void *v12; // rsp
  signed __int64 v13; // rax
  signed __int64 v14; // r14
  _BOOL8 v15; // ST28_8
  AKRESULT v16; // ebx
  unsigned int v17; // eax
  unsigned int v19; // ecx
  __int64 v20; // rcx
  unsigned int v21; // esi
  _BOOL8 cchWideChar; // [rsp+28h] [rbp-8h]
  wchar_t WideCharStr[4]; // [rsp+30h] [rbp+0h]
  int v24; // [rsp+38h] [rbp+8h]
  void *v25; // [rsp+40h] [rbp+10h]
  __int16 v26; // [rsp+48h] [rbp+18h]
  int v27; // [rsp+4Ch] [rbp+1Ch]
  unsigned int out_rulSizeSkipped; // [rsp+80h] [rbp+50h]
  __int64 v29; // [rsp+98h] [rbp+68h]

  v4 = in_uFileOffset;
  v5 = this;
  v27 = -1;
  *(_QWORD *)WideCharStr = 0i64;
  v24 = 0;
  v26 = 1;
  v25 = in_pCookie;
  v6 = -1i64;
  while ( in_pszFilename[v6++ + 1] != 0 )
    ;
  v8 = 2 * v6 + 2;
  v9 = v8 + 15;
  if ( v8 + 15 <= v8 )
    v9 = 1152921504606846960i64;
  v10 = v9 & 0xFFFFFFFFFFFFFFF0ui64;
  v11 = alloca(v10);
  v12 = alloca(v10);
  v13 = -1i64;
  do
    ++v13;
  while ( in_pszFilename[v13] );
  MultiByteToWideChar(0, 0, in_pszFilename, -1, WideCharStr, v13 + 1);
  v14 = (signed __int64)&v5->m_pStream;
  LOBYTE(v15) = 1;
  v16 = ((unsigned int (__fastcall *)(AK::IAkStreamMgr *, wchar_t *, wchar_t *, _QWORD, AK::IAkStdStream **, _BOOL8, _QWORD, _QWORD, void *, _QWORD))AK::IAkStreamMgr::m_pStreamMgr->vfptr->CreateStd)(
          AK::IAkStreamMgr::m_pStreamMgr,
          WideCharStr,
          WideCharStr,
          0i64,
          &v5->m_pStream,
          v15,
          *(_QWORD *)WideCharStr,
          *(_QWORD *)&v24,
          v25,
          *(_QWORD *)&v26);
  if ( v16 == 1
    || (LOBYTE(v26) = 0,
        LOBYTE(cchWideChar) = 1,
        v16 = (unsigned int)AK::IAkStreamMgr::m_pStreamMgr->vfptr->CreateStd(
                              AK::IAkStreamMgr::m_pStreamMgr,
                              WideCharStr,
                              (AkFileSystemFlags *)WideCharStr,
                              0i64,
                              &v5->m_pStream,
                              cchWideChar),
        v16 == 1) )
  {
    v17 = (*(__int64 (**)(void))(**(_QWORD **)v14 + 40i64))();
    v5->m_ulDeviceBlockSize = v17;
    if ( !v17 )
      return 2i64;
    if ( v5->m_ulBufferSize < v17 )
    {
      if ( v5->m_pBuffer )
        AK::MemoryMgr::Free(g_DefaultPoolId, v5->m_pBuffer);
      v19 = 0x8000;
      if ( v5->m_ulDeviceBlockSize > 0x8000 )
        v19 = v5->m_ulDeviceBlockSize;
      v5->m_ulBufferSize = v19;
      v5->m_pBuffer = (char *)AK::MemoryMgr::Malign(g_DefaultPoolId, v19, 0x20u);
    }
    if ( !v5->m_pBuffer )
      return 52i64;
    if ( (_DWORD)v4 )
    {
      v20 = *(_QWORD *)v14;
      v29 = 0i64;
      v16 = (*(unsigned int (__fastcall **)(__int64, __int64, _QWORD, __int64 *))(*(_QWORD *)v20 + 72i64))(
              v20,
              v4,
              0i64,
              &v29);
      if ( v16 == 1 )
      {
        v21 = v4 - v29;
        v16 = CAkBankReader::Skip(v5, v21, &out_rulSizeSkipped);
        if ( out_rulSizeSkipped != v21 )
          v16 = 2;
      }
    }
  }
  return (unsigned int)v16;
}

// File Line: 190
// RVA: 0xA5B4D0
signed __int64 __fastcall CAkBankReader::SetFile(CAkBankReader *this, const void *in_pInMemoryFile, unsigned int in_ui32FileSize)
{
  this->m_pInMemoryBankReaderPtr = (const char *)in_pInMemoryFile;
  this->m_ulRemainingBytes = in_ui32FileSize;
  return 1i64;
}

// File Line: 200
// RVA: 0xA5B170
signed __int64 __fastcall CAkBankReader::SetFile(CAkBankReader *this, __int64 in_FileID, unsigned int in_uFileOffset, unsigned int in_codecID, void *in_pCookie, bool in_bIsLanguageSpecific)
{
  bool v6; // bp
  CAkBankReader *v7; // rdi
  __int64 v8; // rsi
  AK::IAkStdStream **v9; // r14
  char v10; // ST28_1
  unsigned int v11; // er15
  AKRESULT v12; // ebx
  unsigned int v13; // eax
  unsigned int v15; // ecx
  AK::IAkStdStream *v16; // rcx
  unsigned int v17; // esi
  _BOOL8 v18; // [rsp+28h] [rbp-40h]
  int v19; // [rsp+30h] [rbp-38h]
  unsigned int v20; // [rsp+34h] [rbp-34h]
  int v21; // [rsp+38h] [rbp-30h]
  void *v22; // [rsp+40h] [rbp-28h]
  __int16 v23; // [rsp+48h] [rbp-20h]
  int v24; // [rsp+4Ch] [rbp-1Ch]

  v6 = in_bIsLanguageSpecific;
  v20 = in_codecID;
  v24 = -1;
  v19 = 0;
  v23 = in_bIsLanguageSpecific;
  v7 = this;
  v21 = 0;
  v22 = in_pCookie;
  v8 = in_uFileOffset;
  v9 = &this->m_pStream;
  v10 = 1;
  v11 = in_FileID;
  v12 = ((unsigned int (__fastcall *)(AK::IAkStreamMgr *, __int64, int *, _QWORD, AK::IAkStdStream **, char, _QWORD, _QWORD, void *, _QWORD))AK::IAkStreamMgr::m_pStreamMgr->vfptr->CreateStd)(
          AK::IAkStreamMgr::m_pStreamMgr,
          in_FileID,
          &v19,
          0i64,
          &this->m_pStream,
          v10,
          *(_QWORD *)&v19,
          *(_QWORD *)&v21,
          in_pCookie,
          *(_QWORD *)&v23);
  if ( v12 == 1 )
    goto LABEL_22;
  if ( v6 )
  {
    LOBYTE(v23) = 0;
    LOBYTE(v18) = 1;
    v12 = (unsigned int)AK::IAkStreamMgr::m_pStreamMgr->vfptr->CreateStd(
                          AK::IAkStreamMgr::m_pStreamMgr,
                          v11,
                          (AkFileSystemFlags *)&v19,
                          0i64,
                          &v7->m_pStream,
                          v18);
  }
  if ( v12 == 1 )
  {
LABEL_22:
    v13 = ((__int64 (*)(void))(*v9)->vfptr->GetBlockSize)();
    v7->m_ulDeviceBlockSize = v13;
    if ( !v13 )
      return 2i64;
    if ( v7->m_ulBufferSize < v13 )
    {
      if ( v7->m_pBuffer )
        AK::MemoryMgr::Free(g_DefaultPoolId, v7->m_pBuffer);
      v15 = 0x8000;
      if ( v7->m_ulDeviceBlockSize > 0x8000 )
        v15 = v7->m_ulDeviceBlockSize;
      v7->m_ulBufferSize = v15;
      v7->m_pBuffer = (char *)AK::MemoryMgr::Malign(g_DefaultPoolId, v15, 0x20u);
    }
    if ( !v7->m_pBuffer )
      return 52i64;
    if ( (_DWORD)v8 )
    {
      v16 = *v9;
      in_pCookie = 0i64;
      v12 = (unsigned int)v16->vfptr->SetPosition(v16, v8, 0i64, (__int64 *)&in_pCookie);
      if ( v12 == 1 )
      {
        v17 = v8 - (_DWORD)in_pCookie;
        v12 = CAkBankReader::Skip(v7, v17, (unsigned int *)&in_bIsLanguageSpecific);
        if ( in_bIsLanguageSpecific != v17 )
          v12 = 2;
      }
    }
  }
  return (unsigned int)v12;
}

// File Line: 279
// RVA: 0xA5ADB0
signed __int64 __fastcall CAkBankReader::CloseFile(CAkBankReader *this)
{
  CAkBankReader *v1; // rbx
  AK::IAkStdStream *v2; // rcx

  v1 = this;
  v2 = this->m_pStream;
  if ( v2 )
  {
    (*(void (**)(void))v2->vfptr->gap8)();
    v1->m_pStream = 0i64;
  }
  v1->m_pInMemoryBankReaderPtr = 0i64;
  v1->m_ulRemainingBytes = 0;
  return 1i64;
}

// File Line: 294
// RVA: 0xA5AFF0
char *__fastcall CAkBankReader::GetData(CAkBankReader *this, unsigned int in_uSize)
{
  unsigned int v2; // edi
  CAkBankReader *v3; // rbx
  unsigned int v4; // ecx
  char *result; // rax
  __int64 v6; // rsi
  unsigned int v7; // eax
  int v8; // ecx
  char *v9; // rax
  char *v10; // rsi
  unsigned int v11; // eax
  __int64 v12; // rcx
  unsigned int out_rulSizeRead; // [rsp+30h] [rbp+8h]

  v2 = in_uSize;
  v3 = this;
  if ( this->m_pStream )
  {
    v4 = this->m_ulRemainingBytes;
    if ( in_uSize <= v4 )
    {
      result = v3->m_pReadBufferPtr;
      v3->m_ulRemainingBytes = v4 - in_uSize;
      v3->m_pReadBufferPtr = &result[in_uSize];
      return result;
    }
    v6 = 0i64;
    v7 = in_uSize;
    v8 = v4 & 0x1F;
    if ( v8 )
    {
      v7 = in_uSize + 31;
      v6 = (unsigned int)(32 - v8);
    }
    v9 = (char *)AK::MemoryMgr::Malign(g_DefaultPoolId, v7, 0x20u);
    v3->m_pUserReadBuffer = v9;
    if ( v9 )
    {
      v10 = &v9[v6];
      if ( (unsigned int)CAkBankReader::FillData(v3, v10, v2, &out_rulSizeRead) == 1 && out_rulSizeRead == v2 )
        return v10;
      AK::MemoryMgr::Free(g_DefaultPoolId, v3->m_pUserReadBuffer);
      v3->m_pUserReadBuffer = 0i64;
    }
    result = (char *)v3->m_pUserReadBuffer;
  }
  else
  {
    v11 = this->m_ulRemainingBytes;
    v12 = v11;
    if ( in_uSize < v11 )
      v12 = in_uSize;
    v3->m_ulRemainingBytes = v11 - v12;
    result = (char *)v3->m_pInMemoryBankReaderPtr;
    v3->m_pInMemoryBankReaderPtr = &result[v12];
  }
  return result;
}

// File Line: 360
// RVA: 0xA5B120
void __fastcall CAkBankReader::ReleaseData(CAkBankReader *this)
{
  void *v1; // rdx
  CAkBankReader *v2; // rbx

  v1 = this->m_pUserReadBuffer;
  v2 = this;
  if ( v1 )
  {
    AK::MemoryMgr::Free(g_DefaultPoolId, v1);
    v2->m_pUserReadBuffer = 0i64;
  }
}

// File Line: 373
// RVA: 0xA5ADF0
signed __int64 __fastcall CAkBankReader::FillData(CAkBankReader *this, void *in_pBufferToFill, unsigned int in_ulSizeToRead, unsigned int *out_rulSizeRead)
{
  unsigned int *v4; // r15
  unsigned int v5; // ebp
  char *v6; // r14
  CAkBankReader *v7; // rsi
  unsigned int *v8; // r12
  unsigned int v9; // edi
  unsigned int v10; // eax
  AK::IAkStdStream *v11; // rcx
  AK::IAkStdStreamVtbl *v12; // r10
  int v13; // eax
  unsigned int v14; // ebx
  __int64 v15; // rcx
  int v17; // eax
  bool v18; // zf
  unsigned int v19; // eax
  __int64 v20; // [rsp+20h] [rbp-48h]
  __int64 v21; // [rsp+28h] [rbp-40h]
  char v22; // [rsp+70h] [rbp+8h]
  unsigned int v23; // [rsp+78h] [rbp+10h]

  *out_rulSizeRead = 0;
  v4 = out_rulSizeRead;
  v5 = in_ulSizeToRead;
  v6 = (char *)in_pBufferToFill;
  v7 = this;
  if ( this->m_pStream )
  {
    if ( in_ulSizeToRead )
    {
      v8 = &this->m_ulRemainingBytes;
      do
      {
        if ( *v8 )
        {
          v9 = v5;
          if ( *v8 < v5 )
            v9 = *v8;
          memmove(v6, v7->m_pReadBufferPtr, v9);
          v7->m_pReadBufferPtr += v9;
          *v4 += v9;
          *v8 -= v9;
          v6 += v9;
          v5 -= v9;
        }
        else
        {
          v10 = v7->m_ulBufferSize;
          v11 = v7->m_pStream;
          v12 = v11->vfptr;
          LOBYTE(out_rulSizeRead) = 1;
          if ( v5 < v10 )
          {
            v17 = v10 / v7->m_ulDeviceBlockSize;
            *(float *)&v21 = (float)(v7->m_ulDeviceBlockSize * v17) / v7->m_fThroughput;
            LOBYTE(v20) = v7->m_priority;
            v14 = ((__int64 (__fastcall *)(AK::IAkStdStream *, char *, _QWORD, unsigned int *, __int64, __int64, unsigned int *))v12->Read)(
                    v11,
                    v7->m_pBuffer,
                    v7->m_ulDeviceBlockSize * v17,
                    out_rulSizeRead,
                    v20,
                    v21,
                    v8);
            if ( v14 != 1 || ((unsigned int (*)(void))v7->m_pStream->vfptr->GetStatus)() != 1 )
              return v14;
            v18 = *v8 == 0;
            v7->m_pReadBufferPtr = v7->m_pBuffer;
            if ( v18 )
              return 1i64;
          }
          else
          {
            v13 = v5 / v7->m_ulDeviceBlockSize;
            *(float *)&v21 = (float)(v7->m_ulDeviceBlockSize * v13) / v7->m_fThroughput;
            LOBYTE(v20) = v7->m_priority;
            v14 = ((__int64 (__fastcall *)(AK::IAkStdStream *, char *, _QWORD, unsigned int *, __int64, __int64, unsigned int *))v12->Read)(
                    v11,
                    v6,
                    v7->m_ulDeviceBlockSize * v13,
                    out_rulSizeRead,
                    v20,
                    v21,
                    &v23);
            if ( v14 != 1 || ((unsigned int (*)(void))v7->m_pStream->vfptr->GetStatus)() != 1 )
              return v14;
            v15 = v23;
            *v4 += v23;
            v5 -= v15;
            v6 += v15;
            if ( v5 >= v7->m_ulBufferSize )
            {
              v7->m_pStream->vfptr->GetPosition(v7->m_pStream, (bool *)&v22);
              return v14 + 1;
            }
          }
        }
      }
      while ( v5 );
    }
  }
  else
  {
    v19 = this->m_ulRemainingBytes;
    if ( in_ulSizeToRead < v19 )
      v19 = in_ulSizeToRead;
    *out_rulSizeRead = v19;
    this->m_ulRemainingBytes -= v19;
    memmove(in_pBufferToFill, this->m_pInMemoryBankReaderPtr, *out_rulSizeRead);
    v7->m_pInMemoryBankReaderPtr += *v4;
  }
  return 1i64;
}

// File Line: 484
// RVA: 0xA5AFB0
signed __int64 __fastcall CAkBankReader::FillDataEx(CAkBankReader *this, void *in_pBufferToFill, unsigned int in_ulSizeToRead)
{
  unsigned int v3; // ebx
  signed __int64 result; // rax
  unsigned int out_rulSizeRead; // [rsp+48h] [rbp+20h]

  v3 = in_ulSizeToRead;
  out_rulSizeRead = 0;
  result = CAkBankReader::FillData(this, in_pBufferToFill, in_ulSizeToRead, &out_rulSizeRead);
  if ( (_DWORD)result == 1 && v3 != out_rulSizeRead )
    result = 56i64;
  return result;
}

// File Line: 496
// RVA: 0xA5B4E0
__int64 __fastcall CAkBankReader::Skip(CAkBankReader *this, unsigned int in_ulNumBytesToSkip, unsigned int *out_rulSizeSkipped, __int64 a4)
{
  unsigned int *v4; // rsi
  unsigned int v5; // ebx
  CAkBankReader *v6; // rdi
  unsigned int v7; // ebp
  unsigned int *v8; // r14
  unsigned int v9; // ecx
  AK::IAkStdStream *v10; // rcx
  int v11; // eax
  unsigned int v13; // eax
  __int64 v14; // [rsp+60h] [rbp+8h]

  *out_rulSizeSkipped = 0;
  v4 = out_rulSizeSkipped;
  v5 = in_ulNumBytesToSkip;
  v6 = this;
  v7 = 1;
  if ( !this->m_pStream )
  {
    v13 = this->m_ulRemainingBytes;
    if ( in_ulNumBytesToSkip < v13 )
      v13 = in_ulNumBytesToSkip;
    *out_rulSizeSkipped = v13;
    this->m_ulRemainingBytes -= v13;
    this->m_pInMemoryBankReaderPtr += *out_rulSizeSkipped;
    return v7;
  }
  if ( in_ulNumBytesToSkip )
  {
    v8 = &this->m_ulRemainingBytes;
    do
    {
      if ( *v8 )
      {
        v9 = v5;
        if ( *v8 < v5 )
          v9 = *v8;
        v6->m_pReadBufferPtr += v9;
        *v4 += v9;
        *v8 -= v9;
      }
      else
      {
        v10 = v6->m_pStream;
        if ( v5 <= v6->m_ulBufferSize )
        {
          v11 = v6->m_ulBufferSize / v6->m_ulDeviceBlockSize;
          LOBYTE(a4) = 1;
          v7 = ((__int64 (__fastcall *)(AK::IAkStdStream *, char *, _QWORD, __int64, char, _DWORD, unsigned int *))v10->vfptr->Read)(
                 v10,
                 v6->m_pBuffer,
                 v6->m_ulDeviceBlockSize * v11,
                 a4,
                 v6->m_priority,
                 (float)(v6->m_ulDeviceBlockSize * v11) / v6->m_fThroughput,
                 v8);
          if ( v7 == 1 && ((unsigned int (*)(void))v6->m_pStream->vfptr->GetStatus)() == 1 )
          {
            v6->m_pStream->vfptr->GetPosition(v6->m_pStream, (bool *)&v14);
            if ( (_BYTE)v14 && *v8 < v5 )
              return v7 + 1;
            v6->m_pReadBufferPtr = &v6->m_pBuffer[v5];
            *v4 += v5;
            *v8 -= v5;
          }
          return v7;
        }
        v7 = v10->vfptr->SetPosition(v10, v5, AK_MoveCurrent, &v14);
        if ( v7 != 1 )
          return v7;
        v9 = v14;
        *v4 += v14;
      }
      v5 -= v9;
    }
    while ( v5 );
  }
  return v7;
}

