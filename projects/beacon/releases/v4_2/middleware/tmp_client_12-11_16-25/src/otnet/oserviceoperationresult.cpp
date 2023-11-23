// File Line: 18
// RVA: 0xECDCF4
void __fastcall OSuite::ZServiceOperationValue::ZServiceOperationValue(
        OSuite::ZServiceOperationValue *this,
        OSuite::ZString *sName,
        OSuite::ZString *sValue)
{
  OSuite::ZObject *v6; // rdx
  OSuite::ZServiceOperationValue **v7; // rax

  OSuite::ZAtomBase::ZAtomBase(this);
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZServiceOperationValue::`vftable;
  OSuite::ZString::ZString(&this->m_Name, sName);
  OSuite::ZString::ZString(&this->m_Value, sValue);
  OSuite::ZRedBlackTreeBase::ZElementBase::ZElementBase(&this->m_subValues, v6);
  this->m_subValues.m_pList = 0i64;
  this->m_subValues.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZServiceOperationValue *>::`vftable{for `OSuite::ZListBase};
  this->m_subValues.vfptr = (OSuite::IHashableVtbl *)&OSuite::TList<OSuite::ZServiceOperationValue *>::`vftable{for `OSuite::IHashable};
  v7 = (OSuite::ZServiceOperationValue **)OSuite::ZObject::malloc(&this->m_subValues, 0x80ui64, 0i64);
  this->m_subValues.m_nTop = 0i64;
  this->m_subValues.m_nSize = 16i64;
  this->m_subValues.m_pList = v7;
}

// File Line: 23
// RVA: 0xECDF5C
void __fastcall OSuite::ZServiceOperationValue::~ZServiceOperationValue(OSuite::ZServiceOperationValue *this)
{
  OSuite::TList<OSuite::ZServiceOperationValue *> *p_m_subValues; // rdi
  unsigned __int64 m_nIndex; // rsi
  OSuite::ZListBase *m_pListBase; // rbx
  unsigned __int64 v5; // rbp
  void (__fastcall ***v6)(_QWORD, __int64); // rcx
  OSuite::ZServiceOperationValue **m_pList; // rdx
  OSuite::ZServiceOperationValue **v8; // rax
  OSuite::ZServiceOperationValue **v9; // rdx
  OSuite::ZListBase::ZListIteratorBase v10; // [rsp+20h] [rbp-38h] BYREF

  v10.m_pListBase = 0i64;
  p_m_subValues = &this->m_subValues;
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZServiceOperationValue::`vftable;
  OSuite::ZListBase::ZListIteratorBase::ZListIteratorBase(&v10, &this->m_subValues);
  v10.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZServiceOperationValue *>::ZIterator::`vftable;
  while ( !OSuite::ZListBase::ZListIteratorBase::AtEnd(&v10) )
  {
    OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)v10.m_pListBase);
    m_nIndex = v10.m_nIndex;
    m_pListBase = v10.m_pListBase;
    v5 = v10.m_nIndex + 1;
    OSuite::TList<OSuite::ZServiceOperationValue *>::Grow(
      (OSuite::TList<OSuite::ZServiceOperationValue *> *)v10.m_pListBase,
      v10.m_nIndex + 1);
    if ( m_nIndex >= m_pListBase->m_nTop )
      m_pListBase->m_nTop = v5;
    v6 = *(void (__fastcall ****)(_QWORD, __int64))(m_pListBase[1].m_nSize + 8 * m_nIndex);
    if ( v6 )
      (**v6)(v6, 1i64);
    OSuite::ZListBase::ZListIteratorBase::Next(&v10);
  }
  m_pList = p_m_subValues->m_pList;
  v10.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZServiceOperationValue *>::ZIterator::`vftable;
  OSuite::ZObject::free(p_m_subValues, m_pList);
  v8 = (OSuite::ZServiceOperationValue **)OSuite::ZObject::malloc(p_m_subValues, 0x80ui64, 0i64);
  p_m_subValues->m_nTop = 0i64;
  p_m_subValues->m_nSize = 16i64;
  p_m_subValues->m_pList = v8;
  v9 = p_m_subValues->m_pList;
  p_m_subValues->OSuite::ZListBase::OSuite::ZObject::vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZServiceOperationValue *>::`vftable{for `OSuite::ZListBase};
  p_m_subValues->OSuite::IHashable::vfptr = (OSuite::IHashableVtbl *)&OSuite::TList<OSuite::ZServiceOperationValue *>::`vftable{for `OSuite::IHashable};
  OSuite::ZObject::free(p_m_subValues, v9);
  OSuite::ZString::~ZString(&this->m_Value);
  OSuite::ZString::~ZString(&this->m_Name);
  OSuite::ZAtomBase::~ZAtomBase(this);
}

