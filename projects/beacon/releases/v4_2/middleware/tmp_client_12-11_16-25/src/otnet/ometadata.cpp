// File Line: 20
// RVA: 0x15D8B10
__int64 dynamic_initializer_for__OSuite::ZOMetadata::s_nClassId__()
{
  __int64 result; // rax

  result = OSuite::ZAtomBase::GenerateClassId();
  OSuite::ZOMetadata::s_nClassId = result;
  return result;
}

// File Line: 35
// RVA: 0xED520C
char __fastcall OSuite::SplitSchemaQualifiedName(OSuite::ZString *fullyQualifiedName, OSuite::ZString *outSchema, OSuite::ZString *outName)
{
  OSuite::ZString *v3; // rbp
  OSuite::ZString *v4; // rbx
  OSuite::ZString *v5; // rsi
  unsigned __int64 v6; // rdi
  OSuite::ZString *v7; // rax
  OSuite::ZString *v8; // rax
  OSuite::ZString InternalString; // [rsp+20h] [rbp-28h]

  v3 = outSchema;
  v4 = fullyQualifiedName;
  v5 = outName;
  OSuite::ZString::ZString(&InternalString, ".");
  v6 = OSuite::ZString::IndexOf(v4, &InternalString, 0i64);
  OSuite::ZString::~ZString(&InternalString);
  if ( (signed int)v6 <= 0 )
    return 0;
  v7 = OSuite::ZString::Slice(v4, &InternalString, 0i64, v6);
  OSuite::ZString::operator=(v3, v7);
  OSuite::ZString::~ZString(&InternalString);
  v8 = OSuite::ZString::Slice(v4, &InternalString, (signed int)v6 + 1);
  OSuite::ZString::operator=(v5, v8);
  OSuite::ZString::~ZString(&InternalString);
  return 1;
}

