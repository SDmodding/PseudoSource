// File Line: 28
// RVA: 0x146D930
__int64 UFG::Editor::_dynamic_initializer_for__gDAGTypeLookup__()
{
  UFG::qBaseTreeRB::qBaseTreeRB(&gDAGTypeLookup.mTree);
  return atexit((int (__fastcall *)())UFG::Editor::_dynamic_atexit_destructor_for__gDAGTypeLookup__);
}

// File Line: 60
// RVA: 0x205600
UFG::Editor::FnObject *__fastcall UFG::Editor::DAGType::AquireFnObject(
        UFG::Editor::DAGType *this,
        UFG::Editor::DAGPath *path)
{
  unsigned int ObjectHash; // eax
  UFG::Editor::FnObject *mPtr; // rdi
  UFG::Editor::SmartHandleObject *v6; // r8
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *mPrev; // rdx
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *mNext; // rcx
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *v9; // rcx
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *v10; // rax
  UFG::Editor::TypedSmartHandle<2296309086,UFG::Editor::FnObject> v12; // [rsp+28h] [rbp-28h] BYREF

  ObjectHash = UFG::Editor::DAGPath::GetObjectHash(path);
  v12.mPrev = &v12;
  v12.mNext = &v12;
  v12.mPtr = 0i64;
  v12.mTypeId = -1998658210;
  UFG::Editor::TypedSmartHandle<2296309086,UFG::Editor::FnObject>::Init(&v12, ObjectHash);
  mPtr = (UFG::Editor::FnObject *)v12.mPtr;
  if ( !v12.mPtr )
    mPtr = this->vfptr->CreateFnObject(this, path);
  v6 = v12.mPtr;
  if ( v12.mPtr )
  {
    mPrev = v12.mPrev;
    mNext = v12.mNext;
    v12.mPrev->mNext = v12.mNext;
    mNext->mPrev = mPrev;
    v12.mPrev = &v12;
    v12.mNext = &v12;
    if ( (UFG::qList<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList,1,0> *)v6->mSmartHandleList.mNode.mNext == &v6->mSmartHandleList
      && v6 )
    {
      v6->vfptr->__vecDelDtor(v6, 1u);
    }
    v12.mPtr = 0i64;
  }
  v9 = v12.mPrev;
  v10 = v12.mNext;
  v12.mPrev->mNext = v12.mNext;
  v10->mPrev = v9;
  return mPtr;
}

// File Line: 74
// RVA: 0x146C730
__int64 dynamic_initializer_for__UFG::Editor::DAGPath::sEmtpyString__()
{
  UFG::qString::qString(&UFG::Editor::DAGPath::sEmtpyString, &customCaption);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::Editor::DAGPath::sEmtpyString__);
}

// File Line: 79
// RVA: 0x201440
void __fastcall UFG::Editor::DAGPath::DAGPath(UFG::Editor::DAGPath *this)
{
  UFG::qArray<UFG::qSymbol,0> *p_mElements; // rcx

  this->mFnObject.mPrev = &this->mFnObject;
  this->mFnObject.mNext = &this->mFnObject;
  this->mFnObject.mPtr = 0i64;
  this->mFnObject.mTypeId = -1998658210;
  this->mSystemName.mUID = -1;
  p_mElements = &this->mElements;
  p_mElements->p = 0i64;
  *(_QWORD *)&p_mElements->size = 0i64;
  UFG::qArray<UFG::qSymbol,0>::Reallocate(p_mElements, 4u, "qArray.Reallocate(Constructor)");
  this->mInterfaceName.mUID = -1;
  this->mSubElements.p = 0i64;
  *(_QWORD *)&this->mSubElements.size = 0i64;
  this->mPathType = Default;
}

