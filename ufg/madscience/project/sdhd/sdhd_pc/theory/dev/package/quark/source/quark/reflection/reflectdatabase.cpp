// File Line: 38
// RVA: 0x161A60
void __fastcall UFG::qReflectionString::qReflectionString(
        UFG::qReflectionString *this,
        unsigned __int64 uid,
        const char *text)
{
  int v3; // ebp
  const char *v6; // rax
  UFG::qMemoryPool *v8; // rcx
  char *v9; // rax

  this->mBaseNode.mParent = &this->mBaseNode;
  v3 = 0;
  this->mBaseNode.mUID = 0i64;
  this->mBaseNode.mChildren[0] = &this->mBaseNode;
  this->mBaseNode.mChildren[1] = &this->mBaseNode;
  this->mBaseNode.mNeighbours[0] = &this->mBaseNode;
  this->mBaseNode.mNeighbours[1] = &this->mBaseNode;
  if ( text )
  {
    v6 = text;
    while ( *v6++ )
      ;
    v3 = (_DWORD)v6 - (_DWORD)text - 1;
  }
  this->mBaseNode.mUID = uid;
  v8 = UFG::gMainMemoryPool;
  if ( !UFG::gMainMemoryPool )
  {
    UFG::InternalSetupMainMemoryPool((UFG *)UFG::gMainMemoryPool);
    v8 = UFG::gMainMemoryPool;
  }
  v9 = UFG::qMemoryPool::Allocate(v8, v3 + 1, "qReflectionString", 0i64, 1u);
  this->mText = v9;
  UFG::qStringCopy(v9, v3 + 1, text, v3);
}

// File Line: 93
// RVA: 0x173E00
UFG::ReflectionDB *__fastcall UFG::ReflectionDB::Instance()
{
  UFG::ReflectionDB *result; // rax

  if ( (_S11 & 1) != 0 )
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
  unsigned __int64 v4; // rbx
  char i; // al
  UFG::ReflectionDB *v6; // rax
  UFG::qTree64Base::BaseNode *v7; // rsi
  UFG::qMemoryPool *v8; // rcx
  char *v9; // rax
  UFG::qTree64Base::BaseNode *v10; // rax

  v2 = text;
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
  UFG::qTree64Base::Add(&this->mStrings.mTree, v7);
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
    return (UFG::ReflectionDB *)result->mStrings.mTree.mCount;
  return result;
}

// File Line: 164
// RVA: 0x172C10
UFG::qTree64<UFG::qReflectType,UFG::qReflectType,0> *__fastcall UFG::ReflectionDB::GetType(
        UFG::ReflectionDB *this,
        const char *type_name)
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
UFG::qTree64<UFG::qReflectType,UFG::qReflectType,0> *__fastcall UFG::ReflectionDB::GetType(
        UFG::ReflectionDB *this,
        unsigned __int64 type_uid)
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
UFG::qTree64<UFG::qReflectEnum,UFG::qReflectEnum,0> *__fastcall UFG::ReflectionDB::GetEnum(
        UFG::ReflectionDB *this,
        const char *type_name)
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
UFG::qTree64<UFG::qReflectSchema,UFG::qReflectSchema,0> *__fastcall UFG::ReflectionDB::GetSchema(
        UFG::ReflectionDB *this,
        unsigned __int64 type_uid)
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
char __fastcall UFG::ReflectionDB::IsDerivedFrom(
        UFG::ReflectionDB *this,
        unsigned __int64 type_uid,
        unsigned __int64 base_class_uid)
{
  UFG::ReflectionDB *v3; // rax
  unsigned __int64 mUID; // rbx
  __int64 *p_mCount; // rdi
  unsigned __int64 v9; // rdx

  v3 = (UFG::ReflectionDB *)this->mTypes.mTree.mHead.mChildren[0];
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
  mUID = v3->mSchemas.mTree.mHead.mUID;
  p_mCount = &v3->mEnums.mTree.mCount;
  if ( (__int64 *)mUID == &v3->mEnums.mTree.mCount )
    return 0;
  while ( 1 )
  {
    if ( (*(_BYTE *)(mUID + 112) & 2) != 0 )
    {
      v9 = *(_QWORD *)(mUID + 88);
      if ( v9 == base_class_uid || UFG::ReflectionDB::IsDerivedFrom(this, v9, base_class_uid) )
        break;
    }
    mUID = *(_QWORD *)(mUID + 8);
    if ( (__int64 *)mUID == p_mCount )
      return 0;
  }
  return 1;
}

