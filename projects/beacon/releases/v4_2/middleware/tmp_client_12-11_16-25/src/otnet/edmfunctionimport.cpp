// File Line: 11
// RVA: 0xED77BC
OSuite::ZString *__fastcall OSuite::SFunctionParameter::ToString(
        OSuite::SFunctionParameter *this,
        OSuite::ZString *result,
        OSuite::ZString *paramValue)
{
  unsigned int m_Type; // eax
  int v7; // ecx
  const char *v8; // rax
  OSuite::ZStringBuilder v10; // [rsp+20h] [rbp-58h] BYREF

  v10.m_Chars.m_pList = 0i64;
  OSuite::ZStringBuilder::ZStringBuilder(&v10, 0x20ui64);
  OSuite::ZStringBuilder::Append(&v10, &this->m_Name);
  OSuite::ZStringBuilder::Append(&v10, "=");
  m_Type = this->m_Type;
  if ( m_Type <= 0xF && (v7 = 49458, _bittest(&v7, m_Type)) )
  {
    v8 = OSuite::ZString::c_str(paramValue);
    OSuite::ZStringBuilder::AppendFormat(&v10, "%s", v8);
  }
  else
  {
    OSuite::ZStringBuilder::Append(&v10, paramValue);
  }
  OSuite::ZStringBuilder::ToString(&v10, result);
  OSuite::ZUtf8Buffer::~ZUtf8Buffer(&v10);
  return result;
}

// File Line: 40
// RVA: 0xED7160
void __fastcall OSuite::ZOEdmFunctionImport::ZOEdmFunctionImport(OSuite::ZOEdmFunctionImport *this)
{
  OSuite::ZObject *v2; // rdx
  OSuite::SFunctionParameter **v3; // rax

  OSuite::ZOEdmBase::ZOEdmBase(this);
  this->m_EntityTypeName = 0i64;
  this->m_EntityType = 0i64;
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZOEdmFunctionImport::`vftable;
  this->m_ReturnType = SVOP_VOID;
  OSuite::ZString::ZString(&this->m_HttpMethod);
  OSuite::ZRedBlackTreeBase::ZElementBase::ZElementBase(&this->m_Parameters, v2);
  this->m_Parameters.m_pList = 0i64;
  this->m_Parameters.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuitePrivate::ZPlayerConsumableData::ZRequest *>::`vftable{for `OSuite::ZListBase};
  this->m_Parameters.vfptr = (OSuite::IHashableVtbl *)&OSuite::TList<OSuite::ZJsonObject *>::`vftable{for `OSuite::IHashable};
  v3 = (OSuite::SFunctionParameter **)OSuite::ZObject::malloc(&this->m_Parameters, 0x80ui64, 0i64);
  this->m_Parameters.m_nTop = 0i64;
  this->m_Parameters.m_nSize = 16i64;
  this->m_Parameters.m_pList = v3;
}

// File Line: 45
// RVA: 0xED71EC
void __fastcall OSuite::ZOEdmFunctionImport::~ZOEdmFunctionImport(OSuite::ZOEdmFunctionImport *this)
{
  OSuite::TList<OSuite::SFunctionParameter *> *p_m_Parameters; // rbx
  unsigned __int64 m_nIndex; // rbp
  OSuite::ZListBase *m_pListBase; // rsi
  unsigned __int64 v5; // r14
  void (__fastcall ***v6)(_QWORD, __int64); // rcx
  OSuite::SFunctionParameter **m_pList; // rdx
  OSuite::ZListBase::ZListIteratorBase v8; // [rsp+20h] [rbp-38h] BYREF

  v8.m_pListBase = 0i64;
  p_m_Parameters = &this->m_Parameters;
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZOEdmFunctionImport::`vftable;
  OSuite::ZListBase::ZListIteratorBase::ZListIteratorBase(&v8, &this->m_Parameters);
  v8.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable;
  while ( !OSuite::ZListBase::ZListIteratorBase::AtEnd(&v8) )
  {
    OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)v8.m_pListBase);
    m_nIndex = v8.m_nIndex;
    m_pListBase = v8.m_pListBase;
    v5 = v8.m_nIndex + 1;
    OSuite::TList<OSuite::ZONavigationProperty *>::Grow(
      (OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *)v8.m_pListBase,
      v8.m_nIndex + 1);
    if ( m_nIndex >= m_pListBase->m_nTop )
      m_pListBase->m_nTop = v5;
    v6 = *(void (__fastcall ****)(_QWORD, __int64))(m_pListBase[1].m_nSize + 8 * m_nIndex);
    if ( v6 )
      (**v6)(v6, 1i64);
    OSuite::ZListBase::ZListIteratorBase::Next(&v8);
  }
  this->m_EntityType = 0i64;
  m_pList = p_m_Parameters->m_pList;
  p_m_Parameters->OSuite::ZListBase::OSuite::ZObject::vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuitePrivate::ZPlayerConsumableData::ZRequest *>::`vftable{for `OSuite::ZListBase};
  p_m_Parameters->OSuite::IHashable::vfptr = (OSuite::IHashableVtbl *)&OSuite::TList<OSuite::ZJsonObject *>::`vftable{for `OSuite::IHashable};
  OSuite::ZObject::free(p_m_Parameters, m_pList);
  OSuite::ZString::~ZString(&this->m_HttpMethod);
  OSuite::ZOEdmBase::~ZOEdmBase(this);
}