// File Line: 53
// RVA: 0xED2EA4
void __fastcall OSuite::ZOMetadata::ZOMetadata(OSuite::ZOMetadata *this, OSuite::IReader *pReader, OSuite::ZUrl *feedUrl)
{
  OSuite::ZUrl *v3; // rdi
  OSuite::IReader *v4; // rsi
  OSuite::ZOMetadata *v5; // r14
  OSuite::ZObject *v6; // rdx
  OSuite::ZOEdmEntityType **v7; // rax
  OSuite::ZObject *v8; // rdx
  OSuite::ZOEdmComplexType **v9; // rax
  OSuite::ZObject *v10; // rdx
  OSuite::ZOEdmEntitySet **v11; // rax
  OSuite::ZObject *v12; // rdx
  OSuite::ZOEdmFunctionImport **v13; // rax
  OSuite::ZObject *v14; // rdx
  OSuite::ZOEdmAssociation **v15; // rax
  int v16; // eax
  OSuite::ZString *v17; // rax
  bool v18; // al
  OSuite::ZString InternalString; // [rsp+20h] [rbp-59h]
  OSuite::ZString v20; // [rsp+38h] [rbp-41h]
  OSuite::ZString result; // [rsp+50h] [rbp-29h]
  OSuite::ZJsonDocument v22; // [rsp+68h] [rbp-11h]

  v3 = feedUrl;
  v4 = pReader;
  v5 = this;
  OSuite::ZAtomBase::ZAtomBase((OSuite::ZAtomBase *)&this->vfptr);
  v5->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZOMetadata::`vftable;
  v5->m_ClientConfiguration = 0i64;
  OSuite::ZRedBlackTreeBase::ZElementBase::ZElementBase((OSuite::ZObject *)&v5->m_EntityTypes.vfptr, v6);
  v5->m_EntityTypes.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuitePrivate::ZPlayerConsumableData::ZRequest *>::`vftable{for `OSuite::ZListBase};
  v5->m_EntityTypes.vfptr = (OSuite::IHashableVtbl *)&OSuite::TList<OSuite::ZJsonObject *>::`vftable{for `OSuite::IHashable};
  v5->m_EntityTypes.m_pList = 0i64;
  v7 = (OSuite::ZOEdmEntityType **)OSuite::ZObject::malloc((OSuite::ZObject *)&v5->m_EntityTypes.vfptr, 0x80ui64, 0i64);
  v5->m_EntityTypes.m_nTop = 0i64;
  v5->m_EntityTypes.m_pList = v7;
  v5->m_EntityTypes.m_nSize = 16i64;
  OSuite::ZRedBlackTreeBase::ZElementBase::ZElementBase((OSuite::ZObject *)&v5->m_ComplexTypes.vfptr, v8);
  v5->m_ComplexTypes.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuitePrivate::ZPlayerConsumableData::ZRequest *>::`vftable{for `OSuite::ZListBase};
  v5->m_ComplexTypes.m_pList = 0i64;
  v5->m_ComplexTypes.vfptr = (OSuite::IHashableVtbl *)&OSuite::TList<OSuite::ZJsonObject *>::`vftable{for `OSuite::IHashable};
  v9 = (OSuite::ZOEdmComplexType **)OSuite::ZObject::malloc(
                                      (OSuite::ZObject *)&v5->m_ComplexTypes.vfptr,
                                      0x80ui64,
                                      0i64);
  v5->m_ComplexTypes.m_nSize = 16i64;
  v5->m_ComplexTypes.m_nTop = 0i64;
  v5->m_ComplexTypes.m_pList = v9;
  OSuite::ZRedBlackTreeBase::ZElementBase::ZElementBase((OSuite::ZObject *)&v5->m_EntitySets.vfptr, v10);
  v5->m_EntitySets.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuitePrivate::ZPlayerConsumableData::ZRequest *>::`vftable{for `OSuite::ZListBase};
  v5->m_EntitySets.m_pList = 0i64;
  v5->m_EntitySets.vfptr = (OSuite::IHashableVtbl *)&OSuite::TList<OSuite::ZJsonObject *>::`vftable{for `OSuite::IHashable};
  v11 = (OSuite::ZOEdmEntitySet **)OSuite::ZObject::malloc((OSuite::ZObject *)&v5->m_EntitySets.vfptr, 0x80ui64, 0i64);
  v5->m_EntitySets.m_nSize = 16i64;
  v5->m_EntitySets.m_nTop = 0i64;
  v5->m_EntitySets.m_pList = v11;
  OSuite::ZRedBlackTreeBase::ZElementBase::ZElementBase((OSuite::ZObject *)&v5->m_FunctionImports.vfptr, v12);
  v5->m_FunctionImports.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuitePrivate::ZPlayerConsumableData::ZRequest *>::`vftable{for `OSuite::ZListBase};
  v5->m_FunctionImports.m_pList = 0i64;
  v5->m_FunctionImports.vfptr = (OSuite::IHashableVtbl *)&OSuite::TList<OSuite::ZJsonObject *>::`vftable{for `OSuite::IHashable};
  v13 = (OSuite::ZOEdmFunctionImport **)OSuite::ZObject::malloc(
                                          (OSuite::ZObject *)&v5->m_FunctionImports.vfptr,
                                          0x80ui64,
                                          0i64);
  v5->m_FunctionImports.m_nSize = 16i64;
  v5->m_FunctionImports.m_nTop = 0i64;
  v5->m_FunctionImports.m_pList = v13;
  OSuite::ZRedBlackTreeBase::ZElementBase::ZElementBase((OSuite::ZObject *)&v5->m_Associations.vfptr, v14);
  v5->m_Associations.m_pList = 0i64;
  v5->m_Associations.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuitePrivate::ZPlayerConsumableData::ZRequest *>::`vftable{for `OSuite::ZListBase};
  v5->m_Associations.vfptr = (OSuite::IHashableVtbl *)&OSuite::TList<OSuite::ZJsonObject *>::`vftable{for `OSuite::IHashable};
  v15 = (OSuite::ZOEdmAssociation **)OSuite::ZObject::malloc(
                                       (OSuite::ZObject *)&v5->m_Associations.vfptr,
                                       0x80ui64,
                                       0i64);
  v5->m_Associations.m_nSize = 16i64;
  v5->m_Associations.m_nTop = 0i64;
  v5->m_Associations.m_pList = v15;
  result.m_pString = 0i64;
  OSuite::ZUrl::ToString(v3, &result, 0);
  OSuite::ZString::ZString(&InternalString, OSuite::ZWebServiceClient::METADATA_PATH);
  v16 = OSuite::ZString::IndexOf(&result, &InternalString, 0i64);
  v17 = OSuite::ZString::Slice(&result, &v20, 0i64, v16);
  OSuite::ZString::operator=(&v5->m_sBaseURL, v17);
  OSuite::ZString::~ZString(&v20);
  OSuite::ZString::~ZString(&InternalString);
  v22.m_Pairs.m_pLists = 0i64;
  OSuite::ZJsonDocument::ZJsonDocument(&v22, v4);
  v18 = v22.m_bIsValid;
  v5->m_bHasValidSource = v22.m_bIsValid;
  if ( v18 )
  {
    OSuite::ZAtomBase::ParseJson((OSuite::ZAtomBase *)&v5->vfptr, (OSuite::ZJsonObject *)&v22.vfptr);
    if ( v5->m_bHasValidSource )
      OSuite::ZOMetadata::ResolvePointers(v5);
  }
  OSuite::ZJsonDocument::~ZJsonDocument(&v22);
  OSuite::ZString::~ZString(&result);
}

// File Line: 71
// RVA: 0xED3120
void __fastcall OSuite::ZOMetadata::~ZOMetadata(OSuite::ZOMetadata *this)
{
  OSuite::ZOMetadata *v1; // rbx
  OSuite::ZOEdmClientConfiguration *v2; // rcx
  unsigned __int64 v3; // r14
  OSuite::ZListBase *v4; // rdi
  unsigned __int64 v5; // r15
  void (__fastcall ***v6)(_QWORD, signed __int64); // rcx
  OSuite::ZOEdmEntityType **v7; // rax
  unsigned __int64 v8; // r15
  OSuite::ZListBase *v9; // rdi
  unsigned __int64 v10; // r12
  void (__fastcall ***v11)(_QWORD, signed __int64); // rcx
  OSuite::ZOEdmComplexType **v12; // rdx
  OSuite::ZOEdmComplexType **v13; // rax
  unsigned __int64 v14; // r13
  OSuite::ZListBase *v15; // rdi
  unsigned __int64 v16; // r12
  void (__fastcall ***v17)(_QWORD, signed __int64); // rcx
  OSuite::ZOEdmEntitySet **v18; // rdx
  OSuite::ZOEdmEntitySet **v19; // rax
  unsigned __int64 v20; // r12
  OSuite::ZListBase *v21; // r13
  void (__fastcall ***v22)(_QWORD, signed __int64); // rcx
  OSuite::ZOEdmFunctionImport **v23; // rdx
  OSuite::ZOEdmFunctionImport **v24; // rax
  OSuite::ZObject *v25; // r12
  unsigned __int64 v26; // r12
  OSuite::ZListBase *v27; // r13
  void (__fastcall ***v28)(_QWORD, signed __int64); // rcx
  OSuite::ZObjectVtbl *v29; // rdx
  OSuite::ZObjectVtbl *v30; // rax
  OSuite::ZObjectVtbl *v31; // rdx
  OSuite::ZOEdmFunctionImport **v32; // rdx
  OSuite::ZOEdmEntitySet **v33; // rdx
  OSuite::ZOEdmComplexType **v34; // rdx
  OSuite::ZOEdmEntityType **v35; // rdx
  OSuite::ZListBase::ZListIteratorBase v36; // [rsp+0h] [rbp-49h]
  OSuite::ZListBase::ZListIteratorBase v37; // [rsp+18h] [rbp-31h]
  OSuite::ZListBase::ZListIteratorBase v38; // [rsp+30h] [rbp-19h]
  OSuite::ZListBase::ZListIteratorBase v39; // [rsp+48h] [rbp-1h]
  OSuite::ZListBase::ZListIteratorBase v40; // [rsp+60h] [rbp+17h]

  v1 = this;
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZOMetadata::`vftable;
  v2 = this->m_ClientConfiguration;
  if ( v2 )
  {
    v2->vfptr->__vecDelDtor((OSuite::ZObject *)&v2->vfptr, 1u);
    v1->m_ClientConfiguration = 0i64;
  }
  OSuite::ZListBase::ZListIteratorBase::ZListIteratorBase(&v37, (OSuite::ZListBase *)&v1->m_EntityTypes.vfptr);
  v37.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable;
  while ( !OSuite::ZListBase::ZListIteratorBase::AtEnd(&v37) )
  {
    OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)v37.m_pListBase);
    v3 = v37.m_nIndex;
    v4 = v37.m_pListBase;
    v5 = v37.m_nIndex + 1;
    OSuite::TList<OSuite::ZONavigationProperty *>::Grow(
      (OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *)v37.m_pListBase,
      v37.m_nIndex + 1);
    if ( v3 >= v4->m_nTop )
      v4->m_nTop = v5;
    v6 = *(void (__fastcall ****)(_QWORD, signed __int64))(v4[1].m_nSize + 8 * v3);
    if ( v6 )
      (**v6)(v6, 1i64);
    OSuite::ZListBase::ZListIteratorBase::Next(&v37);
  }
  OSuite::ZObject::free((OSuite::ZObject *)&v1->m_EntityTypes.vfptr, v1->m_EntityTypes.m_pList);
  v7 = (OSuite::ZOEdmEntityType **)OSuite::ZObject::malloc((OSuite::ZObject *)&v1->m_EntityTypes.vfptr, 0x80ui64, 0i64);
  v1->m_EntityTypes.m_nTop = 0i64;
  v1->m_EntityTypes.m_nSize = 16i64;
  v1->m_EntityTypes.m_pList = v7;
  v39.m_pListBase = 0i64;
  OSuite::ZListBase::ZListIteratorBase::ZListIteratorBase(&v39, (OSuite::ZListBase *)&v1->m_ComplexTypes.vfptr);
  v39.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable;
  while ( !OSuite::ZListBase::ZListIteratorBase::AtEnd(&v39) )
  {
    OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)v39.m_pListBase);
    v8 = v39.m_nIndex;
    v9 = v39.m_pListBase;
    v10 = v39.m_nIndex + 1;
    OSuite::TList<OSuite::ZONavigationProperty *>::Grow(
      (OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *)v39.m_pListBase,
      v39.m_nIndex + 1);
    if ( v8 >= v9->m_nTop )
      v9->m_nTop = v10;
    v11 = *(void (__fastcall ****)(_QWORD, signed __int64))(v9[1].m_nSize + 8 * v8);
    if ( v11 )
      (**v11)(v11, 1i64);
    OSuite::ZListBase::ZListIteratorBase::Next(&v39);
  }
  v12 = v1->m_ComplexTypes.m_pList;
  v39.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable;
  OSuite::ZObject::free((OSuite::ZObject *)&v1->m_ComplexTypes.vfptr, v12);
  v13 = (OSuite::ZOEdmComplexType **)OSuite::ZObject::malloc(
                                       (OSuite::ZObject *)&v1->m_ComplexTypes.vfptr,
                                       0x80ui64,
                                       0i64);
  v1->m_ComplexTypes.m_nTop = 0i64;
  v1->m_ComplexTypes.m_nSize = 16i64;
  v1->m_ComplexTypes.m_pList = v13;
  OSuite::ZListBase::ZListIteratorBase::ZListIteratorBase(&v36, (OSuite::ZListBase *)&v1->m_EntitySets.vfptr);
  v36.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable;
  while ( !OSuite::ZListBase::ZListIteratorBase::AtEnd(&v36) )
  {
    OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)v36.m_pListBase);
    v14 = v36.m_nIndex;
    v15 = v36.m_pListBase;
    v16 = v36.m_nIndex + 1;
    OSuite::TList<OSuite::ZONavigationProperty *>::Grow(
      (OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *)v36.m_pListBase,
      v36.m_nIndex + 1);
    if ( v14 >= v15->m_nTop )
      v15->m_nTop = v16;
    v17 = *(void (__fastcall ****)(_QWORD, signed __int64))(v15[1].m_nSize + 8 * v14);
    if ( v17 )
      (**v17)(v17, 1i64);
    OSuite::ZListBase::ZListIteratorBase::Next(&v36);
  }
  v18 = v1->m_EntitySets.m_pList;
  v36.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable;
  OSuite::ZObject::free((OSuite::ZObject *)&v1->m_EntitySets.vfptr, v18);
  v19 = (OSuite::ZOEdmEntitySet **)OSuite::ZObject::malloc((OSuite::ZObject *)&v1->m_EntitySets.vfptr, 0x80ui64, 0i64);
  v1->m_EntitySets.m_nTop = 0i64;
  v1->m_EntitySets.m_nSize = 16i64;
  v1->m_EntitySets.m_pList = v19;
  v38.m_pListBase = 0i64;
  OSuite::ZListBase::ZListIteratorBase::ZListIteratorBase(&v38, (OSuite::ZListBase *)&v1->m_FunctionImports.vfptr);
  v38.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable;
  while ( !OSuite::ZListBase::ZListIteratorBase::AtEnd(&v38) )
  {
    OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)v38.m_pListBase);
    v20 = v38.m_nIndex;
    v21 = v38.m_pListBase;
    OSuite::TList<OSuite::ZONavigationProperty *>::Grow(
      (OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *)v38.m_pListBase,
      v38.m_nIndex + 1);
    if ( v20 >= v21->m_nTop )
      v21->m_nTop = v20 + 1;
    v22 = *(void (__fastcall ****)(_QWORD, signed __int64))(v21[1].m_nSize + 8 * v20);
    if ( v22 )
      (**v22)(v22, 1i64);
    OSuite::ZListBase::ZListIteratorBase::Next(&v38);
  }
  v23 = v1->m_FunctionImports.m_pList;
  v38.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable;
  OSuite::ZObject::free((OSuite::ZObject *)&v1->m_FunctionImports.vfptr, v23);
  v24 = (OSuite::ZOEdmFunctionImport **)OSuite::ZObject::malloc(
                                          (OSuite::ZObject *)&v1->m_FunctionImports.vfptr,
                                          0x80ui64,
                                          0i64);
  v25 = (OSuite::ZObject *)&v1->m_Associations.vfptr;
  v1->m_FunctionImports.m_nTop = 0i64;
  v1->m_FunctionImports.m_nSize = 16i64;
  v1->m_FunctionImports.m_pList = v24;
  v40.m_pListBase = 0i64;
  OSuite::ZListBase::ZListIteratorBase::ZListIteratorBase(&v40, (OSuite::ZListBase *)&v1->m_Associations.vfptr);
  v40.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable;
  if ( !OSuite::ZListBase::ZListIteratorBase::AtEnd(&v40) )
  {
    do
    {
      OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)v40.m_pListBase);
      v26 = v40.m_nIndex;
      v27 = v40.m_pListBase;
      OSuite::TList<OSuite::ZONavigationProperty *>::Grow(
        (OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *)v40.m_pListBase,
        v40.m_nIndex + 1);
      if ( v26 >= v27->m_nTop )
        v27->m_nTop = v26 + 1;
      v28 = *(void (__fastcall ****)(_QWORD, signed __int64))(v27[1].m_nSize + 8 * v26);
      if ( v28 )
        (**v28)(v28, 1i64);
      OSuite::ZListBase::ZListIteratorBase::Next(&v40);
    }
    while ( !OSuite::ZListBase::ZListIteratorBase::AtEnd(&v40) );
    v25 = (OSuite::ZObject *)&v1->m_Associations.vfptr;
  }
  v29 = v25[4].vfptr;
  v40.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable;
  OSuite::ZObject::free(v25, v29);
  v30 = (OSuite::ZObjectVtbl *)OSuite::ZObject::malloc(v25, 0x80ui64, 0i64);
  v25[2].vfptr = 0i64;
  v25[1].vfptr = (OSuite::ZObjectVtbl *)16;
  v25[4].vfptr = v30;
  v31 = v25[4].vfptr;
  v25->vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuitePrivate::ZPlayerConsumableData::ZRequest *>::`vftable{for `OSuite::ZListBase};
  v25[3].vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonObject *>::`vftable{for `OSuite::IHashable};
  OSuite::ZObject::free(v25, v31);
  v32 = v1->m_FunctionImports.m_pList;
  v1->m_FunctionImports.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuitePrivate::ZPlayerConsumableData::ZRequest *>::`vftable{for `OSuite::ZListBase};
  v1->m_FunctionImports.vfptr = (OSuite::IHashableVtbl *)&OSuite::TList<OSuite::ZJsonObject *>::`vftable{for `OSuite::IHashable};
  OSuite::ZObject::free((OSuite::ZObject *)&v1->m_FunctionImports.vfptr, v32);
  v33 = v1->m_EntitySets.m_pList;
  v1->m_EntitySets.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuitePrivate::ZPlayerConsumableData::ZRequest *>::`vftable{for `OSuite::ZListBase};
  v1->m_EntitySets.vfptr = (OSuite::IHashableVtbl *)&OSuite::TList<OSuite::ZJsonObject *>::`vftable{for `OSuite::IHashable};
  OSuite::ZObject::free((OSuite::ZObject *)&v1->m_EntitySets.vfptr, v33);
  v34 = v1->m_ComplexTypes.m_pList;
  v1->m_ComplexTypes.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuitePrivate::ZPlayerConsumableData::ZRequest *>::`vftable{for `OSuite::ZListBase};
  v1->m_ComplexTypes.vfptr = (OSuite::IHashableVtbl *)&OSuite::TList<OSuite::ZJsonObject *>::`vftable{for `OSuite::IHashable};
  OSuite::ZObject::free((OSuite::ZObject *)&v1->m_ComplexTypes.vfptr, v34);
  v35 = v1->m_EntityTypes.m_pList;
  v1->m_EntityTypes.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuitePrivate::ZPlayerConsumableData::ZRequest *>::`vftable{for `OSuite::ZListBase};
  v1->m_EntityTypes.vfptr = (OSuite::IHashableVtbl *)&OSuite::TList<OSuite::ZJsonObject *>::`vftable{for `OSuite::IHashable};
  OSuite::ZObject::free((OSuite::ZObject *)&v1->m_EntityTypes.vfptr, v35);
  OSuite::ZAtomBase::~ZAtomBase((OSuite::ZAtomBase *)&v1->vfptr);
}

