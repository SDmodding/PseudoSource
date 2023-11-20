// File Line: 58
// RVA: 0xEE86B4
void __fastcall OSuite::ZDateTime::ZDateTime(OSuite::ZDateTime *this, __int64 nTime)
{
  int v2; // edi
  OSuite::ZDateTime *v3; // rbx
  __int64 v4; // rsi
  __int64 v5; // rax

  v2 = 1970;
  v3 = this;
  this->m_nMonth = 1;
  this->m_nDate = 1;
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable;
  this->m_nYear = 1970;
  v4 = nTime;
  v5 = 86400 * ((OSuite::ZDateTime::IsLeapYear(1970) != 0) + 365);
  if ( v5 <= v4 )
  {
    do
    {
      ++v2;
      v4 -= v5;
      v5 = 86400 * ((OSuite::ZDateTime::IsLeapYear(v2) != 0) + 365);
    }
    while ( v5 <= v4 );
    v3->m_nYear = v2;
  }
  v3->m_nSecond = v4;
  OSuite::ZDateTime::Carry(v3);
}

// File Line: 120
// RVA: 0xEE8750
void __fastcall OSuite::ZJsonSerializer::~ZJsonSerializer(OSuite::ZDateTime *this)
{
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable;
}

// File Line: 130
// RVA: 0xEE875C
OSuite::ZDateTime *__fastcall OSuite::ZDateTime::operator=(OSuite::ZDateTime *this, OSuite::ZDateTime *that)
{
  OSuite::ZDateTime *v2; // rdi
  OSuite::ZDateTime *v3; // rbx

  v2 = that;
  v3 = this;
  if ( this != that )
  {
    OSuite::ZRedBlackTreeBase::ZElementBase::ZElementBase(
      (OSuite::ZObject *)&this->vfptr,
      (OSuite::ZObject *)&that->vfptr);
    v3->m_nYear = v2->m_nYear;
    v3->m_nMonth = v2->m_nMonth;
    v3->m_nDate = v2->m_nDate;
    v3->m_nSecond = v2->m_nSecond;
  }
  return v3;
}

// File Line: 167
// RVA: 0xEE8D20
OSuite::ZDateTime *__fastcall OSuite::ZDateTime::Parse(OSuite::ZDateTime *result, OSuite::ZString *sDate)
{
  OSuite::ZDateTime *v2; // rbx
  OSuite::ZString *v3; // rdi
  OSuite::ZDateTime *v4; // rax
  OSuite::ZDateTime resulta; // [rsp+20h] [rbp-28h]

  v2 = result;
  v3 = sDate;
  result->vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable;
  if ( (unsigned __int8)OSuite::ZString::operator bool(sDate)
    && (OSuite::ZDateTime::ParseRFC3339(v2, v3)
     || OSuite::ZDateTime::ParseRFC1123(v2, v3)
     || OSuite::ZDateTime::ParseRFC850(v2, v3)
     || OSuite::ZDateTime::ParseAsctime(v2, v3)) )
  {
    OSuite::ZDateTime::Carry(v2);
  }
  else
  {
    v4 = OSuite::ZDateTime::CurrentDateTime(&resulta);
    OSuite::ZDateTime::operator=(v2, v4);
  }
  return v2;
}

// File Line: 192
// RVA: 0xEE9A60
__int64 __fastcall OSuite::ZDateTime::ToTime(OSuite::ZDateTime *this)
{
  int v1; // ebx
  __int64 v2; // rsi
  OSuite::ZDateTime *i; // rdi
  bool v4; // al
  int j; // ebx
  int v6; // eax

  v1 = 1970;
  v2 = 0i64;
  for ( i = this; v1 < i->m_nYear; v2 += (v4 != 0) + 365i64 )
    v4 = OSuite::ZDateTime::IsLeapYear(v1++);
  for ( j = 1; j < i->m_nMonth; v2 += v6 )
    v6 = OSuite::ZDateTime::DaysInMonth(i->m_nYear, j++);
  return i->m_nSecond + 86400 * (v2 + i->m_nDate - 1);
}