// File Line: 34
// RVA: 0xECE584
void __fastcall OSuite::ZServiceOperationValue::ParseJsonValue(
        OSuite::ZServiceOperationValue *this,
        OSuite::ZString *name,
        OSuite::ZJsonValue *pJson)
{
  OSuite::ZServiceOperationValue *v5; // rdi
  char v7; // bp
  OSuite::ZJsonObject *m_object; // r14
  OSuite::ZServiceOperationValue *v9; // rax
  OSuite::ZServiceOperationValue *v10; // rbx
  OSuite::ZString *v11; // rax
  OSuite::ZServiceOperationValue *v12; // rax
  OSuite::ZServiceOperationValue *v13; // rsi
  OSuite::ZError *v14; // rax
  OSuite::TPair<enum OSuite::ZError::EError,OSuite::ZString> *ThreadLastError; // rax
  char v16; // bl
  OSuite::TList<OSuite::ZServiceOperationValue *> *p_m_subValues; // rbx
  OSuite::ZServiceOperationValue *v18; // rax
  OSuite::ZString v19; // [rsp+20h] [rbp-58h] BYREF
  void **v20; // [rsp+38h] [rbp-40h]
  int v21; // [rsp+40h] [rbp-38h]
  OSuite::ZString that; // [rsp+48h] [rbp-30h] BYREF

  v5 = 0i64;
  v7 = 0;
  if ( !OSuite::ZString::operator==(name, "__metadata") )
  {
    m_object = pJson->m_object;
    v9 = (OSuite::ZServiceOperationValue *)OSuite::ZObject::operator new(0xE0ui64);
    if ( m_object )
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
        OSuite::ZServiceOperationValue::ZServiceOperationValue(v10, name, v11);
        v13 = v12;
      }
      else
      {
        v13 = 0i64;
      }
      if ( (v7 & 1) != 0 )
        OSuite::ZString::~ZString(&v19);
      OSuite::ZAtomBase::ParseJson(v13, m_object);
      v20 = &OSuite::TPair<enum OSuite::ZError::EError,OSuite::ZString>::`vftable;
      v21 = 7;
      OSuite::ZString::ZString(&that);
      v14 = OSuite::TSingleton<OSuite::ZError>::Object();
      ThreadLastError = OSuite::ZError::GetThreadLastError(v14);
      if ( ThreadLastError->m_First != v21 || (v16 = 1, !OSuite::ZString::operator==(&ThreadLastError->m_Second, &that)) )
        v16 = 0;
      v20 = &OSuite::TPair<enum OSuite::ZError::EError,OSuite::ZString>::`vftable;
      OSuite::ZString::~ZString(&that);
      if ( v16 )
      {
        if ( v13 )
          v13->vfptr->__vecDelDtor(v13, 1u);
        return;
      }
      p_m_subValues = &this->m_subValues;
      OSuite::TList<OSuite::ZServiceOperationValue *>::Grow(&this->m_subValues, this->m_subValues.m_nTop + 1);
      this->m_subValues.m_pList[this->m_subValues.m_nTop] = v13;
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
        OSuite::ZServiceOperationValue::ZServiceOperationValue(v9, name, &pJson->m_literal);
        v5 = v18;
      }
      p_m_subValues = &this->m_subValues;
      OSuite::TList<OSuite::ZServiceOperationValue *>::Grow(&this->m_subValues, this->m_subValues.m_nTop + 1);
      this->m_subValues.m_pList[this->m_subValues.m_nTop] = v5;
    }
    ++p_m_subValues->m_nTop;
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
void __fastcall OSuite::ZOServiceOperationResult::ZOServiceOperationResult(
        OSuite::ZOServiceOperationResult *this,
        OSuite::IReader *pReader,
        OSuite::ZUrl *__formal)
{
  OSuite::ZObject *v5; // rdx
  OSuite::ZServiceOperationValue **v6; // rax
  bool m_bIsValid; // al
  OSuite::ZError *v8; // rax
  OSuite::ZJsonDocument v9; // [rsp+20h] [rbp-48h] BYREF

  OSuite::ZAtomBase::ZAtomBase(this);
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZOServiceOperationResult::`vftable;
  OSuite::ZRedBlackTreeBase::ZElementBase::ZElementBase(&this->m_Values, v5);
  this->m_Values.m_pList = 0i64;
  this->m_Values.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZServiceOperationValue *>::`vftable{for `OSuite::ZListBase};
  this->m_Values.vfptr = (OSuite::IHashableVtbl *)&OSuite::TList<OSuite::ZServiceOperationValue *>::`vftable{for `OSuite::IHashable};
  v6 = (OSuite::ZServiceOperationValue **)OSuite::ZObject::malloc(&this->m_Values, 0x80ui64, 0i64);
  this->m_Values.m_nTop = 0i64;
  v9.m_Pairs.m_pLists = 0i64;
  this->m_Values.m_pList = v6;
  this->m_Values.m_nSize = 16i64;
  OSuite::ZJsonDocument::ZJsonDocument(&v9, pReader);
  m_bIsValid = v9.m_bIsValid;
  this->m_bHasValidSource = v9.m_bIsValid;
  if ( m_bIsValid )
  {
    OSuite::ZAtomBase::ParseJson(this, &v9);
    v8 = OSuite::TSingleton<OSuite::ZError>::Object();
    this->m_bHasValidSource = OSuite::ZError::GetThreadLastError(v8)->m_First != ZERROR_PARSING_FAILED;
  }
  OSuite::ZJsonDocument::~ZJsonDocument(&v9);
}

// File Line: 82
// RVA: 0xECDE24
void __fastcall OSuite::ZOServiceOperationResult::~ZOServiceOperationResult(OSuite::ZOServiceOperationResult *this)
{
  OSuite::TList<OSuite::ZServiceOperationValue *> *p_m_Values; // rbx
  unsigned __int64 m_nIndex; // rsi
  OSuite::ZListBase *m_pListBase; // rdi
  unsigned __int64 v5; // rbp
  void (__fastcall ***v6)(_QWORD, __int64); // rcx
  OSuite::ZServiceOperationValue **m_pList; // rdx
  OSuite::ZServiceOperationValue **v8; // rax
  OSuite::ZServiceOperationValue **v9; // rdx
  OSuite::ZListBase::ZListIteratorBase v10; // [rsp+20h] [rbp-38h] BYREF

  v10.m_pListBase = 0i64;
  p_m_Values = &this->m_Values;
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZOServiceOperationResult::`vftable;
  OSuite::ZListBase::ZListIteratorBase::ZListIteratorBase(&v10, &this->m_Values);
  v10.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZServiceOperationValue *>::ZIterator::`vftable;
  while ( !OSuite::ZListBase::ZListIteratorBase::AtEnd(&v10) )
  {
    OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)v10.m_pListBase);
    m_nIndex = v10.m_nIndex;
    m_pListBase = v10.m_pListBase;
    v5 = v10.m_nIndex + 1;
    OSuite::TList<OSuite::ZServiceOperationValue *>::Grow(
      (OSuite::TList<OSuite::ZServiceOperationValue *> *)v10.m_pListBase,
      v10.m_nIndex + 1);
    if ( m_nIndex >= m_pListBase->m_nTop )
      m_pListBase->m_nTop = v5;
    v6 = *(void (__fastcall ****)(_QWORD, __int64))(m_pListBase[1].m_nSize + 8 * m_nIndex);
    if ( v6 )
      (**v6)(v6, 1i64);
    OSuite::ZListBase::ZListIteratorBase::Next(&v10);
  }
  m_pList = p_m_Values->m_pList;
  v10.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZServiceOperationValue *>::ZIterator::`vftable;
  OSuite::ZObject::free(p_m_Values, m_pList);
  v8 = (OSuite::ZServiceOperationValue **)OSuite::ZObject::malloc(p_m_Values, 0x80ui64, 0i64);
  p_m_Values->m_nTop = 0i64;
  p_m_Values->m_nSize = 16i64;
  p_m_Values->m_pList = v8;
  v9 = p_m_Values->m_pList;
  p_m_Values->OSuite::ZListBase::OSuite::ZObject::vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZServiceOperationValue *>::`vftable{for `OSuite::ZListBase};
  p_m_Values->OSuite::IHashable::vfptr = (OSuite::IHashableVtbl *)&OSuite::TList<OSuite::ZServiceOperationValue *>::`vftable{for `OSuite::IHashable};
  OSuite::ZObject::free(p_m_Values, v9);
  OSuite::ZAtomBase::~ZAtomBase(this);
}

