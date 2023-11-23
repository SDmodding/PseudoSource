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
__int64 __fastcall CAkBankReader::Init(CAkBankReader *this)
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
__int64 __fastcall CAkBankReader::Term(CAkBankReader *this)
{
  if ( this->m_pBuffer )
  {
    AK::MemoryMgr::Free(g_DefaultPoolId, this->m_pBuffer);
    this->m_pBuffer = 0i64;
    this->m_pReadBufferPtr = 0i64;
  }
  else
  {
    this->m_pReadBufferPtr = 0i64;
  }
  return 1i64;
}

// File Line: 110
// RVA: 0xA5B310
__int64 __fastcall CAkBankReader::SetFile(
        CAkBankReader *this,
        const char *in_pszFilename,
        unsigned int in_uFileOffset,
        __int64 in_pCookie)
{
  __int64 v4; // rsi
  __int64 v6; // rax
  unsigned __int64 v8; // rax
  __int64 v9; // rcx
  signed __int64 v10; // rcx
  void *v11; // rsp
  void *v12; // rsp
  __int64 v13; // rax
  AK::IAkStdStream **p_m_pStream; // r14
  AKRESULT v15; // ebx
  unsigned int v16; // eax
  unsigned int m_ulDeviceBlockSize; // ecx
  AK::IAkStdStream *v19; // rcx
  unsigned int v20; // esi
  int cchWideChara; // [rsp+28h] [rbp-8h]
  int cchWideChar; // [rsp+28h] [rbp-8h]
  wchar_t WideCharStr[4]; // [rsp+30h] [rbp+0h] BYREF
  int v24; // [rsp+38h] [rbp+8h]
  __int64 v25; // [rsp+40h] [rbp+10h]
  __int16 v26; // [rsp+48h] [rbp+18h]
  int v27; // [rsp+4Ch] [rbp+1Ch]
  unsigned int out_rulSizeSkipped; // [rsp+80h] [rbp+50h] BYREF
  __int64 v29; // [rsp+98h] [rbp+68h] BYREF

  v4 = in_uFileOffset;
  v27 = -1;
  *(_QWORD *)WideCharStr = 0i64;
  v24 = 0;
  v26 = 1;
  v25 = in_pCookie;
  v6 = -1i64;
  while ( in_pszFilename[++v6] != 0 )
    ;
  v8 = 2 * v6 + 2;
  v9 = v8 + 15;
  if ( v8 + 15 <= v8 )
    v9 = 0xFFFFFFFFFFFFFF0i64;
  v10 = v9 & 0xFFFFFFFFFFFFFFF0ui64;
  v11 = alloca(v10);
  v12 = alloca(v10);
  v13 = -1i64;
  do
    ++v13;
  while ( in_pszFilename[v13] );
  MultiByteToWideChar(0, 0, in_pszFilename, -1, WideCharStr, v13 + 1);
  p_m_pStream = &this->m_pStream;
  LOBYTE(cchWideChara) = 1;
  v15 = AK::IAkStreamMgr::m_pStreamMgr->vfptr->CreateStd(
          AK::IAkStreamMgr::m_pStreamMgr,
          WideCharStr,
          (AkFileSystemFlags *)WideCharStr,
          AK_OpenModeRead,
          &this->m_pStream,
          cchWideChara);
  if ( v15 == AK_Success
    || (LOBYTE(v26) = 0,
        LOBYTE(cchWideChar) = 1,
        v15 = AK::IAkStreamMgr::m_pStreamMgr->vfptr->CreateStd(
                AK::IAkStreamMgr::m_pStreamMgr,
                WideCharStr,
                (AkFileSystemFlags *)WideCharStr,
                AK_OpenModeRead,
                &this->m_pStream,
                cchWideChar),
        v15 == AK_Success) )
  {
    v16 = (*p_m_pStream)->vfptr->GetBlockSize(*p_m_pStream);
    this->m_ulDeviceBlockSize = v16;
    if ( !v16 )
      return 2i64;
    if ( this->m_ulBufferSize < v16 )
    {
      if ( this->m_pBuffer )
        AK::MemoryMgr::Free(g_DefaultPoolId, this->m_pBuffer);
      m_ulDeviceBlockSize = 0x8000;
      if ( this->m_ulDeviceBlockSize > 0x8000 )
        m_ulDeviceBlockSize = this->m_ulDeviceBlockSize;
      this->m_ulBufferSize = m_ulDeviceBlockSize;
      this->m_pBuffer = (char *)AK::MemoryMgr::Malign(g_DefaultPoolId, m_ulDeviceBlockSize, 0x20u);
    }
    if ( !this->m_pBuffer )
      return 52i64;
    if ( (_DWORD)v4 )
    {
      v19 = *p_m_pStream;
      v29 = 0i64;
      v15 = v19->vfptr->SetPosition(v19, v4, AK_MoveBegin, &v29);
      if ( v15 == AK_Success )
      {
        v20 = v4 - v29;
        v15 = CAkBankReader::Skip(this, v20, &out_rulSizeSkipped);
        if ( out_rulSizeSkipped != v20 )
          return 2;
      }
    }
  }
  return (unsigned int)v15;
}

