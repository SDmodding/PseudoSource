// File Line: 30
// RVA: 0x1A3E00
void __fastcall DNA::PropertyBagHandle::PropertyBagHandle(DNA::PropertyBagHandle *this, unsigned __int64 uid)
{
  int v3; // ebx
  UFG::qArray<fastdelegate::FastDelegate1<DNA::PropertyBag *,void>,0> *v4; // rax
  UFG::qArray<fastdelegate::FastDelegate1<DNA::PropertyBag *,void>,0> *v5; // r14
  __int64 size; // rsi
  fastdelegate::FastDelegate1<DNA::PropertyBag *,void> *p; // rcx
  unsigned int v8; // ebx
  unsigned int capacity; // edx
  unsigned int v10; // edx
  _QWORD *p_m_pthis; // rax

  this->mPrev = this;
  this->mNext = this;
  this->mUID = uid;
  v3 = 0;
  this->mPropertyBag = 0i64;
  DNA::Database::Instance();
  v5 = v4 + 1;
  size = v4[1].size;
  if ( !(_DWORD)size )
    goto LABEL_8;
  p = v4[1].p;
  while ( this != (DNA::PropertyBagHandle *)p[v3].m_Closure.m_pthis
       || DNA::PropertyBagHandle::OnPropertyBagDeleted != (void (__fastcall *)(DNA::PropertyBagHandle *, DNA::PropertyBag *))p[v3].m_Closure.m_pFunction )
  {
    if ( ++v3 >= (unsigned int)size )
      goto LABEL_8;
  }
  if ( v3 == -1 )
  {
LABEL_8:
    v8 = size + 1;
    capacity = v4[1].capacity;
    if ( (int)size + 1 > capacity )
    {
      if ( capacity )
        v10 = 2 * capacity;
      else
        v10 = 1;
      for ( ; v10 < v8; v10 *= 2 )
        ;
      if ( v10 - v8 > 0x10000 )
        v10 = size + 65537;
      UFG::qArray<fastdelegate::FastDelegate1<DNA::PropertyBag *,void>,0>::Reallocate(v5, v10, "qArray.Add");
    }
    v5->size = v8;
    p_m_pthis = &v5->p[size].m_Closure.m_pthis;
    p_m_pthis[1] = DNA::PropertyBagHandle::OnPropertyBagDeleted;
    *p_m_pthis = this;
  }
}

// File Line: 37
// RVA: 0x1A3D10
void __fastcall DNA::PropertyBagHandle::PropertyBagHandle(DNA::PropertyBagHandle *this, DNA::PropertyBag *propertyBag)
{
  UFG::qArray<fastdelegate::FastDelegate1<DNA::PropertyBag *,void>,0> *v3; // rax
  UFG::qArray<fastdelegate::FastDelegate1<DNA::PropertyBag *,void>,0> *v4; // r14
  int v5; // edx
  __int64 size; // rsi
  fastdelegate::FastDelegate1<DNA::PropertyBag *,void> *p; // rcx
  unsigned int v8; // ebx
  unsigned int capacity; // edx
  unsigned int v10; // edx
  _QWORD *p_m_pthis; // rax

  this->mPrev = this;
  this->mNext = this;
  this->mUID = propertyBag->mBaseNode.mUID;
  this->mPropertyBag = propertyBag;
  DNA::Database::Instance();
  v4 = v3 + 1;
  v5 = 0;
  size = v3[1].size;
  if ( !(_DWORD)size )
    goto LABEL_8;
  p = v3[1].p;
  while ( this != (DNA::PropertyBagHandle *)p[v5].m_Closure.m_pthis
       || DNA::PropertyBagHandle::OnPropertyBagDeleted != (void (__fastcall *)(DNA::PropertyBagHandle *, DNA::PropertyBag *))p[v5].m_Closure.m_pFunction )
  {
    if ( ++v5 >= (unsigned int)size )
      goto LABEL_8;
  }
  if ( v5 == -1 )
  {
LABEL_8:
    v8 = size + 1;
    capacity = v3[1].capacity;
    if ( (int)size + 1 > capacity )
    {
      if ( capacity )
        v10 = 2 * capacity;
      else
        v10 = 1;
      for ( ; v10 < v8; v10 *= 2 )
        ;
      if ( v10 - v8 > 0x10000 )
        v10 = size + 65537;
      UFG::qArray<fastdelegate::FastDelegate1<DNA::PropertyBag *,void>,0>::Reallocate(v4, v10, "qArray.Add");
    }
    v4->size = v8;
    p_m_pthis = &v4->p[size].m_Closure.m_pthis;
    p_m_pthis[1] = DNA::PropertyBagHandle::OnPropertyBagDeleted;
    *p_m_pthis = this;
  }
}

// File Line: 42
// RVA: 0x1A4310
void __fastcall DNA::PropertyBagHandle::~PropertyBagHandle(DNA::PropertyBagHandle *this)
{
  __int64 v2; // rax
  __int64 v3; // r8
  unsigned int v4; // edx
  unsigned int v5; // eax
  __int64 v6; // r9
  unsigned int v7; // r9d
  __int64 v8; // rdx
  _QWORD *v9; // rcx
  unsigned int v10; // eax
  UFG::qNode<DNA::PropertyBagHandle,DNA::PropertyBagHandle> *mPrev; // rcx
  UFG::qNode<DNA::PropertyBagHandle,DNA::PropertyBagHandle> *mNext; // rax

  if ( DNA::Database::IsInitialized() )
  {
    DNA::Database::Instance();
    v3 = v2;
    v4 = 0;
    v5 = *(_DWORD *)(v2 + 16);
    if ( v5 )
    {
      v6 = *(_QWORD *)(v3 + 24);
      while ( this != *(DNA::PropertyBagHandle **)(v6 + 16i64 * v4)
           || DNA::PropertyBagHandle::OnPropertyBagDeleted != *(void (__fastcall **)(DNA::PropertyBagHandle *, DNA::PropertyBag *))(v6 + 16i64 * v4 + 8) )
      {
        if ( ++v4 >= v5 )
          goto LABEL_15;
      }
      if ( v4 != -1 )
      {
        v7 = v4 + 1;
        if ( v4 + 1 != v5 )
        {
          v8 = 16i64 * (int)v7;
          do
          {
            v9 = (_QWORD *)(v8 + *(_QWORD *)(v3 + 24));
            *(v9 - 1) = v9[1];
            *(v9 - 2) = *v9;
            ++v7;
            v8 += 16i64;
          }
          while ( v7 != *(_DWORD *)(v3 + 16) );
        }
        v10 = *(_DWORD *)(v3 + 16);
        if ( v10 > 1 )
          *(_DWORD *)(v3 + 16) = v10 - 1;
        else
          *(_DWORD *)(v3 + 16) = 0;
      }
    }
  }
LABEL_15:
  mPrev = this->mPrev;
  mNext = this->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  this->mPrev = this;
  this->mNext = this;
}

// File Line: 50
// RVA: 0x1A6190
void __fastcall DNA::PropertyBagHandle::OnPropertyBagDeleted(
        DNA::PropertyBagHandle *this,
        DNA::PropertyBag *propertyBag)
{
  if ( this->mPropertyBag == propertyBag )
    this->mPropertyBag = 0i64;
}

// File Line: 58
// RVA: 0x1A53A0
DNA::PropertyBag *__fastcall DNA::PropertyBagHandle::Get(DNA::PropertyBagHandle *this)
{
  DNA::Database *v2; // rax
  DNA::PropertyBag *result; // rax

  if ( this->mPropertyBag )
    return this->mPropertyBag;
  DNA::Database::Instance();
  result = (DNA::PropertyBag *)DNA::Database::GetPropertyBag(v2, this->mUID);
  this->mPropertyBag = result;
  return result;
}

// File Line: 74
// RVA: 0x1A3C80
void __fastcall DNA::PropertyBag::PropertyBag(DNA::PropertyBag *this, unsigned __int64 uid)
{
  DNA::PropertyData *Property; // rax

  this->mBaseNode.mUID = 0i64;
  this->mBaseNode.mParent = &this->mBaseNode;
  this->mBaseNode.mChildren[0] = &this->mBaseNode;
  this->mBaseNode.mChildren[1] = &this->mBaseNode;
  this->mBaseNode.mNeighbours[0] = &this->mBaseNode;
  this->mBaseNode.mNeighbours[1] = &this->mBaseNode;
  UFG::qBaseTreeRB::qBaseTreeRB(&this->mProperties.mTree);
  *(_WORD *)&this->mIsDirty = 1;
  this->mBaseNode.mUID = uid;
  Property = DNA::PropertyBag::CreateProperty(this, "$Id", (DNA::PropertyType::Enum)151281197);
  if ( Property )
    DNA::PropertyData::Set(Property, 0, uid, 0);
}

// File Line: 124
// RVA: 0x1A42A0
void __fastcall DNA::PropertyBag::~PropertyBag(DNA::PropertyBag *this)
{
  UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *p_mProperties; // rdi
  Render::SkinningCacheNode *Head; // rbx

  p_mProperties = (UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&this->mProperties;
  if ( this->mProperties.mTree.mCount )
  {
    do
    {
      Head = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead(p_mProperties);
      UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(&p_mProperties->mTree, &Head->mNode);
      if ( Head )
      {
        DNA::PropertyData::~PropertyData((DNA::PropertyData *)Head);
        operator delete[](Head);
      }
    }
    while ( p_mProperties->mTree.mCount );
  }
  UFG::qTreeRB<DNA::PropertyData,DNA::PropertyData,1>::~qTreeRB<DNA::PropertyData,DNA::PropertyData,1>((UFG::qTreeRB<DNA::PropertyData,DNA::PropertyData,1> *)p_mProperties);
}

// File Line: 301
// RVA: 0x1A5E50
UFG::qTree64Base *__fastcall DNA::PropertyBag::GetSchemaType(DNA::PropertyBag *this)
{
  char *mData; // rbx
  DNA::Database *v2; // rax
  UFG::qTree64Base *Schema; // rbx
  UFG::qString result; // [rsp+28h] [rbp-30h] BYREF

  mData = DNA::PropertyBag::GetSchemaName(this, &result)->mData;
  DNA::Database::Instance();
  Schema = DNA::Database::GetSchema(v2, mData);
  UFG::qString::~qString(&result);
  return Schema;
}

// File Line: 306
// RVA: 0x1A5B50
DNA::PropertyState::Enum __fastcall DNA::PropertyBag::GetPropertyState(
        DNA::PropertyBag *this,
        const char *propertyName,
        int index)
{
  UFG::qBaseTreeRB *Property; // rax

  Property = DNA::PropertyBag::GetProperty(this, propertyName);
  return DNA::PropertyBag::GetPropertyState(this, (DNA::PropertyData *)Property, index);
}

// File Line: 312
// RVA: 0x1A5AB0
DNA::PropertyState::Enum __fastcall DNA::PropertyBag::GetPropertyState(
        DNA::PropertyBag *this,
        DNA::PropertyData *propertyData,
        int index)
{
  char *mData; // rbx
  DNA::Database *v7; // rax
  UFG::qTree64Base *Schema; // rbx
  DNA::SchemaField *Field; // rax
  unsigned __int64 v10; // rax
  UFG::qString result; // [rsp+28h] [rbp-30h] BYREF

  if ( !propertyData )
    return 0;
  mData = DNA::PropertyBag::GetSchemaName(this, &result)->mData;
  DNA::Database::Instance();
  Schema = DNA::Database::GetSchema(v7, mData);
  UFG::qString::~qString(&result);
  if ( Schema )
  {
    v10 = UFG::qStringHash64(propertyData->mName.mData, 0xFFFFFFFFFFFFFFFFui64);
    Field = DNA::SchemaType::GetField((DNA::SchemaType *)Schema, v10);
  }
  else
  {
    Field = 0i64;
  }
  return DNA::PropertyData::GetPropertyState(propertyData, index, Field);
}

// File Line: 325
// RVA: 0x1A5850
void __fastcall DNA::PropertyBag::GetPropertyInfo(
        DNA::PropertyBag *this,
        const char *propertyName,
        DNA::PropertyInfo *info)
{
  unsigned int v3; // esi
  DNA::PropertyData *Property; // rax
  DNA::PropertyData *v8; // r14
  unsigned int v9; // eax
  __int64 size; // rbp
  unsigned int capacity; // edx
  unsigned int v12; // ebx
  unsigned int v13; // edx
  DNA::PropertyState::Enum *p; // rax
  __int64 v15; // rbp
  unsigned int v16; // edx
  unsigned int v17; // ebx
  unsigned int v18; // edx
  DNA::PropertyState::Enum *v19; // rax
  DNA::SchemaType *SchemaType; // rbx
  DNA::SchemaField *Field; // r12
  unsigned __int64 v22; // rax
  DNA::PropertyState::Enum PropertyState; // eax
  __int64 v24; // rbp
  unsigned int v25; // edx
  unsigned int v26; // ebx
  DNA::PropertyState::Enum v27; // r15d
  unsigned int v28; // edx
  DNA::PropertyState::Enum *v29; // rax

  v3 = 0;
  *(_QWORD *)&info->Type = 0i64;
  info->States.size = 0;
  Property = (DNA::PropertyData *)DNA::PropertyBag::GetProperty(this, propertyName);
  v8 = Property;
  if ( Property )
  {
    info->Type = Property->mPropertyType;
    v9 = DNA::PropertyData::NumItems(Property);
    info->Size = v9;
    if ( *propertyName == 36 )
    {
      if ( v9 )
      {
        do
        {
          size = info->States.size;
          capacity = info->States.capacity;
          v12 = size + 1;
          if ( (int)size + 1 > capacity )
          {
            if ( capacity )
              v13 = 2 * capacity;
            else
              v13 = 1;
            for ( ; v13 < v12; v13 *= 2 )
              ;
            if ( v13 <= 4 )
              v13 = 4;
            if ( v13 - v12 > 0x10000 )
              v13 = size + 65537;
            UFG::qArray<long,0>::Reallocate((UFG::qArray<unsigned long,0> *)&info->States, v13, "qArray.Add");
          }
          p = info->States.p;
          info->States.size = v12;
          ++v3;
          p[size] = Assigned;
        }
        while ( v3 < info->Size );
      }
    }
    else if ( v8->mOwner->mBaseNode.mUID == this->mBaseNode.mUID )
    {
      SchemaType = DNA::PropertyBag::GetSchemaType(this);
      if ( SchemaType )
      {
        v22 = UFG::qStringHash64(propertyName, 0xFFFFFFFFFFFFFFFFui64);
        Field = DNA::SchemaType::GetField(SchemaType, v22);
      }
      else
      {
        Field = 0i64;
      }
      if ( info->Size )
      {
        do
        {
          PropertyState = DNA::PropertyData::GetPropertyState(v8, v3, Field);
          v24 = info->States.size;
          v25 = info->States.capacity;
          v26 = v24 + 1;
          v27 = PropertyState;
          if ( (int)v24 + 1 > v25 )
          {
            if ( v25 )
              v28 = 2 * v25;
            else
              v28 = 1;
            for ( ; v28 < v26; v28 *= 2 )
              ;
            if ( v28 <= 4 )
              v28 = 4;
            if ( v28 - v26 > 0x10000 )
              v28 = v24 + 65537;
            UFG::qArray<long,0>::Reallocate((UFG::qArray<unsigned long,0> *)&info->States, v28, "qArray.Add");
          }
          v29 = info->States.p;
          info->States.size = v26;
          ++v3;
          v29[v24] = v27;
        }
        while ( v3 < info->Size );
      }
    }
    else if ( v9 )
    {
      do
      {
        v15 = info->States.size;
        v16 = info->States.capacity;
        v17 = v15 + 1;
        if ( (int)v15 + 1 > v16 )
        {
          if ( v16 )
            v18 = 2 * v16;
          else
            v18 = 1;
          for ( ; v18 < v17; v18 *= 2 )
            ;
          if ( v18 <= 4 )
            v18 = 4;
          if ( v18 - v17 > 0x10000 )
            v18 = v15 + 65537;
          UFG::qArray<long,0>::Reallocate((UFG::qArray<unsigned long,0> *)&info->States, v18, "qArray.Add");
        }
        v19 = info->States.p;
        info->States.size = v17;
        ++v3;
        v19[v15] = Inherited;
      }
      while ( v3 < info->Size );
    }
  }
}es.p;
        info->States.size = v17;
        ++v3;
        v19[v15] = Inherited;
      }
      while ( v3 < info->Size );
    }
  

