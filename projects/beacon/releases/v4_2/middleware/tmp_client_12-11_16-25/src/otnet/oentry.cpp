// File Line: 20
// RVA: 0x15D8AA8
__int64 dynamic_initializer_for__OSuite::ZOEntry::s_nClassId__()
{
  __int64 result; // rax

  result = OSuite::ZAtomBase::GenerateClassId();
  OSuite::ZOEntry::s_nClassId = result;
  return result;
}

// File Line: 26
// RVA: 0xEC6C5C
void __fastcall OSuite::ZOEntry::ZOEntry(OSuite::ZOEntry *this, OSuite::ZOEdmEntityType *const pEdmEntityType, OSuite::ZUrl *sFeedUrl)
{
  OSuite::ZOEdmEntityType *v3; // rbx
  OSuite::ZOEntry *v4; // rdi
  OSuite::ZObject *v5; // rdx
  OSuite::ZOProperty **v6; // rax
  OSuite::ZObject *v7; // rdx
  OSuite::ZONavigationProperty **v8; // rax

  v3 = pEdmEntityType;
  v4 = this;
  OSuite::ZAtomEntry::ZAtomEntry((OSuite::ZAtomEntry *)&this->vfptr, sFeedUrl);
  v4->m_pEdmEntityType = v3;
  v4->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZOEntry::`vftable';
  OSuite::ZRedBlackTreeBase::ZElementBase::ZElementBase((OSuite::ZObject *)&v4->m_Properties.vfptr, v5);
  v4->m_Properties.m_pList = 0i64;
  v4->m_Properties.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuitePrivate::ZPlayerConsumableData::ZRequest *>::`vftable'{for `OSuite::ZListBase'};
  v4->m_Properties.vfptr = (OSuite::IHashableVtbl *)&OSuite::TList<OSuite::ZJsonObject *>::`vftable'{for `OSuite::IHashable'};
  v6 = (OSuite::ZOProperty **)OSuite::ZObject::malloc((OSuite::ZObject *)&v4->m_Properties.vfptr, 0x80ui64, 0i64);
  v4->m_Properties.m_nTop = 0i64;
  v4->m_Properties.m_nSize = 16i64;
  v4->m_Properties.m_pList = v6;
  OSuite::ZRedBlackTreeBase::ZElementBase::ZElementBase((OSuite::ZObject *)&v4->m_NavProperties.vfptr, v7);
  v4->m_NavProperties.m_pList = 0i64;
  v4->m_NavProperties.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuitePrivate::ZPlayerConsumableData::ZRequest *>::`vftable'{for `OSuite::ZListBase'};
  v4->m_NavProperties.vfptr = (OSuite::IHashableVtbl *)&OSuite::TList<OSuite::ZJsonObject *>::`vftable'{for `OSuite::IHashable'};
  v8 = (OSuite::ZONavigationProperty **)OSuite::ZObject::malloc(
                                          (OSuite::ZObject *)&v4->m_NavProperties.vfptr,
                                          0x80ui64,
                                          0i64);
  v4->m_NavProperties.m_nTop = 0i64;
  v4->m_NavProperties.m_nSize = 16i64;
  v4->m_NavProperties.m_pList = v8;
  v4->m_bHasValidSource = 1;
}

// File Line: 35
// RVA: 0xEC6AA4
void __fastcall OSuite::ZOEntry::ZOEntry(OSuite::ZOEntry *this, OSuite::IReader *pReader, OSuite::ZUrl *sFeedUrl)
{
  OSuite::IReader *v3; // rbp
  OSuite::ZOEntry *v4; // rsi
  OSuite::ZObject *v5; // rdx
  OSuite::ZOProperty **v6; // rax
  OSuite::ZObject *v7; // rdx
  OSuite::ZONavigationProperty **v8; // rax
  OSuite::ZOnlineSuite *v9; // rax
  OSuite::ZWebServiceClient *v10; // rbx
  OSuite::ZOMetadata *v11; // rax
  bool v12; // cl
  OSuite::ZUrl url; // [rsp+20h] [rbp-208h]
  OSuite::ZUrl v14; // [rsp+F8h] [rbp-130h]
  OSuite::ZJsonDocument v15; // [rsp+1D0h] [rbp-58h]

  v3 = pReader;
  v4 = this;
  OSuite::ZAtomEntry::ZAtomEntry((OSuite::ZAtomEntry *)&this->vfptr, sFeedUrl);
  v4->m_pEdmEntityType = 0i64;
  v4->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZOEntry::`vftable';
  OSuite::ZRedBlackTreeBase::ZElementBase::ZElementBase((OSuite::ZObject *)&v4->m_Properties.vfptr, v5);
  v4->m_Properties.m_pList = 0i64;
  v4->m_Properties.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuitePrivate::ZPlayerConsumableData::ZRequest *>::`vftable'{for `OSuite::ZListBase'};
  v4->m_Properties.vfptr = (OSuite::IHashableVtbl *)&OSuite::TList<OSuite::ZJsonObject *>::`vftable'{for `OSuite::IHashable'};
  v6 = (OSuite::ZOProperty **)OSuite::ZObject::malloc((OSuite::ZObject *)&v4->m_Properties.vfptr, 0x80ui64, 0i64);
  v4->m_Properties.m_nTop = 0i64;
  v4->m_Properties.m_pList = v6;
  v4->m_Properties.m_nSize = 16i64;
  OSuite::ZRedBlackTreeBase::ZElementBase::ZElementBase((OSuite::ZObject *)&v4->m_NavProperties.vfptr, v7);
  v4->m_NavProperties.m_pList = 0i64;
  v4->m_NavProperties.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuitePrivate::ZPlayerConsumableData::ZRequest *>::`vftable'{for `OSuite::ZListBase'};
  v4->m_NavProperties.vfptr = (OSuite::IHashableVtbl *)&OSuite::TList<OSuite::ZJsonObject *>::`vftable'{for `OSuite::IHashable'};
  v8 = (OSuite::ZONavigationProperty **)OSuite::ZObject::malloc(
                                          (OSuite::ZObject *)&v4->m_NavProperties.vfptr,
                                          0x80ui64,
                                          0i64);
  v4->m_NavProperties.m_nTop = 0i64;
  v4->m_NavProperties.m_nSize = 16i64;
  v4->m_NavProperties.m_pList = v8;
  OSuite::ZUrl::ZUrl(&url, &v4->m_sFeedURL);
  v9 = OSuite::ZOnlineSuite::Instance();
  v10 = OSuite::ZOnlineSuite::GetForUrl(v9, &url);
  OSuite::ZUrl::~ZUrl(&url);
  OSuite::ZUrl::ZUrl(&v14, &v4->m_sFeedURL);
  v11 = OSuite::ZWebServiceClient::Metadata(v10);
  v4->m_pEdmEntityType = OSuite::ZOMetadata::EntityTypeForUrl(v11, &v14);
  OSuite::ZUrl::~ZUrl(&v14);
  if ( v4->m_pEdmEntityType )
  {
    v15.m_Pairs.m_pLists = 0i64;
    OSuite::ZJsonDocument::ZJsonDocument(&v15, v3);
    v12 = v15.m_bIsValid;
    v4->m_bHasValidSource = v15.m_bIsValid;
    if ( v12 )
      OSuite::ZAtomBase::ParseJson((OSuite::ZAtomBase *)&v4->vfptr, (OSuite::ZJsonObject *)&v15.vfptr);
    OSuite::ZJsonDocument::~ZJsonDocument(&v15);
  }
}

