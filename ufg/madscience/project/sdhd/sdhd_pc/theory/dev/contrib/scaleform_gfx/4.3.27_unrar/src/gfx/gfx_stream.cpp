// File Line: 48
// RVA: 0x89D9B0
void __fastcall Scaleform::GFx::Stream::Stream(
        Scaleform::GFx::Stream *this,
        char *pbuffer,
        unsigned int bufSize,
        Scaleform::MemoryHeap *pheap,
        Scaleform::Log *plog,
        Scaleform::GFx::ParseControl *pparseControl)
{
  Scaleform::Render::RenderBuffer *pObject; // rcx
  unsigned int ParseFlags; // ecx
  unsigned int BufferSize; // eax

  this->vfptr = (Scaleform::GFx::LogBase<Scaleform::GFx::Stream>Vtbl *)&Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::`vftable;
  this->vfptr = (Scaleform::GFx::LogBase<Scaleform::GFx::Stream>Vtbl *)&Scaleform::GFx::Stream::`vftable;
  this->pInput.pObject = 0i64;
  Scaleform::StringDH::StringDH(&this->FileName, pheap);
  this->pBuffer = pbuffer;
  if ( pbuffer )
    this->BufferSize = bufSize;
  else
    this->BufferSize = 0;
  pObject = (Scaleform::Render::RenderBuffer *)this->pInput.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  this->pInput.pObject = 0i64;
  this->pLog = plog;
  this->pParseControl = pparseControl;
  if ( pparseControl )
    ParseFlags = pparseControl->ParseFlags;
  else
    ParseFlags = 0;
  this->ParseFlags = ParseFlags;
  *(_WORD *)&this->CurrentByte = 0;
  Scaleform::String::Clear(&this->FileName);
  *(_QWORD *)&this->TagStack[1] = 0i64;
  this->TagStack[0] = 0;
  this->Pos = 0;
  this->ResyncFile = 0;
  BufferSize = this->BufferSize;
  this->DataSize = BufferSize;
  this->FilePos = BufferSize;
}

// File Line: 62
// RVA: 0x8A7F20
void __fastcall Scaleform::GFx::Stream::~Stream(Scaleform::GFx::Stream *this)
{
  Scaleform::Render::RenderBuffer *pObject; // rcx

  this->vfptr = (Scaleform::GFx::LogBase<Scaleform::GFx::Stream>Vtbl *)&Scaleform::GFx::Stream::`vftable;
  if ( !_InterlockedDecrement((volatile signed __int32 *)((this->FileName.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  pObject = (Scaleform::Render::RenderBuffer *)this->pInput.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  this->vfptr = (Scaleform::GFx::LogBase<Scaleform::GFx::Stream>Vtbl *)&Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::`vftable;
}

// File Line: 66
// RVA: 0x8E5C80
void __fastcall Scaleform::GFx::Stream::Initialize(
        Scaleform::GFx::Stream *this,
        Scaleform::GFx::Resource *pinput,
        Scaleform::Log *plog,
        Scaleform::GFx::ParseControl *pparseControl)
{
  Scaleform::Render::RenderBuffer *pObject; // rcx
  unsigned int ParseFlags; // eax
  const char *v10; // rax

  if ( pinput )
    Scaleform::Render::RenderBuffer::AddRef(pinput);
  pObject = (Scaleform::Render::RenderBuffer *)this->pInput.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  this->pInput.pObject = (Scaleform::File *)pinput;
  this->pLog = plog;
  this->pParseControl = pparseControl;
  if ( pparseControl )
    ParseFlags = pparseControl->ParseFlags;
  else
    ParseFlags = 0;
  this->ParseFlags = ParseFlags;
  *(_WORD *)&this->CurrentByte = 0;
  if ( pinput )
  {
    v10 = (const char *)((__int64 (__fastcall *)(Scaleform::GFx::Resource *))pinput->vfptr->GetKey)(pinput);
    Scaleform::String::operator=(&this->FileName, v10);
  }
  else
  {
    Scaleform::String::Clear(&this->FileName);
  }
  *(_QWORD *)&this->TagStack[1] = 0i64;
  this->TagStack[0] = 0;
  *(_QWORD *)&this->Pos = 0i64;
  this->ResyncFile = 0;
  if ( pinput )
    this->FilePos = ((__int64 (__fastcall *)(Scaleform::GFx::Resource *))pinput->vfptr[1].__vecDelDtor)(pinput);
  else
    this->FilePos = 0;
}

// File Line: 103
// RVA: 0x8FDDF0
__int64 __fastcall Scaleform::GFx::Stream::ReadUInt(Scaleform::GFx::Stream *this, int bitcount)
{
  unsigned int v2; // esi
  int v3; // edi
  unsigned __int8 UnusedBits; // al
  int v6; // ecx
  int v7; // eax
  unsigned int DataSize; // eax
  __int64 Pos; // rdx
  char v10; // cl
  __int64 result; // rax
  unsigned __int8 CurrentByte; // r8
  char v13; // r9

  v2 = 0;
  v3 = bitcount;
  if ( bitcount > 0 )
  {
    while ( 1 )
    {
      UnusedBits = this->UnusedBits;
      if ( UnusedBits )
      {
        v6 = UnusedBits;
        if ( v3 < UnusedBits )
        {
          CurrentByte = this->CurrentByte;
          v13 = this->UnusedBits - v3;
          this->UnusedBits = v13;
          result = v2 | (CurrentByte >> v13);
          this->CurrentByte = CurrentByte & ((1 << v13) - 1);
          return result;
        }
        v7 = (unsigned __int8)this->CurrentByte;
        v3 -= v6;
        this->UnusedBits = 0;
        v2 |= v7 << v3;
      }
      else
      {
        DataSize = this->DataSize;
        this->UnusedBits = 0;
        if ( (int)(DataSize - this->Pos) < 1 )
          Scaleform::GFx::Stream::PopulateBuffer(this, 1);
        Pos = this->Pos;
        v10 = this->pBuffer[Pos];
        this->UnusedBits = 8;
        this->Pos = Pos + 1;
        this->CurrentByte = v10;
      }
      if ( v3 <= 0 )
        return v2;
    }
  }
  return 0i64;
}

