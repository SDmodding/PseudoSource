// File Line: 77
// RVA: 0x89FA80
void __fastcall Scaleform::GFx::ZLibFileImpl::ZLibFileImpl(Scaleform::GFx::ZLibFileImpl *this, Scaleform::File *pin)
{
  Scaleform::File *v2; // rdi
  Scaleform::GFx::ZLibFileImpl *v3; // rbx
  signed __int64 v4; // rcx

  v2 = pin;
  v3 = this;
  this->pIn.pObject = 0i64;
  if ( pin )
    Scaleform::Render::RenderBuffer::AddRef((Scaleform::GFx::Resource *)pin);
  if ( v3->pIn.pObject )
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v3->pIn.pObject);
  v3->pIn.pObject = v2;
  v3->InitialStreamPos = ((__int64 (__fastcall *)(Scaleform::File *))v2->vfptr[4].__vecDelDtor)(v2);
  v3->LogicalStreamPos = 0;
  v3->AtEofFlag = 0;
  v3->ErrorCode = 0;
  v4 = (signed __int64)&v3->ZStream;
  *(_QWORD *)(v4 + 48) = Scaleform::GFx::ZLibAllocFunc;
  *(_QWORD *)(v4 + 56) = Scaleform::GFx::ZLibFreeFunc;
  *(_QWORD *)(v4 + 64) = v3;
  *(_QWORD *)v4 = 0i64;
  *(_DWORD *)(v4 + 8) = 0;
  *(_QWORD *)(v4 + 16) = 0i64;
  *(_DWORD *)(v4 + 24) = 0;
  *(_QWORD *)(v4 + 72) = 0i64;
  *(_DWORD *)(v4 + 80) = 0;
  if ( (unsigned int)inflateInit_(&v3->ZStream, "1.2.7", 88i64) )
  {
    v3->ErrorCode = 1;
  }
  else
  {
    *(_QWORD *)&v3->BacktrackTail = 0i64;
    v3->UserPos = 0;
  }
}

// File Line: 117
// RVA: 0x9010D0
void __fastcall Scaleform::GFx::ZLibFileImpl::Reset(Scaleform::GFx::ZLibFileImpl *this)
{
  Scaleform::GFx::ZLibFileImpl *v1; // rbx
  z_stream_s *v2; // rcx
  Scaleform::File *v3; // rcx
  __int64 v4; // rdx

  v1 = this;
  v2 = &this->ZStream;
  v2[1].total_in = 0;
  LOBYTE(v2[1].avail_in) = 0;
  if ( (unsigned int)inflateReset() )
  {
    v1->ErrorCode = 1;
  }
  else
  {
    v3 = v1->pIn.pObject;
    v4 = (unsigned int)v1->InitialStreamPos;
    v1->ZStream.next_in = 0i64;
    v1->ZStream.avail_in = 0;
    v1->ZStream.next_out = 0i64;
    v1->ZStream.avail_out = 0;
    ((void (__fastcall *)(Scaleform::File *, __int64, _QWORD))v3->vfptr[14].__vecDelDtor)(v3, v4, 0i64);
    v1->LogicalStreamPos = 0;
    *(_QWORD *)&v1->BacktrackTail = 0i64;
    v1->UserPos = 0;
  }
}

