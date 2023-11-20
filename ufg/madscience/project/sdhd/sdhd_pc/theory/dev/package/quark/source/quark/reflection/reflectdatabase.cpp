// File Line: 38
// RVA: 0x161A60
void __fastcall UFG::qReflectionString::qReflectionString(UFG::qReflectionString *this, unsigned __int64 uid, const char *text)
{
  int v3; // ebp
  const char *v4; // rsi
  UFG::qReflectionString *v5; // rdi
  const char *v6; // rax
  char v7; // cl
  UFG::qMemoryPool *v8; // rcx
  char *v9; // rax

  this->mBaseNode.mParent = &this->mBaseNode;
  v3 = 0;
  v4 = text;
  this->mBaseNode.mUID = 0i64;
  v5 = this;
  this->mBaseNode.mChildren[0] = &this->mBaseNode;
  this->mBaseNode.mChildren[1] = &this->mBaseNode;
  this->mBaseNode.mNeighbours[0] = &this->mBaseNode;
  this->mBaseNode.mNeighbours[1] = &this->mBaseNode;
  if ( text )
  {
    v6 = text;
    do
      v7 = *v6++;
    while ( v7 );
    v3 = (_DWORD)v6 - (_DWORD)text - 1;
  }
  v5->mBaseNode.mUID = uid;
  v8 = UFG::gMainMemoryPool;
  if ( !UFG::gMainMemoryPool )
  {
    UFG::InternalSetupMainMemoryPool((UFG *)UFG::gMainMemoryPool);
    v8 = UFG::gMainMemoryPool;
  }
  v9 = UFG::qMemoryPool::Allocate(v8, v3 + 1, "qReflectionString", 0i64, 1u);
  v5->mText = v9;
  UFG::qStringCopy(v9, v3 + 1, v4, v3);
}

// File Line: 93
// RVA: 0x173E00
UFG::ReflectionDB *__fastcall UFG::ReflectionDB::Instance()
{
  UFG::ReflectionDB *result; // rax

  if ( _S11 & 1 )
    return &sReflectedDB;
  _S11 |= 1u;
  sReflectedDB.mStrings.mTree.mHead.mUID = 0i64;
  result = &sReflectedDB;
  sReflectedDB.mStrings.mTree.mHead.mParent = (UFG::qTree64Base::BaseNode *)&sReflectedDB;
  sReflectedDB.mStrings.mTree.mHead.mChildren[0] = (UFG::qTree64Base::BaseNode *)&sReflectedDB;
  sReflectedDB.mStrings.mTree.mHead.mChildren[1] = (UFG::qTree64Base::BaseNode *)&sReflectedDB;
  sReflectedDB.mStrings.mTree.mHead.mNeighbours[0] = (UFG::qTree64Base::BaseNode *)&sReflectedDB;
  sReflectedDB.mStrings.mTree.mHead.mNeighbours[1] = (UFG::qTree64Base::BaseNode *)&sReflectedDB;
  sReflectedDB.mStrings.mTree.mCount = 0i64;
  sReflectedDB.mTypes.mTree.mHead.mUID = 0i64;
  sReflectedDB.mTypes.mTree.mHead.mParent = &sReflectedDB.mTypes.mTree.mHead;
  sReflectedDB.mTypes.mTree.mHead.mChildren[0] = &sReflectedDB.mTypes.mTree.mHead;
  sReflectedDB.mTypes.mTree.mHead.mChildren[1] = &sReflectedDB.mTypes.mTree.mHead;
  sReflectedDB.mTypes.mTree.mHead.mNeighbours[0] = &sReflectedDB.mTypes.mTree.mHead;
  sReflectedDB.mTypes.mTree.mHead.mNeighbours[1] = &sReflectedDB.mTypes.mTree.mHead;
  sReflectedDB.mTypes.mTree.mCount = 0i64;
  sReflectedDB.mEnums.mTree.mHead.mUID = 0i64;
  sReflectedDB.mEnums.mTree.mHead.mParent = &sReflectedDB.mEnums.mTree.mHead;
  sReflectedDB.mEnums.mTree.mHead.mChildren[0] = &sReflectedDB.mEnums.mTree.mHead;
  sReflectedDB.mEnums.mTree.mHead.mChildren[1] = &sReflectedDB.mEnums.mTree.mHead;
  sReflectedDB.mEnums.mTree.mHead.mNeighbours[0] = &sReflectedDB.mEnums.mTree.mHead;
  sReflectedDB.mEnums.mTree.mHead.mNeighbours[1] = &sReflectedDB.mEnums.mTree.mHead;
  sReflectedDB.mEnums.mTree.mCount = 0i64;
  sReflectedDB.mSchemas.mTree.mHead.mUID = 0i64;
  sReflectedDB.mSchemas.mTree.mHead.mParent = &sReflectedDB.mSchemas.mTree.mHead;
  sReflectedDB.mSchemas.mTree.mHead.mChildren[0] = &sReflectedDB.mSchemas.mTree.mHead;
  sReflectedDB.mSchemas.mTree.mHead.mChildren[1] = &sReflectedDB.mSchemas.mTree.mHead;
  sReflectedDB.mSchemas.mTree.mHead.mNeighbours[0] = &sReflectedDB.mSchemas.mTree.mHead;
  sReflectedDB.mSchemas.mTree.mHead.mNeighbours[1] = &sReflectedDB.mSchemas.mTree.mHead;
  sReflectedDB.mSchemas.mTree.mCount = 0i64;
  UFG::gReflectedDB = &sReflectedDB;
  return result;
}

// File Line: 127
// RVA: 0x1667A0
const char *__fastcall UFG::ReflectionDB::AddString(UFG::ReflectionDB *this, const char *text)
{
  const char *v2; // r14
  UFG::ReflectionDB *v3; // rdi
  unsigned __int64 v4; // rbx
  char i; // al
  UFG::ReflectionDB *v6; // rax
  UFG::qTree64Base::BaseNode *v7; // rsi
  UFG::qMemoryPool *v8; // rcx
  char *v9; // rax
  UFG::qTree64Base::BaseNode *v10; // rax

  v2 = text;
  v3 = this;
  v4 = -1i64;
  if ( text )
  {
    for ( i = *text; *text; i = *text )
    {
      v4 = (v4 >> 8) ^ sCrcTable64[(unsigned __int8)(v4 ^ i)];
      ++text;
    }
  }
  v6 = (UFG::ReflectionDB *)this->mStrings.mTree.mHead.mChildren[0];
  v7 = 0i64;
  while ( v6 != this )
  {
    if ( v6->mStrings.mTree.mHead.mUID >= v4 )
    {
      if ( v6->mStrings.mTree.mHead.mUID <= v4 )
        goto LABEL_11;
      v6 = (UFG::ReflectionDB *)v6->mStrings.mTree.mHead.mChildren[0];
    }
    else
    {
      v6 = (UFG::ReflectionDB *)v6->mStrings.mTree.mHead.mChildren[1];
    }
  }
  v6 = 0i64;
LABEL_11:
  if ( v6 )
    return (const char *)v6->mStrings.mTree.mCount;
  v8 = UFG::gMainMemoryPool;
  if ( !UFG::gMainMemoryPool )
  {
    UFG::InternalSetupMainMemoryPool((UFG *)UFG::gMainMemoryPool);
    v8 = UFG::gMainMemoryPool;
  }
  v9 = UFG::qMemoryPool::Allocate(v8, 0x38ui64, "AddString", 0i64, 1u);
  if ( v9 )
  {
    UFG::qReflectionString::qReflectionString((UFG::qReflectionString *)v9, v4, v2);
    v7 = v10;
  }
  UFG::qTree64Base::Add(&v3->mStrings.mTree, v7);
  return (const char *)v7[1].mUID;
}

