// File Line: 21
// RVA: 0xEDAEAC
void __fastcall OSuite::ZSocketManager::InternalSocket::UnBind(
        OSuite::ZSocketManager::InternalSocket *this,
        unsigned __int64 connectionKeepAliveTimeoutMs)
{
  OSuite::ZSocket *m_socket; // rax
  unsigned __int64 v5; // [rsp+20h] [rbp-20h] BYREF
  unsigned __int64 v6; // [rsp+28h] [rbp-18h] BYREF
  unsigned __int64 v7; // [rsp+30h] [rbp-10h] BYREF
  OSuite::ZClock v8; // [rsp+60h] [rbp+20h] BYREF
  unsigned __int64 clock; // [rsp+70h] [rbp+30h] BYREF
  OSuite::ZClock v10; // [rsp+78h] [rbp+38h] BYREF

  this->m_state = SOCKET_STATE_FREE;
  clock = OSuite::ZClock::_GetClock();
  OSuite::ZClock::ZClock(&v8, &clock);
  this->m_lastActionTime = v8;
  OSuite::ZOEdmBase::CleanTempData((int)&v8);
  v5 = OSuite::ZClock::_TimeToClock(connectionKeepAliveTimeoutMs, UNIT_MILLI);
  OSuite::ZClock::ZClock(&v10, &v5);
  v6 = OSuite::ZClock::_GetClock();
  OSuite::ZClock::ZClock((OSuite::ZClock *)&clock, &v6);
  v7 = v10.m_clock + clock;
  OSuite::ZClock::ZClock(&v8, &v7);
  this->m_maxTime = v8;
  OSuite::ZOEdmBase::CleanTempData((int)&v8);
  OSuite::ZOEdmBase::CleanTempData((int)&clock);
  OSuite::ZOEdmBase::CleanTempData((int)&v10);
  m_socket = this->m_socket;
  m_socket->m_nBytesSent = 0i64;
  m_socket->m_nBytesReceived = 0i64;
}

// File Line: 29
// RVA: 0xEDA878
void __fastcall OSuite::ZSocketManager::InternalSocket::Bind(OSuite::ZSocketManager::InternalSocket *this)
{
  OSuite::ZClock v2; // [rsp+30h] [rbp+8h] BYREF
  unsigned __int64 clock; // [rsp+38h] [rbp+10h] BYREF

  this->m_state = SOCKET_STATE_USED;
  clock = OSuite::ZClock::_GetClock();
  OSuite::ZClock::ZClock(&v2, &clock);
  this->m_lastActionTime = v2;
  OSuite::ZOEdmBase::CleanTempData((int)&v2);
  clock = 0i64;
  OSuite::ZClock::ZClock(&v2, &clock);
  this->m_maxTime = v2;
  OSuite::ZOEdmBase::CleanTempData((int)&v2);
}

// File Line: 36
// RVA: 0x15D8B4C
__int64 dynamic_initializer_for__OSuite::ZSocketManager::m_instance__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__OSuite::ZSocketManager::m_instance__);
}

// File Line: 43
// RVA: 0xEDA640
void __fastcall OSuite::ZSocketManager::ZSocketManager(OSuite::ZSocketManager *this)
{
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZSocketManager::`vftable;
  OSuite::ZDoublyLinkedListBase::ZDoublyLinkedListBase((OSuite::ZRedBlackTreeBase *)&this->m_socketList);
  this->m_socketList.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TDoublyLinkedList<OSuite::ZSocketManager::InternalSocket>::`vftable;
  OSuite::ZMutex::ZMutex(&this->m_Mutex);
  this->m_freeSocket = 0i64;
  this->m_KeepAliveTimeoutMs = 25000i64;
  this->m_MinimalRefreshMs = 1000i64;
  this->m_MaxSocket = 7i64;
}

