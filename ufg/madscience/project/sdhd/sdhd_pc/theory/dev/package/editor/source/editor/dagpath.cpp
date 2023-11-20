// File Line: 28
// RVA: 0x146D930
__int64 UFG::Editor::_dynamic_initializer_for__gDAGTypeLookup__()
{
  UFG::qBaseTreeRB::qBaseTreeRB(&gDAGTypeLookup.mTree);
  return atexit(UFG::Editor::_dynamic_atexit_destructor_for__gDAGTypeLookup__);
}

// File Line: 60
// RVA: 0x205600
UFG::Editor::SmartHandleObject *__fastcall UFG::Editor::DAGType::AquireFnObject(UFG::Editor::DAGType *this, UFG::Editor::DAGPath *path)
{
  UFG::Editor::DAGPath *v2; // rsi
  UFG::Editor::DAGType *v3; // rbx
  unsigned int v4; // eax
  UFG::Editor::SmartHandleObject *v5; // rdi
  UFG::Editor::SmartHandleObject *v6; // r8
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *v7; // rdx
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *v8; // rcx
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *v14; // rcx
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *v15; // rax
  UFG::Editor::TypedSmartHandle<2296309086,UFG::Editor::FnObject> v17; // [rsp+28h] [rbp-28h]

  v2 = path;
  v3 = this;
  v4 = UFG::Editor::DAGPath::GetObjectHash(path);
  v17.mPrev = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)&v17;
  v17.mNext = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)&v17;
  v17.mPtr = 0i64;
  v17.mTypeId = -1998658210;
  UFG::Editor::TypedSmartHandle<2296309086,UFG::Editor::FnObject>::Init(&v17, v4);
  v5 = v17.mPtr;
  if ( !v17.mPtr )
    v5 = (UFG::Editor::SmartHandleObject *)v3->vfptr->CreateFnObject(v3, v2);
  v6 = v17.mPtr;
  if ( v17.mPtr )
  {
    v7 = v17.mPrev;
    v8 = v17.mNext;
    v17.mPrev->mNext = v17.mNext;
    v8->mPrev = v7;
    v17.mPrev = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)&v17;
    v17.mNext = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)&v17;
    if ( (UFG::qList<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList,1,0> *)v6->mSmartHandleList.mNode.mNext == &v6->mSmartHandleList
      && v6 )
    {
      v6->vfptr->__vecDelDtor(v6, 1u);
    }
    v17.mPtr = 0i64;
  }
  v17.mPtr = 0i64;
  v14 = v17.mPrev;
  v15 = v17.mNext;
  v17.mPrev->mNext = v17.mNext;
  v15->mPrev = v14;
  return v5;
}

// File Line: 74
// RVA: 0x146C730
__int64 dynamic_initializer_for__UFG::Editor::DAGPath::sEmtpyString__()
{
  UFG::qString::qString(&UFG::Editor::DAGPath::sEmtpyString, &customWorldMapCaption);
  return atexit(dynamic_atexit_destructor_for__UFG::Editor::DAGPath::sEmtpyString__);
}

// File Line: 79
// RVA: 0x201440
void __fastcall UFG::Editor::DAGPath::DAGPath(UFG::Editor::DAGPath *this)
{
  UFG::Editor::DAGPath *v1; // rbx
  UFG::qArray<UFG::qSymbol,0> *v2; // rcx

  v1 = this;
  this->mFnObject.mPrev = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)&this->mFnObject.mPrev;
  this->mFnObject.mNext = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)&this->mFnObject.mPrev;
  this->mFnObject.mPtr = 0i64;
  this->mFnObject.mTypeId = -1998658210;
  this->mSystemName.mUID = -1;
  v2 = &this->mElements;
  v2->p = 0i64;
  *(_QWORD *)&v2->size = 0i64;
  UFG::qArray<UFG::qSymbol,0>::Reallocate(v2, 4u, "qArray.Reallocate(Constructor)");
  v1->mInterfaceName.mUID = -1;
  v1->mSubElements.p = 0i64;
  *(_QWORD *)&v1->mSubElements.size = 0i64;
  v1->mPathType = 0;
}

