// File Line: 20
// RVA: 0xED9AD4
void __fastcall OSuite::ZOFilter::ZOFilter(OSuite::ZOFilter *this)
{
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZOFilter::`vftable';
  OSuite::ZStringBuilder::ZStringBuilder(&this->m_queryBuilder, 0x40ui64);
}

// File Line: 25
// RVA: 0xED9B00
void __fastcall OSuite::ZOFilter::~ZOFilter(OSuite::ZOFilter *this)
{
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZOFilter::`vftable';
  OSuite::ZUtf8Buffer::~ZUtf8Buffer(&this->m_queryBuilder);
}

// File Line: 46
// RVA: 0xED9C0C
OSuite::ZOFilter *__fastcall OSuite::ZOFilter::Compare(OSuite::ZOFilter *this, const char *propertyName, const char *value, OSuite::ZOFilter::ZOperation comparison)
{
  OSuite::ZOFilter *v4; // rbx

  v4 = this;
  if ( propertyName && value )
    OSuite::ZStringBuilder::AppendFormat(
      &this->m_queryBuilder,
      "%s %s '%s'",
      propertyName,
      off_14211D890[comparison],
      value);
  return v4;
}

// File Line: 171
// RVA: 0xED9C50
OSuite::ZOFilter *__fastcall OSuite::ZOFilter::Compare(OSuite::ZOFilter *this, const char *propertyName, int value, OSuite::ZOFilter::ZOperation comparison)
{
  OSuite::ZOFilter *v4; // rbx
  _QWORD v6[3]; // [rsp+20h] [rbp-18h]

  v4 = this;
  if ( propertyName )
  {
    LODWORD(v6[0]) = value;
    OSuite::ZStringBuilder::AppendFormat(
      &this->m_queryBuilder,
      "%s %s %d",
      propertyName,
      off_14211D890[comparison],
      v6[0]);
  }
  return v4;
}

// File Line: 184
// RVA: 0xED9C90
OSuite::ZOFilter *__fastcall OSuite::ZOFilter::Compare(OSuite::ZOFilter *this, const char *propertyName, __int64 value, OSuite::ZOFilter::ZOperation comparison)
{
  OSuite::ZOFilter *v4; // rbx

  v4 = this;
  if ( propertyName )
    OSuite::ZStringBuilder::AppendFormat(
      &this->m_queryBuilder,
      "%s %s %LiL",
      propertyName,
      off_14211D890[comparison],
      value);
  return v4;
}

// File Line: 197
// RVA: 0xED9B54
OSuite::ZOFilter *__fastcall OSuite::ZOFilter::And(OSuite::ZOFilter *this, OSuite::ZOFilter *otherExpression)
{
  OSuite::ZStringBuilder *v2; // rdi
  OSuite::ZOFilter *v3; // rbx
  OSuite::ZOFilter *v4; // rsi
  OSuite::ZString *v5; // rax
  const char *v6; // rbx
  const char *v7; // rax
  OSuite::ZString result; // [rsp+20h] [rbp-48h]
  OSuite::ZString v10; // [rsp+38h] [rbp-30h]

  v10.m_pString = 0i64;
  v2 = &this->m_queryBuilder;
  v3 = otherExpression;
  v4 = this;
  OSuite::ZStringBuilder::ToString(&this->m_queryBuilder, &v10);
  OSuite::ZStringBuilder::Clear(v2, 0x20ui64);
  v5 = OSuite::ZStringBuilder::ToString(&v3->m_queryBuilder, &result);
  v6 = OSuite::ZString::c_str(v5);
  v7 = OSuite::ZString::c_str(&v10);
  OSuite::ZStringBuilder::AppendFormat(v2, "(%s) and (%s)", v7, v6);
  OSuite::ZString::~ZString(&result);
  OSuite::ZString::~ZString(&v10);
  return v4;
}

// File Line: 207
// RVA: 0xED9CD0
OSuite::ZOFilter *__fastcall OSuite::ZOFilter::Or(OSuite::ZOFilter *this, OSuite::ZOFilter *otherExpression)
{
  OSuite::ZStringBuilder *v2; // rdi
  OSuite::ZOFilter *v3; // rbx
  OSuite::ZOFilter *v4; // rsi
  OSuite::ZString *v5; // rax
  const char *v6; // rbx
  const char *v7; // rax
  OSuite::ZString result; // [rsp+20h] [rbp-48h]
  OSuite::ZString v10; // [rsp+38h] [rbp-30h]

  v10.m_pString = 0i64;
  v2 = &this->m_queryBuilder;
  v3 = otherExpression;
  v4 = this;
  OSuite::ZStringBuilder::ToString(&this->m_queryBuilder, &v10);
  OSuite::ZStringBuilder::Clear(v2, 0x20ui64);
  v5 = OSuite::ZStringBuilder::ToString(&v3->m_queryBuilder, &result);
  v6 = OSuite::ZString::c_str(v5);
  v7 = OSuite::ZString::c_str(&v10);
  OSuite::ZStringBuilder::AppendFormat(v2, "(%s) or (%s)", v7, v6);
  OSuite::ZString::~ZString(&result);
  OSuite::ZString::~ZString(&v10);
  return v4;
}

// File Line: 217
// RVA: 0xED9D88
OSuite::ZString *__fastcall OSuite::ZOFilter::ToString(OSuite::ZOFilter *this, OSuite::ZString *result)
{
  OSuite::ZString *v2; // rbx

  v2 = result;
  OSuite::ZStringBuilder::ToString(&this->m_queryBuilder, result);
  return v2;
}