// File Line: 139
// RVA: 0x1724F0
UFG::ReflectionDB *__fastcall UFG::ReflectionDB::GetString(UFG::ReflectionDB *this, unsigned __int64 uid)
{
  UFG::ReflectionDB *result; // rax

  result = (UFG::ReflectionDB *)this->mStrings.mTree.mHead.mChildren[0];
  while ( result != this )
  {
    if ( result->mStrings.mTree.mHead.mUID >= uid )
    {
      if ( result->mStrings.mTree.mHead.mUID <= uid )
        goto LABEL_8;
      result = (UFG::ReflectionDB *)result->mStrings.mTree.mHead.mChildren[0];
    }
    else
    {
      result = (UFG::ReflectionDB *)result->mStrings.mTree.mHead.mChildren[1];
    }
  }
  result = 0i64;
LABEL_8:
  if ( result )
    result = (UFG::ReflectionDB *)result->mStrings.mTree.mCount;
  return result;
}

// File Line: 164
// RVA: 0x172C10
UFG::qTree64<UFG::qReflectType,UFG::qReflectType,0> *__fastcall UFG::ReflectionDB::GetType(UFG::ReflectionDB *this, const char *type_name)
{
  const char *v2; // r8
  unsigned __int64 v3; // rdx
  char v4; // al
  UFG::qTree64<UFG::qReflectType,UFG::qReflectType,0> *result; // rax

  v2 = type_name;
  if ( type_name )
  {
    v4 = *type_name;
    v3 = -1i64;
    if ( v4 )
    {
      do
      {
        ++v2;
        v3 = (v3 >> 8) ^ sCrcTable64[(unsigned __int8)(v3 ^ v4)];
        v4 = *v2;
      }
      while ( *v2 );
    }
  }
  else
  {
    v3 = -1i64;
  }
  result = (UFG::qTree64<UFG::qReflectType,UFG::qReflectType,0> *)this->mTypes.mTree.mHead.mChildren[0];
  while ( result != &this->mTypes )
  {
    if ( result->mTree.mHead.mUID >= v3 )
    {
      if ( result->mTree.mHead.mUID <= v3 )
        return result;
      result = (UFG::qTree64<UFG::qReflectType,UFG::qReflectType,0> *)result->mTree.mHead.mChildren[0];
    }
    else
    {
      result = (UFG::qTree64<UFG::qReflectType,UFG::qReflectType,0> *)result->mTree.mHead.mChildren[1];
    }
  }
  return 0i64;
}

// File Line: 171
// RVA: 0x172C90
UFG::qTree64<UFG::qReflectType,UFG::qReflectType,0> *__fastcall UFG::ReflectionDB::GetType(UFG::ReflectionDB *this, unsigned __int64 type_uid)
{
  UFG::qTree64<UFG::qReflectType,UFG::qReflectType,0> *result; // rax

  result = (UFG::qTree64<UFG::qReflectType,UFG::qReflectType,0> *)this->mTypes.mTree.mHead.mChildren[0];
  while ( result != &this->mTypes )
  {
    if ( result->mTree.mHead.mUID >= type_uid )
    {
      if ( result->mTree.mHead.mUID <= type_uid )
        return result;
      result = (UFG::qTree64<UFG::qReflectType,UFG::qReflectType,0> *)result->mTree.mHead.mChildren[0];
    }
    else
    {
      result = (UFG::qTree64<UFG::qReflectType,UFG::qReflectType,0> *)result->mTree.mHead.mChildren[1];
    }
  }
  return 0i64;
}

// File Line: 177
// RVA: 0x170380
UFG::qTree64<UFG::qReflectEnum,UFG::qReflectEnum,0> *__fastcall UFG::ReflectionDB::GetEnum(UFG::ReflectionDB *this, const char *type_name)
{
  const char *v2; // r8
  unsigned __int64 v3; // rdx
  char v4; // al
  UFG::qTree64<UFG::qReflectEnum,UFG::qReflectEnum,0> *result; // rax

  v2 = type_name;
  if ( type_name )
  {
    v4 = *type_name;
    v3 = -1i64;
    if ( v4 )
    {
      do
      {
        ++v2;
        v3 = (v3 >> 8) ^ sCrcTable64[(unsigned __int8)(v3 ^ v4)];
        v4 = *v2;
      }
      while ( *v2 );
    }
  }
  else
  {
    v3 = -1i64;
  }
  result = (UFG::qTree64<UFG::qReflectEnum,UFG::qReflectEnum,0> *)this->mEnums.mTree.mHead.mChildren[0];
  while ( result != &this->mEnums )
  {
    if ( result->mTree.mHead.mUID >= v3 )
    {
      if ( result->mTree.mHead.mUID <= v3 )
        return result;
      result = (UFG::qTree64<UFG::qReflectEnum,UFG::qReflectEnum,0> *)result->mTree.mHead.mChildren[0];
    }
    else
    {
      result = (UFG::qTree64<UFG::qReflectEnum,UFG::qReflectEnum,0> *)result->mTree.mHead.mChildren[1];
    }
  }
  return 0i64;
}

// File Line: 197
// RVA: 0x172340
UFG::qTree64<UFG::qReflectSchema,UFG::qReflectSchema,0> *__fastcall UFG::ReflectionDB::GetSchema(UFG::ReflectionDB *this, unsigned __int64 type_uid)
{
  UFG::qTree64<UFG::qReflectSchema,UFG::qReflectSchema,0> *result; // rax

  result = (UFG::qTree64<UFG::qReflectSchema,UFG::qReflectSchema,0> *)this->mSchemas.mTree.mHead.mChildren[0];
  while ( result != &this->mSchemas )
  {
    if ( result->mTree.mHead.mUID >= type_uid )
    {
      if ( result->mTree.mHead.mUID <= type_uid )
        return result;
      result = (UFG::qTree64<UFG::qReflectSchema,UFG::qReflectSchema,0> *)result->mTree.mHead.mChildren[0];
    }
    else
    {
      result = (UFG::qTree64<UFG::qReflectSchema,UFG::qReflectSchema,0> *)result->mTree.mHead.mChildren[1];
    }
  }
  return 0i64;
}