// File Line: 98
// RVA: 0x2013B0
void __fastcall UFG::Editor::DAGPath::DAGPath(UFG::Editor::DAGPath *this, UFG::qString *str)
{
  UFG::qString *v2; // rbx
  UFG::Editor::DAGPath *v3; // rdi
  UFG::qArray<UFG::qSymbol,0> *v4; // rcx

  v2 = str;
  v3 = this;
  this->mFnObject.mPrev = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)&this->mFnObject.mPrev;
  this->mFnObject.mNext = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)&this->mFnObject.mPrev;
  this->mFnObject.mPtr = 0i64;
  this->mFnObject.mTypeId = -1998658210;
  this->mSystemName.mUID = -1;
  v4 = &this->mElements;
  v4->p = 0i64;
  *(_QWORD *)&v4->size = 0i64;
  UFG::qArray<UFG::qSymbol,0>::Reallocate(v4, 4u, "qArray.Reallocate(Constructor)");
  v3->mInterfaceName.mUID = -1;
  v3->mSubElements.p = 0i64;
  *(_QWORD *)&v3->mSubElements.size = 0i64;
  v3->mPathType = 0;
  UFG::Editor::DAGPath::SetFromString(v3, v2->mData);
}

// File Line: 112
// RVA: 0x201320
void __fastcall UFG::Editor::DAGPath::DAGPath(UFG::Editor::DAGPath *this, UFG::Editor::DAGPath *src)
{
  UFG::Editor::DAGPath *v2; // rbx
  UFG::Editor::DAGPath *v3; // rdi
  UFG::qArray<UFG::qSymbol,0> *v4; // rcx

  v2 = src;
  v3 = this;
  this->mFnObject.mPrev = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)&this->mFnObject.mPrev;
  this->mFnObject.mNext = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)&this->mFnObject.mPrev;
  this->mFnObject.mPtr = 0i64;
  this->mFnObject.mTypeId = -1998658210;
  this->mSystemName.mUID = -1;
  v4 = &this->mElements;
  v4->p = 0i64;
  *(_QWORD *)&v4->size = 0i64;
  UFG::qArray<UFG::qSymbol,0>::Reallocate(v4, 4u, "qArray.Reallocate(Constructor)");
  v3->mInterfaceName.mUID = -1;
  v3->mSubElements.p = 0i64;
  *(_QWORD *)&v3->mSubElements.size = 0i64;
  v3->mPathType = 0;
  UFG::Editor::DAGPath::operator=(v3, v2);
}

// File Line: 117
// RVA: 0x203280
void __fastcall UFG::Editor::DAGPath::~DAGPath(UFG::Editor::DAGPath *this)
{
  UFG::Editor::TypedSmartHandle<2296309086,UFG::Editor::FnObject> *v1; // rdi
  UFG::qString *v2; // rcx
  unsigned int *v3; // rbx
  UFG::Editor::SmartHandleObject *v4; // rcx
  char *v5; // rbx

  v1 = &this->mFnObject;
  v2 = this->mSubElements.p;
  if ( v2 )
  {
    v3 = &v2[-1].mStringHash32;
    `eh vector destructor iterator'(
      v2,
      0x28ui64,
      v2[-1].mStringHash32,
      (void (__fastcall *)(void *))UFG::qString::~qString);
    operator delete[](v3);
  }
  v1[2].mNext = 0i64;
  v1[2].mPrev = 0i64;
  v4 = v1[1].mPtr;
  if ( v4 )
  {
    v5 = (char *)(&v4[-1].mTypeId + 1);
    `eh vector destructor iterator'(v4, 4ui64, *(&v4[-1].mTypeId + 1), (void (__fastcall *)(void *))_);
    operator delete[](v5);
  }
  v1[1].mPtr = 0i64;
  v1[1].mNext = 0i64;
  UFG::Editor::TypedSmartHandle<2296309086,UFG::Editor::FnObject>::~TypedSmartHandle<2296309086,UFG::Editor::FnObject>(v1);
}

