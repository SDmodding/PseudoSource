// File Line: 21
// RVA: 0x1AC1B0
void __fastcall DNA::PropertyBagWrapper::PropertyBagWrapper(DNA::PropertyBagWrapper *this, DNA::SchemaType *schema)
{
  UFG::qList<DNA::PropertyWrapper,DNA::PropertyWrapper,1,0> *v2; // [rsp+48h] [rbp+10h]

  this->mSchema = schema;
  v2 = &this->mProperties;
  v2->mNode.mPrev = &v2->mNode;
  v2->mNode.mNext = &v2->mNode;
  this->mPropertyBags.p = 0i64;
  *(_QWORD *)&this->mPropertyBags.size = 0i64;
  DNA::PropertyBagWrapper::AddSchemaFields(this, this->mSchema);
}

// File Line: 28
// RVA: 0x1AC140
void __fastcall DNA::PropertyBagWrapper::PropertyBagWrapper(DNA::PropertyBagWrapper *this, DNA::PropertyBag *propertyBag)
{
  DNA::PropertyBag *v2; // rbx
  DNA::PropertyBagWrapper *v3; // rdi
  UFG::qList<DNA::PropertyWrapper,DNA::PropertyWrapper,1,0> *v4; // [rsp+50h] [rbp+18h]

  v2 = propertyBag;
  v3 = this;
  this->mSchema = (DNA::SchemaType *)DNA::PropertyBag::GetSchemaType(propertyBag);
  v4 = &v3->mProperties;
  v4->mNode.mPrev = &v4->mNode;
  v4->mNode.mNext = &v4->mNode;
  v3->mPropertyBags.p = 0i64;
  *(_QWORD *)&v3->mPropertyBags.size = 0i64;
  DNA::PropertyBagWrapper::AddSchemaFields(v3, v3->mSchema);
  DNA::PropertyBagWrapper::AddPropertyBag(v3, v2);
}

// File Line: 34
// RVA: 0x1AC240
void __fastcall DNA::PropertyBagWrapper::~PropertyBagWrapper(DNA::PropertyBagWrapper *this)
{
  DNA::PropertyBagWrapper *v1; // rbx
  DNA::PropertyBag **v2; // rcx
  UFG::qList<DNA::PropertyWrapper,DNA::PropertyWrapper,1,0> *v3; // rbx

  v1 = this;
  v2 = this->mPropertyBags.p;
  if ( v2 )
    operator delete[](v2);
  v1->mPropertyBags.p = 0i64;
  *(_QWORD *)&v1->mPropertyBags.size = 0i64;
  v3 = &v1->mProperties;
  UFG::qList<DNA::PropertyWrapper,DNA::PropertyWrapper,1,0>::DeleteNodes(v3);
  UFG::qNode<UFG::DoorComponent,UFG::DoorComponent>::~qNode<UFG::DoorComponent,UFG::DoorComponent>((UFG::qNode<UFG::qString,UFG::qString> *)v3);
}

// File Line: 37
// RVA: 0x1AC450
void __fastcall DNA::PropertyBagWrapper::AddSchemaFields(DNA::PropertyBagWrapper *this, DNA::SchemaType *schema)
{
  DNA::PropertyBagWrapper *v2; // rbp
  DNA::SchemaType *v3; // rbx
  UFG::qList<DNA::SchemaField,DNA::SchemaField,1,0> *v4; // rsi
  UFG::allocator::free_link *v5; // rdi
  UFG::allocator::free_link *v6; // rax
  UFG::allocator::free_link *v7; // rcx

  v2 = this;
  v3 = (DNA::SchemaType *)schema->mOrderedFields.mNode.mNext;
  v4 = &schema->mOrderedFields;
  if ( v3 != (DNA::SchemaType *)&schema->mOrderedFields )
  {
    v5 = (UFG::allocator::free_link *)&this->mProperties;
    do
    {
      v6 = UFG::qMalloc(0x30ui64, UFG::gGlobalNewName, 0i64);
      if ( v6 )
      {
        v6->mNext = v6;
        v6[1].mNext = v6;
        v6[2].mNext = (UFG::allocator::free_link *)v2;
        v6[3].mNext = (UFG::allocator::free_link *)v3;
        v6[5].mNext = 0i64;
        v6[4].mNext = 0i64;
      }
      else
      {
        v6 = 0i64;
      }
      v7 = v5->mNext;
      v7[1].mNext = v6;
      v6->mNext = v7;
      v6[1].mNext = v5;
      v5->mNext = v6;
      v3 = (DNA::SchemaType *)v3->mBaseNode.mParent;
    }
    while ( v3 != (DNA::SchemaType *)v4 );
  }
}

