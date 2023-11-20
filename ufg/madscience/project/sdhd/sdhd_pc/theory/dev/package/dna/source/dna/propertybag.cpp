// File Line: 30
// RVA: 0x1A3E00
void __fastcall DNA::PropertyBagHandle::PropertyBagHandle(DNA::PropertyBagHandle *this, unsigned __int64 uid)
{
  DNA::PropertyBagHandle *v2; // rdi
  int v3; // ebx
  UFG::qArray<fastdelegate::FastDelegate1<DNA::PropertyBag *,void>,0> *v4; // rax
  UFG::qArray<fastdelegate::FastDelegate1<DNA::PropertyBag *,void>,0> *v5; // r14
  __int64 v6; // rsi
  fastdelegate::FastDelegate1<DNA::PropertyBag *,void> *v7; // rcx
  unsigned int v8; // ebx
  unsigned int v9; // edx
  unsigned int v10; // edx
  _QWORD *v11; // rax

  v2 = this;
  this->mPrev = (UFG::qNode<DNA::PropertyBagHandle,DNA::PropertyBagHandle> *)&this->mPrev;
  this->mNext = (UFG::qNode<DNA::PropertyBagHandle,DNA::PropertyBagHandle> *)&this->mPrev;
  this->mUID = uid;
  v3 = 0;
  this->mPropertyBag = 0i64;
  DNA::Database::Instance();
  v5 = v4 + 1;
  v6 = v4[1].size;
  if ( !(_DWORD)v6 )
    goto LABEL_8;
  v7 = v4[1].p;
  while ( v2 != (DNA::PropertyBagHandle *)v7[v3].m_Closure.m_pthis
       || DNA::PropertyBagHandle::OnPropertyBagDeleted != (void (__fastcall *)(DNA::PropertyBagHandle *, DNA::PropertyBag *))v7[v3].m_Closure.m_pFunction )
  {
    if ( ++v3 >= (unsigned int)v6 )
      goto LABEL_8;
  }
  if ( v3 == -1 )
  {
LABEL_8:
    v8 = v6 + 1;
    v9 = v4[1].capacity;
    if ( (signed int)v6 + 1 > v9 )
    {
      if ( v9 )
        v10 = 2 * v9;
      else
        v10 = 1;
      for ( ; v10 < v8; v10 *= 2 )
        ;
      if ( v10 - v8 > 0x10000 )
        v10 = v6 + 65537;
      UFG::qArray<fastdelegate::FastDelegate1<DNA::PropertyBag *,void>,0>::Reallocate(v5, v10, "qArray.Add");
    }
    v5->size = v8;
    v11 = &v5->p[v6].m_Closure.m_pthis;
    v11[1] = DNA::PropertyBagHandle::OnPropertyBagDeleted;
    *v11 = v2;
  }
}

// File Line: 37
// RVA: 0x1A3D10
void __fastcall DNA::PropertyBagHandle::PropertyBagHandle(DNA::PropertyBagHandle *this, DNA::PropertyBag *propertyBag)
{
  DNA::PropertyBagHandle *v2; // rdi
  UFG::qArray<fastdelegate::FastDelegate1<DNA::PropertyBag *,void>,0> *v3; // rax
  UFG::qArray<fastdelegate::FastDelegate1<DNA::PropertyBag *,void>,0> *v4; // r14
  int v5; // edx
  __int64 v6; // rsi
  fastdelegate::FastDelegate1<DNA::PropertyBag *,void> *v7; // rcx
  unsigned int v8; // ebx
  unsigned int v9; // edx
  unsigned int v10; // edx
  _QWORD *v11; // rax

  v2 = this;
  this->mPrev = (UFG::qNode<DNA::PropertyBagHandle,DNA::PropertyBagHandle> *)&this->mPrev;
  this->mNext = (UFG::qNode<DNA::PropertyBagHandle,DNA::PropertyBagHandle> *)&this->mPrev;
  this->mUID = propertyBag->mBaseNode.mUID;
  this->mPropertyBag = propertyBag;
  DNA::Database::Instance();
  v4 = v3 + 1;
  v5 = 0;
  v6 = v3[1].size;
  if ( !(_DWORD)v6 )
    goto LABEL_8;
  v7 = v3[1].p;
  while ( v2 != (DNA::PropertyBagHandle *)v7[v5].m_Closure.m_pthis
       || DNA::PropertyBagHandle::OnPropertyBagDeleted != (void (__fastcall *)(DNA::PropertyBagHandle *, DNA::PropertyBag *))v7[v5].m_Closure.m_pFunction )
  {
    if ( ++v5 >= (unsigned int)v6 )
      goto LABEL_8;
  }
  if ( v5 == -1 )
  {
LABEL_8:
    v8 = v6 + 1;
    v9 = v3[1].capacity;
    if ( (signed int)v6 + 1 > v9 )
    {
      if ( v9 )
        v10 = 2 * v9;
      else
        v10 = 1;
      for ( ; v10 < v8; v10 *= 2 )
        ;
      if ( v10 - v8 > 0x10000 )
        v10 = v6 + 65537;
      UFG::qArray<fastdelegate::FastDelegate1<DNA::PropertyBag *,void>,0>::Reallocate(v4, v10, "qArray.Add");
    }
    v4->size = v8;
    v11 = &v4->p[v6].m_Closure.m_pthis;
    v11[1] = DNA::PropertyBagHandle::OnPropertyBagDeleted;
    *v11 = v2;
  }
}

// File Line: 42
// RVA: 0x1A4310
void __fastcall DNA::PropertyBagHandle::~PropertyBagHandle(DNA::PropertyBagHandle *this)
{
  DNA::PropertyBagHandle *v1; // rbx
  __int64 v2; // rax
  __int64 v3; // r8
  unsigned int v4; // edx
  unsigned int v5; // eax
  __int64 v6; // r9
  int v7; // er9
  signed __int64 v8; // rdx
  _QWORD *v9; // rcx
  unsigned int v10; // eax
  UFG::qNode<DNA::PropertyBagHandle,DNA::PropertyBagHandle> *v11; // rcx
  UFG::qNode<DNA::PropertyBagHandle,DNA::PropertyBagHandle> *v12; // rax

  v1 = this;
  if ( (unsigned __int8)DNA::Database::IsInitialized() )
  {
    DNA::Database::Instance();
    v3 = v2;
    v4 = 0;
    v5 = *(_DWORD *)(v2 + 16);
    if ( v5 )
    {
      v6 = *(_QWORD *)(v3 + 24);
      while ( v1 != *(DNA::PropertyBagHandle **)(v6 + 16i64 * v4)
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
          v8 = 16i64 * v7;
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
  v11 = v1->mPrev;
  v12 = v1->mNext;
  v11->mNext = v12;
  v12->mPrev = v11;
  v1->mPrev = (UFG::qNode<DNA::PropertyBagHandle,DNA::PropertyBagHandle> *)&v1->mPrev;
  v1->mNext = (UFG::qNode<DNA::PropertyBagHandle,DNA::PropertyBagHandle> *)&v1->mPrev;
}

// File Line: 50
// RVA: 0x1A6190
void __fastcall DNA::PropertyBagHandle::OnPropertyBagDeleted(DNA::PropertyBagHandle *this, DNA::PropertyBag *propertyBag)
{
  if ( this->mPropertyBag == propertyBag )
    this->mPropertyBag = 0i64;
}

// File Line: 58
// RVA: 0x1A53A0
DNA::PropertyBag *__fastcall DNA::PropertyBagHandle::Get(DNA::PropertyBagHandle *this)
{
  DNA::PropertyBagHandle *v1; // rbx
  DNA::Database *v2; // rax
  DNA::PropertyBag *result; // rax

  v1 = this;
  if ( this->mPropertyBag )
    return this->mPropertyBag;
  DNA::Database::Instance();
  result = (DNA::PropertyBag *)DNA::Database::GetPropertyBag(v2, v1->mUID);
  v1->mPropertyBag = result;
  return result;
}

// File Line: 74
// RVA: 0x1A3C80
void __fastcall DNA::PropertyBag::PropertyBag(DNA::PropertyBag *this, unsigned __int64 uid)
{
  unsigned __int64 v2; // rdi
  DNA::PropertyBag *v3; // rbx
  DNA::PropertyData *v4; // rax

  v2 = uid;
  v3 = this;
  this->mBaseNode.mUID = 0i64;
  this->mBaseNode.mParent = &this->mBaseNode;
  this->mBaseNode.mChildren[0] = &this->mBaseNode;
  this->mBaseNode.mChildren[1] = &this->mBaseNode;
  this->mBaseNode.mNeighbours[0] = &this->mBaseNode;
  this->mBaseNode.mNeighbours[1] = &this->mBaseNode;
  UFG::qBaseTreeRB::qBaseTreeRB(&this->mProperties.mTree);
  *(_WORD *)&v3->mIsDirty = 1;
  v3->mBaseNode.mUID = v2;
  v4 = DNA::PropertyBag::CreateProperty(v3, "$Id", (DNA::PropertyType::Enum)151281197);
  if ( v4 )
    DNA::PropertyData::Set(v4, 0, v2, 0);
}

// File Line: 124
// RVA: 0x1A42A0
void __fastcall DNA::PropertyBag::~PropertyBag(DNA::PropertyBag *this)
{
  UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *v1; // rdi
  Render::SkinningCacheNode *v2; // rbx

  v1 = (UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&this->mProperties;
  if ( this->mProperties.mTree.mCount )
  {
    do
    {
      v2 = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead(v1);
      UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(&v1->mTree, &v2->mNode);
      if ( v2 )
      {
        DNA::PropertyData::~PropertyData((DNA::PropertyData *)v2);
        operator delete[](v2);
      }
    }
    while ( v1->mTree.mCount );
  }
  UFG::qTreeRB<DNA::PropertyData,DNA::PropertyData,1>::~qTreeRB<DNA::PropertyData,DNA::PropertyData,1>((UFG::qTreeRB<DNA::PropertyData,DNA::PropertyData,1> *)v1);
}

// File Line: 301
// RVA: 0x1A5E50
UFG::qTree64Base *__fastcall DNA::PropertyBag::GetSchemaType(DNA::PropertyBag *this)
{
  char *v1; // rbx
  DNA::Database *v2; // rax
  UFG::qTree64Base *v3; // rbx
  UFG::qString result; // [rsp+28h] [rbp-30h]

  v1 = DNA::PropertyBag::GetSchemaName(this, &result)->mData;
  DNA::Database::Instance();
  v3 = DNA::Database::GetSchema(v2, v1);
  UFG::qString::~qString(&result);
  return v3;
}

// File Line: 306
// RVA: 0x1A5B50
DNA::PropertyState::Enum __fastcall DNA::PropertyBag::GetPropertyState(DNA::PropertyBag *this, const char *propertyName, unsigned int index)
{
  unsigned int v3; // ebx
  DNA::PropertyBag *v4; // rdi
  UFG::qBaseTreeRB *v5; // rax

  v3 = index;
  v4 = this;
  v5 = DNA::PropertyBag::GetProperty(this, propertyName);
  return DNA::PropertyBag::GetPropertyState(v4, (DNA::PropertyData *)v5, v3);
}

// File Line: 312
// RVA: 0x1A5AB0
DNA::PropertyState::Enum __fastcall DNA::PropertyBag::GetPropertyState(DNA::PropertyBag *this, DNA::PropertyData *propertyData, unsigned int index)
{
  int v3; // esi
  DNA::PropertyData *v4; // rdi
  char *v6; // rbx
  DNA::Database *v7; // rax
  UFG::qTree64Base *v8; // rbx
  DNA::SchemaField *v9; // rax
  unsigned __int64 v10; // rax
  UFG::qString result; // [rsp+28h] [rbp-30h]

  v3 = index;
  v4 = propertyData;
  if ( !propertyData )
    return 0;
  v6 = DNA::PropertyBag::GetSchemaName(this, &result)->mData;
  DNA::Database::Instance();
  v8 = DNA::Database::GetSchema(v7, v6);
  UFG::qString::~qString(&result);
  if ( v8 )
  {
    v10 = UFG::qStringHash64(v4->mName.mData, 0xFFFFFFFFFFFFFFFFui64);
    v9 = DNA::SchemaType::GetField((DNA::SchemaType *)v8, v10);
  }
  else
  {
    v9 = 0i64;
  }
  return DNA::PropertyData::GetPropertyState(v4, v3, v9);
}

// File Line: 325
// RVA: 0x1A5850
void __fastcall DNA::PropertyBag::GetPropertyInfo(DNA::PropertyBag *this, const char *propertyName, DNA::PropertyInfo *info)
{
  unsigned int v3; // esi
  DNA::PropertyInfo *v4; // r13
  const char *v5; // rbp
  DNA::PropertyBag *v6; // rbx
  UFG::qBaseTreeRB *v7; // rax
  UFG::qBaseTreeRB *v8; // r14
  unsigned int v9; // eax
  __int64 v10; // rbp
  unsigned int v11; // edx
  unsigned int v12; // ebx
  unsigned int v13; // edx
  DNA::PropertyState::Enum *v14; // rax
  __int64 v15; // rbp
  unsigned int v16; // edx
  unsigned int v17; // ebx
  unsigned int v18; // edx
  DNA::PropertyState::Enum *v19; // rax
  DNA::SchemaType *v20; // rbx
  DNA::SchemaField *v21; // r12
  unsigned __int64 v22; // rax
  DNA::PropertyState::Enum v23; // eax
  __int64 v24; // rbp
  unsigned int v25; // edx
  unsigned int v26; // ebx
  DNA::PropertyState::Enum v27; // er15
  unsigned int v28; // edx
  DNA::PropertyState::Enum *v29; // rax

  v3 = 0;
  v4 = info;
  v5 = propertyName;
  *(_QWORD *)&info->Type = 0i64;
  info->States.size = 0;
  v6 = this;
  v7 = DNA::PropertyBag::GetProperty(this, propertyName);
  v8 = v7;
  if ( v7 )
  {
    v4->Type = (DNA::PropertyType::Enum)v7[1].mRoot.mParent;
    v9 = DNA::PropertyData::NumItems((DNA::PropertyData *)v7);
    v4->Size = v9;
    if ( *v5 == 36 )
    {
      if ( v9 )
      {
        do
        {
          v10 = v4->States.size;
          v11 = v4->States.capacity;
          v12 = v10 + 1;
          if ( (signed int)v10 + 1 > v11 )
          {
            if ( v11 )
              v13 = 2 * v11;
            else
              v13 = 1;
            for ( ; v13 < v12; v13 *= 2 )
              ;
            if ( v13 <= 4 )
              v13 = 4;
            if ( v13 - v12 > 0x10000 )
              v13 = v10 + 65537;
            UFG::qArray<long,0>::Reallocate((UFG::qArray<unsigned long,0> *)&v4->States, v13, "qArray.Add");
          }
          v14 = v4->States.p;
          v4->States.size = v12;
          ++v3;
          v14[v10] = 2;
        }
        while ( v3 < v4->Size );
      }
    }
    else if ( v8[1].mRoot.mChild[0]->mParent == (UFG::qBaseNodeRB *)v6->mBaseNode.mUID )
    {
      v20 = DNA::PropertyBag::GetSchemaType(v6);
      if ( v20 )
      {
        v22 = UFG::qStringHash64(v5, 0xFFFFFFFFFFFFFFFFui64);
        v21 = DNA::SchemaType::GetField(v20, v22);
      }
      else
      {
        v21 = 0i64;
      }
      if ( v4->Size > 0 )
      {
        do
        {
          v23 = DNA::PropertyData::GetPropertyState((DNA::PropertyData *)v8, v3, v21);
          v24 = v4->States.size;
          v25 = v4->States.capacity;
          v26 = v24 + 1;
          v27 = v23;
          if ( (signed int)v24 + 1 > v25 )
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
            UFG::qArray<long,0>::Reallocate((UFG::qArray<unsigned long,0> *)&v4->States, v28, "qArray.Add");
          }
          v29 = v4->States.p;
          v4->States.size = v26;
          ++v3;
          v29[v24] = v27;
        }
        while ( v3 < v4->Size );
      }
    }
    else if ( v9 )
    {
      do
      {
        v15 = v4->States.size;
        v16 = v4->States.capacity;
        v17 = v15 + 1;
        if ( (signed int)v15 + 1 > v16 )
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
          UFG::qArray<long,0>::Reallocate((UFG::qArray<unsigned long,0> *)&v4->States, v18, "qArray.Add");
        }
        v19 = v4->States.p;
        v4->States.size = v17;
        ++v3;
        v19[v15] = 1;
      }
      while ( v3 < v4->Size );
    }
  }
} v19 = v4->States.p;
        v4->States.size = v17;
        ++v3;
        v19[v15] = 1;
      }
      while ( v3 < v4->Size );
    }
  

