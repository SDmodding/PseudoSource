// File Line: 18
// RVA: 0xECDCF4
void __fastcall OSuite::ZServiceOperationValue::ZServiceOperationValue(OSuite::ZServiceOperationValue *this, OSuite::ZString *sName, OSuite::ZString *sValue)
{
  OSuite::ZString *v3; // rdi
  OSuite::ZString *v4; // rbx
  OSuite::ZServiceOperationValue *v5; // rsi
  OSuite::ZObject *v6; // rdx
  OSuite::ZServiceOperationValue **v7; // rax

  v3 = sValue;
  v4 = sName;
  v5 = this;
  OSuite::ZAtomBase::ZAtomBase((OSuite::ZAtomBase *)&this->vfptr);
  v5->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZServiceOperationValue::`vftable';
  OSuite::ZString::ZString(&v5->m_Name, v4);
  OSuite::ZString::ZString(&v5->m_Value, v3);
  OSuite::ZRedBlackTreeBase::ZElementBase::ZElementBase((OSuite::ZObject *)&v5->m_subValues.vfptr, v6);
  v5->m_subValues.m_pList = 0i64;
  v5->m_subValues.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZServiceOperationValue *>::`vftable'{for `OSuite::ZListBase'};
  v5->m_subValues.vfptr = (OSuite::IHashableVtbl *)&OSuite::TList<OSuite::ZServiceOperationValue *>::`vftable'{for `OSuite::IHashable'};
  v7 = (OSuite::ZServiceOperationValue **)OSuite::ZObject::malloc(
                                            (OSuite::ZObject *)&v5->m_subValues.vfptr,
                                            0x80ui64,
                                            0i64);
  v5->m_subValues.m_nTop = 0i64;
  v5->m_subValues.m_nSize = 16i64;
  v5->m_subValues.m_pList = v7;
}

// File Line: 23
// RVA: 0xECDF5C
void __fastcall OSuite::ZServiceOperationValue::~ZServiceOperationValue(OSuite::ZServiceOperationValue *this)
{
  OSuite::ZObject *v1; // rdi
  OSuite::ZServiceOperationValue *v2; // r14
  unsigned __int64 v3; // rsi
  OSuite::ZListBase *v4; // rbx
  unsigned __int64 v5; // rbp
  void (__fastcall ***v6)(_QWORD, signed __int64); // rcx
  OSuite::ZObjectVtbl *v7; // rdx
  OSuite::ZObjectVtbl *v8; // rax
  OSuite::ZObjectVtbl *v9; // rdx
  OSuite::ZListBase::ZListIteratorBase v10; // [rsp+20h] [rbp-38h]

  v10.m_pListBase = 0i64;
  v1 = (OSuite::ZObject *)&this->m_subValues.vfptr;
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZServiceOperationValue::`vftable';
  v2 = this;
  OSuite::ZListBase::ZListIteratorBase::ZListIteratorBase(&v10, (OSuite::ZListBase *)&this->m_subValues.vfptr);
  v10.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZServiceOperationValue *>::ZIterator::`vftable';
  while ( !OSuite::ZListBase::ZListIteratorBase::AtEnd(&v10) )
  {
    OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)v10.m_pListBase);
    v3 = v10.m_nIndex;
    v4 = v10.m_pListBase;
    v5 = v10.m_nIndex + 1;
    OSuite::TList<OSuite::ZServiceOperationValue *>::Grow(
      (OSuite::TList<OSuite::ZServiceOperationValue *> *)v10.m_pListBase,
      v10.m_nIndex + 1);
    if ( v3 >= v4->m_nTop )
      v4->m_nTop = v5;
    v6 = *(void (__fastcall ****)(_QWORD, signed __int64))(v4[1].m_nSize + 8 * v3);
    if ( v6 )
      (**v6)(v6, 1i64);
    OSuite::ZListBase::ZListIteratorBase::Next(&v10);
  }
  v7 = v1[4].vfptr;
  v10.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZServiceOperationValue *>::ZIterator::`vftable';
  OSuite::ZObject::free(v1, v7);
  v8 = (OSuite::ZObjectVtbl *)OSuite::ZObject::malloc(v1, 0x80ui64, 0i64);
  v1[2].vfptr = 0i64;
  v1[1].vfptr = (OSuite::ZObjectVtbl *)16;
  v1[4].vfptr = v8;
  v9 = v1[4].vfptr;
  v1->vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZServiceOperationValue *>::`vftable'{for `OSuite::ZListBase'};
  v1[3].vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZServiceOperationValue *>::`vftable'{for `OSuite::IHashable'};
  OSuite::ZObject::free(v1, v9);
  OSuite::ZString::~ZString(&v2->m_Value);
  OSuite::ZString::~ZString(&v2->m_Name);
  OSuite::ZAtomBase::~ZAtomBase((OSuite::ZAtomBase *)&v2->vfptr);
}

