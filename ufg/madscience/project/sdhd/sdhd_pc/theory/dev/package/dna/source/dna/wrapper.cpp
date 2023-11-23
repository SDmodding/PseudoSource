// File Line: 21
// RVA: 0x1AC1B0
void __fastcall DNA::PropertyBagWrapper::PropertyBagWrapper(DNA::PropertyBagWrapper *this, DNA::SchemaType *schema)
{
  this->mSchema = schema;
  this->mProperties.mNode.mPrev = &this->mProperties.mNode;
  this->mProperties.mNode.mNext = &this->mProperties.mNode;
  this->mPropertyBags.p = 0i64;
  *(_QWORD *)&this->mPropertyBags.size = 0i64;
  DNA::PropertyBagWrapper::AddSchemaFields(this, this->mSchema);
}

// File Line: 28
// RVA: 0x1AC140
void __fastcall DNA::PropertyBagWrapper::PropertyBagWrapper(
        DNA::PropertyBagWrapper *this,
        DNA::PropertyBag *propertyBag)
{
  this->mSchema = (DNA::SchemaType *)DNA::PropertyBag::GetSchemaType(propertyBag);
  this->mProperties.mNode.mPrev = &this->mProperties.mNode;
  this->mProperties.mNode.mNext = &this->mProperties.mNode;
  this->mPropertyBags.p = 0i64;
  *(_QWORD *)&this->mPropertyBags.size = 0i64;
  DNA::PropertyBagWrapper::AddSchemaFields(this, this->mSchema);
  DNA::PropertyBagWrapper::AddPropertyBag(this, propertyBag);
}

// File Line: 34
// RVA: 0x1AC240
void __fastcall DNA::PropertyBagWrapper::~PropertyBagWrapper(DNA::PropertyBagWrapper *this)
{
  DNA::PropertyBag **p; // rcx
  UFG::qList<DNA::PropertyWrapper,DNA::PropertyWrapper,1,0> *p_mProperties; // rbx

  p = this->mPropertyBags.p;
  if ( p )
    operator delete[](p);
  this->mPropertyBags.p = 0i64;
  *(_QWORD *)&this->mPropertyBags.size = 0i64;
  p_mProperties = &this->mProperties;
  UFG::qList<DNA::PropertyWrapper,DNA::PropertyWrapper,1,0>::DeleteNodes(p_mProperties);
  UFG::qNode<UFG::DoorComponent,UFG::DoorComponent>::~qNode<UFG::DoorComponent,UFG::DoorComponent>((UFG::qNode<UFG::qString,UFG::qString> *)p_mProperties);
}

// File Line: 37
// RVA: 0x1AC450
void __fastcall DNA::PropertyBagWrapper::AddSchemaFields(DNA::PropertyBagWrapper *this, DNA::SchemaType *schema)
{
  DNA::SchemaType *mNext; // rbx
  UFG::qList<DNA::SchemaField,DNA::SchemaField,1,0> *p_mOrderedFields; // rsi
  UFG::qList<DNA::PropertyWrapper,DNA::PropertyWrapper,1,0> *p_mProperties; // rdi
  UFG::allocator::free_link *v6; // rax
  UFG::allocator::free_link *mPrev; // rcx

  mNext = (DNA::SchemaType *)schema->mOrderedFields.mNode.mNext;
  p_mOrderedFields = &schema->mOrderedFields;
  if ( mNext != (DNA::SchemaType *)&schema->mOrderedFields )
  {
    p_mProperties = &this->mProperties;
    do
    {
      v6 = UFG::qMalloc(0x30ui64, UFG::gGlobalNewName, 0i64);
      if ( v6 )
      {
        v6->mNext = v6;
        v6[1].mNext = v6;
        v6[2].mNext = (UFG::allocator::free_link *)this;
        v6[3].mNext = (UFG::allocator::free_link *)mNext;
        v6[5].mNext = 0i64;
        v6[4].mNext = 0i64;
      }
      else
      {
        v6 = 0i64;
      }
      mPrev = (UFG::allocator::free_link *)p_mProperties->mNode.mPrev;
      mPrev[1].mNext = v6;
      v6->mNext = mPrev;
      v6[1].mNext = (UFG::allocator::free_link *)p_mProperties;
      p_mProperties->mNode.mPrev = (UFG::qNode<DNA::PropertyWrapper,DNA::PropertyWrapper> *)v6;
      mNext = (DNA::SchemaType *)mNext->mBaseNode.mParent;
    }
    while ( mNext != (DNA::SchemaType *)p_mOrderedFields );
  }
}