// File Line: 55
// RVA: 0xEC6D30
void __fastcall OSuite::ZOEntry::~ZOEntry(OSuite::ZOEntry *this)
{
  OSuite::ZOEntry *v1; // rbx
  OSuite::TList<OSuite::ZONavigationProperty *> *v2; // rcx
  OSuite::ZONavigationProperty **v3; // rdx
  OSuite::TList<OSuite::ZOProperty *> *v4; // rcx
  OSuite::ZOProperty **v5; // rdx

  v1 = this;
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZOEntry::`vftable';
  OSuite::ZOEntry::Reset(this);
  v2 = &v1->m_NavProperties;
  v3 = v1->m_NavProperties.m_pList;
  v2->vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuitePrivate::ZPlayerConsumableData::ZRequest *>::`vftable'{for `OSuite::ZListBase'};
  v2->vfptr = (OSuite::IHashableVtbl *)&OSuite::TList<OSuite::ZJsonObject *>::`vftable'{for `OSuite::IHashable'};
  OSuite::ZObject::free((OSuite::ZObject *)&v1->m_NavProperties.vfptr, v3);
  v4 = &v1->m_Properties;
  v5 = v1->m_Properties.m_pList;
  v4->vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuitePrivate::ZPlayerConsumableData::ZRequest *>::`vftable'{for `OSuite::ZListBase'};
  v4->vfptr = (OSuite::IHashableVtbl *)&OSuite::TList<OSuite::ZJsonObject *>::`vftable'{for `OSuite::IHashable'};
  OSuite::ZObject::free((OSuite::ZObject *)&v1->m_Properties.vfptr, v5);
  OSuite::ZAtomEntry::~ZAtomEntry((OSuite::ZAtomEntry *)&v1->vfptr);
}

// File Line: 62
// RVA: 0xEC7864
OSuite::ZOProperty *__fastcall OSuite::ZOEntry::Property(OSuite::ZOEntry *this, const char *propertyName)
{
  const char *v2; // rdi
  unsigned __int64 v3; // r14
  OSuite::ZListBase *v4; // rbx
  unsigned __int64 v5; // rsi
  unsigned __int64 v7; // rdi
  OSuite::ZListBase *v8; // rbx
  unsigned __int64 v9; // rsi
  OSuite::ZListBase::ZListIteratorBase v10; // [rsp+20h] [rbp-20h]

  v2 = propertyName;
  if ( propertyName )
  {
    v10.m_pListBase = 0i64;
    OSuite::ZListBase::ZListIteratorBase::ZListIteratorBase(&v10, (OSuite::ZListBase *)&this->m_Properties.vfptr);
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
      if ( OSuite::ZString::EqualsCaseInsensitive((OSuite::ZString *)(*(_QWORD *)(v4[1].m_nSize + 8 * v3) + 152i64), v2) )
      {
        OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)v10.m_pListBase);
        v7 = v10.m_nIndex;
        v8 = v10.m_pListBase;
        v9 = v10.m_nIndex + 1;
        OSuite::TList<OSuite::ZONavigationProperty *>::Grow(
          (OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *)v10.m_pListBase,
          v10.m_nIndex + 1);
        if ( v7 >= v8->m_nTop )
          v8->m_nTop = v9;
        return *(OSuite::ZOProperty **)(v8[1].m_nSize + 8 * v7);
      }
      OSuite::ZListBase::ZListIteratorBase::Next(&v10);
    }
  }
  return 0i64;
}

// File Line: 106
// RVA: 0xEC7838
OSuite::TList<OSuite::ZOProperty *>::ZIterator *__fastcall OSuite::ZOEntry::Properties(OSuite::ZOEntry *this, OSuite::TList<OSuite::ZOProperty *>::ZIterator *result)
{
  OSuite::TList<OSuite::ZOProperty *>::ZIterator *v2; // rbx

  v2 = result;
  OSuite::ZListBase::ZListIteratorBase::ZListIteratorBase(
    (OSuite::ZListBase::ZListIteratorBase *)&result->vfptr,
    (OSuite::ZListBase *)&this->m_Properties.vfptr);
  v2->vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable';
  return v2;
}

