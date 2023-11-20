// File Line: 27
// RVA: 0x187C40
void __fastcall UFG::qMemMove(void *dest, const void *source, unsigned int count)
{
  char *v3; // r9
  char *v4; // rdx
  char *i; // rcx
  char v6; // al
  signed __int64 v7; // rcx
  char v8; // al

  if ( dest <= source || (v3 = (char *)source + count, dest >= v3) )
  {
    if ( count )
    {
      v7 = (_BYTE *)dest - (_BYTE *)source;
      do
      {
        v8 = *(_BYTE *)source;
        source = (char *)source + 1;
        *((char *)source + v7 - 1) = v8;
        --count;
      }
      while ( count );
    }
  }
  else
  {
    v4 = v3 - 1;
    for ( i = (char *)dest + count - 1; count; --count )
    {
      v6 = *v4;
      --i;
      --v4;
      i[1] = v6;
    }
  }
}

// File Line: 62
// RVA: 0x1835F0
void __fastcall UFG::qEndianSwapBytes(char *v, unsigned int num_bytes)
{
  char *i; // r8
  char v3; // al
  char v4; // dl

  if ( num_bytes >= 2 )
  {
    for ( i = &v[num_bytes - 1]; v < i; ++v )
    {
      v3 = *i;
      v4 = *v;
      --i;
      *v = v3;
      i[1] = v4;
    }
  }
}

// File Line: 100
// RVA: 0x18BAB0
char __fastcall UFG::qToBool(const char *text, bool default_value)
{
  bool v2; // bl
  char v3; // r9
  int v4; // eax
  char v5; // cl

  v2 = default_value;
  if ( !text )
    return default_value;
  v3 = *text;
  if ( !*text )
    return default_value;
  if ( *text <= 122 && *text >= 97 )
    v3 -= 32;
  if ( v3 == 84 || v3 == 49 )
    return 1;
  if ( v3 == 70 || v3 == 48 )
    return 0;
  v4 = UFG::qToInt32(text, 0);
  v5 = v2;
  if ( v4 )
    v5 = 1;
  return v5;
}

// File Line: 114
// RVA: 0x15FE00
signed __int64 __fastcall UFG::qToInt<unsigned __int64>(const char *text)
{
  char v1; // dl
  signed __int64 v2; // r8
  const char *v3; // r9
  const char *v4; // r9
  char v5; // al
  __int64 v6; // rcx
  int v8; // eax

  v1 = *text;
  v2 = 0i64;
  v3 = text;
  if ( *text != 48 || (text[1] - 88) & 0xDF )
  {
    if ( v1 != 35 )
    {
      for ( ; v1; v2 = v8 - 48 + 10 * v2 )
      {
        if ( v1 > 57 || v1 < 48 )
          break;
        v8 = v1;
        v1 = (v3++)[1];
      }
      return v2;
    }
    v4 = text + 1;
  }
  else
  {
    v4 = text + 2;
  }
  v5 = *v4;
  if ( !*v4 )
    return v2;
  do
  {
    if ( v5 <= 57 && v5 >= 48 )
    {
      v6 = (unsigned int)(v5 - 48);
    }
    else
    {
      if ( v5 <= 122 && v5 >= 97 )
        v5 -= 32;
      if ( (unsigned __int8)(v5 - 65) > 5u )
        return v2;
      v6 = (unsigned int)(v5 - 55);
    }
    v5 = (v4++)[1];
    v2 = v6 + 16 * v2;
  }
  while ( v5 );
  return v2;
}

// File Line: 214
// RVA: 0x18BEA0
__int64 __fastcall UFG::qToInt32(const char *text, int default_value)
{
  unsigned int v2; // er9
  const char *v3; // r8
  char v4; // dl

  v2 = default_value;
  v3 = text;
  if ( !text )
    return v2;
  v4 = *text;
  if ( !*text )
    return v2;
  if ( *text <= 57 && *text >= 48 )
    goto LABEL_15;
  if ( v4 == 45 )
    return (unsigned int)-UFG::qToInt<long>(text + 1);
  if ( v4 != 43 )
    return v2;
LABEL_15:
  if ( v4 == 45 )
    return (unsigned int)-UFG::qToInt<long>(text + 1);
  if ( v4 == 43 )
    v3 = text + 1;
  return UFG::qToInt<long>(v3);
}

// File Line: 219
// RVA: 0x18C2C0
__int64 __fastcall UFG::qToUInt32(const char *text, unsigned int default_value)
{
  char v2; // r8
  __int64 result; // rax
  const char *v4; // r9

  v2 = *text;
  result = default_value;
  v4 = text;
  if ( *text <= 57 && *text >= 48 || v2 == 35 )
  {
    if ( v2 != 43 )
      return UFG::qToInt<long>(v4);
LABEL_6:
    v4 = text + 1;
    return UFG::qToInt<long>(v4);
  }
  if ( v2 == 43 )
    goto LABEL_6;
  return result;
}

// File Line: 224
// RVA: 0x18BF10
__int64 __fastcall UFG::qToInt64(const char *text, __int64 default_value)
{
  __int64 v2; // r9
  const char *v3; // r8
  char v4; // dl

  v2 = default_value;
  v3 = text;
  if ( !text )
    return v2;
  v4 = *text;
  if ( !*text )
    return v2;
  if ( *text <= 57 && *text >= 48 )
    goto LABEL_15;
  if ( v4 == 45 )
    return -UFG::qToInt<unsigned __int64>(text + 1);
  if ( v4 != 43 )
    return v2;
LABEL_15:
  if ( v4 == 45 )
    return -UFG::qToInt<unsigned __int64>(text + 1);
  if ( v4 == 43 )
    v3 = text + 1;
  return UFG::qToInt<unsigned __int64>(v3);
}

// File Line: 229
// RVA: 0x18C300
unsigned __int64 __fastcall UFG::qToUInt64(const char *text, unsigned __int64 default_value)
{
  char v2; // r8
  unsigned __int64 result; // rax
  const char *v4; // r9

  v2 = *text;
  result = default_value;
  v4 = text;
  if ( *text <= 57 && *text >= 48 || v2 == 35 )
  {
    if ( v2 != 43 )
      return UFG::qToInt<unsigned __int64>(v4);
LABEL_6:
    v4 = text + 1;
    return UFG::qToInt<unsigned __int64>(v4);
  }
  if ( v2 == 43 )
    goto LABEL_6;
  return result;
}

// File Line: 234
// RVA: 0x18BB40
float __fastcall UFG::qToFloat(const char *text, float default_value)
{
  const char *v2; // r8
  char v3; // cl
  char v4; // bl
  char v5; // dl
  float v6; // xmm2_4
  float i; // xmm8_4
  int v8; // eax
  float v9; // xmm6_4
  char v10; // dl
  float v11; // xmm1_4
  float v12; // xmm3_4
  int v13; // eax
  float v14; // xmm0_4
  int v15; // eax
  int v16; // edx
  unsigned int v17; // ecx
  __int64 v18; // rax
  unsigned int v19; // eax
  __int64 v20; // rcx
  __int64 v21; // rax

  v2 = text;
  if ( !text )
    return default_value;
  v3 = *text;
  if ( !v3 || (v3 > 57 || v3 < 48) && ((v3 - 43) & 0xFC || v3 == 44) )
    return default_value;
  v4 = 0;
  if ( v3 == 45 )
  {
    v4 = 1;
LABEL_9:
    ++v2;
    goto LABEL_10;
  }
  if ( v3 == 43 )
    goto LABEL_9;
LABEL_10:
  v5 = *v2;
  v6 = 0.0;
  for ( i = 0.0; *v2 <= 57 && *v2 >= 48; i = (float)(v8 - 48) + (float)(i * 10.0) )
  {
    ++v2;
    v8 = v5;
    v5 = *v2;
  }
  v9 = *(float *)&FLOAT_1_0;
  if ( *v2 == 46 )
  {
    v10 = (v2++)[1];
    v11 = 0.0;
    v12 = *(float *)&FLOAT_1_0;
    if ( v10 <= 57 && v10 >= 48 )
    {
      do
      {
        ++v2;
        v13 = v10;
        v10 = *v2;
        v12 = v12 * 10.0;
        v14 = (float)(v13 - 48) + (float)(v11 * 10.0);
        v11 = (float)(v13 - 48) + (float)(v11 * 10.0);
      }
      while ( *v2 <= 57 && *v2 >= 48 );
      if ( v14 != 0.0 )
        v6 = v14 / v12;
    }
    i = i + v6;
  }
  if ( !((*v2 - 69) & 0xDF) )
  {
    v15 = UFG::qToInt32(v2 + 1, 0);
    v16 = v15;
    if ( v15 >= 8 )
    {
      v17 = ((unsigned int)(v15 - 8) >> 3) + 1;
      v18 = v17;
      v16 -= 8 * v17;
      do
      {
        v9 = (float)((float)((float)((float)((float)((float)((float)(v9 * 10.0) * 10.0) * 10.0) * 10.0) * 10.0) * 10.0)
                   * 10.0)
           * 10.0;
        --v18;
      }
      while ( v18 );
    }
    for ( ; v16 > 0; v9 = v9 * 10.0 )
      --v16;
    if ( -v16 >= 8 )
    {
      v19 = ((unsigned int)(-8 - v16) >> 3) + 1;
      v20 = v19;
      v16 += 8 * v19;
      do
      {
        v9 = (float)((float)((float)((float)((float)((float)((float)(v9 * 0.1) * 0.1) * 0.1) * 0.1) * 0.1) * 0.1) * 0.1)
           * 0.1;
        --v20;
      }
      while ( v20 );
    }
    if ( v16 < 0 )
    {
      v21 = -v16;
      do
      {
        v9 = v9 * 0.1;
        --v21;
      }
      while ( v21 );
    }
    i = i * v9;
  }
  if ( v4 )
    LODWORD(i) ^= _xmm[0];
  return i;
}

// File Line: 370
// RVA: 0x18C230
void __fastcall UFG::qToStringHex(char *buffer, unsigned __int64 buffer_size, unsigned __int64 val, unsigned __int64 sizeof_val, bool add_prefix)
{
  char *v5; // r11
  __int64 v6; // rcx
  unsigned __int64 v7; // rbx
  unsigned __int64 v8; // r8
  const char *v9; // r10
  unsigned __int64 v10; // r9
  signed __int64 v11; // rdx
  unsigned __int64 v12; // rax

  v5 = buffer;
  v6 = 0i64;
  v7 = val;
  if ( buffer_size != 0 && v5 != 0i64 )
  {
    v8 = 2 * sizeof_val;
    *v5 = 0;
    if ( buffer_size >= 2 * sizeof_val + 1 )
    {
      if ( add_prefix )
      {
        *(_WORD *)v5 = 30768;
        v5 += 2;
      }
      if ( v8 )
      {
        v9 = value_character;
        v10 = 2 * sizeof_val;
        v11 = (signed __int64)&v5[v8 - 1];
        do
        {
          --v11;
          v12 = v7 >> v6;
          v6 += 4i64;
          *(_BYTE *)(v11 + 1) = v9[v12 & 0xF];
          --v10;
        }
        while ( v10 );
      }
      v5[v8] = 0;
    }
  }
}

// File Line: 406
// RVA: 0x15FCB0
UFG::qString *__fastcall UFG::qIntToHex<unsigned __int64>(UFG::qString *result, unsigned __int64 val)
{
  UFG::qString *v2; // rbx
  signed int v3; // ecx
  char *v4; // r8
  const char *v5; // r9
  char format[2]; // [rsp+30h] [rbp-28h]
  char v8; // [rsp+41h] [rbp-17h]
  char v9; // [rsp+42h] [rbp-16h]

  v2 = result;
  v3 = 0;
  *(_WORD *)format = 30768;
  v4 = &v8;
  v5 = `UFG::qIntToHex<unsigned __int64>'::`2'::value_character;
  do
  {
    *v4 = v5[(val >> v3) & 0xF];
    v3 += 4;
    --v4;
  }
  while ( v3 < 64 );
  v9 = 0;
  UFG::qString::qString(v2, format, v4);
  return v2;
}

// File Line: 427
// RVA: 0x18BE20
UFG::qString *__fastcall UFG::qToHex(UFG::qString *result, __int64 val)
{
  UFG::qString *v2; // rbx

  v2 = result;
  UFG::qIntToHex<__int64>(result, val);
  return v2;
}

// File Line: 432
// RVA: 0x18BE60
UFG::qString *__fastcall UFG::qToHex(UFG::qString *result, unsigned __int64 val)
{
  UFG::qString *v2; // rbx

  v2 = result;
  UFG::qIntToHex<unsigned __int64>(result, val);
  return v2;
}

// File Line: 437
// RVA: 0x18BDA0
UFG::qString *__fastcall UFG::qToHex(UFG::qString *result, int val)
{
  UFG::qString *v2; // rbx

  v2 = result;
  UFG::qIntToHex<long>(result, val);
  return v2;
}

// File Line: 442
// RVA: 0x18BDE0
UFG::qString *__fastcall UFG::qToHex(UFG::qString *result, unsigned int val)
{
  UFG::qString *v2; // rbx

  v2 = result;
  UFG::qIntToHex<unsigned long>(result, val);
  return v2;
}

// File Line: 472
// RVA: 0x18BF80
UFG::qString *__fastcall UFG::qToString(UFG::qString *result, UFG::qDateTime *date_time, UFG::DateTimeFormat format, UFG::DateTimeFormatFlags flags)
{
  UFG::qDateTime *v4; // rbx
  UFG::qString *v5; // rdi
  __int32 v6; // er9
  const char *v7; // r11
  const char *v8; // rsi
  const char *v9; // rbp
  const char *v10; // r10
  signed int v11; // er8
  unsigned int v12; // edx
  __int64 v14; // [rsp+20h] [rbp-D8h]
  __int64 v15; // [rsp+28h] [rbp-D0h]
  __int64 v16; // [rsp+30h] [rbp-C8h]
  __int64 v17; // [rsp+38h] [rbp-C0h]
  __int64 v18; // [rsp+40h] [rbp-B8h]
  __int64 v19; // [rsp+48h] [rbp-B0h]
  __int64 v20; // [rsp+58h] [rbp-A0h]
  _QWORD v21[2]; // [rsp+60h] [rbp-98h]
  const char *v22; // [rsp+70h] [rbp-88h]
  const char *v23; // [rsp+78h] [rbp-80h]
  const char *v24; // [rsp+80h] [rbp-78h]
  const char *v25; // [rsp+88h] [rbp-70h]
  const char *v26; // [rsp+90h] [rbp-68h]
  const char *v27; // [rsp+98h] [rbp-60h]
  const char *v28; // [rsp+A0h] [rbp-58h]
  const char *v29; // [rsp+A8h] [rbp-50h]
  const char *v30; // [rsp+B0h] [rbp-48h]
  const char *v31; // [rsp+B8h] [rbp-40h]
  const char *v32; // [rsp+C0h] [rbp-38h]
  const char *v33; // [rsp+C8h] [rbp-30h]
  const char *v34; // [rsp+D0h] [rbp-28h]
  __int64 v35; // [rsp+E0h] [rbp-18h]

  v35 = -2i64;
  v4 = date_time;
  v5 = result;
  v6 = flags & 1;
  v7 = ",";
  if ( v6 )
    v7 = " ";
  v8 = ":";
  if ( v6 )
    v8 = "-";
  v9 = ".";
  if ( v6 )
    v9 = "-";
  result->mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&result->mPrev;
  result->mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&result->mPrev;
  result->mMagic = 16909060;
  result->mData = (char *)UFG::qString::sEmptyString;
  result->mLength = 0;
  *(_QWORD *)&result->mStringHash32 = -1i64;
  LODWORD(v21[0]) = 1;
  if ( format )
  {
    if ( format == 1 )
    {
      LODWORD(v19) = date_time->mSecond;
      LODWORD(v17) = date_time->mMinute;
      LODWORD(v15) = date_time->mHour;
      LODWORD(v14) = date_time->mDay;
      UFG::qString::Format(
        result,
        "%04d-%02d-%02d %02d%s%02d%s%02d",
        date_time->mYear,
        date_time->mMonth,
        v14,
        v15,
        v8,
        v17,
        v8,
        v19);
    }
    else if ( (unsigned int)(format - 2) <= 1 )
    {
      v22 = "<invalid>";
      v23 = "Jan";
      v24 = "Feb";
      v25 = "March";
      v26 = "April";
      v27 = "May";
      v28 = "June";
      v29 = "July";
      v30 = "Aug";
      v31 = "Sept";
      v32 = "Oct";
      v33 = "Nov";
      v34 = "Dec";
      v10 = "am";
      v11 = date_time->mMonth;
      if ( v11 <= 0 )
      {
        v11 = 0;
      }
      else if ( v11 >= 12 )
      {
        v11 = 12;
      }
      v12 = date_time->mHour;
      if ( (_WORD)v12 )
      {
        if ( v12 >= 0xC )
        {
          v12 -= 12;
          v10 = "pm";
        }
      }
      else
      {
        v12 = 12;
      }
      LODWORD(v18) = v4->mMinute;
      LODWORD(v16) = v12;
      LODWORD(v15) = v4->mYear;
      UFG::qString::Format(result, "%s %2d%s %4d %2d%s%02d %s", (&v22)[v11], v4->mDay, v7, v15, v16, v8, v18, v10);
    }
  }
  else
  {
    LODWORD(v20) = date_time->mMillisecond;
    LODWORD(v19) = date_time->mSecond;
    LODWORD(v17) = date_time->mMinute;
    LODWORD(v15) = date_time->mHour;
    LODWORD(v14) = date_time->mDay;
    UFG::qString::Format(
      result,
      "%04d-%02d-%02d %02d%s%02d%s%02d%s%03d",
      date_time->mYear,
      date_time->mMonth,
      v14,
      v15,
      v8,
      v17,
      v8,
      v19,
      v9,
      v20,
      v21[0]);
  }
  return v5;
}

