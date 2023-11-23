// File Line: 12
// RVA: 0x15D8AD0
__int64 dynamic_initializer_for__OSuite::ZOFeed::s_nClassId__()
{
  __int64 result; // rax

  result = OSuite::ZAtomBase::GenerateClassId();
  OSuite::ZOFeed::s_nClassId = result;
  return result;
}

// File Line: 19
// RVA: 0xECD824
void __fastcall OSuite::ZOFeed::ZOFeed(OSuite::ZOFeed *this, OSuite::IReader *pReader, OSuite::ZUrl *sFeedUrl)
{
  OSuite::ZOnlineSuite *v6; // rax
  OSuite::ZWebServiceClient *v7; // rax
  OSuite::ZWebServiceClient *v8; // rbp
  OSuite::ZOMetadata *v9; // rax
  OSuite::ZOEdmEntityType *v10; // rax
  OSuite::ZUrl *BaseUrl; // rax
  OSuite::ZString *v12; // rax
  bool m_bIsValid; // cl
  OSuite::ZJsonDocument result; // [rsp+20h] [rbp-58h] BYREF

  OSuite::ZAtomFeed::ZAtomFeed(this, sFeedUrl);
  this->m_inlineEntryCount = -1;
  this->m_pEdmEntityType = 0i64;
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZOFeed::`vftable;
  v6 = OSuite::ZOnlineSuite::Instance();
  v7 = OSuite::ZOnlineSuite::GetForUrl(v6, sFeedUrl);
  v8 = v7;
  if ( v7 )
  {
    v9 = OSuite::ZWebServiceClient::Metadata(v7);
    v10 = OSuite::ZOMetadata::EntityTypeForUrl(v9, sFeedUrl);
    this->m_bHasValidSource = 0;
    this->m_pEdmEntityType = v10;
    BaseUrl = OSuite::ZWebServiceClient::GetBaseUrl(v8);
    v12 = OSuite::ZUrl::ToString(BaseUrl, (OSuite::ZString *)&result, 0);
    OSuite::ZString::operator=(&this->m_sBaseURL, v12);
    OSuite::ZString::~ZString((OSuite::ZString *)&result);
    if ( this->m_pEdmEntityType )
    {
      result.m_Pairs.m_pLists = 0i64;
      OSuite::ZJsonDocument::ZJsonDocument(&result, pReader);
      m_bIsValid = result.m_bIsValid;
      this->m_bHasValidSource = result.m_bIsValid;
      if ( m_bIsValid )
        OSuite::ZAtomBase::ParseJson(this, &result);
      OSuite::ZJsonDocument::~ZJsonDocument(&result);
    }
  }
}

// File Line: 44
// RVA: 0xECD974
bool __fastcall OSuite::ZOFeed::ClassMatch(OSuite::ZOFeed *this, int nClassId)
{
  return OSuite::ZOFeed::s_nClassId == nClassId || OSuite::ZAtomFeed::ClassMatch(this, nClassId);
}

// File Line: 50
// RVA: 0xECD984
void __fastcall OSuite::ZOFeed::ParseJsonValue(OSuite::ZOFeed *this, OSuite::ZString *name, OSuite::ZJsonValue *pJson)
{
  OSuite::TList<OSuite::ZJsonValue *> *p_m_array; // rbx
  OSuite::ZJsonObject *m_object; // r12
  OSuite::ZJsonValue *v7; // r14
  OSuite::ZJsonValue *v8; // r14
  unsigned __int64 m_nIndex; // rdi
  OSuite::ZListBase *m_pListBase; // rbx
  unsigned __int64 v11; // r14
  OSuite::ZJsonObject *v12; // rbx
  OSuite::ZOEntry *v13; // rax
  OSuite::ZAtomEntry *v14; // rax
  OSuite::ZAtomEntry *v15; // rdi
  OSuite::ZError *v16; // rax
  OSuite::ZString v17; // [rsp+20h] [rbp-60h] BYREF
  OSuite::ZString sName; // [rsp+38h] [rbp-48h] BYREF
  void **v19; // [rsp+50h] [rbp-30h]
  OSuite::ZListBase::ZListIteratorBase v20; // [rsp+58h] [rbp-28h] BYREF

  if ( !OSuite::ZString::operator==(name, "d") )
    goto LABEL_22;
  p_m_array = 0i64;
  if ( pJson->m_Type == JSONTYPE_OBJECT )
  {
    m_object = pJson->m_object;
    OSuite::ZString::ZString(&sName, "results");
    v7 = OSuite::ZJsonObject::Value(m_object, &sName);
    OSuite::ZString::~ZString(&sName);
    if ( v7 )
      p_m_array = &v7->m_array;
    OSuite::ZString::ZString(&v17, "__count");
    v8 = OSuite::ZJsonObject::Value(m_object, &v17);
    OSuite::ZString::~ZString(&v17);
    if ( v8 )
      this->m_inlineEntryCount = OSuite::ZString::ToInt(&v8->m_literal);
  }
  else
  {
    if ( pJson->m_Type != JSONTYPE_ARRAY )
    {
LABEL_22:
      OSuite::ZOEdmBase::CleanTempData((int)this);
      return;
    }
    p_m_array = &pJson->m_array;
  }
  if ( !p_m_array )
    goto LABEL_22;
  v20.m_pListBase = 0i64;
  OSuite::ZListBase::ZListIteratorBase::ZListIteratorBase((OSuite::ZListBase::ZListIteratorBase *)&v17, p_m_array);
  v17.OSuite::ZObject::vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable;
  v19 = &OSuite::TConstIterator<OSuite::TList<OSuite::ZOEdmEndRole *>::ZIterator,OSuite::ZOEdmEndRole *,int>::`vftable;
  OSuite::ZListBase::ZListIteratorBase::ZListIteratorBase(&v20, (OSuite::ZListBase::ZListIteratorBase *)&v17);
  v20.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable;
  while ( !OSuite::ZListBase::ZListIteratorBase::AtEnd(&v20) )
  {
    OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)v20.m_pListBase);
    m_nIndex = v20.m_nIndex;
    m_pListBase = v20.m_pListBase;
    v11 = v20.m_nIndex + 1;
    OSuite::TList<OSuite::ZONavigationProperty *>::Grow(
      (OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *)v20.m_pListBase,
      v20.m_nIndex + 1);
    if ( m_nIndex >= m_pListBase->m_nTop )
      m_pListBase->m_nTop = v11;
    v12 = *(OSuite::ZJsonObject **)(*(_QWORD *)(m_pListBase[1].m_nSize + 8 * m_nIndex) + 80i64);
    if ( v12 )
    {
      v13 = (OSuite::ZOEntry *)OSuite::ZObject::operator new(0x180ui64);
      if ( v13 )
      {
        v13->m_sAuthorName.m_pString = 0i64;
        v13->m_sIdentifier.m_pString = 0i64;
        v13->m_sTitle.m_pString = 0i64;
        v13->m_sEditURL.m_pString = 0i64;
        v13->m_sBaseURL.m_pString = 0i64;
        v13->m_currentRequestMutex.m_pInternalMutex = 0i64;
        v13->m_ETag.m_pString = 0i64;
        v13->m_sContentUrl.m_pString = 0i64;
        v13->m_sSummary.m_pString = 0i64;
        v13->m_sContent.m_pString = 0i64;
        v13->m_sFeedURL.m_pString = 0i64;
        v13->m_pCurrentRequest = 0i64;
        v13->m_pEdmEntityType = 0i64;
        v13->m_Properties.m_pList = 0i64;
        v13->m_NavProperties.m_pList = 0i64;
        OSuite::ZOEntry::ZOEntry(v13, this->m_pEdmEntityType, &this->m_sFeedURL);
        v15 = v14;
      }
      else
      {
        v15 = 0i64;
      }
      if ( !v15 )
      {
        v16 = OSuite::TSingleton<OSuite::ZError>::Object();
        OSuite::ZError::SetThreadLastError(v16, ZERROR_OUT_OF_MEMORY, 1);
        return;
      }
      OSuite::ZAtomBase::Parse(v15, v12);
      OSuite::TList<OSuite::ZONavigationProperty *>::Grow(
        (OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *)&this->m_Entries,
        this->m_Entries.m_nTop + 1);
      this->m_Entries.m_pList[this->m_Entries.m_nTop++] = v15;
    }
    OSuite::ZListBase::ZListIteratorBase::Next(&v20);
  }
}

