// File Line: 35
// RVA: 0xEC5348
void __fastcall OSuite::ZOProperty::ZOProperty(OSuite::ZOProperty *this, OSuite::ZOEdmProperty *const pEdmProperty, OSuite::ZString *baseUrl)
{
  OSuite::ZOEdmProperty *v3; // rbx
  OSuite::ZOProperty *v4; // rdi
  OSuite::EdmType v5; // eax
  OSuite::ZObject *v6; // rdx
  OSuite::ZOProperty **v7; // rax

  v3 = pEdmProperty;
  v4 = this;
  OSuite::ZAtomBase::ZAtomBase((OSuite::ZAtomBase *)&this->vfptr, baseUrl);
  v4->m_bNull = 0;
  v4->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZOProperty::`vftable';
  v5 = v3->m_Type;
  v4->m_pEdmProperty = v3;
  v4->m_Type = v5;
  OSuite::ZString::ZString(&v4->m_Name, &v3->m_Name);
  OSuite::ZString::ZString(&v4->m_Value);
  OSuite::ZRedBlackTreeBase::ZElementBase::ZElementBase((OSuite::ZObject *)&v4->m_SubProperties.vfptr, v6);
  v4->m_SubProperties.m_pList = 0i64;
  v4->m_SubProperties.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuitePrivate::ZPlayerConsumableData::ZRequest *>::`vftable'{for `OSuite::ZListBase'};
  v4->m_SubProperties.vfptr = (OSuite::IHashableVtbl *)&OSuite::TList<OSuite::ZJsonObject *>::`vftable'{for `OSuite::IHashable'};
  v7 = (OSuite::ZOProperty **)OSuite::ZObject::malloc((OSuite::ZObject *)&v4->m_SubProperties.vfptr, 0x80ui64, 0i64);
  v4->m_SubProperties.m_nTop = 0i64;
  v4->m_SubProperties.m_nSize = 16i64;
  v4->m_SubProperties.m_pList = v7;
}

// File Line: 44
// RVA: 0xEC5288
void __fastcall OSuite::ZOProperty::ZOProperty(OSuite::ZOProperty *this, OSuite::ZString *name, OSuite::ZString *baseUrl)
{
  OSuite::ZString *v3; // rbx
  OSuite::ZOProperty *v4; // rsi
  OSuite::ZObject *v5; // rdx
  OSuite::ZOProperty **v6; // rax

  v3 = name;
  v4 = this;
  OSuite::ZAtomBase::ZAtomBase((OSuite::ZAtomBase *)&this->vfptr, baseUrl);
  v4->m_pEdmProperty = 0i64;
  v4->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZOProperty::`vftable';
  v4->m_bNull = 0;
  OSuite::ZString::ZString(&v4->m_Name, v3);
  OSuite::ZString::ZString(&v4->m_Value);
  OSuite::ZRedBlackTreeBase::ZElementBase::ZElementBase((OSuite::ZObject *)&v4->m_SubProperties.vfptr, v5);
  v4->m_SubProperties.m_pList = 0i64;
  v4->m_SubProperties.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuitePrivate::ZPlayerConsumableData::ZRequest *>::`vftable'{for `OSuite::ZListBase'};
  v4->m_SubProperties.vfptr = (OSuite::IHashableVtbl *)&OSuite::TList<OSuite::ZJsonObject *>::`vftable'{for `OSuite::IHashable'};
  v6 = (OSuite::ZOProperty **)OSuite::ZObject::malloc((OSuite::ZObject *)&v4->m_SubProperties.vfptr, 0x80ui64, 0i64);
  v4->m_SubProperties.m_nTop = 0i64;
  v4->m_SubProperties.m_pList = v6;
  v4->m_SubProperties.m_nSize = 16i64;
  v4->m_Type = OSuite::deduceEdmTypeFromName(&v4->m_Name);
}

