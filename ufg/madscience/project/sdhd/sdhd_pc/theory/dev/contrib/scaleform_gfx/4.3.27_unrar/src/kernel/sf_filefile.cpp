// File Line: 82
// RVA: 0x94D000
void __fastcall Scaleform::SysErrorModeDisabler::~SysErrorModeDisabler(Scaleform::SysErrorModeDisabler *this)
{
  if ( this->Disabled )
    SetErrorMode(this->OldMode);
}

// File Line: 193
// RVA: 0x93BA30
void __fastcall Scaleform::FILEFile::FILEFile(
        Scaleform::FILEFile *this,
        Scaleform::String *fileName,
        int flags,
        int mode)
{
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::File,2>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::File::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::FILEFile::`vftable;
  Scaleform::String::String(&this->FileName, fileName);
  this->OpenFlags = flags;
  Scaleform::FILEFile::init(this);
}

// File Line: 219
// RVA: 0x9E80F0
void __fastcall Scaleform::FILEFile::init(Scaleform::FILEFile *this)
{
  int OpenFlags; // eax
  char *v3; // rsi
  int v4; // r14d
  UINT v5; // r15d
  __int64 i; // rbx
  unsigned __int64 v7; // rbx
  wchar_t *v8; // rdi
  _iobuf *fs; // rcx
  bool v10; // al
  int v11; // ecx
  wchar_t pbuff[40]; // [rsp+28h] [rbp-50h] BYREF
  UINT v13; // [rsp+84h] [rbp+Ch]
  char *putf8Buffer; // [rsp+88h] [rbp+10h] BYREF

  OpenFlags = this->OpenFlags;
  if ( (OpenFlags & 4) != 0 )
  {
    v3 = "w+b";
    if ( (OpenFlags & 1) == 0 )
      v3 = "wb";
  }
  else if ( (OpenFlags & 8) != 0 )
  {
    v3 = "a+b";
    if ( (OpenFlags & 1) == 0 )
      v3 = "ab";
  }
  else
  {
    v3 = "r+b";
    if ( (OpenFlags & 2) == 0 )
      v3 = "rb";
  }
  if ( (this->FileName.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) != -12i64
    && *(_BYTE *)((this->FileName.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12)
    && *(_BYTE *)((this->FileName.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 13) == 58 )
  {
    v4 = 1;
    v5 = SetErrorMode(1u);
  }
  else
  {
    v4 = 0;
    v5 = v13;
  }
  putf8Buffer = (char *)((this->FileName.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12);
  for ( i = 0i64; (unsigned int)Scaleform::UTF8Util::DecodeNextChar_Advance0(&putf8Buffer); ++i )
    ;
  v7 = i + 1;
  v8 = (wchar_t *)Scaleform::Memory::pGlobalHeap->vfptr->Alloc(Scaleform::Memory::pGlobalHeap, 2 * v7, 0i64);
  Scaleform::UTF8Util::DecodeStringSafe(
    v8,
    v7,
    (char *)((this->FileName.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12),
    -1i64);
  Scaleform::UTF8Util::DecodeStringSafe(pbuff, 0x10ui64, v3, -1i64);
  wfopen_s(&this->fs, v8, pbuff);
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v8);
  fs = this->fs;
  if ( fs )
    rewind(fs);
  v10 = this->fs != 0i64;
  this->Opened = v10;
  if ( v10 )
  {
    this->ErrorCode = 0;
  }
  else
  {
    if ( *errno() == 2 )
    {
      v11 = 4097;
    }
    else if ( *errno() == 13 || *errno() == 1 )
    {
      v11 = 4098;
    }
    else
    {
      v11 = (*errno() == 28) + 4099;
    }
    this->ErrorCode = v11;
  }
  this->LastOp = 0;
  if ( v4 )
    SetErrorMode(v5);
}

// File Line: 304
// RVA: 0x9833E0
const char *__fastcall Scaleform::FILEFile::GetFilePath(Scaleform::MemoryFile *this)
{
  return (const char *)((this->FilePath.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12);
}

// File Line: 311
// RVA: 0x9983D0
__int64 __fastcall std::numpunct<char>::do_decimal_point(std::numpunct<char> *this)
{
  return (unsigned __int8)this->_Dp;
}

// File Line: 315
// RVA: 0x998470
bool __fastcall Scaleform::FILEFile::IsWritable(Scaleform::FILEFile *this)
{
  return ((unsigned __int8 (__fastcall *)(Scaleform::FILEFile *))this->vfptr[2].__vecDelDtor)(this)
      && (this->OpenFlags & 2) != 0;
}

// File Line: 327
// RVA: 0x9B8A00
int __fastcall Scaleform::FILEFile::Tell(Scaleform::FILEFile *this)
{
  int result; // eax
  int v3; // ebx
  bool v4; // zf

  result = ftell(this->fs);
  v3 = result;
  if ( result < 0 )
  {
    if ( *errno() == 2 )
    {
      result = v3;
      this->ErrorCode = 4097;
    }
    else if ( *errno() == 13 || *errno() == 1 )
    {
      result = v3;
      this->ErrorCode = 4098;
    }
    else
    {
      v4 = *errno() == 28;
      result = v3;
      this->ErrorCode = v4 + 4099;
    }
  }
  return result;
}

// File Line: 335
// RVA: 0x998660
__int64 __fastcall Scaleform::FILEFile::LTell(Scaleform::FILEFile *this)
{
  int v2; // eax
  __int64 v3; // rbx
  __int64 result; // rax
  bool v5; // zf

  v2 = ftell(this->fs);
  v3 = v2;
  if ( v2 < 0 )
  {
    if ( *errno() == 2 )
    {
      result = v3;
      this->ErrorCode = 4097;
      return result;
    }
    if ( *errno() != 13 && *errno() != 1 )
    {
      v5 = *errno() == 28;
      result = v3;
      this->ErrorCode = v5 + 4099;
      return result;
    }
    this->ErrorCode = 4098;
  }
  return v3;
}

// File Line: 343
// RVA: 0x9882E0
__int64 __fastcall Scaleform::FILEFile::GetLength(Scaleform::FILEFile *this)
{
  int v2; // esi
  unsigned int v3; // ebx

  v2 = ((__int64 (__fastcall *)(Scaleform::FILEFile *))this->vfptr[4].__vecDelDtor)(this);
  if ( v2 < 0 )
    return 0xFFFFFFFFi64;
  ((void (__fastcall *)(Scaleform::FILEFile *, _QWORD, __int64))this->vfptr[14].__vecDelDtor)(this, 0i64, 2i64);
  v3 = ((__int64 (__fastcall *)(Scaleform::FILEFile *))this->vfptr[4].__vecDelDtor)(this);
  ((void (__fastcall *)(Scaleform::FILEFile *, _QWORD, _QWORD))this->vfptr[14].__vecDelDtor)(
    this,
    (unsigned int)v2,
    0i64);
  return v3;
}

// File Line: 355
// RVA: 0x9984F0
__int64 __fastcall Scaleform::GFx::ZLibFile::LGetLength(Scaleform::GFx::ZLibFile *this)
{
  return ((int (__fastcall *)(Scaleform::GFx::ZLibFile *))this->vfptr[6].__vecDelDtor)(this);
}

// File Line: 366
// RVA: 0x9C2830
unsigned __int64 __fastcall Scaleform::FILEFile::Write(Scaleform::FILEFile *this, const char *pbuffer, int numBytes)
{
  unsigned __int64 v3; // rsi
  _iobuf *fs; // r9
  unsigned __int64 result; // rax
  unsigned int v8; // edi
  int v9; // ecx

  v3 = numBytes;
  if ( (this->LastOp & 0xFFFFFFFD) != 0 )
    fflush(this->fs);
  fs = this->fs;
  this->LastOp = 2;
  result = fwrite(pbuffer, 1ui64, v3, fs);
  v8 = result;
  if ( (int)result < (int)v3 )
  {
    if ( *errno() == 2 )
    {
      v9 = 4097;
    }
    else if ( *errno() == 13 || *errno() == 1 )
    {
      v9 = 4098;
    }
    else
    {
      v9 = (*errno() == 28) + 4099;
    }
    this->ErrorCode = v9;
    return v8;
  }
  return result;
}

// File Line: 383
// RVA: 0x9A4640
unsigned __int64 __fastcall Scaleform::FILEFile::Read(Scaleform::FILEFile *this, char *pbuffer, int numBytes)
{
  unsigned __int64 v3; // rsi
  _iobuf *fs; // r9
  unsigned __int64 result; // rax
  unsigned int v8; // edi
  int v9; // ecx

  v3 = numBytes;
  if ( this->LastOp > 1u )
    fflush(this->fs);
  fs = this->fs;
  this->LastOp = 1;
  result = fread(pbuffer, 1ui64, v3, fs);
  v8 = result;
  if ( (int)result < (int)v3 )
  {
    if ( *errno() == 2 )
    {
      v9 = 4097;
    }
    else if ( *errno() == 13 || *errno() == 1 )
    {
      v9 = 4098;
    }
    else
    {
      v9 = (*errno() == 28) + 4099;
    }
    this->ErrorCode = v9;
    return v8;
  }
  return result;
}

// File Line: 412
// RVA: 0x9B6630
__int64 __fastcall Scaleform::FILEFile::SkipBytes(Scaleform::FILEFile *this, int numBytes)
{
  __int64 v2; // rbx
  __int64 v4; // rsi
  __int64 v5; // rax

  v2 = numBytes;
  v4 = ((__int64 (__fastcall *)(Scaleform::FILEFile *))this->vfptr[5].__vecDelDtor)(this);
  v5 = ((__int64 (__fastcall *)(Scaleform::FILEFile *, __int64, __int64))this->vfptr[15].__vecDelDtor)(this, v2, 1i64);
  if ( v4 == -1 || v5 == -1 )
    return 0xFFFFFFFFi64;
  else
    return v5 - v4;
}

// File Line: 428
// RVA: 0x95B830
__int64 __fastcall Scaleform::FILEFile::BytesAvailable(Scaleform::FILEFile *this)
{
  __int64 v2; // rdi
  __int64 v3; // rax
  __int64 result; // rax
  int v5; // ecx

  v2 = ((__int64 (__fastcall *)(Scaleform::FILEFile *))this->vfptr[5].__vecDelDtor)(this);
  v3 = ((__int64 (__fastcall *)(Scaleform::FILEFile *))this->vfptr[7].__vecDelDtor)(this);
  if ( v2 == -1 || v3 == -1 )
  {
    if ( *errno() == 2 )
    {
      result = 0i64;
      this->ErrorCode = 4097;
    }
    else if ( *errno() == 13 || *errno() == 1 )
    {
      result = 0i64;
      this->ErrorCode = 4098;
    }
    else
    {
      v5 = (*errno() == 28) + 4099;
      result = 0i64;
      this->ErrorCode = v5;
    }
  }
  else
  {
    result = v3 - v2;
    this->ErrorCode = 0;
  }
  return result;
}

// File Line: 446
// RVA: 0x97AC20
bool __fastcall Scaleform::FILEFile::Flush(Scaleform::FILEFile *this)
{
  return fflush(this->fs) == 0;
}

// File Line: 451
// RVA: 0x9ADE60
__int64 __fastcall Scaleform::FILEFile::Seek(Scaleform::FILEFile *this, int offset, int origin)
{
  int v3; // edi
  int v6; // r8d

  v3 = 0;
  if ( !origin )
    goto LABEL_6;
  v6 = origin - 1;
  if ( v6 )
  {
    if ( v6 == 1 )
    {
      v3 = 2;
      goto LABEL_7;
    }
LABEL_6:
    if ( offset == ((unsigned int (__fastcall *)(Scaleform::FILEFile *))this->vfptr[4].__vecDelDtor)(this) )
      return ((__int64 (__fastcall *)(Scaleform::FILEFile *))this->vfptr[4].__vecDelDtor)(this);
    goto LABEL_7;
  }
  v3 = 1;
LABEL_7:
  if ( fseek(this->fs, offset, v3) )
    return 0xFFFFFFFFi64;
  return ((__int64 (__fastcall *)(Scaleform::FILEFile *))this->vfptr[4].__vecDelDtor)(this);
}

// File Line: 491
// RVA: 0x95E2A0
bool __fastcall Scaleform::FILEFile::ChangeSize(Scaleform::FILEFile *this, int newSize)
{
  this->ErrorCode = 4099;
  return 0;
}

// File Line: 523
// RVA: 0x961280
bool __fastcall Scaleform::FILEFile::Close(Scaleform::FILEFile *this)
{
  bool result; // al
  int v3; // edx

  if ( fclose(this->fs) )
  {
    if ( *errno() == 2 )
    {
      result = 0;
      this->ErrorCode = 4097;
    }
    else if ( *errno() == 13 || *errno() == 1 )
    {
      result = 0;
      this->ErrorCode = 4098;
    }
    else
    {
      v3 = (*errno() == 28) + 4099;
      result = 0;
      this->ErrorCode = v3;
    }
  }
  else
  {
    this->Opened = 0;
    result = 1;
    this->fs = 0i64;
    this->ErrorCode = 0;
  }
  return result;
}

// File Line: 623
// RVA: 0x9833F0
char __fastcall Scaleform::SysFile::GetFileStat(Scaleform::FileStat *pfileStat, Scaleform::String *path)
{
  __int64 v4; // rbx
  unsigned __int64 v5; // rbx
  wchar_t *v6; // rdi
  _stat64 buf; // [rsp+20h] [rbp-48h] BYREF
  char *putf8Buffer; // [rsp+78h] [rbp+10h] BYREF

  v4 = 0i64;
  for ( putf8Buffer = (char *)((path->HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12);
        (unsigned int)Scaleform::UTF8Util::DecodeNextChar_Advance0(&putf8Buffer);
        ++v4 )
  {
    ;
  }
  v5 = v4 + 1;
  v6 = (wchar_t *)Scaleform::Memory::pGlobalHeap->vfptr->Alloc(Scaleform::Memory::pGlobalHeap, 2 * v5, 0i64);
  Scaleform::UTF8Util::DecodeStringSafe(v6, v5, (char *)((path->HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12), -1i64);
  LODWORD(v5) = wstat64(v6, &buf);
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v6);
  if ( (_DWORD)v5 )
    return 0;
  pfileStat->AccessTime = buf.st_atime;
  pfileStat->ModifyTime = buf.st_mtime;
  pfileStat->FileSize = buf.st_size;
  return 1;
}