// File Line: 372
// RVA: 0x1A51F0
void __fastcall DNA::PropertyBag::Get(DNA::PropertyBag *this, const char *propertyName, UFG::qString *v, unsigned int index)
{
  unsigned int v4; // edi
  UFG::qString *v5; // rbx
  DNA::PropertyData *v6; // rax
  DNA::PropertyData::Value *v7; // rax

  v4 = index;
  v5 = v;
  v6 = DNA::PropertyBag::GetProperty(this, propertyName);
  if ( v6 && v6->mPropertyType == 826535573 )
  {
    v7 = DNA::PropertyData::GetValue(v6, v4);
    if ( v7 )
      UFG::qString::Set(v5, v7->mData.mData);
  }
}

// File Line: 373
// RVA: 0x1A5110
void __fastcall DNA::PropertyBag::Get(DNA::PropertyBag *this, const char *propertyName, int *v, unsigned int index)
{
  unsigned int v4; // ebx
  int *v5; // rdi
  DNA::PropertyData *v6; // rax
  DNA::PropertyData::Value *v7; // rax

  v4 = index;
  v5 = v;
  v6 = DNA::PropertyBag::GetProperty(this, propertyName);
  if ( v6 && v6->mPropertyType == -2133091136 )
  {
    v7 = DNA::PropertyData::GetValue(v6, v4);
    if ( v7 )
      *v5 = UFG::qToInt32(v7->mData.mData, 0);
  }
}

// File Line: 374
// RVA: 0x1A5240
void __fastcall DNA::PropertyBag::Get(DNA::PropertyBag *this, const char *propertyName, __int64 *v, unsigned int index)
{
  unsigned int v4; // ebx
  __int64 *v5; // rdi
  DNA::PropertyData *v6; // rax
  DNA::PropertyData::Value *v7; // rax

  v4 = index;
  v5 = v;
  v6 = DNA::PropertyBag::GetProperty(this, propertyName);
  if ( v6 && v6->mPropertyType == 224407815 )
  {
    v7 = DNA::PropertyData::GetValue(v6, v4);
    if ( v7 )
      *v5 = UFG::qToInt64(v7->mData.mData, 0i64);
  }
}

// File Line: 375
// RVA: 0x1A5160
void __fastcall DNA::PropertyBag::Get(DNA::PropertyBag *this, const char *propertyName, unsigned int *v, unsigned int index)
{
  unsigned int v4; // ebx
  unsigned int *v5; // rdi
  DNA::PropertyData *v6; // rax
  DNA::PropertyData::Value *v7; // rax

  v4 = index;
  v5 = v;
  v6 = DNA::PropertyBag::GetProperty(this, propertyName);
  if ( v6 && v6->mPropertyType == -2067794966 )
  {
    v7 = DNA::PropertyData::GetValue(v6, v4);
    if ( v7 )
      *v5 = UFG::qToUInt32(v7->mData.mData, 0);
  }
}

// File Line: 376
// RVA: 0x1A5290
void __fastcall DNA::PropertyBag::Get(DNA::PropertyBag *this, const char *propertyName, unsigned __int64 *v, unsigned int index)
{
  unsigned int v4; // ebx
  unsigned __int64 *v5; // rdi
  DNA::PropertyData *v6; // rax
  DNA::PropertyData::Value *v7; // rax

  v4 = index;
  v5 = v;
  v6 = DNA::PropertyBag::GetProperty(this, propertyName);
  if ( v6 && v6->mPropertyType == 151281197 )
  {
    v7 = DNA::PropertyData::GetValue(v6, v4);
    if ( v7 )
      *v5 = UFG::qToUInt64(v7->mData.mData, 0i64);
  }
}

// File Line: 377
// RVA: 0x1A52E0
void __fastcall DNA::PropertyBag::Get(DNA::PropertyBag *this, const char *propertyName, bool *v, unsigned int index)
{
  unsigned int v4; // ebx
  bool *v5; // rdi
  DNA::PropertyData *v6; // rax
  DNA::PropertyData::Value *v7; // rax

  v4 = index;
  v5 = v;
  v6 = DNA::PropertyBag::GetProperty(this, propertyName);
  if ( v6 && v6->mPropertyType == 1138723642 )
  {
    v7 = DNA::PropertyData::GetValue(v6, v4);
    if ( v7 )
      *v5 = UFG::qToBool(v7->mData.mData, 0);
  }
}

// File Line: 379
// RVA: 0x1A51B0
void __fastcall DNA::PropertyBag::Get(DNA::PropertyBag *this, const char *propertyName, float *v, unsigned int index)
{
  unsigned int v4; // ebx
  float *v5; // rdi
  DNA::PropertyData *v6; // rax

  v4 = index;
  v5 = v;
  v6 = DNA::PropertyBag::GetProperty(this, propertyName);
  if ( v6 )
    DNA::PropertyData::Get(v6, v4, v5);
}

// File Line: 380
// RVA: 0x1A5330
void __fastcall DNA::PropertyBag::Get(DNA::PropertyBag *this, const char *propertyName, DNA::PropertyBag **v, unsigned int index)
{
  unsigned int v4; // ebx
  DNA::PropertyBag **v5; // rdi
  DNA::PropertyData *v6; // rax
  DNA::PropertyData::Value *v7; // rax
  unsigned __int64 v8; // rbx
  DNA::Database *v9; // rax

  v4 = index;
  v5 = v;
  *v = 0i64;
  v6 = DNA::PropertyBag::GetProperty(this, propertyName);
  if ( v6 && v6->mPropertyType == -915936389 )
  {
    v7 = DNA::PropertyData::GetValue(v6, v4);
    if ( v7 )
    {
      v8 = UFG::qToUInt64(v7->mData.mData, 0i64);
      DNA::Database::Instance();
      *v5 = (DNA::PropertyBag *)DNA::Database::GetPropertyBag(v9, v8);
    }
  }
}

// File Line: 382
// RVA: 0x1A63B0
void __fastcall DNA::PropertyBag::Set(DNA::PropertyBag *this, const char *propertyName, const char *v, unsigned int index, unsigned int undoId)
{
  unsigned int v5; // ebx
  const char *v6; // rdi
  UFG::qBaseTreeRB *v7; // rax

  v5 = index;
  v6 = v;
  if ( *propertyName != 36 )
  {
    v7 = DNA::PropertyBag::CreateProperty(this, propertyName, (DNA::PropertyType::Enum)826535573);
    if ( v7 )
      DNA::PropertyData::Set((DNA::PropertyData *)v7, v5, v6, undoId);
  }
}

// File Line: 383
// RVA: 0x1A6400
void __fastcall DNA::PropertyBag::Set(DNA::PropertyBag *this, const char *propertyName, int v, unsigned int index, unsigned int undoId)
{
  unsigned int v5; // ebx
  int v6; // edi
  UFG::qBaseTreeRB *v7; // rax

  v5 = index;
  v6 = v;
  if ( *propertyName != 36 )
  {
    v7 = DNA::PropertyBag::CreateProperty(this, propertyName, (DNA::PropertyType::Enum)-2133091136);
    if ( v7 )
      DNA::PropertyData::Set((DNA::PropertyData *)v7, v5, v6, undoId);
  }
}

// File Line: 384
// RVA: 0x1A6540
void __fastcall DNA::PropertyBag::Set(DNA::PropertyBag *this, const char *propertyName, __int64 v, unsigned int index, unsigned int undoId)
{
  unsigned int v5; // ebx
  __int64 v6; // rdi
  UFG::qBaseTreeRB *v7; // rax

  v5 = index;
  v6 = v;
  if ( *propertyName != 36 )
  {
    v7 = DNA::PropertyBag::CreateProperty(this, propertyName, (DNA::PropertyType::Enum)224407815);
    if ( v7 )
      DNA::PropertyData::Set((DNA::PropertyData *)v7, v5, v6, undoId);
  }
}

// File Line: 385
// RVA: 0x1A6450
void __fastcall DNA::PropertyBag::Set(DNA::PropertyBag *this, const char *propertyName, unsigned int v, unsigned int index, unsigned int undoId)
{
  unsigned int v5; // ebx
  unsigned int v6; // edi
  UFG::qBaseTreeRB *v7; // rax

  v5 = index;
  v6 = v;
  if ( *propertyName != 36 )
  {
    v7 = DNA::PropertyBag::CreateProperty(this, propertyName, (DNA::PropertyType::Enum)-2067794966);
    if ( v7 )
      DNA::PropertyData::Set((DNA::PropertyData *)v7, v5, v6, undoId);
  }
}

// File Line: 386
// RVA: 0x1A6590
void __fastcall DNA::PropertyBag::Set(DNA::PropertyBag *this, const char *propertyName, unsigned __int64 v, unsigned int index, unsigned int undoId)
{
  unsigned int v5; // ebx
  unsigned __int64 v6; // rdi
  UFG::qBaseTreeRB *v7; // rax

  v5 = index;
  v6 = v;
  if ( *propertyName != 36 )
  {
    v7 = DNA::PropertyBag::CreateProperty(this, propertyName, (DNA::PropertyType::Enum)151281197);
    if ( v7 )
      DNA::PropertyData::Set((DNA::PropertyData *)v7, v5, v6, undoId);
  }
}

// File Line: 387
// RVA: 0x1A65E0
void __fastcall DNA::PropertyBag::Set(DNA::PropertyBag *this, const char *propertyName, bool v, unsigned int index, unsigned int undoId)
{
  unsigned int v5; // ebx
  bool v6; // di
  UFG::qBaseTreeRB *v7; // rax

  v5 = index;
  v6 = v;
  if ( *propertyName != 36 )
  {
    v7 = DNA::PropertyBag::CreateProperty(this, propertyName, (DNA::PropertyType::Enum)1138723642);
    if ( v7 )
      DNA::PropertyData::Set((DNA::PropertyData *)v7, v5, v6, undoId);
  }
}

// File Line: 389
// RVA: 0x1A64A0
void __fastcall DNA::PropertyBag::Set(DNA::PropertyBag *this, const char *propertyName, float v, unsigned int index, unsigned int undoId)
{
  unsigned int v5; // ebx
  UFG::qBaseTreeRB *v6; // rax

  v5 = index;
  if ( *propertyName != 36 )
  {
    v6 = DNA::PropertyBag::CreateProperty(this, propertyName, (DNA::PropertyType::Enum)1208522079);
    if ( v6 )
      DNA::PropertyData::Set((DNA::PropertyData *)v6, v5, v, undoId);
  }
}

// File Line: 390
// RVA: 0x1A64F0
void __fastcall DNA::PropertyBag::Set(DNA::PropertyBag *this, const char *propertyName, DNA::PropertyBag *v, unsigned int index, unsigned int undoId)
{
  unsigned int v5; // ebx
  DNA::PropertyBag *v6; // rdi
  UFG::qBaseTreeRB *v7; // rax

  v5 = index;
  v6 = v;
  if ( *propertyName != 36 )
  {
    v7 = DNA::PropertyBag::CreateProperty(this, propertyName, (DNA::PropertyType::Enum)-915936389);
    if ( v7 )
      DNA::PropertyData::Set((DNA::PropertyData *)v7, v5, v6, undoId);
  }
}

// File Line: 392
// RVA: 0x1A4820
void __fastcall DNA::PropertyBag::Append(DNA::PropertyBag *this, const char *propertyName, const char *v, unsigned int undoId)
{
  unsigned int v4; // ebx
  const char *v5; // rbp
  const char *v6; // rdi
  DNA::PropertyBag *v7; // rsi
  __int64 v8; // rax
  DNA::PropertyData *v9; // rax
  DNA::PropertyData *v10; // rdi
  unsigned int v11; // eax
  __int64 v12; // rax

  v4 = undoId;
  v5 = v;
  v6 = propertyName;
  v7 = this;
  DNA::Database::Instance();
  DNA::ActionManager::BeginTransaction((DNA::ActionManager *)(v8 + 312), v4);
  if ( *v6 != 36 )
  {
    v9 = DNA::PropertyBag::CreateProperty(v7, v6, (DNA::PropertyType::Enum)826535573);
    v10 = v9;
    if ( v9 )
    {
      v11 = DNA::PropertyData::Add(v9, v4);
      DNA::PropertyData::Set(v10, v11, v5, v4);
    }
  }
  DNA::Database::Instance();
  DNA::ActionManager::EndTransaction((DNA::ActionManager *)(v12 + 312), v4);
}

