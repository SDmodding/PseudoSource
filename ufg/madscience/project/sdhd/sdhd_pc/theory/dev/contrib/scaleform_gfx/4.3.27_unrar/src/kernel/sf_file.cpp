// File Line: 46
// RVA: 0x9391E0
void __fastcall Scaleform::BufferedFile::BufferedFile(Scaleform::BufferedFile *this)
{
  Scaleform::BufferedFile *v1; // rbx

  v1 = this;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::File,2>::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::File::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::DelegatedFile::`vftable';
  this->pFile.pObject = 0i64;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::BufferedFile::`vftable';
  this->pBuffer = (char *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64, signed __int64, _QWORD, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
                            Scaleform::Memory::pGlobalHeap,
                            8184i64,
                            1i64,
                            0i64,
                            -2i64);
  *(_QWORD *)&v1->BufferMode = 0i64;
  v1->FilePos = 0i64;
  v1->DataSize = 0;
}

// File Line: 56
// RVA: 0x939290
void __fastcall Scaleform::BufferedFile::BufferedFile(Scaleform::BufferedFile *this, Scaleform::File *pfile)
{
  Scaleform::File *v2; // rdi
  Scaleform::BufferedFile *v3; // rbx

  v2 = pfile;
  v3 = this;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::File,2>::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::File::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::DelegatedFile::`vftable';
  if ( pfile )
    _InterlockedExchangeAdd(&pfile->RefCount, 1u);
  this->pFile.pObject = pfile;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::BufferedFile::`vftable';
  this->pBuffer = (char *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
                            Scaleform::Memory::pGlobalHeap,
                            8184i64,
                            1i64);
  v3->BufferMode = 0;
  v3->FilePos = ((__int64 (__fastcall *)(Scaleform::File *))v2->vfptr[5].__vecDelDtor)(v2);
  *(_QWORD *)&v3->Pos = 0i64;
}

