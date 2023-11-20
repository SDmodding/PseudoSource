// File Line: 16
// RVA: 0xEE6E84
void __fastcall OSuite::ZUtf8Buffer::~ZUtf8Buffer(OSuite::ZStringBuilder *this)
{
  char *v1; // rdx
  OSuite::ZObject *v2; // rcx

  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZStringBuilder::`vftable';
  v1 = this->m_Chars.m_pList;
  v2 = (OSuite::ZObject *)&this->m_Chars.vfptr;
  v2->vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<unsigned char>::`vftable'{for `OSuite::ZListBase'};
  v2[3].vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<char>::`vftable'{for `OSuite::IHashable'};
  OSuite::ZObject::free(v2, v1);
}

// File Line: 38
// RVA: 0xEE6EB0
OSuite::ZString *__fastcall OSuite::ZStringBuilder::ToString(OSuite::ZStringBuilder *this, OSuite::ZString *result)
{
  OSuite::TList<char> *v2; // rdi
  OSuite::ZString *v3; // rbx

  v2 = &this->m_Chars;
  v3 = result;
  if ( OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)&this->m_Chars) )
    OSuite::ZString::ZString(v3, v2);
  else
    OSuite::ZString::ZString(v3, &customWorldMapCaption);
  return v3;
}

// File Line: 60
// RVA: 0xEE77B8
void __fastcall OSuite::ZStringBuilder::Clear(OSuite::ZStringBuilder *this, unsigned __int64 nSize)
{
  OSuite::ZObject *v2; // rbx
  unsigned __int64 v3; // rdi

  v2 = (OSuite::ZObject *)&this->m_Chars.vfptr;
  v3 = nSize;
  OSuite::ZObject::free((OSuite::ZObject *)&this->m_Chars.vfptr, this->m_Chars.m_pList);
  if ( v3 )
    v2[4].vfptr = (OSuite::ZObjectVtbl *)OSuite::ZObject::malloc(v2, v3, 0i64);
  else
    v2[4].vfptr = 0i64;
  v2[2].vfptr = 0i64;
  v2[1].vfptr = (OSuite::ZObjectVtbl *)v3;
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
  OSuite::ZStringBuilder *v2; // rdi
  OSuite::ZString *v3; // rbx
  unsigned __int64 v4; // rsi
  char *v5; // rbx

  v2 = this;
  v3 = sStr;
  v4 = OSuite::ZString::Count(sStr);
  v5 = OSuite::ZString::c_str(v3);
  OSuite::TList<char>::Grow(&v2->m_Chars, v4 + v2->m_Chars.m_nTop);
  for ( ; v4; --v4 )
    v2->m_Chars.m_pList[v2->m_Chars.m_nTop++] = *v5++;
}

// File Line: 85
// RVA: 0xEE7054
void __fastcall OSuite::ZStringBuilder::Append(OSuite::ZStringBuilder *this, const char *pszStr, unsigned __int64 nLength)
{
  unsigned __int64 v3; // rsi
  const char *v4; // r14
  OSuite::TList<char> *v5; // rdi
  char v6; // bl

  if ( nLength )
  {
    v3 = nLength;
    v4 = pszStr;
    v5 = &this->m_Chars;
    do
    {
      v6 = *v4++;
      OSuite::TList<char>::Grow(v5, v5->m_nTop + 1);
      v5->m_pList[v5->m_nTop++] = v6;
      --v3;
    }
    while ( v3 );
  }
}

// File Line: 94
// RVA: 0xEE7024
void __fastcall OSuite::ZStringBuilder::Append(OSuite::ZStringBuilder *this, const char *pszStr)
{
  OSuite::ZStringBuilder *v2; // rdi
  const char *v3; // rbx
  unsigned __int64 v4; // rax

  v2 = this;
  v3 = pszStr;
  v4 = strlen(pszStr);
  OSuite::ZStringBuilder::Append(v2, v3, v4);
}

// File Line: 100
// RVA: 0xEE6FE8
void __fastcall OSuite::ZStringBuilder::Append(OSuite::ZStringBuilder *this, char nChar)
{
  OSuite::TList<char> *v2; // rbx
  char v3; // di

  v2 = &this->m_Chars;
  v3 = nChar;
  OSuite::TList<char>::Grow(&this->m_Chars, this->m_Chars.m_nTop + 1);
  v2->m_pList[v2->m_nTop++] = v3;
}

