// File Line: 7
// RVA: 0xEEBE80
void __fastcall OSuite::ZCallbackManager::ZCallbackManager(OSuite::ZCallbackManager *this)
{
  OSuite::ZCallbackManager *v1; // rdi

  v1 = this;
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZCallbackManager::`vftable;
  OSuite::ZDoublyLinkedListBase::ZDoublyLinkedListBase((OSuite::ZRedBlackTreeBase *)&this->m_callbacksList);
  v1->m_callbacksList.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TDoublyLinkedList<OSuite::ZSocketManager::InternalSocket>::`vftable;
  OSuite::ZMutex::ZMutex(&v1->m_Mutex);
}

// File Line: 12
// RVA: 0xEEBEC4
void __fastcall OSuite::ZCallbackManager::~ZCallbackManager(OSuite::ZCallbackManager *this)
{
  OSuite::ZDoublyLinkedListBase *v1; // rbx
  OSuite::ZCallbackManager *v2; // rdi
  OSuite::ZObjectVtbl *v3; // rcx
  OSuite::ZDoublyLinkedListBase::ZIteratorBase v4; // [rsp+20h] [rbp-28h]

  v4.m_pList = 0i64;
  v4.m_pElement = 0i64;
  v1 = (OSuite::ZDoublyLinkedListBase *)&this->m_callbacksList.vfptr;
  v2 = this;
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZCallbackManager::`vftable;
  OSuite::ZDoublyLinkedListBase::ZIteratorBase::ZIteratorBase(
    &v4,
    (OSuite::ZDoublyLinkedListBase *)&this->m_callbacksList.vfptr,
    this->m_callbacksList.m_pHead);
  v4.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable;
  while ( !(unsigned __int8)OSuite::ZString::IsNull((OSuite::ZString *)&v4) )
  {
    v3 = v4.m_pElement[1].vfptr;
    if ( v3 )
      (*(void (__fastcall **)(OSuite::ZObjectVtbl *, signed __int64))v3->__vecDelDtor)(v3, 1i64);
    OSuite::ZDoublyLinkedListBase::ZIteratorBase::Remove(&v4);
  }
  OSuite::ZMutex::~ZMutex(&v2->m_Mutex);
  v1->vfptr = (OSuite::ZObjectVtbl *)&OSuite::TDoublyLinkedList<OSuite::ZSocketManager::InternalSocket>::`vftable;
  OSuite::ZDoublyLinkedListBase::Clear(v1);
}

// File Line: 22
// RVA: 0xEEBFAC
void __fastcall OSuite::ZCallbackManager::AddCallback(OSuite::ZCallbackManager *this, OSuite::ManagedCallback *callback)
{
  OSuite::ZCallbackManager *v2; // rdi
  OSuite::ManagedCallback *data; // [rsp+38h] [rbp+10h]

  data = callback;
  v2 = this;
  OSuite::ZMutex::Lock(&this->m_Mutex);
  OSuite::TDoublyLinkedList<OSuite::ZMetricAppender *>::Append(&v2->m_callbacksList, &data);
  OSuite::ZMutex::Unlock(&v2->m_Mutex);
}

// File Line: 31
// RVA: 0xEEBFE8
void __fastcall OSuite::ZCallbackManager::Update(OSuite::ZCallbackManager *this)
{
  OSuite::ZCallbackManager *v1; // rbx
  OSuite::ZDoublyLinkedListBase::ZElementBase *v2; // r8
  OSuite::ZObjectVtbl *v3; // rcx
  OSuite::ZDoublyLinkedListBase::ZIteratorBase v4; // [rsp+20h] [rbp-28h]

  v1 = this;
  if ( OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)&this->m_callbacksList) )
  {
    OSuite::ZMutex::Lock(&v1->m_Mutex);
    v2 = v1->m_callbacksList.m_pHead;
    v4.m_pList = 0i64;
    v4.m_pElement = 0i64;
    OSuite::ZDoublyLinkedListBase::ZIteratorBase::ZIteratorBase(
      &v4,
      (OSuite::ZDoublyLinkedListBase *)&v1->m_callbacksList.vfptr,
      v2);
    v4.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable;
    while ( !(unsigned __int8)OSuite::ZString::IsNull((OSuite::ZString *)&v4) )
    {
      (*((void (__cdecl **)(OSuite::ZObjectVtbl *))v4.m_pElement[1].vfptr->__vecDelDtor + 3))(v4.m_pElement[1].vfptr);
      v3 = v4.m_pElement[1].vfptr;
      if ( v3 )
        (*(void (__fastcall **)(OSuite::ZObjectVtbl *, signed __int64))v3->__vecDelDtor)(v3, 1i64);
      OSuite::ZDoublyLinkedListBase::ZIteratorBase::Remove(&v4);
    }
    OSuite::ZMutex::Unlock(&v1->m_Mutex);
  }
}

