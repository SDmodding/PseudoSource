// File Line: 19
// RVA: 0xEDDAFC
void __fastcall OSuite::ZOEdmEndRole::ZOEdmEndRole(OSuite::ZOEdmEndRole *this, OSuite::ZString *schemaName, OSuite::ZString *name, OSuite::ZString *entityTypeName, OSuite::ZOEdmEndRole::ZMultiplicity eMultiplicity)
{
  OSuite::ZString *v5; // rdi
  OSuite::ZOEdmEndRole *v6; // rbx
  OSuite::ZString *v7; // rax

  v5 = entityTypeName;
  v6 = this;
  OSuite::ZOEdmBase::ZOEdmBase((OSuite::ZOEdmBase *)&this->vfptr, schemaName, name);
  v6->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZOEdmEndRole::`vftable;
  v6->m_Multiplicity = eMultiplicity;
  v7 = (OSuite::ZString *)OSuite::ZObject::operator new(0x18ui64);
  if ( v7 )
  {
    v7->m_pString = 0i64;
    OSuite::ZString::ZString(v7, v5);
  }
  v6->m_EntityType = 0i64;
  v6->m_EntityTypeName = v7;
}

// File Line: 45
// RVA: 0xEDDA88
void __fastcall OSuite::ZOEdmAssociation::ZOEdmAssociation(OSuite::ZOEdmAssociation *this, OSuite::ZString *schemaName, OSuite::ZString *name)
{
  OSuite::ZOEdmAssociation *v3; // rdi
  OSuite::ZObject *v4; // rdx
  OSuite::ZOEdmEndRole **v5; // rax

  v3 = this;
  OSuite::ZOEdmBase::ZOEdmBase((OSuite::ZOEdmBase *)&this->vfptr, schemaName, name);
  v3->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZOEdmAssociation::`vftable;
  OSuite::ZRedBlackTreeBase::ZElementBase::ZElementBase((OSuite::ZObject *)&v3->m_EndRoles.vfptr, v4);
  v3->m_EndRoles.m_pList = 0i64;
  v3->m_EndRoles.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuitePrivate::ZPlayerConsumableData::ZRequest *>::`vftable{for `OSuite::ZListBase};
  v3->m_EndRoles.vfptr = (OSuite::IHashableVtbl *)&OSuite::TList<OSuite::ZJsonObject *>::`vftable{for `OSuite::IHashable};
  v5 = (OSuite::ZOEdmEndRole **)OSuite::ZObject::malloc((OSuite::ZObject *)&v3->m_EndRoles.vfptr, 0x80ui64, 0i64);
  v3->m_EndRoles.m_nTop = 0i64;
  v3->m_EndRoles.m_nSize = 16i64;
  v3->m_EndRoles.m_pList = v5;
}

