// File Line: 8
// RVA: 0xEE0CD0
void __fastcall OSuite::IParser::SkipWhiteSpace(OSuite::IParser *this, OSuite::IParser::ZCharReaderBase *Stream)
{
  OSuite::IParser::ZCharReaderBase *v2; // rbx
  int v3; // eax
  int element; // [rsp+20h] [rbp-18h]

  v2 = Stream;
  do
  {
    if ( v2->m_Stack.m_nFree )
      v3 = OSuite::TStack<int>::Pop(&v2->m_Stack);
    else
      v3 = ((__int64 (__fastcall *)(OSuite::IParser::ZCharReaderBase *))v2->vfptr[1].__vecDelDtor)(v2);
  }
  while ( v3 != -1 && (v3 == 10 || v3 == 13 || v3 == 9 || v3 == 32) );
  element = v3;
  OSuite::TStack<int>::Push(&v2->m_Stack, &element);
}

// File Line: 20
// RVA: 0xEE0AD0
_BOOL8 __fastcall OSuite::IParser::IsWhiteSpace(OSuite::IParser *this, __int64 ch)
{
  signed __int64 v2; // rcx
  _BOOL8 result; // rax

  result = 0;
  if ( (unsigned int)ch <= 0x20 )
  {
    v2 = 4294977024i64;
    if ( _bittest64(&v2, ch) )
      result = 1;
  }
  return result;
}

// File Line: 30
// RVA: 0xEE071C
void __fastcall OSuite::IParser::ZCharReaderBase::~ZCharReaderBase(OSuite::IParser::ZCharReaderBase *this)
{
  OSuite::IParser::ZCharReaderBase *v1; // rbx
  OSuite::ZTextDecoder *v2; // rcx
  OSuite::TList<int> *v3; // rcx

  v1 = this;
  v2 = this->m_pDecoder;
  if ( v2 )
    v2->vfptr->__vecDelDtor((OSuite::ZObject *)&v2->vfptr, 1u);
  v1->m_pDecoder = 0i64;
  v3 = v1->m_Stack.m_pList;
  v1->m_Stack.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TStack<int>::`vftable'{for `OSuite::ZObject'};
  v1->m_Stack.vfptr = (OSuite::IHashableVtbl *)&OSuite::TStack<int>::`vftable'{for `OSuite::IHashable'};
  if ( v3 )
    v3->vfptr->__vecDelDtor((OSuite::ZObject *)&v3->vfptr, 1u);
}

// File Line: 36
// RVA: 0xEE09BC
void __fastcall OSuite::IParser::ZCharReaderBase::DetermineEncoding(OSuite::IParser::ZCharReaderBase *this)
{
  char v1; // bl
  OSuite::IParser::ZCharReaderBase *v2; // rsi
  OSuite::ZTextDecoder *v3; // rax
  OSuite::ZTextDecoder *v4; // rdi
  OSuite::ZTextDecoder *v5; // rax
  OSuite::ZString sEncoding; // [rsp+20h] [rbp-28h]

  v1 = 0;
  v2 = this;
  v3 = (OSuite::ZTextDecoder *)OSuite::ZObject::operator new(0x30ui64);
  v4 = v3;
  if ( v3 )
  {
    v3->m_pFeeder = 0i64;
    v3->m_sEncoding.m_pString = 0i64;
    OSuite::ZString::ZString(&sEncoding, "UTF-8");
    v1 = 1;
    OSuite::ZTextDecoder::ZTextDecoder(v4, &sEncoding);
  }
  else
  {
    v5 = 0i64;
  }
  v2->m_pDecoder = v5;
  if ( v1 & 1 )
    OSuite::ZString::~ZString(&sEncoding);
}

// File Line: 146
// RVA: 0xEE0C60
__int64 __fastcall OSuite::IParser::ZCharReaderBase::Read(OSuite::IParser::ZCharReaderBase *this)
{
  __int64 result; // rax

  if ( this->m_Stack.m_nFree )
    result = OSuite::TStack<int>::Pop(&this->m_Stack);
  else
    result = ((__int64 (*)(void))this->vfptr[1].__vecDelDtor)();
  return result;
}