// File Line: 210
// RVA: 0x175510
char __fastcall UFG::ReflectionDB::IsDerivedFrom(UFG::ReflectionDB *this, unsigned __int64 type_uid, unsigned __int64 base_class_uid)
{
  UFG::ReflectionDB *v3; // rax
  unsigned __int64 v4; // rsi
  UFG::ReflectionDB *v5; // rbp
  unsigned __int64 v7; // rbx
  signed __int64 v8; // rdi
  unsigned __int64 v9; // rdx

  v3 = (UFG::ReflectionDB *)this->mTypes.mTree.mHead.mChildren[0];
  v4 = base_class_uid;
  v5 = this;
  while ( v3 != (UFG::ReflectionDB *)&this->mTypes )
  {
    if ( v3->mStrings.mTree.mHead.mUID >= type_uid )
    {
      if ( v3->mStrings.mTree.mHead.mUID <= type_uid )
        goto LABEL_8;
      v3 = (UFG::ReflectionDB *)v3->mStrings.mTree.mHead.mChildren[0];
    }
    else
    {
      v3 = (UFG::ReflectionDB *)v3->mStrings.mTree.mHead.mChildren[1];
    }
  }
  v3 = 0i64;
LABEL_8:
  if ( type_uid == base_class_uid )
    return 1;
  v7 = v3->mSchemas.mTree.mHead.mUID;
  v8 = (signed __int64)&v3->mEnums.mTree.mCount;
  if ( (__int64 *)v7 == &v3->mEnums.mTree.mCount )
    return 0;
  while ( 1 )
  {
    if ( *(_BYTE *)(v7 + 112) & 2 )
    {
      v9 = *(_QWORD *)(v7 + 88);
      if ( v9 == v4 || UFG::ReflectionDB::IsDerivedFrom(v5, v9, v4) )
        break;
    }
    v7 = *(_QWORD *)(v7 + 8);
    if ( v7 == v8 )
      return 0;
  }
  return 1;
}

// File Line: 235
// RVA: 0x17ECC0
bool __fastcall UFG::ReflectionDB::TryGetEnumStrings(UFG::ReflectionDB *this, const char *type_name, UFG::qList<UFG::qString,UFG::qString,1,0> *strings)
{
  UFG::qList<UFG::qString,UFG::qString,1,0> *v3; // rdi
  UFG::qTree64<UFG::qReflectEnum,UFG::qReflectEnum,0> *v4; // rax
  UFG::qTree64<UFG::qReflectEnum,UFG::qReflectEnum,0> *v5; // r15
  UFG::qTree64Base::BaseNode *v6; // rbx
  signed __int64 i; // r14
  const char *v8; // rbp
  UFG::qMemoryPool *v9; // rcx
  UFG::qString *v10; // rax
  UFG::qNode<UFG::qString,UFG::qString> *v11; // rax
  UFG::qNode<UFG::qString,UFG::qString> *v12; // rcx

  v3 = strings;
  v4 = UFG::ReflectionDB::GetEnum(this, type_name);
  v5 = v4;
  if ( v4 )
  {
    v6 = v4[1].mTree.mHead.mChildren[0];
    for ( i = (signed __int64)&v4[1].mTree.mHead.mParent; v6 != (UFG::qTree64Base::BaseNode *)i; v6 = v6->mParent )
    {
      v8 = UFG::gGlobalNewName;
      v9 = UFG::gMainMemoryPool;
      if ( !UFG::gMainMemoryPool )
      {
        UFG::InternalSetupMainMemoryPool((UFG *)UFG::gMainMemoryPool);
        v9 = UFG::gMainMemoryPool;
      }
      v10 = (UFG::qString *)UFG::qMemoryPool::Allocate(v9, 0x28ui64, v8, 0i64, 1u);
      if ( v10 )
        UFG::qString::qString(v10, (const char *)v6->mChildren[0]);
      else
        v11 = 0i64;
      v12 = v3->mNode.mPrev;
      v12->mNext = v11;
      v11->mPrev = v12;
      v11->mNext = &v3->mNode;
      v3->mNode.mPrev = v11;
    }
  }
  return v5 != 0i64;
}

// File Line: 250
// RVA: 0x16B460
UFG::ReflectionDB::CreateType

// File Line: 278
// RVA: 0x166140
UFG::qReflectField *__fastcall UFG::ReflectionDB::AddField(UFG::ReflectionDB *this, UFG::qReflectType *type, const char *field_name, const char *field_type_name, unsigned __int64 byte_offset, unsigned __int64 array_length, unsigned int flags)
{
  const char *v7; // r15
  const char *v8; // r14
  UFG::qReflectType *v9; // r8
  UFG::ReflectionDB *v10; // r13
  unsigned __int64 v11; // rsi
  unsigned __int64 v12; // rbx
  char *v13; // rdx
  char v14; // al
  UFG::qTree64Base *v15; // rbp
  UFG::qTree64<UFG::qReflectField,UFG::qReflectField,0> *v16; // rax
  UFG::qReflectField *result; // rax
  UFG::qMemoryPool *v18; // rcx
  char *v19; // rax
  char *v20; // rdi
  _QWORD *v21; // rax
  unsigned __int64 v22; // rdx
  char i; // al
  char j; // al
  UFG::qNode<UFG::qReflectField,UFG::qReflectField> *v25; // rcx
  UFG::qReflectType *v26; // [rsp+88h] [rbp+10h]

  v26 = type;
  v7 = field_type_name;
  v8 = field_name;
  v9 = type;
  v10 = this;
  v11 = -1i64;
  v12 = -1i64;
  if ( v8 )
  {
    v13 = (char *)v8;
    v14 = *v8;
    if ( *v8 )
    {
      do
      {
        v12 = (v12 >> 8) ^ sCrcTable64[(unsigned __int8)(v12 ^ v14)];
        v14 = *++v13;
      }
      while ( *v13 );
    }
  }
  v15 = &v9->mFields.mTree;
  v16 = (UFG::qTree64<UFG::qReflectField,UFG::qReflectField,0> *)v9->mFields.mTree.mHead.mChildren[0];
  if ( v16 == &v9->mFields )
    goto LABEL_13;
  while ( v16->mTree.mHead.mUID < v12 )
  {
    v16 = (UFG::qTree64<UFG::qReflectField,UFG::qReflectField,0> *)v16->mTree.mHead.mChildren[1];
LABEL_9:
    if ( v16 == (UFG::qTree64<UFG::qReflectField,UFG::qReflectField,0> *)v15 )
      goto LABEL_13;
  }
  if ( v16->mTree.mHead.mUID > v12 )
  {
    v16 = (UFG::qTree64<UFG::qReflectField,UFG::qReflectField,0> *)v16->mTree.mHead.mChildren[0];
    goto LABEL_9;
  }
  result = (UFG::qReflectField *)&v16[-1].mTree.mHead.mNeighbours[1];
  if ( result )
  {
    result->mFlags |= flags;
    return result;
  }
LABEL_13:
  v18 = UFG::gMainMemoryPool;
  if ( !UFG::gMainMemoryPool )
  {
    UFG::InternalSetupMainMemoryPool((UFG *)UFG::gMainMemoryPool);
    v18 = UFG::gMainMemoryPool;
  }
  v19 = UFG::qMemoryPool::Allocate(v18, 0x78ui64, "AddField", 0i64, 1u);
  v20 = v19;
  if ( v19 )
  {
    *(_QWORD *)v19 = v19;
    *((_QWORD *)v19 + 1) = v19;
    v21 = v19 + 16;
    *v21 = 0i64;
    v21[1] = v21;
    v21[2] = v21;
    v21[3] = v21;
    v21[4] = v21;
    v21[5] = v21;
  }
  else
  {
    v20 = 0i64;
  }
  *((_QWORD *)v20 + 2) = v12;
  *((_QWORD *)v20 + 8) = UFG::ReflectionDB::AddString(v10, v8);
  v22 = -1i64;
  if ( v8 )
  {
    for ( i = *v8; *v8; i = *v8 )
    {
      v22 = (v22 >> 8) ^ sCrcTable64[(unsigned __int8)(v22 ^ i)];
      ++v8;
    }
  }
  *((_QWORD *)v20 + 10) = v22;
  *((_QWORD *)v20 + 9) = UFG::ReflectionDB::AddString(v10, v7);
  if ( v7 )
  {
    for ( j = *v7; *v7; j = *v7 )
    {
      v11 = (v11 >> 8) ^ sCrcTable64[(unsigned __int8)(v11 ^ j)];
      ++v7;
    }
  }
  *((_QWORD *)v20 + 11) = v11;
  *((_QWORD *)v20 + 12) = byte_offset;
  *((_QWORD *)v20 + 13) = array_length;
  *((_DWORD *)v20 + 28) = flags;
  UFG::qTree64Base::Add(v15, (UFG::qTree64Base::BaseNode *)(v20 + 16));
  v25 = v26->mOrderedFields.mNode.mPrev;
  v25->mNext = (UFG::qNode<UFG::qReflectField,UFG::qReflectField> *)v20;
  *(_QWORD *)v20 = v25;
  *((_QWORD *)v20 + 1) = (char *)v26 + 160;
  v26->mOrderedFields.mNode.mPrev = (UFG::qNode<UFG::qReflectField,UFG::qReflectField> *)v20;
  return (UFG::qReflectField *)v20;
}

