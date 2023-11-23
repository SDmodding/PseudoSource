// File Line: 22
// RVA: 0x8E7E80
bool __fastcall Scaleform::GFx::ASUtils::IsWhiteSpace(unsigned int c)
{
  unsigned __int64 v1; // rax
  __int64 v2; // rdx
  bool result; // al

  result = c == 32
        || c - 9 <= 4
        || (v1 = c - 0x2000, (unsigned int)v1 <= 0x29) && (v2 = 0x30000000FFFi64, _bittest64(&v2, v1))
        || c == 8287
        || c == 12288;
  return result;
}

// File Line: 28
// RVA: 0x910BD0
__int64 __fastcall Scaleform::GFx::ASUtils::SkipWhiteSpace(Scaleform::String *str)
{
  unsigned int v2; // ebx
  unsigned int Length; // edi
  __int64 v4; // rbp
  unsigned int CharAt; // eax
  unsigned int v6; // ecx
  unsigned __int64 v7; // rax

  v2 = 0;
  Length = Scaleform::String::GetLength(str);
  if ( !Length )
    return 0i64;
  v4 = 0x30000000FFFi64;
  do
  {
    CharAt = Scaleform::String::GetCharAt(str, v2);
    v6 = CharAt;
    if ( CharAt != 32 && CharAt - 9 > 4 )
    {
      v7 = CharAt - 0x2000;
      if ( ((unsigned int)v7 > 0x29 || !_bittest64(&v4, v7)) && v6 != 8287 && v6 != 12288 )
        break;
    }
    ++v2;
  }
  while ( v2 < Length );
  return v2;
}

// File Line: 43
// RVA: 0x910C70
char *__fastcall Scaleform::GFx::ASUtils::SkipWhiteSpace(char *str, unsigned __int64 len)
{
  const char *v2; // rdi
  char *v3; // rbx
  __int64 v4; // rsi
  unsigned int Char_Advance0; // eax
  unsigned __int64 v6; // rcx
  char *putf8Buffer; // [rsp+30h] [rbp+8h] BYREF

  putf8Buffer = str;
  v2 = &str[len];
  v3 = str;
  if ( str >= &str[len] )
    return str;
  v4 = 0x30000000FFFi64;
  do
  {
    Char_Advance0 = Scaleform::UTF8Util::DecodeNextChar_Advance0((const char **)&putf8Buffer);
    if ( Char_Advance0 != 32 && Char_Advance0 - 9 > 4 )
    {
      v6 = Char_Advance0 - 0x2000;
      if ( ((unsigned int)v6 > 0x29 || !_bittest64(&v4, v6)) && Char_Advance0 != 8287 && Char_Advance0 != 12288 )
        break;
    }
    v3 = putf8Buffer;
  }
  while ( putf8Buffer < v2 );
  return v3;
}

// File Line: 61
// RVA: 0x8C8BA0
void __fastcall Scaleform::GFx::ASUtils::EscapeWithMask(
        const char *psrc,
        unsigned __int64 length,
        Scaleform::String *pescapedStr,
        const unsigned int *escapeMask)
{
  unsigned int v4; // edi
  char *v9; // r10
  __int64 v10; // rax
  int v11; // ebx
  unsigned int v12; // eax
  char v13; // cl
  int v14; // eax
  char v15; // cl
  char putf8str[255]; // [rsp+20h] [rbp-118h] BYREF
  char v17; // [rsp+11Fh] [rbp-19h] BYREF

  v4 = 0;
  v9 = putf8str;
  if ( length )
  {
    v10 = 0i64;
    do
    {
      v11 = (unsigned __int8)psrc[v10];
      if ( v9 + 4 >= &v17 )
      {
        *v9 = 0;
        Scaleform::String::AppendString(pescapedStr, putf8str, -1i64);
        v9 = putf8str;
      }
      if ( v11 < 128 && (v12 = escapeMask[v11 / 32], _bittest((const int *)&v12, v11 % 32)) )
      {
        *v9++ = v11;
      }
      else
      {
        *v9 = 37;
        v13 = 55;
        v14 = v11 % 16;
        if ( v11 / 16 <= 9 )
          v13 = 48;
        v9[1] = v11 / 16 + v13;
        v15 = 55;
        if ( v14 <= 9 )
          v15 = 48;
        v9 += 3;
        *(v9 - 1) = v14 + v15;
      }
      v10 = ++v4;
    }
    while ( v4 < length );
  }
  *v9 = 0;
  Scaleform::String::AppendString(pescapedStr, putf8str, -1i64);
}

// File Line: 95
// RVA: 0x914E60
void __fastcall Scaleform::GFx::ASUtils::Unescape(
        const char *psrc,
        unsigned __int64 length,
        Scaleform::String *punescapedStr)
{
  const char *v3; // rsi
  const char *v5; // rbx
  char *v6; // r9
  int v7; // edi
  int v8; // eax
  int v9; // edx
  int v10; // eax
  int v11; // edx
  char putf8str[255]; // [rsp+20h] [rbp-108h] BYREF
  char v13; // [rsp+11Fh] [rbp-9h] BYREF

  v3 = &psrc[length];
  v5 = psrc;
  v6 = putf8str;
  while ( v5 < v3 )
  {
    v7 = *(unsigned __int8 *)v5++;
    if ( v6 + 1 >= &v13 )
    {
      *v6 = 0;
      Scaleform::String::AppendString(punescapedStr, putf8str, -1i64);
      v6 = putf8str;
    }
    if ( v7 == 37 )
    {
      v8 = *(unsigned __int8 *)v5;
      if ( (unsigned int)(v8 - 97) <= 0x19 )
        v8 -= 32;
      v9 = *((unsigned __int8 *)v5 + 1);
      if ( (unsigned int)(v9 - 97) <= 0x19 )
        v9 -= 32;
      v5 += 2;
      if ( v8 - 48 <= 9 )
        v10 = v8 - 48;
      else
        v10 = v8 - 55;
      if ( v9 - 48 <= 9 )
        v11 = v9 - 48;
      else
        v11 = v9 - 55;
      if ( v10 >= 16 || v11 >= 16 )
        continue;
      *v6 = v11 + 16 * v10;
    }
    else
    {
      *v6 = v7;
    }
    ++v6;
  }
  *v6 = 0;
  Scaleform::String::AppendString(punescapedStr, putf8str, -1i64);
}

