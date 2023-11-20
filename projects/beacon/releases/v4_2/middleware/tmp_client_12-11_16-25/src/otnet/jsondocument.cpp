// File Line: 10
// RVA: 0xED04E4
void __fastcall OSuite::ZJsonDocument::ZJsonDocument(OSuite::ZJsonDocument *this)
{
  OSuite::ZJsonDocument *v1; // rbx

  v1 = this;
  OSuite::ZJsonObject::ZJsonObject((OSuite::ZJsonObject *)&this->vfptr);
  v1->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZJsonDocument::`vftable';
  v1->m_bIsValid = 0;
}

// File Line: 29
// RVA: 0xED050C
void __fastcall OSuite::ZJsonDocument::~ZJsonDocument(OSuite::ZJsonDocument *this)
{
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZJsonDocument::`vftable';
  OSuite::ZJsonObject::~ZJsonObject((OSuite::ZJsonObject *)&this->vfptr);
}

// File Line: 33
// RVA: 0xED0454
void __fastcall OSuite::ZJsonDocument::ZJsonDocument(OSuite::ZJsonDocument *this, OSuite::IReader *pReader)
{
  OSuite::IReader *v2; // rbx
  OSuite::ZJsonDocument *v3; // rdi
  OSuite::ZJsonParser v4; // [rsp+20h] [rbp-88h]

  v2 = pReader;
  v3 = this;
  OSuite::ZJsonObject::ZJsonObject((OSuite::ZJsonObject *)&this->vfptr);
  v3->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZJsonDocument::`vftable';
  v4.m_pRoot = 0i64;
  v4.m_pCurrentElement = 0i64;
  v4.m_Stack.m_pList = 0i64;
  OSuite::ZJsonParser::ZJsonParser(&v4, v3);
  v3->m_bIsValid = OSuite::ZJsonParser::Parse(&v4, v2);
  OSuite::ZJsonParser::~ZJsonParser(&v4);
}