// File Line: 45
// RVA: 0x1AC810
DNA::PropertyWrapper *__fastcall DNA::PropertyBagWrapper::GetProperty(
        DNA::PropertyBagWrapper *this,
        const char *propertyName)
{
  DNA::PropertyWrapper *p_mProperties; // rbx
  unsigned __int64 v3; // rdx
  DNA::PropertyWrapper *result; // rax

  p_mProperties = (DNA::PropertyWrapper *)&this->mProperties;
  v3 = UFG::qStringHash64(propertyName, 0xFFFFFFFFFFFFFFFFui64);
  result = (DNA::PropertyWrapper *)p_mProperties->mNext;
  if ( result == p_mProperties )
    return 0i64;
  while ( result->mSchemaField->mBaseNode.mUID != v3 )
  {
    result = (DNA::PropertyWrapper *)result->mNext;
    if ( result == p_mProperties )
      return 0i64;
  }
  return result;
}

// File Line: 81
// RVA: 0x1AC350
void __fastcall DNA::PropertyBagWrapper::AddPropertyBag(DNA::PropertyBagWrapper *this, DNA::PropertyBag *propertyBag)
{
  unsigned int size; // edx
  unsigned int v4; // eax
  DNA::PropertyBag **p; // r8
  unsigned int capacity; // edx
  __int64 v8; // rbp
  unsigned int v9; // ebx
  unsigned int v10; // edx
  DNA::PropertyBag **v11; // rax
  DNA::PropertyWrapper *i; // rbx
  signed int mArrayLength; // edx

  size = this->mPropertyBags.size;
  v4 = 0;
  if ( !size )
    goto LABEL_7;
  p = this->mPropertyBags.p;
  while ( propertyBag != *p )
  {
    ++v4;
    ++p;
    if ( v4 >= size )
      goto LABEL_7;
  }
  if ( v4 == -1 )
  {
LABEL_7:
    propertyBag->mIsDirtyLock = 1;
    capacity = this->mPropertyBags.capacity;
    v8 = this->mPropertyBags.size;
    v9 = v8 + 1;
    if ( (int)v8 + 1 > capacity )
    {
      if ( capacity )
        v10 = 2 * capacity;
      else
        v10 = 1;
      for ( ; v10 < v9; v10 *= 2 )
        ;
      if ( v10 <= 2 )
        v10 = 2;
      if ( v10 - v9 > 0x10000 )
        v10 = v8 + 65537;
      UFG::qArray<UFG::CompositeDrawableComponent *,32>::Reallocate(
        (UFG::qArray<UFG::qReflectInventoryBase *,0> *)&this->mPropertyBags,
        v10,
        "qArray.Add");
    }
    v11 = this->mPropertyBags.p;
    this->mPropertyBags.size = v9;
    v11[v8] = propertyBag;
    for ( i = (DNA::PropertyWrapper *)this->mProperties.mNode.mNext;
          i != (DNA::PropertyWrapper *)&this->mProperties;
          i = (DNA::PropertyWrapper *)i->mNext )
    {
      mArrayLength = i->mSchemaField->mArrayLength;
      if ( mArrayLength > 0 )
        DNA::PropertyWrapper::SetArrayLength(i, mArrayLength, propertyBag);
    }
    propertyBag->mIsDirtyLock = 0;
  }
}

// File Line: 140
// RVA: 0x1AC290
void __fastcall DNA::PropertyWrapper::~PropertyWrapper(DNA::PropertyWrapper *this)
{
  unsigned int i; // esi
  DNA::PropertyBagWrapper *v3; // rbx
  DNA::PropertyBag **p; // rcx
  DNA::PropertyBagWrapper **v5; // rcx
  DNA::PropertyBagWrapper **v6; // rcx
  UFG::qNode<DNA::PropertyWrapper,DNA::PropertyWrapper> *mPrev; // rcx
  UFG::qNode<DNA::PropertyWrapper,DNA::PropertyWrapper> *mNext; // rax

  for ( i = 0; i < this->mPropertyBagWrapperValues.size; ++i )
  {
    v3 = this->mPropertyBagWrapperValues.p[i];
    if ( v3 )
    {
      p = v3->mPropertyBags.p;
      if ( p )
        operator delete[](p);
      v3->mPropertyBags.p = 0i64;
      *(_QWORD *)&v3->mPropertyBags.size = 0i64;
      UFG::qList<DNA::PropertyWrapper,DNA::PropertyWrapper,1,0>::~qList<DNA::PropertyWrapper,DNA::PropertyWrapper,1,0>(&v3->mProperties);
      operator delete[](v3);
    }
  }
  v5 = this->mPropertyBagWrapperValues.p;
  if ( v5 )
    operator delete[](v5);
  this->mPropertyBagWrapperValues.p = 0i64;
  *(_QWORD *)&this->mPropertyBagWrapperValues.size = 0i64;
  v6 = this->mPropertyBagWrapperValues.p;
  if ( v6 )
    operator delete[](v6);
  this->mPropertyBagWrapperValues.p = 0i64;
  *(_QWORD *)&this->mPropertyBagWrapperValues.size = 0i64;
  mPrev = this->mPrev;
  mNext = this->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  this->mPrev = this;
  this->mNext = this;
}

