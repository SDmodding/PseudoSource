// File Line: 27
// RVA: 0xEDCBAC
void __fastcall OSuite::ZJsonParser::ZJsonParser(OSuite::ZJsonParser *this, OSuite::ZJsonDocument *pRoot)
{
  this->m_pRoot = pRoot;
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZJsonParser::`vftable;
  this->m_pCurrentElement = 0i64;
  this->m_Stack.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TStack<OSuite::ZJsonObject *>::`vftable{for `OSuite::ZObject};
  this->m_Stack.m_nFree = 0i64;
  this->m_Stack.vfptr = (OSuite::IHashableVtbl *)&OSuite::TStack<OSuite::ZJsonObject *>::`vftable{for `OSuite::IHashable};
  this->m_Stack.m_pList = 0i64;
  this->m_nStage = 0;
}

// File Line: 30
// RVA: 0xEDCBE8
void __fastcall OSuite::ZJsonParser::~ZJsonParser(OSuite::ZJsonParser *this)
{
  bool v1; // zf
  OSuite::ZRedBlackTreeBase::ZElementBase *v3; // rax
  OSuite::TList<OSuite::ZJsonObject *> *m_pList; // rcx

  v1 = this->m_Stack.m_nFree == 0;
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZJsonParser::`vftable;
  if ( !v1 )
  {
    do
    {
      v3 = OSuite::TStack<OSuite::ZJsonObject *>::Pop((OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *> *)&this->m_Stack);
      if ( v3 )
        v3->vfptr->__vecDelDtor(v3, 1u);
    }
    while ( this->m_Stack.m_nFree );
  }
  m_pList = this->m_Stack.m_pList;
  this->m_Stack.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TStack<OSuite::ZJsonObject *>::`vftable{for `OSuite::ZObject};
  this->m_Stack.vfptr = (OSuite::IHashableVtbl *)&OSuite::TStack<OSuite::ZJsonObject *>::`vftable{for `OSuite::IHashable};
  if ( m_pList )
    m_pList->OSuite::ZListBase::OSuite::ZObject::vfptr->__vecDelDtor(m_pList, 1u);
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::IParser::`vftable;
}

// File Line: 69
// RVA: 0xEDCD90
char __fastcall OSuite::ZJsonParser::ExtractLiteral(
        OSuite::ZJsonParser *this,
        OSuite::IParser::ZCharReaderBase *Stream,
        OSuite::ZString *sLiteral,
        bool *outIsString)
{
  char v4; // di
  OSuite::ZString *v8; // rsi
  int v9; // ebx
  bool v10; // r13
  int v11; // eax
  int v12; // ebx
  char v13; // si
  char v14; // r14
  int v15; // eax
  int v16; // eax
  OSuite::ZString *v17; // rax
  OSuite::ZString result; // [rsp+28h] [rbp-A0h] BYREF
  OSuite::ZStringBuilder v21; // [rsp+40h] [rbp-88h] BYREF

  v4 = 0;
  v8 = sLiteral;
  v21.m_Chars.m_pList = 0i64;
  OSuite::ZStringBuilder::ZStringBuilder(&v21, 0x20ui64);
  LOBYTE(v9) = OSuite::IParser::ZCharReaderBase::Read(Stream);
  v10 = (_BYTE)v9 == 34;
  if ( (_BYTE)v9 == 34 )
  {
    v11 = OSuite::IParser::ZCharReaderBase::Read(Stream);
    v12 = v11;
    if ( (v11 & 0x80u) != 0 )
    {
      v13 = 1;
      while ( !OSuite::ZJsonParser::HandleUtf8(this, v11) && v12 != -1 )
      {
        OSuite::ZStringBuilder::Append(&v21, v12);
        v11 = OSuite::IParser::ZCharReaderBase::Read(Stream);
        v12 = v11;
      }
    }
    else
    {
      v13 = 0;
    }
    v14 = v12;
    while ( v12 != -1 )
    {
      if ( !v13 && (_BYTE)v12 == 34 && v14 != 92 )
      {
        v8 = sLiteral;
        goto LABEL_25;
      }
      OSuite::ZStringBuilder::Append(&v21, v12);
      v14 = v12;
      v15 = OSuite::IParser::ZCharReaderBase::Read(Stream);
      v12 = v15;
      if ( (v15 & 0x80u) != 0 )
      {
        v13 = 1;
        while ( !OSuite::ZJsonParser::HandleUtf8(this, v15) )
        {
          if ( v12 == -1 )
            goto LABEL_28;
          OSuite::ZStringBuilder::Append(&v21, v12);
          v15 = OSuite::IParser::ZCharReaderBase::Read(Stream);
          v12 = v15;
        }
      }
      else
      {
        v13 = 0;
      }
    }
  }
  else
  {
    do
    {
      OSuite::ZStringBuilder::Append(&v21, v9);
      v16 = OSuite::IParser::ZCharReaderBase::Read(Stream);
      v9 = v16;
    }
    while ( v16 != -1 && v16 != 44 && !OSuite::IParser::IsWhiteSpace(this, v16) );
    OSuite::IParser::ZCharReaderBase::Push(Stream, v9);
LABEL_25:
    if ( outIsString )
      *outIsString = v10;
    v17 = OSuite::ZStringBuilder::ToString(&v21, &result);
    OSuite::ZString::operator=(v8, v17);
    OSuite::ZString::~ZString(&result);
    v4 = 1;
  }
LABEL_28:
  OSuite::ZUtf8Buffer::~ZUtf8Buffer(&v21);
  return v4;
}

// File Line: 167
// RVA: 0xEDCF48
char __fastcall OSuite::ZJsonParser::HandleUtf8(OSuite::ZJsonParser *this, char nChar)
{
  switch ( this->m_nStage )
  {
    case 1:
      goto LABEL_11;
    case 2:
      this->m_nStage = 3;
      return 0;
    case 3:
LABEL_11:
      this->m_nStage = 0;
      break;
    default:
      if ( nChar < 0 )
      {
        if ( (nChar & 0xE0) == 0xC0 )
        {
          this->m_nStage = 1;
        }
        else if ( (nChar & 0xF0) == 0xE0 )
        {
          this->m_nStage = 2;
        }
        return 0;
      }
      break;
  }
  return 1;
}

// File Line: 207
// RVA: 0xEDCF94
OSuite::ZJsonObject *__fastcall OSuite::ZJsonParser::OnObject(
        OSuite::ZJsonParser *this,
        OSuite::IParser::ZCharReaderBase *Stream)
{
  char v4; // bp
  OSuite::ZJsonObject **p_m_pCurrentElement; // rsi
  OSuite::TStack<OSuite::ZJsonObject *> *p_m_Stack; // rcx
  OSuite::ZJsonObject *v7; // rax
  OSuite::ZUsageTracker *v8; // rax
  int v9; // eax
  bool v10; // r15
  OSuite::ZJsonObject *v11; // rdi
  OSuite::ZString sLiteral; // [rsp+20h] [rbp-48h] BYREF

  v4 = 0;
  OSuite::IParser::SkipWhiteSpace(this, Stream);
  p_m_pCurrentElement = &this->m_pCurrentElement;
  p_m_Stack = &this->m_Stack;
  if ( this->m_pCurrentElement )
  {
    OSuite::TStack<OSuite::ZJsonObject *>::Push(p_m_Stack, &this->m_pCurrentElement);
    v7 = (OSuite::ZJsonObject *)OSuite::ZObject::operator new(0x28ui64);
    if ( v7 )
    {
      v7->m_Pairs.m_pLists = 0i64;
      OSuite::ZJsonObject::ZJsonObject(v7);
    }
    *p_m_pCurrentElement = v7;
  }
  else
  {
    *p_m_pCurrentElement = this->m_pRoot;
    OSuite::TStack<OSuite::ZJsonObject *>::Push(p_m_Stack, &this->m_pRoot);
  }
  while ( 1 )
  {
    OSuite::IParser::SkipWhiteSpace(this, Stream);
    sLiteral.m_pString = 0i64;
    OSuite::ZString::ZString(&sLiteral);
    if ( !OSuite::ZJsonParser::ExtractLiteral(this, Stream, &sLiteral, 0i64) )
      break;
    OSuite::IParser::SkipWhiteSpace(this, Stream);
    if ( OSuite::IParser::ZCharReaderBase::Read(Stream) != 58 )
      break;
    OSuite::IParser::SkipWhiteSpace(this, Stream);
    v8 = (OSuite::ZUsageTracker *)OSuite::ZJsonParser::OnValue(this, Stream);
    OSuite::ZJsonObject::Add(*p_m_pCurrentElement, &sLiteral, v8);
    OSuite::IParser::SkipWhiteSpace(this, Stream);
    v9 = OSuite::IParser::ZCharReaderBase::Read(Stream);
    v10 = v9 != 125;
    if ( v9 != 125 && v9 != 44 )
      break;
    OSuite::ZString::~ZString(&sLiteral);
    if ( !v10 )
      goto LABEL_13;
  }
  v4 = 1;
  OSuite::ZString::~ZString(&sLiteral);
LABEL_13:
  v11 = *p_m_pCurrentElement;
  *p_m_pCurrentElement = (OSuite::ZJsonObject *)OSuite::TStack<OSuite::ZJsonObject *>::Pop((OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *> *)&this->m_Stack);
  if ( !v4 )
    return v11;
  if ( this->m_pRoot != v11 )
  {
    if ( v11 )
      v11->vfptr->__vecDelDtor(v11, 1u);
  }
  return 0i64;
}

// File Line: 265
// RVA: 0xEDD114
OSuite::ZJsonValue *__fastcall OSuite::ZJsonParser::OnValue(
        OSuite::ZJsonParser *this,
        OSuite::IParser::ZCharReaderBase *Stream)
{
  char v4; // bp
  OSuite::ZJsonValue *v5; // rdi
  int v6; // eax
  int v7; // eax
  OSuite::ZJsonObject *v8; // rdi
  OSuite::ZJsonValue *v9; // rax
  OSuite::ZJsonValue *v10; // rax
  int v12; // eax
  OSuite::ZJsonValue *v13; // rax
  OSuite::ZJsonValue *v14; // rax
  OSuite::ZJsonValue *v15; // rax
  int v16; // ebp
  OSuite::ZJsonValue *v17; // rax
  bool v18; // r8
  OSuite::ZJsonValue *v19; // rax
  bool outIsString; // [rsp+20h] [rbp-48h] BYREF
  OSuite::ZString sLiteral; // [rsp+28h] [rbp-40h] BYREF

  v4 = 0;
  v5 = 0i64;
  v6 = OSuite::IParser::ZCharReaderBase::Read(Stream);
  if ( v6 == 123 )
  {
    OSuite::IParser::SkipWhiteSpace(this, Stream);
    v7 = OSuite::IParser::ZCharReaderBase::Read(Stream);
    if ( v7 != 125 )
    {
      OSuite::IParser::ZCharReaderBase::Push(Stream, v7);
      v8 = OSuite::ZJsonParser::OnObject(this, Stream);
      if ( v8 )
      {
        OSuite::IParser::SkipWhiteSpace(this, Stream);
        v9 = (OSuite::ZJsonValue *)OSuite::ZObject::operator new(0x60ui64);
        if ( v9 )
        {
          v9->m_literal.m_pString = 0i64;
          v9->m_array.m_pList = 0i64;
          v9->m_object = 0i64;
          OSuite::ZJsonValue::ZJsonValue(v9, v8);
          v5 = v10;
        }
        else
        {
          v5 = 0i64;
        }
        goto LABEL_6;
      }
    }
  }
  else
  {
    if ( v6 == 91 )
    {
      OSuite::IParser::SkipWhiteSpace(this, Stream);
      v12 = OSuite::IParser::ZCharReaderBase::Read(Stream);
      if ( v12 == 93 )
      {
LABEL_6:
        OSuite::IParser::SkipWhiteSpace(this, Stream);
        return v5;
      }
      OSuite::IParser::ZCharReaderBase::Push(Stream, v12);
      v13 = (OSuite::ZJsonValue *)OSuite::ZObject::operator new(0x60ui64);
      if ( v13 )
      {
        v13->m_literal.m_pString = 0i64;
        v13->m_array.m_pList = 0i64;
        v13->m_object = 0i64;
        OSuite::ZJsonValue::ZJsonValue(v13);
        v5 = v14;
      }
      while ( 1 )
      {
        OSuite::IParser::SkipWhiteSpace(this, Stream);
        v15 = OSuite::ZJsonParser::OnValue(this, Stream);
        if ( !v15 )
          break;
        OSuite::ZJsonValue::Add(v5, v15);
        OSuite::IParser::SkipWhiteSpace(this, Stream);
        v16 = OSuite::IParser::ZCharReaderBase::Read(Stream);
        outIsString = v16 == 44;
        OSuite::IParser::SkipWhiteSpace(this, Stream);
        if ( v16 != 44 && v16 != 93 )
          break;
        if ( !outIsString )
          goto LABEL_6;
      }
    }
    else
    {
      OSuite::IParser::ZCharReaderBase::Push(Stream, v6);
      sLiteral.m_pString = 0i64;
      outIsString = 1;
      OSuite::ZString::ZString(&sLiteral);
      if ( OSuite::ZJsonParser::ExtractLiteral(this, Stream, &sLiteral, &outIsString) )
      {
        v17 = (OSuite::ZJsonValue *)OSuite::ZObject::operator new(0x60ui64);
        if ( v17 )
        {
          v18 = outIsString;
          v17->m_literal.m_pString = 0i64;
          v17->m_array.m_pList = 0i64;
          v17->m_object = 0i64;
          OSuite::ZJsonValue::ZJsonValue(v17, &sLiteral, v18);
          v5 = v19;
        }
      }
      else
      {
        v4 = 1;
      }
      OSuite::ZString::~ZString(&sLiteral);
      if ( !v4 )
        goto LABEL_6;
    }
    if ( v5 )
      v5->vfptr->__vecDelDtor(v5, 1u);
  }
  return 0i64;
}

// File Line: 345
// RVA: 0xEDD488
bool __fastcall OSuite::ZJsonParser::Parse(OSuite::ZJsonParser *this, OSuite::IReader *pStream)
{
  OSuite::ZJsonParser *v2; // rbx
  OSuite::IParser::ZStreamCharReader v4; // [rsp+20h] [rbp-88h] BYREF

  memset(&v4.m_Stack.m_pList, 0, 32);
  v2 = this;
  OSuite::IParser::ZStreamCharReader::ZStreamCharReader(&v4, pStream, this);
  LOBYTE(v2) = v2->vfptr[1].__vecDelDtor(v2, (unsigned int)&v4);
  OSuite::IParser::ZCharReaderBase::~ZCharReaderBase(&v4);
  return (char)v2;
}

// File Line: 351
// RVA: 0xEDD348
bool __fastcall OSuite::ZJsonParser::Parse(OSuite::ZJsonParser *this, OSuite::IParser::ZCharReaderBase *Stream)
{
  return OSuite::IParser::ZCharReaderBase::Read(Stream) == 123 && OSuite::ZJsonParser::OnObject(this, Stream) != 0i64;
}

// File Line: 362
// RVA: 0xEDD388
char __fastcall OSuite::ZJsonParser::Parse(OSuite::ZJsonParser *this, OSuite::IHttpResponse *response)
{
  char result; // al
  OSuite::IHttpResponseVtbl *vfptr; // rax
  OSuite::IBufferedReader *v6; // rax
  char v7; // bl
  OSuite::ZString v8; // [rsp+20h] [rbp-59h] BYREF
  OSuite::ZString v9; // [rsp+38h] [rbp-41h] BYREF
  OSuite::IParser::ZHttpCharReader v10; // [rsp+50h] [rbp-29h] BYREF

  result = response->vfptr->IsHandled(response);
  if ( result )
  {
    v9.m_pString = 0i64;
    OSuite::ZString::ZString(&v8, "content-type");
    (*(void (__fastcall **)(OSuite::IHttpResponse *, OSuite::ZString *, OSuite::ZString *))response->vfptr->gap8)(
      response,
      &v9,
      &v8);
    OSuite::ZString::~ZString(&v8);
    if ( OSuite::ZString::operator bool(&v9) && OSuite::ZString::StartsWith(&v9, "application/json") )
    {
      vfptr = response->vfptr;
      memset(&v10.m_Stack.m_pList, 0, 32);
      v6 = vfptr->GetBufferedReader(response);
      OSuite::IParser::ZHttpCharReader::ZHttpCharReader(&v10, v6, this);
      v7 = (char)this->vfptr[1].__vecDelDtor(this, &v10);
      OSuite::IParser::ZCharReaderBase::~ZCharReaderBase(&v10);
    }
    else
    {
      v7 = 0;
    }
    OSuite::ZString::~ZString(&v9);
    return v7;
  }
  return result;
}

