// File Line: 21
// RVA: 0xEDAEAC
void __fastcall OSuite::ZSocketManager::InternalSocket::UnBind(OSuite::ZSocketManager::InternalSocket *this, unsigned __int64 connectionKeepAliveTimeoutMs)
{
  unsigned __int64 v2; // rbx
  OSuite::ZSocketManager::InternalSocket *v3; // rdi
  OSuite::ZSocket *v4; // rax
  unsigned __int64 v5; // [rsp+20h] [rbp-20h]
  unsigned __int64 v6; // [rsp+28h] [rbp-18h]
  unsigned __int64 v7; // [rsp+30h] [rbp-10h]
  OSuite::ZClock v8; // [rsp+60h] [rbp+20h]
  unsigned __int64 clock; // [rsp+70h] [rbp+30h]
  OSuite::ZClock v10; // [rsp+78h] [rbp+38h]

  this->m_state = 0;
  v2 = connectionKeepAliveTimeoutMs;
  v3 = this;
  clock = OSuite::ZClock::_GetClock();
  OSuite::ZClock::ZClock(&v8, &clock);
  v3->m_lastActionTime = v8;
  OSuite::ZOEdmBase::CleanTempData((unsigned __int64)&v8);
  v5 = OSuite::ZClock::_TimeToClock(v2, UNIT_MILLI);
  OSuite::ZClock::ZClock(&v10, &v5);
  v6 = OSuite::ZClock::_GetClock();
  OSuite::ZClock::ZClock((OSuite::ZClock *)&clock, &v6);
  v7 = v10.m_clock + clock;
  OSuite::ZClock::ZClock(&v8, &v7);
  v3->m_maxTime = v8;
  OSuite::ZOEdmBase::CleanTempData((unsigned __int64)&v8);
  OSuite::ZOEdmBase::CleanTempData((unsigned __int64)&clock);
  OSuite::ZOEdmBase::CleanTempData((unsigned __int64)&v10);
  v4 = v3->m_socket;
  v4->m_nBytesSent = 0i64;
  v4->m_nBytesReceived = 0i64;
}

// File Line: 29
// RVA: 0xEDA878
void __fastcall OSuite::ZSocketManager::InternalSocket::Bind(OSuite::ZSocketManager::InternalSocket *this)
{
  OSuite::ZSocketManager::InternalSocket *v1; // rbx
  OSuite::ZClock v2; // [rsp+30h] [rbp+8h]
  unsigned __int64 clock; // [rsp+38h] [rbp+10h]

  v1 = this;
  this->m_state = 1;
  clock = OSuite::ZClock::_GetClock();
  OSuite::ZClock::ZClock(&v2, &clock);
  v1->m_lastActionTime = v2;
  OSuite::ZOEdmBase::CleanTempData((unsigned __int64)&v2);
  clock = 0i64;
  OSuite::ZClock::ZClock(&v2, &clock);
  v1->m_maxTime = v2;
  OSuite::ZOEdmBase::CleanTempData((unsigned __int64)&v2);
}

// File Line: 36
// RVA: 0x15D8B4C
__int64 dynamic_initializer_for__OSuite::ZSocketManager::m_instance__()
{
  return atexit(dynamic_atexit_destructor_for__OSuite::ZSocketManager::m_instance__);
}

// File Line: 43
// RVA: 0xEDA640
void __fastcall OSuite::ZSocketManager::ZSocketManager(OSuite::ZSocketManager *this)
{
  OSuite::ZSocketManager *v1; // rdi

  v1 = this;
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZSocketManager::`vftable;
  OSuite::ZDoublyLinkedListBase::ZDoublyLinkedListBase((OSuite::ZRedBlackTreeBase *)&this->m_socketList);
  v1->m_socketList.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TDoublyLinkedList<OSuite::ZSocketManager::InternalSocket>::`vftable;
  OSuite::ZMutex::ZMutex(&v1->m_Mutex);
  v1->m_freeSocket = 0i64;
  v1->m_KeepAliveTimeoutMs = 25000i64;
  v1->m_MinimalRefreshMs = 1000i64;
  v1->m_MaxSocket = 7i64;
}

