// File Line: 53
// RVA: 0xECD054
OSuite::ZObjectAccessor *__fastcall OSuite::TSingleton<OSuite::ZObjectAccessor>::Object()
{
  OSuite::ZObjectAccessor *result; // rax
  OSuite::ZObjectAccessor *v1; // rax
  OSuite::ZObjectAccessor *v2; // rax
  OSuite::TDoublyLinkedList<OSuite::ZObject *> *v3; // rbx
  OSuite::ZRedBlackTreeBase *v4; // rax
  OSuite::ZObject *data; // [rsp+30h] [rbp+8h]

  result = `OSuite::TSingleton<OSuite::ZObjectAccessor>::Object'::`2'::s_pObject;
  if ( !`OSuite::TSingleton<OSuite::ZObjectAccessor>::Object'::`2'::s_pObject )
  {
    v1 = (OSuite::ZObjectAccessor *)OSuite::ZObject::operator new((unsigned int)((_DWORD)`OSuite::TSingleton<OSuite::ZObjectAccessor>::Object'::`2'::s_pObject
                                                                               + 64));
    if ( v1 )
    {
      v1->m_mapMutex.m_pInternalMutex = 0i64;
      v1->m_LockedObjectAccessMap.m_pLists = 0i64;
      OSuite::ZObjectAccessor::ZObjectAccessor(v1);
      `OSuite::TSingleton<OSuite::ZObjectAccessor>::Object'::`2'::s_pObject = v2;
    }
    else
    {
      `OSuite::TSingleton<OSuite::ZObjectAccessor>::Object'::`2'::s_pObject = 0i64;
    }
    v3 = OSuite::s_pSingletons;
    if ( !OSuite::s_pSingletons )
    {
      v4 = (OSuite::ZRedBlackTreeBase *)OSuite::ZObject::operator new((unsigned int)((_DWORD)OSuite::s_pSingletons + 24));
      v3 = (OSuite::TDoublyLinkedList<OSuite::ZObject *> *)v4;
      if ( v4 )
      {
        v4->m_pTop = 0i64;
        OSuite::ZDoublyLinkedListBase::ZDoublyLinkedListBase(v4);
        v3->vfptr = (OSuite::ZObjectVtbl *)&OSuite::TDoublyLinkedList<OSuite::ZObject *>::`vftable';
      }
      else
      {
        v3 = 0i64;
      }
      OSuite::s_pSingletons = v3;
    }
    data = (OSuite::ZObject *)&`OSuite::TSingleton<OSuite::ZObjectAccessor>::Object'::`2'::s_pObject->vfptr;
    OSuite::TDoublyLinkedList<OSuite::ZObject *>::Append(v3, &data);
    result = `OSuite::TSingleton<OSuite::ZObjectAccessor>::Object'::`2'::s_pObject;
  }
  return result;
}