// File Line: 135
// RVA: 0x8C8B80
void __fastcall Scaleform::GFx::ASUtils::Escape(
        const char *psrc,
        unsigned __int64 length,
        Scaleform::String *pescapedStr)
{
  Scaleform::GFx::ASUtils::EscapeWithMask(psrc, length, pescapedStr, mask);
}

// File Line: 143
// RVA: 0x8C8B90
void __fastcall Scaleform::GFx::ASUtils::EscapePath(
        const char *psrc,
        unsigned __int64 length,
        Scaleform::String *pescapedStr)
{
  Scaleform::GFx::ASUtils::EscapeWithMask(psrc, length, pescapedStr, mask_0);
}

// File Line: 184
// RVA: 0x91A790
void __fastcall Scaleform::GFx::ASUtils::AS3::Formatter::WriteHexWord(Scaleform::StringBuffer *b, unsigned __int16 v)
{
  unsigned __int8 v2; // bl
  __int16 v4; // di
  char v5; // al
  char v6; // al
  unsigned __int8 v7; // di
  char v8; // di
  char v9; // al
  char v10; // al
  unsigned __int8 v11; // bl
  char v12; // bl

  v2 = v;
  v4 = HIBYTE(v);
  v5 = HIBYTE(v) >> 4;
  if ( (unsigned __int8)(HIBYTE(v) >> 4) >= 0xAu )
    v6 = v5 + 55;
  else
    v6 = v5 + 48;
  Scaleform::StringBuffer::AppendChar(b, v6);
  v7 = v4 & 0xF;
  if ( v7 >= 0xAu )
    v8 = v7 + 55;
  else
    v8 = v7 + 48;
  Scaleform::StringBuffer::AppendChar(b, v8);
  v9 = v2 >> 4;
  if ( (unsigned __int8)(v2 >> 4) >= 0xAu )
    v10 = v9 + 55;
  else
    v10 = v9 + 48;
  Scaleform::StringBuffer::AppendChar(b, v10);
  v11 = v2 & 0xF;
  if ( v11 >= 0xAu )
    v12 = v11 + 55;
  else
    v12 = v11 + 48;
  Scaleform::StringBuffer::AppendChar(b, v12);
}

// File Line: 200
// RVA: 0x8FC240
__int64 __fastcall Scaleform::GFx::ASUtils::AS3::Formatter::ReadHex(
        const char **pStr,
        const char *end,
        unsigned __int8 max_chars)
{
  const char *v3; // rdi
  unsigned __int16 v5; // r9
  int v6; // r11d
  int v7; // ebx
  const char *v8; // r8
  char v9; // al
  const char *v10; // r8
  unsigned __int8 v11; // al
  __int64 result; // rax

  v3 = *pStr;
  v5 = 0;
  v6 = 0;
  v7 = max_chars;
  if ( max_chars )
  {
    do
    {
      v8 = *pStr;
      if ( *pStr >= end )
        break;
      v9 = *v8;
      if ( (unsigned __int8)(*v8 - 48) > 9u && (unsigned __int8)(v9 - 65) > 5u && (unsigned __int8)(v9 - 97) > 5u )
        break;
      v10 = v8 + 1;
      *pStr = v10;
      if ( (unsigned __int8)(v9 - 48) > 9u )
      {
        if ( (unsigned __int8)(v9 - 65) > 5u )
        {
          if ( (unsigned __int8)(v9 - 97) > 5u )
          {
            *pStr = v10 - 1;
            v11 = 0;
          }
          else
          {
            v11 = v9 - 87;
          }
        }
        else
        {
          v11 = v9 - 55;
        }
      }
      else
      {
        v11 = v9 - 48;
      }
      ++v6;
      v5 = v11 | (unsigned __int16)(16 * v5);
    }
    while ( v6 < v7 );
  }
  result = v5;
  if ( *pStr - v3 < max_chars )
    *pStr = v3;
  return result;
}

// File Line: 249
// RVA: 0x8C8CD0
void __fastcall Scaleform::GFx::ASUtils::AS3::Formatter::EscapeWithMask(
        char *psrc,
        unsigned __int64 length,
        Scaleform::StringBuffer *b,
        const unsigned int *escapeMask,
        bool useUtf8)
{
  const char *v5; // rbp
  bool v8; // r14
  char *v9; // rsi
  int Char_Advance0; // eax
  unsigned __int16 v11; // bx
  unsigned int v12; // ecx
  char v13; // bl
  unsigned __int8 v14; // al
  char v15; // al
  unsigned __int8 v16; // bl
  char v17; // bl
  char v18; // al
  char v19; // al
  unsigned __int8 v20; // bl
  char *putf8Buffer; // [rsp+40h] [rbp+8h] BYREF

  putf8Buffer = psrc;
  v5 = &psrc[length];
  if ( psrc < &psrc[length] )
  {
    v8 = useUtf8;
    do
    {
      v9 = putf8Buffer;
      Char_Advance0 = Scaleform::UTF8Util::DecodeNextChar_Advance0((const char **)&putf8Buffer);
      v11 = Char_Advance0;
      if ( Char_Advance0 >= 128
        || (v12 = escapeMask[Char_Advance0 / 32], !_bittest((const int *)&v12, Char_Advance0 % 32)) )
      {
        if ( (Char_Advance0 & 0xFF00) != 0 )
        {
          if ( v8 )
          {
            for ( ; v9 < putf8Buffer; ++v9 )
            {
              Scaleform::StringBuffer::AppendChar(b, 0x25u);
              v13 = *v9;
              v14 = (unsigned __int8)*v9 >> 4;
              if ( v14 >= 0xAu )
                v15 = v14 + 55;
              else
                v15 = v14 + 48;
              Scaleform::StringBuffer::AppendChar(b, v15);
              v16 = v13 & 0xF;
              if ( v16 >= 0xAu )
                v17 = v16 + 55;
              else
                v17 = v16 + 48;
              Scaleform::StringBuffer::AppendChar(b, v17);
            }
          }
          else
          {
            Scaleform::StringBuffer::AppendChar(b, 0x25u);
            Scaleform::StringBuffer::AppendChar(b, 0x75u);
            Scaleform::GFx::ASUtils::AS3::Formatter::WriteHexWord(b, v11);
          }
          continue;
        }
        Scaleform::StringBuffer::AppendChar(b, 0x25u);
        v18 = (unsigned __int8)v11 >> 4;
        if ( (unsigned __int8)((unsigned __int8)v11 >> 4) >= 0xAu )
          v19 = v18 + 55;
        else
          v19 = v18 + 48;
        Scaleform::StringBuffer::AppendChar(b, v19);
        v20 = v11 & 0xF;
        if ( v20 >= 0xAu )
          LOBYTE(v11) = v20 + 55;
        else
          LOBYTE(v11) = v20 + 48;
      }
      Scaleform::StringBuffer::AppendChar(b, (char)v11);
    }
    while ( putf8Buffer < v5 );
  }
}