// File Line: 122
// RVA: 0x20C010
UFG::Editor::FnModifier *__fastcall UFG::Editor::DAGPath::GetInterface(UFG::Editor::DAGPath *this, unsigned int typeID, __int64 interfaceName)
{
  UFG::qSymbol *v3; // rsi
  unsigned int v4; // ebx
  UFG::Editor::DAGPath *v5; // rdi
  UFG::Editor::FnObject *v6; // rax
  UFG::Editor::FnObject *v7; // rcx
  unsigned int v8; // er8
  unsigned int v9; // eax
  UFG::Editor::FnModifier **v10; // rcx
  UFG::Editor::FnModifier *v11; // rdx
  UFG::Editor::FnModifier *result; // rax

  v3 = (UFG::qSymbol *)interfaceName;
  v4 = typeID;
  v5 = this;
  v6 = (UFG::Editor::FnObject *)UFG::Editor::DAGPath::GetFnObject(this);
  v7 = v6;
  if ( !v6 )
    return 0i64;
  if ( v5->mInterfaceName.mUID != -1 )
  {
    result = UFG::Editor::FnObject::GetModifier(v6, v3);
    if ( result && result->mTypeID == v4 )
      return result;
    return 0i64;
  }
  v8 = v6->mFnModifiers.size;
  v9 = 0;
  if ( !v8 )
    return 0i64;
  v10 = v7->mFnModifiers.p;
  while ( 1 )
  {
    v11 = *v10;
    if ( (*v10)->mTypeID == v4 )
      break;
    ++v9;
    ++v10;
    if ( v9 >= v8 )
      return 0i64;
  }
  return v11;
}

// File Line: 169
// RVA: 0x2059A0
void __fastcall UFG::Editor::DAGPath::Clear(UFG::Editor::DAGPath *this)
{
  UFG::Editor::DAGPath *v1; // rdi
  UFG::qSymbol *v2; // rcx
  UFG::qSymbol *v3; // rbx
  UFG::qString *v4; // rcx
  unsigned int *v5; // rbx
  UFG::Editor::SmartHandleObject *v6; // rcx
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *v7; // rax
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *v8; // rdx

  v1 = this;
  UFG::qSymbol::set_null(&this->mSystemName);
  v2 = v1->mElements.p;
  if ( v2 )
  {
    v3 = v2 - 1;
    `eh vector destructor iterator'(v2, 4ui64, v2[-1].mUID, (void (__fastcall *)(void *))_);
    operator delete[](v3);
  }
  v1->mElements.p = 0i64;
  *(_QWORD *)&v1->mElements.size = 0i64;
  UFG::qSymbol::set_null(&v1->mInterfaceName);
  v4 = v1->mSubElements.p;
  if ( v4 )
  {
    v5 = &v4[-1].mStringHash32;
    `eh vector destructor iterator'(
      v4,
      0x28ui64,
      v4[-1].mStringHash32,
      (void (__fastcall *)(void *))UFG::qString::~qString);
    operator delete[](v5);
  }
  v1->mSubElements.p = 0i64;
  *(_QWORD *)&v1->mSubElements.size = 0i64;
  v6 = v1->mFnObject.mPtr;
  if ( v6 )
  {
    v7 = v1->mFnObject.mNext;
    v8 = v1->mFnObject.mPrev;
    v8->mNext = v7;
    v7->mPrev = v8;
    v1->mFnObject.mPrev = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)&v1->mFnObject.mPrev;
    v1->mFnObject.mNext = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)&v1->mFnObject.mPrev;
    if ( (UFG::qList<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList,1,0> *)v6->mSmartHandleList.mNode.mNext == &v6->mSmartHandleList )
    {
      if ( v6 )
        v6->vfptr->__vecDelDtor(v6, 1u);
    }
  }
  v1->mFnObject.mPtr = 0i64;
}

// File Line: 178
// RVA: 0x203E70
UFG::Editor::DAGPath *__fastcall UFG::Editor::DAGPath::operator=(UFG::Editor::DAGPath *this, UFG::Editor::DAGPath *other)
{
  UFG::Editor::DAGPath *v2; // rdi
  UFG::Editor::DAGPath *v3; // rbx
  UFG::Editor::SmartHandleObject *v4; // rcx
  unsigned int v5; // eax
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *v6; // rcx
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *v7; // rax

  v2 = other;
  v3 = this;
  if ( other != this )
  {
    UFG::Editor::DAGPath::Clear(this);
    if ( v3->mPathType == Default )
    {
      v4 = v2->mFnObject.mPtr;
      if ( !v3->mFnObject.mPtr )
      {
        if ( v4 )
        {
          v5 = v4->mTypeId;
          v3->mFnObject.mPtr = v4;
          v6 = &v4->mSmartHandleList.mNode;
          v3->mFnObject.mTypeId = v5;
          v7 = v6->mPrev;
          v7->mNext = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)&v3->mFnObject.mPrev;
          v3->mFnObject.mPrev = v7;
          v3->mFnObject.mNext = v6;
          v6->mPrev = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)&v3->mFnObject.mPrev;
        }
      }
    }
    v3->mSystemName.mUID = v2->mSystemName.mUID;
    UFG::qArray<UFG::qSymbol,0>::Clone(&v2->mElements, &v3->mElements);
    v3->mInterfaceName.mUID = v2->mInterfaceName.mUID;
    UFG::qArray<UFG::qString,0>::Clone(&v2->mSubElements, &v3->mSubElements);
  }
  return v3;
}

