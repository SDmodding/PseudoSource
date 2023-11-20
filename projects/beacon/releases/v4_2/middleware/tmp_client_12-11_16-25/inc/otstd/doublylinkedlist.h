// File Line: 323
// RVA: 0xEC17E4
OSuite::ZDoublyLinkedListBase::ZElementBase *__fastcall OSuite::TDoublyLinkedList<OSuite::ZMetricAppender *>::Append(OSuite::TDoublyLinkedList<OSuite::ManagedCallback *> *this, OSuite::ManagedCallback *const *data)
{
  OSuite::TDoublyLinkedList<OSuite::ManagedCallback *> *v2; // rdi
  OSuite::ManagedCallback *const *v3; // rsi
  OSuite::ZObject *v4; // rdx
  OSuite::ZDoublyLinkedListBase::ZElementBase *v5; // rbx

  v2 = this;
  v3 = data;
  v5 = (OSuite::ZDoublyLinkedListBase::ZElementBase *)OSuite::ZObject::operator new(0x20ui64);
  if ( v5 )
  {
    v5->m_pNext = 0i64;
    v5->m_pPrev = 0i64;
    v5[1].vfptr = 0i64;
    OSuite::ZRedBlackTreeBase::ZElementBase::ZElementBase((OSuite::ZObject *)&v5->vfptr, v4);
    v5->vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable;
    v5[1].vfptr = (OSuite::ZObjectVtbl *)*v3;
  }
  else
  {
    v5 = 0i64;
  }
  OSuite::ZDoublyLinkedListBase::AppendElement((OSuite::ZDoublyLinkedListBase *)&v2->vfptr, v5);
  return v5;
}

// File Line: 336
// RVA: 0xEDA95C
OSuite::ZObject *__fastcall OSuite::TDoublyLinkedList<OSuite::ZSocketManager::InternalSocket>::Insert(OSuite::TDoublyLinkedList<OSuite::ZSocketManager::InternalSocket> *this, OSuite::ZSocketManager::InternalSocket *data)
{
  OSuite::TDoublyLinkedList<OSuite::ZSocketManager::InternalSocket> *v2; // rbp
  OSuite::ZSocketManager::InternalSocket *v3; // rsi
  OSuite::ZObject *v4; // rax
  OSuite::ZObject *v5; // rdx
  OSuite::ZObject *v6; // rdi

  v2 = this;
  v3 = data;
  v4 = (OSuite::ZObject *)OSuite::ZObject::operator new(0x38ui64);
  v6 = v4;
  if ( v4 )
  {
    v4[1].vfptr = 0i64;
    v4[2].vfptr = 0i64;
    OSuite::ZRedBlackTreeBase::ZElementBase::ZElementBase(v4, v5);
    v6->vfptr = (OSuite::ZObjectVtbl *)&OSuite::TDoublyLinkedList<OSuite::ZSocketManager::InternalSocket>::ZElement::`vftable;
    OSuite::ZClock::ZClock((OSuite::ZClock *)&v6[3], &v3->m_lastActionTime.m_clock);
    OSuite::ZClock::ZClock((OSuite::ZClock *)&v6[4], &v3->m_maxTime.m_clock);
    LODWORD(v6[5].vfptr) = v3->m_state;
    v6[6].vfptr = (OSuite::ZObjectVtbl *)v3->m_socket;
  }
  else
  {
    v6 = 0i64;
  }
  OSuite::ZDoublyLinkedListBase::InsertElement(
    (OSuite::ZDoublyLinkedListBase *)&v2->vfptr,
    (OSuite::ZDoublyLinkedListBase::ZElementBase *)v6);
  return v6;
}

// File Line: 447
// RVA: 0xEDB754
OSuite::TDoublyLinkedList<OSuite::IHttpRequest *>::ZIterator *__fastcall OSuite::TDoublyLinkedList<OSuite::IHttpRequest *>::Find(OSuite::TDoublyLinkedList<OSuite::IHttpRequest *> *this, OSuite::TDoublyLinkedList<OSuite::IHttpRequest *>::ZIterator *result, OSuite::IHttpRequest *const *data)
{
  OSuite::IHttpRequest *const *v3; // rsi
  OSuite::TDoublyLinkedList<OSuite::IHttpRequest *>::ZIterator *v4; // rbx
  OSuite::TDoublyLinkedList<OSuite::IHttpRequest *> *v5; // rdi
  OSuite::ZDoublyLinkedListBase::ZElementBase *v6; // r8

  v3 = data;
  v4 = result;
  v5 = this;
  if ( OSuite::ZRedBlackTreeBase::IsEmpty((OSuite::ZRedBlackTreeBase *)this) )
    goto LABEL_11;
  v6 = v5->m_pHead;
  while ( v6[1].vfptr != (OSuite::ZObjectVtbl *)*v3 )
  {
    v6 = v6->m_pNext;
    if ( v6 == v5->m_pHead )
    {
      v6 = 0i64;
      break;
    }
  }
  if ( !v6 )
LABEL_11:
    v6 = 0i64;
  OSuite::ZDoublyLinkedListBase::ZIteratorBase::ZIteratorBase(
    (OSuite::ZDoublyLinkedListBase::ZIteratorBase *)&v4->vfptr,
    (OSuite::ZDoublyLinkedListBase *)&v5->vfptr,
    v6);
  v4->vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable;
  return v4;
}

