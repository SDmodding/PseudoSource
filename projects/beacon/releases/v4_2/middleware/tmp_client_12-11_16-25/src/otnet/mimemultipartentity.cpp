// File Line: 25
// RVA: 0xEDDF88
void __fastcall OSuite::ZMimeMultipartEntity::ZMimeMultipartEntity(OSuite::ZMimeMultipartEntity *this)
{
  OSuite::ZMimeMultipartEntity *v1; // rdi

  v1 = this;
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZMimeMultipartEntity::`vftable;
  OSuite::ZDoublyLinkedListBase::ZDoublyLinkedListBase((OSuite::ZRedBlackTreeBase *)&this->m_Parts);
  v1->m_Parts.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TDoublyLinkedList<OSuite::ZSocketManager::InternalSocket>::`vftable;
}

// File Line: 32
// RVA: 0xEDDFC4
void __fastcall OSuite::ZMimeMultipartEntity::~ZMimeMultipartEntity(OSuite::ZMimeMultipartEntity *this)
{
  OSuite::ZDoublyLinkedListBase *v1; // rbx
  OSuite::ZObjectVtbl *v2; // rcx
  OSuite::ZDoublyLinkedListBase::ZIteratorBase v3; // [rsp+20h] [rbp-28h]

  v3.m_pList = 0i64;
  v3.m_pElement = 0i64;
  v1 = (OSuite::ZDoublyLinkedListBase *)&this->m_Parts.vfptr;
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZMimeMultipartEntity::`vftable;
  OSuite::ZDoublyLinkedListBase::ZIteratorBase::ZIteratorBase(
    &v3,
    (OSuite::ZDoublyLinkedListBase *)&this->m_Parts.vfptr,
    this->m_Parts.m_pHead);
  v3.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable;
  while ( !OSuite::ZString::IsNull((OSuite::ZString *)&v3) )
  {
    v2 = v3.m_pElement[1].vfptr;
    if ( v2 )
      (*(void (__fastcall **)(OSuite::ZObjectVtbl *, signed __int64))v2->__vecDelDtor)(v2, 1i64);
    OSuite::ZDoublyLinkedListBase::ZIteratorBase::Next(&v3);
  }
  v1->vfptr = (OSuite::ZObjectVtbl *)&OSuite::TDoublyLinkedList<OSuite::ZSocketManager::InternalSocket>::`vftable;
  OSuite::ZDoublyLinkedListBase::Clear(v1);
}

// File Line: 91
// RVA: 0xEDE098
char __fastcall OSuite::ZMimeMultipartEntity::PostTo(OSuite::ZMimeMultipartEntity *this, OSuite::IHttpRequest *request)
{
  OSuite::ZMimeMultipartEntity *v2; // rdi
  OSuite::IHttpRequest *v3; // rsi
  size_t v4; // rbx
  size_t v5; // rbp
  char v6; // al
  char v7; // bl
  OSuite::ZDoublyLinkedListBase::ZIteratorBase v9; // [rsp+20h] [rbp-38h]

  v2 = this;
  v3 = request;
  v4 = strlen("Media multipart posting\r\n--END_OF_PART_A8F9CE13-8F1B-4850-92AA-09C6B00ADA1F\r\n");
  v5 = strlen("\r\n--END_OF_PART_A8F9CE13-8F1B-4850-92AA-09C6B00ADA1F\r\n");
  v6 = ((__int64 (__fastcall *)(OSuite::IHttpRequest *, const char *, size_t))v3->vfptr[14].__vecDelDtor)(
         v3,
         "Media multipart posting\r\n--END_OF_PART_A8F9CE13-8F1B-4850-92AA-09C6B00ADA1F\r\n",
         v4);
  v9.m_pList = 0i64;
  v9.m_pElement = 0i64;
  v7 = v6;
  OSuite::ZDoublyLinkedListBase::ZIteratorBase::ZIteratorBase(
    &v9,
    (OSuite::ZDoublyLinkedListBase *)&v2->m_Parts.vfptr,
    v2->m_Parts.m_pHead);
  v9.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable;
  while ( !OSuite::ZString::IsNull((OSuite::ZString *)&v9) && v7 )
  {
    OSuite::ZMimeEntity::SerializeTo((OSuite::ZMimeEntity *)v9.m_pElement[1].vfptr, v3);
    v7 = ((__int64 (__fastcall *)(OSuite::IHttpRequest *, const char *, size_t))v3->vfptr[14].__vecDelDtor)(
           v3,
           "\r\n--END_OF_PART_A8F9CE13-8F1B-4850-92AA-09C6B00ADA1F\r\n",
           v5);
    OSuite::ZDoublyLinkedListBase::ZIteratorBase::Next(&v9);
  }
  return v7;
}