// File Line: 190
// RVA: 0xA5B4D0
__int64 __fastcall CAkBankReader::SetFile(
        CAkBankReader *this,
        const char *in_pInMemoryFile,
        unsigned int in_ui32FileSize)
{
  this->m_pInMemoryBankReaderPtr = in_pInMemoryFile;
  this->m_ulRemainingBytes = in_ui32FileSize;
  return 1i64;
}

// File Line: 200
// RVA: 0xA5B170
__int64 __fastcall CAkBankReader::SetFile(
        CAkBankReader *this,
        __int64 in_FileID,
        unsigned int in_uFileOffset,
        unsigned int in_codecID,
        void *in_pCookie,
        unsigned int in_bIsLanguageSpecific)
{
  char v6; // bp
  __int64 v8; // rsi
  AK::IAkStdStream **p_m_pStream; // r14
  unsigned int v10; // r15d
  AKRESULT v11; // ebx
  unsigned int v12; // eax
  unsigned int m_ulDeviceBlockSize; // ecx
  AK::IAkStdStream *v15; // rcx
  unsigned int v16; // esi
  bool v17; // [rsp+28h] [rbp-40h]
  BOOL v18; // [rsp+28h] [rbp-40h]
  _DWORD v19[4]; // [rsp+30h] [rbp-38h] BYREF
  void *v20; // [rsp+40h] [rbp-28h]
  char v21; // [rsp+48h] [rbp-20h]
  char v22; // [rsp+49h] [rbp-1Fh]
  int v23; // [rsp+4Ch] [rbp-1Ch]

  v6 = in_bIsLanguageSpecific;
  v19[1] = in_codecID;
  v23 = -1;
  v19[0] = 0;
  v21 = in_bIsLanguageSpecific;
  v19[2] = 0;
  v20 = in_pCookie;
  v22 = 0;
  v8 = in_uFileOffset;
  p_m_pStream = &this->m_pStream;
  v17 = 1;
  v10 = in_FileID;
  v11 = AK::IAkStreamMgr::m_pStreamMgr->vfptr->CreateStd(
          AK::IAkStreamMgr::m_pStreamMgr,
          in_FileID,
          (AkFileSystemFlags *)v19,
          AK_OpenModeRead,
          &this->m_pStream,
          v17);
  if ( v11 == AK_Success )
    goto LABEL_5;
  if ( v6 )
  {
    v21 = 0;
    LOBYTE(v18) = 1;
    v11 = AK::IAkStreamMgr::m_pStreamMgr->vfptr->CreateStd(
            AK::IAkStreamMgr::m_pStreamMgr,
            v10,
            (AkFileSystemFlags *)v19,
            AK_OpenModeRead,
            &this->m_pStream,
            v18);
  }
  if ( v11 == AK_Success )
  {
LABEL_5:
    v12 = (*p_m_pStream)->vfptr->GetBlockSize(*p_m_pStream);
    this->m_ulDeviceBlockSize = v12;
    if ( !v12 )
      return 2i64;
    if ( this->m_ulBufferSize < v12 )
    {
      if ( this->m_pBuffer )
        AK::MemoryMgr::Free(g_DefaultPoolId, this->m_pBuffer);
      m_ulDeviceBlockSize = 0x8000;
      if ( this->m_ulDeviceBlockSize > 0x8000 )
        m_ulDeviceBlockSize = this->m_ulDeviceBlockSize;
      this->m_ulBufferSize = m_ulDeviceBlockSize;
      this->m_pBuffer = (char *)AK::MemoryMgr::Malign(g_DefaultPoolId, m_ulDeviceBlockSize, 0x20u);
    }
    if ( !this->m_pBuffer )
      return 52i64;
    if ( (_DWORD)v8 )
    {
      v15 = *p_m_pStream;
      in_pCookie = 0i64;
      v11 = v15->vfptr->SetPosition(v15, v8, AK_MoveBegin, (__int64 *)&in_pCookie);
      if ( v11 == AK_Success )
      {
        v16 = v8 - (_DWORD)in_pCookie;
        v11 = CAkBankReader::Skip(this, v16, &in_bIsLanguageSpecific);
        if ( in_bIsLanguageSpecific != v16 )
          return 2;
      }
    }
  }
  return (unsigned int)v11;
}

