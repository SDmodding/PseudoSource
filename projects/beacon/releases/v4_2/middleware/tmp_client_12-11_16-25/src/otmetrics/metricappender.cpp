// File Line: 24
// RVA: 0x15D8A88
__int64 dynamic_initializer_for__OSuite::ZMetricAppender::m_startTime__()
{
  OSuite::ZClock::ZClock(&OSuite::ZMetricAppender::m_startTime);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__OSuite::ZMetricAppender::m_startTime__);
}

// File Line: 47
// RVA: 0xEC1858
OSuite::ZMetricAppender *__fastcall OSuite::ZMetricAppender::CreateAppender(
        const char *pUrl,
        const char *pszPublicIpAddress,
        unsigned __int64 nBytesPerSecond)
{
  unsigned __int64 v3; // rdi
  char v6; // si
  OSuite::ZHttpTransmitter *v8; // rax
  OSuite::ZHttpTransmitter *v9; // rbx
  OSuite::ZString *v10; // rax
  OSuite::ZHttpTransmitter *v11; // rax
  OSuite::ZHttpTransmitter *v12; // rbx
  OSuite::ZMetricAppender *v13; // rax
  unsigned __int64 v14; // rax
  OSuite::ZMutex *v15; // rbx
  unsigned __int64 clock; // [rsp+20h] [rbp-38h] BYREF
  OSuite::ZString v18; // [rsp+28h] [rbp-30h] BYREF
  OSuite::ZClock v19; // [rsp+78h] [rbp+20h] BYREF

  v3 = 0i64;
  v6 = 0;
  LODWORD(v19.m_clock) = 0;
  clock = OSuite::ZClock::_GetClock();
  OSuite::ZClock::ZClock(&v19, &clock);
  OSuite::ZMetricAppender::m_startTime.m_clock = v19.m_clock;
  OSuite::ZOEdmBase::CleanTempData((int)&v19);
  v8 = (OSuite::ZHttpTransmitter *)OSuite::ZObject::operator new(0x160ui64);
  v9 = v8;
  if ( v8 )
  {
    v8->m_url.m_sProtocol.m_pString = 0i64;
    v8->m_url.m_sHost.m_pString = 0i64;
    v8->m_url.m_sFakeHost.m_pString = 0i64;
    v8->m_url.m_sPath.m_pString = 0i64;
    v8->m_url.m_urlParameters.m_parameters.m_pTop = 0i64;
    v8->m_url.m_urlParameters.m_arrayParameters.m_pTop = 0i64;
    v8->m_pHttpRequest = 0i64;
    v8->m_sentHttpRequest.m_pList = 0i64;
    v8->m_mutex.m_pInternalMutex = 0i64;
    v6 = 1;
    OSuite::ZString::ZString(&v18, pUrl);
    OSuite::ZHttpTransmitter::ZHttpTransmitter(v9, v10);
    v12 = v11;
  }
  else
  {
    v12 = 0i64;
  }
  if ( (v6 & 1) != 0 )
    OSuite::ZString::~ZString(&v18);
  OSuite::ZHttpTransmitter::ThrottleBandwidth(v12, nBytesPerSecond);
  v13 = (OSuite::ZMetricAppender *)OSuite::ZObject::operator new(0xC8ui64);
  if ( v13 )
  {
    v13->m_mutex.m_pInternalMutex = 0i64;
    v13->m_Properties.m_propsMapA.m_pLists = 0i64;
    v13->m_Properties.m_propsMapB.m_pLists = 0i64;
    v13->m_Properties.m_pOldProps = 0i64;
    v13->m_Properties.m_pNewProps = 0i64;
    v13->m_Properties.m_Mutex.m_pInternalMutex = 0i64;
    v13->m_sDestinationTable.m_pString = 0i64;
    v13->m_pTransmitter = 0i64;
    OSuite::ZMetricAppender::ZMetricAppender(v13, v12, pszPublicIpAddress);
    v3 = v14;
    v19.m_clock = v14;
  }
  else
  {
    v19.m_clock = 0i64;
  }
  v15 = OSuite::ZMetricAppender::m_appenderListMutex;
  OSuite::ZMutex::Lock(OSuite::ZMetricAppender::m_appenderListMutex);
  OSuite::TDoublyLinkedList<OSuite::ZMetricAppender *>::Append(
    (OSuite::TDoublyLinkedList<OSuite::ManagedCallback *> *)OSuite::ZMetricAppender::m_appenderList,
    (OSuite::ManagedCallback **)&v19);
  OSuite::ZMutex::Unlock(v15);
  return (OSuite::ZMetricAppender *)v3;
}

