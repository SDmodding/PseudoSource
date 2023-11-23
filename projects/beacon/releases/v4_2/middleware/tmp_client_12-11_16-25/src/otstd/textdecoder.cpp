// File Line: 40
// RVA: 0xEEB56C
__int64 __fastcall OSuite::ZTextDecoder::Z8BitFeeder::Feed(
        OSuite::ZTextDecoder::Z8BitFeeder *this,
        unsigned __int8 nChar)
{
  return (unsigned int)this->m_pTable->convert[nChar];
}

// File Line: 58
// RVA: 0xEEB5A4
__int64 __fastcall OSuite::ZTextDecoder::ZUtf16BigFeeder::Feed(
        OSuite::ZTextDecoder::ZUtf16BigFeeder *this,
        unsigned __int8 nChar)
{
  int m_nChar; // eax

  if ( this->m_nStage )
  {
    m_nChar = this->m_nChar;
    this->m_nStage = 0;
    return nChar | (unsigned int)(m_nChar << 8);
  }
  else
  {
    this->m_nStage = 1;
    this->m_nChar = nChar;
    return 0xFFFFFFFFi64;
  }
}

// File Line: 85
// RVA: 0xEEB5CC
__int64 __fastcall OSuite::ZTextDecoder::ZUtf16LittleFeeder::Feed(
        OSuite::ZTextDecoder::ZUtf16LittleFeeder *this,
        unsigned __int8 nChar)
{
  if ( this->m_nStage )
  {
    this->m_nStage = 0;
    return this->m_nChar | (nChar << 8);
  }
  else
  {
    this->m_nChar = nChar;
    this->m_nStage = 1;
    return 0xFFFFFFFFi64;
  }
}

// File Line: 112
// RVA: 0xEEB5F0
__int64 __fastcall OSuite::ZTextDecoder::ZUtf8Feeder::Feed(
        OSuite::ZTextDecoder::ZUtf8Feeder *this,
        unsigned __int8 nChar)
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
      if ( (nChar & 0x80u) == 0 )
        return nChar;
      if ( (nChar & 0xE0) == 0xC0 )
      {
        this->m_nStage = 1;
        v3 = (nChar & 0x1F) << 6;
      }
      else
      {
        if ( (nChar & 0xF0) != 0xE0 )
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
__int64 __fastcall OSuite::ZTextDecoder::ZUtf8Feeder::utf8indexof(char *pszString, unsigned __int64 nCharacterIndex)
{
  char v2; // r8
  __int64 i; // rdx
  char v4; // al
  char v5; // al

  v2 = *pszString;
  for ( i = 0i64; *pszString; v2 = *pszString )
  {
    ++pszString;
    if ( (v2 & 0x80) != 0 )
    {
      if ( (v2 & 0xE0) == 0xC0 )
      {
        v4 = *pszString++;
        if ( (v4 & 0xC0) != 0x80 )
          return i;
        i += 2i64;
      }
      else if ( (v2 & 0xF0) == 0xE0 )
      {
        if ( (*pszString & 0xC0) != 0x80 )
          return i;
        v5 = pszString[1];
        pszString += 2;
        if ( (v5 & 0xC0) != 0x80 )
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
  OSuite::ZString *p_m_sEncoding; // rsi
  __int64 v5; // rax
  const char ***v6; // rbx
  const char **v7; // rcx
  __int64 v8; // rax
  OSuite::ZString that; // [rsp+20h] [rbp-40h] BYREF
  OSuite::ZString result; // [rsp+38h] [rbp-28h] BYREF

  this->m_nChar = -1;
  p_m_sEncoding = &this->m_sEncoding;
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZTextDecoder::`vftable;
  OSuite::ZString::ZString(&this->m_sEncoding);
  result.m_pString = 0i64;
  OSuite::ZString::ToLower(sEncoding, &result);
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
      this->m_pFeeder = (OSuite::ZTextDecoder::IFeeder *)v5;
      OSuite::ZString::operator=(p_m_sEncoding, &result);
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
        this->m_pFeeder = 0i64;
        goto LABEL_21;
      }
      while ( !OSuite::ZString::operator==(&result, **v6) )
      {
        if ( !*++v6 )
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
  this->m_pFeeder = (OSuite::ZTextDecoder::IFeeder *)v8;
  OSuite::ZString::ZString(&that, "utf-16be");
  OSuite::ZString::operator=(p_m_sEncoding, &that);
  OSuite::ZString::~ZString(&that);
LABEL_21:
  OSuite::ZString::~ZString(&result);
}

// File Line: 295
// RVA: 0xEEB480
void __fastcall OSuite::ZTextDecoder::~ZTextDecoder(OSuite::ZTextDecoder *this)
{
  OSuite::ZTextDecoder::IFeeder *m_pFeeder; // rcx

  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZTextDecoder::`vftable;
  m_pFeeder = this->m_pFeeder;
  if ( m_pFeeder )
    m_pFeeder->vfptr->__vecDelDtor(m_pFeeder, 1u);
  OSuite::ZString::~ZString(&this->m_sEncoding);
}

// File Line: 304
// RVA: 0xEEB57C
void __fastcall OSuite::ZTextDecoder::Feed(OSuite::ZTextDecoder *this, __int64 nChar)
{
  OSuite::ZTextDecoder::IFeeder *m_pFeeder; // rcx
  int v4; // eax

  m_pFeeder = this->m_pFeeder;
  if ( m_pFeeder )
    v4 = m_pFeeder->vfptr->Feed(m_pFeeder, nChar);
  else
    v4 = (unsigned __int8)nChar;
  this->m_nChar = v4;
}

// File Line: 323
// RVA: 0xEEB54C
OSuite::ZString *__fastcall OSuite::ZTextDecoder::Encoding(OSuite::ZTextDecoder *this, OSuite::ZString *result)
{
  OSuite::ZString::ZString(result, &this->m_sEncoding);
  return result;
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
      if ( (v3 & 0x80) == 0 )
        goto LABEL_9;
      if ( (v3 & 0xE0) == 0xC0 )
        break;
      if ( (v3 & 0xF0) == 0xE0 )
      {
        if ( (*v2 & 0xC0) != 0x80 )
          return v1;
        v6 = v2[1];
        v2 += 2;
        v5 = (v6 & 0xC0) == 0x80;
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
    v5 = (v4 & 0xC0) == 0x80;
    goto LABEL_8;
  }
  return v1;
}

// File Line: 335
// RVA: 0xEEB66C
// attributes: thunk
unsigned __int64 __fastcall OSuite::ZTextDecoder::utf8indexof(const char *pszString, unsigned __int64 nCharacterIndex)
{
  return OSuite::ZTextDecoder::ZUtf8Feeder::utf8indexof(pszString, nCharacterIndex);
}