// File Line: 51
// RVA: 0xEC53F8
void __fastcall OSuite::ZOProperty::~ZOProperty(OSuite::ZOProperty *this)
{
  OSuite::ZObject *v1; // rdi
  OSuite::ZOProperty *v2; // r14
  unsigned __int64 v3; // rsi
  OSuite::ZListBase *v4; // rbx
  unsigned __int64 v5; // rbp
  void (__fastcall ***v6)(_QWORD, signed __int64); // rcx
  OSuite::ZObjectVtbl *v7; // rdx
  OSuite::ZObjectVtbl *v8; // rax
  OSuite::ZObjectVtbl *v9; // rdx
  OSuite::ZListBase::ZListIteratorBase v10; // [rsp+20h] [rbp-38h]

  v10.m_pListBase = 0i64;
  v1 = (OSuite::ZObject *)&this->m_SubProperties.vfptr;
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZOProperty::`vftable';
  v2 = this;
  OSuite::ZListBase::ZListIteratorBase::ZListIteratorBase(&v10, (OSuite::ZListBase *)&this->m_SubProperties.vfptr);
  v10.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable';
  while ( !OSuite::ZListBase::ZListIteratorBase::AtEnd(&v10) )
  {
    OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)v10.m_pListBase);
    v3 = v10.m_nIndex;
    v4 = v10.m_pListBase;
    v5 = v10.m_nIndex + 1;
    OSuite::TList<OSuite::ZONavigationProperty *>::Grow(
      (OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *)v10.m_pListBase,
      v10.m_nIndex + 1);
    if ( v3 >= v4->m_nTop )
      v4->m_nTop = v5;
    v6 = *(void (__fastcall ****)(_QWORD, signed __int64))(v4[1].m_nSize + 8 * v3);
    if ( v6 )
      (**v6)(v6, 1i64);
    OSuite::ZListBase::ZListIteratorBase::Next(&v10);
  }
  v7 = v1[4].vfptr;
  v10.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable';
  OSuite::ZObject::free(v1, v7);
  v8 = (OSuite::ZObjectVtbl *)OSuite::ZObject::malloc(v1, 0x80ui64, 0i64);
  v1[2].vfptr = 0i64;
  v1[1].vfptr = (OSuite::ZObjectVtbl *)16;
  v1[4].vfptr = v8;
  v9 = v1[4].vfptr;
  v1->vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuitePrivate::ZPlayerConsumableData::ZRequest *>::`vftable'{for `OSuite::ZListBase'};
  v1[3].vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonObject *>::`vftable'{for `OSuite::IHashable'};
  OSuite::ZObject::free(v1, v9);
  OSuite::ZString::~ZString(&v2->m_Value);
  OSuite::ZString::~ZString(&v2->m_Name);
  OSuite::ZAtomBase::~ZAtomBase((OSuite::ZAtomBase *)&v2->vfptr);
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
  OSuite::EdmType v1; // edx
  OSuite::ZOProperty *v2; // rbx
  int v3; // edx
  int v4; // edx
  int v5; // edx
  int v6; // edx
  OSuite::ZDateTime *v7; // rax
  OSuite::ZString *v8; // rax
  OSuite::ZString *v9; // rax
  OSuite::ZDateTime *v10; // rcx
  OSuite::ZDateTime *v11; // rax
  OSuite::ZString *v12; // rax
  OSuite::ZString *v13; // rcx
  int v14; // edx
  int v15; // edx
  int v16; // edx
  int v17; // edx
  unsigned __int64 v18; // rdi
  OSuite::ZListBase *v19; // rbx
  unsigned __int64 v20; // rsi
  OSuite::ZDateTime *v21; // rax
  OSuite::ZString *v22; // rax
  OSuite::ZString *v23; // rax
  OSuite::ZString v24; // [rsp+20h] [rbp-D8h]
  OSuite::ZUuid v25; // [rsp+38h] [rbp-C0h]
  OSuite::ZString v26; // [rsp+58h] [rbp-A0h]
  OSuite::ZString v27; // [rsp+70h] [rbp-88h]
  OSuite::ZString that; // [rsp+98h] [rbp-60h]
  OSuite::ZString v29; // [rsp+B0h] [rbp-48h]
  OSuite::ZString v30; // [rsp+C8h] [rbp-30h]
  OSuite::ZDateTime v31; // [rsp+E0h] [rbp-18h]
  OSuite::ZString v32; // [rsp+F8h] [rbp+0h]
  OSuite::ZDateTime result; // [rsp+110h] [rbp+18h]
  OSuite::ZDateTime v34; // [rsp+128h] [rbp+30h]
  OSuite::ZString v35; // [rsp+140h] [rbp+48h]
  OSuite::ZString v36; // [rsp+158h] [rbp+60h]
  OSuite::ZString v37; // [rsp+170h] [rbp+78h]
  OSuite::ZListBase::ZListIteratorBase v38; // [rsp+188h] [rbp+90h]

  v1 = this->m_Type;
  v2 = this;
  if ( (signed int)v1 <= 7 )
  {
    if ( (signed int)v1 < 6 )
    {
      if ( v1 == EDM_NULL )
        return;
      v3 = v1 - 1;
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
              OSuite::ZString::operator=(&v2->m_Value, v12);
              OSuite::ZString::~ZString(&v37);
              v10 = &v31;
              goto LABEL_11;
            }
            if ( v6 == 1 )
            {
              v7 = OSuite::ZDateTime::CurrentDateTime(&result);
              v8 = OSuite::ZDateTime::ISO8601Date(v7, &v35);
              v9 = OSuite::ZString::operator+(v8, &v30, "Z");
              OSuite::ZString::operator=(&v2->m_Value, v9);
              OSuite::ZString::~ZString(&v30);
              OSuite::ZString::~ZString(&v35);
              v10 = &result;
LABEL_11:
              OSuite::ZJsonSerializer::~ZJsonSerializer(v10);
              return;
            }
LABEL_20:
            OSuite::ZString::ZString(&v26, "0");
            OSuite::ZString::operator=(&v2->m_Value, &v26);
            v13 = &v26;
            goto LABEL_31;
          }
          OSuite::ZString::ZString(&that, "00");
          OSuite::ZString::operator=(&v2->m_Value, &that);
          v13 = &that;
        }
        else
        {
          OSuite::ZString::ZString(&v27, "false");
          OSuite::ZString::operator=(&v2->m_Value, &v27);
          v13 = &v27;
        }
      }
      else
      {
        OSuite::ZString::ZString(&v24, &customWorldMapCaption);
        OSuite::ZString::operator=(&v2->m_Value, &v24);
        v13 = &v24;
      }
