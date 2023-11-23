// File Line: 11
// RVA: 0xED62B4
void __fastcall OSuite::ZOEdmEntityType::ZOEdmEntityType(OSuite::ZOEdmEntityType *this, OSuite::ZString *schema)
{
  OSuite::ZObject *v3; // rdx
  OSuite::ZString *v4; // rax
  OSuite::ZObject *v5; // rdx
  OSuite::ZOEdmProperty **v6; // rax
  OSuite::ZObject *v7; // rdx
  OSuite::ZOEdmNavigationProperty **v8; // rax

  OSuite::ZOEdmBase::ZOEdmBase(this, schema);
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZOEdmEntityType::`vftable;
  OSuite::ZRedBlackTreeBase::ZElementBase::ZElementBase(&this->m_Keys, v3);
  this->m_Keys.m_pList = 0i64;
  this->m_Keys.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZString>::`vftable{for `OSuite::ZListBase};
  this->m_Keys.vfptr = (OSuite::IHashableVtbl *)&OSuite::TList<OSuite::ZString>::`vftable{for `OSuite::IHashable};
  v4 = OSuite::TList<OSuite::ZString>::AllocList(&this->m_Keys, 0i64, 0x10ui64);
  this->m_Keys.m_nTop = 0i64;
  this->m_Keys.m_pList = v4;
  this->m_Keys.m_nSize = 16i64;
  OSuite::ZRedBlackTreeBase::ZElementBase::ZElementBase(&this->m_Properties, v5);
  this->m_Properties.m_pList = 0i64;
  this->m_Properties.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuitePrivate::ZPlayerConsumableData::ZRequest *>::`vftable{for `OSuite::ZListBase};
  this->m_Properties.vfptr = (OSuite::IHashableVtbl *)&OSuite::TList<OSuite::ZJsonObject *>::`vftable{for `OSuite::IHashable};
  v6 = (OSuite::ZOEdmProperty **)OSuite::ZObject::malloc(&this->m_Properties, 0x80ui64, 0i64);
  this->m_Properties.m_nTop = 0i64;
  this->m_Properties.m_nSize = 16i64;
  this->m_Properties.m_pList = v6;
  OSuite::ZRedBlackTreeBase::ZElementBase::ZElementBase(&this->m_NavigationProperties, v7);
  this->m_NavigationProperties.m_pList = 0i64;
  this->m_NavigationProperties.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuitePrivate::ZPlayerConsumableData::ZRequest *>::`vftable{for `OSuite::ZListBase};
  this->m_NavigationProperties.vfptr = (OSuite::IHashableVtbl *)&OSuite::TList<OSuite::ZJsonObject *>::`vftable{for `OSuite::IHashable};
  v8 = (OSuite::ZOEdmNavigationProperty **)OSuite::ZObject::malloc(&this->m_NavigationProperties, 0x80ui64, 0i64);
  this->m_NavigationProperties.m_nTop = 0i64;
  this->m_NavigationProperties.m_nSize = 16i64;
  this->m_NavigationProperties.m_pList = v8;
}

// File Line: 16
// RVA: 0xED63B4
void __fastcall OSuite::ZOEdmEntityType::~ZOEdmEntityType(OSuite::ZOEdmEntityType *this)
{
  OSuite::TList<OSuite::ZOEdmProperty *> *p_m_Properties; // rdi
  unsigned __int64 m_nIndex; // r14
  OSuite::ZListBase *m_pListBase; // rbx
  unsigned __int64 v5; // r15
  void (__fastcall ***v6)(_QWORD, __int64); // rcx
  OSuite::ZOEdmProperty **m_pList; // rdx
  OSuite::ZOEdmProperty **v8; // rax
  unsigned __int64 v9; // r14
  OSuite::ZListBase *v10; // rbx
  unsigned __int64 v11; // r12
  void (__fastcall ***v12)(_QWORD, __int64); // rcx
  OSuite::ZOEdmNavigationProperty **v13; // rdx
  OSuite::ZOEdmNavigationProperty **v14; // rax
  OSuite::ZOEdmNavigationProperty **v15; // rdx
  OSuite::ZOEdmProperty **v16; // rdx
  OSuite::ZString *v17; // rcx
  OSuite::ZListBase::ZListIteratorBase v18; // [rsp+20h] [rbp-40h] BYREF
  OSuite::ZListBase::ZListIteratorBase v19; // [rsp+38h] [rbp-28h] BYREF

  v18.m_pListBase = 0i64;
  p_m_Properties = &this->m_Properties;
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZOEdmEntityType::`vftable;
  OSuite::ZListBase::ZListIteratorBase::ZListIteratorBase(&v18, &this->m_Properties);
  v18.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable;
  while ( !OSuite::ZListBase::ZListIteratorBase::AtEnd(&v18) )
  {
    OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)v18.m_pListBase);
    m_nIndex = v18.m_nIndex;
    m_pListBase = v18.m_pListBase;
    v5 = v18.m_nIndex + 1;
    OSuite::TList<OSuite::ZONavigationProperty *>::Grow(
      (OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *)v18.m_pListBase,
      v18.m_nIndex + 1);
    if ( m_nIndex >= m_pListBase->m_nTop )
      m_pListBase->m_nTop = v5;
    v6 = *(void (__fastcall ****)(_QWORD, __int64))(m_pListBase[1].m_nSize + 8 * m_nIndex);
    if ( v6 )
      (**v6)(v6, 1i64);
    OSuite::ZListBase::ZListIteratorBase::Next(&v18);
  }
  m_pList = p_m_Properties->m_pList;
  v18.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable;
  OSuite::ZObject::free(p_m_Properties, m_pList);
  v8 = (OSuite::ZOEdmProperty **)OSuite::ZObject::malloc(p_m_Properties, 0x80ui64, 0i64);
  p_m_Properties->m_nTop = 0i64;
  v19.m_pListBase = 0i64;
  p_m_Properties->m_pList = v8;
  p_m_Properties->m_nSize = 16i64;
  OSuite::ZListBase::ZListIteratorBase::ZListIteratorBase(&v19, &this->m_NavigationProperties);
  v19.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable;
  while ( !OSuite::ZListBase::ZListIteratorBase::AtEnd(&v19) )
  {
    OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)v19.m_pListBase);
    v9 = v19.m_nIndex;
    v10 = v19.m_pListBase;
    v11 = v19.m_nIndex + 1;
    OSuite::TList<OSuite::ZONavigationProperty *>::Grow(
      (OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *)v19.m_pListBase,
      v19.m_nIndex + 1);
    if ( v9 >= v10->m_nTop )
      v10->m_nTop = v11;
    v12 = *(void (__fastcall ****)(_QWORD, __int64))(v10[1].m_nSize + 8 * v9);
    if ( v12 )
      (**v12)(v12, 1i64);
    OSuite::ZListBase::ZListIteratorBase::Next(&v19);
  }
  v13 = this->m_NavigationProperties.m_pList;
  v19.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable;
  OSuite::ZObject::free(&this->m_NavigationProperties, v13);
  v14 = (OSuite::ZOEdmNavigationProperty **)OSuite::ZObject::malloc(&this->m_NavigationProperties, 0x80ui64, 0i64);
  this->m_NavigationProperties.m_nTop = 0i64;
  this->m_NavigationProperties.m_nSize = 16i64;
  this->m_NavigationProperties.m_pList = v14;
  v15 = this->m_NavigationProperties.m_pList;
  this->m_NavigationProperties.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuitePrivate::ZPlayerConsumableData::ZRequest *>::`vftable{for `OSuite::ZListBase};
  this->m_NavigationProperties.vfptr = (OSuite::IHashableVtbl *)&OSuite::TList<OSuite::ZJsonObject *>::`vftable{for `OSuite::IHashable};
  OSuite::ZObject::free(&this->m_NavigationProperties, v15);
  v16 = p_m_Properties->m_pList;
  p_m_Properties->OSuite::ZListBase::OSuite::ZObject::vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuitePrivate::ZPlayerConsumableData::ZRequest *>::`vftable{for `OSuite::ZListBase};
  p_m_Properties->OSuite::IHashable::vfptr = (OSuite::IHashableVtbl *)&OSuite::TList<OSuite::ZJsonObject *>::`vftable{for `OSuite::IHashable};
  OSuite::ZObject::free(p_m_Properties, v16);
  v17 = this->m_Keys.m_pList;
  this->m_Keys.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZString>::`vftable{for `OSuite::ZListBase};
  this->m_Keys.vfptr = (OSuite::IHashableVtbl *)&OSuite::TList<OSuite::ZString>::`vftable{for `OSuite::IHashable};
  if ( v17 )
  {
    if ( LODWORD(v17[-1].m_pString) )
      v17->OSuite::ZObject::vfptr->__vecDelDtor(v17, 3u);
    else
      Illusion::ShaderParam::operator delete(&v17[-1].m_pString);
  }
  OSuite::ZOEdmBase::~ZOEdmBase(this);
}

