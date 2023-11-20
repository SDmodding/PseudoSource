// File Line: 22
// RVA: 0x8E7E80
bool __fastcall Scaleform::GFx::ASUtils::IsWhiteSpace(unsigned int c)
{
  unsigned __int64 v1; // rax
  signed __int64 v2; // rdx
  bool result; // al

  result = c == 32
        || c - 9 <= 4
        || (v1 = c - 0x2000, (unsigned int)v1 <= 0x29) && (v2 = 3298534887423i64, _bittest64(&v2, v1))
        || c == 8287
        || c == 12288;
  return result;
}

// File Line: 28
// RVA: 0x910BD0
__int64 __fastcall Scaleform::GFx::ASUtils::SkipWhiteSpace(Scaleform::String *str)
{
  Scaleform::String *v1; // rsi
  unsigned int v2; // ebx
  unsigned int v3; // edi
  signed __int64 v4; // rbp
  unsigned int v5; // eax
  unsigned int v6; // ecx
  unsigned __int64 v7; // rax

  v1 = str;
  v2 = 0;
  v3 = Scaleform::String::GetLength(str);
  if ( !v3 )
    return 0i64;
  v4 = 3298534887423i64;
  do
  {
    v5 = Scaleform::String::GetCharAt(v1, v2);
    v6 = v5;
    if ( v5 != 32 && v5 - 9 > 4 )
    {
      v7 = v5 - 0x2000;
      if ( ((unsigned int)v7 > 0x29 || !_bittest64(&v4, v7)) && v6 != 8287 && v6 != 12288 )
        break;
    }
    ++v2;
  }
  while ( v2 < v3 );
  return v2;
}

// File Line: 43
// RVA: 0x910C70
const char *__fastcall Scaleform::GFx::ASUtils::SkipWhiteSpace(const char *str, unsigned __int64 len)
{
  const char *v2; // rdi
  void *v3; // rbx
  signed __int64 v4; // rsi
  unsigned int v5; // eax
  unsigned __int64 v6; // rcx
  char *putf8Buffer; // [rsp+30h] [rbp+8h]

  putf8Buffer = (char *)str;
  v2 = &str[len];
  v3 = (void *)str;
  if ( str >= &str[len] )
    return str;
  v4 = 3298534887423i64;
  do
  {
    v5 = Scaleform::UTF8Util::DecodeNextChar_Advance0((const char **)&putf8Buffer);
    if ( v5 != 32 && v5 - 9 > 4 )
    {
      v6 = v5 - 0x2000;
      if ( ((unsigned int)v6 > 0x29 || !_bittest64(&v4, v6)) && v5 != 8287 && v5 != 12288 )
        break;
    }
    v3 = putf8Buffer;
  }
  while ( putf8Buffer < v2 );
  return (const char *)v3;
}

// File Line: 61
// RVA: 0x8C8BA0
void __fastcall Scaleform::GFx::ASUtils::EscapeWithMask(const char *psrc, unsigned __int64 length, Scaleform::String *pescapedStr, const unsigned int *escapeMask)
{
  unsigned int v4; // edi
  const unsigned int *v5; // r15
  Scaleform::String *v6; // rbp
  unsigned __int64 v7; // rsi
  const char *v8; // r14
  char *v9; // r10
  __int64 v10; // rax
  signed int v11; // ebx
  unsigned int v12; // eax
  char v13; // cl
  int v14; // er8
  int v15; // eax
  char v16; // cl
  char putf8str; // [rsp+20h] [rbp-118h]
  char v18; // [rsp+11Fh] [rbp-19h]

  v4 = 0;
  v5 = escapeMask;
  v6 = pescapedStr;
  v7 = length;
  v8 = psrc;
  v9 = &putf8str;
  if ( length )
  {
    v10 = 0i64;
    do
    {
      v11 = (unsigned __int8)v8[v10];
      if ( v9 + 4 >= &v18 )
      {
        *v9 = 0;
        Scaleform::String::AppendString(v6, &putf8str, -1i64);
        v9 = &putf8str;
      }
      if ( v11 < 128 && (v12 = v5[v11 / 32], _bittest((const signed int *)&v12, v11 % -32)) )
      {
        *v9++ = v11;
      }
      else
      {
        *v9 = 37;
        v13 = 55;
        v14 = v11 / 16;
        v15 = v11 % -16;
        if ( v11 / 16 <= 9 )
          v13 = 48;
        v9[1] = v14 + v13;
        v16 = 55;
        if ( v15 <= 9 )
          v16 = 48;
        v9 += 3;
        *(v9 - 1) = v15 + v16;
      }
      v10 = ++v4;
    }
    while ( v4 < v7 );
  }
  *v9 = 0;
  Scaleform::String::AppendString(v6, &putf8str, -1i64);
}

