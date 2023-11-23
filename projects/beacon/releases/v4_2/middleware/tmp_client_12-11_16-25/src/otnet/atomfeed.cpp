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
  OSuite::ZObject *v4; // rdx
  OSuite::ZAtomEntry **v5; // rax

  OSuite::ZAtomBase::ZAtomBase(this);
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZAtomFeed::`vftable;
  OSuite::ZString::ZString(&this->m_sSubTitle);
  OSuite::ZUrl::ZUrl(&this->m_sFeedURL, sFeedUrl);
  OSuite::ZRedBlackTreeBase::ZElementBase::ZElementBase(&this->m_Entries, v4);
  this->m_Entries.m_pList = 0i64;
  this->m_Entries.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuitePrivate::ZPlayerConsumableData::ZRequest *>::`vftable{for `OSuite::ZListBase};
  this->m_Entries.vfptr = (OSuite::IHashableVtbl *)&OSuite::TList<OSuite::ZJsonObject *>::`vftable{for `OSuite::IHashable};
  v5 = (OSuite::ZAtomEntry **)OSuite::ZObject::malloc(&this->m_Entries, 0x80ui64, 0i64);
  this->m_Entries.m_nTop = 0i64;
  this->m_Entries.m_nSize = 16i64;
  this->m_Entries.m_pList = v5;
}

// File Line: 39
// RVA: 0xEC7F40
void __fastcall OSuite::ZAtomFeed::~ZAtomFeed(OSuite::ZAtomFeed *this)
{
  OSuite::TList<OSuite::ZAtomEntry *> *p_m_Entries; // rdi
  unsigned __int64 m_nIndex; // rsi
  OSuite::ZListBase *m_pListBase; // rbx
  unsigned __int64 v5; // rbp
  void (__fastcall ***v6)(_QWORD, __int64); // rcx
  OSuite::ZAtomEntry **m_pList; // rdx
  OSuite::ZAtomEntry **v8; // rax
  OSuite::ZAtomEntry **v9; // rdx
  OSuite::ZListBase::ZListIteratorBase v10; // [rsp+20h] [rbp-38h] BYREF

  v10.m_pListBase = 0i64;
  p_m_Entries = &this->m_Entries;
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZAtomFeed::`vftable;
  OSuite::ZListBase::ZListIteratorBase::ZListIteratorBase(&v10, &this->m_Entries);
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
  m_pList = p_m_Entries->m_pList;
  v10.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable;
  OSuite::ZObject::free(p_m_Entries, m_pList);
  v8 = (OSuite::ZAtomEntry **)OSuite::ZObject::malloc(p_m_Entries, 0x80ui64, 0i64);
  p_m_Entries->m_nTop = 0i64;
  p_m_Entries->m_nSize = 16i64;
  p_m_Entries->m_pList = v8;
  v9 = p_m_Entries->m_pList;
  p_m_Entries->OSuite::ZListBase::OSuite::ZObject::vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuitePrivate::ZPlayerConsumableData::ZRequest *>::`vftable{for `OSuite::ZListBase};
  p_m_Entries->OSuite::IHashable::vfptr = (OSuite::IHashableVtbl *)&OSuite::TList<OSuite::ZJsonObject *>::`vftable{for `OSuite::IHashable};
  OSuite::ZObject::free(p_m_Entries, v9);
  OSuite::ZUrl::~ZUrl(&this->m_sFeedURL);
  OSuite::ZString::~ZString(&this->m_sSubTitle);
  OSuite::ZAtomBase::~ZAtomBase(this);
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
  OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *p_m_Entries; // rbx
  unsigned __int64 v3; // rdi

  p_m_Entries = (OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *)&this->m_Entries;
  v3 = nIndex;
  if ( nIndex >= OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)&this->m_Entries) )
    return 0i64;
  OSuite::TList<OSuite::ZONavigationProperty *>::Grow(p_m_Entries, v3 + 1);
  if ( v3 >= p_m_Entries->m_nTop )
    p_m_Entries->m_nTop = v3 + 1;
  return p_m_Entries->m_pList[v3];
}

// File Line: 121
// RVA: 0xEC80C0
bool __fastcall OSuite::ZAtomFeed::ClassMatch(OSuite::ZAtomFeed *this, int nClassId)
{
  return OSuite::ZAtomFeed::s_nClassId == nClassId || OSuite::ZAtomBase::ClassMatch(this, nClassId);
}

// File Line: 127
// RVA: 0xEC812C
void __fastcall OSuite::ZAtomFeed::NewEntry(OSuite::ZAtomFeed *this, OSuite::ZString *__formal, OSuite::ZString *a3)
{
  OSuite::ZAtomEntry *v4; // rcx

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
    OSuite::ZAtomEntry::ZAtomEntry(v4, &this->m_sFeedURL);
  }
}