// File Line: 98
// RVA: 0x2013B0
void __fastcall UFG::Editor::DAGPath::DAGPath(UFG::Editor::DAGPath *this, UFG::qString *str)
{
  UFG::qArray<UFG::qSymbol,0> *p_mElements; // rcx

  this->mFnObject.mPrev = &this->mFnObject;
  this->mFnObject.mNext = &this->mFnObject;
  this->mFnObject.mPtr = 0i64;
  this->mFnObject.mTypeId = -1998658210;
  this->mSystemName.mUID = -1;
  p_mElements = &this->mElements;
  p_mElements->p = 0i64;
  *(_QWORD *)&p_mElements->size = 0i64;
  UFG::qArray<UFG::qSymbol,0>::Reallocate(p_mElements, 4u, "qArray.Reallocate(Constructor)");
  this->mInterfaceName.mUID = -1;
  this->mSubElements.p = 0i64;
  *(_QWORD *)&this->mSubElements.size = 0i64;
  this->mPathType = Default;
  UFG::Editor::DAGPath::SetFromString(this, str->mData);
}

// File Line: 112
// RVA: 0x201320
void __fastcall UFG::Editor::DAGPath::DAGPath(UFG::Editor::DAGPath *this, UFG::Editor::DAGPath *src)
{
  UFG::qArray<UFG::qSymbol,0> *p_mElements; // rcx

  this->mFnObject.mPrev = &this->mFnObject;
  this->mFnObject.mNext = &this->mFnObject;
  this->mFnObject.mPtr = 0i64;
  this->mFnObject.mTypeId = -1998658210;
  this->mSystemName.mUID = -1;
  p_mElements = &this->mElements;
  p_mElements->p = 0i64;
  *(_QWORD *)&p_mElements->size = 0i64;
  UFG::qArray<UFG::qSymbol,0>::Reallocate(p_mElements, 4u, "qArray.Reallocate(Constructor)");
  this->mInterfaceName.mUID = -1;
  this->mSubElements.p = 0i64;
  *(_QWORD *)&this->mSubElements.size = 0i64;
  this->mPathType = Default;
  UFG::Editor::DAGPath::operator=(this, src);
}

// File Line: 117
// RVA: 0x203280
void __fastcall UFG::Editor::DAGPath::~DAGPath(UFG::Editor::DAGPath *this)
{
  UFG::qString *p; // rcx
  unsigned int *p_mStringHash32; // rbx
  UFG::qSymbol *v4; // rcx
  UFG::qSymbol *v5; // rbx

  p = this->mSubElements.p;
  if ( p )
  {
    p_mStringHash32 = &p[-1].mStringHash32;
    `eh vector destructor iterator(
      p,
      0x28ui64,
      p[-1].mStringHash32,
      (void (__fastcall *)(void *))UFG::qString::~qString);
    operator delete[](p_mStringHash32);
  }
  this->mSubElements.p = 0i64;
  *(_QWORD *)&this->mSubElements.size = 0i64;
  v4 = this->mElements.p;
  if ( v4 )
  {
    v5 = v4 - 1;
    `eh vector destructor iterator(v4, 4ui64, v4[-1].mUID, (void (__fastcall *)(void *))_);
    operator delete[](v5);
  }
  this->mElements.p = 0i64;
  *(_QWORD *)&this->mElements.size = 0i64;
  UFG::Editor::TypedSmartHandle<2296309086,UFG::Editor::FnObject>::~TypedSmartHandle<2296309086,UFG::Editor::FnObject>(&this->mFnObject);
}