// File Line: 113
// RVA: 0xEC6E84
OSuite::ZOProperty *__fastcall OSuite::ZOEntry::AddProperty(OSuite::ZOEntry *this, const char *propertyName)
{
  char v2; // si
  const char *v3; // rdi
  OSuite::ZOEntry *v4; // rbp
  OSuite::EdmType v6; // ebx
  OSuite::ZOProperty *v7; // rax
  OSuite::ZOProperty *v8; // rbx
  OSuite::ZOProperty *v9; // rax
  OSuite::ZOProperty *v10; // rdi
  OSuite::ZError *v11; // rax
  OSuite::ZString name; // [rsp+20h] [rbp-28h]

  v2 = 0;
  v3 = propertyName;
  v4 = this;
  if ( !propertyName )
    return 0i64;
  OSuite::ZString::ZString(&name, propertyName);
  v6 = OSuite::deduceEdmTypeFromName(&name);
  OSuite::ZString::~ZString(&name);
  if ( v6 == EDM_NULL || OSuite::ZOEntry::Property(v4, v3) )
    return 0i64;
  v7 = (OSuite::ZOProperty *)OSuite::ZObject::operator new(0xF0ui64);
  v8 = v7;
  if ( v7 )
  {
    v7->m_sAuthorName.m_pString = 0i64;
    v7->m_sIdentifier.m_pString = 0i64;
    v7->m_sTitle.m_pString = 0i64;
    v7->m_sEditURL.m_pString = 0i64;
    v7->m_sBaseURL.m_pString = 0i64;
    v7->m_pEdmProperty = 0i64;
    v7->m_Name.m_pString = 0i64;
    v7->m_Value.m_pString = 0i64;
    v7->m_SubProperties.m_pList = 0i64;
    OSuite::ZString::ZString(&name, v3);
    v2 = 1;
    OSuite::ZOProperty::ZOProperty(v8, &name, &v4->m_sBaseURL);
    v10 = v9;
  }
  else
  {
    v10 = 0i64;
  }
  if ( v2 & 1 )
    OSuite::ZString::~ZString(&name);
  if ( !v10 )
  {
    v11 = OSuite::TSingleton<OSuite::ZError>::Object();
    OSuite::ZError::SetThreadLastError(v11, ZERROR_OUT_OF_MEMORY, 1);
    return 0i64;
  }
  OSuite::ZOProperty::ResetToDefault(v10);
  OSuite::TList<OSuite::ZONavigationProperty *>::Grow(
    (OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *)&v4->m_Properties,
    v4->m_Properties.m_nTop + 1);
  v4->m_Properties.m_pList[v4->m_Properties.m_nTop++] = v10;
  return v10;
}

// File Line: 176
// RVA: 0xEC6FE8
bool __fastcall OSuite::ZOEntry::DeleteProperty(OSuite::ZOEntry *this, const char *propertyName)
{
  OSuite::ZOEntry *v2; // rdi
  OSuite::ZOProperty *v3; // rax
  unsigned __int64 v4; // rdx
  OSuite::ZOProperty *v5; // rbx
  OSuite::ZOProperty **v6; // rax

  v2 = this;
  v3 = OSuite::ZOEntry::Property(this, propertyName);
  v4 = 0i64;
  v5 = v3;
  if ( v3 )
  {
    if ( v2->m_Properties.m_nTop > 0 )
    {
      v6 = v2->m_Properties.m_pList;
      while ( *v6 != v5 )
      {
        ++v4;
        ++v6;
        if ( v4 >= v2->m_Properties.m_nTop )
          goto LABEL_8;
      }
      v2->m_Properties.vfptr[1].__vecDelDtor((OSuite::ZObject *)&v2->m_Properties.vfptr, v4);
    }
LABEL_8:
    v5->vfptr->__vecDelDtor((OSuite::ZObject *)&v5->vfptr, 1u);
    LOBYTE(v3) = 1;
  }
  return (char)v3;
}

// File Line: 231
// RVA: 0xEC6FC4
char __fastcall OSuite::ZOEntry::ClassMatch(OSuite::ZOEntry *this, int nClassId)
{
  bool v2; // al
  char v3; // cl

  if ( OSuite::ZOEntry::s_nClassId == nClassId
    || (v2 = OSuite::ZAtomEntry::ClassMatch((OSuite::ZAtomEntry *)&this->vfptr, nClassId), v3 = 0, v2) )
  {
    v3 = 1;
  }
  return v3;
}

