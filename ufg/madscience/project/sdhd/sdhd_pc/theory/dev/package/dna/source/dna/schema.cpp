// File Line: 29
// RVA: 0x1469910
unsigned __int64 DNA::SchemaAnnotationKey::_dynamic_initializer_for__IsHidden__()
{
  unsigned __int64 result; // rax

  result = UFG::qStringHash64("IsHidden", 0xFFFFFFFFFFFFFFFFui64);
  IsHidden = result;
  return result;
}

// File Line: 30
// RVA: 0x14698F0
unsigned __int64 DNA::SchemaAnnotationKey::_dynamic_initializer_for__IsCreatable__()
{
  unsigned __int64 result; // rax

  result = UFG::qStringHash64("IsCreatable", 0xFFFFFFFFFFFFFFFFui64);
  IsCreatable = result;
  return result;
}

// File Line: 31
// RVA: 0x14698B0
unsigned __int64 DNA::SchemaAnnotationKey::_dynamic_initializer_for__Editor__()
{
  unsigned __int64 result; // rax

  result = UFG::qStringHash64("Editor", 0xFFFFFFFFFFFFFFFFui64);
  Editor = result;
  return result;
}

// File Line: 32
// RVA: 0x14698D0
unsigned __int64 DNA::SchemaAnnotationKey::_dynamic_initializer_for__EditorArgs__()
{
  unsigned __int64 result; // rax

  result = UFG::qStringHash64("EditorArgs", 0xFFFFFFFFFFFFFFFFui64);
  EditorArgs = result;
  return result;
}

// File Line: 86
// RVA: 0x1A9FE0
void __fastcall DNA::SchemaEnum::SchemaEnum(DNA::SchemaEnum *this, UFG::qReflectEnum *reflectEnum)
{
  unsigned __int64 mNameUID; // rax

  mNameUID = reflectEnum->mNameUID;
  this->mBaseNode.mUID = 0i64;
  this->mBaseNode.mParent = &this->mBaseNode;
  this->mBaseNode.mChildren[0] = &this->mBaseNode;
  this->mBaseNode.mChildren[1] = &this->mBaseNode;
  this->mBaseNode.mNeighbours[0] = &this->mBaseNode;
  this->mBaseNode.mNeighbours[1] = &this->mBaseNode;
  this->mBaseNode.mUID = mNameUID;
  this->mEnum = reflectEnum;
  this->mValues.mNode.mPrev = &this->mValues.mNode;
  this->mValues.mNode.mNext = &this->mValues.mNode;
}