// File Line: 156
// RVA: 0xEE0C44
void __fastcall OSuite::IParser::ZCharReaderBase::Push(OSuite::IParser::ZCharReaderBase *this, int iData)
{
  int element; // [rsp+38h] [rbp+10h]

  element = iData;
  OSuite::TStack<int>::Push(&this->m_Stack, &element);
}

// File Line: 166
// RVA: 0xEE06CC
void __fastcall OSuite::IParser::ZStreamCharReader::ZStreamCharReader(OSuite::IParser::ZStreamCharReader *this, OSuite::IReader *pStream, OSuite::IParser *pParent)
{
  this->m_Stack.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TStack<int>::`vftable'{for `OSuite::ZObject'};
  this->m_Stack.vfptr = (OSuite::IHashableVtbl *)&OSuite::TStack<int>::`vftable'{for `OSuite::IHashable'};
  this->m_Stack.m_nFree = 0i64;
  this->m_Stack.m_pList = 0i64;
  this->m_pDecoder = 0i64;
  this->m_pParent = pParent;
  this->m_pStream = pStream;
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::IParser::ZStreamCharReader::`vftable';
  OSuite::IParser::ZCharReaderBase::DetermineEncoding((OSuite::IParser::ZCharReaderBase *)&this->vfptr);
}

// File Line: 171
// RVA: 0xEE0C88
__int64 __fastcall OSuite::IParser::ZStreamCharReader::ReadByte(OSuite::IParser::ZStreamCharReader *this)
{
  return ((__int64 (*)(void))this->m_pStream->vfptr->ReadByte)();
}

// File Line: 176
// RVA: 0xEE0CC4
__int64 __fastcall OSuite::IParser::ZStreamCharReader::SetPosition(OSuite::IParser::ZStreamCharReader *this, unsigned __int64 nPosition)
{
  return this->m_pStream->vfptr->SetPosition(this->m_pStream, nPosition);
}

// File Line: 186
// RVA: 0xEE0644
void __fastcall OSuite::IParser::ZHttpCharReader::ZHttpCharReader(OSuite::IParser::ZHttpCharReader *this, OSuite::IBufferedReader *pStream, OSuite::IParser *pParent)
{
  OSuite::IParser::ZHttpCharReader *v3; // rdi
  OSuite::ZString *v4; // rax
  bool v5; // bl
  OSuite::ZString v6; // [rsp+20h] [rbp-28h]

  this->m_Stack.m_nFree = 0i64;
  this->m_Stack.m_pList = 0i64;
  v3 = this;
  this->m_Stack.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TStack<int>::`vftable'{for `OSuite::ZObject'};
  this->m_Stack.vfptr = (OSuite::IHashableVtbl *)&OSuite::TStack<int>::`vftable'{for `OSuite::IHashable'};
  this->m_pDecoder = 0i64;
  this->m_pStream = pStream;
  this->m_pParent = pParent;
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::IParser::ZHttpCharReader::`vftable';
  v4 = (OSuite::ZString *)(*((__int64 (__fastcall **)(OSuite::IBufferedReader *, OSuite::ZString *))&pStream->vfptr[1].__vecDelDtor
                           + 1))(
                            pStream,
                            &v6);
  v5 = OSuite::ZString::operator bool(v4) == 0;
  OSuite::ZString::~ZString(&v6);
  if ( v5 )
    OSuite::IParser::ZCharReaderBase::DetermineEncoding((OSuite::IParser::ZCharReaderBase *)&v3->vfptr);
}

// File Line: 194
// RVA: 0xEE0C78
__int64 __fastcall OSuite::IParser::ZHttpCharReader::ReadByte(OSuite::IParser::ZHttpCharReader *this)
{
  return ((__int64 (*)(void))this->m_pStream->vfptr[1].Flush)();
}