// File Line: 48
// RVA: 0xEDA6A0
void __fastcall OSuite::ZSocketManager::~ZSocketManager(OSuite::ZSocketManager *this)
{
  OSuite::ZDoublyLinkedListBase *v1; // rdi
  OSuite::ZSocketManager *v2; // rsi
  OSuite::ZDoublyLinkedListBase::ZElementBase *v3; // rbx
  unsigned __int64 v4; // rax
  OSuite::ZObjectVtbl *v5; // rcx
  bool v6; // bl
  OSuite::ZDoublyLinkedListBase::ZIteratorBase v7; // [rsp+20h] [rbp-40h]
  OSuite::ZDoublyLinkedListBase::ZIteratorBase v8; // [rsp+38h] [rbp-28h]

  v7.m_pList = 0i64;
  v7.m_pElement = 0i64;
  v1 = (OSuite::ZDoublyLinkedListBase *)&this->m_socketList.vfptr;
  v2 = this;
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZSocketManager::`vftable;
  OSuite::ZDoublyLinkedListBase::ZIteratorBase::ZIteratorBase(
    &v7,
    (OSuite::ZDoublyLinkedListBase *)&this->m_socketList.vfptr,
    this->m_socketList.m_pHead);
  v8.m_pList = 0i64;
  v8.m_pElement = 0i64;
  v7.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable;
  OSuite::ZDoublyLinkedListBase::ZIteratorBase::ZIteratorBase(&v8, v1, 0i64);
  v8.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable;
  while ( 1 )
  {
    v6 = OSuite::ZRedBlackTreeBase::ZIteratorBase::operator bool((OSuite::ZRedBlackTreeBase::ZIteratorBase *)&v8);
    if ( OSuite::ZRedBlackTreeBase::ZIteratorBase::operator bool((OSuite::ZRedBlackTreeBase::ZIteratorBase *)&v7) == v6 )
      break;
    v3 = v7.m_pElement;
    if ( LODWORD(v7.m_pElement[1].m_pPrev) == 1 )
    {
      v4 = OSuite::ZClock::_GetClock();
      OSuite::ZClock::_ClockToTime(v4 - (unsigned __int64)v3[1].vfptr, UNIT_MILLI);
    }
    else
    {
      v5 = v7.m_pElement[2].vfptr;
      if ( v5 )
        (*(void (__fastcall **)(OSuite::ZObjectVtbl *, signed __int64))v5->__vecDelDtor)(v5, 1i64);
    }
    OSuite::ZDoublyLinkedListBase::ZIteratorBase::Next(&v7);
  }
  OSuite::ZDoublyLinkedListBase::Clear(v1);
  OSuite::ZMutex::~ZMutex(&v2->m_Mutex);
  v1->vfptr = (OSuite::ZObjectVtbl *)&OSuite::TDoublyLinkedList<OSuite::ZSocketManager::InternalSocket>::`vftable;
  OSuite::ZDoublyLinkedListBase::Clear(v1);
}