// File Line: 103
// RVA: 0x1AA030
void __fastcall DNA::SchemaField::SchemaField(
        DNA::SchemaField *this,
        UFG::qReflectField *reflectField,
        UFG::qReflectSchema *reflectSchema)
{
  unsigned __int64 mUID; // rax
  UFG::qTreeNode64<DNA::SchemaField,DNA::SchemaField> *v7; // rbp
  UFG::qTree64Base *i; // rsi
  UFG::allocator::free_link *v9; // rax
  UFG::allocator::free_link *v10; // rbx
  const char *v11; // rdi
  const char *mCount; // rdx

  this->mPrev = this;
  this->mNext = this;
  mUID = reflectField->mBaseNode.mUID;
  v7 = &this->UFG::qTreeNode64<DNA::SchemaField,DNA::SchemaField>;
  this->mBaseNode.mUID = 0i64;
  this->mBaseNode.mParent = &this->mBaseNode;
  this->mBaseNode.mChildren[0] = &this->mBaseNode;
  this->mBaseNode.mChildren[1] = &this->mBaseNode;
  this->mBaseNode.mNeighbours[0] = &this->mBaseNode;
  this->mBaseNode.mNeighbours[1] = &this->mBaseNode;
  this->mBaseNode.mUID = mUID;
  UFG::qString::qString(&this->mName, reflectField->mName);
  UFG::qString::qString(&this->mTypeName);
  UFG::qString::qString(&this->mDisplayName);
  this->mArrayLength = reflectField->mArrayLength;
  this->mIsArrayOfPointers = 0;
  this->mAnnotations.mTree.mHead.mUID = 0i64;
  this->mAnnotations.mTree.mHead.mParent = &this->mAnnotations.mTree.mHead;
  this->mAnnotations.mTree.mHead.mChildren[0] = &this->mAnnotations.mTree.mHead;
  this->mAnnotations.mTree.mHead.mChildren[1] = &this->mAnnotations.mTree.mHead;
  this->mAnnotations.mTree.mHead.mNeighbours[0] = &this->mAnnotations.mTree.mHead;
  this->mAnnotations.mTree.mHead.mNeighbours[1] = &this->mAnnotations.mTree.mHead;
  this->mAnnotations.mTree.mCount = 0i64;
  this->mReflectionField = reflectField;
  this->mReflectionSchema = reflectSchema;
  if ( reflectSchema )
  {
    for ( i = UFG::qTree64Base::GetHead(&reflectSchema->mAnnotations.mTree);
          i;
          i = UFG::qTree64Base::GetNext(&reflectSchema->mAnnotations.mTree, &i->mHead) )
    {
      v9 = UFG::qMalloc(0x80ui64, "SchemaAnnotation", 0i64);
      v10 = v9;
      if ( v9 )
      {
        v11 = (const char *)i[1].mHead.mUID;
        mCount = (const char *)i->mCount;
        v9->mNext = 0i64;
        v9[1].mNext = v9;
        v9[2].mNext = v9;
        v9[3].mNext = v9;
        v9[4].mNext = v9;
        v9[5].mNext = v9;
        UFG::qString::qString((UFG::qString *)&v9[6], mCount);
        UFG::qString::qString((UFG::qString *)&v10[11], v11);
        v10->mNext = (UFG::allocator::free_link *)UFG::qStringHash64((const char *)v10[9].mNext, 0xFFFFFFFFFFFFFFFFui64);
      }
      else
      {
        v10 = 0i64;
      }
      UFG::qTree64Base::Add(&this->mAnnotations.mTree, (UFG::qTree64Base::BaseNode *)v10);
    }
  }
  DNA::SchemaField::ParseReflectionField(this, reflectField);
  v7->mBaseNode.mUID = UFG::qStringHash64(this->mName.mData, 0xFFFFFFFFFFFFFFFFui64);
}

// File Line: 117
// RVA: 0x1AA470
void __fastcall DNA::SchemaField::~SchemaField(DNA::SchemaField *this)
{
  UFG::qTree64Base *Head; // rax
  UFG::qTree64Base *v3; // rbx
  UFG::qNode<DNA::SchemaField,DNA::SchemaField> *mPrev; // rcx
  UFG::qNode<DNA::SchemaField,DNA::SchemaField> *mNext; // rax

  while ( this->mAnnotations.mTree.mCount )
  {
    Head = UFG::qTree64Base::GetHead(&this->mAnnotations.mTree);
    v3 = Head;
    if ( Head )
      UFG::qTree64Base::Remove(&this->mAnnotations.mTree, Head);
    if ( v3 )
    {
      UFG::qString::~qString((UFG::qString *)v3[1].mHead.mNeighbours);
      UFG::qString::~qString((UFG::qString *)&v3->mCount);
      operator delete[](v3);
    }
  }
  UFG::qString::~qString(&this->mDisplayName);
  UFG::qString::~qString(&this->mTypeName);
  UFG::qString::~qString(&this->mName);
  mPrev = this->mPrev;
  mNext = this->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  this->mPrev = this;
  this->mNext = this;
}

// File Line: 122
// RVA: 0x1AA5A0
UFG::qTree64Base *__fastcall DNA::SchemaField::GetAnnotation(DNA::SchemaField *this, const char *key)
{
  unsigned __int64 v3; // rax
  UFG::qTree64Base *result; // rax

  v3 = UFG::qStringHash64(key, 0xFFFFFFFFFFFFFFFFui64);
  result = UFG::qTree64Base::Get(&this->mAnnotations.mTree, v3);
  if ( result )
    return (UFG::qTree64Base *)result[2].mHead.mUID;
  return result;
}