// File Line: 149
// RVA: 0x1AC860
DNA::PropertyInfo *__fastcall DNA::PropertyWrapper::GetPropertyInfo(
        DNA::PropertyWrapper *this,
        DNA::PropertyInfo *result)
{
  unsigned int v4; // edi
  DNA::PropertyBagWrapper *mPropertyBagWrapper; // rcx
  int mArrayLength; // ecx
  unsigned int Size; // ecx
  DNA::PropertyInfo info; // [rsp+30h] [rbp-38h] BYREF

  *(_QWORD *)&result->Type = 0i64;
  result->States.p = 0i64;
  *(_QWORD *)&result->States.size = 0i64;
  v4 = 1;
  result->Type = this->mSchemaField->mType;
  result->Size = 0;
  mPropertyBagWrapper = this->mPropertyBagWrapper;
  if ( !mPropertyBagWrapper->mPropertyBags.size )
    return result;
  DNA::PropertyBag::GetPropertyInfo(*mPropertyBagWrapper->mPropertyBags.p, this->mSchemaField->mName.mData, result);
  mArrayLength = this->mSchemaField->mArrayLength;
  if ( mArrayLength >= 2 )
  {
    if ( (signed int)result->Size > mArrayLength )
      goto LABEL_5;
  }
  else
  {
    if ( mArrayLength != -1 )
    {
      if ( (signed int)result->Size <= mArrayLength )
        return result;
LABEL_5:
      result->Size = mArrayLength;
      return result;
    }
    if ( this->mPropertyBagWrapper->mPropertyBags.size > 1 )
    {
      do
      {
        memset(&info, 0, sizeof(info));
        DNA::PropertyBag::GetPropertyInfo(
          this->mPropertyBagWrapper->mPropertyBags.p[v4],
          this->mSchemaField->mName.mData,
          &info);
        Size = info.Size;
        if ( result->Size > info.Size )
        {
          result->Type = info.Type;
          result->Size = Size;
          UFG::qArray<enum DNA::PropertyState::Enum,0>::Clone(
            (UFG::qArray<unsigned long,0> *)&info.States,
            (UFG::qArray<unsigned long,0> *)&result->States);
        }
        if ( info.States.p )
          operator delete[](info.States.p);
        info.States.p = 0i64;
        *(_QWORD *)&info.States.size = 0i64;
        ++v4;
      }
      while ( v4 < this->mPropertyBagWrapper->mPropertyBags.size );
    }
  }
  return result;
}