// File Line: 308
// RVA: 0x8C8E50
char __fastcall Scaleform::GFx::ASUtils::AS3::Formatter::EscapeWithMaskURI(
        char *psrc,
        unsigned __int64 length,
        Scaleform::StringBuffer *b,
        bool isComp)
{
  const char *v4; // r14
  __int64 v7; // r12
  __int64 v8; // rbp
  int Char_Advance0; // eax
  unsigned int v10; // ebx
  unsigned int v11; // ecx
  unsigned int v12; // ecx
  unsigned int v13; // eax
  __int64 i; // rdi
  unsigned __int8 v15; // bl
  char v16; // al
  char v17; // al
  unsigned __int8 v18; // bl
  char v19; // bl
  __int64 pindex[9]; // [rsp+20h] [rbp-48h] BYREF
  char *putf8Buffer; // [rsp+70h] [rbp+8h] BYREF
  char pbuffer[8]; // [rsp+78h] [rbp+10h] BYREF

  putf8Buffer = psrc;
  v4 = &psrc[length];
  v7 = Scaleform::UTF8Util::GetLength(psrc, -1i64);
  v8 = 0i64;
  if ( putf8Buffer >= v4 )
    return 1;
  while ( 1 )
  {
    Char_Advance0 = Scaleform::UTF8Util::DecodeNextChar_Advance0((const char **)&putf8Buffer);
    ++v8;
    v10 = Char_Advance0;
    if ( Char_Advance0 < 128
      && (v11 = uriUnescaped[Char_Advance0 / 32], _bittest((const int *)&v11, Char_Advance0 % 32))
      || !isComp
      && Char_Advance0 < 128
      && (v12 = uriReservedPlusPound[Char_Advance0 / 32], _bittest((const int *)&v12, Char_Advance0 % 32)) )
    {
      Scaleform::StringBuffer::AppendChar(b, (char)Char_Advance0);
      goto LABEL_22;
    }
    if ( (unsigned int)(Char_Advance0 - 56320) <= 0x3FF )
      return 0;
    if ( (unsigned int)(Char_Advance0 - 55296) <= 0x3FF )
      break;
LABEL_13:
    pindex[0] = 0i64;
    Scaleform::UTF8Util::EncodeCharSafe(pbuffer, 6ui64, pindex, v10);
    if ( !pindex[0] )
      return 0;
    for ( i = 0i64; i < pindex[0]; ++i )
    {
      v15 = pbuffer[i];
      Scaleform::StringBuffer::AppendChar(b, 0x25u);
      v16 = v15 >> 4;
      if ( (unsigned __int8)(v15 >> 4) >= 0xAu )
        v17 = v16 + 55;
      else
        v17 = v16 + 48;
      Scaleform::StringBuffer::AppendChar(b, v17);
      v18 = v15 & 0xF;
      if ( v18 >= 0xAu )
        v19 = v18 + 55;
      else
        v19 = v18 + 48;
      Scaleform::StringBuffer::AppendChar(b, v19);
    }
LABEL_22:
    if ( putf8Buffer >= v4 )
      return 1;
  }
  if ( ++v8 != v7 )
  {
    v13 = Scaleform::UTF8Util::DecodeNextChar_Advance0((const char **)&putf8Buffer);
    if ( v13 - 56320 <= 0x3FF )
    {
      v10 = v13 + ((v10 - 55287) << 10);
      goto LABEL_13;
    }
  }
  return 0;
}