// File Line: 393
// RVA: 0xEE89E8
OSuite::ZString *__fastcall OSuite::ZDateTime::ISO8601Date(OSuite::ZDateTime *this, OSuite::ZString *result)
{
  OSuite::ZDateTime *v2; // rbx
  OSuite::ZString *v3; // rdi
  int v4; // er9
  __int64 v6; // [rsp+20h] [rbp-68h]
  __int64 v7; // [rsp+28h] [rbp-60h]
  __int64 v8; // [rsp+30h] [rbp-58h]
  __int64 v9; // [rsp+38h] [rbp-50h]
  OSuite::ZStringBuilder v10; // [rsp+40h] [rbp-48h]

  v10.m_Chars.m_pList = 0i64;
  v2 = this;
  v3 = result;
  OSuite::ZStringBuilder::ZStringBuilder(&v10, 0x28ui64);
  v4 = v2->m_nSecond;
  LODWORD(v9) = v4 % 60;
  LODWORD(v8) = v4 / 60 % 60;
  LODWORD(v7) = v4 / 3600;
  LODWORD(v6) = v2->m_nDate;
  OSuite::ZStringBuilder::AppendFormat(
    &v10,
    "%04d-%02d-%02dT%02d:%02d:%02d",
    (unsigned int)v2->m_nYear,
    (unsigned int)v2->m_nMonth,
    v6,
    v7,
    v8,
    v9);
  OSuite::ZStringBuilder::ToString(&v10, v3);
  OSuite::ZUtf8Buffer::~ZUtf8Buffer(&v10);
  return v3;
}

// File Line: 401
// RVA: 0xEE8AE0
OSuite::ZString *__fastcall OSuite::ZDateTime::ISO8601Time(OSuite::ZDateTime *this, OSuite::ZString *result)
{
  OSuite::ZDateTime *v2; // rbx
  OSuite::ZString *v3; // rdi
  int v4; // ecx
  unsigned int v5; // edx
  _QWORD v7[2]; // [rsp+20h] [rbp-58h]
  OSuite::ZStringBuilder v8; // [rsp+30h] [rbp-48h]

  v8.m_Chars.m_pList = 0i64;
  v2 = this;
  v3 = result;
  OSuite::ZStringBuilder::ZStringBuilder(&v8, 0x28ui64);
  v4 = v2->m_nSecond;
  LODWORD(v7[0]) = v4 % 60;
  v5 = (signed int)(v4 + ((unsigned __int64)(-1851608123i64 * v4) >> 32)) >> 11;
  OSuite::ZStringBuilder::AppendFormat(&v8, "%02d:%02d:%02d", (v5 >> 31) + v5, (unsigned int)(v4 / 60 % 60), v7[0]);
  OSuite::ZStringBuilder::ToString(&v8, v3);
  OSuite::ZUtf8Buffer::~ZUtf8Buffer(&v8);
  return v3;
}

// File Line: 413
// RVA: 0xEE8938
OSuite::ZDateTime *__fastcall OSuite::ZDateTime::CurrentDateTime(OSuite::ZDateTime *result)
{
  OSuite::ZDateTime *v1; // rbx
  __int64 v2; // rax

  v1 = result;
  v2 = time64(0i64);
  OSuite::ZDateTime::ZDateTime(v1, v2 + OSuite::ZDateTime::s_nClockSkew);
  return v1;
}

// File Line: 423
// RVA: 0xEE8920
__int64 __fastcall OSuite::ZDateTime::Current()
{
  return OSuite::ZDateTime::s_nClockSkew + time64(0i64);
}

// File Line: 435
// RVA: 0xEE8964
__int64 __fastcall OSuite::ZDateTime::DaysInMonth(int nYear, int nMonth)
{
  __int64 result; // rax

  if ( nMonth == 2 )
    result = (unsigned int)(OSuite::ZDateTime::IsLeapYear(nYear) != 0) + 28;
  else
    result = (unsigned int)days[nMonth - 1];
  return result;
}

// File Line: 455
// RVA: 0xEE8C1C
bool __fastcall OSuite::ZDateTime::IsLeapYear(int nYear)
{
  if ( nYear % 4 )
    return 0;
  if ( nYear % 100 )
    return 1;
  return nYear == 400 * (nYear / 400);
}

