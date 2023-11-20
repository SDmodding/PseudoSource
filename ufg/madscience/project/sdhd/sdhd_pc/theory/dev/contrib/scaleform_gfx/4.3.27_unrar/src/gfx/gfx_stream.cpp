// File Line: 48
// RVA: 0x89D9B0
void __fastcall Scaleform::GFx::Stream::Stream(Scaleform::GFx::Stream *this, const char *pbuffer, unsigned int bufSize, Scaleform::MemoryHeap *pheap, Scaleform::Log *plog, Scaleform::GFx::ParseControl *pparseControl)
{
  unsigned int v6; // esi
  const char *v7; // rbx
  Scaleform::GFx::Stream *v8; // rdi
  Scaleform::Render::RenderBuffer *v9; // rcx
  unsigned int v10; // ecx
  unsigned int v11; // eax

  v6 = bufSize;
  v7 = pbuffer;
  v8 = this;
  this->vfptr = (Scaleform::GFx::LogBase<Scaleform::GFx::Stream>Vtbl *)&Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::`vftable';
  this->vfptr = (Scaleform::GFx::LogBase<Scaleform::GFx::Stream>Vtbl *)&Scaleform::GFx::Stream::`vftable';
  this->pInput.pObject = 0i64;
  Scaleform::StringDH::StringDH(&this->FileName, pheap);
  v8->pBuffer = (char *)v7;
  if ( v7 )
    v8->BufferSize = v6;
  else
    v8->BufferSize = 0;
  v9 = (Scaleform::Render::RenderBuffer *)v8->pInput.pObject;
  if ( v9 )
    Scaleform::RefCountImpl::Release(v9);
  v8->pInput.pObject = 0i64;
  v8->pLog = plog;
  v8->pParseControl = pparseControl;
  if ( pparseControl )
    v10 = pparseControl->ParseFlags;
  else
    v10 = 0;
  v8->ParseFlags = v10;
  *(_WORD *)&v8->CurrentByte = 0;
  Scaleform::String::Clear((Scaleform::String *)&v8->FileName.0);
  *(_QWORD *)&v8->TagStack[1] = 0i64;
  v8->TagStack[0] = 0;
  v8->Pos = 0;
  v8->ResyncFile = 0;
  v11 = v8->BufferSize;
  v8->DataSize = v11;
  v8->FilePos = v11;
}

// File Line: 62
// RVA: 0x8A7F20
void __fastcall Scaleform::GFx::Stream::~Stream(Scaleform::GFx::Stream *this)
{
  Scaleform::GFx::Stream *v1; // rbx
  Scaleform::Render::RenderBuffer *v2; // rcx

  v1 = this;
  this->vfptr = (Scaleform::GFx::LogBase<Scaleform::GFx::Stream>Vtbl *)&Scaleform::GFx::Stream::`vftable';
  if ( !_InterlockedDecrement((volatile signed __int32 *)((this->FileName.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
    ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  v2 = (Scaleform::Render::RenderBuffer *)v1->pInput.pObject;
  if ( v2 )
    Scaleform::RefCountImpl::Release(v2);
  v1->vfptr = (Scaleform::GFx::LogBase<Scaleform::GFx::Stream>Vtbl *)&Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::`vftable';
}

// File Line: 66
// RVA: 0x8E5C80
void __fastcall Scaleform::GFx::Stream::Initialize(Scaleform::GFx::Stream *this, Scaleform::File *pinput, Scaleform::Log *plog, Scaleform::GFx::ParseControl *pparseControl)
{
  Scaleform::GFx::ParseControl *v4; // rsi
  Scaleform::Log *v5; // rbp
  Scaleform::File *v6; // rdi
  Scaleform::GFx::Stream *v7; // rbx
  Scaleform::Render::RenderBuffer *v8; // rcx
  unsigned int v9; // eax
  const char *v10; // rax

  v4 = pparseControl;
  v5 = plog;
  v6 = pinput;
  v7 = this;
  if ( pinput )
    Scaleform::Render::RenderBuffer::AddRef((Scaleform::GFx::Resource *)pinput);
  v8 = (Scaleform::Render::RenderBuffer *)v7->pInput.pObject;
  if ( v8 )
    Scaleform::RefCountImpl::Release(v8);
  v7->pInput.pObject = v6;
  v7->pLog = v5;
  v7->pParseControl = v4;
  if ( v4 )
    v9 = v4->ParseFlags;
  else
    v9 = 0;
  v7->ParseFlags = v9;
  *(_WORD *)&v7->CurrentByte = 0;
  if ( v6 )
  {
    v10 = (const char *)((__int64 (__fastcall *)(Scaleform::File *))v6->vfptr[1].__vecDelDtor)(v6);
    Scaleform::String::operator=((Scaleform::String *)&v7->FileName.0, v10);
  }
  else
  {
    Scaleform::String::Clear((Scaleform::String *)&v7->FileName.0);
  }
  *(_QWORD *)&v7->TagStack[1] = 0i64;
  v7->TagStack[0] = 0;
  *(_QWORD *)&v7->Pos = 0i64;
  v7->ResyncFile = 0;
  if ( v6 )
    v7->FilePos = ((__int64 (__fastcall *)(Scaleform::File *))v6->vfptr[4].__vecDelDtor)(v6);
  else
    v7->FilePos = 0;
}

// File Line: 103
// RVA: 0x8FDDF0
__int64 __fastcall Scaleform::GFx::Stream::ReadUInt(Scaleform::GFx::Stream *this, unsigned int bitcount)
{
  unsigned int v2; // esi
  signed int v3; // edi
  Scaleform::GFx::Stream *v4; // rbx
  unsigned __int8 v5; // al
  int v6; // ecx
  int v7; // eax
  unsigned int v8; // eax
  __int64 v9; // rdx
  char v10; // cl
  __int64 result; // rax
  char v12; // r8
  char v13; // r9
  unsigned int v14; // eax

  v2 = 0;
  v3 = bitcount;
  v4 = this;
  if ( (signed int)bitcount <= 0 )
    return 0i64;
  while ( 1 )
  {
    v5 = v4->UnusedBits;
    if ( !v5 )
    {
      v8 = v4->DataSize;
      v4->UnusedBits = 0;
      if ( (signed int)(v8 - v4->Pos) < 1 )
        Scaleform::GFx::Stream::PopulateBuffer(v4, 1);
      v9 = v4->Pos;
      v10 = v4->pBuffer[v9];
      v4->UnusedBits = 8;
      v4->Pos = v9 + 1;
      v4->CurrentByte = v10;
      goto LABEL_8;
    }
    v6 = v5;
    if ( v3 < v5 )
      break;
    v7 = (unsigned __int8)v4->CurrentByte;
    v3 -= v6;
    v4->UnusedBits = 0;
    v2 |= v7 << v3;
LABEL_8:
    if ( v3 <= 0 )
      return v2;
  }
  v12 = v4->CurrentByte;
  v13 = v4->UnusedBits - v3;
  v14 = (unsigned __int8)v4->CurrentByte;
  v4->UnusedBits = v13;
  result = v2 | (v14 >> v13);
  v4->CurrentByte = v12 & ((1 << v13) - 1);
  return result;
}