// File Line: 234
// RVA: 0x1AC560
DNA::PropertyBag *__fastcall DNA::PropertyWrapper::FindTopLevelObject(
        DNA::PropertyWrapper *this,
        DNA::PropertyBag *propertyBag)
{
  DNA::PropertyBag *v2; // rbp
  UFG::qReflectField *mReflectionField; // r12
  bool v4; // r13
  UFG::qTree64Base *SchemaType; // rax
  UFG::qTree64Base *Owner; // rax
  DNA::PropertyBag *v7; // r15
  UFG::qBaseTreeRB *i; // rax
  DNA::PropertyData *v9; // rdi
  unsigned int v10; // esi
  unsigned int v11; // ebx
  char *mData; // rbx
  UFG::qTree64Base *v13; // rdi
  unsigned __int64 v14; // rax
  UFG::qTree64Base *Field; // rbx
  UFG::qTree64Base::BaseNode *v16; // rcx
  UFG::qString result; // [rsp+28h] [rbp-50h] BYREF
  DNA::PropertyBag *v; // [rsp+80h] [rbp+8h] BYREF

  v2 = propertyBag;
  mReflectionField = this->mSchemaField->mReflectionField;
  v4 = 0;
  while ( v2 )
  {
    if ( !mReflectionField )
      break;
    SchemaType = DNA::PropertyBag::GetSchemaType(v2);
    if ( !SchemaType )
      break;
    if ( !SchemaType[3].mCount )
      break;
    mReflectionField = 0i64;
    Owner = DNA::PropertyBag::GetOwner(v2);
    v7 = (DNA::PropertyBag *)Owner;
    if ( !Owner )
      break;
    for ( i = (UFG::qBaseTreeRB *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&Owner->mCount);
          ;
          i = UFG::qBaseTreeRB::GetNext(&v7->mProperties.mTree, &v9->mNode) )
    {
      v9 = (DNA::PropertyData *)i;
      if ( !i )
        break;
      if ( LODWORD(i[1].mRoot.mParent) == -915936389 )
      {
        v10 = DNA::PropertyData::NumItems((DNA::PropertyData *)i);
        v11 = 0;
        if ( v10 )
        {
          while ( 1 )
          {
            v = 0i64;
            DNA::PropertyData::Get(v9, v11, (UFG::qTree64Base **)&v);
            if ( v == v2 )
              break;
            if ( ++v11 >= v10 )
              goto LABEL_12;
          }
          mData = DNA::PropertyData::GetName(v9, &result)->mData;
          v13 = DNA::PropertyBag::GetSchemaType(v7);
          v14 = UFG::qStringHash64(mData, 0xFFFFFFFFFFFFFFFFui64);
          Field = DNA::SchemaType::GetField((DNA::SchemaType *)v13, v14);
          UFG::qString::~qString(&result);
          v16 = Field[4].mHead.mNeighbours[0];
          if ( !v4 || ((__int64)v16[2].mChildren[0] & 0x12) == 18 )
          {
            v4 = ((__int64)v16[2].mChildren[0] & 0x12) == 18;
            mReflectionField = (UFG::qReflectField *)Field[4].mHead.mNeighbours[0];
            v2 = v7;
          }
          break;
        }
      }
LABEL_12:
      ;
    }
  }
  return v2;
}

