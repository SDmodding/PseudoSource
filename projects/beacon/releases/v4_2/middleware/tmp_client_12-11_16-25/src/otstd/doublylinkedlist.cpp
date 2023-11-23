// File Line: 12
// RVA: 0xEE39F0
OSuite::ZObject *__fastcall OSuite::ZRedBlackTreeBase::ZElementBase::ZElementBase(
        OSuite::ZObject *this,
        OSuite::ZObject *__formal)
{
  return this;
}

// File Line: 45
// RVA: 0xEE39F4
void __fastcall OSuite::ZListBase::ZListIteratorBase::ZListIteratorBase(
        OSuite::ZListBase::ZListIteratorBase *this,
        OSuite::ZListBase::ZListIteratorBase *that)
{
  this->m_pListBase = that->m_pListBase;
  this->m_nIndex = that->m_nIndex;
}

// File Line: 52
// RVA: 0xEE3A08
void __fastcall OSuite::ZDoublyLinkedListBase::ZIteratorBase::ZIteratorBase(
        OSuite::ZDoublyLinkedListBase::ZIteratorBase *this,
        OSuite::ZDoublyLinkedListBase *pList,
        OSuite::ZDoublyLinkedListBase::ZElementBase *pElement)
{
  this->m_pList = pList;
  this->m_pElement = pElement;
}

// File Line: 56
// RVA: 0xEE3A30
OSuite::ZDoublyLinkedListBase::ZIteratorBase *__fastcall OSuite::ZDoublyLinkedListBase::ZIteratorBase::operator=(
        OSuite::ZDoublyLinkedListBase::ZIteratorBase *this,
        OSuite::ZDoublyLinkedListBase::ZIteratorBase *that)
{
  if ( this != that )
  {
    OSuite::ZRedBlackTreeBase::ZElementBase::ZElementBase(this, that);
    this->m_pList = that->m_pList;
    this->m_pElement = that->m_pElement;
  }
  return this;
}

// File Line: 69
// RVA: 0xEE3B4C
void __fastcall OSuite::ZDoublyLinkedListBase::ZIteratorBase::Next(OSuite::ZDoublyLinkedListBase::ZIteratorBase *this)
{
  OSuite::ZDoublyLinkedListBase::ZElementBase *m_pElement; // rdx
  OSuite::ZDoublyLinkedListBase *m_pList; // rax
  OSuite::ZDoublyLinkedListBase::ZElementBase *m_pNext; // rdx

  m_pElement = this->m_pElement;
  m_pList = this->m_pList;
  if ( m_pElement )
  {
    m_pNext = m_pElement->m_pNext;
    this->m_pElement = m_pNext;
    if ( m_pNext == m_pList->m_pHead )
      this->m_pElement = 0i64;
  }
  else
  {
    this->m_pElement = m_pList->m_pHead;
  }
}

// File Line: 86
// RVA: 0xEE3B7C
void __fastcall OSuite::ZDoublyLinkedListBase::ZIteratorBase::Previous(
        OSuite::ZDoublyLinkedListBase::ZIteratorBase *this)
{
  OSuite::ZDoublyLinkedListBase::ZElementBase *m_pElement; // rax
  OSuite::ZDoublyLinkedListBase::ZElementBase *m_pPrev; // rdx
  OSuite::ZDoublyLinkedListBase::ZElementBase *v3; // r8
  OSuite::ZDoublyLinkedListBase *m_pList; // rax
  OSuite::ZDoublyLinkedListBase::ZElementBase *v5; // rax
  OSuite::ZDoublyLinkedListBase::ZElementBase *v6; // rax
  OSuite::ZDoublyLinkedListBase::ZElementBase *m_pHead; // r8

  m_pElement = this->m_pElement;
  m_pPrev = 0i64;
  if ( !m_pElement )
  {
    m_pHead = this->m_pList->m_pHead;
    if ( m_pHead )
      m_pPrev = m_pHead->m_pPrev;
    goto LABEL_9;
  }
  v3 = m_pElement->m_pPrev;
  m_pList = this->m_pList;
  this->m_pElement = v3;
  v5 = m_pList->m_pHead;
  if ( v5 )
    v6 = v5->m_pPrev;
  else
    v6 = 0i64;
  if ( v3 == v6 )
LABEL_9:
    this->m_pElement = m_pPrev;
}