// File Line: 385
// RVA: 0x914F70
char __fastcall Scaleform::GFx::ASUtils::AS3::Formatter::Unescape(
        char *psrc,
        unsigned __int64 length,
        Scaleform::StringBuffer *b,
        bool useUtf8)
{
  const char *v4; // rdi
  char *v7; // rbx
  unsigned int v8; // eax
  char *v9; // r14
  bool v10; // si
  unsigned int v11; // edx
  char *v12; // r9
  int i; // r8d
  char v14; // al
  unsigned __int8 v15; // al
  unsigned __int16 Hex; // ax
  Scaleform::StringBuffer *v17; // rcx
  char *pStr; // [rsp+50h] [rbp+8h] BYREF

  v4 = &psrc[length];
  v7 = psrc;
  if ( psrc >= &psrc[length] )
    return 1;
  while ( 1 )
  {
    v8 = *v7++;
    pStr = v7;
    if ( v8 == 37 )
      break;
    v11 = v8;
    v17 = b;
LABEL_29:
    Scaleform::StringBuffer::AppendChar(v17, v11);
    if ( v7 >= v4 )
      return 1;
  }
  v9 = v7;
  v10 = useUtf8 && *v7 != 117;
  if ( *v7 == 117 )
  {
    LOWORD(v11) = 0;
    v12 = v7;
    for ( i = 0; i < 4; ++i )
    {
      if ( v7 >= v4 )
        break;
      v14 = *v7;
      if ( (unsigned __int8)(*v7 - 48) > 9u && (unsigned __int8)(v14 - 65) > 5u && (unsigned __int8)(v14 - 97) > 5u )
        break;
      ++v7;
      if ( (unsigned __int8)(v14 - 48) > 9u )
      {
        if ( (unsigned __int8)(v14 - 65) > 5u )
        {
          if ( (unsigned __int8)(v14 - 97) > 5u )
          {
            --v7;
            v15 = 0;
          }
          else
          {
            v15 = v14 - 87;
          }
        }
        else
        {
          v15 = v14 - 55;
        }
      }
      else
      {
        v15 = v14 - 48;
      }
      LOWORD(v11) = v15 | (unsigned __int16)(16 * v11);
    }
    v11 = (unsigned __int16)v11;
    if ( v7 - v12 < 4 )
      v7 = v12;
  }
  else
  {
    Hex = Scaleform::GFx::ASUtils::AS3::Formatter::ReadHex((const char **)&pStr, v4, 2u);
    v7 = pStr;
    v11 = Hex;
  }
  if ( v7 != v9 )
  {
    v17 = b;
    if ( v10 )
      v11 = (char)v11;
    goto LABEL_29;
  }
  return 0;
}

// File Line: 422
// RVA: 0x8C4920
char __fastcall Scaleform::GFx::ASUtils::AS3::Formatter::DecodeURI(
        const char *psrc,
        unsigned __int64 length,
        Scaleform::StringBuffer *b,
        bool isComp)
{
  const char *v4; // r14
  unsigned __int64 v5; // rsi
  const char *v9; // rbx
  unsigned int v10; // eax
  unsigned __int64 v11; // rbp
  const char *v12; // rdx
  char v13; // cl
  char v14; // cl
  char v15; // r9
  const char *v16; // rdx
  char v17; // cl
  char v18; // cl
  unsigned __int8 v19; // r9
  int Char_Advance0; // edi
  int v21; // edx
  __int64 v22; // r9
  __int64 i; // r10
  int v24; // eax
  const char *v25; // r8
  char v26; // cl
  char v27; // cl
  char v28; // dl
  const char *v29; // r8
  char v30; // cl
  char v31; // cl
  char v32; // dl
  unsigned int v33; // ecx
  unsigned int v34; // edx
  char v36[8]; // [rsp+60h] [rbp+8h] BYREF
  char *putf8Buffer; // [rsp+68h] [rbp+10h] BYREF

  v4 = &psrc[length];
  v5 = 0i64;
  v9 = psrc;
  if ( psrc >= &psrc[length] )
    return 1;
  while ( 1 )
  {
    v10 = *v9++;
    if ( v10 != 37 )
    {
      v34 = v10;
      goto LABEL_66;
    }
    v11 = v5;
    v12 = v9;
    if ( v9 < v4 )
    {
      v13 = *v9++;
      if ( (unsigned __int8)(v13 - 48) <= 9u )
      {
        v14 = v13 - 48;
        goto LABEL_12;
      }
      if ( (unsigned __int8)(v13 - 65) <= 5u )
      {
        v14 = v13 - 55;
        goto LABEL_12;
      }
      if ( (unsigned __int8)(v13 - 97) <= 5u )
      {
        v14 = v13 - 87;
        goto LABEL_12;
      }
      --v9;
    }
    v14 = 0;
LABEL_12:
    v15 = v14;
    if ( v9 == v12 )
      return 0;
    v16 = v9;
    if ( v9 < v4 )
    {
      v17 = *v9++;
      if ( (unsigned __int8)(v17 - 48) <= 9u )
      {
        v18 = v17 - 48;
        goto LABEL_22;
      }
      if ( (unsigned __int8)(v17 - 65) <= 5u )
      {
        v18 = v17 - 55;
        goto LABEL_22;
      }
      if ( (unsigned __int8)(v17 - 97) <= 5u )
      {
        v18 = v17 - 87;
        goto LABEL_22;
      }
      --v9;
    }
    v18 = 0;
LABEL_22:
    if ( v9 == v16 )
      return 0;
    v5 += 2i64;
    v19 = v18 | (16 * v15);
    if ( (v19 & 0x80u) == 0 )
    {
      Char_Advance0 = v19;
      goto LABEL_55;
    }
    v21 = 1;
    if ( (v19 & 0x40) == 0 )
      return 0;
    do
      ++v21;
    while ( ((v19 << v21) & 0x80u) != 0 );
    if ( v21 == 1 )
      return 0;
    if ( v21 > 4 )
      return 0;
    v36[0] = v19;
    if ( v5 + 3 * (v21 - 1) >= length )
      return 0;
    v22 = 1i64;
    for ( i = v21; v22 < i; v5 += 3i64 )
    {
      v24 = *v9++;
      if ( v24 != 37 )
        return 0;
      v25 = v9;
      if ( v9 < v4 )
      {
        v26 = *v9++;
        if ( (unsigned __int8)(v26 - 48) <= 9u )
        {
          v27 = v26 - 48;
          goto LABEL_41;
        }
        if ( (unsigned __int8)(v26 - 65) <= 5u )
        {
          v27 = v26 - 55;
          goto LABEL_41;
        }
        if ( (unsigned __int8)(v26 - 97) <= 5u )
        {
          v27 = v26 - 87;
          goto LABEL_41;
        }
        --v9;
      }
      v27 = 0;
LABEL_41:
      v28 = v27;
      if ( v9 == v25 )
        return 0;
      v29 = v9;
      if ( v9 >= v4 )
        goto LABEL_50;
      v30 = *v9++;
      if ( (unsigned __int8)(v30 - 48) > 9u )
      {
        if ( (unsigned __int8)(v30 - 65) > 5u )
        {
          if ( (unsigned __int8)(v30 - 97) > 5u )
          {
            --v9;
LABEL_50:
            v31 = 0;
            goto LABEL_51;
          }
          v31 = v30 - 87;
        }
        else
        {
          v31 = v30 - 55;
        }
      }
      else
      {
        v31 = v30 - 48;
      }
LABEL_51:
      if ( v9 == v29 )
        return 0;
      v32 = v31 | (16 * v28);
      if ( (v32 & 0xC0) != 0x80 )
        return 0;
      v36[v22++] = v32;
    }
    putf8Buffer = v36;
    Char_Advance0 = Scaleform::UTF8Util::DecodeNextChar_Advance0((const char **)&putf8Buffer);
    if ( Char_Advance0 == 65533 )
      return 0;
LABEL_55:
    if ( (unsigned int)Char_Advance0 >= 0x10000 )
      break;
    if ( !isComp && Char_Advance0 < 128 )
    {
      v33 = uriReservedPlusPound[Char_Advance0 / 32];
      if ( _bittest((const int *)&v33, Char_Advance0 % 32) )
      {
        for ( ; v11 <= v5; ++v11 )
          Scaleform::StringBuffer::AppendChar(b, v9[v11]);
        goto LABEL_67;
      }
    }
    v34 = Char_Advance0;
LABEL_66:
    Scaleform::StringBuffer::AppendChar(b, v34);
LABEL_67:
    ++v5;
    if ( v9 >= v4 )
      return 1;
  }
  if ( (unsigned int)Char_Advance0 <= 0x10FFFF )
  {
    Scaleform::StringBuffer::AppendChar(b, (((unsigned int)(Char_Advance0 - 0x10000) >> 10) & 0x3FF) + 55296);
    v34 = (Char_Advance0 & 0x3FF) + 56320;
    goto LABEL_66;
  }
  return 0;
}