// File Line: 149
// RVA: 0x8FDC30
__int64 __fastcall Scaleform::GFx::Stream::ReadUInt1(Scaleform::GFx::Stream *this)
{
  char v1; // al
  Scaleform::GFx::Stream *v2; // rbx
  __int64 v3; // rcx
  unsigned int v4; // edx
  __int64 result; // rax
  char v6; // r8
  char v7; // dl
  unsigned int v8; // eax

  v1 = this->UnusedBits;
  v2 = this;
  if ( v1 )
  {
    v6 = this->CurrentByte;
    v7 = v1 - 1;
    v8 = (unsigned __int8)this->CurrentByte;
    this->UnusedBits = v7;
    result = v8 >> v7;
    this->CurrentByte = v6 & ((1 << v7) - 1);
  }
  else
  {
    this->UnusedBits = 0;
    if ( (signed int)(this->DataSize - this->Pos) < 1 )
      Scaleform::GFx::Stream::PopulateBuffer(this, 1);
    v3 = v2->Pos;
    v4 = (unsigned __int8)v2->pBuffer[v3];
    v2->UnusedBits = 7;
    v2->Pos = v3 + 1;
    result = v4 >> 7;
    v2->CurrentByte = v4 & 0x7F;
  }
  return result;
}

// File Line: 192
// RVA: 0x8F0950
bool __fastcall Scaleform::GFx::Stream::PopulateBuffer(Scaleform::GFx::Stream *this, int size)
{
  int v2; // esi
  Scaleform::GFx::Stream *v3; // rdi
  Scaleform::File *v4; // rcx
  unsigned int v5; // eax
  __int64 v6; // rdx
  unsigned int v7; // eax
  Scaleform::File *v8; // rcx
  __int64 v9; // rdx
  unsigned int v10; // ebx
  int v11; // eax
  unsigned int v12; // edx
  int v13; // ecx
  bool result; // al
  unsigned int v15; // eax

  v2 = size;
  v3 = this;
  if ( !this->DataSize )
  {
    v4 = this->pInput.pObject;
    if ( v4 )
    {
      v5 = ((__int64 (*)(void))v4->vfptr[4].__vecDelDtor)();
      v3->ResyncFile = 0;
      v3->FilePos = v5;
    }
  }
  v6 = v3->Pos;
  v7 = v3->DataSize;
  if ( (unsigned int)v6 >= v7 )
  {
    *(_QWORD *)&v3->Pos = 0i64;
  }
  else
  {
    memmove(v3->pBuffer, &v3->pBuffer[v6], v7 - (unsigned int)v6);
    v3->DataSize -= v3->Pos;
    v3->Pos = 0;
  }
  v8 = v3->pInput.pObject;
  if ( v8 )
  {
    v9 = v3->DataSize;
    v10 = v3->BufferSize - v9;
    v11 = ((__int64 (__fastcall *)(Scaleform::File *, char *, _QWORD))v8->vfptr[10].__vecDelDtor)(
            v8,
            &v3->pBuffer[v9],
            v10);
    if ( v11 >= (signed int)v10 )
    {
      v3->DataSize += v11;
      v3->FilePos += v11;
      result = 1;
    }
    else
    {
      if ( v11 > 0 )
      {
        v3->DataSize += v11;
        v3->FilePos += v11;
      }
      memset(&v3->pBuffer[v3->DataSize], 0, v3->BufferSize - v3->DataSize);
      v12 = v3->Pos;
      v13 = v3->DataSize - v12;
      result = v2 <= v13;
      if ( v13 < v2 )
        v3->DataSize = v12 + v2;
    }
  }
  else
  {
    v3->pBuffer = v3->BuiltinBuffer;
    v3->BufferSize = 512;
    memset(v3->BuiltinBuffer, 0, 0x200ui64);
    v15 = v3->BufferSize;
    v3->Pos = 0;
    v3->FilePos += v15;
    v3->DataSize = v15;
    result = 0;
  }
  return result;
}

// File Line: 287
// RVA: 0x8FD470
__int64 __fastcall Scaleform::GFx::Stream::ReadString(Scaleform::GFx::Stream *this, Scaleform::String *pstr)
{
  Scaleform::String *v2; // r14
  Scaleform::GFx::Stream *v3; // rdi
  unsigned __int64 v4; // rdx
  __int64 v5; // rcx
  char v6; // si
  unsigned __int64 v7; // rbx
  unsigned __int64 v8; // r8
  char *v9; // rcx
  unsigned __int64 v10; // r8
  char *v11; // rcx
  Scaleform::ArrayDataBase<char,Scaleform::AllocatorGH<char,2>,Scaleform::ArrayDefaultPolicy> pheapAddr; // [rsp+28h] [rbp-18h]

  v2 = pstr;
  v3 = this;
  this->UnusedBits = 0;
  pheapAddr.Data = 0i64;
  pheapAddr.Size = 0i64;
  pheapAddr.Policy.Capacity = 0i64;
LABEL_2:
  v4 = pheapAddr.Size;
  while ( 1 )
  {
    v3->UnusedBits = 0;
    if ( (signed int)(v3->DataSize - v3->Pos) < 1 )
    {
      Scaleform::GFx::Stream::PopulateBuffer(v3, 1);
      v4 = pheapAddr.Size;
    }
    v5 = v3->Pos;
    v6 = v3->pBuffer[v5];
    v3->Pos = v5 + 1;
    v7 = v4 + 1;
    if ( !v6 )
      break;
    if ( v7 >= v4 )
    {
      if ( v7 > pheapAddr.Policy.Capacity )
      {
        v8 = v7 + (v7 >> 2);
        goto LABEL_11;
      }
    }
    else if ( v7 < pheapAddr.Policy.Capacity >> 1 )
    {
      v8 = v4 + 1;
LABEL_11:
      Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorGH_POD<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        &pheapAddr,
        &pheapAddr,
        v8);
      goto LABEL_12;
    }
LABEL_12:
    v4 = v7;
    pheapAddr.Size = v7;
    v9 = &pheapAddr.Data[v7 - 1];
    if ( v9 )
    {
      *v9 = v6;
      goto LABEL_2;
    }
  }
  if ( v7 >= v4 )
  {
    if ( v7 > pheapAddr.Policy.Capacity )
    {
      v10 = v7 + (v7 >> 2);
LABEL_19:
      Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorGH_POD<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        &pheapAddr,
        &pheapAddr,
        v10);
    }
  }
  else if ( v7 < pheapAddr.Policy.Capacity >> 1 )
  {
    v10 = v4 + 1;
    goto LABEL_19;
  }
  pheapAddr.Size = v7;
  v11 = &pheapAddr.Data[v7 - 1];
  if ( v11 )
  {
    *v11 = 0;
    v7 = pheapAddr.Size;
  }
  if ( v7 )
  {
    Scaleform::String::AssignString(v2, pheapAddr.Data, v7 - 1);
    LOBYTE(v7) = 1;
  }
  else
  {
    Scaleform::String::Clear(v2);
  }
  if ( pheapAddr.Data )
    ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  return (unsigned __int8)v7;
}

