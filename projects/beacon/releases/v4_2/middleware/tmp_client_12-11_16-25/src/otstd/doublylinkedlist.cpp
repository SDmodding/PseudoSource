// File Line: 12
// RVA: 0xEE39F0
OSuite::ZObject *__fastcall OSuite::ZRedBlackTreeBase::ZElementBase::ZElementBase(OSuite::ZObject *this, OSuite::ZObject *__formal)
{
  return this;
}

// File Line: 45
// RVA: 0xEE39F4
void __fastcall OSuite::ZListBase::ZListIteratorBase::ZListIteratorBase(OSuite::ZListBase::ZListIteratorBase *this, OSuite::ZListBase::ZListIteratorBase *that)
{
  this->m_pListBase = that->m_pListBase;
  this->m_nIndex = that->m_nIndex;
}

// File Line: 52
// RVA: 0xEE3A08
void __fastcall OSuite::ZDoublyLinkedListBase::ZIteratorBase::ZIteratorBase(OSuite::ZDoublyLinkedListBase::ZIteratorBase *this, OSuite::ZDoublyLinkedListBase *pList, OSuite::ZDoublyLinkedListBase::ZElementBase *pElement)
{
  this->m_pList = pList;
  this->m_pElement = pElement;
}

// File Line: 56
// RVA: 0xEE3A30
OSuite::ZDoublyLinkedListBase::ZIteratorBase *__fastcall OSuite::ZDoublyLinkedListBase::ZIteratorBase::operator=(OSuite::ZDoublyLinkedListBase::ZIteratorBase *this, OSuite::ZDoublyLinkedListBase::ZIteratorBase *that)
{
  OSuite::ZDoublyLinkedListBase::ZIteratorBase *v2; // rdi
  OSuite::ZDoublyLinkedListBase::ZIteratorBase *v3; // rbx

  v2 = that;
  v3 = this;
  if ( this != that )
  {
    OSuite::ZRedBlackTreeBase::ZElementBase::ZElementBase(
      (OSuite::ZObject *)&this->vfptr,
      (OSuite::ZObject *)&that->vfptr);
    v3->m_pList = v2->m_pList;
    v3->m_pElement = v2->m_pElement;
  }
  return v3;
}

// File Line: 69
// RVA: 0xEE3B4C
void __fastcall OSuite::ZDoublyLinkedListBase::ZIteratorBase::Next(OSuite::ZDoublyLinkedListBase::ZIteratorBase *this)
{
  OSuite::ZDoublyLinkedListBase::ZElementBase *v1; // rdx
  OSuite::ZDoublyLinkedListBase *v2; // rax
  OSuite::ZDoublyLinkedListBase::ZElementBase *v3; // rdx

  v1 = this->m_pElement;
  v2 = this->m_pList;
  if ( v1 )
  {
    v3 = v1->m_pNext;
    this->m_pElement = v3;
    if ( v3 == v2->m_pHead )
      this->m_pElement = 0i64;
  }
  else
  {
    this->m_pElement = v2->m_pHead;
  }
}

// File Line: 86
// RVA: 0xEE3B7C
void __fastcall OSuite::ZDoublyLinkedListBase::ZIteratorBase::Previous(OSuite::ZDoublyLinkedListBase::ZIteratorBase *this)
{
  OSuite::ZDoublyLinkedListBase::ZElementBase *v1; // rax
  OSuite::ZDoublyLinkedListBase::ZElementBase *v2; // rdx
  OSuite::ZDoublyLinkedListBase::ZElementBase *v3; // r8
  OSuite::ZDoublyLinkedListBase *v4; // rax
  OSuite::ZDoublyLinkedListBase::ZElementBase *v5; // rax
  OSuite::ZDoublyLinkedListBase::ZElementBase *v6; // rax
  OSuite::ZDoublyLinkedListBase::ZElementBase *v7; // r8

  v1 = this->m_pElement;
  v2 = 0i64;
  if ( !v1 )
  {
    v7 = this->m_pList->m_pHead;
    if ( v7 )
      v2 = v7->m_pPrev;
    goto LABEL_9;
  }
  v3 = v1->m_pPrev;
  v4 = this->m_pList;
  this->m_pElement = v3;
  v5 = v4->m_pHead;
  if ( v5 )
    v6 = v5->m_pPrev;
  else
    v6 = 0i64;
  if ( v3 == v6 )
LABEL_9:
    this->m_pElement = v2;
}

