// File Line: 77
// RVA: 0x89FA80
void __fastcall Scaleform::GFx::ZLibFileImpl::ZLibFileImpl(
        Scaleform::GFx::ZLibFileImpl *this,
        Scaleform::GFx::Resource *pin)
{
  this->pIn.pObject = 0i64;
  if ( pin )
    Scaleform::Render::RenderBuffer::AddRef(pin);
  if ( this->pIn.pObject )
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)this->pIn.pObject);
  this->pIn.pObject = (Scaleform::File *)pin;
  this->InitialStreamPos = ((__int64 (__fastcall *)(Scaleform::GFx::Resource *))pin->vfptr[1].__vecDelDtor)(pin);
  this->LogicalStreamPos = 0;
  this->AtEofFlag = 0;
  this->ErrorCode = 0;
  this->ZStream.zalloc = Scaleform::GFx::ZLibAllocFunc;
  this->ZStream.zfree = Scaleform::GFx::ZLibFreeFunc;
  this->ZStream.opaque = this;
  this->ZStream.next_in = 0i64;
  this->ZStream.avail_in = 0;
  this->ZStream.next_out = 0i64;
  this->ZStream.avail_out = 0;
  *(_QWORD *)&this->ZStream.data_type = 0i64;
  this->ZStream.reserved = 0;
  if ( (unsigned int)inflateInit_(&this->ZStream, "1.2.7", 88i64) )
  {
    this->ErrorCode = 1;
  }
  else
  {
    *(_QWORD *)&this->BacktrackTail = 0i64;
    this->UserPos = 0;
  }
}

// File Line: 117
// RVA: 0x9010D0
void __fastcall Scaleform::GFx::ZLibFileImpl::Reset(Scaleform::GFx::ZLibFileImpl *this)
{
  z_stream_s *p_ZStream; // rcx
  Scaleform::File *pObject; // rcx
  __int64 InitialStreamPos; // rdx

  p_ZStream = &this->ZStream;
  p_ZStream[1].total_in = 0;
  LOBYTE(p_ZStream[1].avail_in) = 0;
  if ( (unsigned int)inflateReset() )
  {
    this->ErrorCode = 1;
  }
  else
  {
    pObject = this->pIn.pObject;
    InitialStreamPos = (unsigned int)this->InitialStreamPos;
    this->ZStream.next_in = 0i64;
    this->ZStream.avail_in = 0;
    this->ZStream.next_out = 0i64;
    this->ZStream.avail_out = 0;
    ((void (__fastcall *)(Scaleform::File *, __int64, _QWORD))pObject->vfptr[14].__vecDelDtor)(
      pObject,
      InitialStreamPos,
      0i64);
    this->LogicalStreamPos = 0;
    *(_QWORD *)&this->BacktrackTail = 0i64;
    this->UserPos = 0;
  }
}

