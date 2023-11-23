// File Line: 19
// RVA: 0xEDDAFC
void __fastcall OSuite::ZOEdmEndRole::ZOEdmEndRole(
        OSuite::ZOEdmEndRole *this,
        OSuite::ZString *schemaName,
        OSuite::ZString *name,
        OSuite::ZString *entityTypeName,
        OSuite::ZOEdmEndRole::ZMultiplicity eMultiplicity)
{
  OSuite::ZString *v7; // rax

  OSuite::ZOEdmBase::ZOEdmBase(this, schemaName, name);
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZOEdmEndRole::`vftable;
  this->m_Multiplicity = eMultiplicity;
  v7 = (OSuite::ZString *)OSuite::ZObject::operator new(0x18ui64);
  if ( v7 )
  {
    v7->m_pString = 0i64;
    OSuite::ZString::ZString(v7, entityTypeName);
  }
  this->m_EntityType = 0i64;
  this->m_EntityTypeName = v7;
}

// File Line: 45
// RVA: 0xEDDA88
void __fastcall OSuite::ZOEdmAssociation::ZOEdmAssociation(
        OSuite::ZOEdmAssociation *this,
        OSuite::ZString *schemaName,
        OSuite::ZString *name)
{
  OSuite::ZObject *v4; // rdx
  OSuite::ZOEdmEndRole **v5; // rax

  OSuite::ZOEdmBase::ZOEdmBase(this, schemaName, name);
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZOEdmAssociation::`vftable;
  OSuite::ZRedBlackTreeBase::ZElementBase::ZElementBase(&this->m_EndRoles, v4);
  this->m_EndRoles.m_pList = 0i64;
  this->m_EndRoles.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuitePrivate::ZPlayerConsumableData::ZRequest *>::`vftable{for `OSuite::ZListBase};
  this->m_EndRoles.vfptr = (OSuite::IHashableVtbl *)&OSuite::TList<OSuite::ZJsonObject *>::`vftable{for `OSuite::IHashable};
  v5 = (OSuite::ZOEdmEndRole **)OSuite::ZObject::malloc(&this->m_EndRoles, 0x80ui64, 0i64);
  this->m_EndRoles.m_nTop = 0i64;
  this->m_EndRoles.m_nSize = 16i64;
  this->m_EndRoles.m_pList = v5;
}