// File Line: 58
// RVA: 0xED74D8
OSuite::SFunctionParameter *__fastcall OSuite::ZOEdmFunctionImport::Parameter(
        OSuite::ZOEdmFunctionImport *this,
        OSuite::ZString *sName)
{
  unsigned __int64 m_nIndex; // rdi
  OSuite::ZListBase *m_pListBase; // rbx
  unsigned __int64 v5; // rsi
  __int64 v6; // rbx
  OSuite::ZListBase::ZListIteratorBase that; // [rsp+20h] [rbp-40h] BYREF
  void **v9; // [rsp+38h] [rbp-28h]
  OSuite::ZListBase::ZListIteratorBase v10; // [rsp+40h] [rbp-20h] BYREF

  v10.m_pListBase = 0i64;
  OSuite::ZListBase::ZListIteratorBase::ZListIteratorBase(&that, &this->m_Parameters);
  that.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable;
  v9 = &OSuite::TConstIterator<OSuite::TList<OSuite::ZOEdmEndRole *>::ZIterator,OSuite::ZOEdmEndRole *,int>::`vftable;
  OSuite::ZListBase::ZListIteratorBase::ZListIteratorBase(&v10, &that);
  v10.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable;
  while ( 1 )
  {
    if ( OSuite::ZListBase::ZListIteratorBase::AtEnd(&v10) )
      return 0i64;
    OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)v10.m_pListBase);
    m_nIndex = v10.m_nIndex;
    m_pListBase = v10.m_pListBase;
    v5 = v10.m_nIndex + 1;
    OSuite::TList<OSuite::ZONavigationProperty *>::Grow(
      (OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *)v10.m_pListBase,
      v10.m_nIndex + 1);
    if ( m_nIndex >= m_pListBase->m_nTop )
      m_pListBase->m_nTop = v5;
    v6 = *(_QWORD *)(m_pListBase[1].m_nSize + 8 * m_nIndex);
    if ( OSuite::ZString::operator==((OSuite::ZString *)(v6 + 8), sName) )
      break;
    OSuite::ZListBase::ZListIteratorBase::Next(&v10);
  }
  return (OSuite::SFunctionParameter *)v6;
}

// File Line: 73
// RVA: 0xED75BC
void __fastcall OSuite::ZOEdmFunctionImport::ParseJsonValue(
        OSuite::ZOEdmFunctionImport *this,
        OSuite::ZString *name,
        OSuite::ZJsonValue *pJson)
{
  OSuite::ZString *p_m_Name; // rcx
  OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *p_m_Parameters; // r14
  unsigned __int64 m_nIndex; // rdi
  OSuite::ZListBase *m_pListBase; // rbx
  unsigned __int64 v10; // rsi
  OSuite::ZJsonObject *v11; // rdi
  char *v12; // rbx
  OSuite::ZObjectVtbl *v13; // rax
  OSuite::ZObjectVtbl *v14; // rax
  OSuite::ZListBase::ZListIteratorBase that; // [rsp+20h] [rbp-40h] BYREF
  void **v16; // [rsp+38h] [rbp-28h]
  OSuite::ZListBase::ZListIteratorBase v17; // [rsp+40h] [rbp-20h] BYREF

  if ( OSuite::ZString::operator==(name, "Name") )
  {
    p_m_Name = &this->m_Name;
LABEL_5:
    OSuite::ZString::operator=(p_m_Name, &pJson->m_literal);
    return;
  }
  if ( OSuite::ZString::operator==(name, "HttpMethod") )
  {
    p_m_Name = &this->m_HttpMethod;
    goto LABEL_5;
  }
  if ( OSuite::ZString::operator==(name, "ReturnType") )
  {
    this->vfptr[3].__vecDelDtor(this, (unsigned int)&pJson->m_literal);
  }
  else if ( OSuite::ZString::operator==(name, "Parameters") )
  {
    v17.m_pListBase = 0i64;
    OSuite::ZListBase::ZListIteratorBase::ZListIteratorBase(&that, &pJson->m_array);
    that.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable;
    v16 = &OSuite::TConstIterator<OSuite::TList<OSuite::ZOEdmEndRole *>::ZIterator,OSuite::ZOEdmEndRole *,int>::`vftable;
    OSuite::ZListBase::ZListIteratorBase::ZListIteratorBase(&v17, &that);
    v17.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable;
    if ( !OSuite::ZListBase::ZListIteratorBase::AtEnd(&v17) )
    {
      p_m_Parameters = (OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *)&this->m_Parameters;
      do
      {
        OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)v17.m_pListBase);
        m_nIndex = v17.m_nIndex;
        m_pListBase = v17.m_pListBase;
        v10 = v17.m_nIndex + 1;
        OSuite::TList<OSuite::ZONavigationProperty *>::Grow(
          (OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *)v17.m_pListBase,
          v17.m_nIndex + 1);
        if ( m_nIndex >= m_pListBase->m_nTop )
          m_pListBase->m_nTop = v10;
        v11 = *(OSuite::ZJsonObject **)(*(_QWORD *)(m_pListBase[1].m_nSize + 8 * m_nIndex) + 80i64);
        v12 = (char *)OSuite::ZObject::operator new(0x28ui64);
        if ( v12 )
        {
          *(_QWORD *)v12 = &OSuite::SFunctionParameter::`vftable;
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
        OSuite::TList<OSuite::ZONavigationProperty *>::Grow(p_m_Parameters, p_m_Parameters->m_nTop + 1);
        p_m_Parameters->m_pList[p_m_Parameters->m_nTop++] = (OSuite::ZRedBlackTreeBase::ZElementBase *)v12;
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
  OSuite::ZString *m_EntityTypeName; // rcx

  m_EntityTypeName = this->m_EntityTypeName;
  if ( m_EntityTypeName )
  {
    m_EntityTypeName->OSuite::ZObject::vfptr->__vecDelDtor(m_EntityTypeName, 1u);
    this->m_EntityTypeName = 0i64;
  }
}

// File Line: 113
// RVA: 0xED7380
void __fastcall OSuite::ZOEdmFunctionImport::DeduceReturnTypeInfo(
        OSuite::ZOEdmFunctionImport *this,
        OSuite::ZString *returnTypeString)
{
  OSuite::ZString *v4; // rbx
  bool v5; // bp
  int v6; // ebp
  int v7; // r14d
  OSuite::ZString *v8; // rax
  OSuite::ZString *v9; // rax
  OSuite::ZString *v10; // rax
  OSuite::ZString InternalString; // [rsp+20h] [rbp-28h] BYREF

  OSuite::ZString::ZString(&InternalString, "Edm.");
  v4 = 0i64;
  v5 = OSuite::ZString::IndexOf(returnTypeString, &InternalString, 0i64) < 0;
  OSuite::ZString::~ZString(&InternalString);
  if ( OSuite::ZString::StartsWith(returnTypeString, "Collection") )
  {
    if ( !v5 )
    {
      this->m_ReturnType = SVOP_VALUECOLLECTION;
      return;
    }
    this->m_ReturnType = SVOP_FEED;
    OSuite::ZString::ZString(&InternalString, "Collection(");
    v6 = OSuite::ZString::IndexOf(returnTypeString, &InternalString, 0i64) + 11;
    OSuite::ZString::~ZString(&InternalString);
    OSuite::ZString::ZString(&InternalString, ")");
    v7 = OSuite::ZString::IndexOf(returnTypeString, &InternalString, 0i64) - v6;
    OSuite::ZString::~ZString(&InternalString);
    v8 = (OSuite::ZString *)OSuite::ZObject::operator new(0x18ui64);
    if ( !v8 )
      goto LABEL_10;
    v8->m_pString = 0i64;
    v9 = OSuite::ZString::Slice(returnTypeString, v8, v6, v7);
    goto LABEL_9;
  }
  if ( v5 )
  {
    this->m_ReturnType = SVOP_ENTRY;
    v10 = (OSuite::ZString *)OSuite::ZObject::operator new(0x18ui64);
    if ( !v10 )
    {
LABEL_10:
      this->m_EntityTypeName = v4;
      return;
    }
    v10->m_pString = 0i64;
    OSuite::ZString::ZString(v10, returnTypeString);
LABEL_9:
    v4 = v9;
    goto LABEL_10;
  }
  this->m_ReturnType = SVOP_VALUE;
}

