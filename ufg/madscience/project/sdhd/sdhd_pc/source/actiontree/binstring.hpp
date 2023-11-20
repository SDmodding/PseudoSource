// File Line: 28
// RVA: 0x269D30
void __fastcall BinString::~BinString(BinString *this)
{
  if ( !(~LOBYTE(this->mOffset) & 1) )
  {
    if ( this->mOffset & 0xFFFFFFFFFFFFFFFEui64 )
      JUMPOUT((char *)this + (this->mOffset & 0xFFFFFFFFFFFFFFFEui64), BinString::sEmptyString, operator delete[]);
  }
}

// File Line: 59
// RVA: 0x272680
void __fastcall BinString::Set(BinString *this, const char *new_text)
{
  const char *v2; // rbp
  BinString *v3; // rdi
  int v4; // esi
  char *v5; // rcx
  int v6; // eax
  char *v7; // rbx

  v2 = new_text;
  v3 = this;
  v4 = ~LOBYTE(this->mOffset) & 1;
  if ( !(~LOBYTE(this->mOffset) & 1) )
  {
    if ( this->mOffset & 0xFFFFFFFFFFFFFFFEui64 )
    {
      v5 = (char *)this + (this->mOffset & 0xFFFFFFFFFFFFFFFEui64);
      if ( v5 != BinString::sEmptyString )
        operator delete[](v5);
    }
  }
  if ( v2 && *v2 )
  {
    v6 = UFG::qStringLength(v2);
    v7 = (char *)UFG::qMalloc((unsigned int)(v6 + 1), "BinString", 0i64);
    UFG::qStringCopy(v7, 0x7FFFFFFF, v2, -1);
    v3->mOffset = v7 - (char *)v3;
  }
  else
  {
    v3->mOffset = 0i64;
  }
  if ( !v4 )
    v3->mOffset |= 1ui64;
}