// File Line: 95
// RVA: 0x914E60
void __fastcall Scaleform::GFx::ASUtils::Unescape(const char *psrc, unsigned __int64 length, Scaleform::String *punescapedStr)
{
  const char *v3; // rsi
  Scaleform::String *v4; // rbp
  const char *v5; // rbx
  char *v6; // r9
  int v7; // edi
  int v8; // eax
  int v9; // edx
  int v10; // eax
  int v11; // edx
  char putf8str; // [rsp+20h] [rbp-108h]
  char v13; // [rsp+11Fh] [rbp-9h]

  v3 = &psrc[length];
  v4 = punescapedStr;
  v5 = psrc;
  v6 = &putf8str;
  while ( v5 < v3 )
  {
    v7 = *(unsigned __int8 *)v5++;
    if ( v6 + 1 >= &v13 )
    {
      *v6 = 0;
      Scaleform::String::AppendString(v4, &putf8str, -1i64);
      v6 = &putf8str;
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
  Scaleform::String::AppendString(v4, &putf8str, -1i64);
}

// File Line: 135
// RVA: 0x8C8B80
void __fastcall Scaleform::GFx::ASUtils::Escape(const char *psrc, unsigned __int64 length, Scaleform::String *pescapedStr)
{
  Scaleform::GFx::ASUtils::EscapeWithMask(psrc, length, pescapedStr, mask);
}

// File Line: 143
// RVA: 0x8C8B90
void __fastcall Scaleform::GFx::ASUtils::EscapePath(const char *psrc, unsigned __int64 length, Scaleform::String *pescapedStr)
{
  Scaleform::GFx::ASUtils::EscapeWithMask(psrc, length, pescapedStr, mask_0);
}

// File Line: 184
// RVA: 0x91A790
void __fastcall Scaleform::GFx::ASUtils::AS3::Formatter::WriteHexWord(Scaleform::StringBuffer *b, unsigned __int16 v)
{
  unsigned __int8 v2; // bl
  Scaleform::StringBuffer *v3; // rsi
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
  v3 = b;
  v4 = v >> 8;
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
  Scaleform::StringBuffer::AppendChar(v3, v8);
  v9 = v2 >> 4;
  if ( (unsigned __int8)(v2 >> 4) >= 0xAu )
    v10 = v9 + 55;
  else
    v10 = v9 + 48;
  Scaleform::StringBuffer::AppendChar(v3, v10);
  v11 = v2 & 0xF;
  if ( v11 >= 0xAu )
    v12 = v11 + 55;
  else
    v12 = v11 + 48;
  Scaleform::StringBuffer::AppendChar(v3, v12);
}

// File Line: 200
// RVA: 0x8FC240
__int64 __fastcall Scaleform::GFx::ASUtils::AS3::Formatter::ReadHex(const char **pStr, const char *end, char max_chars)
{
  const char *v3; // rdi
  unsigned __int8 v4; // si
  unsigned __int16 v5; // r9
  int v6; // er11
  int v7; // ebx
  const char *v8; // r8
  char v9; // al
  const char *v10; // r8
  unsigned __int8 v11; // al
  __int64 result; // rax

  v3 = *pStr;
  v4 = max_chars;
  v5 = 0;
  v6 = 0;
  v7 = (unsigned __int8)max_chars;
  if ( (signed int)(unsigned __int8)max_chars > 0 )
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
  if ( *pStr - v3 < v4 )
    *pStr = v3;
  return result;
}

// File Line: 249
// RVA: 0x8C8CD0
void __fastcall Scaleform::GFx::ASUtils::AS3::Formatter::EscapeWithMask(const char *psrc, unsigned __int64 length, Scaleform::StringBuffer *b, const unsigned int *escapeMask, bool useUtf8)
{
  const char *v5; // rbp
  const unsigned int *v6; // r15
  Scaleform::StringBuffer *v7; // rdi
  bool v8; // r14
  char *v9; // rsi
  signed int v10; // eax
  unsigned __int16 v11; // bx
  int v12; // edx
  int v13; // eax
  unsigned int v14; // ecx
  char v15; // bl
  unsigned __int8 v16; // al
  char v17; // al
  unsigned __int8 v18; // bl
  char v19; // bl
  char v20; // al
  char v21; // al
  unsigned __int8 v22; // bl
  char *putf8Buffer; // [rsp+40h] [rbp+8h]

  putf8Buffer = (char *)psrc;
  v5 = &psrc[length];
  v6 = escapeMask;
  v7 = b;
  if ( psrc < &psrc[length] )
  {
    v8 = useUtf8;
    do
    {
      v9 = putf8Buffer;
      v10 = Scaleform::UTF8Util::DecodeNextChar_Advance0((const char **)&putf8Buffer);
      v11 = v10;
      if ( v10 >= 128
        || (v12 = (v10 >> 31) & 0x1F,
            v13 = v12 + v10,
            v14 = v6[v13 >> 5],
            !_bittest((const signed int *)&v14, (v13 & 0x1F) - v12)) )
      {
        if ( v11 & 0xFF00 )
        {
          if ( v8 )
          {
            for ( ; v9 < putf8Buffer; ++v9 )
            {
              Scaleform::StringBuffer::AppendChar(v7, 0x25u);
              v15 = *v9;
              v16 = (unsigned __int8)*v9 >> 4;
              if ( v16 >= 0xAu )
                v17 = v16 + 55;
              else
                v17 = v16 + 48;
              Scaleform::StringBuffer::AppendChar(v7, v17);
              v18 = v15 & 0xF;
              if ( v18 >= 0xAu )
                v19 = v18 + 55;
              else
                v19 = v18 + 48;
              Scaleform::StringBuffer::AppendChar(v7, v19);
            }
          }
          else
          {
            Scaleform::StringBuffer::AppendChar(v7, 0x25u);
            Scaleform::StringBuffer::AppendChar(v7, 0x75u);
            Scaleform::GFx::ASUtils::AS3::Formatter::WriteHexWord(v7, v11);
          }
          continue;
        }
        Scaleform::StringBuffer::AppendChar(v7, 0x25u);
        v20 = (unsigned __int8)v11 >> 4;
        if ( (unsigned __int8)((unsigned __int8)v11 >> 4) >= 0xAu )
          v21 = v20 + 55;
        else
          v21 = v20 + 48;
        Scaleform::StringBuffer::AppendChar(v7, v21);
        v22 = v11 & 0xF;
        if ( v22 >= 0xAu )
          LOBYTE(v11) = v22 + 55;
        else
          LOBYTE(v11) = v22 + 48;
      }
      Scaleform::StringBuffer::AppendChar(v7, (char)v11);
    }
    while ( putf8Buffer < v5 );
  }
}

// File Line: 308
// RVA: 0x8C8E50
char __fastcall Scaleform::GFx::ASUtils::AS3::Formatter::EscapeWithMaskURI(const char *psrc, unsigned __int64 length, Scaleform::StringBuffer *b, bool isComp)
{
  const char *v4; // r14
  bool v5; // r15
  Scaleform::StringBuffer *v6; // rsi
  __int64 v7; // r12
  __int64 v8; // rbp
  signed int v9; // eax
  signed int v10; // ebx
  int v11; // edx
  int v12; // eax
  unsigned int v13; // ecx
  unsigned int v14; // ecx
  unsigned int v15; // eax
  __int64 i; // rdi
  unsigned __int8 v17; // bl
  char v18; // al
  char v19; // al
  unsigned __int8 v20; // bl
  char v21; // bl
  __int64 pindex; // [rsp+20h] [rbp-48h]
  char *putf8Buffer; // [rsp+70h] [rbp+8h]
  char pbuffer[8]; // [rsp+78h] [rbp+10h]

  putf8Buffer = (char *)psrc;
  v4 = &psrc[length];
  v5 = isComp;
  v6 = b;
  v7 = Scaleform::UTF8Util::GetLength(psrc, -1i64);
  v8 = 0i64;
  if ( putf8Buffer >= v4 )
    return 1;
  while ( 1 )
  {
    v9 = Scaleform::UTF8Util::DecodeNextChar_Advance0((const char **)&putf8Buffer);
    ++v8;
    v10 = v9;
    if ( v9 < 128
      && (v11 = (v9 >> 31) & 0x1F,
          v12 = v11 + v9,
          v13 = uriUnescaped[v12 >> 5],
          _bittest((const signed int *)&v13, (v12 & 0x1F) - v11))
      || !v5 && v10 < 128 && (v14 = uriReservedPlusPound[v10 / 32], _bittest((const signed int *)&v14, v10 % -32)) )
    {
      Scaleform::StringBuffer::AppendChar(v6, (char)v10);
      goto LABEL_22;
    }
    if ( (unsigned int)(v10 - 56320) <= 0x3FF )
      return 0;
    if ( (unsigned int)(v10 - 55296) <= 0x3FF )
      break;
LABEL_13:
    pindex = 0i64;
    Scaleform::UTF8Util::EncodeCharSafe(pbuffer, 6ui64, &pindex, v10);
    if ( !pindex )
      return 0;
    for ( i = 0i64; i < pindex; ++i )
    {
      v17 = pbuffer[i];
      Scaleform::StringBuffer::AppendChar(v6, 0x25u);
      v18 = v17 >> 4;
      if ( (unsigned __int8)(v17 >> 4) >= 0xAu )
        v19 = v18 + 55;
      else
        v19 = v18 + 48;
      Scaleform::StringBuffer::AppendChar(v6, v19);
      v20 = v17 & 0xF;
      if ( v20 >= 0xAu )
        v21 = v20 + 55;
      else
        v21 = v20 + 48;
      Scaleform::StringBuffer::AppendChar(v6, v21);
    }
LABEL_22:
    if ( putf8Buffer >= v4 )
      return 1;
  }
  if ( ++v8 != v7 )
  {
    v15 = Scaleform::UTF8Util::DecodeNextChar_Advance0((const char **)&putf8Buffer);
    if ( v15 - 56320 <= 0x3FF )
    {
      v10 = v15 + ((v10 - 55287) << 10);
      goto LABEL_13;
    }
  }
  return 0;
}

// File Line: 385
// RVA: 0x914F70
char __fastcall Scaleform::GFx::ASUtils::AS3::Formatter::Unescape(const char *psrc, unsigned __int64 length, Scaleform::StringBuffer *b, bool useUtf8)
{
  const char *v4; // rdi
  bool v5; // r15
  Scaleform::StringBuffer *v6; // rbp
  char *v7; // rbx
  unsigned int v8; // eax
  char *v9; // r14
  bool v10; // si
  unsigned int v11; // edx
  char *v12; // r9
  signed int v13; // er8
  char v14; // al
  unsigned __int8 v15; // al
  unsigned __int16 v16; // ax
  Scaleform::StringBuffer *v17; // rcx
  char *pStr; // [rsp+50h] [rbp+8h]

  v4 = &psrc[length];
  v5 = useUtf8;
  v6 = b;
  v7 = (char *)psrc;
  if ( psrc >= &psrc[length] )
    return 1;
  while ( 1 )
  {
    v8 = *v7++;
    pStr = v7;
    if ( v8 == 37 )
      break;
    v11 = v8;
    v17 = v6;
LABEL_29:
    Scaleform::StringBuffer::AppendChar(v17, v11);
    if ( v7 >= v4 )
      return 1;
  }
  v9 = v7;
  v10 = v5 && *v7 != 117;
  if ( *v7 == 117 )
  {
    LOWORD(v11) = 0;
    v12 = v7;
    v13 = 0;
    do
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
      ++v13;
      LOWORD(v11) = v15 | (unsigned __int16)(16 * v11);
    }
    while ( v13 < 4 );
    v11 = (unsigned __int16)v11;
    if ( v7 - v12 < 4 )
      v7 = v12;
  }
  else
  {
    v16 = Scaleform::GFx::ASUtils::AS3::Formatter::ReadHex((const char **)&pStr, v4, 2);
    v7 = pStr;
    v11 = v16;
  }
  if ( v7 != v9 )
  {
    v17 = v6;
    if ( v10 )
      v11 = (char)v11;
    goto LABEL_29;
  }
  return 0;
}

// File Line: 422
// RVA: 0x8C4920
char __fastcall Scaleform::GFx::ASUtils::AS3::Formatter::DecodeURI(const char *psrc, unsigned __int64 length, Scaleform::StringBuffer *b, bool isComp)
{
  const char *v4; // r14
  unsigned __int64 v5; // rsi
  bool v6; // r13
  Scaleform::StringBuffer *v7; // r15
  unsigned __int64 v8; // r12
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
  signed int v20; // edi
  signed int v21; // edx
  signed __int64 v22; // r9
  signed __int64 v23; // r10
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
  char v36[8]; // [rsp+60h] [rbp+8h]
  char *putf8Buffer; // [rsp+68h] [rbp+10h]

  v4 = &psrc[length];
  v5 = 0i64;
  v6 = isComp;
  v7 = b;
  v8 = length;
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
    v19 = v18 | 16 * v15;
    if ( (v19 & 0x80u) == 0 )
    {
      v20 = v19;
      goto LABEL_55;
    }
    v21 = 1;
    if ( !(v19 & 0x40) )
      return 0;
    do
      ++v21;
    while ( ((v19 << v21) & 0x80u) != 0 );
    if ( v21 == 1 )
      return 0;
    if ( v21 > 4 )
      return 0;
    v36[0] = v19;
    if ( v5 + 3 * (v21 - 1) >= v8 )
      return 0;
    v22 = 1i64;
    v23 = v21;
    while ( v22 < v23 )
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
      v32 = v31 | 16 * v28;
      if ( (v32 & 0xC0) != -128 )
        return 0;
      v36[v22++] = v32;
      v5 += 3i64;
    }
    putf8Buffer = v36;
    v20 = Scaleform::UTF8Util::DecodeNextChar_Advance0((const char **)&putf8Buffer);
    if ( v20 == 65533 )
      return 0;
LABEL_55:
    if ( (unsigned int)v20 >= 0x10000 )
      break;
    if ( !v6 && v20 < 128 )
    {
      v33 = uriReservedPlusPound[v20 / 32];
      if ( _bittest((const signed int *)&v33, v20 % -32) )
      {
        for ( ; v11 <= v5; ++v11 )
          Scaleform::StringBuffer::AppendChar(v7, v9[v11]);
        goto LABEL_67;
      }
    }
    v34 = v20;
LABEL_66:
    Scaleform::StringBuffer::AppendChar(v7, v34);
LABEL_67:
    ++v5;
    if ( v9 >= v4 )
      return 1;
  }
  if ( (unsigned int)v20 <= 0x10FFFF )
  {
    Scaleform::StringBuffer::AppendChar(v7, (((unsigned int)(v20 - 0x10000) >> 10) & 0x3FF) + 55296);
    v34 = (v20 & 0x3FF) + 56320;
    goto LABEL_66;
  }
  return 0;
}