// File Line: 48
// RVA: 0xEDA6A0
void __fastcall OSuite::ZSocketManager::~ZSocketManager(OSuite::ZSocketManager *this)
{
  OSuite::TDoublyLinkedList<OSuite::ZSocketManager::InternalSocket> *p_m_socketList; // rdi
  __int64 v3; // rbx
  unsigned __int64 Clock; // rax
  void (__fastcall ***v5)(_QWORD, __int64); // rcx
  bool v6; // bl
  _BYTE var40[72]; // [rsp+20h] [rbp-40h] BYREF

  *(_QWORD *)&var40[8] = 0i64;
  *(_QWORD *)&var40[16] = 0i64;
  p_m_socketList = &this->m_socketList;
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZSocketManager::`vftable;
  OSuite::ZDoublyLinkedListBase::ZIteratorBase::ZIteratorBase(
    (OSuite::ZDoublyLinkedListBase::ZIteratorBase *)var40,
    &this->m_socketList,
    this->m_socketList.m_pHead);
  *(_QWORD *)&var40[32] = 0i64;
  *(_QWORD *)&var40[40] = 0i64;
  *(_QWORD *)var40 = &OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable;
  OSuite::ZDoublyLinkedListBase::ZIteratorBase::ZIteratorBase(
    (OSuite::ZDoublyLinkedListBase::ZIteratorBase *)&var40[24],
    p_m_socketList,
    0i64);
  *(_QWORD *)&var40[24] = &OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable;
  while ( 1 )
  {
    v6 = OSuite::ZRedBlackTreeBase::ZIteratorBase::operator bool((OSuite::ZRedBlackTreeBase::ZIteratorBase *)&var40[24]);
    if ( OSuite::ZRedBlackTreeBase::ZIteratorBase::operator bool((OSuite::ZRedBlackTreeBase::ZIteratorBase *)var40) == v6 )
      break;
    v3 = *(_QWORD *)&var40[16];
    if ( *(_DWORD *)(*(_QWORD *)&var40[16] + 40i64) == 1 )
    {
      Clock = OSuite::ZClock::_GetClock();
      OSuite::ZClock::_ClockToTime(Clock - *(_QWORD *)(v3 + 24), UNIT_MILLI);
    }
    else
    {
      v5 = *(void (__fastcall ****)(_QWORD, __int64))(*(_QWORD *)&var40[16] + 48i64);
      if ( v5 )
        (**v5)(v5, 1i64);
    }
    OSuite::ZDoublyLinkedListBase::ZIteratorBase::Next((OSuite::ZDoublyLinkedListBase::ZIteratorBase *)var40);
  }
  OSuite::ZDoublyLinkedListBase::Clear(p_m_socketList);
  OSuite::ZMutex::~ZMutex(&this->m_Mutex);
  p_m_socketList->vfptr = (OSuite::ZObjectVtbl *)&OSuite::TDoublyLinkedList<OSuite::ZSocketManager::InternalSocket>::`vftable;
  OSuite::ZDoublyLinkedListBase::Clear(p_m_socketList);
}