// File Line: 393
// RVA: 0x1A48C0
void __fastcall DNA::PropertyBag::Append(DNA::PropertyBag *this, const char *propertyName, int v, unsigned int undoId)
{
  unsigned int v4; // ebx
  int v5; // ebp
  const char *v6; // rdi
  DNA::PropertyBag *v7; // rsi
  __int64 v8; // rax
  DNA::PropertyData *v9; // rax
  DNA::PropertyData *v10; // rdi
  unsigned int v11; // eax
  __int64 v12; // rax

  v4 = undoId;
  v5 = v;
  v6 = propertyName;
  v7 = this;
  DNA::Database::Instance();
  DNA::ActionManager::BeginTransaction((DNA::ActionManager *)(v8 + 312), v4);
  if ( *v6 != 36 )
  {
    v9 = DNA::PropertyBag::CreateProperty(v7, v6, (DNA::PropertyType::Enum)-2133091136);
    v10 = v9;
    if ( v9 )
    {
      v11 = DNA::PropertyData::Add(v9, v4);
      DNA::PropertyData::Set(v10, v11, v5, v4);
    }
  }
  DNA::Database::Instance();
  DNA::ActionManager::EndTransaction((DNA::ActionManager *)(v12 + 312), v4);
}

// File Line: 394
// RVA: 0x1A4B40
void __fastcall DNA::PropertyBag::Append(DNA::PropertyBag *this, const char *propertyName, __int64 v, unsigned int undoId)
{
  unsigned int v4; // ebx
  __int64 v5; // rbp
  const char *v6; // rdi
  DNA::PropertyBag *v7; // rsi
  __int64 v8; // rax
  DNA::PropertyData *v9; // rax
  DNA::PropertyData *v10; // rdi
  unsigned int v11; // eax
  __int64 v12; // rax

  v4 = undoId;
  v5 = v;
  v6 = propertyName;
  v7 = this;
  DNA::Database::Instance();
  DNA::ActionManager::BeginTransaction((DNA::ActionManager *)(v8 + 312), v4);
  if ( *v6 != 36 )
  {
    v9 = DNA::PropertyBag::CreateProperty(v7, v6, (DNA::PropertyType::Enum)224407815);
    v10 = v9;
    if ( v9 )
    {
      v11 = DNA::PropertyData::Add(v9, v4);
      DNA::PropertyData::Set(v10, v11, v5, v4);
    }
  }
  DNA::Database::Instance();
  DNA::ActionManager::EndTransaction((DNA::ActionManager *)(v12 + 312), v4);
}

// File Line: 395
// RVA: 0x1A4960
void __fastcall DNA::PropertyBag::Append(DNA::PropertyBag *this, const char *propertyName, unsigned int v, unsigned int undoId)
{
  unsigned int v4; // ebx
  unsigned int v5; // ebp
  const char *v6; // rdi
  DNA::PropertyBag *v7; // rsi
  __int64 v8; // rax
  DNA::PropertyData *v9; // rax
  DNA::PropertyData *v10; // rdi
  unsigned int v11; // eax
  __int64 v12; // rax

  v4 = undoId;
  v5 = v;
  v6 = propertyName;
  v7 = this;
  DNA::Database::Instance();
  DNA::ActionManager::BeginTransaction((DNA::ActionManager *)(v8 + 312), v4);
  if ( *v6 != 36 )
  {
    v9 = DNA::PropertyBag::CreateProperty(v7, v6, (DNA::PropertyType::Enum)-2067794966);
    v10 = v9;
    if ( v9 )
    {
      v11 = DNA::PropertyData::Add(v9, v4);
      DNA::PropertyData::Set(v10, v11, v5, v4);
    }
  }
  DNA::Database::Instance();
  DNA::ActionManager::EndTransaction((DNA::ActionManager *)(v12 + 312), v4);
}

// File Line: 396
// RVA: 0x1A4BE0
void __fastcall DNA::PropertyBag::Append(DNA::PropertyBag *this, const char *propertyName, unsigned __int64 v, unsigned int undoId)
{
  unsigned int v4; // ebx
  unsigned __int64 v5; // rbp
  const char *v6; // rdi
  DNA::PropertyBag *v7; // rsi
  __int64 v8; // rax
  DNA::PropertyData *v9; // rax
  DNA::PropertyData *v10; // rdi
  unsigned int v11; // eax
  __int64 v12; // rax

  v4 = undoId;
  v5 = v;
  v6 = propertyName;
  v7 = this;
  DNA::Database::Instance();
  DNA::ActionManager::BeginTransaction((DNA::ActionManager *)(v8 + 312), v4);
  if ( *v6 != 36 )
  {
    v9 = DNA::PropertyBag::CreateProperty(v7, v6, (DNA::PropertyType::Enum)151281197);
    v10 = v9;
    if ( v9 )
    {
      v11 = DNA::PropertyData::Add(v9, v4);
      DNA::PropertyData::Set(v10, v11, v5, v4);
    }
  }
  DNA::Database::Instance();
  DNA::ActionManager::EndTransaction((DNA::ActionManager *)(v12 + 312), v4);
}

// File Line: 397
// RVA: 0x1A4C80
void __fastcall DNA::PropertyBag::Append(DNA::PropertyBag *this, const char *propertyName, bool v, unsigned int undoId)
{
  unsigned int v4; // ebx
  bool v5; // bp
  const char *v6; // rdi
  DNA::PropertyBag *v7; // rsi
  __int64 v8; // rax
  DNA::PropertyData *v9; // rax
  DNA::PropertyData *v10; // rdi
  unsigned int v11; // eax
  __int64 v12; // rax

  v4 = undoId;
  v5 = v;
  v6 = propertyName;
  v7 = this;
  DNA::Database::Instance();
  DNA::ActionManager::BeginTransaction((DNA::ActionManager *)(v8 + 312), v4);
  if ( *v6 != 36 )
  {
    v9 = DNA::PropertyBag::CreateProperty(v7, v6, (DNA::PropertyType::Enum)1138723642);
    v10 = v9;
    if ( v9 )
    {
      v11 = DNA::PropertyData::Add(v9, v4);
      DNA::PropertyData::Set(v10, v11, v5, v4);
    }
  }
  DNA::Database::Instance();
  DNA::ActionManager::EndTransaction((DNA::ActionManager *)(v12 + 312), v4);
}

// File Line: 399
// RVA: 0x1A4A00
void __fastcall DNA::PropertyBag::Append(DNA::PropertyBag *this, const char *propertyName, float v, unsigned int undoId)
{
  unsigned int v4; // ebx
  const char *v5; // rdi
  DNA::PropertyBag *v6; // rsi
  __int64 v7; // rax
  DNA::PropertyData *v8; // rax
  DNA::PropertyData *v9; // rdi
  unsigned int v10; // eax
  __int64 v11; // rax

  v4 = undoId;
  v5 = propertyName;
  v6 = this;
  DNA::Database::Instance();
  DNA::ActionManager::BeginTransaction((DNA::ActionManager *)(v7 + 312), v4);
  if ( *v5 != 36 )
  {
    v8 = DNA::PropertyBag::CreateProperty(v6, v5, (DNA::PropertyType::Enum)1208522079);
    v9 = v8;
    if ( v8 )
    {
      v10 = DNA::PropertyData::Add(v8, v4);
      DNA::PropertyData::Set(v9, v10, v, v4);
    }
  }
  DNA::Database::Instance();
  DNA::ActionManager::EndTransaction((DNA::ActionManager *)(v11 + 312), v4);
}

// File Line: 400
// RVA: 0x1A4AA0
void __fastcall DNA::PropertyBag::Append(DNA::PropertyBag *this, const char *propertyName, DNA::PropertyBag *v, unsigned int undoId)
{
  unsigned int v4; // ebx
  DNA::PropertyBag *v5; // rbp
  const char *v6; // rdi
  DNA::PropertyBag *v7; // rsi
  __int64 v8; // rax
  DNA::PropertyData *v9; // rax
  DNA::PropertyData *v10; // rdi
  unsigned int v11; // eax
  __int64 v12; // rax

  v4 = undoId;
  v5 = v;
  v6 = propertyName;
  v7 = this;
  DNA::Database::Instance();
  DNA::ActionManager::BeginTransaction((DNA::ActionManager *)(v8 + 312), v4);
  if ( *v6 != 36 )
  {
    v9 = DNA::PropertyBag::CreateProperty(v7, v6, (DNA::PropertyType::Enum)-915936389);
    v10 = v9;
    if ( v9 )
    {
      v11 = DNA::PropertyData::Add(v9, v4);
      DNA::PropertyData::Set(v10, v11, v5, v4);
    }
  }
  DNA::Database::Instance();
  DNA::ActionManager::EndTransaction((DNA::ActionManager *)(v12 + 312), v4);
}

// File Line: 403
// RVA: 0x1A4D20
UFG::qBaseTreeRB *__fastcall DNA::PropertyBag::CreateProperty(DNA::PropertyBag *this, const char *propertyName, DNA::PropertyType::Enum propertyType)
{
  DNA::PropertyType::Enum v3; // ebx
  const char *v4; // rsi
  DNA::PropertyBag *v5; // rdi
  unsigned int v6; // eax
  UFG::qBaseTreeRB *result; // rax
  DNA::PropertyData *v8; // rbx
  UFG::allocator::free_link *v9; // rax
  DNA::PropertyData *v10; // rax

  v3 = propertyType;
  v4 = propertyName;
  v5 = this;
  v6 = UFG::qStringHashUpper32(propertyName, 0xFFFFFFFF);
  if ( v6 && (result = UFG::qBaseTreeRB::Get(&v5->mProperties.mTree, v6)) != 0i64 )
  {
    if ( LODWORD(result[1].mRoot.mParent) == v3 )
      return result;
    v8 = 0i64;
  }
  else
  {
    v9 = UFG::qMalloc(0x80ui64, "PropertyBag::CreateProperty", 0i64);
    if ( v9 )
    {
      DNA::PropertyData::PropertyData((DNA::PropertyData *)v9, v5, v4, v3);
      v8 = v10;
    }
    else
    {
      v8 = 0i64;
    }
    DNA::PropertyData::UpdateInheritanceBinding(v8, 0);
    UFG::qBaseTreeRB::Add(&v5->mProperties.mTree, &v8->mNode);
  }
  return (UFG::qBaseTreeRB *)v8;
}

// File Line: 441
// RVA: 0x1A57A0
UFG::qBaseTreeRB *__fastcall DNA::PropertyBag::GetProperty(DNA::PropertyBag *this, const char *propertyName)
{
  const char *v2; // rdi
  DNA::PropertyBag *v3; // rsi
  unsigned int v4; // eax
  UFG::qBaseTreeRB *v5; // rbx
  UFG::qTree64Base *v7; // rax

  v2 = propertyName;
  v3 = this;
  v4 = UFG::qStringHashUpper32(propertyName, 0xFFFFFFFF);
  if ( v4 )
  {
    v5 = UFG::qBaseTreeRB::Get(&v3->mProperties.mTree, v4);
    if ( v5 )
      return v5;
  }
  else
  {
    v5 = 0i64;
  }
  if ( !(unsigned int)UFG::qStringCompare(v2, "$ParentId", -1) || !(unsigned int)UFG::qStringCompare(v2, "$OwnerId", -1) )
    return 0i64;
  v7 = DNA::PropertyBag::GetParent(v3);
  if ( v7 )
    v5 = (UFG::qBaseTreeRB *)DNA::PropertyBag::GetProperty((DNA::PropertyBag *)v7, v2);
  return v5;
}

// File Line: 502
// RVA: 0x1A54D0
UFG::qString *__fastcall DNA::PropertyBag::GetName(DNA::PropertyBag *this, UFG::qString *result)
{
  UFG::qString *v2; // rdi
  DNA::PropertyBag *v3; // rbx
  DNA::PropertyData *v4; // rax
  DNA::PropertyData::Value *v5; // rax

  v2 = result;
  v3 = this;
  UFG::qString::qString(result);
  v4 = DNA::PropertyBag::GetProperty(v3, "$Name");
  if ( v4 )
  {
    if ( v4->mPropertyType == 826535573 )
    {
      v5 = DNA::PropertyData::GetValue(v4, 0);
      if ( v5 )
        UFG::qString::Set(v2, v5->mData.mData);
    }
  }
  return v2;
}

// File Line: 509
// RVA: 0x1A6DA0
void __fastcall DNA::PropertyBag::SetName(DNA::PropertyBag *this, const char *name)
{
  const char *v2; // rbx
  UFG::qBaseTreeRB *v3; // rax

  v2 = name;
  v3 = DNA::PropertyBag::CreateProperty(this, "$Name", (DNA::PropertyType::Enum)826535573);
  if ( v3 )
    DNA::PropertyData::Set((DNA::PropertyData *)v3, 0, v2, 0);
}

// File Line: 514
// RVA: 0x1A5DD0
UFG::qString *__fastcall DNA::PropertyBag::GetSchemaName(DNA::PropertyBag *this, UFG::qString *result)
{
  UFG::qString *v2; // rdi
  DNA::PropertyBag *v3; // rbx
  UFG::qBaseTreeRB *v4; // rax
  DNA::PropertyData::Value *v5; // rax

  v2 = result;
  v3 = this;
  UFG::qString::qString(result);
  v4 = DNA::PropertyBag::GetProperty(v3, "$SchemaName");
  if ( v4 )
  {
    if ( LODWORD(v4[1].mRoot.mParent) == 826535573 )
    {
      v5 = DNA::PropertyData::GetValue((DNA::PropertyData *)v4, 0);
      if ( v5 )
        UFG::qString::Set(v2, v5->mData.mData);
    }
  }
  return v2;
}

// File Line: 521
// RVA: 0x1A73A0
void __fastcall DNA::PropertyBag::SetSchemaName(DNA::PropertyBag *this, const char *name)
{
  const char *v2; // rbx
  UFG::qBaseTreeRB *v3; // rax

  v2 = name;
  v3 = DNA::PropertyBag::CreateProperty(this, "$SchemaName", (DNA::PropertyType::Enum)826535573);
  if ( v3 )
    DNA::PropertyData::Set((DNA::PropertyData *)v3, 0, v2, 0);
}

// File Line: 545
// RVA: 0x1A6D60
void __fastcall DNA::PropertyBag::SetFilePath(DNA::PropertyBag *this, const char *filePath)
{
  const char *v2; // rbx
  UFG::qBaseTreeRB *v3; // rax

  v2 = filePath;
  v3 = DNA::PropertyBag::CreateProperty(this, "$FilePath", (DNA::PropertyType::Enum)826535573);
  if ( v3 )
    DNA::PropertyData::Set((DNA::PropertyData *)v3, 0, v2, 0);
}