// File Line: 103
// RVA: 0xEE3BC4
void __fastcall OSuite::ZDoublyLinkedListBase::ZIteratorBase::Remove(OSuite::ZDoublyLinkedListBase::ZIteratorBase *this)
{
  OSuite::ZDoublyLinkedListBase::ZElementBase *v1; // rbx
  OSuite::ZDoublyLinkedListBase::ZIteratorBase *v2; // rdi

  v1 = this->m_pElement;
  v2 = this;
  OSuite::ZDoublyLinkedListBase::ZIteratorBase::Next(this);
  OSuite::ZDoublyLinkedListBase::DeleteElement(v2->m_pList, v1);
}

// File Line: 158
// RVA: 0xEE3A14
OSuite::ZDoublyLinkedListBase *__fastcall OSuite::ZDoublyLinkedListBase::operator=(OSuite::ZDoublyLinkedListBase *this, OSuite::ZDoublyLinkedListBase *that)
{
  OSuite::ZDoublyLinkedListBase *v2; // rbx

  v2 = this;
  if ( this != that )
    OSuite::ZDoublyLinkedListBase::Clear(this);
  return v2;
}

// File Line: 171
// RVA: 0xEE3AA4
void __fastcall OSuite::ZDoublyLinkedListBase::Clear(OSuite::ZDoublyLinkedListBase *this)
{
  OSuite::ZDoublyLinkedListBase::ZElementBase *v1; // rax
  OSuite::ZDoublyLinkedListBase *v2; // rbx

  v1 = this->m_pHead;
  v2 = this;
  while ( v1 )
  {
    OSuite::ZDoublyLinkedListBase::DeleteElement(v2, v1);
    v1 = v2->m_pHead;
  }
}

// File Line: 203
// RVA: 0xEE3A68
void __fastcall OSuite::ZDoublyLinkedListBase::AppendElement(OSuite::ZDoublyLinkedListBase *this, OSuite::ZDoublyLinkedListBase::ZElementBase *el)
{
  OSuite::ZDoublyLinkedListBase *v2; // r8
  OSuite::ZDoublyLinkedListBase::ZElementBase *v3; // rcx
  OSuite::ZDoublyLinkedListBase::ZElementBase *v4; // rcx
  OSuite::ZDoublyLinkedListBase::ZElementBase *v5; // rax

  v2 = this;
  v3 = this->m_pHead;
  if ( v3 )
  {
    v4 = v3->m_pPrev;
    v5 = v4->m_pNext;
    el->m_pPrev = v4;
    el->m_pNext = v5;
    v4->m_pNext->m_pPrev = el;
    v4->m_pNext = el;
  }
  else
  {
    v2->m_pHead = el;
    el->m_pPrev = el;
    el->m_pNext = el;
  }
  ++v2->m_nTotalElements;
}

// File Line: 225
// RVA: 0xEE3B28
void __fastcall OSuite::ZDoublyLinkedListBase::InsertElement(OSuite::ZDoublyLinkedListBase *this, OSuite::ZDoublyLinkedListBase::ZElementBase *el)
{
  OSuite::ZDoublyLinkedListBase::ZElementBase *v2; // rdi
  OSuite::ZDoublyLinkedListBase *v3; // rbx

  v2 = el;
  v3 = this;
  OSuite::ZDoublyLinkedListBase::AppendElement(this, el);
  v3->m_pHead = v2;
}

// File Line: 232
// RVA: 0xEE3AD0
void __fastcall OSuite::ZDoublyLinkedListBase::DeleteElement(OSuite::ZDoublyLinkedListBase *this, OSuite::ZDoublyLinkedListBase::ZElementBase *pElem)
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
  pElem->vfptr->__vecDelDtor((OSuite::ZObject *)pElem, 1u);
}

// File Line: 275
// RVA: 0xEE3BF0
OSuite::ZDoublyLinkedListBase::ZElementBase *__fastcall OSuite::ZDoublyLinkedListBase::TailElement(OSuite::ZDoublyLinkedListBase *this)
{
  OSuite::ZDoublyLinkedListBase::ZElementBase *v1; // rdx
  OSuite::ZDoublyLinkedListBase::ZElementBase *result; // rax

  v1 = this->m_pHead;
  result = 0i64;
  if ( v1 )
    result = v1->m_pPrev;
  return result;
}