// File Line: 317
// RVA: 0x8E47C0
void __fastcall Scaleform::GFx::Stream::ReadStringWithLength_::_2_::StringReader::InitString(char *pbuffer, unsigned __int64 size, unsigned __int64 a3)
{
  unsigned __int64 v3; // rbp
  unsigned __int64 v4; // r14
  char *v5; // rsi
  unsigned __int64 v6; // rdi
  Scaleform::GFx::Stream *v7; // rbx
  unsigned int v8; // eax
  __int64 v9; // rdx
  char v10; // cl

  if ( a3 )
  {
    v3 = a3;
    v4 = size;
    v5 = pbuffer;
    v6 = 0i64;
    do
    {
      v7 = (Scaleform::GFx::Stream *)*((_QWORD *)v5 + 1);
      v8 = v7->DataSize;
      v7->UnusedBits = 0;
      if ( (signed int)(v8 - v7->Pos) < 1 )
        Scaleform::GFx::Stream::PopulateBuffer(v7, 1);
      v9 = v7->Pos;
      ++v6;
      v10 = v7->pBuffer[v9];
      v7->Pos = v9 + 1;
      *(_BYTE *)(v6 + v4 - 1) = v10;
    }
    while ( v6 < v3 );
  }
}

// File Line: 364
// RVA: 0x8FD5F0
char *__fastcall Scaleform::GFx::Stream::ReadStringWithLength(Scaleform::GFx::Stream *this, Scaleform::MemoryHeap *pheap)
{
  Scaleform::MemoryHeap *v2; // rdi
  Scaleform::GFx::Stream *v3; // rbx
  signed int v4; // eax
  __int64 v5; // rdx
  unsigned int v6; // ecx
  __int64 v7; // rbp
  __int64 v9; // rax
  int v10; // er14
  __int64 v11; // rdi
  __int64 v12; // rsi
  unsigned int v13; // ecx
  __int64 v14; // rdx
  char v15; // cl

  v2 = pheap;
  v3 = this;
  v4 = this->DataSize - this->Pos;
  this->UnusedBits = 0;
  if ( v4 < 1 )
    Scaleform::GFx::Stream::PopulateBuffer(this, 1);
  v5 = v3->Pos;
  v6 = (unsigned __int8)v3->pBuffer[v5];
  v3->Pos = v5 + 1;
  v7 = v6;
  if ( (signed int)v6 <= 0 )
    return 0i64;
  v9 = (__int64)v2->vfptr->Alloc(v2, (signed int)(v6 + 1), 0i64);
  v10 = 0;
  v11 = 0i64;
  v12 = v9;
  if ( v7 > 0 )
  {
    v10 = v7;
    do
    {
      v13 = v3->DataSize;
      v3->UnusedBits = 0;
      if ( (signed int)(v13 - v3->Pos) < 1 )
        Scaleform::GFx::Stream::PopulateBuffer(v3, 1);
      v14 = v3->Pos;
      ++v11;
      v15 = v3->pBuffer[v14];
      v3->Pos = v14 + 1;
      *(_BYTE *)(v11 + v12 - 1) = v15;
    }
    while ( v11 < v7 );
  }
  *(_BYTE *)(v10 + v12) = 0;
  return (char *)v12;
}

// File Line: 382
// RVA: 0x8FDA30
__int64 __fastcall Scaleform::GFx::Stream::ReadToBuffer(Scaleform::GFx::Stream *this, char *pdestBuf, unsigned int sz)
{
  unsigned int v3; // esi
  unsigned int v4; // ebp
  char *v5; // r14
  Scaleform::GFx::Stream *v6; // rdi
  unsigned int v7; // eax
  unsigned int v8; // eax
  signed int v9; // eax

  v3 = 0;
  v4 = sz;
  v5 = pdestBuf;
  v6 = this;
  if ( !this->DataSize )
  {
    v7 = ((__int64 (*)(void))this->pInput.pObject->vfptr[4].__vecDelDtor)();
    v6->ResyncFile = 0;
    v6->FilePos = v7;
  }
  v8 = v6->Pos;
  if ( v8 < v6->DataSize )
  {
    v3 = v6->DataSize - v8;
    if ( v4 < v3 )
      v3 = v4;
    memmove(v5, &v6->pBuffer[v8], v3);
    v6->Pos += v3;
    v4 -= v3;
    v5 += v3;
  }
  if ( v6->Pos >= v6->DataSize )
    *(_QWORD *)&v6->Pos = 0i64;
  if ( v4 )
  {
    v9 = ((__int64 (__fastcall *)(Scaleform::File *, char *, _QWORD))v6->pInput.pObject->vfptr[10].__vecDelDtor)(
           v6->pInput.pObject,
           v5,
           v4);
    v6->FilePos += v9;
    v3 += v9;
    if ( v9 < (signed int)v4 )
      memset(&v5[v9], 0, v4 - v9);
  }
  return v3;
}

