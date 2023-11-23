// File Line: 32
// RVA: 0x94DB50
void __fastcall Scaleform::WStringBuffer::~WStringBuffer(Scaleform::WStringBuffer *this)
{
  if ( this->pText != this->Reserved.pBuffer )
  {
    if ( this->pText )
      ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  }
}

// File Line: 38
// RVA: 0x9AC7F0
bool __fastcall Scaleform::WStringBuffer::Resize(Scaleform::WStringBuffer *this, unsigned __int64 size)
{
  wchar_t *v4; // rax
  wchar_t *v5; // rsi
  wchar_t *pText; // rcx

  if ( size <= this->Length || size < this->Reserved.Size )
  {
    pText = this->pText;
    if ( pText )
      pText[size] = 0;
    this->Length = size;
    LOBYTE(v4) = 1;
  }
  else
  {
    v4 = (wchar_t *)Scaleform::Memory::pGlobalHeap->vfptr->Alloc(Scaleform::Memory::pGlobalHeap, 2 * size + 2, 0i64);
    v5 = v4;
    if ( v4 )
    {
      if ( this->pText )
        memmove(v4, this->pText, 2 * this->Length + 2);
      v5[size] = 0;
      if ( this->pText != this->Reserved.pBuffer && this->pText )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      this->pText = v5;
      this->Length = size;
      LOBYTE(v4) = 1;
    }
  }
  return (char)v4;
}

// File Line: 97
// RVA: 0x9B3FD0
void __fastcall Scaleform::WStringBuffer::SetString(Scaleform::WStringBuffer *this, char *putf8str, __int64 utf8Sz)
{
  __int64 v3; // rbx
  __int64 Length; // rsi

  v3 = utf8Sz;
  if ( utf8Sz == -1 )
  {
    v3 = -1i64;
    do
      ++v3;
    while ( putf8str[v3] );
  }
  Length = Scaleform::UTF8Util::GetLength(putf8str, v3);
  if ( Scaleform::WStringBuffer::Resize(this, Length) )
  {
    if ( v3 )
      Scaleform::UTF8Util::DecodeStringSafe(this->pText, Length + 1, putf8str, v3);
  }
}

// File Line: 106
// RVA: 0x9B4050
void __fastcall Scaleform::WStringBuffer::SetString(
        Scaleform::WStringBuffer *this,
        const wchar_t *pstr,
        unsigned __int64 length)
{
  unsigned __int64 v3; // rbx

  v3 = length;
  if ( length == -1i64 )
  {
    v3 = -1i64;
    do
      ++v3;
    while ( pstr[v3] );
  }
  if ( Scaleform::WStringBuffer::Resize(this, v3) )
  {
    if ( v3 )
      memmove(this->pText, pstr, 2 * v3 + 2);
  }
}

// File Line: 114
// RVA: 0x9B8680
void __fastcall Scaleform::WStringBuffer::StripTrailingNewLines(Scaleform::WStringBuffer *this)
{
  signed __int64 Length; // rdx
  __int64 i; // rdx
  wchar_t *v3; // r8

  Length = this->Length;
  if ( Length > 0 && !this->pText[Length - 1] )
    --Length;
  for ( i = Length - 1; i >= 0; *v3 = 0 )
  {
    v3 = &this->pText[i];
    if ( *v3 != 10 && *v3 != 13 )
      break;
    --this->Length;
    --i;
  }
}