// File Line: 106
// RVA: 0xEE76E4
void __fastcall OSuite::ZStringBuilder::AppendUtf8(OSuite::ZStringBuilder *this, const char *pszUtf8, unsigned __int64 nLength)
{
  char *v3; // rdi
  OSuite::ZStringBuilder *v4; // rsi
  unsigned __int64 v5; // rbx
  int v6; // eax
  int v7; // eax
  OSuite::ZString sEncoding; // [rsp+20h] [rbp-58h]
  OSuite::ZTextDecoder v9; // [rsp+38h] [rbp-40h]

  v9.m_pFeeder = 0i64;
  v9.m_sEncoding.m_pString = 0i64;
  v3 = (char *)pszUtf8;
  v4 = this;
  v5 = nLength;
  OSuite::ZString::ZString(&sEncoding, "UTF-8");
  OSuite::ZTextDecoder::ZTextDecoder(&v9, &sEncoding);
  OSuite::ZString::~ZString(&sEncoding);
  while ( v5 )
  {
    --v5;
    v6 = OSuitePrivate::ZEidosTransaction::GetState((OSuite::Statistics *)&v9);
    if ( v6 != -1 )
      OSuite::ZStringBuilder::Append(v4, v6);
    OSuite::ZTextDecoder::Feed(&v9, *v3++);
  }
  v7 = OSuitePrivate::ZEidosTransaction::GetState((OSuite::Statistics *)&v9);
  if ( v7 != -1 )
    OSuite::ZStringBuilder::Append(v4, v7);
  OSuite::ZTextDecoder::~ZTextDecoder(&v9);
}

// File Line: 133
// RVA: 0xEE7638
void __fastcall OSuite::ZStringBuilder::AppendInt(OSuite::ZStringBuilder *this, __int64 nInt)
{
  nInt = (signed int)nInt;
  if ( (signed __int64)(signed int)nInt >= 0 )
    OSuite::ZStringBuilder::InternalAppendDecimal(this, nInt, 0, 1, 0, 0);
  else
    OSuite::ZStringBuilder::InternalAppendDecimal(this, -nInt, 0, 1, 0, 45);
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
void __fastcall OSuite::ZStringBuilder::InternalAppendDecimal(OSuite::ZStringBuilder *this, unsigned __int64 nInt, int nMinCharacters, int nMinDigits, char cPad, char cPositiveChar)
{
  int v6; // ebx
  int v7; // esi
  unsigned __int64 v8; // r15
  OSuite::ZStringBuilder *v9; // rdi
  int v10; // eax
  int v11; // ebp
  BOOL v12; // er10
  __int64 v13; // rsi
  __int64 v14; // rbx

  v6 = nMinDigits;
  v7 = nMinCharacters;
  v8 = nInt;
  v9 = this;
  v10 = OSuite::ZStringBuilder::DecimalLength(this, nInt);
  v11 = v10;
  v12 = cPositiveChar != 0;
  if ( v10 > v6 )
    v6 = v10;
  if ( v7 > v12 + v6 )
  {
    v13 = (unsigned int)(v7 - (v12 + v6));
    do
    {
      OSuite::ZStringBuilder::Append(v9, cPad);
      --v13;
    }
    while ( v13 );
  }
  if ( cPositiveChar )
    OSuite::ZStringBuilder::Append(v9, cPositiveChar);
  if ( v6 > v11 )
  {
    v14 = (unsigned int)(v6 - v11);
    do
    {
      OSuite::ZStringBuilder::Append(v9, 48);
      --v14;
    }
    while ( v14 );
  }
  OSuite::ZStringBuilder::InternalAppendInt(v9, v8, 10, "0123456789");
}

// File Line: 201
// RVA: 0xEE7B98
void __fastcall OSuite::ZStringBuilder::InternalAppendInt(OSuite::ZStringBuilder *this, unsigned __int64 nInt, int nBase, const char *pszBase)
{
  unsigned __int64 v4; // rdi
  const char *v5; // rsi
  unsigned __int64 v6; // rbx
  OSuite::ZStringBuilder *v7; // rbp

  v4 = nBase;
  v5 = pszBase;
  v6 = nInt;
  v7 = this;
  if ( nInt >= nBase )
    OSuite::ZStringBuilder::InternalAppendInt(this, nInt / nBase, nBase, pszBase);
  OSuite::ZStringBuilder::Append(v7, v5[v6 % v4]);
}

// File Line: 212
// RVA: 0xEE7910
signed __int64 __fastcall OSuite::ZStringBuilder::DecimalLength(OSuite::ZStringBuilder *this, unsigned __int64 nInt)
{
  signed __int64 v2; // rcx
  unsigned __int64 v3; // r8
  unsigned __int64 v4; // rdx

  v2 = 19i64;
  v3 = nInt;
  v4 = 1000000000000000000i64;
  while ( v3 < v4 )
  {
    v4 = (unsigned __int64)(v4 * (unsigned __int128)0xCCCCCCCCCCCCCCCDui64 >> 64) >> 3;
    --v2;
  }
  if ( !v2 )
    v2 = 1i64;
  return v2;
}

// File Line: 227
// RVA: 0xEE7ABC
void __fastcall OSuite::ZStringBuilder::InternalAppendHex(OSuite::ZStringBuilder *this, unsigned __int64 nInt, bool bCaps, const char *pPrefix, int nMinCharacters, int nMinDigits, char cPad)
{
  const char *v7; // r15
  bool v8; // r13
  unsigned __int64 v9; // r12
  OSuite::ZStringBuilder *v10; // rsi
  int v11; // ebp
  int v12; // edi
  int v13; // ebx
  __int64 v14; // r14
  __int64 v15; // rbx
  const char *v16; // r9

  v7 = pPrefix;
  v8 = bCaps;
  v9 = nInt;
  v10 = this;
  v11 = OSuite::ZStringBuilder::HexLength(this, nInt);
  if ( v7 )
    v12 = strlen(v7);
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
      OSuite::ZStringBuilder::Append(v10, cPad);
      --v14;
    }
    while ( v14 );
  }
  if ( v12 )
    OSuite::ZStringBuilder::Append(v10, v7, v12);
  if ( v13 > v11 )
  {
    v15 = (unsigned int)(v13 - v11);
    do
    {
      OSuite::ZStringBuilder::Append(v10, 48);
      --v15;
    }
    while ( v15 );
  }
  v16 = "0123456789abcdef";
  if ( v8 )
    v16 = a01234567_0;
  OSuite::ZStringBuilder::InternalAppendInt(v10, v9, 16, v16);
}