LABEL_31:
      OSuite::ZString::~ZString(v13);
      return;
    }
LABEL_29:
    OSuite::ZString::ZString(&v29, "0.0");
    OSuite::ZString::operator=(&v2->m_Value, &v29);
    v13 = &v29;
    goto LABEL_31;
  }
  v14 = v1 - 8;
  if ( !v14 )
  {
    v25.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZUuid::`vftable'{for `OSuite::ZObject'};
    v25.vfptr = (OSuite::IHashableVtbl *)&OSuite::ZUuid::`vftable'{for `OSuite::IHashable'};
    OSuite::psock::uuid::create(v25.m_anUuid, 1);
    v23 = OSuite::ZUuid::ToString(&v25, &v36);
    OSuite::ZString::operator=(&v2->m_Value, v23);
    v13 = &v36;
    goto LABEL_31;
  }
  v15 = v14 - 5;
  if ( !v15 )
    goto LABEL_29;
  v16 = v15 - 1;
  if ( !v16 )
  {
    OSuite::ZString::ZString((OSuite::ZString *)((char *)&v27 + 16), &customWorldMapCaption);
    OSuite::ZString::operator=(&v2->m_Value, (OSuite::ZString *)((char *)&v27 + 16));
    v13 = (OSuite::ZString *)((char *)&v27 + 16);
    goto LABEL_31;
  }
  v17 = v16 - 1;
  if ( !v17 )
  {
    v21 = OSuite::ZDateTime::CurrentDateTime(&v34);
    v22 = OSuite::ZDateTime::ISO8601Time(v21, &v32);
    OSuite::ZString::operator=(&v2->m_Value, v22);
    OSuite::ZString::~ZString(&v32);
    v10 = &v34;
    goto LABEL_11;
  }
  if ( v17 != 1 )
    goto LABEL_20;
  v38.m_pListBase = 0i64;
  OSuite::ZListBase::ZListIteratorBase::ZListIteratorBase(&v38, (OSuite::ZListBase *)&this->m_SubProperties.vfptr);
  v38.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable';
  while ( !OSuite::ZListBase::ZListIteratorBase::AtEnd(&v38) )
  {
    OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)v38.m_pListBase);
    v18 = v38.m_nIndex;
    v19 = v38.m_pListBase;
    v20 = v38.m_nIndex + 1;
    OSuite::TList<OSuite::ZONavigationProperty *>::Grow(
      (OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *)v38.m_pListBase,
      v38.m_nIndex + 1);
    if ( v18 >= v19->m_nTop )
      v19->m_nTop = v20;
    OSuite::ZOProperty::ResetToDefault(*(OSuite::ZOProperty **)(v19[1].m_nSize + 8 * v18));
    OSuite::ZListBase::ZListIteratorBase::Next(&v38);
  }
}

// File Line: 140
// RVA: 0xEC5784
char __fastcall OSuite::ZOProperty::GetValue(OSuite::ZOProperty *this, OSuite::ZString *outValue)
{
  OSuite::ZString *v2; // rdi
  OSuite::ZOProperty *v3; // rbx
  OSuite::ZString *v4; // rsi

  v2 = &this->m_Value;
  v3 = this;
  v4 = outValue;
  if ( !OSuite::ZString::operator bool(&this->m_Value) || v3->m_bNull || v3->m_Type != 14 )
    return 0;
  OSuite::ZString::operator=(v4, v2);
  return 1;
}

// File Line: 196
// RVA: 0xEC5710
char __fastcall OSuite::ZOProperty::GetValue(OSuite::ZOProperty *this, int *outValue)
{
  OSuite::ZString *v2; // rdi
  OSuite::ZOProperty *v3; // rbx
  int *v4; // rsi

  v2 = &this->m_Value;
  v3 = this;
  v4 = outValue;
  if ( !OSuite::ZString::operator bool(&this->m_Value)
    || v3->m_bNull
    || v3->m_Type != 10
    || (unsigned __int64)(OSuite::ZString::ToInt(v2) + 0x80000000i64) > 0xFFFFFFFF )
  {
    return 0;
  }
  *v4 = OSuite::ZString::ToInt(v2);
  return 1;
}

// File Line: 215
// RVA: 0xEC57E0
char __fastcall OSuite::ZOProperty::GetValue(OSuite::ZOProperty *this, __int64 *outValue)
{
  OSuite::ZString *v2; // rdi
  OSuite::ZOProperty *v3; // rbx
  __int64 *v4; // rsi

  v2 = &this->m_Value;
  v3 = this;
  v4 = outValue;
  if ( !OSuite::ZString::operator bool(&this->m_Value) || v3->m_bNull || v3->m_Type != 11 )
    return 0;
  *v4 = OSuite::ZString::ToInt(v2);
  return 1;
}