// File Line: 34
// RVA: 0xED6704
void __fastcall OSuite::ZOEdmEntityType::ParseJsonValue(
        OSuite::ZOEdmEntityType *this,
        OSuite::ZString *name,
        OSuite::ZJsonValue *pJson)
{
  unsigned __int64 v6; // rsi
  OSuite::ZString::InternalString *m_pString; // rbx
  unsigned __int64 v8; // r14
  __int64 v9; // rbx
  unsigned __int64 v10; // r14
  OSuite::ZString::InternalString *v11; // rbx
  unsigned __int64 v12; // rsi
  OSuite::ZJsonObject *v13; // rbx
  OSuite::ZObjectVtbl *v14; // r14
  OSuite::ZObjectVtbl *v15; // rsi
  OSuite::ZObjectVtbl *v16; // r15
  OSuite::EdmType v17; // r12d
  OSuite::ZOEdmProperty *v18; // rbx
  bool nullable; // al
  OSuite::ZOEdmProperty *v20; // rax
  OSuite::ZOEdmProperty *v21; // rbx
  unsigned __int64 m_nIndex; // r15
  OSuite::ZListBase *m_pListBase; // rbx
  unsigned __int64 v24; // r14
  OSuite::ZJsonObject *v25; // rbx
  OSuite::ZObjectVtbl *v26; // r14
  OSuite::ZObjectVtbl *v27; // r15
  OSuite::ZObjectVtbl *v28; // r13
  OSuite::ZObjectVtbl *v29; // rbx
  OSuite::ZOEdmNavigationProperty *v30; // rax
  OSuite::ZOEdmNavigationProperty *v31; // rax
  OSuite::ZOEdmNavigationProperty *v32; // rbx
  OSuite::ZListBase::ZListIteratorBase that; // [rsp+30h] [rbp-69h] BYREF
  OSuite::ZString v34; // [rsp+48h] [rbp-51h] BYREF
  OSuite::ZString sName; // [rsp+60h] [rbp-39h] BYREF
  OSuite::ZString v36; // [rsp+78h] [rbp-21h] BYREF
  unsigned __int64 v37; // [rsp+90h] [rbp-9h]
  void **v38; // [rsp+98h] [rbp-1h]
  OSuite::ZListBase::ZListIteratorBase v39; // [rsp+A0h] [rbp+7h] BYREF

  if ( OSuite::ZString::operator==(name, "Name") )
  {
    OSuite::ZString::operator=(&this->m_Name, &pJson->m_literal);
  }
  else if ( OSuite::ZString::operator==(name, "Key") )
  {
    v36.m_pString = 0i64;
    OSuite::ZListBase::ZListIteratorBase::ZListIteratorBase(&that, &pJson->m_array);
    that.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable;
    v36.OSuite::ZObject::vfptr = (OSuite::ZObjectVtbl *)&OSuite::TConstIterator<OSuite::TList<OSuite::ZOEdmEndRole *>::ZIterator,OSuite::ZOEdmEndRole *,int>::`vftable;
    OSuite::ZListBase::ZListIteratorBase::ZListIteratorBase(
      (OSuite::ZListBase::ZListIteratorBase *)&v36.OSuite::IHashable,
      &that);
    v36.OSuite::IHashable::vfptr = (OSuite::IHashableVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable;
    while ( !OSuite::ZListBase::ZListIteratorBase::AtEnd((OSuite::ZListBase::ZListIteratorBase *)&v36.OSuite::IHashable) )
    {
      OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)v36.m_pString);
      v6 = v37;
      m_pString = v36.m_pString;
      v8 = v37 + 1;
      OSuite::TList<OSuite::ZONavigationProperty *>::Grow(
        (OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *)v36.m_pString,
        v37 + 1);
      if ( v6 >= *(_QWORD *)&m_pString->m_nHash )
        *(_QWORD *)&m_pString->m_nHash = v8;
      v9 = *(_QWORD *)(*(_QWORD *)&m_pString->m_szString[12] + 8 * v6);
      OSuite::TList<OSuite::ZString>::Grow(&this->m_Keys, this->m_Keys.m_nTop + 1);
      OSuite::ZString::operator=(&this->m_Keys.m_pList[this->m_Keys.m_nTop], (OSuite::ZString *)(v9 + 16));
      ++this->m_Keys.m_nTop;
      OSuite::ZListBase::ZListIteratorBase::Next((OSuite::ZListBase::ZListIteratorBase *)&v36.OSuite::IHashable);
    }
  }
  else if ( OSuite::ZString::operator==(name, "Properties") )
  {
    v36.m_pString = 0i64;
    OSuite::ZListBase::ZListIteratorBase::ZListIteratorBase(&that, &pJson->m_array);
    that.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable;
    v36.OSuite::ZObject::vfptr = (OSuite::ZObjectVtbl *)&OSuite::TConstIterator<OSuite::TList<OSuite::ZOEdmEndRole *>::ZIterator,OSuite::ZOEdmEndRole *,int>::`vftable;
    OSuite::ZListBase::ZListIteratorBase::ZListIteratorBase(
      (OSuite::ZListBase::ZListIteratorBase *)&v36.OSuite::IHashable,
      &that);
    v36.OSuite::IHashable::vfptr = (OSuite::IHashableVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable;
    while ( !OSuite::ZListBase::ZListIteratorBase::AtEnd((OSuite::ZListBase::ZListIteratorBase *)&v36.OSuite::IHashable) )
    {
      OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)v36.m_pString);
      v10 = v37;
      v11 = v36.m_pString;
      v12 = v37 + 1;
      OSuite::TList<OSuite::ZONavigationProperty *>::Grow(
        (OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *)v36.m_pString,
        v37 + 1);
      if ( v10 >= *(_QWORD *)&v11->m_nHash )
        *(_QWORD *)&v11->m_nHash = v12;
      v13 = *(OSuite::ZJsonObject **)(*(_QWORD *)(*(_QWORD *)&v11->m_szString[12] + 8 * v10) + 80i64);
      OSuite::ZString::ZString((OSuite::ZString *)&that, "Name");
      v14 = OSuite::ZJsonObject::Value(v13, (OSuite::ZString *)&that);
      OSuite::ZString::~ZString((OSuite::ZString *)&that);
      OSuite::ZString::ZString(&sName, "Type");
      v15 = OSuite::ZJsonObject::Value(v13, &sName);
      OSuite::ZString::~ZString(&sName);
      OSuite::ZString::ZString(&v34, "Nullable");
      v16 = OSuite::ZJsonObject::Value(v13, &v34);
      OSuite::ZString::~ZString(&v34);
      v17 = (unsigned int)OSuite::stringToEdmType((OSuite::ZString *)&v15[2]);
      v18 = (OSuite::ZOEdmProperty *)OSuite::ZObject::operator new(0x50ui64);
      if ( v18 )
      {
        v18->m_Name.m_pString = 0i64;
        v18->m_Schema.m_pString = 0i64;
        v18->m_ComplexType = 0i64;
        v18->m_ComplexTypeName = 0i64;
        nullable = OSuite::ZString::operator==((OSuite::ZString *)&v16[2], "true");
        OSuite::ZOEdmProperty::ZOEdmProperty(v18, (OSuite::ZString *)&v14[2], v17, (OSuite::ZString *)&v15[2], nullable);
        v21 = v20;
      }
      else
      {
        v21 = 0i64;
      }
      OSuite::TList<OSuite::ZONavigationProperty *>::Grow(
        (OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *)&this->m_Properties,
        this->m_Properties.m_nTop + 1);
      this->m_Properties.m_pList[this->m_Properties.m_nTop++] = v21;
      OSuite::ZListBase::ZListIteratorBase::Next((OSuite::ZListBase::ZListIteratorBase *)&v36.OSuite::IHashable);
    }
  }
  else if ( OSuite::ZString::operator==(name, "NavigationProperties") )
  {
    v39.m_pListBase = 0i64;
    OSuite::ZListBase::ZListIteratorBase::ZListIteratorBase(
      (OSuite::ZListBase::ZListIteratorBase *)&v34,
      &pJson->m_array);
    v34.OSuite::ZObject::vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable;
    v38 = &OSuite::TConstIterator<OSuite::TList<OSuite::ZOEdmEndRole *>::ZIterator,OSuite::ZOEdmEndRole *,int>::`vftable;
    OSuite::ZListBase::ZListIteratorBase::ZListIteratorBase(&v39, (OSuite::ZListBase::ZListIteratorBase *)&v34);
    v39.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable;
    while ( !OSuite::ZListBase::ZListIteratorBase::AtEnd(&v39) )
    {
      OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)v39.m_pListBase);
      m_nIndex = v39.m_nIndex;
      m_pListBase = v39.m_pListBase;
      v24 = v39.m_nIndex + 1;
      OSuite::TList<OSuite::ZONavigationProperty *>::Grow(
        (OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *)v39.m_pListBase,
        v39.m_nIndex + 1);
      if ( m_nIndex >= m_pListBase->m_nTop )
        m_pListBase->m_nTop = v24;
      v25 = *(OSuite::ZJsonObject **)(*(_QWORD *)(m_pListBase[1].m_nSize + 8 * m_nIndex) + 80i64);
      OSuite::ZString::ZString(&v34, "Name");
      v26 = OSuite::ZJsonObject::Value(v25, &v34);
      OSuite::ZString::~ZString(&v34);
      OSuite::ZString::ZString(&sName, "Relationship");
      v27 = OSuite::ZJsonObject::Value(v25, &sName);
      OSuite::ZString::~ZString(&sName);
      OSuite::ZString::ZString((OSuite::ZString *)&that, "FromRole");
      v28 = OSuite::ZJsonObject::Value(v25, (OSuite::ZString *)&that);
      OSuite::ZString::~ZString((OSuite::ZString *)&that);
      OSuite::ZString::ZString(&v36, "ToRole");
      v29 = OSuite::ZJsonObject::Value(v25, &v36);
      OSuite::ZString::~ZString(&v36);
      v30 = (OSuite::ZOEdmNavigationProperty *)OSuite::ZObject::operator new(0x68ui64);
      if ( v30 )
      {
        v30->m_Name.m_pString = 0i64;
        v30->m_Schema.m_pString = 0i64;
        v30->m_Association = 0i64;
        v30->m_FromRole = 0i64;
        v30->m_ToRole = 0i64;
        v30->m_AssociationName = 0i64;
        v30->m_FromRoleName = 0i64;
        v30->m_ToRoleName = 0i64;
        OSuite::ZOEdmNavigationProperty::ZOEdmNavigationProperty(
          v30,
          &this->m_Schema,
          (OSuite::ZString *)&v26[2],
          (OSuite::ZString *)&v27[2],
          (OSuite::ZString *)&v28[2],
          (OSuite::ZString *)&v29[2]);
        v32 = v31;
      }
      else
      {
        v32 = 0i64;
      }
      OSuite::TList<OSuite::ZONavigationProperty *>::Grow(
        (OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *)&this->m_NavigationProperties,
        this->m_NavigationProperties.m_nTop + 1);
      this->m_NavigationProperties.m_pList[this->m_NavigationProperties.m_nTop++] = v32;
      OSuite::ZListBase::ZListIteratorBase::Next(&v39);
    }
  }
  else
  {
    OSuite::ZOEdmBase::CleanTempData((int)this);
  }
}

// File Line: 87
// RVA: 0xED6BDC
OSuite::ZOEdmProperty *__fastcall OSuite::ZOEdmEntityType::Property(
        OSuite::ZOEdmEntityType *this,
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

// File Line: 102
// RVA: 0xED6620
OSuite::ZOEdmNavigationProperty *__fastcall OSuite::ZOEdmEntityType::NavigationProperty(
        OSuite::ZOEdmEntityType *this,
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
  OSuite::ZListBase::ZListIteratorBase::ZListIteratorBase(&that, &this->m_NavigationProperties);
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
  return (OSuite::ZOEdmNavigationProperty *)v6;
}