// File Line: 34
// RVA: 0xECE584
void __fastcall OSuite::ZServiceOperationValue::ParseJsonValue(OSuite::ZServiceOperationValue *this, OSuite::ZString *name, OSuite::ZJsonValue *pJson)
{
  OSuite::ZString *v3; // rsi
  OSuite::ZServiceOperationValue *v4; // r15
  OSuite::ZServiceOperationValue *v5; // rdi
  OSuite::ZJsonValue *v6; // rbx
  char v7; // bp
  OSuite::ZJsonObject *v8; // r14
  OSuite::ZServiceOperationValue *v9; // rax
  OSuite::ZServiceOperationValue *v10; // rbx
  OSuite::ZString *v11; // rax
  OSuite::ZAtomBase *v12; // rax
  OSuite::ZAtomBase *v13; // rsi
  OSuite::ZError *v14; // rax
  OSuite::TPair<enum OSuite::ZError::EError,OSuite::ZString> *v15; // rax
  char v16; // bl
  signed __int64 v17; // rbx
  OSuite::ZServiceOperationValue *v18; // rax
  OSuite::ZString v19; // [rsp+20h] [rbp-58h]
  void **v20; // [rsp+38h] [rbp-40h]
  int v21; // [rsp+40h] [rbp-38h]
  OSuite::ZString that; // [rsp+48h] [rbp-30h]

  v3 = name;
  v4 = this;
  v5 = 0i64;
  v6 = pJson;
  v7 = 0;
  if ( !OSuite::ZString::operator==(name, "__metadata") )
  {
    v8 = v6->m_object;
    v9 = (OSuite::ZServiceOperationValue *)OSuite::ZObject::operator new(0xE0ui64);
    if ( v8 )
    {
      v10 = v9;
      if ( v9 )
      {
        v9->m_sAuthorName.m_pString = 0i64;
        v9->m_sIdentifier.m_pString = 0i64;
        v9->m_sTitle.m_pString = 0i64;
        v9->m_sEditURL.m_pString = 0i64;
        v9->m_sBaseURL.m_pString = 0i64;
        v9->m_Name.m_pString = 0i64;
        v9->m_Value.m_pString = 0i64;
        v9->m_subValues.m_pList = 0i64;
        v7 = 1;
        OSuite::ZString::ZString(&v19);
        OSuite::ZServiceOperationValue::ZServiceOperationValue(v10, v3, v11);
        v13 = v12;
      }
      else
      {
        v13 = 0i64;
      }
      if ( v7 & 1 )
        OSuite::ZString::~ZString(&v19);
      OSuite::ZAtomBase::ParseJson(v13, v8);
      v20 = &OSuite::TPair<enum  OSuite::ZError::EError,OSuite::ZString>::`vftable';
      v21 = 7;
      OSuite::ZString::ZString(&that);
      v14 = OSuite::TSingleton<OSuite::ZError>::Object();
      v15 = OSuite::ZError::GetThreadLastError(v14);
      if ( v15->m_First != v21 || (v16 = 1, !OSuite::ZString::operator==(&v15->m_Second, &that)) )
        v16 = 0;
      v20 = &OSuite::TPair<enum  OSuite::ZError::EError,OSuite::ZString>::`vftable';
      OSuite::ZString::~ZString(&that);
      if ( v16 )
      {
        if ( v13 )
          v13->vfptr->__vecDelDtor((OSuite::ZObject *)&v13->vfptr, 1u);
        return;
      }
      v17 = (signed __int64)&v4->m_subValues;
      OSuite::TList<OSuite::ZServiceOperationValue *>::Grow(&v4->m_subValues, v4->m_subValues.m_nTop + 1);
      v4->m_subValues.m_pList[v4->m_subValues.m_nTop] = (OSuite::ZServiceOperationValue *)v13;
    }
    else
    {
      if ( v9 )
      {
        v9->m_sAuthorName.m_pString = 0i64;
        v9->m_sIdentifier.m_pString = 0i64;
        v9->m_sTitle.m_pString = 0i64;
        v9->m_sEditURL.m_pString = 0i64;
        v9->m_sBaseURL.m_pString = 0i64;
        v9->m_Name.m_pString = 0i64;
        v9->m_Value.m_pString = 0i64;
        v9->m_subValues.m_pList = 0i64;
        OSuite::ZServiceOperationValue::ZServiceOperationValue(v9, v3, &v6->m_literal);
        v5 = v18;
      }
      v17 = (signed __int64)&v4->m_subValues;
      OSuite::TList<OSuite::ZServiceOperationValue *>::Grow(&v4->m_subValues, v4->m_subValues.m_nTop + 1);
      v4->m_subValues.m_pList[v4->m_subValues.m_nTop] = v5;
    }
    ++*(_QWORD *)(v17 + 16);
  }
}