// File Line: 147
// RVA: 0x8E3760
__int64 __fastcall Scaleform::GFx::ZLibFileImpl::Inflate(Scaleform::GFx::ZLibFileImpl *this, void *dst, int bytes)
{
  int v3; // eax
  int v4; // er15
  unsigned int v5; // er14
  int v6; // er12
  char *v7; // rbp
  Scaleform::GFx::ZLibFileImpl *v8; // rsi
  int v9; // ecx
  int v10; // er15
  int v11; // er13
  int v12; // edi
  int v13; // eax
  int v14; // edi
  char *v15; // rcx
  char *v16; // rdx
  signed __int64 v17; // rax
  __int128 v18; // xmm0
  __int64 result; // rax
  int v20; // er15
  signed int v21; // eax
  int v22; // ecx

  v3 = this->UserPos;
  v4 = this->LogicalStreamPos;
  v5 = 0;
  v6 = bytes;
  v7 = (char *)dst;
  v8 = this;
  if ( v3 < v4 )
  {
    v9 = this->BacktrackTail;
    v10 = v4 - v3;
    v11 = v10;
    if ( v10 > bytes )
      v11 = bytes;
    v5 = v11;
    if ( v10 > v9 )
    {
      v12 = v10 - v9;
      if ( v10 - v9 > v11 )
        v12 = v11;
      memmove(dst, &v8->BacktrackBuffer[v9 + v8->BacktrackSize - v10], v12);
      v11 -= v12;
      v10 -= v12;
      v7 += v12;
    }
    if ( v11 > 0 )
    {
      memmove(v7, &v8->BacktrackBuffer[v8->BacktrackTail - v10], v11);
      v7 += v11;
    }
    v6 -= v5;
    v8->UserPos += v5;
  }
  if ( v6 <= 0 )
    return v5;
  v13 = Scaleform::GFx::ZLibFileImpl::InflateFromStream(v8, v7, v6);
  v14 = v13;
  if ( v13 < 4096 )
  {
    if ( v13 > 0 )
    {
      v20 = v13;
      if ( 4096 - v8->BacktrackTail < v13 )
        v20 = 4096 - v8->BacktrackTail;
      if ( v20 > 0 )
      {
        memmove(&v8->BacktrackBuffer[v8->BacktrackTail], v7, v20);
        v7 += v20;
        v8->BacktrackTail += v20;
      }
      if ( v14 > v20 )
      {
        v8->BacktrackTail = v14 - v20;
        memmove(v8->BacktrackBuffer, v7, v14 - v20);
      }
      v21 = v8->BacktrackSize;
      if ( v21 < 4096 )
      {
        v22 = v21 + v14;
        if ( v21 + v14 > 4096 )
          v22 = 4096;
        v8->BacktrackSize = v22;
      }
    }
    result = v14 + v5;
    v8->UserPos = v8->LogicalStreamPos;
  }
  else
  {
    v15 = v8->BacktrackBuffer;
    v8->BacktrackTail = 4096;
    v8->BacktrackSize = 4096;
    v16 = &v7[v13 - 4096];
    if ( ((unsigned __int8)((_BYTE)v8 + 124) | (unsigned __int8)((_BYTE)v7 + v13)) & 0xF )
    {
      memmove(v15, v16, 0x1000ui64);
      result = v14 + v5;
      v8->UserPos = v8->LogicalStreamPos;
    }
    else
    {
      v17 = 32i64;
      do
      {
        v18 = *(_OWORD *)v16;
        v15 += 128;
        v16 += 128;
        *((_OWORD *)v15 - 8) = v18;
        *((_OWORD *)v15 - 7) = *((_OWORD *)v16 - 7);
        *((_OWORD *)v15 - 6) = *((_OWORD *)v16 - 6);
        *((_OWORD *)v15 - 5) = *((_OWORD *)v16 - 5);
        *((_OWORD *)v15 - 4) = *((_OWORD *)v16 - 4);
        *((_OWORD *)v15 - 3) = *((_OWORD *)v16 - 3);
        *((_OWORD *)v15 - 2) = *((_OWORD *)v16 - 2);
        *((_OWORD *)v15 - 1) = *((_OWORD *)v16 - 1);
        --v17;
      }
      while ( v17 );
      result = v14 + v5;
      v8->UserPos = v8->LogicalStreamPos;
    }
  }
  return result;
}

// File Line: 280
// RVA: 0x909DB0
__int64 __fastcall Scaleform::GFx::ZLibFileImpl::SetPosition(Scaleform::GFx::ZLibFileImpl *this, int offset)
{
  int v2; // eax
  int v3; // edi
  Scaleform::GFx::ZLibFileImpl *v4; // rbx
  int v6; // er8
  char dst; // [rsp+20h] [rbp-1008h]

  v2 = this->LogicalStreamPos;
  v3 = offset;
  v4 = this;
  if ( offset >= v2 )
  {
    if ( offset > v2 )
      this->UserPos = v2;
  }
  else
  {
    if ( offset >= v2 - this->BacktrackSize )
    {
      this->UserPos = offset;
      return (unsigned int)offset;
    }
    Scaleform::GFx::ZLibFileImpl::Reset(this);
  }
  if ( v4->UserPos < v3 )
  {
    do
    {
      v6 = 4096;
      if ( v3 - v4->UserPos < 4096 )
        v6 = v3 - v4->UserPos;
    }
    while ( (unsigned int)Scaleform::GFx::ZLibFileImpl::Inflate(v4, &dst, v6) && v4->UserPos < v3 );
  }
  return (unsigned int)v4->UserPos;
}