// File Line: 227
// RVA: 0xEC583C
char __fastcall OSuite::ZOProperty::GetValue(OSuite::ZOProperty *this, bool *outValue)
{
  OSuite::ZString *v2; // rdi
  OSuite::ZOProperty *v3; // rbx
  bool *v4; // rsi

  v2 = &this->m_Value;
  v3 = this;
  v4 = outValue;
  if ( !OSuite::ZString::operator bool(&this->m_Value) || v3->m_bNull || v3->m_Type != 2 )
    return 0;
  *v4 = OSuite::ZString::EqualsCaseInsensitive(v2, "true");
  return 1;
}

// File Line: 282
// RVA: 0xEC63B8
char __fastcall OSuite::ZOProperty::SetValue(OSuite::ZOProperty *this, const char *inValue)
{
  OSuite::ZOProperty *v2; // rbx
  OSuite::ZString that; // [rsp+20h] [rbp-28h]

  v2 = this;
  if ( !inValue || this->m_Type != 14 )
    return 0;
  OSuite::ZString::ZString(&that, inValue);
  OSuite::ZString::operator=(&v2->m_Value, &that);
  OSuite::ZString::~ZString(&that);
  v2->m_bNull = 0;
  return 1;
}

// File Line: 295
// RVA: 0xEC62C0
char __fastcall OSuite::ZOProperty::SetValue(OSuite::ZOProperty *this, OSuite::ZString *inValue)
{
  OSuite::ZOProperty *v2; // rbx
  OSuite::ZString *v3; // rdi

  v2 = this;
  v3 = inValue;
  if ( !OSuite::ZString::operator bool(inValue) || v2->m_Type != 14 )
    return 0;
  OSuite::ZString::operator=(&v2->m_Value, v3);
  v2->m_bNull = 0;
  return 1;
}

// File Line: 308
// RVA: 0xEC6204
char __fastcall OSuite::ZOProperty::SetValue(OSuite::ZOProperty *this, OSuite::ZDateTime *inValue)
{
  OSuite::EdmType v2; // eax
  OSuite::ZOProperty *v3; // rbx
  OSuite::ZString *v4; // rax
  OSuite::ZString *v5; // rcx
  OSuite::ZString *v7; // rax
  OSuite::ZString *v8; // rax
  OSuite::ZString *v9; // rax
  OSuite::ZString result; // [rsp+20h] [rbp-38h]
  OSuite::ZString v11; // [rsp+38h] [rbp-20h]

  v2 = this->m_Type;
  v3 = this;
  switch ( v2 )
  {
    case 4:
      v4 = OSuite::ZDateTime::ISO8601Date(inValue, &result);
      OSuite::ZString::operator=(&v3->m_Value, v4);
      v5 = &result;
LABEL_3:
      OSuite::ZString::~ZString(v5);
      v3->m_bNull = 0;
      return 1;
    case 5:
      v7 = OSuite::ZDateTime::ISO8601Date(inValue, &v11);
      v8 = OSuite::ZString::operator+(v7, &result, "Z");
      OSuite::ZString::operator=(&v3->m_Value, v8);
      OSuite::ZString::~ZString(&result);
LABEL_6:
      v5 = &v11;
      goto LABEL_3;
    case 15:
      v9 = OSuite::ZDateTime::ISO8601Time(inValue, &v11);
      OSuite::ZString::operator=(&v3->m_Value, v9);
      goto LABEL_6;
  }
  return 0;
}

// File Line: 349
// RVA: 0xEC630C
char __fastcall OSuite::ZOProperty::SetValue(OSuite::ZOProperty *this, int inValue)
{
  unsigned int v2; // edi
  OSuite::ZOProperty *v3; // rbx
  OSuite::ZString *v4; // rax
  OSuite::ZString result; // [rsp+20h] [rbp-58h]
  OSuite::ZStringBuilder v7; // [rsp+38h] [rbp-40h]

  v2 = inValue;
  v3 = this;
  if ( this->m_Type != 10 )
    return 0;
  v7.m_Chars.m_pList = 0i64;
  OSuite::ZStringBuilder::ZStringBuilder(&v7, 0x10ui64);
  OSuite::ZStringBuilder::AppendFormat(&v7, "%d", v2);
  v4 = OSuite::ZStringBuilder::ToString(&v7, &result);
  OSuite::ZString::operator=(&v3->m_Value, v4);
  OSuite::ZString::~ZString(&result);
  v3->m_bNull = 0;
  OSuite::ZUtf8Buffer::~ZUtf8Buffer(&v7);
  return 1;
}

// File Line: 436
// RVA: 0xEC55E4
unsigned __int64 __fastcall OSuite::ZOProperty::GetBinarySize(OSuite::ZOProperty *this)
{
  unsigned __int64 result; // rax

  if ( this->m_bNull || this->m_Type != 1 )
    result = 0i64;
  else
    result = OSuite::ZMimeEntity::Base64DecodedLength(&this->m_Value);
  return result;
}