// File Line: 79
// RVA: 0xEC1B5C
void __fastcall OSuite::ZMetricAppender::ReleaseAppender(OSuite::ZMetricAppender *pMetricAppender)
{
  OSuite::ZMutex *v2; // rbx
  OSuite::TDoublyLinkedList<OSuite::ZMetricAppender *> *v3; // rsi
  OSuite::ZDoublyLinkedListBase::ZElementBase *m_pHead; // rdx

  OSuite::ZMetricAppender::Flush(pMetricAppender);
  v2 = OSuite::ZMetricAppender::m_appenderListMutex;
  OSuite::ZMutex::Lock(OSuite::ZMetricAppender::m_appenderListMutex);
  v3 = OSuite::ZMetricAppender::m_appenderList;
  if ( !OSuite::ZRedBlackTreeBase::IsEmpty((OSuite::ZRedBlackTreeBase *)OSuite::ZMetricAppender::m_appenderList) )
  {
    m_pHead = v3->m_pHead;
    while ( (OSuite::ZMetricAppender *)m_pHead[1].vfptr != pMetricAppender )
    {
      m_pHead = m_pHead->m_pNext;
      if ( m_pHead == v3->m_pHead )
      {
        m_pHead = 0i64;
        break;
      }
    }
    if ( m_pHead )
      OSuite::ZDoublyLinkedListBase::DeleteElement(v3, m_pHead);
  }
  OSuite::ZMutex::Unlock(v2);
  if ( pMetricAppender )
    pMetricAppender->vfptr->__vecDelDtor(pMetricAppender, 1i64);
}