// File Line: 327
// RVA: 0x8E3970
__int64 __fastcall Scaleform::GFx::ZLibFileImpl::InflateFromStream(Scaleform::GFx::ZLibFileImpl *this, void *dst, int bytes)
{
  int v3; // esi
  Scaleform::GFx::ZLibFileImpl *v4; // rbx
  unsigned int v6; // eax
  int v7; // eax
  unsigned int v8; // esi

  v3 = bytes;
  v4 = this;
  if ( this->ErrorCode )
    return 0i64;
  this->ZStream.next_out = (char *)dst;
  this->ZStream.avail_out = bytes;
  while ( 1 )
  {
    if ( !v4->ZStream.avail_in )
    {
      v6 = ((__int64 (__fastcall *)(Scaleform::File *, char *, signed __int64))v4->pIn.pObject->vfptr[10].__vecDelDtor)(
             v4->pIn.pObject,
             v4->DataBuffer,
             4096i64);
      if ( !v6 )
        goto LABEL_13;
      v4->ZStream.next_in = v4->DataBuffer;
      v4->ZStream.avail_in = v6;
    }
    v7 = inflate(&v4->ZStream, 2i64);
    if ( v7 == 1 )
      break;
    if ( v7 )
    {
      v4->ErrorCode = 1;
      goto LABEL_13;
    }
    if ( !v4->ZStream.avail_out )
      goto LABEL_13;
  }
  v4->AtEofFlag = 1;
LABEL_13:
  v8 = v3 - v4->ZStream.avail_out;
  v4->LogicalStreamPos += v8;
  return v8;
}

// File Line: 400
// RVA: 0x89F9C0
void __fastcall Scaleform::GFx::ZLibFile::ZLibFile(Scaleform::GFx::ZLibFile *this, Scaleform::File *psourceFile)
{
  Scaleform::File *v2; // rdi
  Scaleform::GFx::ZLibFile *v3; // rbx
  Scaleform::GFx::ZLibFileImpl *v4; // rsi
  Scaleform::GFx::ZLibFileImpl *v5; // rax
  Scaleform::GFx::ZLibFileImpl *v6; // rax
  int v7; // [rsp+58h] [rbp+10h]
  Scaleform::GFx::ZLibFileImpl *v8; // [rsp+60h] [rbp+18h]

  v2 = psourceFile;
  v3 = this;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::File,2>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::File::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::ZLibFile::`vftable;
  v4 = 0i64;
  this->pImpl = 0i64;
  if ( psourceFile
    && ((unsigned __int8 (__fastcall *)(Scaleform::File *))psourceFile->vfptr[2].__vecDelDtor)(psourceFile) )
  {
    v7 = 2;
    v5 = (Scaleform::GFx::ZLibFileImpl *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::GFx::ZLibFile *, signed __int64, int *, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap)(
                                           Scaleform::Memory::pGlobalHeap,
                                           v3,
                                           8320i64,
                                           &v7,
                                           -2i64);
    v8 = v5;
    if ( v5 )
    {
      Scaleform::GFx::ZLibFileImpl::ZLibFileImpl(v5, v2);
      v4 = v6;
    }
    v3->pImpl = v4;
  }
}

// File Line: 411
// RVA: 0x8A8AB0
void __fastcall Scaleform::GFx::ZLibFile::~ZLibFile(Scaleform::GFx::ZLibFile *this)
{
  Scaleform::GFx::ZLibFile *v1; // rbx
  Scaleform::GFx::ZLibFileImpl *v2; // rdi
  int v3; // eax
  Scaleform::Render::RenderBuffer **v4; // rdi

  v1 = this;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::ZLibFile::`vftable;
  v2 = this->pImpl;
  if ( v2 )
  {
    if ( v2->ZStream.avail_in )
    {
      v3 = ((__int64 (__cdecl *)(Scaleform::File *))v2->pIn.pObject->vfptr[4].__vecDelDtor)(v2->pIn.pObject);
      ((void (__fastcall *)(Scaleform::File *, _QWORD, _QWORD))v2->pIn.pObject->vfptr[14].__vecDelDtor)(
        v2->pIn.pObject,
        v3 - v2->ZStream.avail_in,
        0i64);
    }
    inflateEnd(&v1->pImpl->ZStream);
    v4 = (Scaleform::Render::RenderBuffer **)v1->pImpl;
    if ( v4 )
    {
      if ( *v4 )
        Scaleform::RefCountImpl::Release(*v4);
      Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v4);
    }
  }
  Scaleform::RefCountImplCore::~RefCountImplCore((Scaleform::RefCountImplCore *)&v1->vfptr);
}