// File Line: 235
// RVA: 0x17ECC0
bool __fastcall UFG::ReflectionDB::TryGetEnumStrings(
        UFG::ReflectionDB *this,
        const char *type_name,
        UFG::qList<UFG::qString,UFG::qString,1,0> *strings)
{
  UFG::qTree64<UFG::qReflectEnum,UFG::qReflectEnum,0> *Enum; // rax
  UFG::qTree64<UFG::qReflectEnum,UFG::qReflectEnum,0> *v5; // r15
  UFG::qTree64Base::BaseNode *v6; // rbx
  UFG::qTree64Base::BaseNode **i; // r14
  const char *v8; // rbp
  UFG::qMemoryPool *v9; // rcx
  UFG::qString *v10; // rax
  UFG::qNode<UFG::qString,UFG::qString> *v11; // rax
  UFG::qNode<UFG::qString,UFG::qString> *mPrev; // rcx

  Enum = UFG::ReflectionDB::GetEnum(this, type_name);
  v5 = Enum;
  if ( Enum )
  {
    v6 = Enum[1].mTree.mHead.mChildren[0];
    for ( i = &Enum[1].mTree.mHead.mParent; v6 != (UFG::qTree64Base::BaseNode *)i; v6 = v6->mParent )
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
      mPrev = strings->mNode.mPrev;
      mPrev->mNext = v11;
      v11->mPrev = mPrev;
      v11->mNext = &strings->mNode;
      strings->mNode.mPrev = v11;
    }
  }
  return v5 != 0i64;
}

// File Line: 250
// RVA: 0x16B460
UFG::qTree64<UFG::qReflectType,UFG::qReflectType,0> *__fastcall UFG::ReflectionDB::CreateType(
        UFG::ReflectionDB *this,
        const char *type_name,
        UFG::allocator::free_link *num_bytes,
        unsigned int alignment,
        const char *declaration_location,
        unsigned int flags,
        UFG::allocator::free_link *checksum)
{
  const char *v9; // r14
  unsigned __int64 v11; // rsi
  unsigned __int64 v12; // rdi
  char i; // al
  UFG::qTree64<UFG::qReflectType,UFG::qReflectType,0> *result; // rax
  UFG::qMemoryPool *v15; // rcx
  UFG::allocator::free_link *v16; // rax
  UFG::allocator::free_link *v17; // rbx
  UFG::allocator::free_link *v18; // rax
  const char *v19; // rdi
  unsigned __int64 v20; // rdx
  char v21; // al
  char j; // al

  v9 = type_name;
  v11 = -1i64;
  v12 = -1i64;
  if ( type_name )
  {
    for ( i = *type_name; *type_name; i = *type_name )
    {
      v12 = (v12 >> 8) ^ sCrcTable64[(unsigned __int8)(v12 ^ i)];
      ++type_name;
    }
  }
  result = (UFG::qTree64<UFG::qReflectType,UFG::qReflectType,0> *)this->mTypes.mTree.mHead.mChildren[0];
  while ( result != &this->mTypes )
  {
    if ( result->mTree.mHead.mUID >= v12 )
    {
      if ( result->mTree.mHead.mUID <= v12 )
        goto LABEL_11;
      result = (UFG::qTree64<UFG::qReflectType,UFG::qReflectType,0> *)result->mTree.mHead.mChildren[0];
    }
    else
    {
      result = (UFG::qTree64<UFG::qReflectType,UFG::qReflectType,0> *)result->mTree.mHead.mChildren[1];
    }
  }
  result = 0i64;
LABEL_11:
  if ( !result )
  {
    v15 = UFG::gMainMemoryPool;
    if ( !UFG::gMainMemoryPool )
    {
      UFG::InternalSetupMainMemoryPool((UFG *)UFG::gMainMemoryPool);
      v15 = UFG::gMainMemoryPool;
    }
    v16 = UFG::qMemoryPool::Allocate(v15, 0xB0ui64, "CreateType", 0i64, 1u);
    v17 = v16;
    if ( v16 )
    {
      v16->mNext = 0i64;
      v16[1].mNext = v16;
      v16[2].mNext = v16;
      v16[3].mNext = v16;
      v16[4].mNext = v16;
      v16[5].mNext = v16;
      v18 = v16 + 13;
      v18->mNext = 0i64;
      v18[1].mNext = v18;
      v18[2].mNext = v18;
      v18[3].mNext = v18;
      v18[4].mNext = v18;
      v18[5].mNext = v18;
      v18[6].mNext = 0i64;
      v17[20].mNext = v17 + 20;
      v17[21].mNext = v17 + 20;
    }
    else
    {
      v17 = 0i64;
    }
    v17->mNext = (UFG::allocator::free_link *)v12;
    v19 = declaration_location;
    v17[7].mNext = (UFG::allocator::free_link *)UFG::ReflectionDB::AddString(this, declaration_location);
    v20 = -1i64;
    if ( declaration_location )
    {
      v21 = *declaration_location;
      if ( *declaration_location )
      {
        do
        {
          v20 = (v20 >> 8) ^ sCrcTable64[(unsigned __int8)(v20 ^ v21)];
          v21 = *++v19;
        }
        while ( *v19 );
      }
    }
    v17[8].mNext = (UFG::allocator::free_link *)v20;
    v17[6].mNext = (UFG::allocator::free_link *)UFG::ReflectionDB::AddString(this, v9);
    if ( v9 )
    {
      for ( j = *v9; *v9; j = *v9 )
      {
        v11 = (v11 >> 8) ^ sCrcTable64[(unsigned __int8)(v11 ^ j)];
        ++v9;
      }
    }
    v17[9].mNext = (UFG::allocator::free_link *)v11;
    v17[10].mNext = num_bytes;
    LODWORD(v17[11].mNext) = alignment;
    HIDWORD(v17[11].mNext) = flags;
    v17[12].mNext = checksum;
    UFG::qTree64Base::Add(&this->mTypes.mTree, (UFG::qTree64Base::BaseNode *)v17);
    return (UFG::qTree64<UFG::qReflectType,UFG::qReflectType,0> *)v17;
  }
  return result;
}

