// File Line: 7
// RVA: 0xEEBE80
void __fastcall OSuite::ZCallbackManager::ZCallbackManager(OSuite::ZCallbackManager *this)
{
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZCallbackManager::`vftable;
  OSuite::ZDoublyLinkedListBase::ZDoublyLinkedListBase((OSuite::ZRedBlackTreeBase *)&this->m_callbacksList);
  this->m_callbacksList.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TDoublyLinkedList<OSuite::ZSocketManager::InternalSocket>::`vftable;
  OSuite::ZMutex::ZMutex(&this->m_Mutex);
}

// File Line: 12
// RVA: 0xEEBEC4
void __fastcall OSuite::ZCallbackManager::~ZCallbackManager(OSuite::ZCallbackManager *this)
{
  OSuite::TDoublyLinkedList<OSuite::ManagedCallback *> *p_m_callbacksList; // rbx
  OSuite::ZObjectVtbl *vfptr; // rcx
  OSuite::ZDoublyLinkedListBase::ZIteratorBase v4; // [rsp+20h] [rbp-28h] BYREF

  v4.m_pList = 0i64;
  v4.m_pElement = 0i64;
  p_m_callbacksList = &this->m_callbacksList;
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZCallbackManager::`vftable;
  OSuite::ZDoublyLinkedListBase::ZIteratorBase::ZIteratorBase(
    &v4,
    &this->m_callbacksList,
    this->m_callbacksList.m_pHead);
  v4.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable;
  while ( !OSuite::ZString::IsNull((OSuite::ZString *)&v4) )
  {
    vfptr = v4.m_pElement[1].vfptr;
    if ( vfptr )
      (*(void (__fastcall **)(OSuite::ZObjectVtbl *, __int64))vfptr->__vecDelDtor)(vfptr, 1i64);
    OSuite::ZDoublyLinkedListBase::ZIteratorBase::Remove(&v4);
  }
  OSuite::ZMutex::~ZMutex(&this->m_Mutex);
  p_m_callbacksList->vfptr = (OSuite::ZObjectVtbl *)&OSuite::TDoublyLinkedList<OSuite::ZSocketManager::InternalSocket>::`vftable;
  OSuite::ZDoublyLinkedListBase::Clear(p_m_callbacksList);
}

// File Line: 22
// RVA: 0xEEBFAC
void __fastcall OSuite::ZCallbackManager::AddCallback(
        OSuite::ZCallbackManager *this,
        OSuite::ManagedCallback *callback)
{
  OSuite::ManagedCallback *data; // [rsp+38h] [rbp+10h] BYREF

  data = callback;
  OSuite::ZMutex::Lock(&this->m_Mutex);
  OSuite::TDoublyLinkedList<OSuite::ZMetricAppender *>::Append(&this->m_callbacksList, &data);
  OSuite::ZMutex::Unlock(&this->m_Mutex);
}

// File Line: 31
// RVA: 0xEEBFE8
void __fastcall OSuite::ZCallbackManager::Update(OSuite::ZCallbackManager *this)
{
  OSuite::ZDoublyLinkedListBase::ZElementBase *m_pHead; // r8
  OSuite::ZObjectVtbl *vfptr; // rcx
  OSuite::ZDoublyLinkedListBase::ZIteratorBase v4; // [rsp+20h] [rbp-28h] BYREF

  if ( OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)&this->m_callbacksList) )
  {
    OSuite::ZMutex::Lock(&this->m_Mutex);
    m_pHead = this->m_callbacksList.m_pHead;
    v4.m_pList = 0i64;
    v4.m_pElement = 0i64;
    OSuite::ZDoublyLinkedListBase::ZIteratorBase::ZIteratorBase(&v4, &this->m_callbacksList, m_pHead);
    v4.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable;
    while ( !OSuite::ZString::IsNull((OSuite::ZString *)&v4) )
    {
      (*((void (__fastcall **)(OSuite::ZObjectVtbl *))v4.m_pElement[1].vfptr->__vecDelDtor + 3))(v4.m_pElement[1].vfptr);
      vfptr = v4.m_pElement[1].vfptr;
      if ( vfptr )
        (*(void (__fastcall **)(OSuite::ZObjectVtbl *, __int64))vfptr->__vecDelDtor)(vfptr, 1i64);
      OSuite::ZDoublyLinkedListBase::ZIteratorBase::Remove(&v4);
    }
    OSuite::ZMutex::Unlock(&this->m_Mutex);
  }
}