// File Line: 90
// RVA: 0xED42D0
void __fastcall OSuite::ZOMetadata::ParseJsonValue(OSuite::ZOMetadata *this, OSuite::ZString *name, OSuite::ZJsonValue *pJson)
{
  OSuite::ZString *v3; // rsi
  OSuite::ZOMetadata *v4; // r14
  OSuite::ZJsonValue *v5; // rdi
  OSuite::ZOEdmBase *v6; // rbx
  OSuite::ZJsonObject *v7; // rdx
  OSuite::ZError *v8; // rax
  unsigned __int64 v9; // rsi
  OSuite::ZListBase *v10; // rdi
  unsigned __int64 v11; // r15
  OSuite::ZJsonObject *v12; // rdi
  OSuite::ZObjectVtbl *v13; // rax
  OSuite::ZOEdmClientConfiguration *v14; // rax
  OSuite::ZOEdmBase *v15; // rax
  OSuite::ZListBase::ZListIteratorBase that; // [rsp+20h] [rbp-40h]
  void **v17; // [rsp+38h] [rbp-28h]
  OSuite::ZListBase::ZListIteratorBase v18; // [rsp+40h] [rbp-20h]

  v3 = name;
  v4 = this;
  v5 = pJson;
  v6 = 0i64;
  if ( OSuite::ZString::operator==(name, "d") )
  {
    v7 = v5->m_object;
    if ( v7 )
    {
      OSuite::ZAtomBase::ParseJson((OSuite::ZAtomBase *)&v4->vfptr, v7);
    }
    else
    {
      v8 = OSuite::TSingleton<OSuite::ZError>::Object();
      OSuite::ZError::SetThreadLastError(v8, ZERROR_PARSING_FAILED, 1);
    }
  }
  else if ( OSuite::ZString::operator==(v3, "Schemas") )
  {
    v18.m_pListBase = 0i64;
    OSuite::ZListBase::ZListIteratorBase::ZListIteratorBase(&that, (OSuite::ZListBase *)&v5->m_array.vfptr);
    that.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable;
    v17 = &OSuite::TConstIterator<OSuite::TList<OSuite::ZOEdmEndRole *>::ZIterator,OSuite::ZOEdmEndRole *,int>::`vftable;
    OSuite::ZListBase::ZListIteratorBase::ZListIteratorBase(&v18, &that);
    v18.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable;
    while ( !OSuite::ZListBase::ZListIteratorBase::AtEnd(&v18) )
    {
      OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)v18.m_pListBase);
      v9 = v18.m_nIndex;
      v10 = v18.m_pListBase;
      v11 = v18.m_nIndex + 1;
      OSuite::TList<OSuite::ZONavigationProperty *>::Grow(
        (OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *)v18.m_pListBase,
        v18.m_nIndex + 1);
      if ( v9 >= v10->m_nTop )
        v10->m_nTop = v11;
      v12 = *(OSuite::ZJsonObject **)(*(_QWORD *)(v10[1].m_nSize + 8 * v9) + 80i64);
      if ( v12 )
      {
        OSuite::ZString::ZString((OSuite::ZString *)&that, "Namespace");
        v13 = OSuite::ZJsonObject::Value(v12, (OSuite::ZString *)&that);
        OSuite::ZOMetadata::ParseSchema(v4, (OSuite::ZString *)&v13[2], v12);
        OSuite::ZString::~ZString((OSuite::ZString *)&that);
      }
      OSuite::ZListBase::ZListIteratorBase::Next(&v18);
    }
  }
  else if ( OSuite::ZString::operator==(v3, "ClientConfiguration") )
  {
    v14 = (OSuite::ZOEdmClientConfiguration *)OSuite::ZObject::operator new(0x60ui64);
    if ( v14 )
    {
      v14->m_Name.m_pString = 0i64;
      v14->m_Schema.m_pString = 0i64;
      OSuite::ZOEdmClientConfiguration::ZOEdmClientConfiguration(v14);
      v6 = v15;
    }
    v4->m_ClientConfiguration = (OSuite::ZOEdmClientConfiguration *)v6;
    OSuite::ZOEdmBase::ParseJson(v6, v5->m_object);
  }
}

// File Line: 122
// RVA: 0xED4484
void __fastcall OSuite::ZOMetadata::ParseSchema(OSuite::ZOMetadata *this, OSuite::ZString *schemaName, OSuite::ZJsonObject *pJson)
{
  OSuite::ZString *v3; // r15
  OSuite::ZOMetadata *v4; // r13
  int v5; // er12
  OSuite::ZString *v6; // rbx
  unsigned __int64 v7; // rdi
  unsigned __int64 v8; // rbx
  __int64 v9; // rsi
  OSuite::ZJsonObject *v10; // rbx
  OSuite::ZOEdmEntityType *v11; // rax
  OSuite::ZOEdmBase *v12; // rax
  OSuite::ZOEdmBase *v13; // rdi
  unsigned __int64 v14; // rdi
  unsigned __int64 v15; // rbx
  __int64 v16; // rsi
  OSuite::ZJsonObject *v17; // rbx
  OSuite::ZOEdmComplexType *v18; // rax
  OSuite::ZOEdmBase *v19; // rax
  OSuite::ZOEdmBase *v20; // rdi
  unsigned __int64 v21; // rsi
  unsigned __int64 v22; // rbx
  __int64 v23; // r14
  OSuite::ZJsonObject *v24; // rsi
  OSuite::ZOEdmAssociation *v25; // rax
  OSuite::ZOEdmAssociation *v26; // rbx
  OSuite::ZObjectVtbl *v27; // rax
  OSuite::ZOEdmBase *v28; // rax
  OSuite::ZOEdmBase *v29; // rbx
  unsigned __int64 v30; // rdi
  OSuite::ZListBase *v31; // rbx
  unsigned __int64 v32; // rsi
  OSuite::ZJsonObject *v33; // r15
  OSuite::ZObjectVtbl *v34; // rbx
  OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *v35; // rdi
  OSuite::ZString *v36; // r13
  unsigned __int64 v37; // r14
  OSuite::ZListBase *v38; // rbx
  unsigned __int64 v39; // rsi
  OSuite::ZJsonObject *v40; // rbx
  OSuite::ZObjectVtbl *v41; // rsi
  OSuite::ZObjectVtbl *v42; // rbx
  OSuite::ZOEdmEntitySet *v43; // rax
  OSuite::ZRedBlackTreeBase::ZElementBase *v44; // rax
  OSuite::ZRedBlackTreeBase::ZElementBase *v45; // rbx
  OSuite::ZObjectVtbl *v46; // rbx
  unsigned __int64 v47; // rsi
  OSuite::ZListBase *v48; // rdi
  unsigned __int64 v49; // r14
  OSuite::ZJsonObject *v50; // rsi
  OSuite::ZOEdmFunctionImport *v51; // rax
  OSuite::ZOEdmBase *v52; // rax
  OSuite::ZOEdmBase *v53; // rdi
  OSuite::ZListBase::ZListIteratorBase that; // [rsp+20h] [rbp-E0h]
  int v55; // [rsp+38h] [rbp-C8h]
  OSuite::ZString *schema; // [rsp+40h] [rbp-C0h]
  OSuite::ZOMetadata *v57; // [rsp+48h] [rbp-B8h]
  OSuite::ZListBase::ZListIteratorBase v58; // [rsp+50h] [rbp-B0h]
  unsigned __int64 v59; // [rsp+68h] [rbp-98h]
  void **v60; // [rsp+70h] [rbp-90h]
  OSuite::ZListBase::ZListIteratorBase v61; // [rsp+78h] [rbp-88h]
  void **v62; // [rsp+90h] [rbp-70h]
  OSuite::ZListBase::ZListIteratorBase v63; // [rsp+98h] [rbp-68h]
  OSuite::TMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *>::ZIterator result; // [rsp+B0h] [rbp-50h]

  v3 = schemaName;
  schema = schemaName;
  v4 = this;
  v57 = this;
  v5 = 0;
  v55 = 0;
  result.m_pMap = 0i64;
  result.m_iterator.m_iterator.m_pList = 0i64;
  result.m_iterator.m_iterator.m_pElement = 0i64;
  result.m_iterator.m_iterator.m_parents.m_pList = 0i64;
  OSuite::TMap<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>::Iterator(
    (OSuite::TMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *> *)&pJson->m_Pairs,
    &result);
  while ( !OSuite::ZString::IsNull((OSuite::ZString *)&result.m_iterator.m_iterator) )
  {
    v6 = (OSuite::ZString *)&result.m_iterator.m_iterator.m_pElement[1].m_pLeft;
    if ( OSuite::ZString::operator==(
           (OSuite::ZString *)&result.m_iterator.m_iterator.m_pElement[1].m_pLeft,
           "EntityTypes") )
    {
      v58.m_nIndex = 0i64;
      OSuite::ZListBase::ZListIteratorBase::ZListIteratorBase(
        &that,
        (OSuite::ZListBase *)&result.m_iterator.m_iterator.m_pElement[2].vfptr[5]);
      that.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable;
      v58.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TConstIterator<OSuite::TList<OSuite::ZOEdmEndRole *>::ZIterator,OSuite::ZOEdmEndRole *,int>::`vftable;
      OSuite::ZListBase::ZListIteratorBase::ZListIteratorBase(
        (OSuite::ZListBase::ZListIteratorBase *)((char *)&v58 + 8),
        &that);
      v58.m_pListBase = (OSuite::ZListBase *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable;
      while ( !OSuite::ZListBase::ZListIteratorBase::AtEnd((OSuite::ZListBase::ZListIteratorBase *)((char *)&v58 + 8)) )
      {
        OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)v58.m_nIndex);
        v7 = v59;
        v8 = v58.m_nIndex;
        v9 = v59 + 1;
        OSuite::TList<OSuite::ZONavigationProperty *>::Grow(
          (OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *)v58.m_nIndex,
          v59 + 1);
        if ( v7 >= *(_QWORD *)(v8 + 16) )
          *(_QWORD *)(v8 + 16) = v9;
        v10 = *(OSuite::ZJsonObject **)(*(_QWORD *)(*(_QWORD *)(v8 + 32) + 8 * v7) + 80i64);
        if ( v10 )
        {
          v11 = (OSuite::ZOEdmEntityType *)OSuite::ZObject::operator new(0xB0ui64);
          if ( v11 )
          {
            v11->m_Name.m_pString = 0i64;
            v11->m_Schema.m_pString = 0i64;
            v11->m_Keys.m_pList = 0i64;
            v11->m_Properties.m_pList = 0i64;
            v11->m_NavigationProperties.m_pList = 0i64;
            OSuite::ZOEdmEntityType::ZOEdmEntityType(v11, v3);
            v13 = v12;
          }
          else
          {
            v13 = 0i64;
          }
          OSuite::ZOEdmBase::ParseJson(v13, v10);
          OSuite::TList<OSuite::ZONavigationProperty *>::Grow(
            (OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *)&v4->m_EntityTypes,
            v4->m_EntityTypes.m_nTop + 1);
          v4->m_EntityTypes.m_pList[v4->m_EntityTypes.m_nTop++] = (OSuite::ZOEdmEntityType *)v13;
        }
        OSuite::ZListBase::ZListIteratorBase::Next((OSuite::ZListBase::ZListIteratorBase *)((char *)&v58 + 8));
      }
    }
    else if ( OSuite::ZString::operator==(v6, "ComplexTypes") )
    {
      v58.m_nIndex = 0i64;
      OSuite::ZListBase::ZListIteratorBase::ZListIteratorBase(
        &that,
        (OSuite::ZListBase *)&result.m_iterator.m_iterator.m_pElement[2].vfptr[5]);
      that.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable;
      v58.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TConstIterator<OSuite::TList<OSuite::ZOEdmEndRole *>::ZIterator,OSuite::ZOEdmEndRole *,int>::`vftable;
      OSuite::ZListBase::ZListIteratorBase::ZListIteratorBase(
        (OSuite::ZListBase::ZListIteratorBase *)((char *)&v58 + 8),
        &that);
      v58.m_pListBase = (OSuite::ZListBase *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable;
      while ( !OSuite::ZListBase::ZListIteratorBase::AtEnd((OSuite::ZListBase::ZListIteratorBase *)((char *)&v58 + 8)) )
      {
        OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)v58.m_nIndex);
        v14 = v59;
        v15 = v58.m_nIndex;
        v16 = v59 + 1;
        OSuite::TList<OSuite::ZONavigationProperty *>::Grow(
          (OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *)v58.m_nIndex,
          v59 + 1);
        if ( v14 >= *(_QWORD *)(v15 + 16) )
          *(_QWORD *)(v15 + 16) = v16;
        v17 = *(OSuite::ZJsonObject **)(*(_QWORD *)(*(_QWORD *)(v15 + 32) + 8 * v14) + 80i64);
        if ( v17 )
        {
          v18 = (OSuite::ZOEdmComplexType *)OSuite::ZObject::operator new(0x60ui64);
          if ( v18 )
          {
            v18->m_Name.m_pString = 0i64;
            v18->m_Schema.m_pString = 0i64;
            v18->m_Properties.m_pList = 0i64;
            OSuite::ZOEdmComplexType::ZOEdmComplexType(v18, v3);
            v20 = v19;
          }
          else
          {
            v20 = 0i64;
          }
          OSuite::ZOEdmBase::ParseJson(v20, v17);
          OSuite::TList<OSuite::ZONavigationProperty *>::Grow(
            (OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *)&v4->m_ComplexTypes,
            v4->m_ComplexTypes.m_nTop + 1);
          v4->m_ComplexTypes.m_pList[v4->m_ComplexTypes.m_nTop++] = (OSuite::ZOEdmComplexType *)v20;
        }
        OSuite::ZListBase::ZListIteratorBase::Next((OSuite::ZListBase::ZListIteratorBase *)((char *)&v58 + 8));
      }
    }
    else if ( OSuite::ZString::operator==(v6, "Associations") )
    {
      v58.m_nIndex = 0i64;
      OSuite::ZListBase::ZListIteratorBase::ZListIteratorBase(
        &that,
        (OSuite::ZListBase *)&result.m_iterator.m_iterator.m_pElement[2].vfptr[5]);
      that.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable;
      v58.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TConstIterator<OSuite::TList<OSuite::ZOEdmEndRole *>::ZIterator,OSuite::ZOEdmEndRole *,int>::`vftable;
      OSuite::ZListBase::ZListIteratorBase::ZListIteratorBase(
        (OSuite::ZListBase::ZListIteratorBase *)((char *)&v58 + 8),
        &that);
      v58.m_pListBase = (OSuite::ZListBase *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable;
      if ( !OSuite::ZListBase::ZListIteratorBase::AtEnd((OSuite::ZListBase::ZListIteratorBase *)((char *)&v58 + 8)) )
      {
        do
        {
          OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)v58.m_nIndex);
          v21 = v59;
          v22 = v58.m_nIndex;
          v23 = v59 + 1;
          OSuite::TList<OSuite::ZONavigationProperty *>::Grow(
            (OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *)v58.m_nIndex,
            v59 + 1);
          if ( v21 >= *(_QWORD *)(v22 + 16) )
            *(_QWORD *)(v22 + 16) = v23;
          v24 = *(OSuite::ZJsonObject **)(*(_QWORD *)(*(_QWORD *)(v22 + 32) + 8 * v21) + 80i64);
          v25 = (OSuite::ZOEdmAssociation *)OSuite::ZObject::operator new(0x60ui64);
          v26 = v25;
          if ( v25 )
          {
            v25->m_Name.m_pString = 0i64;
            v25->m_Schema.m_pString = 0i64;
            v25->m_EndRoles.m_pList = 0i64;
            OSuite::ZString::ZString((OSuite::ZString *)&that, "Name");
            v5 |= 1u;
            v27 = OSuite::ZJsonObject::Value(v24, (OSuite::ZString *)&that);
            OSuite::ZOEdmAssociation::ZOEdmAssociation(v26, v3, (OSuite::ZString *)&v27[2]);
            v29 = v28;
          }
          else
          {
            v29 = 0i64;
          }
          if ( v5 & 1 )
          {
            v5 &= 0xFFFFFFFE;
            OSuite::ZString::~ZString((OSuite::ZString *)&that);
          }
          OSuite::ZOEdmBase::ParseJson(v29, v24);
          OSuite::TList<OSuite::ZONavigationProperty *>::Grow(
            (OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *)&v4->m_Associations,
            v4->m_Associations.m_nTop + 1);
          v4->m_Associations.m_pList[v4->m_Associations.m_nTop++] = (OSuite::ZOEdmAssociation *)v29;
          OSuite::ZListBase::ZListIteratorBase::Next((OSuite::ZListBase::ZListIteratorBase *)((char *)&v58 + 8));
        }
        while ( !OSuite::ZListBase::ZListIteratorBase::AtEnd((OSuite::ZListBase::ZListIteratorBase *)((char *)&v58 + 8)) );
        v55 = v5;
      }
    }
    else if ( OSuite::ZString::operator==(v6, "EntityContainers") )
    {
      v63.m_pListBase = 0i64;
      OSuite::ZListBase::ZListIteratorBase::ZListIteratorBase(
        &that,
        (OSuite::ZListBase *)&result.m_iterator.m_iterator.m_pElement[2].vfptr[5]);
      that.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable;
      v62 = &OSuite::TConstIterator<OSuite::TList<OSuite::ZOEdmEndRole *>::ZIterator,OSuite::ZOEdmEndRole *,int>::`vftable;
      OSuite::ZListBase::ZListIteratorBase::ZListIteratorBase(&v63, &that);
      v63.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable;
      if ( !OSuite::ZListBase::ZListIteratorBase::AtEnd(&v63) )
      {
        do
        {
          OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)v63.m_pListBase);
          v30 = v63.m_nIndex;
          v31 = v63.m_pListBase;
          v32 = v63.m_nIndex + 1;
          OSuite::TList<OSuite::ZONavigationProperty *>::Grow(
            (OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *)v63.m_pListBase,
            v63.m_nIndex + 1);
          if ( v30 >= v31->m_nTop )
            v31->m_nTop = v32;
          v33 = *(OSuite::ZJsonObject **)(*(_QWORD *)(v31[1].m_nSize + 8 * v30) + 80i64);
          OSuite::ZString::ZString((OSuite::ZString *)&that, "EntitySets");
          v34 = OSuite::ZJsonObject::Value(v33, (OSuite::ZString *)&that);
          OSuite::ZString::~ZString((OSuite::ZString *)&that);
          if ( v34 )
          {
            v61.m_pListBase = 0i64;
            OSuite::ZListBase::ZListIteratorBase::ZListIteratorBase(&v58, (OSuite::ZListBase *)&v34[5]);
            v60 = &OSuite::TConstIterator<OSuite::TList<OSuite::ZOEdmEndRole *>::ZIterator,OSuite::ZOEdmEndRole *,int>::`vftable;
            v58.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable;
            OSuite::ZListBase::ZListIteratorBase::ZListIteratorBase(&v61, &v58);
            v61.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable;
            if ( !OSuite::ZListBase::ZListIteratorBase::AtEnd(&v61) )
            {
              v35 = (OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *)&v4->m_EntitySets;
              v36 = schema;
              do
              {
                OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)v61.m_pListBase);
                v37 = v61.m_nIndex;
                v38 = v61.m_pListBase;
                v39 = v61.m_nIndex + 1;
                OSuite::TList<OSuite::ZONavigationProperty *>::Grow(
                  (OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *)v61.m_pListBase,
                  v61.m_nIndex + 1);
                if ( v37 >= v38->m_nTop )
                  v38->m_nTop = v39;
                v40 = *(OSuite::ZJsonObject **)(*(_QWORD *)(v38[1].m_nSize + 8 * v37) + 80i64);
                OSuite::ZString::ZString((OSuite::ZString *)&v58, "Name");
                v41 = OSuite::ZJsonObject::Value(v40, (OSuite::ZString *)&v58);
                OSuite::ZString::~ZString((OSuite::ZString *)&v58);
                OSuite::ZString::ZString((OSuite::ZString *)&that, "EntityType");
                v42 = OSuite::ZJsonObject::Value(v40, (OSuite::ZString *)&that);
                OSuite::ZString::~ZString((OSuite::ZString *)&that);
                v43 = (OSuite::ZOEdmEntitySet *)OSuite::ZObject::operator new(0x48ui64);
                if ( v43 )
                {
                  v43->m_Name.m_pString = 0i64;
                  v43->m_Schema.m_pString = 0i64;
                  v43->m_EntityType = 0i64;
                  v43->m_EntityTypeName = 0i64;
                  OSuite::ZOEdmEntitySet::ZOEdmEntitySet(
                    v43,
                    v36,
                    (OSuite::ZString *)&v41[2],
                    (OSuite::ZString *)&v42[2]);
                  v45 = v44;
                }
                else
                {
                  v45 = 0i64;
                }
                OSuite::TList<OSuite::ZONavigationProperty *>::Grow(v35, v35->m_nTop + 1);
                v35->m_pList[v35->m_nTop++] = v45;
                OSuite::ZListBase::ZListIteratorBase::Next(&v61);
              }
              while ( !OSuite::ZListBase::ZListIteratorBase::AtEnd(&v61) );
              v4 = v57;
            }
          }
          OSuite::ZString::ZString((OSuite::ZString *)&v58, "FunctionImports");
          v46 = OSuite::ZJsonObject::Value(v33, (OSuite::ZString *)&v58);
          OSuite::ZString::~ZString((OSuite::ZString *)&v58);
          if ( v46 )
          {
            v61.m_pListBase = 0i64;
            OSuite::ZListBase::ZListIteratorBase::ZListIteratorBase(&that, (OSuite::ZListBase *)&v46[5]);
            that.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable;
            v60 = &OSuite::TConstIterator<OSuite::TList<OSuite::ZOEdmEndRole *>::ZIterator,OSuite::ZOEdmEndRole *,int>::`vftable;
            OSuite::ZListBase::ZListIteratorBase::ZListIteratorBase(&v61, &that);
            v61.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable;
            while ( !OSuite::ZListBase::ZListIteratorBase::AtEnd(&v61) )
            {
              OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)v61.m_pListBase);
              v47 = v61.m_nIndex;
              v48 = v61.m_pListBase;
              v49 = v61.m_nIndex + 1;
              OSuite::TList<OSuite::ZONavigationProperty *>::Grow(
                (OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *)v61.m_pListBase,
                v61.m_nIndex + 1);
              if ( v47 >= v48->m_nTop )
                v48->m_nTop = v49;
              v50 = *(OSuite::ZJsonObject **)(*(_QWORD *)(v48[1].m_nSize + 8 * v47) + 80i64);
              v51 = (OSuite::ZOEdmFunctionImport *)OSuite::ZObject::operator new(0x90ui64);
              if ( v51 )
              {
                v51->m_Name.m_pString = 0i64;
                v51->m_Schema.m_pString = 0i64;
                v51->m_EntityTypeName = 0i64;
                v51->m_EntityType = 0i64;
                v51->m_HttpMethod.m_pString = 0i64;
                v51->m_Parameters.m_pList = 0i64;
                OSuite::ZOEdmFunctionImport::ZOEdmFunctionImport(v51);
                v53 = v52;
              }
              else
              {
                v53 = 0i64;
              }
              OSuite::ZOEdmBase::ParseJson(v53, v50);
              OSuite::TList<OSuite::ZONavigationProperty *>::Grow(
                (OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *)&v4->m_FunctionImports,
                v4->m_FunctionImports.m_nTop + 1);
              v4->m_FunctionImports.m_pList[v4->m_FunctionImports.m_nTop++] = (OSuite::ZOEdmFunctionImport *)v53;
              OSuite::ZListBase::ZListIteratorBase::Next(&v61);
            }
          }
          OSuite::ZListBase::ZListIteratorBase::Next(&v63);
        }
        while ( !OSuite::ZListBase::ZListIteratorBase::AtEnd(&v63) );
        v5 = v55;
        v3 = schema;
      }
    }
    OSuite::TMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *>::ZIterator::Next(&result);
  }
  result.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TMap<OSuite::ZString,OSuite::ZJsonValue *>::ZIterator::`vftable;
  result.m_iterator.vfptr = (OSuite::TOrderedMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *,OSuite::TOperatorComparer<void *> >::ZIteratorVtbl *)&OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum  OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64>>::ZIterator::`vftable;
  result.m_iterator.m_iterator.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable;
  result.m_iterator.m_iterator.m_parents.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::ZObject};
  result.m_iterator.m_iterator.m_parents.vfptr = (OSuite::IHashableVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::IHashable};
  if ( result.m_iterator.m_iterator.m_parents.m_pList )
    result.m_iterator.m_iterator.m_parents.m_pList->vfptr->__vecDelDtor(
      (OSuite::ZObject *)result.m_iterator.m_iterator.m_parents.m_pList,
      1u);
}

// File Line: 205
// RVA: 0xED4CE8
void __fastcall OSuite::ZOMetadata::ResolvePointers(OSuite::ZOMetadata *this)
{
  OSuite::ZOMetadata *v1; // rdi
  unsigned __int64 v2; // rsi
  OSuite::ZListBase *v3; // rbx
  unsigned __int64 v4; // r14
  __int64 v5; // rbx
  bool i; // al
  unsigned __int64 v7; // rsi
  OSuite::ZListBase *v8; // rbx
  unsigned __int64 v9; // r14
  unsigned __int64 v10; // rax
  unsigned __int64 v11; // rsi
  OSuite::ZListBase *v12; // rbx
  unsigned __int64 v13; // r14
  _QWORD *v14; // rbx
  OSuite::ZString *v15; // rdx
  unsigned __int64 v16; // rsi
  OSuite::ZListBase *v17; // rbx
  unsigned __int64 v18; // r14
  __int64 v19; // rbx
  OSuite::ZString *v20; // rdx
  OSuite::ZOEdmEntityType *v21; // rax
  unsigned __int64 v22; // rsi
  OSuite::ZListBase *v23; // rbx
  unsigned __int64 v24; // r14
  unsigned __int64 v25; // rax
  unsigned __int64 v26; // rsi
  OSuite::ZListBase *v27; // rbx
  unsigned __int64 v28; // r14
  __int64 v29; // rbx
  unsigned __int64 v30; // rsi
  OSuite::ZListBase *v31; // rbx
  unsigned __int64 v32; // r14
  unsigned __int64 v33; // rax
  __int64 v34; // r15
  unsigned __int64 v35; // r14
  OSuite::ZListBase *v36; // rbx
  unsigned __int64 v37; // rsi
  __int64 v38; // rbx
  OSuite::ZOEdmAssociation *v39; // rax
  OSuite::ZString *v40; // rdx
  OSuite::ZOEdmEndRole *v41; // rax
  OSuite::ZString *v42; // rdx
  OSuite::ZOEdmAssociation *v43; // rcx
  unsigned __int64 v44; // rsi
  OSuite::ZListBase *v45; // rbx
  unsigned __int64 v46; // r14
  _QWORD *v47; // rbx
  OSuite::ZString *v48; // rdx
  OSuite::ZListBase::ZListIteratorBase v49; // [rsp+20h] [rbp-79h]
  OSuite::ZListBase::ZListIteratorBase v50; // [rsp+38h] [rbp-61h]
  OSuite::ZListBase::ZListIteratorBase v51; // [rsp+50h] [rbp-49h]
  OSuite::ZListBase::ZListIteratorBase v52; // [rsp+68h] [rbp-31h]
  OSuite::ZListBase::ZListIteratorBase v53; // [rsp+80h] [rbp-19h]
  OSuite::ZListBase::ZListIteratorBase v54; // [rsp+98h] [rbp-1h]
  OSuite::ZListBase::ZListIteratorBase v55; // [rsp+B0h] [rbp+17h]

  v53.m_pListBase = 0i64;
  v1 = this;
  OSuite::ZListBase::ZListIteratorBase::ZListIteratorBase(&v53, (OSuite::ZListBase *)&this->m_EntitySets.vfptr);
  v53.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable;
  while ( !OSuite::ZListBase::ZListIteratorBase::AtEnd(&v53) )
  {
    OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)v53.m_pListBase);
    v2 = v53.m_nIndex;
    v3 = v53.m_pListBase;
    v4 = v53.m_nIndex + 1;
    OSuite::TList<OSuite::ZONavigationProperty *>::Grow(
      (OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *)v53.m_pListBase,
      v53.m_nIndex + 1);
    if ( v2 >= v3->m_nTop )
      v3->m_nTop = v4;
    v5 = *(_QWORD *)(v3[1].m_nSize + 8 * v2);
    *(_QWORD *)(v5 + 56) = OSuite::ZOMetadata::EntityType(v1, *(OSuite::ZString **)(v5 + 64));
    (*(void (__fastcall **)(__int64))(*(_QWORD *)v5 + 16i64))(v5);
    OSuite::ZListBase::ZListIteratorBase::Next(&v53);
  }
  v51.m_pListBase = 0i64;
  v53.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable;
  OSuite::ZListBase::ZListIteratorBase::ZListIteratorBase(&v51, (OSuite::ZListBase *)&v1->m_ComplexTypes.vfptr);
  v51.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable;
  for ( i = OSuite::ZListBase::ZListIteratorBase::AtEnd(&v51); !i; i = OSuite::ZListBase::ZListIteratorBase::AtEnd(&v51) )
  {
    OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)v51.m_pListBase);
    v7 = v51.m_nIndex;
    v8 = v51.m_pListBase;
    v9 = v51.m_nIndex + 1;
    OSuite::TList<OSuite::ZONavigationProperty *>::Grow(
      (OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *)v51.m_pListBase,
      v51.m_nIndex + 1);
    if ( v7 >= v8->m_nTop )
      v8->m_nTop = v9;
    v10 = v8[1].m_nSize;
    v49.m_pListBase = 0i64;
    OSuite::ZListBase::ZListIteratorBase::ZListIteratorBase(
      &v49,
      (OSuite::ZListBase *)(*(_QWORD *)(v10 + 8 * v7) + 56i64));
    v49.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable;
    while ( !OSuite::ZListBase::ZListIteratorBase::AtEnd(&v49) )
    {
      OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)v49.m_pListBase);
      v11 = v49.m_nIndex;
      v12 = v49.m_pListBase;
      v13 = v49.m_nIndex + 1;
      OSuite::TList<OSuite::ZONavigationProperty *>::Grow(
        (OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *)v49.m_pListBase,
        v49.m_nIndex + 1);
      if ( v11 >= v12->m_nTop )
        v12->m_nTop = v13;
      v14 = *(_QWORD **)(v12[1].m_nSize + 8 * v11);
      v15 = (OSuite::ZString *)v14[9];
      if ( v15 )
      {
        v14[8] = OSuite::ZOMetadata::ComplexType(v1, v15);
        (*(void (__fastcall **)(_QWORD *))(*v14 + 16i64))(v14);
      }
      OSuite::ZListBase::ZListIteratorBase::Next(&v49);
    }
    OSuite::ZListBase::ZListIteratorBase::Next(&v51);
  }
  v52.m_pListBase = 0i64;
  v51.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable;
  OSuite::ZListBase::ZListIteratorBase::ZListIteratorBase(&v52, (OSuite::ZListBase *)&v1->m_FunctionImports.vfptr);
  v52.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable;
  while ( !OSuite::ZListBase::ZListIteratorBase::AtEnd(&v52) )
  {
    OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)v52.m_pListBase);
    v16 = v52.m_nIndex;
    v17 = v52.m_pListBase;
    v18 = v52.m_nIndex + 1;
    OSuite::TList<OSuite::ZONavigationProperty *>::Grow(
      (OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *)v52.m_pListBase,
      v52.m_nIndex + 1);
    if ( v16 >= v17->m_nTop )
      v17->m_nTop = v18;
    v19 = *(_QWORD *)(v17[1].m_nSize + 8 * v16);
    v20 = *(OSuite::ZString **)(v19 + 64);
    if ( v20 )
    {
      v21 = OSuite::ZOMetadata::EntityType(v1, v20);
      *(_QWORD *)(v19 + 72) = v21;
      if ( !v21 )
        *(_DWORD *)(v19 + 56) = 3 - (*(_DWORD *)(v19 + 56) != 0);
      (*(void (__fastcall **)(__int64))(*(_QWORD *)v19 + 16i64))(v19);
    }
    OSuite::ZListBase::ZListIteratorBase::Next(&v52);
  }
  v50.m_pListBase = 0i64;
  v52.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable;
  OSuite::ZListBase::ZListIteratorBase::ZListIteratorBase(&v50, (OSuite::ZListBase *)&v1->m_Associations.vfptr);
  v50.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable;
  while ( !OSuite::ZListBase::ZListIteratorBase::AtEnd(&v50) )
  {
    OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)v50.m_pListBase);
    v22 = v50.m_nIndex;
    v23 = v50.m_pListBase;
    v24 = v50.m_nIndex + 1;
    OSuite::TList<OSuite::ZONavigationProperty *>::Grow(
      (OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *)v50.m_pListBase,
      v50.m_nIndex + 1);
    if ( v22 >= v23->m_nTop )
      v23->m_nTop = v24;
    v25 = v23[1].m_nSize;
    v49.m_pListBase = 0i64;
    OSuite::ZListBase::ZListIteratorBase::ZListIteratorBase(
      &v49,
      (OSuite::ZListBase *)(*(_QWORD *)(v25 + 8 * v22) + 56i64));
    v49.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable;
    while ( !OSuite::ZListBase::ZListIteratorBase::AtEnd(&v49) )
    {
      OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)v49.m_pListBase);
      v26 = v49.m_nIndex;
      v27 = v49.m_pListBase;
      v28 = v49.m_nIndex + 1;
      OSuite::TList<OSuite::ZONavigationProperty *>::Grow(
        (OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *)v49.m_pListBase,
        v49.m_nIndex + 1);
      if ( v26 >= v27->m_nTop )
        v27->m_nTop = v28;
      v29 = *(_QWORD *)(v27[1].m_nSize + 8 * v26);
      *(_QWORD *)(v29 + 72) = OSuite::ZOMetadata::EntityType(v1, *(OSuite::ZString **)(v29 + 64));
      (*(void (__fastcall **)(__int64))(*(_QWORD *)v29 + 16i64))(v29);
      OSuite::ZListBase::ZListIteratorBase::Next(&v49);
    }
    OSuite::ZListBase::ZListIteratorBase::Next(&v50);
  }
  v55.m_pListBase = 0i64;
  v50.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable;
  OSuite::ZListBase::ZListIteratorBase::ZListIteratorBase(&v55, (OSuite::ZListBase *)&v1->m_EntityTypes.vfptr);
  v55.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable;
  while ( !OSuite::ZListBase::ZListIteratorBase::AtEnd(&v55) )
  {
    OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)v55.m_pListBase);
    v30 = v55.m_nIndex;
    v31 = v55.m_pListBase;
    v32 = v55.m_nIndex + 1;
    OSuite::TList<OSuite::ZONavigationProperty *>::Grow(
      (OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *)v55.m_pListBase,
      v55.m_nIndex + 1);
    if ( v30 >= v31->m_nTop )
      v31->m_nTop = v32;
    v33 = v31[1].m_nSize;
    v49.m_pListBase = 0i64;
    v34 = *(_QWORD *)(v33 + 8 * v30);
    OSuite::ZListBase::ZListIteratorBase::ZListIteratorBase(&v49, (OSuite::ZListBase *)(v34 + 136));
    v49.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable;
    while ( !OSuite::ZListBase::ZListIteratorBase::AtEnd(&v49) )
    {
      OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)v49.m_pListBase);
      v35 = v49.m_nIndex;
      v36 = v49.m_pListBase;
      v37 = v49.m_nIndex + 1;
      OSuite::TList<OSuite::ZONavigationProperty *>::Grow(
        (OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *)v49.m_pListBase,
        v49.m_nIndex + 1);
      if ( v35 >= v36->m_nTop )
        v36->m_nTop = v37;
      v38 = *(_QWORD *)(v36[1].m_nSize + 8 * v35);
      v39 = OSuite::ZOMetadata::Association(v1, *(OSuite::ZString **)(v38 + 80));
      v40 = *(OSuite::ZString **)(v38 + 88);
      *(_QWORD *)(v38 + 56) = v39;
      v41 = OSuite::ZOEdmAssociation::EndRole(v39, v40);
      v42 = *(OSuite::ZString **)(v38 + 96);
      v43 = *(OSuite::ZOEdmAssociation **)(v38 + 56);
      *(_QWORD *)(v38 + 64) = v41;
      *(_QWORD *)(v38 + 72) = OSuite::ZOEdmAssociation::EndRole(v43, v42);
      (*(void (__fastcall **)(__int64))(*(_QWORD *)v38 + 16i64))(v38);
      OSuite::ZListBase::ZListIteratorBase::Next(&v49);
    }
    v54.m_pListBase = 0i64;
    v49.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable;
    OSuite::ZListBase::ZListIteratorBase::ZListIteratorBase(&v54, (OSuite::ZListBase *)(v34 + 96));
    v54.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable;
    while ( !OSuite::ZListBase::ZListIteratorBase::AtEnd(&v54) )
    {
      OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)v54.m_pListBase);
      v44 = v54.m_nIndex;
      v45 = v54.m_pListBase;
      v46 = v54.m_nIndex + 1;
      OSuite::TList<OSuite::ZONavigationProperty *>::Grow(
        (OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *)v54.m_pListBase,
        v54.m_nIndex + 1);
      if ( v44 >= v45->m_nTop )
        v45->m_nTop = v46;
      v47 = *(_QWORD **)(v45[1].m_nSize + 8 * v44);
      v48 = (OSuite::ZString *)v47[9];
      if ( v48 )
      {
        v47[8] = OSuite::ZOMetadata::ComplexType(v1, v48);
        (*(void (__fastcall **)(_QWORD *))(*v47 + 16i64))(v47);
      }
      OSuite::ZListBase::ZListIteratorBase::Next(&v54);
    }
    OSuite::ZListBase::ZListIteratorBase::Next(&v55);
  }
}

// File Line: 291
// RVA: 0xED3FC8
OSuite::ZOEdmEntityType *__fastcall OSuite::ZOMetadata::EntityTypeForUrl(OSuite::ZOMetadata *this, OSuite::ZUrl *url)
{
  OSuite::ZOMetadata *v2; // rdi
  OSuite::ZString *v3; // rbx
  unsigned __int64 v4; // rsi
  OSuite::ZOEdmEntitySet *v5; // rbx
  OSuite::ZOEdmFunctionImport *v6; // rax
  OSuite::ZOEdmEntityType *v7; // rbx
  OSuite::ZString *v8; // rcx
  bool v10; // al
  unsigned __int64 v11; // r8
  int v12; // eax
  OSuite::ZString *v13; // rax
  OSuite::ZOEdmEntitySet *v14; // rax
  int v15; // eax
  OSuite::ZString *v16; // rax
  int v17; // eax
  OSuite::ZString *v18; // rax
  OSuite::ZOEdmEntitySet *v19; // rax
  OSuite::ZOEdmNavigationProperty *v20; // rax
  OSuite::ZString v21; // [rsp+20h] [rbp-50h]
  OSuite::ZString result; // [rsp+38h] [rbp-38h]
  OSuite::ZString sName; // [rsp+50h] [rbp-20h]

  v2 = this;
  v3 = OSuite::ZUrl::GetPath(url);
  v4 = OSuite::ZString::LastIndexOf(v3, 47);
  if ( OSuite::ZString::IndexOf(v3, 40, 0i64) >= 0 )
  {
    v10 = OSuite::ZString::EndsWith(v3, ")");
    v11 = (signed int)v4 + 1;
    if ( v10 )
    {
      result.m_pString = 0i64;
      OSuite::ZString::Slice(v3, &result, v11);
      v12 = OSuite::ZString::IndexOf(&result, 40, 0i64);
      v13 = OSuite::ZString::Slice(&result, &sName, 0i64, v12);
      OSuite::ZString::operator=(&result, v13);
      OSuite::ZString::~ZString(&sName);
      v14 = OSuite::ZOMetadata::EntitySet(v2, &result);
      v8 = &result;
      if ( v14 )
      {
        v7 = v14->m_EntityType;
        goto LABEL_7;
      }
    }
    else
    {
      sName.m_pString = 0i64;
      OSuite::ZString::Slice(v3, &sName, v11);
      result.m_pString = 0i64;
      OSuite::ZString::Slice(v3, &result, 0i64, v4);
      v15 = OSuite::ZString::LastIndexOf(&result, 47);
      v16 = OSuite::ZString::Slice(&result, &v21, v15 + 1);
      OSuite::ZString::operator=(&result, v16);
      OSuite::ZString::~ZString(&v21);
      v17 = OSuite::ZString::IndexOf(&result, 40, 0i64);
      v18 = OSuite::ZString::Slice(&result, &v21, 0i64, v17);
      OSuite::ZString::operator=(&result, v18);
      OSuite::ZString::~ZString(&v21);
      v19 = OSuite::ZOMetadata::EntitySet(v2, &result);
      if ( v19 )
      {
        v20 = OSuite::ZOEdmEntityType::NavigationProperty(v19->m_EntityType, &sName);
        if ( v20 )
        {
          v7 = v20->m_ToRole->m_EntityType;
          OSuite::ZString::~ZString(&result);
          v8 = &sName;
          goto LABEL_7;
        }
      }
      OSuite::ZString::~ZString(&result);
      v8 = &sName;
    }
  }
  else
  {
    result.m_pString = 0i64;
    OSuite::ZString::Slice(v3, &result, (signed int)v4 + 1);
    v5 = OSuite::ZOMetadata::EntitySet(v2, &result);
    v6 = OSuite::ZOMetadata::FunctionImport(v2, &result);
    if ( v5 )
    {
      v7 = v5->m_EntityType;
LABEL_6:
      v8 = &result;
LABEL_7:
      OSuite::ZString::~ZString(v8);
      return v7;
    }
    if ( v6 )
    {
      v7 = v6->m_EntityType;
      goto LABEL_6;
    }
    v8 = &result;
  }
  OSuite::ZString::~ZString(v8);
  return 0i64;
}

// File Line: 350
// RVA: 0xED3DA8
OSuite::ZOEdmEntitySet *__fastcall OSuite::ZOMetadata::EntitySet(OSuite::ZOMetadata *this, OSuite::ZString *setName)
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
  v2 = setName;
  OSuite::ZListBase::ZListIteratorBase::ZListIteratorBase(&that, (OSuite::ZListBase *)&this->m_EntitySets.vfptr);
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
  return (OSuite::ZOEdmEntitySet *)v6;
}

// File Line: 365
// RVA: 0xED41EC
OSuite::ZOEdmFunctionImport *__fastcall OSuite::ZOMetadata::FunctionImport(OSuite::ZOMetadata *this, OSuite::ZString *funcName)
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
  v2 = funcName;
  OSuite::ZListBase::ZListIteratorBase::ZListIteratorBase(&that, (OSuite::ZListBase *)&this->m_FunctionImports.vfptr);
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
  return (OSuite::ZOEdmFunctionImport *)v6;
}

// File Line: 381
// RVA: 0xED3680
OSuite::ZOEdmAssociation *__fastcall OSuite::ZOMetadata::Association(OSuite::ZOMetadata *this, OSuite::ZString *fullyQualifiedName)
{
  OSuite::ZOMetadata *v2; // rdi
  OSuite::ZString *v3; // rbx
  unsigned __int64 v4; // rdi
  OSuite::ZListBase *v5; // rbx
  unsigned __int64 v6; // rsi
  __int64 v7; // rbx
  OSuite::ZListBase::ZListIteratorBase that; // [rsp+20h] [rbp-29h]
  void **v10; // [rsp+38h] [rbp-11h]
  OSuite::ZListBase::ZListIteratorBase v11; // [rsp+40h] [rbp-9h]
  OSuite::ZString outSchema; // [rsp+58h] [rbp+Fh]
  OSuite::ZString outName; // [rsp+70h] [rbp+27h]

  outSchema.m_pString = 0i64;
  v2 = this;
  v3 = fullyQualifiedName;
  OSuite::ZString::ZString(&outSchema);
  outName.m_pString = 0i64;
  OSuite::ZString::ZString(&outName);
  if ( OSuite::SplitSchemaQualifiedName(v3, &outSchema, &outName) )
  {
    v11.m_pListBase = 0i64;
    OSuite::ZListBase::ZListIteratorBase::ZListIteratorBase(&that, (OSuite::ZListBase *)&v2->m_Associations.vfptr);
    that.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable;
    v10 = &OSuite::TConstIterator<OSuite::TList<OSuite::ZOEdmEndRole *>::ZIterator,OSuite::ZOEdmEndRole *,int>::`vftable;
    OSuite::ZListBase::ZListIteratorBase::ZListIteratorBase(&v11, &that);
    v11.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable;
    while ( !OSuite::ZListBase::ZListIteratorBase::AtEnd(&v11) )
    {
      OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)v11.m_pListBase);
      v4 = v11.m_nIndex;
      v5 = v11.m_pListBase;
      v6 = v11.m_nIndex + 1;
      OSuite::TList<OSuite::ZONavigationProperty *>::Grow(
        (OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *)v11.m_pListBase,
        v11.m_nIndex + 1);
      if ( v4 >= v5->m_nTop )
        v5->m_nTop = v6;
      v7 = *(_QWORD *)(v5[1].m_nSize + 8 * v4);
      if ( OSuite::ZString::operator==((OSuite::ZString *)(v7 + 8), &outName)
        && OSuite::ZString::operator==((OSuite::ZString *)(v7 + 32), &outSchema) )
      {
        goto LABEL_10;
      }
      OSuite::ZListBase::ZListIteratorBase::Next(&v11);
    }
  }
  v7 = 0i64;