// File Line: 237
// RVA: 0xEC7380
void __fastcall OSuite::ZOEntry::ParseJsonValue(OSuite::ZOEntry *this, OSuite::ZString *name, OSuite::ZJsonValue *pJson)
{
  OSuite::ZString *v3; // r14
  OSuite::ZOEntry *v4; // rsi
  OSuite::ZJsonValue *v5; // rbx
  OSuite::ZONavigationProperty *v6; // rdi
  OSuite::ZJsonObject *v7; // rbx
  OSuite::ZError *v8; // rax
  OSuite::ZJsonValue *v9; // r14
  OSuite::ZJsonObject *v10; // r13
  OSuite::ZJsonValue *v11; // r15
  OSuite::ZString *v12; // r15
  unsigned __int64 v13; // rbx
  unsigned __int64 v14; // r14
  char v15; // al
  char v16; // r12
  char v17; // al
  OSuite::ZJsonValue *v18; // rbx
  OSuite::ZJsonValue *v19; // r13
  OSuite::ZOEdmNavigationProperty *v20; // r15
  OSuite::ZJsonValue *v21; // rax
  OSuite::ZUrl *v22; // rax
  OSuite::ZOnlineSuite *v23; // rax
  OSuite::ZWebServiceClient *v24; // rbx
  OSuite::ZUrl *v25; // rax
  OSuite::ZString *v26; // rax
  unsigned __int64 v27; // rax
  OSuite::ZONavigationProperty *v28; // rax
  OSuite::ZONavigationProperty *v29; // rax
  OSuite::ZOEdmProperty *v30; // r15
  OSuite::ZOProperty *v31; // rax
  OSuite::ZOProperty *v32; // rax
  OSuite::ZOProperty *v33; // rax
  OSuite::ZOProperty *v34; // r15
  OSuite::ZString v35; // [rsp+30h] [rbp-D0h]
  OSuite::ZString v36; // [rsp+48h] [rbp-B8h]
  OSuite::ZUrl result; // [rsp+60h] [rbp-A0h]
  OSuite::ZString sName; // [rsp+138h] [rbp+38h]
  OSuite::ZStringBuilder v39; // [rsp+150h] [rbp+50h]

  v3 = name;
  v4 = this;
  v5 = pJson;
  v6 = 0i64;
  if ( OSuite::ZString::operator==(name, "d") )
  {
    v7 = v5->m_object;
    if ( v7 )
    {
      OSuite::ZString::ZString(&sName, "results");
      v9 = OSuite::ZJsonObject::Value(v7, &sName);
      OSuite::ZString::~ZString(&sName);
      if ( v9 )
        v7 = v9->m_object;
      OSuite::ZAtomBase::ParseJson((OSuite::ZAtomBase *)&v4->vfptr, v7);
    }
    else
    {
      v8 = OSuite::TSingleton<OSuite::ZError>::Object();
      OSuite::ZError::SetThreadLastError(v8, ZERROR_PARSING_FAILED, 1);
    }
    return;
  }
  if ( OSuite::ZString::operator==(v3, "__metadata") )
  {
    v10 = v5->m_object;
    OSuite::ZString::ZString(&sName, "etag");
    v11 = OSuite::ZJsonObject::Value(v10, &sName);
    OSuite::ZString::~ZString(&sName);
    if ( v11 )
    {
      v12 = &v11->m_literal;
      v39.m_Chars.m_pList = 0i64;
      OSuite::ZStringBuilder::ZStringBuilder(&v39, 0x20ui64);
      v13 = 0i64;
      v14 = OSuite::ZString::Count(v12);
      if ( v14 )
      {
        do
        {
          v15 = OSuite::ZString::CharAt(v12, v13++);
          v16 = v15;
          if ( v13 >= v14 )
            v17 = 0;
          else
            v17 = OSuite::ZString::CharAt(v12, v13);
          if ( v16 != 92 || v17 != 34 )
            OSuite::ZStringBuilder::Append(&v39, v16);
        }
        while ( v13 < v14 );
      }
      v4->vfptr[6].__vecDelDtor((OSuite::ZObject *)&v4->vfptr, (unsigned int)&v4->m_ETag);
      OSuite::ZUtf8Buffer::~ZUtf8Buffer(&v39);
    }
    OSuite::ZString::ZString(&sName, "uri");
    v18 = OSuite::ZJsonObject::Value(v10, &sName);
    OSuite::ZString::~ZString(&sName);
    if ( v18 )
      OSuite::ZString::operator=(&v4->m_sEditURL, &v18->m_literal);
    return;
  }
  if ( OSuite::ZString::StartsWith(v3, "__") )
  {
    OSuite::ZOEdmBase::CleanTempData((int)v4);
    return;
  }
  if ( v5->m_Type == 1 )
  {
    OSuite::ZString::ZString(&v36, "__deferred");
    v19 = OSuite::ZJsonObject::Value(v5->m_object, &v36);
    OSuite::ZString::~ZString(&v36);
    if ( v19 )
    {
      v20 = OSuite::ZOEdmEntityType::NavigationProperty(v4->m_pEdmEntityType, v3);
      if ( v20 )
      {
        OSuite::ZString::ZString(&v35, "uri");
        v21 = OSuite::ZJsonObject::Value(v19->m_object, &v35);
        v22 = OSuite::ZUrl::Parse(&result, &v21->m_literal);
        OSuite::ZUrl::ToString(v22, (OSuite::ZString *)&v39, 0);
        OSuite::ZUrl::~ZUrl(&result);
        OSuite::ZString::~ZString(&v35);
        OSuite::ZUrl::ZUrl(&result, &v4->m_sBaseURL);
        v23 = OSuite::ZOnlineSuite::Instance();
        v24 = OSuite::ZOnlineSuite::GetForUrl(v23, &result);
        OSuite::ZUrl::~ZUrl(&result);
        sName.m_pString = 0i64;
        v25 = OSuite::ZWebServiceClient::GetBaseUrl(v24);
        v26 = OSuite::ZUrl::ToString(v25, &v35, 0);
        v27 = OSuite::ZString::Count(v26);
        OSuite::ZString::Slice((OSuite::ZString *)&v39, &sName, v27);
        OSuite::ZString::~ZString(&v35);
        v28 = (OSuite::ZONavigationProperty *)OSuite::ZObject::operator new(0xC0ui64);
        if ( v28 )
        {
          v28->m_sAuthorName.m_pString = 0i64;
          v28->m_sIdentifier.m_pString = 0i64;
          v28->m_sTitle.m_pString = 0i64;
          v28->m_sEditURL.m_pString = 0i64;
          v28->m_sBaseURL.m_pString = 0i64;
          v28->m_sName.m_pString = 0i64;
          v28->m_sHref.m_pString = 0i64;
          v28->m_pEdm = 0i64;
          OSuite::ZONavigationProperty::ZONavigationProperty(v28, v20, v3, &sName, &v4->m_sBaseURL);
          v6 = v29;
        }
        OSuite::TList<OSuite::ZONavigationProperty *>::Grow(
          (OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *)&v4->m_NavProperties,
          v4->m_NavProperties.m_nTop + 1);
        v4->m_NavProperties.m_pList[v4->m_NavProperties.m_nTop++] = v6;
        OSuite::ZString::~ZString(&sName);
        OSuite::ZString::~ZString((OSuite::ZString *)&v39);
      }
      return;
    }
  }
  v30 = OSuite::ZOEdmEntityType::Property(v4->m_pEdmEntityType, v3);
  if ( v30 )
  {
    v31 = (OSuite::ZOProperty *)OSuite::ZObject::operator new(0xF0ui64);
    if ( v31 )
    {
      v31->m_sAuthorName.m_pString = 0i64;
      v31->m_sIdentifier.m_pString = 0i64;
      v31->m_sTitle.m_pString = 0i64;
      v31->m_sEditURL.m_pString = 0i64;
      v31->m_sBaseURL.m_pString = 0i64;
      v31->m_pEdmProperty = 0i64;
      v31->m_Name.m_pString = 0i64;
      v31->m_Value.m_pString = 0i64;
      v31->m_SubProperties.m_pList = 0i64;
      OSuite::ZOProperty::ZOProperty(v31, v30, &v4->m_sBaseURL);
LABEL_32:
      v34 = v32;
      goto LABEL_34;
    }
  }
  else
  {
    v33 = (OSuite::ZOProperty *)OSuite::ZObject::operator new(0xF0ui64);
    if ( v33 )
    {
      v33->m_sAuthorName.m_pString = 0i64;
      v33->m_sIdentifier.m_pString = 0i64;
      v33->m_sTitle.m_pString = 0i64;
      v33->m_sEditURL.m_pString = 0i64;
      v33->m_sBaseURL.m_pString = 0i64;
      v33->m_pEdmProperty = 0i64;
      v33->m_Name.m_pString = 0i64;
      v33->m_Value.m_pString = 0i64;
      v33->m_SubProperties.m_pList = 0i64;
      OSuite::ZOProperty::ZOProperty(v33, v3, &v4->m_sBaseURL);
      goto LABEL_32;
    }
  }
  v34 = 0i64;
LABEL_34:
  if ( v34 )
  {
    OSuite::ZOProperty::ResetToDefault(v34);
    ((void (__fastcall *)(OSuite::ZOProperty *, OSuite::ZString *, OSuite::ZJsonValue *))v34->vfptr[3].__vecDelDtor)(
      v34,
      v3,
      v5);
    OSuite::TList<OSuite::ZONavigationProperty *>::Grow(
      (OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *)&v4->m_Properties,
      v4->m_Properties.m_nTop + 1);
    v4->m_Properties.m_pList[v4->m_Properties.m_nTop++] = v34;
  }
}

