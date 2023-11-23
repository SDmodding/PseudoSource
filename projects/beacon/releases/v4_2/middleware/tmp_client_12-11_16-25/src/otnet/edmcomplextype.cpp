// File Line: 11
// RVA: 0xED298C
void __fastcall OSuite::ZOEdmComplexType::ZOEdmComplexType(OSuite::ZOEdmComplexType *this, OSuite::ZString *schema)
{
  OSuite::ZObject *v3; // rdx
  OSuite::ZOEdmProperty **v4; // rax

  OSuite::ZOEdmBase::ZOEdmBase(this, schema);
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZOEdmComplexType::`vftable;
  OSuite::ZRedBlackTreeBase::ZElementBase::ZElementBase(&this->m_Properties, v3);
  this->m_Properties.m_pList = 0i64;
  this->m_Properties.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuitePrivate::ZPlayerConsumableData::ZRequest *>::`vftable{for `OSuite::ZListBase};
  this->m_Properties.vfptr = (OSuite::IHashableVtbl *)&OSuite::TList<OSuite::ZJsonObject *>::`vftable{for `OSuite::IHashable};
  v4 = (OSuite::ZOEdmProperty **)OSuite::ZObject::malloc(&this->m_Properties, 0x80ui64, 0i64);
  this->m_Properties.m_nTop = 0i64;
  this->m_Properties.m_nSize = 16i64;
  this->m_Properties.m_pList = v4;
}

// File Line: 16
// RVA: 0xED2A00
void __fastcall OSuite::ZOEdmComplexType::~ZOEdmComplexType(OSuite::ZOEdmComplexType *this)
{
  OSuite::TList<OSuite::ZOEdmProperty *> *p_m_Properties; // rbx
  unsigned __int64 m_nIndex; // rsi
  OSuite::ZListBase *m_pListBase; // rdi
  unsigned __int64 v5; // rbp
  void (__fastcall ***v6)(_QWORD, __int64); // rcx
  OSuite::ZOEdmProperty **m_pList; // rdx
  OSuite::ZOEdmProperty **v8; // rax
  OSuite::ZOEdmProperty **v9; // rdx
  OSuite::ZListBase::ZListIteratorBase v10; // [rsp+20h] [rbp-38h] BYREF

  v10.m_pListBase = 0i64;
  p_m_Properties = &this->m_Properties;
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZOEdmComplexType::`vftable;
  OSuite::ZListBase::ZListIteratorBase::ZListIteratorBase(&v10, &this->m_Properties);
  v10.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable;
  while ( !OSuite::ZListBase::ZListIteratorBase::AtEnd(&v10) )
  {
    OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)v10.m_pListBase);
    m_nIndex = v10.m_nIndex;
    m_pListBase = v10.m_pListBase;
    v5 = v10.m_nIndex + 1;
    OSuite::TList<OSuite::ZONavigationProperty *>::Grow(
      (OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *)v10.m_pListBase,
      v10.m_nIndex + 1);
    if ( m_nIndex >= m_pListBase->m_nTop )
      m_pListBase->m_nTop = v5;
    v6 = *(void (__fastcall ****)(_QWORD, __int64))(m_pListBase[1].m_nSize + 8 * m_nIndex);
    if ( v6 )
      (**v6)(v6, 1i64);
    OSuite::ZListBase::ZListIteratorBase::Next(&v10);
  }
  m_pList = p_m_Properties->m_pList;
  v10.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable;
  OSuite::ZObject::free(p_m_Properties, m_pList);
  v8 = (OSuite::ZOEdmProperty **)OSuite::ZObject::malloc(p_m_Properties, 0x80ui64, 0i64);
  p_m_Properties->m_nTop = 0i64;
  p_m_Properties->m_nSize = 16i64;
  p_m_Properties->m_pList = v8;
  v9 = p_m_Properties->m_pList;
  p_m_Properties->OSuite::ZListBase::OSuite::ZObject::vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuitePrivate::ZPlayerConsumableData::ZRequest *>::`vftable{for `OSuite::ZListBase};
  p_m_Properties->OSuite::IHashable::vfptr = (OSuite::IHashableVtbl *)&OSuite::TList<OSuite::ZJsonObject *>::`vftable{for `OSuite::IHashable};
  OSuite::ZObject::free(p_m_Properties, v9);
  OSuite::ZOEdmBase::~ZOEdmBase(this);
}