// File Line: 62
// RVA: 0x15D8AE4
__int64 dynamic_initializer_for__OSuite::ZOServiceOperationResult::s_nClassId__()
{
  __int64 result; // rax

  result = OSuite::ZAtomBase::GenerateClassId();
  OSuite::ZOServiceOperationResult::s_nClassId = result;
  return result;
}

// File Line: 67
// RVA: 0xECDC00
void __fastcall OSuite::ZOServiceOperationResult::ZOServiceOperationResult(OSuite::ZOServiceOperationResult *this, OSuite::IReader *pReader, OSuite::ZUrl *__formal)
{
  OSuite::IReader *v3; // rdi
  OSuite::ZOServiceOperationResult *v4; // rsi
  OSuite::ZObject *v5; // rdx
  OSuite::ZServiceOperationValue **v6; // rax
  bool v7; // al
  OSuite::ZError *v8; // rax
  OSuite::ZJsonDocument v9; // [rsp+20h] [rbp-48h]

  v3 = pReader;
  v4 = this;
  OSuite::ZAtomBase::ZAtomBase((OSuite::ZAtomBase *)&this->vfptr);
  v4->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZOServiceOperationResult::`vftable';
  OSuite::ZRedBlackTreeBase::ZElementBase::ZElementBase((OSuite::ZObject *)&v4->m_Values.vfptr, v5);
  v4->m_Values.m_pList = 0i64;
  v4->m_Values.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZServiceOperationValue *>::`vftable'{for `OSuite::ZListBase'};
  v4->m_Values.vfptr = (OSuite::IHashableVtbl *)&OSuite::TList<OSuite::ZServiceOperationValue *>::`vftable'{for `OSuite::IHashable'};
  v6 = (OSuite::ZServiceOperationValue **)OSuite::ZObject::malloc(
                                            (OSuite::ZObject *)&v4->m_Values.vfptr,
                                            0x80ui64,
                                            0i64);
  v4->m_Values.m_nTop = 0i64;
  v9.m_Pairs.m_pLists = 0i64;
  v4->m_Values.m_pList = v6;
  v4->m_Values.m_nSize = 16i64;
  OSuite::ZJsonDocument::ZJsonDocument(&v9, v3);
  v7 = v9.m_bIsValid;
  v4->m_bHasValidSource = v9.m_bIsValid;
  if ( v7 )
  {
    OSuite::ZAtomBase::ParseJson((OSuite::ZAtomBase *)&v4->vfptr, (OSuite::ZJsonObject *)&v9.vfptr);
    v8 = OSuite::TSingleton<OSuite::ZError>::Object();
    v4->m_bHasValidSource = OSuite::ZError::GetThreadLastError(v8)->m_First != 7;
  }
  OSuite::ZJsonDocument::~ZJsonDocument(&v9);
}