// File Line: 76
// RVA: 0xEDAC1C
OSuite::ZObjectVtbl *__fastcall OSuite::ZSocketManager::TryGetSocket(
        OSuite::ZSocketManager *this,
        OSuite::ZString *sHost,
        int nPort,
        bool *bAlreadyConnected)
{
  OSuite::ZMutex *p_m_Mutex; // rbx
  OSuite::ZString *v8; // r14
  OSuite::ZObjectVtbl *vfptr; // rdi
  OSuite::ZDoublyLinkedListBase::ZElementBase *m_pHead; // r8
  const char *v11; // rax
  OSuite::psock::ipv4addr_t *ResolveAddr; // r8
  OSuite::ZDoublyLinkedListBase::ZElementBase *m_pElement; // r14
  unsigned __int64 Clock; // rax
  unsigned __int64 m_freeSocket; // rax
  bool v16; // al
  int v17; // eax
  OSuite::ZSocket *v18; // rax
  OSuite::ZObjectVtbl *v19; // rax
  OSuite::psock::ipv4addr_t result; // [rsp+28h] [rbp-41h] BYREF
  OSuite::psock::ipv4addr_t Dst; // [rsp+38h] [rbp-31h] BYREF
  OSuite::ZDoublyLinkedListBase::ZIteratorBase v24; // [rsp+48h] [rbp-21h] BYREF
  OSuite::ZSocketManager::InternalSocket v25; // [rsp+60h] [rbp-9h] BYREF

  p_m_Mutex = &this->m_Mutex;
  v8 = sHost;
  vfptr = 0i64;
  OSuite::ZMutex::Lock(&this->m_Mutex);
  if ( !OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)&this->m_socketList) )
    goto LABEL_19;
  m_pHead = this->m_socketList.m_pHead;
  v24.m_pList = 0i64;
  v24.m_pElement = 0i64;
  OSuite::ZDoublyLinkedListBase::ZIteratorBase::ZIteratorBase(&v24, &this->m_socketList, m_pHead);
  v25.m_maxTime.m_clock = 0i64;
  *(_QWORD *)&v25.m_state = 0i64;
  v24.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable;
  OSuite::ZDoublyLinkedListBase::ZIteratorBase::ZIteratorBase(
    (OSuite::ZDoublyLinkedListBase::ZIteratorBase *)&v25,
    &this->m_socketList,
    0i64);
  v25.m_lastActionTime.m_clock = (unsigned __int64)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable;
  while ( !OSuite::ZString::IsNull((OSuite::ZString *)&v24) )
  {
    memset(&Dst, 0, sizeof(Dst));
    v11 = OSuite::ZString::c_str(v8);
    OSuite::psock::getaddrbyname(&Dst, v11);
    ResolveAddr = OSuite::ZSocket::GetResolveAddr((OSuite::ZSocket *)v24.m_pElement[2].vfptr, &result);
    if ( ((unsigned __int8)ResolveAddr->b[3] | (((unsigned __int8)ResolveAddr->b[2] | (((unsigned __int8)ResolveAddr->b[1] | ((unsigned __int8)ResolveAddr->b[0] << 8)) << 8)) << 8)) == ((unsigned __int8)Dst.b[3] | (((unsigned __int8)Dst.b[2] | (((unsigned __int8)Dst.b[1] | ((unsigned __int8)Dst.b[0] << 8)) << 8)) << 8))
      && ResolveAddr->type == Dst.type )
    {
      m_pElement = v24.m_pElement;
      if ( LODWORD(v24.m_pElement[2].vfptr[8].__vecDelDtor) == nPort && !LODWORD(v24.m_pElement[1].m_pPrev) )
      {
        Clock = OSuite::ZClock::_GetClock();
        OSuite::ZClock::_ClockToTime(Clock - (unsigned __int64)m_pElement[1].vfptr, UNIT_MILLI);
        m_freeSocket = this->m_freeSocket;
        if ( m_freeSocket )
          this->m_freeSocket = m_freeSocket - 1;
        OSuite::ZSocketManager::InternalSocket::Bind((OSuite::ZSocketManager::InternalSocket *)&v24.m_pElement[1]);
        vfptr = v24.m_pElement[2].vfptr;
        break;
      }
      v8 = sHost;
    }
    OSuite::ZDoublyLinkedListBase::ZIteratorBase::Next(&v24);
  }
  v25.m_lastActionTime.m_clock = (unsigned __int64)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable;
  v24.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable;
  if ( vfptr )
  {
    v16 = OSuite::ZSocket::VerifyConnection((OSuite::ZSocket *)vfptr);
    *bAlreadyConnected = v16;
    if ( v16 )
    {
      v17 = OSuite::ZSocket::ReceiveByte((OSuite::ZSocket *)vfptr);
      if ( v17 > 0 || v17 == -1 && OSuite::ZSocket::HasFatalError((OSuite::ZSocket *)vfptr) )
      {
        OSuite::ZSocket::Close((OSuite::ZSocket *)vfptr);
        *bAlreadyConnected = 0;
      }
    }
  }
  else
  {
LABEL_19:
    v18 = (OSuite::ZSocket *)OSuite::ZObject::operator new(0x48ui64);
    if ( v18 )
    {
      v18->m_socket = 0i64;
      v18->m_sHost.m_pString = 0i64;
      OSuite::ZSocket::ZSocket(v18);
      vfptr = v19;
    }
    else
    {
      vfptr = 0i64;
    }
    OSuite::ZClock::ZClock(&v25.m_lastActionTime);
    OSuite::ZClock::ZClock(&v25.m_maxTime);
    v25.m_state = SOCKET_STATE_FREE;
    v25.m_socket = (OSuite::ZSocket *)vfptr;
    OSuite::ZSocketManager::InternalSocket::Bind(&v25);
    OSuite::TDoublyLinkedList<OSuite::ZSocketManager::InternalSocket>::Insert(&this->m_socketList, &v25);
    *bAlreadyConnected = 0;
    OSuite::ZOEdmBase::CleanTempData((int)&v25.m_maxTime);
    OSuite::ZOEdmBase::CleanTempData((int)&v25);
  }
  OSuite::ZMutex::Unlock(p_m_Mutex);
  return vfptr;
}

