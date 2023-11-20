// File Line: 49
// RVA: 0xEE4E70
OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *> *__fastcall OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::operator=(OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *> *this, OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *> *that)
{
  OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *> *v2; // rsi
  OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *> *v3; // rdi
  unsigned __int64 v4; // rax
  OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *v5; // rbx
  unsigned __int64 v6; // rcx
  OSuite::ZRedBlackTreeBase::ZElementBase **v7; // r8
  OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *v8; // rcx
  OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *v9; // rax
  OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *v10; // rax

  v2 = that;
  v3 = this;
  if ( this != that )
  {
    v4 = that->m_nFree;
    v5 = 0i64;
    this->m_nFree = v4;
    v6 = 0i64;
    if ( v4 )
    {
      v7 = v3->m_staticList;
      do
      {
        if ( v6 >= 5 )
          break;
        ++v6;
        *v7 = *(OSuite::ZRedBlackTreeBase::ZElementBase **)((char *)v7 + (char *)that - (char *)v3);
        ++v7;
      }
      while ( v6 < v3->m_nFree );
    }
    v8 = v3->m_pList;
    if ( v8 )
      v8->vfptr->__vecDelDtor((OSuite::ZObject *)&v8->vfptr, 1u);
    if ( v2->m_pList )
    {
      v9 = (OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *)OSuite::ZObject::operator new(0x28ui64);
      if ( v9 )
      {
        v9->m_pList = 0i64;
        OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *>::TList<OSuite::ZRedBlackTreeBase::ZElementBase *>(
          v9,
          v2->m_pList);
        v5 = v10;
      }
    }
    v3->m_pList = v5;
  }
  return v3;
}

// File Line: 69
// RVA: 0xEE0B78
void __fastcall OSuite::TStack<int>::Push(OSuite::TStack<int> *this, const int *element)
{
  OSuite::TStack<int> *v2; // rdi
  unsigned __int64 v3; // rcx
  const int *v4; // rsi
  OSuite::ZObject *v5; // rax
  OSuite::ZObject *v6; // rdx
  OSuite::ZObject *v7; // rbx
  OSuite::ZObjectVtbl *v8; // rax
  OSuite::TList<int> *v9; // rbx

  v2 = this;
  v3 = this->m_nFree;
  v4 = element;
  if ( v3 >= 9 )
  {
    if ( !v2->m_pList )
    {
      v5 = (OSuite::ZObject *)OSuite::ZObject::operator new(0x28ui64);
      v7 = v5;
      if ( v5 )
      {
        v5[4].vfptr = 0i64;
        OSuite::ZRedBlackTreeBase::ZElementBase::ZElementBase(v5, v6);
        v7[4].vfptr = 0i64;
        v7->vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<int>::`vftable{for `OSuite::ZListBase};
        v7[3].vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<int>::`vftable{for `OSuite::IHashable};
        v8 = (OSuite::ZObjectVtbl *)OSuite::ZObject::malloc(v7, 0x40ui64, 0i64);
        v7[2].vfptr = 0i64;
        v7[1].vfptr = (OSuite::ZObjectVtbl *)16;
        v7[4].vfptr = v8;
      }
      else
      {
        v7 = 0i64;
      }
      v2->m_pList = (OSuite::TList<int> *)v7;
    }
    v9 = v2->m_pList;
    OSuite::TList<int>::Grow(v9, v9->m_nTop + 1);
    v9->m_pList[v9->m_nTop++] = *v4;
  }
  else
  {
    v2->m_staticList[v3] = *element;
  }
  ++v2->m_nFree;
}

// File Line: 90
// RVA: 0xEE6770
OSuite::ZRedBlackTreeBase::ZElementBase *__fastcall OSuite::TStack<OSuite::ZJsonObject *>::Pop(OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *> *this)
{
  unsigned __int64 v1; // rax
  OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *> *v2; // rdi
  OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *v3; // rbx
  unsigned __int64 v4; // rax
  unsigned __int64 v5; // rbp
  unsigned __int64 v6; // rsi
  OSuite::ZRedBlackTreeBase::ZElementBase *v7; // rbx
  OSuite::ZRedBlackTreeBase::ZElementBase *result; // rax
  unsigned __int64 v9; // rax

  v1 = this->m_nFree;
  v2 = this;
  if ( v1 <= 5 )
  {
    v9 = v1 - 1;
    this->m_nFree = v9;
    result = this->m_staticList[v9];
  }
  else
  {
    v3 = this->m_pList;
    v4 = v1 - 1;
    v5 = v4 - 5;
    this->m_nFree = v4;
    v6 = v4 - 5 + 1;
    OSuite::TList<OSuite::ZONavigationProperty *>::Grow(v3, v6);
    if ( v5 >= v3->m_nTop )
      v3->m_nTop = v6;
    v7 = v3->m_pList[v5];
    v2->m_pList->vfptr[1].__vecDelDtor((OSuite::ZObject *)&v2->m_pList->vfptr, v2->m_nFree - 5);
    result = v7;
  }
  return result;
}

// File Line: 138
// RVA: 0xEDCD20
unsigned int __fastcall OSuite::TStack<OSuite::ZJsonObject *>::ComputeHash(OSuite::TStack<OSuite::ZJsonObject *> *this)
{
  OSuite::TStack<OSuite::ZJsonObject *> *v1; // rsi
  const unsigned __int64 *v2; // rbx
  unsigned int v3; // edi
  signed __int64 v4; // rbp
  unsigned int v5; // eax
  unsigned int v6; // eax
  unsigned int v7; // eax

  v1 = this;
  v2 = &this->m_nFree;
  v3 = OSuite::FComputeHashBegin((_exception *)this);
  v4 = 5i64;
  do
  {
    v5 = OSuite::FComputeHash<OSuite::TList<OSuite::ZJsonObject *> *>(v2);
    ++v2;
    v3 = OSuite::FComputeHashAdd(v3, v5);
    --v4;
  }
  while ( v4 );
  v6 = OSuite::FComputeHash<OSuite::TList<OSuite::ZJsonObject *> *>((const unsigned __int64 *)&v1->m_staticList[4]);
  v7 = OSuite::FComputeHashAdd(v3, v6);
  return OSuite::FComputeHashEnd(v7);
}