// File Line: 426
// RVA: 0x909D30
void __fastcall Scaleform::GFx::Stream::SetPosition(Scaleform::GFx::Stream *this, int pos)
{
  int v2; // edi
  Scaleform::GFx::Stream *v3; // rbx
  int v4; // ecx
  unsigned int v5; // eax

  v2 = pos;
  v3 = this;
  this->UnusedBits = 0;
  v4 = this->FilePos;
  v5 = v3->DataSize;
  if ( pos < (signed int)(v4 - v5) || pos >= v4 )
  {
    if ( (v3->ResyncFile || v4 - v5 + v3->Pos != pos)
      && ((signed int (__fastcall *)(Scaleform::File *, _QWORD, _QWORD))v3->pInput.pObject->vfptr[14].__vecDelDtor)(
           v3->pInput.pObject,
           (unsigned int)pos,
           0i64) >= 0 )
    {
      v3->ResyncFile = 0;
      v3->FilePos = v2;
      *(_QWORD *)&v3->Pos = 0i64;
    }
  }
  else
  {
    v3->Pos = pos + v5 - v4;
  }
}

// File Line: 473
// RVA: 0x8EEE10
__int64 __fastcall Scaleform::GFx::Stream::OpenTag(Scaleform::GFx::Stream *this, Scaleform::GFx::TagInfo *pTagInfo)
{
  unsigned int v2; // er8
  Scaleform::GFx::TagInfo *v3; // r14
  unsigned int v4; // esi
  signed int v5; // er8
  Scaleform::GFx::Stream *v6; // rbx
  unsigned int v7; // esi
  __int64 v8; // r9
  char *v9; // rdx
  __int16 v10; // r8
  __int16 v11; // ax
  unsigned __int16 v12; // r8
  int v13; // edi
  unsigned int v14; // ebp
  unsigned int v15; // eax
  __int64 v16; // r8
  __int64 result; // rax

  v2 = this->DataSize;
  v3 = pTagInfo;
  v4 = this->FilePos - v2;
  v5 = v2 - this->Pos;
  v6 = this;
  v7 = this->Pos + v4;
  this->UnusedBits = 0;
  if ( v5 < 2 )
    Scaleform::GFx::Stream::PopulateBuffer(this, 2);
  v8 = v6->Pos;
  v9 = v6->pBuffer;
  v10 = (unsigned __int8)v9[(unsigned int)(v8 + 1)];
  v11 = (unsigned __int8)v9[v8];
  v6->Pos = v8 + 2;
  v12 = v11 | (v10 << 8);
  v13 = v12 & 0x3F;
  v14 = (signed int)v12 >> 6;
  if ( v13 == 63 )
  {
    v15 = v6->DataSize;
    v6->UnusedBits = 0;
    if ( (signed int)(v15 - (v8 + 2)) < 4 )
      Scaleform::GFx::Stream::PopulateBuffer(v6, 4);
    v16 = v6->Pos;
    v13 = (unsigned __int8)v6->pBuffer[v16] | (((unsigned __int8)v6->pBuffer[(unsigned int)(v16 + 1)] | (((unsigned __int8)v6->pBuffer[(unsigned int)(v16 + 2)] | ((unsigned __int8)v6->pBuffer[(unsigned int)(v16 + 3)] << 8)) << 8)) << 8);
    v6->Pos = v16 + 4;
  }
  v3->TagOffset = v7;
  v3->TagType = v14;
  v3->TagLength = v13;
  v3->TagDataOffset = v6->Pos + v6->FilePos - v6->DataSize;
  if ( v6->ParseFlags & 1 )
    Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(
      (Scaleform::GFx::LogBase<Scaleform::GFx::Stream> *)&v6->vfptr,
      "---------------Tag type = %d, Tag length = %d, offset = %d\n");
  result = v14;
  v6->TagStack[v6->TagStackEntryCount++] = v13 + v6->Pos + v6->FilePos - v6->DataSize;
  return result;
}

// File Line: 506
// RVA: 0x8EEF50
__int64 __fastcall Scaleform::GFx::Stream::OpenTag(Scaleform::GFx::Stream *this)
{
  unsigned int v1; // eax
  Scaleform::GFx::Stream *v2; // rbx
  __int64 v3; // r9
  char *v4; // rdx
  __int16 v5; // r8
  __int16 v6; // ax
  unsigned __int16 v7; // r8
  int v8; // edi
  unsigned int v9; // esi
  unsigned int v10; // eax
  __int64 v11; // r8
  __int64 result; // rax

  v1 = this->DataSize;
  v2 = this;
  this->UnusedBits = 0;
  if ( (signed int)(v1 - this->Pos) < 2 )
    Scaleform::GFx::Stream::PopulateBuffer(this, 2);
  v3 = v2->Pos;
  v4 = v2->pBuffer;
  v5 = (unsigned __int8)v4[(unsigned int)(v3 + 1)];
  v6 = (unsigned __int8)v4[v3];
  v2->Pos = v3 + 2;
  v7 = v6 | (v5 << 8);
  v8 = v7 & 0x3F;
  v9 = (signed int)v7 >> 6;
  if ( v8 == 63 )
  {
    v10 = v2->DataSize;
    v2->UnusedBits = 0;
    if ( (signed int)(v10 - (v3 + 2)) < 4 )
      Scaleform::GFx::Stream::PopulateBuffer(v2, 4);
    v11 = v2->Pos;
    v8 = (unsigned __int8)v2->pBuffer[v11] | (((unsigned __int8)v2->pBuffer[(unsigned int)(v11 + 1)] | (((unsigned __int8)v2->pBuffer[(unsigned int)(v11 + 2)] | ((unsigned __int8)v2->pBuffer[(unsigned int)(v11 + 3)] << 8)) << 8)) << 8);
    v2->Pos = v11 + 4;
  }
  if ( v2->ParseFlags & 1 )
    Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(
      (Scaleform::GFx::LogBase<Scaleform::GFx::Stream> *)&v2->vfptr,
      "---------------Tag type = %d, Tag length = %d\n");
  result = v9;
  v2->TagStack[v2->TagStackEntryCount++] = v8 + v2->Pos + v2->FilePos - v2->DataSize;
  return result;
}