// File Line: 496
// RVA: 0xEE879C
void __fastcall OSuite::ZDateTime::Carry(OSuite::ZDateTime *this)
{
  OSuite::ZDateTime *v1; // rbx
  int v2; // ecx
  int v3; // eax
  signed int v4; // ecx
  signed int v5; // edi
  int v6; // esi
  int v7; // ebp
  int v8; // eax
  signed int v9; // esi
  int v10; // edi
  int v11; // ebp

  v1 = this;
  v2 = this->m_nMonth;
  if ( v2 <= 12 )
  {
    if ( v2 >= 1 )
      goto LABEL_6;
    v1->m_nYear += ((signed int)((unsigned __int64)(715827883i64 * v2) >> 32) >> 1)
                 - 1
                 + ((unsigned int)((unsigned __int64)(715827883i64 * v2) >> 32) >> 31);
    v3 = 12 - -v2 % 12;
  }
  else
  {
    v1->m_nYear += (v2 - 1) / 12;
    v3 = (v2 - 1) % 12 + 1;
  }
  v1->m_nMonth = v3;
LABEL_6:
  v4 = v1->m_nSecond;
  if ( v4 < 86400 )
  {
    if ( v4 < 0 )
    {
      v1->m_nDate += ((signed int)(v4 + ((unsigned __int64)(-1037155065i64 * v4) >> 32)) >> 16)
                   - 1
                   + ((unsigned int)(v4 + ((unsigned __int64)(-1037155065i64 * v4) >> 32)) >> 31);
      v1->m_nSecond = 86400 - -v4 % 86400;
    }
  }
  else
  {
    v1->m_nDate += v4 / 86400;
    v1->m_nSecond = v4 % 86400;
  }
  v5 = v1->m_nMonth;
  v6 = v1->m_nYear;
  v7 = v1->m_nDate;
  while ( v7 > OSuite::ZDateTime::DaysInMonth(v6, v5) )
  {
    v8 = OSuite::ZDateTime::DaysInMonth(v6, v5++);
    v7 -= v8;
    v1->m_nMonth = v5;
    v1->m_nDate = v7;
    if ( v5 > 12 )
    {
      ++v6;
      v5 = 1;
      v1->m_nYear = v6;
      v1->m_nMonth = 1;
    }
  }
  v9 = v1->m_nDate;
  if ( v9 < 1 )
  {
    v10 = v1->m_nMonth;
    v11 = v1->m_nYear;
    do
    {
      v1->m_nMonth = --v10;
      if ( v10 < 1 )
      {
        --v11;
        v10 = 12;
        v1->m_nYear = v11;
        v1->m_nMonth = 12;
      }
      v9 += OSuite::ZDateTime::DaysInMonth(v11, v10);
      v1->m_nDate = v9;
    }
    while ( v9 < 1 );
  }
}

