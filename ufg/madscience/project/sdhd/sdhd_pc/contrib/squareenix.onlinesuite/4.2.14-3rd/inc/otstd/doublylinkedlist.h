// File Line: 60
// RVA: 0x15E240
// attributes: thunk
void __fastcall OSuite::ZDoublyLinkedListBase::~ZDoublyLinkedListBase(OSuite::ZDoublyLinkedListBase *this)
{
  OSuite::ZDoublyLinkedListBase::Clear(this);
}

// File Line: 323
// RVA: 0x15E3D0
OSuite::TDoublyLinkedList<OSuite::ZObject *>::ZElement *__fastcall OSuite::TDoublyLinkedList<OSuite::ZObject *>::Append(
        OSuite::TDoublyLinkedList<OSuite::ZObject *> *this,
        OSuite::ZObject **data)
{
  OSuite::ZObject *v4; // rax
  OSuite::ZObject *v5; // rdx
  OSuite::ZDoublyLinkedListBase::ZElementBase *v6; // rbx

  v4 = (OSuite::ZObject *)OSuite::ZObject::operator new(0x20ui64);
  v6 = (OSuite::ZDoublyLinkedListBase::ZElementBase *)v4;
  if ( v4 )
  {
    OSuite::ZRedBlackTreeBase::ZElementBase::ZElementBase(v4, v5);
    v6->vfptr = (OSuite::ZObjectVtbl *)&OSuite::TDoublyLinkedList<OSuite::ZObject *>::ZElement::`vftable;
    v6[1].vfptr = (OSuite::ZObjectVtbl *)*data;
  }
  else
  {
    v6 = 0i64;
  }
  OSuite::ZDoublyLinkedListBase::AppendElement(this, v6);
  return (OSuite::TDoublyLinkedList<OSuite::ZObject *>::ZElement *)v6;
}