// File Line: 140
// RVA: 0x1AA5E0
char *__fastcall DNA::SchemaField::GetDefaultValue(DNA::SchemaField *this)
{
  UFG::qTree64Base *v2; // rax
  UFG::qTree64Base::BaseNode *mUID; // rdi
  char *mData; // rbx
  DNA::Database *v5; // rax
  UFG::qTree64Base *Enum; // rax
  char *result; // rax

  v2 = UFG::qTree64Base::Get(&this->mAnnotations.mTree, 0x9FBDD84DDA94B822ui64);
  if ( v2 )
  {
    mUID = (UFG::qTree64Base::BaseNode *)v2[2].mHead.mUID;
    if ( mUID )
      goto LABEL_7;
  }
  else
  {
    mUID = 0i64;
  }
  if ( (this->mReflectionField->mFlags & 4) != 0 )
  {
    mData = this->mTypeName.mData;
    DNA::Database::Instance();
    Enum = DNA::Database::GetEnum(v5, mData);
    if ( Enum )
      mUID = Enum[1].mHead.mParent->mChildren[0]->mChildren[0];
  }
LABEL_7:
  result = &customCaption;
  if ( mUID )
    return (char *)mUID;
  return result;
}

// File Line: 154
// RVA: 0x1AA6D0
void __fastcall DNA::SchemaField::GetDefaultValue(DNA::SchemaField *this, char **v)
{
  *v = DNA::SchemaField::GetDefaultValue(this);
}

// File Line: 155
// RVA: 0x1AA6F0
void __fastcall DNA::SchemaField::GetDefaultValue(DNA::SchemaField *this, UFG::qString *v)
{
  char *DefaultValue; // rax

  DefaultValue = DNA::SchemaField::GetDefaultValue(this);
  DNA::DataConverter::ToType(DefaultValue, v);
}

// File Line: 156
// RVA: 0x1AA670
void __fastcall DNA::SchemaField::GetDefaultValue(DNA::SchemaField *this, int *v)
{
  char *DefaultValue; // rax

  DefaultValue = DNA::SchemaField::GetDefaultValue(this);
  DNA::DataConverter::ToType(DefaultValue, v);
}

// File Line: 157
// RVA: 0x1AA710
void __fastcall DNA::SchemaField::GetDefaultValue(DNA::SchemaField *this, __int64 *v)
{
  char *DefaultValue; // rax

  DefaultValue = DNA::SchemaField::GetDefaultValue(this);
  DNA::DataConverter::ToType(DefaultValue, v);
}

// File Line: 158
// RVA: 0x1AA690
void __fastcall DNA::SchemaField::GetDefaultValue(DNA::SchemaField *this, unsigned int *v)
{
  char *DefaultValue; // rax

  DefaultValue = DNA::SchemaField::GetDefaultValue(this);
  DNA::DataConverter::ToType(DefaultValue, v);
}

// File Line: 159
// RVA: 0x1AA730
void __fastcall DNA::SchemaField::GetDefaultValue(DNA::SchemaField *this, unsigned __int64 *v)
{
  char *DefaultValue; // rax

  DefaultValue = DNA::SchemaField::GetDefaultValue(this);
  DNA::DataConverter::ToType(DefaultValue, v);
}

// File Line: 160
// RVA: 0x1AA750
void __fastcall DNA::SchemaField::GetDefaultValue(DNA::SchemaField *this, bool *v)
{
  char *DefaultValue; // rax

  DefaultValue = DNA::SchemaField::GetDefaultValue(this);
  DNA::DataConverter::ToType(DefaultValue, v);
}

// File Line: 161
// RVA: 0x1AA6B0
void __fastcall DNA::SchemaField::GetDefaultValue(DNA::SchemaField *this, float *v)
{
  char *DefaultValue; // rax

  DefaultValue = DNA::SchemaField::GetDefaultValue(this);
  DNA::DataConverter::ToType(DefaultValue, v);
}

// File Line: 165
// RVA: 0x1AA790
UFG::qTree64Base *__fastcall DNA::SchemaField::GetTypeSchema(DNA::SchemaField *this)
{
  char *mData; // rbx
  DNA::Database *v2; // rax

  mData = this->mTypeName.mData;
  DNA::Database::Instance();
  return DNA::Database::GetSchema(v2, mData);
}