// File Line: 308
// RVA: 0x16AF10
UFG::ReflectionDB::CreateEnum

// File Line: 323
// RVA: 0x166000
UFG::qReflectEnumValue *__fastcall UFG::ReflectionDB::AddEnumValue(UFG::ReflectionDB *this, UFG::qReflectEnum *enum_type, const char *value_name, __int64 value)
{
  __int64 v4; // rbp
  const char *v5; // r14
  UFG::qReflectEnum *v6; // rsi
  UFG::ReflectionDB *v7; // r15
  unsigned __int64 v8; // rbx
  const char *v9; // rdx
  char i; // al
  UFG::qReflectEnumValue *result; // rax
  UFG::qReflectEnumValue *v12; // rsi
  UFG::qMemoryPool *v13; // rcx
  char *v14; // rax
  UFG::qReflectEnumValue *v15; // rdi
  UFG::qNode<UFG::qReflectEnumValue,UFG::qReflectEnumValue> *v16; // rcx

  v4 = value;
  v5 = value_name;
  v6 = enum_type;
  v7 = this;
  v8 = -1i64;
  if ( value_name )
  {
    v9 = value_name;
    for ( i = *value_name; *v9; i = *v9 )
    {
      v8 = (v8 >> 8) ^ sCrcTable64[(unsigned __int8)(v8 ^ i)];
      ++v9;
    }
  }
  result = (UFG::qReflectEnumValue *)v6->mValues.mNode.mNext;
  v12 = (UFG::qReflectEnumValue *)&v6->mValues;
  if ( result == v12 )
  {
LABEL_7:
    v13 = UFG::gMainMemoryPool;
    if ( !UFG::gMainMemoryPool )
    {
      UFG::InternalSetupMainMemoryPool((UFG *)UFG::gMainMemoryPool);
      v13 = UFG::gMainMemoryPool;
    }
    v14 = UFG::qMemoryPool::Allocate(v13, 0x28ui64, "AddEnumValue", 0i64, 1u);
    v15 = (UFG::qReflectEnumValue *)v14;
    if ( v14 )
    {
      *(_QWORD *)v14 = v14;
      *((_QWORD *)v14 + 1) = v14;
    }
    else
    {
      v15 = 0i64;
    }
    v15->mName = UFG::ReflectionDB::AddString(v7, v5);
    v15->mNameUID = v8;
    v15->mValue = v4;
    v16 = v12->mPrev;
    v16->mNext = (UFG::qNode<UFG::qReflectEnumValue,UFG::qReflectEnumValue> *)&v15->mPrev;
    v15->mPrev = v16;
    v15->mNext = (UFG::qNode<UFG::qReflectEnumValue,UFG::qReflectEnumValue> *)&v12->mPrev;
    v12->mPrev = (UFG::qNode<UFG::qReflectEnumValue,UFG::qReflectEnumValue> *)&v15->mPrev;
    result = v15;
  }
  else
  {
    while ( v8 != result->mNameUID )
    {
      result = (UFG::qReflectEnumValue *)result->mNext;
      if ( result == v12 )
        goto LABEL_7;
    }
  }
  return result;
}