// File Line: 546
// RVA: 0xEE93D8
char __fastcall OSuite::ZDateTime::ParseRFC3339(OSuite::ZDateTime *this, OSuite::ZString *sDate)
{
  OSuite::ZString *v2; // rbx
  OSuite::ZDateTime *v3; // r13
  char v4; // al
  OSuite::ZString *v5; // rax
  OSuite::ZString *v6; // rax
  OSuite::ZString *v7; // rax
  OSuite::ZString *v8; // rax
  int v9; // esi
  OSuite::ZString *v10; // rax
  int v11; // er15
  OSuite::ZString *v12; // rax
  signed int i; // er14
  unsigned __int8 v14; // al
  char v15; // al
  int v16; // er14
  char v17; // r12
  OSuite::ZString *v18; // rax
  int v19; // edi
  unsigned __int64 v20; // r14
  OSuite::ZString *v21; // rax
  int v22; // ebx
  int v23; // edi
  int v24; // [rsp+20h] [rbp-30h]
  int v25; // [rsp+28h] [rbp-28h]
  OSuite::ZString result; // [rsp+30h] [rbp-20h]
  __int64 v27; // [rsp+A0h] [rbp+50h]
  __int64 v28; // [rsp+A8h] [rbp+58h]

  v2 = sDate;
  v3 = this;
  if ( !OSuite::ZDateTime::IsDigits(sDate, 0i64, 4) )
    return 0;
  v5 = OSuite::ZString::Slice(v2, &result, 0i64, 4ui64);
  v27 = OSuite::ZString::ToInt(v5);
  OSuite::ZString::~ZString(&result);
  if ( OSuite::ZString::CharAt(v2, 4ui64) != 45 )
    return 0;
  if ( !OSuite::ZDateTime::IsDigits(v2, 5ui64, 2) )
    return 0;
  v6 = OSuite::ZString::Slice(v2, &result, 5ui64, 2ui64);
  v28 = OSuite::ZString::ToInt(v6);
  OSuite::ZString::~ZString(&result);
  if ( OSuite::ZString::CharAt(v2, 7ui64) != 45 )
    return 0;
  if ( !OSuite::ZDateTime::IsDigits(v2, 8ui64, 2) )
    return 0;
  v7 = OSuite::ZString::Slice(v2, &result, 8ui64, 2ui64);
  v24 = OSuite::ZString::ToInt(v7);
  OSuite::ZString::~ZString(&result);
  if ( OSuite::ZString::CharAt(v2, 0xAui64) != 84 && OSuite::ZString::CharAt(v2, 0xAui64) != 116 )
    return 0;
  if ( !OSuite::ZDateTime::IsDigits(v2, 0xBui64, 2) )
    return 0;
  v8 = OSuite::ZString::Slice(v2, &result, 0xBui64, 2ui64);
  v9 = OSuite::ZString::ToInt(v8);
  OSuite::ZString::~ZString(&result);
  if ( OSuite::ZString::CharAt(v2, 0xDui64) != 58 )
    return 0;
  if ( !OSuite::ZDateTime::IsDigits(v2, 0xEui64, 2) )
    return 0;
  v10 = OSuite::ZString::Slice(v2, &result, 0xEui64, 2ui64);
  v11 = OSuite::ZString::ToInt(v10);
  OSuite::ZString::~ZString(&result);
  if ( OSuite::ZString::CharAt(v2, 0x10ui64) != 58 || !OSuite::ZDateTime::IsDigits(v2, 0x11ui64, 2) )
    return 0;
  v12 = OSuite::ZString::Slice(v2, &result, 0x11ui64, 2ui64);
  v25 = OSuite::ZString::ToInt(v12);
  OSuite::ZString::~ZString(&result);
  i = 19;
  if ( OSuite::ZString::CharAt(v2, 0x13ui64) == 46 )
  {
    for ( i = 20; i < (signed int)OSuite::ZString::Count(v2); ++i )
    {
      v14 = OSuite::ZString::CharAt(v2, i);
      if ( !isdigit(v14) )
        break;
    }
  }
  if ( OSuite::ZString::CharAt(v2, i) == 43 || OSuite::ZString::CharAt(v2, i) == 45 )
  {
    v15 = OSuite::ZString::CharAt(v2, i);
    v16 = i + 1;
    v17 = v15;
    if ( OSuite::ZDateTime::IsDigits(v2, v16, 2) )
    {
      v18 = OSuite::ZString::Slice(v2, &result, v16, 2ui64);
      v19 = OSuite::ZString::ToInt(v18);
      OSuite::ZString::~ZString(&result);
      v20 = v16 + 2;
      if ( OSuite::ZDateTime::IsDigits(v2, v20, 2) )
      {
        v21 = OSuite::ZString::Slice(v2, &result, v20, 2ui64);
        v22 = OSuite::ZString::ToInt(v21);
        OSuite::ZString::~ZString(&result);
        v23 = 60 * v19;
        if ( v17 == 45 )
          v11 += v22 + v23;
        else
          v11 += -v22 - v23;
        goto LABEL_27;
      }
    }
    return 0;
  }
  if ( OSuite::ZString::CharAt(v2, i) != 90 )
    OSuite::ZString::CharAt(v2, i);
LABEL_27:
  v3->m_nYear = v27;
  v3->m_nMonth = v28;
  v3->m_nDate = v24;
  v4 = 1;
  v3->m_nSecond = v25 + 60 * (v11 + 60 * v9);
  return v4;
}