// File Line: 335
// RVA: 0xEC7B18
void __fastcall OSuite::ZOEntry::ToJson(OSuite::ZOEntry *this, OSuite::ZJsonObject *pJson, OSuite::ZHttp::EMethod eMethod)
{
  OSuite::ZOEntry::ToJsonWithProperties(this, pJson, eMethod, &this->m_Properties);
}

// File Line: 341
// RVA: 0xEC7B24
void __fastcall OSuite::ZOEntry::ToJsonWithProperties(OSuite::ZOEntry *this, OSuite::ZJsonObject *pJson, OSuite::ZHttp::EMethod eMethod, OSuite::TList<OSuite::ZOProperty *> *properties)
{
  char v4; // si
  OSuite::ZOEntry *v5; // r14
  OSuite::TList<OSuite::ZOProperty *> *v6; // r13
  OSuite::ZHttp::EMethod v7; // er12
  OSuite::ZJsonObject *v8; // r15
  OSuite::ZJsonObject *v9; // rax
  OSuite::ZJsonObject *v10; // rax
  OSuite::ZJsonObject *v11; // rbx
  __int64 v12; // rax
  OSuite::ZString *v13; // r13
  unsigned __int64 v14; // rdi
  unsigned __int64 v15; // r12
  char v16; // r15
  OSuite::ZJsonValue *v17; // rdi
  OSuite::ZJsonValue *v18; // rax
  OSuite::ZString *v19; // rax
  OSuite::ZJsonValue *v20; // rdi
  OSuite::ZJsonValue *v21; // rdi
  OSuite::ZJsonValue *v22; // rax
  OSuite::ZString *v23; // rax
  OSuite::ZJsonValue *v24; // rdi
  OSuite::ZJsonValue *v25; // rax
  OSuite::ZJsonValue *v26; // rax
  OSuite::ZJsonValue *v27; // rdi
  OSuite::ZJsonValue *v28; // rax
  OSuite::ZJsonValue *v29; // rax
  OSuite::ZJsonValue *v30; // rbx
  unsigned __int64 v31; // rsi
  OSuite::ZString::InternalString *v32; // rbx
  __int64 v33; // rdi
  __int64 v34; // rcx
  OSuite::ZString sName; // [rsp+20h] [rbp-79h]
  OSuite::ZHttp::EMethod v36; // [rsp+38h] [rbp-61h]
  OSuite::TList<OSuite::ZOProperty *> *v37; // [rsp+40h] [rbp-59h]
  OSuite::ZJsonObject *v38; // [rsp+48h] [rbp-51h]
  int v39; // [rsp+50h] [rbp-49h]
  OSuite::ZString result; // [rsp+58h] [rbp-41h]
  unsigned __int64 v41; // [rsp+70h] [rbp-29h]
  OSuite::ZStringBuilder v42; // [rsp+78h] [rbp-21h]

  v4 = 0;
  v5 = this;
  v6 = properties;
  v37 = properties;
  v7 = eMethod;
  v36 = eMethod;
  v8 = pJson;
  v38 = pJson;
  v39 = 0;
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
  if ( ((unsigned __int8 (__fastcall *)(OSuite::ZOEntry *))v5->vfptr[4].__vecDelDtor)(v5) )
  {
    v12 = ((__int64 (__fastcall *)(OSuite::ZOEntry *))v5->vfptr[5].__vecDelDtor)(v5);
    v42.m_Chars.m_pList = 0i64;
    v13 = (OSuite::ZString *)v12;
    OSuite::ZStringBuilder::ZStringBuilder(&v42, 0x20ui64);
    v14 = 0i64;
    v15 = OSuite::ZString::Count(v13);
    if ( v15 )
    {
      do
      {
        v16 = OSuite::ZString::CharAt(v13, v14);
        if ( v16 == 34 )
          OSuite::ZStringBuilder::Append(&v42, 92);
        OSuite::ZStringBuilder::Append(&v42, v16);
        ++v14;
      }
      while ( v14 < v15 );
      v8 = v38;
    }
    v17 = (OSuite::ZJsonValue *)OSuite::ZObject::operator new(0x60ui64);
    v18 = 0i64;
    if ( v17 )
    {
      v17->m_literal.m_pString = 0i64;
      v17->m_array.m_pList = 0i64;
      v17->m_object = 0i64;
      v4 = 1;
      v19 = OSuite::ZStringBuilder::ToString(&v42, &result);
      OSuite::ZJsonValue::ZJsonValue(v17, v19, 1);
    }
    v20 = v18;
    OSuite::ZString::ZString(&sName, "etag");
    OSuite::ZJsonObject::Add(v11, &sName, v20);
    OSuite::ZString::~ZString(&sName);
    if ( v4 & 1 )
    {
      v4 &= 0xFEu;
      OSuite::ZString::~ZString(&result);
    }
    OSuite::ZUtf8Buffer::~ZUtf8Buffer(&v42);
    v7 = v36;
    v6 = v37;
  }
  if ( v5->m_pEdmEntityType )
  {
    v21 = (OSuite::ZJsonValue *)OSuite::ZObject::operator new(0x60ui64);
    v22 = 0i64;
    if ( v21 )
    {
      v21->m_literal.m_pString = 0i64;
      v21->m_array.m_pList = 0i64;
      v21->m_object = 0i64;
      v4 |= 2u;
      v23 = OSuite::ZOEdmBase::FullyQualifiedName((OSuite::ZOEdmBase *)&v5->m_pEdmEntityType->vfptr, &result);
      OSuite::ZJsonValue::ZJsonValue(v21, v23, 1);
    }
    v24 = v22;
    OSuite::ZString::ZString(&sName, "type");
    OSuite::ZJsonObject::Add(v11, &sName, v24);
    OSuite::ZString::~ZString(&sName);
    if ( v4 & 2 )
      OSuite::ZString::~ZString(&result);
  }
  if ( OSuite::ZString::operator bool(&v5->m_sEditURL) )
  {
    v25 = (OSuite::ZJsonValue *)OSuite::ZObject::operator new(0x60ui64);
    if ( v25 )
    {
      v25->m_literal.m_pString = 0i64;
      v25->m_array.m_pList = 0i64;
      v25->m_object = 0i64;
      OSuite::ZJsonValue::ZJsonValue(v25, &v5->m_sEditURL, 1);
      v27 = v26;
    }
    else
    {
      v27 = 0i64;
    }
    OSuite::ZString::ZString(&sName, "uri");
    OSuite::ZJsonObject::Add(v11, &sName, v27);
    OSuite::ZString::~ZString(&sName);
  }
  if ( v11->m_Pairs.m_nCount <= 0 )
  {
    v11->vfptr->__vecDelDtor((OSuite::ZObject *)&v11->vfptr, 1u);
  }
  else
  {
    v28 = (OSuite::ZJsonValue *)OSuite::ZObject::operator new(0x60ui64);
    if ( v28 )
    {
      v28->m_literal.m_pString = 0i64;
      v28->m_array.m_pList = 0i64;
      v28->m_object = 0i64;
      OSuite::ZJsonValue::ZJsonValue(v28, v11);
      v30 = v29;
    }
    else
    {
      v30 = 0i64;
    }
    OSuite::ZString::ZString(&sName, "__metadata");
    OSuite::ZJsonObject::Add(v8, &sName, v30);
    OSuite::ZString::~ZString(&sName);
  }
  result.m_pString = 0i64;
  OSuite::ZListBase::ZListIteratorBase::ZListIteratorBase(
    (OSuite::ZListBase::ZListIteratorBase *)&sName,
    (OSuite::ZListBase *)&v6->vfptr);
  sName.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable';
  result.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TConstIterator<OSuite::TList<OSuite::ZOEdmEndRole *>::ZIterator,OSuite::ZOEdmEndRole *,int>::`vftable';
  OSuite::ZListBase::ZListIteratorBase::ZListIteratorBase(
    (OSuite::ZListBase::ZListIteratorBase *)&result.vfptr,
    (OSuite::ZListBase::ZListIteratorBase *)&sName);
  result.vfptr = (OSuite::IHashableVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable';
  while ( !OSuite::ZListBase::ZListIteratorBase::AtEnd((OSuite::ZListBase::ZListIteratorBase *)&result.vfptr) )
  {
    OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)result.m_pString);
    v31 = v41;
    v32 = result.m_pString;
    v33 = v41 + 1;
    OSuite::TList<OSuite::ZONavigationProperty *>::Grow(
      (OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *)result.m_pString,
      v41 + 1);
    if ( v31 >= *(_QWORD *)&v32->m_nHash )
      *(_QWORD *)&v32->m_nHash = v33;
    v34 = *(_QWORD *)(v32[1].m_nLength + 8 * v31);
    (*(void (__fastcall **)(__int64, OSuite::ZJsonObject *, _QWORD))(*(_QWORD *)v34 + 16i64))(v34, v8, (unsigned int)v7);
    OSuite::ZListBase::ZListIteratorBase::Next((OSuite::ZListBase::ZListIteratorBase *)&result.vfptr);
  }
  result.vfptr = (OSuite::IHashableVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable';
  result.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TConstIterator<OSuite::TList<OSuite::ZOEdmEndRole *>::ZIterator,OSuite::ZOEdmEndRole *,int>::`vftable';
  OSuite::ZOEdmBase::CleanTempData((int)v5);
}