// File Line: 611
// RVA: 0x8C8B60
void __fastcall Scaleform::GFx::ASUtils::AS3::Escape(const char *psrc, unsigned __int64 length, Scaleform::StringBuffer *b, bool useUtf8)
{
  Scaleform::GFx::ASUtils::AS3::Formatter::EscapeWithMask(psrc, length, b, unescaped_mask, useUtf8);
}

// File Line: 616
// RVA: 0x8C8400
void __fastcall Scaleform::GFx::ASUtils::AS3::EncodeVar(const char *psrc, unsigned __int64 length, Scaleform::StringBuffer *b, bool useUtf8)
{
  Scaleform::GFx::ASUtils::AS3::Formatter::EscapeWithMask(psrc, length, b, unescaped_mask_VAR, useUtf8);
}

// File Line: 621
// RVA: 0x8C83D0
bool __fastcall Scaleform::GFx::ASUtils::AS3::EncodeURI(const char *psrc, unsigned __int64 length, Scaleform::StringBuffer *escapedStr, bool isComp)
{
  return Scaleform::GFx::ASUtils::AS3::Formatter::EscapeWithMaskURI(psrc, length, escapedStr, isComp);
}

// File Line: 626
// RVA: 0x8C83E0
void __fastcall Scaleform::GFx::ASUtils::AS3::EncodeURIComponent(const char *psrc, unsigned __int64 length, Scaleform::StringBuffer *b, bool useUtf8)
{
  Scaleform::GFx::ASUtils::AS3::Formatter::EscapeWithMask(psrc, length, b, unescaped_mask_URIComponent, useUtf8);
}