// File Line: 27
// RVA: 0xED2B64
void __fastcall OSuite::ZOEdmComplexType::ParseJsonValue(
        OSuite::ZOEdmComplexType *this,
        OSuite::ZString *name,
        OSuite::ZJsonValue *pJson)
{
  OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *p_m_Properties; // rdi
  unsigned __int64 m_nIndex; // r14
  OSuite::ZListBase *m_pListBase; // rbx
  unsigned __int64 v9; // rsi
  OSuite::ZJsonObject *v10; // rbx
  OSuite::ZObjectVtbl *v11; // r14
  OSuite::ZObjectVtbl *v12; // rsi
  OSuite::ZObjectVtbl *v13; // r15
  OSuite::EdmType v14; // r12d
  OSuite::ZOEdmProperty *v15; // rax
  OSuite::ZOEdmProperty *v16; // rbx
  bool nullable; // al
  OSuite::ZRedBlackTreeBase::ZElementBase *v18; // rax
  OSuite::ZRedBlackTreeBase::ZElementBase *v19; // rbx
  OSuite::ZListBase::ZListIteratorBase that; // [rsp+30h] [rbp-49h] BYREF
  OSuite::ZString sName; // [rsp+48h] [rbp-31h] BYREF
  OSuite::ZString v22; // [rsp+60h] [rbp-19h] BYREF
  void **v23; // [rsp+78h] [rbp-1h]
  OSuite::ZListBase::ZListIteratorBase v24; // [rsp+80h] [rbp+7h] BYREF

  if ( OSuite::ZString::operator==(name, "Name") )
  {
    OSuite::ZString::operator=(&this->m_Name, &pJson->m_literal);
  }
  else if ( OSuite::ZString::operator==(name, "Properties") )
  {
    v24.m_pListBase = 0i64;
    OSuite::ZListBase::ZListIteratorBase::ZListIteratorBase(&that, &pJson->m_array);
    that.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable;
    v23 = &OSuite::TConstIterator<OSuite::TList<OSuite::ZOEdmEndRole *>::ZIterator,OSuite::ZOEdmEndRole *,int>::`vftable;
    OSuite::ZListBase::ZListIteratorBase::ZListIteratorBase(&v24, &that);
    v24.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable;
    if ( !OSuite::ZListBase::ZListIteratorBase::AtEnd(&v24) )
    {
      p_m_Properties = (OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *)&this->m_Properties;
      do
      {
        OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)v24.m_pListBase);
        m_nIndex = v24.m_nIndex;
        m_pListBase = v24.m_pListBase;
        v9 = v24.m_nIndex + 1;
        OSuite::TList<OSuite::ZONavigationProperty *>::Grow(
          (OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *)v24.m_pListBase,
          v24.m_nIndex + 1);
        if ( m_nIndex >= m_pListBase->m_nTop )
          m_pListBase->m_nTop = v9;
        v10 = *(OSuite::ZJsonObject **)(*(_QWORD *)(m_pListBase[1].m_nSize + 8 * m_nIndex) + 80i64);
        OSuite::ZString::ZString((OSuite::ZString *)&that, "Name");
        v11 = OSuite::ZJsonObject::Value(v10, (OSuite::ZString *)&that);
        OSuite::ZString::~ZString((OSuite::ZString *)&that);
        OSuite::ZString::ZString(&sName, "Type");
        v12 = OSuite::ZJsonObject::Value(v10, &sName);
        OSuite::ZString::~ZString(&sName);
        OSuite::ZString::ZString(&v22, "Nullable");
        v13 = OSuite::ZJsonObject::Value(v10, &v22);
        OSuite::ZString::~ZString(&v22);
        v14 = (unsigned int)OSuite::stringToEdmType((OSuite::ZString *)&v12[2]);
        v15 = (OSuite::ZOEdmProperty *)OSuite::ZObject::operator new(0x50ui64);
        v16 = v15;
        if ( v15 )
        {
          v15->m_Name.m_pString = 0i64;
          v15->m_Schema.m_pString = 0i64;
          v15->m_ComplexType = 0i64;
          v15->m_ComplexTypeName = 0i64;
          nullable = OSuite::ZString::operator==((OSuite::ZString *)&v13[2], "true");
          OSuite::ZOEdmProperty::ZOEdmProperty(
            v16,
            (OSuite::ZString *)&v11[2],
            v14,
            (OSuite::ZString *)&v12[2],
            nullable);
          v19 = v18;
        }
        else
        {
          v19 = 0i64;
        }
        OSuite::TList<OSuite::ZONavigationProperty *>::Grow(p_m_Properties, p_m_Properties->m_nTop + 1);
        p_m_Properties->m_pList[p_m_Properties->m_nTop++] = v19;
        OSuite::ZListBase::ZListIteratorBase::Next(&v24);
      }
      while ( !OSuite::ZListBase::ZListIteratorBase::AtEnd(&v24) );
    }
  }
  else
  {
    OSuite::ZOEdmBase::CleanTempData((int)this);
  }
}nd(&v24) );
    }
  }
  else

// File Line: 56
// RVA: 0xED2D94
OSuite::ZOEdmProperty *__fastcall OSuite::ZOEdmComplexType::Property(
        OSuite::ZOEdmComplexType *this,
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
  OSuite::ZListBase::ZListIteratorBase::ZListIteratorBase(&that, &this->m_Properties);
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
  return (OSuite::ZOEdmProperty *)v6;
}