// File Line: 611
// RVA: 0x8C8B60
void __fastcall Scaleform::GFx::ASUtils::AS3::Escape(
        const char *psrc,
        unsigned __int64 length,
        Scaleform::StringBuffer *b,
        bool useUtf8)
{
  Scaleform::GFx::ASUtils::AS3::Formatter::EscapeWithMask(psrc, length, b, unescaped_mask, useUtf8);
}

// File Line: 616
// RVA: 0x8C8400
void __fastcall Scaleform::GFx::ASUtils::AS3::EncodeVar(
        const char *psrc,
        unsigned __int64 length,
        Scaleform::StringBuffer *b,
        bool useUtf8)
{
  Scaleform::GFx::ASUtils::AS3::Formatter::EscapeWithMask(psrc, length, b, unescaped_mask_VAR, useUtf8);
}

// File Line: 621
// RVA: 0x8C83D0
// attributes: thunk
bool __fastcall Scaleform::GFx::ASUtils::AS3::EncodeURI(
        const char *psrc,
        unsigned __int64 length,
        Scaleform::StringBuffer *escapedStr,
        bool isComp)
{
  return Scaleform::GFx::ASUtils::AS3::Formatter::EscapeWithMaskURI(psrc, length, escapedStr, isComp);
}

// File Line: 626
// RVA: 0x8C83E0
void __fastcall Scaleform::GFx::ASUtils::AS3::EncodeURIComponent(
        const char *psrc,
        unsigned __int64 length,
        Scaleform::StringBuffer *b,
        bool useUtf8)
{
  Scaleform::GFx::ASUtils::AS3::Formatter::EscapeWithMask(psrc, length, b, unescaped_mask_URIComponent, useUtf8);
}

// File Line: 636
// RVA: 0x914E50
// attributes: thunk
bool __fastcall Scaleform::GFx::ASUtils::AS3::Unescape(
        const char *psrc,
        unsigned __int64 length,
        Scaleform::StringBuffer *b,
        bool useUtf8)
{
  return Scaleform::GFx::ASUtils::AS3::Formatter::Unescape(psrc, length, b, useUtf8);
}

// File Line: 641
// RVA: 0x8C4910
// attributes: thunk
bool __fastcall Scaleform::GFx::ASUtils::AS3::DecodeURI(
        const char *psrc,
        unsigned __int64 length,
        Scaleform::StringBuffer *b,
        bool isComp)
{
  return Scaleform::GFx::ASUtils::AS3::Formatter::DecodeURI(psrc, length, b, isComp);
}

// File Line: 678
// RVA: 0x8EBD50
long double __fastcall Scaleform::GFx::NumberUtil::NaN()
{
  return *(double *)GFxNaN_Bytes;
}

// File Line: 679
// RVA: 0x8EF2E0
long double __fastcall Scaleform::GFx::NumberUtil::POSITIVE_INFINITY()
{
  return *(double *)GFxPOSITIVE_INFINITY_Bytes;
}

// File Line: 680
// RVA: 0x8EBD30
long double __fastcall Scaleform::GFx::NumberUtil::NEGATIVE_INFINITY()
{
  return *(double *)GFxNEGATIVE_INFINITY_Bytes;
}

// File Line: 681
// RVA: 0x8EF300
long double __fastcall Scaleform::GFx::NumberUtil::POSITIVE_ZERO()
{
  return *(double *)GFxPOSITIVE_ZERO_Bytes;
}

// File Line: 683
// RVA: 0x8E9600
long double __fastcall Scaleform::GFx::NumberUtil::MIN_VALUE()
{
  return *(double *)GFxMIN_VALUE_Bytes;
}

// File Line: 684
// RVA: 0x8E95E0
long double __fastcall Scaleform::GFx::NumberUtil::MAX_VALUE()
{
  return *(double *)GFxMAX_VALUE_Bytes;
}

// File Line: 687
// RVA: 0x8E7480
bool __fastcall Scaleform::GFx::NumberUtil::IsPOSITIVE_ZERO(long double v)
{
  return *(_QWORD *)&v == *(_QWORD *)GFxPOSITIVE_ZERO_Bytes;
}