// File Line: 91
// RVA: 0xEC1A40
void OSuite::ZMetricAppender::Init(void)
{
  OSuite::ZMutex *v0; // rax
  OSuite::ZMutex *v1; // rax
  OSuite::ZRedBlackTreeBase *v2; // rax
  OSuite::TDoublyLinkedList<OSuite::ZMetricAppender *> *v3; // rbx

  if ( !OSuite::ZMetricAppender::m_appenderListMutex )
  {
    v0 = (OSuite::ZMutex *)OSuite::ZObject::operator new(0x18ui64);
    if ( v0 )
    {
      v0->m_pInternalMutex = 0i64;
      OSuite::ZMutex::ZMutex(v0);
      OSuite::ZMetricAppender::m_appenderListMutex = v1;
    }
    else
    {
      OSuite::ZMetricAppender::m_appenderListMutex = 0i64;
    }
  }
  if ( !OSuite::ZMetricAppender::m_appenderList )
  {
    v2 = (OSuite::ZRedBlackTreeBase *)OSuite::ZObject::operator new(0x18ui64);
    v3 = (OSuite::TDoublyLinkedList<OSuite::ZMetricAppender *> *)v2;
    if ( v2 )
    {
      v2->m_pTop = 0i64;
      OSuite::ZDoublyLinkedListBase::ZDoublyLinkedListBase(v2);
      v3->vfptr = (OSuite::ZObjectVtbl *)&OSuite::TDoublyLinkedList<OSuite::ZSocketManager::InternalSocket>::`vftable;
      OSuite::ZMetricAppender::m_appenderList = v3;
    }
    else
    {
      OSuite::ZMetricAppender::m_appenderList = 0i64;
    }
  }
}

// File Line: 99
// RVA: 0xEC1C60
void OSuite::ZMetricAppender::UnInit(void)
{
  OSuite::ZRedBlackTreeBase::IsEmpty((OSuite::ZRedBlackTreeBase *)OSuite::ZMetricAppender::m_appenderList);
  if ( OSuite::ZMetricAppender::m_appenderList )
    OSuite::ZMetricAppender::m_appenderList->vfptr->__vecDelDtor(OSuite::ZMetricAppender::m_appenderList, 1i64);
  if ( OSuite::ZMetricAppender::m_appenderListMutex )
    OSuite::ZMetricAppender::m_appenderListMutex->vfptr->__vecDelDtor(
      OSuite::ZMetricAppender::m_appenderListMutex,
      1i64);
}

// File Line: 106
// RVA: 0xEC1CA4
void OSuite::ZMetricAppender::Update(void)
{
  OSuite::ZMutex *v0; // rbx
  void *(__fastcall *vecDelDtor)(OSuite::ZObject *, unsigned int); // rdi
  unsigned __int64 Clock; // rax
  unsigned __int64 v3; // rax
  OSuite::ZMetricAppender *vfptr; // rcx
  OSuite::ZDoublyLinkedListBase::ZIteratorBase v5; // [rsp+20h] [rbp-40h] BYREF
  OSuite::ZDoublyLinkedListBase::ZIteratorBase v6; // [rsp+38h] [rbp-28h] BYREF

  v0 = OSuite::ZMetricAppender::m_appenderListMutex;
  OSuite::ZMutex::Lock(OSuite::ZMetricAppender::m_appenderListMutex);
  v5.m_pList = 0i64;
  v5.m_pElement = 0i64;
  OSuite::ZDoublyLinkedListBase::ZIteratorBase::ZIteratorBase(
    &v5,
    OSuite::ZMetricAppender::m_appenderList,
    OSuite::ZMetricAppender::m_appenderList->m_pHead);
  v6.m_pList = 0i64;
  v6.m_pElement = 0i64;
  v5.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable;
  OSuite::ZDoublyLinkedListBase::ZIteratorBase::ZIteratorBase(&v6, OSuite::ZMetricAppender::m_appenderList, 0i64);
  v6.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable;
  while ( !OSuite::ZString::IsNull((OSuite::ZString *)&v5) )
  {
    vecDelDtor = v5.m_pElement[1].vfptr[24].__vecDelDtor;
    Clock = OSuite::ZClock::_GetClock();
    v3 = OSuite::ZClock::_ClockToTime(Clock - *((_QWORD *)vecDelDtor + 4), UNIT_SECONDS);
    vfptr = (OSuite::ZMetricAppender *)v5.m_pElement[1].vfptr;
    if ( v3 > vfptr->m_nTimeoutSecond )
      OSuite::ZMetricAppender::Flush(vfptr);
    OSuite::ZDoublyLinkedListBase::ZIteratorBase::Next(&v5);
  }
  OSuite::ZMutex::Unlock(v0);
}

// File Line: 129
// RVA: 0xEC1544
void __fastcall OSuite::ZMetricAppender::ZMetricAppender(
        OSuite::ZMetricAppender *this,
        OSuite::ITransmitter *pTransmitter,
        const char *pszPublicIpAddress)
{
  OSuite::ZOnlineSuite *v6; // rbp
  OSuite::IGameConfig *GameConfig; // rbx
  const char *v8; // rax
  const char *v9; // rax
  const char *v10; // rax
  const char *v11; // rax
  const char *SessionId; // rax
  const char *v13; // rax
  const char *Platform; // rax
  const char *v15; // rax
  const char *v16; // rax

  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZMetricAppender::`vftable;
  OSuite::ZMutex::ZMutex(&this->m_mutex);
  OSuite::ZMetricProperties::ZMetricProperties(&this->m_Properties);
  OSuite::ZString::ZString(&this->m_sDestinationTable);
  this->m_nTransmitMemoryThreshold = 0x10000i64;
  this->m_nTimeoutSecond = 300i64;
  this->m_pTransmitter = pTransmitter;
  v6 = OSuite::ZOnlineSuite::Instance();
  GameConfig = OSuite::ZOnlineSuite::GetGameConfig(v6);
  if ( !GameConfig->vfptr->IsFinal(GameConfig) )
  {
    v8 = (const char *)GameConfig->vfptr->BuildId(GameConfig);
    OSuite::ZMetricProperties::SetProperty(&this->m_Properties, OSuite::ZMetricAppender::BuildIdPropertyName, v8);
    v9 = OSuitePrivate::MacAddress();
    OSuite::ZMetricProperties::SetProperty(&this->m_Properties, OSuite::ZMetricAppender::MACIDPropertyName, v9);
    v10 = OSuitePrivate::MachineId();
    OSuite::ZMetricProperties::SetProperty(&this->m_Properties, OSuite::ZMetricAppender::HNameIDPropertyName, v10);
    v11 = OSuitePrivate::Target();
    OSuite::ZMetricProperties::SetProperty(&this->m_Properties, OSuite::ZMetricAppender::TargetIDPropertyName, v11);
    OSuite::ZMetricProperties::SetProperty(
      &this->m_Properties,
      OSuite::ZMetricAppender::OSProfileIDPropertyName,
      "official");
    OSuite::ZMetricProperties::SetProperty(
      &this->m_Properties,
      OSuite::ZMetricAppender::OSVersionIDPropertyName,
      "4.2.14.47540");
  }
  SessionId = OSuite::ZOnlineSuite::GetSessionId(v6);
  OSuite::ZMetricProperties::SetProperty(&this->m_Properties, OSuite::ZMetricAppender::SIDPropertyName, SessionId);
  v13 = GameConfig->vfptr->Version(GameConfig);
  OSuite::ZMetricProperties::SetProperty(&this->m_Properties, OSuite::ZMetricAppender::PVersionIDPropertyName, v13);
  Platform = OSuitePrivate::GetPlatform();
  OSuite::ZMetricProperties::SetProperty(&this->m_Properties, OSuite::ZMetricAppender::HIDPropertyName, Platform);
  v15 = OSuitePrivate::Locale();
  OSuite::ZMetricProperties::SetProperty(&this->m_Properties, OSuite::ZMetricAppender::RegionPropertyName, v15);
  if ( !pszPublicIpAddress )
    pszPublicIpAddress = OSuite::ZMetricAppender::DefaultPublicIpAddress;
  OSuite::ZMetricProperties::SetProperty(
    &this->m_Properties,
    OSuite::ZMetricAppender::IPPropertyName,
    pszPublicIpAddress);
  v16 = (const char *)(*((__int64 (__fastcall **)(OSuite::IGameConfig *))&GameConfig->vfptr->BuildId + 1))(GameConfig);
  OSuite::ZMetricProperties::SetProperty(&this->m_Properties, OSuite::ZMetricAppender::PIDPropertyName, v16);
}

// File Line: 153
// RVA: 0xEC1718
void __fastcall OSuite::ZMetricAppender::~ZMetricAppender(OSuite::ZMetricAppender *this)
{
  OSuite::ITransmitter *m_pTransmitter; // rcx

  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZMetricAppender::`vftable;
  m_pTransmitter = this->m_pTransmitter;
  if ( m_pTransmitter )
    m_pTransmitter->vfptr->__vecDelDtor(m_pTransmitter, 1u);
  OSuite::ZString::~ZString(&this->m_sDestinationTable);
  OSuite::ZMetricProperties::~ZMetricProperties(&this->m_Properties);
  OSuite::ZMutex::~ZMutex(&this->m_mutex);
}

// File Line: 159
// RVA: 0xEC1794
bool __fastcall OSuite::ZMetricAppender::AddMetric(OSuite::ZMetricAppender *this, OSuite::ZMetric *pMetric)
{
  OSuite::ZMutex::Lock(&this->m_mutex);
  LOBYTE(pMetric) = ((__int64 (__fastcall *)(OSuite::ITransmitter *, OSuite::ZMetricAppender *, OSuite::ZMetric *))this->m_pTransmitter->vfptr[2].__vecDelDtor)(
                      this->m_pTransmitter,
                      this,
                      pMetric);
  OSuite::ZMutex::Unlock(&this->m_mutex);
  return (char)pMetric;
}

// File Line: 169
// RVA: 0xEC1AC8
OSuite::ZMetric *__fastcall OSuite::ZMetricAppender::NewMetric(OSuite::ZMetricAppender *this, const char *sName)
{
  char v2; // bl
  OSuite::ZMetric *v4; // rax
  OSuite::ZMetric *v5; // rdi
  __int64 v6; // rax
  __int64 v7; // rdi
  OSuite::ZString sNamea; // [rsp+20h] [rbp-28h] BYREF

  v2 = 0;
  if ( !OSuite::ZMetricProperties::Valid(&this->m_Properties) )
    return 0i64;
  v4 = (OSuite::ZMetric *)OSuite::ZObject::operator new(0x48ui64);
  v5 = v4;
  if ( v4 )
  {
    v4->m_sName.m_pString = 0i64;
    v4->m_attributes.m_pTop = 0i64;
    OSuite::ZString::ZString(&sNamea, sName);
    v2 = 1;
    OSuite::ZMetric::ZMetric(v5, &sNamea, &OSuite::ZMetricAppender::m_startTime);
    v7 = v6;
  }
  else
  {
    v7 = 0i64;
  }
  if ( (v2 & 1) != 0 )
    OSuite::ZString::~ZString(&sNamea);
  return (OSuite::ZMetric *)v7;
}

// File Line: 185
// RVA: 0xEC19D4
void __fastcall OSuite::ZMetricAppender::Flush(OSuite::ZMetricAppender *this)
{
  char v2; // al
  OSuite::ITransmitter *m_pTransmitter; // rcx
  bool v4; // zf
  OSuite::ZObjectVtbl *vfptr; // rax

  OSuite::ZMutex::Lock(&this->m_mutex);
  v2 = ((__int64 (__fastcall *)(OSuite::ITransmitter *, OSuite::ZMetricAppender *, _QWORD))this->m_pTransmitter->vfptr[2].__vecDelDtor)(
         this->m_pTransmitter,
         this,
         0i64);
  m_pTransmitter = this->m_pTransmitter;
  v4 = v2 == 0;
  vfptr = m_pTransmitter->vfptr;
  if ( v4 )
    ((void (*)(void))vfptr[3].__vecDelDtor)();
  else
    vfptr[1].__vecDelDtor(m_pTransmitter, (unsigned int)this);
  OSuite::ZMutex::Unlock(&this->m_mutex);
}

// File Line: 196
// RVA: 0xEC1C4C
void __fastcall OSuite::ZMetricAppender::SetPlayerUID(OSuite::ZMetricAppender *this, const char *sValue)
{
  OSuite::ZMetricProperties::SetProperty(&this->m_Properties, OSuite::ZMetricAppender::PlayerUIDPropertyName, sValue);
}

// File Line: 206
// RVA: 0xEC1A34
const char *__fastcall OSuite::ZMetricAppender::GetProperty(OSuite::ZMetricAppender *this, const char *sName)
{
  return OSuite::ZMetricProperties::GetProperty(&this->m_Properties, sName);
}

// File Line: 216
// RVA: 0xEC1A2C
OSuite::ZMetricProperties *__fastcall OSuite::ZMetricAppender::GetProperties(OSuite::ZMetricAppender *this)
{
  return &this->m_Properties;
}

// File Line: 221
// RVA: 0xEC1BE4
void __fastcall OSuite::ZMetricAppender::SetDestinationTable(OSuite::ZMetricAppender *this, const char *sTableName)
{
  const char *v3; // rax
  OSuite::ZString that; // [rsp+20h] [rbp-28h] BYREF

  OSuite::ZString::ZString(&that, sTableName);
  OSuite::ZString::operator=(&this->m_sDestinationTable, &that);
  OSuite::ZString::~ZString(&that);
  if ( OSuite::ZString::operator bool(&this->m_sDestinationTable) )
  {
    v3 = OSuite::ZString::c_str(&this->m_sDestinationTable);
    OSuite::ZMetricProperties::SetProperty(&this->m_Properties, OSuite::ZMetricAppender::DestinationTableName, v3);
  }
}