// File Line: 372
// RVA: 0x1A51F0
void __fastcall DNA::PropertyBag::Get(
        DNA::PropertyBag *this,
        const char *propertyName,
        UFG::qString *v,
        unsigned int index)
{
  DNA::PropertyData *Property; // rax
  DNA::PropertyData::Value *Value; // rax

  Property = DNA::PropertyBag::GetProperty(this, propertyName);
  if ( Property && Property->mPropertyType == 826535573 )
  {
    Value = DNA::PropertyData::GetValue(Property, index);
    if ( Value )
      UFG::qString::Set(v, Value->mData.mData);
  }
}

// File Line: 373
// RVA: 0x1A5110
void __fastcall DNA::PropertyBag::Get(DNA::PropertyBag *this, const char *propertyName, int *v, unsigned int index)
{
  DNA::PropertyData *Property; // rax
  DNA::PropertyData::Value *Value; // rax

  Property = DNA::PropertyBag::GetProperty(this, propertyName);
  if ( Property && Property->mPropertyType == -2133091136 )
  {
    Value = DNA::PropertyData::GetValue(Property, index);
    if ( Value )
      *v = UFG::qToInt32(Value->mData.mData, 0);
  }
}

// File Line: 374
// RVA: 0x1A5240
void __fastcall DNA::PropertyBag::Get(DNA::PropertyBag *this, const char *propertyName, __int64 *v, unsigned int index)
{
  DNA::PropertyData *Property; // rax
  DNA::PropertyData::Value *Value; // rax

  Property = DNA::PropertyBag::GetProperty(this, propertyName);
  if ( Property && Property->mPropertyType == 224407815 )
  {
    Value = DNA::PropertyData::GetValue(Property, index);
    if ( Value )
      *v = UFG::qToInt64(Value->mData.mData, 0i64);
  }
}

// File Line: 375
// RVA: 0x1A5160
void __fastcall DNA::PropertyBag::Get(
        DNA::PropertyBag *this,
        const char *propertyName,
        unsigned int *v,
        unsigned int index)
{
  DNA::PropertyData *Property; // rax
  DNA::PropertyData::Value *Value; // rax

  Property = DNA::PropertyBag::GetProperty(this, propertyName);
  if ( Property && Property->mPropertyType == -2067794966 )
  {
    Value = DNA::PropertyData::GetValue(Property, index);
    if ( Value )
      *v = UFG::qToUInt32(Value->mData.mData, 0);
  }
}

// File Line: 376
// RVA: 0x1A5290
void __fastcall DNA::PropertyBag::Get(
        DNA::PropertyBag *this,
        const char *propertyName,
        unsigned __int64 *v,
        unsigned int index)
{
  DNA::PropertyData *Property; // rax
  DNA::PropertyData::Value *Value; // rax

  Property = DNA::PropertyBag::GetProperty(this, propertyName);
  if ( Property && Property->mPropertyType == 151281197 )
  {
    Value = DNA::PropertyData::GetValue(Property, index);
    if ( Value )
      *v = UFG::qToUInt64(Value->mData.mData, 0i64);
  }
}

// File Line: 377
// RVA: 0x1A52E0
void __fastcall DNA::PropertyBag::Get(DNA::PropertyBag *this, const char *propertyName, bool *v, unsigned int index)
{
  DNA::PropertyData *Property; // rax
  DNA::PropertyData::Value *Value; // rax

  Property = DNA::PropertyBag::GetProperty(this, propertyName);
  if ( Property && Property->mPropertyType == 1138723642 )
  {
    Value = DNA::PropertyData::GetValue(Property, index);
    if ( Value )
      *v = UFG::qToBool(Value->mData.mData, 0);
  }
}

// File Line: 379
// RVA: 0x1A51B0
void __fastcall DNA::PropertyBag::Get(DNA::PropertyBag *this, const char *propertyName, float *v, unsigned int index)
{
  DNA::PropertyData *Property; // rax

  Property = DNA::PropertyBag::GetProperty(this, propertyName);
  if ( Property )
    DNA::PropertyData::Get(Property, index, v);
}

// File Line: 380
// RVA: 0x1A5330
void __fastcall DNA::PropertyBag::Get(
        DNA::PropertyBag *this,
        const char *propertyName,
        UFG::qTree64Base **v,
        unsigned int index)
{
  DNA::PropertyData *Property; // rax
  DNA::PropertyData::Value *Value; // rax
  unsigned __int64 v8; // rbx
  DNA::Database *v9; // rax

  *v = 0i64;
  Property = DNA::PropertyBag::GetProperty(this, propertyName);
  if ( Property && Property->mPropertyType == -915936389 )
  {
    Value = DNA::PropertyData::GetValue(Property, index);
    if ( Value )
    {
      v8 = UFG::qToUInt64(Value->mData.mData, 0i64);
      DNA::Database::Instance();
      *v = DNA::Database::GetPropertyBag(v9, v8);
    }
  }
}

// File Line: 382
// RVA: 0x1A63B0
void __fastcall DNA::PropertyBag::Set(
        DNA::PropertyBag *this,
        const char *propertyName,
        const char *v,
        unsigned int index,
        unsigned int undoId)
{
  UFG::qBaseTreeRB *Property; // rax

  if ( *propertyName != 36 )
  {
    Property = DNA::PropertyBag::CreateProperty(this, propertyName, (DNA::PropertyType::Enum)826535573);
    if ( Property )
      DNA::PropertyData::Set((DNA::PropertyData *)Property, index, v, undoId);
  }
}

// File Line: 383
// RVA: 0x1A6400
void __fastcall DNA::PropertyBag::Set(
        DNA::PropertyBag *this,
        const char *propertyName,
        int v,
        unsigned int index,
        unsigned int undoId)
{
  UFG::qBaseTreeRB *Property; // rax

  if ( *propertyName != 36 )
  {
    Property = DNA::PropertyBag::CreateProperty(this, propertyName, (DNA::PropertyType::Enum)-2133091136);
    if ( Property )
      DNA::PropertyData::Set((DNA::PropertyData *)Property, index, v, undoId);
  }
}

// File Line: 384
// RVA: 0x1A6540
void __fastcall DNA::PropertyBag::Set(
        DNA::PropertyBag *this,
        const char *propertyName,
        __int64 v,
        unsigned int index,
        unsigned int undoId)
{
  UFG::qBaseTreeRB *Property; // rax

  if ( *propertyName != 36 )
  {
    Property = DNA::PropertyBag::CreateProperty(this, propertyName, (DNA::PropertyType::Enum)224407815);
    if ( Property )
      DNA::PropertyData::Set((DNA::PropertyData *)Property, index, v, undoId);
  }
}

// File Line: 385
// RVA: 0x1A6450
void __fastcall DNA::PropertyBag::Set(
        DNA::PropertyBag *this,
        const char *propertyName,
        unsigned int v,
        unsigned int index,
        unsigned int undoId)
{
  UFG::qBaseTreeRB *Property; // rax

  if ( *propertyName != 36 )
  {
    Property = DNA::PropertyBag::CreateProperty(this, propertyName, (DNA::PropertyType::Enum)-2067794966);
    if ( Property )
      DNA::PropertyData::Set((DNA::PropertyData *)Property, index, v, undoId);
  }
}

// File Line: 386
// RVA: 0x1A6590
void __fastcall DNA::PropertyBag::Set(
        DNA::PropertyBag *this,
        const char *propertyName,
        unsigned __int64 v,
        unsigned int index,
        unsigned int undoId)
{
  UFG::qBaseTreeRB *Property; // rax

  if ( *propertyName != 36 )
  {
    Property = DNA::PropertyBag::CreateProperty(this, propertyName, (DNA::PropertyType::Enum)151281197);
    if ( Property )
      DNA::PropertyData::Set((DNA::PropertyData *)Property, index, v, undoId);
  }
}

// File Line: 387
// RVA: 0x1A65E0
void __fastcall DNA::PropertyBag::Set(
        DNA::PropertyBag *this,
        const char *propertyName,
        bool v,
        unsigned int index,
        unsigned int undoId)
{
  UFG::qBaseTreeRB *Property; // rax

  if ( *propertyName != 36 )
  {
    Property = DNA::PropertyBag::CreateProperty(this, propertyName, (DNA::PropertyType::Enum)1138723642);
    if ( Property )
      DNA::PropertyData::Set((DNA::PropertyData *)Property, index, v, undoId);
  }
}

// File Line: 389
// RVA: 0x1A64A0
void __fastcall DNA::PropertyBag::Set(
        DNA::PropertyBag *this,
        const char *propertyName,
        float v,
        unsigned int index,
        unsigned int undoId)
{
  UFG::qBaseTreeRB *Property; // rax

  if ( *propertyName != 36 )
  {
    Property = DNA::PropertyBag::CreateProperty(this, propertyName, (DNA::PropertyType::Enum)1208522079);
    if ( Property )
      DNA::PropertyData::Set((DNA::PropertyData *)Property, index, v, undoId);
  }
}

// File Line: 390
// RVA: 0x1A64F0
void __fastcall DNA::PropertyBag::Set(
        DNA::PropertyBag *this,
        const char *propertyName,
        DNA::PropertyBag *v,
        unsigned int index,
        unsigned int undoId)
{
  UFG::qBaseTreeRB *Property; // rax

  if ( *propertyName != 36 )
  {
    Property = DNA::PropertyBag::CreateProperty(this, propertyName, (DNA::PropertyType::Enum)-915936389);
    if ( Property )
      DNA::PropertyData::Set((DNA::PropertyData *)Property, index, v, undoId);
  }
}

// File Line: 392
// RVA: 0x1A4820
void __fastcall DNA::PropertyBag::Append(
        DNA::PropertyBag *this,
        const char *propertyName,
        const char *v,
        unsigned int undoId)
{
  __int64 v8; // rax
  DNA::PropertyData *Property; // rax
  DNA::PropertyData *v10; // rdi
  unsigned int v11; // eax
  __int64 v12; // rax

  DNA::Database::Instance();
  DNA::ActionManager::BeginTransaction((DNA::ActionManager *)(v8 + 312), undoId);
  if ( *propertyName != 36 )
  {
    Property = DNA::PropertyBag::CreateProperty(this, propertyName, (DNA::PropertyType::Enum)826535573);
    v10 = Property;
    if ( Property )
    {
      v11 = DNA::PropertyData::Add(Property, undoId);
      DNA::PropertyData::Set(v10, v11, v, undoId);
    }
  }
  DNA::Database::Instance();
  DNA::ActionManager::EndTransaction((DNA::ActionManager *)(v12 + 312), undoId);
}

// File Line: 393
// RVA: 0x1A48C0
void __fastcall DNA::PropertyBag::Append(DNA::PropertyBag *this, const char *propertyName, int v, unsigned int undoId)
{
  __int64 v8; // rax
  DNA::PropertyData *Property; // rax
  DNA::PropertyData *v10; // rdi
  unsigned int v11; // eax
  __int64 v12; // rax

  DNA::Database::Instance();
  DNA::ActionManager::BeginTransaction((DNA::ActionManager *)(v8 + 312), undoId);
  if ( *propertyName != 36 )
  {
    Property = DNA::PropertyBag::CreateProperty(this, propertyName, (DNA::PropertyType::Enum)-2133091136);
    v10 = Property;
    if ( Property )
    {
      v11 = DNA::PropertyData::Add(Property, undoId);
      DNA::PropertyData::Set(v10, v11, v, undoId);
    }
  }
  DNA::Database::Instance();
  DNA::ActionManager::EndTransaction((DNA::ActionManager *)(v12 + 312), undoId);
}

// File Line: 394
// RVA: 0x1A4B40
void __fastcall DNA::PropertyBag::Append(
        DNA::PropertyBag *this,
        const char *propertyName,
        __int64 v,
        unsigned int undoId)
{
  __int64 v8; // rax
  DNA::PropertyData *Property; // rax
  DNA::PropertyData *v10; // rdi
  unsigned int v11; // eax
  __int64 v12; // rax

  DNA::Database::Instance();
  DNA::ActionManager::BeginTransaction((DNA::ActionManager *)(v8 + 312), undoId);
  if ( *propertyName != 36 )
  {
    Property = DNA::PropertyBag::CreateProperty(this, propertyName, (DNA::PropertyType::Enum)224407815);
    v10 = Property;
    if ( Property )
    {
      v11 = DNA::PropertyData::Add(Property, undoId);
      DNA::PropertyData::Set(v10, v11, v, undoId);
    }
  }
  DNA::Database::Instance();
  DNA::ActionManager::EndTransaction((DNA::ActionManager *)(v12 + 312), undoId);
}