// File Line: 198
// RVA: 0x20B3F0
void __fastcall UFG::Editor::DAGPath::GetAsString(UFG::Editor::DAGPath *this, UFG::qString *dest, bool includeSubElements)
{
  UFG::Editor::DAGPath *v3; // rdi
  UFG::qSymbolUC *v4; // rcx
  bool v5; // r12
  UFG::qString *v6; // r15
  char *v7; // rax
  __int64 v8; // rbp
  unsigned int v9; // esi
  char *v10; // rbx
  UFG::qSymbolUC *v11; // r14
  char *v12; // rax
  int v13; // eax
  char *v14; // rax
  int v15; // eax
  char *v16; // rbx
  int v17; // eax
  char desta[4120]; // [rsp+20h] [rbp-1018h]

  v3 = this;
  v4 = (UFG::qSymbolUC *)&this->mSystemName;
  v5 = includeSubElements;
  v6 = dest;
  if ( v4->mUID == -1 )
  {
    UFG::qString::Set(dest, &customWorldMapCaption);
  }
  else
  {
    desta[0] = 0;
    v7 = UFG::qSymbol::as_cstr_dbg(v4);
    v8 = 0i64;
    v9 = 0;
    v10 = &desta[(signed int)UFG::qSPrintf(desta, "<%s>", v7)];
    if ( v3->mElements.size )
    {
      do
      {
        v11 = (UFG::qSymbolUC *)&v3->mElements.p[v9];
        v12 = UFG::qSymbol::as_cstr_dbg(v11);
        if ( *v12 && *v12 != -73 )
          v13 = UFG::qSPrintf(v10, "%s", v12);
        else
          v13 = UFG::qSPrintf(v10, "#%X", v11->mUID);
        v10 += v13;
        if ( v9 < v3->mElements.size - 1 )
          v10 += (signed int)UFG::qSPrintf(v10, "|");
        ++v9;
      }
      while ( v9 < v3->mElements.size );
    }
    if ( v5 == 1 && v3->mInterfaceName.mUID != -1 )
    {
      v14 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&v3->mInterfaceName);
      if ( *v14 )
        v15 = UFG::qSPrintf(v10, ".%s", v14);
      else
        v15 = UFG::qSPrintf(v10, ".#%X", v3->mInterfaceName.mUID);
      v16 = &v10[v15];
      if ( v3->mSubElements.size > 0 )
      {
        do
        {
          v17 = UFG::qSPrintf(v16, "[%s]", v3->mSubElements.p[v8].mData);
          v8 = (unsigned int)(v8 + 1);
          v16 += v17;
        }
        while ( (unsigned int)v8 < v3->mSubElements.size );
      }
    }
    UFG::qString::Set(v6, desta);
  }
}