// File Line: 149
// RVA: 0x8FDC30
__int64 __fastcall Scaleform::GFx::Stream::ReadUInt1(Scaleform::GFx::Stream *this)
{
  char UnusedBits; // al
  __int64 Pos; // rcx
  unsigned int v4; // edx
  __int64 result; // rax
  unsigned __int8 CurrentByte; // r8
  char v7; // dl

  UnusedBits = this->UnusedBits;
  if ( UnusedBits )
  {
    CurrentByte = this->CurrentByte;
    v7 = UnusedBits - 1;
    this->UnusedBits = UnusedBits - 1;
    result = CurrentByte >> (UnusedBits - 1);
    this->CurrentByte = CurrentByte & ((1 << v7) - 1);
  }
  else
  {
    this->UnusedBits = 0;
    if ( (signed int)(this->DataSize - this->Pos) < 1 )
      Scaleform::GFx::Stream::PopulateBuffer(this, 1);
    Pos = this->Pos;
    v4 = (unsigned __int8)this->pBuffer[Pos];
    this->UnusedBits = 7;
    this->Pos = Pos + 1;
    result = v4 >> 7;
    this->CurrentByte = v4 & 0x7F;
  }
  return result;
}

// File Line: 192
// RVA: 0x8F0950
bool __fastcall Scaleform::GFx::Stream::PopulateBuffer(Scaleform::GFx::Stream *this, int size)
{
  Scaleform::File *pObject; // rcx
  unsigned int v5; // eax
  __int64 Pos; // rdx
  unsigned int DataSize; // eax
  Scaleform::File *v8; // rcx
  __int64 v9; // rdx
  int v10; // ebx
  int v11; // eax
  unsigned int v12; // edx
  int v13; // ecx
  bool result; // al
  unsigned int BufferSize; // eax

  if ( !this->DataSize )
  {
    pObject = this->pInput.pObject;
    if ( pObject )
    {
      v5 = ((__int64 (__fastcall *)(Scaleform::File *))pObject->vfptr[4].__vecDelDtor)(pObject);
      this->ResyncFile = 0;
      this->FilePos = v5;
    }
  }
  Pos = this->Pos;
  DataSize = this->DataSize;
  if ( (unsigned int)Pos >= DataSize )
  {
    *(_QWORD *)&this->Pos = 0i64;
  }
  else
  {
    memmove(this->pBuffer, &this->pBuffer[Pos], DataSize - (unsigned int)Pos);
    this->DataSize -= this->Pos;
    this->Pos = 0;
  }
  v8 = this->pInput.pObject;
  if ( v8 )
  {
    v9 = this->DataSize;
    v10 = this->BufferSize - v9;
    v11 = ((__int64 (__fastcall *)(Scaleform::File *, char *, _QWORD))v8->vfptr[10].__vecDelDtor)(
            v8,
            &this->pBuffer[v9],
            (unsigned int)v10);
    if ( v11 >= v10 )
    {
      this->DataSize += v11;
      this->FilePos += v11;
      return 1;
    }
    else
    {
      if ( v11 > 0 )
      {
        this->DataSize += v11;
        this->FilePos += v11;
      }
      memset(&this->pBuffer[this->DataSize], 0, this->BufferSize - this->DataSize);
      v12 = this->Pos;
      v13 = this->DataSize - v12;
      result = size <= v13;
      if ( v13 < size )
        this->DataSize = v12 + size;
    }
  }
  else
  {
    this->pBuffer = this->BuiltinBuffer;
    this->BufferSize = 512;
    memset(this->BuiltinBuffer, 0, sizeof(this->BuiltinBuffer));
    BufferSize = this->BufferSize;
    this->Pos = 0;
    this->FilePos += BufferSize;
    this->DataSize = BufferSize;
    return 0;
  }
  return result;
}

// File Line: 287
// RVA: 0x8FD470
__int64 __fastcall Scaleform::GFx::Stream::ReadString(Scaleform::GFx::Stream *this, Scaleform::String *pstr)
{
  unsigned __int64 Size; // rdx
  __int64 Pos; // rcx
  char v6; // si
  unsigned __int64 v7; // rbx
  unsigned __int64 v8; // r8
  char *v9; // rcx
  unsigned __int64 v10; // r8
  char *v11; // rcx
  Scaleform::ArrayDataBase<char,Scaleform::AllocatorGH<char,2>,Scaleform::ArrayDefaultPolicy> pheapAddr; // [rsp+28h] [rbp-18h] BYREF

  this->UnusedBits = 0;
  memset(&pheapAddr, 0, sizeof(pheapAddr));
LABEL_2:
  Size = pheapAddr.Size;
  while ( 1 )
  {
    this->UnusedBits = 0;
    if ( (signed int)(this->DataSize - this->Pos) < 1 )
    {
      Scaleform::GFx::Stream::PopulateBuffer(this, 1);
      Size = pheapAddr.Size;
    }
    Pos = this->Pos;
    v6 = this->pBuffer[Pos];
    this->Pos = Pos + 1;
    v7 = Size + 1;
    if ( !v6 )
      break;
    if ( v7 >= Size )
    {
      if ( v7 > pheapAddr.Policy.Capacity )
      {
        v8 = v7 + (v7 >> 2);
        goto LABEL_11;
      }
    }
    else if ( v7 < pheapAddr.Policy.Capacity >> 1 )
    {
      v8 = Size + 1;
LABEL_11:
      Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorGH_POD<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        &pheapAddr,
        &pheapAddr,
        v8);
    }
    Size = v7;
    pheapAddr.Size = v7;
    v9 = &pheapAddr.Data[v7 - 1];
    if ( v9 )
    {
      *v9 = v6;
      goto LABEL_2;
    }
  }
  if ( v7 >= Size )
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
    v10 = Size + 1;
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
    Scaleform::String::AssignString(pstr, pheapAddr.Data, v7 - 1);
    LOBYTE(v7) = 1;
  }
  else
  {
    Scaleform::String::Clear(pstr);
  }
  if ( pheapAddr.Data )
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  return (unsigned __int8)v7;
}