// File Line: 68
// RVA: 0x948E40
void __fastcall Scaleform::BufferedFile::~BufferedFile(Scaleform::BufferedFile *this)
{
  Scaleform::BufferedFile *v1; // rbx
  Scaleform::File *v2; // rcx

  v1 = this;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::BufferedFile::`vftable';
  if ( this->pFile.pObject )
    Scaleform::BufferedFile::FlushBuffer(this);
  if ( v1->pBuffer )
    ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  v2 = v1->pFile.pObject;
  if ( v2 && !_InterlockedDecrement(&v2->RefCount) && v2 )
    v2->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)&v2->vfptr, 1u);
  v1->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable';
}

// File Line: 97
// RVA: 0x9AE7A0
char __fastcall Scaleform::BufferedFile::SetBufferMode(Scaleform::BufferedFile *this, Scaleform::BufferedFile::BufferModeType mode)
{
  Scaleform::BufferedFile::BufferModeType v2; // edi
  Scaleform::BufferedFile *v3; // rbx
  Scaleform::File *v5; // rcx

  v2 = mode;
  v3 = this;
  if ( !this->pBuffer )
    return 0;
  if ( mode != this->BufferMode )
  {
    Scaleform::BufferedFile::FlushBuffer(this);
    if ( v2 == 2 )
    {
      v5 = v3->pFile.pObject;
      if ( !v5 || !((unsigned __int8 (*)(void))v5->vfptr[3].__vecDelDtor)() )
        return 0;
    }
    v3->BufferMode = v2;
    *(_QWORD *)&v3->Pos = 0i64;
  }
  return 1;
}

// File Line: 118
// RVA: 0x97AC80
void __fastcall Scaleform::BufferedFile::FlushBuffer(Scaleform::BufferedFile *this)
{
  Scaleform::BufferedFile *v1; // rbx
  __int32 v2; // ecx
  unsigned int v3; // er8
  unsigned int v4; // edx

  v1 = this;
  v2 = this->BufferMode - 1;
  if ( v2 )
  {
    if ( v2 == 1 )
    {
      v1->FilePos += ((signed int (__fastcall *)(Scaleform::File *, char *, _QWORD))v1->pFile.pObject->vfptr[9].__vecDelDtor)(
                       v1->pFile.pObject,
                       v1->pBuffer,
                       v1->Pos);
      v1->Pos = 0;
    }
  }
  else
  {
    v3 = v1->DataSize;
    v4 = v1->Pos;
    if ( v3 != v4 )
      v1->FilePos = ((__int64 (__fastcall *)(Scaleform::File *, _QWORD, signed __int64))v1->pFile.pObject->vfptr[15].__vecDelDtor)(
                      v1->pFile.pObject,
                      (signed int)(v4 - v3),
                      1i64);
    *(_QWORD *)&v1->Pos = 0i64;
  }
}

// File Line: 142
// RVA: 0x998A30
void __fastcall Scaleform::BufferedFile::LoadBuffer(Scaleform::BufferedFile *this)
{
  Scaleform::BufferedFile *v1; // rbx
  __int64 v2; // rax

  v1 = this;
  if ( this->BufferMode == 1 )
  {
    v2 = ((__int64 (__fastcall *)(Scaleform::File *, char *, signed __int64))this->pFile.pObject->vfptr[10].__vecDelDtor)(
           this->pFile.pObject,
           this->pBuffer,
           8184i64);
    v1->Pos = 0;
    if ( (signed int)v2 < 0 )
      v2 = 0i64;
    v1->FilePos += v2;
    v1->DataSize = v2;
  }
}

// File Line: 164
// RVA: 0x9B89C0
__int64 __fastcall Scaleform::BufferedFile::Tell(Scaleform::BufferedFile *this)
{
  Scaleform::BufferedFile *v1; // rbx
  __int64 result; // rax

  v1 = this;
  if ( this->BufferMode == 1 )
    return LODWORD(this->FilePos) + this->Pos - this->DataSize;
  result = ((__int64 (*)(void))this->pFile.pObject->vfptr[4].__vecDelDtor)();
  if ( (_DWORD)result != -1 && v1->BufferMode == 2 )
    result = (unsigned int)(v1->Pos + result);
  return result;
}

// File Line: 180
// RVA: 0x998600
unsigned __int64 __fastcall Scaleform::BufferedFile::LTell(Scaleform::BufferedFile *this)
{
  Scaleform::BufferedFile *v1; // rbx
  unsigned __int64 result; // rax

  v1 = this;
  if ( this->BufferMode == 1 )
    return this->FilePos + this->Pos - (unsigned __int64)this->DataSize;
  result = ((__int64 (*)(void))this->pFile.pObject->vfptr[5].__vecDelDtor)();
  if ( result != -1i64 && v1->BufferMode == 2 )
    result += v1->Pos;
  return result;
}

// File Line: 195
// RVA: 0x988290
__int64 __fastcall Scaleform::BufferedFile::GetLength(Scaleform::BufferedFile *this)
{
  Scaleform::BufferedFile *v1; // rdi
  __int64 result; // rax
  unsigned int v3; // ebx
  int v4; // eax

  v1 = this;
  result = ((__int64 (*)(void))this->pFile.pObject->vfptr[6].__vecDelDtor)();
  v3 = result;
  if ( (_DWORD)result != -1 && v1->BufferMode == 2 )
  {
    v4 = v1->Pos + (unsigned __int64)((__int64 (*)(void))v1->pFile.pObject->vfptr[4].__vecDelDtor)();
    if ( v4 > (signed int)v3 )
      v3 = v4;
    result = v3;
  }
  return result;
}

// File Line: 207
// RVA: 0x9984A0
__int64 __fastcall Scaleform::BufferedFile::LGetLength(Scaleform::BufferedFile *this)
{
  Scaleform::BufferedFile *v1; // rdi
  __int64 result; // rax
  __int64 v3; // rbx
  __int64 v4; // rax

  v1 = this;
  result = ((__int64 (*)(void))this->pFile.pObject->vfptr[7].__vecDelDtor)();
  v3 = result;
  if ( result != -1 && v1->BufferMode == 2 )
  {
    v4 = v1->Pos + ((__int64 (*)(void))v1->pFile.pObject->vfptr[5].__vecDelDtor)();
    if ( v4 > v3 )
      v3 = v4;
    result = v3;
  }
  return result;
}

// File Line: 242
// RVA: 0x9C2730
__int64 __fastcall Scaleform::BufferedFile::Write(Scaleform::BufferedFile *this, const char *psourceBuffer, int numBytes)
{
  size_t v3; // rdi
  const char *v4; // rsi
  Scaleform::BufferedFile *v5; // rbx
  Scaleform::File *v6; // rcx
  unsigned int v7; // edx
  int v8; // eax
  unsigned int v9; // er8
  __int64 result; // rax

  v3 = numBytes;
  v4 = psourceBuffer;
  v5 = this;
  if ( this->BufferMode != 2 )
  {
    if ( !this->pBuffer )
      goto LABEL_14;
    Scaleform::BufferedFile::FlushBuffer(this);
    v6 = v5->pFile.pObject;
    if ( !v6 || !((unsigned __int8 (*)(void))v6->vfptr[3].__vecDelDtor)() )
      goto LABEL_14;
    *(_QWORD *)&v5->BufferMode = 2i64;
    v5->DataSize = 0;
  }
  v7 = v5->Pos;
  if ( (signed int)(8184 - v7) >= (signed int)v3 )
    goto LABEL_19;
  if ( v5->BufferMode == 1 )
  {
    v9 = v5->DataSize;
    if ( v9 != v7 )
      v5->FilePos = ((__int64 (__fastcall *)(Scaleform::File *, _QWORD, signed __int64))v5->pFile.pObject->vfptr[15].__vecDelDtor)(
                      v5->pFile.pObject,
                      (signed int)(v7 - v9),
                      1i64);
    *(_QWORD *)&v5->Pos = 0i64;
  }
  else if ( v5->BufferMode == 2 )
  {
    v8 = ((__int64 (__fastcall *)(Scaleform::File *, char *, _QWORD))v5->pFile.pObject->vfptr[9].__vecDelDtor)(
           v5->pFile.pObject,
           v5->pBuffer,
           v7);
    v5->Pos = 0;
    v5->FilePos += v8;
  }
  if ( (signed int)v3 <= 4096 )
  {
LABEL_19:
    memmove(&v5->pBuffer[v5->Pos], v4, v3);
    v5->Pos += v3;
    return (unsigned int)v3;
  }
LABEL_14:
  result = ((__int64 (__fastcall *)(Scaleform::File *, const char *, _QWORD))v5->pFile.pObject->vfptr[9].__vecDelDtor)(
             v5->pFile.pObject,
             v4,
             (unsigned int)v3);
  if ( (signed int)result > 0 )
    v5->FilePos += (signed int)result;
  return result;
}

// File Line: 271
// RVA: 0x9A44F0
__int64 __fastcall Scaleform::BufferedFile::Read(Scaleform::BufferedFile *this, char *pdestBuffer, int numBytes)
{
  size_t v3; // rsi
  char *v4; // rbp
  Scaleform::BufferedFile *v5; // rdi
  unsigned int v6; // eax
  int v7; // er14
  char *v8; // rdx
  __int64 result; // rax
  char *v10; // rbp
  int v11; // eax
  unsigned int v12; // eax

  v3 = numBytes;
  v4 = pdestBuffer;
  v5 = this;
  if ( this->BufferMode != 1 )
  {
    if ( !this->pBuffer )
    {
      result = ((__int64 (__fastcall *)(Scaleform::File *, char *, _QWORD))this->pFile.pObject->vfptr[10].__vecDelDtor)(
                 this->pFile.pObject,
                 pdestBuffer,
                 (unsigned int)numBytes);
      if ( (signed int)result > 0 )
        v5->FilePos += (signed int)result;
      return result;
    }
    Scaleform::BufferedFile::FlushBuffer(this);
    *(_QWORD *)&v5->BufferMode = 1i64;
    v5->DataSize = 0;
  }
  v6 = v5->Pos;
  v7 = v5->DataSize - v6;
  v8 = &v5->pBuffer[v6];
  if ( v7 >= (signed int)v3 )
  {
    memmove(v4, v8, v3);
    result = (unsigned int)v3;
LABEL_21:
    v5->Pos += v3;
    return result;
  }
  memmove(v4, v8, v7);
  v10 = &v4[v7];
  LODWORD(v3) = v3 - v7;
  v5->Pos = v5->DataSize;
  if ( (signed int)v3 <= 4096 )
  {
    if ( v5->BufferMode == 1 )
    {
      v12 = ((__int64 (__fastcall *)(Scaleform::File *, char *, signed __int64))v5->pFile.pObject->vfptr[10].__vecDelDtor)(
              v5->pFile.pObject,
              v5->pBuffer,
              8184i64);
      v5->Pos = 0;
      if ( (v12 & 0x80000000) != 0 )
        v12 = 0;
      v5->FilePos += v12;
      v5->DataSize = v12;
    }
    if ( (signed int)(v5->DataSize - v5->Pos) < (signed int)v3 )
      LODWORD(v3) = v5->DataSize - v5->Pos;
    memmove(v10, &v5->pBuffer[v5->Pos], (signed int)v3);
    result = (unsigned int)(v7 + v3);
    goto LABEL_21;
  }
  v11 = ((__int64 (__fastcall *)(Scaleform::File *, char *, _QWORD))v5->pFile.pObject->vfptr[10].__vecDelDtor)(
          v5->pFile.pObject,
          v10,
          (unsigned int)v3);
  if ( v11 > 0 )
  {
    *(_QWORD *)&v5->Pos = 0i64;
    v5->FilePos += v11;
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
  Scaleform::BufferedFile *v3; // rdi
  unsigned int v4; // eax
  int v5; // eax

  v2 = 0;
  v3 = this;
  if ( this->BufferMode == 1 )
  {
    v4 = this->Pos;
    v2 = this->DataSize - v4;
    if ( v2 >= numBytes )
      v2 = numBytes;
    numBytes -= v2;
    this->Pos = v2 + v4;
  }
  if ( numBytes )
  {
    v5 = ((__int64 (*)(void))this->pFile.pObject->vfptr[11].__vecDelDtor)();
    if ( v5 != -1 )
    {
      *(_QWORD *)&v3->Pos = 0i64;
      v3->FilePos += v5;
      return (unsigned int)(v5 + v2);
    }
    if ( v2 <= 0 )
      v2 = -1;
  }
  return (unsigned int)v2;
}

// File Line: 401
// RVA: 0x95B7D0
__int64 __fastcall Scaleform::BufferedFile::BytesAvailable(Scaleform::BufferedFile *this)
{
  Scaleform::BufferedFile *v1; // rbx
  unsigned int v2; // er8
  __int64 result; // rax

  v1 = this;
  v2 = ((__int64 (*)(void))this->pFile.pObject->vfptr[12].__vecDelDtor)();
  if ( v1->BufferMode == 1 )
    return v2 + v1->DataSize - v1->Pos;
  result = (unsigned int)(v1->BufferMode - 2);
  if ( v1->BufferMode != 2 || (v2 -= v1->Pos, (v2 & 0x80000000) == 0) )
    result = v2;
  return result;
}

// File Line: 421
// RVA: 0x97AC00
__int64 __fastcall Scaleform::BufferedFile::Flush(Scaleform::BufferedFile *this)
{
  Scaleform::BufferedFile *v1; // rbx

  v1 = this;
  Scaleform::BufferedFile::FlushBuffer(this);
  return ((__int64 (*)(void))v1->pFile.pObject->vfptr[13].__vecDelDtor)();
}

// File Line: 428
// RVA: 0x9ADD90
unsigned __int64 __fastcall Scaleform::BufferedFile::Seek(Scaleform::BufferedFile *this, int offset, int origin)
{
  unsigned int v3; // esi
  __int64 v4; // rdi
  Scaleform::BufferedFile *v5; // rbx
  unsigned int v6; // er8
  __int64 v7; // rdx
  __int64 v8; // rcx
  unsigned __int64 v9; // rax
  unsigned __int64 result; // rax
  int v11; // eax
  unsigned __int64 v12; // rdx

  v3 = origin;
  v4 = (unsigned int)offset;
  v5 = this;
  if ( this->BufferMode != 1 )
    goto LABEL_14;
  if ( origin == 1 )
  {
    v6 = this->Pos;
    v7 = this->DataSize;
    v8 = v6 + (unsigned int)v4;
    if ( (unsigned int)v8 <= (unsigned int)v7 )
    {
      v9 = v5->FilePos;
      v5->Pos = v8;
      return v8 + v9 - v7;
    }
    v11 = LODWORD(v5->FilePos) - v7;
    v3 = 0;
    *(_QWORD *)&v5->Pos = 0i64;
    LODWORD(v4) = v6 + v11 + v4;
    goto LABEL_11;
  }
  if ( origin )
  {
LABEL_14:
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
  LODWORD(result) = ((__int64 (__fastcall *)(Scaleform::File *, _QWORD, _QWORD))v5->pFile.pObject->vfptr[14].__vecDelDtor)(
                      v5->pFile.pObject,
                      (unsigned int)v4,
                      v3);
  v5->FilePos = (signed int)result;
  return (unsigned int)result;
}

// File Line: 493
// RVA: 0x998510
__int64 __fastcall Scaleform::BufferedFile::LSeek(Scaleform::BufferedFile *this, __int64 offset, int origin)
{
  unsigned int v3; // esi
  __int64 v4; // rdi
  Scaleform::BufferedFile *v5; // rbx
  __int64 v6; // r8
  __int64 v7; // rax
  unsigned int v8; // edx
  __int64 result; // rax
  unsigned __int64 v10; // rcx
  unsigned __int64 v11; // rcx

  v3 = origin;
  v4 = offset;
  v5 = this;
  if ( this->BufferMode != 1 )
    goto LABEL_14;
  if ( origin == 1 )
  {
    v6 = this->Pos;
    v7 = this->DataSize;
    v8 = v6 + offset;
    if ( v8 <= (unsigned int)v7 )
    {
      this->Pos = v8;
      return v8 + this->FilePos - (unsigned int)v7;
    }
    v10 = this->FilePos - v7;
    v3 = 0;
    *(_QWORD *)&v5->Pos = 0i64;
    v4 += v10 + v6;
    goto LABEL_11;
  }
  if ( origin )
  {
LABEL_14:
    Scaleform::BufferedFile::FlushBuffer(this);
  }
  else
  {
    v11 = this->DataSize;
    if ( offset + (unsigned int)v11 - v5->FilePos <= v11 )
    {
      result = offset;
      v5->Pos = offset + v11 - LODWORD(v5->FilePos);
      return result;
    }
    *(_QWORD *)&v5->Pos = 0i64;
  }
LABEL_11:
  result = ((__int64 (__fastcall *)(Scaleform::File *, __int64, _QWORD))v5->pFile.pObject->vfptr[15].__vecDelDtor)(
             v5->pFile.pObject,
             v4,
             v3);
  v5->FilePos = result;
  return result;
}

// File Line: 553
// RVA: 0x95E270
__int64 __fastcall Scaleform::BufferedFile::ChangeSize(Scaleform::BufferedFile *this, int newSize)
{
  unsigned int v2; // edi
  Scaleform::BufferedFile *v3; // rbx

  v2 = newSize;
  v3 = this;
  Scaleform::BufferedFile::FlushBuffer(this);
  return v3->pFile.pObject->vfptr[17].__vecDelDtor((Scaleform::RefCountImplCore *)v3->pFile.pObject, v2);
}

// File Line: 559
// RVA: 0x964900
__int64 __fastcall Scaleform::FILEFile::CopyFromStream(Scaleform::FILEFile *this, Scaleform::File *pstream, int byteSize)
{
  unsigned int v3; // edi
  int v4; // ebx
  Scaleform::File *v5; // r15
  Scaleform::FILEFile *v6; // r14
  signed int v7; // esi
  int v8; // er8
  signed int v9; // eax
  char v11; // [rsp+20h] [rbp-4018h]

  v3 = 0;
  v4 = byteSize;
  v5 = pstream;
  v6 = this;
  if ( !byteSize )
    return 0i64;
  do
  {
    v7 = v4;
    if ( v4 > 0x4000 )
      v7 = 0x4000;
    v8 = ((__int64 (__fastcall *)(Scaleform::File *, char *, _QWORD))v5->vfptr[10].__vecDelDtor)(
           v5,
           &v11,
           (unsigned int)v7);
    v9 = 0;
    if ( v8 > 0 )
      v9 = (__int64)v6->vfptr[9].__vecDelDtor((Scaleform::RefCountImplCore *)&v6->vfptr, (unsigned int)&v11);
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
  Scaleform::BufferedFile *v1; // rbx
  __int32 v2; // ecx

  v1 = this;
  v2 = this->BufferMode - 1;
  if ( v2 )
  {
    if ( v2 == 1 )
    {
      Scaleform::BufferedFile::FlushBuffer(v1);
      return ((__int64 (*)(void))v1->pFile.pObject->vfptr[19].__vecDelDtor)();
    }
  }
  else
  {
    v1->BufferMode = 0;
  }
  return ((__int64 (*)(void))v1->pFile.pObject->vfptr[19].__vecDelDtor)();
}

// File Line: 616
// RVA: 0x98B620
const char *__fastcall Scaleform::GetShortFilename(const char *purl)
{
  const char *v1; // rdx
  signed __int64 v2; // rax
  char v3; // cl

  v1 = purl;
  v2 = -1i64;
  do
    ++v2;
  while ( purl[v2] );
  if ( !v2 )
    return v1;
  while ( 1 )
  {
    v3 = v1[v2];
    if ( v3 == 92 || v3 == 47 )
      break;
    if ( !--v2 )
      return v1;
  }
  return &v1[v2 + 1];
}

