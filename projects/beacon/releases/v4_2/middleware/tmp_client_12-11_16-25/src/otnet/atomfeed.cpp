// File Line: 9
// RVA: 0x15D8ABC
__int64 dynamic_initializer_for__OSuite::ZAtomFeed::s_nClassId__()
{
  __int64 result; // rax

  result = OSuite::ZAtomBase::GenerateClassId();
  OSuite::ZAtomFeed::s_nClassId = result;
  return result;
}

// File Line: 16
// RVA: 0xEC7EAC
void __fastcall OSuite::ZAtomFeed::ZAtomFeed(OSuite::ZAtomFeed *this, OSuite::ZUrl *sFeedUrl)
{
  OSuite::ZUrl *v2; // rbx
  OSuite::ZAtomFeed *v3; // rdi
  OSuite::ZObject *v4; // rdx
  OSuite::ZAtomEntry **v5; // rax

  v2 = sFeedUrl;
  v3 = this;
  OSuite::ZAtomBase::ZAtomBase((OSuite::ZAtomBase *)&this->vfptr);
  v3->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZAtomFeed::`vftable;
  OSuite::ZString::ZString(&v3->m_sSubTitle);
  OSuite::ZUrl::ZUrl(&v3->m_sFeedURL, v2);
  OSuite::ZRedBlackTreeBase::ZElementBase::ZElementBase((OSuite::ZObject *)&v3->m_Entries.vfptr, v4);
  v3->m_Entries.m_pList = 0i64;
  v3->m_Entries.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuitePrivate::ZPlayerConsumableData::ZRequest *>::`vftable{for `OSuite::ZListBase};
  v3->m_Entries.vfptr = (OSuite::IHashableVtbl *)&OSuite::TList<OSuite::ZJsonObject *>::`vftable{for `OSuite::IHashable};
  v5 = (OSuite::ZAtomEntry **)OSuite::ZObject::malloc((OSuite::ZObject *)&v3->m_Entries.vfptr, 0x80ui64, 0i64);
  v3->m_Entries.m_nTop = 0i64;
  v3->m_Entries.m_nSize = 16i64;
  v3->m_Entries.m_pList = v5;
}

// File Line: 39
// RVA: 0xEC7F40
void __fastcall OSuite::ZAtomFeed::~ZAtomFeed(OSuite::ZAtomFeed *this)
{
  OSuite::ZObject *v1; // rdi
  OSuite::ZAtomFeed *v2; // r14
  unsigned __int64 v3; // rsi
  OSuite::ZListBase *v4; // rbx
  unsigned __int64 v5; // rbp
  void (__fastcall ***v6)(_QWORD, signed __int64); // rcx
  OSuite::ZObjectVtbl *v7; // rdx
  OSuite::ZObjectVtbl *v8; // rax
  OSuite::ZObjectVtbl *v9; // rdx
  OSuite::ZListBase::ZListIteratorBase v10; // [rsp+20h] [rbp-38h]

  v10.m_pListBase = 0i64;
  v1 = (OSuite::ZObject *)&this->m_Entries.vfptr;
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZAtomFeed::`vftable;
  v2 = this;
  OSuite::ZListBase::ZListIteratorBase::ZListIteratorBase(&v10, (OSuite::ZListBase *)&this->m_Entries.vfptr);
  v10.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable;
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
  v10.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable;
  OSuite::ZObject::free(v1, v7);
  v8 = (OSuite::ZObjectVtbl *)OSuite::ZObject::malloc(v1, 0x80ui64, 0i64);
  v1[2].vfptr = 0i64;
  v1[1].vfptr = (OSuite::ZObjectVtbl *)16;
  v1[4].vfptr = v8;
  v9 = v1[4].vfptr;
  v1->vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuitePrivate::ZPlayerConsumableData::ZRequest *>::`vftable{for `OSuite::ZListBase};
  v1[3].vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonObject *>::`vftable{for `OSuite::IHashable};
  OSuite::ZObject::free(v1, v9);
  OSuite::ZUrl::~ZUrl(&v2->m_sFeedURL);
  OSuite::ZString::~ZString(&v2->m_sSubTitle);
  OSuite::ZAtomBase::~ZAtomBase((OSuite::ZAtomBase *)&v2->vfptr);
}

// File Line: 57
// RVA: 0xEC81D0
unsigned __int64 __fastcall OSuite::ZAtomFeed::TotalEntries(OSuite::ZAtomFeed *this)
{
  return OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)&this->m_Entries);
}

// File Line: 64
// RVA: 0xEC80D0
OSuite::ZRedBlackTreeBase::ZElementBase *__fastcall OSuite::ZAtomFeed::GetEntry(OSuite::ZAtomFeed *this, int nIndex)
{
  OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *v2; // rbx
  unsigned __int64 v3; // rdi

  v2 = (OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *)&this->m_Entries;
  v3 = nIndex;
  if ( nIndex >= OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)&this->m_Entries) )
    return 0i64;
  OSuite::TList<OSuite::ZONavigationProperty *>::Grow(v2, v3 + 1);
  if ( v3 >= v2->m_nTop )
    v2->m_nTop = v3 + 1;
  return v2->m_pList[v3];
}

// File Line: 121
// RVA: 0xEC80C0
bool __fastcall OSuite::ZAtomFeed::ClassMatch(OSuite::ZAtomFeed *this, int nClassId)
{
  bool result; // al

  if ( OSuite::ZAtomFeed::s_nClassId == nClassId )
    result = 1;
  else
    result = OSuite::ZAtomBase::ClassMatch((OSuite::ZAtomBase *)&this->vfptr, nClassId);
  return result;
}

// File Line: 127
// RVA: 0xEC812C
void __fastcall OSuite::ZAtomFeed::NewEntry(OSuite::ZAtomFeed *this, OSuite::ZString *__formal, OSuite::ZString *a3)
{
  OSuite::ZAtomFeed *v3; // rbx
  OSuite::ZAtomEntry *v4; // rcx

  v3 = this;
  v4 = (OSuite::ZAtomEntry *)OSuite::ZObject::operator new(0x128ui64);
  if ( v4 )
  {
    v4->m_sAuthorName.m_pString = 0i64;
    v4->m_sIdentifier.m_pString = 0i64;
    v4->m_sTitle.m_pString = 0i64;
    v4->m_sEditURL.m_pString = 0i64;
    v4->m_sBaseURL.m_pString = 0i64;
    v4->m_currentRequestMutex.m_pInternalMutex = 0i64;
    v4->m_ETag.m_pString = 0i64;
    v4->m_sContentUrl.m_pString = 0i64;
    v4->m_sSummary.m_pString = 0i64;
    v4->m_sContent.m_pString = 0i64;
    v4->m_sFeedURL.m_pString = 0i64;
    v4->m_pCurrentRequest = 0i64;
    OSuite::ZAtomEntry::ZAtomEntry(v4, &v3->m_sFeedURL);
  }
}