// File Line: 660
// RVA: 0xEE90AC
char __fastcall OSuite::ZDateTime::ParseRFC1123(OSuite::ZDateTime *this, OSuite::ZString *sDate)
{
  OSuite::ZString *v2; // rdi
  OSuite::ZDateTime *v3; // r14
  char v4; // bl
  OSuite::ZString *v5; // rax
  OSuite::ZString *v6; // rax
  bool v7; // si
  signed int v8; // ebx
  OSuite::ZString *v10; // rax
  int v11; // ebx
  unsigned __int8 v12; // al
  int v13; // ebx
  OSuite::ZString *v14; // rax
  int v15; // er12
  int v16; // ebx
  unsigned __int8 v17; // al
  int v18; // ebx
  OSuite::ZString *v19; // rax
  int v20; // ebx
  unsigned __int8 v21; // al
  int v22; // ebx
  OSuite::ZString *v23; // rax
  int v24; // esi
  int v25; // ebx
  char v26; // al
  int v27; // ebx
  OSuite::ZString *v28; // rax
  int v29; // er13
  int v30; // ebx
  char v31; // al
  int v32; // ebx
  OSuite::ZString *v33; // rax
  int v34; // er15
  OSuite::ZString *v35; // rax
  bool v36; // bl
  OSuite::ZString v37; // [rsp+20h] [rbp-30h]
  OSuite::ZString result; // [rsp+38h] [rbp-18h]
  __int64 v39; // [rsp+A0h] [rbp+50h]
  __int64 v40; // [rsp+A8h] [rbp+58h]

  v2 = sDate;
  v3 = this;
  v4 = 1;
  v5 = OSuite::ZString::Slice(sDate, &result, 0i64, 3ui64);
  v7 = 0;
  if ( OSuite::ZDateTime::IsShortDay(v5) )
  {
    v4 = 3;
    v6 = OSuite::ZString::Slice(v2, &v37, 3ui64, 2ui64);
    if ( OSuite::ZString::operator==(v6, ", ") )
      v7 = 1;
  }
  if ( v4 & 2 )
  {
    v4 &= 0xFDu;
    OSuite::ZString::~ZString(&v37);
  }
  if ( v4 & 1 )
    OSuite::ZString::~ZString(&result);
  v8 = 0;
  if ( v7 )
    v8 = 5;
  if ( !OSuite::ZDateTime::IsDigits(v2, v8, 2) )
    return 0;
  v10 = OSuite::ZString::Slice(v2, &result, v8, 2ui64);
  v40 = OSuite::ZString::ToInt(v10);
  OSuite::ZString::~ZString(&result);
  v11 = v8 + 2;
  v12 = OSuite::ZString::CharAt(v2, v11);
  v13 = v11 + 1;
  if ( !isspace(v12) )
    return 0;
  v14 = OSuite::ZString::Slice(v2, &result, v13, 3ui64);
  v15 = OSuite::ZDateTime::GetMonth(v14);
  OSuite::ZString::~ZString(&result);
  if ( !v15 )
    return 0;
  v16 = v13 + 3;
  v17 = OSuite::ZString::CharAt(v2, v16);
  v18 = v16 + 1;
  if ( !isspace(v17) )
    return 0;
  if ( !OSuite::ZDateTime::IsDigits(v2, v18, 4) )
    return 0;
  v19 = OSuite::ZString::Slice(v2, &result, v18, 4ui64);
  v39 = OSuite::ZString::ToInt(v19);
  OSuite::ZString::~ZString(&result);
  v20 = v18 + 4;
  v21 = OSuite::ZString::CharAt(v2, v20);
  v22 = v20 + 1;
  if ( !isspace(v21) )
    return 0;
  if ( !OSuite::ZDateTime::IsDigits(v2, v22, 2) )
    return 0;
  v23 = OSuite::ZString::Slice(v2, &result, v22, 2ui64);
  v24 = OSuite::ZString::ToInt(v23);
  OSuite::ZString::~ZString(&result);
  v25 = v22 + 2;
  v26 = OSuite::ZString::CharAt(v2, v25);
  v27 = v25 + 1;
  if ( v26 != 58 )
    return 0;
  if ( !OSuite::ZDateTime::IsDigits(v2, v27, 2) )
    return 0;
  v28 = OSuite::ZString::Slice(v2, &result, v27, 2ui64);
  v29 = OSuite::ZString::ToInt(v28);
  OSuite::ZString::~ZString(&result);
  v30 = v27 + 2;
  v31 = OSuite::ZString::CharAt(v2, v30);
  v32 = v30 + 1;
  if ( v31 != 58 )
    return 0;
  if ( !OSuite::ZDateTime::IsDigits(v2, v32, 2) )
    return 0;
  v33 = OSuite::ZString::Slice(v2, &result, v32, 2ui64);
  v34 = OSuite::ZString::ToInt(v33);
  OSuite::ZString::~ZString(&result);
  v35 = OSuite::ZString::Slice(v2, &result, v32 + 2, 4ui64);
  v36 = OSuite::ZString::operator==(v35, " GMT") == 0;
  OSuite::ZString::~ZString(&result);
  if ( v36 )
    return 0;
  v3->m_nMonth = v15;
  v3->m_nYear = v39;
  v3->m_nDate = v40;
  v3->m_nSecond = v34 + 60 * (v29 + 60 * v24);
  return 1;
}