// File Line: 352
// RVA: 0x16B200
UFG::qReflectSchema *__fastcall UFG::ReflectionDB::CreateSchema(UFG::ReflectionDB *this, UFG::qReflectSchema *parent_schema, const char *name)
{
  const char *v3; // r14
  UFG::qReflectSchema *v4; // rbp
  UFG::ReflectionDB *v5; // r15
  unsigned __int64 v6; // rbx
  const char *v7; // rdx
  char i; // al
  UFG::qReflectSchema *v9; // rbp
  UFG::qReflectSchema *result; // rax
  UFG::qMemoryPool *v11; // rcx
  UFG::allocator::free_link *v12; // rax
  UFG::qTree64Base::BaseNode *v13; // rdi
  UFG::allocator::free_link *v14; // rax
  UFG::qTree64Base::BaseNode **v15; // rax
  UFG::qMemoryPool *v16; // rcx
  UFG::allocator::free_link *v17; // rax
  UFG::allocator::free_link *v18; // rax
  UFG::qTree64Base::BaseNode **v19; // rax

  v3 = name;
  v4 = parent_schema;
  v5 = this;
  v6 = -1i64;
  if ( name )
  {
    v7 = name;
    for ( i = *name; *v7; i = *v7 )
    {
      v6 = (v6 >> 8) ^ sCrcTable64[(unsigned __int8)(v6 ^ i)];
      ++v7;
    }
  }
  if ( v4 )
  {
    v9 = (UFG::qReflectSchema *)((char *)v4 + 120);
    result = (UFG::qReflectSchema *)v9->mBaseNode.mChildren[0];
    while ( result != v9 )
    {
      if ( result->mBaseNode.mUID >= v6 )
      {
        if ( result->mBaseNode.mUID <= v6 )
          goto LABEL_12;
        result = (UFG::qReflectSchema *)result->mBaseNode.mChildren[0];
      }
      else
      {
        result = (UFG::qReflectSchema *)result->mBaseNode.mChildren[1];
      }
    }
    result = 0i64;
LABEL_12:
    if ( !result )
    {
      v11 = UFG::gMainMemoryPool;
      if ( !UFG::gMainMemoryPool )
      {
        UFG::InternalSetupMainMemoryPool((UFG *)UFG::gMainMemoryPool);
        v11 = UFG::gMainMemoryPool;
      }
      v12 = UFG::qMemoryPool::Allocate(v11, 0xB0ui64, "CreateSchema", 0i64, 1u);
      v13 = (UFG::qTree64Base::BaseNode *)v12;
      if ( v12 )
      {
        v12->mNext = 0i64;
        v12[1].mNext = v12;
        v12[2].mNext = v12;
        v12[3].mNext = v12;
        v12[4].mNext = v12;
        v12[5].mNext = v12;
        v14 = v12 + 8;
        v14->mNext = 0i64;
        v14[1].mNext = v14;
        v14[2].mNext = v14;
        v14[3].mNext = v14;
        v14[4].mNext = v14;
        v14[5].mNext = v14;
        v14[6].mNext = 0i64;
        v15 = &v13[2].mChildren[1];
        *v15 = 0i64;
        v15[1] = (UFG::qTree64Base::BaseNode *)v15;
        v15[2] = (UFG::qTree64Base::BaseNode *)v15;
        v15[3] = (UFG::qTree64Base::BaseNode *)v15;
        v15[4] = (UFG::qTree64Base::BaseNode *)v15;
        v15[5] = (UFG::qTree64Base::BaseNode *)v15;
        v15[6] = 0i64;
      }
      else
      {
        v13 = 0i64;
      }
LABEL_32:
      v13->mUID = v6;
      v13[1].mUID = (unsigned __int64)UFG::ReflectionDB::AddString(v5, v3);
      v13[1].mParent = (UFG::qTree64Base::BaseNode *)v6;
      UFG::qTree64Base::Add((UFG::qTree64Base *)v9, v13);
      return (UFG::qReflectSchema *)v13;
    }
  }
  else
  {
    v9 = (UFG::qReflectSchema *)&this->mSchemas;
    result = (UFG::qReflectSchema *)this->mSchemas.mTree.mHead.mChildren[0];
    if ( result != (UFG::qReflectSchema *)&this->mSchemas )
    {
      do
      {
        if ( result->mBaseNode.mUID >= v6 )
        {
          if ( result->mBaseNode.mUID <= v6 )
            goto LABEL_26;
          result = (UFG::qReflectSchema *)result->mBaseNode.mChildren[0];
        }
        else
        {
          result = (UFG::qReflectSchema *)result->mBaseNode.mChildren[1];
        }
      }
      while ( result != v9 );
    }
    result = 0i64;
LABEL_26:
    if ( !result )
    {
      v16 = UFG::gMainMemoryPool;
      if ( !UFG::gMainMemoryPool )
      {
        UFG::InternalSetupMainMemoryPool((UFG *)UFG::gMainMemoryPool);
        v16 = UFG::gMainMemoryPool;
      }
      v17 = UFG::qMemoryPool::Allocate(v16, 0xB0ui64, "CreateSchema", 0i64, 1u);
      v13 = (UFG::qTree64Base::BaseNode *)v17;
      if ( v17 )
      {
        v17->mNext = 0i64;
        v17[1].mNext = v17;
        v17[2].mNext = v17;
        v17[3].mNext = v17;
        v17[4].mNext = v17;
        v17[5].mNext = v17;
        v18 = v17 + 8;
        v18->mNext = 0i64;
        v18[1].mNext = v18;
        v18[2].mNext = v18;
        v18[3].mNext = v18;
        v18[4].mNext = v18;
        v18[5].mNext = v18;
        v18[6].mNext = 0i64;
        v19 = &v13[2].mChildren[1];
        *v19 = 0i64;
        v19[1] = (UFG::qTree64Base::BaseNode *)v19;
        v19[2] = (UFG::qTree64Base::BaseNode *)v19;
        v19[3] = (UFG::qTree64Base::BaseNode *)v19;
        v19[4] = (UFG::qTree64Base::BaseNode *)v19;
        v19[5] = (UFG::qTree64Base::BaseNode *)v19;
        v19[6] = 0i64;
      }
      else
      {
        v13 = 0i64;
      }
      goto LABEL_32;
    }
  }
  return result;
}

// File Line: 383
// RVA: 0x16AD80
UFG::qReflectAnnotation *__fastcall UFG::ReflectionDB::CreateAnnotation(UFG::ReflectionDB *this, UFG::qReflectSchema *schema_type, const char *name, const char *value)
{
  const char *v4; // r14
  const char *v5; // r15
  UFG::qReflectSchema *v6; // rbp
  UFG::ReflectionDB *v7; // r12
  unsigned __int64 v8; // rsi
  unsigned __int64 v9; // rdi
  const char *v10; // rdx
  char i; // al
  const char *v12; // rdx
  char j; // al
  UFG::qReflectAnnotation *v14; // rbp
  UFG::qReflectAnnotation *result; // rax
  UFG::qMemoryPool *v16; // rcx
  UFG::allocator::free_link *v17; // rax
  UFG::qReflectAnnotation *v18; // rbx

  v4 = value;
  v5 = name;
  v6 = schema_type;
  v7 = this;
  v8 = -1i64;
  v9 = -1i64;
  if ( name )
  {
    v10 = name;
    for ( i = *name; *v10; i = *v10 )
    {
      v9 = (v9 >> 8) ^ sCrcTable64[(unsigned __int8)(v9 ^ i)];
      ++v10;
    }
  }
  if ( value )
  {
    v12 = value;
    for ( j = *value; *v12; j = *v12 )
    {
      v8 = (v8 >> 8) ^ sCrcTable64[(unsigned __int8)(v8 ^ j)];
      ++v12;
    }
  }
  v14 = (UFG::qReflectAnnotation *)&v6->mAnnotations;
  result = (UFG::qReflectAnnotation *)v14->mBaseNode.mChildren[0];
  while ( result != v14 )
  {
    if ( result->mBaseNode.mUID >= v9 )
    {
      if ( result->mBaseNode.mUID <= v9 )
        goto LABEL_14;
      result = (UFG::qReflectAnnotation *)result->mBaseNode.mChildren[0];
    }
    else
    {
      result = (UFG::qReflectAnnotation *)result->mBaseNode.mChildren[1];
    }
  }
  result = 0i64;
LABEL_14:
  if ( !result )
  {
    v16 = UFG::gMainMemoryPool;
    if ( !UFG::gMainMemoryPool )
    {
      UFG::InternalSetupMainMemoryPool((UFG *)UFG::gMainMemoryPool);
      v16 = UFG::gMainMemoryPool;
    }
    v17 = UFG::qMemoryPool::Allocate(v16, 0x50ui64, "CreateAnnotation", 0i64, 1u);
    v18 = (UFG::qReflectAnnotation *)v17;
    if ( v17 )
    {
      v17->mNext = 0i64;
      v17[1].mNext = v17;
      v17[2].mNext = v17;
      v17[3].mNext = v17;
      v17[4].mNext = v17;
      v17[5].mNext = v17;
    }
    else
    {
      v18 = 0i64;
    }
    v18->mBaseNode.mUID = v9;
    v18->mName = UFG::ReflectionDB::AddString(v7, v5);
    v18->mValue = UFG::ReflectionDB::AddString(v7, v4);
    v18->mNameUID = v9;
    v18->mValueUID = v8;
    UFG::qTree64Base::Add((UFG::qTree64Base *)v14, &v18->mBaseNode);
    result = v18;
  }
  return result;
}