// File Line: 317
// RVA: 0x8E47C0
void __fastcall Scaleform::GFx::Stream::ReadStringWithLength_::_2_::StringReader::InitString(
        char *pbuffer,
        unsigned __int64 size,
        unsigned __int64 a3)
{
  unsigned __int64 i; // rdi
  Scaleform::GFx::Stream *v7; // rbx
  unsigned int DataSize; // eax
  __int64 Pos; // rdx
  char v10; // cl

  if ( a3 )
  {
    for ( i = 0i64; i < a3; *(_BYTE *)(i + size - 1) = v10 )
    {
      v7 = (Scaleform::GFx::Stream *)*((_QWORD *)pbuffer + 1);
      DataSize = v7->DataSize;
      v7->UnusedBits = 0;
      if ( (int)(DataSize - v7->Pos) < 1 )
        Scaleform::GFx::Stream::PopulateBuffer(v7, 1);
      Pos = v7->Pos;
      ++i;
      v10 = v7->pBuffer[Pos];
      v7->Pos = Pos + 1;
    }
  }
}

// File Line: 364
// RVA: 0x8FD5F0
char *__fastcall Scaleform::GFx::Stream::ReadStringWithLength(
        Scaleform::GFx::Stream *this,
        Scaleform::MemoryHeap *pheap)
{
  signed int v4; // eax
  __int64 Pos; // rdx
  int v6; // ecx
  __int64 v7; // rbp
  _BYTE *v9; // rax
  int v10; // r14d
  __int64 v11; // rdi
  _BYTE *v12; // rsi
  unsigned int DataSize; // ecx
  __int64 v14; // rdx
  char v15; // cl

  v4 = this->DataSize - this->Pos;
  this->UnusedBits = 0;
  if ( v4 < 1 )
    Scaleform::GFx::Stream::PopulateBuffer(this, 1);
  Pos = this->Pos;
  v6 = (unsigned __int8)this->pBuffer[Pos];
  this->Pos = Pos + 1;
  v7 = (unsigned int)v6;
  if ( v6 <= 0 )
    return 0i64;
  v9 = pheap->vfptr->Alloc(pheap, v6 + 1, 0i64);
  v10 = 0;
  v11 = 0i64;
  v12 = v9;
  if ( v7 > 0 )
  {
    v10 = v7;
    do
    {
      DataSize = this->DataSize;
      this->UnusedBits = 0;
      if ( (int)(DataSize - this->Pos) < 1 )
        Scaleform::GFx::Stream::PopulateBuffer(this, 1);
      v14 = this->Pos;
      ++v11;
      v15 = this->pBuffer[v14];
      this->Pos = v14 + 1;
      v12[v11 - 1] = v15;
    }
    while ( v11 < v7 );
  }
  v12[v10] = 0;
  return v12;
}

// File Line: 382
// RVA: 0x8FDA30
__int64 __fastcall Scaleform::GFx::Stream::ReadToBuffer(Scaleform::GFx::Stream *this, char *pdestBuf, signed int sz)
{
  unsigned int v3; // esi
  unsigned int v7; // eax
  unsigned int Pos; // eax
  signed int v9; // eax

  v3 = 0;
  if ( !this->DataSize )
  {
    v7 = ((__int64 (__fastcall *)(Scaleform::File *))this->pInput.pObject->vfptr[4].__vecDelDtor)(this->pInput.pObject);
    this->ResyncFile = 0;
    this->FilePos = v7;
  }
  Pos = this->Pos;
  if ( Pos < this->DataSize )
  {
    v3 = this->DataSize - Pos;
    if ( sz < v3 )
      v3 = sz;
    memmove(pdestBuf, &this->pBuffer[Pos], v3);
    this->Pos += v3;
    sz -= v3;
    pdestBuf += v3;
  }
  if ( this->Pos >= this->DataSize )
    *(_QWORD *)&this->Pos = 0i64;
  if ( sz )
  {
    v9 = ((__int64 (__fastcall *)(Scaleform::File *, char *, _QWORD))this->pInput.pObject->vfptr[10].__vecDelDtor)(
           this->pInput.pObject,
           pdestBuf,
           (unsigned int)sz);
    this->FilePos += v9;
    v3 += v9;
    if ( v9 < sz )
      memset(&pdestBuf[v9], 0, (unsigned int)(sz - v9));
  }
  return v3;
}

// File Line: 426
// RVA: 0x909D30
void __fastcall Scaleform::GFx::Stream::SetPosition(Scaleform::GFx::Stream *this, int pos)
{
  signed int FilePos; // ecx
  unsigned int DataSize; // eax

  this->UnusedBits = 0;
  FilePos = this->FilePos;
  DataSize = this->DataSize;
  if ( pos < (int)(FilePos - DataSize) || pos >= FilePos )
  {
    if ( (this->ResyncFile || FilePos - DataSize + this->Pos != pos)
      && ((int (__fastcall *)(Scaleform::File *, _QWORD, _QWORD))this->pInput.pObject->vfptr[14].__vecDelDtor)(
           this->pInput.pObject,
           (unsigned int)pos,
           0i64) >= 0 )
    {
      this->ResyncFile = 0;
      this->FilePos = pos;
      *(_QWORD *)&this->Pos = 0i64;
    }
  }
  else
  {
    this->Pos = pos + DataSize - FilePos;
  }
}