// File Line: 122
// RVA: 0x20C010
UFG::Editor::FnModifier *__fastcall UFG::Editor::DAGPath::GetInterface(
        UFG::Editor::DAGPath *this,
        unsigned int typeID,
        UFG::qSymbol *interfaceName)
{
  UFG::Editor::FnObject *FnObject; // rax
  UFG::Editor::FnObject *v7; // rcx
  unsigned int size; // r8d
  int v9; // eax
  UFG::Editor::FnModifier **i; // rcx
  UFG::Editor::FnModifier *v11; // rdx
  UFG::Editor::FnModifier *result; // rax

  FnObject = UFG::Editor::DAGPath::GetFnObject(this);
  v7 = FnObject;
  if ( !FnObject )
    return 0i64;
  if ( this->mInterfaceName.mUID != -1 )
  {
    result = UFG::Editor::FnObject::GetModifier(FnObject, interfaceName);
    if ( result && result->mTypeID == typeID )
      return result;
    return 0i64;
  }
  size = FnObject->mFnModifiers.size;
  v9 = 0;
  if ( !size )
    return 0i64;
  for ( i = v7->mFnModifiers.p; ; ++i )
  {
    v11 = *i;
    if ( (*i)->mTypeID == typeID )
      break;
    if ( ++v9 >= size )
      return 0i64;
  }
  return v11;
}

// File Line: 169
// RVA: 0x2059A0
void __fastcall UFG::Editor::DAGPath::Clear(UFG::Editor::DAGPath *this)
{
  UFG::qSymbol *p; // rcx
  UFG::qSymbol *v3; // rbx
  UFG::qString *v4; // rcx
  unsigned int *p_mStringHash32; // rbx
  UFG::Editor::SmartHandleObject *mPtr; // rcx
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *mNext; // rax
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *mPrev; // rdx

  UFG::qSymbol::set_null(&this->mSystemName);
  p = this->mElements.p;
  if ( p )
  {
    v3 = p - 1;
    `eh vector destructor iterator(p, 4ui64, p[-1].mUID, (void (__fastcall *)(void *))_);
    operator delete[](v3);
  }
  this->mElements.p = 0i64;
  *(_QWORD *)&this->mElements.size = 0i64;
  UFG::qSymbol::set_null(&this->mInterfaceName);
  v4 = this->mSubElements.p;
  if ( v4 )
  {
    p_mStringHash32 = &v4[-1].mStringHash32;
    `eh vector destructor iterator(
      v4,
      0x28ui64,
      v4[-1].mStringHash32,
      (void (__fastcall *)(void *))UFG::qString::~qString);
    operator delete[](p_mStringHash32);
  }
  this->mSubElements.p = 0i64;
  *(_QWORD *)&this->mSubElements.size = 0i64;
  mPtr = this->mFnObject.mPtr;
  if ( mPtr )
  {
    mNext = this->mFnObject.mNext;
    mPrev = this->mFnObject.mPrev;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    this->mFnObject.mPrev = &this->mFnObject;
    this->mFnObject.mNext = &this->mFnObject;
    if ( (UFG::qList<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList,1,0> *)mPtr->mSmartHandleList.mNode.mNext == &mPtr->mSmartHandleList )
      mPtr->vfptr->__vecDelDtor(mPtr, 1u);
  }
  this->mFnObject.mPtr = 0i64;
}

// File Line: 178
// RVA: 0x203E70
UFG::Editor::DAGPath *__fastcall UFG::Editor::DAGPath::operator=(
        UFG::Editor::DAGPath *this,
        UFG::Editor::DAGPath *other)
{
  UFG::Editor::SmartHandleObject *mPtr; // rcx
  unsigned int mTypeId; // eax
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *p_mNode; // rcx
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *mPrev; // rax

  if ( other != this )
  {
    UFG::Editor::DAGPath::Clear(this);
    if ( this->mPathType == Default )
    {
      mPtr = other->mFnObject.mPtr;
      if ( !this->mFnObject.mPtr )
      {
        if ( mPtr )
        {
          mTypeId = mPtr->mTypeId;
          this->mFnObject.mPtr = mPtr;
          p_mNode = &mPtr->mSmartHandleList.mNode;
          this->mFnObject.mTypeId = mTypeId;
          mPrev = p_mNode->mPrev;
          mPrev->mNext = &this->mFnObject;
          this->mFnObject.mPrev = mPrev;
          this->mFnObject.mNext = p_mNode;
          p_mNode->mPrev = &this->mFnObject;
        }
      }
    }
    this->mSystemName.mUID = other->mSystemName.mUID;
    UFG::qArray<UFG::qSymbol,0>::Clone(&other->mElements, &this->mElements);
    this->mInterfaceName.mUID = other->mInterfaceName.mUID;
    UFG::qArray<UFG::qString,0>::Clone(&other->mSubElements, &this->mSubElements);
  }
  return this;
}