// File Line: 50
// RVA: 0xEDDB58
void __fastcall OSuite::ZOEdmAssociation::~ZOEdmAssociation(OSuite::ZOEdmAssociation *this)
{
  OSuite::ZObject *v1; // rbx
  OSuite::ZOEdmAssociation *v2; // r14
  unsigned __int64 v3; // rsi
  OSuite::ZListBase *v4; // rdi
  unsigned __int64 v5; // rbp
  void (__fastcall ***v6)(_QWORD, signed __int64); // rcx
  OSuite::ZObjectVtbl *v7; // rdx
  OSuite::ZListBase::ZListIteratorBase v8; // [rsp+20h] [rbp-38h]

  v8.m_pListBase = 0i64;
  v1 = (OSuite::ZObject *)&this->m_EndRoles.vfptr;
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZOEdmAssociation::`vftable;
  v2 = this;
  OSuite::ZListBase::ZListIteratorBase::ZListIteratorBase(&v8, (OSuite::ZListBase *)&this->m_EndRoles.vfptr);
  v8.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable;
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
  v7 = v1[4].vfptr;
  v1->vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuitePrivate::ZPlayerConsumableData::ZRequest *>::`vftable{for `OSuite::ZListBase};
  v1[3].vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonObject *>::`vftable{for `OSuite::IHashable};
  OSuite::ZObject::free(v1, v7);
  OSuite::ZOEdmBase::~ZOEdmBase((OSuite::ZOEdmBase *)&v2->vfptr);
}

// File Line: 60
// RVA: 0xEDDD80
void __fastcall OSuite::ZOEdmAssociation::ParseJsonValue(OSuite::ZOEdmAssociation *this, OSuite::ZString *name, OSuite::ZJsonValue *pJson)
{
  OSuite::ZOEdmAssociation *v3; // r15
  OSuite::ZJsonValue *v4; // rbx
  unsigned __int64 v5; // r14
  OSuite::ZListBase *v6; // rbx
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
  OSuite::ZListBase::ZListIteratorBase that; // [rsp+30h] [rbp-39h]
  OSuite::ZString sName; // [rsp+48h] [rbp-21h]
  OSuite::ZString v19; // [rsp+60h] [rbp-9h]
  void **v20; // [rsp+78h] [rbp+Fh]
  OSuite::ZListBase::ZListIteratorBase v21; // [rsp+80h] [rbp+17h]

  v3 = this;
  v4 = pJson;
  if ( OSuite::ZString::operator==(name, "Ends") )
  {
    v21.m_pListBase = 0i64;
    OSuite::ZListBase::ZListIteratorBase::ZListIteratorBase(&that, (OSuite::ZListBase *)&v4->m_array.vfptr);
    that.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable;
    v20 = &OSuite::TConstIterator<OSuite::TList<OSuite::ZOEdmEndRole *>::ZIterator,OSuite::ZOEdmEndRole *,int>::`vftable;
    OSuite::ZListBase::ZListIteratorBase::ZListIteratorBase(&v21, &that);
    v21.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable;
    while ( !OSuite::ZListBase::ZListIteratorBase::AtEnd(&v21) )
    {
      OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)v21.m_pListBase);
      v5 = v21.m_nIndex;
      v6 = v21.m_pListBase;
      v7 = v21.m_nIndex + 1;
      OSuite::TList<OSuite::ZONavigationProperty *>::Grow(
        (OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *)v21.m_pListBase,
        v21.m_nIndex + 1);
      if ( v5 >= v6->m_nTop )
        v6->m_nTop = v7;
      v8 = *(OSuite::ZJsonObject **)(*(_QWORD *)(v6[1].m_nSize + 8 * v5) + 80i64);
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
        eMultiplicity = 1;
      }
      else
      {
        v13 = OSuite::ZString::operator==((OSuite::ZString *)&v11[2], pattern);
        eMultiplicity = 0;
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
          &v3->m_Schema,
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
        (OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *)&v3->m_EndRoles,
        v3->m_EndRoles.m_nTop + 1);
      v3->m_EndRoles.m_pList[v3->m_EndRoles.m_nTop++] = v16;
      OSuite::ZListBase::ZListIteratorBase::Next(&v21);
    }
  }
}

// File Line: 88
// RVA: 0xEDDCC0
OSuite::ZOEdmEndRole *__fastcall OSuite::ZOEdmAssociation::EndRole(OSuite::ZOEdmAssociation *this, OSuite::ZString *roleName)
{
  OSuite::ZString *v2; // rbp
  unsigned __int64 v3; // rdi
  OSuite::ZListBase *v4; // rbx
  unsigned __int64 v5; // rsi
  __int64 v6; // rbx
  OSuite::ZListBase::ZListIteratorBase v8; // [rsp+20h] [rbp-38h]

  v8.m_pListBase = 0i64;
  v2 = roleName;
  OSuite::ZListBase::ZListIteratorBase::ZListIteratorBase(&v8, (OSuite::ZListBase *)&this->m_EndRoles.vfptr);
  v8.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable;
  while ( 1 )
  {
    if ( OSuite::ZListBase::ZListIteratorBase::AtEnd(&v8) )
      return 0i64;
    OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)v8.m_pListBase);
    v3 = v8.m_nIndex;
    v4 = v8.m_pListBase;
    v5 = v8.m_nIndex + 1;
    OSuite::TList<OSuite::ZONavigationProperty *>::Grow(
      (OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *)v8.m_pListBase,
      v8.m_nIndex + 1);
    if ( v3 >= v4->m_nTop )
      v4->m_nTop = v5;
    v6 = *(_QWORD *)(v4[1].m_nSize + 8 * v3);
    if ( OSuite::ZString::operator==((OSuite::ZString *)(v6 + 8), v2) )
      break;
    OSuite::ZListBase::ZListIteratorBase::Next(&v8);
  }
  return (OSuite::ZOEdmEndRole *)v6;
}