// File Line: 473
// RVA: 0x8EEE10
__int64 __fastcall Scaleform::GFx::Stream::OpenTag(Scaleform::GFx::Stream *this, Scaleform::GFx::TagInfo *pTagInfo)
{
  unsigned int DataSize; // r8d
  unsigned int v4; // esi
  int v5; // r8d
  int v7; // esi
  __int64 Pos; // r9
  char *pBuffer; // rdx
  __int16 v10; // r8
  __int16 v11; // ax
  unsigned __int16 v12; // r8
  int v13; // edi
  unsigned int v14; // ebp
  unsigned int v15; // eax
  __int64 v16; // r8
  __int64 result; // rax

  DataSize = this->DataSize;
  v4 = this->FilePos - DataSize;
  v5 = DataSize - this->Pos;
  v7 = this->Pos + v4;
  this->UnusedBits = 0;
  if ( v5 < 2 )
    Scaleform::GFx::Stream::PopulateBuffer(this, 2);
  Pos = this->Pos;
  pBuffer = this->pBuffer;
  v10 = (unsigned __int8)pBuffer[(unsigned int)(Pos + 1)];
  v11 = (unsigned __int8)pBuffer[Pos];
  this->Pos = Pos + 2;
  v12 = v11 | (v10 << 8);
  v13 = v12 & 0x3F;
  v14 = (int)v12 >> 6;
  if ( v13 == 63 )
  {
    v15 = this->DataSize;
    this->UnusedBits = 0;
    if ( (int)(v15 - (Pos + 2)) < 4 )
      Scaleform::GFx::Stream::PopulateBuffer(this, 4);
    v16 = this->Pos;
    v13 = (unsigned __int8)this->pBuffer[v16] | (((unsigned __int8)this->pBuffer[(unsigned int)(v16 + 1)] | (((unsigned __int8)this->pBuffer[(unsigned int)(v16 + 2)] | ((unsigned __int8)this->pBuffer[(unsigned int)(v16 + 3)] << 8)) << 8)) << 8);
    this->Pos = v16 + 4;
  }
  pTagInfo->TagOffset = v7;
  pTagInfo->TagType = v14;
  pTagInfo->TagLength = v13;
  pTagInfo->TagDataOffset = this->Pos + this->FilePos - this->DataSize;
  if ( (this->ParseFlags & 1) != 0 )
    Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(
      this,
      "---------------Tag type = %d, Tag length = %d, offset = %d\n");
  result = v14;
  this->TagStack[this->TagStackEntryCount++] = v13 + this->Pos + this->FilePos - this->DataSize;
  return result;
}

// File Line: 506
// RVA: 0x8EEF50
__int64 __fastcall Scaleform::GFx::Stream::OpenTag(Scaleform::GFx::Stream *this)
{
  unsigned int DataSize; // eax
  __int64 Pos; // r9
  char *pBuffer; // rdx
  __int16 v5; // r8
  __int16 v6; // ax
  unsigned __int16 v7; // r8
  int v8; // edi
  unsigned int v9; // esi
  unsigned int v10; // eax
  __int64 v11; // r8
  __int64 result; // rax

  DataSize = this->DataSize;
  this->UnusedBits = 0;
  if ( (int)(DataSize - this->Pos) < 2 )
    Scaleform::GFx::Stream::PopulateBuffer(this, 2);
  Pos = this->Pos;
  pBuffer = this->pBuffer;
  v5 = (unsigned __int8)pBuffer[(unsigned int)(Pos + 1)];
  v6 = (unsigned __int8)pBuffer[Pos];
  this->Pos = Pos + 2;
  v7 = v6 | (v5 << 8);
  v8 = v7 & 0x3F;
  v9 = (int)v7 >> 6;
  if ( v8 == 63 )
  {
    v10 = this->DataSize;
    this->UnusedBits = 0;
    if ( (int)(v10 - (Pos + 2)) < 4 )
      Scaleform::GFx::Stream::PopulateBuffer(this, 4);
    v11 = this->Pos;
    v8 = (unsigned __int8)this->pBuffer[v11] | (((unsigned __int8)this->pBuffer[(unsigned int)(v11 + 1)] | (((unsigned __int8)this->pBuffer[(unsigned int)(v11 + 2)] | ((unsigned __int8)this->pBuffer[(unsigned int)(v11 + 3)] << 8)) << 8)) << 8);
    this->Pos = v11 + 4;
  }
  if ( (this->ParseFlags & 1) != 0 )
    Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(
      this,
      "---------------Tag type = %d, Tag length = %d\n");
  result = v9;
  this->TagStack[this->TagStackEntryCount++] = v8 + this->Pos + this->FilePos - this->DataSize;
  return result;
}

