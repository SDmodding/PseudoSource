// File Line: 92
// RVA: 0x4295B0
void __fastcall OSuite::TList<OSuite::ZServiceOperationValue *>::ZIterator::~ZIterator(
        OSuite::TList<OSuite::ZServiceOperationValue *>::ZIterator *this)
{
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZServiceOperationValue *>::ZIterator::`vftable;
}

// File Line: 222
// RVA: 0x42E750
OSuite::TList<OSuite::ZServiceOperationValue *>::ZIterator *__fastcall OSuite::TList<OSuite::ZServiceOperationValue *>::Iterator(
        OSuite::TList<OSuite::ZServiceOperationValue *> *this,
        OSuite::TList<OSuite::ZServiceOperationValue *>::ZIterator *result)
{
  OSuite::ZListBase::ZListIteratorBase::ZListIteratorBase(result, this);
  result->vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZServiceOperationValue *>::ZIterator::`vftable;
  return result;
}

// File Line: 231
// RVA: 0x42E7A0
OSuite::TConstIterator<OSuite::TList<OSuite::ZServiceOperationValue *>::ZIterator,OSuite::ZServiceOperationValue *,int> *__fastcall OSuite::TList<OSuite::ZServiceOperationValue *>::Iterator(
        OSuite::TList<OSuite::ZServiceOperationValue *> *this,
        OSuite::TConstIterator<OSuite::TList<OSuite::ZServiceOperationValue *>::ZIterator,OSuite::ZServiceOperationValue *,int> *result)
{
  OSuite::TList<OSuite::ZServiceOperationValue *>::ZIterator *v3; // rax
  OSuite::TList<OSuite::ZServiceOperationValue *>::ZIterator resulta; // [rsp+30h] [rbp-28h] BYREF

  v3 = OSuite::TList<OSuite::ZServiceOperationValue *>::Iterator(this, &resulta);
  result->vfptr = (OSuite::ZObjectVtbl *)&OSuite::TConstIterator<OSuite::TList<OSuite::ZServiceOperationValue *>::ZIterator,OSuite::ZServiceOperationValue *,int>::`vftable;
  OSuite::ZListBase::ZListIteratorBase::ZListIteratorBase(&result->m_iterator, v3);
  result->m_iterator.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZServiceOperationValue *>::ZIterator::`vftable;
  return result;
}

// File Line: 576
// RVA: 0x42D480
void __fastcall OSuite::TList<OSuite::ZServiceOperationValue *>::Grow(
        OSuite::TList<OSuite::ZServiceOperationValue *> *this,
        unsigned __int64 nNewSize)
{
  unsigned __int64 v3; // rdi
  unsigned __int64 v4; // rsi
  OSuite::ZServiceOperationValue **v5; // r14

  if ( nNewSize > this->m_nSize )
  {
    v3 = 0i64;
    v4 = nNewSize + (nNewSize >> 1);
    if ( v4 < 8 )
      v4 = 8i64;
    v5 = (OSuite::ZServiceOperationValue **)OSuite::ZObject::malloc(this, 8 * v4, 0i64);
    if ( this->m_nTop )
    {
      do
      {
        ++v3;
        v5[v3 - 1] = this->m_pList[v3 - 1];
      }
      while ( v3 < this->m_nTop );
    }
    OSuite::ZObject::free(this, this->m_pList);
    this->m_pList = v5;
    this->m_nSize = v4;
  }
}