// File Line: 256
// RVA: 0x212950
void __fastcall UFG::Editor::DAGPath::SetFromString(UFG::Editor::DAGPath *this, const char *str)
{
  const char *v2; // rdi
  UFG::Editor::DAGPath *v3; // rbp
  unsigned int v4; // eax
  signed int v5; // esi
  __int64 v6; // rbx
  char v7; // cl
  __int64 v8; // rbx
  UFG::qSymbol *v9; // rax
  UFG::qSymbol *v10; // rax
  __int64 v11; // rbx
  UFG::qString *v12; // rax
  bool v13; // cl
  char dest[128]; // [rsp+30h] [rbp-C8h]
  UFG::qString v15; // [rsp+B0h] [rbp-48h]
  UFG::qSymbol result; // [rsp+108h] [rbp+10h]
  UFG::qSymbol v17; // [rsp+110h] [rbp+18h]
  UFG::qSymbol v18; // [rsp+118h] [rbp+20h]

  if ( str )
  {
    v2 = str;
    v3 = this;
    v4 = 0;
    v5 = 2;
    if ( *str == 60 )
    {
      v2 = str + 1;
      v5 = 1;
    }
    do
    {
      if ( v5 == 1 )
      {
        if ( *v2 != 62 || !v4 )
        {
LABEL_9:
          v7 = *v2;
          if ( *v2 != 124 && v7 != 46 && v7 != 91 && v7 || !v4 )
          {
LABEL_26:
            if ( v7 != 35 || v4 )
              ++v4;
            goto LABEL_29;
          }
          v8 = v4;
          UFG::qMemCopy(dest, &v2[-v4], v4);
          dest[v8] = 0;
          if ( v5 == 3 )
          {
            if ( *v2 == 91 || !*v2 )
            {
              UFG::qSymbol::set_from_cstr(&v3->mInterfaceName, dest);
              v5 = 4;
LABEL_22:
              v4 = 0;
              goto LABEL_29;
            }
          }
          else if ( v5 == 2 && *v2 == 46 )
          {
            v9 = UFG::qSymbol::create_from_string(&v17, dest);
            UFG::qArray<UFG::qSymbol,0>::Add(&v3->mElements, v9, "qArray.Add");
            v5 = 3;
            goto LABEL_22;
          }
          v10 = UFG::qSymbol::create_from_string(&v18, dest);
          UFG::qArray<UFG::qSymbol,0>::Add(&v3->mElements, v10, "qArray.Add");
          goto LABEL_22;
        }
        v6 = v4;
        UFG::qMemCopy(dest, &v2[-v4], v4);
        dest[v6] = 0;
        v3->mSystemName = (UFG::qSymbol)UFG::qSymbol::create_from_string(&result, dest)->mUID;
        v5 = 2;
        v4 = 0;
      }
      else
      {
        if ( v5 != 4 )
          goto LABEL_9;
        v7 = *v2;
        if ( *v2 != 93 || !v4 )
          goto LABEL_26;
        v11 = v4;
        UFG::qMemCopy(dest, &v2[-v4], v4);
        dest[v11] = 0;
        UFG::qString::qString(&v15, dest);
        UFG::qArray<UFG::qString,0>::Add(&v3->mSubElements, v12, "qArray.Add");
        UFG::qString::~qString(&v15);
        v4 = 0;
      }
LABEL_29:
      v13 = *v2++ != 0;
    }
    while ( v13 );
  }
}

// File Line: 349
// RVA: 0x20BEB0
__int64 __fastcall UFG::Editor::DAGPath::GetHash(UFG::Editor::DAGPath *this)
{
  __int64 result; // rax
  UFG::Editor::DAGPath *v2; // rdi
  unsigned int v3; // ecx
  UFG::qSymbol *v4; // r8
  __int64 v5; // r9
  __int64 v6; // rdx
  __int64 v7; // rdx
  unsigned __int64 v8; // rcx
  __int64 v9; // rcx
  __int64 v10; // rsi
  unsigned __int64 v11; // rax
  unsigned __int64 v12; // rcx
  unsigned int v13; // ebp
  signed __int64 v14; // rbx
  unsigned __int64 v15; // rcx
  unsigned __int64 v16; // rcx
  unsigned __int64 v17; // rcx

  result = this->mSystemName.mUID;
  v2 = this;
  v3 = this->mElements.size;
  if ( v3 )
  {
    v4 = v2->mElements.p;
    v5 = v3;
    do
    {
      v6 = v4->mUID;
      ++v4;
      v7 = result | (v6 << 32);
      v8 = 65
         * ((21 * ((~v7 + (v7 << 18)) ^ ((unsigned __int64)(~v7 + (v7 << 18)) >> 31)) >> 11) ^ 21
                                                                                             * ((~v7 + (v7 << 18)) ^ ((unsigned __int64)(~v7 + (v7 << 18)) >> 31)));
      result = (unsigned int)v8 ^ (unsigned int)(v8 >> 22);
      --v5;
    }
    while ( v5 );
  }
  v9 = v2->mInterfaceName.mUID;
  if ( (_DWORD)v9 != -1 )
  {
    v10 = 0i64;
    v11 = ~(result | (v9 << 32)) + ((result | (v9 << 32)) << 18);
    v12 = 65 * ((21 * (v11 ^ (v11 >> 31)) >> 11) ^ 21 * (v11 ^ (v11 >> 31)));
    v13 = v12 ^ (v12 >> 22);
    if ( v2->mSubElements.size )
    {
      do
      {
        v14 = (signed __int64)&v2->mSubElements.p[v10];
        if ( *(_DWORD *)(v14 + 32) == -1 )
          *(_DWORD *)(v14 + 32) = UFG::qStringHash32(*(const char **)(v14 + 24), 0xFFFFFFFF);
        v10 = (unsigned int)(v10 + 1);
        v15 = v13 | ((unsigned __int64)*(unsigned int *)(v14 + 32) << 32);
        v16 = 21 * ((~v15 + (v15 << 18)) ^ ((~v15 + (v15 << 18)) >> 31));
        v17 = 65 * ((v16 >> 11) ^ v16);
        result = (unsigned int)v17 ^ (unsigned int)(v17 >> 22);
        v13 = v17 ^ (v17 >> 22);
      }
      while ( (unsigned int)v10 < v2->mSubElements.size );
    }
    else
    {
      result = v13;
    }
  }
  return result;
}

