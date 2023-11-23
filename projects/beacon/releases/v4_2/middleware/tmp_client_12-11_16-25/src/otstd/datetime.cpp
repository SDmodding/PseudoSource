// File Line: 58
// RVA: 0xEE86B4
void __fastcall OSuite::ZDateTime::ZDateTime(OSuite::ZDateTime *this, __int64 nTime)
{
  int v2; // edi
  __int64 v5; // rax

  v2 = 1970;
  this->m_nMonth = 1;
  this->m_nDate = 1;
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable;
  this->m_nYear = 1970;
  v5 = 86400 * (OSuite::ZDateTime::IsLeapYear(1970) + 365);
  if ( v5 <= nTime )
  {
    do
    {
      ++v2;
      nTime -= v5;
      v5 = 86400 * (OSuite::ZDateTime::IsLeapYear(v2) + 365);
    }
    while ( v5 <= nTime );
    this->m_nYear = v2;
  }
  this->m_nSecond = nTime;
  OSuite::ZDateTime::Carry(this);
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
  if ( this != that )
  {
    OSuite::ZRedBlackTreeBase::ZElementBase::ZElementBase(this, that);
    this->m_nYear = that->m_nYear;
    this->m_nMonth = that->m_nMonth;
    this->m_nDate = that->m_nDate;
    this->m_nSecond = that->m_nSecond;
  }
  return this;
}

// File Line: 167
// RVA: 0xEE8D20
OSuite::ZDateTime *__fastcall OSuite::ZDateTime::Parse(OSuite::ZDateTime *result, OSuite::ZString *sDate)
{
  OSuite::ZDateTime *v4; // rax
  OSuite::ZDateTime resulta; // [rsp+20h] [rbp-28h] BYREF

  result->vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable;
  if ( (unsigned __int8)OSuite::ZString::operator bool(sDate)
    && (OSuite::ZDateTime::ParseRFC3339(result, sDate)
     || OSuite::ZDateTime::ParseRFC1123(result, sDate)
     || OSuite::ZDateTime::ParseRFC850(result, sDate)
     || OSuite::ZDateTime::ParseAsctime(result, sDate)) )
  {
    OSuite::ZDateTime::Carry(result);
  }
  else
  {
    v4 = OSuite::ZDateTime::CurrentDateTime(&resulta);
    OSuite::ZDateTime::operator=(result, v4);
  }
  return result;
}

// File Line: 192
// RVA: 0xEE9A60
__int64 __fastcall OSuite::ZDateTime::ToTime(OSuite::ZDateTime *this)
{
  int v1; // ebx
  __int64 i; // rsi
  bool IsLeapYear; // al
  int j; // ebx
  int v6; // eax

  v1 = 1970;
  for ( i = 0i64; v1 < this->m_nYear; i += IsLeapYear + 365i64 )
    IsLeapYear = OSuite::ZDateTime::IsLeapYear(v1++);
  for ( j = 1; j < this->m_nMonth; i += v6 )
    v6 = OSuite::ZDateTime::DaysInMonth(this->m_nYear, j++);
  return this->m_nSecond + 86400 * (i + this->m_nDate - 1);
}

// File Line: 393
// RVA: 0xEE89E8
OSuite::ZString *__fastcall OSuite::ZDateTime::ISO8601Date(OSuite::ZDateTime *this, OSuite::ZString *result)
{
  int m_nSecond; // r9d
  int m_nDate; // [rsp+20h] [rbp-68h]
  int v7; // [rsp+28h] [rbp-60h]
  int v8; // [rsp+30h] [rbp-58h]
  int v9; // [rsp+38h] [rbp-50h]
  OSuite::ZStringBuilder v10; // [rsp+40h] [rbp-48h] BYREF

  v10.m_Chars.m_pList = 0i64;
  OSuite::ZStringBuilder::ZStringBuilder(&v10, (OSuite::ZObject *)0x28);
  m_nSecond = this->m_nSecond;
  v9 = m_nSecond % 60;
  v8 = m_nSecond / 60 % 60;
  v7 = m_nSecond / 3600;
  m_nDate = this->m_nDate;
  OSuite::ZStringBuilder::AppendFormat(
    &v10,
    "%04d-%02d-%02dT%02d:%02d:%02d",
    (unsigned int)this->m_nYear,
    (unsigned int)this->m_nMonth,
    m_nDate,
    v7,
    v8,
    v9);
  OSuite::ZStringBuilder::ToString(&v10, result);
  OSuite::ZUtf8Buffer::~ZUtf8Buffer(&v10);
  return result;
}