// File Line: 147
// RVA: 0x8E3760
__int64 __fastcall Scaleform::GFx::ZLibFileImpl::Inflate(Scaleform::GFx::ZLibFileImpl *this, char *dst, int bytes)
{
  int UserPos; // eax
  int LogicalStreamPos; // r15d
  unsigned int v5; // r14d
  int v6; // r12d
  char *v7; // rbp
  int BacktrackTail; // ecx
  int v10; // r15d
  int v11; // r13d
  int v12; // edi
  int v13; // eax
  int v14; // edi
  char *BacktrackBuffer; // rcx
  char *v16; // rdx
  __int64 v17; // rax
  __int128 v18; // xmm0
  __int64 result; // rax
  int v20; // r15d
  int BacktrackSize; // eax
  int v22; // ecx

  UserPos = this->UserPos;
  LogicalStreamPos = this->LogicalStreamPos;
  v5 = 0;
  v6 = bytes;
  v7 = dst;
  if ( UserPos < LogicalStreamPos )
  {
    BacktrackTail = this->BacktrackTail;
    v10 = LogicalStreamPos - UserPos;
    v11 = v10;
    if ( v10 > bytes )
      v11 = bytes;
    v5 = v11;
    if ( v10 > BacktrackTail )
    {
      v12 = v10 - BacktrackTail;
      if ( v10 - BacktrackTail > v11 )
        v12 = v11;
      memmove(dst, &this->BacktrackBuffer[BacktrackTail + this->BacktrackSize - v10], v12);
      v11 -= v12;
      v10 -= v12;
      v7 += v12;
    }
    if ( v11 > 0 )
    {
      memmove(v7, &this->BacktrackBuffer[this->BacktrackTail - v10], v11);
      v7 += v11;
    }
    v6 -= v5;
    this->UserPos += v5;
  }
  if ( v6 <= 0 )
    return v5;
  v13 = Scaleform::GFx::ZLibFileImpl::InflateFromStream(this, v7, v6);
  v14 = v13;
  if ( v13 < 4096 )
  {
    if ( v13 > 0 )
    {
      v20 = v13;
      if ( 4096 - this->BacktrackTail < v13 )
        v20 = 4096 - this->BacktrackTail;
      if ( v20 > 0 )
      {
        memmove(&this->BacktrackBuffer[this->BacktrackTail], v7, v20);
        v7 += v20;
        this->BacktrackTail += v20;
      }
      if ( v14 > v20 )
      {
        this->BacktrackTail = v14 - v20;
        memmove(this->BacktrackBuffer, v7, v14 - v20);
      }
      BacktrackSize = this->BacktrackSize;
      if ( BacktrackSize < 4096 )
      {
        v22 = BacktrackSize + v14;
        if ( BacktrackSize + v14 > 4096 )
          v22 = 4096;
        this->BacktrackSize = v22;
      }
    }
    result = v14 + v5;
    this->UserPos = this->LogicalStreamPos;
  }
  else
  {
    BacktrackBuffer = this->BacktrackBuffer;
    this->BacktrackTail = 4096;
    this->BacktrackSize = 4096;
    v16 = &v7[v13 - 4096];
    if ( (((unsigned __int8)((_BYTE)this + 124) | (unsigned __int8)((_BYTE)v7 + v13)) & 0xF) != 0 )
    {
      memmove(BacktrackBuffer, v16, 0x1000ui64);
      result = v14 + v5;
      this->UserPos = this->LogicalStreamPos;
    }
    else
    {
      v17 = 32i64;
      do
      {
        v18 = *(_OWORD *)v16;
        BacktrackBuffer += 128;
        v16 += 128;
        *((_OWORD *)BacktrackBuffer - 8) = v18;
        *((_OWORD *)BacktrackBuffer - 7) = *((_OWORD *)v16 - 7);
        *((_OWORD *)BacktrackBuffer - 6) = *((_OWORD *)v16 - 6);
        *((_OWORD *)BacktrackBuffer - 5) = *((_OWORD *)v16 - 5);
        *((_OWORD *)BacktrackBuffer - 4) = *((_OWORD *)v16 - 4);
        *((_OWORD *)BacktrackBuffer - 3) = *((_OWORD *)v16 - 3);
        *((_OWORD *)BacktrackBuffer - 2) = *((_OWORD *)v16 - 2);
        *((_OWORD *)BacktrackBuffer - 1) = *((_OWORD *)v16 - 1);
        --v17;
      }
      while ( v17 );
      result = v14 + v5;
      this->UserPos = this->LogicalStreamPos;
    }
  }
  return result;
}