// File Line: 692
// RVA: 0x8E7460
bool __fastcall Scaleform::GFx::NumberUtil::IsNEGATIVE_ZERO(long double v)
{
  return *(_QWORD *)&v == *(_QWORD *)GFxNEGATIVE_ZERO_Bytes;
}

// File Line: 739
// RVA: 0x912F60
char *__fastcall Scaleform::GFx::NumberUtil::ToString(
        long double value,
        char *destStr,
        unsigned __int64 destStrSize,
        int radix)
{
  const char *v5; // r8
  int v7; // r9d
  __int64 v8; // rax
  int v10; // ecx
  char *v11; // rcx

  v5 = fmt[13];
  if ( radix <= 0 )
  {
    if ( radix < -14 )
      v7 = 14;
    else
      v7 = -radix;
    v8 = v7;
    radix = 10;
    v5 = fmt[v8 - 1];
  }
  if ( (*(_QWORD *)&value & 0x7FF0000000000000i64) == 0x7FF0000000000000i64 )
  {
    if ( (*(_QWORD *)&value & 0xFFFFFFFFFFFFFi64) != 0 )
    {
      strcpy_s(destStr, destStrSize, "NaN");
      return destStr;
    }
    if ( value == INFINITY )
    {
      strcpy_s(destStr, destStrSize, aInfinity_2);
      return destStr;
    }
    if ( value == -INFINITY )
    {
      strcpy_s(destStr, destStrSize, aInfinit);
      return destStr;
    }
    return destStr;
  }
  v10 = (int)value;
  if ( radix == 10 )
  {
    if ( (double)v10 == value )
      return Scaleform::GFx::NumberUtil::IntToString(v10, destStr, destStrSize);
    Scaleform::SFsprintf(destStr, destStrSize, v5, value);
    v11 = destStr;
    if ( *destStr )
    {
      while ( ((*v11 - 44) & 0xFD) != 0 )
      {
        if ( !*++v11 )
          return destStr;
      }
      *v11 = 46;
    }
    return destStr;
  }
  return Scaleform::GFx::NumberUtil::IntToString(v10, destStr, destStrSize, radix);
}

// File Line: 866
// RVA: 0x8E6B60
char *__fastcall Scaleform::GFx::NumberUtil::IntToString(
        unsigned int value,
        char *destStr,
        unsigned __int64 destStrSize,
        int radix)
{
  unsigned __int64 v4; // r11
  char *result; // rax
  unsigned int v8; // r10d
  unsigned int v9; // edx
  char v10; // cl
  char v11; // cl
  unsigned int v12; // edx
  char v13; // cl
  char *v14; // rdx
  int v15; // r8d
  unsigned int i; // r9d

  v4 = destStrSize - 1;
  result = &destStr[destStrSize - 1];
  v8 = value;
  *result = 0;
  switch ( radix )
  {
    case 2:
      v14 = 0i64;
      v15 = 1;
      for ( i = 0; i < 0x20; ++i )
      {
        if ( i >= v4 )
          break;
        --result;
        if ( (v15 & value) != 0 )
        {
          *result = 49;
          v14 = result;
        }
        else
        {
          *result = 48;
        }
        v15 *= 2;
        if ( !v15 )
          v15 = 1;
      }
      if ( v14 )
        return v14;
      else
        return &destStr[destStrSize - 2];
    case 8:
      v12 = 0;
      if ( destStrSize != 1 )
      {
        do
        {
          v13 = v8;
          --result;
          v8 >>= 3;
          *result = (v13 & 7) + 48;
          if ( !v8 )
            break;
          ++v12;
        }
        while ( v12 < v4 );
      }
      break;
    case 16:
      v9 = 0;
      if ( destStrSize != 1 )
      {
        do
        {
          --result;
          v10 = v8 & 0xF;
          if ( (v8 & 0xF) > 9 )
            v11 = v10 + 87;
          else
            v11 = v10 + 48;
          v8 >>= 4;
          *result = v11;
          if ( !v8 )
            break;
          ++v9;
        }
        while ( v9 < v4 );
      }
      break;
    default:
      return Scaleform::GFx::NumberUtil::IntToString(value, destStr, destStrSize);
  }
  return result;
}

// File Line: 932
// RVA: 0x8E6AD0
char *__fastcall Scaleform::GFx::NumberUtil::IntToString(int value, char *destStr, unsigned __int64 destStrSize)
{
  unsigned __int64 v3; // r11
  unsigned int v4; // r8d
  char *v5; // r9
  unsigned int i; // r10d

  v3 = destStrSize - 1;
  v4 = 0;
  v5 = &destStr[v3];
  destStr[v3] = 0;
  for ( i = abs32(value); v4 < v3; ++v4 )
  {
    *--v5 = i % 0xA + 48;
    i /= 0xAu;
    if ( !i )
      break;
  }
  if ( v4 >= v3 || value >= 0 )
    return v5;
  *(v5 - 1) = 45;
  return v5 - 1;
}