// File Line: 732
// RVA: 0xEE977C
char __fastcall OSuite::ZDateTime::ParseRFC850(OSuite::ZDateTime *this, OSuite::ZString *sDate)
{
  OSuite::ZDateTime *v2; // r14
  OSuite::ZString *v3; // rdi
  int v4; // eax
  char v5; // al
  int v6; // ebx
  unsigned __int8 v7; // al
  int v8; // ebx
  OSuite::ZString *v9; // rax
  int v10; // ebx
  char v11; // al
  int v12; // ebx
  OSuite::ZString *v13; // rax
  int v14; // er13
  int v15; // ebx
  char v16; // al
  int v17; // ebx
  OSuite::ZString *v18; // rax
  signed int v19; // er12
  int v20; // ebx
  unsigned __int8 v21; // al
  int v22; // ebx
  OSuite::ZString *v23; // rax
  int v24; // esi
  int v25; // ebx
  char v26; // al
  int v27; // ebx
  OSuite::ZString *v28; // rax
  int v29; // ebx
  char v30; // al
  int v31; // ebx
  OSuite::ZString *v32; // rax
  int v33; // er15
  OSuite::ZString *v34; // rax
  bool v35; // bl
  signed int v36; // ecx
  OSuite::ZString result; // [rsp+20h] [rbp-20h]
  __int64 v38; // [rsp+90h] [rbp+50h]
  __int64 v39; // [rsp+98h] [rbp+58h]

  v2 = this;
  v3 = sDate;
  v4 = OSuite::ZDateTime::IsLongDay(sDate);
  if ( !v4 )
    return 0;
  v6 = v4 + 1;
  if ( OSuite::ZString::CharAt(v3, v4) != 44 )
    return 0;
  v7 = OSuite::ZString::CharAt(v3, v6);
  v8 = v6 + 1;
  if ( !isspace(v7) )
    return 0;
  if ( !OSuite::ZDateTime::IsDigits(v3, v8, 2) )
    return 0;
  v9 = OSuite::ZString::Slice(v3, &result, v8, 2ui64);
  v38 = OSuite::ZString::ToInt(v9);
  OSuite::ZString::~ZString(&result);
  v10 = v8 + 2;
  v11 = OSuite::ZString::CharAt(v3, v10);
  v12 = v10 + 1;
  if ( v11 != 45 )
    return 0;
  v13 = OSuite::ZString::Slice(v3, &result, v12, 3ui64);
  v14 = OSuite::ZDateTime::GetMonth(v13);
  OSuite::ZString::~ZString(&result);
  if ( !v14 )
    return 0;
  v15 = v12 + 3;
  v16 = OSuite::ZString::CharAt(v3, v15);
  v17 = v15 + 1;
  if ( v16 != 45 )
    return 0;
  if ( !OSuite::ZDateTime::IsDigits(v3, v17, 2) )
    return 0;
  v18 = OSuite::ZString::Slice(v3, &result, v17, 2ui64);
  v19 = OSuite::ZString::ToInt(v18);
  OSuite::ZString::~ZString(&result);
  v20 = v17 + 2;
  v21 = OSuite::ZString::CharAt(v3, v20);
  v22 = v20 + 1;
  if ( !isspace(v21) )
    return 0;
  if ( !OSuite::ZDateTime::IsDigits(v3, v22, 2) )
    return 0;
  v23 = OSuite::ZString::Slice(v3, &result, v22, 2ui64);
  v24 = OSuite::ZString::ToInt(v23);
  OSuite::ZString::~ZString(&result);
  v25 = v22 + 2;
  v26 = OSuite::ZString::CharAt(v3, v25);
  v27 = v25 + 1;
  if ( v26 != 58 )
    return 0;
  if ( !OSuite::ZDateTime::IsDigits(v3, v27, 2) )
    return 0;
  v28 = OSuite::ZString::Slice(v3, &result, v27, 2ui64);
  v39 = OSuite::ZString::ToInt(v28);
  OSuite::ZString::~ZString(&result);
  v29 = v27 + 2;
  v30 = OSuite::ZString::CharAt(v3, v29);
  v31 = v29 + 1;
  if ( v30 != 58 )
    return 0;
  if ( !OSuite::ZDateTime::IsDigits(v3, v31, 2) )
    return 0;
  v32 = OSuite::ZString::Slice(v3, &result, v31, 2ui64);
  v33 = OSuite::ZString::ToInt(v32);
  OSuite::ZString::~ZString(&result);
  v34 = OSuite::ZString::Slice(v3, &result, v31 + 2, 4ui64);
  v35 = OSuite::ZString::operator==(v34, " GMT") == 0;
  OSuite::ZString::~ZString(&result);
  if ( v35 )
    return 0;
  v36 = 1900;
  v2->m_nMonth = v14;
  if ( v19 < 50 )
    v36 = 2000;
  v2->m_nDate = v38;
  v5 = 1;
  v2->m_nYear = v19 + v36;
  v2->m_nSecond = v33 + 60 * (v39 + 60 * v24);
  return v5;
}

