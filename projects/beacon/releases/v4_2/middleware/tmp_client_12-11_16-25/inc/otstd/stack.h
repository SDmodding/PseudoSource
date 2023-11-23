// File Line: 49
// RVA: 0xEE4E70
OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *> *__fastcall OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::operator=(
        OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *> *this,
        OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *> *that)
{
  unsigned __int64 m_nFree; // rax
  OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *v5; // rbx
  unsigned __int64 v6; // rcx
  OSuite::ZRedBlackTreeBase::ZElementBase **m_staticList; // r8
  OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *m_pList; // rcx
  OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *v9; // rax
  OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *v10; // rax

  if ( this != that )
  {
    m_nFree = that->m_nFree;
    v5 = 0i64;
    this->m_nFree = m_nFree;
    v6 = 0i64;
    if ( m_nFree )
    {
      m_staticList = this->m_staticList;
      do
      {
        if ( v6 >= 5 )
          break;
        ++v6;
        *m_staticList = *(OSuite::ZRedBlackTreeBase::ZElementBase **)((char *)m_staticList + (char *)that - (char *)this);
        ++m_staticList;
      }
      while ( v6 < this->m_nFree );
    }
    m_pList = this->m_pList;
    if ( m_pList )
      m_pList->OSuite::ZListBase::OSuite::ZObject::vfptr->__vecDelDtor(m_pList, 1u);
    if ( that->m_pList )
    {
      v9 = (OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *)OSuite::ZObject::operator new(0x28ui64);
      if ( v9 )
      {
        v9->m_pList = 0i64;
        OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *>::TList<OSuite::ZRedBlackTreeBase::ZElementBase *>(
          v9,
          (OSuite::ZListBase::ZListIteratorBase *)that->m_pList);
        v5 = v10;
      }
    }
    this->m_pList = v5;
  }
  return this;
}

// File Line: 69
// RVA: 0xEE0B78
void __fastcall OSuite::TStack<int>::Push(OSuite::TStack<int> *this, int *element)
{
  unsigned __int64 m_nFree; // rcx
  OSuite::ZObject *v5; // rax
  OSuite::ZObject *v6; // rdx
  OSuite::TList<int> *v7; // rbx
  int *v8; // rax
  OSuite::TList<int> *m_pList; // rbx

  m_nFree = this->m_nFree;
  if ( m_nFree >= 9 )
  {
    if ( !this->m_pList )
    {
      v5 = (OSuite::ZObject *)OSuite::ZObject::operator new(0x28ui64);
      v7 = (OSuite::TList<int> *)v5;
      if ( v5 )
      {
        v5[4].vfptr = 0i64;
        OSuite::ZRedBlackTreeBase::ZElementBase::ZElementBase(v5, v6);
        v7->m_pList = 0i64;
        v7->OSuite::ZListBase::OSuite::ZObject::vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<int>::`vftable{for `OSuite::ZListBase};
        v7->OSuite::IHashable::vfptr = (OSuite::IHashableVtbl *)&OSuite::TList<int>::`vftable{for `OSuite::IHashable};
        v8 = (int *)OSuite::ZObject::malloc(v7, 0x40ui64, 0i64);
        v7->m_nTop = 0i64;
        v7->m_nSize = 16i64;
        v7->m_pList = v8;
      }
      else
      {
        v7 = 0i64;
      }
      this->m_pList = v7;
    }
    m_pList = this->m_pList;
    OSuite::TList<int>::Grow(m_pList, m_pList->m_nTop + 1);
    m_pList->m_pList[m_pList->m_nTop++] = *element;
  }
  else
  {
    this->m_staticList[m_nFree] = *element;
  }
  ++this->m_nFree;
}

// File Line: 90
// RVA: 0xEE6770
OSuite::ZRedBlackTreeBase::ZElementBase *__fastcall OSuite::TStack<OSuite::ZJsonObject *>::Pop(
        OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *> *this)
{
  unsigned __int64 m_nFree; // rax
  OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *m_pList; // rbx
  unsigned __int64 v4; // rax
  unsigned __int64 v5; // rbp
  unsigned __int64 v6; // rsi
  OSuite::ZRedBlackTreeBase::ZElementBase *v7; // rbx
  unsigned __int64 v9; // rax

  m_nFree = this->m_nFree;
  if ( m_nFree <= 5 )
  {
    v9 = m_nFree - 1;
    this->m_nFree = v9;
    return this->m_staticList[v9];
  }
  else
  {
    m_pList = this->m_pList;
    v4 = m_nFree - 1;
    v5 = v4 - 5;
    this->m_nFree = v4;
    v6 = v4 - 5 + 1;
    OSuite::TList<OSuite::ZONavigationProperty *>::Grow(m_pList, v6);
    if ( v5 >= m_pList->m_nTop )
      m_pList->m_nTop = v6;
    v7 = m_pList->m_pList[v5];
    this->m_pList->vfptr[1].__vecDelDtor(this->m_pList, this->m_nFree - 5);
    return v7;
  }
}

// File Line: 138
// RVA: 0xEDCD20
unsigned int __fastcall OSuite::TStack<OSuite::ZJsonObject *>::ComputeHash(OSuite::TStack<OSuite::ZJsonObject *> *this)
{
  unsigned __int64 *p_m_nFree; // rbx
  unsigned int v3; // edi
  __int64 v4; // rbp
  unsigned int v5; // eax
  unsigned int v6; // eax
  unsigned int v7; // eax

  p_m_nFree = &this->m_nFree;
  v3 = OSuite::FComputeHashBegin((_exception *)this);
  v4 = 5i64;
  do
  {
    v5 = OSuite::FComputeHash<OSuite::TList<OSuite::ZJsonObject *> *>((_exception *)p_m_nFree++);
    v3 = OSuite::FComputeHashAdd(v3, v5);
    --v4;
  }
  while ( v4 );
  v6 = OSuite::FComputeHash<OSuite::TList<OSuite::ZJsonObject *> *>((_exception *)&this->m_staticList[4]);
  v7 = OSuite::FComputeHashAdd(v3, v6);
  return OSuite::FComputeHashEnd(v7);
}