// File Line: 198
// RVA: 0x20B3F0
void __fastcall UFG::Editor::DAGPath::GetAsString(
        UFG::Editor::DAGPath *this,
        UFG::qString *dest,
        bool includeSubElements)
{
  UFG::qSymbol *p_mSystemName; // rcx
  char *v7; // rax
  __int64 v8; // rbp
  unsigned int v9; // esi
  char *i; // rbx
  UFG::qSymbolUC *v11; // r14
  char *v12; // rax
  int v13; // eax
  char *v14; // rax
  int v15; // eax
  char *v16; // rbx
  int v17; // eax
  char desta[4120]; // [rsp+20h] [rbp-1018h] BYREF

  p_mSystemName = &this->mSystemName;
  if ( p_mSystemName->mUID == -1 )
  {
    UFG::qString::Set(dest, &customCaption);
  }
  else
  {
    desta[0] = 0;
    v7 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)p_mSystemName);
    v8 = 0i64;
    v9 = 0;
    for ( i = &desta[(int)UFG::qSPrintf(desta, "<%s>", v7)]; v9 < this->mElements.size; ++v9 )
    {
      v11 = (UFG::qSymbolUC *)&this->mElements.p[v9];
      v12 = UFG::qSymbol::as_cstr_dbg(v11);
      if ( !*v12 || *v12 == -73 )
        v13 = UFG::qSPrintf(i, "#%X", v11->mUID);
      else
        v13 = UFG::qSPrintf(i, "%s", v12);
      i += v13;
      if ( v9 < this->mElements.size - 1 )
        i += (int)UFG::qSPrintf(i, "|");
    }
    if ( includeSubElements && this->mInterfaceName.mUID != -1 )
    {
      v14 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&this->mInterfaceName);
      if ( *v14 )
        v15 = UFG::qSPrintf(i, ".%s", v14);
      else
        v15 = UFG::qSPrintf(i, ".#%X", this->mInterfaceName.mUID);
      v16 = &i[v15];
      if ( this->mSubElements.size )
      {
        do
        {
          v17 = UFG::qSPrintf(v16, "[%s]", this->mSubElements.p[v8].mData);
          v8 = (unsigned int)(v8 + 1);
          v16 += v17;
        }
        while ( (unsigned int)v8 < this->mSubElements.size );
      }
    }
    UFG::qString::Set(dest, desta);
  }
}