// File Line: 552
// RVA: 0x8FC300
void __fastcall Scaleform::GFx::Stream::ReadMatrix(
        Scaleform::GFx::Stream *this,
        Scaleform::Render::Matrix2x4<float> *pm)
{
  unsigned int UInt; // esi
  int v5; // eax
  int v6; // r15d
  int v7; // eax
  unsigned int v8; // esi
  int v9; // eax
  int v10; // r15d
  int v11; // eax
  signed int v12; // eax
  unsigned int v13; // esi
  int v14; // eax
  int v15; // r14d
  int v16; // eax

  this->UnusedBits = 0;
  *(_QWORD *)&pm->M[0][2] = 0i64;
  pm->M[1][0] = 0.0;
  pm->M[1][3] = 0.0;
  *(_QWORD *)&pm->M[0][0] = 1065353216i64;
  *(_QWORD *)&pm->M[1][1] = 1065353216i64;
  if ( Scaleform::GFx::Stream::ReadUInt1(this) )
  {
    UInt = Scaleform::GFx::Stream::ReadUInt(this, 5u);
    v5 = Scaleform::GFx::Stream::ReadUInt(this, UInt);
    v6 = 1 << (UInt - 1);
    if ( (v6 & v5) != 0 )
      v5 |= -1 << UInt;
    pm->M[0][0] = (float)v5 * 0.000015258789;
    v7 = Scaleform::GFx::Stream::ReadUInt(this, UInt);
    if ( (v6 & v7) != 0 )
      v7 |= -1 << UInt;
    pm->M[1][1] = (float)v7 * 0.000015258789;
  }
  if ( Scaleform::GFx::Stream::ReadUInt1(this) )
  {
    v8 = Scaleform::GFx::Stream::ReadUInt(this, 5u);
    v9 = Scaleform::GFx::Stream::ReadUInt(this, v8);
    v10 = 1 << (v8 - 1);
    if ( (v10 & v9) != 0 )
      v9 |= -1 << v8;
    pm->M[1][0] = (float)v9 * 0.000015258789;
    v11 = Scaleform::GFx::Stream::ReadUInt(this, v8);
    if ( (v10 & v11) != 0 )
      v11 |= -1 << v8;
    pm->M[0][1] = (float)v11 * 0.000015258789;
  }
  v12 = Scaleform::GFx::Stream::ReadUInt(this, 5u);
  v13 = v12;
  if ( v12 > 0 )
  {
    v14 = Scaleform::GFx::Stream::ReadUInt(this, v12);
    v15 = 1 << (v13 - 1);
    if ( (v15 & v14) != 0 )
      v14 |= -1 << v13;
    pm->M[0][3] = (float)v14;
    v16 = Scaleform::GFx::Stream::ReadUInt(this, v13);
    if ( (v15 & v16) != 0 )
      v16 |= -1 << v13;
    pm->M[1][3] = (float)v16;
  }
}

// File Line: 614
// RVA: 0x8FAFD0
void __fastcall Scaleform::GFx::Stream::ReadCxformRgba(
        Scaleform::GFx::Stream *this,
        Scaleform::Render::Cxform *pcxform)
{
  unsigned int UInt1; // r12d
  unsigned int v5; // ebx
  unsigned int UInt; // eax
  unsigned int v7; // edi
  int v8; // eax
  int v9; // ebx
  int v10; // eax
  int v11; // eax
  int v12; // eax
  int v13; // eax
  int v14; // r15d
  int v15; // eax
  int v16; // eax
  int v17; // eax

  this->UnusedBits = 0;
  UInt1 = Scaleform::GFx::Stream::ReadUInt1(this);
  v5 = Scaleform::GFx::Stream::ReadUInt1(this);
  UInt = Scaleform::GFx::Stream::ReadUInt(this, 4u);
  v7 = UInt;
  if ( v5 )
  {
    v8 = Scaleform::GFx::Stream::ReadUInt(this, UInt);
    v9 = 1 << (v7 - 1);
    if ( (v9 & v8) != 0 )
      v8 |= -1 << v7;
    pcxform->M[0][0] = (float)v8 * 0.00390625;
    v10 = Scaleform::GFx::Stream::ReadUInt(this, v7);
    if ( (v9 & v10) != 0 )
      v10 |= -1 << v7;
    pcxform->M[0][1] = (float)v10 * 0.00390625;
    v11 = Scaleform::GFx::Stream::ReadUInt(this, v7);
    if ( (v9 & v11) != 0 )
      v11 |= -1 << v7;
    pcxform->M[0][2] = (float)v11 * 0.00390625;
    v12 = Scaleform::GFx::Stream::ReadUInt(this, v7);
    if ( (v9 & v12) != 0 )
      v12 |= -1 << v7;
    pcxform->M[0][3] = (float)v12 * 0.00390625;
  }
  else
  {
    *(_QWORD *)&pcxform->M[0][0] = 0x3F8000003F800000i64;
    *(_QWORD *)&pcxform->M[0][2] = 0x3F8000003F800000i64;
  }
  if ( UInt1 )
  {
    v13 = Scaleform::GFx::Stream::ReadUInt(this, v7);
    v14 = 1 << (v7 - 1);
    if ( (v14 & v13) != 0 )
      v13 |= -1 << v7;
    pcxform->M[1][0] = (float)v13;
    v15 = Scaleform::GFx::Stream::ReadUInt(this, v7);
    if ( (v14 & v15) != 0 )
      v15 |= -1 << v7;
    pcxform->M[1][1] = (float)v15;
    v16 = Scaleform::GFx::Stream::ReadUInt(this, v7);
    if ( (v14 & v16) != 0 )
      v16 |= -1 << v7;
    pcxform->M[1][2] = (float)v16;
    v17 = Scaleform::GFx::Stream::ReadUInt(this, v7);
    if ( (v14 & v17) != 0 )
      v17 |= -1 << v7;
    pcxform->M[1][3] = (float)v17;
  }
  else
  {
    *(_QWORD *)&pcxform->M[1][0] = 0i64;
    *(_QWORD *)&pcxform->M[1][2] = 0i64;
  }
  Scaleform::Render::Cxform::Normalize(pcxform);
}

// File Line: 650
// RVA: 0x8FD2D0
void __fastcall Scaleform::GFx::Stream::ReadRect(Scaleform::GFx::Stream *this, Scaleform::Render::Rect<float> *pr)
{
  unsigned int UInt; // ebx
  int v5; // eax
  int v6; // r14d
  int v7; // eax
  int v8; // eax
  int v9; // eax

  this->UnusedBits = 0;
  UInt = Scaleform::GFx::Stream::ReadUInt(this, 5u);
  v5 = Scaleform::GFx::Stream::ReadUInt(this, UInt);
  v6 = 1 << (UInt - 1);
  if ( (v6 & v5) != 0 )
    v5 |= -1 << UInt;
  pr->x1 = (float)v5;
  v7 = Scaleform::GFx::Stream::ReadUInt(this, UInt);
  if ( (v6 & v7) != 0 )
    v7 |= -1 << UInt;
  pr->x2 = (float)v7;
  v8 = Scaleform::GFx::Stream::ReadUInt(this, UInt);
  if ( (v6 & v8) != 0 )
    v8 |= -1 << UInt;
  pr->y1 = (float)v8;
  v9 = Scaleform::GFx::Stream::ReadUInt(this, UInt);
  if ( (v6 & v9) != 0 )
    v9 |= -1 << UInt;
  pr->y2 = (float)v9;
}

