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
void __fastcall OSuite::ZOEntry::ZOEntry(
        OSuite::ZOEntry *this,
        OSuite::ZOEdmEntityType *const pEdmEntityType,
        OSuite::ZUrl *sFeedUrl)
{
  OSuite::ZObject *v5; // rdx
  OSuite::ZOProperty **v6; // rax
  OSuite::ZObject *v7; // rdx
  OSuite::ZONavigationProperty **v8; // rax

  OSuite::ZAtomEntry::ZAtomEntry(this, sFeedUrl);
  this->m_pEdmEntityType = pEdmEntityType;
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZOEntry::`vftable;
  OSuite::ZRedBlackTreeBase::ZElementBase::ZElementBase(&this->m_Properties, v5);
  this->m_Properties.m_pList = 0i64;
  this->m_Properties.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuitePrivate::ZPlayerConsumableData::ZRequest *>::`vftable{for `OSuite::ZListBase};
  this->m_Properties.vfptr = (OSuite::IHashableVtbl *)&OSuite::TList<OSuite::ZJsonObject *>::`vftable{for `OSuite::IHashable};
  v6 = (OSuite::ZOProperty **)OSuite::ZObject::malloc(&this->m_Properties, 0x80ui64, 0i64);
  this->m_Properties.m_nTop = 0i64;
  this->m_Properties.m_nSize = 16i64;
  this->m_Properties.m_pList = v6;
  OSuite::ZRedBlackTreeBase::ZElementBase::ZElementBase(&this->m_NavProperties, v7);
  this->m_NavProperties.m_pList = 0i64;
  this->m_NavProperties.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuitePrivate::ZPlayerConsumableData::ZRequest *>::`vftable{for `OSuite::ZListBase};
  this->m_NavProperties.vfptr = (OSuite::IHashableVtbl *)&OSuite::TList<OSuite::ZJsonObject *>::`vftable{for `OSuite::IHashable};
  v8 = (OSuite::ZONavigationProperty **)OSuite::ZObject::malloc(&this->m_NavProperties, 0x80ui64, 0i64);
  this->m_NavProperties.m_nTop = 0i64;
  this->m_NavProperties.m_nSize = 16i64;
  this->m_NavProperties.m_pList = v8;
  this->m_bHasValidSource = 1;
}

// File Line: 35
// RVA: 0xEC6AA4
void __fastcall OSuite::ZOEntry::ZOEntry(OSuite::ZOEntry *this, OSuite::IReader *pReader, OSuite::ZUrl *sFeedUrl)
{
  OSuite::ZObject *v5; // rdx
  OSuite::ZOProperty **v6; // rax
  OSuite::ZObject *v7; // rdx
  OSuite::ZONavigationProperty **v8; // rax
  OSuite::ZOnlineSuite *v9; // rax
  OSuite::ZWebServiceClient *v10; // rbx
  OSuite::ZOMetadata *v11; // rax
  bool m_bIsValid; // cl
  OSuite::ZUrl url; // [rsp+20h] [rbp-208h] BYREF
  OSuite::ZUrl v14; // [rsp+F8h] [rbp-130h] BYREF
  OSuite::ZJsonDocument v15; // [rsp+1D0h] [rbp-58h] BYREF

  OSuite::ZAtomEntry::ZAtomEntry(this, sFeedUrl);
  this->m_pEdmEntityType = 0i64;
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZOEntry::`vftable;
  OSuite::ZRedBlackTreeBase::ZElementBase::ZElementBase(&this->m_Properties, v5);
  this->m_Properties.m_pList = 0i64;
  this->m_Properties.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuitePrivate::ZPlayerConsumableData::ZRequest *>::`vftable{for `OSuite::ZListBase};
  this->m_Properties.vfptr = (OSuite::IHashableVtbl *)&OSuite::TList<OSuite::ZJsonObject *>::`vftable{for `OSuite::IHashable};
  v6 = (OSuite::ZOProperty **)OSuite::ZObject::malloc(&this->m_Properties, 0x80ui64, 0i64);
  this->m_Properties.m_nTop = 0i64;
  this->m_Properties.m_pList = v6;
  this->m_Properties.m_nSize = 16i64;
  OSuite::ZRedBlackTreeBase::ZElementBase::ZElementBase(&this->m_NavProperties, v7);
  this->m_NavProperties.m_pList = 0i64;
  this->m_NavProperties.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuitePrivate::ZPlayerConsumableData::ZRequest *>::`vftable{for `OSuite::ZListBase};
  this->m_NavProperties.vfptr = (OSuite::IHashableVtbl *)&OSuite::TList<OSuite::ZJsonObject *>::`vftable{for `OSuite::IHashable};
  v8 = (OSuite::ZONavigationProperty **)OSuite::ZObject::malloc(&this->m_NavProperties, 0x80ui64, 0i64);
  this->m_NavProperties.m_nTop = 0i64;
  this->m_NavProperties.m_nSize = 16i64;
  this->m_NavProperties.m_pList = v8;
  OSuite::ZUrl::ZUrl(&url, &this->m_sFeedURL);
  v9 = OSuite::ZOnlineSuite::Instance();
  v10 = OSuite::ZOnlineSuite::GetForUrl(v9, &url);
  OSuite::ZUrl::~ZUrl(&url);
  OSuite::ZUrl::ZUrl(&v14, &this->m_sFeedURL);
  v11 = OSuite::ZWebServiceClient::Metadata(v10);
  this->m_pEdmEntityType = OSuite::ZOMetadata::EntityTypeForUrl(v11, &v14);
  OSuite::ZUrl::~ZUrl(&v14);
  if ( this->m_pEdmEntityType )
  {
    v15.m_Pairs.m_pLists = 0i64;
    OSuite::ZJsonDocument::ZJsonDocument(&v15, pReader);
    m_bIsValid = v15.m_bIsValid;
    this->m_bHasValidSource = v15.m_bIsValid;
    if ( m_bIsValid )
      OSuite::ZAtomBase::ParseJson(this, &v15);
    OSuite::ZJsonDocument::~ZJsonDocument(&v15);
  }
}