// File Line: 550
// RVA: 0x1A6E20
void __fastcall DNA::PropertyBag::SetOwnerUID(DNA::PropertyBag *this, unsigned __int64 uid)
{
  unsigned __int64 v2; // rdi
  DNA::PropertyBag *v3; // rbx
  UFG::qBaseTreeRB *v4; // rax
  DNA::PropertyData::Value *v5; // rax
  UFG::qBaseTreeRB *v6; // rax

  v2 = uid;
  v3 = this;
  v4 = DNA::PropertyBag::GetProperty(this, "$OwnerId");
  if ( !v4
    || LODWORD(v4[1].mRoot.mParent) != 151281197
    || (v5 = DNA::PropertyData::GetValue((DNA::PropertyData *)v4, 0)) == 0i64
    || !UFG::qToUInt64(v5->mData.mData, 0i64) )
  {
    v6 = DNA::PropertyBag::CreateProperty(v3, "$OwnerId", (DNA::PropertyType::Enum)151281197);
    if ( v6 )
      DNA::PropertyData::Set((DNA::PropertyData *)v6, 0, v2, 0);
  }
}

// File Line: 562
// RVA: 0x1A55F0
unsigned __int64 __fastcall DNA::PropertyBag::GetOwnerUID(DNA::PropertyBag *this)
{
  DNA::PropertyData *v1; // rax
  DNA::PropertyData::Value *v2; // rax
  unsigned __int64 result; // rax

  v1 = DNA::PropertyBag::GetProperty(this, "$OwnerId");
  if ( v1 && v1->mPropertyType == 151281197 && (v2 = DNA::PropertyData::GetValue(v1, 0)) != 0i64 )
    result = UFG::qToUInt64(v2->mData.mData, 0i64);
  else
    result = 0i64;
  return result;
}