// File Line: 371
// RVA: 0x20C360
__int64 __fastcall UFG::Editor::DAGPath::GetObjectHash(UFG::Editor::DAGPath *this)
{
  unsigned int v1; // edx
  __int64 result; // rax
  UFG::qSymbol *v3; // r8
  __int64 v4; // r9
  __int64 v5; // rdx
  unsigned __int64 v6; // rdx
  unsigned __int64 v7; // rcx

  v1 = this->mElements.size;
  result = this->mSystemName.mUID;
  if ( v1 )
  {
    v3 = this->mElements.p;
    v4 = v1;
    do
    {
      v5 = v3->mUID;
      ++v3;
      v6 = (unsigned int)result | (unsigned __int64)(v5 << 32);
      v7 = 65
         * ((21 * ((~v6 + (v6 << 18)) ^ ((~v6 + (v6 << 18)) >> 31)) >> 11) ^ 21
                                                                           * ((~v6 + (v6 << 18)) ^ ((~v6 + (v6 << 18)) >> 31)));
      result = (unsigned int)v7 ^ (unsigned int)(v7 >> 22);
      --v4;
    }
    while ( v4 );
  }
  return result;
}

// File Line: 383
// RVA: 0x20BE30
UFG::Editor::SmartHandleObject *__fastcall UFG::Editor::DAGPath::GetFnObject(UFG::Editor::DAGPath *this)
{
  UFG::Editor::DAGPath *v1; // rbx
  unsigned int v3; // edx
  UFG::qBaseTreeRB *v4; // rax
  UFG::Editor::SmartHandleObject *v5; // rax
  unsigned int v6; // ecx
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *v7; // rcx
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *v8; // rax

  v1 = this;
  if ( this->mPathType == 1 )
    return 0i64;
  if ( !this->mFnObject.mPtr )
  {
    v3 = this->mSystemName.mUID;
    if ( v3 )
    {
      v4 = UFG::qBaseTreeRB::Get(&gDAGTypeLookup.mTree, v3);
      if ( v4 )
      {
        if ( v4 != (UFG::qBaseTreeRB *)8 )
        {
          v5 = UFG::Editor::DAGType::AquireFnObject((UFG::Editor::DAGType *)&v4[-1].mCount, v1);
          if ( !v1->mFnObject.mPtr )
          {
            if ( v5 )
            {
              v6 = v5->mTypeId;
              v1->mFnObject.mPtr = v5;
              v1->mFnObject.mTypeId = v6;
              v7 = &v5->mSmartHandleList.mNode;
              v8 = v5->mSmartHandleList.mNode.mPrev;
              v8->mNext = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)&v1->mFnObject.mPrev;
              v1->mFnObject.mPrev = v8;
              v1->mFnObject.mNext = v7;
              v7->mPrev = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)&v1->mFnObject.mPrev;
            }
          }
        }
      }
    }
  }
  return v1->mFnObject.mPtr;
}