// File Line: 424
// RVA: 0x8D7B40
const char *__fastcall Scaleform::GFx::ZLibFile::GetFilePath(Scaleform::GFx::ZLibFile *this)
{
  Scaleform::GFx::ZLibFileImpl *v1; // rcx
  const char *result; // rax

  v1 = this->pImpl;
  if ( v1 )
    result = (const char *)((__int64 (*)(void))v1->pIn.pObject->vfptr[1].__vecDelDtor)();
  else
    result = 0i64;
  return result;
}

// File Line: 436
// RVA: 0x912CF0
signed __int64 __fastcall Scaleform::GFx::ZLibFile::Tell(Scaleform::GFx::ZLibFile *this)
{
  Scaleform::GFx::ZLibFileImpl *v1; // rax
  signed __int64 result; // rax

  v1 = this->pImpl;
  if ( v1 )
    result = (unsigned int)v1->UserPos;
  else
    result = 0xFFFFFFFFi64;
  return result;
}

// File Line: 441
// RVA: 0x8E80D0
__int64 __fastcall Scaleform::GFx::ZLibFile::LTell(Scaleform::GFx::ZLibFile *this)
{
  return ((signed int (*)(void))this->vfptr[4].__vecDelDtor)();
}

// File Line: 445
// RVA: 0x8DAB10
__int64 __fastcall Scaleform::GFx::ZLibFile::GetLength(Scaleform::GFx::ZLibFile *this)
{
  Scaleform::GFx::ZLibFileImpl *v1; // rax
  Scaleform::GFx::ZLibFile *v2; // rsi
  unsigned int v4; // edi
  unsigned int v5; // ebx

  v1 = this->pImpl;
  v2 = this;
  if ( !v1 || v1->ErrorCode )
    return 0i64;
  v4 = v1->UserPos;
  v5 = ((__int64 (__fastcall *)(Scaleform::GFx::ZLibFile *, _QWORD, signed __int64))this->vfptr[14].__vecDelDtor)(
         this,
         0i64,
         2i64);
  ((void (__fastcall *)(Scaleform::GFx::ZLibFile *, _QWORD, _QWORD))v2->vfptr[14].__vecDelDtor)(v2, v4, 0i64);
  return v5;
}

// File Line: 464
// RVA: 0x8D7540
Scaleform::GFx::ZLibFileImpl *__fastcall Scaleform::GFx::ZLibFile::GetErrorCode(Scaleform::GFx::ZLibFile *this)
{
  Scaleform::GFx::ZLibFileImpl *result; // rax

  result = this->pImpl;
  if ( result )
    result = (Scaleform::GFx::ZLibFileImpl *)(unsigned int)result->ErrorCode;
  return result;
}

// File Line: 480
// RVA: 0x8FA860
__int64 __fastcall Scaleform::GFx::ZLibFile::Read(Scaleform::GFx::ZLibFile *this, char *pbuffer, int numBytes)
{
  Scaleform::GFx::ZLibFileImpl *v3; // rcx
  __int64 result; // rax

  v3 = this->pImpl;
  if ( v3 )
    result = Scaleform::GFx::ZLibFileImpl::Inflate(v3, pbuffer, numBytes);
  else
    result = 0xFFFFFFFFi64;
  return result;
}

// File Line: 487
// RVA: 0x910BC0
__int64 __fastcall Scaleform::GFx::ZLibFile::SkipBytes(Scaleform::GFx::ZLibFile *this, __int64 numBytes)
{
  return ((__int64 (__fastcall *)(Scaleform::GFx::ZLibFile *, __int64, signed __int64))this->vfptr[14].__vecDelDtor)(
           this,
           numBytes,
           1i64);
}