// File Line: 82
// RVA: 0xECDE24
void __fastcall OSuite::ZOServiceOperationResult::~ZOServiceOperationResult(OSuite::ZOServiceOperationResult *this)
{
  OSuite::ZObject *v1; // rbx
  OSuite::ZOServiceOperationResult *v2; // r14
  unsigned __int64 v3; // rsi
  OSuite::ZListBase *v4; // rdi
  unsigned __int64 v5; // rbp
  void (__fastcall ***v6)(_QWORD, signed __int64); // rcx
  OSuite::ZObjectVtbl *v7; // rdx
  OSuite::ZObjectVtbl *v8; // rax
  OSuite::ZObjectVtbl *v9; // rdx
  OSuite::ZListBase::ZListIteratorBase v10; // [rsp+20h] [rbp-38h]

  v10.m_pListBase = 0i64;
  v1 = (OSuite::ZObject *)&this->m_Values.vfptr;
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZOServiceOperationResult::`vftable';
  v2 = this;
  OSuite::ZListBase::ZListIteratorBase::ZListIteratorBase(&v10, (OSuite::ZListBase *)&this->m_Values.vfptr);
  v10.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZServiceOperationValue *>::ZIterator::`vftable';
  while ( !OSuite::ZListBase::ZListIteratorBase::AtEnd(&v10) )
  {
    OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)v10.m_pListBase);
    v3 = v10.m_nIndex;
    v4 = v10.m_pListBase;
    v5 = v10.m_nIndex + 1;
    OSuite::TList<OSuite::ZServiceOperationValue *>::Grow(
      (OSuite::TList<OSuite::ZServiceOperationValue *> *)v10.m_pListBase,
      v10.m_nIndex + 1);
    if ( v3 >= v4->m_nTop )
      v4->m_nTop = v5;
    v6 = *(void (__fastcall ****)(_QWORD, signed __int64))(v4[1].m_nSize + 8 * v3);
    if ( v6 )
      (**v6)(v6, 1i64);
    OSuite::ZListBase::ZListIteratorBase::Next(&v10);
  }
  v7 = v1[4].vfptr;
  v10.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZServiceOperationValue *>::ZIterator::`vftable';
  OSuite::ZObject::free(v1, v7);
  v8 = (OSuite::ZObjectVtbl *)OSuite::ZObject::malloc(v1, 0x80ui64, 0i64);
  v1[2].vfptr = 0i64;
  v1[1].vfptr = (OSuite::ZObjectVtbl *)16;
  v1[4].vfptr = v8;
  v9 = v1[4].vfptr;
  v1->vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZServiceOperationValue *>::`vftable'{for `OSuite::ZListBase'};
  v1[3].vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZServiceOperationValue *>::`vftable'{for `OSuite::IHashable'};
  OSuite::ZObject::free(v1, v9);
  OSuite::ZAtomBase::~ZAtomBase((OSuite::ZAtomBase *)&v2->vfptr);
}