// File Line: 808
// RVA: 0xEE8DB0
char __fastcall OSuite::ZDateTime::ParseAsctime(OSuite::ZDateTime *this, OSuite::ZString *sDate)
{
  OSuite::ZString *v2; // rbx
  OSuite::ZDateTime *v3; // r14
  OSuite::ZString *v4; // rax
  bool v5; // di
  OSuite::ZString *v6; // rax
  int v7; // er15
  unsigned __int8 v8; // al
  unsigned __int8 v9; // al
  OSuite::ZString *v10; // rax
  int v11; // esi
  OSuite::ZString *v12; // rax
  unsigned __int8 v13; // al
  OSuite::ZString *v14; // rax
  int v15; // edi
  OSuite::ZString *v16; // rax
  int v17; // er13
  OSuite::ZString *v18; // rax
  int v19; // er12
  unsigned __int8 v20; // al
  OSuite::ZString *v21; // rax
  int v22; // ebx
  char v23; // al
  OSuite::ZString result; // [rsp+20h] [rbp-20h]

  v2 = sDate;
  v3 = this;
  v4 = OSuite::ZString::Slice(sDate, &result, 0i64, 3ui64);
  v5 = OSuite::ZDateTime::IsShortDay(v4) && OSuite::ZString::CharAt(v2, 3ui64) == 32;
  OSuite::ZString::~ZString(&result);
  if ( !v5 )
    return 0;
  v6 = OSuite::ZString::Slice(v2, &result, 4ui64, 3ui64);
  v7 = OSuite::ZDateTime::GetMonth(v6);
  OSuite::ZString::~ZString(&result);
  if ( !v7 )
    return 0;
  v8 = OSuite::ZString::CharAt(v2, 7ui64);
  if ( !isspace(v8) )
    return 0;
  v9 = OSuite::ZString::CharAt(v2, 8ui64);
  if ( isspace(v9) )
  {
    if ( !OSuite::ZDateTime::IsDigits(v2, 9ui64, 1) )
      return 0;
    v10 = OSuite::ZString::Slice(v2, &result, 9ui64, 1ui64);
    v11 = OSuite::ZString::ToInt(v10);
  }
  else
  {
    if ( !OSuite::ZDateTime::IsDigits(v2, 8ui64, 2) )
      return 0;
    v12 = OSuite::ZString::Slice(v2, &result, 8ui64, 2ui64);
    v11 = OSuite::ZString::ToInt(v12);
  }
  OSuite::ZString::~ZString(&result);
  v13 = OSuite::ZString::CharAt(v2, 0xAui64);
  if ( isspace(v13) )
  {
    if ( OSuite::ZDateTime::IsDigits(v2, 0xBui64, 2) )
    {
      v14 = OSuite::ZString::Slice(v2, &result, 0xBui64, 2ui64);
      v15 = OSuite::ZString::ToInt(v14);
      OSuite::ZString::~ZString(&result);
      if ( OSuite::ZString::CharAt(v2, 0xDui64) == 58 )
      {
        if ( OSuite::ZDateTime::IsDigits(v2, 0xEui64, 2) )
        {
          v16 = OSuite::ZString::Slice(v2, &result, 0xEui64, 2ui64);
          v17 = OSuite::ZString::ToInt(v16);
          OSuite::ZString::~ZString(&result);
          if ( OSuite::ZString::CharAt(v2, 0x10ui64) == 58 )
          {
            if ( OSuite::ZDateTime::IsDigits(v2, 0x11ui64, 2) )
            {
              v18 = OSuite::ZString::Slice(v2, &result, 0x11ui64, 2ui64);
              v19 = OSuite::ZString::ToInt(v18);
              OSuite::ZString::~ZString(&result);
              v20 = OSuite::ZString::CharAt(v2, 0x13ui64);
              if ( isspace(v20) )
              {
                if ( OSuite::ZDateTime::IsDigits(v2, 0x14ui64, 4) )
                {
                  v21 = OSuite::ZString::Slice(v2, &result, 0x14ui64, 4ui64);
                  v22 = OSuite::ZString::ToInt(v21);
                  OSuite::ZString::~ZString(&result);
                  v3->m_nYear = v22;
                  v3->m_nMonth = v7;
                  v3->m_nDate = v11;
                  v23 = 1;
                  v3->m_nSecond = v19 + 60 * (v17 + 60 * v15);
                  return v23;
                }
              }
            }
          }
        }
      }
    }
  }
  return 0;
}