LABEL_10:
  OSuite::ZString::~ZString(&outName);
  OSuite::ZString::~ZString(&outSchema);
  return (OSuite::ZOEdmAssociation *)v7;
}

// File Line: 408
// RVA: 0xED3E8C
OSuite::ZOEdmEntityType *__fastcall OSuite::ZOMetadata::EntityType(OSuite::ZOMetadata *this, OSuite::ZString *fullyQualifiedName)
{
  OSuite::ZOMetadata *v2; // rdi
  OSuite::ZString *v3; // rbx
  unsigned __int64 v4; // rdi
  OSuite::ZListBase *v5; // rbx
  unsigned __int64 v6; // rsi
  __int64 v7; // rbx
  OSuite::ZListBase::ZListIteratorBase that; // [rsp+20h] [rbp-29h]
  void **v10; // [rsp+38h] [rbp-11h]
  OSuite::ZListBase::ZListIteratorBase v11; // [rsp+40h] [rbp-9h]
  OSuite::ZString outSchema; // [rsp+58h] [rbp+Fh]
  OSuite::ZString outName; // [rsp+70h] [rbp+27h]

  outSchema.m_pString = 0i64;
  v2 = this;
  v3 = fullyQualifiedName;
  OSuite::ZString::ZString(&outSchema);
  outName.m_pString = 0i64;
  OSuite::ZString::ZString(&outName);
  if ( OSuite::SplitSchemaQualifiedName(v3, &outSchema, &outName) )
  {
    v11.m_pListBase = 0i64;
    OSuite::ZListBase::ZListIteratorBase::ZListIteratorBase(&that, (OSuite::ZListBase *)&v2->m_EntityTypes.vfptr);
    that.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable;
    v10 = &OSuite::TConstIterator<OSuite::TList<OSuite::ZOEdmEndRole *>::ZIterator,OSuite::ZOEdmEndRole *,int>::`vftable;
    OSuite::ZListBase::ZListIteratorBase::ZListIteratorBase(&v11, &that);
    v11.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable;
    while ( !OSuite::ZListBase::ZListIteratorBase::AtEnd(&v11) )
    {
      OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)v11.m_pListBase);
      v4 = v11.m_nIndex;
      v5 = v11.m_pListBase;
      v6 = v11.m_nIndex + 1;
      OSuite::TList<OSuite::ZONavigationProperty *>::Grow(
        (OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *)v11.m_pListBase,
        v11.m_nIndex + 1);
      if ( v4 >= v5->m_nTop )
        v5->m_nTop = v6;
      v7 = *(_QWORD *)(v5[1].m_nSize + 8 * v4);
      if ( OSuite::ZString::operator==((OSuite::ZString *)(v7 + 8), &outName)
        && OSuite::ZString::operator==((OSuite::ZString *)(v7 + 32), &outSchema) )
      {
        goto LABEL_10;
      }
      OSuite::ZListBase::ZListIteratorBase::Next(&v11);
    }
  }
  v7 = 0i64;
LABEL_10:
  OSuite::ZString::~ZString(&outName);
  OSuite::ZString::~ZString(&outSchema);
  return (OSuite::ZOEdmEntityType *)v7;
}

// File Line: 433
// RVA: 0xED37E0
OSuite::ZOEdmComplexType *__fastcall OSuite::ZOMetadata::ComplexType(OSuite::ZOMetadata *this, OSuite::ZString *fullyQualifiedName)
{
  OSuite::ZOMetadata *v2; // rdi
  OSuite::ZString *v3; // rbx
  unsigned __int64 v4; // rdi
  OSuite::ZListBase *v5; // rbx
  unsigned __int64 v6; // rsi
  __int64 v7; // rbx
  OSuite::ZListBase::ZListIteratorBase that; // [rsp+20h] [rbp-29h]
  void **v10; // [rsp+38h] [rbp-11h]
  OSuite::ZListBase::ZListIteratorBase v11; // [rsp+40h] [rbp-9h]
  OSuite::ZString outSchema; // [rsp+58h] [rbp+Fh]
  OSuite::ZString outName; // [rsp+70h] [rbp+27h]

  outSchema.m_pString = 0i64;
  v2 = this;
  v3 = fullyQualifiedName;
  OSuite::ZString::ZString(&outSchema);
  outName.m_pString = 0i64;
  OSuite::ZString::ZString(&outName);
  if ( OSuite::SplitSchemaQualifiedName(v3, &outSchema, &outName) )
  {
    v11.m_pListBase = 0i64;
    OSuite::ZListBase::ZListIteratorBase::ZListIteratorBase(&that, (OSuite::ZListBase *)&v2->m_ComplexTypes.vfptr);
    that.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable;
    v10 = &OSuite::TConstIterator<OSuite::TList<OSuite::ZOEdmEndRole *>::ZIterator,OSuite::ZOEdmEndRole *,int>::`vftable;
    OSuite::ZListBase::ZListIteratorBase::ZListIteratorBase(&v11, &that);
    v11.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable;
    while ( !OSuite::ZListBase::ZListIteratorBase::AtEnd(&v11) )
    {
      OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)v11.m_pListBase);
      v4 = v11.m_nIndex;
      v5 = v11.m_pListBase;
      v6 = v11.m_nIndex + 1;
      OSuite::TList<OSuite::ZONavigationProperty *>::Grow(
        (OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *)v11.m_pListBase,
        v11.m_nIndex + 1);
      if ( v4 >= v5->m_nTop )
        v5->m_nTop = v6;
      v7 = *(_QWORD *)(v5[1].m_nSize + 8 * v4);
      if ( OSuite::ZString::operator==((OSuite::ZString *)(v7 + 8), &outName)
        && OSuite::ZString::operator==((OSuite::ZString *)(v7 + 32), &outSchema) )
      {
        goto LABEL_10;
      }
      OSuite::ZListBase::ZListIteratorBase::Next(&v11);
    }
  }
  v7 = 0i64;