// File Line: 812
// RVA: 0x18B0D0
signed __int64 __fastcall UFG::qStringCompareInsensitive(const char *text_a, const char *text_b, int count)
{
  int v3; // er9
  const char *v4; // r10
  signed __int64 v5; // r11
  unsigned __int8 v6; // al
  unsigned __int8 v7; // r8

  v3 = count;
  v4 = text_b;
  if ( !text_a || !text_b )
    return 0xFFFFFFFFi64;
  if ( count < 0 )
    v3 = -1;
  if ( !v3 )
    return 0i64;
  v5 = text_a - text_b;
  while ( 1 )
  {
    v6 = v4[v5];
    if ( v4[v5] <= 122 && v4[v5] >= 97 )
      v6 -= 32;
    v7 = *v4;
    if ( *v4 <= 122 && *v4 >= 97 )
      v7 -= 32;
    if ( !v6 || v6 != v7 )
      break;
    ++v4;
    if ( !--v3 )
      return 0i64;
  }
  return v6 - (unsigned int)v7;
}

// File Line: 837
// RVA: 0x18B080
signed __int64 __fastcall UFG::qStringCompare(const char *text_a, const char *text_b, int count)
{
  if ( !text_a || !text_b )
    return 0xFFFFFFFFi64;
  if ( count < 0 )
    count = -1;
  if ( !count )
    return 0i64;
  while ( *text_a && *text_a == *text_b )
  {
    ++text_a;
    ++text_b;
    if ( !--count )
      return 0i64;
  }
  return *(unsigned __int8 *)text_a - (unsigned int)*(unsigned __int8 *)text_b;
}

// File Line: 864
// RVA: 0x18B170
char *__fastcall UFG::qStringCopy(char *dest, int dest_size, const char *text, int text_count)
{
  char *v4; // r10
  char *v6; // rax
  signed __int64 v7; // r8
  char v8; // cl

  v4 = dest;
  if ( !dest )
    return 0i64;
  if ( dest_size <= 0 )
    return dest;
  if ( !text || !text_count )
  {
    *dest = 0;
    return dest;
  }
  v6 = dest;
  if ( text_count >= 0 )
  {
    if ( text_count >= dest_size )
      text_count = dest_size - 1;
    for ( ; text_count; --text_count )
    {
      if ( !*text )
        break;
      *v6++ = *text++;
    }
    *v6 = 0;
  }
  else
  {
    v7 = text - dest;
    do
    {
      v8 = (v6++)[v7];
      *(v6 - 1) = v8;
      if ( !v8 )
        break;
      --dest_size;
    }
    while ( dest_size > 1 );
    if ( *(v6 - 1) )
    {
      *v6 = 0;
      return v4;
    }
  }
  return v4;
}

// File Line: 915
// RVA: 0x18B7E0
signed __int64 __fastcall UFG::qStringLength(const char *text)
{
  const char *v1; // rdx
  const char *v3; // rax
  char v4; // cl

  v1 = text;
  if ( !text )
    return 0i64;
  v3 = text;
  do
    v4 = *v3++;
  while ( v4 );
  return v3 - v1 - 1;
}

// File Line: 929
// RVA: 0x18B810
signed __int64 __fastcall UFG::qStringLength(const wchar_t *text)
{
  const wchar_t *v1; // rdx
  const wchar_t *v3; // rax
  wchar_t v4; // cx

  v1 = text;
  if ( !text )
    return 0i64;
  v3 = text;
  do
  {
    v4 = *v3;
    ++v3;
  }
  while ( v4 );
  return v3 - v1 - 1;
}

// File Line: 944
// RVA: 0x18CAB0
char *__fastcall UFG::qWideStringCopy(char *dest, int dest_size, const wchar_t *text, int text_count)
{
  signed int v4; // er10
  char *v5; // rdx
  char v6; // al
  char v8; // al

  v4 = dest_size;
  if ( !dest || dest_size <= 0 )
    return dest;
  if ( !text || !text_count )
  {
    *dest = 0;
    return dest;
  }
  v5 = dest;
  if ( text_count < 0 )
  {
    do
    {
      v6 = *(_BYTE *)text;
      ++v5;
      ++text;
      *(v5 - 1) = v6;
      if ( !v6 )
        break;
      --v4;
    }
    while ( v4 > 1 );
    if ( *(v5 - 1) )
    {
      *v5 = 0;
      return dest;
    }
    return dest;
  }
  if ( text_count >= v4 )
    text_count = v4 - 1;
  for ( ; text_count; --text_count )
  {
    if ( !*text )
      break;
    v8 = *(_BYTE *)text;
    ++v5;
    ++text;
    *(v5 - 1) = v8;
  }
  *v5 = 0;
  return dest;
}

// File Line: 1041
// RVA: 0x18CB30
char *__fastcall UFG::qWideStringCopy(char *dest, const wchar_t *src)
{
  char v2; // al
  char *v3; // r8
  char v4; // al

  if ( dest )
  {
    if ( src )
    {
      v2 = *(_BYTE *)src;
      *dest = *(_BYTE *)src;
      if ( v2 )
      {
        v3 = dest;
        do
        {
          v4 = *((_BYTE *)src + 2);
          ++src;
          *++v3 = v4;
        }
        while ( v4 );
      }
    }
  }
  return dest;
}

// File Line: 1054
// RVA: 0x18CB70
wchar_t *__fastcall UFG::qWideStringCopy(wchar_t *dest, const char *src)
{
  wchar_t v2; // ax
  wchar_t *v3; // r8
  wchar_t v4; // ax

  if ( dest )
  {
    if ( src )
    {
      v2 = *src;
      *dest = v2;
      if ( v2 )
      {
        v3 = dest;
        do
        {
          v4 = (src++)[1];
          ++v3;
          *v3 = v4;
        }
        while ( v4 );
      }
    }
  }
  return dest;
}

// File Line: 1068
// RVA: 0x18B2C0
char *__fastcall UFG::qStringFind(const char *text, int text_length, const char *find, int find_length, int insensitive)
{
  int v5; // er14
  const char *v6; // rbp
  const char *v7; // rdi
  int v8; // esi
  int v9; // ebx
  const char *v10; // rcx
  unsigned int v11; // eax

  v5 = find_length;
  v6 = find;
  v7 = text;
  if ( !text || !*text || !text_length || !find || !*find || !find_length )
    return 0i64;
  v8 = text_length - find_length;
  v9 = 0;
  if ( text_length - find_length < 0 )
    return 0i64;
  while ( 1 )
  {
    v10 = &v7[v9];
    v11 = insensitive ? (unsigned int)UFG::qStringCompareInsensitive(v10, v6, v5) : (unsigned int)UFG::qStringCompare(
                                                                                                    v10,
                                                                                                    v6,
                                                                                                    v5);
    if ( !v11 )
      break;
    if ( ++v9 > v8 )
      return 0i64;
  }
  return (char *)&v7[v9];
}

// File Line: 1146
// RVA: 0x18B200
char *__fastcall UFG::qStringFind(const char *text, const char *find)
{
  const char *v2; // rbp
  const char *v3; // r14
  int v4; // ebx
  const char *v5; // rbx
  char v6; // al
  char v7; // al
  int v8; // esi
  int v9; // edi

  v2 = find;
  v3 = text;
  if ( find )
  {
    v5 = find;
    do
      v6 = *v5++;
    while ( v6 );
    v4 = (_DWORD)v5 - (_DWORD)find - 1;
  }
  else
  {
    v4 = 0;
  }
  if ( !text )
    return 0i64;
  do
    v7 = *text++;
  while ( v7 );
  if ( !*v3 || (_DWORD)text - (_DWORD)v3 == 1 || !find || !*find || !v4 )
    return 0i64;
  v8 = (_DWORD)text - (_DWORD)v3 - 1 - v4;
  v9 = 0;
  if ( v8 < 0 )
    return 0i64;
  while ( (unsigned int)UFG::qStringCompare(&v3[v9], v2, v4) )
  {
    if ( ++v9 > v8 )
      return 0i64;
  }
  return (char *)&v3[v9];
}

// File Line: 1148
// RVA: 0x18B370
char *__fastcall UFG::qStringFindInsensitive(const char *text, const char *find)
{
  const char *v2; // rbp
  const char *v3; // r14
  int v4; // ebx
  const char *v5; // rbx
  char v6; // al
  char v7; // al
  int v8; // esi
  int v9; // edi

  v2 = find;
  v3 = text;
  if ( find )
  {
    v5 = find;
    do
      v6 = *v5++;
    while ( v6 );
    v4 = (_DWORD)v5 - (_DWORD)find - 1;
  }
  else
  {
    v4 = 0;
  }
  if ( !text )
    return 0i64;
  do
    v7 = *text++;
  while ( v7 );
  if ( !*v3 || (_DWORD)text - (_DWORD)v3 == 1 || !find || !*find || !v4 )
    return 0i64;
  v8 = (_DWORD)text - (_DWORD)v3 - 1 - v4;
  v9 = 0;
  if ( v8 < 0 )
    return 0i64;
  while ( (unsigned int)UFG::qStringCompareInsensitive(&v3[v9], v2, v4) )
  {
    if ( ++v9 > v8 )
      return 0i64;
  }
  return (char *)&v3[v9];
}

// File Line: 1182
// RVA: 0x18B430
char *__fastcall UFG::qStringFindLast(const char *text, const char *find)
{
  const char *v2; // rbx
  const char *v3; // r11
  int v4; // er9
  const char *v5; // r9
  char v6; // al
  const char *v7; // r10
  char v8; // al
  signed int v9; // er10
  int v10; // er9
  const char *v11; // rdx
  const char *v12; // rcx
  signed int v13; // eax

  v2 = find;
  v3 = text;
  if ( !find || !*find )
    return 0i64;
  if ( text )
  {
    v5 = text;
    do
      v6 = *v5++;
    while ( v6 );
    v4 = (_DWORD)v5 - (_DWORD)text - 1;
  }
  else
  {
    v4 = 0;
  }
  v7 = find;
  do
    v8 = *v7++;
  while ( v8 );
  v9 = (_DWORD)v7 - (_DWORD)find - 1;
  v10 = v4 - v9;
  if ( v10 < 0 )
    return 0i64;
  while ( 1 )
  {
    v11 = v2;
    v12 = &v3[v10];
    if ( v12 )
    {
      v13 = v9;
      if ( v9 < 0 )
        v13 = -1;
      if ( !v13 )
        break;
      while ( *v12 && *v12 == *v11 )
      {
        ++v12;
        ++v11;
        if ( !--v13 )
          return (char *)&v3[v10];
      }
      if ( *(unsigned __int8 *)v12 == *(unsigned __int8 *)v11 )
        break;
    }
    if ( --v10 < 0 )
      return 0i64;
  }
  return (char *)&v3[v10];
}

// File Line: 1183
// RVA: 0x18B500
char *__fastcall UFG::qStringFindLast(const char *text, const char c)
{
  const char *v2; // r11
  int v3; // er9
  const char *v4; // r9
  char v5; // al
  char *v6; // r10
  char v7; // al
  signed int v8; // er10
  int v9; // er9
  char *v10; // rdx
  const char *v11; // rcx
  signed int v12; // eax
  char v14; // [rsp+18h] [rbp+10h]
  char v15; // [rsp+19h] [rbp+11h]

  v2 = text;
  v14 = c;
  v15 = 0;
  if ( !c )
    return 0i64;
  if ( text )
  {
    v4 = text;
    do
      v5 = *v4++;
    while ( v5 );
    v3 = (_DWORD)v4 - (_DWORD)text - 1;
  }
  else
  {
    v3 = 0;
  }
  v6 = &v14;
  do
    v7 = *v6++;
  while ( v7 );
  v8 = (_DWORD)v6 - (unsigned __int64)&v14 - 1;
  v9 = v3 - v8;
  if ( v9 < 0 )
    return 0i64;
  while ( 1 )
  {
    v10 = &v14;
    v11 = &v2[v9];
    if ( v11 )
    {
      v12 = v8;
      if ( v8 < 0 )
        v12 = -1;
      if ( !v12 )
        break;
      while ( *v11 && *v11 == *v10 )
      {
        ++v11;
        ++v10;
        if ( !--v12 )
          return (char *)&v2[v9];
      }
      if ( *(unsigned __int8 *)v11 == (unsigned __int8)*v10 )
        break;
    }
    if ( --v9 < 0 )
      return 0i64;
  }
  return (char *)&v2[v9];
}

// File Line: 1184
// RVA: 0x18B5E0
char *__fastcall UFG::qStringFindLastInsensitive(const char *text, const char *find)
{
  const char *v2; // rbp
  const char *v3; // rsi
  int v4; // ebx
  const char *v5; // rbx
  char v6; // al
  const char *v7; // rdi
  char v8; // al
  int v9; // edi
  int v10; // ebx

  v2 = find;
  v3 = text;
  if ( !find || !*find )
    return 0i64;
  if ( text )
  {
    v5 = text;
    do
      v6 = *v5++;
    while ( v6 );
    v4 = (_DWORD)v5 - (_DWORD)text - 1;
  }
  else
  {
    v4 = 0;
  }
  v7 = find;
  do
    v8 = *v7++;
  while ( v8 );
  v9 = (_DWORD)v7 - (_DWORD)find - 1;
  v10 = v4 - v9;
  if ( v10 < 0 )
    return 0i64;
  while ( (unsigned int)UFG::qStringCompareInsensitive(&v3[v10], v2, v9) )
  {
    if ( --v10 < 0 )
      return 0i64;
  }
  return (char *)&v3[v10];
}

// File Line: 1202
// RVA: 0x18B840
char *__fastcall UFG::qStringToLower(char *text)
{
  char *i; // r8
  char v2; // al

  if ( text && *text )
  {
    for ( i = text; ; ++i )
    {
      v2 = *i;
      if ( *i <= 90 && *i >= 65 )
        v2 += 32;
      *i = v2;
      if ( !v2 )
        break;
    }
  }
  return text;
}

// File Line: 1217
// RVA: 0x187730
_BOOL8 __fastcall UFG::qIsWhitespace(__int64 c)
{
  signed __int64 v1; // rax
  _BOOL8 result; // rax

  result = 0;
  if ( (unsigned __int8)c <= 0x20u )
  {
    v1 = 6174031360i64;
    if ( _bittest64(&v1, c) )
      result = 1;
  }
  return result;
}

// File Line: 1292
// RVA: 0x18CBB0
signed __int64 __fastcall UFG::qWildcardMatchInsensitive(const char *pattern, const char *text)
{
  char v2; // r10
  unsigned int v3; // ebx
  const char *v4; // r8
  signed __int64 v5; // rdi
  const char *v6; // rsi
  char v7; // r9
  int v8; // er11
  int v9; // eax
  char i; // r10
  char v12; // r9
  int v13; // er11
  int v14; // eax

  v2 = *text;
  v3 = 0;
  v4 = text;
  v5 = 0i64;
  v6 = 0i64;
  if ( *text )
  {
    while ( 1 )
    {
      v7 = *pattern;
      if ( *pattern == 42 )
        break;
      v8 = v7;
      if ( *pattern <= 122 && *pattern >= 97 )
        v8 = v7 - 32;
      v9 = v2;
      if ( v2 <= 122 && v2 >= 97 )
        v9 = v2 - 32;
      if ( v8 != v9 && v7 != 63 )
        return 0i64;
      v2 = (v4++)[1];
      ++pattern;
      if ( !v2 )
        goto LABEL_10;
    }
    for ( i = *v4; *v4; i = *v4 )
    {
      v12 = *pattern;
      if ( *pattern == 42 )
      {
        if ( !*++pattern )
          return 1i64;
        v6 = pattern;
        v5 = (signed __int64)(v4 + 1);
      }
      else
      {
        v13 = v12;
        if ( *pattern <= 122 && *pattern >= 97 )
          v13 = v12 - 32;
        v14 = i;
        if ( i <= 122 && i >= 97 )
          v14 = i - 32;
        if ( v13 == v14 || v12 == 63 )
        {
          ++pattern;
          ++v4;
        }
        else
        {
          v4 = (const char *)v5;
          pattern = v6;
          ++v5;
        }
      }
    }
  }
LABEL_10:
  while ( *pattern == 42 )
    ++pattern;
  LOBYTE(v3) = *pattern == 0;
  return v3;
}

// File Line: 1352
// RVA: 0x1620A0
void __fastcall UFG::qString::qString(UFG::qString *this)
{
  this->mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&this->mPrev;
  this->mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&this->mPrev;
  this->mMagic = 0x1020304;
  this->mData = (char *)UFG::qString::sEmptyString;
  this->mLength = 0;
  *(_QWORD *)&this->mStringHash32 = -1i64;
}

// File Line: 1367
// RVA: 0x161F50
void __fastcall UFG::qString::qString(UFG::qString *this, UFG::qString *text)
{
  UFG::qString *v2; // rbx
  UFG::qString *v3; // rdi

  v2 = text;
  v3 = this;
  this->mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&this->mPrev;
  this->mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&this->mPrev;
  this->mMagic = 16909060;
  this->mData = (char *)UFG::qString::sEmptyString;
  this->mLength = 0;
  UFG::qString::Set(this, text->mData, text->mLength, 0i64, 0);
  v3->mStringHash32 = v2->mStringHash32;
  v3->mStringHashUpper32 = v2->mStringHashUpper32;
}