// File Line: 256
// RVA: 0x212950
void __fastcall UFG::Editor::DAGPath::SetFromString(UFG::Editor::DAGPath *this, const char *str)
{
  const char *v2; // rdi
  unsigned int v4; // eax
  int v5; // esi
  __int64 v6; // rbx
  char v7; // cl
  __int64 v8; // rbx
  UFG::qSymbol *v9; // rax
  UFG::qSymbol *v10; // rax
  __int64 v11; // rbx
  UFG::qString *v12; // rax
  char dest[128]; // [rsp+30h] [rbp-C8h] BYREF
  UFG::qString v15; // [rsp+B0h] [rbp-48h] BYREF
  UFG::qSymbol result; // [rsp+108h] [rbp+10h] BYREF
  UFG::qSymbol v17; // [rsp+110h] [rbp+18h] BYREF
  UFG::qSymbol v18; // [rsp+118h] [rbp+20h] BYREF

  if ( str )
  {
    v2 = str;
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
            continue;
          }
          v8 = v4;
          UFG::qMemCopy(dest, &v2[-v4], v4);
          dest[v8] = 0;
          if ( v5 == 3 )
          {
            if ( *v2 == 91 || !*v2 )
            {
              UFG::qSymbol::set_from_cstr(&this->mInterfaceName, dest);
              v5 = 4;
LABEL_22:
              v4 = 0;
              continue;
            }
          }
          else if ( v5 == 2 && *v2 == 46 )
          {
            v9 = UFG::qSymbol::create_from_string(&v17, dest);
            UFG::qArray<UFG::qSymbol,0>::Add(&this->mElements, v9, "qArray.Add");
            v5 = 3;
            goto LABEL_22;
          }
          v10 = UFG::qSymbol::create_from_string(&v18, dest);
          UFG::qArray<UFG::qSymbol,0>::Add(&this->mElements, v10, "qArray.Add");
          goto LABEL_22;
        }
        v6 = v4;
        UFG::qMemCopy(dest, &v2[-v4], v4);
        dest[v6] = 0;
        this->mSystemName = (UFG::qSymbol)UFG::qSymbol::create_from_string(&result, dest)->mUID;
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
        UFG::qArray<UFG::qString,0>::Add(&this->mSubElements, v12, "qArray.Add");
        UFG::qString::~qString(&v15);
        v4 = 0;
      }
    }
    while ( *v2++ != 0 );
  }
}

// File Line: 349
// RVA: 0x20BEB0
__int64 __fastcall UFG::Editor::DAGPath::GetHash(UFG::Editor::DAGPath *this)
{
  __int64 result; // rax
  unsigned int size; // ecx
  UFG::qSymbol *p; // r8
  __int64 v5; // r9
  __int64 mUID; // rdx
  __int64 v7; // rax
  __int64 v8; // rcx
  __int64 v9; // rsi
  unsigned __int64 v10; // rax
  unsigned __int64 v11; // rcx
  unsigned int v12; // ebp
  UFG::qString *v13; // rbx
  unsigned __int64 v14; // rax

  result = this->mSystemName.mUID;
  size = this->mElements.size;
  if ( size )
  {
    p = this->mElements.p;
    v5 = size;
    do
    {
      mUID = p->mUID;
      ++p;
      v7 = result | (mUID << 32);
      result = (65
              * ((unsigned int)((21 * ((~v7 + (v7 << 18)) ^ ((unsigned __int64)(~v7 + (v7 << 18)) >> 31))) >> 11) ^ (21 * ((~(_DWORD)v7 + ((_DWORD)v7 << 18)) ^ (unsigned int)((unsigned __int64)(~v7 + (v7 << 18)) >> 31))))) ^ (unsigned int)((65 * (((21 * ((~v7 + (v7 << 18)) ^ ((unsigned __int64)(~v7 + (v7 << 18)) >> 31))) >> 11) ^ (21 * ((~v7 + (v7 << 18)) ^ ((unsigned __int64)(~v7 + (v7 << 18)) >> 31))))) >> 22);
      --v5;
    }
    while ( v5 );
  }
  v8 = this->mInterfaceName.mUID;
  if ( (_DWORD)v8 != -1 )
  {
    v9 = 0i64;
    v10 = ~(result | (v8 << 32)) + ((result | (v8 << 32)) << 18);
    v11 = 65 * (((21 * (v10 ^ (v10 >> 31))) >> 11) ^ (21 * (v10 ^ (v10 >> 31))));
    v12 = v11 ^ (v11 >> 22);
    if ( this->mSubElements.size )
    {
      do
      {
        v13 = &this->mSubElements.p[v9];
        if ( v13->mStringHash32 == -1 )
          v13->mStringHash32 = UFG::qStringHash32(v13->mData, 0xFFFFFFFF);
        v9 = (unsigned int)(v9 + 1);
        v14 = v12 | ((unsigned __int64)v13->mStringHash32 << 32);
        result = (65
                * ((unsigned int)((21 * ((~v14 + (v14 << 18)) ^ ((~v14 + (v14 << 18)) >> 31))) >> 11) ^ (21 * ((~(_DWORD)v14 + ((_DWORD)v14 << 18)) ^ (unsigned int)((~v14 + (v14 << 18)) >> 31))))) ^ (unsigned int)((65 * (((21 * ((~v14 + (v14 << 18)) ^ ((~v14 + (v14 << 18)) >> 31))) >> 11) ^ (21 * ((~v14 + (v14 << 18)) ^ ((~v14 + (v14 << 18)) >> 31))))) >> 22);
        v12 = result;
      }
      while ( (unsigned int)v9 < this->mSubElements.size );
    }
    else
    {
      return v12;
    }
  }
  return result;
}

