// File Line: 11
// RVA: 0xED77BC
OSuite::ZString *__fastcall OSuite::SFunctionParameter::ToString(OSuite::SFunctionParameter *this, OSuite::ZString *result, OSuite::ZString *paramValue)
{
  OSuite::SFunctionParameter *v3; // rbx
  OSuite::ZString *v4; // rdi
  OSuite::ZString *v5; // rsi
  unsigned int v6; // eax
  signed int v7; // ecx
  const char *v8; // rax
  OSuite::ZStringBuilder v10; // [rsp+20h] [rbp-58h]

  v10.m_Chars.m_pList = 0i64;
  v3 = this;
  v4 = result;
  v5 = paramValue;
  OSuite::ZStringBuilder::ZStringBuilder(&v10, 0x20ui64);
  OSuite::ZStringBuilder::Append(&v10, &v3->m_Name);
  OSuite::ZStringBuilder::Append(&v10, "=");
  v6 = v3->m_Type;
  if ( v6 <= 0xF && (v7 = 49458, _bittest(&v7, v6)) )
  {
    v8 = OSuite::ZString::c_str(v5);
    OSuite::ZStringBuilder::AppendFormat(&v10, "'%s'", v8);
  }
  else
  {
    OSuite::ZStringBuilder::Append(&v10, v5);
  }
  OSuite::ZStringBuilder::ToString(&v10, v4);
  OSuite::ZUtf8Buffer::~ZUtf8Buffer(&v10);
  return v4;
}

// File Line: 40
// RVA: 0xED7160
void __fastcall OSuite::ZOEdmFunctionImport::ZOEdmFunctionImport(OSuite::ZOEdmFunctionImport *this)
{
  OSuite::ZOEdmFunctionImport *v1; // rdi
  OSuite::ZObject *v2; // rdx
  OSuite::SFunctionParameter **v3; // rax

  v1 = this;
  OSuite::ZOEdmBase::ZOEdmBase((OSuite::ZOEdmBase *)&this->vfptr);
  v1->m_EntityTypeName = 0i64;
  v1->m_EntityType = 0i64;
  v1->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZOEdmFunctionImport::`vftable';
  v1->m_ReturnType = 4;
  OSuite::ZString::ZString(&v1->m_HttpMethod);
  OSuite::ZRedBlackTreeBase::ZElementBase::ZElementBase((OSuite::ZObject *)&v1->m_Parameters.vfptr, v2);
  v1->m_Parameters.m_pList = 0i64;
  v1->m_Parameters.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuitePrivate::ZPlayerConsumableData::ZRequest *>::`vftable'{for `OSuite::ZListBase'};
  v1->m_Parameters.vfptr = (OSuite::IHashableVtbl *)&OSuite::TList<OSuite::ZJsonObject *>::`vftable'{for `OSuite::IHashable'};
  v3 = (OSuite::SFunctionParameter **)OSuite::ZObject::malloc(
                                        (OSuite::ZObject *)&v1->m_Parameters.vfptr,
                                        0x80ui64,
                                        0i64);
  v1->m_Parameters.m_nTop = 0i64;
  v1->m_Parameters.m_nSize = 16i64;
  v1->m_Parameters.m_pList = v3;
}

// File Line: 45
// RVA: 0xED71EC
void __fastcall OSuite::ZOEdmFunctionImport::~ZOEdmFunctionImport(OSuite::ZOEdmFunctionImport *this)
{
  OSuite::ZObject *v1; // rbx
  OSuite::ZOEdmFunctionImport *v2; // rdi
  unsigned __int64 v3; // rbp
  OSuite::ZListBase *v4; // rsi
  unsigned __int64 v5; // r14
  void (__fastcall ***v6)(_QWORD, signed __int64); // rcx
  OSuite::ZObjectVtbl *v7; // rdx
  OSuite::ZListBase::ZListIteratorBase v8; // [rsp+20h] [rbp-38h]

  v8.m_pListBase = 0i64;
  v1 = (OSuite::ZObject *)&this->m_Parameters.vfptr;
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZOEdmFunctionImport::`vftable';
  v2 = this;
  OSuite::ZListBase::ZListIteratorBase::ZListIteratorBase(&v8, (OSuite::ZListBase *)&this->m_Parameters.vfptr);
  v8.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable';
  while ( !OSuite::ZListBase::ZListIteratorBase::AtEnd(&v8) )
  {
    OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)v8.m_pListBase);
    v3 = v8.m_nIndex;
    v4 = v8.m_pListBase;
    v5 = v8.m_nIndex + 1;
    OSuite::TList<OSuite::ZONavigationProperty *>::Grow(
      (OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *)v8.m_pListBase,
      v8.m_nIndex + 1);
    if ( v3 >= v4->m_nTop )
      v4->m_nTop = v5;
    v6 = *(void (__fastcall ****)(_QWORD, signed __int64))(v4[1].m_nSize + 8 * v3);
    if ( v6 )
      (**v6)(v6, 1i64);
    OSuite::ZListBase::ZListIteratorBase::Next(&v8);
  }
  v2->m_EntityType = 0i64;
  v7 = v1[4].vfptr;
  v1->vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuitePrivate::ZPlayerConsumableData::ZRequest *>::`vftable'{for `OSuite::ZListBase'};
  v1[3].vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonObject *>::`vftable'{for `OSuite::IHashable'};
  OSuite::ZObject::free(v1, v7);
  OSuite::ZString::~ZString(&v2->m_HttpMethod);
  OSuite::ZOEdmBase::~ZOEdmBase((OSuite::ZOEdmBase *)&v2->vfptr);
}