// File Line: 453
// RVA: 0x17F4E0
void __fastcall UFG::ReflectionDB::ValidateClassSizes(UFG::ReflectionDB *this)
{
  UFG::qTree64<UFG::qReflectType,UFG::qReflectType,0> *v1; // rsi
  UFG::qTree64Base::BaseNode *v2; // rbx
  UFG::qTree64Base::BaseNode *i; // rax
  UFG::qTree64Base::BaseNode *v4; // rdx
  UFG::qReflectWarehouse *v5; // rax
  __int64 *v6; // rdi
  UFG::qTree64Base::BaseNode *v7; // rax
  UFG::qTree64<UFG::qReflectType,UFG::qReflectType,0> *v8; // rcx
  UFG::qTree64<UFG::qReflectType,UFG::qReflectType,0> *j; // rax
  UFG::qTree64Base::BaseNode **v10; // rax
  __int64 v11[2]; // [rsp+20h] [rbp-28h]

  v1 = &this->mTypes;
  v2 = this->mTypes.mTree.mHead.mChildren[0];
  if ( v2 == (UFG::qTree64Base::BaseNode *)&this->mTypes )
  {
    v2 = 0i64;
  }
  else
  {
    for ( i = v2->mChildren[0]; i != (UFG::qTree64Base::BaseNode *)v1; i = i->mChildren[0] )
      v2 = i;
  }
  while ( v2 )
  {
    if ( !(_S12 & 1) )
    {
      _S12 |= 1u;
      sReflectWarehouse.mInventoryTree.mTree.mHead.mUID = 0i64;
      sReflectWarehouse.mInventoryTree.mTree.mHead.mParent = (UFG::qTree64Base::BaseNode *)&sReflectWarehouse;
      sReflectWarehouse.mInventoryTree.mTree.mHead.mChildren[0] = (UFG::qTree64Base::BaseNode *)&sReflectWarehouse;
      sReflectWarehouse.mInventoryTree.mTree.mHead.mChildren[1] = (UFG::qTree64Base::BaseNode *)&sReflectWarehouse;
      sReflectWarehouse.mInventoryTree.mTree.mHead.mNeighbours[0] = (UFG::qTree64Base::BaseNode *)&sReflectWarehouse;
      sReflectWarehouse.mInventoryTree.mTree.mHead.mNeighbours[1] = (UFG::qTree64Base::BaseNode *)&sReflectWarehouse;
      sReflectWarehouse.mInventoryTree.mTree.mCount = 0i64;
      atexit(UFG::qReflectWarehouse::Instance_::_2_::_dynamic_atexit_destructor_for__sReflectWarehouse__);
    }
    v4 = v2[1].mChildren[1];
    v5 = (UFG::qReflectWarehouse *)sReflectWarehouse.mInventoryTree.mTree.mHead.mChildren[0];
    while ( v5 != &sReflectWarehouse )
    {
      if ( v5->mInventoryTree.mTree.mHead.mUID >= (unsigned __int64)v4 )
      {
        if ( v5->mInventoryTree.mTree.mHead.mUID <= (unsigned __int64)v4 )
        {
          v6 = &v5[-1].mInventoryTree.mTree.mCount;
          if ( v5 != (UFG::qReflectWarehouse *)8
            && v2[1].mNeighbours[0] != (UFG::qTree64Base::BaseNode *)(*(unsigned int (__fastcall **)(__int64 *))*v6)(v6) )
          {
            LODWORD(v11[0]) = (*(__int64 (__fastcall **)(__int64 *))*v6)(v6);
            UFG::qPrintf(
              "%s : error type %s size differs from the reflection database.  Size in Database %d, Size in Memory %d\n",
              v2[1].mParent,
              v2[1].mUID,
              LODWORD(v2[1].mNeighbours[0]),
              v11[0]);
          }
          break;
        }
        v5 = (UFG::qReflectWarehouse *)v5->mInventoryTree.mTree.mHead.mChildren[0];
      }
      else
      {
        v5 = (UFG::qReflectWarehouse *)v5->mInventoryTree.mTree.mHead.mChildren[1];
      }
    }
    v2 = v2->mNeighbours[1];
    v7 = v2->mParent;
    if ( (_QWORD)v2->mParent & 0xFFFFFFFFFFFFFFFCui64 )
    {
      v8 = (UFG::qTree64<UFG::qReflectType,UFG::qReflectType,0> *)v2->mChildren[1];
      if ( v8 == (UFG::qTree64<UFG::qReflectType,UFG::qReflectType,0> *)v8->mTree.mHead.mChildren[1] )
      {
        v8 = (UFG::qTree64<UFG::qReflectType,UFG::qReflectType,0> *)((_QWORD)v2->mParent & 0xFFFFFFFFFFFFFFFCui64);
        if ( ((unsigned __int8)v7 >> 1) & 1 )
        {
          do
          {
            v10 = &v8->mTree.mHead.mParent;
            v8 = (UFG::qTree64<UFG::qReflectType,UFG::qReflectType,0> *)((_QWORD)v8->mTree.mHead.mParent & 0xFFFFFFFFFFFFFFFCui64);
          }
          while ( ((unsigned __int8)*(_DWORD *)v10 >> 1) & 1 );
        }
      }
      else
      {
        for ( j = (UFG::qTree64<UFG::qReflectType,UFG::qReflectType,0> *)v8->mTree.mHead.mChildren[0];
              j != (UFG::qTree64<UFG::qReflectType,UFG::qReflectType,0> *)j->mTree.mHead.mChildren[1];
              j = (UFG::qTree64<UFG::qReflectType,UFG::qReflectType,0> *)j->mTree.mHead.mChildren[0] )
        {
          v8 = j;
        }
      }
      v2 = 0i64;
      if ( v8 != v1 )
        v2 = &v8->mTree.mHead;
    }
  }
}