// File Line: 395
// RVA: 0x1A4960
void __fastcall DNA::PropertyBag::Append(
        DNA::PropertyBag *this,
        const char *propertyName,
        unsigned int v,
        unsigned int undoId)
{
  __int64 v8; // rax
  DNA::PropertyData *Property; // rax
  DNA::PropertyData *v10; // rdi
  unsigned int v11; // eax
  __int64 v12; // rax

  DNA::Database::Instance();
  DNA::ActionManager::BeginTransaction((DNA::ActionManager *)(v8 + 312), undoId);
  if ( *propertyName != 36 )
  {
    Property = DNA::PropertyBag::CreateProperty(this, propertyName, (DNA::PropertyType::Enum)-2067794966);
    v10 = Property;
    if ( Property )
    {
      v11 = DNA::PropertyData::Add(Property, undoId);
      DNA::PropertyData::Set(v10, v11, v, undoId);
    }
  }
  DNA::Database::Instance();
  DNA::ActionManager::EndTransaction((DNA::ActionManager *)(v12 + 312), undoId);
}

// File Line: 396
// RVA: 0x1A4BE0
void __fastcall DNA::PropertyBag::Append(
        DNA::PropertyBag *this,
        const char *propertyName,
        unsigned __int64 v,
        unsigned int undoId)
{
  __int64 v8; // rax
  DNA::PropertyData *Property; // rax
  DNA::PropertyData *v10; // rdi
  unsigned int v11; // eax
  __int64 v12; // rax

  DNA::Database::Instance();
  DNA::ActionManager::BeginTransaction((DNA::ActionManager *)(v8 + 312), undoId);
  if ( *propertyName != 36 )
  {
    Property = DNA::PropertyBag::CreateProperty(this, propertyName, (DNA::PropertyType::Enum)151281197);
    v10 = Property;
    if ( Property )
    {
      v11 = DNA::PropertyData::Add(Property, undoId);
      DNA::PropertyData::Set(v10, v11, v, undoId);
    }
  }
  DNA::Database::Instance();
  DNA::ActionManager::EndTransaction((DNA::ActionManager *)(v12 + 312), undoId);
}

// File Line: 397
// RVA: 0x1A4C80
void __fastcall DNA::PropertyBag::Append(DNA::PropertyBag *this, const char *propertyName, bool v, unsigned int undoId)
{
  __int64 v8; // rax
  DNA::PropertyData *Property; // rax
  DNA::PropertyData *v10; // rdi
  unsigned int v11; // eax
  __int64 v12; // rax

  DNA::Database::Instance();
  DNA::ActionManager::BeginTransaction((DNA::ActionManager *)(v8 + 312), undoId);
  if ( *propertyName != 36 )
  {
    Property = DNA::PropertyBag::CreateProperty(this, propertyName, (DNA::PropertyType::Enum)1138723642);
    v10 = Property;
    if ( Property )
    {
      v11 = DNA::PropertyData::Add(Property, undoId);
      DNA::PropertyData::Set(v10, v11, v, undoId);
    }
  }
  DNA::Database::Instance();
  DNA::ActionManager::EndTransaction((DNA::ActionManager *)(v12 + 312), undoId);
}

// File Line: 399
// RVA: 0x1A4A00
void __fastcall DNA::PropertyBag::Append(
        DNA::PropertyBag *this,
        const char *propertyName,
        float v,
        unsigned int undoId)
{
  __int64 v7; // rax
  DNA::PropertyData *Property; // rax
  DNA::PropertyData *v9; // rdi
  unsigned int v10; // eax
  __int64 v11; // rax

  DNA::Database::Instance();
  DNA::ActionManager::BeginTransaction((DNA::ActionManager *)(v7 + 312), undoId);
  if ( *propertyName != 36 )
  {
    Property = DNA::PropertyBag::CreateProperty(this, propertyName, (DNA::PropertyType::Enum)1208522079);
    v9 = Property;
    if ( Property )
    {
      v10 = DNA::PropertyData::Add(Property, undoId);
      DNA::PropertyData::Set(v9, v10, v, undoId);
    }
  }
  DNA::Database::Instance();
  DNA::ActionManager::EndTransaction((DNA::ActionManager *)(v11 + 312), undoId);
}

// File Line: 400
// RVA: 0x1A4AA0
void __fastcall DNA::PropertyBag::Append(
        DNA::PropertyBag *this,
        const char *propertyName,
        DNA::PropertyBag *v,
        unsigned int undoId)
{
  __int64 v8; // rax
  DNA::PropertyData *Property; // rax
  DNA::PropertyData *v10; // rdi
  unsigned int v11; // eax
  __int64 v12; // rax

  DNA::Database::Instance();
  DNA::ActionManager::BeginTransaction((DNA::ActionManager *)(v8 + 312), undoId);
  if ( *propertyName != 36 )
  {
    Property = DNA::PropertyBag::CreateProperty(this, propertyName, (DNA::PropertyType::Enum)-915936389);
    v10 = Property;
    if ( Property )
    {
      v11 = DNA::PropertyData::Add(Property, undoId);
      DNA::PropertyData::Set(v10, v11, v, undoId);
    }
  }
  DNA::Database::Instance();
  DNA::ActionManager::EndTransaction((DNA::ActionManager *)(v12 + 312), undoId);
}

// File Line: 403
// RVA: 0x1A4D20
UFG::qBaseTreeRB *__fastcall DNA::PropertyBag::CreateProperty(
        DNA::PropertyBag *this,
        const char *propertyName,
        DNA::PropertyType::Enum propertyType)
{
  unsigned int v6; // eax
  UFG::qBaseTreeRB *result; // rax
  DNA::PropertyData *v8; // rbx
  UFG::allocator::free_link *v9; // rax
  DNA::PropertyData *v10; // rax

  v6 = UFG::qStringHashUpper32(propertyName, -1);
  if ( v6 && (result = UFG::qBaseTreeRB::Get(&this->mProperties.mTree, v6)) != 0i64 )
  {
    if ( LODWORD(result[1].mRoot.mParent) == propertyType )
      return result;
    return 0i64;
  }
  else
  {
    v9 = UFG::qMalloc(0x80ui64, "PropertyBag::CreateProperty", 0i64);
    if ( v9 )
    {
      DNA::PropertyData::PropertyData((DNA::PropertyData *)v9, this, propertyName, propertyType);
      v8 = v10;
    }
    else
    {
      v8 = 0i64;
    }
    DNA::PropertyData::UpdateInheritanceBinding(v8, eNone);
    UFG::qBaseTreeRB::Add(&this->mProperties.mTree, &v8->mNode);
  }
  return (UFG::qBaseTreeRB *)v8;
}

// File Line: 441
// RVA: 0x1A57A0
UFG::qBaseTreeRB *__fastcall DNA::PropertyBag::GetProperty(DNA::PropertyBag *this, const char *propertyName)
{
  unsigned int v4; // eax
  UFG::qBaseTreeRB *v5; // rbx
  UFG::qTree64Base *Parent; // rax

  v4 = UFG::qStringHashUpper32(propertyName, -1);
  if ( v4 )
  {
    v5 = UFG::qBaseTreeRB::Get(&this->mProperties.mTree, v4);
    if ( v5 )
      return v5;
  }
  else
  {
    v5 = 0i64;
  }
  if ( !(unsigned int)UFG::qStringCompare(propertyName, "$ParentId", -1)
    || !(unsigned int)UFG::qStringCompare(propertyName, "$OwnerId", -1) )
  {
    return 0i64;
  }
  Parent = DNA::PropertyBag::GetParent(this);
  if ( Parent )
    return (UFG::qBaseTreeRB *)DNA::PropertyBag::GetProperty((DNA::PropertyBag *)Parent, propertyName);
  return v5;
}

// File Line: 502
// RVA: 0x1A54D0
UFG::qString *__fastcall DNA::PropertyBag::GetName(DNA::PropertyBag *this, UFG::qString *result)
{
  DNA::PropertyData *Property; // rax
  DNA::PropertyData::Value *Value; // rax

  UFG::qString::qString(result);
  Property = DNA::PropertyBag::GetProperty(this, "$Name");
  if ( Property )
  {
    if ( Property->mPropertyType == 826535573 )
    {
      Value = DNA::PropertyData::GetValue(Property, 0);
      if ( Value )
        UFG::qString::Set(result, Value->mData.mData);
    }
  }
  return result;
}

// File Line: 509
// RVA: 0x1A6DA0
void __fastcall DNA::PropertyBag::SetName(DNA::PropertyBag *this, const char *name)
{
  UFG::qBaseTreeRB *Property; // rax

  Property = DNA::PropertyBag::CreateProperty(this, "$Name", (DNA::PropertyType::Enum)826535573);
  if ( Property )
    DNA::PropertyData::Set((DNA::PropertyData *)Property, 0, name, 0);
}

// File Line: 514
// RVA: 0x1A5DD0
UFG::qString *__fastcall DNA::PropertyBag::GetSchemaName(DNA::PropertyBag *this, UFG::qString *result)
{
  UFG::qBaseTreeRB *Property; // rax
  DNA::PropertyData::Value *Value; // rax

  UFG::qString::qString(result);
  Property = DNA::PropertyBag::GetProperty(this, "$SchemaName");
  if ( Property )
  {
    if ( LODWORD(Property[1].mRoot.mParent) == 826535573 )
    {
      Value = DNA::PropertyData::GetValue((DNA::PropertyData *)Property, 0);
      if ( Value )
        UFG::qString::Set(result, Value->mData.mData);
    }
  }
  return result;
}

// File Line: 521
// RVA: 0x1A73A0
void __fastcall DNA::PropertyBag::SetSchemaName(DNA::PropertyBag *this, const char *name)
{
  UFG::qBaseTreeRB *Property; // rax

  Property = DNA::PropertyBag::CreateProperty(this, "$SchemaName", (DNA::PropertyType::Enum)826535573);
  if ( Property )
    DNA::PropertyData::Set((DNA::PropertyData *)Property, 0, name, 0);
}

// File Line: 545
// RVA: 0x1A6D60
void __fastcall DNA::PropertyBag::SetFilePath(DNA::PropertyBag *this, const char *filePath)
{
  UFG::qBaseTreeRB *Property; // rax

  Property = DNA::PropertyBag::CreateProperty(this, "$FilePath", (DNA::PropertyType::Enum)826535573);
  if ( Property )
    DNA::PropertyData::Set((DNA::PropertyData *)Property, 0, filePath, 0);
}

// File Line: 550
// RVA: 0x1A6E20
void __fastcall DNA::PropertyBag::SetOwnerUID(DNA::PropertyBag *this, unsigned __int64 uid)
{
  UFG::qBaseTreeRB *Property; // rax
  DNA::PropertyData::Value *Value; // rax
  UFG::qBaseTreeRB *v6; // rax

  Property = DNA::PropertyBag::GetProperty(this, "$OwnerId");
  if ( !Property
    || LODWORD(Property[1].mRoot.mParent) != 151281197
    || (Value = DNA::PropertyData::GetValue((DNA::PropertyData *)Property, 0)) == 0i64
    || !UFG::qToUInt64(Value->mData.mData, 0i64) )
  {
    v6 = DNA::PropertyBag::CreateProperty(this, "$OwnerId", (DNA::PropertyType::Enum)151281197);
    if ( v6 )
      DNA::PropertyData::Set((DNA::PropertyData *)v6, 0, uid, 0);
  }
}

// File Line: 562
// RVA: 0x1A55F0
unsigned __int64 __fastcall DNA::PropertyBag::GetOwnerUID(DNA::PropertyBag *this)
{
  DNA::PropertyData *Property; // rax
  DNA::PropertyData::Value *Value; // rax

  Property = DNA::PropertyBag::GetProperty(this, "$OwnerId");
  if ( Property && Property->mPropertyType == 151281197 && (Value = DNA::PropertyData::GetValue(Property, 0)) != 0i64 )
    return UFG::qToUInt64(Value->mData.mData, 0i64);
  else
    return 0i64;
}

// File Line: 569
// RVA: 0x1A5590
UFG::qTree64Base *__fastcall DNA::PropertyBag::GetOwner(DNA::PropertyBag *this)
{
  unsigned __int64 v1; // rbx
  DNA::PropertyData *Property; // rax
  DNA::PropertyData::Value *Value; // rax
  DNA::Database *v4; // rax

  v1 = 0i64;
  Property = DNA::PropertyBag::GetProperty(this, "$OwnerId");
  if ( Property )
  {
    if ( Property->mPropertyType == 151281197 )
    {
      Value = DNA::PropertyData::GetValue(Property, 0);
      if ( Value )
        v1 = UFG::qToUInt64(Value->mData.mData, 0i64);
    }
  }
  DNA::Database::Instance();
  return DNA::Database::GetPropertyBag(v4, v1);
}

// File Line: 574
// RVA: 0x1A6DE0
void __fastcall DNA::PropertyBag::SetOwner(DNA::PropertyBag *this, DNA::PropertyBag *owner)
{
  DNA::PropertyBag *v2; // rbx
  DNA::Database *v4; // rax

  v2 = owner;
  if ( owner )
    owner = (DNA::PropertyBag *)owner->mBaseNode.mUID;
  DNA::PropertyBag::SetOwnerUID(this, (unsigned __int64)owner);
  DNA::Database::Instance();
  DNA::Database::OnOwnerChanged(v4, (UFG::qTree64Base *)this, v2);
}