// File Line: 401
// RVA: 0xEE8AE0
OSuite::ZString *__fastcall OSuite::ZDateTime::ISO8601Time(OSuite::ZDateTime *this, OSuite::ZString *result)
{
  int m_nSecond; // ecx
  OSuite::ZStringBuilder v6; // [rsp+30h] [rbp-48h] BYREF

  v6.m_Chars.m_pList = 0i64;
  OSuite::ZStringBuilder::ZStringBuilder(&v6, (OSuite::ZObject *)0x28);
  m_nSecond = this->m_nSecond;
  OSuite::ZStringBuilder::AppendFormat(
    &v6,
    "%02d:%02d:%02d",
    (unsigned int)(m_nSecond / 3600),
    (unsigned int)(m_nSecond / 60 % 60),
    m_nSecond % 60);
  OSuite::ZStringBuilder::ToString(&v6, result);
  OSuite::ZUtf8Buffer::~ZUtf8Buffer(&v6);
  return result;
}

// File Line: 413
// RVA: 0xEE8938
OSuite::ZDateTime *__fastcall OSuite::ZDateTime::CurrentDateTime(OSuite::ZDateTime *result)
{
  __int64 v2; // rax

  v2 = time64(0i64);
  OSuite::ZDateTime::ZDateTime(result, v2 + OSuite::ZDateTime::s_nClockSkew);
  return result;
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
  if ( nMonth == 2 )
    return (unsigned int)OSuite::ZDateTime::IsLeapYear(nYear) + 28;
  else
    return (unsigned int)days[nMonth - 1];
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
  int m_nMonth; // ecx
  int v3; // eax
  int m_nSecond; // ecx
  int v5; // edi
  int m_nYear; // esi
  int m_nDate; // ebp
  int v8; // eax
  int v9; // esi
  int v10; // edi
  int v11; // ebp

  m_nMonth = this->m_nMonth;
  if ( m_nMonth <= 12 )
  {
    if ( m_nMonth >= 1 )
      goto LABEL_6;
    this->m_nYear += ((int)((unsigned __int64)(715827883i64 * m_nMonth) >> 32) >> 1)
                   - 1
                   + ((unsigned int)((unsigned __int64)(715827883i64 * m_nMonth) >> 32) >> 31);
    v3 = 12 - -m_nMonth % 12;
  }
  else
  {
    this->m_nYear += (m_nMonth - 1) / 12;
    v3 = (m_nMonth - 1) % 12 + 1;
  }
  this->m_nMonth = v3;
LABEL_6:
  m_nSecond = this->m_nSecond;
  if ( m_nSecond < 86400 )
  {
    if ( m_nSecond < 0 )
    {
      this->m_nDate += ((int)((unsigned __int64)(3257812231i64 * m_nSecond) >> 32) >> 16)
                     - 1
                     + ((unsigned int)((unsigned __int64)(3257812231i64 * m_nSecond) >> 32) >> 31);
      this->m_nSecond = 86400 - -m_nSecond % 86400;
    }
  }
  else
  {
    this->m_nDate += m_nSecond / 86400;
    this->m_nSecond = m_nSecond % 86400;
  }
  v5 = this->m_nMonth;
  m_nYear = this->m_nYear;
  m_nDate = this->m_nDate;
  while ( m_nDate > OSuite::ZDateTime::DaysInMonth(m_nYear, v5) )
  {
    v8 = OSuite::ZDateTime::DaysInMonth(m_nYear, v5++);
    m_nDate -= v8;
    this->m_nMonth = v5;
    this->m_nDate = m_nDate;
    if ( v5 > 12 )
    {
      ++m_nYear;
      v5 = 1;
      this->m_nYear = m_nYear;
      this->m_nMonth = 1;
    }
  }
  v9 = this->m_nDate;
  if ( v9 < 1 )
  {
    v10 = this->m_nMonth;
    v11 = this->m_nYear;
    do
    {
      this->m_nMonth = --v10;
      if ( v10 < 1 )
      {
        --v11;
        v10 = 12;
        this->m_nYear = v11;
        this->m_nMonth = 12;
      }
      v9 += OSuite::ZDateTime::DaysInMonth(v11, v10);
      this->m_nDate = v9;
    }
    while ( v9 < 1 );
  }
}