// File Line: 280
// RVA: 0x909DB0
__int64 __fastcall Scaleform::GFx::ZLibFileImpl::SetPosition(Scaleform::GFx::ZLibFileImpl *this, int offset)
{
  int LogicalStreamPos; // eax
  int v6; // r8d
  char dst[4104]; // [rsp+20h] [rbp-1008h] BYREF

  LogicalStreamPos = this->LogicalStreamPos;
  if ( offset >= LogicalStreamPos )
  {
    if ( offset > LogicalStreamPos )
      this->UserPos = LogicalStreamPos;
  }
  else
  {
    if ( offset >= LogicalStreamPos - this->BacktrackSize )
    {
      this->UserPos = offset;
      return (unsigned int)offset;
    }
    Scaleform::GFx::ZLibFileImpl::Reset(this);
  }
  if ( this->UserPos < offset )
  {
    do
    {
      v6 = 4096;
      if ( offset - this->UserPos < 4096 )
        v6 = offset - this->UserPos;
    }
    while ( (unsigned int)Scaleform::GFx::ZLibFileImpl::Inflate(this, dst, v6) && this->UserPos < offset );
  }
  return (unsigned int)this->UserPos;
}

// File Line: 327
// RVA: 0x8E3970
__int64 __fastcall Scaleform::GFx::ZLibFileImpl::InflateFromStream(
        Scaleform::GFx::ZLibFileImpl *this,
        char *dst,
        unsigned int bytes)
{
  unsigned int v6; // eax
  int v7; // eax
  unsigned int v8; // esi

  if ( this->ErrorCode )
    return 0i64;
  this->ZStream.next_out = dst;
  this->ZStream.avail_out = bytes;
  while ( 1 )
  {
    if ( !this->ZStream.avail_in )
    {
      v6 = ((__int64 (__fastcall *)(Scaleform::File *, char *, __int64))this->pIn.pObject->vfptr[10].__vecDelDtor)(
             this->pIn.pObject,
             this->DataBuffer,
             4096i64);
      if ( !v6 )
        goto LABEL_13;
      this->ZStream.next_in = this->DataBuffer;
      this->ZStream.avail_in = v6;
    }
    v7 = inflate(&this->ZStream, 2i64);
    if ( v7 == 1 )
      break;
    if ( v7 )
    {
      this->ErrorCode = 1;
      goto LABEL_13;
    }
    if ( !this->ZStream.avail_out )
      goto LABEL_13;
  }
  this->AtEofFlag = 1;
LABEL_13:
  v8 = bytes - this->ZStream.avail_out;
  this->LogicalStreamPos += v8;
  return v8;
}

// File Line: 400
// RVA: 0x89F9C0
void __fastcall Scaleform::GFx::ZLibFile::ZLibFile(Scaleform::GFx::ZLibFile *this, Scaleform::File *psourceFile)
{
  Scaleform::GFx::ZLibFileImpl *v4; // rsi
  Scaleform::GFx::ZLibFileImpl *v5; // rax
  Scaleform::GFx::ZLibFileImpl *v6; // rax
  int v7; // [rsp+58h] [rbp+10h] BYREF
  Scaleform::GFx::ZLibFileImpl *v8; // [rsp+60h] [rbp+18h]

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
    v5 = (Scaleform::GFx::ZLibFileImpl *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::GFx::ZLibFile *, __int64, int *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap)(
                                           Scaleform::Memory::pGlobalHeap,
                                           this,
                                           8320i64,
                                           &v7,
                                           -2i64);
    v8 = v5;
    if ( v5 )
    {
      Scaleform::GFx::ZLibFileImpl::ZLibFileImpl(v5, psourceFile);
      v4 = v6;
    }
    this->pImpl = v4;
  }
}