// File Line: 76
// RVA: 0xEDAC1C
OSuite::ZObjectVtbl *__fastcall OSuite::ZSocketManager::TryGetSocket(OSuite::ZSocketManager *this, OSuite::ZString *sHost, int nPort, bool *bAlreadyConnected)
{
  OSuite::ZMutex *v4; // rbx
  OSuite::ZSocketManager *v5; // r15
  bool *v6; // r12
  int v7; // er13
  OSuite::ZString *v8; // r14
  OSuite::ZObjectVtbl *v9; // rdi
  OSuite::ZDoublyLinkedListBase::ZElementBase *v10; // r8
  const char *v11; // rax
  OSuite::psock::ipv4addr_t *v12; // r8
  OSuite::ZDoublyLinkedListBase::ZElementBase *v13; // r14
  unsigned __int64 v14; // rax
  unsigned __int64 v15; // rax
  bool v16; // al
  int v17; // eax
  OSuite::ZSocket *v18; // rax
  OSuite::ZObjectVtbl *v19; // rax
  OSuite::ZString *v21; // [rsp+20h] [rbp-49h]
  OSuite::psock::ipv4addr_t result; // [rsp+28h] [rbp-41h]
  unsigned __int8 Dst; // [rsp+38h] [rbp-31h]
  unsigned __int8 v24; // [rsp+39h] [rbp-30h]
  unsigned __int8 v25; // [rsp+3Ah] [rbp-2Fh]
  unsigned __int8 v26; // [rsp+3Bh] [rbp-2Eh]
  int v27; // [rsp+3Ch] [rbp-2Dh]
  OSuite::ZDoublyLinkedListBase::ZIteratorBase v28; // [rsp+48h] [rbp-21h]
  OSuite::ZDoublyLinkedListBase::ZIteratorBase v29; // [rsp+60h] [rbp-9h]
  OSuite::ZObjectVtbl *v30; // [rsp+78h] [rbp+Fh]

  v4 = &this->m_Mutex;
  v5 = this;
  v6 = bAlreadyConnected;
  v7 = nPort;
  v8 = sHost;
  v21 = sHost;
  v9 = 0i64;
  OSuite::ZMutex::Lock(&this->m_Mutex);
  if ( !OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)&v5->m_socketList) )
    goto LABEL_26;
  v10 = v5->m_socketList.m_pHead;
  v28.m_pList = 0i64;
  v28.m_pElement = 0i64;
  OSuite::ZDoublyLinkedListBase::ZIteratorBase::ZIteratorBase(
    &v28,
    (OSuite::ZDoublyLinkedListBase *)&v5->m_socketList.vfptr,
    v10);
  v29.m_pList = 0i64;
  v29.m_pElement = 0i64;
  v28.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable;
  OSuite::ZDoublyLinkedListBase::ZIteratorBase::ZIteratorBase(
    &v29,
    (OSuite::ZDoublyLinkedListBase *)&v5->m_socketList.vfptr,
    0i64);
  v29.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable;
  while ( !OSuite::ZString::IsNull((OSuite::ZString *)&v28) )
  {
    memset(&Dst, 0, 0xCui64);
    v11 = OSuite::ZString::c_str(v8);
    OSuite::psock::getaddrbyname((OSuite::psock::ipv4addr_t *)&Dst, v11);
    v12 = OSuite::ZSocket::GetResolveAddr((OSuite::ZSocket *)v28.m_pElement[2].vfptr, &result);
    if ( ((unsigned __int8)v12->b[3] | (((unsigned __int8)v12->b[2] | (((unsigned __int8)v12->b[1] | ((unsigned __int8)v12->b[0] << 8)) << 8)) << 8)) == (v26 | ((v25 | ((v24 | (Dst << 8)) << 8)) << 8))
      && v12->type == v27 )
    {
      v13 = v28.m_pElement;
      if ( LODWORD(v28.m_pElement[2].vfptr[8].__vecDelDtor) == v7 && !LODWORD(v28.m_pElement[1].m_pPrev) )
      {
        v14 = OSuite::ZClock::_GetClock();
        OSuite::ZClock::_ClockToTime(v14 - (unsigned __int64)v13[1].vfptr, UNIT_MILLI);
        v15 = v5->m_freeSocket;
        if ( v15 )
          v5->m_freeSocket = v15 - 1;
        OSuite::ZSocketManager::InternalSocket::Bind((OSuite::ZSocketManager::InternalSocket *)&v28.m_pElement[1]);
        v9 = v28.m_pElement[2].vfptr;
        break;
      }
      v8 = v21;
    }
    OSuite::ZDoublyLinkedListBase::ZIteratorBase::Next(&v28);
  }
  v29.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable;
  v28.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable;
  if ( v9 )
  {
    v16 = OSuite::ZSocket::VerifyConnection((OSuite::ZSocket *)v9);
    *v6 = v16;
    if ( v16 )
    {
      v17 = OSuite::ZSocket::ReceiveByte((OSuite::ZSocket *)v9);
      if ( v17 > 0 || v17 == -1 && OSuite::ZSocket::HasFatalError((OSuite::ZSocket *)v9) )
      {
        OSuite::ZSocket::Close((OSuite::ZSocket *)v9);
        *v6 = 0;
      }
    }
  }
  else
  {
LABEL_26:
    v18 = (OSuite::ZSocket *)OSuite::ZObject::operator new(0x48ui64);
    if ( v18 )
    {
      v18->m_socket = 0i64;
      v18->m_sHost.m_pString = 0i64;
      OSuite::ZSocket::ZSocket(v18);
      v9 = v19;
    }
    else
    {
      v9 = 0i64;
    }
    OSuite::ZClock::ZClock((OSuite::ZClock *)&v29);
    OSuite::ZClock::ZClock((OSuite::ZClock *)&v29.m_pList);
    LODWORD(v29.m_pElement) = 0;
    v30 = v9;
    OSuite::ZSocketManager::InternalSocket::Bind((OSuite::ZSocketManager::InternalSocket *)&v29);
    OSuite::TDoublyLinkedList<OSuite::ZSocketManager::InternalSocket>::Insert(
      &v5->m_socketList,
      (OSuite::ZSocketManager::InternalSocket *)&v29);
    *v6 = 0;
    OSuite::ZOEdmBase::CleanTempData((unsigned __int64)&v29.m_pList);
    OSuite::ZOEdmBase::CleanTempData((unsigned __int64)&v29);
  }
  OSuite::ZMutex::Unlock(v4);
  return v9;
}