// File Line: 279
// RVA: 0xA5ADB0
__int64 __fastcall CAkBankReader::CloseFile(CAkBankReader *this)
{
  AK::IAkStdStream *m_pStream; // rcx

  m_pStream = this->m_pStream;
  if ( m_pStream )
  {
    (*(void (__fastcall **)(AK::IAkStdStream *))m_pStream->vfptr->gap8)(m_pStream);
    this->m_pStream = 0i64;
  }
  this->m_pInMemoryBankReaderPtr = 0i64;
  this->m_ulRemainingBytes = 0;
  return 1i64;
}

// File Line: 294
// RVA: 0xA5AFF0
char *__fastcall CAkBankReader::GetData(CAkBankReader *this, unsigned int in_uSize)
{
  unsigned int m_ulRemainingBytes; // ecx
  char *result; // rax
  __int64 v6; // rsi
  unsigned int v7; // eax
  int v8; // ecx
  char *v9; // rax
  char *v10; // rsi
  unsigned int v11; // eax
  __int64 v12; // rcx
  unsigned int out_rulSizeRead; // [rsp+30h] [rbp+8h] BYREF

  if ( this->m_pStream )
  {
    m_ulRemainingBytes = this->m_ulRemainingBytes;
    if ( in_uSize <= m_ulRemainingBytes )
    {
      result = this->m_pReadBufferPtr;
      this->m_ulRemainingBytes = m_ulRemainingBytes - in_uSize;
      this->m_pReadBufferPtr = &result[in_uSize];
      return result;
    }
    v6 = 0i64;
    v7 = in_uSize;
    v8 = m_ulRemainingBytes & 0x1F;
    if ( v8 )
    {
      v7 = in_uSize + 31;
      v6 = (unsigned int)(32 - v8);
    }
    v9 = (char *)AK::MemoryMgr::Malign(g_DefaultPoolId, v7, 0x20u);
    this->m_pUserReadBuffer = v9;
    if ( v9 )
    {
      v10 = &v9[v6];
      if ( (unsigned int)CAkBankReader::FillData(this, v10, in_uSize, &out_rulSizeRead) == 1
        && out_rulSizeRead == in_uSize )
      {
        return v10;
      }
      AK::MemoryMgr::Free(g_DefaultPoolId, this->m_pUserReadBuffer);
      this->m_pUserReadBuffer = 0i64;
    }
    return (char *)this->m_pUserReadBuffer;
  }
  else
  {
    v11 = this->m_ulRemainingBytes;
    v12 = v11;
    if ( in_uSize < v11 )
      v12 = in_uSize;
    this->m_ulRemainingBytes = v11 - v12;
    result = (char *)this->m_pInMemoryBankReaderPtr;
    this->m_pInMemoryBankReaderPtr = &result[v12];
  }
  return result;
}

// File Line: 360
// RVA: 0xA5B120
void __fastcall CAkBankReader::ReleaseData(CAkBankReader *this)
{
  void *m_pUserReadBuffer; // rdx

  m_pUserReadBuffer = this->m_pUserReadBuffer;
  if ( m_pUserReadBuffer )
  {
    AK::MemoryMgr::Free(g_DefaultPoolId, m_pUserReadBuffer);
    this->m_pUserReadBuffer = 0i64;
  }
}

