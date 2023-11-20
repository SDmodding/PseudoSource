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
  OSuite::IReader *v3; // rsi
  OSuite::ZUrl *v4; // rdi
  OSuite::ZOFeed *v5; // rbx
  OSuite::ZOnlineSuite *v6; // rax
  OSuite::ZWebServiceClient *v7; // rax
  OSuite::ZWebServiceClient *v8; // rbp
  OSuite::ZOMetadata *v9; // rax
  OSuite::ZOEdmEntityType *v10; // rax
  OSuite::ZUrl *v11; // rax
  OSuite::ZString *v12; // rax
  char v13; // cl
  OSuite::ZString result; // [rsp+20h] [rbp-58h]
  char v15; // [rsp+48h] [rbp-30h]

  v3 = pReader;
  v4 = sFeedUrl;
  v5 = this;
  OSuite::ZAtomFeed::ZAtomFeed((OSuite::ZAtomFeed *)&this->vfptr, sFeedUrl);
  v5->m_inlineEntryCount = -1;
  v5->m_pEdmEntityType = 0i64;
  v5->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZOFeed::`vftable;
  v6 = OSuite::ZOnlineSuite::Instance();
  v7 = OSuite::ZOnlineSuite::GetForUrl(v6, v4);
  v8 = v7;
  if ( v7 )
  {
    v9 = OSuite::ZWebServiceClient::Metadata(v7);
    v10 = OSuite::ZOMetadata::EntityTypeForUrl(v9, v4);
    v5->m_bHasValidSource = 0;
    v5->m_pEdmEntityType = v10;
    v11 = OSuite::ZWebServiceClient::GetBaseUrl(v8);
    v12 = OSuite::ZUrl::ToString(v11, &result, 0);
    OSuite::ZString::operator=(&v5->m_sBaseURL, v12);
    OSuite::ZString::~ZString(&result);
    if ( v5->m_pEdmEntityType )
    {
      result.m_pString = 0i64;
      OSuite::ZJsonDocument::ZJsonDocument((OSuite::ZJsonDocument *)&result, v3);
      v13 = v15;
      v5->m_bHasValidSource = v15;
      if ( v13 )
        OSuite::ZAtomBase::ParseJson((OSuite::ZAtomBase *)&v5->vfptr, (OSuite::ZJsonObject *)&result);
      OSuite::ZJsonDocument::~ZJsonDocument((OSuite::ZJsonDocument *)&result);
    }
  }
}

// File Line: 44
// RVA: 0xECD974
bool __fastcall OSuite::ZOFeed::ClassMatch(OSuite::ZOFeed *this, int nClassId)
{
  bool result; // al

  if ( OSuite::ZOFeed::s_nClassId == nClassId )
    result = 1;
  else
    result = OSuite::ZAtomFeed::ClassMatch((OSuite::ZAtomFeed *)&this->vfptr, nClassId);
  return result;
}

// File Line: 50
// RVA: 0xECD984
void __fastcall OSuite::ZOFeed::ParseJsonValue(OSuite::ZOFeed *this, OSuite::ZString *name, OSuite::ZJsonValue *pJson)
{
  OSuite::ZOFeed *v3; // rsi
  OSuite::ZJsonValue *v4; // rdi
  OSuite::ZListBase *v5; // rbx
  OSuite::ZJsonObject *v6; // r12
  OSuite::ZJsonValue *v7; // r14
  OSuite::ZJsonValue *v8; // r14
  unsigned __int64 v9; // rdi
  OSuite::ZListBase *v10; // rbx
  unsigned __int64 v11; // r14
  OSuite::ZJsonObject *v12; // rbx
  OSuite::ZOEntry *v13; // rax
  OSuite::ZAtomBase *v14; // rax
  OSuite::ZAtomBase *v15; // rdi
  OSuite::ZError *v16; // rax
  OSuite::ZString v17; // [rsp+20h] [rbp-60h]
  OSuite::ZString sName; // [rsp+38h] [rbp-48h]
  void **v19; // [rsp+50h] [rbp-30h]
  OSuite::ZListBase::ZListIteratorBase v20; // [rsp+58h] [rbp-28h]

  v3 = this;
  v4 = pJson;
  if ( !OSuite::ZString::operator==(name, "d") )
    goto LABEL_22;
  v5 = 0i64;
  if ( v4->m_Type == 1 )
  {
    v6 = v4->m_object;
    OSuite::ZString::ZString(&sName, "results");
    v7 = OSuite::ZJsonObject::Value(v6, &sName);
    OSuite::ZString::~ZString(&sName);
    if ( v7 )
      v5 = (OSuite::ZListBase *)&v7->m_array.vfptr;
    OSuite::ZString::ZString(&v17, "__count");
    v8 = OSuite::ZJsonObject::Value(v6, &v17);
    OSuite::ZString::~ZString(&v17);
    if ( v8 )
      v3->m_inlineEntryCount = OSuite::ZString::ToInt(&v8->m_literal);
  }
  else
  {
    if ( v4->m_Type != 2 )
    {
LABEL_22:
      OSuite::ZOEdmBase::CleanTempData((int)v3);
      return;
    }
    v5 = (OSuite::ZListBase *)&v4->m_array.vfptr;
  }
  if ( !v5 )
    goto LABEL_22;
  v20.m_pListBase = 0i64;
  OSuite::ZListBase::ZListIteratorBase::ZListIteratorBase((OSuite::ZListBase::ZListIteratorBase *)&v17, v5);
  v17.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable;
  v19 = &OSuite::TConstIterator<OSuite::TList<OSuite::ZOEdmEndRole *>::ZIterator,OSuite::ZOEdmEndRole *,int>::`vftable;
  OSuite::ZListBase::ZListIteratorBase::ZListIteratorBase(&v20, (OSuite::ZListBase::ZListIteratorBase *)&v17);
  v20.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable;
  while ( !OSuite::ZListBase::ZListIteratorBase::AtEnd(&v20) )
  {
    OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)v20.m_pListBase);
    v9 = v20.m_nIndex;
    v10 = v20.m_pListBase;
    v11 = v20.m_nIndex + 1;
    OSuite::TList<OSuite::ZONavigationProperty *>::Grow(
      (OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *)v20.m_pListBase,
      v20.m_nIndex + 1);
    if ( v9 >= v10->m_nTop )
      v10->m_nTop = v11;
    v12 = *(OSuite::ZJsonObject **)(*(_QWORD *)(v10[1].m_nSize + 8 * v9) + 80i64);
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
        OSuite::ZOEntry::ZOEntry(v13, v3->m_pEdmEntityType, &v3->m_sFeedURL);
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
        (OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *)&v3->m_Entries,
        v3->m_Entries.m_nTop + 1);
      v3->m_Entries.m_pList[v3->m_Entries.m_nTop++] = (OSuite::ZAtomEntry *)v15;
    }
    OSuite::ZListBase::ZListIteratorBase::Next(&v20);
  }
}