// File Line: 170
// RVA: 0x1AA8D0
__int64 __fastcall DNA::SchemaField::ParseTypeName(DNA::SchemaField *this, UFG::qReflectField *reflectionField)
{
  unsigned int v2; // ebx
  UFG::ReflectionDB *v5; // rax
  UFG::qReflectField *mUID; // rdi
  DNA::PropertyType::Enum v7; // ebx
  unsigned int mFlags; // ecx

  v2 = 0;
  if ( (reflectionField->mFlags & 0x20) != 0 )
  {
    v5 = UFG::ReflectionDB::Instance();
    mUID = (UFG::qReflectField *)UFG::ReflectionDB::GetType(v5, reflectionField->mTypeName)[3].mTree.mHead.mUID;
    v7 = DNA::SchemaField::ParseTypeName(this, mUID);
    if ( v7 == UID_int8 )
    {
      v7 = -915936389;
      if ( (mUID->mFlags & 0x4000) != 0 )
        this->mIsArrayOfPointers = 1;
    }
    this->mArrayLength = -1;
    return (unsigned int)v7;
  }
  else
  {
    UFG::qString::Set(&this->mTypeName, reflectionField->mTypeName);
    if ( (unsigned int)UFG::qStringCompareInsensitive(reflectionField->mTypeName, "long", -1)
      && (unsigned int)UFG::qStringCompareInsensitive(reflectionField->mTypeName, "int32", -1)
      && (unsigned int)UFG::qStringCompareInsensitive(reflectionField->mTypeName, "int", -1) )
    {
      if ( !(unsigned int)UFG::qStringCompareInsensitive(reflectionField->mTypeName, "long long", -1)
        || !(unsigned int)UFG::qStringCompareInsensitive(reflectionField->mTypeName, "int64", -1) )
      {
        return 224407815i64;
      }
      if ( !(unsigned int)UFG::qStringCompareInsensitive(reflectionField->mTypeName, "unsigned long", -1)
        || !(unsigned int)UFG::qStringCompareInsensitive(reflectionField->mTypeName, "unsigned int", -1)
        || !(unsigned int)UFG::qStringCompareInsensitive(reflectionField->mTypeName, "uint32", -1) )
      {
        return 2227172330i64;
      }
      if ( !(unsigned int)UFG::qStringCompareInsensitive(reflectionField->mTypeName, "unsigned long long", -1)
        || !(unsigned int)UFG::qStringCompareInsensitive(reflectionField->mTypeName, "uint64", -1) )
      {
        return 151281197i64;
      }
      if ( !(unsigned int)UFG::qStringCompareInsensitive(reflectionField->mTypeName, "float", -1) )
        return 1208522079i64;
      if ( !(unsigned int)UFG::qStringCompareInsensitive(reflectionField->mTypeName, "bool", -1) )
        return 1138723642i64;
      if ( !(unsigned int)UFG::qStringCompareInsensitive(reflectionField->mTypeName, "char", -1) )
        return 1830847931i64;
      mFlags = reflectionField->mFlags;
      if ( (mFlags & 0x2000) != 0 && (this->mReflectionField->mFlags & 0x10) != 0 )
        return 3379030907i64;
      if ( (mFlags & 4) != 0
        || (mFlags & 0x200) != 0
        || (mFlags & 0x80u) != 0
        || (mFlags & 0x100) != 0
        || (mFlags & 8) != 0 )
      {
        return 826535573i64;
      }
      if ( (reflectionField->mFlags & 0x2000) == 0 )
        return 3379030907i64;
    }
    else
    {
      return (unsigned int)-2133091136;
    }
    return v2;
  }
}

