// File Line: 82
// RVA: 0x94D000
void __fastcall Scaleform::SysErrorModeDisabler::~SysErrorModeDisabler(Scaleform::SysErrorModeDisabler *this)
{
  if ( this->Disabled )
    SetErrorMode(this->OldMode);
}

// File Line: 193
// RVA: 0x93BA30
void __fastcall Scaleform::FILEFile::FILEFile(Scaleform::FILEFile *this, Scaleform::String *fileName, int flags, int mode)
{
  int v4; // ebx
  Scaleform::FILEFile *v5; // rdi

  v4 = flags;
  v5 = this;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::File,2>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::File::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::FILEFile::`vftable;
  Scaleform::String::String(&this->FileName, fileName);
  v5->OpenFlags = v4;
  Scaleform::FILEFile::init(v5);
}

// File Line: 219
// RVA: 0x9E80F0
void __fastcall Scaleform::FILEFile::init(Scaleform::FILEFile *this)
{
  Scaleform::FILEFile *v1; // rbp
  int v2; // eax
  const char *v3; // rsi
  signed int v4; // er14
  UINT v5; // er15
  __int64 i; // rbx
  unsigned __int64 v7; // rbx
  wchar_t *v8; // rdi
  _iobuf *v9; // rcx
  bool v10; // al
  int v11; // ecx
  wchar_t pbuff; // [rsp+28h] [rbp-50h]
  UINT v13; // [rsp+84h] [rbp+Ch]
  char *putf8Buffer; // [rsp+88h] [rbp+10h]

  v1 = this;
  v2 = this->OpenFlags;
  if ( v2 & 4 )
  {
    v3 = "w+b";
    if ( !(v2 & 1) )
      v3 = "wb";
  }
  else if ( v2 & 8 )
  {
    v3 = "a+b";
    if ( !(v2 & 1) )
      v3 = "ab";
  }
  else
  {
    v3 = "r+b";
    if ( !(v2 & 2) )
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
  putf8Buffer = (char *)((v1->FileName.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12);
  for ( i = 0i64; (unsigned int)Scaleform::UTF8Util::DecodeNextChar_Advance0((const char **)&putf8Buffer); ++i )
    ;
  v7 = i + 1;
  v8 = (wchar_t *)Scaleform::Memory::pGlobalHeap->vfptr->Alloc(Scaleform::Memory::pGlobalHeap, 2 * v7, 0i64);
  Scaleform::UTF8Util::DecodeStringSafe(
    v8,
    v7,
    (const char *)((v1->FileName.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12),
    -1i64);
  Scaleform::UTF8Util::DecodeStringSafe(&pbuff, 0x10ui64, v3, -1i64);
  wfopen_s(&v1->fs, v8, &pbuff);
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v8);
  v9 = v1->fs;
  if ( v9 )
    rewind(v9);
  v10 = v1->fs != 0i64;
  v1->Opened = v10;
  if ( v10 )
  {
    v1->ErrorCode = 0;
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
    v1->ErrorCode = v11;
  }
  v1->LastOp = 0;
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
  Scaleform::FILEFile *v1; // rbx

  v1 = this;
  return ((unsigned __int8 (*)(void))this->vfptr[2].__vecDelDtor)() && v1->OpenFlags & 2;
}

// File Line: 327
// RVA: 0x9B8A00
int __fastcall Scaleform::FILEFile::Tell(Scaleform::FILEFile *this)
{
  Scaleform::FILEFile *v1; // rdi
  int result; // eax
  int v3; // ebx
  bool v4; // zf

  v1 = this;
  result = ftell(this->fs);
  v3 = result;
  if ( result < 0 )
  {
    if ( *errno() == 2 )
    {
      result = v3;
      v1->ErrorCode = 4097;
    }
    else if ( *errno() == 13 || *errno() == 1 )
    {
      result = v3;
      v1->ErrorCode = 4098;
    }
    else
    {
      v4 = *errno() == 28;
      result = v3;
      v1->ErrorCode = v4 + 4099;
    }
  }
  return result;
}

// File Line: 335
// RVA: 0x998660
__int64 __fastcall Scaleform::FILEFile::LTell(Scaleform::FILEFile *this)
{
  Scaleform::FILEFile *v1; // rdi
  int v2; // eax
  __int64 v3; // rbx
  __int64 result; // rax
  bool v5; // zf

  v1 = this;
  v2 = ftell(this->fs);
  v3 = v2;
  if ( v2 < 0 )
  {
    if ( *errno() == 2 )
    {
      result = v3;
      v1->ErrorCode = 4097;
      return result;
    }
    if ( *errno() != 13 && *errno() != 1 )
    {
      v5 = *errno() == 28;
      result = v3;
      v1->ErrorCode = v5 + 4099;
      return result;
    }
    v1->ErrorCode = 4098;
  }
  return v3;
}

// File Line: 343
// RVA: 0x9882E0
signed __int64 __fastcall Scaleform::FILEFile::GetLength(Scaleform::FILEFile *this)
{
  Scaleform::FILEFile *v1; // rdi
  unsigned int v2; // esi
  unsigned int v3; // ebx

  v1 = this;
  v2 = ((__int64 (*)(void))this->vfptr[4].__vecDelDtor)();
  if ( (v2 & 0x80000000) != 0 )
    return 0xFFFFFFFFi64;
  ((void (__fastcall *)(Scaleform::FILEFile *, _QWORD, signed __int64))v1->vfptr[14].__vecDelDtor)(v1, 0i64, 2i64);
  v3 = ((__int64 (__fastcall *)(Scaleform::FILEFile *))v1->vfptr[4].__vecDelDtor)(v1);
  ((void (__fastcall *)(Scaleform::FILEFile *, _QWORD, _QWORD))v1->vfptr[14].__vecDelDtor)(v1, v2, 0i64);
  return v3;
}

// File Line: 355
// RVA: 0x9984F0
__int64 __fastcall Scaleform::GFx::ZLibFile::LGetLength(Scaleform::GFx::ZLibFile *this)
{
  return ((signed int (*)(void))this->vfptr[6].__vecDelDtor)();
}

// File Line: 366
// RVA: 0x9C2830
unsigned __int64 __fastcall Scaleform::FILEFile::Write(Scaleform::FILEFile *this, const char *pbuffer, int numBytes)
{
  unsigned __int64 v3; // rsi
  const char *v4; // rdi
  Scaleform::FILEFile *v5; // rbx
  _iobuf *v6; // r9
  unsigned __int64 result; // rax
  unsigned int v8; // edi
  int v9; // ecx

  v3 = numBytes;
  v4 = pbuffer;
  v5 = this;
  if ( this->LastOp & 0xFFFFFFFD )
    fflush(this->fs);
  v6 = v5->fs;
  v5->LastOp = 2;
  result = fwrite(v4, 1ui64, v3, v6);
  v8 = result;
  if ( (signed int)result < (signed int)v3 )
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
    v5->ErrorCode = v9;
    result = v8;
  }
  return result;
}

// File Line: 383
// RVA: 0x9A4640
unsigned __int64 __fastcall Scaleform::FILEFile::Read(Scaleform::FILEFile *this, char *pbuffer, int numBytes)
{
  unsigned __int64 v3; // rsi
  char *v4; // rdi
  Scaleform::FILEFile *v5; // rbx
  _iobuf *v6; // r9
  unsigned __int64 result; // rax
  unsigned int v8; // edi
  int v9; // ecx

  v3 = numBytes;
  v4 = pbuffer;
  v5 = this;
  if ( this->LastOp > 1u )
    fflush(this->fs);
  v6 = v5->fs;
  v5->LastOp = 1;
  result = fread(v4, 1ui64, v3, v6);
  v8 = result;
  if ( (signed int)result < (signed int)v3 )
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
    v5->ErrorCode = v9;
    result = v8;
  }
  return result;
}

// File Line: 412
// RVA: 0x9B6630
signed __int64 __fastcall Scaleform::FILEFile::SkipBytes(Scaleform::FILEFile *this, int numBytes)
{
  __int64 v2; // rbx
  Scaleform::FILEFile *v3; // rdi
  __int64 v4; // rsi
  __int64 v5; // rax
  signed __int64 result; // rax

  v2 = numBytes;
  v3 = this;
  v4 = ((__int64 (*)(void))this->vfptr[5].__vecDelDtor)();
  v5 = ((__int64 (__fastcall *)(Scaleform::FILEFile *, __int64, signed __int64))v3->vfptr[15].__vecDelDtor)(
         v3,
         v2,
         1i64);
  if ( v4 == -1 || v5 == -1 )
    result = 0xFFFFFFFFi64;
  else
    result = v5 - v4;
  return result;
}

// File Line: 428
// RVA: 0x95B830
__int64 __fastcall Scaleform::FILEFile::BytesAvailable(Scaleform::FILEFile *this)
{
  Scaleform::FILEFile *v1; // rbx
  __int64 v2; // rdi
  __int64 v3; // rax
  __int64 result; // rax
  int v5; // ecx

  v1 = this;
  v2 = ((__int64 (*)(void))this->vfptr[5].__vecDelDtor)();
  v3 = ((__int64 (__fastcall *)(Scaleform::FILEFile *))v1->vfptr[7].__vecDelDtor)(v1);
  if ( v2 == -1 || v3 == -1 )
  {
    if ( *errno() == 2 )
    {
      result = 0i64;
      v1->ErrorCode = 4097;
    }
    else if ( *errno() == 13 || *errno() == 1 )
    {
      result = 0i64;
      v1->ErrorCode = 4098;
    }
    else
    {
      v5 = (*errno() == 28) + 4099;
      result = 0i64;
      v1->ErrorCode = v5;
    }
  }
  else
  {
    result = v3 - v2;
    v1->ErrorCode = 0;
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
signed __int64 __fastcall Scaleform::FILEFile::Seek(Scaleform::FILEFile *this, int offset, int origin)
{
  int v3; // edi
  int v4; // esi
  Scaleform::FILEFile *v5; // rbx
  int v6; // er8

  v3 = 0;
  v4 = offset;
  v5 = this;
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
    if ( offset == ((unsigned int (*)(void))this->vfptr[4].__vecDelDtor)() )
      return ((__int64 (__fastcall *)(Scaleform::FILEFile *))v5->vfptr[4].__vecDelDtor)(v5);
    goto LABEL_7;
  }
  v3 = 1;
LABEL_7:
  if ( fseek(v5->fs, v4, v3) )
    return 0xFFFFFFFFi64;
  return ((__int64 (__fastcall *)(Scaleform::FILEFile *))v5->vfptr[4].__vecDelDtor)(v5);
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
char __fastcall Scaleform::FILEFile::Close(Scaleform::FILEFile *this)
{
  Scaleform::FILEFile *v1; // rbx
  char result; // al
  int v3; // edx

  v1 = this;
  if ( fclose(this->fs) )
  {
    if ( *errno() == 2 )
    {
      result = 0;
      v1->ErrorCode = 4097;
    }
    else if ( *errno() == 13 || *errno() == 1 )
    {
      result = 0;
      v1->ErrorCode = 4098;
    }
    else
    {
      v3 = (*errno() == 28) + 4099;
      result = 0;
      v1->ErrorCode = v3;
    }
  }
  else
  {
    v1->Opened = 0;
    result = 1;
    v1->fs = 0i64;
    v1->ErrorCode = 0;
  }
  return result;
}

// File Line: 623
// RVA: 0x9833F0
char __fastcall Scaleform::SysFile::GetFileStat(Scaleform::FileStat *pfileStat, Scaleform::String *path)
{
  Scaleform::FileStat *v2; // rsi
  Scaleform::String *v3; // r14
  __int64 v4; // rbx
  unsigned __int64 v5; // rbx
  wchar_t *v6; // rdi
  _stat64 buf; // [rsp+20h] [rbp-48h]
  char *putf8Buffer; // [rsp+78h] [rbp+10h]

  v2 = pfileStat;
  v3 = path;
  v4 = 0i64;
  for ( putf8Buffer = (char *)((path->HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12);
        (unsigned int)Scaleform::UTF8Util::DecodeNextChar_Advance0((const char **)&putf8Buffer);
        ++v4 )
  {
    ;
  }
  v5 = v4 + 1;
  v6 = (wchar_t *)Scaleform::Memory::pGlobalHeap->vfptr->Alloc(Scaleform::Memory::pGlobalHeap, 2 * v5, 0i64);
  Scaleform::UTF8Util::DecodeStringSafe(v6, v5, (const char *)((v3->HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12), -1i64);
  LODWORD(v5) = wstat64(v6, &buf);
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v6);
  if ( (_DWORD)v5 )
    return 0;
  v2->AccessTime = buf.st_atime;
  v2->ModifyTime = buf.st_mtime;
  v2->FileSize = buf.st_size;
  return 1;
}

