// File Line: 92
// RVA: 0x4295B0
void __fastcall OSuite::TList<OSuite::ZServiceOperationValue *>::ZIterator::~ZIterator(OSuite::TList<OSuite::ZServiceOperationValue *>::ZIterator *this)
{
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZServiceOperationValue *>::ZIterator::`vftable;
}

// File Line: 222
// RVA: 0x42E750
OSuite::TList<OSuite::ZServiceOperationValue *>::ZIterator *__fastcall OSuite::TList<OSuite::ZServiceOperationValue *>::Iterator(OSuite::TList<OSuite::ZServiceOperationValue *> *this, OSuite::TList<OSuite::ZServiceOperationValue *>::ZIterator *result)
{
  OSuite::TList<OSuite::ZServiceOperationValue *>::ZIterator *v2; // rbx

  v2 = result;
  OSuite::ZListBase::ZListIteratorBase::ZListIteratorBase(
    (OSuite::ZListBase::ZListIteratorBase *)&result->vfptr,
    (OSuite::ZListBase *)&this->vfptr);
  v2->vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZServiceOperationValue *>::ZIterator::`vftable;
  return v2;
}

// File Line: 231
// RVA: 0x42E7A0
OSuite::TConstIterator<OSuite::TList<OSuite::ZServiceOperationValue *>::ZIterator,OSuite::ZServiceOperationValue *,int> *__fastcall OSuite::TList<OSuite::ZServiceOperationValue *>::Iterator(OSuite::TList<OSuite::ZServiceOperationValue *> *this, OSuite::TConstIterator<OSuite::TList<OSuite::ZServiceOperationValue *>::ZIterator,OSuite::ZServiceOperationValue *,int> *result)
{
  OSuite::TConstIterator<OSuite::TList<OSuite::ZServiceOperationValue *>::ZIterator,OSuite::ZServiceOperationValue *,int> *v2; // rdi
  OSuite::TList<OSuite::ZServiceOperationValue *>::ZIterator *v3; // rax
  OSuite::TList<OSuite::ZServiceOperationValue *>::ZIterator resulta; // [rsp+30h] [rbp-28h]

  v2 = result;
  v3 = OSuite::TList<OSuite::ZServiceOperationValue *>::Iterator(this, &resulta);
  v2->vfptr = (OSuite::ZObjectVtbl *)&OSuite::TConstIterator<OSuite::TList<OSuite::ZServiceOperationValue *>::ZIterator,OSuite::ZServiceOperationValue *,int>::`vftable;
  OSuite::ZListBase::ZListIteratorBase::ZListIteratorBase(
    (OSuite::ZListBase::ZListIteratorBase *)&v2->m_iterator.vfptr,
    (OSuite::ZListBase::ZListIteratorBase *)&v3->vfptr);
  v2->m_iterator.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZServiceOperationValue *>::ZIterator::`vftable;
  return v2;
}

// File Line: 576
// RVA: 0x42D480
void __fastcall OSuite::TList<OSuite::ZServiceOperationValue *>::Grow(OSuite::TList<OSuite::ZServiceOperationValue *> *this, unsigned __int64 nNewSize)
{
  OSuite::TList<OSuite::ZServiceOperationValue *> *v2; // rbx
  unsigned __int64 v3; // rdi
  unsigned __int64 v4; // rsi
  OSuite::ZServiceOperationValue **v5; // r14

  v2 = this;
  if ( nNewSize <= this->m_nSize )
    return;
  v3 = 0i64;
  v4 = nNewSize + (nNewSize >> 1);
  if ( v4 >= 8 )
  {
    if ( !v4 )
    {
      v5 = 0i64;
      goto LABEL_7;
    }
  }
  else
  {
    v4 = 8i64;
  }
  v5 = (OSuite::ZServiceOperationValue **)OSuite::ZObject::malloc((OSuite::ZObject *)&this->vfptr, 8 * v4, 0i64);
LABEL_7:
  if ( v2->m_nTop > 0 )
  {
    do
    {
      ++v3;
      v5[v3 - 1] = v2->m_pList[v3 - 1];
    }
    while ( v3 < v2->m_nTop );
  }
  OSuite::ZObject::free((OSuite::ZObject *)&v2->vfptr, v2->m_pList);
  v2->m_pList = v5;
  v2->m_nSize = v4;
}