// File Line: 893
// RVA: 0xEE8CDC
char __fastcall OSuite::ZDateTime::IsShortDay(OSuite::ZString *sString)
{
  OSuite::ZString *v1; // rdi
  const char **v2; // rbx

  v1 = sString;
  v2 = OSuite::ZDateTime::s_pszShortDays;
  while ( !OSuite::ZString::StartsWith(v1, *v2) )
  {
    ++v2;
    if ( (signed __int64)v2 >= (signed __int64)OSuite::ZDateTime::s_pszLongDays )
      return 0;
  }
  return 1;
}

// File Line: 907
// RVA: 0xEE8C70
size_t __fastcall OSuite::ZDateTime::IsLongDay(OSuite::ZString *sString)
{
  OSuite::ZString *v1; // rsi
  int v2; // edi
  const char **v3; // rbx

  v1 = sString;
  v2 = 0;
  v3 = OSuite::ZDateTime::s_pszLongDays;
  while ( !OSuite::ZString::StartsWith(v1, *v3) )
  {
    ++v3;
    ++v2;
    if ( (signed __int64)v3 >= (signed __int64)days )
      return 0i64;
  }
  return strlen(OSuite::ZDateTime::s_pszLongDays[v2]);
}

// File Line: 921
// RVA: 0xEE8994
__int64 __fastcall OSuite::ZDateTime::GetMonth(OSuite::ZString *sString)
{
  OSuite::ZString *v1; // rsi
  int v2; // edi
  const char **v3; // rbx

  v1 = sString;
  v2 = 0;
  v3 = OSuite::ZDateTime::s_pszMonths;
  while ( !OSuite::ZString::operator==(v1, *v3) )
  {
    ++v3;
    ++v2;
    if ( (signed __int64)v3 >= (signed __int64)OSuite::ZDateTime::s_pszShortDays )
      return 0i64;
  }
  return (unsigned int)(v2 + 1);
}

// File Line: 935
// RVA: 0xEE8BBC
char __fastcall OSuite::ZDateTime::IsDigits(OSuite::ZString *sString, unsigned __int64 nIndex, int nCount)
{
  int v3; // ebx
  int v4; // edi
  unsigned __int64 v5; // rsi
  OSuite::ZString *v6; // rbp
  unsigned __int8 v7; // al

  v3 = 0;
  v4 = nCount;
  v5 = nIndex;
  v6 = sString;
  if ( nCount <= 0 )
    return 1;
  while ( 1 )
  {
    v7 = OSuite::ZString::CharAt(v6, v5 + v3);
    if ( !isdigit(v7) )
      break;
    if ( ++v3 >= v4 )
      return 1;
  }
  return 0;
}