// File Line: 301
// RVA: 0x1ACC80
void __fastcall DNA::PropertyWrapper::SetArrayLength(
        DNA::PropertyWrapper *this,
        unsigned int array_size,
        DNA::PropertyBag *propertyBag)
{
  unsigned int v4; // esi
  DNA::SchemaField *mSchemaField; // rcx
  DNA::PropertyType::Enum mType; // eax
  unsigned int size; // edi
  UFG::qTree64Base *TypeSchema; // r13
  UFG::qTree64Base *SchemaType; // rax
  unsigned __int64 v11; // rsi
  unsigned __int64 v12; // rdi
  UFG::ReflectionDB *v13; // rax
  DNA::PropertyBag *v14; // rax
  DNA::PropertyBagWrapper *v15; // rdi
  __int64 v16; // r13
  unsigned int v17; // esi
  unsigned int capacity; // edx
  unsigned int v19; // edx
  unsigned int v20; // esi
  unsigned int v21; // edi
  __int64 v22; // r13
  __int64 i; // r12
  DNA::SchemaField *v24; // rax
  const char *v25; // rdi
  DNA::Database *v26; // rax
  UFG::qString *p_result; // rcx
  const char *v28; // rdi
  DNA::Database *v29; // rax
  DNA::PropertyBag **TopLevelObject; // r13
  unsigned int mArrayLength; // r12d
  unsigned int j; // edi
  DNA::PropertyBag *v33; // rsi
  unsigned int v34; // r12d
  unsigned int k; // edi
  DNA::PropertyBag *v36; // r12
  UFG::qTree64Base *Owner; // rax
  UFG::qString *v38; // rax
  DNA::Database *v39; // rax
  UFG::qTree64Base *Schema; // rax
  __int64 mCount; // rax
  unsigned int v42; // edi
  DNA::PropertyInfo info; // [rsp+30h] [rbp-59h] BYREF
  UFG::qTree64Base *p_mParent; // [rsp+48h] [rbp-41h]
  UFG::qString result; // [rsp+50h] [rbp-39h] BYREF
  UFG::qString v46; // [rsp+78h] [rbp-11h] BYREF
  __int64 v47; // [rsp+A0h] [rbp+17h]
  DNA::PropertyBag *propertyBaga; // [rsp+F0h] [rbp+67h] BYREF
  unsigned int v49; // [rsp+F8h] [rbp+6Fh]
  DNA::PropertyBag *v; // [rsp+108h] [rbp+7Fh] BYREF

  v49 = array_size;
  v47 = -2i64;
  v4 = array_size;
  mSchemaField = this->mSchemaField;
  mType = mSchemaField->mType;
  if ( mType == -915936389 )
  {
    if ( DNA::SchemaField::GetTypeSchema(mSchemaField) )
    {
      size = this->mPropertyBagWrapperValues.size;
      LODWORD(propertyBaga) = size;
      if ( size < v4 )
      {
        do
        {
          TypeSchema = DNA::SchemaField::GetTypeSchema(this->mSchemaField);
          if ( (unsigned int)(DNA::PropertyBag::GetPropertyState(propertyBag, this->mSchemaField->mName.mData, size) - 1) <= 1 )
          {
            v = 0i64;
            DNA::PropertyBag::Get(propertyBag, this->mSchemaField->mName.mData, (UFG::qTree64Base **)&v, size);
            SchemaType = DNA::PropertyBag::GetSchemaType(v);
            p_mParent = SchemaType;
            if ( SchemaType )
            {
              v11 = *(_QWORD *)TypeSchema[3].mCount;
              v12 = *(_QWORD *)SchemaType[3].mCount;
              v13 = UFG::ReflectionDB::Instance();
              if ( UFG::ReflectionDB::IsDerivedFrom(v13, v12, v11) == 1 )
                TypeSchema = p_mParent;
            }
          }
          v14 = (DNA::PropertyBag *)UFG::qMalloc(0x28ui64, UFG::gGlobalNewName, 0i64);
          v15 = (DNA::PropertyBagWrapper *)v14;
          v = v14;
          if ( v14 )
          {
            v14->mBaseNode.mUID = (unsigned __int64)TypeSchema;
            p_mParent = (UFG::qTree64Base *)&v14->mBaseNode.mParent;
            v14->mBaseNode.mParent = (UFG::qTree64Base::BaseNode *)&v14->mBaseNode.mParent;
            v14->mBaseNode.mChildren[0] = (UFG::qTree64Base::BaseNode *)&v14->mBaseNode.mParent;
            v14->mBaseNode.mNeighbours[0] = 0i64;
            v14->mBaseNode.mChildren[1] = 0i64;
            DNA::PropertyBagWrapper::AddSchemaFields(
              (DNA::PropertyBagWrapper *)v14,
              (DNA::SchemaType *)v14->mBaseNode.mUID);
          }
          else
          {
            v15 = 0i64;
          }
          v16 = this->mPropertyBagWrapperValues.size;
          v17 = v16 + 1;
          capacity = this->mPropertyBagWrapperValues.capacity;
          if ( (int)v16 + 1 > capacity )
          {
            if ( capacity )
              v19 = 2 * capacity;
            else
              v19 = 1;
            for ( ; v19 < v17; v19 *= 2 )
              ;
            if ( v19 <= 2 )
              v19 = 2;
            if ( v19 - v17 > 0x10000 )
              v19 = v16 + 65537;
            UFG::qArray<UFG::CompositeDrawableComponent *,32>::Reallocate(
              (UFG::qArray<UFG::qReflectInventoryBase *,0> *)&this->mPropertyBagWrapperValues,
              v19,
              "qArray.Add");
          }
          this->mPropertyBagWrapperValues.size = v17;
          this->mPropertyBagWrapperValues.p[v16] = v15;
          size = (_DWORD)propertyBaga + 1;
          LODWORD(propertyBaga) = size;
        }
        while ( size < v49 );
      }
      v20 = 0;
      v21 = v49;
      if ( v49 )
      {
        v22 = 0i64;
        for ( i = 0i64; ; ++i )
        {
          memset(&info, 0, sizeof(info));
          propertyBaga = 0i64;
          DNA::PropertyBag::GetPropertyInfo(propertyBag, this->mSchemaField->mName.mData, &info);
          if ( v20 >= info.Size )
            break;
          v24 = this->mSchemaField;
          if ( info.States.p[i] == Inherited )
          {
            UFG::qString::FormatEx(&result, "%s.Value", v24->mName.mData);
            v25 = (const char *)DNA::SchemaField::GetTypeSchema(this->mSchemaField)[1].mHead.mChildren[0];
            DNA::Database::Instance();
            propertyBaga = DNA::Database::CreateBag(v26, result.mData, v25, propertyBag);
            DNA::PropertyBag::Get(propertyBag, this->mSchemaField->mName.mData, (UFG::qTree64Base **)&v, 0);
            DNA::PropertyBag::SetParent(propertyBaga, v);
            DNA::PropertyBag::Set(propertyBag, this->mSchemaField->mName.mData, propertyBaga, v20, 0);
            p_result = &result;
LABEL_30:
            UFG::qString::~qString(p_result);
            v21 = v49;
            goto LABEL_31;
          }
          DNA::PropertyBag::Get(propertyBag, v24->mName.mData, (UFG::qTree64Base **)&propertyBaga, v20);
LABEL_31:
          DNA::PropertyBagWrapper::AddPropertyBag(this->mPropertyBagWrapperValues.p[v22], propertyBaga);
          if ( info.States.p )
            operator delete[](info.States.p);
          info.States.p = 0i64;
          *(_QWORD *)&info.States.size = 0i64;
          ++v20;
          ++v22;
          if ( v20 >= v21 )
            return;
        }
        UFG::qString::FormatEx(&v46, "%s.Value", this->mSchemaField->mName.mData);
        v28 = (const char *)DNA::SchemaField::GetTypeSchema(this->mSchemaField)[1].mHead.mChildren[0];
        DNA::Database::Instance();
        propertyBaga = DNA::Database::CreateBag(v29, v46.mData, v28, propertyBag);
        DNA::PropertyBag::Append(propertyBag, this->mSchemaField->mName.mData, propertyBaga, 0);
        p_result = &v46;
        goto LABEL_30;
      }
    }
  }
  else if ( mType == 151281197 )
  {
    if ( DNA::SchemaField::GetAnnotation(mSchemaField, "AutoBindUID") )
    {
      memset(&info, 0, sizeof(info));
      DNA::PropertyBag::GetPropertyInfo(propertyBag, this->mSchemaField->mName.mData, &info);
      TopLevelObject = (DNA::PropertyBag **)DNA::PropertyWrapper::FindTopLevelObject(this, propertyBag);
      mArrayLength = this->mSchemaField->mReflectionField->mArrayLength;
      for ( j = 0; j < mArrayLength; ++j )
      {
        v = *TopLevelObject;
        DNA::SchemaField::GetDefaultValue(this->mSchemaField, (unsigned __int64 *)&propertyBaga);
        DNA::PropertyWrapper::SetValueInternal<unsigned __int64>(
          this,
          j,
          (unsigned __int64 *)&v,
          (unsigned __int64 *)&propertyBaga,
          0);
      }
      if ( info.States.p )
        operator delete[](info.States.p);
      info.States.p = 0i64;
      *(_QWORD *)&info.States.size = 0i64;
    }
    if ( DNA::SchemaField::GetAnnotation(this->mSchemaField, "AutoBindType") )
    {
      memset(&info, 0, sizeof(info));
      DNA::PropertyBag::GetPropertyInfo(propertyBag, this->mSchemaField->mName.mData, &info);
      if ( !info.Size || *info.States.p == Inherited )
      {
        v33 = DNA::PropertyWrapper::FindTopLevelObject(this, propertyBag);
        v34 = this->mSchemaField->mReflectionField->mArrayLength;
        for ( k = 0; k < v34; ++k )
        {
          DNA::PropertyBag::GetSchemaName(v33, &v46);
          DNA::PropertyBag::GetSchemaType(v33);
          v = (DNA::PropertyBag *)DNA::PropertyBag::GetSchemaType(v33)->mHead.mUID;
          DNA::SchemaField::GetDefaultValue(this->mSchemaField, (unsigned __int64 *)&propertyBaga);
          DNA::PropertyWrapper::SetValueInternal<unsigned __int64>(
            this,
            k,
            (unsigned __int64 *)&v,
            (unsigned __int64 *)&propertyBaga,
            0);
          UFG::qString::~qString(&v46);
        }
        v4 = v49;
      }
      if ( info.States.p )
        operator delete[](info.States.p);
      info.States.p = 0i64;
      *(_QWORD *)&info.States.size = 0i64;
    }
    if ( DNA::SchemaField::GetAnnotation(this->mSchemaField, "AutoBindHandleType") )
    {
      memset(&info, 0, sizeof(info));
      DNA::PropertyBag::GetPropertyInfo(propertyBag, this->mSchemaField->mName.mData, &info);
      if ( !info.Size || *info.States.p == Inherited )
      {
        v36 = (DNA::PropertyBag *)UFG::qStringHash64("UFG::qReflectObject", 0xFFFFFFFFFFFFFFFFui64);
        Owner = DNA::PropertyBag::GetOwner(propertyBag);
        if ( Owner )
        {
          DNA::PropertyBag::GetSchemaName((DNA::PropertyBag *)Owner, &result);
          if ( UFG::qString::StartsWith(&result, "UFG::qReflectHandle", -1) )
          {
            UFG::qString::ReplaceString(&result, "UFG::qReflectHandle<", &customCaption, 0);
            UFG::qString::ReplaceString(&result, ">", &customCaption, 0);
            v38 = UFG::qString::Trim(&result, &v46);
            UFG::qString::Set(&result, v38->mData, v38->mLength, 0i64, 0);
            UFG::qString::~qString(&v46);
            DNA::Database::Instance();
            Schema = DNA::Database::GetSchema(v39, result.mData);
            if ( Schema )
            {
              mCount = Schema[3].mCount;
              if ( mCount )
                v36 = *(DNA::PropertyBag **)(mCount + 72);
            }
          }
          UFG::qString::~qString(&result);
        }
        v42 = 0;
        if ( v4 )
        {
          v = v36;
          do
          {
            DNA::SchemaField::GetDefaultValue(this->mSchemaField, (unsigned __int64 *)&propertyBaga);
            DNA::PropertyWrapper::SetValueInternal<unsigned __int64>(
              this,
              v42++,
              (unsigned __int64 *)&v,
              (unsigned __int64 *)&propertyBaga,
              0);
          }
          while ( v42 < v4 );
        }
      }
      if ( info.States.p )
        operator delete[](info.States.p);
    }
  }
}

