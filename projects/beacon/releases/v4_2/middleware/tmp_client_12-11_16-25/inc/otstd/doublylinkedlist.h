// File Line: 323
// RVA: 0xEC17E4
OSuite::TDoublyLinkedList<OSuite::ManagedCallback *>::ZElement *__fastcall OSuite::TDoublyLinkedList<OSuite::ZMetricAppender *>::Append(
        OSuite::TDoublyLinkedList<OSuite::ManagedCallback *> *this,
        OSuite::ManagedCallback **data)
{
  OSuite::ZObject *v4; // rdx
  OSuite::ZDoublyLinkedListBase::ZElementBase *v5; // rbx

  v5 = (OSuite::ZDoublyLinkedListBase::ZElementBase *)OSuite::ZObject::operator new(0x20ui64);
  if ( v5 )
  {
    v5->m_pNext = 0i64;
    v5->m_pPrev = 0i64;
    v5[1].vfptr = 0i64;
    OSuite::ZRedBlackTreeBase::ZElementBase::ZElementBase(v5, v4);
    v5->vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable;
    v5[1].vfptr = (OSuite::ZObjectVtbl *)*data;
  }
  else
  {
    v5 = 0i64;
  }
  OSuite::ZDoublyLinkedListBase::AppendElement(this, v5);
  return (OSuite::TDoublyLinkedList<OSuite::ManagedCallback *>::ZElement *)v5;
}

// File Line: 336
// RVA: 0xEDA95C
OSuite::TDoublyLinkedList<OSuite::ZSocketManager::InternalSocket>::ZElement *__fastcall OSuite::TDoublyLinkedList<OSuite::ZSocketManager::InternalSocket>::Insert(
        OSuite::TDoublyLinkedList<OSuite::ZSocketManager::InternalSocket> *this,
        OSuite::ZSocketManager::InternalSocket *data)
{
  OSuite::ZObject *v4; // rax
  OSuite::ZObject *v5; // rdx
  OSuite::ZObject *v6; // rdi

  v4 = (OSuite::ZObject *)OSuite::ZObject::operator new(0x38ui64);
  v6 = v4;
  if ( v4 )
  {
    v4[1].vfptr = 0i64;
    v4[2].vfptr = 0i64;
    OSuite::ZRedBlackTreeBase::ZElementBase::ZElementBase(v4, v5);
    v6->vfptr = (OSuite::ZObjectVtbl *)&OSuite::TDoublyLinkedList<OSuite::ZSocketManager::InternalSocket>::ZElement::`vftable;
    OSuite::ZClock::ZClock((OSuite::ZClock *)&v6[3], &data->m_lastActionTime.m_clock);
    OSuite::ZClock::ZClock((OSuite::ZClock *)&v6[4], &data->m_maxTime.m_clock);
    LODWORD(v6[5].vfptr) = data->m_state;
    v6[6].vfptr = (OSuite::ZObjectVtbl *)data->m_socket;
  }
  else
  {
    v6 = 0i64;
  }
  OSuite::ZDoublyLinkedListBase::InsertElement(this, (OSuite::ZDoublyLinkedListBase::ZElementBase *)v6);
  return (OSuite::TDoublyLinkedList<OSuite::ZSocketManager::InternalSocket>::ZElement *)v6;
}

// File Line: 447
// RVA: 0xEDB754
OSuite::TDoublyLinkedList<OSuite::IHttpRequest *>::ZIterator *__fastcall OSuite::TDoublyLinkedList<OSuite::IHttpRequest *>::Find(
        OSuite::TDoublyLinkedList<OSuite::IHttpRequest *> *this,
        OSuite::TDoublyLinkedList<OSuite::IHttpRequest *>::ZIterator *result,
        OSuite::ZObjectVtbl **data)
{
  OSuite::ZDoublyLinkedListBase::ZElementBase *m_pHead; // r8

  if ( OSuite::ZRedBlackTreeBase::IsEmpty((OSuite::ZRedBlackTreeBase *)this) )
    goto LABEL_7;
  m_pHead = this->m_pHead;
  while ( m_pHead[1].vfptr != *data )
  {
    m_pHead = m_pHead->m_pNext;
    if ( m_pHead == this->m_pHead )
    {
      m_pHead = 0i64;
      break;
    }
  }
  if ( !m_pHead )
LABEL_7:
    m_pHead = 0i64;
  OSuite::ZDoublyLinkedListBase::ZIteratorBase::ZIteratorBase(result, this, m_pHead);
  result->vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable;
  return result;
}

