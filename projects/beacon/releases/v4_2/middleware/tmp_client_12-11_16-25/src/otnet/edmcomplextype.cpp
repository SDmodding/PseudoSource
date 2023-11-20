// File Line: 11
// RVA: 0xED298C
void __fastcall OSuite::ZOEdmComplexType::ZOEdmComplexType(OSuite::ZOEdmComplexType *this, OSuite::ZString *schema)
{
  OSuite::ZOEdmComplexType *v2; // rdi
  OSuite::ZObject *v3; // rdx
  OSuite::ZOEdmProperty **v4; // rax

  v2 = this;
  OSuite::ZOEdmBase::ZOEdmBase((OSuite::ZOEdmBase *)&this->vfptr, schema);
  v2->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZOEdmComplexType::`vftable;
  OSuite::ZRedBlackTreeBase::ZElementBase::ZElementBase((OSuite::ZObject *)&v2->m_Properties.vfptr, v3);
  v2->m_Properties.m_pList = 0i64;
  v2->m_Properties.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuitePrivate::ZPlayerConsumableData::ZRequest *>::`vftable{for `OSuite::ZListBase};
  v2->m_Properties.vfptr = (OSuite::IHashableVtbl *)&OSuite::TList<OSuite::ZJsonObject *>::`vftable{for `OSuite::IHashable};
  v4 = (OSuite::ZOEdmProperty **)OSuite::ZObject::malloc((OSuite::ZObject *)&v2->m_Properties.vfptr, 0x80ui64, 0i64);
  v2->m_Properties.m_nTop = 0i64;
  v2->m_Properties.m_nSize = 16i64;
  v2->m_Properties.m_pList = v4;
}

// File Line: 16
// RVA: 0xED2A00
void __fastcall OSuite::ZOEdmComplexType::~ZOEdmComplexType(OSuite::ZOEdmComplexType *this)
{
  OSuite::ZObject *v1; // rbx
  OSuite::ZOEdmComplexType *v2; // r14
  unsigned __int64 v3; // rsi
  OSuite::ZListBase *v4; // rdi
  unsigned __int64 v5; // rbp
  void (__fastcall ***v6)(_QWORD, signed __int64); // rcx
  OSuite::ZObjectVtbl *v7; // rdx
  OSuite::ZObjectVtbl *v8; // rax
  OSuite::ZObjectVtbl *v9; // rdx
  OSuite::ZListBase::ZListIteratorBase v10; // [rsp+20h] [rbp-38h]

  v10.m_pListBase = 0i64;
  v1 = (OSuite::ZObject *)&this->m_Properties.vfptr;
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZOEdmComplexType::`vftable;
  v2 = this;
  OSuite::ZListBase::ZListIteratorBase::ZListIteratorBase(&v10, (OSuite::ZListBase *)&this->m_Properties.vfptr);
  v10.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable;
  while ( !OSuite::ZListBase::ZListIteratorBase::AtEnd(&v10) )
  {
    OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)v10.m_pListBase);
    v3 = v10.m_nIndex;
    v4 = v10.m_pListBase;
    v5 = v10.m_nIndex + 1;
    OSuite::TList<OSuite::ZONavigationProperty *>::Grow(
      (OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *)v10.m_pListBase,
      v10.m_nIndex + 1);
    if ( v3 >= v4->m_nTop )
      v4->m_nTop = v5;
    v6 = *(void (__fastcall ****)(_QWORD, signed __int64))(v4[1].m_nSize + 8 * v3);
    if ( v6 )
      (**v6)(v6, 1i64);
    OSuite::ZListBase::ZListIteratorBase::Next(&v10);
  }
  v7 = v1[4].vfptr;
  v10.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable;
  OSuite::ZObject::free(v1, v7);
  v8 = (OSuite::ZObjectVtbl *)OSuite::ZObject::malloc(v1, 0x80ui64, 0i64);
  v1[2].vfptr = 0i64;
  v1[1].vfptr = (OSuite::ZObjectVtbl *)16;
  v1[4].vfptr = v8;
  v9 = v1[4].vfptr;
  v1->vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuitePrivate::ZPlayerConsumableData::ZRequest *>::`vftable{for `OSuite::ZListBase};
  v1[3].vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonObject *>::`vftable{for `OSuite::IHashable};
  OSuite::ZObject::free(v1, v9);
  OSuite::ZOEdmBase::~ZOEdmBase((OSuite::ZOEdmBase *)&v2->vfptr);
}