// File Line: 1407
// RVA: 0x161FC0
void UFG::qString::qString(UFG::qString *this, const char *format, ...)
{
  UFG::qString *v2; // rbx
  int v3; // eax
  UFG::qPrintInfo info; // [rsp+40h] [rbp-2138h]
  char text; // [rsp+170h] [rbp-2008h]
  va_list va; // [rsp+2190h] [rbp+18h]

  va_start(va, format);
  v2 = this;
  this->mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&this->mPrev;
  this->mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&this->mPrev;
  this->mMagic = 16909060;
  this->mData = (char *)UFG::qString::sEmptyString;
  this->mLength = 0;
  *(_QWORD *)&this->mStringHash32 = -1i64;
  if ( format )
  {
    info.mStdOutBuffer.NumChars = 0;
    info.OutString = &text;
    info.OutStringLen = 0x2000;
    info.PrintChannel = -1;
    info.StdOut = 0;
    v3 = UFG::qPrintEngine(&info, format, va);
    if ( v3 )
      UFG::qString::Set(v2, &text, v3, 0i64, 0);
  }
}

// File Line: 1463
// RVA: 0x16E480
UFG::qString *UFG::qString::FormatEx(UFG::qString *result, const char *format, ...)
{
  UFG::qString *v2; // rbx
  UFG::qString *v3; // rax
  char *v4; // rcx
  char v5; // al
  int v6; // ecx
  UFG::qNode<UFG::qString,UFG::qString> *v7; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *v8; // rax
  UFG::qString v9; // [rsp+38h] [rbp-C8h]
  __int64 v10; // [rsp+60h] [rbp-A0h]
  UFG::qPrintInfo info; // [rsp+70h] [rbp-90h]
  char text; // [rsp+1A0h] [rbp+A0h]
  va_list va; // [rsp+21D0h] [rbp+20D0h]

  va_start(va, format);
  v10 = -2i64;
  v2 = result;
  if ( format )
  {
    info.mStdOutBuffer.NumChars = 0;
    info.OutString = &text;
    info.OutStringLen = 0x2000;
    info.PrintChannel = -1;
    info.StdOut = 0;
    if ( (unsigned int)UFG::qPrintEngine(&info, format, va) )
    {
      v9.mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&v9;
      v9.mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&v9;
      *(_QWORD *)&v9.mMagic = 16909060i64;
      v9.mData = (char *)UFG::qString::sEmptyString;
      *(_QWORD *)&v9.mStringHash32 = -1i64;
      if ( &text == UFG::qString::sEmptyString )
      {
        v6 = 0;
      }
      else
      {
        v4 = &text;
        do
          v5 = *v4++;
        while ( v5 );
        v6 = (_DWORD)v4 - (unsigned __int64)&text - 1;
      }
      UFG::qString::Set(&v9, &text, v6, 0i64, 0);
      v2->mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&v2->mPrev;
      v2->mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&v2->mPrev;
      v2->mMagic = 16909060;
      v2->mData = (char *)UFG::qString::sEmptyString;
      v2->mLength = 0;
      UFG::qString::Set(v2, v9.mData, v9.mLength, 0i64, 0);
      v2->mStringHash32 = v9.mStringHash32;
      v2->mStringHashUpper32 = v9.mStringHashUpper32;
      if ( v9.mData != UFG::qString::sEmptyString )
      {
        if ( v9.mData )
          UFG::qMemoryPool::Free(UFG::gMainMemoryPool, v9.mData);
      }
      v9.mMagic = 0;
      v7 = v9.mPrev;
      v8 = v9.mNext;
      v9.mPrev->mNext = v9.mNext;
      v8->mPrev = v7;
      v9.mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&v9;
      v9.mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&v9;
    }
    else
    {
      v2->mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&v2->mPrev;
      v2->mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&v2->mPrev;
      v2->mMagic = 16909060;
      v2->mData = (char *)UFG::qString::sEmptyString;
      v2->mLength = 0;
      *(_QWORD *)&v2->mStringHash32 = -1i64;
    }
    v3 = v2;
  }
  else
  {
    result->mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&result->mPrev;
    result->mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&result->mPrev;
    result->mMagic = 16909060;
    result->mData = (char *)UFG::qString::sEmptyString;
    result->mLength = 0;
    *(_QWORD *)&result->mStringHash32 = -1i64;
    v3 = result;
  }
  return v3;
}

// File Line: 1488
// RVA: 0x16E350
void UFG::qString::Format(UFG::qString *this, const char *format, ...)
{
  UFG::qString *v2; // rbx
  int v3; // eax
  UFG::qPrintInfo info; // [rsp+30h] [rbp-2138h]
  char text; // [rsp+160h] [rbp-2008h]
  va_list va; // [rsp+2180h] [rbp+18h]

  va_start(va, format);
  if ( format )
  {
    v2 = this;
    info.mStdOutBuffer.NumChars = 0;
    info.OutStringLen = 0x2000;
    info.OutString = &text;
    info.PrintChannel = -1;
    info.StdOut = 0;
    v3 = UFG::qPrintEngine(&info, format, va);
    if ( v3 )
      UFG::qString::Set(v2, &text, v3, 0i64, 0);
  }
}

// File Line: 1511
// RVA: 0x1643D0
void __fastcall UFG::qString::~qString(UFG::qString *this)
{
  UFG::qString *v1; // rbx
  char *v2; // rdx
  UFG::qNode<UFG::qString,UFG::qString> *v3; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *v4; // rax

  v1 = this;
  v2 = this->mData;
  if ( v2 != UFG::qString::sEmptyString && v2 )
    UFG::qMemoryPool::Free(UFG::gMainMemoryPool, v2);
  v1->mMagic = 0;
  v3 = v1->mPrev;
  v4 = v1->mNext;
  v3->mNext = v4;
  v4->mPrev = v3;
  v1->mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&v1->mPrev;
  v1->mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&v1->mPrev;
}

// File Line: 1521
// RVA: 0x17CA00
void __fastcall UFG::qString::Set(UFG::qString *this, const char *text, int length, const char *textb, int lengthb)
{
  int v5; // esi
  const char *v6; // rbx
  int v7; // er15
  const char *v8; // rdi
  UFG::qString *v9; // rbp
  const char *v10; // r14
  int v11; // er13
  UFG::qMemoryPool *v12; // rcx
  UFG::allocator::free_link *v13; // rax
  int v14; // edx
  UFG::allocator::free_link *v15; // rcx
  signed __int64 v16; // rdi
  char v17; // al
  int v18; // edx
  char *v19; // rcx
  signed __int64 v20; // rbx
  char v21; // al
  char *v22; // rdx

  v5 = 0;
  v6 = textb;
  v7 = length;
  v8 = text;
  v9 = this;
  this->mMagic = 0x1020304;
  if ( !text || !*text )
    v7 = 0;
  if ( textb && *textb )
    v5 = lengthb;
  v10 = UFG::qString::sEmptyString;
  v11 = v7 + v5;
  if ( v7 + v5 > 0 )
  {
    v12 = UFG::gMainMemoryPool;
    if ( !UFG::gMainMemoryPool )
    {
      UFG::InternalSetupMainMemoryPool((UFG *)UFG::gMainMemoryPool);
      v12 = UFG::gMainMemoryPool;
    }
    v13 = UFG::qMemoryPool::Allocate(v12, v11 + 1, "qString.Set", 0i64, 1u);
    v10 = (const char *)v13;
    if ( v7 > 0 )
    {
      v14 = v7 + 1;
      if ( v13 )
      {
        if ( v14 > 0 )
        {
          if ( v8 )
          {
            v15 = v13;
            v16 = v8 - (const char *)v13;
            do
            {
              v17 = *((_BYTE *)&v15->mNext + v16);
              v15 = (UFG::allocator::free_link *)((char *)v15 + 1);
              HIBYTE(v15[-1].mNext) = v17;
              if ( !v17 )
                break;
              --v14;
            }
            while ( v14 > 1 );
            if ( HIBYTE(v15[-1].mNext) )
              LOBYTE(v15->mNext) = 0;
          }
          else
          {
            LOBYTE(v13->mNext) = 0;
          }
        }
      }
    }
    if ( v5 > 0 )
    {
      v18 = v5 + 1;
      v19 = (char *)&v10[v7];
      if ( v19 )
      {
        if ( v18 > 0 )
        {
          if ( !v6 )
            goto LABEL_35;
          v20 = v6 - v19;
          do
          {
            v21 = (v19++)[v20];
            *(v19 - 1) = v21;
            if ( !v21 )
              break;
            --v18;
          }
          while ( v18 > 1 );
          if ( *(v19 - 1) )
LABEL_35:
            *v19 = 0;
        }
      }
    }
  }
  v22 = v9->mData;
  if ( v22 != UFG::qString::sEmptyString && v22 )
    UFG::qMemoryPool::Free(UFG::gMainMemoryPool, v22);
  v9->mData = (char *)v10;
  v9->mLength = v11;
  *(_QWORD *)&v9->mStringHash32 = -1i64;
}

// File Line: 1588
// RVA: 0x17C9B0
void __fastcall UFG::qString::Set(UFG::qString *this, const char *text)
{
  const char *v2; // rax
  char v3; // r8
  int v4; // eax

  if ( text && text != UFG::qString::sEmptyString )
  {
    v2 = text;
    do
      v3 = *v2++;
    while ( v3 );
    v4 = (_DWORD)v2 - (_DWORD)text - 1;
  }
  else
  {
    v4 = 0;
  }
  UFG::qString::Set(this, text, v4, 0i64, 0);
}

// File Line: 1595
// RVA: 0x164A40
char __fastcall UFG::qString::operator==(UFG::qString *this, const char *text)
{
  char *v3; // rax
  signed int v4; // ecx

  if ( !text )
    return this->mLength == 0;
  v3 = this->mData;
  if ( !text || !v3 )
    return 0;
  v4 = -1;
  while ( *text && *text == *v3 )
  {
    ++text;
    ++v3;
    if ( !--v4 )
      return 1;
  }
  return *(unsigned __int8 *)text == (unsigned __int8)*v3;
}

// File Line: 1603
// RVA: 0x1649D0
bool __fastcall UFG::qString::operator==(UFG::qString *this, UFG::qString *text)
{
  int v2; // eax
  char *v4; // rax
  char *v5; // rcx
  signed int v6; // edx

  v2 = text->mLength;
  if ( !v2 && !this->mLength )
    return 1;
  if ( v2 != this->mLength )
    return 0;
  v4 = this->mData;
  v5 = text->mData;
  if ( !v5 || !v4 )
    return 0;
  v6 = -1;
  while ( *v5 && *v5 == *v4 )
  {
    ++v5;
    ++v4;
    if ( !--v6 )
      return 1;
  }
  return *v5 == *v4;
}

// File Line: 1612
// RVA: 0x164B30
char __fastcall UFG::qString::operator!=(UFG::qString *this, const char *text)
{
  char *v3; // rax
  signed int v4; // ecx

  if ( !text )
    return this->mLength != 0;
  v3 = this->mData;
  if ( !text || !v3 )
    return 1;
  v4 = -1;
  while ( *text && *text == *v3 )
  {
    ++text;
    ++v3;
    if ( !--v4 )
      return 0;
  }
  return *(unsigned __int8 *)text != (unsigned __int8)*v3;
}

// File Line: 1617
// RVA: 0x164AA0
bool __fastcall UFG::qString::operator!=(UFG::qString *this, UFG::qString *text)
{
  int v2; // eax
  char *v4; // rax
  char *v5; // rcx
  signed int v6; // edx

  v2 = text->mLength;
  if ( !v2 && !this->mLength )
    return 0;
  if ( v2 != this->mLength )
    return 1;
  v4 = this->mData;
  v5 = text->mData;
  if ( !v5 || !v4 )
    return 1;
  v6 = -1;
  while ( *v5 && *v5 == *v4 )
  {
    ++v5;
    ++v4;
    if ( !--v6 )
      return 0;
  }
  return *v5 != *v4;
}

// File Line: 1646
// RVA: 0x164CB0
UFG::qString *__fastcall UFG::qString::operator+=(UFG::qString *this, UFG::qString *text)
{
  int lengthb; // eax
  UFG::qString *v3; // rbx

  lengthb = text->mLength;
  v3 = this;
  if ( lengthb )
    UFG::qString::Set(this, this->mData, this->mLength, text->mData, lengthb);
  return v3;
}

// File Line: 1656
// RVA: 0x164CE0
UFG::qString *__fastcall UFG::qString::operator+=(UFG::qString *this, const char *text)
{
  UFG::qString *v2; // rbx
  const char *v3; // rax
  char v4; // r8

  v2 = this;
  if ( text && *text )
  {
    v3 = text;
    do
      v4 = *v3++;
    while ( v4 );
    UFG::qString::Set(this, this->mData, this->mLength, text, (_DWORD)v3 - (_DWORD)text - 1);
  }
  return v2;
}

// File Line: 1666
// RVA: 0x172F20
const wchar_t *__fastcall UFG::qString::GetWideName(UFG::qString *this)
{
  char *v1; // rdx
  wchar_t v2; // ax
  bool v3; // zf
  const wchar_t *result; // rax
  wchar_t *v5; // r8
  wchar_t v6; // cx

  v1 = this->mData;
  if ( !v1 )
    return buffer_0;
  v2 = *v1;
  buffer_0[0] = v2;
  v3 = v2 == 0;
  result = buffer_0;
  if ( !v3 )
  {
    v5 = buffer_0;
    do
    {
      v6 = (v1++)[1];
      ++v5;
      *v5 = v6;
    }
    while ( v6 );
  }
  return result;
}

// File Line: 1674
// RVA: 0x17DF20
signed __int64 __fastcall UFG::qString::StartsWith(UFG::qString *this, const char *text, int length)
{
  int v3; // eax
  UFG::qString *v4; // r8
  const char *v5; // rax
  char v6; // cl
  char *v7; // rcx
  signed __int64 result; // rax

  v3 = length;
  v4 = this;
  if ( v3 < 0 )
  {
    if ( text )
    {
      v5 = text;
      do
        v6 = *v5++;
      while ( v6 );
      v3 = (_DWORD)v5 - (_DWORD)text - 1;
    }
    else
    {
      v3 = 0;
    }
  }
  v7 = v4->mData;
  if ( !v7 || !text )
    goto LABEL_21;
  if ( v3 < 0 )
    v3 = -1;
  if ( !v3 )
    goto LABEL_22;
  while ( *v7 && *v7 == *text )
  {
    ++v7;
    ++text;
    if ( !--v3 )
      return 1i64;
  }
  if ( *v7 == *text )
LABEL_22:
    result = 1i64;
  else
LABEL_21:
    result = 0i64;
  return result;
}

// File Line: 1685
// RVA: 0x16D410
signed __int64 __fastcall UFG::qString::EndsWith(UFG::qString *this, const char *text, int length)
{
  int v3; // eax
  UFG::qString *v4; // r8
  const char *v5; // rax
  char v6; // cl
  __int64 v7; // r9
  char *v8; // r8
  signed __int64 result; // rax

  v3 = length;
  v4 = this;
  if ( v3 < 0 )
  {
    if ( text )
    {
      v5 = text;
      do
        v6 = *v5++;
      while ( v6 );
      v3 = (_DWORD)v5 - (_DWORD)text - 1;
    }
    else
    {
      v3 = 0;
    }
  }
  v7 = v4->mLength;
  if ( v3 > (signed int)v7 )
    goto LABEL_22;
  v8 = &v4->mData[v7 - v3];
  if ( !v8 || !text )
    goto LABEL_22;
  if ( v3 < 0 )
    v3 = -1;
  if ( !v3 )
    goto LABEL_23;
  while ( *v8 && *v8 == *text )
  {
    ++v8;
    ++text;
    if ( !--v3 )
      return 1i64;
  }
  if ( *v8 == *text )
LABEL_23:
    result = 1i64;
  else
LABEL_22:
    result = 0i64;
  return result;
}

// File Line: 1699
// RVA: 0x17EBE0
UFG::qString *__fastcall UFG::qString::Trim(UFG::qString *this, UFG::qString *result)
{
  UFG::qString *v2; // rbx
  UFG::qString *v3; // rax
  UFG::qNode<UFG::qString,UFG::qString> *v4; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *v5; // rax
  UFG::qString resulta; // [rsp+40h] [rbp-38h]

  v2 = result;
  result->mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&result->mPrev;
  result->mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&result->mPrev;
  result->mMagic = 16909060;
  result->mData = (char *)UFG::qString::sEmptyString;
  result->mLength = 0;
  *(_QWORD *)&result->mStringHash32 = -1i64;
  v3 = UFG::qTrim(&resulta, this->mData, this->mLength);
  UFG::qString::Set(v2, v3->mData, v3->mLength, 0i64, 0);
  if ( resulta.mData != UFG::qString::sEmptyString && resulta.mData )
    UFG::qMemoryPool::Free(UFG::gMainMemoryPool, resulta.mData);
  v4 = resulta.mPrev;
  v5 = resulta.mNext;
  resulta.mPrev->mNext = resulta.mNext;
  v5->mPrev = v4;
  return v2;
}

// File Line: 1706
// RVA: 0x17E6B0
UFG::qString *__fastcall UFG::qString::ToUpper(UFG::qString *this, UFG::qString *result)
{
  UFG::qString *v2; // rdi
  UFG::qString *v3; // rbx
  char *v4; // rdx
  char v5; // al

  v2 = result;
  v3 = this;
  result->mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&result->mPrev;
  result->mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&result->mPrev;
  result->mMagic = 16909060;
  result->mData = (char *)UFG::qString::sEmptyString;
  result->mLength = 0;
  UFG::qString::Set(result, this->mData, this->mLength, 0i64, 0);
  v2->mStringHash32 = v3->mStringHash32;
  v2->mStringHashUpper32 = v3->mStringHashUpper32;
  v4 = v2->mData;
  if ( v4 && *v4 )
  {
    while ( 1 )
    {
      v5 = *v4;
      if ( *v4 <= 122 && *v4 >= 97 )
        v5 -= 32;
      *v4 = v5;
      if ( !v5 )
        break;
      ++v4;
    }
  }
  return v2;
}

