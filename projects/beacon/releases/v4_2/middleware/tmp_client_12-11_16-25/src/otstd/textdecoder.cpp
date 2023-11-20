// File Line: 40
// RVA: 0xEEB56C
__int64 __fastcall OSuite::ZTextDecoder::Z8BitFeeder::Feed(OSuite::ZTextDecoder::Z8BitFeeder *this, char nChar)
{
  return (unsigned int)this->m_pTable->convert[(unsigned __int8)nChar];
}

// File Line: 58
// RVA: 0xEEB5A4
signed __int64 __fastcall OSuite::ZTextDecoder::ZUtf16BigFeeder::Feed(OSuite::ZTextDecoder::ZUtf16BigFeeder *this, char nChar)
{
  signed __int64 result; // rax
  int v3; // eax

  if ( this->m_nStage )
  {
    v3 = this->m_nChar;
    this->m_nStage = 0;
    result = (unsigned __int8)nChar | (unsigned int)(v3 << 8);
  }
  else
  {
    this->m_nStage = 1;
    this->m_nChar = (unsigned __int8)nChar;
    result = 0xFFFFFFFFi64;
  }
  return result;
}

// File Line: 85
// RVA: 0xEEB5CC
signed __int64 __fastcall OSuite::ZTextDecoder::ZUtf16LittleFeeder::Feed(OSuite::ZTextDecoder::ZUtf16LittleFeeder *this, char nChar)
{
  signed __int64 result; // rax

  if ( this->m_nStage )
  {
    this->m_nStage = 0;
    result = this->m_nChar | ((unsigned int)(unsigned __int8)nChar << 8);
  }
  else
  {
    this->m_nChar = (unsigned __int8)nChar;
    this->m_nStage = 1;
    result = 0xFFFFFFFFi64;
  }
  return result;
}

// File Line: 112
// RVA: 0xEEB5F0
signed __int64 __fastcall OSuite::ZTextDecoder::ZUtf8Feeder::Feed(OSuite::ZTextDecoder::ZUtf8Feeder *this, char nChar)
{
  int v3; // eax

  if ( this->m_nStage != 1 )
  {
    if ( this->m_nStage == 2 )
    {
      this->m_nStage = 3;
      this->m_nChar |= (nChar & 0x3F) << 6;
      return 0xFFFFFFFFi64;
    }
    if ( this->m_nStage != 3 )
    {
      if ( nChar >= 0 )
        return (unsigned __int8)nChar;
      if ( (nChar & 0xE0) == -64 )
      {
        this->m_nStage = 1;
        v3 = (nChar & 0x1F) << 6;
      }
      else
      {
        if ( (nChar & 0xF0) != -32 )
          return 0xFFFFFFFFi64;
        this->m_nStage = 2;
        v3 = (nChar & 0xF) << 12;
      }
      this->m_nChar = v3;
      return 0xFFFFFFFFi64;
    }
  }
  this->m_nStage = 0;
  this->m_nChar |= nChar & 0x3F;
  return (unsigned int)this->m_nChar;
}

// File Line: 199
// RVA: 0xEEB674
__int64 __fastcall OSuite::ZTextDecoder::ZUtf8Feeder::utf8indexof(const char *pszString, unsigned __int64 nCharacterIndex)
{
  char v2; // r8
  __int64 i; // rdx
  char v4; // al
  char v5; // al

  v2 = *pszString;
  for ( i = 0i64; *pszString; v2 = *pszString )
  {
    ++pszString;
    if ( v2 & 0x80 )
    {
      if ( (v2 & 0xE0) == -64 )
      {
        v4 = *pszString++;
        if ( (v4 & 0xC0) != -128 )
          return i;
        i += 2i64;
      }
      else if ( (v2 & 0xF0) == -32 )
      {
        if ( (*pszString & 0xC0) != -128 )
          return i;
        v5 = pszString[1];
        pszString += 2;
        if ( (v5 & 0xC0) != -128 )
          return i;
        i += 3i64;
      }
    }
    else
    {
      ++i;
    }
  }
  return i;
}

