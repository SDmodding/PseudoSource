// File Line: 46
// RVA: 0x9391E0
void __fastcall Scaleform::BufferedFile::BufferedFile(Scaleform::BufferedFile *this)
{
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::File,2>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::File::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::DelegatedFile::`vftable;
  this->pFile.pObject = 0i64;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::BufferedFile::`vftable;
  this->pBuffer = (char *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64, __int64, _QWORD, __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
                            Scaleform::Memory::pGlobalHeap,
                            8184i64,
                            1i64,
                            0i64,
                            -2i64);
  *(_QWORD *)&this->BufferMode = 0i64;
  this->FilePos = 0i64;
  this->DataSize = 0;
}

// File Line: 56
// RVA: 0x939290
void __fastcall Scaleform::BufferedFile::BufferedFile(Scaleform::BufferedFile *this, Scaleform::File *pfile)
{
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::File,2>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::File::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::DelegatedFile::`vftable;
  if ( pfile )
    _InterlockedExchangeAdd(&pfile->RefCount, 1u);
  this->pFile.pObject = pfile;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::BufferedFile::`vftable;
  this->pBuffer = (char *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64, __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
                            Scaleform::Memory::pGlobalHeap,
                            8184i64,
                            1i64);
  this->BufferMode = NoBuffer;
  this->FilePos = ((__int64 (__fastcall *)(Scaleform::File *))pfile->vfptr[5].__vecDelDtor)(pfile);
  *(_QWORD *)&this->Pos = 0i64;
}