// File Line: 1713
// RVA: 0x177580
void __fastcall UFG::qString::MakeUpper(UFG::qString *this)
{
  char *v1; // rdx
  char v2; // al

  v1 = this->mData;
  if ( v1 && *v1 )
  {
    while ( 1 )
    {
      v2 = *v1;
      if ( *v1 <= 122 && *v1 >= 97 )
        v2 -= 32;
      *v1 = v2;
      if ( !v2 )
        break;
      ++v1;
    }
    *(_QWORD *)&this->mStringHash32 = -1i64;
  }
  else
  {
    *(_QWORD *)&this->mStringHash32 = -1i64;
  }
}

// File Line: 1758
// RVA: 0x17E5E0
UFG::qString *__fastcall UFG::qString::ToLower(UFG::qString *this, UFG::qString *result)
{
  UFG::qString *v2; // rdi
  UFG::qString *v3; // rbx
  char *v4; // rdx
  char v5; // al

  v2 = result;
  v3 = this;
  result->mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&result->mPrev;
  result->mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&result->mPrev;
  result->mMagic = 16909060;
  result->mData = (char *)UFG::qString::sEmptyString;
  result->mLength = 0;
  UFG::qString::Set(result, this->mData, this->mLength, 0i64, 0);
  v2->mStringHash32 = v3->mStringHash32;
  v2->mStringHashUpper32 = v3->mStringHashUpper32;
  v4 = v2->mData;
  if ( v4 && *v4 )
  {
    while ( 1 )
    {
      v5 = *v4;
      if ( *v4 <= 90 && *v4 >= 65 )
        v5 += 32;
      *v4 = v5;
      if ( !v5 )
        break;
      ++v4;
    }
  }
  return v2;
}

// File Line: 1765
// RVA: 0x177530
void __fastcall UFG::qString::MakeLower(UFG::qString *this)
{
  char *v1; // rdx
  char v2; // al

  v1 = this->mData;
  if ( v1 && *v1 )
  {
    while ( 1 )
    {
      v2 = *v1;
      if ( *v1 <= 90 && *v1 >= 65 )
        v2 += 32;
      *v1 = v2;
      if ( !v2 )
        break;
      ++v1;
    }
    *(_QWORD *)&this->mStringHash32 = -1i64;
  }
  else
  {
    *(_QWORD *)&this->mStringHash32 = -1i64;
  }
}

// File Line: 1778
// RVA: 0x1708F0
UFG::qString *__fastcall UFG::qString::GetFilename(UFG::qString *this, UFG::qString *result)
{
  UFG::qString *v2; // rbx
  UFG::qString *v3; // r10
  __int64 v4; // r9
  __int64 v5; // rax
  char *v6; // rdx
  char v7; // cl

  v2 = result;
  v3 = this;
  v4 = this->mLength;
  v5 = v4;
  if ( (signed int)v4 >= 0 )
  {
    v6 = this->mData;
    do
    {
      v7 = v6[v5];
      if ( v7 == 92 )
        break;
      if ( v7 == 47 )
        break;
      LODWORD(v4) = v4 - 1;
      --v5;
    }
    while ( v5 >= 0 );
  }
  v2->mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&v2->mPrev;
  v2->mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&v2->mPrev;
  v2->mMagic = 16909060;
  v2->mData = (char *)UFG::qString::sEmptyString;
  v2->mLength = 0;
  *(_QWORD *)&v2->mStringHash32 = -1i64;
  UFG::qString::Set(v2, &v3->mData[(signed int)v4 + 1], v3->mLength - v4 - 1, 0i64, 0);
  return v2;
}

// File Line: 1796
// RVA: 0x1709A0
UFG::qString *__fastcall UFG::qString::GetFilenameWithoutExtension(UFG::qString *this, UFG::qString *result)
{
  UFG::qString *v2; // rbx
  int v3; // er9
  int v4; // er8
  int v5; // er10
  char *v6; // rdx
  char v7; // al
  int v8; // er8
  int v9; // er8
  const char *v10; // rdx

  v2 = result;
  v3 = this->mLength;
  v4 = v3;
  v5 = this->mLength;
  if ( v3 >= 0 )
  {
    v6 = &this->mData[this->mLength];
    do
    {
      v7 = *v6;
      if ( *v6 == 46 && v5 == v3 )
        v5 = v4;
      if ( v7 == 92 )
        break;
      if ( v7 == 47 )
        break;
      --v6;
      --v4;
    }
    while ( v4 >= 0 );
  }
  v8 = v4 + 1;
  v2->mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&v2->mPrev;
  v2->mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&v2->mPrev;
  v2->mMagic = 16909060;
  v2->mData = (char *)UFG::qString::sEmptyString;
  v2->mLength = 0;
  *(_QWORD *)&v2->mStringHash32 = -1i64;
  if ( v8 == v5 )
  {
    v9 = 0;
    v10 = UFG::qString::sEmptyString;
  }
  else
  {
    v10 = &this->mData[v8];
    v9 = v5 - v8;
  }
  UFG::qString::Set(v2, v10, v9, 0i64, 0);
  return v2;
}

// File Line: 1827
// RVA: 0x170750
UFG::qString *__fastcall UFG::qString::GetFilePath(UFG::qString *this, UFG::qString *result)
{
  UFG::qString *v2; // rbx
  UFG::qString *v3; // r11
  int v4; // er10
  __int64 v5; // rax
  char *v6; // rdx
  char v7; // cl
  int v8; // er8
  const char *v9; // rdx

  v2 = result;
  v3 = this;
  v4 = this->mLength - 1;
  if ( v4 >= 0 && this->mData[v4] == 58 )
    v4 = this->mLength - 2;
  v5 = v4;
  if ( v4 >= 0 )
  {
    v6 = this->mData;
    do
    {
      v7 = v6[v5];
      if ( v7 == 92 )
        break;
      if ( v7 == 47 )
        break;
      --v4;
      --v5;
    }
    while ( v5 >= 0 );
  }
  v2->mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&v2->mPrev;
  v2->mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&v2->mPrev;
  v2->mMagic = 16909060;
  v2->mData = (char *)UFG::qString::sEmptyString;
  v2->mLength = 0;
  *(_QWORD *)&v2->mStringHash32 = -1i64;
  if ( v4 > 0 )
  {
    v8 = v4;
    v9 = v3->mData;
  }
  else
  {
    v8 = 0;
    v9 = UFG::qString::sEmptyString;
  }
  UFG::qString::Set(v2, v9, v8, 0i64, 0);
  return v2;
}

// File Line: 1845
// RVA: 0x170810
UFG::qString *__fastcall UFG::qString::GetFilePathWithoutExtension(UFG::qString *this, UFG::qString *result)
{
  UFG::qString *v2; // rbx
  UFG::qString *v3; // r11
  int v4; // er10
  __int64 i; // rcx
  char v6; // al
  UFG::qString *v7; // rcx
  int v8; // er8
  const char *v9; // rdx

  v2 = result;
  v3 = this;
  v4 = this->mLength - 1;
  if ( v4 >= 0 && this->mData[v4] == ':' )
    v4 = this->mLength - 2;
  for ( i = v4; i >= 0; --i )
  {
    v6 = v3->mData[i];
    if ( v6 == 92 )
      break;
    if ( (unsigned __int8)(v6 - 46) <= 1u )
      break;
    --v4;
  }
  result->mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&result->mPrev;
  result->mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&result->mPrev;
  result->mMagic = 16909060;
  result->mData = (char *)UFG::qString::sEmptyString;
  result->mLength = 0;
  *(_QWORD *)&result->mStringHash32 = -1i64;
  v7 = result;
  if ( v4 > 0 )
  {
    v8 = v4;
    v9 = v3->mData;
  }
  else
  {
    v8 = 0;
    v9 = UFG::qString::sEmptyString;
  }
  UFG::qString::Set(v7, v9, v8, 0i64, 0);
  return v2;
}

// File Line: 1880
// RVA: 0x17E180
UFG::qString *__fastcall UFG::qString::Substring(UFG::qString *this, UFG::qString *result, int start, int length)
{
  int v4; // er10
  UFG::qString *v5; // rbx
  UFG::qString *v6; // r9
  int v7; // ecx
  UFG::qNode<UFG::qString,UFG::qString> *v8; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *v9; // rax
  UFG::qString v11; // [rsp+40h] [rbp-30h]

  v4 = length;
  v5 = result;
  v6 = this;
  v11.mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&v11;
  v11.mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&v11;
  *(_QWORD *)&v11.mMagic = 16909060i64;
  v11.mData = (char *)UFG::qString::sEmptyString;
  *(_QWORD *)&v11.mStringHash32 = -1i64;
  v7 = this->mLength;
  if ( start >= v7 || start < 0 )
  {
    result->mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&result->mPrev;
    result->mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&result->mPrev;
    result->mMagic = 16909060;
    result->mData = (char *)UFG::qString::sEmptyString;
    result->mLength = 0;
    UFG::qString::Set(result, v11.mData, v11.mLength, 0i64, 0);
    v5->mStringHash32 = v11.mStringHash32;
    v5->mStringHashUpper32 = v11.mStringHashUpper32;
    if ( v11.mData != UFG::qString::sEmptyString && v11.mData )
      UFG::qMemoryPool::Free(UFG::gMainMemoryPool, v11.mData);
    v11.mMagic = 0;
  }
  else
  {
    if ( v4 < 0 || start + v4 >= v7 )
      v4 = v7 - start;
    UFG::qString::Set(&v11, &v6->mData[start], v4, 0i64, 0);
    v5->mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&v5->mPrev;
    v5->mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&v5->mPrev;
    v5->mMagic = 16909060;
    v5->mData = (char *)UFG::qString::sEmptyString;
    v5->mLength = 0;
    UFG::qString::Set(v5, v11.mData, v11.mLength, 0i64, 0);
    v5->mStringHash32 = v11.mStringHash32;
    v5->mStringHashUpper32 = v11.mStringHashUpper32;
    if ( v11.mData != UFG::qString::sEmptyString && v11.mData )
      UFG::qMemoryPool::Free(UFG::gMainMemoryPool, v11.mData);
    v11.mMagic = 0;
  }
  v8 = v11.mPrev;
  v9 = v11.mNext;
  v11.mPrev->mNext = v11.mNext;
  v9->mPrev = v8;
  return v5;
}

// File Line: 1896
// RVA: 0x17E780
__int64 __fastcall UFG::qString::Tokenize(UFG::qString *this, UFG::qList<UFG::qString,UFG::qString,1,0> *list, const char *separators, const char *allocation_name)
{
  return UFG::qTokenize(list, separators, this->mData, this->mLength, allocation_name, 0);
}

// File Line: 1901
// RVA: 0x17A950
UFG::qString *__fastcall UFG::qString::ReplaceExtension(UFG::qString *this, UFG::qString *result, const char *ext)
{
  const char *v3; // rdi
  UFG::qString *v4; // rbx
  UFG::qString *v5; // rsi
  char *v6; // rdx
  const char *v7; // rcx
  char v8; // al
  UFG::qNode<UFG::qString,UFG::qString> *v9; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *v10; // rax
  UFG::qString v12; // [rsp+40h] [rbp-30h]

  v3 = ext;
  v4 = result;
  v5 = this;
  if ( ext && *ext )
  {
    v6 = UFG::qStringFindLast(this->mData, 46);
    v12.mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&v12;
    v12.mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&v12;
    *(_QWORD *)&v12.mMagic = 16909060i64;
    v12.mData = (char *)UFG::qString::sEmptyString;
    *(_QWORD *)&v12.mStringHash32 = -1i64;
    if ( v6 )
    {
      v7 = v3;
      do
        v8 = *v7++;
      while ( v8 );
      UFG::qString::Set(&v12, v5->mData, (_DWORD)v6 - LODWORD(v5->mData), v3, (_DWORD)v7 - (_DWORD)v3 - 1);
    }
    v4->mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&v4->mPrev;
    v4->mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&v4->mPrev;
    v4->mMagic = 16909060;
    v4->mData = (char *)UFG::qString::sEmptyString;
    v4->mLength = 0;
    UFG::qString::Set(v4, v12.mData, v12.mLength, 0i64, 0);
    v4->mStringHash32 = v12.mStringHash32;
    v4->mStringHashUpper32 = v12.mStringHashUpper32;
    if ( v12.mData != UFG::qString::sEmptyString && v12.mData )
      UFG::qMemoryPool::Free(UFG::gMainMemoryPool, v12.mData);
    v12.mMagic = 0;
    v9 = v12.mPrev;
    v10 = v12.mNext;
    v12.mPrev->mNext = v12.mNext;
    v10->mPrev = v9;
    v12.mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&v12;
    v12.mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&v12;
  }
  else
  {
    UFG::qString::qString(result, this);
  }
  return v4;
}

// File Line: 1919
// RVA: 0x17AAC0
__int64 __fastcall UFG::qString::ReplaceString(UFG::qString *this, const char *find_text, const char *replace_text, bool ignore_case)
{
  const char *v4; // r12
  const char *v5; // rbp
  int v6; // ebx
  const char *v7; // rbx
  char v8; // al
  int v9; // esi
  const char *v10; // rsi
  char v11; // al
  char *v13; // r14
  int v14; // er15
  char *v15; // r13
  UFG::qMemoryPool *v16; // rcx
  int v17; // edi
  unsigned int v18; // edi
  char *v19; // rbx
  UFG::qStringBuilder v20; // [rsp+38h] [rbp-60h]
  UFG::qString *v21; // [rsp+A0h] [rbp+8h]
  int v22; // [rsp+A8h] [rbp+10h]
  bool v23; // [rsp+B8h] [rbp+20h]

  v23 = ignore_case;
  v21 = this;
  v4 = replace_text;
  v5 = find_text;
  if ( find_text )
  {
    v7 = find_text;
    do
      v8 = *v7++;
    while ( v8 );
    v6 = (_DWORD)v7 - (_DWORD)find_text - 1;
  }
  else
  {
    v6 = 0;
  }
  if ( replace_text )
  {
    v10 = replace_text;
    do
      v11 = *v10++;
    while ( v11 );
    v9 = (_DWORD)v10 - (_DWORD)replace_text - 1;
  }
  else
  {
    v9 = 0;
  }
  if ( !v6 )
    return 0i64;
  v13 = this->mData;
  v14 = this->mLength;
  v15 = UFG::qStringFind(this->mData, this->mLength, find_text, v6, ignore_case);
  if ( !v15 )
    return 0i64;
  v16 = UFG::gMainMemoryPool;
  if ( !UFG::gMainMemoryPool )
  {
    UFG::InternalSetupMainMemoryPool((UFG *)UFG::gMainMemoryPool);
    v16 = UFG::gMainMemoryPool;
  }
  v20.mBuffer = (char *)UFG::qMemoryPool::Allocate(v16, 1ui64, "qStringBuilder.ctor", 0i64, 1u);
  *v20.mBuffer = 0;
  *(_QWORD *)&v20.mBufferSize = 1i64;
  v22 = 0;
  do
  {
    v17 = (_DWORD)v15 - (_DWORD)v13;
    UFG::qStringBuilder::Add(&v20, v13, (_DWORD)v15 - (_DWORD)v13);
    UFG::qStringBuilder::Add(&v20, v4, v9);
    v13 = &v15[v6];
    v14 -= v17 + v6;
    v18 = v22++ + 1;
    v15 = UFG::qStringFind(&v15[v6], v14, v5, v6, v23);
  }
  while ( v15 );
  UFG::qStringBuilder::Add(&v20, v13, v14);
  v19 = v20.mBuffer;
  UFG::qString::Set(v21, v20.mBuffer, v20.mStringLength, 0i64, 0);
  if ( v19 )
    UFG::qMemoryPool::Free(UFG::gMainMemoryPool, v19);
  return v18;
}

// File Line: 1970
// RVA: 0x17A920
__int64 __fastcall UFG::qString::ReplaceCharInPlace(UFG::qString *this, char search_char, char replace_char)
{
  int v3; // er10
  char *v4; // r9
  __int64 result; // rax

  v3 = this->mLength;
  v4 = this->mData;
  for ( result = 0i64; v3 > 0; ++v4 )
  {
    if ( *v4 == search_char )
    {
      *v4 = replace_char;
      result = (unsigned int)(result + 1);
    }
    --v3;
  }
  return result;
}

// File Line: 2013
// RVA: 0x17FFF0
UFG::qString *__fastcall UFG::qString::append(UFG::qString *this, const char *str, unsigned int len)
{
  UFG::qString *v3; // rbx

  v3 = this;
  if ( str )
    UFG::qString::Set(this, this->mData, this->mLength, str, len);
  return v3;
}

// File Line: 2022
// RVA: 0x180FF0
signed __int64 __fastcall UFG::qString::find(UFG::qString *this, const char *str)
{
  char *v2; // rbx
  char *v3; // rax
  signed __int64 result; // rax

  v2 = this->mData;
  v3 = UFG::qStringFind(this->mData, str);
  if ( v3 )
    result = v3 - v2;
  else
    result = 0xFFFFFFFFi64;
  return result;
}