// File Line: 471
// RVA: 0x1797C0
UFG::qReflectSchema *__fastcall UFG::ReflectionDB::ReadSchema(UFG::ReflectionDB *this, UFG::qReflectSchema *parent_schema, char **data_ptr)
{
  UFG::ReflectionDB *v3; // rbx
  char **v4; // rbp
  unsigned __int64 v5; // r9
  __int64 v6; // rsi
  UFG::ReflectionDB *v7; // rax
  const char *v8; // r8
  UFG::qReflectSchema *v9; // rdi
  unsigned __int64 v10; // r8
  unsigned __int64 v11; // r9
  UFG::ReflectionDB *v12; // rdx
  UFG::ReflectionDB *v13; // rcx
  const char *v14; // r8
  const char *v15; // r9
  __int64 v17; // [rsp+30h] [rbp+8h]

  v3 = this;
  v4 = data_ptr;
  v5 = *(_QWORD *)*data_ptr;
  v6 = *((_QWORD *)*data_ptr + 2);
  v17 = *((_QWORD *)*data_ptr + 1);
  *data_ptr += 24;
  v7 = (UFG::ReflectionDB *)this->mStrings.mTree.mHead.mChildren[0];
  while ( v7 != this )
  {
    if ( v7->mStrings.mTree.mHead.mUID >= v5 )
    {
      if ( v7->mStrings.mTree.mHead.mUID <= v5 )
        goto LABEL_8;
      v7 = (UFG::ReflectionDB *)v7->mStrings.mTree.mHead.mChildren[0];
    }
    else
    {
      v7 = (UFG::ReflectionDB *)v7->mStrings.mTree.mHead.mChildren[1];
    }
  }
  v7 = 0i64;
LABEL_8:
  v8 = 0i64;
  if ( v7 )
    v8 = (const char *)v7->mStrings.mTree.mCount;
  v9 = UFG::ReflectionDB::CreateSchema(this, parent_schema, v8);
  if ( v17 > 0 )
  {
    do
    {
      v10 = *(_QWORD *)*v4;
      v11 = *((_QWORD *)*v4 + 1);
      *v4 += 16;
      v12 = (UFG::ReflectionDB *)v3->mStrings.mTree.mHead.mChildren[0];
      v13 = v12;
      while ( v13 != v3 )
      {
        if ( v13->mStrings.mTree.mHead.mUID >= v10 )
        {
          if ( v13->mStrings.mTree.mHead.mUID <= v10 )
            goto LABEL_18;
          v13 = (UFG::ReflectionDB *)v13->mStrings.mTree.mHead.mChildren[0];
        }
        else
        {
          v13 = (UFG::ReflectionDB *)v13->mStrings.mTree.mHead.mChildren[1];
        }
      }
      v13 = 0i64;
LABEL_18:
      v14 = 0i64;
      if ( v13 )
        v14 = (const char *)v13->mStrings.mTree.mCount;
      while ( v12 != v3 )
      {
        if ( v12->mStrings.mTree.mHead.mUID >= v11 )
        {
          if ( v12->mStrings.mTree.mHead.mUID <= v11 )
            goto LABEL_27;
          v12 = (UFG::ReflectionDB *)v12->mStrings.mTree.mHead.mChildren[0];
        }
        else
        {
          v12 = (UFG::ReflectionDB *)v12->mStrings.mTree.mHead.mChildren[1];
        }
      }
      v12 = 0i64;
LABEL_27:
      v15 = 0i64;
      if ( v12 )
        v15 = (const char *)v12->mStrings.mTree.mCount;
      UFG::ReflectionDB::CreateAnnotation(v3, v9, v14, v15);
      --v17;
    }
    while ( v17 );
  }
  if ( v6 > 0 )
  {
    do
    {
      UFG::ReflectionDB::ReadSchema(v3, v9, v4);
      --v6;
    }
    while ( v6 );
  }
  return v9;
}