// File Line: 411
// RVA: 0x8A8AB0
void __fastcall Scaleform::GFx::ZLibFile::~ZLibFile(Scaleform::GFx::ZLibFile *this)
{
  Scaleform::GFx::ZLibFileImpl *pImpl; // rdi
  int v3; // eax
  Scaleform::Render::RenderBuffer **v4; // rdi

  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::ZLibFile::`vftable;
  pImpl = this->pImpl;
  if ( pImpl )
  {
    if ( pImpl->ZStream.avail_in )
    {
      v3 = ((__int64 (__fastcall *)(Scaleform::File *))pImpl->pIn.pObject->vfptr[4].__vecDelDtor)(pImpl->pIn.pObject);
      ((void (__fastcall *)(Scaleform::File *, _QWORD, _QWORD))pImpl->pIn.pObject->vfptr[14].__vecDelDtor)(
        pImpl->pIn.pObject,
        v3 - pImpl->ZStream.avail_in,
        0i64);
    }
    inflateEnd(&this->pImpl->ZStream);
    v4 = (Scaleform::Render::RenderBuffer **)this->pImpl;
    if ( v4 )
    {
      if ( *v4 )
        Scaleform::RefCountImpl::Release(*v4);
      Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v4);
    }
  }
  Scaleform::RefCountImplCore::~RefCountImplCore(this);
}

// File Line: 424
// RVA: 0x8D7B40
const char *__fastcall Scaleform::GFx::ZLibFile::GetFilePath(Scaleform::GFx::ZLibFile *this)
{
  Scaleform::GFx::ZLibFileImpl *pImpl; // rcx

  pImpl = this->pImpl;
  if ( pImpl )
    return (const char *)((__int64 (__fastcall *)(Scaleform::File *))pImpl->pIn.pObject->vfptr[1].__vecDelDtor)(pImpl->pIn.pObject);
  else
    return 0i64;
}

// File Line: 436
// RVA: 0x912CF0
__int64 __fastcall Scaleform::GFx::ZLibFile::Tell(Scaleform::GFx::ZLibFile *this)
{
  Scaleform::GFx::ZLibFileImpl *pImpl; // rax

  pImpl = this->pImpl;
  if ( pImpl )
    return (unsigned int)pImpl->UserPos;
  else
    return 0xFFFFFFFFi64;
}

// File Line: 441
// RVA: 0x8E80D0
__int64 __fastcall Scaleform::GFx::ZLibFile::LTell(Scaleform::GFx::ZLibFile *this)
{
  return ((int (__fastcall *)(Scaleform::GFx::ZLibFile *))this->vfptr[4].__vecDelDtor)(this);
}

// File Line: 445
// RVA: 0x8DAB10
__int64 __fastcall Scaleform::GFx::ZLibFile::GetLength(Scaleform::GFx::ZLibFile *this)
{
  Scaleform::GFx::ZLibFileImpl *pImpl; // rax
  unsigned int UserPos; // edi
  unsigned int v5; // ebx

  pImpl = this->pImpl;
  if ( !pImpl || pImpl->ErrorCode )
    return 0i64;
  UserPos = pImpl->UserPos;
  v5 = ((__int64 (__fastcall *)(Scaleform::GFx::ZLibFile *, _QWORD, __int64))this->vfptr[14].__vecDelDtor)(
         this,
         0i64,
         2i64);
  ((void (__fastcall *)(Scaleform::GFx::ZLibFile *, _QWORD, _QWORD))this->vfptr[14].__vecDelDtor)(this, UserPos, 0i64);
  return v5;
}

// File Line: 464
// RVA: 0x8D7540
Scaleform::GFx::ZLibFileImpl *__fastcall Scaleform::GFx::ZLibFile::GetErrorCode(Scaleform::GFx::ZLibFile *this)
{
  Scaleform::GFx::ZLibFileImpl *result; // rax

  result = this->pImpl;
  if ( result )
    return (Scaleform::GFx::ZLibFileImpl *)(unsigned int)result->ErrorCode;
  return result;
}

// File Line: 480
// RVA: 0x8FA860
__int64 __fastcall Scaleform::GFx::ZLibFile::Read(Scaleform::GFx::ZLibFile *this, char *pbuffer, int numBytes)
{
  Scaleform::GFx::ZLibFileImpl *pImpl; // rcx

  pImpl = this->pImpl;
  if ( pImpl )
    return Scaleform::GFx::ZLibFileImpl::Inflate(pImpl, pbuffer, numBytes);
  else
    return 0xFFFFFFFFi64;
}

// File Line: 487
// RVA: 0x910BC0
__int64 __fastcall Scaleform::GFx::ZLibFile::SkipBytes(Scaleform::GFx::ZLibFile *this, __int64 numBytes)
{
  return ((__int64 (__fastcall *)(Scaleform::GFx::ZLibFile *, __int64, __int64))this->vfptr[14].__vecDelDtor)(
           this,
           numBytes,
           1i64);
}

// File Line: 492
// RVA: 0x8B8940
__int64 __fastcall Scaleform::GFx::ZLibFile::BytesAvailable(Scaleform::GFx::ZLibFile *this)
{
  Scaleform::GFx::ZLibFileImpl *pImpl; // rax
  unsigned int UserPos; // edi
  int v5; // ebx

  pImpl = this->pImpl;
  if ( !pImpl || pImpl->ErrorCode )
    return 0i64;
  UserPos = pImpl->UserPos;
  v5 = ((__int64 (__fastcall *)(Scaleform::GFx::ZLibFile *, _QWORD, __int64))this->vfptr[14].__vecDelDtor)(
         this,
         0i64,
         2i64);
  ((void (__fastcall *)(Scaleform::GFx::ZLibFile *, _QWORD, _QWORD))this->vfptr[14].__vecDelDtor)(this, UserPos, 0i64);
  return v5 - UserPos;
}

// File Line: 513
// RVA: 0x904A40
__int64 __fastcall Scaleform::GFx::ZLibFile::Seek(Scaleform::GFx::ZLibFile *this, int offset, int origin)
{
  Scaleform::GFx::ZLibFileImpl *pImpl; // rcx
  int v7; // r8d

  pImpl = this->pImpl;
  if ( !pImpl )
    return 0xFFFFFFFFi64;
  if ( pImpl->ErrorCode )
    return (unsigned int)pImpl->UserPos;
  if ( origin )
  {
    v7 = origin - 1;
    if ( v7 )
    {
      if ( v7 != 1 )
        return (unsigned int)this->pImpl->UserPos;
      Scaleform::GFx::ZLibFileImpl::SetPosition(pImpl, 0x7FFFFFFF);
      if ( !offset )
        return (unsigned int)this->pImpl->UserPos;
      pImpl = this->pImpl;
    }
    offset += pImpl->UserPos;
  }
  Scaleform::GFx::ZLibFileImpl::SetPosition(pImpl, offset);
  return (unsigned int)this->pImpl->UserPos;
}

// File Line: 571
// RVA: 0x8BD1B0
bool __fastcall Scaleform::GFx::ZLibFile::Close(Scaleform::GFx::ZLibFile *this)
{
  Scaleform::GFx::ZLibFileImpl *pImpl; // rdi
  int v4; // eax
  int v5; // esi
  Scaleform::Render::RenderBuffer **v6; // rdi

  pImpl = this->pImpl;
  if ( !pImpl )
    return 0;
  if ( pImpl->ZStream.avail_in )
  {
    v4 = ((__int64 (__fastcall *)(Scaleform::File *))pImpl->pIn.pObject->vfptr[4].__vecDelDtor)(pImpl->pIn.pObject);
    ((void (__fastcall *)(Scaleform::File *, _QWORD, _QWORD))pImpl->pIn.pObject->vfptr[14].__vecDelDtor)(
      pImpl->pIn.pObject,
      v4 - pImpl->ZStream.avail_in,
      0i64);
  }
  v5 = inflateEnd(&this->pImpl->ZStream);
  ((void (__fastcall *)(Scaleform::File *))this->pImpl->pIn.pObject->vfptr[19].__vecDelDtor)(this->pImpl->pIn.pObject);
  v6 = (Scaleform::Render::RenderBuffer **)this->pImpl;
  if ( v6 )
  {
    if ( *v6 )
      Scaleform::RefCountImpl::Release(*v6);
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v6);
  }
  this->pImpl = 0i64;
  return v5 == 0;
}

// File Line: 590
// RVA: 0x91CC50
void *__fastcall Scaleform::GFx::ZLibAllocFunc(void *opaque, unsigned int items, unsigned int size)
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