// File Line: 433
// RVA: 0xEC704C
char __fastcall OSuite::ZOEntry::InternalPostTo(OSuite::ZOEntry *this, OSuite::ZAtomEntry::UploadRequest *pRequest)
{
  OSuite::ZOEntry *v2; // r14
  OSuite::ZAtomEntry::UploadRequest *v3; // rsi
  OSuite::ZHttpManager *v4; // rax
  OSuite::IHttpRequest *v5; // rax
  OSuite::ZObjectVtbl *v6; // rbx
  __int64 v7; // rax
  OSuite::ZObjectVtbl *v8; // rbx
  __int64 v9; // rax
  OSuite::ZObjectVtbl *v10; // rbx
  __int64 v11; // rax
  OSuite::ZObjectVtbl *v12; // rbx
  unsigned __int64 v13; // rax
  OSuite::ZUrl *v14; // rax
  OSuite::IHttpRequest *v15; // rcx
  OSuite::ZUrl url; // [rsp+30h] [rbp-D0h]
  OSuite::ZDateTime v18; // [rsp+108h] [rbp+8h]
  __int64 v19; // [rsp+120h] [rbp+20h]
  __int64 v20; // [rsp+128h] [rbp+28h]
  OSuite::ZOEntry *v21; // [rsp+130h] [rbp+30h]
  bool (__fastcall *v22)(OSuite::ZAtomEntry *, OSuite::IHttpRequest *, unsigned __int64); // [rsp+138h] [rbp+38h]
  OSuite::ZOEntry *v23; // [rsp+140h] [rbp+40h]
  bool (__fastcall *v24)(OSuite::ZOEntry *, OSuite::IHttpRequest *, OSuite::ZHttp::EError); // [rsp+148h] [rbp+48h]
  char v25; // [rsp+150h] [rbp+50h]

  v2 = this;
  this->m_eState = 4;
  v3 = pRequest;
  OSuite::ZDateTime::ZDateTime(&v18);
  v19 = 0i64;
  OSuite::ZJsonDocument::ZJsonDocument((OSuite::ZJsonDocument *)&v18.m_nYear);
  ((void (__fastcall *)(OSuite::ZOEntry *, int *, signed __int64))v2->vfptr[2].__vecDelDtor)(v2, &v18.m_nYear, 2i64);
  OSuite::ZJsonSerializer::Serialize(
    (OSuite::ZJsonSerializer *)&v18,
    &v3->m_entrycontent,
    (OSuite::ZJsonDocument *)&v18.m_nYear);
  OSuite::ZJsonDocument::~ZJsonDocument((OSuite::ZJsonDocument *)&v18.m_nYear);
  OSuite::ZJsonSerializer::~ZJsonSerializer(&v18);
  OSuite::ZUrl::ZUrl(&url, &v2->m_sFeedURL);
  v4 = OSuite::TSingleton<OSuite::ZHttpManager>::Object();
  OSuite::ZHttpRequestManager::CreateHttpRequest(v4->m_httpRequestManager, &url, v2, 1, 30);
  v2->m_pCurrentRequest = v5;
  OSuite::ZUrl::~ZUrl(&url);
  v6 = v2->m_pCurrentRequest->vfptr;
  OSuite::ZString::ZString((OSuite::ZString *)&v18.m_nYear, "POST");
  v6[44].__vecDelDtor((OSuite::ZObject *)&v2->m_pCurrentRequest->vfptr, v7);
  v8 = v2->m_pCurrentRequest->vfptr;
  OSuite::ZString::ZString((OSuite::ZString *)&v18.m_nYear, "application/json");
  v8[36].__vecDelDtor((OSuite::ZObject *)&v2->m_pCurrentRequest->vfptr, v9);
  v10 = v2->m_pCurrentRequest->vfptr;
  OSuite::ZString::ZString((OSuite::ZString *)&v18.m_nYear, "application/json");
  v10[41].__vecDelDtor((OSuite::ZObject *)&v2->m_pCurrentRequest->vfptr, v11);
  v12 = v2->m_pCurrentRequest->vfptr;
  v13 = OSuite::ZStringBuilder::Count((OSuite::ZStringBuilder *)&v3->m_entrycontent);
  v12[42].__vecDelDtor((OSuite::ZObject *)&v2->m_pCurrentRequest->vfptr, v13);
  v2->m_pCurrentRequest->vfptr[43].__vecDelDtor((OSuite::ZObject *)&v2->m_pCurrentRequest->vfptr, (unsigned int)v3);
  v14 = (OSuite::ZUrl *)((__int64 (*)(void))v2->m_pCurrentRequest->vfptr[34].__vecDelDtor)();
  OSuite::ZUrl::operator=(&v3->m_CbData.URL, v14);
  *(_QWORD *)&v18.m_nDate = 0i64;
  *(_QWORD *)&v18.m_nYear = 0i64;
  v20 = 0i64;
  v19 = 0i64;
  v22 = OSuite::ZAtomEntry::OnDataNeeded;
  v21 = v2;
  v24 = OSuite::ZOEntry::OnPostToFinished;
  v15 = v2->m_pCurrentRequest;
  v23 = v2;
  v25 = 0;
  v15->vfptr[6].__vecDelDtor((OSuite::ZObject *)&v15->vfptr, (unsigned int)&v18.m_nYear);
  return 1;
}