// File Line: 636
// RVA: 0x914E50
bool __fastcall Scaleform::GFx::ASUtils::AS3::Unescape(const char *psrc, unsigned __int64 length, Scaleform::StringBuffer *b, bool useUtf8)
{
  return Scaleform::GFx::ASUtils::AS3::Formatter::Unescape(psrc, length, b, useUtf8);
}

// File Line: 641
// RVA: 0x8C4910
bool __fastcall Scaleform::GFx::ASUtils::AS3::DecodeURI(const char *psrc, unsigned __int64 length, Scaleform::StringBuffer *b, bool isComp)
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
char *__fastcall Scaleform::GFx::NumberUtil::ToString(long double value, char *destStr, unsigned __int64 destStrSize, int radix)
{
  unsigned __int64 v4; // r10
  const char *v5; // r8
  char *v6; // rbx
  int v7; // er9
  __int64 v8; // rax
  int v10; // ecx
  char *v11; // rcx

  v4 = destStrSize;
  v5 = fmt[13];
  v6 = destStr;
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
  if ( (*(_QWORD *)&value & 0x7FF0000000000000i64) == 9218868437227405312i64 )
  {
    if ( (*(_QWORD *)&value & 0x7FF0000000000000i64) == 9218868437227405312i64 && *(_QWORD *)&value & 0xFFFFFFFFFFFFFi64 )
    {
      strcpy_s(destStr, v4, "NaN");
      return v6;
    }
    if ( value == 1.797693134862316e308/*+Inf*/ )
    {
      strcpy_s(destStr, v4, aInfinity_2);
      return v6;
    }
    if ( value == -1.797693134862316e308/*-Inf*/ )
    {
      strcpy_s(destStr, v4, aInfinit);
      return v6;
    }
    return v6;
  }
  v10 = (signed int)value;
  if ( radix == 10 )
  {
    if ( (double)v10 == value )
      return Scaleform::GFx::NumberUtil::IntToString(v10, destStr, v4);
    Scaleform::SFsprintf(destStr, v4, v5, value);
    v11 = v6;
    if ( *v6 )
    {
      while ( (*v11 - 44) & 0xFD )
      {
        if ( !*++v11 )
          return v6;
      }
      *v11 = 46;
    }
    return v6;
  }
  return Scaleform::GFx::NumberUtil::IntToString(v10, destStr, v4, radix);
}