// File Line: 168
// RVA: 0xEDA9F4
void __fastcall OSuite::ZSocketManager::ReleaseSocket(OSuite::ZSocketManager *this, OSuite::ZSocket *pSocket, unsigned __int64 connectionKeepAliveTimeoutMs)
{
  OSuite::ZMutex *v3; // rbx
  OSuite::ZSocketManager *v4; // rsi
  unsigned __int64 v5; // r12
  OSuite::ZSocket *v6; // r14
  OSuite::ZDoublyLinkedListBase::ZElementBase *v7; // rdi
  unsigned __int64 v8; // rax
  OSuite::ZDoublyLinkedListBase::ZElementBase *v9; // r8
  OSuite::TDoublyLinkedList<OSuite::ZSocketManager::InternalSocket>::ZIterator result; // [rsp+20h] [rbp-49h]
  OSuite::ZDoublyLinkedListBase::ZIteratorBase v11; // [rsp+38h] [rbp-31h]
  OSuite::ZClock v12; // [rsp+50h] [rbp-19h]
  OSuite::ZClock v13; // [rsp+58h] [rbp-11h]
  int v14; // [rsp+60h] [rbp-9h]
  OSuite::ZSocket *v15; // [rsp+68h] [rbp-1h]
  OSuite::ZDoublyLinkedListBase::ZIteratorBase v16; // [rsp+70h] [rbp+7h]

  v3 = &this->m_Mutex;
  v4 = this;
  v5 = connectionKeepAliveTimeoutMs;
  v6 = pSocket;
  OSuite::ZMutex::Lock(&this->m_Mutex);
  OSuite::ZClock::ZClock(&v12);
  OSuite::ZClock::ZClock(&v13);
  result.m_pList = 0i64;
  result.m_pElement = 0i64;
  v15 = v6;
  v14 = 1;
  OSuite::TDoublyLinkedList<OSuite::ZSocketManager::InternalSocket>::Find(
    &v4->m_socketList,
    &result,
    (OSuite::ZSocketManager::InternalSocket *)&v12);
  if ( OSuite::ZString::IsNull((OSuite::ZString *)&result) )
  {
    if ( v6 )
      v6->vfptr->__vecDelDtor((OSuite::ZObject *)&v6->vfptr, 1u);
  }
  else
  {
    v7 = result.m_pElement;
    v8 = OSuite::ZClock::_GetClock();
    OSuite::ZClock::_ClockToTime(v8 - (unsigned __int64)v7[1].vfptr, UNIT_MILLI);
    if ( !v5 || (v6->m_state & 5) != 5 || OSuite::ZSocket::HasFatalError(v6) )
    {
      OSuite::ZSocketManager::Remove(v4, &result, "Keep alive timeout receive is 0 or socket not longer connected");
    }
    else
    {
      if ( ++v4->m_freeSocket > v4->m_MaxSocket )
      {
        v9 = v4->m_socketList.m_pHead;
        v11.m_pList = 0i64;
        v11.m_pElement = 0i64;
        OSuite::ZDoublyLinkedListBase::ZIteratorBase::ZIteratorBase(
          &v11,
          (OSuite::ZDoublyLinkedListBase *)&v4->m_socketList.vfptr,
          v9);
        v16.m_pList = 0i64;
        v16.m_pElement = 0i64;
        v11.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable;
        OSuite::ZDoublyLinkedListBase::ZIteratorBase::ZIteratorBase(
          &v16,
          (OSuite::ZDoublyLinkedListBase *)&v4->m_socketList.vfptr,
          0i64);
        v16.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable;
        while ( !OSuite::ZString::IsNull((OSuite::ZString *)&v11) )
        {
          if ( !LODWORD(v11.m_pElement[1].m_pPrev) )
          {
            OSuite::ZSocketManager::Remove(
              v4,
              (OSuite::TDoublyLinkedList<OSuite::ZSocketManager::InternalSocket>::ZIterator *)&v11,
              "Maximum of free socket has been reached");
            break;
          }
          OSuite::ZDoublyLinkedListBase::ZIteratorBase::Next(&v11);
        }
      }
      OSuite::ZSocketManager::InternalSocket::UnBind(
        (OSuite::ZSocketManager::InternalSocket *)&result.m_pElement[1],
        v5);
    }
  }
  result.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable;
  OSuite::ZOEdmBase::CleanTempData((unsigned __int64)&v13);
  OSuite::ZOEdmBase::CleanTempData((unsigned __int64)&v12);
  OSuite::ZMutex::Unlock(v3);
}