// File Line: 569
// RVA: 0x1A5590
UFG::qTree64Base *__fastcall DNA::PropertyBag::GetOwner(DNA::PropertyBag *this)
{
  unsigned __int64 v1; // rbx
  DNA::PropertyData *v2; // rax
  DNA::PropertyData::Value *v3; // rax
  DNA::Database *v4; // rax

  v1 = 0i64;
  v2 = DNA::PropertyBag::GetProperty(this, "$OwnerId");
  if ( v2 )
  {
    if ( v2->mPropertyType == 151281197 )
    {
      v3 = DNA::PropertyData::GetValue(v2, 0);
      if ( v3 )
        v1 = UFG::qToUInt64(v3->mData.mData, 0i64);
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
  DNA::PropertyBag *v3; // rdi
  DNA::Database *v4; // rax

  v2 = owner;
  v3 = this;
  if ( owner )
    owner = (DNA::PropertyBag *)owner->mBaseNode.mUID;
  DNA::PropertyBag::SetOwnerUID(this, (unsigned __int64)owner);
  DNA::Database::Instance();
  DNA::Database::OnOwnerChanged(v4, v3, v2);
}

// File Line: 592
// RVA: 0x1A5640
UFG::qTree64Base *__fastcall DNA::PropertyBag::GetParent(DNA::PropertyBag *this)
{
  DNA::PropertyBag *v1; // rdi
  DNA::PropertyData *v2; // rax
  DNA::PropertyData::Value *v3; // rax
  unsigned __int64 v4; // rbx
  DNA::PropertyData *v5; // rax
  DNA::PropertyData::Value *v6; // rax
  DNA::Database *v7; // rax
  UFG::qTree64Base *v8; // rsi
  UFG::qString *v9; // rbx
  UFG::qString *v10; // rax
  DNA::PropertyBag *v11; // rax
  UFG::qString v13; // [rsp+28h] [rbp-60h]
  UFG::qString result; // [rsp+50h] [rbp-38h]

  v1 = this;
  v2 = DNA::PropertyBag::GetProperty(this, "$ParentId");
  if ( v2 )
  {
    if ( v2->mPropertyType == 151281197 )
    {
      v3 = DNA::PropertyData::GetValue(v2, 0);
      if ( v3 )
      {
        if ( UFG::qToUInt64(v3->mData.mData, 0i64) - 1 <= 0xFFFFFFFFFFFFFFFDui64 )
        {
          v4 = 0i64;
          v5 = DNA::PropertyBag::GetProperty(v1, "$ParentId");
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
          v8 = DNA::Database::GetPropertyBag(v7, v4);
          if ( v8 )
          {
            v9 = DNA::PropertyBag::GetSchemaName(v1, &result);
            v10 = DNA::PropertyBag::GetSchemaName((DNA::PropertyBag *)v8, &v13);
            LOBYTE(v9) = (unsigned int)UFG::qStringCompare(v10->mData, v9->mData, -1) == 0;
            UFG::qString::~qString(&v13);
            UFG::qString::~qString(&result);
            if ( (_BYTE)v9 )
            {
              v11 = DNA::PropertyBag::GetParent((DNA::PropertyBag *)v8);
              if ( !v11 )
                return v8;
              while ( v11->mBaseNode.mUID != v1->mBaseNode.mUID )
              {
                v11 = DNA::PropertyBag::GetParent(v11);
                if ( !v11 )
                  return v8;
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
  DNA::PropertyBag *v2; // rsi
  DNA::PropertyBag *v3; // r13
  unsigned __int64 v4; // rdi
  UFG::qString *v5; // rbx
  UFG::qString *v6; // rax
  UFG::qTree64Base *v7; // rax
  unsigned __int64 v8; // rbx
  UFG::qBaseTreeRB *v9; // rax
  DNA::PropertyData::Value *v10; // rax
  UFG::allocator::free_link *v11; // r15
  __int64 v12; // rsi
  unsigned int v13; // er14
  UFG::qBaseTreeRB *v14; // r12
  DNA::PropertyData *v15; // rbp
  const char *v16; // rcx
  DNA::SchemaField *v17; // rbx
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
  UFG::qBaseTreeRB *v33; // rbp
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
  DNA::SchemaType *v48; // [rsp+30h] [rbp-A8h]
  UFG::qString v49; // [rsp+40h] [rbp-98h]
  UFG::qString result; // [rsp+68h] [rbp-70h]
  DNA::PropertyBag *v51; // [rsp+E0h] [rbp+8h]
  DNA::PropertyBag *v52; // [rsp+E8h] [rbp+10h]
  unsigned __int64 v; // [rsp+F0h] [rbp+18h]
  signed __int64 v54; // [rsp+F8h] [rbp+20h]

  v52 = parent;
  v51 = this;
  v2 = parent;
  v3 = this;
  v4 = 0i64;
  v = 0i64;
  if ( !parent )
    goto LABEL_6;
  v4 = parent->mBaseNode.mUID;
  v = parent->mBaseNode.mUID;
  v5 = DNA::PropertyBag::GetSchemaName(this, &result);
  v6 = DNA::PropertyBag::GetSchemaName(v2, &v49);
  LOBYTE(v5) = (unsigned int)UFG::qStringCompare(v6->mData, v5->mData, -1) != 0;
  UFG::qString::~qString(&v49);
  UFG::qString::~qString(&result);
  if ( (_BYTE)v5 )
    return;
  v7 = DNA::PropertyBag::GetParent(v2);
  if ( !v7 )
  {
LABEL_6:
    v8 = 0i64;
    v9 = DNA::PropertyBag::GetProperty(v3, "$ParentId");
    if ( v9 )
    {
      if ( LODWORD(v9[1].mRoot.mParent) == 151281197 )
      {
        v10 = DNA::PropertyData::GetValue((DNA::PropertyData *)v9, 0);
        if ( v10 )
          v8 = UFG::qToUInt64(v10->mData.mData, 0i64);
      }
    }
    if ( v4 == v8 || v4 == v3->mBaseNode.mUID )
      return;
    v11 = 0i64;
    v12 = 0i64;
    v13 = 0;
    v48 = (DNA::SchemaType *)DNA::PropertyBag::GetSchemaType(v3);
    v14 = &v3->mProperties.mTree;
    v54 = (signed __int64)&v3->mProperties;
    v15 = (DNA::PropertyData *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&v3->mProperties);
    if ( v15 )
    {
      do
      {
        v16 = v15->mName.mData;
        if ( *v16 != 36 )
        {
          if ( v48 )
          {
            v18 = UFG::qStringHash64(v16, 0xFFFFFFFFFFFFFFFFui64);
            v17 = DNA::SchemaType::GetField(v48, v18);
          }
          else
          {
            v17 = 0i64;
          }
          if ( (unsigned int)DNA::PropertyData::NumItems(v15) == 1
            && (unsigned int)DNA::PropertyData::GetPropertyState(v15, 0, v17) == 1 )
          {
            v19 = (unsigned int)v12;
            v20 = v12 + 1;
            if ( (signed int)v12 + 1 > v13 )
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
            v11[v19].mNext = (UFG::allocator::free_link *)v15;
            v14 = &v3->mProperties.mTree;
          }
        }
        v15 = (DNA::PropertyData *)UFG::qBaseTreeRB::GetNext(v14, &v15->mNode);
      }
      while ( v15 );
      v3 = v51;
    }
    if ( (_DWORD)v12 )
    {
      v27 = v11;
      do
      {
        v28 = UFG::qStringHashUpper32((const char *)v27->mNext[7].mNext, 0xFFFFFFFF);
        if ( v28 )
        {
          v29 = UFG::qBaseTreeRB::Get(v14, v28);
          v30 = (DNA::PropertyData *)v29;
          if ( v29 )
          {
            UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
              (UFG::qBaseTreeVariableRB<unsigned __int64> *)v14,
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
    v33 = (UFG::qBaseTreeRB *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)v14);
    if ( !v33 )
    {
LABEL_75:
      if ( (_DWORD)v31 )
      {
        v44 = v11;
        do
        {
          v45 = UFG::qStringHashUpper32((const char *)v44->mNext[7].mNext, 0xFFFFFFFF);
          if ( v45 )
          {
            v46 = UFG::qBaseTreeRB::Get(v14, v45);
            v47 = (DNA::PropertyData *)v46;
            if ( v46 )
            {
              UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
                (UFG::qBaseTreeVariableRB<unsigned __int64> *)v14,
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
      if ( **(_BYTE **)&v33->mNULL.mUID != 36 )
      {
        if ( v52 )
        {
          v34 = v33->mRoot.mUID;
          if ( !v34 )
            goto LABEL_74;
          v35 = UFG::qBaseTreeRB::Get(&v52->mProperties.mTree, v34);
          if ( !v35 )
            goto LABEL_74;
          if ( LODWORD(v33[1].mRoot.mParent) != LODWORD(v35[1].mRoot.mParent) )
          {
            v36 = (unsigned int)v31;
            v37 = v31 + 1;
            if ( (signed int)v31 + 1 > v13 )
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
            v11[v36].mNext = (UFG::allocator::free_link *)v33;
            v14 = (UFG::qBaseTreeRB *)v54;
            goto LABEL_74;
          }
        }
        DNA::PropertyData::UpdateInheritanceBinding((DNA::PropertyData *)v33, eStatic);
      }
LABEL_74:
      v33 = UFG::qBaseTreeRB::GetNext(v14, &v33->mRoot);
      if ( !v33 )
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
  UFG::qBaseTreeRB *v3; // rax
  DNA::PropertyData::Value *v4; // rax
  DNA::Database *v5; // rax
  DNA::PropertyBag *v6; // rdi
  unsigned __int64 v7; // rbp
  unsigned int v8; // eax
  UFG::qBaseTreeRB *v9; // rbx
  UFG::qTree64Base *v10; // rax
  DNA::PropertyData::Value *v11; // rax
  DNA::Database *v12; // rax
  DNA::Event<void __cdecl(DNA::PropertyBag *)> *v13; // rax

  v1 = this;
  if ( this->mIsDirtyLock != 1 )
  {
    v2 = 0i64;
    v3 = DNA::PropertyBag::GetProperty(this, "$OwnerId");
    if ( v3 )
    {
      if ( LODWORD(v3[1].mRoot.mParent) == 151281197 )
      {
        v4 = DNA::PropertyData::GetValue((DNA::PropertyData *)v3, 0);
        if ( v4 )
          v2 = UFG::qToUInt64(v4->mData.mData, 0i64);
      }
    }
    DNA::Database::Instance();
    v6 = (DNA::PropertyBag *)DNA::Database::GetPropertyBag(v5, v2);
    if ( v6 )
    {
      while ( 1 )
      {
        v1 = v6;
        if ( v6->mIsDirtyLock == 1 )
          return;
        v7 = 0i64;
        v8 = UFG::qStringHashUpper32("$OwnerId", 0xFFFFFFFF);
        if ( !v8 )
          break;
        v9 = UFG::qBaseTreeRB::Get(&v6->mProperties.mTree, v8);
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
        v6 = (DNA::PropertyBag *)DNA::Database::GetPropertyBag(v12, v7);
        if ( !v6 )
          goto LABEL_20;
      }
      v9 = 0i64;
LABEL_11:
      if ( !(unsigned int)UFG::qStringCompare("$OwnerId", "$ParentId", -1)
        || !(unsigned int)UFG::qStringCompare("$OwnerId", "$OwnerId", -1) )
      {
        goto LABEL_19;
      }
      v10 = DNA::PropertyBag::GetParent(v6);
      if ( v10 )
        v9 = DNA::PropertyBag::GetProperty((DNA::PropertyBag *)v10, "$OwnerId");
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
void __fastcall DNA::PropertyData::PropertyData(DNA::PropertyData *this, DNA::PropertyBag *propertyOwner, const char *propertyName, DNA::PropertyType::Enum type)
{
  DNA::PropertyType::Enum v4; // edi
  const char *v5; // rsi
  DNA::PropertyBag *v6; // rbx
  DNA::PropertyData *v7; // r14
  unsigned int v8; // eax

  v4 = type;
  v5 = propertyName;
  v6 = propertyOwner;
  v7 = this;
  v8 = UFG::qStringHashUpper32(propertyName, 0xFFFFFFFF);
  v7->mNode.mParent = 0i64;
  v7->mNode.mChild[0] = 0i64;
  v7->mNode.mChild[1] = 0i64;
  v7->mNode.mUID = v8;
  UFG::qString::qString(&v7->mName, v5);
  v7->mPropertyType = v4;
  v7->mOwner = v6;
  v7->mOverrideMode = 0;
  v7->mArrayEntries.p = 0i64;
  *(_QWORD *)&v7->mArrayEntries.size = 0i64;
  v7->mOverrideArrayEntries.p = 0i64;
  *(_QWORD *)&v7->mOverrideArrayEntries.size = 0i64;
  if ( *v5 == 36 )
    v7->mOverrideMode = 1;
}

// File Line: 849
// RVA: 0x1A43E0
void __fastcall DNA::PropertyData::~PropertyData(DNA::PropertyData *this)
{
  DNA::PropertyData *v1; // rbx
  unsigned int v2; // edi
  DNA::PropertyData::Value **v3; // rax
  DNA::PropertyData::Value *v4; // rsi
  DNA::PropertyData::Value **v5; // rcx
  unsigned int i; // edi
  DNA::PropertyData::Value **v7; // rax
  DNA::PropertyData::Value *v8; // rsi
  DNA::PropertyData::Value **v9; // rcx
  DNA::PropertyData::Value **v10; // rcx
  DNA::PropertyData::Value **v11; // rcx

  v1 = this;
  v2 = 0;
  if ( this->mArrayEntries.size )
  {
    do
    {
      v3 = v1->mArrayEntries.p;
      v4 = v3[v2];
      if ( v4 )
      {
        DNA::PropertyData::Value::~Value(v3[v2]);
        operator delete[](v4);
      }
      ++v2;
    }
    while ( v2 < v1->mArrayEntries.size );
  }
  v5 = v1->mArrayEntries.p;
  if ( v5 )
    operator delete[](v5);
  v1->mArrayEntries.p = 0i64;
  *(_QWORD *)&v1->mArrayEntries.size = 0i64;
  for ( i = 0; i < v1->mOverrideArrayEntries.size; ++i )
  {
    v7 = v1->mOverrideArrayEntries.p;
    v8 = v7[i];
    if ( v8 )
    {
      DNA::PropertyData::Value::~Value(v7[i]);
      operator delete[](v8);
    }
  }
  v9 = v1->mOverrideArrayEntries.p;
  if ( v9 )
    operator delete[](v9);
  v1->mOverrideArrayEntries.p = 0i64;
  *(_QWORD *)&v1->mOverrideArrayEntries.size = 0i64;
  v1->mOwner = 0i64;
  v10 = v1->mOverrideArrayEntries.p;
  if ( v10 )
    operator delete[](v10);
  v1->mOverrideArrayEntries.p = 0i64;
  *(_QWORD *)&v1->mOverrideArrayEntries.size = 0i64;
  v11 = v1->mArrayEntries.p;
  if ( v11 )
    operator delete[](v11);
  v1->mArrayEntries.p = 0i64;
  *(_QWORD *)&v1->mArrayEntries.size = 0i64;
  UFG::qString::~qString(&v1->mName);
}

// File Line: 943
// RVA: 0x1A4750
__int64 __fastcall DNA::PropertyData::Add(DNA::PropertyData *this, unsigned int undoId)
{
  unsigned int v2; // esi
  DNA::PropertyData *v3; // rdi
  unsigned int v4; // ebp
  UFG::allocator::free_link *v5; // rbx
  UFG::allocator::free_link *v6; // rax
  UFG::allocator::free_link *v7; // rax
  UFG::allocator::free_link *v8; // rcx
  UFG::allocator::free_link *v9; // rax
  __int64 v10; // rax

  v2 = undoId;
  v3 = this;
  v4 = DNA::PropertyData::NumItems(this);
  v5 = UFG::qMalloc(0x30ui64, UFG::gGlobalNewName, 0i64);
  if ( v5 )
  {
    v6 = UFG::qMalloc(0x50ui64, UFG::gGlobalNewName, 0i64);
    if ( v6 )
    {
      DNA::PropertyData::Value::Value((DNA::PropertyData::Value *)v6, v3);
      v8 = v7;
    }
    else
    {
      v8 = 0i64;
    }
    v9 = v5 + 1;
    v9->mNext = v9;
    v9[1].mNext = v9;
    v5->mNext = (UFG::allocator::free_link *)&DNA::IAction::`vftable';
    LOBYTE(v5[3].mNext) = 1;
    *(UFG::allocator::free_link **)((char *)&v5[3].mNext + 4) = (UFG::allocator::free_link *)1601572253;
    v5->mNext = (UFG::allocator::free_link *)&DNA::PropertyData::AddValueAction::`vftable';
    v5[5].mNext = v8;
  }
  else
  {
    v5 = 0i64;
  }
  DNA::Database::Instance();
  DNA::ActionManager::AppendAction((DNA::ActionManager *)(v10 + 312), (DNA::IAction *)v5, v2);
  return v4;
}

// File Line: 967
// RVA: 0x1A5D50
DNA::SchemaField *__fastcall DNA::PropertyData::GetSchemaField(DNA::PropertyData *this)
{
  DNA::PropertyData *v1; // rdi
  char *v2; // rbx
  DNA::Database *v3; // rax
  UFG::qTree64Base *v4; // rbx
  unsigned __int64 v5; // rax
  UFG::qString result; // [rsp+28h] [rbp-30h]

  v1 = this;
  v2 = DNA::PropertyBag::GetSchemaName(this->mOwner, &result)->mData;
  DNA::Database::Instance();
  v4 = DNA::Database::GetSchema(v3, v2);
  UFG::qString::~qString(&result);
  if ( !v4 )
    return 0i64;
  v5 = UFG::qStringHash64(v1->mName.mData, 0xFFFFFFFFFFFFFFFFui64);
  return DNA::SchemaType::GetField((DNA::SchemaType *)v4, v5);
}

// File Line: 974
// RVA: 0x1A7760
void __fastcall DNA::PropertyData::UpdateInheritanceBinding(DNA::PropertyData *this, DNA::PropertyData::eOverrideOption overrideOption)
{
  DNA::PropertyData::eOverrideOption v2; // er12
  DNA::PropertyData *v3; // rbx
  __int64 v4; // r13
  unsigned int v5; // er14
  DNA::PropertyData::Value *v6; // r15
  unsigned int v7; // ecx
  unsigned int v8; // esi
  unsigned int v9; // edi
  unsigned int v10; // edi
  unsigned __int64 v11; // rax
  UFG::allocator::free_link *v12; // rax
  DNA::PropertyData::Value **v13; // rbp
  unsigned int i; // er9
  signed __int64 v15; // r8
  signed __int64 v16; // r9
  DNA::PropertyData::Value *v17; // rdx
  __int64 v18; // rcx
  unsigned int v19; // er8
  DNA::PropertyData::Value **v20; // r9
  unsigned int v21; // eax
  DNA::PropertyData::eOverrideMode v22; // eax
  UFG::qTree64Base *v23; // rax
  UFG::qBaseTreeRB *v24; // r15
  DNA::SchemaField *v25; // rax
  signed int v26; // eax
  char v27; // al
  bool v28; // zf
  unsigned int v29; // esi
  unsigned int v30; // edi
  UFG::qTree64Base *v31; // rax
  UFG::qBaseTreeRB *v32; // rax
  int v33; // eax
  unsigned int v34; // eax
  signed int v35; // er13
  __int64 v36; // rcx
  DNA::PropertyData::Value **v37; // rax
  DNA::PropertyData::Value *v38; // r12
  unsigned int j; // ebp
  unsigned int v40; // edi
  UFG::qTree64Base *v41; // rax
  UFG::qBaseTreeRB *v42; // rax
  int v43; // eax
  DNA::PropertyData::Value *v44; // rax
  DNA::PropertyData::Value *v45; // rsi
  signed int v46; // er8
  signed __int64 v47; // rdx
  unsigned int v48; // eax
  __int64 v49; // r13
  unsigned int v50; // ebp
  unsigned int v51; // edi
  unsigned int v52; // edi
  unsigned __int64 v53; // rax
  UFG::allocator::free_link *v54; // rax
  DNA::PropertyData::Value **v55; // r12
  unsigned int k; // er9
  unsigned __int64 v57; // rdi
  DNA::Database *v58; // rax
  UFG::qTree64Base *v59; // rbp
  unsigned __int64 v60; // rdi
  DNA::Database *v61; // rax
  UFG::qTree64Base *v62; // rax
  DNA::PropertyData::Value **v63; // rcx
  __int64 v64; // r13
  unsigned int v65; // ebp
  unsigned int v66; // edi
  unsigned int v67; // edi
  unsigned __int64 v68; // rax
  UFG::allocator::free_link *v69; // rax
  UFG::allocator::free_link *v70; // r12
  unsigned int l; // er9
  unsigned __int64 v72; // rdi
  DNA::Database *v73; // rax
  UFG::qTree64Base *v74; // rax
  signed __int64 v75; // [rsp+20h] [rbp-78h]
  DNA::PropertyData::Value *v76; // [rsp+28h] [rbp-70h]
  bool v77; // [rsp+A0h] [rbp+8h]
  DNA::PropertyData::eOverrideOption v78; // [rsp+A8h] [rbp+10h]
  unsigned int v79; // [rsp+B0h] [rbp+18h]
  signed int v80; // [rsp+B8h] [rbp+20h]
  int v81; // [rsp+B8h] [rbp+20h]

  v78 = overrideOption;
  v2 = overrideOption;
  v3 = this;
  LODWORD(v4) = this->mOverrideArrayEntries.size;
  v5 = 0;
  if ( (_DWORD)v4 )
  {
    do
    {
      v4 = (unsigned int)(v4 - 1);
      v6 = v3->mOverrideArrayEntries.p[v4];
      v7 = v3->mArrayEntries.size;
      v8 = v7 + 1;
      v9 = v3->mArrayEntries.capacity;
      if ( v7 + 1 > v9 )
      {
        if ( v9 )
          v10 = 2 * v9;
        else
          v10 = 1;
        for ( ; v10 < v8; v10 *= 2 )
          ;
        if ( v10 <= 2 )
          v10 = 2;
        if ( v10 - v8 > 0x10000 )
          v10 = v7 + 65537;
        if ( v10 != v7 )
        {
          v11 = 8i64 * v10;
          if ( !is_mul_ok(v10, 8ui64) )
            v11 = -1i64;
          v12 = UFG::qMalloc(v11, "qArray.Insert", 0i64);
          v13 = (DNA::PropertyData::Value **)v12;
          if ( v3->mArrayEntries.p )
          {
            for ( i = 0; i < v3->mArrayEntries.size; ++i )
              v12[i] = (UFG::allocator::free_link)v3->mArrayEntries.p[i];
            operator delete[](v3->mArrayEntries.p);
          }
          v3->mArrayEntries.p = v13;
          v3->mArrayEntries.capacity = v10;
        }
      }
      v3->mArrayEntries.size = v8;
      v15 = v8 - 1;
      if ( v8 != 1 )
      {
        v16 = v15;
        do
        {
          LODWORD(v15) = v15 - 1;
          v3->mArrayEntries.p[v16] = v3->mArrayEntries.p[(unsigned int)v15];
          --v16;
        }
        while ( (_DWORD)v15 );
      }
      *v3->mArrayEntries.p = v6;
      v17 = v6->mOverridenValue;
      if ( v17 )
      {
        v18 = 0i64;
        v19 = v17->mInheritedValues.size;
        if ( v19 )
        {
          v20 = v17->mInheritedValues.p;
          while ( v6 != v20[v18] )
          {
            v18 = (unsigned int)(v18 + 1);
            if ( (unsigned int)v18 >= v19 )
              goto LABEL_33;
          }
          if ( (signed int)v18 >= 0 )
          {
            v20[v18] = v20[v19 - 1];
            v21 = v17->mInheritedValues.size;
            if ( v21 > 1 )
              v17->mInheritedValues.size = v21 - 1;
            else
              v17->mInheritedValues.size = 0;
          }
        }
LABEL_33:
        v6->mOverridenValue = 0i64;
      }
    }
    while ( (_DWORD)v4 );
    v2 = v78;
  }
  v3->mOverrideArrayEntries.size = 0;
  v22 = v3->mOverrideMode;
  if ( v22 != 1 )
  {
    if ( v22 == eOverride
      && (v23 = DNA::PropertyBag::GetParent(v3->mOwner)) != 0i64
      && (v24 = DNA::PropertyBag::GetProperty((DNA::PropertyBag *)v23, v3->mName.mData)) != 0i64 )
    {
      v77 = 0;
      if ( v2 == 1 )
      {
        v25 = DNA::PropertyData::GetSchemaField(v3);
        if ( v25 )
        {
          v26 = v25->mArrayLength;
          if ( v26 > 1 || (v28 = v26 == -1, v27 = 0, v28) )
            v27 = 1;
          v28 = v27 == 0;
        }
        else
        {
          v29 = v3->mArrayEntries.size;
          v30 = v24[1].mRoot.mUID;
          if ( !LODWORD(v24[1].mRoot.mChild[1]) )
          {
            v31 = DNA::PropertyBag::GetParent((DNA::PropertyBag *)v24[1].mRoot.mChild[0]);
            if ( v31
              && (v32 = DNA::PropertyBag::GetProperty((DNA::PropertyBag *)v31, *(const char **)&v24->mNULL.mUID)) != 0i64 )
            {
              v33 = DNA::PropertyData::NumItems((DNA::PropertyData *)v32);
            }
            else
            {
              v33 = 0;
            }
            v30 += v33;
          }
          if ( v30 > v29 )
            v29 = v30;
          v28 = v29 == 1;
        }
        v77 = v28;
      }
      v34 = 0;
      v79 = 0;
      if ( v3->mArrayEntries.size > 0 )
      {
        v35 = 1;
        v80 = 1;
        v75 = 8i64;
        do
        {
          v36 = v34;
          v37 = v3->mArrayEntries.p;
          v38 = v37[v36];
          v76 = v37[v36];
          for ( j = 0; ; ++j )
          {
            v40 = v24[1].mRoot.mUID;
            if ( !LODWORD(v24[1].mRoot.mChild[1]) )
            {
              v41 = DNA::PropertyBag::GetParent((DNA::PropertyBag *)v24[1].mRoot.mChild[0]);
              if ( v41
                && (v42 = DNA::PropertyBag::GetProperty((DNA::PropertyBag *)v41, *(const char **)&v24->mNULL.mUID)) != 0i64 )
              {
                v43 = DNA::PropertyData::NumItems((DNA::PropertyData *)v42);
              }
              else
              {
                v43 = 0;
              }
              v40 += v43;
            }
            if ( j >= v40 )
              break;
            v44 = DNA::PropertyData::GetValue((DNA::PropertyData *)v24, j);
            v45 = v44;
            if ( v77 == 1 )
              v38->mID = v44->mID;
            if ( v38->mID == v44->mID )
            {
              v46 = v35;
              if ( v35 != v3->mArrayEntries.size )
              {
                v47 = v75;
                do
                {
                  *(DNA::PropertyData::Value **)((char *)v3->mArrayEntries.p + v47 - 8) = *(DNA::PropertyData::Value **)((char *)v3->mArrayEntries.p + v47);
                  ++v46;
                  v47 += 8i64;
                }
                while ( v46 != v3->mArrayEntries.size );
              }
              v48 = v3->mArrayEntries.size;
              if ( v48 > 1 )
                v3->mArrayEntries.size = v48 - 1;
              else
                v3->mArrayEntries.size = 0;
              v49 = v3->mOverrideArrayEntries.size;
              v50 = v49 + 1;
              v51 = v3->mOverrideArrayEntries.capacity;
              if ( (signed int)v49 + 1 > v51 )
              {
                if ( v51 )
                  v52 = 2 * v51;
                else
                  v52 = 1;
                for ( ; v52 < v50; v52 *= 2 )
                  ;
                if ( v52 <= 2 )
                  v52 = 2;
                if ( v52 - v50 > 0x10000 )
                  v52 = v49 + 65537;
                if ( v52 != (_DWORD)v49 )
                {
                  v53 = 8i64 * v52;
                  if ( !is_mul_ok(v52, 8ui64) )
                    v53 = -1i64;
                  v54 = UFG::qMalloc(v53, "qArray.Add", 0i64);
                  v55 = (DNA::PropertyData::Value **)v54;
                  if ( v3->mOverrideArrayEntries.p )
                  {
                    for ( k = 0; k < v3->mOverrideArrayEntries.size; ++k )
                      v54[k] = (UFG::allocator::free_link)v3->mOverrideArrayEntries.p[k];
                    operator delete[](v3->mOverrideArrayEntries.p);
                  }
                  v3->mOverrideArrayEntries.p = v55;
                  v3->mOverrideArrayEntries.capacity = v52;
                  v38 = v76;
                }
              }
              v3->mOverrideArrayEntries.size = v50;
              v3->mOverrideArrayEntries.p[v49] = v38;
              --v79;
              v81 = v80 - 1;
              v75 -= 8i64;
              if ( v3->mPropertyType == -915936389 )
              {
                v57 = UFG::qToUInt64(v38->mData.mData, 0i64);
                DNA::Database::Instance();
                v59 = DNA::Database::GetPropertyBag(v58, v57);
                v60 = UFG::qToUInt64(v45->mData.mData, 0i64);
                DNA::Database::Instance();
                v62 = DNA::Database::GetPropertyBag(v61, v60);
                if ( v59 )
                {
                  if ( v62 )
                    DNA::PropertyBag::SetParent((DNA::PropertyBag *)v59, (DNA::PropertyBag *)v62);
                }
              }
              if ( v45->mInheritedValues.size )
              {
                v63 = v45->mInheritedValues.p;
                if ( v63 )
                  operator delete[](v63);
                v45->mInheritedValues.p = 0i64;
                *(_QWORD *)&v45->mInheritedValues.size = 0i64;
              }
              v38->mOverridenValue = v45;
              v64 = v45->mInheritedValues.size;
              v65 = v64 + 1;
              v66 = v45->mInheritedValues.capacity;
              if ( (signed int)v64 + 1 > v66 )
              {
                if ( v66 )
                  v67 = 2 * v66;
                else
                  v67 = 1;
                for ( ; v67 < v65; v67 *= 2 )
                  ;
                if ( v67 <= 2 )
                  v67 = 2;
                if ( v67 - v65 > 0x10000 )
                  v67 = v64 + 65537;
                if ( v67 != (_DWORD)v64 )
                {
                  v68 = 8i64 * v67;
                  if ( !is_mul_ok(v67, 8ui64) )
                    v68 = -1i64;
                  v69 = UFG::qMalloc(v68, "qArray.Add", 0i64);
                  v70 = v69;
                  if ( v45->mInheritedValues.p )
                  {
                    for ( l = 0; l < v45->mInheritedValues.size; ++l )
                      v69[l] = (UFG::allocator::free_link)v45->mInheritedValues.p[l];
                    operator delete[](v45->mInheritedValues.p);
                  }
                  v45->mInheritedValues.p = (DNA::PropertyData::Value **)v70;
                  v45->mInheritedValues.capacity = v67;
                  v38 = v76;
                }
              }
              v45->mInheritedValues.size = v65;
              v45->mInheritedValues.p[v64] = v38;
              v35 = v81;
              break;
            }
          }
          v34 = v79 + 1;
          v79 = v34;
          v80 = ++v35;
          v75 += 8i64;
        }
        while ( v34 < v3->mArrayEntries.size );
      }
    }
    else if ( v3->mPropertyType == -915936389 && v3->mArrayEntries.size > 0 )
    {
      do
      {
        if ( v3->mPropertyType == -915936389 )
        {
          v72 = UFG::qToUInt64(v3->mArrayEntries.p[v5]->mData.mData, 0i64);
          DNA::Database::Instance();
          v74 = DNA::Database::GetPropertyBag(v73, v72);
          if ( v74 )
            DNA::PropertyBag::SetParent((DNA::PropertyBag *)v74, 0i64);
        }
        ++v5;
      }
      while ( v5 < v3->mArrayEntries.size );
    }
  }
}

// File Line: 1100
// RVA: 0x1A6120
__int64 __fastcall DNA::PropertyData::NumItems(DNA::PropertyData *this)
{
  unsigned int v1; // ebx
  DNA::PropertyData *v2; // rdi
  UFG::qTree64Base *v3; // rax
  UFG::qBaseTreeRB *v4; // rax
  __int64 result; // rax

  v1 = this->mArrayEntries.size;
  v2 = this;
  if ( this->mOverrideMode )
    return v1;
  v3 = DNA::PropertyBag::GetParent(this->mOwner);
  if ( v3 && (v4 = DNA::PropertyBag::GetProperty((DNA::PropertyBag *)v3, v2->mName.mData)) != 0i64 )
    result = v1 + DNA::PropertyData::NumItems((DNA::PropertyData *)v4);
  else
    result = v1;
  return result;
}

// File Line: 1129
// RVA: 0x1A5450
void __fastcall DNA::PropertyData::Get(DNA::PropertyData *this, unsigned int index, unsigned __int64 *v)
{
  unsigned __int64 *v3; // rbx
  DNA::PropertyData::Value *v4; // rax

  v3 = v;
  if ( this->mPropertyType == 151281197 )
  {
    v4 = DNA::PropertyData::GetValue(this, index);
    if ( v4 )
      *v3 = UFG::qToUInt64(v4->mData.mData, 0i64);
  }
}

// File Line: 1132
// RVA: 0x1A53E0
void __fastcall DNA::PropertyData::Get(DNA::PropertyData *this, unsigned int index, float *v)
{
  float *v3; // rbx
  DNA::PropertyData::Value *v4; // rax
  char *v5; // rcx

  v3 = v;
  if ( this->mPropertyType == 1208522079 )
  {
    v4 = DNA::PropertyData::GetValue(this, index);
    if ( v4 )
    {
      v5 = v4->mData.mData;
      if ( (*v5 != 48 || (v5[1] - 88) & 0xDF) && *v5 != 35 )
        *v3 = UFG::qToFloat(v5, 0.0);
      else
        *(_DWORD *)v3 = UFG::qToUInt32(v5, 0);
    }
  }
}

// File Line: 1133
// RVA: 0x1A5480
void __fastcall DNA::PropertyData::Get(DNA::PropertyData *this, unsigned int index, DNA::PropertyBag **v)
{
  DNA::PropertyBag **v3; // rdi
  DNA::PropertyData::Value *v4; // rax
  unsigned __int64 v5; // rbx
  DNA::Database *v6; // rax

  v3 = v;
  if ( this->mPropertyType == -915936389 )
  {
    v4 = DNA::PropertyData::GetValue(this, index);
    if ( v4 )
    {
      v5 = UFG::qToUInt64(v4->mData.mData, 0i64);
      DNA::Database::Instance();
      *v3 = (DNA::PropertyBag *)DNA::Database::GetPropertyBag(v6, v5);
    }
  }
}

// File Line: 1135
// RVA: 0x1A5D20
void __fastcall DNA::PropertyData::GetRaw(DNA::PropertyData *this, unsigned int index, UFG::qString *v)
{
  UFG::qString *v3; // rbx
  DNA::PropertyData::Value *v4; // rax

  v3 = v;
  v4 = DNA::PropertyData::GetValue(this, index);
  if ( v4 )
    UFG::qString::Set(v3, v4->mData.mData);
}

// File Line: 1138
// RVA: 0x1A6A00
void __fastcall DNA::PropertyData::Set(DNA::PropertyData *this, unsigned int index, const char *v, unsigned int undoId)
{
  unsigned int v4; // edi
  const char *v5; // rsi
  DNA::PropertyData *v6; // rbx
  DNA::PropertyData::Value *v7; // rax
  DNA::PropertyData::Value *v8; // rbx
  UFG::allocator::free_link *v9; // rax
  DNA::PropertyData::SetValueAction *v10; // rax
  DNA::PropertyData::SetValueAction *v11; // rbx
  __int64 v12; // rax

  v4 = undoId;
  v5 = v;
  v6 = this;
  if ( this->mPropertyType == 826535573 )
  {
    v7 = DNA::PropertyData::GetValue(this, index);
    v8 = DNA::PropertyData::OverrideValue(v6, v7);
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
      UFG::qString::Set(&v11->mNewValue, v5);
      DNA::PropertyData::SetValueAction::Validate(v11);
      DNA::Database::Instance();
      DNA::ActionManager::AppendAction((DNA::ActionManager *)(v12 + 312), (DNA::IAction *)&v11->vfptr, v4);
    }
  }
}

// File Line: 1139
// RVA: 0x1A6630
void __fastcall DNA::PropertyData::Set(DNA::PropertyData *this, unsigned int index, int v, unsigned int undoId)
{
  unsigned int v4; // edi
  int v5; // esi
  DNA::PropertyData *v6; // rbx
  DNA::PropertyData::Value *v7; // rax
  DNA::PropertyData::Value *v8; // rbx
  UFG::allocator::free_link *v9; // rax
  DNA::PropertyData::SetValueAction *v10; // rax
  DNA::PropertyData::SetValueAction *v11; // rbx
  UFG::qString *v12; // rax
  __int64 v13; // rax
  UFG::qString result; // [rsp+38h] [rbp-30h]

  v4 = undoId;
  v5 = v;
  v6 = this;
  if ( this->mPropertyType == -2133091136 )
  {
    v7 = DNA::PropertyData::GetValue(this, index);
    v8 = DNA::PropertyData::OverrideValue(v6, v7);
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
      v12 = UFG::qToHex(&result, v5);
      UFG::qString::Set(&v11->mNewValue, v12->mData, v12->mLength, 0i64, 0);
      UFG::qString::~qString(&result);
      DNA::PropertyData::SetValueAction::Validate(v11);
      DNA::Database::Instance();
      DNA::ActionManager::AppendAction((DNA::ActionManager *)(v13 + 312), (DNA::IAction *)&v11->vfptr, v4);
    }
  }
}

// File Line: 1140
// RVA: 0x1A6AB0
void __fastcall DNA::PropertyData::Set(DNA::PropertyData *this, unsigned int index, __int64 v, unsigned int undoId)
{
  unsigned int v4; // edi
  __int64 v5; // rsi
  DNA::PropertyData *v6; // rbx
  DNA::PropertyData::Value *v7; // rax
  DNA::PropertyData::Value *v8; // rbx
  UFG::allocator::free_link *v9; // rax
  DNA::PropertyData::SetValueAction *v10; // rax
  DNA::PropertyData::SetValueAction *v11; // rbx
  UFG::qString *v12; // rax
  __int64 v13; // rax
  UFG::qString result; // [rsp+38h] [rbp-30h]

  v4 = undoId;
  v5 = v;
  v6 = this;
  if ( this->mPropertyType == 224407815 )
  {
    v7 = DNA::PropertyData::GetValue(this, index);
    v8 = DNA::PropertyData::OverrideValue(v6, v7);
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
      v12 = UFG::qToHex(&result, v5);
      UFG::qString::Set(&v11->mNewValue, v12->mData, v12->mLength, 0i64, 0);
      UFG::qString::~qString(&result);
      DNA::PropertyData::SetValueAction::Validate(v11);
      DNA::Database::Instance();
      DNA::ActionManager::AppendAction((DNA::ActionManager *)(v13 + 312), (DNA::IAction *)&v11->vfptr, v4);
    }
  }
}

// File Line: 1141
// RVA: 0x1A6720
void __fastcall DNA::PropertyData::Set(DNA::PropertyData *this, unsigned int index, unsigned int v, unsigned int undoId)
{
  unsigned int v4; // edi
  unsigned int v5; // esi
  DNA::PropertyData *v6; // rbx
  DNA::PropertyData::Value *v7; // rax
  DNA::PropertyData::Value *v8; // rbx
  UFG::allocator::free_link *v9; // rax
  DNA::PropertyData::SetValueAction *v10; // rax
  DNA::PropertyData::SetValueAction *v11; // rbx
  UFG::qString *v12; // rax
  __int64 v13; // rax
  UFG::qString result; // [rsp+38h] [rbp-30h]

  v4 = undoId;
  v5 = v;
  v6 = this;
  if ( this->mPropertyType == -2067794966 )
  {
    v7 = DNA::PropertyData::GetValue(this, index);
    v8 = DNA::PropertyData::OverrideValue(v6, v7);
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
      v12 = UFG::qToHex(&result, v5);
      UFG::qString::Set(&v11->mNewValue, v12->mData, v12->mLength, 0i64, 0);
      UFG::qString::~qString(&result);
      DNA::PropertyData::SetValueAction::Validate(v11);
      DNA::Database::Instance();
      DNA::ActionManager::AppendAction((DNA::ActionManager *)(v13 + 312), (DNA::IAction *)&v11->vfptr, v4);
    }
  }
}

// File Line: 1142
// RVA: 0x1A6BA0
void __fastcall DNA::PropertyData::Set(DNA::PropertyData *this, unsigned int index, unsigned __int64 v, unsigned int undoId)
{
  unsigned int v4; // edi
  unsigned __int64 v5; // rsi
  DNA::PropertyData *v6; // rbx
  DNA::PropertyData::Value *v7; // rax
  DNA::PropertyData::Value *v8; // rbx
  UFG::allocator::free_link *v9; // rax
  DNA::PropertyData::SetValueAction *v10; // rax
  DNA::PropertyData::SetValueAction *v11; // rbx
  UFG::qString *v12; // rax
  __int64 v13; // rax
  UFG::qString result; // [rsp+38h] [rbp-30h]

  v4 = undoId;
  v5 = v;
  v6 = this;
  if ( this->mPropertyType == 151281197 )
  {
    v7 = DNA::PropertyData::GetValue(this, index);
    v8 = DNA::PropertyData::OverrideValue(v6, v7);
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
      v12 = UFG::qToHex(&result, v5);
      UFG::qString::Set(&v11->mNewValue, v12->mData, v12->mLength, 0i64, 0);
      UFG::qString::~qString(&result);
      DNA::PropertyData::SetValueAction::Validate(v11);
      DNA::Database::Instance();
      DNA::ActionManager::AppendAction((DNA::ActionManager *)(v13 + 312), (DNA::IAction *)&v11->vfptr, v4);
    }
  }
}

// File Line: 1143
// RVA: 0x1A6C90
void __fastcall DNA::PropertyData::Set(DNA::PropertyData *this, unsigned int index, bool v, unsigned int undoId)
{
  unsigned int v4; // edi
  bool v5; // si
  DNA::PropertyData *v6; // rbx
  DNA::PropertyData::Value *v7; // rax
  DNA::PropertyData::Value *v8; // rbx
  UFG::allocator::free_link *v9; // rax
  DNA::PropertyData::SetValueAction *v10; // rax
  DNA::PropertyData::SetValueAction *v11; // rbx
  const char *v12; // rdx
  __int64 v13; // rax

  v4 = undoId;
  v5 = v;
  v6 = this;
  if ( this->mPropertyType == 1138723642 )
  {
    v7 = DNA::PropertyData::GetValue(this, index);
    v8 = DNA::PropertyData::OverrideValue(v6, v7);
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
      if ( v5 )
        v12 = "true";
      UFG::qString::Set(&v11->mNewValue, v12);
      DNA::PropertyData::SetValueAction::Validate(v11);
      DNA::Database::Instance();
      DNA::ActionManager::AppendAction((DNA::ActionManager *)(v13 + 312), (DNA::IAction *)&v11->vfptr, v4);
    }
  }
}

// File Line: 1145
// RVA: 0x1A6810
void __fastcall DNA::PropertyData::Set(DNA::PropertyData *this, unsigned int index, float v, unsigned int undoId)
{
  unsigned int v4; // edi
  DNA::PropertyData *v5; // rbx
  DNA::PropertyData::Value *v6; // rax
  DNA::PropertyData::Value *v7; // rbx
  UFG::allocator::free_link *v8; // rax
  DNA::PropertyData::SetValueAction *v9; // rax
  DNA::PropertyData::SetValueAction *v10; // rbx
  __int64 v11; // rax
  char buffer; // [rsp+40h] [rbp-118h]

  v4 = undoId;
  v5 = this;
  if ( this->mPropertyType == 1208522079 )
  {
    v6 = DNA::PropertyData::GetValue(this, index);
    v7 = DNA::PropertyData::OverrideValue(v5, v6);
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
      UFG::qToStringHex(&buffer, 0x100ui64, LODWORD(v), 4ui64, 1);
      UFG::qString::Set(&v10->mNewValue, &buffer);
      DNA::PropertyData::SetValueAction::Validate(v10);
      DNA::Database::Instance();
      DNA::ActionManager::AppendAction((DNA::ActionManager *)(v11 + 312), (DNA::IAction *)&v10->vfptr, v4);
    }
  }
}

// File Line: 1146
// RVA: 0x1A6910
void __fastcall DNA::PropertyData::Set(DNA::PropertyData *this, unsigned int index, DNA::PropertyBag *v, unsigned int undoId)
{
  unsigned int v4; // edi
  DNA::PropertyBag *v5; // rsi
  DNA::PropertyData *v6; // rbx
  DNA::PropertyData::Value *v7; // rax
  DNA::PropertyData::Value *v8; // rbx
  UFG::allocator::free_link *v9; // rax
  DNA::PropertyData::SetValueAction *v10; // rax
  DNA::PropertyData::SetValueAction *v11; // rbx
  UFG::qString *v12; // rax
  __int64 v13; // rax
  UFG::qString result; // [rsp+38h] [rbp-30h]

  v4 = undoId;
  v5 = v;
  v6 = this;
  if ( this->mPropertyType == -915936389 )
  {
    v7 = DNA::PropertyData::GetValue(this, index);
    v8 = DNA::PropertyData::OverrideValue(v6, v7);
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
      v12 = UFG::qToHex(&result, v5->mBaseNode.mUID);
      UFG::qString::Set(&v11->mNewValue, v12->mData, v12->mLength, 0i64, 0);
      UFG::qString::~qString(&result);
      DNA::PropertyData::SetValueAction::Validate(v11);
      DNA::Database::Instance();
      DNA::ActionManager::AppendAction((DNA::ActionManager *)(v13 + 312), (DNA::IAction *)&v11->vfptr, v4);
    }
  }
}

// File Line: 1151
// RVA: 0x1A5EA0
DNA::PropertyData::Value *__fastcall DNA::PropertyData::GetValue(DNA::PropertyData *this, unsigned int index)
{
  unsigned int v2; // edi
  DNA::PropertyData *v3; // rbx
  UFG::qTree64Base *v4; // rax
  UFG::qBaseTreeRB *v5; // rax
  DNA::PropertyData *v6; // rsi
  unsigned int v7; // eax
  DNA::PropertyData::Value *v8; // rax
  unsigned int v9; // er8
  DNA::PropertyData::Value *v10; // r10
  __int64 v11; // rax
  DNA::PropertyData::Value **v12; // rdx
  DNA::PropertyData::Value *result; // rax
  __int64 v14; // rdi

  v2 = index;
  v3 = this;
  if ( this->mOverrideMode
    || (v4 = DNA::PropertyBag::GetParent(this->mOwner)) == 0i64
    || (v5 = DNA::PropertyBag::GetProperty((DNA::PropertyBag *)v4, v3->mName.mData),
        (v6 = (DNA::PropertyData *)v5) == 0i64) )
  {
    v7 = 0;
LABEL_13:
    v14 = v2 - v7;
    if ( (unsigned int)v14 < v3->mArrayEntries.size )
      result = v3->mArrayEntries.p[v14];
    else
      result = 0i64;
    return result;
  }
  v7 = DNA::PropertyData::NumItems((DNA::PropertyData *)v5);
  if ( v2 >= v7 )
    goto LABEL_13;
  v8 = DNA::PropertyData::GetValue(v6, v2);
  v9 = v3->mOverrideArrayEntries.size;
  v10 = v8;
  v11 = 0i64;
  if ( !v9 )
    return v10;
  v12 = v3->mOverrideArrayEntries.p;
  while ( (*v12)->mID != v10->mID )
  {
    v11 = (unsigned int)(v11 + 1);
    ++v12;
    if ( (unsigned int)v11 >= v9 )
      return v10;
  }
  result = v3->mOverrideArrayEntries.p[v11];
  if ( !result )
    return v10;
  return result;
}

// File Line: 1223
// RVA: 0x1A61A0
DNA::PropertyData::Value *__fastcall DNA::PropertyData::OverrideValue(DNA::PropertyData *this, DNA::PropertyData::Value *entry)
{
  DNA::PropertyData::Value *v2; // rbx
  DNA::PropertyData *v3; // rdi
  UFG::allocator::free_link *v4; // rax
  DNA::PropertyData::Value *v5; // rax
  DNA::PropertyData::Value *v6; // rsi
  __int64 v7; // rbp
  unsigned int v8; // ebx
  unsigned int v9; // edx
  unsigned int v10; // edx

  v2 = entry;
  v3 = this;
  if ( !entry )
    return this->mArrayEntries.p[(unsigned int)DNA::PropertyData::Add(this, 0)];
  if ( entry->mOwner == this )
    return v2;
  v4 = UFG::qMalloc(0x50ui64, UFG::gGlobalNewName, 0i64);
  if ( v4 )
  {
    DNA::PropertyData::Value::Value((DNA::PropertyData::Value *)v4, v3, v2);
    v6 = v5;
  }
  else
  {
    v6 = 0i64;
  }
  v7 = v3->mOverrideArrayEntries.size;
  v8 = v7 + 1;
  v9 = v3->mOverrideArrayEntries.capacity;
  if ( (signed int)v7 + 1 > v9 )
  {
    if ( v9 )
      v10 = 2 * v9;
    else
      v10 = 1;
    for ( ; v10 < v8; v10 *= 2 )
      ;
    if ( v10 <= 2 )
      v10 = 2;
    if ( v10 - v8 > 0x10000 )
      v10 = v7 + 65537;
    UFG::qArray<UFG::CompositeDrawableComponent *,32>::Reallocate(
      (UFG::qArray<UFG::qReflectInventoryBase *,0> *)&v3->mOverrideArrayEntries,
      v10,
      "qArray.Add");
  }
  v3->mOverrideArrayEntries.size = v8;
  v3->mOverrideArrayEntries.p[v7] = v6;
  return v6;
}

// File Line: 1265
// RVA: 0x1A5B80
signed __int64 __fastcall DNA::PropertyData::GetPropertyState(DNA::PropertyData *this, int index, DNA::SchemaField *schemaField)
{
  DNA::SchemaField *v3; // rbp
  unsigned int v4; // edi
  DNA::PropertyData *v5; // rbx
  UFG::qTree64Base *v6; // rax
  UFG::qBaseTreeRB *v7; // rax
  DNA::PropertyData *v8; // rsi
  DNA::PropertyData::Value *v9; // rax
  DNA::PropertyData::Value *v10; // rax
  _BOOL8 v11; // rbx
  DNA::PropertyData::Value *v13; // rax
  const char *v14; // rax
  UFG::qString v15; // [rsp+28h] [rbp-60h]
  UFG::qString v16; // [rsp+50h] [rbp-38h]

  v3 = schemaField;
  v4 = index;
  v5 = this;
  if ( index >= DNA::PropertyData::NumItems(this) )
    return 0i64;
  if ( DNA::PropertyData::GetValue(v5, v4)->mOwner != v5 )
    return 1i64;
  if ( v5->mOverrideMode
    || (v6 = DNA::PropertyBag::GetParent(v5->mOwner)) == 0i64
    || (v7 = DNA::PropertyBag::GetProperty((DNA::PropertyBag *)v6, v5->mName.mData),
        (v8 = (DNA::PropertyData *)v7) == 0i64)
    || v4 >= DNA::PropertyData::NumItems((DNA::PropertyData *)v7) )
  {
    if ( v3 )
    {
      UFG::qString::qString(&v15);
      v13 = DNA::PropertyData::GetValue(v5, v4);
      if ( v13 )
        UFG::qString::Set(&v15, v13->mData.mData);
      v14 = DNA::SchemaField::GetDefaultValue(v3);
      if ( (unsigned __int8)DNA::DataConverter::Equals(v3->mType, v14, v15.mData) == 1 )
      {
        UFG::qString::~qString(&v15);
        return 0i64;
      }
      UFG::qString::~qString(&v15);
    }
    return 2i64;
  }
  UFG::qString::qString(&v16);
  v9 = DNA::PropertyData::GetValue(v5, v4);
  if ( v9 )
    UFG::qString::Set(&v16, v9->mData.mData);
  UFG::qString::qString(&v15);
  v10 = DNA::PropertyData::GetValue(v8, v4);
  if ( v10 )
    UFG::qString::Set(&v15, v10->mData.mData);
  v11 = (unsigned int)UFG::qStringCompare(v16.mData, v15.mData, -1) != 0;
  UFG::qString::~qString(&v15);
  UFG::qString::~qString(&v16);
  return (unsigned int)(v11 + 1);
}

// File Line: 1313
// RVA: 0x1A73E0
void __fastcall DNA::PropertyData::SetValueAction::SetValue(DNA::PropertyData::SetValueAction *this, DNA::PropertyData::Value *value, const char *data)
{
  __int64 v3; // rbx
  const char *v4; // rbp
  DNA::PropertyData::Value *v5; // rdi
  DNA::PropertyData::Value *v6; // rsi
  DNA::PropertyData::SetValueAction *v7; // [rsp+30h] [rbp+8h]

  v7 = this;
  v3 = 0i64;
  v4 = data;
  v5 = value;
  if ( value->mInheritedValues.size )
  {
    do
    {
      v6 = v5->mInheritedValues.p[v3];
      if ( !(unsigned int)UFG::qStringCompare(v6->mData.mData, v5->mData.mData, -1) )
        DNA::PropertyData::SetValueAction::SetValue(v7, v6, v4);
      v3 = (unsigned int)(v3 + 1);
    }
    while ( (unsigned int)v3 < v5->mInheritedValues.size );
  }
  UFG::qString::Set(&v5->mData, v4);
}

// File Line: 1327
// RVA: 0x1A7D90
void __fastcall DNA::PropertyData::SetValueAction::Validate(DNA::PropertyData::SetValueAction *this)
{
  DNA::PropertyData::SetValueAction *v1; // rdi
  DNA::SchemaField *v2; // rax
  const char *v3; // rax
  bool v4; // al
  DNA::PropertyData::Value *v5; // rsi
  __int64 v6; // rbx
  const char *v7; // r14
  DNA::PropertyData::Value *v8; // rbp

  v1 = this;
  if ( !this->mOldValue.mLength )
  {
    v2 = DNA::PropertyData::GetSchemaField(this->mValue->mOwner);
    if ( v2 )
    {
      v3 = DNA::SchemaField::GetDefaultValue(v2);
      if ( v3 )
        UFG::qString::Set(&v1->mOldValue, v3);
    }
  }
  v4 = (unsigned __int8)DNA::DataConverter::Equals(
                          v1->mValue->mOwner->mPropertyType,
                          v1->mNewValue.mData,
                          v1->mOldValue.mData) == 0;
  v1->mIsValid = v4;
  if ( !v4 && (unsigned int)UFG::qStringCompare(v1->mNewValue.mData, v1->mValue->mData.mData, -1) )
  {
    v5 = v1->mValue;
    v6 = 0i64;
    v7 = v1->mNewValue.mData;
    if ( v5->mInheritedValues.size )
    {
      do
      {
        v8 = v5->mInheritedValues.p[v6];
        if ( !(unsigned int)UFG::qStringCompare(v8->mData.mData, v5->mData.mData, -1) )
          DNA::PropertyData::SetValueAction::SetValue(v1, v8, v7);
        v6 = (unsigned int)(v6 + 1);
      }
      while ( (unsigned int)v6 < v5->mInheritedValues.size );
    }
    UFG::qString::Set(&v5->mData, v7);
  }
}

// File Line: 1350
// RVA: 0x1A4E30
void __fastcall DNA::PropertyData::SetValueAction::DoInternal(DNA::PropertyData::SetValueAction *this)
{
  DNA::PropertyData::Value *v1; // rdi
  char *v2; // r14
  __int64 v3; // rbx
  DNA::PropertyData::SetValueAction *v4; // rsi
  DNA::PropertyData::Value *v5; // rbp
  DNA::PropertyData::Value *v6; // rbx
  DNA::PropertyData *v7; // rdx
  AMD_HD3D *v8; // rax

  v1 = this->mValue;
  v2 = this->mNewValue.mData;
  v3 = 0i64;
  v4 = this;
  if ( v1->mInheritedValues.size )
  {
    do
    {
      v5 = v1->mInheritedValues.p[v3];
      if ( !(unsigned int)UFG::qStringCompare(v5->mData.mData, v1->mData.mData, -1) )
        DNA::PropertyData::SetValueAction::SetValue(v4, v5, v2);
      v3 = (unsigned int)(v3 + 1);
    }
    while ( (unsigned int)v3 < v1->mInheritedValues.size );
  }
  UFG::qString::Set(&v1->mData, v2);
  DNA::PropertyBag::MarkDirty(v4->mValue->mOwner->mOwner);
  v6 = v4->mValue;
  DNA::Database::Instance();
  v7 = v6->mOwner;
  _(v8);
}

// File Line: 1359
// RVA: 0x1A76A0
void __fastcall DNA::PropertyData::SetValueAction::UndoInternal(DNA::PropertyData::SetValueAction *this)
{
  DNA::PropertyData::Value *v1; // rdi
  char *v2; // r14
  __int64 v3; // rbx
  DNA::PropertyData::SetValueAction *v4; // rsi
  DNA::PropertyData::Value *v5; // rbp
  DNA::PropertyData::Value *v6; // rbx
  DNA::PropertyData *v7; // rdx
  AMD_HD3D *v8; // rax

  v1 = this->mValue;
  v2 = this->mOldValue.mData;
  v3 = 0i64;
  v4 = this;
  if ( v1->mInheritedValues.size )
  {
    do
    {
      v5 = v1->mInheritedValues.p[v3];
      if ( !(unsigned int)UFG::qStringCompare(v5->mData.mData, v1->mData.mData, -1) )
        DNA::PropertyData::SetValueAction::SetValue(v4, v5, v2);
      v3 = (unsigned int)(v3 + 1);
    }
    while ( (unsigned int)v3 < v1->mInheritedValues.size );
  }
  UFG::qString::Set(&v1->mData, v2);
  DNA::PropertyBag::MarkDirty(v4->mValue->mOwner->mOwner);
  v6 = v4->mValue;
  DNA::Database::Instance();
  v7 = v6->mOwner;
  _(v8);
}

// File Line: 1368
// RVA: 0x1A6290
void __fastcall DNA::PropertyData::SetValueAction::Print(DNA::PropertyData::SetValueAction *this)
{
  DNA::PropertyData::SetValueAction *v1; // rbx
  UFG::qString *v2; // rax
  UFG::qString result; // [rsp+28h] [rbp-30h]

  v1 = this;
  v2 = DNA::PropertyData::GetName(this->mValue->mOwner, &result);
  UFG::qPrintf("SetValueAction: %s New:%s Old:%s", v2->mData, v1->mNewValue.mData, v1->mOldValue.mData, -2i64);
  UFG::qString::~qString(&result);
}

// File Line: 1373
// RVA: 0x1A7600
char __fastcall DNA::PropertyData::SetValueAction::TryToMerge(DNA::PropertyData::SetValueAction *this, DNA::IAction *action)
{
  DNA::PropertyData::SetValueAction *v2; // rbx

  v2 = this;
  if ( action->mTypeId != 724266166 || action[3].vfptr != (DNA::IActionVtbl *)this->mValue )
    return 0;
  UFG::qString::Set(&this->mNewValue, *(const char **)&action[2].mIsValid);
  v2->vfptr->DoInternal((DNA::IAction *)&v2->vfptr);
  return 1;
}

// File Line: 1389
// RVA: 0x1A4DD0
void __fastcall DNA::PropertyData::AddValueAction::DoInternal(DNA::PropertyData::AddValueAction *this)
{
  DNA::PropertyData::Value **v1; // rbx
  DNA::PropertyData *v2; // rdi
  DNA::Database *v3; // rax

  v1 = &this->mValue;
  v2 = this->mValue->mOwner;
  UFG::qArray<UFG::PedSpawningInfo *,0>::Add(
    (UFG::qArray<UFG::qPropertySet *,0> *)&v2->mArrayEntries,
    (UFG::qPropertySet *const *)&this->mValue,
    "qArray.Add");
  DNA::PropertyBag::MarkDirty((*v1)->mOwner->mOwner);
  DNA::Database::Instance();
  DNA::Database::OnStructureChanged(v3, v2);
}

// File Line: 1399
// RVA: 0x1A7650
void __fastcall DNA::PropertyData::AddValueAction::UndoInternal(DNA::PropertyData::AddValueAction *this)
{
  DNA::PropertyData::Value **v1; // rbx
  DNA::PropertyData *v2; // rdi
  DNA::Database *v3; // rax

  v1 = &this->mValue;
  v2 = this->mValue->mOwner;
  UFG::qArray<DNA::PropertyData::Value *,0>::StableDelete(&v2->mArrayEntries, &this->mValue);
  DNA::PropertyBag::MarkDirty((*v1)->mOwner->mOwner);
  DNA::Database::Instance();
  DNA::Database::OnStructureChanged(v3, v2);
}

// File Line: 1450
// RVA: 0x1A4010
void __fastcall DNA::PropertyData::Value::Value(DNA::PropertyData::Value *this, DNA::PropertyData *owner)
{
  DNA::PropertyData *v2; // rdi
  DNA::PropertyData::Value *v3; // rsi
  unsigned int v4; // ebx

  v2 = owner;
  v3 = this;
  v4 = (unsigned int)UFG::qGetTicks() << 16;
  v3->mID = v4 | (unsigned __int16)UFG::qGetTicks();
  UFG::qString::qString(&v3->mData);
  v3->mOwner = v2;
  v3->mOverridenValue = 0i64;
  v3->mInheritedValues.p = 0i64;
  *(_QWORD *)&v3->mInheritedValues.size = 0i64;
}

// File Line: 1464
// RVA: 0x1A4080
void __fastcall DNA::PropertyData::Value::Value(DNA::PropertyData::Value *this, DNA::PropertyData *owner, DNA::PropertyData::Value *overrideValue)
{
  DNA::PropertyData::Value *v3; // rdi
  DNA::PropertyData *v4; // rbx
  DNA::PropertyData::Value *v5; // rsi
  UFG::qArray<UFG::qReflectInventoryBase *,0> *v6; // rdi
  __int64 v7; // rbp
  unsigned int v8; // ebx
  unsigned int v9; // edx
  unsigned int v10; // edx

  v3 = overrideValue;
  v4 = owner;
  v5 = this;
  this->mID = overrideValue->mID;
  UFG::qString::qString(&this->mData);
  v5->mOwner = v4;
  v5->mOverridenValue = v3;
  v5->mInheritedValues.p = 0i64;
  *(_QWORD *)&v5->mInheritedValues.size = 0i64;
  v6 = (UFG::qArray<UFG::qReflectInventoryBase *,0> *)v5->mOverridenValue;
  v7 = v6[4].size;
  v8 = v7 + 1;
  v9 = v6[4].capacity;
  if ( (signed int)v7 + 1 > v9 )
  {
    if ( v9 )
      v10 = 2 * v9;
    else
      v10 = 1;
    for ( ; v10 < v8; v10 *= 2 )
      ;
    if ( v10 <= 2 )
      v10 = 2;
    if ( v10 - v8 > 0x10000 )
      v10 = v7 + 65537;
    UFG::qArray<UFG::CompositeDrawableComponent *,32>::Reallocate(v6 + 4, v10, "qArray.Add");
  }
  v6[4].size = v8;
  v6[4].p[v7] = (UFG::qReflectInventoryBase *)v5;
  UFG::qString::Set(&v5->mData, v5->mOverridenValue->mData.mData, v5->mOverridenValue->mData.mLength, 0i64, 0);
}

// File Line: 1470
// RVA: 0x1A44F0
void __fastcall DNA::PropertyData::Value::~Value(DNA::PropertyData::Value *this)
{
  DNA::PropertyData::Value *v1; // rdi
  DNA::PropertyData::Value *v2; // rdx
  __int64 v3; // rcx
  unsigned int v4; // er8
  DNA::PropertyData::Value **v5; // r9
  unsigned int v6; // eax
  unsigned int i; // edx
  unsigned __int64 v8; // rbx
  DNA::Database *v9; // rax
  UFG::qTree64Base *v10; // rax
  DNA::PropertyBag *v11; // rbx
  unsigned __int64 v12; // rsi
  DNA::PropertyData *v13; // rax
  DNA::PropertyData::Value *v14; // rax
  DNA::Database *v15; // rax
  DNA::PropertyData::Value **v16; // rcx

  v1 = this;
  v2 = this->mOverridenValue;
  if ( v2 )
  {
    v3 = 0i64;
    v4 = v2->mInheritedValues.size;
    if ( v4 )
    {
      v5 = v2->mInheritedValues.p;
      while ( v1 != v5[v3] )
      {
        v3 = (unsigned int)(v3 + 1);
        if ( (unsigned int)v3 >= v4 )
          goto LABEL_11;
      }
      if ( (signed int)v3 >= 0 )
      {
        v5[v3] = v5[v4 - 1];
        v6 = v2->mInheritedValues.size;
        if ( v6 > 1 )
          v2->mInheritedValues.size = v6 - 1;
        else
          v2->mInheritedValues.size = 0;
      }
    }
  }
LABEL_11:
  for ( i = 0; i < v1->mInheritedValues.size; ++i )
    v1->mInheritedValues.p[i]->mOverridenValue = 0i64;
  v1->mInheritedValues.size = 0;
  if ( v1->mOwner->mPropertyType == -915936389 )
  {
    v8 = UFG::qToUInt64(v1->mData.mData, 0i64);
    DNA::Database::Instance();
    v10 = DNA::Database::GetPropertyBag(v9, v8);
    v11 = (DNA::PropertyBag *)v10;
    if ( v10 )
    {
      v12 = 0i64;
      v13 = DNA::PropertyBag::GetProperty((DNA::PropertyBag *)v10, "$OwnerId");
      if ( v13 )
      {
        if ( v13->mPropertyType == 151281197 )
        {
          v14 = DNA::PropertyData::GetValue(v13, 0);
          if ( v14 )
            v12 = UFG::qToUInt64(v14->mData.mData, 0i64);
        }
      }
      if ( v12 == v1->mOwner->mOwner->mBaseNode.mUID )
      {
        DNA::Database::Instance();
        DNA::Database::DeleteBag(v15, v11);
      }
    }
  }
  v16 = v1->mInheritedValues.p;
  if ( v16 )
    operator delete[](v16);
  v1->mInheritedValues.p = 0i64;
  *(_QWORD *)&v1->mInheritedValues.size = 0i64;
  UFG::qString::~qString(&v1->mData);
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
void __fastcall DNA::DataConverter::ToType(const char *s, bool *v)
{
  *v = UFG::qToBool(s, 0);
}

// File Line: 1505
// RVA: 0x1A7540
void __fastcall DNA::DataConverter::ToType(const char *s, float *v)
{
  if ( (*s != 48 || (s[1] - 88) & 0xDF) && *s != 35 )
    *v = UFG::qToFloat(s, 0.0);
  else
    *(_DWORD *)v = UFG::qToUInt32(s, 0);
}

// File Line: 1508
// RVA: 0x1A74F0
void __fastcall DNA::DataConverter::ToString(UFG::qString *s, const char *v)
{
  UFG::qString::Set(s, v);
}

// File Line: 1519
// RVA: 0x1A4EF0
_BOOL8 __fastcall DNA::DataConverter::Equals(DNA::PropertyType::Enum type, const char *data1, const char *data2)
{
  const char *v3; // rsi
  const char *v4; // rdi
  bool v5; // bl
  unsigned __int64 v6; // rbx
  int v7; // ebx
  int v8; // ebx
  float v9; // xmm6_4
  __int128 v10; // xmm0
  char v11; // bl
  UFG::qString text; // [rsp+28h] [rbp-70h]
  UFG::qString v14; // [rsp+50h] [rbp-48h]

  v3 = data2;
  v4 = data1;
  v5 = 0;
  if ( (signed int)type <= 224407815 )
  {
    if ( type == 224407815 || type == -2133091136 )
    {
      v8 = UFG::qToInt32(data1, 0);
      return v8 == (unsigned int)UFG::qToInt32(v3, 0);
    }
    if ( type == -2067794966 )
    {
      v7 = UFG::qToUInt32(data1, 0);
      return v7 == (unsigned int)UFG::qToUInt32(v3, 0);
    }
    if ( type != -915936389 )
    {
      if ( type == 151281197 )
      {
        v6 = UFG::qToUInt64(data1, 0i64);
        v5 = v6 == UFG::qToUInt64(v3, 0i64);
      }
      return v5;
    }
LABEL_27:
    return 0;
  }
  switch ( type )
  {
    case 826535573:
      UFG::qString::qString(&v14);
      UFG::qString::qString(&text);
      UFG::qString::Set(&v14, v4);
      UFG::qString::Set(&text, v3);
      v5 = UFG::qString::operator==(&v14, &text);
      UFG::qString::~qString(&text);
      UFG::qString::~qString(&v14);
      return v5;
    case 1138723642:
      v11 = UFG::qToBool(data1, 0);
      return v11 == UFG::qToBool(v3, 0);
    case 1208522079:
      if ( (*data1 != 48 || (data1[1] - 88) & 0xDF) && *data1 != 35 )
        v9 = UFG::qToFloat(data1, 0.0);
      else
        LODWORD(v9) = UFG::qToUInt32(data1, 0);
      if ( (*v3 != 48 || (v3[1] - 88) & 0xDF) && *v3 != 35 )
        *(float *)&v10 = UFG::qToFloat(v3, 0.0);
      else
        v10 = (unsigned int)UFG::qToUInt32(v3, 0);
      if ( v9 == *(float *)&v10 )
        return 1;
      goto LABEL_27;
    case 1830847931:
      v5 = *data1 == *data2;
      break;
  }
  return v5;
}