// File Line: 55
// RVA: 0xEC6D30
void __fastcall OSuite::ZOEntry::~ZOEntry(OSuite::ZOEntry *this)
{
  OSuite::ZONavigationProperty **m_pList; // rdx
  OSuite::ZOProperty **v3; // rdx

  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZOEntry::`vftable;
  OSuite::ZOEntry::Reset(this);
  m_pList = this->m_NavProperties.m_pList;
  this->m_NavProperties.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuitePrivate::ZPlayerConsumableData::ZRequest *>::`vftable{for `OSuite::ZListBase};
  this->m_NavProperties.vfptr = (OSuite::IHashableVtbl *)&OSuite::TList<OSuite::ZJsonObject *>::`vftable{for `OSuite::IHashable};
  OSuite::ZObject::free(&this->m_NavProperties, m_pList);
  v3 = this->m_Properties.m_pList;
  this->m_Properties.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuitePrivate::ZPlayerConsumableData::ZRequest *>::`vftable{for `OSuite::ZListBase};
  this->m_Properties.vfptr = (OSuite::IHashableVtbl *)&OSuite::TList<OSuite::ZJsonObject *>::`vftable{for `OSuite::IHashable};
  OSuite::ZObject::free(&this->m_Properties, v3);
  OSuite::ZAtomEntry::~ZAtomEntry(this);
}

// File Line: 62
// RVA: 0xEC7864
OSuite::ZOProperty *__fastcall OSuite::ZOEntry::Property(OSuite::ZOEntry *this, const char *propertyName)
{
  unsigned __int64 m_nIndex; // r14
  OSuite::ZListBase *m_pListBase; // rbx
  unsigned __int64 v5; // rsi
  unsigned __int64 v7; // rdi
  OSuite::ZListBase *v8; // rbx
  unsigned __int64 v9; // rsi
  OSuite::ZListBase::ZListIteratorBase v10; // [rsp+20h] [rbp-20h] BYREF

  if ( propertyName )
  {
    v10.m_pListBase = 0i64;
    OSuite::ZListBase::ZListIteratorBase::ZListIteratorBase(&v10, &this->m_Properties);
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
      if ( OSuite::ZString::EqualsCaseInsensitive(
             (OSuite::ZString *)(*(_QWORD *)(m_pListBase[1].m_nSize + 8 * m_nIndex) + 152i64),
             propertyName) )
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
OSuite::TList<OSuite::ZOProperty *>::ZIterator *__fastcall OSuite::ZOEntry::Properties(
        OSuite::ZOEntry *this,
        OSuite::TList<OSuite::ZOProperty *>::ZIterator *result)
{
  OSuite::ZListBase::ZListIteratorBase::ZListIteratorBase(result, &this->m_Properties);
  result->vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable;
  return result;
}

// File Line: 113
// RVA: 0xEC6E84
OSuite::ZOProperty *__fastcall OSuite::ZOEntry::AddProperty(OSuite::ZOEntry *this, const char *propertyName)
{
  char v2; // si
  OSuite::EdmType v6; // ebx
  OSuite::ZOProperty *v7; // rax
  OSuite::ZOProperty *v8; // rbx
  OSuite::ZOProperty *v9; // rax
  OSuite::ZOProperty *v10; // rdi
  OSuite::ZError *v11; // rax
  OSuite::ZString name; // [rsp+20h] [rbp-28h] BYREF

  v2 = 0;
  if ( !propertyName )
    return 0i64;
  OSuite::ZString::ZString(&name, propertyName);
  v6 = OSuite::deduceEdmTypeFromName(&name);
  OSuite::ZString::~ZString(&name);
  if ( v6 == EDM_NULL || OSuite::ZOEntry::Property(this, propertyName) )
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
    OSuite::ZString::ZString(&name, propertyName);
    v2 = 1;
    OSuite::ZOProperty::ZOProperty(v8, &name, &this->m_sBaseURL);
    v10 = v9;
  }
  else
  {
    v10 = 0i64;
  }
  if ( (v2 & 1) != 0 )
    OSuite::ZString::~ZString(&name);
  if ( !v10 )
  {
    v11 = OSuite::TSingleton<OSuite::ZError>::Object();
    OSuite::ZError::SetThreadLastError(v11, ZERROR_OUT_OF_MEMORY, 1);
    return 0i64;
  }
  OSuite::ZOProperty::ResetToDefault(v10);
  OSuite::TList<OSuite::ZONavigationProperty *>::Grow(
    (OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *)&this->m_Properties,
    this->m_Properties.m_nTop + 1);
  this->m_Properties.m_pList[this->m_Properties.m_nTop++] = v10;
  return v10;
}

// File Line: 176
// RVA: 0xEC6FE8
bool __fastcall OSuite::ZOEntry::DeleteProperty(OSuite::ZOEntry *this, const char *propertyName)
{
  OSuite::ZOProperty *v3; // rax
  unsigned __int64 v4; // rdx
  OSuite::ZOProperty *v5; // rbx
  OSuite::ZOProperty **m_pList; // rax

  v3 = OSuite::ZOEntry::Property(this, propertyName);
  v4 = 0i64;
  v5 = v3;
  if ( v3 )
  {
    if ( this->m_Properties.m_nTop )
    {
      m_pList = this->m_Properties.m_pList;
      while ( *m_pList != v5 )
      {
        ++v4;
        ++m_pList;
        if ( v4 >= this->m_Properties.m_nTop )
          goto LABEL_8;
      }
      this->m_Properties.vfptr[1].__vecDelDtor(&this->m_Properties, v4);
    }
LABEL_8:
    v5->vfptr->__vecDelDtor(v5, 1u);
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

  if ( OSuite::ZOEntry::s_nClassId == nClassId )
    return 1;
  v2 = OSuite::ZAtomEntry::ClassMatch(this, nClassId);
  v3 = 0;
  if ( v2 )
    return 1;
  return v3;
}

// File Line: 237
// RVA: 0xEC7380
void __fastcall OSuite::ZOEntry::ParseJsonValue(
        OSuite::ZOEntry *this,
        OSuite::ZString *name,
        OSuite::ZJsonValue *pJson)
{
  OSuite::ZONavigationProperty *v6; // rdi
  OSuite::ZJsonObject *m_object; // rbx
  OSuite::ZError *v8; // rax
  OSuite::ZJsonValue *v9; // r14
  OSuite::ZJsonObject *v10; // r13
  OSuite::ZJsonValue *v11; // r15
  OSuite::ZString *p_m_literal; // r15
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
  OSuite::ZUrl *BaseUrl; // rax
  OSuite::ZString *v26; // rax
  unsigned __int64 v27; // rax
  OSuite::ZONavigationProperty *v28; // rax
  OSuite::ZONavigationProperty *v29; // rax
  OSuite::ZOEdmProperty *v30; // r15
  OSuite::ZOProperty *v31; // rax
  OSuite::ZOProperty *v32; // rax
  OSuite::ZOProperty *v33; // rax
  OSuite::ZOProperty *v34; // r15
  OSuite::ZString v35; // [rsp+30h] [rbp-D0h] BYREF
  OSuite::ZString v36; // [rsp+48h] [rbp-B8h] BYREF
  OSuite::ZUrl result; // [rsp+60h] [rbp-A0h] BYREF
  OSuite::ZString sName; // [rsp+138h] [rbp+38h] BYREF
  OSuite::ZStringBuilder v39; // [rsp+150h] [rbp+50h] BYREF

  v6 = 0i64;
  if ( OSuite::ZString::operator==(name, "d") )
  {
    m_object = pJson->m_object;
    if ( m_object )
    {
      OSuite::ZString::ZString(&sName, "results");
      v9 = OSuite::ZJsonObject::Value(m_object, &sName);
      OSuite::ZString::~ZString(&sName);
      if ( v9 )
        m_object = v9->m_object;
      OSuite::ZAtomBase::ParseJson(this, m_object);
    }
    else
    {
      v8 = OSuite::TSingleton<OSuite::ZError>::Object();
      OSuite::ZError::SetThreadLastError(v8, ZERROR_PARSING_FAILED, 1);
    }
    return;
  }
  if ( OSuite::ZString::operator==(name, "__metadata") )
  {
    v10 = pJson->m_object;
    OSuite::ZString::ZString(&sName, "etag");
    v11 = OSuite::ZJsonObject::Value(v10, &sName);
    OSuite::ZString::~ZString(&sName);
    if ( v11 )
    {
      p_m_literal = &v11->m_literal;
      v39.m_Chars.m_pList = 0i64;
      OSuite::ZStringBuilder::ZStringBuilder(&v39, 0x20ui64);
      v13 = 0i64;
      v14 = OSuite::ZString::Count(p_m_literal);
      if ( v14 )
      {
        do
        {
          v15 = OSuite::ZString::CharAt(p_m_literal, v13++);
          v16 = v15;
          if ( v13 >= v14 )
            v17 = 0;
          else
            v17 = OSuite::ZString::CharAt(p_m_literal, v13);
          if ( v16 != 92 || v17 != 34 )
            OSuite::ZStringBuilder::Append(&v39, v16);
        }
        while ( v13 < v14 );
      }
      this->vfptr[6].__vecDelDtor(this, (unsigned int)&this->m_ETag);
      OSuite::ZUtf8Buffer::~ZUtf8Buffer(&v39);
    }
    OSuite::ZString::ZString(&sName, "uri");
    v18 = OSuite::ZJsonObject::Value(v10, &sName);
    OSuite::ZString::~ZString(&sName);
    if ( v18 )
      OSuite::ZString::operator=(&this->m_sEditURL, &v18->m_literal);
    return;
  }
  if ( OSuite::ZString::StartsWith(name, "__") )
  {
    OSuite::ZOEdmBase::CleanTempData((int)this);
    return;
  }
  if ( pJson->m_Type == JSONTYPE_OBJECT )
  {
    OSuite::ZString::ZString(&v36, "__deferred");
    v19 = OSuite::ZJsonObject::Value(pJson->m_object, &v36);
    OSuite::ZString::~ZString(&v36);
    if ( v19 )
    {
      v20 = OSuite::ZOEdmEntityType::NavigationProperty(this->m_pEdmEntityType, name);
      if ( v20 )
      {
        OSuite::ZString::ZString(&v35, "uri");
        v21 = OSuite::ZJsonObject::Value(v19->m_object, &v35);
        v22 = OSuite::ZUrl::Parse(&result, &v21->m_literal);
        OSuite::ZUrl::ToString(v22, (OSuite::ZString *)&v39, 0);
        OSuite::ZUrl::~ZUrl(&result);
        OSuite::ZString::~ZString(&v35);
        OSuite::ZUrl::ZUrl(&result, &this->m_sBaseURL);
        v23 = OSuite::ZOnlineSuite::Instance();
        v24 = OSuite::ZOnlineSuite::GetForUrl(v23, &result);
        OSuite::ZUrl::~ZUrl(&result);
        sName.m_pString = 0i64;
        BaseUrl = OSuite::ZWebServiceClient::GetBaseUrl(v24);
        v26 = OSuite::ZUrl::ToString(BaseUrl, &v35, 0);
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
          OSuite::ZONavigationProperty::ZONavigationProperty(v28, v20, name, &sName, &this->m_sBaseURL);
          v6 = v29;
        }
        OSuite::TList<OSuite::ZONavigationProperty *>::Grow(
          (OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *)&this->m_NavProperties,
          this->m_NavProperties.m_nTop + 1);
        this->m_NavProperties.m_pList[this->m_NavProperties.m_nTop++] = v6;
        OSuite::ZString::~ZString(&sName);
        OSuite::ZString::~ZString((OSuite::ZString *)&v39);
      }
      return;
    }
  }
  v30 = OSuite::ZOEdmEntityType::Property(this->m_pEdmEntityType, name);
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
      OSuite::ZOProperty::ZOProperty(v31, v30, &this->m_sBaseURL);
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
      OSuite::ZOProperty::ZOProperty(v33, name, &this->m_sBaseURL);
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
      name,
      pJson);
    OSuite::TList<OSuite::ZONavigationProperty *>::Grow(
      (OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *)&this->m_Properties,
      this->m_Properties.m_nTop + 1);
    this->m_Properties.m_pList[this->m_Properties.m_nTop++] = v34;
  }
}

// File Line: 335
// RVA: 0xEC7B18
void __fastcall OSuite::ZOEntry::ToJson(
        OSuite::ZOEntry *this,
        OSuite::ZJsonObject *pJson,
        OSuite::ZHttp::EMethod eMethod)
{
  OSuite::ZOEntry::ToJsonWithProperties(this, pJson, eMethod, &this->m_Properties);
}

// File Line: 341
// RVA: 0xEC7B24
void __fastcall OSuite::ZOEntry::ToJsonWithProperties(
        OSuite::ZOEntry *this,
        OSuite::ZJsonObject *pJson,
        unsigned __int32 eMethod,
        OSuite::TList<OSuite::ZOProperty *> *properties)
{
  char v4; // si
  OSuite::TList<OSuite::ZOProperty *> *v6; // r13
  unsigned int v7; // r12d
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
  OSuite::ZString::InternalString *m_pString; // rbx
  unsigned __int64 v33; // rdi
  __int64 v34; // rcx
  OSuite::ZString sName; // [rsp+20h] [rbp-79h] BYREF
  OSuite::ZHttp::EMethod v36; // [rsp+38h] [rbp-61h]
  OSuite::TList<OSuite::ZOProperty *> *v37; // [rsp+40h] [rbp-59h]
  OSuite::ZJsonObject *v38; // [rsp+48h] [rbp-51h]
  int v39; // [rsp+50h] [rbp-49h]
  OSuite::ZString result; // [rsp+58h] [rbp-41h] BYREF
  unsigned __int64 v41; // [rsp+70h] [rbp-29h]
  OSuite::ZStringBuilder v42; // [rsp+78h] [rbp-21h] BYREF

  v4 = 0;
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
  if ( ((unsigned __int8 (__fastcall *)(OSuite::ZOEntry *))this->vfptr[4].__vecDelDtor)(this) )
  {
    v12 = ((__int64 (__fastcall *)(OSuite::ZOEntry *))this->vfptr[5].__vecDelDtor)(this);
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
    if ( (v4 & 1) != 0 )
    {
      v4 &= ~1u;
      OSuite::ZString::~ZString(&result);
    }
    OSuite::ZUtf8Buffer::~ZUtf8Buffer(&v42);
    v7 = v36;
    v6 = v37;
  }
  if ( this->m_pEdmEntityType )
  {
    v21 = (OSuite::ZJsonValue *)OSuite::ZObject::operator new(0x60ui64);
    v22 = 0i64;
    if ( v21 )
    {
      v21->m_literal.m_pString = 0i64;
      v21->m_array.m_pList = 0i64;
      v21->m_object = 0i64;
      v4 |= 2u;
      v23 = OSuite::ZOEdmBase::FullyQualifiedName(this->m_pEdmEntityType, &result);
      OSuite::ZJsonValue::ZJsonValue(v21, v23, 1);
    }
    v24 = v22;
    OSuite::ZString::ZString(&sName, "type");
    OSuite::ZJsonObject::Add(v11, &sName, v24);
    OSuite::ZString::~ZString(&sName);
    if ( (v4 & 2) != 0 )
      OSuite::ZString::~ZString(&result);
  }
  if ( OSuite::ZString::operator bool(&this->m_sEditURL) )
  {
    v25 = (OSuite::ZJsonValue *)OSuite::ZObject::operator new(0x60ui64);
    if ( v25 )
    {
      v25->m_literal.m_pString = 0i64;
      v25->m_array.m_pList = 0i64;
      v25->m_object = 0i64;
      OSuite::ZJsonValue::ZJsonValue(v25, &this->m_sEditURL, 1);
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
  if ( v11->m_Pairs.m_nCount )
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
  else
  {
    v11->vfptr->__vecDelDtor(v11, 1u);
  }
  result.m_pString = 0i64;
  OSuite::ZListBase::ZListIteratorBase::ZListIteratorBase((OSuite::ZListBase::ZListIteratorBase *)&sName, v6);
  sName.OSuite::ZObject::vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable;
  result.OSuite::ZObject::vfptr = (OSuite::ZObjectVtbl *)&OSuite::TConstIterator<OSuite::TList<OSuite::ZOEdmEndRole *>::ZIterator,OSuite::ZOEdmEndRole *,int>::`vftable;
  OSuite::ZListBase::ZListIteratorBase::ZListIteratorBase(
    (OSuite::ZListBase::ZListIteratorBase *)&result.OSuite::IHashable,
    (OSuite::ZListBase::ZListIteratorBase *)&sName);
  result.OSuite::IHashable::vfptr = (OSuite::IHashableVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable;
  while ( !OSuite::ZListBase::ZListIteratorBase::AtEnd((OSuite::ZListBase::ZListIteratorBase *)&result.OSuite::IHashable) )
  {
    OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)result.m_pString);
    v31 = v41;
    m_pString = result.m_pString;
    v33 = v41 + 1;
    OSuite::TList<OSuite::ZONavigationProperty *>::Grow(
      (OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *)result.m_pString,
      v41 + 1);
    if ( v31 >= *(_QWORD *)&m_pString->m_nHash )
      *(_QWORD *)&m_pString->m_nHash = v33;
    v34 = *(_QWORD *)(*(_QWORD *)&m_pString->m_szString[12] + 8 * v31);
    (*(void (__fastcall **)(__int64, OSuite::ZJsonObject *, _QWORD))(*(_QWORD *)v34 + 16i64))(v34, v8, v7);
    OSuite::ZListBase::ZListIteratorBase::Next((OSuite::ZListBase::ZListIteratorBase *)&result.OSuite::IHashable);
  }
  result.OSuite::IHashable::vfptr = (OSuite::IHashableVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable;
  result.OSuite::ZObject::vfptr = (OSuite::ZObjectVtbl *)&OSuite::TConstIterator<OSuite::TList<OSuite::ZOEdmEndRole *>::ZIterator,OSuite::ZOEdmEndRole *,int>::`vftable;
  OSuite::ZOEdmBase::CleanTempData((int)this);
}

// File Line: 433
// RVA: 0xEC704C
char __fastcall OSuite::ZOEntry::InternalPostTo(OSuite::ZOEntry *this, OSuite::ZAtomEntry::UploadRequest *pRequest)
{
  OSuite::ZHttpManager *v4; // rax
  OSuite::IHttpRequest *v5; // rax
  OSuite::ZObjectVtbl *vfptr; // rbx
  __int64 v7; // rax
  OSuite::ZObjectVtbl *v8; // rbx
  __int64 v9; // rax
  OSuite::ZObjectVtbl *v10; // rbx
  __int64 v11; // rax
  OSuite::ZObjectVtbl *v12; // rbx
  unsigned __int64 v13; // rax
  OSuite::ZUrl *v14; // rax
  OSuite::IHttpRequest *m_pCurrentRequest; // rcx
  OSuite::ZUrl url; // [rsp+30h] [rbp-D0h] BYREF
  OSuite::ZDateTime v18; // [rsp+108h] [rbp+8h] BYREF
  __int64 v19; // [rsp+120h] [rbp+20h]
  __int64 v20; // [rsp+128h] [rbp+28h]
  OSuite::ZOEntry *v21; // [rsp+130h] [rbp+30h]
  bool (__fastcall *v22)(OSuite::ZAtomEntry *, OSuite::IHttpRequest *, unsigned __int64); // [rsp+138h] [rbp+38h]
  OSuite::ZOEntry *v23; // [rsp+140h] [rbp+40h]
  bool (__fastcall *v24)(OSuite::ZOEntry *, OSuite::IHttpRequest *, OSuite::ZHttp::EError); // [rsp+148h] [rbp+48h]
  char v25; // [rsp+150h] [rbp+50h]

  this->m_eState = ENTRYSTATE_POSTING;
  OSuite::ZDateTime::ZDateTime(&v18);
  v19 = 0i64;
  OSuite::ZJsonDocument::ZJsonDocument((OSuite::ZJsonDocument *)&v18.m_nYear);
  ((void (__fastcall *)(OSuite::ZOEntry *, int *, __int64))this->vfptr[2].__vecDelDtor)(this, &v18.m_nYear, 2i64);
  OSuite::ZJsonSerializer::Serialize(
    (OSuite::ZJsonSerializer *)&v18,
    &pRequest->m_entrycontent,
    (OSuite::ZJsonDocument *)&v18.m_nYear);
  OSuite::ZJsonDocument::~ZJsonDocument((OSuite::ZJsonDocument *)&v18.m_nYear);
  OSuite::ZJsonSerializer::~ZJsonSerializer(&v18);
  OSuite::ZUrl::ZUrl(&url, &this->m_sFeedURL);
  v4 = OSuite::TSingleton<OSuite::ZHttpManager>::Object();
  OSuite::ZHttpRequestManager::CreateHttpRequest(v4->m_httpRequestManager, &url, this, 1, 30);
  this->m_pCurrentRequest = v5;
  OSuite::ZUrl::~ZUrl(&url);
  vfptr = this->m_pCurrentRequest->OSuite::ZAtomEntry::vfptr;
  OSuite::ZString::ZString((OSuite::ZString *)&v18.m_nYear, "POST");
  vfptr[44].__vecDelDtor(this->m_pCurrentRequest, v7);
  v8 = this->m_pCurrentRequest->OSuite::ZAtomEntry::vfptr;
  OSuite::ZString::ZString((OSuite::ZString *)&v18.m_nYear, "application/json");
  v8[36].__vecDelDtor(this->m_pCurrentRequest, v9);
  v10 = this->m_pCurrentRequest->OSuite::ZAtomEntry::vfptr;
  OSuite::ZString::ZString((OSuite::ZString *)&v18.m_nYear, "application/json");
  v10[41].__vecDelDtor(this->m_pCurrentRequest, v11);
  v12 = this->m_pCurrentRequest->OSuite::ZAtomEntry::vfptr;
  v13 = OSuite::ZStringBuilder::Count((OSuite::ZStringBuilder *)&pRequest->m_entrycontent);
  v12[42].__vecDelDtor(this->m_pCurrentRequest, v13);
  this->m_pCurrentRequest->OSuite::ZAtomEntry::vfptr[43].__vecDelDtor(this->m_pCurrentRequest, (unsigned int)pRequest);
  v14 = (OSuite::ZUrl *)((__int64 (__fastcall *)(OSuite::IHttpRequest *))this->m_pCurrentRequest->OSuite::ZAtomEntry::vfptr[34].__vecDelDtor)(this->m_pCurrentRequest);
  OSuite::ZUrl::operator=(&pRequest->m_CbData.URL, v14);
  *(_QWORD *)&v18.m_nDate = 0i64;
  *(_QWORD *)&v18.m_nYear = 0i64;
  v20 = 0i64;
  v19 = 0i64;
  v22 = OSuite::ZAtomEntry::OnDataNeeded;
  v21 = this;
  v24 = OSuite::ZOEntry::OnPostToFinished;
  m_pCurrentRequest = this->m_pCurrentRequest;
  v23 = this;
  v25 = 0;
  m_pCurrentRequest->vfptr[6].__vecDelDtor(m_pCurrentRequest, (unsigned int)&v18.m_nYear);
  return 1;
}

// File Line: 480
// RVA: 0xEC7258
bool __fastcall OSuite::ZOEntry::OnPostToFinished(
        OSuite::ZOEntry *this,
        OSuite::IHttpRequest *pHttpRequest,
        OSuite::ZHttp::EError error)
{
  __int64 v7; // rsi
  OSuite::ZString *v8; // rax
  OSuite::IReader *v9; // rsi
  bool m_bIsValid; // al
  OSuite::ZString v11; // [rsp+20h] [rbp-68h] BYREF
  OSuite::ZJsonDocument v12; // [rsp+38h] [rbp-50h] BYREF

  if ( !this->m_pCurrentRequest )
    return 0;
  v7 = ((__int64 (__fastcall *)(OSuite::IHttpRequest *))pHttpRequest->vfptr[33].__vecDelDtor)(pHttpRequest);
  if ( (*(unsigned int (__fastcall **)(__int64))(*(_QWORD *)v7 + 32i64))(v7) == 201 )
  {
    OSuite::ZString::ZString(&v11, "ETag");
    v8 = (OSuite::ZString *)(*(__int64 (__fastcall **)(__int64, OSuite::ZJsonDocument *, OSuite::ZString *))(*(_QWORD *)v7 + 8i64))(
                              v7,
                              &v12,
                              &v11);
    OSuite::ZString::operator=(&this->m_ETag, v8);
    OSuite::ZString::~ZString((OSuite::ZString *)&v12);
    OSuite::ZString::~ZString(&v11);
    v9 = (OSuite::IReader *)(*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v7 + 64i64))(v7);
    if ( (__int64)v9->vfptr->Size(v9) )
    {
      OSuite::ZOEntry::Reset(this);
      v12.m_Pairs.m_pLists = 0i64;
      OSuite::ZJsonDocument::ZJsonDocument(&v12, v9);
      m_bIsValid = v12.m_bIsValid;
      this->m_bHasValidSource = v12.m_bIsValid;
      if ( m_bIsValid )
        OSuite::ZAtomBase::ParseJson(this, &v12);
      OSuite::ZJsonDocument::~ZJsonDocument(&v12);
    }
  }
  return OSuite::ZAtomEntry::OnFinished(this, pHttpRequest, error);
}

// File Line: 508
// RVA: 0xEC7964
void __fastcall OSuite::ZOEntry::Reset(OSuite::ZOEntry *this)
{
  OSuite::TList<OSuite::ZOProperty *> *p_m_Properties; // rsi
  unsigned __int64 m_nIndex; // rdi
  OSuite::ZListBase *m_pListBase; // rbx
  unsigned __int64 v5; // r14
  void (__fastcall ***v6)(_QWORD, __int64); // rcx
  OSuite::ZOProperty **m_pList; // rdx
  OSuite::ZOProperty **v8; // rax
  OSuite::TList<OSuite::ZONavigationProperty *> *p_m_NavProperties; // rbx
  unsigned __int64 v10; // rsi
  OSuite::ZListBase *v11; // rdi
  unsigned __int64 v12; // r14
  void (__fastcall ***v13)(_QWORD, __int64); // rcx
  OSuite::ZONavigationProperty **v14; // rdx
  OSuite::ZONavigationProperty **v15; // rax
  OSuite::ZListBase::ZListIteratorBase v16; // [rsp+20h] [rbp-40h] BYREF
  OSuite::ZListBase::ZListIteratorBase v17; // [rsp+38h] [rbp-28h] BYREF

  v16.m_pListBase = 0i64;
  p_m_Properties = &this->m_Properties;
  OSuite::ZListBase::ZListIteratorBase::ZListIteratorBase(&v16, &this->m_Properties);
  v16.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable;
  while ( !OSuite::ZListBase::ZListIteratorBase::AtEnd(&v16) )
  {
    OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)v16.m_pListBase);
    m_nIndex = v16.m_nIndex;
    m_pListBase = v16.m_pListBase;
    v5 = v16.m_nIndex + 1;
    OSuite::TList<OSuite::ZONavigationProperty *>::Grow(
      (OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *)v16.m_pListBase,
      v16.m_nIndex + 1);
    if ( m_nIndex >= m_pListBase->m_nTop )
      m_pListBase->m_nTop = v5;
    v6 = *(void (__fastcall ****)(_QWORD, __int64))(m_pListBase[1].m_nSize + 8 * m_nIndex);
    if ( v6 )
      (**v6)(v6, 1i64);
    OSuite::ZListBase::ZListIteratorBase::Next(&v16);
  }
  m_pList = p_m_Properties->m_pList;
  v16.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable;
  OSuite::ZObject::free(p_m_Properties, m_pList);
  v8 = (OSuite::ZOProperty **)OSuite::ZObject::malloc(p_m_Properties, 0x80ui64, 0i64);
  p_m_Properties->m_nTop = 0i64;
  v17.m_pListBase = 0i64;
  p_m_NavProperties = &this->m_NavProperties;
  p_m_Properties->m_pList = v8;
  p_m_Properties->m_nSize = 16i64;
  OSuite::ZListBase::ZListIteratorBase::ZListIteratorBase(&v17, &this->m_NavProperties);
  v17.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable;
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
    v13 = *(void (__fastcall ****)(_QWORD, __int64))(v11[1].m_nSize + 8 * v10);
    if ( v13 )
      (**v13)(v13, 1i64);
    OSuite::ZListBase::ZListIteratorBase::Next(&v17);
  }
  v14 = this->m_NavProperties.m_pList;
  v17.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable;
  OSuite::ZObject::free(p_m_NavProperties, v14);
  v15 = (OSuite::ZONavigationProperty **)OSuite::ZObject::malloc(p_m_NavProperties, 0x80ui64, 0i64);
  this->m_NavProperties.m_nTop = 0i64;
  this->m_NavProperties.m_nSize = 16i64;
  this->m_NavProperties.m_pList = v15;
}