// File Line: 552
// RVA: 0x8FC300
void __fastcall Scaleform::GFx::Stream::ReadMatrix(Scaleform::GFx::Stream *this, Scaleform::Render::Matrix2x4<float> *pm)
{
  float *v2; // rbx
  Scaleform::GFx::Stream *v3; // rbp
  unsigned int v4; // eax
  unsigned int v5; // esi
  signed int v6; // eax
  signed int v7; // er15
  signed int v8; // eax
  unsigned int v9; // eax
  unsigned int v10; // esi
  signed int v11; // eax
  signed int v12; // er15
  signed int v13; // eax
  signed int v14; // eax
  unsigned int v15; // esi
  signed int v16; // eax
  signed int v17; // er14
  signed int v18; // eax

  this->UnusedBits = 0;
  v2 = (float *)pm;
  v3 = this;
  *(_QWORD *)&pm->M[0][2] = 0i64;
  pm->M[1][0] = 0.0;
  pm->M[1][3] = 0.0;
  *(_QWORD *)&pm->M[0][0] = 1065353216i64;
  *(_QWORD *)&pm->M[1][1] = 1065353216i64;
  if ( Scaleform::GFx::Stream::ReadUInt1(this) )
  {
    v4 = Scaleform::GFx::Stream::ReadUInt(v3, 5u);
    v5 = v4;
    v6 = Scaleform::GFx::Stream::ReadUInt(v3, v4);
    v7 = 1 << (v5 - 1);
    if ( v7 & v6 )
      v6 |= -1 << v5;
    *v2 = (float)v6 * 0.000015258789;
    v8 = Scaleform::GFx::Stream::ReadUInt(v3, v5);
    if ( v7 & v8 )
      v8 |= -1 << v5;
    v2[5] = (float)v8 * 0.000015258789;
  }
  if ( Scaleform::GFx::Stream::ReadUInt1(v3) )
  {
    v9 = Scaleform::GFx::Stream::ReadUInt(v3, 5u);
    v10 = v9;
    v11 = Scaleform::GFx::Stream::ReadUInt(v3, v9);
    v12 = 1 << (v10 - 1);
    if ( v12 & v11 )
      v11 |= -1 << v10;
    v2[4] = (float)v11 * 0.000015258789;
    v13 = Scaleform::GFx::Stream::ReadUInt(v3, v10);
    if ( v12 & v13 )
      v13 |= -1 << v10;
    v2[1] = (float)v13 * 0.000015258789;
  }
  v14 = Scaleform::GFx::Stream::ReadUInt(v3, 5u);
  v15 = v14;
  if ( v14 > 0 )
  {
    v16 = Scaleform::GFx::Stream::ReadUInt(v3, v14);
    v17 = 1 << (v15 - 1);
    if ( v17 & v16 )
      v16 |= -1 << v15;
    v2[3] = (float)v16;
    v18 = Scaleform::GFx::Stream::ReadUInt(v3, v15);
    if ( v17 & v18 )
      v18 |= -1 << v15;
    v2[7] = (float)v18;
  }
}

// File Line: 614
// RVA: 0x8FAFD0
void __fastcall Scaleform::GFx::Stream::ReadCxformRgba(Scaleform::GFx::Stream *this, Scaleform::Render::Cxform *pcxform)
{
  Scaleform::Render::Cxform *v2; // rsi
  Scaleform::GFx::Stream *v3; // r14
  unsigned int v4; // er12
  unsigned int v5; // ebx
  unsigned int v6; // eax
  unsigned int v7; // edi
  signed int v8; // eax
  signed int v9; // ebx
  signed int v10; // eax
  signed int v11; // eax
  signed int v12; // eax
  signed int v13; // eax
  signed int v14; // er15
  signed int v15; // eax
  signed int v16; // eax
  signed int v17; // eax

  v2 = pcxform;
  v3 = this;
  this->UnusedBits = 0;
  v4 = Scaleform::GFx::Stream::ReadUInt1(this);
  v5 = Scaleform::GFx::Stream::ReadUInt1(v3);
  v6 = Scaleform::GFx::Stream::ReadUInt(v3, 4u);
  v7 = v6;
  if ( v5 )
  {
    v8 = Scaleform::GFx::Stream::ReadUInt(v3, v6);
    v9 = 1 << (v7 - 1);
    if ( v9 & v8 )
      v8 |= -1 << v7;
    v2->M[0][0] = (float)v8 * 0.00390625;
    v10 = Scaleform::GFx::Stream::ReadUInt(v3, v7);
    if ( v9 & v10 )
      v10 |= -1 << v7;
    v2->M[0][1] = (float)v10 * 0.00390625;
    v11 = Scaleform::GFx::Stream::ReadUInt(v3, v7);
    if ( v9 & v11 )
      v11 |= -1 << v7;
    v2->M[0][2] = (float)v11 * 0.00390625;
    v12 = Scaleform::GFx::Stream::ReadUInt(v3, v7);
    if ( v9 & v12 )
      v12 |= -1 << v7;
    v2->M[0][3] = (float)v12 * 0.00390625;
  }
  else
  {
    *(_QWORD *)&v2->M[0][0] = 4575657222473777152i64;
    *(_QWORD *)&v2->M[0][2] = 4575657222473777152i64;
  }
  if ( v4 )
  {
    v13 = Scaleform::GFx::Stream::ReadUInt(v3, v7);
    v14 = 1 << (v7 - 1);
    if ( v14 & v13 )
      v13 |= -1 << v7;
    v2->M[1][0] = (float)v13;
    v15 = Scaleform::GFx::Stream::ReadUInt(v3, v7);
    if ( v14 & v15 )
      v15 |= -1 << v7;
    v2->M[1][1] = (float)v15;
    v16 = Scaleform::GFx::Stream::ReadUInt(v3, v7);
    if ( v14 & v16 )
      v16 |= -1 << v7;
    v2->M[1][2] = (float)v16;
    v17 = Scaleform::GFx::Stream::ReadUInt(v3, v7);
    if ( v14 & v17 )
      v17 |= -1 << v7;
    v2->M[1][3] = (float)v17;
  }
  else
  {
    *(_QWORD *)&v2->M[1][0] = 0i64;
    *(_QWORD *)&v2->M[1][2] = 0i64;
  }
  Scaleform::Render::Cxform::Normalize(v2);
}