// File Line: 264
// RVA: 0xEE79DC
unsigned __int64 __fastcall OSuite::ZStringBuilder::HexLength(OSuite::ZStringBuilder *this, unsigned __int64 nInt)
{
  unsigned __int64 result; // rax
  unsigned __int64 v3; // rcx

  result = 16i64;
  v3 = 0x1000000000000000i64;
  while ( nInt < v3 )
  {
    v3 >>= 4;
    --result;
  }
  if ( !result )
    result = 1i64;
  return result;
}

// File Line: 278
// RVA: 0xEE71EC
void OSuite::ZStringBuilder::AppendFormat(OSuite::ZStringBuilder *this, const char *pszFormat, ...)
{
  va_list va; // [rsp+40h] [rbp+18h]

  va_start(va, pszFormat);
  OSuite::ZStringBuilder::AppendFormatList(this, pszFormat, va);
}

// File Line: 337
// RVA: 0xEE70B8
void __fastcall OSuite::ZStringBuilder::AppendBinaryExponential(OSuite::ZStringBuilder *this, long double dValue)
{
  OSuite::ZStringBuilder *v2; // rbx
  signed __int64 v3; // rbp
  int v4; // edi
  const char *v5; // rdx
  unsigned __int64 v6; // rsi

  v2 = this;
  v3 = *(_QWORD *)&dValue & 0xFFFFFFFFFFFFFi64;
  v4 = ((*(_QWORD *)&dValue >> 52) & 0x7FF) - 1023;
  if ( dValue < 0.0 )
    OSuite::ZStringBuilder::Append(this, 45);
  if ( v4 == -1023 )
  {
    OSuite::ZStringBuilder::Append(v2, "0.");
    v4 = -1022;
  }
  else
  {
    if ( v4 == 1024 )
    {
      if ( !v3 )
      {
        OSuite::ZStringBuilder::Append(v2, "inf");
        return;
      }
      v5 = "nan#";
    }
    else
    {
      v5 = "1.";
    }
    OSuite::ZStringBuilder::Append(v2, v5);
  }
  v6 = 0x8000000000000i64;
  do
  {
    if ( !((v6 | (v6 - 1)) & v3) )
      break;
    OSuite::ZStringBuilder::Append(v2, ((v6 & v3) != 0) + 48);
    v6 >>= 1;
  }
  while ( v6 );
  OSuite::ZStringBuilder::Append(v2, 98);
  if ( v4 & 0xFFFFFBFF )
  {
    OSuite::ZStringBuilder::Append(v2, "*2");
    if ( v4 != 1 )
    {
      OSuite::ZStringBuilder::Append(v2, 94);
      OSuite::ZStringBuilder::AppendInt(v2, v4);
    }
  }
}