// File Line: 27
// RVA: 0xED2B64
void __fastcall OSuite::ZOEdmComplexType::ParseJsonValue(OSuite::ZOEdmComplexType *this, OSuite::ZString *name, OSuite::ZJsonValue *pJson)
{
  OSuite::ZString *v3; // rsi
  OSuite::ZOEdmComplexType *v4; // rbx
  OSuite::ZJsonValue *v5; // rdi
  OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *v6; // rdi
  unsigned __int64 v7; // r14
  OSuite::ZListBase *v8; // rbx
  unsigned __int64 v9; // rsi
  OSuite::ZJsonObject *v10; // rbx
  OSuite::ZObjectVtbl *v11; // r14
  OSuite::ZObjectVtbl *v12; // rsi
  OSuite::ZObjectVtbl *v13; // r15
  OSuite::EdmType v14; // er12
  OSuite::ZOEdmProperty *v15; // rax
  OSuite::ZOEdmProperty *v16; // rbx
  bool nullable; // al
  OSuite::ZRedBlackTreeBase::ZElementBase *v18; // rax
  OSuite::ZRedBlackTreeBase::ZElementBase *v19; // rbx
  OSuite::ZListBase::ZListIteratorBase that; // [rsp+30h] [rbp-49h]
  OSuite::ZString sName; // [rsp+48h] [rbp-31h]
  OSuite::ZString v22; // [rsp+60h] [rbp-19h]
  void **v23; // [rsp+78h] [rbp-1h]
  OSuite::ZListBase::ZListIteratorBase v24; // [rsp+80h] [rbp+7h]

  v3 = name;
  v4 = this;
  v5 = pJson;
  if ( OSuite::ZString::operator==(name, "Name") )
  {
    OSuite::ZString::operator=(&v4->m_Name, &v5->m_literal);
  }
  else if ( OSuite::ZString::operator==(v3, "Properties") )
  {
    v24.m_pListBase = 0i64;
    OSuite::ZListBase::ZListIteratorBase::ZListIteratorBase(&that, (OSuite::ZListBase *)&v5->m_array.vfptr);
    that.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable;
    v23 = &OSuite::TConstIterator<OSuite::TList<OSuite::ZOEdmEndRole *>::ZIterator,OSuite::ZOEdmEndRole *,int>::`vftable;
    OSuite::ZListBase::ZListIteratorBase::ZListIteratorBase(&v24, &that);
    v24.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable;
    if ( !OSuite::ZListBase::ZListIteratorBase::AtEnd(&v24) )
    {
      v6 = (OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *)&v4->m_Properties;
      do
      {
        OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)v24.m_pListBase);
        v7 = v24.m_nIndex;
        v8 = v24.m_pListBase;
        v9 = v24.m_nIndex + 1;
        OSuite::TList<OSuite::ZONavigationProperty *>::Grow(
          (OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *)v24.m_pListBase,
          v24.m_nIndex + 1);
        if ( v7 >= v8->m_nTop )
          v8->m_nTop = v9;
        v10 = *(OSuite::ZJsonObject **)(*(_QWORD *)(v8[1].m_nSize + 8 * v7) + 80i64);
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
        OSuite::TList<OSuite::ZONavigationProperty *>::Grow(v6, v6->m_nTop + 1);
        v6->m_pList[v6->m_nTop++] = v19;
        OSuite::ZListBase::ZListIteratorBase::Next(&v24);
      }
      while ( !OSuite::ZListBase::ZListIteratorBase::AtEnd(&v24) );
    }
  }
  else
  {
    OSuite::ZOEdmBase::CleanTempData((int)v4);
  }
}::AtEnd(&v24) );
    }
  }
  else
  {
    OSuite::ZOEdmBase::C

// File Line: 56
// RVA: 0xED2D94
OSuite::ZOEdmProperty *__fastcall OSuite::ZOEdmComplexType::Property(OSuite::ZOEdmComplexType *this, OSuite::ZString *sName)
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
  OSuite::ZListBase::ZListIteratorBase::ZListIteratorBase(&that, (OSuite::ZListBase *)&this->m_Properties.vfptr);
  that.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable;
  v9 = &OSuite::TConstIterator<OSuite::TList<OSuite::ZOEdmEndRole *>::ZIterator,OSuite::ZOEdmEndRole *,int>::`vftable;
  OSuite::ZListBase::ZListIteratorBase::ZListIteratorBase(&v10, &that);
  v10.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable;
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
  return (OSuite::ZOEdmProperty *)v6;
}