// File Line: 373
// RVA: 0xA5ADF0
signed __int64 __fastcall CAkBankReader::FillData(
        CAkBankReader *this,
        char *in_pBufferToFill,
        unsigned int in_ulSizeToRead,
        unsigned int *out_rulSizeRead)
{
  unsigned int *v4; // r15
  unsigned int v5; // ebp
  char *v6; // r14
  unsigned int *p_m_ulRemainingBytes; // r12
  unsigned int v9; // edi
  unsigned int m_ulBufferSize; // eax
  AK::IAkStdStream *m_pStream; // rcx
  AK::IAkStdStreamVtbl *vfptr; // r10
  unsigned int v13; // ebx
  __int64 v14; // rcx
  bool v16; // zf
  unsigned int m_ulRemainingBytes; // eax
  int v18; // [rsp+20h] [rbp-48h]
  char v19; // [rsp+70h] [rbp+8h] BYREF
  unsigned int v20; // [rsp+78h] [rbp+10h] BYREF

  *out_rulSizeRead = 0;
  v4 = out_rulSizeRead;
  v5 = in_ulSizeToRead;
  v6 = in_pBufferToFill;
  if ( this->m_pStream )
  {
    if ( in_ulSizeToRead )
    {
      p_m_ulRemainingBytes = &this->m_ulRemainingBytes;
      do
      {
        if ( *p_m_ulRemainingBytes )
        {
          v9 = v5;
          if ( *p_m_ulRemainingBytes < v5 )
            v9 = *p_m_ulRemainingBytes;
          memmove(v6, this->m_pReadBufferPtr, v9);
          this->m_pReadBufferPtr += v9;
          *v4 += v9;
          *p_m_ulRemainingBytes -= v9;
          v6 += v9;
          v5 -= v9;
        }
        else
        {
          m_ulBufferSize = this->m_ulBufferSize;
          m_pStream = this->m_pStream;
          vfptr = m_pStream->vfptr;
          LOBYTE(out_rulSizeRead) = 1;
          if ( v5 < m_ulBufferSize )
          {
            LOBYTE(v18) = this->m_priority;
            v13 = ((__int64 (__fastcall *)(AK::IAkStdStream *, char *, _QWORD, unsigned int *, int, _DWORD, unsigned int *))vfptr->Read)(
                    m_pStream,
                    this->m_pBuffer,
                    this->m_ulDeviceBlockSize * (m_ulBufferSize / this->m_ulDeviceBlockSize),
                    out_rulSizeRead,
                    v18,
                    (float)(int)(this->m_ulDeviceBlockSize * (m_ulBufferSize / this->m_ulDeviceBlockSize))
                  / this->m_fThroughput,
                    p_m_ulRemainingBytes);
            if ( v13 != 1 || this->m_pStream->vfptr->GetStatus(this->m_pStream) != AK_StmStatusCompleted )
              return v13;
            v16 = *p_m_ulRemainingBytes == 0;
            this->m_pReadBufferPtr = this->m_pBuffer;
            if ( v16 )
              return 1i64;
          }
          else
          {
            LOBYTE(v18) = this->m_priority;
            v13 = ((__int64 (__fastcall *)(AK::IAkStdStream *, char *, _QWORD, unsigned int *, int, _DWORD, unsigned int *))vfptr->Read)(
                    m_pStream,
                    v6,
                    this->m_ulDeviceBlockSize * (v5 / this->m_ulDeviceBlockSize),
                    out_rulSizeRead,
                    v18,
                    (float)(int)(this->m_ulDeviceBlockSize * (v5 / this->m_ulDeviceBlockSize)) / this->m_fThroughput,
                    &v20);
            if ( v13 != 1 || this->m_pStream->vfptr->GetStatus(this->m_pStream) != AK_StmStatusCompleted )
              return v13;
            v14 = v20;
            *v4 += v20;
            v5 -= v14;
            v6 += v14;
            if ( v5 >= this->m_ulBufferSize )
            {
              this->m_pStream->vfptr->GetPosition(this->m_pStream, (bool *)&v19);
              return v13 + 1;
            }
          }
        }
      }
      while ( v5 );
    }
  }
  else
  {
    m_ulRemainingBytes = this->m_ulRemainingBytes;
    if ( in_ulSizeToRead < m_ulRemainingBytes )
      m_ulRemainingBytes = in_ulSizeToRead;
    *out_rulSizeRead = m_ulRemainingBytes;
    this->m_ulRemainingBytes -= m_ulRemainingBytes;
    memmove(in_pBufferToFill, this->m_pInMemoryBankReaderPtr, *out_rulSizeRead);
    this->m_pInMemoryBankReaderPtr += *v4;
  }
  return 1i64;
}