// File Line: 371
// RVA: 0x20C360
__int64 __fastcall UFG::Editor::DAGPath::GetObjectHash(UFG::Editor::DAGPath *this)
{
  unsigned int size; // edx
  __int64 result; // rax
  UFG::qSymbol *p; // r8
  __int64 v4; // r9
  __int64 mUID; // rdx
  unsigned __int64 v6; // rax

  size = this->mElements.size;
  result = this->mSystemName.mUID;
  if ( size )
  {
    p = this->mElements.p;
    v4 = size;
    do
    {
      mUID = p->mUID;
      ++p;
      v6 = (unsigned int)result | (unsigned __int64)(mUID << 32);
      result = (65
              * ((unsigned int)((21 * ((~v6 + (v6 << 18)) ^ ((~v6 + (v6 << 18)) >> 31))) >> 11) ^ (21
                                                                                                 * ((~(_DWORD)v6 + ((_DWORD)v6 << 18)) ^ (unsigned int)((~v6 + (v6 << 18)) >> 31))))) ^ (unsigned int)((65 * (((21 * ((~v6 + (v6 << 18)) ^ ((~v6 + (v6 << 18)) >> 31))) >> 11) ^ (21 * ((~v6 + (v6 << 18)) ^ ((~v6 + (v6 << 18)) >> 31))))) >> 22);
      --v4;
    }
    while ( v4 );
  }
  return result;
}

// File Line: 383
// RVA: 0x20BE30
UFG::Editor::FnObject *__fastcall UFG::Editor::DAGPath::GetFnObject(UFG::Editor::DAGPath *this)
{
  unsigned int mUID; // edx
  UFG::qBaseTreeRB *v4; // rax
  UFG::Editor::FnObject *v5; // rax
  unsigned int mTypeId; // ecx
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *p_mNode; // rcx
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *mPrev; // rax

  if ( this->mPathType == Half )
    return 0i64;
  if ( !this->mFnObject.mPtr )
  {
    mUID = this->mSystemName.mUID;
    if ( mUID )
    {
      v4 = UFG::qBaseTreeRB::Get(&gDAGTypeLookup.mTree, mUID);
      if ( v4 )
      {
        if ( v4 != (UFG::qBaseTreeRB *)8 )
        {
          v5 = UFG::Editor::DAGType::AquireFnObject((UFG::Editor::DAGType *)&v4[-1].mCount, this);
          if ( !this->mFnObject.mPtr )
          {
            if ( v5 )
            {
              mTypeId = v5->mTypeId;
              this->mFnObject.mPtr = v5;
              this->mFnObject.mTypeId = mTypeId;
              p_mNode = &v5->mSmartHandleList.UFG::Editor::SmartHandleObject::mNode;
              mPrev = v5->mSmartHandleList.UFG::Editor::SmartHandleObject::mNode.mPrev;
              mPrev->mNext = &this->mFnObject;
              this->mFnObject.mPrev = mPrev;
              this->mFnObject.mNext = p_mNode;
              p_mNode->mPrev = &this->mFnObject;
            }
          }
        }
      }
    }
  }
  return (UFG::Editor::FnObject *)this->mFnObject.mPtr;
}