// File Line: 58
// RVA: 0xED74D8
OSuite::SFunctionParameter *__fastcall OSuite::ZOEdmFunctionImport::Parameter(OSuite::ZOEdmFunctionImport *this, OSuite::ZString *sName)
{
  OSuite::ZString *v2; // r14
  unsigned __int64 v3; // rdi
  OSuite::ZListBase *v4; // rbx
  unsigned __int64 v5; // rsi
  __int64 v6; // rbx
  OSuite::ZListBase::ZListIteratorBase that; // [rsp+20h] [rbp-40h]
  void **v9; // [rsp+38h] [rbp-28h]
  OSuite::ZListBase::ZListIteratorBase v10; // [rsp+40h] [rbp-20h]

  v10.m_pListBase = 0i64;
  v2 = sName;
  OSuite::ZListBase::ZListIteratorBase::ZListIteratorBase(&that, (OSuite::ZListBase *)&this->m_Parameters.vfptr);
  that.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable';
  v9 = &OSuite::TConstIterator<OSuite::TList<OSuite::ZOEdmEndRole *>::ZIterator,OSuite::ZOEdmEndRole *,int>::`vftable';
  OSuite::ZListBase::ZListIteratorBase::ZListIteratorBase(&v10, &that);
  v10.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable';
  while ( 1 )
  {
    if ( OSuite::ZListBase::ZListIteratorBase::AtEnd(&v10) )
      return 0i64;
    OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)v10.m_pListBase);
    v3 = v10.m_nIndex;
    v4 = v10.m_pListBase;
    v5 = v10.m_nIndex + 1;
    OSuite::TList<OSuite::ZONavigationProperty *>::Grow(
      (OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *)v10.m_pListBase,
      v10.m_nIndex + 1);
    if ( v3 >= v4->m_nTop )
      v4->m_nTop = v5;
    v6 = *(_QWORD *)(v4[1].m_nSize + 8 * v3);
    if ( OSuite::ZString::operator==((OSuite::ZString *)(v6 + 8), v2) )
      break;
    OSuite::ZListBase::ZListIteratorBase::Next(&v10);
  }
  return (OSuite::SFunctionParameter *)v6;
}

// File Line: 73
// RVA: 0xED75BC
void __fastcall OSuite::ZOEdmFunctionImport::ParseJsonValue(OSuite::ZOEdmFunctionImport *this, OSuite::ZString *name, OSuite::ZJsonValue *pJson)
{
  OSuite::ZString *v3; // rsi
  OSuite::ZOEdmFunctionImport *v4; // rbx
  OSuite::ZJsonValue *v5; // rdi
  OSuite::ZString *v6; // rcx
  OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *v7; // r14
  unsigned __int64 v8; // rdi
  OSuite::ZListBase *v9; // rbx
  unsigned __int64 v10; // rsi
  OSuite::ZJsonObject *v11; // rdi
  char *v12; // rbx
  OSuite::ZObjectVtbl *v13; // rax
  OSuite::ZObjectVtbl *v14; // rax
  OSuite::ZListBase::ZListIteratorBase that; // [rsp+20h] [rbp-40h]
  void **v16; // [rsp+38h] [rbp-28h]
  OSuite::ZListBase::ZListIteratorBase v17; // [rsp+40h] [rbp-20h]

  v3 = name;
  v4 = this;
  v5 = pJson;
  if ( OSuite::ZString::operator==(name, "Name") )
  {
    v6 = &v4->m_Name;
LABEL_5:
    OSuite::ZString::operator=(v6, &v5->m_literal);
    return;
  }
  if ( OSuite::ZString::operator==(v3, "HttpMethod") )
  {
    v6 = &v4->m_HttpMethod;
    goto LABEL_5;
  }
  if ( OSuite::ZString::operator==(v3, "ReturnType") )
  {
    v4->vfptr[3].__vecDelDtor((OSuite::ZObject *)&v4->vfptr, (unsigned int)&v5->m_literal);
  }
  else if ( OSuite::ZString::operator==(v3, "Parameters") )
  {
    v17.m_pListBase = 0i64;
    OSuite::ZListBase::ZListIteratorBase::ZListIteratorBase(&that, (OSuite::ZListBase *)&v5->m_array.vfptr);
    that.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable';
    v16 = &OSuite::TConstIterator<OSuite::TList<OSuite::ZOEdmEndRole *>::ZIterator,OSuite::ZOEdmEndRole *,int>::`vftable';
    OSuite::ZListBase::ZListIteratorBase::ZListIteratorBase(&v17, &that);
    v17.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable';
    if ( !OSuite::ZListBase::ZListIteratorBase::AtEnd(&v17) )
    {
      v7 = (OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *)&v4->m_Parameters;
      do
      {
        OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)v17.m_pListBase);
        v8 = v17.m_nIndex;
        v9 = v17.m_pListBase;
        v10 = v17.m_nIndex + 1;
        OSuite::TList<OSuite::ZONavigationProperty *>::Grow(
          (OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *)v17.m_pListBase,
          v17.m_nIndex + 1);
        if ( v8 >= v9->m_nTop )
          v9->m_nTop = v10;
        v11 = *(OSuite::ZJsonObject **)(*(_QWORD *)(v9[1].m_nSize + 8 * v8) + 80i64);
        v12 = (char *)OSuite::ZObject::operator new(0x28ui64);
        if ( v12 )
        {
          *(_QWORD *)v12 = &OSuite::SFunctionParameter::`vftable';
          OSuite::ZString::ZString((OSuite::ZString *)(v12 + 8));
        }
        else
        {
          v12 = 0i64;
        }
        OSuite::ZString::ZString((OSuite::ZString *)&that, "Name");
        v13 = OSuite::ZJsonObject::Value(v11, (OSuite::ZString *)&that);
        OSuite::ZString::operator=((OSuite::ZString *)(v12 + 8), (OSuite::ZString *)&v13[2]);
        OSuite::ZString::~ZString((OSuite::ZString *)&that);
        OSuite::ZString::ZString((OSuite::ZString *)&that, "Type");
        v14 = OSuite::ZJsonObject::Value(v11, (OSuite::ZString *)&that);
        *((_DWORD *)v12 + 8) = OSuite::stringToEdmType((OSuite::ZString *)&v14[2]);
        OSuite::ZString::~ZString((OSuite::ZString *)&that);
        OSuite::TList<OSuite::ZONavigationProperty *>::Grow(v7, v7->m_nTop + 1);
        v7->m_pList[v7->m_nTop++] = (OSuite::ZRedBlackTreeBase::ZElementBase *)v12;
        OSuite::ZListBase::ZListIteratorBase::Next(&v17);
      }
      while ( !OSuite::ZListBase::ZListIteratorBase::AtEnd(&v17) );
    }
  }
}

// File Line: 103
// RVA: 0xED7358
void __fastcall OSuite::ZOEdmFunctionImport::CleanTempData(OSuite::ZOEdmFunctionImport *this)
{
  OSuite::ZOEdmFunctionImport *v1; // rbx
  OSuite::ZString *v2; // rcx

  v1 = this;
  v2 = this->m_EntityTypeName;
  if ( v2 )
  {
    v2->vfptr->__vecDelDtor((OSuite::ZObject *)&v2->vfptr, 1u);
    v1->m_EntityTypeName = 0i64;
  }
}

// File Line: 113
// RVA: 0xED7380
void __fastcall OSuite::ZOEdmFunctionImport::DeduceReturnTypeInfo(OSuite::ZOEdmFunctionImport *this, OSuite::ZString *returnTypeString)
{
  OSuite::ZString *v2; // rsi
  OSuite::ZOEdmFunctionImport *v3; // rdi
  OSuite::ZString *v4; // rbx
  bool v5; // bp
  int v6; // ebp
  int v7; // er14
  OSuite::ZString *v8; // rax
  OSuite::ZString *v9; // rax
  OSuite::ZString *v10; // rax
  OSuite::ZString InternalString; // [rsp+20h] [rbp-28h]

  v2 = returnTypeString;
  v3 = this;
  OSuite::ZString::ZString(&InternalString, "Edm.");
  v4 = 0i64;
  v5 = OSuite::ZString::IndexOf(v2, &InternalString, 0i64) < 0;
  OSuite::ZString::~ZString(&InternalString);
  if ( OSuite::ZString::StartsWith(v2, "Collection") )
  {
    if ( !v5 )
    {
      v3->m_ReturnType = 3;
      return;
    }
    v3->m_ReturnType = 0;
    OSuite::ZString::ZString(&InternalString, "Collection(");
    v6 = OSuite::ZString::IndexOf(v2, &InternalString, 0i64) + 11;
    OSuite::ZString::~ZString(&InternalString);
    OSuite::ZString::ZString(&InternalString, ")");
    v7 = OSuite::ZString::IndexOf(v2, &InternalString, 0i64) - v6;
    OSuite::ZString::~ZString(&InternalString);
    v8 = (OSuite::ZString *)OSuite::ZObject::operator new(0x18ui64);
    if ( !v8 )
      goto LABEL_10;
    v8->m_pString = 0i64;
    v9 = OSuite::ZString::Slice(v2, v8, v6, v7);
    goto LABEL_9;
  }
  if ( v5 )
  {
    v3->m_ReturnType = 1;
    v10 = (OSuite::ZString *)OSuite::ZObject::operator new(0x18ui64);
    if ( !v10 )
    {
LABEL_10:
      v3->m_EntityTypeName = v4;
      return;
    }
    v10->m_pString = 0i64;
    OSuite::ZString::ZString(v10, v2);
LABEL_9:
    v4 = v9;
    goto LABEL_10;
  }
  v3->m_ReturnType = 2;
}