// File Line: 168
// RVA: 0xEDA9F4
void __fastcall OSuite::ZSocketManager::ReleaseSocket(
        OSuite::ZSocketManager *this,
        OSuite::ZSocket *pSocket,
        unsigned __int64 connectionKeepAliveTimeoutMs)
{
  OSuite::ZMutex *p_m_Mutex; // rbx
  OSuite::ZDoublyLinkedListBase::ZElementBase *m_pElement; // rdi
  unsigned __int64 Clock; // rax
  OSuite::ZDoublyLinkedListBase::ZElementBase *m_pHead; // r8
  OSuite::TDoublyLinkedList<OSuite::ZSocketManager::InternalSocket>::ZIterator result; // [rsp+20h] [rbp-49h] BYREF
  OSuite::ZDoublyLinkedListBase::ZIteratorBase v11; // [rsp+38h] [rbp-31h] BYREF
  OSuite::ZSocketManager::InternalSocket v12; // [rsp+50h] [rbp-19h] BYREF
  OSuite::ZDoublyLinkedListBase::ZIteratorBase v13; // [rsp+70h] [rbp+7h] BYREF

  p_m_Mutex = &this->m_Mutex;
  OSuite::ZMutex::Lock(&this->m_Mutex);
  OSuite::ZClock::ZClock(&v12.m_lastActionTime);
  OSuite::ZClock::ZClock(&v12.m_maxTime);
  result.m_pList = 0i64;
  result.m_pElement = 0i64;
  v12.m_socket = pSocket;
  v12.m_state = SOCKET_STATE_USED;
  OSuite::TDoublyLinkedList<OSuite::ZSocketManager::InternalSocket>::Find(&this->m_socketList, &result, &v12);
  if ( OSuite::ZString::IsNull((OSuite::ZString *)&result) )
  {
    if ( pSocket )
      pSocket->vfptr->__vecDelDtor(pSocket, 1i64);
  }
  else
  {
    m_pElement = result.m_pElement;
    Clock = OSuite::ZClock::_GetClock();
    OSuite::ZClock::_ClockToTime(Clock - (unsigned __int64)m_pElement[1].vfptr, UNIT_MILLI);
    if ( connectionKeepAliveTimeoutMs && (pSocket->m_state & 5) == 5 && !OSuite::ZSocket::HasFatalError(pSocket) )
    {
      if ( ++this->m_freeSocket > this->m_MaxSocket )
      {
        m_pHead = this->m_socketList.m_pHead;
        v11.m_pList = 0i64;
        v11.m_pElement = 0i64;
        OSuite::ZDoublyLinkedListBase::ZIteratorBase::ZIteratorBase(&v11, &this->m_socketList, m_pHead);
        v13.m_pList = 0i64;
        v13.m_pElement = 0i64;
        v11.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable;
        OSuite::ZDoublyLinkedListBase::ZIteratorBase::ZIteratorBase(&v13, &this->m_socketList, 0i64);
        v13.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable;
        while ( !OSuite::ZString::IsNull((OSuite::ZString *)&v11) )
        {
          if ( !LODWORD(v11.m_pElement[1].m_pPrev) )
          {
            OSuite::ZSocketManager::Remove(
              this,
              (OSuite::TDoublyLinkedList<OSuite::ZSocketManager::InternalSocket>::ZIterator *)&v11,
              "Maximum of free socket has been reached");
            break;
          }
          OSuite::ZDoublyLinkedListBase::ZIteratorBase::Next(&v11);
        }
      }
      OSuite::ZSocketManager::InternalSocket::UnBind(
        (OSuite::ZSocketManager::InternalSocket *)&result.m_pElement[1],
        connectionKeepAliveTimeoutMs);
    }
    else
    {
      OSuite::ZSocketManager::Remove(this, &result, "Keep alive timeout receive is 0 or socket not longer connected");
    }
  }
  result.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable;
  OSuite::ZOEdmBase::CleanTempData((int)&v12.m_maxTime);
  OSuite::ZOEdmBase::CleanTempData((int)&v12);
  OSuite::ZMutex::Unlock(p_m_Mutex);
}