// File Line: 592
// RVA: 0x1A5640
UFG::qTree64Base *__fastcall DNA::PropertyBag::GetParent(DNA::PropertyBag *this)
{
  DNA::PropertyData *Property; // rax
  DNA::PropertyData::Value *Value; // rax
  unsigned __int64 v4; // rbx
  DNA::PropertyData *v5; // rax
  DNA::PropertyData::Value *v6; // rax
  DNA::Database *v7; // rax
  UFG::qTree64Base *PropertyBag; // rsi
  UFG::qString *SchemaName; // rbx
  UFG::qString *v10; // rax
  DNA::PropertyBag *Parent; // rax
  UFG::qString v13; // [rsp+28h] [rbp-60h] BYREF
  UFG::qString result; // [rsp+50h] [rbp-38h] BYREF

  Property = DNA::PropertyBag::GetProperty(this, "$ParentId");
  if ( Property )
  {
    if ( Property->mPropertyType == 151281197 )
    {
      Value = DNA::PropertyData::GetValue(Property, 0);
      if ( Value )
      {
        if ( UFG::qToUInt64(Value->mData.mData, 0i64) - 1 <= 0xFFFFFFFFFFFFFFFDui64 )
        {
          v4 = 0i64;
          v5 = DNA::PropertyBag::GetProperty(this, "$ParentId");
          if ( v5 )
          {
            if ( v5->mPropertyType == 151281197 )
            {
              v6 = DNA::PropertyData::GetValue(v5, 0);
              if ( v6 )
                v4 = UFG::qToUInt64(v6->mData.mData, 0i64);
            }
          }
          DNA::Database::Instance();
          PropertyBag = DNA::Database::GetPropertyBag(v7, v4);
          if ( PropertyBag )
          {
            SchemaName = DNA::PropertyBag::GetSchemaName(this, &result);
            v10 = DNA::PropertyBag::GetSchemaName((DNA::PropertyBag *)PropertyBag, &v13);
            LOBYTE(SchemaName) = (unsigned int)UFG::qStringCompare(v10->mData, SchemaName->mData, -1) == 0;
            UFG::qString::~qString(&v13);
            UFG::qString::~qString(&result);
            if ( (_BYTE)SchemaName )
            {
              Parent = DNA::PropertyBag::GetParent((DNA::PropertyBag *)PropertyBag);
              if ( !Parent )
                return PropertyBag;
              while ( Parent->mBaseNode.mUID != this->mBaseNode.mUID )
              {
                Parent = DNA::PropertyBag::GetParent(Parent);
                if ( !Parent )
                  return PropertyBag;
              }
            }
          }
        }
      }
    }
  }
  return 0i64;
}

// File Line: 624
// RVA: 0x1A6EA0
void __fastcall DNA::PropertyBag::SetParent(DNA::PropertyBag *this, DNA::PropertyBag *parent)
{
  DNA::PropertyBag *v3; // r13
  unsigned __int64 mUID; // rdi
  UFG::qString *SchemaName; // rbx
  UFG::qString *v6; // rax
  UFG::qTree64Base *v7; // rax
  unsigned __int64 v8; // rbx
  UFG::qBaseTreeRB *Property; // rax
  DNA::PropertyData::Value *Value; // rax
  UFG::allocator::free_link *v11; // r15
  __int64 v12; // rsi
  unsigned int v13; // r14d
  UFG::qBaseTreeRB *p_mTree; // r12
  DNA::PropertyData *Head; // rbp
  const char *mData; // rcx
  DNA::SchemaField *Field; // rbx
  unsigned __int64 v18; // rax
  __int64 v19; // r12
  unsigned int v20; // edi
  unsigned int v21; // ebx
  unsigned __int64 v22; // rax
  UFG::allocator::free_link *v23; // rax
  UFG::allocator::free_link *v24; // r14
  UFG::allocator::free_link *v25; // rdx
  __int64 v26; // r8
  UFG::allocator::free_link *v27; // rdi
  unsigned int v28; // eax
  UFG::qBaseTreeRB *v29; // rax
  DNA::PropertyData *v30; // rbx
  __int64 v31; // rsi
  UFG::qBaseTreeRB *v32; // rax
  UFG::qBaseTreeRB *Next; // rbp
  unsigned int v34; // edx
  UFG::qBaseTreeRB *v35; // rax
  __int64 v36; // r12
  unsigned int v37; // edi
  unsigned int v38; // ebx
  unsigned __int64 v39; // rax
  UFG::allocator::free_link *v40; // rax
  UFG::allocator::free_link *v41; // r14
  UFG::allocator::free_link *v42; // rcx
  __int64 v43; // rdx
  UFG::allocator::free_link *v44; // rdi
  unsigned int v45; // eax
  UFG::qBaseTreeRB *v46; // rax
  DNA::PropertyData *v47; // rbx
  DNA::SchemaType *SchemaType; // [rsp+30h] [rbp-A8h]
  UFG::qString v49; // [rsp+40h] [rbp-98h] BYREF
  UFG::qString result; // [rsp+68h] [rbp-70h] BYREF
  unsigned __int64 v; // [rsp+F0h] [rbp+18h]
  UFG::qTreeRB<DNA::PropertyData,DNA::PropertyData,1> *p_mProperties; // [rsp+F8h] [rbp+20h]

  v3 = this;
  mUID = 0i64;
  v = 0i64;
  if ( !parent )
    goto LABEL_6;
  mUID = parent->mBaseNode.mUID;
  v = parent->mBaseNode.mUID;
  SchemaName = DNA::PropertyBag::GetSchemaName(this, &result);
  v6 = DNA::PropertyBag::GetSchemaName(parent, &v49);
  LOBYTE(SchemaName) = (unsigned int)UFG::qStringCompare(v6->mData, SchemaName->mData, -1) != 0;
  UFG::qString::~qString(&v49);
  UFG::qString::~qString(&result);
  if ( (_BYTE)SchemaName )
    return;
  v7 = DNA::PropertyBag::GetParent(parent);
  if ( !v7 )
  {
LABEL_6:
    v8 = 0i64;
    Property = DNA::PropertyBag::GetProperty(v3, "$ParentId");
    if ( Property )
    {
      if ( LODWORD(Property[1].mRoot.mParent) == 151281197 )
      {
        Value = DNA::PropertyData::GetValue((DNA::PropertyData *)Property, 0);
        if ( Value )
          v8 = UFG::qToUInt64(Value->mData.mData, 0i64);
      }
    }
    if ( mUID == v8 || mUID == v3->mBaseNode.mUID )
      return;
    v11 = 0i64;
    v12 = 0i64;
    v13 = 0;
    SchemaType = (DNA::SchemaType *)DNA::PropertyBag::GetSchemaType(v3);
    p_mTree = &v3->mProperties.mTree;
    p_mProperties = &v3->mProperties;
    Head = (DNA::PropertyData *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&v3->mProperties);
    if ( Head )
    {
      do
      {
        mData = Head->mName.mData;
        if ( *mData != 36 )
        {
          if ( SchemaType )
          {
            v18 = UFG::qStringHash64(mData, 0xFFFFFFFFFFFFFFFFui64);
            Field = DNA::SchemaType::GetField(SchemaType, v18);
          }
          else
          {
            Field = 0i64;
          }
          if ( (unsigned int)DNA::PropertyData::NumItems(Head) == 1
            && (unsigned int)DNA::PropertyData::GetPropertyState(Head, 0, Field) == 1 )
          {
            v19 = (unsigned int)v12;
            v20 = v12 + 1;
            if ( (int)v12 + 1 > v13 )
            {
              v21 = 1;
              if ( v13 )
                v21 = 2 * v13;
              for ( ; v21 < v20; v21 *= 2 )
                ;
              if ( v21 <= 2 )
                v21 = 2;
              if ( v21 - v20 > 0x10000 )
                v21 = v12 + 65537;
              if ( v21 != (_DWORD)v12 )
              {
                v22 = 8i64 * v21;
                if ( !is_mul_ok(v21, 8ui64) )
                  v22 = -1i64;
                v23 = UFG::qMalloc(v22, "qArray.Add", 0i64);
                v24 = v23;
                if ( v11 )
                {
                  if ( (_DWORD)v12 )
                  {
                    v25 = v23;
                    v26 = (unsigned int)v12;
                    do
                    {
                      v25->mNext = *(UFG::allocator::free_link **)((char *)v25 + (char *)v11 - (char *)v23);
                      ++v25;
                      --v26;
                    }
                    while ( v26 );
                  }
                  operator delete[](v11);
                }
                v11 = v24;
                v13 = v21;
              }
            }
            v12 = v20;
            v11[v19].mNext = (UFG::allocator::free_link *)Head;
            p_mTree = &v3->mProperties.mTree;
          }
        }
        Head = (DNA::PropertyData *)UFG::qBaseTreeRB::GetNext(p_mTree, &Head->mNode);
      }
      while ( Head );
      v3 = this;
    }
    if ( (_DWORD)v12 )
    {
      v27 = v11;
      do
      {
        v28 = UFG::qStringHashUpper32((const char *)v27->mNext[7].mNext, -1);
        if ( v28 )
        {
          v29 = UFG::qBaseTreeRB::Get(p_mTree, v28);
          v30 = (DNA::PropertyData *)v29;
          if ( v29 )
          {
            UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
              (UFG::qBaseTreeVariableRB<unsigned __int64> *)p_mTree,
              (UFG::qBaseNodeVariableRB<unsigned __int64> *)v29);
            DNA::PropertyData::~PropertyData(v30);
            operator delete[](v30);
          }
        }
        ++v27;
        --v12;
      }
      while ( v12 );
    }
    v31 = 0i64;
    v32 = DNA::PropertyBag::CreateProperty(v3, "$ParentId", (DNA::PropertyType::Enum)151281197);
    if ( v32 )
      DNA::PropertyData::Set((DNA::PropertyData *)v32, 0, v, 0);
    Next = (UFG::qBaseTreeRB *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)p_mTree);
    if ( !Next )
    {
LABEL_75:
      if ( (_DWORD)v31 )
      {
        v44 = v11;
        do
        {
          v45 = UFG::qStringHashUpper32((const char *)v44->mNext[7].mNext, -1);
          if ( v45 )
          {
            v46 = UFG::qBaseTreeRB::Get(p_mTree, v45);
            v47 = (DNA::PropertyData *)v46;
            if ( v46 )
            {
              UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
                (UFG::qBaseTreeVariableRB<unsigned __int64> *)p_mTree,
                (UFG::qBaseNodeVariableRB<unsigned __int64> *)v46);
              DNA::PropertyData::~PropertyData(v47);
              operator delete[](v47);
            }
          }
          ++v44;
          --v31;
        }
        while ( v31 );
      }
      if ( v11 )
        operator delete[](v11);
      return;
    }
    while ( 1 )
    {
      if ( **(_BYTE **)&Next->mNULL.mUID != 36 )
      {
        if ( parent )
        {
          v34 = Next->mRoot.mUID;
          if ( !v34 )
            goto LABEL_74;
          v35 = UFG::qBaseTreeRB::Get(&parent->mProperties.mTree, v34);
          if ( !v35 )
            goto LABEL_74;
          if ( LODWORD(Next[1].mRoot.mParent) != LODWORD(v35[1].mRoot.mParent) )
          {
            v36 = (unsigned int)v31;
            v37 = v31 + 1;
            if ( (int)v31 + 1 > v13 )
            {
              v38 = 1;
              if ( v13 )
                v38 = 2 * v13;
              for ( ; v38 < v37; v38 *= 2 )
                ;
              if ( v38 <= 2 )
                v38 = 2;
              if ( v38 - v37 > 0x10000 )
                v38 = v31 + 65537;
              if ( v38 != (_DWORD)v31 )
              {
                v39 = 8i64 * v38;
                if ( !is_mul_ok(v38, 8ui64) )
                  v39 = -1i64;
                v40 = UFG::qMalloc(v39, "qArray.Add", 0i64);
                v41 = v40;
                if ( v11 )
                {
                  if ( (_DWORD)v31 )
                  {
                    v42 = v40;
                    v43 = (unsigned int)v31;
                    do
                    {
                      v42->mNext = *(UFG::allocator::free_link **)((char *)v42 + (char *)v11 - (char *)v40);
                      ++v42;
                      --v43;
                    }
                    while ( v43 );
                  }
                  operator delete[](v11);
                }
                v11 = v41;
                v13 = v38;
              }
            }
            v31 = v37;
            v11[v36].mNext = (UFG::allocator::free_link *)Next;
            p_mTree = &p_mProperties->mTree;
            goto LABEL_74;
          }
        }
        DNA::PropertyData::UpdateInheritanceBinding((DNA::PropertyData *)Next, eStatic);
      }
LABEL_74:
      Next = UFG::qBaseTreeRB::GetNext(p_mTree, &Next->mRoot);
      if ( !Next )
        goto LABEL_75;
    }
  }
  while ( v7->mHead.mUID != v3->mBaseNode.mUID )
  {
    v7 = DNA::PropertyBag::GetParent((DNA::PropertyBag *)v7);
    if ( !v7 )
      goto LABEL_6;
  }
}

// File Line: 777
// RVA: 0x1A5F90
void __fastcall DNA::PropertyBag::MarkDirty(DNA::PropertyBag *this)
{
  DNA::PropertyBag *v1; // rsi
  unsigned __int64 v2; // rbx
  UFG::qBaseTreeRB *Property; // rax
  DNA::PropertyData::Value *Value; // rax
  DNA::Database *v5; // rax
  DNA::PropertyBag *PropertyBag; // rdi
  unsigned __int64 v7; // rbp
  unsigned int v8; // eax
  UFG::qBaseTreeRB *v9; // rbx
  UFG::qTree64Base *Parent; // rax
  DNA::PropertyData::Value *v11; // rax
  DNA::Database *v12; // rax
  DNA::Event<void __cdecl(DNA::PropertyBag *)> *v13; // rax

  v1 = this;
  if ( !this->mIsDirtyLock )
  {
    v2 = 0i64;
    Property = DNA::PropertyBag::GetProperty(this, "$OwnerId");
    if ( Property )
    {
      if ( LODWORD(Property[1].mRoot.mParent) == 151281197 )
      {
        Value = DNA::PropertyData::GetValue((DNA::PropertyData *)Property, 0);
        if ( Value )
          v2 = UFG::qToUInt64(Value->mData.mData, 0i64);
      }
    }
    DNA::Database::Instance();
    PropertyBag = (DNA::PropertyBag *)DNA::Database::GetPropertyBag(v5, v2);
    if ( PropertyBag )
    {
      while ( 1 )
      {
        v1 = PropertyBag;
        if ( PropertyBag->mIsDirtyLock )
          return;
        v7 = 0i64;
        v8 = UFG::qStringHashUpper32("$OwnerId", -1);
        if ( !v8 )
          break;
        v9 = UFG::qBaseTreeRB::Get(&PropertyBag->mProperties.mTree, v8);
        if ( !v9 )
          goto LABEL_11;
LABEL_16:
        if ( LODWORD(v9[1].mRoot.mParent) == 151281197 )
        {
          v11 = DNA::PropertyData::GetValue((DNA::PropertyData *)v9, 0);
          if ( v11 )
            v7 = UFG::qToUInt64(v11->mData.mData, 0i64);
        }
LABEL_19:
        DNA::Database::Instance();
        PropertyBag = (DNA::PropertyBag *)DNA::Database::GetPropertyBag(v12, v7);
        if ( !PropertyBag )
          goto LABEL_20;
      }
      v9 = 0i64;
LABEL_11:
      if ( !(unsigned int)UFG::qStringCompare("$OwnerId", "$ParentId", -1)
        || !(unsigned int)UFG::qStringCompare("$OwnerId", "$OwnerId", -1) )
      {
        goto LABEL_19;
      }
      Parent = DNA::PropertyBag::GetParent(PropertyBag);
      if ( Parent )
        v9 = DNA::PropertyBag::GetProperty((DNA::PropertyBag *)Parent, "$OwnerId");
      if ( !v9 )
        goto LABEL_19;
      goto LABEL_16;
    }
LABEL_20:
    if ( !v1->mIsDirty )
    {
      v1->mIsDirty = 1;
      DNA::Database::Instance();
      DNA::Event<void (DNA::PropertyBag *)>::Invoke(v13 + 2, v1);
    }
  }
}