// File Line: 238
// RVA: 0xEDAF70
void __fastcall OSuite::ZSocketManager::Update(OSuite::ZSocketManager *this)
{
  OSuite::ZSocketManager *v1; // rsi
  unsigned __int64 v2; // rax
  OSuite::ZDoublyLinkedListBase::ZElementBase *v3; // r8
  OSuite::ZDoublyLinkedListBase::ZElementBase *v4; // rdi
  OSuite::ZSocket *v5; // rcx
  const char *v6; // r8
  unsigned __int64 clock; // [rsp+20h] [rbp-29h]
  unsigned __int64 v8; // [rsp+28h] [rbp-21h]
  OSuite::ZClock v9; // [rsp+30h] [rbp-19h]
  OSuite::ZClock v10; // [rsp+38h] [rbp-11h]
  int v11; // [rsp+40h] [rbp-9h]
  OSuite::ZObjectVtbl *v12; // [rsp+48h] [rbp-1h]
  OSuite::ZDoublyLinkedListBase::ZIteratorBase v13; // [rsp+50h] [rbp+7h]
  OSuite::ZDoublyLinkedListBase::ZIteratorBase v14; // [rsp+68h] [rbp+1Fh]

  v1 = this;
  if ( !(_S1_45 & 1) )
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
  OSuite::ZOEdmBase::CleanTempData((unsigned __int64)&clock);
  if ( OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)&v1->m_socketList) )
  {
    OSuite::ZMutex::Lock(&v1->m_Mutex);
    v3 = v1->m_socketList.m_pHead;
    v13.m_pList = 0i64;
    v13.m_pElement = 0i64;
    OSuite::ZDoublyLinkedListBase::ZIteratorBase::ZIteratorBase(
      &v13,
      (OSuite::ZDoublyLinkedListBase *)&v1->m_socketList.vfptr,
      v3);
    v14.m_pList = 0i64;
    v14.m_pElement = 0i64;
    v13.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable;
    OSuite::ZDoublyLinkedListBase::ZIteratorBase::ZIteratorBase(
      &v14,
      (OSuite::ZDoublyLinkedListBase *)&v1->m_socketList.vfptr,
      0i64);
    v14.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable;
    while ( 1 )
    {
      if ( OSuite::ZString::IsNull((OSuite::ZString *)&v13) )
      {
        OSuite::ZMutex::Unlock(&v1->m_Mutex);
        return;
      }
      v4 = v13.m_pElement;
      OSuite::ZClock::ZClock(&v9, (const unsigned __int64 *)&v13.m_pElement[1]);
      OSuite::ZClock::ZClock(&v10, (const unsigned __int64 *)&v4[1].m_pNext);
      v11 = (int)v4[1].m_pPrev;
      v5 = (OSuite::ZSocket *)v4[2].vfptr;
      v12 = v4[2].vfptr;
      if ( v11 != 1 )
      {
        if ( internalClock.m_clock >= v10.m_clock )
        {
          v6 = "Keep alive timeout has been reached";
LABEL_8:
          OSuite::ZSocketManager::Remove(
            v1,
            (OSuite::TDoublyLinkedList<OSuite::ZSocketManager::InternalSocket>::ZIterator *)&v13,
            v6);
          goto LABEL_12;
        }
        if ( !OSuite::ZSocket::VerifyConnection(v5) )
        {
          v6 = "Socket is no longer connected";
          goto LABEL_8;
        }
      }
      OSuite::ZDoublyLinkedListBase::ZIteratorBase::Next(&v13);
LABEL_12:
      OSuite::ZOEdmBase::CleanTempData((unsigned __int64)&v10);
      OSuite::ZOEdmBase::CleanTempData((unsigned __int64)&v9);
    }
  }
}

// File Line: 286
// RVA: 0xEDABC0
void __fastcall OSuite::ZSocketManager::Remove(OSuite::ZSocketManager *this, OSuite::TDoublyLinkedList<OSuite::ZSocketManager::InternalSocket>::ZIterator *socketIt, const char *reason)
{
  OSuite::ZSocketManager *v3; // rbx
  OSuite::TDoublyLinkedList<OSuite::ZSocketManager::InternalSocket>::ZIterator *v4; // rdi
  OSuite::ZObjectVtbl *v5; // rcx
  unsigned __int64 v6; // rax

  v3 = this;
  v4 = socketIt;
  OSuite::ZSocket::Abort((OSuite::ZSocket *)socketIt->m_pElement[2].vfptr, 0);
  v5 = v4->m_pElement[2].vfptr;
  if ( v5 )
    (*(void (__fastcall **)(OSuite::ZObjectVtbl *, signed __int64))v5->__vecDelDtor)(v5, 1i64);
  OSuite::ZDoublyLinkedListBase::ZIteratorBase::Remove((OSuite::ZDoublyLinkedListBase::ZIteratorBase *)&v4->vfptr);
  v6 = v3->m_freeSocket;
  if ( v6 )
    v3->m_freeSocket = v6 - 1;
}