// File Line: 238
// RVA: 0xEDAF70
void __fastcall OSuite::ZSocketManager::Update(OSuite::ZSocketManager *this)
{
  unsigned __int64 v2; // rax
  OSuite::ZDoublyLinkedListBase::ZElementBase *m_pHead; // r8
  OSuite::ZDoublyLinkedListBase::ZElementBase *m_pElement; // rdi
  OSuite::ZSocket *vfptr; // rcx
  const char *v6; // r8
  unsigned __int64 clock; // [rsp+20h] [rbp-29h] BYREF
  unsigned __int64 v8; // [rsp+28h] [rbp-21h] BYREF
  OSuite::ZClock v9; // [rsp+30h] [rbp-19h] BYREF
  OSuite::ZClock v10; // [rsp+38h] [rbp-11h] BYREF
  int m_pPrev; // [rsp+40h] [rbp-9h]
  OSuite::ZSocket *v12; // [rsp+48h] [rbp-1h]
  OSuite::ZDoublyLinkedListBase::ZIteratorBase v13; // [rsp+50h] [rbp+7h] BYREF
  OSuite::ZDoublyLinkedListBase::ZIteratorBase v14; // [rsp+68h] [rbp+1Fh] BYREF

  if ( (_S1_45 & 1) == 0 )
  {
    _S1_45 |= 1u;
    clock = OSuite::ZClock::_GetClock();
    OSuite::ZClock::ZClock(&internalClock, &clock);
    atexit(OSuite::ZSocketManager::Update_::_2_::_dynamic_atexit_destructor_for__internalClock__);
  }
  v2 = OSuite::ZClock::_GetClock();
  OSuite::ZClock::_ClockToTime(v2 - internalClock.m_clock, UNIT_MILLI);
  v8 = OSuite::ZClock::_GetClock();
  OSuite::ZClock::ZClock((OSuite::ZClock *)&clock, &v8);
  internalClock.m_clock = clock;
  OSuite::ZOEdmBase::CleanTempData((int)&clock);
  if ( OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)&this->m_socketList) )
  {
    OSuite::ZMutex::Lock(&this->m_Mutex);
    m_pHead = this->m_socketList.m_pHead;
    v13.m_pList = 0i64;
    v13.m_pElement = 0i64;
    OSuite::ZDoublyLinkedListBase::ZIteratorBase::ZIteratorBase(&v13, &this->m_socketList, m_pHead);
    v14.m_pList = 0i64;
    v14.m_pElement = 0i64;
    v13.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable;
    OSuite::ZDoublyLinkedListBase::ZIteratorBase::ZIteratorBase(&v14, &this->m_socketList, 0i64);
    v14.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable;
    while ( 1 )
    {
      if ( OSuite::ZString::IsNull((OSuite::ZString *)&v13) )
      {
        OSuite::ZMutex::Unlock(&this->m_Mutex);
        return;
      }
      m_pElement = v13.m_pElement;
      OSuite::ZClock::ZClock(&v9, (const unsigned __int64 *)&v13.m_pElement[1]);
      OSuite::ZClock::ZClock(&v10, (const unsigned __int64 *)&m_pElement[1].m_pNext);
      m_pPrev = (int)m_pElement[1].m_pPrev;
      vfptr = (OSuite::ZSocket *)m_pElement[2].vfptr;
      v12 = vfptr;
      if ( m_pPrev != 1 )
      {
        if ( internalClock.m_clock >= v10.m_clock )
        {
          v6 = "Keep alive timeout has been reached";
LABEL_8:
          OSuite::ZSocketManager::Remove(
            this,
            (OSuite::TDoublyLinkedList<OSuite::ZSocketManager::InternalSocket>::ZIterator *)&v13,
            v6);
          goto LABEL_12;
        }
        if ( !OSuite::ZSocket::VerifyConnection(vfptr) )
        {
          v6 = "Socket is no longer connected";
          goto LABEL_8;
        }
      }
      OSuite::ZDoublyLinkedListBase::ZIteratorBase::Next(&v13);
LABEL_12:
      OSuite::ZOEdmBase::CleanTempData((int)&v10);
      OSuite::ZOEdmBase::CleanTempData((int)&v9);
    }
  }
}

// File Line: 286
// RVA: 0xEDABC0
void __fastcall OSuite::ZSocketManager::Remove(
        OSuite::ZSocketManager *this,
        OSuite::TDoublyLinkedList<OSuite::ZSocketManager::InternalSocket>::ZIterator *socketIt,
        const char *reason)
{
  OSuite::ZObjectVtbl *vfptr; // rcx
  unsigned __int64 m_freeSocket; // rax

  OSuite::ZSocket::Abort((OSuite::ZSocket *)socketIt->m_pElement[2].vfptr, ERR_OK);
  vfptr = socketIt->m_pElement[2].vfptr;
  if ( vfptr )
    (*(void (__fastcall **)(OSuite::ZObjectVtbl *, __int64))vfptr->__vecDelDtor)(vfptr, 1i64);
  OSuite::ZDoublyLinkedListBase::ZIteratorBase::Remove(socketIt);
  m_freeSocket = this->m_freeSocket;
  if ( m_freeSocket )
    this->m_freeSocket = m_freeSocket - 1;
}

