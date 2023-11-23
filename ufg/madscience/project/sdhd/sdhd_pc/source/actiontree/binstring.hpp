// File Line: 28
// RVA: 0x269D30
void __fastcall BinString::~BinString(BinString *this)
{
  char *v1; // rcx

  if ( (this->mOffset & 1) != 0 && (this->mOffset & 0xFFFFFFFFFFFFFFFEui64) != 0 )
  {
    v1 = (char *)this + (this->mOffset & 0xFFFFFFFFFFFFFFFEui64);
    if ( v1 != BinString::sEmptyString )
      operator delete[](v1);
  }
}

// File Line: 59
// RVA: 0x272680
void __fastcall BinString::Set(BinString *this, char *new_text)
{
  BOOL v4; // esi
  char *v5; // rcx
  int v6; // eax
  char *v7; // rbx

  v4 = (this->mOffset & 1) == 0;
  if ( (this->mOffset & 1) != 0 && (this->mOffset & 0xFFFFFFFFFFFFFFFEui64) != 0 )
  {
    v5 = (char *)this + (this->mOffset & 0xFFFFFFFFFFFFFFFEui64);
    if ( v5 != BinString::sEmptyString )
      operator delete[](v5);
  }
  if ( new_text && *new_text )
  {
    v6 = UFG::qStringLength(new_text);
    v7 = (char *)UFG::qMalloc((unsigned int)(v6 + 1), "BinString", 0i64);
    UFG::qStringCopy(v7, 0x7FFFFFFF, new_text, -1);
    this->mOffset = v7 - (char *)this;
  }
  else
  {
    this->mOffset = 0i64;
  }
  if ( !v4 )
    this->mOffset |= 1ui64;
}