// File Line: 278
// RVA: 0x166140
UFG::qList<UFG::qReflectField,UFG::qReflectField,1,0> *__fastcall UFG::ReflectionDB::AddField(
        UFG::ReflectionDB *this,
        UFG::qReflectType *type,
        const char *field_name,
        const char *field_type_name,
        unsigned __int64 byte_offset,
        unsigned __int64 array_length,
        unsigned int flags)
{
  unsigned __int64 v11; // rsi
  unsigned __int64 v12; // rbx
  const char *v13; // rdx
  char i; // al
  UFG::qTree64<UFG::qReflectField,UFG::qReflectField,0> *p_mFields; // rbp
  UFG::qReflectType *v16; // rax
  UFG::qList<UFG::qReflectField,UFG::qReflectField,1,0> *result; // rax
  UFG::qMemoryPool *v18; // rcx
  char *v19; // rax
  char *v20; // rdi
  _QWORD *v21; // rax
  unsigned __int64 v22; // rdx
  char j; // al
  char k; // al
  UFG::qNode<UFG::qReflectField,UFG::qReflectField> *mPrev; // rcx

  v11 = -1i64;
  v12 = -1i64;
  if ( field_name )
  {
    v13 = field_name;
    for ( i = *field_name; *v13; i = *v13 )
    {
      v12 = (v12 >> 8) ^ sCrcTable64[(unsigned __int8)(v12 ^ i)];
      ++v13;
    }
  }
  p_mFields = &type->mFields;
  v16 = (UFG::qReflectType *)type->mFields.mTree.mHead.mChildren[0];
  if ( v16 == (UFG::qReflectType *)&type->mFields )
    goto LABEL_13;
  while ( v16->mBaseNode.mUID < v12 )
  {
    v16 = (UFG::qReflectType *)v16->mBaseNode.mChildren[1];
LABEL_9:
    if ( v16 == (UFG::qReflectType *)p_mFields )
      goto LABEL_13;
  }
  if ( v16->mBaseNode.mUID > v12 )
  {
    v16 = (UFG::qReflectType *)v16->mBaseNode.mChildren[0];
    goto LABEL_9;
  }
  result = &v16[-1].mOrderedFields;
  if ( result )
  {
    LODWORD(result[7].mNode.mPrev) |= flags;
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
  *((_QWORD *)v20 + 8) = UFG::ReflectionDB::AddString(this, field_name);
  v22 = -1i64;
  if ( field_name )
  {
    for ( j = *field_name; *field_name; j = *field_name )
    {
      v22 = (v22 >> 8) ^ sCrcTable64[(unsigned __int8)(v22 ^ j)];
      ++field_name;
    }
  }
  *((_QWORD *)v20 + 10) = v22;
  *((_QWORD *)v20 + 9) = UFG::ReflectionDB::AddString(this, field_type_name);
  if ( field_type_name )
  {
    for ( k = *field_type_name; *field_type_name; k = *field_type_name )
    {
      v11 = (v11 >> 8) ^ sCrcTable64[(unsigned __int8)(v11 ^ k)];
      ++field_type_name;
    }
  }
  *((_QWORD *)v20 + 11) = v11;
  *((_QWORD *)v20 + 12) = byte_offset;
  *((_QWORD *)v20 + 13) = array_length;
  *((_DWORD *)v20 + 28) = flags;
  UFG::qTree64Base::Add(&p_mFields->mTree, (UFG::qTree64Base::BaseNode *)(v20 + 16));
  mPrev = type->mOrderedFields.mNode.mPrev;
  mPrev->mNext = (UFG::qNode<UFG::qReflectField,UFG::qReflectField> *)v20;
  *(_QWORD *)v20 = mPrev;
  *((_QWORD *)v20 + 1) = &type->mOrderedFields;
  type->mOrderedFields.mNode.mPrev = (UFG::qNode<UFG::qReflectField,UFG::qReflectField> *)v20;
  return (UFG::qList<UFG::qReflectField,UFG::qReflectField,1,0> *)v20;
}

// File Line: 308
// RVA: 0x16AF10
UFG::qTree64<UFG::qReflectEnum,UFG::qReflectEnum,0> *__fastcall UFG::ReflectionDB::CreateEnum(
        UFG::ReflectionDB *this,
        const char *type_name)
{
  const char *v2; // r14
  unsigned __int64 v4; // rbx
  char i; // al
  UFG::qTree64<UFG::qReflectEnum,UFG::qReflectEnum,0> *result; // rax
  UFG::qMemoryPool *v7; // rcx
  UFG::allocator::free_link *v8; // rax
  UFG::qTree64Base::BaseNode *v9; // rdi

  v2 = type_name;
  v4 = -1i64;
  if ( type_name )
  {
    for ( i = *type_name; *type_name; i = *type_name )
    {
      v4 = (v4 >> 8) ^ sCrcTable64[(unsigned __int8)(v4 ^ i)];
      ++type_name;
    }
  }
  result = (UFG::qTree64<UFG::qReflectEnum,UFG::qReflectEnum,0> *)this->mEnums.mTree.mHead.mChildren[0];
  while ( result != &this->mEnums )
  {
    if ( result->mTree.mHead.mUID >= v4 )
    {
      if ( result->mTree.mHead.mUID <= v4 )
        goto LABEL_11;
      result = (UFG::qTree64<UFG::qReflectEnum,UFG::qReflectEnum,0> *)result->mTree.mHead.mChildren[0];
    }
    else
    {
      result = (UFG::qTree64<UFG::qReflectEnum,UFG::qReflectEnum,0> *)result->mTree.mHead.mChildren[1];
    }
  }
  result = 0i64;
LABEL_11:
  if ( !result )
  {
    v7 = UFG::gMainMemoryPool;
    if ( !UFG::gMainMemoryPool )
    {
      UFG::InternalSetupMainMemoryPool((UFG *)UFG::gMainMemoryPool);
      v7 = UFG::gMainMemoryPool;
    }
    v8 = UFG::qMemoryPool::Allocate(v7, 0x50ui64, "CreateEnum", 0i64, 1u);
    v9 = (UFG::qTree64Base::BaseNode *)v8;
    if ( v8 )
    {
      v8->mNext = 0i64;
      v8[1].mNext = v8;
      v8[2].mNext = v8;
      v8[3].mNext = v8;
      v8[4].mNext = v8;
      v8[5].mNext = v8;
      v8[8].mNext = v8 + 8;
      v8[9].mNext = v8 + 8;
    }
    else
    {
      v9 = 0i64;
    }
    v9->mUID = v4;
    v9[1].mUID = (unsigned __int64)UFG::ReflectionDB::AddString(this, v2);
    v9[1].mParent = (UFG::qTree64Base::BaseNode *)v4;
    UFG::qTree64Base::Add(&this->mEnums.mTree, v9);
    return (UFG::qTree64<UFG::qReflectEnum,UFG::qReflectEnum,0> *)v9;
  }
  return result;
}

// File Line: 323
// RVA: 0x166000
UFG::qReflectEnumValue *__fastcall UFG::ReflectionDB::AddEnumValue(
        UFG::ReflectionDB *this,
        UFG::qReflectEnum *enum_type,
        const char *value_name,
        __int64 value)
{
  unsigned __int64 v8; // rbx
  const char *v9; // rdx
  char i; // al
  UFG::qReflectEnumValue *result; // rax
  UFG::qReflectEnumValue *p_mValues; // rsi
  UFG::qMemoryPool *v13; // rcx
  char *v14; // rax
  char *v15; // rdi
  UFG::qNode<UFG::qReflectEnumValue,UFG::qReflectEnumValue> *mPrev; // rcx

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
  result = (UFG::qReflectEnumValue *)enum_type->mValues.mNode.mNext;
  p_mValues = (UFG::qReflectEnumValue *)&enum_type->mValues;
  if ( result == p_mValues )
  {
LABEL_7:
    v13 = UFG::gMainMemoryPool;
    if ( !UFG::gMainMemoryPool )
    {
      UFG::InternalSetupMainMemoryPool((UFG *)UFG::gMainMemoryPool);
      v13 = UFG::gMainMemoryPool;
    }
    v14 = UFG::qMemoryPool::Allocate(v13, 0x28ui64, "AddEnumValue", 0i64, 1u);
    v15 = v14;
    if ( v14 )
    {
      *(_QWORD *)v14 = v14;
      *((_QWORD *)v14 + 1) = v14;
    }
    else
    {
      v15 = 0i64;
    }
    *((_QWORD *)v15 + 2) = UFG::ReflectionDB::AddString(this, value_name);
    *((_QWORD *)v15 + 3) = v8;
    *((_QWORD *)v15 + 4) = value;
    mPrev = p_mValues->mPrev;
    mPrev->mNext = (UFG::qNode<UFG::qReflectEnumValue,UFG::qReflectEnumValue> *)v15;
    *(_QWORD *)v15 = mPrev;
    *((_QWORD *)v15 + 1) = p_mValues;
    p_mValues->mPrev = (UFG::qNode<UFG::qReflectEnumValue,UFG::qReflectEnumValue> *)v15;
    return (UFG::qReflectEnumValue *)v15;
  }
  else
  {
    while ( v8 != result->mNameUID )
    {
      result = (UFG::qReflectEnumValue *)result->mNext;
      if ( result == p_mValues )
        goto LABEL_7;
    }
  }
  return result;
}

// File Line: 352
// RVA: 0x16B200
UFG::qReflectSchema *__fastcall UFG::ReflectionDB::CreateSchema(
        UFG::ReflectionDB *this,
        UFG::qReflectSchema *parent_schema,
        const char *name)
{
  unsigned __int64 v6; // rbx
  const char *v7; // rdx
  char i; // al
  UFG::qReflectSchema *p_mSchemas; // rbp
  UFG::qReflectSchema *result; // rax
  UFG::qMemoryPool *v11; // rcx
  UFG::allocator::free_link *v12; // rax
  UFG::qTree64Base::BaseNode *v13; // rdi
  UFG::qMemoryPool *v14; // rcx
  UFG::allocator::free_link *v15; // rax

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
  if ( parent_schema )
  {
    p_mSchemas = (UFG::qReflectSchema *)&parent_schema->mSchemas;
    result = (UFG::qReflectSchema *)p_mSchemas->mBaseNode.mChildren[0];
    while ( result != p_mSchemas )
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
      if ( !v12 )
      {
        v13 = 0i64;
LABEL_30:
        v13->mUID = v6;
        v13[1].mUID = (unsigned __int64)UFG::ReflectionDB::AddString(this, name);
        v13[1].mParent = (UFG::qTree64Base::BaseNode *)v6;
        UFG::qTree64Base::Add((UFG::qTree64Base *)p_mSchemas, v13);
        return (UFG::qReflectSchema *)v13;
      }
LABEL_28:
      v12->mNext = 0i64;
      v12[1].mNext = v12;
      v12[2].mNext = v12;
      v12[3].mNext = v12;
      v12[4].mNext = v12;
      v12[5].mNext = v12;
      v15 = v12 + 8;
      v15->mNext = 0i64;
      v15[1].mNext = v15;
      v15[2].mNext = v15;
      v15[3].mNext = v15;
      v15[4].mNext = v15;
      v15[5].mNext = v15;
      v15[6].mNext = 0i64;
      v13[2].mChildren[1] = 0i64;
      v13[2].mNeighbours[0] = (UFG::qTree64Base::BaseNode *)((char *)v13 + 120);
      v13[2].mNeighbours[1] = (UFG::qTree64Base::BaseNode *)((char *)v13 + 120);
      v13[3].mUID = (unsigned __int64)&v13[2].mChildren[1];
      v13[3].mParent = (UFG::qTree64Base::BaseNode *)((char *)v13 + 120);
      v13[3].mChildren[0] = (UFG::qTree64Base::BaseNode *)((char *)v13 + 120);
      v13[3].mChildren[1] = 0i64;
      goto LABEL_30;
    }
  }
  else
  {
    p_mSchemas = (UFG::qReflectSchema *)&this->mSchemas;
    result = (UFG::qReflectSchema *)this->mSchemas.mTree.mHead.mChildren[0];
    if ( result != (UFG::qReflectSchema *)&this->mSchemas )
    {
      do
      {
        if ( result->mBaseNode.mUID >= v6 )
        {
          if ( result->mBaseNode.mUID <= v6 )
            goto LABEL_24;
          result = (UFG::qReflectSchema *)result->mBaseNode.mChildren[0];
        }
        else
        {
          result = (UFG::qReflectSchema *)result->mBaseNode.mChildren[1];
        }
      }
      while ( result != p_mSchemas );
    }
    result = 0i64;
LABEL_24:
    if ( !result )
    {
      v14 = UFG::gMainMemoryPool;
      if ( !UFG::gMainMemoryPool )
      {
        UFG::InternalSetupMainMemoryPool((UFG *)UFG::gMainMemoryPool);
        v14 = UFG::gMainMemoryPool;
      }
      v12 = UFG::qMemoryPool::Allocate(v14, 0xB0ui64, "CreateSchema", 0i64, 1u);
      v13 = (UFG::qTree64Base::BaseNode *)v12;
      if ( !v12 )
      {
        v13 = 0i64;
        goto LABEL_30;
      }
      goto LABEL_28;
    }
  }
  return result;
}