// File Line: 650
// RVA: 0x8FD2D0
void __fastcall Scaleform::GFx::Stream::ReadRect(Scaleform::GFx::Stream *this, Scaleform::Render::Rect<float> *pr)
{
  Scaleform::Render::Rect<float> *v2; // rsi
  Scaleform::GFx::Stream *v3; // rbp
  unsigned int v4; // eax
  unsigned int v5; // ebx
  signed int v6; // eax
  signed int v7; // er14
  signed int v8; // eax
  signed int v9; // eax
  signed int v10; // eax

  v2 = pr;
  v3 = this;
  this->UnusedBits = 0;
  v4 = Scaleform::GFx::Stream::ReadUInt(this, 5u);
  v5 = v4;
  v6 = Scaleform::GFx::Stream::ReadUInt(v3, v4);
  v7 = 1 << (v5 - 1);
  if ( v7 & v6 )
    v6 |= -1 << v5;
  v2->x1 = (float)v6;
  v8 = Scaleform::GFx::Stream::ReadUInt(v3, v5);
  if ( v7 & v8 )
    v8 |= -1 << v5;
  v2->x2 = (float)v8;
  v9 = Scaleform::GFx::Stream::ReadUInt(v3, v5);
  if ( v7 & v9 )
    v9 |= -1 << v5;
  v2->y1 = (float)v9;
  v10 = Scaleform::GFx::Stream::ReadUInt(v3, v5);
  if ( v7 & v10 )
    v10 |= -1 << v5;
  v2->y2 = (float)v10;
}

// File Line: 669
// RVA: 0x8FD3C0
void __fastcall Scaleform::GFx::Stream::ReadRgb(Scaleform::GFx::Stream *this, Scaleform::Render::Color *pc)
{
  Scaleform::Render::Color *v2; // rdi
  Scaleform::GFx::Stream *v3; // rbx
  signed int v4; // eax
  __int64 v5; // rdx
  char v6; // cl
  int v7; // eax
  __int64 v8; // r8
  char v9; // cl
  int v10; // eax
  __int64 v11; // rdx
  char v12; // cl

  v2 = pc;
  v3 = this;
  v4 = this->DataSize - this->Pos;
  this->UnusedBits = 0;
  if ( v4 < 1 )
    Scaleform::GFx::Stream::PopulateBuffer(this, 1);
  v5 = v3->Pos;
  v6 = v3->pBuffer[v5];
  v3->Pos = v5 + 1;
  v2->Channels.Red = v6;
  v7 = v3->DataSize - v3->Pos;
  v3->UnusedBits = 0;
  if ( v7 < 1 )
    Scaleform::GFx::Stream::PopulateBuffer(v3, 1);
  v8 = v3->Pos;
  v9 = v3->pBuffer[v8];
  v3->Pos = v8 + 1;
  v2->Channels.Green = v9;
  v10 = v3->DataSize - v3->Pos;
  v3->UnusedBits = 0;
  if ( v10 < 1 )
    Scaleform::GFx::Stream::PopulateBuffer(v3, 1);
  v11 = v3->Pos;
  v12 = v3->pBuffer[v11];
  v3->Pos = v11 + 1;
  v2->Channels.Blue = v12;
  v2->Channels.Alpha = -1;
}

// File Line: 685
// RVA: 0x8FE1D0
__int64 __fastcall Scaleform::GFx::Stream::ReadVU32(Scaleform::GFx::Stream *this)
{
  unsigned int v1; // edi
  Scaleform::GFx::Stream *v2; // rbx
  unsigned int v3; // esi
  unsigned int v4; // eax
  __int64 v5; // rcx
  char v6; // r8
  unsigned int v7; // eax

  v1 = 0;
  v2 = this;
  v3 = 0;
  do
  {
    v4 = v2->DataSize;
    v2->UnusedBits = 0;
    if ( (signed int)(v4 - v2->Pos) < 1 )
      Scaleform::GFx::Stream::PopulateBuffer(v2, 1);
    v5 = v2->Pos;
    v6 = v2->pBuffer[v5];
    v7 = v5 + 1;
    LOBYTE(v5) = v3;
    v3 += 7;
    v2->Pos = v7;
    v1 |= (v6 & 0x7F) << v5;
  }
  while ( v3 < 0x20 && v6 < 0 );
  return v1;
}

// File Line: 738
// RVA: 0x8DAD00
Expression::IMemberMap *__fastcall Scaleform::GFx::Stream::GetLog(Expression::IMemberMap *this)
{
  return this->mResourceOwner;
}

// File Line: 746
// RVA: 0x8E7E20
__int64 __fastcall Scaleform::GFx::Stream::IsVerboseParseAction(Scaleform::GFx::Stream *this)
{
  return (this->ParseFlags >> 1) & 1;
}

// File Line: 850
// RVA: 0x8FDED0
__int64 __fastcall Scaleform::GFx::StreamContext::ReadUInt(Scaleform::GFx::StreamContext *this, unsigned int bitcount)
{
  unsigned int v2; // er8
  Scaleform::GFx::StreamContext *v3; // r10
  unsigned int v4; // er11
  int v5; // ebx
  unsigned int v6; // er8
  unsigned __int64 v8; // rdx
  const char *v9; // rcx
  const char *v10; // rcx
  int v11; // er8
  int v12; // eax
  signed int v13; // ecx
  signed __int64 v14; // rax
  const char *v15; // r8
  int v16; // er9
  unsigned int v17; // eax
  int v18; // er8
  int v19; // eax
  unsigned __int64 v20; // rdx
  unsigned __int64 v21; // rcx
  int v22; // ecx

  v2 = this->CurBitIndex;
  v3 = this;
  v4 = v2 + bitcount;
  v5 = (1 << (8 - v2)) - 1;
  if ( !bytesInBits[bitcount] )
    return 0i64;
  if ( bytesInBits[bitcount] != 1 )
  {
    if ( bytesInBits[bitcount] != 2 )
    {
      if ( bytesInBits[bitcount] == 3 )
      {
        v8 = this->CurByteIndex;
        v9 = this->pData;
        if ( v4 <= 0x18 )
        {
          v18 = (unsigned __int8)v9[v8 + 1] | ((unsigned __int8)(v5 & v9[v8]) << 8);
          v19 = (unsigned __int8)v9[v8 + 2];
          v13 = 24;
          v6 = v19 | (v18 << 8);
          v14 = v8 + 2;
          goto LABEL_19;
        }
      }
      else
      {
        if ( bytesInBits[bitcount] != 4 )
        {
          v6 = 0;
LABEL_7:
          ++v3->CurByteIndex;
          v3->CurBitIndex = 0;
          return v6;
        }
        v8 = this->CurByteIndex;
        if ( v4 > 0x20 )
        {
          v15 = this->pData;
          v16 = (unsigned __int8)this->pData[v8 + 3] | (((unsigned __int8)this->pData[v8 + 2] | (((unsigned __int8)this->pData[v8 + 1] | ((unsigned __int8)(v5 & this->pData[v8]) << 8)) << 8)) << 8);
          this->CurByteIndex = v8 + 4;
          v17 = (unsigned __int8)v15[v8 + 4];
          this->CurBitIndex = v4 - 32;
          return (v16 << (v4 - 32)) | (v17 >> (8 - (v4 - 32)));
        }
        v9 = this->pData;
      }
      v10 = &v9[v8];
      v11 = *((unsigned __int8 *)v10 + 2) | ((*((unsigned __int8 *)v10 + 1) | ((unsigned __int8)(v5 & *v10) << 8)) << 8);
      v12 = *((unsigned __int8 *)v10 + 3);
      v13 = 32;
      v6 = v12 | (v11 << 8);
      v14 = v8 + 3;
LABEL_19:
      v3->CurByteIndex = v14;
      goto LABEL_20;
    }
    if ( v4 > 0x10 )
    {
      v20 = this->CurByteIndex;
      v13 = 24;
      v6 = (unsigned __int8)v3->pData[v20 + 2] | (((unsigned __int8)v3->pData[v20 + 1] | ((unsigned __int8)(v5 & v3->pData[v20]) << 8)) << 8);
      v14 = v20 + 2;
      goto LABEL_19;
    }
LABEL_18:
    v21 = this->CurByteIndex;
    v6 = (unsigned __int8)v3->pData[v21 + 1] | ((unsigned __int8)(v5 & v3->pData[v21]) << 8);
    v14 = v21 + 1;
    v13 = 16;
    goto LABEL_19;
  }
  if ( v4 > 8 )
    goto LABEL_18;
  v13 = 8;
  v6 = (unsigned __int8)(v5 & v3->pData[v3->CurByteIndex]);
LABEL_20:
  v22 = v13 - v4;
  if ( !v22 )
    goto LABEL_7;
  v3->CurBitIndex = 8 - v22;
  return v6 >> v22;
}