// File Line: 273
// RVA: 0x1AA7C0
void __fastcall DNA::SchemaField::ParseReflectionField(DNA::SchemaField *this, UFG::qReflectField *reflectionField)
{
  UFG::qTree64Base *v3; // rax
  char *mUID; // rdx
  char *mData; // r10
  char *v6; // rdx
  char *i; // rax
  char v8; // r8
  char v9; // r8
  char text[1032]; // [rsp+20h] [rbp-408h] BYREF

  this->mType = DNA::SchemaField::ParseTypeName(this, reflectionField);
  v3 = UFG::qTree64Base::Get(&this->mAnnotations.mTree, 0xBA5A85D7368891B0ui64);
  if ( !v3 || (mUID = (char *)v3[2].mHead.mUID) == 0i64 )
  {
    mData = this->mName.mData;
    v6 = text;
    for ( i = mData; *i; ++i )
    {
      if ( i == mData && *i == 109 )
      {
        v8 = i[1];
        if ( v8 == 95 )
        {
          ++i;
          continue;
        }
        if ( (unsigned __int8)(v8 - 65) <= 0x19u )
          continue;
      }
      v9 = *i;
      if ( *(_WORD *)i == 25187 )
      {
        if ( i[2] == 95 )
          ++i;
        ++i;
        continue;
      }
      if ( v9 == 95 )
      {
        *v6 = 32;
LABEL_21:
        ++v6;
        continue;
      }
      if ( v6 == text || (unsigned __int8)(v9 - 97) > 0x19u || (unsigned __int8)(i[1] - 65) > 0x19u )
      {
        *v6 = v9;
        goto LABEL_21;
      }
      *v6 = v9;
      v6[1] = 32;
      v6 += 2;
    }
    *v6 = 0;
    mUID = text;
  }
  UFG::qString::Set(&this->mDisplayName, mUID);
}