// File Line: 814
// RVA: 0x1A3EF0
void __fastcall DNA::PropertyData::PropertyData(
        DNA::PropertyData *this,
        DNA::PropertyBag *propertyOwner,
        const char *propertyName,
        DNA::PropertyType::Enum type)
{
  unsigned int v8; // eax

  v8 = UFG::qStringHashUpper32(propertyName, -1);
  this->mNode.mParent = 0i64;
  this->mNode.mChild[0] = 0i64;
  this->mNode.mChild[1] = 0i64;
  this->mNode.mUID = v8;
  UFG::qString::qString(&this->mName, propertyName);
  this->mPropertyType = type;
  this->mOwner = propertyOwner;
  this->mOverrideMode = eOverride;
  this->mArrayEntries.p = 0i64;
  *(_QWORD *)&this->mArrayEntries.size = 0i64;
  this->mOverrideArrayEntries.p = 0i64;
  *(_QWORD *)&this->mOverrideArrayEntries.size = 0i64;
  if ( *propertyName == 36 )
    this->mOverrideMode = eInherit;
}

// File Line: 849
// RVA: 0x1A43E0
void __fastcall DNA::PropertyData::~PropertyData(DNA::PropertyData *this)
{
  unsigned int i; // edi
  DNA::PropertyData::Value **p; // rax
  DNA::PropertyData::Value *v4; // rsi
  DNA::PropertyData::Value **v5; // rcx
  unsigned int j; // edi
  DNA::PropertyData::Value **v7; // rax
  DNA::PropertyData::Value *v8; // rsi
  DNA::PropertyData::Value **v9; // rcx
  DNA::PropertyData::Value **v10; // rcx
  DNA::PropertyData::Value **v11; // rcx

  for ( i = 0; i < this->mArrayEntries.size; ++i )
  {
    p = this->mArrayEntries.p;
    v4 = p[i];
    if ( v4 )
    {
      DNA::PropertyData::Value::~Value(p[i]);
      operator delete[](v4);
    }
  }
  v5 = this->mArrayEntries.p;
  if ( v5 )
    operator delete[](v5);
  this->mArrayEntries.p = 0i64;
  *(_QWORD *)&this->mArrayEntries.size = 0i64;
  for ( j = 0; j < this->mOverrideArrayEntries.size; ++j )
  {
    v7 = this->mOverrideArrayEntries.p;
    v8 = v7[j];
    if ( v8 )
    {
      DNA::PropertyData::Value::~Value(v7[j]);
      operator delete[](v8);
    }
  }
  v9 = this->mOverrideArrayEntries.p;
  if ( v9 )
    operator delete[](v9);
  this->mOverrideArrayEntries.p = 0i64;
  *(_QWORD *)&this->mOverrideArrayEntries.size = 0i64;
  this->mOwner = 0i64;
  v10 = this->mOverrideArrayEntries.p;
  if ( v10 )
    operator delete[](v10);
  this->mOverrideArrayEntries.p = 0i64;
  *(_QWORD *)&this->mOverrideArrayEntries.size = 0i64;
  v11 = this->mArrayEntries.p;
  if ( v11 )
    operator delete[](v11);
  this->mArrayEntries.p = 0i64;
  *(_QWORD *)&this->mArrayEntries.size = 0i64;
  UFG::qString::~qString(&this->mName);
}

// File Line: 943
// RVA: 0x1A4750
__int64 __fastcall DNA::PropertyData::Add(DNA::PropertyData *this, unsigned int undoId)
{
  unsigned int v4; // ebp
  UFG::allocator::free_link *v5; // rbx
  UFG::allocator::free_link *v6; // rax
  UFG::allocator::free_link *v7; // rax
  UFG::allocator::free_link *v8; // rcx
  __int64 v9; // rax

  v4 = DNA::PropertyData::NumItems(this);
  v5 = UFG::qMalloc(0x30ui64, UFG::gGlobalNewName, 0i64);
  if ( v5 )
  {
    v6 = UFG::qMalloc(0x50ui64, UFG::gGlobalNewName, 0i64);
    if ( v6 )
    {
      DNA::PropertyData::Value::Value((DNA::PropertyData::Value *)v6, this);
      v8 = v7;
    }
    else
    {
      v8 = 0i64;
    }
    v5[1].mNext = v5 + 1;
    v5[2].mNext = v5 + 1;
    v5->mNext = (UFG::allocator::free_link *)&DNA::IAction::`vftable;
    LOBYTE(v5[3].mNext) = 1;
    *(UFG::allocator::free_link **)((char *)&v5[3].mNext + 4) = (UFG::allocator::free_link *)1601572253;
    v5->mNext = (UFG::allocator::free_link *)&DNA::PropertyData::AddValueAction::`vftable;
    v5[5].mNext = v8;
  }
  else
  {
    v5 = 0i64;
  }
  DNA::Database::Instance();
  DNA::ActionManager::AppendAction((DNA::ActionManager *)(v9 + 312), (DNA::IAction *)v5, undoId);
  return v4;
}

// File Line: 967
// RVA: 0x1A5D50
DNA::SchemaField *__fastcall DNA::PropertyData::GetSchemaField(DNA::PropertyData *this)
{
  char *mData; // rbx
  DNA::Database *v3; // rax
  UFG::qTree64Base *Schema; // rbx
  unsigned __int64 v5; // rax
  UFG::qString result; // [rsp+28h] [rbp-30h] BYREF

  mData = DNA::PropertyBag::GetSchemaName(this->mOwner, &result)->mData;
  DNA::Database::Instance();
  Schema = DNA::Database::GetSchema(v3, mData);
  UFG::qString::~qString(&result);
  if ( !Schema )
    return 0i64;
  v5 = UFG::qStringHash64(this->mName.mData, 0xFFFFFFFFFFFFFFFFui64);
  return DNA::SchemaType::GetField((DNA::SchemaType *)Schema, v5);
}

// File Line: 974
// RVA: 0x1A7760
void __fastcall DNA::PropertyData::UpdateInheritanceBinding(
        DNA::PropertyData *this,
        DNA::PropertyData::eOverrideOption overrideOption)
{
  DNA::PropertyData::eOverrideOption v2; // r12d
  __int64 v4; // r13
  unsigned int v5; // r14d
  DNA::PropertyData::Value *v6; // r15
  unsigned int size; // ecx
  unsigned int v8; // esi
  unsigned int capacity; // edi
  unsigned int v10; // edi
  unsigned __int64 v11; // rax
  UFG::allocator::free_link *v12; // rax
  DNA::PropertyData::Value **v13; // rbp
  unsigned int i; // r9d
  __int64 v15; // r8
  __int64 v16; // r9
  DNA::PropertyData::Value *mOverridenValue; // rdx
  __int64 v18; // rcx
  unsigned int v19; // r8d
  DNA::PropertyData::Value **p; // r9
  unsigned int v21; // eax
  DNA::PropertyData::eOverrideMode mOverrideMode; // eax
  UFG::qTree64Base *v23; // rax
  UFG::qBaseTreeRB *v24; // r15
  DNA::SchemaField *SchemaField; // rax
  int mArrayLength; // eax
  char v27; // al
  bool v28; // zf
  unsigned int v29; // esi
  unsigned int mUID; // edi
  UFG::qTree64Base *Parent; // rax
  UFG::qBaseTreeRB *Property; // rax
  int v33; // eax
  unsigned int v34; // eax
  int v35; // r13d
  DNA::PropertyData::Value *v36; // r12
  unsigned int j; // ebp
  unsigned int v38; // edi
  UFG::qTree64Base *v39; // rax
  UFG::qBaseTreeRB *v40; // rax
  int v41; // eax
  DNA::PropertyData::Value *Value; // rax
  DNA::PropertyData::Value *v43; // rsi
  int v44; // r8d
  __int64 v45; // rdx
  unsigned int v46; // eax
  __int64 v47; // r13
  unsigned int v48; // ebp
  unsigned int v49; // edi
  unsigned int v50; // edi
  unsigned __int64 v51; // rax
  UFG::allocator::free_link *v52; // rax
  DNA::PropertyData::Value **v53; // r12
  unsigned int k; // r9d
  unsigned __int64 v55; // rdi
  DNA::Database *v56; // rax
  UFG::qTree64Base *PropertyBag; // rbp
  unsigned __int64 v58; // rdi
  DNA::Database *v59; // rax
  UFG::qTree64Base *v60; // rax
  DNA::PropertyData::Value **v61; // rcx
  __int64 v62; // r13
  unsigned int v63; // ebp
  unsigned int v64; // edi
  unsigned int v65; // edi
  unsigned __int64 v66; // rax
  UFG::allocator::free_link *v67; // rax
  UFG::allocator::free_link *v68; // r12
  unsigned int m; // r9d
  unsigned __int64 v70; // rdi
  DNA::Database *v71; // rax
  UFG::qTree64Base *v72; // rax
  __int64 v73; // [rsp+20h] [rbp-78h]
  DNA::PropertyData::Value *v74; // [rsp+28h] [rbp-70h]
  bool v75; // [rsp+A0h] [rbp+8h]
  unsigned int v77; // [rsp+B0h] [rbp+18h]
  int v78; // [rsp+B8h] [rbp+20h]
  int v79; // [rsp+B8h] [rbp+20h]

  v2 = overrideOption;
  LODWORD(v4) = this->mOverrideArrayEntries.size;
  v5 = 0;
  if ( (_DWORD)v4 )
  {
    do
    {
      v4 = (unsigned int)(v4 - 1);
      v6 = this->mOverrideArrayEntries.p[v4];
      size = this->mArrayEntries.size;
      v8 = size + 1;
      capacity = this->mArrayEntries.capacity;
      if ( size + 1 > capacity )
      {
        if ( capacity )
          v10 = 2 * capacity;
        else
          v10 = 1;
        for ( ; v10 < v8; v10 *= 2 )
          ;
        if ( v10 <= 2 )
          v10 = 2;
        if ( v10 - v8 > 0x10000 )
          v10 = size + 65537;
        if ( v10 != size )
        {
          v11 = 8i64 * v10;
          if ( !is_mul_ok(v10, 8ui64) )
            v11 = -1i64;
          v12 = UFG::qMalloc(v11, "qArray.Insert", 0i64);
          v13 = (DNA::PropertyData::Value **)v12;
          if ( this->mArrayEntries.p )
          {
            for ( i = 0; i < this->mArrayEntries.size; ++i )
              v12[i] = (UFG::allocator::free_link)this->mArrayEntries.p[i];
            operator delete[](this->mArrayEntries.p);
          }
          this->mArrayEntries.p = v13;
          this->mArrayEntries.capacity = v10;
        }
      }
      this->mArrayEntries.size = v8;
      v15 = v8 - 1;
      if ( v8 != 1 )
      {
        v16 = v15;
        do
        {
          LODWORD(v15) = v15 - 1;
          this->mArrayEntries.p[v16--] = this->mArrayEntries.p[(unsigned int)v15];
        }
        while ( (_DWORD)v15 );
      }
      *this->mArrayEntries.p = v6;
      mOverridenValue = v6->mOverridenValue;
      if ( mOverridenValue )
      {
        v18 = 0i64;
        v19 = mOverridenValue->mInheritedValues.size;
        if ( v19 )
        {
          p = mOverridenValue->mInheritedValues.p;
          while ( v6 != p[v18] )
          {
            v18 = (unsigned int)(v18 + 1);
            if ( (unsigned int)v18 >= v19 )
              goto LABEL_33;
          }
          if ( (int)v18 >= 0 )
          {
            p[v18] = p[v19 - 1];
            v21 = mOverridenValue->mInheritedValues.size;
            if ( v21 > 1 )
              mOverridenValue->mInheritedValues.size = v21 - 1;
            else
              mOverridenValue->mInheritedValues.size = 0;
          }
        }
LABEL_33:
        v6->mOverridenValue = 0i64;
      }
    }
    while ( (_DWORD)v4 );
    v2 = overrideOption;
  }
  this->mOverrideArrayEntries.size = 0;
  mOverrideMode = this->mOverrideMode;
  if ( mOverrideMode != eInherit )
  {
    if ( mOverrideMode == eOverride
      && (v23 = DNA::PropertyBag::GetParent(this->mOwner)) != 0i64
      && (v24 = DNA::PropertyBag::GetProperty((DNA::PropertyBag *)v23, this->mName.mData)) != 0i64 )
    {
      v75 = 0;
      if ( v2 == eStatic )
      {
        SchemaField = DNA::PropertyData::GetSchemaField(this);
        if ( SchemaField )
        {
          mArrayLength = SchemaField->mArrayLength;
          if ( mArrayLength > 1 || (v28 = mArrayLength == -1, v27 = 0, v28) )
            v27 = 1;
          v28 = v27 == 0;
        }
        else
        {
          v29 = this->mArrayEntries.size;
          mUID = v24[1].mRoot.mUID;
          if ( !LODWORD(v24[1].mRoot.mChild[1]) )
          {
            Parent = DNA::PropertyBag::GetParent((DNA::PropertyBag *)v24[1].mRoot.mChild[0]);
            if ( Parent
              && (Property = DNA::PropertyBag::GetProperty((DNA::PropertyBag *)Parent, *(const char **)&v24->mNULL.mUID)) != 0i64 )
            {
              v33 = DNA::PropertyData::NumItems((DNA::PropertyData *)Property);
            }
            else
            {
              v33 = 0;
            }
            mUID += v33;
          }
          if ( mUID > v29 )
            v29 = mUID;
          v28 = v29 == 1;
        }
        v75 = v28;
      }
      v34 = 0;
      v77 = 0;
      if ( this->mArrayEntries.size )
      {
        v35 = 1;
        v78 = 1;
        v73 = 8i64;
        do
        {
          v36 = this->mArrayEntries.p[v34];
          v74 = v36;
          for ( j = 0; ; ++j )
          {
            v38 = v24[1].mRoot.mUID;
            if ( !LODWORD(v24[1].mRoot.mChild[1]) )
            {
              v39 = DNA::PropertyBag::GetParent((DNA::PropertyBag *)v24[1].mRoot.mChild[0]);
              if ( v39
                && (v40 = DNA::PropertyBag::GetProperty((DNA::PropertyBag *)v39, *(const char **)&v24->mNULL.mUID)) != 0i64 )
              {
                v41 = DNA::PropertyData::NumItems((DNA::PropertyData *)v40);
              }
              else
              {
                v41 = 0;
              }
              v38 += v41;
            }
            if ( j >= v38 )
              break;
            Value = DNA::PropertyData::GetValue((DNA::PropertyData *)v24, j);
            v43 = Value;
            if ( v75 )
              v36->mID = Value->mID;
            if ( v36->mID == Value->mID )
            {
              v44 = v35;
              if ( v35 != this->mArrayEntries.size )
              {
                v45 = v73;
                do
                {
                  *(DNA::PropertyData::Value **)((char *)this->mArrayEntries.p + v45 - 8) = *(DNA::PropertyData::Value **)((char *)this->mArrayEntries.p + v45);
                  ++v44;
                  v45 += 8i64;
                }
                while ( v44 != this->mArrayEntries.size );
              }
              v46 = this->mArrayEntries.size;
              if ( v46 > 1 )
                this->mArrayEntries.size = v46 - 1;
              else
                this->mArrayEntries.size = 0;
              v47 = this->mOverrideArrayEntries.size;
              v48 = v47 + 1;
              v49 = this->mOverrideArrayEntries.capacity;
              if ( (int)v47 + 1 > v49 )
              {
                if ( v49 )
                  v50 = 2 * v49;
                else
                  v50 = 1;
                for ( ; v50 < v48; v50 *= 2 )
                  ;
                if ( v50 <= 2 )
                  v50 = 2;
                if ( v50 - v48 > 0x10000 )
                  v50 = v47 + 65537;
                if ( v50 != (_DWORD)v47 )
                {
                  v51 = 8i64 * v50;
                  if ( !is_mul_ok(v50, 8ui64) )
                    v51 = -1i64;
                  v52 = UFG::qMalloc(v51, "qArray.Add", 0i64);
                  v53 = (DNA::PropertyData::Value **)v52;
                  if ( this->mOverrideArrayEntries.p )
                  {
                    for ( k = 0; k < this->mOverrideArrayEntries.size; ++k )
                      v52[k] = (UFG::allocator::free_link)this->mOverrideArrayEntries.p[k];
                    operator delete[](this->mOverrideArrayEntries.p);
                  }
                  this->mOverrideArrayEntries.p = v53;
                  this->mOverrideArrayEntries.capacity = v50;
                  v36 = v74;
                }
              }
              this->mOverrideArrayEntries.size = v48;
              this->mOverrideArrayEntries.p[v47] = v36;
              --v77;
              v79 = v78 - 1;
              v73 -= 8i64;
              if ( this->mPropertyType == -915936389 )
              {
                v55 = UFG::qToUInt64(v36->mData.mData, 0i64);
                DNA::Database::Instance();
                PropertyBag = DNA::Database::GetPropertyBag(v56, v55);
                v58 = UFG::qToUInt64(v43->mData.mData, 0i64);
                DNA::Database::Instance();
                v60 = DNA::Database::GetPropertyBag(v59, v58);
                if ( PropertyBag )
                {
                  if ( v60 )
                    DNA::PropertyBag::SetParent((DNA::PropertyBag *)PropertyBag, (DNA::PropertyBag *)v60);
                }
              }
              if ( v43->mInheritedValues.size )
              {
                v61 = v43->mInheritedValues.p;
                if ( v61 )
                  operator delete[](v61);
                v43->mInheritedValues.p = 0i64;
                *(_QWORD *)&v43->mInheritedValues.size = 0i64;
              }
              v36->mOverridenValue = v43;
              v62 = v43->mInheritedValues.size;
              v63 = v62 + 1;
              v64 = v43->mInheritedValues.capacity;
              if ( (int)v62 + 1 > v64 )
              {
                if ( v64 )
                  v65 = 2 * v64;
                else
                  v65 = 1;
                for ( ; v65 < v63; v65 *= 2 )
                  ;
                if ( v65 <= 2 )
                  v65 = 2;
                if ( v65 - v63 > 0x10000 )
                  v65 = v62 + 65537;
                if ( v65 != (_DWORD)v62 )
                {
                  v66 = 8i64 * v65;
                  if ( !is_mul_ok(v65, 8ui64) )
                    v66 = -1i64;
                  v67 = UFG::qMalloc(v66, "qArray.Add", 0i64);
                  v68 = v67;
                  if ( v43->mInheritedValues.p )
                  {
                    for ( m = 0; m < v43->mInheritedValues.size; ++m )
                      v67[m] = (UFG::allocator::free_link)v43->mInheritedValues.p[m];
                    operator delete[](v43->mInheritedValues.p);
                  }
                  v43->mInheritedValues.p = (DNA::PropertyData::Value **)v68;
                  v43->mInheritedValues.capacity = v65;
                  v36 = v74;
                }
              }
              v43->mInheritedValues.size = v63;
              v43->mInheritedValues.p[v62] = v36;
              v35 = v79;
              break;
            }
          }
          v34 = v77 + 1;
          v77 = v34;
          v78 = ++v35;
          v73 += 8i64;
        }
        while ( v34 < this->mArrayEntries.size );
      }
    }
    else if ( this->mPropertyType == -915936389 && this->mArrayEntries.size )
    {
      do
      {
        if ( this->mPropertyType == -915936389 )
        {
          v70 = UFG::qToUInt64(this->mArrayEntries.p[v5]->mData.mData, 0i64);
          DNA::Database::Instance();
          v72 = DNA::Database::GetPropertyBag(v71, v70);
          if ( v72 )
            DNA::PropertyBag::SetParent((DNA::PropertyBag *)v72, 0i64);
        }
        ++v5;
      }
      while ( v5 < this->mArrayEntries.size );
    }
  }
}