// File Line: 966
// RVA: 0x8FC4B0
void __fastcall Scaleform::GFx::StreamContext::ReadMatrix(Scaleform::GFx::StreamContext *this, Scaleform::Render::Matrix2x4<float> *pm)
{
  float *v2; // rdi
  Scaleform::GFx::StreamContext *v3; // rbx
  unsigned int v4; // edx
  unsigned __int64 v5; // r9
  int v6; // er8
  unsigned int v7; // eax
  unsigned int v8; // ebp
  signed int v9; // eax
  signed int v10; // er12
  signed int v11; // eax
  unsigned int v12; // edx
  unsigned __int64 v13; // r9
  int v14; // er8
  unsigned int v15; // eax
  unsigned int v16; // ebp
  signed int v17; // eax
  signed int v18; // er15
  signed int v19; // eax
  signed int v20; // eax
  unsigned int v21; // ebp
  signed int v22; // eax
  signed int v23; // er14
  signed int v24; // eax

  v2 = (float *)pm;
  v3 = this;
  if ( this->CurBitIndex )
    ++this->CurByteIndex;
  this->CurBitIndex = 0;
  *(_OWORD *)&pm->M[0][0] = 0x3F800000ui64;
  pm->M[1][0] = 0.0;
  *(_QWORD *)&pm->M[1][1] = 1065353216i64;
  pm->M[1][3] = 0.0;
  v4 = this->CurBitIndex;
  v5 = this->CurByteIndex;
  v6 = (unsigned __int8)this->pData[v5] & (1 << (7 - v4));
  this->CurBitIndex = v4 + 1;
  if ( v4 + 1 >= 8 )
  {
    this->CurBitIndex = 0;
    this->CurByteIndex = v5 + 1;
  }
  if ( v6 )
  {
    v7 = Scaleform::GFx::StreamContext::ReadUInt(this, 5u);
    v8 = v7;
    v9 = Scaleform::GFx::StreamContext::ReadUInt(v3, v7);
    v10 = 1 << (v8 - 1);
    if ( v10 & v9 )
      v9 |= -1 << v8;
    *v2 = (float)v9 * 0.000015258789;
    v11 = Scaleform::GFx::StreamContext::ReadUInt(v3, v8);
    if ( v10 & v11 )
      v11 |= -1 << v8;
    v2[5] = (float)v11 * 0.000015258789;
  }
  v12 = v3->CurBitIndex;
  v13 = v3->CurByteIndex;
  v14 = (unsigned __int8)v3->pData[v13] & (1 << (7 - v12));
  v3->CurBitIndex = v12 + 1;
  if ( v12 + 1 >= 8 )
  {
    v3->CurBitIndex = 0;
    v3->CurByteIndex = v13 + 1;
  }
  if ( v14 )
  {
    v15 = Scaleform::GFx::StreamContext::ReadUInt(v3, 5u);
    v16 = v15;
    v17 = Scaleform::GFx::StreamContext::ReadUInt(v3, v15);
    v18 = 1 << (v16 - 1);
    if ( v18 & v17 )
      v17 |= -1 << v16;
    v2[4] = (float)v17 * 0.000015258789;
    v19 = Scaleform::GFx::StreamContext::ReadUInt(v3, v16);
    if ( v18 & v19 )
      v19 |= -1 << v16;
    v2[1] = (float)v19 * 0.000015258789;
  }
  v20 = Scaleform::GFx::StreamContext::ReadUInt(v3, 5u);
  v21 = v20;
  if ( v20 > 0 )
  {
    v22 = Scaleform::GFx::StreamContext::ReadUInt(v3, v20);
    v23 = 1 << (v21 - 1);
    if ( v23 & v22 )
      v22 |= -1 << v21;
    v2[3] = (float)v22;
    v24 = Scaleform::GFx::StreamContext::ReadUInt(v3, v21);
    if ( v23 & v24 )
      v24 |= -1 << v21;
    v2[7] = (float)v24;
  }
}