// File Line: 432
// RVA: 0xEE7210
void __fastcall OSuite::ZStringBuilder::AppendFormatList(OSuite::ZStringBuilder *this, const char *pszFormat, char *arguments)
{
  OSuite::ZStringBuilder *v3; // r13
  char *v4; // rdi
  const char *v5; // rsi
  unsigned __int64 v6; // rax
  int v7; // ebp
  char v8; // dl
  int v9; // er14
  char v10; // r9
  char cPositiveChar; // r10
  char cPad; // r11
  signed int v13; // er8
  int v14; // er15
  int v15; // eax
  int v16; // eax
  signed __int64 v17; // rcx
  long double v18; // xmm1_8
  const char *v19; // rbp
  int v20; // ebx
  __int64 v21; // r14
  unsigned __int64 v22; // rax
  int v23; // ebx
  __int64 v24; // r14
  int v25; // er8
  int v26; // er8
  signed __int64 v27; // rdx
  int v28; // er9
  int v29; // er8
  OSuite::ZStringBuilder *v30; // rcx
  unsigned __int64 v31; // rdx
  _DWORD *v32; // rbx
  bool v33; // cl
  int v34; // er8
  int v35; // er8
  unsigned __int64 v36; // rdx
  const char *v37; // r9
  int v38; // er8
  int v39; // er8
  unsigned __int64 v40; // [rsp+70h] [rbp+8h]

  v3 = this;
  v4 = arguments;
  v5 = pszFormat;
  v6 = OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)&this->m_Chars);
  v7 = v6;
  v40 = v6;
