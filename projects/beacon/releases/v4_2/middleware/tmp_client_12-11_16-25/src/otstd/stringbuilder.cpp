// File Line: 16
// RVA: 0xEE6E84
void __fastcall OSuite::ZUtf8Buffer::~ZUtf8Buffer(OSuite::ZStringBuilder *this)
{
  char *m_pList; // rdx
  OSuite::TList<char> *p_m_Chars; // rcx

  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZStringBuilder::`vftable;
  m_pList = this->m_Chars.m_pList;
  p_m_Chars = &this->m_Chars;
  p_m_Chars->OSuite::ZListBase::OSuite::ZObject::vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<unsigned char>::`vftable{for `OSuite::ZListBase};
  p_m_Chars->OSuite::IHashable::vfptr = (OSuite::IHashableVtbl *)&OSuite::TList<char>::`vftable{for `OSuite::IHashable};
  OSuite::ZObject::free(p_m_Chars, m_pList);
}

// File Line: 38
// RVA: 0xEE6EB0
OSuite::ZString *__fastcall OSuite::ZStringBuilder::ToString(OSuite::ZStringBuilder *this, OSuite::ZString *result)
{
  OSuite::ZRedBlackTreeBase *p_m_Chars; // rdi

  p_m_Chars = (OSuite::ZRedBlackTreeBase *)&this->m_Chars;
  if ( OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)&this->m_Chars) )
    OSuite::ZString::ZString(result, p_m_Chars);
  else
    OSuite::ZString::ZString(result, &customCaption);
  return result;
}

// File Line: 60
// RVA: 0xEE77B8
void __fastcall OSuite::ZStringBuilder::Clear(OSuite::ZStringBuilder *this, unsigned __int64 nSize)
{
  OSuite::TList<char> *p_m_Chars; // rbx

  p_m_Chars = &this->m_Chars;
  OSuite::ZObject::free(&this->m_Chars, this->m_Chars.m_pList);
  if ( nSize )
    p_m_Chars->m_pList = (char *)OSuite::ZObject::malloc(p_m_Chars, nSize, 0i64);
  else
    p_m_Chars->m_pList = 0i64;
  p_m_Chars->m_nTop = 0i64;
  p_m_Chars->m_nSize = nSize;
}

// File Line: 66
// RVA: 0xEE77B0
char *__fastcall OSuite::ZStringBuilder::Buffer(OSuite::ZStringBuilder *this)
{
  return this->m_Chars.m_pList;
}

// File Line: 72
// RVA: 0xEE7904
unsigned __int64 __fastcall OSuite::ZStringBuilder::Count(OSuite::ZStringBuilder *this)
{
  return OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)&this->m_Chars);
}

// File Line: 78
// RVA: 0xEE6F7C
void __fastcall OSuite::ZStringBuilder::Append(OSuite::ZStringBuilder *this, OSuite::ZString *sStr)
{
  unsigned __int64 v4; // rsi
  char *v5; // rbx

  v4 = OSuite::ZString::Count(sStr);
  v5 = OSuite::ZString::c_str(sStr);
  OSuite::TList<char>::Grow(&this->m_Chars, v4 + this->m_Chars.m_nTop);
  for ( ; v4; --v4 )
    this->m_Chars.m_pList[this->m_Chars.m_nTop++] = *v5++;
}

// File Line: 85
// RVA: 0xEE7054
void __fastcall OSuite::ZStringBuilder::Append(OSuite::ZStringBuilder *this, char *pszStr, unsigned __int64 nLength)
{
  unsigned __int64 v3; // rsi
  OSuite::TList<char> *p_m_Chars; // rdi
  char v6; // bl

  if ( nLength )
  {
    v3 = nLength;
    p_m_Chars = &this->m_Chars;
    do
    {
      v6 = *pszStr++;
      OSuite::TList<char>::Grow(p_m_Chars, p_m_Chars->m_nTop + 1);
      p_m_Chars->m_pList[p_m_Chars->m_nTop++] = v6;
      --v3;
    }
    while ( v3 );
  }
}

// File Line: 94
// RVA: 0xEE7024
void __fastcall OSuite::ZStringBuilder::Append(OSuite::ZStringBuilder *this, const char *pszStr)
{
  unsigned __int64 v4; // rax

  v4 = strlen(pszStr);
  OSuite::ZStringBuilder::Append(this, pszStr, v4);
}

// File Line: 100
// RVA: 0xEE6FE8
void __fastcall OSuite::ZStringBuilder::Append(OSuite::ZStringBuilder *this, char nChar)
{
  OSuite::TList<char> *p_m_Chars; // rbx

  p_m_Chars = &this->m_Chars;
  OSuite::TList<char>::Grow(&this->m_Chars, this->m_Chars.m_nTop + 1);
  p_m_Chars->m_pList[p_m_Chars->m_nTop++] = nChar;
}

// File Line: 106
// RVA: 0xEE76E4
void __fastcall OSuite::ZStringBuilder::AppendUtf8(
        OSuite::ZStringBuilder *this,
        char *pszUtf8,
        unsigned __int64 nLength)
{
  int State; // eax
  int v7; // eax
  OSuite::ZString sEncoding; // [rsp+20h] [rbp-58h] BYREF
  OSuite::ZTextDecoder v9; // [rsp+38h] [rbp-40h] BYREF

  v9.m_pFeeder = 0i64;
  v9.m_sEncoding.m_pString = 0i64;
  OSuite::ZString::ZString(&sEncoding, "UTF-8");
  OSuite::ZTextDecoder::ZTextDecoder(&v9, &sEncoding);
  OSuite::ZString::~ZString(&sEncoding);
  while ( nLength )
  {
    --nLength;
    State = OSuitePrivate::ZEidosTransaction::GetState((OSuite::Statistics *)&v9);
    if ( State != -1 )
      OSuite::ZStringBuilder::Append(this, State);
    OSuite::ZTextDecoder::Feed(&v9, *pszUtf8++);
  }
  v7 = OSuitePrivate::ZEidosTransaction::GetState((OSuite::Statistics *)&v9);
  if ( v7 != -1 )
    OSuite::ZStringBuilder::Append(this, v7);
  OSuite::ZTextDecoder::~ZTextDecoder(&v9);
}

// File Line: 133
// RVA: 0xEE7638
void __fastcall OSuite::ZStringBuilder::AppendInt(OSuite::ZStringBuilder *this, int nInt)
{
  if ( nInt >= 0i64 )
    OSuite::ZStringBuilder::InternalAppendDecimal(this, nInt, 0, 1, 0, 0);
  else
    OSuite::ZStringBuilder::InternalAppendDecimal(this, -(__int64)nInt, 0, 1, 0, 45);
}

// File Line: 139
// RVA: 0xEE766C
void __fastcall OSuite::ZStringBuilder::AppendInt(OSuite::ZStringBuilder *this, unsigned int nInt)
{
  OSuite::ZStringBuilder::InternalAppendDecimal(this, nInt, 0, 1, 0, 0);
}

// File Line: 145
// RVA: 0xEE7690
void __fastcall OSuite::ZStringBuilder::AppendInt(OSuite::ZStringBuilder *this, __int64 nInt)
{
  if ( nInt >= 0 )
    OSuite::ZStringBuilder::InternalAppendDecimal(this, nInt, 0, 1, 0, 0);
  else
    OSuite::ZStringBuilder::InternalAppendDecimal(this, -nInt, 0, 1, 0, 45);
}

// File Line: 151
// RVA: 0xEE76C0
void __fastcall OSuite::ZStringBuilder::AppendInt(OSuite::ZStringBuilder *this, unsigned __int64 nInt)
{
  OSuite::ZStringBuilder::InternalAppendDecimal(this, nInt, 0, 1, 0, 0);
}

// File Line: 170
// RVA: 0xEE7A08
void __fastcall OSuite::ZStringBuilder::InternalAppendDecimal(
        OSuite::ZStringBuilder *this,
        unsigned __int64 nInt,
        int nMinCharacters,
        int nMinDigits,
        char cPad,
        char cPositiveChar)
{
  int v10; // eax
  int v11; // ebp
  BOOL v12; // r10d
  __int64 v13; // rsi
  __int64 v14; // rbx

  v10 = OSuite::ZStringBuilder::DecimalLength(this, nInt);
  v11 = v10;
  v12 = cPositiveChar != 0;
  if ( v10 > nMinDigits )
    nMinDigits = v10;
  if ( nMinCharacters > v12 + nMinDigits )
  {
    v13 = (unsigned int)(nMinCharacters - (v12 + nMinDigits));
    do
    {
      OSuite::ZStringBuilder::Append(this, cPad);
      --v13;
    }
    while ( v13 );
  }
  if ( cPositiveChar )
    OSuite::ZStringBuilder::Append(this, cPositiveChar);
  if ( nMinDigits > v11 )
  {
    v14 = (unsigned int)(nMinDigits - v11);
    do
    {
      OSuite::ZStringBuilder::Append(this, 48);
      --v14;
    }
    while ( v14 );
  }
  OSuite::ZStringBuilder::InternalAppendInt(this, nInt, 10, "0123456789");
}

// File Line: 201
// RVA: 0xEE7B98
void __fastcall OSuite::ZStringBuilder::InternalAppendInt(
        OSuite::ZStringBuilder *this,
        unsigned __int64 nInt,
        int nBase,
        const char *pszBase)
{
  unsigned __int64 v4; // rdi

  v4 = nBase;
  if ( nInt >= nBase )
    OSuite::ZStringBuilder::InternalAppendInt(this, nInt / nBase, nBase, pszBase);
  OSuite::ZStringBuilder::Append(this, pszBase[nInt % v4]);
}

// File Line: 212
// RVA: 0xEE7910
__int64 __fastcall OSuite::ZStringBuilder::DecimalLength(OSuite::ZStringBuilder *this, unsigned __int64 nInt)
{
  __int64 v2; // rcx
  unsigned __int64 i; // rdx

  v2 = 19i64;
  for ( i = 1000000000000000000i64; nInt < i; i /= 0xAui64 )
    --v2;
  if ( !v2 )
    return 1i64;
  return v2;
}

// File Line: 227
// RVA: 0xEE7ABC
void __fastcall OSuite::ZStringBuilder::InternalAppendHex(
        OSuite::ZStringBuilder *this,
        unsigned __int64 nInt,
        bool bCaps,
        char *pPrefix,
        int nMinCharacters,
        int nMinDigits,
        char cPad)
{
  int v11; // ebp
  int v12; // edi
  int v13; // ebx
  __int64 v14; // r14
  __int64 v15; // rbx
  const char *v16; // r9

  v11 = OSuite::ZStringBuilder::HexLength(this, nInt);
  if ( pPrefix )
    v12 = strlen(pPrefix);
  else
    v12 = 0;
  v13 = nMinDigits;
  if ( v11 > nMinDigits )
    v13 = v11;
  if ( nMinCharacters > v12 + v13 )
  {
    v14 = (unsigned int)(nMinCharacters - (v12 + v13));
    do
    {
      OSuite::ZStringBuilder::Append(this, cPad);
      --v14;
    }
    while ( v14 );
  }
  if ( v12 )
    OSuite::ZStringBuilder::Append(this, pPrefix, v12);
  if ( v13 > v11 )
  {
    v15 = (unsigned int)(v13 - v11);
    do
    {
      OSuite::ZStringBuilder::Append(this, 48);
      --v15;
    }
    while ( v15 );
  }
  v16 = "0123456789abcdef";
  if ( bCaps )
    v16 = a01234567_0;
  OSuite::ZStringBuilder::InternalAppendInt(this, nInt, 16, v16);
}

// File Line: 264
// RVA: 0xEE79DC
unsigned __int64 __fastcall OSuite::ZStringBuilder::HexLength(OSuite::ZStringBuilder *this, unsigned __int64 nInt)
{
  unsigned __int64 result; // rax
  unsigned __int64 i; // rcx

  result = 16i64;
  for ( i = 0x1000000000000000i64; nInt < i; i >>= 4 )
    --result;
  if ( !result )
    return 1i64;
  return result;
}

// File Line: 278
// RVA: 0xEE71EC
void OSuite::ZStringBuilder::AppendFormat(OSuite::ZStringBuilder *this, const char *pszFormat, ...)
{
  va_list va; // [rsp+40h] [rbp+18h] BYREF

  va_start(va, pszFormat);
  OSuite::ZStringBuilder::AppendFormatList(this, pszFormat, va);
}

// File Line: 337
// RVA: 0xEE70B8
void __fastcall OSuite::ZStringBuilder::AppendBinaryExponential(OSuite::ZStringBuilder *this, long double dValue)
{
  __int64 v3; // rbp
  int v4; // edi
  const char *v5; // rdx
  unsigned __int64 v6; // rsi

  v3 = *(_QWORD *)&dValue & 0xFFFFFFFFFFFFFi64;
  v4 = ((*(_QWORD *)&dValue >> 52) & 0x7FF) - 1023;
  if ( dValue < 0.0 )
    OSuite::ZStringBuilder::Append(this, 45);
  if ( ((*(_QWORD *)&dValue >> 52) & 0x7FF) != 0 )
  {
    if ( ((*(_QWORD *)&dValue >> 52) & 0x7FF) == 2047 )
    {
      if ( !v3 )
      {
        OSuite::ZStringBuilder::Append(this, "inf");
        return;
      }
      v5 = "nan#";
    }
    else
    {
      v5 = "1.";
    }
    OSuite::ZStringBuilder::Append(this, v5);
  }
  else
  {
    OSuite::ZStringBuilder::Append(this, "0.");
    v4 = -1022;
  }
  v6 = 0x8000000000000i64;
  do
  {
    if ( ((v6 | (v6 - 1)) & v3) == 0 )
      break;
    OSuite::ZStringBuilder::Append(this, ((v6 & v3) != 0) + 48);
    v6 >>= 1;
  }
  while ( v6 );
  OSuite::ZStringBuilder::Append(this, 98);
  if ( (v4 & 0xFFFFFBFF) != 0 )
  {
    OSuite::ZStringBuilder::Append(this, "*2");
    if ( v4 != 1 )
    {
      OSuite::ZStringBuilder::Append(this, 94);
      OSuite::ZStringBuilder::AppendInt(this, v4);
    }
  }
}

// File Line: 432
// RVA: 0xEE7210
void __fastcall OSuite::ZStringBuilder::AppendFormatList(
        OSuite::ZStringBuilder *this,
        char *pszFormat,
        char *arguments)
{
  int v6; // ebp
  char v7; // dl
  int v8; // r14d
  char v9; // r9
  char cPositiveChar; // r10
  char cPad; // r11
  int v12; // r8d
  int v13; // r15d
  int v14; // eax
  int v15; // eax
  __int64 v16; // rcx
  long double v17; // xmm1_8
  char *v18; // rbp
  int v19; // ebx
  __int64 v20; // r14
  unsigned __int64 v21; // rax
  int v22; // ebx
  __int64 v23; // r14
  int v24; // r8d
  signed __int64 v25; // rdx
  int v26; // r9d
  int v27; // r8d
  OSuite::ZStringBuilder *v28; // rcx
  unsigned __int64 v29; // rdx
  _DWORD *v30; // rbx
  bool v31; // cl
  int v32; // r8d
  unsigned __int64 v33; // rdx
  const char *v34; // r9
  int v35; // r8d
  int v36; // [rsp+70h] [rbp+8h]

  v6 = OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)&this->m_Chars);
  v36 = v6;
LABEL_38:
  v7 = *pszFormat++;
  while ( v7 )
  {
    if ( v7 != 37 )
      goto LABEL_37;
    v7 = *pszFormat;
    v8 = 0;
    v9 = 0;
    ++pszFormat;
    cPositiveChar = 0;
    cPad = 32;
    v12 = 2;
    v13 = -1;
    while ( *pszFormat )
    {
      if ( v7 != 45 )
      {
        switch ( v7 )
        {
          case +:
            cPositiveChar = 43;
            break;
          case  :
            cPositiveChar = 32;
            break;
          case #:
            v9 = 1;
            break;
          case 0:
            cPad = 48;
            break;
          default:
            goto LABEL_15;
        }
      }
      v7 = *pszFormat++;
    }
LABEL_15:
    if ( v7 == 42 )
    {
      v7 = *pszFormat;
      v8 = *(_DWORD *)arguments;
      arguments += 8;
      ++pszFormat;
    }
    else
    {
      while ( v7 >= 48 && v7 <= 57 )
      {
        v14 = v7;
        v7 = *pszFormat++;
        v8 = v14 + 2 * (5 * v8 - 24);
      }
    }
    if ( v7 == 46 )
    {
      v7 = *pszFormat++;
      if ( v7 == 42 )
      {
        v7 = *pszFormat;
        v13 = *(_DWORD *)arguments;
        arguments += 8;
        ++pszFormat;
      }
      else
      {
        v13 = 0;
        while ( v7 >= 48 && v7 <= 57 )
        {
          v15 = v7;
          v7 = *pszFormat++;
          v13 = v15 + 2 * (5 * v13 - 24);
        }
      }
    }
    switch ( v7 )
    {
      case H:
        v7 = *pszFormat++;
        v12 = 0;
        goto LABEL_36;
      case h:
        v12 = 1;
        break;
      case l:
        v12 = 3;
        break;
      case L:
        v12 = 4;
        break;
      default:
        goto LABEL_36;
    }
    v7 = *pszFormat++;
LABEL_36:
    if ( v7 == 37 )
      goto LABEL_37;
    if ( (unsigned __int8)(v7 - 69) <= 0x22u )
    {
      v16 = 0x700000005i64;
      if ( _bittest64(&v16, (char)(v7 - 69)) )
      {
        v17 = *(double *)arguments;
        arguments += 8;
        OSuite::ZStringBuilder::AppendBinaryExponential(this, v17);
        goto LABEL_38;
      }
    }
    switch ( v7 )
    {
      case c:
        v7 = *arguments;
        arguments += 8;
LABEL_37:
        OSuite::ZStringBuilder::Append(this, v7);
        goto LABEL_38;
      case s:
        v18 = *(char **)arguments;
        arguments += 8;
        if ( v12 <= 1 )
        {
          if ( v18 )
            goto LABEL_51;
          if ( v13 )
          {
            v18 = "(null)";
LABEL_51:
            v19 = OSuite::ZTextDecoder::utf8len(v18);
          }
          else
          {
            v19 = 0;
          }
          if ( v19 < v8 )
          {
            v20 = (unsigned int)(v8 - v19);
            do
            {
              OSuite::ZStringBuilder::Append(this, 32);
              --v20;
            }
            while ( v20 );
          }
          if ( v18 )
          {
            if ( v13 == -1 || v19 <= v13 )
              v13 = v19;
            v21 = OSuite::ZTextDecoder::utf8indexof(v18, v13);
            OSuite::ZStringBuilder::AppendUtf8(this, v18, v21);
          }
LABEL_73:
          v6 = v36;
          goto LABEL_38;
        }
        if ( v18 )
        {
LABEL_64:
          v22 = strlen(v18);
        }
        else
        {
          if ( v13 )
          {
            v18 = "(null)";
            goto LABEL_64;
          }
          v22 = 0;
        }
        if ( v22 < v8 )
        {
          v23 = (unsigned int)(v8 - v22);
          do
          {
            OSuite::ZStringBuilder::Append(this, 32);
            --v23;
          }
          while ( v23 );
        }
        if ( v18 )
        {
          if ( v13 == -1 || v22 <= v13 )
            v13 = v22;
          OSuite::ZStringBuilder::Append(this, v18, v13);
        }
        goto LABEL_73;
      case i:
      case d:
        if ( v13 == -1 )
          v13 = 1;
        arguments += 8;
        if ( v12 )
        {
          v35 = v12 - 1;
          if ( v35 )
          {
            if ( v35 == 3 )
              v25 = *((_QWORD *)arguments - 1);
            else
              v25 = *((int *)arguments - 2);
          }
          else
          {
            v25 = *((__int16 *)arguments - 4);
          }
        }
        else
        {
          v25 = *(arguments - 8);
        }
        v26 = v13;
        v27 = v8;
        v28 = this;
        if ( v25 < 0 )
        {
          OSuite::ZStringBuilder::InternalAppendDecimal(this, -v25, v8, v13, cPad, 45);
          goto LABEL_38;
        }
LABEL_88:
        OSuite::ZStringBuilder::InternalAppendDecimal(v28, v25, v27, v26, cPad, cPositiveChar);
        goto LABEL_38;
      case u:
        if ( v13 == -1 )
          v13 = 1;
        arguments += 8;
        if ( v12 )
        {
          v24 = v12 - 1;
          if ( v24 )
          {
            if ( v24 == 3 )
              v25 = *((_QWORD *)arguments - 1);
            else
              v25 = *((unsigned int *)arguments - 2);
          }
          else
          {
            v25 = *((unsigned __int16 *)arguments - 4);
          }
        }
        else
        {
          v25 = (unsigned __int8)*(arguments - 8);
        }
        v26 = v13;
        v27 = v8;
        v28 = this;
        goto LABEL_88;
    }
    if ( ((v7 - 88) & 0xDF) == 0 )
    {
      if ( v13 == -1 )
        v13 = 1;
      v31 = v7 == 88;
      arguments += 8;
      if ( v12 )
      {
        v32 = v12 - 1;
        if ( v32 )
        {
          if ( v32 == 3 )
            v33 = *((_QWORD *)arguments - 1);
          else
            v33 = *((unsigned int *)arguments - 2);
        }
        else
        {
          v33 = *((unsigned __int16 *)arguments - 4);
        }
      }
      else
      {
        v33 = (unsigned __int8)*(arguments - 8);
      }
      if ( v9 && v33 )
      {
        v34 = "0x";
        if ( v31 )
          v34 = "0X";
      }
      else
      {
        v34 = 0i64;
      }
      OSuite::ZStringBuilder::InternalAppendHex(this, v33, v31, v34, v8, v13, cPad);
      goto LABEL_38;
    }
    if ( v7 == 112 )
    {
      v29 = *(_QWORD *)arguments;
      arguments += 8;
      OSuite::ZStringBuilder::InternalAppendHex(this, v29, 1, 0i64, 0, 1, 0);
      goto LABEL_38;
    }
    if ( v7 == 110 )
    {
      v30 = *(_DWORD **)arguments;
      arguments += 8;
      *v30 = OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)&this->m_Chars) - v6;
      goto LABEL_38;
    }
  }
}