// File Line: 383
// RVA: 0x16AD80
UFG::qReflectAnnotation *__fastcall UFG::ReflectionDB::CreateAnnotation(
        UFG::ReflectionDB *this,
        UFG::qReflectSchema *schema_type,
        const char *name,
        const char *value)
{
  unsigned __int64 v8; // rsi
  unsigned __int64 v9; // rdi
  const char *v10; // rdx
  char i; // al
  const char *v12; // rdx
  char j; // al
  UFG::qReflectAnnotation *p_mAnnotations; // rbp
  UFG::qReflectAnnotation *result; // rax
  UFG::qMemoryPool *v16; // rcx
  UFG::allocator::free_link *v17; // rax
  UFG::qTree64Base::BaseNode *v18; // rbx

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
  p_mAnnotations = (UFG::qReflectAnnotation *)&schema_type->mAnnotations;
  result = (UFG::qReflectAnnotation *)p_mAnnotations->mBaseNode.mChildren[0];
  while ( result != p_mAnnotations )
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
    v18 = (UFG::qTree64Base::BaseNode *)v17;
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
    v18->mUID = v9;
    v18[1].mUID = (unsigned __int64)UFG::ReflectionDB::AddString(this, name);
    v18[1].mParent = (UFG::qTree64Base::BaseNode *)UFG::ReflectionDB::AddString(this, value);
    v18[1].mChildren[0] = (UFG::qTree64Base::BaseNode *)v9;
    v18[1].mChildren[1] = (UFG::qTree64Base::BaseNode *)v8;
    UFG::qTree64Base::Add((UFG::qTree64Base *)p_mAnnotations, v18);
    return (UFG::qReflectAnnotation *)v18;
  }
  return result;
}