LABEL_39:
  v8 = *v5++;
  while ( v8 )
  {
    if ( v8 != 37 )
      goto LABEL_38;
    v8 = *v5;
    v9 = 0;
    v10 = 0;
    ++v5;
    cPositiveChar = 0;
    cPad = 32;
    v13 = 2;
    v14 = -1;
    while ( *v5 )
    {
      if ( v8 != 45 )
      {
        switch ( v8 )
        {
          case 43:
            cPositiveChar = 43;
            break;
          case 32:
            cPositiveChar = 32;
            break;
          case 35:
            v10 = 1;
            break;
          case 48:
            cPad = 48;
            break;
          default:
            goto LABEL_16;
        }
      }
      v8 = *v5++;
    }
LABEL_16:
    if ( v8 == 42 )
    {
      v8 = *v5;
      v9 = *(_DWORD *)v4;
      v4 += 8;
      ++v5;
    }
    else
    {
      while ( v8 >= 48 && v8 <= 57 )
      {
        v15 = v8;
        v8 = *v5++;
        v9 = v15 + 2 * (5 * v9 - 24);
      }
    }
    if ( v8 == 46 )
    {
      v8 = *v5++;
      if ( v8 == 42 )
      {
        v8 = *v5;
        v14 = *(_DWORD *)v4;
        v4 += 8;
        ++v5;
      }
      else
      {
        v14 = 0;
        while ( v8 >= 48 && v8 <= 57 )
        {
          v16 = v8;
          v8 = *v5++;
          v14 = v16 + 2 * (5 * v14 - 24);
        }
      }
    }
    switch ( v8 )
    {
      case 72:
        v8 = *v5++;
        v13 = 0;
        goto LABEL_37;
      case 104:
        v13 = 1;
        break;
      case 108:
        v13 = 3;
        break;
      case 76:
        v13 = 4;
        break;
      default:
        goto LABEL_37;
    }
    v8 = *v5++;
LABEL_37:
    if ( v8 == 37 )
      goto LABEL_38;
    if ( (unsigned __int8)(v8 - 69) <= 0x22u )
    {
      v17 = 30064771077i64;
      if ( _bittest64(&v17, (char)(v8 - 69)) )
      {
        v18 = *(double *)v4;
        v4 += 8;
        OSuite::ZStringBuilder::AppendBinaryExponential(v3, v18);
        goto LABEL_39;
      }
    }
    switch ( v8 )
    {
      case 99:
        v8 = *v4;
        v4 += 8;
LABEL_38:
        OSuite::ZStringBuilder::Append(v3, v8);
        goto LABEL_39;
      case 115:
        v19 = *(const char **)v4;
        v4 += 8;
        if ( v13 <= 1 )
        {
          if ( v19 )
            goto LABEL_52;
          if ( v14 )
          {
            v19 = "(null)";
LABEL_52:
            v20 = OSuite::ZTextDecoder::utf8len(v19);
          }
          else
          {
            v20 = 0;
          }
          if ( v20 < v9 )
          {
            v21 = (unsigned int)(v9 - v20);
            do
            {
              OSuite::ZStringBuilder::Append(v3, 32);
              --v21;
            }
            while ( v21 );
          }
          if ( v19 )
          {
            if ( v14 == -1 || v20 <= v14 )
              v14 = v20;
            v22 = OSuite::ZTextDecoder::utf8indexof(v19, v14);
            OSuite::ZStringBuilder::AppendUtf8(v3, v19, v22);
          }
LABEL_74:
          v7 = v40;
          goto LABEL_39;
        }
        if ( v19 )
        {
LABEL_65:
          v23 = strlen(v19);
        }
        else
        {
          if ( v14 )
          {
            v19 = "(null)";
            goto LABEL_65;
          }
          v23 = 0;
        }
        if ( v23 < v9 )
        {
          v24 = (unsigned int)(v9 - v23);
          do
          {
            OSuite::ZStringBuilder::Append(v3, 32);
            --v24;
          }
          while ( v24 );
        }
        if ( v19 )
        {
          if ( v14 == -1 || v23 <= v14 )
            v14 = v23;
          OSuite::ZStringBuilder::Append(v3, v19, v14);
        }
        goto LABEL_74;
      case 105:
      case 100:
        if ( v14 == -1 )
          v14 = 1;
        v4 += 8;
        if ( v13 )
        {
          v38 = v13 - 1;
          if ( v38 )
          {
            v39 = v38 - 2;
            if ( v39 && v39 == 1 )
              v27 = *((_QWORD *)v4 - 1);
            else
              v27 = *((signed int *)v4 - 2);
          }
          else
          {
            v27 = *((signed __int16 *)v4 - 4);
          }
        }
        else
        {
          v27 = *(v4 - 8);
        }
        v28 = v14;
        v29 = v9;
        v30 = v3;
        if ( v27 < 0 )
        {
          OSuite::ZStringBuilder::InternalAppendDecimal(v3, -v27, v9, v14, cPad, 45);
          goto LABEL_39;
        }
LABEL_90:
        OSuite::ZStringBuilder::InternalAppendDecimal(v30, v27, v29, v28, cPad, cPositiveChar);
        goto LABEL_39;
      case 117:
        if ( v14 == -1 )
          v14 = 1;
        v4 += 8;
        if ( v13 )
        {
          v25 = v13 - 1;
          if ( v25 )
          {
            v26 = v25 - 2;
            if ( v26 && v26 == 1 )
              v27 = *((_QWORD *)v4 - 1);
            else
              v27 = *((unsigned int *)v4 - 2);
          }
          else
          {
            v27 = *((unsigned __int16 *)v4 - 4);
          }
        }
        else
        {
          v27 = (unsigned __int8)*(v4 - 8);
        }
        v28 = v14;
        v29 = v9;
        v30 = v3;
        goto LABEL_90;
    }
    if ( !((v8 - 88) & 0xDF) )
    {
      if ( v14 == -1 )
        v14 = 1;
      v33 = v8 == 88;
      v4 += 8;
      if ( v13 )
      {
        v34 = v13 - 1;
        if ( v34 )
        {
          v35 = v34 - 2;
          if ( v35 && v35 == 1 )
            v36 = *((_QWORD *)v4 - 1);
          else
            v36 = *((unsigned int *)v4 - 2);
        }
        else
        {
          v36 = *((unsigned __int16 *)v4 - 4);
        }
      }
      else
      {
        v36 = (unsigned __int8)*(v4 - 8);
      }
      if ( v10 && v36 )
      {
        v37 = "0x";
        if ( v33 )
          v37 = "0X";
      }
      else
      {
        v37 = 0i64;
      }
      OSuite::ZStringBuilder::InternalAppendHex(v3, v36, v33, v37, v9, v14, cPad);
      goto LABEL_39;
    }
    if ( v8 == 112 )
    {
      v31 = *(_QWORD *)v4;
      v4 += 8;
      OSuite::ZStringBuilder::InternalAppendHex(v3, v31, 1, 0i64, 0, 1, 0);
      goto LABEL_39;
    }
    if ( v8 == 110 )
    {
      v32 = *(_DWORD **)v4;
      v4 += 8;
      *v32 = OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)&v3->m_Chars) - v7;
      goto LABEL_39;
    }
  }
}