// File Line: 97
// RVA: 0xECE1A0
char __fastcall OSuite::ZOServiceOperationResult::ClassMatch(OSuite::ZOServiceOperationResult *this, int nClassId)
{
  bool v2; // al
  char v3; // cl

  if ( OSuite::ZOServiceOperationResult::s_nClassId == nClassId
    || (v2 = OSuite::ZAtomBase::ClassMatch((OSuite::ZAtomBase *)&this->vfptr, nClassId), v3 = 0, v2) )
  {
    v3 = 1;
  }
  return v3;
}

// File Line: 108
// RVA: 0xECE2C0
void __fastcall OSuite::ZOServiceOperationResult::ParseJsonValue(OSuite::ZOServiceOperationResult *this, OSuite::ZString *name, OSuite::ZJsonValue *pJson)
{
  OSuite::ZOServiceOperationResult *v3; // r13
  OSuite::ZAtomBase *v4; // rdi
  OSuite::ZJsonValue *v5; // rbx
  int v6; // er14
  unsigned __int64 v7; // r15
  OSuite::ZListBase *v8; // rbx
  unsigned __int64 v9; // r12
  OSuite::ZJsonObject *v10; // rbx
  OSuite::ZServiceOperationValue *v11; // rax
  OSuite::ZAtomBase *v12; // rax
  OSuite::ZAtomBase *v13; // r15
  unsigned __int64 v14; // r13
  OSuite::ZListBase *v15; // rbx
  unsigned __int64 v16; // r15
  __int64 v17; // r15
  OSuite::ZServiceOperationValue *v18; // rax
  OSuite::ZServiceOperationValue *v19; // rbx
  OSuite::ZAtomBase *v20; // rax
  OSuite::ZServiceOperationValue *v21; // rax
  OSuite::ZAtomBase *v22; // rax
  OSuite::ZOServiceOperationResult *v23; // [rsp+20h] [rbp-50h]
  OSuite::ZListBase::ZListIteratorBase that; // [rsp+28h] [rbp-48h]
  int v25; // [rsp+40h] [rbp-30h]
  void **v26; // [rsp+48h] [rbp-28h]
  OSuite::ZListBase::ZListIteratorBase v27; // [rsp+50h] [rbp-20h]

  v3 = this;
  v23 = this;
  v4 = 0i64;
  v5 = pJson;
  v6 = 0;
  v25 = 0;
  if ( OSuite::ZString::operator==(name, "d") )
  {
    if ( v5->m_Type == 2 )
    {
      v27.m_pListBase = 0i64;
      OSuite::ZListBase::ZListIteratorBase::ZListIteratorBase(&that, (OSuite::ZListBase *)&v5->m_array.vfptr);
      that.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable';
      v26 = &OSuite::TConstIterator<OSuite::TList<OSuite::ZOEdmEndRole *>::ZIterator,OSuite::ZOEdmEndRole *,int>::`vftable';
      OSuite::ZListBase::ZListIteratorBase::ZListIteratorBase(&v27, &that);
      v27.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable';
      while ( 1 )
      {
        if ( OSuite::ZListBase::ZListIteratorBase::AtEnd(&v27) )
          return;
        OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)v27.m_pListBase);
        v7 = v27.m_nIndex;
        v8 = v27.m_pListBase;
        v9 = v27.m_nIndex + 1;
        OSuite::TList<OSuite::ZONavigationProperty *>::Grow(
          (OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *)v27.m_pListBase,
          v27.m_nIndex + 1);
        if ( v7 >= v8->m_nTop )
          v8->m_nTop = v9;
        v10 = *(OSuite::ZJsonObject **)(*(_QWORD *)(v8[1].m_nSize + 8 * v7) + 80i64);
        if ( v10 )
          break;
        OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)v27.m_pListBase);
        v14 = v27.m_nIndex;
        v15 = v27.m_pListBase;
        v16 = v27.m_nIndex + 1;
        OSuite::TList<OSuite::ZONavigationProperty *>::Grow(
          (OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *)v27.m_pListBase,
          v27.m_nIndex + 1);
        if ( v14 >= v15->m_nTop )
          v15->m_nTop = v16;
        v17 = *(_QWORD *)(v15[1].m_nSize + 8 * v14);
        if ( !OSuite::ZString::Empty((OSuite::ZString *)(v17 + 16)) )
        {
          v18 = (OSuite::ZServiceOperationValue *)OSuite::ZObject::operator new(0xE0ui64);
          v19 = v18;
          if ( v18 )
          {
            v18->m_sAuthorName.m_pString = 0i64;
            v18->m_sIdentifier.m_pString = 0i64;
            v18->m_sTitle.m_pString = 0i64;
            v18->m_sEditURL.m_pString = 0i64;
            v18->m_sBaseURL.m_pString = 0i64;
            v18->m_Name.m_pString = 0i64;
            v18->m_Value.m_pString = 0i64;
            v18->m_subValues.m_pList = 0i64;
            OSuite::ZString::ZString((OSuite::ZString *)&that, "element");
            v6 |= 1u;
            OSuite::ZServiceOperationValue::ZServiceOperationValue(
              v19,
              (OSuite::ZString *)&that,
              (OSuite::ZString *)(v17 + 16));
            v13 = v20;
          }
          else
          {
            v13 = 0i64;
          }
          if ( v6 & 1 )
          {
            v6 &= 0xFFFFFFFE;
            OSuite::ZString::~ZString((OSuite::ZString *)&that);
          }
          v3 = v23;
          goto LABEL_11;
        }
        v3 = v23;
LABEL_22:
        OSuite::ZListBase::ZListIteratorBase::Next(&v27);
      }
      v11 = (OSuite::ZServiceOperationValue *)OSuite::ZObject::operator new(0xE0ui64);
      if ( v11 )
      {
        v11->m_sAuthorName.m_pString = 0i64;
        v11->m_sIdentifier.m_pString = 0i64;
        v11->m_sTitle.m_pString = 0i64;
        v11->m_sEditURL.m_pString = 0i64;
        v11->m_sBaseURL.m_pString = 0i64;
        v11->m_Name.m_pString = 0i64;
        v11->m_Value.m_pString = 0i64;
        v11->m_subValues.m_pList = 0i64;
        OSuite::ZServiceOperationValue::ZServiceOperationValue(v11);
        v13 = v12;
      }
      else
      {
        v13 = 0i64;
      }
      OSuite::ZAtomBase::Parse(v13, v10);
LABEL_11:
      OSuite::TList<OSuite::ZServiceOperationValue *>::Grow(&v3->m_Values, v3->m_Values.m_nTop + 1);
      v3->m_Values.m_pList[v3->m_Values.m_nTop++] = (OSuite::ZServiceOperationValue *)v13;
      goto LABEL_22;
    }
    v21 = (OSuite::ZServiceOperationValue *)OSuite::ZObject::operator new(0xE0ui64);
    if ( v21 )
    {
      v21->m_sAuthorName.m_pString = 0i64;
      v21->m_sIdentifier.m_pString = 0i64;
      v21->m_sTitle.m_pString = 0i64;
      v21->m_sEditURL.m_pString = 0i64;
      v21->m_sBaseURL.m_pString = 0i64;
      v21->m_Name.m_pString = 0i64;
      v21->m_Value.m_pString = 0i64;
      v21->m_subValues.m_pList = 0i64;
      OSuite::ZServiceOperationValue::ZServiceOperationValue(v21);
      v4 = v22;
    }
    OSuite::ZAtomBase::Parse(v4, v5->m_object);
    OSuite::TList<OSuite::ZServiceOperationValue *>::Grow(&v3->m_Values, v3->m_Values.m_nTop + 1);
    v3->m_Values.m_pList[v3->m_Values.m_nTop++] = (OSuite::ZServiceOperationValue *)v4;
  }
}