// File Line: 1100
// RVA: 0x1A6120
__int64 __fastcall DNA::PropertyData::NumItems(DNA::PropertyData *this)
{
  unsigned int size; // ebx
  UFG::qTree64Base *Parent; // rax
  UFG::qBaseTreeRB *Property; // rax

  size = this->mArrayEntries.size;
  if ( this->mOverrideMode )
    return size;
  Parent = DNA::PropertyBag::GetParent(this->mOwner);
  if ( Parent && (Property = DNA::PropertyBag::GetProperty((DNA::PropertyBag *)Parent, this->mName.mData)) != 0i64 )
    return size + DNA::PropertyData::NumItems((DNA::PropertyData *)Property);
  else
    return size;
}

// File Line: 1129
// RVA: 0x1A5450
void __fastcall DNA::PropertyData::Get(DNA::PropertyData *this, unsigned int index, unsigned __int64 *v)
{
  DNA::PropertyData::Value *Value; // rax

  if ( this->mPropertyType == 151281197 )
  {
    Value = DNA::PropertyData::GetValue(this, index);
    if ( Value )
      *v = UFG::qToUInt64(Value->mData.mData, 0i64);
  }
}

// File Line: 1132
// RVA: 0x1A53E0
void __fastcall DNA::PropertyData::Get(DNA::PropertyData *this, unsigned int index, float *v)
{
  DNA::PropertyData::Value *Value; // rax
  char *mData; // rcx

  if ( this->mPropertyType == 1208522079 )
  {
    Value = DNA::PropertyData::GetValue(this, index);
    if ( Value )
    {
      mData = Value->mData.mData;
      if ( *mData == 48 && ((mData[1] - 88) & 0xDF) == 0 || *mData == 35 )
        *(_DWORD *)v = UFG::qToUInt32(mData, 0);
      else
        *v = UFG::qToFloat(mData, 0.0);
    }
  }
}

// File Line: 1133
// RVA: 0x1A5480
void __fastcall DNA::PropertyData::Get(DNA::PropertyData *this, unsigned int index, UFG::qTree64Base **v)
{
  DNA::PropertyData::Value *Value; // rax
  unsigned __int64 v5; // rbx
  DNA::Database *v6; // rax

  if ( this->mPropertyType == -915936389 )
  {
    Value = DNA::PropertyData::GetValue(this, index);
    if ( Value )
    {
      v5 = UFG::qToUInt64(Value->mData.mData, 0i64);
      DNA::Database::Instance();
      *v = DNA::Database::GetPropertyBag(v6, v5);
    }
  }
}

// File Line: 1135
// RVA: 0x1A5D20
void __fastcall DNA::PropertyData::GetRaw(DNA::PropertyData *this, unsigned int index, UFG::qString *v)
{
  DNA::PropertyData::Value *Value; // rax

  Value = DNA::PropertyData::GetValue(this, index);
  if ( Value )
    UFG::qString::Set(v, Value->mData.mData);
}

// File Line: 1138
// RVA: 0x1A6A00
void __fastcall DNA::PropertyData::Set(DNA::PropertyData *this, unsigned int index, const char *v, unsigned int undoId)
{
  DNA::PropertyData::Value *Value; // rax
  DNA::PropertyData::Value *v8; // rbx
  UFG::allocator::free_link *v9; // rax
  DNA::PropertyData::SetValueAction *v10; // rax
  DNA::PropertyData::SetValueAction *v11; // rbx
  __int64 v12; // rax

  if ( this->mPropertyType == 826535573 )
  {
    Value = DNA::PropertyData::GetValue(this, index);
    v8 = DNA::PropertyData::OverrideValue(this, Value);
    if ( v8 )
    {
      v9 = UFG::qMalloc(0x80ui64, "SetValueAction", 0i64);
      if ( v9 )
      {
        DNA::PropertyData::SetValueAction::SetValueAction((DNA::PropertyData::SetValueAction *)v9, v8);
        v11 = v10;
      }
      else
      {
        v11 = 0i64;
      }
      UFG::qString::Set(&v11->mNewValue, v);
      DNA::PropertyData::SetValueAction::Validate(v11);
      DNA::Database::Instance();
      DNA::ActionManager::AppendAction((DNA::ActionManager *)(v12 + 312), v11, undoId);
    }
  }
}

// File Line: 1139
// RVA: 0x1A6630
void __fastcall DNA::PropertyData::Set(DNA::PropertyData *this, unsigned int index, int v, unsigned int undoId)
{
  DNA::PropertyData::Value *Value; // rax
  DNA::PropertyData::Value *v8; // rbx
  UFG::allocator::free_link *v9; // rax
  DNA::PropertyData::SetValueAction *v10; // rax
  DNA::PropertyData::SetValueAction *v11; // rbx
  UFG::qString *v12; // rax
  __int64 v13; // rax
  UFG::qString result; // [rsp+38h] [rbp-30h] BYREF

  if ( this->mPropertyType == -2133091136 )
  {
    Value = DNA::PropertyData::GetValue(this, index);
    v8 = DNA::PropertyData::OverrideValue(this, Value);
    if ( v8 )
    {
      v9 = UFG::qMalloc(0x80ui64, "SetValueAction", 0i64);
      if ( v9 )
      {
        DNA::PropertyData::SetValueAction::SetValueAction((DNA::PropertyData::SetValueAction *)v9, v8);
        v11 = v10;
      }
      else
      {
        v11 = 0i64;
      }
      v12 = UFG::qToHex(&result, v);
      UFG::qString::Set(&v11->mNewValue, v12->mData, v12->mLength, 0i64, 0);
      UFG::qString::~qString(&result);
      DNA::PropertyData::SetValueAction::Validate(v11);
      DNA::Database::Instance();
      DNA::ActionManager::AppendAction((DNA::ActionManager *)(v13 + 312), v11, undoId);
    }
  }
}

// File Line: 1140
// RVA: 0x1A6AB0
void __fastcall DNA::PropertyData::Set(DNA::PropertyData *this, unsigned int index, __int64 v, unsigned int undoId)
{
  DNA::PropertyData::Value *Value; // rax
  DNA::PropertyData::Value *v8; // rbx
  UFG::allocator::free_link *v9; // rax
  DNA::PropertyData::SetValueAction *v10; // rax
  DNA::PropertyData::SetValueAction *v11; // rbx
  UFG::qString *v12; // rax
  __int64 v13; // rax
  UFG::qString result; // [rsp+38h] [rbp-30h] BYREF

  if ( this->mPropertyType == 224407815 )
  {
    Value = DNA::PropertyData::GetValue(this, index);
    v8 = DNA::PropertyData::OverrideValue(this, Value);
    if ( v8 )
    {
      v9 = UFG::qMalloc(0x80ui64, "SetValueAction", 0i64);
      if ( v9 )
      {
        DNA::PropertyData::SetValueAction::SetValueAction((DNA::PropertyData::SetValueAction *)v9, v8);
        v11 = v10;
      }
      else
      {
        v11 = 0i64;
      }
      v12 = UFG::qToHex(&result, v);
      UFG::qString::Set(&v11->mNewValue, v12->mData, v12->mLength, 0i64, 0);
      UFG::qString::~qString(&result);
      DNA::PropertyData::SetValueAction::Validate(v11);
      DNA::Database::Instance();
      DNA::ActionManager::AppendAction((DNA::ActionManager *)(v13 + 312), v11, undoId);
    }
  }
}

// File Line: 1141
// RVA: 0x1A6720
void __fastcall DNA::PropertyData::Set(
        DNA::PropertyData *this,
        unsigned int index,
        unsigned int v,
        unsigned int undoId)
{
  DNA::PropertyData::Value *Value; // rax
  DNA::PropertyData::Value *v8; // rbx
  UFG::allocator::free_link *v9; // rax
  DNA::PropertyData::SetValueAction *v10; // rax
  DNA::PropertyData::SetValueAction *v11; // rbx
  UFG::qString *v12; // rax
  __int64 v13; // rax
  UFG::qString result; // [rsp+38h] [rbp-30h] BYREF

  if ( this->mPropertyType == -2067794966 )
  {
    Value = DNA::PropertyData::GetValue(this, index);
    v8 = DNA::PropertyData::OverrideValue(this, Value);
    if ( v8 )
    {
      v9 = UFG::qMalloc(0x80ui64, "SetValueAction", 0i64);
      if ( v9 )
      {
        DNA::PropertyData::SetValueAction::SetValueAction((DNA::PropertyData::SetValueAction *)v9, v8);
        v11 = v10;
      }
      else
      {
        v11 = 0i64;
      }
      v12 = UFG::qToHex(&result, v);
      UFG::qString::Set(&v11->mNewValue, v12->mData, v12->mLength, 0i64, 0);
      UFG::qString::~qString(&result);
      DNA::PropertyData::SetValueAction::Validate(v11);
      DNA::Database::Instance();
      DNA::ActionManager::AppendAction((DNA::ActionManager *)(v13 + 312), v11, undoId);
    }
  }
}