// File Line: 866
// RVA: 0x8E6B60
char *__fastcall Scaleform::GFx::NumberUtil::IntToString(int value, char *destStr, unsigned __int64 destStrSize, int radix)
{
  unsigned __int64 v4; // r11
  unsigned __int64 v5; // rbx
  char *v6; // rdi
  char *result; // rax
  unsigned int v8; // er10
  unsigned int v9; // edx
  char v10; // cl
  char v11; // cl
  unsigned int v12; // edx
  char v13; // cl
  const char *v14; // rdx
  signed int v15; // er8
  unsigned int v16; // er9

  v4 = destStrSize - 1;
  v5 = destStrSize;
  v6 = destStr;
  result = &destStr[destStrSize - 1];
  v8 = value;
  *result = 0;
  switch ( radix )
  {
    case 2:
      v14 = 0i64;
      v15 = 1;
      v16 = 0;
      do
      {
        if ( v16 >= v4 )
          break;
        --result;
        if ( v15 & value )
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
        ++v16;
      }
      while ( v16 < 0x20 );
      if ( v14 )
        result = (char *)v14;
      else
        result = &v6[v5 - 2];
      break;
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
      result = Scaleform::GFx::NumberUtil::IntToString(value, destStr, destStrSize);
      break;
  }
  return result;
}

