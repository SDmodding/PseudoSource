// File Line: 53
// RVA: 0x15E530
OSuite::ZError *__fastcall OSuite::TSingleton<OSuite::ZError>::Object()
{
  OSuite::ZError *result; // rax
  OSuite::ZError *v1; // rax
  OSuite::ZError *v2; // rax
  OSuite::ZError *v3; // rsi
  OSuite::TDoublyLinkedList<OSuite::ZObject *> *v4; // rbx
  OSuite::ZRedBlackTreeBase *v5; // rax
  OSuite::ZObject *v6; // rax
  OSuite::ZObject *v7; // rdx
  OSuite::ZDoublyLinkedListBase::ZElementBase *v8; // rdi

  result = `OSuite::TSingleton<OSuite::ZError>::Object::`2::s_pObject;
  if ( !`OSuite::TSingleton<OSuite::ZError>::Object::`2::s_pObject )
  {
    v1 = (OSuite::ZError *)OSuite::ZObject::operator new(0xF8ui64);
    if ( v1 )
    {
      OSuite::ZError::ZError(v1);
      v3 = v2;
    }
    else
    {
      v3 = 0i64;
    }
    `OSuite::TSingleton<OSuite::ZError>::Object::`2::s_pObject = v3;
    v4 = OSuite::s_pSingletons;
    if ( !OSuite::s_pSingletons )
    {
      v5 = (OSuite::ZRedBlackTreeBase *)OSuite::ZObject::operator new((unsigned int)((_DWORD)OSuite::s_pSingletons + 24));
      v4 = (OSuite::TDoublyLinkedList<OSuite::ZObject *> *)v5;
      if ( v5 )
      {
        OSuite::ZDoublyLinkedListBase::ZDoublyLinkedListBase(v5);
        v4->vfptr = (OSuite::ZObjectVtbl *)&OSuite::TDoublyLinkedList<OSuite::ZObject *>::`vftable;
      }
      else
      {
        v4 = 0i64;
      }
      OSuite::s_pSingletons = v4;
      v3 = `OSuite::TSingleton<OSuite::ZError>::Object::`2::s_pObject;
    }
    v6 = (OSuite::ZObject *)OSuite::ZObject::operator new(0x20ui64);
    v8 = (OSuite::ZDoublyLinkedListBase::ZElementBase *)v6;
    if ( v6 )
    {
      OSuite::ZRedBlackTreeBase::ZElementBase::ZElementBase(v6, v7);
      v8->vfptr = (OSuite::ZObjectVtbl *)&OSuite::TDoublyLinkedList<OSuite::ZObject *>::ZElement::`vftable;
      v8[1].vfptr = (OSuite::ZObjectVtbl *)v3;
    }
    else
    {
      v8 = 0i64;
    }
    OSuite::ZDoublyLinkedListBase::AppendElement((OSuite::ZDoublyLinkedListBase *)&v4->vfptr, v8);
    result = `OSuite::TSingleton<OSuite::ZError>::Object::`2::s_pObject;
  }
  return result;
}