// File Line: 444
// RVA: 0x1ACB00
void __fastcall DNA::PropertyWrapper::Set(DNA::PropertyWrapper *this, unsigned int index, char *v, unsigned int undoId)
{
  char *va; // [rsp+40h] [rbp+8h] BYREF
  char *value; // [rsp+50h] [rbp+18h] BYREF

  value = v;
  DNA::SchemaField::GetDefaultValue(this->mSchemaField, &va);
  DNA::PropertyWrapper::SetValueInternal<char const *>(this, index, (const char **)&value, (const char **)&va, undoId);
}

// File Line: 445
// RVA: 0x1AC9B0
void __fastcall DNA::PropertyWrapper::Set(DNA::PropertyWrapper *this, unsigned int index, int v, unsigned int undoId)
{
  int va; // [rsp+40h] [rbp+8h] BYREF
  int value; // [rsp+50h] [rbp+18h] BYREF

  value = v;
  DNA::SchemaField::GetDefaultValue(this->mSchemaField, &va);
  DNA::PropertyWrapper::SetValueInternal<long>(this, index, &value, &va, undoId);
}

// File Line: 446
// RVA: 0x1ACB60
void __fastcall DNA::PropertyWrapper::Set(
        DNA::PropertyWrapper *this,
        unsigned int index,
        __int64 v,
        unsigned int undoId)
{
  __int64 va; // [rsp+40h] [rbp+8h] BYREF
  __int64 value; // [rsp+50h] [rbp+18h] BYREF

  value = v;
  DNA::SchemaField::GetDefaultValue(this->mSchemaField, &va);
  DNA::PropertyWrapper::SetValueInternal<__int64>(this, index, &value, &va, undoId);
}