// File Line: 492
// RVA: 0x8B8940
__int64 __fastcall Scaleform::GFx::ZLibFile::BytesAvailable(Scaleform::GFx::ZLibFile *this)
{
  Scaleform::GFx::ZLibFileImpl *v1; // rax
  Scaleform::GFx::ZLibFile *v2; // rsi
  unsigned int v4; // edi
  int v5; // ebx

  v1 = this->pImpl;
  v2 = this;
  if ( !v1 || v1->ErrorCode )
    return 0i64;
  v4 = v1->UserPos;
  v5 = ((__int64 (__fastcall *)(Scaleform::GFx::ZLibFile *, _QWORD, signed __int64))this->vfptr[14].__vecDelDtor)(
         this,
         0i64,
         2i64);
  ((void (__fastcall *)(Scaleform::GFx::ZLibFile *, _QWORD, _QWORD))v2->vfptr[14].__vecDelDtor)(v2, v4, 0i64);
  return v5 - v4;
}

// File Line: 513
// RVA: 0x904A40
signed __int64 __fastcall Scaleform::GFx::ZLibFile::Seek(Scaleform::GFx::ZLibFile *this, int offset, int origin)
{
  Scaleform::GFx::ZLibFile *v3; // rdi
  Scaleform::GFx::ZLibFileImpl *v4; // rcx
  int v5; // ebx
  int v7; // er8

  v3 = this;
  v4 = this->pImpl;
  v5 = offset;
  if ( !v4 )
    return 0xFFFFFFFFi64;
  if ( v4->ErrorCode )
    return (unsigned int)v4->UserPos;
  if ( origin )
  {
    v7 = origin - 1;
    if ( v7 )
    {
      if ( v7 != 1 )
        return (unsigned int)v3->pImpl->UserPos;
      Scaleform::GFx::ZLibFileImpl::SetPosition(v4, 0x7FFFFFFF);
      if ( !v5 )
        return (unsigned int)v3->pImpl->UserPos;
      v4 = v3->pImpl;
    }
    v5 += v4->UserPos;
  }
  Scaleform::GFx::ZLibFileImpl::SetPosition(v4, v5);
  return (unsigned int)v3->pImpl->UserPos;
}

// File Line: 571
// RVA: 0x8BD1B0
bool __fastcall Scaleform::GFx::ZLibFile::Close(Scaleform::GFx::ZLibFile *this)
{
  Scaleform::GFx::ZLibFile *v1; // rbx
  Scaleform::GFx::ZLibFileImpl *v2; // rdi
  int v4; // eax
  int v5; // esi
  Scaleform::Render::RenderBuffer **v6; // rdi

  v1 = this;
  v2 = this->pImpl;
  if ( !v2 )
    return 0;
  if ( v2->ZStream.avail_in )
  {
    v4 = ((__int64 (__cdecl *)(Scaleform::File *))v2->pIn.pObject->vfptr[4].__vecDelDtor)(v2->pIn.pObject);
    ((void (__fastcall *)(Scaleform::File *, _QWORD, _QWORD))v2->pIn.pObject->vfptr[14].__vecDelDtor)(
      v2->pIn.pObject,
      v4 - v2->ZStream.avail_in,
      0i64);
  }
  v5 = inflateEnd(&v1->pImpl->ZStream);
  ((void (__cdecl *)(Scaleform::File *))v1->pImpl->pIn.pObject->vfptr[19].__vecDelDtor)(v1->pImpl->pIn.pObject);
  v6 = (Scaleform::Render::RenderBuffer **)v1->pImpl;
  if ( v6 )
  {
    if ( *v6 )
      Scaleform::RefCountImpl::Release(*v6);
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v6);
  }
  v1->pImpl = 0i64;
  return v5 == 0;
}

// File Line: 590
// RVA: 0x91CC50
__int64 __fastcall Scaleform::GFx::ZLibAllocFunc(void *opaque, unsigned int items, unsigned int size)
{
  return Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap(
           Scaleform::Memory::pGlobalHeap,
           opaque,
           items * size,
           0i64);
}

// File Line: 597
// RVA: 0x91CC70
void __fastcall Scaleform::GFx::ZLibFreeFunc(void *__formal, void *address)
{
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, address);
}