// File Line: 103
// RVA: 0xEE3BC4
void __fastcall OSuite::ZDoublyLinkedListBase::ZIteratorBase::Remove(
        OSuite::ZDoublyLinkedListBase::ZIteratorBase *this)
{
  OSuite::ZDoublyLinkedListBase::ZElementBase *m_pElement; // rbx

  m_pElement = this->m_pElement;
  OSuite::ZDoublyLinkedListBase::ZIteratorBase::Next(this);
  OSuite::ZDoublyLinkedListBase::DeleteElement(this->m_pList, m_pElement);
}

// File Line: 158
// RVA: 0xEE3A14
OSuite::ZDoublyLinkedListBase *__fastcall OSuite::ZDoublyLinkedListBase::operator=(
        OSuite::ZDoublyLinkedListBase *this,
        OSuite::ZDoublyLinkedListBase *that)
{
  if ( this != that )
    OSuite::ZDoublyLinkedListBase::Clear(this);
  return this;
}

// File Line: 171
// RVA: 0xEE3AA4
void __fastcall OSuite::ZDoublyLinkedListBase::Clear(OSuite::ZDoublyLinkedListBase *this)
{
  OSuite::ZDoublyLinkedListBase::ZElementBase *i; // rax

  for ( i = this->m_pHead; i; i = this->m_pHead )
    OSuite::ZDoublyLinkedListBase::DeleteElement(this, i);
}

// File Line: 203
// RVA: 0xEE3A68
void __fastcall OSuite::ZDoublyLinkedListBase::AppendElement(
        OSuite::ZDoublyLinkedListBase *this,
        OSuite::ZDoublyLinkedListBase::ZElementBase *el)
{
  OSuite::ZDoublyLinkedListBase::ZElementBase *m_pHead; // rcx
  OSuite::ZDoublyLinkedListBase::ZElementBase *m_pPrev; // rcx
  OSuite::ZDoublyLinkedListBase::ZElementBase *m_pNext; // rax

  m_pHead = this->m_pHead;
  if ( m_pHead )
  {
    m_pPrev = m_pHead->m_pPrev;
    m_pNext = m_pPrev->m_pNext;
    el->m_pPrev = m_pPrev;
    el->m_pNext = m_pNext;
    m_pPrev->m_pNext->m_pPrev = el;
    m_pPrev->m_pNext = el;
  }
  else
  {
    this->m_pHead = el;
    el->m_pPrev = el;
    el->m_pNext = el;
  }
  ++this->m_nTotalElements;
}

// File Line: 225
// RVA: 0xEE3B28
void __fastcall OSuite::ZDoublyLinkedListBase::InsertElement(
        OSuite::ZDoublyLinkedListBase *this,
        OSuite::ZDoublyLinkedListBase::ZElementBase *el)
{
  OSuite::ZDoublyLinkedListBase::AppendElement(this, el);
  this->m_pHead = el;
}

// File Line: 232
// RVA: 0xEE3AD0
void __fastcall OSuite::ZDoublyLinkedListBase::DeleteElement(
        OSuite::ZDoublyLinkedListBase *this,
        OSuite::ZDoublyLinkedListBase::ZElementBase *pElem)
{
  if ( this->m_pHead == pElem )
    this->m_pHead = pElem->m_pNext;
  pElem->m_pPrev->m_pNext = pElem->m_pNext;
  pElem->m_pNext->m_pPrev = pElem->m_pPrev;
  pElem->m_pNext = 0i64;
  pElem->m_pPrev = 0i64;
  if ( !this->m_pHead->m_pNext )
    this->m_pHead = 0i64;
  --this->m_nTotalElements;
  pElem->vfptr->__vecDelDtor(pElem, 1i64);
}

// File Line: 275
// RVA: 0xEE3BF0
OSuite::ZDoublyLinkedListBase::ZElementBase *__fastcall OSuite::ZDoublyLinkedListBase::TailElement(
        OSuite::ZDoublyLinkedListBase *this)
{
  OSuite::ZDoublyLinkedListBase::ZElementBase *m_pHead; // rdx
  OSuite::ZDoublyLinkedListBase::ZElementBase *result; // rax

  m_pHead = this->m_pHead;
  result = 0i64;
  if ( m_pHead )
    return m_pHead->m_pPrev;
  return result;
}