// File Line: 447
// RVA: 0x1ACA10
void __fastcall DNA::PropertyWrapper::Set(
        DNA::PropertyWrapper *this,
        unsigned int index,
        unsigned int v,
        unsigned int undoId)
{
  unsigned int va; // [rsp+40h] [rbp+8h] BYREF
  unsigned int value; // [rsp+50h] [rbp+18h] BYREF

  value = v;
  DNA::SchemaField::GetDefaultValue(this->mSchemaField, &va);
  DNA::PropertyWrapper::SetValueInternal<unsigned long>(this, index, &value, &va, undoId);
}

// File Line: 448
// RVA: 0x1ACBC0
void __fastcall DNA::PropertyWrapper::Set(
        DNA::PropertyWrapper *this,
        unsigned int index,
        unsigned __int64 v,
        unsigned int undoId)
{
  unsigned __int64 va; // [rsp+40h] [rbp+8h] BYREF
  unsigned __int64 value; // [rsp+50h] [rbp+18h] BYREF

  value = v;
  DNA::SchemaField::GetDefaultValue(this->mSchemaField, &va);
  DNA::PropertyWrapper::SetValueInternal<unsigned __int64>(this, index, &value, &va, undoId);
}

// File Line: 449
// RVA: 0x1ACC20
void __fastcall DNA::PropertyWrapper::Set(DNA::PropertyWrapper *this, unsigned int index, bool v, unsigned int undoId)
{
  bool va; // [rsp+40h] [rbp+8h] BYREF
  bool value; // [rsp+50h] [rbp+18h] BYREF

  value = v;
  DNA::SchemaField::GetDefaultValue(this->mSchemaField, &va);
  DNA::PropertyWrapper::SetValueInternal<bool>(this, index, &value, &va, undoId);
}

// File Line: 450
// RVA: 0x1ACA70
void __fastcall DNA::PropertyWrapper::Set(DNA::PropertyWrapper *this, unsigned int index, float v, unsigned int undoId)
{
  float va; // [rsp+40h] [rbp+8h] BYREF
  float value; // [rsp+50h] [rbp+18h] BYREF

  value = v;
  DNA::SchemaField::GetDefaultValue(this->mSchemaField, &va);
  DNA::PropertyWrapper::SetValueInternal<float>(this, index, &value, &va, undoId);
}