// File Line: 2039
// RVA: 0x18C340
__int64 __fastcall UFG::qTokenize(UFG::qList<UFG::qString,UFG::qString,1,0> *list, const char *separators, const char *buffer, int buffer_length, const char *allocation_name, bool add_empty_strings)
{
  int v6; // er10
  const char *v7; // r12
  const char *v8; // rbp
  UFG::qList<UFG::qString,UFG::qString,1,0> *v9; // rsi
  const char *v10; // r10
  char v11; // al
  const char *v12; // rbx
  int v13; // er9
  const char *v14; // rcx
  char v15; // al
  int v16; // ecx
  int v17; // er13
  int v18; // edi
  unsigned int v19; // edx
  __int64 v20; // r14
  __int64 v21; // r15
  __int64 v22; // r8
  __int64 v23; // rax
  UFG::qMemoryPool *v24; // rcx
  UFG::allocator::free_link *v25; // rax
  UFG::qString *v26; // rbx
  UFG::qNode<UFG::qString,UFG::qString> *v27; // rax
  int v28; // edi
  char *v29; // rax
  UFG::qString *v30; // rbx
  UFG::qNode<UFG::qString,UFG::qString> *v31; // rcx
  const char *v33; // [rsp+38h] [rbp-60h]
  __int64 v34; // [rsp+40h] [rbp-58h]
  UFG::qList<UFG::qString,UFG::qString,1,0> *v35; // [rsp+A0h] [rbp+8h]
  int v36; // [rsp+B0h] [rbp+18h]

  v35 = list;
  v6 = buffer_length;
  v7 = buffer;
  v8 = separators;
  v9 = list;
  if ( !buffer || !*buffer || !list || !separators || !*separators )
    return 0i64;
  if ( !buffer_length )
  {
    v10 = buffer;
    do
      v11 = *v10++;
    while ( v11 );
    v6 = (_DWORD)v10 - (_DWORD)buffer - 1;
  }
  v12 = "qTokenize";
  if ( allocation_name )
    v12 = allocation_name;
  v33 = v12;
  v13 = -(add_empty_strings != 0);
  v14 = separators;
  do
    v15 = *v14++;
  while ( v15 );
  v16 = (_DWORD)v14 - (_DWORD)separators - 1;
  v17 = 0;
  v18 = 0;
  v19 = 0;
  v36 = 0;
  v20 = 0i64;
  v21 = v16;
  v22 = v6;
  v34 = v6;
  if ( v6 > 0 )
  {
    do
    {
      v23 = 0i64;
      if ( v21 <= 0 )
      {
LABEL_28:
        ++v18;
      }
      else
      {
        while ( v7[v20] != v8[v23] )
        {
          if ( ++v23 >= v21 )
            goto LABEL_28;
        }
        if ( v18 - v17 <= v13 )
        {
          v9 = v35;
        }
        else
        {
          v24 = UFG::gMainMemoryPool;
          if ( !UFG::gMainMemoryPool )
          {
            UFG::InternalSetupMainMemoryPool((UFG *)UFG::gMainMemoryPool);
            v24 = UFG::gMainMemoryPool;
          }
          v25 = UFG::qMemoryPool::Allocate(v24, 0x28ui64, v12, 0i64, 1u);
          v26 = (UFG::qString *)v25;
          if ( v25 )
          {
            v25->mNext = v25;
            v25[1].mNext = v25;
            LODWORD(v25[2].mNext) = 16909060;
            v25[3].mNext = (UFG::allocator::free_link *)UFG::qString::sEmptyString;
            HIDWORD(v25[2].mNext) = 0;
            v25[4].mNext = (UFG::allocator::free_link *)-1i64;
          }
          else
          {
            v26 = 0i64;
          }
          UFG::qString::Set(v26, &v7[v17], v18 - v17, 0i64, 0);
          v9 = v35;
          v27 = v35->mNode.mPrev;
          v27->mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&v26->mPrev;
          v26->mPrev = v27;
          v26->mNext = &v35->mNode;
          v35->mNode.mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&v26->mPrev;
          v19 = v36++ + 1;
          v12 = v33;
          v22 = v34;
          v13 = -(add_empty_strings != 0);
        }
        v17 = ++v18;
      }
      ++v20;
    }
    while ( v20 < v22 );
  }
  v28 = v18 - v17;
  if ( v28 > 0 )
  {
    v29 = operator new(0x28ui64, v12);
    v30 = (UFG::qString *)v29;
    if ( v29 )
    {
      *(_QWORD *)v29 = v29;
      *((_QWORD *)v29 + 1) = v29;
      *((_DWORD *)v29 + 4) = 16909060;
      *((_QWORD *)v29 + 3) = UFG::qString::sEmptyString;
      *((_DWORD *)v29 + 5) = 0;
      *((_QWORD *)v29 + 4) = -1i64;
    }
    else
    {
      v30 = 0i64;
    }
    UFG::qString::Set(v30, &v7[v17], v28, 0i64, 0);
    v31 = v9->mNode.mPrev;
    v31->mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&v30->mPrev;
    v30->mPrev = v31;
    v30->mNext = &v9->mNode;
    v9->mNode.mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&v30->mPrev;
    v19 = v36 + 1;
  }
  return v19;
} v31;
    v30->mNext = &v9->mNode;
    v9->mNode.

// File Line: 2183
// RVA: 0x183860
UFG::qNode<UFG::qString,UFG::qString> *__fastcall UFG::qFindString(UFG::qList<UFG::qString,UFG::qString,1,0> *list, const char *search_string, bool case_insensitive)
{
  unsigned int v3; // er11
  bool v4; // di
  const char *v5; // r9
  char i; // dl
  char v7; // al
  char v8; // al
  UFG::qNode<UFG::qString,UFG::qString> *v9; // r8
  UFG::qNode<UFG::qString,UFG::qString> *v10; // r10
  unsigned int v11; // er9
  char j; // al
  UFG::qNode<UFG::qString,UFG::qString> *v13; // r9
  unsigned int v14; // edx
  char k; // al

  v3 = -1;
  v4 = case_insensitive;
  v5 = search_string;
  if ( case_insensitive )
  {
    if ( search_string )
    {
      for ( i = *search_string; i; v3 = (v3 << 8) ^ sCrcTable32[(unsigned __int8)(v7 ^ HIBYTE(v3))] )
      {
        if ( i <= 122 && i >= 97 )
          i -= 32;
        v7 = i;
        i = (v5++)[1];
      }
    }
  }
  else if ( search_string )
  {
    v8 = *search_string;
    if ( *search_string )
    {
      do
      {
        ++v5;
        v3 = (v3 << 8) ^ sCrcTable32[(unsigned __int8)(v8 ^ HIBYTE(v3))];
        v8 = *v5;
      }
      while ( *v5 );
    }
  }
  v9 = list->mNode.mNext;
  if ( v9 == (UFG::qNode<UFG::qString,UFG::qString> *)list )
    return 0i64;
  while ( 1 )
  {
    if ( v4 )
    {
      if ( HIDWORD(v9[2].mPrev) == -1 )
      {
        v10 = v9[1].mNext;
        v11 = -1;
        if ( v10 )
        {
          for ( j = (char)v10->mPrev; LOBYTE(v10->mPrev); j = (char)v10->mPrev )
          {
            if ( j <= 122 && j >= 97 )
              j -= 32;
            v10 = (UFG::qNode<UFG::qString,UFG::qString> *)((char *)v10 + 1);
            v11 = (v11 << 8) ^ sCrcTable32[(unsigned __int8)(j ^ HIBYTE(v11))];
          }
        }
        HIDWORD(v9[2].mPrev) = v11;
      }
      if ( v3 == HIDWORD(v9[2].mPrev) )
        break;
    }
    if ( LODWORD(v9[2].mPrev) == -1 )
    {
      v13 = v9[1].mNext;
      v14 = -1;
      if ( v13 )
      {
        for ( k = (char)v13->mPrev; LOBYTE(v13->mPrev); k = (char)v13->mPrev )
        {
          v13 = (UFG::qNode<UFG::qString,UFG::qString> *)((char *)v13 + 1);
          v14 = (v14 << 8) ^ sCrcTable32[(unsigned __int8)(k ^ HIBYTE(v14))];
        }
      }
      LODWORD(v9[2].mPrev) = v14;
    }
    if ( v3 == LODWORD(v9[2].mPrev) )
      break;
    v9 = v9->mNext;
    if ( v9 == (UFG::qNode<UFG::qString,UFG::qString> *)list )
      return 0i64;
  }
  return v9;
}

// File Line: 2265
// RVA: 0x18C740
UFG::qString *__fastcall UFG::qTrim(UFG::qString *result, const char *text, int length)
{
  int v3; // er10
  const char *v4; // r9
  UFG::qString *v5; // rbx
  const char *v6; // r10
  char v7; // al
  int v8; // er8
  signed __int64 v9; // rcx
  signed __int64 v10; // rdx
  signed __int64 v11; // r11
  char v12; // al
  char v13; // al
  int v14; // er10
  UFG::qNode<UFG::qString,UFG::qString> *v15; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *v16; // rax
  UFG::qString v18; // [rsp+40h] [rbp-30h]

  v3 = length;
  v4 = text;
  v5 = result;
  v18.mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&v18;
  v18.mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&v18;
  *(_QWORD *)&v18.mMagic = 16909060i64;
  v18.mData = (char *)UFG::qString::sEmptyString;
  *(_QWORD *)&v18.mStringHash32 = -1i64;
  if ( text )
  {
    if ( length < 0 )
    {
      v6 = text;
      do
        v7 = *v6++;
      while ( v7 );
      v3 = (_DWORD)v6 - (_DWORD)text - 1;
    }
    if ( v3 > 0 )
    {
      v8 = 0;
      v9 = 0i64;
      v10 = v3;
      v11 = 6174031360i64;
      while ( 1 )
      {
        v12 = v4[v9];
        if ( (unsigned __int8)v12 > 0x20u || !_bittest64(&v11, v12) || v9 >= v3 )
          break;
        ++v8;
        ++v9;
      }
      while ( 1 )
      {
        v13 = v4[v10 - 1];
        if ( (unsigned __int8)v13 > 0x20u || !_bittest64(&v11, v13) || v10 < v9 )
          break;
        --v3;
        --v10;
      }
      v14 = v3 - v8;
      if ( v14 > 0 )
        UFG::qString::Set(&v18, &v4[v8], v14, 0i64, 0);
    }
    v5->mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&v5->mPrev;
    v5->mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&v5->mPrev;
    v5->mMagic = 16909060;
    v5->mData = (char *)UFG::qString::sEmptyString;
    v5->mLength = 0;
    UFG::qString::Set(v5, v18.mData, v18.mLength, 0i64, 0);
    v5->mStringHash32 = v18.mStringHash32;
    v5->mStringHashUpper32 = v18.mStringHashUpper32;
    if ( v18.mData != UFG::qString::sEmptyString && v18.mData )
      UFG::qMemoryPool::Free(UFG::gMainMemoryPool, v18.mData);
    v18.mMagic = 0;
  }
  else
  {
    result->mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&result->mPrev;
    result->mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&result->mPrev;
    result->mMagic = 16909060;
    result->mData = (char *)UFG::qString::sEmptyString;
    result->mLength = 0;
    UFG::qString::Set(result, v18.mData, v18.mLength, 0i64, 0);
    v5->mStringHash32 = v18.mStringHash32;
    v5->mStringHashUpper32 = v18.mStringHashUpper32;
    if ( v18.mData != UFG::qString::sEmptyString && v18.mData )
      UFG::qMemoryPool::Free(UFG::gMainMemoryPool, v18.mData);
    v18.mMagic = 0;
  }
  v15 = v18.mPrev;
  v16 = v18.mNext;
  v18.mPrev->mNext = v18.mNext;
  v16->mPrev = v15;
  return v5;
}

// File Line: 2300
// RVA: 0x181F00
UFG::qString *__fastcall UFG::qCleanupFilepath(UFG::qString *result, const char *path, char separator)
{
  const char *v3; // r14
  UFG::qString *v4; // r12
  char v5; // bl
  UFG::qMemoryPool *v6; // rcx
  UFG::allocator::free_link *v7; // rsi
  int v8; // edi
  int i; // ebp
  char v10; // al
  UFG::qMemoryPool *v11; // rcx
  UFG::allocator::free_link *v12; // rbx
  UFG::qMemoryPool *v13; // rcx
  UFG::allocator::free_link *v14; // rbx
  char source; // [rsp+A0h] [rbp+18h]

  source = separator;
  v3 = path;
  v4 = result;
  v5 = 0;
  v6 = UFG::gMainMemoryPool;
  if ( !UFG::gMainMemoryPool )
  {
    UFG::InternalSetupMainMemoryPool((UFG *)UFG::gMainMemoryPool);
    v6 = UFG::gMainMemoryPool;
  }
  v7 = UFG::qMemoryPool::Allocate(v6, 1ui64, "qStringBuilder.ctor", 0i64, 1u);
  LOBYTE(v7->mNext) = 0;
  v8 = 1;
  for ( i = 0; *v3; ++v3 )
  {
    v10 = *v3;
    if ( *v3 == 92 || v10 == 47 )
    {
      if ( !v5 )
      {
        if ( source )
        {
          if ( i + 2 > v8 )
          {
            do
              v8 *= 2;
            while ( i + 2 > v8 );
            v13 = UFG::gMainMemoryPool;
            if ( !UFG::gMainMemoryPool )
            {
              UFG::InternalSetupMainMemoryPool((UFG *)UFG::gMainMemoryPool);
              v13 = UFG::gMainMemoryPool;
            }
            v14 = UFG::qMemoryPool::Allocate(v13, v8, "StringBuilder::Add", 0i64, 1u);
            UFG::qMemCopy(v14, v7, i + 1);
            if ( v7 )
              UFG::qMemoryPool::Free(UFG::gMainMemoryPool, v7);
            v7 = v14;
          }
          UFG::qMemCopy((char *)v7 + i, &source, 1u);
          *((_BYTE *)&v7->mNext + i++ + 1) = 0;
        }
        v5 = 1;
      }
    }
    else
    {
      if ( v10 )
      {
        if ( i + 2 > v8 )
        {
          do
            v8 *= 2;
          while ( i + 2 > v8 );
          v11 = UFG::gMainMemoryPool;
          if ( !UFG::gMainMemoryPool )
          {
            UFG::InternalSetupMainMemoryPool((UFG *)UFG::gMainMemoryPool);
            v11 = UFG::gMainMemoryPool;
          }
          v12 = UFG::qMemoryPool::Allocate(v11, v8, "StringBuilder::Add", 0i64, 1u);
          UFG::qMemCopy(v12, v7, i + 1);
          if ( v7 )
            UFG::qMemoryPool::Free(UFG::gMainMemoryPool, v7);
          v7 = v12;
        }
        UFG::qMemCopy((char *)v7 + i, v3, 1u);
        *((_BYTE *)&v7->mNext + i++ + 1) = 0;
      }
      v5 = 0;
    }
  }
  UFG::qString::qString(v4, (const char *)v7);
  if ( v7 )
    UFG::qMemoryPool::Free(UFG::gMainMemoryPool, v7);
  return v4;
}

// File Line: 2331
// RVA: 0x1620F0
void __fastcall UFG::qStringBuilder::qStringBuilder(UFG::qStringBuilder *this)
{
  UFG::qStringBuilder *v1; // rbx
  UFG::qMemoryPool *v2; // rcx
  char *v3; // rax

  v1 = this;
  v2 = UFG::gMainMemoryPool;
  if ( !UFG::gMainMemoryPool )
  {
    UFG::InternalSetupMainMemoryPool((UFG *)UFG::gMainMemoryPool);
    v2 = UFG::gMainMemoryPool;
  }
  v3 = UFG::qMemoryPool::Allocate(v2, 1ui64, "qStringBuilder.ctor", 0i64, 1u);
  v1->mBuffer = v3;
  *v3 = 0;
  *(_QWORD *)&v1->mBufferSize = 1i64;
}

// File Line: 2349
// RVA: 0x164430
void __fastcall UFG::qStringBuilder::~qStringBuilder(UFG::qStringBuilder *this)
{
  UFG::qStringBuilder *v1; // rbx

  v1 = this;
  if ( this->mBuffer )
    UFG::qMemoryPool::Free(UFG::gMainMemoryPool, this->mBuffer);
  v1->mBuffer = 0i64;
  *(_QWORD *)&v1->mBufferSize = 0i64;
}

// File Line: 2365
// RVA: 0x164950
UFG::qStringBuilder *__fastcall UFG::qStringBuilder::operator<<(UFG::qStringBuilder *this, const unsigned __int64 v)
{
  UFG::qStringBuilder *v2; // rbx

  v2 = this;
  UFG::qStringBuilder::Format(this, "%u64", v);
  return v2;
}

// File Line: 2370
// RVA: 0x164980
UFG::qStringBuilder *__fastcall UFG::qStringBuilder::operator<<(UFG::qStringBuilder *this, const bool v)
{
  UFG::qStringBuilder *v2; // rbx

  v2 = this;
  if ( v == 1 )
    UFG::qStringBuilder::Add(this, "true", 4);
  else
    UFG::qStringBuilder::Add(this, "false", 5);
  return v2;
}

// File Line: 2372
// RVA: 0x164920
UFG::qStringBuilder *__fastcall UFG::qStringBuilder::operator<<(UFG::qStringBuilder *this, const char *v)
{
  UFG::qStringBuilder *v2; // rbx

  v2 = this;
  UFG::qStringBuilder::Format(this, "%s", v);
  return v2;
}

// File Line: 2375
// RVA: 0x164900
UFG::qStringBuilder *__fastcall UFG::qStringBuilder::operator<<(UFG::qStringBuilder *this, UFG::qString *v)
{
  UFG::qStringBuilder *v2; // rbx

  v2 = this;
  UFG::qStringBuilder::Add(this, v->mData, v->mLength);
  return v2;
}