// File Line: 480
// RVA: 0xEC7258
bool __fastcall OSuite::ZOEntry::OnPostToFinished(OSuite::ZOEntry *this, OSuite::IHttpRequest *pHttpRequest, OSuite::ZHttp::EError error)
{
  OSuite::ZHttp::EError v3; // ebp
  OSuite::IHttpRequest *v4; // rdi
  OSuite::ZOEntry *v5; // rbx
  __int64 v7; // rsi
  OSuite::ZString *v8; // rax
  OSuite::IReader *v9; // rsi
  char v10; // al
  OSuite::ZString v11; // [rsp+20h] [rbp-68h]
  OSuite::ZString v12; // [rsp+38h] [rbp-50h]
  char v13; // [rsp+60h] [rbp-28h]

  v3 = error;
  v4 = pHttpRequest;
  v5 = this;
  if ( !this->m_pCurrentRequest )
    return 0;
  v7 = ((__int64 (__fastcall *)(OSuite::IHttpRequest *))pHttpRequest->vfptr[33].__vecDelDtor)(pHttpRequest);
  if ( (*(unsigned int (__fastcall **)(__int64))(*(_QWORD *)v7 + 32i64))(v7) == 201 )
  {
    OSuite::ZString::ZString(&v11, "ETag");
    v8 = (OSuite::ZString *)(*(__int64 (__fastcall **)(__int64, OSuite::ZString *, OSuite::ZString *))(*(_QWORD *)v7 + 8i64))(
                              v7,
                              &v12,
                              &v11);
    OSuite::ZString::operator=(&v5->m_ETag, v8);
    OSuite::ZString::~ZString(&v12);
    OSuite::ZString::~ZString(&v11);
    v9 = (OSuite::IReader *)(*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v7 + 64i64))(v7);
    if ( v9->vfptr->Size(v9) )
    {
      OSuite::ZOEntry::Reset(v5);
      v12.m_pString = 0i64;
      OSuite::ZJsonDocument::ZJsonDocument((OSuite::ZJsonDocument *)&v12, v9);
      v10 = v13;
      v5->m_bHasValidSource = v13;
      if ( v10 )
        OSuite::ZAtomBase::ParseJson((OSuite::ZAtomBase *)&v5->vfptr, (OSuite::ZJsonObject *)&v12);
      OSuite::ZJsonDocument::~ZJsonDocument((OSuite::ZJsonDocument *)&v12);
    }
  }
  return OSuite::ZAtomEntry::OnFinished((OSuite::ZAtomEntry *)&v5->vfptr, v4, v3);
}