// File Line: 994
// RVA: 0x8FAE10
void __fastcall Scaleform::GFx::StreamContext::ReadCxformRgb(Scaleform::GFx::StreamContext *this, Scaleform::Render::Cxform *pcxform)
{
  Scaleform::Render::Cxform *v2; // rdi
  Scaleform::GFx::StreamContext *v3; // r14
  unsigned __int64 v4; // r9
  const char *v5; // r8
  char v6; // al
  char v7; // bl
  BOOL v8; // er12
  unsigned int v9; // eax
  unsigned int v10; // esi
  signed int v11; // eax
  signed int v12; // ebx
  signed int v13; // eax
  signed int v14; // eax
  signed int v15; // eax
  signed int v16; // er15
  signed int v17; // eax
  signed int v18; // eax

  v2 = pcxform;
  v3 = this;
  if ( this->CurBitIndex )
    ++this->CurByteIndex;
  v4 = this->CurByteIndex;
  v5 = this->pData;
  this->CurBitIndex = 0;
  v6 = v5[v4];
  this->CurBitIndex = 1;
  v7 = v5[v4];
  this->CurBitIndex = 2;
  v8 = (unsigned __int8)(v6 & 0x80) != 0;
  v9 = Scaleform::GFx::StreamContext::ReadUInt(this, 4u);
  v10 = v9;
  if ( v7 & 0x40 )
  {
    v11 = Scaleform::GFx::StreamContext::ReadUInt(v3, v9);
    v12 = 1 << (v10 - 1);
    if ( v12 & v11 )
      v11 |= -1 << v10;
    v2->M[0][0] = (float)v11 * 0.00390625;
    v13 = Scaleform::GFx::StreamContext::ReadUInt(v3, v10);
    if ( v12 & v13 )
      v13 |= -1 << v10;
    v2->M[0][1] = (float)v13 * 0.00390625;
    v14 = Scaleform::GFx::StreamContext::ReadUInt(v3, v10);
    if ( v12 & v14 )
      v14 |= -1 << v10;
    v2->M[0][3] = 1.0;
    v2->M[0][2] = (float)v14 * 0.00390625;
  }
  else
  {
    *(_QWORD *)&v2->M[0][0] = 4575657222473777152i64;
    *(_QWORD *)&v2->M[0][2] = 4575657222473777152i64;
  }
  if ( v8 )
  {
    v15 = Scaleform::GFx::StreamContext::ReadUInt(v3, v10);
    v16 = 1 << (v10 - 1);
    if ( v16 & v15 )
      v15 |= -1 << v10;
    v2->M[1][0] = (float)v15;
    v17 = Scaleform::GFx::StreamContext::ReadUInt(v3, v10);
    if ( v16 & v17 )
      v17 |= -1 << v10;
    v2->M[1][1] = (float)v17;
    v18 = Scaleform::GFx::StreamContext::ReadUInt(v3, v10);
    if ( v16 & v18 )
      v18 |= -1 << v10;
    v2->M[1][3] = 1.0;
    v2->M[1][2] = (float)v18;
  }
  else
  {
    *(_QWORD *)&v2->M[1][0] = 0i64;
    *(_QWORD *)&v2->M[1][2] = 0i64;
  }
  Scaleform::Render::Cxform::Normalize(v2);
}

// File Line: 1028
// RVA: 0x8FB1C0
void __fastcall Scaleform::GFx::StreamContext::ReadCxformRgba(Scaleform::GFx::StreamContext *this, Scaleform::Render::Cxform *pcxform)
{
  Scaleform::Render::Cxform *v2; // rsi
  Scaleform::GFx::StreamContext *v3; // r14
  unsigned __int64 v4; // r9
  const char *v5; // r8
  char v6; // al
  char v7; // bl
  BOOL v8; // er12
  unsigned int v9; // eax
  unsigned int v10; // edi
  signed int v11; // eax
  signed int v12; // ebx
  signed int v13; // eax
  signed int v14; // eax
  signed int v15; // eax
  signed int v16; // eax
  signed int v17; // er15
  signed int v18; // eax
  signed int v19; // eax
  signed int v20; // eax

  v2 = pcxform;
  v3 = this;
  if ( this->CurBitIndex )
    ++this->CurByteIndex;
  v4 = this->CurByteIndex;
  v5 = this->pData;
  this->CurBitIndex = 0;
  v6 = v5[v4];
  this->CurBitIndex = 1;
  v7 = v5[v4];
  this->CurBitIndex = 2;
  v8 = (unsigned __int8)(v6 & 0x80) != 0;
  v9 = Scaleform::GFx::StreamContext::ReadUInt(this, 4u);
  v10 = v9;
  if ( v7 & 0x40 )
  {
    v11 = Scaleform::GFx::StreamContext::ReadUInt(v3, v9);
    v12 = 1 << (v10 - 1);
    if ( v12 & v11 )
      v11 |= -1 << v10;
    v2->M[0][0] = (float)v11 * 0.00390625;
    v13 = Scaleform::GFx::StreamContext::ReadUInt(v3, v10);
    if ( v12 & v13 )
      v13 |= -1 << v10;
    v2->M[0][1] = (float)v13 * 0.00390625;
    v14 = Scaleform::GFx::StreamContext::ReadUInt(v3, v10);
    if ( v12 & v14 )
      v14 |= -1 << v10;
    v2->M[0][2] = (float)v14 * 0.00390625;
    v15 = Scaleform::GFx::StreamContext::ReadUInt(v3, v10);
    if ( v12 & v15 )
      v15 |= -1 << v10;
    v2->M[0][3] = (float)v15 * 0.00390625;
  }
  else
  {
    *(_QWORD *)&v2->M[0][0] = 4575657222473777152i64;
    *(_QWORD *)&v2->M[0][2] = 4575657222473777152i64;
  }
  if ( v8 )
  {
    v16 = Scaleform::GFx::StreamContext::ReadUInt(v3, v10);
    v17 = 1 << (v10 - 1);
    if ( v17 & v16 )
      v16 |= -1 << v10;
    v2->M[1][0] = (float)v16;
    v18 = Scaleform::GFx::StreamContext::ReadUInt(v3, v10);
    if ( v17 & v18 )
      v18 |= -1 << v10;
    v2->M[1][1] = (float)v18;
    v19 = Scaleform::GFx::StreamContext::ReadUInt(v3, v10);
    if ( v17 & v19 )
      v19 |= -1 << v10;
    v2->M[1][2] = (float)v19;
    v20 = Scaleform::GFx::StreamContext::ReadUInt(v3, v10);
    if ( v17 & v20 )
      v20 |= -1 << v10;
    v2->M[1][3] = (float)v20;
  }
  else
  {
    *(_QWORD *)&v2->M[1][0] = 0i64;
    *(_QWORD *)&v2->M[1][2] = 0i64;
  }
  Scaleform::Render::Cxform::Normalize(v2);
}

