// File Line: 35
// RVA: 0xEC5348
void __fastcall OSuite::ZOProperty::ZOProperty(
        OSuite::ZOProperty *this,
        OSuite::ZOEdmProperty *const pEdmProperty,
        OSuite::ZString *baseUrl)
{
  OSuite::EdmType m_Type; // eax
  OSuite::ZObject *v6; // rdx
  OSuite::ZOProperty **v7; // rax

  OSuite::ZAtomBase::ZAtomBase(this, baseUrl);
  this->m_bNull = 0;
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZOProperty::`vftable;
  m_Type = pEdmProperty->m_Type;
  this->m_pEdmProperty = pEdmProperty;
  this->m_Type = m_Type;
  OSuite::ZString::ZString(&this->m_Name, &pEdmProperty->m_Name);
  OSuite::ZString::ZString(&this->m_Value);
  OSuite::ZRedBlackTreeBase::ZElementBase::ZElementBase(&this->m_SubProperties, v6);
  this->m_SubProperties.m_pList = 0i64;
  this->m_SubProperties.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuitePrivate::ZPlayerConsumableData::ZRequest *>::`vftable{for `OSuite::ZListBase};
  this->m_SubProperties.vfptr = (OSuite::IHashableVtbl *)&OSuite::TList<OSuite::ZJsonObject *>::`vftable{for `OSuite::IHashable};
  v7 = (OSuite::ZOProperty **)OSuite::ZObject::malloc(&this->m_SubProperties, 0x80ui64, 0i64);
  this->m_SubProperties.m_nTop = 0i64;
  this->m_SubProperties.m_nSize = 16i64;
  this->m_SubProperties.m_pList = v7;
}

// File Line: 44
// RVA: 0xEC5288
void __fastcall OSuite::ZOProperty::ZOProperty(
        OSuite::ZOProperty *this,
        OSuite::ZString *name,
        OSuite::ZString *baseUrl)
{
  OSuite::ZObject *v5; // rdx
  OSuite::ZOProperty **v6; // rax

  OSuite::ZAtomBase::ZAtomBase(this, baseUrl);
  this->m_pEdmProperty = 0i64;
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZOProperty::`vftable;
  this->m_bNull = 0;
  OSuite::ZString::ZString(&this->m_Name, name);
  OSuite::ZString::ZString(&this->m_Value);
  OSuite::ZRedBlackTreeBase::ZElementBase::ZElementBase(&this->m_SubProperties, v5);
  this->m_SubProperties.m_pList = 0i64;
  this->m_SubProperties.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuitePrivate::ZPlayerConsumableData::ZRequest *>::`vftable{for `OSuite::ZListBase};
  this->m_SubProperties.vfptr = (OSuite::IHashableVtbl *)&OSuite::TList<OSuite::ZJsonObject *>::`vftable{for `OSuite::IHashable};
  v6 = (OSuite::ZOProperty **)OSuite::ZObject::malloc(&this->m_SubProperties, 0x80ui64, 0i64);
  this->m_SubProperties.m_nTop = 0i64;
  this->m_SubProperties.m_pList = v6;
  this->m_SubProperties.m_nSize = 16i64;
  this->m_Type = OSuite::deduceEdmTypeFromName(&this->m_Name);
}