LABEL_10:
  OSuite::ZString::~ZString(&outName);
  OSuite::ZString::~ZString(&outSchema);
  return (OSuite::ZOEdmComplexType *)v7;
}

// File Line: 458
// RVA: 0xED3A18
OSuite::ZOEntry *__fastcall OSuite::ZOMetadata::CreateEntry(OSuite::ZOMetadata *this, OSuite::ZOEdmEntitySet *const entitySet)
{
  OSuite::ZOEdmEntityType *v2; // r14
  OSuite::ZOMetadata *v3; // r13
  OSuite::ZOEdmEntitySet *v4; // rsi
  char v5; // di
  OSuite::ZOEntry *v6; // rax
  OSuite::ZOEntry *v7; // rbx
  OSuite::ZString *v8; // rax
  OSuite::ZUrl *v9; // rax
  __int64 v10; // rax
  __int64 v11; // rsi
  unsigned __int64 v12; // r15
  OSuite::ZListBase *v13; // rbx
  unsigned __int64 v14; // rdi
  OSuite::ZOProperty *v15; // rbx
  OSuite::ZListBase::ZListIteratorBase that; // [rsp+28h] [rbp-D8h]
  OSuite::ZString result; // [rsp+40h] [rbp-C0h]
  OSuite::ZUrl v19; // [rsp+58h] [rbp-A8h]
  void **v20; // [rsp+130h] [rbp+30h]
  OSuite::ZListBase::ZListIteratorBase v21; // [rsp+138h] [rbp+38h]

  v2 = entitySet->m_EntityType;
  v3 = this;
  v4 = entitySet;
  v5 = 0;
  v6 = (OSuite::ZOEntry *)OSuite::ZObject::operator new(0x180ui64);
  v7 = v6;
  if ( v6 )
  {
    v6->m_sAuthorName.m_pString = 0i64;
    v6->m_sIdentifier.m_pString = 0i64;
    v6->m_sTitle.m_pString = 0i64;
    v6->m_sEditURL.m_pString = 0i64;
    v6->m_sBaseURL.m_pString = 0i64;
    v6->m_currentRequestMutex.m_pInternalMutex = 0i64;
    v6->m_ETag.m_pString = 0i64;
    v6->m_sContentUrl.m_pString = 0i64;
    v6->m_sSummary.m_pString = 0i64;
    v6->m_sContent.m_pString = 0i64;
    v6->m_sFeedURL.m_pString = 0i64;
    v6->m_pCurrentRequest = 0i64;
    v6->m_pEdmEntityType = 0i64;
    v6->m_Properties.m_pList = 0i64;
    v6->m_NavProperties.m_pList = 0i64;
    v5 = 3;
    v8 = OSuite::ZString::operator+(&v3->m_sBaseURL, &result, &v4->m_Name);
    v9 = OSuite::ZUrl::Parse(&v19, v8);
    OSuite::ZOEntry::ZOEntry(v7, v2, v9);
    v11 = v10;
  }
  else
  {
    v11 = 0i64;
  }
  if ( v5 & 2 )
  {
    v5 &= 0xFDu;
    OSuite::ZUrl::~ZUrl(&v19);
  }
  if ( v5 & 1 )
    OSuite::ZString::~ZString(&result);
  v21.m_pListBase = 0i64;
  OSuite::ZListBase::ZListIteratorBase::ZListIteratorBase(&that, (OSuite::ZListBase *)&v2->m_Properties.vfptr);
  that.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable;
  v20 = &OSuite::TConstIterator<OSuite::TList<OSuite::ZOEdmEndRole *>::ZIterator,OSuite::ZOEdmEndRole *,int>::`vftable;
  OSuite::ZListBase::ZListIteratorBase::ZListIteratorBase(&v21, &that);
  v21.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable;
  while ( !OSuite::ZListBase::ZListIteratorBase::AtEnd(&v21) )
  {
    OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)v21.m_pListBase);
    v12 = v21.m_nIndex;
    v13 = v21.m_pListBase;
    v14 = v21.m_nIndex + 1;
    OSuite::TList<OSuite::ZONavigationProperty *>::Grow(
      (OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *)v21.m_pListBase,
      v21.m_nIndex + 1);
    if ( v12 >= v13->m_nTop )
      v13->m_nTop = v14;
    v15 = OSuite::ZOMetadata::CreateProperty(v3, *(OSuite::ZOEdmProperty **)(v13[1].m_nSize + 8 * v12));
    OSuite::ZOProperty::ResetToDefault(v15);
    OSuite::TList<OSuite::ZONavigationProperty *>::Grow(
      (OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *)(v11 + 304),
      *(_QWORD *)(v11 + 320) + 1i64);
    *(_QWORD *)(*(_QWORD *)(v11 + 336) + 8i64 * (*(_QWORD *)(v11 + 320))++) = v15;
    OSuite::ZListBase::ZListIteratorBase::Next(&v21);
  }
  return (OSuite::ZOEntry *)v11;
}

// File Line: 475
// RVA: 0xED3C1C
OSuite::ZOProperty *__fastcall OSuite::ZOMetadata::CreateProperty(OSuite::ZOMetadata *this, OSuite::ZOEdmProperty *propertyTemplate)
{
  OSuite::ZOMetadata *v2; // rdi
  OSuite::ZOEdmProperty *v3; // rbx
  OSuite::ZOProperty *v4; // rax
  OSuite::ZOProperty *v5; // rax
  OSuite::ZOProperty *v6; // rdi
  OSuite::ZOEdmComplexType *v7; // rdx
  OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *v8; // rsi
  OSuite::ZOMetadata *v9; // rdi
  OSuite::ZListBase *v10; // rbx
  OSuite::ZOProperty *v11; // rbx
  OSuite::ZOMetadata *v13; // [rsp+20h] [rbp-50h]
  unsigned __int64 v14; // [rsp+20h] [rbp-50h]
  OSuite::ZOProperty *v15; // [rsp+28h] [rbp-48h]
  OSuite::ZListBase::ZListIteratorBase that; // [rsp+30h] [rbp-40h]
  void **v17; // [rsp+48h] [rbp-28h]
  OSuite::ZListBase::ZListIteratorBase v18; // [rsp+50h] [rbp-20h]

  v2 = this;
  v13 = this;
  v3 = propertyTemplate;
  v4 = (OSuite::ZOProperty *)OSuite::ZObject::operator new(0xF0ui64);
  if ( v4 )
  {
    v4->m_sAuthorName.m_pString = 0i64;
    v4->m_sIdentifier.m_pString = 0i64;
    v4->m_sTitle.m_pString = 0i64;
    v4->m_sEditURL.m_pString = 0i64;
    v4->m_sBaseURL.m_pString = 0i64;
    v4->m_pEdmProperty = 0i64;
    v4->m_Name.m_pString = 0i64;
    v4->m_Value.m_pString = 0i64;
    v4->m_SubProperties.m_pList = 0i64;
    OSuite::ZOProperty::ZOProperty(v4, v3, &v2->m_sBaseURL);
    v6 = v5;
  }
  else
  {
    v6 = 0i64;
  }
  v15 = v6;
  if ( (unsigned int)OSuite::ZOProperty::Type(v6) == 16 )
  {
    v7 = v3->m_ComplexType;
    v18.m_pListBase = 0i64;
    OSuite::ZListBase::ZListIteratorBase::ZListIteratorBase(&that, (OSuite::ZListBase *)&v7->m_Properties.vfptr);
    that.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable;
    v17 = &OSuite::TConstIterator<OSuite::TList<OSuite::ZOEdmEndRole *>::ZIterator,OSuite::ZOEdmEndRole *,int>::`vftable;
    OSuite::ZListBase::ZListIteratorBase::ZListIteratorBase(&v18, &that);
    v18.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable;
    if ( !OSuite::ZListBase::ZListIteratorBase::AtEnd(&v18) )
    {
      v8 = (OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *)&v6->m_SubProperties;
      v9 = v13;
      do
      {
        OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)v18.m_pListBase);
        v10 = v18.m_pListBase;
        v14 = v18.m_nIndex;
        OSuite::TList<OSuite::ZONavigationProperty *>::Grow(
          (OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *)v18.m_pListBase,
          v18.m_nIndex + 1);
        if ( v14 >= v10->m_nTop )
          v10->m_nTop = v14 + 1;
        v11 = OSuite::ZOMetadata::CreateProperty(v9, *(OSuite::ZOEdmProperty **)(v10[1].m_nSize + 8 * v14));
        OSuite::TList<OSuite::ZONavigationProperty *>::Grow(v8, v8->m_nTop + 1);
        v8->m_pList[v8->m_nTop++] = (OSuite::ZRedBlackTreeBase::ZElementBase *)v11;
        OSuite::ZListBase::ZListIteratorBase::Next(&v18);
      }
      while ( !OSuite::ZListBase::ZListIteratorBase::AtEnd(&v18) );
      v6 = v15;
    }
  }
  return v6;
}