// File Line: 508
// RVA: 0xEC7964
void __fastcall OSuite::ZOEntry::Reset(OSuite::ZOEntry *this)
{
  OSuite::ZObject *v1; // rsi
  OSuite::ZOEntry *v2; // r15
  unsigned __int64 v3; // rdi
  OSuite::ZListBase *v4; // rbx
  unsigned __int64 v5; // r14
  void (__fastcall ***v6)(_QWORD, signed __int64); // rcx
  OSuite::ZObjectVtbl *v7; // rdx
  OSuite::ZObjectVtbl *v8; // rax
  OSuite::ZObject *v9; // rbx
  unsigned __int64 v10; // rsi
  OSuite::ZListBase *v11; // rdi
  unsigned __int64 v12; // r14
  void (__fastcall ***v13)(_QWORD, signed __int64); // rcx
  OSuite::ZONavigationProperty **v14; // rdx
  OSuite::ZONavigationProperty **v15; // rax
  OSuite::ZListBase::ZListIteratorBase v16; // [rsp+20h] [rbp-40h]
  OSuite::ZListBase::ZListIteratorBase v17; // [rsp+38h] [rbp-28h]

  v16.m_pListBase = 0i64;
  v1 = (OSuite::ZObject *)&this->m_Properties.vfptr;
  v2 = this;
  OSuite::ZListBase::ZListIteratorBase::ZListIteratorBase(&v16, (OSuite::ZListBase *)&this->m_Properties.vfptr);
  v16.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable';
  while ( !OSuite::ZListBase::ZListIteratorBase::AtEnd(&v16) )
  {
    OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)v16.m_pListBase);
    v3 = v16.m_nIndex;
    v4 = v16.m_pListBase;
    v5 = v16.m_nIndex + 1;
    OSuite::TList<OSuite::ZONavigationProperty *>::Grow(
      (OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *)v16.m_pListBase,
      v16.m_nIndex + 1);
    if ( v3 >= v4->m_nTop )
      v4->m_nTop = v5;
    v6 = *(void (__fastcall ****)(_QWORD, signed __int64))(v4[1].m_nSize + 8 * v3);
    if ( v6 )
      (**v6)(v6, 1i64);
    OSuite::ZListBase::ZListIteratorBase::Next(&v16);
  }
  v7 = v1[4].vfptr;
  v16.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable';
  OSuite::ZObject::free(v1, v7);
  v8 = (OSuite::ZObjectVtbl *)OSuite::ZObject::malloc(v1, 0x80ui64, 0i64);
  v1[2].vfptr = 0i64;
  v17.m_pListBase = 0i64;
  v9 = (OSuite::ZObject *)&v2->m_NavProperties.vfptr;
  v1[4].vfptr = v8;
  v1[1].vfptr = (OSuite::ZObjectVtbl *)16;
  OSuite::ZListBase::ZListIteratorBase::ZListIteratorBase(&v17, (OSuite::ZListBase *)&v2->m_NavProperties.vfptr);
  v17.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable';
  while ( !OSuite::ZListBase::ZListIteratorBase::AtEnd(&v17) )
  {
    OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)v17.m_pListBase);
    v10 = v17.m_nIndex;
    v11 = v17.m_pListBase;
    v12 = v17.m_nIndex + 1;
    OSuite::TList<OSuite::ZONavigationProperty *>::Grow(
      (OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *)v17.m_pListBase,
      v17.m_nIndex + 1);
    if ( v10 >= v11->m_nTop )
      v11->m_nTop = v12;
    v13 = *(void (__fastcall ****)(_QWORD, signed __int64))(v11[1].m_nSize + 8 * v10);
    if ( v13 )
      (**v13)(v13, 1i64);
    OSuite::ZListBase::ZListIteratorBase::Next(&v17);
  }
  v14 = v2->m_NavProperties.m_pList;
  v17.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable';
  OSuite::ZObject::free(v9, v14);
  v15 = (OSuite::ZONavigationProperty **)OSuite::ZObject::malloc(v9, 0x80ui64, 0i64);
  v2->m_NavProperties.m_nTop = 0i64;
  v2->m_NavProperties.m_nSize = 16i64;
  v2->m_NavProperties.m_pList = v15;
}