// File Line: 669
// RVA: 0x8FD3C0
void __fastcall Scaleform::GFx::Stream::ReadRgb(Scaleform::GFx::Stream *this, Scaleform::Render::Color *pc)
{
  signed int v4; // eax
  __int64 Pos; // rdx
  char v6; // cl
  signed int v7; // eax
  __int64 v8; // r8
  char v9; // cl
  signed int v10; // eax
  __int64 v11; // rdx
  char v12; // cl

  v4 = this->DataSize - this->Pos;
  this->UnusedBits = 0;
  if ( v4 < 1 )
    Scaleform::GFx::Stream::PopulateBuffer(this, 1);
  Pos = this->Pos;
  v6 = this->pBuffer[Pos];
  this->Pos = Pos + 1;
  pc->Channels.Red = v6;
  v7 = this->DataSize - this->Pos;
  this->UnusedBits = 0;
  if ( v7 < 1 )
    Scaleform::GFx::Stream::PopulateBuffer(this, 1);
  v8 = this->Pos;
  v9 = this->pBuffer[v8];
  this->Pos = v8 + 1;
  pc->Channels.Green = v9;
  v10 = this->DataSize - this->Pos;
  this->UnusedBits = 0;
  if ( v10 < 1 )
    Scaleform::GFx::Stream::PopulateBuffer(this, 1);
  v11 = this->Pos;
  v12 = this->pBuffer[v11];
  this->Pos = v11 + 1;
  pc->Channels.Blue = v12;
  pc->Channels.Alpha = -1;
}