// File Line: 546
// RVA: 0xEE93D8
bool __fastcall OSuite::ZDateTime::ParseRFC3339(OSuite::ZDateTime *this, OSuite::ZString *sDate)
{
  bool v4; // al
  OSuite::ZString *v5; // rax
  OSuite::ZString *v6; // rax
  OSuite::ZString *v7; // rax
  OSuite::ZString *v8; // rax
  int v9; // esi
  OSuite::ZString *v10; // rax
  int v11; // r15d
  OSuite::ZString *v12; // rax
  int i; // r14d
  unsigned __int8 v14; // al
  char v15; // al
  int v16; // r14d
  char v17; // r12
  OSuite::ZString *v18; // rax
  int v19; // edi
  unsigned __int64 v20; // r14
  OSuite::ZString *v21; // rax
  int v22; // ebx
  int v23; // edi
  int v24; // [rsp+20h] [rbp-30h]
  int v25; // [rsp+28h] [rbp-28h]
  OSuite::ZString result; // [rsp+30h] [rbp-20h] BYREF
  int v27; // [rsp+A0h] [rbp+50h]
  int v28; // [rsp+A8h] [rbp+58h]

  if ( !OSuite::ZDateTime::IsDigits(sDate, 0i64, 4) )
    return 0;
  v5 = OSuite::ZString::Slice(sDate, &result, 0i64, 4ui64);
  v27 = OSuite::ZString::ToInt(v5);
  OSuite::ZString::~ZString(&result);
  if ( OSuite::ZString::CharAt(sDate, 4ui64) != 45 )
    return 0;
  if ( !OSuite::ZDateTime::IsDigits(sDate, 5ui64, 2) )
    return 0;
  v6 = OSuite::ZString::Slice(sDate, &result, 5ui64, 2ui64);
  v28 = OSuite::ZString::ToInt(v6);
  OSuite::ZString::~ZString(&result);
  if ( OSuite::ZString::CharAt(sDate, 7ui64) != 45 )
    return 0;
  if ( !OSuite::ZDateTime::IsDigits(sDate, 8ui64, 2) )
    return 0;
  v7 = OSuite::ZString::Slice(sDate, &result, 8ui64, 2ui64);
  v24 = OSuite::ZString::ToInt(v7);
  OSuite::ZString::~ZString(&result);
  if ( OSuite::ZString::CharAt(sDate, 0xAui64) != 84 && OSuite::ZString::CharAt(sDate, 0xAui64) != 116 )
    return 0;
  if ( !OSuite::ZDateTime::IsDigits(sDate, 0xBui64, 2) )
    return 0;
  v8 = OSuite::ZString::Slice(sDate, &result, 0xBui64, 2ui64);
  v9 = OSuite::ZString::ToInt(v8);
  OSuite::ZString::~ZString(&result);
  if ( OSuite::ZString::CharAt(sDate, 0xDui64) != 58 )
    return 0;
  if ( !OSuite::ZDateTime::IsDigits(sDate, 0xEui64, 2) )
    return 0;
  v10 = OSuite::ZString::Slice(sDate, &result, 0xEui64, 2ui64);
  v11 = OSuite::ZString::ToInt(v10);
  OSuite::ZString::~ZString(&result);
  if ( OSuite::ZString::CharAt(sDate, 0x10ui64) != 58 || !OSuite::ZDateTime::IsDigits(sDate, 0x11ui64, 2) )
    return 0;
  v12 = OSuite::ZString::Slice(sDate, &result, 0x11ui64, 2ui64);
  v25 = OSuite::ZString::ToInt(v12);
  OSuite::ZString::~ZString(&result);
  i = 19;
  if ( OSuite::ZString::CharAt(sDate, 0x13ui64) == 46 )
  {
    for ( i = 20; i < (int)OSuite::ZString::Count(sDate); ++i )
    {
      v14 = OSuite::ZString::CharAt(sDate, i);
      if ( !isdigit(v14) )
        break;
    }
  }
  if ( OSuite::ZString::CharAt(sDate, i) == 43 || OSuite::ZString::CharAt(sDate, i) == 45 )
  {
    v15 = OSuite::ZString::CharAt(sDate, i);
    v16 = i + 1;
    v17 = v15;
    if ( OSuite::ZDateTime::IsDigits(sDate, v16, 2) )
    {
      v18 = OSuite::ZString::Slice(sDate, &result, v16, 2ui64);
      v19 = OSuite::ZString::ToInt(v18);
      OSuite::ZString::~ZString(&result);
      v20 = v16 + 2;
      if ( OSuite::ZDateTime::IsDigits(sDate, v20, 2) )
      {
        v21 = OSuite::ZString::Slice(sDate, &result, v20, 2ui64);
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
  if ( OSuite::ZString::CharAt(sDate, i) != 90 )
    OSuite::ZString::CharAt(sDate, i);
LABEL_27:
  this->m_nYear = v27;
  this->m_nMonth = v28;
  this->m_nDate = v24;
  v4 = 1;
  this->m_nSecond = v25 + 60 * (v11 + 60 * v9);
  return v4;
}

// File Line: 660
// RVA: 0xEE90AC
char __fastcall OSuite::ZDateTime::ParseRFC1123(OSuite::ZDateTime *this, OSuite::ZString *sDate)
{
  char v4; // bl
  OSuite::ZString *v5; // rax
  OSuite::ZString *v6; // rax
  bool v7; // si
  int v8; // ebx
  OSuite::ZString *v10; // rax
  int v11; // ebx
  unsigned __int8 v12; // al
  int v13; // ebx
  OSuite::ZString *v14; // rax
  int Month; // r12d
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
  int v29; // r13d
  int v30; // ebx
  char v31; // al
  int v32; // ebx
  OSuite::ZString *v33; // rax
  int v34; // r15d
  OSuite::ZString *v35; // rax
  bool v36; // bl
  OSuite::ZString v37; // [rsp+20h] [rbp-30h] BYREF
  OSuite::ZString result; // [rsp+38h] [rbp-18h] BYREF
  int v39; // [rsp+A0h] [rbp+50h]
  int v40; // [rsp+A8h] [rbp+58h]

  v4 = 1;
  v5 = OSuite::ZString::Slice(sDate, &result, 0i64, 3ui64);
  v7 = 0;
  if ( OSuite::ZDateTime::IsShortDay(v5) )
  {
    v4 = 3;
    v6 = OSuite::ZString::Slice(sDate, &v37, 3ui64, 2ui64);
    if ( OSuite::ZString::operator==(v6, ", ") )
      v7 = 1;
  }
  if ( (v4 & 2) != 0 )
  {
    v4 &= ~2u;
    OSuite::ZString::~ZString(&v37);
  }
  if ( (v4 & 1) != 0 )
    OSuite::ZString::~ZString(&result);
  v8 = 0;
  if ( v7 )
    v8 = 5;
  if ( !OSuite::ZDateTime::IsDigits(sDate, v8, 2) )
    return 0;
  v10 = OSuite::ZString::Slice(sDate, &result, v8, 2ui64);
  v40 = OSuite::ZString::ToInt(v10);
  OSuite::ZString::~ZString(&result);
  v11 = v8 + 2;
  v12 = OSuite::ZString::CharAt(sDate, v11);
  v13 = v11 + 1;
  if ( !isspace(v12) )
    return 0;
  v14 = OSuite::ZString::Slice(sDate, &result, v13, 3ui64);
  Month = OSuite::ZDateTime::GetMonth(v14);
  OSuite::ZString::~ZString(&result);
  if ( !Month )
    return 0;
  v16 = v13 + 3;
  v17 = OSuite::ZString::CharAt(sDate, v16);
  v18 = v16 + 1;
  if ( !isspace(v17) )
    return 0;
  if ( !OSuite::ZDateTime::IsDigits(sDate, v18, 4) )
    return 0;
  v19 = OSuite::ZString::Slice(sDate, &result, v18, 4ui64);
  v39 = OSuite::ZString::ToInt(v19);
  OSuite::ZString::~ZString(&result);
  v20 = v18 + 4;
  v21 = OSuite::ZString::CharAt(sDate, v20);
  v22 = v20 + 1;
  if ( !isspace(v21) )
    return 0;
  if ( !OSuite::ZDateTime::IsDigits(sDate, v22, 2) )
    return 0;
  v23 = OSuite::ZString::Slice(sDate, &result, v22, 2ui64);
  v24 = OSuite::ZString::ToInt(v23);
  OSuite::ZString::~ZString(&result);
  v25 = v22 + 2;
  v26 = OSuite::ZString::CharAt(sDate, v25);
  v27 = v25 + 1;
  if ( v26 != 58 )
    return 0;
  if ( !OSuite::ZDateTime::IsDigits(sDate, v27, 2) )
    return 0;
  v28 = OSuite::ZString::Slice(sDate, &result, v27, 2ui64);
  v29 = OSuite::ZString::ToInt(v28);
  OSuite::ZString::~ZString(&result);
  v30 = v27 + 2;
  v31 = OSuite::ZString::CharAt(sDate, v30);
  v32 = v30 + 1;
  if ( v31 != 58 )
    return 0;
  if ( !OSuite::ZDateTime::IsDigits(sDate, v32, 2) )
    return 0;
  v33 = OSuite::ZString::Slice(sDate, &result, v32, 2ui64);
  v34 = OSuite::ZString::ToInt(v33);
  OSuite::ZString::~ZString(&result);
  v35 = OSuite::ZString::Slice(sDate, &result, v32 + 2, 4ui64);
  v36 = OSuite::ZString::operator==(v35, " GMT") == 0;
  OSuite::ZString::~ZString(&result);
  if ( v36 )
    return 0;
  this->m_nMonth = Month;
  this->m_nYear = v39;
  this->m_nDate = v40;
  this->m_nSecond = v34 + 60 * (v29 + 60 * v24);
  return 1;
}

// File Line: 732
// RVA: 0xEE977C
bool __fastcall OSuite::ZDateTime::ParseRFC850(OSuite::ZDateTime *this, OSuite::ZString *sDate)
{
  int IsLongDay; // eax
  bool v5; // al
  int v6; // ebx
  unsigned __int8 v7; // al
  int v8; // ebx
  OSuite::ZString *v9; // rax
  int v10; // ebx
  char v11; // al
  int v12; // ebx
  OSuite::ZString *v13; // rax
  int Month; // r13d
  int v15; // ebx
  char v16; // al
  int v17; // ebx
  OSuite::ZString *v18; // rax
  int v19; // r12d
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
  int v33; // r15d
  OSuite::ZString *v34; // rax
  bool v35; // bl
  int v36; // ecx
  OSuite::ZString result; // [rsp+20h] [rbp-20h] BYREF
  int v38; // [rsp+90h] [rbp+50h]
  int v39; // [rsp+98h] [rbp+58h]

  IsLongDay = OSuite::ZDateTime::IsLongDay(sDate);
  if ( !IsLongDay )
    return 0;
  v6 = IsLongDay + 1;
  if ( OSuite::ZString::CharAt(sDate, IsLongDay) != 44 )
    return 0;
  v7 = OSuite::ZString::CharAt(sDate, v6);
  v8 = v6 + 1;
  if ( !isspace(v7) )
    return 0;
  if ( !OSuite::ZDateTime::IsDigits(sDate, v8, 2) )
    return 0;
  v9 = OSuite::ZString::Slice(sDate, &result, v8, 2ui64);
  v38 = OSuite::ZString::ToInt(v9);
  OSuite::ZString::~ZString(&result);
  v10 = v8 + 2;
  v11 = OSuite::ZString::CharAt(sDate, v10);
  v12 = v10 + 1;
  if ( v11 != 45 )
    return 0;
  v13 = OSuite::ZString::Slice(sDate, &result, v12, 3ui64);
  Month = OSuite::ZDateTime::GetMonth(v13);
  OSuite::ZString::~ZString(&result);
  if ( !Month )
    return 0;
  v15 = v12 + 3;
  v16 = OSuite::ZString::CharAt(sDate, v15);
  v17 = v15 + 1;
  if ( v16 != 45 )
    return 0;
  if ( !OSuite::ZDateTime::IsDigits(sDate, v17, 2) )
    return 0;
  v18 = OSuite::ZString::Slice(sDate, &result, v17, 2ui64);
  v19 = OSuite::ZString::ToInt(v18);
  OSuite::ZString::~ZString(&result);
  v20 = v17 + 2;
  v21 = OSuite::ZString::CharAt(sDate, v20);
  v22 = v20 + 1;
  if ( !isspace(v21) )
    return 0;
  if ( !OSuite::ZDateTime::IsDigits(sDate, v22, 2) )
    return 0;
  v23 = OSuite::ZString::Slice(sDate, &result, v22, 2ui64);
  v24 = OSuite::ZString::ToInt(v23);
  OSuite::ZString::~ZString(&result);
  v25 = v22 + 2;
  v26 = OSuite::ZString::CharAt(sDate, v25);
  v27 = v25 + 1;
  if ( v26 != 58 )
    return 0;
  if ( !OSuite::ZDateTime::IsDigits(sDate, v27, 2) )
    return 0;
  v28 = OSuite::ZString::Slice(sDate, &result, v27, 2ui64);
  v39 = OSuite::ZString::ToInt(v28);
  OSuite::ZString::~ZString(&result);
  v29 = v27 + 2;
  v30 = OSuite::ZString::CharAt(sDate, v29);
  v31 = v29 + 1;
  if ( v30 != 58 )
    return 0;
  if ( !OSuite::ZDateTime::IsDigits(sDate, v31, 2) )
    return 0;
  v32 = OSuite::ZString::Slice(sDate, &result, v31, 2ui64);
  v33 = OSuite::ZString::ToInt(v32);
  OSuite::ZString::~ZString(&result);
  v34 = OSuite::ZString::Slice(sDate, &result, v31 + 2, 4ui64);
  v35 = OSuite::ZString::operator==(v34, " GMT") == 0;
  OSuite::ZString::~ZString(&result);
  if ( v35 )
    return 0;
  v36 = 1900;
  this->m_nMonth = Month;
  if ( v19 < 50 )
    v36 = 2000;
  this->m_nDate = v38;
  v5 = 1;
  this->m_nYear = v19 + v36;
  this->m_nSecond = v33 + 60 * (v39 + 60 * v24);
  return v5;
}

// File Line: 808
// RVA: 0xEE8DB0
bool __fastcall OSuite::ZDateTime::ParseAsctime(OSuite::ZDateTime *this, OSuite::ZString *sDate)
{
  OSuite::ZString *v4; // rax
  bool v5; // di
  OSuite::ZString *v6; // rax
  int Month; // r15d
  unsigned __int8 v8; // al
  unsigned __int8 v9; // al
  OSuite::ZString *v10; // rax
  int v11; // esi
  OSuite::ZString *v12; // rax
  unsigned __int8 v13; // al
  OSuite::ZString *v14; // rax
  int v15; // edi
  OSuite::ZString *v16; // rax
  int v17; // r13d
  OSuite::ZString *v18; // rax
  int v19; // r12d
  unsigned __int8 v20; // al
  OSuite::ZString *v21; // rax
  int v22; // ebx
  bool v23; // al
  OSuite::ZString result; // [rsp+20h] [rbp-20h] BYREF

  v4 = OSuite::ZString::Slice(sDate, &result, 0i64, 3ui64);
  v5 = OSuite::ZDateTime::IsShortDay(v4) && OSuite::ZString::CharAt(sDate, 3ui64) == 32;
  OSuite::ZString::~ZString(&result);
  if ( !v5 )
    return 0;
  v6 = OSuite::ZString::Slice(sDate, &result, 4ui64, 3ui64);
  Month = OSuite::ZDateTime::GetMonth(v6);
  OSuite::ZString::~ZString(&result);
  if ( !Month )
    return 0;
  v8 = OSuite::ZString::CharAt(sDate, 7ui64);
  if ( !isspace(v8) )
    return 0;
  v9 = OSuite::ZString::CharAt(sDate, 8ui64);
  if ( isspace(v9) )
  {
    if ( !OSuite::ZDateTime::IsDigits(sDate, 9ui64, 1) )
      return 0;
    v10 = OSuite::ZString::Slice(sDate, &result, 9ui64, 1ui64);
    v11 = OSuite::ZString::ToInt(v10);
  }
  else
  {
    if ( !OSuite::ZDateTime::IsDigits(sDate, 8ui64, 2) )
      return 0;
    v12 = OSuite::ZString::Slice(sDate, &result, 8ui64, 2ui64);
    v11 = OSuite::ZString::ToInt(v12);
  }
  OSuite::ZString::~ZString(&result);
  v13 = OSuite::ZString::CharAt(sDate, 0xAui64);
  if ( isspace(v13) )
  {
    if ( OSuite::ZDateTime::IsDigits(sDate, 0xBui64, 2) )
    {
      v14 = OSuite::ZString::Slice(sDate, &result, 0xBui64, 2ui64);
      v15 = OSuite::ZString::ToInt(v14);
      OSuite::ZString::~ZString(&result);
      if ( OSuite::ZString::CharAt(sDate, 0xDui64) == 58 )
      {
        if ( OSuite::ZDateTime::IsDigits(sDate, 0xEui64, 2) )
        {
          v16 = OSuite::ZString::Slice(sDate, &result, 0xEui64, 2ui64);
          v17 = OSuite::ZString::ToInt(v16);
          OSuite::ZString::~ZString(&result);
          if ( OSuite::ZString::CharAt(sDate, 0x10ui64) == 58 )
          {
            if ( OSuite::ZDateTime::IsDigits(sDate, 0x11ui64, 2) )
            {
              v18 = OSuite::ZString::Slice(sDate, &result, 0x11ui64, 2ui64);
              v19 = OSuite::ZString::ToInt(v18);
              OSuite::ZString::~ZString(&result);
              v20 = OSuite::ZString::CharAt(sDate, 0x13ui64);
              if ( isspace(v20) )
              {
                if ( OSuite::ZDateTime::IsDigits(sDate, 0x14ui64, 4) )
                {
                  v21 = OSuite::ZString::Slice(sDate, &result, 0x14ui64, 4ui64);
                  v22 = OSuite::ZString::ToInt(v21);
                  OSuite::ZString::~ZString(&result);
                  this->m_nYear = v22;
                  this->m_nMonth = Month;
                  this->m_nDate = v11;
                  v23 = 1;
                  this->m_nSecond = v19 + 60 * (v17 + 60 * v15);
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
  const char **v2; // rbx

  v2 = OSuite::ZDateTime::s_pszShortDays;
  while ( !OSuite::ZString::StartsWith(sString, *v2) )
  {
    if ( (__int64)++v2 >= (__int64)OSuite::ZDateTime::s_pszLongDays )
      return 0;
  }
  return 1;
}

// File Line: 907
// RVA: 0xEE8C70
size_t __fastcall OSuite::ZDateTime::IsLongDay(OSuite::ZString *sString)
{
  int v2; // edi
  const char **v3; // rbx

  v2 = 0;
  v3 = OSuite::ZDateTime::s_pszLongDays;
  while ( !OSuite::ZString::StartsWith(sString, *v3) )
  {
    ++v3;
    ++v2;
    if ( (__int64)v3 >= (__int64)days )
      return 0i64;
  }
  return strlen(OSuite::ZDateTime::s_pszLongDays[v2]);
}

// File Line: 921
// RVA: 0xEE8994
__int64 __fastcall OSuite::ZDateTime::GetMonth(OSuite::ZString *sString)
{
  int v2; // edi
  const char **v3; // rbx

  v2 = 0;
  v3 = OSuite::ZDateTime::s_pszMonths;
  while ( !OSuite::ZString::operator==(sString, *v3) )
  {
    ++v3;
    ++v2;
    if ( (__int64)v3 >= (__int64)OSuite::ZDateTime::s_pszShortDays )
      return 0i64;
  }
  return (unsigned int)(v2 + 1);
}

// File Line: 935
// RVA: 0xEE8BBC
char __fastcall OSuite::ZDateTime::IsDigits(OSuite::ZString *sString, unsigned __int64 nIndex, int nCount)
{
  int v3; // ebx
  unsigned __int8 v7; // al

  v3 = 0;
  if ( nCount <= 0 )
    return 1;
  while ( 1 )
  {
    v7 = OSuite::ZString::CharAt(sString, nIndex + v3);
    if ( !isdigit(v7) )
      break;
    if ( ++v3 >= nCount )
      return 1;
  }
  return 0;
}