// File Line: 451
// RVA: 0x1ACAD0
void __fastcall DNA::PropertyWrapper::Set(
        DNA::PropertyWrapper *this,
        unsigned int index,
        DNA::PropertyBag *v,
        unsigned int undoId)
{
  DNA::PropertyBag *default_value; // [rsp+50h] [rbp+18h] BYREF

  default_value = v;
  DNA::PropertyWrapper::SetValueInternal<DNA::PropertyBag *>(this, index, &default_value, &default_value, undoId);
}

// File Line: 453
// RVA: 0x1AC710
// attributes: thunk
void __fastcall DNA::PropertyWrapper::Get(
        DNA::PropertyWrapper *this,
        unsigned int index,
        UFG::qString *v,
        unsigned int undoId)
{
  DNA::PropertyWrapper::GetValueInternal<UFG::qString>(this, index, v);
}

// File Line: 454
// RVA: 0x1AC6E0
// attributes: thunk
void __fastcall DNA::PropertyWrapper::Get(DNA::PropertyWrapper *this, unsigned int index, int *v, unsigned int undoId)
{
  DNA::PropertyWrapper::GetValueInternal<long>(this, index, v);
}

// File Line: 455
// RVA: 0x1AC720
// attributes: thunk
void __fastcall DNA::PropertyWrapper::Get(
        DNA::PropertyWrapper *this,
        unsigned int index,
        __int64 *v,
        unsigned int undoId)
{
  DNA::PropertyWrapper::GetValueInternal<__int64>(this, index, v);
}

// File Line: 456
// RVA: 0x1AC6F0
// attributes: thunk
void __fastcall DNA::PropertyWrapper::Get(
        DNA::PropertyWrapper *this,
        unsigned int index,
        unsigned int *v,
        unsigned int undoId)
{
  DNA::PropertyWrapper::GetValueInternal<unsigned long>(this, index, v);
}

// File Line: 457
// RVA: 0x1AC730
// attributes: thunk
void __fastcall DNA::PropertyWrapper::Get(
        DNA::PropertyWrapper *this,
        unsigned int index,
        unsigned __int64 *v,
        unsigned int undoId)
{
  DNA::PropertyWrapper::GetValueInternal<unsigned __int64>(this, index, v);
}

// File Line: 458
// RVA: 0x1AC740
// attributes: thunk
void __fastcall DNA::PropertyWrapper::Get(DNA::PropertyWrapper *this, unsigned int index, bool *v, unsigned int undoId)
{
  DNA::PropertyWrapper::GetValueInternal<bool>(this, index, v);
}

// File Line: 459
// RVA: 0x1AC700
// attributes: thunk
void __fastcall DNA::PropertyWrapper::Get(
        DNA::PropertyWrapper *this,
        unsigned int index,
        float *v,
        unsigned int undoId)
{
  DNA::PropertyWrapper::GetValueInternal<float>(this, index, v);
}

// File Line: 461
// RVA: 0x1AC750
void __fastcall DNA::PropertyWrapper::Get(
        DNA::PropertyWrapper *this,
        unsigned int index,
        DNA::PropertyBagWrapper **v,
        unsigned int undoId)
{
  unsigned int size; // ecx
  __int64 v7; // rbp
  unsigned int v8; // ebx
  unsigned int v9; // edx
  __int64 v10; // rcx
  DNA::PropertyBagWrapper *mPropertyBagWrapper; // rsi

  size = this->mPropertyBagWrapperValues.size;
  v7 = index;
  if ( index >= size )
  {
    v8 = 0;
    if ( this->mSchemaField->mArrayLength >= 0 )
    {
      *v = 0i64;
    }
    else
    {
      v9 = 0;
      if ( size )
      {
        do
        {
          v10 = v9++;
          this->mPropertyBagWrapperValues.p[v10]->mPropertyBags.size = 0;
        }
        while ( v9 < this->mPropertyBagWrapperValues.size );
      }
      mPropertyBagWrapper = this->mPropertyBagWrapper;
      if ( mPropertyBagWrapper->mPropertyBags.size )
      {
        do
          DNA::PropertyWrapper::SetArrayLength(this, v7 + 1, mPropertyBagWrapper->mPropertyBags.p[v8++]);
        while ( v8 < mPropertyBagWrapper->mPropertyBags.size );
      }
      *v = this->mPropertyBagWrapperValues.p[v7];
    }
  }
  else
  {
    *v = this->mPropertyBagWrapperValues.p[index];
  }
}