// File Line: 68
// RVA: 0x948E40
void __fastcall Scaleform::BufferedFile::~BufferedFile(Scaleform::BufferedFile *this)
{
  Scaleform::File *pObject; // rcx

  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::BufferedFile::`vftable;
  if ( this->pFile.pObject )
    Scaleform::BufferedFile::FlushBuffer(this);
  if ( this->pBuffer )
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  pObject = this->pFile.pObject;
  if ( pObject && !_InterlockedDecrement(&pObject->RefCount) )
    pObject->vfptr->__vecDelDtor(pObject, 1u);
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
}

// File Line: 97
// RVA: 0x9AE7A0
char __fastcall Scaleform::BufferedFile::SetBufferMode(
        Scaleform::BufferedFile *this,
        Scaleform::BufferedFile::BufferModeType mode)
{
  Scaleform::File *pObject; // rcx

  if ( !this->pBuffer )
    return 0;
  if ( mode != this->BufferMode )
  {
    Scaleform::BufferedFile::FlushBuffer(this);
    if ( mode == WriteBuffer )
    {
      pObject = this->pFile.pObject;
      if ( !pObject || !((unsigned __int8 (__fastcall *)(Scaleform::File *))pObject->vfptr[3].__vecDelDtor)(pObject) )
        return 0;
    }
    this->BufferMode = mode;
    *(_QWORD *)&this->Pos = 0i64;
  }
  return 1;
}

// File Line: 118
// RVA: 0x97AC80
void __fastcall Scaleform::BufferedFile::FlushBuffer(Scaleform::BufferedFile *this)
{
  __int32 v2; // ecx
  unsigned int DataSize; // r8d
  unsigned int Pos; // edx

  v2 = this->BufferMode - 1;
  if ( v2 )
  {
    if ( v2 == 1 )
    {
      this->FilePos += ((int (__fastcall *)(Scaleform::File *, char *, _QWORD))this->pFile.pObject->Scaleform::DelegatedFile::vfptr[9].__vecDelDtor)(
                         this->pFile.pObject,
                         this->pBuffer,
                         this->Pos);
      this->Pos = 0;
    }
  }
  else
  {
    DataSize = this->DataSize;
    Pos = this->Pos;
    if ( DataSize != Pos )
      this->FilePos = ((__int64 (__fastcall *)(Scaleform::File *, _QWORD, __int64))this->pFile.pObject->Scaleform::DelegatedFile::vfptr[15].__vecDelDtor)(
                        this->pFile.pObject,
                        (int)(Pos - DataSize),
                        1i64);
    *(_QWORD *)&this->Pos = 0i64;
  }
}

// File Line: 142
// RVA: 0x998A30
void __fastcall Scaleform::BufferedFile::LoadBuffer(Scaleform::BufferedFile *this)
{
  __int64 v2; // rax

  if ( this->BufferMode == ReadBuffer )
  {
    v2 = ((__int64 (__fastcall *)(Scaleform::File *, char *, __int64))this->pFile.pObject->Scaleform::DelegatedFile::vfptr[10].__vecDelDtor)(
           this->pFile.pObject,
           this->pBuffer,
           8184i64);
    this->Pos = 0;
    if ( (int)v2 < 0 )
      v2 = 0i64;
    this->FilePos += v2;
    this->DataSize = v2;
  }
}

// File Line: 164
// RVA: 0x9B89C0
__int64 __fastcall Scaleform::BufferedFile::Tell(Scaleform::BufferedFile *this)
{
  __int64 result; // rax

  if ( this->BufferMode == ReadBuffer )
    return LODWORD(this->FilePos) + this->Pos - this->DataSize;
  result = ((__int64 (__fastcall *)(Scaleform::File *))this->pFile.pObject->Scaleform::DelegatedFile::vfptr[4].__vecDelDtor)(this->pFile.pObject);
  if ( (_DWORD)result != -1 && this->BufferMode == WriteBuffer )
    return (unsigned int)(this->Pos + result);
  return result;
}

// File Line: 180
// RVA: 0x998600
unsigned __int64 __fastcall Scaleform::BufferedFile::LTell(Scaleform::BufferedFile *this)
{
  unsigned __int64 result; // rax

  if ( this->BufferMode == ReadBuffer )
    return this->FilePos + this->Pos - (unsigned __int64)this->DataSize;
  result = ((__int64 (__fastcall *)(Scaleform::File *))this->pFile.pObject->Scaleform::DelegatedFile::vfptr[5].__vecDelDtor)(this->pFile.pObject);
  if ( result != -1i64 && this->BufferMode == WriteBuffer )
    result += this->Pos;
  return result;
}

// File Line: 195
// RVA: 0x988290
__int64 __fastcall Scaleform::BufferedFile::GetLength(Scaleform::BufferedFile *this)
{
  __int64 result; // rax
  unsigned int v3; // ebx
  unsigned int v4; // eax

  result = ((__int64 (__fastcall *)(Scaleform::File *))this->pFile.pObject->Scaleform::DelegatedFile::vfptr[6].__vecDelDtor)(this->pFile.pObject);
  v3 = result;
  if ( (_DWORD)result != -1 && this->BufferMode == WriteBuffer )
  {
    v4 = this->Pos
       + ((__int64 (__fastcall *)(Scaleform::File *))this->pFile.pObject->Scaleform::DelegatedFile::vfptr[4].__vecDelDtor)(this->pFile.pObject);
    if ( (int)v4 > (int)v3 )
      return v4;
    return v3;
  }
  return result;
}

// File Line: 207
// RVA: 0x9984A0
__int64 __fastcall Scaleform::BufferedFile::LGetLength(Scaleform::BufferedFile *this)
{
  __int64 result; // rax
  __int64 v3; // rbx
  __int64 v4; // rax

  result = ((__int64 (__fastcall *)(Scaleform::File *))this->pFile.pObject->Scaleform::DelegatedFile::vfptr[7].__vecDelDtor)(this->pFile.pObject);
  v3 = result;
  if ( result != -1 && this->BufferMode == WriteBuffer )
  {
    v4 = this->Pos
       + ((__int64 (__fastcall *)(Scaleform::File *))this->pFile.pObject->Scaleform::DelegatedFile::vfptr[5].__vecDelDtor)(this->pFile.pObject);
    if ( v4 > v3 )
      return v4;
    return v3;
  }
  return result;
}

// File Line: 242
// RVA: 0x9C2730
__int64 __fastcall Scaleform::BufferedFile::Write(
        Scaleform::BufferedFile *this,
        const char *psourceBuffer,
        int numBytes)
{
  size_t v3; // rdi
  Scaleform::File *pObject; // rcx
  unsigned int Pos; // edx
  int v8; // eax
  unsigned int DataSize; // r8d
  __int64 result; // rax

  v3 = numBytes;
  if ( this->BufferMode != WriteBuffer )
  {
    if ( !this->pBuffer )
      goto LABEL_14;
    Scaleform::BufferedFile::FlushBuffer(this);
    pObject = this->pFile.pObject;
    if ( !pObject || !((unsigned __int8 (__fastcall *)(Scaleform::File *))pObject->vfptr[3].__vecDelDtor)(pObject) )
      goto LABEL_14;
    *(_QWORD *)&this->BufferMode = 2i64;
    this->DataSize = 0;
  }
  Pos = this->Pos;
  if ( (int)(8184 - Pos) >= (int)v3 )
    goto LABEL_16;
  if ( this->BufferMode == ReadBuffer )
  {
    DataSize = this->DataSize;
    if ( DataSize != Pos )
      this->FilePos = ((__int64 (__fastcall *)(Scaleform::File *, _QWORD, __int64))this->pFile.pObject->Scaleform::DelegatedFile::vfptr[15].__vecDelDtor)(
                        this->pFile.pObject,
                        (int)(Pos - DataSize),
                        1i64);
    *(_QWORD *)&this->Pos = 0i64;
  }
  else if ( this->BufferMode == WriteBuffer )
  {
    v8 = ((__int64 (__fastcall *)(Scaleform::File *, char *, _QWORD))this->pFile.pObject->Scaleform::DelegatedFile::vfptr[9].__vecDelDtor)(
           this->pFile.pObject,
           this->pBuffer,
           Pos);
    this->Pos = 0;
    this->FilePos += v8;
  }
  if ( (int)v3 <= 4096 )
  {
LABEL_16:
    memmove(&this->pBuffer[this->Pos], psourceBuffer, v3);
    this->Pos += v3;
    return (unsigned int)v3;
  }
LABEL_14:
  result = ((__int64 (__fastcall *)(Scaleform::File *, const char *, _QWORD))this->pFile.pObject->Scaleform::DelegatedFile::vfptr[9].__vecDelDtor)(
             this->pFile.pObject,
             psourceBuffer,
             (unsigned int)v3);
  if ( (int)result > 0 )
    this->FilePos += (int)result;
  return result;
}

// File Line: 271
// RVA: 0x9A44F0
__int64 __fastcall Scaleform::BufferedFile::Read(
        Scaleform::BufferedFile *this,
        char *pdestBuffer,
        unsigned int numBytes)
{
  size_t v3; // rsi
  unsigned int Pos; // eax
  int v7; // r14d
  char *v8; // rdx
  __int64 result; // rax
  char *v10; // rbp
  int v11; // eax
  signed int v12; // eax

  v3 = (int)numBytes;
  if ( this->BufferMode != ReadBuffer )
  {
    if ( !this->pBuffer )
    {
      result = ((__int64 (__fastcall *)(Scaleform::File *, char *, _QWORD))this->pFile.pObject->Scaleform::DelegatedFile::vfptr[10].__vecDelDtor)(
                 this->pFile.pObject,
                 pdestBuffer,
                 numBytes);
      if ( (int)result > 0 )
        this->FilePos += (int)result;
      return result;
    }
    Scaleform::BufferedFile::FlushBuffer(this);
    *(_QWORD *)&this->BufferMode = 1i64;
    this->DataSize = 0;
  }
  Pos = this->Pos;
  v7 = this->DataSize - Pos;
  v8 = &this->pBuffer[Pos];
  if ( v7 >= (int)v3 )
  {
    memmove(pdestBuffer, v8, v3);
    result = (unsigned int)v3;
LABEL_21:
    this->Pos += v3;
    return result;
  }
  memmove(pdestBuffer, v8, v7);
  v10 = &pdestBuffer[v7];
  LODWORD(v3) = v3 - v7;
  this->Pos = this->DataSize;
  if ( (int)v3 <= 4096 )
  {
    if ( this->BufferMode == ReadBuffer )
    {
      v12 = ((__int64 (__fastcall *)(Scaleform::File *, char *, __int64))this->pFile.pObject->Scaleform::DelegatedFile::vfptr[10].__vecDelDtor)(
              this->pFile.pObject,
              this->pBuffer,
              8184i64);
      this->Pos = 0;
      if ( v12 < 0 )
        v12 = 0;
      this->FilePos += (unsigned int)v12;
      this->DataSize = v12;
    }
    if ( (signed int)(this->DataSize - this->Pos) < (int)v3 )
      LODWORD(v3) = this->DataSize - this->Pos;
    memmove(v10, &this->pBuffer[this->Pos], (int)v3);
    result = (unsigned int)(v7 + v3);
    goto LABEL_21;
  }
  v11 = ((__int64 (__fastcall *)(Scaleform::File *, char *, _QWORD))this->pFile.pObject->Scaleform::DelegatedFile::vfptr[10].__vecDelDtor)(
          this->pFile.pObject,
          v10,
          (unsigned int)v3);
  if ( v11 > 0 )
  {
    *(_QWORD *)&this->Pos = 0i64;
    this->FilePos += v11;
  }
  if ( v11 == -1 )
    v11 = 0;
  return (unsigned int)(v7 + v11);
}

// File Line: 373
// RVA: 0x9B65B0
__int64 __fastcall Scaleform::BufferedFile::SkipBytes(Scaleform::BufferedFile *this, int numBytes)
{
  int v2; // ebx
  unsigned int Pos; // eax
  int v5; // eax

  v2 = 0;
  if ( this->BufferMode == ReadBuffer )
  {
    Pos = this->Pos;
    v2 = this->DataSize - Pos;
    if ( v2 >= numBytes )
      v2 = numBytes;
    numBytes -= v2;
    this->Pos = v2 + Pos;
  }
  if ( numBytes )
  {
    v5 = ((__int64 (__fastcall *)(Scaleform::File *))this->pFile.pObject->Scaleform::DelegatedFile::vfptr[11].__vecDelDtor)(this->pFile.pObject);
    if ( v5 != -1 )
    {
      *(_QWORD *)&this->Pos = 0i64;
      this->FilePos += v5;
      return (unsigned int)(v5 + v2);
    }
    if ( v2 <= 0 )
      return (unsigned int)-1;
  }
  return (unsigned int)v2;
}

// File Line: 401
// RVA: 0x95B7D0
__int64 __fastcall Scaleform::BufferedFile::BytesAvailable(Scaleform::BufferedFile *this)
{
  int v2; // r8d
  __int64 result; // rax

  v2 = ((__int64 (__fastcall *)(Scaleform::File *))this->pFile.pObject->Scaleform::DelegatedFile::vfptr[12].__vecDelDtor)(this->pFile.pObject);
  if ( this->BufferMode == ReadBuffer )
    return v2 + this->DataSize - this->Pos;
  result = (unsigned int)(this->BufferMode - 2);
  if ( this->BufferMode != WriteBuffer )
    return (unsigned int)v2;
  v2 -= this->Pos;
  if ( v2 >= 0 )
    return (unsigned int)v2;
  return result;
}

// File Line: 421
// RVA: 0x97AC00
__int64 __fastcall Scaleform::BufferedFile::Flush(Scaleform::BufferedFile *this)
{
  Scaleform::BufferedFile::FlushBuffer(this);
  return ((__int64 (__fastcall *)(Scaleform::File *))this->pFile.pObject->Scaleform::DelegatedFile::vfptr[13].__vecDelDtor)(this->pFile.pObject);
}

// File Line: 428
// RVA: 0x9ADD90
__int64 __fastcall Scaleform::BufferedFile::Seek(
        Scaleform::BufferedFile *this,
        unsigned int offset,
        unsigned int origin)
{
  unsigned int v3; // esi
  __int64 v4; // rdi
  unsigned int Pos; // r8d
  __int64 DataSize; // rdx
  __int64 v8; // rcx
  unsigned __int64 FilePos; // rax
  __int64 result; // rax
  int v11; // eax
  unsigned __int64 v12; // rdx

  v3 = origin;
  v4 = offset;
  if ( this->BufferMode != ReadBuffer )
    goto LABEL_10;
  if ( origin == 1 )
  {
    Pos = this->Pos;
    DataSize = this->DataSize;
    v8 = Pos + (unsigned int)v4;
    if ( (unsigned int)v8 <= (unsigned int)DataSize )
    {
      FilePos = this->FilePos;
      this->Pos = v8;
      return v8 + FilePos - DataSize;
    }
    v11 = LODWORD(this->FilePos) - DataSize;
    v3 = 0;
    *(_QWORD *)&this->Pos = 0i64;
    LODWORD(v4) = Pos + v11 + v4;
    goto LABEL_11;
  }
  if ( origin )
  {
LABEL_10:
    Scaleform::BufferedFile::FlushBuffer(this);
  }
  else
  {
    v12 = this->DataSize;
    if ( v12 + v4 - this->FilePos <= v12 )
    {
      result = (unsigned int)v4;
      this->Pos = v4 + v12 - LODWORD(this->FilePos);
      return result;
    }
    *(_QWORD *)&this->Pos = 0i64;
  }
LABEL_11:
  LODWORD(result) = ((__int64 (__fastcall *)(Scaleform::File *, _QWORD, _QWORD))this->pFile.pObject->Scaleform::DelegatedFile::vfptr[14].__vecDelDtor)(
                      this->pFile.pObject,
                      (unsigned int)v4,
                      v3);
  this->FilePos = (int)result;
  return (unsigned int)result;
}

// File Line: 493
// RVA: 0x998510
unsigned __int64 __fastcall Scaleform::BufferedFile::LSeek(
        Scaleform::BufferedFile *this,
        unsigned __int64 offset,
        unsigned int origin)
{
  unsigned int v3; // esi
  unsigned __int64 v4; // rdi
  __int64 Pos; // r8
  __int64 DataSize; // rax
  unsigned int v8; // edx
  unsigned __int64 result; // rax
  __int64 v10; // rcx
  unsigned __int64 v11; // rcx

  v3 = origin;
  v4 = offset;
  if ( this->BufferMode != ReadBuffer )
    goto LABEL_10;
  if ( origin == 1 )
  {
    Pos = this->Pos;
    DataSize = this->DataSize;
    v8 = Pos + offset;
    if ( v8 <= (unsigned int)DataSize )
    {
      this->Pos = v8;
      return v8 + this->FilePos - (unsigned int)DataSize;
    }
    v10 = this->FilePos - DataSize;
    v3 = 0;
    *(_QWORD *)&this->Pos = 0i64;
    v4 += v10 + Pos;
    goto LABEL_11;
  }
  if ( origin )
  {
LABEL_10:
    Scaleform::BufferedFile::FlushBuffer(this);
  }
  else
  {
    v11 = this->DataSize;
    if ( offset + (unsigned int)v11 - this->FilePos <= v11 )
    {
      result = offset;
      this->Pos = offset + v11 - LODWORD(this->FilePos);
      return result;
    }
    *(_QWORD *)&this->Pos = 0i64;
  }
LABEL_11:
  result = ((__int64 (__fastcall *)(Scaleform::File *, unsigned __int64, _QWORD))this->pFile.pObject->Scaleform::DelegatedFile::vfptr[15].__vecDelDtor)(
             this->pFile.pObject,
             v4,
             v3);
  this->FilePos = result;
  return result;
}

// File Line: 553
// RVA: 0x95E270
void *__fastcall Scaleform::BufferedFile::ChangeSize(Scaleform::BufferedFile *this, unsigned int newSize)
{
  Scaleform::BufferedFile::FlushBuffer(this);
  return this->pFile.pObject->Scaleform::DelegatedFile::vfptr[17].__vecDelDtor(this->pFile.pObject, newSize);
}

// File Line: 559
// RVA: 0x964900
__int64 __fastcall Scaleform::FILEFile::CopyFromStream(
        Scaleform::FILEFile *this,
        Scaleform::File *pstream,
        int byteSize)
{
  unsigned int v3; // edi
  int v4; // ebx
  int v7; // esi
  int v8; // r8d
  int v9; // eax
  char v11[16408]; // [rsp+20h] [rbp-4018h] BYREF

  v3 = 0;
  v4 = byteSize;
  if ( !byteSize )
    return 0i64;
  do
  {
    v7 = v4;
    if ( v4 > 0x4000 )
      v7 = 0x4000;
    v8 = ((__int64 (__fastcall *)(Scaleform::File *, char *, _QWORD))pstream->vfptr[10].__vecDelDtor)(
           pstream,
           v11,
           (unsigned int)v7);
    v9 = 0;
    if ( v8 > 0 )
      v9 = (int)this->vfptr[9].__vecDelDtor(this, v11);
    v3 += v9;
    v4 -= v9;
  }
  while ( v9 >= v7 && v4 );
  return v3;
}

// File Line: 586
// RVA: 0x961190
__int64 __fastcall Scaleform::BufferedFile::Close(Scaleform::BufferedFile *this)
{
  __int32 v2; // ecx

  v2 = this->BufferMode - 1;
  if ( v2 )
  {
    if ( v2 == 1 )
    {
      Scaleform::BufferedFile::FlushBuffer(this);
      return ((__int64 (__fastcall *)(Scaleform::File *))this->pFile.pObject->Scaleform::DelegatedFile::vfptr[19].__vecDelDtor)(this->pFile.pObject);
    }
  }
  else
  {
    this->BufferMode = NoBuffer;
  }
  return ((__int64 (__fastcall *)(Scaleform::File *))this->pFile.pObject->Scaleform::DelegatedFile::vfptr[19].__vecDelDtor)(this->pFile.pObject);
}

// File Line: 616
// RVA: 0x98B620
const char *__fastcall Scaleform::GetShortFilename(const char *purl)
{
  __int64 v2; // rax
  char v3; // cl

  v2 = -1i64;
  do
    ++v2;
  while ( purl[v2] );
  if ( !v2 )
    return purl;
  while ( 1 )
  {
    v3 = purl[v2];
    if ( v3 == 92 || v3 == 47 )
      break;
    if ( !--v2 )
      return purl;
  }
  return &purl[v2 + 1];
}