// File Line: 45
// RVA: 0x1AC810
DNA::PropertyWrapper *__fastcall DNA::PropertyBagWrapper::GetProperty(DNA::PropertyBagWrapper *this, const char *propertyName)
{
  DNA::PropertyWrapper *v2; // rbx
  unsigned __int64 v3; // rdx
  DNA::PropertyWrapper *result; // rax

  v2 = (DNA::PropertyWrapper *)&this->mProperties;
  v3 = UFG::qStringHash64(propertyName, 0xFFFFFFFFFFFFFFFFui64);
  result = (DNA::PropertyWrapper *)v2->mNext;
  if ( result == v2 )
    return 0i64;
  while ( result->mSchemaField->mBaseNode.mUID != v3 )
  {
    result = (DNA::PropertyWrapper *)result->mNext;
    if ( result == v2 )
      return 0i64;
  }
  return result;
}

// File Line: 81
// RVA: 0x1AC350
void __fastcall DNA::PropertyBagWrapper::AddPropertyBag(DNA::PropertyBagWrapper *this, DNA::PropertyBag *propertyBag)
{
  DNA::PropertyBag *v2; // rdi
  unsigned int v3; // edx
  unsigned int v4; // eax
  DNA::PropertyBagWrapper *v5; // r14
  DNA::PropertyBag **v6; // r8
  unsigned int v7; // edx
  __int64 v8; // rbp
  unsigned int v9; // ebx
  unsigned int v10; // edx
  DNA::PropertyBag **v11; // rax
  DNA::PropertyWrapper *i; // rbx
  signed int v13; // edx

  v2 = propertyBag;
  v3 = this->mPropertyBags.size;
  v4 = 0;
  v5 = this;
  if ( !v3 )
    goto LABEL_7;
  v6 = this->mPropertyBags.p;
  while ( v2 != *v6 )
  {
    ++v4;
    ++v6;
    if ( v4 >= v3 )
      goto LABEL_7;
  }
  if ( v4 == -1 )
  {
LABEL_7:
    v2->mIsDirtyLock = 1;
    v7 = this->mPropertyBags.capacity;
    v8 = this->mPropertyBags.size;
    v9 = v8 + 1;
    if ( (signed int)v8 + 1 > v7 )
    {
      if ( v7 )
        v10 = 2 * v7;
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
    v11 = v5->mPropertyBags.p;
    v5->mPropertyBags.size = v9;
    v11[v8] = v2;
    for ( i = (DNA::PropertyWrapper *)v5->mProperties.mNode.mNext;
          i != (DNA::PropertyWrapper *)&v5->mProperties;
          i = (DNA::PropertyWrapper *)i->mNext )
    {
      v13 = i->mSchemaField->mArrayLength;
      if ( v13 > 0 )
        DNA::PropertyWrapper::SetArrayLength(i, v13, v2);
    }
    v2->mIsDirtyLock = 0;
  }
}

// File Line: 140
// RVA: 0x1AC290
void __fastcall DNA::PropertyWrapper::~PropertyWrapper(DNA::PropertyWrapper *this)
{
  DNA::PropertyWrapper *v1; // rdi
  unsigned int v2; // esi
  DNA::PropertyBagWrapper *v3; // rbx
  DNA::PropertyBag **v4; // rcx
  DNA::PropertyBagWrapper **v5; // rcx
  DNA::PropertyBagWrapper **v6; // rcx
  UFG::qNode<DNA::PropertyWrapper,DNA::PropertyWrapper> *v7; // rcx
  UFG::qNode<DNA::PropertyWrapper,DNA::PropertyWrapper> *v8; // rax

  v1 = this;
  v2 = 0;
  if ( this->mPropertyBagWrapperValues.size )
  {
    do
    {
      v3 = v1->mPropertyBagWrapperValues.p[v2];
      if ( v3 )
      {
        v4 = v3->mPropertyBags.p;
        if ( v4 )
          operator delete[](v4);
        v3->mPropertyBags.p = 0i64;
        *(_QWORD *)&v3->mPropertyBags.size = 0i64;
        UFG::qList<DNA::PropertyWrapper,DNA::PropertyWrapper,1,0>::~qList<DNA::PropertyWrapper,DNA::PropertyWrapper,1,0>(&v3->mProperties);
        operator delete[](v3);
      }
      ++v2;
    }
    while ( v2 < v1->mPropertyBagWrapperValues.size );
  }
  v5 = v1->mPropertyBagWrapperValues.p;
  if ( v5 )
    operator delete[](v5);
  v1->mPropertyBagWrapperValues.p = 0i64;
  *(_QWORD *)&v1->mPropertyBagWrapperValues.size = 0i64;
  v6 = v1->mPropertyBagWrapperValues.p;
  if ( v6 )
    operator delete[](v6);
  v1->mPropertyBagWrapperValues.p = 0i64;
  *(_QWORD *)&v1->mPropertyBagWrapperValues.size = 0i64;
  v7 = v1->mPrev;
  v8 = v1->mNext;
  v7->mNext = v8;
  v8->mPrev = v7;
  v1->mPrev = (UFG::qNode<DNA::PropertyWrapper,DNA::PropertyWrapper> *)&v1->mPrev;
  v1->mNext = (UFG::qNode<DNA::PropertyWrapper,DNA::PropertyWrapper> *)&v1->mPrev;
}

// File Line: 149
// RVA: 0x1AC860
DNA::PropertyInfo *__fastcall DNA::PropertyWrapper::GetPropertyInfo(DNA::PropertyWrapper *this, DNA::PropertyInfo *result)
{
  DNA::PropertyInfo *v2; // rbx
  DNA::PropertyWrapper *v3; // rsi
  unsigned int v4; // edi
  DNA::PropertyBagWrapper *v5; // rcx
  signed int v6; // ecx
  unsigned int v8; // ecx
  DNA::PropertyInfo info; // [rsp+30h] [rbp-38h]

  v2 = result;
  v3 = this;
  *(_QWORD *)&result->Type = 0i64;
  result->States.p = 0i64;
  *(_QWORD *)&result->States.size = 0i64;
  v4 = 1;
  result->Type = this->mSchemaField->mType;
  result->Size = 0;
  v5 = this->mPropertyBagWrapper;
  if ( v5->mPropertyBags.size )
  {
    DNA::PropertyBag::GetPropertyInfo(*v5->mPropertyBags.p, v3->mSchemaField->mName.mData, result);
    v6 = v3->mSchemaField->mArrayLength;
    if ( v6 >= 2 )
    {
      if ( v6 != -1 )
      {
        if ( (signed int)v2->Size > v6 )
          goto LABEL_5;
        return v2;
      }
    }
    else if ( v6 != -1 )
    {
      if ( (signed int)v2->Size <= v6 )
        return v2;
LABEL_5:
      v2->Size = v6;
      return v2;
    }
    if ( v3->mPropertyBagWrapper->mPropertyBags.size > 1 )
    {
      do
      {
        *(_QWORD *)&info.Type = 0i64;
        info.States.p = 0i64;
        *(_QWORD *)&info.States.size = 0i64;
        DNA::PropertyBag::GetPropertyInfo(
          v3->mPropertyBagWrapper->mPropertyBags.p[v4],
          v3->mSchemaField->mName.mData,
          &info);
        v8 = info.Size;
        if ( v2->Size > info.Size )
        {
          v2->Type = info.Type;
          v2->Size = v8;
          UFG::qArray<enum  DNA::PropertyState::Enum,0>::Clone(
            (UFG::qArray<unsigned long,0> *)&info.States,
            (UFG::qArray<unsigned long,0> *)&v2->States);
        }
        if ( info.States.p )
          operator delete[](info.States.p);
        info.States.p = 0i64;
        *(_QWORD *)&info.States.size = 0i64;
        ++v4;
      }
      while ( v4 < v3->mPropertyBagWrapper->mPropertyBags.size );
    }
    return v2;
  }
  return result;
}

// File Line: 234
// RVA: 0x1AC560
DNA::PropertyBag *__fastcall DNA::PropertyWrapper::FindTopLevelObject(DNA::PropertyWrapper *this, DNA::PropertyBag *propertyBag)
{
  DNA::PropertyBag *v2; // rbp
  UFG::qReflectField *v3; // r12
  bool v4; // r13
  UFG::qTree64Base *v5; // rax
  UFG::qTree64Base *v6; // rax
  DNA::PropertyBag *v7; // r15
  UFG::qBaseTreeRB *i; // rax
  DNA::PropertyData *v9; // rdi
  unsigned int v10; // esi
  unsigned int v11; // ebx
  char *v12; // rbx
  UFG::qTree64Base *v13; // rdi
  unsigned __int64 v14; // rax
  UFG::qTree64Base *v15; // rbx
  UFG::qTree64Base::BaseNode *v16; // rcx
  UFG::qString result; // [rsp+28h] [rbp-50h]
  DNA::PropertyBag *v; // [rsp+80h] [rbp+8h]

  v2 = propertyBag;
  v3 = this->mSchemaField->mReflectionField;
  v4 = 0;
  while ( v2 )
  {
    if ( !v3 )
      break;
    v5 = DNA::PropertyBag::GetSchemaType(v2);
    if ( !v5 )
      break;
    if ( !v5[3].mCount )
      break;
    v3 = 0i64;
    v6 = DNA::PropertyBag::GetOwner(v2);
    v7 = (DNA::PropertyBag *)v6;
    if ( !v6 )
      break;
    for ( i = (UFG::qBaseTreeRB *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&v6->mCount);
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
            DNA::PropertyData::Get(v9, v11, &v);
            if ( v == v2 )
              break;
            if ( ++v11 >= v10 )
              goto LABEL_12;
          }
          v12 = DNA::PropertyData::GetName(v9, &result)->mData;
          v13 = DNA::PropertyBag::GetSchemaType(v7);
          v14 = UFG::qStringHash64(v12, 0xFFFFFFFFFFFFFFFFui64);
          v15 = DNA::SchemaType::GetField((DNA::SchemaType *)v13, v14);
          UFG::qString::~qString(&result);
          v16 = v15[4].mHead.mNeighbours[0];
          if ( !v4 || ((_QWORD)v16[2].mChildren[0] & 0x12) == 18 )
          {
            v4 = ((_QWORD)v16[2].mChildren[0] & 0x12) == 18;
            v3 = (UFG::qReflectField *)v15[4].mHead.mNeighbours[0];
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
void __fastcall DNA::PropertyWrapper::SetArrayLength(DNA::PropertyWrapper *this, unsigned int array_size, DNA::PropertyBag *propertyBag)
{
  DNA::PropertyBag *v3; // r15
  unsigned int v4; // esi
  DNA::PropertyWrapper *v5; // r14
  DNA::SchemaField *v6; // rcx
  DNA::PropertyType::Enum v7; // eax
  unsigned int v8; // edi
  UFG::qTree64Base *v9; // r13
  UFG::qTree64Base *v10; // rax
  unsigned __int64 v11; // rsi
  unsigned __int64 v12; // rdi
  UFG::ReflectionDB *v13; // rax
  DNA::PropertyBag *v14; // rax
  DNA::PropertyBag *v15; // rdi
  UFG::qTree64Base::BaseNode **v16; // rcx
  __int64 v17; // r13
  unsigned int v18; // esi
  unsigned int v19; // edx
  unsigned int v20; // edx
  unsigned int v21; // esi
  unsigned int v22; // edi
  __int64 v23; // r13
  __int64 v24; // r12
  DNA::SchemaField *v25; // rax
  const char *v26; // rdi
  DNA::Database *v27; // rax
  UFG::qString *v28; // rcx
  const char *v29; // rdi
  DNA::Database *v30; // rax
  DNA::PropertyBag **v31; // r13
  unsigned int v32; // er12
  unsigned int v33; // edi
  DNA::PropertyBag *v34; // rsi
  unsigned int v35; // er12
  unsigned int v36; // edi
  DNA::PropertyBag *v37; // r12
  UFG::qTree64Base *v38; // rax
  UFG::qString *v39; // rax
  DNA::Database *v40; // rax
  UFG::qTree64Base *v41; // rax
  __int64 v42; // rax
  unsigned int v43; // edi
  DNA::PropertyInfo info; // [rsp+30h] [rbp-59h]
  UFG::qTree64Base *v45; // [rsp+48h] [rbp-41h]
  UFG::qString result; // [rsp+50h] [rbp-39h]
  UFG::qString v47; // [rsp+78h] [rbp-11h]
  __int64 v48; // [rsp+A0h] [rbp+17h]
  DNA::PropertyBag *propertyBaga; // [rsp+F0h] [rbp+67h]
  unsigned int v50; // [rsp+F8h] [rbp+6Fh]
  DNA::PropertyBag *v; // [rsp+108h] [rbp+7Fh]

  v50 = array_size;
  v48 = -2i64;
  v3 = propertyBag;
  v4 = array_size;
  v5 = this;
  v6 = this->mSchemaField;
  v7 = v6->mType;
  if ( v7 == -915936389 )
  {
    if ( DNA::SchemaField::GetTypeSchema(v6) )
    {
      v8 = v5->mPropertyBagWrapperValues.size;
      LODWORD(propertyBaga) = v8;
      if ( v8 < v4 )
      {
        do
        {
          v9 = DNA::SchemaField::GetTypeSchema(v5->mSchemaField);
          if ( (unsigned int)(DNA::PropertyBag::GetPropertyState(v3, v5->mSchemaField->mName.mData, v8) - 1) <= 1 )
          {
            v = 0i64;
            DNA::PropertyBag::Get(v3, v5->mSchemaField->mName.mData, &v, v8);
            v10 = DNA::PropertyBag::GetSchemaType(v);
            v45 = v10;
            if ( v10 )
            {
              v11 = *(_QWORD *)v9[3].mCount;
              v12 = *(_QWORD *)v10[3].mCount;
              v13 = UFG::ReflectionDB::Instance();
              if ( UFG::ReflectionDB::IsDerivedFrom(v13, v12, v11) == 1 )
                v9 = v45;
            }
          }
          v14 = (DNA::PropertyBag *)UFG::qMalloc(0x28ui64, UFG::gGlobalNewName, 0i64);
          v15 = v14;
          v = v14;
          if ( v14 )
          {
            v14->mBaseNode.mUID = (unsigned __int64)v9;
            v16 = &v14->mBaseNode.mParent;
            v45 = (UFG::qTree64Base *)v16;
            *v16 = (UFG::qTree64Base::BaseNode *)v16;
            v16[1] = (UFG::qTree64Base::BaseNode *)v16;
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
          v17 = v5->mPropertyBagWrapperValues.size;
          v18 = v17 + 1;
          v19 = v5->mPropertyBagWrapperValues.capacity;
          if ( (signed int)v17 + 1 > v19 )
          {
            if ( v19 )
              v20 = 2 * v19;
            else
              v20 = 1;
            for ( ; v20 < v18; v20 *= 2 )
              ;
            if ( v20 <= 2 )
              v20 = 2;
            if ( v20 - v18 > 0x10000 )
              v20 = v17 + 65537;
            UFG::qArray<UFG::CompositeDrawableComponent *,32>::Reallocate(
              (UFG::qArray<UFG::qReflectInventoryBase *,0> *)&v5->mPropertyBagWrapperValues,
              v20,
              "qArray.Add");
          }
          v5->mPropertyBagWrapperValues.size = v18;
          v5->mPropertyBagWrapperValues.p[v17] = (DNA::PropertyBagWrapper *)v15;
          v8 = (_DWORD)propertyBaga + 1;
          LODWORD(propertyBaga) = v8;
        }
        while ( v8 < v50 );
      }
      v21 = 0;
      v22 = v50;
      if ( v50 )
      {
        v23 = 0i64;
        v24 = 0i64;
        while ( 1 )
        {
          *(_QWORD *)&info.Type = 0i64;
          info.States.p = 0i64;
          *(_QWORD *)&info.States.size = 0i64;
          propertyBaga = 0i64;
          DNA::PropertyBag::GetPropertyInfo(v3, v5->mSchemaField->mName.mData, &info);
          if ( v21 >= info.Size )
            break;
          v25 = v5->mSchemaField;
          if ( info.States.p[v24] == 1 )
          {
            UFG::qString::FormatEx(&result, "%s.Value", v25->mName.mData);
            v26 = (const char *)DNA::SchemaField::GetTypeSchema(v5->mSchemaField)[1].mHead.mChildren[0];
            DNA::Database::Instance();
            propertyBaga = DNA::Database::CreateBag(v27, result.mData, v26, v3);
            DNA::PropertyBag::Get(v3, v5->mSchemaField->mName.mData, &v, 0);
            DNA::PropertyBag::SetParent(propertyBaga, v);
            DNA::PropertyBag::Set(v3, v5->mSchemaField->mName.mData, propertyBaga, v21, 0);
            v28 = &result;
LABEL_30:
            UFG::qString::~qString(v28);
            v22 = v50;
            goto LABEL_31;
          }
          DNA::PropertyBag::Get(v3, v25->mName.mData, &propertyBaga, v21);
LABEL_31:
          DNA::PropertyBagWrapper::AddPropertyBag(v5->mPropertyBagWrapperValues.p[v23], propertyBaga);
          if ( info.States.p )
            operator delete[](info.States.p);
          info.States.p = 0i64;
          *(_QWORD *)&info.States.size = 0i64;
          ++v21;
          ++v24;
          ++v23;
          if ( v21 >= v22 )
            return;
        }
        UFG::qString::FormatEx(&v47, "%s.Value", v5->mSchemaField->mName.mData);
        v29 = (const char *)DNA::SchemaField::GetTypeSchema(v5->mSchemaField)[1].mHead.mChildren[0];
        DNA::Database::Instance();
        propertyBaga = DNA::Database::CreateBag(v30, v47.mData, v29, v3);
        DNA::PropertyBag::Append(v3, v5->mSchemaField->mName.mData, propertyBaga, 0);
        v28 = &v47;
        goto LABEL_30;
      }
    }
  }
  else if ( v7 == 151281197 )
  {
    if ( DNA::SchemaField::GetAnnotation(v6, "AutoBindUID") )
    {
      *(_QWORD *)&info.Type = 0i64;
      info.States.p = 0i64;
      *(_QWORD *)&info.States.size = 0i64;
      DNA::PropertyBag::GetPropertyInfo(v3, v5->mSchemaField->mName.mData, &info);
      v31 = (DNA::PropertyBag **)DNA::PropertyWrapper::FindTopLevelObject(v5, v3);
      v32 = v5->mSchemaField->mReflectionField->mArrayLength;
      v33 = 0;
      if ( v32 )
      {
        do
        {
          v = *v31;
          DNA::SchemaField::GetDefaultValue(v5->mSchemaField, (unsigned __int64 *)&propertyBaga);
          DNA::PropertyWrapper::SetValueInternal<unsigned __int64>(
            v5,
            v33++,
            (unsigned __int64 *)&v,
            (unsigned __int64 *)&propertyBaga,
            0);
        }
        while ( v33 < v32 );
      }
      if ( info.States.p )
        operator delete[](info.States.p);
      info.States.p = 0i64;
      *(_QWORD *)&info.States.size = 0i64;
    }
    if ( DNA::SchemaField::GetAnnotation(v5->mSchemaField, "AutoBindType") )
    {
      *(_QWORD *)&info.Type = 0i64;
      info.States.p = 0i64;
      *(_QWORD *)&info.States.size = 0i64;
      DNA::PropertyBag::GetPropertyInfo(v3, v5->mSchemaField->mName.mData, &info);
      if ( !info.Size || *info.States.p == 1 )
      {
        v34 = DNA::PropertyWrapper::FindTopLevelObject(v5, v3);
        v35 = v5->mSchemaField->mReflectionField->mArrayLength;
        v36 = 0;
        if ( v35 )
        {
          do
          {
            DNA::PropertyBag::GetSchemaName(v34, &v47);
            DNA::PropertyBag::GetSchemaType(v34);
            v = (DNA::PropertyBag *)DNA::PropertyBag::GetSchemaType(v34)->mHead.mUID;
            DNA::SchemaField::GetDefaultValue(v5->mSchemaField, (unsigned __int64 *)&propertyBaga);
            DNA::PropertyWrapper::SetValueInternal<unsigned __int64>(
              v5,
              v36,
              (unsigned __int64 *)&v,
              (unsigned __int64 *)&propertyBaga,
              0);
            UFG::qString::~qString(&v47);
            ++v36;
          }
          while ( v36 < v35 );
        }
        v4 = v50;
      }
      if ( info.States.p )
        operator delete[](info.States.p);
      info.States.p = 0i64;
      *(_QWORD *)&info.States.size = 0i64;
    }
    if ( DNA::SchemaField::GetAnnotation(v5->mSchemaField, "AutoBindHandleType") )
    {
      *(_QWORD *)&info.Type = 0i64;
      info.States.p = 0i64;
      *(_QWORD *)&info.States.size = 0i64;
      DNA::PropertyBag::GetPropertyInfo(v3, v5->mSchemaField->mName.mData, &info);
      if ( !info.Size || *info.States.p == 1 )
      {
        v37 = (DNA::PropertyBag *)UFG::qStringHash64("UFG::qReflectObject", 0xFFFFFFFFFFFFFFFFui64);
        v38 = DNA::PropertyBag::GetOwner(v3);
        if ( v38 )
        {
          DNA::PropertyBag::GetSchemaName((DNA::PropertyBag *)v38, &result);
          if ( (unsigned int)UFG::qString::StartsWith(&result, "UFG::qReflectHandle", -1) )
          {
            UFG::qString::ReplaceString(&result, "UFG::qReflectHandle<", &customWorldMapCaption, 0);
            UFG::qString::ReplaceString(&result, ">", &customWorldMapCaption, 0);
            v39 = UFG::qString::Trim(&result, &v47);
            UFG::qString::Set(&result, v39->mData, v39->mLength, 0i64, 0);
            UFG::qString::~qString(&v47);
            DNA::Database::Instance();
            v41 = DNA::Database::GetSchema(v40, result.mData);
            if ( v41 )
            {
              v42 = v41[3].mCount;
              if ( v42 )
                v37 = *(DNA::PropertyBag **)(v42 + 72);
            }
          }
          UFG::qString::~qString(&result);
        }
        v43 = 0;
        if ( v4 )
        {
          v = v37;
          do
          {
            DNA::SchemaField::GetDefaultValue(v5->mSchemaField, (unsigned __int64 *)&propertyBaga);
            DNA::PropertyWrapper::SetValueInternal<unsigned __int64>(
              v5,
              v43++,
              (unsigned __int64 *)&v,
              (unsigned __int64 *)&propertyBaga,
              0);
          }
          while ( v43 < v4 );
        }
      }
      if ( info.States.p )
        operator delete[](info.States.p);
    }
  }
}

// File Line: 444
// RVA: 0x1ACB00
void __fastcall DNA::PropertyWrapper::Set(DNA::PropertyWrapper *this, unsigned int index, const char *v, unsigned int undoId)
{
  DNA::PropertyWrapper *v4; // rsi
  unsigned int v5; // edi
  unsigned int v6; // ebx
  char *va; // [rsp+40h] [rbp+8h]
  char *value; // [rsp+50h] [rbp+18h]

  value = (char *)v;
  v4 = this;
  v5 = index;
  v6 = undoId;
  DNA::SchemaField::GetDefaultValue(this->mSchemaField, (const char **)&va);
  DNA::PropertyWrapper::SetValueInternal<char const *>(v4, v5, (const char **)&value, (const char **)&va, v6);
}

// File Line: 445
// RVA: 0x1AC9B0
void __fastcall DNA::PropertyWrapper::Set(DNA::PropertyWrapper *this, unsigned int index, int v, unsigned int undoId)
{
  DNA::PropertyWrapper *v4; // rsi
  unsigned int v5; // edi
  unsigned int v6; // ebx
  int va; // [rsp+40h] [rbp+8h]
  int value; // [rsp+50h] [rbp+18h]

  value = v;
  v4 = this;
  v5 = index;
  v6 = undoId;
  DNA::SchemaField::GetDefaultValue(this->mSchemaField, &va);
  DNA::PropertyWrapper::SetValueInternal<long>(v4, v5, &value, &va, v6);
}

// File Line: 446
// RVA: 0x1ACB60
void __fastcall DNA::PropertyWrapper::Set(DNA::PropertyWrapper *this, unsigned int index, __int64 v, unsigned int undoId)
{
  DNA::PropertyWrapper *v4; // rsi
  unsigned int v5; // edi
  unsigned int v6; // ebx
  __int64 va; // [rsp+40h] [rbp+8h]
  __int64 value; // [rsp+50h] [rbp+18h]

  value = v;
  v4 = this;
  v5 = index;
  v6 = undoId;
  DNA::SchemaField::GetDefaultValue(this->mSchemaField, &va);
  DNA::PropertyWrapper::SetValueInternal<__int64>(v4, v5, &value, &va, v6);
}

// File Line: 447
// RVA: 0x1ACA10
void __fastcall DNA::PropertyWrapper::Set(DNA::PropertyWrapper *this, unsigned int index, unsigned int v, unsigned int undoId)
{
  DNA::PropertyWrapper *v4; // rsi
  unsigned int v5; // edi
  unsigned int v6; // ebx
  unsigned int va; // [rsp+40h] [rbp+8h]
  unsigned int value; // [rsp+50h] [rbp+18h]

  value = v;
  v4 = this;
  v5 = index;
  v6 = undoId;
  DNA::SchemaField::GetDefaultValue(this->mSchemaField, &va);
  DNA::PropertyWrapper::SetValueInternal<unsigned long>(v4, v5, &value, &va, v6);
}

// File Line: 448
// RVA: 0x1ACBC0
void __fastcall DNA::PropertyWrapper::Set(DNA::PropertyWrapper *this, unsigned int index, unsigned __int64 v, unsigned int undoId)
{
  DNA::PropertyWrapper *v4; // rsi
  unsigned int v5; // edi
  unsigned int v6; // ebx
  unsigned __int64 va; // [rsp+40h] [rbp+8h]
  unsigned __int64 value; // [rsp+50h] [rbp+18h]

  value = v;
  v4 = this;
  v5 = index;
  v6 = undoId;
  DNA::SchemaField::GetDefaultValue(this->mSchemaField, &va);
  DNA::PropertyWrapper::SetValueInternal<unsigned __int64>(v4, v5, &value, &va, v6);
}

// File Line: 449
// RVA: 0x1ACC20
void __fastcall DNA::PropertyWrapper::Set(DNA::PropertyWrapper *this, unsigned int index, bool v, unsigned int undoId)
{
  DNA::PropertyWrapper *v4; // rsi
  unsigned int v5; // edi
  unsigned int v6; // ebx
  bool va; // [rsp+40h] [rbp+8h]
  bool value; // [rsp+50h] [rbp+18h]

  value = v;
  v4 = this;
  v5 = index;
  v6 = undoId;
  DNA::SchemaField::GetDefaultValue(this->mSchemaField, &va);
  DNA::PropertyWrapper::SetValueInternal<bool>(v4, v5, &value, &va, v6);
}

// File Line: 450
// RVA: 0x1ACA70
void __fastcall DNA::PropertyWrapper::Set(DNA::PropertyWrapper *this, unsigned int index, float v, unsigned int undoId)
{
  DNA::PropertyWrapper *v4; // rsi
  unsigned int v5; // edi
  unsigned int v6; // ebx
  float va; // [rsp+40h] [rbp+8h]
  float value; // [rsp+50h] [rbp+18h]

  value = v;
  v4 = this;
  v5 = index;
  v6 = undoId;
  DNA::SchemaField::GetDefaultValue(this->mSchemaField, &va);
  DNA::PropertyWrapper::SetValueInternal<float>(v4, v5, &value, &va, v6);
}

// File Line: 451
// RVA: 0x1ACAD0
void __fastcall DNA::PropertyWrapper::Set(DNA::PropertyWrapper *this, unsigned int index, DNA::PropertyBag *v, unsigned int undoId)
{
  DNA::PropertyBag *default_value; // [rsp+50h] [rbp+18h]

  default_value = v;
  DNA::PropertyWrapper::SetValueInternal<DNA::PropertyBag *>(this, index, &default_value, &default_value, undoId);
}

// File Line: 453
// RVA: 0x1AC710
void __fastcall DNA::PropertyWrapper::Get(DNA::PropertyWrapper *this, unsigned int index, UFG::qString *v, unsigned int undoId)
{
  DNA::PropertyWrapper::GetValueInternal<UFG::qString>(this, index, v);
}

// File Line: 454
// RVA: 0x1AC6E0
void __fastcall DNA::PropertyWrapper::Get(DNA::PropertyWrapper *this, unsigned int index, int *v, unsigned int undoId)
{
  DNA::PropertyWrapper::GetValueInternal<long>(this, index, v);
}

// File Line: 455
// RVA: 0x1AC720
void __fastcall DNA::PropertyWrapper::Get(DNA::PropertyWrapper *this, unsigned int index, __int64 *v, unsigned int undoId)
{
  DNA::PropertyWrapper::GetValueInternal<__int64>(this, index, v);
}

// File Line: 456
// RVA: 0x1AC6F0
void __fastcall DNA::PropertyWrapper::Get(DNA::PropertyWrapper *this, unsigned int index, unsigned int *v, unsigned int undoId)
{
  DNA::PropertyWrapper::GetValueInternal<unsigned long>(this, index, v);
}

// File Line: 457
// RVA: 0x1AC730
void __fastcall DNA::PropertyWrapper::Get(DNA::PropertyWrapper *this, unsigned int index, unsigned __int64 *v, unsigned int undoId)
{
  DNA::PropertyWrapper::GetValueInternal<unsigned __int64>(this, index, v);
}

// File Line: 458
// RVA: 0x1AC740
void __fastcall DNA::PropertyWrapper::Get(DNA::PropertyWrapper *this, unsigned int index, bool *v, unsigned int undoId)
{
  DNA::PropertyWrapper::GetValueInternal<bool>(this, index, v);
}

// File Line: 459
// RVA: 0x1AC700
void __fastcall DNA::PropertyWrapper::Get(DNA::PropertyWrapper *this, unsigned int index, float *v, unsigned int undoId)
{
  DNA::PropertyWrapper::GetValueInternal<float>(this, index, v);
}

// File Line: 461
// RVA: 0x1AC750
void __fastcall DNA::PropertyWrapper::Get(DNA::PropertyWrapper *this, unsigned int index, DNA::PropertyBagWrapper **v, unsigned int undoId)
{
  DNA::PropertyWrapper *v4; // rdi
  unsigned int v5; // ecx
  DNA::PropertyBagWrapper **v6; // r14
  __int64 v7; // rbp
  unsigned int v8; // ebx
  unsigned int v9; // edx
  __int64 v10; // rcx
  DNA::PropertyBagWrapper *v11; // rsi

  v4 = this;
  v5 = this->mPropertyBagWrapperValues.size;
  v6 = v;
  v7 = index;
  if ( index >= v5 )
  {
    v8 = 0;
    if ( v4->mSchemaField->mArrayLength >= 0 )
    {
      *v = 0i64;
    }
    else
    {
      v9 = 0;
      if ( v5 )
      {
        do
        {
          v10 = v9++;
          v4->mPropertyBagWrapperValues.p[v10]->mPropertyBags.size = 0;
        }
        while ( v9 < v4->mPropertyBagWrapperValues.size );
      }
      v11 = v4->mPropertyBagWrapper;
      if ( v11->mPropertyBags.size > 0 )
      {
        do
          DNA::PropertyWrapper::SetArrayLength(v4, v7 + 1, v11->mPropertyBags.p[v8++]);
        while ( v8 < v11->mPropertyBags.size );
      }
      *v6 = v4->mPropertyBagWrapperValues.p[v7];
    }
  }
  else
  {
    *v = v4->mPropertyBagWrapperValues.p[index];
  }
}