// File Line: 685
// RVA: 0x8FE1D0
__int64 __fastcall Scaleform::GFx::Stream::ReadVU32(Scaleform::GFx::Stream *this)
{
  unsigned int v1; // edi
  unsigned int v3; // esi
  unsigned int DataSize; // eax
  __int64 Pos; // rcx
  char v6; // r8
  unsigned int v7; // eax

  v1 = 0;
  v3 = 0;
  do
  {
    DataSize = this->DataSize;
    this->UnusedBits = 0;
    if ( (int)(DataSize - this->Pos) < 1 )
      Scaleform::GFx::Stream::PopulateBuffer(this, 1);
    Pos = this->Pos;
    v6 = this->pBuffer[Pos];
    v7 = Pos + 1;
    LOBYTE(Pos) = v3;
    v3 += 7;
    this->Pos = v7;
    v1 |= (v6 & 0x7F) << Pos;
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
  unsigned int CurBitIndex; // r8d
  unsigned int v4; // r11d
  int v5; // ebx
  unsigned int v6; // r8d
  unsigned __int64 CurByteIndex; // rdx
  const char *pData; // rcx
  const char *v10; // rcx
  int v11; // r8d
  int v12; // eax
  int v13; // ecx
  unsigned __int64 v14; // rax
  const char *v15; // r8
  int v16; // r9d
  unsigned int v17; // eax
  int v18; // r8d
  int v19; // eax
  unsigned __int64 v20; // rdx
  unsigned __int64 v21; // rcx
  unsigned int v22; // ecx

  CurBitIndex = this->CurBitIndex;
  v4 = CurBitIndex + bitcount;
  v5 = (1 << (8 - CurBitIndex)) - 1;
  if ( !bytesInBits[bitcount] )
    return 0i64;
  if ( bytesInBits[bitcount] != 1 )
  {
    if ( bytesInBits[bitcount] != 2 )
    {
      if ( bytesInBits[bitcount] == 3 )
      {
        CurByteIndex = this->CurByteIndex;
        pData = this->pData;
        if ( v4 <= 0x18 )
        {
          v18 = (unsigned __int8)pData[CurByteIndex + 1] | ((unsigned __int8)(v5 & pData[CurByteIndex]) << 8);
          v19 = (unsigned __int8)pData[CurByteIndex + 2];
          v13 = 24;
          v6 = v19 | (v18 << 8);
          v14 = CurByteIndex + 2;
          goto LABEL_19;
        }
      }
      else
      {
        if ( bytesInBits[bitcount] != 4 )
        {
          v6 = 0;
LABEL_7:
          ++this->CurByteIndex;
          this->CurBitIndex = 0;
          return v6;
        }
        CurByteIndex = this->CurByteIndex;
        if ( v4 > 0x20 )
        {
          v15 = this->pData;
          v16 = (unsigned __int8)this->pData[CurByteIndex + 3] | (((unsigned __int8)this->pData[CurByteIndex + 2] | (((unsigned __int8)this->pData[CurByteIndex + 1] | ((unsigned __int8)(v5 & this->pData[CurByteIndex]) << 8)) << 8)) << 8);
          this->CurByteIndex = CurByteIndex + 4;
          v17 = (unsigned __int8)v15[CurByteIndex + 4];
          this->CurBitIndex = v4 - 32;
          return (v16 << (v4 - 32)) | (v17 >> (8 - (v4 - 32)));
        }
        pData = this->pData;
      }
      v10 = &pData[CurByteIndex];
      v11 = *((unsigned __int8 *)v10 + 2) | ((*((unsigned __int8 *)v10 + 1) | ((unsigned __int8)(v5 & *v10) << 8)) << 8);
      v12 = *((unsigned __int8 *)v10 + 3);
      v13 = 32;
      v6 = v12 | (v11 << 8);
      v14 = CurByteIndex + 3;
LABEL_19:
      this->CurByteIndex = v14;
      goto LABEL_20;
    }
    if ( v4 > 0x10 )
    {
      v20 = this->CurByteIndex;
      v13 = 24;
      v6 = (unsigned __int8)this->pData[v20 + 2] | (((unsigned __int8)this->pData[v20 + 1] | ((unsigned __int8)(v5 & this->pData[v20]) << 8)) << 8);
      v14 = v20 + 2;
      goto LABEL_19;
    }
LABEL_18:
    v21 = this->CurByteIndex;
    v6 = (unsigned __int8)this->pData[v21 + 1] | ((unsigned __int8)(v5 & this->pData[v21]) << 8);
    v14 = v21 + 1;
    v13 = 16;
    goto LABEL_19;
  }
  if ( v4 > 8 )
    goto LABEL_18;
  v13 = 8;
  v6 = (unsigned __int8)(v5 & this->pData[this->CurByteIndex]);
LABEL_20:
  v22 = v13 - v4;
  if ( !v22 )
    goto LABEL_7;
  this->CurBitIndex = 8 - v22;
  return v6 >> v22;
}

// File Line: 966
// RVA: 0x8FC4B0
void __fastcall Scaleform::GFx::StreamContext::ReadMatrix(
        Scaleform::GFx::StreamContext *this,
        Scaleform::Render::Matrix2x4<float> *pm)
{
  unsigned int CurBitIndex; // edx
  unsigned __int64 CurByteIndex; // r9
  int v6; // r8d
  unsigned int UInt; // ebp
  int v8; // eax
  int v9; // r12d
  int v10; // eax
  unsigned int v11; // edx
  unsigned __int64 v12; // r9
  int v13; // r8d
  unsigned int v14; // ebp
  int v15; // eax
  int v16; // r15d
  int v17; // eax
  signed int v18; // eax
  unsigned int v19; // ebp
  int v20; // eax
  int v21; // r14d
  int v22; // eax

  if ( this->CurBitIndex )
    ++this->CurByteIndex;
  this->CurBitIndex = 0;
  *(_OWORD *)&pm->M[0][0] = 0x3F800000ui64;
  pm->M[1][0] = 0.0;
  *(_QWORD *)&pm->M[1][1] = 1065353216i64;
  pm->M[1][3] = 0.0;
  CurBitIndex = this->CurBitIndex;
  CurByteIndex = this->CurByteIndex;
  v6 = (unsigned __int8)this->pData[CurByteIndex] & (1 << (7 - CurBitIndex));
  this->CurBitIndex = CurBitIndex + 1;
  if ( CurBitIndex + 1 >= 8 )
  {
    this->CurBitIndex = 0;
    this->CurByteIndex = CurByteIndex + 1;
  }
  if ( v6 )
  {
    UInt = Scaleform::GFx::StreamContext::ReadUInt(this, 5u);
    v8 = Scaleform::GFx::StreamContext::ReadUInt(this, UInt);
    v9 = 1 << (UInt - 1);
    if ( (v9 & v8) != 0 )
      v8 |= -1 << UInt;
    pm->M[0][0] = (float)v8 * 0.000015258789;
    v10 = Scaleform::GFx::StreamContext::ReadUInt(this, UInt);
    if ( (v9 & v10) != 0 )
      v10 |= -1 << UInt;
    pm->M[1][1] = (float)v10 * 0.000015258789;
  }
  v11 = this->CurBitIndex;
  v12 = this->CurByteIndex;
  v13 = (unsigned __int8)this->pData[v12] & (1 << (7 - v11));
  this->CurBitIndex = v11 + 1;
  if ( v11 + 1 >= 8 )
  {
    this->CurBitIndex = 0;
    this->CurByteIndex = v12 + 1;
  }
  if ( v13 )
  {
    v14 = Scaleform::GFx::StreamContext::ReadUInt(this, 5u);
    v15 = Scaleform::GFx::StreamContext::ReadUInt(this, v14);
    v16 = 1 << (v14 - 1);
    if ( (v16 & v15) != 0 )
      v15 |= -1 << v14;
    pm->M[1][0] = (float)v15 * 0.000015258789;
    v17 = Scaleform::GFx::StreamContext::ReadUInt(this, v14);
    if ( (v16 & v17) != 0 )
      v17 |= -1 << v14;
    pm->M[0][1] = (float)v17 * 0.000015258789;
  }
  v18 = Scaleform::GFx::StreamContext::ReadUInt(this, 5u);
  v19 = v18;
  if ( v18 > 0 )
  {
    v20 = Scaleform::GFx::StreamContext::ReadUInt(this, v18);
    v21 = 1 << (v19 - 1);
    if ( (v21 & v20) != 0 )
      v20 |= -1 << v19;
    pm->M[0][3] = (float)v20;
    v22 = Scaleform::GFx::StreamContext::ReadUInt(this, v19);
    if ( (v21 & v22) != 0 )
      v22 |= -1 << v19;
    pm->M[1][3] = (float)v22;
  }
}

// File Line: 994
// RVA: 0x8FAE10
void __fastcall Scaleform::GFx::StreamContext::ReadCxformRgb(
        Scaleform::GFx::StreamContext *this,
        Scaleform::Render::Cxform *pcxform)
{
  unsigned __int64 CurByteIndex; // r9
  const char *pData; // r8
  char v6; // al
  char v7; // bl
  BOOL v8; // r12d
  unsigned int UInt; // eax
  unsigned int v10; // esi
  int v11; // eax
  int v12; // ebx
  int v13; // eax
  int v14; // eax
  int v15; // eax
  int v16; // r15d
  int v17; // eax
  int v18; // eax

  if ( this->CurBitIndex )
    ++this->CurByteIndex;
  CurByteIndex = this->CurByteIndex;
  pData = this->pData;
  this->CurBitIndex = 0;
  v6 = pData[CurByteIndex];
  this->CurBitIndex = 1;
  v7 = pData[CurByteIndex];
  this->CurBitIndex = 2;
  v8 = (v6 & 0x80) != 0;
  UInt = Scaleform::GFx::StreamContext::ReadUInt(this, 4u);
  v10 = UInt;
  if ( (v7 & 0x40) != 0 )
  {
    v11 = Scaleform::GFx::StreamContext::ReadUInt(this, UInt);
    v12 = 1 << (v10 - 1);
    if ( (v12 & v11) != 0 )
      v11 |= -1 << v10;
    pcxform->M[0][0] = (float)v11 * 0.00390625;
    v13 = Scaleform::GFx::StreamContext::ReadUInt(this, v10);
    if ( (v12 & v13) != 0 )
      v13 |= -1 << v10;
    pcxform->M[0][1] = (float)v13 * 0.00390625;
    v14 = Scaleform::GFx::StreamContext::ReadUInt(this, v10);
    if ( (v12 & v14) != 0 )
      v14 |= -1 << v10;
    pcxform->M[0][3] = 1.0;
    pcxform->M[0][2] = (float)v14 * 0.00390625;
  }
  else
  {
    *(_QWORD *)&pcxform->M[0][0] = 0x3F8000003F800000i64;
    *(_QWORD *)&pcxform->M[0][2] = 0x3F8000003F800000i64;
  }
  if ( v8 )
  {
    v15 = Scaleform::GFx::StreamContext::ReadUInt(this, v10);
    v16 = 1 << (v10 - 1);
    if ( (v16 & v15) != 0 )
      v15 |= -1 << v10;
    pcxform->M[1][0] = (float)v15;
    v17 = Scaleform::GFx::StreamContext::ReadUInt(this, v10);
    if ( (v16 & v17) != 0 )
      v17 |= -1 << v10;
    pcxform->M[1][1] = (float)v17;
    v18 = Scaleform::GFx::StreamContext::ReadUInt(this, v10);
    if ( (v16 & v18) != 0 )
      v18 |= -1 << v10;
    pcxform->M[1][3] = 1.0;
    pcxform->M[1][2] = (float)v18;
  }
  else
  {
    *(_QWORD *)&pcxform->M[1][0] = 0i64;
    *(_QWORD *)&pcxform->M[1][2] = 0i64;
  }
  Scaleform::Render::Cxform::Normalize(pcxform);
}

// File Line: 1028
// RVA: 0x8FB1C0
void __fastcall Scaleform::GFx::StreamContext::ReadCxformRgba(
        Scaleform::GFx::StreamContext *this,
        Scaleform::Render::Cxform *pcxform)
{
  unsigned __int64 CurByteIndex; // r9
  const char *pData; // r8
  char v6; // al
  char v7; // bl
  BOOL v8; // r12d
  unsigned int UInt; // eax
  unsigned int v10; // edi
  int v11; // eax
  int v12; // ebx
  int v13; // eax
  int v14; // eax
  int v15; // eax
  int v16; // eax
  int v17; // r15d
  int v18; // eax
  int v19; // eax
  int v20; // eax

  if ( this->CurBitIndex )
    ++this->CurByteIndex;
  CurByteIndex = this->CurByteIndex;
  pData = this->pData;
  this->CurBitIndex = 0;
  v6 = pData[CurByteIndex];
  this->CurBitIndex = 1;
  v7 = pData[CurByteIndex];
  this->CurBitIndex = 2;
  v8 = (v6 & 0x80) != 0;
  UInt = Scaleform::GFx::StreamContext::ReadUInt(this, 4u);
  v10 = UInt;
  if ( (v7 & 0x40) != 0 )
  {
    v11 = Scaleform::GFx::StreamContext::ReadUInt(this, UInt);
    v12 = 1 << (v10 - 1);
    if ( (v12 & v11) != 0 )
      v11 |= -1 << v10;
    pcxform->M[0][0] = (float)v11 * 0.00390625;
    v13 = Scaleform::GFx::StreamContext::ReadUInt(this, v10);
    if ( (v12 & v13) != 0 )
      v13 |= -1 << v10;
    pcxform->M[0][1] = (float)v13 * 0.00390625;
    v14 = Scaleform::GFx::StreamContext::ReadUInt(this, v10);
    if ( (v12 & v14) != 0 )
      v14 |= -1 << v10;
    pcxform->M[0][2] = (float)v14 * 0.00390625;
    v15 = Scaleform::GFx::StreamContext::ReadUInt(this, v10);
    if ( (v12 & v15) != 0 )
      v15 |= -1 << v10;
    pcxform->M[0][3] = (float)v15 * 0.00390625;
  }
  else
  {
    *(_QWORD *)&pcxform->M[0][0] = 0x3F8000003F800000i64;
    *(_QWORD *)&pcxform->M[0][2] = 0x3F8000003F800000i64;
  }
  if ( v8 )
  {
    v16 = Scaleform::GFx::StreamContext::ReadUInt(this, v10);
    v17 = 1 << (v10 - 1);
    if ( (v17 & v16) != 0 )
      v16 |= -1 << v10;
    pcxform->M[1][0] = (float)v16;
    v18 = Scaleform::GFx::StreamContext::ReadUInt(this, v10);
    if ( (v17 & v18) != 0 )
      v18 |= -1 << v10;
    pcxform->M[1][1] = (float)v18;
    v19 = Scaleform::GFx::StreamContext::ReadUInt(this, v10);
    if ( (v17 & v19) != 0 )
      v19 |= -1 << v10;
    pcxform->M[1][2] = (float)v19;
    v20 = Scaleform::GFx::StreamContext::ReadUInt(this, v10);
    if ( (v17 & v20) != 0 )
      v20 |= -1 << v10;
    pcxform->M[1][3] = (float)v20;
  }
  else
  {
    *(_QWORD *)&pcxform->M[1][0] = 0i64;
    *(_QWORD *)&pcxform->M[1][2] = 0i64;
  }
  Scaleform::Render::Cxform::Normalize(pcxform);
}