// File Line: 498
// RVA: 0x176470
char __fastcall UFG::ReflectionDB::Load(UFG::ReflectionDB *this, const char *filename)
{
  const char *v2; // rbx
  UFG::ReflectionDB *v3; // rdi
  __int64 v4; // rbp
  UFG::qMemoryPool *v5; // r14
  UFG::qFile *v6; // rsi
  UFG::allocator::free_link *v7; // rax
  UFG::allocator::free_link *v8; // r15
  char *v10; // r14
  int v11; // eax
  signed __int64 v12; // rcx
  unsigned __int64 v13; // rsi
  unsigned __int64 v14; // rdx
  unsigned __int64 v15; // rbp
  unsigned int v16; // er14
  unsigned int flags; // er15
  unsigned __int64 checksum; // r12
  UFG::qTree64<UFG::qReflectType,UFG::qReflectType,0> *v19; // rax
  unsigned __int64 v20; // r13
  UFG::ReflectionDB *v21; // rbx
  UFG::ReflectionDB *v22; // rax
  UFG::qReflectType *v23; // rax
  unsigned __int64 v24; // rbp
  UFG::qReflectType *k; // rsi
  UFG::ReflectionDB *v26; // rcx
  unsigned __int64 v27; // r8
  unsigned __int64 v28; // r9
  UFG::ReflectionDB *v29; // rax
  const char *v30; // r8
  const char *v31; // r9
  const char *v32; // rbx
  const char *j; // rsi
  int v34; // ecx
  const char *v35; // rcx
  char v36; // al
  UFG::qTree64<UFG::qReflectEnum,UFG::qReflectEnum,0> *v37; // rax
  char *v38; // rcx
  char *v39; // rbp
  unsigned __int64 v40; // rdx
  unsigned __int64 *v41; // rbx
  UFG::ReflectionDB *v42; // rax
  const char *v43; // rdx
  UFG::qTree64<UFG::qReflectEnum,UFG::qReflectEnum,0> *i; // rsi
  UFG::ReflectionDB *v45; // rax
  unsigned __int64 v46; // rdx
  const char *v47; // r8
  UFG::allocator::free_link *v48; // [rsp+40h] [rbp-1C8h]
  char *v49; // [rsp+48h] [rbp-1C0h]
  char dest; // [rsp+50h] [rbp-1B8h]
  char *data_ptr; // [rsp+220h] [rbp+18h]
  unsigned __int64 v52; // [rsp+228h] [rbp+20h]

  v2 = filename;
  v3 = this;
  if ( unk_14235ACD8 )
    goto LABEL_8;
  if ( !filename )
    goto LABEL_8;
  if ( !*filename )
    goto LABEL_8;
  v4 = UFG::qGetFileSize(filename);
  if ( v4 <= 0 )
    goto LABEL_8;
  v5 = UFG::gMainMemoryPool;
  v6 = UFG::qOpen(v2, QACCESS_READ, 1);
  if ( !v6 )
    goto LABEL_8;
  UFG::qSPrintf(&dest, "qReadEntireFile(%s)", v2);
  v7 = UFG::qMemoryPool::Allocate(v5, v4 + 1, &dest, 0i64, 1u);
  v8 = v7;
  v48 = v7;
  if ( !v7 )
  {
    UFG::qClose(v6);
LABEL_8:
    UFG::qPrintf("ERROR: Could not load ReflectionDB.  File not found!  filename = %s\n", v2);
    return 0;
  }
  if ( (signed int)UFG::qRead(v6, v7, v4, 0i64, QSEEK_CUR) != v4 )
  {
    UFG::qClose(v6);
    UFG::qMemoryPool::Free(v5, v8);
    goto LABEL_8;
  }
  UFG::qClose(v6);
  v10 = (char *)v8;
  *((_BYTE *)&v8->mNext + v4) = 0;
  v49 = (char *)v8 + v4;
  data_ptr = (char *)v8;
  if ( v8 < (UFG::allocator::free_link *)((char *)v8 + v4) )
  {
    do
    {
      v11 = *(_DWORD *)v10;
      if ( *(_DWORD *)v10 == 735085971 )
      {
        v37 = (UFG::qTree64<UFG::qReflectEnum,UFG::qReflectEnum,0> *)v3->mEnums.mTree.mHead.mChildren[0];
        v38 = &v10[*((unsigned int *)v10 + 3) + 16];
        v39 = &v38[*((unsigned int *)v10 + 2)];
        v40 = *(_QWORD *)v38;
        v41 = (unsigned __int64 *)(v38 + 8);
        while ( v37 != &v3->mEnums )
        {
          if ( v37->mTree.mHead.mUID >= v40 )
          {
            if ( v37->mTree.mHead.mUID <= v40 )
              goto LABEL_43;
            v37 = (UFG::qTree64<UFG::qReflectEnum,UFG::qReflectEnum,0> *)v37->mTree.mHead.mChildren[0];
          }
          else
          {
            v37 = (UFG::qTree64<UFG::qReflectEnum,UFG::qReflectEnum,0> *)v37->mTree.mHead.mChildren[1];
          }
        }
        v42 = (UFG::ReflectionDB *)v3->mStrings.mTree.mHead.mChildren[0];
        while ( v42 != v3 )
        {
          if ( v42->mStrings.mTree.mHead.mUID >= v40 )
          {
            if ( v42->mStrings.mTree.mHead.mUID <= v40 )
              goto LABEL_68;
            v42 = (UFG::ReflectionDB *)v42->mStrings.mTree.mHead.mChildren[0];
          }
          else
          {
            v42 = (UFG::ReflectionDB *)v42->mStrings.mTree.mHead.mChildren[1];
          }
        }
        v42 = 0i64;
LABEL_68:
        v43 = 0i64;
        if ( v42 )
          v43 = (const char *)v42->mStrings.mTree.mCount;
        for ( i = UFG::ReflectionDB::CreateEnum(v3, v43); v41 < (unsigned __int64 *)v39; v41 += 2 )
        {
          v45 = (UFG::ReflectionDB *)v3->mStrings.mTree.mHead.mChildren[0];
          v46 = *v41;
          while ( v45 != v3 )
          {
            if ( v45->mStrings.mTree.mHead.mUID >= v46 )
            {
              if ( v45->mStrings.mTree.mHead.mUID <= v46 )
                goto LABEL_78;
              v45 = (UFG::ReflectionDB *)v45->mStrings.mTree.mHead.mChildren[0];
            }
            else
            {
              v45 = (UFG::ReflectionDB *)v45->mStrings.mTree.mHead.mChildren[1];
            }
          }
          v45 = 0i64;
LABEL_78:
          v47 = 0i64;
          if ( v45 )
            v47 = (const char *)v45->mStrings.mTree.mCount;
          UFG::ReflectionDB::AddEnumValue(v3, (UFG::qReflectEnum *)i, v47, v41[1]);
        }
      }
      else
      {
        switch ( v11 )
        {
          case 1473657222:
            data_ptr = &v10[*((unsigned int *)v10 + 3) + 16];
            UFG::ReflectionDB::ReadSchema(v3, 0i64, &data_ptr);
            break;
          case 1565686639:
            v32 = &v10[*((unsigned int *)v10 + 3) + 16];
            for ( j = &v32[*((unsigned int *)v10 + 2)]; v32 < j; v32 += v34 + 1 )
            {
              UFG::ReflectionDB::AddString(v3, v32);
              if ( v32 )
              {
                v35 = v32;
                do
                  v36 = *v35++;
                while ( v36 );
                v34 = (_DWORD)v35 - (_DWORD)v32 - 1;
              }
              else
              {
                v34 = 0;
              }
            }
            break;
          case -444625387:
            v12 = (signed __int64)&v10[*((unsigned int *)v10 + 3) + 16];
            v13 = *(_QWORD *)v12;
            v14 = *(_QWORD *)(v12 + 8);
            v15 = *(_QWORD *)(v12 + 16);
            v16 = *(_DWORD *)(v12 + 24);
            flags = *(_DWORD *)(v12 + 28);
            checksum = *(_QWORD *)(v12 + 32);
            v52 = v12 + *((unsigned int *)data_ptr + 2);
            v19 = (UFG::qTree64<UFG::qReflectType,UFG::qReflectType,0> *)v3->mTypes.mTree.mHead.mChildren[0];
            v20 = v12 + 40;
            while ( v19 != &v3->mTypes )
            {
              if ( v19->mTree.mHead.mUID >= v14 )
              {
                if ( v19->mTree.mHead.mUID <= v14 )
                  goto LABEL_42;
                v19 = (UFG::qTree64<UFG::qReflectType,UFG::qReflectType,0> *)v19->mTree.mHead.mChildren[0];
              }
              else
              {
                v19 = (UFG::qTree64<UFG::qReflectType,UFG::qReflectType,0> *)v19->mTree.mHead.mChildren[1];
              }
            }
            v21 = UFG::ReflectionDB::GetString(v3, v14);
            v22 = UFG::ReflectionDB::GetString(v3, v13);
            v23 = UFG::ReflectionDB::CreateType(v3, (const char *)v21, v15, v16, (const char *)v22, flags, checksum);
            v24 = v52;
            for ( k = v23; v20 < v24; v20 += 40i64 )
            {
              v26 = (UFG::ReflectionDB *)v3->mStrings.mTree.mHead.mChildren[0];
              v27 = *(_QWORD *)v20;
              v28 = *(_QWORD *)(v20 + 8);
              v29 = v26;
              while ( v29 != v3 )
              {
                if ( v29->mStrings.mTree.mHead.mUID >= v27 )
                {
                  if ( v29->mStrings.mTree.mHead.mUID <= v27 )
                    goto LABEL_30;
                  v29 = (UFG::ReflectionDB *)v29->mStrings.mTree.mHead.mChildren[0];
                }
                else
                {
                  v29 = (UFG::ReflectionDB *)v29->mStrings.mTree.mHead.mChildren[1];
                }
              }
              v29 = 0i64;
LABEL_30:
              v30 = 0i64;
              if ( v29 )
                v30 = (const char *)v29->mStrings.mTree.mCount;
              while ( v26 != v3 )
              {
                if ( v26->mStrings.mTree.mHead.mUID >= v28 )
                {
                  if ( v26->mStrings.mTree.mHead.mUID <= v28 )
                    goto LABEL_39;
                  v26 = (UFG::ReflectionDB *)v26->mStrings.mTree.mHead.mChildren[0];
                }
                else
                {
                  v26 = (UFG::ReflectionDB *)v26->mStrings.mTree.mHead.mChildren[1];
                }
              }
              v26 = 0i64;
LABEL_39:
              v31 = 0i64;
              if ( v26 )
                v31 = (const char *)v26->mStrings.mTree.mCount;
              UFG::ReflectionDB::AddField(
                v3,
                k,
                v30,
                v31,
                *(_QWORD *)(v20 + 16),
                *(_QWORD *)(v20 + 24),
                *(_DWORD *)(v20 + 32));
            }
LABEL_42:
            v10 = data_ptr;
            break;
        }
      }
LABEL_43:
      v10 += ((*((_DWORD *)v10 + 1) + 3) & 0xFFFFFFFC) + 16;
      data_ptr = v10;
    }
    while ( v10 < v49 );
    v8 = v48;
  }
  UFG::qMemoryPool::Free(UFG::gMainMemoryPool, v8);
  return 1;
}

