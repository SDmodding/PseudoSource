// File Line: 10
// RVA: 0xED04E4
void __fastcall OSuite::ZJsonDocument::ZJsonDocument(OSuite::ZJsonDocument *this)
{
  OSuite::ZJsonObject::ZJsonObject(this);
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZJsonDocument::`vftable;
  this->m_bIsValid = 0;
}

// File Line: 29
// RVA: 0xED050C
void __fastcall OSuite::ZJsonDocument::~ZJsonDocument(OSuite::ZJsonDocument *this)
{
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZJsonDocument::`vftable;
  OSuite::ZJsonObject::~ZJsonObject(this);
}

// File Line: 33
// RVA: 0xED0454
void __fastcall OSuite::ZJsonDocument::ZJsonDocument(OSuite::ZJsonDocument *this, OSuite::IReader *pReader)
{
  OSuite::ZJsonParser v4; // [rsp+20h] [rbp-88h] BYREF

  OSuite::ZJsonObject::ZJsonObject(this);
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZJsonDocument::`vftable;
  v4.m_pRoot = 0i64;
  v4.m_pCurrentElement = 0i64;
  v4.m_Stack.m_pList = 0i64;
  OSuite::ZJsonParser::ZJsonParser(&v4, this);
  this->m_bIsValid = OSuite::ZJsonParser::Parse(&v4, pReader);
  OSuite::ZJsonParser::~ZJsonParser(&v4);
}