// File Line: 966
// RVA: 0x911B80
double __fastcall Scaleform::GFx::NumberUtil::StringToInt(
        const char *str,
        unsigned int strLen,
        int radix,
        unsigned int *endIndex)
{
  signed int v5; // r14d
  unsigned int v6; // r15d
  char v8; // r13
  bool v9; // bp
  unsigned int v10; // ebx
  unsigned int Length; // esi
  __int64 v12; // r15
  unsigned int CharAt; // eax
  unsigned __int64 v14; // rcx
  __int64 v15; // rcx
  char v17; // dl
  int v18; // esi
  __int64 v19; // rdx
  __int64 v20; // rdx
  double v21; // xmm3_8
  double v22; // xmm2_8
  int v23; // ecx
  __int64 v24; // r8
  char v25; // cl
  int v26; // eax
  int v27; // ebx
  const char *v28; // rax
  int v29; // r9d
  unsigned int v30; // r8d
  char v31; // cl
  char v32; // r9
  char v33; // r10
  char v34; // r11
  char v35; // cl
  int v36; // eax
  char v37; // cl
  int v38; // eax
  char v39; // cl
  __int64 v40; // rdx
  const char *v41; // r8
  char v42; // cl
  int v43; // eax
  Scaleform::String v45; // [rsp+88h] [rbp+20h] BYREF

  v5 = radix;
  v6 = strLen;
  v8 = 0;
  *endIndex = 0;
  v9 = 1;
  if ( radix )
  {
    if ( (unsigned int)(radix - 2) > 0x22 )
      return *(double *)GFxNaN_Bytes;
    v9 = radix == 16;
  }
  else
  {
    v5 = 10;
  }
  Scaleform::String::String(&v45, str);
  v10 = 0;
  Length = Scaleform::String::GetLength(&v45);
  if ( Length )
  {
    v12 = 0x30000000FFFi64;
    do
    {
      CharAt = Scaleform::String::GetCharAt(&v45, v10);
      if ( CharAt != 32 && CharAt - 9 > 4 )
      {
        v14 = CharAt - 0x2000;
        if ( ((unsigned int)v14 > 0x29 || !_bittest64(&v12, v14)) && CharAt != 8287 && CharAt != 12288 )
          break;
      }
      ++v10;
    }
    while ( v10 < Length );
    v6 = strLen;
  }
  *endIndex = Scaleform::UTF8Util::GetByteIndex(v10, str, v6);
  if ( !_InterlockedDecrement((volatile signed __int32 *)((v45.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  v15 = *endIndex;
  if ( (_DWORD)v15 == v6 )
    return 0.0;
  v17 = str[v15];
  if ( v17 == 45 )
  {
    v18 = -1;
  }
  else
  {
    v18 = 1;
    if ( v17 != 43 )
      goto LABEL_23;
  }
  *endIndex = v15 + 1;
LABEL_23:
  if ( !v9
    || (v19 = *endIndex, v6 - (unsigned int)v19 <= 1)
    || str[v19] != 48
    || ((str[(unsigned int)(v19 + 1)] - 88) & 0xDF) != 0
    || (v5 = 16, *endIndex = v19 + 2, v6 != (_DWORD)v19 + 2) )
  {
    v20 = *endIndex;
    v21 = 0.0;
    v22 = 0.0;
    LOBYTE(v23) = 0;
    if ( (unsigned int)v20 < v6 )
    {
      do
      {
        v24 = *endIndex;
        v25 = str[v24];
        if ( (unsigned __int8)(v25 - 48) > 9u )
        {
          if ( (unsigned __int8)(v25 - 97) > 0x19u )
          {
            if ( (unsigned __int8)(v25 - 65) > 0x19u )
              v23 = -1;
            else
              v23 = v25 - 55;
          }
          else
          {
            v23 = v25 - 87;
          }
        }
        else
        {
          v23 = v25 - 48;
        }
        if ( v23 >= v5 )
          break;
        if ( v23 < 0 )
          break;
        v22 = (double)v5 * v22 + (double)v23;
        *endIndex = v24 + 1;
      }
      while ( (int)v24 + 1 < v6 );
    }
    if ( *endIndex != (_DWORD)v20 )
    {
      if ( v22 < 9.007199254740992e15 )
        return (double)v18 * v22;
      if ( (unsigned int)v5 > 0x10 )
        return (double)v18 * v22;
      v26 = 65796;
      if ( !_bittest(&v26, v5) )
        return (double)v18 * v22;
      v27 = 1;
      if ( v5 == 8 )
      {
        v27 = 3;
      }
      else if ( v5 == 16 )
      {
        v27 = 4;
      }
      if ( (unsigned int)v20 < v6 )
      {
        v28 = &str[v20];
        do
        {
          if ( *v28 != 48 )
            break;
          v20 = (unsigned int)(v20 + 1);
          ++v28;
        }
        while ( (unsigned int)v20 < v6 );
      }
      v22 = 0.0;
      v29 = 0;
      if ( (unsigned int)v20 < v6 )
      {
        v30 = 0;
        while ( v30 <= 0x34 )
        {
          v31 = str[v20];
          if ( (unsigned __int8)(v31 - 48) > 9u )
          {
            if ( (unsigned __int8)(v31 - 97) > 0x19u )
            {
              if ( (unsigned __int8)(v31 - 65) > 0x19u )
                v23 = -1;
              else
                v23 = v31 - 55;
            }
            else
            {
              v23 = v31 - 87;
            }
          }
          else
          {
            v23 = v31 - 48;
          }
          v20 = (unsigned int)(v20 + 1);
          if ( v23 >= v5 || v23 < 0 )
          {
            LOBYTE(v23) = 0;
            break;
          }
          v22 = (double)v5 * v22 + (double)v23;
          ++v29;
          v30 += v27;
          if ( (unsigned int)v20 >= v6 )
            break;
        }
      }
      if ( (unsigned int)(v27 * v29) <= 0x34 )
        return (double)v18 * v22;
      v32 = 0;
      v33 = 0;
      v34 = 0;
      if ( v5 != 2 )
      {
        if ( v5 != 8 )
        {
          if ( v5 != 16 )
          {
LABEL_104:
            v40 = (unsigned int)(v20 + 1);
            if ( (unsigned int)v40 < v6 )
            {
              v41 = &str[v40];
              do
              {
                v42 = *v41;
                if ( (unsigned __int8)(*v41 - 48) > 9u )
                {
                  if ( (unsigned __int8)(v42 - 97) > 0x19u )
                  {
                    if ( (unsigned __int8)(v42 - 65) > 0x19u )
                      break;
                    v43 = v42 - 55;
                  }
                  else
                  {
                    v43 = v42 - 87;
                  }
                }
                else
                {
                  v43 = v42 - 48;
                }
                if ( v43 == -1 )
                  break;
                if ( v43 >= v5 )
                  break;
                v32 |= v43 != 0;
                v8 += v27;
                LODWORD(v40) = v40 + 1;
                ++v41;
              }
              while ( (unsigned int)v40 < v6 );
            }
            if ( v34 && (v33 || v32) )
              v21 = DOUBLE_1_0;
            v22 = (v21 + v22) * (double)(1 << v8);
            return (double)v18 * v22;
          }
          v33 = v23 & 1;
          if ( (unsigned int)v20 < v6 )
          {
            v35 = str[v20];
            if ( (unsigned __int8)(v35 - 48) <= 9u )
            {
              v36 = v35 - 48;
LABEL_77:
              if ( v36 != -1 && v36 < 16 )
              {
                v34 = (v36 & 8) != 0;
                v32 = (v36 & 3) != 0;
LABEL_103:
                v8 = v27;
                goto LABEL_104;
              }
              goto LABEL_80;
            }
            if ( (unsigned __int8)(v35 - 97) <= 0x19u )
            {
              v36 = v35 - 87;
              goto LABEL_77;
            }
            if ( (unsigned __int8)(v35 - 65) <= 0x19u )
            {
              v36 = v35 - 55;
              goto LABEL_77;
            }
          }
LABEL_80:
          v32 = v33 != 0;
          goto LABEL_104;
        }
        if ( (unsigned int)v20 < v6 )
        {
          v37 = str[v20];
          if ( (unsigned __int8)(v37 - 48) <= 9u )
          {
            v38 = v37 - 48;
LABEL_88:
            if ( v38 != -1 && v38 < 8 )
              goto LABEL_91;
            goto LABEL_90;
          }
          if ( (unsigned __int8)(v37 - 97) <= 0x19u )
          {
            v38 = v37 - 87;
            goto LABEL_88;
          }
          if ( (unsigned __int8)(v37 - 65) <= 0x19u )
          {
            v38 = v37 - 55;
            goto LABEL_88;
          }
        }
LABEL_90:
        LOBYTE(v38) = 0;
LABEL_91:
        v33 = (v38 & 2) != 0;
LABEL_102:
        v34 = v38 & 1;
        goto LABEL_103;
      }
      v33 = v23 & 1;
      if ( (unsigned int)v20 < v6 )
      {
        v39 = str[v20];
        if ( (unsigned __int8)(v39 - 48) <= 9u )
        {
          v38 = v39 - 48;
LABEL_99:
          if ( v38 != -1 && v38 < 2 )
            goto LABEL_102;
          goto LABEL_101;
        }
        if ( (unsigned __int8)(v39 - 97) <= 0x19u )
        {
          v38 = v39 - 87;
          goto LABEL_99;
        }
        if ( (unsigned __int8)(v39 - 65) <= 0x19u )
        {
          v38 = v39 - 55;
          goto LABEL_99;
        }
      }
LABEL_101:
      LOBYTE(v38) = 0;
      goto LABEL_102;
    }
  }
  return *(double *)GFxNaN_Bytes;
}

// File Line: 1137
// RVA: 0x9119C0
long double __fastcall Scaleform::GFx::NumberUtil::StringToDouble(
        const char *str,
        unsigned int strLen,
        unsigned int *endIndex)
{
  __int64 v4; // r14
  unsigned int v6; // ebx
  unsigned int Length; // ebp
  __int64 v8; // r15
  unsigned int CharAt; // eax
  unsigned __int64 v10; // rcx
  __int64 v11; // rax
  unsigned int v12; // r14d
  long double result; // xmm0_8
  const char *v14; // rsi
  char v15; // al
  Scaleform::String::DataDesc *v16; // rax
  char *v17; // rcx
  Scaleform::String v18; // [rsp+70h] [rbp+18h] BYREF
  char *tailptr; // [rsp+78h] [rbp+20h] BYREF

  v4 = strLen;
  *endIndex = 0;
  Scaleform::String::String(&v18, str);
  v6 = 0;
  Length = Scaleform::String::GetLength(&v18);
  if ( Length )
  {
    v8 = 0x30000000FFFi64;
    do
    {
      CharAt = Scaleform::String::GetCharAt(&v18, v6);
      if ( CharAt != 32 && CharAt - 9 > 4 )
      {
        v10 = CharAt - 0x2000;
        if ( ((unsigned int)v10 > 0x29 || !_bittest64(&v8, v10)) && CharAt != 8287 && CharAt != 12288 )
          break;
      }
      ++v6;
    }
    while ( v6 < Length );
  }
  *endIndex = Scaleform::UTF8Util::GetByteIndex(v6, str, v4);
  if ( !_InterlockedDecrement((volatile signed __int32 *)((v18.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  v11 = *endIndex;
  v12 = v4 - v11;
  if ( !v12 )
  {
    v18.pData = *(Scaleform::String::DataDesc **)GFxNaN_Bytes;
    return *(double *)GFxNaN_Bytes;
  }
  tailptr = 0i64;
  v14 = &str[v11];
  if ( v12 > 1 )
  {
    v15 = *v14;
    if ( *v14 == 43 )
    {
      if ( !strncmp(v14, "+Infinity", 9ui64) )
      {
        *endIndex += 9;
        goto LABEL_20;
      }
    }
    else if ( v15 == 45 )
    {
      if ( !strncmp(v14, aInfinit, 9ui64) )
      {
        *endIndex += 9;
        v16 = *(Scaleform::String::DataDesc **)GFxNEGATIVE_INFINITY_Bytes;
        goto LABEL_21;
      }
    }
    else if ( v15 == 73 && !strncmp(v14, aInfinity_2, 8ui64) )
    {
      *endIndex += 8;
LABEL_20:
      v16 = *(Scaleform::String::DataDesc **)GFxPOSITIVE_INFINITY_Bytes;
LABEL_21:
      v18.pData = v16;
      return *(double *)&v16;
    }
  }
  result = Scaleform::SFstrtod(v14, &tailptr);
  v17 = tailptr;
  *endIndex += (_DWORD)tailptr - (_DWORD)v14;
  if ( v17 == v14 )
    return *(double *)GFxNaN_Bytes;
  return result;
}