// File Line: 447
// RVA: 0xEC5578
bool __fastcall OSuite::ZOProperty::GetBinary(OSuite::ZOProperty *this, char *buffer, unsigned __int64 bufferLength)
{
  bool v3; // bl
  char *v4; // rbp
  OSuite::ZOProperty *v5; // rdi

  v3 = 0;
  v4 = buffer;
  v5 = this;
  if ( buffer
    && bufferLength
    && !this->m_bNull
    && this->m_Type == 1
    && OSuite::ZOProperty::GetBinarySize(this) == bufferLength )
  {
    v3 = OSuite::ZMimeEntity::Base64Decode(v4, &v5->m_Value);
  }
  return v3;
}

// File Line: 476
// RVA: 0xEC5614
OSuite::ZOProperty *__fastcall OSuite::ZOProperty::GetSubProperty(OSuite::ZOProperty *this, const char *subPropertyName)
{
  OSuite::ZOProperty *v2; // rbx
  unsigned __int64 v3; // rsi
  OSuite::ZListBase *v4; // rbx
  unsigned __int64 v5; // rdi
  __int64 v6; // rbx
  OSuite::ZListBase::ZListIteratorBase v8; // [rsp+20h] [rbp-40h]
  OSuite::ZString that; // [rsp+38h] [rbp-28h]

  v2 = this;
  if ( !subPropertyName )
    return 0i64;
  that.m_pString = 0i64;
  OSuite::ZString::ZString(&that, subPropertyName);
  v8.m_pListBase = 0i64;
  OSuite::ZListBase::ZListIteratorBase::ZListIteratorBase(&v8, (OSuite::ZListBase *)&v2->m_SubProperties.vfptr);
  v8.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable';
  while ( 1 )
  {
    if ( OSuite::ZListBase::ZListIteratorBase::AtEnd(&v8) )
    {
      OSuite::ZString::~ZString(&that);
      return 0i64;
    }
    OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)v8.m_pListBase);
    v3 = v8.m_nIndex;
    v4 = v8.m_pListBase;
    v5 = v8.m_nIndex + 1;
    OSuite::TList<OSuite::ZONavigationProperty *>::Grow(
      (OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *)v8.m_pListBase,
      v8.m_nIndex + 1);
    if ( v3 >= v4->m_nTop )
      v4->m_nTop = v5;
    v6 = *(_QWORD *)(v4[1].m_nSize + 8 * v3);
    if ( OSuite::ZString::operator==((OSuite::ZString *)(v6 + 152), &that) )
      break;
    OSuite::ZListBase::ZListIteratorBase::Next(&v8);
  }
  v8.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable';
  OSuite::ZString::~ZString(&that);
  return (OSuite::ZOProperty *)v6;
}

