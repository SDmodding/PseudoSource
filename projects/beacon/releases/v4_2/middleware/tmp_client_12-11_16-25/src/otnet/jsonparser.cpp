// File Line: 27
// RVA: 0xEDCBAC
void __fastcall OSuite::ZJsonParser::ZJsonParser(OSuite::ZJsonParser *this, OSuite::ZJsonDocument *pRoot)
{
  this->m_pRoot = (OSuite::ZJsonObject *)&pRoot->vfptr;
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZJsonParser::`vftable';
  this->m_pCurrentElement = 0i64;
  this->m_Stack.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TStack<OSuite::ZJsonObject *>::`vftable'{for `OSuite::ZObject'};
  this->m_Stack.m_nFree = 0i64;
  this->m_Stack.vfptr = (OSuite::IHashableVtbl *)&OSuite::TStack<OSuite::ZJsonObject *>::`vftable'{for `OSuite::IHashable'};
  this->m_Stack.m_pList = 0i64;
  this->m_nStage = 0;
}

// File Line: 30
// RVA: 0xEDCBE8
void __fastcall OSuite::ZJsonParser::~ZJsonParser(OSuite::ZJsonParser *this)
{
  bool v1; // zf
  OSuite::ZJsonParser *v2; // rbx
  OSuite::ZRedBlackTreeBase::ZElementBase *v3; // rax
  OSuite::TList<OSuite::ZJsonObject *> *v4; // rcx

  v1 = this->m_Stack.m_nFree == 0;
  v2 = this;
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZJsonParser::`vftable';
  if ( !v1 )
  {
    do
    {
      v3 = OSuite::TStack<OSuite::ZJsonObject *>::Pop((OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *> *)&v2->m_Stack);
      if ( v3 )
        v3->vfptr->__vecDelDtor((OSuite::ZObject *)&v3->vfptr, 1u);
    }
    while ( v2->m_Stack.m_nFree );
  }
  v4 = v2->m_Stack.m_pList;
  v2->m_Stack.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TStack<OSuite::ZJsonObject *>::`vftable'{for `OSuite::ZObject'};
  v2->m_Stack.vfptr = (OSuite::IHashableVtbl *)&OSuite::TStack<OSuite::ZJsonObject *>::`vftable'{for `OSuite::IHashable'};
  if ( v4 )
    v4->vfptr->__vecDelDtor((OSuite::ZObject *)&v4->vfptr, 1u);
  v2->vfptr = (OSuite::ZObjectVtbl *)&OSuite::IParser::`vftable';
}

// File Line: 69
// RVA: 0xEDCD90
char __fastcall OSuite::ZJsonParser::ExtractLiteral(OSuite::ZJsonParser *this, OSuite::IParser::ZCharReaderBase *Stream, OSuite::ZString *sLiteral, bool *outIsString)
{
  char v4; // di
  OSuite::IParser::ZCharReaderBase *v5; // rbp
  OSuite::ZJsonParser *v6; // r15
  bool *v7; // r12
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
  OSuite::ZString *v19; // [rsp+20h] [rbp-A8h]
  OSuite::ZString result; // [rsp+28h] [rbp-A0h]
  OSuite::ZStringBuilder v21; // [rsp+40h] [rbp-88h]

  v4 = 0;
  v5 = Stream;
  v6 = this;
  v7 = outIsString;
  v8 = sLiteral;
  v19 = sLiteral;
  v21.m_Chars.m_pList = 0i64;
  OSuite::ZStringBuilder::ZStringBuilder(&v21, 0x20ui64);
  LOBYTE(v9) = OSuite::IParser::ZCharReaderBase::Read(v5);
  v10 = (_BYTE)v9 == 34;
  if ( (_BYTE)v9 == 34 )
  {
    v11 = OSuite::IParser::ZCharReaderBase::Read(v5);
    v12 = v11;
    if ( (v11 & 0x80u) != 0 )
    {
      v13 = 1;
      while ( !OSuite::ZJsonParser::HandleUtf8(v6, v11) && v12 != -1 )
      {
        OSuite::ZStringBuilder::Append(&v21, v12);
        v11 = OSuite::IParser::ZCharReaderBase::Read(v5);
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
        v8 = v19;
        goto LABEL_25;
      }
      OSuite::ZStringBuilder::Append(&v21, v12);
      v14 = v12;
      v15 = OSuite::IParser::ZCharReaderBase::Read(v5);
      v12 = v15;
      if ( (v15 & 0x80u) != 0 )
      {
        v13 = 1;
        while ( !OSuite::ZJsonParser::HandleUtf8(v6, v15) )
        {
          if ( v12 == -1 )
            goto LABEL_28;
          OSuite::ZStringBuilder::Append(&v21, v12);
          v15 = OSuite::IParser::ZCharReaderBase::Read(v5);
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
      v16 = OSuite::IParser::ZCharReaderBase::Read(v5);
      v9 = v16;
    }
    while ( v16 != -1 && v16 != 44 && !OSuite::IParser::IsWhiteSpace((OSuite::IParser *)&v6->vfptr, v16) );
    OSuite::IParser::ZCharReaderBase::Push(v5, v9);
LABEL_25:
    if ( v7 )
      *v7 = v10;
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
      goto LABEL_15;
    case 2:
      this->m_nStage = 3;
      return 0;
    case 3:
LABEL_15:
      this->m_nStage = 0;
      break;
    default:
      if ( nChar < 0 )
      {
        if ( (nChar & 0xE0) == -64 )
        {
          this->m_nStage = 1;
        }
        else if ( (nChar & 0xF0) == -32 )
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
OSuite::ZJsonObject *__fastcall OSuite::ZJsonParser::OnObject(OSuite::ZJsonParser *this, OSuite::IParser::ZCharReaderBase *Stream)
{
  OSuite::IParser::ZCharReaderBase *v2; // rdi
  OSuite::ZJsonParser *v3; // rbx
  char v4; // bp
  OSuite::ZJsonObject **v5; // rsi
  OSuite::TStack<OSuite::ZJsonObject *> *v6; // rcx
  OSuite::ZJsonObject *v7; // rax
  OSuite::ZJsonValue *v8; // rax
  int v9; // eax
  bool v10; // r15
  OSuite::ZJsonObject *v11; // rdi
  OSuite::ZString sLiteral; // [rsp+20h] [rbp-48h]

  v2 = Stream;
  v3 = this;
  v4 = 0;
  OSuite::IParser::SkipWhiteSpace((OSuite::IParser *)&this->vfptr, Stream);
  v5 = &v3->m_pCurrentElement;
  v6 = &v3->m_Stack;
  if ( v3->m_pCurrentElement )
  {
    OSuite::TStack<OSuite::ZJsonObject *>::Push(v6, &v3->m_pCurrentElement);
    v7 = (OSuite::ZJsonObject *)OSuite::ZObject::operator new(0x28ui64);
    if ( v7 )
    {
      v7->m_Pairs.m_pLists = 0i64;
      OSuite::ZJsonObject::ZJsonObject(v7);
    }
    *v5 = v7;
  }
  else
  {
    *v5 = v3->m_pRoot;
    OSuite::TStack<OSuite::ZJsonObject *>::Push(v6, &v3->m_pRoot);
  }
  while ( 1 )
  {
    OSuite::IParser::SkipWhiteSpace((OSuite::IParser *)&v3->vfptr, v2);
    sLiteral.m_pString = 0i64;
    OSuite::ZString::ZString(&sLiteral);
    if ( !OSuite::ZJsonParser::ExtractLiteral(v3, v2, &sLiteral, 0i64) )
      break;
    OSuite::IParser::SkipWhiteSpace((OSuite::IParser *)&v3->vfptr, v2);
    if ( OSuite::IParser::ZCharReaderBase::Read(v2) != 58 )
      break;
    OSuite::IParser::SkipWhiteSpace((OSuite::IParser *)&v3->vfptr, v2);
    v8 = OSuite::ZJsonParser::OnValue(v3, v2);
    OSuite::ZJsonObject::Add(*v5, &sLiteral, v8);
    OSuite::IParser::SkipWhiteSpace((OSuite::IParser *)&v3->vfptr, v2);
    v9 = OSuite::IParser::ZCharReaderBase::Read(v2);
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
  v11 = *v5;
  *v5 = (OSuite::ZJsonObject *)OSuite::TStack<OSuite::ZJsonObject *>::Pop((OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *> *)&v3->m_Stack);
  if ( !v4 )
    return v11;
  if ( v3->m_pRoot != v11 )
  {
    if ( v11 )
      v11->vfptr->__vecDelDtor((OSuite::ZObject *)&v11->vfptr, 1u);
  }
  return 0i64;
}

// File Line: 265
// RVA: 0xEDD114
OSuite::ZJsonValue *__fastcall OSuite::ZJsonParser::OnValue(OSuite::ZJsonParser *this, OSuite::IParser::ZCharReaderBase *Stream)
{
  OSuite::ZJsonParser *v2; // rsi
  OSuite::IParser::ZCharReaderBase *v3; // rbx
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
  bool outIsString; // [rsp+20h] [rbp-48h]
  OSuite::ZString sLiteral; // [rsp+28h] [rbp-40h]

  v2 = this;
  v3 = Stream;
  v4 = 0;
  v5 = 0i64;
  v6 = OSuite::IParser::ZCharReaderBase::Read(Stream);
  if ( v6 == 123 )
  {
    OSuite::IParser::SkipWhiteSpace((OSuite::IParser *)&v2->vfptr, v3);
    v7 = OSuite::IParser::ZCharReaderBase::Read(v3);
    if ( v7 != 125 )
    {
      OSuite::IParser::ZCharReaderBase::Push(v3, v7);
      v8 = OSuite::ZJsonParser::OnObject(v2, v3);
      if ( v8 )
      {
        OSuite::IParser::SkipWhiteSpace((OSuite::IParser *)&v2->vfptr, v3);
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
      OSuite::IParser::SkipWhiteSpace((OSuite::IParser *)&v2->vfptr, v3);
      v12 = OSuite::IParser::ZCharReaderBase::Read(v3);
      if ( v12 == 93 )
      {
LABEL_6:
        OSuite::IParser::SkipWhiteSpace((OSuite::IParser *)&v2->vfptr, v3);
        return v5;
      }
      OSuite::IParser::ZCharReaderBase::Push(v3, v12);
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
        OSuite::IParser::SkipWhiteSpace((OSuite::IParser *)&v2->vfptr, v3);
        v15 = OSuite::ZJsonParser::OnValue(v2, v3);
        if ( !v15 )
          break;
        OSuite::ZJsonValue::Add(v5, v15);
        OSuite::IParser::SkipWhiteSpace((OSuite::IParser *)&v2->vfptr, v3);
        v16 = OSuite::IParser::ZCharReaderBase::Read(v3);
        outIsString = v16 == 44;
        OSuite::IParser::SkipWhiteSpace((OSuite::IParser *)&v2->vfptr, v3);
        if ( v16 != 44 && v16 != 93 )
          break;
        if ( outIsString != 1 )
          goto LABEL_6;
      }
    }
    else
    {
      OSuite::IParser::ZCharReaderBase::Push(v3, v6);
      sLiteral.m_pString = 0i64;
      outIsString = 1;
      OSuite::ZString::ZString(&sLiteral);
      if ( OSuite::ZJsonParser::ExtractLiteral(v2, v3, &sLiteral, &outIsString) )
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
      v5->vfptr->__vecDelDtor((OSuite::ZObject *)&v5->vfptr, 1u);
  }
  return 0i64;
}

// File Line: 345
// RVA: 0xEDD488
bool __fastcall OSuite::ZJsonParser::Parse(OSuite::ZJsonParser *this, OSuite::IReader *pStream)
{
  OSuite::ZJsonParser *v2; // rbx
  OSuite::IParser::ZStreamCharReader v4; // [rsp+20h] [rbp-88h]

  v4.m_Stack.m_pList = 0i64;
  v2 = this;
  _mm_store_si128((__m128i *)&v4.m_pDecoder, (__m128i)0i64);
  v4.m_pStream = 0i64;
  OSuite::IParser::ZStreamCharReader::ZStreamCharReader(&v4, pStream, (OSuite::IParser *)&this->vfptr);
  LOBYTE(v2) = (__int64)v2->vfptr[1].__vecDelDtor((OSuite::ZObject *)&v2->vfptr, (unsigned int)&v4);
  OSuite::IParser::ZCharReaderBase::~ZCharReaderBase((OSuite::IParser::ZCharReaderBase *)&v4.vfptr);
  return (char)v2;
}

// File Line: 351
// RVA: 0xEDD348
bool __fastcall OSuite::ZJsonParser::Parse(OSuite::ZJsonParser *this, OSuite::IParser::ZCharReaderBase *Stream)
{
  OSuite::ZJsonParser *v2; // rdi
  OSuite::IParser::ZCharReaderBase *v3; // rbx
  bool result; // al

  v2 = this;
  v3 = Stream;
  if ( OSuite::IParser::ZCharReaderBase::Read(Stream) == 123 )
    result = OSuite::ZJsonParser::OnObject(v2, v3) != 0i64;
  else
    result = 0;
  return result;
}

// File Line: 362
// RVA: 0xEDD388
char __fastcall OSuite::ZJsonParser::Parse(OSuite::ZJsonParser *this, OSuite::IHttpResponse *response)
{
  OSuite::ZJsonParser *v2; // rdi
  OSuite::IHttpResponse *v3; // rbx
  char result; // al
  OSuite::IHttpResponseVtbl *v5; // rax
  OSuite::IBufferedReader *v6; // rax
  char v7; // bl
  OSuite::ZString v8; // [rsp+20h] [rbp-59h]
  OSuite::ZString v9; // [rsp+38h] [rbp-41h]
  OSuite::IParser::ZHttpCharReader v10; // [rsp+50h] [rbp-29h]

  v2 = this;
  v3 = response;
  result = response->vfptr->IsHandled(response);
  if ( result )
  {
    v9.m_pString = 0i64;
    OSuite::ZString::ZString(&v8, "content-type");
    (*(void (__fastcall **)(OSuite::IHttpResponse *, OSuite::ZString *, OSuite::ZString *))v3->vfptr->gap8)(
      v3,
      &v9,
      &v8);
    OSuite::ZString::~ZString(&v8);
    if ( OSuite::ZString::operator bool(&v9) && OSuite::ZString::StartsWith(&v9, "application/json") )
    {
      v5 = v3->vfptr;
      v10.m_Stack.m_pList = 0i64;
      v10.m_pStream = 0i64;
      _mm_store_si128((__m128i *)&v10.m_pDecoder, (__m128i)0i64);
      v6 = v5->GetBufferedReader(v3);
      OSuite::IParser::ZHttpCharReader::ZHttpCharReader(&v10, v6, (OSuite::IParser *)&v2->vfptr);
      v7 = (__int64)v2->vfptr[1].__vecDelDtor((OSuite::ZObject *)&v2->vfptr, (unsigned int)&v10);
      OSuite::IParser::ZCharReaderBase::~ZCharReaderBase((OSuite::IParser::ZCharReaderBase *)&v10.vfptr);
    }
    else
    {
      v7 = 0;
    }
    OSuite::ZString::~ZString(&v9);
    result = v7;
  }
  return result;
}