// File Line: 50
// RVA: 0xEDDB58
void __fastcall OSuite::ZOEdmAssociation::~ZOEdmAssociation(OSuite::ZOEdmAssociation *this)
{
  OSuite::TList<OSuite::ZOEdmEndRole *> *p_m_EndRoles; // rbx
  unsigned __int64 m_nIndex; // rsi
  OSuite::ZListBase *m_pListBase; // rdi
  unsigned __int64 v5; // rbp
  void (__fastcall ***v6)(_QWORD, __int64); // rcx
  OSuite::ZOEdmEndRole **m_pList; // rdx
  OSuite::ZListBase::ZListIteratorBase v8; // [rsp+20h] [rbp-38h] BYREF

  v8.m_pListBase = 0i64;
  p_m_EndRoles = &this->m_EndRoles;
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZOEdmAssociation::`vftable;
  OSuite::ZListBase::ZListIteratorBase::ZListIteratorBase(&v8, &this->m_EndRoles);
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
  m_pList = p_m_EndRoles->m_pList;
  p_m_EndRoles->OSuite::ZListBase::OSuite::ZObject::vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuitePrivate::ZPlayerConsumableData::ZRequest *>::`vftable{for `OSuite::ZListBase};
  p_m_EndRoles->OSuite::IHashable::vfptr = (OSuite::IHashableVtbl *)&OSuite::TList<OSuite::ZJsonObject *>::`vftable{for `OSuite::IHashable};
  OSuite::ZObject::free(p_m_EndRoles, m_pList);
  OSuite::ZOEdmBase::~ZOEdmBase(this);
}

// File Line: 60
// RVA: 0xEDDD80
void __fastcall OSuite::ZOEdmAssociation::ParseJsonValue(
        OSuite::ZOEdmAssociation *this,
        OSuite::ZString *name,
        OSuite::ZJsonValue *pJson)
{
  unsigned __int64 m_nIndex; // r14
  OSuite::ZListBase *m_pListBase; // rbx
  unsigned __int64 v7; // rsi
  OSuite::ZJsonObject *v8; // rbx
  OSuite::ZObjectVtbl *v9; // rsi
  OSuite::ZObjectVtbl *v10; // r14
  OSuite::ZObjectVtbl *v11; // rbx
  OSuite::ZOEdmEndRole::ZMultiplicity eMultiplicity; // ebx
  bool v13; // al
  OSuite::ZOEdmEndRole *v14; // rax
  OSuite::ZOEdmEndRole *v15; // rax
  OSuite::ZOEdmEndRole *v16; // rbx
  OSuite::ZListBase::ZListIteratorBase that; // [rsp+30h] [rbp-39h] BYREF
  OSuite::ZString sName; // [rsp+48h] [rbp-21h] BYREF
  OSuite::ZString v19; // [rsp+60h] [rbp-9h] BYREF
  void **v20; // [rsp+78h] [rbp+Fh]
  OSuite::ZListBase::ZListIteratorBase v21; // [rsp+80h] [rbp+17h] BYREF

  if ( OSuite::ZString::operator==(name, "Ends") )
  {
    v21.m_pListBase = 0i64;
    OSuite::ZListBase::ZListIteratorBase::ZListIteratorBase(&that, &pJson->m_array);
    that.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable;
    v20 = &OSuite::TConstIterator<OSuite::TList<OSuite::ZOEdmEndRole *>::ZIterator,OSuite::ZOEdmEndRole *,int>::`vftable;
    OSuite::ZListBase::ZListIteratorBase::ZListIteratorBase(&v21, &that);
    v21.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable;
    while ( !OSuite::ZListBase::ZListIteratorBase::AtEnd(&v21) )
    {
      OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)v21.m_pListBase);
      m_nIndex = v21.m_nIndex;
      m_pListBase = v21.m_pListBase;
      v7 = v21.m_nIndex + 1;
      OSuite::TList<OSuite::ZONavigationProperty *>::Grow(
        (OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *)v21.m_pListBase,
        v21.m_nIndex + 1);
      if ( m_nIndex >= m_pListBase->m_nTop )
        m_pListBase->m_nTop = v7;
      v8 = *(OSuite::ZJsonObject **)(*(_QWORD *)(m_pListBase[1].m_nSize + 8 * m_nIndex) + 80i64);
      OSuite::ZString::ZString((OSuite::ZString *)&that, "Role");
      v9 = OSuite::ZJsonObject::Value(v8, (OSuite::ZString *)&that);
      OSuite::ZString::~ZString((OSuite::ZString *)&that);
      OSuite::ZString::ZString(&sName, "Type");
      v10 = OSuite::ZJsonObject::Value(v8, &sName);
      OSuite::ZString::~ZString(&sName);
      OSuite::ZString::ZString(&v19, "Multiplicity");
      v11 = OSuite::ZJsonObject::Value(v8, &v19);
      OSuite::ZString::~ZString(&v19);
      if ( OSuite::ZString::operator==((OSuite::ZString *)&v11[2], "1") )
      {
        eMultiplicity = ONE;
      }
      else
      {
        v13 = OSuite::ZString::operator==((OSuite::ZString *)&v11[2], pattern);
        eMultiplicity = ZERO;
        if ( v13 )
          eMultiplicity = 2;
      }
      v14 = (OSuite::ZOEdmEndRole *)OSuite::ZObject::operator new(0x50ui64);
      if ( v14 )
      {
        v14->m_Name.m_pString = 0i64;
        v14->m_Schema.m_pString = 0i64;
        v14->m_EntityTypeName = 0i64;
        v14->m_EntityType = 0i64;
        OSuite::ZOEdmEndRole::ZOEdmEndRole(
          v14,
          &this->m_Schema,
          (OSuite::ZString *)&v9[2],
          (OSuite::ZString *)&v10[2],
          eMultiplicity);
        v16 = v15;
      }
      else
      {
        v16 = 0i64;
      }
      OSuite::TList<OSuite::ZONavigationProperty *>::Grow(
        (OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *)&this->m_EndRoles,
        this->m_EndRoles.m_nTop + 1);
      this->m_EndRoles.m_pList[this->m_EndRoles.m_nTop++] = v16;
      OSuite::ZListBase::ZListIteratorBase::Next(&v21);
    }
  }
}

// File Line: 88
// RVA: 0xEDDCC0
OSuite::ZOEdmEndRole *__fastcall OSuite::ZOEdmAssociation::EndRole(
        OSuite::ZOEdmAssociation *this,
        OSuite::ZString *roleName)
{
  unsigned __int64 m_nIndex; // rdi
  OSuite::ZListBase *m_pListBase; // rbx
  unsigned __int64 v5; // rsi
  __int64 v6; // rbx
  OSuite::ZListBase::ZListIteratorBase v8; // [rsp+20h] [rbp-38h] BYREF

  v8.m_pListBase = 0i64;
  OSuite::ZListBase::ZListIteratorBase::ZListIteratorBase(&v8, &this->m_EndRoles);
  v8.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable;
  while ( 1 )
  {
    if ( OSuite::ZListBase::ZListIteratorBase::AtEnd(&v8) )
      return 0i64;
    OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)v8.m_pListBase);
    m_nIndex = v8.m_nIndex;
    m_pListBase = v8.m_pListBase;
    v5 = v8.m_nIndex + 1;
    OSuite::TList<OSuite::ZONavigationProperty *>::Grow(
      (OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *)v8.m_pListBase,
      v8.m_nIndex + 1);
    if ( m_nIndex >= m_pListBase->m_nTop )
      m_pListBase->m_nTop = v5;
    v6 = *(_QWORD *)(m_pListBase[1].m_nSize + 8 * m_nIndex);
    if ( OSuite::ZString::operator==((OSuite::ZString *)(v6 + 8), roleName) )
      break;
    OSuite::ZListBase::ZListIteratorBase::Next(&v8);
  }
  return (OSuite::ZOEdmEndRole *)v6;
}