// File Line: 2384
// RVA: 0x165B90
void __fastcall UFG::qStringBuilder::Add(UFG::qStringBuilder *this, const char *text, int length)
{
  int v3; // ebx
  const char *v4; // rsi
  UFG::qStringBuilder *v5; // rdi
  const char *v6; // rbx
  char v7; // al
  int v8; // eax
  int v9; // ecx
  UFG::qMemoryPool *v10; // rcx
  unsigned __int64 v11; // rbp
  char *v12; // rbp

  if ( text )
  {
    v3 = length;
    v4 = text;
    v5 = this;
    if ( *text )
    {
      if ( length == -1 )
      {
        v6 = text;
        do
          v7 = *v6++;
        while ( v7 );
        v3 = (_DWORD)v6 - (_DWORD)text - 1;
      }
      v8 = this->mBufferSize;
      v9 = v3 + this->mStringLength + 1;
      if ( v9 > v8 )
      {
        do
          v8 *= 2;
        while ( v9 > v8 );
        v5->mBufferSize = v8;
        v10 = UFG::gMainMemoryPool;
        v11 = v8;
        if ( !UFG::gMainMemoryPool )
        {
          UFG::InternalSetupMainMemoryPool((UFG *)UFG::gMainMemoryPool);
          v10 = UFG::gMainMemoryPool;
        }
        v12 = UFG::qMemoryPool::Allocate(v10, v11, "StringBuilder::Add", 0i64, 1u);
        UFG::qMemCopy(v12, v5->mBuffer, v5->mStringLength + 1);
        if ( v5->mBuffer )
          UFG::qMemoryPool::Free(UFG::gMainMemoryPool, v5->mBuffer);
        v5->mBuffer = v12;
      }
      UFG::qMemCopy(&v5->mBuffer[v5->mStringLength], v4, v3);
      v5->mBuffer[v5->mStringLength + (signed __int64)v3] = 0;
      v5->mStringLength += v3;
    }
  }
}

// File Line: 2459
// RVA: 0x16E3F0
void UFG::qStringBuilder::Format(UFG::qStringBuilder *this, const char *format, ...)
{
  UFG::qStringBuilder *v2; // rbx
  int v3; // eax
  UFG::qPrintInfo info; // [rsp+20h] [rbp-2138h]
  char text; // [rsp+150h] [rbp-2008h]
  va_list va; // [rsp+2170h] [rbp+18h]

  va_start(va, format);
  v2 = this;
  info.mStdOutBuffer.NumChars = 0;
  info.OutStringLen = 0x2000;
  info.OutString = &text;
  info.PrintChannel = -1;
  info.StdOut = 0;
  v3 = UFG::qPrintEngine(&info, format, va);
  if ( v3 )
    UFG::qStringBuilder::Add(v2, &text, v3);
}

// File Line: 2551
// RVA: 0x1816C0
void __fastcall UFG::qAddPrintHandler(int (__fastcall *handler)(void *, const char *), void *user_data)
{
  UFG::allocator::free_link *v2; // rdi
  int (__fastcall *v3)(void *, const char *); // rsi
  _RTL_CRITICAL_SECTION *v4; // rbx
  _RTL_CRITICAL_SECTION *v5; // rax
  UFG::qMemoryPool *v6; // rcx
  UFG::allocator::free_link *v7; // rax
  _QWORD *v8; // rcx
  __int64 *v9; // rdx
  _QWORD *v10; // rax

  v2 = (UFG::allocator::free_link *)user_data;
  v3 = handler;
  v4 = lpCriticalSection;
  if ( !lpCriticalSection )
  {
    UFG::qMutex::qMutex(&stru_14235BB80, &customWorldMapCaption);
    v4 = v5;
    lpCriticalSection = v5;
  }
  UFG::qMutex::Lock(v4);
  v6 = UFG::gMainMemoryPool;
  if ( !UFG::gMainMemoryPool )
  {
    UFG::InternalSetupMainMemoryPool((UFG *)UFG::gMainMemoryPool);
    v6 = UFG::gMainMemoryPool;
  }
  v7 = UFG::qMemoryPool::Allocate(v6, 0x20ui64, "qString.AddPrintHandler", 0i64, 1u);
  v8 = &v7->mNext;
  if ( v7 )
  {
    v7->mNext = v7;
    v7[1].mNext = v7;
    v7[2].mNext = (UFG::allocator::free_link *)v3;
    v7[3].mNext = v2;
  }
  else
  {
    v8 = 0i64;
  }
  v9 = (__int64 *)qword_14235BBC8;
  if ( !qword_14235BBC8 )
  {
    v9 = &qword_14235BBB8;
    qword_14235BBB8 = (__int64)&qword_14235BBB8;
    qword_14235BBC0 = (__int64)&qword_14235BBB8;
    qword_14235BBC8 = (__int64)&qword_14235BBB8;
  }
  v10 = (_QWORD *)v9[1];
  v9[1] = (__int64)v8;
  *v8 = v9;
  v8[1] = v10;
  *v10 = v8;
  UFG::qMutex::Unlock(v4);
}

// File Line: 2562
// RVA: 0x18A1E0
void __fastcall UFG::qRemovePrintHandler(int (__fastcall *handler_func)(void *, const char *), void *user_data)
{
  void *v2; // rbp
  int (__fastcall *v3)(void *, const char *); // r14
  _RTL_CRITICAL_SECTION *v4; // rsi
  _RTL_CRITICAL_SECTION *v5; // rax
  __int64 *v6; // rdi
  __int64 *v7; // rdx
  __int64 *v8; // rbx
  __int64 v9; // rax
  __int64 v10; // r8
  __int64 *v11; // rax

  v2 = user_data;
  v3 = handler_func;
  v4 = lpCriticalSection;
  if ( !lpCriticalSection )
  {
    UFG::qMutex::qMutex(&stru_14235BB80, &customWorldMapCaption);
    v4 = v5;
    lpCriticalSection = v5;
  }
  UFG::qMutex::Lock(v4);
  v6 = (__int64 *)qword_14235BBC8;
  if ( !qword_14235BBC8 )
  {
    v6 = &qword_14235BBB8;
    qword_14235BBB8 = (__int64)&qword_14235BBB8;
    qword_14235BBC0 = (__int64)&qword_14235BBB8;
    qword_14235BBC8 = (__int64)&qword_14235BBB8;
  }
  v7 = (__int64 *)v6[1];
  if ( v7 != v6 )
  {
    do
    {
      v8 = (__int64 *)v7[1];
      if ( (void *)v7[3] == v2 && (int (__fastcall *)(void *, const char *))v7[2] == v3 )
      {
        v9 = *v7;
        *(_QWORD *)(v9 + 8) = v8;
        *v8 = v9;
        *v7 = (__int64)v7;
        v7[1] = (__int64)v7;
        v10 = *v7;
        v11 = (__int64 *)v7[1];
        *(_QWORD *)(v10 + 8) = v11;
        *v11 = v10;
        *v7 = (__int64)v7;
        v7[1] = (__int64)v7;
        UFG::qMemoryPool::Free(UFG::gMainMemoryPool, v7);
      }
      v7 = v8;
    }
    while ( v8 != v6 );
  }
  UFG::qMutex::Unlock(v4);
}

// File Line: 2588
// RVA: 0x1835E0
_BOOL8 __fastcall UFG::qEnablePrintHandlers(bool enabled)
{
  _BOOL8 result; // rax

  result = sPrintHandlersEnabled;
  sPrintHandlersEnabled = enabled;
  return result;
}

// File Line: 2633
// RVA: 0x17DFD0
void __fastcall UFG::qPrintInfo::StuffChar(UFG::qPrintInfo *this, char c)
{
  UFG::qPrintInfo *v2; // r8
  char *v3; // rcx
  __int64 v4; // r9

  v2 = this;
  if ( this->StdOut )
  {
    if ( this->mStdOutBuffer.NumChars == 255 )
    {
      this->mStdOutBuffer.Buffer[255] = 0;
      this->mStdOutBuffer.NumChars = 0;
    }
    this->mStdOutBuffer.Buffer[this->mStdOutBuffer.NumChars++] = c;
  }
  else
  {
    v3 = this->OutString;
    if ( v3 )
    {
      v4 = v2->NumWritten;
      if ( (signed int)v4 < v2->OutStringLen - 1 )
      {
        v3[v4] = c;
        v2->OutString[v2->NumWritten + 1] = 0;
      }
    }
    ++v2->NumWritten;
  }
}

// File Line: 2659
// RVA: 0x17E040
void __fastcall UFG::qPrintInfo::StuffString(UFG::qPrintInfo *this, const char *text, int text_length)
{
  char v3; // r9
  const char *i; // r10
  char *v5; // rdx
  __int64 v6; // r11

  v3 = *text;
  for ( i = text; v3; --text_length )
  {
    if ( !text_length )
      break;
    if ( this->StdOut )
    {
      if ( this->mStdOutBuffer.NumChars == 255 )
      {
        this->mStdOutBuffer.Buffer[255] = 0;
        this->mStdOutBuffer.NumChars = 0;
      }
      this->mStdOutBuffer.Buffer[this->mStdOutBuffer.NumChars++] = v3;
    }
    else
    {
      v5 = this->OutString;
      if ( v5 )
      {
        v6 = this->NumWritten;
        if ( (signed int)v6 < this->OutStringLen - 1 )
        {
          v5[v6] = v3;
          this->OutString[this->NumWritten + 1] = 0;
        }
      }
      ++this->NumWritten;
    }
    v3 = (i++)[1];
  }
}

// File Line: 2680
// RVA: 0x17E0E0
void __fastcall UFG::qPrintInfo::StuffWideString(UFG::qPrintInfo *this, const wchar_t *text, int text_length)
{
  const wchar_t *i; // r9
  char v4; // dl
  char *v5; // r10
  __int64 v6; // r11

  for ( i = text; *i; --text_length )
  {
    if ( !text_length )
      break;
    v4 = *(_BYTE *)i;
    if ( this->StdOut )
    {
      if ( this->mStdOutBuffer.NumChars == 255 )
      {
        this->mStdOutBuffer.Buffer[255] = 0;
        this->mStdOutBuffer.NumChars = 0;
      }
      this->mStdOutBuffer.Buffer[this->mStdOutBuffer.NumChars++] = v4;
    }
    else
    {
      v5 = this->OutString;
      if ( v5 )
      {
        v6 = this->NumWritten;
        if ( (signed int)v6 < this->OutStringLen - 1 )
        {
          v5[v6] = v4;
          this->OutString[this->NumWritten + 1] = 0;
        }
      }
      ++this->NumWritten;
    }
    ++i;
  }
}

// File Line: 2713
// RVA: 0x15EFC0
const char *__fastcall UFG::PrintfHandleChar(const char *fmt, UFG::qPrintInfo *info, UFG::qPrintArgs *args, void *data)
{
  char v4; // al

  v4 = *(_BYTE *)data;
  args->ConvertBuffer[1] = 0;
  args->ConvertBuffer[0] = v4;
  args->pResultString = args->ConvertBuffer;
  args->ResultStringLength = 1;
  return fmt + 1;
}

// File Line: 2727
// RVA: 0x15EFE0
const char *__fastcall UFG::PrintfHandleWideString(const char *fmt, UFG::qPrintInfo *info, UFG::qPrintArgs *args, void *data)
{
  const char *v4; // rsi
  UFG::qPrintArgs *v5; // rbx
  const wchar_t *v6; // rbp
  const wchar_t *v7; // rdi
  int v8; // ecx
  const wchar_t *v9; // rcx
  wchar_t v10; // ax
  int v11; // eax

  v4 = fmt + 1;
  v5 = args;
  if ( fmt[1] == 113 )
  {
    *(_WORD *)args->Prefix = 34;
    *(_WORD *)args->Suffix = 34;
    v4 = fmt + 2;
  }
  args->WideString = 1;
  v6 = *(const wchar_t **)data;
  if ( *(_QWORD *)data )
  {
    v7 = L"[badptr]";
    if ( UFG::qIsValidPointer(*(const void **)data, 1) )
      v7 = v6;
  }
  else
  {
    v7 = L"[null]";
  }
  if ( UFG::qIsValidPointer(v7 + 8, 4) && *((_DWORD *)v7 + 4) == 16909060 )
    v7 = (const wchar_t *)*((_QWORD *)v7 + 3);
  if ( v7 )
  {
    v9 = v7;
    do
    {
      v10 = *v9;
      ++v9;
    }
    while ( v10 );
    v8 = (unsigned __int64)(v9 - v7) - 1;
  }
  else
  {
    v8 = 0;
  }
  v11 = v5->Precision;
  v5->pResultString = (const char *)v7;
  if ( v8 <= v11 || v11 < 0 )
    v5->ResultStringLength = v8;
  else
    v5->ResultStringLength = v11;
  return v4;
}

// File Line: 2786
// RVA: 0x15F0C0
const char *__fastcall UFG::PrintfHandleString(const char *fmt, UFG::qPrintInfo *info, UFG::qPrintArgs *args, void *data)
{
  const char *v4; // rsi
  UFG::qPrintArgs *v5; // rdi
  const char *v6; // rbp
  const char *v7; // rbx
  int v8; // ecx
  const char *v9; // rcx
  char v10; // al
  int v11; // eax

  v4 = fmt + 1;
  v5 = args;
  if ( fmt[1] == 113 )
  {
    *(_WORD *)args->Prefix = 34;
    *(_WORD *)args->Suffix = 34;
    v4 = fmt + 2;
  }
  v6 = *(const char **)data;
  if ( *(_QWORD *)data )
  {
    v7 = "[badptr]";
    if ( UFG::qIsValidPointer(*(const void **)data, 1) )
      v7 = v6;
  }
  else
  {
    v7 = "[null]";
  }
  if ( UFG::qIsValidPointer(v7 + 16, 4) && *((_DWORD *)v7 + 4) == 16909060 )
    v7 = (const char *)*((_QWORD *)v7 + 3);
  if ( v7 )
  {
    v9 = v7;
    do
      v10 = *v9++;
    while ( v10 );
    v8 = (_DWORD)v9 - (_DWORD)v7 - 1;
  }
  else
  {
    v8 = 0;
  }
  v11 = v5->Precision;
  v5->pResultString = v7;
  if ( v8 <= v11 || v11 < 0 )
    v5->ResultStringLength = v8;
  else
    v5->ResultStringLength = v11;
  return v4;
}

// File Line: 2867
// RVA: 0x15F190
const char *__fastcall UFG::PrintfHandleInt(const char *fmt, UFG::qPrintInfo *info, UFG::qPrintArgs *args, void *data)
{
  char v4; // al
  signed int v5; // edx
  char v6; // bl
  char v7; // si
  char v8; // bp
  UFG::qPrintArgs *v9; // r10
  signed int v10; // er11
  const char *v11; // rdi
  unsigned __int64 v12; // r9
  bool v13; // r14
  int v14; // eax
  char v15; // bl
  int v16; // eax
  char *v17; // r8
  int v18; // edx
  char v19; // dl
  char *v20; // r8
  int v21; // ecx
  char *v22; // rcx
  char v23; // al
  int i; // edx
  char *v25; // rcx
  char v26; // al

  v4 = *fmt;
  v5 = 32;
  v6 = 0;
  v7 = 0;
  v8 = 0;
  v9 = args;
  v10 = 10;
  if ( *fmt == 120 )
  {
    v10 = 16;
  }
  else if ( v4 == 88 )
  {
    v10 = 16;
    v7 = 1;
  }
  else if ( v4 != 100 && v4 != 68 && v4 != 105 && v4 != 73 )
  {
    switch ( v4 )
    {
      case 117:
        v6 = 1;
        break;
      case 112:
        args->Flags |= 8u;
        v10 = 16;
        v5 = 64;
        v8 = 1;
        v7 = 0;
        args->Width = 16;
        break;
      case 80:
        args->Flags |= 8u;
        v10 = 16;
        v8 = 1;
        args->Width = 16;
        v7 = 1;
        v5 = 64;
        break;
      case 98:
        v10 = 2;
        break;
    }
  }
  v11 = fmt + 1;
  if ( fmt[1] == 54 && fmt[2] == 52 )
  {
    v5 = 64;
    v11 = fmt + 3;
  }
  v12 = *(_QWORD *)data;
  v13 = v12 >> ((unsigned __int8)v5 - 1) != 0;
  if ( v10 == 10 )
  {
    if ( v6 || !v13 )
    {
      v14 = args->Flags;
      if ( v14 & 2 )
      {
        *(_WORD *)args->Prefix = 43;
      }
      else if ( v14 & 4 )
      {
        *(_WORD *)args->Prefix = 32;
      }
    }
    else
    {
      v12 = -(signed __int64)v12;
      *(_WORD *)args->Prefix = 45;
    }
  }
  if ( v5 == 32 )
    v12 = (unsigned int)v12;
  v15 = 0;
  if ( v10 == 16 )
  {
    v15 = 39;
    if ( v7 )
      v15 = 7;
    if ( v8 )
    {
      *(_WORD *)args->Prefix = 30768;
      args->Prefix[2] = 0;
    }
    v16 = args->Width;
    if ( v16
      && (signed __int64)(v12 << (64 - (unsigned __int8)v5)) >> (64 - (unsigned __int8)v5) >> 4 * (unsigned __int8)v16 == -1 )
    {
      v12 &= (1i64 << 4 * (unsigned __int8)v16) - 1;
    }
  }
  if ( args->Precision >= 0 )
    args->Flags &= 0xFFFFFFF7;
  else
    args->Precision = 1;
  v17 = &args->ConvertBuffer[63];
  v9->ConvertBuffer[63] = 0;
  while ( 1 )
  {
    v18 = v9->Precision;
    --v17;
    --v9->Precision;
    if ( v18 <= 0 && !v12 )
      break;
    v19 = v12 % v10 + 48;
    v12 /= (unsigned __int64)v10;
    if ( v19 > 57 )
      v19 += v15;
    *v17 = v19;
  }
  v20 = v17 + 1;
  if ( v9->Flags & 8 )
  {
    if ( v20 )
    {
      v22 = v20;
      do
        v23 = *v22++;
      while ( v23 );
      v21 = (_DWORD)v22 - (_DWORD)v20 - 1;
    }
    else
    {
      v21 = 0;
    }
    for ( i = v9->Width - (v13 != 0) - v21; i > 0; *v20 = 48 )
    {
      --v20;
      --i;
    }
  }
  v9->pResultString = v20;
  if ( v20 )
  {
    v25 = v20;
    do
      v26 = *v25++;
    while ( v26 );
    v9->ResultStringLength = (_DWORD)v25 - (_DWORD)v20 - 1;
  }
  else
  {
    v9->ResultStringLength = 0;
  }
  return v11;
}

