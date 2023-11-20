// File Line: 12
// RVA: 0xEE4AE0
void __fastcall OSuite::FDeleteSingletons(OSuite *this)
{
  OSuite::ZObjectVtbl *v1; // rbx
  OSuite::ZDoublyLinkedListBase::ZIteratorBase v2; // [rsp+20h] [rbp-48h]
  OSuite::ZDoublyLinkedListBase::ZIteratorBase v3; // [rsp+38h] [rbp-30h]

  if ( OSuite::s_pSingletons )
  {
    v2.m_pList = 0i64;
    v2.m_pElement = 0i64;
    OSuite::ZDoublyLinkedListBase::ZIteratorBase::ZIteratorBase(
      &v2,
      (OSuite::ZDoublyLinkedListBase *)&OSuite::s_pSingletons->vfptr,
      0i64);
    v3.m_pList = 0i64;
    v3.m_pElement = 0i64;
    v2.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable';
    OSuite::ZDoublyLinkedListBase::ZIteratorBase::ZIteratorBase(
      &v3,
      (OSuite::ZDoublyLinkedListBase *)&OSuite::s_pSingletons->vfptr,
      OSuite::s_pSingletons->m_pHead);
    v3.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable';
    do
    {
      OSuite::ZDoublyLinkedListBase::ZIteratorBase::Previous(&v2);
      v1 = v2.m_pElement[1].vfptr;
      if ( v1 )
        (*(void (__fastcall **)(OSuite::ZObjectVtbl *, signed __int64))v1->__vecDelDtor)(v2.m_pElement[1].vfptr, 1i64);
    }
    while ( v1 != v3.m_pElement[1].vfptr );
    if ( OSuite::s_pSingletons )
      OSuite::s_pSingletons->vfptr->__vecDelDtor((OSuite::ZObject *)OSuite::s_pSingletons, 1u);
  }
}