// File Line: 1142
// RVA: 0x1A6BA0
void __fastcall DNA::PropertyData::Set(
        DNA::PropertyData *this,
        unsigned int index,
        unsigned __int64 v,
        unsigned int undoId)
{
  DNA::PropertyData::Value *Value; // rax
  DNA::PropertyData::Value *v8; // rbx
  UFG::allocator::free_link *v9; // rax
  DNA::PropertyData::SetValueAction *v10; // rax
  DNA::PropertyData::SetValueAction *v11; // rbx
  UFG::qString *v12; // rax
  __int64 v13; // rax
  UFG::qString result; // [rsp+38h] [rbp-30h] BYREF

  if ( this->mPropertyType == 151281197 )
  {
    Value = DNA::PropertyData::GetValue(this, index);
    v8 = DNA::PropertyData::OverrideValue(this, Value);
    if ( v8 )
    {
      v9 = UFG::qMalloc(0x80ui64, "SetValueAction", 0i64);
      if ( v9 )
      {
        DNA::PropertyData::SetValueAction::SetValueAction((DNA::PropertyData::SetValueAction *)v9, v8);
        v11 = v10;
      }
      else
      {
        v11 = 0i64;
      }
      v12 = UFG::qToHex(&result, v);
      UFG::qString::Set(&v11->mNewValue, v12->mData, v12->mLength, 0i64, 0);
      UFG::qString::~qString(&result);
      DNA::PropertyData::SetValueAction::Validate(v11);
      DNA::Database::Instance();
      DNA::ActionManager::AppendAction((DNA::ActionManager *)(v13 + 312), v11, undoId);
    }
  }
}

// File Line: 1143
// RVA: 0x1A6C90
void __fastcall DNA::PropertyData::Set(DNA::PropertyData *this, unsigned int index, bool v, unsigned int undoId)
{
  DNA::PropertyData::Value *Value; // rax
  DNA::PropertyData::Value *v8; // rbx
  UFG::allocator::free_link *v9; // rax
  DNA::PropertyData::SetValueAction *v10; // rax
  DNA::PropertyData::SetValueAction *v11; // rbx
  const char *v12; // rdx
  __int64 v13; // rax

  if ( this->mPropertyType == 1138723642 )
  {
    Value = DNA::PropertyData::GetValue(this, index);
    v8 = DNA::PropertyData::OverrideValue(this, Value);
    if ( v8 )
    {
      v9 = UFG::qMalloc(0x80ui64, "SetValueAction", 0i64);
      if ( v9 )
      {
        DNA::PropertyData::SetValueAction::SetValueAction((DNA::PropertyData::SetValueAction *)v9, v8);
        v11 = v10;
      }
      else
      {
        v11 = 0i64;
      }
      v12 = "false";
      if ( v )
        v12 = "true";
      UFG::qString::Set(&v11->mNewValue, v12);
      DNA::PropertyData::SetValueAction::Validate(v11);
      DNA::Database::Instance();
      DNA::ActionManager::AppendAction((DNA::ActionManager *)(v13 + 312), v11, undoId);
    }
  }
}

// File Line: 1145
// RVA: 0x1A6810
void __fastcall DNA::PropertyData::Set(DNA::PropertyData *this, unsigned int index, float v, unsigned int undoId)
{
  DNA::PropertyData::Value *Value; // rax
  DNA::PropertyData::Value *v7; // rbx
  UFG::allocator::free_link *v8; // rax
  DNA::PropertyData::SetValueAction *v9; // rax
  DNA::PropertyData::SetValueAction *v10; // rbx
  __int64 v11; // rax
  char buffer[256]; // [rsp+40h] [rbp-118h] BYREF

  if ( this->mPropertyType == 1208522079 )
  {
    Value = DNA::PropertyData::GetValue(this, index);
    v7 = DNA::PropertyData::OverrideValue(this, Value);
    if ( v7 )
    {
      v8 = UFG::qMalloc(0x80ui64, "SetValueAction", 0i64);
      if ( v8 )
      {
        DNA::PropertyData::SetValueAction::SetValueAction((DNA::PropertyData::SetValueAction *)v8, v7);
        v10 = v9;
      }
      else
      {
        v10 = 0i64;
      }
      UFG::qToStringHex(buffer, 0x100ui64, LODWORD(v), 4ui64, 1);
      UFG::qString::Set(&v10->mNewValue, buffer);
      DNA::PropertyData::SetValueAction::Validate(v10);
      DNA::Database::Instance();
      DNA::ActionManager::AppendAction((DNA::ActionManager *)(v11 + 312), v10, undoId);
    }
  }
}

// File Line: 1146
// RVA: 0x1A6910
void __fastcall DNA::PropertyData::Set(
        DNA::PropertyData *this,
        unsigned int index,
        DNA::PropertyBag *v,
        unsigned int undoId)
{
  DNA::PropertyData::Value *Value; // rax
  DNA::PropertyData::Value *v8; // rbx
  UFG::allocator::free_link *v9; // rax
  DNA::PropertyData::SetValueAction *v10; // rax
  DNA::PropertyData::SetValueAction *v11; // rbx
  UFG::qString *v12; // rax
  __int64 v13; // rax
  UFG::qString result; // [rsp+38h] [rbp-30h] BYREF

  if ( this->mPropertyType == -915936389 )
  {
    Value = DNA::PropertyData::GetValue(this, index);
    v8 = DNA::PropertyData::OverrideValue(this, Value);
    if ( v8 )
    {
      v9 = UFG::qMalloc(0x80ui64, "SetValueAction", 0i64);
      if ( v9 )
      {
        DNA::PropertyData::SetValueAction::SetValueAction((DNA::PropertyData::SetValueAction *)v9, v8);
        v11 = v10;
      }
      else
      {
        v11 = 0i64;
      }
      v12 = UFG::qToHex(&result, v->mBaseNode.mUID);
      UFG::qString::Set(&v11->mNewValue, v12->mData, v12->mLength, 0i64, 0);
      UFG::qString::~qString(&result);
      DNA::PropertyData::SetValueAction::Validate(v11);
      DNA::Database::Instance();
      DNA::ActionManager::AppendAction((DNA::ActionManager *)(v13 + 312), v11, undoId);
    }
  }
}

// File Line: 1151
// RVA: 0x1A5EA0
DNA::PropertyData::Value *__fastcall DNA::PropertyData::GetValue(DNA::PropertyData *this, unsigned int index)
{
  UFG::qTree64Base *Parent; // rax
  UFG::qBaseTreeRB *Property; // rax
  DNA::PropertyData *v6; // rsi
  unsigned int v7; // eax
  DNA::PropertyData::Value *Value; // rax
  unsigned int size; // r8d
  DNA::PropertyData::Value *v10; // r10
  __int64 v11; // rax
  DNA::PropertyData::Value **i; // rdx
  DNA::PropertyData::Value *result; // rax
  __int64 v14; // rdi

  if ( this->mOverrideMode
    || (Parent = DNA::PropertyBag::GetParent(this->mOwner)) == 0i64
    || (Property = DNA::PropertyBag::GetProperty((DNA::PropertyBag *)Parent, this->mName.mData),
        (v6 = (DNA::PropertyData *)Property) == 0i64) )
  {
    v7 = 0;
LABEL_13:
    v14 = index - v7;
    if ( (unsigned int)v14 < this->mArrayEntries.size )
      return this->mArrayEntries.p[v14];
    else
      return 0i64;
  }
  v7 = DNA::PropertyData::NumItems((DNA::PropertyData *)Property);
  if ( index >= v7 )
    goto LABEL_13;
  Value = DNA::PropertyData::GetValue(v6, index);
  size = this->mOverrideArrayEntries.size;
  v10 = Value;
  v11 = 0i64;
  if ( !size )
    return v10;
  for ( i = this->mOverrideArrayEntries.p; (*i)->mID != v10->mID; ++i )
  {
    v11 = (unsigned int)(v11 + 1);
    if ( (unsigned int)v11 >= size )
      return v10;
  }
  result = this->mOverrideArrayEntries.p[v11];
  if ( !result )
    return v10;
  return result;
}

// File Line: 1223
// RVA: 0x1A61A0
DNA::PropertyData::Value *__fastcall DNA::PropertyData::OverrideValue(
        DNA::PropertyData *this,
        DNA::PropertyData::Value *entry)
{
  DNA::PropertyData::Value *v2; // rbx
  UFG::allocator::free_link *v4; // rax
  DNA::PropertyData::Value *v5; // rax
  DNA::PropertyData::Value *v6; // rsi
  __int64 size; // rbp
  unsigned int v8; // ebx
  unsigned int capacity; // edx
  unsigned int v10; // edx

  v2 = entry;
  if ( !entry )
    return this->mArrayEntries.p[(unsigned int)DNA::PropertyData::Add(this, 0)];
  if ( entry->mOwner == this )
    return v2;
  v4 = UFG::qMalloc(0x50ui64, UFG::gGlobalNewName, 0i64);
  if ( v4 )
  {
    DNA::PropertyData::Value::Value((DNA::PropertyData::Value *)v4, this, v2);
    v6 = v5;
  }
  else
  {
    v6 = 0i64;
  }
  size = this->mOverrideArrayEntries.size;
  v8 = size + 1;
  capacity = this->mOverrideArrayEntries.capacity;
  if ( (int)size + 1 > capacity )
  {
    if ( capacity )
      v10 = 2 * capacity;
    else
      v10 = 1;
    for ( ; v10 < v8; v10 *= 2 )
      ;
    if ( v10 <= 2 )
      v10 = 2;
    if ( v10 - v8 > 0x10000 )
      v10 = size + 65537;
    UFG::qArray<UFG::CompositeDrawableComponent *,32>::Reallocate(
      (UFG::qArray<UFG::qReflectInventoryBase *,0> *)&this->mOverrideArrayEntries,
      v10,
      "qArray.Add");
  }
  this->mOverrideArrayEntries.size = v8;
  this->mOverrideArrayEntries.p[size] = v6;
  return v6;
}

// File Line: 1265
// RVA: 0x1A5B80
__int64 __fastcall DNA::PropertyData::GetPropertyState(
        DNA::PropertyData *this,
        unsigned int index,
        DNA::SchemaField *schemaField)
{
  UFG::qTree64Base *Parent; // rax
  UFG::qBaseTreeRB *Property; // rax
  DNA::PropertyData *v8; // rsi
  DNA::PropertyData::Value *v9; // rax
  DNA::PropertyData::Value *v10; // rax
  BOOL v11; // ebx
  DNA::PropertyData::Value *Value; // rax
  char *DefaultValue; // rax
  UFG::qString v15; // [rsp+28h] [rbp-60h] BYREF
  UFG::qString v16; // [rsp+50h] [rbp-38h] BYREF

  if ( index >= DNA::PropertyData::NumItems(this) )
    return 0i64;
  if ( DNA::PropertyData::GetValue(this, index)->mOwner != this )
    return 1i64;
  if ( this->mOverrideMode
    || (Parent = DNA::PropertyBag::GetParent(this->mOwner)) == 0i64
    || (Property = DNA::PropertyBag::GetProperty((DNA::PropertyBag *)Parent, this->mName.mData),
        (v8 = (DNA::PropertyData *)Property) == 0i64)
    || index >= DNA::PropertyData::NumItems((DNA::PropertyData *)Property) )
  {
    if ( schemaField )
    {
      UFG::qString::qString(&v15);
      Value = DNA::PropertyData::GetValue(this, index);
      if ( Value )
        UFG::qString::Set(&v15, Value->mData.mData);
      DefaultValue = (char *)DNA::SchemaField::GetDefaultValue(schemaField);
      if ( DNA::DataConverter::Equals(schemaField->mType, DefaultValue, v15.mData) )
      {
        UFG::qString::~qString(&v15);
        return 0i64;
      }
      UFG::qString::~qString(&v15);
    }
    return 2i64;
  }
  UFG::qString::qString(&v16);
  v9 = DNA::PropertyData::GetValue(this, index);
  if ( v9 )
    UFG::qString::Set(&v16, v9->mData.mData);
  UFG::qString::qString(&v15);
  v10 = DNA::PropertyData::GetValue(v8, index);
  if ( v10 )
    UFG::qString::Set(&v15, v10->mData.mData);
  v11 = UFG::qStringCompare(v16.mData, v15.mData, -1) != 0;
  UFG::qString::~qString(&v15);
  UFG::qString::~qString(&v16);
  return (unsigned int)(v11 + 1);
}

// File Line: 1313
// RVA: 0x1A73E0
void __fastcall DNA::PropertyData::SetValueAction::SetValue(
        DNA::PropertyData::SetValueAction *this,
        DNA::PropertyData::Value *value,
        const char *data)
{
  __int64 i; // rbx
  DNA::PropertyData::Value *v6; // rsi

  for ( i = 0i64; (unsigned int)i < value->mInheritedValues.size; i = (unsigned int)(i + 1) )
  {
    v6 = value->mInheritedValues.p[i];
    if ( !(unsigned int)UFG::qStringCompare(v6->mData.mData, value->mData.mData, -1) )
      DNA::PropertyData::SetValueAction::SetValue(this, v6, data);
  }
  UFG::qString::Set(&value->mData, data);
}

// File Line: 1327
// RVA: 0x1A7D90
void __fastcall DNA::PropertyData::SetValueAction::Validate(DNA::PropertyData::SetValueAction *this)
{
  DNA::SchemaField *SchemaField; // rax
  const char *DefaultValue; // rax
  bool v4; // al
  DNA::PropertyData::Value *mValue; // rsi
  __int64 v6; // rbx
  char *i; // r14
  DNA::PropertyData::Value *v8; // rbp

  if ( !this->mOldValue.mLength )
  {
    SchemaField = DNA::PropertyData::GetSchemaField(this->mValue->mOwner);
    if ( SchemaField )
    {
      DefaultValue = DNA::SchemaField::GetDefaultValue(SchemaField);
      if ( DefaultValue )
        UFG::qString::Set(&this->mOldValue, DefaultValue);
    }
  }
  v4 = !DNA::DataConverter::Equals(this->mValue->mOwner->mPropertyType, this->mNewValue.mData, this->mOldValue.mData);
  this->mIsValid = v4;
  if ( !v4 && (unsigned int)UFG::qStringCompare(this->mNewValue.mData, this->mValue->mData.mData, -1) )
  {
    mValue = this->mValue;
    v6 = 0i64;
    for ( i = this->mNewValue.mData; (unsigned int)v6 < mValue->mInheritedValues.size; v6 = (unsigned int)(v6 + 1) )
    {
      v8 = mValue->mInheritedValues.p[v6];
      if ( !(unsigned int)UFG::qStringCompare(v8->mData.mData, mValue->mData.mData, -1) )
        DNA::PropertyData::SetValueAction::SetValue(this, v8, i);
    }
    UFG::qString::Set(&mValue->mData, i);
  }
}