// File Line: 255
// RVA: 0xEEB288
void __fastcall OSuite::ZTextDecoder::ZTextDecoder(OSuite::ZTextDecoder *this, OSuite::ZString *sEncoding)
{
  OSuite::ZString *v2; // rsi
  OSuite::ZTextDecoder *v3; // rdi
  OSuite::ZString *v4; // rbx
  __int64 v5; // rax
  const char ***v6; // rbx
  const char **v7; // rcx
  __int64 v8; // rax
  OSuite::ZString that; // [rsp+20h] [rbp-40h]
  OSuite::ZString result; // [rsp+38h] [rbp-28h]

  this->m_nChar = -1;
  v2 = &this->m_sEncoding;
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZTextDecoder::`vftable;
  v3 = this;
  v4 = sEncoding;
  OSuite::ZString::ZString(&this->m_sEncoding);
  result.m_pString = 0i64;
  OSuite::ZString::ToLower(v4, &result);
  if ( OSuite::ZString::operator==(&result, "utf-8") )
  {
    v5 = OSuite::ZObject::operator new(0x18ui64);
    if ( v5 )
    {
      *(_QWORD *)v5 = &OSuite::ZTextDecoder::ZUtf8Feeder::`vftable{for `OSuite::ZTextDecoder::IFeeder};
LABEL_4:
      *(_QWORD *)(v5 + 8) = &OSuite::ZTextDecoder::ZUtf8Feeder::`vftable{for `OSuite::ZObject};
      *(_DWORD *)(v5 + 16) = 0;
LABEL_6:
      v3->m_pFeeder = (OSuite::ZTextDecoder::IFeeder *)v5;
      OSuite::ZString::operator=(v2, &result);
      goto LABEL_21;
    }
    goto LABEL_5;
  }
  if ( !OSuite::ZString::operator==(&result, "utf-16") && !OSuite::ZString::operator==(&result, "utf-16be") )
  {
    if ( OSuite::ZString::operator==(&result, "utf-16le") )
    {
      v5 = OSuite::ZObject::operator new(0x18ui64);
      if ( v5 )
      {
        *(_QWORD *)v5 = &OSuite::ZTextDecoder::ZUtf16LittleFeeder::`vftable{for `OSuite::ZTextDecoder::IFeeder};
        goto LABEL_4;
      }
    }
    else
    {
      v6 = (const char ***)conversiontables;
      if ( !conversiontables[0] )
      {
LABEL_15:
        v3->m_pFeeder = 0i64;
        goto LABEL_21;
      }
      while ( !OSuite::ZString::operator==(&result, **v6) )
      {
        ++v6;
        if ( !*v6 )
          goto LABEL_15;
      }
      v5 = OSuite::ZObject::operator new(0x18ui64);
      if ( v5 )
      {
        *(_QWORD *)(v5 + 16) = 0i64;
        v7 = *v6;
        *(_QWORD *)v5 = &OSuite::ZTextDecoder::Z8BitFeeder::`vftable{for `OSuite::ZTextDecoder::IFeeder};
        *(_QWORD *)(v5 + 16) = v7;
        *(_QWORD *)(v5 + 8) = &OSuite::ZTextDecoder::ZUtf8Feeder::`vftable{for `OSuite::ZObject};
        goto LABEL_6;
      }
    }
LABEL_5:
    v5 = 0i64;
    goto LABEL_6;
  }
  v8 = OSuite::ZObject::operator new(0x18ui64);
  if ( v8 )
  {
    *(_DWORD *)(v8 + 16) = 0;
    *(_QWORD *)v8 = &OSuite::ZTextDecoder::ZUtf16BigFeeder::`vftable{for `OSuite::ZTextDecoder::IFeeder};
    *(_QWORD *)(v8 + 8) = &OSuite::ZTextDecoder::ZUtf8Feeder::`vftable{for `OSuite::ZObject};
  }
  v3->m_pFeeder = (OSuite::ZTextDecoder::IFeeder *)v8;
  OSuite::ZString::ZString(&that, "utf-16be");
  OSuite::ZString::operator=(v2, &that);
  OSuite::ZString::~ZString(&that);
LABEL_21:
  OSuite::ZString::~ZString(&result);
}

// File Line: 295
// RVA: 0xEEB480
void __fastcall OSuite::ZTextDecoder::~ZTextDecoder(OSuite::ZTextDecoder *this)
{
  OSuite::ZTextDecoder *v1; // rbx
  OSuite::ZTextDecoder::IFeeder *v2; // rcx

  v1 = this;
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZTextDecoder::`vftable;
  v2 = this->m_pFeeder;
  if ( v2 )
    v2->vfptr->__vecDelDtor(v2, 1u);
  OSuite::ZString::~ZString(&v1->m_sEncoding);
}

// File Line: 304
// RVA: 0xEEB57C
void __fastcall OSuite::ZTextDecoder::Feed(OSuite::ZTextDecoder *this, __int64 nChar)
{
  OSuite::ZTextDecoder *v2; // rbx
  OSuite::ZTextDecoder::IFeeder *v3; // rcx
  int v4; // eax

  v2 = this;
  v3 = this->m_pFeeder;
  if ( v3 )
    v4 = v3->vfptr->Feed(v3, nChar);
  else
    v4 = (unsigned __int8)nChar;
  v2->m_nChar = v4;
}

// File Line: 323
// RVA: 0xEEB54C
OSuite::ZString *__fastcall OSuite::ZTextDecoder::Encoding(OSuite::ZTextDecoder *this, OSuite::ZString *result)
{
  OSuite::ZString *v2; // rbx

  v2 = result;
  OSuite::ZString::ZString(result, &this->m_sEncoding);
  return v2;
}

// File Line: 329
// RVA: 0xEEB6E4
__int64 __fastcall OSuite::ZTextDecoder::utf8len(const char *pszString)
{
  __int64 v1; // r8
  const char *v2; // rdx
  char v3; // cl
  char v4; // al
  bool v5; // zf
  char v6; // cl

  v1 = 0i64;
  v2 = pszString;
  if ( *pszString )
  {
    while ( 1 )
    {
      v3 = *v2++;
      if ( !(v3 & 0x80) )
        goto LABEL_9;
      if ( (v3 & 0xE0) == -64 )
        break;
      if ( (v3 & 0xF0) == -32 )
      {
        if ( (*v2 & 0xC0) != -128 )
          return v1;
        v6 = v2[1];
        v2 += 2;
        v5 = (v6 & 0xC0) == -128;
LABEL_8:
        if ( !v5 )
          return v1;
LABEL_9:
        ++v1;
      }
      if ( !*v2 )
        return v1;
    }
    v4 = *v2++;
    v5 = (v4 & 0xC0) == -128;
    goto LABEL_8;
  }
  return v1;
}

// File Line: 335
// RVA: 0xEEB66C
unsigned __int64 __fastcall OSuite::ZTextDecoder::utf8indexof(const char *pszString, unsigned __int64 nCharacterIndex)
{
  return OSuite::ZTextDecoder::ZUtf8Feeder::utf8indexof(pszString, nCharacterIndex);
}