// File Line: 51
// RVA: 0xEC53F8
void __fastcall OSuite::ZOProperty::~ZOProperty(OSuite::ZOProperty *this)
{
  OSuite::TList<OSuite::ZOProperty *> *p_m_SubProperties; // rdi
  unsigned __int64 m_nIndex; // rsi
  OSuite::ZListBase *m_pListBase; // rbx
  unsigned __int64 v5; // rbp
  void (__fastcall ***v6)(_QWORD, __int64); // rcx
  OSuite::ZOProperty **m_pList; // rdx
  OSuite::ZOProperty **v8; // rax
  OSuite::ZOProperty **v9; // rdx
  OSuite::ZListBase::ZListIteratorBase v10; // [rsp+20h] [rbp-38h] BYREF

  v10.m_pListBase = 0i64;
  p_m_SubProperties = &this->m_SubProperties;
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZOProperty::`vftable;
  OSuite::ZListBase::ZListIteratorBase::ZListIteratorBase(&v10, &this->m_SubProperties);
  v10.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable;
  while ( !OSuite::ZListBase::ZListIteratorBase::AtEnd(&v10) )
  {
    OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)v10.m_pListBase);
    m_nIndex = v10.m_nIndex;
    m_pListBase = v10.m_pListBase;
    v5 = v10.m_nIndex + 1;
    OSuite::TList<OSuite::ZONavigationProperty *>::Grow(
      (OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *)v10.m_pListBase,
      v10.m_nIndex + 1);
    if ( m_nIndex >= m_pListBase->m_nTop )
      m_pListBase->m_nTop = v5;
    v6 = *(void (__fastcall ****)(_QWORD, __int64))(m_pListBase[1].m_nSize + 8 * m_nIndex);
    if ( v6 )
      (**v6)(v6, 1i64);
    OSuite::ZListBase::ZListIteratorBase::Next(&v10);
  }
  m_pList = p_m_SubProperties->m_pList;
  v10.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable;
  OSuite::ZObject::free(p_m_SubProperties, m_pList);
  v8 = (OSuite::ZOProperty **)OSuite::ZObject::malloc(p_m_SubProperties, 0x80ui64, 0i64);
  p_m_SubProperties->m_nTop = 0i64;
  p_m_SubProperties->m_nSize = 16i64;
  p_m_SubProperties->m_pList = v8;
  v9 = p_m_SubProperties->m_pList;
  p_m_SubProperties->OSuite::ZListBase::OSuite::ZObject::vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuitePrivate::ZPlayerConsumableData::ZRequest *>::`vftable{for `OSuite::ZListBase};
  p_m_SubProperties->OSuite::IHashable::vfptr = (OSuite::IHashableVtbl *)&OSuite::TList<OSuite::ZJsonObject *>::`vftable{for `OSuite::IHashable};
  OSuite::ZObject::free(p_m_SubProperties, v9);
  OSuite::ZString::~ZString(&this->m_Value);
  OSuite::ZString::~ZString(&this->m_Name);
  OSuite::ZAtomBase::~ZAtomBase(this);
}

// File Line: 61
// RVA: 0xEC6A1C
__int64 __fastcall OSuite::ZOProperty::Type(OSuite::ZOProperty *this)
{
  return (unsigned int)this->m_Type;
}

// File Line: 67
// RVA: 0xEC5EAC
void __fastcall OSuite::ZOProperty::ResetToDefault(OSuite::ZOProperty *this)
{
  OSuite::EdmType m_Type; // edx
  __int32 v3; // edx
  __int32 v4; // edx
  __int32 v5; // edx
  int v6; // edx
  OSuite::ZDateTime *v7; // rax
  OSuite::ZString *v8; // rax
  OSuite::ZString *v9; // rax
  OSuite::ZDateTime *p_result; // rcx
  OSuite::ZDateTime *v11; // rax
  OSuite::ZString *v12; // rax
  OSuite::ZString *p_that; // rcx
  __int32 v14; // edx
  __int32 v15; // edx
  __int32 v16; // edx
  int v17; // edx
  unsigned __int64 m_nIndex; // rdi
  OSuite::ZListBase *m_pListBase; // rbx
  unsigned __int64 v20; // rsi
  OSuite::ZDateTime *v21; // rax
  OSuite::ZString *v22; // rax
  OSuite::ZString *v23; // rax
  OSuite::ZString v24; // [rsp+20h] [rbp-D8h] BYREF
  OSuite::ZUuid v25; // [rsp+38h] [rbp-C0h] BYREF
  OSuite::ZString v26; // [rsp+58h] [rbp-A0h] BYREF
  OSuite::ZString v27; // [rsp+70h] [rbp-88h] BYREF
  OSuite::ZString that; // [rsp+98h] [rbp-60h] BYREF
  OSuite::ZString v29; // [rsp+B0h] [rbp-48h] BYREF
  OSuite::ZString v30; // [rsp+C8h] [rbp-30h] BYREF
  OSuite::ZDateTime v31; // [rsp+E0h] [rbp-18h] BYREF
  OSuite::ZString v32; // [rsp+F8h] [rbp+0h] BYREF
  OSuite::ZDateTime result; // [rsp+110h] [rbp+18h] BYREF
  OSuite::ZDateTime v34; // [rsp+128h] [rbp+30h] BYREF
  OSuite::ZString v35; // [rsp+140h] [rbp+48h] BYREF
  OSuite::ZString v36; // [rsp+158h] [rbp+60h] BYREF
  OSuite::ZString v37; // [rsp+170h] [rbp+78h] BYREF
  OSuite::ZListBase::ZListIteratorBase v38; // [rsp+188h] [rbp+90h] BYREF

  m_Type = this->m_Type;
  if ( m_Type <= EDM_DOUBLE )
  {
    if ( m_Type < EDM_DECIMAL )
    {
      if ( m_Type == EDM_NULL )
        return;
      v3 = m_Type - 1;
      if ( v3 )
      {
        v4 = v3 - 1;
        if ( v4 )
        {
          v5 = v4 - 1;
          if ( v5 )
          {
            v6 = v5 - 1;
            if ( !v6 )
            {
              v11 = OSuite::ZDateTime::CurrentDateTime(&v31);
              v12 = OSuite::ZDateTime::ISO8601Date(v11, &v37);
              OSuite::ZString::operator=(&this->m_Value, v12);
              OSuite::ZString::~ZString(&v37);
              p_result = &v31;
              goto LABEL_11;
            }
            if ( v6 == 1 )
            {
              v7 = OSuite::ZDateTime::CurrentDateTime(&result);
              v8 = OSuite::ZDateTime::ISO8601Date(v7, &v35);
              v9 = OSuite::ZString::operator+(v8, &v30, "Z");
              OSuite::ZString::operator=(&this->m_Value, v9);
              OSuite::ZString::~ZString(&v30);
              OSuite::ZString::~ZString(&v35);
              p_result = &result;
LABEL_11:
              OSuite::ZJsonSerializer::~ZJsonSerializer(p_result);
              return;
            }
LABEL_20:
            OSuite::ZString::ZString(&v26, "0");
            OSuite::ZString::operator=(&this->m_Value, &v26);
            p_that = &v26;
            goto LABEL_31;
          }
          OSuite::ZString::ZString(&that, "00");
          OSuite::ZString::operator=(&this->m_Value, &that);
          p_that = &that;
        }
        else
        {
          OSuite::ZString::ZString(&v27, "false");
          OSuite::ZString::operator=(&this->m_Value, &v27);
          p_that = &v27;
        }
      }
      else
      {
        OSuite::ZString::ZString(&v24, &customCaption);
        OSuite::ZString::operator=(&this->m_Value, &v24);
        p_that = &v24;
      }
LABEL_31:
      OSuite::ZString::~ZString(p_that);
      return;
    }
LABEL_29:
    OSuite::ZString::ZString(&v29, "0.0");
    OSuite::ZString::operator=(&this->m_Value, &v29);
    p_that = &v29;
    goto LABEL_31;
  }
  v14 = m_Type - 8;
  if ( !v14 )
  {
    v25.OSuite::ZObject::vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZUuid::`vftable{for `OSuite::ZObject};
    v25.OSuite::IHashable::vfptr = (OSuite::IHashableVtbl *)&OSuite::ZUuid::`vftable{for `OSuite::IHashable};
    OSuite::psock::uuid::create(v25.m_anUuid, 1);
    v23 = OSuite::ZUuid::ToString(&v25, &v36);
    OSuite::ZString::operator=(&this->m_Value, v23);
    p_that = &v36;
    goto LABEL_31;
  }
  v15 = v14 - 5;
  if ( !v15 )
    goto LABEL_29;
  v16 = v15 - 1;
  if ( !v16 )
  {
    OSuite::ZString::ZString((OSuite::ZString *)&v27.m_pString, &customCaption);
    OSuite::ZString::operator=(&this->m_Value, (OSuite::ZString *)&v27.m_pString);
    p_that = (OSuite::ZString *)&v27.m_pString;
    goto LABEL_31;
  }
  v17 = v16 - 1;
  if ( !v17 )
  {
    v21 = OSuite::ZDateTime::CurrentDateTime(&v34);
    v22 = OSuite::ZDateTime::ISO8601Time(v21, &v32);
    OSuite::ZString::operator=(&this->m_Value, v22);
    OSuite::ZString::~ZString(&v32);
    p_result = &v34;
    goto LABEL_11;
  }
  if ( v17 != 1 )
    goto LABEL_20;
  v38.m_pListBase = 0i64;
  OSuite::ZListBase::ZListIteratorBase::ZListIteratorBase(&v38, &this->m_SubProperties);
  v38.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable;
  while ( !OSuite::ZListBase::ZListIteratorBase::AtEnd(&v38) )
  {
    OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)v38.m_pListBase);
    m_nIndex = v38.m_nIndex;
    m_pListBase = v38.m_pListBase;
    v20 = v38.m_nIndex + 1;
    OSuite::TList<OSuite::ZONavigationProperty *>::Grow(
      (OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *)v38.m_pListBase,
      v38.m_nIndex + 1);
    if ( m_nIndex >= m_pListBase->m_nTop )
      m_pListBase->m_nTop = v20;
    OSuite::ZOProperty::ResetToDefault(*(OSuite::ZOProperty **)(m_pListBase[1].m_nSize + 8 * m_nIndex));
    OSuite::ZListBase::ZListIteratorBase::Next(&v38);
  }
}

// File Line: 140
// RVA: 0xEC5784
char __fastcall OSuite::ZOProperty::GetValue(OSuite::ZOProperty *this, OSuite::ZString *outValue)
{
  OSuite::ZString *p_m_Value; // rdi

  p_m_Value = &this->m_Value;
  if ( !OSuite::ZString::operator bool(&this->m_Value) || this->m_bNull || this->m_Type != EDM_STRING )
    return 0;
  OSuite::ZString::operator=(outValue, p_m_Value);
  return 1;
}

// File Line: 196
// RVA: 0xEC5710
char __fastcall OSuite::ZOProperty::GetValue(OSuite::ZOProperty *this, int *outValue)
{
  OSuite::ZString *p_m_Value; // rdi

  p_m_Value = &this->m_Value;
  if ( !OSuite::ZString::operator bool(&this->m_Value)
    || this->m_bNull
    || this->m_Type != EDM_INT32
    || (unsigned __int64)(OSuite::ZString::ToInt(p_m_Value) + 0x80000000i64) > 0xFFFFFFFF )
  {
    return 0;
  }
  *outValue = OSuite::ZString::ToInt(p_m_Value);
  return 1;
}

// File Line: 215
// RVA: 0xEC57E0
char __fastcall OSuite::ZOProperty::GetValue(OSuite::ZOProperty *this, __int64 *outValue)
{
  OSuite::ZString *p_m_Value; // rdi

  p_m_Value = &this->m_Value;
  if ( !OSuite::ZString::operator bool(&this->m_Value) || this->m_bNull || this->m_Type != EDM_INT64 )
    return 0;
  *outValue = OSuite::ZString::ToInt(p_m_Value);
  return 1;
}

// File Line: 227
// RVA: 0xEC583C
char __fastcall OSuite::ZOProperty::GetValue(OSuite::ZOProperty *this, bool *outValue)
{
  OSuite::ZString *p_m_Value; // rdi

  p_m_Value = &this->m_Value;
  if ( !OSuite::ZString::operator bool(&this->m_Value) || this->m_bNull || this->m_Type != EDM_BOOLEAN )
    return 0;
  *outValue = OSuite::ZString::EqualsCaseInsensitive(p_m_Value, "true");
  return 1;
}

// File Line: 282
// RVA: 0xEC63B8
char __fastcall OSuite::ZOProperty::SetValue(OSuite::ZOProperty *this, const char *inValue)
{
  OSuite::ZString that; // [rsp+20h] [rbp-28h] BYREF

  if ( !inValue || this->m_Type != EDM_STRING )
    return 0;
  OSuite::ZString::ZString(&that, inValue);
  OSuite::ZString::operator=(&this->m_Value, &that);
  OSuite::ZString::~ZString(&that);
  this->m_bNull = 0;
  return 1;
}

// File Line: 295
// RVA: 0xEC62C0
char __fastcall OSuite::ZOProperty::SetValue(OSuite::ZOProperty *this, OSuite::ZString *inValue)
{
  if ( !OSuite::ZString::operator bool(inValue) || this->m_Type != EDM_STRING )
    return 0;
  OSuite::ZString::operator=(&this->m_Value, inValue);
  this->m_bNull = 0;
  return 1;
}

// File Line: 308
// RVA: 0xEC6204
char __fastcall OSuite::ZOProperty::SetValue(OSuite::ZOProperty *this, OSuite::ZDateTime *inValue)
{
  OSuite::EdmType m_Type; // eax
  OSuite::ZString *v4; // rax
  OSuite::ZString *p_result; // rcx
  OSuite::ZString *v7; // rax
  OSuite::ZString *v8; // rax
  OSuite::ZString *v9; // rax
  OSuite::ZString result; // [rsp+20h] [rbp-38h] BYREF
  OSuite::ZString v11; // [rsp+38h] [rbp-20h] BYREF

  m_Type = this->m_Type;
  switch ( m_Type )
  {
    case EDM_DATETIME:
      v4 = OSuite::ZDateTime::ISO8601Date(inValue, &result);
      OSuite::ZString::operator=(&this->m_Value, v4);
      p_result = &result;
LABEL_3:
      OSuite::ZString::~ZString(p_result);
      this->m_bNull = 0;
      return 1;
    case EDM_DATETIMEOFFSET:
      v7 = OSuite::ZDateTime::ISO8601Date(inValue, &v11);
      v8 = OSuite::ZString::operator+(v7, &result, "Z");
      OSuite::ZString::operator=(&this->m_Value, v8);
      OSuite::ZString::~ZString(&result);
LABEL_6:
      p_result = &v11;
      goto LABEL_3;
    case EDM_TIME:
      v9 = OSuite::ZDateTime::ISO8601Time(inValue, &v11);
      OSuite::ZString::operator=(&this->m_Value, v9);
      goto LABEL_6;
  }
  return 0;
}

// File Line: 349
// RVA: 0xEC630C
char __fastcall OSuite::ZOProperty::SetValue(OSuite::ZOProperty *this, unsigned int inValue)
{
  OSuite::ZString *v4; // rax
  OSuite::ZString result; // [rsp+20h] [rbp-58h] BYREF
  OSuite::ZStringBuilder v7; // [rsp+38h] [rbp-40h] BYREF

  if ( this->m_Type != EDM_INT32 )
    return 0;
  v7.m_Chars.m_pList = 0i64;
  OSuite::ZStringBuilder::ZStringBuilder(&v7, 0x10ui64);
  OSuite::ZStringBuilder::AppendFormat(&v7, "%d", inValue);
  v4 = OSuite::ZStringBuilder::ToString(&v7, &result);
  OSuite::ZString::operator=(&this->m_Value, v4);
  OSuite::ZString::~ZString(&result);
  this->m_bNull = 0;
  OSuite::ZUtf8Buffer::~ZUtf8Buffer(&v7);
  return 1;
}

// File Line: 436
// RVA: 0xEC55E4
unsigned __int64 __fastcall OSuite::ZOProperty::GetBinarySize(OSuite::ZOProperty *this)
{
  if ( this->m_bNull || this->m_Type != EDM_BINARY )
    return 0i64;
  else
    return OSuite::ZMimeEntity::Base64DecodedLength(&this->m_Value);
}

// File Line: 447
// RVA: 0xEC5578
bool __fastcall OSuite::ZOProperty::GetBinary(OSuite::ZOProperty *this, char *buffer, unsigned __int64 bufferLength)
{
  char v3; // bl

  v3 = 0;
  if ( buffer
    && bufferLength
    && !this->m_bNull
    && this->m_Type == EDM_BINARY
    && OSuite::ZOProperty::GetBinarySize(this) == bufferLength )
  {
    return OSuite::ZMimeEntity::Base64Decode(buffer, &this->m_Value);
  }
  return v3;
}

// File Line: 476
// RVA: 0xEC5614
OSuite::ZOProperty *__fastcall OSuite::ZOProperty::GetSubProperty(
        OSuite::ZOProperty *this,
        const char *subPropertyName)
{
  unsigned __int64 m_nIndex; // rsi
  OSuite::ZListBase *m_pListBase; // rbx
  unsigned __int64 v5; // rdi
  __int64 v6; // rbx
  OSuite::ZListBase::ZListIteratorBase v8; // [rsp+20h] [rbp-40h] BYREF
  OSuite::ZString that; // [rsp+38h] [rbp-28h] BYREF

  if ( !subPropertyName )
    return 0i64;
  that.m_pString = 0i64;
  OSuite::ZString::ZString(&that, subPropertyName);
  v8.m_pListBase = 0i64;
  OSuite::ZListBase::ZListIteratorBase::ZListIteratorBase(&v8, &this->m_SubProperties);
  v8.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable;
  while ( 1 )
  {
    if ( OSuite::ZListBase::ZListIteratorBase::AtEnd(&v8) )
    {
      OSuite::ZString::~ZString(&that);
      return 0i64;
    }
    OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)v8.m_pListBase);
    m_nIndex = v8.m_nIndex;
    m_pListBase = v8.m_pListBase;
    v5 = v8.m_nIndex + 1;
    OSuite::TList<OSuite::ZONavigationProperty *>::Grow(
      (OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *)v8.m_pListBase,
      v8.m_nIndex + 1);
    if ( m_nIndex >= m_pListBase->m_nTop )
      m_pListBase->m_nTop = v5;
    v6 = *(_QWORD *)(m_pListBase[1].m_nSize + 8 * m_nIndex);
    if ( OSuite::ZString::operator==((OSuite::ZString *)(v6 + 152), &that) )
      break;
    OSuite::ZListBase::ZListIteratorBase::Next(&v8);
  }
  v8.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable;
  OSuite::ZString::~ZString(&that);
  return (OSuite::ZOProperty *)v6;
}

// File Line: 527
// RVA: 0xEC5938
void __fastcall OSuite::ZOProperty::ParseJsonValue(
        OSuite::ZOProperty *this,
        OSuite::ZString *__formal,
        OSuite::ZJsonValue *pJson)
{
  OSuite::ZJsonValue *v5; // r13
  OSuite::ZJsonValue *v6; // rax
  OSuite::ZOnlineSuite *v7; // rax
  OSuite::ZWebServiceClient *v8; // rbx
  OSuite::ZOMetadata *v9; // rax
  OSuite::ZOEdmComplexType *v10; // rax
  OSuite::TMap<OSuite::ZString,OSuite::ZJsonValue *> *p_m_Pairs; // rcx
  OSuite::ZOEdmComplexType *v12; // rbx
  void *(__fastcall *vecDelDtor)(OSuite::IHashable *, unsigned int); // r12
  OSuite::ZString *p_ComputeHash; // r15
  OSuite::ZOProperty *v15; // rax
  OSuite::ZOProperty *v16; // rbx
  OSuite::ZOEdmProperty *v17; // rax
  OSuite::ZOProperty *v18; // rax
  OSuite::ZOProperty *v19; // r14
  OSuite::ZString *p_result; // rcx
  OSuite::ZString *p_m_Value; // rbx
  bool v22; // al
  unsigned __int64 v23; // rax
  OSuite::ZString *v24; // rax
  unsigned __int64 v25; // rax
  OSuite::ZString *v26; // rax
  unsigned __int64 v27; // rax
  OSuite::ZString *v28; // rax
  unsigned __int64 v29; // rax
  OSuite::ZString *v30; // rax
  unsigned __int64 v31; // rax
  OSuite::ZString *v32; // rax
  int v33; // esi
  int IndexOf; // eax
  __int64 v35; // rax
  OSuite::ZString *v36; // rax
  OSuite::ZError *v37; // rax
  OSuite::ZOEdmComplexType *v38; // [rsp+20h] [rbp-E0h]
  OSuite::ZString sName; // [rsp+28h] [rbp-D8h] BYREF
  OSuite::ZString result; // [rsp+40h] [rbp-C0h] BYREF
  OSuite::ZString v41; // [rsp+58h] [rbp-A8h] BYREF
  OSuite::ZString v42; // [rsp+70h] [rbp-90h] BYREF
  OSuite::ZString v43; // [rsp+88h] [rbp-78h] BYREF
  OSuite::ZString v44; // [rsp+A0h] [rbp-60h] BYREF
  OSuite::ZString fullyQualifiedName; // [rsp+B8h] [rbp-48h] BYREF
  OSuite::ZString v46; // [rsp+D0h] [rbp-30h] BYREF
  OSuite::ZUrl url; // [rsp+F0h] [rbp-10h] BYREF

  if ( pJson->m_Type != JSONTYPE_OBJECT )
  {
    p_m_Value = &this->m_Value;
    OSuite::ZString::operator=(&this->m_Value, &pJson->m_literal);
    v22 = OSuite::ZString::operator==(p_m_Value, "null");
    this->m_bNull = v22;
    if ( v22 )
      return;
    switch ( this->m_Type )
    {
      case EDM_DATETIME:
        if ( OSuite::ZString::StartsWith(p_m_Value, "\\/Date") )
        {
          v33 = OSuite::ZString::IndexOf(p_m_Value, 40, 0i64);
          IndexOf = OSuite::ZString::LastIndexOf(p_m_Value, 41);
          if ( v33 > 0 && IndexOf > 0 && IndexOf > v33 )
          {
            fullyQualifiedName.m_pString = 0i64;
            OSuite::ZString::Slice(p_m_Value, &fullyQualifiedName, v33 + 1, IndexOf - v33 - 1);
            v35 = OSuite::ZString::ToInt(&fullyQualifiedName);
            OSuite::ZDateTime::ZDateTime((OSuite::ZDateTime *)&v46, v35 / 1000);
            v36 = OSuite::ZDateTime::ISO8601Date((OSuite::ZDateTime *)&v46, &v44);
            OSuite::ZString::operator=(p_m_Value, v36);
            OSuite::ZString::~ZString(&v44);
            OSuite::ZJsonSerializer::~ZJsonSerializer((OSuite::ZDateTime *)&v46);
            goto LABEL_17;
          }
        }
        break;
      case EDM_DATETIMEOFFSET:
        if ( OSuite::ZString::StartsWith(p_m_Value, "datetimeoffset") )
        {
          v31 = OSuite::ZString::Count(p_m_Value);
          v32 = OSuite::ZString::Slice(p_m_Value, &v43, 0xFui64, v31 - 16);
          OSuite::ZString::operator=(p_m_Value, v32);
          p_result = &v43;
          goto LABEL_34;
        }
        break;
      case EDM_DECIMAL:
        if ( OSuite::ZString::EndsWith(p_m_Value, "M") || OSuite::ZString::EndsWith(p_m_Value, "m") )
        {
          v29 = OSuite::ZString::Count(p_m_Value);
          v30 = OSuite::ZString::Slice(p_m_Value, &v41, 0i64, v29 - 1);
          OSuite::ZString::operator=(p_m_Value, v30);
          p_result = &v41;
          goto LABEL_34;
        }
        break;
      case EDM_GUID:
        if ( OSuite::ZString::StartsWith(p_m_Value, "guid") )
        {
          v27 = OSuite::ZString::Count(p_m_Value);
          v28 = OSuite::ZString::Slice(p_m_Value, &v42, 5ui64, v27 - 6);
          OSuite::ZString::operator=(p_m_Value, v28);
          p_result = &v42;
          goto LABEL_34;
        }
        break;
      case EDM_SINGLE:
        if ( OSuite::ZString::EndsWith(p_m_Value, "f") )
        {
          v25 = OSuite::ZString::Count(p_m_Value);
          v26 = OSuite::ZString::Slice(p_m_Value, &result, 0i64, v25 - 1);
          OSuite::ZString::operator=(p_m_Value, v26);
          p_result = &result;
          goto LABEL_34;
        }
        break;
      case EDM_TIME:
        if ( OSuite::ZString::StartsWith(p_m_Value, "time") )
        {
          v23 = OSuite::ZString::Count(p_m_Value);
          v24 = OSuite::ZString::Slice(p_m_Value, &sName, 5ui64, v23 - 6);
          OSuite::ZString::operator=(p_m_Value, v24);
          p_result = &sName;
          goto LABEL_34;
        }
        break;
      default:
        return;
    }
    goto LABEL_42;
  }
  OSuite::ZString::ZString(&sName, "__metadata");
  v5 = OSuite::ZJsonObject::Value(pJson->m_object, &sName);
  OSuite::ZString::~ZString(&sName);
  if ( !v5 )
  {
LABEL_42:
    v37 = OSuite::TSingleton<OSuite::ZError>::Object();
    OSuite::ZError::SetThreadLastError(v37, ZERROR_PARSING_FAILED, 1);
    return;
  }
  fullyQualifiedName.m_pString = 0i64;
  OSuite::ZString::ZString(&v46, "type");
  v6 = OSuite::ZJsonObject::Value(v5->m_object, &v46);
  OSuite::ZString::ZString(&fullyQualifiedName, &v6->m_literal);
  OSuite::ZString::~ZString(&v46);
  OSuite::ZUrl::ZUrl(&url, &this->m_sBaseURL);
  v7 = OSuite::ZOnlineSuite::Instance();
  v8 = OSuite::ZOnlineSuite::GetForUrl(v7, &url);
  OSuite::ZUrl::~ZUrl(&url);
  v9 = OSuite::ZWebServiceClient::Metadata(v8);
  v10 = OSuite::ZOMetadata::ComplexType(v9, &fullyQualifiedName);
  p_m_Pairs = &pJson->m_object->m_Pairs;
  v12 = v10;
  v38 = v10;
  url.OSuite::IHashable::vfptr = 0i64;
  url.m_sHost.vfptr = 0i64;
  url.m_sHost.vfptr = 0i64;
  url.m_urlParameters.vfptr = 0i64;
  OSuite::TMap<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>::Iterator(
    (OSuite::TMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *> *)p_m_Pairs,
    (OSuite::TMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *>::ZIterator *)&url);
  while ( !OSuite::ZString::IsNull((OSuite::ZString *)&url.m_sProtocol.m_pString) )
  {
    vecDelDtor = url.m_sHost.vfptr[4].__vecDelDtor;
    p_ComputeHash = (OSuite::ZString *)&url.m_sHost.vfptr[2].ComputeHash;
    if ( (char *)vecDelDtor == (char *)v5 )
      goto LABEL_13;
    v15 = (OSuite::ZOProperty *)OSuite::ZObject::operator new(0xF0ui64);
    if ( v12 )
    {
      v16 = v15;
      if ( !v15 )
        goto LABEL_11;
      v15->m_sAuthorName.m_pString = 0i64;
      v15->m_sIdentifier.m_pString = 0i64;
      v15->m_sTitle.m_pString = 0i64;
      v15->m_sEditURL.m_pString = 0i64;
      v15->m_sBaseURL.m_pString = 0i64;
      v15->m_pEdmProperty = 0i64;
      v15->m_Name.m_pString = 0i64;
      v15->m_Value.m_pString = 0i64;
      v15->m_SubProperties.m_pList = 0i64;
      v17 = OSuite::ZOEdmComplexType::Property(v38, p_ComputeHash);
      OSuite::ZOProperty::ZOProperty(v16, v17, &this->m_sBaseURL);
    }
    else
    {
      if ( !v15 )
      {
LABEL_11:
        v19 = 0i64;
        goto LABEL_12;
      }
      v15->m_sAuthorName.m_pString = 0i64;
      v15->m_sIdentifier.m_pString = 0i64;
      v15->m_sTitle.m_pString = 0i64;
      v15->m_sEditURL.m_pString = 0i64;
      v15->m_sBaseURL.m_pString = 0i64;
      v15->m_pEdmProperty = 0i64;
      v15->m_Name.m_pString = 0i64;
      v15->m_Value.m_pString = 0i64;
      v15->m_SubProperties.m_pList = 0i64;
      OSuite::ZOProperty::ZOProperty(v15, p_ComputeHash, &this->m_sBaseURL);
    }
    v19 = v18;
LABEL_12:
    ((void (__fastcall *)(OSuite::ZOProperty *, OSuite::ZString *, void *(__fastcall *)(OSuite::IHashable *, unsigned int)))v19->vfptr[3].__vecDelDtor)(
      v19,
      p_ComputeHash,
      vecDelDtor);
    OSuite::TList<OSuite::ZONavigationProperty *>::Grow(
      (OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *)&this->m_SubProperties,
      this->m_SubProperties.m_nTop + 1);
    this->m_SubProperties.m_pList[this->m_SubProperties.m_nTop++] = v19;
    v12 = v38;
LABEL_13:
    OSuite::TMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *>::ZIterator::Next((OSuite::TMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *>::ZIterator *)&url);
  }
  url.OSuite::ZObject::vfptr = (OSuite::ZObjectVtbl *)&OSuite::TMap<OSuite::ZString,OSuite::ZJsonValue *>::ZIterator::`vftable;
  url.m_sProtocol.vfptr = (OSuite::IHashableVtbl *)&OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64>>::ZIterator::`vftable;
  url.m_sProtocol.m_pString = (OSuite::ZString::InternalString *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable;
  url.m_sHost.m_pString = (OSuite::ZString::InternalString *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::ZObject};
  url.m_sFakeHost.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::IHashable};
  if ( url.m_urlParameters.vfptr )
    (*(void (__fastcall **)(OSuite::IHashableVtbl *, __int64))url.m_urlParameters.vfptr->__vecDelDtor)(
      url.m_urlParameters.vfptr,
      1i64);
LABEL_17:
  p_result = &fullyQualifiedName;
LABEL_34:
  OSuite::ZString::~ZString(p_result);
}

// File Line: 668
// RVA: 0xEC6408
void __fastcall OSuite::ZOProperty::ToJson(OSuite::ZOProperty *this, OSuite::ZJsonObject *pJson, unsigned int eMethod)
{
  OSuite::ZJsonValue *v3; // rbx
  OSuite::ZJsonObject *v4; // r13
  OSuite::ZJsonValue *v6; // rax
  OSuite::ZJsonValue *v7; // rsi
  OSuite::ZJsonValue *v8; // rax
  OSuite::ZJsonObject *v9; // rax
  OSuite::ZJsonObject *v10; // rax
  OSuite::ZJsonObject *v11; // r12
  OSuite::ZOEdmProperty *m_pEdmProperty; // rcx
  char v13; // si
  OSuite::ZString *v14; // rax
  OSuite::ZJsonObject *v15; // rax
  OSuite::ZJsonObject *v16; // rax
  OSuite::ZJsonObject *v17; // r15
  OSuite::ZJsonValue *v18; // rax
  OSuite::ZJsonValue *v19; // rax
  OSuite::ZJsonValue *v20; // r14
  OSuite::ZJsonValue *v21; // rax
  OSuite::ZJsonValue *v22; // rax
  OSuite::ZJsonValue *v23; // r14
  unsigned __int64 v24; // r15
  OSuite::ZString::InternalString *m_pString; // r14
  unsigned __int64 v26; // r13
  __int64 v27; // rcx
  OSuite::ZJsonValue *v28; // rax
  OSuite::ZJsonValue *v29; // rax
  OSuite::EdmType m_Type; // ecx
  bool v31; // r14
  __int32 v32; // ecx
  __int32 v33; // ecx
  __int32 v34; // ecx
  int v35; // ecx
  OSuite::ZString *v36; // rax
  OSuite::ZString *p_result; // rcx
  OSuite::ZString *v38; // rax
  OSuite::ZString *v39; // rax
  OSuite::ZString *v40; // rax
  __int64 v41; // rax
  OSuite::ZString *v42; // rax
  OSuite::ZString *v43; // rax
  OSuite::ZString *v44; // rax
  OSuite::ZString *v45; // rax
  OSuite::ZString *v46; // rax
  OSuite::ZString *v47; // rax
  OSuite::ZString *v48; // rax
  OSuite::ZString *v49; // rax
  OSuite::ZJsonValue *v50; // rax
  OSuite::ZString result; // [rsp+30h] [rbp-D0h] BYREF
  OSuite::ZString v54; // [rsp+48h] [rbp-B8h] BYREF
  OSuite::ZString v55; // [rsp+60h] [rbp-A0h] BYREF
  OSuite::ZString v56; // [rsp+78h] [rbp-88h] BYREF
  OSuite::ZString v57; // [rsp+90h] [rbp-70h] BYREF
  OSuite::ZString v58; // [rsp+A8h] [rbp-58h] BYREF
  OSuite::ZString v59; // [rsp+C0h] [rbp-40h] BYREF
  OSuite::ZString v60; // [rsp+D8h] [rbp-28h] BYREF
  OSuite::ZString v61; // [rsp+F0h] [rbp-10h] BYREF
  OSuite::ZString v62; // [rsp+108h] [rbp+8h] BYREF
  OSuite::ZString v63; // [rsp+120h] [rbp+20h] BYREF
  OSuite::ZString sValue; // [rsp+138h] [rbp+38h] BYREF
  OSuite::ZString sName; // [rsp+150h] [rbp+50h] BYREF
  OSuite::ZString v66; // [rsp+168h] [rbp+68h] BYREF
  unsigned __int64 v67; // [rsp+180h] [rbp+80h]
  OSuite::ZStringBuilder v68; // [rsp+188h] [rbp+88h] BYREF

  v3 = 0i64;
  v4 = pJson;
  if ( !this->m_bNull )
  {
    if ( this->m_Type == EDM_COMPLEX )
    {
      v9 = (OSuite::ZJsonObject *)OSuite::ZObject::operator new(0x28ui64);
      if ( v9 )
      {
        v9->m_Pairs.m_pLists = 0i64;
        OSuite::ZJsonObject::ZJsonObject(v9);
        v11 = v10;
      }
      else
      {
        v11 = 0i64;
      }
      m_pEdmProperty = this->m_pEdmProperty;
      sValue.m_pString = 0i64;
      if ( m_pEdmProperty )
      {
        v13 = 2;
        v14 = OSuite::ZOEdmBase::FullyQualifiedName(m_pEdmProperty, &result);
      }
      else
      {
        v13 = 4;
        v14 = OSuite::ZString::operator+(&this->m_Name, &sName, "_complex");
      }
      OSuite::ZString::ZString(&sValue, v14);
      if ( (v13 & 4) != 0 )
      {
        v13 &= ~4u;
        OSuite::ZString::~ZString(&sName);
      }
      if ( (v13 & 2) != 0 )
        OSuite::ZString::~ZString(&result);
      v15 = (OSuite::ZJsonObject *)OSuite::ZObject::operator new(0x28ui64);
      if ( v15 )
      {
        v15->m_Pairs.m_pLists = 0i64;
        OSuite::ZJsonObject::ZJsonObject(v15);
        v17 = v16;
      }
      else
      {
        v17 = 0i64;
      }
      v18 = (OSuite::ZJsonValue *)OSuite::ZObject::operator new(0x60ui64);
      if ( v18 )
      {
        v18->m_literal.m_pString = 0i64;
        v18->m_array.m_pList = 0i64;
        v18->m_object = 0i64;
        OSuite::ZJsonValue::ZJsonValue(v18, &sValue, 1);
        v20 = v19;
      }
      else
      {
        v20 = 0i64;
      }
      OSuite::ZString::ZString(&sName, "type");
      OSuite::ZJsonObject::Add(v17, &sName, v20);
      OSuite::ZString::~ZString(&sName);
      v21 = (OSuite::ZJsonValue *)OSuite::ZObject::operator new(0x60ui64);
      if ( v21 )
      {
        v21->m_literal.m_pString = 0i64;
        v21->m_array.m_pList = 0i64;
        v21->m_object = 0i64;
        OSuite::ZJsonValue::ZJsonValue(v21, v17);
        v23 = v22;
      }
      else
      {
        v23 = 0i64;
      }
      OSuite::ZString::ZString(&sName, "__metadata");
      OSuite::ZJsonObject::Add(v11, &sName, v23);
      OSuite::ZString::~ZString(&sName);
      v66.m_pString = 0i64;
      OSuite::ZListBase::ZListIteratorBase::ZListIteratorBase(
        (OSuite::ZListBase::ZListIteratorBase *)&sName,
        &this->m_SubProperties);
      sName.OSuite::ZObject::vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable;
      v66.OSuite::ZObject::vfptr = (OSuite::ZObjectVtbl *)&OSuite::TConstIterator<OSuite::TList<OSuite::ZOEdmEndRole *>::ZIterator,OSuite::ZOEdmEndRole *,int>::`vftable;
      OSuite::ZListBase::ZListIteratorBase::ZListIteratorBase(
        (OSuite::ZListBase::ZListIteratorBase *)&v66.OSuite::IHashable,
        (OSuite::ZListBase::ZListIteratorBase *)&sName);
      v66.OSuite::IHashable::vfptr = (OSuite::IHashableVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable;
      if ( !OSuite::ZListBase::ZListIteratorBase::AtEnd((OSuite::ZListBase::ZListIteratorBase *)&v66.OSuite::IHashable) )
      {
        do
        {
          OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)v66.m_pString);
          v24 = v67;
          m_pString = v66.m_pString;
          v26 = v67 + 1;
          OSuite::TList<OSuite::ZONavigationProperty *>::Grow(
            (OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *)v66.m_pString,
            v67 + 1);
          if ( v24 >= *(_QWORD *)&m_pString->m_nHash )
            *(_QWORD *)&m_pString->m_nHash = v26;
          v27 = *(_QWORD *)(*(_QWORD *)&m_pString->m_szString[12] + 8 * v24);
          (*(void (__fastcall **)(__int64, OSuite::ZJsonObject *, _QWORD))(*(_QWORD *)v27 + 16i64))(v27, v11, eMethod);
          OSuite::ZListBase::ZListIteratorBase::Next((OSuite::ZListBase::ZListIteratorBase *)&v66.OSuite::IHashable);
        }
        while ( !OSuite::ZListBase::ZListIteratorBase::AtEnd((OSuite::ZListBase::ZListIteratorBase *)&v66.OSuite::IHashable) );
        v4 = pJson;
      }
      v66.OSuite::IHashable::vfptr = (OSuite::IHashableVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable;
      v66.OSuite::ZObject::vfptr = (OSuite::ZObjectVtbl *)&OSuite::TConstIterator<OSuite::TList<OSuite::ZOEdmEndRole *>::ZIterator,OSuite::ZOEdmEndRole *,int>::`vftable;
      v28 = (OSuite::ZJsonValue *)OSuite::ZObject::operator new(0x60ui64);
      if ( !v28 )
        goto LABEL_59;
      v28->m_literal.m_pString = 0i64;
      v28->m_array.m_pList = 0i64;
      v28->m_object = 0i64;
      OSuite::ZJsonValue::ZJsonValue(v28, v11);
      goto LABEL_58;
    }
    sValue.m_pString = 0i64;
    OSuite::ZString::ZString(&sValue, &this->m_Value);
    m_Type = this->m_Type;
    v31 = 1;
    if ( m_Type <= EDM_DOUBLE )
    {
      if ( m_Type != EDM_DOUBLE )
      {
        v32 = m_Type - 1;
        if ( v32 )
        {
          v33 = v32 - 2;
          if ( v33 )
          {
            v34 = v33 - 1;
            if ( v34 )
            {
              v35 = v34 - 1;
              if ( !v35 )
              {
                OSuite::ZString::ZString(&v54, "datetimeoffset");
                v39 = OSuite::ZString::operator+(v38, &v58, &sValue);
                v40 = OSuite::ZString::operator+(v39, &v57, "");
                OSuite::ZString::operator=(&sValue, v40);
                OSuite::ZString::~ZString(&v57);
                OSuite::ZString::~ZString(&v58);
                p_result = &v54;
                goto LABEL_55;
              }
              if ( v35 == 1 )
              {
                v36 = OSuite::ZString::operator+(&sValue, &result, "m");
                OSuite::ZString::operator=(&sValue, v36);
                p_result = &result;
LABEL_55:
                OSuite::ZString::~ZString(p_result);
                goto LABEL_56;
              }
              goto LABEL_53;
            }
            OSuite::ZDateTime::Parse((OSuite::ZDateTime *)&sName, &sValue);
            v68.m_Chars.m_pList = 0i64;
            OSuite::ZStringBuilder::ZStringBuilder(&v68, 0x28ui64);
            v41 = OSuite::ZDateTime::ToTime((OSuite::ZDateTime *)&sName);
            OSuite::ZStringBuilder::AppendFormat(&v68, "\\/Date(%Ld)\\/", 1000 * v41);
            v42 = OSuite::ZStringBuilder::ToString(&v68, &v62);
            OSuite::ZString::operator=(&sValue, v42);
            OSuite::ZString::~ZString(&v62);
            OSuite::ZUtf8Buffer::~ZUtf8Buffer(&v68);
            OSuite::ZJsonSerializer::~ZJsonSerializer((OSuite::ZDateTime *)&sName);
LABEL_56:
            v50 = (OSuite::ZJsonValue *)OSuite::ZObject::operator new(0x60ui64);
            if ( !v50 )
            {
LABEL_59:
              OSuite::ZJsonObject::Add(v4, &this->m_Name, v3);
LABEL_60:
              OSuite::ZString::~ZString(&sValue);
              return;
            }
            v50->m_literal.m_pString = 0i64;
            v50->m_array.m_pList = 0i64;
            v50->m_object = 0i64;
            OSuite::ZJsonValue::ZJsonValue(v50, &sValue, v31);
LABEL_58:
            v3 = v29;
            goto LABEL_59;
          }
        }
      }
LABEL_52:
      OSuite::ZString::operator=(&sValue, &sValue);
      goto LABEL_56;
    }
    if ( m_Type == EDM_GUID )
    {
      OSuite::ZString::ZString(&v66, "guid");
      v48 = OSuite::ZString::operator+(v47, &v60, &sValue);
      v49 = OSuite::ZString::operator+(v48, &v63, "");
      OSuite::ZString::operator=(&sValue, v49);
      OSuite::ZString::~ZString(&v63);
      OSuite::ZString::~ZString(&v60);
      p_result = &v66;
      goto LABEL_55;
    }
    if ( m_Type > EDM_INT32 )
    {
      if ( m_Type <= EDM_SBYTE )
        goto LABEL_52;
      switch ( m_Type )
      {
        case EDM_SINGLE:
          v46 = OSuite::ZString::operator+(&sValue, &v61, "f");
          OSuite::ZString::operator=(&sValue, v46);
          p_result = &v61;
          goto LABEL_55;
        case EDM_STRING:
          goto LABEL_52;
        case EDM_TIME:
          OSuite::ZString::ZString(&v59, "time");
          v44 = OSuite::ZString::operator+(v43, &v55, &sValue);
          v45 = OSuite::ZString::operator+(v44, &v56, "");
          OSuite::ZString::operator=(&sValue, v45);
          OSuite::ZString::~ZString(&v56);
          OSuite::ZString::~ZString(&v55);
          p_result = &v59;
          goto LABEL_55;
      }
    }
LABEL_53:
    v31 = 0;
    goto LABEL_56;
  }
  v6 = (OSuite::ZJsonValue *)OSuite::ZObject::operator new(0x60ui64);
  v7 = v6;
  if ( v6 )
  {
    v6->m_literal.m_pString = 0i64;
    v6->m_array.m_pList = 0i64;
    v6->m_object = 0i64;
    OSuite::ZString::ZString(&sValue, "null");
    LOBYTE(v3) = 1;
    OSuite::ZJsonValue::ZJsonValue(v7, &sValue, 0);
  }
  else
  {
    v8 = 0i64;
  }
  OSuite::ZJsonObject::Add(v4, &this->m_Name, v8);
  if ( ((unsigned __int8)v3 & 1) != 0 )
    goto LABEL_60;
}

