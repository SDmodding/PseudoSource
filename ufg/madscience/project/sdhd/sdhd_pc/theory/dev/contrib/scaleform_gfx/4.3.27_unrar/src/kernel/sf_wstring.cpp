// File Line: 32
// RVA: 0x94DB50
void __fastcall Scaleform::WStringBuffer::~WStringBuffer(Scaleform::WStringBuffer *this)
{
  if ( this->pText != this->Reserved.pBuffer )
  {
    if ( this->pText )
      ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
  }
}

// File Line: 38
// RVA: 0x9AC7F0
bool __fastcall Scaleform::WStringBuffer::Resize(Scaleform::WStringBuffer *this, unsigned __int64 size)
{
  unsigned __int64 v2; // rdi
  Scaleform::WStringBuffer *v3; // rbx
  wchar_t *v4; // rax
  wchar_t *v5; // rsi
  wchar_t *v6; // rcx

  v2 = size;
  v3 = this;
  if ( size <= this->Length || size < this->Reserved.Size )
  {
    v6 = this->pText;
    if ( v6 )
      v6[size] = 0;
    v3->Length = size;
    LOBYTE(v4) = 1;
  }
  else
  {
    v4 = (wchar_t *)Scaleform::Memory::pGlobalHeap->vfptr->Alloc(Scaleform::Memory::pGlobalHeap, 2 * size + 2, 0i64);
    v5 = v4;
    if ( v4 )
    {
      if ( v3->pText )
        memmove(v4, v3->pText, 2 * v3->Length + 2);
      v5[v2] = 0;
      if ( v3->pText != v3->Reserved.pBuffer && v3->pText )
        ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
      v3->pText = v5;
      v3->Length = v2;
      LOBYTE(v4) = 1;
    }
  }
  return (char)v4;
}

// File Line: 97
// RVA: 0x9B3FD0
void __fastcall Scaleform::WStringBuffer::SetString(Scaleform::WStringBuffer *this, const char *putf8str, unsigned __int64 utf8Sz)
{
  __int64 v3; // rbx
  const char *v4; // rdi
  Scaleform::WStringBuffer *v5; // r14
  unsigned __int64 v6; // rsi

  v3 = utf8Sz;
  v4 = putf8str;
  v5 = this;
  if ( utf8Sz == -1i64 )
  {
    v3 = -1i64;
    do
      ++v3;
    while ( putf8str[v3] );
  }
  v6 = Scaleform::UTF8Util::GetLength(putf8str, v3);
  if ( Scaleform::WStringBuffer::Resize(v5, v6) )
  {
    if ( v3 )
      Scaleform::UTF8Util::DecodeStringSafe(v5->pText, v6 + 1, v4, v3);
  }
}

// File Line: 106
// RVA: 0x9B4050
void __fastcall Scaleform::WStringBuffer::SetString(Scaleform::WStringBuffer *this, const wchar_t *pstr, unsigned __int64 length)
{
  signed __int64 v3; // rbx
  const wchar_t *v4; // rdi
  Scaleform::WStringBuffer *v5; // rsi

  v3 = length;
  v4 = pstr;
  v5 = this;
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
      memmove(v5->pText, v4, 2 * v3 + 2);
  }
}

// File Line: 114
// RVA: 0x9B8680
void __fastcall Scaleform::WStringBuffer::StripTrailingNewLines(Scaleform::WStringBuffer *this)
{
  signed __int64 v1; // rdx
  signed __int64 i; // rdx
  wchar_t *v3; // r8
  wchar_t v4; // ax

  v1 = this->Length;
  if ( v1 > 0 && !this->pText[v1 - 1] )
    --v1;
  for ( i = v1 - 1; i >= 0; *v3 = 0 )
  {
    v3 = &this->pText[i];
    v4 = *v3;
    if ( v4 != 10 && v4 != 13 )
      break;
    --this->Length;
    --i;
  }
}