// File Line: 932
// RVA: 0x8E6AD0
char *__fastcall Scaleform::GFx::NumberUtil::IntToString(int value, char *destStr, unsigned __int64 destStrSize)
{
  unsigned __int64 v3; // r11
  unsigned int v4; // er8
  char *v5; // r9
  unsigned int v6; // er10

  v3 = destStrSize - 1;
  v4 = 0;
  v5 = &destStr[v3];
  destStr[v3] = 0;
  v6 = abs(value);
  if ( v3 )
  {
    do
    {
      *--v5 = v6 % 0xA + 48;
      v6 /= 0xAu;
      if ( !v6 )
        break;
      ++v4;
    }
    while ( v4 < v3 );
  }
  if ( v4 >= v3 || value >= 0 )
    return v5;
  *(v5 - 1) = 45;
  return v5 - 1;
}

// File Line: 966
// RVA: 0x911B80
double __fastcall Scaleform::GFx::NumberUtil::StringToInt(const char *str, unsigned int strLen, int radix, unsigned int *endIndex)
{
  unsigned int *v4; // rdi
  int v5; // er14
  unsigned int v6; // er15
  const char *v7; // r12
  char v8; // r13
  char v9; // bp
  unsigned int v10; // ebx
  unsigned int v11; // esi
  signed __int64 v12; // r15
  unsigned int v13; // eax
  unsigned __int64 v14; // rcx
  __int64 v15; // rcx
  char v17; // dl
  signed int v18; // esi
  __int64 v19; // rdx
  __int64 v20; // rdx
  double v21; // xmm3_8
  double v22; // xmm2_8
  int v23; // ecx
  __int64 v24; // r8
  char v25; // cl
  signed int v26; // eax
  signed int v27; // ebx
  const char *v28; // rax
  int v29; // er9
  unsigned int v30; // er8
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
  unsigned int v44; // [rsp+78h] [rbp+10h]
  Scaleform::String v45; // [rsp+88h] [rbp+20h]

  v44 = strLen;
  v4 = endIndex;
  v5 = radix;
  v6 = strLen;
  v7 = str;
  v8 = 0;
  *endIndex = 0;
  v9 = 1;
  if ( radix )
  {
    if ( (unsigned int)(radix - 2) > 0x22 )
      return *(double *)GFxNaN_Bytes;
    v9 = 1;
    if ( radix != 16 )
      v9 = 0;
  }
  else
  {
    v5 = 10;
  }
  Scaleform::String::String(&v45, str);
  v10 = 0;
  v11 = Scaleform::String::GetLength(&v45);
  if ( v11 )
  {
    v12 = 3298534887423i64;
    do
    {
      v13 = Scaleform::String::GetCharAt(&v45, v10);
      if ( v13 != 32 && v13 - 9 > 4 )
      {
        v14 = v13 - 0x2000;
        if ( ((unsigned int)v14 > 0x29 || !_bittest64(&v12, v14)) && v13 != 8287 && v13 != 12288 )
          break;
      }
      ++v10;
    }
    while ( v10 < v11 );
    v6 = v44;
  }
  *v4 = Scaleform::UTF8Util::GetByteIndex(v10, v7, v6);
  if ( !_InterlockedDecrement((volatile signed __int32 *)((v45.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
    ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  v15 = *v4;
  if ( (_DWORD)v15 == v6 )
    return 0.0;
  v17 = v7[v15];
  if ( v17 == 45 )
  {
    v18 = -1;
  }
  else
  {
    v18 = 1;
    if ( v17 != 43 )
      goto LABEL_24;
  }
  *v4 = v15 + 1;
LABEL_24:
  if ( !v9
    || (v19 = *v4, v6 - (unsigned int)v19 <= 1)
    || v7[v19] != 48
    || (v7[(unsigned int)(v19 + 1)] - 88) & 0xDF
    || (v5 = 16, *v4 = v19 + 2, v6 != (_DWORD)v19 + 2) )
  {
    v20 = *v4;
    v21 = 0.0;
    v22 = 0.0;
    LOBYTE(v23) = 0;
    if ( (unsigned int)v20 < v6 )
    {
      do
      {
        v24 = *v4;
        v25 = v7[v24];
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
        *v4 = v24 + 1;
      }
      while ( (signed int)v24 + 1 < v6 );
    }
    if ( *v4 != (_DWORD)v20 )
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
        v28 = &v7[v20];
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
          v31 = v7[v20];
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
LABEL_105:
            v40 = (unsigned int)(v20 + 1);
            if ( (unsigned int)v40 < v6 )
            {
              v41 = &v7[v40];
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
            v35 = v7[v20];
            if ( (unsigned __int8)(v35 - 48) <= 9u )
            {
              v36 = v35 - 48;
LABEL_78:
              if ( v36 != -1 && v36 < 16 )
              {
                v34 = ((unsigned int)v36 >> 3) & 1;
                v32 = (v36 & 3) != 0;
LABEL_104:
                v8 = v27;
                goto LABEL_105;
              }
              goto LABEL_81;
            }
            if ( (unsigned __int8)(v35 - 97) <= 0x19u )
            {
              v36 = v35 - 87;
              goto LABEL_78;
            }
            if ( (unsigned __int8)(v35 - 65) <= 0x19u )
            {
              v36 = v35 - 55;
              goto LABEL_78;
            }
          }
LABEL_81:
          v32 = v33 != 0;
          goto LABEL_105;
        }
        if ( (unsigned int)v20 < v6 )
        {
          v37 = v7[v20];
          if ( (unsigned __int8)(v37 - 48) <= 9u )
          {
            v38 = v37 - 48;
LABEL_89:
            if ( v38 != -1 && v38 < 8 )
              goto LABEL_92;
            goto LABEL_91;
          }
          if ( (unsigned __int8)(v37 - 97) <= 0x19u )
          {
            v38 = v37 - 87;
            goto LABEL_89;
          }
          if ( (unsigned __int8)(v37 - 65) <= 0x19u )
          {
            v38 = v37 - 55;
            goto LABEL_89;
          }
        }
LABEL_91:
        v38 = 0;
LABEL_92:
        v33 = ((unsigned int)v38 >> 1) & 1;
LABEL_103:
        v34 = v38 & 1;
        goto LABEL_104;
      }
      v33 = v23 & 1;
      if ( (unsigned int)v20 < v6 )
      {
        v39 = v7[v20];
        if ( (unsigned __int8)(v39 - 48) <= 9u )
        {
          v38 = v39 - 48;
LABEL_100:
          if ( v38 != -1 && v38 < 2 )
            goto LABEL_103;
          goto LABEL_102;
        }
        if ( (unsigned __int8)(v39 - 97) <= 0x19u )
        {
          v38 = v39 - 87;
          goto LABEL_100;
        }
        if ( (unsigned __int8)(v39 - 65) <= 0x19u )
        {
          v38 = v39 - 55;
          goto LABEL_100;
        }
      }
LABEL_102:
      LOBYTE(v38) = 0;
      goto LABEL_103;
    }
  }
  return *(double *)GFxNaN_Bytes;
}

// File Line: 1137
// RVA: 0x9119C0
long double __fastcall Scaleform::GFx::NumberUtil::StringToDouble(const char *str, unsigned int strLen, unsigned int *endIndex)
{
  unsigned int *v3; // rdi
  __int64 v4; // r14
  const char *v5; // rsi
  unsigned int v6; // ebx
  unsigned int v7; // ebp
  signed __int64 v8; // r15
  unsigned int v9; // eax
  unsigned __int64 v10; // rcx
  __int64 v11; // rax
  unsigned int v12; // er14
  long double result; // xmm0_8
  const char *v14; // rsi
  char v15; // al
  Scaleform::String::DataDesc *v16; // rax
  char *v17; // rcx
  Scaleform::String v18; // [rsp+70h] [rbp+18h]
  char *tailptr; // [rsp+78h] [rbp+20h]

  v3 = endIndex;
  v4 = strLen;
  v5 = str;
  *endIndex = 0;
  Scaleform::String::String(&v18, str);
  v6 = 0;
  v7 = Scaleform::String::GetLength(&v18);
  if ( v7 )
  {
    v8 = 3298534887423i64;
    do
    {
      v9 = Scaleform::String::GetCharAt(&v18, v6);
      if ( v9 != 32 && v9 - 9 > 4 )
      {
        v10 = v9 - 0x2000;
        if ( ((unsigned int)v10 > 0x29 || !_bittest64(&v8, v10)) && v9 != 8287 && v9 != 12288 )
          break;
      }
      ++v6;
    }
    while ( v6 < v7 );
  }
  *v3 = Scaleform::UTF8Util::GetByteIndex(v6, v5, v4);
  if ( !_InterlockedDecrement((volatile signed __int32 *)((v18.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
    ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  v11 = *v3;
  v12 = v4 - v11;
  if ( !v12 )
  {
    v18.pData = *(Scaleform::String::DataDesc **)GFxNaN_Bytes;
    return *(double *)GFxNaN_Bytes;
  }
  tailptr = 0i64;
  v14 = &v5[v11];
  if ( v12 > 1 )
  {
    v15 = *v14;
    if ( *v14 == 43 )
    {
      if ( !strncmp(v14, "+Infinity", 9ui64) )
      {
        *v3 += 9;
        goto LABEL_20;
      }
    }
    else if ( v15 == 45 )
    {
      if ( !strncmp(v14, aInfinit, 9ui64) )
      {
        *v3 += 9;
        v16 = *(Scaleform::String::DataDesc **)GFxNEGATIVE_INFINITY_Bytes;
        goto LABEL_21;
      }
    }
    else if ( v15 == 73 && !strncmp(v14, aInfinity_2, 8ui64) )
    {
      *v3 += 8;
LABEL_20:
      v16 = *(Scaleform::String::DataDesc **)GFxPOSITIVE_INFINITY_Bytes;
LABEL_21:
      v18.pData = v16;
      return *(double *)&v16;
    }
  }
  result = Scaleform::SFstrtod(v14, &tailptr);
  v17 = tailptr;
  *v3 += (_DWORD)tailptr - (_DWORD)v14;
  if ( v17 == v14 )
    result = *(double *)GFxNaN_Bytes;
  return result;
}