// File Line: 527
// RVA: 0xEC5938
void __fastcall OSuite::ZOProperty::ParseJsonValue(OSuite::ZOProperty *this, OSuite::ZString *__formal, OSuite::ZJsonValue *pJson)
{
  OSuite::ZJsonValue *v3; // r14
  OSuite::ZOProperty *v4; // rsi
  OSuite::ZJsonValue *v5; // r13
  OSuite::ZJsonValue *v6; // rax
  OSuite::ZOnlineSuite *v7; // rax
  OSuite::ZWebServiceClient *v8; // rbx
  OSuite::ZOMetadata *v9; // rax
  OSuite::ZOEdmComplexType *v10; // rax
  OSuite::TMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *> *v11; // rcx
  OSuite::ZOEdmComplexType *v12; // rbx
  void *(__fastcall *v13)(OSuite::IHashable *, unsigned int); // r12
  OSuite::ZString *v14; // r15
  OSuite::ZOProperty *v15; // rax
  OSuite::ZOProperty *v16; // rbx
  OSuite::ZOEdmProperty *v17; // rax
  OSuite::ZOProperty *v18; // rax
  OSuite::ZOProperty *v19; // r14
  OSuite::ZString *v20; // rcx
  OSuite::ZString *v21; // rbx
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
  int v34; // eax
  __int64 v35; // rax
  OSuite::ZString *v36; // rax
  OSuite::ZError *v37; // rax
  OSuite::ZOEdmComplexType *v38; // [rsp+20h] [rbp-E0h]
  OSuite::ZString sName; // [rsp+28h] [rbp-D8h]
  OSuite::ZString result; // [rsp+40h] [rbp-C0h]
  OSuite::ZString v41; // [rsp+58h] [rbp-A8h]
  OSuite::ZString v42; // [rsp+70h] [rbp-90h]
  OSuite::ZString v43; // [rsp+88h] [rbp-78h]
  OSuite::ZString v44; // [rsp+A0h] [rbp-60h]
  OSuite::ZString fullyQualifiedName; // [rsp+B8h] [rbp-48h]
  OSuite::ZString v46; // [rsp+D0h] [rbp-30h]
  OSuite::ZUrl url; // [rsp+F0h] [rbp-10h]

  v3 = pJson;
  v4 = this;
  if ( pJson->m_Type != 1 )
  {
    v21 = &this->m_Value;
    OSuite::ZString::operator=(&this->m_Value, &pJson->m_literal);
    v22 = OSuite::ZString::operator==(v21, "null");
    v4->m_bNull = v22;
    if ( v22 )
      return;
    switch ( v4->m_Type )
    {
      case 4:
        if ( OSuite::ZString::StartsWith(v21, "\\/Date") == 1 )
        {
          v33 = OSuite::ZString::IndexOf(v21, 40, 0i64);
          v34 = OSuite::ZString::LastIndexOf(v21, 41);
          if ( v33 > 0 && v34 > 0 && v34 > v33 )
          {
            fullyQualifiedName.m_pString = 0i64;
            OSuite::ZString::Slice(v21, &fullyQualifiedName, v33 + 1, v34 - v33 - 1);
            v35 = OSuite::ZString::ToInt(&fullyQualifiedName);
            OSuite::ZDateTime::ZDateTime(
              (OSuite::ZDateTime *)&v46,
              ((unsigned __int64)((unsigned __int128)(v35 * (signed __int128)2361183241434822607i64) >> 64) >> 63)
            + ((signed __int64)((unsigned __int128)(v35 * (signed __int128)2361183241434822607i64) >> 64) >> 7));
            v36 = OSuite::ZDateTime::ISO8601Date((OSuite::ZDateTime *)&v46, &v44);
            OSuite::ZString::operator=(v21, v36);
            OSuite::ZString::~ZString(&v44);
            OSuite::ZJsonSerializer::~ZJsonSerializer((OSuite::ZDateTime *)&v46);
            goto LABEL_17;
          }
        }
        break;
      case 5:
        if ( OSuite::ZString::StartsWith(v21, "datetimeoffset'") == 1 )
        {
          v31 = OSuite::ZString::Count(v21);
          v32 = OSuite::ZString::Slice(v21, &v43, 0xFui64, v31 - 16);
          OSuite::ZString::operator=(v21, v32);
          v20 = &v43;
          goto LABEL_34;
        }
        break;
      case 6:
        if ( OSuite::ZString::EndsWith(v21, "M") || OSuite::ZString::EndsWith(v21, "m") )
        {
          v29 = OSuite::ZString::Count(v21);
          v30 = OSuite::ZString::Slice(v21, &v41, 0i64, v29 - 1);
          OSuite::ZString::operator=(v21, v30);
          v20 = &v41;
          goto LABEL_34;
        }
        break;
      case 8:
        if ( OSuite::ZString::StartsWith(v21, "guid'") == 1 )
        {
          v27 = OSuite::ZString::Count(v21);
          v28 = OSuite::ZString::Slice(v21, &v42, 5ui64, v27 - 6);
          OSuite::ZString::operator=(v21, v28);
          v20 = &v42;
          goto LABEL_34;
        }
        break;
      case 0xD:
        if ( OSuite::ZString::EndsWith(v21, "f") )
        {
          v25 = OSuite::ZString::Count(v21);
          v26 = OSuite::ZString::Slice(v21, &result, 0i64, v25 - 1);
          OSuite::ZString::operator=(v21, v26);
          v20 = &result;
          goto LABEL_34;
        }
        break;
      case 0xF:
        if ( OSuite::ZString::StartsWith(v21, "time'") == 1 )
        {
          v23 = OSuite::ZString::Count(v21);
          v24 = OSuite::ZString::Slice(v21, &sName, 5ui64, v23 - 6);
          OSuite::ZString::operator=(v21, v24);
          v20 = &sName;
          goto LABEL_34;
        }
        break;
      default:
        return;
    }
    goto LABEL_42;
  }
  OSuite::ZString::ZString(&sName, "__metadata");
  v5 = OSuite::ZJsonObject::Value(v3->m_object, &sName);
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
  OSuite::ZUrl::ZUrl(&url, &v4->m_sBaseURL);
  v7 = OSuite::ZOnlineSuite::Instance();
  v8 = OSuite::ZOnlineSuite::GetForUrl(v7, &url);
  OSuite::ZUrl::~ZUrl(&url);
  v9 = OSuite::ZWebServiceClient::Metadata(v8);
  v10 = OSuite::ZOMetadata::ComplexType(v9, &fullyQualifiedName);
  v11 = (OSuite::TMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *> *)&v3->m_object->m_Pairs;
  v12 = v10;
  v38 = v10;
  url.vfptr = 0i64;
  url.m_sHost.vfptr = 0i64;
  url.m_sHost.vfptr = 0i64;
  url.m_urlParameters.vfptr = 0i64;
  OSuite::TMap<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>::Iterator(
    v11,
    (OSuite::TMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *>::ZIterator *)&url);
  while ( !OSuite::ZString::IsNull((OSuite::ZString *)((char *)&url.m_sProtocol + 16)) )
  {
    v13 = url.m_sHost.vfptr[4].__vecDelDtor;
    v14 = (OSuite::ZString *)&url.m_sHost.vfptr[2].ComputeHash;
    if ( (char *)v13 == (char *)v5 )
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
      v17 = OSuite::ZOEdmComplexType::Property(v38, v14);
      OSuite::ZOProperty::ZOProperty(v16, v17, &v4->m_sBaseURL);
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
      OSuite::ZOProperty::ZOProperty(v15, v14, &v4->m_sBaseURL);
    }
    v19 = v18;
LABEL_12:
    ((void (__fastcall *)(OSuite::ZOProperty *, OSuite::ZString *, void *(__fastcall *)(OSuite::IHashable *, unsigned int)))v19->vfptr[3].__vecDelDtor)(
      v19,
      v14,
      v13);
    OSuite::TList<OSuite::ZONavigationProperty *>::Grow(
      (OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *)&v4->m_SubProperties,
      v4->m_SubProperties.m_nTop + 1);
    v4->m_SubProperties.m_pList[v4->m_SubProperties.m_nTop++] = v19;
    v12 = v38;
LABEL_13:
    OSuite::TMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *>::ZIterator::Next((OSuite::TMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *>::ZIterator *)&url);
  }
  url.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TMap<OSuite::ZString,OSuite::ZJsonValue *>::ZIterator::`vftable';
  url.m_sProtocol.vfptr = (OSuite::IHashableVtbl *)&OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum  OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64>>::ZIterator::`vftable';
  url.m_sProtocol.m_pString = (OSuite::ZString::InternalString *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable';
  url.m_sHost.m_pString = (OSuite::ZString::InternalString *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable'{for `OSuite::ZObject'};
  url.m_sFakeHost.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable'{for `OSuite::IHashable'};
  if ( url.m_urlParameters.vfptr )
    (*(void (__fastcall **)(OSuite::IHashableVtbl *, signed __int64))url.m_urlParameters.vfptr->__vecDelDtor)(
      url.m_urlParameters.vfptr,
      1i64);