// File Line: 2981
// RVA: 0x16A400
__int64 __fastcall UFG::ComputeFloatExponent(long double val)
{
  __int64 result; // rax
  bool i; // dl
  signed int j; // ecx

  result = 0i64;
  for ( i = val < 1.0; val >= 10.0; result = (unsigned int)(result + 1) )
    val = val * 0.1;
  for ( j = (signed int)val; val != 0.0; j = (signed int)val )
  {
    if ( j )
      break;
    val = val * 10.0;
    result = (unsigned int)(result + 1);
  }
  if ( i )
    result = (unsigned int)-(signed int)result;
  return result;
}

// File Line: 3026
// RVA: 0x15F3E0
const char *__fastcall UFG::PrintfHandleFloatExp(const char *fmt, UFG::qPrintInfo *info, UFG::qPrintArgs *args, void *data)
{
  UFG::qPrintArgs *v4; // rbx
  const char *v5; // rsi
  bool v7; // r15
  __int64 v8; // rcx
  int v9; // ebp
  const char *v10; // rdx
  const char *v11; // rcx
  char v12; // al
  double v13; // xmm3_8
  char v14; // r14
  int v15; // eax
  int v16; // er8
  _BYTE *v17; // r11
  int v18; // er9
  double v19; // xmm5_8
  double v20; // xmm0_8
  double v21; // xmm2_8
  int v22; // edx
  unsigned int v23; // eax
  __int64 v24; // rcx
  __int64 v25; // rax
  int v26; // ecx
  double v27; // xmm0_8
  bool v28; // di
  int v29; // er10
  int v30; // ecx
  unsigned int v31; // eax
  double v32; // xmm2_8
  double v33; // xmm4_8
  double i; // xmm3_8
  char v35; // dl
  _BYTE *v36; // rcx
  __int64 v37; // rcx
  char v38; // al
  int v39; // er8
  __int64 v40; // rcx
  char v41; // al
  int v42; // er8
  __int64 v43; // r10
  int v44; // er8
  unsigned int v45; // er9
  int v46; // er9
  char *v47; // rcx
  char v48; // al
  signed int v49; // ecx
  char *v50; // rcx
  char v51; // al

  v4 = args;
  v5 = fmt;
  if ( !fmt )
    return 0i64;
  v7 = ((*fmt - 69) & 0xFD) == 0;
  v8 = *(_QWORD *)data >> 32;
  v9 = 0;
  if ( ((*(_QWORD *)data >> 32) & 0x7FF00000) == 2146435072 )
  {
    if ( (_DWORD)v8 == -1048576 )
    {
      v10 = "-1.#INF";
    }
    else
    {
      v10 = "1.#INF ";
      if ( (_DWORD)v8 != 2146435072 )
        v10 = "1.#QNAN";
    }
  }
  else
  {
    v10 = 0i64;
  }
  args->pResultString = v10;
  if ( !v10 )
  {
    v13 = *(double *)data;
    v14 = 0;
    args->ConvertBuffer[10] = 0;
    if ( v13 < 0.0 )
    {
      v13 = -v13;
      v14 = 1;
    }
    v15 = UFG::ComputeFloatExponent(v13);
    v18 = v15;
    v19 = DOUBLE_1_0;
    if ( v15 )
    {
      v20 = DOUBLE_10_0;
      if ( v15 < 0 )
        v15 = -v15;
      v21 = DOUBLE_1_0;
      while ( 1 )
      {
        if ( v15 & 1 )
          v21 = v21 * v20;
        v15 = (unsigned int)v15 >> 1;
        if ( !v15 )
          break;
        v20 = v20 * v20;
      }
      if ( v18 >= 0 )
        v19 = v21;
      else
        v19 = 1.0 / v21;
    }
    if ( v19 == 0.0 )
    {
      v22 = v18;
      if ( -v18 >= 8 )
      {
        v23 = ((unsigned int)(-8 - v18) >> 3) + 1;
        v24 = v23;
        v22 = v18 + 8 * v23;
        do
        {
          v13 = v13 * 10.0 * 10.0 * 10.0 * 10.0 * 10.0 * 10.0 * 10.0 * 10.0;
          --v24;
        }
        while ( v24 );
      }
      if ( v22 < 0 )
      {
        v25 = -v22;
        do
        {
          v13 = v13 * 10.0;
          --v25;
        }
        while ( v25 );
      }
    }
    else if ( v19 != 1.0 )
    {
      v13 = v13 / v19;
    }
    v26 = v4->Precision;
    v27 = DOUBLE_10_0;
    if ( v4->Precision == -1 )
      v26 = sPrintPrecisionDefault;
    v28 = v26 == 0;
    v29 = v26 + 1;
    v30 = -v26;
    v31 = v30;
    if ( v30 < 0 )
      v31 = -v30;
    v32 = DOUBLE_1_0;
    while ( 1 )
    {
      if ( v31 & 1 )
        v32 = v32 * v27;
      v31 >>= 1;
      if ( !v31 )
        break;
      v27 = v27 * v27;
    }
    if ( v30 >= 0 )
      v33 = v32;
    else
      v33 = 1.0 / v32;
    for ( i = v13 + v33 * 0.5; i >= 10.0; ++v18 )
      i = i * 0.1;
    v35 = 1;
    if ( v29 )
    {
      v36 = v17;
      do
      {
        ++v16;
        *(++v36 - 1) = (signed int)i + 48;
        i = (i - (double)(signed int)i) * 10.0;
        if ( v35 )
        {
          if ( !v28 )
          {
            *v36 = 46;
            ++v16;
            ++v36;
          }
          v35 = 0;
        }
        --v29;
      }
      while ( v29 );
    }
    v37 = v16;
    v38 = 101;
    if ( v7 )
      v38 = 69;
    v39 = v16 + 1;
    v17[v37] = v38;
    v40 = v39;
    v41 = 43;
    if ( v18 < 0 )
      v41 = 45;
    v42 = v39 + 1;
    v17[v40] = v41;
    if ( v18 < 0 )
      v18 = -v18;
    v43 = v42;
    v44 = v18 / 10;
    v17[v43 + 2] = v18 % 10 + 48;
    v45 = (signed int)((unsigned __int64)(1717986919i64 * (v18 / 10)) >> 32) >> 2;
    v46 = (v45 >> 31) + v45;
    v17[v43 + 1] = v44 - 10 * v46 + 48;
    v17[v43] = v46 % 10 + 48;
    v17[v43 + 3] = 0;
    if ( !(v4->Flags & 8) )
      goto LABEL_70;
    v47 = v17;
    do
      v48 = *v47++;
    while ( v48 );
    LOBYTE(v9) = v14 != 0;
    v49 = v4->Width - v9 - ((_DWORD)v47 - (_DWORD)v17 - 1);
    if ( v49 <= 10 )
    {
      if ( v49 <= 0 )
      {
LABEL_70:
        if ( v14 )
          *--v17 = 45;
        v4->pResultString = v17;
        v50 = v17;
        do
          v51 = *v50++;
        while ( v51 );
        v4->ResultStringLength = (_DWORD)v50 - (_DWORD)v17 - 1;
        return v5 + 1;
      }
    }
    else
    {
      v49 = 10;
    }
    do
    {
      --v17;
      --v49;
      *v17 = 48;
    }
    while ( v49 > 0 );
    goto LABEL_70;
  }
  v11 = v10;
  do
    v12 = *v11++;
  while ( v12 );
  args->ResultStringLength = (_DWORD)v11 - (_DWORD)v10 - 1;
  return v5 + 1;
}

// File Line: 3140
// RVA: 0x15E7F0
const char *__fastcall UFG::PrintfHandleFloatNorm(const char *fmt, UFG::qPrintInfo *info, UFG::qPrintArgs *args, void *data)
{
  int v4; // er11
  const char *v5; // rbx
  __int64 v6; // r10
  const char *v7; // rdx
  const char *v8; // rcx
  char v9; // al
  double v11; // xmm1_8
  const char *v12; // r10
  bool v13; // zf
  char *v14; // rdx
  char v15; // di
  int v16; // eax
  double v17; // xmm2_8
  int v18; // er9
  double v19; // xmm0_8
  double v20; // xmm1_8
  char *i; // rax
  char *v22; // rcx
  int v23; // er9
  const char *v24; // r9
  char v25; // al
  int v26; // edx
  char *v27; // rdx
  char v28; // al

  v4 = 0;
  v5 = fmt;
  v6 = *(_QWORD *)data >> 32;
  if ( ((*(_QWORD *)data >> 32) & 0x7FF00000) == 2146435072 )
  {
    if ( (_DWORD)v6 == -1048576 )
    {
      v7 = "-1.#INF";
    }
    else
    {
      v7 = "1.#INF ";
      if ( (_DWORD)v6 != 2146435072 )
        v7 = "1.#QNAN";
    }
  }
  else
  {
    v7 = 0i64;
  }
  args->pResultString = v7;
  if ( v7 )
  {
    v8 = v7;
    do
      v9 = *v8++;
    while ( v9 );
    args->ResultStringLength = (_DWORD)v8 - (_DWORD)v7 - 1;
    return v5 + 1;
  }
  v11 = *(double *)data;
  v12 = &args->ConvertBuffer[10];
  args->ConvertBuffer[10] = 48;
  v13 = args->Precision == -1;
  v14 = &args->ConvertBuffer[11];
  args->pResultString = &args->ConvertBuffer[11];
  if ( v13 )
    args->Precision = sPrintPrecisionDefault;
  v15 = 0;
  if ( v11 >= 0.0 )
  {
    v16 = args->Flags;
    if ( v16 & 2 )
    {
      *(_WORD *)args->Prefix = 43;
    }
    else if ( v16 & 4 )
    {
      *(_WORD *)args->Prefix = 32;
    }
  }
  else
  {
    v11 = -v11;
    *(_WORD *)args->Prefix = 45;
    v15 = 1;
  }
  v17 = DOUBLE_1_0;
  if ( v11 > 1.0 )
  {
    do
      v17 = v17 * 10.0;
    while ( v17 < v11 );
  }
  if ( v17 > v11 )
    v17 = v17 * 0.1;
  v18 = 0;
  if ( v17 < 1.0 )
    goto LABEL_56;
  do
  {
    ++v14;
    ++v18;
    *(v14 - 1) = (signed int)(v11 / v17) + 48;
    v19 = (double)(char)(signed int)(v11 / v17) * v17;
    v17 = v17 * 0.1;
    v11 = v11 - v19;
  }
  while ( v17 >= 1.0 );
  if ( !v18 )
LABEL_56:
    *v14++ = 48;
  if ( args->Precision )
  {
    for ( *v14++ = 46; args->Precision; v11 = v20 - (double)(char)(signed int)v20 )
    {
      --args->Precision;
      v20 = v11 * 10.0;
      *(++v14 - 1) = (signed int)v20 + 48;
    }
  }
  --args->Precision;
  if ( v11 * 10.0 >= 5.0 )
  {
    for ( i = v14 - 1; ; --i )
    {
      while ( *i == 57 )
        *i-- = 48;
      if ( *i != 46 )
        break;
    }
    ++*i;
    if ( i == v12 )
      args->pResultString = v12;
  }
  *v14 = 0;
  v22 = (char *)args->pResultString;
  if ( args->Flags & 8 )
  {
    if ( v22 )
    {
      v24 = args->pResultString;
      do
        v25 = *v24++;
      while ( v25 );
      v23 = (_DWORD)v24 - (_DWORD)v22 - 1;
    }
    else
    {
      v23 = 0;
    }
    v26 = args->Width - (v15 != 0) - v23;
    if ( v26 > 10 )
    {
      v26 = 10;
      goto LABEL_48;
    }
    if ( v26 > 0 )
    {
      do
      {
LABEL_48:
        --v22;
        --v26;
        *v22 = 48;
      }
      while ( v26 > 0 );
      goto LABEL_49;
    }
  }
LABEL_49:
  args->pResultString = v22;
  if ( v22 )
  {
    v27 = v22;
    do
      v28 = *v27++;
    while ( v28 );
    v4 = (_DWORD)v27 - (_DWORD)v22 - 1;
  }
  args->ResultStringLength = v4;
  return v5 + 1;
}

// File Line: 3266
// RVA: 0x15EA60
const char *__fastcall UFG::PrintfHandleFloatSmrt(const char *fmt, UFG::qPrintInfo *info, UFG::qPrintArgs *args, void *data)
{
  UFG::qPrintArgs *v4; // rsi
  const char *v5; // r10
  int v7; // edi
  __int64 v8; // rcx
  const char *v9; // rdx
  const char *v10; // rcx
  char v11; // al
  double v12; // xmm0_8
  int v13; // eax
  UFG::qPrintArgs *v14; // r8
  void *v15; // r9
  const char *v16; // r10
  UFG::qPrintInfo *v17; // r11
  int v18; // ecx
  char v19; // bl
  const char *v20; // rax
  const char *v21; // r11
  const char *v22; // rbp
  const char *v23; // rcx
  char v24; // al
  int v25; // eax
  int v26; // er9
  __int16 *v27; // rdx
  const char *v28; // rcx
  signed int v29; // er8
  signed __int64 v30; // r9
  const char *v31; // rcx
  char v32; // al
  int v33; // ecx
  int v34; // er10
  int i; // er9
  __int16 *v36; // rdx
  const char *v37; // rcx
  signed int v38; // eax
  const char *v39; // rcx
  const char *v40; // rcx
  char v41; // al
  int v42; // ecx
  int v43; // er10
  int j; // er9
  __int16 *v45; // rdx
  const char *v46; // rcx
  signed int v47; // eax
  int v48; // er8
  _BYTE *k; // rcx
  char *v50; // rcx
  char *v51; // rdx
  char v52; // al
  __int64 v53; // rdx
  char v54; // al
  __int16 v55; // [rsp+30h] [rbp+8h]

  v4 = args;
  v5 = fmt;
  if ( !fmt )
    return 0i64;
  v7 = 0;
  v8 = *(_QWORD *)data >> 32;
  if ( (v8 & 0x7FF00000) == 2146435072 )
  {
    if ( (_DWORD)v8 == -1048576 )
    {
      v9 = "-1.#INF";
    }
    else
    {
      v9 = "1.#INF ";
      if ( (_DWORD)v8 != 2146435072 )
        v9 = "1.#QNAN";
    }
  }
  else
  {
    v9 = 0i64;
  }
  args->pResultString = v9;
  if ( !v9 )
  {
    v12 = *(double *)data;
    if ( *(double *)data < 0.0 )
      v12 = -v12;
    v13 = UFG::ComputeFloatExponent(v12);
    v18 = v14->Precision;
    if ( v14->Precision == -1 )
      v18 = sPrintPrecisionDefault;
    v19 = 0;
    if ( v13 < -4 || v13 >= v18 )
    {
      v19 = 1;
      if ( v18 > 0 )
        --v18;
      v14->Precision = v18;
      v20 = UFG::PrintfHandleFloatExp(v16, v17, v14, v15);
    }
    else
    {
      v14->Precision = v18 - v13 - 1;
      v20 = UFG::PrintfHandleFloatNorm(v16, v17, v14, v15);
    }
    v21 = v4->pResultString;
    v22 = v20;
    v55 = 46;
    if ( v21 )
    {
      v23 = v21;
      do
        v24 = *v23++;
      while ( v24 );
      v25 = (_DWORD)v23 - (_DWORD)v21 - 1;
      if ( *v21 )
      {
        if ( (_DWORD)v23 - (_DWORD)v21 != 1 )
        {
          v26 = 0;
          if ( (signed int)v23 - (signed int)v21 - 2 >= 0 )
          {
            while ( 1 )
            {
              v27 = &v55;
              v28 = &v21[v26];
              if ( v28 )
                break;
LABEL_48:
              if ( ++v26 > v25 - 1 )
                return v22;
            }
            v29 = 1;
            while ( *v28 && *v28 == *(_BYTE *)v27 )
            {
              ++v28;
              v27 = (__int16 *)((char *)v27 + 1);
              if ( !--v29 )
                goto LABEL_35;
            }
            if ( *(unsigned __int8 *)v28 != *(unsigned __int8 *)v27 )
              goto LABEL_48;
LABEL_35:
            if ( !&v21[v26] )
              return v22;
            v30 = (signed __int64)&v21[v4->ResultStringLength - 1];
            if ( v19 )
            {
              v55 = 101;
              v31 = v21;
              do
                v32 = *v31++;
              while ( v32 );
              v33 = (_DWORD)v31 - (_DWORD)v21;
              if ( v33 != 1 )
              {
                v34 = v33 - 2;
                for ( i = 0; i <= v34; ++i )
                {
                  v36 = &v55;
                  v37 = &v21[i];
                  if ( v37 )
                  {
                    v38 = 1;
                    while ( *v37 && *v37 == *(_BYTE *)v36 )
                    {
                      ++v37;
                      v36 = (__int16 *)((char *)v36 + 1);
                      if ( !--v38 )
                        goto LABEL_46;
                    }
                    if ( *(unsigned __int8 *)v37 == *(unsigned __int8 *)v36 )
                    {
LABEL_46:
                      v39 = &v21[i];
                      goto LABEL_53;
                    }
                  }
                }
              }
              v39 = 0i64;
LABEL_53:
              if ( !v39 )
              {
                v55 = 69;
                v40 = v21;
                do
                  v41 = *v40++;
                while ( v41 );
                v42 = (_DWORD)v40 - (_DWORD)v21;
                if ( v42 != 1 )
                {
                  v43 = v42 - 2;
                  for ( j = 0; j <= v43; ++j )
                  {
                    v45 = &v55;
                    v46 = &v21[j];
                    if ( v46 )
                    {
                      v47 = 1;
                      while ( *v46 && *v46 == *(_BYTE *)v45 )
                      {
                        ++v46;
                        v45 = (__int16 *)((char *)v45 + 1);
                        if ( !--v47 )
                          goto LABEL_63;
                      }
                      if ( *(unsigned __int8 *)v46 == *(unsigned __int8 *)v45 )
                      {
LABEL_63:
                        v39 = &v21[j];
                        goto LABEL_67;
                      }
                    }
                  }
                }
                v39 = 0i64;
LABEL_67:
                if ( !v39 )
                  return v22;
              }
              v30 = (signed __int64)(v39 - 1);
            }
            v48 = 0;
            for ( k = (_BYTE *)v30; !((*k - 46) & 0xFD); --k )
            {
              ++v48;
              if ( *k == 46 )
                break;
            }
            if ( v48 )
            {
              v50 = (char *)(v30 + 1);
              if ( v30 != -1 )
              {
                v51 = (char *)(v30 + 1);
                do
                  v52 = *v51++;
                while ( v52 );
                v7 = (_DWORD)v51 - (_DWORD)v50 - 1;
              }
              v53 = v7 + 1;
              if ( v7 + 1 > 0 )
              {
                do
                {
                  v54 = *v50++;
                  v50[-(signed __int64)v48 - 1] = v54;
                  --v53;
                }
                while ( v53 );
              }
              v4->ResultStringLength -= v48;
            }
          }
        }
      }
    }
    return v22;
  }
  v10 = v9;
  do
    v11 = *v10++;
  while ( v11 );
  args->ResultStringLength = (_DWORD)v10 - (_DWORD)v9 - 1;
  return v5 + 1;
}