// File Line: 349
// RVA: 0x1AA1F0
void __fastcall DNA::SchemaType::SchemaType(
        DNA::SchemaType *this,
        UFG::qReflectType *reflectType,
        UFG::qReflectSchema *reflectSchema)
{
  UFG::qReflectType *v4; // rbx
  unsigned __int64 mUID; // rax
  UFG::qTree64<DNA::SchemaField,DNA::SchemaField,0> *p_mFields; // r12
  UFG::qList<DNA::SchemaField,DNA::SchemaField,1,0> *p_mOrderedFields; // r14
  UFG::qTree64Base *Head; // rbp
  UFG::allocator::free_link *v10; // rax
  UFG::allocator::free_link *v11; // rbx
  const char *v12; // rdi
  const char *mCount; // rdx
  UFG::qReflectField *mNext; // rdi
  UFG::qReflectField *v15; // rbp
  UFG::qTree64Base *v16; // rbx
  UFG::allocator::free_link *v17; // rax
  __int64 v18; // rax
  __int64 v19; // rbx
  UFG::qNode<DNA::SchemaField,DNA::SchemaField> *mPrev; // rax

  v4 = reflectType;
  mUID = reflectType->mBaseNode.mUID;
  this->mBaseNode.mUID = 0i64;
  this->mBaseNode.mParent = &this->mBaseNode;
  this->mBaseNode.mChildren[0] = &this->mBaseNode;
  this->mBaseNode.mChildren[1] = &this->mBaseNode;
  this->mBaseNode.mNeighbours[0] = &this->mBaseNode;
  this->mBaseNode.mNeighbours[1] = &this->mBaseNode;
  this->mBaseNode.mUID = mUID;
  UFG::qString::qString(&this->mName, reflectType->mName);
  p_mFields = &this->mFields;
  this->mFields.mTree.mHead.mUID = 0i64;
  this->mFields.mTree.mHead.mParent = &this->mFields.mTree.mHead;
  this->mFields.mTree.mHead.mChildren[0] = &this->mFields.mTree.mHead;
  this->mFields.mTree.mHead.mChildren[1] = &this->mFields.mTree.mHead;
  this->mFields.mTree.mHead.mNeighbours[0] = &this->mFields.mTree.mHead;
  this->mFields.mTree.mHead.mNeighbours[1] = &this->mFields.mTree.mHead;
  this->mFields.mTree.mCount = 0i64;
  p_mOrderedFields = &this->mOrderedFields;
  this->mOrderedFields.mNode.mPrev = &this->mOrderedFields.mNode;
  this->mOrderedFields.mNode.mNext = &this->mOrderedFields.mNode;
  this->mAnnotations.mTree.mHead.mUID = 0i64;
  this->mAnnotations.mTree.mHead.mParent = &this->mAnnotations.mTree.mHead;
  this->mAnnotations.mTree.mHead.mChildren[0] = &this->mAnnotations.mTree.mHead;
  this->mAnnotations.mTree.mHead.mChildren[1] = &this->mAnnotations.mTree.mHead;
  this->mAnnotations.mTree.mHead.mNeighbours[0] = &this->mAnnotations.mTree.mHead;
  this->mAnnotations.mTree.mHead.mNeighbours[1] = &this->mAnnotations.mTree.mHead;
  this->mAnnotations.mTree.mCount = 0i64;
  this->mReflectionType = v4;
  this->mReflectionSchema = reflectSchema;
  if ( reflectSchema )
  {
    Head = UFG::qTree64Base::GetHead(&reflectSchema->mAnnotations.mTree);
    if ( Head )
    {
      do
      {
        v10 = UFG::qMalloc(0x80ui64, "SchemaAnnotation", 0i64);
        v11 = v10;
        if ( v10 )
        {
          v12 = (const char *)Head[1].mHead.mUID;
          mCount = (const char *)Head->mCount;
          v10->mNext = 0i64;
          v10[1].mNext = v10;
          v10[2].mNext = v10;
          v10[3].mNext = v10;
          v10[4].mNext = v10;
          v10[5].mNext = v10;
          UFG::qString::qString((UFG::qString *)&v10[6], mCount);
          UFG::qString::qString((UFG::qString *)&v11[11], v12);
          v11->mNext = (UFG::allocator::free_link *)UFG::qStringHash64(
                                                      (const char *)v11[9].mNext,
                                                      0xFFFFFFFFFFFFFFFFui64);
        }
        else
        {
          v11 = 0i64;
        }
        UFG::qTree64Base::Add(&this->mAnnotations.mTree, (UFG::qTree64Base::BaseNode *)v11);
        Head = UFG::qTree64Base::GetNext(&reflectSchema->mAnnotations.mTree, &Head->mHead);
      }
      while ( Head );
      p_mFields = &this->mFields;
      v4 = reflectType;
    }
  }
  mNext = (UFG::qReflectField *)v4->mOrderedFields.mNode.mNext;
  v15 = (UFG::qReflectField *)&v4->mOrderedFields;
  if ( mNext != (UFG::qReflectField *)&v4->mOrderedFields )
  {
    do
    {
      if ( reflectSchema )
        v16 = UFG::qTree64Base::Get(&reflectSchema->mSchemas.mTree, mNext->mBaseNode.mUID);
      else
        v16 = 0i64;
      v17 = UFG::qMalloc(0x110ui64, "Database::SchemaField", 0i64);
      if ( v17 )
      {
        DNA::SchemaField::SchemaField((DNA::SchemaField *)v17, mNext, (UFG::qReflectSchema *)v16);
        v19 = v18;
      }
      else
      {
        v19 = 0i64;
      }
      UFG::qTree64Base::Add(&p_mFields->mTree, (UFG::qTree64Base::BaseNode *)(v19 + 16));
      mPrev = p_mOrderedFields->mNode.mPrev;
      mPrev->mNext = (UFG::qNode<DNA::SchemaField,DNA::SchemaField> *)v19;
      *(_QWORD *)v19 = mPrev;
      *(_QWORD *)(v19 + 8) = p_mOrderedFields;
      p_mOrderedFields->mNode.mPrev = (UFG::qNode<DNA::SchemaField,DNA::SchemaField> *)v19;
      mNext = (UFG::qReflectField *)mNext->mNext;
    }
    while ( mNext != v15 );
  }
}

// File Line: 373
// RVA: 0x1AA770
UFG::qTree64Base *__fastcall DNA::SchemaType::GetField(DNA::SchemaType *this, unsigned __int64 fieldNameUID)
{
  UFG::qTree64Base *result; // rax

  result = UFG::qTree64Base::Get(&this->mFields.mTree, fieldNameUID);
  if ( result )
    return (UFG::qTree64Base *)((char *)result - 16);
  return result;
}