LABEL_17:
  v20 = &fullyQualifiedName;
LABEL_34:
  OSuite::ZString::~ZString(v20);
}

// File Line: 668
// RVA: 0xEC6408
void __fastcall OSuite::ZOProperty::ToJson(OSuite::ZOProperty *this, OSuite::ZJsonObject *pJson, OSuite::ZHttp::EMethod eMethod)
{
  OSuite::ZJsonValue *v3; // rbx
  OSuite::ZJsonObject *v4; // r13
  OSuite::ZOProperty *v5; // rdi
  OSuite::ZJsonValue *v6; // rax
  OSuite::ZJsonValue *v7; // rsi
  OSuite::ZJsonValue *v8; // rax
  OSuite::ZJsonObject *v9; // rax
  OSuite::ZJsonObject *v10; // rax
  OSuite::ZJsonObject *v11; // r12
  OSuite::ZOEdmBase *v12; // rcx
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
  OSuite::ZString::InternalString *v25; // r14
  __int64 v26; // r13
  __int64 v27; // rcx
  OSuite::ZJsonValue *v28; // rax
  OSuite::ZJsonValue *v29; // rax
  signed int v30; // ecx
  bool v31; // r14
  int v32; // ecx
  int v33; // ecx
  int v34; // ecx
  int v35; // ecx
  OSuite::ZString *v36; // rax
  OSuite::ZString *v37; // rcx
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
  OSuite::ZHttp::EMethod v51; // [rsp+20h] [rbp-E0h]
  OSuite::ZJsonObject *v52; // [rsp+28h] [rbp-D8h]
  OSuite::ZString result; // [rsp+30h] [rbp-D0h]
  OSuite::ZString v54; // [rsp+48h] [rbp-B8h]
  OSuite::ZString v55; // [rsp+60h] [rbp-A0h]
  OSuite::ZString v56; // [rsp+78h] [rbp-88h]
  OSuite::ZString v57; // [rsp+90h] [rbp-70h]
  OSuite::ZString v58; // [rsp+A8h] [rbp-58h]
  OSuite::ZString v59; // [rsp+C0h] [rbp-40h]
  OSuite::ZString v60; // [rsp+D8h] [rbp-28h]
  OSuite::ZString v61; // [rsp+F0h] [rbp-10h]
  OSuite::ZString v62; // [rsp+108h] [rbp+8h]
  OSuite::ZString v63; // [rsp+120h] [rbp+20h]
  OSuite::ZString sValue; // [rsp+138h] [rbp+38h]
  OSuite::ZString sName; // [rsp+150h] [rbp+50h]
  OSuite::ZString v66; // [rsp+168h] [rbp+68h]
  unsigned __int64 v67; // [rsp+180h] [rbp+80h]
  OSuite::ZStringBuilder v68; // [rsp+188h] [rbp+88h]

  v3 = 0i64;
  v51 = eMethod;
  v4 = pJson;
  v52 = pJson;
  v5 = this;
  if ( !this->m_bNull )
  {
    if ( this->m_Type == 16 )
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
      v12 = (OSuite::ZOEdmBase *)&v5->m_pEdmProperty->vfptr;
      sValue.m_pString = 0i64;
      if ( v12 )
      {
        v13 = 2;
        v14 = OSuite::ZOEdmBase::FullyQualifiedName(v12, &result);
      }
      else
      {
        v13 = 4;
        v14 = OSuite::ZString::operator+(&v5->m_Name, &sName, "_complex");
      }
      OSuite::ZString::ZString(&sValue, v14);
      if ( v13 & 4 )
      {
        v13 &= 0xFBu;
        OSuite::ZString::~ZString(&sName);
      }
      if ( v13 & 2 )
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
        (OSuite::ZListBase *)&v5->m_SubProperties.vfptr);
      sName.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable';
      v66.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TConstIterator<OSuite::TList<OSuite::ZOEdmEndRole *>::ZIterator,OSuite::ZOEdmEndRole *,int>::`vftable';
      OSuite::ZListBase::ZListIteratorBase::ZListIteratorBase(
        (OSuite::ZListBase::ZListIteratorBase *)&v66.vfptr,
        (OSuite::ZListBase::ZListIteratorBase *)&sName);
      v66.vfptr = (OSuite::IHashableVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable';
      if ( !OSuite::ZListBase::ZListIteratorBase::AtEnd((OSuite::ZListBase::ZListIteratorBase *)&v66.vfptr) )
      {
        do
        {
          OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)v66.m_pString);
          v24 = v67;
          v25 = v66.m_pString;
          v26 = v67 + 1;
          OSuite::TList<OSuite::ZONavigationProperty *>::Grow(
            (OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *)v66.m_pString,
            v67 + 1);
          if ( v24 >= *(_QWORD *)&v25->m_nHash )
            *(_QWORD *)&v25->m_nHash = v26;
          v27 = *(_QWORD *)(v25[1].m_nLength + 8 * v24);
          (*(void (__fastcall **)(__int64, OSuite::ZJsonObject *, _QWORD))(*(_QWORD *)v27 + 16i64))(
            v27,
            v11,
            (unsigned int)v51);
          OSuite::ZListBase::ZListIteratorBase::Next((OSuite::ZListBase::ZListIteratorBase *)&v66.vfptr);
        }
        while ( !OSuite::ZListBase::ZListIteratorBase::AtEnd((OSuite::ZListBase::ZListIteratorBase *)&v66.vfptr) );
        v4 = v52;
      }
      v66.vfptr = (OSuite::IHashableVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable';
      v66.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TConstIterator<OSuite::TList<OSuite::ZOEdmEndRole *>::ZIterator,OSuite::ZOEdmEndRole *,int>::`vftable';
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
    v30 = v5->m_Type;
    v31 = 1;
    if ( v30 <= 7 )
    {
      if ( v30 != 7 )
      {
        v32 = v30 - 1;
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
                OSuite::ZString::ZString(&v54, "datetimeoffset'");
                v39 = OSuite::ZString::operator+(v38, &v58, &sValue);
                v40 = OSuite::ZString::operator+(v39, &v57, "'");
                OSuite::ZString::operator=(&sValue, v40);
                OSuite::ZString::~ZString(&v57);
                OSuite::ZString::~ZString(&v58);
                v37 = &v54;
                goto LABEL_55;
              }
              if ( v35 == 1 )
              {
                v36 = OSuite::ZString::operator+(&sValue, &result, "m");
                OSuite::ZString::operator=(&sValue, v36);
                v37 = &result;
LABEL_55:
                OSuite::ZString::~ZString(v37);
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
              OSuite::ZJsonObject::Add(v4, &v5->m_Name, v3);
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
    if ( v30 == 8 )
    {
      OSuite::ZString::ZString(&v66, "guid'");
      v48 = OSuite::ZString::operator+(v47, &v60, &sValue);
      v49 = OSuite::ZString::operator+(v48, &v63, "'");
      OSuite::ZString::operator=(&sValue, v49);
      OSuite::ZString::~ZString(&v63);
      OSuite::ZString::~ZString(&v60);
      v37 = &v66;
      goto LABEL_55;
    }
    if ( v30 > 10 )
    {
      if ( v30 <= 12 )
        goto LABEL_52;
      switch ( v30 )
      {
        case 13:
          v46 = OSuite::ZString::operator+(&sValue, &v61, "f");
          OSuite::ZString::operator=(&sValue, v46);
          v37 = &v61;
          goto LABEL_55;
        case 14:
          goto LABEL_52;
        case 15:
          OSuite::ZString::ZString(&v59, "time'");
          v44 = OSuite::ZString::operator+(v43, &v55, &sValue);
          v45 = OSuite::ZString::operator+(v44, &v56, "'");
          OSuite::ZString::operator=(&sValue, v45);
          OSuite::ZString::~ZString(&v56);
          OSuite::ZString::~ZString(&v55);
          v37 = &v59;
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
  OSuite::ZJsonObject::Add(v4, &v5->m_Name, v8);
  if ( (unsigned __int8)v3 & 1 )
    goto LABEL_60;
}