// File Line: 1350
// RVA: 0x1A4E30
void __fastcall DNA::PropertyData::SetValueAction::DoInternal(DNA::PropertyData::SetValueAction *this)
{
  DNA::PropertyData::Value *mValue; // rdi
  char *mData; // r14
  __int64 i; // rbx
  DNA::PropertyData::Value *v5; // rbp
  AMD_HD3D *v6; // rax

  mValue = this->mValue;
  mData = this->mNewValue.mData;
  for ( i = 0i64; (unsigned int)i < mValue->mInheritedValues.size; i = (unsigned int)(i + 1) )
  {
    v5 = mValue->mInheritedValues.p[i];
    if ( !(unsigned int)UFG::qStringCompare(v5->mData.mData, mValue->mData.mData, -1) )
      DNA::PropertyData::SetValueAction::SetValue(this, v5, mData);
  }
  UFG::qString::Set(&mValue->mData, mData);
  DNA::PropertyBag::MarkDirty(this->mValue->mOwner->mOwner);
  DNA::Database::Instance();
  _(v6);
}

// File Line: 1359
// RVA: 0x1A76A0
void __fastcall DNA::PropertyData::SetValueAction::UndoInternal(DNA::PropertyData::SetValueAction *this)
{
  DNA::PropertyData::Value *mValue; // rdi
  char *mData; // r14
  __int64 i; // rbx
  DNA::PropertyData::Value *v5; // rbp
  AMD_HD3D *v6; // rax

  mValue = this->mValue;
  mData = this->mOldValue.mData;
  for ( i = 0i64; (unsigned int)i < mValue->mInheritedValues.size; i = (unsigned int)(i + 1) )
  {
    v5 = mValue->mInheritedValues.p[i];
    if ( !(unsigned int)UFG::qStringCompare(v5->mData.mData, mValue->mData.mData, -1) )
      DNA::PropertyData::SetValueAction::SetValue(this, v5, mData);
  }
  UFG::qString::Set(&mValue->mData, mData);
  DNA::PropertyBag::MarkDirty(this->mValue->mOwner->mOwner);
  DNA::Database::Instance();
  _(v6);
}

// File Line: 1368
// RVA: 0x1A6290
void __fastcall DNA::PropertyData::SetValueAction::Print(DNA::PropertyData::SetValueAction *this)
{
  UFG::qString *Name; // rax
  UFG::qString result; // [rsp+28h] [rbp-30h] BYREF

  Name = DNA::PropertyData::GetName(this->mValue->mOwner, &result);
  UFG::qPrintf("SetValueAction: %s New:%s Old:%s", Name->mData, this->mNewValue.mData, this->mOldValue.mData);
  UFG::qString::~qString(&result);
}

// File Line: 1373
// RVA: 0x1A7600
char __fastcall DNA::PropertyData::SetValueAction::TryToMerge(
        DNA::PropertyData::SetValueAction *this,
        DNA::IAction *action)
{
  if ( action->mTypeId != 724266166 || action[3].vfptr != (DNA::IActionVtbl *)this->mValue )
    return 0;
  UFG::qString::Set(&this->mNewValue, *(const char **)&action[2].mIsValid);
  this->vfptr->DoInternal(this);
  return 1;
}

// File Line: 1389
// RVA: 0x1A4DD0
void __fastcall DNA::PropertyData::AddValueAction::DoInternal(DNA::PropertyData::AddValueAction *this)
{
  DNA::PropertyData::Value **p_mValue; // rbx
  DNA::PropertyData *mOwner; // rdi
  DNA::Database *v3; // rax

  p_mValue = &this->mValue;
  mOwner = this->mValue->mOwner;
  UFG::qArray<UFG::PedSpawningInfo *,0>::Add(
    (UFG::qArray<UFG::qPropertySet *,0> *)&mOwner->mArrayEntries,
    (UFG::qPropertySet *const *)&this->mValue,
    "qArray.Add");
  DNA::PropertyBag::MarkDirty((*p_mValue)->mOwner->mOwner);
  DNA::Database::Instance();
  DNA::Database::OnStructureChanged(v3, mOwner);
}

// File Line: 1399
// RVA: 0x1A7650
void __fastcall DNA::PropertyData::AddValueAction::UndoInternal(DNA::PropertyData::AddValueAction *this)
{
  DNA::PropertyData::Value **p_mValue; // rbx
  DNA::PropertyData *mOwner; // rdi
  DNA::Database *v3; // rax

  p_mValue = &this->mValue;
  mOwner = this->mValue->mOwner;
  UFG::qArray<DNA::PropertyData::Value *,0>::StableDelete(&mOwner->mArrayEntries, &this->mValue);
  DNA::PropertyBag::MarkDirty((*p_mValue)->mOwner->mOwner);
  DNA::Database::Instance();
  DNA::Database::OnStructureChanged(v3, mOwner);
}

// File Line: 1450
// RVA: 0x1A4010
void __fastcall DNA::PropertyData::Value::Value(DNA::PropertyData::Value *this, DNA::PropertyData *owner)
{
  unsigned int v4; // ebx

  v4 = (unsigned int)UFG::qGetTicks() << 16;
  this->mID = v4 | (unsigned __int16)UFG::qGetTicks();
  UFG::qString::qString(&this->mData);
  this->mOwner = owner;
  this->mOverridenValue = 0i64;
  this->mInheritedValues.p = 0i64;
  *(_QWORD *)&this->mInheritedValues.size = 0i64;
}

// File Line: 1464
// RVA: 0x1A4080
void __fastcall DNA::PropertyData::Value::Value(
        DNA::PropertyData::Value *this,
        DNA::PropertyData *owner,
        DNA::PropertyData::Value *overrideValue)
{
  UFG::qArray<UFG::qReflectInventoryBase *,0> *mOverridenValue; // rdi
  __int64 size; // rbp
  unsigned int v8; // ebx
  unsigned int capacity; // edx
  unsigned int v10; // edx

  this->mID = overrideValue->mID;
  UFG::qString::qString(&this->mData);
  this->mOwner = owner;
  this->mOverridenValue = overrideValue;
  this->mInheritedValues.p = 0i64;
  *(_QWORD *)&this->mInheritedValues.size = 0i64;
  mOverridenValue = (UFG::qArray<UFG::qReflectInventoryBase *,0> *)this->mOverridenValue;
  size = mOverridenValue[4].size;
  v8 = size + 1;
  capacity = mOverridenValue[4].capacity;
  if ( (int)size + 1 > capacity )
  {
    if ( capacity )
      v10 = 2 * capacity;
    else
      v10 = 1;
    for ( ; v10 < v8; v10 *= 2 )
      ;
    if ( v10 <= 2 )
      v10 = 2;
    if ( v10 - v8 > 0x10000 )
      v10 = size + 65537;
    UFG::qArray<UFG::CompositeDrawableComponent *,32>::Reallocate(mOverridenValue + 4, v10, "qArray.Add");
  }
  mOverridenValue[4].size = v8;
  mOverridenValue[4].p[size] = (UFG::qReflectInventoryBase *)this;
  UFG::qString::Set(&this->mData, this->mOverridenValue->mData.mData, this->mOverridenValue->mData.mLength, 0i64, 0);
}

// File Line: 1470
// RVA: 0x1A44F0
void __fastcall DNA::PropertyData::Value::~Value(DNA::PropertyData::Value *this)
{
  DNA::PropertyData::Value *mOverridenValue; // rdx
  __int64 v3; // rcx
  unsigned int size; // r8d
  DNA::PropertyData::Value **p; // r9
  unsigned int v6; // eax
  unsigned int i; // edx
  unsigned __int64 v8; // rbx
  DNA::Database *v9; // rax
  UFG::qTree64Base *PropertyBag; // rax
  UFG::qTree64Base *v11; // rbx
  unsigned __int64 v12; // rsi
  DNA::PropertyData *Property; // rax
  DNA::PropertyData::Value *Value; // rax
  DNA::Database *v15; // rax
  DNA::PropertyData::Value **v16; // rcx

  mOverridenValue = this->mOverridenValue;
  if ( mOverridenValue )
  {
    v3 = 0i64;
    size = mOverridenValue->mInheritedValues.size;
    if ( size )
    {
      p = mOverridenValue->mInheritedValues.p;
      while ( this != p[v3] )
      {
        v3 = (unsigned int)(v3 + 1);
        if ( (unsigned int)v3 >= size )
          goto LABEL_11;
      }
      if ( (int)v3 >= 0 )
      {
        p[v3] = p[size - 1];
        v6 = mOverridenValue->mInheritedValues.size;
        if ( v6 > 1 )
          mOverridenValue->mInheritedValues.size = v6 - 1;
        else
          mOverridenValue->mInheritedValues.size = 0;
      }
    }
  }
LABEL_11:
  for ( i = 0; i < this->mInheritedValues.size; ++i )
    this->mInheritedValues.p[i]->mOverridenValue = 0i64;
  this->mInheritedValues.size = 0;
  if ( this->mOwner->mPropertyType == -915936389 )
  {
    v8 = UFG::qToUInt64(this->mData.mData, 0i64);
    DNA::Database::Instance();
    PropertyBag = DNA::Database::GetPropertyBag(v9, v8);
    v11 = PropertyBag;
    if ( PropertyBag )
    {
      v12 = 0i64;
      Property = DNA::PropertyBag::GetProperty((DNA::PropertyBag *)PropertyBag, "$OwnerId");
      if ( Property )
      {
        if ( Property->mPropertyType == 151281197 )
        {
          Value = DNA::PropertyData::GetValue(Property, 0);
          if ( Value )
            v12 = UFG::qToUInt64(Value->mData.mData, 0i64);
        }
      }
      if ( v12 == this->mOwner->mOwner->mBaseNode.mUID )
      {
        DNA::Database::Instance();
        DNA::Database::DeleteBag(v15, v11);
      }
    }
  }
  v16 = this->mInheritedValues.p;
  if ( v16 )
    operator delete[](v16);
  this->mInheritedValues.p = 0i64;
  *(_QWORD *)&this->mInheritedValues.size = 0i64;
  UFG::qString::~qString(&this->mData);
}

// File Line: 1498
// RVA: 0x1A7590
void __fastcall DNA::DataConverter::ToType(const char *s, UFG::qString *v)
{
  UFG::qString::Set(v, s);
}

// File Line: 1499
// RVA: 0x1A7500
void __fastcall DNA::DataConverter::ToType(const char *s, int *v)
{
  *v = UFG::qToInt32(s, 0);
}

// File Line: 1500
// RVA: 0x1A75A0
void __fastcall DNA::DataConverter::ToType(const char *s, __int64 *v)
{
  *v = UFG::qToInt64(s, 0i64);
}

// File Line: 1501
// RVA: 0x1A7520
void __fastcall DNA::DataConverter::ToType(const char *s, unsigned int *v)
{
  *v = UFG::qToUInt32(s, 0);
}

// File Line: 1502
// RVA: 0x1A75C0
void __fastcall DNA::DataConverter::ToType(const char *s, unsigned __int64 *v)
{
  *v = UFG::qToUInt64(s, 0i64);
}

// File Line: 1503
// RVA: 0x1A75E0
void __fastcall DNA::DataConverter::ToType(char *s, bool *v)
{
  *v = UFG::qToBool(s, 0);
}

// File Line: 1505
// RVA: 0x1A7540
void __fastcall DNA::DataConverter::ToType(const char *s, float *v)
{
  if ( *s == 48 && ((s[1] - 88) & 0xDF) == 0 || *s == 35 )
    *(_DWORD *)v = UFG::qToUInt32(s, 0);
  else
    *v = UFG::qToFloat(s, 0.0);
}

// File Line: 1508
// RVA: 0x1A74F0
// attributes: thunk
void __fastcall DNA::DataConverter::ToString(UFG::qString *s, const char *v)
{
  UFG::qString::Set(s, v);
}

// File Line: 1519
// RVA: 0x1A4EF0
_BOOL8 __fastcall DNA::DataConverter::Equals(int type, char *data1, char *data2)
{
  bool v5; // bl
  unsigned __int64 v6; // rbx
  int v7; // ebx
  int v8; // ebx
  float v9; // xmm6_4
  float v10; // xmm0_4
  bool v11; // bl
  UFG::qString text; // [rsp+28h] [rbp-70h] BYREF
  UFG::qString v14; // [rsp+50h] [rbp-48h] BYREF

  v5 = 0;
  if ( type <= 224407815 )
  {
    if ( type == 224407815 || type == -2133091136 )
    {
      v8 = UFG::qToInt32(data1, 0);
      return v8 == (unsigned int)UFG::qToInt32(data2, 0);
    }
    if ( type == -2067794966 )
    {
      v7 = UFG::qToUInt32(data1, 0);
      return v7 == (unsigned int)UFG::qToUInt32(data2, 0);
    }
    if ( type != -915936389 )
    {
      if ( type == 151281197 )
      {
        v6 = UFG::qToUInt64(data1, 0i64);
        return v6 == UFG::qToUInt64(data2, 0i64);
      }
      return v5;
    }
    return 0;
  }
  switch ( type )
  {
    case 826535573:
      UFG::qString::qString(&v14);
      UFG::qString::qString(&text);
      UFG::qString::Set(&v14, data1);
      UFG::qString::Set(&text, data2);
      v5 = UFG::qString::operator==(&v14, &text);
      UFG::qString::~qString(&text);
      UFG::qString::~qString(&v14);
      return v5;
    case 1138723642:
      v11 = UFG::qToBool(data1, 0);
      return v11 == UFG::qToBool(data2, 0);
    case 1208522079:
      if ( *data1 == 48 && ((data1[1] - 88) & 0xDF) == 0 || *data1 == 35 )
        LODWORD(v9) = UFG::qToUInt32(data1, 0);
      else
        v9 = UFG::qToFloat(data1, 0.0);
      if ( *data2 == 48 && ((data2[1] - 88) & 0xDF) == 0 || *data2 == 35 )
        LODWORD(v10) = UFG::qToUInt32(data2, 0);
      else
        v10 = UFG::qToFloat(data2, 0.0);
      return v9 == v10;
    case 1830847931:
      v5 = *data1 == *data2;
      break;
  }
  return v5;
}