// File Line: 3351
// RVA: 0x15EDC0
const char *__fastcall UFG::PrintfHandleVector(const char *fmt, UFG::qPrintInfo *info, UFG::qPrintArgs *args, void *data)
{
  const char *v4; // rbx
  UFG::qPrintArgs *v5; // rdi
  signed int v6; // eax
  float *v7; // rcx
  double v8; // ST40_8
  int v9; // ST30_4
  double v10; // ST28_8
  int v11; // ST20_4
  double v12; // ST58_8
  double v13; // ST40_8
  int v14; // ST30_4
  double v15; // ST28_8
  int v16; // ST20_4
  double v17; // ST70_8
  double v18; // ST58_8
  double v19; // ST40_8
  int v20; // ST30_4
  double v21; // ST28_8
  int v22; // ST20_4
  signed __int64 v23; // r8
  signed int v24; // edx
  char *v25; // rcx
  char v26; // al
  char *v27; // rcx
  char v28; // al
  char dest[72]; // [rsp+80h] [rbp-48h]

  v4 = fmt + 1;
  v5 = args;
  v6 = 3;
  if ( fmt[1] == 50 )
  {
    v6 = 2;
    v4 = fmt + 2;
  }
  if ( *v4 == 51 )
  {
    v6 = 3;
    ++v4;
  }
  if ( *v4 == 52 )
  {
    v6 = 4;
    ++v4;
  }
  v7 = *(float **)data;
  switch ( v6 )
  {
    case 2:
      v8 = v7[1];
      v9 = args->Width;
      v10 = *v7;
      v11 = args->Precision;
      UFG::qSPrintf(dest, 50, "[%*.*f,%*.*f]");
      break;
    case 3:
      v12 = v7[2];
      v13 = v7[1];
      v14 = args->Width;
      v15 = *v7;
      v16 = args->Precision;
      UFG::qSPrintf(dest, 50, "[%*.*f,%*.*f,%*.*f]");
      break;
    case 4:
      v17 = v7[3];
      v18 = v7[2];
      v19 = v7[1];
      v20 = args->Width;
      v21 = *v7;
      v22 = args->Precision;
      UFG::qSPrintf(dest, 50, "[%*.*f,%*.*f,%*.*f,%*.*f]");
      break;
  }
  v23 = (signed __int64)v5->ConvertBuffer;
  v24 = 64;
  if ( v5 != (UFG::qPrintArgs *)-18i64 )
  {
    v25 = v5->ConvertBuffer;
    do
    {
      v26 = dest[(_QWORD)v25++ - v23];
      *(v25 - 1) = v26;
      if ( !v26 )
        break;
      --v24;
    }
    while ( v24 > 1 );
    if ( *(v25 - 1) )
      *v25 = 0;
  }
  v5->pResultString = (const char *)v23;
  if ( v5 == (UFG::qPrintArgs *)-18i64 )
  {
    MEMORY[0x4E] = 0;
  }
  else
  {
    v27 = v5->ConvertBuffer;
    do
      v28 = *v27++;
    while ( v28 );
    v5->ResultStringLength = (_DWORD)v27 - v23 - 1;
  }
  return v4;
}

// File Line: 3444
// RVA: 0x188C90
__int64 __fastcall UFG::qPrintEngine(UFG::qPrintInfo *info, const char *fmt, char *arg_list)
{
  char *v3; // rax
  char *v4; // r14
  const char *v5; // rdi
  UFG::qPrintInfo *v6; // rbx
  char v7; // cl
  char *v8; // rdx
  __int64 v9; // r8
  char v10; // al
  int v11; // eax
  int v12; // er8
  int v13; // er9
  char v14; // cl
  char v15; // dl
  int v16; // eax
  char v17; // dl
  int v18; // eax
  UFG::qPrintfHandler *v19; // r9
  signed int v20; // eax
  const char *v21; // rdx
  const char *v22; // rcx
  const char *(__fastcall *v23)(const char *, UFG::qPrintInfo *, UFG::qPrintArgs *, void *); // r10
  __int64 v24; // xmm0_8
  int v25; // eax
  __int64 v26; // rax
  __int64 v27; // rax
  char *v28; // rcx
  char v29; // al
  int v30; // edx
  char *v31; // rcx
  char v32; // al
  int v33; // eax
  int v34; // esi
  int v35; // er8
  char *v36; // rcx
  __int64 v37; // rdx
  char *v38; // rdx
  char v39; // r9
  char *v40; // rcx
  __int64 v41; // r8
  char *v42; // rdx
  char v43; // r9
  char *v44; // rcx
  __int64 v45; // r8
  int i; // er8
  char *v47; // rcx
  __int64 v48; // rdx
  int v50; // [rsp+20h] [rbp-39h]
  int v51; // [rsp+24h] [rbp-35h]
  int v52; // [rsp+28h] [rbp-31h]
  char v53; // [rsp+2Ch] [rbp-2Dh]
  char v54; // [rsp+2Fh] [rbp-2Ah]
  char v55; // [rsp+32h] [rbp-27h]
  wchar_t *text; // [rsp+78h] [rbp+1Fh]
  int text_length; // [rsp+80h] [rbp+27h]
  char v58; // [rsp+84h] [rbp+2Bh]
  __int64 v59; // [rsp+C0h] [rbp+67h]

  v3 = info->OutString;
  v4 = arg_list;
  v5 = fmt;
  v6 = info;
  info->OriginalFmt = fmt;
  info->NumWritten = 0;
  if ( v3 )
    *v3 = 0;
  v7 = *fmt;
  if ( *fmt )
  {
    do
    {
      if ( v7 == 37 )
      {
        v10 = v5[1];
        if ( v10 == 37 )
        {
          UFG::qPrintInfo::StuffChar(v6, 37);
          v5 += 2;
        }
        else
        {
          if ( v10 != 32 )
          {
            v11 = 0;
            ++v5;
            v12 = -1;
            v13 = 0;
            v51 = 0;
            text = (wchar_t *)&v55;
            v53 = 0;
            v54 = 0;
            v50 = -1;
            v55 = 0;
            v58 = 0;
            while ( 1 )
            {
              while ( 1 )
              {
                while ( 1 )
                {
                  while ( 1 )
                  {
                    v52 = v11;
                    v14 = *v5;
                    if ( *v5 != 45 )
                      break;
                    v11 |= 1u;
                    ++v5;
                  }
                  if ( v14 != 43 )
                    break;
                  v11 |= 2u;
                  ++v5;
                }
                if ( v14 != 32 )
                  break;
                v11 |= 4u;
                ++v5;
              }
              if ( v14 != 48 )
                break;
              v11 |= 8u;
              ++v5;
            }
            v15 = *v5;
            if ( *v5 == 42 )
            {
              v16 = *(_DWORD *)v4;
              v4 += 8;
              ++v5;
              v51 = v16;
            }
            else
            {
              for ( ; *v5 <= 57 && *v5 >= 48; v15 = *v5 )
              {
                ++v5;
                v13 = v15 + 2 * (v13 + 4 * (v13 - 6));
                v51 = v13;
              }
            }
            if ( *v5 == 46 )
            {
              v12 = 0;
              v50 = 0;
              ++v5;
            }
            v17 = *v5;
            if ( *v5 == 42 )
            {
              v18 = *(_DWORD *)v4;
              v4 += 8;
              ++v5;
              v50 = v18;
            }
            else
            {
              for ( ; *v5 <= 57 && *v5 >= 48; v17 = *v5 )
              {
                ++v5;
                v12 = v17 + 2 * (v12 + 4 * (v12 - 6));
                v50 = v12;
              }
            }
            v19 = sPrintfHandlers;
            while ( 1 )
            {
              v20 = v19->NameLen;
              v21 = v19->Name;
              v22 = v5;
              if ( v5 )
              {
                if ( v21 )
                {
                  if ( v20 < 0 )
                    v20 = -1;
                  if ( !v20 )
                    break;
                  while ( *v22 && *v22 == *v21 )
                  {
                    ++v22;
                    ++v21;
                    if ( !--v20 )
                      goto LABEL_45;
                  }
                  if ( *(unsigned __int8 *)v22 == *(unsigned __int8 *)v21 )
                    break;
                }
              }
              ++v19;
              if ( v19 == (UFG::qPrintfHandler *)UFG::qProfiler::sReportNames )
                goto LABEL_106;
            }
LABEL_45:
            v23 = v19->Handler;
            v59 = 0i64;
            if ( v23 == UFG::PrintfHandleFloatSmrt
              || v23 == UFG::PrintfHandleFloatExp
              || v23 == UFG::PrintfHandleFloatNorm )
            {
              v24 = *(_QWORD *)v4;
              v4 += 8;
              v59 = v24;
              goto LABEL_55;
            }
            v25 = v19->Size;
            if ( v25 == 32 )
            {
              v26 = *(unsigned int *)v4;
              v4 += 8;
              goto LABEL_54;
            }
            if ( v25 == 64 )
            {
              v26 = *(_QWORD *)v4;
              v4 += 8;
LABEL_54:
              v59 = v26;
            }
LABEL_55:
            v27 = ((__int64 (__fastcall *)(const char *, UFG::qPrintInfo *, int *, __int64 *, _QWORD))v23)(
                    v5,
                    v6,
                    &v50,
                    &v59,
                    *(_QWORD *)&v50);
            v28 = &v53;
            v5 = (const char *)v27;
            do
              v29 = *v28++;
            while ( v29 );
            v30 = (_DWORD)v28 - (unsigned __int64)&v53 - 1;
            v31 = &v54;
            do
              v32 = *v31++;
            while ( v32 );
            v33 = text_length;
            v34 = text_length + v30 + (_DWORD)v31 - (unsigned __int64)&v54 - 1;
            if ( !(v52 & 1) )
            {
              v35 = v51 - (text_length + v30 + (_DWORD)v31 - (unsigned __int64)&v54);
              if ( (signed int)(v51 - (text_length + v30 + (_DWORD)v31 - (unsigned __int64)&v54)) >= 0 )
              {
                do
                {
                  if ( v6->StdOut )
                  {
                    if ( v6->mStdOutBuffer.NumChars == 255 )
                    {
                      v6->mStdOutBuffer.Buffer[255] = 0;
                      v6->mStdOutBuffer.NumChars = 0;
                    }
                    v6->mStdOutBuffer.Buffer[v6->mStdOutBuffer.NumChars++] = 32;
                  }
                  else
                  {
                    v36 = v6->OutString;
                    if ( v36 )
                    {
                      v37 = v6->NumWritten;
                      if ( (signed int)v37 < v6->OutStringLen - 1 )
                      {
                        v36[v37] = 32;
                        v6->OutString[v6->NumWritten + 1] = 0;
                      }
                    }
                    ++v6->NumWritten;
                  }
                  --v35;
                }
                while ( v35 >= 0 );
                v33 = text_length;
              }
            }
            v38 = &v53;
            if ( v53 )
            {
              do
              {
                v39 = *v38;
                if ( v6->StdOut )
                {
                  if ( v6->mStdOutBuffer.NumChars == 255 )
                  {
                    v6->mStdOutBuffer.Buffer[255] = 0;
                    v6->mStdOutBuffer.NumChars = 0;
                  }
                  v6->mStdOutBuffer.Buffer[v6->mStdOutBuffer.NumChars++] = v39;
                }
                else
                {
                  v40 = v6->OutString;
                  if ( v40 )
                  {
                    v41 = v6->NumWritten;
                    if ( (signed int)v41 < v6->OutStringLen - 1 )
                    {
                      v40[v41] = v39;
                      v6->OutString[v6->NumWritten + 1] = 0;
                    }
                  }
                  ++v6->NumWritten;
                }
                ++v38;
              }
              while ( *v38 );
              v33 = text_length;
            }
            if ( v58 )
              UFG::qPrintInfo::StuffWideString(v6, text, v33);
            else
              UFG::qPrintInfo::StuffString(v6, (const char *)text, v33);
            v42 = &v54;
            if ( v54 )
            {
              do
              {
                v43 = *v42;
                if ( v6->StdOut )
                {
                  if ( v6->mStdOutBuffer.NumChars == 255 )
                  {
                    v6->mStdOutBuffer.Buffer[255] = 0;
                    v6->mStdOutBuffer.NumChars = 0;
                  }
                  v6->mStdOutBuffer.Buffer[v6->mStdOutBuffer.NumChars++] = v43;
                }
                else
                {
                  v44 = v6->OutString;
                  if ( v44 )
                  {
                    v45 = v6->NumWritten;
                    if ( (signed int)v45 < v6->OutStringLen - 1 )
                    {
                      v44[v45] = v43;
                      v6->OutString[v6->NumWritten + 1] = 0;
                    }
                  }
                  ++v6->NumWritten;
                }
                ++v42;
              }
              while ( *v42 );
            }
            if ( v52 & 1 )
            {
              for ( i = v51 - v34 - 1; i >= 0; --i )
              {
                if ( v6->StdOut )
                {
                  if ( v6->mStdOutBuffer.NumChars == 255 )
                  {
                    v6->mStdOutBuffer.Buffer[255] = 0;
                    v6->mStdOutBuffer.NumChars = 0;
                  }
                  v6->mStdOutBuffer.Buffer[v6->mStdOutBuffer.NumChars++] = 32;
                }
                else
                {
                  v47 = v6->OutString;
                  if ( v47 )
                  {
                    v48 = v6->NumWritten;
                    if ( (signed int)v48 < v6->OutStringLen - 1 )
                    {
                      v47[v48] = 32;
                      v6->OutString[v6->NumWritten + 1] = 0;
                    }
                  }
                  ++v6->NumWritten;
                }
              }
            }
            goto LABEL_106;
          }
          UFG::qPrintInfo::StuffChar(v6, 37);
          UFG::qPrintInfo::StuffChar(v6, 32);
          v5 += 2;
        }
      }
      else if ( v6->StdOut )
      {
        if ( v6->mStdOutBuffer.NumChars == 255 )
        {
          v6->mStdOutBuffer.Buffer[255] = 0;
          v6->mStdOutBuffer.NumChars = 0;
        }
        v6->mStdOutBuffer.Buffer[v6->mStdOutBuffer.NumChars++] = v7;
        ++v5;
      }
      else
      {
        v8 = v6->OutString;
        if ( v8 )
        {
          v9 = v6->NumWritten;
          if ( (signed int)v9 < v6->OutStringLen - 1 )
          {
            v8[v9] = v7;
            v6->OutString[v6->NumWritten + 1] = 0;
          }
        }
        ++v6->NumWritten;
        ++v5;
      }
LABEL_106:
      v7 = *v5;
    }
    while ( *v5 );
  }
  return (unsigned int)v6->NumWritten;
}

// File Line: 3637
// RVA: 0x18C940
__int64 __fastcall UFG::qVSPrintf(char *dest, int max_len, const char *fmt, char *arg_list)
{
  UFG::qPrintInfo info; // [rsp+20h] [rbp-138h]

  info.mStdOutBuffer.NumChars = 0;
  info.OutString = dest;
  info.OutStringLen = max_len;
  info.PrintChannel = -1;
  info.StdOut = 0;
  return UFG::qPrintEngine(&info, fmt, arg_list);
}

// File Line: 3649
// RVA: 0x18AB50
__int64 UFG::qSPrintf(char *dest, const char *fmt, ...)
{
  UFG::qPrintInfo info; // [rsp+20h] [rbp-138h]
  va_list va; // [rsp+170h] [rbp+18h]

  va_start(va, fmt);
  info.mStdOutBuffer.NumChars = 0;
  info.OutString = dest;
  info.OutStringLen = 0x7FFFFFFF;
  info.PrintChannel = -1;
  info.StdOut = 0;
  return UFG::qPrintEngine(&info, fmt, va);
}

// File Line: 3657
// RVA: 0x18AB00
__int64 UFG::qSPrintf(char *dest, int max_len, const char *fmt, ...)
{
  UFG::qPrintInfo info; // [rsp+20h] [rbp-138h]
  va_list va; // [rsp+178h] [rbp+20h]

  va_start(va, fmt);
  info.mStdOutBuffer.NumChars = 0;
  info.OutString = dest;
  info.OutStringLen = max_len;
  info.PrintChannel = -1;
  info.StdOut = 0;
  return UFG::qPrintEngine(&info, fmt, va);
}