// File Line: 97
// RVA: 0xECE1A0
char __fastcall OSuite::ZOServiceOperationResult::ClassMatch(OSuite::ZOServiceOperationResult *this, int nClassId)
{
  bool v2; // al
  char v3; // cl

  if ( OSuite::ZOServiceOperationResult::s_nClassId == nClassId )
    return 1;
  v2 = OSuite::ZAtomBase::ClassMatch(this, nClassId);
  v3 = 0;
  if ( v2 )
    return 1;
  return v3;
}

// File Line: 108
// RVA: 0xECE2C0
void __fastcall OSuite::ZOServiceOperationResult::ParseJsonValue(
        OSuite::ZOServiceOperationResult *this,
        OSuite::ZString *name,
        OSuite::ZJsonValue *pJson)
{
  OSuite::ZOServiceOperationResult *v3; // r13
  OSuite::ZAtomBase *v4; // rdi
  int v6; // r14d
  unsigned __int64 m_nIndex; // r15
  OSuite::ZListBase *m_pListBase; // rbx
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
  OSuite::ZListBase::ZListIteratorBase that; // [rsp+28h] [rbp-48h] BYREF
  int v25; // [rsp+40h] [rbp-30h]
  void **v26; // [rsp+48h] [rbp-28h]
  OSuite::ZListBase::ZListIteratorBase v27; // [rsp+50h] [rbp-20h] BYREF

  v3 = this;
  v4 = 0i64;
  v6 = 0;
  v25 = 0;
  if ( OSuite::ZString::operator==(name, "d") )
  {
    if ( pJson->m_Type == JSONTYPE_ARRAY )
    {
      v27.m_pListBase = 0i64;
      OSuite::ZListBase::ZListIteratorBase::ZListIteratorBase(&that, &pJson->m_array);
      that.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable;
      v26 = &OSuite::TConstIterator<OSuite::TList<OSuite::ZOEdmEndRole *>::ZIterator,OSuite::ZOEdmEndRole *,int>::`vftable;
      OSuite::ZListBase::ZListIteratorBase::ZListIteratorBase(&v27, &that);
      v27.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable;
      while ( 1 )
      {
        if ( OSuite::ZListBase::ZListIteratorBase::AtEnd(&v27) )
          return;
        OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)v27.m_pListBase);
        m_nIndex = v27.m_nIndex;
        m_pListBase = v27.m_pListBase;
        v9 = v27.m_nIndex + 1;
        OSuite::TList<OSuite::ZONavigationProperty *>::Grow(
          (OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *)v27.m_pListBase,
          v27.m_nIndex + 1);
        if ( m_nIndex >= m_pListBase->m_nTop )
          m_pListBase->m_nTop = v9;
        v10 = *(OSuite::ZJsonObject **)(*(_QWORD *)(m_pListBase[1].m_nSize + 8 * m_nIndex) + 80i64);
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
          if ( (v6 & 1) != 0 )
          {
            v6 &= ~1u;
            OSuite::ZString::~ZString((OSuite::ZString *)&that);
          }
          v3 = this;
          goto LABEL_11;
        }
        v3 = this;
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
    OSuite::ZAtomBase::Parse(v4, pJson->m_object);
    OSuite::TList<OSuite::ZServiceOperationValue *>::Grow(&v3->m_Values, v3->m_Values.m_nTop + 1);
    v3->m_Values.m_pList[v3->m_Values.m_nTop++] = (OSuite::ZServiceOperationValue *)v4;
  }
}