// File Line: 484
// RVA: 0xA5AFB0
signed __int64 __fastcall CAkBankReader::FillDataEx(
        CAkBankReader *this,
        char *in_pBufferToFill,
        unsigned int in_ulSizeToRead)
{
  signed __int64 result; // rax
  unsigned int out_rulSizeRead; // [rsp+48h] [rbp+20h] BYREF

  out_rulSizeRead = 0;
  result = CAkBankReader::FillData(this, in_pBufferToFill, in_ulSizeToRead, &out_rulSizeRead);
  if ( (_DWORD)result == 1 && in_ulSizeToRead != out_rulSizeRead )
    return 56i64;
  return result;
}

// File Line: 496
// RVA: 0xA5B4E0
__int64 __fastcall CAkBankReader::Skip(
        CAkBankReader *this,
        unsigned int in_ulNumBytesToSkip,
        unsigned int *out_rulSizeSkipped,
        __int64 a4)
{
  unsigned int v5; // ebx
  unsigned int v7; // ebp
  unsigned int *p_m_ulRemainingBytes; // r14
  unsigned int v9; // ecx
  AK::IAkStdStream *m_pStream; // rcx
  unsigned int v11; // eax
  unsigned int m_ulRemainingBytes; // eax
  __int64 v14; // [rsp+60h] [rbp+8h] BYREF

  *out_rulSizeSkipped = 0;
  v5 = in_ulNumBytesToSkip;
  v7 = 1;
  if ( !this->m_pStream )
  {
    m_ulRemainingBytes = this->m_ulRemainingBytes;
    if ( in_ulNumBytesToSkip < m_ulRemainingBytes )
      m_ulRemainingBytes = in_ulNumBytesToSkip;
    *out_rulSizeSkipped = m_ulRemainingBytes;
    this->m_ulRemainingBytes -= m_ulRemainingBytes;
    this->m_pInMemoryBankReaderPtr += *out_rulSizeSkipped;
    return v7;
  }
  if ( in_ulNumBytesToSkip )
  {
    p_m_ulRemainingBytes = &this->m_ulRemainingBytes;
    do
    {
      if ( *p_m_ulRemainingBytes )
      {
        v9 = v5;
        if ( *p_m_ulRemainingBytes < v5 )
          v9 = *p_m_ulRemainingBytes;
        this->m_pReadBufferPtr += v9;
        *out_rulSizeSkipped += v9;
        *p_m_ulRemainingBytes -= v9;
      }
      else
      {
        m_pStream = this->m_pStream;
        if ( v5 <= this->m_ulBufferSize )
        {
          v11 = this->m_ulBufferSize / this->m_ulDeviceBlockSize;
          LOBYTE(a4) = 1;
          v7 = ((__int64 (__fastcall *)(AK::IAkStdStream *, char *, _QWORD, __int64, char, _DWORD, unsigned int *))m_pStream->vfptr->Read)(
                 m_pStream,
                 this->m_pBuffer,
                 this->m_ulDeviceBlockSize * v11,
                 a4,
                 this->m_priority,
                 (float)(int)(this->m_ulDeviceBlockSize * v11) / this->m_fThroughput,
                 p_m_ulRemainingBytes);
          if ( v7 == 1 && this->m_pStream->vfptr->GetStatus(this->m_pStream) == AK_StmStatusCompleted )
          {
            this->m_pStream->vfptr->GetPosition(this->m_pStream, (bool *)&v14);
            if ( (_BYTE)v14 && *p_m_ulRemainingBytes < v5 )
              return v7 + 1;
            this->m_pReadBufferPtr = &this->m_pBuffer[v5];
            *out_rulSizeSkipped += v5;
            *p_m_ulRemainingBytes -= v5;
          }
          return v7;
        }
        v7 = m_pStream->vfptr->SetPosition(m_pStream, v5, AK_MoveCurrent, &v14);
        if ( v7 != 1 )
          return v7;
        v9 = v14;
        *out_rulSizeSkipped += v14;
      }
      v5 -= v9;
    }
    while ( v5 );
  }
  return v7;
}