// File Line: 453
// RVA: 0x17F4E0
void __fastcall UFG::ReflectionDB::ValidateClassSizes(UFG::ReflectionDB *this)
{
  UFG::qTree64<UFG::qReflectType,UFG::qReflectType,0> *p_mTypes; // rsi
  UFG::qTree64Base::BaseNode *p_mHead; // rbx
  UFG::qTree64<UFG::qReflectType,UFG::qReflectType,0> *i; // rax
  UFG::qTree64Base::BaseNode *v4; // rdx
  UFG::qReflectWarehouse *v5; // rax
  __int64 *p_mCount; // rdi
  UFG::qTree64Base::BaseNode *mParent; // rax
  UFG::qTree64<UFG::qReflectType,UFG::qReflectType,0> *v8; // rcx
  UFG::qTree64<UFG::qReflectType,UFG::qReflectType,0> *j; // rax
  _DWORD *p_mParent; // rax
  __int64 v11; // [rsp+20h] [rbp-28h]

  p_mTypes = &this->mTypes;
  p_mHead = this->mTypes.mTree.mHead.mChildren[0];
  if ( p_mHead == (UFG::qTree64Base::BaseNode *)&this->mTypes )
  {
    p_mHead = 0i64;
  }
  else
  {
    for ( i = (UFG::qTree64<UFG::qReflectType,UFG::qReflectType,0> *)p_mHead->mChildren[0];
          i != p_mTypes;
          i = (UFG::qTree64<UFG::qReflectType,UFG::qReflectType,0> *)i->mTree.mHead.mChildren[0] )
    {
      p_mHead = &i->mTree.mHead;
    }
  }
  while ( p_mHead )
  {
    if ( (_S12 & 1) == 0 )
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
    v4 = p_mHead[1].mChildren[1];
    v5 = (UFG::qReflectWarehouse *)sReflectWarehouse.mInventoryTree.mTree.mHead.mChildren[0];
    while ( v5 != &sReflectWarehouse )
    {
      if ( v5->mInventoryTree.mTree.mHead.mUID >= (unsigned __int64)v4 )
      {
        if ( v5->mInventoryTree.mTree.mHead.mUID <= (unsigned __int64)v4 )
        {
          p_mCount = &v5[-1].mInventoryTree.mTree.mCount;
          if ( v5 != (UFG::qReflectWarehouse *)8
            && p_mHead[1].mNeighbours[0] != (UFG::qTree64Base::BaseNode *)(*(unsigned int (__fastcall **)(__int64 *))*p_mCount)(p_mCount) )
          {
            LODWORD(v11) = (*(__int64 (__fastcall **)(__int64 *))*p_mCount)(p_mCount);
            UFG::qPrintf(
              "%s : error type %s size differs from the reflection database.  Size in Database %d, Size in Memory %d\n",
              (const char *)p_mHead[1].mParent,
              (const char *)p_mHead[1].mUID,
              LODWORD(p_mHead[1].mNeighbours[0]),
              v11);
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
    p_mHead = p_mHead->mNeighbours[1];
    mParent = p_mHead->mParent;
    if ( ((unsigned __int64)mParent & 0xFFFFFFFFFFFFFFFCui64) != 0 )
    {
      v8 = (UFG::qTree64<UFG::qReflectType,UFG::qReflectType,0> *)p_mHead->mChildren[1];
      if ( v8 == (UFG::qTree64<UFG::qReflectType,UFG::qReflectType,0> *)v8->mTree.mHead.mChildren[1] )
      {
        v8 = (UFG::qTree64<UFG::qReflectType,UFG::qReflectType,0> *)((unsigned __int64)p_mHead->mParent & 0xFFFFFFFFFFFFFFFCui64);
        if ( ((unsigned __int8)mParent & 2) != 0 )
        {
          do
          {
            p_mParent = &v8->mTree.mHead.mParent;
            v8 = (UFG::qTree64<UFG::qReflectType,UFG::qReflectType,0> *)((unsigned __int64)v8->mTree.mHead.mParent & 0xFFFFFFFFFFFFFFFCui64);
          }
          while ( (*p_mParent & 2) != 0 );
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
      p_mHead = 0i64;
      if ( v8 != p_mTypes )
        p_mHead = &v8->mTree.mHead;
    }
  }
}

// File Line: 471
// RVA: 0x1797C0
UFG::qReflectSchema *__fastcall UFG::ReflectionDB::ReadSchema(
        UFG::ReflectionDB *this,
        UFG::qReflectSchema *parent_schema,
        char **data_ptr)
{
  unsigned __int64 v5; // r9
  __int64 v6; // rsi
  UFG::ReflectionDB *v7; // rax
  const char *mCount; // r8
  UFG::qReflectSchema *Schema; // rdi
  unsigned __int64 v10; // r8
  unsigned __int64 v11; // r9
  UFG::ReflectionDB *v12; // rdx
  UFG::ReflectionDB *v13; // rcx
  const char *v14; // r8
  const char *v15; // r9
  __int64 v17; // [rsp+30h] [rbp+8h]

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
  mCount = 0i64;
  if ( v7 )
    mCount = (const char *)v7->mStrings.mTree.mCount;
  Schema = UFG::ReflectionDB::CreateSchema(this, parent_schema, mCount);
  if ( v17 > 0 )
  {
    do
    {
      v10 = *(_QWORD *)*data_ptr;
      v11 = *((_QWORD *)*data_ptr + 1);
      *data_ptr += 16;
      v12 = (UFG::ReflectionDB *)this->mStrings.mTree.mHead.mChildren[0];
      v13 = v12;
      while ( v13 != this )
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
      while ( v12 != this )
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
      UFG::ReflectionDB::CreateAnnotation(this, Schema, v14, v15);
      --v17;
    }
    while ( v17 );
  }
  if ( v6 > 0 )
  {
    do
    {
      UFG::ReflectionDB::ReadSchema(this, Schema, data_ptr);
      --v6;
    }
    while ( v6 );
  }
  return Schema;
}

// File Line: 498
// RVA: 0x176470
char __fastcall UFG::ReflectionDB::Load(UFG::ReflectionDB *this, const char *filename)
{
  __int64 FileSize; // rbp
  UFG::qMemoryPool *v5; // r14
  UFG::qFile *v6; // rsi
  UFG::allocator::free_link *v7; // rax
  char *v8; // r15
  char *v10; // r14
  int v11; // eax
  char *v12; // rcx
  unsigned __int64 v13; // rsi
  unsigned __int64 v14; // rdx
  UFG::allocator::free_link *v15; // rbp
  unsigned int v16; // r14d
  unsigned int flags; // r15d
  UFG::allocator::free_link *checksum; // r12
  UFG::ReflectionDB *v19; // rax
  unsigned __int64 v20; // r13
  UFG::ReflectionDB *String; // rbx
  UFG::ReflectionDB *v22; // rax
  UFG::qTree64<UFG::qReflectType,UFG::qReflectType,0> *Type; // rax
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
  UFG::ReflectionDB *v37; // rax
  unsigned __int64 *v38; // rcx
  unsigned __int64 *v39; // rbp
  unsigned __int64 v40; // rdx
  unsigned __int64 *v41; // rbx
  UFG::ReflectionDB *v42; // rax
  const char *mCount; // rdx
  UFG::qTree64<UFG::qReflectEnum,UFG::qReflectEnum,0> *i; // rsi
  UFG::ReflectionDB *v45; // rax
  unsigned __int64 v46; // rdx
  const char *v47; // r8
  char *v48; // [rsp+40h] [rbp-1C8h]
  char *v49; // [rsp+48h] [rbp-1C0h]
  char dest[384]; // [rsp+50h] [rbp-1B8h] BYREF
  char *data_ptr; // [rsp+220h] [rbp+18h] BYREF
  unsigned __int64 v52; // [rsp+228h] [rbp+20h]

  if ( byte_14235ACD8 )
    goto LABEL_8;
  if ( !filename )
    goto LABEL_8;
  if ( !*filename )
    goto LABEL_8;
  FileSize = UFG::qGetFileSize(filename);
  if ( FileSize <= 0 )
    goto LABEL_8;
  v5 = UFG::gMainMemoryPool;
  v6 = UFG::qOpen(filename, QACCESS_READ, 1);
  if ( !v6 )
    goto LABEL_8;
  UFG::qSPrintf(dest, "qReadEntireFile(%s)", filename);
  v7 = UFG::qMemoryPool::Allocate(v5, FileSize + 1, dest, 0i64, 1u);
  v8 = (char *)v7;
  v48 = (char *)v7;
  if ( !v7 )
  {
    UFG::qClose(v6);
LABEL_8:
    UFG::qPrintf("ERROR: Could not load ReflectionDB.  File not found!  filename = %s\n", filename);
    return 0;
  }
  if ( (int)UFG::qRead(v6, v7, FileSize, 0i64, QSEEK_CUR) != FileSize )
  {
    UFG::qClose(v6);
    UFG::qMemoryPool::Free(v5, v8);
    goto LABEL_8;
  }
  UFG::qClose(v6);
  v10 = v8;
  v8[FileSize] = 0;
  v49 = &v8[FileSize];
  data_ptr = v8;
  if ( v8 < &v8[FileSize] )
  {
    do
    {
      v11 = *(_DWORD *)v10;
      if ( *(_DWORD *)v10 == 735085971 )
      {
        v37 = (UFG::ReflectionDB *)this->mEnums.mTree.mHead.mChildren[0];
        v38 = (unsigned __int64 *)&v10[*((unsigned int *)v10 + 3) + 16];
        v39 = (unsigned __int64 *)((char *)v38 + *((unsigned int *)v10 + 2));
        v40 = *v38;
        v41 = v38 + 1;
        while ( v37 != (UFG::ReflectionDB *)&this->mEnums )
        {
          if ( v37->mStrings.mTree.mHead.mUID >= v40 )
          {
            if ( v37->mStrings.mTree.mHead.mUID <= v40 )
              goto LABEL_43;
            v37 = (UFG::ReflectionDB *)v37->mStrings.mTree.mHead.mChildren[0];
          }
          else
          {
            v37 = (UFG::ReflectionDB *)v37->mStrings.mTree.mHead.mChildren[1];
          }
        }
        v42 = (UFG::ReflectionDB *)this->mStrings.mTree.mHead.mChildren[0];
        while ( v42 != this )
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
        mCount = 0i64;
        if ( v42 )
          mCount = (const char *)v42->mStrings.mTree.mCount;
        for ( i = UFG::ReflectionDB::CreateEnum(this, mCount); v41 < v39; v41 += 2 )
        {
          v45 = (UFG::ReflectionDB *)this->mStrings.mTree.mHead.mChildren[0];
          v46 = *v41;
          while ( v45 != this )
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
          UFG::ReflectionDB::AddEnumValue(this, (UFG::qReflectEnum *)i, v47, v41[1]);
        }
      }
      else
      {
        switch ( v11 )
        {
          case 1473657222:
            data_ptr = &v10[*((unsigned int *)v10 + 3) + 16];
            UFG::ReflectionDB::ReadSchema(this, 0i64, &data_ptr);
            break;
          case 1565686639:
            v32 = &v10[*((unsigned int *)v10 + 3) + 16];
            for ( j = &v32[*((unsigned int *)v10 + 2)]; v32 < j; v32 += v34 + 1 )
            {
              UFG::ReflectionDB::AddString(this, v32);
              if ( v32 )
              {
                v35 = v32;
                while ( *v35++ )
                  ;
                v34 = (_DWORD)v35 - (_DWORD)v32 - 1;
              }
              else
              {
                v34 = 0;
              }
            }
            break;
          case -444625387:
            v12 = &v10[*((unsigned int *)v10 + 3) + 16];
            v13 = *(_QWORD *)v12;
            v14 = *((_QWORD *)v12 + 1);
            v15 = (UFG::allocator::free_link *)*((_QWORD *)v12 + 2);
            v16 = *((_DWORD *)v12 + 6);
            flags = *((_DWORD *)v12 + 7);
            checksum = (UFG::allocator::free_link *)*((_QWORD *)v12 + 4);
            v52 = (unsigned __int64)&v12[*((unsigned int *)data_ptr + 2)];
            v19 = (UFG::ReflectionDB *)this->mTypes.mTree.mHead.mChildren[0];
            v20 = (unsigned __int64)(v12 + 40);
            while ( v19 != (UFG::ReflectionDB *)&this->mTypes )
            {
              if ( v19->mStrings.mTree.mHead.mUID >= v14 )
              {
                if ( v19->mStrings.mTree.mHead.mUID <= v14 )
                  goto LABEL_42;
                v19 = (UFG::ReflectionDB *)v19->mStrings.mTree.mHead.mChildren[0];
              }
              else
              {
                v19 = (UFG::ReflectionDB *)v19->mStrings.mTree.mHead.mChildren[1];
              }
            }
            String = UFG::ReflectionDB::GetString(this, v14);
            v22 = UFG::ReflectionDB::GetString(this, v13);
            Type = UFG::ReflectionDB::CreateType(
                     this,
                     (const char *)String,
                     v15,
                     v16,
                     (const char *)v22,
                     flags,
                     checksum);
            v24 = v52;
            for ( k = (UFG::qReflectType *)Type; v20 < v24; v20 += 40i64 )
            {
              v26 = (UFG::ReflectionDB *)this->mStrings.mTree.mHead.mChildren[0];
              v27 = *(_QWORD *)v20;
              v28 = *(_QWORD *)(v20 + 8);
              v29 = v26;
              while ( v29 != this )
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
              while ( v26 != this )
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
                this,
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

